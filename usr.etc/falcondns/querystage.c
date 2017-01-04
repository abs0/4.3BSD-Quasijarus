/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Main query stage processing
 */

#ifndef lint
static char sccsid[] = "@(#)querystage.c	1.23 (IFCTF) 2013/08/10";
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
extern struct dname *fsrcache_look_for_cname();
extern void fsr_handle_response(), fsr_handle_error();

qstage_answer_from_zone(q, n, wild)
	register struct query *q;
	struct node *n;
	int wild;
{
	register struct query_stage *qs;
	struct dname *owner, owner_st;
	int owner_set = 0;
	HEADER *hdr = (HEADER *)q->q_msg;
	register struct rr *rr;
	register int accept;
	u_long minttl;

	qs = &q->q_stages[q->q_curstage];
	if (n->n_zonehead && q->q_type != T_AXFR)
		minttl = n->n_zonehead->n_soa->soa_minimum;
	else
		minttl = 0;
	/* do SOA and NS first */
	if (n->n_soa &&
	    (q->q_type == T_SOA || q->q_type == T_ANY || q->q_type == T_AXFR)) {
		if (emit_soa_into_msg(q, n) < 0) {
			qs->qs_flags |= QSFLAGS_TC;
			return(-1);
		}
		qs->qs_answer_rrcount++;
		hdr->ancount++;
	}
	if (n->n_ns &&
	    (q->q_type == T_NS || q->q_type == T_ANY || q->q_type == T_AXFR)) {
		if (emit_ns_rrset_into_msg(q, n, minttl) < 0) {
			qs->qs_flags |= QSFLAGS_TC;
			return(-1);
		}
		qs->qs_answer_rrcount += n->n_ns->ns_count;
		hdr->ancount += n->n_ns->ns_count;
	}
	/* now do the general RRs */
	for (rr = n->n_rrzone; rr; rr = rr->rr_next) {
		switch (q->q_type) {
		case T_SOA:
		case T_NS:
			/*
			 * Don't bother looking for these,
			 * we know they can't be there.
			 */
			return(qs->qs_answer_rrcount);
		case T_ANY:
		case T_AXFR:
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
		if (accept) {
			if (!owner_set) {
				if (wild)
					owner = &qs->qs_qname;
				else {
					dname_of_node(n, &owner_st);
					owner = &owner_st;
				}
				owner_set = 1;
			}
			if (emit_genrr_into_msg(q, owner, rr, minttl) < 0) {
				qs->qs_flags |= QSFLAGS_TC;
				return(-1);
			}
			qs->qs_answer_rrcount++;
			hdr->ancount++;
		}
	}
	return(qs->qs_answer_rrcount);
}

struct dname *
qstage_cname_from_zone(q, n, wild)
	register struct query *q;
	struct node *n;
	int wild;
{
	register struct query_stage *qs;
	HEADER *hdr = (HEADER *)q->q_msg;
	register struct rr *rr;
	u_long minttl;

	qs = &q->q_stages[q->q_curstage];
	for (rr = n->n_rrzone; rr; rr = rr->rr_next) {
		if (rr->rr_type != T_CNAME)
			continue;
		if (n->n_zonehead)
			minttl = n->n_zonehead->n_soa->soa_minimum;
		else
			minttl = 0;
		if (emit_genrr_into_msg(q, &qs->qs_qname, rr, minttl) < 0) {
			qs->qs_flags |= QSFLAGS_TC;
			return(0);
		}
		qs->qs_cname_rrcount = 1;
		hdr->ancount++;
		return((struct dname *)(rr + 1));
	}
	return(0);
}

/*
 * This function is called when a query stage has hit a CNAME.
 * It handles loop detection and chain length limiting,
 * then dispatches the query either to the next stage or
 * to completion processing.
 */
void
qstage_handle_cname(q, cname)
	register struct query *q;
	register struct dname *cname;
{
	register int i;

	if (q->q_trace) {
		fputs("CNAME ", q->q_trace);
		print_dname(cname, q->q_trace);
		putc('\n', q->q_trace);
	}
	for (i = 0; i <= q->q_curstage; i++)
		if (dname_compare(&q->q_stages[i].qs_qname, cname)) {
			/* CNAME loop */
			if (q->q_trace)
				fputs("CNAME loop detected\n", q->q_trace);
			query_complete(q);
			return;
		}
	/* is there room for one more stage? */
	if (i <= MAX_CNAME_CHAIN) {
		if (q->q_trace)
			fputs("CNAME: scheduling the next stage\n", q->q_trace);
		q->q_curstage = i;
		dname_copy(cname, &q->q_stages[i].qs_qname);
		stage_query(q);
	} else {
		if (q->q_trace)
			fputs("CNAME: no room left\n", q->q_trace);
		query_complete(q);
	}
}

is_cachedref_unusable(ns)
	register struct ns_rrset *ns;
{
	register struct nsrr *srv;

	for (srv = ns->ns_chain; srv; srv = srv->nsrr_next) {
		if (srv->nsrr_addrcnt && current_time < srv->nsrr_A_expire)
			return(0);
		if (!(srv->nsrr_flags & NSRR_FLAGS_NEEDGLUE))
			return(0);
	}
	return(-1);
}

void
query_stage_process(q)
	register struct query *q;
{
	register struct query_stage *qs;
	register struct node *n, *ch, *noa;
	register int depth;
	int wild = 0;
	struct dname *cname, scratch_dname;
	HEADER *hdr = (HEADER *)q->q_msg;

	qs = &q->q_stages[q->q_curstage];
	if (q->q_trace) {
		fprintf(q->q_trace, "Entering query %d stage %d\n",
			q->q_trace_index, q->q_curstage);
		fputs("QNAME=", q->q_trace);
		print_dname(&qs->qs_qname, q->q_trace);
		putc('\n', q->q_trace);
	}
	q->q_answer_ptr = q->q_msgptr;
	qs->qs_cname_rrcount = 0;
	qs->qs_answer_rrcount = 0;
	qs->qs_flags = 0;
restart:
	n = q->q_class->c_root;
	noa = 0;
	for (depth = qs->qs_qname.dn_nlabels; n; n = ch) {
		if (n->n_ns) {
			/* cached referrals expire! */
			if (n->n_ns->ns_type == NSTYPE_CACHEDREF &&
			    current_time >= n->n_ns->ns_expire) {
				if (n->n_refcount == 1) {
					free_ns_rrset(n->n_ns);
					n->n_ns = 0;
				}
			} else if (n->n_ns->ns_type != NSTYPE_CACHEDREF ||
				   hdr->rd && hdr->ra ||
				   norec_allow_cached_ref) {
				noa = n;
				q->q_noa_depth = qs->qs_qname.dn_nlabels-depth;
			}
		}
		if (!depth--)
			break;
		ch = node_findchild(&n->n_nzch, qs->qs_qname.dn_labels[depth],
				    0);
		if (!ch)
			ch = node_findchild(&n->n_zonech,
					    qs->qs_qname.dn_labels[depth], 0);
		if (!ch && n->n_zonech_wild && noa && noa->n_zone) {
			n = n->n_zonech_wild;
			wild = depth + 1;
			if (q->q_trace) {
				dname_of_node(n, &scratch_dname);
				fputs("using wildcard at ", q->q_trace);
				print_dname(&scratch_dname, q->q_trace);
				putc('\n', q->q_trace);
			}
			break;
		}
	}
	if (!noa) {
		if (q->q_trace)
			fputs("No NOA found\n", q->q_trace);
		/* the forwarder logic will go here eventually */
		if (q->q_trace)
			fputs("No NOA, no forwarder: hands empty\n",
				q->q_trace);
		qs->qs_result = QSRESULT_NOTHING;
		query_complete(q);
		return;
	}
	/* sans-NOA case filtered out, now we know we have a NOA */
	if (q->q_trace) {
		fputs("NOA is ", q->q_trace);
		dname_of_node(noa, &scratch_dname);
		print_dname(&scratch_dname, q->q_trace);
		fprintf(q->q_trace, " type %d\n", noa->n_ns->ns_type);
	}
	switch (noa->n_ns->ns_type) {
	case NSTYPE_ZONEHEAD:
		qs->qs_flags |= QSFLAGS_AA;
		if (!n) {
			if (q->q_trace)
				fputs("NXDOMAIN\n", q->q_trace);
			qs->qs_result = QSRESULT_NXDOMAIN;
			if (q->q_flags & QFLAGS_WANT_NEGSOA &&
			    emit_soa_into_msg(q, noa) >= 0)
				hdr->nscount = 1;
			query_complete(q);
			return;
		}
		if (qstage_answer_from_zone(q, n, wild)) {
			if (q->q_trace)
				fputs("authoritative answer\n", q->q_trace);
			qs->qs_result = QSRESULT_ANSWER;
			if (q->q_flags & QFLAGS_WANT_AA_NS &&
			    !(qs->qs_flags & QSFLAGS_TC) &&
			    (n != noa ||
				q->q_type != T_NS && q->q_type != T_ANY) &&
			    emit_ns_rrset_into_msg(q, noa,
				noa->n_soa->soa_minimum) >= 0)
				    hdr->nscount = noa->n_ns->ns_count;
			query_complete(q);
			return;
		}
		if (cname = qstage_cname_from_zone(q, n, wild)) {
			if (q->q_trace)
				fputs("authoritative CNAME\n", q->q_trace);
			qs->qs_result = QSRESULT_CNAME;
			qstage_handle_cname(q, cname);
			return;
		}
		if (qs->qs_flags & QSFLAGS_TC) {
			if (q->q_trace)
				fputs("authoritative CNAME caused TC\n",
					q->q_trace);
			qs->qs_result = QSRESULT_TC;
		} else {
			if (q->q_trace)
				fputs("authoritative no data at node\n",
					q->q_trace);
			qs->qs_result = QSRESULT_NOREC;
			if (q->q_flags & QFLAGS_WANT_NEGSOA &&
			    emit_soa_into_msg(q, noa) >= 0)
				hdr->nscount = 1;
		}
		query_complete(q);
		return;
	case NSTYPE_DELEGATION:
		if (!(q->q_flags & QFLAGS_WANT_GLUE) || !n)
			break;
		if (qstage_answer_from_zone(q, n, 0)) {
			if (q->q_trace)
				fputs("answered with glue record from zone\n",
					q->q_trace);
			qs->qs_result = QSRESULT_ANSWER;
			query_complete(q);
			return;
		}
		break;
	case NSTYPE_CACHEDREF:
		if (is_cachedref_unusable(noa->n_ns)) {
			if (q->q_trace)
				fprintf(q->q_trace,
		"unusable cached referral, invalidating and restarting\n");
			noa->n_ns->ns_expire = 0;
			goto restart;
		}
		break;
	}
	/* caching operation */
	if (n && (hdr->rd && hdr->ra || norec_allow_cached_ans) &&
	    !(q->q_flags & QFLAGS_WANT_AA)) {
		if (q->q_trace)
			fputs("looking in the cache\n", q->q_trace);
		if (fsrcache_look_for_answer(q, n)) {
			if (q->q_trace)
				fputs("found answer\n", q->q_trace);
			query_complete(q);
			return;
		}
		if (cname = fsrcache_look_for_cname(q, n)) {
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
			query_complete(q);
			return;
		}
	}
	/* Going to a foreign NS. Return a referral or follow ourselves? */
	if (hdr->rd && hdr->ra) {
		if (q->q_trace)
			fputs("recursive query, asking foreign NS\n",
				q->q_trace);
		if (!(q->q_flags & QFLAGS_INTERNAL) && !q->q_dupcatch_backptr
		    && !q->q_trace && query_dup_intercept(q))
			return;
		noa->n_refcount++;
		q->q_noa = noa;
		q->q_askforns_response_callbk = fsr_handle_response;
		q->q_askforns_error_callbk = fsr_handle_error;
		askforns_entry(q);
		return;
	}
	if (q->q_trace)
		fputs("iterative query, answering with a referral\n",
			q->q_trace);
	if (q->q_flags & QFLAGS_INTERNAL) {
		if (q->q_trace)
			fprintf(q->q_trace,
	"internal non-recursive query, assuming referral would be useless\n");
		qs->qs_result = QSRESULT_NOTHING;
		query_complete(q);
		return;
	}
	if (noa->n_ns->ns_type == NSTYPE_ANCHOR &&
	    current_time >= noa->n_ns->ns_expire) {
		if (q->q_trace)
			fprintf(q->q_trace,
	"not supposed to return a non-validated NS-anchor as a referral\n");
		qs->qs_result = QSRESULT_NOTHING;
		query_complete(q);
		return;
	}
	if (emit_ns_rrset_into_msg(q, noa, noa->n_zonehead ?
	    noa->n_zonehead->n_soa->soa_minimum : 0L) < 0) {
		if (q->q_trace)
			fputs("NS referral didn't fit, setting TC", q->q_trace);
		qs->qs_flags |= QSFLAGS_TC;
		qs->qs_result = QSRESULT_TC;
		query_complete(q);
		return;
	}
	qs->qs_result = QSRESULT_REFERRAL;
	hdr->nscount = noa->n_ns->ns_count;
	if (noa->n_ns->ns_type != NSTYPE_DELEGATION &&
	    emit_ns_add_into_msg(q, noa))
		qs->qs_flags |= QSFLAGS_NS_ADD_DONE;
	query_complete(q);
}
