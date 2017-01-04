h20288
s 00016/00005/00014
d D 5.5 88/06/27 17:00:42 bostic 6 5
c install approved copyright notice
e
s 00001/00001/00018
d D 5.4 88/05/22 17:25:53 mckusick 5 4
c convert to use DEFS.h in ../../vax
e
s 00002/00002/00017
d D 5.3 86/03/09 21:26:11 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00018
d D 5.2 85/06/05 19:04:57 mckusick 3 2
c Fix copyright
e
s 00010/00001/00009
d D 5.1 85/05/30 15:22:01 dist 2 1
c Add copyright
e
s 00010/00000/00000
d D 4.1 82/12/15 15:33:42 sam 1 0
c date and time created 82/12/15 15:33:42 by sam
e
u
U
t
T
I 1
D 2
/* %W% %G% */
E 2
I 2
/*
 * Copyright (c) 1983 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
E 6
 */

D 4
#ifndef lint
E 4
I 4
D 6
#ifdef LIBC_SCCS
E 4
D 3
static char sccsid[] = "%W% (Berkeley) %G%";
E 3
I 3
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 3
D 4
#endif not lint
E 4
I 4
#endif LIBC_SCCS
E 6
I 6
#if defined(LIBC_SCCS) && !defined(lint)
	.asciz "%W% (Berkeley) %G%"
#endif /* LIBC_SCCS and not lint */
E 6
E 4

E 2
/* hostorder = ntohl(netorder) */

#include "DEFS.h"

D 5
ENTRY(ntohl)
E 5
I 5
ENTRY(ntohl, 0)
E 5
	rotl	$-8,4(ap),r0
	insv	r0,$16,$8,r0
	movb	7(ap),r0
	ret
E 1
