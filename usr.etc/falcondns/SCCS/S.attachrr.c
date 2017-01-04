h42250
s 00001/00001/00370
d D 1.10 2013/01/06 08:15:48 msokolov 10 9
c s/dname_in_bailiwick/dname_is_under/
e
s 00001/00001/00370
d D 1.9 2013/01/06 07:03:51 msokolov 9 8
c MSDNS => FalconDNS
e
s 00002/00002/00369
d D 1.8 2011/12/22 05:52:17 msokolov 8 7
c ttl-limit tunable setting split into several
e
s 00002/00002/00369
d D 1.7 2011/12/07 23:25:12 msokolov 7 6
c oops, need MIN, not MAX
e
s 00004/00003/00367
d D 1.6 2011/12/07 19:07:40 msokolov 6 5
c ttl-limit setting implemented
e
s 00078/00103/00292
d D 1.5 2011/12/04 03:18:13 msokolov 5 4
c attach_rr_to_node() converted to use struct parsedrr
e
s 00001/00000/00394
d D 1.4 2011/11/11 18:49:01 msokolov 4 3
c ns_roundrobin member added
e
s 00005/00002/00389
d D 1.3 2011/10/29 21:33:40 msokolov 3 2
c NS RR flags slight reform
e
s 00031/00028/00360
d D 1.2 2011/09/12 04:26:06 msokolov 2 1
c NS record handling revamped into RRset model
e
s 00388/00000/00000
d D 1.1 2011/07/15 19:20:05 msokolov 1 0
c date and time created 2011/07/15 19:20:05 by msokolov
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
 * This module handles the attachment of RRs to tree nodes.
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

D 6
#include <sys/types.h>
E 6
I 6
#include <sys/param.h>
E 6
#include <netinet/in.h>
#include <arpa/nameser.h>
#include <syslog.h>
#include "dname.h"
#include "tree.h"
D 2
#include "rr.h"
E 2
I 2
#include "nsrec.h"
E 2
#include "globals.h"
I 5
#include "msgparse.h"
E 5

extern u_char *myalloc();
D 5
extern u_char *extract_dname_from_msg();
E 5

/*
 * The attach_rr_to_node() function does what the name says.
D 5
 * The incoming RR is given in the over-the-wire format, and this
 * function is intended to be used in two ways:
E 5
I 5
 * The incoming RR is given in the parsed format of struct parsedrr,
 * and this function is intended to be used in two ways:
E 5
 *
 * 1. The code in zoneload.c calls it when processing an RR from
 *    a binary zone file.  The format of these files is identical
 *    to the standard over-the-wire format except that compression
 *    is disallowed, and the entire RR has already been read from
 *    the file into a memory buffer (on the stack).
 *
 * 2. The same function will be used to add RRs to the cache, and
 *    the intent is that the data will be copied from whatever
 *    protocol message the RR came in.  The decision to cache or
 *    not to cache will be made before calling this function, and
 *    because that would require looking at the RR, the implication
 *    is that some sanity checking will already have been done.
 *
 * This function is responsible for resolving duplicates as well.
 * The general underlying assumption is that by the time this
 * function is called, the new RR has already been validated and
 * the decision to store it is firm, so it can take precedence
 * over old ones.
 *
 * Return value:
 *  0 = success
 * -1 = invalid RR
 * -2 = malloc failure
 */

static void
set_ttl(rr, ttlin)
	register struct rr *rr;
	u_long ttlin;
{
	if (rr->rr_flags & RR_CACHED)
D 6
		rr->rr_expire = current_time + ttlin;
E 6
I 6
D 7
		rr->rr_expire = current_time + MAX(ttlin, ttl_limit);
E 7
I 7
D 8
		rr->rr_expire = current_time + MIN(ttlin, ttl_limit);
E 8
I 8
		rr->rr_expire = current_time + MIN(ttlin, ttl_limit_data);
E 8
E 7
E 6
	else
		rr->rr_ttl = ttlin;
}

static
D 5
handle_ns(n, fix, rdata, msgstart, iscache)
E 5
I 5
handle_ns(n, prr, iscache)
E 5
	struct node *n;
