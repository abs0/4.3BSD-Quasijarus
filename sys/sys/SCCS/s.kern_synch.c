h06849
s 00063/00001/00369
d D 7.6 87/12/11 00:13:44 mckusick 59 58
c comment decribing how p_cpu decay is computed (with help from shannon)
e
s 00000/00002/00370
d D 7.5 87/07/21 13:07:28 mckusick 58 57
c get rid of unneeded header files
e
s 00006/00005/00366
d D 7.4 87/02/19 17:29:23 karels 57 56
c make sleep spin-wait during autoconfiguration
e
s 00003/00004/00368
d D 7.3 86/11/30 18:07:57 karels 56 55
c clear slptime after stop; don't have to updatepri at high ipl
e
s 00002/00003/00370
d D 7.2 86/11/03 11:59:57 karels 55 54
c merge in tahoe support
e
s 00001/00001/00372
d D 7.1 86/06/05 00:04:49 mckusick 54 53
c 4.3BSD release version
e
s 00007/00001/00366
d D 6.10 85/06/08 14:38:24 mckusick 53 52
c Add copyright
e
s 00002/00001/00365
d D 6.9 85/06/07 15:33:15 karels 52 51
c ordering problem in wakeup, can't zero slptime before updatepri
e
s 00006/00002/00360
d D 6.8 85/06/02 22:58:32 karels 51 50
c if the change won't work, at least explain the obscurity happening;
c minor cleanup
e
s 00023/00010/00339
d D 6.7 85/05/27 19:12:50 mckusick 50 48
c round robin sleep queue (from edward@ucbmonet)
e
s 00026/00016/00333
d R 6.7 85/05/22 11:53:08 mckusick 49 48
c round robin sleep queue (from edward@monet)
e
s 00015/00002/00334
d D 6.6 85/03/18 15:20:04 karels 48 47
c sleep just drops priority briefly, then returns after a panic
c (no panic sleep, no rescheduling)
e
s 00049/00016/00287
d D 6.5 84/12/20 14:35:12 karels 47 46
c don't recalc pri of sleepers until awakened; no "panic sleep" after panics
e
s 00010/00010/00293
d D 6.4 84/08/29 20:20:29 bloom 46 45
c Change to includes.  no more ../h
e
s 00011/00007/00292
d D 6.3 84/07/31 17:29:55 karels 45 44
c move loop invariants in schedcpu; try to make curpri reflect
c the current process (still not right); curpri is always a usrpri
e
s 00001/00001/00298
d D 6.2 84/05/22 11:45:17 karels 44 43
c linked lists of active, zombie and free procs; avoid linear proc
c searches wherever possible
e
s 00000/00000/00299
d D 6.1 83/07/29 06:34:24 sam 43 42
c 4.2 distribution
e
s 00000/00014/00299
d D 4.26 83/05/21 15:35:05 sam 42 41
c no more mush
e
s 00005/00002/00308
d D 4.25 82/12/17 11:45:08 sam 41 40
c sun merge
e
s 00000/00001/00310
d D 4.24 82/10/21 20:57:27 root 40 39
c lint
e
s 00002/00002/00309
d D 4.23 82/10/17 21:49:18 root 39 38
c more lint
e
s 00001/00002/00310
d D 4.22 82/10/10 15:08:16 root 38 37
c split header files over to vax directories
e
s 00003/00091/00309
d D 4.21 82/09/08 07:57:28 root 37 36
c timeouts used for all timers now
e
s 00138/00170/00262
d D 4.20 82/09/06 22:49:31 root 36 35
c 
e
s 00029/00050/00403
d D 4.19 82/09/04 09:13:37 root 35 34
c new timer stuff and untested tsleep()
e
s 00011/00003/00442
d D 4.18 82/08/10 17:41:38 sam 34 33
c file locking
e
s 00022/00003/00423
d D 4.17 82/07/22 13:09:44 kre 33 32
c disc quotas / mush;
c father/son/brother proc pointers;
c fixed tsleep so it works with pri < PZERO
e
s 00001/00001/00425
d D 4.16 82/01/24 22:01:58 wnj 32 31
c clean up SDETACH
e
s 00062/00048/00364
d D 4.15 81/11/08 17:02:43 wnj 31 30
c cleanup and remove vrpages references
e
s 00001/00001/00411
d D 4.14 81/06/11 15:00:32 wnj 30 29
c fix to priority computation (|| with changes to clock.c)
e
s 00012/00006/00400
d D 4.13 81/04/17 17:54:32 wnj 29 28
c remove spurious high ipl's
e
s 00002/00000/00404
d D 4.12 81/04/15 12:36:40 wnj 28 27
c if running over limit in tight core situation, lower priority
e
s 00001/00000/00403
d D 4.11 81/04/13 20:34:47 root 27 26
c copy maxrss at fork time
e
s 00001/00001/00402
d D 4.10 81/03/09 01:48:55 wnj 26 25
c lint and a few minor fixed
e
s 00003/00011/00400
d D 4.9 81/03/06 11:38:36 wnj 25 24
c get rid of UCBIPC stuff
e
s 00001/00001/00410
d D 4.8 81/02/26 23:40:06 wnj 24 23
c rid of NPROC
e
s 00001/00009/00410
d D 4.7 81/02/26 04:24:56 wnj 23 22
c FASTVAX xxx or -> UNFAST
e
s 00003/00005/00416
d D 4.6 81/02/16 20:50:51 wnj 22 21
c eliminate wasteful wakeup of runin; aston() missing added
e
s 00007/00003/00414
d D 4.5 81/02/15 20:24:21 wnj 21 20
c new ast stuff
e
s 00011/00003/00406
d D 4.4 81/02/01 18:01:33 wnj 20 19
c UCBIPC crud
e
s 00001/00001/00408
d D 4.3 80/11/10 00:31:35 bill 19 18
c minor lint
e
s 00001/00001/00408
d D 4.2 80/11/09 23:35:04 bill 18 17
c function results (void)'ed for minor lint
e
s 00000/00000/00409
d D 4.1 80/11/09 17:32:37 bill 17 16
c minor fixups to restart stuff; version 4.1 for distrib
e
s 00001/00001/00408
d D 3.16 80/10/19 01:50:30 bill 16 15
c double slope of nice
e
s 00002/00002/00407
d D 3.15 80/10/11 21:32:11 bill 15 14
c %cpu
e
s 00001/00001/00408
d D 3.14 80/09/25 21:31:42 bill 14 13
c keep NUSIG on fork
e
s 00001/00001/00408
d D 3.13 80/07/13 14:13:33 bill 13 12
c inherit SDETACH on fork(), vfork()
e
s 00000/00001/00409
d D 3.12 80/06/24 19:28:50 bill 12 11
c no swplo
e
s 00001/00001/00409
d D 3.11 80/06/07 02:47:23 bill 11 10
c %H%->%G%
e
s 00004/00004/00406
d D 3.10 80/05/24 19:45:23 bill 10 9
c new signal stuff
e
s 00017/00021/00393
d D 3.9 80/05/18 11:34:40 bill 9 8
c first stab + revised sleep, wakeup
e
s 00044/00021/00370
d D 3.8 80/05/18 10:55:34 bill 8 7
c first attempt at new slp.c
e
s 00003/00003/00388
d D 3.7 80/05/08 10:22:56 bill 7 6
c VOID=>void
e
s 00005/00003/00386
d D 3.6 80/04/16 18:02:17 bill 6 5
c tsleep fixes per dmr
e
s 00001/00001/00388
d D 3.5 80/04/14 22:59:01 bill 5 4
c ick
e
s 00044/00000/00345
d D 3.4 80/04/14 19:19:53 bill 4 3
c added tsleep()
e
s 00000/00012/00345
d D 3.3 80/04/14 18:34:28 bill 3 2
c cleanup for reasonable setjmp(), longjmp()
e
s 00001/00001/00356
d D 3.2 80/04/12 17:24:26 bill 2 1
c fix comment about SSWAP
e
s 00357/00000/00000
d D 3.1 80/04/09 16:04:11 bill 1 0
c date and time created 80/04/09 16:04:11 by bill
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%H%	*/
E 11
I 11
D 26
/*	%M%	%I%	%G%	*/
E 26
I 26
D 53
/*	%M%	%I%	%E%	*/
E 53
I 53
/*
D 54
 * Copyright (c) 1982 Regents of the University of California.
E 54
I 54
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 54
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 53
E 26
E 11

I 41
#include "../machine/pte.h"
I 55
#include "../machine/psl.h"
#include "../machine/mtpr.h"
E 55

E 41
D 46
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/proc.h"
#include "../h/file.h"
#include "../h/inode.h"
#include "../h/vm.h"
D 41
#include "../h/pte.h"
E 41
I 8
D 38
#include "../h/inline.h"
I 21
#include "../h/mtpr.h"
E 38
I 36
D 42
#ifdef MUSH
E 36
I 33
#include "../h/quota.h"
I 36
#include "../h/share.h"
#endif
E 42
#include "../h/kernel.h"
#include "../h/buf.h"
E 46
I 46
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "proc.h"
D 58
#include "file.h"
#include "inode.h"
E 58
#include "vm.h"
#include "kernel.h"
#include "buf.h"
E 46
I 38
D 41
#include "../vax/mtpr.h"	/* XXX */
E 41
E 38
E 36
E 33
E 21
E 8

