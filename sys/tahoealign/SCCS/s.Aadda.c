h27611
s 00014/00000/00000
d D 1.1 86/07/20 11:13:50 sam 1 0
c date and time created 86/07/20 11:13:50 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
adda(infop)	process_info *infop;
/*
/*	Add address.
/*
/************************/
{
	register long result;

	result = operand(infop,1)->data + operand(infop,0)->data;
	write_back (infop,result, operand(infop,1));
}
E 1
