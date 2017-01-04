h37225
s 00017/00000/00000
d D 1.1 86/07/20 11:14:35 sam 1 0
c date and time created 86/07/20 11:14:35 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
pusha(infop)	process_info *infop;
/*
/*	Push address of the operand
/*
/**************************************/
{
	register long new_address;

	new_address = operand(infop,0)->address;
	if (new_address < 0) negative_1; else negative_0;
	if (new_address == 0) zero_1; else zero_0;
	overflow_0; carry_1;
	push (infop, new_address);
}
E 1
