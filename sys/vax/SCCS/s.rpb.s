h63851
s 00001/00001/00017
d D 7.1 86/06/05 00:57:51 mckusick 3 2
c 4.3BSD release version
e
s 00007/00001/00011
d D 6.2 85/06/08 13:56:38 mckusick 2 1
c Add copyright
e
s 00012/00000/00000
d D 6.1 83/08/01 12:10:12 sam 1 0
c date and time created 83/08/01 12:10:12 by sam
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
D 3
 * Copyright (c) 1982 Regents of the University of California.
E 3
I 3
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

/*
 * This has to get loaded first (physical 0) as 780 memory restart rom
 * only looks for rpb on a 64K page boundary (doc isn't wrong,
 * it never says what size "page boundary" rpb has to be on).
 */
	.globl	_rpb
_rpb:
	.space	508
erpb:
	.space	4
E 1
