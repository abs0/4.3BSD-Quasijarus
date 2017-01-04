h53391
s 00014/00009/00107
d D 5.6 88/06/18 13:58:34 bostic 14 13
c install approved copyright notice
e
s 00010/00004/00106
d D 5.5 88/02/08 10:44:41 karels 13 12
c new copyrights
e
s 00002/00000/00108
d D 5.4 88/02/08 10:42:59 karels 12 11
c new imp headers
e
s 00009/00003/00099
d D 5.3 86/06/25 13:38:13 karels 11 10
c don't close the good descriptors; use syslog
e
s 00012/00012/00090
d D 5.2 86/05/05 19:32:07 karels 10 9
c update and correct; add -r to implog
e
s 00013/00001/00089
d D 5.1 85/05/28 14:49:47 dist 9 8
c Add copyright
e
s 00001/00001/00089
d D 4.8 83/07/01 23:59:06 sam 8 7
c include fix
e
s 00001/00001/00089
d D 4.7 83/06/12 02:46:47 sam 7 6
c new signals
e
s 00005/00003/00085
d D 4.6 83/05/05 16:26:41 sam 6 5
c was crazy before
e
s 00012/00011/00076
d D 4.5 82/11/15 11:48:20 sam 5 4
c convert to 4.1c
e
s 00003/00001/00084
d D 4.4 82/11/14 15:07:07 sam 4 3
c add sccsid stuff
e
s 00018/00017/00067
d D 4.3 82/11/14 15:05:00 sam 3 2
c conversion to 4.1c sys calls and directory structure + misc 
c 	cleanups
e
s 00014/00004/00070
d D 4.2 82/10/10 16:35:30 sam 2 1
c start up cleanly
e
s 00074/00000/00000
d D 4.1 82/04/04 19:30:19 sam 1 0
c date and time created 82/04/04 19:30:19 by sam
e
u
U
t
T
I 9
/*
D 13
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
D 14
 * Copyright (c) 1983,1988 Regents of the University of California.
E 14
I 14
 * Copyright (c) 1983, 1988 Regents of the University of California.
E 14
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
E 13
 */

E 9
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
D 4
/*	implogd.c	4.2	82/10/10	*/
E 4
I 4
#ifndef lint
I 9
char copyright[] =
D 13
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 13
I 13
D 14
"%Z% Copyright (c) 1983,1988 Regents of the University of California.\n\
E 14
I 14
"%Z% Copyright (c) 1983, 1988 Regents of the University of California.\n\
E 14
E 13
 All rights reserved.\n";
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14

#ifndef lint
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif
E 9
I 9
D 14
#endif not lint
E 14
I 14
#endif /* not lint */
E 14
E 9
E 4
E 3

D 8
#include <time.h>
E 8
#include <sgtty.h>
I 3

I 8
#include <sys/time.h>
E 8
E 3
D 5
#include <sys/types.h>
E 5
I 5
#include <sys/param.h>
E 5
#include <sys/socket.h>
I 11
#include <sys/syslog.h>
E 11
I 5
#include <sys/file.h>
E 5
D 3
#include <net/in.h>
E 3

I 12
#include <net/if.h>

E 12
I 3
#include <netinet/in.h>
I 5
#include <netimp/if_imp.h>
E 5

E 3
#define	LOGFILE	"/usr/adm/implog"
D 5
#define	IMPMTU	((8159 / 8) & ~01)
E 5

u_char	request[1024];
int	marktime();
int	options;
extern	int errno;
int	log;

/*
 * Socket address, internet style, with
 * unused space taken by timestamp and packet
 * size.
 */
struct sockstamp {
	short	sin_family;
	u_short	sin_port;
	struct	in_addr sin_addr;
	time_t	sin_time;
D 3
	int	sin_cc;
E 3
I 3
	int	sin_len;
E 3
};

D 3
struct	sockproto improto = { PF_IMPLINK, 0 };
struct	sockstamp from;

