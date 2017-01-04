h40410
s 00020/00000/00000
d D 1.1 86/07/20 11:14:21 sam 1 0
c date and time created 86/07/20 11:14:21 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h"
lnf(infop)	process_info *infop;
/*
/*	Load a negated float operand into accumulator.
/*
/******************************************************/
{

	register struct oprnd	*op_pnt;

	op_pnt = operand(infop,0);
	if ( reserved( op_pnt->data ) ) 
		exception(infop, ILL_OPRND);
	if ( op_pnt->data == 0 ) acc_high = 0;
	else acc_high = 0x80000000 ^ op_pnt->data ;
	psl &= ~PSL_DBL;
	infop->acc_dbl = 0;
}
E 1
