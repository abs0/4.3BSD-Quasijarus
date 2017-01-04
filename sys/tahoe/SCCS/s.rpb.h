h09895
s 00007/00001/00016
d D 7.1 88/05/21 18:36:17 karels 2 1
c bring up to revision 7 for tahoe release
e
s 00017/00000/00000
d D 1.1 86/01/05 18:46:23 sam 1 0
c date and time created 86/01/05 18:46:23 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

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
extern	struct rpb rpb;
#endif
E 1
