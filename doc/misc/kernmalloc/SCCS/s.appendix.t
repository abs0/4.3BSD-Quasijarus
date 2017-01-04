h51335
s 00014/00026/00091
d D 1.2 88/04/22 17:38:01 mckusick 2 1
c cleanup to make fit on two pages
e
s 00117/00000/00000
d D 1.1 88/04/21 19:32:05 mckusick 1 0
c for reviewer #204
e
u
U
t
T
I 1
.\"	%W%	(Copyright 1988 M. K. McKusick)	%E%
D 2
.H 1 "Appendix 1 - Implementation Details"
.PP
E 2
I 2
.bp
.H 1 "Appendix A - Implementation Details"
.LP
E 2
.nf
I 2
.vS
E 2
/*
 * Constants for setting the parameters of the kernel memory allocator.
 *
 * 2 ** MINBUCKET is the smallest unit of memory that will be
 * allocated. It must be at least large enough to hold a pointer.
 *
 * Units of memory less or equal to MAXALLOCSAVE will permanently
D 2
 * allocate physical memory; requests for these size pieces of
 * memory are quite fast. Allocations greater than MAXALLOCSAVE must
 * always allocate and free physical memory; requests for these
 * size allocations should be done infrequently as they will be slow.
E 2
I 2
 * allocate physical memory; requests for these size pieces of memory
 * are quite fast. Allocations greater than MAXALLOCSAVE must
 * always allocate and free physical memory; requests for these size
 * allocations should be done infrequently as they will be slow.
E 2
 * Constraints: CLBYTES <= MAXALLOCSAVE <= 2 ** (MINBUCKET + 14)
 * and MAXALLOCSIZE must be a power of two.
 */
#define MINBUCKET	4		/* 4 => min allocation of 16 bytes */
#define MAXALLOCSAVE	(2 * CLBYTES)

/*
 * Maximum amount of kernel dynamic memory.
 * Constraints: must be a multiple of the pagesize.
 */
D 2
#define MAXKMEM		1024*PAGESIZE
E 2
I 2
#define MAXKMEM		(1024 * PAGESIZE)
E 2

/*
 * Arena for all kernel dynamic memory allocation.
 * This arena is known to start on a page boundary.
 */
extern char kmembase[MAXKMEM];

/*
 * Array of descriptors that describe the contents of each page
 */
struct kmemsizes {
	short	ks_indx;	/* bucket index, size of small allocations */
	u_short	ks_pagecnt;	/* for large allocations, pages allocated */
} kmemsizes[MAXKMEM / PAGESIZE];

/*
 * Set of buckets for each size of memory block that is retained
 */
struct kmembuckets {
	caddr_t kb_next;	/* list of free blocks */
} bucket[MINBUCKET + 16];
D 2

E 2
I 2
.bp
E 2
/*
D 2
 * Macro to convert a size to a bucket index.
 * If the size is constant, this macro reduces to a
 * compile time constant.
E 2
I 2
 * Macro to convert a size to a bucket index. If the size is constant,
 * this macro reduces to a compile time constant.
E 2
 */
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
D 2
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
E 2
I 2
			/* etc ... */
E 2

/*
 * Macro versions for the usual cases of malloc/free
 */
#define MALLOC(space, cast, size, flags) { \
	register struct kmembuckets *kbp = &bucket[BUCKETINDX(size)]; \
	long s = splimp(); \
	if (kbp->kb_next == NULL) { \
		(space) = (cast)malloc(size, flags); \
	} else { \
		(space) = (cast)kbp->kb_next; \
		kbp->kb_next = *(caddr_t *)(space); \
	} \
	splx(s); \
}

#define FREE(addr) { \
	register struct kmembuckets *kbp; \
	register struct kmemsizes *ksp = \
		&kmemsizes[((addr) - kmembase) / PAGESIZE]; \
	long s = splimp(); \
	if (1 << ksp->ks_indx > MAXALLOCSAVE) { \
		free(addr); \
	} else { \
		kbp = &bucket[ksp->ks_indx]; \
		*(caddr_t *)(addr) = kbp->kb_next; \
		kbp->kb_next = (caddr_t)(addr); \
	} \
	splx(s); \
}
D 2
.fi
E 2
I 2
.vE
E 2
E 1
