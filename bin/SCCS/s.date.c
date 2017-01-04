h12119
s 00008/00002/00371
d D 4.23 99/12/14 20:31:32 msokolov 26 25
c Y2K
e
s 00001/00001/00372
d D 4.22 87/04/06 12:21:07 bostic 25 24
c new time package, general cleanup
e
s 00018/00018/00355
d D 4.21 87/04/06 12:19:43 bostic 24 23
c new time package, cleanup
e
s 00165/00144/00208
d D 4.20 87/03/24 08:48:32 bostic 23 22
c new time package, general cleanup
e
s 00010/00022/00342
d D 4.19 86/05/18 21:43:21 lepreau 22 21
c lint
e
s 00013/00005/00351
d D 4.18 86/05/18 01:18:42 lepreau 21 20
c reqork exit codes: 0 = success, 1 = failure, 2 = failed to set remote.
c errors got to stderr
e
s 00001/00002/00355
d D 4.17 86/04/29 19:46:54 bloom 20 19
c use absolute instead of relative time for setting network date
e
s 00019/00005/00338
d D 4.16 86/04/13 21:28:42 karels 19 17
c add -n to avoid setting network time
e
s 00007/00002/00341
d R 4.16 86/04/13 21:07:58 karels 18 17
c add -n to avoid timed
e
s 00141/00142/00202
d D 4.15 86/02/17 01:22:06 karels 17 16
c cleanups from sam; connect in order to be able to get async. errors;
c check for ECONNREFUSED later
e
s 00001/00001/00343
d D 4.14 85/11/01 16:57:27 bloom 16 15
c fix syslog message
e
s 00012/00000/00332
d D 4.13 85/10/11 17:57:32 mckusick 15 14
c copyright
e
s 00002/00001/00330
d D 4.12 85/10/11 11:44:39 karels 14 13
c don't complain about not binding if network not turned on
e
s 00002/00001/00329
d D 4.11 85/09/17 23:59:11 eric 13 12
c facilities in syslog
e
s 00002/00003/00328
d D 4.10 85/06/26 11:08:43 bloom 12 11
c don't want date set wrong on errors
e
s 00057/00068/00274
d D 4.9 85/06/25 15:14:50 karels 11 10
c patch things up a bit
e
s 00001/00000/00341
d D 4.8 85/06/19 16:27:36 mckusick 10 9
c need to declare errno
e
s 00213/00033/00128
d D 4.7 85/06/17 21:26:00 gusella 9 6
c now works with timed
e
s 00213/00033/00128
d R 4.7 85/06/14 23:07:21 gusella 8 6
c now works with timed
e
s 00203/00025/00136
d R 4.7 85/06/14 17:01:31 gusella 7 6
c now works with timed
e
s 00001/00001/00160
d D 4.6 83/09/28 10:21:24 ralph 6 5
c wtmp[0] wasn't being set to previous time.
e
s 00001/00001/00160
d D 4.5 83/07/01 23:57:57 wnj 5 4
c include problems
e
s 00004/00001/00157
d D 4.4 83/05/23 00:02:44 sam 4 3
c utmp format changed
e
s 00035/00032/00123
d D 4.3 83/02/28 18:58:55 leres 3 2
c Changed to print out usage if new date is botched. Cleaned
c up a few things
e
s 00046/00058/00109
d D 4.2 83/02/26 18:17:02 sam 2 1
c almost lost changes
e
s 00167/00000/00000
d D 4.1 80/10/01 17:26:05 bill 1 0
c date and time created 80/10/01 17:26:05 by bill
e
u
U
t
T
I 15
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
D 17
"%Z% Copyright (c) 1985 Regents of the University of California.\n\
E 17
I 17
"@(#) Copyright (c) 1985 Regents of the University of California.\n\
E 17
 All rights reserved.\n";
#endif not lint

E 15
I 2
#ifndef lint
E 2
I 1
D 9
static char *sccsid = "%W% (Berkeley) %G%";
I 2
#endif
E 9
I 9
D 24
static char sccsid[] = "%W% (Berkeley) %G%";
E 24
I 24
D 25
static char sccsid[] = "@(#)date.c	4.20 (Berkeley) 3/24/87";
E 25
I 25
static char *sccsid = "%W% (Berkeley) %G%";
E 25
E 24
#endif not lint
E 9

E 2
D 3
#include <stdio.h>
E 3
/*
D 3
 * date : print date
 * date YYMMDDHHMM[.SS] : set date, if allowed
 * date -u ... : date in GMT
E 3
I 3
 * Date - print and set date
I 9
D 17
 * Modified by Riccardo Gusella to work with timed 
E 17
E 9
E 3
 */
I 3

I 9
D 11
#include <sys/types.h>
E 11
I 11
#include <sys/param.h>
E 11
E 9
D 23
#include <stdio.h>
E 23
E 3
D 5
#include <time.h>
E 5
I 5
#include <sys/time.h>
I 9
D 17
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define TSPTYPES
#include <protocols/timed.h>
E 17
#include <sys/file.h>
#include <errno.h>
#include <syslog.h>
E 9
E 5
D 2
#include <sys/types.h>
#include <sys/timeb.h>
E 2
#include <utmp.h>
I 23
#include <tzfile.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
E 23
I 9

