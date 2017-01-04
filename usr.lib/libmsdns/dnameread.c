#ifndef lint
static char sccsid[] = "@(#)dnameread.c	1.1 (IFCTF) 2011/12/28";
#endif

#include <sys/types.h>
#include <arpa/nameser.h>
#include <stdio.h>
#include "dname.h"

/*
 * This function reads an uncompressed binary string domain-name
 * from a stdio stream.
 *
 * Return value:
 *  0 = success
 * -1 = EOF upfront
 * -2 = EOF in the middle
 * -3 = total length exceeded
 * -4 = high bits set in a length octet
 */
read_dname_from_file(dn, f)
	register struct dname *dn;
	register FILE *f;
{
	register u_char *dp;
	int lcnt;
	register int len;

	dn->dn_stringlen = 0;
	dp = dn->dn_buf;
	for (lcnt = 0; ; lcnt++) {
		len = getc(f);
		if (len < 0)
			return(dn->dn_stringlen ? -2 : -1);
		if (len & INDIR_MASK)
			return(-4);
		dn->dn_stringlen += len + 1;
		if (dn->dn_stringlen > 256)
			return(-3);
		dn->dn_labels[lcnt] = dp;
		*dp++ = len;
		if (len) {
			if (fread(dp, 1, len, f) != len)
				return(-2);
			dp += len;
		} else
			break;
	}
	dn->dn_nlabels = lcnt;
	return(0);
}
