h57730
s 00009/00003/00033
d D 5.3 86/08/01 09:24:00 sam 4 3
c oops, gotta push counter for mcount
e
s 00006/00000/00030
d D 5.2 86/08/01 09:08:35 sam 3 1
c add XENTRY for fpe
e
s 00006/00000/00030
d R 5.2 86/08/01 09:03:00 sam 2 1
c add XENTRY for fpe code
e
s 00030/00000/00000
d D 5.1 86/08/01 08:52:45 sam 1 0
c date and time created 86/08/01 08:52:45 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

/*
 * Macros used to define entry points
 * in assembly language routines.
 */
#if defined(GPROF) || defined(PROF)
#define	ENTRY(name, regs) \
D 4
	.globl _/**/name; .align 2; _/**/name: .word regs; callf $4,mcount
E 4
I 4
	.globl _/**/name; .align 2; _/**/name: .word regs; \
	.data; .align 2; 1: .long 0; .text; \
	pushal 1b; callf $8,mcount;
E 4
#define	ASENTRY(name, regs) \
D 4
	.globl name; .align 2; name: .word regs; callf $4,mcount
E 4
I 4
	.globl name; .align 2; name: .word regs; \
	.data; .align 2; 1: .long 0; .text; \
	pushal 1b; callf $8,mcount;
E 4
I 3
#define	XENTRY(name, regs) \
	.globl _/**/name; .globl X/**/name; .align 2; \
D 4
	_/**/name: X/**/name: .word regs; callf $4,mcount
E 4
I 4
	_/**/name: X/**/name: .word regs; \
	.data; .align 2; 1: .long 0; .text; \
	pushal 1b; callf $8,mcount
E 4
E 3
#else
#define	ENTRY(name, regs) \
	.globl _/**/name; .align 2; _/**/name: .word regs
#define	ASENTRY(name, regs) \
	.globl name; .align 2; name: .word regs
I 3
#define	XENTRY(name, regs) \
	.globl _/**/name; .globl X/**/name; .align 2; \
	_/**/name: X/**/name: .word regs;
E 3
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
