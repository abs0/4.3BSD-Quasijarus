#ifdef LIBC_SCCS
	.asciz	"@(#)emul.s	5.1 (Berkeley) 2011/10/18"
#endif LIBC_SCCS

/* see emul(3) man page for the documentation */

#include "DEFS.h"

ENTRY(emul, 0)
	emul	4(ap),8(ap),12(ap),r0
	ret

ENTRY(emulu, 0)
	emul	4(ap),8(ap),12(ap),r0
	/* now apply corrections */
	tstl	4(ap)
	bgeq	1f
	addl2	8(ap),r1
1:	tstl	8(ap)
	bgeq	1f
	addl2	4(ap),r1
1:	tstl	12(ap)
	bgeq	1f
	incl	r1
1:	ret
