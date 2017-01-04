h62605
s 00000/00002/00422
d D 5.15 88/05/23 19:41:27 bostic 46 45
c remove vhangup on exit
e
s 00033/00021/00391
d D 5.14 88/05/22 16:39:58 bostic 45 44
c fix security problem with pty's
e
s 00002/00001/00410
d D 5.13 87/09/09 16:09:32 karels 44 42
c don't accept connections from ports below 512
e
s 00002/00001/00410
d R 5.13 87/09/04 17:46:18 karels 43 42
c don't accept connections from ports below 512
e
s 00001/00000/00410
d D 5.12 87/03/10 16:53:38 mckusick 42 41
c eliminate race in cleanup (4.3BSD/etc/49 from Jeff Smith <aat@j.cc.purdue.edu>)
e
s 00009/00009/00401
d D 5.11 86/05/23 14:40:24 mckusick 41 40
c must be word aligned
e
s 00019/00004/00391
d D 5.10 86/01/07 19:29:32 karels 40 39
c use select on exceptional condition on pty to detect flush faster
e
s 00019/00032/00376
d D 5.9 85/11/08 08:32:50 karels 39 38
c only need to indicate window knowledge in oob messages
c until we get a response; close hole in message after control correctly;
c remove sun grot and other useless code
e
s 00000/00001/00408
d D 5.8 85/10/22 18:43:03 bloom 38 37
c be more social about killing attached processes (vhangup takes care of it)
c (from sun!guy)
e
s 00004/00001/00405
d D 5.7 85/09/17 23:13:07 mckusick 37 35
c take responsibility for reseting window size when first opening pty;
c send window size capability in every oob message in case first is lost
e
s 00004/00001/00405
d R 5.7 85/09/17 23:08:00 mckusick 36 35
c take responsibility for reseting window size when first opening pty;
c send window size capability in every oob message in case first is lost
e
s 00001/00001/00405
d D 5.6 85/09/17 19:17:08 eric 35 33
c facilities in syslog
e
s 00001/00000/00406
d R 5.6 85/09/16 20:26:19 mckusick 34 33
c add slight delay to help expidite setting of window size
e
s 00000/00003/00406
d D 5.5 85/09/12 20:48:38 mckusick 33 30
i 32 31
c merge of Suns changes
e
s 00039/00021/00363
d D 5.2.1.2 85/09/12 20:46:04 mckusick 32 31
c update from Sun
e
s 00000/00000/00384
d D 5.2.1.1 85/09/12 20:30:51 mckusick 31 28
c branch-place-holder
e
s 00007/00004/00381
d D 5.4 85/09/12 20:29:28 mckusick 30 29
c pass through internet number if gethostbyaddr() fails (check in for kjd)
e
s 00001/00000/00384
d D 5.3 85/08/08 13:55:47 bloom 29 28
c disconnect from terminal completely
e
s 00025/00013/00359
d D 5.2 85/06/19 11:14:40 bloom 28 27
c use one read of utmp and use O_APPEND for wtmp to avoid races
c 	(from ks@purdue-ecn)
e
s 00014/00002/00358
d D 5.1 85/05/28 15:20:13 dist 27 26
c Add copyright
e
s 00004/00004/00356
d D 4.25 85/03/24 12:47:22 sam 26 25
c correct comment now that I (believe) I understand ...
e
s 00006/00000/00354
d D 4.24 85/03/23 13:38:52 sam 25 24
c ignore SIGTTOU to avoid problems with csh changing prgrps (when 
c performing TIOCSWINSZ)
e
s 00146/00126/00208
d D 4.23 85/03/17 23:33:03 sam 24 23
c handle propagated window size changes
e
s 00003/00002/00331
d D 4.22 84/09/13 11:33:27 ralph 23 22
c use syslog for error messages
e
s 00002/00002/00331
d D 4.21 84/09/04 21:41:29 sam 22 21
c convert setsockopt calls to new interface
e
s 00020/00086/00313
d D 4.20 84/04/11 15:58:24 karels 21 19
c convert for use with inetd
e
s 00000/00000/00399
d R 4.20 84/04/11 15:37:28 karels 20 19
c convert for inetd
e
s 00025/00011/00374
d D 4.19 84/03/22 15:33:37 karels 19 18
c many cleanups; avoid looping if writes to socket WOULDBLOCK
e
s 00002/00002/00383
d D 4.18 83/07/01 03:19:32 sam 18 17
c add \r so readable
e
s 00001/00000/00384
d D 4.17 83/06/24 12:09:34 sam 17 16
c child inheriting original socket
e
s 00002/00002/00382
d D 4.16 83/06/12 01:40:49 sam 16 15
c new signals
e
s 00001/00001/00383
d D 4.15 83/06/02 17:41:53 sam 15 14
c socket.h
e
s 00002/00000/00382
d D 4.14 83/05/22 23:48:50 sam 14 13
c utmp changed
e
s 00002/00004/00380
d D 4.13 83/05/03 20:54:23 sam 13 12
c turn on keep alives
e
s 00024/00003/00360
d D 4.12 83/02/28 20:07:04 sam 12 11
c printing out illegal address is helpful in debugging
e
s 00003/00001/00360
d D 4.11 83/02/21 19:40:57 sam 11 10
c ignore SIGCHLD in child
e
s 00001/00001/00360
d D 4.10 83/01/22 16:11:09 sam 10 9
c oops
e
s 00024/00006/00337
d D 4.9 83/01/18 19:55:29 sam 9 8
c put back debugging and reap children so no zombies
e
s 00001/00002/00342
d D 4.8 83/01/07 20:36:11 sam 8 7
c no more SIOCDONE
e
s 00001/00000/00343
d D 4.7 82/12/29 15:57:33 sam 7 6
c put vhangup back in to clean pty
e
s 00003/00003/00340
d D 4.6 82/12/25 20:28:17 sam 6 5
c port numbers now byte swapped
e
s 00001/00001/00342
d D 4.5 82/11/15 18:32:53 sam 5 4
c add domain specification
e
s 00051/00020/00292
d D 4.4 82/11/15 01:23:21 sam 4 3
c fix fork failing and make diagnostics consistent
e
s 00022/00016/00290
d D 4.3 82/11/14 15:13:51 sam 3 2
c convert to 4.1c sys calls and directory layout
e
s 00027/00012/00279
d D 4.2 82/10/07 23:42:12 sam 2 1
c use new date base routines
e
s 00291/00000/00000
d D 4.1 82/04/02 10:28:59 wnj 1 0
c date and time created 82/04/02 10:28:59 by wnj
e
u
U
f b 
t
T
I 27
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 27
I 1
#ifndef lint
D 21
static char sccsid[] = "%W% %E%";
E 21
I 21
D 27
static	char sccsid[] = "%W% (Berkeley) %G%";
E 21
#endif
E 27
I 27
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 27

