h40418
s 00002/00009/00345
d D 7.6 2011/10/09 08:53:54 msokolov 32 31
c adjtime: more thoughtful slew rate selection logic
e
s 00000/00001/00354
d D 7.5 87/07/21 13:10:48 mckusick 31 30
c delete unneeded header files
e
s 00017/00013/00338
d D 7.4 87/03/23 17:46:14 bostic 30 29
c changed set/gettimeofday to set/get timezone alone
e
s 00003/00002/00348
d D 7.3 86/11/03 12:00:01 karels 29 28
c merge in tahoe support
e
s 00000/00001/00350
d D 7.2 86/07/27 20:00:44 karels 28 27
c rm extraneous splx
e
s 00001/00001/00350
d D 7.1 86/06/05 00:05:08 mckusick 27 26
c 4.3BSD release version
e
s 00021/00009/00330
d D 6.10 86/05/27 15:21:56 karels 26 25
c use faster adjustment for larger corrections
e
s 00002/00001/00337
d D 6.9 86/02/23 23:09:18 karels 25 24
c lint
e
s 00005/00006/00333
d D 6.8 86/01/13 17:38:31 karels 24 23
c microsecond times using microtime; spl7 => splclock
e
s 00007/00005/00332
d D 6.7 85/10/17 18:55:07 mckusick 23 22
c return old timer value, even when a new one is not specified (from ralph)
e
s 00006/00001/00331
d D 6.6 85/10/11 16:48:59 karels 22 21
c time adj must be multiple of tickadj for now (avoid oscillation)
e
s 00007/00001/00325
d D 6.5 85/06/08 14:38:53 mckusick 21 20
c Add copyright
e
s 00026/00000/00300
d D 6.4 84/11/14 10:04:52 karels 20 19
c adjtime
e
s 00006/00006/00294
d D 6.3 84/08/29 20:20:37 bloom 19 18
c Change to includes.  no more ../h
e
s 00002/00002/00298
d D 6.2 84/06/06 23:06:18 sam 18 17
c fix bug, wasn't setting timezone
c *** CHANGED *** 84/06/06 23:08:32 sam
c never actually SET timezone
e
s 00000/00000/00300
d D 6.1 83/07/29 06:34:37 sam 17 16
c 4.2 distribution
e
s 00001/00001/00299
d D 5.16 83/06/10 21:24:09 sam 16 15
c fixing wrong, set 0 val to tick
e
s 00000/00070/00300
d D 5.15 83/05/27 12:47:24 sam 15 14
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00001/00000/00369
d D 5.14 82/12/30 16:28:21 root 14 13
c fix to computation of integral times in kern_clock and alarm(0) in _time
e
s 00015/00022/00354
d D 5.13 82/12/28 23:47:05 sam 13 12
c copyin & copyout now return EFAULT and all callers uniformly 
c return (or ignore) this value
e
s 00002/00001/00374
d D 5.12 82/12/17 11:45:27 sam 12 11
c sun merge
e
s 00001/00001/00374
d D 5.11 82/11/02 11:30:53 root 11 10
c clock name
e
s 00009/00008/00366
d D 5.10 82/10/17 21:49:29 root 10 9
c more lint
e
s 00000/00002/00374
d D 5.9 82/10/17 14:04:50 root 9 8
c fix lint
e
s 00001/00001/00375
d D 5.8 82/10/10 15:08:28 root 8 7
c split header files over to vax directories
e
s 00122/00048/00254
d D 5.7 82/09/11 13:12:25 root 7 6
c cleanup with comments
e
s 00025/00000/00277
d D 5.6 82/09/08 08:07:36 root 6 5
c oalarm now here
e
s 00046/00010/00231
d D 5.5 82/09/08 07:57:39 root 5 4
c timeouts used for all timers now
e
s 00079/00046/00162
d D 5.4 82/09/06 22:54:16 root 4 3
c  
e
s 00164/00062/00044
d D 5.3 82/09/04 09:15:15 root 3 2
c new timeofday and interval timer stuff; itimers need testing
e
s 00020/00005/00086
d D 5.2 82/07/24 18:10:32 root 2 1
c merge with calder
e
s 00091/00000/00000
d D 5.1 82/07/15 20:20:48 root 1 0
c date and time created 82/07/15 20:20:48 by root
e
u
U
f b 
t
T
I 1
D 21
/*	%M%	%I%	%E%	*/
E 21
I 21
/*
D 27
 * Copyright (c) 1982 Regents of the University of California.
E 27
I 27
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 27
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 32
 *	%W% (Berkeley) %G%
E 32
I 32
 *	%W% (Berkeley) %E%
E 32
 */