D 5
	struct rrfixed *fix;
	u_char *rdata, *msgstart;
E 5
I 5
	register struct parsedrr *prr;
E 5
{
D 3
	struct dname newdn;
E 3
I 3
D 5
	struct dname newdn, owner;
E 5
E 3
D 2
	register struct rr *rr, **rrp, *nrr;
E 2
I 2
	register struct ns_rrset *set;
	register struct nsrr *ind, **indp;
E 2
	register u_char *dp;

D 5
	if (!extract_dname_from_msg(&newdn, rdata, rdata + fix->rdlength,
				    msgstart))
		return(-1);
E 5
I 2
	set = n->n_ns;
	if (!set) {
		set = (struct ns_rrset *) myalloc(sizeof(struct ns_rrset));
		if (!set)
			return(-2);
		set->ns_type = iscache ? NSTYPE_CACHEDREF : NSTYPE_DELEGATION;
		set->ns_count = 0;
		set->ns_chain = 0;
I 4
		set->ns_roundrobin = 0;
E 4
		n->n_ns = set;
	}
E 2
	if (iscache)
D 2
		rrp = &n->n_rrcache;
E 2
I 2
D 5
		set->ns_expire = current_time + fix->ttl;
E 5
I 5
D 6
		set->ns_expire = current_time + prr->prr_fix.ttl;
E 6
I 6
		set->ns_expire = current_time +
D 7
					MAX(prr->prr_fix.ttl, ttl_limit);
E 7
I 7
D 8
					MIN(prr->prr_fix.ttl, ttl_limit);
E 8
I 8
					MIN(prr->prr_fix.ttl, ttl_limit_ns);
E 8
E 7
E 6
E 5
E 2
	else
D 2
		rrp = &n->n_rrzone;
	for (; rr = *rrp; rrp = &rr->rr_next) {
		if (rr->rr_type != T_NS)
			break;
		dp = (u_char *)rr + sizeof(struct rr) + 4;
E 2
I 2
D 5
		set->ns_ttl = fix->ttl;
E 5
I 5
		set->ns_ttl = prr->prr_fix.ttl;
E 5
	for (indp = &set->ns_chain; ind = *indp; indp = &ind->nsrr_next) {
		dp = (u_char *)ind + sizeof(struct nsrr);
E 2
D 5
		if (!dname_compare(dp, &newdn))
E 5
I 5
		if (!dname_compare((struct dname *)dp, &prr->prr_rdata_dn[0]))
E 5
			continue;
D 2
		/* already exists: update it and be done */
		/* all we need to update is TTL */
		set_ttl(rr, fix->ttl);
E 2
I 2
		/* already exists: just keep it */
D 3
		ind->nsrr_delcandidate = 0;
E 3
I 3
		ind->nsrr_flags &= ~NSRR_FLAGS_DELETE;
E 3
E 2
		return(0);
	}
	/* store new RR */
D 2
	dp = myalloc(sizeof(struct rr) + 4 + dn_spaceneeded(&newdn));
	if (!dp)
E 2
I 2
D 5
	dp = myalloc(sizeof(struct nsrr) + dn_spaceneeded(&newdn));
E 5
I 5
	dp = myalloc(sizeof(struct nsrr) +
			dn_spaceneeded(&prr->prr_rdata_dn[0]));
E 5
	if (!dp) {
		if (!set->ns_count) {
			free(set);
			n->n_ns = 0;
		}
E 2
		return(-2);
D 2
	nrr = (struct rr *)dp;
	dp += sizeof(struct rr);
	nrr->rr_node = n;
	nrr->rr_next = rr;
	nrr->rr_type = T_NS;
	nrr->rr_class = fix->class;
	nrr->rr_flags = iscache ? RR_CACHED : 0;
	set_ttl(nrr, fix->ttl);
	*(u_long *)dp = 0;
	dp += 4;
E 2
I 2
	}
	ind = (struct nsrr *)dp;
	bzero(ind, sizeof(struct nsrr));
	dp += sizeof(struct nsrr);
E 2
D 5
	dname_copy_discontig(&newdn, dp);
E 5
I 5
	dname_copy_discontig(&prr->prr_rdata_dn[0], dp);
E 5
D 2
	*rrp = nrr;
	if (iscache)
		n->n_rrcache_nscount++;
	else
		n->n_rrzone_nscount++;
E 2
I 2
	*indp = ind;
	set->ns_count++;
I 3
D 5
	dname_of_node(n, &owner);
	if (dname_in_bailiwick(&newdn, &owner))
E 5
I 5
D 10
	if (dname_in_bailiwick(&prr->prr_rdata_dn[0], &prr->prr_owner))
E 10
I 10
	if (dname_is_under(&prr->prr_rdata_dn[0], &prr->prr_owner))
E 10
E 5
		ind->nsrr_flags |= NSRR_FLAGS_NEEDGLUE;
E 3
E 2
	return(0);
}

static
D 5
handle_gen_dname(n, fix, rdata, msgstart, iscache)
E 5
I 5
handle_gen_dname(n, prr, iscache)
E 5
	struct node *n;
D 5
	register struct rrfixed *fix;
	u_char *rdata, *msgstart;
E 5
I 5
	register struct parsedrr *prr;
E 5
{
D 5
	struct dname newdn;
E 5
	register struct rr *rr, **rrp;
	register u_char *dp;
	int mxpref;

D 5
	if (fix->type != T_MX) {
		if (!extract_dname_from_msg(&newdn, rdata,
					    rdata + fix->rdlength, msgstart))
			return(-1);
	} else {
		if (fix->rdlength < 3)
			return(-1);
		mxpref = rdata[0] << 8 | rdata[1];
		if (!extract_dname_from_msg(&newdn, rdata + 2,
					    rdata + fix->rdlength, msgstart))
			return(-1);
	}
E 5
I 5
	if (prr->prr_fix.type == T_MX)
		mxpref = prr->prr_rdata[0] << 8 | prr->prr_rdata[1];
E 5
	if (iscache)
		rrp = &n->n_rrcache;
	else
		rrp = &n->n_rrzone;
	for (; rr = *rrp; rrp = &rr->rr_next) {
D 5
		if (rr->rr_type != fix->type || rr->rr_class != fix->class)
E 5
I 5
		if (rr->rr_type != prr->prr_fix.type ||
		    rr->rr_class != prr->prr_fix.class)
E 5
			continue;
		dp = (u_char *)rr + sizeof(struct rr);
D 5
		if (!dname_compare(dp, &newdn))
E 5
I 5
		if (!dname_compare((struct dname *)dp, &prr->prr_rdata_dn[0]))
E 5
			continue;
		/* already exists: update it and be done */
D 5
		set_ttl(rr, fix->ttl);
E 5
I 5
		set_ttl(rr, prr->prr_fix.ttl);
E 5
		rr->rr_mxpref = mxpref;		/* garbage field if not MX */
		return(0);
	}
	/* store new RR */
D 5
	dp = myalloc(sizeof(struct rr) + dn_spaceneeded(&newdn));
E 5
I 5
	dp = myalloc(sizeof(struct rr) + dn_spaceneeded(&prr->prr_rdata_dn[0]));
E 5
	if (!dp)
		return(-2);
	rr = (struct rr *)dp;
	dp += sizeof(struct rr);
	rr->rr_node = n;
	rr->rr_next = 0;
D 5
	rr->rr_type = fix->type;
	rr->rr_class = fix->class;
E 5
I 5
	rr->rr_type = prr->prr_fix.type;
	rr->rr_class = prr->prr_fix.class;
E 5
	rr->rr_flags = iscache ? RR_CACHED : 0;
D 5
	set_ttl(rr, fix->ttl);
E 5
I 5
	set_ttl(rr, prr->prr_fix.ttl);
E 5
	rr->rr_mxpref = mxpref;		/* garbage field if not MX */
D 5
	dname_copy_discontig(&newdn, dp);
E 5
I 5
	dname_copy_discontig(&prr->prr_rdata_dn[0], dp);
E 5
	*rrp = rr;
	return(0);
}

static
D 5
handle_raw_mult(n, fix, rdata, iscache)
E 5
I 5
handle_raw_mult(n, prr, iscache)
E 5
	struct node *n;
D 5
	register struct rrfixed *fix;
	u_char *rdata;
E 5
I 5
	register struct parsedrr *prr;
E 5
{
	register struct rr *rr, **rrp;
	register u_char *dp;

	if (iscache)
		rrp = &n->n_rrcache;
	else
		rrp = &n->n_rrzone;
	for (; rr = *rrp; rrp = &rr->rr_next) {
D 5
		if (rr->rr_type != fix->type || rr->rr_class != fix->class)
E 5
I 5
		if (rr->rr_type != prr->prr_fix.type ||
		    rr->rr_class != prr->prr_fix.class)
E 5
			continue;
D 5
		if (rr->rr_length != fix->rdlength)
E 5
I 5
		if (rr->rr_length != prr->prr_fix.rdlength)
E 5
			continue;
D 5
		if (bcmp((u_char *)rr + sizeof(struct rr), rdata,
E 5
I 5
		if (bcmp((u_char *)rr + sizeof(struct rr), prr->prr_rdata,
E 5
			 rr->rr_length))
			continue;
		/* already exists: update it and be done */
		/* all we need to update is TTL */
D 5
		set_ttl(rr, fix->ttl);
E 5
I 5
		set_ttl(rr, prr->prr_fix.ttl);
E 5
		return(0);
	}
	/* store new RR */
D 5
	dp = myalloc(sizeof(struct rr) + fix->rdlength);
E 5
I 5
	dp = myalloc(sizeof(struct rr) + prr->prr_fix.rdlength);
E 5
	if (!dp)
		return(-2);
	rr = (struct rr *)dp;
	dp += sizeof(struct rr);
	rr->rr_node = n;
	rr->rr_next = 0;
D 5
	rr->rr_type = fix->type;
	rr->rr_class = fix->class;
E 5
I 5
	rr->rr_type = prr->prr_fix.type;
	rr->rr_class = prr->prr_fix.class;
E 5
	rr->rr_flags = iscache ? RR_CACHED : 0;
D 5
	set_ttl(rr, fix->ttl);
	rr->rr_length = fix->rdlength;
	bcopy(rdata, dp, fix->rdlength);
E 5
I 5
	set_ttl(rr, prr->prr_fix.ttl);
	rr->rr_length = prr->prr_fix.rdlength;
	bcopy(prr->prr_rdata, dp, prr->prr_fix.rdlength);
E 5
	*rrp = rr;
	return(0);
}

static
D 5
handle_raw_unique(n, fix, rdata, iscache)
E 5
I 5
handle_raw_unique(n, prr, iscache)
E 5
	struct node *n;
D 5
	register struct rrfixed *fix;
	u_char *rdata;
E 5
I 5
	register struct parsedrr *prr;
E 5
{
	register struct rr *rr, **rrp;
	register u_char *dp;

	if (iscache)
		rrp = &n->n_rrcache;
	else
		rrp = &n->n_rrzone;
loop:	for (; rr = *rrp; rrp = &rr->rr_next) {
D 5
		if (rr->rr_type != fix->type || rr->rr_class != fix->class)
E 5
I 5
		if (rr->rr_type != prr->prr_fix.type ||
		    rr->rr_class != prr->prr_fix.class)
E 5
			continue;
		/* delete the old RR */
		*rrp = rr->rr_next;
		free(rr);
		goto loop;
	}
	/* store new RR */
D 5
	dp = myalloc(sizeof(struct rr) + fix->rdlength);
E 5
I 5
	dp = myalloc(sizeof(struct rr) + prr->prr_fix.rdlength);
E 5
	if (!dp)
		return(-2);
	rr = (struct rr *)dp;
	dp += sizeof(struct rr);
	rr->rr_node = n;
	rr->rr_next = 0;
D 5
	rr->rr_type = fix->type;
	rr->rr_class = fix->class;
E 5
I 5
	rr->rr_type = prr->prr_fix.type;
	rr->rr_class = prr->prr_fix.class;
E 5
	rr->rr_flags = iscache ? RR_CACHED : 0;
D 5
	set_ttl(rr, fix->ttl);
	rr->rr_length = fix->rdlength;
	bcopy(rdata, dp, fix->rdlength);
E 5
I 5
	set_ttl(rr, prr->prr_fix.ttl);
	rr->rr_length = prr->prr_fix.rdlength;
	bcopy(prr->prr_rdata, dp, prr->prr_fix.rdlength);
E 5
	*rrp = rr;
	return(0);
}

static
D 5
handle_minfo(n, fix, rdata, msgstart)
E 5
I 5
handle_minfo(n, prr)
E 5
	struct node *n;
D 5
	register struct rrfixed *fix;
	u_char *rdata, *msgstart;
E 5
I 5
	register struct parsedrr *prr;
E 5
{
D 5
	struct dname dn1, dn2;
E 5
	register struct rr *rr, **rrp;
	register u_char *dp;
	register struct minfo *mi;

D 5
	dp = rdata;
	dp = extract_dname_from_msg(&dn1, dp, rdata + fix->rdlength, msgstart);
	if (!dp)
		return(-1);
	dp = extract_dname_from_msg(&dn2, dp, rdata + fix->rdlength, msgstart);
	if (!dp)
		return(-1);
E 5
	rrp = &n->n_rrzone;
loop:	for (; rr = *rrp; rrp = &rr->rr_next) {
D 5
		if (rr->rr_type != T_MINFO || rr->rr_class != fix->class)
E 5
I 5
		if (rr->rr_type != T_MINFO ||
		    rr->rr_class != prr->prr_fix.class)
E 5
			continue;
		/* delete the old RR */
		*rrp = rr->rr_next;
		free(rr);
		goto loop;
	}
	/* store new RR */
	dp = myalloc(sizeof(struct rr) + sizeof(struct minfo) +
D 5
			dn_spaceneeded(&dn1) + dn_spaceneeded(&dn2));
E 5
I 5
			dn_spaceneeded(&prr->prr_rdata_dn[0]) +
			dn_spaceneeded(&prr->prr_rdata_dn[1]));
E 5
	if (!dp)
		return(-2);
	rr = (struct rr *)dp;
	dp += sizeof(struct rr);
	rr->rr_node = n;
	rr->rr_next = 0;
	rr->rr_type = T_MINFO;
D 5
	rr->rr_class = fix->class;
E 5
I 5
	rr->rr_class = prr->prr_fix.class;
E 5
	rr->rr_flags = 0;
D 5
	rr->rr_ttl = fix->ttl;
E 5
I 5
	rr->rr_ttl = prr->prr_fix.ttl;
E 5
	mi = (struct minfo *)dp;
	dp += sizeof(struct minfo);
	mi->minfo_dn1 = (struct dname *)dp;
D 5
	dname_copy_discontig(&dn1, dp);
	dp += dn_spaceneeded(&dn1);
E 5
I 5
	dname_copy_discontig(&prr->prr_rdata_dn[0], dp);
	dp += dn_spaceneeded(&prr->prr_rdata_dn[0]);
E 5
	mi->minfo_dn2 = (struct dname *)dp;
D 5
	dname_copy_discontig(&dn2, dp);
E 5
I 5
	dname_copy_discontig(&prr->prr_rdata_dn[1], dp);
E 5
	*rrp = rr;
	return(0);
}

static
D 5
handle_wks(n, fix, rdata, iscache)
E 5
I 5
handle_wks(n, prr, iscache)
E 5
	struct node *n;
D 5
	struct rrfixed *fix;
	u_char *rdata;
E 5
I 5
	register struct parsedrr *prr;
E 5
{
	register struct rr *rr, **rrp;
	register u_char *dp;

D 5
	if (fix->class != C_IN)
E 5
I 5
	if (prr->prr_fix.class != C_IN)
E 5
		return(-1);
D 5
	if (fix->rdlength < 5 + 1 || fix->rdlength > 5 + 8192)
E 5
I 5
	if (prr->prr_fix.rdlength < 5 + 1 || prr->prr_fix.rdlength > 5 + 8192)
E 5
		return(-1);
	if (iscache)
		rrp = &n->n_rrcache;
	else
		rrp = &n->n_rrzone;
loop:	for (; rr = *rrp; rrp = &rr->rr_next) {
		if (rr->rr_type != T_WKS)
			continue;
		/* we know it's C_IN because we don't store any others */
D 5
		if (bcmp((u_char *)rr + sizeof(struct rr), rdata, 5))
E 5
I 5
		if (bcmp((u_char *)rr + sizeof(struct rr), prr->prr_rdata, 5))
E 5
			continue;
		/* delete the old RR */
		*rrp = rr->rr_next;
		free(rr);
		goto loop;
	}
	/* store new RR */
D 5
	dp = myalloc(sizeof(struct rr) + fix->rdlength);
E 5
I 5
	dp = myalloc(sizeof(struct rr) + prr->prr_fix.rdlength);
E 5
	if (!dp)
		return(-2);
	rr = (struct rr *)dp;
	dp += sizeof(struct rr);
	rr->rr_node = n;
	rr->rr_next = 0;
	rr->rr_type = T_WKS;
	rr->rr_class = C_IN;
	rr->rr_flags = iscache ? RR_CACHED : 0;
D 5
	set_ttl(rr, fix->ttl);
	rr->rr_length = fix->rdlength;
	bcopy(rdata, dp, fix->rdlength);
E 5
I 5
	set_ttl(rr, prr->prr_fix.ttl);
	rr->rr_length = prr->prr_fix.rdlength;
	bcopy(prr->prr_rdata, dp, prr->prr_fix.rdlength);
E 5
	*rrp = rr;
	return(0);
}

D 5
attach_rr_to_node(n, fix, rdata, msgstart, iscache)
E 5
I 5
attach_rr_to_node(n, prr, iscache)
E 5
	struct node *n;
D 5
	register struct rrfixed *fix;
	u_char *rdata, *msgstart;
E 5
I 5
	register struct parsedrr *prr;
E 5
{
D 5
	switch (fix->type) {
E 5
I 5
	switch (prr->prr_fix.type) {
E 5
	case T_NS:
D 5
		return(handle_ns(n, fix, rdata, msgstart, iscache));
E 5
I 5
		return(handle_ns(n, prr, iscache));
E 5
	case T_CNAME:
	case T_MB:
	case T_MG:
	case T_MR:
	case T_MX:
	case T_PTR:
D 5
		return(handle_gen_dname(n, fix, rdata, msgstart, iscache));
E 5
I 5
		return(handle_gen_dname(n, prr, iscache));
E 5
	case T_A:
D 5
		if (fix->class == C_IN && fix->rdlength != 4)
E 5
I 5
		if (prr->prr_fix.class == C_IN && prr->prr_fix.rdlength != 4)
E 5
			return(-1);
		/* FALL THRU */
	case T_TXT:
D 5
		return(handle_raw_mult(n, fix, rdata, iscache));
E 5
I 5
		return(handle_raw_mult(n, prr, iscache));
E 5
	case T_HINFO:
D 5
		return(handle_raw_unique(n, fix, rdata, iscache));
E 5
I 5
		return(handle_raw_unique(n, prr, iscache));
E 5
	case T_MINFO:
		if (iscache) {
			syslog(LOG_CRIT,
			"attach_rr_to_node() BUG: attempt to cache MINFO");
			return(-1);
		}
D 5
		return(handle_minfo(n, fix, rdata, msgstart));
E 5
I 5
		return(handle_minfo(n, prr));
E 5
	case T_WKS:
D 5
		return(handle_wks(n, fix, rdata, iscache));
E 5
I 5
		return(handle_wks(n, prr, iscache));
E 5
	default:
		syslog(LOG_CRIT,
		"BUG: RR type not checked before calling attach_rr_to_node()");
		return(-1);
	}
}
E 1
