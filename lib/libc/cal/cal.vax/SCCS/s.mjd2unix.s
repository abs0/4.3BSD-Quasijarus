h28658
s 00014/00000/00000
d D 5.1 2012/06/15 06:47:38 msokolov 1 0
c date and time created 2012/06/15 06:47:38 by msokolov
e
u
U
t
T
I 1
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley) %E%"
#endif LIBC_SCCS

/* see mjd2unixtime(3) man page for the documentation */

#include "DEFS.h"
#include <calendardefs.h>

ENTRY(mjd2unixtime, 0)
	movl	4(ap),r5
	subl3	$UNIX_EPOCH_MJD,0(r5),r2
	emul	$86400,r2,4(r5),r0
	ret
E 1
