h16028
s 00013/00008/00019
d D 5.5 88/06/27 17:25:07 bostic 8 7
c install approved copyright notice
e
s 00011/00005/00016
d D 5.4 88/05/25 17:13:46 bostic 7 6
c written by Kirk McKusick and Sam Leffler; add Berkeley specific header
e
s 00002/00002/00019
d D 5.3 86/03/09 21:12:28 donn 6 4
c added LIBC_SCCS condition for sccs ids
e
s 00001/00001/00020
d R 5.3 86/02/26 18:08:20 mckusick 5 4
c ffs(0) == -1, not 0 (from kwlalonde%waterloo.csnet@csnet-relay.arpa)
e
s 00001/00001/00020
d D 5.2 85/06/05 18:58:26 mckusick 4 3
c Fix copyright
e
s 00010/00001/00011
d D 5.1 85/05/30 15:13:55 dist 3 2
c Add copyright
e
s 00001/00001/00011
d D 4.2 84/11/01 23:51:39 sam 2 1
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00012/00000/00000
d D 4.1 82/12/15 15:33:37 sam 1 0
c date and time created 82/12/15 15:33:37 by sam
e
u
U
t
T
I 1
D 3
/* %W% %G% */
E 3
I 3
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
D 4
static char sccsid[] = "%W% (Berkeley) %G%";
E 4
I 4
	.asciz	"%W% (Berkeley) %G%"
E 4
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

E 3
/* bit = ffs(value) */

#include "DEFS.h"

D 2
ENTRY(ffs)
E 2
I 2
ENTRY(ffs, 0)
E 2
	ffs	$0,$32,4(ap),r0
	bneq	1f
	mnegl	$1,r0
1:
	incl	r0
	ret
E 1
