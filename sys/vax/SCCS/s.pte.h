h37251
s 00004/00000/00095
d D 7.5 04/03/18 19:23:58 msokolov 26 25
c add declarations for Babyvaxmap and vmbinfomap
e
s 00008/00007/00087
d D 7.4 88/05/02 20:25:42 karels 25 23
c add kvtopte, kvtophys; rm VAX630-specific maps
e
s 00000/00000/00094
d D 7.3.1.1 87/11/30 10:56:40 karels 24 23
x 21
c branch for tahoe release (no malloc)
e
s 00002/00003/00092
d D 7.3 87/07/11 19:05:48 karels 23 21
c remove loop invariants from dirty(); pg_swapm is gone
e
s 00002/00003/00092
d R 7.3 87/07/11 18:50:21 karels 22 21
c pg_swapm is gone
e
s 00001/00001/00094
d D 7.2 87/06/20 12:02:02 mckusick 21 20
c camap is replaced by kmempt
e
s 00001/00001/00094
d D 7.1 86/06/05 00:47:18 mckusick 20 19
c 4.3BSD release version
e
s 00004/00000/00091
d D 6.7 86/04/22 10:48:27 kridle 19 18
c Added MicroVAX II Support (KA630)
e
s 00001/00000/00090
d D 6.6 85/08/05 18:58:11 bloom 18 17
c add support for 8600
e
s 00007/00001/00083
d D 6.5 85/06/08 13:45:00 mckusick 17 16
c Add copyright
e
s 00002/00002/00082
d D 6.4 85/04/18 16:43:56 mckusick 16 15
c fileno only needs to be one bit now, so increase blkno in step with cmap
e
s 00002/00002/00082
d D 6.3 84/12/20 15:05:10 karels 15 14
c pg_fileno is just text or zero until VM redone (for >30 open files)
e
s 00000/00001/00084
d D 6.2 84/08/12 01:07:13 mckusick 14 13
c vtopte is now a macro
e
s 00000/00000/00085
d D 6.1 83/07/29 07:20:59 sam 13 12
c 4.2 distribution
e
s 00001/00000/00084
d D 4.9 81/05/14 17:43:01 root 12 11
c add PG_FOD
e
s 00000/00002/00084
d D 4.8 81/03/09 00:27:24 wnj 11 10
c lint
e
s 00001/00001/00085
d D 4.7 81/02/27 00:02:36 wnj 10 9
c dont give first dimension of Nexmap
e
s 00004/00000/00082
d D 4.6 81/02/23 20:52:25 wnj 9 8
c put in #ifndef LOCORE so can include in locore.s
e
s 00001/00001/00081
d D 4.5 81/02/19 21:41:59 wnj 8 7
c %G%->%E%
e
s 00001/00000/00081
d D 4.4 81/02/15 12:14:14 wnj 7 6
c bootable autoconf version
e
s 00001/00000/00080
d D 4.3 81/02/07 15:52:11 wnj 6 5
c calloc map
e
s 00001/00000/00079
d D 4.2 81/01/15 19:38:17 wnj 5 4
c added msgbufmap for new msgbuf saving
e
s 00000/00000/00079
d D 4.1 80/11/09 17:01:36 bill 4 3
c stamp for 4bsd
e
s 00001/00000/00078
d D 3.3 80/08/27 09:08:13 bill 3 2
c added bufmap
e
s 00001/00001/00077
d D 3.2 80/06/07 03:00:25 bill 2 1
c %H%->%G%
e
s 00078/00000/00000
d D 3.1 80/04/09 16:25:11 bill 1 0
c date and time created 80/04/09 16:25:11 by bill
e
u
U
f b 
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 8
/*	%M%	%I%	%G%	*/
E 8
I 8
D 17
/*	%M%	%I%	%E%	*/
E 17
I 17
/*
D 20
 * Copyright (c) 1982 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 17
E 8
E 2

/*
 * VAX page table entry
 *
 * There are two major kinds of pte's: those which have ever existed (and are
 * thus either now in core or on the swap device), and those which have
 * never existed, but which will be filled on demand at first reference.
 * There is a structure describing each.  There is also an ancillary
 * structure used in page clustering.
 */

