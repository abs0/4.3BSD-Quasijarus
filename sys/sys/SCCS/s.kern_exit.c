h04289
s 00004/00004/00283
d D 7.4 87/08/07 20:21:47 mckusick 24 22
c use malloc/free to hold zombie status
e
s 00004/00004/00283
d R 7.4 87/06/20 14:46:21 mckusick 23 22
c use malloc/free to hold zombie status
e
s 00001/00001/00286
d D 7.3 87/02/23 22:12:52 karels 22 21
c print errno when init can't be executed
e
s 00005/00000/00282
d D 7.2 86/11/03 11:59:40 karels 21 20
c merge in tahoe support
e
s 00001/00001/00281
d D 7.1 86/06/05 00:02:37 mckusick 20 19
c 4.3BSD release version
e
s 00007/00001/00275
d D 6.13 86/03/12 11:00:42 karels 19 18
c need to raise ipl before freeing page tables (done by vrelu);
c might as well free user struct before freeing the page tables that map it.
e
s 00000/00001/00276
d D 6.12 86/02/20 14:49:33 karels 18 17
c spl5 in exit is redundant
e
s 00001/00001/00276
d D 6.11 85/11/04 17:52:35 karels 17 16
c cleanup spgrp, rm unused code (should rm it all)
e
s 00007/00001/00270
d D 6.10 85/06/08 14:35:56 mckusick 16 15
c Add copyright
e
s 00017/00012/00254
d D 6.9 85/05/27 19:58:30 karels 15 14
c implement high-water mark on file descriptors in use;
c printf when init can't be found;
c M_WAIT is implemented!
e
s 00001/00002/00265
d D 6.8 85/05/22 19:50:51 mckusick 14 13
c eliminate double meaning of SOUSIG
e
s 00013/00009/00254
d D 6.7 85/04/14 18:12:58 sam 13 12
c recover from mbuf lossage during exit (logging event)
e
s 00005/00001/00258
d D 6.6 85/03/12 13:53:24 mckusick 12 11
c add another bit to sigvec() flags to disable system call restart
e
s 00001/00000/00258
d D 6.5 84/12/20 14:28:19 karels 11 10
c make spgrp use child pointers instead of linear searches
e
s 00013/00013/00245
d D 6.4 84/08/29 20:19:25 bloom 10 9
c Change to includes.  no more ../h
e
s 00003/00001/00255
d D 6.3 84/06/10 01:10:03 sam 9 8
c don't copyout rusage on wait3 unless user has supplied buffer
e
s 00046/00037/00210
d D 6.2 84/05/22 11:44:15 karels 8 7
c linked lists of active, zombie and free procs; avoid linear proc
c searches wherever possible
e
s 00000/00000/00247
d D 6.1 83/07/29 06:32:57 sam 7 6
c 4.2 distribution
e
s 00000/00003/00247
d D 4.6 83/07/01 02:18:37 sam 6 5
c purge #if sun's
e
s 00000/00002/00250
d D 4.5 83/06/16 15:45:57 sam 5 4
c lint
e
s 00001/00001/00251
d D 4.4 83/06/14 01:37:08 sam 4 3
c revamp locking to be done at the file table level
e
s 00007/00011/00245
d D 4.3 83/06/02 15:56:45 sam 3 2
c new signals
e
s 00000/00021/00256
d D 4.2 83/05/31 01:03:37 sam 2 1
c collect all the compatibility stuff in single files
e
s 00277/00000/00000
d D 4.1 83/05/27 14:02:44 sam 1 0
c date and time created 83/05/27 14:02:44 by sam
e
u
U
t
T
I 1
D 16
/*	%M%	%I%	%E%	*/
E 16
I 16
/*
D 20
 * Copyright (c) 1982 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 16

#include "../machine/reg.h"
#include "../machine/psl.h"

D 10
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/map.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/kernel.h"
#include "../h/proc.h"
#include "../h/buf.h"
#include "../h/wait.h"
#include "../h/vm.h"
#include "../h/file.h"
#include "../h/mbuf.h"
#include "../h/inode.h"
E 10
I 10
#include "param.h"
#include "systm.h"
#include "map.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "proc.h"
#include "buf.h"
#include "wait.h"
#include "vm.h"
#include "file.h"
D 24
#include "mbuf.h"
E 24
#include "inode.h"
I 13
#include "syslog.h"
I 24
#include "malloc.h"
E 24
E 13
E 10

/*
 * Exit system call: pass back caller's arg
 */
rexit()
{
	register struct a {
		int	rval;
	} *uap;

	uap = (struct a *)u.u_ap;
	exit((uap->rval & 0377) << 8);
}

