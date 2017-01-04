h35666
s 00014/00014/00408
d D 1.23 2013/08/10 07:11:43 msokolov 23 22
c external queries bypass the queue
e
s 00003/00000/00419
d D 1.22 2013/01/13 15:31:47 msokolov 22 21
c duplicate query suppression implemented
e
s 00015/00077/00404
d D 1.21 2013/01/11 23:02:48 msokolov 21 20
c first round of changes for the new FSR cache design
e
s 00001/00001/00480
d D 1.20 2013/01/06 07:03:57 msokolov 20 19
c MSDNS => FalconDNS
e
s 00002/00000/00479
d D 1.19 2011/12/21 07:18:16 msokolov 19 18
c suppress NS duplication between answer and authority sections
e
s 00005/00004/00474
d D 1.18 2011/12/20 20:45:19 msokolov 18 17
c query flags slightly revamped
e
s 00007/00011/00471
d D 1.17 2011/12/19 08:03:49 msokolov 17 16
c axed NSRR_FLAGS_BAD, preparing for caching foreign NS temp failures
e
s 00001/00001/00481
d D 1.16 2011/12/13 23:28:18 msokolov 16 15
c NS answer fix for AXFR serving
e
s 00028/00023/00454
d D 1.15 2011/12/08 05:15:37 msokolov 15 14
c configurable policy settings for caching/glue corner cases
e
s 00017/00001/00460
d D 1.14 2011/12/08 01:39:52 msokolov 14 13
c guard against returning stale anchors/referrals to NS/* queries
e
s 00006/00006/00455
d D 1.13 2011/12/07 07:40:01 msokolov 13 12
c recursive query logic hooked in
e
s 00002/00001/00459
d D 1.12 2011/12/01 05:22:04 msokolov 12 11
c minimum TTL for NS records returned as referrals
e
s 00001/00001/00459
d D 1.11 2011/11/05 10:06:43 msokolov 11 10
c no need for a per-stage answer pointer
e
s 00003/00001/00457
d D 1.10 2011/11/01 08:59:40 msokolov 10 9
c implemented A additional data return for referrals
e
s 00051/00017/00407
d D 1.9 2011/11/01 08:00:51 msokolov 9 8
c NOA concept rethought
e
s 00009/00006/00415
d D 1.8 2011/11/01 05:54:42 msokolov 8 7
c safer and more sensible handling of RR owner names
e
s 00033/00014/00388
d D 1.7 2011/10/31 08:44:53 msokolov 7 6
c minimum TTL, AXFR and other logic fixes
e
s 00079/00004/00323
d D 1.6 2011/10/30 07:41:18 msokolov 6 5
c trace implemented
e
s 00021/00016/00306
d D 1.5 2011/10/30 01:16:53 msokolov 5 4
c query processing shaping up
e
s 00030/00000/00292
d D 1.4 2011/10/29 22:01:48 msokolov 4 3
c catch those cached referrals that have gone unusable but not expired
e
s 00047/00031/00245
d D 1.3 2011/10/29 20:39:16 msokolov 3 2
c cached RR expiration implemented
e
s 00031/00020/00245
d D 1.2 2011/10/29 19:19:31 msokolov 2 1
c qstage_handle_cname() factored out
e
s 00265/00000/00000
d D 1.1 2011/10/29 10:06:43 msokolov 1 0
c date and time created 2011/10/29 10:06:43 by msokolov
e
u
U
t
T
I 1
/*
D 20
 * Michael Sokolov's Domain Name Server (MSDNS)
E 20
I 20
 * FalconDNS daemon by Michael Spacefalcon
E 20
 *
 * Main query stage processing
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include "dname.h"
#include "class.h"
#include "tree.h"
#include "nsrec.h"
#include "query.h"
#include "globals.h"

extern struct node *node_findchild();
I 21
extern struct dname *fsrcache_look_for_cname();
E 21
I 13
extern void fsr_handle_response(), fsr_handle_error();
E 13

I 14
D 21
static
is_ns_returnable(ns)
	register struct ns_rrset *ns;
{
	switch (ns->ns_type) {
	case NSTYPE_ZONEHEAD:
D 15
	case NSTYPE_DELEGATION:
E 15
		return(1);
I 15
	case NSTYPE_DELEGATION:
		return(nsglue_answers);
E 15
	case NSTYPE_ANCHOR:
	case NSTYPE_CACHEDREF:
		return(ns->ns_expire > current_time);
	}
	return(0);
}

E 14
D 3
qstage_answer_from_node(q, n, wild, rrchain)
E 3
I 3
qstage_answer_from_node(q, n, wild, do_cache)
E 21
I 21
qstage_answer_from_zone(q, n, wild)
E 21
E 3
	register struct query *q;
D 3
	register struct node *n;
	int wild;
	struct rr *rrchain;
E 3
I 3
	struct node *n;
D 21
	int wild, do_cache;
E 21
I 21
	int wild;
E 21
E 3
{
	register struct query_stage *qs;
D 8
	struct dname owner;
E 8
I 8
	struct dname *owner, owner_st;
E 8
	int owner_set = 0;
	HEADER *hdr = (HEADER *)q->q_msg;
D 3
	register struct rr *rr;
E 3
I 3
D 21
	register struct rr *rr, **rrp;
E 21
I 21
	register struct rr *rr;
E 21
E 3
	register int accept;
I 7
	u_long minttl;
E 7

	qs = &q->q_stages[q->q_curstage];
I 7
	if (n->n_zonehead && q->q_type != T_AXFR)
		minttl = n->n_zonehead->n_soa->soa_minimum;
	else
		minttl = 0;
E 7
	/* do SOA and NS first */
