h26256
s 00011/00005/00061
d D 5.4 88/02/18 17:04:16 bostic 15 14
c written by Kurt Shoens; added Berkeley specific header
e
s 00008/00016/00058
d D 5.3 87/05/18 12:28:37 edward 14 13
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00073
d D 5.2 85/06/21 17:13:38 mckusick 13 12
c botched copyright
e
s 00007/00001/00067
d D 5.1 85/06/06 10:40:47 dist 12 11
c Add copyright
e
s 00002/00004/00066
d D 1.8 85/01/09 10:18:18 ralph 11 10
c use sigmask() macro
e
s 00004/00001/00066
d D 1.7 83/08/13 11:35:06 sam 10 8
c standardize sccs keyword lines
e
s 00004/00000/00067
d R 1.7 83/08/11 22:19:07 sam 9 8
c standardize sccs keyword lines
e
s 00008/00010/00059
d D 1.6 83/06/12 11:17:03 sam 8 7
c new signals
e
s 00003/00000/00066
d D 1.5 82/10/21 05:45:47 carl 7 6
c Null definition of sigchild() added if SIGRETRO is undefined.
e
s 00001/00000/00065
d D 1.4 82/07/26 17:10:33 kurt 6 5
c added call on sigchild() after fork() to fix retrofit signals 
c 
e
s 00000/00000/00065
d D 1.3 82/03/15 09:44:35 kurt 5 2
i 4 3
c Included Eric's branch changes to remove vax and vmunix 
c dependencies. 
c 
e
s 00011/00001/00054
d D 1.2.1.2 82/03/15 09:34:10 kurt 4 3
c Eric Allman's fixes to remove VAX and VMUNIX dependencies
e
s 00000/00000/00055
d D 1.2.1.1 82/03/15 09:26:59 kurt 3 2
c branch-place-holder
e
s 00007/00007/00048
d D 1.2 81/09/19 16:52:04 kurt 2 1
c changed pclose() to sighold/sigrelse instead of old signal jazz. 
c 
e
s 00055/00000/00000
d D 1.1 81/09/10 08:13:29 kurt 1 0
c date and time created 81/09/10 08:13:29 by kurt
e
u
U
f b 
f i 
t
T
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
D 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 15
 */

E 12
I 10
D 15
#ifndef lint
D 13
static char sccsid[] = "%W% (Berkeley) %G%";
E 13
I 13
static char *sccsid = "%W% (Berkeley) %G%";
E 13
D 12
#endif
E 12
I 12
#endif not lint
E 15
I 15
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 15
E 12

E 10
I 1
#include <stdio.h>
D 14
#include <signal.h>
E 14
I 14
#include <sys/signal.h>
#include <sys/types.h>
#include <sys/wait.h>
E 14
I 4
#include <errno.h>
I 14

E 14
E 4
#define	tst(a,b)	(*mode == 'r'? (b) : (a))
#define	RDR	0
#define	WTR	1
static	int	popen_pid[20];
D 10
static	char	*sccsid = "%W% %G%";
E 10

I 4
D 8
# ifndef VMUNIX
# define vfork	fork
# endif VMUNIX
E 8
I 8
D 11
#ifdef VMUNIX
#define	mask(s)	(1<<((s)-1))
#else
E 11
I 11
D 14
#ifndef VMUNIX
E 11
#define vfork	fork
#endif VMUNIX
E 8
I 7
#ifndef	SIGRETRO
#define	sigchild()
#endif
E 7

E 14
E 4
FILE *
popen(cmd,mode)
char	*cmd;
char	*mode;
{
	int p[2];
	register myside, hisside, pid;

	if(pipe(p) < 0)
		return NULL;
	myside = tst(p[WTR], p[RDR]);
	hisside = tst(p[RDR], p[WTR]);
	if((pid = vfork()) == 0) {
		/* myside and hisside reverse roles in child */
I 6
D 14
		sigchild();
E 14
E 6
		close(myside);
		dup2(hisside, tst(0, 1));
		close(hisside);
		execl("/bin/csh", "sh", "-c", cmd, 0);
		_exit(1);
	}
	if(pid == -1)
		return NULL;
	popen_pid[myside] = pid;
	close(hisside);
	return(fdopen(myside, mode));
}

pclose(ptr)
FILE *ptr;
{
D 2
	register f, r, (*hstat)(), (*istat)(), (*qstat)();
E 2
I 2
	register f, r;
E 2
D 8
	int status;
E 8
I 8
D 14
	int status, omask;
E 14
I 14
	int omask;
	union wait status;
E 14
E 8
I 4
	extern int errno;
E 4

	f = fileno(ptr);
	fclose(ptr);
I 4
D 14
# ifdef VMUNIX
E 14
E 4
D 2
	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
	hstat = signal(SIGHUP, SIG_IGN);
E 2
I 2
D 8
	sighold(SIGINT);
	sighold(SIGQUIT);
	sighold(SIGHUP);
E 8
I 8
D 11
	omask = sigblock(mask(SIGINT)|mask(SIGQUIT)|mask(SIGHUP));
E 11
I 11
	omask = sigblock(sigmask(SIGINT)|sigmask(SIGQUIT)|sigmask(SIGHUP));
E 11
E 8
E 2
D 4
	while((r = wait(&status)) != popen_pid[f] && r != -1)
E 4
I 4
D 14
# endif VMUNIX
E 14
	while((r = wait(&status)) != popen_pid[f] && r != -1 && errno != EINTR)
E 4
		;
	if(r == -1)
D 14
		status = -1;
I 4
# ifdef VMUNIX
E 14
I 14
		status.w_status = -1;
E 14
E 4
D 2
	signal(SIGINT, istat);
	signal(SIGQUIT, qstat);
	signal(SIGHUP, hstat);
E 2
I 2
D 8
	sigrelse(SIGINT);
	sigrelse(SIGQUIT);
	sigrelse(SIGHUP);
E 8
I 8
	sigsetmask(omask);
E 8
I 4
D 14
# endif VMUNIX
E 4
E 2
	return(status);
E 14
I 14
	return (status.w_status);
E 14
}
E 1
