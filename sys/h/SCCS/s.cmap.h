h39642
s 00001/00001/00085
d D 7.1 86/06/04 23:20:34 mckusick 18 17
c 4.3BSD release version
e
s 00005/00003/00081
d D 6.8 86/06/02 16:31:35 karels 17 16
c correct instructions on increasing physical memory limit
e
s 00002/00002/00082
d D 6.7 86/05/30 17:33:34 karels 16 15
c unsigned some more, bigger hash table as usual
e
s 00007/00001/00077
d D 6.6 85/06/08 14:55:11 mckusick 15 14
c Add copyright
e
s 00009/00010/00069
d D 6.5 85/03/19 18:17:07 karels 14 13
c use the unused bits
e
s 00001/00001/00078
d D 6.4 84/08/03 19:23:06 mckusick 13 12
c avoid an unnecessary unsigned division
e
s 00033/00008/00046
d D 6.3 84/02/07 17:42:13 karels 12 11
c raise memory, mounted filesystem limits
e
s 00002/00000/00052
d D 6.2 83/09/24 23:17:19 karels 11 10
c offsets also in locore.s
e
s 00000/00000/00052
d D 6.1 83/07/29 06:11:53 sam 10 9
c 4.2 distribution
e
s 00002/00003/00050
d D 4.5 81/03/09 00:26:47 wnj 9 8
c lint
e
s 00001/00000/00052
d D 4.4 81/02/27 02:38:34 wnj 8 7
c dynamic alloc kernel version
e
s 00000/00002/00052
d D 4.3 81/02/26 04:30:28 wnj 7 6
c cosmetics
e
s 00001/00001/00053
d D 4.2 81/02/19 21:39:33 wnj 6 5
c %G%->%E%
e
s 00000/00000/00054
d D 4.1 80/11/09 17:00:42 bill 5 4
c stamp for 4bsd
e
s 00024/00017/00030
d D 3.4 80/07/12 17:00:12 bill 4 3
c back to 12 bytes
e
s 00010/00001/00037
d D 3.3 80/07/11 08:22:52 bill 3 2
c with <hlink,mdev>
e
s 00001/00001/00037
d D 3.2 80/06/07 02:56:33 bill 2 1
c %H%->%G%
e
s 00038/00000/00000
d D 3.1 80/04/09 16:23:28 bill 1 0
c date and time created 80/04/09 16:23:28 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 6
/*	%M%	%I%	%G%	*/
E 6
I 6
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
/*
D 18
 * Copyright (c) 1982 Regents of the University of California.
E 18
I 18
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 15
E 6
E 2

/*
 * core map entry
I 11
D 12
 * Note that offsets in this structure are also known
 * in Fastreclaim (vax/locore.s).
E 12
I 12
 *
 * Limits imposed by this structure:
 *
 *		limit		     cur. size		fields
D 17
 *	Physical memory+		64 Mb	c_next, c_prev, c_hlink
E 17
I 17
 *	Physical memory*		64 Mb	c_next, c_prev, c_hlink
E 17
 *	Mounted filesystems		255	c_mdev
 *	size of a process segment	1 Gb	c_page
D 14
 *	filesystem size			2 Gb	c_blkno
 *	proc, text table size		1024	c_ndx
E 14
I 14
 *	filesystem size			8 Gb	c_blkno
 *	proc, text table size		64K	c_ndx
E 14
 *
D 17
 *	+ memory can be expanded by converting first three entries
D 14
 *	to bit fields, shrinking c_unused, and increasing MAXMEM below.
E 14
I 14
 *	to bit fields, shrinking c_ndx, and increasing MAXMEM below.
E 17
I 17
 *	* memory can be expanded by converting first three entries
 *	to bit fields of larger than 16 bits, shrinking c_ndx accordingly,
 *	and increasing MAXMEM below.  Also, the type of cmhash
 *	(below) must be changed to long.
E 17
E 14
E 12
E 11
D 7
 *
 * NB: THE SIZE OF THIS STRUCTURE IS WELL KNOWN IN cmap.m
E 7
 */
