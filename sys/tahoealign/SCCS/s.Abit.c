h42602
s 00021/00000/00000
d D 1.1 86/07/20 11:13:58 sam 1 0
c date and time created 86/07/20 11:13:58 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
bit(infop) 	process_info *infop;
/*
/*	Test set bits
/*
/***************************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register	long	Register_11;
	register	long	Register_10;

	Register_11 = operand(infop,0)->data;
	Register_12 = operand(infop,1)->data;
	Register_10=psl;
	Set_psl(r10);	/* restore the user psl */
	asm ("	bitl	r11,r12");
	asm ("	movpsl	r12");
	New_cc(Register_12);
}
E 1
