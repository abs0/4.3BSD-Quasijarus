h35077
s 00021/00000/00000
d D 5.1 2012/06/15 06:47:39 msokolov 1 0
c date and time created 2012/06/15 06:47:39 by msokolov
e
u
U
t
T
I 1
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley) %E%"
#endif LIBC_SCCS

/* see unix2mjdtime(3) man page for the documentation */

#include "DEFS.h"
#include <calendardefs.h>

ENTRY(unix2mjdtime, 0)
#ifdef notyet
	/* 64-bit time_t */
	movq	*4(ap),r1
#else
	movl	*4(ap),r1
	clrl	r2
#endif
	movl	8(ap),r5
	ediv	$86400,r1,r3,4(r5)
	addl3	$UNIX_EPOCH_MJD,r3,0(r5)
	ret
E 1
