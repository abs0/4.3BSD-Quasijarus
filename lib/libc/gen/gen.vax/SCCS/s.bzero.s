h21695
s 00013/00008/00024
d D 5.5 88/06/27 17:25:05 bostic 8 7
c install approved copyright notice
e
s 00011/00005/00021
d D 5.4 88/05/25 17:13:44 bostic 7 6
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00024
d D 5.3 86/03/09 21:11:51 donn 6 5
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00025
d D 5.2 85/06/05 18:58:11 mckusick 5 4
c Fix copyright
e
s 00010/00001/00016
d D 5.1 85/05/30 15:13:33 dist 4 3
c Add copyright
e
s 00001/00001/00016
d D 4.3 84/11/01 23:51:33 sam 3 2
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00010/00001/00007
d D 4.2 83/01/14 14:59:37 mckusick 2 1
c fix for zero'ing more than 65K
e
s 00008/00000/00000
d D 4.1 82/12/15 15:33:35 sam 1 0
c date and time created 82/12/15 15:33:35 by sam
e
u
U
t
T
I 1
D 4
/* %W% %G% */
E 4
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

D 6
#ifndef lint
E 6
I 6
D 7
#ifdef LIBC_SCCS
E 6
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
	.asciz	"%W% (Berkeley) %G%"
E 5
D 6
#endif not lint
E 6
I 6
#endif LIBC_SCCS
E 7
I 7
D 8
#if defined(SYSLIBC_SCCS) && !defined(lint)
_sccsid:.asciz	"%W% (Berkeley) %G%"
#endif /* SYSLIBC_SCCS and not lint */
E 8
I 8
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 8
E 7
E 6

E 4
/* bzero(base, length) */

#include "DEFS.h"

D 3
ENTRY(bzero)
E 3
I 3
ENTRY(bzero, 0)
E 3
D 2
	movc5	$0, (r0), $0, 8(ap), *4(ap)
E 2
I 2
	movl	4(ap),r3
	jbr	2f
1:
	subl2	r0,8(ap)
	movc5	$0,(r3),$0,r0,(r3)
2:
	movzwl	$65535,r0
	cmpl	8(ap),r0
	jgtr	1b
	movc5	$0,(r3),$0,8(ap),(r3)
E 2
	ret
E 1
