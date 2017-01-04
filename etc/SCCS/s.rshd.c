h59123
s 00001/00001/00274
d D 5.11 88/04/18 15:06:59 bostic 34 33
c allow root to log in, even if nologin around
e
s 00009/00004/00266
d D 5.10 87/09/04 17:46:21 karels 33 32
c don't accept connections from ports below 512
e
s 00005/00000/00265
d D 5.9 87/05/04 12:03:26 bostic 32 31
c handle presence of /etc/nologin 
e
s 00001/00001/00264
d D 5.8 86/12/09 11:30:11 mckusick 31 30
c Rshd sets nonblocking mode on wrong file descriptor
c (from 4.3BSD/etc/31, serge)
e
s 00018/00019/00247
d D 5.7 86/05/09 03:00:13 lepreau 30 29
c lint
e
s 00007/00010/00259
d D 5.6 86/01/29 14:02:25 karels 29 28
c connection failure on second port unimportant (he gave up);
c don't need to build hostent structures
e
s 00003/00002/00266
d D 5.5 86/01/03 16:27:32 mckusick 28 27
c error needs to take additional arguments (jason@opal)
e
s 00008/00002/00260
d D 5.4 85/09/18 10:12:58 bloom 27 26
c don't exit on gethostbyaddr() failure, pass through address
e
s 00001/00007/00261
d D 5.3 85/09/17 19:12:58 eric 26 25
c facilities in syslog
e
s 00002/00001/00266
d D 5.2 85/08/28 10:02:29 bloom 25 24
c allow null passwd (from serge@arpa)
e
s 00014/00002/00253
d D 5.1 85/05/28 15:32:11 dist 24 23
c Add copyright
e
s 00016/00011/00239
d D 4.21 84/09/13 11:33:19 ralph 23 22
c use syslog for error messages
e
s 00005/00003/00245
d D 4.20 84/09/04 21:41:37 sam 22 21
c convert setsockopt calls to new interface
e
s 00001/00001/00247
d D 4.19 84/05/25 11:54:27 layer 21 20
c fixed exclusion from group 0 (from jrs@purue.arpa)
e
s 00025/00088/00223
d D 4.18 84/04/11 15:58:43 karels 20 18
c convert for use with inetd
e
s 00000/00000/00311
d R 4.18 84/04/11 15:37:33 karels 19 18
c convert for inetd
e
s 00002/00002/00309
d D 4.17 83/07/02 00:19:13 sam 18 17
c include fixes
e
s 00006/00003/00305
d D 4.16 83/06/12 01:46:35 sam 17 16
c new signals and linger no longer default
e
s 00000/00002/00308
d D 4.15 83/05/03 20:54:31 sam 16 15
c turn on keep alives
e
s 00005/00006/00305
d D 4.14 83/02/23 14:00:39 sam 15 13
c plug security hole with root; setgid comes before setuid; 
c parameter passing problem to shutdown
e
s 00004/00003/00308
d R 4.14 83/02/23 13:58:19 sam 14 13
c fix security hole with root; setgid must precede setuid, etc.
e
s 00001/00000/00310
d D 4.13 83/02/21 19:41:37 sam 13 12
c ignore SIGCHLD in child
e
s 00002/00009/00308
d D 4.12 83/02/10 21:30:22 sam 12 11
c remove backoff; DEBUG change before was wrong
e
s 00031/00013/00286
d D 4.11 83/01/22 22:17:48 sam 11 10
c do backoff on connect failure (probably not needed); also 
c postpone dups to allow diagnostics when running in debugging mode
e
s 00001/00001/00298
d D 4.10 83/01/22 16:11:42 sam 10 9
c SIGCHLD reset on each occurance
e
s 00012/00004/00287
d D 4.9 83/01/18 19:41:29 sam 9 8
c reap zombies instead of leaving one always outstanding
e
s 00014/00004/00277
d D 4.8 83/01/13 21:39:51 sam 8 7
c add debugging back in; fix FIN_WAIT_2 problem
e
s 00001/00002/00280
d D 4.7 83/01/07 20:38:00 sam 7 6
c no more SIOCDONE
e
s 00002/00002/00280
d D 4.6 82/12/25 21:18:39 sam 6 5
c port numbers now byte swapped
e
s 00001/00001/00281
d D 4.5 82/11/15 18:33:23 sam 5 4
c add domain specification
e
s 00001/00001/00281
d D 4.4 82/11/15 01:23:55 sam 4 3
c using wrong port for fd 2
e
s 00032/00023/00250
d D 4.3 82/11/14 15:15:12 sam 3 2
c convert to 4.1c sys calls and directory layout
e
s 00027/00016/00246
d D 4.2 82/10/07 23:42:18 sam 2 1
c use new date base routines
e
s 00262/00000/00000
d D 4.1 82/04/02 10:29:04 wnj 1 0
c date and time created 82/04/02 10:29:04 by wnj
e
u
U
f b 
t
T
I 24
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 24
I 1
#ifndef lint
D 18
static char sccsid[] = "%W% %E%";
E 18
I 18
D 20
static char sccsid[] = "%W% (Berkeley) %E%";
E 20
I 20
D 24
static	char sccsid[] = "%W% (Berkeley) %G%";
E 20
E 18
#endif
E 24
I 24
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 24

