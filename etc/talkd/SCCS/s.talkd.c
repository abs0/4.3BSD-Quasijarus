h09830
s 00010/00005/00093
d D 5.4 88/06/18 14:10:45 bostic 8 7
c install approved copyright notice
e
s 00010/00004/00088
d D 5.3 88/05/20 11:53:35 bostic 7 6
c add Berkeley specific header
e
s 00025/00042/00067
d D 5.2 86/03/13 17:13:25 mckusick 6 5
c new version from sam@monet.berkeley.edu
e
s 00014/00002/00095
d D 5.1 85/06/06 09:20:23 dist 5 4
c Add copyright
e
s 00006/00010/00091
d D 1.4 84/12/20 17:55:09 bloom 4 3
c change from own byte swap to ntoh routines
e
s 00026/00000/00075
d D 1.3 84/05/11 14:20:17 layer 3 2
c Now works between SUNs and VAXen
e
s 00053/00171/00022
d D 1.2 84/04/11 15:15:17 karels 2 1
c reformatting; convert daemon for inetd; add keywords
e
s 00193/00000/00000
d D 1.1 84/04/11 15:03:18 karels 1 0
c date and time created 84/04/11 15:03:18 by karels
e
u
U
t
T
I 5
/*
 * Copyright (c) 1983 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */

E 5
I 1
D 2
/* $Header: talkd.c 1.5 83/05/10 13:57:29 moore Exp $ */
E 2
I 2
#ifndef lint
D 5
static	char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 5
I 5
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 5
E 2

D 2
/* The top level of the daemon, the format is heavily borrowed
   from rwhod.c. Basically: find out who and where you are; 
   disconnect all descriptors and ttys, and then endless
   loop on waiting for and processing requests
E 2
I 2
/*
 * The top level of the daemon, the format is heavily borrowed
 * from rwhod.c. Basically: find out who and where you are; 
 * disconnect all descriptors and ttys, and then endless
 * loop on waiting for and processing requests
E 2
 */
D 2

#include "ctl.h"

E 2
#include <stdio.h>
#include <errno.h>
D 2
#include <sgtty.h>
#include <sys/ioctl.h>
E 2
I 2
#include <signal.h>
I 6
#include <syslog.h>
E 6
E 2

D 2
#define MAX_ERR 20	/* Number of times to attempt to open the 
			   control socket */
E 2
I 2
D 6
#include "ctl.h"
E 6
I 6
#include <protocols/talkd.h>
E 6
E 2

D 2
extern	errno;

E 2
D 6
struct	sockaddr_in sin = { AF_INET };

E 6
D 2
CTL_MSG request;
CTL_RESPONSE response;
int sockt;
char hostname[HOST_NAME_LENGTH];
E 2
I 2
CTL_MSG		request;
CTL_RESPONSE	response;
E 2

D 2
struct hostent *gethostbyname();
struct servent *getservbyname();
E 2
I 2
int	sockt;
int	debug = 0;
I 3
D 6
FILE	*debugout;
E 6
E 3
int	timeout();
long	lastmsgtime;
E 2

D 2
int debug = 0;
E 2
I 2
char	hostname[32];
E 2

D 2
main(argc)
int argc;
E 2
I 2
#define TIMEOUT 30
#define MAXIDLE 120

main(argc, argv)
	int argc;
	char *argv[];
