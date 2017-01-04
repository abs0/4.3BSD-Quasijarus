h36947
s 00016/00000/00000
d D 1.1 86/07/20 11:14:11 sam 1 0
c date and time created 86/07/20 11:14:11 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h"
divf(infop)	process_info *infop;
/*
/*	Divide accumulator by operand to accumulator (float).
/*
/*******************************************************************/
{
	register float	*operand_pnt;
	register float	*acc_pnt;

	operand_pnt = (float *)&operand(infop,0)->data;
	acc_pnt = (float *) &acc_high;
	*acc_pnt = *acc_pnt / *operand_pnt;
}
E 1
