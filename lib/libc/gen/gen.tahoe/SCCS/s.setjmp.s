h53037
s 00013/00008/00075
d D 1.4 88/06/27 17:47:07 bostic 4 3
c install approved copyright notice
e
s 00018/00003/00065
d D 1.3 88/05/23 21:33:39 bostic 3 2
c add Berkeley/CCI specific header; fix sccsid
e
s 00017/00017/00051
d D 1.2 86/08/22 15:54:35 sam 2 1
c fix to use sigreturn protocol
e
s 00068/00000/00000
d D 1.1 86/08/01 08:49:37 sam 1 0
c date and time created 86/08/01 08:49:37 by sam
e
u
U
t
T
I 1
D 3
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley/CCI) %G%"
#endif LIBC_SCCS
E 3
I 3
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
I 4
 * Redistribution and use in source and binary forms are permitted
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
 *
E 4
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
D 4
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
 */

#if defined(LIBC_SCCS) && !defined(lint)
D 4
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 4
I 4
	.asciz "%W% (Berkeley) %G%"
E 4
#endif /* LIBC_SCCS and not lint */
E 3

/*
 * C library -- setjmp, longjmp
 *
 *	longjmp(a,v)
 * will generate a "return(v)" from
 * the last call to
 *	setjmp(a)
 * by restoring registers from the stack,
 * previous signal mask, and doing a return.
D 2
 *
 * BUG: always restores onsigstack state to 0
E 2
 */

#include "DEFS.h"

D 2
ENTRY(setjmp, 0)
E 2
I 2
ENTRY(setjmp, R6)
	movl	4(fp),r6		# construct sigcontext
	movab	-8(sp),sp		# space for current struct sigstack
	pushal	(sp)			# get current values
	pushl	$0			# no new values
	callf	$16,_sigstack		# pop args plus signal stack value
	movl	(sp)+,(r6)		# save onsigstack status of caller
E 2
	pushl	$0
	callf	$8,_sigblock		# get signal mask
D 2
	movl	r0,r1
	movl	4(fp),r0
	movl	(fp),(r0)		# save frame pointer of caller
	movl	-8(fp),4(r0)		# save pc of caller
	movl	r1,8(r0)		# save signal mask
	clrl	12(r0)			# XXX (should be onsigstack) XXX
E 2
I 2
	movl	r0,4(r6)		# save signal mask of caller
	addl3	$8,fp,8(r6)		# save stack pointer of caller
	movl	(fp),12(r6)		# save frame pointer of caller
	movl	-8(fp),20(r6)		# save pc of caller
	movpsl	24(r6)			# save psl of caller
E 2
	clrl	r0
	ret

ENTRY(longjmp, 0)
	movl	8(fp),r0		# return(v)
	movl	4(fp),r1		# fetch buffer
D 2
	tstl	(r1)
E 2
I 2
	tstl	12(r1)
E 2
	beql	botch
loop:
D 2
	cmpl	(r1),(fp)
E 2
I 2
	cmpl	12(r1),(fp)
E 2
	beql	done
	blssu	botch
	movl	$loop,-8(fp)
	ret				# pop another frame

done:
	cmpb	*-8(fp),reiins		# returning to an "rei"?
	bneq	1f
	movab	3f,-8(fp)		# do return w/ psl-pc pop
	brw	2f
1:
	movab	4f,-8(fp)		# do standard return
2:
	ret				# unwind stack before signals enabled
3:
	addl2	$8,sp			# compensate for PSL-PC push
4:
D 2
	pushal	(sp)			# old stack pointer
	pushl	8(r1)			# old signal mask
	pushl	12(r1)			# old onsigstack
	pushal	(sp)			# pointer to sigcontext
	kcall	$139			# restore previous signal context
	jmp	*4(r1)			# done, return....
E 2
I 2
	pushl	r1			# pointer to sigcontext
	callf	$4,_sigreturn		# restore previous context
					# we should never return
E 2

botch:
	callf	$4,_longjmperror
	halt

	.data
reiins:	rei
E 1
