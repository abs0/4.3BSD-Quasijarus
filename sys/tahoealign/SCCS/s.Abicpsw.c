h23804
s 00014/00000/00000
d D 1.1 86/07/20 11:13:57 sam 1 0
c date and time created 86/07/20 11:13:57 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
bicpsw(infop)	process_info *infop;
/*
/*	Bits clear in PSW.
/*
/*************************************/
{
	register int mask;

	mask = operand(infop,0)->data;
	psl &= ~(mask & 0x7f);
}
E 1
