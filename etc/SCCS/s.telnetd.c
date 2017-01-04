h52716
s 00010/00005/01418
d D 5.29 88/06/18 14:34:53 bostic 63 62
c install approved copyright notice
e
s 00000/00001/01423
d D 5.28 88/05/23 19:41:32 bostic 62 61
c remove vhangup on exit
e
s 00017/00011/01407
d D 5.27 88/05/22 16:40:02 bostic 61 60
c fix security problem with pty's
e
s 00012/00006/01406
d D 5.26 88/03/08 10:33:34 bostic 60 59
c add Berkeley specific copyright
e
s 00128/00011/01284
d D 5.25 88/01/05 16:13:27 minshall 59 58
c Fixes from rick@sesimo to use /etc/gettytab for login banner.
e
s 00019/00001/01276
d D 5.24 88/01/05 13:56:46 minshall 58 57
c Fix from Charles Hedrick at Rutgers - flush output when
c pty wants output flushed.
e
s 00005/00005/01272
d D 5.23 87/10/22 10:46:38 bostic 57 56
c ANSI C; sprintf now returns an int.
e
s 00001/00001/01276
d D 5.22 87/10/16 14:33:16 minshall 56 55
c Fix bug where turning off CRMOD causes clients which send
c <CR><LF> to always see ^M (and, so line can't be terminated).
e
s 00005/00000/01272
d D 5.21 87/10/16 13:59:05 minshall 55 54
c Fix bug where we hang trying to do an ioctl(pty, TIOCSETP, ...).
e
s 00007/00007/01265
d D 5.20 87/09/02 23:22:25 minshall 54 53
c Sigh.  Map <CR><LF> to \r, rather than \n.
c 
c This is changed after a large amount of discussion in the tcp-ip
c mailing list.  The reasons are basically pragmatic.
e
s 00003/00002/01269
d D 5.19 87/07/27 16:01:37 bostic 53 52
c checked in for minshall -- apparently adjusting the way CR-NUL 
c is handled; comment was "Don't do CR-NUL if we are in binary mode"
e
s 00010/00005/01261
d D 5.18 86/05/12 22:21:20 minshall 52 51
c Two bugs.  First, ttloop() was not reacting to an EOF on the 
c read from the network.  Second, if a wont ttype was coming in it was 
c not causing the ttypopt clock to be set since 1) the setting was in 
c dontoption rather than wontoption and 2) we were leaving hisopts[ttype] 
c equal to OPT_NO.
e
s 00141/00142/01125
d D 5.17 86/05/12 08:18:52 minshall 51 50
c With the old version, we could interlock if the remote 
c host WAS willing to send terminal type information, bug wouldn't 
c send it until WE answered some other question first.  So, we now 
c do the terminal type gathering through the standard telrcv() mechanism.
e
s 00010/00009/01257
d D 5.16 86/05/08 18:24:25 karels 50 49
c minor fixes
e
s 00015/00005/01251
d D 5.15 86/05/07 16:50:03 minshall 49 48
c Correction to acutally pick up information transferred during 
c terminal type negotiation (were getting zeroes).
e
s 00271/00034/00985
d D 5.14 86/04/30 11:15:19 minshall 48 47
c This version fixes ECHOing problems, discovers 4.2 (brain-damaged) 
c clients, and receives terminal type information from the client.
e
s 00093/00015/00926
d D 5.13 86/04/22 22:16:03 minshall 47 46
c This version flushes the network buffer when doing an abort output.
e
s 00030/00004/00911
d D 5.12 86/04/20 21:30:53 minshall 46 45
c Get ready for SO_OOBINLINE; Handle TELNET BREAK distinct from TELNET IP.
e
s 00031/00019/00884
d D 5.11 86/04/19 18:20:35 minshall 45 44
c I forgot Dave Borman's change to keep options up to date (arghh!).
e
s 00001/00001/00902
d D 5.10 86/04/19 16:36:44 minshall 44 43
c Minor change to allow us to work with hosts whose urgent pointer is off by one.
e
s 00275/00033/00628
d D 5.9 86/04/19 16:33:57 minshall 43 42
c This version handles out-of-band data, abort output, and
c initiates suppress-go-ahead.
e
s 00020/00001/00641
d D 5.8 86/04/09 09:18:27 minshall 42 41
c This version does various flavors of CR-LF, CR-NULL, etc., correctly.
e
s 00005/00010/00637
d D 5.7 86/03/07 16:35:04 minshall 41 40
c Keep compatibility with 4.2 telnet.  Note that 4.2 telnet
c does NOT meet the telnet spec (it sends CR with no following LF or NULL),
c but we follow the spec even if we keep compatibility.
e
s 00013/00006/00634
d D 5.6 86/02/06 11:40:34 minshall 40 39
c Fix for carriage return (from userid <borman>).
e
s 00001/00000/00639
d D 5.5 86/02/05 04:51:17 lepreau 39 38
c parent needs to setpgrp
e
s 00000/00001/00639
d D 5.4 85/10/22 18:43:11 bloom 38 37
c be more social about killing attached processes (vhangup takes care of it)
c (from sun!guy)
e
s 00001/00001/00639
d D 5.3 85/09/17 19:17:17 eric 37 36
c facilities in syslog
e
s 00028/00015/00612
d D 5.2 85/06/19 11:20:05 bloom 36 35
c use large read of utmp instead of many (from ks@purdue-ecn)
e
s 00014/00002/00613
d D 5.1 85/05/28 15:39:30 dist 35 34
c Add copyright
e
s 00017/00011/00598
d D 4.32 85/05/10 17:44:54 karels 34 32
c fix pty allocation
e
s 00013/00009/00600
d R 4.32 85/05/10 17:17:46 karels 33 32
c fix pty allocation
e
s 00023/00017/00586
d D 4.31 84/12/23 17:16:36 sam 32 31
c 3 things from brl: search pqrs pty's, correct select logic to 
c fix flow buffering problems, accept AYT's; also use append mode on wtmp 
c file and make all lseek+open parameters symbolic
e
s 00002/00019/00601
d D 4.30 84/11/29 17:01:18 ralph 31 30
c use inet_ntoa instead of local copy.
e
s 00003/00002/00617
d D 4.29 84/09/13 11:33:34 ralph 30 29
c use syslog for error messages
e
s 00002/00002/00617
d D 4.28 84/09/04 21:41:43 sam 29 28
c convert setsockopt calls to new interface
e
s 00012/00085/00607
d D 4.27 84/04/11 15:59:07 karels 28 26
c convert for use with inetd
e
s 00000/00000/00692
d R 4.27 84/04/11 15:37:37 karels 27 26
c convert for inetd
e
s 00001/00001/00691
d D 4.26 83/08/06 11:11:30 sam 26 25
c leave SIGCHLD alone
e
s 00003/00000/00689
d D 4.25 83/07/06 00:44:13 sam 25 24
c set term since login expects it now
e
s 00002/00002/00687
d D 4.24 83/07/06 00:24:51 sam 24 23
c add banner since getty.h is about to go away
e
s 00002/00002/00687
d D 4.23 83/07/02 00:19:48 sam 23 22
c include fixes
e
s 00002/00002/00687
d D 4.22 83/06/12 01:48:54 sam 22 21
c new signals
e
s 00009/00001/00680
d D 4.21 83/05/24 16:21:42 sam 21 20
c banner moves out of login
e
s 00035/00006/00646
d D 4.20 83/05/22 23:57:55 sam 20 19
c utmp changed format
e
s 00002/00004/00650
d D 4.19 83/05/03 20:54:38 sam 19 18
c turn on keep alives
e
s 00003/00001/00651
d D 4.18 83/02/21 19:40:12 sam 18 17
c ignore SIGCHLD in child
e
s 00001/00001/00651
d D 4.17 83/01/22 16:12:16 sam 17 16
c SIGCHLD reset on each occurance 
e
s 00024/00004/00628
d D 4.16 83/01/18 20:19:03 sam 16 15
c put back debugging and reap children to avoid zombies
e
s 00001/00002/00631
d D 4.15 83/01/07 20:35:26 sam 15 14
c no more SIOCDONE
e
s 00001/00003/00632
d D 4.14 82/12/29 15:56:14 sam 14 13
c vhangup to clear pty
e
s 00001/00001/00634
d D 4.13 82/12/25 21:19:47 sam 13 12
c port numbers now byte swapped
e
s 00001/00001/00634
d D 4.12 82/11/17 16:09:30 sam 12 11
c forgot to change socket calls
e
s 00034/00018/00601
d D 4.11 82/11/15 01:25:21 sam 11 10
c missing arg to accept and make diagnostics consistent
e
s 00029/00020/00590
d D 4.10 82/11/14 15:19:56 sam 10 9
c convert to 4.1c sys calls and directory layout
e
s 00015/00000/00595
d D 4.9 82/10/10 16:35:04 sam 9 8
c start up cleanly
e
s 00016/00011/00579
d D 4.8 82/10/07 22:45:04 sam 8 7
c have server request to do echo
e
s 00025/00008/00565
d D 4.7 82/10/06 18:26:32 sam 7 6
c bugs with error ignored error returns & new net data base library
e
s 00005/00004/00568
d D 4.6 82/03/31 10:03:54 sam 6 5
c don't init master pty to have ECHO on and don't send will ECHO option
e
s 00008/00040/00564
d D 4.5 82/03/23 14:42:20 root 5 4
c purge debug crap
e
s 00001/00001/00603
d D 4.4 82/03/23 11:42:51 root 4 3
c require keep-alive
e
s 00001/00002/00603
d D 4.3 82/03/16 21:25:32 root 3 2
c set up sccsid's
e
s 00038/00001/00567
d D 4.2 82/03/01 11:50:54 sam 2 1
c bug fix in sprintf, plus debugging code
e
s 00568/00000/00000
d D 4.1 82/02/28 10:34:17 root 1 0
c date and time created 82/02/28 10:34:17 by root
e
u
U
t
T
I 35
/*
D 50
 * Copyright (c) 1983 Regents of the University of California.
E 50
I 50
D 60
 * Copyright (c) 1983,1986 Regents of the University of California.
E 50
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 60
I 60
 * Copyright (c) 1983, 1986 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 63
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 63
I 63
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
E 63
E 60
 */

