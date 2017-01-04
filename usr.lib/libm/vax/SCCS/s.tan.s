h04443
s 00010/00005/00076
d D 5.3 88/06/30 17:32:28 bostic 7 6
c install approved copyright notice
e
s 00015/00010/00066
d D 5.2 88/04/29 12:36:25 bostic 6 5
c added Berkeley specific header
e
s 00000/00000/00076
d D 5.1 87/11/30 18:50:01 bostic 5 4
c tahoe release
e
s 00004/00002/00072
d D 1.3 85/09/12 22:20:34 elefunt 4 2
c adding sccsid asciz string to each source file.
e
s 00003/00002/00072
d R 1.3 85/09/12 22:16:06 elefunt 3 2
c adding sccsid asciz string to each source file.
e
s 00001/00001/00073
d D 1.2 85/09/12 20:17:25 elefunt 2 1
c 4.3BSD version dated 09/12/85.
e
s 00074/00000/00000
d D 1.1 85/09/06 17:50:25 zliu 1 0
c date and time created 85/09/06 17:50:25 by zliu
e
u
U
t
T
I 1
D 6
# 
E 6
# Copyright (c) 1985 Regents of the University of California.
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
D 4

D 2
# %W% (ELEFUNT) %G%
E 2
I 2
# %Z%%M%	1.1 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%
E 4
I 4
	.data
	.align	2
_sccsid:
.asciz	"%Z%%M%	1.1 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%"
E 4
E 2

#  This is the implementation of Peter Tang's double precision  
#  tangent for the VAX using Bob Corbett's argument reduction.
#  
#  Notes:
#       under 1,024,000 random arguments testing on [0,2*pi] 
#       tan() observed maximum error = 2.15 ulps
#
# double tan(arg)
# double arg;
# method: true range reduction to [-pi/4,pi/4], P. Tang  &  B. Corbett
# S. McDonald, April 4,  1985
#
	.globl	_tan
	.text
	.align	1

_tan:	.word	0xffc		# save r2-r11
	movq	4(ap),r0
	bicw3	$0x807f,r0,r2
	beql	1f		# if x is zero or reserved operand then return x
#
# Save the PSL's IV & FU bits on the stack.
#
	movpsl	r2
	bicw3	$0xff9f,r2,-(sp)
#
#  Clear the IV & FU bits.
#
	bicpsw	$0x0060
	jsb	libm$argred
#
#  At this point,
#	   r0  contains the quadrant number, 0, 1, 2, or 3;
#	r2/r1  contains the reduced argument as a D-format number;
#  	   r3  contains a F-format extension to the reduced argument;
#
#  Save  r3/r0  so that we can call cosine after calling sine.
#
	movq	r2,-(sp)
	movq	r0,-(sp)
#
#  Call sine.  r4 = 0  implies sine.
#
	movl	$0,r4
	jsb	libm$sincos
#
#  Save  sin(x)  in  r11/r10 .
#
	movd	r0,r10
#
#  Call cosine.  r4 = 1  implies cosine.
#
	movq	(sp)+,r0
	movq	(sp)+,r2
	movl	$1,r4
	jsb	libm$sincos
	divd3	r0,r10,r0
	bispsw	(sp)+
1:	ret
E 1
