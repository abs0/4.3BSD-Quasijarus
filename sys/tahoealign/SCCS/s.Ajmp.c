h21386
s 00012/00000/00000
d D 1.1 86/07/20 11:14:18 sam 1 0
c date and time created 86/07/20 11:14:18 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
jmp(infop)
process_info *infop;
/*
/*	Jump to the given address.
/*
/********************************************/
{
	pc = operand(infop,0)->address ;
}
E 1
