h36218
s 00025/00000/00039
d D 7.2 88/05/07 14:19:17 karels 16 14
c vax 8200 support from torek: generalize cpu support, ops, clock ops
e
s 00005/00000/00039
d R 7.2 86/12/06 18:39:50 sam 15 14
c define enablertclock() as null
e
s 00001/00001/00038
d D 7.1 86/06/05 00:41:08 mckusick 14 13
c 4.3BSD release version
e
s 00007/00001/00032
d D 6.2 85/06/08 13:39:57 mckusick 13 12
c Add copyright
e
s 00000/00000/00033
d D 6.1 83/07/29 07:19:18 sam 12 11
c 4.2 distribution
e
s 00001/00005/00032
d D 4.8 82/10/31 15:31:10 root 11 10
c move clkstart macro into clock.c, where clock code is now
e
s 00001/00001/00036
d D 4.7 82/09/12 03:23:59 root 10 9
c NICR based on hz
e
s 00002/00004/00035
d D 4.6 82/09/04 09:29:54 root 9 8
c setsoftclock in asm.sed; clkreld in locore.s
e
s 00005/00005/00034
d D 4.5 81/02/23 20:33:25 wnj 8 7
c pad with 0's
e
s 00001/00001/00038
d D 4.4 81/02/19 21:39:25 wnj 7 6
c %G%->%E%
e
s 00005/00000/00034
d D 4.3 81/02/15 20:37:27 wnj 6 5
c ast and hard/soft clock
e
s 00001/00001/00033
d D 4.2 81/01/28 12:08:57 wnj 5 4
c fix LEAPYEAR for year 2000
e
s 00000/00000/00034
d D 4.1 80/11/09 17:00:40 bill 4 3
c stamp for 4bsd
e
s 00020/00006/00014
d D 3.3 80/09/16 17:26:28 bill 3 2
c typos
e
s 00001/00001/00019
d D 3.2 80/06/07 02:56:20 bill 2 1
c %H%->%G%
e
s 00020/00000/00000
d D 3.1 80/04/09 16:23:23 bill 1 0
c date and time created 80/04/09 16:23:23 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 7
/*	%M%	%I%	%G%	*/
E 7
I 7
D 13
/*	%M%	%I%	%E%	*/
E 13
I 13
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
E 13
E 7
E 2

/*
 * VAX clock registers
 */

D 8
#define	ICCS_RUN	0x1
#define	ICCS_TRANS	0x10
#define	ICCS_SS		0x20
#define	ICCS_IE		0x40
#define	ICCS_INT	0x80
E 8
I 8
#define	ICCS_RUN	0x00000001
#define	ICCS_TRANS	0x00000010
#define	ICCS_SS		0x00000020
#define	ICCS_IE		0x00000040
#define	ICCS_INT	0x00000080
E 8
#define	ICCS_ERR	0x80000000
	
D 3
/* THIS IS RIDICULOUS */
#define	YRCURR	1980		/* current year */
E 3
I 3
#define	SECDAY		((unsigned)(24*60*60))		/* seconds per day */
#define	SECYR		((unsigned)(365*SECDAY))	/* per common year */
/*
 * TODRZERO is the what the TODR should contain when the ``year'' begins.
 * The TODR should always contain a number between 0 and SECYR+SECDAY.
 */
#define	TODRZERO	((unsigned)(1<<28))
E 3

D 3
#define	YRREF	1970		/* reference year for time */
#define	SECHR	(60*60)		/* seconds/hr */
#define	SECDAY	(24*SECHR)	/* seconds/day */
#define	SECYR	(365*SECDAY)	/* seconds/common year */
E 3
I 3
#define	YRREF		1970
D 5
#define	LEAPYEAR(year)	((year)%4==0 && year != 2000)	/* good till 2100 */
E 5
I 5
#define	LEAPYEAR(year)	((year)%4==0)	/* good till time becomes negative */
E 5

/*
D 11
 * Start a 60 HZ clock.
E 11
I 11
 * Has the time-of-day clock wrapped around?
E 11
 */
D 11
#define	clkstart() {\
D 10
	mtpr(NICR, -16667);	/* 16.667 milli-seconds */\
E 10
I 10
	mtpr(NICR, -1000000/hz);	/* 10 milli-seconds */\
E 10
	mtpr(ICCS, ICCS_RUN+ICCS_IE+ICCS_TRANS+ICCS_INT+ICCS_ERR);\
}
E 11
D 9
#define	clkreld()	mtpr(ICCS, ICCS_RUN+ICCS_IE+ICCS_INT+ICCS_ERR)

E 9
#define	clkwrap()	(((unsigned)mfpr(TODR) - TODRZERO)/100 > SECYR+SECDAY)
I 6

/*
D 9
 * Software clock is software interrupt level 8
E 9
I 9
 * Software clock is software interrupt level 8,
 * implemented as mtpr(SIRR, 0x8) in asm.sed.
E 9
 */
I 16

#ifndef LOCORE
/*
 * 8200s and 630s have a clock chip like those found in digital alarm
 * clocks and watches.  Converting this to and from system times is
 * painful, so we do it in only one place.  The routine chiptotime()
 * converts a chiptime to the right value for time.tv_sec, and
 * timetochip converts time.tv_sec back.
 */
struct chiptime {
	int	sec;
	int	min;
	int	hour;
	int	day;
	int	mon;
	int	year;
};

/*
 * Clock read routine return values.
 */
#define	CLKREAD_OK	0	/* success, time.tv_sec set */
#define	CLKREAD_WARN	1	/* clock appears wrong but time set anyway */
#define	CLKREAD_BAD	2	/* clock is bad, no time available */
#endif
E 16
D 9
#define	setsoftclock()	mtpr(SIRR, 0x8)
E 9
E 6
E 3
E 1
