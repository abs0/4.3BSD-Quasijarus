h06207
s 00004/00000/00284
d D 7.2 86/11/03 11:59:44 karels 14 13
c merge in tahoe support
e
s 00001/00001/00283
d D 7.1 86/06/05 00:02:50 mckusick 13 12
c 4.3BSD release version
e
s 00002/00002/00282
d D 6.9 86/02/23 23:08:50 karels 12 11
c lint
e
s 00001/00001/00283
d D 6.8 86/02/20 15:58:23 karels 11 10
c cleanups from Sam: format, spl's, ptrace defs
e
s 00007/00001/00277
d D 6.7 85/06/08 14:36:09 mckusick 10 9
c Add copyright
e
s 00001/00001/00277
d D 6.6 85/05/27 19:53:59 karels 9 8
c implement high-water mark on file descriptors in use
e
s 00014/00014/00264
d D 6.5 84/08/29 20:19:31 bloom 8 7
c Change to includes.  no more ../h
e
s 00001/00001/00277
d D 6.4 84/07/14 14:46:10 sam 7 6
c starting time of proc now timeval
e
s 00004/00003/00274
d D 6.3 84/06/06 23:21:31 sam 6 5
c Berkeley coding standards committee in action (clean up your act Mike)
e
s 00046/00023/00231
d D 6.2 84/05/22 11:44:25 karels 5 4
c linked lists of active, zombie and free procs; avoid linear proc
c searches wherever possible
e
s 00000/00000/00254
d D 6.1 83/07/29 06:33:01 sam 4 3
c 4.2 distribution
e
s 00000/00004/00254
d D 4.3 83/06/14 01:37:13 sam 3 2
c revamp locking to be done at the file table level
e
s 00005/00004/00253
d D 4.2 83/06/02 15:56:51 sam 2 1
c new signals
e
s 00257/00000/00000
d D 4.1 83/05/27 14:02:45 sam 1 0
c date and time created 83/05/27 14:02:45 by sam
e
u
U
t
T
I 1
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 10

#include "../machine/reg.h"
#include "../machine/pte.h"
#include "../machine/psl.h"

D 8
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/map.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/kernel.h"
#include "../h/proc.h"
#include "../h/inode.h"
#include "../h/seg.h"
#include "../h/vm.h"
#include "../h/text.h"
#include "../h/file.h"
#include "../h/acct.h"
#include "../h/quota.h"
E 8
I 8
#include "param.h"
#include "systm.h"
#include "map.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "proc.h"
#include "inode.h"
#include "seg.h"
#include "vm.h"
#include "text.h"
#include "file.h"
#include "acct.h"
#include "quota.h"
E 8

/*
 * fork system call.
 */
fork()
{

	u.u_cdmap = zdmap;
	u.u_csmap = zdmap;
	if (swpexpand(u.u_dsize, u.u_ssize, &u.u_cdmap, &u.u_csmap) == 0) {
		u.u_r.r_val2 = 0;
		return;
	}
	fork1(0);
}

vfork()
{

	fork1(1);
}