I 21
/*
 * remote login server:
 *	remuser\0
 *	locuser\0
D 24
 *	terminal type\0
E 24
I 24
 *	terminal info\0
E 24
 *	data
 */

E 21
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
I 18
#include <sys/wait.h>
I 24
#include <sys/file.h>
E 24
E 18
D 3
#include <net/in.h>
E 3
I 3

#include <netinet/in.h>

E 3
#include <errno.h>
#include <pwd.h>
D 18
#include <wait.h>
E 18
#include <signal.h>
#include <sgtty.h>
#include <stdio.h>
I 2
#include <netdb.h>
I 23
#include <syslog.h>
I 24
#include <strings.h>
E 24
E 23
E 2

I 32
# ifndef TIOCPKT_WINDOW
# define TIOCPKT_WINDOW 0x80
# endif TIOCPKT_WINDOW

E 32
D 45
extern	errno;
E 45
I 45
extern	int errno;
E 45
I 9
int	reapchild();
E 9
struct	passwd *getpwnam();
D 2
char	*crypt(), *rindex(), *index(), *malloc(), *raddr();
E 2
I 2
D 12
char	*crypt(), *rindex(), *index(), *malloc();
E 12
I 12
D 24
char	*crypt(), *rindex(), *index(), *malloc(), *ntoa();
E 24
I 24
D 32
char	*crypt(), *malloc();
E 32
I 32
char	*malloc();
E 32
E 24
E 12
E 2
D 9
int	options = SO_ACCEPTCONN|SO_KEEPALIVE;
E 9
D 2
struct	sockaddr_in sin = { AF_INET, IPPORT_LOGINSERVER };
E 2
I 2
D 21
struct	sockaddr_in sin = { AF_INET };
E 2
/*
 * remote login server:
 *	remuser\0
 *	locuser\0
 *	terminal type\0
 *	data
 */
E 21
I 21

