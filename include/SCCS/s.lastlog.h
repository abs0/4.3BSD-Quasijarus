h45526
s 00007/00001/00006
d D 5.1 85/05/30 09:36:35 dist 3 2
c Add copyright
e
s 00001/00000/00006
d D 4.2 83/05/22 20:21:38 sam 2 1
c add remote host name as in utmp
e
s 00006/00000/00000
d D 4.1 83/05/03 13:48:01 sam 1 0
c date and time created 83/05/03 13:48:01 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

struct lastlog {
	time_t	ll_time;
	char	ll_line[8];
I 2
	char	ll_host[16];		/* same as in utmp */
E 2
};
E 1
