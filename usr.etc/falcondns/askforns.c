/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * This module is part of the full service resolver logic.
 * It is responsible for sending a query to one of the foreign NS
 * for a NOA and persevering until the result is either a response
 * or an error.
 */

#ifndef lint
static char sccsid[] = "@(#)askforns.c	1.26 (IFCTF) 2013/08/10";
#endif

#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include <syslog.h>
#include "dname.h"
#include "class.h"
#include "tree.h"
#include "nsrec.h"
#include "query.h"
#include "udpout.h"
#include "globals.h"
#include "selectloop.h"
#include "tcpqueue.h"

extern u_char *myalloc();
extern struct udpout *alloc_udpout_struct();
extern struct query *create_internal_query();
extern u_long intquery_negative_ttl();
extern u_long random();

void askforns_send(), askforns_sendforreal();

static void
formulate_outgoing_query(q)
	register struct query *q;
{
	register struct udpout *uo;
	register u_char *dp;
	register struct dname *qname;

	uo = q->q_udpout;
	/*
	 * Header init: we want all zeros except the ID field
	 * which has already been set for us and the 1 in the
	 * QDCOUNT field (least significant octet).
	 */
	bzero(uo->uo_query + 2, 10);
	uo->uo_query[5] = 1;
	dp = uo->uo_query + sizeof(HEADER);
	qname = &q->q_stages[q->q_curstage].qs_qname;
	bcopy(qname->dn_labels[0], dp, qname->dn_stringlen);
	dp += qname->dn_stringlen;
	PUTSHORT(q->q_type, dp);
	PUTSHORT(q->q_class->c_class, dp);
	uo->uo_querylen = dp - uo->uo_query;
}

static void
tcp_response_handler(tq, msg, msglen)
	register struct tcpquery *tq;
	u_char *msg;
	int msglen;
{
	register struct query *q;
	register struct udpout *uo;
	register HEADER *hdr;

	q = (struct query *) tq->tq_userinfo;
	hdr = (HEADER *) msg;
	if (q->q_trace)
		fprintf(q->q_trace, "TCP response: RCODE=%d\n", hdr->rcode);
	uo = q->q_udpout;
	if (hdr->tc) {
		if (q->q_trace)
			fputs("TCP response has TC set!\n", q->q_trace);
		stats_tcpretry_tcagain++;
error_out:	free_udpout_struct(uo);
		q->q_askforns_error_callbk(q);
		return;
	}
	/* check QDCOUNT and the question echo */
	if (ntohs(hdr->qdcount) > 1) {
		if (q->q_trace)
			fprintf(q->q_trace,
				"QDCOUNT=%d in TCP response: error\n",
				ntohs(hdr->qdcount));
		stats_tcpretry_badecho++;
		goto error_out;
	}
	if (hdr->qdcount) {
		/* question echo must match our query */
		if (msglen < uo->uo_querylen) {
mismatch:		if (q->q_trace)
				fprintf(q->q_trace,
		"TCP response with QDCOUNT=1 doesn't match our query: error\n");
			stats_tcpretry_badecho++;
			goto error_out;
		}
		if (bcmp(uo->uo_query + sizeof(HEADER), msg + sizeof(HEADER),
			 uo->uo_querylen - sizeof(HEADER)))
			goto mismatch;
	}
	/* pass it up! */
	stats_tcpretry_success++;
	q->q_askforns_response_callbk(q, msg, msglen);
	free_udpout_struct(uo);
}

static void
tcp_error_handler(tq)
	struct tcpquery *tq;
{
	register struct query *q;

	q = (struct query *) tq->tq_userinfo;
	if (q->q_trace)
		fputs("tcpqueue layer returned an error indication\n",
			q->q_trace);
	free_udpout_struct(q->q_udpout);
	q->q_askforns_error_callbk(q);
	stats_tcpretry_fail++;
}

static void
retry_via_tcp(q, uo, sin)
	register struct query *q;
	register struct udpout *uo;
	struct sockaddr_in *sin;
{
	register struct tcpquery *tq;