fork1(isvfork)
	int isvfork;
{
	register struct proc *p1, *p2;
	register a;

	a = 0;
D 5
	p2 = NULL;
	for (p1 = proc; p1 < procNPROC; p1++) {
		if (p1->p_stat==NULL && p2==NULL)
			p2 = p1;
		else {
			if (p1->p_uid==u.u_uid && p1->p_stat!=NULL)
E 5
I 5
	if (u.u_uid != 0) {
		for (p1 = allproc; p1; p1 = p1->p_nxt)
			if (p1->p_uid == u.u_uid)
E 5
				a++;
D 5
		}
E 5
I 5
		for (p1 = zombproc; p1; p1 = p1->p_nxt)
			if (p1->p_uid == u.u_uid)
				a++;
E 5
	}
	/*
	 * Disallow if
	 *  No processes at all;
	 *  not su and too many procs owned; or
	 *  not su and would take last slot.
	 */
I 5
	p2 = freeproc;
E 5
	if (p2==NULL)
		tablefull("proc");
D 5
	if (p2==NULL || (u.u_uid!=0 && (p2==procNPROC-1 || a>MAXUPRC))) {
E 5
I 5
	if (p2==NULL || (u.u_uid!=0 && (p2->p_nxt == NULL || a>MAXUPRC))) {
E 5
		u.u_error = EAGAIN;
		if (!isvfork) {
D 12
			(void) vsexpand(0, &u.u_cdmap, 1);
			(void) vsexpand(0, &u.u_csmap, 1);
E 12
I 12
			(void) vsexpand((size_t)0, &u.u_cdmap, 1);
			(void) vsexpand((size_t)0, &u.u_csmap, 1);
E 12
		}
		goto out;
	}
	p1 = u.u_procp;
	if (newproc(isvfork)) {
		u.u_r.r_val1 = p1->p_pid;
		u.u_r.r_val2 = 1;  /* child */
D 7
		u.u_start = time.tv_sec;
E 7
I 7
		u.u_start = time;
E 7
		u.u_acflag = AFORK;
		return;
	}
	u.u_r.r_val1 = p2->p_pid;

out:
	u.u_r.r_val2 = 0;
}

/*
 * Create a new process-- the internal version of
 * sys fork.
 * It returns 1 in the new process, 0 in the old.
 */
newproc(isvfork)
	int isvfork;
{
D 5
	register struct proc *p;
E 5
	register struct proc *rpp, *rip;
	register int n;
	register struct file *fp;
I 5
	static int pidchecked = 0;
E 5

D 5
	p = NULL;
E 5
	/*
	 * First, just locate a slot for a process
	 * and copy the useful info from this process into it.
	 * The panic "cannot happen" because fork has already
	 * checked for the existence of a slot.
	 */
D 5
retry:
E 5
	mpid++;
I 5
retry:
E 5
	if (mpid >= 30000) {
D 5
		mpid = 0;
		goto retry;
E 5
I 5
		mpid = 100;
		pidchecked = 0;
E 5
	}
D 5
	for (rpp = proc; rpp < procNPROC; rpp++) {
		if (rpp->p_stat == NULL && p==NULL)
			p = rpp;
		if (rpp->p_pid==mpid || rpp->p_pgrp==mpid)
			goto retry;
E 5
I 5
	if (mpid >= pidchecked) {
		int doingzomb = 0;
I 6

E 6
		pidchecked = 30000;
		/*
		 * Scan the proc table to check whether this pid
		 * is in use.  Remember the lowest pid that's greater
		 * than mpid, so we can avoid checking for a while.
		 */
		rpp = allproc;
again:
		for (; rpp != NULL; rpp = rpp->p_nxt) {
D 6
			if (rpp->p_pid==mpid || rpp->p_pgrp==mpid) {
E 6
I 6
			if (rpp->p_pid == mpid || rpp->p_pgrp == mpid) {
E 6
				mpid++;
				if (mpid >= pidchecked)
					goto retry;
			}
D 6
			if ((rpp->p_pid > mpid) && (pidchecked > rpp->p_pid))
E 6
I 6
			if (rpp->p_pid > mpid && pidchecked > rpp->p_pid)
E 6
				pidchecked = rpp->p_pid;
D 6
			if ((rpp->p_pgrp > mpid) && (pidchecked > rpp->p_pgrp))
E 6
I 6
			if (rpp->p_pgrp > mpid && pidchecked > rpp->p_pgrp)
E 6
				pidchecked = rpp->p_pgrp;
		}
		if (!doingzomb) {
			doingzomb = 1;
			rpp = zombproc;
			goto again;
		}
E 5
	}
D 5
	if ((rpp = p) == NULL)
E 5
I 5
	if ((rpp = freeproc) == NULL)
E 5
		panic("no procs");

I 5
	freeproc = rpp->p_nxt;			/* off freeproc */
	rpp->p_nxt = allproc;			/* onto allproc */
	rpp->p_nxt->p_prev = &rpp->p_nxt;	/*   (allproc is never NULL) */
	rpp->p_prev = &allproc;
	allproc = rpp;

E 5
	/*
	 * Make a proc table entry for the new process.
	 */
	rip = u.u_procp;
#ifdef QUOTA
	rpp->p_quota = rip->p_quota;
	rpp->p_quota->q_cnt++;
#endif
I 14
#if defined(tahoe)
	rpp->p_ckey = rip->p_ckey;
	rpp->p_dkey = 0;
#endif
E 14
	rpp->p_stat = SIDL;
	timerclear(&rpp->p_realtimer.it_value);
D 2
	rpp->p_flag = SLOAD | (rip->p_flag & (SPAGI|SNUSIG));
E 2
I 2
	rpp->p_flag = SLOAD | (rip->p_flag & (SPAGI|SOUSIG));
E 2
	if (isvfork) {
		rpp->p_flag |= SVFORK;
		rpp->p_ndx = rip->p_ndx;
	} else
		rpp->p_ndx = rpp - proc;
	rpp->p_uid = rip->p_uid;
	rpp->p_pgrp = rip->p_pgrp;
	rpp->p_nice = rip->p_nice;
	rpp->p_textp = isvfork ? 0 : rip->p_textp;
	rpp->p_pid = mpid;
	rpp->p_ppid = rip->p_pid;
	rpp->p_pptr = rip;
	rpp->p_osptr = rip->p_cptr;
	if (rip->p_cptr)
		rip->p_cptr->p_ysptr = rpp;
	rpp->p_ysptr = NULL;
	rpp->p_cptr = NULL;
	rip->p_cptr = rpp;
	rpp->p_time = 0;
	rpp->p_cpu = 0;
D 2
	rpp->p_siga0 = rip->p_siga0;
	rpp->p_siga1 = rip->p_siga1;
	/* take along any pending signals, like stops? */
E 2
I 2
	rpp->p_sigmask = rip->p_sigmask;
	rpp->p_sigcatch = rip->p_sigcatch;
	rpp->p_sigignore = rip->p_sigignore;
	/* take along any pending signals like stops? */
E 2
	if (isvfork) {
		rpp->p_tsize = rpp->p_dsize = rpp->p_ssize = 0;
		rpp->p_szpt = clrnd(ctopt(UPAGES));
		forkstat.cntvfork++;
		forkstat.sizvfork += rip->p_dsize + rip->p_ssize;
	} else {
		rpp->p_tsize = rip->p_tsize;
		rpp->p_dsize = rip->p_dsize;
		rpp->p_ssize = rip->p_ssize;
		rpp->p_szpt = rip->p_szpt;
		forkstat.cntfork++;
		forkstat.sizfork += rip->p_dsize + rip->p_ssize;
	}
	rpp->p_rssize = 0;
	rpp->p_maxrss = rip->p_maxrss;
	rpp->p_wchan = 0;
	rpp->p_slptime = 0;
	rpp->p_pctcpu = 0;
	rpp->p_cpticks = 0;
	n = PIDHASH(rpp->p_pid);
D 5
	p->p_idhash = pidhash[n];
E 5
I 5
	rpp->p_idhash = pidhash[n];
E 5
	pidhash[n] = rpp - proc;
	multprog++;

	/*
	 * Increase reference counts on shared objects.
	 */
D 9
	for (n = 0; n < NOFILE; n++) {
E 9
I 9
	for (n = 0; n <= u.u_lastfile; n++) {
E 9
		fp = u.u_ofile[n];
		if (fp == NULL)
			continue;
		fp->f_count++;
D 3
		if (u.u_pofile[n]&UF_SHLOCK)
			((struct inode *)fp->f_data)->i_shlockc++;
		if (u.u_pofile[n]&UF_EXLOCK)
			((struct inode *)fp->f_data)->i_exlockc++;
E 3
	}
	u.u_cdir->i_count++;
	if (u.u_rdir)
		u.u_rdir->i_count++;

	/*
D 5
	 * Partially simulate the environment
	 * of the new process so that when it is actually
	 * created (by copying) it will look right.
E 5
	 * This begins the section where we must prevent the parent
	 * from being swapped.
	 */
	rip->p_flag |= SKEEP;
	if (procdup(rpp, isvfork))
		return (1);

	/*
	 * Make child runnable and add to run queue.
	 */
D 11
	(void) spl6();
E 11
I 11
	(void) splclock();
E 11
	rpp->p_stat = SRUN;
	setrq(rpp);
	(void) spl0();

	/*
	 * Cause child to take a non-local goto as soon as it runs.
	 * On older systems this was done with SSWAP bit in proc
	 * table; on VAX we use u.u_pcb.pcb_sswap so don't need
	 * to do rpp->p_flag |= SSWAP.  Actually do nothing here.
	 */
	/* rpp->p_flag |= SSWAP; */

	/*
	 * Now can be swapped.
	 */
	rip->p_flag &= ~SKEEP;

	/*
	 * If vfork make chain from parent process to child
	 * (where virtal memory is temporarily).  Wait for
	 * child to finish, steal virtual memory back,
	 * and wakeup child to let it die.
	 */
	if (isvfork) {
		u.u_procp->p_xlink = rpp;
		u.u_procp->p_flag |= SNOVM;
		while (rpp->p_flag & SVFORK)
			sleep((caddr_t)rpp, PZERO - 1);
		if ((rpp->p_flag & SLOAD) == 0)
			panic("newproc vfork");
		uaccess(rpp, Vfmap, &vfutl);
		u.u_procp->p_xlink = 0;
		vpassvm(rpp, u.u_procp, &vfutl, &u, Vfmap);
		u.u_procp->p_flag &= ~SNOVM;
		rpp->p_ndx = rpp - proc;
		rpp->p_flag |= SVFDONE;
		wakeup((caddr_t)rpp);
	}

	/*
	 * 0 return means parent.
	 */
	return (0);
}
E 1
