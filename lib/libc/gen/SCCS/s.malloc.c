h05770
s 00002/00002/00382
d D 5.6 86/03/09 19:50:20 donn 12 11
c added LIBC_SCCS condition for sccs ids
e
s 00013/00012/00371
d D 5.5 86/02/25 00:34:27 lepreau 11 10
c reorder elements in RCHECK'ed header so can properly catch free'ing a free blk
c and not get segmentation fault later (applies only to debug code).
c Reality treatment for comments.
e
s 00010/00010/00373
d D 5.4 86/01/10 01:35:18 lepreau 10 9
c when findbucket fails twice, copy largest possible area, not smallest;
c fix up botch() debug code
e
s 00010/00003/00373
d D 5.3 86/01/09 20:18:32 mckusick 9 8
c add sanity checks for preposterous sizes
e
s 00001/00001/00375
d D 5.2 85/10/11 18:03:22 mckusick 8 7
c fix copyright date
e
s 00007/00001/00369
d D 5.1 85/05/30 10:44:52 dist 7 6
c Add copyright
e
s 00003/00003/00367
d D 4.6 84/11/28 10:08:43 ralph 6 5
c store RMAGIC on a short boundary (if RCHECK defined).
e
s 00115/00082/00255
d D 4.5 84/11/02 17:13:21 ralph 5 4
c page align properly, round to 2**n+pagesize-overhead for large blocks.
e
s 00012/00004/00325
d D 4.4 84/11/02 14:31:26 ralph 4 3
c fix range checking.
e
s 00029/00012/00300
d D 4.3 83/09/16 18:32:45 sam 3 2
c just tidying up; I'll never learn...
e
s 00280/00160/00032
d D 4.2 83/09/11 21:55:26 karels 2 1
c installing Caltech malloc, with fixes from lepreau@utah-cs
e
s 00192/00000/00000
d D 4.1 83/06/22 18:17:58 root 1 0
c date and time created 83/06/22 18:17:58 by root
e
u
U
t
T
I 7
/*
D 8
 * Copyright (c) 1980 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1983 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
D 12
#ifndef lint
E 12
I 12
#if defined(LIBC_SCCS) && !defined(lint)
E 12
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif
E 7
I 7
D 12
#endif not lint
E 12
I 12
#endif LIBC_SCCS and not lint
E 12
E 7
I 2

/*
 * malloc.c (Caltech) 2/21/82
 * Chris Kingsley, kingsley@cit-20.
 *
 * This is a very fast storage allocator.  It allocates blocks of a small 
 * number of different sizes, and keeps free lists of each size.  Blocks that
 * don't exactly fit are passed up to the next larger size.  In this 
D 11
 * implementation, the available sizes are 2^n-4 (or 2^n-12) bytes long.
 * This is designed for use in a program that uses vast quantities of memory,
 * but bombs when it runs out. 
E 11
I 11
 * implementation, the available sizes are 2^n-4 (or 2^n-10) bytes long.
 * This is designed for use in a virtual memory environment.
E 11
 */

#include <sys/types.h>

#define	NULL 0

/*
 * The overhead on a block is at least 4 bytes.  When free, this space
 * contains a pointer to the next free block, and the bottom two bits must
 * be zero.  When in use, the first byte is set to MAGIC, and the second
 * byte is the size index.  The remaining bytes are for alignment.
D 11
 * If range checking is enabled and the size of the block fits
 * in two bytes, then the top two bytes hold the size of the requested block
 * plus the range checking words, and the header word MINUS ONE.
E 11
I 11
 * If range checking is enabled then a second word holds the size of the
 * requested block, less 1, rounded up to a multiple of sizeof(RMAGIC).
 * The order of elements is critical: ov_magic must overlay the low order
 * bits of ov_next, and ov_magic can not be a valid ov_next bit pattern.
E 11
 */