	if (q->q_trace)
		fputs("UDP TC response, retrying via TCP\n", q->q_trace);
	tq = (struct tcpquery *) myalloc(sizeof(struct tcpquery));
	if (!tq) {
mallocfail:	if (q->q_trace)
			fputs("error: unable to malloc struct tcpqueue\n",
				q->q_trace);
		free_udpout_struct(q->q_udpout);
		q->q_askforns_error_callbk(q);
		return;
	}
	bcopy(sin, &tq->tq_sin, sizeof(struct sockaddr_in));
	uo->uo_tcplen = htons(uo->uo_querylen);
	tq->tq_query = (u_char *) &uo->uo_tcplen;
	tq->tq_querylen = uo->uo_querylen + 2;
	tq->tq_userinfo = (caddr_t) q;
	tq->tq_response_callbk = tcp_response_handler;
	tq->tq_error_callbk = tcp_error_handler;
	if (tcpqueue_submit_query(tq) < 0) {
		free(tq);
		goto mallocfail;
	}
}

static
is_srcaddr_valid(ns, srcaddr, srvrtn)
	struct ns_rrset *ns;
	register u_long srcaddr;
	struct nsrr **srvrtn;
{
	register struct nsrr *ind;
	register int i;

	for (ind = ns->ns_chain; ind; ind = ind->nsrr_next) {
		for (i = 0; i < ind->nsrr_addrcnt; i++)
			if (ind->nsrr_addrs[i] == srcaddr) {
				*srvrtn = ind;
				return(1);
			}
	}
	return(0);
}

void
askforns_recvfunc(uo, msg, msglen, from)
	register struct udpout *uo;
	u_char *msg;
	int msglen;
	struct sockaddr_in *from;
{
	register struct query *q;
	register HEADER *hdr;
	struct ns_rrset *ns;
	struct nsrr *srv;

	if (udpout_debug)
		syslog(LOG_DEBUG, "udpout-debug: entered askforns_recvfunc()");
	hdr = (HEADER *)msg;
	/* quickest check first: ignore if it isn't a response */
	if (!hdr->qr) {
		if (udpout_debug)
			syslog(LOG_DEBUG,
				"udpout-debug: dropping because of QR=0");
		return;
	}
	/* now verify the origin address */
	if (ntohs(from->sin_port) != NAMESERVER_PORT) {
		if (udpout_debug)
			syslog(LOG_DEBUG,
			"udpout-debug: dropping because the src port is wrong");
		return;
	}
	q = (struct query *) uo->uo_userinfo;
	ns = q->q_noa->n_ns;
	if (!ns) {
		/* This can only happen if an NS-anchor has been pulled */
		if (q->q_trace)
			fprintf(q->q_trace, "askforns_recvfunc: NS missing!\n");
		if (q->q_timeout) {
			timesched_discard(q->q_timeout);
			q->q_timeout = 0;
		}
		if (q->q_child) {
			q->q_child->q_parent = 0;
			q->q_child = 0;
		}
		free_udpout_struct(uo);
		q->q_askforns_error_callbk(q);
		return;
	}
	if (!is_srcaddr_valid(ns, from->sin_addr.s_addr, &srv)) {
		if (udpout_debug)
			syslog(LOG_DEBUG,
			"udpout-debug: dropping because the src addr is wrong");
		return;
	}
	/* check QDCOUNT and the question echo */
	if (ntohs(hdr->qdcount) > 1) {
		if (q->q_trace)
			fprintf(q->q_trace,
				"response from %s: QDCOUNT=%d, ignored\n",
				inet_ntoa(from->sin_addr), ntohs(hdr->qdcount));
		return;
	}
	if (hdr->qdcount && !hdr->tc) {
		/* question echo must match our query */
		if (msglen < uo->uo_querylen) {
			if (q->q_trace)
				fprintf(q->q_trace,
	"response from %s with QDCOUNT=1 is shorter than our query: bogon\n",
					inet_ntoa(from->sin_addr));
			return;
		}
		if (bcmp(uo->uo_query + sizeof(HEADER), msg + sizeof(HEADER),
			 uo->uo_querylen - sizeof(HEADER))) {
			if (q->q_trace)
				fprintf(q->q_trace,
	"response from %s: question echo doesn't match our query, ignored\n",
					inet_ntoa(from->sin_addr));
			return;
		}
	}
	/* check the RCODE */
	if (q->q_trace)
		fprintf(q->q_trace, "got RCODE %d from %s\n", hdr->rcode,
			inet_ntoa(from->sin_addr));
	switch (hdr->rcode) {
	case NOERROR:
	case NXDOMAIN:
		/*
		 * We are done as far as this service layer
		 * is concerned. Pass it up.
		 */
		uo->uo_recv = 0;
		srv->nsrr_tempfail = 0;
		if (q->q_timeout) {
			timesched_discard(q->q_timeout);
			q->q_timeout = 0;
		}
		if (q->q_child) {
			q->q_child->q_parent = 0;
			q->q_child = 0;
		}
		if (hdr->tc) {
			stats_incoming_udp_tc++;
			log_udp_tc_response(q, (struct dname *) (srv+1), from);
			retry_via_tcp(q, uo, from);
			return;
		}
		q->q_askforns_response_callbk(q, msg, msglen);
		free_udpout_struct(uo);
		return;
	case SERVFAIL:
	default:
		/*
		 * Handle the "weird" RCODEs like SERVFAIL
		 * by "accelerating" the timeout that would
		 * cause us to try the next server.
		 *
		 * This way we can handle a situation in which
		 * some of the servers in an NS RRset return
		 * bogosity while others are good.
		 *
		 * We also mark the bad server, formally called
		 * "caching temporary failures".
		 */
		srv->nsrr_tempfail = current_time + tempfail_cache_dur;
		if (q->q_timeout) {
			if (q->q_trace)
				fputs("timeout accelerated\n", q->q_trace);
			timesched_discard(q->q_timeout);
			q->q_timeout = 0;
			askforns_send(q, 1);
		}
	}
}

