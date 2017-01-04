h33661
s 00010/00005/00161
d D 7.7 88/06/27 18:42:32 bostic 7 6
c install approved copyright notice
e
s 00007/00007/00159
d D 7.6 88/05/24 19:28:33 mckusick 6 5
c lint
e
s 00008/00002/00158
d D 7.5 88/02/06 11:00:57 mckusick 5 4
c change copyright
e
s 00005/00001/00155
d D 7.4 88/02/03 18:00:53 mckusick 4 3
c add yet more statistics
e
s 00002/00002/00154
d D 7.3 87/07/15 14:29:19 mckusick 3 2
c CLBYTES should be NBPG
e
s 00001/00000/00151
d D 7.2 87/06/06 15:11:32 mckusick 2 1
c add M_GPROF, M_IOCTLOPS, M_SUPERBLK, and M_TEMP memory types
e
s 00151/00000/00000
d D 7.1 87/06/06 13:26:49 mckusick 1 0
c date and time created 87/06/06 13:26:49 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 5
 *
 *	%W% (Berkeley) %G%
 */

#define KMEMSTATS

/*
 * flags to malloc
 */
#define M_WAITOK	0x0000
#define M_NOWAIT	0x0001

/*
 * Types of memory to be allocated
 */
#define	M_FREE		0	/* should be on free list */
#define M_MBUF		1	/* mbuf */
#define M_DEVBUF	2	/* device driver memory */
#define	M_SOCKET	3	/* socket structure */
#define	M_PCB		4	/* protocol control block */
#define	M_RTABLE	5	/* routing tables */
#define	M_HTABLE	6	/* IMP host tables */
#define	M_FTABLE	7	/* fragment reassembly header */
#define	M_ZOMBIE	8	/* zombie proc status */
#define	M_IFADDR	9	/* interface address */
#define	M_SOOPTS	10	/* socket options */
#define	M_SONAME	11	/* socket name */
#define M_NAMEI		12	/* namei path name buffer */
I 2
#define M_GPROF		13	/* kernel profiling buffer */
#define M_IOCTLOPS	14	/* ioctl data buffer */
#define M_SUPERBLK	15	/* super block data */
D 4
#define M_TEMP		16	/* misc temporary data buffers */
E 4
I 4
#define M_CRED		16	/* credentials */
#define M_TEMP		49	/* misc temporary data buffers */
E 4
E 2
#define M_LAST		50

struct kmemstats {
	long	ks_inuse;	/* # of packets of this type currently in use */
	long	ks_calls;	/* total packets of this type ever allocated */
I 4
	long 	ks_memuse;	/* total memory held in bytes */
	u_short	ks_limblocks;	/* number of times blocked for hitting limit */
	u_short	ks_mapblocks;	/* number of times blocked for kernel map */
E 4
	long	ks_maxused;	/* maximum number ever used */
	long	ks_limit;	/* most that are allowed to exist */
};

/*
 * Array of descriptors that describe the contents of each page
 */
struct kmemusage {
	short ku_indx;		/* bucket index */
	union {
		u_short freecnt;/* for small allocations, free pieces in page */
		u_short pagecnt;/* for large allocations, pages alloced */
	} ku_un;
};
#define ku_freecnt ku_un.freecnt
#define ku_pagecnt ku_un.pagecnt

/*
 * Set of buckets for each size of memory block that is retained
 */
struct kmembuckets {
	caddr_t kb_next;	/* list of free blocks */
	long	kb_calls;	/* total calls to allocate this size */
	long	kb_total;	/* total number of blocks allocated */
	long	kb_totalfree;	/* # of free elements in this bucket */
	long	kb_elmpercl;	/* # of elements in this sized allocation */
	long	kb_highwat;	/* high water mark */
	long	kb_couldfree;	/* over high water mark and could free */
};

