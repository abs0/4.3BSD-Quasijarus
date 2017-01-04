h52398
s 00007/00001/00027
d D 5.1 85/05/30 15:05:47 dist 4 3
c Add copyright
e
s 00024/00007/00004
d D 4.3 84/11/01 23:51:02 sam 3 2
c change ENTRY & ASENTRY to allow setting the register save mask
e
s 00003/00000/00008
d D 4.2 83/06/27 19:52:37 root 2 1
c need assembler entry point
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
D 3
/* %M% %I% %E% */
E 3
I 3
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4
E 3

I 3
#define R0	0x001
#define R1	0x002
#define R2	0x004
#define R3	0x008
#define R4	0x010
#define R5	0x020
#define R6	0x040
#define	R7 	0x080
#define	R8	0x100
#define	R9	0x200
#define	R10	0x400
#define	R11	0x800

E 3
#ifdef PROF
D 3
#define	ENTRY(x)	.globl _/**/x; .align 2; _/**/x: .word 0; \
			.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
I 2
#define	ASENTRY(x)	.globl x; .align 2; x: .word 0; \
			.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
E 3
I 3
#define	ENTRY(x, regs) \
	.globl _/**/x; .align 2; _/**/x: .word regs; \
	.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
#define	ASENTRY(x, regs) \
	.globl x; .align 2; x: .word regs; \
	.data; 1:; .long 0; .text; moval 1b,r0; jsb mcount
E 3
E 2
#else
D 3
#define	ENTRY(x)	.globl _/**/x; .align 2; _/**/x: .word 0
I 2
#define	ASENTRY(x)	.globl x; .align 2; x: .word 0
E 3
I 3
#define	ENTRY(x, regs) \
	.globl _/**/x; .align 2; _/**/x: .word regs
#define	ASENTRY(x, regs) \
	.globl x; .align 2; x: .word regs
E 3
E 2
#endif
E 1
