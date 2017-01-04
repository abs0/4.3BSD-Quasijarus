h06569
s 00162/00101/00221
d D 5.3 86/03/29 07:21:16 lepreau 8 7
c make csh-specific hacks to libc malloc.c, sid 5.5.
e
s 00003/00003/00319
d D 5.2 85/06/06 13:11:57 edward 7 5
c cleaning up after bozos
e
s 00002/00002/00320
d R 5.2 85/06/06 12:50:55 edward 6 5
c clean up after bozos
e
s 00008/00002/00314
d D 5.1 85/06/04 11:13:08 dist 5 4
c Add copyright
e
s 00023/00031/00293
d D 4.4 84/12/13 14:43:32 edward 4 3
c performance
e
s 00289/00181/00035
d D 4.3 83/11/13 23:35:36 layer 3 2
c new malloc from Caltech.   Better for alloc'ing small chunks of space.
e
s 00001/00001/00215
d D 4.2 83/02/09 14:16:58 sam 2 1
c cleanups from sun
e
s 00216/00000/00000
d D 4.1 80/10/09 12:39:55 bill 1 0
c date and time created 80/10/09 12:39:55 by bill
e
u
U
t
T
I 5
/*
D 8
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
E 7
I 7
 * All rights reserved.  The Berkeley Software License Agreement
E 8
I 8
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
E 8
E 7
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
D 3
static	char *sccsid = "%Z%%M% %I% %G%";
E 3
I 3
#ifndef lint
I 8
/* From "@(#)malloc.c	5.5 (Berkeley) 2/25/86"; */
E 8
D 5
static	char *sccsid = "%Z%%M% %I% (Berkeley from Caltech) %G%";
#endif
E 5
I 5
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7
I 7
static char *sccsid = "%W% (Berkeley) %G%";
D 8
#endif
E 8
I 8
#endif not lint
E 8
E 7
E 5
E 3

D 3
#include "sh.local.h"
E 3
I 3
/*
 * malloc.c (Caltech) 2/21/82
 * Chris Kingsley, kingsley@cit-20.
 *
 * This is a very fast storage allocator.  It allocates blocks of a small 
 * number of different sizes, and keeps free lists of each size.  Blocks that
 * don't exactly fit are passed up to the next larger size.  In this 
D 8
 * implementation, the available sizes are 2^n-4 (or 2^n-12) bytes long.
 * This is designed for use in a program that uses vast quantities of memory,
 * but bombs when it runs out. 
E 8
I 8
 * implementation, the available sizes are 2^n-4 (or 2^n-10) bytes long.
 * This is designed for use in a virtual memory environment.
E 8
 */

#include <sys/types.h>

#define	NULL 0

/*
 * The overhead on a block is at least 4 bytes.  When free, this space
 * contains a pointer to the next free block, and the bottom two bits must
 * be zero.  When in use, the first byte is set to MAGIC, and the second
 * byte is the size index.  The remaining bytes are for alignment.
D 8
 * If range checking is enabled and the size of the block fits
 * in two bytes, then the top two bytes hold the size of the requested block
 * plus the range checking words, and the header word MINUS ONE.
E 8
I 8
 * If range checking is enabled then a second word holds the size of the
 * requested block, less 1, rounded up to a multiple of sizeof(RMAGIC).
 * The order of elements is critical: ov_magic must overlay the low order
 * bits of ov_next, and ov_magic can not be a valid ov_next bit pattern.
E 8
 */
union	overhead {
	union	overhead *ov_next;	/* when free */
	struct {
		u_char	ovu_magic;	/* magic number */
		u_char	ovu_index;	/* bucket # */
#ifdef RCHECK
D 8
		u_short	ovu_size;	/* actual block size */
		u_int	ovu_rmagic;	/* range magic number */
E 8
I 8
		u_short	ovu_rmagic;	/* range magic number */
		u_int	ovu_size;	/* actual block size */
E 8
#endif
	} ovu;
#define	ov_magic	ovu.ovu_magic
#define	ov_index	ovu.ovu_index
D 8
#define	ov_size		ovu.ovu_size
E 8
#define	ov_rmagic	ovu.ovu_rmagic
I 8
#define	ov_size		ovu.ovu_size
E 8
};

