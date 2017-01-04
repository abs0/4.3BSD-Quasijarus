h60637
s 00038/00002/00121
d D 5.3 86/11/03 21:52:35 mckusick 24 23
c update for tahoe
e
s 00000/00035/00123
d D 5.2 85/06/26 19:06:04 jerry 23 22
c move f77_abort() and no_lg.c to libI77.
e
s 00007/00003/00151
d D 5.1 85/06/07 22:07:21 kre 22 21
c Add copyright
e
s 00006/00002/00148
d D 2.17 85/06/04 21:09:16 libs 21 20
c check directly for -lg.
e
s 00031/00016/00119
d D 2.16 85/05/14 21:40:24 libs 20 15
c define f77_abort() as centralized abend proc. for f77 giving consistent
c error handling and dumps only when wanted.  Also add return 0; to main.
e
s 00030/00016/00119
d R 2.16 85/05/09 23:07:43 libs 19 15
c call f77_abort() instead of abort() to get consistent error handling
c and dumps only when wanted.
e
s 00026/00007/00128
d R 2.16 85/05/06 17:47:47 libs 18 15
c Have sigdie() call f77_abort; define f77_abort() so dumps are
c generated only on demand by loader option or environment variable settings.
e
s 00025/00007/00128
d R 2.16 85/05/06 17:03:33 libs 17 15
c Change all calls to abort() to f77_abort() and have f77_abort() 
c call abort() for dump only when environment and load flags so specify.
e
s 00022/00007/00128
d R 2.16 85/05/06 14:12:58 libs 16 15
c Change all calls to abort() to f77_abort() and have f77_abort() 
c call abort() for dump only when environment and load flags so specify.
e
s 00009/00001/00126
d D 2.15 83/08/25 16:36:25 dlw 15 14
c reset signals to default to prevent looping on total disaster. DLW
e
s 00010/00002/00117
d D 2.14 83/08/08 22:08:37 dlw 14 13
c adapted to 4.2 signal conventions. DLW
e
s 00003/00017/00116
d D 2.13 83/06/21 21:32:37 dlw 13 12
c removed #ifdef UCBVAX. DLW
e
s 00001/00001/00132
d D 2.12 83/05/19 13:05:57 fortran 12 11
c changed MAIN__ to MAIN_
e
s 00014/00014/00119
d D 2.11 82/10/30 22:09:20 dlw 11 10
c fixed conditionals to use vax (not VAX). DLW
e
s 00004/00003/00129
d D 2.10 81/11/03 16:06:22 dlw 10 9
c f_exit() after error messages on sigdie(). DLW
e
s 00002/00002/00130
d D 2.9 81/08/20 13:09:27 dlw 9 8
c added *** to error messages. DLW
e
s 00017/00001/00115
d D 2.8 81/08/20 10:39:07 dlw 8 7
c added descriptions to SIGILL mesg. DLW
e
s 00021/00018/00095
d D 2.7 81/08/19 13:05:07 dlw 7 6
c arranged to trap EVERY signal. DLW
e
s 00005/00001/00108
d D 2.6 81/08/13 21:56:15 dlw 6 5
c changed wording of FPE mesg for the pdp11's. DLW
e
s 00033/00004/00076
d D 2.5 81/08/13 18:47:26 dlw 5 4
c added UCBVAX fpe definitions. DLW
e
s 00007/00007/00073
d D 2.4 81/08/13 17:54:23 dlw 4 3
c fixed signal expression inside the if's. DLW
e
s 00039/00073/00041
d D 2.3 81/08/13 15:38:10 dlw 3 2
c replaced individual sigtraps with one & an action table. DLW
e
s 00036/00008/00078
d D 2.2 81/08/13 10:26:26 dlw 2 1
c added other signals to catch list. DLW
e
s 00086/00000/00000
d D 2.1 81/08/13 10:25:08 dlw 1 0
c date and time created 81/08/13 10:25:08 by dlw
e
u
U
t
T
I 1
D 22
/* STARTUP PROCEDURE FOR UNIX FORTRAN PROGRAMS */
I 2
D 3
char id_libF77[] = "%W%";
E 3
I 3
char id_libF77[] = "%W%	%G%";
E 3
E 2

E 22
I 22
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W%	%G%
 */
E 22
#include <stdio.h>
#include <signal.h>
I 2
#include "../libI77/fiodefs.h"
E 2

I 24
extern int errno;
char *getenv();
E 24
I 20
D 23
extern int errno;
char *getenv();
D 21
int f77_dump_flag;
E 21

E 23
E 20
int xargc;
char **xargv;

