h22334
s 00011/00005/00064
d D 5.7 88/05/25 17:13:57 bostic 15 14
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00000/00022/00069
d D 5.6 87/05/10 14:54:17 mckusick 14 13
c NOCOMPAT is history
e
s 00002/00002/00089
d D 5.5 86/03/09 21:14:00 donn 13 12
c added LIBC_SCCS condition for sccs ids
e
s 00001/00008/00090
d D 5.4 86/01/09 15:54:20 mckusick 12 11
c break longjmp botch out into a separate routine, so programs can exit gracefully
e
s 00001/00001/00097
d D 5.3 85/08/16 19:48:51 mckusick 11 10
c one too many levels of indirection (from ks@purdue)
e
s 00001/00001/00097
d D 5.2 85/06/05 19:00:01 mckusick 10 9
c Fix copyright
e
s 00009/00001/00089
d D 5.1 85/05/30 15:16:06 dist 9 8
c Add copyright
e
s 00010/00010/00080
d D 4.8 85/04/24 13:13:30 mckusick 8 7
c cannot count on saving r1 across subroutine calls
e
s 00046/00039/00044
d D 4.7 85/03/11 18:29:46 mckusick 7 6
c clean up onstack bug, use new system call when possible
e
s 00002/00002/00081
d D 4.6 84/11/01 23:52:01 sam 6 5
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00002/00000/00081
d D 4.5 83/08/14 14:26:51 sam 5 4
c revised chmk 139 interface
e
s 00001/00000/00080
d D 4.4 83/07/02 12:17:29 sam 4 3
c probably an assembler bug
e
s 00003/00002/00077
d D 4.3 83/06/30 16:31:52 sam 3 2
c 
e
s 00000/00001/00079
d D 4.2 83/06/28 00:34:23 root 2 1
c oops
e
s 00080/00000/00000
d D 4.1 83/06/27 15:42:06 root 1 0
c date and time created 83/06/27 15:42:06 by root
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
D 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
 */

D 13
#ifndef lint
E 13
I 13
D 15
#ifdef LIBC_SCCS
E 13
D 10
static char sccsid[] = "%W% (Berkeley) %G%";
E 10
I 10
	.asciz	"%W% (Berkeley) %G%"
E 10
D 13
#endif not lint
E 13
I 13
#endif LIBC_SCCS
E 15
I 15
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 15
E 13
E 9

/*
 * C library -- setjmp, longjmp
 *
 *	longjmp(a,v)
 * will generate a "return(v)" from
 * the last call to
 *	setjmp(a)
 * by restoring registers from the stack,
D 7
 * previous signal mask, and doing a return.
 *
 * BUG: always restores onsigstack state to 0
E 7
I 7
 * and a struct sigcontext, see <signal.h>
E 7
 */

#include "DEFS.h"

D 6
ENTRY(setjmp)
E 6
I 6
D 8
ENTRY(setjmp, 0)
I 7
	movl	4(ap),r1		# construct sigcontext
E 8
I 8
ENTRY(setjmp, R6)
	movl	4(ap),r6		# construct sigcontext
E 8
	subl2	$8,sp			# space for current struct sigstack
	pushl	sp			# get current values
	pushl	$0			# no new values
	calls	$3,_sigstack		# pop args plus signal stack value
D 8
	movl	*(sp)+,(r1)+		# save onsigstack status of caller
E 8
I 8
D 11
	movl	*(sp)+,(r6)+		# save onsigstack status of caller
E 11
I 11
	movl	(sp)+,(r6)+		# save onsigstack status of caller
E 11
E 8
E 7
E 6
	pushl	$0
	calls	$1,_sigblock		# get signal mask
D 7
	movl	r0,r1
	movl	4(ap),r0
	movl	12(fp),(r0)		# save frame pointer of caller
	movl	16(fp),4(r0)		# save pc of caller
	movl	r1,8(r0)		# save signal mask
	clrl	12(r0)			# XXX (should be onsigstack) XXX
E 7
I 7
D 8
	movl	r0,(r1)+		# save signal mask of caller
