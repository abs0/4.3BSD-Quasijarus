h65276
s 00113/00086/00025
d D 4.7 2011/07/13 06:33:49 msokolov 7 6
c finally switched to 4-digit years
e
s 00006/00002/00105
d D 4.6 99/12/14 21:20:17 msokolov 6 5
c Y2K
e
s 00004/00000/00103
d D 4.5 87/10/06 19:12:58 bostic 5 4
c fix removal of dysize() from C library
e
s 00014/00014/00089
d D 4.4 87/02/15 16:42:21 lepreau 4 3
c modern syntax for asgops & inits; sccs keywords
e
s 00002/00001/00101
d D 4.3 85/05/03 23:38:12 sam 3 2
c build in day-month table from ctime to avoid local ctime
e
s 00001/00001/00101
d D 4.2 81/01/28 10:52:48 eric 2 1
c fix timezone calculation
e
s 00102/00000/00000
d D 4.1 81/01/15 13:47:30 eric 1 0
c date and time created 81/01/15 13:47:30 by eric
e
u
U
f b 
f i 
t
T
I 1
# include	"../hdr/macros.h"
I 5
D 7
# include	<tzfile.h>
E 7
I 7
# include	<ctype.h>
# include	<calendardefs.h>
# include	<ctslcal.h>
E 7
E 5

D 4
SCCSID(%W%);
E 4
I 4
static char Sccsid[] = "%W%	%G%";
E 4

/*
	Function to convert date in the form "yymmddhhmmss" to
	standard UNIX time (seconds since Jan. 1, 1970 GMT).
	Units left off of the right are replaced by their
	maximum possible values.

D 7
	The function corrects properly for leap year,
	daylight savings time, offset from Greenwich time, etc.
E 7
I 7
	Completely rewritten by Michael Sokolov to use
	CTSL MJD functions.
E 7

	Function returns -1 if bad time is given (i.e., "730229").
*/
I 5

D 7
#define	dysize(year)	(isleap(year) ? DAYS_PER_LYEAR : DAYS_PER_NYEAR)

E 7
E 5
char *Datep;

I 7
extern long atol();
E 7

D 7
date_ab(adt,bdt)
char *adt;
long *bdt;
E 7
I 7
static int
collect_number(cp, reqdig, var)
	register char *cp;
	int reqdig, *var;
E 7
{
D 7
	int y, t, d, h, m, s, i;
	long tim;
	extern int *localtime();
#define	time_t	long
#include <sys/timeb.h>
	struct timeb timeb;
E 7
I 7
	register int c, i;
	int accum;
E 7

D 7
	ftime(&timeb);
	Datep = adt;

	if((y=g2()) == -2) y = 99;
D 6
	if(y<70 || y>99) return(-1);
E 6
I 6
	if (y < 0)
		return(-1);
	if (y >= 70)
		y += 1900;
	else
		y += 2000;
E 6

	if((t=g2()) == -2) t = 12;
	if(t<1 || t>12) return(-1);

	if((d=g2()) == -2) d = mosize(y,t);
	if(d<1 || d>mosize(y,t)) return(-1);

	if((h=g2()) == -2) h = 23;
	if(h<0 || h>23) return(-1);

	if((m=g2()) == -2) m = 59;
	if(m<0 || m>59) return(-1);

	if((s=g2()) == -2) s = 59;
	if(s<0 || s>59) return(-1);

	tim = 0L;
D 4
	y =+ 1900;
E 4
I 4
D 6
	y += 1900;
E 6
E 4
	for(i=1970; i<y; i++)
D 4
		tim =+ dysize(i);
E 4
I 4
		tim += dysize(i);
E 4
	while(--t)
D 4
		tim =+ mosize(y,t);
	tim =+ d - 1;
	tim =* 24;
	tim =+ h;
	tim =* 60;
	tim =+ m;
I 2
	tim =+ timeb.timezone;			/* GMT correction */
E 2
	tim =* 60;
	tim =+ s;
E 4
I 4
		tim += mosize(y,t);
	tim += d - 1;
	tim *= 24;
	tim += h;
	tim *= 60;
	tim += m;
	tim += timeb.timezone;			/* GMT correction */
	tim *= 60;
	tim += s;
E 4

D 2
	tim =+ timeb.timezone;			/* GMT correction */
E 2
	if(localtime(&tim)[8])
D 4
		tim =+ -1*60*60;		/* daylight savings */
E 4
I 4
		tim += -1*60*60;		/* daylight savings */
E 4
	*bdt = tim;
E 7
I 7
	for (accum = i = 0; i < reqdig; i++) {
		c = *cp++;
		if (!isdigit(c))
			return(-1);
		c -= '0';
		accum = accum * 10 + c;
	}
	*var = accum;
E 7
	return(0);
}

