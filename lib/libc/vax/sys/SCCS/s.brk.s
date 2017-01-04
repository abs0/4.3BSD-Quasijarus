h20050
s 00011/00006/00031
d D 5.5 88/06/27 18:20:44 bostic 9 8
c install approved copyright notice
e
s 00010/00004/00027
d D 5.4 88/05/20 17:12:57 bostic 8 7
c add Berkeley specific header
e
s 00002/00002/00029
d D 5.3 86/03/09 21:38:11 donn 7 6
c added SYSLIBC_SCCS condition for sccs ids
e
s 00001/00001/00030
d D 5.2 85/06/05 19:10:11 mckusick 6 5
c Fix copyright
e
s 00009/00001/00022
d D 5.1 85/06/03 09:13:04 dist 5 4
c Add copyright
e
s 00002/00000/00021
d D 4.3 83/10/06 00:52:26 layer 4 2
c put back entry point __brk -- layer
e
s 00003/00000/00021
d R 4.3 83/08/22 19:08:50 layer 3 2
c another entry to accomodate ld -H option.	-layer
e
s 00010/00001/00011
d D 4.2 83/07/26 00:24:25 mckusick 2 1
c do not allow brk() below _end
e
s 00012/00000/00000
d D 4.1 82/12/04 16:13:18 mckusick 1 0
c date and time created 82/12/04 16:13:18 by mckusick
e
u
U
t
T
I 1
D 5
/* %M% %I% %E% */
E 5
I 5
/*
 * Copyright (c) 1983 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

D 7
#ifndef lint
E 7
I 7
D 8
#ifdef SYSLIBC_SCCS
E 8
I 8
#if defined(SYSLIBC_SCCS) && !defined(lint)
E 8
E 7
D 6
static char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
D 9
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 9
I 9
	.asciz "%W% (Berkeley) %G%"
E 9
E 6
D 7
#endif not lint
E 7
I 7
D 8
#endif SYSLIBC_SCCS
E 8
I 8
#endif /* SYSLIBC_SCCS and not lint */
E 8
E 7
E 5

#include "SYS.h"

#define	SYS_brk		17

	.globl	curbrk
I 2
	.globl	minbrk
I 4
ENTRY(_brk)
	jbr	ok
E 4
E 2

D 2
SYSCALL(brk)
E 2
I 2
ENTRY(brk)
	cmpl	4(ap),minbrk
	bgeq	ok
	movl	minbrk,4(ap)
ok:
	chmk	$SYS_brk
	jcs	err
E 2
	movl	4(ap),curbrk
	clrl	r0
	ret
I 2
err:
	jmp	cerror
E 2
E 1
