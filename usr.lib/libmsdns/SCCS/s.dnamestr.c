h46541
s 00027/00000/00000
d D 1.1 2011/12/27 23:03:04 msokolov 1 0
c date and time created 2011/12/27 23:03:04 by msokolov
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
 * This function takes a potentially discontiguous dname
 * and emits a contiguous binary string.
 */
dname_emit_bstring(dn, buf)
	register struct dname *dn;
	u_char *buf;
{
	register u_char *dp;
	register int i, l;

	dp = buf;
	for (i = 0; i < dn->dn_nlabels; i++) {
		l = dn->dn_labels[i][0];
		*dp++ = l;
		bcopy(dn->dn_labels[i]+1, dp, l);
		dp += l;
	}
	*dp = 0;
}
E 1
