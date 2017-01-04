h14671
s 00012/00000/00000
d D 7.1 04/02/07 11:32:39 msokolov 1 0
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

	.globl	_strcpy
_strcpy:
	.word	0
	movq	4(ap),r0
0:	movb	(r1)+,(r0)+
	bneq	0b
	movl	4(ap),r0
	ret
E 1
