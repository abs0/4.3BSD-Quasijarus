h60603
s 00029/00000/00000
d D 5.1 87/04/07 00:08:59 mckusick 1 0
c MC68000 Version
e
u
U
t
T
I 1
#
# Copyright (c) 1982 Regents of the University of California.
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
	movl	d0,_errno
	jsr	_syserr		| new code
	moveq	#-1,d0
	rts

.globl	__mycerror		| clumsy way to get this loaded

__mycerror:
	.word	0
	rts
E 1
