h05744
s 00002/00002/00054
d D 4.6 87/05/02 15:57:51 bostic 6 5
c don't use char tabs in printfs
e
s 00002/00002/00054
d D 4.5 84/05/07 14:40:36 ralph 5 4
c allow tabs for sepparators.
e
s 00001/00001/00055
d D 4.4 83/07/03 20:15:51 sam 4 3
c include fix
e
s 00003/00002/00053
d D 4.3 82/06/28 03:39:39 wnj 3 2
c fix to allow 08/... in dates (for Ted Kowalski)
e
s 00002/00000/00053
d D 4.2 81/02/28 20:49:29 wnj 2 1
c fixes from various sources for clean termination
e
s 00053/00000/00000
d D 4.1 81/02/28 20:45:55 wnj 1 0
c date and time created 81/02/28 20:45:55 by wnj
e
u
U
t
T
I 1
static	char *sccsid = "%W% (Berkeley) %E%";
/* /usr/lib/calendar produces an egrep -f file
   that will select today's and tomorrow's
   calendar entries, with special weekend provisions

   used by calendar command
*/
D 4
#include <time.h>
E 4
I 4
#include <sys/time.h>
E 4

#define DAY (3600*24L)

char *month[] = {
	"[Jj]an",
	"[Ff]eb",
	"[Mm]ar",
	"[Aa]pr",
	"[Mm]ay",
	"[Jj]un",
	"[Jj]ul",
	"[Aa]ug",
	"[Ss]ep",
	"[Oo]ct",
	"[Nn]ov",
	"[Dd]ec"
};
struct tm *localtime();

tprint(t)
long t;
{
	struct tm *tm;
	tm = localtime(&t);
D 3
	printf("(^|[ (,;])((%s[^ ]* *|%d/)0*%d)([^0123456789]|$)\n",
		month[tm->tm_mon], tm->tm_mon + 1, tm->tm_mday);
E 3
I 3
D 5
	printf("(^|[ (,;])((%s[^ ]* *|(0%d|%d)/)0*%d)([^0123456789]|$)\n",
E 5
I 5
D 6
	printf("(^|[ 	(,;])((%s[^ \t]*[ \t]*|(0%d|%d)/)0*%d)([^0123456789]|$)\n",
E 6
I 6
	printf("(^|[ \t(,;])((%s[^ \t]*[ \t]*|(0%d|%d)/)0*%d)([^0123456789]|$)\n",
E 6
E 5
		month[tm->tm_mon],
		tm->tm_mon + 1, tm->tm_mon + 1, tm->tm_mday);
E 3
I 2
D 5
	printf("(^|[ (,;])((\\* *)0*%d)([^0123456789]|$)\n",
E 5
I 5
D 6
	printf("(^|[ 	(,;])((\\*[ \t]*)0*%d)([^0123456789]|$)\n",
E 6
I 6
	printf("(^|[ \t(,;])((\\*[ \t]*)0*%d)([^0123456789]|$)\n",
E 6
E 5
		tm->tm_mday);
E 2
}

main()
{
	long t;
	time(&t);
	tprint(t);
	switch(localtime(&t)->tm_wday) {
	case 5:
		t += DAY;
		tprint(t);
	case 6:
		t += DAY;
		tprint(t);
	default:
		t += DAY;
		tprint(t);
	}
}
E 1
