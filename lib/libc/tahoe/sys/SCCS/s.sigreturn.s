h52055
s 00011/00006/00027
d D 5.3 88/06/27 18:42:13 bostic 3 2
c install approved copyright notice
e
s 00010/00004/00023
d D 5.2 88/05/20 15:55:08 bostic 2 1
c add Berkeley specific header
e
s 00027/00000/00000
d D 5.1 86/07/02 16:23:54 sam 1 0
c date and time created 86/07/02 16:23:54 by sam
e
u
U
t
T
I 1
/*
 * Copyright (c) 1983 Regents of the University of California.
D 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
I 2
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
E 2
 */

D 2
#ifdef SYSLIBC_SCCS
E 2
I 2
#if defined(SYSLIBC_SCCS) && !defined(lint)
E 2
D 3
_sccsid:.asciz	"%W% (Berkeley) %G%"
E 3
I 3
	.asciz "%W% (Berkeley) %G%"
E 3
D 2
#endif SYSLIBC_SCCS
E 2
I 2
#endif /* SYSLIBC_SCCS and not lint */
E 2

#include "SYS.h"

/*
 * We must preserve the state of the registers as the user has set them up.
 */
#ifdef PROF
#define	POPR(r)	movl (sp)+,r
#undef ENTRY
#define	ENTRY(x) \
	.globl _/**/x; .align 2; _/**/x: .word 0; \
	pushl r0; pushl r1; pushl r2; pushl r3; pushl r4; pushl r5; \
	.data; 1:; .long 0; .text; pushl $1b; callf $8,mcount; \
	POPR(r5); POPR(r4); POPR(r3); POPR(r2); POPR(r1); POPR(r0);
#endif PROF

SYSCALL(sigreturn)
	ret
E 1
