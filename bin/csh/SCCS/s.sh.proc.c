h20808
s 00002/00002/01100
d D 5.10 88/05/19 15:39:01 bostic 27 26
c install C version of _doprnt
e
s 00002/00001/01100
d D 5.9 88/01/20 11:55:28 bostic 26 25
c Bug involving csh and the "source" command; 4.3BSD/bin/115
e
s 00003/00003/01098
d D 5.8 87/09/16 14:47:47 bostic 25 24
c use "Suspended", not "Stopped"; bug report 4.3BSD/bin/56
e
s 00001/00001/01100
d D 5.7 87/09/16 11:47:30 bostic 24 23
c non-interactive csh/children fix; bug report 4.3BSD/bin/42
e
s 00014/00009/01087
d D 5.6 87/06/25 09:15:20 bostic 23 22
c csh long/int mismatches; bug report 4.3BSD/bin/45
e
s 00006/00006/01090
d D 5.5 86/05/13 01:12:24 lepreau 22 21
c nice is absolute after all; allow killing with 0 as a signum and negative pids;
c fix botched code that suppresses SIGPIPE and SIGINT termiantion msgs (from
c glenn@sun).  Not sure he fixed it rgiht but it's a lot better than before.
e
s 00002/00001/01094
d D 5.4 86/01/12 02:34:05 lepreau 21 20
c nice is relative, not absolute. (Kirk "authorized" it.)
e
s 00001/00001/01094
d D 5.3 85/07/31 19:48:26 mckusick 20 19
c block SIGINTS while waiting for a kid (from ks@purdue)
e
s 00003/00003/01092
d D 5.2 85/06/06 13:08:48 edward 19 18
c cleaning up after bozos
e
s 00008/00002/01087
d D 5.1 85/06/04 11:06:58 dist 18 17
c Add copyright
e
s 00005/00001/01084
d D 4.17 85/03/19 18:40:03 mckusick 17 16
c boiler plate around killpg()
e
s 00016/00006/01069
d D 4.16 85/02/01 12:18:27 edward 16 15
c padds fixed to take care of && and ||
e
s 00043/00053/01032
d D 4.15 84/12/13 14:39:22 edward 15 14
c performance
e
s 00000/00005/01085
d D 4.14 84/11/21 11:25:29 ralph 14 13
c don't need to ignore SIGINT due to process groups.
e
s 00035/00045/01055
d D 4.13 84/08/31 09:31:02 ralph 13 12
c use new signal calls instead of compatibility routines.
e
s 00001/00001/01099
d D 4.12 83/07/01 23:28:25 wnj 12 11
c include fixes
e
s 00011/00006/01089
d D 4.11 83/07/01 03:57:46 sam 11 10
c fixes from wnj to allow job names to be globbed
e
s 00029/00040/01066
d D 4.10 83/06/11 16:49:45 sam 10 9
c different approach, try signal compatibility package
e
s 00040/00029/01066
d D 4.9 83/06/10 23:59:30 sam 9 8
c new signals; no libjobs; still loses SIGINT by getting it masked 
c sometimes, but we check it in before we lose something
e
s 00011/00008/01084
d D 4.8 83/02/03 09:12:55 sam 8 7
c use high precision time calls
e
s 00012/00037/01080
d D 4.7 82/12/30 17:35:28 sam 7 6
c finally works (updated for 4.1c and merged with sun)
e
s 00004/00001/01113
d D 4.6 81/05/03 19:52:00 root 6 5
c fix to way time is printed
e
s 00001/00001/01113
d D 4.5 81/04/05 22:15:28 root 5 4
c fixed up!
e
s 00007/00005/01107
d D 4.4 81/04/05 22:14:51 root 4 3
c really fixed
e
s 00009/00008/01103
d D 4.3 81/03/11 18:52:01 wnj 3 2
c minor bug fixes
e
s 00018/00012/01093
d D 4.2 81/02/07 12:16:15 wnj 2 1
c fixed job control bug, improved choice of + and - jobs
e
s 01105/00000/00000
d D 4.1 80/10/09 12:41:33 bill 1 0
c date and time created 80/10/09 12:41:33 by bill
e
u
U
t
T
I 18
/*
 * Copyright (c) 1980 Regents of the University of California.
D 19
 * All rights reserved.  The Berkeley software License Agreement
E 19
I 19
 * All rights reserved.  The Berkeley Software License Agreement
E 19
 * specifies the terms and conditions for redistribution.
 */

E 18
I 1
D 4
static	char *sccsid = "%Z%%M% %I% %G%";
E 4
I 4
D 5
static	char *sccsid = "@(#)sh.proc.c 4.4 3/31/81";
E 5
I 5
D 15
static	char *sccsid = "%W% (Berkeley) %E%";
E 15
I 15
#ifndef lint
D 18
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 18
I 18
D 19
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 19
I 19
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 19
E 18
E 15
E 5
E 4

#include "sh.h"
#include "sh.dir.h"
#include "sh.proc.h"
D 12
#include <wait.h>
E 12
I 12
#include <sys/wait.h>
E 12
#include <sys/ioctl.h>

/*
 * C Shell - functions that manage processes, handling hanging, termination
 */

#define BIGINDEX	9	/* largest desirable job index */

/*
 * pchild - called at interrupt level by the SIGCHLD signal
 *	indicating that at least one child has terminated or stopped
 *	thus at least one wait system call will definitely return a
 *	childs status.  Top level routines (like pwait) must be sure
 *	to mask interrupts when playing with the proclist data structures!
 */
pchild()
{
	register struct process *pp;
	register struct process	*fp;
	register int pid;
	union wait w;
	int jobflags;
D 7
#ifdef VMUNIX
	struct vtimes vt;
#endif
E 7
I 7
	struct rusage ru;
I 26
	extern int insource;
E 26
E 7

D 15
	if (!timesdone)
		timesdone++, times(&shtimes);
E 15
loop:
D 15
	pid = wait3(&w.w_status, (setintr ? WNOHANG|WUNTRACED:WNOHANG),
D 7
#ifndef VMUNIX
	    0);
#else
	    &vt);
#endif
E 7
I 7
	    &ru);
E 15
I 15
D 24
	pid = wait3(&w, (setintr ? WNOHANG|WUNTRACED:WNOHANG), &ru);
E 24
I 24
D 26
	pid = wait3(&w, ((setintr && intty) ? WNOHANG|WUNTRACED:WNOHANG), &ru);
E 26
I 26
	pid = wait3(&w, (setintr && (intty || insource) ? WNOHANG|WUNTRACED:WNOHANG), &ru);
