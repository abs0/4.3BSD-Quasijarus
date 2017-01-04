h13885
s 00038/00000/00000
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

write_byte (infop,byte, where)
process_info	*infop;
long		byte; 
struct oprnd 	*where;
/*
/*	Put the 'byte' at the given address in
/*	tahoe's memory.
/*	
/*	1. Only the least significant byte is written.
/*
/**************************************************/
{
	register struct operand_des *look_at;

	look_at = &Table[opCODE].operand[last_operand];
	if (! (look_at->add_modes & NOVF))
		if (byte > 0x7f || byte < -0x80) overflow_1;	
	if (!(where->mode & W)) exception(infop, ILL_ADDRMOD);
	switch (where->mode & ADDFIELD)	/* Mask out R/W bits */
	{
	case Add:
		put_byte(infop, byte, where->address);
		break;
	case Dir:
		Replace (infop, where->reg_number, byte);
		break;
	case SPmode:
		where->mode = where->mode & ~SPmode | Add;
		write_longword (infop, byte, where);
		break;
	default:
		printf("Unknown destination in write_byte (alignment code)\n");
	};
}	
E 1
