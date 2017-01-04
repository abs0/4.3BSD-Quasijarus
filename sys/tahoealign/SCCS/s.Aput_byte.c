h47251
s 00023/00000/00000
d D 1.1 86/07/20 11:14:36 sam 1 0
c date and time created 86/07/20 11:14:36 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include	"../tahoealign/align.h"

put_byte (infop, byte, where)
process_info	*infop;
char		*where;
long		byte;
/*
/*	Put the byte at the given address in memory.
/*	Caveat: It's quite difficult to find a pte reference
/*		fault.  So I took the easy way out and just signal
/*		an illegal access.
/*	
/**************************************************/
{
	register long code;

	code = writeable(infop, where, 1);
	if ( code == TRUE ) {
		*where = byte;
	} else exception (infop, ILL_ACCESS, where, code);
}
E 1