void
askforns_entry(q)
	register struct query *q;
{
	register struct udpout *uo;

	uo = alloc_udpout_struct();
	if (!uo) {
		if (q->q_trace)
			fprintf(q->q_trace,
				"unable to malloc udpout structure\n");
		q->q_askforns_error_callbk(q);
		return;
	}
	q->q_udpout = uo;
	uo->uo_userinfo = (caddr_t) q;
	formulate_outgoing_query(q);
	q->q_timeout = 0;
	q->q_child = 0;
	q->q_retrycnt = 0;
	askforns_send(q, 0);
}

void
askforns_subquery_complete(subq)
	register struct query *subq;
{
	register struct query *orq;
	struct query_stage *qs = &subq->q_stages[subq->q_curstage];
	register struct ns_rrset *ns;
	register struct nsrr *srv;
	u_long ttl;

	if (subq->q_trace)
		fprintf(subq->q_trace,
	"subquery %d finished: result from stage %d: code %d, flags %04x\n",
			subq->q_trace_index, subq->q_curstage, qs->qs_result,
			qs->qs_flags);
	orq = (struct query *) subq->q_parent;
	if (!orq) {
		if (subq->q_trace) {
			fputs("the parent query is gone\n", subq->q_trace);
			query_trace_free(subq);
		}
		free_query_struct(subq);
		return;
	}
	if (subq->q_trace)
		query_trace_free(subq);
	orq->q_child = 0;
	ns = orq->q_noa->n_ns;
	if (!ns) {
		/*
		 * This can only happen if an NS-anchor has been pulled.
		 * But this type of subquery should never be initiated
		 * on an anchor NOA in the first place!
		 */
		if (orq->q_trace)
			fprintf(orq->q_trace,
				"askforns_subquery_complete: NS missing!\n");
		free_query_struct(subq);
		free_udpout_struct(orq->q_udpout);
		orq->q_askforns_error_callbk(orq);
		return;
	}
	/*
	 * There is a possible corner case which we need to guard
	 * against: suppose that the askforns layer gets invoked
	 * on a NOA with a CACHEDREF and a subquery gets initiated,
	 * but by the time the subquery returns, an NS-anchor has
	 * been installed on the node where the CACHEDREF used to be.
	 * If we don't guard against this case here, we could
	 * end up modifying the anchor, which is a no-no.
	 *
	 * Also note that if an NS-anchor gets installed, then deleted
	 * before our subquery returns, it could trigger the missing NS
	 * case checked for above.  *Extremely* unlikely, but...
	 */
	if (ns->ns_type == NSTYPE_ANCHOR) {
		if (orq->q_trace)
			fprintf(orq->q_trace,
				"oops, it's an anchor, won't touch it\n");
		free_query_struct(subq);
		askforns_send(orq, 0);
		return;
	}
	/* find the server whose A (or lack thereof) we just got back */
	for (srv = ns->ns_chain; srv; srv = srv->nsrr_next)
		if (dname_compare((struct dname *)(srv + 1),
				  &subq->q_stages[0].qs_qname))
			break;
	if (!srv) {
		if (orq->q_trace)
			fprintf(orq->q_trace,
		"can't find the NS corresponding to completed subquery!\n");
		free_query_struct(subq);
		askforns_send(orq, 0);
		return;
	}
	if (orq->q_trace) {
		fputs("completed subquery for server ", orq->q_trace);
		print_dname((struct dname *)(srv + 1), orq->q_trace);
		putc('\n', orq->q_trace);
	}
	switch (qs->qs_result) {
	case QSRESULT_ANSWER:
		break;
	case QSRESULT_NXDOMAIN:
	case QSRESULT_NOREC:
	case QSRESULT_CNAME:
		if (orq->q_trace)
			fprintf(orq->q_trace, "negative answer, caching TTL\n");
		ttl = intquery_negative_ttl(subq);
		free_query_struct(subq);
		if (ttl < tempfail_cache_dur)
			ttl = tempfail_cache_dur;
		srv->nsrr_tempfail = current_time + ttl;
		askforns_send(orq, 1);
		return;
	default:
		if (orq->q_trace)
			fprintf(orq->q_trace,
			"subquery result is an error, going to next NS\n");
		free_query_struct(subq);
		srv->nsrr_tempfail = current_time + tempfail_cache_dur;
		askforns_send(orq, 1);
		return;
	}
	if (orq->q_trace)
		fputs("got an answer\n", orq->q_trace);
	srv->nsrr_addrcnt = intquery_extract_A_answer(subq, srv->nsrr_addrs,
				NS_MAX_ADDRESSES, &ttl);
	free_query_struct(subq);
	if (!srv->nsrr_addrcnt) {
		if (orq->q_trace)
			fputs("intquery_extract_A_answer returned 0!\n",
				orq->q_trace);
		srv->nsrr_tempfail = current_time + tempfail_cache_dur;
		askforns_send(orq, 1);
		return;
	}
	srv->nsrr_A_expire = current_time + MIN(ttl, ttl_limit_ns);
	srv->nsrr_tempfail = 0;
	ns->ns_roundrobin = srv;
	askforns_sendforreal(orq, srv);
}

