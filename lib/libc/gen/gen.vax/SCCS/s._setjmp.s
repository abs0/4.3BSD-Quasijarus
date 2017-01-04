h55065
s 00013/00008/00072
d D 5.7 88/06/27 17:24:58 bostic 10 9
c install approved copyright notice
e
s 00011/00006/00069
d D 5.6 88/05/25 17:13:38 bostic 9 8
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00073
d D 5.5 86/03/09 21:10:40 donn 8 7
c added LIBC_SCCS condition for sccs ids
e
s 00003/00000/00072
d D 5.4 86/01/20 16:15:25 karels 7 6
c let's not get carried away with deletions: put back reiins
e
s 00001/00009/00071
d D 5.3 86/01/09 15:54:15 mckusick 6 5
c break longjmp botch out into a separate routine, so programs can exit gracefully
e
s 00001/00001/00079
d D 5.2 85/06/05 18:55:29 mckusick 5 4
c Fix copyright
e
s 00010/00001/00070
d D 5.1 85/05/30 15:11:23 dist 4 3
c Add copyright
e
s 00002/00002/00069
d D 4.3 84/11/01 23:51:06 sam 3 2
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00001/00000/00070
d D 4.2 83/07/02 12:17:31 sam 2 1
c probably an assembler bug
e
s 00070/00000/00000
d D 4.1 83/06/30 16:24:10 sam 1 0
c date and time created 83/06/30 16:24:10 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
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
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
	.asciz	"%W% (Berkeley) %G%"
E 5
D 8
#endif not lint
E 8
I 8
#endif LIBC_SCCS
E 8

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
E 4

/*
 * C library -- _setjmp, _longjmp
 *
 *	_longjmp(a,v)
 * will generate a "return(v)" from
 * the last call to
 *	_setjmp(a)
 * by restoring registers from the stack,
 * The previous signal state is NOT restored.
 */

#include "DEFS.h"

D 3
ENTRY(_setjmp)
E 3
I 3
ENTRY(_setjmp, 0)
E 3
	movl	4(ap),r0
	movl	12(fp),(r0)		# save frame pointer of caller
	movl	16(fp),4(r0)		# save pc of caller
	clrl	r0
	ret

D 3
ENTRY(_longjmp)
E 3
I 3
ENTRY(_longjmp, 0)
E 3
	movl	8(ap),r0		# return(v)
	movl	4(ap),r1		# fetch buffer
	tstl	(r1)
	beql	botch
loop:
	bitw	$1,6(fp)		# r0 saved?
	beql	1f
	movl	r0,20(fp)
	bitw	$2,6(fp)		# was r1 saved?
	beql	2f
	movl	r1,24(fp)
	brb	2f
1:
	bitw	$2,6(fp)		# was r1 saved?
	beql	2f
	movl	r1,20(fp)
2:
	cmpl	(r1),12(fp)
	beql	done
	blssu	botch
	movl	$loop,16(fp)
	ret				# pop another frame

done:
	cmpb	*16(fp),reiins		# returning to an "rei"?
	bneq	1f
	movab	3f,16(fp)		# do return w/ psl-pc pop
	brw	2f
1:
	movab	4f,16(fp)		# do standard return
2:
	ret				# unwind stack before signals enabled
3:
	addl2	$8,sp			# compensate for PSL-PC push
4:
	jmp	*4(r1)			# done, return....

botch:
D 6
	pushl	$msgend-msg
	pushl	$msg
	pushl	$2
	calls	$3,_write
E 6
I 6
	calls	$0,_longjmperror
E 6
	halt
I 7

	.data
reiins: rei
E 7
D 6

I 2
	.data
E 2
msg:	.ascii	"_longjmp botch\n"
msgend:
reiins:	rei
E 6
E 1
