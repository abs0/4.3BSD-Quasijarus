h24252
s 00011/00001/00012
d D 1.2 88/03/28 12:34:12 bostic 2 1
c add Berkeley specific header
e
s 00013/00000/00000
d D 1.1 86/11/11 22:54:10 minshall 1 0
c date and time created 86/11/11 22:54:10 by minshall
e
u
U
t
T
I 1
/*
D 2
 *	@(#)defs.h	3.1  10/29/86
E 2
I 2
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 *
 *	%W% (Berkeley) %G%
E 2
 */

#ifdef PROF
#define	ENTRY(x)	.globl _/**/x; .align 2; _/**/x: .word 0; \
			.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
#define	ASENTRY(x)	.globl x; .align 2; x: .word 0; \
			.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
#else
#define	ENTRY(x)	.globl _/**/x; .align 2; _/**/x: .word 0
#define	ASENTRY(x)	.globl x; .align 2; x: .word 0
#endif
E 1
