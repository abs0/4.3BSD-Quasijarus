h54779
s 00011/00006/00015
d D 5.5 88/06/27 18:20:35 bostic 7 6
c install approved copyright notice
e
s 00010/00004/00011
d D 5.4 88/05/20 17:12:49 bostic 6 5
c add Berkeley specific header
e
s 00002/00002/00013
d D 5.3 86/03/09 21:36:56 donn 5 4
c added SYSLIBC_SCCS condition for sccs ids
e
s 00001/00001/00014
d D 5.2 85/06/05 19:28:55 mckusick 4 2
c Add copyright
e
s 00001/00000/00015
d R 5.2 85/06/03 10:28:49 dist 3 2
c Add copyright
e
s 00009/00001/00006
d D 5.1 85/05/31 08:35:50 dist 2 1
c Add copyright
e
s 00007/00000/00000
d D 4.1 82/12/04 16:14:51 mckusick 1 0
c date and time created 82/12/04 16:14:51 by mckusick
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
E 2

#include "SYS.h"

	.align	1
PSEUDO(_exit,exit)
			# _exit(status)
E 1
