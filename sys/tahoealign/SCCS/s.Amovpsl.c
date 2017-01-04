h21951
s 00011/00000/00000
d D 1.1 86/07/20 11:14:25 sam 1 0
c date and time created 86/07/20 11:14:25 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "../tahoealign/align.h" 
movpsl(infop)	process_info *infop;
/*
/*	Move PSL to some place.
/*
/************************************/
{
	write_back (infop, psl, operand(infop,0));
}
E 1
