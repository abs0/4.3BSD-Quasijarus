h58775
s 00027/00000/00000
d D 1.1 86/07/20 11:14:43 sam 1 0
c date and time created 86/07/20 11:14:43 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
shrq(infop) 	process_info *infop;
/*
/*	Shift right quadword.
/*
/********************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register 	long	Register_11;
	register 	long	Register_10;
	register	long	*Register_9;
	quadword	result;

	Register_12 = operand(infop,0)->data;	/* Counter */
	Register_9 = &operand(infop,1)->data;	/* Source */

	Register_10=psl;
	Set_psl(r10);	/* restore the user psl */
	asm ("	shrq	r12,(r9),r10");
	asm ("	movpsl	r12");
	New_cc (Register_12);
	result.high = Register_10;
	result.low  = Register_11;
	write_quadword (infop, result, operand(infop,2));
}
E 1
