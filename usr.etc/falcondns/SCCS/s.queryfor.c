h31043
s 00002/00002/00744
d D 1.24 2013/08/10 07:11:48 msokolov 24 23
c external queries bypass the queue
e
s 00022/00024/00724
d D 1.23 2013/01/13 09:11:18 msokolov 23 22
c cache the response even if it can't be returned because of TC
e
s 00040/00003/00708
d D 1.22 2013/01/13 08:05:45 msokolov 22 21
c positive response caching implemented
e
s 00024/00107/00687
d D 1.21 2013/01/13 07:04:11 msokolov 21 20
c beginning of the new caching mechanism
e
s 00013/00001/00781
d D 1.20 2013/01/11 23:02:51 msokolov 20 19
c first round of changes for the new FSR cache design
e
s 00005/00005/00777
d D 1.19 2013/01/06 08:56:35 msokolov 19 18
c more sensible and consistent msgparse function naming:
c s/extract_dname_from_msg/msgparse_extract_dname/
c s/parse_incoming_rr/msgparse_rdata/
e
s 00001/00001/00781
d D 1.18 2013/01/06 08:15:49 msokolov 18 17
c s/dname_in_bailiwick/dname_is_under/
e
s 00000/00006/00782
d D 1.17 2013/01/06 07:38:00 msokolov 17 16
c fsr_handle_answer: the check for CNAME pointing back to itself isn't necessary
e
s 00001/00001/00787
d D 1.16 2013/01/06 07:04:10 msokolov 16 15
c MSDNS => FalconDNS
e
s 00029/00000/00759
d D 1.15 2011/12/22 06:22:24 msokolov 15 14
c block CNAME attacks coming from above
e
s 00002/00001/00757
d D 1.14 2011/12/22 06:00:23 msokolov 14 13
c require AA for extending TTL of original NS
e
s 00002/00002/00756
d D 1.13 2011/12/22 05:52:20 msokolov 13 12
c ttl-limit tunable setting split into several
e
s 00028/00057/00730
d D 1.12 2011/12/21 23:33:18 msokolov 12 11
c fsr_handle_auth() is now only used for referrals and negative answers
e
s 00146/00007/00641
d D 1.11 2011/12/21 22:47:52 msokolov 11 10
c smarter handling of delegates updating their own referrals
e
s 00001/00001/00647
d D 1.10 2011/12/20 20:45:21 msokolov 10 9
c query flags slightly revamped
e
s 00000/00001/00648
d D 1.9 2011/12/19 08:03:54 msokolov 9 8
c axed NSRR_FLAGS_BAD, preparing for caching foreign NS temp failures
e
s 00001/00000/00648
d D 1.8 2011/12/13 05:05:40 msokolov 8 7
c TC stats implemented
e
s 00042/00001/00606
d D 1.7 2011/12/08 08:09:44 msokolov 7 6
c AR section forwarding implemented
e
s 00003/00003/00604
d D 1.6 2011/12/08 03:19:13 msokolov 6 5
c use the incoming RR owner capitalization for answer cache nodes
e
s 00001/00001/00606
d D 1.5 2011/12/07 23:25:14 msokolov 5 4
c oops, need MIN, not MAX
e
s 00055/00007/00552
d D 1.4 2011/12/07 07:40:02 msokolov 4 3
c recursive query logic hooked in
e
s 00053/00001/00506
d D 1.3 2011/12/07 06:42:52 msokolov 3 2
c fsr_extract_ns_addrs() written
e
s 00207/00009/00300
d D 1.2 2011/12/07 05:35:47 msokolov 2 1
c fsr_handle_auth() implemented
e
s 00309/00000/00000
d D 1.1 2011/12/07 01:58:40 msokolov 1 0
c date and time created 2011/12/07 01:58:40 by msokolov
e
u
U
t
T
I 1
/*
D 16
 * Michael Sokolov's Domain Name Server (MSDNS)
E 16
I 16
 * FalconDNS daemon by Michael Spacefalcon
E 16
 *
 * Full service resolver: handling responses from foreign NS
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 3
#include <sys/types.h>
E 3
I 3
#include <sys/param.h>
E 3
#include <netinet/in.h>
I 3
#include <arpa/inet.h>
E 3
#include <arpa/nameser.h>
#include <syslog.h>
#include "dname.h"
#include "class.h"
#include "tree.h"
I 2
#include "nsrec.h"
E 2
#include "query.h"
#include "globals.h"
#include "msgparse.h"
#include "udpout.h"

extern u_char *msgparse_extract_rr();
D 21
extern struct node *alloc_new_node(), *node_findchild();
E 21
I 21
extern struct node *node_findchild(), *get_node_for_cache();
I 22
extern struct rr *internalize_rr();
E 22
E 21

I 11
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

E 11
D 21
struct node *
D 2
get_node_for_answer_cache(q, dn)
E 2
I 2
get_node_for_cache(q, dn, answer)
E 2
	struct query *q;
	register struct dname *dn;
{
	register int depth;
	register struct node *n, *ch;
	struct node_findaddchild_private_state st;

	n = q->q_noa;
D 2
	if (n->n_unlinked)
E 2
I 2
	if (answer && n->n_unlinked)
E 2
		return(0);
	depth = dn->dn_nlabels - q->q_noa_depth;
	for (; depth--; n = ch) {
		ch = node_findchild(&n->n_nzch, dn->dn_labels[depth], &st);
		if (!ch)
			ch = node_findchild(&n->n_zonech,
					    dn->dn_labels[depth], 0);
		if (ch) {
D 2
			if (ch->n_ns)
E 2
I 2
			if (ch->n_ns && ch->n_ns->ns_type != NSTYPE_CACHEDREF)
E 2
				return(0);
		} else {
			ch = alloc_new_node(n->n_class, dn->dn_labels[depth]);
			if (!ch)
				return(0);
			if (node_addchild(&n->n_nzch, ch, &st) < 0) {
				free(ch);
				return(0);
			}
			ch->n_parent = n;
			ch->n_nextincache = cache_node_list;
			if (cache_node_list)
				cache_node_list->n_cache_backptr =
							&ch->n_nextincache;
			cache_node_list = ch;
			ch->n_cache_backptr = &cache_node_list;
		}
	}
	return(n);
}

E 21
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

I 15
static
D 21
is_cname_too_deep(q, dn)
E 21
I 21
check_encroach(q, dn)
E 21
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
D 21
			return(1);
E 21
I 21
			return(-1);
E 21
	}
	return(0);
}

E 15
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
I 22
	struct rr *cache_chain_head = 0;
	struct rr **cache_chain_tail = &cache_chain_head;
	struct node *cn = 0;
	register struct rr *srr;
	time_t cache_expire = 0;
E 22
D 21
	register struct node *cn = 0;
	int tried_cache = 0;
E 21
I 11
	u_char *rr_start;
E 11

	qs = &q->q_stages[q->q_curstage];
	hdrout = (HEADER *)q->q_msg;
	expected_owner = &qs->qs_qname;
	qs->qs_result = QSRESULT_NOREC;
	for (i = 0; i < ancount; i++) {
I 11
		rr_start = cp;
E 11
		cp = msgparse_extract_rr(&rr, cp, msg + msglen, msg);
		if (!cp) {
			if (q->q_trace)
				fprintf(q->q_trace,
				"error extracting RR #%d from answer section\n",
					i);
error_out:		qs->qs_result = QSRESULT_ERROR;
I 22
			if (cache_chain_head)
				free_rrchain(cache_chain_head);
E 22
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
D 19
		if (parse_incoming_rr(&rr, msg) < 0) {
E 19
I 19
		if (msgparse_rdata(&rr, msg) < 0) {
E 19
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
I 20
D 21
#if 0
E 20
			if (rr.prr_fix.ttl < ttl_sensible_min && ttl_bump_cname)
				rr.prr_fix.ttl = ttl_sensible_min;
E 21
			if (rr.prr_fix.class == q->q_class->c_class &&
D 21
			    rr.prr_fix.ttl &&
			    !dname_compare(&rr.prr_owner, &rr.prr_rdata_dn[0])){
				if (!tried_cache) {
D 2
					cn = get_node_for_answer_cache(q,
						expected_owner);
E 2
I 2
					cn = get_node_for_cache(q,
D 6
						expected_owner, 1);
E 6
I 6
						&rr.prr_owner, 1);
E 6
E 2
					tried_cache = 1;
				}
				if (cn)
					attach_rr_to_node(cn, &rr, 1);
			}
I 20
#endif
E 21
I 21
			    !dname_compare(&rr.prr_owner, &rr.prr_rdata_dn[0]))
				fsrcache_store_cname(q, &rr);
E 21
E 20
D 23
			if (emit_parsedrr_into_msg(q, &rr) < 0) {
tc_out:				if (q->q_trace)
					fputs("returning TC\n", q->q_trace);
				qs->qs_result = QSRESULT_TC;
				qs->qs_flags |= QSFLAGS_TC;
I 22
				if (cache_chain_head)
					free_rrchain(cache_chain_head);
E 22
				return(cp);
			}
			hdrout->ancount++;
E 23
			/* does it answer the query? */
			if (q->q_type == T_CNAME || q->q_type == T_ANY ||
			    qs->qs_answer_rrcount) {
				if (q->q_trace)
					fprintf(q->q_trace,
						"CNAME accepted as answer\n");
D 23
				qs->qs_answer_rrcount++;
D 22
				break;
E 22
I 22
				goto answer_cache;
E 23
I 23
				goto answer;
E 23
E 22
			}
			/* nope, needs messy CNAME handling */
