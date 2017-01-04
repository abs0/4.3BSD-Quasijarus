h53723
s 00001/00001/00355
d D 7.2 87/02/26 18:09:59 karels 15 14
c do reboot more flexibly
e
s 00001/00001/00355
d D 7.1 86/06/05 00:05:24 mckusick 14 13
c 4.3BSD release version
e
s 00001/00001/00355
d D 6.7 86/03/04 19:54:53 karels 13 11
c consistency
e
s 00356/00000/00000
d R 6.7 86/03/04 19:25:17 karels 12 11
c consistency
e
s 00004/00003/00352
d D 6.6 86/02/20 20:46:55 karels 11 10
c spls
e
s 00001/00001/00354
d D 6.5 85/11/28 10:34:51 bloom 10 9
c hostid should be a long
e
s 00007/00001/00348
d D 6.4 85/06/08 14:39:19 mckusick 9 8
c Add copyright
e
s 00001/00001/00348
d D 6.3 85/03/12 13:53:29 mckusick 8 7
c add another bit to sigvec() flags to disable system call restart
e
s 00007/00007/00342
d D 6.2 84/08/29 20:20:46 bloom 7 6
c Change to includes.  no more ../h
e
s 00000/00000/00349
d D 6.1 83/07/29 06:34:48 sam 6 5
c 4.2 distribution
e
s 00001/00012/00348
d D 4.5 83/06/21 20:35:53 sam 5 4
c change NOCOMPAT to COMPAT and make it work
e
s 00011/00005/00349
d D 4.4 83/06/09 21:59:48 sam 4 3
c "final" sigvec interface?
e
s 00017/00051/00337
d D 4.3 83/06/02 15:57:11 sam 3 2
c new signals
e
s 00022/00001/00366
d D 4.2 83/05/31 01:03:49 sam 2 1
c collect all the compatibility stuff in single files
e
s 00367/00000/00000
d D 4.1 83/05/27 14:02:49 sam 1 0
c date and time created 83/05/27 14:02:49 by sam
e
u
U
f b 
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9

D 7
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/kernel.h"
#include "../h/proc.h"
#include "../h/reboot.h"
E 7
I 7
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "proc.h"
#include "reboot.h"
E 7
D 2
#include "../h/quota.h"
E 2

gethostid()
{

	u.u_r.r_val1 = hostid;
}

sethostid()
{
	struct a {
D 10
		int	hostid;
E 10
I 10
		long	hostid;
E 10
	} *uap = (struct a *)u.u_ap;

	if (suser())
		hostid = uap->hostid;
}

gethostname()
{
	register struct a {
		char	*hostname;
D 13
		int	len;
E 13
I 13
		u_int	len;
E 13
	} *uap = (struct a *)u.u_ap;
	register u_int len;

	len = uap->len;
	if (len > hostnamelen + 1)
		len = hostnamelen + 1;
	u.u_error = copyout((caddr_t)hostname, (caddr_t)uap->hostname, len);
}

sethostname()
{
	register struct a {
		char	*hostname;
		u_int	len;
	} *uap = (struct a *)u.u_ap;

	if (!suser())
		return;
	if (uap->len > sizeof (hostname) - 1) {
		u.u_error = EINVAL;
		return;
	}
	hostnamelen = uap->len;
	u.u_error = copyin((caddr_t)uap->hostname, hostname, uap->len);
	hostname[hostnamelen] = 0;
}

reboot()
{
	register struct a {
		int	opt;
	};

	if (suser())
D 15
		boot(RB_BOOT, ((struct a *)u.u_ap)->opt);
E 15
I 15
		boot(((struct a *)u.u_ap)->opt);
E 15
}

D 5
#ifndef NOCOMPAT
E 5
I 5
#ifdef COMPAT
E 5
I 2
#include "../h/quota.h"

E 2
osetuid()
{
	register uid;
	register struct a {
		int	uid;
	} *uap;

	uap = (struct a *)u.u_ap;
	uid = uap->uid;
	if (u.u_ruid == uid || u.u_uid == uid || suser()) {
#ifdef QUOTA
		if (u.u_quota->q_uid != uid) {
			qclean();
			qstart(getquota(uid, 0, 0));
		}
#endif
		u.u_uid = uid;
		u.u_procp->p_uid = uid;
		u.u_ruid = uid;
	}
}

