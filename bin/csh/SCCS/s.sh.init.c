h28674
s 00004/00004/00235
d D 5.3 87/09/16 14:47:51 bostic 10 9
c use "Suspended", not "Stopped"; bug report 4.3BSD/bin/56
e
s 00003/00003/00236
d D 5.2 85/06/06 13:09:56 edward 9 8
c cleaning up after bozos
e
s 00008/00002/00231
d D 5.1 85/06/04 11:02:49 dist 8 7
c Add copyright
e
s 00001/00001/00232
d D 4.7 85/06/01 16:55:45 edward 7 6
c allow setenv with 0 and 1 arugments:
c 	setenv -> printenv
c 	setenv x -> setenv x ''
e
s 00002/00002/00231
d D 4.6 85/05/22 19:27:43 mckusick 6 5
c add SIGUSR1 and SIGUSR2
e
s 00001/00001/00232
d D 4.5 85/01/30 12:10:42 edward 5 4
c SIGWINCH added
e
s 00009/00009/00224
d D 4.4 84/12/13 14:40:22 edward 4 3
c performance
e
s 00004/00000/00229
d D 4.3 83/06/11 00:01:04 sam 3 2
c new signals; no libjobs
e
s 00001/00001/00228
d D 4.2 81/08/20 23:47:48 mckusic 2 1
c put in history save and restore
e
s 00229/00000/00000
d D 4.1 80/10/09 12:41:13 bill 1 0
c date and time created 80/10/09 12:41:13 by bill
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
E 9
I 9
 * All rights reserved.  The Berkeley Software License Agreement
E 9
 * specifies the terms and conditions for redistribution.
 */

E 8
I 1
D 4
static	char *sccsid = "%Z%%M% %I% %G%";
E 4
I 4
#ifndef lint
D 8
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 8
I 8
D 9
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
I 9
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 9
E 8
E 4

#include "sh.local.h"

/*
 * C shell
 */

extern	int doalias();
extern	int dobg();
extern	int dobreak();
extern	int dochngd();
extern	int docontin();
extern	int dodirs();
extern	int doecho();
extern	int doelse();
extern	int doend();
extern	int doendif();
extern	int doendsw();
extern	int doeval();
extern	int doexit();
extern	int dofg();
extern	int doforeach();
extern	int doglob();
extern	int dogoto();
extern	int dohash();
extern	int dohist();
extern	int doif();
extern	int dojobs();
extern	int dokill();
extern	int dolet();
extern	int dolimit();
extern	int dologin();
extern	int dologout();
I 3
#ifdef NEWGRP
E 3
extern	int donewgrp();
I 3
#endif
E 3
extern	int donice();
extern	int donotify();
extern	int donohup();
extern	int doonintr();
extern	int dopopd();
extern	int dopushd();
extern	int dorepeat();
extern	int doset();
extern	int dosetenv();
extern	int dosource();
extern	int dostop();
extern	int dosuspend();
extern	int doswbrk();
extern	int doswitch();
extern	int dotime();
extern	int dounlimit();
extern	int doumask();
extern	int dowait();
extern	int dowhile();
extern	int dozip();
extern	int execash();
extern	int goodbye();
#ifdef VFORK
extern	int hashstat();
#endif
extern	int shift();
extern	int showall();
extern	int unalias();
extern	int dounhash();
extern	int unset();
extern	int dounsetenv();

#define	INF	1000

struct	biltins {
	char	*bname;
	int	(*bfunct)();
	short	minargs, maxargs;
} bfunc[] = {
	"@",		dolet,		0,	INF,
	"alias",	doalias,	0,	INF,
D 4
#ifdef debug
E 4
	"alloc",	showall,	0,	1,
D 4
#endif
E 4
	"bg",		dobg,		0,	INF,
	"break",	dobreak,	0,	0,
	"breaksw",	doswbrk,	0,	0,
#ifdef IIASA
	"bye",		goodbye,	0,	0,
#endif
	"case",		dozip,		0,	1,
	"cd",		dochngd,	0,	1,
	"chdir",	dochngd,	0,	1,
	"continue",	docontin,	0,	0,
	"default",	dozip,		0,	0,
	"dirs",		dodirs,		0,	1,
	"echo",		doecho,		0,	INF,
	"else",		doelse,		0,	INF,
	"end",		doend,		0,	0,
	"endif",	dozip,		0,	0,
	"endsw",	dozip,		0,	0,
	"eval",		doeval,		0,	INF,
	"exec",		execash,	1,	INF,
	"exit",		doexit,		0,	INF,
	"fg",		dofg,		0,	INF,
	"foreach",	doforeach,	3,	INF,
#ifdef IIASA
	"gd",		dopushd,	0,	1,
#endif
	"glob",		doglob,		0,	INF,
	"goto",		dogoto,		1,	1,
#ifdef VFORK
	"hashstat",	hashstat,	0,	0,
#endif
	"history",	dohist,		0,	2,
	"if",		doif,		1,	INF,
	"jobs",		dojobs,		0,	1,
	"kill",		dokill,		1,	INF,
	"limit",	dolimit,	0,	3,
	"login",	dologin,	0,	1,
	"logout",	dologout,	0,	0,
I 3
#ifdef NEWGRP
E 3
	"newgrp",	donewgrp,	1,	1,
I 3
#endif
E 3
	"nice",		donice,		0,	INF,
	"nohup",	donohup,	0,	INF,
	"notify",	donotify,	0,	INF,
	"onintr",	doonintr,	0,	2,
	"popd",		dopopd,		0,	1,
	"pushd",	dopushd,	0,	1,
#ifdef IIASA
	"rd",		dopopd,		0,	1,
#endif
	"rehash",	dohash,		0,	0,
	"repeat",	dorepeat,	2,	INF,
	"set",		doset,		0,	INF,
D 7
	"setenv",	dosetenv,	2,	2,
E 7
I 7
	"setenv",	dosetenv,	0,	2,
E 7
	"shift",	shift,		0,	1,
D 2
	"source",	dosource,	1,	1,
E 2
I 2
	"source",	dosource,	1,	2,
E 2
	"stop",		dostop,		1,	INF,
	"suspend",	dosuspend,	0,	0,
	"switch",	doswitch,	1,	INF,
	"time",		dotime,		0,	INF,
	"umask",	doumask,	0,	1,
	"unalias",	unalias,	1,	INF,
	"unhash",	dounhash,	0,	0,
	"unlimit",	dounlimit,	0,	INF,
	"unset",	unset,		1,	INF,
	"unsetenv",	dounsetenv,	1,	INF,
	"wait",		dowait,		0,	0,
	"while",	dowhile,	1,	INF,
D 4
	0,		0,		0,	0,
E 4
};
I 4
int nbfunc = sizeof bfunc / sizeof *bfunc;
E 4

