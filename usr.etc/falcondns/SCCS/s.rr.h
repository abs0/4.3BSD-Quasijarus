h38995
s 00093/00035/00059
d D 1.6 2013/01/11 23:02:40 msokolov 6 5
c first round of changes for the new FSR cache design
e
s 00003/00014/00091
d D 1.5 2011/09/12 04:26:01 msokolov 5 4
c NS record handling revamped into RRset model
e
s 00001/00001/00104
d D 1.4 2011/07/15 21:47:39 msokolov 4 3
c don't use struct in_addr to avoid dependency on <netinet/in.h>
e
s 00034/00013/00071
d D 1.3 2011/07/15 08:55:37 msokolov 3 2
c more thought
e
s 00023/00011/00061
d D 1.2 2011/07/14 04:23:13 msokolov 2 1
c reworking structures for zone loading
e
s 00072/00000/00000
d D 1.1 11/07/11 08:04:07 msokolov 1 0
c MSDNS project started, template compiles
e
u
U
t
T
I 1
/*
 * In-memory representation of RRs
 *
D 6
 * Each RR is stored in a single malloced chunk.  Because it's a
 * variable-length deal, no simple C struct representation is possible.
D 2
 * Each RR except SOA begins with struct rrhdr which is immediately
E 2
I 2
D 5
 * Each RR except SOA begins with struct rr which is immediately
E 5
I 5
 * Each RR except NS and SOA begins with struct rr which is immediately
E 5
E 2
 * followed by type-dependent additions, usually struct dname.
E 6
I 6
 *	%W% (IFCTF) %E%
E 6
D 2
 * The current implementation strategy is that unknown RR types aren't
 * stored in memory, i.e., not accepted when reading text files and
 * not cached in recursive operation.
E 2
 *
I 2
D 3
 * We allow RRs whose type/class we don't understand; in fact that's
 * how we handle types like HINFO, TXT, WKS etc which we know but
 * have no need to parse.  Basically if it doesn't contain domain-names,
 * we don't need to parse it.  If it's an unparsed type, the rr_length
 * field is valid and the data immediately follows the struct in the
 * malloced chunk.  If it's a simple domain-name RR, struct dname
 * directly follows struct rr.  A few types are handled specially.
E 3
I 3
D 6
 * We have considered allowing RRs whose type/class we don't understand:
 * if an RR doesn't contain domain names, we can just store it and
 * regurgitate it without having to know what it means.  However, the
 * ultimate deciding factor against allowing unknown RRs is the issue
 * of duplicate resolution: what are the semantics of having more than
 * one RR of a given type at a given node?  Besides, there are probably
 * a bunch of new RR types we don't know about which contain domain names
 * and which we may receive in compressed form; storing them unparsed
 * and then regurgitating garbage would be a worse embarrassment than
 * simply dropping them.
E 6
I 6
 * In this version of FalconDNS we are going to take a bold departure
 * from our original design, and allow the use of struct rr internal
 * representation for *all* RR types, including SOA/NS contained in
 * cached answers, and totally unknown RR types a la RFC 3597.
E 6
E 3
 *
E 2
D 6
 *	%W% (IFCTF) %E%
E 6
I 6
 * When storing data loaded from zones, the struct rr form will be
 * used just like in the first MSDNS version: to store everything except
 * NS and SOA records.  The zone-head SOA still lives in its own special
 * struct soa which isn't used for anything else.  The special NS RRset
 * structures defined in nsrec.h are still used just like before:
 * marking zone-heads, delegation points, NS-anchors and cached referrals
 * in the ADDT.  All NS RRs loaded from zones will be contained in these
 * special NS RRset structures.
 *
 * But for the FSR cache functionality, we have a new data structure
 * design.  Cached referrals will be stored just like before, using the
 * special NS RRset structures, but we are taking a very different approach
 * to caching answers.  RRs comprising cached answers will no longer be
 * stored "loose" like before; instead the basic cached entity will be
 * the complete answer block keyed on the {node, QTYPE} tuple.  Each
 * individual RR will still be held in a struct rr, and these structs
 * will be chained as usual, but it will be a second-level chain linked
 * from a higher-level chain of cached QTYPE answers.  The motivation is
 * consistency and determinism: if we are willing to pass a certain
 * response along from a foreign name server to our client on the initial
 * query, we should also be able to cache and regurgitate the exact same
 * thing.
E 6
 */

#ifndef	__RR_H
#define	__RR_H

#include "dname.h"

I 5
D 6
/* The following struct is used for all RRs except NS and SOA */

E 6
I 6
/*
 * The following struct rr is the beginning of a malloced chunk.
 * It is always followed by type-dependent variable-length stuff.
 */
