h02915
s 00007/00001/00053
d D 5.1 85/06/07 23:24:59 kre 2 1
c Add copyright
e
s 00054/00000/00000
d D 1.1 85/03/28 11:04:38 ralph 1 0
c date and time created 85/03/28 11:04:38 by ralph
e
u
U
t
T
I 1
/*
D 2
char id_malloc[] = "%W%";
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
 *
I 2
 *	%W%	%G%
 */

/*
E 2
 *	allows f77 programs to dynamicly allocate space
 *	three routines:
 *		call malloc(need, addr)
 *		integer need, addr
 *
 *		call free(addr)
 *		integer addr
 *
 *		call falloc( nelem, elsize, clean, basevec, addr, offset )
 *		integer nelem, elsize, clean, addr, offset
 *		dimension basevec(1)
 *
 *	malloc() & falloc() alloc space and put address in 'addr', 0 if can't
 *	do it.  free() frees a block.  malloc() gets a block of at least
 *	'need' bytes; falloc() gets at least nelem*elsize bytes, zeros
 *	the block if clean=1, and returns an offset so that the block
 *	can be referenced as basevec(offset+1)...basevec(offset+nelem)
 *	in the calling program.  falloc() gets an extra element so that
 *	all the elements will be in the block even if address arithmetic
 *	involves truncation.
 */

char *calloc(), *malloc();

malloc_( need, addr )
int *need; char **addr;
{
	*addr = malloc( *need );
}

free_( addr )
char **addr;
{
	free( *addr );
}

falloc_( nelem, elsize, clean, basevec, addr, offset )
int *nelem, *elsize, *clean, *offset;
char **addr, *basevec;
{
	if( *clean == 1 )
		*addr = calloc( *nelem + 1, *elsize );
	else
		*addr = malloc( (*nelem + 1) * *elsize );
		
	if( *addr != 0 )
		*offset = ((*addr - basevec) / *elsize) + 1;
	else
		*offset = 0;

}
E 1
