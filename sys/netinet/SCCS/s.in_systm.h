h07756
s 00010/00005/00030
d D 7.3 88/06/29 17:06:44 bostic 20 19
c install approved copyright notice
e
s 00008/00002/00027
d D 7.2 87/12/07 17:45:27 bostic 19 18
c use Berkeley specific header
e
s 00001/00001/00028
d D 7.1 86/06/05 00:26:38 mckusick 18 17
c 4.3BSD release version
e
s 00000/00004/00029
d D 6.3 85/08/26 14:45:43 karels 17 16
c not used from locore (obviously)
e
s 00007/00001/00026
d D 6.2 85/06/08 12:39:07 mckusick 16 15
c Add copyright
e
s 00000/00000/00027
d D 6.1 83/07/29 07:11:24 sam 15 14
c 4.2 distribution
e
s 00000/00023/00027
d D 4.14 82/10/09 05:45:23 wnj 14 13
c localize header files
e
s 00001/00010/00049
d D 4.13 82/06/24 22:17:09 sam 13 12
c splimp moved to asm.sed
e
s 00000/00012/00059
d D 4.12 82/06/20 00:54:04 sam 12 11
c purge COUNT stuff now that we can use gprof
e
s 00002/00001/00069
d D 4.11 82/05/31 17:16:54 sam 11 10
c make 3com hack conditional on configuration
e
s 00006/00002/00064
d D 4.10 82/04/20 14:02:49 sam 10 9
c make 3com kludge conditional
e
s 00001/00001/00065
d D 4.9 82/04/11 02:38:55 feldman 9 8
c raise splimp for ec hack (temporary)
e
s 00024/00006/00042
d D 4.8 82/03/19 01:49:09 wnj 8 7
c fix to use only one soft intr for net thereby fixing bug in raw sockets
e
s 00001/00000/00047
d D 4.7 81/11/29 21:59:31 wnj 7 6
c lint and interface cleanups
e
s 00006/00003/00041
d D 4.6 81/11/26 11:56:24 wnj 6 5
c before carry to ARPAVAX
e
s 00000/00016/00044
d D 4.5 81/11/20 00:46:39 wnj 5 4
c linted
e
s 00002/00004/00058
d D 4.4 81/11/18 15:37:00 wnj 4 3
c more cleanup
e
s 00001/00002/00061
d D 4.3 81/11/16 14:16:39 wnj 3 2
c more lint
e
s 00000/00005/00063
d D 4.2 81/11/15 12:59:30 wnj 2 1
c listing
e
s 00068/00000/00000
d D 4.1 81/11/08 16:29:20 wnj 1 0
c date and time created 81/11/08 16:29:20 by wnj
e
u
U
t
T
I 1
D 10
/* %M% %I% %E% */
E 10
I 10
D 16
/*	%M%	%I%	%E%	*/
E 16
I 16
/*
D 18
 * Copyright (c) 1982 Regents of the University of California.
E 18
I 18
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 18
D 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 19
I 19
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 20
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 20
I 20
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
E 20
E 19
 *
 *	%W% (Berkeley) %G%
 */
E 16
E 10

/*
 * Miscellaneous internetwork
 * definitions for kernel.
 */

I 8
D 17
#ifndef LOCORE
E 17
E 8
D 2
/* THESE SHOULD BE ELIMINATED */
#define	NCON		20		/* SHOULD BE DYNAMIC, NO LIMIT */
#define	NHOST		20		/* SHOULD BE SOME DYNAMIC LIMIT */
/* END SHOULD BE ELIMINATED */

E 2
/*
 * Network types.
 *
 * Internally the system keeps counters in the headers with the bytes
 * swapped so that VAX instructions will work on them.  It reverses
 * the bytes before transmission at each protocol level.  The n_ types
 * represent the types with the bytes in ``high-ender'' order.
 */
typedef u_short n_short;		/* short as received from the net */
typedef u_long	n_long;			/* long as received from the net */
D 6
typedef u_long	seq_t;			/* sequence number */
E 6

