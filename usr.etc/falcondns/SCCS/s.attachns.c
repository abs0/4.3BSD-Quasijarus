h41159
s 00002/00004/00073
d D 1.2 2013/01/14 02:12:11 msokolov 2 1
c don't leave partial or mixed RRsets on malloc failure
e
s 00077/00000/00000
d D 1.1 2013/01/11 23:01:22 msokolov 1 0
c new module for the new FSR cache design
e
u
U
t
T
I 1
/*
 * FalconDNS daemon by Michael Spacefalcon
 *
 * This module handles the attachment of NS RRs to tree nodes,
 * forming NS RRsets in the ADDT.
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/param.h>
#include <arpa/nameser.h>
#include "dname.h"
#include "tree.h"
#include "nsrec.h"
#include "globals.h"
#include "msgparse.h"

extern u_char *myalloc();

/*
 * The following function is used to populate all NS RRsets in the ADDT
 * with the exception of NS-anchors; see nsanchor.c for the latter.
 */
attach_ns_to_node(n, prr, iscache)
	struct node *n;
	register struct parsedrr *prr;
{
	register struct ns_rrset *set;
	register struct nsrr *ind, **indp;
	register u_char *dp;

	set = n->n_ns;
	if (!set) {
		set = (struct ns_rrset *) myalloc(sizeof(struct ns_rrset));
		if (!set)
			return(-2);
		set->ns_type = iscache ? NSTYPE_CACHEDREF : NSTYPE_DELEGATION;
		set->ns_count = 0;
		set->ns_chain = 0;
		set->ns_roundrobin = 0;
		n->n_ns = set;
	}
	if (iscache)
		set->ns_expire = current_time +
					MIN(prr->prr_fix.ttl, ttl_limit_ns);
	else
		set->ns_ttl = prr->prr_fix.ttl;
	for (indp = &set->ns_chain; ind = *indp; indp = &ind->nsrr_next) {
		dp = (u_char *)ind + sizeof(struct nsrr);
		if (!dname_compare((struct dname *)dp, &prr->prr_rdata_dn[0]))
			continue;
		/* already exists: just keep it */
		ind->nsrr_flags &= ~NSRR_FLAGS_DELETE;
		return(0);
	}
	/* store new RR */
	dp = myalloc(sizeof(struct nsrr) +
			dn_spaceneeded(&prr->prr_rdata_dn[0]));
	if (!dp) {
D 2
		if (!set->ns_count) {
			free(set);
			n->n_ns = 0;
		}
E 2
I 2
		free_ns_rrset(set);
		n->n_ns = 0;
E 2
		return(-2);
	}
	ind = (struct nsrr *)dp;
	bzero(ind, sizeof(struct nsrr));
	dp += sizeof(struct nsrr);
	dname_copy_discontig(&prr->prr_rdata_dn[0], dp);
	*indp = ind;
	set->ns_count++;
	if (dname_is_under(&prr->prr_rdata_dn[0], &prr->prr_owner))
		ind->nsrr_flags |= NSRR_FLAGS_NEEDGLUE;
	return(0);
}
E 1