E 2
{
D 2
    struct sockaddr_in from;
    int from_size;
    int cc;
    int name_length = sizeof(hostname);
    struct servent *sp;
    struct hostent *hp;
E 2
I 2
D 6
	struct sockaddr_in from;
	int fromlen, cc;
I 3
	
	if (debug)
		debugout = (FILE *)fopen ("/usr/tmp/talkd.msgs", "w");
E 6
I 6
	register CTL_MSG *mp = &request;
	int cc;
E 6
E 3
E 2

D 2

    if ( argc > 1 ) {
	debug = 1;
    }

    if ( !debug ) {
	if (fork()) {
	    exit(0);
E 2
I 2
	if (getuid()) {
D 6
		fprintf(stderr, "Talkd : not super user\n");
E 6
I 6
		fprintf(stderr, "%s: getuid: not super-user", argv[0]);
E 6
		exit(1);
E 2
	}
D 2
    }
E 2
I 2
D 6
	gethostname(hostname, sizeof (hostname));
	(void) chdir("/dev");
E 6
I 6
	openlog("talkd", LOG_PID, LOG_DAEMON);
	if (gethostname(hostname, sizeof (hostname) - 1) < 0) {
		syslog(LOG_ERR, "gethostname: %m");
		_exit(1);
	}
	if (chdir("/dev") < 0) {
		syslog(LOG_ERR, "chdir: /dev: %m");
		_exit(1);
	}
	if (argc > 1 && strcmp(argv[1], "-d") == 0)
		debug = 1;
E 6
	signal(SIGALRM, timeout);
	alarm(TIMEOUT);
	for (;;) {
		extern int errno;
E 2

D 2
    gethostname(hostname, &name_length);

    hp = gethostbyname(hostname);
    if (hp == (struct hostent *) 0) {
	    fprintf(stderr, "talkd: Cannot obtain local address\n");
	    exit(1);
    }

#ifdef NTALK
    sp = getservbyname("ntalk", "udp");
#else
    sp = getservbyname("talk", "udp");
#endif

    if (sp == 0) {
	    fprintf(stderr, "talkd: udp/talk: unknown service\n");
	    exit(1);
    }

    if (getuid()) {
	fprintf(stderr, "Talkd : not super user\n");
	exit(1);
    }

    setup_desc();

    sin.sin_port = sp->s_port;
    sockt = socket(AF_INET, SOCK_DGRAM, 0, 0);
    if (sockt < 0) {
	    print_error("talkd: socket");
	    exit(1);
    }

    if (bind(sockt, (caddr_t)&sin, sizeof (sin), 0) < 0) {
	print_error("bind");
	exit(1);
    }

    for (;;) {

	from_size = sizeof(from);
	cc = recvfrom(sockt, (char *)&request, sizeof (request), 0, 
		      &from, &from_size);

	if (cc != sizeof(request)) {
	    if (cc < 0 && errno != EINTR) {
		print_error("receive");
	    }
	} else {

	    if (debug) printf("Request received : \n");
	    if (debug) print_request(&request);

	    process_request(&request, &response);

	    if (debug) printf("Response sent : \n");
	    if (debug) print_response(&response);

E 2
I 2
D 6
		fromlen = sizeof(from);
		cc = recvfrom(0, (char *)&request, sizeof (request), 0,
		    &from, &fromlen);
		if (cc != sizeof(request)) {
E 6
I 6
		cc = recv(0, (char *)mp, sizeof (*mp), 0);
		if (cc != sizeof (*mp)) {
E 6
			if (cc < 0 && errno != EINTR)
D 6
			perror("recvfrom");
E 6
I 6
				syslog(LOG_WARNING, "recv: %m");
E 6
			continue;
		}
		lastmsgtime = time(0);
I 3
D 6
		swapmsg(&request);
D 4
		if (debug) print_request(&request, fp);
E 4
I 4
		if (debug) print_request(&request);
E 4
E 3
		process_request(&request, &response);
E 6
I 6
		process_request(mp, &response);
E 6
E 2
		/* can block here, is this what I want? */
D 2

	    cc = sendto(sockt, (char *) &response, sizeof(response), 0,
			&request.ctl_addr, sizeof(request.ctl_addr));

	    if (cc != sizeof(response)) {
		print_error("Send");
	    }
E 2
I 2
D 6
		cc = sendto(sockt, (char *) &response,
		    sizeof (response), 0, &request.ctl_addr,
		    sizeof (request.ctl_addr));
		if (cc != sizeof(response))
			perror("sendto");
E 6
I 6
		cc = sendto(sockt, (char *)&response,
		    sizeof (response), 0, &mp->ctl_addr, sizeof (mp->ctl_addr));
		if (cc != sizeof (response))
			syslog(LOG_WARNING, "sendto: %m");
E 6
E 2
	}
I 3
D 4
	if (debug) close (debugout);
E 4
E 3
D 2
    }
E 2
}

D 2
    /* disconnect all descriptors, remove ourself from the process
     * group that spawned us
     */

setup_desc()
E 2
I 2
timeout()
E 2
{
D 2
    int s;
E 2

D 2
    if (debug) return;

    for (s = 0; s < 10; s++) {
	(void) close(s);
    }

    (void) open("/dev/null", 0);
    (void) dup2(0, 1);
    (void) dup2(0, 2);

    s = open("/dev/tty", 2);

    if (s >= 0) {
	ioctl(s, TIOCNOTTY, (struct sgttyb *) 0);
	(void) close(s);
    }

    (void) chdir("/dev");
}

extern int sys_nerr;
extern char *sys_errlist[];

print_error(string)
char *string;
{
    FILE *cons;
    char *err_dev = "/dev/console";
    char *sys;
    int val, pid;

    if (debug) err_dev = "/dev/tty";

    sys = "Unknown error";

    if(errno < sys_nerr) {
	sys = sys_errlist[errno];
    }

	/* don't ever open tty's directly, let a child do it */
    if ((pid = fork()) == 0) {
	cons = fopen(err_dev, "a");
	if (cons != NULL) {
	    fprintf(cons, "Talkd : %s : %s(%d)\n\r", string, sys,
		    errno);
	    fclose(cons);
	}
	exit(0);
    } else {
	    /* wait for the child process to return */
	do {
	    val = wait(0);
	    if (val == -1) {
		if (errno == EINTR) {
		    continue;
		} else if (errno == ECHILD) {
		    break;
		}
	    }
	} while (val != pid);
    }
E 2
I 2
	if (time(0) - lastmsgtime >= MAXIDLE)
D 6
		exit(0);
E 6
I 6
		_exit(0);
E 6
	alarm(TIMEOUT);
I 3
D 6
}

D 4
#define swapshort(a) (((a << 8) | ((unsigned short) a >> 8)) & 0xffff)
#define swaplong(a) ((swapshort(a) << 16) | (swapshort(((unsigned)a >> 16))))

E 4
/*  
 * heuristic to detect if need to swap bytes
 */

swapmsg(req)
	CTL_MSG *req;
{
D 4
	if (req->ctl_addr.sin_family == swapshort(AF_INET)) {
		req->id_num = swaplong(req->id_num);
		req->pid = swaplong(req->pid);
		req->addr.sin_family = swapshort(req->addr.sin_family);
E 4
I 4
	if (req->ctl_addr.sin_family == ntohs(AF_INET)) {
		req->id_num = ntohl(req->id_num);
		req->pid = ntohl(req->pid);
		req->addr.sin_family = ntohs(req->addr.sin_family);
E 4
		req->ctl_addr.sin_family =
D 4
			swapshort(req->ctl_addr.sin_family);
E 4
I 4
			ntohs(req->ctl_addr.sin_family);
E 4
	}
E 6
E 3
E 2
}
E 1
