h34996
s 00011/00011/00506
d D 7.7 03/04/13 15:18:39 msokolov 23 21
c 8-bit ex
e
s 00000/00018/00499
d D 7.6.1.1 88/08/08 18:26:18 mckusick 22 21
c delete decryption for the foreign sites (4.3BSD Tahoe)
e
s 00086/00020/00431
d D 7.6 87/03/09 12:46:43 conrad 21 19
c make ex/vi work on vms
e
s 00000/00018/00433
d D 7.5.1.1 86/08/12 15:51:40 mckusick 20 19
c delete decryption for the foreign sites
e
s 00022/00003/00429
d D 7.5 85/08/29 17:33:42 bloom 19 18
c only use .exrc if owned by user or option sourceany is used
e
s 00002/00002/00430
d D 7.4 85/06/07 18:18:10 bloom 18 17
c fix sccsid and copyright for xstr
e
s 00016/00002/00416
d D 7.3 85/05/31 13:50:11 dist 17 15
c Add copyright
e
s 00016/00002/00524
d D 5.3.1.1 85/05/31 11:56:26 dist 16 9
c Add copyright
e
s 00011/00011/00407
d D 7.2 85/03/27 12:00:04 bloom 15 14
c move sbrk to avoid problems with fopen calling malloc
e
s 00014/00004/00404
d D 7.1 81/07/08 22:27:37 mark 14 13
c release 3.7 - a few bug fixes and a few new features.
e
s 00001/00130/00407
d D 6.4 80/11/08 21:22:03 mark 13 12
c moved signal catching routines to ex_subr.c so they'll be in root ovly
e
s 00016/00000/00521
d D 6.3 80/10/28 22:06:59 mark 12 11
c added emt catch for overlay pdp-11 systems
e
s 00000/00008/00521
d D 6.2 80/10/20 11:19:26 mark 11 10
c took out code ignoring hangups on USG since nobody knows why it's there
e
s 00008/00005/00521
d D 6.1 80/10/19 01:19:51 mark 10 9
c preliminary release 3.6 10/18/80
e
s 00001/00001/00525
d D 5.3 80/09/13 13:30:39 mark 9 8
c fixed SCCS keyword
e
s 00002/00002/00524
d D 5.2 80/09/12 08:31:52 mark 8 7
c separated TIOCLGET and SIGTSTP since Cory only has the former
e
s 00000/00000/00526
d D 5.1 80/08/20 16:07:20 mark 7 6
c Release 3.5, August 20, 1980
e
s 00007/00004/00519
d D 4.3 80/08/20 00:24:03 mark 6 5
c made CRYPT an #ifdef
e
s 00008/00001/00515
d D 4.2 80/08/01 17:58:24 mark 5 4
c added sccs, Bill put in more buffers
e
s 00074/00024/00442
d D 4.1 80/08/01 00:09:17 mark 4 3
c release 3.4, June 24, 1980
e
s 00004/00000/00462
d D 3.1 80/07/31 23:35:46 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00006/00000/00456
d D 2.1 80/07/31 23:17:01 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00456/00000/00000
d D 1.1 80/07/31 22:59:57 mark 1 0
c date and time created 80/07/31 22:59:57 by mark
e
u
U
f b 
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 14
D 16
/* Copyright (c) 1980 Regents of the University of California */
D 6
static char *sccsid = "%W% %G%";
E 6
I 6
D 9
static char *sccsid = "@(#)ex.c	4.2 8/1/80";
E 9
I 9
static char *sccsid = "%W% %G%";
E 16
I 16
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 16
E 14
I 14
D 17
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 17
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 18
char copyright[] =
E 18
I 18
char *copyright =
E 18
D 21
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 21
I 21
"@(#) Copyright (c) 1980 Regents of the University of California.\n\
E 21
 All rights reserved.\n";
#endif not lint

#ifndef lint
D 18
static char sccsid[] = "%W% (Berkeley) %G%";
E 18
I 18
static char *sccsid = "%W% (Berkeley) %G%";
E 18
#endif not lint

E 17
E 14
E 9
E 6
E 5
#include "ex.h"
#include "ex_argv.h"
#include "ex_temp.h"
#include "ex_tty.h"

