h04354
s 00007/00001/00028
d D 5.1 85/06/07 23:22:40 kre 2 1
c Add copyright
e
s 00029/00000/00000
d D 1.1 81/08/01 18:48:17 dlw 1 0
c date and time created 81/08/01 18:48:17 by dlw
e
u
U
t
T
I 1
/*
D 2
char id_isatty[] = "%W%";
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
 *
I 2
 *	%W%	%G%
 */

/*
E 2
 * determine if stream is associated with a tty (async port)
 *
 * calling sequence:
 *	logical	isatty, val
 *	val = isatty (lunit)
 * where:
 *	val will be .TRUE. if lunit is associated with a 'tty'
 */

#include	"../libI77/fiodefs.h"

extern unit units[];	/* logical units table from iolib */

long isatty_(u)
long *u;
{
	int	i;
	unit	*lu;

	if (*u < 0 || *u >= MXUNIT)
		return(0);
	lu = &units[*u];
	if (!lu->ufd)
		return(0);
	return((long)(isatty(fileno(lu->ufd)) != 0));
}
E 1
