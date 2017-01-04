h25414
s 00001/00000/00049
d D 7.5 02/07/11 10:57:55 msokolov 12 11
c add PPPCTL software interrupt
e
s 00010/00005/00039
d D 7.4 88/06/27 18:59:36 bostic 11 10
c install approved copyright notice
e
s 00008/00002/00036
d D 7.3 87/12/30 11:57:33 bostic 10 9
c add Berkeley header
e
s 00001/00001/00037
d D 7.2 86/10/28 22:31:20 karels 9 8
c merge in tahoe
e
s 00001/00001/00037
d D 7.1 86/06/04 23:40:41 mckusick 8 7
c 4.3BSD release version
e
s 00001/00001/00037
d D 6.3 85/08/02 18:09:54 karels 7 6
c add IMP internal software interrupt, delete ND
e
s 00007/00001/00031
d D 6.2 85/06/08 12:26:32 mckusick 6 5
c Add copyright
e
s 00000/00000/00032
d D 6.1 83/07/29 07:08:41 sam 5 4
c 4.2 distribution
e
s 00001/00005/00031
d D 4.4 83/07/06 18:09:42 sam 4 3
c sun purge
e
s 00001/00000/00035
d D 4.3 83/01/17 15:53:03 sam 3 2
c add croft's stuff
e
s 00006/00000/00029
d D 4.2 82/10/31 14:57:46 root 2 1
c #if sun stuff
e
s 00029/00000/00000
d D 4.1 82/10/09 05:14:41 wnj 1 0
c date and time created 82/10/09 05:14:41 by wnj
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
D 8
 * Copyright (c) 1980 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1980, 1986 Regents of the University of California.
E 8
D 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 10
I 10
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 *
 *	%W% (Berkeley) %G%
 */
E 6

/*
 * The networking code runs off software interrupts.
 *
 * You can switch into the network by doing splnet() and return by splx().
 * The software interrupt level for the network is higher than the software
 * level for the clock (so you can enter the network in routines called
 * at timeout time).
 */
I 2
D 4
#if sun
#include "../sun/sir.h"
#define	setsoftnet()	siron(SIR_NET)
#else
/* #include "../vax/mtpr.h" */
E 4
I 4
D 9
#ifdef vax
E 9
I 9
#if defined(vax) || defined(tahoe)
E 9
E 4
E 2
#define	setsoftnet()	mtpr(SIRR, 12)
I 2
#endif
E 2

/*
 * Each ``pup-level-1'' input queue has a bit in a ``netisr'' status
 * word which is used to de-multiplex a single software
 * interrupt used for scheduling the network code to calls
 * on the lowest level routine of each protocol.
 */
#define	NETISR_RAW	0		/* same as AF_UNSPEC */
#define	NETISR_IP	2		/* same as AF_INET */
I 7
#define	NETISR_IMP	3		/* same as AF_IMPLINK */
E 7
#define	NETISR_NS	6		/* same as AF_NS */
I 12
#define	NETISR_PPPCTL	30
E 12
I 3
D 7
#define	NETISR_ND	7		/* network disk protocol */
E 7
E 3

#define	schednetisr(anisr)	{ netisr |= 1<<(anisr); setsoftnet(); }

#ifndef LOCORE
#ifdef KERNEL
int	netisr;				/* scheduling bits for network */
#endif
#endif
E 1
