/*
 *	@(#)strcmp.c	7.1 (Berkeley) 2/7/04
 */

	.globl	_strcmp
_strcmp:
	.word	0
	movq	4(ap),r0
0:	cmpb	(r0),(r1)+
	bneq	1f
	tstb	(r0)+
	bneq	0b
	clrl	r0
	ret
1:	cvtbl	(r0),r0
	cvtbl	-(r1),r1
	subl2	r1,r0
	ret
