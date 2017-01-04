h21254
s 00010/00003/00654
d D 5.12 09/01/13 07:05:01 msokolov 36 34
c security fix: catch argc == 0
c support for tty-less mode (stdin is not a tty)
c -e with no following char disables the escape feature
e
s 00002/00000/00657
d R 5.12 86/12/10 17:36:42 sam 35 34
c strip parity if we're not using eight-bit stuff
e
s 00129/00078/00528
d D 5.11 86/08/07 13:00:02 mckusick 34 32
c lint plus window size negotiation fixups from Torek
e
s 00130/00079/00527
d R 5.11 86/08/06 22:55:51 mckusick 33 32
c lint plus window size negotiation fixups from Torek
e
s 00046/00002/00560
d D 5.10 86/03/30 16:38:43 karels 32 30
c I'm tired of merging: add sun #ifdefs
e
s 00045/00001/00561
d R 5.10 86/03/30 16:24:04 karels 31 30
c I'm tired of merging; add sun #ifdefs
e
s 00001/00001/00561
d D 5.9 86/02/17 04:27:01 lepreau 30 29
c missing return value
e
s 00108/00038/00454
d D 5.8 85/11/08 09:46:48 karels 29 28
c don't flush input on oob unless it's really a flush; careful about
c restarting syscalls after return from oob(); misc cleanup
e
s 00005/00011/00487
d D 5.7 85/10/30 16:16:31 mckusick 28 27
c -w is obsolete
e
s 00005/00002/00493
d D 5.6 85/09/18 18:31:57 mckusick 27 25
c only send window size the first time it is noted in out of band data
e
s 00002/00001/00494
d R 5.6 85/09/17 23:06:04 mckusick 26 25
c only send window size the first time it is noted in out of band data
e
s 00000/00000/00495
d D 5.5 85/09/12 20:57:19 mckusick 25 22
i 24 23
c merge from Sun
e
s 00073/00052/00421
d D 5.3.1.2 85/09/12 20:55:55 mckusick 24 23
c update from Bill Nowicki at Sun
e
s 00000/00000/00473
d D 5.3.1.1 85/09/12 20:54:21 mckusick 23 21
c branch-place-holder
e
s 00003/00002/00471
d D 5.4 85/07/24 09:14:56 karels 22 21
c ioctl SPGRP -> fcntl F_SETOWN, and reverse sense of proc/pgrp
e
s 00051/00044/00422
d D 5.3 85/06/18 18:30:04 bloom 21 20
c fix handling of escape char and stopping differences (^Z/^Y)
e
s 00002/00001/00464
d D 5.2 85/06/08 13:09:40 bloom 20 19
c fix looping problem if receiving oob data and connection is lost
e
s 00014/00002/00451
d D 5.1 85/05/31 09:43:46 dist 19 18
c Add copyright
e
s 00015/00001/00438
d D 4.18 85/05/31 09:35:59 bloom 18 17
c add litout mode (-L)
e
s 00089/00031/00350
d D 4.17 85/03/17 23:33:20 sam 17 16
c propagate window size changes
e
s 00002/00001/00379
d D 4.16 84/12/03 00:05:49 lepreau 16 15
c cnvt setsockopt to new interface
e
s 00002/00002/00378
d D 4.15 83/07/02 00:55:21 sam 15 14
c include fixes
e
s 00045/00035/00335
d D 4.14 83/06/13 02:47:54 sam 14 13
c boy is this getting boring
e
s 00014/00014/00356
d D 4.13 83/06/10 23:34:44 sam 13 12
c new signals, no libjobs
e
s 00014/00010/00356
d D 4.12 83/04/30 18:53:41 sam 12 11
c from shannon to handle tabs properly and print neater 
c messages when closing connections; also ignore 0177 as a special 
c character -- guess early hope was to propagate break's, but they 
c should be mapped by the terminal handler into signals...
e
s 00043/00014/00323
d D 4.11 83/03/31 10:16:22 edward 11 10
c Fixed backgrounding bug.  Now uses new signals.
e
s 00003/00001/00334
d D 4.10 83/03/03 15:46:47 sam 10 9
c fix from ed wang for hanging on logout
e
s 00007/00007/00328
d D 4.9 83/02/09 17:05:22 sam 9 8
c from sun
e
s 00006/00003/00329
d D 4.8 83/01/18 19:27:51 sam 8 7
c put debugging back in
e
s 00050/00057/00282
d D 4.7 82/12/25 21:11:51 sam 7 6
c use new ioctls; add ^Y command; fix exiting bug
e
s 00000/00004/00339
d D 4.6 82/12/05 22:46:04 sam 6 5
c had broken interrupt flushing
e
s 00157/00454/00186
d D 4.5 82/11/27 16:21:58 sam 5 4
c major rework: 4.1c, netdb.h, eliminate crud, ...
e
s 00004/00002/00636
d D 4.4 82/11/15 01:22:51 sam 4 3
c null pointer problem with TERM
e
s 00002/00002/00636
d D 4.3 82/11/14 15:13:34 sam 3 2
c convert to 4.1c sys calls and directory layout
e
s 00003/00002/00635
d D 4.2 82/04/06 12:54:27 jkf 2 1
c remember settings of ECHO and CRMOD
e
s 00637/00000/00000
d D 4.1 82/04/02 10:28:57 wnj 1 0
c date and time created 82/04/02 10:28:57 by wnj
e
u
U
f b 
t
T
I 19
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 19
I 1
#ifndef lint
D 15
static char sccsid[] = "%W% %E%";
E 15
I 15
D 19
static char sccsid[] = "%W% (Berkeley) %E%";
E 15
#endif
E 19
I 19
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 19

I 13
/*
 * rlogin - remote login
 */
E 13
D 5
#include <stdio.h>
#include <sgtty.h>
E 5
D 32
#include <sys/types.h>
E 32
I 32
#include <sys/param.h>
E 32
I 29
#include <sys/errno.h>
E 29
I 22
#include <sys/file.h>
E 22
#include <sys/socket.h>
I 34
#include <sys/time.h>
#include <sys/resource.h>
E 34
I 15
#include <sys/wait.h>
E 15
I 5

E 5
D 3
#include <net/in.h>
E 3
I 3
#include <netinet/in.h>
I 5

#include <stdio.h>
#include <sgtty.h>
E 5
E 3
#include <errno.h>
#include <pwd.h>
I 5
#include <signal.h>
I 29
#include <setjmp.h>
E 29
#include <netdb.h>
I 17
D 24
#include <setjmp.h>
E 24
E 17
I 11
D 15
#include <wait.h>
E 15
E 11
E 5

I 24
# ifndef TIOCPKT_WINDOW
# define TIOCPKT_WINDOW 0x80
# endif TIOCPKT_WINDOW

E 24
D 13
/*
D 5
 * rlogin - remote login; this is a hacked version of cu
E 5
I 5
 * rlogin - remote login
E 5
 */
E 13
D 34
char	*index(), *rindex(), *malloc(), *getenv();
E 34
I 34
/* concession to sun */
# ifndef SIGUSR1
# define SIGUSR1 30
# endif SIGUSR1

char	*index(), *rindex(), *malloc(), *getenv(), *strcat(), *strcpy();
E 34
struct	passwd *getpwuid();
D 5
struct	passwd *pwd;
char	*name, *pass;
E 5
I 5
char	*name;
E 5
int	rem;
char	cmdchar = '~';
D 8
int	rcmdoptions = 0;
E 8
int	eight;
I 18
int	litout;
I 36
int	notty;
E 36
E 18
char	*speeds[] =
    { "0", "50", "75", "110", "134", "150", "200", "300",
      "600", "1200", "1800", "2400", "4800", "9600", "19200", "38400" };
