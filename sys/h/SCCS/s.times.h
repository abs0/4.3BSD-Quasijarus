h15370
s 00001/00001/00016
d D 7.1 86/06/04 23:29:39 mckusick 7 6
c 4.3BSD release version
e
s 00007/00001/00010
d D 6.2 85/06/08 15:09:51 mckusick 6 5
c Add copyright
e
s 00000/00000/00011
d D 6.1 83/07/29 06:14:25 sam 5 4
c 4.2 distribution
e
s 00001/00001/00010
d D 4.2 81/02/19 21:42:28 wnj 4 3
c %G%->%E%
e
s 00000/00000/00011
d D 4.1 80/11/09 17:01:50 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00010
d D 3.2 80/06/07 03:01:16 bill 2 1
c %H%->%G%
e
s 00011/00000/00000
d D 3.1 80/04/09 16:25:34 bill 1 0
c date and time created 80/04/09 16:25:34 by bill
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
 * Structure returned by times()
 */
struct tms {
	time_t	tms_utime;		/* user time */
	time_t	tms_stime;		/* system time */
	time_t	tms_cutime;		/* user time, children */
	time_t	tms_cstime;		/* system time, children */
};
E 1
