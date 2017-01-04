h38343
s 00017/00000/00000
d D 1.1 86/07/20 11:13:56 sam 1 0
c date and time created 86/07/20 11:13:56 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
bbs(infop)	process_info *infop;
/*
/*	Branch on bit set.
/*
/********************************/
{
	register int position,base, new_address;

	position = operand(infop,0)-> data & 0x1f;
	base = operand(infop,1)->data;
	new_address = operand(infop,2) -> address;
	negative_0; zero_1; overflow_0; carry_1;
	if  (base & 1 << position) pc = new_address;
}
E 1
