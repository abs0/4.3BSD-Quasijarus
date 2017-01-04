h64238
s 00014/00007/00124
d D 5.4 86/05/26 22:12:21 karels 12 11
c consistency, use SIGTERM once then SIGKILL's, uniform logging (once)
e
s 00018/00011/00113
d D 5.3 86/05/24 22:46:26 karels 11 10
c log username, log before kill, give init a sec to TSTP
e
s 00003/00030/00121
d D 5.2 86/05/12 18:30:14 eric 10 9
c eliminate shutdownlog in favor of syslog
e
s 00014/00002/00137
d D 5.1 85/05/28 15:05:07 dist 9 8
c Add copyright
e
s 00001/00001/00138
d D 4.8 83/07/02 00:18:56 sam 8 7
c include fixes
e
s 00004/00000/00135
d D 4.7 83/05/22 23:57:36 sam 7 6
c utmp changed format
e
s 00001/00000/00134
d D 4.6 83/02/09 14:59:26 sam 6 5
c allow reboots across the net
e
s 00002/00000/00132
d D 4.5 81/04/21 02:07:16 root 5 4
c add check for failure to fopen shutdownlog
e
s 00002/00000/00130
d D 4.4 81/04/02 23:17:58 root 4 3
c Fixed previous
e
s 00029/00000/00101
d D 4.3 81/04/02 23:15:50 root 3 2
c Added logging
e
s 00076/00008/00025
d D 4.2 81/02/28 23:00:30 wnj 2 1
c new reboot scheme
e
s 00033/00000/00000
d D 4.1 80/10/10 00:45:10 bill 1 0
c date and time created 80/10/10 00:45:10 by bill
e
u
U
t
T
I 9
/*
D 11
 * Copyright (c) 1980 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1980,1986 Regents of the University of California.
E 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 9
I 7
#ifndef lint
E 7
I 1
D 2
#include <stdio.h>
#include <sys/reboot.h>
E 2
I 2
D 9
static	char *sccsid = "%W% (Berkeley) %G%";
I 7
#endif
E 9
I 9
char copyright[] =
D 12
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 12
I 12
"%Z% Copyright (c) 1980,1986 Regents of the University of California.\n\
E 12
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9

E 7
E 2
/*
 * Reboot
 */
D 2
static	char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
#include <stdio.h>
#include <sys/reboot.h>
#include <errno.h>
#include <signal.h>
I 11
#include <pwd.h>
E 11
I 3
#include <sys/types.h>
D 8
#include <time.h>
E 8
I 8
#include <sys/time.h>
I 10
D 11
#include <syslog.h>
E 11
I 11
#include <sys/syslog.h>
E 11
E 10
E 8
E 3
E 2

I 3
D 10
#define SHUTDOWNLOG "/usr/adm/shutdownlog"

E 10
E 3
main(argc, argv)
	int argc;
	char **argv;
{
	int howto;
	register char *argp;
I 2
	register i;
	register ok = 0;
	register qflag = 0;
I 12
	int needlog = 1;
E 12
I 11
	char *user, *getlogin();
	struct passwd *pw, *getpwuid();
E 11
E 2

I 10
	openlog("reboot", 0, LOG_AUTH);
E 10
	argc--, argv++;
	howto = 0;
	while (argc > 0) {
D 2
		if (!strcmp(*argv, "-s"))
			howto |= RB_SINGLE;
E 2
I 2
		if (!strcmp(*argv, "-q"))
			qflag++;
E 2
		else if (!strcmp(*argv, "-n"))
			howto |= RB_NOSYNC;
I 12
		else if (!strcmp(*argv, "-l"))
			needlog = 0;
E 12
D 2
		else if (!strcmp(*argv, "-a"))
			howto |= RB_ASKNAME;
E 2
		else {
			fprintf(stderr,
D 2
			    "usage: reboot [ -a ] [ -n ] [ -s ]\n");
E 2
I 2
			    "usage: reboot [ -n ][ -q ]\n");
E 2
			exit(1);
		}
		argc--, argv++;
	}
