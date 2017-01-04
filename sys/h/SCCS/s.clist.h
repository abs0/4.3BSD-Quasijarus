h27167
s 00001/00001/00020
d D 7.1 86/06/04 23:20:23 mckusick 8 7
c 4.3BSD release version
e
s 00007/00001/00014
d D 6.2 85/06/08 14:54:57 mckusick 7 6
c Add copyright
e
s 00000/00000/00015
d D 6.1 83/07/29 06:11:51 sam 6 5
c 4.2 distribution
e
s 00002/00002/00013
d D 4.4 81/03/09 00:26:44 wnj 5 4
c lint
e
s 00006/00001/00009
d D 4.3 81/02/27 00:03:21 wnj 4 3
c go to pointer basis
e
s 00001/00001/00009
d D 4.2 81/02/19 21:39:19 wnj 3 2
c %G%->%E%
e
s 00000/00000/00010
d D 4.1 80/11/09 17:02:18 bill 2 1
c stamp for 4bsd
e
s 00010/00000/00000
d D 3.1 80/10/08 22:34:45 bill 1 0
c date and time created 80/10/08 22:34:45 by bill
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%G%	*/
E 3
I 3
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
E 3

/*
 * Raw structures for the character list routines.
 */
struct cblock {
	struct cblock *c_next;
	char	c_info[CBSIZE];
};
D 4
struct	cblock	cfree[];
E 4
I 4
#ifdef KERNEL
D 5
extern	struct	cblock *cfree;
extern	int nclist;
E 5
I 5
struct	cblock *cfree;
int	nclist;
E 5
struct	cblock *cfreelist;
int	cfreecount;
#endif
E 4
E 1
