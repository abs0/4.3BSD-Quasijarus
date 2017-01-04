/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Full service resolver: handling responses from foreign NS
 */

#ifndef lint
static char sccsid[] = "@(#)queryfor.c	1.24 (IFCTF) 2013/08/10";
#endif

#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "dname.h"
#include "class.h"
#include "tree.h"
#include "nsrec.h"
#include "query.h"
#include "globals.h"
#include "msgparse.h"
#include "udpout.h"

extern u_char *msgparse_extract_rr();
extern struct node *node_findchild(), *get_node_for_cache();
extern struct rr *internalize_rr();

/*
 * XXX kludge: we use static variables below to track NS records
 * in foreign responses which appear to be a refresh of the cached
 * referral that got us here in the first place.  These variables
 * persist only for the processing of a single foreign response and
 * really ought to be stack-allocated, but given that we have no
 * threads or signal handlers or the like, we cheat...
 */

#define	NS_REFRESH_MAX	20
static u_char *ns_refresh_array[NS_REFRESH_MAX];
static int ns_refresh_count;
static u_long ns_refresh_ttl;

dname_under_noa(q, dn)
	struct query *q;
	register struct dname *dn;
{
	register struct dname *qname;
	register int d, noa_depth;

	noa_depth = q->q_noa_depth;
	if (dn->dn_nlabels < noa_depth)
		return(0);
	qname = &q->q_stages[q->q_curstage].qs_qname;
	for (d = 1; d <= noa_depth; d++) {
		if (!label_match(dn->dn_labels[dn->dn_nlabels-d],
				 qname->dn_labels[qname->dn_nlabels-d]))
			return(0);
	}
	return(1);
}

static
check_encroach(q, dn)
	struct query *q;
	register struct dname *dn;
{
	register int depth;
	register struct node *n, *ch;

	n = q->q_noa;
	depth = dn->dn_nlabels - q->q_noa_depth;
	for (; depth--; n = ch) {
		ch = node_findchild(&n->n_nzch, dn->dn_labels[depth], 0);
		if (!ch)
			ch = node_findchild(&n->n_zonech,
					    dn->dn_labels[depth], 0);
		if (!ch)
			return(0);
		if (ch->n_ns && ch->n_ns->ns_type != NSTYPE_CACHEDREF)
			return(-1);
	}
	return(0);
}

u_char *
fsr_handle_answer(q, cp, msg, msglen, ancount, cname_buf)
	register struct query *q;
	u_char *cp, *msg;
	int msglen, ancount;
	struct dname *cname_buf;
{
	register HEADER *hdrout;
	register struct query_stage *qs;
	struct parsedrr rr;
	int i;
	register struct dname *expected_owner;
	struct rr *cache_chain_head = 0;
	struct rr **cache_chain_tail = &cache_chain_head;
	struct node *cn = 0;
	register struct rr *srr;
	time_t cache_expire = 0;
	u_char *rr_start;