E 3
main(argc, argv)
	char *argv[];
{
D 3
	int s, cc;
E 3
I 3
D 11
	int s;
E 11
I 11
	int i, s;
E 11
E 3
	time_t t;
I 3
	struct sockstamp from;
E 3

	argc--, argv++;
I 11
	openlog("implogd", LOG_PID | LOG_ODELAY, LOG_DAEMON);
E 11
	if (argc > 0 && !strcmp(argv[0], "-d"))
		options |= SO_DEBUG;
I 10
	log = open(LOGFILE, O_CREAT|O_WRONLY|O_APPEND, 0644);
	if (log < 0) {
I 11
		syslog(LOG_ERR, "%s: %m\n", LOGFILE);
E 11
		perror("implogd: open");
		exit(1);
	}
	from.sin_time = time(0);
	from.sin_len = sizeof (time_t);
	write(log, (char *)&from, sizeof (from));
	if ((s = socket(AF_IMPLINK, SOCK_RAW, 0)) < 0) {
I 11
		syslog(LOG_ERR, "socket: %m\n");
E 11
		perror("implogd: socket");
		exit(5);
	}
E 10
D 2
	s = open("/dev/tty", 2);
	if (s >= 0) {
		ioctl(s, TIOCNOTTY, 0);
		close(s);
E 2
I 2
#ifndef DEBUG
	if (fork())
		exit(0);
D 11
	for (s = 0; s < 10; s++)
		(void) close(t);
E 11
I 11
	for (i = 0; i < 10; i++)
		if (i != log && i != s)
			(void) close(i);
E 11
	(void) open("/", 0);
	(void) dup2(0, 1);
	(void) dup2(0, 2);
	{ int tt = open("/dev/tty", 2);
	  if (tt > 0) {
		ioctl(tt, TIOCNOTTY, 0);
		close(tt);
	  }
E 2
	}
I 2
#endif
E 2
D 5
	log = open(LOGFILE, 1);
	if (log < 0)
E 5
I 5
D 7
	log = open(LOGFILE, FCREATE|FWRONLY|FAPPEND, 0644);
E 7
I 7
D 10
	log = open(LOGFILE, O_CREAT|O_WRONLY|O_APPEND, 0644);
E 7
	if (log < 0) {
		perror("implogd: open");
E 5
		exit(1);
D 5
	lseek(log, 0L, 2);
E 5
I 5
	}
E 5
	from.sin_time = time(0);
D 3
	from.sin_cc = sizeof(time_t);
	write(log, (char *)&from, sizeof(from));
E 3
I 3
	from.sin_len = sizeof (time_t);
	write(log, (char *)&from, sizeof (from));
E 3
D 5
again:
D 3
	errno = 0;
	if ((s = socket(SOCK_RAW, &improto, 0, options)) < 0) {
E 3
I 3
	s = socket(AF_IMPLINK, SOCK_RAW, 0, 0);
	if (s < 0) {
E 3
		perror("socket");
E 5
I 5
	while ((s = socket(AF_IMPLINK, SOCK_RAW, 0, 0)) < 0) {
		perror("implogd: socket");
E 5
		sleep(5);
D 5
		goto again;
E 5
	}
E 10
	for (;;) {
D 3
		cc = receive(s, &from, request, sizeof(request));
		if (cc <= 0)
E 3
I 3
D 6
		int len = sizeof (request);
E 6
I 6
		int fromlen = sizeof (from), len;
E 6

D 5
		if (recvfrom(s, request, &len, &from, sizeof (from), 0) < 0)
E 5
I 5
D 6
		if (recvfrom(s, request, &len, 0, &from, sizeof (from)) < 0) {
E 6
I 6
		len = recvfrom(s, request, sizeof (request), 0,
			&from, &fromlen);
		if (len < 0) {
I 11
			syslog(LOG_ERR, "recvfrom: %m\n");
E 11
E 6
			perror("implogd: recvfrom");
E 5
E 3
			continue;
I 5
		}
E 5
D 3
		if (cc > IMPMTU)	/* sanity */
E 3
I 3
D 6
		if (len <= 0 || len > IMPMTU)	/* sanity */
E 6
I 6
		if (len == 0 || len > IMPMTU)	/* sanity */
E 6
E 3
			continue;
D 3
		from.sin_cc = cc;
E 3
I 3
		from.sin_len = len;
E 3
		from.sin_time = time(0);
D 3
		write(log, (char *)&from, sizeof(from));
		write(log, request, cc);
E 3
I 3
		write(log, (char *)&from, sizeof (from));
		write(log, request, len);
E 3
	}
	/*NOTREACHED*/
}
E 1
