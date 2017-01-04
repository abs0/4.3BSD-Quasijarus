h56093
s 00028/00000/00000
d D 1.1 86/07/20 11:14:50 sam 1 0
c date and time created 86/07/20 11:14:50 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include	"../tahoealign/align.h"

write_longword (infop, longword, where)
process_info	*infop;
long		longword;
struct oprnd 	*where;
/*
/*	Put the longword at the given address in
/*	tahoe's memory.
/*
/**************************************************/
{
	if (! (where->mode & W)) exception(infop, ILL_ADDRMOD);
	switch (where->mode & ADDFIELD)	/* Mask out R/W bits */
	{
	case Add:
	case SPmode:
		put_longword (infop, longword, where->address);
		break;
	case Dir:
		Replace (infop, where->reg_number, longword);
		break;
	default:
		printf("Unknown destination in write_long (alignment code)\n");
	};
}	
E 1