	qs = &q->q_stages[q->q_curstage];
	hdrout = (HEADER *)q->q_msg;
	expected_owner = &qs->qs_qname;
	qs->qs_result = QSRESULT_NOREC;
	for (i = 0; i < ancount; i++) {
		rr_start = cp;
		cp = msgparse_extract_rr(&rr, cp, msg + msglen, msg);
		if (!cp) {
			if (q->q_trace)
				fprintf(q->q_trace,
				"error extracting RR #%d from answer section\n",
					i);
error_out:		qs->qs_result = QSRESULT_ERROR;
			if (cache_chain_head)
				free_rrchain(cache_chain_head);
			return(0);
		}
		if (!dname_compare(&rr.prr_owner, expected_owner)) {
			if (q->q_trace)
				fprintf(q->q_trace,
					"answer RR #%d: wrong owner, skipped\n",
					i);
			continue;
		}
		if (q->q_trace)
			fprintf(q->q_trace, "answer RR #%d: type=%d class=%d\n",
				i, rr.prr_fix.type, rr.prr_fix.class);
		if (msgparse_rdata(&rr, msg) < 0) {
			if (q->q_trace)
				fprintf(q->q_trace,
					"answer RR #%d: RDATA parse error\n",
					i);
			goto error_out;
		}
		switch (rr.prr_fix.type) {
		case T_CNAME:
			if (q->q_trace)
				fputs("got CNAME\n", q->q_trace);
			/*
			 * We cache a received CNAME if the RR class
			 * matches the query/tree class and if the
			 * CNAME target doesn't equal the CNAME owner.
			 *
			 * For the purpose of this caching it doesn't
			 * matter whether the CNAME itself answers the
			 * query or not.
			 */
			if (rr.prr_fix.class == q->q_class->c_class &&
			    !dname_compare(&rr.prr_owner, &rr.prr_rdata_dn[0]))
				fsrcache_store_cname(q, &rr);
			/* does it answer the query? */
			if (q->q_type == T_CNAME || q->q_type == T_ANY ||
			    qs->qs_answer_rrcount) {
				if (q->q_trace)
					fprintf(q->q_trace,
						"CNAME accepted as answer\n");
				goto answer;
			}
			/* nope, needs messy CNAME handling */
			if (emit_parsedrr_into_msg(q, &rr) < 0) {
				if (q->q_trace)
					fputs("returning TC\n", q->q_trace);
				qs->qs_result = QSRESULT_TC;
				qs->qs_flags |= QSFLAGS_TC;
				return(cp);
			}
			hdrout->ancount++;
			qs->qs_cname_rrcount++;
			dname_copy_discontig(&rr.prr_rdata_dn[0], cname_buf);
			qs->qs_result = QSRESULT_CNAME;
			if (!dname_under_noa(q, cname_buf)) {
				if (q->q_trace)
					fprintf(q->q_trace,
		"CNAME is not under our NOA, will do it as a new stage\n");
				return(cp);
			}
			if (check_encroach(q, cname_buf)) {
				if (q->q_trace)
					fprintf(q->q_trace,
	"CNAME is encroaching on another NOA, will do it as a new stage\n");
				return(cp);
			}
			if (q->q_trace)
				fprintf(q->q_trace,
			"CNAME falls under NOA, continuing in this stage\n");
			expected_owner = cname_buf;
			q->q_answer_ptr = q->q_msgptr;
			break;
		case T_NS:
			if (rr.prr_owner.dn_nlabels == q->q_noa_depth &&
			    rr.prr_fix.class == q->q_class->c_class) {
				if (ns_refresh_count < NS_REFRESH_MAX)
					ns_refresh_array[ns_refresh_count++] =
						rr_start;
				if (rr.prr_fix.ttl < ns_refresh_ttl)
					ns_refresh_ttl = rr.prr_fix.ttl;
			}
			/* FALL THRU */
		default:
		answer:
			qs->qs_result = QSRESULT_ANSWER;
			if (!(qs->qs_flags & QSFLAGS_TC)) {
				if (emit_parsedrr_into_msg(q, &rr) >= 0) {
					hdrout->ancount++;
					qs->qs_answer_rrcount++;
				} else
					qs->qs_flags |= QSFLAGS_TC;
			}
			if (cache_chain_tail) {
				if (rr.prr_fix.ttl > ttl_limit_data)
					rr.prr_fix.ttl = ttl_limit_data;
				if (rr.prr_fix.ttl < ttl_sensible_min)
					continue;
				if (!cn) {
					cn = get_node_for_cache(q,
							&rr.prr_owner, 1);
					if (!cn)
						goto cache_fail;
				}
				srr = internalize_rr(&rr, rr.prr_fix.ttl);
				if (srr) {
					*cache_chain_tail = srr;
					cache_chain_tail = &srr->rr_next;
					if (srr->rr_expire > cache_expire)
						cache_expire = srr->rr_expire;
				} else {
					free_rrchain(cache_chain_head);
					cache_chain_head = 0;
cache_fail:				cache_chain_tail = 0;
				}
			}
		}
	}
	if (cache_chain_head)
		fsrcache_store_posans(cn, cache_chain_head, q->q_type,
					cache_expire);
	return(cp);
}

