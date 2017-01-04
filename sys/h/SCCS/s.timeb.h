h08968
s 00001/00001/00017
d D 7.1 86/06/04 23:29:30 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00011
d D 6.2 85/06/08 15:09:43 mckusick 6 5
c Add copyright
e
s 00000/00000/00012
d D 6.1 83/07/29 06:14:23 sam 5 4
c 4.2 distribution
e
s 00001/00001/00011
d D 4.2 81/02/19 21:42:25 wnj 4 3
c %G%->%E%
e
s 00000/00000/00012
d D 4.1 80/11/09 17:01:48 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00011
d D 3.2 80/06/07 03:01:09 bill 2 1
c %H%->%G%
e
s 00012/00000/00000
d D 3.1 80/04/09 16:25:30 bill 1 0
c date and time created 80/04/09 16:25:30 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 4
/*	%M%	%I%	%G%	*/
E 4
I 4
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
E 4
E 2

/*
 * Structure returned by ftime system call
 */
struct timeb
{
	time_t	time;
	unsigned short millitm;
	short	timezone;
	short	dstflag;
};
E 1
