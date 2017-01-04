h24134
s 00055/00018/00501
d D 1.11 2013/01/11 23:02:50 msokolov 11 10
c first round of changes for the new FSR cache design
e
s 00002/00002/00517
d D 1.10 2013/01/06 08:30:38 msokolov 10 9
c preparations for librification:
c s/store_label_casepreserve/copy_label_casepreserve/
c s/store_label_can/copy_label_can/
e
s 00001/00001/00518
d D 1.9 2013/01/06 07:03:59 msokolov 9 8
c MSDNS => FalconDNS
e
s 00050/00006/00469
d D 1.8 2011/12/24 04:31:17 msokolov 8 7
c emit_dname_into_msg_newtype() fully implemented
e
s 00057/00000/00418
d D 1.7 2011/12/23 08:10:36 msokolov 7 6
c preliminary handling of some new post-RFC1035 RR types
c abstention from compression per RFC 3597 remains to be implemented
e
s 00071/00000/00347
d D 1.6 2011/12/03 07:39:19 msokolov 6 5
c emit_parsedrr_into_msg() implemented
e
s 00042/00000/00305
d D 1.5 2011/11/01 08:59:42 msokolov 5 4
c implemented A additional data return for referrals
e
s 00003/00029/00302
d D 1.4 2011/11/01 05:54:43 msokolov 4 3
c safer and more sensible handling of RR owner names
e
s 00008/00006/00323
d D 1.3 2011/10/31 08:44:02 msokolov 3 2
c minimum TTL logic added
e
s 00182/00000/00147
d D 1.2 2011/10/29 07:48:13 msokolov 2 1
c RR output implemented
e
s 00147/00000/00000
d D 1.1 2011/10/29 05:48:22 msokolov 1 0
c started
e
u
U
t
T
I 1
/*
D 9
 * Michael Sokolov's Domain Name Server (MSDNS)
E 9
I 9
 * FalconDNS daemon by Michael Spacefalcon
E 9
 *
 * Query response writer functions: the black magic of emitting RRs
 * from internal to external representation, handling domain-name
 * compression and message length limit guards.
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 3
#include <sys/types.h>
E 3
I 3
#include <sys/param.h>
E 3
#include <netinet/in.h>
#include <arpa/nameser.h>
I 2
#include <syslog.h>
#include "class.h"
E 2
#include "dname.h"
#include "tree.h"
#include "nsrec.h"
#include "query.h"
I 4
#include "zone.h"
E 4
I 2
#include "globals.h"
I 6
#include "msgparse.h"
E 6
E 2

extern int label_match(), label_match_casesen();
extern struct compress_node *get_compress_node();

/*
 * This function emits a given dname into the response message
 * being built in the given struct query, starting at q->q_msgptr
 * and advancing that pointer accordingly.  The compression tree
 * is made use of and updated accordingly.
 *
 * Return value:
 *   0 = success
 *  -1 = ran into q->q_msg_endstop
 */
