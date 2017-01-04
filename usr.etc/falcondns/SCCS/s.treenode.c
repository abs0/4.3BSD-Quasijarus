h62084
s 00002/00006/00404
d D 1.20 2013/01/13 21:56:22 msokolov 20 19
c free_subtree: no more need to worry about deleting active NS-anchors,
c it was only needed for hard class reloads, and is now taken care of
c in the extra treewalk done by the hard class reload code in classreload.c
e
s 00002/00002/00408
d D 1.19 2013/01/13 15:45:52 msokolov 19 18
c check for empty child hash tables: possible speed-up
e
s 00027/00003/00383
d D 1.18 2013/01/11 23:02:43 msokolov 18 17
c first round of changes for the new FSR cache design
e
s 00001/00001/00385
d D 1.17 2011/12/18 20:10:05 msokolov 17 16
c bugfix in split_hash()
e
s 00098/00000/00288
d D 1.16 2011/12/13 03:54:49 msokolov 16 15
c hash-info implemented
e
s 00004/00005/00284
d D 1.15 2011/12/13 03:33:51 msokolov 15 14
c free_subtree() on an NS-anchor is now legal with hard reload-class
e
s 00022/00000/00267
d D 1.14 2011/12/10 07:55:33 msokolov 14 13
c find_node_by_dname() implemented
e
s 00025/00000/00242
d D 1.13 2011/12/10 07:37:03 msokolov 13 12
c node_has_children() implemented
e
s 00044/00011/00198
d D 1.12 2011/12/10 07:24:03 msokolov 12 11
c hash splitting implemented
e
s 00005/00000/00204
d D 1.11 2011/12/01 06:15:56 msokolov 11 10
c data structure changes in preparation for cache-created nodes
e
s 00006/00001/00198
d D 1.10 2011/10/28 04:43:15 msokolov 10 9
c NS-anchor deletion handling
e
s 00002/00002/00197
d D 1.9 2011/09/13 00:30:57 msokolov 9 8
c free_rrchain() and free_ns_rrset() exported
e
s 00016/00001/00183
d D 1.8 2011/09/12 04:26:03 msokolov 8 7
c NS record handling revamped into RRset model
e
s 00006/00017/00178
d D 1.7 2011/07/19 19:02:41 msokolov 7 6
c reattach_lower_zones() split off from free_subtree()
e
s 00027/00012/00168
d D 1.6 2011/07/18 00:22:51 msokolov 6 5
c further optimization and tree walking support
e
s 00003/00002/00177
d D 1.5 2011/07/17 00:38:23 msokolov 5 4
c label case handling rethought slightly
e
s 00031/00010/00148
d D 1.4 2011/07/15 23:53:13 msokolov 4 3
c zoneinst.c added
e
s 00051/00000/00107
d D 1.3 2011/07/15 21:48:07 msokolov 3 2
c free_subtree() implemented
e
s 00078/00000/00029
d D 1.2 2011/07/14 07:03:13 msokolov 2 1
c node_findchild()/node_addchild() magic implemented
e
s 00029/00000/00000
d D 1.1 2011/07/14 02:02:21 msokolov 1 0
c date and time created 2011/07/14 02:02:21 by msokolov
e
u
U
t
T
I 1
/*
D 18
 * Basic operations on tree nodes
E 18
I 18
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Basic operations on domain tree nodes
E 18
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
I 16
#include <ctype.h>
E 16
I 4
#include <syslog.h>
I 14
#include "class.h"
#include "dname.h"
E 14
E 4
#include "tree.h"
I 3
D 8
#include "rr.h"
E 8
I 8
#include "nsrec.h"
I 12
#include "globals.h"
E 12
E 8
E 3

extern u_char *myalloc();
I 2
extern u_long label_hash();
E 2

struct node *
alloc_new_node(cl, label)
	struct class *cl;
	u_char *label;
{
	register struct node *n;

	n = (struct node *)myalloc(sizeof(struct node));
	if (n) {
I 5
		bzero(n, sizeof(struct node));
E 5
		n->n_class = cl;
		store_label_in_node(label, n);
		n->n_refcount = 1;
	}
	return(n);
I 2
}

struct node *
node_findchild(chlist, lab, st)
D 6
	struct nodechildren *chlist;
E 6
I 6
	struct hashtable **chlist;
E 6
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
D 6
	for (h = chlist->nch_hash; h; ) {
E 6
I 6
	for (h = *chlist; h; ) {
E 6
		idx = hash & 0xF;
D 12
		if (st)
			st->chain = &h->h_chains[idx];
E 12
I 12
		if (st) {
			st->ht = h;
			st->nlevels++;
			st->idx = idx;
		}
E 12
		n = h->h_chains[idx];
		if (n)
			break;
		h = h->h_subtables[idx];
		hash >>= 4;
D 12
		if (st)
			st->nlevels++;
E 12
	}
	for (idx = 0; n; n = n->n_nextsib, idx++)
D 5
		if (label_match_can(lab, n))
E 5
I 5
		if (label_match_node(lab, n))
E 5
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
D 6
	struct nodechildren *chlist;
E 6
I 6
	struct hashtable **chlist;
E 6
{
	register u_char *chunk;

	chunk = myalloc(sizeof(struct hashtable));
	if (!chunk)
		return(-1);
	bzero(chunk, sizeof(struct hashtable));
D 6
	chlist->nch_hash = (struct hashtable *)chunk;
E 6
I 6
	*chlist = (struct hashtable *)chunk;
E 6
	return(0);
}

I 12
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
D 17
		idx = label_hash(n) >> shiftcnt;
E 17
I 17
		idx = (label_hash(n) >> shiftcnt) & 0xF;
E 17
		n->n_nextsib = nsib = newh->h_chains[idx];
		if (nsib)
			nsib->n_backptr = &n->n_nextsib;
		n->n_backptr = &newh->h_chains[idx];
		newh->h_chains[idx] = n;
	}
}

E 12
node_addchild(chlist, new, st)
D 6
	register struct nodechildren *chlist;
E 6
I 6
	register struct hashtable **chlist;
E 6
	register struct node *new;
	register struct node_findaddchild_private_state *st;
{
D 12
	register struct node *prev;
E 12
I 12
	register struct node *prev, **chainp;
	register u_char *newhash;
E 12

D 6
	if (!chlist->nch_hash) {
E 6
I 6
D 12
	if (!*chlist) {
E 12
I 12
	if (*chlist)
		chainp = &st->ht->h_chains[st->idx];
	else {
E 12
E 6
		if (alloc_first_hash(chlist) < 0)
			return(-1);
D 6
		st->chain = &chlist->nch_hash->h_chains[st->hash&0xF];
E 6
I 6
D 12
		st->chain = &(*chlist)->h_chains[st->hash&0xF];
E 12
I 12
		chainp = &(*chlist)->h_chains[st->hash&0xF];
E 12
E 6
	}
D 12
	prev = *st->chain;
E 12
I 12
	prev = *chainp;
E 12
	new->n_nextsib = prev;
	if (prev)
		prev->n_backptr = &new->n_nextsib;
D 12
	*st->chain = new;
	new->n_backptr = st->chain;
D 5
	chlist->nch_count++;
E 5
I 5
D 6
	/* chlist->nch_count++; */
