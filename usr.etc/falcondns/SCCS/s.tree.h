h31076
s 00022/00040/00074
d D 1.11 2013/01/11 23:02:41 msokolov 11 10
c first round of changes for the new FSR cache design
e
s 00002/00001/00112
d D 1.10 2011/12/10 07:24:01 msokolov 10 9
c hash splitting implemented
e
s 00007/00002/00106
d D 1.9 2011/12/01 06:15:55 msokolov 9 8
c data structure changes in preparation for cache-created nodes
e
s 00002/00000/00106
d D 1.8 2011/10/31 07:18:48 msokolov 8 7
c n_zonehead and n_nextinzone implemented
e
s 00012/00018/00094
d D 1.7 2011/09/12 04:26:02 msokolov 7 6
c NS record handling revamped into RRset model
e
s 00002/00007/00110
d D 1.6 2011/07/18 00:22:49 msokolov 6 5
c further optimization and tree walking support
e
s 00002/00002/00115
d D 1.5 2011/07/17 00:38:19 msokolov 5 4
c label case handling rethought slightly
e
s 00029/00002/00088
d D 1.4 2011/07/14 07:03:11 msokolov 4 3
c node_findchild()/node_addchild() magic implemented
e
s 00002/00002/00088
d D 1.3 2011/07/14 04:23:14 msokolov 3 2
c reworking structures for zone loading
e
s 00009/00006/00081
d D 1.2 2011/07/14 02:03:51 msokolov 2 1
c children substructure split out
e
s 00087/00000/00000
d D 1.1 11/07/11 08:04:08 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
 * Our view of the domain name tree is of the old-fashioned kind,
 * RFC 882/883-style: a single tree in which all zones and the cache
 * are mixed together.
 *
D 11
 * We have nodes and we have RRs.  A node represents a domain name
 * (label and all of its parents), RRs are attached to nodes.  A key
 * distinction between data from zones and the cache is that zones
 * give us nodes, whereas the cache deals with RRs.  Although zone
 * data (master files or AXFR) are given as RRs, we immediately assemble
 * them into nodes and keep these nodes intact thereafter, hence a
 * zone always stays intact: an outgoing AXFR will always give a
 * faithful copy of the zone even if it extends past the bottom cut
 * points.  OTOH, with caching we get individual RRs, we create nodes
 * for them as needed, and we delete these nodes when the cached RRs expire.
E 11
I 11
 * This key FalconDNS data structure is called the active domain data
 * tree (ADDT).  It stores all of our authoritative data, and the
 * operation of our FSR revolves around the ADDT as well.
E 11
 *
 *	%W% (IFCTF) %E%
 */

#ifndef	__TREE_H
#define	__TREE_H

I 2
D 6
struct nodechildren {
D 5
	int	nch_count;
E 5
I 5
	/* int	nch_count; */
E 5
D 4
	int	nch_hashsize;
	struct	node **nch_hash;
E 4
I 4
	struct	hashtable *nch_hash;
E 4
};

E 6
E 2
struct node {
	/* info intrinsic to the node itself */
	u_char	n_labellen;
D 5
	u_char	n_label_uc[MAXLABEL];	/* uppercase */
E 5
	u_char	n_label_cp[MAXLABEL];	/* case-preserving */
I 5
	u_char	n_label_uc[MAXLABEL];	/* uppercase */
E 5
	/* simple links */
I 9
	u_char	n_unlinked;
E 9
I 2
	struct	class *n_class;
E 2
	struct	node *n_parent;
	struct	node *n_nextsib;	/* in whatever chain our parent has */
					/* used to link to us */
	struct	node **n_backptr;	/* whichever link points to us */
	/* RRs attached to this node */
	struct	soa *n_soa;		/* SOA only from zone */
D 3
	struct	rrhdr *n_rrzone;	/* RRs from zone */
E 3
I 3
D 7
	struct	rr *n_rrzone;		/* RRs from zone */
E 3
	int	n_rrzone_nscount;	/* how many NS records in the above */
D 3
	struct	rrhdr *n_rrcache;	/* cached RRs */
E 3
I 3
	struct	rr *n_rrcache;		/* cached RRs */
E 3
	int	n_rrcache_nscount;	/* how many NS records in the above */
E 7
I 7
	struct	ns_rrset *n_ns;		/* see nsrec.h */
	struct	rr *n_rrzone;		/* RRs from zone (not NS or SOA) */
D 11
	struct	rr *n_rrcache;		/* cached RRs (ditto) */
E 11
I 11
	struct	rescache *n_cached_ans;
	struct	rr *n_cached_cname;
	struct	rescache *n_cached_nxdom;
E 11
E 7
	/* child nodes within the zone */
D 2
	int	n_zonech_count;
	int	n_zonech_hashsize;
	struct	node **n_zonech_hash;
E 2
I 2
D 6
	struct	nodechildren n_zonech;
E 6
I 6
	struct	hashtable *n_zonech;
E 6
E 2
	struct	node *n_zonech_wild;
	/* child nodes not from within the zone */
D 2
	int	n_nzch_count;
	int	n_nzch_hashsize;
	struct	node **n_nzch_hash;
E 2
I 2
D 6
	struct	nodechildren n_nzch;
E 6
I 6
	struct	hashtable *n_nzch;
E 6
E 2
	/* our private management info */
	struct	zone *n_zone;	/* is there a zone attached to this node? */
I 8
	struct	node *n_zonehead;
D 9
	struct	node *n_nextinzone;	/* used for AXFR out */
E 8
	int	n_refcount;	/* normally 1, incremented for AXFR out */
E 9
I 9
D 11
	struct	node *n_nextmisc;  /* overlayed n_nextinzone & n_nextincache */
E 11
I 11
	struct	node *n_nextinzone;
	struct	node *n_nextincache;
E 11
	struct	node **n_cache_backptr;
	int	n_refcount;	/* normally 1, incremented for held pointers */
E 9
};
I 9

