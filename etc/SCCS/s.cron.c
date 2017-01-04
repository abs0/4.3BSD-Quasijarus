h07977
s 00044/00022/00336
d D 4.13 87/09/30 14:32:08 bostic 16 15
c lint & error logging; bug reports 4.3BSD/etc/{80,81}
e
s 00030/00005/00328
d D 4.12 86/05/27 17:41:26 mckusick 15 14
c add ``-d file'' to log process executions and exit codes
e
s 00054/00018/00279
d D 4.11 86/01/10 04:33:01 lepreau 14 13
c Handle crontab.local and/or crontab (or neither); cleanups
e
s 00000/00002/00297
d D 4.10 85/10/31 20:18:24 bloom 13 12
c don't use old free() - realloc() since (from chris@maryland)
e
s 00046/00009/00253
d D 4.9 84/12/17 09:45:47 bloom 12 11
c add user to run as for security
e
s 00001/00001/00261
d D 4.8 83/08/14 22:33:35 mckusick 11 10
c == should be = (kre)
e
s 00004/00001/00258
d D 4.7 83/07/02 00:18:42 sam 10 9
c include fixes
e
s 00003/00002/00256
d D 4.6 82/06/28 04:25:50 wnj 9 8
c fix to fixes
e
s 00002/00002/00256
d D 4.5 82/06/28 04:24:08 wnj 8 7
c typo
e
s 00004/00002/00254
d D 4.4 82/06/28 04:22:56 wnj 7 6
c fix bug that caused core dumps, sunday is now 7
e
s 00006/00003/00250
d D 4.3 81/07/05 19:14:59 root 6 2
c fix to runaway cron when time changes
e
s 00006/00003/00250
d R 4.3 81/07/05 19:13:10 root 5 2
c prevent runaway cron when time changes
e
s 00006/00003/00250
d R 4.3 81/07/05 18:52:31 root 4 2
c new cron fixing ``runaway'' after time moved forward
e
s 00006/00001/00252
d R 4.3 81/07/05 18:49:27 root 3 2
c fix to runaway cron problem when time set
e
s 00005/00005/00248
d D 4.2 81/05/17 20:12:32 root 2 1
c DLW sent fix (anything that goes off at 2 won't work)
e
s 00253/00000/00000
d D 4.1 80/10/01 17:25:53 bill 1 0
c date and time created 80/10/01 17:25:53 by bill
e
u
U
t
T
I 10
#ifndef lint
E 10
I 1
static char *sccsid = "%W% (Berkeley) %G%";
I 10
#endif

E 10
#include <sys/types.h>
#include <stdio.h>
#include <ctype.h>
#include <signal.h>
D 10
#include <time.h>
E 10
I 10
#include <sys/time.h>
E 10
#include <sys/stat.h>
I 12
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/file.h>
I 16
#include <sys/resource.h>
E 16
#include <pwd.h>
I 15
#include <fcntl.h>
I 16
#include <syslog.h>
E 16
E 15
E 12

D 7
#define	LISTS	512
E 7
I 7
D 9
#define	LISTS	BUFSIZ
E 9
I 9
#define	LISTS	(2*BUFSIZ)
#define	MAXLIN	BUFSIZ
E 9
E 7

I 12
#ifndef CRONTAB
#define CRONTAB "/usr/lib/crontab"
#endif

I 14
#ifndef CRONTABLOC
#define CRONTABLOC  "/usr/lib/crontab.local"
#endif

E 14
E 12
D 2
#define	EXACT	0
#define	ANY	1
#define	LIST	2
#define	RANGE	3
#define	EOS	4
E 2
I 2
#define	EXACT	100
#define	ANY	101
#define	LIST	102
#define	RANGE	103
#define	EOS	104
I 14

E 14
E 2
D 12
char	crontab[]	= "/usr/lib/crontab";
E 12
I 12
char	crontab[]	= CRONTAB;
I 14
char	loc_crontab[]   = CRONTABLOC;
E 14
E 12
D 16
time_t	itime;
E 16
I 16
time_t	itime, time();
E 16
struct	tm *loct;
struct	tm *localtime();
char	*malloc();
char	*realloc();
I 12
int	reapchild();
E 12
int	flag;
char	*list;
I 14
char	*listend;
E 14
unsigned listsize;

D 15
main()
E 15
I 15
FILE	*debug;
#define dprintf if (debug) fprintf

main(argc, argv)
	int argc;
	char **argv;
E 15
{
	register char *cp;
	char *cmp();
	time_t filetime = 0;
I 14
	time_t lfiletime = 0;
I 15
	char c;
	extern char *optarg;
E 15
E 14

D 12
     /*	setuid(1); */
E 12
D 16
	if (fork())
E 16
I 16
	openlog("cron", LOG_PID | LOG_CONS | LOG_NOWAIT, LOG_DAEMON);
	switch (fork()) {

	case -1:
		syslog(LOG_ERR, "fork: %m");
		exit(1);
		/* NOTREACHED */
	case 0:
		break;
	default:
E 16
		exit(0);
I 16
		/* NOTREACHED */
	}

E 16
I 15
	c = getopt(argc, argv, "d:");
	if (c == 'd') {
		debug = fopen(optarg, "w");
		if (debug == NULL)
			exit(1);
D 16
		fcntl(fileno(debug), F_SETFL, FAPPEND);
E 16
I 16
		(void) fcntl(fileno(debug), F_SETFL, FAPPEND);
E 16
	}
E 15
D 16
	chdir("/");
D 12
	freopen(crontab, "r", stdin);
E 12
	freopen("/", "r", stdout);
	freopen("/", "r", stderr);
E 16
I 16
	(void) chdir("/");
	(void) freopen("/", "r", stdout);
	(void) freopen("/", "r", stderr);
E 16
I 12
	untty();
E 12
D 16
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
I 12
	signal(SIGCHLD, reapchild);
E 12
	time(&itime);
E 16
I 16
	(void) signal(SIGHUP, SIG_IGN);
	(void) signal(SIGINT, SIG_IGN);
	(void) signal(SIGQUIT, SIG_IGN);
	(void) signal(SIGCHLD, reapchild);
	(void) time(&itime);
E 16
	itime -= localtime(&itime)->tm_sec;
D 12
	fclose(stdin);
E 12

	for (;; itime+=60, slp()) {
D 14
		struct stat cstat;

		if (stat(crontab, &cstat) == -1)
			continue;
		if (cstat.st_mtime > filetime) {
E 14
I 14
		struct stat cstat, lcstat;
		int newcron, newloc;
		
		newcron = 0;
		if (stat(crontab, &cstat) < 0)
		    cstat.st_mtime = 1;
		if (cstat.st_mtime != filetime) {
E 14
			filetime = cstat.st_mtime;
I 14
			newcron++;
		}

		newloc  = 0;
		if (stat(loc_crontab, &lcstat) < 0)
		    lcstat.st_mtime = 1;
		if (lcstat.st_mtime != lfiletime) {
			lfiletime = lcstat.st_mtime;
			newloc++;
		}

		if (newcron || newloc) {
E 14
			init();
I 14
			append(crontab);
			append(loc_crontab);
			*listend++ = EOS;
			*listend++ = EOS;
E 14
		}
I 14

E 14
		loct = localtime(&itime);
		loct->tm_mon++;		 /* 1-12 for month */
I 7
D 8
		if (loct->tm_day == 0)
			loct->tm_day == 7;	/* sunday is 7, not 0 */
E 8
I 8
		if (loct->tm_wday == 0)
D 11
			loct->tm_wday == 7;	/* sunday is 7, not 0 */
E 11
I 11
			loct->tm_wday = 7;	/* sunday is 7, not 0 */
E 11
E 8
E 7
		for(cp = list; *cp != EOS;) {
			flag = 0;
			cp = cmp(cp, loct->tm_min);
			cp = cmp(cp, loct->tm_hour);
			cp = cmp(cp, loct->tm_mday);
			cp = cmp(cp, loct->tm_mon);
			cp = cmp(cp, loct->tm_wday);
D 6
			if(flag == 0) {
				slp();
E 6
I 6
			if(flag == 0)
E 6
				ex(cp);
D 6
			}
E 6
			while(*cp++ != 0)
				;
		}
	}
}

char *
cmp(p, v)
char *p;
{
	register char *cp;

	cp = p;
	switch(*cp++) {

	case EXACT:
		if (*cp++ != v)
			flag++;
		return(cp);

	case ANY:
		return(cp);

	case LIST:
		while(*cp != LIST)
			if(*cp++ == v) {
				while(*cp++ != LIST)
					;
				return(cp);
			}
		flag++;
		return(cp+1);

	case RANGE:
		if(*cp > v || cp[1] < v)
			flag++;
		return(cp+2);
	}
	if(cp[-1] != v)
		flag++;
	return(cp);
}

slp()
{
	register i;
	time_t t;

D 16
	time(&t);
E 16
I 16
	(void) time(&t);
E 16
	i = itime - t;
I 6
	if(i < -60 * 60 || i > 60 * 60) {
		itime = t;
		i = 60 - localtime(&itime)->tm_sec;
		itime += i;
	}
E 6
	if(i > 0)
D 16
		sleep(i);
E 16
I 16
		sleep((u_int)i);
E 16
}

ex(s)
char *s;
{
D 16
	int st;
E 16
I 12
	register struct passwd *pwd;
	char user[BUFSIZ];
	char *c = user;
I 15
	int pid;
E 15
E 12

D 15
	if(fork()) {
E 15
I 15
D 16
	if (fork()) {
E 16
I 16
	switch (fork()) {
	case 0:
		break;
	case -1:
		syslog(LOG_ERR, "cannot fork: %m (running %.40s%s)",
			s, strlen(s) > 40 ? "..." : "");
		/*FALLTHROUGH*/
	default:
E 16
E 15
D 12
		wait(&st);
E 12
		return;
	}
D 12
	if(fork())
		exit(0);
E 12
I 12
D 16

E 16
I 15
	pid = getpid();
E 15
	while(*s != ' ' && *s != '\t')
		*c++ = *s++;
	*c = '\0';
I 15
	s++;
E 15
	if ((pwd = getpwnam(user)) == NULL) {
I 16
		syslog(LOG_ERR, "invalid user name \"%s\"", user);
E 16
I 15
		dprintf(debug, "%d: cannot find %s\n", pid, user),
			fflush(debug);
E 15
		exit(1);
	}
	(void) setgid(pwd->pw_gid);
D 16
	initgroups(pwd->pw_name, pwd->pw_gid);
E 16
I 16
	(void) initgroups(pwd->pw_name, pwd->pw_gid);
E 16
	(void) setuid(pwd->pw_uid);
E 12
D 16
	freopen("/", "r", stdin);
E 16
I 16
	(void) freopen("/", "r", stdin);
	closelog();
E 16
D 12
	execl("/bin/sh", "sh", "-c", s, 0);
E 12
I 12
D 15
	execl("/bin/sh", "sh", "-c", ++s, 0);
E 15
I 15
	dprintf(debug, "%d: executing %s", pid, s), fflush (debug);
	execl("/bin/sh", "sh", "-c", s, 0);
I 16
	syslog(LOG_ERR, "cannot exec /bin/sh: %m");
E 16
	dprintf(debug, "%d: cannot execute sh\n", pid), fflush (debug);
E 15
E 12
	exit(0);
}

init()
{
I 14
	/*
	 * Don't free in case was longer than LISTS.  Trades off
	 * the rare case of crontab shrinking vs. the common case of
	 * extra realloc's needed in append() for a large crontab.
	 */
	if (list == 0) {
		list = malloc(LISTS);
		listsize = LISTS;
	}
	listend = list;
}

append(fn)
char *fn;
{
E 14
	register i, c;
	register char *cp;
	register char *ocp;
	register int n;

D 14
	freopen(crontab, "r", stdin);
	if (list) {
D 13
		free(list);
E 13
		list = realloc(list, LISTS);
	} else
		list = malloc(LISTS);
	listsize = LISTS;
	cp = list;

E 14
I 14
	if (freopen(fn, "r", stdin) == NULL)
		return;
	cp = listend;
E 14
loop:
D 7
	if(cp > list+listsize-100) {
E 7
I 7
D 9
	if(cp > list+listsize-BUFSIZ) {
E 9
I 9
	if(cp > list+listsize-MAXLIN) {
E 9
E 7
D 14
		char *olist;
E 14
I 14
		int length = cp - list;

E 14
		listsize += LISTS;
D 14
		olist = list;
E 14
D 13
		free(list);
E 13
		list = realloc(list, listsize);
D 14
		cp = list + (cp - olist);
E 14
I 14
		cp = list + length;
E 14
	}
	ocp = cp;
	for(i=0;; i++) {
		do
			c = getchar();
		while(c == ' ' || c == '\t')
			;
		if(c == EOF || c == '\n')
			goto ignore;
		if(i == 5)
			break;
		if(c == '*') {
			*cp++ = ANY;
			continue;
		}
		if ((n = number(c)) < 0)
			goto ignore;
		c = getchar();
		if(c == ',')
			goto mlist;
		if(c == '-')
			goto mrange;
		if(c != '\t' && c != ' ')
			goto ignore;
		*cp++ = EXACT;
		*cp++ = n;
		continue;

	mlist:
		*cp++ = LIST;
		*cp++ = n;
		do {
			if ((n = number(getchar())) < 0)
				goto ignore;
			*cp++ = n;
			c = getchar();
		} while (c==',');
		if(c != '\t' && c != ' ')
			goto ignore;
		*cp++ = LIST;
		continue;

	mrange:
		*cp++ = RANGE;
		*cp++ = n;
		if ((n = number(getchar())) < 0)
			goto ignore;
		c = getchar();
		if(c != '\t' && c != ' ')
			goto ignore;
		*cp++ = n;
	}
	while(c != '\n') {
		if(c == EOF)
			goto ignore;
		if(c == '%')
			c = '\n';
		*cp++ = c;
		c = getchar();
	}
	*cp++ = '\n';
	*cp++ = 0;
	goto loop;

ignore:
	cp = ocp;
	while(c != '\n') {
		if(c == EOF) {
D 14
			*cp++ = EOS;
			*cp++ = EOS;
E 14
D 16
			fclose(stdin);
E 16
I 16
			(void) fclose(stdin);
E 16
I 14
			listend = cp;
E 14
			return;
		}
		c = getchar();
	}
	goto loop;
}

number(c)
register c;
{
	register n = 0;

	while (isdigit(c)) {
		n = n*10 + c - '0';
		c = getchar();
	}
D 16
	ungetc(c, stdin);
E 16
I 16
	(void) ungetc(c, stdin);
E 16
D 12
	if (n>100)
E 12
I 12
	if (n>=100)
E 12
		return(-1);
	return(n);
I 12
}

reapchild()
{
	union wait status;
I 15
	int pid;
E 15

D 15
	while(wait3(&status, WNOHANG, 0) > 0)
		;
E 15
I 15
D 16
	while ((pid = wait3(&status, WNOHANG, 0)) > 0)
E 16
I 16
	while ((pid = wait3(&status, WNOHANG, (struct rusage *)0)) > 0)
E 16
		dprintf(debug, "%d: child exits with signal %d status %d\n",
			pid, status.w_termsig, status.w_retcode),
			fflush (debug);
E 15
}

untty()
{
	int i;

	i = open("/dev/tty", O_RDWR);
	if (i >= 0) {
D 16
		ioctl(i, TIOCNOTTY, (char *)0);
E 16
I 16
		(void) ioctl(i, TIOCNOTTY, (char *)0);
E 16
		(void) close(i);
	}
E 12
}
E 1