E 6
E 5
	/* TODO: implement hash splitting */
E 12
I 12
	*chainp = new;
	new->n_backptr = chainp;
	if (st->chainlen >= max_hash_chain && st->nlevels <= 7 &&
	    (newhash = myalloc(sizeof(struct hashtable))))
		split_hash(st, (struct hashtable *) newhash);
E 12
	return(0);
I 14
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
E 14
I 3
}

/*
 * free_subtree() frees a node and everything below it: RRs, children
 * and hash tables.  The node must have already been unlinked from
 * whatever is above before calling this function.
I 4
D 7
 *
 * The second argument to free_subtree() tells it whether or not
 * it should check for zones in need of reattachment.
E 7
E 4
 */

I 4
D 9
static void
E 9
I 9
void
E 9
E 4
free_rrchain(rr)
	register struct rr *rr;
{
	register struct rr *next;

	for (; rr; rr = next) {
		next = rr->rr_next;
		free(rr);
	}
}

I 8
D 9
static void
E 9
I 9
void
I 18
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
E 18
E 9
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

E 8
D 4
free_subtree(n)
E 4
I 4
static void free_hashtable();

void
D 7
free_subtree(n, flag)
E 7
I 7
free_subtree(n)
E 7
E 4
	register struct node *n;
I 4
D 7
	register int flag;