u_char *
fsr_scan_ns_after_answer(q, cp, msg, msglen, nscount)
	register struct query *q;
	register u_char *cp;
	u_char *msg;
	int msglen, nscount;
{
	struct parsedrr rr;
	int i;
	register u_char *rr_start;

	for (i = 0; i < nscount; i++) {
		rr_start = cp;
		cp = msgparse_extract_rr(&rr, cp, msg + msglen, msg);
		if (!cp) {
			if (q->q_trace)
				fprintf(q->q_trace,
				"error extracting RR #%d from NS section\n", i);
			return(0);
		}
		if (rr.prr_fix.type != T_NS)
			continue;
		if (rr.prr_fix.class != q->q_class->c_class)
			continue;
		if (rr.prr_owner.dn_nlabels != q->q_noa_depth)
			continue;
		if (!dname_under_noa(q, &rr.prr_owner))
			continue;
		if (ns_refresh_count < NS_REFRESH_MAX)
			ns_refresh_array[ns_refresh_count++] = rr_start;
		if (rr.prr_fix.ttl < ns_refresh_ttl)
			ns_refresh_ttl = rr.prr_fix.ttl;
	}
	return(cp);
}

fsr_refresh_ns(q, msg, msglen)
	register struct query *q;
	u_char *msg;
	int msglen;
{
	u_char *endp = msg + msglen;
	register struct ns_rrset *ns = q->q_noa->n_ns;
	register struct nsrr *srv;
	struct parsedrr rr;
	time_t newexp;
	register int i, match;

	if (q->q_trace)
		fprintf(q->q_trace,
			"got some NS records for our existing NOA\n");
	if (!ns || ns->ns_type != NSTYPE_CACHEDREF) {
		if (q->q_trace)
			fprintf(q->q_trace,
			"fsr_refresh_ns(): no CACHEDREF, nothing to do\n");
		return(0);
	}
	newexp = current_time + ns_refresh_ttl;
	if (newexp <= ns->ns_expire) {
		if (q->q_trace)
			fprintf(q->q_trace,
				"new NS RRset is no better than the old\n");
		return(0);
	}
	/*
	 * Now the tedious part: ensure that the new NS RRset
	 * equals or is a superset of the one we already have.
	 */
	for (srv = ns->ns_chain; srv; srv = srv->nsrr_next) {
		match = 0;
		for (i = 0; i < ns_refresh_count; i++) {
			msgparse_extract_rr(&rr, ns_refresh_array[i], endp,
					    msg);
			if (msgparse_rdata(&rr, msg) < 0) {
				if (q->q_trace)
					fprintf(q->q_trace,
				"fsr_refresh_ns(): RDATA parse error\n");
				return(0);
			}
			if (dname_compare((struct dname *)(srv + 1),
					  &rr.prr_rdata_dn[0])) {
				match = 1;
				break;
			}
		}
		if (!match) {
			if (q->q_trace)
				fprintf(q->q_trace,
			"old NS not found in the new RRset: not updating\n");
			return(0);
		}
	}
	if (q->q_trace)
		fprintf(q->q_trace,
	"new RRset is a superset of the existing, extending expiration\n");
	ns->ns_expire = newexp;
	return(1);
}

static void
mark_for_deletion(ns)
	struct ns_rrset *ns;
{
	register struct nsrr *ind;

	for (ind = ns->ns_chain; ind; ind = ind->nsrr_next)
		ind->nsrr_flags |= NSRR_FLAGS_DELETE;
}

static void
delete_old_nsrr(ns)
	register struct ns_rrset *ns;
{
	register struct nsrr *ind, **indp;

	indp = &ns->ns_chain;
loop:	for (; ind = *indp; indp = &ind->nsrr_next)
		if (ind->nsrr_flags & NSRR_FLAGS_DELETE) {
			*indp = ind->nsrr_next;
			if (ns->ns_roundrobin == ind)
				ns->ns_roundrobin = 0;
			free(ind);
			ns->ns_count--;
			goto loop;
		}
	if (ns->ns_count < 1) {
		syslog(LOG_CRIT, "BUG: ns_count<1 after NS RRset update");
		abort();
	}
}

