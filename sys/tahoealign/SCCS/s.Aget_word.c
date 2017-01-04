h52580
s 00023/00000/00000
d D 1.1 86/07/20 11:14:17 sam 1 0
c date and time created 86/07/20 11:14:17 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include	"../tahoealign/align.h"
int get_word (infop, address)
process_info	*infop;
char		*address;
/*
/*	Fetch the word at the given 'address' from memory.
/*	Caveat: It's quite difficult to find a pte reference
/*		fault.  So I took the easy way out and just signal
/*		an illegal access.
/*	
/**************************************************/
{
	register long code, value;

	code = readable(infop, address, 2);
	if (code == TRUE) {
		value = *address++ << 8;
		value = value | *address & 0xff;
		return(value);
	} else exception (infop, ILL_ACCESS, address, code);
}
E 1