E 7
E 4
{
D 4
	register struct rr *rr;

E 4
I 4
D 7
	if (flag >= 2 && n->n_zone) {
		reattach_zone(n->n_zone);
		return;
	}
E 7
	if (--n->n_refcount > 0)
		return;
	if (n->n_refcount < 0) {
		syslog(LOG_CRIT, "BUG: n_refcount decremented past zero");
		abort();
	}
E 4
	if (n->n_soa)
		free(n->n_soa);
I 8
D 10
	if (n->n_ns)
E 10
I 10
D 20
	if (n->n_ns) {
D 15
		if (n->n_ns->ns_type == NSTYPE_ANCHOR) {
			syslog(LOG_CRIT, "BUG: free_subtree() on NS-anchor");
			abort();
		}
E 10
		free_ns_rrset(n->n_ns);
E 15
I 15
		if (n->n_ns->ns_type == NSTYPE_ANCHOR)
			delete_nsanchor((struct ns_anchor *) n->n_ns);
		else
			free_ns_rrset(n->n_ns);
E 15
I 10
	}
E 20
I 20
	if (n->n_ns)
		free_ns_rrset(n->n_ns);
E 20
E 10
E 8
D 18
	free_rrchain(n->n_rrzone);
	free_rrchain(n->n_rrcache);
E 18
I 18
	if (n->n_rrzone)
		free_rrchain(n->n_rrzone);
	if (n->n_cached_ans)
		free_rescache_chain(n->n_cached_ans);
	if (n->n_cached_cname)
		free(n->n_cached_cname);
	if (n->n_cached_nxdom)
		free(n->n_cached_nxdom);
E 18
I 11
	if (n->n_cache_backptr) {
		*n->n_cache_backptr = n->n_nextincache;
		if (n->n_nextincache)
			n->n_nextincache->n_cache_backptr = n->n_cache_backptr;
	}
E 11
D 4
	free_hashtable_with_children(n->n_zonech.nch_hash);
	free_hashtable_with_children(n->n_nzch.nch_hash);
E 4
I 4
D 7
	if (flag)
		flag++;
E 7
D 6
	if (n->n_zonech.nch_hash)
		free_hashtable(n->n_zonech.nch_hash, flag);
	if (n->n_nzch.nch_hash)
		free_hashtable(n->n_nzch.nch_hash, flag);
E 6
I 6
	if (n->n_zonech)
D 7
		free_hashtable(n->n_zonech, flag);
E 7
I 7
		free_hashtable(n->n_zonech);
E 7
	if (n->n_nzch)
D 7
		free_hashtable(n->n_nzch, flag);
E 7
I 7
		free_hashtable(n->n_nzch);
E 7
E 6
E 4
	free(n);
}

D 4
free_hashtable_with_children(h)
E 4
I 4
static void
D 7
free_hashtable(h, flag)
E 7
I 7
free_hashtable(h)
E 7
E 4
	register struct hashtable *h;
I 4
D 7
	register int flag;
E 7
E 4
{
	register int i;
	register struct node *n, *nn;

D 4
	if (!h)
		return;
E 4
	for (i = 0; i < 16; i++) {
		for (n = h->h_chains[i]; n; n = nn) {
			nn = n->n_nextsib;
D 4
			free_subtree(n);
E 4
I 4
D 7
			free_subtree(n, flag);
E 7
I 7
			free_subtree(n);
E 7
E 4
		}
		if (h->h_subtables[i])
D 4
			free_hashtable_with_children(h->h_subtables[i]);
E 4
I 4
D 7
			free_hashtable(h->h_subtables[i], flag);
E 7
I 7
			free_hashtable(h->h_subtables[i]);
E 7
E 4
	}
	free(h);
I 6
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
E 6
E 3
E 2
}
I 13

static
hashtable_nonempty(h)
	register struct hashtable *h;
{
	register int i;

D 19
	for (i = 0; i < 16; i++) {
E 19
I 19
	for (i = 0; i < 16; i++)
E 19
		if (h->h_chains[i])
			return(1);
I 19
	for (i = 0; i < 16; i++)
E 19
		if (h->h_subtables[i] && hashtable_nonempty(h->h_subtables[i]))
			return(1);
D 19
	}
E 19
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
I 16
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
E 16
}
E 13
E 1