I 45
/*ARGSUSED*/
E 45
E 21
main(argc, argv)
	int argc;
	char **argv;
{
D 9
	union wait status;
	int f, debug = 0;
E 9
I 9
D 13
	int f, options = SO_KEEPALIVE;
E 13
I 13
D 21
	int f, options = 0;
E 21
I 21
D 22
	int options = 0, fromlen;
E 22
I 22
D 45
	int on = 1, options = 0, fromlen;
E 45
I 45
	int on = 1, fromlen;
E 45
E 22
E 21
E 13
E 9
	struct sockaddr_in from;
I 2
D 21
	struct servent *sp;
E 21
E 2

I 35
	openlog("rlogind", LOG_PID | LOG_AUTH, LOG_AUTH);
E 35
I 2
D 21
	sp = getservbyname("login", "tcp");
	if (sp == 0) {
		fprintf(stderr, "rlogind: tcp/rlogin: unknown service\n");
		exit(1);
E 21
I 21
	fromlen = sizeof (from);
	if (getpeername(0, &from, &fromlen) < 0) {
		fprintf(stderr, "%s: ", argv[0]);
		perror("getpeername");
		_exit(1);
E 21
	}
E 2
D 21
#ifndef DEBUG
	if (fork())
		exit(0);
	for (f = 0; f < 10; f++)
		(void) close(f);
	(void) open("/", 0);
	(void) dup2(0, 1);
	(void) dup2(0, 2);
	{ int tt = open("/dev/tty", 2);
	  if (tt > 0) {
		ioctl(tt, TIOCNOTTY, 0);
		close(tt);
	  }
E 21
I 21
D 22
	if (setsockopt(0, SOL_SOCKET, SO_KEEPALIVE, 0, 0) < 0) {
E 22
I 22
	if (setsockopt(0, SOL_SOCKET, SO_KEEPALIVE, &on, sizeof (on)) < 0) {
E 22
D 23
		fprintf(stderr, "%s: ", argv[0]);
		perror("setsockopt (SO_KEEPALIVE)");
E 23
I 23
D 35
		openlog(argv[0], LOG_PID, 0);
E 35
		syslog(LOG_WARNING, "setsockopt (SO_KEEPALIVE): %m");
E 23
E 21
	}
D 21
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
		options |= SO_DEBUG, argv++, argc--;
	if (argc > 0) {
E 3
I 3
	if (argc > 0 && !strcmp(argv[0], "-d")) {
I 9
		options |= SO_DEBUG;
		argc--, argv++;
	}
	if (argc > 0) {
E 9
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
		argv++, argc--;
	}
I 3
D 5
	f = socket(0, SOCK_STREAM, 0, 0);
E 5
I 5
	f = socket(AF_INET, SOCK_STREAM, 0, 0);
E 5
	if (f < 0) {
		perror("rlogind: socket");
		exit(1);
	}
I 9
	if (options & SO_DEBUG)
		if (setsockopt(f, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
			perror("rlogind: setsockopt (SO_DEBUG)");
D 13
#ifdef notdef
E 13
	if (setsockopt(f, SOL_SOCKET, SO_KEEPALIVE, 0, 0) < 0)
D 13
		perror("rlogind: setsocktopt (SO_KEEPALIVE)");
#endif
E 13
I 13
		perror("rlogind: setsockopt (SO_KEEPALIVE)");
E 13
E 9
	if (bind(f, &sin, sizeof (sin), 0) < 0) {
		perror("rlogind: bind");
		exit(1);
	}
I 9
D 10
	signal(SIGCHLD, reapchild);
E 10
I 10
D 16
	sigset(SIGCHLD, reapchild);
E 16
I 16
	signal(SIGCHLD, reapchild);
E 16
E 10
E 9
	listen(f, 10);
E 3
E 2
	for (;;) {
D 3
		f = socket(SOCK_STREAM, 0, &sin, options);
		if (f < 0) {
			perror("socket");
			sleep(5);
			continue;
		}
		if (accept(f, &from) < 0) {
E 3
I 3
		int s, len = sizeof (from);

		s = accept(f, &from, &len, 0);
		if (s < 0) {
I 9
			if (errno == EINTR)
				continue;
E 9
E 3
D 4
			perror("accept");
E 4
I 4
			perror("rlogind: accept");
E 4
D 3
			close(f);
E 3
D 9
			sleep(1);
E 9
			continue;
		}
D 11
		if (fork() == 0)
E 11
I 11
		if (fork() == 0) {
			signal(SIGCHLD, SIG_IGN);
I 17
			close(f);
E 17
E 11
D 3
			doit(f, &from);
		close(f);
E 3
I 3
			doit(s, &from);
I 11
		}
E 11
		close(s);
E 3
D 9
		while (wait3(status, WNOHANG, 0) > 0)
			continue;
E 9
	}
I 9
}

reapchild()
{
	union wait status;

	while (wait3(&status, WNOHANG, 0) > 0)
		;
E 21
I 21
	doit(0, &from);
E 21
E 9
}

D 24
char	locuser[32], remuser[32];
char	buf[BUFSIZ];
E 24
int	child;
int	cleanup();
int	netf;
D 45
extern	errno;
E 45
char	*line;
I 30
extern	char	*inet_ntoa();
E 30

I 37
struct winsize win = { 0, 0, 0, 0 };
E 37
I 32

I 37

E 37
E 32
doit(f, fromp)
	int f;
	struct sockaddr_in *fromp;
{
D 2
	char c, *rhost;
E 2
I 2
D 24
	char c;
E 2
D 4
	int i, p, cc, t;
E 4
I 4
	int i, p, cc, t, pid;
E 4
	int stop = TIOCPKT_DOSTOP;
E 24
I 24
	int i, p, t, pid, on = 1;
E 24
I 2
	register struct hostent *hp;
I 30
	struct hostent hostent;
E 30
I 24
	char c;
E 24
E 2

	alarm(60);
	read(f, &c, 1);
	if (c != 0)
		exit(1);
	alarm(0);
D 2
#if vax
E 2
D 6
	fromp->sin_port = htons(fromp->sin_port);
E 6
I 6
D 19
	fromp->sin_port = htons((u_short)fromp->sin_port);
E 19
I 19
	fromp->sin_port = ntohs((u_short)fromp->sin_port);
E 19
E 6
D 2
#endif
	rhost = raddr(fromp->sin_addr.s_addr);
E 2
I 2
	hp = gethostbyaddr(&fromp->sin_addr, sizeof (struct in_addr),
		fromp->sin_family);
I 4
D 12
	if (hp == 0)
		fatal(f, "Host name for your address unknown");
E 12
I 12
	if (hp == 0) {
D 19
		char buf[BUFSIZ], *cp = (char *)&fromp->sin_addr;
E 19
I 19
D 30
		char buf[BUFSIZ];
E 19
D 32

		fatal(f, sprintf(buf, "Host name for your address (%s) unknown",
D 24
			ntoa(fromp->sin_addr)));
E 24
I 24
			inet_ntoa(fromp->sin_addr)));
E 32
I 32
D 33
		(void) sprintf(buf, "Host name for your address (%s) unknown",
			inet_ntoa(fromp->sin_addr));
		fatal(f, buf);
E 33
E 32
E 30
I 30
		/*
		 * Only the name is used below.
		 */
		hp = &hostent;
		hp->h_name = inet_ntoa(fromp->sin_addr);
E 30
E 24
	}
E 12
E 4
E 2
	if (fromp->sin_family != AF_INET ||
D 19
	    fromp->sin_port >= IPPORT_RESERVED ||
D 2
	    rhost == 0) {
E 2
I 2
D 4
	    hp == 0) {
E 2
		write(f, "\01Permission denied.\n", 20);
		exit(1);
	}
E 4
I 4
	    hp == 0)
E 19
I 19
D 44
	    fromp->sin_port >= IPPORT_RESERVED)
E 44
I 44
	    fromp->sin_port >= IPPORT_RESERVED ||
	    fromp->sin_port < IPPORT_RESERVED/2)
E 44
E 19
		fatal(f, "Permission denied");
E 4
	write(f, "", 1);
	for (c = 'p'; c <= 's'; c++) {
		struct stat stb;
		line = "/dev/ptyXX";
		line[strlen("/dev/pty")] = c;
		line[strlen("/dev/ptyp")] = '0';
		if (stat(line, &stb) < 0)
			break;
		for (i = 0; i < 16; i++) {
D 45
			line[strlen("/dev/ptyp")] = "0123456789abcdef"[i];
			p = open(line, 2);
E 45
I 45
			line[sizeof("/dev/ptyp") - 1] = "0123456789abcdef"[i];
			p = open(line, O_RDWR);
E 45
			if (p > 0)
				goto gotpty;
		}
	}
D 4
	dup2(f, 1);
	printf("All network ports in use.\r\n");
	exit(1);
E 4
I 4
D 32
	fatal(f, "All network ports in use");
E 32
I 32
	fatal(f, "Out of ptys");
E 32
	/*NOTREACHED*/
E 4
gotpty:
I 37
	(void) ioctl(p, TIOCSWINSZ, &win);
E 37
D 19
	dup2(f, 0);
E 19
I 19
	netf = f;
E 19
	line[strlen("/dev/")] = 't';
I 45
	t = open(line, O_RDWR);
	if (t < 0)
		fatalperror(f, line);
	if (fchmod(t, 0))
		fatalperror(f, line);
	(void)signal(SIGHUP, SIG_IGN);
	vhangup();
	(void)signal(SIGHUP, SIG_DFL);
	t = open(line, O_RDWR);
	if (t < 0)
		fatalperror(f, line);
	{
		struct sgttyb b;

		(void)ioctl(t, TIOCGETP, &b);
		b.sg_flags = RAW|ANYP;
		(void)ioctl(t, TIOCSETP, &b);
	}
E 45
#ifdef DEBUG
D 45
	{ int tt = open("/dev/tty", 2);
	  if (tt > 0) {
		ioctl(tt, TIOCNOTTY, 0);
		close(tt);
	  }
E 45
I 45
	{
		int tt = open("/dev/tty", O_RDWR);
		if (tt > 0) {
			(void)ioctl(tt, TIOCNOTTY, 0);
			(void)close(tt);
		}
E 45
	}
#endif
D 45
	t = open(line, 2);
D 4
	if (t < 0) {
		dup2(f, 2);
		perror(line);
		exit(1);
	}
E 4
I 4
	if (t < 0)
		fatalperror(f, line, errno);
E 4
	{ struct sgttyb b;
	  gtty(t, &b); b.sg_flags = RAW|ANYP; stty(t, &b);
	}
E 45
D 4
	if (fork()) {
E 4
I 4
	pid = fork();
	if (pid < 0)
D 45
		fatalperror(f, "", errno);
E 45
I 45
		fatalperror(f, "");
E 45
D 24
	if (pid) {
E 4
		char pibuf[1024], fibuf[1024], *pbp, *fbp;
D 19
		int pcc = 0, fcc = 0, on = 1;
E 19
I 19
		register pcc = 0, fcc = 0;
		int on = 1;
E 19
/* FILE *console = fopen("/dev/console", "w");  */
/* setbuf(console, 0); */

/* fprintf(console, "f %d p %d\r\n", f, p); */
E 24
I 24
	if (pid == 0) {
		close(f), close(p);
		dup2(t, 0), dup2(t, 1), dup2(t, 2);
E 24
I 19
		close(t);
E 19
D 24
		ioctl(f, FIONBIO, &on);
		ioctl(p, FIONBIO, &on);
		ioctl(p, TIOCPKT, &on);
		signal(SIGTSTP, SIG_IGN);
D 16
		sigset(SIGCHLD, cleanup);
E 16
I 16
		signal(SIGCHLD, cleanup);
E 16
		for (;;) {
			int ibits = 0, obits = 0;
E 24
I 24
		execl("/bin/login", "login", "-r", hp->h_name, 0);
D 45
		fatalperror(2, "/bin/login", errno);
E 45
I 45
		fatalperror(2, "/bin/login");
E 45
		/*NOTREACHED*/
	}
	close(t);
	ioctl(f, FIONBIO, &on);
	ioctl(p, FIONBIO, &on);
	ioctl(p, TIOCPKT, &on);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGCHLD, cleanup);
I 29
	setpgrp(0, 0);
E 29
	protocol(f, p);
I 42
	signal(SIGCHLD, SIG_IGN);
E 42
	cleanup();
}
E 24
D 4
			if (fcc) obits |= (1<<p); else ibits |= (1<<f);
E 4
I 4

D 24
			if (fcc)
				obits |= (1<<p);
E 24
I 24
char	magic[2] = { 0377, 0377 };
I 39
char	oobdata[] = {TIOCPKT_WINDOW};
E 39

/*
 * Handle a "control" request (signaled by magic being present)
 * in the data stream.  For now, we are only willing to handle
 * window size changes.
 */
control(pty, cp, n)
	int pty;
	char *cp;
	int n;
{
D 41
	struct winsize *wp;
E 41
I 41
	struct winsize w;
E 41

D 41
	if (n < 4+sizeof (*wp) || cp[2] != 's' || cp[3] != 's')
E 41
I 41
	if (n < 4+sizeof (w) || cp[2] != 's' || cp[3] != 's')
E 41
		return (0);
I 39
	oobdata[0] &= ~TIOCPKT_WINDOW;	/* we know he heard */
E 39
D 41
	wp = (struct winsize *)(cp+4);
	wp->ws_row = ntohs(wp->ws_row);
	wp->ws_col = ntohs(wp->ws_col);
	wp->ws_xpixel = ntohs(wp->ws_xpixel);
	wp->ws_ypixel = ntohs(wp->ws_ypixel);
	(void)ioctl(pty, TIOCSWINSZ, wp);
	return (4+sizeof (*wp));
E 41
I 41
	bcopy(cp+4, (char *)&w, sizeof(w));
	w.ws_row = ntohs(w.ws_row);
	w.ws_col = ntohs(w.ws_col);
	w.ws_xpixel = ntohs(w.ws_xpixel);
	w.ws_ypixel = ntohs(w.ws_ypixel);
	(void)ioctl(pty, TIOCSWINSZ, &w);
	return (4+sizeof (w));
E 41
}

/*
 * rlogin "protocol" machine.
 */
protocol(f, p)
	int f, p;
{
	char pibuf[1024], fibuf[1024], *pbp, *fbp;
	register pcc = 0, fcc = 0;
D 32
	int cc, stop = TIOCPKT_DOSTOP;
E 32
I 32
D 39
	int cc, stop = TIOCPKT_DOSTOP, wsize;
	static char oob[] = {TIOCPKT_WINDOW};
E 39
I 39
	int cc;
I 40
	char cntl;
E 40
E 39
E 32

I 25
	/*
D 26
	 * This is a hack for the TIOCSWINSZ calls
	 * (csh pgrp manipulation appears to cause
	 * trouble).
E 26
I 26
	 * Must ignore SIGTTOU, otherwise we'll stop
	 * when we try and set slave pty's window shape
D 39
	 * (our pgrp is that of the master pty).
E 39
I 39
	 * (our controlling tty is the master pty).
E 39
E 26
	 */
D 26
	(void) signal(SIGTTOU, SIG_IGN);		/* XXX */
E 26
I 26
	(void) signal(SIGTTOU, SIG_IGN);
I 32
D 39
	send(f, oob, 1, MSG_OOB);	/* indicate new rlogin */
E 39
I 39
	send(f, oobdata, 1, MSG_OOB);	/* indicate new rlogin */
E 39
E 32
E 26
E 25
	for (;;) {
D 40
		int ibits = 0, obits = 0;
E 40
I 40
		int ibits, obits, ebits;
E 40

I 40
		ibits = 0;
		obits = 0;
E 40
		if (fcc)
			obits |= (1<<p);
		else
			ibits |= (1<<f);
		if (pcc >= 0)
			if (pcc)
				obits |= (1<<f);
E 24
			else
D 24
				ibits |= (1<<f);
E 4
			if (pcc >= 0)
D 4
			if (pcc) obits |= (1<<f); else ibits |= (1<<p);
			if (fcc < 0 && pcc < 0) break;
E 4
I 4
				if (pcc)
					obits |= (1<<f);
				else
					ibits |= (1<<p);
D 19
			if (fcc < 0 && pcc < 0)
				break;
E 19
E 4
/* fprintf(console, "ibits from %d obits from %d\r\n", ibits, obits); */
D 3
			select(32, &ibits, &obits, 10000000);
E 3
I 3
D 19
			select(16, &ibits, &obits, 0, 0, 0);
E 19
I 19
			if (select(16, &ibits, &obits, 0, 0) < 0) {
				if (errno == EINTR)
					continue;
				fatalperror(f, "select", errno);
			}
E 19
E 3
/* fprintf(console, "ibits %d obits %d\r\n", ibits, obits); */
			if (ibits == 0 && obits == 0) {
I 19
				/* shouldn't happen... */
E 19
				sleep(5);
E 24
I 24
				ibits |= (1<<p);
D 40
		if (select(16, &ibits, &obits, 0, 0) < 0) {
E 40
I 40
		ebits = (1<<p);
		if (select(16, &ibits, &obits, &ebits, 0) < 0) {
E 40
			if (errno == EINTR)
E 24
				continue;
D 24
			}
			if (ibits & (1<<f)) {
				fcc = read(f, fibuf, sizeof (fibuf));
/* fprintf(console, "%d from f\r\n", fcc); */
				if (fcc < 0 && errno == EWOULDBLOCK)
					fcc = 0;
				else {
					if (fcc <= 0)
						break;
					fbp = fibuf;
				}
			}
			if (ibits & (1<<p)) {
				pcc = read(p, pibuf, sizeof (pibuf));
/* fprintf(console, "%d from p, buf[0] %x, errno %d\r\n", pcc, buf[0], errno); */
				pbp = pibuf;
				if (pcc < 0 && errno == EWOULDBLOCK)
					pcc = 0;
				else if (pcc <= 0)
E 24
I 24
D 45
			fatalperror(f, "select", errno);
E 45
I 45
			fatalperror(f, "select");
E 45
		}
D 40
		if (ibits == 0 && obits == 0) {
E 40
I 40
		if (ibits == 0 && obits == 0 && ebits == 0) {
E 40
			/* shouldn't happen... */
			sleep(5);
			continue;
		}
I 40
#define	pkcontrol(c)	((c)&(TIOCPKT_FLUSHWRITE|TIOCPKT_NOSTOP|TIOCPKT_DOSTOP))
		if (ebits & (1<<p)) {
			cc = read(p, &cntl, 1);
			if (cc == 1 && pkcontrol(cntl)) {
				cntl |= oobdata[0];
				send(f, &cntl, 1, MSG_OOB);
				if (cntl & TIOCPKT_FLUSHWRITE) {
					pcc = 0;
					ibits &= ~(1<<p);
				}
			}
		}
E 40
		if (ibits & (1<<f)) {
			fcc = read(f, fibuf, sizeof (fibuf));
			if (fcc < 0 && errno == EWOULDBLOCK)
				fcc = 0;
			else {
				register char *cp;
				int left, n;

				if (fcc <= 0)
E 24
D 19
					pcc = -1;
E 19
I 19
					break;
E 19
D 24
				else if (pibuf[0] == 0)
					pbp++, pcc--;
				else {
					if (pibuf[0]&(TIOCPKT_FLUSHWRITE|
						      TIOCPKT_NOSTOP|
						      TIOCPKT_DOSTOP)) {
I 19
					/* The following 3 lines do nothing. */
E 19
						int nstop = pibuf[0] &
						    (TIOCPKT_NOSTOP|
						     TIOCPKT_DOSTOP);
						if (nstop)
							stop = nstop;
						pibuf[0] |= nstop;
D 3
						ioctl(f,SIOCSENDOOB,&pibuf[0]);
E 3
I 3
D 15
						send(f,&pibuf[0],1,SOF_OOB);
E 15
I 15
						send(f,&pibuf[0],1,MSG_OOB);
E 24
I 24
				fbp = fibuf;
I 32

E 32
			top:
D 39
				for (cp = fibuf; cp < fibuf+fcc; cp++)
E 39
I 39
				for (cp = fibuf; cp < fibuf+fcc-1; cp++)
E 39
					if (cp[0] == magic[0] &&
					    cp[1] == magic[1]) {
						left = fcc - (cp-fibuf);
						n = control(p, cp, left);
						if (n) {
							left -= n;
							if (left > 0)
D 39
								bcopy(cp, cp+n, left);
E 39
I 39
								bcopy(cp+n, cp, left);
E 39
							fcc -= n;
							goto top; /* n^2 */
D 32
						}
E 24
E 15
E 3
					}
E 32
I 32
D 39
						} /* if (n) */
					} /* for (cp = ) */
				} /* else */
		} /* if (ibits & (1<<f)) */
E 39
I 39
						}
					}
			}
		}
E 39

		if ((obits & (1<<p)) && fcc > 0) {
D 39
			wsize = fcc;
			do {
				cc = write(p, fbp, wsize);
				wsize /= 2;
			} while (cc<0 && errno==EWOULDBLOCK && wsize);
E 39
I 39
			cc = write(p, fbp, fcc);
E 39
			if (cc > 0) {
				fcc -= cc;
				fbp += cc;
E 32
D 24
					pcc = 0;
				}
E 24
			}
D 24
			if ((obits & (1<<f)) && pcc > 0) {
				cc = write(f, pbp, pcc);
I 19
				if (cc < 0 && errno == EWOULDBLOCK) {
					/* also shouldn't happen */
					sleep(5);
					continue;
E 24
I 24
		}
I 32

E 32
		if (ibits & (1<<p)) {
			pcc = read(p, pibuf, sizeof (pibuf));
			pbp = pibuf;
			if (pcc < 0 && errno == EWOULDBLOCK)
				pcc = 0;
			else if (pcc <= 0)
				break;
			else if (pibuf[0] == 0)
				pbp++, pcc--;
			else {
D 40
#define	pkcontrol(c)	((c)&(TIOCPKT_FLUSHWRITE|TIOCPKT_NOSTOP|TIOCPKT_DOSTOP))
E 40
I 32
D 39
				int out = FREAD;

E 39
E 32
				if (pkcontrol(pibuf[0])) {
D 39
				/* The following 3 lines do nothing. */
					int nstop = pibuf[0] &
					    (TIOCPKT_NOSTOP|TIOCPKT_DOSTOP);

					if (nstop)
						stop = nstop;
D 37
					pibuf[0] |= nstop;
E 37
I 37
					pibuf[0] |= nstop | oob[0];
E 39
I 39
					pibuf[0] |= oobdata[0];
E 39
E 37
					send(f, &pibuf[0], 1, MSG_OOB);
I 32
D 39
					if (pibuf[0] & TIOCPKT_FLUSHWRITE)
					  ioctl(p, TIOCFLUSH, (char *)&out);

E 39
E 32
E 24
				}
E 19
D 24
/* fprintf(console, "%d of %d to f\r\n", cc, pcc); */
				if (cc > 0) {
					pcc -= cc;
					pbp += cc;
				}
E 24
I 24
				pcc = 0;
E 24
			}
D 24
			if ((obits & (1<<p)) && fcc > 0) {
				cc = write(p, fbp, fcc);
/* fprintf(console, "%d of %d to p\r\n", cc, fcc); */
				if (cc > 0) {
					fcc -= cc;
					fbp += cc;
				}
E 24
I 24
		}
		if ((obits & (1<<f)) && pcc > 0) {
D 32
			cc = write(f, pbp, pcc);
			if (cc < 0 && errno == EWOULDBLOCK) {
				/* also shouldn't happen */
				sleep(5);
				continue;
E 24
			}
E 32
I 32
D 39
			wsize = pcc;
			do {
				cc = write(f, pbp, wsize);
				wsize /= 2;
			} while (cc<0 && errno==EWOULDBLOCK && wsize);
E 39
I 39
			cc = write(f, pbp, pcc);
			if (cc < 0 && errno == EWOULDBLOCK) {
				/* also shouldn't happen */
				sleep(5);
				continue;
			}
E 39
E 32
I 24
			if (cc > 0) {
				pcc -= cc;
				pbp += cc;
D 32
			}
E 24
		}
D 24
		cleanup();
E 24
I 24
		if ((obits & (1<<p)) && fcc > 0) {
			cc = write(p, fbp, fcc);
			if (cc > 0) {
				fcc -= cc;
				fbp += cc;
E 32
			}
		}
E 24
	}
D 24
	close(f);
	close(p);
	dup2(t, 0);
	dup2(t, 1);
	dup2(t, 2);
	close(t);
D 2
	execl("/bin/login", "login", "-r", rhost, 0);
E 2
I 2
	execl("/bin/login", "login", "-r", hp->h_name, 0);
E 2
D 4
	perror("/bin/login");
	exit(1);
E 4
I 4
	fatalperror(2, "/bin/login", errno);
	/*NOTREACHED*/
E 24
E 4
}

cleanup()
{
D 8
	int how = 2;
E 8
D 46

E 46
	rmut();
I 7
D 46
	vhangup();		/* XXX */
E 46
E 7
D 8
	ioctl(netf, SIOCDONE, &how);
E 8
I 8
	shutdown(netf, 2);
E 8
D 38
	kill(0, SIGKILL);
E 38
	exit(1);
I 4
}

fatal(f, msg)
	int f;
	char *msg;
{
	char buf[BUFSIZ];

	buf[0] = '\01';		/* error indicator */
D 18
	(void) sprintf(buf + 1, "rlogind: %s.\n", msg);
E 18
I 18
	(void) sprintf(buf + 1, "rlogind: %s.\r\n", msg);
E 18
	(void) write(f, buf, strlen(buf));
	exit(1);
}

D 45
fatalperror(f, msg, errno)
E 45
I 45
fatalperror(f, msg)
E 45
	int f;
	char *msg;
D 45
	int errno;
E 45
{
	char buf[BUFSIZ];
I 19
	extern int sys_nerr;
E 19
	extern char *sys_errlist[];

D 19
	(void) sprintf(buf, "%s: %s", msg, sys_errlist[errno]);
E 19
I 19
D 24
	if ((unsigned) errno < sys_nerr)
E 24
I 24
	if ((unsigned)errno < sys_nerr)
E 24
		(void) sprintf(buf, "%s: %s", msg, sys_errlist[errno]);
	else
		(void) sprintf(buf, "%s: Error %d", msg, errno);
E 19
	fatal(f, buf);
E 4
}

#include <utmp.h>

struct	utmp wtmp;
char	wtmpf[]	= "/usr/adm/wtmp";
D 28
char	utmp[] = "/etc/utmp";
E 28
I 28
char	utmpf[] = "/etc/utmp";
E 28
#define SCPYN(a, b)	strncpy(a, b, sizeof(a))
#define SCMPN(a, b)	strncmp(a, b, sizeof(a))

rmut()
{
	register f;
	int found = 0;
I 28
	struct utmp *u, *utmp;
	int nutmp;
	struct stat statbf;
E 28

D 24
	f = open(utmp, 2);
E 24
I 24
D 28
	f = open(utmp, O_RDWR);
E 28
I 28
	f = open(utmpf, O_RDWR);
E 28
E 24
	if (f >= 0) {
D 28
		while(read(f, (char *)&wtmp, sizeof(wtmp)) == sizeof(wtmp)) {
			if (SCMPN(wtmp.ut_line, line+5) || wtmp.ut_name[0]==0)
				continue;
D 24
			lseek(f, -(long)sizeof(wtmp), 1);
E 24
I 24
			lseek(f, -(long)sizeof(wtmp), L_INCR);
E 24
			SCPYN(wtmp.ut_name, "");
I 14
			SCPYN(wtmp.ut_host, "");
E 14
			time(&wtmp.ut_time);
			write(f, (char *)&wtmp, sizeof(wtmp));
			found++;
E 28
I 28
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
E 28
		}
		close(f);
	}
	if (found) {
D 24
		f = open(wtmpf, 1);
E 24
I 24
D 28
		f = open(wtmpf, O_WRONLY);
E 28
I 28
		f = open(wtmpf, O_WRONLY|O_APPEND);
E 28
E 24
		if (f >= 0) {
			SCPYN(wtmp.ut_line, line+5);
			SCPYN(wtmp.ut_name, "");
I 14
			SCPYN(wtmp.ut_host, "");
E 14
			time(&wtmp.ut_time);
D 24
			lseek(f, (long)0, 2);
E 24
I 24
D 28
			lseek(f, (long)0, L_XTND);
E 28
E 24
			write(f, (char *)&wtmp, sizeof(wtmp));
			close(f);
		}
	}
	chmod(line, 0666);
	chown(line, 0, 0);
	line[strlen("/dev/")] = 'p';
	chmod(line, 0666);
	chown(line, 0, 0);
I 12
D 24
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
E 24
E 12
}
E 1