main(argc, argv, arge)
int argc;
char **argv;
char **arge;
{
D 3
int sigfdie(), sigidie(), sigqdie(), sigindie(), sigtdie();
I 2
int sigildie(), sigedie(), sigbdie(), sigsdie();
E 3
I 3
int sigdie();
E 3
E 2
long int (*sigf)();
I 7
int signum;
E 7

xargc = argc;
xargv = argv;
D 3
signal(SIGFPE, sigfdie);	/* ignore underflow, enable overflow */
signal(SIGIOT, sigidie);
if(sigf=signal(SIGQUIT, sigqdie) != SIG_DFL) signal(SIGQUIT, sigf);
if(sigf=signal(SIGINT, sigindie) != SIG_DFL) signal(SIGINT, sigf);
if(sigf=signal(SIGTERM, sigtdie) != SIG_DFL) signal(SIGTERM, sigf);
I 2
if(sigf=signal(SIGILL, sigildie) != SIG_DFL) signal(SIGILL, sigf);
if(sigf=signal(SIGEMT, sigedie) != SIG_DFL) signal(SIGEMT, sigf);
if(sigf=signal(SIGBUS, sigbdie) != SIG_DFL) signal(SIGBUS, sigf);
if(sigf=signal(SIGSEGV, sigsdie) != SIG_DFL) signal(SIGSEGV, sigf);
E 3
I 3
D 7
signal(SIGFPE, sigdie);	/* ignore underflow, enable overflow */
signal(SIGIOT, sigdie);
D 4
if(sigf=signal(SIGQUIT, sigdie) != SIG_DFL) signal(SIGQUIT, sigf);
if(sigf=signal(SIGINT,  sigdie) != SIG_DFL) signal(SIGINT,  sigf);
if(sigf=signal(SIGTERM, sigdie) != SIG_DFL) signal(SIGTERM, sigf);
if(sigf=signal(SIGILL,  sigdie) != SIG_DFL) signal(SIGILL,  sigf);
if(sigf=signal(SIGEMT,  sigdie) != SIG_DFL) signal(SIGEMT,  sigf);
if(sigf=signal(SIGBUS,  sigdie) != SIG_DFL) signal(SIGBUS,  sigf);
if(sigf=signal(SIGSEGV, sigdie) != SIG_DFL) signal(SIGSEGV, sigf);
E 4
I 4
if((sigf=signal(SIGQUIT, sigdie)) != SIG_DFL) signal(SIGQUIT, sigf);
if((sigf=signal(SIGINT,  sigdie)) != SIG_DFL) signal(SIGINT,  sigf);
if((sigf=signal(SIGTERM, sigdie)) != SIG_DFL) signal(SIGTERM, sigf);
if((sigf=signal(SIGILL,  sigdie)) != SIG_DFL) signal(SIGILL,  sigf);
if((sigf=signal(SIGEMT,  sigdie)) != SIG_DFL) signal(SIGEMT,  sigf);
if((sigf=signal(SIGBUS,  sigdie)) != SIG_DFL) signal(SIGBUS,  sigf);
if((sigf=signal(SIGSEGV, sigdie)) != SIG_DFL) signal(SIGSEGV, sigf);
E 7
E 4
E 3
E 2

I 7
for (signum=1; signum<=16; signum++)
{
	if((sigf=signal(signum, sigdie)) != SIG_DFL) signal(signum, sigf);
}

E 7
#ifdef pdp11
	ldfps(01200); /* detect overflow as an exception */
#endif

f_init();
D 12
MAIN__();
E 12
I 12
MAIN_();
E 12
f_exit();
I 20
return 0;
E 20
}

I 3
struct action {
	char *mesg;
	int   core;
} sig_act[16] = {
D 7
	{ 0, 0},			/* SIGHUP  */
E 7
I 7
	{"Hangup", 0},			/* SIGHUP  */
E 7
	{"Interrupt!", 0},		/* SIGINT  */
	{"Quit!", 1},			/* SIGQUIT */
I 8
D 11
#ifdef UCBVAX
E 11
I 11
D 13
#ifdef	UCBVAX
E 13
E 11
	{"Illegal ", 1},		/* SIGILL  */
D 11
#else
E 11
I 11
D 13
#else	UCBVAX
E 11
E 8
	{"Illegal instruction", 1},	/* SIGILL  */
I 8
D 11
#endif
E 11
I 11
#endif	UCBVAX
E 13
E 11
E 8
D 7
	{ 0, 0},			/* SIGTRAP */
E 7
I 7
	{"Trace Trap", 1},		/* SIGTRAP */
E 7
	{"IOT Trap", 1},		/* SIGIOT  */
D 6
	{"EMT trap", 1},		/* SIGEMT  */
E 6
I 6
	{"EMT Trap", 1},		/* SIGEMT  */
D 11
#ifdef UCBVAX
E 11
I 11
D 13
#ifdef	UCBVAX
E 13
E 11
E 6
D 5
	{"Floating Point Exception", 1},/* SIGFPE  */
E 5
I 5
	{"Arithmetic Exception", 1},	/* SIGFPE  */
I 6
D 11
#else
E 11
I 11
D 13
#else	UCBVAX
E 11
	{"Floating Point Exception", 1},/* SIGFPE  */
D 11
#endif
E 11
I 11
#endif	UCBVAX
E 13
E 11
E 6
E 5
	{ 0, 0},			/* SIGKILL */
	{"Bus error", 1},		/* SIGBUS  */
	{"Segmentation violation", 1},	/* SIGSEGV */
D 7
	{ 0, 0},			/* SIGSYS  */
	{ 0, 0},			/* SIGPIPE */
	{ 0, 0},			/* SIGALRM */
E 7
I 7
	{"Sys arg", 1},			/* SIGSYS  */
	{"Open pipe", 0},		/* SIGPIPE */
	{"Alarm", 0},			/* SIGALRM */
E 7
	{"Terminated", 0},		/* SIGTERM */
D 7
	{ 0, 0},			/* unassigned */
E 7
I 7
	{"Sig 16", 0},			/* unassigned */
E 7
};
E 3

