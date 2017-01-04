h09136
s 00010/00005/00102
d D 5.3 88/06/30 17:32:23 bostic 7 6
c install approved copyright notice
e
s 00017/00012/00090
d D 5.2 88/04/29 12:36:21 bostic 6 5
c added Berkeley specific header
e
s 00000/00000/00102
d D 5.1 87/11/30 18:49:59 bostic 5 4
c tahoe release
e
s 00007/00004/00095
d D 1.3 85/09/12 22:20:24 elefunt 4 2
c adding sccsid asciz string to each source file.
e
s 00006/00004/00095
d R 1.3 85/09/12 22:15:57 elefunt 3 2
c adding sccsid asciz string to each source file.
e
s 00001/00001/00098
d D 1.2 85/09/12 20:17:15 elefunt 2 1
c 4.3BSD version dated 09/12/85.
e
s 00099/00000/00000
d D 1.1 85/09/06 17:50:22 zliu 1 0
c date and time created 85/09/06 17:50:22 by zliu
e
u
U
t
T
I 1
D 6
/* 
 * Copyright (c) 1985 Regents of the University of California.
 * 
 * Use and reproduction of this software are granted  in  accordance  with
 * the terms and conditions specified in  the  Berkeley  Software  License
 * Agreement (in particular, this entails acknowledgement of the programs'
 * source, and inclusion of this notice) with the additional understanding
 * that  all  recipients  should regard themselves as participants  in  an
 * ongoing  research  project and hence should  feel  obligated  to report
 * their  experiences (good or bad) with these elementary function  codes,
 * using "sendbug 4bsd-bugs@BERKELEY", to the authors.
D 4
 *
 *
D 2
 * %W% (ELEFUNT) %G%
E 2
I 2
 * %Z%%M%	1.1 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%
E 2
 *
E 4
I 4
 */
E 6
I 6
# Copyright (c) 1985 Regents of the University of California.
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
#
E 6
	.data
	.align	2
_sccsid:
.asciz	"%Z%%M%	1.1 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%"

/*
E 4
 * double sqrt(arg)   revised August 15,1982
 * double arg;
 * if(arg<0.0) { _errno = EDOM; return(<a reserved operand>); }
 * if arg is a reserved operand it is returned as it is
 * W. Kahan's magic square root
 * coded by Heidi Stettner and revised by Emile LeBlanc 8/18/82
 *
 * entry points:_d_sqrt		address of double arg is on the stack
 *		_sqrt		double arg is on the stack
 */
	.text
	.align	1
	.globl	_sqrt
	.globl	_d_sqrt
	.globl	libm$dsqrt_r5
	.set	EDOM,33

_d_sqrt:
	.word	0x003c          # save r5,r4,r3,r2
	movq	*4(ap),r0
	jmp  	dsqrt2
_sqrt:
	.word	0x003c          # save r5,r4,r3,r2
	movq    4(ap),r0
dsqrt2:	bicw3	$0x807f,r0,r2	# check exponent of input
	jeql	noexp		# biased exponent is zero -> 0.0 or reserved
	bsbb	libm$dsqrt_r5
noexp:	ret

/* **************************** internal procedure */

libm$dsqrt_r5:			# ENTRY POINT FOR cdabs and cdsqrt
				# returns double square root scaled by
				# 2^r6

	movd	r0,r4
	jleq	nonpos		# argument is not positive
	movzwl	r4,r2
	ashl	$-1,r2,r0
	addw2	$0x203c,r0	# r0 has magic initial approximation
/*
 * Do two steps of Heron's rule
 * ((arg/guess) + guess) / 2 = better guess
 */
	divf3	r0,r4,r2
	addf2	r2,r0
	subw2	$0x80,r0	# divide by two

	divf3	r0,r4,r2
	addf2	r2,r0
	subw2	$0x80,r0	# divide by two

/* Scale argument and approximation to prevent over/underflow */

	bicw3	$0x807f,r4,r1
	subw2	$0x4080,r1		# r1 contains scaling factor
	subw2	r1,r4
	movl	r0,r2
	subw2	r1,r2

/* Cubic step
 *
 * b = a + 2*a*(n-a*a)/(n+3*a*a) where b is better approximation,
 * a is approximation, and n is the original argument.
 * (let s be scale factor in the following comments)
 */
	clrl	r1
	clrl	r3
	muld2	r0,r2			# r2:r3 = a*a/s
	subd2	r2,r4			# r4:r5 = n/s - a*a/s
	addw2	$0x100,r2		# r2:r3 = 4*a*a/s
	addd2	r4,r2			# r2:r3 = n/s + 3*a*a/s
	muld2	r0,r4			# r4:r5 = a*n/s - a*a*a/s
	divd2	r2,r4			# r4:r5 = a*(n-a*a)/(n+3*a*a)
	addw2	$0x80,r4		# r4:r5 = 2*a*(n-a*a)/(n+3*a*a)
	addd2	r4,r0			# r0:r1 = a + 2*a*(n-a*a)/(n+3*a*a)
	rsb				# DONE!
nonpos:
	jneq	negarg
	ret			# argument and root are zero
negarg:
	pushl	$EDOM
	calls	$1,_infnan	# generate the reserved op fault
	ret
E 1
