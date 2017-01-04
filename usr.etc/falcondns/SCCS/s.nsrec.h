h39244
s 00002/00001/00107
d D 1.8 2011/12/19 08:03:51 msokolov 8 7
c axed NSRR_FLAGS_BAD, preparing for caching foreign NS temp failures
e
s 00007/00002/00101
d D 1.7 2011/12/12 22:14:59 msokolov 7 6
c NS-anchor validation code written
e
s 00005/00000/00098
d D 1.6 2011/12/11 06:29:34 msokolov 6 5
c prep for NS-anchor refresh logic
e
s 00001/00000/00097
d D 1.5 2011/11/11 18:49:03 msokolov 5 4
c ns_roundrobin member added
e
s 00006/00002/00091
d D 1.4 2011/10/29 21:33:41 msokolov 4 3
c NS RR flags slight reform
e
s 00002/00000/00091
d D 1.3 2011/10/28 04:27:09 msokolov 3 2
c NS-anchor installation fully implemented
e
s 00001/00000/00090
d D 1.2 2011/09/12 06:11:52 msokolov 2 1
c need pointer to class in struct ns_anchor
e
s 00090/00000/00000
d D 1.1 2011/09/12 04:24:23 msokolov 1 0
c date and time created 2011/09/12 04:24:23 by msokolov
e
u
U
t
T
I 1
/*
 * This header file defines those MSDNS data structures
 * which are responsible for the demarcation of NS authority
 * between us and other name servers.
 *
 * The problem has turned out to be more complex than we first thought.
 *
 *	%W% (IFCTF) %E%
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
I 5
	struct	nsrr *ns_roundrobin;
E 5
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
D 4
	int	nsrr_delcandidate;
E 4
I 4
	u_short	nsrr_flags;
E 4
	/* what follows is the attached A RRset as in additional data */
I 4
	u_short	nsrr_addrcnt;
E 4
	u_long	nsrr_addrs[NS_MAX_ADDRESSES];
D 4
	int	nsrr_addrcnt;
E 4
	time_t	nsrr_A_expire;	/* for the attached A RRset, not NS! */
I 8
	/* caching temporary failures */
	time_t	nsrr_tempfail;
E 8
I 7
	/* the following last field is for NS-anchors only */
	char	*nsrr_ascii;
E 7
};
/* struct dname with the server name immediately follows struct nsrr */
I 7
/* for NS-anchors we store the ASCII version as well for syslog messages */
E 7
I 4

#define	NSRR_FLAGS_NEEDGLUE	0x8000	/* "in bailiwick" as djb says it */
D 8
#define	NSRR_FLAGS_BAD		0x4000	/* this server is unusable */
E 8
#define	NSRR_FLAGS_DELETE	0x2000	/* used in CACHEDREF updates */
E 4

/*
 * struct ns_anchor manages an NS-anchor much like struct zone
 * manages a zone.
 * It is used in the initial loading of anchor data from files
D 7
 * prior to activation in the domain tree, and it will also be used
 * for anchor refresh operations.
E 7
I 7
 * prior to activation in the domain tree, as well as for
 * refresh/validation operations.
E 7
 *
 * struct ns_anchor begins with struct ns_rrset so that the n_ns
 * pointer in struct node can dual-serve as the ns_anchor pointer.
 */

struct ns_anchor {
	struct	ns_rrset nsa_rrset;
I 2
	struct	class *nsa_class;
E 2
	struct	node *nsa_node;
	/* the following 3 variable-length entities are appended to the same */
	/* malloced chunk after the struct itself */
	char	*nsa_ascii_domname;
	struct	dname *nsa_dname;
	char	*nsa_filename;
	FILE	*nsa_fileread;
	int	nsa_fileread_lineno;
I 7
	int	nsa_ttl_limit;
E 7
I 3
	int	nsa_ttl_percent;
	int	nsa_retry_interval;
I 6
	int	nsa_warn_interval;
E 6
E 3
	struct	ns_anchor *nsa_next;
I 6
	/* validation mechanism */
	struct	timesched *nsa_val_sched;
	struct	query *nsa_val_op;
	struct	nsrr *nsa_val_server;
I 7
	u_long	nsa_val_ttl;
E 7
E 6
};

#endif	/* include guard */
E 1