I 2

I 11
D 12
	user = getlogin();
	if (user == (char *)0 && (pw = getpwuid(getuid())))
		user = pw->pw_name;
	if (user == (char *)0)
		user = "root";
	syslog(LOG_CRIT, "halted by %s", user);
E 12
I 12
	if (needlog) {
		user = getlogin();
		if (user == (char *)0 && (pw = getpwuid(getuid())))
			user = pw->pw_name;
		if (user == (char *)0)
			user = "root";
		syslog(LOG_CRIT, "rebooted by %s", user);
	}
E 12

E 11
I 6
	signal(SIGHUP, SIG_IGN);	/* for remote connections */
E 6
	if (kill(1, SIGTSTP) == -1) {
		fprintf(stderr, "reboot: can't idle init\n");
		exit(1);
	}
I 11
	sleep(1);
I 12
	(void) kill(-1, SIGTERM);	/* one chance to catch it */
	sleep(5);
E 12
E 11

	if (!qflag) for (i = 1; ; i++) {
		if (kill(-1, SIGKILL) == -1) {
			extern int errno;

			if (errno == ESRCH)
				break;

			perror("reboot: kill");
			kill(1, SIGHUP);
			exit(1);
		}
		if (i > 5) {
D 11
	fprintf(stderr, "CAUTION: some process(es) wouldn't die\n");
E 11
I 11
			fprintf(stderr,
			    "CAUTION: some process(es) wouldn't die\n");
E 11
			break;
		}
		setalarm(2 * i);
		pause();
	}

I 4
D 11
	if ((howto & RB_NOSYNC) == 0)
D 10
		log_entry();
E 10
I 10
		syslog(LOG_CRIT, "halted for reboot");
E 10
E 4
	if (!qflag) {
		if (!(howto & RB_NOSYNC)) {
			markdown();
			sync();
			sync();
		}
E 11
I 11
	if (!qflag && (howto & RB_NOSYNC) == 0) {
		markdown();
		sync();
E 11
		setalarm(5);
		pause();
	}
E 2
	syscall(55, howto);
	perror("reboot");
I 2
	kill(1, SIGHUP);
	exit(1);
}

dingdong()
{
	/* RRRIIINNNGGG RRRIIINNNGGG */
}

setalarm(n)
{
	signal(SIGALRM, dingdong);
	alarm(n);
}

#include <utmp.h>
#define SCPYN(a, b)	strncpy(a, b, sizeof(a))
char	wtmpf[]	= "/usr/adm/wtmp";
struct utmp wtmp;

markdown()
{
	register f = open(wtmpf, 1);
	if (f >= 0) {
		lseek(f, 0L, 2);
		SCPYN(wtmp.ut_line, "~");
		SCPYN(wtmp.ut_name, "shutdown");
I 7
		SCPYN(wtmp.ut_host, "");
E 7
		time(&wtmp.ut_time);
		write(f, (char *)&wtmp, sizeof(wtmp));
		close(f);
	}
I 3
D 10
}

char *days[] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

char *months[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
	"Oct", "Nov", "Dec"
};

log_entry()
{
	FILE *fp;
	struct tm *tm, *localtime();
	time_t now;

	time(&now);
	tm = localtime(&now);
	fp = fopen(SHUTDOWNLOG, "a");
I 5
	if (fp == 0)
		return;
E 5
	fseek(fp, 0L, 2);
	fprintf(fp, "%02d:%02d  %s %s %2d, %4d.  Halted for reboot.\n", tm->tm_hour,
		tm->tm_min, days[tm->tm_wday], months[tm->tm_mon],
		tm->tm_mday, tm->tm_year + 1900);
	fclose(fp);
E 10
E 3
E 2
}
E 1
