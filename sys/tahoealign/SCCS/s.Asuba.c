h31611
s 00016/00000/00000
d D 1.1 86/07/20 11:14:46 sam 1 0
c date and time created 86/07/20 11:14:46 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
suba(infop)	process_info *infop;
/*
/*	Subtract address.
/*
/****************************/
{
	register int data0, data1, result;

	data0 = operand(infop,0)->data;
	data1 = operand(infop,1)->data;
	result = data1 - data0;
	write_back (infop,result, operand(infop,1));
}
E 1
