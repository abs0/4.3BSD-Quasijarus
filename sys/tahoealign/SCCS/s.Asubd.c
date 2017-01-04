h37974
s 00016/00000/00000
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
subd(infop)	process_info *infop;
/*
/*	Subtract operand from accumulator to accumulator (double).
/*
/*******************************************************************/
{
	register double 	*operand_pnt;
	register double		*acc_pnt;

	operand_pnt = (double *)&operand(infop,0)->data;
	acc_pnt = (double *) &acc_high;
	*acc_pnt = *acc_pnt - *operand_pnt;
}
E 1
