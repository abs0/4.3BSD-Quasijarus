h11093
s 00002/00002/00184
d D 5.6 88/05/19 15:39:09 bostic 12 11
c install C version of _doprnt
e
s 00012/00012/00174
d D 5.5 87/06/25 09:15:26 bostic 11 10
c csh long/int mismatches; bug report 4.3BSD/bin/45
e
s 00001/00002/00185
d D 5.4 86/05/13 01:07:23 lepreau 10 9
c nice is absolute (note that in 5.2 and before "nice +<num>" was relative.)
e
s 00005/00003/00182
d D 5.3 86/01/12 02:34:21 lepreau 9 8
c nice is relative, not absolute. (Kirk "authorized" it.)
e
s 00003/00003/00182
d D 5.2 85/06/06 13:08:23 edward 8 7
c cleaning up after bozos
e
s 00008/00002/00177
d D 5.1 85/06/04 11:08:28 dist 7 6
c Add copyright
e
s 00008/00010/00171
d D 4.6 84/12/13 14:38:55 edward 6 5
c performance
e
s 00005/00013/00176
d D 4.5 84/10/13 17:35:39 sam 5 4
c fix nice
e
s 00003/00001/00186
d D 4.4 83/08/11 20:13:09 sam 4 3
c standardize sccs keyword lines
e
s 00010/00008/00177
d D 4.3 83/02/03 09:13:16 sam 3 2
c use high precision time calls
e
s 00073/00068/00112
d D 4.2 82/12/30 17:35:50 sam 2 1
c finally works (updated for 4.1c and merged with sun)
e
s 00180/00000/00000
d D 4.1 80/10/09 12:41:59 bill 1 0
c date and time created 80/10/09 12:41:59 by bill
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
E 8
I 8
 * All rights reserved.  The Berkeley Software License Agreement
E 8
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
D 2
static	char *sccsid = "%Z%%M% %I% %G%";
E 2
I 2
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
#ifndef lint
D 6
static char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
D 7
static char *sccsid = "%W% (Berkeley) %G%";
E 6
#endif
E 7
I 7
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8
I 8
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 8
E 7
E 4
E 2

#include "sh.h"

/*
 * C Shell - routines handling process timing and niceing
 */
D 2
#ifdef VMUNIX
struct	vtimes vm0;
#else
E 2
D 6
struct	tms times0;
struct	tms timesdol;
E 6
D 2
#endif
E 2

settimes()
{
I 2
	struct rusage ruch;
E 2

D 3
	time(&time0);
E 3
I 3
D 6
	gettimeofday(&time0, (struct timezone *)0);
E 3
D 2
#ifdef VMUNIX
	vtimes(&vm0, 0);
#else
	times(&times0);
#endif
E 2
I 2
	getrusage(RUSAGE_SELF, &ru0);
	getrusage(RUSAGE_CHILDREN, &ruch);
E 6
I 6
	(void) gettimeofday(&time0, (struct timezone *)0);
	(void) getrusage(RUSAGE_SELF, &ru0);
	(void) getrusage(RUSAGE_CHILDREN, &ruch);
E 6
	ruadd(&ru0, &ruch);
E 2
}

/*
 * dotime is only called if it is truly a builtin function and not a
 * prefix to another command
 */
dotime()
{
D 3
	time_t timedol;
E 3
I 3
	struct timeval timedol;
E 3
D 2
#ifdef VMUNIX
	struct vtimes vm1, vmch;
E 2
I 2
	struct rusage ru1, ruch;
E 2

D 2
	vtimes(&vm1, &vmch);
	vmsadd(&vm1, &vmch);
#endif

E 2
I 2
D 6
	getrusage(RUSAGE_SELF, &ru1);
	getrusage(RUSAGE_CHILDREN, &ruch);
E 6
I 6
	(void) getrusage(RUSAGE_SELF, &ru1);
	(void) getrusage(RUSAGE_CHILDREN, &ruch);
E 6
	ruadd(&ru1, &ruch);
E 2
D 3
	time(&timedol);
D 2
#ifdef VMUNIX
	pvtimes(&vm0, &vm1, timedol - time0);
#else
	times(&timesdol);
	ptimes(timedol - time0, &times0, &timesdol);
#endif
E 2
I 2
	prusage(&ru0, &ru1, timedol - time0);
E 3
I 3
D 6
	gettimeofday(&timedol, (struct timezone *)0);
E 6
I 6
	(void) gettimeofday(&timedol, (struct timezone *)0);
E 6
	prusage(&ru0, &ru1, &timedol, &time0);
E 3
E 2
}

/*
 * donice is only called when it on the line by itself or with a +- value
 */