emit_dname_into_msg(q, dn)
	struct query *q;
	register struct dname *dn;
{
	register struct compress_node *cn, **addp;
	struct compress_node *old;
	register int depth, i;
	int (*matchfunc)();
	int size;
	u_char *new_labels[127];

	/* First we need to weed out the root dname */
	if (q->q_msgptr >= q->q_msg_endstop)
		return(-1);
	if (!dn->dn_nlabels) {
		*q->q_msgptr++ = 0;
		return(0);
	}
	/*
	 * The real work starts here.
	 *
	 * We begin by determining how much of the tail we can
	 * compress away, i.e., how much of the existing compression
	 * tree can be made use of.
	 *
	 * This is where the case-sensitive vs. case-insensitive
	 * compression matters.
	 */
	if (q->q_flags & QFLAGS_COMPRESS_CASESEN)
		matchfunc = label_match_casesen;
	else
		matchfunc = label_match;
	addp = &q->q_first_cnode;
	old = 0;
	for (depth = dn->dn_nlabels; --depth >= 0; ) {
		for (cn = *addp; cn; addp = &cn->cn_nextsib, cn = *addp)
			if (matchfunc(cn->cn_label, dn->dn_labels[depth]))
				break;
		if (!cn)
			break;
		old = cn;
		addp = &cn->cn_firstchild;
	}
	/*
	 * At this point if depth is negative (-1), it means that the
	 * entire dname of interest is already in the compression tree
	 * and old points to the node of interest.
	 *
	 * If (depth >= 0), it means that dn_labels[depth] is the
	 * rightmost label that needs to be emitted new, old points
	 * to the reusable part (if old is null, then dn_labels[depth]
	 * is the TLD), and addp is the pointer through which the
	 * first newly allocated compression node should be linked.
	 *
	 * Now we need to compute the size which the newly emitted
	 * compressed dname will take up.
	 */
	if (old) {
		size = 2;	/* final pointer */
		for (i = 0; i <= depth; i++)
			size += *dn->dn_labels[i] + 1;
	} else
		size = dn->dn_stringlen;
	/* Is there room for it in the response message? */
	if (q->q_msg_endstop - q->q_msgptr < size)
		return(-1);
	/*
	 * Write out the new stuff, saving label pointers
	 * in a stack-allocated array for later storage
	 * in compression tree nodes.
	 */
	for (i = 0; i <= depth; i++) {
		new_labels[i] = q->q_msgptr;
D 10
		store_label_casepreserve(dn->dn_labels[i], q->q_msgptr);
E 10
I 10
		copy_label_casepreserve(dn->dn_labels[i], q->q_msgptr);
E 10
		q->q_msgptr += *new_labels[i] + 1;
	}
	if (old) {
		i = old->cn_label - q->q_msg;
		*q->q_msgptr++ = INDIR_MASK | (i >> 8);
		*q->q_msgptr++ = i;
	} else
		*q->q_msgptr++ = 0;
	/*
	 * The message output is done.  All we have left to do is
	 * to add the newly emitted labels to the compression tree
	 * so they can be used as future pointer targets.
	 *
	 * The beginning of the rightmost of our newly emitted labels
	 * needs to be within the 16384 octet window in order for us
	 * to be able to add any new compression tree nodes: each
	 * node is guaranteed to be usable as a pointer without
	 * further checking, and storing nodes that aren't usable
	 * as such would only be a waste of memory.  If our rightmost
	 * newly emitted label is past the mark, we simply return here.
	 *
	 * Failure to allocate new compression tree nodes is similarly
	 * non-fatal.
	 */
	if (depth < 0)
		return(0);
	if (new_labels[depth] > q->q_msg + 16383)
		return(0);
	for (i = depth; i >= 0; i--) {
		cn = get_compress_node(q);
		if (!cn)
			return(0);
		cn->cn_label = new_labels[i];
		cn->cn_nextsib = 0;
		cn->cn_firstchild = 0;
		*addp = cn;
		addp = &cn->cn_firstchild;
	}
I 2
	return(0);
}

I 7
/*
 * RFC 3597 prohibits compression for <domain-name>s appearing in RDATA
D 11
 * of post-RFC1035 RR types.  MSDNS offers the compress-new-RR-types
E 11
I 11
 * of post-RFC1035 RR types.  FalconDNS offers the compress-new-RR-types
E 11
 * configuration option, giving the choice of following the rules or
 * compressing anyway.  The per-type dispatchers in emit_genrr_into_msg()
 * and emit_parsedrr_into_msg() call emit_dname_into_msg_newtype()
 * instead of the regular emit_dname_into_msg() for RDATA of post-RFC1035
 * RR types.  If compress-new-RR-types has been set to true, we simply
 * call the good old emit_dname_into_msg().  Otherwise we have to emit
 * the dname without back-pointers, but we still would like to record
 * any new potential targets for future compression.
D 8
 *
 * The logic remains to be implemented, for now we just call the old
 * compress-always code.
E 8
 */
emit_dname_into_msg_newtype(q, dn)
D 8
	struct query *q;
	struct dname *dn;
E 8
I 8
	register struct query *q;
	register struct dname *dn;
