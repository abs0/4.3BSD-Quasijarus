h02649
s 00008/00000/00806
d D 7.3 86/12/14 14:52:28 sam 50 49
c add missing MMAP code from merge
e
s 00001/00001/00805
d D 7.2 86/11/03 11:59:50 karels 49 48
c merge in tahoe support
e
s 00001/00001/00805
d D 7.1 86/06/05 00:04:14 mckusick 48 47
c 4.3BSD release version
e
s 00006/00006/00800
d D 6.21 86/02/23 23:09:06 karels 47 46
c lint
e
s 00004/00006/00802
d D 6.20 86/02/20 15:33:23 karels 46 45
c use sigmask uniformly
e
s 00001/00001/00807
d D 6.19 85/09/18 09:32:47 karels 45 44
c lint
e
s 00001/00001/00807
d D 6.18 85/08/23 15:48:51 karels 44 43
c back to EPERM if killpg (not -1) can't do it
e
s 00007/00001/00801
d D 6.17 85/06/08 14:37:38 mckusick 43 42
c Add copyright
e
s 00002/00000/00800
d D 6.16 85/05/22 20:06:14 mckusick 42 41
c only dump core if user has read permission on the text
e
s 00005/00005/00795
d D 6.15 85/05/22 14:34:08 mckusick 41 40
c make signal semantics more like system V;
c non-super user can do `kill -1 1' to kill all processes run by them,
c return ESRCH instaed of EINVAL for `kill 0 1' when not in a process group
e
s 00000/00001/00800
d D 6.14 85/03/19 20:48:50 mckusick 40 39
c eliminate extraneous include of conf.h
e
s 00049/00034/00752
d D 6.13 85/03/13 20:06:01 mckusick 39 38
c rewritten kill code from sun!shannon
e
s 00005/00007/00781
d D 6.12 85/03/13 19:40:56 karels 38 37
c give SIGCHLD on stop even if traced (once only)
e
s 00012/00002/00776
d D 6.11 85/03/12 13:52:55 mckusick 37 36
c add another bit to sigvec() flags to disable system call restart
e
s 00000/00026/00778
d D 6.10 85/03/12 13:03:21 mckusick 36 35
c eliminate signal() system call interface
e
s 00002/00000/00802
d D 6.9 84/12/31 12:36:16 bloom 35 34
c Added SIGWINCH for windows
e
s 00001/00007/00801
d D 6.8 84/11/20 11:13:46 karels 34 33
c remove unused code
e
s 00039/00042/00769
d D 6.7 84/09/04 14:23:00 bloom 33 32
c mask macro moved to header file and name changed to sigmask
e
s 00017/00017/00794
d D 6.6 84/08/29 20:20:09 bloom 32 31
c Change to includes.  no more ../h
e
s 00029/00000/00782
d D 6.5 84/08/24 16:55:29 mckusick 31 30
c add `signal' as a system call
e
s 00006/00005/00776
d D 6.4 84/07/08 16:13:44 mckusick 30 29
c rework `namei' interface to eliminate global variables
e
s 00002/00004/00779
d D 6.3 84/05/22 11:45:02 karels 29 28
c linked lists of active, zombie and free procs; avoid linear proc
c searches wherever possible
e
s 00003/00001/00780
d D 6.2 83/09/08 10:48:45 mckusick 28 27
c If a process exists but has a different uid than the killer it should return
c EPERM rather than ESRCH. (Bill Shanon)
e
s 00000/00000/00781
d D 6.1 83/08/20 15:38:37 sam 27 26
c 4.2 distribution
e
s 00017/00008/00764
d D 5.24 83/08/20 15:38:13 sam 26 24
c from shannon; can't allow masked signals to be presented; 
c also, beware of ptrace taking child signal, then changing it to something
e
s 00000/00000/00772
d R 6.1 83/07/29 06:33:48 sam 25 24
c 4.2 distribution
e
s 00000/00001/00772
d D 5.23 83/06/24 00:26:21 sam 24 23
c crud from previous interface not deleted
e
s 00004/00001/00769
d D 5.22 83/06/21 20:35:40 sam 23 22
c change NOCOMPAT to COMPAT and make it work
e
s 00006/00005/00764
d D 5.21 83/06/10 21:23:27 sam 22 21
c beware of masked signals with STRC
e
s 00076/00033/00693
d D 5.20 83/06/09 21:59:32 sam 21 20
c "final" sigvec interface?
e
s 00144/00051/00582
d D 5.19 83/06/02 15:56:56 sam 20 18
c new signals
e
s 00000/00000/00633
d R 5.19 83/05/31 01:03:42 sam 19 18
c collect all the compatibility stuff in single files
e
s 00005/00003/00628
d D 5.18 83/05/30 19:28:11 sam 18 17
c kill with signal 0 allows for error checking without sending a signal 
c from shannon@sun.UUCP
e
s 00006/00101/00625
d D 5.17 83/05/27 12:47:09 sam 17 16
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00002/00002/00724
d D 5.16 83/05/21 15:34:33 sam 16 15
c disallow core files on setgid programs; make core files mode 644
e
s 00040/00046/00686
d D 5.15 82/12/28 19:50:39 sam 15 14
c kludge killpg so csh runs again
e
s 00001/00001/00731
d D 5.14 82/12/19 17:51:41 sam 14 13
c checking old value instead of new on signal call when 
c new action is to ignore (from Mike Karels)
e
s 00004/00003/00728
d D 5.13 82/12/17 11:44:41 sam 13 12
c sun merge
e
s 00003/00002/00728
d D 5.12 82/11/13 22:50:19 sam 12 11
c merge of 4.1b and 4.1c
e
s 00009/00005/00721
d D 5.11 82/10/31 14:25:58 root 11 10
c fixes from 68k
e
s 00002/00000/00724
d D 5.10 82/10/21 20:57:07 root 10 9
c lint
e
s 00007/00007/00717
d D 5.9 82/10/17 23:03:31 root 9 8
c lint
e
s 00001/00001/00723
d D 5.8 82/10/10 15:08:01 root 8 7
c split header files over to vax directories
e
s 00001/00030/00723
d D 5.7 82/09/08 08:04:26 root 7 6
c move oalarm, opause to here
e
s 00006/00006/00747
d D 5.6 82/09/06 22:49:21 root 6 5
c 
e
s 00021/00011/00732
d D 5.5 82/09/04 09:12:27 root 5 4
c new timer stuff, to be filled in kill and killpg
e
s 00023/00020/00720
d D 5.4 82/08/22 20:33:33 root 4 3
c use rdwri()
e
s 00001/00001/00739
d D 5.3 82/08/10 17:50:59 sam 3 2
c new itrunc
e
s 00100/00259/00640
d D 5.2 82/07/24 18:10:14 root 2 1
c merge with calder
e
s 00899/00000/00000
d D 5.1 82/07/15 20:12:50 root 1 0
c date and time created 82/07/15 20:12:50 by root
e
u
U
f b 
t
T
I 1
D 43
/*	%M%	%I%	%E%	*/
E 43
I 43
/*
D 48
 * Copyright (c) 1982 Regents of the University of California.
E 48
I 48
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 48
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 43

I 13
#include "../machine/reg.h"
#include "../machine/pte.h"
#include "../machine/psl.h"
I 49
#include "../machine/mtpr.h"
E 49

E 13
D 32
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
D 13
#include "../h/reg.h"
E 13
#include "../h/inode.h"
#include "../h/proc.h"
D 5
#include "../h/clock.h"
E 5
D 8
#include "../h/mtpr.h"
E 8
#include "../h/timeb.h"
#include "../h/times.h"
#include "../h/conf.h"
#include "../h/buf.h"
#include "../h/mount.h"
#include "../h/text.h"
#include "../h/seg.h"
D 13
#include "../h/pte.h"
#include "../h/psl.h"
E 13
#include "../h/vm.h"
D 5
#include "../h/vlimit.h"
E 5
#include "../h/acct.h"
I 4
#include "../h/uio.h"
I 7
#include "../h/kernel.h"
E 32
I 32
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "inode.h"
#include "proc.h"
#include "timeb.h"
#include "times.h"
D 40
#include "conf.h"
E 40
#include "buf.h"
#include "mount.h"
#include "text.h"
#include "seg.h"
#include "vm.h"
#include "acct.h"
#include "uio.h"
#include "kernel.h"
E 32
I 12
D 30
#include "../h/nami.h"
E 30
E 12
E 7
E 4

I 21
D 33
#define	mask(s)	(1 << ((s)-1))
#define	cantmask	(mask(SIGKILL)|mask(SIGCONT)|mask(SIGSTOP))
E 33
I 33
#define	cantmask	(sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP))
I 46
#define	stopsigmask	(sigmask(SIGSTOP)|sigmask(SIGTSTP)| \
			sigmask(SIGTTIN)|sigmask(SIGTTOU))
E 46
E 33

I 31
/*
D 36
 * Quick interface to signal handler.
 */
