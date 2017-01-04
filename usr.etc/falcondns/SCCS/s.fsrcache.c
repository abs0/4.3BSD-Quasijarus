h00778
s 00007/00000/00387
d D 1.5 2013/01/14 01:57:52 msokolov 5 4
c all nodes with cached stuff on them get put on the cache sweep list
e
s 00020/00000/00367
d D 1.4 2013/01/13 08:05:47 msokolov 4 3
c positive response caching implemented
e
s 00033/00009/00334
d D 1.3 2013/01/13 07:26:12 msokolov 3 2
c return specially-cached CNAMEs as answers when appropriate
e
s 00209/00001/00134
d D 1.2 2013/01/13 07:04:13 msokolov 2 1
c beginning of the new caching mechanism
e
s 00135/00000/00000
d D 1.1 2013/01/11 23:01:23 msokolov 1 0
c new module for the new FSR cache design
e
u
U
t
T
I 1
/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * This module implements the caching part of the full service resolver
 * (FSR) functionality.
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
I 2
#include <syslog.h>
E 2
#include "dname.h"
#include "tree.h"
D 2
#include "rr.h"
E 2
I 2
#include "nsrec.h"
E 2
#include "query.h"
I 2
#include "msgparse.h"
E 2
#include "globals.h"

I 2
extern u_char *myalloc();
extern struct node *alloc_new_node(), *node_findchild();
extern struct rr *internalize_rr();

E 2
static
return_pos_answer(q, rrchain)
	register struct query *q;
	struct rr *rrchain;
{
	register struct query_stage *qs;
	HEADER *hdr = (HEADER *)q->q_msg;
	register struct rr *rr;

	qs = &q->q_stages[q->q_curstage];
	qs->qs_result = QSRESULT_ANSWER;
	for (rr = rrchain; rr; rr = rr->rr_next) {
		if (rr->rr_expire < current_time)
			continue;
		if (emit_genrr_into_msg(q, &qs->qs_qname, rr, 0) < 0) {
			qs->qs_flags |= QSFLAGS_TC;
			return(-1);
		}
		qs->qs_answer_rrcount++;
		hdr->ancount++;
	}
	return(1);
}

static
I 3
return_cname_as_ans(q, rr)
	register struct query *q;
	struct rr *rr;
{
	register struct query_stage *qs;
	HEADER *hdr = (HEADER *)q->q_msg;

	qs = &q->q_stages[q->q_curstage];
	qs->qs_result = QSRESULT_ANSWER;
	if (emit_genrr_into_msg(q, &qs->qs_qname, rr, 0) < 0) {
		qs->qs_flags |= QSFLAGS_TC;
		return(-1);
	}
	qs->qs_answer_rrcount++;
	hdr->ancount++;
	return(1);
}

static
E 3
return_neg_answer(q, rc, rescode)
	register struct query *q;
	struct rescache *rc;
{
	register struct query_stage *qs;
	HEADER *hdr = (HEADER *)q->q_msg;

	qs = &q->q_stages[q->q_curstage];
	qs->qs_result = rescode;
	if (emit_ncache_soa_into_msg(q, rc) >= 0) {
		hdr->nscount = 1;
		return(1);
	} else {
		qs->qs_flags |= QSFLAGS_TC;
		return(-1);
	}
}

fsrcache_look_for_answer(q, n)
	struct query *q;
	register struct node *n;
{
	register int qtype = q->q_type;
	register struct rescache *rc, **rcp;

I 3
	if (n->n_cached_cname && current_time >= n->n_cached_cname->rr_expire) {
		free(n->n_cached_cname);
		n->n_cached_cname = 0;
	}
	if (n->n_cached_nxdom && current_time >= n->n_cached_nxdom->rc_expire) {
		free(n->n_cached_nxdom);
		n->n_cached_nxdom = 0;
	}
E 3
	rcp = &n->n_cached_ans;
	while (rc = *rcp) {
		if (current_time >= rc->rc_expire) {
			*rcp = rc->rc_next;
			if (rc->rc_pos)
				free_rrchain(rc->rc_pos);
			free(rc);
			continue;
		}
		if (rc->rc_qtype == qtype)
			break;
		rcp = &rc->rc_next;
	}
	if (rc) {
		if (rc->rc_pos)
			return return_pos_answer(q, rc->rc_pos);
		else
			return return_neg_answer(q, rc, QSRESULT_NOREC);
	}
D 3
	rc = n->n_cached_nxdom;
	if (!rc)
		return(0);
	if (current_time >= rc->rc_expire) {
		free(rc);
		n->n_cached_nxdom = 0;
		return(0);
	}
	return return_neg_answer(q, rc, QSRESULT_NXDOMAIN);
E 3
I 3
	if (n->n_cached_nxdom)
		return return_neg_answer(q, n->n_cached_nxdom,
					 QSRESULT_NXDOMAIN);
	if (n->n_cached_cname && (qtype == T_CNAME || qtype == T_ANY))
		return return_cname_as_ans(q, n->n_cached_cname);
	return(0);
E 3
}

