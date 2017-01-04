h58208
s 00011/00006/00016
d D 5.5 88/06/27 18:20:31 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00012
d D 5.4 88/05/20 17:12:45 bostic 7 6
c add Berkeley specific header
e
s 00002/00002/00014
d D 5.3 86/03/09 21:36:34 donn 6 5
c added SYSLIBC_SCCS condition for sccs ids
e
s 00001/00001/00015
d D 5.2 85/06/05 19:09:21 mckusick 5 2
c Fix copyright
e
s 00010/00000/00016
d R 5.3 85/06/03 10:25:31 dist 4 3
c Add copyright
e
s 00001/00001/00015
d R 5.2 85/05/31 08:32:14 dist 3 2
c Add copyright
e
s 00009/00001/00007
d D 5.1 85/05/31 08:19:42 dist 2 1
c Add copyright
e
s 00008/00000/00000
d D 4.1 82/12/04 17:03:42 sam 1 0
c date and time created 82/12/04 17:03:42 by sam
e
u
U
t
T
I 1
D 2
/* %M% %I% %E% */
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
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
#ifdef SYSLIBC_SCCS
E 7
I 7
#if defined(SYSLIBC_SCCS) && !defined(lint)
E 7
E 6
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
D 8
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 8
I 8
	.asciz "%W% (Berkeley) %G%"
E 8
E 5
D 6
#endif not lint
E 6
I 6
D 7
#endif SYSLIBC_SCCS
E 7
I 7
#endif /* SYSLIBC_SCCS and not lint */
E 7
E 6
E 2

#include "SYS.h"

#define	SYS_vadvise	72

SYSCALL(vadvise)
	ret
E 1
