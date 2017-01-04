h23514
s 00014/00000/00000
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
bispsw(infop)	process_info *infop;
/*
/*	Bits set in PSW.
/*
/*************************************/
{
	register int mask;

	mask = operand(infop,0)->data;
	psl |= mask & 0x7f;
}
E 1
