/*
 * In-memory representation of RRs
 *
 *	@(#)rr.h	1.6 (IFCTF) 2013/01/11
 *
 * In this version of FalconDNS we are going to take a bold departure
 * from our original design, and allow the use of struct rr internal
 * representation for *all* RR types, including SOA/NS contained in
 * cached answers, and totally unknown RR types a la RFC 3597.
 *
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
 */

#ifndef	__RR_H
#define	__RR_H

#include "dname.h"

/*
 * The following struct rr is the beginning of a malloced chunk.
 * It is always followed by type-dependent variable-length stuff.
 */
struct rr {
	struct	rr *rr_next;
	u_short	rr_type;
	u_short	rr_class;
	union	rr_ttlu {
		u_long	rru_ttl;	/* for RRs from zones */
		time_t	rru_expire;	/* for cached RRs */
	}	rr_ttlu;
	u_short	rr_miscshort;
	u_short	rr_flags;
};
#define	rr_ttl		rr_ttlu.rru_ttl
#define	rr_expire	rr_ttlu.rru_expire
#define	rr_length	rr_miscshort
#define	rr_mxpref	rr_miscshort

/* rr_flags definitions */
#define	RR_CACHED	0x8000

/*
 * The variable-length stuff that follows struct rr in the same
 * malloced chunk:
 *
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
 */

/*
 * MINFO and RP are stored as follows:
 * struct rr
 * struct minfo
 * struct dname
 * struct dname
 */
struct minfo {
	struct	dname *minfo_dn1;
	struct	dname *minfo_dn2;
};

/*
 * SOA records are a mess: we have several different structs for
 * storing them in different contexts.  The following struct soa
 * is used only for our own authoritative zones, at the zone-head node.
 *
 * The malloced chunk begins with struct soa and is followed by two dnames.
 */
struct soa {
	struct	dname *soa_mname;
	struct	dname *soa_rname;
	/* the following numbers are in the local machine byte order */
	u_long	soa_serial;
	u_long	soa_refresh;
	u_long	soa_retry;
	u_long	soa_expire;
	u_long	soa_minimum;
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
};

#endif	/* include guard */
