h29106
s 00001/00001/00141
d D 5.3 87/06/25 09:15:18 bostic 14 13
c csh long/int mismatches; bug report 4.3BSD/bin/45
e
s 00003/00003/00139
d D 5.2 85/06/06 13:08:40 edward 13 12
c cleaning up after bozos
e
s 00008/00002/00134
d D 5.1 85/06/04 11:00:03 dist 12 11
c Add copyright
e
s 00017/00007/00119
d D 4.10 85/03/19 18:30:51 mckusick 11 10
c better argument cracking
e
s 00020/00017/00106
d D 4.9 84/12/13 14:39:13 edward 10 9
c performance
e
s 00003/00006/00120
d D 4.8 84/10/15 10:00:07 ralph 9 8
c don't loop if option unknown (history -x).
e
s 00001/00001/00125
d D 4.7 84/08/31 09:30:59 ralph 8 7
c use new signal calls instead of compatibility routines.
e
s 00001/00001/00125
d D 4.6 83/06/11 16:49:39 sam 7 6
c different approach, try signal compatibility package
e
s 00001/00001/00125
d D 4.5 83/06/10 23:59:23 sam 6 5
c new signals; no libjobs; still loses SIGINT by getting it masked 
c sometimes, but we check it in before we lose something
e
s 00001/00001/00125
d D 4.4 82/12/30 17:35:18 sam 5 4
c finally works (updated for 4.1c and merged with sun)
e
s 00015/00015/00111
d D 4.3 81/11/19 21:04:04 mckusic 4 2
c add ``history -h >file'' and ``source -h file'' to 
c implement history save and restore.
e
s 00003/00003/00123
d R 4.3 81/08/20 23:47:45 mckusic 3 2
c put in history save and restore
e
s 00019/00011/00107
d D 4.2 81/08/18 17:00:37 mckusic 2 1
c save history in ~/.history at logout and restore at login
e
s 00118/00000/00000
d D 4.1 80/10/09 12:41:10 bill 1 0
c date and time created 80/10/09 12:41:10 by bill
e
u
U
t
T
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
D 13
 * All rights reserved.  The Berkeley software License Agreement
E 13
I 13
 * All rights reserved.  The Berkeley Software License Agreement
E 13
 * specifies the terms and conditions for redistribution.
 */

E 12
I 1
D 10
static	char *sccsid = "%Z%%M% %I% %G%";
E 10
I 10
#ifndef lint
D 12
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 12
I 12
D 13
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 13
I 13
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 13
E 12
E 10

#include "sh.h"

/*
 * C shell
 */

savehist(sp)
	struct wordent *sp;
{
	register struct Hist *hp, *np;
D 10
	int histlen;
	register char *cp;
E 10
I 10
	register int histlen = 0;
	char *cp;
E 10

D 10
	cp = value("history");
	if (*cp == 0)
		histlen = 0;
	else {
		while (*cp && digit(*cp))
			cp++;
		/* avoid a looping snafu */
		if (*cp)
			set("history", "10");
		histlen = getn(value("history"));
	}
E 10
	/* throw away null lines */
	if (sp->next->word[0] == '\n')
		return;
I 10
	cp = value("history");
	if (*cp) {
		register char *p = cp;

		while (*p) {
			if (!digit(*p)) {
				histlen = 0;
				break;
			}
			histlen = histlen * 10 + *p++ - '0';
		}
	}
E 10
	for (hp = &Histlist; np = hp->Hnext;)
		if (eventno - np->Href >= histlen || histlen == 0)
			hp->Hnext = np->Hnext, hfree(np);
		else
			hp = np;
D 10
	enthist(++eventno, sp, 1);
E 10
I 10
	(void) enthist(++eventno, sp, 1);
E 10
}

struct Hist *
enthist(event, lp, docopy)
	int event;
	register struct wordent *lp;
	bool docopy;
{
	register struct Hist *np;

D 10
	np = (struct Hist *) calloc(1, sizeof *np);
E 10
I 10
	np = (struct Hist *) xalloc(sizeof *np);
E 10
	np->Hnum = np->Href = event;
	if (docopy)
		copylex(&np->Hlex, lp);
	else {
		np->Hlex.next = lp->next;
		lp->next->prev = &np->Hlex;
		np->Hlex.prev = lp->prev;
		lp->prev->next = &np->Hlex;
	}
	np->Hnext = Histlist.Hnext;
	Histlist.Hnext = np;
	return (np);
}

