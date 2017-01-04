h10764
s 00023/00008/00166
d D 1.9 2013/01/14 01:46:46 msokolov 9 8
c delete any cached answers from shadowed subtrees
e
s 00002/00002/00172
d D 1.8 2013/01/06 07:03:52 msokolov 8 7
c MSDNS => FalconDNS
e
s 00014/00002/00160
d D 1.7 2011/12/10 04:53:23 msokolov 7 6
c more careful handling of new zones overlapped an in-zone child
e
s 00001/00000/00161
d D 1.6 2011/12/01 06:27:18 msokolov 6 5
c set n_unlinked flag
e
s 00012/00000/00149
d D 1.5 2011/10/28 04:43:16 msokolov 5 4
c NS-anchor deletion handling
e
s 00046/00018/00103
d D 1.4 2011/07/19 19:02:43 msokolov 4 3
c reattach_lower_zones() split off from free_subtree()
e
s 00003/00000/00118
d D 1.3 2011/07/16 02:12:11 msokolov 3 2
c correctly go down zonech path as well
e
s 00006/00008/00112
d D 1.2 2011/07/16 01:18:47 msokolov 2 1
c zone loading code complete
e
s 00120/00000/00000
d D 1.1 2011/07/15 23:50:37 msokolov 1 0
c date and time created 2011/07/15 23:50:37 by msokolov
e
u
U
t
T
I 1
/*
D 8
 * Michael Sokolov's Domain Name Server (MSDNS)
E 8
I 8
 * FalconDNS daemon by Michael Spacefalcon
E 8
 *
 * This module handles the installation of newly loaded zones
D 8
 * into the active domain tree.
E 8
I 8
 * into the active domain data tree.
E 8
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "dname.h"
#include "tree.h"
#include "zone.h"
#include "class.h"
I 5
#include "nsrec.h"
E 5

extern struct node *alloc_new_node(), *node_findchild();

/*
 * This function installs a new zone tree, replacing any previous
 * node in its place.  All 3 arguments must be non-null.
 *
 * Return value:
 *  0 = success
 * -1 = malloc failure when filling intermediate nodes
 */
install_zone_tree(cl, zt, anchor)
	struct class *cl;
	struct node *zt;
	register struct dname *anchor;
{
	int depth;
	register struct node *n, *ch;
	struct node_findaddchild_private_state st;
	static char rootlabel = 0;

	/* are we installing a root zone? */
	if (!anchor->dn_nlabels) {
		/* it's either a trivial install or replace */
		if (cl->c_root)
			return(replace_zone_tree(cl->c_root, zt));
		cl->c_root = zt;
		zt->n_backptr = &cl->c_root;
		return(0);
	}
	/* not root zone: get to immediate parent node */
	/* is there a root node already? */
	n = cl->c_root;
	if (!n) {
		n = alloc_new_node(cl, &rootlabel);
		if (!n)
			return(-1);
		cl->c_root = n;
		n->n_backptr = &cl->c_root;
	}
	depth = anchor->dn_nlabels;
	for (; --depth; n = ch) {
		ch = node_findchild(&n->n_nzch, anchor->dn_labels[depth], &st);
I 3
		if (!ch)
			ch = node_findchild(&n->n_zonech,
					    anchor->dn_labels[depth], 0);
E 3
		if (!ch) {
			ch = alloc_new_node(cl, anchor->dn_labels[depth]);
			if (!ch)
				return(-1);
			if (node_addchild(&n->n_nzch, ch, &st) < 0) {
				free(ch);
				return(-1);
			}
			ch->n_parent = n;
		}
	}
	zt->n_parent = n;
	ch = node_findchild(&n->n_nzch, anchor->dn_labels[0], &st);
	if (ch)
		return(replace_zone_tree(ch, zt));
D 7
	return(node_addchild(&n->n_nzch, zt, &st));
E 7
I 7
	if (node_addchild(&n->n_nzch, zt, &st) < 0)
		return(-1);
	ch = node_findchild(&n->n_zonech, anchor->dn_labels[0], 0);
	if (ch)
		reattach_lower_zones_overlap(ch);
	return(0);
E 7
}

/*
I 4
 * reattach_lower_zones() scans a subtree which is about to be freed,
 * locates any zones which are *below* the given node, and reattaches
 * them via install_zone_tree().
 */

