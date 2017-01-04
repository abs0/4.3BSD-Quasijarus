/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * The query-response hash table (one per class) will be used to detect
 * and suppress duplicate queries going into the work-heavy FSR and FWD
 * mechanisms, and to hold the full response cache (FRC).
 *
 *	%W% (IFCTF) %E%
 */

#ifndef	__QRHT_H
#define	__QRHT_H

/*
 * A struct qrhead will be allocated every time a QNAME is hashed and
 * inserted into the QRHT.  The struct itself has fields only for the
 * length of the QNAME binary string and for QTYPE; the actual QNAME
 * binary string will be appended at the end of the struct in the same
 * malloced chunk.  (Just the binary string is stored, no struct dname.)
 * The QCLASS is implicit, as the QRHT exists per class.
 *
 * Once a qrhead has been created, it can be used to queue duplicate
 * queries and to cache full responses (FRC).
 */

#define	QRH_NQUEUES	6
#define	QRHQ_FSR_UDP	0
#define	QRHQ_FSR_TCP	2
#define	QRHQ_FWD	4

struct qrhead {
	u_short	qrh_qname_len;	/* including the terminating NUL, like dname */
	u_short	qrh_qtype;
	struct	qrhead *qrh_nextinchain;
	struct	qrhead **qrh_chain_backptr;
	struct	qrhead *qrh_nextinfrc;
	struct	qrhead **qrh_frc_backptr;
	int	qrh_refcount;
	struct	query *qrh_queues[QRH_NQUEUES];
	struct	frc *qrh_frc;
};

/*
 * Full response cache (FRC) structure
 *
 * Every query response cached by the FRC mechanism will fall into
 * exactly one of the following two cases:
 *
 * 1. Cached positive responses:
 *    RCODE=NOERROR
 *    Answer section with one or more RRs which answer the query,
 *	i.e., not a CNAME or chain of CNAMEs for non-CNAME QTYPEs.
 *    If NS or AR sections were present in the original response,
 *	they will be stripped from the cached copy.
 *
 * 2. Cached negative responses:
 *    RCODE: either NOERROR or NXDOMAIN
 *    Answer section: either empty, or containing one or more CNAMEs
 *	which don't answer the QTYPE, i.e., which ought to trigger a
 *	new query stage.
 *    Authority section: always containing exactly one RR for this
 *	cached response type: the negative SOA.
 *    AR section: always empty
 *
 * An example of a response that does not qualify under either case
 * and thus can't be cached with the FRC mechanism: a response consisting
 * of a CNAME chain, but no final answer and no negative SOA, perhaps
 * resulting from an alias loop or a CNAME chain that exceeds our limit.
 *
 * What we actually store is a copy of the complete response message
 * starting from header octct 2 (i.e., with the XID stripped off) and
 * continuing through the last octet of the last RR, i.e., the last
 * answer RR for positive responses or the negative SOA.  The presence
 * or absence of the question echo will be whatever was emitted by
 * whichever FalconDNS instance in the forwarder chain that produced
 * the response in FSR mode - the whole point of the FRC mechanism is
 * that we don't rewrite or reshuffle these responses, and all domain-name
 * compression remains intact.
 *
 * The record counts in the header portion of each cached response
 * will be stored in the network byte order: QDCOUNT will reflect the
 * presence or absence of the question echo, ANCOUNT and NSCOUNT will be
 * set appropriately for the cached positive or negative response (in
 * particular, note that NSCOUNT will always be 0 for cached positive
 * responses, and 1 for negative ones), and ARCOUNT will always be 0.
 *
 * Regurgitation of a cached response requires only two transformations:
 * prepending of the XID for the new query we are responding to, and
 * patching the TTL fields of one or more RRs.  There will always be
 * at least one RR needing to be patched: the minimal positive response
 * has one RR in the answer section, and the minimal negative response
 * consists of the SOA in the authority section.
 *
 * TTL handling: when a query response is being considered for addition
 * to the FRC, the lowest TTL of the RRs to be included (all of the answer
 * section, and the negative SOA for NCACHE) will be computed.  If the
 * decision is made to cache, the cached entity will be tagged with a
 * single absolute expiration time for the whole thing.  Upon regurgitation,
 * the TTL fields of all RRs (answer and negative SOA) will be set to
 * whatever time remains till that overall expiration time.
 * The specific mechanism for the patching of the TTL fields remains TBD.
 *
 * The malloced chunk begins with struct frc and is immediately followed
 * by the cached blob as described above.
 */

struct frc {
	time_t	frc_expire;
	int	frc_bloblen;
	int	frc_rrcount;
	int	frc_first_patch_offset;
};

#endif	/* include guard */