E 6
E 5
D 2
struct rrhdr {
E 2
I 2
struct rr {
E 2
D 6
	struct	node *rr_node;
E 6
D 2
	struct	rrhdr *rr_next;
E 2
I 2
	struct	rr *rr_next;
E 2
	u_short	rr_type;
	u_short	rr_class;
	union	rr_ttlu {
		u_long	rru_ttl;	/* for RRs from zones */
		time_t	rru_expire;	/* for cached RRs */
	}	rr_ttlu;
I 2
D 3
	u_short	rr_length;
E 3
I 3
	u_short	rr_miscshort;
E 3
	u_short	rr_flags;
E 2
};
#define	rr_ttl		rr_ttlu.rru_ttl
#define	rr_expire	rr_ttlu.rru_expire
I 3
#define	rr_length	rr_miscshort
#define	rr_mxpref	rr_miscshort
E 3

I 2
/* rr_flags definitions */
#define	RR_CACHED	0x8000

I 3
/*
D 6
 * While we don't store totally unknown RR types, if it's a known
 * type that doesn't contain domains or anything of interest to us
 * like TXT or HINFO or WKS, we can still store it unparsed.  In
 * that case the raw RDATA immediately follows struct rr and the
 * rr_length member is valid (set to RDLENGTH).
E 6
I 6
 * The variable-length stuff that follows struct rr in the same
 * malloced chunk:
E 6
 *
D 6
 * However, if RDATA is a domain-name, we store it as a struct dname
 * instead (immediately following struct rr), and in that case
 * rr_length would be useless.  We don't use rr_length for such
 * RR types and we even reuse it to store MX preferences.
E 6
I 6
 * For types which are known to have no <domain-name>s in RDATA,
 * and unknown RR types per RFC 3597, we store the raw RDATA, and
 * set the rr_length (rr_miscshort) member to RDLENGTH.
 *
 * If RDATA is known to be a single <domain-name>, we store it as a
 * struct dname immediately following struct rr.  In this and other
 * cases where we store struct dname objects, rr_length would be useless.
 * We don't use rr_length for such RR types and we even reuse it to store
 * MX preferences.
 *
 * Some of the more difficult RR types (those that contain more than one
 * <domain-name> and/or additional material other than a leading 16-bit
 * integer like MX) are handled by putting a type-specific struct after
 * struct rr.
E 6
 */

E 3
D 6
#define	MAX_UNPARSED_RDATA	16384

E 6
E 2
/*
D 2
 * For NS records we sandwich an extra pointer between struct rrhdr and the
 * domain string.  This pointer is normally NULL, but for cached NS records it
E 2
I 2
D 5
 * For NS records we sandwich an extra pointer between struct rr and
 * struct dname.  This pointer is normally NULL, but for cached NS records it
E 2
 * may point to a chain of struct nsaddr's with the name server's addresses
 * received as additional data.
 */
struct nsaddr {
D 4
	struct	in_addr nsa_addr;
E 4
I 4
	u_long	nsa_addr;
E 4
	time_t	nsa_expire;	/* always cached, this isn't used for zones */
	struct	nsaddr *nsa_next;
};

/*
E 5
D 2
 * struct mxrec comes after struct rrhdr.  It's a struct in the same
E 2
I 2
D 3
 * struct mxrec comes after struct rr.  It's a struct in the same
E 2
 * loose sense as dname.
E 3
I 3
D 6
 * MINFO is stored as follows:
E 6
I 6
 * MINFO and RP are stored as follows:
E 6
 * struct rr
 * struct minfo
 * struct dname
 * struct dname
E 3
 */
D 3
struct mxrec {
D 2
	u_short	mx_pref;
E 2
I 2
	u_short	mx_pref;	/* network byte order */
E 2
	struct	dname mx_exch;
E 3
I 3
struct minfo {
	struct	dname *minfo_dn1;
	struct	dname *minfo_dn2;
E 3
};

/*
D 6
 * An SOA RR is stored as a single malloced chunk like other RRs, but
D 2
 * it does not begin with struct rrhdr.  (The reason for that is because
E 2
I 2
 * it does not begin with struct rr.  (The reason for that is because
E 2
 * it isn't kept in the linked list with the others, see struct node
 * definition.)  Instead the malloced chunk for an SOA begins with
 * struct soa and is followed by two dnames.
E 6
I 6
 * SOA records are a mess: we have several different structs for
 * storing them in different contexts.  The following struct soa
 * is used only for our own authoritative zones, at the zone-head node.
 *
 * The malloced chunk begins with struct soa and is followed by two dnames.
E 6
 */
struct soa {
D 5
	struct	node *soa_node;
E 5
	struct	dname *soa_mname;
	struct	dname *soa_rname;
I 6
	/* the following numbers are in the local machine byte order */
E 6
	u_long	soa_serial;
	u_long	soa_refresh;
	u_long	soa_retry;
	u_long	soa_expire;
	u_long	soa_minimum;
I 6
};

/*
 * A cached SOA (part of a cached answer block) is stored as follows:
 * struct rr
 * struct cachedsoa
 * struct dname
 * struct dname
 */
struct cachedsoa {
	struct	dname *csoa_mname;
	struct	dname *csoa_rname;
	u_char	csoa_numbers[20];	/* raw, network byte order */
};

/*
 * Each FSR cached answer (positive or negative) begins with the
 * following struct; these structs will be chained per QTYPE
 * off the ADDT node.
 *
 * For positive answers, the rc_pos member will point to the first
 * struct rr in the answer block chain.  For negative answers, the
 * rc_pos member will be NULL (that's how one knows that it's a
 * negative answer), and there will be a struct ncache following
 * immediately after struct rescache in the same malloced chunk.
 * The 3 dnames for the SOA follow afterward.
 */
struct rescache {
	time_t	rc_expire;
	int	rc_qtype;
	struct	rr *rc_pos;
	struct	rescache *rc_next;
};

struct ncache {
	struct	dname *nsoa_owner;
	struct	dname *nsoa_mname;
	struct	dname *nsoa_rname;
	u_char	nsoa_numbers[20];	/* raw, network byte order */
E 6
};

#endif	/* include guard */
E 1
