h42873
s 00002/00001/00078
d D 5.5 87/09/30 12:18:02 bostic 12 11
c long/int bug; bug report 4.3BSD/lib/26
e
s 00000/00001/00079
d D 5.4 86/03/26 10:21:18 bloom 11 10
c param.h no longer needed
e
s 00002/00002/00078
d D 5.3 86/03/09 19:52:30 donn 10 9
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00071
d D 5.2 85/06/05 12:29:39 mckusick 9 8
c Add copyright
e
s 00000/00000/00072
d D 5.1 85/05/30 10:47:42 dist 8 7
c Add copyright
e
s 00020/00006/00052
d D 4.7 85/03/04 14:50:00 serge 7 6
c dynamically allocate process id array
e
s 00002/00001/00056
d D 4.6 84/11/10 18:23:18 lepreau 6 5
c use NOFILE from param.h
e
s 00021/00024/00036
d D 4.5 84/07/06 20:20:43 sam 5 4
c remove signal calls in favor of sigblock/sigsetmask
e
s 00004/00001/00056
d D 4.4 83/09/25 11:59:03 karels 4 3
c don't lose fd's if fork fails
e
s 00004/00002/00053
d D 4.3 83/08/18 16:50:32 sam 3 2
c bug fix from dlw: can't unconditionally close, must check if needed
e
s 00001/00001/00054
d D 4.2 82/11/14 14:08:44 sam 2 1
c vfork is on the way out, don't perpetuate binaries w/ sys call
e
s 00055/00000/00000
d D 4.1 80/12/21 16:50:45 wnj 1 0
c date and time created 80/12/21 16:50:45 by wnj
e
u
U
t
T
I 1
D 9
/* %W% (Berkeley) %G% */
E 9
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 10
#ifndef lint
E 10
I 10
#if defined(LIBC_SCCS) && !defined(lint)
E 10
static char sccsid[] = "%W% (Berkeley) %G%";
D 10
#endif not lint
E 10
I 10
#endif LIBC_SCCS and not lint
E 10
E 9
I 5

E 5
#include <stdio.h>
#include <signal.h>
I 6
D 11
#include <sys/param.h>
E 11
E 6
I 5

E 5
#define	tst(a,b)	(*mode == 'r'? (b) : (a))
#define	RDR	0
#define	WTR	1
D 5
static	int	popen_pid[20];
E 5

I 5
D 6
static	int popen_pid[20];
E 6
I 6
D 7
static	int popen_pid[NOFILE];
E 7
I 7
extern	char *malloc();
E 7
E 6

I 7
static	int *popen_pid;
static	int nfiles;

E 7
E 5
FILE *
popen(cmd,mode)
D 5
char	*cmd;
char	*mode;
E 5
I 5
	char *cmd;
	char *mode;
E 5
{
	int p[2];
D 5
	register myside, hisside, pid;
E 5
I 5
	int myside, hisside, pid;
E 5

I 7
	if (nfiles <= 0)
		nfiles = getdtablesize();
	if (popen_pid == NULL) {
		popen_pid = (int *)malloc(nfiles * sizeof *popen_pid);
		if (popen_pid == NULL)
			return (NULL);
		for (pid = 0; pid < nfiles; pid++)
			popen_pid[pid] = -1;
	}
E 7
D 5
	if(pipe(p) < 0)
		return NULL;
E 5
I 5
	if (pipe(p) < 0)
		return (NULL);
E 5
	myside = tst(p[WTR], p[RDR]);
	hisside = tst(p[RDR], p[WTR]);
D 2
	if((pid = vfork()) == 0) {
E 2
I 2
D 5
	if((pid = fork()) == 0) {
E 5
I 5
D 7
	if ((pid = fork()) == 0) {
E 7
I 7
	if ((pid = vfork()) == 0) {
E 7
E 5
E 2
		/* myside and hisside reverse roles in child */
		close(myside);
D 3
		dup2(hisside, tst(0, 1));
		close(hisside);
E 3
I 3
		if (hisside != tst(0, 1)) {
			dup2(hisside, tst(0, 1));
			close(hisside);
		}
E 3
D 7
		execl("/bin/sh", "sh", "-c", cmd, 0);
		_exit(1);
E 7
I 7
		execl("/bin/sh", "sh", "-c", cmd, (char *)NULL);
		_exit(127);
E 7
	}
D 4
	if(pid == -1)
E 4
I 4
D 5
	if(pid == -1) {
E 5
I 5
	if (pid == -1) {
E 5
		close(myside);
		close(hisside);
E 4
D 5
		return NULL;
E 5
I 5
		return (NULL);
E 5
I 4
	}
E 4
	popen_pid[myside] = pid;
	close(hisside);
D 5
	return(fdopen(myside, mode));
E 5
I 5
	return (fdopen(myside, mode));
E 5
}

pclose(ptr)
D 5
FILE *ptr;
E 5
I 5
	FILE *ptr;
E 5
{
D 5
	register f, r, (*hstat)(), (*istat)(), (*qstat)();
	int status;
E 5
I 5
D 12
	int child, pid, status, omask;
E 12
I 12
	long omask;
	int child, pid, status;
E 12
E 5

D 5
	f = fileno(ptr);
E 5
I 5
	child = popen_pid[fileno(ptr)];
I 7
	popen_pid[fileno(ptr)] = -1;
E 7
E 5
	fclose(ptr);
D 5
	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
	hstat = signal(SIGHUP, SIG_IGN);
	while((r = wait(&status)) != popen_pid[f] && r != -1)
E 5
I 5
D 7
#define	mask(s)	(1 << ((s)-1))
	omask = sigblock(mask(SIGINT)|mask(SIGQUIT)|mask(SIGHUP));
E 7
I 7
	if (child == -1)
		return (-1);
	omask = sigblock(sigmask(SIGINT)|sigmask(SIGQUIT)|sigmask(SIGHUP));
E 7
	while ((pid = wait(&status)) != child && pid != -1)
E 5
		;
D 5
	if(r == -1)
		status = -1;
	signal(SIGINT, istat);
	signal(SIGQUIT, qstat);
	signal(SIGHUP, hstat);
	return(status);
E 5
I 5
	(void) sigsetmask(omask);
	return (pid == -1 ? -1 : status);
E 5
}
E 1
