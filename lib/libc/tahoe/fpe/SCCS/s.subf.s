h26414
s 00017/00000/00000
d D 1.1 86/07/02 16:25:58 sam 1 0
c date and time created 86/07/02 16:25:58 by sam
e
u
U
t
T
I 1
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley/CCI) %G%"
#endif LIBC_SCCS

#include <tahoemath/fp.h>
#include "DEFS.h"

XENTRY(subf, R2|R3|R4|R5|R6|R7|R8|R9)
	clrl	r1
	pushl	12(fp)
	callf	$8,Xnegf
	pushl	r1
	pushl	r0
	pushl	8(fp)
	pushl	4(fp)
	callf	$20,Xaddf
	ret
E 1
