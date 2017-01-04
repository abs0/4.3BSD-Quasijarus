h38104
s 00001/00001/00040
d D 7.2 88/01/28 20:53:08 karels 8 7
c uvax changes; fix devsw index in confxx; header updates
e
s 00001/00001/00040
d D 7.1 86/06/05 01:43:44 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00034
d D 6.2 85/06/08 13:10:01 mckusick 6 5
c Add copyright
e
s 00000/00000/00035
d D 6.1 83/07/29 07:47:20 sam 5 4
c 4.2 distribution
e
s 00002/00001/00033
d D 4.3 82/11/13 23:14:56 sam 4 3
c move includes for 4.1c directory layout
e
s 00001/00001/00033
d D 4.2 81/03/15 20:46:23 wnj 3 2
c 
e
s 00000/00000/00034
d D 4.1 80/11/09 16:29:23 bill 2 1
c stamp for 4bsd
e
s 00034/00000/00000
d D 1.1 80/06/28 10:42:54 bill 1 0
c date and time created 80/06/28 10:42:54 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%G%	*/
E 3
I 3
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 7
 * Copyright (c) 1982 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 6
E 3

D 8
#include "../h/param.h"
E 8
I 8
#include "param.h"
E 8
D 4
#include "../h/mtpr.h"
E 4
I 4

#include "../vax/mtpr.h"
E 4

/*ARGSUSED*/
/*VARARGS1*/
mtpr(regno, value)
{

	asm("	mtpr	8(ap),4(ap)");
}

/*ARGSUSED*/
mfpr(regno)
{

	asm("	mfpr	4(ap),r0");
#ifdef lint
	return (0);
#endif
}

/*
 * Copy bytes within kernel
 */
/*ARGSUSED*/
bcopy(from, to, count)
	caddr_t from, to;
	unsigned count;
{

	asm("	movc3	12(ap),*4(ap),*8(ap)");
}
E 1
