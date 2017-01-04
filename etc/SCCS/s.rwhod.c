h35676
s 00001/00001/00520
d D 5.10 87/10/22 10:44:51 bostic 43 42
c ANSI C; sprintf now returns an int.
e
s 00016/00005/00505
d D 5.9 86/03/05 19:18:28 mckusick 42 41
c more minor tweeks from Torek
e
s 00008/00007/00502
d D 5.8 86/02/01 13:49:21 karels 41 40
c perhaps a bit less inelegant (and someone has to use the 4.2-style syscalls!)
e
s 00015/00004/00494
d D 5.7 86/01/31 13:43:07 mckusick 40 39
c reduce number of creat's and length of pathnames (from speck@csvax.caltech.edu)
e
s 00000/00007/00498
d D 5.6 85/10/25 13:55:54 bloom 39 38
c Why try to be intelligent about address families too late
e
s 00001/00001/00504
d D 5.5 85/09/17 19:15:45 eric 38 37
c facilities in syslog
e
s 00004/00000/00501
d D 5.4 85/09/15 14:24:23 bloom 37 35
c strip domain part of hostname
e
s 00009/00003/00498
d R 5.4 85/09/15 00:09:44 bloom 36 35
c strip domain from hostname, servent will not stay around after gethostbyname()
e
s 00000/00026/00501
d D 5.3 85/06/19 08:31:35 karels 35 34
c remove old, unused subnet code
e
s 00001/00001/00526
d D 5.2 85/06/18 19:09:06 mckusick 34 33
c rwhod.h moves to /usr/include/protocols
e
s 00014/00002/00513
d D 5.1 85/06/06 14:19:27 dist 33 32
c Add copyright
e
s 00016/00004/00499
d D 4.30 85/06/06 13:57:24 bloom 32 31
c dynamically configure utmp size
e
s 00009/00006/00494
d D 4.29 85/06/03 09:52:14 karels 31 30
c use GIFBRDADDR instead of trying to figure it out by hand
e
s 00002/00001/00498
d D 4.28 85/02/25 14:15:03 karels 30 29
c increase max size of utmp examined, make it a #define
e
s 00001/00000/00498
d D 4.27 84/10/23 09:27:33 tef 29 28
c utmptime tested but never set, caused /etc/utmp to get read everytime
e
s 00002/00002/00496
d D 4.26 84/09/04 21:35:09 sam 28 27
c changeover to new socketopt interface
e
s 00004/00000/00494
d D 4.25 84/08/29 15:13:28 karels 27 25
c add SO_BROADCAST flag on socket
e
s 00004/00000/00494
d R 4.25 84/08/29 15:07:03 karels 26 25
c add SO_BROADCAST flag on socket
e
s 00024/00029/00470
d D 4.24 84/07/06 10:34:18 ralph 25 24
c use syslog routines.
e
s 00012/00000/00487
d D 4.23 84/07/04 12:08:59 sam 24 23
c don't nlist /vmunix unless file changes (from dpk@brl)
e
s 00030/00002/00457
d D 4.22 84/05/11 16:40:23 karels 23 22
c determine correct broadcast address on subnets
e
s 00007/00001/00452
d D 4.21 83/11/14 15:54:58 ralph 22 21
c broadcast status info less often.
e
s 00001/00001/00452
d D 4.20 83/10/11 16:00:43 leres 21 20
c Fix from Wayne@lbl-csam, allow ispunct() characters in host names.
e
s 00001/00001/00452
d D 4.19 83/07/01 04:18:06 sam 20 19
c rwhod.h no longer in /usr/include
e
s 00002/00001/00451
d D 4.18 83/06/30 12:24:25 sam 19 17
c avoid losing alarm clock
e
s 00003/00001/00451
d R 4.18 83/06/30 12:23:16 sam 18 17
c avoid losing alarm clock
e
s 00000/00001/00452
d D 4.17 83/06/24 11:47:26 sam 17 16
c delte extra signal clal
e
s 00021/00018/00432
d D 4.16 83/06/18 13:06:02 sam 16 15
c one bug fix and a number of cleanups
e
s 00001/00001/00449
d D 4.15 83/06/12 01:46:58 sam 15 14
c new signals
e
s 00001/00001/00449
d D 4.14 83/06/02 10:41:07 sam 14 13
c double != long
e
s 00002/00002/00448
d D 4.13 83/06/02 10:20:08 sam 13 12
c typo
e
s 00002/00023/00448
d D 4.12 83/06/01 16:21:08 sam 12 11
c notyet is here
e
s 00095/00016/00376
d D 4.11 83/05/28 11:16:41 sam 11 10
c prepare for switchover
e
s 00002/00000/00390
d D 4.10 83/05/09 22:01:30 sam 10 9
c ignore old packets 
e
s 00133/00022/00257
d D 4.9 83/05/05 13:19:57 sam 9 8
c use ioctl's to configure networks; change protocol to include 
c version stamp and type fields (allows expansion to handle multi-net 
c environment)
e
s 00033/00001/00246
d D 4.8 83/04/04 07:39:48 sam 8 7
c do byte swapping (from shannon@sun)
e
s 00001/00002/00246
d D 4.7 82/12/24 21:05:18 sam 7 6
c port not byte swapped; no more asm.sed; 
c move spool area to /usr/spool/rwho so /etc is always changing
e
s 00001/00001/00247
d D 4.6 82/11/15 18:33:56 sam 6 5
c add domain specification
e
s 00025/00022/00223
d D 4.5 82/11/14 15:17:42 sam 5 4
c convert to 4.1c sys calls and directory layout
e
s 00052/00020/00193
d D 4.4 82/10/10 19:43:15 sam 4 3
c convert to new data base and add sanity check on file creation
e
s 00005/00002/00208
d D 4.3 82/04/20 18:35:16 sam 3 2
c missing bounds check
e
s 00001/00001/00209
d D 4.2 82/04/15 16:28:08 sam 2 1
c makes ernie happy
e
s 00210/00000/00000
d D 4.1 82/04/02 10:29:11 wnj 1 0
c date and time created 82/04/02 10:29:11 by wnj
e
u
U
t
T
I 33
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 33
I 1
#ifndef lint
D 8
static char sccsid[] = "%W% %E%";
E 8
I 8
D 9
static char sccsid[] = "%W% %G%";
E 9
I 9
D 11
static char sccsid[] = "%W% %E%";
E 11
I 11
D 33
static char sccsid[] = "%W% (Berkeley) %E%";
E 11
E 9
E 8
#endif
E 33
I 33
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 33

