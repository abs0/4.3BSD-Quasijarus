h51822
s 00001/00000/00157
d D 7.3 02/09/15 00:51:21 msokolov 17 16
c add P1LOW define
e
s 00002/00005/00155
d D 7.2 87/11/30 10:58:30 karels 16 15
c remove unused count from mapin
e
s 00001/00001/00159
d D 7.1 86/06/05 00:50:24 mckusick 15 14
c 4.3BSD release version
e
s 00007/00005/00153
d D 6.7 85/10/23 18:16:51 karels 14 13
c {MAX,DFL}{T,D,S}SIZ now all in bytes
e
s 00007/00001/00151
d D 6.6 85/06/08 13:47:52 mckusick 13 12
c Add copyright
e
s 00022/00006/00130
d D 6.5 85/03/07 21:57:06 karels 12 11
c more flexible parameters, allow options MAXDSIZ to set VM config
e
s 00014/00000/00122
d D 6.4 85/03/07 18:38:54 mckusick 11 10
c Add a second hand to the clock algorithm. The front hand clears the
c reference bit, the back hand frees pages that are still unreferenced.
e
s 00003/00002/00119
d D 6.3 85/03/07 18:36:31 mckusick 10 9
c lotsfree is now 512KB but at most 1/4 of memory
e
s 00003/00003/00118
d D 6.2 84/08/12 01:08:38 mckusick 9 8
c add constant BTOPUSRSTACK == btop(USRSTACK) as optimizer cannot fold it
e
s 00000/00000/00121
d D 6.1 83/07/29 07:21:46 sam 8 7
c 4.2 distribution
e
s 00001/00001/00120
d D 4.5 83/06/29 18:06:14 root 7 6
c size SYSPTSIZE on MAXUSERS
e
s 00006/00000/00115
d D 4.4 83/06/14 23:48:12 sam 6 4
c macro definition for mapin (BEWARE, expects count=1)
e
s 00006/00000/00115
d R 4.4 83/06/14 23:38:19 sam 5 4
c questionable, but make mapin a macro since it used to be a 
c simple assignment statement (ought to look at how much this buys us)
e
s 00019/00000/00096
d D 4.3 83/06/14 22:58:25 sam 4 2
c cleanup
e
s 00001/00001/00095
d R 4.3 83/02/21 22:23:45 sam 3 2
c make SYSPTSIZE based on MAXUSERS to increase size of buffer pool
e
s 00001/00001/00095
d D 4.2 82/11/13 22:59:21 sam 2 1
c merge of 4.1b with 4.1c
e
s 00096/00000/00000
d D 4.1 82/11/09 11:28:29 sam 1 0
c date and time created 82/11/09 11:28:29 by sam
e
u
U
t
T
I 1
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
/*
D 15
 * Copyright (c) 1982 Regents of the University of California.
E 15
I 15
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 13

/*
 * Machine dependent constants for VAX
 */
/*
 * USRTEXT is the start of the user text/data space, while USRSTACK
 * is the top (end) of the user stack.  LOWPAGES and HIGHPAGES are
 * the number of pages from the beginning of the P0 region to the
 * beginning of the text and from the beginning of the P1 region to the
 * beginning of the stack respectively.
 */
D 9
					/* number of ptes per page */
E 9
#define	USRTEXT		0
I 17
#define	P1LOW		0x40000000		 /* lowest address in P1 */
E 17
D 9
#define	USRSTACK	(0x80000000-UPAGES*NBPG)
					/* Start of user stack */
E 9
I 9
#define	USRSTACK	(0x80000000-UPAGES*NBPG) /* Start of user stack */
#define	BTOPUSRSTACK	(0x400000 - UPAGES)	 /* btop(USRSTACK) */
/* number of ptes per page */
E 9
#define	P1PAGES		0x200000	/* number of pages in P1 region */
#define	LOWPAGES	0
#define	HIGHPAGES	UPAGES

/*
D 12
 * Virtual memory related constants
E 12
I 12
D 14
 * Virtual memory related constants, all in clicks
E 14
I 14
 * Virtual memory related constants, all in bytes
E 14
E 12
 */
D 12
#define	SLOP	32
#define	MAXTSIZ		(6*2048-SLOP)		/* max text size (clicks) */
E 12
I 12
D 14
#define	MAXTSIZ		(6*CLSIZE*1024)		/* max text size */
E 14
I 14
#ifndef MAXTSIZ
#define	MAXTSIZ		(6*1024*1024)		/* max text size */
#endif
E 14
#ifndef DFLDSIZ
D 14
#define	DFLDSIZ		(6*1024*1024/NBPG)	/* initial data size limit */
E 14
I 14
#define	DFLDSIZ		(6*1024*1024)		/* initial data size limit */
E 14
#endif
E 12
#ifndef MAXDSIZ
D 12
#define	MAXDSIZ		(12*1024-32-SLOP)	/* max data size (clicks) */
E 12
I 12
D 14
#define	MAXDSIZ		(16*1024*1024/NBPG)	/* max data size */
E 14
I 14
#define	MAXDSIZ		(16*1024*1024)		/* max data size */
E 14
E 12
#endif
D 12
#define	MAXSSIZ		(12*1024-32-SLOP)	/* max stack size (clicks) */
E 12
I 12
#ifndef	DFLSSIZ
D 14
#define	DFLSSIZ		(512*1024/NBPG)		/* initial stack size limit */
E 14
I 14
#define	DFLSSIZ		(512*1024)		/* initial stack size limit */
E 14
#endif
#ifndef	MAXSSIZ
#define	MAXSSIZ		MAXDSIZ			/* max stack size */
#endif
E 12