E 8
{
D 8
	return(emit_dname_into_msg(q, dn));
E 8
I 8
	register struct compress_node *cn, **addp;
	register int i;
	register int (*matchfunc)();
	u_char *new_labels[127];

	if (compress_new_types)
		return(emit_dname_into_msg(q, dn));
	/* emit the dname at hand without back-pointers */
	if (q->q_msg_endstop - q->q_msgptr < dn->dn_stringlen)
		return(-1);
	for (i = 0; i < dn->dn_nlabels; i++) {
		new_labels[i] = q->q_msgptr;
D 10
		store_label_casepreserve(dn->dn_labels[i], q->q_msgptr);
E 10
I 10
		copy_label_casepreserve(dn->dn_labels[i], q->q_msgptr);
E 10
		q->q_msgptr += *new_labels[i] + 1;
	}
	*q->q_msgptr++ = 0;
	/*
	 * Message output done, now try to save the pointers
	 * for future reuse.
	 */
	if (q->q_flags & QFLAGS_COMPRESS_CASESEN)
		matchfunc = label_match_casesen;
	else
		matchfunc = label_match;
	addp = &q->q_first_cnode;
	for (i = dn->dn_nlabels; --i >= 0; ) {
		for (cn = *addp; cn; addp = &cn->cn_nextsib, cn = *addp)
			if (matchfunc(cn->cn_label, dn->dn_labels[i]))
				break;
		if (!cn)
			break;
		addp = &cn->cn_firstchild;
	}
	if (i < 0)
		return(0);
	if (new_labels[i] > q->q_msg + 16383)
		return(0);
	for (; i >= 0; i--) {
		cn = get_compress_node(q);
		if (!cn)
			return(0);
		cn->cn_label = new_labels[i];
		cn->cn_nextsib = 0;
		cn->cn_firstchild = 0;
		*addp = cn;
		addp = &cn->cn_firstchild;
	}
	return(0);
E 8
}

E 7
D 4
void
get_rr_owner_dname(q, n, wild, dn)
	register struct query *q;
	register struct node *n;
	int wild;
	register struct dname *dn;
{
	struct query_stage *qs = &q->q_stages[q->q_curstage];
	register int d;

	dn->dn_stringlen = 0;
	for (d = 0; d < wild; d++) {
		dn->dn_labels[d] = qs->qs_qname.dn_labels[d];
		dn->dn_stringlen += dn->dn_labels[d][0] + 1;
	}
	if (wild)
		n = n->n_parent;
	for (; n; n = n->n_parent) {
		dn->dn_labels[d] = (u_char *) n;
		dn->dn_stringlen += dn->dn_labels[d][0] + 1;
		d++;
	}
	dn->dn_nlabels = d - 1;
}

E 4
emit_soa_into_msg(q, n)
	register struct query *q;
	struct node *n;
{
	u_char *saveptr, *fixptr, *dataptr;
D 4
	struct dname owner;
E 4
	struct rrfixed fix;
	register struct soa *soa;
	u_long longs[5];

	saveptr = q->q_msgptr;
D 4
	get_rr_owner_dname(q, n, 0, &owner);
	if (emit_dname_into_msg(q, &owner) < 0)
E 4
I 4
	if (emit_dname_into_msg(q, n->n_zone->z_dname) < 0)
E 4
		return(-1);
	if (q->q_msg_endstop - q->q_msgptr < RRFIXEDSZ) {
err:		q->q_msgptr = saveptr;
		return(-1);
	}
	fixptr = q->q_msgptr;
	q->q_msgptr += RRFIXEDSZ;
	dataptr = q->q_msgptr;
	soa = n->n_soa;
	if (emit_dname_into_msg(q, soa->soa_mname) < 0)
		goto err;
	if (emit_dname_into_msg(q, soa->soa_rname) < 0)
		goto err;
	if (q->q_msg_endstop - q->q_msgptr < 20)
		goto err;
	longs[0] = htonl(soa->soa_serial);
	longs[1] = htonl(soa->soa_refresh);
	longs[2] = htonl(soa->soa_retry);
	longs[3] = htonl(soa->soa_expire);
	longs[4] = htonl(soa->soa_minimum);
	bcopy(longs, q->q_msgptr, 20);
	q->q_msgptr += 20;
	fix.type = htons(T_SOA);
	fix.class = htons(q->q_class->c_class);
	fix.ttl = longs[4];
	fix.rdlength = htons(q->q_msgptr - dataptr);
	bcopy(&fix, fixptr, RRFIXEDSZ);
	return(0);
}

D 3
emit_ns_rrset_into_msg(q, n)
E 3
I 3
emit_ns_rrset_into_msg(q, n, minttl)
E 3
	register struct query *q;
	struct node *n;
I 3
	u_long minttl;
