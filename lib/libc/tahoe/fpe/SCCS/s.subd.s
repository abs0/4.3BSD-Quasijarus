h24909
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

XENTRY(subd, 0)
	pushl	16(fp)
	pushl	12(fp)
	callf	$12,Xnegd
	pushl	r1
	pushl	r0
	pushl	8(fp)
	pushl	4(fp)
	callf	$20,Xaddd
	ret
E 1
