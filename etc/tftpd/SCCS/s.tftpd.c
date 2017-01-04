h50554
s 00022/00008/00610
d D 5.15 05/04/17 10:08:22 msokolov 30 29
x 28 27 26
c backport to 4.3BSD
e
s 00171/00042/00437
d D 5.14 93/02/12 20:19:09 andrew 29 28
c add options for logging, suppressing naks; allow relative file
c searchs, more directory prefixes, minor fixes
e
s 00012/00010/00467
d D 5.13 91/02/26 12:28:37 bostic 28 27
c ANSI fixes
e
s 00001/00011/00476
d D 5.12 90/06/01 15:55:43 bostic 27 26
c new copyright notice
e
s 00005/00005/00482
d D 5.11 90/05/28 12:41:06 bostic 26 25
c sys_errlist -> strerror(3)
e
s 00008/00002/00479
d D 5.10 90/04/30 17:35:56 tef 25 24
c prevent tricksters from getting around directory restrictions
e
s 00018/00002/00463
d D 5.9 88/10/10 22:24:21 tef 24 23
c restrict directories from which files may be accessed
e
s 00010/00005/00455
d D 5.8 88/06/18 14:01:50 bostic 23 22
c install approved copyright notice
e
s 00010/00005/00450
d D 5.7 88/03/28 13:54:47 bostic 22 21
c add Berkeley specific header
e
s 00064/00010/00391
d D 5.6 86/05/13 14:34:29 minshall 21 20
c For and exit so that inetd can have us be a "wait" service. 
c The problem with the old way is that there is a race between tftpd (starting 
c up) and inetd (after forking and execing) to see who gets to read from port 
c 69 (the udp port).  If inetd wins, it will spawn another instance of tftpd. 
c So, we read the packet from port 69, then fork and the parent returns.
e
s 00004/00030/00397
d D 5.5 86/02/07 21:43:43 minshall 20 19
c Only re-synchronize on an error (some implementations may
c well decide to send three or four udp packets before worrying about
c not getting any ACKs from us, so we shouldn't throw away all their
c fine efforts to speed up transfers).
e
s 00042/00002/00385
d D 5.4 86/02/07 14:32:24 minshall 19 18
c Resend data in send, flush input data in send and receive.
e
s 00108/00052/00279
d D 5.3 86/02/07 11:48:12 minshall 18 17
c New version of tftpd (incorporating changes from <guyton@rand-unix>).
e
s 00001/00003/00330
d D 5.2 85/09/17 19:14:25 eric 17 16
c facilities in syslog
e
s 00014/00002/00319
d D 5.1 85/05/28 15:40:54 dist 16 15
c Add copyright
e
s 00007/00003/00314
d D 4.14 84/09/13 11:33:46 ralph 15 14
c use syslog for error messages
e
s 00000/00010/00317
d D 4.13 84/04/12 22:41:08 sam 14 13
c enable fixes
e
s 00058/00086/00269
d D 4.12 84/04/11 15:59:37 karels 13 11
c convert for use with inetd
e
s 00000/00000/00355
d R 4.12 84/04/11 15:37:43 karels 12 11
c convert for inetd
e
s 00005/00003/00350
d D 4.11 83/07/02 00:20:10 sam 11 10
c include fixes
e
s 00000/00001/00353
d D 4.10 83/06/12 02:20:59 sam 10 9
c forgot DEBUG
e
s 00067/00069/00287
d D 4.9 83/06/12 01:36:59 sam 9 8
c lots of cleanups
e
s 00002/00002/00354
d D 4.8 83/05/03 20:55:15 sam 8 7
c move from /usr/src/ucb forces include move to <arpa/tftp.h>
e
s 00001/00001/00355
d D 4.7 82/12/25 21:21:50 sam 7 6
c port numbers now byte swapped
e
s 00001/00001/00355
d D 4.6 82/11/15 18:34:40 sam 6 5
c add domain specification
e
s 00001/00001/00355
d D 4.5 82/11/15 01:26:23 sam 5 4
c recvfrom/sendto flags arg out of order
e
s 00025/00022/00331
d D 4.4 82/11/14 15:21:59 sam 4 3
c convert to 4.1c sys calls and directory layout
e
s 00009/00004/00344
d D 4.3 82/10/08 00:58:33 sam 3 2
c convert to new library routines
e
s 00000/00002/00348
d D 4.2 82/08/19 21:53:46 sam 2 1
c no more debugging please
e
s 00350/00000/00000
d D 4.1 82/08/16 22:20:33 sam 1 0
c date and time created 82/08/16 22:20:33 by sam
e
u
U
t
T
I 16
/*
D 29
 * Copyright (c) 1983 Regents of the University of California.
E 29
I 29
 * Copyright (c) 1983, 1993 Regents of the University of California.
E 29
D 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 22
I 22
 * All rights reserved.
 *
D 27
 * Redistribution and use in source and binary forms are permitted
D 23
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 23
I 23
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 27
I 27
 * %sccs.include.redist.c%
E 27
E 23
E 22
 */

E 16
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
#ifndef lint
D 13
static char sccsid[] = "%W% (Berkeley) %G%";
E 13
I 13
D 16
static	char sccsid[] = "%W% (Berkeley) %G%";
E 13
#endif
E 16
I 16
char copyright[] =
D 29
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 29
I 29
"@(#) Copyright (c) 1983, 1993 Regents of the University of California.\n\
E 29
 All rights reserved.\n";
