h12451
s 00001/00001/00021
d D 7.1 86/06/05 00:43:34 mckusick 4 3
c 4.3BSD release version
e
s 00007/00001/00015
d D 6.2 85/06/08 13:42:09 mckusick 3 2
c Add copyright
e
s 00000/00000/00016
d D 6.1 83/07/29 07:19:52 sam 2 1
c 4.2 distribution
e
s 00016/00000/00000
d D 4.1 83/02/10 21:56:15 sam 1 0
c date and time created 83/02/10 21:56:15 by sam
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
D 4
 * Copyright (c) 1982 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

/*
 * Definition of the vax calls/callg frame.
 */
struct frame {
	int	fr_handler;
	u_int	fr_psw:16,		/* saved psw */
		fr_mask:12,		/* register save mask */
		:1,
		fr_s:1,			/* call was a calls, not callg */
		fr_spa:2;		/* stack pointer alignment */
	int	fr_savap;		/* saved arg pointer */
	int	fr_savfp;		/* saved frame pointer */
	int	fr_savpc;		/* saved program counter */
};
E 1
