h44183
s 00037/00000/00000
d D 1.1 86/07/02 16:25:57 sam 1 0
c date and time created 86/07/02 16:25:57 by sam
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

/*
 * Reserved floating point operand.
 */
ASENTRY(sfpresop, 0)
	movl	$0xaaaaaaaa,r0
	clrl	r1
	ret

/*
 * Floating point overflow.
 */
ASENTRY(sfpover, 0)
	movl	$HUGE0,r0
	clrl	r1
	ret

/*
 * Floating point underflow.
 */
ASENTRY(sfpunder, 0)
	clrl	r0
	clrl	r1
	ret

/*
 * Floating point division by zero.
 */
ASENTRY(sfpzdiv, 0)
	divl2	$0,r0		# force division by zero.
	ret
E 1
