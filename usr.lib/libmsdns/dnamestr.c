#ifndef lint
static char sccsid[] = "@(#)dnamestr.c	1.1 (IFCTF) 2011/12/27";
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