osetgid()
{
	register gid;
	register struct a {
		int	gid;
	} *uap;

	uap = (struct a *)u.u_ap;
	gid = uap->gid;
	if (u.u_rgid == gid || u.u_gid == gid || suser()) {
		leavegroup(u.u_rgid);
		(void) entergroup(gid);
		u.u_gid = gid;
		u.u_rgid = gid;
	}
}

/*
 * Pid of zero implies current process.
 * Pgrp -1 is getpgrp system call returning
 * current process group.
 */
osetpgrp()
{
	register struct proc *p;
	register struct a {
		int	pid;
		int	pgrp;
	} *uap;

	uap = (struct a *)u.u_ap;
	if (uap->pid == 0)
		p = u.u_procp;
	else {
		p = pfind(uap->pid);
		if (p == 0) {
			u.u_error = ESRCH;
			return;
		}
	}
	if (uap->pgrp <= 0) {
		u.u_r.r_val1 = p->p_pgrp;
		return;
	}
	if (p->p_uid != u.u_uid && u.u_uid && !inferior(p)) {
		u.u_error = EPERM;
		return;
	}
	p->p_pgrp = uap->pgrp;
}

otime()
{

	u.u_r.r_time = time.tv_sec;
}

ostime()
{
	register struct a {
		int	time;
	} *uap = (struct a *)u.u_ap;
	struct timeval tv;

	tv.tv_sec = uap->time;
	tv.tv_usec = 0;
	setthetime(&tv);
}

/* from old timeb.h */
struct timeb {
	time_t	time;
	u_short	millitm;
	short	timezone;
	short	dstflag;
};

oftime()
{
	register struct a {
		struct	timeb	*tp;
	} *uap;
	struct timeb tb;
I 11
	int s;
E 11

	uap = (struct a *)u.u_ap;
D 11
	(void) spl7();
E 11
I 11
	s = splhigh();
E 11
	tb.time = time.tv_sec;
	tb.millitm = time.tv_usec / 1000;
D 11
	(void) spl0();
E 11
I 11
	splx(s);
E 11
	tb.timezone = tz.tz_minuteswest;
	tb.dstflag = tz.tz_dsttime;
	u.u_error = copyout((caddr_t)&tb, (caddr_t)uap->tp, sizeof (tb));
}

oalarm()
{
	register struct a {
		int	deltat;
	} *uap = (struct a *)u.u_ap;
	register struct proc *p = u.u_procp;
D 11
	int s = spl7();
E 11
I 11
	int s = splhigh();
E 11

	untimeout(realitexpire, (caddr_t)p);
	timerclear(&p->p_realtimer.it_interval);
	u.u_r.r_val1 = 0;
	if (timerisset(&p->p_realtimer.it_value) &&
	    timercmp(&p->p_realtimer.it_value, &time, >))
		u.u_r.r_val1 = p->p_realtimer.it_value.tv_sec - time.tv_sec;
	if (uap->deltat == 0) {
		timerclear(&p->p_realtimer.it_value);
		splx(s);
		return;
	}
	p->p_realtimer.it_value = time;
	p->p_realtimer.it_value.tv_sec += uap->deltat;
	timeout(realitexpire, (caddr_t)p, hzto(&p->p_realtimer.it_value));
	splx(s);
}

onice()
{
	register struct a {
		int	niceness;
	} *uap = (struct a *)u.u_ap;
	register struct proc *p = u.u_procp;

	donice(p, (p->p_nice-NZERO)+uap->niceness);
}

#include "../h/times.h"

otimes()
{
	register struct a {
		struct	tms *tmsb;
	} *uap = (struct a *)u.u_ap;
	struct tms atms;

	atms.tms_utime = scale60(&u.u_ru.ru_utime);
	atms.tms_stime = scale60(&u.u_ru.ru_stime);
	atms.tms_cutime = scale60(&u.u_cru.ru_utime);
	atms.tms_cstime = scale60(&u.u_cru.ru_stime);
	u.u_error = copyout((caddr_t)&atms, (caddr_t)uap->tmsb, sizeof (atms));
}

scale60(tvp)
	register struct timeval *tvp;
{

	return (tvp->tv_sec * 60 + tvp->tv_usec / 16667);
}

#include "../h/vtimes.h"

