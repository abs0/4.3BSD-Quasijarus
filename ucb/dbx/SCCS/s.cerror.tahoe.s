h57631
s 00017/00017/00013
d D 5.2 88/01/12 00:04:43 donn 3 2
c merge in latest Linton version
e
s 00000/00000/00030
d D 5.1 86/02/22 22:24:32 sam 2 1
c update sccsid
e
s 00030/00000/00000
d D 1.1 86/02/22 22:23:35 sam 1 0
c date and time created 86/02/22 22:23:35 by sam
e
u
U
t
T
I 1
D 3
#
# Copyright (c) 1985 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
#
# modified version of cerror
#
# The idea is that every time an error occurs in a system call
# I want a special function "syserr" called.  This function will
# either print a message and exit or do nothing depending on
# defaults and use of "onsyserr".
#
E 3
I 3
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 *
 *
 * modified version of cerror
 *
 * The idea is that every time an error occurs in a system call
 * I want a special function "syserr" called.  This function will
 * either print a message and exit or do nothing depending on
 * defaults and use of "onsyserr".
 */
E 3

.globl	cerror
.comm	_errno,4

cerror:
	movl	r0,_errno
D 3
	callf	$0,_syserr	# new code
E 3
I 3
	callf	$0,_syserr	/* new code */
E 3
	mnegl	$1,r0
	ret

D 3
.globl	__mycerror		# clumsy way to get this loaded
E 3
I 3
.globl	__mycerror		/* clumsy way to get this loaded */
E 3

__mycerror:
	.word	0
	ret
E 1
