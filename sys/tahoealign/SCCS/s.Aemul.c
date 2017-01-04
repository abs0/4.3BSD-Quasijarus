h03614
s 00029/00000/00000
d D 1.1 86/07/20 11:14:14 sam 1 0
c date and time created 86/07/20 11:14:14 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/


#include "../tahoealign/align.h"
emul(infop)	process_info *infop;
/*
/*	Extended precision multiplication.
/*
/***************************************/
{
	register long Register_12;	/* multiplicand */
	register long Register_11;	/* product least */
	register long Register_10;	/* product most */
	register long Register_9;	/* addend */
	register long Register_8;	/* multiplier */
	quadword result;

	Register_8 = operand(infop, 0)->data;
	Register_12 = operand(infop, 1)->data;
	Register_9 = operand(infop, 2)->data;
	Register_10=psl;
	Set_psl(r10);	/* restore the user psl */
	asm ("	emul	r8,r12,r9,r10");
	asm ("	movpsl	r8");
	New_cc (Register_8);
	result.high = Register_10;
	result.low  = Register_11;
	write_quadword (infop, result, operand(infop, 3));
}
E 1
