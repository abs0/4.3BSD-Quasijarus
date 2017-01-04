h10462
s 00010/00005/00040
d D 5.3 88/06/30 17:32:19 bostic 7 6
c install approved copyright notice
e
s 00016/00010/00029
d D 5.2 88/04/29 12:36:18 bostic 6 5
c added Berkeley specific header
e
s 00000/00000/00039
d D 5.1 87/11/30 18:49:57 bostic 5 4
c tahoe release
e
s 00007/00004/00032
d D 1.3 85/09/12 22:20:15 elefunt 4 2
c adding sccsid asciz string to each source file.
e
s 00006/00004/00032
d R 1.3 85/09/12 22:15:50 elefunt 3 2
c adding sccsid asciz string to each source file.
e
s 00001/00001/00035
d D 1.2 85/09/12 20:17:06 elefunt 2 1
c 4.3BSD version dated 09/12/85.
e
s 00036/00000/00000
d D 1.1 85/09/06 17:50:18 zliu 1 0
c date and time created 85/09/06 17:50:18 by zliu
e
u
U
t
T
I 1
D 6
/* 
E 6
I 6
/*
E 6
 * Copyright (c) 1985 Regents of the University of California.
D 6
 * 
 * Use and reproduction of this software are granted  in  accordance  with
 * the terms and conditions specified in  the  Berkeley  Software  License
 * Agreement (in particular, this entails acknowledgement of the programs'
 * source, and inclusion of this notice) with the additional understanding
 * that  all  recipients  should regard themselves as participants  in  an
 * ongoing  research  project and hence should  feel  obligated  to report
 * their  experiences (good or bad) with these elementary function  codes,
 * using "sendbug 4bsd-bugs@BERKELEY", to the authors.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 7
 *
 * All recipients should regard themselves as participants in an ongoing
 * research project and hence should feel obligated to report their
 * experiences (good or bad) with these elementary function codes, using
 * the sendbug(8) program, to the authors.
 *
 *	%W% (Berkeley) %G%
E 6
D 4
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
	.data
	.align	2
_sccsid:
.asciz	"%Z%%M%	1.1 (Berkeley) 8/21/85; %I% (ucb.elefunt) %G%"

/*
E 4
 * infnan(arg) int arg;
 * where arg :=    EDOM	if result is  NaN
 *	     :=  ERANGE	if result is +INF
 *	     := -ERANGE if result is -INF
 *
 * The Reserved Operand Fault is generated inside of this routine.
D 4
 *
E 4
 */	
	.globl	_infnan
	.set	EDOM,33
	.set	ERANGE,34
	.text
	.align 1
_infnan:
	.word	0x0
	cmpl	4(ap),$ERANGE
	bneq	1f
	movl	$ERANGE,_errno
	brb	2f
1:	movl	$EDOM,_errno
2:	emodd	$0,$0,$0x8000,r0,r0	# generates the reserved operand fault
	ret
E 1
