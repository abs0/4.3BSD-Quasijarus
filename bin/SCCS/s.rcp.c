h31918
s 00001/00001/00718
d D 5.9 87/10/22 09:55:43 bostic 29 28
c ANSI C; sprintf now returns an int.
e
s 00006/00006/00713
d D 5.8 87/09/28 18:26:40 bostic 28 27
c change "file changed size" error to a real read error message
e
s 00015/00005/00704
d D 5.7 87/09/10 15:26:01 bostic 27 26
c usage for only 1 argument; do copy/truncate, not create 
c RCP clobbers files; bug report 4.3BSD/bin/24
e
s 00004/00002/00705
d D 5.6 87/07/27 16:28:38 bostic 26 25
c rcp dereferences NULL; bug report 4.3BSD/bin/36
e
s 00002/00002/00705
d D 5.5 87/05/05 08:49:41 bostic 25 24
c don't use search path for rsh, hardwire it in; bug report 4.3BSD/bin/65
e
s 00019/00061/00688
d D 5.4 85/09/12 16:14:41 bloom 24 23
c fix protocol error returns (karels), make work with named and remove old code
e
s 00008/00003/00741
d D 5.3 85/06/08 01:02:26 lepreau 23 21
c overload -p to also mean "preserve modes/ignore umask"
e
s 00007/00002/00742
d R 5.3 85/06/08 00:23:52 lepreau 22 21
c overload -p to also mean "preserve mode info/ignore umask"
e
s 00125/00052/00619
d D 5.2 85/06/08 00:09:58 lepreau 21 20
c add -p option to preserve file & dir a/mtimes
e
s 00014/00002/00657
d D 5.1 85/05/31 09:24:56 dist 20 19
c Add copyright
e
s 00073/00023/00586
d D 4.16 85/05/29 16:15:15 mckusick 19 18
c use a file system optimal blocksize
e
s 00051/00000/00558
d D 4.15 85/04/11 09:47:55 ralph 18 16
c make changes ifdef NAMESERVER for others to use.
e
s 00023/00035/00523
d R 4.15 85/04/11 09:11:34 ralph 17 16
c undo user@ change until nameser is really used.
e
s 00035/00023/00523
d D 4.14 85/03/05 16:15:23 ralph 16 15
c change to user@host:file to avoid conflicts with the nameserver.
e
s 00028/00063/00518
d D 4.13 85/02/27 11:45:21 ralph 15 14
c removed replaced makedir with mkdir, more speedups.
e
s 00010/00003/00571
d D 4.12 85/02/20 16:01:25 ralph 14 13
c use getservbyname() instead of constants.
e
s 00031/00039/00543
d D 4.11 85/02/16 17:49:52 serge 13 11
c streamline susystem() and makedir() by removing unnecessary fork's
e
s 00033/00039/00543
d R 4.11 85/01/09 18:26:08 serge 12 11
c streamline susystem() and makedir() by removing unnecessary fork's
e
s 00002/00001/00580
d D 4.10 84/02/13 15:49:44 ralph 11 9
c fix access check of parent directory for names like /foo.
e
s 00007/00010/00571
d R 4.10 84/01/30 15:10:13 ralph 10 9
c need to copy user name due to new getpwnam().
e
s 00006/00006/00575
d D 4.9 84/01/26 15:59:56 ralph 9 8
c fix 3rd party transfers
e
s 00017/00005/00564
d D 4.8 83/08/12 11:58:58 ralph 8 7
c fixes "No match." message from shell.
e
s 00001/00001/00568
d D 4.7 83/07/03 16:04:28 sam 7 6
c typo
e
s 00008/00002/00561
d D 4.6 83/07/01 03:01:53 sam 6 5
c default null name after : to "."
e
s 00005/00004/00558
d D 4.5 83/06/10 23:34:10 sam 5 4
c new signals, no libjobs
e
s 00005/00003/00557
d D 4.4 82/11/14 15:09:19 sam 4 3
c convert to 4.1c sys calls and directory layout
e
s 00002/00002/00558
d D 4.3 82/05/09 23:58:49 mckusick 3 2
c update to new fs
e
s 00007/00004/00553
d D 4.2 82/05/05 19:00:27 mckusick 2 1
c add tef's mods for pdp-11's
e
s 00557/00000/00000
d D 4.1 82/04/02 10:28:53 wnj 1 0
c date and time created 82/04/02 10:28:53 by wnj
e
u
U
f b 
t
T
I 20
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 20
I 1
#ifndef lint
D 20
static char sccsid[] = "%W% %E%";
#endif
E 20
I 20
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 20

I 5
/*
 * rcp
 */
E 5
D 4
#include <stdio.h>
#include <signal.h>
E 4
D 3
#include <sys/types.h>
E 3
I 3
#include <sys/param.h>
I 27
#include <sys/file.h>
E 27
E 3
#include <sys/stat.h>
I 21
#include <sys/time.h>
E 21
#include <sys/ioctl.h>
D 4
#include <net/in.h>
E 4
I 4

#include <netinet/in.h>

