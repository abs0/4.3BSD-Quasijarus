h33180
s 00007/00001/00155
d D 7.1 88/05/21 18:36:47 karels 9 8
c bring up to revision 7 for tahoe release
e
s 00002/00005/00154
d D 1.8 88/01/07 11:35:14 karels 8 7
c mapin works only with count of 1; avoid redundant conversions
c of "v" from bytes<=>pages
e
s 00001/00006/00158
d D 1.7 87/06/01 18:19:37 karels 7 6
c really, the kernel doesn't have to map all of memory
e
s 00001/00001/00163
d D 1.6 86/04/19 11:10:33 sam 6 5
c up max data seg size to 32 meg
e
s 00001/00001/00163
d D 1.5 86/04/11 13:50:59 sam 5 4
c increase max data size to 24Mb
e
s 00002/00014/00162
d D 1.4 86/01/20 23:52:37 sam 4 3
c cleanup some more of the autoconfig stuff: eliminate all page 
c maps defined in locore.s in favor of dynamically allocated entries; rename 
c some of the iospace definitions and move them into ../tahoevba/vbaparam.h 
c (will ease vme support sometime?)
e
s 00005/00005/00171
d D 1.3 86/01/12 15:38:48 sam 3 2
c 4.3- plus start of autoconfig
e
s 00065/00023/00111
d D 1.2 86/01/05 18:42:49 sam 2 1
c 1st working version
e
s 00134/00000/00000
d D 1.1 85/07/22 20:15:48 sam 1 0
c date and time created 85/07/22 20:15:48 by sam
e
u
U
t
T
I 1
D 2
/*	vmparam.h	1.3	5/25/85	*/
/*	vmparam.h	6.1	83/07/29	*/
E 2
I 2
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9
E 2

/*
D 4
 * Machine dependent constants for TAHOE
E 4
I 4
 * Machine dependent constants for tahoe.
E 4
 */
I 4

E 4
/*
 * USRTEXT is the start of the user text/data space, while USRSTACK
 * is the top (end) of the user stack.  LOWPAGES and HIGHPAGES are
 * the number of pages from the beginning of the P0 region to the
 * beginning of the text and from the beginning of the P2 region to the
 * beginning of the stack respectively.
 */
D 2
					/* number of ptes per page */
E 2
#define	USRTEXT		0
D 2
#define	USRSTACK	(0xC0000000-UPAGES*NBPG)
					/* Start of user stack */
E 2
I 2
#define	USRSTACK	(0xc0000000-UPAGES*NBPG) /* Start of user stack */
#define	BTOPUSRSTACK	(0x300000 - UPAGES)	 /* btop(USRSTACK) */
E 2
#define	P2PAGES		0x100000	/* number of pages in P2 region */
#define	LOWPAGES	0
#define	HIGHPAGES	UPAGES

/*
D 2
 * Virtual memory related constants
E 2
I 2
D 3
 * Virtual memory related constants, all in clicks
E 3
I 3
 * Virtual memory related constants, all in bytes
E 3
E 2
 */
D 2
#define	SLOP	32
#define	MAXTSIZ		(6*1024-SLOP)		/* max text size (clicks) */
#define	MAXDSIZ		(19*2048-32-SLOP)	/* max data size (clicks) */
#define	MAXSSIZ		(19*2048-32-SLOP)	/* max stack size (clicks) */
E 2
I 2
D 3
#define	MAXTSIZ		(6*CLSIZE*1024)		/* max text size */
E 3
I 3
#define	MAXTSIZ		(6*1024*1024)		/* max text size */
E 3
#ifndef DFLDSIZ
D 3
#define	DFLDSIZ		(6*1024*1024/NBPG)	/* initial data size limit */
E 3
I 3
#define	DFLDSIZ		(6*1024*1024)		/* initial data size limit */
E 3
#endif
#ifndef MAXDSIZ
D 3
#define	MAXDSIZ		(19*1024*1024/NBPG)	/* max data size */
E 3
I 3
D 5
#define	MAXDSIZ		(16*1024*1024)		/* max data size */
E 5
I 5
D 6
#define	MAXDSIZ		(24*1024*1024)		/* max data size */
E 6
I 6
#define	MAXDSIZ		(32*1024*1024)		/* max data size */
E 6
E 5
E 3
#endif
#ifndef	DFLSSIZ
D 3
#define	DFLSSIZ		(512*1024/NBPG)		/* initial stack size limit */
E 3
I 3
#define	DFLSSIZ		(512*1024)		/* initial stack size limit */
E 3
#endif
#ifndef	MAXSSIZ
#define	MAXSSIZ		MAXDSIZ			/* max stack size */
#endif
E 2