I 23
			if (emit_parsedrr_into_msg(q, &rr) < 0) {
				if (q->q_trace)
					fputs("returning TC\n", q->q_trace);
				qs->qs_result = QSRESULT_TC;
				qs->qs_flags |= QSFLAGS_TC;
				return(cp);
			}
			hdrout->ancount++;
E 23
			qs->qs_cname_rrcount++;
			dname_copy_discontig(&rr.prr_rdata_dn[0], cname_buf);
			qs->qs_result = QSRESULT_CNAME;
D 17
			if (dname_compare(expected_owner, cname_buf)) {
				if (q->q_trace)
					fprintf(q->q_trace,
					"CNAME points back to itself!\n");
				return(cp);
			}
E 17
			if (!dname_under_noa(q, cname_buf)) {
				if (q->q_trace)
					fprintf(q->q_trace,
		"CNAME is not under our NOA, will do it as a new stage\n");
I 15
				return(cp);
			}
D 21
			if (is_cname_too_deep(q, cname_buf)) {
E 21
I 21
			if (check_encroach(q, cname_buf)) {
E 21
				if (q->q_trace)
					fprintf(q->q_trace,
	"CNAME is encroaching on another NOA, will do it as a new stage\n");
E 15
				return(cp);
			}
			if (q->q_trace)
				fprintf(q->q_trace,
			"CNAME falls under NOA, continuing in this stage\n");
			expected_owner = cname_buf;
D 21
			cn = 0;
			tried_cache = 0;
E 21
			q->q_answer_ptr = q->q_msgptr;
			break;
D 21
		case T_A:
		case T_MX:
		case T_PTR:
I 20
#if 0
E 20
			if (rr.prr_fix.class == q->q_class->c_class &&
			    rr.prr_fix.ttl >= ttl_sensible_min) {
				if (!tried_cache) {
D 2
					cn = get_node_for_answer_cache(q,
						expected_owner);
E 2
I 2
					cn = get_node_for_cache(q,
D 6
						expected_owner, 1);
E 6
I 6
						&rr.prr_owner, 1);
E 6
E 2
					tried_cache = 1;
				}
				if (cn)
					attach_rr_to_node(cn, &rr, 1);
			}
