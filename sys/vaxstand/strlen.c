/*
 *	@(#)strlen.c	7.1 (Berkeley) 2/7/04
 */

	.globl	_strlen
_strlen:
	.word	0
	movl	4(ap),r0
0:	tstb	(r0)+
	bneq	0b
	decl	r0
	subl2	4(ap),r0
	ret