/*
I 12
 * Default sizes of swap allocation chunks (see dmap.h).
 * The actual values may be changed in vminit() based on MAXDSIZ.
 * With MAXDSIZ of 16Mb and NDMAP of 38, dmmax will be 1024.
 */
#define	DMMIN	32			/* smallest swap allocation */
#define	DMMAX	4096			/* largest potential swap allocation */
#define	DMTEXT	1024			/* swap allocation for text */

/*
E 12
 * Sizes of the system and user portions of the system page table.
 */
/* SYSPTSIZE IS SILLY; IT SHOULD BE COMPUTED AT BOOT TIME */
D 2
#define	SYSPTSIZE	(12*NPTEPG)
E 2
I 2
D 7
#define	SYSPTSIZE	(35*NPTEPG)
E 7
I 7
#define	SYSPTSIZE	((20+MAXUSERS)*NPTEPG)
E 7
E 2
D 12
#define	USRPTSIZE 	(8*NPTEPG)
E 12
I 12
#define	USRPTSIZE 	(32*NPTEPG)
E 12

/*
 * The size of the clock loop.
 */
#define	LOOPPAGES	(maxfree - firstfree)

/*
 * The time for a process to be blocked before being very swappable.
 * This is a number of seconds which the system takes as being a non-trivial
 * amount of real time.  You probably shouldn't change this;
 * it is used in subtle ways (fractions and multiples of it are, that is, like
 * half of a ``long time'', almost a long time, etc.)
 * It is related to human patience and other factors which don't really
 * change over time.
 */
#define	MAXSLP 		20

/*
 * A swapped in process is given a small amount of core without being bothered
 * by the page replacement algorithm.  Basically this says that if you are
 * swapped in you deserve some resources.  We protect the last SAFERSS
 * pages against paging and will just swap you out rather than paging you.
 * Note that each process has at least UPAGES+CLSIZE pages which are not
 * paged anyways (this is currently 8+2=10 pages or 5k bytes), so this
 * number just means a swapped in process is given around 25k bytes.
 * Just for fun: current memory prices are 4600$ a megabyte on VAX (4/22/81),
 * so we loan each swapped in process memory worth 100$, or just admit
 * that we don't consider it worthwhile and swap it out to disk which costs
 * $30/mb or about $0.75.
 */
#define	SAFERSS		32		/* nominal ``small'' resident set size
					   protected against replacement */

/*
 * DISKRPM is used to estimate the number of paging i/o operations
 * which one can expect from a single disk controller.
 */
#define	DISKRPM		60

/*
 * Klustering constants.  Klustering is the gathering
 * of pages together for pagein/pageout, while clustering
 * is the treatment of hardware page size as though it were
 * larger than it really is.
 *
 * KLMAX gives maximum cluster size in CLSIZE page (cluster-page)
 * units.  Note that KLMAX*CLSIZE must be <= DMMIN in dmap.h.
 */

#define	KLMAX	(32/CLSIZE)
#define	KLSEQL	(16/CLSIZE)		/* in klust if vadvise(VA_SEQL) */
#define	KLIN	(8/CLSIZE)		/* default data/stack in klust */
#define	KLTXT	(4/CLSIZE)		/* default text in klust */
#define	KLOUT	(32/CLSIZE)

/*
 * KLSDIST is the advance or retard of the fifo reclaim for sequential
 * processes data space.
 */
#define	KLSDIST	3		/* klusters advance/retard for seq. fifo */
I 4

/*
 * Paging thresholds (see vm_sched.c).
D 10
 * Strategy of 4/22/81:
 *	lotsfree is 1/4 of memory free.
E 10
I 10
 * Strategy of 1/19/85:
 *	lotsfree is 512k bytes, but at most 1/4 of memory
E 10
 *	desfree is 200k bytes, but at most 1/8 of memory
 *	minfree is 64k bytes, but at most 1/2 of desfree
 */
I 10
#define	LOTSFREE	(512 * 1024)
E 10
#define	LOTSFREEFRACT	4
#define	DESFREE		(200 * 1024)
#define	DESFREEFRACT	8
#define	MINFREE		(64 * 1024)
#define	MINFREEFRACT	2

/*
I 11
 * There are two clock hands, initially separated by HANDSPREAD bytes
 * (but at most all of user memory).  The amount of time to reclaim
 * a page once the pageout process examines it increases with this
 * distance and decreases as the scan rate rises.
 */
#define	HANDSPREAD	(2 * 1024 * 1024)

/*
 * The number of times per second to recompute the desired paging rate
 * and poke the pagedaemon.
 */
#define	RATETOSCHEDPAGING	4

/*
E 11
 * Believed threshold (in megabytes) for which interleaved
 * swapping area is desirable.
 */
#define	LOTSOFMEM	2
I 6

D 16
/*
 * BEWARE THIS DEFINITION WORKS ONLY WITH COUNT OF 1
 */
#define	mapin(pte, v, pfnum, count, prot) \
	(*(int *)(pte) = (pfnum) | (prot), mtpr(TBIS, ptob(v)))
E 16
I 16
#define	mapin(pte, v, pfnum, prot) \
	(*(int *)(pte) = (pfnum) | (prot), mtpr(TBIS, v))
E 16
E 6
E 4
E 1