ovtimes()
{
	register struct a {
		struct	vtimes *par;
		struct	vtimes *chi;
	} *uap = (struct a *)u.u_ap;
	struct vtimes avt;

	if (uap->par) {
		getvtimes(&u.u_ru, &avt);
		u.u_error = copyout((caddr_t)&avt, (caddr_t)uap->par,
			sizeof (avt));
		if (u.u_error)
			return;
	}
	if (uap->chi) {
		getvtimes(&u.u_cru, &avt);
		u.u_error = copyout((caddr_t)&avt, (caddr_t)uap->chi,
			sizeof (avt));
		if (u.u_error)
			return;
	}
I 2
}

#include "../machine/psl.h"
#include "../machine/reg.h"

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
E 2
}

getvtimes(aru, avt)
	register struct rusage *aru;
	register struct vtimes *avt;
{

	avt->vm_utime = scale60(&aru->ru_utime);
	avt->vm_stime = scale60(&aru->ru_stime);
	avt->vm_idsrss = ((aru->ru_idrss+aru->ru_isrss) / hz) * 60;
	avt->vm_ixrss = aru->ru_ixrss / hz * 60;
	avt->vm_maxrss = aru->ru_maxrss;
	avt->vm_majflt = aru->ru_majflt;
	avt->vm_minflt = aru->ru_minflt;
	avt->vm_nswap = aru->ru_nswap;
	avt->vm_inblk = aru->ru_inblock;
	avt->vm_oublk = aru->ru_oublock;
}

ovlimit()
{

	u.u_error = EACCES;
D 5
}

okill()
{
	register struct a {
		int	pid;
		int	signo;
	} *uap = (struct a *)u.u_ap;

	u.u_error = kill1(uap->signo < 0,
		uap->signo < 0 ? -uap->signo : uap->signo, uap->pid);
E 5
}

ossig()
{
D 3
	register int (*f)();
E 3
	struct a {
		int	signo;
		int	(*fun)();
D 3
	} *uap;
	register struct proc *p = u.u_procp;
	register a;
	long sigmask;
E 3
I 3
	} *uap = (struct a *)u.u_ap;
D 4
	register int a, (*f)();
E 4
I 4
	register int a;
	struct sigvec vec;
	register struct sigvec *sv = &vec;
E 4
	struct proc *p = u.u_procp;
E 3

D 3
	uap = (struct a *)u.u_ap;
	a = uap->signo & SIGNUMMASK;
E 3
D 4
	f = uap->fun;
E 4
D 3
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
E 3
I 3
	a = uap->signo;
I 4
	sv->sv_handler = uap->fun;
E 4
E 3
	/*
D 3
	 * Change setting atomically.
E 3
I 3
	 * Kill processes trying to use job control facilities
	 * (this'll help us find any vestiges of the old stuff).
E 3
	 */
D 3
	(void) spl6();
	sigmask = 1L << (a-1);
	if (f == SIG_IGN)
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
E 3
I 3
	if ((a &~ 0377) ||
D 4
	    (f != SIG_DFL && f != SIG_IGN && ((int)f) & 1)) {
E 4
I 4
	    (sv->sv_handler != SIG_DFL && sv->sv_handler != SIG_IGN &&
	     ((int)sv->sv_handler) & 1)) {
E 4
		psignal(p, SIGSYS);
		return;
E 3
	}
D 3
	if (uap->signo & SIGDORTI)
		u.u_eosys = SIMULATERTI;
E 3
I 3
	if (a <= 0 || a >= NSIG || a == SIGKILL || a == SIGSTOP ||
D 4
	    a == SIGCONT && (f == SIG_IGN || f == SIG_HOLD)) {
E 4
I 4
	    a == SIGCONT && sv->sv_handler == SIG_IGN) {
E 4
		u.u_error = EINVAL;
		return;
	}
D 4
	setsignal(a, f, 0);
E 4
I 4
	sv->sv_mask = 0;
D 8
	sv->sv_onstack = 0;
E 8
I 8
	sv->sv_flags = SV_INTERRUPT;
E 8
	u.u_r.r_val1 = (int)u.u_signal[a];
	setsigvec(a, sv);
E 4
	p->p_flag |= SOUSIG;		/* mark as simulating old stuff */
E 3
}
#endif
E 1
