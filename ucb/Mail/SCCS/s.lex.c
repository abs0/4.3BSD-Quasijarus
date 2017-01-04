h27835
s 00002/00009/00686
d D 5.8 88/04/12 15:44:03 edward 48 47
c just exit on SIGHUP, don't try to save messages into mbox
e
s 00011/00005/00684
d D 5.7 88/02/18 17:04:00 bostic 47 46
c written by Kurt Shoens; added Berkeley specific header
e
s 00001/00000/00688
d D 5.6 88/01/02 22:36:18 bostic 46 45
c fix extern declarations for ANSI C
e
s 00027/00041/00661
d D 5.5 87/05/18 12:28:08 edward 45 44
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00002/00001/00700
d D 5.4 85/11/02 20:29:29 serge 44 43
c check for overflow in getrawlist()
e
s 00026/00007/00675
d D 5.3 85/09/15 16:55:14 serge 43 42
c disallow "Mail -f directory" (or other non-plain file)
e
s 00001/00001/00681
d D 5.2 85/06/21 17:10:58 mckusick 42 41
c botched copyright
e
s 00008/00002/00674
d D 5.1 85/06/06 10:35:19 dist 41 40
c Add copyright
e
s 00035/00015/00641
d D 2.17 85/04/18 18:17:20 serge 40 39
c modified to work with new stdio; added retain command; fixed several bugs
e
s 00003/00004/00653
d D 2.16 84/08/08 17:05:12 ralph 39 38
c fix stdio flushing, don't mess with stdio buffers
e
s 00010/00000/00647
d D 2.15 84/08/03 14:59:48 ralph 38 37
c Just print no mail if zero length mail file
e
s 00003/00003/00644
d D 2.14 83/08/11 22:16:33 sam 37 36
c standardize sccs keyword lines
e
s 00004/00003/00643
d D 2.13 83/06/15 13:26:56 sam 36 35
c merge leres code
e
s 00001/00003/00645
d D 2.12 83/06/12 11:16:20 sam 35 34
c new signals
e
s 00002/00002/00646
d D 2.11 83/01/22 14:49:35 leres 34 33
c Moved printing of initial greeting to beginning of announce()
e
s 00001/00006/00647
d D 2.10 82/08/13 21:27:14 kurt 33 32
c fixed setfile() to not print error message, just return the 
c right code. 
c 
e
s 00010/00001/00643
d D 2.9 82/03/24 16:10:35 kurt 32 30
c changed newfileinfo() to print the number of saved 
c and deleted messages. 
c 
e
s 00006/00001/00643
d R 2.9 82/03/24 15:32:52 kurt 31 30
c changed newfileinfo() to print the number of deleted 
c messages. 
c 
e
s 00001/00001/00643
d D 2.8 82/03/15 09:44:19 kurt 30 28
i 29
c Included Eric's branch changes to remove vax and vmunix 
c dependencies. 
c 
e
s 00013/00000/00604
d D 2.5.1.1 82/03/15 09:33:46 kurt 29 26
c Eric Allman's fixes to remove VAX and VMUNIX dependencies
e
s 00010/00002/00621
d D 2.7 82/02/17 22:54:40 kurt 28 27
c changed newfileinfo() to detect when user is editing a folder and 
c report it as +folder for clarity 
c 
e
s 00050/00031/00573
d D 2.6 82/02/13 14:47:06 kurt 27 26
c changed the way commands() works:  now it just reads commands 
c until eof and returns.  all the old garbage about printing headers and 
c sourcing .mailrc have been removed. 
c Added routine load() to read the user's .mailrc and /usr/lib/Mail.rc 
c 
e
s 00003/00004/00601
d D 2.5 81/10/21 13:54:58 kurt 26 25
c changed method of holding SIGCONT to just catch signal or 
c set its disposition to SIG_DFL, rather than trying sighold/sigrelse, 
c which choke on SIGCONT. 
c 
e
s 00009/00007/00596
d D 2.4 81/10/20 17:21:36 kurt 25 24
c changed the prompt string to be easily set 
c and easily set it to & 
c 
e
s 00006/00003/00597
d D 2.3 81/09/12 10:44:52 kurt 24 23
c now if you type more than 25 eofs in a row, it assumes you really
c mean it.  this is to combat a strange dialup problem that makes your
c program read eofs forever.
e
s 00000/00000/00600
d D 2.2 81/09/09 14:09:03 kurt 23 20
i 22 21
c added stuff from branch to handle the version stuff better
e
s 00002/00002/00598
d D 2.1.1.2 81/09/09 13:55:09 kurt 22 21
c changed usage of version string to be more pleasant
e
s 00000/00000/00600
d D 2.1.1.1 81/09/09 13:49:18 kurt 21 20
c branch-place-holder
e
s 00000/00000/00600
d D 2.1 81/07/01 11:09:20 kurt 20 19
c Release to Heidi Stettner
e
s 00001/00001/00599
d D 1.19 81/04/20 13:41:37 kurt 19 18
c changed to version 2.1
e
s 00004/00006/00596
d D 1.18 81/04/20 13:36:34 kurt 18 17
c changed to make use of signal holding facility
e
s 00017/00002/00585
d D 1.17 81/04/01 17:49:19 kurt 17 16
c changed to print out prompt when resumed after ^Z
e
s 00032/00015/00555
d D 1.16 81/04/01 12:53:15 kurt 16 15
c changed calls on signal to sigset;
c changed to trap hangups and make them simulate quits
e
s 00009/00002/00561
d D 1.15 81/03/13 12:51:51 kas 15 14
c now handles interrupts correctly during initial header printing
c so that an initial CR will get you the first msg
e
s 00001/00001/00562
d D 1.14 81/02/06 09:36:53 kas 14 13
c Now takes -N flag to suppress initial header printing
e
s 00001/00001/00562
d D 1.13 81/01/23 17:05:17 kas 13 12
c added : to the stop character set
e
s 00027/00015/00536
d D 1.12 81/01/13 23:34:34 kas 12 11
c added newfileinfo() to print out interesting stuff about mailname;
c announce() now calls this
e
s 00010/00004/00541
d D 1.11 81/01/12 16:33:41 kas 11 10
c execute now takes a second parameter which says whether the command
c was invoked from collect.  If so, one may not execute commands marked with R
e
s 00002/00001/00543
d D 1.10 81/01/12 11:50:57 kas 10 9
c if there are no messages, avoids printing headers on start up
e
s 00002/00002/00542
d D 1.9 81/01/05 17:35:20 kas 9 8
c Changed conditional command flag from C to F
e
s 00024/00002/00520
d D 1.8 80/10/18 18:13:13 kas 8 7
c setfile() now copies the new file name into mailname;
c execute() now tests cond to see if command should be executed;
c transparent commands (currently file) do not affect sawcom so that
c a subsequent "next" command will print the first message
e
s 00009/00003/00513
d D 1.7 80/10/17 00:32:30 kas 7 6
c announce now looks for the first unread message if there
c are no new messages and sets dot to the first "interesting" message
c it finds
e
s 00007/00001/00509
d D 1.6 80/10/16 18:46:56 kas 6 5
c initial header printing now attempts to start the header
c listing at the first new message (failing that, at the first message
c as before)
e
s 00004/00009/00506
d D 1.5 80/10/16 16:20:07 kas 5 4
c reinstated code to announce headers in lex
c made setfile just set flag shudann to make lex print headers later
c removed loop in announce() which preserves all messages if value("hold"0
e
s 00001/00000/00514
d D 1.4 80/10/10 13:42:42 kas 4 3
c Reset sawcom after reading new file so that
c carriage return turns into t1 at start
e
s 00122/00010/00392
d D 1.3 80/10/09 13:34:59 kas 3 2
c added subroutine setfile to make changing input files easy;
c added checks for commands which cannot be executed in read only mode;
c changed announce() to print out [Read only] when appropriate.
e
s 00005/00000/00397
d D 1.2 80/10/08 18:56:15 kas 2 1
c Added ignoreeof flag which requires explicit quit instead of
c End of File from terminal to leave Mail.
e
s 00397/00000/00000
d D 1.1 80/10/08 09:50:24 kas 1 0
c date and time created 80/10/08 09:50:24 by kas
e
u
U
f b 
t
T
I 41
/*
 * Copyright (c) 1980 Regents of the University of California.
D 47
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 47
I 47
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 47
 */

E 41
I 1
D 37
#
E 37
I 37
D 47
#ifndef lint
D 40
static char sccsid[] = "%W% (Berkeley) %G%";
E 40
I 40
D 41
static char *sccsid = "%W% (Berkeley) %G%";
E 40
#endif
E 41
I 41
D 42
static char sccsid[] = "%W% (Berkeley) %G%";
E 42
I 42
static char *sccsid = "%W% (Berkeley) %G%";
E 42
#endif not lint
E 47
I 47
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 47
E 41
E 37

#include "rcv.h"
I 38
#include <sys/stat.h>
I 43
#include <errno.h>
E 43
E 38

/*
 * Mail -- a mail program
 *
 * Lexical processing of commands.
 */
D 37

static char *SccsId = "%W% %G%";
E 37

I 25
char	*prompt = "& ";

E 25
/*
I 3
 * Set up editing on the given file name.
 * If isedit is true, we are considered to be editing the file,
 * otherwise we are reading our mail which has signficance for
 * mbox and so forth.
 */

setfile(name, isedit)
	char *name;
{
	FILE *ibuf;
	int i;
I 38
	struct stat stb;
E 38
	static int shudclob;
	static char efile[128];
	extern char tempMesg[];
I 43
	extern int errno;
E 43
D 16
	int (*sigs[2])();
E 16
I 16
D 18
	int (*sigs[3])();
E 18
E 16

D 33
	if ((ibuf = fopen(name, "r")) == NULL) {
		if (isedit)
			perror(name);
		else
			printf("No mail for %s\n", myname);
E 33
I 33
	if ((ibuf = fopen(name, "r")) == NULL)
E 33
		return(-1);
I 38
D 43
	if (!edit) {
		if (fstat(fileno(ibuf), &stb) < 0) {
			perror(name);
			exit(1);
		}
		if (stb.st_size == 0)
			return(-1);
E 43
I 43

	if (fstat(fileno(ibuf), &stb) < 0) {
		fclose(ibuf);
		return (-1);
	}

	switch (stb.st_mode & S_IFMT) {
	case S_IFDIR:
		fclose(ibuf);
		errno = EISDIR;
		return (-1);

	case S_IFREG:
		break;

	default:
		fclose(ibuf);
		errno = EINVAL;
		return (-1);
	}

	if (!edit && stb.st_size == 0) {
		fclose(ibuf);
		return(-1);
E 43
	}
E 38
D 33
	}
E 33

	/*
	 * Looks like all will be well.  We must now relinquish our
D 18
	 * hold on the current set of stuff.  Must ignore signals
E 18
I 18
	 * hold on the current set of stuff.  Must hold signals
E 18
	 * while we are reading the new file, else we will ruin
	 * the message[] data structure.
	 */

D 16
	for (i = SIGINT; i <= SIGQUIT; i++)
		sigs[i - SIGINT] = signal(i, SIG_IGN);
E 16
I 16
D 18
	sigsave(sigs, SIG_IGN);
E 18
I 18
	holdsigs();
E 18
E 16
	if (shudclob) {
		if (edit)
			edstop();
		else
			quit();
	}

	/*
	 * Copy the messages into /tmp
	 * and set pointers.
	 */

	readonly = 0;
	if ((i = open(name, 1)) < 0)
		readonly++;
	else
		close(i);
	if (shudclob) {
		fclose(itf);
		fclose(otf);
	}
	shudclob = 1;
	edit = isedit;
	strncpy(efile, name, 128);
	editfile = efile;
I 8
	if (name != mailname)
		strcpy(mailname, name);
E 8
	mailsize = fsize(ibuf);
	if ((otf = fopen(tempMesg, "w")) == NULL) {
		perror(tempMesg);
		exit(1);
	}
	if ((itf = fopen(tempMesg, "r")) == NULL) {
		perror(tempMesg);
		exit(1);
	}
	remove(tempMesg);
	setptr(ibuf);
	setmsize(msgCount);
	fclose(ibuf);
D 16
	for (i = SIGINT; i <= SIGQUIT; i++)
		signal(i, sigs[i - SIGINT]);
E 16
I 16
D 18
	sigret(sigs);
E 18
I 18
	relsesigs();
E 18
E 16
D 12
	printf("%s: ", name);
E 12
D 5
	announce(!edit);
E 5
I 5
D 27
	shudann = 1;
E 27
E 5
I 4
	sawcom = 0;
E 4
	return(0);
}

/*
E 3
 * Interpret user commands one by one.  If standard input is not a tty,
 * print no prompt.
 */

int	*msgvec;
I 45
jmp_buf	commjmp;
E 45

commands()
{
D 24
	int prompt, firstsw, stop();
E 24
I 24
D 25
	int eofloop, prompt, firstsw, stop();
E 25
I 25
D 27
	int eofloop, shudprompt, firstsw, stop();
E 27
I 27
	int eofloop, shudprompt, stop();
E 27
E 25
E 24
	register int n;
	char linebuf[LINESIZE];
I 16
D 17
	int hangup();
E 17
I 17
	int hangup(), contin();
E 17
E 16

I 29
D 45
# ifdef VMUNIX
E 29
I 17
D 26
	sigset(SIGCONT, contin);
	sighold(SIGCONT);
E 26
I 26
	sigset(SIGCONT, SIG_DFL);
I 29
# endif VMUNIX
E 45
I 45
	signal(SIGCONT, SIG_DFL);
E 45
E 29
E 26
E 17
D 3
	msgvec = (int *) calloc((unsigned) (msgCount + 1), sizeof *msgvec);
E 3
D 16
	if (rcvmode)
		if (signal(SIGINT, SIG_IGN) == SIG_DFL)
			signal(SIGINT, stop);
E 16
I 16
D 27
	if (rcvmode) {
E 27
I 27
	if (rcvmode && !sourcing) {
E 27
D 45
		if (sigset(SIGINT, SIG_IGN) != SIG_IGN)
			sigset(SIGINT, stop);
		if (sigset(SIGHUP, SIG_IGN) != SIG_IGN)
			sigset(SIGHUP, hangup);
E 45
I 45
		if (signal(SIGINT, SIG_IGN) != SIG_IGN)
			signal(SIGINT, stop);
		if (signal(SIGHUP, SIG_IGN) != SIG_IGN)
			signal(SIGHUP, hangup);
E 45
	}
E 16
D 27
	input = stdin;
D 25
	prompt = 1;
E 25
I 25
	shudprompt = 1;
E 25
	if (!intty)
D 25
		prompt = 0;
E 25
I 25
		shudprompt = 0;
E 25
	firstsw = 1;
E 27
I 27
	shudprompt = intty && !sourcing;
E 27
	for (;;) {
		setexit();
D 27
		if (firstsw > 0) {
			firstsw = 0;
			source1(mailrc);
			if (!nosrc)
				source1(MASTER);
		}
E 27

		/*
D 27
		 * How's this for obscure:  after we
		 * finish sourcing for the first time,
		 * go off and print the headers!
		 */

I 3
D 5
#ifdef CRAZYWOW
E 3
		if (firstsw == 0 && !sourcing) {
			firstsw = -1;
E 5
I 5
		if (shudann && !sourcing) {
			shudann = 0;
E 5
			if (rcvmode)
D 3
				announce();
E 3
I 3
D 5
				announce(1);
E 5
I 5
				announce(edit);
E 5
E 3
		}
I 3
D 5
#endif
E 5
E 3

		/*
E 27
		 * Print the prompt, if needed.  Clear out
		 * string space, and flush the output.
		 */

		if (!rcvmode && !sourcing)
			return;
I 24
		eofloop = 0;
E 24
I 2
top:
E 2
D 17
		if (prompt && !sourcing)
E 17
I 17
D 25
		if (prompt && !sourcing) {
E 25
I 25
D 27
		if (shudprompt && !sourcing) {
I 29
D 30
# ifdef VMUNIX
E 30
E 29
E 27
I 27
		if (shudprompt) {
I 45
			setjmp(commjmp);
			signal(SIGCONT, contin);
E 45
I 36
			printf(prompt);
D 39
			flush();
E 39
I 39
D 45
			fflush(stdout);
E 39
E 36
I 30
# ifdef VMUNIX
E 30
E 27
E 25
D 26
			sigrelse(SIGCONT);
E 26
I 26
			sigset(SIGCONT, contin);
I 29
# endif VMUNIX
E 29
E 26
E 17
D 25
			printf("_\r");
E 25
I 25
D 36
			printf(prompt);
E 25
I 17
		}
E 17
		flush();
E 36
I 36
		} else
D 39
			flush();
E 39
I 39
			fflush(stdout);
E 45
I 45
		}
		fflush(stdout);
E 45
E 39
E 36
		sreset();

		/*
		 * Read a line of commands from the current input
		 * and handle end of file specially.
		 */

		n = 0;
		for (;;) {
D 45
			if (readline(input, &linebuf[n]) <= 0) {
E 45
I 45
			if (readline(input, &linebuf[n]) < 0) {
E 45
				if (n != 0)
					break;
I 27
				if (loading)
					return;
E 27
				if (sourcing) {
					unstack();
					goto more;
I 2
				}
D 25
				if (value("ignoreeof") != NOSTR && prompt) {
E 25
I 25
				if (value("ignoreeof") != NOSTR && shudprompt) {
E 25
D 24
					printf("Use \"quit\" to quit.\n");
					goto top;
E 24
I 24
					if (++eofloop < 25) {
						printf("Use \"quit\" to quit.\n");
						goto top;
					}
E 24
E 2
				}
D 16
				if (!edit) {
					signal(SIGINT, SIG_IGN);
E 16
I 16
D 27
				if (!edit)
E 16
					return;
D 16
				}
E 16
				edstop();
E 27
I 27
				if (edit)
					edstop();
E 27
				return;
			}
			if ((n = strlen(linebuf)) == 0)
				break;
			n--;
			if (linebuf[n] != '\\')
				break;
			linebuf[n++] = ' ';
		}
I 29
D 45
# ifdef VMUNIX
E 29
I 17
D 26
		sighold(SIGCONT);
E 26
I 26
		sigset(SIGCONT, SIG_DFL);
I 29
# endif VMUNIX
E 45
I 45
		signal(SIGCONT, SIG_DFL);
E 45
E 29
E 26
E 17
D 11
		if (execute(linebuf))
E 11
I 11
		if (execute(linebuf, 0))
E 11
			return;
more:		;
	}
}

/*
 * Execute a single command.  If the command executed
 * is "quit," then return non-zero so that the caller
 * will know to return back to main, if he cares.
I 11
 * Contxt is non-zero if called while composing mail.
E 11
 */

D 11
execute(linebuf)
E 11
I 11
execute(linebuf, contxt)
E 11
	char linebuf[];
{
	char word[LINESIZE];
	char *arglist[MAXARGC];
	struct cmd *com;
	register char *cp, *cp2;
	register int c;
I 3
	int muvec[2];
E 3
	int edstop(), e;

	/*
	 * Strip the white space away from the beginning
	 * of the command, then scan out a word, which
	 * consists of anything except digits and white space.
	 *
	 * Handle ! escapes differently to get the correct
	 * lexical conventions.
	 */

D 45
	cp = linebuf;
	while (any(*cp, " \t"))
		cp++;
E 45
I 45
	for (cp = linebuf; isspace(*cp); cp++)
		;
E 45
	if (*cp == '!') {
		if (sourcing) {
			printf("Can't \"!\" while sourcing\n");
			unstack();
			return(0);
		}
		shell(cp+1);
		return(0);
	}
	cp2 = word;
D 3
	while (*cp && !any(*cp, " \t0123456789$^.-+*'\""))
E 3
I 3
D 13
	while (*cp && !any(*cp, " \t0123456789$^./-+*'\""))
E 13
I 13
	while (*cp && !any(*cp, " \t0123456789$^.:/-+*'\""))
E 13
E 3
		*cp2++ = *cp++;
	*cp2 = '\0';

	/*
	 * Look up the command; if not found, bitch.
	 * Normally, a blank command would map to the
	 * first command in the table; while sourcing,
	 * however, we ignore blank lines to eliminate
	 * confusion.
	 */

D 45
	if (sourcing && equal(word, ""))
E 45
I 45
	if (sourcing && *word == '\0')
E 45
		return(0);
	com = lex(word);
	if (com == NONE) {
D 27
		printf("What?\n");
E 27
I 27
		printf("Unknown command: \"%s\"\n", word);
		if (loading)
			return(1);
E 27
		if (sourcing)
			unstack();
		return(0);
	}

	/*
I 8
	 * See if we should execute the command -- if a conditional
	 * we always execute it, otherwise, check the state of cond.
	 */

D 9
	if ((com->c_argtype & C) == 0)
E 9
I 9
	if ((com->c_argtype & F) == 0)
E 9
		if (cond == CRCV && !rcvmode || cond == CSEND && rcvmode)
			return(0);

	/*
E 8
	 * Special case so that quit causes a return to
	 * main, who will call the quit code directly.
	 * If we are in a source file, just unstack.
	 */

	if (com->c_func == edstop && sourcing) {
I 27
		if (loading)
			return(1);
E 27
		unstack();
		return(0);
	}
	if (!edit && com->c_func == edstop) {
D 16
		signal(SIGINT, SIG_IGN);
E 16
I 16
D 45
		sigset(SIGINT, SIG_IGN);
E 45
I 45
		signal(SIGINT, SIG_IGN);
E 45
E 16
		return(1);
	}

	/*
	 * Process the arguments to the command, depending
	 * on the type he expects.  Default to an error.
	 * If we are sourcing an interactive command, it's
	 * an error.
	 */

	if (!rcvmode && (com->c_argtype & M) == 0) {
		printf("May not execute \"%s\" while sending\n",
		    com->c_name);
I 27
		if (loading)
			return(1);
E 27
D 11
		unstack();
E 11
I 11
		if (sourcing)
			unstack();
E 11
		return(0);
	}
	if (sourcing && com->c_argtype & I) {
		printf("May not execute \"%s\" while sourcing\n",
		    com->c_name);
I 27
		if (loading)
			return(1);
E 27
		unstack();
		return(0);
	}
I 3
	if (readonly && com->c_argtype & W) {
		printf("May not execute \"%s\" -- message file is read only\n",
		   com->c_name);
I 27
		if (loading)
			return(1);
E 27
		if (sourcing)
			unstack();
		return(0);
	}
I 11
	if (contxt && com->c_argtype & R) {
		printf("Cannot recursively invoke \"%s\"\n", com->c_name);
		return(0);
	}
E 11
E 3
	e = 1;
D 3
	switch (com->c_argtype & ~(P|I|M)) {
E 3
I 3
D 8
	switch (com->c_argtype & ~(P|I|M|W)) {
E 8
I 8
D 9
	switch (com->c_argtype & ~(C|P|I|M|T|W)) {
E 9
I 9
D 11
	switch (com->c_argtype & ~(F|P|I|M|T|W)) {
E 11
I 11
	switch (com->c_argtype & ~(F|P|I|M|T|W|R)) {
E 11
E 9
E 8
E 3
	case MSGLIST:
		/*
		 * A message list defaulting to nearest forward
		 * legal message.
		 */
I 27
		if (msgvec == 0) {
			printf("Illegal use of \"message list\"\n");
			return(-1);
		}
E 27
		if ((c = getmsglist(cp, msgvec, com->c_msgflag)) < 0)
			break;
		if (c  == 0) {
			*msgvec = first(com->c_msgflag,
				com->c_msgmask);
			msgvec[1] = NULL;
		}
		if (*msgvec == NULL) {
			printf("No applicable messages\n");
			break;
		}
		e = (*com->c_func)(msgvec);
		break;

	case NDMLIST:
		/*
		 * A message list with no defaults, but no error
		 * if none exist.
		 */
I 27
		if (msgvec == 0) {
			printf("Illegal use of \"message list\"\n");
			return(-1);
		}
E 27
		if (getmsglist(cp, msgvec, com->c_msgflag) < 0)
			break;
		e = (*com->c_func)(msgvec);
		break;

	case STRLIST:
		/*
		 * Just the straight string, with
		 * leading blanks removed.
		 */
D 45
		while (any(*cp, " \t"))
E 45
I 45
		while (isspace(*cp))
E 45
			cp++;
		e = (*com->c_func)(cp);
		break;

	case RAWLIST:
		/*
		 * A vector of strings, in shell style.
		 */
D 44
		if ((c = getrawlist(cp, arglist)) < 0)
E 44
I 44
		if ((c = getrawlist(cp, arglist,
				sizeof arglist / sizeof *arglist)) < 0)
E 44
			break;
		if (c < com->c_minargs) {
			printf("%s requires at least %d arg(s)\n",
				com->c_name, com->c_minargs);
			break;
		}
		if (c > com->c_maxargs) {
			printf("%s takes no more than %d arg(s)\n",
				com->c_name, com->c_maxargs);
			break;
		}
		e = (*com->c_func)(arglist);
		break;

	case NOLIST:
		/*
		 * Just the constant zero, for exiting,
		 * eg.
		 */
		e = (*com->c_func)(0);
		break;

	default:
		panic("Unknown argtype");
	}

	/*
	 * Exit the current source file on
	 * error.
	 */

I 27
	if (e && loading)
		return(1);
E 27
	if (e && sourcing)
		unstack();
	if (com->c_func == edstop)
		return(1);
	if (value("autoprint") != NOSTR && com->c_argtype & P)
D 3
		if ((dot->m_flag & MDELETED) == 0)
			print(dot);
E 3
I 3
		if ((dot->m_flag & MDELETED) == 0) {
			muvec[0] = dot - &message[0] + 1;
			muvec[1] = 0;
			type(muvec);
		}
E 3
D 8
	if (!sourcing)
E 8
I 8
	if (!sourcing && (com->c_argtype & T) == 0)
E 8
		sawcom = 1;
	return(0);
I 17
}

/*
 * When we wake up after ^Z, reprint the prompt.
 */
I 45
/*ARGSUSED*/
E 45
contin(s)
{

D 25
	printf("_\r");
E 25
I 25
D 45
	printf(prompt);
E 25
	fflush(stdout);
E 45
I 45
	longjmp(commjmp, 1);
E 45
E 17
}

/*
I 16
D 48
 * Branch here on hangup signal and simulate quit.
E 48
I 48
 * Branch here on hangup signal and simulate "exit".
E 48
 */
D 45
hangup()
E 45
I 45
/*ARGSUSED*/
hangup(s)
E 45
{
D 18
	int (*sigs[3])();
E 18

D 18
	sigsave(sigs);
E 18
I 18
D 48
	holdsigs();
E 18
	if (edit) {
		if (setexit())
			exit(0);
		edstop();
	}
	else
		quit();
E 48
I 48
	/* nothing to do? */
E 48
	exit(0);
}

/*
E 16
I 3
 * Set the size of the message vector used to construct argument
 * lists to message list functions.
 */
 
setmsize(sz)
{

D 45
	if (msgvec != (int *) 0)
		cfree(msgvec);
E 45
I 45
	if (msgvec != 0)
		cfree((char *) msgvec);
E 45
	msgvec = (int *) calloc((unsigned) (sz + 1), sizeof *msgvec);
}

/*
E 3
 * Find the correct command in the command table corresponding
 * to the passed command "word"
 */

struct cmd *
lex(word)
	char word[];
{
	register struct cmd *cp;
	extern struct cmd cmdtab[];

	for (cp = &cmdtab[0]; cp->c_name != NOSTR; cp++)
		if (isprefix(word, cp->c_name))
			return(cp);
	return(NONE);
}

/*
 * Determine if as1 is a valid prefix of as2.
 * Return true if yep.
 */

isprefix(as1, as2)
	char *as1, *as2;
{
	register char *s1, *s2;

	s1 = as1;
	s2 = as2;
	while (*s1++ == *s2)
		if (*s2++ == '\0')
			return(1);
	return(*--s1 == '\0');
}

/*
D 45
 * The following gets called on receipt of a rubout.  This is
E 45
I 45
 * The following gets called on receipt of an interrupt.  This is
E 45
 * to abort printout of a command, mainly.
 * Dispatching here when command() is inactive crashes rcv.
 * Close all open files except 0, 1, 2, and the temporary.
D 45
 * The special call to getuserid() is needed so it won't get
 * annoyed about losing its open file.
E 45
 * Also, unstack all source files.
 */

I 15
int	inithdr;			/* am printing startup headers */

I 40
#ifdef _NFILE
static
_fwalk(function)
	register int (*function)();
{
	register FILE *iop;

	for (iop = _iob; iop < _iob + _NFILE; iop++)
		(*function)(iop);
}
#endif

static
xclose(iop)
	register FILE *iop;
{
	if (iop == stdin || iop == stdout ||
	    iop == stderr || iop == itf || iop == otf)
		return;

	if (iop != pipef)
		fclose(iop);
	else {
		pclose(pipef);
		pipef = NULL;
	}
}

I 45
/*ARGSUSED*/
E 45
E 40
E 15
D 16
stop()
E 16
I 16
stop(s)
E 16
{
D 45
	register FILE *fp;
E 45

I 29
D 45
# ifndef VMUNIX
	s = SIGINT;
# endif VMUNIX
E 45
E 29
	noreset = 0;
D 16
	signal(SIGINT, SIG_IGN);
E 16
D 15
	sawcom++;
E 15
I 15
	if (!inithdr)
		sawcom++;
	inithdr = 0;
E 15
	while (sourcing)
		unstack();
D 45
	getuserid((char *) -1);
E 45
D 40
	for (fp = &_iob[0]; fp < &_iob[_NFILE]; fp++) {
		if (fp == stdin || fp == stdout)
			continue;
		if (fp == itf || fp == otf)
			continue;
		if (fp == stderr)
			continue;
I 3
		if (fp == pipef) {
			pclose(pipef);
			pipef = NULL;
			continue;
		}
E 3
		fclose(fp);
	}
E 40
I 40

	/*
	 * Walk through all the open FILEs, applying xclose() to them
	 */
	_fwalk(xclose);

E 40
	if (image >= 0) {
		close(image);
		image = -1;
	}
D 39
	clrbuf(stdout);
	printf("Interrupt\n");
E 39
I 39
	fprintf(stderr, "Interrupt\n");
E 39
I 29
D 35
# ifdef VMUNIX
E 29
D 16
	signal(SIGINT, stop);
E 16
I 16
	sigrelse(s);
I 29
# else
E 35
I 35
D 45
# ifndef VMUNIX
E 35
	signal(s, stop);
# endif
E 45
E 29
E 16
	reset(0);
}

/*
 * Announce the presence of the current Mail version,
 * give the message count, and print a header listing.
 */

D 19
char	*greeting	= "Mail version 2.0 %s.  Type ? for help.\n";
E 19
I 19
D 22
char	*greeting	= "Mail version 2.1 %s.  Type ? for help.\n";
E 22
I 22
char	*greeting	= "Mail version %s.  Type ? for help.\n";
E 22
E 19

D 3
announce()
E 3
I 3
announce(pr)
E 3
{
D 7
	int vec[2];
E 7
I 7
	int vec[2], mdot;
E 7
	extern char *version;
I 12

I 34
	if (pr && value("quiet") == NOSTR)
		printf(greeting, version);
E 34
	mdot = newfileinfo();
	vec[0] = mdot;
	vec[1] = 0;
D 34
	if (pr && value("quiet") == NOSTR)
		printf(greeting, version);
E 34
	dot = &message[mdot - 1];
D 14
	if (msgCount > 0)
E 14
I 14
D 15
	if (msgCount > 0 && !noheader)
E 15
I 15
	if (msgCount > 0 && !noheader) {
		inithdr++;
E 15
E 14
		headers(vec);
I 15
		inithdr = 0;
	}
E 15
}

/*
 * Announce information about the file we are editing.
 * Return a likely place to set dot.
 */
D 28

E 28
newfileinfo()
{
E 12
	register struct message *mp;
I 8
D 12
	register int u, n;
E 12
I 12
D 32
	register int u, n, mdot;
E 32
I 32
	register int u, n, mdot, d, s;
E 32
I 28
	char fname[BUFSIZ], zname[BUFSIZ], *ename;
E 28
E 12
E 8

D 5
	if (value("hold") != NOSTR)
		for (mp = &message[0]; mp < &message[msgCount]; mp++)
			mp->m_flag |= MPRESERVE;
E 5
D 6
	vec[0] = 1;
E 6
I 6
	for (mp = &message[0]; mp < &message[msgCount]; mp++)
		if (mp->m_flag & MNEW)
			break;
I 7
	if (mp >= &message[msgCount])
		for (mp = &message[0]; mp < &message[msgCount]; mp++)
			if ((mp->m_flag & MREAD) == 0)
				break;
E 7
	if (mp < &message[msgCount])
D 7
		vec[0] = mp - &message[0] + 1;
E 7
I 7
		mdot = mp - &message[0] + 1;
E 7
	else
D 7
		vec[0] = 1;
E 7
I 7
		mdot = 1;
I 32
	s = d = 0;
E 32
D 12
	vec[0] = mdot;
E 7
E 6
	vec[1] = 0;
D 3
	if (value("quiet") == NOSTR)
E 3
I 3
	if (pr && value("quiet") == NOSTR)
E 3
		printf(greeting, version);
	if (msgCount == 1)
D 3
		printf("1 message:\n");
E 3
I 3
		printf("1 message");
E 3
	else
D 3
		printf("%d messages:\n", msgCount);
E 3
I 3
		printf("%d messages", msgCount);
	if (readonly)
		printf(" [Read only]");
E 12
I 8
	for (mp = &message[0], n = 0, u = 0; mp < &message[msgCount]; mp++) {
		if (mp->m_flag & MNEW)
			n++;
		if ((mp->m_flag & MREAD) == 0)
			u++;
I 32
		if (mp->m_flag & MDELETED)
			d++;
		if (mp->m_flag & MSAVED)
			s++;
E 32
	}
I 12
D 28
	printf("\"%s\": ", mailname);
E 28
I 28
	ename = mailname;
	if (getfold(fname) >= 0) {
		strcat(fname, "/");
		if (strncmp(fname, mailname, strlen(fname)) == 0) {
			sprintf(zname, "+%s", mailname + strlen(fname));
			ename = zname;
		}
	}
	printf("\"%s\": ", ename);
E 28
	if (msgCount == 1)
		printf("1 message");
	else
		printf("%d messages", msgCount);
E 12
	if (n > 0)
		printf(" %d new", n);
	if (u-n > 0)
		printf(" %d unread", u);
I 32
	if (d > 0)
		printf(" %d deleted", d);
	if (s > 0)
		printf(" %d saved", s);
E 32
I 12
	if (readonly)
		printf(" [Read only]");
E 12
E 8
	printf("\n");
E 3
D 10
	headers(vec);
E 10
I 10
D 12
	if (msgCount > 0)
		headers(vec);
E 10
I 7
	dot = &message[mdot - 1];
E 12
I 12
	return(mdot);
E 12
E 7
}

D 45
strace() {}

E 45
/*
 * Print the current version number.
 */

I 45
/*ARGSUSED*/
E 45
pversion(e)
{
I 46
	extern char *version;
E 46
I 45

E 45
D 22
	printf(greeting, version);
E 22
I 22
	printf("Version %s\n", version);
E 22
	return(0);
I 27
}

/*
 * Load a file of user definitions.
 */
load(name)
	char *name;
{
	register FILE *in, *oldin;

	if ((in = fopen(name, "r")) == NULL)
		return;
	oldin = input;
	input = in;
	loading = 1;
	sourcing = 1;
	commands();
	loading = 0;
	sourcing = 0;
	input = oldin;
	fclose(in);
E 27
}
E 1
