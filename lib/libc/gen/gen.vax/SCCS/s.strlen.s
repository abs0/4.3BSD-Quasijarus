h32203
s 00013/00008/00023
d D 5.5 88/06/27 17:25:23 bostic 8 7
c install approved copyright notice
e
s 00011/00005/00020
d D 5.4 88/05/25 17:14:15 bostic 7 6
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00023
d D 5.3 86/03/09 21:14:55 donn 6 5
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00024
d D 5.2 85/06/05 19:01:03 mckusick 5 4
c Fix copyright
e
s 00009/00001/00016
d D 5.1 85/05/30 15:17:19 dist 4 3
c Add copyright
e
s 00005/00005/00012
d D 4.3 84/11/07 12:24:44 mckusick 3 2
c fix bug in finding length of >65535 byte strings
e
s 00002/00003/00015
d D 4.2 84/11/01 23:52:16 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00018/00000/00000
d D 4.1 84/11/01 23:19:42 sam 1 0
c date and time created 84/11/01 23:19:42 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
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

/*
 * Return the length of cp (not counting '\0').
 *
 * strlen(cp)
 *	char *cp;
 */
D 2
	.globl	_strlen
E 2
I 2
#include "DEFS.h"
E 2

D 2
_strlen:
	.word	0x0
E 2
I 2
ENTRY(strlen, 0)
E 2
D 3
	movl	4(ap),r2
0:
	locc	$0,$65535,(r2)	# look for '\0'
	beql	0b
	subl3	r2,r1,r0	# len = cp - base
E 3
I 3
	movl	4(ap),r1
1:
	locc	$0,$65535,(r1)	# look for '\0'
	beql	1b
	subl3	4(ap),r1,r0	# len = cp - base
E 3
	ret
E 1
