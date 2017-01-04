h18476
s 00008/00000/00043
d D 5.1 85/05/08 12:36:42 dist 2 1
c Create SCCS file, add copyright
e
s 00043/00000/00000
d D 1.1 85/05/08 12:21:43 dist 1 0
c date and time created 85/05/08 12:21:43 by dist
e
u
U
t
T
I 2
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
# 
#
E 2
I 1
#double asin(arg)
#double arg; -1.0<=arg<=1.0 or an out of range error return
#method: call atan() after range reduction
# calls: satan (internal entry point of atan.s), _sqrt
# J F Jarvis August 8, 1078
.globl	_asin
.globl	_errno
.globl	_sqrt
.globl	satan
.set	EDOM,33
.text
.align	1
_asin:
	.word	0x3c0
	bispsw	$0xe0
	movd	4(ap),r6
	jgtr	a1
	mnegd	r6,r6
a1:	cmpd	r6,$0d1.0e+0
	jleq	a2
	movl	$EDOM,_errno
	clrd	r0
	ret
#
a2:	muld3	r6,r6,r0
	subd3	r0,$0d1.0e+0,-(sp)
	calls	$2,_sqrt
	cmpd	r6,$0d0.6875
	jleq	a3
	divd2	r6,r0
	jsb	satan
	subd3	r0,pio2,r0
	jbr	a4
a3:	divd3	r0,r6,r0
	jsb	satan
a4:	tstd	4(ap)
	jleq	a5
	ret
a5:	mnegd	r0,r0
	ret
.data
.align	2
pio2: .double 0d1.57079632679489661923e+0
E 1
