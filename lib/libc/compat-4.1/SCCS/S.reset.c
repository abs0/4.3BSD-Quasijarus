h21202
s 00020/00000/00000
d D 4.1 83/06/30 16:11:54 sam 1 0
c date and time created 83/06/30 16:11:54 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/*
 * Backwards compatible setexit/reset.
 */
#include <setjmp.h>

static	jmp_buf save;

setexit()
{
	
	return (setjmp(save));
}

reset(x)
{

	longjmp(save, x);
}
E 1
