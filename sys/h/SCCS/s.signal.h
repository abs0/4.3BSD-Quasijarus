h62327
s 00005/00001/00105
d D 7.4 04/01/11 11:39:57 msokolov 21 20
c make it usable by assembly code, it's used by the new same mode emulator
e
s 00004/00000/00102
d D 7.3 88/05/14 11:24:40 karels 20 19
c use "../machine" for consistency (for now)
e
s 00002/00014/00100
d D 7.2 87/07/11 15:24:56 karels 19 18
c move code definitions to <machine/trap.h>
e
s 00001/00001/00113
d D 7.1 86/06/04 23:27:39 mckusick 18 17
c 4.3BSD release version
e
s 00003/00003/00111
d D 6.9 86/02/20 14:04:41 karels 17 16
c typo
e
s 00002/00000/00112
d D 6.8 86/02/02 21:32:54 karels 16 15
c compatibility with those other people
e
s 00007/00001/00105
d D 6.7 85/06/08 15:06:58 mckusick 15 14
c Add copyright
e
s 00002/00000/00104
d D 6.6 85/05/22 18:35:00 mckusick 14 13
c define SIGUSR1 and SIGUSR2
e
s 00004/00001/00100
d D 6.5 85/03/11 20:48:13 mckusick 13 11
c generalize sv_onstack to sv_flags to allow extensions for other options
e
s 00004/00001/00100
d R 6.5 85/03/11 20:37:26 mckusick 12 11
c generalize sv_onstack to sv_flags to allow extensions for other options
e
s 00002/00000/00099
d D 6.4 85/03/07 22:17:55 mckusick 11 9
c add fp and ap to signal context so sigcatch() can become a real syscall
e
s 00002/00000/00099
d R 6.4 85/03/07 20:28:10 mckusick 10 9
c add fp and ap to signal context so sigcatch() can become a real syscall
e
s 00001/00000/00098
d D 6.3 84/12/31 12:41:49 bloom 9 8
c added SIGWINCH
e
s 00006/00000/00092
d D 6.2 84/08/30 13:35:59 ralph 8 7
c added sigmask macro to convert signal number to bit mask.
e
s 00000/00000/00092
d D 6.1 83/08/14 14:21:50 sam 7 6
c 4.2 distribution
e
s 00001/00000/00091
d D 4.4 83/08/14 14:21:35 sam 6 4
c must have sp as well for signal stacks to work 
e
s 00000/00000/00091
d R 6.1 83/08/08 18:29:50 sam 5 4
c 4.2 distribution
e
s 00000/00001/00091
d D 4.3 83/08/08 18:29:34 sam 4 2
c sigvec incorrectly defined
e
s 00000/00000/00092
d R 6.1 83/07/29 06:13:54 sam 3 2
c 4.2 distribution
e
s 00018/00000/00074
d D 4.2 83/06/09 21:56:57 sam 2 1
c "final" sigvec interface?
e
s 00074/00000/00000
d D 4.1 83/06/02 15:52:54 sam 1 0
c date and time created 83/06/02 15:52:54 by sam
e
u
U
t
T
I 1
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
/*
D 18
 * Copyright (c) 1982 Regents of the University of California.
E 18
I 18
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 15

#ifndef	NSIG
#define NSIG	32

I 21
#ifndef LOCORE
E 21
I 20
#ifdef KERNEL
#include "../machine/trap.h"	/* codes for SIGILL, SIGFPE */
#else
E 20
I 19
#include <machine/trap.h>	/* codes for SIGILL, SIGFPE */
I 20
#endif
I 21
#endif
E 21
E 20

