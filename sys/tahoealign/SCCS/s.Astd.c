h38496
s 00019/00000/00000
d D 1.1 86/07/20 11:14:43 sam 1 0
c date and time created 86/07/20 11:14:43 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h"
std(infop)	process_info *infop;
/*
/*	Store accumulator (double) in destination.
/*
/*************************************************/
{
	quadword ac;

	ac.high = acc_high;
	ac.low = acc_low;
	write_quadword (infop, ac, operand(infop,0) );
	if (ac.high < 0) negative_1; else negative_0;
	if ( (ac.high & 0xff800000) == 0 ) zero_1; else zero_0;
	carry_1;
	overflow_0;
}
E 1
