h62404
s 00007/00001/00012
d D 5.1 85/05/30 09:42:17 dist 4 3
c Add copyright
e
s 00001/00000/00012
d D 4.2 83/05/22 19:22:53 sam 3 1
c add field for remote host name
e
s 00001/00000/00012
d R 4.2 83/05/22 19:13:41 sam 2 1
c add field for remote host name
e
s 00012/00000/00000
d D 4.1 83/05/03 13:48:22 sam 1 0
c date and time created 83/05/03 13:48:22 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

/*
 * Structure of utmp and wtmp files.
 *
 * Assuming the number 8 is unwise.
 */
struct utmp {
	char	ut_line[8];		/* tty name */
	char	ut_name[8];		/* user id */
I 3
	char	ut_host[16];		/* host name, if remote */
E 3
	long	ut_time;		/* time on */
};
E 1
