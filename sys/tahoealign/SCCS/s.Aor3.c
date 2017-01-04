h46706
s 00021/00000/00000
d D 1.1 86/07/20 11:14:31 sam 1 0
c date and time created 86/07/20 11:14:31 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
or3 (infop)	process_info *infop;
/*
/*	Or , 3 operands.
/*
/****************************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register 	long	data0, data1, result;

	data0 = operand(infop,0)->data; 
	data1 = operand(infop,1)->data; 
	Register_12=psl;
	Set_psl(r12);	/* restore the user psl */
	result = data0 | data1;		/* 32 bits of true result */
	asm ("	movpsl	r12");
	New_cc (Register_12);
	write_back (infop,result, operand(infop,2) );
}
E 1