D 11
#define	n_nextinzone	n_nextmisc
#define	n_nextincache	n_nextmisc
E 9

E 11
/*
I 4
 * The black magic of dynamically expanding hash tables which
 * provide the branching glue between tree nodes.
 */
struct hashtable {
	struct	node *h_chains[16];
	struct	hashtable *h_subtables[16];
};

/*
E 4
D 11
 * Each node has two sets of RRs attached from it: one from zone, one
 * from caching activities.  Among other things, this separation makes
 * it easier to handle the TTL difference (static TTL value for data from
 * zones, an expiration time_t for cached RRs).
D 7
 * RRs within each group are stored unordered with two exceptions:
E 7
I 7
 * RRs within each group are stored unordered with the exception
 * of NS and SOA which use different structures altogether.
E 11
I 11
 * We have two sets of links to child nodes: one for in-zone nodes
 * and one for other nodes.  The non-zone children take precedence.
 * At first that will seem counter-logical, but consider the case when
 * we are authoritative for two adjoining zones: in that case the
 * non-zone child will be the child zone, whereas the in-zone child
 * will be the glue record.  The child zone should take precedence.
E 11
E 7
 *
D 7
 * - NS records come before all other types, and there is a special
 *   field which counts them.  That field allows us to tell right away
 *   if any are present.
 * - The SOA is stored separately and its special unique nature is
 *   enforced.  We do not cache SOA records even though RFC 1034/1035
 *   allow us to (RFC 882/883 didn't).  We abstain from caching them
 *   for simplicity of implementation rather than veneration of RFC 882/883.
 *
 * RRs from zone take precedence.  Normally if a node falls within a zone,
 * we won't accept any non-authoritative RRs for it, but if a node defines
 * a zone bottom cut, we technically aren't authoritative for it, so we
 * accept cached RRs in that case.  That's a special case in which NS
 * records from a zone and cached RRs can appear on the same node.
E 7
I 7
D 11
 * The only nodes that can have both from-zone and cached RRs on them
 * (on n_rrzone and n_rrcache chains, respectively) are those nodes
 * which have initially been created from loading a zone, but which lie
 * below a delegation point (bottom cut).  We aren't authoritative
 * for these nodes, hence we need to accept cached RRs, but we don't
 * want to lose the glue records in the process or mess with them
 * in any way, hence the two separate linked lists.
E 7
 */

/*
 * We similarly have two sets of links to child nodes: one for in-zone nodes
 * and one for other nodes.  However, the precedence is the opposite of
 * that for RRs: the non-zone children take precedence.  At first that
 * will seem counter-logical, but consider the case when we are authoritative
 * for two adjoining zones: in that case the non-zone child will be the
 * child zone, whereas the in-zone child will be the glue record.  The
 * child zone should take precedence.  The cache mechanism won't be allowed
 * to create child nodes under a zone node unless they fall below a bottom
 * cut point.
E 11
I 11
 * The case of adjoining or overlapping zones is the only one in which
 * a given subdomain label can appear in both in-zone and non-zone
 * child hash tables, and is the sole reason for the present complexity.
 *
 * The cache mechanism won't be allowed to create child nodes under a
 * zonal node unless they fall below a bottom cut point, and it will
 * traverse down the in-zone child links when they exist before creating
 * new nodes.
E 11
 */
I 4

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
I 10
	struct	hashtable *ht;
E 10
	int	nlevels;
D 10
	struct	node **chain;
E 10
I 10
	int	idx;
E 10
	int	chainlen;
};
E 4

#endif	/* include guard */
E 1
