h58811
s 00005/00000/00021
d D 5.2 85/07/12 19:33:53 mckusick 2 1
c add load flag to tell that -lg was used
e
s 00021/00000/00000
d D 5.1 85/07/12 19:33:02 mckusick 1 0
c date and time created 85/07/12 19:33:02 by mckusick
e
u
U
t
T
I 1
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#ifndef lint
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif not lint

	.data
	.comm	__dbargs,512
	.text
	.align	1
	.globl	__dbsubc
__dbsubc:
	callg	__dbargs+4,*__dbargs
	.globl	__dbsubn
__dbsubn:
	halt

	.data
I 2
#  __lg_flag is used by f77_abort to decide whether or not to dump memory
	.globl	__lg_flag
__lg_flag:
	.long	1
	.text
E 2
E 1