E 21

I 12
D 29
#include "../machine/reg.h"

E 29
E 12
D 19
#include "../h/param.h"
D 3
#include "../h/systm.h"
#include "../h/dir.h"
E 3
I 3
#include "../h/dir.h"		/* XXX */
E 3
#include "../h/user.h"
I 3
#include "../h/kernel.h"
E 3
D 12
#include "../h/reg.h"
E 12
#include "../h/inode.h"
#include "../h/proc.h"
E 19
I 19
#include "param.h"
#include "dir.h"		/* XXX */
#include "user.h"
#include "kernel.h"
D 31
#include "inode.h"
E 31
#include "proc.h"
I 29

#include "../machine/reg.h"
#include "../machine/cpu.h"
E 29
E 19
D 3
#include "../h/clock.h"
#include "../h/mtpr.h"
#include "../h/timeb.h"
#include "../h/times.h"
#include "../h/reboot.h"
#include "../h/fs.h"
#include "../h/conf.h"
#include "../h/buf.h"
#include "../h/mount.h"
E 3

I 4
/* 
 * Time of day and interval timer support.
I 7
 *
 * These routines provide the kernel entry points to get and set
 * the time-of-day and per-process interval timers.  Subroutines
 * here provide support for adding and subtracting timeval structures
 * and decrementing interval timers, optionally reloading the interval
 * timers when they expire.
E 7
 */

E 4
D 2
/*
 * return the current time (old-style entry)
 */
