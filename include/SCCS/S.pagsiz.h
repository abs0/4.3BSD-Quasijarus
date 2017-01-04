h40287
s 00007/00001/00007
d D 5.1 85/05/30 09:44:19 dist 2 1
c Add copyright
e
s 00008/00000/00000
d D 4.1 83/05/03 13:48:09 sam 1 0
c date and time created 83/05/03 13:48:09 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

#define	NBPG	512
#define	PGOFSET	511
#define	CLSIZE	2
#define	CLOFSET	1023
#define	PAGSIZ	(NBPG*CLSIZE)
#define	PAGRND	((PAGSIZ)-1)
E 1
