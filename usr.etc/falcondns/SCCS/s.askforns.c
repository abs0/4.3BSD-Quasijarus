h38493
s 00001/00001/00634
d D 1.26 2013/08/10 07:11:45 msokolov 26 25
c external queries bypass the queue
e
s 00002/00001/00633
d D 1.25 2013/01/07 06:01:39 msokolov 25 24
c allow A subqueries on an NSTYPE_DELEGATION even if NSRR_FLAGS_NEEDGLUE is set
e
s 00001/00001/00633
d D 1.24 2013/01/06 07:04:07 msokolov 24 23
c MSDNS => FalconDNS
e
s 00019/00003/00615
d D 1.23 2011/12/22 07:56:22 msokolov 23 22
c SOA/CNAME negative caching implemented
e
s 00001/00001/00617
d D 1.22 2011/12/22 05:52:18 msokolov 22 21
c ttl-limit tunable setting split into several
e
s 00005/00001/00613
d D 1.21 2011/12/20 19:48:16 msokolov 21 20
c track and report outcomes of TCP retry attempts (after getting UDP TC)
e
s 00026/00001/00588
d D 1.20 2011/12/20 07:35:51 msokolov 20 19
c guard against inadvertent NS-anchor alteration
e
s 00001/00000/00588
d D 1.19 2011/12/20 06:05:02 msokolov 19 18
c log UDP TC responses
e
s 00013/00004/00575
d D 1.18 2011/12/20 05:15:03 msokolov 18 17
c ability to send to more than just the first A of many
e
s 00045/00019/00534
d D 1.17 2011/12/19 09:13:09 msokolov 17 16
c tempfail caching implemented
e
s 00000/00001/00553
d D 1.16 2011/12/19 08:03:52 msokolov 16 15
c axed NSRR_FLAGS_BAD, preparing for caching foreign NS temp failures
e
s 00003/00000/00551
d D 1.15 2011/12/18 00:35:30 msokolov 15 14
c missing returns were wreaking havoc with glueless NS
e
s 00016/00012/00535
d D 1.14 2011/12/17 06:38:01 msokolov 14 13
c tcpqueue revamped
e
s 00096/00004/00451
d D 1.13 2011/12/14 23:59:29 msokolov 13 12
c TCP retry implemented
e
s 00001/00000/00454
d D 1.12 2011/12/13 05:02:09 msokolov 12 11
c TC stats implemented
e
s 00001/00001/00453
d D 1.11 2011/12/11 07:30:28 msokolov 11 10
c internal queries: prep for NS-anchor refresh
e
s 00001/00001/00453
d D 1.10 2011/12/07 23:25:13 msokolov 10 9
c oops, need MIN, not MAX
e
s 00018/00003/00436
d D 1.9 2011/12/07 23:14:25 msokolov 9 8
c fixed 'fromlen' bug in udpout.c
c created udpout-debug apparatus in the process of chasing after that bug
e
s 00012/00006/00427
d D 1.8 2011/12/07 07:46:58 msokolov 8 7
c skip unusable glueless servers
e
s 00008/00004/00425
d D 1.7 2011/11/12 19:16:08 msokolov 7 6
c askforns retries logic better thought through
e
s 00078/00000/00351
d D 1.6 2011/11/12 18:46:02 msokolov 6 5
c askforns_subquery_complete implemented
e
s 00051/00005/00300
d D 1.5 2011/11/12 06:08:48 msokolov 5 4
c askforns done except for the subquery completion function
e
s 00097/00004/00208
d D 1.4 2011/11/11 23:10:45 msokolov 4 3
c fleshing out
e
s 00034/00005/00178
d D 1.3 2011/11/11 21:30:35 msokolov 3 2
c question echo and TC checks implemented
e
s 00001/00000/00182
d D 1.2 2011/11/11 20:55:23 msokolov 2 1
c #include <machine/endian.h> for hton[ls] and ntoh[ls]
e
s 00182/00000/00000
d D 1.1 2011/11/11 09:00:17 msokolov 1 0
c started
e
u
U
t
T
I 1
/*
D 24
 * Michael Sokolov's Domain Name Server (MSDNS)
E 24
I 24
 * FalconDNS daemon by Michael Spacefalcon
E 24
 *
 * This module is part of the full service resolver logic.
 * It is responsible for sending a query to one of the foreign NS
 * for a NOA and persevering until the result is either a response
 * or an error.
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 8
#include <sys/types.h>
I 2
#include <machine/endian.h>
E 8
I 8
#include <sys/param.h>
E 8
I 4
#include <sys/socket.h>
E 4
E 2
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <stdio.h>
I 9
#include <syslog.h>
E 9
#include "dname.h"
#include "class.h"
#include "tree.h"
#include "nsrec.h"
#include "query.h"
#include "udpout.h"
I 4
#include "globals.h"
E 4
#include "selectloop.h"
I 13
#include "tcpqueue.h"
E 13

I 5
extern u_char *myalloc();
E 5
extern struct udpout *alloc_udpout_struct();
extern struct query *create_internal_query();
I 23
extern u_long intquery_negative_ttl();
E 23
I 4
extern u_long random();
E 4

D 4
void askforns_send();
E 4
I 4
void askforns_send(), askforns_sendforreal();
E 4

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

I 13
static void
D 14
tcp_response_handler(tq)
	register struct tcpqueue *tq;
E 14
I 14
tcp_response_handler(tq, msg, msglen)
	register struct tcpquery *tq;
	u_char *msg;
	int msglen;
E 14
{
	register struct query *q;
	register struct udpout *uo;
	register HEADER *hdr;

	q = (struct query *) tq->tq_userinfo;
D 14
	hdr = (HEADER *) tq->tq_rspbuf;
E 14
I 14
	hdr = (HEADER *) msg;
E 14
	if (q->q_trace)
		fprintf(q->q_trace, "TCP response: RCODE=%d\n", hdr->rcode);
	uo = q->q_udpout;
	if (hdr->tc) {
		if (q->q_trace)
			fputs("TCP response has TC set!\n", q->q_trace);
D 21
		stats_incoming_tcp_tc++;
E 21
I 21
		stats_tcpretry_tcagain++;
E 21
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
I 21
		stats_tcpretry_badecho++;
E 21
		goto error_out;
	}
	if (hdr->qdcount) {
		/* question echo must match our query */
