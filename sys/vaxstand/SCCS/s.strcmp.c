h18970
s 00018/00000/00000
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
E 1
