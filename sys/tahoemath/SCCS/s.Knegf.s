h64532
s 00003/00003/00017
d D 1.3 86/01/05 18:51:05 sam 3 2
c working (mostly)
e
s 00005/00003/00015
d D 1.2 86/01/03 23:47:08 sam 2 1
c massive cleanups; use SYS.h macros to allow profiling; moved to 
c tahoemath directory; revamp comments for cpp
e
s 00018/00000/00000
d D 1.1 85/08/02 15:31:21 sam 1 0
c date and time created 85/08/02 15:31:21 by sam
e
u
U
t
T
I 2
/*	%M%	%I%	%E%	*/
E 2
I 1

D 3
#include "fp.h"
D 2
#include "fp_in_krnl.h"
E 2
I 2
#include "Kfp.h"
#include "SYS.h"
E 3
I 3
#include "../tahoemath/fp.h"
#include "../tahoemath/Kfp.h"
#include "../tahoe/SYS.h"
E 3

E 2
	.text
D 2
	.globl	_Knegf
_Knegf:	.word	0x0000
E 2
I 2
ENTRY(Knegf, 0)
E 2
	clrl	r1
	andl3	$EXPMASK,4(fp),r0	/* check for reserved operand,zero. */
	beql	retzero
	movl	4(fp),r0		/* fetch operand. */
	bbc	$31,r0,seton
	andl2	$(0!SIGNBIT),r0		/* turn it off. */
	ret
seton:	orl2	$SIGNBIT,r0		/* turn it on. */
	ret
retzero:
	clrl	r0
	ret
E 1
