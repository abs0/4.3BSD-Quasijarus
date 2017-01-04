h32759
s 00020/00000/00000
d D 1.1 86/07/20 11:14:34 sam 1 0
c date and time created 86/07/20 11:14:34 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include	"../tahoealign/align.h"

push (infop,longword)	process_info *infop;
int	longword;
/*
/*	Push the given datum on the current stack.
/*
/******************************************/
{

	struct oprnd temp;

	temp.mode = Add | W; 
	sp -= 4; 
	temp.address = sp; 
	temp.length = 4;
	write_back(infop,longword, &temp) ;
}
E 1