I 9
#ifndef LOCORE
E 9
struct pte
{
unsigned int	pg_pfnum:21,		/* core page frame number or 0 */
		:2,
		pg_vreadm:1,		/* modified since vread (or with _m) */
D 23
		pg_swapm:1,		/* have to write back to swap */
E 23
I 23
		:1,
E 23
		pg_fod:1,		/* is fill on demand (=0) */
		pg_m:1,			/* hardware maintained modified bit */
		pg_prot:4,		/* access control */
		pg_v:1;			/* valid bit */
};
struct hpte
{
unsigned int	pg_pfnum:21,
		:2,
		pg_high:9;		/* special for clustering */
};
struct fpte
{
D 16
unsigned int	pg_blkno:20,		/* file system block number */
		pg_fileno:5,		/* file mapped from or TEXT or ZERO */
E 16
I 16
unsigned int	pg_blkno:24,		/* file system block number */
		pg_fileno:1,		/* file mapped from or TEXT or ZERO */
E 16
		pg_fod:1,		/* is fill on demand (=1) */
		:1,
		pg_prot:4,
		pg_v:1;
};
I 9
#endif
E 9

#define	PG_V		0x80000000
#define	PG_PROT		0x78000000
#define	PG_M		0x04000000
I 12
#define	PG_FOD		0x02000000
E 12
#define	PG_VREADM	0x00800000
#define	PG_PFNUM	0x001fffff

D 15
#define	PG_FZERO	(NOFILE)
#define	PG_FTEXT	(NOFILE+1)
E 15
I 15
#define	PG_FZERO	0
#define	PG_FTEXT	1
E 15
#define	PG_FMAX		(PG_FTEXT)

#define	PG_NOACC	0
#define	PG_KW		0x10000000
#define	PG_KR		0x18000000
#define	PG_UW		0x20000000
#define	PG_URKW		0x70000000
#define	PG_URKR		0x78000000

/*
 * Pte related macros
 */
D 23
#define	dirty(pte)	((pte)->pg_fod == 0 && (pte)->pg_pfnum && \
			    ((pte)->pg_m || (pte)->pg_swapm))
E 23
I 23
#define	dirty(pte)	((pte)->pg_m)
E 23

I 9
D 25
#ifndef LOCORE
E 9
#ifdef KERNEL
E 25
I 25
/*
 * Kernel virtual address to page table entry and to physical address.
 */
#define	kvtopte(va) (&Sysmap[((unsigned)(va) &~ KERNBASE) >> PGSHIFT])
#define	kvtophys(x) ((kvtopte(x)->pg_pfnum << PGSHIFT) | ((int)(x) & PGOFSET))
E 25
D 14
struct	pte *vtopte();
E 14

I 25
#if defined(KERNEL) && !defined(LOCORE)
E 25
/* utilities defined in locore.s */
extern	struct pte Sysmap[];
extern	struct pte Usrptmap[];
extern	struct pte usrpt[];
extern	struct pte Swapmap[];
extern	struct pte Forkmap[];
extern	struct pte Xswapmap[];
extern	struct pte Xswap2map[];
extern	struct pte Pushmap[];
extern	struct pte Vfmap[];
extern	struct pte mmap[];
D 11
extern	struct pte mcrmap[];
I 3
extern	struct pte bufmap[];
E 11
I 5
extern	struct pte msgbufmap[];
I 6
D 21
extern	struct pte camap[];
E 21
I 21
extern	struct pte kmempt[], ekmempt[];
E 21
I 7
D 10
extern	struct pte Nexmap[16][16];
E 10
I 10
extern	struct pte Nexmap[][16];
I 25
#if VAX8600
E 25
I 18
extern	struct pte Ioamap[][1];
I 19
D 25
#ifdef VAX630
extern	struct pte Clockmap[];
extern	struct pte Ka630map[];
E 25
#endif
I 26
#if NEED_BABYVAX_SUPPORT
extern	struct pte Babyvaxmap[];
#endif
extern	struct pte vmbinfomap[];
E 26
E 19
E 18
E 10
I 9
D 25
#endif
E 9
E 7
E 6
E 5
E 3
#endif
E 25
I 25
#endif /* defined(KERNEL) && !defined(LOCORE) */
E 25
E 1
