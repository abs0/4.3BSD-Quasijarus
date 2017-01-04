h45200
s 00037/00000/00000
d D 1.1 86/07/02 16:25:53 sam 1 0
c date and time created 86/07/02 16:25:53 by sam
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
ASENTRY(fpresop, 0)
	movl	$0xaaaaaaaa,r0
	movl	$0xaaaaaaaa,r1
	ret

/*
 * Floating point overflow.
 */
ASENTRY(fpover, 0)
	movl	$HUGE0,r0
	movl	$HUGE1,r1
	ret

/*
 * Floating point underflow.
 */
ASENTRY(fpunder, 0)
	clrl	r0
	clrl	r1
	ret

/*
 * Floating point division by zero.
 */
ASENTRY(fpzdiv, 0)
	divl2	$0,r1		# force division by zero.
	ret
E 1
