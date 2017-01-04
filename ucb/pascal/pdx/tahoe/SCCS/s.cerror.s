h53867
s 00023/00000/00000
d D 5.1 87/04/07 00:07:19 mckusick 1 0
c CCI Version
e
u
U
t
T
I 1
#
# Copyright (c) 1987 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
#
# modified version of cerror
#
# The idea is that every time an error occurs in a system call
# I want a special function "syserr" called.  This function will
# either print a message and exit or do nothing depending on
# defaults and use of "onsyserr".
#

.globl	cerror
.comm	_errno,4

cerror:
	movl	r0,_errno
	callf	$4,_syserr	# new code
	mnegl	$1,r0
	ret
E 1
