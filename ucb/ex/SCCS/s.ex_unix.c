h13270
s 00006/00006/00349
d D 7.8 03/04/13 15:19:16 msokolov 15 14
c 8-bit ex
e
s 00011/00011/00344
d D 7.7 87/03/09 12:46:24 conrad 14 13
c make ex/vi work on vms
e
s 00006/00003/00349
d D 7.6 85/10/22 16:31:44 bloom 13 12
c wait for all children, not just one
e
s 00001/00001/00351
d D 7.5 85/06/07 18:21:20 bloom 12 11
c fix sccsid and copyright for xstr
e
s 00010/00002/00342
d D 7.4 85/05/31 13:58:39 dist 11 9
c Add copyright
e
s 00010/00002/00330
d D 5.2.1.1 85/05/31 12:09:47 dist 10 5
c Add copyright
e
s 00008/00000/00336
d D 7.3 85/03/27 11:55:07 bloom 9 8
c use optimal size for i/o
e
s 00001/00001/00335
d D 7.2 83/06/10 10:08:13 ralph 8 7
c updating sccs files due to restoring an older SCCS directory
e
s 00003/00003/00333
d D 7.1 81/07/08 22:32:09 mark 7 6
c release 3.7 - a few bug fixes and a few new features.
e
s 00004/00000/00332
d D 6.1 80/10/19 01:21:44 mark 6 5
c preliminary release 3.6 10/18/80
e
s 00002/00002/00330
d D 5.2 80/09/12 08:32:08 mark 5 4
c separated TIOCLGET and SIGTSTP since Cory only has the former
e
s 00000/00000/00332
d D 5.1 80/08/20 16:12:44 mark 4 3
c Release 3.5, August 20, 1980
e
s 00001/00001/00331
d D 4.3 80/08/01 22:14:25 mark 3 2
c fixed quote typo
e
s 00001/00000/00331
d D 4.2 80/08/01 20:42:03 mark 2 1
c Bill added more buffers, and I put in sccs.
e
s 00331/00000/00000
d D 4.1 80/08/01 00:41:11 mark 1 0
c date and time created 80/08/01 00:41:11 by mark
e
u
U
t
T
I 1
D 10
D 11
/* Copyright (c) 1979 Regents of the University of California */
I 2
D 3
static char *sccsid = "%W%;
E 3
I 3
D 7
static char *sccsid = "%W% %G%";
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 10
E 7
I 7
D 8
static char *sccsid = "@(#)ex_unix.c	6.1 10/18/80";
E 8
I 8
static char *sccsid = "%W%	%G%";
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 12
static char sccsid[] = "%W% (Berkeley) %G%";
E 12
I 12
static char *sccsid = "%W% (Berkeley) %G%";
E 12
#endif not lint

E 11
E 8
E 7
E 3
E 2
#include "ex.h"
#include "ex_temp.h"
#include "ex_tty.h"
#include "ex_vis.h"

/*
 * Unix escapes, filtering
 */

/*
 * First part of a shell escape,
 * parse the line, expanding # and % and ! and printing if implied.
 */
