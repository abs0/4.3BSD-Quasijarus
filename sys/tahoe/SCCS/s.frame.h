h36822
s 00003/00001/00010
d D 7.1 88/05/21 18:35:12 karels 2 1
c bring up to revision 7 for tahoe release
e
s 00011/00000/00000
d D 1.1 86/01/05 18:46:20 sam 1 0
c date and time created 86/01/05 18:46:20 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 *	%W% (Berkeley) %G%
 */
E 2

/*
 * Definition of the tahoe call frame.
 */
struct frame {
	int	fr_savpc;		/* saved program counter */
	u_int	fr_mask:16,		/* register save mask */
		fr_removed:16;		/* 4*number of arguments + 4 */
	int	fr_savfp;		/* saved frame pointer */
};
E 1