union	overhead {
	union	overhead *ov_next;	/* when free */
	struct {
I 5
D 11
#ifndef RCHECK
E 11
E 5
		u_char	ovu_magic;	/* magic number */
		u_char	ovu_index;	/* bucket # */
D 5
#ifdef RCHECK
		u_short	ovu_size;	/* actual block size */
		u_int	ovu_rmagic;	/* range magic number */
E 5
I 5
D 11
#else
		u_int	ovu_size;	/* actual block size */
		u_char	ovu_magic;	/* magic number */
		u_char	ovu_index;	/* bucket # */
E 11
I 11
#ifdef RCHECK
E 11
		u_short	ovu_rmagic;	/* range magic number */
I 11
		u_int	ovu_size;	/* actual block size */
E 11
E 5
#endif
	} ovu;
#define	ov_magic	ovu.ovu_magic
#define	ov_index	ovu.ovu_index
D 5
#define	ov_size		ovu.ovu_size
E 5
#define	ov_rmagic	ovu.ovu_rmagic
I 5
#define	ov_size		ovu.ovu_size
E 5
};

D 5
#define	MAGIC		0xff		/* magic # on accounting info */
#define RMAGIC		0x55555555	/* magic # on range info */
E 5
I 5
#define	MAGIC		0xef		/* magic # on accounting info */
#define RMAGIC		0x5555		/* magic # on range info */

E 5
#ifdef RCHECK
D 5
#define	RSLOP		sizeof (u_int)
E 5
I 5
#define	RSLOP		sizeof (u_short)
E 5
#else
#define	RSLOP		0
#endif

/*
 * nextf[i] is the pointer to the next free block of size 2^(i+3).  The
 * smallest allocatable block is 8 bytes.  The overhead information
 * precedes the data area returned to the user.
 */
#define	NBUCKETS 30
static	union overhead *nextf[NBUCKETS];
extern	char *sbrk();

I 5
static	int pagesz;			/* page size */
static	int pagebucket;			/* page size bucket */

E 5
#ifdef MSTATS
/*
 * nmalloc[i] is the difference between the number of mallocs and frees
 * for a given block size.
 */
static	u_int nmalloc[NBUCKETS];
#include <stdio.h>
#endif

E 2
D 5
#ifdef debug
D 2
#define ASSERT(p) if(!(p))botch("p");else
E 2
I 2
#define	ASSERT(p)   if (!(p)) botch("p"); else
E 5
I 5
D 10
#ifdef DEBUG
E 10
I 10
#if defined(DEBUG) || defined(RCHECK)
E 10
#define	ASSERT(p)   if (!(p)) botch("p")
I 10
#include <stdio.h>
E 10
E 5
static
E 2
botch(s)
D 3
char *s;
E 3
I 3
	char *s;
E 3
{
D 3
	printf("assertion botched: %s\n",s);
E 3
I 3
D 10

	printf("assertion botched: %s\n", s);
E 10
I 10
	fprintf(stderr, "\r\nassertion botched: %s\r\n", s);
 	(void) fflush(stderr);		/* just in case user buffered it */
E 10
E 3
	abort();
}
#else
D 2
#define ASSERT(p)
E 2
I 2
#define	ASSERT(p)
E 2
#endif

D 2
/*	avoid break bug */
#ifdef pdp11
#define GRANULE 64
#else
#define GRANULE 0
#endif
/*	C storage allocator
 *	circular first-fit strategy
 *	works with noncontiguous, but monotonically linked, arena
 *	each block is preceded by a ptr to the (pointer of) 
 *	the next following block
 *	blocks are exact number of words long 
 *	aligned to the data type requirements of ALIGN
 *	pointers to blocks must have BUSY bit 0
 *	bit in ptr is 1 for busy, 0 for idle
 *	gaps in arena are merely noted as busy blocks
 *	last block of arena (pointed to by alloct) is empty and
 *	has a pointer to first
 *	idle blocks are coalesced during space search
 *
 *	a different implementation may need to redefine
 *	ALIGN, NALIGN, BLOCK, BUSY, INT
 *	where INT is integer type to which a pointer can be cast
*/
#define INT int
#define ALIGN int
#define NALIGN 1
#define WORD sizeof(union store)
#define BLOCK 1024	/* a multiple of WORD*/
#define BUSY 1
#define NULL 0
#define testbusy(p) ((INT)(p)&BUSY)
#define setbusy(p) (union store *)((INT)(p)|BUSY)
#define clearbusy(p) (union store *)((INT)(p)&~BUSY)

