h19603
s 00065/00000/00000
d D 1.1 2011/12/27 02:01:51 msokolov 1 0
c beginning of libmsdns
e
u
U
t
T
I 1
/*
 * struct dname copying/compaction functions
 */

#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include "dname.h"

/*
 * This function copies a struct dname to a new location, compacts it
 * in the process, and adjusts the pointers inside.
 *
 * The source dname must be contiguous.
 */
dname_copy(dnsrc, newloc)
	register struct dname *dnsrc;
	u_char *newloc;
{
	register struct dname *newdn;
	register u_char *oldstr, *newstr;
	register int i;

	newdn = (struct dname *)newloc;
	newdn->dn_nlabels = dnsrc->dn_nlabels;
	newdn->dn_stringlen = dnsrc->dn_stringlen;
	oldstr = dnsrc->dn_labels[0];
	newstr = (u_char *)(newdn->dn_labels + newdn->dn_nlabels + 1);
	for (i = 0; i <= dnsrc->dn_nlabels; i++)
		newdn->dn_labels[i] = dnsrc->dn_labels[i] - oldstr + newstr;
	bcopy(oldstr, newstr, dnsrc->dn_stringlen);
}

/*
 * This function is just like dname_copy(), but the source dname
 * may have non-contiguously-stored labels.
 *
 * Discontiguous source dnames result from parsing a domain-name
 * out of a DNS protocol message where compression was used.
 * Also from dname_of_node() and similar functions.
 */
dname_copy_discontig(dnsrc, newloc)
	register struct dname *dnsrc;
	u_char *newloc;
{
	register struct dname *newdn;
	register u_char *dp;
	register int i, l;

	newdn = (struct dname *)newloc;
	newdn->dn_nlabels = dnsrc->dn_nlabels;
	newdn->dn_stringlen = dnsrc->dn_stringlen;
	dp = (u_char *)(newdn->dn_labels + newdn->dn_nlabels + 1);
	for (i = 0; i < dnsrc->dn_nlabels; i++) {
		newdn->dn_labels[i] = dp;
		l = dnsrc->dn_labels[i][0];
		*dp++ = l;
		bcopy(dnsrc->dn_labels[i]+1, dp, l);
		dp += l;
	}
	newdn->dn_labels[i] = dp;
	*dp = 0;
}
E 1