D 4
char	term[64];
E 4
I 4
D 5
char	term[64] = "dumb";
E 5
I 5
D 17
char	term[64] = "network";
E 17
I 17
char	term[256] = "network";
E 17
extern	int errno;
int	lostpeer();
I 17
D 24
int	nosigwin;
jmp_buf	winsizechanged;
E 24
I 24
int	dosigwinch = 0;
I 32
#ifndef sigmask
#define sigmask(m)	(1 << ((m)-1))
#endif
#ifdef sun
D 34
struct	ttysize winsize;
E 34
struct winsize {
	unsigned short ws_row, ws_col;
	unsigned short ws_xpixel, ws_ypixel;
};
D 34
#else sun
E 32
D 28
int	nosigwin = 0;
E 28
E 24
struct	winsize winsize;
E 34
I 32
#endif sun
I 34
struct	winsize winsize;
E 34
E 32
D 24
int	sigwinch();
E 24
I 24
int	sigwinch(), oob();
E 24
E 17
E 5
E 4

I 34
/*
 * The following routine provides compatibility (such as it is)
 * between 4.2BSD Suns and others.  Suns have only a `ttysize',
 * so we convert it to a winsize.
 */
#ifdef sun
int
get_window_size(fd, wp)
	int fd;
	struct winsize *wp;
{
	struct ttysize ts;
	int error;

	if ((error = ioctl(0, TIOCGSIZE, &ts)) != 0)
		return (error);
	wp->ws_row = ts.ts_lines;
	wp->ws_col = ts.ts_cols;
	wp->ws_xpixel = 0;
	wp->ws_ypixel = 0;
	return (0);
}
#else sun
#define get_window_size(fd, wp)	ioctl(fd, TIOCGWINSZ, wp)
#endif sun

E 34
I 5
D 6
#define	CTRL(c)	('c' & 037)

