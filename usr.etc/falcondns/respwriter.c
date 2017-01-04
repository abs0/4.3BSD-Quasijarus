/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * Query response writer functions: the black magic of emitting RRs
 * from internal to external representation, handling domain-name
 * compression and message length limit guards.
 */

#ifndef lint
static char sccsid[] = "@(#)respwriter.c	1.11 (IFCTF) 2013/01/11";
#endif

#include <sys/param.h>
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "class.h"
#include "dname.h"
#include "tree.h"
#include "nsrec.h"
#include "query.h"
#include "zone.h"
#include "globals.h"
#include "msgparse.h"

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
		copy_label_casepreserve(dn->dn_labels[i], q->q_msgptr);
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
	return(0);
}

/*
 * RFC 3597 prohibits compression for <domain-name>s appearing in RDATA
 * of post-RFC1035 RR types.  FalconDNS offers the compress-new-RR-types
 * configuration option, giving the choice of following the rules or
 * compressing anyway.  The per-type dispatchers in emit_genrr_into_msg()
 * and emit_parsedrr_into_msg() call emit_dname_into_msg_newtype()
 * instead of the regular emit_dname_into_msg() for RDATA of post-RFC1035
 * RR types.  If compress-new-RR-types has been set to true, we simply
 * call the good old emit_dname_into_msg().  Otherwise we have to emit
 * the dname without back-pointers, but we still would like to record
 * any new potential targets for future compression.
 */
emit_dname_into_msg_newtype(q, dn)
	register struct query *q;
	register struct dname *dn;
{
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
		copy_label_casepreserve(dn->dn_labels[i], q->q_msgptr);
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
}

emit_soa_into_msg(q, n)
	register struct query *q;
	struct node *n;
{
	u_char *saveptr, *fixptr, *dataptr;
	struct rrfixed fix;
	register struct soa *soa;
	u_long longs[5];

	saveptr = q->q_msgptr;
	if (emit_dname_into_msg(q, n->n_zone->z_dname) < 0)
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

emit_ns_rrset_into_msg(q, n, minttl)
	register struct query *q;
	struct node *n;
	u_long minttl;
{
	u_char *saveptr, *fixptr, *dataptr;
	struct dname owner;
	struct rrfixed fix;
	register struct ns_rrset *ns = n->n_ns;
	register struct nsrr *nsrr;

	saveptr = q->q_msgptr;
	dname_of_node(n, &owner);
	fix.type = htons(T_NS);
	fix.class = htons(q->q_class->c_class);
	switch (ns->ns_type) {
	case NSTYPE_ZONEHEAD:
	case NSTYPE_DELEGATION:
		fix.ttl = htonl(MAX(ns->ns_ttl, minttl));
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

emit_genrr_into_msg(q, owner, rr, minttl)
	register struct query *q;
	struct dname *owner;
	register struct rr *rr;
	u_long minttl;
{
	u_char *saveptr, *fixptr, *dataptr;
	struct rrfixed fix;
	struct minfo *minfo;
	struct cachedsoa *soa;

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
		fix.ttl = htonl(MAX(rr->rr_ttl, minttl));
	switch (rr->rr_type) {
	case T_CNAME:
	case T_MB:
	case T_MD:
	case T_MF:
	case T_MG:
	case T_MR:
	case T_NS:
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
	default:
		/* unparsed RDATA */
		if (q->q_msg_endstop - q->q_msgptr < rr->rr_length)
			goto err;
		bcopy(rr + 1, q->q_msgptr, rr->rr_length);
		q->q_msgptr += rr->rr_length;
	}
	fix.rdlength = htons(q->q_msgptr - dataptr);
	bcopy(&fix, fixptr, RRFIXEDSZ);
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
	return(0);
}

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
