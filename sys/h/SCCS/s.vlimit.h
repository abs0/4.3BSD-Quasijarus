h47840
s 00001/00001/00021
d D 7.1 86/06/04 23:31:56 mckusick 10 9
c 4.3BSD release version
e
s 00007/00001/00015
d D 6.2 85/06/08 15:12:56 mckusick 9 8
c Add copyright
e
s 00000/00000/00016
d D 6.1 83/07/29 06:15:04 sam 8 7
c 4.2 distribution
e
s 00002/00001/00014
d D 4.3 81/04/13 20:41:08 root 7 6
c add LIM_MAXRSS
e
s 00001/00001/00014
d D 4.2 81/02/19 21:43:10 wnj 6 5
c %G%->%E%
e
s 00000/00000/00015
d D 4.1 80/11/09 17:02:16 bill 5 4
c stamp for 4bsd
e
s 00000/00000/00015
d D 3.4 80/07/18 14:54:12 bill 4 3
c minor
e
s 00002/00000/00013
d D 3.3 80/07/12 19:50:32 bill 3 2
c added NLIMITS
e
s 00002/00000/00011
d D 3.2 80/07/12 19:07:33 bill 2 1
c INFINITY lives here.
e
s 00011/00000/00000
d D 3.1 80/07/12 16:31:43 bill 1 0
c date and time created 80/07/12 16:31:43 by bill
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%G%	*/
E 6
I 6
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 10
 * Copyright (c) 1982 Regents of the University of California.
E 10
I 10
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9
E 6

/*
 * Limits for u.u_limit[i], per process, inherited.
 */
#define	LIM_NORAISE	0	/* if <> 0, can't raise limits */
#define	LIM_CPU		1	/* max secs cpu time */
#define	LIM_FSIZE	2	/* max size of file created */
#define	LIM_DATA	3	/* max growth of data space */
#define	LIM_STACK	4	/* max growth of stack */
#define	LIM_CORE	5	/* max size of ``core'' file */
I 7
#define	LIM_MAXRSS	6	/* max desired data+stack core usage */
E 7
I 2

I 3
D 7
#define	NLIMITS		5
E 7
I 7
#define	NLIMITS		6
E 7

E 3
#define	INFINITY	0x7fffffff
E 2
E 1