D 14
		if (tq->tq_rsplen < uo->uo_querylen) {
E 14
I 14
		if (msglen < uo->uo_querylen) {
E 14
mismatch:		if (q->q_trace)
				fprintf(q->q_trace,
		"TCP response with QDCOUNT=1 doesn't match our query: error\n");
I 21
			stats_tcpretry_badecho++;
E 21
			goto error_out;
		}
D 14
		if (bcmp(uo->uo_query + sizeof(HEADER),
			 tq->tq_rspbuf + sizeof(HEADER),
E 14
I 14
		if (bcmp(uo->uo_query + sizeof(HEADER), msg + sizeof(HEADER),
E 14
			 uo->uo_querylen - sizeof(HEADER)))
			goto mismatch;
	}
	/* pass it up! */
I 21
	stats_tcpretry_success++;
E 21
D 14
	q->q_askforns_response_callbk(q, tq->tq_rspbuf, tq->tq_rsplen);
E 14
I 14
	q->q_askforns_response_callbk(q, msg, msglen);
E 14
	free_udpout_struct(uo);
}

static void
tcp_error_handler(tq)
D 14
	struct tcpqueue *tq;
E 14
I 14
	struct tcpquery *tq;
E 14
{
	register struct query *q;

	q = (struct query *) tq->tq_userinfo;
	if (q->q_trace)
		fputs("tcpqueue layer returned an error indication\n",
			q->q_trace);
	free_udpout_struct(q->q_udpout);
	q->q_askforns_error_callbk(q);
I 21
	stats_tcpretry_fail++;
E 21
}

static void
retry_via_tcp(q, uo, sin)
	register struct query *q;
	register struct udpout *uo;
	struct sockaddr_in *sin;
{
D 14
	register struct tcpqueue *tq;
E 14
I 14
	register struct tcpquery *tq;
E 14

	if (q->q_trace)
		fputs("UDP TC response, retrying via TCP\n", q->q_trace);
D 14
	tq = (struct tcpqueue *) myalloc(sizeof(struct tcpqueue));
E 14
I 14
	tq = (struct tcpquery *) myalloc(sizeof(struct tcpquery));
E 14
	if (!tq) {
D 14
		if (q->q_trace)
E 14
I 14
mallocfail:	if (q->q_trace)
E 14
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
D 14
	tcpqueue_submit(tq);
E 14
I 14
	if (tcpqueue_submit_query(tq) < 0) {
		free(tq);
		goto mallocfail;
	}
E 14
}

E 13
static
D 17
is_srcaddr_valid(ns, srcaddr)
E 17
I 17
is_srcaddr_valid(ns, srcaddr, srvrtn)
E 17
	struct ns_rrset *ns;
	register u_long srcaddr;
I 17
	struct nsrr **srvrtn;
E 17
{
	register struct nsrr *ind;
	register int i;

	for (ind = ns->ns_chain; ind; ind = ind->nsrr_next) {
		for (i = 0; i < ind->nsrr_addrcnt; i++)
D 17
			if (ind->nsrr_addrs[i] == srcaddr)
E 17
I 17
			if (ind->nsrr_addrs[i] == srcaddr) {
				*srvrtn = ind;
E 17
				return(1);
I 17
			}
E 17
	}
	return(0);
}

void
askforns_recvfunc(uo, msg, msglen, from)
D 3
	struct udpout *uo;
E 3
I 3
	register struct udpout *uo;
E 3
	u_char *msg;
	int msglen;
	struct sockaddr_in *from;
{
	register struct query *q;
	register HEADER *hdr;
	struct ns_rrset *ns;
I 17
	struct nsrr *srv;
E 17

I 9
	if (udpout_debug)
		syslog(LOG_DEBUG, "udpout-debug: entered askforns_recvfunc()");
E 9
	hdr = (HEADER *)msg;
	/* quickest check first: ignore if it isn't a response */
D 9
	if (!hdr->qr)
E 9
I 9
	if (!hdr->qr) {
		if (udpout_debug)
			syslog(LOG_DEBUG,
				"udpout-debug: dropping because of QR=0");
E 9
		return;
I 9
	}
E 9
	/* now verify the origin address */
D 9
	if (ntohs(from->sin_port) != NAMESERVER_PORT)
E 9
I 9
	if (ntohs(from->sin_port) != NAMESERVER_PORT) {
		if (udpout_debug)
			syslog(LOG_DEBUG,
			"udpout-debug: dropping because the src port is wrong");
E 9
		return;
I 9
	}
E 9
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
D 9
	if (!is_srcaddr_valid(ns, from->sin_addr.s_addr))
E 9
I 9
D 17
	if (!is_srcaddr_valid(ns, from->sin_addr.s_addr)) {
E 17
I 17
	if (!is_srcaddr_valid(ns, from->sin_addr.s_addr, &srv)) {
E 17
		if (udpout_debug)
			syslog(LOG_DEBUG,
			"udpout-debug: dropping because the src addr is wrong");
E 9
		return;
I 9
	}
E 9
I 3
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
E 3
	/* check the RCODE */
	if (q->q_trace)
		fprintf(q->q_trace, "got RCODE %d from %s\n", hdr->rcode,
D 3
			from->sin_addr);
E 3
I 3
			inet_ntoa(from->sin_addr));
E 3
	switch (hdr->rcode) {
	case NOERROR:
	case NXDOMAIN:
		/*
		 * We are done as far as this service layer
		 * is concerned. Pass it up.
D 3
		 *
		 * TODO: check for TC and retry via TCP.
E 3
		 */
I 13
		uo->uo_recv = 0;
I 17
		srv->nsrr_tempfail = 0;
E 17
E 13
		if (q->q_timeout) {
			timesched_discard(q->q_timeout);
			q->q_timeout = 0;
		}
		if (q->q_child) {
			q->q_child->q_parent = 0;
			q->q_child = 0;
		}
I 3
		if (hdr->tc) {
I 12
			stats_incoming_udp_tc++;
I 19
			log_udp_tc_response(q, (struct dname *) (srv+1), from);
E 19
E 12
D 13
			/* TODO: retry via TCP */
			q->q_askforns_error_callbk(q);
		} else
			q->q_askforns_response_callbk(q, msg, msglen);
E 13
I 13
			retry_via_tcp(q, uo, from);
			return;
		}
		q->q_askforns_response_callbk(q, msg, msglen);
E 13
E 3
		free_udpout_struct(uo);
D 3
		q->q_askforns_response_callbk(q, msg, msglen);
E 3
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
I 17
		 *
		 * We also mark the bad server, formally called
		 * "caching temporary failures".
E 17
		 */
I 17
		srv->nsrr_tempfail = current_time + tempfail_cache_dur;
E 17
		if (q->q_timeout) {
I 4
			if (q->q_trace)
				fputs("timeout accelerated\n", q->q_trace);
E 4
			timesched_discard(q->q_timeout);
			q->q_timeout = 0;
D 4
			askforns_send(q);
E 4
I 4
			askforns_send(q, 1);
E 4
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
I 3
	q->q_retrycnt = 0;
E 3
D 4
	askforns_send(q);
E 4
I 4
	askforns_send(q, 0);
E 4
}

void
I 6
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
D 11
	orq = subq->q_parent;
E 11
I 11
	orq = (struct query *) subq->q_parent;
E 11
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
D 17
	if (qs->qs_result != QSRESULT_ANSWER) {
		if (orq->q_trace)
			fprintf(orq->q_trace,
"subquery result is not ANSWER, treating as failure, going to next NS\n");
		free_query_struct(subq);
		askforns_send(orq, 1);
I 15
		return;
E 15
	}
E 17
	ns = orq->q_noa->n_ns;
	if (!ns) {
D 20
		/* This can only happen if an NS-anchor has been pulled */
E 20
I 20
		/*
		 * This can only happen if an NS-anchor has been pulled.
		 * But this type of subquery should never be initiated
		 * on an anchor NOA in the first place!
		 */
E 20
		if (orq->q_trace)
			fprintf(orq->q_trace,
				"askforns_subquery_complete: NS missing!\n");
		free_query_struct(subq);
		free_udpout_struct(orq->q_udpout);
		orq->q_askforns_error_callbk(orq);
I 20
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
E 20
		return;
	}
D 17
	/* find the server whose A we just got back */
E 17
I 17
	/* find the server whose A (or lack thereof) we just got back */
E 17
	for (srv = ns->ns_chain; srv; srv = srv->nsrr_next)
		if (dname_compare((struct dname *)(srv + 1),
				  &subq->q_stages[0].qs_qname))
			break;
	if (!srv) {
		if (orq->q_trace)
D 17
			fputs("can't find the NS whose A we just got!\n",
				orq->q_trace);
E 17
I 17
			fprintf(orq->q_trace,
		"can't find the NS corresponding to completed subquery!\n");
E 17
		free_query_struct(subq);
D 7
		askforns_send(orq, 1);
E 7
I 7
		askforns_send(orq, 0);
I 15
		return;
E 15
E 7
	}
	if (orq->q_trace) {
D 17
		fputs("got A for server ", orq->q_trace);
E 17
I 17
		fputs("completed subquery for server ", orq->q_trace);
E 17
		print_dname((struct dname *)(srv + 1), orq->q_trace);
		putc('\n', orq->q_trace);
	}
I 17
D 23
	if (qs->qs_result != QSRESULT_ANSWER) {
E 23
I 23
	switch (qs->qs_result) {
	case QSRESULT_ANSWER:
		break;
	case QSRESULT_NXDOMAIN:
	case QSRESULT_NOREC:
	case QSRESULT_CNAME:
E 23
		if (orq->q_trace)
I 23
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
E 23
			fprintf(orq->q_trace,
D 23
"subquery result is not ANSWER, treating as failure, going to next NS\n");
E 23
I 23
			"subquery result is an error, going to next NS\n");
E 23
		free_query_struct(subq);
		srv->nsrr_tempfail = current_time + tempfail_cache_dur;
		askforns_send(orq, 1);
		return;
	}
	if (orq->q_trace)
		fputs("got an answer\n", orq->q_trace);
E 17
	srv->nsrr_addrcnt = intquery_extract_A_answer(subq, srv->nsrr_addrs,
				NS_MAX_ADDRESSES, &ttl);
	free_query_struct(subq);
	if (!srv->nsrr_addrcnt) {
		if (orq->q_trace)
			fputs("intquery_extract_A_answer returned 0!\n",
				orq->q_trace);
I 17
		srv->nsrr_tempfail = current_time + tempfail_cache_dur;
E 17
		askforns_send(orq, 1);
I 15
		return;
E 15
	}
D 16
	srv->nsrr_flags &= ~NSRR_FLAGS_BAD;
E 16
D 8
	srv->nsrr_A_expire = current_time + ttl;
E 8
I 8
D 10
	srv->nsrr_A_expire = current_time + MAX(ttl, ttl_limit);
E 10
I 10
D 22
	srv->nsrr_A_expire = current_time + MIN(ttl, ttl_limit);
E 22
I 22
	srv->nsrr_A_expire = current_time + MIN(ttl, ttl_limit_ns);
E 22
I 17
	srv->nsrr_tempfail = 0;
E 17
E 10
E 8
	ns->ns_roundrobin = srv;
	askforns_sendforreal(orq, srv);
}

void
E 6
D 4
askforns_send(q)
E 4
I 4
askforns_send(q, next)
E 4
	register struct query *q;
I 4
	int next;
E 4
{
I 4
	register struct ns_rrset *ns;
	register struct nsrr *srv;
	register int i;
I 5
	register struct query *subq;
E 5
E 4

I 4
	ns = q->q_noa->n_ns;
	if (!ns) {
		/* This can only happen if an NS-anchor has been pulled */
		if (q->q_trace)
			fprintf(q->q_trace, "askforns_send: NS missing!\n");
error_out:	free_udpout_struct(q->q_udpout);
		q->q_askforns_error_callbk(q);
		return;
	}
D 5
retry:	if (q->q_retrycnt >= ns->ns_count * askforns_retries) {
E 5
I 5
D 7
	if (q->q_retrycnt >= ns->ns_count * askforns_retries) {
E 7
I 7
	if (!q->q_retrycnt) {
		q->q_retrylimit = ns->ns_count * askforns_retries_perserver;
		if (q->q_retrylimit > askforns_retries_total)
			q->q_retrylimit = askforns_retries_total;
	}
D 8
	if (++q->q_retrycnt > q->q_retrylimit) {
E 8
I 8
loop:	if (++q->q_retrycnt > q->q_retrylimit) {
E 8
E 7
E 5
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
I 5
		if (!srv)
			srv = ns->ns_chain;
E 5
		ns->ns_roundrobin = srv;
	}
I 5
	if (q->q_trace) {
		fputs("trying server ", q->q_trace);
		print_dname((struct dname *)(srv + 1), q->q_trace);
		putc('\n', q->q_trace);
	}
I 17
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
E 17
E 5
	/* do we have an actual IP address to send to? */
	if (srv->nsrr_addrcnt) {
D 5
		askforns_sendforreal(q, srv);
		return;
E 5
I 5
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
E 5
	}
E 4
D 5

I 4

E 5
I 5
	if (q->q_trace)
		fputs("NS has no attached A, need a subquery\n", q->q_trace);
I 8
D 25
	if (srv->nsrr_flags & NSRR_FLAGS_NEEDGLUE) {
E 25
I 25
	if (srv->nsrr_flags & NSRR_FLAGS_NEEDGLUE &&
	    ns->ns_type != NSTYPE_DELEGATION) {
E 25
		if (q->q_trace)
			fprintf(q->q_trace,
				"this server requires glue, try next\n");
D 17
retry:		next = 1;
		goto loop;
E 17
I 17
		goto badserver;
E 17
	}
E 8
	/* is the subquery we're about to form the same as previous? */
	if (q->q_flags & QFLAGS_WANT_GLUE &&
	    dname_compare((struct dname *)(srv + 1), &q->q_stages[0].qs_qname)){
		if (q->q_trace)
			fputs("subquery would be a loop, giving up\n",
				q->q_trace);
D 8
		goto error_out;
E 8
I 8
D 17
		goto retry;
E 17
I 17
		goto badserver;
E 17
E 8
	}
	/* create the subquery */
	if (q->q_nest_depth >= max_nested_queries) {
		if (q->q_trace)
			fprintf(q->q_trace,
			"current query %d has nest depth %d, exceeds limit\n",
				q->q_trace_index, q->q_nest_depth);
D 8
		goto error_out;
E 8
I 8
D 17
		goto retry;
E 17
I 17
		goto badserver;
E 17
E 8
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
D 23
	subq->q_flags |= QFLAGS_WANT_GLUE;
E 23
I 23
	subq->q_flags |= QFLAGS_WANT_GLUE | QFLAGS_WANT_NEGSOA;
E 23
I 6
	subq->q_callwhendone = askforns_subquery_complete;
E 6
D 7
	put_query_on_queue(q, QSTATE_STAGE);
E 7
I 7
D 26
	put_query_on_queue(subq, QSTATE_STAGE);
E 26
I 26
	stage_query(subq);
E 26
E 7
E 5
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
D 18
 * RRset) to have multiple A records, I haven't encountered this kind
 * of usage in the real world.  For now we punt and only send to the
 * first A.
E 18
I 18
 * RRset) to have multiple A records, such usage is uncommon in the real
 * world: instead the standard practice is to have largish NS RRsets
 * with one A record per NS.  Consequently, we make no real effort to
 * try all As of a given NS in turn: instead we only iterate through the
 * NS RRset, and if a given NS has multiple As, we merely pick a random
 * one to send our query to, and don't keep track of which As belonging
 * to the same server have or haven't been tried.
E 18
 */
void
askforns_sendforreal(q, srv)
	register struct query *q;
	register struct nsrr *srv;
{
	struct sockaddr_in dest;
	register struct timesched *t;
	register struct udpout *uo;
I 18
	register int i;
E 18

I 18
	if (srv->nsrr_addrcnt > 1)
		i = random() % srv->nsrr_addrcnt;
	else
		i = 0;
E 18
	dest.sin_family = AF_INET;
D 18
	dest.sin_addr.s_addr = srv->nsrr_addrs[0];
E 18
I 18
	dest.sin_addr.s_addr = srv->nsrr_addrs[i];
E 18
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
I 5
D 7
	q->q_retrycnt++;
E 7
E 5
E 4
}
E 1
