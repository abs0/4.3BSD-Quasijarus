h40117
s 00019/00000/00000
d D 1.1 86/07/20 11:14:20 sam 1 0
c date and time created 86/07/20 11:14:20 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h"
ldfd(infop)	process_info *infop;
/*
/*	Load into accumulator float operand converted to double.
/*
/***************************************************************/
{
	register struct oprnd *oprnd_pnt;

	oprnd_pnt = operand(infop,0);
	if ( reserved( oprnd_pnt->data ) ) 
		exception(infop, ILL_OPRND);
	acc_high = oprnd_pnt->data ;
	acc_low = 0;
	psl |= PSL_DBL;
	infop->acc_dbl = 1;
}
E 1
