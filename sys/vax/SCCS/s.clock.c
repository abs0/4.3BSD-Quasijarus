h33858
s 00010/00007/00233
d D 7.6 04/03/18 19:25:30 msokolov 11 10
c Long live DEC STD 032!
e
s 00007/00005/00233
d D 7.5 90/03/13 13:13:12 karels 10 9
c don't set todr to time zero
e
s 00002/00001/00236
d D 7.4 88/08/27 07:01:15 tef 9 8
c Add support for microvax 3000.
e
s 00002/00002/00235
d D 7.3 88/07/09 14:11:37 karels 8 7
c update copyrights
e
s 00150/00067/00087
d D 7.2 88/05/07 14:19:14 karels 7 6
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00001/00001/00153
d D 7.1 86/06/05 00:40:56 mckusick 6 5
c 4.3BSD release version
e
s 00030/00004/00124
d D 6.4 86/04/22 10:50:38 kridle 5 4
c Added MicroVAX II Support (KA630)
e
s 00007/00001/00121
d D 6.3 85/06/08 13:39:48 mckusick 4 3
c Add copyright
e
s 00005/00005/00117
d D 6.2 84/08/28 18:08:45 bloom 3 2
c Change to includes.  No more ../h
e
s 00000/00000/00122
d D 6.1 83/07/29 07:19:15 sam 2 1
c 4.2 distribution
e
s 00122/00000/00000
d D 4.1 83/02/10 21:57:52 sam 1 0
c date and time created 83/02/10 21:57:52 by sam
e
u
U
t
T
I 9

E 9
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
D 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 8
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

D 3
#include "../h/param.h"
#include "../h/time.h"
#include "../h/kernel.h"
E 3
I 3
#include "param.h"
#include "time.h"
#include "kernel.h"
E 3

D 3
#include "../vax/mtpr.h"
#include "../vax/clock.h"
E 3
I 3
#include "mtpr.h"
#include "clock.h"
I 5
#include "cpu.h"
I 11
#include "cpucond.h"
E 11
E 5
E 3

/*
 * Machine-dependent clock routines.
 *
 * Startrtclock restarts the real-time clock, which provides
 * hardclock interrupts to kern_clock.c.
 *
 * Inittodr initializes the time of day hardware which provides
 * date functions.  Its primary function is to use some file
 * system information in case the hardare clock lost state.
 *
 * Resettodr restores the time of day hardware after a time change.
 */

/*
 * Start the real-time clock.
 */
startrtclock()
{
D 5

	mtpr(NICR, -1000000/hz);
	mtpr(ICCS, ICCS_RUN+ICCS_IE+ICCS_TRANS+ICCS_INT+ICCS_ERR);
E 5
I 5
D 7
#ifdef VAX630
	if (cpu == VAX_630) {
		mtpr(ICCS, ICCS_IE);
	} else {
#endif
		mtpr(NICR, -1000000/hz);
		mtpr(ICCS, ICCS_RUN+ICCS_IE+ICCS_TRANS+ICCS_INT+ICCS_ERR);
#ifdef VAX630
	}
#endif
E 7
I 7

	(*cpuops->cpu_clock->clkstartrt)();
E 7
E 5
}

/*
 * Initialze the time of day register, based on the time base which is, e.g.
 * from a filesystem.  Base provides the time to within six months,
D 7
 * and the time of year clock provides the rest.
E 7
I 7
 * and the time of year clock (if any) provides the rest.
E 7
 */
