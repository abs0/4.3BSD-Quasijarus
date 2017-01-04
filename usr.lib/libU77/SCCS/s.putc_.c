h50449
s 00007/00001/00037
d D 5.1 85/06/07 23:27:13 kre 4 3
c Add copyright
e
s 00002/00002/00036
d D 1.3 81/08/11 19:42:38 dlw 3 2
c added test for return val of nowwriting(). DLW
e
s 00009/00005/00029
d D 1.2 81/06/15 21:59:38 dlw 2 1
c added 'nowwriting(lu)'. DLW
e
s 00034/00000/00000
d D 1.1 81/02/11 22:32:46 dlw 1 0
c date and time created 81/02/11 22:32:46 by dlw
e
u
U
t
T
I 1
/*
D 4
char id_putc[] = "%W%";
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
 *
I 4
 *	%W%	%G%
 */

/*
E 4
 * write a character to the standard output
 *
 * calling sequence:
 *	integer putc
 *	ierror =  putc (char)
 * where:
 *	char will be sent to the standard output, usually the terminal
 *	ierror will be 0 if successful; a system error code otherwise.
 */

#include	"../libI77/f_errno.h"
#include	"../libI77/fiodefs.h"

extern unit units[];	/* logical units table from iolib */

long putc_(c, clen)
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
	if (!units[STDOUT].ufd)
E 2
I 2
	lu = &units[STDOUT];
	if (!lu->ufd)
E 2
		return((long)(errno=F_ERNOPEN));
D 2
	putc (*c, units[STDOUT].ufd);
	if (ferror(units[STDOUT].ufd))
E 2
I 2
D 3
	if (!lu->uwrt)
		nowwriting(lu);
E 3
I 3
	if (!lu->uwrt && ! nowwriting(lu))
		return((long)errno);
E 3
	putc (*c, lu->ufd);
	if (ferror(lu->ufd))
E 2
	{
		i = errno;
D 2
		clearerr(units[STDOUT].ufd);
E 2
I 2
		clearerr(lu->ufd);
E 2
		return((long)i);
	}
	return(0L);
}
E 1