D 7

mosize(y,t)
int y, t;
E 7
I 7
date_ab(adt,bdt)
char *adt;
long *bdt;
E 7
{
D 3
	extern int dmsize[];
E 3
I 3
D 7
	static	int dmsize[12] =
	    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
E 7
I 7
	struct calendar_date caldate;
	register char *cp;
	long mjd;
	int hh = 23, mm = 59, ss = 59;
E 7
E 3

D 7
	if(t==2 && dysize(y)==366) return(29);
	return(dmsize[t-1]);
}


g2()
{
	register int c;
	register char *p;

	for (p = Datep; *p; p++)
		if (numeric(*p))
			break;
	if (*p) {
		c = (*p++ - '0') * 10;
		if (*p)
D 4
			c =+ (*p++ - '0');
E 4
I 4
			c += (*p++ - '0');
E 4
		else
			c = -1;
	}
	else
		c = -2;
	Datep = p;
	return(c);
E 7
I 7
	for (cp = adt; isspace(*cp); cp++)
		;
	if (isdigit(*cp)) {
		/* assume Gregorian, deal with the 2 vs 4 digit mess */
		if (cp[0] == '1' && cp[1] == '9' || cp[0] == '2') {
			if (collect_number(cp, 4, &caldate.year) < 0)
				return(-1);
			cp += 4;
		} else if (cp[0] >= '7') {	/* 2-digit year */
			if (collect_number(cp, 2, &caldate.year) < 0)
				return(-1);
			cp += 2;
			caldate.year += 1900;
		} else if (cp[0] == '0' ||
			   cp[0] == '1' && (cp[1] == '0' || cp[1] == '1')) {
			/* silly me kept using 2-digit years through 2011! */
			if (collect_number(cp, 2, &caldate.year) < 0)
				return(-1);
			cp += 2;
			caldate.year += 2000;
		} else
			return(-1);
		while (*cp && !isdigit(*cp))
			cp++;
		if (*cp) {
			/* require both month and day */
			if (collect_number(cp, 2, &caldate.month) < 0)
				return(-1);
			cp += 2;
			while (*cp && !isdigit(*cp))
				cp++;
			if (collect_number(cp, 2, &caldate.day) < 0)
				return(-1);
			cp += 2;
			if (!roman_date_valid(&caldate, 1))
				return(-1);
		} else {
			caldate.month = 12;
			caldate.day = 31;
			/* we know it's valid */
		}
		mjd = gregtomjd(&caldate);
	} else if (cp[0] == 'M' && cp[1] == 'J' && cp[2] == 'D') {
		cp += 3;
		while (*cp && !isdigit(*cp))
			cp++;
		if (!isdigit(*cp))
			return(-1);
		mjd = atol(cp);
		while (isdigit(*cp))
			cp++;
	} else
		return(-1);
	if (mjd < UNIX_EPOCH_MJD)
		return(-1);
	/* now collect HH:MM:SS */
	while (*cp && !isdigit(*cp))
		cp++;
	if (!*cp)
		goto finish;
	if (collect_number(cp, 2, &hh) < 0)
		return(-1);
	cp += 2;
	if (hh > 23)
		return(-1);
	while (*cp && !isdigit(*cp))
		cp++;
	if (!*cp)
		goto finish;
	if (collect_number(cp, 2, &mm) < 0)
		return(-1);
	cp += 2;
	if (mm > 59)
		return(-1);
	while (*cp && !isdigit(*cp))
		cp++;
	if (!*cp)
		goto finish;
	if (collect_number(cp, 2, &ss) < 0)
		return(-1);
	cp += 2;
	if (ss > 59)
		return(-1);
finish:	Datep = cp;
	*bdt = (mjd-UNIX_EPOCH_MJD) * 86400 + hh*3600 + mm*60 + ss;
	return(0);
E 7
}
E 1
