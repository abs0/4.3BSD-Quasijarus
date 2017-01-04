h11461
s 00002/00002/00044
d D 5.2 86/03/09 19:56:29 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00037
d D 5.1 85/05/30 10:50:50 dist 4 3
c Add copyright
e
s 00003/00003/00035
d D 4.3 85/05/22 18:40:20 mckusick 3 2
c add definitions for SIGWINCH, SIGUSR1, and SIGUSR2
e
s 00002/00000/00036
d D 4.2 83/02/10 22:48:35 sam 2 1
c must have signal.h
e
s 00036/00000/00000
d D 4.1 83/02/10 22:46:01 sam 1 0
c date and time created 83/02/10 22:46:01 by sam
e
u
U
t
T
I 1
D 4
/*	%W% (Berkeley) %G%	*/
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5
E 4

I 2
#include <signal.h>

E 2
char	*sys_siglist[NSIG] = {
	"Signal 0",
	"Hangup",			/* SIGHUP */
	"Interrupt",			/* SIGINT */
	"Quit",				/* SIGQUIT */
	"Illegal instruction",		/* SIGILL */
	"Trace/BPT trap",		/* SIGTRAP */
	"IOT trap",			/* SIGIOT */
	"EMT trap",			/* SIGEMT */
	"Floating point exception",	/* SIGFPE */
	"Killed",			/* SIGKILL */
	"Bus error",			/* SIGBUS */
	"Segmentation fault",		/* SIGSEGV */
	"Bad system call",		/* SIGSYS */
	"Broken pipe",			/* SIGPIPE */
	"Alarm clock",			/* SIGALRM */
	"Terminated",			/* SIGTERM */
	"Urgent I/O condition",		/* SIGURG */
	"Stopped (signal)",		/* SIGSTOP */
	"Stopped",			/* SIGTSTP */
	"Continued",			/* SIGCONT */
	"Child exited",			/* SIGCHLD */
	"Stopped (tty input)",		/* SIGTTIN */
	"Stopped (tty output)",		/* SIGTTOU */
	"I/O possible",			/* SIGIO */
	"Cputime limit exceeded",	/* SIGXCPU */
	"Filesize limit exceeded",	/* SIGXFSZ */
	"Virtual timer expired",	/* SIGVTALRM */
	"Profiling timer expired",	/* SIGPROF */
D 3
	"Signal 28",
E 3
I 3
	"Window size changes",		/* SIGWINCH */
E 3
	"Signal 29",
D 3
	"Signal 30",
	"Signal 31"
E 3
I 3
	"User defined signal 1",	/* SIGUSR1 */
	"User defined signal 2"		/* SIGUSR2 */
E 3
};
E 1
