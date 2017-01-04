h46691
s 00007/00001/00034
d D 5.1 85/06/07 23:15:53 kre 3 2
c Add copyright
e
s 00003/00001/00032
d D 1.2 81/02/20 12:54:02 dlw 2 1
c fixed errno for bad unit to be F_ERUNIT. DLW
e
s 00033/00000/00000
d D 1.1 81/02/19 10:03:41 dlw 1 0
c date and time created 81/02/19 10:03:41 by dlw
e
u
U
t
T
I 1
/*
D 3
char id_fseek[] = "%W%";
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
 * position a file associated with a fortran logical unit
 *
 * calling sequence:
 *	ierror = fseek(lunit, ioff, ifrom)
 * where:
 *	lunit is an open logical unit
 *	ioff is an offset in bytes relative to the position specified by ifrom
 *	ifrom	- 0 means 'beginning of the file'
 *		- 1 means 'the current position'
 *		- 2 means 'the end of the file'
 *	ierror will be 0 if successful, a system error code otherwise.
 */

#include	<stdio.h>
#include	"../libI77/f_errno.h"
#include	"../libI77/fiodefs.h"

extern unit units[];

long fseek_(lu, off, from)
long *lu, *off, *from;
{
D 2
	if (*lu < 0 || *lu >= MXUNIT || *from < 0 || *from > 2)
E 2
I 2
	if (*lu < 0 || *lu >= MXUNIT)
		return((long)(errno=F_ERUNIT));
	if (*from < 0 || *from > 2)
E 2
		return((long)(errno=F_ERARG));
	if (!units[*lu].ufd)
		return((long)(errno=F_ERNOPEN));
	if (fseek(units[*lu].ufd, *off, (int)*from) < 0)
		return((long)errno);
	return(0L);
}
E 1