D 22
#endif not lint
E 22
I 22
#endif /* not lint */
E 22

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 22
#endif not lint
E 16
E 11

E 22
I 22
#endif /* not lint */
E 22
I 18

E 18
/*
 * Trivial file transfer protocol server.
I 18
 *
D 29
 * This version includes many modifications by Jim Guyton <guyton@rand-unix>
E 29
I 29
 * This version includes many modifications by Jim Guyton
 * <guyton@rand-unix>.
E 29
E 18
 */
I 18

E 18
D 29
#include <sys/types.h>
E 29
I 29
#include <sys/param.h>
E 29
D 4
#include <net/in.h>
E 4
D 28
#include <sys/socket.h>
E 28
D 4
#include <signal.h>
E 4
#include <sys/ioctl.h>
I 11
D 28
#include <sys/wait.h>
E 28
#include <sys/stat.h>
I 26
D 28
#include <sys/signal.h>
E 28
I 28
D 29
#include <signal.h>
#include <fcntl.h>
E 28
E 26
E 11
I 4

E 29
I 28
#include <sys/socket.h>
I 29

E 29
E 28
#include <netinet/in.h>
D 28

E 28
I 8
#include <arpa/tftp.h>
D 28

E 28
E 8
D 26
#include <signal.h>
E 26
I 26
D 29
#include <netdb.h>
E 29
I 29
#include <arpa/inet.h>
E 29
I 28

I 29
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
E 29
E 28
#include <setjmp.h>
I 28
D 29
#include <syslog.h>
E 29
I 29
D 30
#include <signal.h>
E 30
I 30
#include <setjmp.h>
E 30
E 29
E 28
E 26
E 4
D 11
#include <stat.h>
E 11
#include <stdio.h>
D 11
#include <wait.h>
E 11
D 29
#include <errno.h>
#include <ctype.h>
I 3
D 26
#include <netdb.h>
I 9
#include <setjmp.h>
E 26
I 15
D 28
#include <syslog.h>
E 28
I 26
#include <string.h>
E 29
I 28
#include <stdlib.h>
I 29
D 30
#include <string.h>
E 30
I 30
#include <strings.h>
E 30
#include <syslog.h>
E 29
E 28
E 26
E 15
E 9
I 4
D 8

E 4
E 3
#include "tftp.h"
E 8

I 29
D 30
#include "pathnames.h"
E 30
I 30
extern int errno;
extern int optind;
E 30

E 29
I 9
D 10
#define	DEBUG	1
E 10
#define	TIMEOUT		5

E 9
D 2
#define	DEBUG		1

E 2
D 29
extern	int errno;
E 29
D 3
struct	sockaddr_in sin = { AF_INET, IPPORT_TFTP };
E 3
I 3
struct	sockaddr_in sin = { AF_INET };
E 3
D 13
int	f;
E 13
I 13
int	peer;
E 13
I 9
int	rexmtval = TIMEOUT;
int	maxtimeout = 5*TIMEOUT;
E 9
D 4
int	options;
E 4
D 18
char	buf[BUFSIZ];
E 18
I 18

#define	PKTSIZE	SEGSIZE+4
char	buf[PKTSIZE];
char	ackbuf[PKTSIZE];
E 18
I 9
D 13
int	reapchild();
E 13
I 13
struct	sockaddr_in from;
int	fromlen;
E 13
E 9

D 13
main(argc, argv)
	char *argv[];
E 13
I 13
D 24
main()
E 24
I 24
D 29
#define MAXARG	4
char	*dirs[MAXARG+1];
E 29
I 29
/*
 * Null-terminated directory prefix list for absolute pathname requests and 
 * search list for relative pathname requests.
 *
 * MAXDIRS should be at least as large as the number of arguments that
 * inetd allows (currently 20).
 */
#define MAXDIRS	20
static struct dirlist {
	char	*name;
	int	len;
} dirs[MAXDIRS+1];
static int	suppress_naks;
static int	logging;
E 29

D 29
main(ac, av)
	char **av;
E 29
I 29
static char *errtomsg();
static char *verifyhost();

main(argc, argv)
	int argc;
	char *argv[];