I 41
D 55
#ifdef vax
#include "../vax/mtpr.h"	/* XXX */
#endif
E 55
E 41
I 36
/*
 * Force switch among equal priority processes every 100ms.
 */
roundrobin()
{

	runrun++;
	aston();
D 39
	timeout(roundrobin, 0, hz / 10);
E 39
I 39
	timeout(roundrobin, (caddr_t)0, hz / 10);
E 39
}

D 37
/*
 * The digital decay cpu usage priority assignment is scaled to run in
 * time as expanded by the 1 minute load average.  Each second we
 * multiply the the previous cpu usage estimate by
 *		nrscale*avenrun[0]
 * The following relates the load average to the period over which
 * cpu usage is 90% forgotten:
 *	loadav 1	 5 seconds
 *	loadav 5	24 seconds
 *	loadav 10	47 seconds
 *	loadav 20	93 seconds
 * This is a great improvement on the previous algorithm which
 * decayed the priorities by a constant, and decayed away all knowledge
 * of previous activity in about 20 seconds.  Under heavy load,
 * the previous algorithm degenerated to round-robin with poor response
 * time when there was a high load average.
 */
E 37
I 37
D 47
/* constants to digital decay and forget 90% of usage in 5*loadav time */
E 37
#undef ave
#define	ave(a,b) ((int)(((int)(a*b))/(b+1)))
int	nrscale = 2;
E 47
I 47
D 59
/* fraction for digital decay to forget 90% of usage in 5*loadav sec */
E 59
I 59
/*
 * constants for digital decay and forget
 *	90% of (p_cpu) usage in 5*loadav time
 *	95% of (p_pctcpu) usage in 60 seconds (load insensitive)
 *          Note that, as ps(1) mentions, this can let percentages
 *          total over 100% (I've seen 137.9% for 3 processes).
 *
 * Note that hardclock updates p_cpu and p_cpticks independently.
 *
 * We wish to decay away 90% of p_cpu in (5 * loadavg) seconds.
 * That is, the system wants to compute a value of decay such
 * that the following for loop:
 * 	for (i = 0; i < (5 * loadavg); i++)
 * 		p_cpu *= decay;
 * will compute
 * 	p_cpu *= 0.1;
 * for all values of loadavg:
 *
 * Mathematically this loop can be expressed by saying:
 * 	decay ** (5 * loadavg) ~= .1
 *
 * The system computes decay as:
 * 	decay = (2 * loadavg) / (2 * loadavg + 1)
 *
 * We wish to prove that the system's computation of decay
 * will always fulfill the equation:
 * 	decay ** (5 * loadavg) ~= .1
 *
 * If we compute b as:
 * 	b = 2 * loadavg
 * then
 * 	decay = b / (b + 1)
 *
 * We now need to prove two things:
 *	1) Given factor ** (5 * loadavg) ~= .1, prove factor == b/(b+1)
 *	2) Given b/(b+1) ** power ~= .1, prove power == (5 * loadavg)
 *	
 * Facts:
 *         For x close to zero, exp(x) =~ 1 + x, since
 *              exp(x) = 0! + x**1/1! + x**2/2! + ... .
 *              therefore exp(-1/b) =~ 1 - (1/b) = (b-1)/b.
 *         For x close to zero, ln(1+x) =~ x, since
 *              ln(1+x) = x - x**2/2 + x**3/3 - ...     -1 < x < 1
 *              therefore ln(b/(b+1)) = ln(1 - 1/(b+1)) =~ -1/(b+1).
 *         ln(.1) =~ -2.30
 *
 * Proof of (1):
 *    Solve (factor)**(power) =~ .1 given power (5*loadav):
 *	solving for factor,
 *      ln(factor) =~ (-2.30/5*loadav), or
 *      factor =~ exp(-1/((5/2.30)*loadav) =~ exp(-1/(2*loadav)) =
 *          exp(-1/b) =~ (b-1)/b =~ b/(b+1).                    QED
 *
 * Proof of (2):
 *    Solve (factor)**(power) =~ .1 given factor == (b/(b+1)):
 *	solving for power,
 *      power*ln(b/(b+1)) =~ -2.30, or
 *      power =~ 2.3 * (b + 1) = 4.6*loadav + 2.3 =~ 5*loadav.  QED
 *
 * Actual power values for the implemented algorithm are as follows:
 *      loadav: 1       2       3       4
 *      power:  5.68    10.32   14.94   19.55
 */
