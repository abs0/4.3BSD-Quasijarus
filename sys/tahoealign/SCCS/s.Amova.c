h45445
s 00020/00000/00000
d D 1.1 86/07/20 11:14:24 sam 1 0
c date and time created 86/07/20 11:14:24 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
mova(infop) 	process_info *infop;
/*
/*	Move operand address
/*
/****************************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register	long	Register_11;

	Register_12 = operand(infop, 0)->address;
	Register_11=psl;
	Set_psl(r11);	/* restore the user psl */
	asm ("	movab	(r12),r11");	/* Moves original addr to r11 */
	asm ("	movpsl	r12");
	New_cc (Register_12);
	write_back (infop, Register_11, operand(infop,1));
}	
E 1
