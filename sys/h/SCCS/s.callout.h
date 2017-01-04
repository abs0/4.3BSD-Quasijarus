h12604
s 00001/00001/00027
d D 7.1 86/06/04 23:20:16 mckusick 11 10
c 4.3BSD release version
e
s 00007/00001/00021
d D 6.2 85/06/08 14:54:48 mckusick 10 9
c Add copyright
e
s 00000/00000/00022
d D 6.1 83/07/29 06:11:48 sam 9 8
c 4.2 distribution
e
s 00003/00003/00019
d D 4.6 81/04/18 11:33:20 wnj 8 7
c switch to linked lists
e
s 00002/00002/00020
d D 4.5 81/03/09 00:26:40 wnj 7 6
c lint
e
s 00003/00003/00019
d D 4.4 81/02/27 02:38:17 wnj 6 5
c dynamic alloc kernel version
e
s 00004/00001/00018
d D 4.3 81/02/27 00:03:23 wnj 5 4
c go to pointer basis
e
s 00001/00001/00018
d D 4.2 81/02/19 21:39:15 wnj 4 3
c %G%->%E%
e
s 00000/00000/00019
d D 4.1 80/11/09 17:00:38 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00018
d D 3.2 80/06/07 02:56:14 bill 2 1
c %H%->%G%
e
s 00019/00000/00000
d D 3.1 80/04/09 16:23:21 bill 1 0
c date and time created 80/04/09 16:23:21 by bill
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
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
/*
D 11
 * Copyright (c) 1982 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 10
E 4
E 2

/*
 * The callout structure is for
 * a routine arranging
 * to be called by the clock interrupt
 * (clock.c) with a specified argument,
 * in a specified amount of time.
 * Used, for example, to time tab
 * delays on typewriters.
 */

D 6
struct	callo
E 6
I 6
D 8
struct	callout
E 6
{
E 8
I 8
struct	callout {
E 8
	int	c_time;		/* incremental time */
	caddr_t	c_arg;		/* argument to routine */
	int	(*c_func)();	/* routine */
I 8
	struct	callout *c_next;
E 8
};
D 5
struct	callo	callout[NCALL];
E 5
I 5
#ifdef KERNEL
D 6
extern	struct callo *callout;
extern	int ncallo;
E 6
I 6
D 7
extern	struct callout *callout;
extern	int ncallout;
E 7
I 7
D 8
struct	callout *callout;
E 8
I 8
struct	callout *callfree, *callout, calltodo;
E 8
int	ncallout;
E 7
E 6
#endif
E 5
E 1