E 19
#define	SIGHUP	1	/* hangup */
#define	SIGINT	2	/* interrupt */
#define	SIGQUIT	3	/* quit */
#define	SIGILL	4	/* illegal instruction (not reset when caught) */
D 19
#define	    ILL_RESAD_FAULT	0x0	/* reserved addressing fault */
#define	    ILL_PRIVIN_FAULT	0x1	/* privileged instruction fault */
#define	    ILL_RESOP_FAULT	0x2	/* reserved operand fault */
/* CHME, CHMS, CHMU are not yet given back to users reasonably */
E 19
#define	SIGTRAP	5	/* trace trap (not reset when caught) */
#define	SIGIOT	6	/* IOT instruction */
I 16
#define	SIGABRT	SIGIOT	/* compatibility */
E 16
#define	SIGEMT	7	/* EMT instruction */
#define	SIGFPE	8	/* floating point exception */
D 19
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
E 19
#define	SIGKILL	9	/* kill (cannot be caught or ignored) */
#define	SIGBUS	10	/* bus error */
#define	SIGSEGV	11	/* segmentation violation */
#define	SIGSYS	12	/* bad argument to system call */
#define	SIGPIPE	13	/* write on a pipe with no one to read it */
#define	SIGALRM	14	/* alarm clock */
#define	SIGTERM	15	/* software termination signal from kill */
#define	SIGURG	16	/* urgent condition on IO channel */
#define	SIGSTOP	17	/* sendable stop signal not from tty */
#define	SIGTSTP	18	/* stop signal from tty */
#define	SIGCONT	19	/* continue a stopped process */
#define	SIGCHLD	20	/* to parent on child stop or exit */
I 16
#define	SIGCLD	SIGCHLD	/* compatibility */
E 16
#define	SIGTTIN	21	/* to readers pgrp upon background tty read */
#define	SIGTTOU	22	/* like TTIN for output if (tp->t_local&LTOSTOP) */
#define	SIGIO	23	/* input/output possible signal */
#define	SIGXCPU	24	/* exceeded CPU time limit */
#define	SIGXFSZ	25	/* exceeded file size limit */
#define	SIGVTALRM 26	/* virtual time alarm */
#define	SIGPROF	27	/* profiling time alarm */
I 9
#define SIGWINCH 28	/* window size changes */
I 14
#define SIGUSR1 30	/* user defined signal 1 */
#define SIGUSR2 31	/* user defined signal 2 */
E 14
E 9

I 21
#ifndef LOCORE
E 21
#ifndef KERNEL
int	(*signal())();
I 2
D 4
int	(*sigvec())();
E 4
E 2
#endif
I 2

/*
 * Signal vector "template" used in sigvec call.
 */
struct	sigvec {
	int	(*sv_handler)();	/* signal handler */
	int	sv_mask;		/* signal mask to apply */
D 13
	int	sv_onstack;		/* if non-zero, take on signal stack */
E 13
I 13
	int	sv_flags;		/* see signal options below */
E 13
};
I 13
#define SV_ONSTACK	0x0001	/* take signal on signal stack */
#define SV_INTERRUPT	0x0002	/* do not restart system on signal return */
#define sv_onstack sv_flags	/* isn't compatibility wonderful! */
E 13

/*
 * Structure used in sigstack call.
 */
struct	sigstack {
	char	*ss_sp;			/* signal stack pointer */
	int	ss_onstack;		/* current status */
};
E 2

/*
 * Information pushed on stack when a signal is delivered.
 * This is used by the kernel to restore state following
 * execution of the signal handler.  It is also made available
 * to the handler to allow it to properly restore state if
 * a non-standard exit is performed.
 */
struct	sigcontext {
	int	sc_onstack;		/* sigstack state to restore */
	int	sc_mask;		/* signal mask to restore */
I 6
	int	sc_sp;			/* sp to restore */
I 11
D 17
	int	sc_fp;			/* fp to retore */
	int	sc_ap;			/* ap to retore */
E 11
E 6
	int	sc_pc;			/* pc to retore */
E 17
I 17
	int	sc_fp;			/* fp to restore */
	int	sc_ap;			/* ap to restore */
	int	sc_pc;			/* pc to restore */
E 17
	int	sc_ps;			/* psl to restore */
};

#define	BADSIG		(int (*)())-1
#define	SIG_DFL		(int (*)())0
#define	SIG_IGN		(int (*)())1

#ifdef KERNEL
#define	SIG_CATCH	(int (*)())2
#define	SIG_HOLD	(int (*)())3
#endif
D 21
#endif
E 21
I 8

/*
 * Macro for converting signal number to a mask suitable for
 * sigblock().
 */
#define sigmask(m)	(1 << ((m)-1))
I 21
#endif	!LOCORE
#endif	!NSIG
E 21
E 8
E 1