typedef	u_long	n_time;			/* ms since 00:00 GMT, byte rev */
I 8
D 17
#endif
E 17
E 8

D 14
/*
D 6
 * The network runs as a software interrupt process.
E 6
I 6
 * The internet code runs off software interrupts.
D 8
 * There is one software interrupt level for each IP layer protocol
 * (e.g. IP, PUP, etc), and each such interrupt traps to the lowest
 * level routine for that protocol.
E 8
 *
E 6
 * You can switch into the network by doing splnet() and return by splx().
 * The software interrupt level for the network is higher than the software
 * level for the clock (so you can enter the network in routines called
D 13
 * at timeout time).  Splimp is an ipl high enough to block all imps.
D 4
 * While manipulating the mbuf buffer pool you have to block imps since
 * allocation occurs at interrupt level.  (It would be easier to
 * use interlocked instructions, but we don't do this yet.)
E 4
I 4
 * While manipulating the mbuf buffer pool you have to block imps.
E 13
I 13
 * at timeout time).
E 13
E 4
 */
D 8
#define	splimp		spl5
D 6
#define	setsoftnet()	mtpr(SIRR, 12)
E 6
I 6
#define	setipintr()	mtpr(SIRR, 12)
I 7
#define	setrawintr()	mtpr(SIRR, 13)
E 8
I 8
D 13

E 8
E 7
E 6
/* splnet is defined in ../sys/asm.sed */
I 8
D 9
#define	splimp		spl5
E 9
I 9
D 10
#define	splimp		spl6	/* temporary hack, usually spl5 */
E 10
I 10
D 11
#ifdef ECHACK
E 11
I 11
#include "ec.h"
#if NEC > 0
E 11
#define	splimp		spl6
#else
#define	splimp		spl5
#endif
E 13
E 10
E 9
#define	setsoftnet()	mtpr(SIRR, 12)
E 8

I 8
/*
 * Each ``pup-level-1'' input queue has a bit in a ``netisr'' status
 * word which is used to de-multiplex a single software
 * interrupt used for scheduling the network code to calls
 * on the lowest level routine of each protocol.
 */
#define	NETISR_RAW	0		/* same as AF_UNSPEC */
#define	NETISR_IP	2		/* same as AF_INET */
#define	NETISR_NS	6		/* same as AF_NS */

#define	schednetisr(anisr)	{ netisr |= 1<<(anisr); setsoftnet(); }

E 14
D 17
#ifndef LOCORE
E 17
#ifdef KERNEL
D 14
int	netisr;				/* scheduling bits for network */
E 14
D 12
#endif


E 8
D 5
/*
 * Network statistics record.
 *
 * SHOULD BE KEPT PER INTERFACE, AND WITH CNT, RATE, SUM.
 */
struct	net_stat {
	int	imp_resets;		/* # times imp reset */
	int	imp_flushes;		/* # packets flushed by imp */
	int	imp_drops;		/* # msgs from imp no-one wants */
	int	m_drops;		/* # mbuf drops from lack of bufs */
	int	ip_badsum;		/* # bad ip checksums */
	int	t_badsum;		/* # bad tcp checksums */
	int	t_badsegs;		/* # bad tcp segments */
	int	t_unack;		/* # tcp segs placed on rcv_unack */
};

E 5
#ifdef	KERNEL
E 12
D 3
int	nnetpages;
extern	struct net_stat netstat;		/* net statistics block */
E 3
I 3
D 4
struct	net_stat netstat;		/* net statistics block */
E 4
I 4
n_time	iptime();
E 4
E 3
D 12
#endif

#ifdef KPROF
#include "../inet/count.h"
#define	COUNT(i)	nrcount[i]++
int	nrcount[NCOUNTERS+1];
#else
#define	COUNT(i)
E 12
I 8
D 17
#endif
E 17
E 8
#endif
E 1
