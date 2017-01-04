h14951
s 00013/00000/00000
d D 7.1 04/02/07 11:32:40 msokolov 1 0
c split out of srt0.c
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
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
E 1
