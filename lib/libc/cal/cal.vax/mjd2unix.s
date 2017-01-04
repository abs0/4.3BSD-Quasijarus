#ifdef LIBC_SCCS
	.asciz	"@(#)mjd2unix.s	5.1 (Berkeley) 2012/06/15"
#endif LIBC_SCCS

/* see mjd2unixtime(3) man page for the documentation */

#include "DEFS.h"
#include <calendardefs.h>

ENTRY(mjd2unixtime, 0)
	movl	4(ap),r5
	subl3	$UNIX_EPOCH_MJD,0(r5),r2
	emul	$86400,r2,4(r5),r0
	ret
