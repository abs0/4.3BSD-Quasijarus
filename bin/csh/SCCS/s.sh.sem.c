h39349
s 00001/00001/00404
d D 5.5 87/06/25 09:15:24 bostic 11 10
c csh long/int mismatches; bug report 4.3BSD/bin/45
e
s 00014/00005/00391
d D 5.4 86/05/13 01:08:33 lepreau 10 9
c nice is absolute after all; comment the problem Sun has with signal status
c getting zapped by vfork'ed child
e
s 00003/00002/00393
d D 5.3 86/01/12 02:34:15 lepreau 9 8
c nice is relative, not absolute. (Kirk "authorized" it.)
e
s 00003/00003/00392
d D 5.2 85/06/06 13:10:22 edward 8 7
c cleaning up after bozos
e
s 00008/00002/00387
d D 5.1 85/06/04 11:07:36 dist 7 6
c Add copyright
e
s 00003/00003/00386
d D 4.6 85/01/16 14:26:44 edward 6 5
c don't need to turn off close-on-exec after dup any more
e
s 00059/00044/00330
d D 4.5 84/12/13 14:40:58 edward 5 4
c performance
e
s 00018/00017/00356
d D 4.4 84/08/31 09:31:31 ralph 4 3
c use new signal calls instead of compatibility routines.
e
s 00013/00013/00360
d D 4.3 83/06/11 16:50:05 sam 3 2
c different approach, try signal compatibility package
e
s 00017/00013/00356
d D 4.2 83/06/10 23:59:48 sam 2 1
c new signals; no libjobs; still loses SIGINT by getting it masked 
c sometimes, but we check it in before we lose something
e
s 00369/00000/00000
d D 4.1 80/10/09 12:41:47 bill 1 0
c date and time created 80/10/09 12:41:47 by bill
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
E 8
I 8
 * All rights reserved.  The Berkeley Software License Agreement
E 8
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
D 5
static	char *sccsid = "%Z%%M% %I% %G%";
E 5
I 5
#ifndef lint
D 7
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 7
I 7
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8
I 8
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 8
E 7
E 5

#include "sh.h"
#include "sh.proc.h"
#include <sys/ioctl.h>

/*
 * C shell
 */

