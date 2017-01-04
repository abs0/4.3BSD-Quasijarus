h64984
s 00000/00000/00042
d D 4.2 88/02/24 20:45:16 rick 2 1
c remove extraneous ifdefs
e
s 00042/00000/00000
d D 4.1 85/01/22 13:04:21 ralph 1 0
c date and time created 85/01/22 13:04:21 by ralph
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "../condevs.h"
#ifdef DATAKIT
#include <dk.h>
#define DKTRIES 2
/***
 *	dkopn(flds)	make datakit connection
 *
 *	return codes:
 *		>0 - file number - ok
 *		FAIL - failed
 */
dkopn(flds)
char *flds[];
{
	int dkphone;
	register char *cp;
	register ret, i;

	if (setjmp(Sjbuf))
		return CF_DIAL;

	signal(SIGALRM, alarmtr);
	dkphone = 0;
	cp = flds[F_PHONE];
	while(*cp)
		dkphone = 10 * dkphone + (*cp++ - '0');
	DEBUG(4, "dkphone (%d) ", dkphone);
	for (i = 0; i < DKTRIES; i++) {
		getnextfd();
		ret = dkdial(D_SH, dkphone, 0);
		next_fd = -1;
		DEBUG(4, "dkdial (%d)\n", ret);
		if (ret > -1)
			break;
	}
	return ret;
}
#endif
E 1