unix0(warn)
	bool warn;
{
D 15
	register char *up, *fp;
E 15
I 15
	register u_char *up, *fp;
E 15
	register short c;
D 15
	char printub, puxb[UXBSIZE + sizeof (int)];
E 15
I 15
	u_char printub, puxb[UXBSIZE + sizeof (int)];
E 15

	printub = 0;
	CP(puxb, uxb);
D 14
	c = getchar();
E 14
I 14
	c = ex_getchar();
E 14
	if (c == '\n' || c == EOF)
		error("Incomplete shell escape command@- use 'shell' to get a shell");
	up = uxb;
	do {
		switch (c) {

		case '\\':
			if (any(peekchar(), "%#!"))
D 14
				c = getchar();
E 14
I 14
				c = ex_getchar();
E 14
		default:
			if (up >= &uxb[UXBSIZE]) {
tunix:
				uxb[0] = 0;
				error("Command too long");
			}
			*up++ = c;
			break;

		case '!':
			fp = puxb;
			if (*fp == 0) {
				uxb[0] = 0;
				error("No previous command@to substitute for !");
			}
			printub++;
			while (*fp) {
				if (up >= &uxb[UXBSIZE])
					goto tunix;
				*up++ = *fp++;
			}
			break;

		case '#':
			fp = altfile;
			if (*fp == 0) {
				uxb[0] = 0;
				error("No alternate filename@to substitute for #");
			}
			goto uexp;

		case '%':
			fp = savedfile;
			if (*fp == 0) {
				uxb[0] = 0;
				error("No filename@to substitute for %%");
			}
uexp:
			printub++;
			while (*fp) {
				if (up >= &uxb[UXBSIZE])
					goto tunix;
D 15
				*up++ = *fp++ | QUOTE;
E 15
I 15
				*up++ = *fp++;
E 15
			}
			break;
		}
D 14
		c = getchar();
E 14
I 14
		c = ex_getchar();
E 14
	} while (c == '"' || c == '|' || !endcmd(c));
	if (c == EOF)
		ungetchar(c);
	*up = 0;
	if (!inopen)
		resetflav();
	if (warn)
		ckaw();
	if (warn && hush == 0 && chng && xchng != chng && value(WARN) && dol > zero) {
		xchng = chng;
		vnfl();
D 14
		printf(mesg("[No write]|[No write since last change]"));
E 14
I 14
		ex_printf(mesg("[No write]|[No write since last change]"));
E 14
		noonl();
		flush();
	} else
		warn = 0;
	if (printub) {
		if (uxb[0] == 0)
			error("No previous command@to repeat");
		if (inopen) {
			splitw++;
			vclean();
			vgoto(WECHO, 0);
		}
		if (warn)
			vnfl();
		if (hush == 0)
			lprintf("!%s", uxb);
		if (inopen && Outchar != termchar) {
			vclreol();
			vgoto(WECHO, 0);
		} else
			putnl();
		flush();
	}
}

/*
 * Do the real work for execution of a shell escape.
 * Mode is like the number passed to open system calls
 * and indicates filtering.  If input is implied, newstdin
 * must have been setup already.
 */
ttymode
unixex(opt, up, newstdin, mode)
D 15
	char *opt, *up;
E 15
I 15
	u_char *opt, *up;
E 15
	int newstdin, mode;
{
	int pvec[2];
	ttymode f;

	signal(SIGINT, SIG_IGN);
D 5
#ifdef TIOCLGET
E 5
I 5
#ifdef SIGTSTP
E 5
	if (dosusp)
		signal(SIGTSTP, SIG_DFL);
#endif
	if (inopen)
		f = setty(normf);
	if ((mode & 1) && pipe(pvec) < 0) {
		/* Newstdin should be io so it will be closed */
		if (inopen)
D 14
			setty(f);
E 14
I 14
			ignore(setty(f));
E 14
		error("Can't make pipe for filter");
	}
#ifndef VFORK
	pid = fork();
#else
	pid = vfork();
#endif
	if (pid < 0) {
		if (mode & 1) {
			close(pvec[0]);
			close(pvec[1]);
		}
		setrupt();
		error("No more processes");
	}
	if (pid == 0) {
		if (mode & 2) {
			close(0);
			dup(newstdin);
			close(newstdin);
		}
		if (mode & 1) {
			close(pvec[0]);
			close(1);
			dup(pvec[1]);
			if (inopen) {
				close(2);
				dup(1);
			}
			close(pvec[1]);
		}
		if (io)
			close(io);
		if (tfile)
			close(tfile);
D 14
#ifndef VMUNIX
E 14
I 14
#ifdef EXSTRINGS
E 14
		close(erfile);
#endif
		signal(SIGHUP, oldhup);
		signal(SIGQUIT, oldquit);
		if (ruptible)
			signal(SIGINT, SIG_DFL);
D 15
		execl(svalue(SHELL), "sh", opt, up, (char *) 0);
E 15
I 15
		execl(svalue(SHELL), "sh", opt, up, (u_char *) 0);
E 15
D 14
		printf("No %s!\n", svalue(SHELL));
E 14
I 14
		ex_printf("No %s!\n", svalue(SHELL));
E 14
		error(NOSTR);
	}
	if (mode & 1) {
		io = pvec[0];
		close(pvec[1]);
	}
	if (newstdin)
		close(newstdin);
	return (f);
}