static struct dname *
return_cname(q, rr)
	register struct query *q;
	struct rr *rr;
{
	register struct query_stage *qs;
	HEADER *hdr = (HEADER *)q->q_msg;

	qs = &q->q_stages[q->q_curstage];
	if (emit_genrr_into_msg(q, &qs->qs_qname, rr, 0) < 0) {
		qs->qs_flags |= QSFLAGS_TC;
		return(0);
	}
	qs->qs_cname_rrcount = 1;
	hdr->ancount++;
	return((struct dname *)(rr + 1));
}

struct dname *
fsrcache_look_for_cname(q, n)
	struct query *q;
	register struct node *n;
{
	register struct rr *rr;

	rr = n->n_cached_cname;
	if (!rr)
		return(0);
	if (current_time >= rr->rr_expire) {
		free(rr);
		n->n_cached_cname = 0;
		return(0);
	}
	return return_cname(q, rr);
I 2
}

struct node *
get_node_for_cache(q, dn, answer)
	struct query *q;
	register struct dname *dn;
{
	register int depth;
	register struct node *n, *ch;
	struct node_findaddchild_private_state st;

	n = q->q_noa;
	if (answer && n->n_unlinked)
		return(0);
	depth = dn->dn_nlabels - q->q_noa_depth;
	for (; depth--; n = ch) {
		ch = node_findchild(&n->n_nzch, dn->dn_labels[depth], &st);
		if (!ch)
			ch = node_findchild(&n->n_zonech,
					    dn->dn_labels[depth], 0);
		if (ch) {
			if (ch->n_ns && ch->n_ns->ns_type != NSTYPE_CACHEDREF)
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
I 5
	if (!n->n_cache_backptr) {
		n->n_nextincache = cache_node_list;
		if (cache_node_list)
			cache_node_list->n_cache_backptr = &n->n_nextincache;
		cache_node_list = n;
		n->n_cache_backptr = &cache_node_list;
	}
E 5
	return(n);
}

static void
install_qtype_rescache(n, newrc)
	register struct node *n;
	register struct rescache *newrc;
{
	register struct rescache *p, **pp;
	register int qtype;

	/* first delete any old conflicting answers */
	/* while at it, toss any expired stuff */
	qtype = newrc->rc_qtype;
	for (pp = &n->n_cached_ans; p = *pp; ) {
		if (p->rc_qtype == qtype || current_time >= p->rc_expire) {
			*pp = p->rc_next;
			if (p->rc_pos)
				free_rrchain(p->rc_pos);
			free(p);
			continue;
		}
		pp = &p->rc_next;
	}
	/* putting the new one at the head produces an LRU effect */
	newrc->rc_next = n->n_cached_ans;
	n->n_cached_ans = newrc;
	/* if there is an old NXDOMAIN, it's obviously in conflict; delete it */
	if (n->n_cached_nxdom) {
		free(n->n_cached_nxdom);
		n->n_cached_nxdom = 0;
	}
}

I 4
void
fsrcache_store_posans(n, rrchain, qtype, expire)
	struct node *n;
	struct rr *rrchain;
	int qtype;
	time_t expire;
{
	register struct rescache *rc;

	rc = (struct rescache *) myalloc(sizeof(struct rescache));
	if (!rc) {
		free_rrchain(rrchain);
		return;
	}
	rc->rc_expire = expire;
	rc->rc_qtype = qtype;
	rc->rc_pos = rrchain;
	install_qtype_rescache(n, rc);
}

E 4
static struct rescache *
create_neg_rescache(soa, ttl)
	register struct parsedrr *soa;
	u_long ttl;
{
	register u_char *dp;
	register struct rescache *rc;
	register struct ncache *nc;

	dp = myalloc(sizeof(struct rescache) + sizeof(struct ncache) +
			dn_spaceneeded(&soa->prr_owner) +
			dn_spaceneeded(&soa->prr_rdata_dn[0]) +
			dn_spaceneeded(&soa->prr_rdata_dn[1]));
	if (!dp)
		return(0);
	rc = (struct rescache *)dp;
	dp += sizeof(struct rescache);
	rc->rc_expire = current_time + ttl;
	rc->rc_pos = 0;
	nc = (struct ncache *)dp;
	dp += sizeof(struct ncache);
	nc->nsoa_owner = (struct dname *)dp;
	dname_copy_discontig(&soa->prr_owner, dp);
	dp += dn_spaceneeded(&soa->prr_owner);
	nc->nsoa_mname = (struct dname *)dp;
	dname_copy_discontig(&soa->prr_rdata_dn[0], dp);
	dp += dn_spaceneeded(&soa->prr_rdata_dn[0]);
	nc->nsoa_rname = (struct dname *)dp;
	dname_copy_discontig(&soa->prr_rdata_dn[1], dp);
	bcopy(soa->prr_rdata_misc, nc->nsoa_numbers, 20);
	return(rc);
}

static void
clean_node_for_nxdom(n)
	register struct node *n;
{
	/* delete any previous cached answers or CNAME */
	if (n->n_cached_ans) {
		free_rescache_chain(n->n_cached_ans);
		n->n_cached_ans = 0;
	}
	if (n->n_cached_cname) {
		free(n->n_cached_cname);
		n->n_cached_cname = 0;
	}
	/* if there is an old NXDOMAIN, delete it too */
	if (n->n_cached_nxdom) {
		free(n->n_cached_nxdom);
		n->n_cached_nxdom = 0;
	}
}

void
fsrcache_store_negans(q, soa)
	struct query *q;
	struct parsedrr *soa;
{
	register u_long ttl;
	register u_char *cp;
	register struct rescache *rc;
	register struct node *n;
	register struct query_stage *qs;

	cp = soa->prr_rdata_misc + 16;
	GETLONG(ttl, cp);
	if (ttl > ttl_limit_ncache)
		ttl = ttl_limit_ncache;
	if (ttl < ttl_sensible_min)
		return;
	rc = create_neg_rescache(soa, ttl);
	if (!rc)
		return;
	qs = &q->q_stages[q->q_curstage];
	n = get_node_for_cache(q, &qs->qs_qname, 1);
	if (!n) {
		free(rc);
		return;
	}
	switch (qs->qs_result) {
	case QSRESULT_NOREC:
		rc->rc_qtype = q->q_type;
		install_qtype_rescache(n, rc);
		return;
	case QSRESULT_NXDOMAIN:
		clean_node_for_nxdom(n);
		n->n_cached_nxdom = rc;
		return;
	default:
		syslog(LOG_CRIT,
		"BUG: unexpected qs_result %d in fsrcache_store_negans()",
			qs->qs_result);
		abort();
	}
}

void
fsrcache_store_cname(q, prr)
	struct query *q;
	register struct parsedrr *prr;
{
	register u_long ttl;
	register struct rr *srr;
	register struct node *n;

	ttl = prr->prr_fix.ttl;
	if (ttl > ttl_limit_data)
		ttl = ttl_limit_data;
	if (ttl < ttl_bump_cname)
		ttl = ttl_bump_cname;
	if (ttl < ttl_sensible_min)
		return;
	srr = internalize_rr(prr, ttl);
	if (!srr)
		return;
	n = get_node_for_cache(q, &prr->prr_owner, 1);
	if (!n) {
		free(srr);
		return;
	}
	if (n->n_cached_cname)
		free(n->n_cached_cname);
	n->n_cached_cname = srr;
	/* if there is an old NXDOMAIN, it's obviously in conflict; delete it */
	if (n->n_cached_nxdom) {
		free(n->n_cached_nxdom);
		n->n_cached_nxdom = 0;
	}
E 2
}
E 1