E 3
{
	u_char *saveptr, *fixptr, *dataptr;
	struct dname owner;
	struct rrfixed fix;
	register struct ns_rrset *ns = n->n_ns;
	register struct nsrr *nsrr;

	saveptr = q->q_msgptr;
D 4
	get_rr_owner_dname(q, n, 0, &owner);
E 4
I 4
	dname_of_node(n, &owner);
E 4
	fix.type = htons(T_NS);
	fix.class = htons(q->q_class->c_class);
	switch (ns->ns_type) {
	case NSTYPE_ZONEHEAD:
	case NSTYPE_DELEGATION:
D 3
		fix.ttl = htonl(ns->ns_ttl);
E 3
I 3
		fix.ttl = htonl(MAX(ns->ns_ttl, minttl));
E 3
		break;
	case NSTYPE_ANCHOR:
	case NSTYPE_CACHEDREF:
		fix.ttl = htonl(ns->ns_expire - current_time);
	}
	for (nsrr = ns->ns_chain; nsrr; nsrr = nsrr->nsrr_next) {
		if (emit_dname_into_msg(q, &owner) < 0) {
err:			q->q_msgptr = saveptr;
			return(-1);
		}
		if (q->q_msg_endstop - q->q_msgptr < RRFIXEDSZ)
			goto err;
		fixptr = q->q_msgptr;
		q->q_msgptr += RRFIXEDSZ;
		dataptr = q->q_msgptr;
		if (emit_dname_into_msg(q, (struct dname *)(nsrr + 1)) < 0)
			goto err;
		fix.rdlength = htons(q->q_msgptr - dataptr);
		bcopy(&fix, fixptr, RRFIXEDSZ);
	}
	return(0);
}

D 3
emit_genrr_into_msg(q, owner, rr)
E 3
I 3
emit_genrr_into_msg(q, owner, rr, minttl)
E 3
	register struct query *q;
	struct dname *owner;
	register struct rr *rr;
I 3
	u_long minttl;
E 3
{
	u_char *saveptr, *fixptr, *dataptr;
	struct rrfixed fix;
	struct minfo *minfo;
I 11
	struct cachedsoa *soa;
E 11

	saveptr = q->q_msgptr;
	if (emit_dname_into_msg(q, owner) < 0)
		return(-1);
	if (q->q_msg_endstop - q->q_msgptr < RRFIXEDSZ) {
err:		q->q_msgptr = saveptr;
		return(-1);
	}
	fixptr = q->q_msgptr;
	q->q_msgptr += RRFIXEDSZ;
	dataptr = q->q_msgptr;
	fix.type = htons(rr->rr_type);
	fix.class = htons(rr->rr_class);
	if (rr->rr_flags & RR_CACHED)
		fix.ttl = htonl(rr->rr_expire - current_time);
	else
D 3
		fix.ttl = htonl(rr->rr_ttl);
E 3
I 3
		fix.ttl = htonl(MAX(rr->rr_ttl, minttl));
E 3
	switch (rr->rr_type) {
D 11
	case T_A:
I 7
	case T_AAAA:
E 7
	case T_HINFO:
I 7
	case T_ISDN:
E 7
	case T_TXT:
	case T_WKS:
I 7
	case T_X25:
E 7
		/* unparsed RDATA */
		if (q->q_msg_endstop - q->q_msgptr < rr->rr_length)
			goto err;
		bcopy(rr + 1, q->q_msgptr, rr->rr_length);
		q->q_msgptr += rr->rr_length;
		break;
E 11
	case T_CNAME:
	case T_MB:
I 11
	case T_MD:
	case T_MF:
E 11
	case T_MG:
	case T_MR:
I 11
	case T_NS:
E 11
	case T_PTR:
		/* single domain-name */
		if (emit_dname_into_msg(q, (struct dname *)(rr + 1)) < 0)
			goto err;
		break;
	case T_MINFO:
		minfo = (struct minfo *)(rr + 1);
		if (emit_dname_into_msg(q, minfo->minfo_dn1) < 0)
			goto err;
		if (emit_dname_into_msg(q, minfo->minfo_dn2) < 0)
			goto err;
		break;
	case T_MX:
		if (q->q_msg_endstop - q->q_msgptr < 2)
			goto err;
		PUTSHORT(rr->rr_mxpref, q->q_msgptr);
		if (emit_dname_into_msg(q, (struct dname *)(rr + 1)) < 0)
			goto err;
		break;
I 11
	case T_SOA:
		soa = (struct cachedsoa *)(rr + 1);
		if (emit_dname_into_msg(q, soa->csoa_mname) < 0)
			goto err;
		if (emit_dname_into_msg(q, soa->csoa_rname) < 0)
			goto err;
		if (q->q_msg_endstop - q->q_msgptr < 20)
			goto err;
		bcopy(soa->csoa_numbers, q->q_msgptr, 20);
		q->q_msgptr += 20;
		break;
E 11
I 7
	/* post-RFC1035 RR types with <domain-name>s in RDATA */
	case T_AFSDB:
	case T_RT:
		if (q->q_msg_endstop - q->q_msgptr < 2)
			goto err;
		PUTSHORT(rr->rr_mxpref, q->q_msgptr);
		if (emit_dname_into_msg_newtype(q, (struct dname *)(rr+1)) < 0)
			goto err;
		break;
	case T_RP:
		minfo = (struct minfo *)(rr + 1);
		if (emit_dname_into_msg_newtype(q, minfo->minfo_dn1) < 0)
			goto err;
		if (emit_dname_into_msg_newtype(q, minfo->minfo_dn2) < 0)
			goto err;
		break;
E 7
	default:
D 11
		syslog(LOG_CRIT,
D 3
			"BUG: unexpected RR type %d in emit_genrr_into_msg",
E 3
I 3
			"BUG: unexpected RR type %d in emit_genrr_into_msg()",
E 3
			rr->rr_type);
		abort();
E 11
I 11
		/* unparsed RDATA */
		if (q->q_msg_endstop - q->q_msgptr < rr->rr_length)
			goto err;
		bcopy(rr + 1, q->q_msgptr, rr->rr_length);
		q->q_msgptr += rr->rr_length;
E 11
	}
	fix.rdlength = htons(q->q_msgptr - dataptr);
	bcopy(&fix, fixptr, RRFIXEDSZ);
I 6
	return(0);
}

