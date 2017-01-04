h27541
s 00064/00000/00000
d D 1.1 2011/12/27 02:01:50 msokolov 1 0
c beginning of libmsdns
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (IFCTF) %E%";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include <ctype.h>
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
E 1
