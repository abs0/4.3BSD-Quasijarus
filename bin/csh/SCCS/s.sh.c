h33684
s 00001/00001/00942
d D 5.6 88/05/19 15:38:34 bostic 32 31
c install C version of _doprnt
e
s 00004/00000/00939
d D 5.5 88/01/20 11:55:40 bostic 31 30
c Bug involving csh and the "source" command; 4.3BSD/bin/115
e
s 00005/00004/00934
d D 5.4 87/06/25 09:15:07 bostic 30 29
c csh long/int mismatches; bug report 4.3BSD/bin/45
e
s 00003/00000/00935
d D 5.3 86/03/29 07:16:36 lepreau 29 28
c lint
e
s 00003/00003/00932
d D 5.2 85/06/06 13:10:57 edward 28 27
c cleaning up after bozos
e
s 00008/00002/00927
d D 5.1 85/06/04 10:54:40 dist 27 26
c Add copyright
e
s 00001/00001/00928
d D 4.23 85/03/24 17:09:33 edward 26 25
c check for set group id as well as setuid
e
s 00001/00001/00928
d D 4.22 85/03/19 17:54:38 mckusick 25 24
c load history after sourcing .login file in case .login sets history variable
e
s 00001/00003/00928
d D 4.21 85/01/16 10:29:03 edward 24 23
c can't use environ SHELL as variable shell
e
s 00072/00087/00859
d D 4.20 84/12/13 14:41:53 edward 23 22
c performance
e
s 00013/00007/00933
d D 4.19 84/09/07 15:25:00 ralph 22 21
c added -b flag to force next arg as shell input file for setuid scripts.
e
s 00023/00027/00917
d D 4.18 84/08/31 09:30:33 ralph 21 20
c use new signal calls instead of compatibility routines.
e
s 00006/00002/00938
d D 4.17 84/07/06 22:42:12 sam 20 19
c fix up profiling; correct last hack
e
s 00020/00020/00920
d D 4.16 84/07/06 21:13:45 sam 19 18
c restore prior formatting
e
s 00001/00001/00939
d D 4.15 84/06/06 16:51:07 layer 18 17
c create .history with mode 666 not 777 (should use umask, too, but
c it doesn't)
e
s 00001/00001/00939
d D 4.14 83/11/02 14:52:35 layer 17 16
c is called with -c, then don't print the prompt
e
s 00023/00015/00917
d D 4.13 83/11/02 13:45:33 layer 16 14
c move the prompt printing stuff to a function
c (for the filename completion stuff)
e
s 00001/00001/00931
d R 4.13 83/06/27 22:01:11 sam 15 14
c move loadhist down so setting history in .login works
e
s 00015/00015/00917
d D 4.12 83/06/11 16:48:49 sam 14 13
c different approach, try signal compatibility package
e
s 00018/00017/00914
d D 4.11 83/06/10 23:58:43 sam 13 12
c new signals; no libjobs; still loses SIGINT by getting it masked 
c sometimes, but we check it in before we lose something
e
s 00001/00001/00930
d D 4.10 83/02/03 09:12:39 sam 12 11
c use high precision time calls
e
s 00003/00001/00928
d D 4.9 82/06/06 13:06:15 mckusick 11 10
c fix to allow shell scripts to run in background
e
s 00001/00001/00928
d D 4.8 82/03/28 18:24:45 wnj 10 9
c signal handling bug fix
e
s 00015/00011/00914
d D 4.7 82/02/17 14:33:00 mckusic 9 8
c only save history if "savehist" is specified
e
s 00004/00001/00921
d D 4.6 82/02/12 15:28:50 mckusic 8 7
c save history if exceed cpu time or file size limits in shell
e
s 00002/00001/00920
d D 4.5 81/11/22 15:38:06 mckusic 7 6
c fix bug with HIST not being reset correctly
e
s 00055/00016/00866
d D 4.4 81/11/19 21:03:32 mckusic 6 3
c add ``history -h >file'' and ``source -h file'' to 
c implement history save and restore.
e
s 00034/00012/00870
d R 4.4 81/08/21 00:36:03 mckusic 5 3
c put in history save and restore
e
s 00033/00012/00870
d R 4.4 81/08/20 23:47:32 mckusic 4 3
c put in history save and restore
e
s 00024/00004/00858
d D 4.3 81/08/18 17:00:18 mckusic 3 2
c save history in ~/.history at logout and restore at login
e
s 00007/00001/00855
d D 4.2 81/03/11 18:51:44 wnj 2 1
c minor bug fixes
e
s 00856/00000/00000
d D 4.1 80/10/09 12:40:21 bill 1 0
c date and time created 80/10/09 12:40:21 by bill
e
u
U
t
T
I 27
/*
 * Copyright (c) 1980 Regents of the University of California.
D 28
 * All rights reserved.  The Berkeley software License Agreement
E 28
I 28
 * All rights reserved.  The Berkeley Software License Agreement
E 28
 * specifies the terms and conditions for redistribution.
 */

E 27
I 1
D 23
static	char *sccsid = "%Z%%M% %I% %G%";
E 23
I 23
#ifndef lint
D 27
static	char *sccsid = "%W% (Berkeley) %G%";
#endif
E 27
I 27
D 28
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 28
I 28
static char *sccsid = "%W% (Berkeley) %G%";
#endif
E 28
E 27
E 23

#include "sh.h"
#include <sys/ioctl.h>
/*
 * C Shell
 *
 * Bill Joy, UC Berkeley, California, USA
 * October 1978, May 1980
 *
 * Jim Kulp, IIASA, Laxenburg, Austria
 * April 1980
 */

char	*pathlist[] =	{ ".", "/usr/ucb", "/bin", "/usr/bin", 0 };
I 3
D 6
char	*dumphist[] =	{ "history", "-c", "+1000" };
E 6
I 6
D 9
char	*dumphist[] =	{ "history", "-h", 0 };
E 9
I 9
char	*dumphist[] =	{ "history", "-h", 0, 0 };
E 9
char	*loadhist[] =	{ "source", "-h", "~/.history", 0 };
E 6
E 3
char	HIST = '!';
char	HISTSUB = '^';
bool	nofile;
bool	reenter;
bool	nverbose;
bool	nexececho;
bool	quitit;
bool	fast;
I 22
bool	batch;
E 22
bool	prompt = 1;
I 3
bool	enterhist = 0;
E 3

I 29
extern	gid_t getegid(), getgid();
extern	uid_t geteuid(), getuid();

E 29
main(c, av)
	int c;
	char **av;
{
	register char **v, *cp;
	register int f;
I 21
	struct sigvec osv;
E 21

	settimes();			/* Immed. estab. timing base */
	v = av;
	if (eq(v[0], "a.out"))		/* A.out's are quittable */
		quitit = 1;
	uid = getuid();
D 21
	loginsh = **v == '-';
E 21
I 21
	loginsh = **v == '-' && c == 1;
E 21
	if (loginsh)
D 23
		time(&chktim);
E 23
I 23
		(void) time(&chktim);
E 23

	/*
	 * Move the descriptors to safe places.
	 * The variable didfds is 0 while we have only FSH* to work with.
	 * When didfds is true, we have 0,1,2 and prefer to use these.
	 */
	initdesc();

	/*
	 * Initialize the shell variables.
	 * ARGV and PROMPT are initialized later.
	 * STATUS is also munged in several places.
	 * CHILD is munged when forking/waiting
	 */

	set("status", "0");
	dinit(cp = getenv("HOME"));	/* dinit thinks that HOME == cwd in a
					 * login shell */
	if (cp == NOSTR)
		fast++;			/* No home -> can't read scripts */
	else
		set("home", savestr(cp));
	/*
	 * Grab other useful things from the environment.
	 * Should we grab everything??
	 */
	if ((cp = getenv("USER")) != NOSTR)
		set("user", savestr(cp));
	if ((cp = getenv("TERM")) != NOSTR)
		set("term", savestr(cp));
	/*
	 * Re-initialize path if set in environment
	 */
	if ((cp = getenv("PATH")) == NOSTR)
		set1("path", saveblk(pathlist), &shvhed);
D 23
	else {
		register unsigned i = 0;
		register char *dp;
		register char **pv;
E 23
I 23
	else
		importpath(cp);
D 24
	if ((cp = getenv("SHELL")) == NOSTR)
		cp = SHELLPATH;
	set("shell", savestr(cp));
E 24
I 24
	set("shell", SHELLPATH);
E 24
E 23

D 23
		for (dp = cp; *dp; dp++)
			if (*dp == ':')
				i++;
		pv = (char **)calloc(i+2, sizeof (char **));
		for (dp = cp, i = 0; ;)
			if (*dp == ':') {
				*dp = 0;
				pv[i++] = savestr(*cp ? cp : ".");
				*dp++ = ':';
				cp = dp;
			} else if (*dp++ == 0) {
				pv[i++] = savestr(*cp ? cp : ".");
				break;
			}
		pv[i] = 0;
		set1("path", pv, &shvhed);
	}
	set("shell", SHELLPATH);

E 23
	doldol = putn(getpid());		/* For $$ */
	shtemp = strspl("/tmp/sh", doldol);	/* For << */

	/*
	 * Record the interrupt states from the parent process.
	 * If the parent is non-interruptible our hand must be forced
	 * or we (and our children) won't be either.
	 * Our children inherit termination from our parent.
	 * We catch it only if we are the login shell.
	 */
D 21
	parintr = signal(SIGINT, SIG_IGN);	/* parents interruptibility */
D 13
	sigset(SIGINT, parintr);			/* ... restore */
E 13
I 13
D 14
	signal(SIGINT, parintr);			/* ... restore */
E 14
I 14
	sigset(SIGINT, parintr);			/* ... restore */
E 14
E 13
	parterm = signal(SIGTERM, SIG_IGN);	/* parents terminability */
	signal(SIGTERM, parterm);			/* ... restore */
E 21
I 21
D 23
	sigvec(SIGINT, 0, &osv);		/* parents interruptibility */
E 23
I 23
		/* parents interruptibility */
	(void) sigvec(SIGINT, (struct sigvec *)0, &osv);
E 23
	parintr = osv.sv_handler;
D 23
	sigvec(SIGTERM, 0, &osv);		/* parents terminability */
E 23
I 23
		/* parents terminability */
	(void) sigvec(SIGTERM, (struct sigvec *)0, &osv);
E 23
	parterm = osv.sv_handler;
E 21
I 6
D 8
	if (loginsh)
E 8
I 8
	if (loginsh) {
E 8
D 23
		signal(SIGHUP, phup);		/* exit processing on HUP */
I 8
		signal(SIGXCPU, phup);		/* ...and on XCPU */
		signal(SIGXFSZ, phup);		/* ...and on XFSZ */
E 23
I 23
		(void) signal(SIGHUP, phup);	/* exit processing on HUP */
		(void) signal(SIGXCPU, phup);	/* ...and on XCPU */
		(void) signal(SIGXFSZ, phup);	/* ...and on XFSZ */
E 23
	}
E 8
E 6

	/*
	 * Process the arguments.
	 *
	 * Note that processing of -v/-x is actually delayed till after
	 * script processing.
D 22
	 *
	 * We set the first character of our name to be '-' if we are
	 * a shell running interruptible commands.  Many programs which
	 * examine ps'es use this to filter such shells out.
E 22
	 */
	c--, v++;
D 22
	while (c > 0 && (cp = v[0])[0] == '-') {
I 21
		cp++;
E 22
I 22
	while (c > 0 && (cp = v[0])[0] == '-' && *++cp != '\0' && !batch) {
E 22
E 21
		do switch (*cp++) {

I 22
		case 'b':		/* -b	Next arg is input file */
			batch++;
			break;

E 22
D 21
		case 0:			/* -	Interruptible, no prompt */
			prompt = 0;
			setintr++;
			nofile++;
			break;

E 21
		case 'c':		/* -c	Command input from arg */
			if (c == 1)
				exit(0);
			c--, v++;
			arginp = v[0];
			prompt = 0;
			nofile++;
			break;

		case 'e':		/* -e	Exit on any error */
			exiterr++;
			break;

		case 'f':		/* -f	Fast start */
			fast++;
			break;

		case 'i':		/* -i	Interactive, even if !intty */
			intact++;
			nofile++;
			break;

		case 'n':		/* -n	Don't execute */
			noexec++;
			break;

		case 'q':		/* -q	(Undoc'd) ... die on quit */
			quitit = 1;
			break;

		case 's':		/* -s	Read from std input */
			nofile++;
			break;

		case 't':		/* -t	Read one line from input */
			onelflg = 2;
			prompt = 0;
			nofile++;
			break;

		case 'v':		/* -v	Echo hist expanded input */
			nverbose = 1;			/* ... later */
			break;

		case 'x':		/* -x	Echo just before execution */
			nexececho = 1;			/* ... later */
			break;

		case 'V':		/* -V	Echo hist expanded input */
			setNS("verbose");		/* NOW! */
			break;

		case 'X':		/* -X	Echo just before execution */
			setNS("echo");			/* NOW! */
			break;

		} while (*cp);
		v++, c--;
	}
I 22
D 23
argsdone:
E 23
E 22

	if (quitit)			/* With all due haste, for debugging */
D 23
		signal(SIGQUIT, SIG_DFL);
E 23
I 23
		(void) signal(SIGQUIT, SIG_DFL);
E 23

	/*
D 22
	 * Unless prevented by -, -c, -i, -s, or -t, if there
E 22
I 22
	 * Unless prevented by -c, -i, -s, or -t, if there
E 22
	 * are remaining arguments the first of them is the name
	 * of a shell file from which to read commands.
	 */
	if (nofile == 0 && c > 0) {
		nofile = open(v[0], 0);
		if (nofile < 0) {
			child++;		/* So this ... */
			Perror(v[0]);		/* ... doesn't return */
		}
		file = v[0];
		SHIN = dmove(nofile, FSHIN);	/* Replace FSHIN */
I 23
		(void) ioctl(SHIN, FIOCLEX, (char *)0);
E 23
		prompt = 0;
		c--, v++;
I 22
	}
D 23
	if (uid != geteuid() && !batch) {
E 23
I 23
D 26
	if (!batch && uid != geteuid()) {
E 26
I 26
	if (!batch && (uid != geteuid() || getgid() != getegid())) {
E 26
E 23
		errno = EACCES;
		child++;			/* So this ... */
		Perror("csh");			/* ... doesn't return */
E 22
	}
	/*
	 * Consider input a tty if it really is or we are interactive.
	 */
	intty = intact || isatty(SHIN);
	/*
	 * Decide whether we should play with signals or not.
	 * If we are explicitly told (via -i, or -) or we are a login
	 * shell (arg0 starts with -) or the input and output are both
	 * the ttys("csh", or "csh</dev/ttyx>/dev/ttyx")
	 * Note that in only the login shell is it likely that parent
	 * may have set signals to be ignored
	 */
D 10
	if (loginsh || intact || intty && isatty(SHOUT))
E 10
I 10
D 11
	if (loginsh || intact || intty && isatty(SHOUT) || parintr == SIG_DFL)
E 11
I 11
	if (loginsh || intact || intty && isatty(SHOUT))
E 11
E 10
		setintr = 1;
#ifdef TELL
	settell();
#endif
	/*
	 * Save the remaining arguments in argv.
	 */
	setq("argv", v, &shvhed);

	/*
	 * Set up the prompt.
	 */
	if (prompt)
		set("prompt", uid == 0 ? "# " : "% ");

	/*
	 * If we are an interactive shell, then start fiddling
	 * with the signals; this is a tricky game.
	 */
	shpgrp = getpgrp(0);
	opgrp = tpgrp = -1;
	oldisc = -1;
	if (setintr) {
		**av = '-';
		if (!quitit)		/* Wary! */
D 23
			signal(SIGQUIT, SIG_IGN);
D 13
		sigset(SIGINT, pintr);
		sighold(SIGINT);
E 13
I 13
D 14
		sigblock(mask(SIGINT));
		signal(SIGINT, pintr);
E 14
I 14
D 21
		sigset(SIGINT, pintr);
		sighold(SIGINT);
E 21
I 21
		signal(SIGINT, pintr);
		sigblock(sigmask(SIGINT));
E 21
E 14
E 13
		signal(SIGTERM, SIG_IGN);
E 23
I 23
			(void) signal(SIGQUIT, SIG_IGN);
		(void) signal(SIGINT, pintr);
		(void) sigblock(sigmask(SIGINT));
		(void) signal(SIGTERM, SIG_IGN);
E 23
		if (quitit == 0 && arginp == 0) {
D 23
			signal(SIGTSTP, SIG_IGN);
			signal(SIGTTIN, SIG_IGN);
			signal(SIGTTOU, SIG_IGN);
E 23
I 23
			(void) signal(SIGTSTP, SIG_IGN);
			(void) signal(SIGTTIN, SIG_IGN);
			(void) signal(SIGTTOU, SIG_IGN);
E 23
			/*
			 * Wait till in foreground, in case someone
			 * stupidly runs
			 *	csh &
			 * dont want to try to grab away the tty.
			 */
			if (isatty(FSHDIAG))
				f = FSHDIAG;
			else if (isatty(FSHOUT))
				f = FSHOUT;
			else if (isatty(OLDSTD))
				f = OLDSTD;
			else
				f = -1;
retry:
D 23
			if (ioctl(f, TIOCGPGRP, &tpgrp) == 0 && tpgrp != -1) {
E 23
I 23
			if (ioctl(f, TIOCGPGRP, (char *)&tpgrp) == 0 &&
			    tpgrp != -1) {
E 23
				int ldisc;
				if (tpgrp != shpgrp) {
D 13
					int old = sigsys(SIGTTIN, SIG_DFL);
E 13
I 13
D 14
					int (*old)() = signal(SIGTTIN, SIG_DFL);
E 14
I 14
D 21
					int (*old)() = sigsys(SIGTTIN, SIG_DFL);
E 21
I 21
					int (*old)() = signal(SIGTTIN, SIG_DFL);
E 21
E 14
E 13
D 23
					kill(0, SIGTTIN);
D 13
					sigsys(SIGTTIN, old);
E 13
I 13
D 14
					signal(SIGTTIN, old);
E 14
I 14
D 21
					sigsys(SIGTTIN, old);
E 21
I 21
					signal(SIGTTIN, old);
E 23
I 23
					(void) kill(0, SIGTTIN);
					(void) signal(SIGTTIN, old);
E 23
E 21
E 14
E 13
					goto retry;
				}
D 23
				if (ioctl(f, TIOCGETD, &oldisc) != 0) 
E 23
I 23
				if (ioctl(f, TIOCGETD, (char *)&oldisc) != 0) 
E 23
					goto notty;
				if (oldisc != NTTYDISC) {
D 6
			printf("Switching to new tty driver...\n");
E 6
I 6
#ifdef DEBUG
					printf("Switching to new tty driver...\n");
#endif DEBUG
E 6
					ldisc = NTTYDISC;
D 23
					ioctl(f, TIOCSETD, &ldisc);
E 23
I 23
					(void) ioctl(f, TIOCSETD,
						(char *)&ldisc);
E 23
				} else
					oldisc = -1;
				opgrp = shpgrp;
				shpgrp = getpid();
				tpgrp = shpgrp;
D 23
				ioctl(f, TIOCSPGRP, &shpgrp);
				setpgrp(0, shpgrp);
				dcopy(f, FSHTTY);
				ioctl(FSHTTY, FIOCLEX, 0);
E 23
I 23
				(void) ioctl(f, TIOCSPGRP, (char *)&shpgrp);
				(void) setpgrp(0, shpgrp);
				(void) ioctl(dcopy(f, FSHTTY), FIOCLEX,
					(char *)0);
E 23
			} else {
notty:
  printf("Warning: no access to tty; thus no job control in this shell...\n");
				tpgrp = -1;
			}
		}
	}
I 11
	if (setintr == 0 && parintr == SIG_DFL)
		setintr++;
E 11
D 13
	sigset(SIGCHLD, pchild);		/* while signals not ready */
E 13
I 13
D 14
	signal(SIGCHLD, pchild);		/* while signals not ready */
E 14
I 14
D 21
	sigset(SIGCHLD, pchild);		/* while signals not ready */
E 21
I 21
D 23
	signal(SIGCHLD, pchild);	/* while signals not ready */
E 23
I 23
	(void) signal(SIGCHLD, pchild);	/* while signals not ready */
E 23
E 21
E 14
E 13

	/*
	 * Set an exit here in case of an interrupt or error reading
	 * the shell start-up scripts.
	 */
	setexit();
	haderr = 0;		/* In case second time through */
	if (!fast && reenter == 0) {
		reenter++;
		/* Will have value("home") here because set fast if don't */
		srccat(value("home"), "/.cshrc");
D 23
		if (!fast && !arginp && !onelflg)
E 23
I 23
		if (!fast && !arginp && !onelflg && !havhash)
E 23
			dohash();
I 6
D 25
		dosource(loadhist);
E 25
E 6
		if (loginsh) {
D 3
			int ldisc;
E 3
			srccat(value("home"), "/.login");
I 3
D 6
			enterhist = 1;
			srccat(value("home"), "/.history");
			enterhist = 0;
E 6
E 3
		}
I 25
		dosource(loadhist);
E 25
	}

	/*
	 * Now are ready for the -v and -x flags
	 */
	if (nverbose)
		setNS("verbose");
	if (nexececho)
		setNS("echo");

	/*
	 * All the rest of the world is inside this call.
	 * The argument to process indicates whether it should
	 * catch "error unwinds".  Thus if we are a interactive shell
	 * our call here will never return by being blown past on an error.
	 */
	process(setintr);

	/*
	 * Mop-up.
	 */
	if (loginsh) {
		printf("logout\n");
D 23
		close(SHIN);
E 23
I 23
		(void) close(SHIN);
E 23
		child++;
		goodbye();
	}
I 6
	rechist();
E 6
	exitstat();
}

untty()
{

	if (tpgrp > 0) {
D 23
		setpgrp(0, opgrp);
		ioctl(FSHTTY, TIOCSPGRP, &opgrp);
E 23
I 23
		(void) setpgrp(0, opgrp);
		(void) ioctl(FSHTTY, TIOCSPGRP, (char *)&opgrp);
E 23
		if (oldisc != -1 && oldisc != NTTYDISC) {
I 6
#ifdef DEBUG
E 6
			printf("\nReverting to old tty driver...\n");
I 6
#endif DEBUG
E 6
D 23
			ioctl(FSHTTY, TIOCSETD, &oldisc);
E 23
I 23
			(void) ioctl(FSHTTY, TIOCSETD, (char *)&oldisc);
E 23
		}
	}
}

importpath(cp)
D 13
char *cp;
E 13
I 13
	char *cp;
E 13
{
	register int i = 0;
	register char *dp;
	register char **pv;
	int c;
	static char dot[2] = {'.', 0};

	for (dp = cp; *dp; dp++)
		if (*dp == ':')
			i++;
	/*
	 * i+2 where i is the number of colons in the path.
	 * There are i+1 directories in the path plus we need
	 * room for a zero terminator.
	 */
D 23
	pv = (char **) calloc(i+2, sizeof (char **));
E 23
I 23
	pv = (char **) calloc((unsigned) (i + 2), sizeof (char **));
E 23
	dp = cp;
	i = 0;
	if (*dp)
	for (;;) {
		if ((c = *dp) == ':' || c == 0) {
			*dp = 0;
			pv[i++] = savestr(*cp ? cp : dot);
			if (c) {
				cp = dp + 1;
				*dp = ':';
			} else
				break;
		}
		dp++;
	}
	pv[i] = 0;
	set1("path", pv, &shvhed);
}

/*
 * Source to the file which is the catenation of the argument names.
 */
srccat(cp, dp)
	char *cp, *dp;
{
	register char *ep = strspl(cp, dp);
	register int unit = dmove(open(ep, 0), -1);

D 23
	/* ioctl(unit, FIOCLEX, NULL); */
E 23
I 23
	(void) ioctl(unit, FIOCLEX, (char *)0);
E 23
	xfree(ep);
#ifdef INGRES
D 6
	srcunit(unit, 0);
E 6
I 6
	srcunit(unit, 0, 0);
E 6
#else
D 6
	srcunit(unit, 1);
E 6
I 6
	srcunit(unit, 1, 0);
E 6
#endif
}

/*
 * Source to a unit.  If onlyown it must be our file or our group or
 * we don't chance it.	This occurs on ".cshrc"s and the like.
 */
I 31
int	insource;
static
E 31
D 6
srcunit(unit, onlyown)
E 6
I 6
srcunit(unit, onlyown, hflg)
E 6
	register int unit;
	bool onlyown;
I 6
	bool hflg;
E 6
{
	/* We have to push down a lot of state here */
	/* All this could go into a structure */
	int oSHIN = -1, oldintty = intty;
	struct whyle *oldwhyl = whyles;
	char *ogointr = gointr, *oarginp = arginp;
	char *oevalp = evalp, **oevalvec = evalvec;
	int oonelflg = onelflg;
I 6
	bool oenterhist = enterhist;
	char OHIST = HIST;
E 6
#ifdef TELL
	bool otell = cantell;
#endif
	struct Bin saveB;

	/* The (few) real local variables */
	jmp_buf oldexit;
D 21
	int reenter;
E 21
I 21
D 30
	int reenter, omask;
E 30
I 30
	int reenter;
	long omask;
E 30
E 21

	if (unit < 0)
		return;
	if (didfds)
		donefds();
	if (onlyown) {
		struct stat stb;

D 13
		if (fstat(unit, &stb) < 0 || (stb.st_uid != uid && stb.st_gid != getgid())) {
E 13
I 13
		if (fstat(unit, &stb) < 0 ||
		    (stb.st_uid != uid && stb.st_gid != getgid())) {
E 13
D 23
			close(unit);
E 23
I 23
			(void) close(unit);
E 23
			return;
		}
	}

	/*
	 * There is a critical section here while we are pushing down the
	 * input stream since we have stuff in different structures.
	 * If we weren't careful an interrupt could corrupt SHIN's Bin
	 * structure and kill the shell.
	 *
	 * We could avoid the critical region by grouping all the stuff
	 * in a single structure and pointing at it to move it all at
	 * once.  This is less efficient globally on many variable references
	 * however.
	 */
I 31
	insource = 1;
E 31
	getexit(oldexit);
	reenter = 0;
	if (setintr)
D 13
		sighold(SIGINT);
E 13
I 13
D 14
		(void) sigblock(mask(SIGINT));
E 14
I 14
D 21
		sighold(SIGINT);
E 21
I 21
		omask = sigblock(sigmask(SIGINT));
E 21
E 14
E 13
	setexit();
	reenter++;
	if (reenter == 1) {
		/* Setup the new values of the state stuff saved above */
		copy((char *)&saveB, (char *)&B, sizeof saveB);
		fbuf = (char **) 0;
		fseekp = feobp = fblocks = 0;
		oSHIN = SHIN, SHIN = unit, arginp = 0, onelflg = 0;
		intty = isatty(SHIN), whyles = 0, gointr = 0;
		evalvec = 0; evalp = 0;
I 6
		enterhist = hflg;
		if (enterhist)
			HIST = '\0';
E 6
		/*
		 * Now if we are allowing commands to be interrupted,
		 * we let ourselves be interrupted.
		 */
		if (setintr)
D 13
			sigrelse(SIGINT);
E 13
I 13
D 14
			(void) sigrelse(mask(SIGINT));
E 14
I 14
D 21
			sigrelse(SIGINT);
E 21
I 21
D 23
			sigsetmask(omask);
E 23
I 23
			(void) sigsetmask(omask);
E 23
E 21
E 14
E 13
#ifdef TELL
		settell();
#endif
		process(0);		/* 0 -> blow away on errors */
	}
	if (setintr)
D 13
		sigrelse(SIGINT);
E 13
I 13
D 14
		(void) sigrelse(mask(SIGINT));
E 14
I 14
D 21
		sigrelse(SIGINT);
E 21
I 21
D 23
		sigsetmask(omask);
E 23
I 23
		(void) sigsetmask(omask);
E 23
E 21
E 14
E 13
	if (oSHIN >= 0) {
		register int i;

		/* We made it to the new state... free up its storage */
		/* This code could get run twice but xfree doesn't care */
		for (i = 0; i < fblocks; i++)
			xfree(fbuf[i]);
		xfree((char *)fbuf);

		/* Reset input arena */
		copy((char *)&B, (char *)&saveB, sizeof B);

D 23
		close(SHIN), SHIN = oSHIN;
E 23
I 23
		(void) close(SHIN), SHIN = oSHIN;
E 23
		arginp = oarginp, onelflg = oonelflg;
		evalp = oevalp, evalvec = oevalvec;
		intty = oldintty, whyles = oldwhyl, gointr = ogointr;
I 7
		if (enterhist)
			HIST = OHIST;
E 7
I 6
		enterhist = oenterhist;
D 7
		HIST = OHIST;
E 7
E 6
#ifdef TELL
		cantell = otell;
#endif
	}

	resexit(oldexit);
	/*
	 * If process reset() (effectively an unwind) then
	 * we must also unwind.
	 */
	if (reenter >= 2)
		error(NOSTR);
I 31
	insource = 0;
E 31
}

D 6
goodbye()
E 6
I 6
rechist()
E 6
{
I 3
	char buf[BUFSIZ];
	int fp, ftmp, oldidfds;
E 3

D 6
	if (loginsh) {
E 6
I 6
	if (!fast) {
I 9
		if (value("savehist")[0] == '\0')
			return;
E 9
E 6
I 3
D 23
		strcpy(buf, value("home"));
		strcat(buf, "/.history");
E 23
I 23
		(void) strcpy(buf, value("home"));
		(void) strcat(buf, "/.history");
E 23
D 18
		fp = creat(buf, 0777);
E 18
I 18
		fp = creat(buf, 0666);
E 18
D 9
		if (fp != -1) {
			oldidfds = didfds;
			didfds = 0;
			ftmp = SHOUT;
			SHOUT = fp;
			dohist(dumphist);
			close(fp);
			SHOUT = ftmp;
			didfds = oldidfds;
		}
E 9
I 9
		if (fp == -1)
			return;
		oldidfds = didfds;
		didfds = 0;
		ftmp = SHOUT;
		SHOUT = fp;
D 23
		strcpy(buf, value("savehist"));
E 23
I 23
		(void) strcpy(buf, value("savehist"));
E 23
		dumphist[2] = buf;
		dohist(dumphist);
D 23
		close(fp);
E 23
I 23
		(void) close(fp);
E 23
		SHOUT = ftmp;
		didfds = oldidfds;
E 9
I 6
	}
}

goodbye()
{
	if (loginsh) {
E 6
E 3
D 23
		signal(SIGQUIT, SIG_IGN);
D 13
		sigset(SIGINT, SIG_IGN);
E 13
I 13
D 14
		signal(SIGINT, SIG_IGN);
E 14
I 14
D 21
		sigset(SIGINT, SIG_IGN);
E 21
I 21
		signal(SIGINT, SIG_IGN);
E 21
E 14
E 13
		signal(SIGTERM, SIG_IGN);
E 23
I 23
		(void) signal(SIGQUIT, SIG_IGN);
		(void) signal(SIGINT, SIG_IGN);
		(void) signal(SIGTERM, SIG_IGN);
E 23
		setintr = 0;		/* No interrupts after "logout" */
		if (adrof("home"))
			srccat(value("home"), "/.logout");
	}
I 6
	rechist();
E 6
	exitstat();
}

exitstat()
{

I 23
#ifdef PROF
	monitor(0);
#endif
E 23
	/*
	 * Note that if STATUS is corrupted (i.e. getn bombs)
	 * then error will exit directly because we poke child here.
	 * Otherwise we might continue unwarrantedly (sic).
	 */
	child++;
	exit(getn(value("status")));
}

I 6
/*
 * in the event of a HUP we want to save the history
 */
phup()
{
	rechist();
	exit(1);
}

E 6
char	*jobargv[2] = { "jobs", 0 };
/*
 * Catch an interrupt, e.g. during lexical input.
 * If we are an interactive shell, we reset the interrupt catch
 * immediately.  In any case we drain the shell output,
 * and finally go through the normal error mechanism, which
 * gets a chance to make the shell go away.
 */
pintr()
{
I 2
	pintr1(1);
}

pintr1(wantnl)
	bool wantnl;
{
E 2
	register char **v;
I 21
D 30
	int omask;
E 30
I 30
	long omask;
E 30
E 21

I 21
D 30
	omask = sigblock(0);
E 30
I 30
	omask = sigblock(0L);
E 30
E 21
	if (setintr) {
D 13
		sigrelse(SIGINT);
E 13
I 13
D 14
		(void) sigrelse(mask(SIGINT));
E 14
I 14
D 21
		sigrelse(SIGINT);
E 21
I 21
D 23
		sigsetmask(omask & ~sigmask(SIGINT));
E 23
I 23
		(void) sigsetmask(omask & ~sigmask(SIGINT));
E 23
E 21
E 14
E 13
		if (pjobs) {
			pjobs = 0;
			printf("\n");
			dojobs(jobargv);
			bferr("Interrupted");
		}
	}
D 21
	if (setintr)
D 13
		sighold(SIGINT);
	sigrelse(SIGCHLD);
E 13
I 13
D 14
		sigblock(mask(SIGINT));
	sigrelse(mask(SIGCHLD));
E 14
I 14
		sighold(SIGINT);
	sigrelse(SIGCHLD);
E 21
I 21
D 23
	sigsetmask(omask & ~sigmask(SIGCHLD));
E 23
I 23
	(void) sigsetmask(omask & ~sigmask(SIGCHLD));
E 23
E 21
E 14
E 13
	draino();

	/*
	 * If we have an active "onintr" then we search for the label.
	 * Note that if one does "onintr -" then we shan't be interruptible
	 * so we needn't worry about that here.
	 */
	if (gointr) {
		search(ZGOTO, 0, gointr);
		timflg = 0;
		if (v = pargv)
			pargv = 0, blkfree(v);
		if (v = gargv)
			gargv = 0, blkfree(v);
		reset();
D 2
	} else if (intty)
E 2
I 2
	} else if (intty && wantnl)
E 2
		printf("\n");		/* Some like this, others don't */
	error(NOSTR);
}

/*
 * Process is the main driving routine for the shell.
 * It runs all command processing, except for those within { ... }
 * in expressions (which is run by a routine evalav in sh.exp.c which
 * is a stripped down process), and `...` evaluation which is run
 * also by a subset of this code in sh.glob.c in the routine backeval.
 *
 * The code here is a little strange because part of it is interruptible
 * and hence freeing of structures appears to occur when none is necessary
 * if this is ignored.
 *
 * Note that if catch is not set then we will unwind on any error.
 * If an end-of-file occurs, we return.
 */
process(catch)
	bool catch;
{
D 23
	register char *cp;
E 23
	jmp_buf osetexit;
D 23
	struct command *t;
E 23
I 23
	register struct command *t;
E 23

	getexit(osetexit);
	for (;;) {
		pendjob();
		paraml.next = paraml.prev = &paraml;
		paraml.word = "";
		t = 0;
		setexit();
D 3
		justpr = 0;			/* A chance to execute */
E 3
I 3
		justpr = enterhist;	/* execute if not entering history */
E 3

		/*
		 * Interruptible during interactive reads
		 */
		if (setintr)
D 13
			sigrelse(SIGINT);
E 13
I 13
D 14
			(void) sigrelse(mask(SIGINT));
E 14
I 14
D 21
			sigrelse(SIGINT);
E 21
I 21
D 23
			sigsetmask(sigblock(0) & ~sigmask(SIGINT));
E 23
I 23
D 30
			(void) sigsetmask(sigblock(0) & ~sigmask(SIGINT));
E 30
I 30
			(void) sigsetmask(sigblock(0L) & ~sigmask(SIGINT));
E 30
E 23
E 21
E 14
E 13

		/*
		 * For the sake of reset()
		 */
		freelex(&paraml), freesyn(t), t = 0;

		if (haderr) {
			if (!catch) {
				/* unwind */
				doneinp = 0;
				resexit(osetexit);
				reset();
			}
			haderr = 0;
			/*
			 * Every error is eventually caught here or
			 * the shell dies.  It is at this
			 * point that we clean up any left-over open
			 * files, by closing all but a fixed number
			 * of pre-defined files.  Thus routines don't
			 * have to worry about leaving files open due
			 * to deeper errors... they will get closed here.
			 */
			closem();
			continue;
		}
		if (doneinp) {
			doneinp = 0;
			break;
		}
		if (chkstop)
			chkstop--;
		if (neednote)
			pnote();
D 17
		if (intty && evalvec == 0) {
E 17
I 17
		if (intty && prompt && evalvec == 0) {
E 17
			mailchk();
			/*
			 * If we are at the end of the input buffer
			 * then we are going to read fresh stuff.
			 * Otherwise, we are rereading input and don't
			 * need or want to prompt.
			 */
			if (fseekp == feobp)
D 16
				if (!whyles)
					for (cp = value("prompt"); *cp; cp++)
						if (*cp == HIST)
							printf("%d", eventno + 1);
						else {
							if (*cp == '\\' && cp[1] == HIST)
								cp++;
							putchar(*cp | QUOTE);
						}
				else
					/*
					 * Prompt for forward reading loop
					 * body content.
					 */
					printf("? ");
E 16
I 16
D 19
			    printprompt();
E 19
I 19
				printprompt();
E 19
E 16
D 23
			flush();
E 23
		}
		err = 0;

		/*
		 * Echo not only on VERBOSE, but also with history expansion.
		 * If there is a lexical error then we forego history echo.
		 */
D 6
		if (lex(&paraml) && !err && intty || adrof("verbose")) {
E 6
I 6
		if (lex(&paraml) && !err && intty ||
		    adrof("verbose")) {
E 6
			haderr = 1;
			prlex(&paraml);
			haderr = 0;
		}

		/*
		 * The parser may lose space if interrupted.
		 */
		if (setintr)
D 13
			sighold(SIGINT);
E 13
I 13
D 14
			sigblock(mask(SIGINT));
E 14
I 14
D 21
			sighold(SIGINT);
E 21
I 21
D 23
			sigblock(sigmask(SIGINT));
E 23
I 23
			(void) sigblock(sigmask(SIGINT));
E 23
E 21
E 14
E 13

		/*
D 3
		 * Save input text on the history list if it
E 3
I 3
		 * Save input text on the history list if 
		 * reading in old history, or it
E 3
		 * is from the terminal at the top level and not
		 * in a loop.
		 */
D 3
		if (catch && intty && !whyles)
E 3
I 3
		if (enterhist || catch && intty && !whyles)
E 3
			savehist(&paraml);

		/*
D 6
		 * Print lexical error messages.
E 6
I 6
		 * Print lexical error messages, except when sourcing
		 * history lists.
E 6
		 */
D 6
		if (err)
E 6
I 6
		if (!enterhist && err)
E 6
			error(err);

		/*
		 * If had a history command :p modifier then
		 * this is as far as we should go
		 */
		if (justpr)
			reset();

		alias(&paraml);

		/*
		 * Parse the words of the input into a parse tree.
		 */
		t = syntax(paraml.next, &paraml, 0);
		if (err)
			error(err);

		/*
		 * Execute the parse tree
		 */
		execute(t, tpgrp);

		/*
		 * Made it!
		 */
		freelex(&paraml), freesyn(t);
	}
	resexit(osetexit);
}

dosource(t)
	register char **t;
{
	register char *f;
	register int u;
I 6
	bool hflg = 0;
	char buf[BUFSIZ];
E 6

	t++;
D 6
	f = globone(*t);
E 6
I 6
	if (*t && eq(*t, "-h")) {
		t++;
		hflg++;
	}
D 23
	strcpy(buf, *t);
E 23
I 23
	(void) strcpy(buf, *t);
E 23
	f = globone(buf);
E 6
	u = dmove(open(f, 0), -1);
	xfree(f);
D 6
	if (u < 0)
E 6
I 6
	if (u < 0 && !hflg)
E 6
		Perror(f);
I 23
	(void) ioctl(u, FIOCLEX, (char *)0);
E 23
D 6
	srcunit(u, 0);
E 6
I 6
	srcunit(u, 0, hflg);
E 6
}

/*
 * Check for mail.
 * If we are a login shell, then we don't want to tell
 * about any mail file unless its been modified
 * after the time we started.
 * This prevents us from telling the user things he already
 * knows, since the login program insists on saying
 * "You have mail."
 */
mailchk()
{
	register struct varent *v;
	register char **vp;
	time_t t;
	int intvl, cnt;
	struct stat stb;
	bool new;

	v = adrof("mail");
	if (v == 0)
		return;
D 23
	time(&t);
E 23
I 23
	(void) time(&t);
E 23
	vp = v->vec;
	cnt = blklen(vp);
	intvl = (cnt && number(*vp)) ? (--cnt, getn(*vp++)) : MAILINTVL;
	if (intvl < 1)
		intvl = 1;
	if (chktim + intvl > t)
		return;
	for (; *vp; vp++) {
		if (stat(*vp, &stb) < 0)
			continue;
D 12
		new = stb.st_mtime > time0;
E 12
I 12
		new = stb.st_mtime > time0.tv_sec;
E 12
		if (stb.st_size == 0 || stb.st_atime > stb.st_mtime ||
		    (stb.st_atime < chktim && stb.st_mtime < chktim) ||
		    loginsh && !new)
			continue;
		if (cnt == 1)
			printf("You have %smail.\n", new ? "new " : "");
		else
			printf("%s in %s.\n", new ? "New mail" : "Mail", *vp);
	}
	chktim = t;
}

#include <pwd.h>
/*
 * Extract a home directory from the password file
 * The argument points to a buffer where the name of the
 * user whose home directory is sought is currently.
 * We write the home directory of the user back there.
 */
gethdir(home)
	char *home;
{
	register struct passwd *pp = getpwnam(home);

	if (pp == 0)
		return (1);
D 23
	strcpy(home, pp->pw_dir);
E 23
I 23
	(void) strcpy(home, pp->pw_dir);
E 23
	return (0);
}

/*
 * Move the initial descriptors to their eventual
 * resting places, closin all other units.
 */
initdesc()
{

D 23
	didcch = 0;			/* Havent closed for child */
E 23
	didfds = 0;			/* 0, 1, 2 aren't set up */
D 23
	SHIN = dcopy(0, FSHIN);
	SHOUT = dcopy(1, FSHOUT);
	SHDIAG = dcopy(2, FSHDIAG);
	OLDSTD = dcopy(SHIN, FOLDSTD);
E 23
I 23
	(void) ioctl(SHIN = dcopy(0, FSHIN), FIOCLEX, (char *)0);
	(void) ioctl(SHOUT = dcopy(1, FSHOUT), FIOCLEX, (char *)0);
	(void) ioctl(SHDIAG = dcopy(2, FSHDIAG), FIOCLEX, (char *)0);
	(void) ioctl(OLDSTD = dcopy(SHIN, FOLDSTD), FIOCLEX, (char *)0);
E 23
	closem();
}

I 20
#ifdef PROF
done(i)
#else
E 20
exit(i)
I 20
#endif
E 20
	int i;
{

	untty();
D 23
#ifdef PROF
D 20
	IEH3exit(i);
E 20
I 20
	monitor(0);
E 20
#else
E 23
	_exit(i);
D 23
#endif
E 23
I 16
}

D 19
printprompt ()
E 19
I 19
printprompt()
E 19
{
D 19
    register char *cp;
    if (!whyles)
	for (cp = value ("prompt"); *cp; cp++)
	    if (*cp == HIST)
		printf ("%d", eventno + 1);
	    else
	    {
		if (*cp == '\\' && cp[1] == HIST)
		    cp++;
		putchar (*cp | QUOTE);
	    }
    else
    /* 
     * Prompt for forward reading loop
     * body content.
     */
	printf ("? ");
    flush ();
E 19
I 19
	register char *cp;

D 20
	if (whyles) {
E 20
I 20
	if (!whyles) {
E 20
		for (cp = value("prompt"); *cp; cp++)
			if (*cp == HIST)
				printf("%d", eventno + 1);
			else {
				if (*cp == '\\' && cp[1] == HIST)
					cp++;
D 32
				putchar(*cp | QUOTE);
E 32
I 32
				cshputchar(*cp | QUOTE);
E 32
			}
	} else
		/* 
		 * Prompt for forward reading loop
		 * body content.
		 */
		printf("? ");
	flush();
E 19
E 16
}
E 1