#ifdef KERNEL
#define MINALLOCSIZE	(1 << MINBUCKET)
#define BUCKETINDX(size) \
	(size) <= (MINALLOCSIZE * 128) \
		? (size) <= (MINALLOCSIZE * 8) \
			? (size) <= (MINALLOCSIZE * 2) \
				? (size) <= (MINALLOCSIZE * 1) \
					? (MINBUCKET + 0) \
					: (MINBUCKET + 1) \
				: (size) <= (MINALLOCSIZE * 4) \
					? (MINBUCKET + 2) \
					: (MINBUCKET + 3) \
			: (size) <= (MINALLOCSIZE* 32) \
				? (size) <= (MINALLOCSIZE * 16) \
					? (MINBUCKET + 4) \
					: (MINBUCKET + 5) \
				: (size) <= (MINALLOCSIZE * 64) \
					? (MINBUCKET + 6) \
					: (MINBUCKET + 7) \
		: (size) <= (MINALLOCSIZE * 2048) \
			? (size) <= (MINALLOCSIZE * 512) \
				? (size) <= (MINALLOCSIZE * 256) \
					? (MINBUCKET + 8) \
					: (MINBUCKET + 9) \
				: (size) <= (MINALLOCSIZE * 1024) \
					? (MINBUCKET + 10) \
					: (MINBUCKET + 11) \
			: (size) <= (MINALLOCSIZE * 8192) \
				? (size) <= (MINALLOCSIZE * 4096) \
					? (MINBUCKET + 12) \
					: (MINBUCKET + 13) \
				: (size) <= (MINALLOCSIZE * 16384) \
					? (MINBUCKET + 14) \
					: (MINBUCKET + 15)

/*
 * Turn virtual addresses into kmem map indicies
 */
D 3
#define kmemxtob(addr)	(kmembase + (addr) * CLBYTES)
#define btokmemx(addr)	(((addr) - kmembase) / CLBYTES)
E 3
I 3
D 6
#define kmemxtob(addr)	(kmembase + (addr) * NBPG)
#define btokmemx(addr)	(((addr) - kmembase) / NBPG)
E 3
#define btokup(addr)	(&kmemusage[((addr) - kmembase) >> CLSHIFT])
E 6
I 6
#define kmemxtob(alloc)	(kmembase + (alloc) * NBPG)
#define btokmemx(addr)	(((caddr_t)(addr) - kmembase) / NBPG)
#define btokup(addr)	(&kmemusage[((caddr_t)(addr) - kmembase) >> CLSHIFT])
E 6

/*
 * Macro versions for the usual cases of malloc/free
 */
#ifdef KMEMSTATS
#define MALLOC(space, cast, size, type, flags) \
D 6
	(space) = (cast)malloc(size, type, flags)
#define FREE(addr, type) free(addr, type)
E 6
I 6
	(space) = (cast)malloc((u_long)(size), type, flags)
#define FREE(addr, type) free((caddr_t)(addr), type)
E 6

#else /* do not collect statistics */
#define MALLOC(space, cast, size, type, flags) { \
	register struct kmembuckets *kbp = &bucket[BUCKETINDX(size)]; \
	long s = splimp(); \
	if (kbp->kb_next == NULL) { \
D 6
		(space) = (cast)malloc(size, type, flags); \
E 6
I 6
		(space) = (cast)malloc((u_long)(size), type, flags); \
E 6
	} else { \
		(space) = (cast)kbp->kb_next; \
		kbp->kb_next = *(caddr_t *)(space); \
	} \
	splx(s); \
}

#define FREE(addr, type) { \
	register struct kmembuckets *kbp; \
	register struct kmemusage *kup = btokup(addr); \
	long s = splimp(); \
	if (1 << kup->ku_indx > MAXALLOCSAVE) { \
D 6
		free(addr, type); \
E 6
I 6
		free((caddr_t)(addr), type); \
E 6
	} else { \
		kbp = &bucket[kup->ku_indx]; \
		*(caddr_t *)(addr) = kbp->kb_next; \
		kbp->kb_next = (caddr_t)(addr); \
	} \
	splx(s); \
}
#endif /* do not collect statistics */

extern struct kmemstats kmemstats[];
extern struct kmemusage *kmemusage;
extern char kmembase[];
extern struct kmembuckets bucket[];
extern qaddr_t malloc();
extern void free();
#endif KERNEL
E 1
