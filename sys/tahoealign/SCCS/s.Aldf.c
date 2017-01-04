h41220
s 00020/00000/00000
d D 1.1 86/07/20 11:14:19 sam 1 0
c date and time created 86/07/20 11:14:19 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h"
ldf(infop)	process_info *infop;
/*
/*	Load a float operand into accumulator.
/*
/*************************************************/
{

	register struct oprnd *oprnd_pnt;

	oprnd_pnt = operand(infop,0);
	if ( reserved( oprnd_pnt->data ) ) 
		exception(infop, ILL_OPRND);
	if ( (oprnd_pnt->data & 0xff800000) == 0 ) acc_high = 0;
	else acc_high = oprnd_pnt->data ;
	psl &= ~PSL_DBL;
	infop->acc_dbl = 0;
}
E 1