/*
 * Wait for the command to complete.
 * F is for restoration of tty mode if from open/visual.
 * C flags suppression of printing.
 */
unixwt(c, f)
	bool c;
	ttymode f;
{

	waitfor();
D 5
#ifdef TIOCLGET
E 5
I 5
#ifdef SIGTSTP
E 5
	if (dosusp)
		signal(SIGTSTP, onsusp);
#endif
	if (inopen)
D 14
		setty(f);
E 14
I 14
		ignore(setty(f));
E 14
	setrupt();
	if (!inopen && c && hush == 0) {
D 14
		printf("!\n");
E 14
I 14
		ex_printf("!\n");
E 14
		flush();
		termreset();
		gettmode();
	}
}

/*
 * Setup a pipeline for the filtration implied by mode
 * which is like a open number.  If input is required to
 * the filter, then a child editor is created to write it.
 * If output is catch it from io which is created by unixex.
 */
filter(mode)
	register int mode;
{
	static int pvec[2];
D 7
	register ttymode f;
E 7
I 7
	ttymode f;	/* mjm: was register */
E 7
	register int lines = lineDOL();
I 9
	struct stat statb;
E 9

	mode++;
	if (mode & 2) {
		signal(SIGINT, SIG_IGN);
		if (pipe(pvec) < 0)
			error("Can't make pipe");
		pid = fork();
		io = pvec[0];
		if (pid < 0) {
			setrupt();
			close(pvec[1]);
			error("No more processes");
		}
		if (pid == 0) {
			setrupt();
			io = pvec[1];
			close(pvec[0]);
D 7
			putfile();
E 7
I 7
			putfile(1);
E 7
D 14
			exit(0);
E 14
I 14
			ex_exit(0);
E 14
		}
		close(pvec[1]);
		io = pvec[0];
		setrupt();
	}
	f = unixex("-c", uxb, (mode & 2) ? pvec[0] : 0, mode);
	if (mode == 3) {
D 14
		delete(0);
E 14
I 14
		ex_delete(0);
E 14
		addr2 = addr1 - 1;
	}
	if (mode & 1) {
		if(FIXUNDO)
			undap1 = undap2 = addr2+1;
I 9
		if (fstat(io, &statb) < 0)
			bsize = LBSIZE;
		else {
			bsize = statb.st_blksize;
			if (bsize <= 0)
				bsize = LBSIZE;
		}
E 9
		ignore(append(getfile, addr2));
I 6
#ifdef TRACE
		if (trace)
			vudump("after append in filter");
#endif
E 6
	}
	close(io);
	io = -1;
	unixwt(!inopen, f);
	netchHAD(lines);
}

/*
 * Set up to do a recover, getting io to be a pipe from
 * the recover process.
 */
recover()
{
	static int pvec[2];

	if (pipe(pvec) < 0)
		error(" Can't make pipe for recovery");
	pid = fork();
	io = pvec[0];
	if (pid < 0) {
		close(pvec[1]);
		error(" Can't fork to execute recovery");
	}
	if (pid == 0) {
		close(2);
		dup(1);
		close(1);
		dup(pvec[1]);
	        close(pvec[1]);
D 15
		execl(EXRECOVER, "exrecover", svalue(DIRECTORY), file, (char *) 0);
E 15
I 15
		execl(EXRECOVER, "exrecover", svalue(DIRECTORY), file, (u_char *) 0);
E 15
		close(1);
		dup(2);
		error(" No recovery routine");
	}
	close(pvec[1]);
}

/*
 * Wait for the process (pid an external) to complete.
 */
waitfor()
{
I 13
	int stat = 0;
E 13

D 13
	do
		rpid = wait(&status);
	while (rpid != pid && rpid != -1);
E 13
I 13
	do {
		rpid = wait(&stat);
		if (rpid == pid)
			status = stat;
	} while (rpid != -1);
E 13
	status = (status >> 8) & 0377;
}

/*
 * The end of a recover operation.  If the process
 * exits non-zero, force not edited; otherwise force
 * a write.
 */
revocer()
{

	waitfor();
	if (pid == rpid && status != 0)
		edited = 0;
	else
		change();
}
E 1