I 20
/*
 * remote shell server:
 *	remuser\0
 *	locuser\0
 *	command\0
 *	data
 */
E 20
D 3
#include <stdio.h>
E 3
#include <sys/ioctl.h>
#include <sys/param.h>
#include <sys/socket.h>
I 32
#include <sys/file.h>
E 32
I 18
D 30
#include <sys/wait.h>
E 30
I 30
#include <sys/time.h>
E 30
E 18
D 3
#include <net/in.h>
E 3
I 3

#include <netinet/in.h>

I 27
#include <arpa/inet.h>

E 27
#include <stdio.h>
E 3
#include <errno.h>
#include <pwd.h>
D 18
#include <wait.h>
E 18
#include <signal.h>
I 2
#include <netdb.h>
I 23
#include <syslog.h>
E 23
E 2

int	errno;
I 9
D 20
int	reapchild();
E 9
D 2
struct	sockaddr_in sin = { AF_INET, IPPORT_CMDSERVER };
E 2
I 2
struct	sockaddr_in sin = { AF_INET };
E 20
E 2
D 23
struct	passwd *getpwnam();
D 2
char	*index(), *rindex(), *raddr(), *sprintf();
E 2
I 2
char	*index(), *rindex(), *sprintf();
E 23
I 23
D 30
char	*index(), *rindex();
E 23
E 2
D 8
int	options = SO_ACCEPTCONN|SO_KEEPALIVE;
E 8
I 8
D 20
int	options;
E 20
E 8
/* VARARGS 1 */
E 30
I 30
char	*index(), *rindex(), *strncat();
/*VARARGS1*/
E 30
int	error();
D 20
/*
D 17
 * remote execute server:
E 17
I 17
 * remote shell server:
E 17
 *	remuser\0
 *	locuser\0
 *	command\0
 *	data
 */
E 20
I 20

