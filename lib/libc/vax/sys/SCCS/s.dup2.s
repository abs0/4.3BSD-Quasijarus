h60364
s 00011/00006/00014
d D 5.5 88/06/27 18:20:59 bostic 7 6
c install approved copyright notice
e
s 00010/00004/00010
d D 5.4 88/05/20 17:13:15 bostic 6 5
c add Berkeley specific header
e
s 00002/00002/00012
d D 5.3 86/03/09 21:39:57 donn 5 4
c added SYSLIBC_SCCS condition for sccs ids
e
s 00001/00001/00013
d D 5.2 85/06/05 19:12:03 mckusick 4 3
c Fix copyright
e
s 00009/00001/00005
d D 5.1 85/06/03 09:20:01 dist 3 2
c Add copyright
e
s 00001/00006/00005
d D 4.2 83/06/27 22:10:56 sam 2 1
c use proper interface
e
s 00011/00000/00000
d D 4.1 82/12/04 16:16:40 mckusick 1 0
c date and time created 82/12/04 16:16:40 by mckusick
e
u
U
t
T
I 1
D 3
/* %M% %I% %E% */
E 3
I 3
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
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

D 5
#ifndef lint
E 5
I 5
D 6
#ifdef SYSLIBC_SCCS
E 6
I 6
#if defined(SYSLIBC_SCCS) && !defined(lint)
E 6
E 5
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
I 4
D 7
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 7
I 7
	.asciz "%W% (Berkeley) %G%"
E 7
E 4
D 5
#endif not lint
E 5
I 5
D 6
#endif SYSLIBC_SCCS
E 6
I 6
#endif /* SYSLIBC_SCCS and not lint */
E 6
E 5
E 3

#include "SYS.h"

D 2
ENTRY(dup2)
	bisb2	$0100,4(ap)		/* XXX */
	chmk	$SYS_dup		/* XXX */
	jcs	err
E 2
I 2
SYSCALL(dup2)
E 2
	ret
D 2
err:
	jmp	cerror
E 2
E 1
