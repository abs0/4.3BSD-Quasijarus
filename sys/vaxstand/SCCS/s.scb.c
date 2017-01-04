h52662
s 00001/00001/00063
d D 7.2 04/02/26 18:02:18 msokolov 2 1
c oops, need movl, not moval
e
s 00064/00000/00000
d D 7.1 04/02/07 11:33:52 msokolov 1 0
c date and time created 04/02/07 11:33:52 by msokolov
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
 */

#include "../vax/mtpr.h"

	.text
	.globl	_setupscb
_setupscb:
	.word	0
D 2
	moval	4(ap),r0
E 2
I 2
	movl	4(ap),r0
E 2
#ifndef SMALL
	clrl	r1	
1:	addl3    $_scb_catcher+1,r1,(r0)+ # point each vector loc to handler
					# +1 to handle on the interrupt stack
	addl2	$8,r1			#
	cmpw	$1024,r1
	bneq	1b
#else SMALL
	movl	$128,r1
1:	movl	$_scb_catcher+1,(r0)+
	sobgtr	r1,1b
#endif SMALL
	mtpr	4(ap),$SCBB
	ret

	.text
	.align	2
	.globl	_scb_catcher
_scb_catcher:
#ifdef SMALL
	pushab	scbint
	calls	$1,_printf
	halt
#else SMALL
#define PJ pushr $0x3f;jsb Xstray
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
	PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ;PJ
#undef PJ
Xstray:
	/*
	 * Calculate and report the vector location of the stray
	 * scb interrupt
	 */
	subl3	$_scb_catcher+8,(sp)+,r0
	ashl	$-1,r0,-(sp)
	pushal	exception               # push the address of the text
	calls	$2,_printf              # print it
	halt                            # no recovery
#endif SMALL

	.data
#ifndef SMALL
exception:
	.asciz  "Unexpected exception at SCB vector 0x%x\n"
#else
scbint:	.asciz	"scbint"
#endif SMALL
E 1
