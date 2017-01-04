h60749
s 00004/00002/00273
d D 4.7 83/07/02 00:17:54 sam 7 6
c include fixes
e
s 00001/00001/00274
d D 4.6 82/06/27 15:26:17 wnj 6 5
c fix to banner
e
s 00001/00001/00274
d D 4.5 82/06/27 15:19:51 root 5 4
c fix to make stamp decoding correspond to that created by date
e
s 00022/00000/00253
d D 4.4 82/02/13 15:32:25 root 4 3
c bug fix: deal properly with ttynames other an tty00-tty99
e
s 00001/00001/00252
d D 4.3 81/07/02 18:43:49 root 3 2
c dont give free sessions if > 1.5 day
e
s 00002/00002/00251
d D 4.2 81/07/02 01:30:53 bugs 2 1
c fixes to name processing (8 char names and non-alnum names work) per z@cca
e
s 00253/00000/00000
d D 4.1 80/10/01 17:24:32 bill 1 0
c date and time created 80/10/01 17:24:32 by bill
e
u
U
t
T
I 7
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 7
I 1
/*
D 6
 * acct [ -w wtmp ] [ -d ] [ -p ] [ people ]
E 6
I 6
 * ac [ -w wtmp ] [ -d ] [ -p ] [ people ]
E 6
 */
D 7
static char *sccsid = "%W% (Berkeley) %G%";
E 7

#include <stdio.h>
#include <ctype.h>
D 7
#include <time.h>
E 7
#include <utmp.h>
I 7
#include <sys/time.h>
E 7
#include <sys/types.h>
#include <sys/timeb.h>

#define NMAX sizeof(ibuf.ut_name)
#define LMAX sizeof(ibuf.ut_line)

I 4
/*
E 4
#define	TSIZE	1000
I 4
*/
#define TSIZE  6242
E 4
#define	USIZE	500
struct  utmp ibuf;

struct ubuf {
	char	uname[NMAX];
	long	utime;
} ubuf[USIZE];

struct tbuf {
	struct	ubuf	*userp;
	long	ttime;
} tbuf[TSIZE];

char	*wtmp;
int	pflag, byday;
long	dtime;
long	midnight;
long	lastime;
long	day	= 86400L;
int	pcount;
char	**pptr;