/*VARARGS 1*/
execute(t, wanttty, pipein, pipeout)
	register struct command *t;
	int wanttty, *pipein, *pipeout;
{
	bool forked = 0;
	struct biltins *bifunc;
	int pid = 0;
	int pv[2];

	if (t == 0)
		return;
	if ((t->t_dflg & FAND) && wanttty > 0)
		wanttty = 0;
	switch (t->t_dtyp) {

	case TCOM:
		if ((t->t_dcom[0][0] & (QUOTE|TRIM)) == QUOTE)
D 5
			strcpy(t->t_dcom[0], t->t_dcom[0] + 1);
E 5
I 5
			(void) strcpy(t->t_dcom[0], t->t_dcom[0] + 1);
E 5
		if ((t->t_dflg & FREDO) == 0)
			Dfix(t);		/* $ " ' \ */
		if (t->t_dcom[0] == 0)
			return;
		/* fall into... */

	case TPAR:
		if (t->t_dflg & FPOU)
			mypipe(pipeout);
		/*
		 * Must do << early so parent will know
		 * where input pointer should be.
		 * If noexec then this is all we do.
		 */
		if (t->t_dflg & FHERE) {
D 5
			close(0);
E 5
I 5
			(void) close(0);
E 5
			heredoc(t->t_dlef);
			if (noexec)
D 5
				close(0);
E 5
I 5
				(void) close(0);
E 5
		}
		if (noexec)
			break;

		set("status", "0");

		/*
		 * This mess is the necessary kludge to handle the prefix
		 * builtins: nice, nohup, time.  These commands can also
		 * be used by themselves, and this is not handled here.
		 * This will also work when loops are parsed.
		 */
		while (t->t_dtyp == TCOM)
			if (eq(t->t_dcom[0], "nice"))
				if (t->t_dcom[1])
					if (any(t->t_dcom[1][0], "+-"))
						if (t->t_dcom[2]) {
							setname("nice");
							t->t_nice = getn(t->t_dcom[1]);
							lshift(t->t_dcom, 2);
							t->t_dflg |= FNICE;
						} else
							break;
					else {
						t->t_nice = 4;
						lshift(t->t_dcom, 1);
						t->t_dflg |= FNICE;
					}
				else
					break;
			else if (eq(t->t_dcom[0], "nohup"))
				if (t->t_dcom[1]) {
					t->t_dflg |= FNOHUP;
					lshift(t->t_dcom, 1);
				} else
					break;
			else if (eq(t->t_dcom[0], "time"))
				if (t->t_dcom[1]) {
					t->t_dflg |= FTIME;
					lshift(t->t_dcom, 1);
				} else
					break;
			else
				break;
		/*
		 * Check if we have a builtin function and remember which one.
		 */
		bifunc = t->t_dtyp == TCOM ? isbfunc(t) : (struct biltins *) 0;

		/*
		 * We fork only if we are timed, or are not the end of
		 * a parenthesized list and not a simple builtin function.
		 * Simple meaning one that is not pipedout, niced, nohupped,
		 * or &'d.
		 * It would be nice(?) to not fork in some of these cases.
		 */
		if (((t->t_dflg & FTIME) || (t->t_dflg & FPAR) == 0 &&
		     (!bifunc || t->t_dflg & (FPOU|FAND|FNICE|FNOHUP))))
#ifdef VFORK
		    if (t->t_dtyp == TPAR || t->t_dflg&(FREDO|FAND) || bifunc)
#endif
			{ forked++; pid = pfork(t, wanttty); }
#ifdef VFORK
		    else {
			int vffree();
D 5
			int ochild, osetintr, ohaderr, odidfds, odidcch;
E 5
I 5
			int ochild, osetintr, ohaderr, odidfds;
E 5
			int oSHIN, oSHOUT, oSHDIAG, oOLDSTD, otpgrp;
I 4
D 11
			int omask;
E 11
I 11
			long omask;
E 11
E 4

I 10
			/* 
			 * Prepare for the vfork by saving everything
			 * that the child corrupts before it exec's.
			 * Note that in some signal implementations
			 * which keep the signal info in user space
			 * (e.g. Sun's) it will also be necessary to
 			 * save and restore the current sigvec's for
			 * the signals the child touches before it
			 * exec's.
			 */
E 10
D 2
			sighold(SIGCHLD);
E 2
I 2
D 3
			(void) sigblock(mask(SIGCHLD));
E 3
I 3
D 4
			sighold(SIGCHLD);
E 4
I 4
			omask = sigblock(sigmask(SIGCHLD));
E 4
E 3
E 2
			ochild = child; osetintr = setintr;
D 5
			ohaderr = haderr; odidfds = didfds; odidcch = didcch;
E 5
I 5
			ohaderr = haderr; odidfds = didfds;
E 5
			oSHIN = SHIN; oSHOUT = SHOUT;
			oSHDIAG = SHDIAG; oOLDSTD = OLDSTD; otpgrp = tpgrp;
			Vsav = Vdp = 0; Vav = 0;
			pid = vfork();
			if (pid < 0) {
D 2
				sigrelse(SIGCHLD);
E 2
I 2
D 3
				(void) sigrelse(mask(SIGCHLD));
E 3
I 3
D 4
				sigrelse(SIGCHLD);
E 4
I 4
D 5
				sigsetmask(omask);
E 5
I 5
				(void) sigsetmask(omask);
E 5
E 4
E 3
E 2
				error("No more processes");
			}
			forked++;
D 10
			if (pid) {
E 10
I 10
			if (pid) {	/* parent */
E 10
				child = ochild; setintr = osetintr;
				haderr = ohaderr; didfds = odidfds;
D 5
				didcch = odidcch; SHIN = oSHIN;
E 5
I 5
				SHIN = oSHIN;
E 5
				SHOUT = oSHOUT; SHDIAG = oSHDIAG;
				OLDSTD = oOLDSTD; tpgrp = otpgrp;
				xfree(Vsav); Vsav = 0;
				xfree(Vdp); Vdp = 0;
D 5
				xfree(Vav); Vav = 0;
E 5
I 5
				xfree((char *)Vav); Vav = 0;
E 5
				/* this is from pfork() */
				palloc(pid, t);
D 2
				sigrelse(SIGCHLD);
E 2
I 2
D 3
				(void) sigrelse(mask(SIGCHLD));
E 3
I 3
D 4
				sigrelse(SIGCHLD);
E 4
I 4
D 5
				sigsetmask(omask);
E 5
I 5
				(void) sigsetmask(omask);
E 5
E 4
E 3
E 2
D 10
			} else {
E 10
I 10
			} else {	/* child */
E 10
				/* this is from pfork() */
				int pgrp;
				bool ignint = 0;

				if (setintr)
					ignint =
					    (tpgrp == -1 && (t->t_dflg&FINT))
					    || gointr && eq(gointr, "-");
				pgrp = pcurrjob ? pcurrjob->p_jobid : getpid();
				child++;
				if (setintr) {
					setintr = 0;
D 2
					sigsys(SIGCHLD, SIG_DFL);
					sigsys(SIGINT, ignint ? SIG_IGN : vffree);
					sigsys(SIGQUIT, ignint ? SIG_IGN : SIG_DFL);
E 2
I 2
#ifdef notdef
D 3
					signal(SIGCHLD, SIG_DFL);
E 3
I 3
D 4
					sigsys(SIGCHLD, SIG_DFL);
E 4
I 4
D 5
					signal(SIGCHLD, SIG_DFL);
E 5
I 5
					(void) signal(SIGCHLD, SIG_DFL);
E 5
E 4
E 3
#endif
D 3
					signal(SIGINT,
E 3
I 3
D 4
					sigsys(SIGINT,
E 3
					    ignint ? SIG_IGN : vffree);
D 3
					signal(SIGQUIT,
E 3
I 3
					sigsys(SIGQUIT,
E 3
					    ignint ? SIG_IGN : SIG_DFL);
E 4
I 4
D 5
					signal(SIGINT, ignint ?
E 5
I 5
					(void) signal(SIGINT, ignint ?
E 5
						SIG_IGN : vffree);
D 5
					signal(SIGQUIT, ignint ?
E 5
I 5
					(void) signal(SIGQUIT, ignint ?
E 5
						SIG_IGN : SIG_DFL);
E 4
E 2
					if (wanttty >= 0) {
D 2
						sigsys(SIGTSTP, SIG_DFL);
						sigsys(SIGTTIN, SIG_DFL);
						sigsys(SIGTTOU, SIG_DFL);
E 2
I 2
D 3
						signal(SIGTSTP, SIG_DFL);
						signal(SIGTTIN, SIG_DFL);
						signal(SIGTTOU, SIG_DFL);
E 3
I 3
D 4
						sigsys(SIGTSTP, SIG_DFL);
						sigsys(SIGTTIN, SIG_DFL);
						sigsys(SIGTTOU, SIG_DFL);
E 4
I 4
D 5
						signal(SIGTSTP, SIG_DFL);
						signal(SIGTTIN, SIG_DFL);
						signal(SIGTTOU, SIG_DFL);
E 5
I 5
						(void) signal(SIGTSTP, SIG_DFL);
						(void) signal(SIGTTIN, SIG_DFL);
						(void) signal(SIGTTOU, SIG_DFL);
E 5
E 4
E 3
E 2
					}
D 2
					sigsys(SIGTERM, parterm);
E 2
I 2
D 3
					signal(SIGTERM, parterm);
E 3
I 3
D 4
					sigsys(SIGTERM, parterm);
E 4
I 4
D 5
					signal(SIGTERM, parterm);
E 5
I 5
					(void) signal(SIGTERM, parterm);
E 5
E 4
E 3
E 2
				} else if (tpgrp == -1 && (t->t_dflg&FINT)) {
D 2
					sigsys(SIGINT, SIG_IGN);
					sigsys(SIGQUIT, SIG_IGN);
E 2
I 2
D 3
					signal(SIGINT, SIG_IGN);
					signal(SIGQUIT, SIG_IGN);
E 3
I 3
D 4
					sigsys(SIGINT, SIG_IGN);
					sigsys(SIGQUIT, SIG_IGN);
E 4
I 4
D 5
					signal(SIGINT, SIG_IGN);
					signal(SIGQUIT, SIG_IGN);
E 5
I 5
					(void) signal(SIGINT, SIG_IGN);
					(void) signal(SIGQUIT, SIG_IGN);
E 5
E 4
E 3
E 2
				}
				if (wanttty > 0)
D 5
					ioctl(FSHTTY, TIOCSPGRP, &pgrp);
E 5
I 5
					(void) ioctl(FSHTTY, TIOCSPGRP,
						(char *)&pgrp);
E 5
				if (wanttty >= 0 && tpgrp >= 0)
D 5
					setpgrp(0, pgrp);
E 5
I 5
					(void) setpgrp(0, pgrp);
E 5
				if (tpgrp > 0)
					tpgrp = 0;
				if (t->t_dflg & FNOHUP)
D 2
					sigsys(SIGHUP, SIG_IGN);
E 2
I 2
D 3
					signal(SIGHUP, SIG_IGN);
E 3
I 3
D 4
					sigsys(SIGHUP, SIG_IGN);
E 4
I 4
D 5
					signal(SIGHUP, SIG_IGN);
E 5
I 5
					(void) signal(SIGHUP, SIG_IGN);
E 5
E 4
E 3
E 2
				if (t->t_dflg & FNICE)
D 4
					nice(t->t_nice);
E 4
I 4
D 5
					setpriority(PRIO_PROCESS, 0, t->t_nice);
E 5
I 5
D 9
					(void) setpriority(PRIO_PROCESS,
						0, t->t_nice);
E 9
I 9
D 10
					(void) setpriority(PRIO_PROCESS, 0,
			    		    getpriority(PRIO_PROCESS, 0)
					    + t->t_nice);
E 10
I 10
					(void) setpriority(PRIO_PROCESS,
						0, t->t_nice);
E 10
E 9
E 5
E 4
			}

D 4
		}
E 4
I 4
		    }
E 4
#endif
		if (pid != 0) {
			/*
			 * It would be better if we could wait for the
			 * whole job when we knew the last process
			 * had been started.  Pwait, in fact, does
			 * wait for the whole job anyway, but this test
			 * doesn't really express our intentions.
			 */
D 5
			if (didfds==0 && t->t_dflg&FPIN)
				close(pipein[0]), close(pipein[1]);
E 5
I 5
			if (didfds==0 && t->t_dflg&FPIN) {
				(void) close(pipein[0]);
				(void) close(pipein[1]);
			}
E 5
			if ((t->t_dflg & (FPOU|FAND)) == 0)
				pwait();
			break;
		}
		doio(t, pipein, pipeout);
D 5
		if (t->t_dflg & FPOU)
			close(pipeout[0]), close(pipeout[1]);
E 5
I 5
		if (t->t_dflg & FPOU) {
			(void) close(pipeout[0]);
			(void) close(pipeout[1]);
		}
E 5

		/*
		 * Perform a builtin function.
		 * If we are not forked, arrange for possible stopping
		 */
		if (bifunc) {
			func(t, bifunc);
			if (forked)
				exitstat();
			break;
		}
		if (t->t_dtyp != TPAR) {
			doexec(t);
			/*NOTREACHED*/
		}
		/*
		 * For () commands must put new 0,1,2 in FSH* and recurse
		 */
		OLDSTD = dcopy(0, FOLDSTD);
		SHOUT = dcopy(1, FSHOUT);
		SHDIAG = dcopy(2, FSHDIAG);
D 5
		close(SHIN), SHIN = -1;
		didcch = 0, didfds = 0;
E 5
I 5
		(void) close(SHIN);
		SHIN = -1;
		didfds = 0;
E 5
		wanttty = -1;
		t->t_dspr->t_dflg |= t->t_dflg & FINT;
		execute(t->t_dspr, wanttty);
		exitstat();

	case TFIL:
		t->t_dcar->t_dflg |= FPOU |
		    (t->t_dflg & (FPIN|FAND|FDIAG|FINT));
		execute(t->t_dcar, wanttty, pipein, pv);
		t->t_dcdr->t_dflg |= FPIN |
		    (t->t_dflg & (FPOU|FAND|FPAR|FINT));
		if (wanttty > 0)
			wanttty = 0;		/* got tty already */
		execute(t->t_dcdr, wanttty, pv, pipeout);
		break;

	case TLST:
		if (t->t_dcar) {
			t->t_dcar->t_dflg |= t->t_dflg & FINT;
			execute(t->t_dcar, wanttty);
			/*
			 * In strange case of A&B make a new job after A
			 */
			if (t->t_dcar->t_dflg&FAND && t->t_dcdr &&
			    (t->t_dcdr->t_dflg&FAND) == 0)
				pendjob();
		}
		if (t->t_dcdr) {
			t->t_dcdr->t_dflg |= t->t_dflg & (FPAR|FINT);
			execute(t->t_dcdr, wanttty);
		}
		break;

	case TOR:
	case TAND:
		if (t->t_dcar) {
			t->t_dcar->t_dflg |= t->t_dflg & FINT;
			execute(t->t_dcar, wanttty);
			if ((getn(value("status")) == 0) != (t->t_dtyp == TAND))
				return;
		}
		if (t->t_dcdr) {
			t->t_dcdr->t_dflg |= t->t_dflg & (FPAR|FINT);
			execute(t->t_dcdr, wanttty);
		}
		break;
	}
	/*
	 * Fall through for all breaks from switch
	 *
	 * If there will be no more executions of this
	 * command, flush all file descriptors.
	 * Places that turn on the FREDO bit are responsible
	 * for doing donefds after the last re-execution
	 */
	if (didfds && !(t->t_dflg & FREDO))
		donefds();
}

#ifdef VFORK
vffree()
{
	register char **v;

	if (v = gargv)
D 5
		gargv = 0, xfree(gargv);
E 5
I 5
		gargv = 0, xfree((char *)v);
E 5
	if (v = pargv)
D 5
		pargv = 0, xfree(pargv);
E 5
I 5
		pargv = 0, xfree((char *)v);
E 5
	_exit(1);
}
#endif

/*
 * Perform io redirection.
 * We may or maynot be forked here.
 */
doio(t, pipein, pipeout)
	register struct command *t;
	int *pipein, *pipeout;
{
	register char *cp;
	register int flags = t->t_dflg;

	if (didfds || (flags & FREDO))
		return;
	if ((flags & FHERE) == 0) {	/* FHERE already done */
D 5
		close(0);
E 5
I 5
		(void) close(0);
E 5
		if (cp = t->t_dlef) {
			cp = globone(Dfix1(cp));
			xfree(cp);
			if (open(cp, 0) < 0)
				Perror(cp);
D 5
		} else if (flags & FPIN)
			dup(pipein[0]), close(pipein[0]), close(pipein[1]);
		else if ((flags & FINT) && tpgrp == -1)
			close(0), open("/dev/null", 0);
		else
			dup(OLDSTD);
E 5
I 5
		} else if (flags & FPIN) {
			(void) dup(pipein[0]);
			(void) close(pipein[0]);
			(void) close(pipein[1]);
		} else if ((flags & FINT) && tpgrp == -1) {
			(void) close(0);
			(void) open("/dev/null", 0);
		} else
D 6
			(void) ioctl(dup(OLDSTD), FIONCLEX, (char *)0);
E 6
I 6
			(void) dup(OLDSTD);
E 6
E 5
	}
D 5
	close(1);
E 5
I 5
	(void) close(1);
E 5
	if (cp = t->t_drit) {
		cp = globone(Dfix1(cp));
		xfree(cp);
		if ((flags & FCAT) && open(cp, 1) >= 0)
D 5
			lseek(1, 0l, 2);
E 5
I 5
			(void) lseek(1, (off_t)0, 2);
E 5
		else {
			if (!(flags & FANY) && adrof("noclobber")) {
				if (flags & FCAT)
					Perror(cp);
				chkclob(cp);
			}
			if (creat(cp, 0666) < 0)
				Perror(cp);
		}
	} else if (flags & FPOU)
D 5
		dup(pipeout[1]);
E 5
I 5
		(void) dup(pipeout[1]);
E 5
	else
D 5
		dup(SHOUT);
E 5
I 5
D 6
		(void) ioctl(dup(SHOUT), FIONCLEX, (char *)0);
E 6
I 6
		(void) dup(SHOUT);
E 6
E 5

D 5
	close(2);
	dup((flags & FDIAG) ? 1 : SHDIAG);
E 5
I 5
	(void) close(2);
	if (flags & FDIAG)
		(void) dup(1);
	else
D 6
		(void) ioctl(dup(SHDIAG), FIONCLEX, (char *)0);
E 6
I 6
		(void) dup(SHDIAG);
E 6
E 5
	didfds = 1;
}

mypipe(pv)
	register int *pv;
{

	if (pipe(pv) < 0)
		goto oops;
	pv[0] = dmove(pv[0], -1);
	pv[1] = dmove(pv[1], -1);
	if (pv[0] >= 0 && pv[1] >= 0)
		return;
oops:
	error("Can't make pipe");
}

chkclob(cp)
	register char *cp;
{
	struct stat stb;

	if (stat(cp, &stb) < 0)
		return;
	if ((stb.st_mode & S_IFMT) == S_IFCHR)
		return;
	error("%s: File exists", cp);
}
E 1
