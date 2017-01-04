# include	"../hdr/defines.h"

static char Sccsid[] = "@(#)date_ba.c	5.3	7/13/2011";

date_ba(bdt,adt)
long *bdt;
char *adt;
{
	register struct tm *tm;

	tm = gmtime(bdt);
	sprintf(adt, "%04d/%02d/%02d %02d:%02d:%02d", tm->tm_year + 1900,
		tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min,
		tm->tm_sec);
	return(adt);
}