E 8
I 8
	movl	r0,(r6)+		# save signal mask of caller
E 8
	movl	(ap),r0
D 8
	moval	4(ap)[r0],(r1)+		# save sp of caller
	movl	12(fp),(r1)+		# save frame pointer of caller
	movl	8(fp),(r1)+		# save argument pointer of caller
	movl	16(fp),(r1)+		# save pc of caller
	movpsl	(r1)			# save psl of caller
	movw	4(fp),(r1)
E 8
I 8
	moval	4(ap)[r0],(r6)+		# save sp of caller
	movl	12(fp),(r6)+		# save frame pointer of caller
	movl	8(fp),(r6)+		# save argument pointer of caller
	movl	16(fp),(r6)+		# save pc of caller
	movpsl	(r6)			# save psl of caller
	movw	4(fp),(r6)
E 8
E 7
	clrl	r0
	ret

D 6
ENTRY(longjmp)
E 6
I 6
ENTRY(longjmp, 0)
E 6
D 2
	.word	0x0000
E 2
	movl	8(ap),r0		# return(v)
	movl	4(ap),r1		# fetch buffer
D 7
	tstl	(r1)
E 7
I 7
	tstl	12(r1)
E 7
	beql	botch
loop:
D 7
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
E 7
I 7
	cmpl	12(r1),fp		# are we there yet?
E 7
	beql	done
	blssu	botch
I 7
	moval	20(fp),r2
	blbc	6(fp),1f		# was r0 saved?
	movl	r0,(r2)+
1:
	bbc	$1,6(fp),2f		# was r1 saved?
	movl	r1,(r2)
2:
E 7
	movl	$loop,16(fp)
	ret				# pop another frame

done:
D 7
	cmpb	*16(fp),reiins		# returning to an "rei"?
	bneq	1f
	movab	3f,16(fp)		# do return w/ psl-pc pop
	brw	2f
1:
	movab	4f,16(fp)		# do standard return
2:
	ret				# unwind stack before signals enabled
E 7
I 7
D 14

#ifndef NOCOMPAT
/*
 * This code checks to see if it can use the new sigreturn.
 * If it finds that sigtramp is using the new system call,
 * it will also use it. Otherwise it uses the old system call
 * to preserve compatibility.
 */
#include <vax/machparam.h>
#define U (0x80000000-UPAGES*NBPG)
#define PCB_SIGC 0x6c
#define CHMKINS 7
	cmpl	3f,U+PCB_SIGC+CHMKINS	# check to see how sigtramp returns
	beql	4f			# sigtramp uses the new system call
	pushl	r1			# must use the old signal return
	chmk	$139			# restore previous context
	jmp	*20(r1)			# done, return
E 7
3:
D 7
	addl2	$8,sp			# compensate for PSL-PC push
E 7
I 7
	chmk	$103			# the new system call for sigreturn
E 7
4:
I 5
D 7
	pushl	sp			# old stack pointer
E 5
	pushl	8(r1)			# old signal mask
	pushl	12(r1)			# old onsigstack
I 5
	pushl	sp			# pointer to sigcontext
E 5
	chmk	$139			# restore previous signal context
	jmp	*4(r1)			# done, return....
E 7
I 7
#endif NOCOMPAT
E 7

E 14
I 7
	pushl	r1			# pointer to sigcontext
	calls	$1,_sigreturn		# restore previous context
					# we should never return
E 7
botch:
D 3
	pushl	$14
E 3
I 3
D 12
	pushl	$msgend-msg
E 3
	pushl	$msg
	pushl	$2
	calls	$3,_write
E 12
I 12
	calls	$0,_longjmperror
E 12
	halt
D 12

I 4
	.data
E 4
D 3
msg:	.byte	'l, 'o, 'n, 'g, 'j, 'm, 'p, ' , 'b, 'o, 't, 'c, 'h, 012
E 3
I 3
msg:	.ascii	"longjmp botch\n"
msgend:
E 12
E 3
D 7
reiins:	rei
E 7
E 1
