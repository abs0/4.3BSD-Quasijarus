h28846
s 00013/00008/00019
d D 1.3 88/06/27 17:46:49 bostic 3 2
c install approved copyright notice
e
s 00018/00003/00009
d D 1.2 88/05/23 21:33:16 bostic 2 1
c add Berkeley/CCI specific header; fix sccsid
e
s 00012/00000/00000
d D 1.1 86/08/01 08:49:31 sam 1 0
c date and time created 86/08/01 08:49:31 by sam
e
u
U
t
T
I 1
D 2
#ifdef LIBC_SCCS
	.asciz	"%W% (Berkeley/CCI) %G%"
#endif LIBC_SCCS
E 2
I 2
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
I 3
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
 *
E 3
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
D 3
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
 */

#if defined(LIBC_SCCS) && !defined(lint)
D 3
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 3
I 3
	.asciz "%W% (Berkeley) %G%"
E 3
#endif /* LIBC_SCCS and not lint */
E 2

/* C library -- abort */

#include "DEFS.h"

ENTRY(abort, 0)
	rei
	clrl	r0
	ret
E 1
