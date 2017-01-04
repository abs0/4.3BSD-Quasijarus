h23973
s 00002/00002/00044
d D 1.2 86/08/01 09:22:14 sam 2 1
c use common ENTRY definition
e
s 00046/00000/00000
d D 1.1 86/07/02 16:30:23 sam 1 0
c date and time created 86/07/02 16:30:23 by sam
e
u
U
t
T
I 1
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
#ifdef LIBC_SCCS
_sccsid:.asciz	"%W% (Berkeley/CCI) %G%"
#endif LIBC_SCCS

/*
 * C library -- reset, setexit
 *
 *	reset(x)
 * will generate a "return" from
 * the last call to
 *	setexit()
 * by restoring r2 - r12, fp
 * and doing a return.
 * The returned value is x; on the original
 * call the returned value is 0.
 *
 * useful for going back to the main loop
 * after a horrible error in a lowlevel
 * routine.
 */
#include "DEFS.h"

D 2
ENTRY(setexit)
E 2
I 2
ENTRY(setexit, 0)
E 2
	movab	setsav,r0
	storer	$0x1ffc, (r0)
	movl	(fp),44(r0)		# fp
	moval	4(fp),48(r0)		# sp
	movl	-8(fp),52(r0)		# pc
	clrl	r0
	ret

D 2
ENTRY(reset)
E 2
I 2
ENTRY(reset, 0)
E 2
	movl	4(fp),r0	# returned value
	movab	setsav,r1
	loadr	$0x1ffc,(r1)
	movl	44(r1),fp
	movl	48(r1),sp
	jmp 	*52(r1)

	.data
setsav:	.space	14*4
E 1
