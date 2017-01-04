h56121
s 00018/00002/00027
d D 7.3 87/07/11 15:26:01 karels 14 13
c move code definitions from signal.h
e
s 00001/00000/00028
d D 7.2 87/02/21 11:19:16 karels 13 12
c kdb (for sam; untested); misc.
e
s 00001/00001/00027
d D 7.1 86/06/05 00:49:02 mckusick 12 11
c 4.3BSD release version
e
s 00007/00001/00021
d D 6.2 85/06/08 13:46:46 mckusick 11 10
c Add copyright
e
s 00000/00000/00022
d D 6.1 83/07/29 07:21:26 sam 10 9
c 4.2 distribution
e
s 00014/00014/00008
d D 4.7 82/10/31 15:15:19 root 9 8
c change to T_... names for trap codes
e
s 00002/00000/00020
d D 4.6 81/03/03 18:31:45 wnj 8 7
c add comments
e
s 00003/00003/00017
d D 4.5 81/03/03 18:31:00 wnj 7 6
c rearrange numbers for /usr/include/signal.h's sake
e
s 00000/00002/00020
d D 4.4 81/02/26 04:30:17 wnj 6 5
c cosmetics
e
s 00001/00001/00021
d D 4.3 81/02/19 21:42:37 wnj 5 4
c %G%->%E%
e
s 00001/00002/00021
d D 4.2 81/02/15 20:37:34 wnj 4 3
c ast and hard/soft clock
e
s 00000/00000/00023
d D 4.1 80/11/09 17:01:51 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00022
d D 3.2 80/06/07 03:01:22 bill 2 1
c %H%->%G%
e
s 00023/00000/00000
d D 3.1 80/04/09 16:25:36 bill 1 0
c date and time created 80/04/09 16:25:36 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 12
 * Copyright (c) 1982 Regents of the University of California.
E 12
I 12
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11
E 5
E 2

/*
 * Trap type values
I 14
 * also known in trap.c for name strings
E 14
D 6
 *
 * NB: OFFSETS HERE ARE ALSO DEFINED IN trap.m
E 6
 */

I 8
D 14
/* The first three constant values are known to the real world <signal.h> */
E 14
E 8
D 9
#define	RESADFLT	0		/* reserved addressing fault */
#define	PRIVINFLT	1		/* privileged instruction fault */
D 7
#define	BPTFLT		2		/* bpt instruction fault */
#define	XFCFLT		3		/* xfc instruction fault */
#define	RESOPFLT	4		/* reserved operand fault */
E 7
I 7
#define	RESOPFLT	2		/* reserved operand fault */
E 9
I 9
#define	T_RESADFLT	0		/* reserved addressing fault */
#define	T_PRIVINFLT	1		/* privileged instruction fault */
#define	T_RESOPFLT	2		/* reserved operand fault */
E 9
I 8
D 14
/* End of known constants */
E 14
I 14
/* definitions for <sys/signal.h> */
#define	    ILL_RESAD_FAULT	T_RESADFLT
#define	    ILL_PRIVIN_FAULT	T_PRIVINFLT
#define	    ILL_RESOP_FAULT	T_RESOPFLT
/* CHME, CHMS, CHMU are not yet given back to users reasonably */
E 14
E 8
D 9
#define	BPTFLT		3		/* bpt instruction fault */
#define	XFCFLT		4		/* xfc instruction fault */
E 7
#define	SYSCALL		5		/* chmk instruction (syscall trap) */
#define	ARITHTRAP	6		/* arithmetic trap */
D 4
#define	RESCHED		7		/* software level 1 trap
					   (reschedule trap) */
E 4
I 4
#define	ASTFLT		7		/* software level 2 trap (ast deliv) */
E 4
#define	SEGFLT		8		/* segmentation fault */
#define	PROTFLT		9		/* protection fault */
#define	TRCTRAP		10		/* trace trap */
#define	COMPATFLT	11		/* compatibility mode fault */
#define	PAGEFLT		12		/* page fault */
#define	TABLEFLT	13		/* page table fault */
E 9
I 9
#define	T_BPTFLT	3		/* bpt instruction fault */
#define	T_XFCFLT	4		/* xfc instruction fault */
#define	T_SYSCALL	5		/* chmk instruction (syscall trap) */
#define	T_ARITHTRAP	6		/* arithmetic trap */
#define	T_ASTFLT	7		/* software level 2 trap (ast deliv) */
#define	T_SEGFLT	8		/* segmentation fault */
#define	T_PROTFLT	9		/* protection fault */
#define	T_TRCTRAP	10		/* trace trap */
#define	T_COMPATFLT	11		/* compatibility mode fault */
#define	T_PAGEFLT	12		/* page fault */
#define	T_TABLEFLT	13		/* page table fault */
I 13
#define	T_KDBTRAP	14		/* kernel debugger trap */
I 14

/* codes for SIGFPE/ARITHTRAP */
#define	    FPE_INTOVF_TRAP	0x1	/* integer overflow */
#define	    FPE_INTDIV_TRAP	0x2	/* integer divide by zero */
#define	    FPE_FLTOVF_TRAP	0x3	/* floating overflow */
#define	    FPE_FLTDIV_TRAP	0x4	/* floating/decimal divide by zero */
#define	    FPE_FLTUND_TRAP	0x5	/* floating underflow */
#define	    FPE_DECOVF_TRAP	0x6	/* decimal overflow */
#define	    FPE_SUBRNG_TRAP	0x7	/* subscript out of range */
#define	    FPE_FLTOVF_FAULT	0x8	/* floating overflow fault */
#define	    FPE_FLTDIV_FAULT	0x9	/* divide by zero floating fault */
#define	    FPE_FLTUND_FAULT	0xa	/* floating underflow fault */
E 14
E 13
E 9
E 1