#ifdef TRACE
I 21
#ifdef	vms
D 23
char	tttrace[]	= { 't','r','a','c','e','.','l','i','s' };
E 23
I 23
u_char	tttrace[]	= { 't','r','a','c','e','.','l','i','s' };
E 23
#else
E 21
D 23
char	tttrace[]	= { '/','d','e','v','/','t','t','y','x','x',0 };
E 23
I 23
u_char	tttrace[]	= { '/','d','e','v','/','t','t','y','x','x',0 };
E 23
#endif
I 21
#endif
E 21

/*
 * The code for ex is divided as follows:
 *
 * ex.c			Entry point and routines handling interrupt, hangup
 *			signals; initialization code.
 *
 * ex_addr.c		Address parsing routines for command mode decoding.
 *			Routines to set and check address ranges on commands.
 *
 * ex_cmds.c		Command mode command decoding.
 *
 * ex_cmds2.c		Subroutines for command decoding and processing of
 *			file names in the argument list.  Routines to print
 *			messages and reset state when errors occur.
 *
 * ex_cmdsub.c		Subroutines which implement command mode functions
 *			such as append, delete, join.
 *
 * ex_data.c		Initialization of options.
 *
 * ex_get.c		Command mode input routines.
 *
 * ex_io.c		General input/output processing: file i/o, unix
 *			escapes, filtering, source commands, preserving
 *			and recovering.
 *
 * ex_put.c		Terminal driving and optimizing routines for low-level
 *			output (cursor-positioning); output line formatting
 *			routines.
 *
 * ex_re.c		Global commands, substitute, regular expression
 *			compilation and execution.
 *
 * ex_set.c		The set command.
 *
 * ex_subr.c		Loads of miscellaneous subroutines.
 *
 * ex_temp.c		Editor buffer routines for main buffer and also
 *			for named buffers (Q registers if you will.)
 *
 * ex_tty.c		Terminal dependent initializations from termcap
 *			data base, grabbing of tty modes (at beginning
 *			and after escapes).
 *
I 4
 * ex_unix.c		Routines for the ! command and its variations.
 *
E 4
 * ex_v*.c		Visual/open mode routines... see ex_v.c for a
 *			guide to the overall organization.
 */

/*
 * Main procedure.  Process arguments and then
 * transfer control to the main command processing loop
D 4
 * in the routine commands.  We are entered as either "ex", "edit" or "vi"
 * and the distinction is made here.  Actually, we are "vi" if
 * there is a 'v' in our name, and "edit" if there is a 'd' in our
 * name.  For edit we just diddle options; for vi we actually
 * force an early visual command, setting the external initev so
 * the q command in visual doesn't give command mode.
E 4
I 4
 * in the routine commands.  We are entered as either "ex", "edit", "vi"
 * or "view" and the distinction is made here.  Actually, we are "vi" if
 * there is a 'v' in our name, "view" is there is a 'w', and "edit" if
 * there is a 'd' in our name.  For edit we just diddle options;
 * for vi we actually force an early visual command.
E 4
 */
main(ac, av)
	register int ac;
D 23
	register char *av[];
E 23
I 23
	register u_char *av[];
