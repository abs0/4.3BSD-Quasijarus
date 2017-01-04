#ifndef lint
static char sccsid[] = "@(#)dnameunder.c	1.1 (IFCTF) 2011/12/27";
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
