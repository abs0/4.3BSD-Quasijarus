h46642
s 00028/00000/00000
d D 1.1 2011/12/27 02:01:53 msokolov 1 0
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
#include "dname.h"

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
E 1
