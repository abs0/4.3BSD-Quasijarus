/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * This module handles the attachment of zonal RRs to tree nodes
 * during the zone loading process.  It takes the place of the old
 * attachrr.c code in the original MSDNS version - specifically, the
 * extra functionality added on top of our new internalize_rr()
 * function is the check for duplicates and conflicts.
 */

#ifndef lint
static char sccsid[] = "@(#)zonerr.c	1.1 (IFCTF) 2013/01/11";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "dname.h"
#include "tree.h"
#include "rr.h"
#include "msgparse.h"

extern struct rr *internalize_rr();

/*
 * Every time the code in zoneload.c calls us to add a new RR to a node,
 * we will ultimately get to the end of the n_rrzone chain, internalize
 * our new RR and add it to the chain - slam dunk.  But as we traverse
 * the already-loaded n_rrzone chain, we check for possible duplicates
 * and conflicts.  If an already-loaded RR has the same type and class
 * as the new one, the compare_for_conflict() function is called.
 *
 * The first two arguments to compare_for_conflict() are self-explanatory.
 * The return value is 0 if the code in attach_rrzone_to_node() should
 * keep going, or 1 if attach_rrzone_to_node() should exit.  In the
 * latter case, put the return value in *rstat.
 */

static
compare_general(old, new, rstat)
	register struct rr *old;
	register struct parsedrr *new;
	int *rstat;
{
	if (old->rr_length != new->prr_fix.rdlength)
		return(0);
	if (bcmp((u_char *)(old + 1), new->prr_rdata, old->rr_length))
		return(0);
	*rstat = old->rr_ttl == new->prr_fix.ttl ? 0 : -1;
	return(1);
}

static
compare_gen_dname(old, new, rstat)
	register struct rr *old;
	register struct parsedrr *new;
	int *rstat;
{
	if (!dname_compare((struct dname *)(old + 1), &new->prr_rdata_dn[0]))
		return(0);
	*rstat = old->rr_ttl == new->prr_fix.ttl ? 0 : -1;
	return(1);
}

static
compare_mx(old, new, rstat)
	register struct rr *old;
	register struct parsedrr *new;
	int *rstat;
{
	int newpref;

	if (!dname_compare((struct dname *)(old + 1), &new->prr_rdata_dn[0]))
		return(0);
	newpref = new->prr_rdata[0] << 8 | new->prr_rdata[1];
	if (newpref == old->rr_mxpref && new->prr_fix.ttl == old->rr_ttl)
		*rstat = 0;
	else
		*rstat = -1;
	return(1);
}

static
compare_afsdb(old, new, rstat)
	register struct rr *old;
	register struct parsedrr *new;
	int *rstat;
{
	if ((new->prr_rdata[0] << 8 | new->prr_rdata[1]) != old->rr_miscshort)
		return(0);
	if (!dname_compare((struct dname *)(old + 1), &new->prr_rdata_dn[0]))
		return(0);
	*rstat = old->rr_ttl == new->prr_fix.ttl ? 0 : -1;
	return(1);
}

static
compare_hinfo(old, new, rstat)
	register struct rr *old;
	register struct parsedrr *new;
	int *rstat;
{
	if (old->rr_length == new->prr_fix.rdlength &&
	    !bcmp((u_char *)(old + 1), new->prr_rdata, old->rr_length) &&
	    old->rr_ttl == new->prr_fix.ttl)
		*rstat = 0;
	else
		*rstat = -1;
	return(1);
}

static
compare_minfo(old, new, rstat)
	register struct rr *old;
	register struct parsedrr *new;
	int *rstat;
{
	register struct minfo *oldmi;

	oldmi = (struct minfo *)(old + 1);
	if (dname_compare(oldmi->minfo_dn1, &new->prr_rdata_dn[0]) &&
	    dname_compare(oldmi->minfo_dn2, &new->prr_rdata_dn[1]) &&
	    old->rr_ttl == new->prr_fix.ttl)
		*rstat = 0;
	else
		*rstat = -1;
	return(1);
}

static
compare_rp(old, new, rstat)
	register struct rr *old;
	register struct parsedrr *new;
	int *rstat;
{
	register struct minfo *oldmi;

	oldmi = (struct minfo *)(old + 1);
	if (!dname_compare(oldmi->minfo_dn1, &new->prr_rdata_dn[0]))
		return(0);
	if (!dname_compare(oldmi->minfo_dn2, &new->prr_rdata_dn[1]))
		return(0);
	*rstat = old->rr_ttl == new->prr_fix.ttl ? 0 : -1;
	return(1);
}

static
compare_wks(old, new, rstat)
	register struct rr *old;
	register struct parsedrr *new;
	int *rstat;
{
	if (bcmp((u_char *)(old + 1), new->prr_rdata, 5))
		return(0);
	if (old->rr_length == new->prr_fix.rdlength &&
	    !bcmp((u_char *)(old + 1), new->prr_rdata, old->rr_length) &&
	    old->rr_ttl == new->prr_fix.ttl)
		*rstat = 0;
	else
		*rstat = -1;
	return(1);
}

static
compare_for_conflict(old, new, rstat)
	struct rr *old;
	struct parsedrr *new;
	int *rstat;
{
	switch (old->rr_type) {
	case T_CNAME:
	case T_MB:
	case T_MG:
	case T_MR:
	case T_PTR:
		return compare_gen_dname(old, new, rstat);
	case T_MX:
	case T_RT:
		return compare_mx(old, new, rstat);
	case T_AFSDB:
		return compare_afsdb(old, new, rstat);
	case T_HINFO:
		return compare_hinfo(old, new, rstat);
	case T_MINFO:
		return compare_minfo(old, new, rstat);
	case T_RP:
		return compare_rp(old, new, rstat);
	case T_WKS:
		return compare_wks(old, new, rstat);
	case T_SOA:
	case T_NS:
	case T_MD:
	case T_MF:
		syslog(LOG_CRIT,
			"BUG: bad RR type %d in attach_rrzone_to_node()",
			old->rr_type);
		abort();
	default:
		return compare_general(old, new, rstat);
	}
}

/*
 * The attach_rrzone_to_node() function takes the place of the old
 * attach_rr_to_node(), but only for zone loading.
 *
 * Return value:
 *  0 = success
 * -1 = new RR conflicts with an already-loaded one
 * -2 = malloc failure
 */
attach_rrzone_to_node(n, prr)
	struct node *n;
	register struct parsedrr *prr;
{
	register struct rr *rr, **rrp;
	int rstat;

	for (rrp = &n->n_rrzone; rr = *rrp; rrp = &rr->rr_next)
		if (rr->rr_type == prr->prr_fix.type &&
		    rr->rr_class == prr->prr_fix.class &&
		    compare_for_conflict(rr, prr, &rstat))
			return(rstat);
	rr = internalize_rr(prr, 0);
	if (!rr)
		return(-2);
	*rrp = rr;
	return(0);
}
