h49585
s 00022/00000/00000
d D 1.1 86/07/20 11:14:07 sam 1 0
c date and time created 86/07/20 11:14:07 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h"
cvld(infop)	process_info *infop;
/*
/*	Convert integer to double (into accumulator).
/*
/******************************************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register	double	*Register_11;
	register	long	Register_10;

	Register_11 = (double *) &acc_high;
	Register_10 = operand(infop,0)->data;
	Register_12=psl;
	Set_psl(r12);	/* restore the user psl */
	asm ("	cvld	r10");		/* Don't change the order !! */
	asm ("	movpsl	r12");
	asm ("	std	(r11)");
	New_cc (Register_12);
}
E 1