static void
reattach_zone(z)
	register struct zone *z;
{
	if (install_zone_tree(z->z_class, z->z_activetree, z->z_dname) < 0) {
		syslog(LOG_CRIT,
		"zone %s (%d) has been lost to swap above + malloc failure",
			z->z_ascii_domname, z->z_class->c_class);
		reattach_lower_zones(z->z_activetree);
		free_subtree(z->z_activetree);
		z->z_activetree = 0;
		z->z_flags |= Z_LOST_IN_MALLOC;
	}
}

static void
reattach_process_node(n, orig)
	register struct node *n, *orig;
{
I 5
	register struct ns_rrset *ns;
	struct ns_anchor *a;

E 5
	if (n != orig && n->n_zone) {
		if (n->n_nextsib)
			n->n_nextsib->n_backptr = n->n_backptr;
		*n->n_backptr = n->n_nextsib;
		reattach_zone(n->n_zone);
		return;
I 5
	}
I 6
D 7
	n->n_unlinked = 1;
E 7
I 7
D 9
	if (orig)
E 9
I 9
	if (orig) {
E 9
		n->n_unlinked = 1;
E 7
E 6
D 9
	ns = n->n_ns;
	if (ns && ns->ns_type == NSTYPE_ANCHOR) {
		a = (struct ns_anchor *) ns;
		syslog(LOG_NOTICE,
			"NS-anchor at %s (class %d) displaced by zone",
			a->nsa_ascii_domname, n->n_class->c_class);
		delete_nsanchor(a);
E 9
I 9
		ns = n->n_ns;
		if (ns && ns->ns_type == NSTYPE_ANCHOR) {
			a = (struct ns_anchor *) ns;
			syslog(LOG_NOTICE,
				"NS-anchor at %s (class %d) displaced by zone",
				a->nsa_ascii_domname, n->n_class->c_class);
			delete_nsanchor(a);
		}
	} else {
		/* delete any cached stuff from the shadowed subtree */
		if (n->n_cached_ans) {
			free_rescache_chain(n->n_cached_ans);
			n->n_cached_ans = 0;
		}
		if (n->n_cached_cname) {
			free(n->n_cached_cname);
			n->n_cached_cname = 0;
		}
		if (n->n_cached_nxdom) {
			free(n->n_cached_nxdom);
			n->n_cached_nxdom = 0;
		}
E 9
E 5
	}
	if (n->n_zonech)
		iterate_node_children(n->n_zonech, reattach_process_node, orig);
	if (n->n_nzch)
		iterate_node_children(n->n_nzch, reattach_process_node, orig);
}

reattach_lower_zones(n)
	struct node *n;
{
	reattach_process_node(n, n);
I 7
}

reattach_lower_zones_overlap(n)
	struct node *n;
{
	reattach_process_node(n, 0);
E 7
}

/*
E 4
 * This function replaces a given node/tree with a new node/tree.
 * The old argument must be non-null, but the new argument may be null
 * if a zone is being deleted from the active domain tree.
 */
replace_zone_tree(old, new)
	struct node *old, *new;
{
	if (new) {
		new->n_nextsib = old->n_nextsib;
		if (new->n_nextsib)
			new->n_nextsib->n_backptr = &new->n_nextsib;
		new->n_backptr = old->n_backptr;
		*new->n_backptr = new;
	} else {
		if (old->n_nextsib)
			old->n_nextsib->n_backptr = old->n_backptr;
		*old->n_backptr = old->n_nextsib;
	}
D 4
	free_subtree(old, 1);
E 4
I 4
	reattach_lower_zones(old);
	free_subtree(old);
E 4
	return(0);
D 4
}

/*
 * This function reattaches a zone tree which was about to be
 * tossed by free_subtree() called from replace_zone_tree().
 */
reattach_zone(z)
	register struct zone *z;
{
D 2
	register int i;

	i = install_zone_tree(z->z_class, z->z_activetree, z->z_dname);
	if (i < 0) {
		z->z_flags |= Z_ZOMBIE;
E 2
I 2
	if (install_zone_tree(z->z_class, z->z_activetree, z->z_dname) < 0) {
E 2
		syslog(LOG_CRIT,
D 2
	"zone %s (%d) has become a zombie (swap above + malloc failure)",
E 2
I 2
		"zone %s (%d) has been lost to swap above + malloc failure",
E 2
			z->z_ascii_domname, z->z_class->c_class);
D 2
	} else
		z->z_flags &= ~Z_ZOMBIE;
E 2
I 2
		free_subtree(z->z_activetree, 1);
		z->z_activetree = 0;
		z->z_flags |= Z_LOST_IN_MALLOC;
	}
E 4
E 2
}
E 1
