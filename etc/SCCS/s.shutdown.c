h56403
s 00002/00000/00410
d D 5.7 87/12/26 13:07:23 bostic 27 26
c predeclare finish; fix for ANSI C
e
s 00019/00015/00391
d D 5.6 86/05/26 22:12:27 karels 26 25
c consistency, use SIGTERM once then SIGKILL's, uniform logging (once)
e
s 00004/00002/00402
d D 5.5 86/05/12 17:50:55 eric 25 24
c lint
e
s 00020/00067/00384
d D 5.4 86/05/12 17:45:16 eric 24 23
c shutdownlog subsumed into syslog (as LOG_AUTH)
e
s 00052/00046/00399
d D 5.3 85/11/06 14:18:38 bloom 23 22
c make it lint (almost, putc can't be done easily)
e
s 00040/00004/00405
d D 5.2 85/11/01 16:55:51 bloom 22 21
c add fastboot and nosync flags from David Grubb (dgg@mit-athena)
e
s 00014/00002/00395
d D 5.1 85/05/28 15:36:29 dist 21 20
c Add copyright
e
s 00008/00005/00389
d D 4.20 84/02/02 13:03:00 karels 20 19
c writes restart after alarms!
e
s 00002/00002/00392
d D 4.19 83/06/17 21:19:24 root 19 18
c merge monet
e
s 00003/00002/00391
d D 4.18 83/06/02 17:41:19 sam 18 17
c purge nice
e
s 00002/00000/00391
d D 4.17 83/05/22 23:57:27 sam 17 16
c utmp changed format
e
s 00001/00000/00390
d D 4.16 83/04/29 14:39:10 edward 16 15
c Now ignores SIGTTOU
e
s 00000/00007/00390
d D 4.15 83/01/16 17:31:46 sam 15 14
c check in for bill
e
s 00066/00038/00331
d D 4.14 82/10/23 20:50:21 mckusick 14 13
c lint, output format
e
s 00002/00002/00367
d D 4.13 82/03/15 04:26:59 root 13 12
c machine independent
e
s 00003/00001/00366
d D 4.12 82/03/15 04:25:44 root 12 11
c machine independent
e
s 00004/00003/00363
d D 4.11 82/02/01 08:29:40 root 11 10
c fix by rrh: prints out sysname!username instead of just username
e
s 00004/00001/00362
d D 4.10 81/06/12 13:24:07 root 10 9
c I supressed the sending of messages to sleeper.
e
s 00001/00001/00362
d D 4.9 81/06/11 16:40:08 wnj 9 8
c !cc
e
s 00026/00009/00337
d D 4.8 81/06/11 16:35:19 wnj 8 7
c fixes per kre
e
s 00001/00001/00345
d D 4.7 81/05/11 03:29:27 root 7 6
c new sccs line
e
s 00003/00008/00343
d D 4.6 81/05/10 16:08:06 root 6 5
c no -y flag; geteuid() must be root
e
s 00010/00001/00341
d D 4.5 81/05/04 11:15:05 toy 5 4
c Added -y flag.
e
s 00002/00000/00340
d D 4.4 81/04/21 02:16:14 root 4 3
c added error check in log_entry()
e
s 00023/00015/00317
d D 4.3 81/04/03 13:02:17 root 3 2
c write log entries
e
s 00048/00007/00284
d D 4.2 81/02/28 22:42:22 wnj 2 1
c changed but still crufty
e
s 00291/00000/00000
d D 4.1 81/02/07 22:23:07 wnj 1 0
c date and time created 81/02/07 22:23:07 by wnj
e
u
U
t
T
I 21
/*
D 26
 * Copyright (c) 1983 Regents of the University of California.
E 26
I 26
 * Copyright (c) 1983,1986 Regents of the University of California.
E 26
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 21
I 17
#ifndef lint
E 17
I 1
D 7
/*	%W% (Berkeley/Melbourne) %E%	*/
E 7
I 7
D 21
static	char *sccsid = "%W% (Berkeley) %E%";
I 17
#endif
E 21
I 21
char copyright[] =
D 26
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 26
I 26
"%Z% Copyright (c) 1983,1986 Regents of the University of California.\n\
E 26
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 21
E 17
E 7

#include <stdio.h>
#include <ctype.h>
#include <signal.h>
I 20
#include <setjmp.h>
E 20
#include <utmp.h>
I 26
#include <pwd.h>
E 26
D 18
#include <time.h>
E 18
I 18
#include <sys/time.h>
#include <sys/resource.h>
E 18
D 26
#include <sys/types.h>
E 26
I 26
#include <sys/param.h>
E 26
I 24
#include <sys/syslog.h>

E 24
I 11
D 12
#include <whoami.h>
E 12
E 11
/*
 *	/etc/shutdown when [messages]
 *
 *	allow super users to tell users and remind users
 *	of iminent shutdown of unix
 *	and shut it down automatically
 *	and even reboot or halt the machine if they desire
D 15
 *
 *		Ian Johnstone, Sydney, 1977
 *		Robert Elz, Melbourne, 1978
 *		Peter Lamb, Melbourne, 1980
 *		William Joy, Berkeley, 1981
I 2
 *		Michael Toy, Berkeley, 1981
I 10
 *		Dave Presotto, Berkeley, 1981
E 15
E 10
E 2
 */
I 2
D 24
#ifdef DEBUG
#define LOGFILE "shutdown.log"
#else
#define LOGFILE "/usr/adm/shutdownlog"
#endif
E 24
I 24

E 24
E 2
#define	REBOOT	"/etc/reboot"
#define	HALT	"/etc/halt"
#define MAXINTS 20
#define	HOURS	*3600
#define MINUTES	*60
#define SECONDS
D 8
#define NLOG		20		/* no of lines possible for message */
E 8
I 8
D 24
#define NLOG		20		/* no of args possible for message */
E 24
I 24
#define NLOG		600		/* no of bytes possible for message */
E 24
E 8
#define	NOLOGTIME	5 MINUTES
I 10
#define IGNOREUSER	"sleeper"
E 10

I 12
D 26
char	hostname[32];
E 26
I 26
char	hostname[MAXHOSTNAMELEN];
E 26

E 12
D 20
int	do_nothing();
E 20
I 20
int	timeout();
E 20
time_t	getsdt();
I 27
void	finish();
E 27

extern	char *ctime();
extern	struct tm *localtime();
I 23
extern	long time();
E 23

I 23
extern	char *strcpy();
extern	char *strncat();
extern	off_t lseek();

E 23
struct	utmp utmp;
int	sint;
int	stogo;
char	tpath[] =	"/dev/";
int	nlflag = 1;		/* nolog yet to be done */
int	killflg = 1;
D 23
int	reboot = 0;
E 23
I 23
int	doreboot = 0;
E 23
I 5
D 6
int	noroot = 0;
E 6
E 5
int	halt = 0;
I 22
int     fast = 0;
char    *nosync = NULL;
char    nosyncflag[] = "-n";
E 22
char	term[sizeof tpath + sizeof utmp.ut_line];
char	tbuf[BUFSIZ];
char	nolog1[] = "\n\nNO LOGINS: System going down at %5.5s\n\n";
D 24
char	*nolog2[NLOG+1];
E 24
I 24
char	nolog2[NLOG+1];
E 24
#ifdef	DEBUG
char	nologin[] = "nologin";
I 22
char    fastboot[] = "fastboot";
E 22
#else
char	nologin[] = "/etc/nologin";
I 22
char	fastboot[] = "/fastboot";
E 22
#endif
D 14
int slots;
E 14
I 14
time_t	nowtime;
I 20
jmp_buf	alarmbuf;
E 20

E 14
struct interval {
	int stogo;
	int sint;
} interval[] = {
	4 HOURS,	1 HOURS,
	2 HOURS,	30 MINUTES,
	1 HOURS,	15 MINUTES,
	30 MINUTES,	10 MINUTES,
	15 MINUTES,	5 MINUTES,
D 2
	10 MINUTES,	2 MINUTES,
E 2
I 2
	10 MINUTES,	5 MINUTES,
	5 MINUTES,	3 MINUTES,
E 2
D 14
	2 MINUTES,	30 SECONDS,
I 8
	40 SECONDS,	10 SECONDS,
E 14
I 14
	2 MINUTES,	1 MINUTES,
	1 MINUTES,	30 SECONDS,
E 14
E 8
	0 SECONDS,	0 SECONDS
};
I 14

E 14
I 2
char *shutter, *getlogin();
I 14

E 14
E 2
main(argc,argv)
	int argc;
	char **argv;
{
	register i, ufd;
D 24
	register char **mess, *f;
E 24
I 24
	register char *f;
E 24
	char *ts;
D 14
	long sdt;
E 14
I 14
	time_t sdt;
E 14
	int h, m;
D 14
	long nowtime;
E 14
I 14
	int first;
E 14
	FILE *termf;
I 26
	struct passwd *pw, *getpwuid();
E 26
I 25
	extern char *strcat();
	extern uid_t geteuid();
E 25

I 2
	shutter = getlogin();
I 26
	if (shutter == 0 && (pw = getpwuid(getuid())))
		shutter = pw->pw_name;
E 26
I 24
	if (shutter == 0)
		shutter = "???";
E 24
I 12
D 23
	gethostname(hostname, sizeof (hostname));
E 23
I 23
	(void) gethostname(hostname, sizeof (hostname));
I 24
	openlog("shutdown", 0, LOG_AUTH);
E 24
E 23
E 12
E 2
	argc--, argv++;
	while (argc > 0 && (f = argv[0], *f++ == '-')) {
		while (i = *f++) switch (i) {
		case 'k':
			killflg = 0;
			continue;
I 22
		case 'n':
			nosync = nosyncflag;
			continue;
		case 'f':
			fast = 1;
			continue;
E 22
		case 'r':
D 23
			reboot = 1;
E 23
I 23
			doreboot = 1;
E 23
			continue;
		case 'h':
			halt = 1;
			continue;
I 5
D 6
		case 'y':
			noroot = 1;
			continue;
E 6
E 5
		default:
			fprintf(stderr, "shutdown: '%c' - unknown flag\n", i);
			exit(1);
		}
		argc--, argv++;
	}
	if (argc < 1) {
D 5
		printf("Usage: %s [-krd] shutdowntime [nologmessage]\n",
E 5
I 5
D 6
		printf("Usage: %s [-krdy] shutdowntime [nologmessage]\n",
E 6
I 6
D 8
		printf("Usage: %s [ -krd ] shutdowntime [ message ]\n",
E 8
I 8
D 22
		printf("Usage: %s [ -krh ] shutdowntime [ message ]\n",
E 8
E 6
E 5
		    argv[0]);
E 22
I 22
	        /* argv[0] is not available after the argument handling. */
		printf("Usage: shutdown [ -krhfn ] shutdowntime [ message ]\n");
E 22
I 5
		finish();
	}
I 22
	if (fast && (nosync == nosyncflag)) {
	        printf ("shutdown: Incompatible switches 'fast' & 'nosync'\n");
		finish();
	}
E 22
D 6
	if (noroot == 0 && geteuid() != 0)
	{
		printf("Must specify -y flag to run as normal user.\n");
E 6
I 6
	if (geteuid()) {
		fprintf(stderr, "NOT super-user\n");
E 6
E 5
		finish();
	}
I 14
D 23
	nowtime = time((time_t *)0);
E 23
I 23
	nowtime = time((long *)0);
E 23
E 14
	sdt = getsdt(argv[0]);
	argc--, argv++;
D 24
	i = 0;
	while (argc-- > 0)
		if (i < NLOG)
			nolog2[i++] = *argv++;
	nolog2[i] = NULL;
E 24
I 24
	nolog2[0] = '\0';
	while (argc-- > 0) {
D 25
		strcat(nolog2, " ");
		strcat(nolog2, *argv++);
E 25
I 25
		(void) strcat(nolog2, " ");
		(void) strcat(nolog2, *argv++);
E 25
	}
E 24
D 14
	nowtime = time((long *)0);
E 14
	m = ((stogo = sdt - nowtime) + 30)/60;
	h = m/60; 
	m %= 60;
	ts = ctime(&sdt);
D 2
	printf("Shutdown at %5.5s\n", ts+11);
	printf("ie. in ");
E 2
I 2
	printf("Shutdown at %5.5s (in ", ts+11);
E 2
	if (h > 0)
		printf("%d hour%s ", h, h != 1 ? "s" : "");
D 2
	printf("%d minute%s\n", m, m != 1 ? "s" : "");
E 2
I 2
	printf("%d minute%s) ", m, m != 1 ? "s" : "");
E 2
#ifndef DEBUG
D 23
	signal(SIGHUP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
E 23
I 23
	(void) signal(SIGHUP, SIG_IGN);
	(void) signal(SIGQUIT, SIG_IGN);
	(void) signal(SIGINT, SIG_IGN);
E 23
#endif
I 16
D 23
	signal(SIGTTOU, SIG_IGN);
E 16
	signal(SIGTERM, finish);
D 20
	signal(SIGALRM, do_nothing);
E 20
I 20
	signal(SIGALRM, timeout);
E 20
D 18
	nice(-20);
E 18
I 18
	setpriority(PRIO_PROCESS, 0, PRIO_MIN);
E 18
I 8
	fflush(stdout);
E 23
I 23
	(void) signal(SIGTTOU, SIG_IGN);
	(void) signal(SIGTERM, finish);
	(void) signal(SIGALRM, timeout);
	(void) setpriority(PRIO_PROCESS, 0, PRIO_MIN);
	(void) fflush(stdout);
E 23
E 8
I 2
#ifndef DEBUG
E 2
	if (i = fork()) {
D 2
		printf("%d\n", i);
E 2
I 2
		printf("[pid %d]\n", i);
E 2
		exit(0);
	}
I 14
#else
D 23
	putc('\n', stdout);
E 23
I 23
	(void) putc('\n', stdout);
E 23
E 14
I 2
#endif
E 2
	sint = 1 HOURS;
	f = "";
I 14
	ufd = open("/etc/utmp",0);
	if (ufd < 0) {
		perror("shutdown: /etc/utmp");
		exit(1);
	}
	first = 1;
E 14
	for (;;) {
		for (i = 0; stogo <= interval[i].stogo && interval[i].sint; i++)
			sint = interval[i].sint;
I 14
		if (stogo > 0 && (stogo-sint) < interval[i].stogo)
			sint = stogo - interval[i].stogo;
E 14
		if (stogo <= NOLOGTIME && nlflag) {
			nlflag = 0;
			nolog(sdt);
		}
		if (sint >= stogo || sint == 0)
			f = "FINAL ";
D 14
		ufd = open("/etc/utmp",0);
		nowtime = time((long *) 0);
E 14
I 14
D 23
		nowtime = time((time_t *) 0);
		lseek(ufd, 0L, 0);
E 14
		while (read(ufd,&utmp,sizeof utmp)==sizeof utmp)
E 23
I 23
		nowtime = time((long *)0);
		(void) lseek(ufd, 0L, 0);
		while (read(ufd,(char *)&utmp,sizeof utmp)==sizeof utmp)
E 23
D 10
		if (utmp.ut_name[0]) {
E 10
I 10
		if (utmp.ut_name[0] &&
		    strncmp(utmp.ut_name, IGNOREUSER, sizeof(utmp.ut_name))) {
I 20
			if (setjmp(alarmbuf))
				continue;
E 20
E 10
D 23
			strcpy(term, tpath);
			strncat(term, utmp.ut_line, sizeof utmp.ut_line);
			alarm(3);
E 23
I 23
			(void) strcpy(term, tpath);
			(void) strncat(term, utmp.ut_line, sizeof utmp.ut_line);
			(void) alarm(3);
E 23
#ifdef DEBUG
D 2
			if ((termf = fopen("/dev/tty", "w")) != NULL)
E 2
I 2
			if ((termf = stdout) != NULL)
E 2
#else
			if ((termf = fopen(term, "w")) != NULL)
#endif
			{
D 23
				alarm(0);
E 23
I 23
				(void) alarm(0);
E 23
				setbuf(termf, tbuf);
D 14
				fprintf(termf, "\n\n");
				warn(termf, sdt, nowtime);
				if (sdt - nowtime > 1 MINUTES)
E 14
I 14
				fprintf(termf, "\n\r\n");
				warn(termf, sdt, nowtime, f);
				if (first || sdt - nowtime > 1 MINUTES) {
					if (*nolog2)
D 24
						fprintf(termf, "\t...");
E 14
					for (mess = nolog2; *mess; mess++)
D 14
						fprintf(termf, "%s ", *mess);
E 14
I 14
						fprintf(termf, " %s", *mess);
E 24
I 24
						fprintf(termf, "\t...%s", nolog2);
E 24
				}
D 23
				fputc('\r', termf);
E 14
				fputc('\n', termf);
I 2
				alarm(5);
E 23
I 23
				(void) fputc('\r', termf);
				(void) fputc('\n', termf);
				(void) alarm(5);
E 23
#ifdef DEBUG
D 23
				fflush(termf);
E 23
I 23
				(void) fflush(termf);
E 23
#else
E 2
D 23
				fclose(termf);
E 23
I 23
				(void) fclose(termf);
E 23
I 2
#endif
E 2
D 23
				alarm(0);
E 23
I 23
				(void) alarm(0);
E 23
			}
		}
D 14
		if (stogo < 0) {
E 14
I 14
		if (stogo <= 0) {
E 14
D 24
	printf("\n\007\007System shutdown time has arrived\007\007\n");
I 2
			log_entry(sdt);
E 24
I 24
			printf("\n\007\007System shutdown time has arrived\007\007\n");
D 26
			syslog(LOG_CRIT, "%s!%s: %s", hostname, shutter, nolog2);
E 26
I 26
			syslog(LOG_CRIT, "%s by %s: %s",
			    doreboot ? "reboot" : halt ? "halt" : "shutdown",
			    shutter, nolog2);
			sleep(2);
E 26
E 24
E 2
D 23
			unlink(nologin);
E 23
I 23
			(void) unlink(nologin);
E 23
			if (!killflg) {
				printf("but you'll have to do it yourself\n");
				finish();
			}
I 22
			if (fast)
				doitfast();
E 22
#ifndef DEBUG
I 14
D 23
			kill(-1, SIGTERM);	/* terminate everyone */
E 23
I 23
D 26
			(void) kill(-1, SIGTERM);	/* terminate everyone */
E 23
			sleep(5);		/* & wait while they die */
E 26
E 14
D 23
			if (reboot)
E 23
I 23
			if (doreboot)
E 23
D 22
				execle(REBOOT, "reboot", 0, 0);
E 22
I 22
D 26
				execle(REBOOT, "reboot", nosync, 0, 0);
E 26
I 26
				execle(REBOOT, "reboot", "-l", nosync, 0, 0);
E 26
E 22
			if (halt)
D 22
				execle(HALT, "halt", 0, 0);
E 22
I 22
D 26
				execle(HALT, "halt", nosync, 0, 0);
E 22
D 23
			kill(1, SIGTERM);	/* sync */
			kill(1, SIGTERM);	/* sync */
E 23
I 23
			(void) kill(1, SIGTERM);	/* sync */
			(void) kill(1, SIGTERM);	/* sync */
E 23
			sleep(20);
E 26
I 26
				execle(HALT, "halt", "-l", nosync, 0, 0);
			(void) kill(1, SIGTERM);	/* to single user */
E 26
#else
D 26
			printf("EXTERMINATE EXTERMINATE\n");
E 26
I 22
D 23
			if (reboot)
E 23
I 23
			if (doreboot)
E 23
				printf("REBOOT");
			if (halt)
				printf(" HALT");
			if (fast)
D 26
				printf(" %s (without fsck's)\n", nosync);
E 26
I 26
				printf(" -l %s (without fsck's)\n", nosync);
E 26
			else
D 26
				printf(" %s\n", nosync);
E 26
I 26
				printf(" -l %s\n", nosync);
			else
				printf("kill -HUP 1\n");
E 26

E 22
#endif
			finish();
		}
D 14
		stogo = sdt - time((long *) 0);
		if (stogo > 0)
E 14
I 14
D 23
		stogo = sdt - time((time_t *) 0);
E 23
I 23
		stogo = sdt - time((long *) 0);
E 23
		if (stogo > 0 && sint > 0)
E 14
D 23
			sleep(sint<stogo ? sint : stogo);
E 23
I 23
			sleep((unsigned)(sint<stogo ? sint : stogo));
E 23
		stogo -= sint;
I 14
		first = 0;
E 14
	}
}

time_t
getsdt(s)
D 14
register char *s;
E 14
I 14
	register char *s;
E 14
{
	time_t t, t1, tim;
	register char c;
	struct tm *lt;

I 14
	if (strcmp(s, "now") == 0)
		return(nowtime);
E 14
	if (*s == '+') {
		++s; 
		t = 0;
		for (;;) {
			c = *s++;
			if (!isdigit(c))
				break;
			t = t * 10 + c - '0';
		}
		if (t <= 0)
			t = 5;
		t *= 60;
D 14
		tim = time((long *) 0) + t;
E 14
I 14
D 23
		tim = time((time_t *) 0) + t;
E 23
I 23
		tim = time((long *) 0) + t;
E 23
E 14
		return(tim);
	}
	t = 0;
	while (strlen(s) > 2 && isdigit(*s))
		t = t * 10 + *s++ - '0';
	if (*s == ':')
		s++;
	if (t > 23)
		goto badform;
	tim = t*60;
	t = 0;
	while (isdigit(*s))
		t = t * 10 + *s++ - '0';
	if (t > 59)
		goto badform;
	tim += t; 
	tim *= 60;
D 14
	t1 = time((long *) 0);
E 14
I 14
D 23
	t1 = time((time_t *) 0);
E 23
I 23
	t1 = time((long *) 0);
E 23
E 14
	lt = localtime(&t1);
	t = lt->tm_sec + lt->tm_min*60 + lt->tm_hour*3600;
	if (tim < t || tim >= (24*3600)) {
		/* before now or after midnight */
		printf("That must be tomorrow\nCan't you wait till then?\n");
		finish();
	}
D 14
	return (t1 + tim -t);
E 14
I 14
	return (t1 + tim - t);
E 14
badform:
	printf("Bad time format\n");
	finish();
I 23
	/*NOTREACHED*/
E 23
}

D 14
warn(term, sdt, nowtime)
E 14
I 14
warn(term, sdt, now, type)
E 14
	FILE *term;
D 14
	long sdt, nowtime;
E 14
I 14
	time_t sdt, now;
	char *type;
E 14
{
	char *ts;
I 8
D 9
	register delay = std - nowtime;
E 9
I 9
D 14
	register delay = sdt - nowtime;
E 14
I 14
	register delay = sdt - now;
E 14
E 9
E 8

I 2
D 8
	fprintf(term, "\007\007*** System shutdown message from %s ***\n", shutter);
E 8
I 8
	if (delay > 8)
		while (delay % 5)
			delay++;

D 24
	if (shutter)
		fprintf(term,
E 24
I 24
	fprintf(term,
E 24
D 11
		    "\007\007*** System shutdown message from %s ***\n",
		    shutter);
E 11
I 11
D 14
		    "\007\007*** System shutdown message from %s!%s ***\n",
D 13
		    sysname,shutter);
E 13
I 13
		    hostname,shutter);
E 14
I 14
D 19
	    "\007\007\t*** %sSystem shutdown message from %s!%s ***\r\n\n",
		    type, hostname, shutter);
E 19
I 19
	    "\007\007\t*** %sSystem shutdown message from %s@%s ***\r\n\n",
		    type, shutter, hostname);
E 19
E 14
E 13
E 11
D 24
	else
		fprintf(term,
D 14
		    "\007\007*** System shutdown message ***\n");
E 14
I 14
		    "\007\007\t*** %sSystem shutdown message (%s) ***\r\n\n",
		    type, hostname);
E 24

E 14
E 8
E 2
	ts = ctime(&sdt);
D 8
	if (sdt - nowtime > 10 MINUTES)
E 8
I 8
D 14
	if (delay> 10 MINUTES)
E 8
		fprintf(term, "System going down at %5.5s\n", ts+11);
D 8
	else if ( sdt - nowtime > 60 SECONDS ) {
E 8
I 8
	else if ( delay > 60 SECONDS ) {
E 8
		fprintf(term, "System going down in %d minute%s\n",
D 8
		(sdt-nowtime+30)/60, (sdt-nowtime+30)/60 != 1 ? "s" : "");
	} else if ( sdt - nowtime > 0 ) {
E 8
I 8
		(delay+30)/60, (delay+30)/60 != 1 ? "s" : "");
	} else if ( delay > 0 ) {
E 8
D 2
		fprintf(term, "System going down in %d seconds\n",
E 2
I 2
		fprintf(term, "System going down in %d second%s\n",
E 2
D 8
		sdt-nowtime, sdt-nowtime != 1 ? "s" : "");
E 8
I 8
		delay, delay != 1 ? "s" : "");
E 14
I 14
	if (delay > 10 MINUTES)
		fprintf(term, "System going down at %5.5s\r\n", ts+11);
	else if (delay > 95 SECONDS) {
		fprintf(term, "System going down in %d minute%s\r\n",
		    (delay+30)/60, (delay+30)/60 != 1 ? "s" : "");
	} else if (delay > 0) {
		fprintf(term, "System going down in %d second%s\r\n",
		    delay, delay != 1 ? "s" : "");
E 14
E 8
	} else
D 14
		fprintf(term, "System going down IMMEDIATELY\n");
E 14
I 14
		fprintf(term, "System going down IMMEDIATELY\r\n");
I 22
}

doitfast()
{
	FILE *fastd;

	if ((fastd = fopen(fastboot, "w")) != NULL) {
		putc('\n', fastd);
D 23
		fclose(fastd);
E 23
I 23
		(void) fclose(fastd);
E 23
	}
E 22
E 14
}

nolog(sdt)
D 14
	long sdt;
E 14
I 14
	time_t sdt;
E 14
{
	FILE *nologf;
D 24
	register char **mess;
E 24

I 14
D 23
	unlink(nologin);			/* in case linked to std file */
E 23
I 23
	(void) unlink(nologin);			/* in case linked to std file */
E 23
E 14
	if ((nologf = fopen(nologin, "w")) != NULL) {
		fprintf(nologf, nolog1, (ctime(&sdt)) + 11);
I 8
D 23
		putc('\t', nologf);
E 23
I 23
D 24
		(void) putc('\t', nologf);
E 23
E 8
		for (mess = nolog2; *mess; mess++)
D 8
			fprintf(nologf, "\t%s\n", *mess);
E 8
I 8
			fprintf(nologf, " %s", *mess);
D 23
		putc('\n', nologf);
E 8
		fclose(nologf);
E 23
I 23
		(void) putc('\n', nologf);
E 24
I 24
		if (*nolog2)
			fprintf(nologf, "\t%s\n", nolog2 + 1);
E 24
		(void) fclose(nologf);
E 23
	}
}

I 27
void
E 27
finish()
{
D 23
	signal(SIGTERM, SIG_IGN);
	unlink(nologin);
E 23
I 23
	(void) signal(SIGTERM, SIG_IGN);
	(void) unlink(nologin);
E 23
	exit(0);
}

D 20
do_nothing()
E 20
I 20
timeout()
E 20
{
D 20

	signal(SIGALRM, do_nothing);
E 20
I 20
	longjmp(alarmbuf, 1);
E 20
I 2
D 24
}

/*
 * make an entry in the shutdown log
 */

D 3
log_entry(sdt)
time_t sdt;
E 3
I 3
char *days[] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

char *months[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
	"Oct", "Nov", "Dec"
};

log_entry(now)
D 14
time_t now;
E 14
I 14
	time_t now;
E 14
E 3
{
D 3
	FILE *logf;
	char **mess;
E 3
I 3
	register FILE *fp;
	register char **mess;
	struct tm *tm, *localtime();
E 3

D 3
	if ((logf = fopen(LOGFILE, "a")) == NULL)
	{
		fprintf(stderr, "*** Can't write on log file ***\n");
		return;
	}
	fseek(logf, 0L, 2);
	fprintf(logf, "Shutdown by %s at %s",
			shutter, ctime(&sdt));
E 3
I 3
	tm = localtime(&now);
	fp = fopen(LOGFILE, "a");
I 4
D 14
	if (fp==0)
E 14
I 14
	if (fp == NULL) {
		printf("Shutdown: log entry failed\n");
E 14
		return;
I 14
	}
E 14
E 4
D 23
	fseek(fp, 0L, 2);
E 23
I 23
	(void) fseek(fp, 0L, 2);
E 23
	fprintf(fp, "%02d:%02d  %s %s %2d, %4d.  Shutdown:", tm->tm_hour,
		tm->tm_min, days[tm->tm_wday], months[tm->tm_mon],
		tm->tm_mday, tm->tm_year + 1900);
E 3
	for (mess = nolog2; *mess; mess++)
D 3
		fprintf(logf, "\t%s\n", *mess);
	fputc('\n', logf);
	fclose(logf);
E 3
I 3
		fprintf(fp, " %s", *mess);
I 8
	if (shutter)
D 11
		fprintf(fp, " (by %s)", shutter);
E 11
I 11
D 13
		fprintf(fp, " (by %s!%s)", sysname,shutter);
E 13
I 13
D 14
		fprintf(fp, " (by %s!%s)", hostname,shutter);
E 14
I 14
		fprintf(fp, " (by %s!%s)", hostname, shutter);
E 14
E 13
E 11
E 8
D 23
	fputc('\n', fp);
	fclose(fp);
E 23
I 23
	(void) fputc('\n', fp);
	(void) fclose(fp);
E 24
E 23
E 3
E 2
}
E 1