struct node *
fsr_handle_auth(q, cp, msg, msglen, nscount, rrset_owner)
	register struct query *q;
	u_char *cp, *msg;
	int msglen, nscount;
	register struct dname *rrset_owner;
{
	HEADER *hdrout;
	struct query_stage *qs;
	struct parsedrr rr;
	int i;
	register struct node *n = 0;
	register int rrset_status = 0;

	qs = &q->q_stages[q->q_curstage];
	hdrout = (HEADER *)q->q_msg;
	for (i = 0; i < nscount; i++) {
		cp = msgparse_extract_rr(&rr, cp, msg + msglen, msg);
		if (!cp) {
			if (q->q_trace)
				fprintf(q->q_trace,
				"error extracting RR #%d from NS section\n", i);
			break;
		}
		if (q->q_trace)
			fprintf(q->q_trace, "auth RR #%d: type=%d class=%d\n",
				i, rr.prr_fix.type, rr.prr_fix.class);
		if (rr.prr_fix.class != q->q_class->c_class) {
			if (q->q_trace)
				fprintf(q->q_trace,
					"auth RR #%d: wrong class, skipped\n",
					i);
			continue;
		}
		switch (rrset_status) {
		case 0:
			if (!dname_under_noa(q, &rr.prr_owner)) {
				if (q->q_trace)
					fprintf(q->q_trace,
					"RR owner not under NOA, skipped\n");
				continue;
			}
			dname_copy_discontig(&rr.prr_owner, rrset_owner);
			break;
		case 1:
			if (!dname_compare(&rr.prr_owner, rrset_owner)) {
				if (q->q_trace)
					fprintf(q->q_trace,
				"RR owner doesn't match previous, skipped\n");
				continue;
			}
			break;
		default:
			if (q->q_trace)
				fputs("skip-all\n", q->q_trace);
			continue;
		}
		switch (rr.prr_fix.type) {
		case T_NS:
			break;
		case T_SOA:
			if (rrset_status) {
				if (q->q_trace)
					fprintf(q->q_trace,
				"already accepted NS, can't accept SOA\n");
				continue;
			}
			if (!(qs->qs_flags & QSFLAGS_AA)) {
				if (q->q_trace)
					fprintf(q->q_trace,
				"not accepting negative SOA with AA=0\n");
				continue;
			}
			if (!dname_is_under(&qs->qs_qname, rrset_owner)) {
				if (q->q_trace)
					fprintf(q->q_trace,
			"SOA owner is not above QNAME, not accepting\n");
				continue;
			}
			if (msgparse_rdata(&rr, msg) < 0) {
				if (q->q_trace)
					fprintf(q->q_trace,
						"SOA RDATA parse error\n");
				continue;
			}
			if (q->q_trace)
				fputs("accepting negative SOA\n", q->q_trace);
			if (q->q_flags & QFLAGS_WANT_NEGSOA &&
			    emit_parsedrr_into_msg(q, &rr) >= 0)
				hdrout->nscount = 1;
			fsrcache_store_negans(q, &rr);
			return(0);
		default:
			continue;
		}
		/* handle NS */
		if (msgparse_rdata(&rr, msg) < 0) {
			if (q->q_trace)
				fprintf(q->q_trace, "NS RDATA parse error\n");
			continue;
		}
		if (!rrset_status) {
			if (rrset_owner->dn_nlabels == q->q_noa_depth) {
				if (q->q_trace)
					fprintf(q->q_trace,
					"referral back to itself, lame\n");
				return(0);
			}
			if (!dname_is_under(&qs->qs_qname, rrset_owner)) {
				if (q->q_trace)
					fprintf(q->q_trace,
				"referral doesn't bring us closer to QNAME\n");
				qs->qs_result = QSRESULT_ERROR;
				return(0);
			}
			if (q->q_trace)
				fprintf(q->q_trace,
					"creating new CACHEDREF\n");
			n = get_node_for_cache(q, rrset_owner, 0);
			if (!n) {
				if (q->q_trace)
					fprintf(q->q_trace,
					"can't get a node for the referral!\n");
				qs->qs_result = QSRESULT_ERROR;
				return(0);
			}
			if (n->n_ns)
				mark_for_deletion(n->n_ns);
			rrset_status = 1;
		}
		if (rr.prr_fix.ttl < ttl_bump_ns)
			rr.prr_fix.ttl = ttl_bump_ns;
		if (attach_ns_to_node(n, &rr, 1) < 0) {
			if (q->q_trace)
				fprintf(q->q_trace, "unable to attach NS RR\n");
			qs->qs_result = QSRESULT_ERROR;
			return(0);
		}
		if (q->q_trace)
			fputs("NS RR accepted\n", q->q_trace);
	}
	/* clean up the new NOA */
	if (n) {
		if (!n->n_ns || n->n_ns->ns_type != NSTYPE_CACHEDREF) {
			syslog(LOG_CRIT,
	"BUG in fsr_handle_auth(): finishing part has a node but no CACHEDREF");
			abort();
		}
		delete_old_nsrr(n->n_ns);
	}
	return(n);
}