inittodr(base)
	time_t base;
{
D 7
	register u_int todr = mfpr(TODR);
	long deltat;
	int year = YRREF;
D 5

E 5
I 5
#if VAX630
	/*
	 * If this is a Ka630, call ka630tod to handle the funny tod clock.
	 */
	if (cpu == VAX_630) {
		ka630tod(base);
		return;
	}
#endif
E 7
I 7
	long deltat, badbase = 0;

E 7
E 5
	if (base < 5*SECYR) {
D 7
		printf("WARNING: preposterous time in file system");
		time.tv_sec = 6*SECYR + 186*SECDAY + SECDAY/2;
		resettodr();
		goto check;
E 7
I 7
		printf("WARNING: preposterous time in file system\n");
		/* read the system clock anyway */
		base = 6*SECYR + 186*SECDAY + SECDAY/2;
		badbase = 1;
E 7
	}
I 7
	switch ((*cpuops->cpu_clock->clkread)(base)) {

	case CLKREAD_BAD:
		/*
		 * Believe the time in the file system for lack of
		 * anything better, resetting the TODR.
		 */
		time.tv_sec = base;
		if (!badbase)
			resettodr();
		break;

	case CLKREAD_WARN:
		break;

	case CLKREAD_OK:
		if (badbase)
			break;
		/*
		 * See if we gained/lost two or more days;
		 * if so, assume something is amiss.
		 */
		deltat = time.tv_sec - base;
		if (deltat < 0)
			deltat = -deltat;
		if (deltat < 2 * SECDAY)
			return;
		printf("WARNING: clock %s %d days",
		    time.tv_sec < base ? "lost" : "gained", deltat / SECDAY);
		break;

	default:
		panic("inittodr");
		/* NOTREACHED */
	}
	printf(" -- CHECK AND RESET THE DATE!\n");
}

/*
 * Reset the TODR based on the time value; used when the TODR
D 10
 * has a preposterous value and also when the time is reset
 * by the stime system call.  Also called when the TODR goes past
 * TODRZERO + 100*(SECYEAR+2*SECDAY) (e.g. on Jan 2 just after midnight)
 * to wrap the TODR around.
E 10
I 10
 * has a preposterous value, when the time is changed, and when rebooting.
 * Also called when the TODR goes past TODRZERO + 100*(SECYEAR+2*SECDAY)
 * (e.g. on Jan 2 just after midnight) to wrap the TODR around.
 * Avoid doing this if we haven't figured out the time yet
 * (e.g., when crashing during autoconfig).
E 10
 */
resettodr()
{

D 10
	(*cpuops->cpu_clock->clkwrite)();
E 10
I 10
	if (time.tv_sec)
		(*cpuops->cpu_clock->clkwrite)();
E 10
}

/*
D 11
 * ``Standard'' VAX clock routines.
E 11
I 11
 * Standard VAX (DEC STD 032) clock routines.
E 11
 */
D 11
#if VAX8600 || VAX8200 || VAX780 || VAX750 || VAX730
E 11
vaxstd_clkstartrt()
{

	mtpr(NICR, -1000000/hz);
	mtpr(ICCS, ICCS_RUN+ICCS_IE+ICCS_TRANS+ICCS_INT+ICCS_ERR);
}
D 11
#endif
E 11

D 9
#if VAX8600 || VAX780 || VAX750 || VAX730
E 9
I 9
D 11
#if VAX8600 || VAX780 || VAX750 || VAX730 || VAX650
E 11
I 11
uvax_clkstartrt()
{
	mtpr(ICCS, ICCS_IE);
}

