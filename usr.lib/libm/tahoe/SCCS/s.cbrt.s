h06814
s 00010/00006/00097
d D 5.4 88/06/30 17:38:16 bostic 7 6
c install approved copyright notice
e
s 00016/00010/00087
d D 5.3 88/04/29 13:23:23 bostic 6 5
c add Berkeley specific headers
e
s 00000/00000/00097
d D 5.2 87/11/30 18:49:08 bostic 5 4
c tahoe release
e
s 00000/00000/00097
d D 5.1 87/11/30 18:46:16 bostic 4 3
c tahoe release
e
s 00004/00004/00093
d D 1.2 87/07/13 13:38:46 zliu 3 1
c clean-ups.
e
s 00004/00004/00093
d R 1.2 87/07/13 13:06:05 zliu 2 1
c various clean-ups; added Makefile and mcount.sed.
e
s 00097/00000/00000
d D 1.1 87/07/11 18:43:03 zliu 1 0
c date and time created 87/07/11 18:43:03 by zliu
e
u
U
t
T
I 1
D 6
# 
E 6
I 6
D 7
#
E 7
E 6
# Copyright (c) 1987 Regents of the University of California.
D 6
# 
# Use and reproduction of this software are granted  in  accordance  with
# the terms and conditions specified in  the  Berkeley  Software  License
# Agreement (in particular, this entails acknowledgement of the programs'
# source, and inclusion of this notice) with the additional understanding
# that  all  recipients  should regard themselves as participants  in  an
# ongoing  research  project and hence should  feel  obligated  to report
# their  experiences (good or bad) with these elementary function  codes,
# using "sendbug 4bsd-bugs@BERKELEY", to the authors.
E 6
I 6
# All rights reserved.
#
# Redistribution and use in source and binary forms are permitted
D 7
# provided that this notice is preserved and that due credit is given
# to the University of California at Berkeley. The name of the University
# may not be used to endorse or promote products derived from this
# software without specific prior written permission. This software
# is provided ``as is'' without express or implied warranty.
E 7
I 7
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the University of California, Berkeley.  The name of the
# University may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 7
#
# All recipients should regard themselves as participants in an ongoing
# research project and hence should feel obligated to report their
# experiences (good or bad) with these elementary function codes, using
# the sendbug(8) program, to the authors.
#
#	%W% (Berkeley) %G%
E 6
#
	.data
	.align	2
_sccsid:
.asciz	"%Z%%M%	%I%	(ucb.elefunt) %G%"

# double cbrt(double arg)
# W. Kahan, 10/13/80. revised 1/13/84 for keeping sign symmetry
D 3
# Revised and tested by Z. Alex Liu (7/11/87)
E 3
I 3
# Re-coded in tahoe assembly language by Z. Alex Liu (7/13/87)
E 3
# Max error less than 0.667 ULPs _if_ +,-,*,/ were all correctly rounded...
	.globl	_cbrt
	.globl	_d_cbrt
	.globl	_dcbrt_
	.text
D 3
	.align	1
E 3
I 3
	.align	2
E 3
_cbrt:
_d_cbrt:
D 3
	.word	0x01fc		# save r2 to r8
E 3
I 3
	.word	0x01fc		# save r2-r8
E 3
	movl	4(fp),r0	# r0:r1 = x
	movl	8(fp),r1
	brb	1f
_dcbrt_:
D 3
	.word	0x01fc		# save r2 to r8
E 3
I 3
	.word	0x01fc		# save r2-r8
E 3
	movl	4(fp),r8
	movl	(r8),r0
	movl	4(r8),r1	# r0:r1 = x

1:	andl3	$0x7f800000,r0,r2	# biased exponent of x
	beql	return		# dcbrt(0)=0  dcbrt(res)=res. operand
	andl3	$0x80000000,r0,r8	# r8 has sign(x)
	xorl2	r8,r0		# r0 is abs(x)
	movl	r0,r2		# r2 has abs(x)
	divl2	$3,r2		# rough dcbrt with bias/3
	addl2	B,r2		# restore bias, diminish fraction
	ldf	r2		# acc = |q|=|dcbrt| to 5 bits
	mulf	r2		# acc = qq
	divf	r0		# acc = qq/|x|
	mulf	r2		# acc = qqq/|x|
	addf	C		# acc = C+qqq/|x|
	stf	r3		# r3 = s = C+qqq/|x|
	ldf	D		# acc = D
	divf	r3		# acc = D/s
	addf	E		# acc = E+D/s
	addf	r3		# acc = s+E+D/s
	stf	r3		# r3 = s+E+D/s
	ldf	F		# acc = F
	divf	r3		# acc = F/(s+E+D/s)
	addf	G		# acc = G+F/(s+E+D/s)
	mulf	r2		# acc = q*(G+F/(s+E+D/s)) = new q to 23 bits
	stf	r2		# r2 = q*(G+F/(s+E+D/s)) = new q to 23 bits
	clrl	r3		# r2:r3 = q as double float
	ldd	r2		# acc = q as double float
	muld	r2		# acc = qq exactly
	std	r4		# r4:r5 = qq exactly
	ldd	r0		# acc = |x|
	divd	r4		# acc = |x|/(q*q) rounded
	std	r0		# r0:r1 = |x|/(q*q) rounded
	subd	r2		# acc = |x|/(q*q)-q exactly
	std	r6		# r6:r7 = |x|/(q*q)-q exactly
	movl    r2,r4
	clrl	r5		# r4:r5 = q as double float
	addl2	$0x800000,r4	# r4:r5 = 2*q
	ldd	r4		# acc = 2*q
	addd	r0		# acc = 2*q+|x|/(q*q)
	std	r4		# r4:r5 = 2*q+|x|/(q*q)
	ldd	r6		# acc = |x|/(q*q)-q
	divd	r4		# acc = (|x|/(q*q)-q)/(2*q+|x|/(q*q))
	muld	r2		# acc = q*(|x|/(q*q)-q)/(2*q+|x|/(q*q))
	addd	r2		# acc = q+q*(|x|/(q*q)-q)/(2*q+|x|/(q*q))
	std	r0		# r0:r1 = |result|
	orl2	r8,r0		# restore the sign bit
return: ret			# error less than 0.667ULPs?

	.data
	.align	2
B :	.long	721142941	#(86-0.03306235651)*(2^23)
	.align	2
C:	.long	0x400af8b0	#.float	0f0.5428571429	# 19/35
	.align	2
D:	.long	0xc0348ef1	#.float	0f-0.7053061224	# -864/1225
	.align	2
E:	.long	0x40b50750	#.float	0f1.414285714	# 99/70
	.align	2
F:	.long	0x40cdb6db	#.float	0f1.607142857	# 45/28
	.align	2
G:	.long	0x3fb6db6e	#.float	0f0.3571428571	# 5/14
E 1