E 9
I 3
D 17
#define WTMP "/usr/adm/wtmp"
I 11
D 12
#define	TRIES		3	/* attempts to contact time server */
E 12
#define WAITACK		2	/* seconds */
#define WAITDATEACK	5	/* seconds */
E 17
I 17
D 23
#define WTMP	"/usr/adm/wtmp"
E 23
I 23
#define	WTMP		"/usr/adm/wtmp"
#define	ATOI2(ar)	(ar[0] - '0') * 10 + (ar[1] - '0'); ar += 2;
E 23
E 17
E 11
E 3
D 2
long	timbuf;
E 2
I 2

D 9
struct	timeval tv;
E 9
I 9
D 23
struct	timeval tv, now;
E 9
struct	timezone tz;
E 2
char	*ap, *ep, *sp;
D 19
int	uflag;
E 19
I 19
int	uflag, nflag;
I 21
int	retval;
E 23
I 23
static struct timeval	tv;
static int	retval;
E 23
E 21
E 19

D 23
char	*timezone();
D 17
static	int	dmsize[12] =
E 17
I 17
static	int dmsize[12] =
E 17
D 2
{
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};
E 2
I 2
    { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
I 3
D 17
static char *usage = "usage: date [-u] [yymmddhhmm[.ss]]\n";
E 17
I 17
D 19
static	char *usage = "usage: date [-u] [yymmddhhmm[.ss]]\n";
E 19
I 19
static	char *usage = "usage: date [-n] [-u] [yymmddhhmm[.ss]]\n";
E 23
I 23
static int	dmsize[] =
	{ -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
E 23
E 19
E 17
E 3
E 2

D 4
struct utmp wtmp[2] = { {"|", "", 0}, {"{", "", 0}};
E 4
I 4
D 23
struct utmp wtmp[2] = {
E 23
I 23
static struct utmp	wtmp[2] = {
E 23
	{ "|", "", "", 0 },
	{ "{", "", "", 0 }
};
E 4

D 23
char	*ctime();
char	*asctime();
struct	tm *localtime();
struct	tm *gmtime();
I 17
D 22
char	*strcpy();
E 22
I 22
char	*strcpy(), *strncpy();
E 22
char	*username, *getlogin();
I 22
long	time();
uid_t	getuid();
E 22
E 17

I 9
D 17
char *strcpy();
char *username, *getlogin();

D 11
#define WAITACK		10	/* seconds */
#define WAITDATEACK	5	/* seconds */

E 11
int sock, length, port;
D 11
int ready, found;
char hostname[32];
E 11
I 11
char hostname[MAXHOSTNAMELEN];
E 11
struct timeval tout;
struct servent *srvp;
D 11
struct hostent *hp, *gethostbyname();
E 11
struct tsp msg;
struct sockaddr_in sin, dest, from;

E 17
E 9
main(argc, argv)
D 2
char *argv[];
E 2
I 2
	int argc;
	char *argv[];
E 23
I 23
main(argc,argv)
	int	argc;
	char	**argv;
E 23
E 2
{
I 9
D 17
	int wf;
D 11
	int timed_ack;
E 11
I 11
	int timed_ack, found;
	long waittime;
E 17
E 11
E 9
D 23
	register char *tzn;
E 23
I 23
	extern int	optind;
	extern char	*optarg;
D 24
	static char	usage[] = "usage: date [-n] [-u] [yymmddhhmm[.ss]]\n";
E 24
	struct timezone	tz;
	char	*ap,			/* time string */
		*tzn;			/* time zone */
	int	ch,			/* getopts char */
		uflag,			/* do it in GMT */
		nflag,			/* only set time locally */
		wf;			/* wtmp file descriptor */
	long	time();
	uid_t	getuid();
	char	*username, *getlogin();
E 23
I 11
D 17
	fd_set ready;
E 11
I 10
	extern int errno;
E 10
D 2
	struct timeb info;
E 2
D 9
	int wf, rc;
E 9
I 9
	int bytenetorder(), bytehostorder();
E 17
E 9
D 2
	extern char _sobuf[];
E 2

I 13
D 24
	openlog("date", LOG_ODELAY, LOG_AUTH);
E 13
D 2
	setbuf(stdout, _sobuf);
E 2
D 9
	rc = 0;
D 2
	ftime(&info);
E 2
I 2
	gettimeofday(&tv, &tz);
E 9
I 9
D 23
	(void) gettimeofday(&tv, &tz);
I 11
	now = tv;
E 23
E 11

E 24
E 9
E 2
D 3
	if (argc>1 && argv[1][0]=='-' && argv[1][1]=='u') {
E 3
I 3
D 19
	if (argc > 1 && strcmp(argv[1], "-u") == 0) {
E 19
I 19
D 23
	while (argc > 1 && argv[1][0] == '-') {
		while (*++argv[1])
		    switch ((int)argv[1][0]) {

		    case 'n':
			nflag++;
E 23
I 23
	nflag = uflag = 0;
D 24
	while ((ch = getopt(argc,argv,"nu")) != EOF)
E 24
I 24
	tz.tz_dsttime = tz.tz_minuteswest = 0;
	while ((ch = getopt(argc,argv,"d:nut:")) != EOF)
E 24
		switch((char)ch) {
		case 'd':
			tz.tz_dsttime = atoi(optarg) ? 1 : 0;
E 23
			break;
D 23

		    case 'u':
			uflag++;
E 23
I 23
		case 'n':
			nflag = 1;
E 23
			break;
D 23

		    default:
D 21
			printf(usage);
E 21
I 21
			fprintf(stderr, usage);
E 23
I 23
D 24
		case 't':
			tz.tz_minuteswest = atoi(optarg);
			break;
E 24
		case 'u':
			uflag = 1;
			break;
I 24
		case 't':	/* error check; we can't allow "PST" */
			if (isdigit(*optarg)) {
				tz.tz_minuteswest = atoi(optarg);
				break;
			}
			/*FALLTHROUGH*/
E 24
		default:
D 24
			fputs(usage,stderr);
E 24
I 24
			usage();
E 24
E 23
E 21
			exit(1);
		}
E 19
E 3
D 23
		argc--;
		argv++;
E 23
I 23
	argc -= optind;
	argv += optind;

	if (argc > 1) {
D 24
		fputs(usage,stderr);
E 24
I 24
		usage();
E 24
		exit(1);
E 23
D 19
		uflag++;
E 19
	}
D 2
	if(argc > 1) {
E 2
I 2
D 9
	if (argc > 1) {
E 2
		ap = argv[1];
I 6
		wtmp[0].ut_time = tv.tv_sec;
E 6
		if (gtime()) {
D 3
			printf("date: bad conversion\n");
E 3
I 3
			printf(usage);
E 9
I 9
D 23
	if (argc > 2) {
D 21
		printf(usage);
E 21
I 21
		fprintf(stderr, usage);
E 23
I 23

	if ((tz.tz_minuteswest || tz.tz_dsttime) &&
	    settimeofday((struct timeval *)NULL,&tz)) {
		perror("settimeofday");
		retval = 1;
		goto display;
	}

	if (gettimeofday(&tv,&tz)) {
		perror("gettimeofday");
E 23
E 21
		exit(1);
	}
D 23
	if (argc == 1) 
E 23
I 23

	if (!argc)
E 23
		goto display;

D 23
	if (getuid() != 0) {
D 21
		printf("You are not superuser: date not set\n");
E 21
I 21
		fprintf(stderr, "You are not superuser: date not set\n");
E 23
I 23
D 24
	if (getuid()) {
		fputs("You are not superuser: date not set.\n",stderr);
E 23
		retval = 1;
E 21
D 11
		exit(1);
E 11
I 11
		goto display;
E 11
	}
D 23
	username = getlogin();
D 11
	if (username == NULL) {
		printf("Cannot record your name: date not set\n");
		exit(1);
	}
	syslog(LOG_ERR, "date: set by %s", username);
E 11
I 11
D 21
	if (username == NULL)		/* single-user or no tty */
E 21
I 21
	if (username == NULL || *username == '\0')  /* single-user or no tty */
E 21
		username = "root";
E 23
D 13
	syslog(LOG_SECURITY, "date: set by %s", username);
E 13
I 13
D 16
	syslog(LOG_NOTICE, "date: set by %s", username);
E 16
I 16
D 17
	syslog(LOG_NOTICE, "set by %s", username);
E 17
E 16
E 13
E 11

E 24
D 23
	ap = argv[1];
E 23
	wtmp[0].ut_time = tv.tv_sec;
D 23
	if (gtime()) {
D 21
		printf(usage);
E 21
I 21
		fprintf(stderr, usage);
E 23
I 23
	if (gtime(*argv)) {
D 24
		fprintf(stderr,usage);
E 24
I 24
		usage();
E 24
E 23
		retval = 1;
E 21
D 11
		exit(1);
E 11
I 11
		goto display;
E 11
	}
D 23
	/* convert to GMT assuming local time */
	if (uflag == 0) {
		tv.tv_sec += (long)tz.tz_minuteswest*60;
		/* now fix up local daylight time */
E 23
I 23

	if (!uflag) {		/* convert to GMT assuming local time */
		tv.tv_sec += (long)tz.tz_minuteswest * SECS_PER_MIN;
				/* now fix up local daylight time */
E 23
D 11
		if (localtime((long *)&tv.tv_sec)->tm_isdst)
E 11
I 11
		if (localtime((time_t *)&tv.tv_sec)->tm_isdst)
E 11
D 23
			tv.tv_sec -= 60*60;
E 23
I 23
			tv.tv_sec -= SECS_PER_HOUR;
E 23
	}
D 11
	(void) open("/etc/timed", O_WRONLY, 01700);
	if (errno != ETXTBSY) {
		if (settimeofday(&tv, (struct timezone *)0) < 0) {
			perror("settimeofday");
E 9
E 3
			exit(1);
		}
D 9
		/* convert to GMT assuming local time */
D 3
		if (uflag==0) {
E 3
I 3
		if (uflag == 0) {
E 3
D 2
			timbuf += (long)info.timezone*60;
E 2
I 2
			tv.tv_sec += (long)tz.tz_minuteswest*60;
E 2
			/* now fix up local daylight time */
D 2
			if(localtime(&timbuf)->tm_isdst)
				timbuf -= 60*60;
E 2
I 2
			if (localtime(&tv.tv_sec)->tm_isdst)
				tv.tv_sec -= 60*60;
E 9
I 9
		if ((wf = open(WTMP, 1)) >= 0) {
			(void) time((long *)&wtmp[1].ut_time);
			(void) lseek(wf, (off_t)0L, 2);
			(void) write(wf, (char *)wtmp, sizeof(wtmp));
			(void) close(wf);
E 9
E 2
		}
D 2
		time(&wtmp[0].ut_time);
		if(stime(&timbuf) < 0) {
E 2
I 2
D 9
		tv.tv_sec = tv.tv_sec;
D 6
		wtmp[0].ut_time = tv.tv_sec;
E 6
		if (settimeofday(&tv, (struct timezone *)0) < 0) {
E 2
			rc++;
D 3
			printf("date: no permission\n");
		} else if ((wf = open("/usr/adm/wtmp", 1)) >= 0) {
E 3
I 3
			perror("Failed to set date");
		} else if ((wf = open(WTMP, 1)) >= 0) {
E 3
			time(&wtmp[1].ut_time);
			lseek(wf, 0L, 2);
			write(wf, (char *)wtmp, sizeof(wtmp));
			close(wf);
E 9
I 9
		goto display;
	}

E 11
I 11
D 17
	
E 11
/*
 * Here we set the date in the machines controlled by timedaemons
 * by communicating the new date to the local timedaemon. 
 * If the timedaemon is in the master state, it performs the correction on 
 * all slaves. If it is in the slave state, it notifies the master 
 * that a correction is needed.
 */
E 17
I 17
D 19
	if (!settime(tv)) {
E 19
I 19
D 23
	if (nflag || !settime(tv)) {
E 19
		int wf;
E 17

D 17
	srvp = getservbyname("timed", "udp");
	if (srvp == 0) {
		fprintf(stderr, "udp/timed: unknown service\n");
D 11
		exit(1);
E 11
I 11
		goto oldway;
E 11
	}	
	dest.sin_port = srvp->s_port;
	dest.sin_family = AF_INET;
I 11
	dest.sin_addr.s_addr = htonl((u_long)INADDR_ANY);
E 11
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
D 11
		perror("opening socket");
		exit(1);
E 11
I 11
		if (errno != EPROTONOSUPPORT)
			perror("socket");
		goto oldway;
E 11
	}

	sin.sin_family = AF_INET;
	for (port = IPPORT_RESERVED - 1; port > IPPORT_RESERVED / 2; port--) {
		sin.sin_port = htons((u_short)port);
		if (bind(sock, (struct sockaddr *)&sin, sizeof (sin)) >= 0)
			break;
D 11
		if (errno != EADDRINUSE && errno != EADDRNOTAVAIL) {
E 11
I 11
		if (errno != EADDRINUSE) {
E 11
D 14
			perror("bind");
E 14
I 14
			if (errno != EADDRNOTAVAIL)
				perror("bind");
E 14
			(void) close(sock);
D 11
			exit(1);
E 11
I 11
			goto oldway;
E 11
E 9
		}
	}
D 3
	if (rc==0)
E 3
I 3
D 9
	if (rc == 0)
E 3
D 2
		time(&timbuf);
	if(uflag) {
		ap = asctime(gmtime(&timbuf));
E 2
I 2
		time(&tv.tv_sec);
E 9
I 9
	if (port == IPPORT_RESERVED / 2) {
		fprintf(stderr, "socket: All ports in use\n");
		(void) close(sock);
D 11
		exit(1);
E 11
I 11
		goto oldway;
E 11
	}

D 11
	(void) gethostname(hostname,sizeof(hostname));
	hp = gethostbyname(hostname);
	if (hp == NULL) {
		perror("gethostbyname");
		exit(1);
	}
	bcopy(hp->h_addr, &dest.sin_addr.s_addr, hp->h_length);

E 11
	msg.tsp_type = TSP_DATE;
I 11
	msg.tsp_vers = TSPVERSION;
	(void) gethostname(hostname, sizeof(hostname));
E 11
	(void) strcpy(msg.tsp_name, hostname);
D 11
	(void) gettimeofday(&now, (struct timezone *)0);
E 11
D 12
	timevalsub(&tv, &now);
E 12
	msg.tsp_time = tv;
I 12
	timevalsub(&msg.tsp_time, &now);
E 12
	bytenetorder(&msg);
	length = sizeof(struct sockaddr_in);
	if (sendto(sock, (char *)&msg, sizeof(struct tsp), 0, 
						&dest, length) < 0) {
D 11
		perror("sendto");
		exit(1);
E 11
I 11
		if (errno != ECONNREFUSED)
			perror("sendto");
		goto oldway;
E 11
	}

	timed_ack = -1;
D 11
	tout.tv_sec = WAITACK;
	tout.tv_usec = 0;
E 11
I 11
	waittime = WAITACK;
E 11
loop:
D 11
	ready = 1<<sock;
	found = select(20, &ready, (int *)0, (int *)0, &tout);
	if (found) {
E 11
I 11
	tout.tv_sec = waittime;
	tout.tv_usec = 0;
	FD_ZERO(&ready);
	FD_SET(sock, &ready);
	found = select(FD_SETSIZE, &ready, (fd_set *)0, (fd_set *)0, &tout);
	if (found > 0 && FD_ISSET(sock, &ready)) {
E 11
		length = sizeof(struct sockaddr_in);
		if (recvfrom(sock, (char *)&msg, sizeof(struct tsp), 0, 
							&from, &length) < 0) {
			perror("recvfrom");
D 11
			exit(1);
E 11
I 11
			goto oldway;
E 11
		}
		bytehostorder(&msg);

		switch (msg.tsp_type) {

		case TSP_ACK:
			timed_ack = TSP_ACK;
D 11
			tout.tv_sec = WAITDATEACK;
			tout.tv_usec = 0;
E 11
I 11
			waittime = WAITDATEACK;
E 11
			goto loop;
D 11
			break;
E 11
		case TSP_DATEACK:
D 11
			goto display;
			break;
E 11
I 11
D 12
			goto oldway;
E 12
I 12
			goto display;
E 12
E 11
		default:
D 11
			printf("Wrong ack received: %s\n", 
E 11
I 11
			printf("Wrong ack received from timed: %s\n", 
E 11
						tsptype[msg.tsp_type]);
			timed_ack = -1;
			break;
		}
	}

D 11
	if (timed_ack == TSP_ACK) {
E 11
I 11
	if (timed_ack == TSP_ACK)
E 11
		printf("Network date being set\n");
D 11
		exit(0);
	} else {
		printf("Communication problems\n");
		exit(1);
E 11
I 11
	else {
		printf("Communication error with timed\n");
oldway:
E 17
		if (settimeofday(&tv, (struct timezone *)0) < 0) {
E 23
I 23
	if (nflag || !netsettime(tv)) {
		if (settimeofday(&tv,(struct timezone *)0)) {
E 23
			perror("settimeofday");
I 21
			retval = 1;
E 21
			goto display;
		}
D 17
		if ((wf = open(WTMP, 1)) >= 0) {
E 17
I 17
D 23
		if ((wf = open(WTMP, O_WRONLY|O_APPEND)) >= 0) {
E 17
			(void) time((time_t *)&wtmp[1].ut_time);
D 17
			(void) lseek(wf, (off_t)0L, 2);
E 17
			(void) write(wf, (char *)wtmp, sizeof(wtmp));
			(void) close(wf);
E 23
I 23
		if ((wf = open(WTMP,O_WRONLY|O_APPEND)) < 0)
			fputs("date: can't write wtmp file.\n",stderr);
		else {
			(void)time((time_t *)&wtmp[1].ut_time);
			/*NOSTRICT*/
			(void)write(wf,(char *)wtmp,sizeof(wtmp));
			(void)close(wf);
E 23
		}
E 11
	}
I 17
D 23
	syslog(LOG_NOTICE, "set by %s", username);
E 23
E 17

I 23
	username = getlogin();
	if (!username || *username == '\0')	/* single-user or no tty */
		username = "root";
D 24
	syslog(LOG_NOTICE,"set by %s",username);
E 24
I 24
	syslog(LOG_AUTH | LOG_NOTICE,"date set by %s",username);
E 24

E 23
display:
D 23
	(void) gettimeofday(&tv, (struct timezone *)0);
E 23
I 23
	if (gettimeofday(&tv,(struct timezone *)0)) {
		perror("gettimeofday");
		exit(1);
	}
E 23
E 9
	if (uflag) {
D 9
		ap = asctime(gmtime(&tv.tv_sec));
E 9
I 9
D 11
		ap = asctime(gmtime((long *)&tv.tv_sec));
E 11
I 11
		ap = asctime(gmtime((time_t *)&tv.tv_sec));
E 11
E 9
E 2
		tzn = "GMT";
D 23
	} else {
		struct tm *tp;
E 23
I 23
	}
	else {
		struct tm	*tp;

E 23
D 2
		tp = localtime(&timbuf);
E 2
I 2
D 9
		tp = localtime(&tv.tv_sec);
E 9
I 9
D 11
		tp = localtime((long *)&tv.tv_sec);
E 11
I 11
		tp = localtime((time_t *)&tv.tv_sec);
E 11
E 9
E 2
		ap = asctime(tp);
D 2
		tzn = timezone(info.timezone, tp->tm_isdst);
E 2
I 2
D 23
		tzn = timezone(tz.tz_minuteswest, tp->tm_isdst);
E 23
I 23
		tzn = tp->tm_zone;
E 23
E 2
	}
D 23
	printf("%.20s", ap);
	if (tzn)
		printf("%s", tzn);
	printf("%s", ap+19);
E 23
I 23
	printf("%.20s%s%s",ap,tzn,ap + 19);
E 23
I 21
	exit(retval);
E 21
D 9
	exit(rc);
E 9
}

D 23
gtime()
E 23
I 23
/*
 * gtime --
 *	convert user's time into number of seconds
 */
static
gtime(ap)
	register char	*ap;		/* user argument */
E 23
{
D 23
	register int i, year, month;
	int day, hour, mins, secs;
	struct tm *L;
	char x;
E 23
I 23
	register int	year, month;
	register char	*C;		/* pointer into time argument */
	struct tm	*L;
	int	day, hour, mins, secs;
I 26
	int	century;
E 26
E 23

D 3
	ep=ap;
E 3
I 3
D 23
	ep = ap;
E 3
	while(*ep) ep++;
D 3
	sp=ap;
	while(sp<ep) {
E 3
I 3
	sp = ap;
	while(sp < ep) {
E 3
		x = *sp;
		*sp++ = *--ep;
		*ep = x;
E 23
I 23
	for (secs = 0, C = ap;*C;++C) {
		if (*C == '.') {		/* seconds provided */
			if (strlen(C) != 3)
				return(1);
			*C = NULL;
			secs = (C[1] - '0') * 10 + (C[2] - '0');
			break;
		}
		if (!isdigit(*C))
			return(-1);
E 23
	}
D 3
	sp=ap;
E 3
I 3
D 23
	sp = ap;
E 3
D 2
	time(&timbuf);
	L=localtime(&timbuf);
E 2
I 2
D 9
	gettimeofday(&tv, 0);
D 3
	L=localtime(&tv.tv_sec);
E 3
I 3
	L = localtime(&tv.tv_sec);
E 9
I 9
	(void) gettimeofday(&tv, (struct timezone *)0);
E 23
I 23

E 23
D 11
	L = localtime((long *)&tv.tv_sec);
E 11
I 11
	L = localtime((time_t *)&tv.tv_sec);
E 11
E 9
E 3
E 2
D 23
	secs = gp(-1);
D 2
	if(*sp!='.') {
E 2
I 2
D 3
	if (*sp!='.') {
E 2
		mins=secs;
		secs=0;
	} else {sp++;
E 3
I 3
	if (*sp != '.') {
		mins = secs;
		secs = 0;
	} else {
		sp++;
E 3
		mins = gp(-1);
E 23
I 23
D 26
	year = L->tm_year;			/* defaults */
E 26
I 26
	century = L->tm_year / 100 + 19;	/* defaults */
	year = L->tm_year % 100;
E 26
	month = L->tm_mon + 1;
	day = L->tm_mday;

	switch ((int)(C - ap)) {		/* length */
I 26
		case 12:			/* yyyymmddhhmm */
			century = ATOI2(ap);
E 26
		case 10:			/* yymmddhhmm */
			year = ATOI2(ap);
		case 8:				/* mmddhhmm */
			month = ATOI2(ap);
		case 6:				/* ddhhmm */
			day = ATOI2(ap);
		case 4:				/* hhmm */
			hour = ATOI2(ap);
			mins = ATOI2(ap);
			break;
		default:
			return(1);
E 23
	}
D 23
	hour = gp(-1);
	day = gp(L->tm_mday);
	month = gp(L->tm_mon+1);
	year = gp(L->tm_year);
D 2
	if(*sp)
		return(1);
	if( month<1 || month>12 ||
E 2
I 2
	if (*sp)
		return (1);
D 3
	if (month<1 || month>12 ||
E 2
	    day<1 || day>31 ||
	    mins<0 || mins>59 ||
	    secs<0 || secs>59)
E 3
I 3
	if (month < 1 || month > 12 ||
	    day < 1 || day > 31 ||
	    mins < 0 || mins > 59 ||
	    secs < 0 || secs > 59)
E 3
D 2
		return(1);
E 2
I 2
		return (1);
E 23
I 23

	if (*ap || month < 1 || month > 12 || day < 1 || day > 31 ||
	     mins < 0 || mins > 59 || secs < 0 || secs > 59)
		return(1);
E 23
E 2
D 3
	if (hour==24) {
		hour=0; day++;
E 3
I 3
	if (hour == 24) {
I 23
		++day;
E 23
		hour = 0;
D 23
		day++;
E 23
E 3
	}
D 3
	if (hour<0 || hour>23)
E 3
I 3
D 23
	if (hour < 0 || hour > 23)
E 3
D 2
		return(1);
	timbuf = 0;
E 2
I 2
		return (1);
E 23
I 23
	else if (hour < 0 || hour > 23)
		return(1);

E 23
	tv.tv_sec = 0;
E 2
D 23
	year += 1900;
D 2
	for(i=1970; i<year; i++)
		timbuf += dysize(i);
E 2
I 2
D 3
	for (i=1970; i<year; i++)
E 3
I 3
	for (i = 1970; i < year; i++)
E 3
		tv.tv_sec += dysize(i);
E 2
	/* Leap year */
D 3
	if (dysize(year)==366 && month >= 3)
E 3
I 3
	if (dysize(year) == 366 && month >= 3)
E 3
D 2
		timbuf++;
	while(--month)
		timbuf += dmsize[month-1];
	timbuf += day-1;
	timbuf = 24*timbuf + hour;
	timbuf = 60*timbuf + mins;
	timbuf = 60*timbuf + secs;
	return(0);

E 2
I 2
		tv.tv_sec++;
E 23
I 23
D 26
	year += TM_YEAR_BASE;
E 26
I 26
	year += century * 100;
	if (year < EPOCH_YEAR)
		return(1);
E 26
	if (isleap(year) && month > 2)
		++tv.tv_sec;
	for (--year;year >= EPOCH_YEAR;--year)
		tv.tv_sec += isleap(year) ? DAYS_PER_LYEAR : DAYS_PER_NYEAR;
E 23
	while (--month)
D 23
		tv.tv_sec += dmsize[month-1];
	tv.tv_sec += day-1;
	tv.tv_sec = 24*tv.tv_sec + hour;
	tv.tv_sec = 60*tv.tv_sec + mins;
	tv.tv_sec = 60*tv.tv_sec + secs;
	return (0);
E 23
I 23
		tv.tv_sec += dmsize[month];
	tv.tv_sec += day - 1;
	tv.tv_sec = HOURS_PER_DAY * tv.tv_sec + hour;
	tv.tv_sec = MINS_PER_HOUR * tv.tv_sec + mins;
	tv.tv_sec = SECS_PER_MIN * tv.tv_sec + secs;
	return(0);
E 23
E 2
}

D 23
gp(dfault)
{
	register int c, d;

D 2
	if(*sp==0)
		return(dfault);
E 2
I 2
D 3
	if (*sp==0)
E 3
I 3
	if (*sp == 0)
E 3
		return (dfault);
E 2
D 3
	c = (*sp++)-'0';
	d = (*sp ? (*sp++)-'0' : 0);
D 2
	if(c<0 || c>9 || d<0 || d>9)
		return(-1);
	return(c+10*d);
E 2
I 2
	if (c<0 || c>9 || d<0 || d>9)
E 3
I 3
	c = (*sp++) - '0';
	d = (*sp ? (*sp++) - '0' : 0);
	if (c < 0 || c > 9 || d < 0 || d > 9)
E 3
		return (-1);
	return (c+10*d);
I 9
}

E 23
I 17
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define TSPTYPES
#include <protocols/timed.h>

#define WAITACK		2	/* seconds */
#define WAITDATEACK	5	/* seconds */

extern	int errno;
/*
 * Set the date in the machines controlled by timedaemons
 * by communicating the new date to the local timedaemon. 
 * If the timedaemon is in the master state, it performs the
 * correction on all slaves.  If it is in the slave state, it
 * notifies the master that a correction is needed.
I 21
 * Returns 1 on success, 0 on failure.
E 21
 */
D 23
settime(tv)
	struct timeval tv;
E 23
I 23
static
netsettime(ntv)
	struct timeval ntv;
E 23
{
	int s, length, port, timed_ack, found, err;
	long waittime;
	fd_set ready;
	char hostname[MAXHOSTNAMELEN];
	struct timeval tout;
	struct servent *sp;
	struct tsp msg;
	struct sockaddr_in sin, dest, from;

	sp = getservbyname("timed", "udp");
	if (sp == 0) {
D 23
		fprintf(stderr, "udp/timed: unknown service\n");
E 23
I 23
		fputs("udp/timed: unknown service\n",stderr);
E 23
I 21
		retval = 2;
E 21
		return (0);
D 23
	}	
E 23
I 23
	}
E 23
	dest.sin_port = sp->s_port;
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = htonl((u_long)INADDR_ANY);
	s = socket(AF_INET, SOCK_DGRAM, 0);
	if (s < 0) {
		if (errno != EPROTONOSUPPORT)
			perror("date: socket");
		goto bad;
	}
D 22
	bzero(&sin, sizeof (sin));
E 22
I 22
	bzero((char *)&sin, sizeof (sin));
E 22
	sin.sin_family = AF_INET;
	for (port = IPPORT_RESERVED - 1; port > IPPORT_RESERVED / 2; port--) {
		sin.sin_port = htons((u_short)port);
		if (bind(s, (struct sockaddr *)&sin, sizeof (sin)) >= 0)
			break;
		if (errno != EADDRINUSE) {
			if (errno != EADDRNOTAVAIL)
				perror("date: bind");
			goto bad;
		}
	}
	if (port == IPPORT_RESERVED / 2) {
D 23
		fprintf(stderr, "date: All ports in use\n");
E 23
I 23
		fputs("date: All ports in use\n",stderr);
E 23
		goto bad;
	}
D 20
	msg.tsp_type = TSP_DATE;
E 20
I 20
	msg.tsp_type = TSP_SETDATE;
E 20
	msg.tsp_vers = TSPVERSION;
D 23
	(void) gethostname(hostname, sizeof (hostname));
E 23
I 23
	if (gethostname(hostname, sizeof (hostname))) {
		perror("gethostname");
		goto bad;
	}
E 23
	(void) strncpy(msg.tsp_name, hostname, sizeof (hostname));
D 20
	timevalsub(&tv, &now);
E 20
	msg.tsp_seq = htons((u_short)0);
D 23
	msg.tsp_time.tv_sec = htonl((u_long)tv.tv_sec);
	msg.tsp_time.tv_usec = htonl((u_long)tv.tv_usec);
E 23
I 23
	msg.tsp_time.tv_sec = htonl((u_long)ntv.tv_sec);
	msg.tsp_time.tv_usec = htonl((u_long)ntv.tv_usec);
E 23
	length = sizeof (struct sockaddr_in);
	if (connect(s, &dest, length) < 0) {
		perror("date: connect");
		goto bad;
	}
D 22
	if (send(s, &msg, sizeof (struct tsp), 0) < 0) {
E 22
I 22
	if (send(s, (char *)&msg, sizeof (struct tsp), 0) < 0) {
E 22
		if (errno != ECONNREFUSED)
			perror("date: send");
		goto bad;
	}
	timed_ack = -1;
	waittime = WAITACK;
loop:
	tout.tv_sec = waittime;
	tout.tv_usec = 0;
	FD_ZERO(&ready);
	FD_SET(s, &ready);
	found = select(FD_SETSIZE, &ready, (fd_set *)0, (fd_set *)0, &tout);
	length = sizeof(err);
D 22
	if (getsockopt(s, SOL_SOCKET, SO_ERROR, &err, &length) == 0 && err) {
E 22
I 22
	if (getsockopt(s, SOL_SOCKET, SO_ERROR, (char *)&err, &length) == 0
	    && err) {
E 22
		errno = err;
		if (errno != ECONNREFUSED)
			perror("date: send (delayed error)");
		goto bad;
	}
	if (found > 0 && FD_ISSET(s, &ready)) {
		length = sizeof (struct sockaddr_in);
D 22
		if (recvfrom(s, &msg, sizeof (struct tsp), 0, &from,
E 22
I 22
		if (recvfrom(s, (char *)&msg, sizeof (struct tsp), 0, &from,
E 22
		    &length) < 0) {
			if (errno != ECONNREFUSED)
				perror("date: recvfrom");
			goto bad;
		}
		msg.tsp_seq = ntohs(msg.tsp_seq);
		msg.tsp_time.tv_sec = ntohl(msg.tsp_time.tv_sec);
		msg.tsp_time.tv_usec = ntohl(msg.tsp_time.tv_usec);
		switch (msg.tsp_type) {

		case TSP_ACK:
			timed_ack = TSP_ACK;
			waittime = WAITDATEACK;
			goto loop;

		case TSP_DATEACK:
D 22
			close(s);
E 22
I 22
			(void)close(s);
E 22
			return (1);

		default:
			fprintf(stderr,
			    "date: Wrong ack received from timed: %s\n", 
			    tsptype[msg.tsp_type]);
			timed_ack = -1;
			break;
		}
	}
	if (timed_ack == -1)
D 23
		fprintf(stderr,
		    "date: Can't reach time daemon, time set locally.\n");
E 23
I 23
		fputs("date: Can't reach time daemon, time set locally.\n",
		    stderr);
E 23
bad:
D 22
	close(s);
E 22
I 22
	(void)close(s);
E 22
I 21
	retval = 2;
E 21
	return (0);
I 24
}

usage()
{
	fputs("usage: date [-nu] [-d dst] [-t minutes_west] [yymmddhhmm[.ss]]\n",stderr);
E 24
D 22
}

E 17
timevalsub(t1, t2)
D 17
struct timeval *t1, *t2;
E 17
I 17
	register struct timeval *t1, *t2;
E 17
{
	t1->tv_sec -= t2->tv_sec;
	t1->tv_usec -= t2->tv_usec;
	if (t1->tv_usec < 0) {
		t1->tv_sec--;
		t1->tv_usec += 1000000;
	}
	if (t1->tv_usec >= 1000000) {
		t1->tv_sec++;
		t1->tv_usec -= 1000000;
	}
E 22
D 17
}

bytenetorder(ptr)
struct tsp *ptr;
{
	ptr->tsp_seq = htons((u_short)ptr->tsp_seq);
	ptr->tsp_time.tv_sec = htonl((u_long)ptr->tsp_time.tv_sec);
	ptr->tsp_time.tv_usec = htonl((u_long)ptr->tsp_time.tv_usec);
}

bytehostorder(ptr)
struct tsp *ptr;
{
	ptr->tsp_seq = ntohs((u_short)ptr->tsp_seq);
	ptr->tsp_time.tv_sec = ntohl((u_long)ptr->tsp_time.tv_sec);
	ptr->tsp_time.tv_usec = ntohl((u_long)ptr->tsp_time.tv_usec);
E 17
E 9
E 2
}
E 1