D 5
#include <stdio.h>
#include <signal.h>
E 5
#include <sys/types.h>
D 5
#include <net/in.h>
E 5
#include <sys/socket.h>
D 5
#include <errno.h>
#include <utmp.h>
#include "rwhod.h"
E 5
#include <sys/stat.h>
D 5
#include <nlist.h>
E 5
#include <sys/ioctl.h>
I 16
#include <sys/file.h>
E 16
I 5

I 9
#include <net/if.h>
E 9
#include <netinet/in.h>

#include <nlist.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <utmp.h>
E 5
I 4
#include <ctype.h>
#include <netdb.h>
I 25
#include <syslog.h>
E 25
I 9
D 20
#include <rwhod.h>
E 20
I 20
D 34
#include "rwhod.h"
E 34
I 34
#include <protocols/rwhod.h>
E 34
E 20
E 9
E 4

I 22
/*
 * Alarm interval. Don't forget to change the down time check in ruptime
 * if this is changed.
 */
D 25
#define AL_INTERVAL (5 * 60)
E 25
I 25
#define AL_INTERVAL (3 * 60)
I 30
D 32
#define	MAXTTYS	256			/* Max # of utmp entries examined */
E 32
E 30
E 25

E 22
I 5
D 9
#include "rwhod.h"

E 9
E 5
D 4
struct	sockaddr_in sin = { AF_INET, IPPORT_WHOSERVER };
E 4
I 4
struct	sockaddr_in sin = { AF_INET };
E 4

extern	errno;

D 9
char	*localnet = "localnet";
char	*myname = "myname";
E 9
I 9
char	myname[32];
E 9

struct	nlist nl[] = {
#define	NL_AVENRUN	0
	{ "_avenrun" },
D 5
#define	NL_BOOTIME	1
	{ "_bootime" },
E 5
I 5
#define	NL_BOOTTIME	1
	{ "_boottime" },
E 5
	0
};

I 9
/*
 * We communicate with each neighbor in
 * a list constructed at the time we're
 * started up.  Neighbors are currently
 * directly connected via a hardware interface.
 */
struct	neighbor {
	struct	neighbor *n_next;
	char	*n_name;		/* interface name */
	char	*n_addr;		/* who to send to */
	int	n_addrlen;		/* size of address */
	int	n_flags;		/* should forward?, interface flags */
};

struct	neighbor *neighbors;
E 9
struct	whod mywd;
I 9
struct	servent *sp;
E 9
int	s, utmpf, kmemf = -1;

I 8
D 9
#define	WHDRSIZE	(sizeof (wd) - sizeof (wd.wd_we))
E 9
I 9
#define	WHDRSIZE	(sizeof (mywd) - sizeof (mywd.wd_we))
#define	RWHODIR		"/usr/spool/rwho"
E 9

E 8
int	onalrm();
D 9
char	*strcpy(), *sprintf();
E 9
I 9
D 43
char	*strcpy(), *sprintf(), *malloc();
E 43
I 43
char	*strcpy(), *malloc();
E 43
E 9
long	lseek();
int	getkmem();
I 9
struct	in_addr inet_makeaddr();
E 9