donice(v)
	register char **v;
{
	register char *cp;
I 9
	int nval;
E 9

	v++, cp = *v++;
D 5
	if (cp == 0) {
#ifndef V6
		nice(20);
		nice(-10);
#endif
		nice(4);
	} else if (*v == 0 && any(cp[0], "+-")) {
#ifndef V6
		nice(20);
		nice(-10);
#endif
		nice(getn(cp));
	}
E 5
I 5
	if (cp == 0)
D 9
		(void) setpriority(PRIO_PROCESS, 0, 4);
E 9
I 9
		nval = 4;
E 9
	else if (*v == 0 && any(cp[0], "+-"))
D 9
		(void) setpriority(PRIO_PROCESS, 0, 
		    getpriority(PRIO_PROCESS, 0) + getn(cp));
E 9
I 9
		nval = getn(cp);
D 10
	(void) setpriority(PRIO_PROCESS, 0,
		getpriority(PRIO_PROCESS, 0) + nval);
E 10
I 10
	(void) setpriority(PRIO_PROCESS, 0, nval);
E 10
E 9
E 5
}

D 2
#ifndef VMUNIX
ptimes(utime, stime, etime)
	register time_t utime, stime, etime;
E 2
I 2
ruadd(ru, ru2)
	register struct rusage *ru, *ru2;
E 2
{
I 2
	register long *lp, *lp2;
	register int cnt;
E 2

D 2
	p60ths(utime);
	printf("u ");
	p60ths(stime);
	printf("s ");
	psecs(etime);
	printf(" %d%%\n", (int) (100 * (utime+stime) /
		(60 * (etime ? etime : 1))));
E 2
I 2
	tvadd(&ru->ru_utime, &ru2->ru_utime);
	tvadd(&ru->ru_stime, &ru2->ru_stime);
	if (ru2->ru_maxrss > ru->ru_maxrss)
		ru->ru_maxrss = ru2->ru_maxrss;
	cnt = &ru->ru_last - &ru->ru_first + 1;
	lp = &ru->ru_first; lp2 = &ru2->ru_first;
	do
		*lp++ += *lp2++;
	while (--cnt > 0);
E 2
}

D 2
#else
vmsadd(vp, wp)
	register struct vtimes *vp, *wp;
{

	vp->vm_utime += wp->vm_utime;
	vp->vm_stime += wp->vm_stime;
	vp->vm_nswap += wp->vm_nswap;
	vp->vm_idsrss += wp->vm_idsrss;
	vp->vm_ixrss += wp->vm_ixrss;
	if (vp->vm_maxrss < wp->vm_maxrss)
		vp->vm_maxrss = wp->vm_maxrss;
	vp->vm_majflt += wp->vm_majflt;
	vp->vm_minflt += wp->vm_minflt;
	vp->vm_inblk += wp->vm_inblk;
	vp->vm_oublk += wp->vm_oublk;
}

pvtimes(v0, v1, sec)
	register struct vtimes *v0, *v1;
E 2
I 2
D 3
prusage(r0, r1, sec)
E 3
I 3
prusage(r0, r1, e, b)
E 3
	register struct rusage *r0, *r1;
E 2
D 3
	time_t sec;
E 3
I 3
	struct timeval *e, *b;
