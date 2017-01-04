/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Basic operations on domain tree nodes
 */

#ifndef lint
static char sccsid[] = "@(#)treenode.c	1.20 (IFCTF) 2013/01/13";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include <ctype.h>
#include <syslog.h>
#include "class.h"
#include "dname.h"
#include "tree.h"
#include "nsrec.h"
#include "globals.h"

extern u_char *myalloc();
extern u_long label_hash();

struct node *
alloc_new_node(cl, label)
	struct class *cl;
	u_char *label;
{
	register struct node *n;

	n = (struct node *)myalloc(sizeof(struct node));
	if (n) {
		bzero(n, sizeof(struct node));
		n->n_class = cl;
		store_label_in_node(label, n);
		n->n_refcount = 1;
	}
	return(n);
}

struct node *
node_findchild(chlist, lab, st)
	struct hashtable **chlist;
	register u_char *lab;
	register struct node_findaddchild_private_state *st;
{
	register struct hashtable *h;
	register int idx;
	register struct node *n = 0;
	u_long hash;

	hash = label_hash(lab);
	if (st) {
		st->hash = hash;
		st->nlevels = 0;
	}
	for (h = *chlist; h; ) {
		idx = hash & 0xF;
		if (st) {
			st->ht = h;
			st->nlevels++;
			st->idx = idx;
		}
		n = h->h_chains[idx];
		if (n)
			break;
		h = h->h_subtables[idx];
		hash >>= 4;
	}
	for (idx = 0; n; n = n->n_nextsib, idx++)
		if (label_match_node(lab, n))
			return(n);
	if (st)
		st->chainlen = idx;
	return(0);
}

/*
 * This function allocates the first level hash table for the first time.
 * Returns 0 if successful or -1 if malloc failed.
 */
static
alloc_first_hash(chlist)
	struct hashtable **chlist;
{
	register u_char *chunk;

	chunk = myalloc(sizeof(struct hashtable));
	if (!chunk)
		return(-1);
	bzero(chunk, sizeof(struct hashtable));
	*chlist = (struct hashtable *)chunk;
	return(0);
}

static void
split_hash(st, newh)
	register struct node_findaddchild_private_state *st;
	register struct hashtable *newh;
{
	register struct node *n, *nsib;
	struct node *nn;
	int shiftcnt;
	register int idx;

	bzero(newh, sizeof(struct hashtable));
	st->ht->h_subtables[st->idx] = newh;
	n = st->ht->h_chains[st->idx];
	st->ht->h_chains[st->idx] = 0;
	shiftcnt = st->nlevels * 4;
	for (; n; n = nn) {
		nn = n->n_nextsib;
		idx = (label_hash(n) >> shiftcnt) & 0xF;
		n->n_nextsib = nsib = newh->h_chains[idx];
		if (nsib)
			nsib->n_backptr = &n->n_nextsib;
		n->n_backptr = &newh->h_chains[idx];
		newh->h_chains[idx] = n;
	}
}

node_addchild(chlist, new, st)
	register struct hashtable **chlist;
	register struct node *new;
	register struct node_findaddchild_private_state *st;
{
	register struct node *prev, **chainp;
	register u_char *newhash;

	if (*chlist)
		chainp = &st->ht->h_chains[st->idx];
	else {
		if (alloc_first_hash(chlist) < 0)
			return(-1);
		chainp = &(*chlist)->h_chains[st->hash&0xF];
	}
	prev = *chainp;
	new->n_nextsib = prev;
	if (prev)
		prev->n_backptr = &new->n_nextsib;
	*chainp = new;
	new->n_backptr = chainp;
	if (st->chainlen >= max_hash_chain && st->nlevels <= 7 &&
	    (newhash = myalloc(sizeof(struct hashtable))))
		split_hash(st, (struct hashtable *) newhash);
	return(0);
}

struct node *
find_node_by_dname(cl, target)
	struct class *cl;
	register struct dname *target;
{
	register struct node *n, *ch;
	register int depth;

	n = cl->c_root;
	for (depth = target->dn_nlabels; n; n = ch) {
		if (!depth--)
			break;
		ch = node_findchild(&n->n_nzch, target->dn_labels[depth], 0);
		if (!ch)
			ch = node_findchild(&n->n_zonech,
					    target->dn_labels[depth], 0);
	}
	return(n);
}

/*
 * free_subtree() frees a node and everything below it: RRs, children
 * and hash tables.  The node must have already been unlinked from
 * whatever is above before calling this function.
 */

void
free_rrchain(rr)
	register struct rr *rr;
{
	register struct rr *next;

	for (; rr; rr = next) {
		next = rr->rr_next;
		free(rr);
	}
}

void
free_rescache_chain(rc)
	register struct rescache *rc;
{
	register struct rescache *next;
	register struct rr *rrs;

	for (; rc; rc = next) {
		rrs = rc->rc_pos;
		if (rrs)
			free_rrchain(rrs);
		next = rc->rc_next;
		free(rc);
	}
}

void
free_ns_rrset(ns)
	struct ns_rrset *ns;
{
	register struct nsrr *rr, *next;

	for (rr = ns->ns_chain; rr; rr = next) {
		next = rr->nsrr_next;
		free(rr);
	}
	free(ns);
}

static void free_hashtable();

