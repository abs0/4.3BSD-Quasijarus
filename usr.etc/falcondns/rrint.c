/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * This module handles the generation of internalized RRs, which will
 * then be attached to ADDT nodes by code in other modules.
 */

#ifndef lint
static char sccsid[] = "@(#)rrint.c	1.1 (IFCTF) 2013/01/11";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include "dname.h"
#include "rr.h"
#include "msgparse.h"
#include "globals.h"

extern u_char *myalloc();

/*
 * The internalize_rr() function takes an RR that has been received
 * from the outside world (protocol message or binzone file), contained
 * in a struct parsedrr that has already passed msgparse_rdata(),
 * and converts it into a struct rr for longer-term storage.
 * This function computes the needed malloc chunk size, does the malloc,
 * and then fills the rather complex variable-length, variable-structure
 * chunk, beginning with struct rr.
 *
 * The second argument serves a dual function: if nonzero, it indicates
 * that the internalized RR is of the cached kind (expiration time rather
 * than TTL), and gives the TTL value to be added to current_time.
 * If the second argument is zero, it means that the RR being worked on
 * is zonal, and will get its TTL from prr_fix.ttl, coming from the
 * binzone file.
 *
 * The prr_owner dname is ignored.
 *
 * The return value is struct rr *; it points to the just-created
 * internal RR representation if successful, or null on errors.
 * The only currently possible error is malloc failure.
 */

static struct rr *
internalize_raw(prr, cachettl)
	register struct parsedrr *prr;
	int cachettl;
{
	register struct rr *rr;
	register u_char *dp;

	dp = myalloc(sizeof(struct rr) + prr->prr_fix.rdlength);
	if (!dp)
		return(0);
	rr = (struct rr *)dp;
	dp += sizeof(struct rr);
	rr->rr_next = 0;
	rr->rr_type = prr->prr_fix.type;
	rr->rr_class = prr->prr_fix.class;
	if (cachettl) {
		rr->rr_flags = RR_CACHED;
		rr->rr_expire = current_time + cachettl;
	} else {
		rr->rr_flags = 0;
		rr->rr_ttl = prr->prr_fix.ttl;
	}
	rr->rr_length = prr->prr_fix.rdlength;
	bcopy(prr->prr_rdata, dp, prr->prr_fix.rdlength);
	return(rr);
}

static struct rr *
internalize_dname(prr, cachettl)
	register struct parsedrr *prr;
	int cachettl;
{
	register struct rr *rr;
	register u_char *dp;

	dp = myalloc(sizeof(struct rr) + dn_spaceneeded(&prr->prr_rdata_dn[0]));
	if (!dp)
		return(0);
	rr = (struct rr *)dp;
	dp += sizeof(struct rr);
	rr->rr_next = 0;
	rr->rr_type = prr->prr_fix.type;
	rr->rr_class = prr->prr_fix.class;
	if (cachettl) {
		rr->rr_flags = RR_CACHED;
		rr->rr_expire = current_time + cachettl;
	} else {
		rr->rr_flags = 0;
		rr->rr_ttl = prr->prr_fix.ttl;
	}
	dname_copy_discontig(&prr->prr_rdata_dn[0], dp);
	switch (rr->rr_type) {
	case T_MX:
	case T_AFSDB:
	case T_RT:
		rr->rr_miscshort = prr->prr_rdata[0] << 8 | prr->prr_rdata[1];
	}
	return(rr);
}

static struct rr *
internalize_minfo(prr, cachettl)
	register struct parsedrr *prr;
	int cachettl;
{
	register struct rr *rr;
	register u_char *dp;
	register struct minfo *mi;

	dp = myalloc(sizeof(struct rr) + sizeof(struct minfo) +
			dn_spaceneeded(&prr->prr_rdata_dn[0]) +
			dn_spaceneeded(&prr->prr_rdata_dn[1]));
	if (!dp)
		return(0);
	rr = (struct rr *)dp;
	dp += sizeof(struct rr);
	rr->rr_next = 0;
	rr->rr_type = prr->prr_fix.type;
	rr->rr_class = prr->prr_fix.class;
	if (cachettl) {
		rr->rr_flags = RR_CACHED;
		rr->rr_expire = current_time + cachettl;
	} else {
		rr->rr_flags = 0;
		rr->rr_ttl = prr->prr_fix.ttl;
	}
	mi = (struct minfo *)dp;
	dp += sizeof(struct minfo);
	mi->minfo_dn1 = (struct dname *)dp;
	dname_copy_discontig(&prr->prr_rdata_dn[0], dp);
	dp += dn_spaceneeded(&prr->prr_rdata_dn[0]);
	mi->minfo_dn2 = (struct dname *)dp;
	dname_copy_discontig(&prr->prr_rdata_dn[1], dp);
	if (rr->rr_type == T_PX)
		rr->rr_miscshort = prr->prr_rdata[0] << 8 | prr->prr_rdata[1];
	return(rr);
}

static struct rr *
internalize_soa(prr, cachettl)
	register struct parsedrr *prr;
	int cachettl;
{
	register struct rr *rr;
	register u_char *dp;
	register struct cachedsoa *soa;

	dp = myalloc(sizeof(struct rr) + sizeof(struct cachedsoa) +
			dn_spaceneeded(&prr->prr_rdata_dn[0]) +
			dn_spaceneeded(&prr->prr_rdata_dn[1]));
	if (!dp)
		return(0);
	rr = (struct rr *)dp;
	dp += sizeof(struct rr);
	rr->rr_next = 0;
	rr->rr_type = T_SOA;
	rr->rr_class = prr->prr_fix.class;
	rr->rr_flags = RR_CACHED;
	rr->rr_expire = current_time + cachettl;
	soa = (struct cachedsoa *)dp;
	dp += sizeof(struct cachedsoa);
	soa->csoa_mname = (struct dname *)dp;
	dname_copy_discontig(&prr->prr_rdata_dn[0], dp);
	dp += dn_spaceneeded(&prr->prr_rdata_dn[0]);
	soa->csoa_rname = (struct dname *)dp;
	dname_copy_discontig(&prr->prr_rdata_dn[1], dp);
	bcopy(prr->prr_rdata_misc, soa->csoa_numbers, 20);
	return(rr);
}

struct rr *
internalize_rr(prr, cachettl)
	struct parsedrr *prr;
	int cachettl;
{
	switch (prr->prr_fix.type) {
	case T_NS:
	case T_MD:
	case T_MF:
	case T_CNAME:
	case T_MB:
	case T_MG:
	case T_MR:
	case T_PTR:
	case T_MX:
	case T_AFSDB:
	case T_RT:
		return internalize_dname(prr, cachettl);
	case T_MINFO:
	case T_RP:
		return internalize_minfo(prr, cachettl);
	case T_SOA:
		return internalize_soa(prr, cachettl);
	default:
		return internalize_raw(prr, cachettl);
	}
}
