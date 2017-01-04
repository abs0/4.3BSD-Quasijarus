h23767
s 00007/00001/00028
d D 5.1 85/06/07 23:16:35 kre 3 2
c Add copyright
e
s 00001/00001/00028
d D 1.2 81/02/20 12:55:35 dlw 2 1
c fixed errno for bad unit to be F_ERUNIT. DLW
e
s 00029/00000/00000
d D 1.1 81/02/19 10:04:03 dlw 1 0
c date and time created 81/02/19 10:04:03 by dlw
e
u
U
t
T
I 1
/*
D 3
char id_ftell[] = "%W%";
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
 *
I 3
 *	%W%	%G%
 */

/*
E 3
 * return current file position
 *
 * calling sequence:
 *	integer curpos, ftell
 *	curpos = ftell(lunit)
 * where:
 *	lunit is an open logical unit
 *	curpos will be the current offset in bytes from the start of the
 *		file associated with that logical unit
 *		or a (negative) system error code.
 */

#include	"../libI77/fiodefs.h"
#include	"../libI77/f_errno.h"

extern unit units[];

long ftell_(lu)
long *lu;
{
	if (*lu < 0 || *lu >= MXUNIT)
D 2
		return(-(long)(errno=F_ERARG));
E 2
I 2
		return(-(long)(errno=F_ERUNIT));
E 2
	if (!units[*lu].ufd)
		return(-(long)(errno=F_ERNOPEN));
	return(ftell(units[*lu].ufd));
}
E 1