I 20
#endif
E 20
			goto forward_answer;
		case T_HINFO:
		case T_TXT:
		case T_WKS:
I 20
#if 0
E 20
			if (rr.prr_fix.class == q->q_class->c_class &&
			    rr.prr_fix.ttl >= ttl_sensible_min &&
			    rr.prr_fix.type == q->q_type &&
			    rr.prr_fix.rdlength <= cache_max_rdlength) {
				if (!tried_cache) {
D 2
					cn = get_node_for_answer_cache(q,
						expected_owner);
E 2
I 2
					cn = get_node_for_cache(q,
D 6
						expected_owner, 1);
E 6
I 6
						&rr.prr_owner, 1);
E 6
E 2
					tried_cache = 1;
				}
				if (cn)
					attach_rr_to_node(cn, &rr, 1);
			}
I 20
#endif
E 20
			goto forward_answer;
E 21
I 11
		case T_NS:
			if (rr.prr_owner.dn_nlabels == q->q_noa_depth &&
			    rr.prr_fix.class == q->q_class->c_class) {
				if (ns_refresh_count < NS_REFRESH_MAX)
					ns_refresh_array[ns_refresh_count++] =
						rr_start;
				if (rr.prr_fix.ttl < ns_refresh_ttl)
					ns_refresh_ttl = rr.prr_fix.ttl;
			}
