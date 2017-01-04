h14566
s 00001/00001/00014
d D 7.1 86/06/05 01:13:40 mckusick 8 7
c 4.3BSD release version
e
s 00007/00001/00008
d D 6.2 85/06/08 14:18:26 mckusick 7 6
c Add copyright
e
s 00000/00000/00009
d D 6.1 83/07/29 07:28:13 sam 6 5
c 4.2 distribution
e
s 00002/00003/00007
d D 4.3 82/12/30 13:31:27 sam 5 4
c dz device structure changed
e
s 00001/00001/00009
d D 4.2 81/02/19 21:41:48 wnj 4 3
c %G%->%E%
e
s 00000/00000/00010
d D 4.1 80/11/09 17:01:26 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00009
d D 3.2 80/06/07 02:59:45 bill 2 1
c %H%->%G%
e
s 00010/00000/00000
d D 3.1 80/04/09 16:24:55 bill 1 0
c date and time created 80/04/09 16:24:55 by bill
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
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7
E 4
E 2

D 5
struct pdma
{
	struct	device *p_addr;
E 5
I 5
struct pdma {
	struct	dzdevice *p_addr;
E 5
	char	*p_mem;
	char	*p_end;
	int	p_arg;
	int	(*p_fcn)();
};
E 1