E 26
E 24
E 15
E 7
	if (pid <= 0) {
		if (errno == EINTR) {
			errno = 0;
			goto loop;
		}
		pnoprocesses = pid == -1;
		return;
	}
	for (pp = proclist.p_next; pp != PNULL; pp = pp->p_next)
		if (pid == pp->p_pid)
			goto found;
	goto loop;
found:
	if (pid == atoi(value("child")))
		unsetv("child");
	pp->p_flags &= ~(PRUNNING|PSTOPPED|PREPORTED);
	if (WIFSTOPPED(w)) {
		pp->p_flags |= PSTOPPED;
		pp->p_reason = w.w_stopsig;
	} else {
D 15
		if (pp->p_flags & (PTIME|PPTIME) || adrof("time")) {
			time_t oldcutimes, oldcstimes;
			oldcutimes = shtimes.tms_cutime;
			oldcstimes = shtimes.tms_cstime;
D 8
			time(&pp->p_etime);
E 8
I 8
			gettimeofday(&pp->p_etime, (struct timezone *)0);
E 8
			times(&shtimes);
			pp->p_utime = shtimes.tms_cutime - oldcutimes;
			pp->p_stime = shtimes.tms_cstime - oldcstimes;
		} else
			times(&shtimes);
E 15
I 15
		if (pp->p_flags & (PTIME|PPTIME) || adrof("time"))
			(void) gettimeofday(&pp->p_etime, (struct timezone *)0);
E 15
D 7
#ifdef VMUNIX
		pp->p_vtimes = vt;
#endif
E 7
I 7
		pp->p_rusage = ru;
E 7
		if (WIFSIGNALED(w)) {
			if (w.w_termsig == SIGINT)
				pp->p_flags |= PINTERRUPTED;
			else
				pp->p_flags |= PSIGNALED;
			if (w.w_coredump)
				pp->p_flags |= PDUMPED;
			pp->p_reason = w.w_termsig;
		} else {
			pp->p_reason = w.w_retcode;
D 7
#ifdef IIASA
			if (pp->p_reason >= 3)
#else
E 7
			if (pp->p_reason != 0)
D 7
#endif
E 7
				pp->p_flags |= PAEXITED;
			else
				pp->p_flags |= PNEXITED;
		}
	}
	jobflags = 0;
	fp = pp;
	do {
		if ((fp->p_flags & (PPTIME|PRUNNING|PSTOPPED)) == 0 &&
		    !child && adrof("time") &&
D 15
		    (fp->p_utime + fp->p_stime) / HZ >=
E 15
I 15
		    fp->p_rusage.ru_utime.tv_sec+fp->p_rusage.ru_stime.tv_sec >=
E 15
		     atoi(value("time")))
			fp->p_flags |= PTIME;
		jobflags |= fp->p_flags;
	} while ((fp = fp->p_friends) != pp);
	pp->p_flags &= ~PFOREGND;
	if (pp == pp->p_friends && (pp->p_flags & PPTIME)) {
		pp->p_flags &= ~PPTIME;
		pp->p_flags |= PTIME;
	}
	if ((jobflags & (PRUNNING|PREPORTED)) == 0) {
		fp = pp;
		do {
			if (fp->p_flags&PSTOPPED)
				fp->p_flags |= PREPORTED;
		} while((fp = fp->p_friends) != pp);
		while(fp->p_pid != fp->p_jobid)
			fp = fp->p_friends;
I 2
		if (jobflags&PSTOPPED) {
			if (pcurrent && pcurrent != fp)
				pprevious = pcurrent;
			pcurrent = fp;
		} else
			pclrcurr(fp);
E 2
		if (jobflags&PFOREGND) {
D 2
			if (jobflags&PSTOPPED) {
				if (pcurrent && pcurrent != fp)
					pprevious = pcurrent;
				pcurrent = fp;
			} else
				pclrcurr(fp);
E 2
			if (jobflags & (PSIGNALED|PSTOPPED|PPTIME) ||
#ifdef IIASA
			    jobflags & PAEXITED ||
#endif
			    !eq(dcwd->di_name, fp->p_cwd->di_name)) {
D 3
				if (jobflags & PSTOPPED)
					printf("\n");
				pprint(fp, AREASON|SHELLDIR);
E 3
I 3
				;	/* print in pjwait */
E 3
D 6
			} else if ((jobflags & (PTIME|PSTOPPED)) == PTIME)
E 6
I 6
			}
/*
		else if ((jobflags & (PTIME|PSTOPPED)) == PTIME)
E 6
				ptprint(fp);
I 6
*/
E 6
		} else {
			if (jobflags&PNOTIFY || adrof("notify")) {
				printf("\215\n");
D 15
				pprint(pp, NUMBER|NAME|REASON);
E 15
I 15
				(void) pprint(pp, NUMBER|NAME|REASON);
E 15
				if ((jobflags&PSTOPPED) == 0)
					pflush(pp);
			} else {
D 2
				if ((jobflags&PSTOPPED) == 0)
					pclrcurr(fp);
E 2
				fp->p_flags |= PNEEDNOTE;
				neednote++;
			}
		}
	}
	goto loop;
}

pnote()
{
	register struct process *pp;
D 13
	int flags;
E 13
I 13
D 23
	int flags, omask;
E 23
I 23
	int flags;
	long omask;
E 23
E 13

	neednote = 0;
	for (pp = proclist.p_next; pp != PNULL; pp = pp->p_next) {
		if (pp->p_flags & PNEEDNOTE) {
D 9
			sighold(SIGCHLD);
E 9
I 9
D 10
			(void) sigblock(mask(SIGCHLD));
E 10
I 10
D 13
			sighold(SIGCHLD);
E 13
I 13
			omask = sigblock(sigmask(SIGCHLD));
E 13
E 10
E 9
			pp->p_flags &= ~PNEEDNOTE;
			flags = pprint(pp, NUMBER|NAME|REASON);
			if ((flags&(PRUNNING|PSTOPPED)) == 0)
				pflush(pp);
D 9
			sigrelse(SIGCHLD);
E 9
I 9
D 10
			(void) sigrelse(mask(SIGCHLD));
E 10
I 10
D 13
			sigrelse(SIGCHLD);
E 13
I 13
D 15
			sigsetmask(omask);
E 15
I 15
			(void) sigsetmask(omask);
E 15
E 13
E 10
E 9
		}
	}
}

/*
 * pwait - wait for current job to terminate, maintaining integrity
 *	of current and previous job indicators.
 */