E 6
E 5
main(argc, argv)
	int argc;
	char **argv;
{
D 5
	int pid;
	char *host, *cp, **ap, buf[BUFSIZ];
	register int cc;
E 5
I 5
	char *host, *cp;
E 5
	struct sgttyb ttyb;
	struct passwd *pwd;
I 5
	struct servent *sp;
D 8
	int uid;
E 8
I 8
D 24
	int uid, options = 0;
E 24
I 24
	int uid, options = 0, oldmask;
E 24
I 16
	int on = 1;
E 16
E 8
E 5

I 36
	if (argc < 1)
		goto usage;
E 36
	host = rindex(argv[0], '/');
	if (host)
		host++;
	else
		host = argv[0];
	argv++, --argc;
	if (!strcmp(host, "rlogin"))
		host = *argv++, --argc;
another:
D 9
	if (!strcmp(*argv, "-d")) {
E 9
I 9
	if (argc > 0 && !strcmp(*argv, "-d")) {
E 9
		argv++, argc--;
D 8
		rcmdoptions |= SO_DEBUG;
E 8
I 8
		options |= SO_DEBUG;
E 8
		goto another;
	}
D 9
	if (!strcmp(*argv, "-l")) {
E 9
I 9
	if (argc > 0 && !strcmp(*argv, "-l")) {
E 9
		argv++, argc--;
		if (argc == 0)
			goto usage;
		name = *argv++; argc--;
		goto another;
	}
D 9
	if (!strncmp(*argv, "-e", 2)) {
E 9
I 9
	if (argc > 0 && !strncmp(*argv, "-e", 2)) {
E 9
		cmdchar = argv[0][2];
		argv++, argc--;
		goto another;
	}
D 9
	if (!strcmp(*argv, "-8")) {
E 9
I 9
	if (argc > 0 && !strcmp(*argv, "-8")) {
E 9
		eight = 1;
		argv++, argc--;
		goto another;
	}
I 18
	if (argc > 0 && !strcmp(*argv, "-L")) {
		litout = 1;
		argv++, argc--;
		goto another;
	}
E 18
I 17
D 28
	if (argc > 0 && !strcmp(*argv, "-w")) {
		nosigwin++;
		argv++, argc--;
		goto another;
	}
E 28
E 17
	if (host == 0)
		goto usage;
	if (argc > 0)
		goto usage;
	pwd = getpwuid(getuid());
	if (pwd == 0) {
		fprintf(stderr, "Who are you?\n");
		exit(1);
	}
D 5
	cc = 0;
E 5
I 5
	sp = getservbyname("login", "tcp");
	if (sp == 0) {
		fprintf(stderr, "rlogin: login/tcp: unknown service\n");
		exit(2);
	}
E 5
D 4
	strcpy(term, getenv("TERM"));
E 4
I 4
	cp = getenv("TERM");
	if (cp)
D 34
		strcpy(term, cp);
E 34
I 34
		(void) strcpy(term, cp);
E 34
E 4
D 7
	if (gtty(0, &ttyb)==0) {
E 7
I 7
D 17
	if (ioctl(0, TIOCGETP, &ttyb)==0) {
E 17
I 17
	if (ioctl(0, TIOCGETP, &ttyb) == 0) {
E 17
E 7
D 34
		strcat(term, "/");
		strcat(term, speeds[ttyb.sg_ospeed]);
E 34
I 34
		(void) strcat(term, "/");
		(void) strcat(term, speeds[ttyb.sg_ospeed]);
E 34
D 36
	}
E 36
I 36
	} else
		eight = notty = 1;
E 36
I 32
D 34
#ifdef sun
	(void) ioctl(0, TIOCGSIZE, &winsize);
#else sun
E 32
I 17
D 24
	if (!nosigwin && ioctl(0, TIOCGWINSZ, &winsize) == 0) {
		cp = index(term, '\0');
		sprintf(cp, "/%u,%u,%u,%u", winsize.ws_row, winsize.ws_col,
		    winsize.ws_xpixel, winsize.ws_ypixel);
	}
E 24
I 24
	(void) ioctl(0, TIOCGWINSZ, &winsize);
I 32
#endif sun
E 32
E 24
E 17
D 5
        rem = rcmd(&host, IPPORT_LOGINSERVER, pwd->pw_name,
E 5
I 5
D 11
	signal(SIGPIPE, lostpeer);
E 11
I 11
D 13
	sigset(SIGPIPE, lostpeer);
E 13
I 13
	signal(SIGPIPE, lostpeer);
I 24
	signal(SIGURG, oob);
	oldmask = sigblock(sigmask(SIGURG));
E 34
I 34
	(void) get_window_size(0, &winsize);
	(void) signal(SIGPIPE, lostpeer);
	/* will use SIGUSR1 for window size hack, so hold it off */
	oldmask = sigblock(sigmask(SIGURG) | sigmask(SIGUSR1));
E 34
E 24
E 13
E 11
        rem = rcmd(&host, sp->s_port, pwd->pw_name,
E 5
	    name ? name : pwd->pw_name, term, 0);
        if (rem < 0)
                exit(1);
I 8
	if (options & SO_DEBUG &&
D 16
	    setsockopt(rem, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 16
I 16
	    setsockopt(rem, SOL_SOCKET, SO_DEBUG, &on, sizeof (on)) < 0)
E 16
		perror("rlogin: setsockopt (SO_DEBUG)");
E 8
D 5
	setuid(getuid());
	cumain();
	exit(0);
E 5
I 5
	uid = getuid();
	if (setuid(uid) < 0) {
		perror("rlogin: setuid");
		exit(1);
	}
D 24
	doit();
E 24
I 24
	doit(oldmask);
E 24
	/*NOTREACHED*/
E 5
usage:
	fprintf(stderr,
D 12
	    "usage: rlogin host [ -ex ] [ -l username ]\n");
E 12
I 12
D 18
	    "usage: rlogin host [ -ex ] [ -l username ] [ -8 ]\n");
E 18
I 18
D 28
	    "usage: rlogin host [ -ex ] [ -l username ] [ -8 ] [ -L ] [ -w ]\n");
E 28
I 28
	    "usage: rlogin host [ -ex ] [ -l username ] [ -8 ] [ -L ]\n");
E 28
E 18
E 12
	exit(1);
}

D 5
#include <ctype.h>
#include <signal.h>

E 5
#define CRLF "\r\n"
D 5
#define wrc(ds) write(ds,&c,1)
E 5

D 5
char	tkill, terase;	/* current input kill & erase */
int	efk;		/* process of id of listener  */
char	c, oc;
int	pipes[] = {-1,-1};
int	intr, sig2();
int	parent;

int	nhup;
E 5
I 5
int	child;
E 5
D 11
int	done();
E 11
I 11
int	catchild();
I 24
D 34
int	writeroob();
E 34
I 34
int	copytochild(), writeroob();
E 34
E 24
E 11

D 5
struct tchars deftchars;
struct tchars notchars = { 0377, 0377, 'q'&037, 's'&037, 0377, 0377 };
struct ltchars defltchars;
struct ltchars noltchars = { 0377, 0377, 0377, 0377, 0377, 0377 };
D 2
char defkill, deferase;
E 2
I 2
char defkill, deferase, defflags;
E 5
I 5
D 7
char	tkill, terase;	/* current input kill & erase */
char	defkill, deferase, defflags;
E 7
I 7
D 14
int	defflags;
I 12
int	tabflag;
E 12
struct	ttychars deftc;
struct	ttychars notc = {
	-1,	-1,	-1,	-1,	-1,
	-1,	-1,	-1,	-1,	-1,
	-1,	-1,	-1,	-1
};
E 14
I 14
int	defflags, tabflag;
I 18
int	deflflags;
E 18
char	deferase, defkill;
struct	tchars deftc;
struct	ltchars defltc;
struct	tchars notc =	{ -1, -1, -1, -1, -1, -1 };
struct	ltchars noltc =	{ -1, -1, -1, -1, -1, -1 };
E 14
E 7
E 5
E 2

D 5
cumain()
E 5
I 5
D 7
struct	tchars deftchars;
struct	tchars notchars = { -1, -1, CTRL(q), CTRL(s), -1, -1 };
struct	ltchars defltchars;
struct	ltchars noltchars = { -1, -1, -1, -1, -1, -1 };

E 7
D 24
doit()
E 24
I 24
doit(oldmask)
E 24
E 5
{
D 5
	int fk;
	int speed;
	char *telno;
E 5
D 7
	struct sgttyb stbuf;
E 7
	int exit();
I 14
	struct sgttyb sb;
E 14

D 5
	gtty(0, &stbuf);
E 5
I 5
D 7
	ioctl(0, TIOCGETP, (char *)&stbuf);
E 5
	defkill = stbuf.sg_kill;
	deferase = stbuf.sg_erase;
I 2
	defflags = stbuf.sg_flags & (ECHO | CRMOD);
E 2
D 5
	ioctl(0, TIOCGETC, &deftchars);
	ioctl(0, TIOCGLTC, &defltchars);
E 5
I 5
	ioctl(0, TIOCGETC, (char *)&deftchars);
	ioctl(0, TIOCGLTC, (char *)&defltchars);
E 7
I 7
D 14
	ioctl(0, TIOCGET, (char *)&defflags);
E 14
I 14
D 34
	ioctl(0, TIOCGETP, (char *)&sb);
E 34
I 34
	(void) ioctl(0, TIOCGETP, (char *)&sb);
E 34
	defflags = sb.sg_flags;
E 14
I 12
	tabflag = defflags & TBDELAY;
E 12
	defflags &= ECHO | CRMOD;
D 14
	ioctl(0, TIOCCGET, (char *)&deftc);
	notc.tc_startc = deftc.tc_startc;
	notc.tc_stopc = deftc.tc_stopc;
E 14
I 14
	deferase = sb.sg_erase;
	defkill = sb.sg_kill;
I 18
D 34
	ioctl(0, TIOCLGET, (char *)&deflflags);
E 18
	ioctl(0, TIOCGETC, (char *)&deftc);
E 34
I 34
	(void) ioctl(0, TIOCLGET, (char *)&deflflags);
	(void) ioctl(0, TIOCGETC, (char *)&deftc);
E 34
	notc.t_startc = deftc.t_startc;
	notc.t_stopc = deftc.t_stopc;
D 34
	ioctl(0, TIOCGLTC, (char *)&defltc);
E 14
E 7
E 5
D 11
	signal(SIGINT, exit);
	signal(SIGHUP, exit);
	signal(SIGQUIT, exit);
E 11
I 11
D 13
	sigset(SIGINT, exit);
	sigset(SIGHUP, exit);
	sigset(SIGQUIT, exit);
E 13
I 13
D 24
	signal(SIGINT, exit);
E 24
I 24
	signal(SIGINT, SIG_IGN);
E 24
	signal(SIGHUP, exit);
	signal(SIGQUIT, exit);
E 34
I 34
	(void) ioctl(0, TIOCGLTC, (char *)&defltc);
	(void) signal(SIGINT, SIG_IGN);
	setsignal(SIGHUP, exit);
	setsignal(SIGQUIT, exit);
E 34
E 13
E 11
D 5
	pipe(pipes);
	parent = getpid();
	fk = fork();
	nhup = (int)signal(SIGINT, SIG_IGN);
	if (fk == 0) {
		rd();
		sleep(1);
E 5
I 5
	child = fork();
	if (child == -1) {
		perror("rlogin: fork");
D 29
		done();
E 29
I 29
		done(1);
E 29
	}
D 11
	signal(SIGINT, SIG_IGN);
E 11
I 11
D 13
	sigignore(SIGINT);
E 13
I 13
D 24
	signal(SIGINT, SIG_IGN);
E 13
	mode(1);
E 24
E 11
	if (child == 0) {
I 24
		mode(1);
D 34
		sigsetmask(oldmask);
E 24
D 7
		signal(SIGPIPE, SIG_IGN);
E 7
D 29
		reader();
E 29
I 29
		if (reader() == 0) {
E 34
I 34
		if (reader(oldmask) == 0) {
E 34
			prf("Connection closed.");
			exit(0);
		}
E 29
E 5
D 12
		prf("\007Lost connection.");
E 12
I 12
		sleep(1);
		prf("\007Connection closed.");
E 12
		exit(3);
	}
I 24
D 34
	signal(SIGURG, writeroob);
	sigsetmask(oldmask);
E 24
D 11
	signal(SIGCHLD, done);
	mode(1);
E 11
I 11
D 13
	sigset(SIGCHLD, catchild);
E 13
I 13
	signal(SIGCHLD, catchild);
E 34
I 34

	/*
	 * We may still own the socket, and may have a pending SIGURG
	 * (or might receive one soon) that we really want to send to
	 * the reader.  Set a trap that simply copies such signals to
	 * the child.
	 */
	(void) signal(SIGURG, copytochild);
	(void) signal(SIGUSR1, writeroob);
	(void) sigsetmask(oldmask);
	(void) signal(SIGCHLD, catchild);
E 34
I 17
D 28
	if (!nosigwin)
		signal(SIGWINCH, sigwinch);
E 28
E 17
E 13
E 11
D 5
	efk = fk;
	wr();
	if (fk != -1) kill(fk, SIGKILL);
E 5
I 5
	writer();
E 5
D 12
	prf("Disconnected.");
E 12
I 12
	prf("Closed connection.");
E 12
D 29
	done();
E 29
I 29
	done(0);
E 29
}

I 34
/*
 * Trap a signal, unless it is being ignored.
 */
setsignal(sig, act)
	int sig, (*act)();
{
	int omask = sigblock(sigmask(sig));

	if (signal(sig, act) == SIG_IGN)
		(void) signal(sig, SIG_IGN);
	(void) sigsetmask(omask);
}

E 34
D 29
done()
E 29
I 29
done(status)
	int status;
E 29
{
I 34
	int w;
E 34

	mode(0);
D 5
	wait((int *)NULL);
E 5
I 5
D 34
	if (child > 0 && kill(child, SIGKILL) >= 0)
		wait((int *)0);
E 34
I 34
	if (child > 0) {
		/* make sure catchild does not snap it up */
		(void) signal(SIGCHLD, SIG_DFL);
		if (kill(child, SIGKILL) >= 0)
			while ((w = wait((union wait *)0)) > 0 && w != child)
				/*void*/;
	}
E 34
E 5
D 29
	exit(0);
E 29
I 29
	exit(status);
E 29
}

I 24
/*
I 34
 * Copy SIGURGs to the child process.
 */
copytochild()
{

	(void) kill(child, SIGURG);
}

/*
E 34
 * This is called when the reader process gets the out-of-band (urgent)
 * request to turn on the window-changing protocol.
 */
writeroob()
{

I 27
D 28
	if (dosigwinch == 0)
E 28
I 28
	if (dosigwinch == 0) {
E 28
		sendwindow();
I 28
D 34
		signal(SIGWINCH, sigwinch);
E 34
I 34
		(void) signal(SIGWINCH, sigwinch);
E 34
	}
E 28
E 27
	dosigwinch = 1;
D 27
	sendwindow();
E 27
}

E 24
I 11
catchild()
{
	union wait status;
	int pid;

again:
D 34
	pid = wait3(&status, WNOHANG|WUNTRACED, 0);
E 34
I 34
	pid = wait3(&status, WNOHANG|WUNTRACED, (struct rusage *)0);
E 34
	if (pid == 0)
		return;
	/*
	 * if the child (reader) dies, just quit
	 */
	if (pid < 0 || pid == child && !WIFSTOPPED(status))
D 29
		done();
E 29
I 29
D 34
		done(status.w_termsig | status.w_retcode);
E 34
I 34
		done((int)(status.w_termsig | status.w_retcode));
E 34
E 29
	goto again;
}

E 11
/*
D 5
 *	wr: write to remote: 0 -> line.
 *	~.	terminate
 *	~<file	send file
 *	~!	local login-style shell
 *	~!cmd	execute cmd locally
 *	~$proc	execute proc locally, send output to line
 *	~%cmd	execute builtin cmd (put and take)
 *	~^Z	suspend cu process.
E 5
I 5
 * writer: write to remote: 0 -> line.
 * ~.	terminate
 * ~^Z	suspend rlogin process.
I 8
 * ~^Y  suspend rlogin process, but leave reader alone.
E 8
E 5
 */
D 5

wr()
E 5
I 5
writer()
E 5
{
D 5
	int ds,fk,lcl,x;
	char *p,b[600];
	for (;;) {
		p=b;
		while (rdc(0) == 1) {
			if (p == b) lcl=(c == cmdchar);
			if (p == b+1 && b[0] == cmdchar) lcl=(c!=cmdchar);
			if (!lcl) {
				c = oc;
				if (wrc(rem) == 0) {
					prf("line gone"); return;
				}
				if (eight == 0)
					c &= 0177;
			}
			if (lcl) {
				if (c == 0177) c=tkill;
				if (c == '\r' || c == '\n') goto A;
				wrc(0);
			}
			*p++=c;
			if (c == terase) {
				p=p-2; 
				if (p<b) p=b;
			}
			if (c == tkill || c == 0177 || c == '\4' || c == '\r' || c == '\n') p=b;
		}
		return;
A: 
		echo("");
		*p=0;
		switch (b[1]) {
		case '.':
		case '\004':
			return;
		case '!':
		case '$':
			fk = fork();
			signal(SIGCHLD, SIG_DFL);
			if (fk == 0) {
				char *shell = getenv("SHELL");
				if (shell == 0) shell = "/bin/sh";
				close(1);
				dup(b[1] == '$'? rem:2);
				close(rem);
				mode(0);
				if (!nhup) signal(SIGINT, SIG_DFL);
				if (b[2] == 0) execl(shell,shell,0);
				/* if (b[2] == 0) execl(shell,"-",0); */
				else execl(shell,"sh","-c",b+2,0);
				prf("Can't execute shell");
				exit(~0);
			}
			if (fk!=(-1)) {
				while (wait(&x)!=fk);
			}
			signal(SIGCHLD, done);
			mode(1);
			if (b[1] == '!') echo("!");
			break;
		case '<':
			if (b[2] == 0) break;
			if ((ds=open(b+2,0))<0) {
				prf("Can't divert %s",b+1); 
				break;
			}
			intr=x=0;
			mode(2);
			if (!nhup) signal(SIGINT, sig2);
			while (!intr && rdc(ds) == 1) {
				if (wrc(rem) == 0) {
					x=1; 
					break;
				}
			}
			signal(SIGINT, SIG_IGN);
			close(ds);
			mode(1);
			if (x) return;
			break;
		case '>':
		case ':':
			{
			register char *q;
E 5
I 5
D 17
	char b[600], c;
	register char *p;
E 17
I 17
D 21
	char obuf[600], c;
	register char *op;
E 21
I 21
	char c;
E 21
E 17
I 11
	register n;
I 21
	register bol = 1;               /* beginning of line */
	register local = 0;
E 21
E 11
E 5

I 17
D 24
	/*
	 * Handle SIGWINCH's with in-band signaling of new
	 * window size.  It seems reasonable that we flush
	 * pending input and not force out of band signal
	 * as this most likely will occur from an input device
	 * other than the keyboard (e.g. a mouse).
	 *
	 * The hack of using 0377 to signal an in-band signal
	 * is pretty bad, but otherwise we'd be forced to
	 * either get complicated (use MSG_OOB) or go to a
	 * serious (telnet-style) protocol.
	 */
	if (setjmp(winsizechanged)) {
I 21
		char obuf[4 + sizeof (struct winsize)];
E 21
		struct winsize *wp = (struct winsize *)(obuf+4);

		obuf[0] = 0377;			/* XXX */
		obuf[1] = 0377;			/* XXX */
		obuf[2] = 's';			/* XXX */
		obuf[3] = 's';			/* XXX */
		wp->ws_row = htons(winsize.ws_row);
		wp->ws_col = htons(winsize.ws_col);
		wp->ws_xpixel = htons(winsize.ws_xpixel);
		wp->ws_ypixel = htons(winsize.ws_ypixel);
		(void) write(rem, obuf, 4+sizeof (*wp));
	}
E 17
D 5
			q = b+1;
			if(*q=='>') q++;
			write(pipes[1],q,strlen(q)+1);
			if (efk != -1) kill(efk,SIGEMT);
E 5
I 5
D 21
top:
D 17
	p = b;
E 17
I 17
	op = obuf;
E 17
D 11
	while (read(0, &c, 1) > 0) {
E 11
I 11
	for (;;) {
E 11
		int local;
E 21

E 24
I 21
	for (;;) {
E 21
I 11
		n = read(0, &c, 1);
D 17
		if (n == 0)
			break;
		if (n < 0)
			if (errno == EINTR)
E 17
I 17
		if (n <= 0) {
			if (n < 0 && errno == EINTR)
E 17
				continue;
D 17
			else
				break;

E 11
		if (eight == 0)
E 17
I 17
			break;
		}
D 24
		if (!eight)
E 17
			c &= 0177;
E 24
		/*
		 * If we're at the beginning of the line
		 * and recognize a command character, then
		 * we echo locally.  Otherwise, characters
		 * are echo'd remotely.  If the command
		 * character is doubled, this acts as a 
		 * force and local echo is suppressed.
		 */
D 17
		if (p == b)
E 17
I 17
D 21
		if (op == obuf)
E 17
			local = (c == cmdchar);
D 17
		if (p == b + 1 && *b == cmdchar)
E 17
I 17
		if (op == obuf + 1 && *obuf == cmdchar)
E 17
			local = (c != cmdchar);
		if (!local) {
			if (write(rem, &c, 1) == 0) {
				prf("line gone");
				return;
E 21
I 21
		if (bol) {
			bol = 0;
D 36
			if (c == cmdchar) {
E 36
I 36
			if (c == cmdchar && c && !notty) {
E 36
				bol = 0;
				local = 1;
				continue;
E 21
E 5
			}
D 5
			break;
#ifdef SIGTSTP
#define CTRLZ	26
		case CTRLZ:
			mode(0);
			signal(SIGCHLD, SIG_IGN);
			kill(0, SIGTSTP);
			signal(SIGCHLD, done);
			mode(1);
			break;
#endif
		case '%':
			dopercen(&b[2]);
			break;
		default:
			prf("Use `%c%c' to start line with `%c'", cmdchar, cmdchar, cmdchar);
		}
		continue;
	}
}
E 5
I 5
D 17
			if (eight == 0)
E 17
I 17
D 21
			if (!eight)
E 17
				c &= 0177;
		} else {
D 12
			if (c == 0177)
D 7
				c = tkill;
E 7
I 7
				c = deftc.tc_kill;
E 12
E 7
			if (c == '\r' || c == '\n') {
D 7
				switch (b[1]) {
E 7
I 7
D 17
				char cmdc = b[1];
E 17
I 17
				char cmdc = obuf[1];
E 17
E 7
E 5

D 5
dopercen(line)
register char *line;
{
	char *args[10];
	register narg, f;
	int rcount;
	for (narg = 0; narg < 10;) {
		while(*line == ' ' || *line == '\t')
			line++;
		if (*line == '\0')
			break;
		args[narg++] = line;
		while(*line != '\0' && *line != ' ' && *line != '\t')
			line++;
		if (*line == '\0')
			break;
		*line++ = '\0';
	}
	if (equal(args[0], "take")) {
		if (narg < 2) {
			prf("usage: %c%%take from [to]", cmdchar);
			return;
		}
		if (narg < 3)
			args[2] = args[1];
		write(pipes[1], ">/dev/null",sizeof(">/dev/null"));
		if (efk != -1) kill(efk,SIGEMT);
		sleep(5);
		wrln("echo '%c>:", cmdchar);
		wrln(args[2]);
		wrln("'; tee /dev/null <");
		wrln(args[1]);
		wrln(";echo '%c>'\n", cmdchar);
		return;
	} else if (equal(args[0], "put")) {
		prf("%c%%put doesn't work yet (use rsh)", cmdchar);
		return;
/*
		if (narg < 2) {
			prf("usage: %c%%put from [to]", cmdchar);
			return;
		}
		if (narg < 3)
			args[2] = args[1];
		if ((f = open(args[1], 0)) < 0) {
			prf("cannot open: %s", args[1]);
			return;
		}
		wrln("stty -echo;cat >");
		wrln(args[2]);
		wrln(";stty echo\n");
		sleep(5);
		intr = 0;
		if (!nhup)
			signal(SIGINT, sig2);
		mode(2);
		rcount = 0;
		while(!intr && rdc(f) == 1) {
			rcount++;
			if (c == tkill || c == terase)
				wrln("\\");
			if (wrc(rem) != 1) {
				sleep(2);
				if (wrc(rem) != 1) {
					prf("character missed");
					intr = 1;
					break;
E 5
I 5
D 7
				case '.':
				case CTRL(d):
E 7
I 7
D 14
				if (cmdc == '.' || cmdc == deftc.tc_eofc) {
E 14
I 14
				if (cmdc == '.' || cmdc == deftc.t_eofc) {
E 14
E 7
					write(0, CRLF, sizeof(CRLF));
					return;
D 7

				case CTRL(z):
E 7
I 7
				}
D 14
				if (cmdc == deftc.tc_suspc ||
				    cmdc == deftc.tc_dsuspc) {
E 14
I 14
				if (cmdc == defltc.t_suspc ||
				    cmdc == defltc.t_dsuspc) {
E 14
E 7
D 17
					write(0, CRLF, sizeof(CRLF));
					mode(0);
D 11
					signal(SIGCHLD, SIG_IGN);
E 11
I 11
D 13
					sigignore(SIGCHLD);
E 13
I 13
					signal(SIGCHLD, SIG_IGN);
E 13
E 11
D 7
					kill(0, SIGTSTP);
E 7
I 7
D 14
					kill(cmdc == deftc.tc_suspc ?
E 14
I 14
					kill(cmdc == defltc.t_suspc ?
E 14
					  0 : getpid(), SIGTSTP);
E 7
D 11
					signal(SIGCHLD, done);
E 11
I 11
D 13
					sigrelse(SIGCHLD);
E 13
I 13
					signal(SIGCHLD, catchild);
E 13
E 11
					mode(1);
E 17
I 17
					stop(cmdc);
E 17
					goto top;
E 5
				}
I 5
D 17
				*p++ = c;
				write(rem, b, p - b);
E 17
I 17
				*op++ = c;
				write(rem, obuf, op - obuf);
E 17
				goto top;
E 21
I 21
		} else if (local) {
			local = 0;
			if (c == '.' || c == deftc.t_eofc) {
				echo(c);
				break;
E 21
E 5
			}
I 5
D 21
			write(1, &c, 1);
E 21
I 21
			if (c == defltc.t_suspc || c == defltc.t_dsuspc) {
				bol = 1;
				echo(c);
				stop(c);
				continue;
			}
			if (c != cmdchar)
D 34
				write(rem, &cmdchar, 1);
E 34
I 34
				(void) write(rem, &cmdchar, 1);
E 34
E 21
E 5
		}
D 5
		signal(SIGINT, SIG_IGN);
		close(f);
		if (intr) {
			wrln("\n");
			prf("stopped after %d bytes", rcount);
E 5
I 5
D 17
		*p++ = c;
E 17
I 17
D 21
		*op++ = c;
E 17
D 7
		if (c == terase) {
E 7
I 7
D 14
		if (c == deftc.tc_erase) {
E 14
I 14
		if (c == deferase) {
E 14
E 7
D 17
			p -= 2; 
			if (p < b)
E 17
I 17
			op -= 2; 
			if (op < obuf)
E 17
				goto top;
E 21
I 21
		if (write(rem, &c, 1) == 0) {
			prf("line gone");
			break;
E 21
E 5
		}
D 5
		wrln("\004");
		sleep(5);
		mode(1);
		return;
*/
E 5
I 5
D 7
		if (c == tkill || c == 0177 || c == CTRL(d) ||
E 7
I 7
D 12
		if (c == deftc.tc_kill || c == 0177 || c == deftc.tc_eofc ||
E 12
I 12
D 14
		if (c == deftc.tc_kill || c == deftc.tc_eofc ||
E 14
I 14
D 21
		if (c == defkill || c == deftc.t_eofc ||
E 14
E 12
E 7
		    c == '\r' || c == '\n')
			goto top;
I 11
D 17
		if (p >= &b[sizeof b])
			p--;
E 17
I 17
		if (op >= &obuf[sizeof (obuf)])
			op--;
E 21
I 21
		bol = c == defkill || c == deftc.t_eofc ||
I 29
		    c == deftc.t_intrc || c == defltc.t_suspc ||
E 29
		    c == '\r' || c == '\n';
E 21
	}
}

I 21
echo(c)
register char c;
{
	char buf[8];
	register char *p = buf;

	c &= 0177;
	*p++ = cmdchar;
	if (c < ' ') {
		*p++ = '^';
		*p++ = c + '@';
	} else if (c == 0177) {
		*p++ = '^';
		*p++ = '?';
	} else
		*p++ = c;
	*p++ = '\r';
	*p++ = '\n';
D 34
	write(1, buf, p - buf);
E 34
I 34
	(void) write(1, buf, p - buf);
E 34
}

E 21
stop(cmdc)
	char cmdc;
{
D 24
	struct winsize ws;

E 24
D 21
	write(0, CRLF, sizeof(CRLF));
E 21
	mode(0);
D 34
	signal(SIGCHLD, SIG_IGN);
	kill(cmdc == defltc.t_suspc ? 0 : getpid(), SIGTSTP);
	signal(SIGCHLD, catchild);
E 34
I 34
	(void) signal(SIGCHLD, SIG_IGN);
	(void) kill(cmdc == defltc.t_suspc ? 0 : getpid(), SIGTSTP);
	(void) signal(SIGCHLD, catchild);
E 34
	mode(1);
	sigwinch();			/* check for size changes */
}

I 32
D 34
#ifdef sun
E 34
E 32
sigwinch()
{
I 32
D 34
	struct ttysize ws;

	if (dosigwinch && ioctl(0, TIOCGSIZE, &ws) == 0 &&
	    bcmp(&ws, &winsize, sizeof (ws))) {
		winsize = ws;
		sendwindow();
	}
}

#else sun
sigwinch()
{
E 34
E 32
	struct winsize ws;

D 24
	if (!nosigwin && ioctl(0, TIOCGWINSZ, &ws) == 0 &&
E 24
I 24
D 28
	if (dosigwinch && !nosigwin && ioctl(0, TIOCGWINSZ, &ws) == 0 &&
E 28
I 28
D 34
	if (dosigwinch && ioctl(0, TIOCGWINSZ, &ws) == 0 &&
E 34
I 34
	if (dosigwinch && get_window_size(0, &ws) == 0 &&
E 34
E 28
E 24
	    bcmp(&ws, &winsize, sizeof (ws))) {
		winsize = ws;
D 24
		longjmp(winsizechanged, 1);
E 24
I 24
		sendwindow();
E 24
E 17
E 11
E 5
	}
D 5
	prf("%c%%%s unknown\n", cmdchar, args[0]);
E 5
}
I 32
D 34
#endif
E 34
E 32

I 24
/*
 * Send the window size to the server via the magic escape
 */
sendwindow()
{
	char obuf[4 + sizeof (struct winsize)];
	struct winsize *wp = (struct winsize *)(obuf+4);

	obuf[0] = 0377;
	obuf[1] = 0377;
	obuf[2] = 's';
	obuf[3] = 's';
I 32
D 34
#ifdef sun
	wp->ws_row = htons(winsize.ts_lines);
	wp->ws_col = htons(winsize.ts_cols);
	wp->ws_xpixel = 0;
	wp->ws_ypixel = 0;
#else sun
E 34
E 32
	wp->ws_row = htons(winsize.ws_row);
	wp->ws_col = htons(winsize.ws_col);
	wp->ws_xpixel = htons(winsize.ws_xpixel);
	wp->ws_ypixel = htons(winsize.ws_ypixel);
I 32
D 34
#endif sun
E 34
E 32
	(void) write(rem, obuf, sizeof(obuf));
}

I 29
/*
 * reader: read from remote: line -> 1
 */
#define	READING	1
#define	WRITING	2

char	rcvbuf[8 * 1024];
int	rcvcnt;
int	rcvstate;
I 32
int	ppid;
E 32
jmp_buf	rcvtop;

E 29
E 24
D 5
equal(s1, s2)
register char *s1, *s2;
{
	while (*s1++ == *s2)
		if (*s2++ == '\0')
			return(1);
	return(0);
}

wrln(s, p1, p2, p3)
register char *s;
int p1, p2, p3;
{
	char wbuf[256];

	sprintf(wbuf, s, p1, p2, p3);
	s = wbuf;
	while (*s)
		write(rem, s++, 1);
}
int ds,slnt;
int justrung;

/*
 *	rd: read from remote: line -> 1
 *	catch:
 *	~>[>][:][file]
 *	stuff from file...
 *	~>	(ends diversion)
 */

int ds,slnt,taking;
int justrung;
readmsg(){
	static char dobuff[128], morejunk[256];
	int n;
	justrung = 1;
	signal(SIGEMT,readmsg);
	n = read(pipes[0],morejunk,256);
	dodiver(morejunk);
}

dodiver(msg)
char *msg;
{
	register char *cp = msg; 

	if (*cp=='>') cp++;
	if (*cp==':') {
		cp++;
		if(*cp==0) {
			slnt ^= 1;
			return;
		} else  {
			slnt = 1;
		}
	}
	if (ds >= 0) close(ds);
	if (*cp==0) {
		slnt = 0;
		ds = -1;
		return;
	}
	if (*msg!='>' || (ds=open(cp,1))<0) ds=creat(cp,0644);
	lseek(ds, (long)0, 2);
	if(ds < 0) prf("Creat failed:"), prf(cp);
	if (ds<0) prf("Can't divert %s",cp+1);
}


/*
 *	rd: read from remote: line -> 1
 *	catch: diversion caught by interrupt routine
 */

#define ORDIN 0
#define SAWCR 1
#define EOL   2
#define SAWTL 3
#define DIVER 4

E 5
oob()
{
D 5
	int mark, cc, out = 1+1;
	char waste[512];
E 5
I 5
D 9
	int out = 1+1;
E 9
I 9
D 29
	int out = 1+1, atmark;
E 29
I 29
	int out = FWRITE, atmark, n;
	int rcvd = 0;
E 29
E 9
	char waste[BUFSIZ], mark;
I 24
	struct sgttyb sb;
I 27
D 29
	static int didnotify = 0;
E 29
E 27
E 24
E 5

D 11
	signal(SIGURG, oob);
E 11
D 5
	ioctl(1, TIOCFLUSH, &out);
E 5
I 5
D 29
	ioctl(1, TIOCFLUSH, (char *)&out);
E 5
	for (;;) {
I 24
		int rv;
E 24
D 9
		if (ioctl(rem, SIOCATMARK, &mark) < 0) {
E 9
I 9
		if (ioctl(rem, SIOCATMARK, &atmark) < 0) {
E 9
			perror("ioctl");
			break;
		}
D 9
		if (mark)
E 9
I 9
		if (atmark)
E 9
			break;
D 5
		cc = read(rem, waste, 512);
E 5
I 5
D 20
		(void) read(rem, waste, sizeof (waste));
E 20
I 20
D 24
		if (read(rem, waste, sizeof (waste)) <= 0)
E 24
I 24
		rv = read(rem, waste, sizeof (waste));
		if (rv <= 0)
E 24
			break;
E 29
I 29
	while (recv(rem, &mark, 1, MSG_OOB) < 0)
		switch (errno) {
		
		case EWOULDBLOCK:
			/*
			 * Urgent data not here yet.
			 * It may not be possible to send it yet
			 * if we are blocked for output
			 * and our input buffer is full.
			 */
			if (rcvcnt < sizeof(rcvbuf)) {
				n = read(rem, rcvbuf + rcvcnt,
					sizeof(rcvbuf) - rcvcnt);
				if (n <= 0)
					return;
				rcvd += n;
			} else {
				n = read(rem, waste, sizeof(waste));
				if (n <= 0)
					return;
			}
			continue;
				
		default:
			return;
E 29
E 20
E 5
	}
D 3
	ioctl(rem, SIOCRCVOOB, &mark);
E 3
I 3
D 13
	recv(rem, &mark, 1, SOF_OOB);
E 13
I 13
D 29
	recv(rem, &mark, 1, MSG_OOB);
I 24
D 27
	if (mark & TIOCPKT_WINDOW) {
E 27
I 27
	if (didnotify == 0 && (mark & TIOCPKT_WINDOW)) {
E 29
I 29
	if (mark & TIOCPKT_WINDOW) {
E 29
E 27
		/*
		 * Let server know about window size changes
		 */
D 32
		kill(getppid(), SIGURG);
E 32
I 32
D 34
		kill(ppid, SIGURG);
E 34
I 34
D 36
		(void) kill(ppid, SIGUSR1);
E 36
I 36
		if (!notty)
			(void) kill(ppid, SIGUSR1);
E 36
E 34
E 32
I 27
D 29
		didnotify = 1;
E 29
E 27
	}
D 29
	if (eight)
		return;
E 24
E 13
E 3
	if (mark & TIOCPKT_NOSTOP) {
E 29
I 29
	if (!eight && (mark & TIOCPKT_NOSTOP)) {
E 29
I 24
D 34
		ioctl(0, TIOCGETP, (char *)&sb);
E 34
I 34
		(void) ioctl(0, TIOCGETP, (char *)&sb);
E 34
		sb.sg_flags &= ~CBREAK;
		sb.sg_flags |= RAW;
D 34
		ioctl(0, TIOCSETN, (char *)&sb);
E 34
I 34
		(void) ioctl(0, TIOCSETN, (char *)&sb);
E 34
E 24
D 5
		notchars.t_stopc = 0377;
		notchars.t_startc = 0377;
		ioctl(0, TIOCSETC, &notchars);
E 5
I 5
D 7
		notchars.t_stopc = -1;
		notchars.t_startc = -1;
		ioctl(0, TIOCSETC, (char *)&notchars);
E 7
I 7
D 14
		notc.tc_stopc = -1;
		notc.tc_startc = -1;
		ioctl(0, TIOCCSET, (char *)&notc);
E 14
I 14
		notc.t_stopc = -1;
		notc.t_startc = -1;
D 34
		ioctl(0, TIOCSETC, (char *)&notc);
E 34
I 34
		(void) ioctl(0, TIOCSETC, (char *)&notc);
E 34
E 14
E 7
E 5
	}
D 29
	if (mark & TIOCPKT_DOSTOP) {
E 29
I 29
	if (!eight && (mark & TIOCPKT_DOSTOP)) {
E 29
I 24
D 34
		ioctl(0, TIOCGETP, (char *)&sb);
E 34
I 34
		(void) ioctl(0, TIOCGETP, (char *)&sb);
E 34
		sb.sg_flags &= ~RAW;
		sb.sg_flags |= CBREAK;
D 34
		ioctl(0, TIOCSETN, (char *)&sb);
E 34
I 34
		(void) ioctl(0, TIOCSETN, (char *)&sb);
E 34
E 24
D 5
		notchars.t_stopc = 's'&037;
		notchars.t_startc = 'q'&037;
		ioctl(0, TIOCSETC, &notchars);
E 5
I 5
D 7
		notchars.t_stopc = CTRL(s);
		notchars.t_startc = CTRL(q);
		ioctl(0, TIOCSETC, (char *)&notchars);
E 7
I 7
D 14
		notc.tc_stopc = deftc.tc_stopc;
		notc.tc_startc = deftc.tc_startc;
		ioctl(0, TIOCCSET, (char *)&notc);
E 14
I 14
		notc.t_stopc = deftc.t_stopc;
		notc.t_startc = deftc.t_startc;
D 34
		ioctl(0, TIOCSETC, (char *)&notc);
E 34
I 34
		(void) ioctl(0, TIOCSETC, (char *)&notc);
E 34
E 14
E 7
E 5
	}
I 29
	if (mark & TIOCPKT_FLUSHWRITE) {
D 34
		ioctl(1, TIOCFLUSH, (char *)&out);
E 34
I 34
		(void) ioctl(1, TIOCFLUSH, (char *)&out);
E 34
		for (;;) {
			if (ioctl(rem, SIOCATMARK, &atmark) < 0) {
				perror("ioctl");
				break;
			}
			if (atmark)
				break;
			n = read(rem, waste, sizeof (waste));
			if (n <= 0)
				break;
		}
		/*
		 * Don't want any pending data to be output,
		 * so clear the recv buffer.
		 * If we were hanging on a write when interrupted,
		 * don't want it to restart.  If we were reading,
		 * restart anyway.
		 */
		rcvcnt = 0;
		longjmp(rcvtop, 1);
	}
I 34

E 34
	/*
I 34
	 * oob does not do FLUSHREAD (alas!)
	 */

	/*
E 34
	 * If we filled the receive buffer while a read was pending,
	 * longjmp to the top to restart appropriately.  Don't abort
	 * a pending write, however, or we won't know how much was written.
	 */
	if (rcvd && rcvstate == READING)
		longjmp(rcvtop, 1);
E 29
}

D 5
rd()
E 5
I 5
/*
 * reader: read from remote: line -> 1
 */
D 34
reader()
E 34
I 34
reader(oldmask)
	int oldmask;
E 34
E 5
{
I 32
#if !defined(BSD) || BSD < 43
	int pid = -getpid();
#else
E 32
D 5
	extern int ds,slnt;
	char rb[600], lb[600], *rlim, *llim, c;
	register char *p,*q;
	int cnt, state = 0, mustecho, oldslnt, readmsg();
E 5
I 5
D 29
	char rb[BUFSIZ];
	register int cnt;
E 29
I 29
	int pid = getpid();
I 32
#endif
E 32
	int n, remaining;
	char *bufp = rcvbuf;
E 29
E 5

D 5
	signal(SIGEMT,readmsg);  /* set up child for catching diversion msgs
				    from parent */
	signal(SIGURG,oob);
E 5
I 5
D 11
	signal(SIGURG, oob);
E 11
I 11
D 13
	sigset(SIGURG, oob);
E 13
I 13
D 24
	signal(SIGURG, oob);
E 24
I 21
D 34
	signal(SIGTTOU, SIG_IGN);
E 21
E 13
E 11
D 6
#ifdef notdef
E 6
E 5
D 22
	{ int pid = -getpid();
D 5
	  ioctl(rem, SIOCSPGRP, &pid); }
	ds=(-1);
	p = lb; llim = lb+600;
agin:
E 5
I 5
	  ioctl(rem, SIOCSPGRP, (char *)&pid); }
E 22
I 22
D 29
	{ int pid = getpid();
	  fcntl(rem, F_SETOWN, pid); }
E 29
I 29
	fcntl(rem, F_SETOWN, pid);
E 34
I 34
	(void) signal(SIGTTOU, SIG_IGN);
	(void) signal(SIGURG, oob);
E 34
I 32
	ppid = getppid();
I 34
	(void) fcntl(rem, F_SETOWN, pid);
E 34
E 32
	(void) setjmp(rcvtop);
I 34
	(void) sigsetmask(oldmask);
E 34
E 29
E 22
D 6
#endif
E 6
E 5
	for (;;) {
D 5
		extern errno;
		errno = 0;
		cnt = read(rem,rb,600);
E 5
I 5
D 29
		cnt = read(rem, rb, sizeof (rb));
E 5
D 10
		if (cnt <= 0) {
E 10
I 10
		if (cnt == 0)
			break;
		if (cnt < 0) {
E 29
I 29
		while ((remaining = rcvcnt - (bufp - rcvbuf)) > 0) {
			rcvstate = WRITING;
			n = write(1, bufp, remaining);
			if (n < 0) {
				if (errno != EINTR)
D 30
					return;
E 30
I 30
					return (-1);
E 30
				continue;
			}
			bufp += n;
		}
		bufp = rcvbuf;
		rcvcnt = 0;
		rcvstate = READING;
		rcvcnt = read(rem, rcvbuf, sizeof (rcvbuf));
		if (rcvcnt == 0)
			return (0);
		if (rcvcnt < 0) {
E 29
E 10
D 5
			if (errno == EINTR) {
				errno = 0;
E 5
I 5
			if (errno == EINTR)
E 5
				continue;
I 32
			perror("read");
E 32
D 5
			}
E 5
D 29
			break;
E 29
I 29
			return (-1);
E 29
		}
D 5
		if(!slnt) write(1,rb,cnt);
		if(ds < 0) continue;
		oldslnt = slnt;
		for( q=rb, rlim = rb + cnt - 1; q <= rlim; ) {
			if (eight == 0)
			c &= 0177;
			if(p < llim) *p++ = c;
			switch(state) {
			case ORDIN:
				if(c=='\r') state = SAWCR;
				break;
			case SAWCR:
				if(c=='\n') {
					state = EOL;
					p--;
					p[-1] = '\n';
				} else state = ORDIN;
				break;
			case EOL:
				state = (c==cmdchar ? SAWTL : 
					 (c=='\r' ? SAWCR : ORDIN));
				break;
			case SAWTL:
				state = (c=='>' ? DIVER : 
					 (c=='\r' ? SAWCR : ORDIN));
				break;
			case DIVER:
				if(c=='\r') {
					p--;
				} else if (c=='\n') {
					state = ORDIN;
					p[-1] = 0;
					dodiver(lb+2);
					c = 0; p = lb;
				}
			}
			if(slnt==0 && oldslnt) {
				if(c=='\n') {
					write(rem,lb,p-lb-1);
					write(rem,CRLF,sizeof(CRLF));
				} else if(q==rlim) {
					write(rem,lb,p-lb);
					c = '\n';  /*force flush to file*/
				}
			}
			if(c=='\n') {
				if(ds >= 0)
					write(ds,lb,p-lb);
				p = lb;
			}
		}
E 5
I 5
D 29
		write(1, rb, cnt);
E 29
E 5
	}
D 5
	if(justrung) {
		justrung = 0;
		goto agin;
	}
E 5
}

D 5
struct {char lobyte; char hibyte;};
E 5
mode(f)
{
D 7
	struct sgttyb stbuf;
E 7
I 7
D 14
	struct ttychars *tc;
	int flags;
E 14
I 14
	struct tchars *tc;
	struct ltchars *ltc;
	struct sgttyb sb;
I 18
	int	lflags;
E 18
E 14
E 7
D 5
	ioctl(0, TIOCGETP, &stbuf);
E 5
I 5

I 36
	if (notty)
		return;
E 36
D 7
	ioctl(0, TIOCGETP, (char *)&stbuf);
E 5
	if (f == 0) {
		stbuf.sg_flags &= ~CBREAK;
D 2
		stbuf.sg_flags |= ECHO|CRMOD;
E 2
I 2
		stbuf.sg_flags |= defflags;
E 2
D 5
		ioctl(0, TIOCSETC, &deftchars);
		ioctl(0, TIOCSLTC, &defltchars);
E 5
I 5
		ioctl(0, TIOCSETC, (char *)&deftchars);
		ioctl(0, TIOCSLTC, (char *)&defltchars);
E 5
		stbuf.sg_kill = defkill;
		stbuf.sg_erase = deferase;
E 7
I 7
D 14
	ioctl(0, TIOCGET, (char *)&flags);
E 14
I 14
D 34
	ioctl(0, TIOCGETP, (char *)&sb);
I 18
	ioctl(0, TIOCLGET, (char *)&lflags);
E 34
I 34
	(void) ioctl(0, TIOCGETP, (char *)&sb);
	(void) ioctl(0, TIOCLGET, (char *)&lflags);
E 34
E 18
E 14
	switch (f) {

	case 0:
D 12
		flags &= ~CBREAK;
		flags |= defflags;
E 12
I 12
D 14
		flags &= ~(CBREAK|RAW|TBDELAY);
		flags |= defflags|tabflag;
E 14
I 14
		sb.sg_flags &= ~(CBREAK|RAW|TBDELAY);
		sb.sg_flags |= defflags|tabflag;
E 14
E 12
		tc = &deftc;
I 14
		ltc = &defltc;
		sb.sg_kill = defkill;
		sb.sg_erase = deferase;
I 18
		lflags = deflflags;
E 18
E 14
		break;

	case 1:
D 12
		flags |= CBREAK;
E 12
I 12
D 14
		flags |= (eight ? RAW : CBREAK);
E 12
		flags &= ~defflags;
E 14
I 14
		sb.sg_flags |= (eight ? RAW : CBREAK);
		sb.sg_flags &= ~defflags;
E 14
I 12
		/* preserve tab delays, but turn off XTABS */
D 14
		if ((flags & TBDELAY) == XTABS)
			flags &= ~TBDELAY;
E 14
I 14
		if ((sb.sg_flags & TBDELAY) == XTABS)
			sb.sg_flags &= ~TBDELAY;
E 14
E 12
		tc = &notc;
I 14
		ltc = &noltc;
		sb.sg_kill = sb.sg_erase = -1;
I 18
		if (litout)
			lflags |= LLITOUT;
E 18
E 14
		break;

	default:
		return;
E 7
	}
D 7
	if (f == 1) {
		stbuf.sg_flags |= CBREAK;
		stbuf.sg_flags &= ~(ECHO|CRMOD);
D 5
		ioctl(0, TIOCSETC, &notchars);
		ioctl(0, TIOCSLTC, &noltchars);
		stbuf.sg_kill = 0377;
		stbuf.sg_erase = 0377;
E 5
I 5
		ioctl(0, TIOCSETC, (char *)&notchars);
		ioctl(0, TIOCSLTC, (char *)&noltchars);
		stbuf.sg_kill = -1;
		stbuf.sg_erase = -1;
E 5
	}
	if (f == 2) {
		stbuf.sg_flags &= ~CBREAK;
		stbuf.sg_flags &= ~(ECHO|CRMOD);
D 5
		ioctl(0, TIOCSETC, &deftchars);
		ioctl(0, TIOCSLTC, &defltchars);
		stbuf.sg_kill = 0377;
		stbuf.sg_erase = 0377;
E 5
I 5
		ioctl(0, TIOCSETC, (char *)&deftchars);
		ioctl(0, TIOCSLTC, (char *)&defltchars);
		stbuf.sg_kill = -1;
		stbuf.sg_erase = -1;
E 5
	}
D 5
	ioctl(0, TIOCSETN, &stbuf);
E 5
I 5
	ioctl(0, TIOCSETN, (char *)&stbuf);
E 7
I 7
D 14
	ioctl(0, TIOCSET, (char *)&flags);
	ioctl(0, TIOCCSET, (char *)tc);
E 14
I 14
D 34
	ioctl(0, TIOCSLTC, (char *)ltc);
	ioctl(0, TIOCSETC, (char *)tc);
	ioctl(0, TIOCSETN, (char *)&sb);
I 18
	ioctl(0, TIOCLSET, (char *)&lflags);
E 34
I 34
	(void) ioctl(0, TIOCSLTC, (char *)ltc);
	(void) ioctl(0, TIOCSETC, (char *)tc);
	(void) ioctl(0, TIOCSETN, (char *)&sb);
	(void) ioctl(0, TIOCLSET, (char *)&lflags);
E 34
E 18
E 14
E 7
E 5
}

D 5
echo(s)
char *s;
{
	char *p;
	for (p=s;*p;p++);
	if (p>s) write(0,s,p-s);
	write(0,CRLF, sizeof(CRLF));
}

E 5
I 5
/*VARARGS*/
E 5
D 24
prf(f, a1, a2, a3)
E 24
I 24
prf(f, a1, a2, a3, a4, a5)
E 24
D 5
char *f;
E 5
I 5
	char *f;
E 5
{
I 34

E 34
D 24
	fprintf(stderr, f, a1, a2, a3);
E 24
I 24
	fprintf(stderr, f, a1, a2, a3, a4, a5);
E 24
	fprintf(stderr, CRLF);
}

D 5
exists(devname)
char *devname;
E 5
I 5
lostpeer()
E 5
{
D 5
	if (access(devname, 0)==0)
		return(1);
	prf("%s does not exist", devname);
	return(0);
}

rdc(ds)
{

	ds=read(ds,&c,1); 
	oc = c;
	if (eight == 0)
		c &= 0177;
	return (ds);
}

sig2()
{
	signal(SIGINT, SIG_IGN); 
	intr = 1;
E 5
I 5
D 11
	signal(SIGPIPE, SIG_IGN);
E 11
I 11
D 13
	sigignore(SIGPIPE);
E 13
I 13
D 34
	signal(SIGPIPE, SIG_IGN);
E 34
I 34

	(void) signal(SIGPIPE, SIG_IGN);
E 34
E 13
E 11
D 12
	prf("\007Lost connection");
E 12
I 12
	prf("\007Connection closed.");
E 12
D 29
	done();
E 29
I 29
	done(1);
E 29
E 5
}
I 32

E 32
E 1
