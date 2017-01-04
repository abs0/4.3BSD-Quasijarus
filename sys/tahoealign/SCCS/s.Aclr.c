h24205
s 00016/00000/00000
d D 1.1 86/07/20 11:14:02 sam 1 0
c date and time created 86/07/20 11:14:02 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
clr(infop)	process_info *infop;
/*
/*	Clear operand
/*
/*************************************/
{

	write_back(infop, 0, operand(infop,0));
	negative_0;
	zero_1;
	overflow_0;
	carry_1;
}
E 1
