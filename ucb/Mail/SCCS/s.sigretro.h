h36832
s 00008/00002/00022
d D 5.2 88/02/18 17:04:25 bostic 3 2
c written by Kurt Shoens; added Berkeley specific header
e
s 00007/00001/00017
d D 5.1 85/06/06 10:48:34 dist 2 1
c Add copyright
e
s 00018/00000/00000
d D 4.1 83/08/11 22:12:35 sam 1 0
c date and time created 83/08/11 22:12:35 by sam
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
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
 *
 *	%W% (Berkeley) %G%
 */
E 2

/*
 * Define extra stuff not found in signal.h
 */

#ifndef SIGRETRO

#define	SIGRETRO				/* Can use this for cond code */

#ifndef SIG_HOLD

#define	SIG_HOLD	(int (*)()) 3		/* Phony action to hold sig */
#define	BADSIG		(int (*)()) -1		/* Return value on error */

#endif SIG_HOLD

#endif SIGRETRO
E 1