hfree(hp)
	register struct Hist *hp;
{

	freelex(&hp->Hlex);
	xfree((char *)hp);
}

dohist(vp)
	char **vp;
{
D 2
	int n, rflg = 0;
E 2
I 2
D 4
	int n, rflg = 0, cflg = 0;
E 2

E 4
I 4
	int n, rflg = 0, hflg = 0;
E 4
	if (getn(value("history")) == 0)
		return;
	if (setintr)
D 6
		sigrelse(SIGINT);
E 6
I 6
D 7
		(void) sigrelse(mask(SIGINT));
E 7
I 7
D 8
		sigrelse(SIGINT);
E 8
I 8
D 10
		sigsetmask(sigblock(0) & ~sigmask(SIGINT));
E 10
I 10
D 14
		(void) sigsetmask(sigblock(0) & ~sigmask(SIGINT));
E 14
I 14
		(void) sigsetmask(sigblock(0L) & ~sigmask(SIGINT));
E 14
E 10
E 8
E 7
E 6
D 11
	vp++;
D 2
	if (*vp && eq(*vp, "-r")) {
		rflg++;
		vp++;
E 2
I 2
D 5
	while (*vp[0] == '-') {
E 5
I 5
	while (*vp && *vp[0] == '-') {
E 5
D 4
		if (*vp && eq(*vp, "-c")) {
			cflg++;
E 4
I 4
D 9
		if (*vp && eq(*vp, "-h")) {
E 9
I 9
		if (*vp && eq(*vp, "-h"))
E 9
			hflg++;
E 4
D 9
			vp++;
		}
		if (*vp && eq(*vp, "-r")) {
E 9
I 9
		else if (*vp && eq(*vp, "-r"))
E 9
			rflg++;
D 9
			vp++;
		}
E 9
I 9
		vp++;
E 11
I 11
 	while (*++vp && **vp == '-') {
 		char *vp2 = *vp;
 
 		while (*++vp2)
 			switch (*vp2) {
 			case 'h':
 				hflg++;
 				break;
 			case 'r':
 				rflg++;
 				break;
 			case '-':	/* ignore multiple '-'s */
 				break;
 			default:
 				printf("Unknown flag: -%c\n", *vp2);
 				error("Usage: history [-rh] [# number of events]");
			}
E 11
E 9
E 2
	}
	if (*vp)
		n = getn(*vp);
D 4
	else
		n = 1000;
D 2
	dohist1(Histlist.Hnext, &n, rflg);
E 2
I 2
	dohist1(Histlist.Hnext, &n, rflg, cflg);
E 4
I 4
	else {
		n = getn(value("history"));
	}
	dohist1(Histlist.Hnext, &n, rflg, hflg);
E 4
E 2
}

D 2
dohist1(hp, np, rflg)
E 2
I 2
D 4
dohist1(hp, np, rflg, cflg)
E 4
I 4
dohist1(hp, np, rflg, hflg)
E 4
E 2
	struct Hist *hp;
D 4
	int *np;
E 4
I 4
	int *np, rflg, hflg;
E 4
{
	bool print = (*np) > 0;
top:
	if (hp == 0)
		return;
	(*np)--;
	hp->Href++;
	if (rflg == 0) {
D 2
		dohist1(hp->Hnext, np, rflg);
E 2
I 2
D 4
		dohist1(hp->Hnext, np, rflg, cflg);
E 4
I 4
		dohist1(hp->Hnext, np, rflg, hflg);
E 4
E 2
		if (print)
D 2
			phist(hp);
E 2
I 2
D 4
			phist(hp, cflg);
E 4
I 4
			phist(hp, hflg);
E 4
E 2
		return;
	}
	if (*np >= 0)
D 2
		phist(hp);
E 2
I 2
D 4
		phist(hp, cflg);
E 4
I 4
		phist(hp, hflg);
E 4
E 2
	hp = hp->Hnext;
	goto top;
}

D 2
phist(hp)
E 2
I 2
D 4
phist(hp, cflg)
E 4
I 4
phist(hp, hflg)
E 4
E 2
	register struct Hist *hp;
I 2
D 4
	int cflg;
E 4
I 4
	int hflg;
E 4
E 2
{

D 2
	printf("%6d\t", hp->Hnum);
E 2
I 2
D 4
	if (cflg == 0)
E 4
I 4
	if (hflg == 0)
E 4
		printf("%6d\t", hp->Hnum);
E 2
	prlex(&hp->Hlex);
}
E 1