E 29
E 24
E 13
{
D 9
	union wait status;
E 9
D 13
	struct sockaddr_in from;
E 13
	register struct tftphdr *tp;
D 24
	register int n;
E 24
I 24
D 29
	register int n = 0;
E 24
I 21
	int on = 1;
E 29
I 29
	register int n;
	int ch, on;
E 29
E 21
I 3
D 13
	struct servent *sp;
E 13
E 3

I 24
D 29
	ac--; av++;
	while (ac-- > 0 && n < MAXARG)
		dirs[n++] = *av++;
E 24
I 17
	openlog("tftpd", LOG_PID, LOG_DAEMON);
E 29
I 29
D 30
	openlog("tftpd", LOG_PID, LOG_FTP);
E 30
I 30
	openlog("tftpd", LOG_PID, LOG_DAEMON);
E 30
	while ((ch = getopt(argc, argv, "ln")) != EOF) {
		switch (ch) {
		case 'l':
			logging = 1;
			break;
		case 'n':
			suppress_naks = 1;
			break;
		default:
			syslog(LOG_WARNING, "ignoring unknown option -%c", ch);
		}
	}
	if (optind < argc) {
		struct dirlist *dirp;

		/* Get list of directory prefixes. Skip relative pathnames. */
		for (dirp = dirs; optind < argc && dirp < &dirs[MAXDIRS];
		     optind++) {
			if (argv[optind][0] == '/') {
				dirp->name = argv[optind];
				dirp->len  = strlen(dirp->name);
				dirp++;
			}
		}
	}

	on = 1;
E 29
E 17
I 3
D 13
	sp = getservbyname("tftp", "udp");
	if (sp == 0) {
		fprintf(stderr, "tftpd: udp/tftp: unknown service\n");
E 13
I 13
D 21
	alarm(10);
E 21
I 21
	if (ioctl(0, FIONBIO, &on) < 0) {
		syslog(LOG_ERR, "ioctl(FIONBIO): %m\n");
		exit(1);
	}
E 21
	fromlen = sizeof (from);
	n = recvfrom(0, buf, sizeof (buf), 0,
D 28
	    (caddr_t)&from, &fromlen);
E 28
I 28
	    (struct sockaddr *)&from, &fromlen);
E 28
	if (n < 0) {
D 21
		perror("tftpd: recvfrom");
E 21
I 21
		syslog(LOG_ERR, "recvfrom: %m\n");
E 21
E 13
		exit(1);
	}
I 21
	/*
	 * Now that we have read the message out of the UDP
	 * socket, we fork and exit.  Thus, inetd will go back
	 * to listening to the tftp port, and the next request
	 * to come in will start up a new instance of tftpd.
	 *
	 * We do this so that inetd can run tftpd in "wait" mode.
	 * The problem with tftpd running in "nowait" mode is that
	 * inetd may get one or more successful "selects" on the
	 * tftp port before we do our receive, so more than one
	 * instance of tftpd may be started up.  Worse, if tftpd
	 * break before doing the above "recvfrom", inetd would
	 * spawn endless instances, clogging the system.
	 */
	{
		int pid;
		int i, j;

		for (i = 1; i < 20; i++) {
		    pid = fork();
		    if (pid < 0) {
				sleep(i);
				/*
				 * flush out to most recently sent request.
				 *
				 * This may drop some request, but those
				 * will be resent by the clients when
				 * they timeout.  The positive effect of
				 * this flush is to (try to) prevent more
				 * than one tftpd being started up to service
				 * a single request from a single client.
				 */
				j = sizeof from;
				i = recvfrom(0, buf, sizeof (buf), 0,
D 28
				    (caddr_t)&from, &j);
E 28
I 28
				    (struct sockaddr *)&from, &j);
E 28
				if (i > 0) {
					n = i;
					fromlen = j;
				}
		    } else {
				break;
		    }
		}
		if (pid < 0) {
			syslog(LOG_ERR, "fork: %m\n");
			exit(1);
		} else if (pid != 0) {
			exit(0);
		}
	}
E 21
D 4
	sin.sin_port = htons(sp->s_port);
E 4
I 4
D 7
	sin.sin_port = htons((u_short)sp->s_port);
E 7
I 7
D 13
	sin.sin_port = sp->s_port;
E 7
E 4
E 3
#ifndef DEBUG
E 13
I 13
	from.sin_family = AF_INET;
	alarm(0);
D 14
#ifdef do_it_right_and_use_a_new_port
E 13
	if (fork())
		exit(0);