D 7
	if (n->n_soa && (q->q_type == T_SOA || q->q_type == T_ANY) && !wild) {
E 7
I 7
	if (n->n_soa &&
	    (q->q_type == T_SOA || q->q_type == T_ANY || q->q_type == T_AXFR)) {
E 7
		if (emit_soa_into_msg(q, n) < 0) {
			qs->qs_flags |= QSFLAGS_TC;
			return(-1);
		}
		qs->qs_answer_rrcount++;
		hdr->ancount++;
	}
D 7
	if (n->n_ns && (q->q_type == T_NS || q->q_type == T_ANY) && !wild) {
		if (emit_ns_rrset_into_msg(q, n) < 0) {
E 7
I 7
	if (n->n_ns &&
D 14
	    (q->q_type == T_NS || q->q_type == T_ANY || q->q_type == T_AXFR)) {
E 14
I 14
D 21
	    (q->q_type == T_NS || q->q_type == T_ANY || q->q_type == T_AXFR) &&
D 16
	    is_ns_returnable(n->n_ns)) {
E 16
I 16
	    (!do_cache || is_ns_returnable(n->n_ns))) {
E 21
I 21
	    (q->q_type == T_NS || q->q_type == T_ANY || q->q_type == T_AXFR)) {
E 21
E 16
E 14
		if (emit_ns_rrset_into_msg(q, n, minttl) < 0) {
E 7
			qs->qs_flags |= QSFLAGS_TC;
			return(-1);
		}
		qs->qs_answer_rrcount += n->n_ns->ns_count;
		hdr->ancount += n->n_ns->ns_count;
	}
	/* now do the general RRs */
D 3
	for (rr = rrchain; rr; rr = rr->rr_next) {
E 3
I 3
D 21
	rrp = do_cache ? &n->n_rrcache : &n->n_rrzone;
	while (rr = *rrp) {
		/* cached RR expiration is handled here */
		if (do_cache && current_time >= rr->rr_expire) {
			*rrp = rr->rr_next;
			free(rr);
			continue;
		}
E 21
I 21
	for (rr = n->n_rrzone; rr; rr = rr->rr_next) {
E 21
E 3
		switch (q->q_type) {
		case T_SOA:
		case T_NS:
D 3
			/* don't bother looking for these */
			return(qs->qs_answer_rrcount);
E 3
I 3
			/*
			 * Don't bother looking for these,
			 * we know they can't be there.
			 */
D 21
			if (!do_cache)
				return(qs->qs_answer_rrcount);
			/*
			 * If looking in the cache, plow through
			 * the rest in order to get rid of any
			 * expired RRs.
			 */
			accept = 0;
			break;
E 21
I 21
			return(qs->qs_answer_rrcount);
E 21
E 3
		case T_ANY:
I 7
		case T_AXFR:
E 7
			accept = 1;
			break;
		case T_MAILB:
			switch (rr->rr_type) {
			case T_MB:
			case T_MG:
			case T_MR:
				accept = 1;
				break;
			default:
				accept = 0;
			}
			break;
		default:
			accept = (rr->rr_type == q->q_type);
		}
D 3
		if (!accept)
			continue;
		if (!owner_set) {
			get_rr_owner_dname(q, n, wild, &owner);
			owner_set = 1;
E 3
I 3
		if (accept) {
			if (!owner_set) {
D 8
				get_rr_owner_dname(q, n, wild, &owner);
E 8
I 8
				if (wild)
					owner = &qs->qs_qname;
				else {
					dname_of_node(n, &owner_st);
					owner = &owner_st;
				}
E 8
				owner_set = 1;
			}
D 7
			if (emit_genrr_into_msg(q, &owner, rr) < 0) {
E 7
I 7
D 8
			if (emit_genrr_into_msg(q, &owner, rr, minttl) < 0) {
E 8
I 8
			if (emit_genrr_into_msg(q, owner, rr, minttl) < 0) {
E 8
E 7
				qs->qs_flags |= QSFLAGS_TC;
				return(-1);
			}
			qs->qs_answer_rrcount++;
			hdr->ancount++;
E 3
		}
D 3
		if (emit_genrr_into_msg(q, &owner, rr) < 0) {
			qs->qs_flags |= QSFLAGS_TC;
			return(-1);
		}
		qs->qs_answer_rrcount++;
		hdr->ancount++;
E 3
I 3
D 21
		rrp = &rr->rr_next;
E 21
E 3
	}
	return(qs->qs_answer_rrcount);
}

struct dname *
D 3
qstage_cname_from_node(q, n, wild, rrchain)
E 3
I 3
D 21
qstage_cname_from_node(q, n, wild, do_cache)
E 21
I 21
qstage_cname_from_zone(q, n, wild)
E 21
E 3
	register struct query *q;
	struct node *n;
D 3
	int wild;
	struct rr *rrchain;
E 3
I 3
D 21
	int wild, do_cache;
E 21
I 21
	int wild;
E 21
E 3
{
	register struct query_stage *qs;
D 8
	struct dname owner;
E 8
	HEADER *hdr = (HEADER *)q->q_msg;
	register struct rr *rr;
I 7
	u_long minttl;
E 7

	qs = &q->q_stages[q->q_curstage];
D 3
	for (rr = rrchain; rr; rr = rr->rr_next) {
E 3
I 3
D 21
	for (rr = do_cache ? n->n_rrcache : n->n_rrzone; rr; rr = rr->rr_next) {
E 21
I 21
	for (rr = n->n_rrzone; rr; rr = rr->rr_next) {
E 21
E 3
		if (rr->rr_type != T_CNAME)
			continue;
D 8
		get_rr_owner_dname(q, n, wild, &owner);
E 8
D 7
		if (emit_genrr_into_msg(q, &owner, rr) < 0) {
E 7
I 7
		if (n->n_zonehead)
			minttl = n->n_zonehead->n_soa->soa_minimum;
		else
			minttl = 0;
D 8
		if (emit_genrr_into_msg(q, &owner, rr, minttl) < 0) {
E 8
I 8
		if (emit_genrr_into_msg(q, &qs->qs_qname, rr, minttl) < 0) {
E 8
E 7
			qs->qs_flags |= QSFLAGS_TC;
			return(0);
		}
		qs->qs_cname_rrcount = 1;
		hdr->ancount++;
		return((struct dname *)(rr + 1));
	}
	return(0);
}

I 2
/*
 * This function is called when a query stage has hit a CNAME.
 * It handles loop detection and chain length limiting,
 * then dispatches the query either to the next stage or
D 5
 * to the completion queue.
E 5
I 5
 * to completion processing.
E 5
 */
E 2
void
I 2
qstage_handle_cname(q, cname)
	register struct query *q;
	register struct dname *cname;
{
	register int i;

I 6
	if (q->q_trace) {
		fputs("CNAME ", q->q_trace);
		print_dname(cname, q->q_trace);
		putc('\n', q->q_trace);
	}
E 6
D 5
	for (i = 0; i < q->q_curstage; i++)
E 5
I 5
	for (i = 0; i <= q->q_curstage; i++)
E 5
		if (dname_compare(&q->q_stages[i].qs_qname, cname)) {
			/* CNAME loop */
I 6
			if (q->q_trace)
				fputs("CNAME loop detected\n", q->q_trace);
E 6
D 5
			put_query_on_complq(q);
E 5
I 5
D 23
			put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
			query_complete(q);
E 23
E 5
			return;
		}
	/* is there room for one more stage? */
	if (i <= MAX_CNAME_CHAIN) {
I 6
		if (q->q_trace)
			fputs("CNAME: scheduling the next stage\n", q->q_trace);
E 6
		q->q_curstage = i;
		dname_copy(cname, &q->q_stages[i].qs_qname);
D 5
		put_query_on_queue(q);
E 5
I 5
D 23
		put_query_on_queue(q, QSTATE_STAGE);
E 23
I 23
		stage_query(q);
E 23
E 5
D 6
	} else
E 6
I 6
	} else {
		if (q->q_trace)
			fputs("CNAME: no room left\n", q->q_trace);
E 6
D 5
		put_query_on_complq(q);
E 5
I 5
D 23
		put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
		query_complete(q);
E 23
I 6
	}
E 6
E 5
}

I 4
is_cachedref_unusable(ns)
	register struct ns_rrset *ns;
{
D 17
	register struct nsrr *nsrr;
	register int allbad = 1;
E 17
I 17
	register struct nsrr *srv;
E 17

D 17
	for (nsrr = ns->ns_chain; nsrr; nsrr = nsrr->nsrr_next) {
D 13
		/* expire A first */
		if (nsrr->nsrr_addrcnt && current_time >= nsrr->nsrr_A_expire)
			nsrr->nsrr_addrcnt = 0;
		/* does that make it unusable? */
E 13
		if (nsrr->nsrr_flags & NSRR_FLAGS_NEEDGLUE &&
D 13
		    !nsrr->nsrr_addrcnt)
E 13
I 13
		    (!nsrr->nsrr_addrcnt ||
		     current_time >= nsrr->nsrr_A_expire))
E 13
			nsrr->nsrr_flags |= NSRR_FLAGS_BAD;
		/* we need at least one good server */
		if (!(nsrr->nsrr_flags & NSRR_FLAGS_BAD))
			allbad = 0;
E 17
I 17
	for (srv = ns->ns_chain; srv; srv = srv->nsrr_next) {
		if (srv->nsrr_addrcnt && current_time < srv->nsrr_A_expire)
			return(0);
		if (!(srv->nsrr_flags & NSRR_FLAGS_NEEDGLUE))
			return(0);
E 17
	}
D 17
	return(allbad);
E 17
I 17
	return(-1);
E 17
}

E 4
void
E 2
query_stage_process(q)
	register struct query *q;
{
	register struct query_stage *qs;
D 9
	register struct node *n, *ch;
E 9
I 9
	register struct node *n, *ch, *noa;
E 9
	register int depth;
	int wild = 0;
D 6
	struct dname *cname;
E 6
I 6
	struct dname *cname, scratch_dname;
E 6
D 9
	struct ns_rrset *ns;
E 9
I 5
	HEADER *hdr = (HEADER *)q->q_msg;
E 5

	qs = &q->q_stages[q->q_curstage];
I 6
	if (q->q_trace) {
		fprintf(q->q_trace, "Entering query %d stage %d\n",
			q->q_trace_index, q->q_curstage);
		fputs("QNAME=", q->q_trace);
		print_dname(&qs->qs_qname, q->q_trace);
		putc('\n', q->q_trace);
	}
E 6
D 11
	qs->qs_answer_ptr = q->q_msgptr;
E 11
I 11
	q->q_answer_ptr = q->q_msgptr;
E 11
	qs->qs_cname_rrcount = 0;
	qs->qs_answer_rrcount = 0;
	qs->qs_flags = 0;
D 9
	qs->qs_noa = 0;
E 9
I 4
restart:
E 4
	n = q->q_class->c_root;
I 9
	noa = 0;
E 9
	for (depth = qs->qs_qname.dn_nlabels; n; n = ch) {
		if (n->n_ns) {
			/* cached referrals expire! */
			if (n->n_ns->ns_type == NSTYPE_CACHEDREF &&
			    current_time >= n->n_ns->ns_expire) {
D 7
				free_ns_rrset(n->n_ns);
				n->n_ns = 0;
E 7
I 7
				if (n->n_refcount == 1) {
					free_ns_rrset(n->n_ns);
					n->n_ns = 0;
				}
E 7
D 15
			} else {
E 15
I 15
			} else if (n->n_ns->ns_type != NSTYPE_CACHEDREF ||
				   hdr->rd && hdr->ra ||
				   norec_allow_cached_ref) {
E 15
D 9
				qs->qs_noa = n;
				qs->qs_noa_depth = qs->qs_qname.dn_nlabels
						   - depth;
E 9
I 9
				noa = n;
				q->q_noa_depth = qs->qs_qname.dn_nlabels-depth;
E 9
			}
		}
		if (!depth--)
			break;
		ch = node_findchild(&n->n_nzch, qs->qs_qname.dn_labels[depth],
				    0);
		if (!ch)
			ch = node_findchild(&n->n_zonech,
					    qs->qs_qname.dn_labels[depth], 0);
D 9
		if (!ch && n->n_zonech_wild && qs->qs_noa &&
		    qs->qs_noa->n_zone) {
E 9
I 9
		if (!ch && n->n_zonech_wild && noa && noa->n_zone) {
E 9
			n = n->n_zonech_wild;
			wild = depth + 1;
I 6
			if (q->q_trace) {
				dname_of_node(n, &scratch_dname);
				fputs("using wildcard at ", q->q_trace);
				print_dname(&scratch_dname, q->q_trace);
				putc('\n', q->q_trace);
			}
E 6
			break;
		}
	}
D 9
	if (!qs->qs_noa) {
E 9
I 9
	if (!noa) {
E 9
I 6
		if (q->q_trace)
			fputs("No NOA found\n", q->q_trace);
I 7
D 21
#if 0
		/*
		 * If/when we implement forwarder logic,
		 * it could cache RRs here.
		 * But in the absence of caching forwarder logic
		 * there is no point in looking right now.
		 */
E 7
E 6
D 3
		if (n && qstage_answer_from_node(q, n, 0, n->n_rrcache)) {
E 3
I 3
		if (n && qstage_answer_from_node(q, n, 0, 1)) {
I 6
			if (q->q_trace)
				fputs("found cached answer\n", q->q_trace);
E 6
E 3
			qs->qs_result = QSRESULT_ANSWER;
D 5
			put_query_on_complq(q);
E 5
I 5
			put_query_on_queue(q, QSTATE_COMPLETE);
E 5
			return;
		}
D 3
		if (n && (cname = qstage_cname_from_node(q, n, 0,
							 n->n_rrcache))) {
E 3
I 3
		if (n && (cname = qstage_cname_from_node(q, n, 0, 1))) {
I 6
			if (q->q_trace)
				fputs("found cached CNAME\n", q->q_trace);
E 6
E 3
			qs->qs_result = QSRESULT_CNAME;
D 2
			if (q->q_curstage < MAX_CNAME_CHAIN) {
				q->q_curstage++;
				dname_copy(cname,
					&q->q_stages[q->q_curstage].qs_qname);
				put_query_on_queue(q);
			} else
				put_query_on_complq(q);
E 2
I 2
			qstage_handle_cname(q, cname);
E 2
			return;
		}
		if (qs->qs_flags & QSFLAGS_TC) {
I 6
			if (q->q_trace)
				fputs("found cached CNAME, TC\n", q->q_trace);
E 6
			qs->qs_result = QSRESULT_TC;
D 5
			put_query_on_complq(q);
E 5
I 5
			put_query_on_queue(q, QSTATE_COMPLETE);
E 5
			return;
		}
I 7
#endif
E 21
E 7
		/* the forwarder logic will go here eventually */
I 6
		if (q->q_trace)
			fputs("No NOA, no forwarder: hands empty\n",
				q->q_trace);
E 6
		qs->qs_result = QSRESULT_NOTHING;
D 5
		put_query_on_complq(q);
E 5
I 5
D 23
		put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
		query_complete(q);
E 23
E 5
		return;
	}
	/* sans-NOA case filtered out, now we know we have a NOA */
D 9
	qs->qs_noa->n_refcount++;
	ns = qs->qs_noa->n_ns;
E 9
I 6
	if (q->q_trace) {
		fputs("NOA is ", q->q_trace);
D 9
		dname_of_node(qs->qs_noa, &scratch_dname);
E 9
I 9
		dname_of_node(noa, &scratch_dname);
E 9
		print_dname(&scratch_dname, q->q_trace);
D 9
		fprintf(q->q_trace, " type %d\n", ns->ns_type);
E 9
I 9
		fprintf(q->q_trace, " type %d\n", noa->n_ns->ns_type);
E 9
	}
E 6
D 9
	switch (ns->ns_type) {
E 9
I 9
	switch (noa->n_ns->ns_type) {
E 9
	case NSTYPE_ZONEHEAD:
		qs->qs_flags |= QSFLAGS_AA;
		if (!n) {
I 6
			if (q->q_trace)
				fputs("NXDOMAIN\n", q->q_trace);
E 6
			qs->qs_result = QSRESULT_NXDOMAIN;
I 9
D 18
			if (!(q->q_flags & QFLAGS_INTERNAL) &&
E 18
I 18
			if (q->q_flags & QFLAGS_WANT_NEGSOA &&
E 18
			    emit_soa_into_msg(q, noa) >= 0)
				hdr->nscount = 1;
E 9
D 5
			put_query_on_complq(q);
E 5
I 5
D 23
			put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
			query_complete(q);
E 23
E 5
			return;
		}
D 3
		if (qstage_answer_from_node(q, n, wild, n->n_rrzone)) {
E 3
I 3
D 21
		if (qstage_answer_from_node(q, n, wild, 0)) {
E 21
I 21
		if (qstage_answer_from_zone(q, n, wild)) {
E 21
I 6
			if (q->q_trace)
				fputs("authoritative answer\n", q->q_trace);
E 6
E 3
			qs->qs_result = QSRESULT_ANSWER;
I 9
D 18
			if (!(q->q_flags & QFLAGS_INTERNAL) &&
E 18
I 18
			if (q->q_flags & QFLAGS_WANT_AA_NS &&
E 18
			    !(qs->qs_flags & QSFLAGS_TC) &&
I 19
			    (n != noa ||
				q->q_type != T_NS && q->q_type != T_ANY) &&
E 19
			    emit_ns_rrset_into_msg(q, noa,
				noa->n_soa->soa_minimum) >= 0)
				    hdr->nscount = noa->n_ns->ns_count;
E 9
D 5
			put_query_on_complq(q);
E 5
I 5
D 23
			put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
			query_complete(q);
E 23
E 5
			return;
		}
D 3
		if (cname = qstage_cname_from_node(q, n, wild, n->n_rrzone)) {
E 3
I 3
D 21
		if (cname = qstage_cname_from_node(q, n, wild, 0)) {
E 21
I 21
		if (cname = qstage_cname_from_zone(q, n, wild)) {
E 21
I 6
			if (q->q_trace)
				fputs("authoritative CNAME\n", q->q_trace);
E 6
E 3
			qs->qs_result = QSRESULT_CNAME;
D 2
			if (q->q_curstage < MAX_CNAME_CHAIN) {
				q->q_curstage++;
				dname_copy(cname,
					&q->q_stages[q->q_curstage].qs_qname);
				put_query_on_queue(q);
			} else
				put_query_on_complq(q);
E 2
I 2
			qstage_handle_cname(q, cname);
E 2
			return;
		}
D 6
		if (qs->qs_flags & QSFLAGS_TC)
E 6
I 6
		if (qs->qs_flags & QSFLAGS_TC) {
			if (q->q_trace)
				fputs("authoritative CNAME caused TC\n",
					q->q_trace);
E 6
			qs->qs_result = QSRESULT_TC;
D 6
		else
E 6
I 6
		} else {
			if (q->q_trace)
				fputs("authoritative no data at node\n",
					q->q_trace);
E 6
			qs->qs_result = QSRESULT_NOREC;
I 9
D 18
			if (!(q->q_flags & QFLAGS_INTERNAL) &&
E 18
I 18
			if (q->q_flags & QFLAGS_WANT_NEGSOA &&
E 18
			    emit_soa_into_msg(q, noa) >= 0)
				hdr->nscount = 1;
E 9
I 6
		}
E 6
D 5
		put_query_on_complq(q);
E 5
I 5
D 23
		put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
		query_complete(q);
E 23
E 5
		return;
	case NSTYPE_DELEGATION:
		if (!(q->q_flags & QFLAGS_WANT_GLUE) || !n)
			break;
D 3
		if (qstage_answer_from_node(q, n, 0, n->n_rrzone)) {
E 3
I 3
D 21
		if (qstage_answer_from_node(q, n, 0, 0)) {
E 21
I 21
		if (qstage_answer_from_zone(q, n, 0)) {
E 21
I 6
			if (q->q_trace)
				fputs("answered with glue record from zone\n",
					q->q_trace);
E 6
E 3
			qs->qs_result = QSRESULT_ANSWER;
D 5
			put_query_on_complq(q);
E 5
I 5
D 23
			put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
			query_complete(q);
E 23
E 5
			return;
I 4
		}
		break;
	case NSTYPE_CACHEDREF:
D 9
		if (is_cachedref_unusable(ns)) {
E 9
I 9
		if (is_cachedref_unusable(noa->n_ns)) {
E 9
I 6
			if (q->q_trace)
				fprintf(q->q_trace,
D 7
			"unusable cached referral, clearing and restarting\n");
E 6
			free_ns_rrset(ns);
			qs->qs_noa->n_ns = 0;
E 7
I 7
		"unusable cached referral, invalidating and restarting\n");
D 9
			ns->ns_expire = 0;
E 7
			qs->qs_noa->n_refcount--;
E 9
I 9
			noa->n_ns->ns_expire = 0;
E 9
			goto restart;
E 4
		}
		break;
	}
	/* caching operation */
I 6
D 15
	if (q->q_trace)
		fputs("looking in the cache\n", q->q_trace);
E 6
D 3
	if (n && qstage_answer_from_node(q, n, 0, n->n_rrcache)) {
E 3
I 3
	if (n && qstage_answer_from_node(q, n, 0, 1)) {
E 15
I 15
D 18
	if (n && (hdr->rd && hdr->ra || norec_allow_cached_ans)) {
E 18
I 18
	if (n && (hdr->rd && hdr->ra || norec_allow_cached_ans) &&
	    !(q->q_flags & QFLAGS_WANT_AA)) {
E 18
E 15
I 6
		if (q->q_trace)
D 15
			fputs("found answer\n", q->q_trace);
E 6
E 3
		qs->qs_result = QSRESULT_ANSWER;
D 5
		put_query_on_complq(q);
E 5
I 5
		put_query_on_queue(q, QSTATE_COMPLETE);
E 5
		return;
	}
D 3
	if (n && (cname = qstage_cname_from_node(q, n, 0, n->n_rrcache))) {
E 3
I 3
	if (n && (cname = qstage_cname_from_node(q, n, 0, 1))) {
I 6
		if (q->q_trace)
			fputs("found CNAME\n", q->q_trace);
E 6
E 3
		qs->qs_result = QSRESULT_CNAME;
D 2
		if (q->q_curstage < MAX_CNAME_CHAIN) {
			q->q_curstage++;
			dname_copy(cname, &q->q_stages[q->q_curstage].qs_qname);
			put_query_on_queue(q);
		} else
			put_query_on_complq(q);
E 2
I 2
		qstage_handle_cname(q, cname);
E 2
		return;
	}
	if (qs->qs_flags & QSFLAGS_TC) {
I 6
		if (q->q_trace)
			fputs("found CNAME, TC\n", q->q_trace);
E 6
		qs->qs_result = QSRESULT_TC;
D 5
		put_query_on_complq(q);
E 5
I 5
		put_query_on_queue(q, QSTATE_COMPLETE);
E 5
		return;
E 15
I 15
			fputs("looking in the cache\n", q->q_trace);
D 21
		if (qstage_answer_from_node(q, n, 0, 1)) {
E 21
I 21
		if (fsrcache_look_for_answer(q, n)) {
E 21
			if (q->q_trace)
				fputs("found answer\n", q->q_trace);
D 21
			qs->qs_result = QSRESULT_ANSWER;
E 21
D 23
			put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
			query_complete(q);
E 23
			return;
		}
D 21
		if (cname = qstage_cname_from_node(q, n, 0, 1)) {
E 21
I 21
		if (cname = fsrcache_look_for_cname(q, n)) {
E 21
			if (q->q_trace)
				fputs("found CNAME\n", q->q_trace);
			qs->qs_result = QSRESULT_CNAME;
			qstage_handle_cname(q, cname);
			return;
		}
		if (qs->qs_flags & QSFLAGS_TC) {
			if (q->q_trace)
				fputs("found CNAME, TC\n", q->q_trace);
			qs->qs_result = QSRESULT_TC;
D 23
			put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
			query_complete(q);
E 23
			return;
		}
E 15
	}
D 5
	/* recursion logic will go here */
E 5
I 5
	/* Going to a foreign NS. Return a referral or follow ourselves? */
	if (hdr->rd && hdr->ra) {
I 6
		if (q->q_trace)
			fputs("recursive query, asking foreign NS\n",
				q->q_trace);
I 22
		if (!(q->q_flags & QFLAGS_INTERNAL) && !q->q_dupcatch_backptr
		    && !q->q_trace && query_dup_intercept(q))
			return;
E 22
I 9
		noa->n_refcount++;
		q->q_noa = noa;
E 9
E 6
D 13
		put_query_on_queue(q, QSTATE_FOREIGN);
E 13
I 13
		q->q_askforns_response_callbk = fsr_handle_response;
		q->q_askforns_error_callbk = fsr_handle_error;
		askforns_entry(q);
E 13
		return;
	}
I 6
	if (q->q_trace)
		fputs("iterative query, answering with a referral\n",
			q->q_trace);
I 9
	if (q->q_flags & QFLAGS_INTERNAL) {
		if (q->q_trace)
			fprintf(q->q_trace,
	"internal non-recursive query, assuming referral would be useless\n");
		qs->qs_result = QSRESULT_NOTHING;
D 23
		put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
		query_complete(q);
E 23
		return;
	}
	if (noa->n_ns->ns_type == NSTYPE_ANCHOR &&
	    current_time >= noa->n_ns->ns_expire) {
		if (q->q_trace)
			fprintf(q->q_trace,
	"not supposed to return a non-validated NS-anchor as a referral\n");
		qs->qs_result = QSRESULT_NOTHING;
D 23
		put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
		query_complete(q);
E 23
		return;
	}
D 12
	if (emit_ns_rrset_into_msg(q, noa, 0L) < 0) {
E 12
I 12
	if (emit_ns_rrset_into_msg(q, noa, noa->n_zonehead ?
	    noa->n_zonehead->n_soa->soa_minimum : 0L) < 0) {
E 12
		if (q->q_trace)
			fputs("NS referral didn't fit, setting TC", q->q_trace);
		qs->qs_flags |= QSFLAGS_TC;
		qs->qs_result = QSRESULT_TC;
D 23
		put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
		query_complete(q);
E 23
		return;
	}
E 9
E 6
E 5
D 7
	if (ns->ns_type == NSTYPE_ANCHOR && current_time >= ns->ns_expire)
		qs->qs_result = QSRESULT_NOTHING;
	else
		qs->qs_result = QSRESULT_REFERRAL;
E 7
I 7
	qs->qs_result = QSRESULT_REFERRAL;
I 9
	hdr->nscount = noa->n_ns->ns_count;
D 10
	/* TODO: emit the attached A RRset(s) */
E 10
I 10
	if (noa->n_ns->ns_type != NSTYPE_DELEGATION &&
	    emit_ns_add_into_msg(q, noa))
		qs->qs_flags |= QSFLAGS_NS_ADD_DONE;
E 10
E 9
E 7
D 5
	put_query_on_complq(q);
E 5
I 5
D 23
	put_query_on_queue(q, QSTATE_COMPLETE);
E 23
I 23
	query_complete(q);
E 23
E 5
}
E 1