gtime()
E 2
I 2
D 3
rtime()
E 3
I 3
gettimeofday()
E 3
E 2
{
I 3
	register struct a {
		struct	timeval *tp;
		struct	timezone *tzp;
	} *uap = (struct a *)u.u_ap;
	struct timeval atv;
I 4
D 24
	int s;
E 24
E 4
E 3
I 2

I 3
D 4
	microtime(&atv);
E 4
I 4
D 24
	s = spl7(); atv = time; splx(s);
E 24
I 24
D 30
	microtime(&atv);
E 24
E 4
D 13
	if (copyout((caddr_t)&atv, (caddr_t)uap->tp, sizeof (atv))) {
		u.u_error = EFAULT;
E 13
I 13
	u.u_error = copyout((caddr_t)&atv, (caddr_t)uap->tp, sizeof (atv));
	if (u.u_error)
E 13
		return;
D 13
	}
E 13
	if (uap->tzp == 0)
		return;
I 4
	/* SHOULD HAVE PER-PROCESS TIMEZONE */
E 4
D 10
	if (copyout((caddr_t)&tz, uap->tzp, sizeof (tz))) {
E 10
I 10
D 13
	if (copyout((caddr_t)&tz, (caddr_t)uap->tzp, sizeof (tz))) {
E 10
		u.u_error = EFAULT;
		return;
	}
E 13
I 13
	u.u_error = copyout((caddr_t)&tz, (caddr_t)uap->tzp, sizeof (tz));
E 30
I 30
	if (uap->tp) {
		microtime(&atv);
		u.u_error = copyout((caddr_t)&atv, (caddr_t)uap->tp,
			sizeof (atv));
		if (u.u_error)
			return;
	}
	if (uap->tzp)
		u.u_error = copyout((caddr_t)&tz, (caddr_t)uap->tzp,
			sizeof (tz));
E 30
E 13
E 3
}

D 3
rusage()
E 3
I 3
settimeofday()
E 3
{
I 3
	register struct a {
D 4
		struct timeval *tv;
		struct timezone *tzp;
E 4
I 4
		struct	timeval *tv;
		struct	timezone *tzp;
E 4
	} *uap = (struct a *)u.u_ap;
	struct timeval atv;
	struct timezone atz;
E 3

I 3
D 13
	if (copyin((caddr_t)uap->tv, (caddr_t)&atv, sizeof (struct timeval))) {
		u.u_error = EFAULT;
E 13
I 13
D 30
	u.u_error = copyin((caddr_t)uap->tv, (caddr_t)&atv,
		sizeof (struct timeval));
	if (u.u_error)
E 13
		return;
D 13
	}
E 13
D 4
	if (suser()) {
		struct timeval tdelta;

		tdelta = atv;

		timevalsub(&tdelta, &time);
		timevaladd(&boottime, &tdelta);
		time = atv;
		clockset();
	}
	if (uap->tzp) {
E 4
I 4
	setthetime(&atv);
E 30
I 30
	if (uap->tv) {
		u.u_error = copyin((caddr_t)uap->tv, (caddr_t)&atv,
			sizeof (struct timeval));
		if (u.u_error)
			return;
		setthetime(&atv);
	}
E 30
	if (uap->tzp && suser()) {
E 4
D 13
		if (copyin((caddr_t)uap->tzp, (caddr_t)&atz, sizeof (atz))) {
			u.u_error = EFAULT;
E 13
I 13
		u.u_error = copyin((caddr_t)uap->tzp, (caddr_t)&atz,
			sizeof (atz));
D 18
		if (u.u_error)
E 13
			return;
E 18
I 18
		if (u.u_error == 0)
			tz = atz;
E 18
D 13
		}
E 13
D 4
		/* XXX */
E 4
	}
E 3
}

I 4
setthetime(tv)
	struct timeval *tv;
{
D 9
	register int delta;
E 9
	int s;

	if (!suser())
		return;
I 7
/* WHAT DO WE DO ABOUT PENDING REAL-TIME TIMEOUTS??? */
E 7
	boottime.tv_sec += tv->tv_sec - time.tv_sec;
D 24
	s = spl7(); time = *tv; splx(s);
E 24
I 24
	s = splhigh(); time = *tv; splx(s);
E 24
D 11
	clockset();
E 11
I 11
	resettodr();
E 11
}

I 20
D 26
int adjtimedelta;
I 22
extern int tickadj;
E 26
I 26
extern	int tickadj;			/* "standard" clock skew, us./tick */
D 32
int	tickdelta;			/* current clock skew, us. per tick */
E 32
long	timedelta;			/* unapplied time correction, us. */
D 32
long	bigadj = 1000000;		/* use 10x skew above bigadj us. */
E 32
E 26
E 22

adjtime()
{
	register struct a {
		struct timeval *delta;
		struct timeval *olddelta;
	} *uap = (struct a *)u.u_ap;
D 22

E 22
	struct timeval atv, oatv;
I 26
	register long ndelta;
E 26
I 22
	int s;
E 22

	if (!suser()) 
		return;
	u.u_error = copyin((caddr_t)uap->delta, (caddr_t)&atv,
		sizeof (struct timeval));
	if (u.u_error)
		return;
I 26
	ndelta = atv.tv_sec * 1000000 + atv.tv_usec;
D 32
	if (timedelta == 0)
		if (ndelta > bigadj)
			tickdelta = 10 * tickadj;
		else
			tickdelta = tickadj;
	if (ndelta % tickdelta)
E 32
I 32
	if (ndelta % tickadj)
E 32
		ndelta = ndelta / tickadj * tickadj;

E 26
I 22
	s = splclock();
E 22
	if (uap->olddelta) {
D 26
		oatv.tv_sec = adjtimedelta / 1000000;
		oatv.tv_usec = adjtimedelta % 1000000;
		(void) copyout((caddr_t)&oatv, (caddr_t)uap->olddelta,
			sizeof (struct timeval));
E 26
I 26
		oatv.tv_sec = timedelta / 1000000;
		oatv.tv_usec = timedelta % 1000000;
E 26
	}
D 26
	adjtimedelta = atv.tv_sec * 1000000 + atv.tv_usec;
I 22
	if (adjtimedelta % tickadj)
		adjtimedelta = adjtimedelta / tickadj * tickadj;
E 26
I 26
	timedelta = ndelta;
E 26
	splx(s);
I 26

	if (uap->olddelta)
		(void) copyout((caddr_t)&oatv, (caddr_t)uap->olddelta,
			sizeof (struct timeval));
E 26
E 22
}

E 20
E 4
D 3
itimer()
E 3
I 3
D 7
timevaladd(t1, t2)
	struct timeval *t1, *t2;
E 3
{

I 3
	t1->tv_sec += t2->tv_sec;
D 4
	t1->tv_usec += t2->tv_sec;
E 4
I 4
	t1->tv_usec += t2->tv_usec;
E 4
	timevalfix(t1);
E 3
}

D 3
/* BEGIN DEPRECATED */
ogtime()
E 3
I 3
timevalsub(t1, t2)
	struct timeval *t1, *t2;
E 3
{

E 2
D 3
	u.u_r.r_time = time;
	if (clkwrap())
		clkset();
E 3
I 3
	t1->tv_sec -= t2->tv_sec;
D 4
	t1->tv_usec -= t2->tv_sec;
E 4
I 4
	t1->tv_usec -= t2->tv_usec;
E 4
	timevalfix(t1);
E 3
}

D 3
/*
 * New time entry-- return TOD with milliseconds, timezone,
 * DST flag
 */
D 2
ftime()
E 2
I 2
oftime()
E 3
I 3
timevalfix(t1)
	struct timeval *t1;
E 3
E 2
{
I 3

	if (t1->tv_usec < 0) {
		t1->tv_sec--;
		t1->tv_usec += 1000000;
	}
	if (t1->tv_usec >= 1000000) {
		t1->tv_sec++;
		t1->tv_usec -= 1000000;
	}
}

E 7
I 7
/*
 * Get value of an interval timer.  The process virtual and
 * profiling virtual time timers are kept in the u. area, since
 * they can be swapped out.  These are kept internally in the
 * way they are specified externally: in time until they expire.
 *
 * The real time interval timer is kept in the process table slot
 * for the process, and its value (it_value) is kept as an
 * absolute time rather than as a delta, so that it is easy to keep
 * periodic real-time signals from drifting.
 *
 * Virtual time timers are processed in the hardclock() routine of
 * kern_clock.c.  The real time timer is processed by a timeout
 * routine, called from the softclock() routine.  Since a callout
 * may be delayed in real time due to interrupt processing in the system,
 * it is possible for the real time timeout routine (realitexpire, given below),
 * to be delayed in real time past when it is supposed to occur.  It
 * does not suffice, therefore, to reload the real timer .it_value from the
 * real time timers .it_interval.  Rather, we compute the next time in
 * absolute time the timer should go off.
 */
E 7
getitimer()
{
E 3
	register struct a {
D 3
		struct	timeb	*tp;
	} *uap;
	struct timeb t;
	register unsigned ms;
E 3
I 3
		u_int	which;
		struct	itimerval *itv;
	} *uap = (struct a *)u.u_ap;
D 5
	register struct itimerval *itp;
E 5
I 5
	struct itimerval aitv;
E 5
	int s;
E 3

D 3
	uap = (struct a *)u.u_ap;
	(void) spl7();
	t.time = time;
	ms = lbolt;
	(void) spl0();
	if (ms > hz) {
		ms -= hz;
		t.time++;
E 3
I 3
	if (uap->which > 2) {
		u.u_error = EINVAL;
		return;
E 3
	}
D 3
	t.millitm = (1000*ms)/hz;
	t.timezone = timezone;
	t.dstflag = dstflag;
	if (copyout((caddr_t)&t, (caddr_t)uap->tp, sizeof(t)) < 0)
E 3
I 3
D 5
	if (uap->which == ITIMER_REAL)
		itp = &u.u_procp->p_realtimer;
	else
		itp = &u.u_timer[uap->which];
E 5
D 24
	s = spl7();
E 24
I 24
	s = splclock();
E 24
D 4
	if (copyout((caddr_t)itp, uap->itv, sizeof (struct itimerval))) {
E 4
I 4
D 5
	if (copyout((caddr_t)itp, uap->itv, sizeof (struct itimerval)))
E 5
I 5
	if (uap->which == ITIMER_REAL) {
I 7
		/*
		 * Convert from absoulte to relative time in .it_value
		 * part of real time timer.  If time for real time timer
		 * has passed return 0, else return difference between
		 * current time and time for the timer to go off.
		 */
E 7
		aitv = u.u_procp->p_realtimer;
		if (timerisset(&aitv.it_value))
			if (timercmp(&aitv.it_value, &time, <))
				timerclear(&aitv.it_value);
			else
				timevalsub(&aitv.it_value, &time);
	} else
		aitv = u.u_timer[uap->which];
	splx(s);
D 10
	if (copyout((caddr_t)&aitv, uap->itv, sizeof (struct itimerval)))
E 10
I 10
D 13
	if (copyout((caddr_t)&aitv, (caddr_t)uap->itv,
	    sizeof (struct itimerval)))
E 10
E 5
E 4
E 3
		u.u_error = EFAULT;
E 13
I 13
	u.u_error = copyout((caddr_t)&aitv, (caddr_t)uap->itv,
	    sizeof (struct itimerval));
E 13
D 3
	if (clkwrap())
		clkset();
E 3
I 3
D 4
		goto bad;
	}
bad:
E 4
D 28
	splx(s);
E 28
E 3
}
I 2
D 3
/* END DEPRECATED */
E 3
E 2

D 3
/*
 * Set the time
 */
stime()
E 3
I 3
setitimer()
E 3
{
	register struct a {
D 3
		time_t	time;
	} *uap;
E 3
I 3
		u_int	which;
D 4
		struct	itimerval *itv;
E 4
I 4
		struct	itimerval *itv, *oitv;
E 4
	} *uap = (struct a *)u.u_ap;
D 23
	struct itimerval aitv;
E 23
I 23
	struct itimerval aitv, *aitvp;
E 23
	int s;
I 5
	register struct proc *p = u.u_procp;
E 5
E 3

D 3
	uap = (struct a *)u.u_ap;
	if (suser()) {
		bootime += uap->time - time;
		time = uap->time;
		clkset();
E 3
I 3
D 4
	s = spl7();
E 4
	if (uap->which > 2) {
		u.u_error = EINVAL;
D 4
		goto bad;
E 4
I 4
		return;
E 4
E 3
	}
I 3
D 13
	if (copyin((caddr_t)uap->itv, (caddr_t)&aitv,
	    sizeof (struct itimerval))) {
		u.u_error = EFAULT;
E 13
I 13
D 23
	u.u_error = copyin((caddr_t)uap->itv, (caddr_t)&aitv,
	    sizeof (struct itimerval));
	if (u.u_error)
E 13
D 4
		goto bad;
E 4
I 4
		return;
E 23
I 23
	aitvp = uap->itv;
E 23
E 4
D 13
	}
E 13
D 4
	u.u_timer[uap->which] = aitv;
E 4
I 4
	if (uap->oitv) {
		uap->itv = uap->oitv;
		getitimer();
	}
I 23
	if (aitvp == 0)
		return;
D 25
	u.u_error = copyin(aitvp, (caddr_t)&aitv, sizeof (struct itimerval));
E 25
I 25
	u.u_error = copyin((caddr_t)aitvp, (caddr_t)&aitv,
	    sizeof (struct itimerval));
E 25
	if (u.u_error)
		return;
E 23
	if (itimerfix(&aitv.it_value) || itimerfix(&aitv.it_interval)) {
		u.u_error = EINVAL;
		return;
	}
D 24
	s = spl7();
E 24
I 24
	s = splclock();
E 24
E 4
D 5
	if (uap->which == ITIMER_REAL)
		u.u_procp->p_realtimer = aitv;
D 4
bad:
E 4
I 4
	else
E 5
I 5
	if (uap->which == ITIMER_REAL) {
D 7
		untimeout(unrto, p);
E 7
I 7
D 10
		untimeout(realitexpire, p);
E 10
I 10
		untimeout(realitexpire, (caddr_t)p);
E 10
E 7
		if (timerisset(&aitv.it_value)) {
			timevaladd(&aitv.it_value, &time);
D 7
			timeout(unrto, p, hzto(&aitv.it_value));
E 7
I 7
D 10
			timeout(realitexpire, p, hzto(&aitv.it_value));
E 10
I 10
			timeout(realitexpire, (caddr_t)p, hzto(&aitv.it_value));
E 10
E 7
		}
		p->p_realtimer = aitv;
	} else
E 5
		u.u_timer[uap->which] = aitv;
E 4
	splx(s);
D 4
	return;
E 4
E 3
}

I 5
D 7
unrto(p)
E 7
I 7
/*
 * Real interval timer expired:
 * send process whose timer expired an alarm signal.
 * If time is not set up to reload, then just return.
 * Else compute next time timer should go off which is > current time.
 * This is where delay in processing this timeout causes multiple
 * SIGALRM calls to be compressed into one.
 */
realitexpire(p)
E 7
	register struct proc *p;
{
	int s;

	psignal(p, SIGALRM);
	if (!timerisset(&p->p_realtimer.it_interval)) {
		timerclear(&p->p_realtimer.it_value);
		return;
	}
	for (;;) {
D 24
		s = spl7();
E 24
I 24
		s = splclock();
E 24
		timevaladd(&p->p_realtimer.it_value,
		    &p->p_realtimer.it_interval);
		if (timercmp(&p->p_realtimer.it_value, &time, >)) {
D 7
			timeout(unrto, p, hzto(&p->p_realtimer.it_value));
E 7
I 7
D 10
			timeout(realitexpire,
			    p, hzto(&p->p_realtimer.it_value));
E 10
I 10
			timeout(realitexpire, (caddr_t)p,
			    hzto(&p->p_realtimer.it_value));
E 10
E 7
			splx(s);
			return;
		}
		splx(s);
	}
}

I 7
/*
 * Check that a proposed value to load into the .it_value or
 * .it_interval part of an interval timer is acceptable, and
 * fix it to have at least minimal value (i.e. if it is less
 * than the resolution of the clock, round it up.)
 */
E 7
E 5
D 3
times()
E 3
I 3
D 4
getandsetitimer()
E 4
I 4
itimerfix(tv)
	struct timeval *tv;
E 4
E 3
{
I 3
D 4
	int s = spl7();
E 4

D 4
	getitimer();
	if (u.u_error == 0) {
		u.u_ap[1] = u.u_ap[2];
		setitimer();
	}
	splx(s);
E 4
I 4
D 5
	if (tv->tv_sec < 0 || tv->tv_usec < 0)
E 5
I 5
	if (tv->tv_sec < 0 || tv->tv_sec > 100000000 ||
	    tv->tv_usec < 0 || tv->tv_usec >= 1000000)
E 5
		return (EINVAL);
D 16
	if (tv->tv_sec == 0 && tv->tv_usec < tick)
E 16
I 16
	if (tv->tv_sec == 0 && tv->tv_usec != 0 && tv->tv_usec < tick)
E 16
		tv->tv_usec = tick;
	return (0);
E 4
}

I 7
/*
 * Decrement an interval timer by a specified number
 * of microseconds, which must be less than a second,
 * i.e. < 1000000.  If the timer expires, then reload
 * it.  In this case, carry over (usec - old value) to
 * reducint the value reloaded into the timer so that
 * the timer does not drift.  This routine assumes
 * that it is called in a context where the timers
 * on which it is operating cannot change in value.
 */
E 7
itimerdecr(itp, usec)
	register struct itimerval *itp;
	int usec;
{

D 4
	while (itp->itimer_value.tv_usec < usec) {
		if (itp->itimer_value.tv_sec == 0)
E 4
I 4
	if (itp->it_value.tv_usec < usec) {
		if (itp->it_value.tv_sec == 0) {
I 7
			/* expired, and already in next interval */
E 7
			usec -= itp->it_value.tv_usec;
E 4
			goto expire;
D 4
		itp->itimer_value.tv_usec += 1000000;
		itp->itimer_value.tv_sec--;
E 4
I 4
		}
		itp->it_value.tv_usec += 1000000;
		itp->it_value.tv_sec--;
E 4
	}
D 4
	itp->itimer_value.tv_usec -= usec;
	if (timerisset(&itp->itimer_value))
E 4
I 4
	itp->it_value.tv_usec -= usec;
	usec = 0;
	if (timerisset(&itp->it_value))
E 4
		return (1);
I 7
	/* expired, exactly at end of interval */
E 7
expire:
D 4
	if (itp->itimer_reload == 0)
		itp->itimer_value.tv_usec = 0;
	else
		itp->itimer_value = itp->itimer_interval;
E 4
I 4
	if (timerisset(&itp->it_interval)) {
		itp->it_value = itp->it_interval;
		itp->it_value.tv_usec -= usec;
		if (itp->it_value.tv_usec < 0) {
			itp->it_value.tv_usec += 1000000;
			itp->it_value.tv_sec--;
		}
	} else
D 7
		itp->it_value.tv_usec = 0;
E 7
I 7
		itp->it_value.tv_usec = 0;		/* sec is already 0 */
E 7
E 4
	return (0);
}

I 7
/*
 * Add and subtract routines for timevals.
 * N.B.: subtract routine doesn't deal with
 * results which are before the beginning,
 * it just gets very confused in this case.
 * Caveat emptor.
 */
timevaladd(t1, t2)
	struct timeval *t1, *t2;
{

	t1->tv_sec += t2->tv_sec;
	t1->tv_usec += t2->tv_usec;
	timevalfix(t1);
}

timevalsub(t1, t2)
	struct timeval *t1, *t2;
{

	t1->tv_sec -= t2->tv_sec;
	t1->tv_usec -= t2->tv_usec;
	timevalfix(t1);
}

timevalfix(t1)
	struct timeval *t1;
{

	if (t1->tv_usec < 0) {
		t1->tv_sec--;
		t1->tv_usec += 1000000;
	}
	if (t1->tv_usec >= 1000000) {
		t1->tv_sec++;
		t1->tv_usec -= 1000000;
	}
}
D 15

E 7
#ifndef NOCOMPAT
otime()
{

	u.u_r.r_time = time.tv_sec;
}

I 4
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

E 4
D 7
#include "../h/timeb.h"
E 7
I 7
/* from old timeb.h */
struct timeb {
	time_t	time;
	u_short	millitm;
	short	timezone;
	short	dstflag;
};
E 7

oftime()
{
E 3
	register struct a {
D 3
		time_t	(*times)[4];
E 3
I 3
		struct	timeb	*tp;
E 3
	} *uap;
D 3
	struct tms tms;
E 3
I 3
D 7
	struct timeb t;
E 7
I 7
	struct timeb tb;
E 7
E 3

D 3
	tms.tms_utime = u.u_vm.vm_utime;
	tms.tms_stime = u.u_vm.vm_stime;
	tms.tms_cutime = u.u_cvm.vm_utime;
	tms.tms_cstime = u.u_cvm.vm_stime;
E 3
	uap = (struct a *)u.u_ap;
D 3
	if (copyout((caddr_t)&tms, (caddr_t)uap->times, sizeof(struct tms)) < 0)
E 3
I 3
	(void) spl7();
D 7
	t.time = time.tv_sec;
	t.millitm = time.tv_usec / 1000;
E 7
I 7
	tb.time = time.tv_sec;
	tb.millitm = time.tv_usec / 1000;
E 7
	(void) spl0();
D 7
	t.timezone = tz.tz_minuteswest;
	t.dstflag = tz.tz_dsttime;
	if (copyout((caddr_t)&t, (caddr_t)uap->tp, sizeof(t)) < 0)
E 7
I 7
	tb.timezone = tz.tz_minuteswest;
	tb.dstflag = tz.tz_dsttime;
D 8
	if (copyout((caddr_t)&tb, (caddr_t)uap->tp, sizeof(t)) < 0)
E 8
I 8
D 13
	if (copyout((caddr_t)&tb, (caddr_t)uap->tp, sizeof (tb)) < 0)
E 8
E 7
E 3
		u.u_error = EFAULT;
E 13
I 13
	u.u_error = copyout((caddr_t)&tb, (caddr_t)uap->tp, sizeof (tb));
E 13
}
I 4
D 7
#endif
E 7
I 7

E 7
I 6
oalarm()
{
	register struct a {
		int	deltat;
	} *uap = (struct a *)u.u_ap;
	register struct proc *p = u.u_procp;
D 9
	struct timeval atv;
E 9
	int s = spl7();

D 7
	untimeout(unrto, p);
E 7
I 7
D 10
	untimeout(realitexpire, p);
E 10
I 10
	untimeout(realitexpire, (caddr_t)p);
E 10
E 7
	timerclear(&p->p_realtimer.it_interval);
	u.u_r.r_val1 = 0;
	if (timerisset(&p->p_realtimer.it_value) &&
	    timercmp(&p->p_realtimer.it_value, &time, >))
		u.u_r.r_val1 = p->p_realtimer.it_value.tv_sec - time.tv_sec;
	if (uap->deltat == 0) {
I 14
		timerclear(&p->p_realtimer.it_value);
E 14
		splx(s);
		return;
	}
	p->p_realtimer.it_value = time;
	p->p_realtimer.it_value.tv_sec += uap->deltat;
D 7
	timeout(unrto, p, hzto(&p->p_realtimer.it_value));
E 7
I 7
D 10
	timeout(realitexpire, p, hzto(&p->p_realtimer.it_value));
E 10
I 10
	timeout(realitexpire, (caddr_t)p, hzto(&p->p_realtimer.it_value));
E 10
E 7
	splx(s);
}
D 7

E 7
I 7
#endif
E 15
E 7
E 6
E 4
E 1