E 23
{
I 2
D 21
#ifndef VMUNIX
E 21
I 21
#ifdef EXSTRINGS
E 21
E 2
D 23
	char *erpath = EXSTRINGS;
E 23
I 23
	u_char *erpath = EXSTRINGS;
E 23
I 2
#endif
E 2
D 23
	register char *cp;
E 23
I 23
	register u_char *cp;
E 23
	register int c;
	bool recov = 0;
	bool ivis;
	bool itag = 0;
	bool fast = 0;
I 12
D 13
	int onemt();
E 13
I 13
	extern int onemt();
I 21
#ifdef UNIX_SBRK
	extern char *sbrk();
#else
	extern char *malloc();
#endif
E 21
E 13
E 12
#ifdef TRACE
D 23
	register char *tracef;
E 23
I 23
	register u_char *tracef;
E 23
#endif
I 21
#ifdef	vms
D 23
	char termtype[20];
E 23
I 23
	u_char termtype[20];
E 23
#endif
E 21

	/*
	 * Immediately grab the tty modes so that we wont
	 * get messed up if an interrupt comes in quickly.
	 */
D 21
	gTTY(1);
E 21
I 21
	ex_gTTY(1);
E 21
I 4
#ifndef USG3TTY
E 4
	normf = tty.sg_flags;
I 4
#else
	normf = tty;
#endif
E 4
	ppid = getpid();
I 5
D 6
#ifdef HORSE
	horse(ac, av);
#endif
E 6
E 5
	/*
D 4
	 * Defend against d's, v's, and a's in directories of
E 4
I 4
	 * Defend against d's, v's, w's, and a's in directories of
E 4
	 * path leading to our true name.
	 */
I 21
#ifndef	vms
E 21
	av[0] = tailpath(av[0]);
I 21
#else
	/*
	 * This program has to be invoked by using the following
	 * string definitions:
	 *
	 * vi == "$dir:ex.exe vi"
	 * view == "$dir:ex.exe view"
	 * ex == "$dir:ex.exe ex"
	 * edit == "$dir:ex.exe edit"
	 */
	ac--;
	av++;
#endif
E 21
D 4
	ivis = any('v', av[0]);
E 4

	/*
D 4
	 * For debugging take files out of . if name is a.out.
	 * If a 'd' in our name, then set options for edit.
E 4
I 4
	 * Figure out how we were invoked: ex, edit, vi, view.
E 4
	 */
I 2
D 4
#ifndef VMUNIX
E 2
	if (av[0][0] == 'a')
		erpath = tailpath(erpath);
I 2
#endif
E 2
	if (ivis) {
#ifdef notdef
		options[BEAUTIFY].odefault = value(BEAUTIFY) = 1;
#endif
	} else if (any('d', av[0])) {
E 4
I 4
	ivis = any('v', av[0]);	/* "vi" */
	if (any('w', av[0]))	/* "view" */
		value(READONLY) = 1;
	if (any('d', av[0])) {	/* "edit" */
E 4
		value(OPEN) = 0;
		value(REPORT) = 1;
		value(MAGIC) = 0;
	}

I 4
D 21
#ifndef VMUNIX
E 21
I 21
#ifdef EXSTRINGS
E 21
E 4
	/*
I 4
	 * For debugging take files out of . if name is a.out.
	 */
	if (av[0][0] == 'a')
		erpath = tailpath(erpath);
#endif
	/*
E 4
	 * Open the error message file.
	 */
	draino();
I 2
D 21
#ifndef VMUNIX
E 21
I 21
#ifdef EXSTRINGS
E 21
E 2
	erfile = open(erpath+4, 0);
	if (erfile < 0) {
		erfile = open(erpath, 0);
	}
I 2
#endif
E 2
	pstop();

	/*
	 * Initialize interrupt handling.
	 */
	oldhup = signal(SIGHUP, SIG_IGN);
	if (oldhup == SIG_DFL)
		signal(SIGHUP, onhup);
	oldquit = signal(SIGQUIT, SIG_IGN);
	ruptible = signal(SIGINT, SIG_IGN) == SIG_DFL;
	if (signal(SIGTERM, SIG_IGN) == SIG_DFL)
		signal(SIGTERM, onhup);
I 12
	if (signal(SIGEMT, SIG_IGN) == SIG_DFL)
		signal(SIGEMT, onemt);
E 12
I 4
D 8
#ifdef TIOCLGET
E 8
I 8
D 10
#ifdef SIGTSTP
E 8
	if (signal(SIGTSTP, SIG_IGN) == SIG_DFL)
		signal(SIGTSTP, onsusp), dosusp++;
#endif
E 10
E 4

	/*
D 15
	 * Initialize end of core pointers.
	 * Normally we avoid breaking back to fendcore after each
	 * file since this can be expensive (much core-core copying).
	 * If your system can scatter load processes you could do
	 * this as ed does, saving a little core, but it will probably
	 * not often make much difference.
	 */
	fendcore = (line *) sbrk(0);
	endcore = fendcore - 2;

	/*
E 15
	 * Process flag arguments.
	 */
	ac--, av++;
	while (ac && av[0][0] == '-') {
		c = av[0][1];
		if (c == 0) {
			hush = 1;
			value(AUTOPRINT) = 0;
			fast++;
		} else switch (c) {

I 4
		case 'R':
			value(READONLY) = 1;
			break;

E 4
#ifdef TRACE
		case 'T':
			if (av[0][2] == 0)
				tracef = "trace";
			else {
				tracef = tttrace;
				tracef[8] = av[0][2];
				if (tracef[8])
					tracef[9] = av[0][3];
				else
					tracef[9] = 0;
			}
			trace = fopen(tracef, "w");
I 14
#define tracbuf NULL
E 14
			if (trace == NULL)
D 21
				printf("Trace create error\n");
E 21
I 21
				ex_printf("Trace create error\n");
E 21
D 14
			setbuf(trace, tracbuf);
E 14
I 14
			else
				setbuf(trace, tracbuf);
E 14
			break;

#endif

#ifdef LISPCODE
		case 'l':
			value(LISP) = 1;
			value(SHOWMATCH) = 1;
			break;
#endif

		case 'r':
			recov++;
			break;

		case 't':
			if (ac > 1 && av[1][0] != '-') {
				ac--, av++;
				itag = 1;
				/* BUG: should check for too long tag. */
				CP(lasttag, av[0]);
			}
			break;

		case 'v':
			ivis = 1;
			break;

		case 'w':
			defwind = 0;
			if (av[0][2] == 0) defwind = 3;
			else for (cp = &av[0][2]; isdigit(*cp); cp++)
				defwind = 10*defwind + *cp - '0';
			break;

I 6
D 20
D 22
#ifdef CRYPT
E 6
I 4
		case 'x':
			/* -x: encrypted mode */
			xflag = 1;
			break;
I 6
#endif
E 22
E 20
E 6

E 4
		default:
			smerror("Unknown option %s\n", av[0]);
			break;
		}
		ac--, av++;
	}
I 15

D 21
	/*
	 * Initialize end of core pointers.
	 * Normally we avoid breaking back to fendcore after each
	 * file since this can be expensive (much core-core copying).
	 * If your system can scatter load processes you could do
	 * this as ed does, saving a little core, but it will probably
	 * not often make much difference.
	 */
	fendcore = (line *) sbrk(0);
	endcore = fendcore - 2;
E 15
I 10

#ifdef SIGTSTP
E 21
I 21
#ifdef SIGTSTP
E 21
	if (!hush && signal(SIGTSTP, SIG_IGN) == SIG_DFL)
		signal(SIGTSTP, onsusp), dosusp++;
#endif

E 10
	if (ac && av[0][0] == '+') {
		firstpat = &av[0][1];
		ac--, av++;
	}

I 6
D 20
D 22
#ifdef CRYPT
E 6
I 4
	if(xflag){
		key = getpass(KEYPROMPT);
		kflag = crinit(key, perm);
	}
I 6
#endif
E 22
E 20
E 6

E 4
	/*
	 * If we are doing a recover and no filename
	 * was given, then execute an exrecover command with
	 * the -r option to type out the list of saved file names.
	 * Otherwise set the remembered file name to the first argument
	 * file name so the "recover" initial command will find it.
	 */
	if (recov) {
		if (ac == 0) {
			ppid = 0;
			setrupt();
			execl(EXRECOVER, "exrecover", "-r", 0);
			filioerr(EXRECOVER);
D 21
			exit(1);
E 21
I 21
			ex_exit(1);
E 21
		}
		CP(savedfile, *av++), ac--;
	}

	/*
	 * Initialize the argument list.
	 */
	argv0 = av;
	argc0 = ac;
	args0 = av[0];
	erewind();

	/*
	 * Initialize a temporary file (buffer) and
	 * set up terminal environment.  Read user startup commands.
	 */
D 10
	init();
E 10
	if (setexit() == 0) {
		setrupt();
		intty = isatty(0);
		value(PROMPT) = intty;
I 21
#ifndef	vms
E 21
I 4
		if (cp = getenv("SHELL"))
I 21
#else
		if (cp = getlog("SHELL"))
#endif
E 21
			CP(shell, cp);
E 4
		if (fast || !intty)
			setterm("dumb");
		else {
			gettmode();
I 21
#ifndef	vms
E 21
D 4
			if ((cp = getenv("TERM")) != 0)
E 4
I 4
			if ((cp = getenv("TERM")) != 0 && *cp)
E 4
				setterm(cp);
I 21
#else
			if ((cp = getlog("TERM")) != 0 && *cp) {
				/*
				 * Can't just use it directly since getlog
				 * returns a pointer to a static buffer that
				 * tgetent() will eventually use
				 */
				CP(termtype, cp);
				setterm(termtype);
			}
#endif
E 21
		}
	}
D 14
	if (setexit() == 0 && !fast && intty)
E 14
I 14
	if (setexit() == 0 && !fast && intty) {
I 21
#ifndef	vms
E 21
E 14
D 4
		if (globp = getenv("EXINIT"))
E 4
I 4
		if ((globp = getenv("EXINIT")) && *globp)
I 21
#else
		if ((globp = getlog("EXINIT")) && *globp)
#endif
E 21
E 4
			commands(1,1);
D 4
		else if ((cp = getenv("HOME")) != 0)
			source(strcat(strcpy(genbuf, cp), "/.exrc"), 1);
E 4
I 4
		else {
			globp = 0;
D 19
			if ((cp = getenv("HOME")) != 0 && *cp)
				source(strcat(strcpy(genbuf, cp), "/.exrc"), 1);
E 19
I 19
			if ((cp = getenv("HOME")) != 0 && *cp) {
				(void) strcat(strcpy(genbuf, cp), "/.exrc");
				if (iownit(genbuf))
					source(genbuf, 1);
			}
E 19
		}
I 14
		/*
		 * Allow local .exrc too.  This loses if . is $HOME,
		 * but nobody should notice unless they do stupid things
		 * like putting a version command in .exrc.  Besides,
		 * they should be using EXINIT, not .exrc, right?
		 */
D 19
		source(".exrc", 1);
E 19
I 19
		 if (iownit(".exrc"))
			source(".exrc", 1);
E 19
	}
I 21
#ifdef	UNIX_SBRK
	/*
	 * Initialize end of core pointers.
	 * Normally we avoid breaking back to fendcore after each
	 * file since this can be expensive (much core-core copying).
	 * If your system can scatter load processes you could do
	 * this as ed does, saving a little core, but it will probably
	 * not often make much difference.
	 */
	fendcore = (line *) sbrk(0);
	endcore = fendcore - 2;
#else
	/*
	 * Allocate all the memory we will ever use in one chunk.
	 * This is for system such as VMS where sbrk() does not
	 * guarantee that the memory allocated beyond the end is
	 * consecutive.  VMS's RMS does all sorts of memory allocation
	 * and screwed up ex royally because ex assumes that all
	 * memory up to "endcore" belongs to it and RMS has different
	 * ideas.
	 */
	fendcore = (line *) malloc((unsigned)
		value(LINELIMIT) * sizeof (line *));
	if (fendcore == NULL) {
		lprintf("ex: cannot handle %d lines\n", value(LINELIMIT));
		lprintf("ex: set \"linelimit\" lower\n");
		flush();
		ex_exit(1);
	}
	endcore = fendcore + (value(LINELIMIT) - 1);
#endif
E 21
E 14
I 10
	init();	/* moved after prev 2 chunks to fix directory option */
E 10
E 4

	/*
	 * Initial processing.  Handle tag, recover, and file argument
	 * implied next commands.  If going in as 'vi', then don't do
	 * anything, just set initev so we will do it later (from within
	 * visual).
	 */
	if (setexit() == 0) {
		if (recov)
			globp = "recover";
		else if (itag)
			globp = ivis ? "tag" : "tag|p";
		else if (argc)
			globp = "next";
		if (ivis)
			initev = globp;
		else if (globp) {
			inglobal = 1;
			commands(1, 1);
			inglobal = 0;
		}
	}

	/*
	 * Vi command... go into visual.
	 * Strange... everything in vi usually happens
	 * before we ever "start".
	 */
	if (ivis) {
		/*
		 * Don't have to be upward compatible with stupidity
		 * of starting editing at line $.
		 */
		if (dol > zero)
			dot = one;
		globp = "visual";
		if (setexit() == 0)
			commands(1, 1);
	}

	/*
	 * Clear out trash in state accumulated by startup,
	 * and then do the main command loop for a normal edit.
	 * If you quit out of a 'vi' command by doing Q or ^\,
	 * you also fall through to here.
	 */
I 10
	seenprompt = 1;
E 10
	ungetchar(0);
	globp = 0;
	initev = 0;
	setlastchar('\n');
	setexit();
	commands(0, 0);
	cleanup(1);
D 21
	exit(0);
E 21
I 21
	ex_exit(0);
E 21
}

/*
 * Initialization, before editing a new file.
 * Main thing here is to get a new buffer (in fileinit),
 * rest is peripheral state resetting.
 */
init()
{
	register int i;

	fileinit();
	dot = zero = truedol = unddol = dol = fendcore;
	one = zero+1;
	undkind = UNDNONE;
	chng = 0;
	edited = 0;
I 4
D 11
#ifdef USG
	signal (SIGHUP, SIG_IGN);
#endif
#ifdef USG3TTY
#ifndef USG
	signal (SIGHUP, SIG_IGN);
#endif
#endif
E 11
E 4
	for (i = 0; i <= 'z'-'a'+1; i++)
		names[i] = 1;
	anymarks = 0;
I 6
D 20
D 22
#ifdef CRYPT
E 6
I 4
        if(xflag) {
                xtflag = 1;
                makekey(key, tperm);
        }
I 6
#endif
E 22
E 20
E 6
E 4
}

/*
D 13
 * When a hangup occurs our actions are similar to a preserve
 * command.  If the buffer has not been [Modified], then we do
 * nothing but remove the temporary files and exit.
 * Otherwise, we sync the temp file and then attempt a preserve.
 * If the preserve succeeds, we unlink our temp files.
 * If the preserve fails, we leave the temp files as they are
 * as they are a backup even without preservation if they
 * are not removed.
 */
onhup()
{

I 4
	/*
	 * USG tty driver can send multiple HUP's!!
	 */
	signal(SIGINT, SIG_IGN);
	signal(SIGHUP, SIG_IGN);
E 4
	if (chng == 0) {
		cleanup(1);
		exit(0);
	}
	if (setexit() == 0) {
		if (preserve()) {
			cleanup(1);
			exit(0);
		}
	}
	exit(1);
}

/*
 * An interrupt occurred.  Drain any output which
 * is still in the output buffering pipeline.
 * Catch interrupts again.  Unless we are in visual
 * reset the output state (out of -nl mode, e.g).
 * Then like a normal error (with the \n before Interrupt
 * suppressed in visual mode).
 */
onintr()
{

#ifndef CBREAK
	signal(SIGINT, onintr);
#else
	signal(SIGINT, inopen ? vintr : onintr);
#endif
	draino();
	if (!inopen) {
		pstop();
		setlastchar('\n');
#ifdef CBREAK
	}
#else
	} else
		vraw();
#endif
	error("\nInterrupt" + inopen);
}