I 12
#ifndef	LOCORE
E 12
struct cmap
{
D 4
unsigned int 	c_next:14,	/* index of next free list entry */
		c_page:17,	/* virtual page number in segment */
E 4
I 4
D 12
unsigned int 	c_next:13,	/* index of next free list entry */
		c_prev:13,	/* index of previous free list entry */
		c_mdev:4,	/* which mounted dev this is from */
E 12
I 12
unsigned short 	c_next,		/* index of next free list entry */
		c_prev,		/* index of previous free list entry */
		c_hlink;	/* hash link for <blkno,mdev> */
D 14
unsigned char	c_unused;	/* fill, expansion for above */
unsigned int	c_mdev:8,	/* which mounted dev this is from */
E 14
I 14
unsigned short	c_ndx;		/* index of owner proc or text */
unsigned int	c_page:21,	/* virtual page number in segment */
E 14
E 12
		c_lock:1,	/* locked for raw i/o or pagein */
		c_want:1,	/* wanted */
D 12
		c_page:16,	/* virtual page number in segment */
		c_hlink:13,	/* hash link for <blkno,mdev> */
E 12
E 4
		c_intrans:1,	/* intransit bit */
D 4
		c_prev:14,	/* index of previous free list entry */
		c_ndx:10,	/* index of owner proc or text */
D 3
		c_flag:8;	/* flags */
E 3
I 3
		c_flag:8,	/* flags */
E 4
I 4
		c_free:1,	/* on the free list */
		c_gone:1,	/* associated page has been released */
		c_type:2,	/* type CSYS or CTEXT or CSTACK or CDATA */
E 4
D 12
		c_blkno:20,	/* disk block this is a copy of */
E 12
I 12
D 14
		c_page:21,	/* virtual page number in segment */
E 14
		:4,		/* to longword boundary */
D 14
		c_blkno:22,	/* disk block this is a copy of */
E 12
D 4
		c_mdev:4,	/* which mounted dev this is from */
		c_hlink:14;	/* hash link for <blkno,mdev> */
E 4
I 4
		c_ndx:10;	/* index of owner proc or text */
E 14
I 14
		c_blkno:24,	/* disk block this is a copy of */
		c_mdev:8;	/* which mounted dev this is from */
E 14
E 4
E 3
};
I 12
#else	LOCORE
/*
 * bit offsets of elements in cmap
 */
D 14
#define	C_INTRANS	66
#define	C_FREE		67
E 14
I 14
#define	C_INTRANS	87
#define	C_FREE		88
E 14
#define	SZ_CMAP		16		/* sizeof(struct cmap) */
E 12

I 12
#define	MAXMEM		64*1024		/* maximum memory, in Kbytes */
#endif	LOCORE

E 12
#define	CMHEAD	0

I 4
/*
 * Shared text pages are not totally abandoned when a process
 * exits, but are remembered while in the free list hashed by <mdev,blkno>
 * off the cmhash structure so that they can be reattached
 * if another instance of the program runs again soon.
 */
E 4
I 3
D 16
#define	CMHSIZ	512		/* SHOULD BE DYNAMIC */
E 16
I 16
#define	CMHSIZ	2048		/* SHOULD BE DYNAMIC */
E 16
#define	CMHASH(bn)	((bn)&(CMHSIZ-1))

I 12
#ifndef	LOCORE
E 12
E 3
#ifdef	KERNEL
D 9
extern	struct cmap *cmap;
extern	struct cmap *ecmap;
E 9
I 9
struct	cmap *cmap;
struct	cmap *ecmap;
E 9
I 8
int	ncmap;
E 8
I 3
struct	cmap *mfind();
I 4
D 9
struct	cmap zcmap;
E 9
E 4
E 3
int	firstfree, maxfree;
I 3
D 4
int	ecmx;
E 4
I 4
int	ecmx;			/* cmap index of ecmap */
E 4
D 16
short	cmhash[CMHSIZ];
E 16
I 16
u_short	cmhash[CMHSIZ];
E 16
E 3
#endif

D 4
/* bits defined in c_flag */
E 4
I 4
/* bits defined in c_type */
E 4

D 4
#define	MTEXT		0x01		/* belongs to shared text segment */
#define	MDATA		0x02		/* belongs to data segment */
#define	MSTACK		0x04		/* belongs to stack segment */
#define	MSYS		0x08		/* allocated to u area */
#define	MGONE		0x10		/* associated page has been released */
#define	MFREE		0x20		/* on the free list */
#define	MLOCK		0x40		/* locked for raw i/o or pagein */
#define	MWANT		0x80		/* wanted */
E 4
I 4
#define	CSYS		0		/* none of below */
#define	CTEXT		1		/* belongs to shared text segment */
#define	CDATA		2		/* belongs to data segment */
#define	CSTACK		3		/* belongs to stack segment */
E 4

D 13
#define	pgtocm(x)	((((x)-firstfree) / CLSIZE) + 1)
E 13
I 13
#define	pgtocm(x)	(((int) ((x)-firstfree) / CLSIZE) + 1)
E 13
#define	cmtopg(x)	((((x)-1) * CLSIZE) + firstfree)
I 12
#endif	LOCORE
E 12
E 1
