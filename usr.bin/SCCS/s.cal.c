h65115
s 00034/00040/00168
d D 4.4 87/05/28 21:04:37 sam 4 3
c make cal print calendar for current month with no arguments
e
s 00004/00001/00204
d D 4.3 83/08/11 20:27:38 sam 3 2
c standardize sccs keyword lines
e
s 00001/00001/00204
d D 4.2 82/02/28 23:16:41 wnj 2 1
c fix sccs keywords
e
s 00205/00000/00000
d D 4.1 82/02/28 23:15:28 wnj 1 0
c date and time created 82/02/28 23:15:28 by wnj
e
u
U
t
T
I 1
D 2
char	*sccsid = "%W% %I%";
E 2
I 2
D 3
char	*sccsid = "%W% %E%";
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

I 4
#include <sys/types.h>
#include <time.h>
#include <stdio.h>

E 4
E 3
E 2
char	dayw[] = {
	" S  M Tu  W Th  F  S"
};
char	*smon[]= {
	"January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December",
};
char	string[432];
main(argc, argv)
char *argv[];
{
	register y, i, j;
	int m;

D 4
	if(argc < 2) {
		printf("usage: cal [month] year\n");
		exit(0);
	}
E 4
	if(argc == 2)
		goto xlong;
I 4
	/*
	 * print out just month
	 */
	if(argc < 2) {			/* current month */
		time_t t;
		struct tm *tm;
E 4

D 4
/*
 *	print out just month
 */

	m = number(argv[1]);
	if(m<1 || m>12)
		goto badarg;
	y = number(argv[2]);
	if(y<1 || y>9999)
		goto badarg;
E 4
I 4
		t = time(0);
		tm = localtime(&t);
		m = tm->tm_mon + 1;
		y = tm->tm_year + 1900;
	} else {
		m = atoi(argv[1]);
		if(m<1 || m>12) {
			fprintf(stderr, "cal: %s: Bad month.\n", argv[1]);
			exit(1);
		}
		y = atoi(argv[2]);
		if(y<1 || y>9999) {
			fprintf(stderr, "cal: %s: Bad year.\n", argv[2]);
			exit(2);
		}
	}
E 4
	printf("   %s %u\n", smon[m-1], y);
	printf("%s\n", dayw);
	cal(m, y, string, 24);
	for(i=0; i<6*24; i+=24)
		pstr(string+i, 24);
	exit(0);

D 4
/*
 *	print out complete year
 */

E 4
xlong:
D 4
	y = number(argv[1]);
	if(y<1 || y>9999)
		goto badarg;
E 4
I 4
	/*
	 * print out complete year
	 */
	y = atoi(argv[1]);
	if(y<1 || y>9999) {
		fprintf(stderr, "cal: %s: Bad year.\n", argv[1]);
		exit(2);
	}
E 4
	printf("\n\n\n");
	printf("				%u\n", y);
	printf("\n");
	for(i=0; i<12; i+=3) {
		for(j=0; j<6*72; j++)
			string[j] = '\0';
		printf("	 %.3s", smon[i]);
		printf("			%.3s", smon[i+1]);
		printf("		       %.3s\n", smon[i+2]);
		printf("%s   %s   %s\n", dayw, dayw, dayw);
		cal(i+1, y, string, 72);
		cal(i+2, y, string+23, 72);
		cal(i+3, y, string+46, 72);
		for(j=0; j<6*72; j+=72)
			pstr(string+j, 72);
	}
	printf("\n\n\n");
	exit(0);
D 4

badarg:
	printf("Bad argument\n");
}

number(str)
char *str;
{
	register n, c;
	register char *s;

	n = 0;
	s = str;
	while(c = *s++) {
		if(c<'0' || c>'9')
			return(0);
		n = n*10 + c-'0';
	}
	return(n);
E 4
}

pstr(str, n)
char *str;
{
	register i;
	register char *s;

	s = str;
	i = n;
	while(i--)
		if(*s++ == '\0')
			s[-1] = ' ';
	i = n+1;
	while(i--)
		if(*--s != ' ')
			break;
	s[1] = '\0';
	printf("%s\n", str);
}

char	mon[] = {
	0,
	31, 29, 31, 30,
	31, 30, 31, 31,
	30, 31, 30, 31,
};

cal(m, y, p, w)
char *p;
{
	register d, i;
	register char *s;

	s = p;
	d = jan1(y);
	mon[2] = 29;
	mon[9] = 30;

	switch((jan1(y+1)+7-d)%7) {

	/*
	 *	non-leap year
	 */
	case 1:
		mon[2] = 28;
		break;

	/*
	 *	1752
	 */
	default:
		mon[9] = 19;
		break;

	/*
	 *	leap year
	 */
	case 2:
		;
	}
	for(i=1; i<m; i++)
		d += mon[i];
	d %= 7;
	s += 3*d;
	for(i=1; i<=mon[m]; i++) {
		if(i==3 && mon[m]==19) {
			i += 11;
			mon[m] += 11;
		}
		if(i > 9)
			*s = i/10+'0';
		s++;
		*s++ = i%10+'0';
		s++;
		if(++d == 7) {
			d = 0;
			s = p+w;
			p = s;
		}
	}
}

/*
 *	return day of the week
 *	of jan 1 of given year
 */

jan1(yr)
{
	register y, d;

/*
 *	normal gregorian calendar
 *	one extra day per four years
 */

	y = yr;
	d = 4+y+(y+3)/4;

/*
 *	julian calendar
 *	regular gregorian
 *	less three days per 400
 */

	if(y > 1800) {
		d -= (y-1701)/100;
		d += (y-1601)/400;
	}

/*
 *	great calendar changeover instant
 */

	if(y > 1752)
		d += 3;

	return(d%7);
}
E 1
