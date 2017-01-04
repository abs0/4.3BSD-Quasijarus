h46029
s 00010/00005/00105
d D 5.8 88/06/27 17:34:18 bostic 13 12
c install approved copyright notice
e
s 00009/00003/00101
d D 5.7 87/12/03 22:39:48 bostic 12 11
c add Berkeley specific header
e
s 00003/00003/00101
d D 5.6 87/04/06 16:47:51 karels 11 9
c missing _
e
s 00001/00001/00103
d R 5.6 87/04/06 16:45:07 karels 10 9
c missing _
e
s 00001/00001/00103
d D 5.5 87/04/01 09:59:59 bostic 9 8
c changed tztab to _tztab
e
s 00002/00002/00102
d D 5.4 87/03/28 11:31:55 bostic 8 7
c put LIBC_SCCS back 
e
s 00073/00048/00031
d D 5.3 87/03/28 11:27:07 bostic 7 6
c new time package
e
s 00002/00002/00077
d D 5.2 86/03/09 20:00:17 donn 6 5
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00069
d D 5.1 85/05/30 10:52:52 dist 5 4
c Add copyright
e
s 00002/00002/00068
d D 4.4 83/09/25 16:52:40 karels 4 3
c MET and EET are - from GMT
e
s 00006/00000/00064
d D 4.3 83/07/09 14:03:10 sam 3 2
c european timezone rules
e
s 00019/00000/00045
d D 4.2 83/06/10 22:42:49 sam 2 1
c from robert
e
s 00045/00000/00000
d D 4.1 80/12/21 16:40:25 wnj 1 0
c date and time created 80/12/21 16:40:25 by wnj
e
u
U
t
T
I 1
D 5
/* %W% (Berkeley) %G% */
E 5
I 5
/*
D 7
 * Copyright (c) 1980 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1987 Regents of the University of California.
E 7
D 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 */

D 6
#ifndef lint
E 6
I 6
D 7
#if defined(LIBC_SCCS) && !defined(lint)
E 7
I 7
D 8
#ifndef lint
E 8
I 8
#if defined(LIBC_SCCS) && !defined(lint)
E 8
E 7
E 6
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
D 7
#endif LIBC_SCCS and not lint
E 7
I 7
D 8
#endif
E 8
I 8
D 12
#endif LIBC_SCCS and not lint
E 12
I 12
#endif /* LIBC_SCCS and not lint */
E 12
E 8
E 7
E 6

I 7
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include <tzfile.h>

E 7
E 5
/*
D 7
 * The arguments are the number of minutes of time
 * you are westward from Greenwich and whether DST is in effect.
 * It returns a string
 * giving the name of the local timezone.
 *
 * Sorry, I don't know all the names.
E 7
I 7
 * timezone --
 *	The arguments are the number of minutes of time you are westward
 *	from Greenwich and whether DST is in effect.  It returns a string
 *	giving the name of the local timezone.  Should be replaced, in the
 *	application code, by a call to localtime.
E 7
 */

I 7
static char	czone[TZ_MAX_CHARS];		/* space for zone name */

char *
timezone(zone, dst)
	int	zone,
		dst;
{
	register char	*beg,
			*end;
D 11
	char	*getenv(), *index(), *strncpy(), *tztab();
E 11
I 11
	char	*getenv(), *index(), *strncpy(), *_tztab();
E 11

	if (beg = getenv("TZNAME")) {		/* set in environment */
		if (end = index(beg, ',')) {	/* "PST,PDT" */
			if (dst)
				return(++end);
			*end = '\0';
			(void)strncpy(czone,beg,sizeof(czone) - 1);
			czone[sizeof(czone) - 1] = '\0';
			*end = ',';
			return(czone);
		}
		return(beg);
	}
D 11
	return(tztab(zone,dst));	/* default: table or created zone */
E 11
I 11
	return(_tztab(zone,dst));	/* default: table or created zone */
E 11
}