D 8
#define	MAGIC		0xff		/* magic # on accounting info */
#define RMAGIC		0x55555555	/* magic # on range info */
E 8
I 8
#define	MAGIC		0xef		/* magic # on accounting info */
#define RMAGIC		0x5555		/* magic # on range info */

E 8
#ifdef RCHECK
D 8
#define	RSLOP		sizeof (u_int)
E 8
I 8
#define	RSLOP		sizeof (u_short)
E 8
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

I 8
static	int pagesz;			/* page size */
static	int pagebucket;			/* page size bucket */

E 8
E 3
D 4
#ifdef debug
E 4
D 3
#define ASSERT(p) if(!(p))botch("p");else
E 3
I 3
/*
 * nmalloc[i] is the difference between the number of mallocs and frees
 * for a given block size.
 */
static	u_int nmalloc[NBUCKETS];
D 4
#endif
E 4

D 8
#ifdef debug
#define	ASSERT(p)   if (!(p)) botch("p"); else
E 8
I 8
#if defined(DEBUG) || defined(RCHECK)
#define	ASSERT(p)   if (!(p)) botch("p")
E 8
static
E 3
botch(s)
D 8
char *s;
E 8
I 8
	char *s;
E 8
{
D 8
	printf("assertion botched: %s\n",s);
E 8
I 8
	printf("\r\nassertion botched: %s\r\n", s);
E 8
	abort();
}
#else
D 3
#define ASSERT(p)
E 3
I 3
#define	ASSERT(p)
E 3
#endif

D 3
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

E 3
char *
malloc(nbytes)
D 3
unsigned nbytes;
E 3
I 3
D 8
	register unsigned nbytes;
E 8
I 8
	unsigned nbytes;
E 8
E 3
{
D 3
	register union store *p, *q;
	register nw;
	static temp;	/*coroutines assume no auto*/
E 3
I 3
D 8
  	register union overhead *p;
  	register int bucket = 0;
  	register unsigned shiftr;
E 8
I 8
  	register union overhead *op;
  	register int bucket;
	register unsigned amt, n;
E 8
E 3

D 3
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
E 3
I 3
	/*
D 8
	 * Convert amount of memory requested into
	 * closest block size stored in hash buckets
	 * which satisfies request.  Account for
	 * space used per block for accounting.
E 8
I 8
	 * First time malloc is called, setup page size and
	 * align break pointer so all data will be page aligned.
E 8
	 */
D 8
  	nbytes += sizeof (union overhead) + RSLOP;
  	nbytes = (nbytes + 3) &~ 3; 
  	shiftr = (nbytes - 1) >> 2;
	/* apart from this loop, this is O(1) */
  	while (shiftr >>= 1)
  		bucket++;
E 8
I 8
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
E 8
	/*
I 8
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
		if (amt == 0)
			return (NULL);
		bucket++;
	}
	/*
E 8
	 * If nothing in hash bucket right now,
	 * request more memory from the system.
	 */
D 8
  	if (nextf[bucket] == NULL)    
E 8
I 8
  	if ((op = nextf[bucket]) == NULL) {
E 8
  		morecore(bucket);
D 8
  	if ((p = (union overhead *)nextf[bucket]) == NULL)
  		return (NULL);
E 8
I 8
  		if ((op = nextf[bucket]) == NULL)
  			return (NULL);
	}
E 8
	/* remove from linked list */
D 8
  	nextf[bucket] = nextf[bucket]->ov_next;
	p->ov_magic = MAGIC;
	p->ov_index= bucket;
E 8
I 8
  	nextf[bucket] = op->ov_next;
	op->ov_magic = MAGIC;
	op->ov_index = bucket;
E 8
D 4
#ifdef debug
E 4
  	nmalloc[bucket]++;
D 4
#endif
E 4
#ifdef RCHECK
	/*
	 * Record allocated size of block and
	 * bound space with magic numbers.
	 */
D 8
  	if (nbytes <= 0x10000)
		p->ov_size = nbytes - 1;
	p->ov_rmagic = RMAGIC;
  	*((u_int *)((caddr_t)p + nbytes - RSLOP)) = RMAGIC;
E 8
I 8
	op->ov_size = (nbytes + RSLOP - 1) & ~(RSLOP - 1);
	op->ov_rmagic = RMAGIC;
  	*(u_short *)((caddr_t)(op + 1) + op->ov_size) = RMAGIC;
E 8
#endif
D 8
  	return ((char *)(p + 1));
E 8
I 8
  	return ((char *)(op + 1));
E 8
E 3
}