E 35
I 1
D 3
/*	%M%	%I%	%E%	*/

E 3
I 3
D 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
I 5
#ifndef lint
D 23
static char sccsid[] = "%W% %E%";
E 23
I 23
D 28
static char sccsid[] = "%W% (Berkeley) %E%";
E 28
I 28
D 35
static	char sccsid[] = "%W% (Berkeley) %G%";
E 28
E 23
#endif
E 35
I 35
char copyright[] =
D 60
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 60
I 60
"%Z% Copyright (c) 1983, 1986 Regents of the University of California.\n\
E 60
 All rights reserved.\n";
D 60
#endif not lint
E 60
I 60
#endif /* not lint */
E 60

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 60
#endif not lint
E 60
I 60
#endif /* not lint */
E 60
E 35

E 5
E 3
/*
D 50
 * Stripped-down telnet server.
E 50
I 50
 * Telnet server.
E 50
 */
I 10
D 50
#include <sys/types.h>
E 50
I 50
#include <sys/param.h>
E 50
#include <sys/socket.h>
I 23
#include <sys/wait.h>
I 32
#include <sys/file.h>
I 34
#include <sys/stat.h>
I 43
#include <sys/time.h>
E 43
E 34
E 32
E 23

#include <netinet/in.h>

I 19
#include <arpa/telnet.h>

E 19
E 10
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <sgtty.h>
D 23
#include <wait.h>
E 23
D 10
#include <sys/types.h>
#include <sys/socket.h>
#include <net/in.h>
E 10
I 7
#include <netdb.h>
I 30
#include <syslog.h>
I 48
#include <ctype.h>
E 48
E 30
I 21
D 24
#include <getty.h>
E 24
E 21
I 10

E 10
E 7
D 19
#include "telnet.h"

E 19
D 10
#define	INFINITY	10000000
E 10
D 24
#define	BELL		'\07'
E 24
I 24
D 49
#define	BELL	'\07'
D 36
#define BANNER	"\r\n\r\n4.2 BSD UNIX (%s)\r\n\r\r\n\r%s"
E 36
I 36
#define BANNER	"\r\n\r\n4.3 BSD UNIX (%s)\r\n\r\r\n\r%s"
E 36
E 24
D 5
#define	swab(x)		((((x) >> 8) | ((x) << 8)) & 0xffff)
E 5

E 49
I 48
D 51
#define	OPT_DONT	0		/* don't do this option */
#define	OPT_WONT	0		/* won't do this option */
#define	OPT_DO		1		/* do this option */
#define	OPT_WILL	1		/* will do this option */
#define	OPT_ALWAYS_LOOK	2		/* special case for echo */
E 51
I 51
#define	OPT_NO			0		/* won't do this option */
#define	OPT_YES			1		/* will do this option */
#define	OPT_YES_BUT_ALWAYS_LOOK	2
#define	OPT_NO_BUT_ALWAYS_LOOK	3
E 51
E 48
char	hisopts[256];
char	myopts[256];

char	doopt[] = { IAC, DO, '%', 'c', 0 };
char	dont[] = { IAC, DONT, '%', 'c', 0 };
char	will[] = { IAC, WILL, '%', 'c', 0 };
char	wont[] = { IAC, WONT, '%', 'c', 0 };

/*
 * I/O data buffers, pointers, and counters.
 */
char	ptyibuf[BUFSIZ], *ptyip = ptyibuf;
I 48

E 48
char	ptyobuf[BUFSIZ], *pfrontp = ptyobuf, *pbackp = ptyobuf;
I 48

E 48
char	netibuf[BUFSIZ], *netip = netibuf;
I 48
#define	NIACCUM(c)	{   *netip++ = c; \
			    ncc++; \
			}

E 48
D 6
char	netobuf[BUFSIZ] =
	{ IAC, DO, TELOPT_ECHO, '\r', '\n' },
	*nfrontp = netobuf + 5, *nbackp = netobuf;
E 6
I 6
char	netobuf[BUFSIZ], *nfrontp = netobuf, *nbackp = netobuf;
I 43
char	*neturg = 0;		/* one past last bye of urgent data */
I 48
	/* the remote system seems to NOT be an old 4.2 */
int	not42 = 1;

I 59
#define	BANNER	"\r\n\r\n4.3 BSD UNIX (%s)\r\n\r\r\n\r"
E 59

I 49
D 59
char BANNER1[] = "\r\n\r\n4.3 BSD UNIX (",
    BANNER2[] = ")\r\n\r\0\r\n\r\0";

E 59
E 49
D 51
char	subbuffer[100], *subpointer, *subend;	/* buffer for sub-options */
E 51
I 51
		/* buffer for sub-options */
char	subbuffer[100], *subpointer= subbuffer, *subend= subbuffer;
E 51
#define	SB_CLEAR()	subpointer = subbuffer;
D 51
#define	SB_TERM()	subend = subpointer;
E 51
I 51
#define	SB_TERM()	{ subend = subpointer; SB_CLEAR(); }
E 51
#define	SB_ACCUM(c)	if (subpointer < (subbuffer+sizeof subbuffer)) { \
				*subpointer++ = (c); \
			}
I 51
#define	SB_GET()	((*subpointer++)&0xff)
#define	SB_EOF()	(subpointer >= subend)
E 51

E 48
E 43
E 6
int	pcc, ncc;

int	pty, net;
int	inter;
I 16
D 28
int	reapchild();
E 28
I 25
extern	char **environ;
E 25
E 16
extern	int errno;
D 34
char	line[] = "/dev/ptyp0";
E 34
I 34
char	*line;
I 43
int	SYNCHing = 0;		/* we are in TELNET SYNCH mode */
/*
 * The following are some clocks used to decide how to interpret
 * the relationship between various variables.
 */
E 43
E 34

I 43
struct {
    int
	system,			/* what the current time is */
	echotoggle,		/* last time user entered echo character */
	modenegotiated,		/* last time operating mode negotiated */
	didnetreceive,		/* last time we read data from network */
I 51
	ttypeopt,		/* ttype will/won't received */
	ttypesubopt,		/* ttype subopt is received */
	getterminal,		/* time started to get terminal information */
E 51
	gotDM;			/* when did we last see a data mark */
} clocks;

D 51
#define	settimer(x)	clocks.x = clocks.system++
E 51
I 51
#define	settimer(x)	(clocks.x = ++clocks.system)
#define	sequenceIs(x,y)	(clocks.x < clocks.y)
E 51

E 43
D 5
struct	sockaddr_in sin = { AF_INET, swab(IPPORT_TELNET) };
E 5
I 5
D 7
struct	sockaddr_in sin = { AF_INET, IPPORT_TELNET };
E 7
I 7
D 28
struct	sockaddr_in sin = { AF_INET };
E 7
E 5
D 4
int	options = SO_ACCEPTCONN;
E 4
I 4
D 10
int	options = SO_ACCEPTCONN|SO_KEEPALIVE;
E 10
E 4

E 28
I 2
D 5
/*
 * Debugging hooks.  Turned on with a SIGTERM.
 * Successive SIGTERM's toggle the switch.
 */
int	toggle();
int	debug;
FILE	*log;
char	logfile[80] = "/tmp/teldebugx";

