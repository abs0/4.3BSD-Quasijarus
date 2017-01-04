h40929
s 00024/00000/00000
d D 1.1 86/07/02 16:25:56 sam 1 0
c date and time created 86/07/02 16:25:56 by sam
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

XENTRY(negf, 0)
	clrl	r1
	andl3	$EXPMASK,4(fp),r0	/* check for reserved operand,zero. */
	beql	isreserved
	movl	4(fp),r0		/* fetch operand. */
	bbc	$31,r0,seton
	andl2	$(0!SIGNBIT),r0		/* turn it off. */
	ret
seton:	orl2	$SIGNBIT,r0		/* turn it on. */
	ret
isreserved:
	bbc	$31,4(fp),retzero
	callf	$4,sfpresop
	ret
retzero:
	clrl	r0
	ret
E 1