pwait()
{
	register struct process *fp, *pp;
I 13
D 23
	int omask;
E 23
I 23
	long omask;
E 23
E 13

	/*
	 * Here's where dead procs get flushed.
	 */
D 9
	sighold(SIGCHLD);
E 9
I 9
D 10
	(void) sigblock(mask(SIGCHLD));
E 10
I 10
D 13
	sighold(SIGCHLD);
E 13
I 13
	omask = sigblock(sigmask(SIGCHLD));
E 13
E 10
E 9
	for (pp = (fp = &proclist)->p_next; pp != PNULL; pp = (fp = pp)->p_next)
		if (pp->p_pid == 0) {
			fp->p_next = pp->p_next;
			xfree(pp->p_command);
			if (pp->p_cwd && --pp->p_cwd->di_count == 0)
				if (pp->p_cwd->di_next == 0)
					dfree(pp->p_cwd);
			xfree((char *)pp);
			pp = fp;
		}
D 9
	sigrelse(SIGCHLD);
E 9
I 9
D 10
	(void) sigrelse(mask(SIGCHLD));
#ifdef notdef
E 10
I 10
D 13
	sigrelse(SIGCHLD);
E 10
E 9
	if (setintr)
D 9
		sigignore(SIGINT);
E 9
I 9
D 10
		signal(SIGINT, SIG_IGN);
#endif
E 10
I 10
		sigignore(SIGINT);
E 13
I 13
D 15
	sigsetmask(omask);
E 15
I 15
	(void) sigsetmask(omask);
E 15
E 13
E 10
E 9
	pjwait(pcurrjob);
}

/*
 * pjwait - wait for a job to finish or become stopped
 *	It is assumed to be in the foreground state (PFOREGND)
 */