/*
I 2
 * Default sizes of swap allocation chunks (see dmap.h).
 * The actual values may be changed in vminit() based on MAXDSIZ.
 * With MAXDSIZ of 16Mb and NDMAP of 38, dmmax will be 1024.
 */
#define	DMMIN	32			/* smallest swap allocation */
#define	DMMAX	4096			/* largest potential swap allocation */
#define	DMTEXT	1024			/* swap allocation for text */

/*
E 2
 * Sizes of the system and user portions of the system page table.
 */
/* SYSPTSIZE IS SILLY; IT SHOULD BE COMPUTED AT BOOT TIME */
D 2
#define	SYSPTSIZE	((30+MAXUSERS)*NPTEPG/4)
#define	USRPTSIZE 	(2*NPTEPG)
E 2
I 2
D 7
#ifdef notdef
#define	SYSPTSIZE	((20+MAXUSERS)*NPTEPG)
#define	USRPTSIZE 	(32*NPTEPG)
#else
#define	SYSPTSIZE	((128*NPTEPG/2)+(MAXUSERS*NPTEPG/16))
E 7
I 7
#define	SYSPTSIZE	((20+MAXUSERS/2)*NPTEPG)
E 7
#define	USRPTSIZE 	(4*NPTEPG)
D 7
#endif
E 7
E 2

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
D 2
#define	SAFERSS		16		/* nominal ``small'' resident set size
E 2
I 2
#define	SAFERSS		32		/* nominal ``small'' resident set size
E 2
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

/*
 * Paging thresholds (see vm_sched.c).
D 2
 * Strategy of 4/22/81:
 *	lotsfree is 1/4 of memory free.
E 2
I 2
 * Strategy of 1/19/85:
 *	lotsfree is 512k bytes, but at most 1/4 of memory
E 2
 *	desfree is 200k bytes, but at most 1/8 of memory
 *	minfree is 64k bytes, but at most 1/2 of desfree
 */
I 2
#define	LOTSFREE	(512 * 1024)
E 2
#define	LOTSFREEFRACT	4
#define	DESFREE		(200 * 1024)
#define	DESFREEFRACT	8
#define	MINFREE		(64 * 1024)
#define	MINFREEFRACT	2

/*
I 2
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
E 2
 * Believed threshold (in megabytes) for which interleaved
 * swapping area is desirable.
 */
#define	LOTSOFMEM	2

D 8
/*
 * BEWARE THIS DEFINITION WORKS ONLY WITH COUNT OF 1
 */
#define	mapin(pte, v, pfnum, count, prot) \
D 2
	(*(int *)(pte) = (pfnum) | (prot), mtpr(ptob(v), TBIS))
E 2
I 2
	(*(int *)(pte) = (pfnum) | (prot), mtpr(TBIS, ptob(v)))
E 8
I 8
#define	mapin(pte, v, pfnum, prot) \
	(*(int *)(pte) = (pfnum) | (prot), mtpr(TBIS, v))
E 8
E 2

I 2
/*
 * Invalidate a cluster (optimized here for standard CLSIZE).
 */
#if CLSIZE == 1
#define	tbiscl(v)	mtpr(TBIS, ptob(v))
#endif
D 4

E 2
/* 
 * The following constant is used to initialize the map of the
 * system page table i/o entries.
 * It's value should be the highest i/o address used by all the 
 * controllers handled in the system as specified in ubminit 
 * structure in ioconf.c.
D 2
*/
#define MAXIOADDR 0xffffee45	/* highest physical io address */

/* Number of entries in the system page pable for i/o space */
#define IOSIZE	(( (MAXIOADDR - IOBASE+ NBPG -1) >> PGSHIFT )+1)
#define TBUFSIZ	10		/* maximum tape buffer size */
#define	ACEBPTE	32		/* ACC Ethernet (ACE) I/O window	*/
E 2
I 2
 */
#define MAXIOADDR	0xffffee45
/* number of entries in the system page pable for i/o space */
#define IOSIZE		(((MAXIOADDR - (int)IOBASE+ NBPG-1) >> PGSHIFT)+1)
#define TBUFSIZ		32		/* maximum tape buffer size */
#define	ACEBPTE		32		/* ACC Ethernet (ACE) I/O window */
E 4
E 2
E 1