union store { union store *ptr;
	      ALIGN dummy[NALIGN];
	      int calloc;	/*calloc clears an array of integers*/
};

static	union store allocs[2];	/*initial arena*/
static	union store *allocp;	/*search ptr*/
static	union store *alloct;	/*arena top*/
static	union store *allocx;	/*for benefit of realloc*/
char	*sbrk();

E 2
char *
malloc(nbytes)
D 2
unsigned nbytes;
E 2
I 2
D 5
	register unsigned nbytes;
E 5
I 5
	unsigned nbytes;
E 5
E 2
{
D 2
	register union store *p, *q;
	register nw;
	static temp;	/*coroutines assume no auto*/
E 2
I 2
D 5
  	register union overhead *p;
  	register int bucket = 0;
  	register unsigned shiftr;
E 5
I 5
  	register union overhead *op;
  	register int bucket;
	register unsigned amt, n;
E 5
E 2

D 2
	if(allocs[0].ptr==0) {	/*first time*/
		allocs[0].ptr = setbusy(&allocs[1]);
		allocs[1].ptr = setbusy(&allocs[0]);
		alloct = &allocs[1];
		allocp = &allocs[0];
	}
	nw = (nbytes+WORD+WORD-1)/WORD;
	ASSERT(allocp>=allocs && allocp<=alloct);
	ASSERT(allock());
	for(p=allocp; ; ) {
		for(temp=0; ; ) {
			if(!testbusy(p->ptr)) {
				while(!testbusy((q=p->ptr)->ptr)) {
					ASSERT(q>p&&q<alloct);
					p->ptr = q->ptr;
				}
				if(q>=p+nw && p+nw>=p)
					goto found;
			}
			q = p;
			p = clearbusy(p->ptr);
			if(p>q)
				ASSERT(p<=alloct);
			else if(q!=alloct || p!=allocs) {
				ASSERT(q==alloct&&p==allocs);
				return(NULL);
			} else if(++temp>1)
				break;
		}
		temp = ((nw+BLOCK/WORD)/(BLOCK/WORD))*(BLOCK/WORD);
		q = (union store *)sbrk(0);
		if(q+temp+GRANULE < q) {
			return(NULL);
		}
		q = (union store *)sbrk(temp*WORD);
		if((INT)q == -1) {
			return(NULL);
		}
		ASSERT(q>alloct);
		alloct->ptr = q;
		if(q!=alloct+1)
			alloct->ptr = setbusy(alloct->ptr);
		alloct = q->ptr = q+temp-1;
		alloct->ptr = setbusy(allocs);
	}
found:
	allocp = p + nw;
	ASSERT(allocp<=alloct);
	if(q>allocp) {
		allocx = allocp->ptr;
		allocp->ptr = p->ptr;
	}
	p->ptr = setbusy(allocp);
	return((char *)(p+1));
E 2
I 2
	/*
D 5
	 * Convert amount of memory requested into
	 * closest block size stored in hash buckets
	 * which satisfies request.  Account for
	 * space used per block for accounting.
E 5
I 5
	 * First time malloc is called, setup page size and
	 * align break pointer so all data will be page aligned.
E 5
	 */
D 5
  	nbytes += sizeof (union overhead) + RSLOP;
  	nbytes = (nbytes + 3) &~ 3; 
  	shiftr = (nbytes - 1) >> 2;
	/* apart from this loop, this is O(1) */
  	while (shiftr >>= 1)
  		bucket++;
E 5
I 5
	if (pagesz == 0) {
		pagesz = n = getpagesize();
		op = (union overhead *)sbrk(0);
  		n = n - sizeof (*op) - ((int)op & (n - 1));
		if (n < 0)
			n += pagesz;
  		if (n) {
  			if (sbrk(n) == (char *)-1)
				return (NULL);
		}
		bucket = 0;
		amt = 8;
		while (pagesz > amt) {
			amt <<= 1;
			bucket++;
		}
		pagebucket = bucket;
	}
E 5
	/*
I 5
	 * Convert amount of memory requested into closest block size
	 * stored in hash buckets which satisfies request.
	 * Account for space used per block for accounting.
	 */
	if (nbytes <= (n = pagesz - sizeof (*op) - RSLOP)) {
#ifndef RCHECK
		amt = 8;	/* size of first bucket */
		bucket = 0;
#else
		amt = 16;	/* size of first bucket */
		bucket = 1;
#endif
		n = -(sizeof (*op) + RSLOP);
	} else {
		amt = pagesz;
		bucket = pagebucket;
	}
	while (nbytes > amt + n) {
		amt <<= 1;
I 9
		if (amt == 0)
			return (NULL);
E 9
		bucket++;
	}
	/*
E 5
	 * If nothing in hash bucket right now,
	 * request more memory from the system.
	 */
D 5
  	if (nextf[bucket] == NULL)    
E 5
I 5
  	if ((op = nextf[bucket]) == NULL) {
E 5
  		morecore(bucket);
D 5
  	if ((p = (union overhead *)nextf[bucket]) == NULL)
  		return (NULL);
E 5
I 5
  		if ((op = nextf[bucket]) == NULL)
  			return (NULL);
	}
E 5
	/* remove from linked list */
D 5
  	nextf[bucket] = nextf[bucket]->ov_next;
	p->ov_magic = MAGIC;
	p->ov_index= bucket;
E 5
I 5
  	nextf[bucket] = op->ov_next;
	op->ov_magic = MAGIC;
	op->ov_index = bucket;
E 5
#ifdef MSTATS
  	nmalloc[bucket]++;
#endif
#ifdef RCHECK
	/*
	 * Record allocated size of block and
	 * bound space with magic numbers.
	 */
D 4
  	if (nbytes <= 0x10000)
		p->ov_size = nbytes - 1;
E 4
D 5
	p->ov_rmagic = RMAGIC;
D 4
  	*((u_int *)((caddr_t)p + nbytes - RSLOP)) = RMAGIC;
E 4
I 4
  	if (bucket <= 13) {
		p->ov_size = nbytes - 1;
  		*((u_int *)((caddr_t)p + nbytes - RSLOP)) = RMAGIC;
	}
E 5
I 5
D 6
	op->ov_size = nbytes;
E 6
I 6
	op->ov_size = (nbytes + RSLOP - 1) & ~(RSLOP - 1);
E 6
	op->ov_rmagic = RMAGIC;
D 6
  	*(u_short *)((caddr_t)(op + 1) + nbytes) = RMAGIC;
E 6
I 6
  	*(u_short *)((caddr_t)(op + 1) + op->ov_size) = RMAGIC;
E 6
E 5
E 4
#endif
D 5
  	return ((char *)(p + 1));
E 5
I 5
  	return ((char *)(op + 1));
E 5
E 2
}