D 3
/*	freeing strategy tuned for LIFO allocation
*/
free(ap)
register char *ap;
E 3
I 3
/*
 * Allocate more memory to the indicated bucket.
 */
D 8
static
E 8
morecore(bucket)
D 8
	register bucket;
E 8
I 8
	int bucket;
E 8
E 3
{
D 3
	register union store *p = (union store *)ap;
E 3
I 3
  	register union overhead *op;
D 8
  	register int rnu;       /* 2^rnu bytes will be requested */
  	register int nblks;     /* become nblks blocks of the desired size */
	register int siz;
E 8
I 8
	register int sz;		/* size of desired block */
  	int amt;			/* amount to allocate */
  	int nblks;			/* how many blocks we get */
E 8
E 3

D 3
	ASSERT(p>clearbusy(allocs[1].ptr)&&p<=alloct);
	ASSERT(allock());
	allocp = --p;
/* 	ASSERT(testbusy(p->ptr)); */
	p->ptr = clearbusy(p->ptr);
	ASSERT(p->ptr > allocp && p->ptr <= alloct);
E 3
I 3
D 8
  	if (nextf[bucket])
  		return;
E 8
	/*
D 8
	 * Insure memory is allocated
	 * on a page boundary.  Should
	 * make getpageize call?
E 8
I 8
	 * sbrk_size <= 0 only for big, FLUFFY, requests (about
	 * 2^30 bytes on a VAX, I think) or for a negative arg.
E 8
	 */
D 8
  	op = (union overhead *)sbrk(0);
  	if ((int)op & 0x3ff)
D 4
  		sbrk(1024 - ((int)op & 0x3ff));
E 4
I 4
  		(void) sbrk(1024 - ((int)op & 0x3ff));
E 4
	/* take 2k unless the block is bigger than that */
  	rnu = (bucket <= 8) ? 11 : bucket + 3;
  	nblks = 1 << (rnu - (bucket + 3));  /* how many blocks to get */
  	if (rnu < bucket)
		rnu = bucket;
	op = (union overhead *)sbrk(1 << rnu);
E 8
I 8
	sz = 1 << (bucket + 3);
#ifdef DEBUG
	ASSERT(sz > 0);
#else
	if (sz <= 0)
		return;
#endif
	if (sz < pagesz) {
		amt = pagesz;
  		nblks = amt / sz;
	} else {
		amt = sz + pagesz;
		nblks = 1;
	}
	op = (union overhead *)sbrk(amt);
E 8
	/* no more room! */
  	if ((int)op == -1)
  		return;
	/*
D 8
	 * Round up to minimum allocation size boundary
	 * and deduct from block count to reflect.
	 */
  	if ((int)op & 7) {
  		op = (union overhead *)(((int)op + 8) &~ 7);
  		nblks--;
  	}
	/*
E 8
	 * Add new memory allocated to that on
	 * free list for this hash bucket.
	 */
  	nextf[bucket] = op;
D 8
  	siz = 1 << (bucket + 3);
E 8
  	while (--nblks > 0) {
D 8
		op->ov_next = (union overhead *)((caddr_t)op + siz);
		op = (union overhead *)((caddr_t)op + siz);
E 8
I 8
		op->ov_next = (union overhead *)((caddr_t)op + sz);
		op = (union overhead *)((caddr_t)op + sz);
E 8
  	}
E 3
}