E 3
{
	register time_t t =
D 2
	    (v1->vm_utime-v0->vm_utime)+(v1->vm_stime-v0->vm_stime);
E 2
I 2
	    (r1->ru_utime.tv_sec-r0->ru_utime.tv_sec)*100+
	    (r1->ru_utime.tv_usec-r0->ru_utime.tv_usec)/10000+
	    (r1->ru_stime.tv_sec-r0->ru_stime.tv_sec)*100+
	    (r1->ru_stime.tv_usec-r0->ru_stime.tv_usec)/10000;
E 2
	register char *cp;
D 11
	register int i;
E 11
I 11
	register long i;
E 11
	register struct varent *vp = adrof("time");
I 3
D 11
	int ms =
E 11
I 11
	long ms =
E 11
	    (e->tv_sec-b->tv_sec)*100 + (e->tv_usec-b->tv_usec)/10000;
E 3

	cp = "%Uu %Ss %E %P %X+%Dk %I+%Oio %Fpf+%Ww";
	if (vp && vp->vec[0] && vp->vec[1])
		cp = vp->vec[1];
	for (; *cp; cp++)
	if (*cp != '%')
D 12
		putchar(*cp);
E 12
I 12
		cshputchar(*cp);
E 12
	else if (cp[1]) switch(*++cp) {

	case 'U':
D 2
		p60ths(v1->vm_utime - v0->vm_utime);
E 2
I 2
		pdeltat(&r1->ru_utime, &r0->ru_utime);
E 2
		break;

	case 'S':
D 2
		p60ths(v1->vm_stime - v0->vm_stime);
E 2
I 2
		pdeltat(&r1->ru_stime, &r0->ru_stime);
E 2
		break;

	case 'E':
D 3
		psecs(sec);
E 3
I 3
D 6
		psecs(ms / 100);
E 6
I 6
D 11
		psecs((long)(ms / 100));
E 11
I 11
		psecs(ms / 100);
E 11
E 6
E 3
		break;

	case 'P':
D 2
		printf("%d%%", (int) ((100 * t) / (60 * (sec ? sec : 1))));
E 2
I 2
D 3
		printf("%d%%", (int) (t / ((sec ? sec : 1))));
E 3
I 3
		printf("%d%%", (int) (t*100 / ((ms ? ms : 1))));
E 3
E 2
		break;

	case 'W':
D 2
		i = v1->vm_nswap - v0->vm_nswap;
E 2
I 2
		i = r1->ru_nswap - r0->ru_nswap;
E 2
D 11
		printf("%d", i);
E 11
I 11
		printf("%ld", i);
E 11
		break;

	case 'X':
D 2
		printf("%d", t == 0 ? 0 : (v1->vm_ixrss-v0->vm_ixrss)/(2*t));
E 2
I 2
D 11
		printf("%d", t == 0 ? 0 : (r1->ru_ixrss-r0->ru_ixrss)/t);
E 11
I 11
		printf("%ld", t == 0 ? 0L : (r1->ru_ixrss-r0->ru_ixrss)/t);
E 11
E 2
		break;

	case 'D':
D 2
		printf("%d", t == 0 ? 0 : (v1->vm_idsrss-v0->vm_idsrss)/(2*t));
E 2
I 2
D 11
		printf("%d", t == 0 ? 0 :
E 11
I 11
		printf("%ld", t == 0 ? 0L :
E 11
		    (r1->ru_idrss+r1->ru_isrss-(r0->ru_idrss+r0->ru_isrss))/t);
E 2
		break;

	case 'K':
D 2
		printf("%d", t == 0 ? 0 : ((v1->vm_ixrss+v1->vm_idsrss) -
		   (v0->vm_ixrss+v0->vm_idsrss))/(2*t));
E 2
I 2
D 11
		printf("%d", t == 0 ? 0 :
E 11
I 11
		printf("%ld", t == 0 ? 0L :
E 11
		    ((r1->ru_ixrss+r1->ru_isrss+r1->ru_idrss) -
		    (r0->ru_ixrss+r0->ru_idrss+r0->ru_isrss))/t);
E 2
		break;

	case 'M':
D 2
		printf("%d", v1->vm_maxrss/2);
E 2
I 2
D 11
		printf("%d", r1->ru_maxrss/2);
E 11
I 11
		printf("%ld", r1->ru_maxrss/2);
E 11
E 2
		break;

	case 'F':
D 2
		printf("%d", v1->vm_majflt-v0->vm_majflt);
E 2
I 2
D 11
		printf("%d", r1->ru_majflt-r0->ru_majflt);
E 11
I 11
		printf("%ld", r1->ru_majflt-r0->ru_majflt);
E 11
E 2
		break;

	case 'R':
D 2
		printf("%d", v1->vm_minflt-v0->vm_minflt);
E 2
I 2
D 11
		printf("%d", r1->ru_minflt-r0->ru_minflt);
E 11
I 11
		printf("%ld", r1->ru_minflt-r0->ru_minflt);
E 11
E 2
		break;

	case 'I':
D 2
		printf("%d", v1->vm_inblk-v0->vm_inblk);
E 2
I 2
D 11
		printf("%d", r1->ru_inblock-r0->ru_inblock);
E 11
I 11
		printf("%ld", r1->ru_inblock-r0->ru_inblock);
E 11
E 2
		break;

	case 'O':
D 2
		printf("%d", v1->vm_oublk-v0->vm_oublk);
E 2
I 2
D 11
		printf("%d", r1->ru_oublock-r0->ru_oublock);
E 11
I 11
		printf("%ld", r1->ru_oublock-r0->ru_oublock);
E 11
E 2
		break;
D 2

E 2
	}
D 12
	putchar('\n');
E 12
I 12
	cshputchar('\n');
E 12
}
D 2
#endif
E 2
I 2

pdeltat(t1, t0)
	struct timeval *t1, *t0;
{
	struct timeval td;

	tvsub(&td, t1, t0);
	printf("%d.%01d", td.tv_sec, td.tv_usec/100000);
}

tvadd(tsum, t0)
	struct timeval *tsum, *t0;
{

	tsum->tv_sec += t0->tv_sec;
	tsum->tv_usec += t0->tv_usec;
	if (tsum->tv_usec > 1000000)
		tsum->tv_sec++, tsum->tv_usec -= 1000000;
}

tvsub(tdiff, t1, t0)
	struct timeval *tdiff, *t1, *t0;
{

	tdiff->tv_sec = t1->tv_sec - t0->tv_sec;
	tdiff->tv_usec = t1->tv_usec - t0->tv_usec;
	if (tdiff->tv_usec < 0)
		tdiff->tv_sec--, tdiff->tv_usec += 1000000;
}
E 2
E 1