D 2
/*	freeing strategy tuned for LIFO allocation
*/
free(ap)
register char *ap;
E 2
I 2
/*
 * Allocate more memory to the indicated bucket.
 */
D 9
static
E 9
morecore(bucket)
D 5
	register bucket;
E 5
I 5
	int bucket;
E 5
E 2
{
D 2
	register union store *p = (union store *)ap;
E 2
I 2
  	register union overhead *op;
D 5
  	register int rnu;       /* 2^rnu bytes will be requested */
  	register int nblks;     /* become nblks blocks of the desired size */
	register int siz;
E 5
I 5
	register int sz;		/* size of desired block */
D 9
  	register int amt;		/* amount to allocate */
  	register int nblks;		/* how many blocks we get */
E 9
I 9
  	int amt;			/* amount to allocate */
  	int nblks;			/* how many blocks we get */
E 9
E 5
E 2

I 9
	/*
	 * sbrk_size <= 0 only for big, FLUFFY, requests (about
	 * 2^30 bytes on a VAX, I think) or for a negative arg.
	 */
E 9
D 2
	ASSERT(p>clearbusy(allocs[1].ptr)&&p<=alloct);
	ASSERT(allock());
	allocp = --p;
	ASSERT(testbusy(p->ptr));
	p->ptr = clearbusy(p->ptr);
	ASSERT(p->ptr > allocp && p->ptr <= alloct);
E 2
I 2
D 5
  	if (nextf[bucket])
  		return;
	/*
	 * Insure memory is allocated
	 * on a page boundary.  Should
	 * make getpageize call?
	 */
  	op = (union overhead *)sbrk(0);
  	if ((int)op & 0x3ff)
  		sbrk(1024 - ((int)op & 0x3ff));
	/* take 2k unless the block is bigger than that */
  	rnu = (bucket <= 8) ? 11 : bucket + 3;
  	nblks = 1 << (rnu - (bucket + 3));  /* how many blocks to get */
  	if (rnu < bucket)
		rnu = bucket;
	op = (union overhead *)sbrk(1 << rnu);
E 5
I 5
	sz = 1 << (bucket + 3);
I 11
#ifdef DEBUG
	ASSERT(sz > 0);
#else
E 11
I 9
	if (sz <= 0)
		return;
I 11
#endif
E 11
E 9
	if (sz < pagesz) {
		amt = pagesz;
  		nblks = amt / sz;
	} else {
		amt = sz + pagesz;
		nblks = 1;
	}
	op = (union overhead *)sbrk(amt);
E 5
	/* no more room! */
  	if ((int)op == -1)
  		return;
	/*
D 5
	 * Round up to minimum allocation size boundary
	 * and deduct from block count to reflect.
	 */
  	if ((int)op & 7) {
  		op = (union overhead *)(((int)op + 8) &~ 7);
  		nblks--;
  	}
	/*
E 5
	 * Add new memory allocated to that on
	 * free list for this hash bucket.
	 */
  	nextf[bucket] = op;
D 5
  	siz = 1 << (bucket + 3);
E 5
  	while (--nblks > 0) {
D 5
		op->ov_next = (union overhead *)((caddr_t)op + siz);
		op = (union overhead *)((caddr_t)op + siz);
E 5
I 5
		op->ov_next = (union overhead *)((caddr_t)op + sz);
		op = (union overhead *)((caddr_t)op + sz);
E 5
  	}
E 2
}

