h40033
s 00018/00000/00000
d D 1.1 86/07/20 11:14:08 sam 1 0
c date and time created 86/07/20 11:14:08 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h"
cvt(infop) 	process_info *infop;
/*
/*	Convert , checks overflow
/*
/****************************************/
{
	register long result;

	result = operand(infop,0)->data;
	if (result < 0 )  negative_1 ; else negative_0;
	if (result == 0 )  zero_1 ; else zero_0;
	carry_1; overflow_0;
		/* Overflow may be set by writing back */
	write_back (infop, result, operand(infop,1) );
}
E 1
