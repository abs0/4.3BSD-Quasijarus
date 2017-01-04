h30932
s 00001/00001/00248
d D 5.6 87/10/22 18:12:05 bostic 19 18
c ANSI C; sprintf now returns an int.
e
s 00012/00009/00237
d D 5.5 87/06/02 12:44:55 karels 18 17
c don't bother forking to read /dev/null
e
s 00006/00003/00240
d D 5.4 85/08/28 11:48:44 bloom 17 16
c fix signal handling for /bin/sh
e
s 00001/00001/00242
d D 5.3 85/06/06 01:09:33 lepreau 16 15
c correct usage msg
e
s 00007/00001/00236
d D 5.2 85/05/31 09:44:31 bloom 15 14
c Ignore -L flag so can get passed to rlogin
e
s 00014/00002/00223
d D 5.1 85/05/31 09:27:27 dist 14 13
c Add copyright
e
s 00005/00001/00220
d D 4.12 85/04/24 15:54:12 bloom 13 12
c Ignore -w flag so can get passed to rlogin
e
s 00002/00002/00219
d D 4.11 85/03/02 12:30:01 bloom 12 11
c portability fix
e
s 00005/00001/00216
d D 4.10 84/12/17 07:45:48 lepreau 11 10
c ignore -8 flag so can get passed to rlogin
e
s 00002/00002/00215
d D 4.9 84/12/03 00:05:43 lepreau 10 9
c cnvt setsockopt to new interface
e
s 00008/00011/00209
d D 4.8 83/06/10 23:34:39 sam 9 8
c new signals, no libjobs
e
s 00002/00001/00218
d D 4.7 83/02/23 13:57:47 sam 8 7
c calling shutdown w/ wrong parameter causes -n to break
e
s 00004/00004/00215
d D 4.6 83/02/09 17:06:06 sam 7 6
c from sun
e
s 00008/00000/00211
d D 4.5 83/01/30 21:27:06 leres 6 4
c Ignore the -e flag to allow aliases with rlogin to work
e
s 00008/00000/00211
d R 4.5 83/01/30 21:17:58 leres 5 4
c Ignore the -e flag to allow aliases with rlogin to work
e
s 00011/00001/00200
d D 4.4 83/01/13 20:53:33 sam 4 3
c SIOCDONE -> shutdown; socket options
e
s 00008/00001/00193
d D 4.3 82/12/25 21:18:28 sam 3 2
c port numbers now byte swapped; eliminate constant
e
s 00019/00005/00175
d D 4.2 82/11/14 15:14:58 sam 2 1
c convert to 4.1c sys calls and directory layout
e
s 00180/00000/00000
d D 4.1 82/04/02 10:29:03 wnj 1 0
c date and time created 82/04/02 10:29:03 by wnj
e
u
U
f b 
t
T
I 14
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 14
I 1
#ifndef lint
D 14
static char sccsid[] = "%W% %E%";
#endif
E 14
I 14
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 14

D 2
#include <stdio.h>
E 2
#include <sys/types.h>
#include <sys/socket.h>
D 2
#include <net/in.h>
E 2
I 2
#include <sys/ioctl.h>
E 2
#include <sys/file.h>
I 2

#include <netinet/in.h>

#include <stdio.h>
E 2
#include <errno.h>
#include <signal.h>
D 2
#include <sys/ioctl.h>
E 2
#include <pwd.h>
I 3
#include <netdb.h>
E 3

/*
 * rsh - remote shell
 */
/* VARARGS */
int	error();
D 19
char	*index(), *rindex(), *malloc(), *getpass(), *sprintf(), *strcpy();
E 19
I 19
char	*index(), *rindex(), *malloc(), *getpass(), *strcpy();
E 19

struct	passwd *getpwuid();

int	errno;
int	options;
int	rfd2;
I 18
int	nflag;
E 18
int	sendsig();

I 9
#define	mask(s)	(1 << ((s) - 1))

