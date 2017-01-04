h58000
s 00027/00000/00000
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

put_longword (infop, longword, where)
register	process_info	*infop;
register	char		*where;
register	long		longword;
/*
/*	Put the longword at the given address in memory.
/*	Caveat: It's quite difficult to find a pte reference
/*		fault.  So I took the easy way out and just signal
/*		an illegal access.
/*	
/**************************************************/
{
	register long code;

	code = writeable(infop, where, 4);
	if ( code == TRUE ) {
		*where++ = longword>>24;
		*where++ = longword>>16;
		*where++ = longword>>8;
		*where = longword;
	} else exception (infop, ILL_ACCESS, where, code);
}
E 1
