h47861
s 00010/00005/00022
d D 5.4 88/06/27 17:52:57 bostic 5 4
c install approved copyright notice
e
s 00008/00002/00019
d D 5.3 88/05/20 16:25:34 bostic 4 3
c add Berkeley specific header
e
s 00001/00001/00020
d D 5.2 88/05/19 13:50:59 bostic 3 2
c move syscall.h to /sys/h
e
s 00007/00001/00014
d D 5.1 85/06/05 09:38:40 dist 2 1
c Add copyright
e
s 00015/00000/00000
d D 4.1 83/05/10 13:27:36 sam 1 0
c date and time created 83/05/10 13:27:36 by sam
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
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 *
 *	%W% (Berkeley) %G%
 */
E 2

D 3
#include <syscall.h>
E 3
I 3
#include <sys/syscall.h>
E 3

#ifdef PROF
#define	ENTRY(x)	.globl _/**/x; .align 2; _/**/x: .word 0; \
			.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
#else
#define	ENTRY(x)	.globl _/**/x; .align 2; _/**/x: .word 0
#endif PROF
#define	SYSCALL(x)	err: jmp cerror; ENTRY(x); chmk $SYS_/**/x; jcs err
#define	PSEUDO(x,y)	ENTRY(x); chmk $SYS_/**/y
#define	CALL(x,y)	calls $x, _/**/y

	.globl	cerror
E 1
