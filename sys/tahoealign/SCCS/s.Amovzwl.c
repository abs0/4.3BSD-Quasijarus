h47084
s 00021/00000/00000
d D 1.1 86/07/20 11:14:26 sam 1 0
c date and time created 86/07/20 11:14:26 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
movzwl(infop) 	process_info *infop;
/*
/*	Move word to longword, zero-extended
/*
/****************************************/
{
	register long result;
	register struct oprnd *oppnt;

	oppnt = operand(infop,0);
	result = oppnt->data;
	negative_0;
	if (result == 0 )  zero_1 ; else zero_0;
	overflow_0;  carry_1;
	if ((oppnt->mode & 0xff) == Dir) 
		write_back (infop, result , operand(infop,1) );
	else write_back (infop, result & 0xffff, operand(infop,1) );
}
E 1
