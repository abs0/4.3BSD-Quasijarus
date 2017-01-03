# include	"../hdr/defines.h"
# define DO2(p,n,c)	*p++ = n/10 + '0'; *p++ = n%10 + '0'; *p++ = c;

static char Sccsid[] = "@(#)date_ba.c	5.2	12/14/99";

date_ba(bdt,adt)
long *bdt;
char *adt;
{
	register struct tm *lcltm;
	register char *p;

	lcltm = localtime(bdt);
	p = adt;
	DO2(p,(lcltm->tm_year % 100),'/');
	DO2(p,(lcltm->tm_mon + 1),'/');
	DO2(p,lcltm->tm_mday,' ');
	DO2(p,lcltm->tm_hour,':');
	DO2(p,lcltm->tm_min,':');
	DO2(p,lcltm->tm_sec,0);
	return(adt);
}