emit_parsedrr_into_msg(q, rr)
	register struct query *q;
	register struct parsedrr *rr;
{
	u_char *saveptr, *fixptr, *dataptr;
	struct rrfixed fixout;

	saveptr = q->q_msgptr;
	if (emit_dname_into_msg(q, &rr->prr_owner) < 0)
		return(-1);
	if (q->q_msg_endstop - q->q_msgptr < RRFIXEDSZ) {
err:		q->q_msgptr = saveptr;
		return(-1);
	}
	fixptr = q->q_msgptr;
	q->q_msgptr += RRFIXEDSZ;
	dataptr = q->q_msgptr;
	fixout.type = htons(rr->prr_fix.type);
	fixout.class = htons(rr->prr_fix.class);
	fixout.ttl = htonl(rr->prr_fix.ttl);
	switch (rr->prr_fix.type) {
	case T_CNAME:
	case T_MB:
	case T_MD:
	case T_MF:
	case T_MG:
	case T_MR:
	case T_NS:
	case T_PTR:
		/* single domain-name */
		if (emit_dname_into_msg(q, &rr->prr_rdata_dn[0]) < 0)
			goto err;
		break;
	case T_MINFO:
		if (emit_dname_into_msg(q, &rr->prr_rdata_dn[0]) < 0)
			goto err;
		if (emit_dname_into_msg(q, &rr->prr_rdata_dn[1]) < 0)
			goto err;
		break;
	case T_MX:
		if (q->q_msg_endstop - q->q_msgptr < 2)
			goto err;
		*q->q_msgptr++ = rr->prr_rdata[0];
		*q->q_msgptr++ = rr->prr_rdata[1];
		if (emit_dname_into_msg(q, &rr->prr_rdata_dn[0]) < 0)
			goto err;
		break;
	case T_SOA:
		if (emit_dname_into_msg(q, &rr->prr_rdata_dn[0]) < 0)
			goto err;
		if (emit_dname_into_msg(q, &rr->prr_rdata_dn[1]) < 0)
			goto err;
		if (q->q_msg_endstop - q->q_msgptr < 20)
			goto err;
		bcopy(rr->prr_rdata_misc, q->q_msgptr, 20);
		q->q_msgptr += 20;
I 7
		break;
	/* post-RFC1035 RR types with <domain-name>s in RDATA */
	case T_AFSDB:
	case T_RT:
		if (q->q_msg_endstop - q->q_msgptr < 2)
			goto err;
		*q->q_msgptr++ = rr->prr_rdata[0];
		*q->q_msgptr++ = rr->prr_rdata[1];
		if (emit_dname_into_msg_newtype(q, &rr->prr_rdata_dn[0]) < 0)
			goto err;
		break;
	case T_RP:
		if (emit_dname_into_msg_newtype(q, &rr->prr_rdata_dn[0]) < 0)
			goto err;
		if (emit_dname_into_msg_newtype(q, &rr->prr_rdata_dn[1]) < 0)
			goto err;
E 7
		break;
	default:
		/* unparsed RDATA */
		if (q->q_msg_endstop - q->q_msgptr < rr->prr_fix.rdlength)
			goto err;
		bcopy(rr->prr_rdata, q->q_msgptr, rr->prr_fix.rdlength);
		q->q_msgptr += rr->prr_fix.rdlength;
		break;
	}
	fixout.rdlength = htons(q->q_msgptr - dataptr);
	bcopy(&fixout, fixptr, RRFIXEDSZ);
I 11
	return(0);
}

