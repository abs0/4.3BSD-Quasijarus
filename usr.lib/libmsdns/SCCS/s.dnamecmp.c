h53027
s 00030/00000/00000
d D 1.1 2011/12/27 02:01:51 msokolov 1 0
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
E 1