void
askforns_send(q, next)
	register struct query *q;
	int next;
{
	register struct ns_rrset *ns;
	register struct nsrr *srv;
	register int i;
	register struct query *subq;

	ns = q->q_noa->n_ns;
	if (!ns) {
		/* This can only happen if an NS-anchor has been pulled */
		if (q->q_trace)
			fprintf(q->q_trace, "askforns_send: NS missing!\n");
error_out:	free_udpout_struct(q->q_udpout);
		q->q_askforns_error_callbk(q);
		return;
	}
	if (!q->q_retrycnt) {
		q->q_retrylimit = ns->ns_count * askforns_retries_perserver;
		if (q->q_retrylimit > askforns_retries_total)
			q->q_retrylimit = askforns_retries_total;
	}
loop:	if (++q->q_retrycnt > q->q_retrylimit) {
		if (q->q_trace)
			fprintf(q->q_trace, "q_retrycnt=%d, giving up\n",
				q->q_retrycnt);
		goto error_out;
	}
	srv = ns->ns_roundrobin;
	if (!srv) {
		i = random() % ns->ns_count;
		for (srv = ns->ns_chain; i; i--)
			srv = srv->nsrr_next;
		ns->ns_roundrobin = srv;
	} else if (next) {
		srv = srv->nsrr_next;
		if (!srv)
			srv = ns->ns_chain;
		ns->ns_roundrobin = srv;
	}
	if (q->q_trace) {
		fputs("trying server ", q->q_trace);
		print_dname((struct dname *)(srv + 1), q->q_trace);
		putc('\n', q->q_trace);
	}
	if (srv->nsrr_tempfail > current_time) {
		if (q->q_trace)
			fputs("served marked as bad (cached tempfail)\n",
				q->q_trace);
badserver:	if (ns->ns_count == 1) {
			if (q->q_trace)
				fputs("lone server is bad, giving up\n",
					q->q_trace);
			goto error_out;
		}
		next = 1;
		goto loop;
	}
	/* do we have an actual IP address to send to? */
	if (srv->nsrr_addrcnt) {
		if (current_time >= srv->nsrr_A_expire &&
		    (ns->ns_type == NSTYPE_DELEGATION ||
		     ns->ns_type == NSTYPE_CACHEDREF &&
		     !(srv->nsrr_flags & NSRR_FLAGS_NEEDGLUE))) {
			if (q->q_trace)
				fputs("attached A expired\n", q->q_trace);
			srv->nsrr_addrcnt = 0;
		} else {
			askforns_sendforreal(q, srv);
			return;
		}
	}
	if (q->q_trace)
		fputs("NS has no attached A, need a subquery\n", q->q_trace);
	if (srv->nsrr_flags & NSRR_FLAGS_NEEDGLUE &&
	    ns->ns_type != NSTYPE_DELEGATION) {
		if (q->q_trace)
			fprintf(q->q_trace,
				"this server requires glue, try next\n");
		goto badserver;
	}
	/* is the subquery we're about to form the same as previous? */
	if (q->q_flags & QFLAGS_WANT_GLUE &&
	    dname_compare((struct dname *)(srv + 1), &q->q_stages[0].qs_qname)){
		if (q->q_trace)
			fputs("subquery would be a loop, giving up\n",
				q->q_trace);
		goto badserver;
	}
	/* create the subquery */
	if (q->q_nest_depth >= max_nested_queries) {
		if (q->q_trace)
			fprintf(q->q_trace,
			"current query %d has nest depth %d, exceeds limit\n",
				q->q_trace_index, q->q_nest_depth);
		goto badserver;
	}
	subq = create_internal_query(q);
	if (!subq) {
		if (q->q_trace)
			fputs("unable to malloc subquery\n", q->q_trace);
		goto error_out;
	}
	subq->q_class = q->q_class;
	dname_copy((struct dname *)(srv + 1), &subq->q_stages[0].qs_qname);
	subq->q_type = T_A;
	subq->q_flags |= QFLAGS_WANT_GLUE | QFLAGS_WANT_NEGSOA;
	subq->q_callwhendone = askforns_subquery_complete;
	stage_query(subq);
}

