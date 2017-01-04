h13995
s 00010/00005/00076
d D 7.2 88/06/29 17:34:29 bostic 8 7
c install approved copyright notice
e
s 00000/00000/00081
d D 7.1 88/05/26 09:09:52 karels 7 6
c bring up to revision 7 for tahoe release
e
s 00019/00006/00062
d D 1.5 88/05/26 09:05:14 karels 6 4
c lint, header cleanups
e
s 00017/00005/00063
d R 7.1 88/05/21 18:34:58 karels 5 4
c bring up to revision 7 for tahoe release
e
s 00006/00003/00062
d D 1.4 86/12/23 20:44:03 sam 4 3
c must have cp command block in data segment to insure vtoph 
c works with noproc; correct tick and tickadj when reseting hz
e
s 00050/00007/00015
d D 1.3 86/12/06 22:34:32 sam 3 2
c set interval timer value at boot time according to hz
e
s 00000/00000/00022
d D 1.2 86/01/05 18:42:17 sam 2 1
c 1st working version
e
s 00022/00000/00000
d D 1.1 85/07/22 21:55:54 sam 1 0
c date and time created 85/07/22 21:55:54 by sam
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 8
 *
 *	%W% (Berkeley) %G%
 */
E 6

D 3
#include "../h/param.h"
#include "../h/time.h"
#include "../h/kernel.h"
E 3
I 3
#include "param.h"
#include "time.h"
#include "kernel.h"

D 6
#include "../tahoe/cpu.h"
#include "../tahoe/mtpr.h"
E 3
#include "../tahoe/clock.h"
I 3
#include "../tahoe/cp.h"
E 6
I 6
#include "pte.h"
#include "cpu.h"
#include "mtpr.h"
#include "clock.h"
#include "cp.h"
E 6
E 3

/*
D 3
 * Initialze the time of day register, based on the time base which is, e.g.
 * from a filesystem.
E 3
I 3
 * Machine-dependent clock routines.
 *
 * Startrtclock restarts the real-time clock, which provides
 * hardclock interrupts to kern_clock.c.
 *
 * Inittodr initializes any time of day hardware which provides
 * date functions.  Its primary function is to use some file
 * system information in case the hardare clock lost state.
E 3
 */
I 3

/*
 * Start the real-time clock by initializing the
 * interval timer on the console processor card
 * according to hz.
 */
startrtclock()
{
	register int t;
D 4
	struct cphdr cpclock;
E 4
I 4
	static struct cphdr cpclock;	/* must be in data space */
E 4
	
	cpclock.cp_unit = CPCLOCK;
	cpclock.cp_comm = CPWRITE;
	if (hz == 0) {
I 4
		extern int tickadj;		/* XXX */
E 4
		hz = 60;
I 4
		tick = 1000000 / hz;
		tickadj = 240000 / (60 * hz);
E 4
		printf("clock set to %dhz\n", hz);
	}
	cpclock.cp_count = hztocount(hz);
D 4
	/* try to insure last cmd completed */
E 4
	if (cnlast) {
I 4
		/* try to insure last cmd was taken by cp */
E 4
		for (t = 30000; (cnlast->cp_unit&CPTAKE) == 0 && t > 0; t--)
			uncache(&cnlast->cp_unit);
		cnlast = 0;
	}
D 4
	mtpr(CPMDCB, &cpclock);
E 4
I 4
D 6
	mtpr(CPMDCB, vtoph((struct proc *)0, (unsigned)&cpclock));
E 6
I 6
	mtpr(CPMDCB, kvtophys(&cpclock));
E 6
E 4
	for (t = 30000; (cpclock.cp_unit&CPDONE) == 0 && t > 0; t--)
		uncache(&cpclock.cp_unit);
}

/*
 * Initialze the time of day register, based on
 * the time base which is, e.g. from a filesystem.
 */
E 3
inittodr(base)
	time_t base;
{

	if (base < 5*SECYR) {
D 3
		printf("WARNING: preposterous time in file system");
E 3
I 3
		printf("WARNING: preposterous time in file system ");
E 3
		time.tv_sec = 6*SECYR + 186*SECDAY + SECDAY/2;
	} else
		time.tv_sec = base;
D 3
	printf(" CHECK AND RESET THE DATE!\n");
E 3
I 3
	printf("CHECK AND RESET THE DATE!\n");
E 3
}
E 1
