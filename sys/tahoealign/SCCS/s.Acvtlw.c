h41511
s 00020/00000/00000
d D 1.1 86/07/20 11:14:10 sam 1 0
c date and time created 86/07/20 11:14:10 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h"
cvtlw(infop) 
process_info *infop;
/*
/*	Convert longword to word
/*
/****************************************/
{
	register long result;

	result = operand(infop,0)->data;
	if (result < 0 )  negative_1 ; else negative_0;
	if (result == 0 )  zero_1 ; else zero_0;
	carry_1; 
	if (result > 0x7fff || result <= -0x8000) overflow_1;
	else overflow_0;
	write_back (infop, result, operand(infop,1) );
}
E 1