main(argc, argv) 
char **argv;
{
	int c, fl;
	register i;
	FILE *wf;

	wtmp = "/usr/adm/wtmp";
	while (--argc > 0 && **++argv == '-')
	switch(*++*argv) {
	case 'd':
		byday++;
		continue;

	case 'w':
		if (--argc>0)
			wtmp = *++argv;
		continue;

	case 'p':
		pflag++;
		continue;
	}
	pcount = argc;
	pptr = argv;
	if ((wf = fopen(wtmp, "r")) == NULL) {
		printf("No %s\n", wtmp);
		exit(1);
	}
	for(;;) {
		if (fread((char *)&ibuf, sizeof(ibuf), 1, wf) != 1)
			break;
		fl = 0;
		for (i=0; i<NMAX; i++) {
			c = ibuf.ut_name[i];
D 2
			if(isdigit(c) || isalpha(c)) {
E 2
I 2
			if (isprint(c) && c != ' ') {
E 2
				if (fl)
					goto skip;
				continue;
			}
			if (c==' ' || c=='\0') {
				fl++;
				ibuf.ut_name[i] = '\0';
			} else
				goto skip;
		}
		loop();
    skip:;
	}
	ibuf.ut_name[0] = '\0';
	ibuf.ut_line[0] = '~';
	time(&ibuf.ut_time);
	loop();
	print();
	exit(0);
}

loop()
{
	register i;
	register struct tbuf *tp;
	register struct ubuf *up;

	if(ibuf.ut_line[0] == '|') {
		dtime = ibuf.ut_time;
		return;
	}
D 5
	if(ibuf.ut_line[0] == '}') {
E 5
I 5
	if(ibuf.ut_line[0] == '{') {
E 5
		if(dtime == 0)
			return;
		for(tp = tbuf; tp < &tbuf[TSIZE]; tp++)
			tp->ttime += ibuf.ut_time-dtime;
		dtime = 0;
		return;
	}
	if (lastime>ibuf.ut_time || lastime+(1.5*day)<ibuf.ut_time)
		midnight = 0;
	if (midnight==0)
		newday();
	lastime = ibuf.ut_time;
	if (byday && ibuf.ut_time > midnight) {
		upall(1);
		print();
		newday();
		for (up=ubuf; up < &ubuf[USIZE]; up++)
			up->utime = 0;
	}
	if (ibuf.ut_line[0] == '~') {
		ibuf.ut_name[0] = '\0';
		upall(0);
		return;
	}
I 4
	/*
E 4
	if (ibuf.ut_line[0]=='t')
		i = (ibuf.ut_line[3]-'0')*10 + (ibuf.ut_line[4]-'0');
	else
		i = TSIZE-1;
	if (i<0 || i>=TSIZE)
		i = TSIZE-1;
I 4
	*/

	/*
	 * Correction contributed by Phyllis Kantar @ Rand-unix
	 *
	 * Fixes long standing problem with tty names other than 00-99
	 */
	if (ibuf.ut_line[0]=='t') {
		i = (ibuf.ut_line[3]-'0');
		if(ibuf.ut_line[4])
			i = i*79 + (ibuf.ut_line[4]-'0');
	} else
		i = TSIZE-1;
	if (i<0 || i>=TSIZE) {
		i = TSIZE-1;
		printf("ac: Bad tty name: %s\n", ibuf.ut_line);
	}

E 4
	tp = &tbuf[i];
	update(tp, 0);
}

print()
{
	int i;
	long ttime, t;

	ttime = 0;
	for (i=0; i<USIZE; i++) {
		if(!among(i))
			continue;
		t = ubuf[i].utime;
		if (t>0)
			ttime += t;
		if (pflag && ubuf[i].utime > 0) {
			printf("\t%-*.*s%6.2f\n", NMAX, NMAX,
			    ubuf[i].uname, ubuf[i].utime/3600.);
		}
	}
	if (ttime > 0) {
		pdate();
		printf("\ttotal%9.2f\n", ttime/3600.);
	}
}

upall(f)
{
	register struct tbuf *tp;

	for (tp=tbuf; tp < &tbuf[TSIZE]; tp++)
		update(tp, f);
}

update(tp, f)
struct tbuf *tp;
{
	int j;
	struct ubuf *up;
	long t, t1;

	if (f)
		t = midnight;
	else
		t = ibuf.ut_time;
	if (tp->userp) {
		t1 = t - tp->ttime;
D 3
		if (t1>0 && t1 < 1.5*day)
E 3
I 3
		if (t1 > 0)
E 3
			tp->userp->utime += t1;
	}
	tp->ttime = t;
	if (f)
		return;
	if (ibuf.ut_name[0]=='\0') {
		tp->userp = 0;
		return;
	}
	for (up=ubuf; up < &ubuf[USIZE]; up++) {
		if (up->uname[0] == '\0')
			break;
		for (j=0; j<NMAX && up->uname[j]==ibuf.ut_name[j]; j++);
		if (j>=NMAX)
			break;
	}
	for (j=0; j<NMAX; j++)
		up->uname[j] = ibuf.ut_name[j];
	tp->userp = up;
}

among(i)
{
	register j, k;
	register char *p;

	if (pcount==0)
		return(1);
	for (j=0; j<pcount; j++) {
		p = pptr[j];
		for (k=0; k<NMAX; k++) {
			if (*p == ubuf[i].uname[k]) {
D 2
				if (*p++ == '\0')
E 2
I 2
				if (*p++ == '\0' || k == NMAX-1)
E 2
					return(1);
			} else
				break;
		}
	}
	return(0);
}

newday()
{
	long ttime;
	struct timeb tb;
	struct tm *localtime();

	time(&ttime);
	if (midnight == 0) {
		ftime(&tb);
		midnight = 60*(long)tb.timezone;
		if (localtime(&ttime)->tm_isdst)
			midnight -= 3600;
	}
	while (midnight <= ibuf.ut_time)
		midnight += day;
}

pdate()
{
	long x;
	char *ctime();

	if (byday==0)
		return;
	x = midnight-1;
	printf("%.6s", ctime(&x)+4);
}
E 1