E 11
E 9
vaxstd_clkread(base)
	time_t base;
{
	register u_int todr = mfpr(TODR);
	int year;

E 7
	/*
	 * TODRZERO is base used by VMS, which runs on local time.
	 */
	if (todr < TODRZERO) {
		printf("WARNING: todr too small");
D 7
		time.tv_sec = base;
		/*
		 * Believe the time in the file system for lack of
		 * anything better, resetting the TODR.
		 */
		resettodr();
		goto check;
E 7
I 7
		return (CLKREAD_BAD);
E 7
	}

	/*
D 8
	 * Sneak to within 6 month of the time in the filesystem,
E 8
I 8
	 * Sneak to within 6 months of the time in the filesystem,
E 8
	 * by starting with the time of the year suggested by the TODR,
	 * and advancing through succesive years.  Adding the number of
	 * seconds in the current year takes us to the end of the current year
	 * and then around into the next year to the same position.
	 */
D 7
	time.tv_sec = (todr-TODRZERO)/100;
	while (time.tv_sec < base-SECYR/2) {
E 7
I 7
	time.tv_sec = (todr - TODRZERO) / 100;
	year = YRREF;
	while (time.tv_sec < base - SECYR/2) {
E 7
		if (LEAPYEAR(year))
			time.tv_sec += SECDAY;
		year++;
		time.tv_sec += SECYR;
	}

D 7
	/*
	 * See if we gained/lost two or more days;
	 * if so, assume something is amiss.
	 */
	deltat = time.tv_sec - base;
	if (deltat < 0)
		deltat = -deltat;
	if (deltat < 2*SECDAY)
		return;
	printf("WARNING: clock %s %d days",
	    time.tv_sec < base ? "lost" : "gained", deltat / SECDAY);
check:
	printf(" -- CHECK AND RESET THE DATE!\n");
E 7
I 7
	return (CLKREAD_OK);
E 7
}

D 7
/*
 * Reset the TODR based on the time value; used when the TODR
 * has a preposterous value and also when the time is reset
 * by the stime system call.  Also called when the TODR goes past
 * TODRZERO + 100*(SECYEAR+2*SECDAY) (e.g. on Jan 2 just after midnight)
 * to wrap the TODR around.
 */
resettodr()
E 7
I 7
vaxstd_clkwrite()
E 7
{
	int year = YRREF;
	u_int secyr;
	u_int yrtime = time.tv_sec;
I 5

D 7
#if VAX630
E 7
	/*
D 7
	 * If this is a ka630, call ka630stod to set the funny tod clock.
	 */
	if (cpu == VAX_630) {
		ka630stod();
		return;
	}
#endif
E 5

	/*
E 7
	 * Whittle the time down to an offset in the current year,
	 * by subtracting off whole years as long as possible.
	 */
	for (;;) {
		secyr = SECYR;
		if (LEAPYEAR(year))
			secyr += SECDAY;
		if (yrtime < secyr)
			break;
		yrtime -= secyr;
		year++;
	}
	mtpr(TODR, TODRZERO + yrtime*100);
}
I 7
D 11
#endif
E 11

D 11
#if VAX8200 || VAX630
E 11
I 11
#if NEED_GREGTOY_SUPPORT
E 11
/*
 * This code is defunct after 2099.
D 11
 * Will Unix still be here then??
E 11
I 11
 * Hopefully by then we will get rid of this Gregorian calendar abomination
 * and TOY chips based on it, and everyone will implement TODR per DEC STD 032.
E 11
 */
short dayyr[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

chiptotime(c)
	register struct chiptime *c;
{
	register int days, yr;

	/* simple sanity checks */
	if (c->year < 70 || c->mon < 1 || c->mon > 12 ||
	    c->day < 1 || c->day > 31) {
		printf("WARNING: preposterous clock chip time");
		return (0);
	}
	days = 0;
	for (yr = 70; yr < c->year; yr++)
		days += LEAPYEAR(yr) ? 366 : 365;
	days += dayyr[c->mon - 1] + c->day - 1;
	if (LEAPYEAR(yr) && c->mon > 2)
		days++;
	/* now have days since Jan 1, 1970; the rest is easy... */
	return (days * SECDAY + c->hour * 3600 + c->min * 60 + c->sec);
}

timetochip(c)
	register struct chiptime *c;
{
	register int t, t2, t3;

	/* compute the year */
	t2 = time.tv_sec / SECDAY;
	t = 69;
	while (t2 >= 0) {	/* whittle off years */
		t3 = t2;
		t++;
		t2 -= LEAPYEAR(t) ? 366 : 365;
	}
	c->year = t;

	/* t3 = month + day; separate */
	t = LEAPYEAR(t);
	for (t2 = 1; t2 < 12; t2++)
		if (t3 < dayyr[t2] + (t && t2 > 1))
			break;

	/* t2 is month */
	c->mon = t2;
	c->day = t3 - dayyr[t2 - 1] + 1;
	if (t && t2 > 2)
		c->day--;

	/* the rest is easy */
	t = time.tv_sec % SECDAY;
	c->hour = t / 3600;
	t %= 3600;
	c->min = t / 60;
	c->sec = t % 60;
}
#endif
E 7
E 1
