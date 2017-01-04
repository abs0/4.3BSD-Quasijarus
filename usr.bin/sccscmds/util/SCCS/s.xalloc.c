h51401
s 00004/00112/00020
d D 1.2 85/05/04 00:26:14 sam 2 1
c no longer used (leave xfree as stub rather than changing all source)
e
s 00132/00000/00000
d D 1.1 82/05/19 17:17:01 rrh 1 0
c date and time created 82/05/19 17:17:01 by rrh
e
u
U
t
T
I 1
# include "../hdr/macros.h"
I 2
# include <stdio.h>
E 2
SCCSID(@(#)xalloc	2.1);

D 2
/*
	xalloc/xfree based on alloc/free in C library at one time.
	Also xfreeall() frees all memory allocated (calls brk(II)).
 
	Xfree always coalesces contiguous free blocks.
	Xalloc uses a first fit strategy.
	Xalloc always allocates words (rounds up).
	Xalloc actually allocates one more word than the
	amount requested.  The extra word (the first word of the
	allocated block) contains the size (in bytes) of the entire block.
	This size is used by xfree to identify contiguous blocks,
	and is used by xalloc to implement the first fit strategy.
 
	Bad things will happen if the size word is changed.
	Worse things happen if xfree is called with a
	garbage argument.
 
	Xalloc returns the address of the allocated area on success,
	fatal() on failure.
	Xfree and xfreeall don't return anything.
*/

struct fb {
	unsigned	f_size;
	char		*f_next;
};

struct fb Freelist {
	0,
	0x3FFFFFFF,
};

# define SLOP	(sizeof(int *))

extern	end;
unsigned Lastbrk	&end;

E 2
xalloc(asize)
unsigned asize;
{
D 2
	register unsigned usize;
	register struct fb *np, *cp;
E 2

D 2
	if((usize = asize) == 0)
		return(0);
	usize =+ 2*sizeof(int *) -1;
	usize =& ~(sizeof(int *) -1);
	for(;;) {
		cp = &Freelist;
		while((np = cp->f_next) != 0x3FFFFFFF) {
			if(np->f_size>=usize) {
			/*
				Don't break the block up if it
				is not more than SLOP bigger than the
				amount needed.
			*/
				if(usize+SLOP >= np->f_size)
					cp->f_next = np->f_next;
			/*
				Break the block into 2 pieces.
			*/
				else {
					cp = cp->f_next = ((int)np) + usize;
					cp->f_size = np->f_size - usize;
					cp->f_next = np->f_next;
					np->f_size = usize;
				}
				zero(&np->f_next,usize-sizeof(int *));
				return(&np->f_next);
			}
			cp = np;
		}
	/*
		Nothing on the free list is big enough;
		get more core from the operating system.
	*/
		asize = usize<1024? 1024: usize;
		asize = (asize+511) & (~511);
		if((cp = sbrk(asize)) == -1) {
			return(fatal("out of space (ut9)"));
		}
		Lastbrk = ((int)cp) + asize;
		cp->f_size = asize;
	/*
		Add the new piece to the free list.
	*/
		xfree(&cp->f_next);
	}
E 2
I 2
	fprintf(stderr, "Call to xalloc!?!\n");
E 2
}


xfree(aptr)
char *aptr;
{
D 2
	register struct fb *ptr, *cp, *np;
E 2

D 2
	if (aptr && aptr < Lastbrk) {
		ptr = aptr-sizeof(int *);
		cp = &Freelist;
		while((np = cp->f_next) < ptr)
			cp = np;
	/*
		Try to coalesce with the following block.
	*/
		if(((int)ptr) + ptr->f_size == ((int)np)) {
			ptr->f_size =+ np->f_size;
			ptr->f_next = np->f_next;
			np = ptr;
		} else
			ptr->f_next = np;
	/*
		Try to coalesce with the preceding block.
	*/
		if(((int)cp) + cp->f_size == ((int)ptr)) {
			cp->f_size =+ ptr->f_size;
			cp->f_next = ptr->f_next;
		} else
			cp->f_next = ptr;
	}
E 2
I 2
	fprintf(stderr, "Call to xfree!?!\n");
E 2
}


xfreeall()
{
D 2
	brk(&end);
	Lastbrk = &end;
	Freelist.f_size = 0;
	Freelist.f_next = 0x3FFFFFFF;
E 2
I 2

E 2
}
E 1
