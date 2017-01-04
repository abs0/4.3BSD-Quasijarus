h51473
s 00025/00000/00000
d D 1.1 86/07/20 11:14:41 sam 1 0
c date and time created 86/07/20 11:14:41 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/


#include "../tahoealign/align.h" 

shll(infop)	process_info *infop;
/*
/*	Shift logical left (longword).
/*	Checks for overflow.
/*
/*******************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register	long	Register_11;
	register	long	Register_10;
	
	Register_12 = operand(infop,0)->data;
	Register_11 = operand(infop,1)->data;
	Register_10 = psl;
	Set_psl(r10);	/*save the orig CC bits of the psl */
	asm("	shll	r12,r11,r10");
	asm("	movpsl	r12");
	New_cc (Register_12);
	write_back (infop, Register_10, operand(infop,2));
}
E 1
