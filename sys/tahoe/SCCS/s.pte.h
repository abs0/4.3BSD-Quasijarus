h08868
s 00007/00001/00090
d D 7.1 88/05/21 18:36:14 karels 7 6
c bring up to revision 7 for tahoe release
e
s 00007/00001/00084
d D 1.6 88/05/02 20:22:12 karels 6 5
c add kvtopte, kvtophys
e
s 00001/00001/00084
d D 1.5 87/07/11 19:06:01 karels 5 4
c remove loop invariants from dirty()
e
s 00001/00001/00084
d D 1.4 87/06/06 13:15:41 mckusick 4 3
c camap is replaced by kmempt
e
s 00000/00008/00085
d D 1.3 86/01/17 00:21:59 sam 3 2
c allocate page tables for drivers at boot time
e
s 00010/00019/00083
d D 1.2 86/01/05 18:42:41 sam 2 1
c 1st working version
e
s 00102/00000/00000
d D 1.1 85/07/21 21:12:24 sam 1 0
c date and time created 85/07/21 21:12:24 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7
D 2
/*	Tahoe version, November 1982	*/
E 2

/*
 * Tahoe page table entry
 *
 * There are two major kinds of pte's: those which have ever existed (and are
 * thus either now in core or on the swap device), and those which have
 * never existed, but which will be filled on demand at first reference.
 * There is a structure describing each.  There is also an ancillary
 * structure used in page clustering.
 */

#ifndef LOCORE
struct pte
{
unsigned int	
		pg_v:1,			/* valid bit */
		pg_prot:4,		/* access control */
		pg_fod:1,		/* is fill on demand (=0) */
D 2
		pg_swapm:1,		/* must write back to swap */
E 2
I 2
		:1,			/* must write back to swap (unused) */
E 2
		pg_nc:1,		/* 'uncacheable page' bit */
		pg_m:1,			/* hardware maintained modified bit */
D 2
	/*	pg_u:1,			/* hardware maintained 'used' bit */
					/* Not implemented in this version */
		pg_vreadm:1,		/* modified since vread (ored with _m)*/
E 2
I 2
		pg_u:1,			/* hardware maintained 'used' bit */
E 2
		pg_pfnum:22;		/* core page frame number or 0 */
};
struct hpte
{
unsigned int	
		pg_high:10,		/* special for clustering */
		pg_pfnum:22;
};
struct fpte
{
unsigned int	
		pg_v:1,
		pg_prot:4,
		pg_fod:1,		/* is fill on demand (=1) */
		:1,
D 2
		pg_fileno:5,		/* file mapped from or TEXT or ZERO */
		pg_blkno:20;		/* file system block number */
E 2
I 2
		pg_fileno:1,		/* file mapped from or TEXT or ZERO */
		pg_blkno:24;		/* file system block number */
E 2
};
#endif

#define	PG_V		0x80000000
#define	PG_PROT		0x78000000 /* all protection bits  (dorit). */
#define	PG_FOD		0x04000000
#define	PG_SWAPM	0x02000000
#define PG_N		0x01000000 /* Non-cacheable */
#define	PG_M		0x00800000
D 2
/*  #define PG_U	0x00400000 /* NOT implemented now !!! */
#define PG_VREADM	0x00400000 /* Uses 'U' bit location !!! */
E 2
I 2
D 6
#define PG_U		0x00400000 /* not currently used */
E 6
I 6
#define PG_U		0x00400000
E 6
E 2
#define	PG_PFNUM	0x003fffff

D 2
#define	PG_FZERO	(NOFILE)
#define	PG_FTEXT	(NOFILE+1)
E 2
I 2
#define	PG_FZERO	0
#define	PG_FTEXT	1
E 2
#define	PG_FMAX		(PG_FTEXT)

#define	PG_NOACC	0
#define	PG_KR		0x40000000
#define	PG_KW		0x60000000
#define	PG_URKR		0x50000000
#define	PG_URKW		0x70000000
#define	PG_UW		0x78000000

/*
 * Pte related macros
 */
D 2
#define	dirty(pte)	((pte)->pg_fod == 0 && (pte)->pg_pfnum && \
			    ((pte)->pg_m || (pte)->pg_swapm))
E 2
I 2
D 5
#define	dirty(pte)	((pte)->pg_fod == 0 && (pte)->pg_pfnum && (pte)->pg_m)
E 5
I 5
#define	dirty(pte)	((pte)->pg_m)
I 6

/*
 * Kernel virtual address to page table entry and to physical address.
 */
#define	kvtopte(va) (&Sysmap[((int)(va) &~ KERNBASE) >> PGSHIFT])
#define	kvtophys(x) ((kvtopte(x)->pg_pfnum << PGSHIFT) | ((int)(x) & PGOFSET))
E 6
E 5
E 2

#ifndef LOCORE
#ifdef KERNEL
D 2
struct	pte *vtopte();

E 2
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
D 2
/*
extern	struct pte IOmap[];
*/
E 2
D 3
extern	struct pte VD0map[];
extern	struct pte VD1map[];
extern	struct pte VD2map[];
extern	struct pte VD3map[];
extern	struct pte UDmap[];
D 2
extern	struct pte CYmap[];
E 2
I 2
extern	struct pte CY0map[];
extern	struct pte CY1map[];
E 2
extern	struct pte XYmap[];
E 3
extern	struct pte mmap[];
extern	struct pte msgbufmap[];
D 4
extern	struct pte camap[];
E 4
I 4
extern	struct pte kmempt[], ekmempt[];
E 4
#endif
#endif
E 1
