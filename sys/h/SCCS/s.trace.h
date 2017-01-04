h22372
s 00001/00001/00085
d D 7.1 86/06/04 23:29:50 mckusick 13 12
c 4.3BSD release version
e
s 00007/00001/00079
d D 6.3 85/06/08 15:10:02 mckusick 12 11
c Add copyright
e
s 00004/00002/00076
d D 6.2 84/01/03 19:45:25 sam 11 10
c pack buffer size into trace record for buffer cache
e
s 00000/00000/00078
d D 6.1 83/07/29 06:14:27 sam 10 9
c 4.2 distribution
e
s 00002/00000/00076
d D 4.9 82/05/31 19:11:02 mckusick 9 8
c move ifdef TRACE out of .c files and into trace.h where it belongs
e
s 00001/00000/00075
d D 4.8 81/07/25 20:59:16 wnj 8 7
c added TR_SWAPIO
e
s 00006/00000/00069
d D 4.7 81/04/18 11:50:04 wnj 7 6
c add stamp tracing
e
s 00005/00005/00064
d D 4.6 81/03/11 18:47:15 wnj 6 5
c new names for getting rid of EPAWNJ in bio.c
e
s 00003/00002/00066
d D 4.5 81/03/09 12:44:42 wnj 5 4
c fixups to get to compile
e
s 00010/00000/00058
d D 4.4 81/03/09 02:17:37 wnj 4 3
c minor trace fixups
e
s 00048/00011/00010
d D 4.3 81/03/03 12:39:31 wnj 3 2
c first crack at hagmann/terry version
e
s 00002/00000/00019
d D 4.2 81/02/19 21:42:35 wnj 2 1
c %G%->%E%
e
s 00019/00000/00000
d D 4.1 81/02/19 21:34:33 wnj 1 0
c date and time created 81/02/19 21:34:33 by wnj
e
u
U
t
T
I 2
D 12
/*	%M%	%I%	%E%	*/
E 12
I 12
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 12

E 2
I 1
D 3
#define	bit(a)		(1<<(a))
E 3
I 3
/*
D 11
 * File system buffer tracing points; all trace <dev, bn>
E 11
I 11
 * File system buffer tracing points; all trace <pack(dev, size), bn>
E 11
 */
D 6
#define	TR_BREAD	0	/* buffer read */
#define	TR_BWRITE	1	/* buffer written */
#define	TR_MISS		2	/* cache miss */
#define	TR_HIT		3	/* cache hit */
#define	TR_RA		4	/* read ahead */
E 6
I 6
#define	TR_BREADHIT	0	/* buffer read found in cache */
#define	TR_BREADMISS	1	/* buffer read not in cache */
#define	TR_BWRITE	2	/* buffer written */
#define	TR_BREADHITRA	3	/* buffer read-ahead found in cache */
#define	TR_BREADMISSRA	4	/* buffer read-ahead not in cache */
E 6
D 5
#define	TR_XFOD		5	/* exe fod read */
#define	TR_BRELSE	6	/* brelse */
E 5
I 5
#define	TR_XFODMISS	5	/* exe fod read */
#define	TR_XFODHIT	6	/* exe fod read */
#define	TR_BRELSE	7	/* brelse */
I 11
#define	TR_BREALLOC	8	/* expand/contract a buffer */
E 11
E 5
E 3

D 3
#define	TR_BREAD	bit(0)
#define	TR_BWRITE	bit(1)
#define	TR_MISS		bit(2)
#define	TR_HIT		bit(3)
#define	TR_RA		bit(4)
#define	TR_XFOD		bit(5)
#define	TR_BRELSE	bit(6)
#define	TR_MALL		bit(7)
E 3
I 3
/*
 * Memory allocator trace points; all trace the amount of memory involved
 */
#define	TR_MALL		10	/* memory allocated */
E 3

I 3
/*
 * Paging trace points: all are <vaddr, pid>
 */
#define	TR_INTRANS	20	/* page intransit block */
#define	TR_EINTRANS	21	/* page intransit wait done */
#define	TR_FRECLAIM	22	/* reclaim from free list */
#define	TR_RECLAIM	23	/* reclaim from loop */
#define	TR_XSFREC	24	/* reclaim from free list instead of drum */
#define	TR_XIFREC	25	/* reclaim from free list instead of fsys */
#define	TR_WAITMEM	26	/* wait for memory in pagein */
#define	TR_EWAITMEM	27	/* end memory wait in pagein */
#define	TR_ZFOD		28	/* zfod page fault */
#define	TR_EXFOD	29	/* exec fod page fault */
#define	TR_VRFOD	30	/* vread fod page fault */
#define	TR_CACHEFOD	31	/* fod in file system cache */
#define	TR_SWAPIN	32	/* drum page fault */
#define	TR_PGINDONE	33	/* page in done */
I 8
#define	TR_SWAPIO	34	/* swap i/o request arrives */
E 8

/*
 * System call trace points.
 */
#define	TR_VADVISE	40	/* vadvise occurred with <arg, pid> */

/*
I 7
 * Miscellaneous
 */
D 11
#define	TR_STAMP	50	/* user said vtrace(VTR_STAMP, value); */
E 11
I 11
#define	TR_STAMP	45	/* user said vtrace(VTR_STAMP, value); */
E 11

/*
E 7
 * This defines the size of the trace flags array.
 */
#define	TR_NFLAGS	100	/* generous */

E 3
#define	TRCSIZ		4096

I 4
/*
 * Specifications of the vtrace() system call, which takes one argument.
 */
#define	VTRACE		64+51

#define	VTR_DISABLE	0		/* set a trace flag to 0 */
#define	VTR_ENABLE	1		/* set a trace flag to 1 */
#define	VTR_VALUE	2		/* return value of a trace flag */
#define	VTR_UALARM	3		/* set alarm to go off (sig 16) */
					/* in specified number of hz */
I 7
#define	VTR_STAMP	4		/* user specified stamp */
E 7
E 4
D 3
#if defined(KERNEL) && defined(EPAWNJ)
E 3
I 3
#ifdef KERNEL
#ifdef TRACE
char	traceflags[TR_NFLAGS];
struct	proc *traceproc;
E 3
int	tracebuf[TRCSIZ];
unsigned tracex;
int	tracewhich;
I 11
#define	pack(a,b)	((a)<<16)|(b)
E 11
D 3
#define	trace(a,b,c)	if (tracewhich&(a)) trace1(a,b,c)
E 3
I 3
#define	trace(a,b,c)	if (traceflags[a]) trace1(a,b,c)
I 9
#else
#define	trace(a,b,b)	;
E 9
#endif
E 3
#endif
E 1