E 7
static struct zone {
	int	offset;
	char	*stdzone;
	char	*dlzone;
} zonetab[] = {
I 3
D 4
	1*60, "MET", "MET DST",		/* Middle European */
	2*60, "EET", "EET DST",		/* Eastern European */
E 4
I 4
D 7
	-1*60, "MET", "MET DST",	/* Middle European */
	-2*60, "EET", "EET DST",	/* Eastern European */
E 4
E 3
	4*60, "AST", "ADT",		/* Atlantic */
	5*60, "EST", "EDT",		/* Eastern */
	6*60, "CST", "CDT",		/* Central */
	7*60, "MST", "MDT",		/* Mountain */
	8*60, "PST", "PDT",		/* Pacific */
E 7
I 7
	-1*60,	"MET",	"MET DST",	/* Middle European */
	-2*60,	"EET",	"EET DST",	/* Eastern European */
	4*60,	"AST",	"ADT",		/* Atlantic */
	5*60,	"EST",	"EDT",		/* Eastern */
	6*60,	"CST",	"CDT",		/* Central */
	7*60,	"MST",	"MDT",		/* Mountain */
	8*60,	"PST",	"PDT",		/* Pacific */
E 7
I 3
#ifdef notdef
	/* there's no way to distinguish this from WET */
E 3
D 7
	0, "GMT", 0,			/* Greenwich */
E 7
I 7
	0,	"GMT",	0,		/* Greenwich */
E 7
I 3
#endif
D 7
	0*60, "WET", "WET DST",		/* Western European */
E 3
I 2
	-10*60, "EST", "EST",		/* Aust: Eastern */
	-10*60+30, "CST", "CST",	/* Aust: Central */
	-8*60, "WST", 0,		/* Aust: Western */
E 7
I 7
	0*60,	"WET",	"WET DST",	/* Western European */
	-10*60,	"EST",	"EST",		/* Aust: Eastern */
     -10*60+30,	"CST",	"CST",		/* Aust: Central */
	-8*60,	"WST",	0,		/* Aust: Western */
E 7
E 2
	-1
};

D 7
char *timezone(zone, dst)
E 7
I 7
/*
D 11
 * tztab --
E 11
I 11
 * _tztab --
E 11
 *	check static tables or create a new zone name; broken out so that
 *	we can make a guess as to what the zone is if the standard tables
 *	aren't in place in /etc.  DO NOT USE THIS ROUTINE OUTSIDE OF THE
 *	STANDARD LIBRARY.
 */
char *
D 9
tztab(zone,dst)
E 9
I 9
_tztab(zone,dst)
E 9
	register int	zone;
	int	dst;
E 7
{
D 7
	register struct zone *zp;
	static char czone[10];
	char *sign;
I 2
	register char *p, *q;
	char *getenv(), *index();
E 7
I 7
	register struct zone	*zp;
	register char	sign;
E 7
E 2

I 2
D 7
	if (p = getenv("TZNAME")) {
		if (q = index(p, ',')) {
			if (dst)
				return(++q);
			else {
				*q = '\0';
				strncpy(czone, p, sizeof(czone)-1);
				czone[sizeof(czone)-1] = '\0';
				*q = ',';
				return (czone);
			}
		}
		return(p);
	}
E 2
	for (zp=zonetab; zp->offset!=-1; zp++)
		if (zp->offset==zone) {
E 7
I 7
	for (zp = zonetab; zp->offset != -1;++zp)	/* static tables */
		if (zp->offset == zone) {
E 7
			if (dst && zp->dlzone)
				return(zp->dlzone);
			if (!dst && zp->stdzone)
				return(zp->stdzone);
		}
D 7
	if (zone<0) {
E 7
I 7

	if (zone < 0) {					/* create one */
E 7
		zone = -zone;
D 7
		sign = "+";
	} else
		sign = "-";
	sprintf(czone, "GMT%s%d:%02d", sign, zone/60, zone%60);
E 7
I 7
		sign = '+';
	}
	else
		sign = '-';
	(void)sprintf(czone,"GMT%c%d:%02d",sign,zone / 60,zone % 60);
E 7
	return(czone);
}
E 1
