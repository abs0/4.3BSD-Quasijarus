h44176
s 00018/00011/00015
d D 5.3 86/01/26 12:33:00 sam 4 2
c improve portability
e
s 00018/00013/00013
d R 5.3 86/01/26 12:23:13 sam 3 2
c improve portability
e
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
D 4
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 4
#ifndef lint
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif not lint

I 4
#if defined(vax)
#define	CALL(n, f)	callg	n,*f
#endif
#if defined(tahoe)
#define	CALL(n, f)	calls	n,*f
#endif

E 4
	.data
	.comm	__dbargs,512
	.text
	.align	1
D 4
	.globl	__dbsubc
__dbsubc:
	callg	__dbargs+4,*__dbargs
	.globl	__dbsubn
__dbsubn:
E 4
I 4
	.globl	__dsubc
__dsubc:
	CALL(__dbargs+4,__dbargs)
	.globl	__dsubn
__dsubn:
E 4
	halt

	.data
I 2
D 4
#  __lg_flag is used by f77_abort to decide whether or not to dump memory
E 4
I 4
/*  __lg_flag is used by f77_abort to decide whether or not to dump memory */
E 4
	.globl	__lg_flag
__lg_flag:
	.long	1
	.text
E 2
E 1
