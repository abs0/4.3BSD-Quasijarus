/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * This module handles the installation of newly loaded zones
 * into the active domain data tree.
 */

#ifndef lint
static char sccsid[] = "@(#)zoneinst.c	1.9 (IFCTF) 2013/01/14";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "dname.h"
#include "tree.h"
#include "zone.h"
#include "class.h"
#include "nsrec.h"

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
		if (!ch)
			ch = node_findchild(&n->n_zonech,
					    anchor->dn_labels[depth], 0);
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
	if (node_addchild(&n->n_nzch, zt, &st) < 0)
		return(-1);
	ch = node_findchild(&n->n_zonech, anchor->dn_labels[0], 0);
	if (ch)
		reattach_lower_zones_overlap(ch);
	return(0);
}

/*
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
	register struct ns_rrset *ns;
	struct ns_anchor *a;

	if (n != orig && n->n_zone) {
		if (n->n_nextsib)
			n->n_nextsib->n_backptr = n->n_backptr;
		*n->n_backptr = n->n_nextsib;
		reattach_zone(n->n_zone);
		return;
	}
	if (orig) {
		n->n_unlinked = 1;
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
}

reattach_lower_zones_overlap(n)
	struct node *n;
{
	reattach_process_node(n, 0);
}

/*
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
	reattach_lower_zones(old);
	free_subtree(old);
	return(0);
}
