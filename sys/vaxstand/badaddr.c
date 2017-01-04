/*
 *	@(#)badaddr.c	7.1 (Berkeley) 2/7/04
 */

#define LOCORE
#include "../vax/cpu.h"
#include "../vax/mtpr.h"

	.globl	_badaddr
_badaddr:
	.word	0
	movl	$1,r0
	movl	4(ap),r3
	movl	8(ap),r4
	mfpr	$SCBB,r2
	addl2	$4,r2
	movl	(r2),r5
	movab	9f,(r2)
	bbc	$0,r4,1f; tstb	(r3)
1:	bbc	$1,r4,1f; tstw	(r3)
1:	bbc	$2,r4,1f; tstl	(r3)
1:	clrl	r0			# made it w/o machine checks
2:	movl	r5,(r2)
	ret
	.align	2
9:
	casel	_cpu,$1,$VAX_MAX
0:
	.word	8f-0b		# 1 is 780
	.word	5f-0b		# 2 is 750
	.word	5f-0b		# 3 is 730
	.word	6f-0b		# 4 is 8600
	.word	5f-0b		# 5 is 8200
	.word	1f-0b		# 6 is 8800
	.word	1f-0b		# 7 is 610
	.word	5f-0b		# 8 is 630
	.word	1f-0b		# 9 is ???
	.word	1f-0b		# 10 is 650
5:
	mtpr	$0xf,$MCESR
	brb	1f
6:
	mtpr	$0,$EHSR
	brb	1f
8:
	mtpr	$0,$SBIFS
1:
	addl2	(sp)+,sp		# discard mchchk trash
	movab	2b,(sp)
	rei
