h30593
s 00007/00001/00035
d D 7.1 88/05/21 18:36:33 karels 5 4
c bring up to revision 7 for tahoe release
e
s 00018/00002/00018
d D 1.3 87/07/11 15:25:44 karels 4 2
c move code definitions from signal.h
e
s 00018/00002/00018
d R 1.3 87/07/11 15:25:06 karels 3 2
c ci trap.h
e
s 00001/00000/00019
d D 1.2 86/11/25 16:43:15 sam 2 1
c kdb additions
e
s 00019/00000/00000
d D 1.1 86/01/05 18:46:24 sam 1 0
c date and time created 86/01/05 18:46:24 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

D 4
/*	first 3 constants known in system C files - don't change */
E 4
I 4
/*
 * Trap type values
 * also known in trap.c for name strings
 */

E 4
#define	T_RESADFLT	0	/* reserved addressing */
#define	T_PRIVINFLT	1	/* privileged instruction */
#define	T_RESOPFLT	2	/* reserved operand */
D 4
/*	those constants shouldn't change 	*/
E 4
#define	T_BPTFLT	3	/* breakpoint instruction */
#define	T_SYSCALL	5	/* system call (kcall) */
#define	T_ARITHTRAP	6	/* arithmetic trap */
#define	T_ASTFLT	7	/* system forced exception */
#define	T_SEGFLT	8	/* segmentation (limit) fault */
#define	T_PROTFLT	9	/* protection fault */
#define	T_TRCTRAP	10	/* trace trap */
#define	T_PAGEFLT	12	/* page fault */
#define	T_TABLEFLT	13	/* page table fault */
#define	T_ALIGNFLT	14	/* alignment fault */
#define	T_KSPNOTVAL	15	/* kernel stack pointer not valid */
#define	T_BUSERR	16	/* bus error */
I 2
#define	T_KDBTRAP	17	/* kernel debugger trap */
I 4

/* definitions for <sys/signal.h> */
#define	    ILL_RESAD_FAULT	T_RESADFLT
#define	    ILL_PRIVIN_FAULT	T_PRIVINFLT
#define	    ILL_RESOP_FAULT	T_RESOPFLT
#define	    ILL_ALIGN_FAULT	T_ALIGNFLT

/* codes for SIGFPE/ARITHTRAP */
#define	    FPE_INTOVF_TRAP	0x1	/* integer overflow */
#define	    FPE_INTDIV_TRAP	0x2	/* integer divide by zero */
#define	    FPE_FLTDIV_TRAP	0x3	/* floating/decimal divide by zero */
#define	    FPE_FLTOVF_TRAP	0x4	/* floating overflow */
#define	    FPE_FLTUND_TRAP	0x5	/* floating underflow */
E 4
E 2
E 1
