h32361
s 00002/00002/00048
d D 5.4 86/03/09 21:00:06 donn 7 6
c added LIBC_SCCS condition for sccs ids
e
s 00002/00000/00048
d D 5.3 85/06/21 16:43:13 mckusick 6 4
c don't forget lint
e
s 00001/00001/00047
d R 5.3 85/06/05 18:58:13 mckusick 5 4
c Fix copyright
e
s 00001/00004/00047
d D 5.2 85/05/30 22:12:34 sam 4 3
c correct sccsid
e
s 00010/00001/00041
d D 5.1 85/05/30 14:52:23 dist 3 2
c Add copyright
e
s 00020/00024/00022
d D 4.2 83/07/05 19:54:43 sam 2 1
c C-ized
e
s 00046/00000/00000
d D 4.1 80/12/21 16:58:23 wnj 1 0
c date and time created 80/12/21 16:58:23 by wnj
e
u
U
t
T
I 1
D 2
# %W% (Berkeley) %G%
# C library -- reset, setexit
E 2
I 2
/*
D 3
 * %W% (Berkeley) %G%
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
I 6
D 7
#ifndef lint
E 7
I 7
#ifdef LIBC_SCCS
E 7
E 6
D 4

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4
I 4
_sccsid:.asciz	"%W% (Berkeley) %G%"
I 6
D 7
#endif not lint
E 7
I 7
#endif LIBC_SCCS
E 7
E 6
E 4

/*
E 3
 * C library -- reset, setexit
 *
 *	reset(x)
 * will generate a "return" from
 * the last call to
 *	setexit()
 * by restoring r6 - r12, ap, fp
 * and doing a return.
 * The returned value is x; on the original
 * call the returned value is 0.
 *
 * useful for going back to the main loop
 * after a horrible error in a lowlevel
 * routine.
 */
#include "DEFS.h"
E 2

D 2
#	reset(x)
# will generate a "return" from
# the last call to
#	setexit()
# by restoring r6 - r12, ap, fp
# and doing a return.
# The returned value is x; on the original
# call the returned value is 0.
#
# useful for going back to the main loop
# after a horrible error in a lowlevel
# routine.

.globl	_setexit
.globl	_reset

	.align	1
_setexit:
	.word	0x0000
E 2
I 2
ENTRY(setexit)
E 2
	movab	setsav,r0
	movq	r6,(r0)+
	movq	r8,(r0)+
	movq	r10,(r0)+
	movq	8(fp),(r0)+		# ap, fp
	movab	4(ap),(r0)+		# sp
	movl	16(fp),(r0)		# pc
	clrl	r0
	ret

D 2
	.align	1
_reset:
	.word	0x0000
E 2
I 2
ENTRY(reset)
E 2
	movl	4(ap),r0	# returned value
	movab	setsav,r1
	movq	(r1)+,r6
	movq	(r1)+,r8
	movq	(r1)+,r10
	movq	(r1)+,r12
	movl	(r1)+,sp
	jmp 	*(r1)

	.data
setsav:	.space	10*4
E 1