E 5
E 2
main(argc, argv)
	char *argv[];
{
D 16
	int s, pid;
	union wait status;
E 16
I 16
D 28
	int s, pid, options;
E 16
I 7
	struct servent *sp;
E 28
I 28
	struct sockaddr_in from;
D 29
	int fromlen;
E 29
I 29
	int on = 1, fromlen;
E 29
E 28
E 7

I 43
#if	defined(DEBUG)
	{
	    int s, ns, foo;
	    struct servent *sp;
	    static struct sockaddr_in sin = { AF_INET };

	    sp = getservbyname("telnet", "tcp");
	    if (sp == 0) {
		    fprintf(stderr, "telnetd: tcp/telnet: unknown service\n");
		    exit(1);
	    }
	    sin.sin_port = sp->s_port;
	    argc--, argv++;
	    if (argc > 0) {
		    sin.sin_port = atoi(*argv);
		    sin.sin_port = htons((u_short)sin.sin_port);
	    }

	    s = socket(AF_INET, SOCK_STREAM, 0);
	    if (s < 0) {
		    perror("telnetd: socket");;
		    exit(1);
	    }
	    if (bind(s, &sin, sizeof sin) < 0) {
		perror("bind");
		exit(1);
	    }
	    if (listen(s, 1) < 0) {
		perror("listen");
		exit(1);
	    }
	    foo = sizeof sin;
	    ns = accept(s, &sin, &foo);
	    if (ns < 0) {
		perror("accept");
		exit(1);
	    }
	    dup2(ns, 0);
	    close(s);
	}
#endif	/* defined(DEBUG) */
E 43
I 37
	openlog("telnetd", LOG_PID | LOG_ODELAY, LOG_DAEMON);
E 37
I 7
D 28
	sp = getservbyname("telnet", "tcp");
	if (sp == 0) {
		fprintf(stderr, "telnetd: tcp/telnet: unknown service\n");
		exit(1);
E 28
I 28
	fromlen = sizeof (from);
	if (getpeername(0, &from, &fromlen) < 0) {
		fprintf(stderr, "%s: ", argv[0]);
		perror("getpeername");
		_exit(1);
E 28
	}
D 28
	sin.sin_port = sp->s_port;
E 7
	argc--, argv++;
I 16
	if (argc > 0 && !strcmp(*argv, "-d")) {
		options |= SO_DEBUG;
		argc--, argv++;
E 28
I 28
D 29
	if (setsockopt(0, SOL_SOCKET, SO_KEEPALIVE, 0, 0) < 0) {
E 29
I 29
	if (setsockopt(0, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof (on)) < 0) {
E 29
D 30
		fprintf(stderr, "%s: ", argv[0]);
		perror("setsockopt (SO_KEEPALIVE)");
E 30
I 30
D 37
		openlog(argv[0], LOG_PID, 0);
E 37
		syslog(LOG_WARNING, "setsockopt (SO_KEEPALIVE): %m");
E 30
E 28
	}
E 16
D 10
	if (argc > 0 && !strcmp(argv[0], "-d"))
D 7
		options |= SO_DEBUG;
I 5
#if vax || pdp11
E 7
I 7
		options |= SO_DEBUG, argc--, argv++;
E 10
D 28
	if (argc > 0) {
		sin.sin_port = atoi(*argv);
		if (sin.sin_port <= 0) {
			fprintf(stderr, "telnetd: %s: bad port #\n", *argv);
			exit(1);
		}
I 13
		sin.sin_port = htons((u_short)sin.sin_port);
E 13
	}
E 7
D 10
	sin.sin_port = htons(sin.sin_port);
E 10
I 10
D 13
	sin.sin_port = htons((u_short)sin.sin_port);
E 13
E 10
I 9
#ifndef DEBUG
	if (fork())
		exit(0);
	for (s = 0; s < 10; s++)
		(void) close(s);
	(void) open("/", 0);
	(void) dup2(0, 1);
	(void) dup2(0, 2);
	{ int tt = open("/dev/tty", 2);
	  if (tt > 0) {
		ioctl(tt, TIOCNOTTY, 0);
		close(tt);
	  }
	}
#endif
I 10
again:
D 12
	s = socket(0, SOCK_STREAM, 0, 0);
E 12
I 12
	s = socket(AF_INET, SOCK_STREAM, 0, 0);
E 12
	if (s < 0) {
		perror("telnetd: socket");;
		sleep(5);
		goto again;
	}
I 16
	if (options & SO_DEBUG)
		if (setsockopt(s, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
			perror("telnetd: setsockopt (SO_DEBUG)");
D 19
#ifdef notdef
E 19
	if (setsockopt(s, SOL_SOCKET, SO_KEEPALIVE, 0, 0) < 0)
		perror("telnetd: setsockopt (SO_KEEPALIVE)");
D 19
#endif
E 19
E 16
	while (bind(s, (caddr_t)&sin, sizeof (sin), 0) < 0) {
		perror("telnetd: bind");
		sleep(5);
	}
I 16
D 17
	signal(SIGCHLD, reapchild);
E 17
I 17
D 22
	sigset(SIGCHLD, reapchild);
E 22
I 22
	signal(SIGCHLD, reapchild);
E 22
E 17
E 16
	listen(s, 10);
E 10
E 9
D 7
#endif
E 7
E 5
	for (;;) {
D 10
		errno = 0;
		if ((s = socket(SOCK_STREAM, 0, &sin, options)) < 0) {
			perror("socket");
			sleep(5);
			continue;
		}
		if (accept(s, 0) < 0) {
E 10
I 10
D 20
		int s2;
E 20
I 20
		struct sockaddr_in from;
		int s2, fromlen = sizeof (from);
E 20

D 11
		s2 = accept(s, (caddr_t)0, 0);
E 11
I 11
D 20
		s2 = accept(s, (caddr_t)0, 0, 0);
E 20
I 20
		s2 = accept(s, (caddr_t)&from, &fromlen);
E 20
E 11
		if (s2 < 0) {
I 16
			if (errno == EINTR)
				continue;
E 16
E 10
D 11
			perror("accept");
E 11
I 11
			perror("telnetd: accept");
E 11
D 10
			close(s);
E 10
			sleep(1);
			continue;
		}
		if ((pid = fork()) < 0)
			printf("Out of processes\n");
D 18
		else if (pid == 0)
E 18
I 18
		else if (pid == 0) {
D 26
			signal(SIGCHLD, SIG_IGN);
E 26
I 26
			signal(SIGCHLD, SIG_DFL);
E 26
E 18
D 10
			doit(s);
		close(s);
E 10
I 10
D 20
			doit(s2);
E 20
I 20
			doit(s2, &from);
E 20
I 18
		}
E 18
		close(s2);
E 10
D 16
		while (wait3(status, WNOHANG, 0) > 0)
			continue;
E 16
	}
	/*NOTREACHED*/
I 16
}

reapchild()
{
	union wait status;

	while (wait3(&status, WNOHANG, 0) > 0)
		;
E 28
I 28
	doit(0, &from);
E 28
E 16
}

I 51
char	*terminaltype = 0;
char	*envinit[2];
int	cleanup();
E 51
I 25
D 48
char	*envinit[] = { "TERM=network", 0 };
E 48
I 48

/*
D 51
 * Get()
E 51
I 51
 * ttloop
E 51
 *
D 51
 *	Return next character from file descriptor.
E 51
I 51
 *	A small subroutine to flush the network output buffer, get some data
 * from the network, and pass it through the telnet state machine.  We
 * also flush the pty input buffer (by dropping its data) if it becomes
 * too full.
 */

void
ttloop()
{
    if (nfrontp-nbackp) {
	netflush();
    }
    ncc = read(net, netibuf, sizeof netibuf);
    if (ncc < 0) {
	syslog(LOG_INFO, "ttloop:  read: %m\n");
I 52
	exit(1);
    } else if (ncc == 0) {
	syslog(LOG_INFO, "ttloop:  peer died: %m\n");
	exit(1);
E 52
    }
    netip = netibuf;
    telrcv();			/* state machine */
    if (ncc > 0) {
	pfrontp = pbackp = ptyobuf;
	telrcv();
    }
}

/*
 * getterminaltype
E 51
 *
D 51
 *	This is not meant to be very efficient, since it is only
 * run during startup.
E 51
I 51
 *	Ask the other end to send along its terminal type.
 * Output is the variable terminaltype filled in.
E 51
 */

D 51
Get(f)
int	f;		/* the file descriptor */
E 51
I 51
void
getterminaltype()
E 51
{
D 51
    char	input;
E 51
I 51
    static char sbuf[] = { IAC, DO, TELOPT_TTYPE };
E 51

D 51
    if (read(f, &input, 1) != 1) {
D 50
	syslog(LOG_ERR, "read: %m\n");
E 50
I 50
	syslog(LOG_INFO, "read: %m\n");
E 50
	exit(1);
E 51
I 51
    settimer(getterminal);
    bcopy(sbuf, nfrontp, sizeof sbuf);
    nfrontp += sizeof sbuf;
I 52
    hisopts[TELOPT_TTYPE] = OPT_YES_BUT_ALWAYS_LOOK;
E 52
    while (sequenceIs(ttypeopt, getterminal)) {
	ttloop();
E 51
    }
D 51
    return input&0xff;
E 51
I 51
    if (hisopts[TELOPT_TTYPE] == OPT_YES) {
	static char sbbuf[] = { IAC, SB, TELOPT_TTYPE, TELQUAL_SEND, IAC, SE };

	bcopy(sbbuf, nfrontp, sizeof sbbuf);
	nfrontp += sizeof sbbuf;
	while (sequenceIs(ttypesubopt, getterminal)) {
	    ttloop();
	}
    }
E 51
}

D 51
char	*terminaltype;
char	*envinit[2];
E 48
E 25
int	cleanup();

E 51
/*
 * Get a pty, scan input lines.
 */
D 20
doit(f)
E 20
I 20
doit(f, who)
	int f;
	struct sockaddr_in *who;
E 20
{
D 20
	char *cp = line;
E 20
I 20
D 31
	char *cp = line, *host, *ntoa();
E 31
I 31
D 34
	char *cp = line, *host, *inet_ntoa();
E 34
I 34
	char *host, *inet_ntoa();
E 34
E 31
E 20
D 32
	int i, p, cc, t;
E 32
I 32
	int i, p, t;
E 32
	struct sgttyb b;
I 20
	struct hostent *hp;
I 32
D 34
	char *pqrs;
E 34
I 34
D 48
	char c;
E 48
I 48
	int c;
D 51
	int gotterminaltype = 0;
E 51
E 48
E 34
E 32
E 20

I 48
D 51
	/*
	 * Try to get a terminal type from the foreign host.
	 */

	{
	    static char sbuf[] = { IAC, DO, TELOPT_TTYPE };

	    terminaltype = 0;
	    if (write(f, sbuf, sizeof sbuf) == -1) {
D 50
		syslog(LOG_ERR, "write sbuf: %m\n");
E 50
I 50
		syslog(LOG_INFO, "write sbuf: %m\n");
E 50
		exit(1);
	    }
	    for (;;) {		/* ugly, but we are VERY early */
		while ((c = Get(f)) != IAC) {
		    NIACCUM(c);
		}
		if ((c = Get(f)) == WILL) {
		    if ((c = Get(f)) == TELOPT_TTYPE) {
			static char sbbuf[] = { IAC, SB, TELOPT_TTYPE,
							TELQUAL_SEND, IAC, SE };
			if (write(f, sbbuf, sizeof sbbuf) == -1) {
D 50
			    syslog(LOG_ERR, "write sbbuf: %m\n");
E 50
I 50
			    syslog(LOG_INFO, "write sbbuf: %m\n");
E 50
			    exit(1);
			}
			break;
		    } else {
			NIACCUM(IAC);
			NIACCUM(WILL);
			NIACCUM(c);
		    }
		} else if (c == WONT) {
		    if ((c = Get(f)) == TELOPT_TTYPE) {
			terminaltype = "TERM=network";
			break;
		    } else {
			NIACCUM(IAC);
			NIACCUM(WONT);
			NIACCUM(c);
		    }
		} else {
		    NIACCUM(IAC);
		    NIACCUM(c);
		}
	    }
	    if (!terminaltype) {
		for (;;) {
		    while ((c = Get(f)) != IAC) {
			NIACCUM(c);
		    }
		    if ((c = Get(f)) != SB) {
			NIACCUM(IAC);
			NIACCUM(c);
		    } else if ((c = Get(f)) != TELOPT_TTYPE) {
			NIACCUM(IAC);
			NIACCUM(SB);
			NIACCUM(c);
		    } else if ((c = Get(f)) != TELQUAL_IS) {
			NIACCUM(IAC);
			NIACCUM(SB);
			NIACCUM(TELOPT_TTYPE);
			NIACCUM(c);
		    } else {		/* Yaaaay! */
			static char terminalname[5+41] = "TERM=";

			terminaltype = terminalname+strlen(terminalname);

			while (terminaltype <
				    (terminalname + sizeof terminalname-1)) {
			    if ((c = Get(f)) == IAC) {
				if ((c = Get(f)) == SE) {
				    break;		/* done */
				} else {
				    *terminaltype++ = IAC;	/* ? */
				    if (isupper(c)) {
					c = tolower(c);
				    }
				    *terminaltype++ = c;
				}
			    } else {
				if (isupper(c)) {
				    c = tolower(c);
				}
				*terminaltype++ = c;    /* accumulate name */
			    }
			}
			*terminaltype = 0;
			terminaltype = terminalname;
			gotterminaltype = 1;
			break;
		    }
		}
	    }
	    envinit[0] = terminaltype;
	    envinit[1] = 0;
	}
I 49
	netip = netibuf;
E 49

E 51
E 48
D 32
	for (i = 0; i < 16; i++) {
		cp[strlen("/dev/ptyp")] = "0123456789abcdef"[i];
		p = open(cp, 2);
		if (p > 0)
			goto gotpty;
E 32
I 32
D 34
	t = strlen("/dev/ptyp");
	for (pqrs = "pqrs"; *pqrs; pqrs++) {
		cp[t] = *pqrs;
E 34
I 34
	for (c = 'p'; c <= 's'; c++) {
		struct stat stb;

		line = "/dev/ptyXX";
		line[strlen("/dev/pty")] = c;
		line[strlen("/dev/ptyp")] = '0';
		if (stat(line, &stb) < 0)
			break;
E 34
		for (i = 0; i < 16; i++) {
D 34
			cp[t] = "0123456789abcdef"[i];
			p = open(cp, O_RDWR);
E 34
I 34
D 61
			line[strlen("/dev/ptyp")] = "0123456789abcdef"[i];
			p = open(line, 2);
E 61
I 61
			line[sizeof("/dev/ptyp") - 1] = "0123456789abcdef"[i];
			p = open(line, O_RDWR);
E 61
E 34
			if (p > 0)
				goto gotpty;
		}
E 32
	}
D 11
	dup2(f, 1);
	printf("All network ports in use.\n");
	exit(1);
E 11
I 11
	fatal(f, "All network ports in use");
	/*NOTREACHED*/
E 11
gotpty:
I 2
D 5
	logfile[strlen("/tmp/teldebug")] = "0123456789abcdef"[i];
E 5
E 2
	dup2(f, 0);
D 34
	cp[strlen("/dev/")] = 't';
E 34
I 34
	line[strlen("/dev/")] = 't';
E 34
D 32
	t = open("/dev/tty", 2);
E 32
I 32
	t = open("/dev/tty", O_RDWR);
E 32
	if (t >= 0) {
		ioctl(t, TIOCNOTTY, 0);
		close(t);
	}
D 32
	t = open(cp, 2);
E 32
I 32
D 34
	t = open(cp, O_RDWR);
E 34
I 34
	t = open(line, O_RDWR);
E 34
E 32
D 11
	if (t < 0) {
		dup2(f, 2);
		perror(cp);
		exit(1);
	}
E 11
I 11
	if (t < 0)
D 34
		fatalperror(f, cp, errno);
E 34
I 34
D 61
		fatalperror(f, line, errno);
E 61
I 61
		fatalperror(f, line);
	if (fchmod(t, 0))
		fatalperror(f, line);
	(void)signal(SIGHUP, SIG_IGN);
	vhangup();
	(void)signal(SIGHUP, SIG_DFL);
	t = open(line, O_RDWR);
	if (t < 0)
		fatalperror(f, line);
E 61
E 34
E 11
	ioctl(t, TIOCGETP, &b);
D 6
	b.sg_flags = ECHO|CRMOD|XTABS|ANYP;
E 6
I 6
	b.sg_flags = CRMOD|XTABS|ANYP;
E 6
	ioctl(t, TIOCSETP, &b);
I 6
	ioctl(p, TIOCGETP, &b);
D 8
	b.sg_flags &= ~ECHO;		/* not until remote says to */
E 8
I 8
	b.sg_flags &= ~ECHO;
E 8
	ioctl(p, TIOCSETP, &b);
I 20
	hp = gethostbyaddr(&who->sin_addr, sizeof (struct in_addr),
		who->sin_family);
	if (hp)
		host = hp->h_name;
	else
D 31
		host = ntoa(who->sin_addr);
E 31
I 31
		host = inet_ntoa(who->sin_addr);
I 51

	net = f;
	pty = p;

	/*
	 * get terminal type.
	 */
	getterminaltype();

E 51
E 31
E 20
E 6
D 11
	if ((i = fork()) < 0) {
		dup2(f, 2);
		perror("fork");
		exit(1);
	}
E 11
I 11
	if ((i = fork()) < 0)
D 61
		fatalperror(f, "fork", errno);
E 61
I 61
		fatalperror(f, "fork");
E 61
E 11
	if (i)
		telnet(f, p);
	close(f);
	close(p);
	dup2(t, 0);
	dup2(t, 1);
	dup2(t, 2);
	close(t);
I 51
	envinit[0] = terminaltype;
	envinit[1] = 0;
E 51
I 25
	environ = envinit;
E 25
D 20
	execl("/bin/login", "telnet-login", 0);
E 20
I 20
D 21
	execl("/bin/login", "telnet-login", "-h", host, 0);
E 21
I 21
D 48
	execl("/bin/login", "login", "-h", host, 0);
E 48
I 48
	/*
	 * -h : pass on name of host.
I 51
	 *		WARNING:  -h is accepted by login if and only if
	 *			getuid() == 0.
E 51
	 * -p : don't clobber the environment (so terminal type stays set).
	 */
	execl("/bin/login", "login", "-h", host,
D 51
					gotterminaltype ? "-p" : 0, 0);
E 51
I 51
					terminaltype ? "-p" : 0, 0);
E 51
E 48
E 21
E 20
D 11
	perror("/bin/login");
E 11
I 11
D 61
	fatalperror(f, "/bin/login", errno);
E 61
I 61
	fatalperror(f, "/bin/login");
E 61
	/*NOTREACHED*/
}

fatal(f, msg)
	int f;
	char *msg;
{
	char buf[BUFSIZ];

D 32
	(void) sprintf(buf, "telnetd: %s.\n", msg);
E 32
I 32
	(void) sprintf(buf, "telnetd: %s.\r\n", msg);
E 32
	(void) write(f, buf, strlen(buf));
E 11
	exit(1);
}

I 11
D 61
fatalperror(f, msg, errno)
E 61
I 61
fatalperror(f, msg)
E 61
	int f;
	char *msg;
D 61
	int errno;
E 61
{
	char buf[BUFSIZ];
	extern char *sys_errlist[];

D 32
	(void) sprintf(buf, "%s: %s", msg, sys_errlist[errno]);
E 32
I 32
	(void) sprintf(buf, "%s: %s\r\n", msg, sys_errlist[errno]);
E 32
	fatal(f, buf);
}

I 43

E 43
E 11
/*
I 43
 * Check a descriptor to see if out of band data exists on it.
 */


stilloob(s)
int	s;		/* socket number */
{
    static struct timeval timeout = { 0 };
    fd_set	excepts;
    int value;

    do {
	FD_ZERO(&excepts);
	FD_SET(s, &excepts);
	value = select(s+1, (fd_set *)0, (fd_set *)0, &excepts, &timeout);
D 50
    } while ((value == -1) && (errno = EINTR));
E 50
I 50
    } while ((value == -1) && (errno == EINTR));
E 50

    if (value < 0) {
D 61
	fatalperror(pty, "select", errno);
E 61
I 61
	fatalperror(pty, "select");
E 61
    }
    if (FD_ISSET(s, &excepts)) {
	return 1;
    } else {
	return 0;
    }
}

/*
E 43
 * Main loop.  Select from pty and network, and
 * hand data to telnet receiver finite state machine.
 */
telnet(f, p)
{
	int on = 1;
I 21
D 50
	char hostname[32];
E 50
I 50
	char hostname[MAXHOSTNAMELEN];
I 59
#define	TABBUFSIZ	512
	char	defent[TABBUFSIZ];
	char	defstrs[TABBUFSIZ];
#undef	TABBUFSIZ
	char *HE;
	char *HN;
	char *IM;
E 59
E 50
E 21

D 51
	net = f, pty = p;
E 51
	ioctl(f, FIONBIO, &on);
	ioctl(p, FIONBIO, &on);
I 58
	ioctl(p, TIOCPKT, &on);
E 58
I 46
D 48
#if	defined(xxxSO_OOBINLINE)
	setsockopt(net, SOL_SOCKET, SO_OOBINLINE, on, sizeof on);
#endif	/* defined(xxxSO_OOBINLINE) */
E 48
I 48
#if	defined(SO_OOBINLINE)
	setsockopt(net, SOL_SOCKET, SO_OOBINLINE, &on, sizeof on);
#endif	/* defined(SO_OOBINLINE) */
E 48
E 46
	signal(SIGTSTP, SIG_IGN);
I 55
	/*
	 * Ignoring SIGTTOU keeps the kernel from blocking us
	 * in ttioctl() in /sys/tty.c.
	 */
	signal(SIGTTOU, SIG_IGN);
E 55
D 22
	sigset(SIGCHLD, cleanup);
E 22
I 22
	signal(SIGCHLD, cleanup);
I 39
	setpgrp(0, 0);
E 39
E 22
I 2
D 5
	sigset(SIGTERM, toggle);
E 5
E 2

I 8
	/*
D 43
	 * Request to do remote echo.
E 43
I 43
	 * Request to do remote echo and to suppress go ahead.
E 43
	 */
D 51
	dooption(TELOPT_ECHO);
D 43
	myopts[TELOPT_ECHO] = 1;
E 43
I 43
	dooption(TELOPT_SGA);
E 51
I 51
	if (!myopts[TELOPT_ECHO]) {
	    dooption(TELOPT_ECHO);
	}
	if (!myopts[TELOPT_SGA]) {
	    dooption(TELOPT_SGA);
	}
E 51
E 43
I 21
	/*
I 48
	 * Is the client side a 4.2 (NOT 4.3) system?  We need to know this
	 * because 4.2 clients are unable to deal with TCP urgent data.
	 *
	 * To find out, we send out a "DO ECHO".  If the remote system
	 * answers "WILL ECHO" it is probably a 4.2 client, and we note
	 * that fact ("WILL ECHO" ==> that the client will echo what
	 * WE, the server, sends it; it does NOT mean that the client will
	 * echo the terminal input).
	 */
D 57
	sprintf(nfrontp, doopt, TELOPT_ECHO);
E 57
I 57
	(void) sprintf(nfrontp, doopt, TELOPT_ECHO);
E 57
	nfrontp += sizeof doopt-2;
D 51
	hisopts[TELOPT_ECHO] = OPT_ALWAYS_LOOK;
E 51
I 51
	hisopts[TELOPT_ECHO] = OPT_YES_BUT_ALWAYS_LOOK;
E 51

	/*
E 48
	 * Show banner that getty never gave.
I 49
	 *
D 59
	 * The banner includes some null's (for TELNET CR disambiguation),
	 * so we have to be somewhat complicated.
E 59
I 59
	 * We put the banner in the pty input buffer.  This way, it
	 * gets carriage return null processing, etc., just like all
	 * other pty --> client data.
E 59
E 49
	 */
I 49

E 49
	gethostname(hostname, sizeof (hostname));
I 59
	if (getent(defent, "default") == 1) {
		char *getstr();
		char *p=defstrs;
E 59
D 49
	sprintf(nfrontp, BANNER, hostname, "");
	nfrontp += strlen(nfrontp);
E 49
I 49

D 59
	bcopy(BANNER1, nfrontp, sizeof BANNER1 -1);
	nfrontp += sizeof BANNER1 - 1;
	bcopy(hostname, nfrontp, strlen(hostname));
	nfrontp += strlen(hostname);
	bcopy(BANNER2, nfrontp, sizeof BANNER2 -1);
	nfrontp += sizeof BANNER2 - 1;
E 59
I 59
		HE = getstr("he", &p);
		HN = getstr("hn", &p);
		IM = getstr("im", &p);
		if (HN && *HN)
			strcpy(hostname, HN);
		edithost(HE, hostname);
		if (IM && *IM)
D 61
			putf(IM, ptyibuf+1, p);
E 61
I 61
			putf(IM, ptyibuf+1);
E 61
	} else {
		sprintf(ptyibuf+1, BANNER, hostname);
	}
E 59
E 49
I 48

I 59
	ptyip = ptyibuf+1;		/* Prime the pump */
	pcc = strlen(ptyip);		/* ditto */

E 59
I 58
	/* Clear ptybuf[0] - where the packet information is received */
	ptyibuf[0] = 0;
I 59

E 59
E 58
	/*
	 * Call telrcv() once to pick up anything received during
	 * terminal type negotiation.
	 */
	telrcv();

E 48
E 21
E 8
	for (;;) {
D 43
		int ibits = 0, obits = 0;
E 43
I 43
		fd_set ibits, obits, xbits;
E 43
		register int c;

I 43
		if (ncc < 0 && pcc < 0)
			break;

		FD_ZERO(&ibits);
		FD_ZERO(&obits);
		FD_ZERO(&xbits);
E 43
		/*
		 * Never look for input if there's still
		 * stuff in the corresponding output buffer
		 */
D 32
		if (nfrontp - nbackp)
E 32
I 32
D 43
		if (nfrontp - nbackp || pcc > 0)
E 32
			obits |= (1 << f);
		else
			ibits |= (1 << p);
D 32
		if (pfrontp - pbackp)
E 32
I 32
		if (pfrontp - pbackp || ncc > 0)
E 32
			obits |= (1 << p);
		else
			ibits |= (1 << f);
		if (ncc < 0 && pcc < 0)
			break;
I 2
D 5
		if (debug)
			fprintf(log, "select: ibits=%d, obits=%d\n",
				ibits, obits);
E 5
E 2
D 10
		select(32, &ibits, &obits, INFINITY);
E 10
I 10
		select(16, &ibits, &obits, 0, 0);
E 10
I 2
D 5
		if (debug)
			fprintf(log, "ibits=%d, obits=%d\n", ibits, obits);
E 5
E 2
		if (ibits == 0 && obits == 0) {
E 43
I 43
		if (nfrontp - nbackp || pcc > 0) {
			FD_SET(f, &obits);
I 58
			FD_SET(p, &xbits);
E 58
		} else {
			FD_SET(p, &ibits);
		}
		if (pfrontp - pbackp || ncc > 0) {
			FD_SET(p, &obits);
		} else {
			FD_SET(f, &ibits);
		}
		if (!SYNCHing) {
			FD_SET(f, &xbits);
		}
		if ((c = select(16, &ibits, &obits, &xbits,
						(struct timeval *)0)) < 1) {
			if (c == -1) {
				if (errno == EINTR) {
					continue;
				}
			}
E 43
			sleep(5);
			continue;
		}

		/*
I 43
		 * Any urgent data?
		 */
		if (FD_ISSET(net, &xbits)) {
		    SYNCHing = 1;
		}

		/*
E 43
		 * Something to read from the network...
		 */
D 43
		if (ibits & (1 << f)) {
			ncc = read(f, netibuf, BUFSIZ);
I 2
D 5
			if (debug)
				fprintf(log, "read %d from net\n", ncc);
E 5
E 2
			if (ncc < 0 && errno == EWOULDBLOCK)
				ncc = 0;
			else {
				if (ncc <= 0)
					break;
				netip = netibuf;
E 43
I 43
		if (FD_ISSET(net, &ibits)) {
D 46
#if	!defined(IOCTL_TO_DO_UNIX_OOB_IN_TCP_WAY)
E 46
I 46
D 48
#if	!defined(xxxSO_OOBINLINE)
E 48
I 48
#if	!defined(SO_OOBINLINE)
E 48
E 46
			/*
D 50
			 * In 4.2 (and some early 4.3) systems, the
E 50
I 50
			 * In 4.2 (and 4.3 beta) systems, the
E 50
			 * OOB indication and data handling in the kernel
			 * is such that if two separate TCP Urgent requests
			 * come in, one byte of TCP data will be overlaid.
			 * This is fatal for Telnet, but we try to live
			 * with it.
			 *
			 * In addition, in 4.2 (and...), a special protocol
			 * is needed to pick up the TCP Urgent data in
			 * the correct sequence.
			 *
			 * What we do is:  if we think we are in urgent
			 * mode, we look to see if we are "at the mark".
			 * If we are, we do an OOB receive.  If we run
			 * this twice, we will do the OOB receive twice,
			 * but the second will fail, since the second
			 * time we were "at the mark", but there wasn't
			 * any data there (the kernel doesn't reset
			 * "at the mark" until we do a normal read).
			 * Once we've read the OOB data, we go ahead
			 * and do normal reads.
			 *
			 * There is also another problem, which is that
			 * since the OOB byte we read doesn't put us
			 * out of OOB state, and since that byte is most
			 * likely the TELNET DM (data mark), we would
			 * stay in the TELNET SYNCH (SYNCHing) state.
			 * So, clocks to the rescue.  If we've "just"
			 * received a DM, then we test for the
			 * presence of OOB data when the receive OOB
			 * fails (and AFTER we did the normal mode read
			 * to clear "at the mark").
			 */
		    if (SYNCHing) {
			int atmark;

			ioctl(net, SIOCATMARK, (char *)&atmark);
			if (atmark) {
			    ncc = recv(net, netibuf, sizeof (netibuf), MSG_OOB);
			    if ((ncc == -1) && (errno == EINVAL)) {
				ncc = read(net, netibuf, sizeof (netibuf));
D 51
				if (clocks.didnetreceive < clocks.gotDM) {
E 51
I 51
				if (sequenceIs(didnetreceive, gotDM)) {
E 51
				    SYNCHing = stilloob(net);
				}
			    }
			} else {
			    ncc = read(net, netibuf, sizeof (netibuf));
E 43
			}
I 43
		    } else {
			ncc = read(net, netibuf, sizeof (netibuf));
		    }
		    settimer(didnetreceive);
D 46
#else	/* !defined(IOCTL_TO_DO_UNIX_OOB_IN_TCP_WAY) */
E 46
I 46
D 48
#else	/* !defined(xxxSO_OOBINLINE)) */
E 48
I 48
#else	/* !defined(SO_OOBINLINE)) */
E 48
E 46
		    ncc = read(net, netibuf, sizeof (netibuf));
D 46
#endif	/* !defined(IOCTL_TO_DO_UNIX_OOB_IN_TCP_WAY) */
E 46
I 46
D 48
#endif	/* !defined(xxxSO_OOBINLINE)) */
E 48
I 48
#endif	/* !defined(SO_OOBINLINE)) */
E 48
E 46
		    if (ncc < 0 && errno == EWOULDBLOCK)
			ncc = 0;
		    else {
			if (ncc <= 0) {
			    break;
			}
			netip = netibuf;
		    }
E 43
		}

		/*
		 * Something to read from the pty...
		 */
I 58
		if (FD_ISSET(p, &xbits)) {
			if (read(p, ptyibuf, 1) != 1) {
				break;
			}
		}
E 58
D 43
		if (ibits & (1 << p)) {
E 43
I 43
		if (FD_ISSET(p, &ibits)) {
E 43
			pcc = read(p, ptyibuf, BUFSIZ);
I 2
D 5
			if (debug)
				fprintf(log, "read %d from pty\n", pcc);
E 5
E 2
			if (pcc < 0 && errno == EWOULDBLOCK)
				pcc = 0;
			else {
				if (pcc <= 0)
					break;
D 58
				ptyip = ptyibuf;
E 58
I 58
				/* Skip past "packet" */
				pcc--;
				ptyip = ptyibuf+1;
E 58
			}
I 58
		}
		if (ptyibuf[0] & TIOCPKT_FLUSHWRITE) {
			netclear();	/* clear buffer back */
			*nfrontp++ = IAC;
			*nfrontp++ = DM;
			neturg = nfrontp-1;  /* off by one XXX */
			ptyibuf[0] = 0;
E 58
		}

		while (pcc > 0) {
			if ((&netobuf[BUFSIZ] - nfrontp) < 2)
				break;
			c = *ptyip++ & 0377, pcc--;
			if (c == IAC)
				*nfrontp++ = c;
			*nfrontp++ = c;
I 42
D 53
			if (c == '\r') {
E 53
I 53
			/* Don't do CR-NUL if we are in binary mode */
			if ((c == '\r') && (myopts[TELOPT_BINARY] == OPT_NO)) {
E 53
				if (pcc > 0 && ((*ptyip & 0377) == '\n')) {
					*nfrontp++ = *ptyip++ & 0377;
					pcc--;
				} else
					*nfrontp++ = '\0';
			}
E 42
		}
D 43
		if ((obits & (1 << f)) && (nfrontp - nbackp) > 0)
E 43
I 43
		if (FD_ISSET(f, &obits) && (nfrontp - nbackp) > 0)
E 43
			netflush();
		if (ncc > 0)
			telrcv();
D 43
		if ((obits & (1 << p)) && (pfrontp - pbackp) > 0)
E 43
I 43
		if (FD_ISSET(p, &obits) && (pfrontp - pbackp) > 0)
E 43
			ptyflush();
	}
	cleanup();
}
	
/*
 * State for recv fsm
 */
#define	TS_DATA		0	/* base state */
#define	TS_IAC		1	/* look for double IAC's */
#define	TS_CR		2	/* CR-LF ->'s CR */
D 48
#define	TS_BEGINNEG	3	/* throw away begin's... */
#define	TS_ENDNEG	4	/* ...end's (suboption negotiation) */
E 48
I 48
#define	TS_SB		3	/* throw away begin's... */
#define	TS_SE		4	/* ...end's (suboption negotiation) */
E 48
#define	TS_WILL		5	/* will option negotiation */
#define	TS_WONT		6	/* wont " */
#define	TS_DO		7	/* do " */
#define	TS_DONT		8	/* dont " */

telrcv()
{
	register int c;
	static int state = TS_DATA;
D 43
	struct sgttyb b;
E 43

	while (ncc > 0) {
		if ((&ptyobuf[BUFSIZ] - pfrontp) < 2)
			return;
		c = *netip++ & 0377, ncc--;
		switch (state) {

I 40
		case TS_CR:
			state = TS_DATA;
I 54
			/* Strip off \n or \0 after a \r */
E 54
D 41
			if (c == 0) {
				*pfrontp++ = '\r';
E 41
I 41
			if ((c == 0) || (c == '\n')) {
E 41
				break;
D 41
			} else if (c == '\n') {
				*pfrontp++ = c;
				break;
			} else
				*pfrontp++ = '\r';
E 41
I 41
			}
E 41
			/* FALL THROUGH */

E 40
		case TS_DATA:
			if (c == IAC) {
				state = TS_IAC;
				break;
			}
			if (inter > 0)
				break;
I 42
			/*
D 54
			 * We map \r\n ==> \n, since \r\n says
E 54
I 54
			 * We now map \r\n ==> \r for pragmatic reasons.
			 * Many client implementations send \r\n when
			 * the user hits the CarriageReturn key.
			 *
			 * We USED to map \r\n ==> \n, since \r\n says
E 54
			 * that we want to be in column 1 of the next
			 * printable line, and \n is the standard
			 * unix way of saying that (\r is only good
			 * if CRMOD is set, which it normally is).
			 */
E 42
D 40
			*pfrontp++ = c;
E 40
D 41
			if (!myopts[TELOPT_BINARY] && c == '\r')
E 41
I 41
D 48
			if (!myopts[TELOPT_BINARY] && c == '\r') {
E 48
I 48
D 51
			if ((myopts[TELOPT_BINARY] == OPT_DONT) && c == '\r') {
E 51
I 51
D 53
			if ((myopts[TELOPT_BINARY] == OPT_NO) && c == '\r') {
E 53
I 53
			if ((c == '\r') && (hisopts[TELOPT_BINARY] == OPT_NO)) {
E 53
E 51
E 48
E 41
D 42
				state = TS_CR;
E 42
I 42
D 54
				if ((ncc > 0) && ('\n' == *netip)) {
					netip++; ncc--;
					c = '\n';
				} else {
					state = TS_CR;
				}
E 54
I 54
				state = TS_CR;
E 54
E 42
D 40
			break;

		case TS_CR:
			if (c && c != '\n')
E 40
I 40
D 41
			else
E 40
				*pfrontp++ = c;
E 41
I 41
			}
			*pfrontp++ = c;
E 41
D 40
			state = TS_DATA;
E 40
			break;

		case TS_IAC:
			switch (c) {

			/*
			 * Send the process on the pty side an
			 * interrupt.  Do this with a NULL or
			 * interrupt char; depending on the tty mode.
			 */
D 46
			case BREAK:
E 46
			case IP:
				interrupt();
				break;

I 46
			case BREAK:
				sendbrk();
				break;

E 46
			/*
			 * Are You There?
			 */
			case AYT:
D 32
				*pfrontp++ = BELL;
E 32
I 32
				strcpy(nfrontp, "\r\n[Yes]\r\n");
				nfrontp += 9;
E 32
				break;

			/*
I 43
			 * Abort Output
			 */
			case AO: {
					struct ltchars tmpltc;

					ptyflush();	/* half-hearted */
					ioctl(pty, TIOCGLTC, &tmpltc);
					if (tmpltc.t_flushc != '\377') {
						*pfrontp++ = tmpltc.t_flushc;
					}
I 47
					netclear();	/* clear buffer back */
E 47
					*nfrontp++ = IAC;
					*nfrontp++ = DM;
D 44
					neturg = nfrontp;
E 44
I 44
					neturg = nfrontp-1; /* off by one XXX */
E 44
					break;
				}

			/*
E 43
			 * Erase Character and
			 * Erase Line
			 */
			case EC:
D 43
			case EL:
				ptyflush();	/* half-hearted */
				ioctl(pty, TIOCGETP, &b);
				*pfrontp++ = (c == EC) ?
					b.sg_erase : b.sg_kill;
				break;
E 43
I 43
			case EL: {
					struct sgttyb b;
					char ch;
E 43

I 43
					ptyflush();	/* half-hearted */
					ioctl(pty, TIOCGETP, &b);
					ch = (c == EC) ?
						b.sg_erase : b.sg_kill;
					if (ch != '\377') {
						*pfrontp++ = ch;
					}
					break;
				}

E 43
			/*
			 * Check for urgent data...
			 */
			case DM:
I 43
				SYNCHing = stilloob(net);
				settimer(gotDM);
E 43
				break;

I 43

E 43
			/*
			 * Begin option subnegotiation...
			 */
			case SB:
D 48
				state = TS_BEGINNEG;
E 48
I 48
				state = TS_SB;
E 48
				continue;

			case WILL:
I 45
				state = TS_WILL;
				continue;

E 45
			case WONT:
I 45
				state = TS_WONT;
				continue;

E 45
			case DO:
I 45
				state = TS_DO;
				continue;

E 45
			case DONT:
D 45
				state = TS_WILL + (c - WILL);
E 45
I 45
				state = TS_DONT;
E 45
				continue;

			case IAC:
				*pfrontp++ = c;
				break;
			}
			state = TS_DATA;
			break;

D 48
		case TS_BEGINNEG:
			if (c == IAC)
				state = TS_ENDNEG;
E 48
I 48
		case TS_SB:
			if (c == IAC) {
				state = TS_SE;
			} else {
				SB_ACCUM(c);
			}
E 48
			break;

D 48
		case TS_ENDNEG:
			state = c == SE ? TS_DATA : TS_BEGINNEG;
E 48
I 48
		case TS_SE:
			if (c != SE) {
				if (c != IAC) {
					SB_ACCUM(IAC);
				}
				SB_ACCUM(c);
				state = TS_SB;
			} else {
				SB_TERM();
				suboption();	/* handle sub-option */
				state = TS_DATA;
			}
E 48
			break;

		case TS_WILL:
D 48
			if (!hisopts[c])
E 48
I 48
D 51
			if (hisopts[c] != OPT_WILL)
E 51
I 51
			if (hisopts[c] != OPT_YES)
E 51
E 48
				willoption(c);
			state = TS_DATA;
			continue;

		case TS_WONT:
D 48
			if (hisopts[c])
E 48
I 48
D 51
			if (hisopts[c] != OPT_WONT)
E 51
I 51
			if (hisopts[c] != OPT_NO)
E 51
E 48
				wontoption(c);
			state = TS_DATA;
			continue;

		case TS_DO:
D 48
			if (!myopts[c])
E 48
I 48
D 51
			if (myopts[c] != OPT_DO)
E 51
I 51
			if (myopts[c] != OPT_YES)
E 51
E 48
				dooption(c);
			state = TS_DATA;
			continue;

		case TS_DONT:
D 48
			if (myopts[c]) {
				myopts[c] = 0;
				sprintf(nfrontp, wont, c);
D 8
				nfrontp += sizeof(wont) - 2;
E 8
I 8
				nfrontp += sizeof (wont) - 2;
E 48
I 48
D 51
			if (myopts[c] != OPT_DONT) {
E 51
I 51
			if (myopts[c] != OPT_NO) {
E 51
				dontoption(c);
E 48
E 8
			}
			state = TS_DATA;
			continue;

		default:
I 50
			syslog(LOG_ERR, "telnetd: panic state=%d\n", state);
E 50
D 10
			printf("netser: panic state=%d\n", state);
E 10
I 10
			printf("telnetd: panic state=%d\n", state);
E 10
			exit(1);
		}
	}
}

willoption(option)
	int option;
{
	char *fmt;

	switch (option) {

	case TELOPT_BINARY:
		mode(RAW, 0);
D 45
		goto common;
E 45
I 45
		fmt = doopt;
		break;
E 45

	case TELOPT_ECHO:
D 48
		mode(0, ECHO|CRMOD);
D 45
		/*FALL THRU*/
E 45
I 45
		fmt = doopt;
E 48
I 48
		not42 = 0;		/* looks like a 4.2 system */
		/*
		 * Now, in a 4.2 system, to break them out of ECHOing
		 * (to the terminal) mode, we need to send a "WILL ECHO".
		 * Kludge upon kludge!
		 */
D 51
		if (myopts[TELOPT_ECHO] == OPT_DO) {
E 51
I 51
		if (myopts[TELOPT_ECHO] == OPT_YES) {
E 51
		    dooption(TELOPT_ECHO);
		}
		fmt = dont;
E 48
		break;
E 45

I 48
	case TELOPT_TTYPE:
I 51
		settimer(ttypeopt);
		if (hisopts[TELOPT_TTYPE] == OPT_YES_BUT_ALWAYS_LOOK) {
		    hisopts[TELOPT_TTYPE] = OPT_YES;
		    return;
		}
		fmt = doopt;
		break;

E 51
E 48
	case TELOPT_SGA:
D 45
	common:
		hisopts[option] = 1;
E 45
		fmt = doopt;
		break;

	case TELOPT_TM:
		fmt = dont;
		break;

	default:
		fmt = dont;
		break;
	}
I 45
	if (fmt == doopt) {
D 48
		hisopts[option] = 1;
E 48
I 48
D 51
		hisopts[option] = OPT_WILL;
E 51
I 51
		hisopts[option] = OPT_YES;
E 51
E 48
	} else {
D 48
		hisopts[option] = 0;
E 48
I 48
D 51
		hisopts[option] = OPT_WONT;
E 51
I 51
		hisopts[option] = OPT_NO;
E 51
E 48
	}
E 45
D 2
	sprintf(nfrontp, dont, option);
E 2
I 2
D 57
	sprintf(nfrontp, fmt, option);
E 57
I 57
	(void) sprintf(nfrontp, fmt, option);
E 57
E 2
D 8
	nfrontp += sizeof(dont) - 2;
E 8
I 8
	nfrontp += sizeof (dont) - 2;
E 8
}

wontoption(option)
	int option;
{
	char *fmt;

	switch (option) {
D 45

E 45
	case TELOPT_ECHO:
D 48
		mode(ECHO|CRMOD, 0);
E 48
I 48
		not42 = 1;		/* doesn't seem to be a 4.2 system */
E 48
D 45
		goto common;
E 45
I 45
		break;
E 45

	case TELOPT_BINARY:
		mode(0, RAW);
D 45
		/*FALL THRU*/

	case TELOPT_SGA:
	common:
		hisopts[option] = 0;
		fmt = dont;
E 45
		break;
I 52

	case TELOPT_TTYPE:
	    settimer(ttypeopt);
	    break;
E 52
D 45

	default:
		fmt = dont;
E 45
	}
I 52

E 52
I 45
	fmt = dont;
D 48
	hisopts[option] = 0;
E 48
I 48
D 51
	hisopts[option] = OPT_WONT;
E 51
I 51
	hisopts[option] = OPT_NO;
E 51
E 48
E 45
D 57
	sprintf(nfrontp, fmt, option);
E 57
I 57
	(void) sprintf(nfrontp, fmt, option);
E 57
D 8
	nfrontp += sizeof(doopt) - 2;
E 8
I 8
	nfrontp += sizeof (doopt) - 2;
E 8
}

dooption(option)
	int option;
{
	char *fmt;

	switch (option) {

	case TELOPT_TM:
		fmt = wont;
		break;

	case TELOPT_ECHO:
		mode(ECHO|CRMOD, 0);
D 45
		goto common;
E 45
I 45
		fmt = will;
		break;
E 45

	case TELOPT_BINARY:
		mode(RAW, 0);
D 45
		/*FALL THRU*/
E 45
I 45
		fmt = will;
		break;
E 45

	case TELOPT_SGA:
D 45
	common:
E 45
		fmt = will;
		break;

	default:
		fmt = wont;
		break;
I 45
	}
	if (fmt == will) {
D 48
	    myopts[option] = 1;
E 48
I 48
D 51
	    myopts[option] = OPT_DO;
E 51
I 51
	    myopts[option] = OPT_YES;
E 51
E 48
	} else {
D 48
	    myopts[option] = 0;
E 48
I 48
D 51
	    myopts[option] = OPT_DONT;
E 51
I 51
	    myopts[option] = OPT_NO;
E 51
E 48
E 45
	}
D 57
	sprintf(nfrontp, fmt, option);
E 57
I 57
	(void) sprintf(nfrontp, fmt, option);
E 57
D 8
	nfrontp += sizeof(doopt) - 2;
E 8
I 8
	nfrontp += sizeof (doopt) - 2;
E 8
}

I 48

dontoption(option)
int option;
{
    char *fmt;

    switch (option) {
    case TELOPT_ECHO:		/* we should stop echoing */
D 56
	mode(0, ECHO|CRMOD);
E 56
I 56
	mode(0, ECHO);
E 56
	fmt = wont;
D 52
	break;
I 51

    case TELOPT_TTYPE:
	fmt = wont;
	settimer(ttypeopt);
E 52
	break;

E 51
    default:
	fmt = wont;
	break;
    }
I 51

E 51
    if (fmt = wont) {
D 51
	myopts[option] = OPT_DONT;
E 51
I 51
	myopts[option] = OPT_NO;
E 51
    } else {
D 51
	myopts[option] = OPT_DO;
E 51
I 51
	myopts[option] = OPT_YES;
E 51
    }
D 57
    sprintf(nfrontp, fmt, option);
E 57
I 57
    (void) sprintf(nfrontp, fmt, option);
E 57
    nfrontp += sizeof (wont) - 2;
}

/*
 * suboption()
 *
 *	Look at the sub-option buffer, and try to be helpful to the other
 * side.
 *
 *	Currently we recognize:
 *
D 51
 *	(nothing - we only do terminal type at start-up time)
E 51
I 51
 *	Terminal type is
E 51
 */

suboption()
{
D 51
    switch (subbuffer[0]&0xff) {
E 51
I 51
    switch (SB_GET()) {
    case TELOPT_TTYPE: {		/* Yaaaay! */
	static char terminalname[5+41] = "TERM=";

	settimer(ttypesubopt);

	if (SB_GET() != TELQUAL_IS) {
	    return;		/* ??? XXX but, this is the most robust */
	}

	terminaltype = terminalname+strlen(terminalname);

	while ((terminaltype < (terminalname + sizeof terminalname-1)) &&
								    !SB_EOF()) {
	    register int c;

	    c = SB_GET();
	    if (isupper(c)) {
		c = tolower(c);
	    }
	    *terminaltype++ = c;    /* accumulate name */
	}
	*terminaltype = 0;
	terminaltype = terminalname;
	break;
    }

E 51
    default:
	;
    }
}

E 48
mode(on, off)
	int on, off;
{
	struct sgttyb b;

	ptyflush();
	ioctl(pty, TIOCGETP, &b);
	b.sg_flags |= on;
	b.sg_flags &= ~off;
	ioctl(pty, TIOCSETP, &b);
}

/*
 * Send interrupt to process on other side of pty.
 * If it is in raw mode, just write NULL;
 * otherwise, write intr char.
 */
interrupt()
{
	struct sgttyb b;
	struct tchars tchars;

	ptyflush();	/* half-hearted */
	ioctl(pty, TIOCGETP, &b);
	if (b.sg_flags & RAW) {
		*pfrontp++ = '\0';
		return;
	}
	*pfrontp++ = ioctl(pty, TIOCGETC, &tchars) < 0 ?
		'\177' : tchars.t_intrc;
I 46
}

/*
 * Send quit to process on other side of pty.
 * If it is in raw mode, just write NULL;
 * otherwise, write quit char.
 */
sendbrk()
{
	struct sgttyb b;
	struct tchars tchars;

	ptyflush();	/* half-hearted */
	ioctl(pty, TIOCGETP, &b);
	if (b.sg_flags & RAW) {
		*pfrontp++ = '\0';
		return;
	}
	*pfrontp++ = ioctl(pty, TIOCGETC, &tchars) < 0 ?
		'\034' : tchars.t_quitc;
E 46
}

ptyflush()
{
	int n;

	if ((n = pfrontp - pbackp) > 0)
		n = write(pty, pbackp, n);
D 7
	if (n < 0 && errno == EWOULDBLOCK)
		n = 0;
E 7
I 7
	if (n < 0)
		return;
E 7
	pbackp += n;
	if (pbackp == pfrontp)
		pbackp = pfrontp = ptyobuf;
}
I 47

/*
 * nextitem()
 *
 *	Return the address of the next "item" in the TELNET data
 * stream.  This will be the address of the next character if
 * the current address is a user data character, or it will
 * be the address of the character following the TELNET command
 * if the current address is a TELNET IAC ("I Am a Command")
 * character.
 */
E 47

I 43
D 47
#if	0
E 43
netflush()
E 47
I 47
char *
nextitem(current)
char	*current;
E 47
{
D 47
	int n;
E 47
I 47
    if ((*current&0xff) != IAC) {
	return current+1;
    }
    switch (*(current+1)&0xff) {
    case DO:
    case DONT:
    case WILL:
    case WONT:
	return current+3;
    case SB:		/* loop forever looking for the SE */
	{
	    register char *look = current+2;
E 47

D 47
	if ((n = nfrontp - nbackp) > 0)
		n = write(net, nbackp, n);
D 7
	if (n < 0 && errno == EWOULDBLOCK)
		n = 0;
E 7
I 7
	if (n < 0) {
		if (errno == EWOULDBLOCK)
			return;
		/* should blow this guy away... */
		return;
E 47
I 47
	    for (;;) {
		if ((*look++&0xff) == IAC) {
		    if ((*look++&0xff) == SE) {
			return look;
		    }
		}
	    }
E 47
	}
E 7
D 47
	nbackp += n;
	if (nbackp == nfrontp)
		nbackp = nfrontp = netobuf;
E 47
I 47
    default:
	return current+2;
    }
E 47
I 2
D 5
}

toggle()
{
	if (debug) {
		fprintf(log, "log stopped\n");
		if (log)
			fclose(log);
	} else {
		if ((log = fopen(logfile, "a")) != NULL) {
			setbuf(log, 0);
			fprintf(log, "log started on /dev/pty%c\n",
				logfile[strlen("/tmp/teldebug")]);
			fprintf(log, "net=%d, pty=%d\n", net, pty);
		}
	}
	debug = !debug;
E 5
E 2
}
I 43
D 47
#else	/* 0 */
E 47


/*
I 47
 * netclear()
 *
 *	We are about to do a TELNET SYNCH operation.  Clear
 * the path to the network.
 *
 *	Things are a bit tricky since we may have sent the first
 * byte or so of a previous TELNET command into the network.
 * So, we have to scan the network buffer from the beginning
 * until we are up to where we want to be.
 *
 *	A side effect of what we do, just to keep things
 * simple, is to clear the urgent data pointer.  The principal
 * caller should be setting the urgent data pointer AFTER calling
 * us in any case.
 */

netclear()
{
    register char *thisitem, *next;
    char *good;
#define	wewant(p)	((nfrontp > p) && ((*p&0xff) == IAC) && \
				((*(p+1)&0xff) != EC) && ((*(p+1)&0xff) != EL))

    thisitem = netobuf;

    while ((next = nextitem(thisitem)) <= nbackp) {
	thisitem = next;
    }

    /* Now, thisitem is first before/at boundary. */

    good = netobuf;	/* where the good bytes go */

    while (nfrontp > thisitem) {
	if (wewant(thisitem)) {
	    int length;

	    next = thisitem;
	    do {
		next = nextitem(next);
	    } while (wewant(next) && (nfrontp > next));
	    length = next-thisitem;
	    bcopy(thisitem, good, length);
	    good += length;
	    thisitem = next;
	} else {
	    thisitem = nextitem(thisitem);
	}
    }

    nbackp = netobuf;
    nfrontp = good;		/* next byte to be sent */
    neturg = 0;
}

/*
E 47
 *  netflush
 *		Send as much data as possible to the network,
 *	handling requests for urgent data.
 */


netflush()
{
    int n;

    if ((n = nfrontp - nbackp) > 0) {
D 48
	if (!neturg) {
E 48
I 48
	/*
	 * if no urgent data, or if the other side appears to be an
	 * old 4.2 client (and thus unable to survive TCP urgent data),
	 * write the entire buffer in non-OOB mode.
	 */
	if ((neturg == 0) || (not42 == 0)) {
E 48
	    n = write(net, nbackp, n);	/* normal write */
	} else {
	    n = neturg - nbackp;
	    /*
	     * In 4.2 (and 4.3) systems, there is some question about
	     * what byte in a sendOOB operation is the "OOB" data.
	     * To make ourselves compatible, we only send ONE byte
	     * out of band, the one WE THINK should be OOB (though
	     * we really have more the TCP philosophy of urgent data
	     * rather than the Unix philosophy of OOB data).
	     */
	    if (n > 1) {
		n = send(net, nbackp, n-1, 0);	/* send URGENT all by itself */
	    } else {
		n = send(net, nbackp, n, MSG_OOB);	/* URGENT data */
	    }
	}
    }
    if (n < 0) {
	if (errno == EWOULDBLOCK)
	    return;
	/* should blow this guy away... */
	return;
    }
    nbackp += n;
    if (nbackp >= neturg) {
	neturg = 0;
    }
    if (nbackp == nfrontp) {
	nbackp = nfrontp = netobuf;
    }
}
D 47
#endif	/* 0 */
E 47
E 43

cleanup()
{
D 15
	int how = 2;
E 15

	rmut();
I 11
D 14
#ifdef notdef
E 11
	vhangup();
I 10
D 11
#ifndef notdef
E 10
	ioctl(net, SIOCDONE, &how);
E 11
I 10
#endif
E 14
I 14
D 62
	vhangup();	/* XXX */
E 62
E 14
I 11
D 15
	ioctl(net, SIOCDONE, &how);
E 15
I 15
	shutdown(net, 2);
E 15
E 11
E 10
D 38
	kill(0, SIGKILL);
E 38
	exit(1);
}

#include <utmp.h>

struct	utmp wtmp;
char	wtmpf[]	= "/usr/adm/wtmp";
D 36
char	utmp[] = "/etc/utmp";
D 8
#define SCPYN(a, b)	strncpy(a, b, sizeof(a))
#define SCMPN(a, b)	strncmp(a, b, sizeof(a))
E 8
I 8
#define SCPYN(a, b)	strncpy(a, b, sizeof (a))
#define SCMPN(a, b)	strncmp(a, b, sizeof (a))
E 36
I 36
char	utmpf[] = "/etc/utmp";
#define SCPYN(a, b)	strncpy(a, b, sizeof(a))
#define SCMPN(a, b)	strncmp(a, b, sizeof(a))
E 36
E 8

rmut()
{
	register f;
	int found = 0;
I 36
	struct utmp *u, *utmp;
	int nutmp;
	struct stat statbf;
E 36

D 32
	f = open(utmp, 2);
E 32
I 32
D 36
	f = open(utmp, O_RDWR);
E 36
I 36
	f = open(utmpf, O_RDWR);
E 36
E 32
	if (f >= 0) {
D 8
		while(read(f, (char *)&wtmp, sizeof(wtmp)) == sizeof(wtmp)) {
E 8
I 8
D 36
		while(read(f, (char *)&wtmp, sizeof (wtmp)) == sizeof (wtmp)) {
E 8
			if (SCMPN(wtmp.ut_line, line+5) || wtmp.ut_name[0]==0)
				continue;
D 8
			lseek(f, -(long)sizeof(wtmp), 1);
E 8
I 8
D 32
			lseek(f, -(long)sizeof (wtmp), 1);
E 32
I 32
			lseek(f, -(long)sizeof (wtmp), L_INCR);
E 32
E 8
			SCPYN(wtmp.ut_name, "");
I 20
			SCPYN(wtmp.ut_host, "");
E 20
			time(&wtmp.ut_time);
D 8
			write(f, (char *)&wtmp, sizeof(wtmp));
E 8
I 8
			write(f, (char *)&wtmp, sizeof (wtmp));
E 8
			found++;
E 36
I 36
		fstat(f, &statbf);
		utmp = (struct utmp *)malloc(statbf.st_size);
		if (!utmp)
			syslog(LOG_ERR, "utmp malloc failed");
		if (statbf.st_size && utmp) {
			nutmp = read(f, utmp, statbf.st_size);
			nutmp /= sizeof(struct utmp);
		
			for (u = utmp ; u < &utmp[nutmp] ; u++) {
				if (SCMPN(u->ut_line, line+5) ||
				    u->ut_name[0]==0)
					continue;
				lseek(f, ((long)u)-((long)utmp), L_SET);
				SCPYN(u->ut_name, "");
				SCPYN(u->ut_host, "");
				time(&u->ut_time);
				write(f, (char *)u, sizeof(wtmp));
				found++;
			}
E 36
		}
		close(f);
	}
	if (found) {
D 32
		f = open(wtmpf, 1);
E 32
I 32
		f = open(wtmpf, O_WRONLY|O_APPEND);
E 32
		if (f >= 0) {
			SCPYN(wtmp.ut_line, line+5);
			SCPYN(wtmp.ut_name, "");
I 20
			SCPYN(wtmp.ut_host, "");
E 20
			time(&wtmp.ut_time);
D 32
			lseek(f, (long)0, 2);
E 32
D 8
			write(f, (char *)&wtmp, sizeof(wtmp));
E 8
I 8
D 36
			write(f, (char *)&wtmp, sizeof (wtmp));
E 36
I 36
			write(f, (char *)&wtmp, sizeof(wtmp));
E 36
E 8
			close(f);
		}
	}
	chmod(line, 0666);
	chown(line, 0, 0);
	line[strlen("/dev/")] = 'p';
	chmod(line, 0666);
	chown(line, 0, 0);
I 59
}

char	editedhost[32];

edithost(pat, host)
	register char *pat;
	register char *host;
{
	register char *res = editedhost;

	if (!pat)
		pat = "";
	while (*pat) {
		switch (*pat) {

		case '#':
			if (*host)
				host++;
			break;

		case '@':
			if (*host)
				*res++ = *host++;
			break;

		default:
			*res++ = *pat;
			break;

		}
		if (res == &editedhost[sizeof editedhost - 1]) {
			*res = '\0';
			return;
		}
		pat++;
	}
	if (*host)
		strncpy(res, host, sizeof editedhost - (res - editedhost) - 1);
	else
		*res = '\0';
	editedhost[sizeof editedhost - 1] = '\0';
}

static char *putlocation;

puts(s)
register char *s;
{

	while (*s)
		putchr(*s++);
}

putchr(cc)
{
	*putlocation++ = cc;
}

D 61
putf(cp, where, tty)
E 61
I 61
putf(cp, where)
E 61
register char *cp;
char *where;
D 61
int tty;
E 61
{
	char *slash;
	char datebuffer[60];
	extern char *rindex();

	putlocation = where;

	while (*cp) {
		if (*cp != '%') {
			putchr(*cp++);
			continue;
		}
		switch (*++cp) {

		case 't':
			slash = rindex(line, '/');
			if (slash == (char *) 0)
				puts(line);
			else
				puts(&slash[1]);
			break;

		case 'h':
			puts(editedhost);
			break;

		case 'd':
			get_date(datebuffer);
			puts(datebuffer);
			break;

		case '%':
			putchr('%');
			break;
		}
		cp++;
	}
E 59
I 20
D 31
}

/*
 * Convert network-format internet address
 * to base 256 d.d.d.d representation.
 */
char *
ntoa(in)
	struct in_addr in;
{
	static char b[18];
	register char *p;

	p = (char *)&in;
#define	UC(b)	(((int)b)&0xff)
	sprintf(b, "%d.%d.%d.%d", UC(p[0]), UC(p[1]), UC(p[2]), UC(p[3]));
	return (b);
E 31
E 20
}
E 1
