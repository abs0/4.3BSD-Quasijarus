h00835
s 00003/00003/00400
d D 5.14 88/07/06 10:00:37 bostic 20 19
c make tzone file copyright notices consistent
e
s 00010/00005/00393
d D 5.13 88/06/27 17:34:03 bostic 19 18
c install approved copyright notice
e
s 00012/00003/00386
d D 5.12 87/12/03 22:44:58 bostic 18 17
c put reasonable header on it
e
s 00002/00002/00387
d D 5.11 87/04/13 07:46:26 bostic 17 16
c update from Arthur Olson; bug report 4.3BSD/lib/52
e
s 00001/00001/00388
d D 5.10 87/04/06 12:37:07 bostic 16 15
c minor printf format error
e
s 00002/00002/00387
d D 5.9 87/04/01 10:00:21 bostic 15 14
c changed tztab to _tztab
e
s 00002/00002/00387
d D 5.8 87/03/28 11:33:02 bostic 14 13
c put LIBC_SCCS back
e
s 00034/00008/00355
d D 5.7 87/03/28 11:27:01 bostic 13 12
c new time package
e
s 00311/00285/00052
d D 5.6 87/03/11 18:51:33 bostic 12 11
c added new time package routines
e
s 00002/00002/00335
d D 5.5 86/03/09 19:45:24 donn 11 10
c added LIBC_SCCS condition for sccs ids
e
s 00006/00002/00331
d D 5.4 86/01/03 10:03:59 bloom 10 9
c cut down the number of unnecessary calls to gettimeofday
e
s 00001/00001/00332
d D 5.3 85/10/25 16:00:53 mckusick 9 8
c lets get it right (from ist!dt)
e
s 00020/00011/00313
d D 5.2 85/06/24 00:14:21 kre 8 7
c Fixed (?) European DST rules, and added a special set for
c Canada without the 74/75 peculiarities (Tilbrook says this is so...)
e
s 00008/00001/00316
d D 5.1 85/06/05 12:12:03 mckusick 7 6
c Add copyright
e
s 00008/00008/00309
d D 4.6 84/08/29 15:13:14 ralph 6 5
c fix ctime(time 0), year > 2100 (can't be generated with long).
e
s 00001/00001/00316
d D 4.5 84/03/16 15:53:43 karels 5 4
c handle negative times
e
s 00028/00003/00289
d D 4.4 83/07/09 14:02:56 sam 4 3
c european timezone rules
e
s 00004/00002/00288
d D 4.3 83/07/01 18:32:31 sam 3 2
c include fixes
e
s 00070/00026/00220
d D 4.2 83/06/10 22:42:43 sam 2 1
c from robert
e
s 00246/00000/00000
d D 4.1 80/12/21 16:39:33 wnj 1 0
c date and time created 80/12/21 16:39:33 by wnj
e
u
U
t
T
I 7
/*
D 13
 * Copyright (c) 1980 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1987 Regents of the University of California.
E 13
D 18
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 18
I 18
 * All rights reserved.
 *
I 20
 * This code is derived from software contributed to Berkeley by
 * Arthur Olson.
 *
E 20
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
D 20
 *
 * This code was supplied by Arthur Olson, originally, and has been
 * slightly modified at the University of California.
E 20
E 18
 */

E 7
I 1
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
D 11
#ifndef lint
E 11
I 11
D 13
#if defined(LIBC_SCCS) && !defined(lint)
E 13
I 13
D 14
#ifndef lint
E 14
I 14
#if defined(LIBC_SCCS) && !defined(lint)
E 14
E 13
E 11
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif
E 7
I 7
D 11
#endif not lint
E 11
I 11
D 13
#endif LIBC_SCCS and not lint
E 13
I 13
D 14
#endif
E 14
I 14
D 18
#endif LIBC_SCCS and not lint
E 18
I 18
#endif /* LIBC_SCCS and not lint */
E 18
E 14
E 13
E 11

E 7
E 3
D 12
/*
 * This routine converts time as follows.
 * The epoch is 0000 Jan 1 1970 GMT.
 * The argument time is in seconds since then.
 * The localtime(t) entry returns a pointer to an array
 * containing
 *  seconds (0-59)
 *  minutes (0-59)
 *  hours (0-23)
 *  day of month (1-31)
 *  month (0-11)
 *  year-1970
 *  weekday (0-6, Sun is 0)
 *  day of the year
 *  daylight savings flag
 *
 * The routine calls the system to determine the local
 * timezone and whether Daylight Saving Time is permitted locally.
D 4
 * (DST is then determined by the current US standard rules)
 * There is a table that accounts for the peculiarities
 * undergone by daylight time in 1974-1975.
E 4
I 4
 * (DST is then determined by the current local rules)
E 4
 *
 * The routine does not work
 * in Saudi Arabia which runs on Solar time.
 *
 * asctime(tvec))
 * where tvec is produced by localtime
 * returns a ptr to a character string
 * that has the ascii time in the form
D 6
 *	Thu Jan 01 00:00:00 1970n0\\
 *	01234567890123456789012345
E 6
I 6
 *	Thu Jan 01 00:00:00 1970\n\0
 *	0123456789012345678901234 5
E 6
 *	0	  1	    2
 *
 * ctime(t) just calls localtime, then asctime.
 */
E 12
I 12
#include "sys/param.h"
I 13
#include "sys/time.h"
E 13
#include "tzfile.h"
D 13
#include "time.h"
E 13
E 12

D 3
#include <time.h>
E 3
I 3
D 12
#include <sys/time.h>
E 3
#include <sys/types.h>
#include <sys/timeb.h>

static	char	cbuf[26];
static	int	dmsize[12] =
E 12
I 12
char *
ctime(t)
time_t *t;
E 12
{
D 12
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};
E 12
I 12
	struct tm	*localtime();
	char	*asctime();
E 12

I 12
	return(asctime(localtime(t)));
}