D 3
/*	realloc(p, nbytes) reallocates a block obtained from malloc()
 *	and freed since last call of malloc()
 *	to have new size nbytes, and old content
 *	returns new location, or 0 on failure
*/
E 3
I 3
free(cp)
	char *cp;
{   
  	register int size;
	register union overhead *op;
E 3

D 3
char *
realloc(p, nbytes)
register union store *p;
unsigned nbytes;
{
	register union store *q;
	union store *s, *t;
	register unsigned nw;
	unsigned onw;
E 3
I 3
  	if (cp == NULL)
  		return;
	op = (union overhead *)((caddr_t)cp - sizeof (union overhead));
E 3
D 8

E 8
D 3
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
#ifdef	V6
		copy(t++, s++, sizeof (*t));
E 3
I 3
	/* 
D 8
	** The following botch is because csh tries to free a free block
	** when processing the =~ or !~ operators. -- layer@ucbmonet
E 8
I 8
	 * The following botch is because csh tries to free a free block
	 * when processing the =~ or !~ operators. -- layer@ucbmonet
E 8
	*/
D 8
#ifdef CSHbotch /* was debug */
E 8
I 8
#ifdef CSHbotch /* was DEBUG */
E 8
  	ASSERT(op->ov_magic == MAGIC);		/* make sure it was in use */
E 3
#else
D 3
		*t++ = *s++;
E 3
I 3
	if (op->ov_magic != MAGIC)
		return;				/* sanity */
E 3
#endif
D 3
	if(q<p && q+nw>=p)
		(q+(q+nw-p))->ptr = allocx;
	return((char *)q);
}
E 3
D 8

E 8
I 3
#ifdef RCHECK
  	ASSERT(op->ov_rmagic == RMAGIC);
D 8
	if (op->ov_index <= 13)
		ASSERT(*(u_int *)((caddr_t)op + op->ov_size + 1 - RSLOP) == RMAGIC);
E 8
I 8
	ASSERT(*(u_short *)((caddr_t)(op + 1) + op->ov_size) == RMAGIC);
E 8
#endif
D 8
  	ASSERT(op->ov_index < NBUCKETS);
E 8
  	size = op->ov_index;
D 8
	op->ov_next = nextf[size];
E 8
I 8
  	ASSERT(size < NBUCKETS);
	op->ov_next = nextf[size];	/* also clobbers ov_magic */
E 8
  	nextf[size] = op;
E 3
D 4
#ifdef debug
E 4
D 3
allock()
{
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
E 3
I 3
  	nmalloc[size]--;
E 3
D 4
#endif
E 4
}
D 3
#endif
E 3

I 3
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
D 8
int realloc_srchlen = 4;	/* 4 should be plenty.  -1 means whole list */
E 8
I 8
int realloc_srchlen = 4;	/* 4 should be plenty, -1 =>'s whole list */
E 8

char *
realloc(cp, nbytes)
	char *cp; 
	unsigned nbytes;
{   
D 8
  	register u_int onb;
E 8
I 8
  	register u_int onb, i;
E 8
	union overhead *op;
  	char *res;
D 8
	register int i;
E 8
	int was_alloced = 0;

  	if (cp == NULL)
  		return (malloc(nbytes));
	op = (union overhead *)((caddr_t)cp - sizeof (union overhead));
	if (op->ov_magic == MAGIC) {
		was_alloced++;
		i = op->ov_index;
D 8
	}
	else {		/* already free: he is doing "compaction" (tee hee) */
E 8
I 8
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
		 * largest possible (so that all "nbytes" of new
		 * memory are copied into).  Note that this could cause
		 * a memory fault if the old area was tiny, and the moon
		 * is gibbous.  However, that is very unlikely.
		 */
E 8
		if ((i = findbucket(op, 1)) < 0 &&
		    (i = findbucket(op, realloc_srchlen)) < 0)
D 8
			i = 0;		/* assume smallest possible */
E 8
I 8
			i = NBUCKETS;
E 8
	}
D 8
	onb = (1 << (i + 3)) - sizeof (*op) - RSLOP;
	if (was_alloced &&		/* avoid the copy if same size block */
	    nbytes <= onb && nbytes > (onb >> 1) - sizeof(*op) - RSLOP)
		return(cp);
E 8
I 8
	onb = 1 << (i + 3);
	if (onb < pagesz)
		onb -= sizeof (*op) + RSLOP;
	else
		onb += pagesz - sizeof (*op) - RSLOP;
	/* avoid the copy if same size block */
	if (was_alloced) {
		if (i) {
			i = 1 << (i + 2);
			if (i < pagesz)
				i -= sizeof (*op) + RSLOP;
			else
				i += pagesz - sizeof (*op) - RSLOP;
		}
		if (nbytes <= onb && nbytes > i) {
#ifdef RCHECK
			op->ov_size = (nbytes + RSLOP - 1) & ~(RSLOP - 1);
			*(u_short *)((caddr_t)(op + 1) + op->ov_size) = RMAGIC;
#endif
			return(cp);
		} else
			free(cp);
	}
E 8
  	if ((res = malloc(nbytes)) == NULL)
  		return (NULL);
D 8
  	if (cp != res)			/* common optimization */
E 8
I 8
  	if (cp != res)		/* common optimization if "compacting" */
E 8
		bcopy(cp, res, (nbytes < onb) ? nbytes : onb);
D 8
  	if (was_alloced)
		free(cp);
E 8
  	return (res);
}

/*
 * Search ``srchlen'' elements of each free list for a block whose
 * header starts at ``freep''.  If srchlen is -1 search the whole list.
 * Return bucket number, or -1 if not found.
 */
static
findbucket(freep, srchlen)
D 8
union overhead *freep;
int srchlen;
E 8
I 8
	union overhead *freep;
	int srchlen;
E 8
{
	register union overhead *p;
	register int i, j;

D 8
	for (i = 0; i < NBUCKETS; i++)
		for (j = 0, p = nextf[i]; p && j != srchlen; j++, p = p->ov_next)
E 8
I 8
	for (i = 0; i < NBUCKETS; i++) {
		j = 0;
		for (p = nextf[i]; p && j != srchlen; p = p->ov_next) {
E 8
			if (p == freep)
				return (i);
I 8
			j++;
		}
	}
E 8
	return (-1);
}

E 3
D 4
#ifdef debug
E 4
D 3
showall(v)
	char **v;
E 3
I 3
/*
 * mstats - print out statistics about malloc
 * 
 * Prints two lines of numbers, one showing the length of the free list
 * for each size category, the second showing the number of mallocs -
 * frees for each size category.
 */
showall(s)
D 4
	char **s;
E 4
I 4
char **s;
E 4
E 3
{
D 3
	register union store *p, *q;
	int used = 0, free = 0, i;
E 3
I 3
D 4
  	register int i, j;
  	register union overhead *p;
  	int totfree = 0,
  	totused = 0;
E 4
I 4
	register int i, j;
	register union overhead *p;
	int totfree = 0,
	totused = 0;
E 4
E 3

D 3
	for (p = clearbusy(allocs[1].ptr); p != alloct; p = q) {
		q = clearbusy(p->ptr);
		if (v[1])
		printf("%6o %5d %s\n", p,
		    ((unsigned) q - (unsigned) p),
		    testbusy(p->ptr) ? "BUSY" : "FREE");
		i = ((unsigned) q - (unsigned) p);
		if (testbusy(p->ptr)) used += i; else free += i;
	}
D 2
	printf("%d used, %d free, %l end\n", used, free, clearbusy(alloct));
E 2
I 2
	printf("%d used, %d free, %ld end\n", used, free, clearbusy(alloct));
E 3
I 3
	if (s[1])
D 4
	    printf("Memory allocation statistics %s\nfree:\t", s[1]);
  	for (i = 0; i < NBUCKETS; i++) {
  		for (j = 0, p = nextf[i]; p; p = p->ov_next, j++)
  			;
	
  		if (s[1])
		    printf(" %d", j);
  		totfree += j * (1 << (i + 3));
  	}
E 4
I 4
		printf("Memory allocation statistics %s\nfree:", s[1]);
	for (i = 0; i < NBUCKETS; i++) {
		for (j = 0, p = nextf[i]; p; p = p->ov_next, j++)
			;
D 8

E 8
		if (s[1])
			printf(" %d", j);
		totfree += j * (1 << (i + 3));
	}
E 4
	if (s[1])
D 4
  	    printf("\nused:\t");
  	for (i = 0; i < NBUCKETS; i++) {
  		if (s[1])
		    printf(" %d", nmalloc[i]);
  		totused += nmalloc[i] * (1 << (i + 3));
  	}
E 4
I 4
		printf("\nused:");
	for (i = 0; i < NBUCKETS; i++) {
		if (s[1])
			printf(" %d", nmalloc[i]);
		totused += nmalloc[i] * (1 << (i + 3));
	}
E 4
	if (s[1])
D 4
	    printf("\n\t");
  	printf("Total in use: %d, total free: %d\n", totused, totfree);
E 4
I 4
		printf("\n");
	printf("Total in use: %d, total free: %d\n", totused, totfree);
E 4
E 3
E 2
}
D 4
#endif
E 4
E 1
