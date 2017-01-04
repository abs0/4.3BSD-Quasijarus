h51704
s 00022/00000/00000
d D 1.1 86/07/20 11:14:00 sam 1 0
c date and time created 86/07/20 11:14:00 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
casel(infop)	process_info *infop;
/*
/*	Case (longword).
/*	Can't use real HW opcode, don't want to branch out !
/*
/***********************************/
{
	register long selector, base;
	register unsigned temporary, limit;

	selector = operand(infop,0)->data;
	base = operand(infop,1)->data;
	limit = operand(infop,2)->data;
	if (pc & 1) pc += 1;	/* Displacements are aligned ! */
	temporary = selector - base;
	if (temporary <= limit)
		pc = pc + get_word (infop, (char *)(pc + 2*temporary) );
	else pc = pc + limit*2 + 2;
}
E 1
