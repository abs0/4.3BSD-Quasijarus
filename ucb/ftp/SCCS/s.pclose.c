h42189
s 00050/00035/00041
d D 1.2 86/03/07 12:32:56 minshall 2 1
c Clean up for lint; change some stderr to stdout; bug fix
c (in ruserpass.c, routine rnetrc()).
e
s 00076/00000/00000
d D 1.1 86/02/03 15:22:23 minshall 1 0
c date and time created 86/02/03 15:22:23 by minshall
e
u
U
t
T
I 1
/*
D 2
 * Copyright (c) 1985 Regents of the University of California.
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
E 2
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

#include <stdio.h>
#include <signal.h>
I 2
#include <sys/param.h>
#include <sys/wait.h>

E 2
#define	tst(a,b)	(*mode == 'r'? (b) : (a))
#define	RDR	0
#define	WTR	1
D 2
static	int	popen_pid[20];
E 2

I 2
extern	char *malloc();

static	int *popen_pid;
static	int nfiles;

E 2
FILE *
D 2
popen(cmd,mode)
char	*cmd;
char	*mode;
E 2
I 2
mypopen(cmd,mode)
	char *cmd;
	char *mode;
E 2
{
	int p[2];
D 2
	register myside, hisside, pid;
E 2
I 2
	int myside, hisside, pid;
E 2

D 2
	if(pipe(p) < 0)
		return NULL;
E 2
I 2
	if (nfiles <= 0)
		nfiles = getdtablesize();
	if (popen_pid == NULL) {
		popen_pid = (int *)malloc((unsigned) nfiles * sizeof *popen_pid);
		if (popen_pid == NULL)
			return (NULL);
		for (pid = 0; pid < nfiles; pid++)
			popen_pid[pid] = -1;
	}
	if (pipe(p) < 0)
		return (NULL);
E 2
	myside = tst(p[WTR], p[RDR]);
	hisside = tst(p[RDR], p[WTR]);
D 2
	if((pid = fork()) == 0) {
E 2
I 2
	if ((pid = vfork()) == 0) {
E 2
		/* myside and hisside reverse roles in child */
D 2
		close(myside);
E 2
I 2
		(void) close(myside);
E 2
		if (hisside != tst(0, 1)) {
D 2
			dup2(hisside, tst(0, 1));
			close(hisside);
E 2
I 2
			(void) dup2(hisside, tst(0, 1));
			(void) close(hisside);
E 2
		}
D 2
		execl("/bin/sh", "sh", "-c", cmd, 0);
		_exit(1);
E 2
I 2
		execl("/bin/sh", "sh", "-c", cmd, (char *)NULL);
		_exit(127);
E 2
	}
D 2
	if(pid == -1) {
		close(myside);
		close(hisside);
		return NULL;
E 2
I 2
	if (pid == -1) {
		(void) close(myside);
		(void) close(hisside);
		return (NULL);
E 2
	}
	popen_pid[myside] = pid;
D 2
	close(hisside);
	return(fdopen(myside, mode));
E 2
I 2
	(void) close(hisside);
	return (fdopen(myside, mode));
E 2
}

pabort()
{
	extern int mflag;

	mflag = 0;
}

D 2
pclose(ptr)
FILE *ptr;
E 2
I 2
mypclose(ptr)
	FILE *ptr;
E 2
{
D 2
	register f, r, (*hstat)(), (*istat)(), (*qstat)();
	int status, pabort();
E 2
I 2
	int child, pid, omask, pabort(), (*istat)();
	union wait status;
E 2

D 2
	f = fileno(ptr);
	fclose(ptr);
E 2
I 2
	child = popen_pid[fileno(ptr)];
	popen_pid[fileno(ptr)] = -1;
	(void) fclose(ptr);
	if (child == -1)
		return (-1);
E 2
	istat = signal(SIGINT, pabort);
D 2
	qstat = signal(SIGQUIT, SIG_IGN);
	hstat = signal(SIGHUP, SIG_IGN);
	while((r = wait(&status)) != popen_pid[f] && r != -1)
E 2
I 2
	omask = sigblock(sigmask(SIGQUIT)|sigmask(SIGHUP));
	while ((pid = wait(&status)) != child && pid != -1)
E 2
		;
D 2
	if(r == -1)
		status = -1;
	signal(SIGINT, istat);
	signal(SIGQUIT, qstat);
	signal(SIGHUP, hstat);
	return(status);
E 2
I 2
	(void) sigsetmask(omask);
	(void) signal(SIGINT, istat);
	return (pid == -1 ? -1 : 0);
E 2
}
E 1