E 14
D 13
	for (f = 0; f < 10; f++)
		(void) close(f);
	(void) open("/", 0);
	(void) dup2(0, 1);
	(void) dup2(0, 2);
	{ int t = open("/dev/tty", 2);
	  if (t >= 0) {
		ioctl(t, TIOCNOTTY, (char *)0);
		(void) close(t);
	  }
E 13
I 13
	close(0);
	close(1);
	peer = socket(AF_INET, SOCK_DGRAM, 0);
	if (peer < 0) {
D 15
		perror("tftpd: socket");
E 15
I 15
D 17
		openlog("tftpd", LOG_PID, 0);
E 17
D 21
		syslog(LOG_ERR, "socket: %m");
E 21
I 21
		syslog(LOG_ERR, "socket: %m\n");
E 21
E 15
		exit(1);
E 13
	}
I 13
D 28
	if (bind(peer, (caddr_t)&sin, sizeof (sin)) < 0) {
E 28
I 28
	if (bind(peer, (struct sockaddr *)&sin, sizeof (sin)) < 0) {
E 28
D 15
		perror("tftpd: bind");
E 15
I 15
D 17
		openlog("tftpd", LOG_PID, 0);
E 17
D 21
		syslog(LOG_ERR, "bind: %m");
E 21
I 21
		syslog(LOG_ERR, "bind: %m\n");
E 21
E 15
		exit(1);
	}
D 14
#else
	/*
	 * The current 4.2 tftp client neglects to switch its destination
	 * port after the first ACK.
	 */
	peer = 0;
E 13
D 3
#endif
#if vax || pdp11
	sin.sin_port = htons(sin.sin_port);
E 3
#endif
E 14
I 9
D 13
	signal(SIGCHLD, reapchild);
E 9
D 4
	argc--, argv++;
	if (argc > 0 && !strcmp(argv[0], "-d"))
		options |= SO_DEBUG;
E 4
	for (;;) {
D 4
		errno = 0;
		f = socket(SOCK_DGRAM, 0, &sin, options);
E 4
I 4
		int fromlen;

D 6
		f = socket(0, SOCK_DGRAM, 0, 0);
E 6
I 6
D 9
		f = socket(AF_INET, SOCK_DGRAM, 0, 0);
E 9
I 9
		f = socket(AF_INET, SOCK_DGRAM, 0);
E 9
E 6
E 4
		if (f < 0) {
D 4
			perror("socket");
E 4
I 4
			perror("tftpd: socket");
D 9
			close(f);
E 9
E 4
			sleep(5);
			continue;
		}
I 9
		if (setsockopt(f, SOL_SOCKET, SO_REUSEADDR, 0, 0) < 0)
			perror("tftpd: setsockopt (SO_REUSEADDR)");
		sleep(1);			/* let child do connect */
E 9
I 4
		while (bind(f, (caddr_t)&sin, sizeof (sin), 0) < 0) {
			perror("tftpd: bind");
D 9
			close(f);
E 9
			sleep(5);
D 9
			continue;
E 9
		}
E 4
D 9
again:
D 4
		n = receive(f, &from, buf, sizeof (buf));
E 4
I 4
		fromlen = sizeof (from);
D 5
		n = recvfrom(f, buf, sizeof (buf), (caddr_t)&from, &fromlen, 0);
E 5
I 5
		n = recvfrom(f, buf, sizeof (buf), 0, (caddr_t)&from, &fromlen);
E 5
E 4
		if (n <= 0) {
			if (n < 0)
D 4
				perror("receive");
E 4
I 4
				perror("tftpd: recvfrom");
E 4
			goto again;
		}
E 9
I 9
		do {
			fromlen = sizeof (from);
			n = recvfrom(f, buf, sizeof (buf), 0,
			    (caddr_t)&from, &fromlen);
		} while (n <= 0);
E 9
		tp = (struct tftphdr *)buf;
D 4
#if vax || pdp11
E 4
		tp->th_opcode = ntohs(tp->th_opcode);
D 4
#endif
E 4
		if (tp->th_opcode == RRQ || tp->th_opcode == WRQ)
			if (fork() == 0)
				tftp(&from, tp, n);
		(void) close(f);
E 13
I 13
D 28
	if (connect(peer, (caddr_t)&from, sizeof(from)) < 0) {
E 28
I 28
	if (connect(peer, (struct sockaddr *)&from, sizeof(from)) < 0) {
E 28
D 15
		perror("tftpd: connect");
E 15
I 15
D 17
		openlog("tftpd", LOG_PID, 0);
E 17
D 21
		syslog(LOG_ERR, "connect: %m");
E 21
I 21
		syslog(LOG_ERR, "connect: %m\n");
E 21
E 15
		exit(1);
E 13
D 4
#ifdef notdef
E 4
D 9
		while (wait3(status, WNOHANG, 0) > 0)
D 4
#else
		while (wait3(status, 0, 0) > 0)
E 4
			continue;
E 9
	}
I 13
	tp = (struct tftphdr *)buf;
	tp->th_opcode = ntohs(tp->th_opcode);
	if (tp->th_opcode == RRQ || tp->th_opcode == WRQ)
		tftp(tp, n);
	exit(1);
E 13
}

I 9
D 13
reapchild()
{
	union wait status;

	while (wait3(&status, WNOHANG, 0) > 0)
		;
}

E 13
E 9
int	validate_access();
int	sendfile(), recvfile();

struct formats {
	char	*f_mode;
	int	(*f_validate)();
	int	(*f_send)();
	int	(*f_recv)();
I 18
	int	f_convert;
E 18
} formats[] = {
D 18
	{ "netascii",	validate_access,	sendfile,	recvfile },
	{ "octet",	validate_access,	sendfile,	recvfile },
E 18
I 18
	{ "netascii",	validate_access,	sendfile,	recvfile, 1 },
	{ "octet",	validate_access,	sendfile,	recvfile, 0 },
E 18
#ifdef notdef
D 18
	{ "mail",	validate_user,		sendmail,	recvmail },
E 18
I 18
	{ "mail",	validate_user,		sendmail,	recvmail, 1 },
E 18
#endif
	{ 0 }
};

D 13
int	fd;			/* file being transferred */

E 13
/*
 * Handle initial connection protocol.
 */
D 13
tftp(client, tp, size)
	struct sockaddr_in *client;
E 13
I 13
tftp(tp, size)
E 13
	struct tftphdr *tp;
	int size;
{
	register char *cp;
	int first = 1, ecode;
	register struct formats *pf;
	char *filename, *mode;

D 4
	if (connect(f, client) < 0) {
E 4
I 4
D 13
	if (connect(f, (caddr_t)client, sizeof (*client), 0) < 0) {
E 4
		perror("connect");
		exit(1);
	}
E 13
	filename = cp = tp->th_stuff;
again:
	while (cp < buf + size) {
		if (*cp == '\0')
			break;
		cp++;
	}
	if (*cp != '\0') {
		nak(EBADOP);
		exit(1);
	}
	if (first) {
		mode = ++cp;
		first = 0;
		goto again;
	}
	for (cp = mode; *cp; cp++)
		if (isupper(*cp))
			*cp = tolower(*cp);
	for (pf = formats; pf->f_mode; pf++)
		if (strcmp(pf->f_mode, mode) == 0)
			break;
	if (pf->f_mode == 0) {
		nak(EBADOP);
		exit(1);
	}
D 13
	ecode = (*pf->f_validate)(filename, client, tp->th_opcode);
E 13
I 13
D 29
	ecode = (*pf->f_validate)(filename, tp->th_opcode);
E 29
I 29
	ecode = (*pf->f_validate)(&filename, tp->th_opcode);
	if (logging) {
		syslog(LOG_INFO, "%s: %s request for %s: %s",
			verifyhost(&from),
			tp->th_opcode == WRQ ? "write" : "read",
			filename, errtomsg(ecode));
	}
E 29
E 13
	if (ecode) {
I 29
		/*
		 * Avoid storms of naks to a RRQ broadcast for a relative
		 * bootfile pathname from a diskless Sun.
		 */
		if (suppress_naks && *filename != '/' && ecode == ENOTFOUND)
			exit(0);
E 29
		nak(ecode);
		exit(1);
	}
	if (tp->th_opcode == WRQ)
		(*pf->f_recv)(pf);
	else
		(*pf->f_send)(pf);
	exit(0);
}

I 13
D 18
int	fd;
E 18

I 18
FILE *file;

E 18
E 13
/*
 * Validate file access.  Since we
 * have no uid or gid, for now require
 * file to exist and be publicly
 * readable/writable.
I 24
 * If we were invoked with arguments
 * from inetd then the file must also be
 * in one of the given directory prefixes.
E 24
 * Note also, full path name must be
 * given as we have no login directory.
 */
D 13
validate_access(file, client, mode)
E 13
I 13
D 18
validate_access(file, mode)
E 13
	char *file;
E 18
I 18
D 29
validate_access(filename, mode)
	char *filename;
E 29
I 29
validate_access(filep, mode)
	char **filep;
E 29
E 18
D 13
	struct sockaddr_in *client;
E 13
	int mode;
{
	struct stat stbuf;
I 18
	int	fd;
I 24
D 25
	char **dirp = dirs;
E 25
I 25
D 29
	char *cp, **dirp;
E 29
I 29
	struct dirlist *dirp;
	static char pathname[MAXPATHLEN];
	char *filename = *filep;
E 29
E 25
E 24
E 18

D 18
	if (*file != '/')
E 18
I 18
D 29
	if (*filename != '/')
I 24
		return (EACCESS);
E 29
D 25
	for (; *dirp; dirp++)
E 25
I 25
	/*
D 29
	 * prevent tricksters from getting around the directory restrictions
E 29
I 29
	 * Prevent tricksters from getting around the directory restrictions
E 29
	 */
D 29
	for (cp = filename + 1; *cp; cp++)
		if(*cp == '.' && strncmp(cp-1, "/../", 4) == 0)
			return(EACCESS);
	for (dirp = dirs; *dirp; dirp++)
E 25
		if (strncmp(filename, *dirp, strlen(*dirp)) == 0)
			break;
	if (*dirp==0 && dirp!=dirs)
E 29
I 29
D 30
	if (strstr(filename, "/../"))
E 30
I 30
	if (hasdotdot(filename))
E 30
E 29
E 24
E 18
		return (EACCESS);
D 18
	if (stat(file, &stbuf) < 0)
E 18
I 18
D 29
	if (stat(filename, &stbuf) < 0)
E 18
		return (errno == ENOENT ? ENOTFOUND : EACCESS);
	if (mode == RRQ) {
		if ((stbuf.st_mode&(S_IREAD >> 6)) == 0)
E 29
I 29

	if (*filename == '/') {
		/*
		 * Allow the request if it's in one of the approved locations.
		 * Special case: check the null prefix ("/") by looking 
		 * for length = 1 and relying on the arg. processing that
		 * it's a /.
		 */
		for (dirp = dirs; dirp->name != NULL; dirp++) {
			if (dirp->len == 1 ||
			    (!strncmp(filename, dirp->name, dirp->len) &&
			     filename[dirp->len] == '/'))
				    break;
		}
		/* If directory list is empty, allow access to any file */
		if (dirp->name == NULL && dirp != dirs)
E 29
			return (EACCESS);
I 29
		if (stat(filename, &stbuf) < 0)
			return (errno == ENOENT ? ENOTFOUND : EACCESS);
		if ((stbuf.st_mode & S_IFMT) != S_IFREG)
			return (ENOTFOUND);
		if (mode == RRQ) {
D 30
			if ((stbuf.st_mode & S_IROTH) == 0)
E 30
I 30
			if ((stbuf.st_mode & 04) == 0)
E 30
				return (EACCESS);
		} else {
D 30
			if ((stbuf.st_mode & S_IWOTH) == 0)
E 30
I 30
			if ((stbuf.st_mode & 02) == 0)
E 30
				return (EACCESS);
		}
E 29
	} else {
D 29
		if ((stbuf.st_mode&(S_IWRITE >> 6)) == 0)
E 29
I 29
		int err;

		/* 
		 * Relative file name: search the approved locations for it.
		 * Don't allow write requests or ones that avoid directory
		 * restrictions.
		 */

		if (mode != RRQ || !strncmp(filename, "../", 3))
E 29
			return (EACCESS);
I 29

		/*
		 * If the file exists in one of the directories and isn't
		 * readable, continue looking. However, change the error code 
		 * to give an indication that the file exists.
		 */
		err = ENOTFOUND;
		for (dirp = dirs; dirp->name != NULL; dirp++) {
			sprintf(pathname, "%s/%s", dirp->name, filename);
			if (stat(pathname, &stbuf) == 0 &&
			    (stbuf.st_mode & S_IFMT) == S_IFREG) {
D 30
				if ((stbuf.st_mode & S_IROTH) != 0) {
E 30
I 30
				if ((stbuf.st_mode & 04) != 0) {
E 30
					break;
				}
				err = EACCESS;
			}
		}
		if (dirp->name == NULL)
			return (err);
		*filep = filename = pathname;
E 29
	}
D 18
	fd = open(file, mode == RRQ ? 0 : 1);
E 18
I 18
	fd = open(filename, mode == RRQ ? 0 : 1);
E 18
	if (fd < 0)
		return (errno + 100);
I 18
	file = fdopen(fd, (mode == RRQ)? "r":"w");
	if (file == NULL) {
		return errno+100;
	}
E 18
	return (0);
}

D 9
int timeout;
E 9
I 9
int	timeout;
jmp_buf	timeoutbuf;
E 9

I 28
void
E 28
timer()
{
D 9
	timeout += TIMEOUT;
	if (timeout >= MAXTIMEOUT)
E 9
I 9

	timeout += rexmtval;
	if (timeout >= maxtimeout)
E 9
		exit(1);
D 9
	alarm(TIMEOUT);
E 9
I 9
	longjmp(timeoutbuf, 1);
E 9
}

/*
 * Send the requested file.
 */
sendfile(pf)
D 18
	struct format *pf;
E 18
I 18
	struct formats *pf;
E 18
{
D 18
	register struct tftphdr *tp;
E 18
I 18
	struct tftphdr *dp, *r_init();
	register struct tftphdr *ap;    /* ack packet */
E 18
	register int block = 1, size, n;

D 9
	sigset(SIGALRM, timer);
E 9
I 9
	signal(SIGALRM, timer);
E 9
D 18
	tp = (struct tftphdr *)buf;
E 18
I 18
	dp = r_init();
	ap = (struct tftphdr *)ackbuf;
E 18
	do {
D 18
		size = read(fd, tp->th_data, SEGSIZE);
E 18
I 18
		size = readit(file, &dp, pf->f_convert);
E 18
		if (size < 0) {
			nak(errno + 100);
D 9
			break;
E 9
I 9
D 13
			goto abort;
E 13
I 13
D 18
			return;
E 18
I 18
			goto abort;
E 18
E 13
E 9
		}
D 18
		tp->th_opcode = htons((u_short)DATA);
		tp->th_block = htons((u_short)block);
E 18
I 18
		dp->th_opcode = htons((u_short)DATA);
		dp->th_block = htons((u_short)block);
E 18
		timeout = 0;
D 9
		alarm(TIMEOUT);
rexmt:
E 9
I 9
		(void) setjmp(timeoutbuf);
E 9
D 13
		if (write(f, buf, size + 4) != size + 4) {
D 9
			perror("send");
			break;
E 9
I 9
			perror("tftpd: write");
			goto abort;
E 13
I 13
D 18
		if (send(peer, buf, size + 4, 0) != size + 4) {
			perror("tftpd: send");
			return;
E 18
I 18

I 19
send_data:
D 20
		/* Now, we flush anything pending to be read */
		/* This is to try to keep in synch between the two sides */
		while (1) {
			int i;
			char rbuf[PKTSIZE];

			(void) ioctl(peer, FIONREAD, &i);
			if (i) {
				fromlen = sizeof from;
				n = recvfrom(peer, rbuf, sizeof (rbuf), 0,
					(caddr_t)&from, &fromlen);
			} else {
				break;
			}
		}
E 20
E 19
		if (send(peer, dp, size + 4, 0) != size + 4) {
D 21
			perror("tftpd: write");
E 21
I 21
			syslog(LOG_ERR, "tftpd: write: %m\n");
E 21
			goto abort;
E 18
E 13
E 9
		}
I 18
		read_ahead(file, pf->f_convert);
E 18
D 9
again:
		n = read(f, buf, sizeof (buf));
		if (n <= 0) {
			if (n == 0)
				goto again;
			if (errno == EINTR)
				goto rexmt;
E 9
I 9
D 19
		do {
E 19
I 19
		for ( ; ; ) {
E 19
D 18
			alarm(rexmtval);
D 13
			n = read(f, buf, sizeof (buf));
E 13
I 13
			n = recv(peer, buf, sizeof (buf), 0);
E 18
I 18
			alarm(rexmtval);        /* read the ack */
			n = recv(peer, ackbuf, sizeof (ackbuf), 0);
E 18
E 13
E 9
			alarm(0);
D 9
			perror("receive");
			break;
		}
		alarm(0);
#if vax || pdp11
D 4
		tp->th_opcode = ntohs(tp->th_opcode);
		tp->th_block = ntohs(tp->th_block);
E 4
I 4
		tp->th_opcode = ntohs((u_short)tp->th_opcode);
		tp->th_block = ntohs((u_short)tp->th_block);
E 4
#endif
		if (tp->th_opcode == ERROR)
			break;
		if (tp->th_opcode != ACK || tp->th_block != block)
			goto again;
E 9
I 9
			if (n < 0) {
D 13
				perror("tftpd: read");
				goto abort;
E 13
I 13
D 18
				perror("tftpd: recv");
				return;
E 18
I 18
D 21
				perror("tftpd: read");
E 21
I 21
				syslog(LOG_ERR, "tftpd: read: %m\n");
E 21
				goto abort;
E 18
E 13
			}
D 18
			tp->th_opcode = ntohs((u_short)tp->th_opcode);
			tp->th_block = ntohs((u_short)tp->th_block);
			if (tp->th_opcode == ERROR)
D 13
				goto abort;
E 13
I 13
				return;
E 13
		} while (tp->th_opcode != ACK || tp->th_block != block);
E 18
I 18
			ap->th_opcode = ntohs((u_short)ap->th_opcode);
			ap->th_block = ntohs((u_short)ap->th_block);

			if (ap->th_opcode == ERROR)
				goto abort;
I 19
			
			if (ap->th_opcode == ACK) {
				if (ap->th_block == block) {
					break;
				}
I 20
				/* Re-synchronize with the other side */
				(void) synchnet(peer);
E 20
				if (ap->th_block == (block -1)) {
					goto send_data;
				}
			}
E 19

D 19
		}  while (ap->th_opcode != ACK || ap->th_block != block);
E 19
I 19
		}
E 19
E 18
E 9
		block++;
	} while (size == SEGSIZE);
I 18
abort:
	(void) fclose(file);
E 18
I 9
D 13
abort:
E 9
	(void) close(fd);
E 13
}

I 28
void
E 28
I 18
justquit()
{
	exit(0);
}


E 18
/*
 * Receive a file.
 */
recvfile(pf)
D 18
	struct format *pf;
E 18
I 18
	struct formats *pf;
E 18
{
D 18
	register struct tftphdr *tp;
E 18
I 18
	struct tftphdr *dp, *w_init();
	register struct tftphdr *ap;    /* ack buffer */
E 18
	register int block = 0, n, size;

D 9
	sigset(SIGALRM, timer);
E 9
I 9
	signal(SIGALRM, timer);
E 9
D 18
	tp = (struct tftphdr *)buf;
E 18
I 18
	dp = w_init();
	ap = (struct tftphdr *)ackbuf;
E 18
	do {
		timeout = 0;
D 9
		alarm(TIMEOUT);
E 9
D 18
		tp->th_opcode = htons((u_short)ACK);
		tp->th_block = htons((u_short)block);
E 18
I 18
		ap->th_opcode = htons((u_short)ACK);
		ap->th_block = htons((u_short)block);
E 18
		block++;
D 9
rexmt:
E 9
I 9
		(void) setjmp(timeoutbuf);
E 9
D 13
		if (write(f, buf, 4) != 4) {
D 9
			perror("ack");
			break;
E 9
I 9
			perror("tftpd: write");
E 13
I 13
D 18
		if (send(peer, buf, 4, 0) != 4) {
			perror("tftpd: send");
E 18
I 18
send_ack:
I 19
D 20
		/* Now, we flush anything pending to be read */
		/* This is to try to keep in synch between the two sides */
		while (1) {
			int i;
			char rbuf[PKTSIZE];

			(void) ioctl(peer, FIONREAD, &i);
			if (i) {
				fromlen = sizeof from;
				n = recvfrom(peer, rbuf, sizeof (rbuf), 0,
					(caddr_t)&from, &fromlen);
			} else {
				break;
			}
		}
E 20
E 19
		if (send(peer, ackbuf, 4, 0) != 4) {
D 21
			perror("tftpd: write");
E 21
I 21
			syslog(LOG_ERR, "tftpd: write: %m\n");
E 21
E 18
E 13
			goto abort;
E 9
		}
D 9
again:
		n = read(f, buf, sizeof (buf));
		if (n <= 0) {
			if (n == 0)
				goto again;
			if (errno == EINTR)
				goto rexmt;
E 9
I 9
D 18
		do {
E 18
I 18
		write_behind(file, pf->f_convert);
		for ( ; ; ) {
E 18
			alarm(rexmtval);
D 13
			n = read(f, buf, sizeof (buf));
E 13
I 13
D 18
			n = recv(peer, buf, sizeof (buf), 0);
E 18
I 18
			n = recv(peer, dp, PKTSIZE, 0);
E 18
E 13
E 9
			alarm(0);
D 9
			perror("receive");
			break;
		}
		alarm(0);
#if vax || pdp11
D 4
		tp->th_opcode = ntohs(tp->th_opcode);
		tp->th_block = ntohs(tp->th_block);
E 4
I 4
		tp->th_opcode = ntohs((u_short)tp->th_opcode);
		tp->th_block = ntohs((u_short)tp->th_block);
E 4
#endif
		if (tp->th_opcode == ERROR)
			break;
		if (tp->th_opcode != DATA || block != tp->th_block)
			goto again;
E 9
I 9
D 18
			if (n < 0) {
D 13
				perror("tftpd: read");
E 13
I 13
				perror("tftpd: recv");
E 18
I 18
			if (n < 0) {            /* really? */
D 21
				perror("tftpd: read");
E 21
I 21
				syslog(LOG_ERR, "tftpd: read: %m\n");
E 21
E 18
E 13
				goto abort;
			}
D 18
			tp->th_opcode = ntohs((u_short)tp->th_opcode);
			tp->th_block = ntohs((u_short)tp->th_block);
			if (tp->th_opcode == ERROR)
E 18
I 18
			dp->th_opcode = ntohs((u_short)dp->th_opcode);
			dp->th_block = ntohs((u_short)dp->th_block);
			if (dp->th_opcode == ERROR)
E 18
				goto abort;
D 18
		} while (tp->th_opcode != DATA || block != tp->th_block);
E 9
		size = write(fd, tp->th_data, n - 4);
		if (size < 0) {
			nak(errno + 100);
E 18
I 18
			if (dp->th_opcode == DATA) {
				if (dp->th_block == block) {
					break;   /* normal */
				}
I 20
				/* Re-synchronize with the other side */
				(void) synchnet(peer);
E 20
				if (dp->th_block == (block-1))
					goto send_ack;          /* rexmit */
			}
		}
		/*  size = write(file, dp->th_data, n - 4); */
		size = writeit(file, &dp, n - 4, pf->f_convert);
		if (size != (n-4)) {                    /* ahem */
			if (size < 0) nak(errno + 100);
			else nak(ENOSPACE);
E 18
D 9
			break;
E 9
I 9
			goto abort;
E 9
		}
	} while (size == SEGSIZE);
I 18
	write_behind(file, pf->f_convert);
	(void) fclose(file);            /* close data file */

	ap->th_opcode = htons((u_short)ACK);    /* send the "final" ack */
	ap->th_block = htons((u_short)(block));
	(void) send(peer, ackbuf, 4, 0);

	signal(SIGALRM, justquit);      /* just quit on timeout */
	alarm(rexmtval);
	n = recv(peer, buf, sizeof (buf), 0); /* normally times out and quits */
	alarm(0);
	if (n >= 4 &&                   /* if read some data */
	    dp->th_opcode == DATA &&    /* and got a data block */
	    block == dp->th_block) {	/* then my last ack was lost */
		(void) send(peer, ackbuf, 4, 0);     /* resend final ack */
	}
E 18
I 9
abort:
E 9
D 18
	tp->th_opcode = htons((u_short)ACK);
	tp->th_block = htons((u_short)(block));
D 13
	(void) write(f, buf, 4);
	(void) close(fd);
E 13
I 13
	(void) send(peer, buf, 4, 0);
E 18
I 18
	return;
E 18
E 13
}

struct errmsg {
	int	e_code;
	char	*e_msg;
} errmsgs[] = {
	{ EUNDEF,	"Undefined error code" },
	{ ENOTFOUND,	"File not found" },
	{ EACCESS,	"Access violation" },
	{ ENOSPACE,	"Disk full or allocation exceeded" },
	{ EBADOP,	"Illegal TFTP operation" },
	{ EBADID,	"Unknown transfer ID" },
	{ EEXISTS,	"File already exists" },
	{ ENOUSER,	"No such user" },
	{ -1,		0 }
};

I 29
static char *
errtomsg(error)
	int error;
{
	static char buf[20];
	register struct errmsg *pe;
	if (error == 0)
		return "success";
	for (pe = errmsgs; pe->e_code >= 0; pe++)
		if (pe->e_code == error)
			return pe->e_msg;
	sprintf(buf, "error %d", error);
	return buf;
}

E 29
/*
 * Send a nak packet (error message).
 * Error code passed in is one of the
 * standard TFTP codes, or a UNIX errno
 * offset by 100.
 */
nak(error)
	int error;
{
	register struct tftphdr *tp;
	int length;
	register struct errmsg *pe;
D 26
	extern char *sys_errlist[];
E 26

	tp = (struct tftphdr *)buf;
	tp->th_opcode = htons((u_short)ERROR);
	tp->th_code = htons((u_short)error);
	for (pe = errmsgs; pe->e_code >= 0; pe++)
		if (pe->e_code == error)
			break;
D 18
	if (pe->e_code < 0)
E 18
I 18
	if (pe->e_code < 0) {
E 18
D 26
		pe->e_msg = sys_errlist[error - 100];
E 26
I 26
		pe->e_msg = strerror(error - 100);
E 26
I 18
		tp->th_code = EUNDEF;   /* set 'undef' errorcode */
	}
E 18
	strcpy(tp->th_msg, pe->e_msg);
	length = strlen(pe->e_msg);
	tp->th_msg[length] = '\0';
	length += 5;
D 13
	if (write(f, buf, length) != length)
E 13
I 13
	if (send(peer, buf, length, 0) != length)
E 13
D 21
		perror("nak");
E 21
I 21
		syslog(LOG_ERR, "nak: %m\n");
I 29
}

static char *
verifyhost(fromp)
	struct sockaddr_in *fromp;
{
	struct hostent *hp;

	hp = gethostbyaddr((char *)&fromp->sin_addr, sizeof (fromp->sin_addr),
			    fromp->sin_family);
	if (hp)
		return hp->h_name;
	else
		return inet_ntoa(fromp->sin_addr);
I 30
}

hasdotdot(str)
	char *str;
{
	register char *cp;

	for (cp = str; cp = index(cp, '/'); ) {
		cp++;
		if (!strncmp(cp, "../", 3))
			return(1);
	}
	return(0);
E 30
E 29
E 21
I 13
D 18
	exit(1);
E 18
E 13
}
E 1