I 24
#ifdef tahoe
/* The following arrays are defined & used assuming that signal codes are 
   1 to 5 for SIGFPE, and 0 to 3 for SIGILL. 
   Actually ILL_ALIGN_FAULT=14, and is mapped to 3. */

#define N_ACT_ILL 4			/* number of entries in act_ill[] */
#define N_ACT_FPE 5			/* number of entries in act_fpe[] */
#define ILL_ALIGN_FAULT 14

E 24
I 5
D 11
#ifdef UCBVAX
E 11
I 11
D 13
#ifdef	UCBVAX
E 13
E 11
struct action act_fpe[] = {
	{"Integer overflow", 1},
	{"Integer divide by 0", 1},
I 24
	{"Floating divide by zero", 1},
	{"Floating point overflow", 1},
	{"Floating point underflow", 1},
};

#else vax || pdp11

struct action act_fpe[] = {
	{"Integer overflow", 1},
	{"Integer divide by 0", 1},
E 24
D 13
	{"Floating point overflow", 1},
	{"Floating divide by zero", 1},
	{"Floating point underflow", 1},
E 13
I 13
	{"Floating point overflow trap", 1},
	{"Floating divide by zero trap", 1},
	{"Floating point underflow trap", 1},
E 13
	{"Decimal overflow", 1},
	{"Subscript range", 1},
	{"Floating point overflow", 0},
	{"Floating divide by zero", 0},
	{"Floating point underflow", 0},
};
I 24
#endif vax || pdp11
E 24
I 8

struct action act_ill[] = {
	{"addr mode", 1},
	{"instruction", 1},
	{"operand", 0},
I 24
#ifdef tahoe
	{"alignment", 1},
#endif tahoe
E 24
};
E 8
D 11
#endif
E 11
I 11
D 13
#endif	UCBVAX
E 13
E 11
E 5
D 3
static sigfdie()
{
sigdie("Floating Exception", 1);
}
E 3

I 14
D 24
#if	vax
E 24
I 24
#if (defined(vax) || defined(tahoe))
E 24
sigdie(s, t, sc)
int s; int t; struct sigcontext *sc;

#else	pdp11
I 24

E 24
E 14
D 3

D 2

E 2
static sigidie()
E 3
I 3
D 5
sigdie(s)
int s;
E 5
I 5
sigdie(s, t, pc)
int s; int t; long pc;
I 14

D 24
#endif
E 24
I 24
#endif pdp11
E 24
E 14
E 5
E 3
{
D 3
sigdie("IOT Trap", 1);
}


static sigqdie()
{
sigdie("Quit signal", 1);
}


D 2

E 2
static sigindie()
{
sigdie("Interrupt!", 0);
}


D 2

E 2
static sigtdie()
{
sigdie("Killed", 0);
}


I 2
static sigildie()
{
sigdie("Illegal instruction", 1);
}
E 2

D 2
static sigdie(s, kill)
E 2
I 2

static sigedie()
{
sigdie("EMT trap", 1);
}


static sigbdie()
{
sigdie("Bus error", 1);
}


static sigsdie()
{
sigdie("Segmentation violation", 1);
}


