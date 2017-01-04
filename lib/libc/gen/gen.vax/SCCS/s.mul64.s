h39362
s 00025/00000/00000
d D 5.1 2011/10/18 03:36:36 msokolov 1 0
c new function implemented
e
u
U
t
T
I 1
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley) %E%"
#endif LIBC_SCCS

/*
 * See mul64(3) man page for the documentation.
 * Algorithm taken directly from the ancient VAX-11 Architecture Handbook,
 * description of EMUL on page 150.
 */

#include "DEFS.h"

ENTRY(mul64, 0)
	emul	4(ap),12(ap),$0,r0
	mull3	8(ap),12(ap),r2
	addl2	r2,r1
	mull3	4(ap),16(ap),r2
	addl2	r2,r1
	tstl	4(ap)
	bgeq	1f
	addl2	12(ap),r1
1:	tstl	12(ap)
	bgeq	1f
	addl2	4(ap),r1
1:	ret
E 1
