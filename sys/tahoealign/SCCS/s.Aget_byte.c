h48159
s 00021/00000/00000
d D 1.1 86/07/20 11:14:16 sam 1 0
c date and time created 86/07/20 11:14:16 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include	"../tahoealign/align.h"
int get_byte (infop, address)
process_info	*infop;
char		*address;
/*
/*	Fetch the byte at the given 'address' from memory.
/*	Caveat: It's quite difficult to find a pte reference
/*		fault.  So I took the easy way out and just signal
/*		an illegal access.
/*	
/**************************************************/
{
	register long code;

	code = readable(infop, (long)address, 1);
	if ( code == TRUE ) {
		return(*address);
	} else exception (infop, ILL_ACCESS, address, code);
}
E 1