D 2
/*	realloc(p, nbytes) reallocates a block obtained from malloc()
 *	and freed since last call of malloc()
 *	to have new size nbytes, and old content
 *	returns new location, or 0 on failure
*/
E 2
I 2
free(cp)
	char *cp;
{   
  	register int size;
	register union overhead *op;
E 2

I 2
  	if (cp == NULL)
  		return;
	op = (union overhead *)((caddr_t)cp - sizeof (union overhead));
D 5
#ifdef debug
E 5
I 5
#ifdef DEBUG
E 5
  	ASSERT(op->ov_magic == MAGIC);		/* make sure it was in use */
#else
	if (op->ov_magic != MAGIC)
		return;				/* sanity */
#endif
#ifdef RCHECK
  	ASSERT(op->ov_rmagic == RMAGIC);
D 5
	if (op->ov_index <= 13)
		ASSERT(*(u_int *)((caddr_t)op + op->ov_size + 1 - RSLOP) == RMAGIC);
E 5
I 5
	ASSERT(*(u_short *)((caddr_t)(op + 1) + op->ov_size) == RMAGIC);
E 5
#endif
D 5
  	ASSERT(op->ov_index < NBUCKETS);
E 5
  	size = op->ov_index;
I 5
  	ASSERT(size < NBUCKETS);
E 5
D 11
	op->ov_next = nextf[size];
E 11
I 11
	op->ov_next = nextf[size];	/* also clobbers ov_magic */
E 11
  	nextf[size] = op;
#ifdef MSTATS
  	nmalloc[size]--;
#endif
}