#define	ZBREAK		0
#define	ZBRKSW		1
#define	ZCASE		2
#define	ZDEFAULT 	3
#define	ZELSE		4
#define	ZEND		5
#define	ZENDIF		6
#define	ZENDSW		7
#define	ZEXIT		8
#define	ZFOREACH	9
#define	ZGOTO		10
#define	ZIF		11
#define	ZLABEL		12
#define	ZLET		13
#define	ZSET		14
#define	ZSWITCH		15
#define	ZTEST		16
#define	ZTHEN		17
#define	ZWHILE		18

struct srch {
	char	*s_name;
	short	s_value;
} srchn[] = {
	"@",		ZLET,
	"break",	ZBREAK,
	"breaksw",	ZBRKSW,
	"case",		ZCASE,
	"default", 	ZDEFAULT,
	"else",		ZELSE,
	"end",		ZEND,
	"endif",	ZENDIF,
	"endsw",	ZENDSW,
	"exit",		ZEXIT,
	"foreach", 	ZFOREACH,
	"goto",		ZGOTO,
	"if",		ZIF,
	"label",	ZLABEL,
	"set",		ZSET,
	"switch",	ZSWITCH,
	"while",	ZWHILE,
D 4
	0,		0,
E 4
};
I 4
int nsrchn = sizeof srchn / sizeof *srchn;
E 4

struct	mesg {
	char	*iname;
	char	*pname;
} mesg[] = {
	0,	0,
	"HUP",	"Hangup",
	"INT",	"Interrupt",	
	"QUIT",	"Quit",
	"ILL",	"Illegal instruction",
	"TRAP",	"Trace/BPT trap",
	"IOT",	"IOT trap",
	"EMT",	"EMT trap",
	"FPE",	"Floating exception",
	"KILL",	"Killed",
	"BUS",	"Bus error",
	"SEGV",	"Segmentation fault",
	"SYS",	"Bad system call",
	"PIPE",	"Broken pipe",
	"ALRM",	"Alarm clock",
	"TERM",	"Terminated",
D 4
	0,	"Signal 16",
E 4
I 4
	"URG",	"Urgent I/O condition",
E 4
D 10
	"STOP",	"Stopped (signal)",
	"TSTP",	"Stopped",
E 10
I 10
	"STOP",	"Suspended (signal)",
	"TSTP",	"Suspended",
E 10
	"CONT",	"Continued",
	"CHLD",	"Child exited",
D 10
	"TTIN", "Stopped (tty input)",
	"TTOU", "Stopped (tty output)",
E 10
I 10
	"TTIN", "Suspended (tty input)",
	"TTOU", "Suspended (tty output)",
E 10
D 4
	"TINT", "Tty input interrupt",
E 4
I 4
	"IO",	"I/O possible",
E 4
	"XCPU",	"Cputime limit exceeded",
	"XFSZ", "Filesize limit exceeded",
D 4
	0,	"Signal 26",
	0,	"Signal 27",
E 4
I 4
	"VTALRM","Virtual timer expired",
	"PROF",	"Profiling timer expired",
E 4
D 5
	0,	"Signal 28",
E 5
I 5
	"WINCH","Window size changed",
E 5
	0,	"Signal 29",
D 6
	0,	"Signal 30",
	0,	"Signal 31",
E 6
I 6
	"USR1",	"User defined signal 1",
	"USR2",	"User defined signal 2",
E 6
	0,	"Signal 32"
};
E 1
