h65166
s 00010/00005/00037
d D 7.2 88/06/29 17:34:28 bostic 4 3
c install approved copyright notice
e
s 00013/00001/00029
d D 7.1 88/05/21 18:34:52 karels 3 2
c bring up to revision 7 for tahoe release
e
s 00002/00002/00028
d D 1.2 86/01/24 14:16:47 sam 2 1
c call to mcount must be callf $4,mcount
e
s 00030/00000/00000
d D 1.1 86/01/05 18:46:19 sam 1 0
c date and time created 86/01/05 18:46:19 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
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
 *
 *	%W% (Berkeley) %G%
 */
E 3

/*
 * Macros used to define entry points
 * in assembly language routines.
 */
#if defined(GPROF) || defined(PROF)
#define	ENTRY(name, regs) \
D 2
	.globl _/**/name; .align 2; _/**/name: .word regs; callf $0,mcount
E 2
I 2
	.globl _/**/name; .align 2; _/**/name: .word regs; callf $4,mcount
E 2
#define	ASENTRY(name, regs) \
D 2
	.globl name; .align 2; name: .word regs; callf $0,mcount
E 2
I 2
	.globl name; .align 2; name: .word regs; callf $4,mcount
E 2
#else
#define	ENTRY(name, regs) \
	.globl _/**/name; .align 2; _/**/name: .word regs
#define	ASENTRY(name, regs) \
	.globl name; .align 2; name: .word regs
#endif
#define R0	0x0001
#define R1	0x0002
#define R2	0x0004
#define R3	0x0008
#define R4	0x0010
#define R5	0x0020
#define R6	0x0040
#define	R7	0x0080
#define	R8	0x0100
#define	R9	0x0200
#define	R10	0x0400
#define	R11	0x0800
#define	R12	0x1000
E 1