signal()
{
	register struct a {
		int	signo;
		int	(*handler)();	/* signal handler */
	} *uap = (struct a  *)u.u_ap;
	struct sigvec vec;
	register struct sigvec *sv = &vec;
	register int sig;

	sig = uap->signo;
	if (sig <= 0 || sig >= NSIG || sig == SIGKILL || sig == SIGSTOP ||
	    (sig == SIGCONT && uap->handler == SIG_IGN)) {
		u.u_error = EINVAL;
		return;
	}
	sv->sv_handler = uap->handler;
	sv->sv_mask = 0;
	sv->sv_onstack = 0;
	u.u_r.r_val1 = (int)u.u_signal[sig];
	setsigvec(sig, sv);
}

/*
E 36
 * Generalized interface signal handler.
 */
E 31
E 21
D 2
ssig()
E 2
I 2
D 20
/* KILL CODE SHOULDNT KNOW ABOUT PROCESS INTERNALS !?! */

E 20
sigvec()
E 2
{
I 20
D 21
	struct a {
E 21
I 21
	register struct a {
E 21
		int	signo;
D 21
		int	(*sighandler)();
		int	sigmask;
E 21
I 21
		struct	sigvec *nsv;
		struct	sigvec *osv;
E 21
	} *uap = (struct a  *)u.u_ap;
I 21
	struct sigvec vec;
	register struct sigvec *sv;
E 21
	register int sig;
I 37
	int bit;
E 37
E 20
D 2
	register int (*f)();
	struct a {
		int	signo;
		int	(*fun)();
	} *uap;
	register struct proc *p = u.u_procp;
	register a;
	long sigmask;
E 2

I 20
	sig = uap->signo;
D 21
	if (sig <= 0 || sig >= NSIG || sig == SIGKILL || sig == SIGSTOP ||
	    (sig == SIGCONT && uap->sighandler == SIG_IGN)) {
E 21
I 21
	if (sig <= 0 || sig >= NSIG || sig == SIGKILL || sig == SIGSTOP) {
E 21
		u.u_error = EINVAL;
		return;
	}
D 21
	setsignal(sig, uap->sighandler, uap->sigmask);
E 21
I 21
	sv = &vec;
	if (uap->osv) {
		sv->sv_handler = u.u_signal[sig];
		sv->sv_mask = u.u_sigmask[sig];
D 33
		sv->sv_onstack = (u.u_sigonstack & mask(sig)) != 0;
E 33
I 33
D 37
		sv->sv_onstack = (u.u_sigonstack & sigmask(sig)) != 0;
E 37
I 37
		bit = sigmask(sig);
		sv->sv_flags = 0;
		if ((u.u_sigonstack & bit) != 0)
			sv->sv_flags |= SV_ONSTACK;
		if ((u.u_sigintr & bit) != 0)
			sv->sv_flags |= SV_INTERRUPT;
E 37
E 33
		u.u_error =
		    copyout((caddr_t)sv, (caddr_t)uap->osv, sizeof (vec));
		if (u.u_error)
			return;
	}
	if (uap->nsv) {
		u.u_error =
		    copyin((caddr_t)uap->nsv, (caddr_t)sv, sizeof (vec));
		if (u.u_error)
			return;
		if (sig == SIGCONT && sv->sv_handler == SIG_IGN) {
			u.u_error = EINVAL;
			return;
		}
		setsigvec(sig, sv);
	}
E 21
E 20
D 2
	uap = (struct a *)u.u_ap;
	a = uap->signo & SIGNUMMASK;
	f = uap->fun;
	if (a<=0 || a>=NSIG || a==SIGKILL || a==SIGSTOP ||
	    a==SIGCONT && (f == SIG_IGN || f == SIG_HOLD)) {
		u.u_error = EINVAL;
		return;
	}
	if ((uap->signo &~ SIGNUMMASK) || (f != SIG_DFL && f != SIG_IGN &&
	    SIGISDEFER(f)))
		u.u_procp->p_flag |= SNUSIG;
	/* 
	 * Don't clobber registers if we are to simulate
	 * a ret+rti.
	 */
	if ((uap->signo&SIGDORTI) == 0)
		u.u_r.r_val1 = (int)u.u_signal[a];
	/*
	 * Change setting atomically.
	 */
	(void) spl6();
	sigmask = 1L << (a-1);
	if (u.u_signal[a] == SIG_IGN)
		p->p_sig &= ~sigmask;		/* never to be seen again */
	u.u_signal[a] = f;
	if (f != SIG_DFL && f != SIG_IGN && f != SIG_HOLD)
		f = SIG_CATCH;
	if ((int)f & 1)
		p->p_siga0 |= sigmask;
	else
		p->p_siga0 &= ~sigmask;
	if ((int)f & 2)
		p->p_siga1 |= sigmask;
	else
		p->p_siga1 &= ~sigmask;
	(void) spl0();
	/*
	 * Now handle options.
	 */
	if (uap->signo & SIGDOPAUSE) {
		/*
		 * Simulate a PDP11 style wait instrution which
		 * atomically lowers priority, enables interrupts
		 * and hangs.
		 */
		pause();
		/*NOTREACHED*/
	}
	if (uap->signo & SIGDORTI)
		u.u_eosys = SIMULATERTI;
E 2
}

I 20
D 21
setsignal(sig, action, sigmask)
	int sig, (*action)(), sigmask;
E 21
I 21
setsigvec(sig, sv)
	int sig;
	register struct sigvec *sv;
E 21
{
	register struct proc *p;
D 21
	register int mask;
E 21
I 21
	register int bit;
E 21

D 21
	u.u_r.r_val1 = (int)u.u_signal[sig];
	mask = 1 << (sig - 1);
E 21
I 21
D 33
	bit = mask(sig);
E 33
I 33
	bit = sigmask(sig);
E 33
E 21
	p = u.u_procp;
	/*
	 * Change setting atomically.
	 */
D 33
	(void) spl6();
E 33
I 33
	(void) splhigh();
E 33
D 21
	u.u_signal[sig] = action;
	u.u_sigmask[sig] = sigmask;
	if (action == SIG_IGN) {
		p->p_sig &= ~mask;		/* never to be seen again */
		p->p_sigignore |= mask;
		p->p_sigcatch &= ~mask;
E 21
I 21
	u.u_signal[sig] = sv->sv_handler;
	u.u_sigmask[sig] = sv->sv_mask &~ cantmask;
D 37
	if (sv->sv_onstack)
E 37
I 37
	if (sv->sv_flags & SV_INTERRUPT)
		u.u_sigintr |= bit;
	else
		u.u_sigintr &= ~bit;
	if (sv->sv_flags & SV_ONSTACK)
E 37
		u.u_sigonstack |= bit;
	else
		u.u_sigonstack &= ~bit;
	if (sv->sv_handler == SIG_IGN) {
		p->p_sig &= ~bit;		/* never to be seen again */
		p->p_sigignore |= bit;
		p->p_sigcatch &= ~bit;
E 21
	} else {
D 21
		p->p_sigignore &= ~mask;
		if (action == SIG_DFL)
			p->p_sigcatch &= ~mask;
E 21
I 21
		p->p_sigignore &= ~bit;
		if (sv->sv_handler == SIG_DFL)
			p->p_sigcatch &= ~bit;
E 21
		else
D 21
			p->p_sigcatch |= mask;
E 21
I 21
			p->p_sigcatch |= bit;
E 21
	}
	(void) spl0();
}

E 20
D 2
kill()
E 2
I 2
sigblock()
E 2
{
I 20
	struct a {
D 21
		int	mask;
E 21
I 21
D 33
		int	sigmask;
E 33
I 33
		int	mask;
E 33
E 21
	} *uap = (struct a *)u.u_ap;
D 21
	struct proc *p = u.u_procp;
E 21
I 21
	register struct proc *p = u.u_procp;
E 21
E 20
I 2

I 20
D 33
	(void) spl6();
E 33
I 33
	(void) splhigh();
E 33
	u.u_r.r_val1 = p->p_sigmask;
D 21
	p->p_sigmask |= uap->mask;
E 21
I 21
D 33
	p->p_sigmask |= uap->sigmask &~ cantmask;
E 33
I 33
	p->p_sigmask |= uap->mask &~ cantmask;
E 33
E 21
	(void) spl0();
E 20
}

sigsetmask()
{
I 20
	struct a {
D 21
		int	mask;
E 21
I 21
D 33
		int	sigmask;
E 33
I 33
		int	mask;
E 33
E 21
	} *uap = (struct a *)u.u_ap;
	register struct proc *p = u.u_procp;
E 20

I 20
D 33
	(void) spl6();
E 33
I 33
	(void) splhigh();
E 33
	u.u_r.r_val1 = p->p_sigmask;
D 21
	p->p_sigmask = uap->mask;
E 21
I 21
D 33
	p->p_sigmask = uap->sigmask &~ cantmask;
E 33
I 33
	p->p_sigmask = uap->mask &~ cantmask;
E 33
E 21
	(void) spl0();
E 20
}

sigpause()
{
I 20
	struct a {
D 21
		int	mask;
E 21
I 21
D 33
		int	sigmask;
E 33
I 33
		int	mask;
E 33
E 21
	} *uap = (struct a *)u.u_ap;
	register struct proc *p = u.u_procp;
E 20

I 20
	/*
	 * When returning from sigpause, we want
	 * the old mask to be restored after the
	 * signal handler has finished.  Thus, we
	 * save it here and mark the proc structure
	 * to indicate this (should be in u.).
	 */
	u.u_oldmask = p->p_sigmask;
	p->p_flag |= SOMASK;
D 21
	p->p_sigmask = uap->mask;
E 21
I 21
D 33
	p->p_sigmask = uap->sigmask &~ cantmask;
E 33
I 33
	p->p_sigmask = uap->mask &~ cantmask;
E 33
E 21
	for (;;)
		sleep((caddr_t)&u, PSLEP);
	/*NOTREACHED*/
E 20
}
I 21
#undef cantmask
D 33
#undef mask
E 33
E 21

sigstack()
{
I 20
D 21
	struct a {
E 21
I 21
	register struct a {
E 21
D 24
		caddr_t	asp;
E 24
D 21
		int	onsigstack;
E 21
I 21
		struct	sigstack *nss;
		struct	sigstack *oss;
E 21
	} *uap = (struct a *)u.u_ap;
I 21
	struct sigstack ss;
E 21
E 20

I 20
D 21
	u.u_sigstack = uap->asp;
	u.u_onsigstack = uap->onsigstack;
E 21
I 21
	if (uap->oss) {
		u.u_error = copyout((caddr_t)&u.u_sigstack, (caddr_t)uap->oss, 
		    sizeof (struct sigstack));
		if (u.u_error)
			return;
	}
	if (uap->nss) {
		u.u_error =
		    copyin((caddr_t)uap->nss, (caddr_t)&ss, sizeof (ss));
		if (u.u_error == 0)
			u.u_sigstack = ss;
	}
E 21
E 20
}

I 23
D 39
/* KILL SHOULD BE UPDATED */

E 39
E 23
I 10
D 20
#ifdef notdef
E 20
E 10
I 5
kill()
{
I 20
	register struct a {
		int	pid;
		int	signo;
	} *uap = (struct a *)u.u_ap;
I 39
	register struct proc *p;
E 39
E 20

I 20
D 23
	u.u_error = kill1(0, uap->signo, uap->pid);
E 23
I 23
D 39
	u.u_error = kill1(uap->signo < 0,
		uap->signo < 0 ? -uap->signo : uap->signo, uap->pid);
E 39
I 39
	if (uap->signo < 0 || uap->signo > NSIG) {
		u.u_error = EINVAL;
		return;
	}
	if (uap->pid > 0) {
		/* kill single process */
		p = pfind(uap->pid);
		if (p == 0) {
			u.u_error = ESRCH;
			return;
		}
		if (u.u_uid && u.u_uid != p->p_uid)
			u.u_error = EPERM;
		else if (uap->signo)
			psignal(p, uap->signo);
		return;
	}
	switch (uap->pid) {
	case -1:		/* broadcast signal */
D 41
		if (suser())
			u.u_error = killpg1(uap->signo, 0, 1);
E 41
I 41
		u.u_error = killpg1(uap->signo, 0, 1);
E 41
		break;
	case 0:			/* signal own process group */
		u.u_error = killpg1(uap->signo, 0, 0);
		break;
	default:		/* negative explicit process group */
		u.u_error = killpg1(uap->signo, -uap->pid, 0);
		break;
	}
	return;
E 39
E 23
E 20
}
I 10
D 20
#endif
E 20
E 10

I 15
D 17
/* TEMPORARY */
E 17
E 15
killpg()
{
I 15
	register struct a {
		int	pgrp;
		int	signo;
	} *uap = (struct a *)u.u_ap;
E 15

I 15
D 17
	u.u_error = okill1(1, uap->signo, uap->pgrp);
E 17
I 17
D 39
	u.u_error = kill1(1, uap->signo, uap->pgrp);
E 39
I 39
	if (uap->signo < 0 || uap->signo > NSIG) {
		u.u_error = EINVAL;
		return;
	}
	u.u_error = killpg1(uap->signo, uap->pgrp, 0);
E 39
E 17
E 15
}

I 20
/* KILL CODE SHOULDNT KNOW ABOUT PROCESS INTERNALS !?! */

E 20
E 5
D 17
/* BEGIN DEFUNCT */
okill()
{
E 2
D 15
	register struct proc *p;
	register a, sig;
E 15
	register struct a {
		int	pid;
		int	signo;
D 15
	} *uap;
	int f, priv;
E 15
I 15
	} *uap = (struct a *)u.u_ap;
E 15

D 15
	uap = (struct a *)u.u_ap;
	f = 0;
	a = uap->pid;
	priv = 0;
	sig = uap->signo;
	if (sig < 0)
		/*
		 * A negative signal means send to process group.
		 */
		uap->signo = -uap->signo;
	if (uap->signo == 0 || uap->signo > NSIG) {
		u.u_error = EINVAL;
		return;
E 15
I 15
	u.u_error = okill1(uap->signo < 0,
		uap->signo < 0 ? -uap->signo : uap->signo, uap->pid);
}

okill1(ispgrp, signo, who)
E 17
I 17
D 39
kill1(ispgrp, signo, who)
E 17
	int ispgrp, signo, who;
E 39
I 39
killpg1(signo, pgrp, all)
	int signo, pgrp, all;
E 39
{
	register struct proc *p;
D 39
	int f, priv = 0;
E 39
I 39
	int f, error = 0;
E 39

D 18
	if (signo == 0 || signo > NSIG)
E 18
I 18
D 39
	if (signo < 0 || signo > NSIG)
E 18
		return (EINVAL);
	if (who > 0 && !ispgrp) {
		p = pfind(who);
D 28
		if (p == 0 || u.u_uid && u.u_uid != p->p_uid)
E 28
I 28
		if (p == 0)
E 28
			return (ESRCH);
I 28
		if (u.u_uid && u.u_uid != p->p_uid)
			return (EPERM);
E 28
D 18
		psignal(p, signo);
E 18
I 18
		if (signo)
			psignal(p, signo);
E 18
		return (0);
E 15
	}
D 15
	if (a > 0 && sig > 0) {
		p = pfind(a);
		if (p == 0 || u.u_uid && u.u_uid != p->p_uid) {
			u.u_error = ESRCH;
			return;
		}
		psignal(p, uap->signo);
		return;
	}
	if (a==-1 && u.u_uid==0) {
		priv++;
		a = 0;
		sig = -1;		/* like sending to pgrp */
	} else if (a==0) {
E 15
I 15
	if (who == -1 && u.u_uid == 0)
		priv++, who = 0, ispgrp = 1;	/* like sending to pgrp */
	else if (who == 0) {
E 39
I 39
	if (!all && pgrp == 0) {
E 39
E 15
		/*
		 * Zero process id means send to my process group.
		 */
D 15
		sig = -1;
		a = u.u_procp->p_pgrp;
		if (a == 0) {
			u.u_error = EINVAL;
			return;
		}
E 15
I 15
D 39
		ispgrp = 1;
		who = u.u_procp->p_pgrp;
		if (who == 0)
E 39
I 39
		pgrp = u.u_procp->p_pgrp;
		if (pgrp == 0)
E 39
D 41
			return (EINVAL);
E 41
I 41
			return (ESRCH);
E 41
E 15
	}
D 15
	for(p = proc; p < procNPROC; p++) {
E 15
I 15
D 29
	for (f = 0, p = proc; p < procNPROC; p++) {
E 15
		if (p->p_stat == NULL)
			continue;
E 29
I 29
	for (f = 0, p = allproc; p != NULL; p = p->p_nxt) {
E 29
D 15
		if (sig > 0) {
			if (p->p_pid != a)
E 15
I 15
D 39
		if (!ispgrp) {
			if (p->p_pid != who)
E 15
				continue;
D 15
		} else if (p->p_pgrp!=a && priv==0 || p->p_ppid==0 ||
		    (p->p_flag&SSYS) || (priv && p==u.u_procp))
E 15
I 15
		} else if (p->p_pgrp != who && priv == 0 || p->p_ppid == 0 ||
		    (p->p_flag&SSYS) || (priv && p == u.u_procp))
E 39
I 39
		if ((p->p_pgrp != pgrp && !all) || p->p_ppid == 0 ||
		    (p->p_flag&SSYS) || (all && p == u.u_procp))
E 39
E 15
			continue;
I 39
D 41
		f++;
E 41
E 39
		if (u.u_uid != 0 && u.u_uid != p->p_uid &&
D 15
		    (uap->signo != SIGCONT || !inferior(p)))
E 15
I 15
D 39
		    (signo != SIGCONT || !inferior(p)))
E 39
I 39
		    (signo != SIGCONT || !inferior(p))) {
D 41
			error = EPERM;
E 41
I 41
			if (!all)
				error = EPERM;
E 41
E 39
E 15
			continue;
D 39
		f++;
E 39
I 39
		}
I 41
		f++;
E 41
E 39
D 15
		psignal(p, uap->signo);
E 15
I 15
D 18
		psignal(p, signo);
E 18
I 18
		if (signo)
			psignal(p, signo);
E 18
E 15
	}
D 15
	if (f == 0)
		u.u_error = ESRCH;
E 15
I 15
D 17
	return (f == 0? ESRCH : 0);
E 17
I 17
D 39
	return (f == 0 ? ESRCH : 0);
E 39
I 39
D 44
	return (f == 0 ? ESRCH : error);
E 44
I 44
	return (error ? error : (f == 0 ? ESRCH : 0));
E 44
E 39
E 17
E 15
}

D 2
/*
 * Priority for tracing
 */
#define	IPCPRI	PZERO
E 2
I 2
D 17
ossig()
{
	register int (*f)();
	struct a {
		int	signo;
		int	(*fun)();
	} *uap;
	register struct proc *p = u.u_procp;
	register a;
	long sigmask;
E 2

D 2
/*
 * Tracing variables.
 * Used to pass trace command from
 * parent to child being traced.
 * This data base cannot be
 * shared and is locked
 * per user.
 */
struct {
	int	ip_lock;
	int	ip_req;
	int	*ip_addr;
	int	ip_data;
} ipc;
E 2
I 2
	uap = (struct a *)u.u_ap;
	a = uap->signo & SIGNUMMASK;
	f = uap->fun;
	if (a<=0 || a>=NSIG || a==SIGKILL || a==SIGSTOP ||
	    a==SIGCONT && (f == SIG_IGN || f == SIG_HOLD)) {
		u.u_error = EINVAL;
		return;
	}
	if ((uap->signo &~ SIGNUMMASK) || (f != SIG_DFL && f != SIG_IGN &&
	    SIGISDEFER(f)))
		u.u_procp->p_flag |= SNUSIG;
	/* 
	 * Don't clobber registers if we are to simulate
	 * a ret+rti.
	 */
	if ((uap->signo&SIGDORTI) == 0)
		u.u_r.r_val1 = (int)u.u_signal[a];
	/*
	 * Change setting atomically.
	 */
	(void) spl6();
	sigmask = 1L << (a-1);
D 14
	if (u.u_signal[a] == SIG_IGN)
E 14
I 14
	if (f == SIG_IGN)
E 14
		p->p_sig &= ~sigmask;		/* never to be seen again */
	u.u_signal[a] = f;
	if (f != SIG_DFL && f != SIG_IGN && f != SIG_HOLD)
		f = SIG_CATCH;
	if ((int)f & 1)
		p->p_siga0 |= sigmask;
	else
		p->p_siga0 &= ~sigmask;
	if ((int)f & 2)
		p->p_siga1 |= sigmask;
	else
		p->p_siga1 &= ~sigmask;
	(void) spl0();
	/*
	 * Now handle options.
	 */
	if (uap->signo & SIGDOPAUSE) {
		/*
		 * Simulate a PDP11 style wait instrution which
		 * atomically lowers priority, enables interrupts
		 * and hangs.
		 */
		opause();
		/*NOTREACHED*/
	}
	if (uap->signo & SIGDORTI)
		u.u_eosys = SIMULATERTI;
}
E 2

E 17
/*
 * Send the specified signal to
 * all processes with 'pgrp' as
 * process group.
D 20
 * Called by tty.c for quits and
 * interrupts.
E 20
 */
gsignal(pgrp, sig)
	register int pgrp;
{
	register struct proc *p;

	if (pgrp == 0)
		return;
D 29
	for(p = proc; p < procNPROC; p++)
E 29
I 29
	for (p = allproc; p != NULL; p = p->p_nxt)
E 29
		if (p->p_pgrp == pgrp)
			psignal(p, sig);
}

/*
 * Send the specified signal to
 * the specified process.
 */
psignal(p, sig)
	register struct proc *p;
	register int sig;
{
	register int s;
	register int (*action)();
D 20
	long sigmask;
E 20
I 20
D 33
	int sigmask;
E 33
I 33
	int mask;
E 33
E 20

	if ((unsigned)sig >= NSIG)
		return;
D 20
	sigmask = (1L << (sig-1));
E 20
I 20
D 33
	sigmask = 1 << (sig-1);
E 33
I 33
	mask = sigmask(sig);
E 33
E 20

	/*
	 * If proc is traced, always give parent a chance.
D 20
	 * Otherwise get the signal action from the bits in the proc table.
E 20
	 */
	if (p->p_flag & STRC)
		action = SIG_DFL;
	else {
D 20
		s = (p->p_siga1&sigmask) != 0;
		s <<= 1;
		s |= (p->p_siga0&sigmask) != 0;
		action = (int(*)())s;
E 20
		/*
D 20
		 * If the signal is ignored, we forget about it immediately.
E 20
I 20
		 * If the signal is being ignored,
		 * then we forget about it immediately.
E 20
		 */
D 20
		if (action == SIG_IGN)
E 20
I 20
D 33
		if (p->p_sigignore & sigmask)
E 33
I 33
		if (p->p_sigignore & mask)
E 33
E 20
			return;
I 20
D 33
		if (p->p_sigmask & sigmask)
E 33
I 33
		if (p->p_sigmask & mask)
E 33
			action = SIG_HOLD;
D 33
		else if (p->p_sigcatch & sigmask)
E 33
I 33
		else if (p->p_sigcatch & mask)
E 33
			action = SIG_CATCH;
		else
			action = SIG_DFL;
E 20
	}
D 33
#define mask(sig)	(1<<(sig-1))
#define	stops	(mask(SIGSTOP)|mask(SIGTSTP)|mask(SIGTTIN)|mask(SIGTTOU))
E 33
I 33
D 46
#define	stops	(sigmask(SIGSTOP)|sigmask(SIGTSTP)| \
			sigmask(SIGTTIN)|sigmask(SIGTTOU))
E 46
E 33
	if (sig) {
D 33
		p->p_sig |= sigmask;
E 33
I 33
		p->p_sig |= mask;
E 33
		switch (sig) {

		case SIGTERM:
D 20
			if ((p->p_flag&STRC) != 0 || action != SIG_DFL)
E 20
I 20
			if ((p->p_flag&STRC) || action != SIG_DFL)
E 20
				break;
			/* fall into ... */

		case SIGKILL:
			if (p->p_nice > NZERO)
				p->p_nice = NZERO;
			break;

		case SIGCONT:
D 46
			p->p_sig &= ~stops;
E 46
I 46
			p->p_sig &= ~stopsigmask;
E 46
			break;

		case SIGSTOP:
		case SIGTSTP:
		case SIGTTIN:
		case SIGTTOU:
D 33
			p->p_sig &= ~mask(SIGCONT);
E 33
I 33
			p->p_sig &= ~sigmask(SIGCONT);
E 33
			break;
		}
	}
D 33
#undef mask
E 33
D 46
#undef stops
E 46
	/*
	 * Defer further processing for signals which are held.
	 */
	if (action == SIG_HOLD)
		return;
D 33
	s = spl6();
E 33
I 33
	s = splhigh();
E 33
	switch (p->p_stat) {

	case SSLEEP:
		/*
		 * If process is sleeping at negative priority
		 * we can't interrupt the sleep... the signal will
		 * be noticed when the process returns through
		 * trap() or syscall().
		 */
		if (p->p_pri <= PZERO)
			goto out;
		/*
		 * Process is sleeping and traced... make it runnable
		 * so it can discover the signal in issig() and stop
		 * for the parent.
		 */
		if (p->p_flag&STRC)
			goto run;
		switch (sig) {

		case SIGSTOP:
		case SIGTSTP:
		case SIGTTIN:
		case SIGTTOU:
			/*
			 * These are the signals which by default
			 * stop a process.
			 */
			if (action != SIG_DFL)
				goto run;
			/*
			 * Don't clog system with children of init
			 * stopped from the keyboard.
			 */
			if (sig != SIGSTOP && p->p_pptr == &proc[1]) {
				psignal(p, SIGKILL);
D 33
				p->p_sig &= ~sigmask;
E 33
I 33
				p->p_sig &= ~mask;
E 33
				splx(s);
				return;
			}
			/*
			 * If a child in vfork(), stopping could
			 * cause deadlock.
			 */
			if (p->p_flag&SVFORK)
				goto out;
D 33
			p->p_sig &= ~sigmask;
E 33
I 33
			p->p_sig &= ~mask;
E 33
			p->p_cursig = sig;
I 38
			psignal(p->p_pptr, SIGCHLD);
E 38
			stop(p);
			goto out;

		case SIGIO:
		case SIGURG:
		case SIGCHLD:
I 35
		case SIGWINCH:
E 35
			/*
			 * These signals are special in that they
			 * don't get propogated... if the process
			 * isn't interested, forget it.
			 */
			if (action != SIG_DFL)
				goto run;
D 33
			p->p_sig &= ~sigmask;		/* take it away */
E 33
I 33
			p->p_sig &= ~mask;		/* take it away */
E 33
			goto out;

		default:
			/*
			 * All other signals cause the process to run
			 */
			goto run;
		}
		/*NOTREACHED*/

	case SSTOP:
		/*
		 * If traced process is already stopped,
		 * then no further action is necessary.
		 */
		if (p->p_flag&STRC)
			goto out;
		switch (sig) {

		case SIGKILL:
			/*
			 * Kill signal always sets processes running.
			 */
			goto run;

		case SIGCONT:
			/*
			 * If the process catches SIGCONT, let it handle
			 * the signal itself.  If it isn't waiting on
			 * an event, then it goes back to run state.
			 * Otherwise, process goes back to sleep state.
			 */
			if (action != SIG_DFL || p->p_wchan == 0)
				goto run;
			p->p_stat = SSLEEP;
			goto out;

		case SIGSTOP:
		case SIGTSTP:
		case SIGTTIN:
		case SIGTTOU:
			/*
			 * Already stopped, don't need to stop again.
			 * (If we did the shell could get confused.)
			 */
D 33
			p->p_sig &= ~sigmask;		/* take it away */
E 33
I 33
			p->p_sig &= ~mask;		/* take it away */
E 33
			goto out;

		default:
			/*
			 * If process is sleeping interruptibly, then
			 * unstick it so that when it is continued
			 * it can look at the signal.
			 * But don't setrun the process as its not to
			 * be unstopped by the signal alone.
			 */
			if (p->p_wchan && p->p_pri > PZERO)
				unsleep(p);
			goto out;
		}
		/*NOTREACHED*/

	default:
		/*
		 * SRUN, SIDL, SZOMB do nothing with the signal,
		 * other than kicking ourselves if we are running.
		 * It will either never be noticed, or noticed very soon.
		 */
		if (p == u.u_procp && !noproc)
I 8
D 49
#include "../vax/mtpr.h"
E 49
E 8
			aston();
		goto out;
	}
	/*NOTREACHED*/
run:
	/*
	 * Raise priority to at least PUSER.
	 */
	if (p->p_pri > PUSER)
D 34
		if ((p != u.u_procp || noproc) && p->p_stat == SRUN &&
		    (p->p_flag & SLOAD)) {
			remrq(p);
			p->p_pri = PUSER;
			setrq(p);
		} else
			p->p_pri = PUSER;
E 34
I 34
		p->p_pri = PUSER;
E 34
	setrun(p);
out:
	splx(s);
}

/*
 * Returns true if the current
 * process has a signal to process.
 * The signal to process is put in p_cursig.
 * This is asked at least once each time a process enters the
 * system (though this can usually be done without actually
 * calling issig by checking the pending signal masks.)
 * A signal does not do anything
 * directly to a process; it sets
 * a flag that asks the process to
 * do something to itself.
 */
issig()
{
	register struct proc *p;
	register int sig;
D 20
	long sigbits;
	long sigmask;
E 20
I 20
D 33
	int sigbits, sigmask;
E 33
I 33
	int sigbits, mask;
E 33
E 20

	p = u.u_procp;
	for (;;) {
D 26
		sigbits = p->p_sig;
E 26
I 26
		sigbits = p->p_sig &~ p->p_sigmask;
E 26
		if ((p->p_flag&STRC) == 0)
D 20
			sigbits &= ~p->p_ignsig;
E 20
I 20
D 26
			sigbits &= ~(p->p_sigignore | p->p_sigmask);
E 26
I 26
			sigbits &= ~p->p_sigignore;
E 26
E 20
		if (p->p_flag&SVFORK)
D 46
#define bit(a) (1<<(a-1))
			sigbits &= ~(bit(SIGSTOP)|bit(SIGTSTP)|bit(SIGTTIN)|bit(SIGTTOU));
E 46
I 46
			sigbits &= ~stopsigmask;
E 46
		if (sigbits == 0)
			break;
D 20
		sig = ffs((int)sigbits);
		sigmask = 1L << (sig-1);
E 20
I 20
D 47
		sig = ffs(sigbits);
E 47
I 47
		sig = ffs((long)sigbits);
E 47
D 33
		sigmask = 1 << (sig-1);
E 20
		p->p_sig &= ~sigmask;		/* take the signal! */
E 33
I 33
		mask = sigmask(sig);
		p->p_sig &= ~mask;		/* take the signal! */
E 33
		p->p_cursig = sig;
D 20
		if (p->p_flag&STRC && (p->p_flag&SVFORK)==0) {
E 20
I 20
		if (p->p_flag&STRC && (p->p_flag&SVFORK) == 0) {
E 20
			/*
			 * If traced, always stop, and stay
			 * stopped until released by the parent.
			 */
I 38
			psignal(p->p_pptr, SIGCHLD);
E 38
			do {
				stop(p);
				swtch();
			} while (!procxmt() && p->p_flag&STRC);

			/*
D 22
			 * If the traced bit got turned off,
			 * then put the signal taken above back into p_sig
			 * and go back up to the top to rescan signals.
			 * This ensures that siga0 and u_signal are consistent.
E 22
I 22
D 26
			 * If the traced bit got turned off or signal
			 * is being masked, then put the signal taken
			 * above back into p_sig and go back up to the
			 * top to rescan signals.  This ensures that
			 * p_sig* and u_signal are consistent.
E 26
I 26
			 * If the traced bit got turned off,
			 * then put the signal taken above back into p_sig
			 * and go back up to the top to rescan signals.
			 * This ensures that p_sig* and u_signal are consistent.
E 26
E 22
			 */
D 22
			if ((p->p_flag&STRC) == 0) {
E 22
I 22
D 26
			if ((p->p_flag&STRC) == 0 || (p->p_sigmask & sigmask)) {
E 26
I 26
			if ((p->p_flag&STRC) == 0) {
E 26
E 22
D 33
				p->p_sig |= sigmask;
E 33
I 33
				p->p_sig |= mask;
E 33
				continue;
			}

			/*
			 * If parent wants us to take the signal,
			 * then it will leave it in p->p_cursig;
			 * otherwise we just look for signals again.
			 */
			sig = p->p_cursig;
			if (sig == 0)
				continue;
I 26

			/*
			 * If signal is being masked put it back
			 * into p_sig and look for other signals.
			 */
D 33
			sigmask = 1 << (sig-1);
			if (p->p_sigmask & sigmask) {
				p->p_sig |= sigmask;
E 33
I 33
			mask = sigmask(sig);
			if (p->p_sigmask & mask) {
				p->p_sig |= mask;
E 33
				continue;
			}
E 26
		}
D 45
		switch (u.u_signal[sig]) {
E 45
I 45
		switch ((int)u.u_signal[sig]) {
E 45

		case SIG_DFL:
			/*
			 * Don't take default actions on system processes.
			 */
			if (p->p_ppid == 0)
				break;
			switch (sig) {

			case SIGTSTP:
			case SIGTTIN:
			case SIGTTOU:
				/*
				 * Children of init aren't allowed to stop
				 * on signals from the keyboard.
				 */
				if (p->p_pptr == &proc[1]) {
					psignal(p, SIGKILL);
					continue;
				}
				/* fall into ... */

			case SIGSTOP:
				if (p->p_flag&STRC)
					continue;
I 38
				psignal(p->p_pptr, SIGCHLD);
E 38
				stop(p);
				swtch();
				continue;

			case SIGCONT:
			case SIGCHLD:
I 20
			case SIGURG:
I 21
			case SIGIO:
I 35
			case SIGWINCH:
E 35
E 21
E 20
				/*
				 * These signals are normally not
				 * sent if the action is the default.
				 */
				continue;		/* == ignore */

			default:
				goto send;
			}
			/*NOTREACHED*/

		case SIG_HOLD:
		case SIG_IGN:
			/*
			 * Masking above should prevent us
			 * ever trying to take action on a held
			 * or ignored signal, unless process is traced.
			 */
			if ((p->p_flag&STRC) == 0)
				printf("issig\n");
			continue;

		default:
			/*
			 * This signal has an action, let
			 * psig process it.
			 */
			goto send;
		}
		/*NOTREACHED*/
	}
	/*
	 * Didn't find a signal to send.
	 */
	p->p_cursig = 0;
	return (0);

send:
	/*
	 * Let psig process the signal.
	 */
	return (sig);
}

D 2
#ifndef vax
ffs(mask)
	register long mask;
{
	register int i;

	for(i=1; i<NSIG; i++) {
		if (mask & 1)
			return (i);
		mask >>= 1;
	}
	return (0);
}
#endif

E 2
/*
 * Put the argument process into the stopped
D 38
 * state and notify the parent via wakeup and/or signal.
E 38
I 38
 * state and notify the parent via wakeup.
 * Signals are handled elsewhere.
E 38
 */
stop(p)
	register struct proc *p;
{

	p->p_stat = SSTOP;
	p->p_flag &= ~SWTED;
	wakeup((caddr_t)p->p_pptr);
D 38
	/*
	 * Avoid sending signal to parent if process is traced
	 */
	if (p->p_flag&STRC)
		return;
	psignal(p->p_pptr, SIGCHLD);
E 38
}

/*
 * Perform the action specified by
 * the current signal.
 * The usual sequence is:
 *	if (issig())
 *		psig();
 * The signal bit has already been cleared by issig,
 * and the current signal number stored in p->p_cursig.
 */
psig()
{
D 20
	register struct proc *rp = u.u_procp;
	register int n = rp->p_cursig;
	long sigmask = 1L << (n-1);
E 20
I 20
	register struct proc *p = u.u_procp;
	register int sig = p->p_cursig;
D 33
	int sigmask = 1 << (sig - 1), returnmask;
E 33
I 33
	int mask = sigmask(sig), returnmask;
E 33
E 20
	register int (*action)();

D 20
	if (rp->p_cursig == 0)
E 20
I 20
	if (sig == 0)
E 20
		panic("psig");
D 20
	action = u.u_signal[n];
E 20
I 20
	action = u.u_signal[sig];
E 20
	if (action != SIG_DFL) {
D 20
		if (action == SIG_IGN || action == SIG_HOLD)
E 20
I 20
D 33
		if (action == SIG_IGN || (p->p_sigmask & sigmask))
E 33
I 33
		if (action == SIG_IGN || (p->p_sigmask & mask))
E 33
E 20
			panic("psig action");
		u.u_error = 0;
D 20
		if (n != SIGILL && n != SIGTRAP)
			u.u_signal[n] = 0;
E 20
		/*
D 20
		 * If this catch value indicates automatic holding of
		 * subsequent signals, set the hold value.
E 20
I 20
		 * Set the new mask value and also defer further
		 * occurences of this signal (unless we're simulating
		 * the old signal facilities). 
		 *
		 * Special case: user has done a sigpause.  Here the
		 * current mask is not of interest, but rather the
		 * mask from before the sigpause is what we want restored
		 * after the signal processing is completed.
E 20
		 */
D 20
		if (SIGISDEFER(action)) {
			(void) spl6();
D 17
			if ((int)SIG_HOLD & 1)
				rp->p_siga0 |= sigmask;
			else
				rp->p_siga0 &= ~sigmask;
			if ((int)SIG_HOLD & 2)
				rp->p_siga1 |= sigmask;
			else
				rp->p_siga1 &= ~sigmask;
E 17
I 17
			/* SIG_HOLD known to be 3 */
			rp->p_siga0 |= sigmask;
			rp->p_siga1 |= sigmask;
E 17
			u.u_signal[n] = SIG_HOLD;
			(void) spl0();
			action = SIGUNDEFER(action);
E 20
I 20
D 33
		(void) spl6();
E 33
I 33
		(void) splhigh();
E 33
		if (p->p_flag & SOUSIG) {
			if (sig != SIGILL && sig != SIGTRAP) {
				u.u_signal[sig] = SIG_DFL;
D 33
				p->p_sigcatch &= ~sigmask;
E 33
I 33
				p->p_sigcatch &= ~mask;
E 33
			}
D 33
			sigmask = 0;
E 33
I 33
			mask = 0;
E 33
E 20
		}
I 20
		if (p->p_flag & SOMASK) {
			returnmask = u.u_oldmask;
			p->p_flag &= ~SOMASK;
		} else
			returnmask = p->p_sigmask;
D 21
		p->p_sigmask = u.u_sigmask[sig] | sigmask;
E 21
I 21
D 33
		p->p_sigmask |= u.u_sigmask[sig] | sigmask;
E 33
I 33
		p->p_sigmask |= u.u_sigmask[sig] | mask;
E 33
E 21
		(void) spl0();
E 20
I 5
		u.u_ru.ru_nsignals++;
E 5
D 20
		sendsig(action, n);
		rp->p_cursig = 0;
E 20
I 20
		sendsig(action, sig, returnmask);
		p->p_cursig = 0;
E 20
		return;
	}
	u.u_acflag |= AXSIG;
D 20
	switch (n) {
E 20
I 20
	switch (sig) {
E 20

	case SIGILL:
	case SIGIOT:
	case SIGBUS:
	case SIGQUIT:
	case SIGTRAP:
	case SIGEMT:
	case SIGFPE:
	case SIGSEGV:
	case SIGSYS:
D 20
		u.u_arg[0] = n;
E 20
I 20
		u.u_arg[0] = sig;
E 20
		if (core())
D 20
			n += 0200;
E 20
I 20
			sig += 0200;
E 20
	}
D 20
	exit(n);
E 20
I 20
	exit(sig);
E 20
}

D 17
#ifdef unneeded
int	corestop = 0;
#endif
E 17
/*
 * Create a core image on the file "core"
 * If you are looking for protection glitches,
 * there are probably a wealth of them here
 * when this occurs to a suid command.
 *
 * It writes UPAGES block of the
 * user.h area followed by the entire
 * data+stack segments.
 */
core()
{
	register struct inode *ip;
D 30
	extern schar();
E 30
I 30
	register struct nameidata *ndp = &u.u_nd;
E 30

D 17
#ifdef unneeded
	if (corestop) {
		int i;
		for (i = 0; i < 10; i++)
			if (u.u_comm[i])
				putchar(u.u_comm[i], 0);
		printf(", uid %d\n", u.u_uid);
		if (corestop&2)
			asm("halt");
	}
#endif
E 17
D 16
	if (u.u_uid != u.u_ruid)
E 16
I 16
	if (u.u_uid != u.u_ruid || u.u_gid != u.u_rgid)
E 16
D 4
		return;
E 4
I 4
		return (0);
E 4
D 5
	if (ctob(UPAGES+u.u_dsize+u.u_ssize) >= u.u_limit[LIM_CORE])
E 5
I 5
	if (ctob(UPAGES+u.u_dsize+u.u_ssize) >=
	    u.u_rlimit[RLIMIT_CORE].rlim_cur)
E 5
		return (0);
I 42
	if (u.u_procp->p_textp && access(u.u_procp->p_textp->x_iptr, IREAD))
		return (0);
E 42
	u.u_error = 0;
D 30
	u.u_dirp = "core";
D 12
	ip = namei(schar, 1, 1);
E 12
I 12
	ip = namei(schar, CREATE, 1);
E 30
I 30
	ndp->ni_nameiop = CREATE | FOLLOW;
	ndp->ni_segflg = UIO_SYSSPACE;
	ndp->ni_dirp = "core";
	ip = namei(ndp);
E 30
E 12
	if (ip == NULL) {
		if (u.u_error)
			return (0);
D 16
		ip = maknode(0666);
E 16
I 16
D 30
		ip = maknode(0644);
E 30
I 30
		ip = maknode(0644, ndp);
E 30
E 16
		if (ip==NULL)
			return (0);
	}
D 4
	if (!access(ip, IWRITE) &&
	   (ip->i_mode&IFMT) == IFREG &&
	   ip->i_nlink == 1) {
D 3
		itrunc(ip);
E 3
I 3
		itrunc(ip, 0);
E 3
		u.u_acflag |= ACORE;
		u.u_offset = 0;
		u.u_base = (caddr_t)&u;
		u.u_count = ctob(UPAGES);
		u.u_segflg = 1;
		writei(ip);
		u.u_base = (char *)ctob(u.u_tsize);
		u.u_count = ctob(u.u_dsize);
		u.u_segflg = 0;
		writei(ip);
		u.u_base = (char *)(USRSTACK - ctob(u.u_ssize));
		u.u_count = ctob(u.u_ssize);
		writei(ip);
	} else
E 4
I 4
	if (access(ip, IWRITE) ||
	   (ip->i_mode&IFMT) != IFREG ||
	   ip->i_nlink != 1) {
E 4
		u.u_error = EFAULT;
I 4
		goto out;
	}
I 50
#ifdef MMAP
	{ register int fd;
	/* unmasp funky devices in the user's address space */
	for (fd = 0; fd < u.u_lastfile; fd++)
		if (u.u_ofile[fd] && (u.u_pofile[fd] & UF_MAPPED))
			munmapfd(fd);
	}
#endif
E 50
D 12
	itrunc(ip, 0);
E 12
I 12
	itrunc(ip, (u_long)0);
E 12
	u.u_acflag |= ACORE;
D 9
	u.u_error =rdwri(UIO_WRITE, ip,
E 9
I 9
D 11
	u.u_error = rdwri(UIO_WRITE, ip,
E 9
	    (caddr_t)&u, ctob(UPAGES),
	    0, 1, (int *)0);
E 11
I 11
D 20
	/* if (u.u_error == 0) */
		u.u_error = rdwri(UIO_WRITE, ip,
		    (caddr_t)&u,
		    ctob(UPAGES),
		    0, 1, (int *)0);
E 20
I 20
	u.u_error = rdwri(UIO_WRITE, ip,
	    (caddr_t)&u,
	    ctob(UPAGES),
D 47
	    0, 1, (int *)0);
E 47
I 47
	    (off_t)0, 1, (int *)0);
E 47
E 20
E 11
D 6
	if (u.u_error)
E 6
I 6
	if (u.u_error == 0)
E 6
D 9
	rdwri(UIO_WRITE, ip,
	    (caddr_t)ctob(u.u_tsize), ctob(u.u_dsize),
	    ctob(UPAGES), 0, (int *)0);
E 9
I 9
		u.u_error = rdwri(UIO_WRITE, ip,
D 11
		    (caddr_t)ctob(u.u_tsize), ctob(u.u_dsize),
E 11
I 11
		    (caddr_t)ctob(dptov(u.u_procp, 0)),
D 47
		    ctob(u.u_dsize),
E 11
		    ctob(UPAGES), 0, (int *)0);
E 47
I 47
		    (int)ctob(u.u_dsize),
		    (off_t)ctob(UPAGES), 0, (int *)0);
E 47
E 9
D 6
	if (u.u_error)
E 6
I 6
	if (u.u_error == 0)
E 6
D 9
	rdwri(UIO_WRITE, ip,
	    (caddr_t)(USRSTACK-ctob(u.u_ssize)), ctob(u.u_ssize),
	    ctob(UPAGES)+ctob(u.u_dsize), 0, (int *)0);
E 9
I 9
		u.u_error = rdwri(UIO_WRITE, ip,
D 11
		    (caddr_t)(USRSTACK-ctob(u.u_ssize)), ctob(u.u_ssize),
E 11
I 11
		    (caddr_t)ctob(sptov(u.u_procp, u.u_ssize - 1)),
D 47
		    ctob(u.u_ssize),
E 11
		    ctob(UPAGES)+ctob(u.u_dsize), 0, (int *)0);
E 47
I 47
		    (int)ctob(u.u_ssize),
		    (off_t)ctob(UPAGES)+ctob(u.u_dsize), 0, (int *)0);
E 47
E 9
out:
E 4
	iput(ip);
D 4
	return (u.u_error==0);
E 4
I 4
	return (u.u_error == 0);
E 4
}
I 4
D 7

E 4
D 2

E 2
/*
D 2
 * grow the stack to include the SP
 * true return if successful.
E 2
I 2
 * alarm clock signal
E 2
 */
D 2
grow(sp)
	unsigned sp;
E 2
I 2
oalarm()
E 2
{
D 2
	register si;

	if (sp >= USRSTACK-ctob(u.u_ssize))
		return (0);
	si = clrnd(btoc((USRSTACK-sp)) - u.u_ssize + SINCR);
	if (ctob(u.u_ssize+si) > u.u_limit[LIM_STACK])
		return (0);
	if (chksize(u.u_tsize, u.u_dsize, u.u_ssize+si))
		return (0);
	if (swpexpand(u.u_dsize, u.u_ssize+si, &u.u_dmap, &u.u_smap)==0)
		return (0);
	
	expand(si, P1BR);
	return (1);
}

/*
 * sys-trace system call.
 */
ptrace()
{
E 2
D 5
	register struct proc *p;
I 2
	register c;
E 5
E 2
	register struct a {
D 2
		int	req;
		int	pid;
		int	*addr;
		int	data;
E 2
I 2
		int	deltat;
E 2
D 5
	} *uap;
E 5
I 5
	} *uap = (struct a *)u.u_ap;
	register struct proc *p = u.u_procp;
	int s = spl7();
E 5

D 5
	uap = (struct a *)u.u_ap;
D 2
	if (uap->req <= 0) {
		u.u_procp->p_flag |= STRC;
		return;
	}
	p = pfind(uap->pid);
	if (p == 0 || p->p_stat != SSTOP || p->p_ppid != u.u_procp->p_pid) {
		u.u_error = ESRCH;
		return;
	}
	while (ipc.ip_lock)
		sleep((caddr_t)&ipc, IPCPRI);
	ipc.ip_lock = p->p_pid;
	ipc.ip_data = uap->data;
	ipc.ip_addr = uap->addr;
	ipc.ip_req = uap->req;
	p->p_flag &= ~SWTED;
	while (ipc.ip_req > 0) {
		if (p->p_stat==SSTOP)
			setrun(p);
		sleep((caddr_t)&ipc, IPCPRI);
	}
	u.u_r.r_val1 = ipc.ip_data;
	if (ipc.ip_req < 0)
		u.u_error = EIO;
	ipc.ip_lock = 0;
	wakeup((caddr_t)&ipc);
E 2
I 2
	p = u.u_procp;
	c = p->p_clktim;
	p->p_clktim = uap->deltat;
	u.u_r.r_val1 = c;
E 5
I 5
D 6
	p->p_realtimer.itimer_reload = 0;
	u.u_r.r_val1 = p->p_realtimer.itimer_value.tv_sec;
	p->p_realtimer.itimer_value.tv_sec = uap->deltat;
	p->p_realtimer.itimer_value.tv_usec = 0;
E 6
I 6
	timerclear(&p->p_realtimer.it_interval);
	u.u_r.r_val1 = p->p_realtimer.it_value.tv_sec;
	p->p_realtimer.it_value.tv_sec = uap->deltat;
	p->p_realtimer.it_value.tv_usec = 0;
E 6
	splx(s);
E 5
E 2
}

D 2
int ipcreg[] = {R0,R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11,AP,FP,SP,PC};
E 2
/*
D 2
 * Code that the child process
 * executes to implement the command
 * of the parent process in tracing.
E 2
I 2
 * indefinite wait.
 * no one should wakeup(&u)
E 2
 */
D 2
procxmt()
E 2
I 2
opause()
E 2
{
D 2
	register int i;
	register *p;
	register struct text *xp;
E 2

D 2
	if (ipc.ip_lock != u.u_procp->p_pid)
		return (0);
	u.u_procp->p_slptime = 0;
	i = ipc.ip_req;
	ipc.ip_req = 0;
	switch (i) {

	/* read user I */
	case 1:
		if (!useracc((caddr_t)ipc.ip_addr, 4, B_READ))
			goto error;
		ipc.ip_data = fuiword((caddr_t)ipc.ip_addr);
		break;

	/* read user D */
	case 2:
		if (!useracc((caddr_t)ipc.ip_addr, 4, B_READ))
			goto error;
		ipc.ip_data = fuword((caddr_t)ipc.ip_addr);
		break;

	/* read u */
	case 3:
		i = (int)ipc.ip_addr;
		if (i<0 || i >= ctob(UPAGES))
			goto error;
		ipc.ip_data = ((physadr)&u)->r[i>>2];
		break;

	/* write user I */
	/* Must set up to allow writing */
	case 4:
		/*
		 * If text, must assure exclusive use
		 */
		if (xp = u.u_procp->p_textp) {
			if (xp->x_count!=1 || xp->x_iptr->i_mode&ISVTX)
				goto error;
			xp->x_iptr->i_flag &= ~ITEXT;
		}
		i = -1;
		if (chgprot((caddr_t)ipc.ip_addr, RW) &&
		    chgprot((caddr_t)ipc.ip_addr+(sizeof(int)-1), RW))
			i = suiword((caddr_t)ipc.ip_addr, ipc.ip_data);
		(void) chgprot((caddr_t)ipc.ip_addr, RO);
		(void) chgprot((caddr_t)ipc.ip_addr+(sizeof(int)-1), RO);
		if (i < 0)
			goto error;
		if (xp)
			xp->x_flag |= XWRIT;
		break;

	/* write user D */
	case 5:
		if (suword((caddr_t)ipc.ip_addr, 0) < 0)
			goto error;
		(void) suword((caddr_t)ipc.ip_addr, ipc.ip_data);
		break;

	/* write u */
	case 6:
		i = (int)ipc.ip_addr;
		p = (int *)&((physadr)&u)->r[i>>2];
		for (i=0; i<16; i++)
			if (p == &u.u_ar0[ipcreg[i]])
				goto ok;
		if (p == &u.u_ar0[PS]) {
			ipc.ip_data |= PSL_CURMOD|PSL_PRVMOD;
			ipc.ip_data &=  ~PSL_USERCLR;
			goto ok;
		}
		goto error;

	ok:
		*p = ipc.ip_data;
		break;

	/* set signal and continue */
	/* one version causes a trace-trap */
	case 9:
	case 7:
		if ((int)ipc.ip_addr != 1)
			u.u_ar0[PC] = (int)ipc.ip_addr;
		if ((unsigned)ipc.ip_data > NSIG)
			goto error;
		u.u_procp->p_cursig = ipc.ip_data;	/* see issig */
		if (i == 9)
			u.u_ar0[PS] |= PSL_T;
		wakeup((caddr_t)&ipc);
		return (1);

	/* force exit */
	case 8:
		wakeup((caddr_t)&ipc);
		exit(u.u_procp->p_cursig);

	default:
	error:
		ipc.ip_req = -1;
	}
	wakeup((caddr_t)&ipc);
	return (0);
E 2
I 2
	for (;;)
		sleep((caddr_t)&u, PSLEP);
E 2
}
I 2

E 7
E 2
E 1