fsr_extract_ns_addrs(q, cp, msg, msglen, noa)
	register struct query *q;
	register u_char *cp;
	u_char *msg;
	int msglen;
	struct node *noa;
{
	u_char *endp = msg + msglen;
	register struct ns_rrset *ns = noa->n_ns;
	register struct nsrr *srv;
	struct parsedrr rr;
	int count;
	time_t newexp;

	if (!ns || ns->ns_type != NSTYPE_CACHEDREF) {
		if (q->q_trace)
			fprintf(q->q_trace,
		"fsr_extract_ns_addrs(): no CACHEDREF, nothing to do\n");
		return(0);
	}
	for (count = 0; cp < endp; ) {
		cp = msgparse_extract_rr(&rr, cp, endp, msg);
		if (!cp)
			break;
		if (rr.prr_fix.type != T_A || rr.prr_fix.class != C_IN ||
		    rr.prr_fix.rdlength != 4)
			continue;
		for (srv = ns->ns_chain; srv; srv = srv->nsrr_next)
			if (dname_compare((struct dname *)(srv + 1),
					  &rr.prr_owner))
				break;
		if (!srv)
			continue;
		if (rr.prr_fix.ttl < ttl_bump_ns)
			rr.prr_fix.ttl = ttl_bump_ns;
		newexp = current_time + MIN(rr.prr_fix.ttl, ttl_limit_ns);
		if (newexp < srv->nsrr_A_expire) {
			if (q->q_trace) {
				fputs("server ", q->q_trace);
				print_dname((struct dname *)(srv + 1),
						q->q_trace);
				fprintf(q->q_trace,
			": new A expires sooner than the old, not accepting\n");
			}
			continue;
		}
		if (q->q_trace) {
			fprintf(q->q_trace,
				"accepting A %u.%u.%u.%u for server ",
				rr.prr_rdata[0], rr.prr_rdata[1],
				rr.prr_rdata[2], rr.prr_rdata[3]);
			print_dname(&rr.prr_owner, q->q_trace);
			putc('\n', q->q_trace);
		}
		bcopy(rr.prr_rdata, &srv->nsrr_addrs[0], 4);
		srv->nsrr_addrcnt = 1;
		srv->nsrr_A_expire = newexp;
		count++;
	}
	return(count);
}

fsr_forward_addinfo(q, cp, msg, msglen, arcount)
	register struct query *q;
	u_char *cp, *msg;
	int msglen, arcount;
{
	register HEADER *hdrout;
	struct parsedrr rr;
	int i;

	hdrout = (HEADER *)q->q_msg;
	if (q->q_trace)
		fputs("forwarding AR section\n", q->q_trace);
	for (i = 0; i < arcount; i++) {
		cp = msgparse_extract_rr(&rr, cp, msg + msglen, msg);
		if (!cp) {
			if (q->q_trace)
				fprintf(q->q_trace,
				"AR #%d: unable to extract from src msg\n",
					i);
			break;
		}
		if (msgparse_rdata(&rr, msg) < 0) {
			if (q->q_trace)
				fprintf(q->q_trace,
					"AR #%d: RDATA parse error\n", i);
			continue;
		}
		if (emit_parsedrr_into_msg(q, &rr) < 0) {
			if (q->q_trace)
				fprintf(q->q_trace,
					"AR #%d doesn't fit into resp msg\n",
					i);
			stats_fwd_ar_tc++;
			break;
		}
		hdrout->arcount++;
	}
	return(hdrout->arcount);
}