I 30
/*ARGSUSED*/
E 30
E 20
main(argc, argv)
	int argc;
	char **argv;
{
D 9
	union wait status;
E 9
D 17
	int f;
E 17
I 17
D 20
	int f, linger;
E 20
I 20
D 22
	int linger, fromlen;
E 22
I 22
	struct linger linger;
	int on = 1, fromlen;
E 22
E 20
E 17
	struct sockaddr_in from;
I 2
D 20
	struct servent *sp;
E 20
E 2

I 26
	openlog("rsh", LOG_PID | LOG_ODELAY, LOG_DAEMON);
E 26
I 2
D 20
	sp = getservbyname("shell", "tcp");
	if (sp == 0) {
		fprintf(stderr, "rshd: tcp/shell: unknown service\n");
		exit(1);
E 20
I 20
	fromlen = sizeof (from);
	if (getpeername(0, &from, &fromlen) < 0) {
		fprintf(stderr, "%s: ", argv[0]);
		perror("getpeername");
		_exit(1);
E 20
	}
E 2
D 20
#ifndef DEBUG
	if (fork())
		exit(0);
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
E 20
I 20
D 22
	if (setsockopt(0, SOL_SOCKET, SO_KEEPALIVE, 0, 0) < 0) {
E 22
I 22
D 30
	if (setsockopt(0, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof (on)) < 0) {
E 30
I 30
	if (setsockopt(0, SOL_SOCKET, SO_KEEPALIVE, (char *)&on,
	    sizeof (on)) < 0)
E 30
E 22
D 23
		fprintf(stderr, "%s: ", argv[0]);
		perror("setsockopt (SO_KEEPALIVE)");
E 23
I 23
D 26
		openlog(argv[0], LOG_PID, 0);
E 26
		syslog(LOG_WARNING, "setsockopt (SO_KEEPALIVE): %m");
E 23
E 20
D 30
	}
E 30
D 20
#endif
D 2
#if vax
	sin.sin_port = htons(sin.sin_port);
#endif
E 2
I 2
D 6
	sin.sin_port = htons(sp->s_port);
E 6
I 6
	sin.sin_port = sp->s_port;
E 6
E 2
	argc--, argv++;
D 3
	if (argc > 0 && !strcmp(argv[0], "-d"))
D 2
		options |= SO_DEBUG;
E 2
I 2
		options |= SO_DEBUG, argc--, argv++;
	if (argc > 0) {
E 3
I 3
	if (argc > 0 && !strcmp(argv[0], "-d")) {
I 8
		options |= SO_DEBUG;
		argc--, argv++;
	}
	if (argc > 0) {
E 8
E 3
		int port = atoi(argv[0]);

		if (port < 0) {
			fprintf(stderr, "%s: bad port #\n", argv[0]);
			exit(1);
		}
D 6
		sin.sin_port = htons(port);
E 6
I 6
		sin.sin_port = htons((u_short)port);
E 6
		argc--, argv++;
	}
I 3
D 5
	f = socket(0, SOCK_STREAM, 0, 0);
E 5
I 5
	f = socket(AF_INET, SOCK_STREAM, 0, 0);
E 5
	if (f < 0) {
		perror("rshd: socket");
		exit(1);
	}
I 8
	if (options & SO_DEBUG && setsockopt(f, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
		perror("rshd: setsockopt (SO_DEBUG)");
D 16
#ifdef notdef
E 16
	if (setsockopt(f, SOL_SOCKET, SO_KEEPALIVE, 0, 0) < 0)
		perror("rshd: setsockopt (SO_KEEPALIVE)");
E 20
I 17
D 22
	linger = 60;			/* XXX */
E 22
I 22
	linger.l_onoff = 1;
	linger.l_linger = 60;			/* XXX */
E 22
D 20
	if (setsockopt(f, SOL_SOCKET, SO_LINGER, &linger, 0) < 0)
		perror("rshd: setsockopt (SO_LINGER)");
E 17
D 16
#endif
E 16
E 8
	if (bind(f, (caddr_t)&sin, sizeof (sin), 0) < 0) {
		perror("rshd: bind");
		exit(1);
E 20
I 20
D 30
	if (setsockopt(0, SOL_SOCKET, SO_LINGER, &linger, sizeof (linger)) < 0) {
E 30
I 30
	if (setsockopt(0, SOL_SOCKET, SO_LINGER, (char *)&linger,
	    sizeof (linger)) < 0)
E 30
D 23
		fprintf(stderr, "%s: ", argv[0]);
		perror("setsockopt (SO_LINGER)");
E 23
I 23
D 26
		openlog(argv[0], LOG_PID, 0);
E 26
		syslog(LOG_WARNING, "setsockopt (SO_LINGER): %m");
E 23
E 20
D 30
	}
E 30
I 9
D 10
	signal(SIGCHLD, reapchild);
E 10
I 10
D 17
	sigset(SIGCHLD, reapchild);
E 17
I 17
D 20
	signal(SIGCHLD, reapchild);
E 17
E 10
E 9
	listen(f, 10);
E 3
E 2
	for (;;) {
D 3
		errno = 0;
		f = socket(SOCK_STREAM, 0, &sin, options);
		if (f < 0) {
			perror("socket");
			sleep(5);
			continue;
		}
		if (accept(f, &from) < 0) {
E 3
I 3
		int g, len = sizeof (from);

		g = accept(f, &from, &len, 0);
		if (g < 0) {
I 9
			if (errno == EINTR)
				continue;
E 9
E 3
D 8
			perror("accept");
E 8
I 8
			perror("rshd: accept");
E 8
D 3
			(void) close(f);
E 3
D 9
			sleep(1);
E 9
			continue;
		}
D 3
		if (fork() == 0)
			doit(f, &from);
		(void) close(f);
		while(wait3(status, WNOHANG, 0) > 0)
E 3
I 3
		if (fork() == 0) {
D 15
			close(f);
E 15
I 13
			signal(SIGCHLD, SIG_IGN);
I 15
			close(f);
E 15
E 13
			doit(g, &from);
		}
		close(g);
D 9
		while (wait3(status, WNOHANG, 0) > 0)
E 3
			continue;
E 9
	}
E 20
I 20
	doit(dup(0), &from);
E 20
I 9
}

D 20
reapchild()
{
	union wait status;

	while (wait3(&status, WNOHANG, 0) > 0)
		;
E 9
}

E 20
char	username[20] = "USER=";
char	homedir[64] = "HOME=";
char	shell[64] = "SHELL=";
char	*envinit[] =
	    {homedir, shell, "PATH=:/usr/ucb:/bin:/usr/bin", username, 0};
char	**environ;

doit(f, fromp)
	int f;
	struct sockaddr_in *fromp;
{
	char cmdbuf[NCARGS+1], *cp;
	char locuser[16], remuser[16];
	struct passwd *pwd;
D 2
	char *rhost;
E 2
D 11
	int s;
E 11
I 11
D 30
	int s, backoff;
E 30
I 30
	int s;
E 30
E 11
I 2
	struct hostent *hp;
I 27
D 29
	struct hostent hostent;
E 29
I 29
	char *hostname;
E 29
E 27
E 2
	short port;
	int pv[2], pid, ready, readfrom, cc;
	char buf[BUFSIZ], sig;
	int one = 1;

	(void) signal(SIGINT, SIG_DFL);
	(void) signal(SIGQUIT, SIG_DFL);
	(void) signal(SIGTERM, SIG_DFL);
D 8
#ifdef DEBUG
E 8
I 8
D 12
#ifndef DEBUG
E 12
I 12
#ifdef DEBUG
E 12
E 8
	{ int t = open("/dev/tty", 2);
	  if (t >= 0) {
		ioctl(t, TIOCNOTTY, (char *)0);
		(void) close(t);
	  }
	}
#endif
D 11
	dup2(f, 0);
	dup2(f, 1);
	dup2(f, 2);
E 11
D 2
#if vax
E 2
	fromp->sin_port = ntohs((u_short)fromp->sin_port);
D 2
#endif
E 2
D 33
	if (fromp->sin_family != AF_INET ||
D 11
	    fromp->sin_port >= IPPORT_RESERVED)
E 11
I 11
	    fromp->sin_port >= IPPORT_RESERVED) {
E 33
I 33
	if (fromp->sin_family != AF_INET) {
E 33
D 23
		fprintf(stderr, "rshd: malformed from address\n");
E 23
I 23
D 26
		openlog("rshd", LOG_PID, 0);
E 26
		syslog(LOG_ERR, "malformed from address\n");
E 23
E 11
		exit(1);
I 11
	}
I 33
	if (fromp->sin_port >= IPPORT_RESERVED ||
	    fromp->sin_port < IPPORT_RESERVED/2) {
		syslog(LOG_NOTICE, "connection from bad port\n");
		exit(1);
	}
E 33
E 11
	(void) alarm(60);
	port = 0;
	for (;;) {
		char c;
D 11
		if (read(f, &c, 1) != 1)
E 11
I 11
D 33
		if (read(f, &c, 1) != 1) {
D 15
			int how = 1+1;

E 15
D 23
			perror("rshd: read");
E 23
I 23
D 26
			openlog("rshd", LOG_PID, 0);
E 26
			syslog(LOG_ERR, "read: %m");
E 33
I 33
		if ((cc = read(f, &c, 1)) != 1) {
			if (cc < 0)
				syslog(LOG_NOTICE, "read: %m");
E 33
E 23
D 15
			shutdown(f, &how);
E 15
I 15
			shutdown(f, 1+1);
E 15
E 11
			exit(1);
I 11
		}
E 11
		if (c == 0)
			break;
		port = port * 10 + c - '0';
	}
	(void) alarm(0);
	if (port != 0) {
D 3
		s = rresvport(0);
E 3
I 3
D 11
		int lport = IPPORT_RESERVED - 1;
E 11
I 11
D 30
		int lport = IPPORT_RESERVED - 1, retryshift;
E 30
I 30
		int lport = IPPORT_RESERVED - 1;
E 30
E 11
D 8
		s = rresvport(0, &lport);
E 8
I 8
		s = rresvport(&lport);
E 8
E 3
D 11
		if (s < 0)
E 11
I 11
		if (s < 0) {
D 23
			perror("rshd: can't get stderr port");
E 23
I 23
D 26
			openlog("rshd", LOG_PID, 0);
E 26
			syslog(LOG_ERR, "can't get stderr port: %m");
E 23
E 11
			exit(1);
D 11
		if (port >= IPPORT_RESERVED)
			goto protofail;
		(void) alarm(60);
E 11
I 11
		}
		if (port >= IPPORT_RESERVED) {
D 23
			fprintf(stderr, "rshd: 2nd port not reserved\n");
E 23
I 23
D 26
			openlog("rshd", LOG_PID, 0);
E 26
			syslog(LOG_ERR, "2nd port not reserved\n");
E 23
			exit(1);
		}
E 11
D 2
		fromp->sin_port = port;
#if vax
		fromp->sin_port = ntohs(fromp->sin_port);
#endif
E 2
I 2
D 3
		fromp->sin_port = ntohs(port);
E 2
		if (connect(s, fromp) < 0)
E 3
I 3
D 4
		fromp->sin_port = htons((u_short)fromp->sin_port);
E 4
I 4
		fromp->sin_port = htons((u_short)port);
E 4
D 11
		if (connect(s, fromp, sizeof (*fromp), 0) < 0)
E 11
I 11
D 12
		for (backoff = 1; backoff != 0; backoff <<= 1) {
			(void) alarm(60);
			if (connect(s, fromp, sizeof (*fromp), 0) >= 0)
				break;
			(void) alarm(0);
			sleep(backoff);
		}
		if (backoff == 0) {
E 12
I 12
D 30
		if (connect(s, fromp, sizeof (*fromp), 0) < 0) {
E 30
I 30
		if (connect(s, fromp, sizeof (*fromp)) < 0) {
E 30
E 12
D 23
			perror("rshd: connect");
E 23
I 23
D 26
			openlog("rshd", LOG_PID, 0);
E 26
D 29
			syslog(LOG_ERR, "connect: %m");
E 29
I 29
			syslog(LOG_INFO, "connect second port: %m");
E 29
E 23
E 11
E 3
			exit(1);
D 11
		(void) alarm(0);
E 11
I 11
		}
E 11
	}
I 11
	dup2(f, 0);
	dup2(f, 1);
	dup2(f, 2);
E 11
D 2
	rhost = raddr(fromp->sin_addr.s_addr);
	if (rhost == 0) {
E 2
I 2
D 30
	hp = gethostbyaddr(&fromp->sin_addr, sizeof (struct in_addr),
E 30
I 30
	hp = gethostbyaddr((char *)&fromp->sin_addr, sizeof (struct in_addr),
E 30
		fromp->sin_family);
D 29
	if (hp == 0) {
E 2
D 27
		error("Host name for your address unknown\n");
		exit(1);
E 27
I 27
		/*
		 * Only the name is used below
		 */
		hp = &hostent;
		hp->h_name = inet_ntoa(fromp->sin_addr);
E 27
	}
E 29
I 29
	if (hp)
		hostname = hp->h_name;
	else
		hostname = inet_ntoa(fromp->sin_addr);
E 29
	getstr(remuser, sizeof(remuser), "remuser");
	getstr(locuser, sizeof(locuser), "locuser");
	getstr(cmdbuf, sizeof(cmdbuf), "command");
	setpwent();
	pwd = getpwnam(locuser);
	if (pwd == NULL) {
		error("Login incorrect.\n");
		exit(1);
	}
	endpwent();
	if (chdir(pwd->pw_dir) < 0) {
I 20
D 30
		chdir("/");
E 30
I 30
		(void) chdir("/");
E 30
#ifdef notdef
E 20
		error("No remote directory.\n");
		exit(1);
I 20
#endif
E 20
	}
D 2
	if (ruserok(rhost, remuser, locuser) < 0) {
E 2
I 2
D 15
	if (ruserok(hp->h_name, remuser, locuser) < 0) {
E 15
I 15
D 25
	if (ruserok(hp->h_name, pwd->pw_uid == 0, remuser, locuser) < 0) {
E 25
I 25
	if (pwd->pw_passwd != 0 && *pwd->pw_passwd != '\0' &&
D 29
	    ruserok(hp->h_name, pwd->pw_uid == 0, remuser, locuser) < 0) {
E 29
I 29
	    ruserok(hostname, pwd->pw_uid == 0, remuser, locuser) < 0) {
E 29
E 25
E 15
E 2
		error("Permission denied.\n");
I 32
		exit(1);
	}
D 34
	if (!access("/etc/nologin", F_OK)) {
E 34
I 34
	if (pwd->pw_uid && !access("/etc/nologin", F_OK)) {
E 34
		error("Logins currently disabled.\n");
E 32
		exit(1);
	}
	(void) write(2, "\0", 1);
	if (port) {
		if (pipe(pv) < 0) {
			error("Can't make pipe.\n");
			exit(1);
		}
		pid = fork();
		if (pid == -1)  {
			error("Try again.\n");
			exit(1);
		}
		if (pid) {
			(void) close(0); (void) close(1); (void) close(2);
			(void) close(f); (void) close(pv[1]);
			readfrom = (1<<s) | (1<<pv[0]);
D 31
			ioctl(pv[1], FIONBIO, (char *)&one);
E 31
I 31
			ioctl(pv[0], FIONBIO, (char *)&one);
E 31
			/* should set s nbio! */
			do {
				ready = readfrom;
D 3
				(void) select(32, &ready, 0, 1000000);
E 3
I 3
D 30
				if (select(16, &ready, 0, 0, 0) < 0)
E 30
I 30
				if (select(16, &ready, (fd_set *)0,
				    (fd_set *)0, (struct timeval *)0) < 0)
E 30
					break;
E 3
				if (ready & (1<<s)) {
					if (read(s, &sig, 1) <= 0)
						readfrom &= ~(1<<s);
					else
						killpg(pid, sig);
				}
				if (ready & (1<<pv[0])) {
I 15
					errno = 0;
E 15
					cc = read(pv[0], buf, sizeof (buf));
					if (cc <= 0) {
D 7
						int done = 1+1;
						ioctl(s, SIOCDONE, (char *)&done);
E 7
I 7
						shutdown(s, 1+1);
E 7
						readfrom &= ~(1<<pv[0]);
					} else
						(void) write(s, buf, cc);
				}
			} while (readfrom);
			exit(0);
		}
		setpgrp(0, getpid());
		(void) close(s); (void) close(pv[0]);
		dup2(pv[1], 2);
	}
	if (*pwd->pw_shell == '\0')
		pwd->pw_shell = "/bin/sh";
	(void) close(f);
D 3
	inigrp(pwd->pw_name, pwd->pw_gid);
E 3
I 3
D 21
	initgroups(pwd->pw_name, pwd->pw_gid);
E 21
E 3
D 15
	(void) setuid(pwd->pw_uid);
E 15
D 30
	(void) setgid(pwd->pw_gid);
E 30
I 30
	(void) setgid((gid_t)pwd->pw_gid);
E 30
I 21
	initgroups(pwd->pw_name, pwd->pw_gid);
E 21
I 15
D 30
	(void) setuid(pwd->pw_uid);
E 30
I 30
	(void) setuid((uid_t)pwd->pw_uid);
E 30
E 15
	environ = envinit;
	strncat(homedir, pwd->pw_dir, sizeof(homedir)-6);
	strncat(shell, pwd->pw_shell, sizeof(shell)-7);
	strncat(username, pwd->pw_name, sizeof(username)-6);
	cp = rindex(pwd->pw_shell, '/');
	if (cp)
		cp++;
	else
		cp = pwd->pw_shell;
	execl(pwd->pw_shell, cp, "-c", cmdbuf, 0);
	perror(pwd->pw_shell);
	exit(1);
D 30
protofail:
	error("rsh: protocol failure detected by remote\n");
	exit(1);
E 30
}

D 30
/* VARARGS 1 */
E 30
I 30
/*VARARGS1*/
E 30
D 28
error(fmt)
E 28
I 28
error(fmt, a1, a2, a3)
E 28
	char *fmt;
I 28
	int a1, a2, a3;
E 28
{
	char buf[BUFSIZ];

	buf[0] = 1;
D 28
	(void) sprintf(buf+1, fmt);
E 28
I 28
	(void) sprintf(buf+1, fmt, a1, a2, a3);
E 28
	(void) write(2, buf, strlen(buf));
}

getstr(buf, cnt, err)
	char *buf;
	int cnt;
	char *err;
{
	char c;

	do {
		if (read(0, &c, 1) != 1)
			exit(1);
		*buf++ = c;
		if (--cnt == 0) {
			error("%s too long\n", err);
			exit(1);
		}
	} while (c != 0);
}
E 1
