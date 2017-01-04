h33883
s 00001/00001/00022
d D 7.1 86/06/05 00:47:36 mckusick 6 5
c 4.3BSD release version
e
s 00007/00001/00016
d D 6.2 85/06/08 13:45:29 mckusick 5 4
c Add copyright
e
s 00000/00000/00017
d D 6.1 83/07/29 07:21:06 sam 4 3
c 4.2 distribution
e
s 00001/00001/00016
d D 4.3 81/05/01 12:52:07 root 3 2
c typo
e
s 00000/00000/00017
d D 4.2 81/02/19 21:42:09 wnj 2 1
c %G%->%E%
e
s 00017/00000/00000
d D 4.1 81/02/19 21:34:23 wnj 1 0
c date and time created 81/02/19 21:34:23 by wnj
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * The restart parameter block, which is a page in (very) low
 * core which runs after a crash.  Currently, the restart
 * procedure takes a dump.
 */
struct rpb {
	struct	rpb *rp_selfref;	/* self-reference */
	int	(*rp_dumprout)();	/* routine to be called */
	long	rp_checksum;		/* checksum of 31 words of dumprout */
	long	rp_flag;		/* set to 1 when dumprout runs */
/* the dump stack grows from the end of the rpb page not to reach here */
};
#ifdef KERNEL
D 3
extern	struct rpb rbp;
E 3
I 3
extern	struct rpb rpb;
E 3
#endif
E 1
