h60080
s 00001/00000/00035
d D 5.2 85/01/22 14:09:15 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00035/00000/00000
d D 5.1 83/07/02 17:57:12 sam 1 0
c date and time created 83/07/02 17:57:12 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include "uucp.h"
#include <sgtty.h>

/*******
 *	ioctl(fn, com, ttbuf)	for machines without ioctl
 *	int fn, com;
 *	struct sgttyb *ttbuf;
 *
 *	return codes - same as stty and gtty
 */

ioctl(fn, com, ttbuf)
register int fn, com;
struct sgttyb *ttbuf;
{
	struct sgttyb tb;

	switch (com) {
	case TIOCHPCL:
		gtty(fn, &tb);
		tb.sg_flags |= 1;
		return(stty(fn, &tb));
	case TIOCGETP:
		return(gtty(fn, ttbuf));
	case TIOCSETP:
		return(stty(fn, ttbuf));
	case TIOCEXCL:
I 2
	case TIOCNXCL:
E 2
	default:
		return(-1);
	}
}
E 1