/*
 * Release resources.
 * Save u. area for parent to look at.
 * Enter zombie state.
 * Wake up parent and init processes,
 * and dispose of children.
 */
exit(rv)
	int rv;
{
	register int i;
D 8
	register struct proc *p, *q;
E 8
I 8
	register struct proc *p, *q, *nq;
E 8
	register int x;
D 24
	struct mbuf *m = m_getclr(M_WAIT, MT_ZOMBIE);
E 24

#ifdef PGINPROF
	vmsizmon();
#endif
	p = u.u_procp;
I 24
	MALLOC(p->p_ru, struct rusage *, sizeof(struct rusage),
		M_ZOMBIE, M_WAITOK);
E 24
	p->p_flag &= ~(STRC|SULOCK);
	p->p_flag |= SWEXIT;
D 3
	(void) spl6();
	/* we know SIG_IGN is 1 */
	p->p_siga0 = ~0;
	p->p_siga1 = 0;
	(void) spl0();
E 3
I 3
	p->p_sigignore = ~0;
E 3
	p->p_cpticks = 0;
	p->p_pctcpu = 0;
D 3
	for (i=0; i<NSIG; i++)
E 3
I 3
	for (i = 0; i < NSIG; i++)
E 3
		u.u_signal[i] = SIG_IGN;
	untimeout(realitexpire, (caddr_t)p);
	/*
	 * Release virtual memory.  If we resulted from
	 * a vfork(), instead give the resources back to
	 * the parent.
	 */
	if ((p->p_flag & SVFORK) == 0)
		vrelvm();
	else {
		p->p_flag &= ~SVFORK;
		wakeup((caddr_t)p);
		while ((p->p_flag & SVFDONE) == 0)
			sleep((caddr_t)p, PZERO - 1);
		p->p_flag &= ~SVFDONE;
	}
D 15
	for (i = 0; i < NOFILE; i++) {
E 15
I 15
	for (i = 0; i <= u.u_lastfile; i++) {
E 15
		struct file *f;
D 5
		int po;
E 5

		f = u.u_ofile[i];
D 15
		u.u_ofile[i] = NULL;
D 5
		po = u.u_pofile[i];
E 5
		u.u_pofile[i] = 0;
D 4
		closef(f, po);
E 4
I 4
		closef(f);
E 15
I 15
		if (f) {
			u.u_ofile[i] = NULL;
			u.u_pofile[i] = 0;
			closef(f);
		}
E 15
E 4
	}
	ilock(u.u_cdir);
	iput(u.u_cdir);
	if (u.u_rdir) {
		ilock(u.u_rdir);
		iput(u.u_rdir);
	}
	u.u_rlimit[RLIMIT_FSIZE].rlim_cur = RLIM_INFINITY;
	acct();
#ifdef QUOTA
	qclean();
#endif
D 6
#ifdef sun
	ctxfree(u.u_procp);
#endif
E 6
D 19
	vrelpt(u.u_procp);
E 19
I 19
	/*
	 * Freeing the user structure and kernel stack
	 * for the current process: have to run a bit longer
	 * using the pages which are about to be freed...
	 * vrelu will block memory allocation by raising ipl.
	 */
E 19
	vrelu(u.u_procp, 0);
I 19
	vrelpt(u.u_procp);
E 19
D 18
	(void) spl5();		/* hack for mem alloc race XXX */
E 18
I 8
	if (*p->p_prev = p->p_nxt)		/* off allproc queue */
		p->p_nxt->p_prev = p->p_prev;
	if (p->p_nxt = zombproc)		/* onto zombproc */
		p->p_nxt->p_prev = &p->p_nxt;
	p->p_prev = &zombproc;
	zombproc = p;
E 8
	multprog--;
	p->p_stat = SZOMB;
	noproc = 1;
	i = PIDHASH(p->p_pid);
	x = p - proc;
	if (pidhash[i] == x)
		pidhash[i] = p->p_idhash;
	else {
		for (i = pidhash[i]; i != 0; i = proc[i].p_idhash)
			if (proc[i].p_idhash == x) {
				proc[i].p_idhash = p->p_idhash;
				goto done;
			}
		panic("exit");
	}
D 15
	if (p->p_pid == 1)
		panic("init died");
E 15
I 15
	if (p->p_pid == 1) {
		if (p->p_dsize == 0) {
D 22
			printf("Can't exec /etc/init\n");
E 22
I 22
			printf("Can't exec /etc/init (errno %d)\n", rv >> 8);
E 22
			for (;;)
				;
		} else
			panic("init died");
	}
E 15
done:
	p->p_xstat = rv;
D 13
if (m == 0)
panic("exit: m_getclr");
	p->p_ru = mtod(m, struct rusage *);
	*p->p_ru = u.u_ru;
	ruadd(p->p_ru, &u.u_cru);
E 13
I 13
D 15
	if (m) {
		p->p_ru = mtod(m, struct rusage *);
		*p->p_ru = u.u_ru;
		ruadd(p->p_ru, &u.u_cru);
	} else
		log(KERN_ALERT, "exit: pid %d: no mbuf", p->p_pid);
E 15
I 15
D 24
	p->p_ru = mtod(m, struct rusage *);
E 24
	*p->p_ru = u.u_ru;
	ruadd(p->p_ru, &u.u_cru);
E 15
E 13
D 8
	for (q = proc; q < procNPROC; q++)
		if (q->p_pptr == p) {
			if (q->p_osptr)
				q->p_osptr->p_ysptr = q->p_ysptr;
			if (q->p_ysptr)
				q->p_ysptr->p_osptr = q->p_osptr;
			if (proc[1].p_cptr)
				proc[1].p_cptr->p_ysptr = q;
			q->p_osptr = proc[1].p_cptr;
			q->p_ysptr = NULL;
			proc[1].p_cptr = q;
E 8
I 8
	if (p->p_cptr)		/* only need this if any child is S_ZOMB */
		wakeup((caddr_t)&proc[1]);
	for (q = p->p_cptr; q != NULL; q = nq) {
		nq = q->p_osptr;
		if (nq != NULL)
			nq->p_ysptr = NULL;
		if (proc[1].p_cptr)
			proc[1].p_cptr->p_ysptr = q;
		q->p_osptr = proc[1].p_cptr;
		q->p_ysptr = NULL;
		proc[1].p_cptr = q;
E 8

D 8
			q->p_pptr = &proc[1];
			q->p_ppid = 1;
			wakeup((caddr_t)&proc[1]);
			/*
			 * Traced processes are killed
			 * since their existence means someone is screwing up.
			 * Stopped processes are sent a hangup and a continue.
			 * This is designed to be ``safe'' for setuid
			 * processes since they must be willing to tolerate
			 * hangups anyways.
			 */
			if (q->p_flag&STRC) {
				q->p_flag &= ~STRC;
				psignal(q, SIGKILL);
			} else if (q->p_stat == SSTOP) {
				psignal(q, SIGHUP);
				psignal(q, SIGCONT);
			}
			/*
			 * Protect this process from future
			 * tty signals, clear TSTP/TTIN/TTOU if pending.
			 */
			(void) spgrp(q, -1);
E 8
I 8
		q->p_pptr = &proc[1];
		q->p_ppid = 1;
		/*
		 * Traced processes are killed
		 * since their existence means someone is screwing up.
		 * Stopped processes are sent a hangup and a continue.
		 * This is designed to be ``safe'' for setuid
		 * processes since they must be willing to tolerate
		 * hangups anyways.
		 */
		if (q->p_flag&STRC) {
			q->p_flag &= ~STRC;
			psignal(q, SIGKILL);
		} else if (q->p_stat == SSTOP) {
			psignal(q, SIGHUP);
			psignal(q, SIGCONT);
E 8
		}
I 8
		/*
		 * Protect this process from future
		 * tty signals, clear TSTP/TTIN/TTOU if pending.
		 */
D 17
		(void) spgrp(q, -1);
E 17
I 17
		(void) spgrp(q);
E 17
	}
I 11
	p->p_cptr = NULL;
E 11
E 8
	psignal(p->p_pptr, SIGCHLD);
	wakeup((caddr_t)p->p_pptr);
I 21
#if defined(tahoe)
	dkeyrelease(p->p_dkey), p->p_dkey = 0;
	ckeyrelease(p->p_ckey), p->p_ckey = 0;
	u.u_pcb.pcb_savacc.faddr = (float *)NULL;
#endif
E 21
	swtch();
}

wait()
{
	struct rusage ru, *rup;

	if ((u.u_ar0[PS] & PSL_ALLCC) != PSL_ALLCC) {
		u.u_error = wait1(0, (struct rusage *)0);
		return;
	}
	rup = (struct rusage *)u.u_ar0[R1];
	u.u_error = wait1(u.u_ar0[R0], &ru);
	if (u.u_error)
		return;
D 9
	(void) copyout((caddr_t)&ru, (caddr_t)rup, sizeof (struct rusage));
E 9
I 9
	if (rup != (struct rusage *)0)
		u.u_error = copyout((caddr_t)&ru, (caddr_t)rup,
		    sizeof (struct rusage));
E 9
}

D 2
#ifndef NOCOMPAT
#include "../h/vtimes.h"

owait()
{
	struct rusage ru;
	struct vtimes *vtp, avt;

	if ((u.u_ar0[PS] & PSL_ALLCC) != PSL_ALLCC) {
		u.u_error = wait1(0, (struct rusage *)0);
		return;
	}
	vtp = (struct vtimes *)u.u_ar0[R1];
	u.u_error = wait1(u.u_ar0[R0], &ru);
	if (u.u_error)
		return;
	getvtimes(&ru, &avt);
	(void) copyout((caddr_t)&avt, (caddr_t)vtp, sizeof (struct vtimes));
}
#endif

E 2
/*
 * Wait system call.
 * Search for a terminated (zombie) child,
 * finally lay it to rest, and collect its status.
 * Look also for stopped (traced) children,
 * and pass back status from them.
 */
wait1(options, ru)
	register int options;
	struct rusage *ru;
{
	register f;
	register struct proc *p, *q;

	f = 0;
loop:
D 8
	for (p = proc; p < procNPROC; p++)
	if (p->p_pptr == u.u_procp) {
E 8
I 8
	q = u.u_procp;
	for (p = q->p_cptr; p; p = p->p_osptr) {
E 8
		f++;
		if (p->p_stat == SZOMB) {
			u.u_r.r_val1 = p->p_pid;
			u.u_r.r_val2 = p->p_xstat;
			p->p_xstat = 0;
D 13
			if (ru)
E 13
I 13
			if (ru && p->p_ru)
E 13
				*ru = *p->p_ru;
D 13
			ruadd(&u.u_cru, p->p_ru);
			(void) m_free(dtom(p->p_ru));
			p->p_ru = 0;
E 13
I 13
			if (p->p_ru) {
				ruadd(&u.u_cru, p->p_ru);
D 24
				(void) m_free(dtom(p->p_ru));
E 24
I 24
				FREE(p->p_ru, M_ZOMBIE);
E 24
				p->p_ru = 0;
			}
E 13
			p->p_stat = NULL;
			p->p_pid = 0;
			p->p_ppid = 0;
I 8
			if (*p->p_prev = p->p_nxt)	/* off zombproc */
				p->p_nxt->p_prev = p->p_prev;
			p->p_nxt = freeproc;		/* onto freeproc */
			freeproc = p;
E 8
			if (q = p->p_ysptr)
				q->p_osptr = p->p_osptr;
			if (q = p->p_osptr)
				q->p_ysptr = p->p_ysptr;
			if ((q = p->p_pptr)->p_cptr == p)
				q->p_cptr = p->p_osptr;
			p->p_pptr = 0;
			p->p_ysptr = 0;
			p->p_osptr = 0;
			p->p_cptr = 0;
			p->p_sig = 0;
D 3
			p->p_siga0 = 0;
			p->p_siga1 = 0;
E 3
I 3
			p->p_sigcatch = 0;
			p->p_sigignore = 0;
			p->p_sigmask = 0;
E 3
			p->p_pgrp = 0;
			p->p_flag = 0;
			p->p_wchan = 0;
			p->p_cursig = 0;
			return (0);
		}
		if (p->p_stat == SSTOP && (p->p_flag&SWTED)==0 &&
		    (p->p_flag&STRC || options&WUNTRACED)) {
			p->p_flag |= SWTED;
			u.u_r.r_val1 = p->p_pid;
			u.u_r.r_val2 = (p->p_cursig<<8) | WSTOPPED;
			return (0);
		}
	}
D 3
	if (f == 0) {
E 3
I 3
	if (f == 0)
E 3
		return (ECHILD);
D 3
	}
E 3
	if (options&WNOHANG) {
		u.u_r.r_val1 = 0;
		return (0);
	}
D 3
	if ((u.u_procp->p_flag&SNUSIG) && setjmp(&u.u_qsave)) {
E 3
I 3
D 12
	if ((u.u_procp->p_flag&SOUSIG) == 0 && setjmp(&u.u_qsave)) {
E 12
I 12
	if (setjmp(&u.u_qsave)) {
		p = u.u_procp;
D 14
		if ((u.u_sigintr & sigmask(p->p_cursig)) != 0 ||
		    (p->p_flag & SOUSIG) != 0)
E 14
I 14
		if ((u.u_sigintr & sigmask(p->p_cursig)) != 0)
E 14
			return(EINTR);
E 12
E 3
		u.u_eosys = RESTARTSYS;
		return (0);
	}
	sleep((caddr_t)u.u_procp, PWAIT);
	goto loop;
}
E 1
