h16647
s 00013/00008/00049
d D 5.5 88/06/27 17:25:04 bostic 10 9
c install approved copyright notice
e
s 00011/00005/00046
d D 5.4 88/05/25 17:13:43 bostic 9 8
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00049
d D 5.3 86/03/09 21:11:40 donn 8 7
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00050
d D 5.2 85/06/05 18:57:56 mckusick 7 6
c Fix copyright
e
s 00010/00001/00041
d D 5.1 85/05/30 15:13:17 dist 6 5
c Add copyright
e
s 00001/00006/00041
d D 4.5 84/11/01 23:51:30 sam 5 4
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00034/00005/00013
d D 4.4 83/09/25 20:18:31 mckusick 4 3
c fix to insure that overlapping strings are properly handled
e
s 00001/00001/00017
d D 4.3 83/09/12 11:17:08 karels 3 2
c correct comment on usage
e
s 00011/00001/00007
d D 4.2 83/01/14 14:55:29 mckusick 2 1
c fix for transfers greater than 65K
e
s 00008/00000/00000
d D 4.1 82/12/15 15:33:34 sam 1 0
c date and time created 82/12/15 15:33:34 by sam
e
u
U
t
T
I 1
D 6
/* %W% %G% */
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */

D 8
#ifndef lint
E 8
I 8
D 9
#ifdef LIBC_SCCS
E 8
D 7
static char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
	.asciz	"%W% (Berkeley) %G%"
E 7
D 8
#endif not lint
E 8
I 8
#endif LIBC_SCCS
E 9
I 9
D 10
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 10
I 10
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 10
E 9
E 8

E 6
D 3
/* bcopy(to, from, size) */
E 3
I 3
/* bcopy(from, to, size) */
E 3

#include "DEFS.h"

D 4
ENTRY(bcopy)
E 4
I 4
D 5
	.globl	_bcopy
_bcopy:
	.word	0x0040
#ifdef PROF
	.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
#endif PROF
E 5
I 5
ENTRY(bcopy, R6)
E 5
E 4
D 2
	movc3	12(ap), *4(ap), *8(ap)
E 2
I 2
	movl	4(ap),r1
	movl	8(ap),r3
D 4
	jbr	2f
E 4
I 4
	movl	12(ap),r6
	cmpl	r1,r3
	bgtr	2f		# normal forward case
	blss	3f		# overlapping, must do backwards
	ret			# equal, nothing to do
E 4
1:
D 4
	subl2	r0,12(ap)
E 4
I 4
	subl2	r0,r6
E 4
	movc3	r0,(r1),(r3)
2:
	movzwl	$65535,r0
D 4
	cmpl	12(ap),r0
E 4
I 4
	cmpl	r6,r0
E 4
	jgtr	1b
D 4
	movc3	12(ap),(r1),(r3)
E 4
I 4
	movc3	r6,(r1),(r3)
	ret
3:
	addl2	r6,r1
	addl2	r6,r3
	movzwl	$65535,r0
	jbr	5f
4:
	subl2	r0,r6
	subl2	r0,r1
	subl2	r0,r3
	movc3	r0,(r1),(r3)
	movzwl	$65535,r0
	subl2	r0,r1
	subl2	r0,r3
5:
	cmpl	r6,r0
	jgtr	4b
	subl2	r6,r1
	subl2	r6,r3
	movc3	r6,(r1),(r3)
E 4
E 2
	ret
E 1