E 59
#define	filter(loadav) ((2 * (loadav)) / (2 * (loadav) + 1))

E 47
D 40
double	avenrun[];
E 40
D 37

/*
 * Constant for decay filter for cpu usage field
 * in process table (used by ps au).
 */
E 37
double	ccpu = 0.95122942450071400909;		/* exp(-1/20) */

D 37
#ifdef MELB
E 37
/*
D 37
 * Automatic niceness rate & max constants
 */
#define	MAXNICE	(8 + NZERO)	/* maximum auto nice value */
#define	NFACT	(40 * hz)	/* nice++ every 40 secs cpu+sys time */
#endif

/*
E 37
 * Recompute process priorities, once a second
 */
schedcpu()
{
I 45
	register double ccpu1 = (1.0 - ccpu) / (double)hz;
E 45
	register struct proc *p;
	register int s, a;
I 47
	float scale = filter(avenrun[0]);
E 47

D 37
	s = spl6(); time.tv_sec += lbolt / hz; lbolt %= hz; splx(s);
E 37
	wakeup((caddr_t)&lbolt);
D 37

E 37
D 44
	for (p = proc; p < procNPROC; p++) if (p->p_stat && p->p_stat!=SZOMB) {
E 44
I 44
	for (p = allproc; p != NULL; p = p->p_nxt) {
E 44
D 42
#ifdef MUSH
D 37
		/*
		 * Charge process for memory in use
		 */
E 37
		if (p->p_quota->q_uid)
			p->p_quota->q_cost +=
			    shconsts.sc_click * p->p_rssize;
#endif
E 42
		if (p->p_time != 127)
			p->p_time++;
D 37
		if (timerisset(&p->p_seltimer) &&
		     --p->p_seltimer.tv_sec <= 0) {
			timerclear(&p->p_seltimer);
			s = spl6();
			switch (p->p_stat) {

			case SSLEEP:
				setrun(p);
				break;

			case SSTOP:
				unsleep(p);
				break;
			}
			splx(s);
		}
		if (timerisset(&p->p_realtimer.it_value) &&
		    itimerdecr(&p->p_realtimer, 1000000) == 0)
			psignal(p, SIGALRM);
E 37
		if (p->p_stat==SSLEEP || p->p_stat==SSTOP)
			if (p->p_slptime != 127)
				p->p_slptime++;
D 47
		if (p->p_flag&SLOAD)
D 45
			p->p_pctcpu = ccpu * p->p_pctcpu +
			    (1.0 - ccpu) * (p->p_cpticks/(float)hz);
E 45
I 45
			p->p_pctcpu = ccpu * p->p_pctcpu + ccpu1 * p->p_cpticks;
E 47
I 47
		/*
		 * If the process has slept the entire second,
		 * stop recalculating its priority until it wakes up.
		 */
		if (p->p_slptime > 1) {
			p->p_pctcpu *= ccpu;
			continue;
		}
		/*
		 * p_pctcpu is only for ps.
		 */
		p->p_pctcpu = ccpu * p->p_pctcpu + ccpu1 * p->p_cpticks;
E 47
E 45
		p->p_cpticks = 0;
D 42
#ifdef MUSH
E 42
D 47
		a = ave((p->p_cpu & 0377), avenrun[0]*nrscale) +
D 42
		     p->p_nice - NZERO + p->p_quota->q_nice;
#else
		a = ave((p->p_cpu & 0377), avenrun[0]*nrscale) +
E 42
		     p->p_nice - NZERO;
E 47
I 47
		a = (int) (scale * (p->p_cpu & 0377)) + p->p_nice;
E 47
D 42
#endif
E 42
		if (a < 0)
			a = 0;
		if (a > 255)
			a = 255;
		p->p_cpu = a;
		(void) setpri(p);
D 47
		s = spl6();	/* prevent state changes */
E 47
I 47
		s = splhigh();	/* prevent state changes */
E 47
		if (p->p_pri >= PUSER) {
I 45
#define	PPQ	(128 / NQS)
E 45
			if ((p != u.u_procp || noproc) &&
			    p->p_stat == SRUN &&
			    (p->p_flag & SLOAD) &&
D 45
			    p->p_pri != p->p_usrpri) {
E 45
I 45
			    (p->p_pri / PPQ) != (p->p_usrpri / PPQ)) {
E 45
				remrq(p);
				p->p_pri = p->p_usrpri;
				setrq(p);
			} else
				p->p_pri = p->p_usrpri;
		}
		splx(s);
	}
	vmmeter();
	if (runin!=0) {
		runin = 0;
		wakeup((caddr_t)&runin);
	}
	if (bclnlist != NULL)
		wakeup((caddr_t)&proc[2]);
D 39
	timeout(schedcpu, 0, hz);
E 39
I 39
	timeout(schedcpu, (caddr_t)0, hz);
E 39
}

I 47
/*
 * Recalculate the priority of a process after it has slept for a while.
 */
updatepri(p)
	register struct proc *p;
{
	register int a = p->p_cpu & 0377;
	float scale = filter(avenrun[0]);

	p->p_slptime--;		/* the first time was done in schedcpu */
	while (a && --p->p_slptime)
		a = (int) (scale * a) /* + p->p_nice */;
I 56
	p->p_slptime = 0;
E 56
	if (a < 0)
		a = 0;
	if (a > 255)
		a = 255;
	p->p_cpu = a;
	(void) setpri(p);
}

E 47
E 36
D 3
#ifdef FASTVAX
asm(" .globl _eintr");
#endif
E 3
D 21

E 21
#define SQSIZE 0100	/* Must be power of 2 */
#define HASH(x)	(( (int) x >> 5) & (SQSIZE-1))
D 50
struct proc *slpque[SQSIZE];
E 50
I 50
struct slpque {
	struct proc *sq_head;
	struct proc **sq_tailp;
} slpque[SQSIZE];
E 50

/*
 * Give up the processor till a wakeup occurs
 * on chan, at which time the process
 * enters the scheduling queue at priority pri.
 * The most important effect of pri is that when
 * pri<=PZERO a signal cannot disturb the sleep;
 * if pri>PZERO signals will be processed.
 * Callers of this routine must be prepared for
 * premature return, and check that the reason for
 * sleeping has gone away.
 */
sleep(chan, pri)
D 35
caddr_t chan;
E 35
I 35
	caddr_t chan;
	int pri;
E 35
{
D 9
	register struct proc *rp;
E 9
I 9
D 50
	register struct proc *rp, **hp;
E 50
I 50
	register struct proc *rp;
	register struct slpque *qp;
E 50
E 9
D 10
	register s, h;
E 10
I 10
	register s;
I 57
	extern int cold;
E 57
E 10

	rp = u.u_procp;
D 47
	s = spl6();
	if (chan==0 || rp->p_stat != SRUN || rp->p_rlink)
E 47
I 47
	s = splhigh();
D 48
	if ((chan==0 || rp->p_stat != SRUN || rp->p_rlink) &&
	    panicstr == (char *) NULL)
E 48
I 48
D 57
	if (panicstr) {
E 57
I 57
	if (cold || panicstr) {
E 57
		/*
D 57
		 * After a panic, just give interrupts a chance,
		 * then just return; don't run any other procs 
		 * or panic below, in case this is the idle process
		 * and already asleep.
E 57
I 57
		 * After a panic, or during autoconfiguration,
		 * just give interrupts a chance, then just return;
		 * don't run any other procs or panic below,
		 * in case this is the idle process and already asleep.
E 57
		 * The splnet should be spl0 if the network was being used
		 * by the filesystem, but for now avoid network interrupts
		 * that might cause another panic.
		 */
		(void) splnet();
		splx(s);
		return;
	}
	if (chan==0 || rp->p_stat != SRUN || rp->p_rlink)
E 48
E 47
		panic("sleep");
D 9
	rp->p_stat = SSLEEP;
E 9
	rp->p_wchan = chan;
	rp->p_slptime = 0;
	rp->p_pri = pri;
D 9
	h = HASH(chan);
	rp->p_link = slpque[h];
	slpque[h] = rp;
E 9
I 9
D 50
	hp = &slpque[HASH(chan)];
	rp->p_link = *hp;
	*hp = rp;
E 50
I 50
	qp = &slpque[HASH(chan)];
	if (qp->sq_head == 0)
		qp->sq_head = rp;
	else
		*qp->sq_tailp = rp;
	*(qp->sq_tailp = &rp->p_link) = 0;
E 50
E 9
D 31
	if(pri > PZERO) {
D 8
		if(rp->p_sig && issig()) {
E 8
I 8
		if(ISSIG(rp)) {
E 31
I 31
	if (pri > PZERO) {
I 51
		/*
		 * If we stop in issig(), wakeup may already have happened
		 * when we return (rp->p_wchan will then be 0).
		 */
E 51
		if (ISSIG(rp)) {
E 31
E 8
D 9
			rp->p_wchan = 0;
E 9
I 9
			if (rp->p_wchan)
				unsleep(rp);
E 9
			rp->p_stat = SRUN;
D 9
			slpque[h] = rp->p_link;
E 9
D 7
			VOID spl0();
E 7
I 7
			(void) spl0();
E 7
			goto psig;
		}
I 9
		if (rp->p_wchan == 0)
			goto out;
		rp->p_stat = SSLEEP;
E 9
D 7
		VOID spl0();
E 7
I 7
		(void) spl0();
I 35
		u.u_ru.ru_nvcsw++;
E 35
E 7
D 22
		if(runin != 0) {
			runin = 0;
			wakeup((caddr_t)&runin);
		}
E 22
		swtch();
D 8
		if(rp->p_sig && issig())
E 8
I 8
D 31
		if(ISSIG(rp))
E 31
I 31
		if (ISSIG(rp))
E 31
E 8
			goto psig;
	} else {
I 10
		rp->p_stat = SSLEEP;
E 10
D 7
		VOID spl0();
E 7
I 7
		(void) spl0();
I 35
		u.u_ru.ru_nvcsw++;
E 35
E 7
		swtch();
	}
I 45
	curpri = rp->p_usrpri;
E 45
I 9
out:
E 9
	splx(s);
	return;

	/*
	 * If priority was low (>PZERO) and
D 31
	 * there has been a signal,
	 * execute non-local goto to
	 * the qsav location.
	 * (see trap1/trap.c)
E 31
I 31
	 * there has been a signal, execute non-local goto through
D 37
	 * u.u_qsav, aborting the system call in progress (see trap.c)
E 37
I 37
	 * u.u_qsave, aborting the system call in progress (see trap.c)
E 37
D 47
	 * (or finishing a tsleep, see below)
E 47
E 31
	 */
psig:
D 3
#ifndef FASTVAX
E 3
D 37
	longjmp(u.u_qsav);
E 37
I 37
	longjmp(&u.u_qsave);
E 37
D 3
#else
	asm(".set U_SSAV,140");
	asm("movl _u+U_SSAV,fp");
	asm("movl _u+U_SSAV+4,sp");
	asm("movl _u+U_SSAV+8,r11");
	u.u_error = EINTR;
	asm("jmp _eintr");
#endif
E 3
	/*NOTREACHED*/
D 37
}

/*
I 4
D 35
 * Sleep on chan at pri.
 * Return in no more than the indicated number of seconds.
 * (If seconds==0, no timeout implied)
 * Return	TS_OK if chan was awakened normally
 *		TS_TIME if timeout occurred
 *		TS_SIG if asynchronous signal occurred
I 31
 *
 * SHOULD HAVE OPTION TO SLEEP TO ABSOLUTE TIME OR AN
 * INCREMENT IN MILLISECONDS!
E 35
I 35
 * Sleep on chan at pri for at most a specified amount of time.
 * Return (TS_OK,TS_TIME,TS_SIG) on (normal,timeout,signal) condition.
E 35
E 31
 */
D 35
tsleep(chan, pri, seconds)
E 35
I 35
tsleep(chan, pri, tvp)
E 35
D 31
caddr_t chan;
E 31
I 31
	caddr_t chan;
D 35
	int pri, seconds;
E 35
I 35
	int pri;
	struct timeval *tvp;
E 35
E 31
{
D 35
	label_t lqsav;
	register struct proc *pp;
D 33
	register sec, n, rval;
E 33
I 33
	register sec, n, rval, sov;
E 35
I 35
	register struct proc *p = u.u_procp;
	int s, rval;
E 35
E 33

D 35
	pp = u.u_procp;
I 5
	n = spl7();
E 5
	sec = 0;
	rval = 0;
I 33
	sov = 0;
E 33
D 5
	n = spl7();
E 5
	if (pp->p_clktim && pp->p_clktim<seconds)
D 33
		seconds = 0;
E 33
I 33
		if (pri > PZERO)
			seconds = 0;
		else
			sov++;
E 33
	if (seconds) {
		pp->p_flag |= STIMO;
D 6
		if ((sec = pp->p_clktim-seconds) < 0)
			sec = 0;
E 6
I 6
		sec = pp->p_clktim-seconds;
E 6
		pp->p_clktim = seconds;
	}
	bcopy((caddr_t)u.u_qsav, (caddr_t)lqsav, sizeof (label_t));
	if (setjmp(u.u_qsav))
		rval = TS_SIG;
	else {
E 35
I 35
	s = spl7();
D 36
	if (timercmp(tvp, &p->p_realtimer.itimer_value, >)) {
E 36
I 36
	if (timercmp(tvp, &p->p_realtimer.it_value, >)) {
E 36
		/* alarm will occur first! */
E 35
		sleep(chan, pri);
D 35
		if ((pp->p_flag&STIMO)==0 && seconds)
			rval = TS_TIME;
		else
E 35
I 35
		rval = TS_OK;		/* almost NOTREACHED modulo fuzz */
	} else {
		label_t lqsav;

		bcopy((caddr_t)u.u_qsav, (caddr_t)lqsav, sizeof (label_t));
		p->p_seltimer = *tvp;
		if (setjmp(u.u_qsav))
			rval = TS_SIG;
		else {
			sleep(chan, pri);
E 35
			rval = TS_OK;
D 35
	}
	pp->p_flag &= ~STIMO;
	bcopy((caddr_t)lqsav, (caddr_t)u.u_qsav, sizeof (label_t));
D 6
	pp->p_clktim += sec;
E 6
I 6
	if (sec > 0)
		pp->p_clktim += sec;
D 33
	else
E 33
I 33
	else if (sov) {
		if ((pp->p_clktim += sec) <= 0) {
			pp->p_clktim = 0;
			psignal(pp, SIGALRM);
E 35
		}
D 35
	} else
E 33
		pp->p_clktim = 0;
E 6
	splx(n);
E 35
I 35
		timerclear(&p->p_seltimer);
		bcopy((caddr_t)lqsav, (caddr_t)u.u_qsav, sizeof (label_t));
	}
	splx(s);
E 35
D 31
	return(rval);
E 31
I 31
	return (rval);
E 37
E 31
}

/*
I 8
 * Remove a process from its wait queue
 */
unsleep(p)
D 31
register struct proc *p;
E 31
I 31
	register struct proc *p;
E 31
{
I 50
	register struct slpque *qp;
E 50
	register struct proc **hp;
D 50
	register s;
E 50
I 50
	int s;
E 50

D 47
	s = spl6();
E 47
I 47
	s = splhigh();
E 47
	if (p->p_wchan) {
D 50
		hp = &slpque[HASH(p->p_wchan)];
E 50
I 50
		hp = &(qp = &slpque[HASH(p->p_wchan)])->sq_head;
E 50
		while (*hp != p)
			hp = &(*hp)->p_link;
		*hp = p->p_link;
I 50
		if (qp->sq_tailp == &p->p_link)
			qp->sq_tailp = hp;
E 50
		p->p_wchan = 0;
	}
	splx(s);
}

/*
E 8
E 4
 * Wake up all processes sleeping on chan.
 */
wakeup(chan)
D 31
register caddr_t chan;
E 31
I 31
	register caddr_t chan;
E 31
{
D 9
	register struct proc *p, *q;
	register i;
E 9
I 9
D 50
	register struct proc *p, **q, **h;
E 50
I 50
	register struct slpque *qp;
	register struct proc *p, **q;
E 50
E 9
	int s;

D 47
	s = spl6();
E 47
I 47
	s = splhigh();
E 47
D 9
	i = HASH(chan);
E 9
I 9
D 50
	h = &slpque[HASH(chan)];
E 50
I 50
	qp = &slpque[HASH(chan)];
E 50
E 9
restart:
D 9
	p = slpque[i];
	q = NULL;
	while(p != NULL) {
E 9
I 9
D 50
	for (q = h; p = *q; ) {
E 50
I 50
	for (q = &qp->sq_head; p = *q; ) {
E 50
E 9
D 8
		if (p->p_rlink || p->p_stat != SSLEEP)
E 8
I 8
		if (p->p_rlink || p->p_stat != SSLEEP && p->p_stat != SSTOP)
E 8
			panic("wakeup");
D 10
		if (p->p_wchan==chan && p->p_stat!=SZOMB) {
E 10
I 10
		if (p->p_wchan==chan) {
E 10
D 9
			if (q == NULL)
				slpque[i] = p->p_link;
			else
				q->p_link = p->p_link;
E 9
			p->p_wchan = 0;
I 9
			*q = p->p_link;
I 47
D 51
			if (p->p_slptime > 1)
				updatepri(p);
E 51
I 50
			if (qp->sq_tailp == &p->p_link)
				qp->sq_tailp = q;
E 50
E 47
E 9
D 52
			p->p_slptime = 0;
E 52
D 8
			/* OPTIMIZED INLINE EXPANSION OF setrun(p) */
			p->p_stat = SRUN;
			if (p->p_flag & SLOAD) {
E 8
I 8
			if (p->p_stat == SSLEEP) {
				/* OPTIMIZED INLINE EXPANSION OF setrun(p) */
I 51
				if (p->p_slptime > 1)
					updatepri(p);
I 52
D 56
				p->p_slptime = 0;
E 56
E 52
E 51
				p->p_stat = SRUN;
D 23
				if (p->p_flag & SLOAD) {
E 8
#ifndef FASTVAX
D 8
				p->p_link = runq;
				runq = p->p_link;
E 8
I 8
					p->p_link = runq;
					runq = p->p_link;
E 8
#else
E 23
I 23
				if (p->p_flag & SLOAD)
E 23
D 8
				setrq(p);
E 8
I 8
					setrq(p);
E 8
D 23
#endif
I 8
				}
E 23
D 21
				if(p->p_pri < curpri)
E 21
I 21
D 31
				if(p->p_pri < curpri) {
E 31
I 31
D 45
				if (p->p_pri < curpri) {
E 31
E 21
					runrun++;
I 21
					aston();
				}
E 45
I 45
				/*
				 * Since curpri is a usrpri,
				 * p->p_pri is always better than curpri.
				 */
				runrun++;
				aston();
E 45
E 21
D 29
				if(runout != 0 && (p->p_flag&SLOAD) == 0) {
					runout = 0;
					wakeup((caddr_t)&runout);
E 29
I 29
				if ((p->p_flag&SLOAD) == 0) {
					if (runout != 0) {
						runout = 0;
						wakeup((caddr_t)&runout);
					}
					wantin++;
E 29
				}
				/* END INLINE EXPANSION */
I 9
				goto restart;
E 9
E 8
			}
I 52
D 56
			p->p_slptime = 0;
E 56
E 52
D 8
			if(p->p_pri < curpri)
				runrun++;
			if(runout != 0 && (p->p_flag&SLOAD) == 0) {
				runout = 0;
				wakeup((caddr_t)&runout);
			}
			/* END INLINE EXPANSION */
E 8
D 9
			goto restart;
		}
		q = p;
		p = p->p_link;
E 9
I 9
		} else
			q = &p->p_link;
E 9
	}
	splx(s);
}

D 23
#ifdef FASTVAX
E 23
/*
 * Initialize the (doubly-linked) run queues
 * to be empty.
 */
rqinit()
{
	register int i;

	for (i = 0; i < NQS; i++)
		qs[i].ph_link = qs[i].ph_rlink = (struct proc *)&qs[i];
}
D 23
#endif
E 23

/*
 * Set the process running;
 * arrange for it to be swapped in if necessary.
 */
setrun(p)
D 31
register struct proc *p;
E 31
I 31
	register struct proc *p;
E 31
{
D 10
	register caddr_t w;
E 10
D 31
	register s;
E 31
I 31
	register int s;
E 31

D 47
	s = spl6();
E 47
I 47
	s = splhigh();
E 47
	switch (p->p_stat) {

	case 0:
	case SWAIT:
	case SRUN:
	case SZOMB:
	default:
		panic("setrun");

I 10
	case SSTOP:
E 10
	case SSLEEP:
D 8
		if (w = p->p_wchan) {
			wakeup(w);
			splx(s);
			return;
		}
E 8
I 8
		unsleep(p);		/* e.g. when sending signals */
E 8
		break;

	case SIDL:
D 10
	case SSTOP:
E 10
		break;
	}
I 47
D 56
	if (p->p_slptime > 1)
		updatepri(p);
E 56
E 47
	p->p_stat = SRUN;
	if (p->p_flag & SLOAD)
		setrq(p);
	splx(s);
I 56
	if (p->p_slptime > 1)
		updatepri(p);
E 56
D 21
	if(p->p_pri < curpri)
E 21
I 21
D 31
	if(p->p_pri < curpri) {
E 31
I 31
	if (p->p_pri < curpri) {
E 31
E 21
		runrun++;
I 21
		aston();
	}
E 21
D 29
	if(runout != 0 && (p->p_flag&SLOAD) == 0) {
		runout = 0;
		wakeup((caddr_t)&runout);
E 29
I 29
	if ((p->p_flag&SLOAD) == 0) {
D 31
		if(runout != 0) {
E 31
I 31
		if (runout != 0) {
E 31
			runout = 0;
			wakeup((caddr_t)&runout);
		}
		wantin++;
E 29
	}
}

/*
 * Set user priority.
 * The rescheduling flag (runrun)
 * is set if the priority is better
 * than the currently running process.
 */
setpri(pp)
D 31
register struct proc *pp;
E 31
I 31
	register struct proc *pp;
E 31
{
D 31
	register p;
E 31
I 31
	register int p;
E 31

D 30
	p = (pp->p_cpu & 0377)/16;
E 30
I 30
	p = (pp->p_cpu & 0377)/4;
E 30
D 16
	p += PUSER + pp->p_nice - NZERO;
E 16
I 16
D 47
	p += PUSER + 2*(pp->p_nice - NZERO);
E 47
I 47
	p += PUSER + 2 * pp->p_nice;
E 47
I 28
	if (pp->p_rssize > pp->p_maxrss && freemem < desfree)
		p += 2*4;	/* effectively, nice(4) */
E 28
E 16
D 31
	if(p > 127)
E 31
I 31
	if (p > 127)
E 31
		p = 127;
D 22
	if(p < curpri)
E 22
I 22
D 31
	if(p < curpri) {
E 31
I 31
	if (p < curpri) {
E 31
E 22
		runrun++;
I 22
		aston();
	}
E 22
	pp->p_usrpri = p;
D 31
	return(p);
E 31
I 31
	return (p);
E 31
D 36
}

/*
 * Create a new process-- the internal version of
 * sys fork.
 * It returns 1 in the new process, 0 in the old.
 */
newproc(isvfork)
I 31
	int isvfork;
E 31
{
	register struct proc *p;
	register struct proc *rpp, *rip;
	register int n;
I 34
	register struct file *fp;
E 34

	p = NULL;
	/*
	 * First, just locate a slot for a process
	 * and copy the useful info from this process into it.
	 * The panic "cannot happen" because fork has already
	 * checked for the existence of a slot.
	 */
retry:
	mpid++;
D 31
	if(mpid >= 30000) {
E 31
I 31
	if (mpid >= 30000) {
E 31
		mpid = 0;
		goto retry;
	}
D 24
	for(rpp = &proc[0]; rpp < &proc[NPROC]; rpp++) {
E 24
I 24
D 31
	for(rpp = proc; rpp < procNPROC; rpp++) {
E 24
		if(rpp->p_stat == NULL && p==NULL)
E 31
I 31
	for (rpp = proc; rpp < procNPROC; rpp++) {
		if (rpp->p_stat == NULL && p==NULL)
E 31
			p = rpp;
		if (rpp->p_pid==mpid || rpp->p_pgrp==mpid)
			goto retry;
	}
D 31
	if ((rpp = p)==NULL)
E 31
I 31
	if ((rpp = p) == NULL)
E 31
		panic("no procs");

	/*
D 31
	 * make proc entry for new proc
E 31
I 31
	 * Make a proc table entry for the new process.
E 31
	 */
D 31

E 31
	rip = u.u_procp;
I 33
#ifdef QUOTA
	(rpp->p_quota = rip->p_quota)->q_cnt++;
#endif
E 33
	rpp->p_stat = SIDL;
D 35
	rpp->p_clktim = 0;
E 35
I 35
	timerclear(&rpp->p_realtimer.itimer_value);
E 35
D 13
	rpp->p_flag = SLOAD | (rip->p_flag & SPAGI);
E 13
I 13
D 14
	rpp->p_flag = SLOAD | (rip->p_flag & (SPAGI|SDETACH));
E 14
I 14
D 32
	rpp->p_flag = SLOAD | (rip->p_flag & (SPAGI|SDETACH|SNUSIG));
E 32
I 32
	rpp->p_flag = SLOAD | (rip->p_flag & (SPAGI|SNUSIG));
E 32
E 14
E 13
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
I 8
	rpp->p_pptr = rip;
I 33
	rpp->p_osptr = rip->p_cptr;
	if (rip->p_cptr)
		rip->p_cptr->p_ysptr = rpp;
	rpp->p_ysptr = NULL;
	rpp->p_cptr = NULL;
	rip->p_cptr = rpp;
E 33
E 8
	rpp->p_time = 0;
	rpp->p_cpu = 0;
I 8
	rpp->p_siga0 = rip->p_siga0;
	rpp->p_siga1 = rip->p_siga1;
	/* take along any pending signals, like stops? */
E 8
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
I 27
	rpp->p_maxrss = rip->p_maxrss;
E 27
	rpp->p_wchan = 0;
	rpp->p_slptime = 0;
D 15
	rpp->p_aveflt = rip->p_aveflt;
D 12
	rate.v_pgin += rip->p_aveflt;
E 12
	rpp->p_faults = 0;
E 15
I 15
	rpp->p_pctcpu = 0;
	rpp->p_cpticks = 0;
E 15
	n = PIDHASH(rpp->p_pid);
	p->p_idhash = pidhash[n];
	pidhash[n] = rpp - proc;
I 31
	multprog++;
E 31

	/*
D 31
	 * make duplicate entries
	 * where needed
E 31
I 31
	 * Increase reference counts on shared objects.
E 31
	 */
D 31

	multprog++;

E 31
D 34
	for(n=0; n<NOFILE; n++)
D 31
		if(u.u_ofile[n] != NULL) {
E 31
I 31
		if (u.u_ofile[n] != NULL)
E 31
D 20
			u.u_ofile[n]->f_count++;
			if(!isvfork && u.u_vrpages[n])
				u.u_ofile[n]->f_inode->i_vfdcnt++;
E 20
I 20
D 25
#ifdef UCBIPC
			if (u.u_pofile[n] & ISPORT)
				u.u_oport[n]->pt_count++;
			else {
#endif
				u.u_ofile[n]->f_count++;
				if(!isvfork && u.u_vrpages[n])
					u.u_ofile[n]->f_inode->i_vfdcnt++;
#ifdef UCBIPC
			}
#endif UCBIPC
E 25
I 25
			u.u_ofile[n]->f_count++;
E 34
I 34
	for (n = 0; n < NOFILE; n++) {
		fp = u.u_ofile[n];
		if (fp == NULL)
			continue;
		fp->f_count++;
		if (u.u_pofile[n]&RDLOCK)
			fp->f_inode->i_rdlockc++;
		if (u.u_pofile[n]&WRLOCK)
			fp->f_inode->i_wrlockc++;
	}
E 34
D 31
			if(!isvfork && u.u_vrpages[n])
				u.u_ofile[n]->f_inode->i_vfdcnt++;
E 25
E 20
		}

E 31
	u.u_cdir->i_count++;
	if (u.u_rdir)
		u.u_rdir->i_count++;
I 31

E 31
	/*
	 * Partially simulate the environment
	 * of the new process so that when it is actually
	 * created (by copying) it will look right.
I 31
	 * This begins the section where we must prevent the parent
	 * from being swapped.
E 31
	 */
D 31

	rip->p_flag |= SKEEP;	/* prevent parent from being swapped */

E 31
I 31
	rip->p_flag |= SKEEP;
E 31
	if (procdup(rpp, isvfork))
		return (1);

I 31
	/*
	 * Make child runnable and add to run queue.
	 */
E 31
D 18
	spl6();
E 18
I 18
	(void) spl6();
E 18
	rpp->p_stat = SRUN;
	setrq(rpp);
D 19
	spl0();
E 19
I 19
	(void) spl0();
E 19
D 2
	/* THE SSWAP BIT IS REPLACED BY u.u_pcb.pcb_sswap SEE procdup */
E 2
I 2
D 31
	/* SSWAP NOT NEEDED IN THIS CASE AS u.u_pcb.pcb_sswap SUFFICES */
E 31
I 31

	/*
	 * Cause child to take a non-local goto as soon as it runs.
	 * On older systems this was done with SSWAP bit in proc
	 * table; on VAX we use u.u_pcb.pcb_sswap so don't need
	 * to do rpp->p_flag |= SSWAP.  Actually do nothing here.
	 */
E 31
E 2
	/* rpp->p_flag |= SSWAP; */
I 31

	/*
	 * Now can be swapped.
	 */
E 31
	rip->p_flag &= ~SKEEP;
I 31

	/*
	 * If vfork make chain from parent process to child
	 * (where virtal memory is temporarily).  Wait for
	 * child to finish, steal virtual memory back,
	 * and wakeup child to let it die.
	 */
E 31
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
D 31
		for (n = 0; n < NOFILE; n++)
			if (vfutl.u_vrpages[n]) {
				if ((u.u_vrpages[n] = vfutl.u_vrpages[n] - 1) == 0)
					if (--u.u_ofile[n]->f_inode->i_vfdcnt < 0)
						panic("newproc i_vfdcnt");
				vfutl.u_vrpages[n] = 0;
			}
E 31
		u.u_procp->p_flag &= ~SNOVM;
		rpp->p_ndx = rpp - proc;
		rpp->p_flag |= SVFDONE;
		wakeup((caddr_t)rpp);
	}
I 31

	/*
	 * 0 return means parent.
	 */
E 31
	return (0);
E 36
}
E 1