D 21
			goto forward_answer;
E 21
I 21
			/* FALL THRU */
E 21
E 11
		default:
D 21
		forward_answer:
E 21
D 23
			if (emit_parsedrr_into_msg(q, &rr) < 0)
				goto tc_out;
			hdrout->ancount++;
			qs->qs_answer_rrcount++;
I 21
D 22
			/* new positive caching logic to be added here */
E 22
I 22
		answer_cache:
E 23
I 23
		answer:
			qs->qs_result = QSRESULT_ANSWER;
			if (!(qs->qs_flags & QSFLAGS_TC)) {
				if (emit_parsedrr_into_msg(q, &rr) >= 0) {
					hdrout->ancount++;
					qs->qs_answer_rrcount++;
				} else
					qs->qs_flags |= QSFLAGS_TC;
			}
E 23
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
E 22
E 21
		}
	}
D 22
	if (qs->qs_answer_rrcount)
E 22
I 22
D 23
	if (qs->qs_answer_rrcount) {
E 22
		qs->qs_result = QSRESULT_ANSWER;
I 22
		if (cache_chain_head)
			fsrcache_store_posans(cn, cache_chain_head, q->q_type,
						cache_expire);
	}
E 23
I 23
	if (cache_chain_head)
		fsrcache_store_posans(cn, cache_chain_head, q->q_type,
					cache_expire);
E 23
E 22
	return(cp);
I 2
}