E 12
/*
D 12
 * The following table is used for 1974 and 1975 and
 * gives the day number of the first day after the Sunday of the
 * change.
 */
D 2
static struct {
E 2
I 2
struct dstab {
	int	dayyr;
E 2
	int	daylb;
	int	dayle;
D 2
} daytab[] = {
	5,	333,	/* 1974: Jan 6 - last Sun. in Nov */
	58,	303,	/* 1975: Last Sun. in Feb - last Sun in Oct */
E 2
};
E 12
I 12
** A la X3J11
*/
E 12

I 2
D 12
static struct dstab usdaytab[] = {
	1974,	5,	333,	/* 1974: Jan 6 - last Sun. in Nov */
	1975,	58,	303,	/* 1975: Last Sun. in Feb - last Sun in Oct */
	0,	119,	303,	/* all other years: end Apr - end Oct */
};
static struct dstab ausdaytab[] = {
	1970,	400,	0,	/* 1970: no daylight saving at all */
	1971,	303,	0,	/* 1971: daylight saving from Oct 31 */
	1972,	303,	58,	/* 1972: Jan 1 -> Feb 27 & Oct 31 -> dec 31 */
	0,	303,	65,	/* others: -> Mar 7, Oct 31 -> */
};
E 12
I 12
char *
asctime(timeptr)
register struct tm *	timeptr;
{
	static char	wday_name[DAYS_PER_WEEK][3] = {
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	};
	static char	mon_name[MONS_PER_YEAR][3] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	static char	result[26];
E 12

I 4
D 12
/*
 * The European tables ... based on hearsay
 * Believed correct for:
D 8
 *	WE:	Great Britain, Ireland, Portugal
E 8
I 8
 *	WE:	Great Britain, Portugal?
E 8
 *	ME:	Belgium, Luxembourg, Netherlands, Denmark, Norway,
 *		Austria, Poland, Czechoslovakia, Sweden, Switzerland,
 *		DDR, DBR, France, Spain, Hungary, Italy, Jugoslavia
I 8
 *		Finland (EE timezone, but ME dst rules)
E 8
 * Eastern European dst is unknown, we'll make it ME until someone speaks up.
D 8
 *	EE:	Bulgaria, Finland, Greece, Rumania, Turkey, Western Russia
E 8
I 8
 *	EE:	Bulgaria, Greece, Rumania, Turkey, Western Russia
 *
 * Ireland is unpredictable.  (Years when Easter Sunday just happens ...)
 * Years before 1983 are suspect.
E 8
 */
static struct dstab wedaytab[] = {
D 8
	1983,	86,	303,	/* 1983: end March - end Oct */
	1984,	86,	303,	/* 1984: end March - end Oct */
	1985,	86,	303,	/* 1985: end March - end Oct */
	0,	400,	0,	/* others: no daylight saving at all ??? */
E 8
I 8
	1983,	89,	296,	/* 1983: end March - end Oct */
	0,	89,	303,	/* others: end March - end Oct */
E 8
};
E 12
I 12
D 16
	(void) sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
E 16
I 16
	(void) sprintf(result, "%.3s %.3s%3d %02d:%02d:%02d %d\n",
E 16
		wday_name[timeptr->tm_wday],
		mon_name[timeptr->tm_mon],
		timeptr->tm_mday, timeptr->tm_hour,
		timeptr->tm_min, timeptr->tm_sec,
		TM_YEAR_BASE + timeptr->tm_year);
	return result;
}
E 12

D 12
static struct dstab medaytab[] = {
D 8
	1983,	86,	272,	/* 1983: end March - end Sep */
	1984,	86,	272,	/* 1984: end March - end Sep */
	1985,	86,	272,	/* 1985: end March - end Sep */
	0,	400,	0,	/* others: no daylight saving at all ??? */
E 8
I 8
	1983,	89,	296,	/* 1983: end March - end Oct */
	0,	89,	272,	/* others: end March - end Sep */
E 12
I 12
#ifndef TRUE
#define TRUE		1
#define FALSE		0
#endif /* !TRUE */

extern char *		getenv();
extern char *		strcpy();
extern char *		strcat();
struct tm *		offtime();

struct ttinfo {				/* time type information */
	long		tt_gmtoff;	/* GMT offset in seconds */
	int		tt_isdst;	/* used to set tm_isdst */
	int		tt_abbrind;	/* abbreviation list index */
E 12
E 8
};

I 8
D 12
/*
 * Canada, same as the US, except no early 70's fluctuations.
 * Can this really be right ??
 */
static struct dstab candaytab[] = {
	0,	119,	303,	/* all years: end Apr - end Oct */
E 12
I 12
struct state {
	int		timecnt;
	int		typecnt;
	int		charcnt;
	time_t		ats[TZ_MAX_TIMES];
	unsigned char	types[TZ_MAX_TIMES];
	struct ttinfo	ttis[TZ_MAX_TYPES];
	char		chars[TZ_MAX_CHARS + 1];
E 12
};

E 8
E 4
D 12
static struct dayrules {
	int		dst_type;	/* number obtained from system */
	int		dst_hrs;	/* hours to add when dst on */
	struct	dstab *	dst_rules;	/* one of the above */
	enum {STH,NTH}	dst_hemi;	/* southern, northern hemisphere */
} dayrules [] = {
	DST_USA,	1,	usdaytab,	NTH,
	DST_AUST,	1,	ausdaytab,	STH,
I 4
	DST_WET,	1,	wedaytab,	NTH,
	DST_MET,	1,	medaytab,	NTH,
	DST_EET,	1,	medaytab,	NTH,	/* XXX */
I 8
	DST_CAN,	1,	candaytab,	NTH,
E 8
E 4
	-1,
E 12
I 12
static struct state	s;

static int		tz_is_set;

char *			tzname[2] = {
	"GMT",
	"GMT"
E 12
};

E 2
D 12
struct tm	*gmtime();
char		*ct_numb();
struct tm	*localtime();
char	*ctime();
char	*ct_num();
char	*asctime();
E 12
I 12
#ifdef USG_COMPAT
time_t			timezone = 0;
int			daylight = 0;
#endif /* USG_COMPAT */
E 12

D 12
char *
ctime(t)
D 2
long *t;
E 2
I 2
D 6
unsigned long *t;
E 6
I 6
time_t *t;
E 12
I 12
static long
detzcode(codep)
char *	codep;
E 12
E 6
E 2
{
D 12
	return(asctime(localtime(t)));
E 12
I 12
	register long	result;
	register int	i;

	result = 0;
	for (i = 0; i < 4; ++i)
		result = (result << 8) | (codep[i] & 0xff);
	return result;
E 12
}

D 12
struct tm *
localtime(tim)
D 2
long *tim;
E 2
I 2
D 6
unsigned long *tim;
E 6
I 6
time_t *tim;
E 12
I 12
static
tzload(name)
register char *	name;
E 12
E 6
E 2
{
D 12
	register int dayno;
	register struct tm *ct;
D 2
	register daylbegin, daylend;
	long copyt;
	struct timeb systime;
E 2
I 2
	register dalybeg, daylend;
	register struct dayrules *dr;
	register struct dstab *ds;
	int year;
D 6
	unsigned long copyt;
E 6
I 6
	time_t copyt;
E 6
	struct timeval curtime;
D 10
	struct timezone zone;
E 10
I 10
	static struct timezone zone;
	static int init = 0;
E 12
I 12
	register int	i;
	register int	fid;
E 12
E 10
E 2

D 2
	ftime(&systime);
	copyt = *tim - (long)systime.timezone*60;
E 2
I 2
D 10
	gettimeofday(&curtime, &zone);
E 10
I 10
D 12
	if (!init) {
		gettimeofday(&curtime, &zone);
		init++;
E 12
I 12
	if (name == 0 && (name = TZDEFAULT) == 0)
		return -1;
	{
		register char *	p;
		register int	doaccess;
		char		fullname[MAXPATHLEN];

		doaccess = name[0] == '/';
		if (!doaccess) {
			if ((p = TZDIR) == 0)
				return -1;
			if ((strlen(p) + strlen(name) + 1) >= sizeof fullname)
				return -1;
			(void) strcpy(fullname, p);
			(void) strcat(fullname, "/");
			(void) strcat(fullname, name);
			/*
			** Set doaccess if '.' (as in "../") shows up in name.
			*/
			while (*name != '\0')
				if (*name++ == '.')
					doaccess = TRUE;
			name = fullname;
		}
		if (doaccess && access(name, 4) != 0)
			return -1;
		if ((fid = open(name, 0)) == -1)
			return -1;
E 12
	}
E 10
D 6
	copyt = *tim - (unsigned long)zone.tz_minuteswest*60;
E 6
I 6
D 12
	copyt = *tim - (time_t)zone.tz_minuteswest*60;
E 6
E 2
	ct = gmtime(&copyt);
	dayno = ct->tm_yday;
D 2
	daylbegin = 119;	/* last Sun in Apr */
	daylend = 303;		/* Last Sun in Oct */
	if (ct->tm_year==74 || ct->tm_year==75) {
		daylbegin = daytab[ct->tm_year-74].daylb;
		daylend = daytab[ct->tm_year-74].dayle;
	}
	daylbegin = sunday(ct, daylbegin);
	daylend = sunday(ct, daylend);
	if (systime.dstflag &&
	    (dayno>daylbegin || (dayno==daylbegin && ct->tm_hour>=2)) &&
	    (dayno<daylend || (dayno==daylend && ct->tm_hour<1))) {
		copyt += 1*60*60;
E 2
I 2
	for (dr = dayrules; dr->dst_type >= 0; dr++)
		if (dr->dst_type == zone.tz_dsttime)
			break;
	if (dr->dst_type >= 0) {
		year = ct->tm_year + 1900;
		for (ds = dr->dst_rules; ds->dayyr; ds++)
			if (ds->dayyr == year)
				break;
		dalybeg = ds->daylb;	/* first Sun after dst starts */
		daylend = ds->dayle;	/* first Sun after dst ends */
		dalybeg = sunday(ct, dalybeg);
		daylend = sunday(ct, daylend);
		switch (dr->dst_hemi) {
		case NTH:
		    if (!(
		       (dayno>dalybeg || (dayno==dalybeg && ct->tm_hour>=2)) &&
		       (dayno<daylend || (dayno==daylend && ct->tm_hour<1))
		    ))
			    return(ct);
		    break;
		case STH:
		    if (!(
		       (dayno>dalybeg || (dayno==dalybeg && ct->tm_hour>=2)) ||
		       (dayno<daylend || (dayno==daylend && ct->tm_hour<2))
		    ))
			    return(ct);
		    break;
		default:
		    return(ct);
E 12
I 12
	{
		register char *			p;
		register struct tzhead *	tzhp;
		char				buf[sizeof s];

		i = read(fid, buf, sizeof buf);
		if (close(fid) != 0 || i < sizeof *tzhp)
			return -1;
		tzhp = (struct tzhead *) buf;
		s.timecnt = (int) detzcode(tzhp->tzh_timecnt);
		s.typecnt = (int) detzcode(tzhp->tzh_typecnt);
		s.charcnt = (int) detzcode(tzhp->tzh_charcnt);
		if (s.timecnt > TZ_MAX_TIMES ||
			s.typecnt == 0 ||
			s.typecnt > TZ_MAX_TYPES ||
			s.charcnt > TZ_MAX_CHARS)
				return -1;
		if (i < sizeof *tzhp +
			s.timecnt * (4 + sizeof (char)) +
			s.typecnt * (4 + 2 * sizeof (char)) +
			s.charcnt * sizeof (char))
				return -1;
		p = buf + sizeof *tzhp;
		for (i = 0; i < s.timecnt; ++i) {
			s.ats[i] = detzcode(p);
			p += 4;
E 12
		}
D 12
	        copyt += dr->dst_hrs*60*60;
E 2
		ct = gmtime(&copyt);
		ct->tm_isdst++;
E 12
I 12
		for (i = 0; i < s.timecnt; ++i)
			s.types[i] = (unsigned char) *p++;
		for (i = 0; i < s.typecnt; ++i) {
			register struct ttinfo *	ttisp;

			ttisp = &s.ttis[i];
			ttisp->tt_gmtoff = detzcode(p);
			p += 4;
			ttisp->tt_isdst = (unsigned char) *p++;
			ttisp->tt_abbrind = (unsigned char) *p++;
		}
		for (i = 0; i < s.charcnt; ++i)
			s.chars[i] = *p++;
		s.chars[i] = '\0';	/* ensure '\0' at end */
E 12
	}
D 12
	return(ct);
E 12
I 12
	/*
	** Check that all the local time type indices are valid.
	*/
	for (i = 0; i < s.timecnt; ++i)
		if (s.types[i] >= s.typecnt)
			return -1;
	/*
	** Check that all abbreviation indices are valid.
	*/
	for (i = 0; i < s.typecnt; ++i)
		if (s.ttis[i].tt_abbrind >= s.charcnt)
			return -1;
	/*
	** Set tzname elements to initial values.
	*/
	tzname[0] = tzname[1] = &s.chars[0];
#ifdef USG_COMPAT
D 17
	timezone = s.ttis[0].tt_gmtoff;
E 17
I 17
	timezone = -s.ttis[0].tt_gmtoff;
E 17
	daylight = 0;
#endif /* USG_COMPAT */
	for (i = 1; i < s.typecnt; ++i) {
		register struct ttinfo *	ttisp;

		ttisp = &s.ttis[i];
		if (ttisp->tt_isdst) {
			tzname[1] = &s.chars[ttisp->tt_abbrind];
#ifdef USG_COMPAT
			daylight = 1;
#endif /* USG_COMPAT */ 
		} else {
			tzname[0] = &s.chars[ttisp->tt_abbrind];
#ifdef USG_COMPAT
D 17
			timezone = ttisp->tt_gmtoff;
E 17
I 17
			timezone = -ttisp->tt_gmtoff;
E 17
#endif /* USG_COMPAT */ 
		}
	}
	return 0;
E 12
}

D 12
/*
 * The argument is a 0-origin day number.
D 9
 * The value is the day number of the first
E 9
I 9
 * The value is the day number of the last
E 9
D 8
 * Sunday on or after the day.
E 8
I 8
 * Sunday on or before the day.
E 8
 */
E 12
static
I 13
tzsetkernel()
{
	struct timeval	tv;
	struct timezone	tz;
D 15
	char	*tztab();
E 15
I 15
	char	*_tztab();
E 15

	if (gettimeofday(&tv, &tz))
		return -1;
	s.timecnt = 0;		/* UNIX counts *west* of Greenwich */
	s.ttis[0].tt_gmtoff = tz.tz_minuteswest * -SECS_PER_MIN;
	s.ttis[0].tt_abbrind = 0;
D 15
	(void)strcpy(s.chars, tztab(tz.tz_minuteswest, 0));
E 15
I 15
	(void)strcpy(s.chars, _tztab(tz.tz_minuteswest, 0));
E 15
	tzname[0] = tzname[1] = s.chars;
#ifdef USG_COMPAT
	timezone = tz.tz_minuteswest * 60;
	daylight = tz.tz_dsttime;
#endif /* USG_COMPAT */
	return 0;
}

static
E 13
D 12
sunday(t, d)
register struct tm *t;
register int d;
E 12
I 12
tzsetgmt()
E 12
{
D 12
	if (d >= 58)
		d += dysize(t->tm_year) - 365;
	return(d - (d - t->tm_yday + t->tm_wday + 700) % 7);
E 12
I 12
	s.timecnt = 0;
	s.ttis[0].tt_gmtoff = 0;
	s.ttis[0].tt_abbrind = 0;
	(void) strcpy(s.chars, "GMT");
	tzname[0] = tzname[1] = s.chars;
#ifdef USG_COMPAT
	timezone = 0;
	daylight = 0;
#endif /* USG_COMPAT */
E 12
}

D 12
struct tm *
gmtime(tim)
D 2
long *tim;
E 2
I 2
D 6
unsigned long *tim;
E 6
I 6
time_t *tim;
E 12
I 12
void
tzset()
E 12
E 6
E 2
{
D 12
	register int d0, d1;
D 2
	long hms, day;
E 2
I 2
D 5
	unsigned long hms, day;
E 5
I 5
	long hms, day;
E 5
E 2
	register int *tp;
	static struct tm xtime;
E 12
I 12
	register char *	name;
E 12

D 12
	/*
	 * break initial number into days
	 */
	hms = *tim % 86400;
	day = *tim / 86400;
	if (hms<0) {
		hms += 86400;
		day -= 1;
	}
	tp = (int *)&xtime;

	/*
	 * generate hours:minutes:seconds
	 */
	*tp++ = hms%60;
	d1 = hms/60;
	*tp++ = d1%60;
	d1 /= 60;
	*tp++ = d1;

	/*
	 * day is the day number.
	 * generate day of the week.
	 * The addend is 4 mod 7 (1/1/1970 was Thursday)
	 */

	xtime.tm_wday = (day+7340036)%7;

	/*
	 * year number
	 */
	if (day>=0) for(d1=70; day >= dysize(d1); d1++)
		day -= dysize(d1);
	else for (d1=70; day<0; d1--)
		day += dysize(d1-1);
	xtime.tm_year = d1;
	xtime.tm_yday = d0 = day;

	/*
	 * generate month
	 */

	if (dysize(d1)==366)
		dmsize[1] = 29;
	for(d1=0; d0 >= dmsize[d1]; d1++)
		d0 -= dmsize[d1];
	dmsize[1] = 28;
	*tp++ = d0+1;
	*tp++ = d1;
	xtime.tm_isdst = 0;
	return(&xtime);
E 12
I 12
	tz_is_set = TRUE;
	name = getenv("TZ");
D 13
	if (name != 0 && *name == '\0')
		tzsetgmt();		/* GMT by request */
	else if (tzload(name) != 0)
		tzsetgmt();
E 13
I 13
	if (!name || *name) {			/* did not request GMT */
		if (name && !tzload(name))	/* requested name worked */
			return;
		if (!tzload((char *)0))		/* default name worked */
			return;
		if (!tzsetkernel())		/* kernel guess worked */
			return;
	}
	tzsetgmt();				/* GMT is default */
E 13
E 12
}

D 12
char *
asctime(t)
struct tm *t;
E 12
I 12
struct tm *
localtime(timep)
time_t *	timep;
E 12
{
D 12
	register char *cp, *ncp;
	register int *tp;
E 12
I 12
	register struct ttinfo *	ttisp;
	register struct tm *		tmp;
	register int			i;
	time_t				t;
E 12

D 12
	cp = cbuf;
	for (ncp = "Day Mon 00 00:00:00 1900\n"; *cp++ = *ncp++;);
	ncp = &"SunMonTueWedThuFriSat"[3*t->tm_wday];
	cp = cbuf;
	*cp++ = *ncp++;
	*cp++ = *ncp++;
	*cp++ = *ncp++;
	cp++;
	tp = &t->tm_mon;
	ncp = &"JanFebMarAprMayJunJulAugSepOctNovDec"[(*tp)*3];
	*cp++ = *ncp++;
	*cp++ = *ncp++;
	*cp++ = *ncp++;
	cp = ct_numb(cp, *--tp);
	cp = ct_numb(cp, *--tp+100);
	cp = ct_numb(cp, *--tp+100);
	cp = ct_numb(cp, *--tp+100);
	if (t->tm_year>=100) {
		cp[1] = '2';
D 2
		cp[2] = '0';
E 2
I 2
D 6
		cp[2] = '0' + t->tm_year >= 200;
E 6
I 6
		cp[2] = '0' + (t->tm_year-100) / 100;
E 12
I 12
	if (!tz_is_set)
		(void) tzset();
	t = *timep;
	if (s.timecnt == 0 || t < s.ats[0]) {
		i = 0;
		while (s.ttis[i].tt_isdst)
			if (++i >= s.timecnt) {
				i = 0;
				break;
			}
	} else {
		for (i = 1; i < s.timecnt; ++i)
			if (t < s.ats[i])
				break;
		i = s.types[i - 1];
E 12
E 6
E 2
	}
D 12
	cp += 2;
	cp = ct_numb(cp, t->tm_year+100);
	return(cbuf);
E 12
I 12
	ttisp = &s.ttis[i];
	/*
	** To get (wrong) behavior that's compatible with System V Release 2.0
	** you'd replace the statement below with
	**	tmp = offtime((time_t) (t + ttisp->tt_gmtoff), 0L);
	*/
	tmp = offtime(&t, ttisp->tt_gmtoff);
	tmp->tm_isdst = ttisp->tt_isdst;
	tzname[tmp->tm_isdst] = &s.chars[ttisp->tt_abbrind];
	tmp->tm_zone = &s.chars[ttisp->tt_abbrind];
	return tmp;
E 12
}

D 12
dysize(y)
E 12
I 12
struct tm *
gmtime(clock)
time_t *	clock;
E 12
{
D 12
	if((y%4) == 0)
		return(366);
	return(365);
E 12
I 12
	register struct tm *	tmp;

	tmp = offtime(clock, 0L);
	tzname[0] = "GMT";
	tmp->tm_zone = "GMT";		/* UCT ? */
	return tmp;
E 12
}

D 12
static char *
ct_numb(cp, n)
register char *cp;
E 12
I 12
static int	mon_lengths[2][MONS_PER_YEAR] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

static int	year_lengths[2] = {
	DAYS_PER_NYEAR, DAYS_PER_LYEAR
};

struct tm *
offtime(clock, offset)
time_t *	clock;
long		offset;
E 12
{
D 12
	cp++;
	if (n>=10)
		*cp++ = (n/10)%10 + '0';
	else
		*cp++ = ' ';
	*cp++ = n%10 + '0';
	return(cp);
E 12
I 12
	register struct tm *	tmp;
	register long		days;
	register long		rem;
	register int		y;
	register int		yleap;
	register int *		ip;
	static struct tm	tm;

	tmp = &tm;
	days = *clock / SECS_PER_DAY;
	rem = *clock % SECS_PER_DAY;
	rem += offset;
	while (rem < 0) {
		rem += SECS_PER_DAY;
		--days;
	}
	while (rem >= SECS_PER_DAY) {
		rem -= SECS_PER_DAY;
		++days;
	}
	tmp->tm_hour = (int) (rem / SECS_PER_HOUR);
	rem = rem % SECS_PER_HOUR;
	tmp->tm_min = (int) (rem / SECS_PER_MIN);
	tmp->tm_sec = (int) (rem % SECS_PER_MIN);
	tmp->tm_wday = (int) ((EPOCH_WDAY + days) % DAYS_PER_WEEK);
	if (tmp->tm_wday < 0)
		tmp->tm_wday += DAYS_PER_WEEK;
	y = EPOCH_YEAR;
	if (days >= 0)
		for ( ; ; ) {
			yleap = isleap(y);
			if (days < (long) year_lengths[yleap])
				break;
			++y;
			days = days - (long) year_lengths[yleap];
		}
	else do {
		--y;
		yleap = isleap(y);
		days = days + (long) year_lengths[yleap];
	} while (days < 0);
	tmp->tm_year = y - TM_YEAR_BASE;
	tmp->tm_yday = (int) days;
	ip = mon_lengths[yleap];
	for (tmp->tm_mon = 0; days >= (long) ip[tmp->tm_mon]; ++(tmp->tm_mon))
		days = days - (long) ip[tmp->tm_mon];
	tmp->tm_mday = (int) (days + 1);
	tmp->tm_isdst = 0;
	tmp->tm_zone = "";
	tmp->tm_gmtoff = offset;
	return tmp;
E 12
}
E 1
