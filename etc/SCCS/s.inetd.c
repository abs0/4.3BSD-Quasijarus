h23888
s 00010/00005/00944
d D 5.13 88/06/18 14:34:31 bostic 18 17
c install approved copyright notice
e
s 00011/00006/00938
d D 5.12 87/12/26 12:32:35 bostic 17 16
c Berkeley header; declare strdup() properly for ANSI C
e
s 00004/00004/00940
d D 5.11 87/10/22 10:35:54 bostic 16 15
c ANSI C; sprintf now returns an int.
e
s 00028/00021/00916
d D 5.10 87/10/16 16:20:22 karels 15 14
c ignore stop signals, in case we aren't called directly from init/rc
e
s 00043/00052/00894
d D 5.9 87/09/22 08:03:00 bostic 14 13
c redo chargen functions; bug report 4.3BSD/etc/32 
c fix rlogin shell bug; bug report 4.3BSD/etc/33 
c fix long/int problems from 2.10BSD
e
s 00009/00005/00937
d D 5.8 87/09/01 09:38:26 karels 13 12
c fix incorrect title; block signals to test if there's nothing to do
e
s 00024/00002/00918
d D 5.7 86/08/19 09:27:21 karels 12 11
c bug fix, internals had to be last
e
s 00142/00061/00778
d D 5.6 86/04/29 12:35:29 karels 11 10
c notice when server failing, drop service fo a while;
c block all the interesting signals while messing with service blocks;
c check all of the descriptors ready after select
e
s 00024/00018/00815
d D 5.5 86/03/21 06:43:57 lepreau 10 9
c the "user" field was forgotten & thus couldn't be changed; lint.
e
s 00350/00021/00483
d D 5.4 86/03/13 21:25:04 karels 9 8
c add internal services
e
s 00028/00022/00476
d D 5.3 85/09/27 10:40:20 karels 8 7
c changes from tef: allow wait on streams, use sigmask, etc.;
c convert to use new select macros (and up to 256 sockets)
e
s 00001/00001/00497
d D 5.2 85/09/17 19:17:29 eric 7 6
c facilities in syslog
e
s 00014/00002/00484
d D 5.1 85/05/28 14:24:12 dist 6 5
c add copyright
e
s 00013/00000/00473
d D 4.4 84/11/10 22:03:54 bloom 5 3
c added user field to config file so that daemons may be run as somebody 
c besides root
e
s 00012/00000/00473
d R 4.4 84/11/08 17:19:28 bloom 4 3
c add user to config file to allow the servers to run as someone besides
c root
e
s 00006/00003/00467
d D 4.3 84/09/04 21:41:22 sam 3 2
c convert setsockopt calls to new interface
e
s 00017/00020/00453
d D 4.2 84/05/18 11:42:05 ralph 2 1
c modified to use syslog
e
s 00473/00000/00000
d D 4.1 84/04/11 16:31:53 karels 1 0
c date and time created 84/04/11 16:31:53 by karels
e
u
U
t
T
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
D 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 17
I 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 18
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 18
I 18
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
E 18
E 17
 */

E 6
I 1
#ifndef lint
D 6
static	char sccsid[] = "%W% (Berkeley) %G%";
#endif
E 6
I 6
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17
E 6

/*
 * Inetd - Internet super-server
 *
 * This program invokes all internet services as needed.
 * connection-oriented services are invoked each time a
 * connection is made, by creating a process.  This process
 * is passed the connection as file descriptor 0 and is
 * expected to do a getpeername to find out the source host
 * and port.
 *
 * Datagram oriented services are invoked when a datagram
 * arrives; a process is created and passed a pending message
 * on file descriptor 0.  Datagram servers may either connect
 * to their peer, freeing up the original socket for inetd
 * to receive further messages on, or ``take over the socket'',
 * processing all arriving datagrams and, eventually, timing
 * out.	 The first type of server is said to be ``multi-threaded'';
 * the second type of server ``single-threaded''. 
 *
 * Inetd uses a configuration file which is read at startup
 * and, possibly, at some later time in response to a hangup signal.
 * The configuration file is ``free format'' with fields given in the
 * order shown below.  Continuation lines for an entry must being with
 * a space or tab.  All fields must be present in each entry.
 *
 *	service name			must be in /etc/services
 *	socket type			stream/dgram/raw/rdm/seqpacket
 *	protocol			must be in /etc/protocols
 *	wait/nowait			single-threaded/multi-threaded
I 5
 *	user				user to run daemon as
E 5
 *	server program			full path name
 *	server program arguments	maximum of MAXARGS (5)
 *
 * Comment lines are indicated by a `#' in column 1.
 */
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <sys/wait.h>
I 10
#include <sys/time.h>
#include <sys/resource.h>
E 10

#include <netinet/in.h>
#include <arpa/inet.h>

#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <netdb.h>
I 2
#include <syslog.h>
I 5
#include <pwd.h>
E 5
E 2

I 11
#define	TOOMANY		40		/* don't start more than TOOMANY */
#define	CNT_INTVL	60		/* servers in CNT_INTVL sec. */
#define	RETRYTIME	(60*10)		/* retry after bind or server fail */

#define	SIGBLOCK	(sigmask(SIGCHLD)|sigmask(SIGHUP)|sigmask(SIGALRM))

E 11
extern	int errno;

D 11
int	reapchild();
E 11
I 11
int	reapchild(), retry();
E 11
char	*index();
char	*malloc();

int	debug = 0;
D 8
int	allsock;
E 8
I 8
int	nsock, maxsock;
fd_set	allsock;
E 8
int	options;
I 11
int	timingout;
E 11
struct	servent *sp;

