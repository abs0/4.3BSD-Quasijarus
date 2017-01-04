h33468
s 00011/00006/00014
d D 5.4 88/06/27 18:20:41 bostic 4 3
c install approved copyright notice
e
s 00010/00004/00010
d D 5.3 88/05/20 17:12:54 bostic 3 2
c add Berkeley specific header
e
s 00002/00002/00012
d D 5.2 86/03/09 21:37:45 donn 2 1
c added SYSLIBC_SCCS condition for sccs ids
e
s 00014/00000/00000
d D 5.1 85/06/09 11:30:17 mckusick 1 0
c date and time created 85/06/09 11:30:17 by mckusick
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

D 2
#ifndef lint
E 2
I 2
D 3
#ifdef SYSLIBC_SCCS
E 3
I 3
#if defined(SYSLIBC_SCCS) && !defined(lint)
E 3
E 2
D 4
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 4
I 4
	.asciz "%W% (Berkeley) %G%"
E 4
D 2
#endif not lint
E 2
I 2
D 3
#endif SYSLIBC_SCCS
E 3
I 3
#endif /* SYSLIBC_SCCS and not lint */
E 3
E 2

#include "SYS.h"

SYSCALL(adjtime)
	ret
E 1
