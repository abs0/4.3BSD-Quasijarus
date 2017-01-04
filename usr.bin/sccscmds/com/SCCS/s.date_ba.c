h04442
s 00005/00011/00011
d D 5.3 2011/07/13 06:33:50 msokolov 3 2
c finally switched to 4-digit years
e
s 00001/00001/00021
d D 5.2 99/12/14 21:32:27 msokolov 2 1
c Y2K
e
s 00022/00000/00000
d D 5.1 99/12/14 21:31:04 msokolov 1 0
c date and time created 99/12/14 21:31:04 by msokolov
e
u
U
t
T
I 1
# include	"../hdr/defines.h"
D 3
# define DO2(p,n,c)	*p++ = n/10 + '0'; *p++ = n%10 + '0'; *p++ = c;
E 3

static char Sccsid[] = "%W%	%G%";

date_ba(bdt,adt)
long *bdt;
char *adt;
{
D 3
	register struct tm *lcltm;
	register char *p;
E 3
I 3
	register struct tm *tm;
E 3

D 3
	lcltm = localtime(bdt);
	p = adt;
D 2
	DO2(p,lcltm->tm_year,'/');
E 2
I 2
	DO2(p,(lcltm->tm_year % 100),'/');
E 2
	DO2(p,(lcltm->tm_mon + 1),'/');
	DO2(p,lcltm->tm_mday,' ');
	DO2(p,lcltm->tm_hour,':');
	DO2(p,lcltm->tm_min,':');
	DO2(p,lcltm->tm_sec,0);
E 3
I 3
	tm = gmtime(bdt);
	sprintf(adt, "%04d/%02d/%02d %02d:%02d:%02d", tm->tm_year + 1900,
		tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min,
		tm->tm_sec);
E 3
	return(adt);
}
E 1