I 11
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
D 19
			if (parse_incoming_rr(&rr, msg) < 0) {
E 19
I 19
			if (msgparse_rdata(&rr, msg) < 0) {
E 19
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

E 11
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
I 3
			if (ns->ns_roundrobin == ind)
				ns->ns_roundrobin = 0;
E 3
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
D 12
fsr_handle_auth(q, cpp, msg, msglen, nscount, acceptref, rrset_owner)
E 12
I 12
fsr_handle_auth(q, cp, msg, msglen, nscount, rrset_owner)
E 12
	register struct query *q;
D 12
	u_char **cpp, *msg;
	int msglen, nscount, acceptref;
E 12
I 12
	u_char *cp, *msg;
	int msglen, nscount;
E 12
	register struct dname *rrset_owner;
{
D 12
	u_char *cp = *cpp;
E 12
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
D 12
				"error extracting RR #%d from NS section\n",
					i);
E 12
I 12
				"error extracting RR #%d from NS section\n", i);
E 12
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
D 19
			if (parse_incoming_rr(&rr, msg) < 0) {
E 19
I 19
D 21
			if (msgparse_rdata(&rr, msg) < 0) {
E 21
I 21
			if (!(qs->qs_flags & QSFLAGS_AA)) {
E 21
E 19
				if (q->q_trace)
					fprintf(q->q_trace,
D 21
						"SOA RDATA parse error\n");
E 21
I 21
				"not accepting negative SOA with AA=0\n");
E 21
				continue;
			}
I 20
D 21
			if (!(qs->qs_flags & QSFLAGS_AA)) {
E 21
I 21
			if (!dname_is_under(&qs->qs_qname, rrset_owner)) {
E 21
				if (q->q_trace)
					fprintf(q->q_trace,
D 21
				"not accepting negative SOA with AA=0\n");
E 21
I 21
			"SOA owner is not above QNAME, not accepting\n");
E 21
				continue;
			}
I 21
			if (msgparse_rdata(&rr, msg) < 0) {
				if (q->q_trace)
					fprintf(q->q_trace,
						"SOA RDATA parse error\n");
				continue;
			}
E 21
E 20
I 12
			if (q->q_trace)
				fputs("accepting negative SOA\n", q->q_trace);
E 12
D 10
			if (!(q->q_flags & QFLAGS_INTERNAL) &&
E 10
I 10
			if (q->q_flags & QFLAGS_WANT_NEGSOA &&
E 10
			    emit_parsedrr_into_msg(q, &rr) >= 0)
				hdrout->nscount = 1;
I 21
			fsrcache_store_negans(q, &rr);
E 21
D 12
			rrset_status = -1;
			continue;
E 12
I 12
			return(0);
E 12
		default:
			continue;
		}
		/* handle NS */
D 19
		if (parse_incoming_rr(&rr, msg) < 0) {
E 19
I 19
		if (msgparse_rdata(&rr, msg) < 0) {
E 19
			if (q->q_trace)
				fprintf(q->q_trace, "NS RDATA parse error\n");
			continue;
		}
		if (!rrset_status) {
			if (rrset_owner->dn_nlabels == q->q_noa_depth) {
				if (q->q_trace)
					fprintf(q->q_trace,
D 12
					"NS RRset owner matches current NOA\n");
				n = q->q_noa;
				if (n->n_ns &&
				    n->n_ns->ns_type == NSTYPE_CACHEDREF) {
					if (q->q_trace)
						fprintf(q->q_trace,
						"updating old CACHEDREF\n");
				} else {
					if (q->q_trace)
						fprintf(q->q_trace,
					"no old CACHEDREF, do nothing\n");
					n = 0;
					rrset_status = -1;
					continue;
				}
			} else {
				if (!acceptref) {
					if (q->q_trace)
						fprintf(q->q_trace,
			"not accepting NS RRset owner != current NOA\n");
					rrset_status = -1;
					continue;
				}
				if (!dname_in_bailiwick(&qs->qs_qname,
							rrset_owner)) {
					if (q->q_trace)
						fprintf(q->q_trace,
E 12
I 12
					"referral back to itself, lame\n");
				return(0);
			}
D 18
			if (!dname_in_bailiwick(&qs->qs_qname, rrset_owner)) {
E 18
I 18
			if (!dname_is_under(&qs->qs_qname, rrset_owner)) {
E 18
				if (q->q_trace)
					fprintf(q->q_trace,
E 12
				"referral doesn't bring us closer to QNAME\n");
D 12
					qs->qs_result = QSRESULT_ERROR;
					rrset_status = -1;
					continue;
				}
E 12
I 12
				qs->qs_result = QSRESULT_ERROR;
				return(0);
			}
			if (q->q_trace)
				fprintf(q->q_trace,
					"creating new CACHEDREF\n");
			n = get_node_for_cache(q, rrset_owner, 0);
			if (!n) {
E 12
				if (q->q_trace)
					fprintf(q->q_trace,
D 12
						"creating new CACHEDREF\n");
				n = get_node_for_cache(q, rrset_owner, 0);
				if (!n) {
					if (q->q_trace)
						fprintf(q->q_trace,
E 12
					"can't get a node for the referral!\n");
D 12
					qs->qs_result = QSRESULT_ERROR;
					rrset_status = -1;
					continue;
				}
E 12
I 12
				qs->qs_result = QSRESULT_ERROR;
				return(0);
E 12
			}
			if (n->n_ns)
				mark_for_deletion(n->n_ns);
			rrset_status = 1;
		}
I 4
D 21
		if (rr.prr_fix.ttl < ttl_sensible_min && ttl_bump_ns)
			rr.prr_fix.ttl = ttl_sensible_min;
E 21
I 21
		if (rr.prr_fix.ttl < ttl_bump_ns)
			rr.prr_fix.ttl = ttl_bump_ns;
E 21
E 4
D 20
		if (attach_rr_to_node(n, &rr, 1) < 0) {
E 20
I 20
		if (attach_ns_to_node(n, &rr, 1) < 0) {
E 20
			if (q->q_trace)
				fprintf(q->q_trace, "unable to attach NS RR\n");
D 12
			if (n != q->q_noa)
				qs->qs_result = QSRESULT_ERROR;
			n = 0;
			rrset_status = -1;
			continue;
E 12
I 12
			qs->qs_result = QSRESULT_ERROR;
			return(0);
E 12
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
D 12
	*cpp = cp;
E 12
	return(n);
I 3
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
I 11
	time_t newexp;
E 11

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
D 11
			if (dname_compare(srv + 1, &rr.prr_owner))
E 11
I 11
			if (dname_compare((struct dname *)(srv + 1),
					  &rr.prr_owner))
E 11
				break;
		if (!srv)
			continue;
I 11
D 21
		if (rr.prr_fix.ttl < ttl_sensible_min && ttl_bump_ns)
			rr.prr_fix.ttl = ttl_sensible_min;
E 21
I 21
		if (rr.prr_fix.ttl < ttl_bump_ns)
			rr.prr_fix.ttl = ttl_bump_ns;
E 21
D 13
		newexp = current_time + MIN(rr.prr_fix.ttl, ttl_limit);
E 13
I 13
		newexp = current_time + MIN(rr.prr_fix.ttl, ttl_limit_ns);
E 13
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
E 11
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
I 4
D 11
		if (rr.prr_fix.ttl < ttl_sensible_min && ttl_bump_ns)
			rr.prr_fix.ttl = ttl_sensible_min;
E 4
		srv->nsrr_A_expire = current_time +
D 5
					MAX(rr.prr_fix.ttl, ttl_limit);
E 5
I 5
					MIN(rr.prr_fix.ttl, ttl_limit);
E 11
I 11
		srv->nsrr_A_expire = newexp;
E 11
E 5
D 9
		srv->nsrr_flags &= ~NSRR_FLAGS_BAD;
E 9
		count++;
	}
	return(count);
E 3
E 2
}

I 7
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
D 19
		if (parse_incoming_rr(&rr, msg) < 0) {
E 19
I 19
		if (msgparse_rdata(&rr, msg) < 0) {
E 19
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
I 8
D 12
				stats_fwd_ar_tc++;
E 12
I 12
			stats_fwd_ar_tc++;
E 12
E 8
			break;
		}
		hdrout->arcount++;
	}
	return(hdrout->arcount);
}

E 7
void
fsr_handle_response(q, msg, msglen)
	register struct query *q;
	u_char *msg;
	int msglen;
{
	register HEADER *hdrin;
	register struct query_stage *qs;
D 4
	u_char *cp;
E 4
I 4
	u_char *cp, *answer_start;
E 4
	int ancount, nscount, arcount;
D 4
	struct dname cname;
E 4
I 4
	struct dname dnscratch;
	register struct node *newnoa;
E 4

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
D 24
		put_query_on_queue(q, QSTATE_COMPLETE);
E 24
I 24
		query_complete(q);
E 24
		return;
	}
	if (hdrin->aa)
		qs->qs_flags |= QSFLAGS_AA;
	/* start parsing! */
	if (hdrin->qdcount)
		cp = msg + q->q_udpout->uo_querylen;
	else
		cp = msg + sizeof(HEADER);
I 4
	answer_start = cp;
I 11
	ns_refresh_count = 0;
D 13
	ns_refresh_ttl = ttl_limit;
E 13
I 13
	ns_refresh_ttl = ttl_limit_ns;
E 13
E 11
E 4
	if (ancount)
D 4
		cp = fsr_handle_answer(q, cp, msg, msglen, ancount, &cname);
E 4
I 4
		cp = fsr_handle_answer(q, cp, msg, msglen, ancount, &dnscratch);
E 4
	else
		qs->qs_result = QSRESULT_NOREC;
	switch (qs->qs_result) {
	case QSRESULT_ANSWER:
D 4
		/* TODO: use the NS section to update NOA */
E 4
I 4
D 11
		if (fsr_handle_auth(q, &cp, msg, msglen, nscount, 0,
					&dnscratch))
E 11
I 11
		cp = fsr_scan_ns_after_answer(q, cp, msg, msglen, nscount);
D 14
		if (ns_refresh_count && fsr_refresh_ns(q, msg, msglen))
E 14
I 14
		if (ns_refresh_count && hdrin->aa &&
		    fsr_refresh_ns(q, msg, msglen))
E 14
E 11
			fsr_extract_ns_addrs(q, answer_start, msg, msglen,
						q->q_noa);
E 4
D 7
		/* TODO: forward the additional info section */
E 7
I 7
D 23
		if (cp && arcount &&
E 23
I 23
		if (cp && arcount && !(qs->qs_flags & QSFLAGS_TC) &&
E 23
		    fsr_forward_addinfo(q, cp, msg, msglen, arcount))
			qs->qs_flags |= QSFLAGS_ADD_FORWARDED;
E 7
		goto out;
	case QSRESULT_NOREC:
		break;
	case QSRESULT_CNAME:
		free_subtree(q->q_noa);
D 4
		qstage_handle_cname(q, &cname);
E 4
I 4
		qstage_handle_cname(q, &dnscratch);
E 4
		return;
	case QSRESULT_ERROR:
	case QSRESULT_TC:
		goto out;
	default:
		syslog(LOG_CRIT,
			"BUG: unexpected result from fsr_handle_answer()\n");
		abort();
	}
I 4
	if (q->q_trace)
		fputs("no answer\n", q->q_trace);
E 4
	if (hdrin->rcode == NXDOMAIN)
		qs->qs_result = QSRESULT_NXDOMAIN;
D 4
	/* referral handling: to be implemented */
	goto out;
E 4
I 4
D 12
	newnoa = fsr_handle_auth(q, &cp, msg, msglen, nscount, 1, &dnscratch);
E 12
I 12
	newnoa = fsr_handle_auth(q, cp, msg, msglen, nscount, &dnscratch);
E 12
	if (newnoa)
		fsr_extract_ns_addrs(q, answer_start, msg, msglen, newnoa);
D 12
	if (!newnoa || newnoa == q->q_noa) {
E 12
I 12
	else {
E 12
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
I 21
	qs->qs_flags = 0; /* disregard any AA from intermediate referrals */
E 21
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
D 24
	put_query_on_queue(q, QSTATE_COMPLETE);
E 24
I 24
	query_complete(q);
E 24
E 4
}
E 1
