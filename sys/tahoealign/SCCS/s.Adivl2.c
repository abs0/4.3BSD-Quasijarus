h53353
s 00027/00000/00000
d D 1.1 86/07/20 11:14:12 sam 1 0
c date and time created 86/07/20 11:14:12 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
divl2(infop) 	process_info *infop;
/*
/*	Arithmetic division, 2 operands.
/*
/**************************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register 	long	divident, divisor, result;

	divisor = operand(infop,0)->data;
	divident = operand(infop,1)->data;
	if (divisor == 0) {
		exception (infop, ARITHMETIC, 2);
	} else {
		Register_12=psl;
		Set_psl(r12);	/* restore the user psl */
		result = divident / divisor;
		asm ("	movpsl	r12");
		New_cc (Register_12);
	}
	write_back (infop,result, operand(infop,1));
}


E 1
