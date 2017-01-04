h49468
s 00010/00005/00025
d D 7.2 88/06/29 17:34:30 bostic 5 4
c install approved copyright notice
e
s 00013/00001/00017
d D 7.1 88/05/21 18:35:00 karels 4 3
c bring up to revision 7 for tahoe release
e
s 00006/00000/00012
d D 1.3 86/12/06 22:34:33 sam 3 2
c set interval timer value at boot time according to hz
e
s 00002/00002/00010
d D 1.2 86/01/05 18:42:18 sam 2 1
c 1st working version
e
s 00012/00000/00000
d D 1.1 85/07/22 20:18:09 sam 1 0
c date and time created 85/07/22 20:18:09 by sam
e
u
U
t
T
I 1
D 2
/*	clock.h	4.5	81/02/23	*/
E 2
I 2
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 5
 *
 *	%W% (Berkeley) %G%
 */
E 4
E 2

#define	SECDAY		((unsigned)(24*60*60))		/* seconds per day */
#define	SECYR		((unsigned)(365*SECDAY))	/* per common year */

#define	YRREF		1970
#define	LEAPYEAR(year)	((year)%4==0)	/* good till time becomes negative */

/*
 * Software clock is software interrupt level 8
 */
D 2
#define	setsoftclock()	mtpr(0x8, SIRR)
E 2
I 2
#define	setsoftclock()	mtpr(SIRR, 0x8)
I 3

/*
 * To calculate value for interval timer register, we
 * use the fact that 20512 yields a 60hz clock.
 */
#define	hztocount(v)	((20512*60) / (v))
E 3
E 2
E 1