struct	servtab {
	char	*se_service;		/* name of service */
	int	se_socktype;		/* type of socket to use */
	char	*se_proto;		/* protocol used */
	short	se_wait;		/* single threaded server */
	short	se_checked;		/* looked at during merge */
I 5
	char	*se_user;		/* user name to run as */
I 9
	struct	biltin *se_bi;		/* if built-in, description */
E 9
E 5
	char	*se_server;		/* server program */
#define MAXARGV 5
	char	*se_argv[MAXARGV+1];	/* program arguments */
	int	se_fd;			/* open descriptor */
	struct	sockaddr_in se_ctrladdr;/* bound address */
I 11
	int	se_count;		/* number started since se_time */
	struct	timeval se_time;	/* start of se_count */
E 11
	struct	servtab *se_next;
} *servtab;

I 9
int echo_stream(), discard_stream(), machtime_stream();
int daytime_stream(), chargen_stream();
int echo_dg(), discard_dg(), machtime_dg(), daytime_dg(), chargen_dg();

struct biltin {
	char	*bi_service;		/* internally provided service name */
	int	bi_socktype;		/* type of socket supported */
	short	bi_fork;		/* 1 if should fork before call */
	short	bi_wait;		/* 1 if should wait for child */
	int	(*bi_fn)();		/* function which performs it */
} biltins[] = {
	/* Echo received data */
	"echo",		SOCK_STREAM,	1, 0,	echo_stream,
	"echo",		SOCK_DGRAM,	0, 0,	echo_dg,

	/* Internet /dev/null */
	"discard",	SOCK_STREAM,	1, 0,	discard_stream,
	"discard",	SOCK_DGRAM,	0, 0,	discard_dg,

	/* Return 32 bit time since 1970 */
	"time",		SOCK_STREAM,	0, 0,	machtime_stream,
	"time",		SOCK_DGRAM,	0, 0,	machtime_dg,

	/* Return human-readable time */
	"daytime",	SOCK_STREAM,	0, 0,	daytime_stream,
	"daytime",	SOCK_DGRAM,	0, 0,	daytime_dg,

	/* Familiar character generator */
	"chargen",	SOCK_STREAM,	1, 0,	chargen_stream,
	"chargen",	SOCK_DGRAM,	0, 0,	chargen_dg,
	0
};

#define NUMINT	(sizeof(intab) / sizeof(struct inent))
E 9
char	*CONFIG = "/etc/inetd.conf";
I 9
char	**Argv;
char 	*LastArg;
E 9

D 9
main(argc, argv)
E 9
I 9
main(argc, argv, envp)
E 9
	int argc;
D 9
	char *argv[];
E 9
I 9
	char *argv[], *envp[];
