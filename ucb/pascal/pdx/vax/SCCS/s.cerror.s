h22415
s 00005/00002/00024
d D 5.1 85/06/07 19:41:48 mckusick 4 3
c Add copyright
e
s 00001/00001/00025
d D 1.3 82/09/02 20:36:09 linton 3 2
c added id keywords
e
s 00003/00000/00023
d D 1.2 82/09/02 20:34:44 linton 2 1
c p cerror.s
e
s 00023/00000/00000
d D 1.1 82/01/18 23:12:01 linton 1 0
c date and time created 82/01/18 23:12:01 by linton
e
u
U
t
T
I 2
D 3
# Copy
E 3
I 3
D 4
# Copyright (c) 1982 Regents of the University of California
E 4
E 3
#
D 4
# static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
# Copyright (c) 1982 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#	%W% (Berkeley) %G%
E 4
E 2
I 1
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
	calls	$0,_syserr	# new code
	mnegl	$1,r0
	ret

.globl	__mycerror		# clumsy way to get this loaded

__mycerror:
	.word	0
	ret
E 1