emit_ncache_soa_into_msg(q, rc)
	register struct query *q;
	struct rescache *rc;
{
	register struct ncache *soa = (struct ncache *)(rc + 1);
	u_char *saveptr, *fixptr, *dataptr;
	struct rrfixed fix;

	saveptr = q->q_msgptr;
	if (emit_dname_into_msg(q, soa->nsoa_owner) < 0)
		return(-1);
	if (q->q_msg_endstop - q->q_msgptr < RRFIXEDSZ) {
err:		q->q_msgptr = saveptr;
		return(-1);
	}
	fixptr = q->q_msgptr;
	q->q_msgptr += RRFIXEDSZ;
	dataptr = q->q_msgptr;
	if (emit_dname_into_msg(q, soa->nsoa_mname) < 0)
		goto err;
	if (emit_dname_into_msg(q, soa->nsoa_rname) < 0)
		goto err;
	if (q->q_msg_endstop - q->q_msgptr < 20)
		goto err;
	bcopy(soa->nsoa_numbers, q->q_msgptr, 20);
	q->q_msgptr += 20;
	fix.type = htons(T_SOA);
	fix.class = htons(q->q_class->c_class);
	fix.ttl = htonl(rc->rc_expire - current_time);
	fix.rdlength = htons(q->q_msgptr - dataptr);
	bcopy(&fix, fixptr, RRFIXEDSZ);
E 11
E 6
E 2
	return(0);
}
I 5

emit_ns_add_into_msg(q, n)
	register struct query *q;
	struct node *n;
{
	u_char *saveptr;
	struct rrfixed fix;
	register struct nsrr *ns;
	HEADER *hdr = (HEADER *)q->q_msg;
	register int i, count = 0;
	int savecnt;

	fix.type = htons(T_A);
	fix.class = htons(C_IN);
	fix.rdlength = htons(4);
	for (ns = n->n_ns->ns_chain; ns; ns = ns->nsrr_next) {
		if (!ns->nsrr_addrcnt || current_time >= ns->nsrr_A_expire)
			continue;
		fix.ttl = htonl(ns->nsrr_A_expire - current_time);
		saveptr = q->q_msgptr;
		savecnt = count;
		for (i = 0; i < ns->nsrr_addrcnt; i++) {
			if (emit_dname_into_msg(q, (struct dname *)(ns+1)) < 0){
				q->q_msgptr = saveptr;
				count = savecnt;
				break;
			}
			if (q->q_msg_endstop - q->q_msgptr < RRFIXEDSZ + 4) {
				q->q_msgptr = saveptr;
				count = savecnt;
				break;
			}
			bcopy(&fix, q->q_msgptr, RRFIXEDSZ);
			q->q_msgptr += RRFIXEDSZ;
			bcopy(&ns->nsrr_addrs[i], q->q_msgptr, 4);
			q->q_msgptr += 4;
			count++;
		}
	}
	hdr->arcount = count;
	return(count);
}
E 5
E 1