E 9
main(argc, argv0)
	int argc;
	char **argv0;
{
	int rem, pid;
	char *host, *cp, **ap, buf[BUFSIZ], *args, **argv = argv0, *user = 0;
	register int cc;
	int asrsh = 0;
	struct passwd *pwd;
	int readfrom, ready;
	int one = 1;
I 3
	struct servent *sp;
I 9
	int omask;
E 9
E 3

	host = rindex(argv[0], '/');
	if (host)
		host++;
	else
		host = argv[0];
	argv++, --argc;
	if (!strcmp(host, "rsh")) {
		host = *argv++, --argc;
		asrsh = 1;
	}
another:
D 7
	if (!strcmp(*argv, "-l")) {
E 7
I 7
	if (argc > 0 && !strcmp(*argv, "-l")) {
E 7
		argv++, argc--;
		if (argc > 0)
			user = *argv++, argc--;
		goto another;
	}
D 7
	if (!strcmp(*argv, "-n")) {
E 7
I 7
	if (argc > 0 && !strcmp(*argv, "-n")) {
E 7
		argv++, argc--;
D 18
		(void) close(0);
		(void) open("/dev/null", 0);
E 18
I 18
		nflag++;
E 18
		goto another;
	}
D 7
	if (!strcmp(*argv, "-d")) {
E 7
I 7
	if (argc > 0 && !strcmp(*argv, "-d")) {
E 7
		argv++, argc--;
		options |= SO_DEBUG;
		goto another;
	}
I 6
	/*
D 11
	 * Ignore the -e flag to allow aliases with rlogin
E 11
I 11
D 13
	 * Ignore the -e and -8 flags to allow aliases with rlogin
E 13
I 13
D 15
	 * Ignore the -w, -e and -8 flags to allow aliases with rlogin
E 15
I 15
	 * Ignore the -L, -w, -e and -8 flags to allow aliases with rlogin
E 15
E 13
E 11
	 * to work
I 15
	 *
	 * There must be a better way to do this! -jmb
E 15
	 */
I 15
	if (argc > 0 && !strncmp(*argv, "-L", 2)) {
		argv++, argc--;
		goto another;
	}
E 15
I 13
	if (argc > 0 && !strncmp(*argv, "-w", 2)) {
		argv++, argc--;
		goto another;
	}
E 13
D 7
	if (!strncmp(*argv, "-e", 2)) {
E 7
I 7
	if (argc > 0 && !strncmp(*argv, "-e", 2)) {
I 11
		argv++, argc--;
		goto another;
	}
	if (argc > 0 && !strncmp(*argv, "-8", 2)) {
E 11
E 7
		argv++, argc--;
		goto another;
	}
E 6
	if (host == 0)
		goto usage;
	if (argv[0] == 0) {
		if (asrsh)
			*argv0 = "rlogin";
		execv("/usr/ucb/rlogin", argv0);
		perror("/usr/ucb/rlogin");
		exit(1);
	}
	pwd = getpwuid(getuid());
	if (pwd == 0) {
		fprintf(stderr, "who are you?\n");
		exit(1);
	}
	cc = 0;
	for (ap = argv; *ap; ap++)
		cc += strlen(*ap) + 1;
	cp = args = malloc(cc);
	for (ap = argv; *ap; ap++) {
		(void) strcpy(cp, *ap);
		while (*cp)
			cp++;
		if (ap[1])
			*cp++ = ' ';
	}
D 3
        rem = rcmd(&host, IPPORT_CMDSERVER, pwd->pw_name,
E 3
I 3
	sp = getservbyname("shell", "tcp");
	if (sp == 0) {
		fprintf(stderr, "rsh: shell/tcp: unknown service\n");
		exit(1);
	}
        rem = rcmd(&host, sp->s_port, pwd->pw_name,
E 3
	    user ? user : pwd->pw_name, args, &rfd2);
        if (rem < 0)
                exit(1);
I 4
	if (rfd2 < 0) {
		fprintf(stderr, "rsh: can't establish stderr\n");
		exit(2);
	}
	if (options & SO_DEBUG) {
D 10
		if (setsockopt(rem, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 10
I 10
		if (setsockopt(rem, SOL_SOCKET, SO_DEBUG, &one, sizeof (one)) < 0)
E 10
			perror("setsockopt (stdin)");
D 10
		if (setsockopt(rfd2, SOL_SOCKET, SO_DEBUG, 0, 0) < 0)
E 10
I 10
		if (setsockopt(rfd2, SOL_SOCKET, SO_DEBUG, &one, sizeof (one)) < 0)
E 10
			perror("setsockopt (stderr)");
	}
E 4
	(void) setuid(getuid());
D 9
	sigacts(SIG_HOLD);
E 9
I 9
	omask = sigblock(mask(SIGINT)|mask(SIGQUIT)|mask(SIGTERM));
D 17
	signal(SIGINT, sendsig);
	signal(SIGQUIT, sendsig);
	signal(SIGTERM, sendsig);
E 17
I 17
	if (signal(SIGINT, SIG_IGN) != SIG_IGN)
		signal(SIGINT, sendsig);
	if (signal(SIGQUIT, SIG_IGN) != SIG_IGN)
		signal(SIGQUIT, sendsig);
	if (signal(SIGTERM, SIG_IGN) != SIG_IGN)
		signal(SIGTERM, sendsig);
E 17
E 9
D 18
        pid = fork();
        if (pid < 0) {
		perror("fork");
                exit(1);
        }
E 18
I 18
	if (nflag == 0) {
		pid = fork();
		if (pid < 0) {
			perror("fork");
			exit(1);
		}
	}
E 18
	ioctl(rfd2, FIONBIO, &one);
	ioctl(rem, FIONBIO, &one);
D 18
        if (pid == 0) {
E 18
I 18
        if (nflag == 0 && pid == 0) {
E 18
		char *bp; int rembits, wc;
		(void) close(rfd2);
	reread:
I 8
		errno = 0;
E 8
		cc = read(0, buf, sizeof buf);
		if (cc <= 0)
			goto done;
		bp = buf;
	rewrite:
		rembits = 1<<rem;
D 2
		(void) select(20, 0, &rembits, 100000);
E 2
I 2
		if (select(16, 0, &rembits, 0, 0) < 0) {
			if (errno != EINTR) {
				perror("select");
				exit(1);
			}
			goto rewrite;
		}
E 2
		if ((rembits & (1<<rem)) == 0)
			goto rewrite;
		wc = write(rem, bp, cc);
		if (wc < 0) {
			if (errno == EWOULDBLOCK)
				goto rewrite;
			goto done;
		}
		cc -= wc; bp += wc;
		if (cc == 0)
			goto reread;
		goto rewrite;
	done:
D 4
		{ int flags = 1; ioctl(rem, SIOCDONE, &flags); }
E 4
I 4
D 8
		{ int flags = 1; (void) shutdown(rem, &flags); }
E 8
I 8
		(void) shutdown(rem, 1);
E 8
E 4
		exit(0);
	}
D 9
	sigacts(sendsig);
E 9
I 9
	sigsetmask(omask);
E 9
	readfrom = (1<<rfd2) | (1<<rem);
	do {
		ready = readfrom;
D 2
		(void) select(32, &ready, 0, 10000000);
E 2
I 2
		if (select(16, &ready, 0, 0, 0) < 0) {
			if (errno != EINTR) {
				perror("select");
				exit(1);
			}
			continue;
		}
E 2
		if (ready & (1<<rfd2)) {
			errno = 0;
			cc = read(rfd2, buf, sizeof buf);
			if (cc <= 0) {
				if (errno != EWOULDBLOCK)
					readfrom &= ~(1<<rfd2);
			} else
				(void) write(2, buf, cc);
		}
		if (ready & (1<<rem)) {
			errno = 0;
			cc = read(rem, buf, sizeof buf);
			if (cc <= 0) {
				if (errno != EWOULDBLOCK)
					readfrom &= ~(1<<rem);
			} else
				(void) write(1, buf, cc);
		}
        } while (readfrom);
D 18
        (void) kill(pid, SIGKILL);
E 18
I 18
	if (nflag == 0)
		(void) kill(pid, SIGKILL);
E 18
	exit(0);
usage:
	fprintf(stderr,
D 16
	    "usage: rsh host [ -l login ] [ -p passwd ] command\n");
E 16
I 16
	    "usage: rsh host [ -l login ] [ -n ] command\n");
E 16
	exit(1);
D 9
}

sigacts(state)
	int (*state)();
{

	sigset(SIGINT, state);
	sigset(SIGQUIT, state);
	sigset(SIGTERM, state);
E 9
}

sendsig(signo)
D 12
	int signo;
E 12
I 12
	char signo;
E 12
{

D 12
	(void) write(rfd2, (char *)&signo, 1);
E 12
I 12
	(void) write(rfd2, &signo, 1);
E 12
}
E 1
