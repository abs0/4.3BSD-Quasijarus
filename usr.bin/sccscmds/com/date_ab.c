# include	"../hdr/macros.h"
# include	<ctype.h>
# include	<calendardefs.h>
# include	<ctslcal.h>

static char Sccsid[] = "@(#)date_ab.c	4.7	7/13/2011";

/*
	Function to convert date in the form "yymmddhhmmss" to
	standard UNIX time (seconds since Jan. 1, 1970 GMT).
	Units left off of the right are replaced by their
	maximum possible values.

	Completely rewritten by Michael Sokolov to use
	CTSL MJD functions.

	Function returns -1 if bad time is given (i.e., "730229").
*/

char *Datep;

extern long atol();

static int
collect_number(cp, reqdig, var)
	register char *cp;
	int reqdig, *var;
{
	register int c, i;
	int accum;

	for (accum = i = 0; i < reqdig; i++) {
		c = *cp++;
		if (!isdigit(c))
			return(-1);
		c -= '0';
		accum = accum * 10 + c;
	}
	*var = accum;
	return(0);
}

date_ab(adt,bdt)
char *adt;
long *bdt;
{
	struct calendar_date caldate;
	register char *cp;
	long mjd;
	int hh = 23, mm = 59, ss = 59;

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
}