void
fsr_handle_response(q, msg, msglen)
	register struct query *q;
	u_char *msg;
	int msglen;
{
	register HEADER *hdrin;
	register struct query_stage *qs;
	u_char *cp, *answer_start;
	int ancount, nscount, arcount;
	struct dname dnscratch;
	register struct node *newnoa;

	hdrin = (HEADER *)msg;
	ancount = ntohs(hdrin->ancount);
	nscount = ntohs(hdrin->nscount);
	arcount = ntohs(hdrin->arcount);
	if (q->q_trace)
		fprintf(q->q_trace,
	"parsing foreign response: RCODE=%d ANCOUNT=%d NSCOUNT=%d ARCOUNT=%d\n",
			hdrin->rcode, ancount, nscount, arcount);
	qs = &q->q_stages[q->q_curstage];
	switch (hdrin->rcode) {
	case NOERROR:
	case NXDOMAIN:
		break;
	default:
		if (q->q_trace)
			fprintf(q->q_trace, "not NOERROR or NXDOMAIN, fail\n");
error_out:	qs->qs_result = QSRESULT_ERROR;
out:		free_subtree(q->q_noa);
		query_complete(q);
		return;
	}
	if (hdrin->aa)
		qs->qs_flags |= QSFLAGS_AA;
	/* start parsing! */
	if (hdrin->qdcount)
		cp = msg + q->q_udpout->uo_querylen;
	else
		cp = msg + sizeof(HEADER);
	answer_start = cp;
	ns_refresh_count = 0;
	ns_refresh_ttl = ttl_limit_ns;
	if (ancount)
		cp = fsr_handle_answer(q, cp, msg, msglen, ancount, &dnscratch);
	else
		qs->qs_result = QSRESULT_NOREC;
	switch (qs->qs_result) {
	case QSRESULT_ANSWER:
		cp = fsr_scan_ns_after_answer(q, cp, msg, msglen, nscount);
		if (ns_refresh_count && hdrin->aa &&
		    fsr_refresh_ns(q, msg, msglen))
			fsr_extract_ns_addrs(q, answer_start, msg, msglen,
						q->q_noa);
		if (cp && arcount && !(qs->qs_flags & QSFLAGS_TC) &&
		    fsr_forward_addinfo(q, cp, msg, msglen, arcount))
			qs->qs_flags |= QSFLAGS_ADD_FORWARDED;
		goto out;
	case QSRESULT_NOREC:
		break;
	case QSRESULT_CNAME:
		free_subtree(q->q_noa);
		qstage_handle_cname(q, &dnscratch);
		return;
	case QSRESULT_ERROR:
	case QSRESULT_TC:
		goto out;
	default:
		syslog(LOG_CRIT,
			"BUG: unexpected result from fsr_handle_answer()\n");
		abort();
	}
	if (q->q_trace)
		fputs("no answer\n", q->q_trace);
	if (hdrin->rcode == NXDOMAIN)
		qs->qs_result = QSRESULT_NXDOMAIN;
	newnoa = fsr_handle_auth(q, cp, msg, msglen, nscount, &dnscratch);
	if (newnoa)
		fsr_extract_ns_addrs(q, answer_start, msg, msglen, newnoa);
	else {
		if (hdrin->aa) {
			if (q->q_trace)
				fprintf(q->q_trace,
			"no referral, AA set, accepting NXDOMAIN/NOREC\n");
			goto out;
		} else {
			if (q->q_trace)
				fprintf(q->q_trace,
				"no referral, AA clear, converting to ERROR\n");
			goto error_out;
		}
	}
	if (q->q_trace) {
		fputs("referral: new NOA is ", q->q_trace);
		print_dname(&dnscratch, q->q_trace);
		putc('\n', q->q_trace);
		fputs("resubmitting to askforns layer\n", q->q_trace);
	}
	newnoa->n_refcount++;
	free_subtree(q->q_noa);
	q->q_noa = newnoa;
	q->q_noa_depth = dnscratch.dn_nlabels;
	qs->qs_flags = 0; /* disregard any AA from intermediate referrals */
	askforns_entry(q);
}

void
fsr_handle_error(q)
	register struct query *q;
{
	if (q->q_trace)
		fprintf(q->q_trace,
			"askforns layer returned error indication\n");
	free_subtree(q->q_noa);
	q->q_stages[q->q_curstage].qs_result = QSRESULT_ERROR;
	query_complete(q);
}