E 9
{
D 8
	int ctrl;
E 8
	register struct servtab *sep;
I 5
	register struct passwd *pwd;
E 5
	char *cp, buf[50];
D 11
	int pid, i;
E 11
I 11
	int pid, i, dofork;
	struct sigvec sv;
E 11

I 9
	Argv = argv;
	if (envp == 0 || *envp == 0)
		envp = argv;
	while (*envp)
		envp++;
	LastArg = envp[-1] + strlen(envp[-1]);
E 9
	argc--, argv++;
	while (argc > 0 && *argv[0] == '-') {
		for (cp = &argv[0][1]; *cp; cp++) switch (*cp) {

		case 'd':
			debug = 1;
			options |= SO_DEBUG;
			break;

		default:
			fprintf(stderr,
			    "inetd: Unknown flag -%c ignored.\n", *cp);
			break;
		}
nextopt:
		argc--, argv++;
	}
	if (argc > 0)
		CONFIG = argv[0];
D 15
#ifndef DEBUG
	if (fork())
		exit(0);
	{ int s;
	for (s = 0; s < 10; s++)
		(void) close(s);
E 15
I 15
	if (debug == 0) {
		if (fork())
			exit(0);
		{ int s;
		for (s = 0; s < 10; s++)
			(void) close(s);
		}
		(void) open("/", O_RDONLY);
		(void) dup2(0, 1);
		(void) dup2(0, 2);
		{ int tt = open("/dev/tty", O_RDWR);
		  if (tt > 0) {
			ioctl(tt, TIOCNOTTY, (char *)0);
			close(tt);
		  }
		}
		(void) setpgrp(0, 0);
		signal(SIGTSTP, SIG_IGN);
		signal(SIGTTIN, SIG_IGN);
		signal(SIGTTOU, SIG_IGN);
E 15
	}
D 15
	(void) open("/", O_RDONLY);
	(void) dup2(0, 1);
	(void) dup2(0, 2);
	{ int tt = open("/dev/tty", O_RDWR);
	  if (tt > 0) {
D 10
		ioctl(tt, TIOCNOTTY, 0);
E 10
I 10
		ioctl(tt, TIOCNOTTY, (char *)0);
E 10
		close(tt);
	  }
	}
I 14
	(void) setpgrp(0, 0);
E 14
#endif
E 15
I 2
D 7
	openlog("inetd", LOG_PID, 0);
E 7
I 7
D 11
	openlog("inetd", LOG_PID, LOG_DAEMON);
E 11
I 11
	openlog("inetd", LOG_PID | LOG_NOWAIT, LOG_DAEMON);
	bzero((char *)&sv, sizeof(sv));
	sv.sv_mask = SIGBLOCK;
	sv.sv_handler = retry;
	sigvec(SIGALRM, &sv, (struct sigvec *)0);
E 11
E 7
E 2
	config();
D 11
	signal(SIGHUP, config);
	signal(SIGCHLD, reapchild);
E 11
I 11
	sv.sv_handler = config;
	sigvec(SIGHUP, &sv, (struct sigvec *)0);
	sv.sv_handler = reapchild;
	sigvec(SIGCHLD, &sv, (struct sigvec *)0);

E 11
	for (;;) {
D 8
		int readable, s, ctrl;
E 8
I 8
D 11
		int s, ctrl, n;
		fd_set readable;
E 11
I 11
	    int s, ctrl, n;
	    fd_set readable;
E 11
E 8

D 8
		while (allsock == 0)
E 8
I 8
D 11
		while (nsock == 0)
E 8
			sigpause(0);
		readable = allsock;
D 8
		if (select(32, &readable, 0, 0, 0) <= 0)
E 8
I 8
D 10
		if ((n = select(maxsock + 1, &readable, 0, 0, 0)) <= 0)
E 10
I 10
		if ((n = select(maxsock + 1, &readable, (fd_set *)0,
		    (fd_set *)0, (struct timeval *)0)) <= 0)
E 10
E 8
			continue;
D 8
		s = ffs(readable)-1;
		if (s < 0)
			continue;
E 8
I 8
		for (s = 0; s <= maxsock; s++)
			if (FD_ISSET(s, &readable))
				break;
E 8
		for (sep = servtab; sep; sep = sep->se_next)
			if (s == sep->se_fd)
				goto found;
D 10
		abort(1);
E 10
I 10
		abort();
E 10
	found:
E 11
I 11
D 13
	    while (nsock == 0)
E 13
I 13
	    if (nsock == 0) {
		(void) sigblock(SIGBLOCK);
		while (nsock == 0)
E 13
D 14
		    sigpause(0);
I 13
		(void) sigsetmask(0);
E 14
I 14
		    sigpause(0L);
		(void) sigsetmask(0L);
E 14
	    }
E 13
	    readable = allsock;
	    if ((n = select(maxsock + 1, &readable, (fd_set *)0,
		(fd_set *)0, (struct timeval *)0)) <= 0) {
		    if (n < 0 && errno != EINTR)
D 13
				syslog(LOG_WARNING, "select: %m\n");
E 13
I 13
			syslog(LOG_WARNING, "select: %m\n");
E 13
		    sleep(1);
		    continue;
	    }
	    for (sep = servtab; n && sep; sep = sep->se_next)
	    if (FD_ISSET(sep->se_fd, &readable)) {
		n--;
E 11
		if (debug)
			fprintf(stderr, "someone wants %s\n", sep->se_service);
D 8
		if (sep->se_socktype == SOCK_STREAM) {
E 8
I 8
		if (!sep->se_wait && sep->se_socktype == SOCK_STREAM) {
E 8
D 10
			ctrl = accept(s, 0, 0);
E 10
I 10
D 11
			ctrl = accept(s, (struct sockaddr *)0, (int *)0);
E 11
I 11
			ctrl = accept(sep->se_fd, (struct sockaddr *)0,
			    (int *)0);
E 11
E 10
D 2
		if (debug)
			fprintf(stderr, "accept, ctrl %d\n", ctrl);
E 2
I 2
			if (debug)
				fprintf(stderr, "accept, ctrl %d\n", ctrl);
E 2
			if (ctrl < 0) {
				if (errno == EINTR)
					continue;
D 2
				perror("inetd: accept");
E 2
I 2
				syslog(LOG_WARNING, "accept: %m");
E 2
				continue;
			}
		} else
			ctrl = sep->se_fd;
D 8
#define mask(sig)	(1 << (sig - 1))
		sigblock(mask(SIGCHLD)|mask(SIGHUP));
E 8
I 8
D 10
		sigblock(sigmask(SIGCHLD)|sigmask(SIGHUP));
E 10
I 10
D 11
		(void) sigblock(sigmask(SIGCHLD)|sigmask(SIGHUP));
E 11
I 11
		(void) sigblock(SIGBLOCK);
E 11
E 10
E 8
D 9
		pid = fork();
E 9
I 9
		pid = 0;
D 11
		if (sep->se_bi == 0 || sep->se_bi->bi_fork)
E 11
I 11
		dofork = (sep->se_bi == 0 || sep->se_bi->bi_fork);
		if (dofork) {
			if (sep->se_count++ == 0)
			    (void)gettimeofday(&sep->se_time,
			        (struct timezone *)0);
			else if (sep->se_count >= TOOMANY) {
				struct timeval now;

				(void)gettimeofday(&now, (struct timezone *)0);
				if (now.tv_sec - sep->se_time.tv_sec >
				    CNT_INTVL) {
					sep->se_time = now;
					sep->se_count = 1;
				} else {
					syslog(LOG_ERR,
			"%s/%s server failing (looping), service terminated\n",
					    sep->se_service, sep->se_proto);
					FD_CLR(sep->se_fd, &allsock);
					(void) close(sep->se_fd);
					sep->se_fd = -1;
					sep->se_count = 0;
					nsock--;
D 14
					sigsetmask(0);
E 14
I 14
					sigsetmask(0L);
E 14
					if (!timingout) {
						timingout = 1;
						alarm(RETRYTIME);
					}
					continue;
				}
			}
E 11
			pid = fork();
I 11
		}
E 11
E 9
		if (pid < 0) {
D 8
			if (sep->se_socktype == SOCK_STREAM)
E 8
I 8
			if (!sep->se_wait && sep->se_socktype == SOCK_STREAM)
E 8
				close(ctrl);
I 11
D 14
			sigsetmask(0);
E 14
I 14
			sigsetmask(0L);
E 14
E 11
			sleep(1);
			continue;
		}
D 11
		if (sep->se_wait) {
E 11
I 11
		if (pid && sep->se_wait) {
E 11
			sep->se_wait = pid;
D 8
			allsock &= ~(1 << s);
E 8
I 8
D 11
			FD_CLR(s, &allsock);
E 11
I 11
			FD_CLR(sep->se_fd, &allsock);
E 11
			nsock--;
E 8
		}
D 14
		sigsetmask(0);
E 14
I 14
		sigsetmask(0L);
E 14
		if (pid == 0) {
D 15
#ifdef	DEBUG
D 11
			int tt = open("/dev/tty", O_RDWR);
			if (tt > 0) {
E 11
I 11
			int tt;
E 15
I 15
			if (debug) {
			    int tt;
E 15

D 15
			if (dofork && (tt = open("/dev/tty", O_RDWR)) > 0) {
E 15
I 15
			    if (dofork && (tt = open("/dev/tty", O_RDWR)) > 0) {
E 15
E 11
				ioctl(tt, TIOCNOTTY, 0);
				close(tt);
I 15
			    }
			    (void) setpgrp(0, 0);
			    signal(SIGTSTP, SIG_IGN);
			    signal(SIGTTIN, SIG_IGN);
			    signal(SIGTTOU, SIG_IGN);
E 15
			}
D 15
#endif
E 15
D 8
			dup2(ctrl, 0), close(ctrl), dup2(0, 1);
E 8
I 8
D 9
			dup2(ctrl, 0); close(ctrl); dup2(0, 1); dup2(0, 2);
E 8
			for (i = getdtablesize(); --i > 2; )
				close(i);
I 5
			if ((pwd = getpwnam(sep->se_user)) == NULL) {
				syslog(LOG_ERR, "getpwnam: %s: No such user"
					,sep->se_user);
				exit(1);
E 9
I 9
D 11
			if (sep->se_bi == 0 || sep->se_bi->bi_fork)
E 11
I 11
			if (dofork)
E 11
				for (i = getdtablesize(); --i > 2; )
					if (i != ctrl)
						close(i);
			if (sep->se_bi)
				(*sep->se_bi->bi_fn)(ctrl, sep);
			else {
				dup2(ctrl, 0);
				close(ctrl);
				dup2(0, 1);
				dup2(0, 2);
				if ((pwd = getpwnam(sep->se_user)) == NULL) {
					syslog(LOG_ERR,
						"getpwnam: %s: No such user",
						sep->se_user);
I 11
					if (sep->se_socktype != SOCK_STREAM)
						recv(0, buf, sizeof (buf), 0);
E 11
					_exit(1);
				}
				if (pwd->pw_uid) {
D 10
					(void) setgid(pwd->pw_gid);
E 10
I 10
					(void) setgid((gid_t)pwd->pw_gid);
E 10
					initgroups(pwd->pw_name, pwd->pw_gid);
D 10
					(void) setuid(pwd->pw_uid);
E 10
I 10
					(void) setuid((uid_t)pwd->pw_uid);
E 10
				}
				if (debug)
					fprintf(stderr, "%d execl %s\n",
					    getpid(), sep->se_server);
				execv(sep->se_server, sep->se_argv);
				if (sep->se_socktype != SOCK_STREAM)
					recv(0, buf, sizeof (buf), 0);
				syslog(LOG_ERR, "execv %s: %m", sep->se_server);
				_exit(1);
E 9
			}
D 9
			(void) setgid(pwd->pw_gid);
			initgroups(pwd->pw_name, pwd->pw_gid);
			(void) setuid(pwd->pw_uid);
E 5
			if (debug)
				fprintf(stderr, "%d execl %s\n",
				    getpid(), sep->se_server);
			execv(sep->se_server, sep->se_argv);
			if (sep->se_socktype != SOCK_STREAM)
D 2
				recv(0, buf, sizeof (buf));
			if (debug)
				fprintf(stderr, "execl failed\n");
E 2
I 2
				recv(0, buf, sizeof (buf), 0);
			syslog(LOG_ERR, "execv %s: %m", sep->se_server);
E 2
			_exit(1);
E 9
		}
D 8
		if (sep->se_socktype == SOCK_STREAM)
E 8
I 8
		if (!sep->se_wait && sep->se_socktype == SOCK_STREAM)
E 8
			close(ctrl);
I 11
	    }
E 11
	}
}

reapchild()
{
	union wait status;
	int pid;
	register struct servtab *sep;

	for (;;) {
D 10
		pid = wait3(&status, WNOHANG, 0);
E 10
I 10
		pid = wait3(&status, WNOHANG, (struct rusage *)0);
E 10
		if (pid <= 0)
			break;
		if (debug)
			fprintf(stderr, "%d reaped\n", pid);
		for (sep = servtab; sep; sep = sep->se_next)
			if (sep->se_wait == pid) {
				if (status.w_status)
D 2
					fprintf(stderr,
					    "inetd: %s: exit status %d\n",
E 2
I 2
					syslog(LOG_WARNING,
					    "%s: exit status 0x%x",
E 2
					    sep->se_server, status);
				if (debug)
					fprintf(stderr, "restored %s, fd %d\n",
					    sep->se_service, sep->se_fd);
D 8
				allsock |= 1 << sep->se_fd;
E 8
I 8
				FD_SET(sep->se_fd, &allsock);
				nsock++;
E 8
				sep->se_wait = 1;
			}
	}
}

config()
{
	register struct servtab *sep, *cp, **sepp;
	struct servtab *getconfigent(), *enter();
D 3
	int omask;
E 3
I 3
D 11
	int omask, on = 1;
E 11
I 11
D 14
	int omask;
E 14
I 14
	long omask;
E 14
E 11
E 3

	if (!setconfig()) {
D 2
		fprintf(stderr, "inetd: ");
		perror(CONFIG);
E 2
I 2
		syslog(LOG_ERR, "%s: %m", CONFIG);
E 2
		return;
	}
	for (sep = servtab; sep; sep = sep->se_next)
		sep->se_checked = 0;
	while (cp = getconfigent()) {
		for (sep = servtab; sep; sep = sep->se_next)
			if (strcmp(sep->se_service, cp->se_service) == 0 &&
			    strcmp(sep->se_proto, cp->se_proto) == 0)
				break;
		if (sep != 0) {
			int i;

D 8
			omask = sigblock(mask(SIGCHLD));
E 8
I 8
D 11
			omask = sigblock(sigmask(SIGCHLD));
E 8
			sep->se_wait = cp->se_wait;
E 11
I 11
			omask = sigblock(SIGBLOCK);
			if (cp->se_bi == 0)
				sep->se_wait = cp->se_wait;
E 11
#define SWAP(a, b) { char *c = a; a = b; b = c; }
I 10
			if (cp->se_user)
				SWAP(sep->se_user, cp->se_user);
E 10
			if (cp->se_server)
				SWAP(sep->se_server, cp->se_server);
			for (i = 0; i < MAXARGV; i++)
				SWAP(sep->se_argv[i], cp->se_argv[i]);
			sigsetmask(omask);
			freeconfig(cp);
D 12
		} else
E 12
I 12
			if (debug)
				print_service("REDO", sep);
		} else {
E 12
			sep = enter(cp);
I 12
			if (debug)
				print_service("ADD ", sep);
		}
E 12
		sep->se_checked = 1;
D 11
		if (sep->se_fd != -1)
			continue;
E 11
		sp = getservbyname(sep->se_service, sep->se_proto);
		if (sp == 0) {
D 2
			fprintf(stderr,
			    "inetd: %s/%s: unknown service\n",
E 2
I 2
			syslog(LOG_ERR, "%s/%s: unknown service",
E 2
			    sep->se_service, sep->se_proto);
			continue;
		}
D 11
		sep->se_ctrladdr.sin_port = sp->s_port;
		if ((sep->se_fd = socket(AF_INET, sep->se_socktype, 0)) < 0) {
D 2
			fprintf(stderr, "inetd: %s/%s: ",
E 2
I 2
			syslog(LOG_ERR, "%s/%s: socket: %m",
E 2
			    sep->se_service, sep->se_proto);
D 2
			perror("socket");
E 2
			continue;
E 11
I 11
		if (sp->s_port != sep->se_ctrladdr.sin_port) {
			sep->se_ctrladdr.sin_port = sp->s_port;
			if (sep->se_fd != -1)
				(void) close(sep->se_fd);
			sep->se_fd = -1;
E 11
		}
I 3
D 11
#define	turnon(fd, opt) \
D 10
	setsockopt(fd, SOL_SOCKET, opt, &on, sizeof (on))
E 10
I 10
	setsockopt(fd, SOL_SOCKET, opt, (char *)&on, sizeof (on))
E 10
E 3
		if (strcmp(sep->se_proto, "tcp") == 0 && (options & SO_DEBUG) &&
D 3
		    setsockopt(sep->se_fd, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 3
I 3
		    turnon(sep->se_fd, SO_DEBUG) < 0)
E 3
D 2
			perror("inetd: setsockopt (SO_DEBUG)");
E 2
I 2
			syslog(LOG_ERR, "setsockopt (SO_DEBUG): %m");
E 2
D 3
		if (setsockopt(sep->se_fd, SOL_SOCKET, SO_REUSEADDR, 0, 0) < 0)
E 3
I 3
		if (turnon(sep->se_fd, SO_REUSEADDR) < 0)
E 3
D 2
			perror("inetd: setsockopt (SO_REUSEADDR)");
E 2
I 2
			syslog(LOG_ERR, "setsockopt (SO_REUSEADDR): %m");
I 3
#undef turnon
E 3
E 2
		if (bind(sep->se_fd, &sep->se_ctrladdr,
D 10
		    sizeof (sep->se_ctrladdr), 0) < 0) {
E 10
I 10
		    sizeof (sep->se_ctrladdr)) < 0) {
E 10
D 2
			fprintf(stderr, "inetd: %s/%s: ",
E 2
I 2
			syslog(LOG_ERR, "%s/%s: bind: %m",
E 2
			    sep->se_service, sep->se_proto);
D 2
			perror("bind");
E 2
			continue;
		}
		if (sep->se_socktype == SOCK_STREAM)
			listen(sep->se_fd, 10);
D 8
		allsock |= 1 << sep->se_fd;
E 8
I 8
		FD_SET(sep->se_fd, &allsock);
		nsock++;
		if (sep->se_fd > maxsock)
			maxsock = sep->se_fd;
E 11
I 11
		if (sep->se_fd == -1)
			setup(sep);
E 11
E 8
	}
	endconfig();
	/*
	 * Purge anything not looked at above.
	 */
D 8
	omask = sigblock(mask(SIGCHLD));
E 8
I 8
D 11
	omask = sigblock(sigmask(SIGCHLD));
E 11
I 11
	omask = sigblock(SIGBLOCK);
E 11
E 8
	sepp = &servtab;
	while (sep = *sepp) {
		if (sep->se_checked) {
			sepp = &sep->se_next;
			continue;
		}
		*sepp = sep->se_next;
		if (sep->se_fd != -1) {
D 8
			allsock &= ~(1 << sep->se_fd);
E 8
I 8
			FD_CLR(sep->se_fd, &allsock);
			nsock--;
E 8
			(void) close(sep->se_fd);
		}
I 12
		if (debug)
			print_service("FREE", sep);
E 12
		freeconfig(sep);
		free((char *)sep);
	}
	(void) sigsetmask(omask);
}

I 11
retry()
{
	register struct servtab *sep;

	timingout = 0;
	for (sep = servtab; sep; sep = sep->se_next)
		if (sep->se_fd == -1)
			setup(sep);
}

setup(sep)
	register struct servtab *sep;
{
	int on = 1;

	if ((sep->se_fd = socket(AF_INET, sep->se_socktype, 0)) < 0) {
		syslog(LOG_ERR, "%s/%s: socket: %m",
		    sep->se_service, sep->se_proto);
		return;
	}
#define	turnon(fd, opt) \
setsockopt(fd, SOL_SOCKET, opt, (char *)&on, sizeof (on))
	if (strcmp(sep->se_proto, "tcp") == 0 && (options & SO_DEBUG) &&
	    turnon(sep->se_fd, SO_DEBUG) < 0)
		syslog(LOG_ERR, "setsockopt (SO_DEBUG): %m");
	if (turnon(sep->se_fd, SO_REUSEADDR) < 0)
		syslog(LOG_ERR, "setsockopt (SO_REUSEADDR): %m");
#undef turnon
	if (bind(sep->se_fd, &sep->se_ctrladdr,
	    sizeof (sep->se_ctrladdr)) < 0) {
		syslog(LOG_ERR, "%s/%s: bind: %m",
		    sep->se_service, sep->se_proto);
		(void) close(sep->se_fd);
		sep->se_fd = -1;
		if (!timingout) {
			timingout = 1;
			alarm(RETRYTIME);
		}
		return;
	}
	if (sep->se_socktype == SOCK_STREAM)
		listen(sep->se_fd, 10);
	FD_SET(sep->se_fd, &allsock);
	nsock++;
	if (sep->se_fd > maxsock)
		maxsock = sep->se_fd;
}

E 11
struct servtab *
enter(cp)
	struct servtab *cp;
{
	register struct servtab *sep;
D 8
	int omask, i;
E 8
I 8
D 14
	int omask;
E 14
I 14
	long omask;
E 14
E 8
D 17
	char *strdup();
E 17

	sep = (struct servtab *)malloc(sizeof (*sep));
	if (sep == (struct servtab *)0) {
D 2
		fprintf(stderr, "Out of memory.\n");
E 2
I 2
		syslog(LOG_ERR, "Out of memory.");
E 2
		exit(-1);
	}
	*sep = *cp;
	sep->se_fd = -1;
D 8
	omask = sigblock(mask(SIGCHLD));
E 8
I 8
D 11
	omask = sigblock(sigmask(SIGCHLD));
E 11
I 11
	omask = sigblock(SIGBLOCK);
E 11
E 8
	sep->se_next = servtab;
	servtab = sep;
	sigsetmask(omask);
	return (sep);
}

FILE	*fconfig = NULL;
struct	servtab serv;
char	line[256];
char	*skip(), *nextline();

setconfig()
{

	if (fconfig != NULL) {
D 10
		fseek(fconfig, 0, L_SET);
E 10
I 10
		fseek(fconfig, 0L, L_SET);
E 10
		return (1);
	}
	fconfig = fopen(CONFIG, "r");
	return (fconfig != NULL);
}

endconfig()
{

	if (fconfig == NULL)
		return;
	fclose(fconfig);
	fconfig = NULL;
}

struct servtab *
getconfigent()
{
	register struct servtab *sep = &serv;
D 17
	char *cp, *arg;
E 17
	int argc;
I 17
	char *cp, *arg, *strdup();
E 17

I 9
more:
E 9
	while ((cp = nextline(fconfig)) && *cp == '#')
		;
	if (cp == NULL)
		return ((struct servtab *)0);
	sep->se_service = strdup(skip(&cp));
	arg = skip(&cp);
	if (strcmp(arg, "stream") == 0)
		sep->se_socktype = SOCK_STREAM;
	else if (strcmp(arg, "dgram") == 0)
		sep->se_socktype = SOCK_DGRAM;
	else if (strcmp(arg, "rdm") == 0)
		sep->se_socktype = SOCK_RDM;
	else if (strcmp(arg, "seqpacket") == 0)
		sep->se_socktype = SOCK_SEQPACKET;
	else if (strcmp(arg, "raw") == 0)
		sep->se_socktype = SOCK_RAW;
	else
		sep->se_socktype = -1;
	sep->se_proto = strdup(skip(&cp));
	arg = skip(&cp);
	sep->se_wait = strcmp(arg, "wait") == 0;
I 5
	sep->se_user = strdup(skip(&cp));
E 5
	sep->se_server = strdup(skip(&cp));
I 9
	if (strcmp(sep->se_server, "internal") == 0) {
		register struct biltin *bi;

		for (bi = biltins; bi->bi_service; bi++)
			if (bi->bi_socktype == sep->se_socktype &&
			    strcmp(bi->bi_service, sep->se_service) == 0)
				break;
		if (bi->bi_service == 0) {
			syslog(LOG_ERR, "internal service %s unknown\n",
				sep->se_service);
			goto more;
		}
		sep->se_bi = bi;
		sep->se_wait = bi->bi_wait;
D 12
	}
E 12
I 12
	} else
		sep->se_bi = NULL;
E 12
E 9
	argc = 0;
	for (arg = skip(&cp); cp; arg = skip(&cp))
		if (argc < MAXARGV)
			sep->se_argv[argc++] = strdup(arg);
	while (argc <= MAXARGV)
		sep->se_argv[argc++] = NULL;
	return (sep);
}

freeconfig(cp)
	register struct servtab *cp;
{
	int i;

	if (cp->se_service)
		free(cp->se_service);
	if (cp->se_proto)
		free(cp->se_proto);
I 10
	if (cp->se_user)
		free(cp->se_user);
E 10
	if (cp->se_server)
		free(cp->se_server);
	for (i = 0; i < MAXARGV; i++)
		if (cp->se_argv[i])
			free(cp->se_argv[i]);
}

char *
skip(cpp)
	char **cpp;
{
	register char *cp = *cpp;
	char *start;

again:
	while (*cp == ' ' || *cp == '\t')
		cp++;
	if (*cp == '\0') {
		char c;

		c = getc(fconfig);
		ungetc(c, fconfig);
		if (c == ' ' || c == '\t')
			if (cp = nextline(fconfig))
				goto again;
		*cpp = (char *)0;
		return ((char *)0);
	}
	start = cp;
	while (*cp && *cp != ' ' && *cp != '\t')
		cp++;
	if (*cp != '\0')
		*cp++ = '\0';
	*cpp = cp;
	return (start);
}

char *
nextline(fd)
	FILE *fd;
{
	char *cp;

D 10
	if (fgets(line, sizeof (line), fconfig) == NULL)
E 10
I 10
	if (fgets(line, sizeof (line), fd) == NULL)
E 10
		return ((char *)0);
	cp = index(line, '\n');
	if (cp)
		*cp = '\0';
	return (line);
}

char *
strdup(cp)
	char *cp;
{
	char *new;

	if (cp == NULL)
		cp = "";
D 10
	new = malloc(strlen(cp) + 1);
E 10
I 10
	new = malloc((unsigned)(strlen(cp) + 1));
E 10
	if (new == (char *)0) {
D 2
		fprintf(stderr, "Out of memory.\n");
E 2
I 2
		syslog(LOG_ERR, "Out of memory.");
E 2
		exit(-1);
	}
	strcpy(new, cp);
	return (new);
I 9
}

setproctitle(a, s)
	char *a;
	int s;
{
	int size;
	register char *cp;
	struct sockaddr_in sin;
	char buf[80];

	cp = Argv[0];
	size = sizeof(sin);
	if (getpeername(s, &sin, &size) == 0)
D 16
		sprintf(buf, "-%s [%s]", a, inet_ntoa(sin.sin_addr)); 
E 16
I 16
		(void) sprintf(buf, "-%s [%s]", a, inet_ntoa(sin.sin_addr)); 
E 16
	else
D 16
		sprintf(buf, "-%s", a); 
E 16
I 16
		(void) sprintf(buf, "-%s", a); 
E 16
	strncpy(cp, buf, LastArg - cp);
	cp += strlen(cp);
	while (cp < LastArg)
		*cp++ = ' ';
}

/*
 * Internet services provided internally by inetd:
 */

/* ARGSUSED */
echo_stream(s, sep)		/* Echo service -- echo data back */
	int s;
	struct servtab *sep;
{
	char buffer[BUFSIZ];
	int i;

D 13
	setproctitle("echo", s);
E 13
I 13
	setproctitle(sep->se_service, s);
E 13
	while ((i = read(s, buffer, sizeof(buffer))) > 0 &&
	    write(s, buffer, i) > 0)
		;
	exit(0);
}

/* ARGSUSED */
echo_dg(s, sep)			/* Echo service -- echo data back */
	int s;
	struct servtab *sep;
{
	char buffer[BUFSIZ];
	int i, size;
	struct sockaddr sa;

	size = sizeof(sa);
	if ((i = recvfrom(s, buffer, sizeof(buffer), 0, &sa, &size)) < 0)
		return;
	(void) sendto(s, buffer, i, 0, &sa, sizeof(sa));
}

/* ARGSUSED */
discard_stream(s, sep)		/* Discard service -- ignore data */
	int s;
	struct servtab *sep;
{
	char buffer[BUFSIZ];

D 13
	setproctitle("discard", s);
E 13
I 13
	setproctitle(sep->se_service, s);
E 13
	while (1) {
		while (read(s, buffer, sizeof(buffer)) > 0)
			;
		if (errno != EINTR)
			break;
	}
	exit(0);
}

/* ARGSUSED */
discard_dg(s, sep)		/* Discard service -- ignore data */
	int s;
	struct servtab *sep;
{
	char buffer[BUFSIZ];

	(void) read(s, buffer, sizeof(buffer));
}

#include <ctype.h>
#define LINESIZ 72
char ring[128];
char *endring;

initring()
{
	register int i;

	endring = ring;

	for (i = 0; i <= 128; ++i)
		if (isprint(i))
			*endring++ = i;
}

/* ARGSUSED */
chargen_stream(s, sep)		/* Character generator */
	int s;
	struct servtab *sep;
{
I 14
	register char *rs;
	int len;
E 14
	char text[LINESIZ+2];
D 14
	register int i;
	register char *rp, *rs, *dp;
E 14

D 13
	setproctitle("discard", s);
E 13
I 13
	setproctitle(sep->se_service, s);
E 13
D 14
	if (endring == 0)
E 14
I 14

	if (!endring) {
E 14
		initring();
I 14
		rs = ring;
	}
E 14

D 14
	for (rs = ring; ; ++rs) {
		if (rs >= endring)
			rs = ring;
		rp = rs;
		dp = text;
		i = MIN(LINESIZ, endring - rp);
		bcopy(rp, dp, i);
		dp += i;
		if ((rp += i) >= endring)
			rp = ring;
		if (i < LINESIZ) {
			i = LINESIZ - i;
			bcopy(rp, dp, i);
			dp += i;
			if ((rp += i) >= endring)
				rp = ring;
E 14
I 14
	text[LINESIZ] = '\r';
	text[LINESIZ + 1] = '\n';
	for (rs = ring;;) {
		if ((len = endring - rs) >= LINESIZ)
			bcopy(rs, text, LINESIZ);
		else {
			bcopy(rs, text, len);
			bcopy(ring, text + len, LINESIZ - len);
E 14
		}
D 14
		*dp++ = '\r';
		*dp++ = '\n';

		if (write(s, text, dp - text) != dp - text)
E 14
I 14
		if (++rs == endring)
			rs = ring;
		if (write(s, text, sizeof(text)) != sizeof(text))
E 14
			break;
	}
	exit(0);
}

/* ARGSUSED */
chargen_dg(s, sep)		/* Character generator */
	int s;
	struct servtab *sep;
{
D 14
	char text[LINESIZ+2];
	register int i;
	register char *rp;
	static char *rs = ring;
E 14
	struct sockaddr sa;
D 14
	int size;
E 14
I 14
	static char *rs;
	int len, size;
	char text[LINESIZ+2];
E 14

D 14
	if (endring == 0)
E 14
I 14
	if (endring == 0) {
E 14
		initring();
I 14
		rs = ring;
	}
E 14

	size = sizeof(sa);
	if (recvfrom(s, text, sizeof(text), 0, &sa, &size) < 0)
		return;
D 14
	rp = rs;
	if (rs++ >= endring)
		rs = ring;
	i = MIN(LINESIZ - 2, endring - rp);
	bcopy(rp, text, i);
	if ((rp += i) >= endring)
		rp = ring;
	if (i < LINESIZ - 2) {
		bcopy(rp, text, i);
		if ((rp += i) >= endring)
			rp = ring;
	}
	text[LINESIZ - 2] = '\r';
	text[LINESIZ - 1] = '\n';
E 14

I 14
	if ((len = endring - rs) >= LINESIZ)
		bcopy(rs, text, LINESIZ);
	else {
		bcopy(rs, text, len);
		bcopy(ring, text + len, LINESIZ - len);
	}
	if (++rs == endring)
		rs = ring;
	text[LINESIZ] = '\r';
	text[LINESIZ + 1] = '\n';
E 14
	(void) sendto(s, text, sizeof(text), 0, &sa, sizeof(sa));
}

/*
 * Return a machine readable date and time, in the form of the
 * number of seconds since midnight, Jan 1, 1900.  Since gettimeofday
 * returns the number of seconds since midnight, Jan 1, 1970,
 * we must add 2208988800 seconds to this figure to make up for
 * some seventy years Bell Labs was asleep.
 */
D 10
#include <sys/time.h>
E 10

long
machtime()
{
	struct timeval tv;

D 10
	if (gettimeofday(&tv, 0) < 0) {
E 10
I 10
	if (gettimeofday(&tv, (struct timezone *)0) < 0) {
E 10
		fprintf(stderr, "Unable to get time of day\n");
D 10
		return;
E 10
I 10
		return (0L);
E 10
	}
	return (htonl((long)tv.tv_sec + 2208988800));
}

/* ARGSUSED */
machtime_stream(s, sep)
	int s;
	struct servtab *sep;
{
	long result;

	result = machtime();
	(void) write(s, (char *) &result, sizeof(result));
}

/* ARGSUSED */
machtime_dg(s, sep)
	int s;
	struct servtab *sep;
{
	long result;
	struct sockaddr sa;
	int size;

	size = sizeof(sa);
D 10
	if (recvfrom(s, &result, sizeof(result), 0, &sa, &size) < 0)
E 10
I 10
	if (recvfrom(s, (char *)&result, sizeof(result), 0, &sa, &size) < 0)
E 10
		return;
	result = machtime();
	(void) sendto(s, (char *) &result, sizeof(result), 0, &sa, sizeof(sa));
}

/* ARGSUSED */
daytime_stream(s, sep)		/* Return human-readable time of day */
	int s;
	struct servtab *sep;
{
	char buffer[256];
	time_t time(), clock;
	char *ctime();

	clock = time((time_t *) 0);

D 14
	sprintf(buffer, "%s\r", ctime(&clock));
E 14
I 14
D 16
	sprintf(buffer, "%.24s\r\n", ctime(&clock));
E 16
I 16
	(void) sprintf(buffer, "%.24s\r\n", ctime(&clock));
E 16
E 14
D 10
	write(s, buffer, strlen(buffer));
E 10
I 10
	(void) write(s, buffer, strlen(buffer));
E 10
}

/* ARGSUSED */
daytime_dg(s, sep)		/* Return human-readable time of day */
	int s;
	struct servtab *sep;
{
	char buffer[256];
	time_t time(), clock;
	struct sockaddr sa;
	int size;
	char *ctime();

	clock = time((time_t *) 0);

	size = sizeof(sa);
	if (recvfrom(s, buffer, sizeof(buffer), 0, &sa, &size) < 0)
		return;
D 14
	sprintf(buffer, "%s\r", ctime(&clock));
E 14
I 14
D 16
	sprintf(buffer, "%.24s\r\n", ctime(&clock));
E 16
I 16
	(void) sprintf(buffer, "%.24s\r\n", ctime(&clock));
E 16
E 14
	(void) sendto(s, buffer, strlen(buffer), 0, &sa, sizeof(sa));
I 12
}

/*
 * print_service:
 *	Dump relevant information to stderr
 */
print_service(action, sep)
	char *action;
	struct servtab *sep;
{
	fprintf(stderr,
	    "%s: %s proto=%s, wait=%d, user=%s builtin=%x server=%s\n",
	    action, sep->se_service, sep->se_proto,
	    sep->se_wait, sep->se_user, sep->se_bi, sep->se_server);
E 12
E 9
}
E 1
