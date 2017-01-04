/*
 *	@(#)strcpy.c	7.1 (Berkeley) 2/7/04
 */

	.globl	_strcpy
_strcpy:
	.word	0
	movq	4(ap),r0
0:	movb	(r1)+,(r0)+
	bneq	0b
	movl	4(ap),r0
	ret
