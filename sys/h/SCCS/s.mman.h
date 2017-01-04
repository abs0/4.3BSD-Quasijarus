h48046
s 00001/00001/00022
d D 7.1 86/06/04 23:25:02 mckusick 5 4
c 4.3BSD release version
e
s 00007/00001/00016
d D 6.2 85/06/08 15:01:36 mckusick 4 3
c Add copyright
e
s 00000/00000/00017
d D 6.1 83/07/29 06:13:08 sam 3 2
c 4.2 distribution
e
s 00001/00009/00016
d D 4.2 82/09/04 09:28:46 root 2 1
c drop PAGESIZE as a constant
e
s 00025/00000/00000
d D 4.1 82/09/04 09:28:08 root 1 0
c date and time created 82/09/04 09:28:08 by root
e
u
U
t
T
I 1
D 2
/*	mman.h	5.1	82/07/17	*/

#if vax
#define	PAGESIZE	1024
#endif

#if sun
#define	PAGESIZE	2048
#endif
E 2
I 2
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 5
 * Copyright (c) 1982 Regents of the University of California.
E 5
I 5
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4
E 2

/* protections are chosen from these bits, or-ed together */
#define	PROT_READ	0x1		/* pages can be read */
#define	PROT_WRITE	0x2		/* pages can be written */
#define	PROT_EXEC	0x4		/* pages can be executed */

/* sharing types: choose either SHARED or PRIVATE */
#define	MAP_SHARED	1		/* share changes */
#define	MAP_PRIVATE	2		/* changes are private */

/* advice to madvise */
#define	MADV_NORMAL	0		/* no further special treatment */
#define	MADV_RANDOM	1		/* expect random page references */
#define	MADV_SEQUENTIAL	2		/* expect sequential page references */
#define	MADV_WILLNEED	3		/* will need these pages */
#define	MADV_DONTNEED	4		/* dont need these pages */
E 1
