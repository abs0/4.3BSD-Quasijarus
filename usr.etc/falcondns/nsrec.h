/*
 * This header file defines those MSDNS data structures
 * which are responsible for the demarcation of NS authority
 * between us and other name servers.
 *
 * The problem has turned out to be more complex than we first thought.
 *
 *	@(#)nsrec.h	1.8 (IFCTF) 2011/12/19
 */

#ifndef	__NSREC_H
#define	__NSREC_H

#include <stdio.h>
#include "rr.h"

/*
 * NS records are handled specially.  A node has one or more NS records
 * if and only if it falls into exactly one of the following 4 categories:
 *
 * 1. top node of a zone;
 * 2. delegation point (end of zone);
 * 3. anchor installed by the local admin (usually for .);
 * 4. a cached referral from a foreign name server consulted
 *    as a result of 2 or 3 above.
 *
 * Because it has to be exactly one of the listed categories, a node
 * cannot have a mixture of NS records of different kinds.  Furthermore,
 * we have decided to implement an RFC 2181 style RRset notion
 * for NS records, even though we don't have that for general RRs yet.
 *
 * There can be only one NS RRset attached to a given tree node.  If
 * a node has a non-NULL pointer to struct ns_rrset, that node marks
 * a change in NS authority (one of the 4 types above), otherwise the
 * NS RRset pointer is NULL.
 */

struct ns_rrset {
	u_short	ns_type;
	u_short	ns_count;
	struct	nsrr *ns_chain;
	union	rr_ttlu ns_ttlu;
	struct	nsrr *ns_roundrobin;
};
#define	ns_ttl		ns_ttlu.rru_ttl
#define	ns_expire	ns_ttlu.rru_expire

#define	NSTYPE_ZONEHEAD		1
#define	NSTYPE_DELEGATION	2
#define	NSTYPE_ANCHOR		3
#define	NSTYPE_CACHEDREF	4

/* the following structs are individual NS RRs chained off the RRset */

#define	NS_MAX_ADDRESSES	4

struct nsrr {
	struct	nsrr *nsrr_next;
	u_short	nsrr_flags;
	/* what follows is the attached A RRset as in additional data */
	u_short	nsrr_addrcnt;
	u_long	nsrr_addrs[NS_MAX_ADDRESSES];
	time_t	nsrr_A_expire;	/* for the attached A RRset, not NS! */
	/* caching temporary failures */
	time_t	nsrr_tempfail;
	/* the following last field is for NS-anchors only */
	char	*nsrr_ascii;
};
/* struct dname with the server name immediately follows struct nsrr */
/* for NS-anchors we store the ASCII version as well for syslog messages */

#define	NSRR_FLAGS_NEEDGLUE	0x8000	/* "in bailiwick" as djb says it */
#define	NSRR_FLAGS_DELETE	0x2000	/* used in CACHEDREF updates */

/*
 * struct ns_anchor manages an NS-anchor much like struct zone
 * manages a zone.
 * It is used in the initial loading of anchor data from files
 * prior to activation in the domain tree, as well as for
 * refresh/validation operations.
 *
 * struct ns_anchor begins with struct ns_rrset so that the n_ns
 * pointer in struct node can dual-serve as the ns_anchor pointer.
 */

struct ns_anchor {
	struct	ns_rrset nsa_rrset;
	struct	class *nsa_class;
	struct	node *nsa_node;
	/* the following 3 variable-length entities are appended to the same */
	/* malloced chunk after the struct itself */
	char	*nsa_ascii_domname;
	struct	dname *nsa_dname;
	char	*nsa_filename;
	FILE	*nsa_fileread;
	int	nsa_fileread_lineno;
	int	nsa_ttl_limit;
	int	nsa_ttl_percent;
	int	nsa_retry_interval;
	int	nsa_warn_interval;
	struct	ns_anchor *nsa_next;
	/* validation mechanism */
	struct	timesched *nsa_val_sched;
	struct	query *nsa_val_op;
	struct	nsrr *nsa_val_server;
	u_long	nsa_val_ttl;
};

#endif	/* include guard */
