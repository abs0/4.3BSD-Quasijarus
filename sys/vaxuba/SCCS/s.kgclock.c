h22258
s 00001/00001/00099
d D 7.1 86/06/05 01:11:11 mckusick 11 10
c 4.3BSD release version
e
s 00001/00000/00099
d D 6.5 85/09/19 15:55:41 karels 10 9
c kgprobe needs to return register set size
e
s 00007/00001/00092
d D 6.4 85/06/08 14:17:38 mckusick 9 8
c Add copyright
e
s 00006/00006/00087
d D 6.3 84/08/29 20:08:35 bloom 8 7
c Change to includes.  No more ../h
e
s 00008/00001/00085
d D 6.2 84/08/20 09:24:10 karels 7 6
c allow kgclock to be disabled
e
s 00000/00000/00086
d D 6.1 83/07/29 07:27:59 sam 6 5
c 4.2 distribution
e
s 00017/00012/00069
d D 4.4 83/05/30 18:33:30 sam 5 3
c cleanup, time is a struct timeval you know
e
s 00019/00014/00067
d R 4.4 83/05/30 17:45:45 sam 4 3
c cleanup
e
s 00012/00007/00069
d D 4.3 83/03/03 14:55:49 sam 3 2
c update includes to reflect 4.1c locations
e
s 00016/00000/00060
d D 4.2 83/03/01 18:03:32 mckusick 2 1
c add code to calibrate the other timer based on the wall clock
e
s 00060/00000/00000
d D 4.1 83/03/01 13:33:28 mckusick 1 0
c date and time created 83/03/01 13:33:28 by mckusick
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 11
 * Copyright (c) 1982 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9

D 5
#ifdef KGCLOCK		/* kl-11 as profiling clock */
E 5
I 5
#include "kg.h"
#if NKG > 0
/*
 * KL-11 as profiling clock
 */
#include "../machine/pte.h"
#include "../machine/psl.h"
E 5

I 3
D 8
#include "../h/param.h"
E 3
#include "../h/map.h"
D 5
#include "../h/pte.h"
E 5
#include "../h/buf.h"
I 5
#include "../h/time.h"
#include "../h/kernel.h"
E 8
I 8
#include "param.h"
#include "map.h"
#include "buf.h"
#include "time.h"
#include "kernel.h"
E 8

E 5
D 3
#include "../h/ubavar.h"
#include "../h/psl.h"
E 3
I 3
D 8
#include "../vaxuba/ubavar.h"
E 8
I 8
#include "ubavar.h"
E 8
D 5
#include "../machine/psl.h"
E 5
E 3

I 2
D 5
int	phz = 0;
E 5
E 2
int	kgprobe(), kgattach();
struct	uba_device *kginfo[1];
u_short	kgstd[] = { 0177560, 0 };
struct	uba_driver kgdriver =
    { kgprobe, 0, kgattach, 0, kgstd, "kg", kginfo };

struct klregs {
	u_short	fill[2];
	u_short	tcsr;
	u_short	tbuf;
};
#define	KLSTRT	0300		/* intr enbl + done */
struct	klregs *klbase;

I 7
int	usekgclock = 1;		/* if zero, kgclock is disabled */

E 7
kgprobe(reg)
D 5
caddr_t reg;
E 5
I 5
	caddr_t reg;
E 5
{
	register int br, cvec;	/* value-result */
	register struct klregs *klp = (struct klregs *)reg;

	klp->tcsr = KLSTRT;
	DELAY(100000);
	klp->tcsr = 0;
I 10
	return (sizeof(struct klregs));
E 10
}

kgattach(ui)
D 3
struct uba_device *ui;
E 3
I 3
	struct uba_device *ui;
E 3
{
I 3

E 3
	klbase = (struct klregs *)ui->ui_addr;
}

/*
 * start the sampling clock
 */
startkgclock()
{
I 3

E 3
D 7
	if (klbase)
E 7
I 7
	if (klbase && usekgclock && phz == 0)
E 7
		klbase->tcsr = KLSTRT;	/* enable interrupts */
}

/* ARGSUSED */
kgclock(dev, r0, r1, r2, r3, r4 ,r5, pc, ps)
D 3
caddr_t pc;
E 3
I 3
	caddr_t pc;
	int ps;
E 3
{
	register int k;
I 2
D 3
	static int otime = 0;
	static int calibrate;
E 3
I 3
D 5
	extern time_t time;
	static time_t otime = 0;
	static time_t calibrate;
E 5
I 5
	static long otime;
	static long calibrate;
E 5
E 3
E 2

I 7
	if (usekgclock == 0) {
		phz = 0;
		otime = 0;
		return;
	}
E 7
	klbase->tbuf = 0377;	/* reprime clock (scope sync too) */
I 2
	if (phz == 0) {
		if (otime == 0) {
D 5
			otime = time + 1;
E 5
I 5
			otime = time.tv_sec + 1;
E 5
			calibrate = 0;
		}
D 5
		if (time >= otime)
E 5
I 5
		if (time.tv_sec >= otime)
E 5
			calibrate++;
D 5
		if (time >= otime + 4) {
E 5
I 5
		if (time.tv_sec >= otime + 4) {
E 5
			phz = calibrate / 4;
			otime = 0;
		}
		return;
	}
E 2
D 3
	gatherstats();		/* this routine lives in kern_clock.c */
E 3
I 3
	gatherstats(pc, ps);	/* this routine lives in kern_clock.c */
E 3
}
D 5
#endif KGCLOCK
E 5
I 5
#endif
E 5
E 1
