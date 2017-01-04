h10978
s 00007/00001/00041
d D 5.1 85/06/07 23:14:50 kre 6 5
c Add copyright
e
s 00001/00001/00041
d D 1.5 85/03/20 14:54:34 ralph 5 4
c don't strip parity since its done with stdio.
e
s 00002/00002/00040
d D 1.4 81/08/11 19:42:15 dlw 4 3
c added test for return val of nowreading(). DLW
e
s 00009/00005/00033
d D 1.3 81/06/15 22:00:05 dlw 3 2
c added 'nowreading(lu)'. DLW
e
s 00001/00001/00037
d D 1.2 81/02/20 12:51:24 dlw 2 1
c fixed errno for bad unit to be F_ERUNIT. DLW
e
s 00038/00000/00000
d D 1.1 81/02/11 22:33:57 dlw 1 0
c date and time created 81/02/11 22:33:57 by dlw
e
u
U
t
T
I 1
/*
D 6
char id_fgetc[] = "%W%";
E 6
I 6
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
 *
I 6
 *	%W%	%G%
 */

/*
E 6
 * get a character from a logical unit bypassing formatted I/O
 *
 * calling sequence:
 *	integer fgetc
 *	ierror = fgetc (unit, char)
 * where:
 *	char will return a character from logical unit
 *	ierror will be 0 if successful; a system error code otherwise.
 */

#include	"../libI77/fiodefs.h"
#include	"../libI77/f_errno.h"

extern unit units[];	/* logical units table from iolib */

long fgetc_(u, c, clen)
long *u; char *c; long clen;
{
D 3
	int i;
E 3
I 3
	int	i;
	unit	*lu;
E 3

	if (*u < 0 || *u >= MXUNIT)
D 2
		return((long)(errno=F_ERARG));
E 2
I 2
		return((long)(errno=F_ERUNIT));
E 2
D 3
	if (!units[*u].ufd)
E 3
I 3
	lu = &units[*u];
	if (!lu->ufd)
E 3
		return((long)(errno=F_ERNOPEN));
D 3
	if ((i = getc (units[*u].ufd)) < 0)
E 3
I 3
D 4
	if (lu->uwrt)
		nowreading(lu);
E 4
I 4
	if (lu->uwrt && ! nowreading(lu))
		return((long)errno);
E 4
	if ((i = getc (lu->ufd)) < 0)
E 3
	{
D 3
		if (feof(units[*u].ufd))
E 3
I 3
		if (feof(lu->ufd))
E 3
			return(-1L);
		i = errno;
D 3
		clearerr(units[*u].ufd);
E 3
I 3
		clearerr(lu->ufd);
E 3
		return((long)i);
	}
D 5
	*c = i & 0177;
E 5
I 5
	*c = i;
E 5
	return(0L);
}
E 1
