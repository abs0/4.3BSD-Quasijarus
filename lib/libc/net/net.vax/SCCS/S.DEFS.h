h45904
s 00007/00001/00007
d D 5.1 85/05/30 15:20:30 dist 2 1
c Add copyright
e
s 00008/00000/00000
d D 4.1 82/12/15 15:33:46 sam 1 0
c date and time created 82/12/15 15:33:46 by sam
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
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

#ifdef PROF
#define	ENTRY(x)	.globl _/**/x; .align 2; _/**/x: .word 0; \
			.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
#else
#define	ENTRY(x)	.globl _/**/x; .align 2; _/**/x: .word 0
#endif
E 1
