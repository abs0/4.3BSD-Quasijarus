h45076
s 00022/00000/00000
d D 1.1 86/07/20 11:14:10 sam 1 0
c date and time created 86/07/20 11:14:10 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
dec(infop)	process_info *infop;
/*
/*	Decrement operand.
/*
/***************************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register	long	Register_11;

	Register_11 = operand(infop,0)->data;
	Register_12=psl;
	Set_psl(r12);	/* restore the user psl */
	asm ("	decl	r11");			/* Make sure to use the
						 * right opcode */
	asm ("	movpsl	r12");
	New_cc (Register_12);

	write_back (infop,Register_11, operand(infop,0) );
}	
E 1