pjwait(pp)
	register struct process *pp;
{
	register struct process *fp;
D 9
	int jobflags, reason;
E 9
I 9
D 10
	int jobflags, reason, omask;
E 10
I 10
D 13
	int jobflags, reason;
E 13
I 13
D 23
	int jobflags, reason, omask;
E 23
I 23
	int jobflags, reason;
	long omask;
E 23
D 15
	int (*old)();
E 15
E 13
E 10
E 9

I 13
D 14
	if (setintr)
		old = signal(SIGINT, SIG_IGN);

E 14
E 13
I 11
	while (pp->p_pid != pp->p_jobid)
		pp = pp->p_friends;
E 11
	fp = pp;
	do {
		if ((fp->p_flags&(PFOREGND|PRUNNING)) == PRUNNING)
			printf("BUG: waiting for background job!\n");
	} while ((fp = fp->p_friends) != pp);
	/*
	 * Now keep pausing as long as we are not interrupted (SIGINT),
	 * and the target process, or any of its friends, are running
	 */
	fp = pp;
I 13
	omask = sigblock(sigmask(SIGCHLD));
E 13
I 9
D 10
	omask = sigblock(mask(SIGCHLD));
E 10
E 9
	for (;;) {
I 10
D 13
		sighold(SIGCHLD);
E 13
E 10
D 9
		sighold(SIGCHLD);
E 9
		jobflags = 0;
		do
			jobflags |= fp->p_flags;
D 13
		while((fp = (fp->p_friends)) != pp);
E 13
I 13
		while ((fp = (fp->p_friends)) != pp);
E 13
		if ((jobflags & PRUNNING) == 0)
			break;
D 9
		sigpause(SIGCHLD);
E 9
I 9
D 10
		sigpause(omask &~ mask(SIGCHLD));
E 10
I 10
D 13
		sigpause(sigblock(0) &~ mask(SIGCHLD));
E 13
I 13
D 20
		sigpause(0);
E 20
I 20
D 23
		sigpause(sigblock(0) &~ sigmask(SIGCHLD));
E 23
I 23
		sigpause(sigblock(0L) &~ sigmask(SIGCHLD));
E 23
E 20
E 13
E 10
E 9
	}
D 9
	sigrelse(SIGCHLD);
E 9
I 9
D 10
	sigsetmask(omask);
E 10
I 10
D 13
	sigrelse(SIGCHLD);
E 13
I 13
D 15
	sigsetmask(omask);
E 13
E 10
E 9
	if (tpgrp > 0)
		ioctl(FSHTTY, TIOCSPGRP, &tpgrp);	/* get tty back */
E 15
I 15
	(void) sigsetmask(omask);
	if (tpgrp > 0)			/* get tty back */
		(void) ioctl(FSHTTY, TIOCSPGRP, (char *)&tpgrp);
E 15
I 4
	if ((jobflags&(PSIGNALED|PSTOPPED|PTIME)) ||
	     !eq(dcwd->di_name, fp->p_cwd->di_name)) {
		if (jobflags&PSTOPPED)
			printf("\n");
D 15
		pprint(pp, AREASON|SHELLDIR);
E 15
I 15
		(void) pprint(pp, AREASON|SHELLDIR);
E 15
	}
E 4
D 3
	if (jobflags & PSTOPPED)
		return;
	if ((jobflags&PINTERRUPTED) && setintr &&
E 3
I 3
	if ((jobflags&(PINTERRUPTED|PSTOPPED)) && setintr &&
E 3
	    (!gointr || !eq(gointr, "-"))) {
D 3
		pflush(pp);
		pintr();
E 3
I 3
		if ((jobflags & PSTOPPED) == 0)
			pflush(pp);
D 4
		else {
			printf("\n");
			pprint(pp, AREASON|SHELLDIR);
		}
E 4
		pintr1(0);
E 3
		/*NOTREACHED*/
	}
	reason = 0;
	fp = pp;
	do {
		if (fp->p_reason)
			reason = fp->p_flags & (PSIGNALED|PINTERRUPTED) ?
				fp->p_reason | QUOTE : fp->p_reason;
	} while ((fp = fp->p_friends) != pp);
	set("status", putn(reason));
	if (reason && exiterr)
		exitstat();
	pflush(pp);
I 13
D 14
	if (setintr)
		signal(SIGINT, old);
E 14
E 13
}

/*
 * dowait - wait for all processes to finish
 */
dowait()
{
	register struct process *pp;
I 13
D 23
	int omask;
E 23
I 23
	long omask;
E 23
E 13
I 9
D 10
	int omask;
E 10
E 9

	pjobs++;
D 13
	if (setintr)
D 9
		sigrelse(SIGINT);
E 9
I 9
D 10
		(void) sigrelse(mask(SIGINT));
	omask = sigblock(mask(SIGCHLD));
E 10
I 10
		sigrelse(SIGINT);
E 13
I 13
	omask = sigblock(sigmask(SIGCHLD));
E 13
E 10
E 9
loop:
I 10
D 13
	sighold(SIGCHLD);
E 13
E 10
D 9
	sighold(SIGCHLD);
E 9
	for (pp = proclist.p_next; pp; pp = pp->p_next)
D 11
		if (pp->p_pid && pp->p_pid == pp->p_jobid &&
E 11
I 11
		if (pp->p_pid && /* pp->p_pid == pp->p_jobid && */
E 11
		    pp->p_flags&PRUNNING) {
D 9
			sigpause(SIGCHLD);
E 9
I 9
D 10
			sigpause(omask &~ mask(SIGCHLD));
E 10
I 10
D 13
			sigpause(sigblock(0) &~ mask(SIGCHLD));
E 13
I 13
D 23
			sigpause(0);
E 23
I 23
			sigpause(0L);
E 23
E 13
E 10
E 9
			goto loop;
		}
D 9
	sigrelse(SIGCHLD);
E 9
I 9
D 10
	sigsetmask(omask);
E 10
I 10
D 13
	sigrelse(SIGCHLD);
E 13
I 13
D 15
	sigsetmask(omask);
E 15
I 15
	(void) sigsetmask(omask);
E 15
E 13
E 10
E 9
	pjobs = 0;
}

/*
 * pflushall - flush all jobs from list (e.g. at fork())
 */
pflushall()
{
	register struct process	*pp;

	for (pp = proclist.p_next; pp != PNULL; pp = pp->p_next)
		if (pp->p_pid)
			pflush(pp);
}

/*
 * pflush - flag all process structures in the same job as the
 *	the argument process for deletion.  The actual free of the
 *	space is not done here since pflush is called at interrupt level.
 */
pflush(pp)
	register struct process	*pp;
{
	register struct process *np;
	register int index;

	if (pp->p_pid == 0) {
		printf("BUG: process flushed twice");
		return;
	}
	while (pp->p_pid != pp->p_jobid)
		pp = pp->p_friends;
	pclrcurr(pp);
	if (pp == pcurrjob)
		pcurrjob = 0;
	index = pp->p_index;
	np = pp;
	do {
		np->p_index = np->p_pid = 0;
		np->p_flags &= ~PNEEDNOTE;
	} while ((np = np->p_friends) != pp);
	if (index == pmaxindex) {
		for (np = proclist.p_next, index = 0; np; np = np->p_next)
			if (np->p_index > index)
				index = np->p_index;
		pmaxindex = index;
	}
}

/*
 * pclrcurr - make sure the given job is not the current or previous job;
 *	pp MUST be the job leader
 */
pclrcurr(pp)
	register struct process *pp;
{

	if (pp == pcurrent)
		if (pprevious != PNULL) {
			pcurrent = pprevious;
			pprevious = pgetcurr(pp);
		} else {
			pcurrent = pgetcurr(pp);
			pprevious = pgetcurr(pp);
		}
	else if (pp == pprevious)
		pprevious = pgetcurr(pp);
}

/* +4 here is 1 for '\0', 1 ea for << >& >> */
char	command[PMAXLEN+4];
int	cmdlen;
char	*cmdp;
/*
 * palloc - allocate a process structure and fill it up.
 *	an important assumption is made that the process is running.
 */
palloc(pid, t)
	int pid;
	register struct command *t;
{
	register struct process	*pp;
	int i;

	pp = (struct process *)calloc(1, sizeof(struct process));
	pp->p_pid = pid;
	pp->p_flags = t->t_dflg & FAND ? PRUNNING : PRUNNING|PFOREGND;
	if (t->t_dflg & FTIME)
		pp->p_flags |= PPTIME;
	cmdp = command;
	cmdlen = 0;
	padd(t);
	*cmdp++ = 0;
	if (t->t_dflg & FPOU) {
		pp->p_flags |= PPOU;
		if (t->t_dflg & FDIAG)
			pp->p_flags |= PDIAG;
	}
	pp->p_command = savestr(command);
	if (pcurrjob) {
		struct process *fp;
		/* careful here with interrupt level */
		pp->p_cwd = 0;
		pp->p_index = pcurrjob->p_index;
		pp->p_friends = pcurrjob;
		pp->p_jobid = pcurrjob->p_pid;
		for (fp = pcurrjob; fp->p_friends != pcurrjob; fp = fp->p_friends)
			;
		fp->p_friends = pp;
	} else {
		pcurrjob = pp;
		pp->p_jobid = pid;
		pp->p_friends = pp;
		pp->p_cwd = dcwd;
		dcwd->di_count++;
		if (pmaxindex < BIGINDEX)
			pp->p_index = ++pmaxindex;
		else {
			struct process *np;

			for (i = 1; ; i++) {
				for (np = proclist.p_next; np; np = np->p_next)
					if (np->p_index == i)
						goto tryagain;
D 2
				pmaxindex = pp->p_index = i;
E 2
I 2
				pp->p_index = i;
				if (i > pmaxindex)
					pmaxindex = i;
E 2
				break;			
			tryagain:;
			}
		}
		if (pcurrent == PNULL)
			pcurrent = pp;
		else if (pprevious == PNULL)
			pprevious = pp;
	}
	pp->p_next = proclist.p_next;
	proclist.p_next = pp;
D 8
	time(&pp->p_btime);
E 8
I 8
D 15
	gettimeofday(&pp->p_btime, (struct timezone *)0);
E 15
I 15
	(void) gettimeofday(&pp->p_btime, (struct timezone *)0);
E 15
E 8
}

padd(t)
	register struct command *t;
{
	char **argp;

	if (t == 0)
		return;
	switch (t->t_dtyp) {

	case TPAR:
		pads("( ");
		padd(t->t_dspr);
		pads(" )");
		break;

	case TCOM:
		for (argp = t->t_dcom; *argp; argp++) {
			pads(*argp);
			if (argp[1])
				pads(" ");
		}
		break;

I 16
	case TOR:
	case TAND:
E 16
	case TFIL:
D 16
		padd(t->t_dcar);
		pads(" | ");
		padd(t->t_dcdr);
		return;

E 16
	case TLST:
		padd(t->t_dcar);
D 16
		pads("; ");
E 16
I 16
		switch (t->t_dtyp) {
		case TOR:
			pads(" || ");
			break;
		case TAND:
			pads(" && ");
			break;
		case TFIL:
			pads(" | ");
			break;
		case TLST:
			pads("; ");
			break;
		}
E 16
		padd(t->t_dcdr);
		return;
	}
	if ((t->t_dflg & FPIN) == 0 && t->t_dlef) {
		pads((t->t_dflg & FHERE) ? " << " : " < ");
		pads(t->t_dlef);
	}
	if ((t->t_dflg & FPOU) == 0 && t->t_drit) {
		pads((t->t_dflg & FCAT) ? " >>" : " >");
		if (t->t_dflg & FDIAG)
			pads("&");
		pads(" ");
		pads(t->t_drit);
	}
}

pads(cp)
	char *cp;
{
	register int i = strlen(cp);

	if (cmdlen >= PMAXLEN)
		return;
	if (cmdlen + i >= PMAXLEN) {
D 15
		strcpy(cmdp, " ...");
E 15
I 15
		(void) strcpy(cmdp, " ...");
E 15
		cmdlen = PMAXLEN;
		cmdp += 4;
		return;
	}
D 15
	strcpy(cmdp, cp);
E 15
I 15
	(void) strcpy(cmdp, cp);
E 15
	cmdp += i;
	cmdlen += i;
}

/*
 * psavejob - temporarily save the current job on a one level stack
 *	so another job can be created.  Used for { } in exp6
 *	and `` in globbing.
 */
psavejob()
{

	pholdjob = pcurrjob;
	pcurrjob = PNULL;
}

/*
 * prestjob - opposite of psavejob.  This may be missed if we are interrupted
 *	somewhere, but pendjob cleans up anyway.
 */
prestjob()
{

	pcurrjob = pholdjob;
	pholdjob = PNULL;
}

/*
 * pendjob - indicate that a job (set of commands) has been completed
 *	or is about to begin.
 */
pendjob()
{
	register struct process *pp, *tp;

	if (pcurrjob && (pcurrjob->p_flags&(PFOREGND|PSTOPPED)) == 0) {
		pp = pcurrjob;
		while (pp->p_pid != pp->p_jobid)
			pp = pp->p_friends;
		printf("[%d]", pp->p_index);
		tp = pp;
		do {
			printf(" %d", pp->p_pid);
			pp = pp->p_friends;
		} while (pp != tp);
		printf("\n");
	}
	pholdjob = pcurrjob = 0;
}

/*
 * pprint - print a job
 */
pprint(pp, flag)
	register struct process	*pp;
{
	register status, reason;
	struct process *tp;
	extern char *linp, linbuf[];
	int jobflags, pstatus;
	char *format;

	while (pp->p_pid != pp->p_jobid)
		pp = pp->p_friends;
	if (pp == pp->p_friends && (pp->p_flags & PPTIME)) {
		pp->p_flags &= ~PPTIME;
		pp->p_flags |= PTIME;
	}
	tp = pp;
	status = reason = -1; 
	jobflags = 0;
	do {
		jobflags |= pp->p_flags;
		pstatus = pp->p_flags & PALLSTATES;
		if (tp != pp && linp != linbuf && !(flag&FANCY) &&
		    (pstatus == status && pp->p_reason == reason ||
		     !(flag&REASON)))
			printf(" ");
		else {
			if (tp != pp && linp != linbuf)
				printf("\n");
			if(flag&NUMBER)
				if (pp == tp)
					printf("[%d]%s %c ", pp->p_index,
					    pp->p_index < 10 ? " " : "",
					    pp==pcurrent ? '+' :
						(pp == pprevious ? '-' : ' '));
				else
					printf("       ");
			if (flag&FANCY)
				printf("%5d ", pp->p_pid);
			if (flag&(REASON|AREASON)) {
				if (flag&NAME)
D 25
					format = "%-21s";
E 25
I 25
					format = "%-23s";
E 25
				else
					format = "%s";
				if (pstatus == status)
					if (pp->p_reason == reason) {
						printf(format, "");
						goto prcomd;
					} else
						reason = pp->p_reason;
				else {
					status = pstatus;
					reason = pp->p_reason;
				}
				switch (status) {

				case PRUNNING:
					printf(format, "Running ");
					break;

				case PINTERRUPTED:
				case PSTOPPED:
				case PSIGNALED:
D 22
					if (flag&REASON || reason != SIGINT ||
					    reason != SIGPIPE)
E 22
I 22
					if ((flag&(REASON|AREASON))
					    && reason != SIGINT
					    && reason != SIGPIPE)
E 22
						printf(format, mesg[pp->p_reason].pname);
					break;

				case PNEXITED:
				case PAEXITED:
					if (flag & REASON)
						if (pp->p_reason)
							printf("Exit %-16d", pp->p_reason);
						else
							printf(format, "Done");
					break;

				default:
					printf("BUG: status=%-9o", status);
				}
			}
		}
prcomd:
		if (flag&NAME) {
			printf("%s", pp->p_command);
			if (pp->p_flags & PPOU)
				printf(" |");
			if (pp->p_flags & PDIAG)
				printf("&");
		}
		if (flag&(REASON|AREASON) && pp->p_flags&PDUMPED)
			printf(" (core dumped)");
		if (tp == pp->p_friends) {
			if (flag&AMPERSAND)
				printf(" &");
			if (flag&JOBDIR &&
			    !eq(tp->p_cwd->di_name, dcwd->di_name)) {
				printf(" (wd: ");
				dtildepr(value("home"), tp->p_cwd->di_name);
				printf(")");
			}
		}
		if (pp->p_flags&PPTIME && !(status&(PSTOPPED|PRUNNING))) {
			if (linp != linbuf)
				printf("\n\t");
D 7
#ifndef VMUNIX
			ptimes(pp->p_utime, pp->p_stime, pp->p_etime-pp->p_btime);
#else
			pvtimes(&zvms, &pp->p_vtimes, pp->p_etime - pp->p_btime);
#endif
E 7
I 7
			{ static struct rusage zru;
D 8
			  prusage(&zru, &pp->p_rusage,
			      pp->p_etime - pp->p_btime);
E 8
I 8
			  prusage(&zru, &pp->p_rusage, &pp->p_etime,
			    &pp->p_btime);
E 8
			}
E 7
		}
		if (tp == pp->p_friends) {
			if (linp != linbuf)
				printf("\n");
			if (flag&SHELLDIR && !eq(tp->p_cwd->di_name, dcwd->di_name)) {
				printf("(wd now: ");
				dtildepr(value("home"), dcwd->di_name);
				printf(")\n");
			}
		}
	} while ((pp = pp->p_friends) != tp);
	if (jobflags&PTIME && (jobflags&(PSTOPPED|PRUNNING)) == 0) {
		if (jobflags & NUMBER)
			printf("       ");
		ptprint(tp);
	}
	return (jobflags);
}

ptprint(tp)
	register struct process *tp;
{
D 8
	time_t tetime = 0;
E 8
I 8
	struct timeval tetime, diff;
	static struct timeval ztime;
E 8
D 7
#ifdef VMUNIX
	struct vtimes vmt;
#else
	time_t tutime = 0, tstime = 0;
#endif
E 7
I 7
	struct rusage ru;
	static struct rusage zru;
E 7
	register struct process *pp = tp;

D 7
	vmt = zvms;
E 7
I 7
	ru = zru;
I 8
	tetime = ztime;
E 8
E 7
	do {
D 7
#ifdef VMUNIX
		vmsadd(&vmt, &pp->p_vtimes);
#else
		tutime += pp->p_utime;
		tstime += pp->p_stime;
#endif
E 7
I 7
		ruadd(&ru, &pp->p_rusage);
E 7
D 8
		if (pp->p_etime - pp->p_btime > tetime)
			tetime = pp->p_etime - pp->p_btime;
E 8
I 8
		tvsub(&diff, &pp->p_etime, &pp->p_btime);
		if (timercmp(&diff, &tetime, >))
			tetime = diff;
E 8
	} while ((pp = pp->p_friends) != tp);
D 7
#ifdef VMUNIX
	pvtimes(&zvms, &vmt, tetime);
#else
	ptimes(tutime, tstime, tetime);
#endif
E 7
I 7
D 8
	prusage(&zru, &ru, tetime);
E 8
I 8
	prusage(&zru, &ru, &tetime, &ztime);
E 8
E 7
}

/*
 * dojobs - print all jobs
 */
dojobs(v)
	char **v;
{
	register struct process *pp;
	register int flag = NUMBER|NAME|REASON;
	int i;

	if (chkstop)
		chkstop = 2;
	if (*++v) {
		if (v[1] || !eq(*v, "-l"))
			error("Usage: jobs [ -l ]");
		flag |= FANCY|JOBDIR;
	}
	for (i = 1; i <= pmaxindex; i++)
		for (pp = proclist.p_next; pp; pp = pp->p_next)
			if (pp->p_index == i && pp->p_pid == pp->p_jobid) {
				pp->p_flags &= ~PNEEDNOTE;
				if (!(pprint(pp, flag) & (PRUNNING|PSTOPPED)))
					pflush(pp);
				break;
			}
}

/*
 * dofg - builtin - put the job into the foreground
 */
dofg(v)
	char **v;
{
	register struct process *pp;

	okpcntl();
	++v;
	do {
		pp = pfind(*v);
		pstart(pp, 1);
D 13
		if (setintr)
D 9
			sigignore(SIGINT);
E 9
I 9
D 10
			signal(SIGINT, SIG_IGN);
E 10
I 10
			sigignore(SIGINT);
E 13
E 10
E 9
		pjwait(pp);
	} while (*v && *++v);
}

/*
 * %... - builtin - put the job into the foreground
 */
dofg1(v)
	char **v;
{
	register struct process *pp;

	okpcntl();
	pp = pfind(v[0]);
	pstart(pp, 1);
D 13
	if (setintr)
D 9
		sigignore(SIGINT);
E 9
I 9
D 10
		signal(SIGINT, SIG_IGN);
E 10
I 10
		sigignore(SIGINT);
E 13
E 10
E 9
	pjwait(pp);
}

/*
 * dobg - builtin - put the job into the background
 */
dobg(v)
	char **v;
{
	register struct process *pp;

	okpcntl();
	++v;
	do {
		pp = pfind(*v);
		pstart(pp, 0);
	} while (*v && *++v);
}

/*
 * %... & - builtin - put the job into the background
 */
dobg1(v)
	char **v;
{
	register struct process *pp;

	pp = pfind(v[0]);
	pstart(pp, 0);
}

/*
 * dostop - builtin - stop the job
 */
dostop(v)
	char **v;
{

	pkill(++v, SIGSTOP);
}

/*
 * dokill - builtin - superset of kill (1)
 */
dokill(v)
	char **v;
{
	register int signum;
	register char *name;

	v++;
	if (v[0] && v[0][0] == '-') {
		if (v[0][1] == 'l') {
			for (signum = 1; signum <= NSIG; signum++) {
				if (name = mesg[signum].iname)
					printf("%s ", name);
				if (signum == 16)
D 15
					printf("\n");
E 15
I 15
D 27
					putchar('\n');
E 27
I 27
					cshputchar('\n');
E 27
E 15
			}
D 15
			printf("\n");
E 15
I 15
D 27
			putchar('\n');
E 27
I 27
			cshputchar('\n');
E 27
E 15
			return;
		}
		if (digit(v[0][1])) {
			signum = atoi(v[0]+1);
D 22
			if (signum < 1 || signum > NSIG)
E 22
I 22
			if (signum < 0 || signum > NSIG)
E 22
				bferr("Bad signal number");
		} else {
			name = &v[0][1];
			for (signum = 1; signum <= NSIG; signum++)
			if (mesg[signum].iname &&
			    eq(name, mesg[signum].iname))
				goto gotsig;
			setname(name);
			bferr("Unknown signal; kill -l lists signals");
		}
gotsig:
		v++;
	} else
		signum = SIGTERM;
	pkill(v, signum);
}

pkill(v, signum)
	char **v;
	int signum;
{
	register struct process *pp, *np;
	register int jobflags = 0;
D 13
	int pid;
E 13
I 13
D 23
	int omask, pid, err = 0;
E 23
I 23
	int pid, err = 0;
	long omask;
E 23
E 13
I 11
	char *cp;
E 11
	extern char *sys_errlist[];
D 9
	int err = 0;
E 9
I 9
D 10
	int err = 0, omask = 0;
E 10
I 10
D 13
	int err = 0;
E 13
E 10
E 9

I 13
	omask = sigmask(SIGCHLD);
E 13
	if (setintr)
D 9
		sighold(SIGINT);
	sighold(SIGCHLD);
E 9
I 9
D 10
		omask |= mask(SIGINT);
	omask |= mask(SIGCHLD);
	omask = sigblock(omask);
E 10
I 10
D 13
		sighold(SIGINT);
	sighold(SIGCHLD);
E 13
I 13
		omask |= sigmask(SIGINT);
	omask = sigblock(omask) & ~omask;
E 13
E 10
E 9
	while (*v) {
D 11
		if (**v == '%') {
			np = pp = pfind(*v);
E 11
I 11
		cp = globone(*v);
		if (*cp == '%') {
			np = pp = pfind(cp);
E 11
			do
				jobflags |= np->p_flags;
			while ((np = np->p_friends) != pp);
			switch (signum) {

			case SIGSTOP:
			case SIGTSTP:
			case SIGTTIN:
			case SIGTTOU:
				if ((jobflags & PRUNNING) == 0) {
D 11
					printf("%s: Already stopped\n", *v);
E 11
I 11
D 25
					printf("%s: Already stopped\n", cp);
E 25
I 25
					printf("%s: Already suspended\n", cp);
E 25
E 11
					err++;
					goto cont;
				}
			}
D 15
			killpg(pp->p_jobid, signum);
E 15
I 15
D 17
			(void) killpg(pp->p_jobid, signum);
E 17
I 17
			if (killpg(pp->p_jobid, signum) < 0) {
				printf("%s: ", cp);
				printf("%s\n", sys_errlist[errno]);
				err++;
			}
E 17
E 15
			if (signum == SIGTERM || signum == SIGHUP)
D 15
				killpg(pp->p_jobid, SIGCONT);
E 15
I 15
				(void) killpg(pp->p_jobid, SIGCONT);
E 15
D 11
		} else if (!digit(**v))
E 11
I 11
D 22
		} else if (!digit(*cp))
E 22
I 22
		} else if (!(digit(*cp) || *cp == '-'))
E 22
E 11
			bferr("Arguments should be jobs or process id's");
		else {
D 11
			pid = atoi(*v);
E 11
I 11
			pid = atoi(cp);
E 11
			if (kill(pid, signum) < 0) {
				printf("%d: ", pid);
				printf("%s\n", sys_errlist[errno]);
				err++;
				goto cont;
			}
			if (signum == SIGTERM || signum == SIGHUP)
D 15
				kill(pid, SIGCONT);
E 15
I 15
				(void) kill(pid, SIGCONT);
E 15
		}
cont:
I 11
		xfree(cp);
E 11
		v++;
	}
D 9
	sigrelse(SIGCHLD);
	if (setintr)
		sigrelse(SIGINT);
E 9
I 9
D 10
	sigsetmask(omask);
E 10
I 10
D 13
	sigrelse(SIGCHLD);
	if (setintr)
		sigrelse(SIGINT);
E 13
I 13
D 15
	sigsetmask(omask);
E 15
I 15
	(void) sigsetmask(omask);
E 15
E 13
E 10
E 9
	if (err)
		error(NOSTR);
}

/*
 * pstart - start the job in foreground/background
 */
pstart(pp, foregnd)
	register struct process *pp;
	int foregnd;
{
	register struct process *np;
D 13
	int jobflags = 0;
E 13
I 13
D 23
	int omask, jobflags = 0;
E 23
I 23
	int jobflags = 0;
	long omask;
E 23
E 13

D 9
	sighold(SIGCHLD);
E 9
I 9
D 10
	(void) sigblock(mask(SIGCHLD));
E 10
I 10
D 13
	sighold(SIGCHLD);
E 13
I 13
	omask = sigblock(sigmask(SIGCHLD));
E 13
E 10
E 9
	np = pp;
	do {
		jobflags |= np->p_flags;
		if (np->p_flags&(PRUNNING|PSTOPPED)) {
			np->p_flags |= PRUNNING;
			np->p_flags &= ~PSTOPPED;
			if (foregnd)
				np->p_flags |= PFOREGND;
			else
				np->p_flags &= ~PFOREGND;
		}
	} while((np = np->p_friends) != pp);
I 2
	if (!foregnd)
		pclrcurr(pp);
E 2
D 15
	pprint(pp, foregnd ? NAME|JOBDIR : NUMBER|NAME|AMPERSAND);
E 15
I 15
	(void) pprint(pp, foregnd ? NAME|JOBDIR : NUMBER|NAME|AMPERSAND);
E 15
	if (foregnd)
D 15
		ioctl(FSHTTY, TIOCSPGRP, &pp->p_jobid);
E 15
I 15
		(void) ioctl(FSHTTY, TIOCSPGRP, (char *)&pp->p_jobid);
E 15
	if (jobflags&PSTOPPED)
D 15
		killpg(pp->p_jobid, SIGCONT);
D 9
	sigrelse(SIGCHLD);
E 9
I 9
D 10
	(void) sigrelse(mask(SIGCHLD));
E 10
I 10
D 13
	sigrelse(SIGCHLD);
E 13
I 13
	sigsetmask(omask);
E 15
I 15
		(void) killpg(pp->p_jobid, SIGCONT);
	(void) sigsetmask(omask);
E 15
E 13
E 10
E 9
}

panystop(neednl)
{
	register struct process *pp;

	chkstop = 2;
	for (pp = proclist.p_next; pp; pp = pp->p_next)
		if (pp->p_flags & PSTOPPED)
D 25
			error("\nThere are stopped jobs" + 1 - neednl);
E 25
I 25
			error("\nThere are suspended jobs" + 1 - neednl);
E 25
}

struct process *
pfind(cp)
	char *cp;
{
	register struct process *pp, *np;

	if (cp == 0 || cp[1] == 0 || eq(cp, "%%") || eq(cp, "%+")) {
		if (pcurrent == PNULL)
			bferr("No current job");
		return (pcurrent);
	}
	if (eq(cp, "%-") || eq(cp, "%#")) {
		if (pprevious == PNULL)
			bferr("No previous job");
		return (pprevious);
	}
	if (digit(cp[1])) {
		int index = atoi(cp+1);
		for (pp = proclist.p_next; pp; pp = pp->p_next)
			if (pp->p_index == index && pp->p_pid == pp->p_jobid)
				return (pp);
		bferr("No such job");
	}
	np = PNULL;
	for (pp = proclist.p_next; pp; pp = pp->p_next)
		if (pp->p_pid == pp->p_jobid) {
			if (cp[1] == '?') {
				register char *dp;
				for (dp = pp->p_command; *dp; dp++) {
					if (*dp != cp[2])
						continue;
					if (prefix(cp+2, dp))
						goto match;
				}
			} else if (prefix(cp+1, pp->p_command)) {
match:
				if (np)
					bferr("Ambiguous");
				np = pp;
			}
		}
	if (np)
		return (np);
	if (cp[1] == '?')
		bferr("No job matches pattern");
	else
		bferr("No such job");
I 15
	/*NOTREACHED*/
E 15
}

/*
D 2
 * pgetcurr - find a job that is not pp and ``most recent''
E 2
I 2
 * pgetcurr - find most recent job that is not pp, preferably stopped
E 2
 */
struct process *
pgetcurr(pp)
	register struct process *pp;
{
	register struct process *np;
I 2
	register struct process *xp = PNULL;
E 2

	for (np = proclist.p_next; np; np = np->p_next)
		if (np != pcurrent && np != pp && np->p_pid &&
		    np->p_pid == np->p_jobid) {
D 2
			return (np);
E 2
I 2
			if (np->p_flags & PSTOPPED)
				return (np);
			if (xp == PNULL)
				xp = np;
E 2
		}
D 2
	return (PNULL);
E 2
I 2
	return (xp);
E 2
}

/*
 * donotify - flag the job so as to report termination asynchronously
 */
donotify(v)
	char **v;
{
	register struct process *pp;

	pp = pfind(*++v);
	pp->p_flags |= PNOTIFY;
}

/*
 * Do the fork and whatever should be done in the child side that
 * should not be done if we are not forking at all (like for simple builtin's)
 * Also do everything that needs any signals fiddled with in the parent side
 *
 * Wanttty tells whether process and/or tty pgrps are to be manipulated:
 *	-1:	leave tty alone; inherit pgrp from parent
 *	 0:	already have tty; manipulate process pgrps only
 *	 1:	want to claim tty; manipulate process and tty pgrps
 * It is usually just the value of tpgrp.
 */
pfork(t, wanttty)
	struct command *t;	/* command we are forking for */
	int wanttty;
{
	register int pid;
	bool ignint = 0;
D 9
	int pgrp;
E 9
I 9
D 10
	int pgrp, omask;
E 10
I 10
D 13
	int pgrp;
E 13
I 13
D 23
	int pgrp, omask;
E 23
I 23
	int pgrp;
	long omask;
E 23
E 13
E 10
E 9

	/*
	 * A child will be uninterruptible only under very special
	 * conditions. Remember that the semantics of '&' is
	 * implemented by disconnecting the process from the tty so
	 * signals do not need to ignored just for '&'.
	 * Thus signals are set to default action for children unless:
	 *	we have had an "onintr -" (then specifically ignored)
	 *	we are not playing with signals (inherit action)
	 */
	if (setintr)
		ignint = (tpgrp == -1 && (t->t_dflg&FINT))
		    || (gointr && eq(gointr, "-"));
	/*
	 * Hold SIGCHLD until we have the process installed in our table.
	 */
D 9
	sighold(SIGCHLD);
E 9
I 9
D 10
	(void) sigblock(mask(SIGCHLD));
E 10
I 10
D 13
	sighold(SIGCHLD);
E 13
I 13
	omask = sigblock(sigmask(SIGCHLD));
E 13
E 10
E 9
	while ((pid = fork()) < 0)
		if (setintr == 0)
			sleep(FORKSLEEP);
		else {
D 9
			sigrelse(SIGINT);
			sigrelse(SIGCHLD);
E 9
I 9
D 10
			(void) sigrelse(mask(SIGINT)|mask(SIGCHLD));
E 10
I 10
D 13
			sigrelse(SIGINT);
			sigrelse(SIGCHLD);
E 13
I 13
D 15
			sigsetmask(omask);
E 15
I 15
			(void) sigsetmask(omask);
E 15
E 13
E 10
E 9
			error("No more processes");
		}
	if (pid == 0) {
		settimes();
		pgrp = pcurrjob ? pcurrjob->p_jobid : getpid();
		pflushall();
		pcurrjob = PNULL;
D 15
		timesdone = 0;
E 15
		child++;
		if (setintr) {
			setintr = 0;		/* until I think otherwise */
D 9
			sigrelse(SIGCHLD);
E 9
I 9
D 10
			(void) sigrelse(mask(SIGCHLD));
E 10
I 10
D 13
			sigrelse(SIGCHLD);
E 13
E 10
E 9
			/*
			 * Children just get blown away on SIGINT, SIGQUIT
			 * unless "onintr -" seen.
			 */
D 15
			signal(SIGINT, ignint ? SIG_IGN : SIG_DFL);
			signal(SIGQUIT, ignint ? SIG_IGN : SIG_DFL);
E 15
I 15
			(void) signal(SIGINT, ignint ? SIG_IGN : SIG_DFL);
			(void) signal(SIGQUIT, ignint ? SIG_IGN : SIG_DFL);
E 15
			if (wanttty >= 0) {
				/* make stoppable */
D 15
				signal(SIGTSTP, SIG_DFL);
				signal(SIGTTIN, SIG_DFL);
				signal(SIGTTOU, SIG_DFL);
E 15
I 15
				(void) signal(SIGTSTP, SIG_DFL);
				(void) signal(SIGTTIN, SIG_DFL);
				(void) signal(SIGTTOU, SIG_DFL);
E 15
			}
D 15
			signal(SIGTERM, parterm);
E 15
I 15
			(void) signal(SIGTERM, parterm);
E 15
		} else if (tpgrp == -1 && (t->t_dflg&FINT)) {
D 15
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
E 15
I 15
			(void) signal(SIGINT, SIG_IGN);
			(void) signal(SIGQUIT, SIG_IGN);
E 15
		}
		if (wanttty > 0)
D 15
			ioctl(FSHTTY, TIOCSPGRP, &pgrp);
E 15
I 15
			(void) ioctl(FSHTTY, TIOCSPGRP, (char *)&pgrp);
E 15
		if (wanttty >= 0 && tpgrp >= 0)
D 15
			setpgrp(0, pgrp);
E 15
I 15
			(void) setpgrp(0, pgrp);
E 15
		if (tpgrp > 0)
			tpgrp = 0;		/* gave tty away */
		/*
		 * Nohup and nice apply only to TCOM's but it would be
		 * nice (?!?) if you could say "nohup (foo;bar)"
		 * Then the parser would have to know about nice/nohup/time
		 */
		if (t->t_dflg & FNOHUP)
D 15
			signal(SIGHUP, SIG_IGN);
E 15
I 15
			(void) signal(SIGHUP, SIG_IGN);
E 15
D 13
		if (t->t_dflg & FNICE) {
/* sigh...
			nice(20);
			nice(-10);
*/
			nice(t->t_nice);
		}
I 9
D 10
		sigrelse(mask(SIGINT));
E 10
E 9

E 13
I 13
		if (t->t_dflg & FNICE)
D 15
			setpriority(PRIO_PROCESS, 0, t->t_nice);
E 15
I 15
D 21
			(void) setpriority(PRIO_PROCESS, 0, t->t_nice);
E 21
I 21
D 22
			(void) setpriority(PRIO_PROCESS, 0,
			    getpriority(PRIO_PROCESS, 0) + t->t_nice);
E 22
I 22
			(void) setpriority(PRIO_PROCESS, 0, t->t_nice);
E 22
E 21
E 15
E 13
	} else {
		palloc(pid, t);
D 9
		sigrelse(SIGCHLD);
E 9
I 9
D 10
		(void) sigrelse(mask(SIGCHLD));
E 10
I 10
D 13
		sigrelse(SIGCHLD);
E 13
I 13
D 15
		sigsetmask(omask);
E 15
I 15
		(void) sigsetmask(omask);
E 15
E 13
E 10
E 9
	}

	return (pid);
}

okpcntl()
{

	if (tpgrp == -1)
		error("No job control in this shell");
	if (tpgrp == 0)
		error("No job control in subshells");
I 9
D 10
}

/*
 * For "compatibility".
 */
sigrelse(m)
{

	return (sigsetmask(sigblock(0) &~ m));
E 10
E 9
}
E 1