#include <stdio.h>
#include <signal.h>
E 4
#include <pwd.h>
#include <ctype.h>
I 14
#include <netdb.h>
E 14
#include <errno.h>
D 5
/*
 * rcp
 */
E 5
I 5

E 5
int	rem;
D 29
char	*colon(), *index(), *rindex(), *malloc(), *strcpy(), *sprintf();
E 29
I 29
char	*colon(), *index(), *rindex(), *malloc(), *strcpy();
E 29
int	errs;
int	lostconn();
D 21
int	iamremote;

E 21
int	errno;
char	*sys_errlist[];
int	iamremote, targetshouldbedirectory;
int	iamrecursive;
I 21
int	pflag;
E 21
struct	passwd *pwd;
struct	passwd *getpwuid();
I 14
D 15
struct	servent *sp;
E 15
I 15
int	userid;
int	port;
E 15
E 14

I 19
struct buffer {
	int	cnt;
	char	*buf;
} *allocbuf();

E 19
/*VARARGS*/
int	error();

#define	ga()	 	(void) write(rem, "", 1)

main(argc, argv)
	int argc;
	char **argv;
{
	char *targ, *host, *src;
I 18
D 24
#ifndef NAMESERVER
	char *suser, *tuser;
#else NAMESERVER
E 24
E 18
D 16
	char *suser, *tuser;
E 16
I 16
	char *suser, *tuser, *thost;
I 18
D 24
#endif NAMESERVER
E 24
E 18
E 16
	int i;
	char buf[BUFSIZ], cmd[16];
I 15
	struct servent *sp;
E 15
D 14
	
E 14
I 14

	sp = getservbyname("shell", "tcp");
	if (sp == NULL) {
		fprintf(stderr, "rcp: shell/tcp: unknown service\n");
		exit(1);
	}
E 14
D 15
	setpwent();
	pwd = getpwuid(getuid());
	endpwent();
E 15
I 15
	port = sp->s_port;
	pwd = getpwuid(userid = getuid());
E 15
	if (pwd == 0) {
		fprintf(stderr, "who are you?\n");
		exit(1);
	}
D 21
	argc--, argv++;
	if (argc > 0 && !strcmp(*argv, "-r")) {
		iamrecursive++;
		argc--, argv++;
E 21
I 21

	for (argc--, argv++; argc > 0 && **argv == '-'; argc--, argv++) {
		(*argv)++;
		while (**argv) switch (*(*argv)++) {

		    case 'r':
			iamrecursive++;
			break;

		    case 'p':		/* preserve mtimes and atimes */
			pflag++;
			break;

		    /* The rest of these are not for users. */
		    case 'd':
			targetshouldbedirectory = 1;
			break;

		    case 'f':		/* "from" */
			iamremote = 1;
			(void) response();
			(void) setuid(userid);
			source(--argc, ++argv);
			exit(errs);

		    case 't':		/* "to" */
			iamremote = 1;
			(void) setuid(userid);
			sink(--argc, ++argv);
			exit(errs);

		    default:
D 27
			fprintf(stderr,
D 23
		"Usage: rcp [-rp] f1 f2, or: rcp [-rp] f1 ... fn d2\n");
E 23
I 23
		"Usage: rcp [-p] f1 f2; or: rcp [-rp] f1 ... fn d2\n");
E 23
			exit(1);
E 27
I 27
			usage();
E 27
		}
E 21
	}
D 21
	if (argc > 0 && !strcmp(*argv, "-d")) {
		targetshouldbedirectory = 1;
		argc--, argv++;
	}
	if (argc > 0 && !strcmp(*argv, "-f")) {
		argc--, argv++; iamremote = 1;
		(void) response();
D 15
		(void) setuid(getuid());
E 15
I 15
		(void) setuid(userid);
E 15
		source(argc, argv);
		exit(errs);
	}
	if (argc > 0 && !strcmp(*argv, "-t")) {
		argc--, argv++; iamremote = 1;
D 15
		(void) setuid(getuid());
E 15
I 15
		(void) setuid(userid);
E 15
		sink(argc, argv);
		exit(errs);
	}
E 21
D 27
	rem = -1;
E 27
I 27
	if (argc < 2)
		usage();
E 27
	if (argc > 2)
		targetshouldbedirectory = 1;
I 27
	rem = -1;
E 27
D 21
	(void) sprintf(cmd, "rcp%s%s",
	    iamrecursive ? " -r" : "", targetshouldbedirectory ? " -d" : "");
D 5
	sigsys(SIGPIPE, lostconn);
E 5
I 5
	signal(SIGPIPE, lostconn);
E 21
I 21
	(void) sprintf(cmd, "rcp%s%s%s",
	    iamrecursive ? " -r" : "", pflag ? " -p" : "", 
	    targetshouldbedirectory ? " -d" : "");
	(void) signal(SIGPIPE, lostconn);
E 21
E 5
	targ = colon(argv[argc - 1]);
D 21
	if (targ) {
E 21
I 21
	if (targ) {				/* ... to remote */
E 21
		*targ++ = 0;
I 6
		if (*targ == 0)
			targ = ".";
I 18
D 24
#ifndef NAMESERVER
		tuser = rindex(argv[argc - 1], '.');
		if (tuser) {
			*tuser++ = 0;
			if (!okname(tuser))
				exit(1);
		} else
			tuser = pwd->pw_name;
#else NAMESERVER
E 24
E 18
E 6
D 16
		tuser = rindex(argv[argc - 1], '.');
		if (tuser) {
			*tuser++ = 0;
			if (!okname(tuser))
E 16
I 16
		thost = index(argv[argc - 1], '@');
		if (thost) {
			*thost++ = 0;
			tuser = argv[argc - 1];
			if (*tuser == '\0')
D 24
				tuser = pwd->pw_name;
E 24
I 24
				tuser = NULL;
E 24
			else if (!okname(tuser))
E 16
				exit(1);
D 16
		} else
E 16
I 16
		} else {
			thost = argv[argc - 1];
E 16
D 24
			tuser = pwd->pw_name;
E 24
I 24
			tuser = NULL;
E 24
I 16
		}
I 18
D 24
#endif NAMESERVER
E 24
E 18
E 16
		for (i = 0; i < argc - 1; i++) {
			src = colon(argv[i]);
D 21
			if (src) {
E 21
I 21
			if (src) {		/* remote to remote */
E 21
				*src++ = 0;
I 6
				if (*src == 0)
D 7
					*src = ".";
E 7
I 7
					src = ".";
I 18
D 24
#ifndef NAMESERVER
				suser = rindex(argv[i], '.');
				if (suser) {
					*suser++ = 0;
					if (!okname(suser))
#else NAMESERVER
E 24
E 18
E 7
E 6
D 16
				suser = rindex(argv[i], '.');
				if (suser) {
					*suser++ = 0;
					if (!okname(suser))
E 16
I 16
				host = index(argv[i], '@');
				if (host) {
					*host++ = 0;
					suser = argv[i];
					if (*suser == '\0')
						suser = pwd->pw_name;
					else if (!okname(suser))
I 18
D 24
#endif NAMESERVER
E 24
E 18
E 16
						continue;
I 18
D 24
#ifndef NAMESERVER
		(void) sprintf(buf, "rsh %s -l %s -n %s %s '%s.%s:%s'",
					    argv[i], suser, cmd, src,
					    argv[argc - 1], tuser, targ);
E 24
I 24
D 25
		(void) sprintf(buf, "rsh %s -l %s -n %s %s '%s%s%s:%s'",
E 25
I 25
		(void) sprintf(buf, "/usr/ucb/rsh %s -l %s -n %s %s '%s%s%s:%s'",
E 25
D 26
					    host, suser, cmd, src, tuser,
E 26
I 26
					    host, suser, cmd, src,
					    tuser ? tuser : "",
E 26
					    tuser ? "@" : "",
					    thost, targ);
E 24
				} else
D 24
		(void) sprintf(buf, "rsh %s -n %s %s '%s.%s:%s'",
					    argv[i], cmd, src,
					    argv[argc - 1], tuser, targ);
#else NAMESERVER
E 18
D 2
		(void) sprintf(buf, "rsh %s -l %s %s %s '%s:%s' </dev/null",
E 2
I 2
D 8
		(void) sprintf(buf, "rsh %s -L %s %s %s '%s:%s' </dev/null",
E 8
I 8
D 9
		(void) sprintf(buf, "rsh %s -L %s -n %s %s '%s:%s'",
E 8
E 2
					    argv[i], suser, cmd,
					    src, argv[argc - 1], targ);
E 9
I 9
D 16
		(void) sprintf(buf, "rsh %s -l %s -n %s %s '%s.%s:%s'",
					    argv[i], suser, cmd, src,
					    argv[argc - 1], tuser, targ);
E 16
I 16
		(void) sprintf(buf, "rsh %s -l %s -n %s %s '%s@%s:%s'",
					    host, suser, cmd, src,
					    tuser, thost, targ);
E 16
E 9
				} else
D 8
		(void) sprintf(buf, "rsh %s %s %s '%s:%s' </dev/null",
E 8
I 8
D 9
		(void) sprintf(buf, "rsh %s -n %s %s '%s:%s'",
E 8
					    argv[i], cmd,
					    src, argv[argc - 1], targ);
E 9
I 9
D 16
		(void) sprintf(buf, "rsh %s -n %s %s '%s.%s:%s'",
E 16
I 16
		(void) sprintf(buf, "rsh %s -n %s %s '%s@%s:%s'",
E 16
					    argv[i], cmd, src,
D 16
					    argv[argc - 1], tuser, targ);
E 16
I 16
					    tuser, thost, targ);
I 18
#endif NAMESERVER
E 24
I 24
D 25
		(void) sprintf(buf, "rsh %s -n %s %s '%s%s%s:%s'",
E 25
I 25
		(void) sprintf(buf, "/usr/ucb/rsh %s -n %s %s '%s%s%s:%s'",
E 25
D 26
					    argv[i], cmd, src, tuser,
E 26
I 26
					    argv[i], cmd, src,
					    tuser ? tuser : "",
E 26
					    tuser ? "@" : "",
					    thost, targ);
E 24
E 18
E 16
E 9
				(void) susystem(buf);
D 21
			} else {
E 21
I 21
			} else {		/* local to remote */
E 21
				if (rem == -1) {
					(void) sprintf(buf, "%s -t %s",
					    cmd, targ);
I 18
D 24
#ifndef NAMESERVER
					host = argv[argc - 1];
#else NAMESERVER
E 24
E 18
D 16
					host = argv[argc - 1];
E 16
I 16
					host = thost;
I 18
D 24
#endif NAMESERVER
E 18
E 16
D 14
					rem = rcmd(&host, IPPORT_CMDSERVER,
E 14
I 14
D 15
					rem = rcmd(&host, sp->s_port,
E 14
					    pwd->pw_name, tuser,
E 15
I 15
					rem = rcmd(&host, port, pwd->pw_name, tuser,
E 24
I 24
					rem = rcmd(&host, port, pwd->pw_name,
					    tuser ? tuser : pwd->pw_name,
E 24
E 15
					    buf, 0);
					if (rem < 0)
						exit(1);
					if (response() < 0)
						exit(1);
I 15
					(void) setuid(userid);
E 15
				}
				source(1, argv+i);
			}
		}
D 21
	} else {
E 21
I 21
	} else {				/* ... to local */
E 21
		if (targetshouldbedirectory)
			verifydir(argv[argc - 1]);
		for (i = 0; i < argc - 1; i++) {
			src = colon(argv[i]);
D 21
			if (src == 0) {
				(void) sprintf(buf, "/bin/cp%s %s %s",
E 21
I 21
			if (src == 0) {		/* local to local */
				(void) sprintf(buf, "/bin/cp%s%s %s %s",
E 21
				    iamrecursive ? " -r" : "",
I 21
				    pflag ? " -p" : "",
E 21
				    argv[i], argv[argc - 1]);
				(void) susystem(buf);
D 21
			} else {
E 21
I 21
			} else {		/* remote to local */
E 21
				*src++ = 0;
I 6
				if (*src == 0)
					src = ".";
I 18
D 24
#ifndef NAMESERVER
				suser = rindex(argv[i], '.');
				if (suser) {
					*suser++ = 0;
					if (!okname(suser))
#else NAMESERVER
E 24
E 18
E 6
D 16
				suser = rindex(argv[i], '.');
				if (suser) {
					*suser++ = 0;
					if (!okname(suser))
E 16
I 16
				host = index(argv[i], '@');
				if (host) {
					*host++ = 0;
					suser = argv[i];
					if (*suser == '\0')
						suser = pwd->pw_name;
					else if (!okname(suser))
I 18
D 24
#endif NAMESERVER
E 24
E 18
E 16
						continue;
I 18
D 24
#ifndef NAMESERVER
				} else
#else NAMESERVER
E 24
E 18
D 16
				} else
E 16
I 16
				} else {
					host = argv[i];
I 18
D 24
#endif NAMESERVER
E 24
E 18
E 16
					suser = pwd->pw_name;
I 18
D 24
#ifdef NAMESERVER
E 24
E 18
I 16
				}
I 18
D 24
#endif NAMESERVER
E 24
E 18
E 16
				(void) sprintf(buf, "%s -f %s", cmd, src);
I 18
D 24
#ifndef NAMESERVER
				host = argv[i];
#endif NAMESERVER
E 24
E 18
D 16
				host = argv[i];
E 16
D 14
				rem = rcmd(&host, IPPORT_CMDSERVER,
E 14
I 14
D 15
				rem = rcmd(&host, sp->s_port,
E 14
				    pwd->pw_name, suser,
E 15
I 15
				rem = rcmd(&host, port, pwd->pw_name, suser,
E 15
				    buf, 0);
				if (rem < 0)
D 16
					exit(1);
E 16
I 16
					continue;
E 16
I 15
				(void) setreuid(0, userid);
E 15
				sink(1, argv+argc-1);
I 15
				(void) setreuid(userid, 0);
E 15
				(void) close(rem);
				rem = -1;
			}
		}
	}
	exit(errs);
}

verifydir(cp)
	char *cp;
{
	struct stat stb;

D 15
	if (stat(cp, &stb) < 0)
		goto bad;
	if ((stb.st_mode & S_IFMT) == S_IFDIR)
		return;
	errno = ENOTDIR;
bad:
E 15
I 15
	if (stat(cp, &stb) >= 0) {
		if ((stb.st_mode & S_IFMT) == S_IFDIR)
			return;
		errno = ENOTDIR;
	}
E 15
	error("rcp: %s: %s.\n", cp, sys_errlist[errno]);
	exit(1);
}

char *
colon(cp)
	char *cp;
{

	while (*cp) {
		if (*cp == ':')
			return (cp);
		if (*cp == '/')
			return (0);
		cp++;
	}
	return (0);
}

okname(cp0)
	char *cp0;
{
	register char *cp = cp0;
	register int c;

	do {
		c = *cp;
		if (c & 0200)
			goto bad;
		if (!isalpha(c) && !isdigit(c) && c != '_' && c != '-')
			goto bad;
		cp++;
	} while (*cp);
	return (1);
bad:
	fprintf(stderr, "rcp: invalid user name %s\n", cp0);
	return (0);
}

D 13
susystem(buf)
	char *buf;
E 13
I 13
susystem(s)
	char *s;
E 13
{
I 13
	int status, pid, w;
	register int (*istat)(), (*qstat)();
E 13

D 13
	if (fork() == 0) {
		(void) setuid(getuid());
		(void) system(buf);
		_exit(0);
	} else
		(void) wait((int *)0);
E 13
I 13
	if ((pid = vfork()) == 0) {
D 15
		setuid(getuid());
E 15
I 15
D 21
		setuid(userid);
E 21
I 21
		(void) setuid(userid);
E 21
E 15
		execl("/bin/sh", "sh", "-c", s, (char *)0);
		_exit(127);
	}
	istat = signal(SIGINT, SIG_IGN);
	qstat = signal(SIGQUIT, SIG_IGN);
	while ((w = wait(&status)) != pid && w != -1)
		;
	if (w == -1)
		status = -1;
D 21
	signal(SIGINT, istat);
	signal(SIGQUIT, qstat);
E 21
I 21
	(void) signal(SIGINT, istat);
	(void) signal(SIGQUIT, qstat);
E 21
	return (status);
E 13
}

source(argc, argv)
	int argc;
	char **argv;
{
	char *last, *name;
	struct stat stb;
D 19
	char buf[BUFSIZ];
D 2
	int x, sizerr, f, i;
E 2
I 2
	int x, sizerr, f;
E 19
I 19
	static struct buffer buffer;
	struct buffer *bp;
D 28
	int x, sizerr, f, amt;
E 28
I 28
	int x, readerr, f, amt;
E 28
E 19
	off_t i;
I 19
	char buf[BUFSIZ];
E 19
E 2

	for (x = 0; x < argc; x++) {
		name = argv[x];
D 15
		if (access(name, 4) < 0 || (f = open(name, 0)) < 0) {
E 15
I 15
		if ((f = open(name, 0)) < 0) {
E 15
			error("rcp: %s: %s\n", name, sys_errlist[errno]);
			continue;
		}
		if (fstat(f, &stb) < 0)
			goto notreg;
		switch (stb.st_mode&S_IFMT) {

		case S_IFREG:
			break;

		case S_IFDIR:
			if (iamrecursive) {
				(void) close(f);
D 21
				rsource(name, (int)stb.st_mode);
E 21
I 21
				rsource(name, &stb);
E 21
				continue;
			}
			/* fall into ... */
		default:
notreg:
			(void) close(f);
			error("rcp: %s: not a plain file\n", name);
			continue;
		}
		last = rindex(name, '/');
		if (last == 0)
			last = name;
		else
			last++;
D 2
		(void) sprintf(buf, "C%04o %d %s\n",
E 2
I 2
D 21
		(void) sprintf(buf, "C%04o %D %s\n",
E 21
I 21
		if (pflag) {
			/*
			 * Make it compatible with possible future
			 * versions expecting microseconds.
			 */
			(void) sprintf(buf, "T%ld 0 %ld 0\n",
			    stb.st_mtime, stb.st_atime);
			(void) write(rem, buf, strlen(buf));
			if (response() < 0) {
				(void) close(f);
				continue;
			}
		}
		(void) sprintf(buf, "C%04o %ld %s\n",
E 21
E 2
		    stb.st_mode&07777, stb.st_size, last);
		(void) write(rem, buf, strlen(buf));
		if (response() < 0) {
			(void) close(f);
			continue;
		}
I 19
		if ((bp = allocbuf(&buffer, f, BUFSIZ)) < 0) {
			(void) close(f);
			continue;
		}
E 19
D 28
		sizerr = 0;
E 28
I 28
		readerr = 0;
E 28
D 19
		for (i = 0; i < stb.st_size; i += BUFSIZ) {
			int amt = BUFSIZ;
E 19
I 19
		for (i = 0; i < stb.st_size; i += bp->cnt) {
			amt = bp->cnt;
E 19
			if (i + amt > stb.st_size)
				amt = stb.st_size - i;
D 19
			if (sizerr == 0 && read(f, buf, amt) != amt)
E 19
I 19
D 28
			if (sizerr == 0 && read(f, bp->buf, amt) != amt)
E 19
				sizerr = 1;
E 28
I 28
			if (readerr == 0 && read(f, bp->buf, amt) != amt)
				readerr = errno;
E 28
D 19
			(void) write(rem, buf, amt);
E 19
I 19
			(void) write(rem, bp->buf, amt);
E 19
		}
		(void) close(f);
D 28
		if (sizerr == 0)
E 28
I 28
		if (readerr == 0)
E 28
			ga();
		else
D 28
			error("rcp: %s: file changed size\n", name);
E 28
I 28
			error("rcp: %s: %s\n", name, sys_errlist[readerr]);
E 28
		(void) response();
	}
}

D 3
#include <ndir.h>
E 3
I 3
D 6
#include <dir.h>
E 6
I 6
#include <sys/dir.h>
E 6
E 3

D 21
rsource(name, mode)
E 21
I 21
rsource(name, statp)
E 21
	char *name;
D 21
	int mode;
E 21
I 21
	struct stat *statp;
E 21
{
	DIR *d = opendir(name);
	char *last;
	struct direct *dp;
	char buf[BUFSIZ];
	char *bufv[1];

	if (d == 0) {
D 15
		error("%s: %s\n", name, sys_errlist[errno]);
E 15
I 15
		error("rcp: %s: %s\n", name, sys_errlist[errno]);
E 15
		return;
	}
	last = rindex(name, '/');
	if (last == 0)
		last = name;
	else
		last++;
D 21
	(void) sprintf(buf, "D%04o %d %s\n", mode&07777, 0, last);
E 21
I 21
	if (pflag) {
		(void) sprintf(buf, "T%ld 0 %ld 0\n",
		    statp->st_mtime, statp->st_atime);
		(void) write(rem, buf, strlen(buf));
		if (response() < 0) {
			closedir(d);
			return;
		}
	}
	(void) sprintf(buf, "D%04o %d %s\n", statp->st_mode&07777, 0, last);
E 21
	(void) write(rem, buf, strlen(buf));
	if (response() < 0) {
		closedir(d);
		return;
	}
	while (dp = readdir(d)) {
		if (dp->d_ino == 0)
			continue;
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;
		if (strlen(name) + 1 + strlen(dp->d_name) >= BUFSIZ - 1) {
			error("%s/%s: Name too long.\n", name, dp->d_name);
			continue;
		}
		(void) sprintf(buf, "%s/%s", name, dp->d_name);
		bufv[0] = buf;
		source(1, bufv);
	}
	closedir(d);
	(void) write(rem, "E\n", 2);
	(void) response();
}

response()
{
	char resp, c, rbuf[BUFSIZ], *cp = rbuf;

	if (read(rem, &resp, 1) != 1)
		lostconn();
	switch (resp) {

D 21
	case 0:
E 21
I 21
	case 0:				/* ok */
E 21
		return (0);

	default:
		*cp++ = resp;
		/* fall into... */
D 21
	case 1:
	case 2:
E 21
I 21
	case 1:				/* error, followed by err msg */
	case 2:				/* fatal error, "" */
E 21
		do {
			if (read(rem, &c, 1) != 1)
				lostconn();
			*cp++ = c;
		} while (cp < &rbuf[BUFSIZ] && c != '\n');
		if (iamremote == 0)
			(void) write(2, rbuf, cp - rbuf);
		errs++;
		if (resp == 1)
			return (-1);
		exit(1);
	}
	/*NOTREACHED*/
}

lostconn()
{

	if (iamremote == 0)
		fprintf(stderr, "rcp: lost connection\n");
	exit(1);
}

sink(argc, argv)
	int argc;
	char **argv;
{
D 19
	char *targ;
	char cmdbuf[BUFSIZ], nambuf[BUFSIZ], buf[BUFSIZ], *cp;
D 2
	int of, mode, i, size, wrerr, exists;
E 2
I 2
D 8
	int of, mode, wrerr, exists;
E 8
I 8
	int of, mode, wrerr, exists, first;
E 8
	off_t i, size;
E 2
	char *whopp;
	struct stat stb; int targisdir = 0;
#define	SCREWUP(str)	{ whopp = str; goto screwup; }
E 19
I 19
	off_t i, j;
	char *targ, *whopp, *cp;
	int of, mode, wrerr, exists, first, count, amt, size;
	struct buffer *bp;
	static struct buffer buffer;
	struct stat stb;
	int targisdir = 0;
E 19
	int mask = umask(0);
	char *myargv[1];
I 19
D 21
	char cmdbuf[BUFSIZ], nambuf[BUFSIZ], buf[BUFSIZ];
E 21
I 21
	char cmdbuf[BUFSIZ], nambuf[BUFSIZ];
	int setimes = 0;
	struct timeval tv[2];
#define atime	tv[0]
#define mtime	tv[1]
E 21
#define	SCREWUP(str)	{ whopp = str; goto screwup; }
E 19

D 21
	umask(mask);
E 21
I 21
D 23
	(void) umask(mask);
E 23
I 23
	if (!pflag)
		(void) umask(mask);
E 23
E 21
D 15
	if (argc > 1) {
E 15
I 15
	if (argc != 1) {
E 15
		error("rcp: ambiguous target\n");
		exit(1);
	}
	targ = *argv;
	if (targetshouldbedirectory)
		verifydir(targ);
	ga();
	if (stat(targ, &stb) == 0 && (stb.st_mode & S_IFMT) == S_IFDIR)
		targisdir = 1;
D 8
	for (;;) {
E 8
I 8
	for (first = 1; ; first = 0) {
E 8
		cp = cmdbuf;
		if (read(rem, cp, 1) <= 0)
			return;
		if (*cp++ == '\n')
			SCREWUP("unexpected '\\n'");
		do {
			if (read(rem, cp, 1) != 1)
				SCREWUP("lost connection");
		} while (*cp++ != '\n');
		*cp = 0;
		if (cmdbuf[0] == '\01' || cmdbuf[0] == '\02') {
			if (iamremote == 0)
D 6
				(void) write(2, cmdbuf, strlen(cmdbuf));
E 6
I 6
				(void) write(2, cmdbuf+1, strlen(cmdbuf+1));
E 6
			if (cmdbuf[0] == '\02')
				exit(1);
			errs++;
			continue;
		}
		*--cp = 0;
		cp = cmdbuf;
		if (*cp == 'E') {
			ga();
			return;
		}
I 21

#define getnum(t) (t) = 0; while (isdigit(*cp)) (t) = (t) * 10 + (*cp++ - '0');
		if (*cp == 'T') {
			setimes++;
			cp++;
			getnum(mtime.tv_sec);
			if (*cp++ != ' ')
				SCREWUP("mtime.sec not delimited");
			getnum(mtime.tv_usec);
			if (*cp++ != ' ')
				SCREWUP("mtime.usec not delimited");
			getnum(atime.tv_sec);
			if (*cp++ != ' ')
				SCREWUP("atime.sec not delimited");
			getnum(atime.tv_usec);
			if (*cp++ != '\0')
				SCREWUP("atime.usec not delimited");
			ga();
			continue;
		}
E 21
D 8
		if (*cp != 'C' && *cp != 'D')
E 8
I 8
		if (*cp != 'C' && *cp != 'D') {
			/*
			 * Check for the case "rcp remote:foo\* local:bar".
			 * In this case, the line "No match." can be returned
			 * by the shell before the rcp command on the remote is
			 * executed so the ^Aerror_message convention isn't
			 * followed.
			 */
			if (first) {
				error("%s\n", cp);
				exit(1);
			}
E 8
			SCREWUP("expected control record");
I 8
		}
E 8
		cp++;
		mode = 0;
		for (; cp < cmdbuf+5; cp++) {
			if (*cp < '0' || *cp > '7')
				SCREWUP("bad mode");
			mode = (mode << 3) | (*cp - '0');
		}
		if (*cp++ != ' ')
			SCREWUP("mode not delimited");
		size = 0;
D 23
		while (*cp >= '0' && *cp <= '9')
E 23
I 23
		while (isdigit(*cp))
E 23
			size = size * 10 + (*cp++ - '0');
		if (*cp++ != ' ')
			SCREWUP("size not delimited");
		if (targisdir)
			(void) sprintf(nambuf, "%s%s%s", targ,
			    *targ ? "/" : "", cp);
		else
			(void) strcpy(nambuf, targ);
		exists = stat(nambuf, &stb) == 0;
D 15
		if (exists && access(nambuf, 2) < 0)
			goto bad2;
		{ char *slash = rindex(nambuf, '/'), *dir;
		  if (slash == 0) {
			slash = "/";
			dir = ".";
		  } else {
			*slash = 0;
			dir = nambuf;
I 11
			if (*dir == '\0')
				dir = "/";
E 11
		  }
		  if (exists == 0 && access(dir, 2) < 0)
			goto bad;
		  *slash = '/';
		  if (cmdbuf[0] == 'D') {
			if (stat(nambuf, &stb) == 0) {
E 15
I 15
		if (cmdbuf[0] == 'D') {
			if (exists) {
E 15
				if ((stb.st_mode&S_IFMT) != S_IFDIR) {
					errno = ENOTDIR;
					goto bad;
				}
I 23
				if (pflag)
					(void) chmod(nambuf, mode);
E 23
D 13
			} else if (mkdir(nambuf, mode) < 0)
E 13
I 13
D 15
			} else if (makedir(nambuf, mode) < 0)
E 15
I 15
			} else if (mkdir(nambuf, mode) < 0)
E 15
E 13
				goto bad;
			myargv[0] = nambuf;
			sink(1, myargv);
I 21
			if (setimes) {
				setimes = 0;
				if (utimes(nambuf, tv) < 0)
					error("rcp: can't set times on %s: %s\n",
					    nambuf, sys_errlist[errno]);
			}
E 21
			continue;
D 15
		  }
		  if ((of = creat(nambuf, mode)) < 0) {
E 15
I 15
		}
D 27
		if ((of = creat(nambuf, mode)) < 0) {
E 27
I 27
		if ((of = open(nambuf, O_WRONLY|O_CREAT, mode)) < 0) {
E 27
E 15
	bad:
D 15
			*slash = '/';
	bad2:
E 15
			error("rcp: %s: %s\n", nambuf, sys_errlist[errno]);
			continue;
D 15
		  }
E 15
		}
I 23
		if (exists && pflag)
			(void) fchmod(of, mode);
E 23
D 15
		if (exists == 0) {
D 13
			(void) stat(nambuf, &stb);
			(void) chown(nambuf, pwd->pw_uid, stb.st_gid);
E 13
I 13
			(void) chown(nambuf, pwd->pw_uid, -1);
E 13
			(void) chmod(nambuf, mode &~ mask);
		}
E 15
I 15
D 21
		if (exists)
			(void) fchmod(of, mode &~ mask);
E 21
E 15
		ga();
I 19
		if ((bp = allocbuf(&buffer, of, BUFSIZ)) < 0) {
D 21
			close(of);
E 21
I 21
			(void) close(of);
E 21
			continue;
		}
		cp = bp->buf;
		count = 0;
E 19
		wrerr = 0;
		for (i = 0; i < size; i += BUFSIZ) {
D 19
			int amt = BUFSIZ;
			char *cp = buf;

E 19
I 19
			amt = BUFSIZ;
E 19
			if (i + amt > size)
				amt = size - i;
I 19
			count += amt;
E 19
			do {
D 19
				int j = read(rem, cp, amt);

E 19
I 19
				j = read(rem, cp, amt);
E 19
D 24
				if (j <= 0)
E 24
I 24
				if (j <= 0) {
					if (j == 0)
					    error("rcp: dropped connection");
					else
					    error("rcp: %s\n",
						sys_errlist[errno]);
E 24
					exit(1);
I 24
				}
E 24
				amt -= j;
				cp += j;
			} while (amt > 0);
D 19
			amt = BUFSIZ;
			if (i + amt > size)
				amt = size - i;
			if (wrerr == 0 && write(of, buf, amt) != amt)
				wrerr++;
E 19
I 19
			if (count == bp->cnt) {
				if (wrerr == 0 &&
				    write(of, bp->buf, count) != count)
					wrerr++;
				count = 0;
				cp = bp->buf;
			}
E 19
		}
I 19
		if (count != 0 && wrerr == 0 &&
		    write(of, bp->buf, count) != count)
			wrerr++;
I 27
		if (ftruncate(of, size))
			error("rcp: can't truncate %s: %s\n",
			    nambuf, sys_errlist[errno]);
E 27
E 19
		(void) close(of);
		(void) response();
I 21
		if (setimes) {
			setimes = 0;
			if (utimes(nambuf, tv) < 0)
				error("rcp: can't set times on %s: %s\n",
				    nambuf, sys_errlist[errno]);
		}				   
E 21
		if (wrerr)
D 21
			error("rcp: %s: %s\n", cp, sys_errlist[errno]);
E 21
I 21
			error("rcp: %s: %s\n", nambuf, sys_errlist[errno]);
E 21
		else
			ga();
	}
screwup:
	error("rcp: protocol screwup: %s\n", whopp);
	exit(1);
I 19
}

struct buffer *
allocbuf(bp, fd, blksize)
	struct buffer *bp;
	int fd, blksize;
{
	struct stat stb;
	int size;

	if (fstat(fd, &stb) < 0) {
		error("rcp: fstat: %s\n", sys_errlist[errno]);
		return ((struct buffer *)-1);
	}
	size = roundup(stb.st_blksize, blksize);
	if (size == 0)
		size = blksize;
	if (bp->cnt < size) {
		if (bp->buf != 0)
			free(bp->buf);
D 21
		bp->buf = (char *)malloc(size);
E 21
I 21
		bp->buf = (char *)malloc((unsigned) size);
E 21
		if (bp->buf == 0) {
			error("rcp: malloc: out of memory\n");
			return ((struct buffer *)-1);
		}
	}
	bp->cnt = size;
	return (bp);
E 19
}

D 21
/*VARARGS*/
E 21
I 21
/*VARARGS1*/
E 21
error(fmt, a1, a2, a3, a4, a5)
	char *fmt;
	int a1, a2, a3, a4, a5;
{
	char buf[BUFSIZ], *cp = buf;

	errs++;
	*cp++ = 1;
	(void) sprintf(cp, fmt, a1, a2, a3, a4, a5);
	(void) write(rem, buf, strlen(buf));
	if (iamremote == 0)
		(void) write(2, buf+1, strlen(buf+1));
I 27
}

usage()
{
	fputs("usage: rcp [-p] f1 f2; or: rcp [-rp] f1 ... fn d2\n", stderr);
	exit(1);
E 27
D 15
}

D 13
mkdir(name, mode)
	char *name;
	int mode;
E 13
I 13
makedir(name, mode)
	register char *name;
	register int mode;
E 13
{
D 13
	char *argv[4];
	int pid, rc;
E 13
I 13
	register int _errno;
E 13

D 13
	argv[0] = "mkdir";
	argv[1] = name;
	argv[2] = 0;
	pid = fork();
	if (pid < 0) {
		perror("cp");
		return (1);
E 13
I 13
	if (mkdir(name, mode) < 0 || chown(name, getuid(), -1) < 0) {
		_errno = errno;
		rmdir(name);
		errno = _errno;
		return (-1);
E 13
	}
D 13
	if (pid) {
		while (wait(&rc) != pid)
			continue;
		if (rc == 0)
			if (chmod(name, mode) < 0) {
				perror(name);
				rc = 1;
			}
		return (rc);
	}
	(void) setuid(getuid());
	execv("/bin/mkdir", argv);
	execv("/usr/bin/mkdir", argv);
	perror("mkdir");
	_exit(1);
	/*NOTREACHED*/
E 13
I 13

	return (0);
E 15
E 13
}
I 2
D 11

E 11
E 2
E 1