static sigdie(s, core)
E 2
register char *s;
D 2
int kill;
E 2
I 2
int core;
E 2
{
E 3
D 2
/* print error message, then clear buffers */
fprintf(stderr, "%s\n", s);
E 2
I 2
extern unit units[];
I 3
register struct action *act = &sig_act[s-1];
E 3
D 10
/* clear buffers, then print error message */
E 2
f_exit();
E 10
I 10
/* print error message, then flush buffers */

I 15
if (s == SIGHUP || s == SIGINT || s == SIGQUIT)
	signal(s, SIG_IGN);	/* don't allow it again */
else
	signal(s, SIG_DFL);	/* shouldn't happen again, but ... */

D 20
#if	vax
sigsetmask(0);			/* don't block */
#endif

E 20
E 15
E 10
I 2
D 3
fprintf(units[STDERR].ufd, "%s\n", s);
E 3
I 3
D 5
if (act->mesg) fprintf(units[STDERR].ufd, "%s\n", act->mesg);
E 5
I 5
if (act->mesg)
	{
D 11
#ifdef UCBVAX
E 11
I 11
D 13
#ifdef	UCBVAX
E 13
E 11
D 9
	fprintf(units[STDERR].ufd, "%s", act->mesg);
E 9
I 9
	fprintf(units[STDERR].ufd, "*** %s", act->mesg);
E 9
	if (s == SIGFPE)
D 7
		fprintf(units[STDERR].ufd, ": %s\n", act_fpe[t-1].mesg);
	else
		putc('\n', units[STDERR].ufd);
E 7
I 7
		{
I 24
#ifndef tahoe
E 24
		if (t >= 1 && t <= 10)
I 24
#else tahoe
		if ((t-1) >= 0 && t < N_ACT_FPE)
#endif tahoe
E 24
			fprintf(units[STDERR].ufd, ": %s", act_fpe[t-1].mesg);
		else
			fprintf(units[STDERR].ufd, ": Type=%d?", t);
		}
	else if (s == SIGILL)
D 8
		fprintf(units[STDERR].ufd, ": Code=%d", t);
E 8
I 8
		{
I 24
#ifndef tahoe
E 24
		if (t == 4) t = 2;	/* 4.0bsd botch */
		if (t >= 0 && t <= 2)
I 24
#else tahoe
		if (t == ILL_ALIGN_FAULT)	/* ILL_ALIGN_FAULT maps to last
			t = N_ACT_ILL-1;   	   entry in act_ill[] */
		if (t >= 0 && t < N_ACT_ILL)
#endif tahoe
E 24
			fprintf(units[STDERR].ufd, "%s", act_ill[t].mesg);
		else
			fprintf(units[STDERR].ufd, "compat mode: Code=%d", t);
		}
E 8
	putc('\n', units[STDERR].ufd);
E 7
D 11
#else
E 11
I 11
D 13
#else	UCBVAX
E 11
D 9
	fprintf(units[STDERR].ufd, "%s\n", act->mesg);
E 9
I 9
	fprintf(units[STDERR].ufd, "*** %s\n", act->mesg);
E 9
D 11
#endif
E 11
I 11
#endif	UCBVAX
E 13
E 11
	}
I 10
D 20
f_exit();
E 10
E 5
E 3
E 2
_cleanup();
E 20
I 20
f77_abort( s, act->core );
D 23
}
E 20

I 21
extern int _dbsubc;	/* dbsubc is non-zero if -lg was specified to ld */
E 21
D 2
if(kill)
E 2
I 2
D 3
if(core)
E 3
I 3
D 20
if(act->core)
E 3
E 2
	{
	/* now get a core */
I 5
D 11
#ifdef VAX
E 11
I 11
#if	vax
E 20
I 20
f77_abort( err_val, act_core )
{
	char first_char, *env_var;
	int core_dump;

	env_var = getenv("f77_dump_flag");
	first_char = (env_var == NULL) ? 0 : *env_var;

E 20
E 11
	signal(SIGILL, SIG_DFL);
D 11
#else
E 11
I 11
D 14
#else	vax
E 14
I 14
D 15
	sigsetmask(0);
E 15
D 20
#else	pdp11
E 14
E 11
E 5
D 3
	signal(SIGIOT, 0);
E 3
I 3
	signal(SIGIOT, SIG_DFL);
I 5
D 11
#endif
E 11
I 11
D 14
#endif	vax
E 14
I 14
#endif
E 14
E 11
E 5
E 3
	abort();
	}
D 3
else
	exit(1);
E 3
I 3
exit(s);
E 20
I 20
	sigsetmask(0);			/* don't block */

I 21
	/* see if we want a core dump:
		first line checks for signals like hangup - don't dump then.
		second line checks if -lg specified to ld (e.g. by saying
			-g to f77) and checks the f77_dump_flag var. */
E 21
	core_dump = ((nargs() != 2) || act_core) &&
D 21
	    ( (f77_dump_flag && (first_char != 'n')) || first_char == 'y');
E 21
I 21
	    ( (_dbsubc && (first_char != 'n')) || first_char == 'y');
E 21

	if( !core_dump )
		fprintf(units[STDERR].ufd,"*** Execution terminated\n");

	f_exit();
	_cleanup();
	if( nargs() ) errno = err_val;
	else errno = -2;   /* prior value will be meaningless,
				so set it to undefined value */

	if( core_dump ) abort();
	else  exit( errno );
E 23
E 20
E 3
}
E 1
