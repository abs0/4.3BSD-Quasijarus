h62267
s 00027/00000/00000
d D 1.1 86/07/20 11:14:32 sam 1 0
c date and time created 86/07/20 11:14:32 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 

#define	PSL_USER	PSL_CURMOD
probew(infop)	process_info *infop;
/*
/*	Probe write accessability.
/*
/*************************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register	long	Register_11;
	register	long	Register_10;
	register	long	Register_9;

	Register_9 = operand(infop,0)->data & 1;	/* Required mode */
	if (psl & PSL_USER) Register_9 = 1;		/* user can't probe as
							 *  kernel ! */
	Register_10 = operand(infop,1)->address;	/* Base address */
	Register_11 = operand(infop,2)->data;		/* Length */
	Register_12=psl;
	Set_psl(r12);	/* restore the user psl */
	asm ("	probew	r9,(r10),r11");
	asm ("	movpsl	r12");
	New_cc (Register_12);
}
E 1
