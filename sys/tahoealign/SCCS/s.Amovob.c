h55606
s 00027/00000/00000
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
movob_op(infop) 
process_info *infop;
/*
/*	Move output byte
/*
/****************************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register	long	Register_11;
	register	long	Register_10;
	register	long	code;


	Register_12 = operand(infop,0)->data;
	Register_11 = operand(infop,1)->address;
	code = writeable(infop, Register_11, 1);
	if ( code == TRUE ) {
		Register_10=psl;
		Set_psl(r10);	/* restore the user psl */
		asm ("	movob	r12,(r11)");
		asm ("	movpsl	r12");
		New_cc (Register_12);
	} else exception (infop, ILL_ACCESS, Register_11, code);
}
E 1
