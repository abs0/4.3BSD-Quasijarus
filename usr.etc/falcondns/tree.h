/*
 * Our view of the domain name tree is of the old-fashioned kind,
 * RFC 882/883-style: a single tree in which all zones and the cache
 * are mixed together.
 *
 * This key FalconDNS data structure is called the active domain data
 * tree (ADDT).  It stores all of our authoritative data, and the
 * operation of our FSR revolves around the ADDT as well.
 *
 *	@(#)tree.h	1.11 (IFCTF) 2013/01/11
 */

#ifndef	__TREE_H
#define	__TREE_H

struct node {
	/* info intrinsic to the node itself */
	u_char	n_labellen;
	u_char	n_label_cp[MAXLABEL];	/* case-preserving */
	u_char	n_label_uc[MAXLABEL];	/* uppercase */
	/* simple links */
	u_char	n_unlinked;
	struct	class *n_class;
	struct	node *n_parent;
	struct	node *n_nextsib;	/* in whatever chain our parent has */
					/* used to link to us */
	struct	node **n_backptr;	/* whichever link points to us */
	/* RRs attached to this node */
	struct	soa *n_soa;		/* SOA only from zone */
	struct	ns_rrset *n_ns;		/* see nsrec.h */
	struct	rr *n_rrzone;		/* RRs from zone (not NS or SOA) */
	struct	rescache *n_cached_ans;
	struct	rr *n_cached_cname;
	struct	rescache *n_cached_nxdom;
	/* child nodes within the zone */
	struct	hashtable *n_zonech;
	struct	node *n_zonech_wild;
	/* child nodes not from within the zone */
	struct	hashtable *n_nzch;
	/* our private management info */
	struct	zone *n_zone;	/* is there a zone attached to this node? */
	struct	node *n_zonehead;
	struct	node *n_nextinzone;
	struct	node *n_nextincache;
	struct	node **n_cache_backptr;
	int	n_refcount;	/* normally 1, incremented for held pointers */
};

/*
 * The black magic of dynamically expanding hash tables which
 * provide the branching glue between tree nodes.
 */
struct hashtable {
	struct	node *h_chains[16];
	struct	hashtable *h_subtables[16];
};

/*
 * We have two sets of links to child nodes: one for in-zone nodes
 * and one for other nodes.  The non-zone children take precedence.
 * At first that will seem counter-logical, but consider the case when
 * we are authoritative for two adjoining zones: in that case the
 * non-zone child will be the child zone, whereas the in-zone child
 * will be the glue record.  The child zone should take precedence.
 *
 * The case of adjoining or overlapping zones is the only one in which
 * a given subdomain label can appear in both in-zone and non-zone
 * child hash tables, and is the sole reason for the present complexity.
 *
 * The cache mechanism won't be allowed to create child nodes under a
 * zonal node unless they fall below a bottom cut point, and it will
 * traverse down the in-zone child links when they exist before creating
 * new nodes.
 */

/*
 * The node_findchild() and node_addchild() functions work in tandem.
 * If you are traversing the tree with no intent of modifying it,
 * just use node_findchild().  However, if you are going to add a node,
 * you are of course expected to check if one already exists (that's
 * the whole point of these nodes!), and the two functions work together
 * in this case.  Call node_findchild() first, but pass it a pointer
 * to a private state structure.  If the node doesn't already exist,
 * you create one, and when you call node_addchild(), you pass that
 * saved state from node_findchild().  The node_addchild() function
 * does NOT work by itself without node_findchild().
 */
struct node_findaddchild_private_state {
	u_long	hash;
	struct	hashtable *ht;
	int	nlevels;
	int	idx;
	int	chainlen;
};

#endif	/* include guard */
