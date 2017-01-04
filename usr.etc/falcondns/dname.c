/*
 * Utility functions for operating on struct dname objects.
 */

#ifndef lint
static char sccsid[] = "@(#)dname.c	1.9 (IFCTF) 2013/01/06";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include <ctype.h>
#include <stdio.h>
#include "dname.h"

/*
 * This function takes a domain-name in ASCII form (it comes from
 * our class definition files, but we require it to follow RFC 1035),
 * parses it and stores it in a struct dname.
 *
 * Return value:
 *  0 = success
 * -1 = ASCII domain-name violates some RFC 1035 rule
 */
parse_ascii_dname(asc, dn)
	register char *asc;
	struct dname *dn;
{
	register u_char *dp;
	u_char *lp;
	register int c, i;
	int lcount = 0;

	lp = dn->dn_buf;
	while (*asc) {
		if (*asc == '.') {
			asc++;
			continue;
		}
		dn->dn_labels[lcount] = lp;
		dp = lp;
		*dp++ = 0;
		while ((c = *asc++) && c != '.') {
			if ((*lp)++ >= MAXLABEL)
				return(-1);
			if (dp - dn->dn_buf >= 255)
				return(-1);
			if (c == '\\') {
				if (!*asc)
					return(-1);
				if (isdigit(*asc)) {
					c = 0;
					for (i = 0; i < 3 && isdigit(*asc); i++)
						c = c*10 + *asc++ - '0';
				} else
					c = *asc++;
			}
			*dp++ = c;
		}
		if (!c)
			asc--;
		lcount++;
		lp = dp;
	}
	dn->dn_labels[lcount] = lp;
	*lp++ = 0;
	dn->dn_nlabels = lcount;
	dn->dn_stringlen = lp - dn->dn_buf;
	return(0);
}

/*
 * This function compares two dnames in the proper case-insensitive manner.
 * Returns 1 if equal, 0 otherwise.
 */
dname_compare(dn1, dn2)
	struct dname *dn1, *dn2;
{
	register u_char **l1, **l2;
	register int i;
	int lcnt;

	if (dn1->dn_stringlen != dn2->dn_stringlen)
		return(0);
	lcnt = dn1->dn_nlabels;
	if (lcnt != dn2->dn_nlabels)
		return(0);
	l1 = dn1->dn_labels;
	l2 = dn2->dn_labels;
	for (i = 0; i < lcnt; i++)
		if (!label_match(*l1++, *l2++))
			return(0);
	return(1);
}

/*
 * This function returns 1 if the 1st dname argument is either equal to
 * or a subdomain of the 2nd dname argument, 0 otherwise.
 */
dname_is_under(c, h)
	register struct dname *c, *h;
{
	register int cl, hl;

	cl = c->dn_nlabels;
	hl = h->dn_nlabels;
	if (cl < hl)
		return(0);
	while (hl) {
		cl--;
		hl--;
		if (!label_match(c->dn_labels[cl], h->dn_labels[hl]))
			return(0);
	}
	return(1);
}

/*
 * This function copies a struct dname to a new location, compacts it
 * in the process, and adjusts the pointers inside.
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

print_dname(dn, f)
	register struct dname *dn;
	register FILE *f;
{
	register int i;

	for (i = 0; i < dn->dn_nlabels; i++) {
		print_label(dn->dn_labels[i], f);
		putc('.', f);
	}
	if (!i)
		putc('.', f);
}
