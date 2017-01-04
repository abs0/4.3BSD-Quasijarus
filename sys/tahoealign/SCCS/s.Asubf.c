h37482
s 00017/00000/00000
d D 1.1 86/07/20 11:14:47 sam 1 0
c date and time created 86/07/20 11:14:47 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/


#include "../tahoealign/align.h"
subf(infop)	process_info *infop;
/*
/*	Subtract operand from accumulator to accumulator (float).
/*
/*******************************************************************/
{
	register float 	*operand_pnt;
	register float		*acc_pnt;

	operand_pnt = (float *)&operand(infop,0)->data;
	acc_pnt = (float *) &acc_high;
	*acc_pnt = *acc_pnt - *operand_pnt;
}
E 1