/*
 * If we are interruptible, enable interrupts again.
 * In some critical sections we turn interrupts off,
 * but not very often.
 */
setrupt()
{

D 4
	if (ruptible)
E 4
I 4
	if (ruptible) {
E 4
#ifndef CBREAK
		signal(SIGINT, onintr);
#else
		signal(SIGINT, inopen ? vintr : onintr);
#endif
I 4
D 8
#ifdef TIOCLGET
E 8
I 8
#ifdef SIGTSTP
E 8
		if (dosusp)
			signal(SIGTSTP, onsusp);
#endif
	}
E 4
}

preserve()
{

I 5
#ifdef VMUNIX
	tflush();
#endif
E 5
	synctmp();
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0) {
		close(0);
		dup(tfile);
		execl(EXPRESERVE, "expreserve", (char *) 0);
		exit(1);
	}
	waitfor();
	if (rpid == pid && status == 0)
		return (1);
	return (0);
}

#ifndef V6
exit(i)
	int i;
{

I 3
# ifdef TRACE
	if (trace)
		fclose(trace);
# endif
E 3
	_exit(i);
}
#endif

/*
E 13
 * Return last component of unix path name p.
 */
D 23
char *
E 23
I 23
u_char *
E 23
tailpath(p)
D 23
register char *p;
E 23
I 23
register u_char *p;
E 23
{
D 23
	register char *r;
E 23
I 23
	register u_char *r;
E 23

	for (r=p; *p; p++)
		if (*p == '/')
			r = p+1;
	return(r);
I 19
}

/*
 * Check ownership of file.  Return nonzero if it exists and is owned by the
 * user or the option sourceany is used
 */
iownit(file)
D 23
char *file;
E 23
I 23
u_char *file;
E 23
{
	struct stat sb;

	if (stat(file, &sb) == 0 && (value(SOURCEANY) || sb.st_uid == getuid()))
		return(1);
	else
		return(0);
E 19
I 12
D 13
}

/*
 * The following code is defensive programming against a bug in the
 * pdp-11 overlay implementation.  Sometimes it goes nuts and asks
 * for an overlay with some garbage number, which generates an emt
 * trap.  This is a less than elegant solution, but it is somewhat
 * better than core dumping and losing your work, leaving your tty
 * in a weird state, etc.
 */
onemt()
{
	error("emt trap@ - try again");
E 13
E 12
}
E 1