void
askforns_timeoutfunc(q)
	register struct query *q;
{
	q->q_timeout = 0;
	if (q->q_trace)
		fputs("askforns: UDP query timeout, going to next NS\n",
			q->q_trace);
	askforns_send(q, 1);
}

/*
 * While it is possible for a single name server (one NS record in an
 * RRset) to have multiple A records, such usage is uncommon in the real
 * world: instead the standard practice is to have largish NS RRsets
 * with one A record per NS.  Consequently, we make no real effort to
 * try all As of a given NS in turn: instead we only iterate through the
 * NS RRset, and if a given NS has multiple As, we merely pick a random
 * one to send our query to, and don't keep track of which As belonging
 * to the same server have or haven't been tried.
 */
void
askforns_sendforreal(q, srv)
	register struct query *q;
	register struct nsrr *srv;
{
	struct sockaddr_in dest;
	register struct timesched *t;
	register struct udpout *uo;
	register int i;

	if (srv->nsrr_addrcnt > 1)
		i = random() % srv->nsrr_addrcnt;
	else
		i = 0;
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = srv->nsrr_addrs[i];
	dest.sin_port = htons(NAMESERVER_PORT);
	if (q->q_trace) {
		fputs("Sending UDP query to ", q->q_trace);
		print_dname((struct dname *)(srv + 1), q->q_trace);
		fprintf(q->q_trace, " at %s\n", inet_ntoa(dest.sin_addr));
	}
	uo = q->q_udpout;
	t = (struct timesched *) myalloc(sizeof(struct timesched));
	if (!t) {
		if (q->q_trace)
			fputs("unable to malloc timeout struct\n", q->q_trace);
		free_udpout_struct(uo);
		q->q_askforns_error_callbk(q);
		return;
	}
	sendto(uo->uo_socket, uo->uo_query, uo->uo_querylen, 0, &dest,
		sizeof dest);
	uo->uo_recv = askforns_recvfunc;
	t->tim_time = current_time + askforns_timeout + 1;
	t->tim_func = askforns_timeoutfunc;
	t->tim_arg = (caddr_t) q;
	time_schedule(t);
	q->q_timeout = t;
}