/*
 * When a program attempts "storage compaction" as mentioned in the
 * old malloc man page, it realloc's an already freed block.  Usually
 * this is the last block it freed; occasionally it might be farther
 * back.  We have to search all the free lists for the block in order
 * to determine its bucket: 1st we make one pass thru the lists
 * checking only the first block in each; if that fails we search
 * ``realloc_srchlen'' blocks in each list for a match (the variable
 * is extern so the caller can modify it).  If that fails we just copy
 * however many bytes was given to realloc() and hope it's not huge.
 */
D 3
int realloc_srchlen = 4;	/* 4 should be plenty.  -1 means whole list */
E 3
I 3
int realloc_srchlen = 4;	/* 4 should be plenty, -1 =>'s whole list */
E 3

E 2
char *
D 2
realloc(p, nbytes)
register union store *p;
unsigned nbytes;
E 2
I 2
realloc(cp, nbytes)
	char *cp; 
	unsigned nbytes;
{   
D 5
  	register u_int onb;
E 5
I 5
  	register u_int onb, i;
E 5
	union overhead *op;
  	char *res;
D 5
	register int i;
E 5
	int was_alloced = 0;

  	if (cp == NULL)
  		return (malloc(nbytes));
	op = (union overhead *)((caddr_t)cp - sizeof (union overhead));
	if (op->ov_magic == MAGIC) {
		was_alloced++;
		i = op->ov_index;
D 3
	}
	else {		/* already free: he is doing "compaction" (tee hee) */
E 3
I 3
	} else {
		/*
		 * Already free, doing "compaction".
		 *
		 * Search for the old block of memory on the
		 * free list.  First, check the most common
		 * case (last element free'd), then (this failing)
		 * the last ``realloc_srchlen'' items free'd.
		 * If all lookups fail, then assume the size of
		 * the memory block being realloc'd is the
D 10
		 * smallest possible.
E 10
I 10
		 * largest possible (so that all "nbytes" of new
		 * memory are copied into).  Note that this could cause
		 * a memory fault if the old area was tiny, and the moon
		 * is gibbous.  However, that is very unlikely.
E 10
		 */
E 3
		if ((i = findbucket(op, 1)) < 0 &&
		    (i = findbucket(op, realloc_srchlen)) < 0)
I 5
D 10
#ifndef RCHECK
E 5
D 3
			i = 0;		/* assume shortest possible */
E 3
I 3
			i = 0;
I 5
#else
			i = 1;	/* smallest possible w/ RCHECK */
#endif
E 10
I 10
			i = NBUCKETS;
E 10
E 5
E 3
	}
D 5
	onb = (1 << (i + 3)) - sizeof (*op) - RSLOP;
E 5
I 5
	onb = 1 << (i + 3);
	if (onb < pagesz)
		onb -= sizeof (*op) + RSLOP;
	else
		onb += pagesz - sizeof (*op) - RSLOP;
E 5
D 3
	if (was_alloced &&		/* avoid the copy if same size block */
E 3
I 3
	/* avoid the copy if same size block */
D 5
	if (was_alloced &&
E 3
D 4
	    nbytes <= onb && nbytes > (onb >> 1) - sizeof(*op) - RSLOP)
E 4
I 4
	    nbytes <= onb && nbytes > (1 << (i + 2)) - sizeof(*op) - RSLOP) {
#ifdef RCHECK
  		if (i <= 13) {
			op->ov_size = nbytes - 1;
  			*((u_int *)((caddr_t)op + nbytes - RSLOP)) = RMAGIC;
E 5
I 5
	if (was_alloced) {
		if (i) {
			i = 1 << (i + 2);
			if (i < pagesz)
				i -= sizeof (*op) + RSLOP;
			else
				i += pagesz - sizeof (*op) - RSLOP;
E 5
		}
I 5
		if (nbytes <= onb && nbytes > i) {
#ifdef RCHECK
D 6
			op->ov_size = nbytes;
E 6
I 6
			op->ov_size = (nbytes + RSLOP - 1) & ~(RSLOP - 1);
E 6
			*(u_short *)((caddr_t)(op + 1) + op->ov_size) = RMAGIC;
E 5
#endif
E 4
D 5
		return(cp);
E 5
I 5
			return(cp);
		} else
			free(cp);
E 5
I 4
	}
E 4
  	if ((res = malloc(nbytes)) == NULL)
  		return (NULL);
D 10
  	if (cp != res)			/* common optimization */
E 10
I 10
  	if (cp != res)		/* common optimization if "compacting" */
E 10
		bcopy(cp, res, (nbytes < onb) ? nbytes : onb);
D 5
  	if (was_alloced)
		free(cp);
E 5
  	return (res);
}

/*
 * Search ``srchlen'' elements of each free list for a block whose
 * header starts at ``freep''.  If srchlen is -1 search the whole list.
 * Return bucket number, or -1 if not found.
 */
static
findbucket(freep, srchlen)
D 3
union overhead *freep;
int srchlen;
E 3
I 3
	union overhead *freep;
	int srchlen;
E 3
E 2
{
D 2
	register union store *q;
	union store *s, *t;
	register unsigned nw;
	unsigned onw;
E 2
I 2
	register union overhead *p;
	register int i, j;
E 2

D 2
	if(testbusy(p[-1].ptr))
		free((char *)p);
	onw = p[-1].ptr - p;
	q = (union store *)malloc(nbytes);
	if(q==NULL || q==p)
		return((char *)q);
	s = p;
	t = q;
	nw = (nbytes+WORD-1)/WORD;
	if(nw<onw)
		onw = nw;
	while(onw--!=0)
		*t++ = *s++;
	if(q<p && q+nw>=p)
		(q+(q+nw-p))->ptr = allocx;
	return((char *)q);
E 2
I 2
D 3
	for (i = 0; i < NBUCKETS; i++)
		for (j = 0, p = nextf[i]; p && j != srchlen; j++, p = p->ov_next)
E 3
I 3
	for (i = 0; i < NBUCKETS; i++) {
		j = 0;
		for (p = nextf[i]; p && j != srchlen; p = p->ov_next) {
E 3
			if (p == freep)
				return (i);
I 3
			j++;
		}
	}
E 3
	return (-1);
E 2
}

D 2
#ifdef debug
allock()
E 2
I 2
#ifdef MSTATS
/*
 * mstats - print out statistics about malloc
 * 
 * Prints two lines of numbers, one showing the length of the free list
 * for each size category, the second showing the number of mallocs -
 * frees for each size category.
 */
mstats(s)
	char *s;
E 2
{
D 2
#ifdef longdebug
	register union store *p;
	int x;
	x = 0;
	for(p= &allocs[0]; clearbusy(p->ptr) > p; p=clearbusy(p->ptr)) {
		if(p==allocp)
			x++;
	}
	ASSERT(p==alloct);
	return(x==1|p==allocp);
#else
	return(1);
#endif
E 2
I 2
  	register int i, j;
  	register union overhead *p;
  	int totfree = 0,
  	totused = 0;

  	fprintf(stderr, "Memory allocation statistics %s\nfree:\t", s);
  	for (i = 0; i < NBUCKETS; i++) {
  		for (j = 0, p = nextf[i]; p; p = p->ov_next, j++)
  			;
  		fprintf(stderr, " %d", j);
  		totfree += j * (1 << (i + 3));
  	}
  	fprintf(stderr, "\nused:\t");
  	for (i = 0; i < NBUCKETS; i++) {
  		fprintf(stderr, " %d", nmalloc[i]);
  		totused += nmalloc[i] * (1 << (i + 3));
  	}
D 3
  	fprintf(stderr, "\n\tTotal in use: %d, total free: %d\n", totused, totfree);
E 3
I 3
  	fprintf(stderr, "\n\tTotal in use: %d, total free: %d\n",
	    totused, totfree);
E 3
E 2
}
#endif
E 1