main()
{
	struct sockaddr_in from;
I 41
	struct stat st;
E 41
	char path[64];
D 28
	int addr;
E 28
I 28
D 42
	int addr, on = 1;
E 42
I 42
	int on = 1;
E 42
E 28
I 4
D 9
	struct servent *sp;
E 9
I 9
D 39
	struct hostent *hp;
E 39
I 37
	char *cp;
	extern char *index();
E 37
E 9
E 4

I 25
	if (getuid()) {
		fprintf(stderr, "rwhod: not super user\n");
		exit(1);
	}
E 25
I 4
	sp = getservbyname("who", "udp");
	if (sp == 0) {
		fprintf(stderr, "rwhod: udp/who: unknown service\n");
		exit(1);
	}
D 5
#if vax || pdp11
E 5
D 7
	sp->s_port = htons(sp->s_port);
E 7
D 5
#endif
	sin.sin_port = sp->s_port;
E 5
E 4
#ifndef DEBUG
	if (fork())
		exit(0);
	{ int s;
	  for (s = 0; s < 10; s++)
		(void) close(s);
	  (void) open("/", 0);
	  (void) dup2(0, 1);
	  (void) dup2(0, 2);
	  s = open("/dev/tty", 2);
	  if (s >= 0) {
		ioctl(s, TIOCNOTTY, 0);
		(void) close(s);
	  }
	}
#endif
D 40
	(void) chdir("/dev");
E 40
I 40
	if (chdir(RWHODIR) < 0) {
		perror(RWHODIR);
		exit(1);
	}
E 40
	(void) signal(SIGHUP, getkmem);
D 25
	if (getuid()) {
D 4
		fprintf(stderr, "not super user\n");
E 4
I 4
		fprintf(stderr, "rwhod: not super user\n");
E 4
		exit(1);
	}
E 25
I 25
D 38
	openlog("rwhod", LOG_PID, 0);
E 38
I 38
	openlog("rwhod", LOG_PID, LOG_DAEMON);
E 38
E 25
D 9
	addr = rhost(&localnet);
	if (addr == -1) {
D 4
		fprintf(stderr, "no localnet for whod\n");
E 4
I 4
		fprintf(stderr, "rwhod: no localnet\n");
E 9
I 9
	/*
	 * Establish host name as returned by system.
	 */
	if (gethostname(myname, sizeof (myname) - 1) < 0) {
D 25
		perror("gethostname");
E 25
I 25
		syslog(LOG_ERR, "gethostname: %m");
E 25
E 9
E 4
		exit(1);
	}
I 37
	if ((cp = index(myname, '.')) != NULL)
		*cp = '\0';
E 37
D 9
	sin.sin_addr.s_addr = addr;
	if (rhost(&myname) == -1) {
D 4
		fprintf(stderr, "don't know my name\n");
E 4
I 4
		fprintf(stderr, "rwhod: don't know \"myname\"\n");
E 4
		exit(1);
	}
	strncpy(mywd.wd_hostname, myname, sizeof (mywd.wd_hostname) - 1);
E 9
I 9
	strncpy(mywd.wd_hostname, myname, sizeof (myname) - 1);
E 9
D 16
	utmpf = open("/etc/utmp", 0);
E 16
I 16
	utmpf = open("/etc/utmp", O_RDONLY);
E 16
	if (utmpf < 0) {
		(void) close(creat("/etc/utmp", 0644));
D 16
		utmpf = open("/etc/utmp", 0);
E 16
I 16
		utmpf = open("/etc/utmp", O_RDONLY);
E 16
	}
	if (utmpf < 0) {
D 4
		perror("/etc/utmp");
E 4
I 4
D 25
		perror("rwhod: /etc/utmp");
E 25
I 25
		syslog(LOG_ERR, "/etc/utmp: %m");
E 25
E 4
		exit(1);
	}
I 5
D 9
	sin.sin_port = sp->s_port;
E 9
E 5
	getkmem();
D 4
#ifdef vax
	sin.sin_port = htons(sin.sin_port);
#endif
E 4
D 5
again:
	if ((s = socket(SOCK_DGRAM, 0, &sin, 0)) < 0) {
E 5
I 5
D 6
	if ((s = socket(0, SOCK_DGRAM, 0, 0)) < 0) {
E 6
I 6
D 16
	if ((s = socket(AF_INET, SOCK_DGRAM, 0, 0)) < 0) {
E 16
I 16
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
E 16
E 6
E 5
D 4
		perror("socket");
E 4
I 4
D 25
		perror("rwhod: socket");
E 25
I 25
		syslog(LOG_ERR, "socket: %m");
E 25
E 4
D 5
		sleep(5);
		goto again;
E 5
I 5
		exit(1);
E 5
	}
I 27
D 28
	if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, 0, 0) < 0) {
E 28
I 28
	if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &on, sizeof (on)) < 0) {
E 28
		syslog(LOG_ERR, "setsockopt SO_BROADCAST: %m");
		exit(1);
	}
E 27
I 9
D 39
	hp = gethostbyname(myname);
	if (hp == NULL) {
D 25
		fprintf(stderr, "%s: don't know my own name\n", myname);
E 25
I 25
		syslog(LOG_ERR, "%s: don't know my own name", myname);
E 25
		exit(1);
	}
	sin.sin_family = hp->h_addrtype;
E 39
	sin.sin_port = sp->s_port;
E 9
I 5
D 16
	if (bind(s, &sin, sizeof (sin), 0) < 0) {
E 16
I 16
	if (bind(s, &sin, sizeof (sin)) < 0) {
E 16
D 25
		perror("rwhod: bind");
E 25
I 25
		syslog(LOG_ERR, "bind: %m");
E 25
		exit(1);
	}
I 9
	if (!configure(s))
		exit(1);
E 9
E 5
D 15
	sigset(SIGALRM, onalrm);
E 15
I 15
	signal(SIGALRM, onalrm);
E 15
	onalrm();
	for (;;) {
		struct whod wd;
D 5
		int cc, whod;
E 5
I 5
D 9
		int cc, whod, len=sizeof (from);
E 9
I 9
		int cc, whod, len = sizeof (from);
E 9
E 5

D 5
		cc = receive(s, &from, (char *)&wd, sizeof (struct whod));
E 5
I 5
D 9
		cc = recvfrom(s, (char *)&wd, sizeof (struct whod), 0, &from, &len);
E 9
I 9
		cc = recvfrom(s, (char *)&wd, sizeof (struct whod), 0,
			&from, &len);
E 9
E 5
		if (cc <= 0) {
			if (cc < 0 && errno != EINTR)
D 4
				perror("receive");
E 4
I 4
D 5
				perror("rwhod: receive");
E 5
I 5
D 25
				perror("rwhod: recv");
E 25
I 25
				syslog(LOG_WARNING, "recv: %m");
E 25
E 5
E 4
			continue;
		}
D 4
#ifdef vax
		from.sin_port = ntohs(from.sin_port);
#endif
		if (from.sin_port != IPPORT_WHOSERVER) {
			printf("bad from port %d\n", from.sin_port);
E 4
I 4
		if (from.sin_port != sp->s_port) {
D 25
			fprintf(stderr, "rwhod: %d: bad from port\n",
E 25
I 25
			syslog(LOG_WARNING, "%d: bad from port",
E 25
				ntohs(from.sin_port));
E 4
			continue;
		}
D 4
/*
		if (rhost(&wd.wd_hostname) == -1) {
			printf("unknown host %s\n", wd.wd_hostname);
E 4
I 4
#ifdef notdef
		if (gethostbyname(wd.wd_hostname) == 0) {
D 25
			fprintf(stderr, "rwhod: %s: unknown host\n",
E 25
I 25
			syslog(LOG_WARNING, "%s: unknown host",
E 25
				wd.wd_hostname);
E 4
			continue;
		}
D 4
*/
E 4
I 4
#endif
I 11
D 12
#ifdef notyet
E 12
E 11
I 10
		if (wd.wd_vers != WHODVERSION)
			continue;
E 10
I 9
		if (wd.wd_type != WHODTYPE_STATUS)
			continue;
I 11
D 12
#endif
E 12
E 11
E 9
		if (!verify(wd.wd_hostname)) {
D 25
			fprintf(stderr, "rwhod: malformed host name from %x\n",
E 25
I 25
			syslog(LOG_WARNING, "malformed host name from %x",
E 25
				from.sin_addr);
			continue;
		}
E 4
D 7
		(void) sprintf(path, "/etc/whod.%s", wd.wd_hostname);
E 7
I 7
D 40
		(void) sprintf(path, "%s/whod.%s", RWHODIR, wd.wd_hostname);
E 7
		whod = creat(path, 0666);
E 40
I 40
		(void) sprintf(path, "whod.%s", wd.wd_hostname);
D 41
		whod = open(path, O_WRONLY);	/* much faster than creat() */
		{	struct stat s;
			if (whod < 0 || fstat(whod, &s) < 0 || s.st_size > cc) {
				(void) close(whod);
				whod = creat(path, 0666);
			}
		}
E 41
I 41
		/*
		 * Rather than truncating and growing the file each time,
		 * use ftruncate if size is less than previous size.
		 */
		whod = open(path, O_WRONLY | O_CREAT, 0644);
E 41
E 40
		if (whod < 0) {
D 4
			printf("can't create %s\n", path);
E 4
I 4
D 25
			fprintf(stderr, "rwhod: ");
			perror(path);
E 25
I 25
			syslog(LOG_WARNING, "%s: %m", path);
E 25
E 4
			continue;
		}
I 11
D 12
#ifdef notyet
E 12
E 11
I 8
#if vax || pdp11
		{
D 16
			int i, n = (cc - WHDRSIZE)/sizeof(struct utmp);
E 16
I 16
			int i, n = (cc - WHDRSIZE)/sizeof(struct whoent);
E 16
			struct whoent *we;

			/* undo header byte swapping before writing to file */
			wd.wd_sendtime = ntohl(wd.wd_sendtime);
			for (i = 0; i < 3; i++)
				wd.wd_loadav[i] = ntohl(wd.wd_loadav[i]);
			wd.wd_boottime = ntohl(wd.wd_boottime);
			we = wd.wd_we;
			for (i = 0; i < n; i++) {
				we->we_idle = ntohl(we->we_idle);
D 12
				we->we_utmp.ut_time = ntohl(we->we_utmp.ut_time);
E 12
I 12
D 13
				we->we_utmp.ut_time =
				    ntohl(we->we_utmp.ut_time);
E 13
I 13
				we->we_utmp.out_time =
				    ntohl(we->we_utmp.out_time);
E 13
E 12
				we++;
			}
		}
#endif
I 11
D 12
#endif
E 12
E 11
E 8
		(void) time(&wd.wd_recvtime);
		(void) write(whod, (char *)&wd, cc);
I 41
		if (fstat(whod, &st) < 0 || st.st_size > cc)
			ftruncate(whod, cc);
E 41
		(void) close(whod);
	}
I 4
}

/*
 * Check out host name for unprintables
 * and other funnies before allowing a file
 * to be created.  Sorry, but blanks aren't allowed.
 */
verify(name)
	register char *name;
{
	register int size = 0;

	while (*name) {
D 21
		if (!isascii(*name) || !isalnum(*name))
E 21
I 21
		if (!isascii(*name) || !(isalnum(*name) || ispunct(*name)))
E 21
			return (0);
		name++, size++;
	}
	return (size > 0);
E 4
}

int	utmptime;
int	utmpent;
D 2
struct	utmp utmp[100];
E 2
I 2
D 3
struct	utmp utmp[500];
E 3
I 3
D 30
struct	utmp utmp[100];
E 30
I 30
D 32
struct	utmp utmp[MAXTTYS];
E 32
I 32
int	utmpsize = 0;
struct	utmp *utmp;
E 32
E 30
E 3
E 2
int	alarmcount;

onalrm()
{
	register int i;
	struct stat stb;
D 3
	register struct whoent *we = mywd.wd_we;
E 3
I 3
	register struct whoent *we = mywd.wd_we, *wlast;
E 3
	int cc;
	double avenrun[3];
	time_t now = time(0);
I 9
	register struct neighbor *np;
E 9

	if (alarmcount % 10 == 0)
		getkmem();
	alarmcount++;
	(void) fstat(utmpf, &stb);
D 32
	if (stb.st_mtime != utmptime) {
E 32
I 32
	if ((stb.st_mtime != utmptime) || (stb.st_size > utmpsize)) {
E 32
I 29
		utmptime = stb.st_mtime;
I 32
		if (stb.st_size > utmpsize) {
			utmpsize = stb.st_size + 10 * sizeof(struct utmp);
			if (utmp)
				utmp = (struct utmp *)realloc(utmp, utmpsize);
			else
				utmp = (struct utmp *)malloc(utmpsize);
			if (! utmp) {
				fprintf(stderr, "rwhod: malloc failed\n");
				utmpsize = 0;
				goto done;
			}
		}
E 32
E 29
D 16
		(void) lseek(utmpf, (long)0, 0);
E 16
I 16
		(void) lseek(utmpf, (long)0, L_SET);
E 16
D 32
		cc = read(utmpf, (char *)utmp, sizeof (utmp));
E 32
I 32
		cc = read(utmpf, (char *)utmp, stb.st_size);
E 32
		if (cc < 0) {
			perror("/etc/utmp");
D 19
			return;
E 19
I 19
			goto done;
E 19
		}
I 3
D 9
		wlast = &mywd.wd_we[(1024 / sizeof (struct whoent)) - 1];
E 9
I 9
		wlast = &mywd.wd_we[1024 / sizeof (struct whoent) - 1];
E 9
E 3
		utmpent = cc / sizeof (struct utmp);
		for (i = 0; i < utmpent; i++)
			if (utmp[i].ut_name[0]) {
D 11
				we->we_utmp = utmp[i];
E 11
I 11
				bcopy(utmp[i].ut_line, we->we_utmp.out_line,
				   sizeof (utmp[i].ut_line));
				bcopy(utmp[i].ut_name, we->we_utmp.out_name,
				   sizeof (utmp[i].ut_name));
D 12
#ifdef notyet
E 12
				we->we_utmp.out_time = htonl(utmp[i].ut_time);
D 12
#else
				we->we_utmp.out_time = utmp[i].ut_time;
#endif
E 12
E 11
I 3
				if (we >= wlast)
					break;
E 3
				we++;
			}
		utmpent = we - mywd.wd_we;
	}
I 42

	/*
	 * The test on utmpent looks silly---after all, if no one is
	 * logged on, why worry about efficiency?---but is useful on
	 * (e.g.) compute servers.
	 */
	if (utmpent && chdir("/dev")) {
		syslog(LOG_ERR, "chdir(/dev): %m");
		exit(1);
	}
E 42
	we = mywd.wd_we;
	for (i = 0; i < utmpent; i++) {
D 11
		if (stat(we->we_utmp.ut_line, &stb) >= 0)
E 11
I 11
D 40
		if (stat(we->we_utmp.out_line, &stb) >= 0)
E 40
I 40
D 42
		char path[64];
		(void) sprintf(path, "/dev/%s", we->we_utmp.out_line);
		if (stat(path, &stb) >= 0)
E 42
I 42
		if (stat(we->we_utmp.out_line, &stb) >= 0)
E 42
E 40
D 12
#ifdef notyet
E 12
			we->we_idle = htonl(now - stb.st_atime);
D 12
#else
E 11
			we->we_idle = now - stb.st_atime;
I 11
#endif
E 12
E 11
		we++;
	}
D 16
	(void) lseek(kmemf, (long)nl[NL_AVENRUN].n_value, 0);
E 16
I 16
	(void) lseek(kmemf, (long)nl[NL_AVENRUN].n_value, L_SET);
E 16
	(void) read(kmemf, (char *)avenrun, sizeof (avenrun));
	for (i = 0; i < 3; i++)
I 11
D 12
#ifdef notyet
E 12
D 14
		mywd.wd_loadav[i] = htonl(avenrun[i] * 100);
E 14
I 14
		mywd.wd_loadav[i] = htonl((u_long)(avenrun[i] * 100));
E 14
D 12
#else
E 11
		mywd.wd_loadav[i] = avenrun[i] * 100;
D 11
	cc = (char *)we - (char *)&mywd;
	(void) time(&mywd.wd_sendtime);
I 8
#if vax || pdp11
	mywd.wd_sendtime = htonl(mywd.wd_sendtime);
	for (i = 0; i < 3; i++)
		mywd.wd_loadav[i] = htonl(mywd.wd_loadav[i]);
	mywd.wd_boottime = htonl(mywd.wd_boottime);
	we = mywd.wd_we;
	for (i = 0; i < utmpent; i++) {
		we->we_idle = htonl(we->we_idle);
		we->we_utmp.ut_time = htonl(we->we_utmp.ut_time);
		we++;
	}
E 11
#endif
E 12
I 11
	cc = (char *)we - (char *)&mywd;
D 12
#ifdef notyet
E 12
	mywd.wd_sendtime = htonl(time(0));
E 11
E 8
D 5
	send(s, &sin, (char *)&mywd, cc);
E 5
I 5
D 9
	(void) sendto(s, (char *)&mywd, cc, 0, &sin, sizeof (sin));
E 9
I 9
	mywd.wd_vers = WHODVERSION;
	mywd.wd_type = WHODTYPE_STATUS;
I 11
D 12
#else
	mywd.wd_sendtime = time(0);
#endif
E 12
E 11
	for (np = neighbors; np != NULL; np = np->n_next)
		(void) sendto(s, (char *)&mywd, cc, 0,
			np->n_addr, np->n_addrlen);
I 42
	if (utmpent && chdir(RWHODIR)) {
		syslog(LOG_ERR, "chdir(%s): %m", RWHODIR);
		exit(1);
	}
E 42
I 19
done:
E 19
E 9
E 5
D 22
	(void) alarm(60);
E 22
I 22
	(void) alarm(AL_INTERVAL);
E 22
}

getkmem()
{
D 42
	struct nlist *nlp;
E 42
I 24
	static ino_t vmunixino;
	static time_t vmunixctime;
	struct stat sb;
E 24

I 24
	if (stat("/vmunix", &sb) < 0) {
		if (vmunixctime)
			return;
	} else {
		if (sb.st_ctime == vmunixctime && sb.st_ino == vmunixino)
			return;
		vmunixctime = sb.st_ctime;
		vmunixino= sb.st_ino;
	}
E 24
D 17
	signal(SIGHUP, getkmem);
E 17
	if (kmemf >= 0)
		(void) close(kmemf);
loop:
D 25
	for (nlp = &nl[sizeof (nl) / sizeof (nl[0])]; --nlp >= nl; ) {
		nlp->n_value = 0;
		nlp->n_type = 0;
	}
	nlist("/vmunix", nl);
	if (nl[0].n_value == 0) {
		fprintf(stderr, "/vmunix namelist botch\n");
E 25
I 25
	if (nlist("/vmunix", nl)) {
		syslog(LOG_WARNING, "/vmunix namelist botch");
E 25
		sleep(300);
		goto loop;
	}
D 16
	kmemf = open("/dev/kmem", 0);
E 16
I 16
	kmemf = open("/dev/kmem", O_RDONLY);
E 16
	if (kmemf < 0) {
D 25
		perror("/dev/kmem");
		sleep(300);
		goto loop;
E 25
I 25
		syslog(LOG_ERR, "/dev/kmem: %m");
		exit(1);
E 25
	}
D 5
	(void) lseek(kmemf, (long)nl[NL_BOOTIME].n_value, 0);
	(void) read(kmemf, (char *)&mywd.wd_bootime, sizeof (mywd.wd_bootime));
E 5
I 5
D 16
	(void) lseek(kmemf, (long)nl[NL_BOOTTIME].n_value, 0);
	(void) read(kmemf, (char *)&mywd.wd_boottime, sizeof (mywd.wd_boottime));
E 16
I 16
	(void) lseek(kmemf, (long)nl[NL_BOOTTIME].n_value, L_SET);
	(void) read(kmemf, (char *)&mywd.wd_boottime,
	    sizeof (mywd.wd_boottime));
E 16
I 11
D 12
#ifdef notyet
E 12
	mywd.wd_boottime = htonl(mywd.wd_boottime);
D 12
#endif
E 12
E 11
I 9
}

/*
 * Figure out device configuration and select
 * networks which deserve status information.
 */
configure(s)
	int s;
{
	char buf[BUFSIZ];
	struct ifconf ifc;
	struct ifreq ifreq, *ifr;
D 16
	int n;
E 16
	struct sockaddr_in *sin;
	register struct neighbor *np;
I 16
	int n;
E 16

	ifc.ifc_len = sizeof (buf);
	ifc.ifc_buf = buf;
	if (ioctl(s, SIOCGIFCONF, (char *)&ifc) < 0) {
D 25
		perror("rwhod: ioctl (get interface configuration)");
E 25
I 25
		syslog(LOG_ERR, "ioctl (get interface configuration)");
E 25
		return (0);
	}
	ifr = ifc.ifc_req;
	for (n = ifc.ifc_len / sizeof (struct ifreq); n > 0; n--, ifr++) {
		for (np = neighbors; np != NULL; np = np->n_next)
			if (np->n_name &&
			    strcmp(ifr->ifr_name, np->n_name) == 0)
				break;
		if (np != NULL)
			continue;
		ifreq = *ifr;
		np = (struct neighbor *)malloc(sizeof (*np));
		if (np == NULL)
			continue;
		np->n_name = malloc(strlen(ifr->ifr_name) + 1);
		if (np->n_name == NULL) {
			free((char *)np);
			continue;
		}
		strcpy(np->n_name, ifr->ifr_name);
		np->n_addrlen = sizeof (ifr->ifr_addr);
		np->n_addr = malloc(np->n_addrlen);
		if (np->n_addr == NULL) {
			free(np->n_name);
			free((char *)np);
			continue;
		}
		bcopy((char *)&ifr->ifr_addr, np->n_addr, np->n_addrlen);
		if (ioctl(s, SIOCGIFFLAGS, (char *)&ifreq) < 0) {
D 25
			perror("rwhod: ioctl (get interface flags)");
E 25
I 25
			syslog(LOG_ERR, "ioctl (get interface flags)");
E 25
			free((char *)np);
			continue;
		}
D 31
		if ((ifreq.ifr_flags & (IFF_BROADCAST|IFF_POINTOPOINT)) == 0) {
E 31
I 31
		if ((ifreq.ifr_flags & IFF_UP) == 0 ||
		    (ifreq.ifr_flags & (IFF_BROADCAST|IFF_POINTOPOINT)) == 0) {
E 31
			free((char *)np);
			continue;
		}
		np->n_flags = ifreq.ifr_flags;
		if (np->n_flags & IFF_POINTOPOINT) {
			if (ioctl(s, SIOCGIFDSTADDR, (char *)&ifreq) < 0) {
D 25
				perror("rwhod: ioctl (get dstaddr)");
E 25
I 25
				syslog(LOG_ERR, "ioctl (get dstaddr)");
E 25
				free((char *)np);
				continue;
			}
			/* we assume addresses are all the same size */
			bcopy((char *)&ifreq.ifr_dstaddr,
			  np->n_addr, np->n_addrlen);
		}
		if (np->n_flags & IFF_BROADCAST) {
I 31
			if (ioctl(s, SIOCGIFBRDADDR, (char *)&ifreq) < 0) {
				syslog(LOG_ERR, "ioctl (get broadaddr)");
				free((char *)np);
				continue;
			}
E 31
			/* we assume addresses are all the same size */
D 31
			sin = (struct sockaddr_in *)np->n_addr;
D 23
			sin->sin_addr =
			  inet_makeaddr(inet_netof(sin->sin_addr), INADDR_ANY);
E 23
I 23
			sin->sin_addr = inet_makeaddr((np->n_flags & IFF_LOCAL)?
				inet_subnetof(sin->sin_addr) :
				inet_netof(sin->sin_addr),
				INADDR_ANY);
E 31
I 31
			bcopy((char *)&ifreq.ifr_broadaddr,
			  np->n_addr, np->n_addrlen);
E 31
E 23
		}
		/* gag, wish we could get rid of Internet dependencies */
		sin = (struct sockaddr_in *)np->n_addr;
		sin->sin_port = sp->s_port;
		np->n_next = neighbors;
		neighbors = np;
	}
	return (1);
I 23
}

D 35
/*
 * Return the possible subnetwork number from an internet address.
 * If the address is of the form of a subnet address (most significant
 * bit of the host part is set), believe the subnet exists.
 * Otherwise, return the network number.  Any subnet number is only valid
 * if this is a ``local'' net.
 */
inet_subnetof(in)
	struct in_addr in;
{
	register u_long i = ntohl(in.s_addr);

	if (IN_CLASSA(i)) {
		if (IN_SUBNETA(i))
			return ((i & IN_CLASSA_SUBNET) >> IN_CLASSA_SUBNSHIFT);
		else
			return ((i & IN_CLASSA_NET) >> IN_CLASSA_NSHIFT);
	} else if (IN_CLASSB(i)) {
		if (IN_SUBNETB(i))
			return ((i & IN_CLASSB_SUBNET) >> IN_CLASSB_SUBNSHIFT);
		else
			return ((i & IN_CLASSB_NET) >> IN_CLASSB_NSHIFT);
	} else
		return ((i & IN_CLASSC_NET) >> IN_CLASSC_NSHIFT);
E 23
E 9
E 5
}
I 11

E 35
#ifdef DEBUG
sendto(s, buf, cc, flags, to, tolen)
	int s;
	char *buf;
	int cc, flags;
	char *to;
	int tolen;
{
	register struct whod *w = (struct whod *)buf;
	register struct whoent *we;
	struct sockaddr_in *sin = (struct sockaddr_in *)to;
	char *interval();

	printf("sendto %x.%d\n", ntohl(sin->sin_addr), ntohs(sin->sin_port));
	printf("hostname %s %s\n", w->wd_hostname,
D 16
	   interval(w->wd_sendtime - w->wd_boottime, "  up"));
E 16
I 16
	   interval(ntohl(w->wd_sendtime) - ntohl(w->wd_boottime), "  up"));
E 16
	printf("load %4.2f, %4.2f, %4.2f\n",
D 16
	    w->wd_loadav[0] / 100.0, w->wd_loadav[1] / 100.0,
	    w->wd_loadav[2] / 100.0);
E 16
I 16
	    ntohl(w->wd_loadav[0]) / 100.0, ntohl(w->wd_loadav[1]) / 100.0,
	    ntohl(w->wd_loadav[2]) / 100.0);
E 16
	cc -= WHDRSIZE;
	for (we = w->wd_we, cc /= sizeof (struct whoent); cc > 0; cc--, we++) {
I 16
		time_t t = ntohl(we->we_utmp.out_time);
E 16
		printf("%-8.8s %s:%s %.12s",
D 16
			 we->we_utmp.out_name,
			 w->wd_hostname, we->we_utmp.out_line,
			ctime((time_t *)&we->we_utmp.out_time)+4);
		we->we_idle /= 60;
E 16
I 16
			we->we_utmp.out_name,
			w->wd_hostname, we->we_utmp.out_line,
			ctime(&t)+4);
		we->we_idle = ntohl(we->we_idle) / 60;
E 16
		if (we->we_idle) {
			if (we->we_idle >= 100*60)
				we->we_idle = 100*60 - 1;
			if (we->we_idle >= 60)
				printf(" %2d", we->we_idle / 60);
			else
				printf("   ");
			printf(":%02d", we->we_idle % 60);
		}
		printf("\n");
	}
}

char *
interval(time, updown)
	int time;
	char *updown;
{
	static char resbuf[32];
	int days, hours, minutes;

	if (time < 0 || time > 3*30*24*60*60) {
		(void) sprintf(resbuf, "   %s ??:??", updown);
		return (resbuf);
	}
	minutes = (time + 59) / 60;		/* round to minutes */
	hours = minutes / 60; minutes %= 60;
	days = hours / 24; hours %= 24;
	if (days)
		(void) sprintf(resbuf, "%s %2d+%02d:%02d",
		    updown, days, hours, minutes);
	else
		(void) sprintf(resbuf, "%s    %2d:%02d",
		    updown, hours, minutes);
	return (resbuf);
}
#endif
E 11
E 1