void
free_subtree(n)
	register struct node *n;
{
	if (--n->n_refcount > 0)
		return;
	if (n->n_refcount < 0) {
		syslog(LOG_CRIT, "BUG: n_refcount decremented past zero");
		abort();
	}
	if (n->n_soa)
		free(n->n_soa);
	if (n->n_ns)
		free_ns_rrset(n->n_ns);
	if (n->n_rrzone)
		free_rrchain(n->n_rrzone);
	if (n->n_cached_ans)
		free_rescache_chain(n->n_cached_ans);
	if (n->n_cached_cname)
		free(n->n_cached_cname);
	if (n->n_cached_nxdom)
		free(n->n_cached_nxdom);
	if (n->n_cache_backptr) {
		*n->n_cache_backptr = n->n_nextincache;
		if (n->n_nextincache)
			n->n_nextincache->n_cache_backptr = n->n_cache_backptr;
	}
	if (n->n_zonech)
		free_hashtable(n->n_zonech);
	if (n->n_nzch)
		free_hashtable(n->n_nzch);
	free(n);
}

static void
free_hashtable(h)
	register struct hashtable *h;
{
	register int i;
	register struct node *n, *nn;

	for (i = 0; i < 16; i++) {
		for (n = h->h_chains[i]; n; n = nn) {
			nn = n->n_nextsib;
			free_subtree(n);
		}
		if (h->h_subtables[i])
			free_hashtable(h->h_subtables[i]);
	}
	free(h);
}

iterate_node_children(h, func, arg)
	register struct hashtable *h;
	void (*func)();
	u_long arg;
{
	register int i;
	register struct node *n;

	for (i = 0; i < 16; i++) {
		for (n = h->h_chains[i]; n; n = n->n_nextsib)
			func(n, arg);
		if (h->h_subtables[i])
			iterate_node_children(h->h_subtables[i], func, arg);
	}
}

static
hashtable_nonempty(h)
	register struct hashtable *h;
{
	register int i;

	for (i = 0; i < 16; i++)
		if (h->h_chains[i])
			return(1);
	for (i = 0; i < 16; i++)
		if (h->h_subtables[i] && hashtable_nonempty(h->h_subtables[i]))
			return(1);
	return(0);
}

node_has_children(n)
	register struct node *n;
{
	if (n->n_zonech && hashtable_nonempty(n->n_zonech))
		return(1);
	if (n->n_nzch && hashtable_nonempty(n->n_nzch))
		return(1);
	return(0);
}

static void
hashinfo_recurse(h, level, totalp, levelsp, maxchp)
	register struct hashtable *h;
	int level, *totalp, *levelsp, *maxchp;
{
	register int i, clen;
	register struct node *n;

	if (level > *levelsp)
		*levelsp = level;
	for (i = 0; i < 16; i++) {
		for (n = h->h_chains[i], clen = 0; n; n = n->n_nextsib, clen++)
			(*totalp)++;
		if (clen > *maxchp)
			*maxchp = clen;
		if (h->h_subtables[i])
			hashinfo_recurse(h->h_subtables[i], level+1, totalp,
					 levelsp, maxchp);
	}
}

static void
hashinfo_initrecurse(h, totalp, levelsp, maxchp)
	register struct hashtable *h;
	int *totalp, *levelsp, *maxchp;
{
	*totalp = 0;
	*levelsp = 0;
	*maxchp = 0;
	hashinfo_recurse(h, 1, totalp, levelsp, maxchp);
}

void
cmd_hash_info(args)
	char *args;
{
	register char *cp;
	char *arg1, *arg2;
	int classnum;
	register struct class *cl;
	struct dname dname;
	register struct node *n;
	int total, levels, maxchain;

	for (cp = args; isspace(*cp); cp++)
		;
	if (!isdigit(*cp)) {
badusage:	syslog(LOG_ERR, "usage: hash-info class domain");
		return;
	}
	for (arg1 = cp; *cp && !isspace(*cp); cp++)
		;
	if (!*cp)
		goto badusage;
	*cp++ = '\0';
	while (isspace(*cp))
		cp++;
	if (!*cp)
		goto badusage;
	for (arg2 = cp; *cp && !isspace(*cp); cp++)
		;
	if (*cp)
		*cp++ = '\0';
	classnum = atoi(arg1);
	if (classnum >= 255)
		goto badusage;
	cl = class_array[classnum];
	if (!cl) {
		syslog(LOG_ERR, "hash-info: class %d not defined", classnum);
		return;
	}
	if (parse_ascii_dname(arg2, &dname) < 0)
		goto badusage;
	n = find_node_by_dname(cl, &dname);
	if (!n) {
		syslog(LOG_ERR, "hash-info: %s not found in class %d", arg2,
			classnum);
		return;
	}
	if (n->n_zonech) {
		hashinfo_initrecurse(n->n_zonech, &total, &levels, &maxchain);
		syslog(LOG_INFO,
	"%s (%d): in-zone children: %d total, hash depth %d, max chain %d",
			arg2, classnum, total, levels, maxchain);
	} else
		syslog(LOG_INFO, "%s (%d): no in-zone children", arg2,
			classnum);
	if (n->n_nzch) {
		hashinfo_initrecurse(n->n_nzch, &total, &levels, &maxchain);
		syslog(LOG_INFO,
	"%s (%d): non-zone children: %d total, hash depth %d, max chain %d",
			arg2, classnum, total, levels, maxchain);
	} else
		syslog(LOG_INFO, "%s (%d): no non-zone children", arg2,
			classnum);
}
