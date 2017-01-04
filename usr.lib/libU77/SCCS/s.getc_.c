h61060
s 00007/00001/00039
d D 5.1 85/06/07 23:17:45 kre 5 4
c Add copyright
e
s 00001/00001/00039
d D 1.4 85/03/20 14:54:39 ralph 4 3
c don't strip parity since its done with stdio.
e
s 00002/00002/00038
d D 1.3 81/08/11 19:41:47 dlw 3 2
c added test for return val of nowreading(). DLW
e
s 00009/00005/00031
d D 1.2 81/06/15 22:00:27 dlw 2 1
c added 'nowreading(lu)'. DLW
e
s 00036/00000/00000
d D 1.1 81/02/11 22:34:00 dlw 1 0
c date and time created 81/02/11 22:34:00 by dlw
e
u
U
t
T
I 1
/*
D 5
char id_getc[] = "%W%";
E 5
I 5
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
 *
I 5
 *	%W%	%G%
 */

/*
E 5
 * get a character from the standard input
 *
 * calling sequence:
 *	integer getc
 *	ierror = getc (char)
 * where:
 *	char will be read from the standard input, usually the terminal
 *	ierror will be 0 if successful; a system error code otherwise.
 */

#include	"../libI77/f_errno.h"
#include	"../libI77/fiodefs.h"

extern unit units[];	/* logical units table from iolib */

long getc_(c, clen)
char *c; long clen;
{
D 2
	int i;
E 2
I 2
	int	i;
	unit	*lu;
E 2

D 2
	if (!units[STDIN].ufd)
E 2
I 2
	lu = &units[STDIN];
	if (!lu->ufd)
E 2
		return((long)(errno=F_ERNOPEN));
D 2
	if ((i = getc (units[STDIN].ufd)) < 0)
E 2
I 2
D 3
	if (lu->uwrt)
		nowreading(lu);
E 3
I 3
	if (lu->uwrt && ! nowreading(lu))
		return((long)errno);
E 3
	if ((i = getc (lu->ufd)) < 0)
E 2
	{
D 2
		if (feof(units[STDIN].ufd))
E 2
I 2
		if (feof(lu->ufd))
E 2
			return(-1L);
		i = errno;
D 2
		clearerr(units[STDIN].ufd);
E 2
I 2
		clearerr(lu->ufd);
E 2
		return((long)i);
	}
D 4
	*c = i & 0177;
E 4
I 4
	*c = i;
E 4
	return(0L);
}
E 1
