h34682
s 00034/00018/00777
d D 5.7 03/04/15 19:00:37 msokolov 33 32
c add koi8edit option to convert interpolated messages from KOI-7 to KOI-8 for
c ease of editing
e
s 00011/00005/00784
d D 5.6 88/02/18 17:03:38 bostic 32 31
c written by Kurt Shoens; added Berkeley specific header
e
s 00001/00001/00788
d D 5.5 88/01/28 21:14:16 edward 31 30
c fixed stupid bug in handling of ~?
e
s 00002/00001/00787
d D 5.4 88/01/02 22:35:04 bostic 30 29
c fix extern declarations for ANSI C
e
s 00166/00256/00622
d D 5.3 87/05/18 12:28:11 edward 29 28
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00877
d D 5.2 85/06/21 17:08:55 mckusick 28 27
c botched copyright
e
s 00007/00001/00871
d D 5.1 85/06/06 10:25:03 dist 27 26
c Add copyright
e
s 00003/00003/00869
d D 2.18 85/01/09 10:17:54 ralph 26 25
c use sigmask() macro
e
s 00004/00004/00868
d D 2.17 84/08/08 17:05:26 ralph 25 24
c fix stdio flushing, don't mess with stdio buffers
e
s 00008/00005/00864
d D 2.16 84/07/19 15:42:35 ralph 24 23
c use flock for mailbox locking
e
s 00003/00003/00866
d D 2.15 83/08/11 22:14:11 sam 23 22
c standardize sccs keyword lines
e
s 00007/00007/00862
d D 2.14 83/06/12 11:16:28 sam 22 21
c new signals
e
s 00001/00001/00868
d D 2.13 83/01/22 14:56:13 leres 21 20
c Modified to use perror() to report open failure on THELPFILE
e
s 00011/00016/00858
d D 2.12 82/10/21 05:53:03 carl 20 19
c Changes to support long mail sizes (long m_size).
c Changed msize(x) to inline expansion x->m_size.
c Deleted definition of foonly().  Changed calls to foonly() to call signull().
e
s 00001/00000/00873
d D 2.11 82/10/21 04:36:47 carl 19 18
c Added a line to print ``(continue)'' after ~: escape.
e
s 00001/00002/00872
d D 2.10 82/07/28 23:11:10 kurt 18 17
c changed calls on send to include the doignore parameter. 
c 
e
s 00002/00000/00872
d D 2.9 82/07/26 17:07:24 kurt 17 16
c added calls on sigchild() after forks to fix up retrofit signals 
c 
e
s 00000/00000/00872
d D 2.8 82/03/15 09:43:59 kurt 16 13
i 15 14
c Included Eric's branch changes to remove vax and vmunix 
c dependencies. 
c 
e
s 00044/00003/00828
d D 2.7.1.2 82/03/15 09:33:04 kurt 15 14
c Eric Allman's fixes to remove VAX and VMUNIX dependencies
e
s 00000/00000/00831
d D 2.7.1.1 82/03/15 09:16:48 kurt 14 13
c branch-place-holder
e
s 00001/00001/00830
d D 2.7 81/12/07 15:47:25 kurt 13 12
c more careful when examining return status value -- 
c we only claim a fatal error if the editor died by other than exit() 
c 
e
s 00001/00001/00830
d D 2.6 81/10/22 16:43:38 kurt 12 11
c Allow ~w to write on an existing file if it is not a "plain" file 
c 
e
s 00000/00001/00831
d D 2.5 81/10/21 13:54:06 kurt 11 10
c removed dangerous sigrelse(SIGCONT). 
c Stuff with SIGCONT and libjobs signal package have been causing grief. 
c 
e
s 00002/00001/00830
d D 2.4 81/09/19 17:05:23 kurt 10 9
c fixed collect() botch -- it used to be if you set ignoreeof without 
c set dot, you couldn't terminate a message normally.  Now ignoreeof implies dot. 
c 
e
s 00001/00001/00830
d D 2.3 81/09/19 14:29:00 kurt 9 8
c corrected erroneous message produced by ignoreeof in collect() 
c 
e
s 00013/00004/00818
d D 2.2 81/09/14 19:19:19 kurt 8 7
c made collect() ignore eof's (to a point) if ignoreeof is set;
c now checks value("dot) anew for each line which is a . alone.
e
s 00000/00000/00822
d D 2.1 81/07/01 11:08:24 kurt 7 6
c Release to Heidi Stettner
e
s 00013/00004/00809
d D 1.6 81/05/22 14:42:14 kurt 6 5
c Fixed SIGCONT bug where reported wrong program state;
c made ignore SIGCONT with in ~e and ~v
e
s 00001/00002/00812
d D 1.5 81/04/20 13:34:50 kurt 5 4
c ~ escapes now interpreted when standard input not a tty
e
s 00019/00002/00795
d D 1.4 81/04/01 17:39:32 kurt 4 3
c changed to print (continue) when continued after ^Z
e
s 00032/00047/00765
d D 1.3 81/04/01 12:45:39 kurt 3 2
c changed calls on signal to sigset/sigsys;
c hangups now cause current message to be saved in ~/dead.letter;
c replaced hokie nofault stuff with sighold/sigrelse
e
s 00001/00001/00811
d D 1.2 81/01/12 16:30:13 kas 2 1
c now calls execute with 2nd parameter to indicate from collect
e
s 00812/00000/00000
d D 1.1 80/10/08 09:49:33 kas 1 0
c date and time created 80/10/08 09:49:33 by kas
e
u
U
f b 
t
T
I 27
/*
 * Copyright (c) 1980 Regents of the University of California.
D 32
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 32
I 32
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 32
 */

E 27
I 1
D 23
#
E 23
I 23
D 32
#ifndef lint
D 28
static char sccsid[] = "%W% (Berkeley) %G%";
E 28
I 28
static char *sccsid = "%W% (Berkeley) %G%";
E 28
D 27
#endif
E 27
I 27
#endif not lint
E 32
I 32
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 32
E 27
E 23

/*
 * Mail -- a mail program
 *
 * Collect input from standard input, handling
 * ~ escapes.
 */
D 23

static char *SccsId = "%W% %G%";
E 23

#include "rcv.h"
#include <sys/stat.h>
I 29
#include <sys/wait.h>
E 29

/*
 * Read a message from standard output and return a read file to it
 * or NULL on error.
 */

/*
 * The following hokiness with global variables is so that on
 * receipt of an interrupt signal, the partial message can be salted
D 29
 * away on dead.letter.  The output file must be available to flush,
 * and the input to read.  Several open files could be saved all through
 * Mail if stdio allowed simultaneous read/write access.
E 29
I 29
 * away on dead.letter.
E 29
 */

D 29
static	int	(*savesig)();		/* Previous SIGINT value */
E 29
I 29
static	int	(*saveint)();		/* Previous SIGINT value */
E 29
I 3
static	int	(*savehup)();		/* Previous SIGHUP value */
I 15
D 29
# ifdef VMUNIX
E 29
E 15
I 4
static	int	(*savecont)();		/* Previous SIGCONT value */
I 15
D 29
# endif VMUNIX
E 15
E 4
E 3
static	FILE	*newi;			/* File for saving away */
static	FILE	*newo;			/* Output side of same */
static	int	hf;			/* Ignore interrups */
E 29
I 29
static	FILE	*collf;			/* File for saving away */
E 29
D 3
static	int	nofault;		/* Soft signal if set */
E 3
static	int	hadintr;		/* Have seen one SIGINT so far */

static	jmp_buf	coljmp;			/* To get back to work */

FILE *
collect(hp)
	struct header *hp;
{
D 29
	FILE *ibuf, *fbuf, *obuf;
D 3
	int lc, cc, escape, collrub(), intack(), stopdot;
E 3
I 3
D 4
	int lc, cc, escape, collrub(), intack(), stopdot, collhup;
E 4
I 4
D 8
	int lc, cc, escape, collrub(), intack(), stopdot, collhup, collcont();
E 8
I 8
	int lc, cc, escape, collrub(), intack(), collhup, collcont(), eof;
E 29
I 29
	FILE *fp, *fbuf;
	int lc, cc, escape, eof;
	int collrub(), intack(), collcont();
E 29
E 8
E 4
E 3
	register int c, t;
	char linebuf[LINESIZE], *cp;
	extern char tempMail[];
I 6
	int notify();
I 15
D 29
	extern collintsig(), collhupsig();
E 29
I 24
	char getsub;
I 29
	int omask;
E 29
E 24
E 15
E 6

	noreset++;
D 8
	stopdot = (value("dot") != NOSTR) && intty;
E 8
D 29
	ibuf = obuf = NULL;
	if (value("ignore") != NOSTR)
		hf = 1;
	else
		hf = 0;
D 3
	nofault = 1;
E 3
	hadintr = 0;
I 15
# ifdef VMUNIX
E 15
D 3
	if ((savesig = signal(SIGINT, SIG_IGN)) != SIG_IGN)
		signal(SIGINT, hf ? intack : collrub);
E 3
I 3
	if ((savesig = sigset(SIGINT, SIG_IGN)) != SIG_IGN)
D 22
		sigset(SIGINT, hf ? intack : collrub), sighold(SIGINT);
E 22
I 22
D 26
		sigset(SIGINT, hf ? intack : collrub), sigblock(mask(SIGINT));
E 26
I 26
		sigset(SIGINT, hf ? intack : collrub), sigblock(sigmask(SIGINT));
E 26
E 22
	if ((savehup = sigset(SIGHUP, SIG_IGN)) != SIG_IGN)
D 15
		sigset(SIGHUP, collrub), sighold(SIGINT);
E 15
I 15
D 22
		sigset(SIGHUP, collrub), sighold(SIGHUP);
E 22
I 22
D 26
		sigset(SIGHUP, collrub), sigblock(mask(SIGHUP));
E 26
I 26
		sigset(SIGHUP, collrub), sigblock(sigmask(SIGHUP));
E 26
E 22
E 15
I 4
	savecont = sigset(SIGCONT, collcont);
I 15
# else VMUNIX
	savesig = signal(SIGINT, SIG_IGN);
	savehup = signal(SIGHUP, SIG_IGN);
# endif VMUNIX
E 15
E 4
E 3
	newi = NULL;
	newo = NULL;
	if ((obuf = fopen(tempMail, "w")) == NULL) {
		perror(tempMail);
E 29
I 29
	fp = NULL;
	collf = NULL;

	/*
	 * Start catching signals from here, but we're still die on interrupts
	 * until we're in the main loop.
	 */
	omask = sigblock(sigmask(SIGINT) | sigmask(SIGHUP));
	if ((saveint = signal(SIGINT, SIG_IGN)) != SIG_IGN)
		signal(SIGINT, value("ignore") != NOSTR ? intack : collrub);
	if ((savehup = signal(SIGHUP, SIG_IGN)) != SIG_IGN)
		signal(SIGHUP, collrub);
	savecont = signal(SIGCONT, SIG_DFL);
	if (setjmp(coljmp)) {
		remove(tempMail);
E 29
		goto err;
	}
D 29
	newo = obuf;
	if ((ibuf = fopen(tempMail, "r")) == NULL) {
E 29
I 29
	sigsetmask(omask & ~(sigmask(SIGINT) | sigmask(SIGHUP)));

	if ((fp = fopen(tempMail, "w+")) == NULL) {
E 29
		perror(tempMail);
D 29
		newo = NULL;
		fclose(obuf);
E 29
		goto err;
	}
D 29
	newi = ibuf;
E 29
I 29
	collf = fp;
E 29
	remove(tempMail);

	/*
	 * If we are going to prompt for a subject,
	 * refrain from printing a newline after
	 * the headers (since some people mind).
	 */
D 29

E 29
	t = GTO|GSUBJECT|GCC|GNL;
D 24
	c = 0;
E 24
I 24
	getsub = 0;
E 24
	if (intty && sflag == NOSTR && hp->h_subject == NOSTR && value("ask"))
D 24
		t &= ~GNL, c++;
E 24
I 24
		t &= ~GNL, getsub++;
E 24
	if (hp->h_seq != 0) {
		puthead(hp, stdout, t);
		fflush(stdout);
	}
D 24
	if (c)
		grabh(hp, GSUBJECT);
E 24
	escape = ESCAPE;
	if ((cp = value("escape")) != NOSTR)
		escape = *cp;
I 8
	eof = 0;
E 8
D 29
	for (;;) {
I 22
D 26
		int omask = sigblock(0) &~ (mask(SIGINT)|mask(SIGHUP));
E 26
I 26
		int omask = sigblock(0) &~ (sigmask(SIGINT)|sigmask(SIGHUP));
E 29
I 29
	hadintr = 0;
E 29
E 26

E 22
D 29
		setjmp(coljmp);
I 15
# ifdef VMUNIX
E 15
D 3
		nofault = 0;
E 3
I 3
D 22
		sigrelse(SIGINT);
		sigrelse(SIGHUP);
E 22
I 22
		sigsetmask(omask);
E 22
I 15
# else VMUNIX
		if (savesig != SIG_IGN)
			signal(SIGINT, hf ? intack : collintsig);
		if (savehup != SIG_IGN)
			signal(SIGHUP, collhupsig);
# endif VMUNIX
E 15
E 3
D 25
		flush();
E 25
I 25
		fflush(stdout);
E 25
I 24
		if (getsub) {
E 29
I 29
	/*
	 * We can put the setjmp here because register variable
	 * needs to be saved in the loop.
	 */
	if (!setjmp(coljmp)) {
		signal(SIGCONT, collcont);
		if (getsub)
E 29
			grabh(hp, GSUBJECT);
D 29
			getsub = 0;
			continue;
E 29
I 29
	} else {
		/*
		 * Come here for printing the after-signal message.
		 * Duplicate messages won't be printed because
		 * the write is aborted if we get a SIGTTOU.
		 */
cont:
		if (hadintr) {
			fflush(stdout);
			fprintf(stderr,
			"\n(Interrupt -- one more to kill letter)\n");
		} else {
			printf("(continue)\n");
			fflush(stdout);
E 29
		}
E 24
D 8
		if (readline(stdin, linebuf) <= 0)
E 8
I 8
D 29
		if (readline(stdin, linebuf) <= 0) {
E 29
I 29
	}
	for (;;) {
		if (readline(stdin, linebuf) < 0) {
E 29
			if (intty && value("ignoreeof") != NOSTR) {
				if (++eof > 35)
					break;
D 9
				printf("Use \"%cq\" to terminate letter\n",
E 9
I 9
D 29
				printf("Use \".\" to terminate letter\n",
E 9
				    escape);
E 29
I 29
				printf("Use \".\" to terminate letter\n");
E 29
				continue;
			}
E 8
			break;
I 8
		}
		eof = 0;
E 8
		hadintr = 0;
D 8
		if (stopdot && equal(".", linebuf))
E 8
I 8
D 10
		if (intty && equal(".", linebuf) && value("dot") != NOSTR)
E 10
I 10
		if (intty && equal(".", linebuf) &&
		    (value("dot") != NOSTR || value("ignoreeof") != NOSTR))
E 10
E 8
			break;
D 5
		if (linebuf[0] != escape ||
		    (!intty && value("henry") == NOSTR)) {
E 5
I 5
		if (linebuf[0] != escape || rflag != NOSTR) {
E 5
D 29
			if ((t = putline(obuf, linebuf)) < 0)
E 29
I 29
			if (putline(fp, linebuf) < 0)
E 29
				goto err;
			continue;
		}
		c = linebuf[1];
D 3
		nofault= 0;
E 3
		switch (c) {
		default:
			/*
			 * On double escape, just send the single one.
			 * Otherwise, it's an error.
			 */

			if (c == escape) {
D 29
				if (putline(obuf, &linebuf[1]) < 0)
E 29
I 29
				if (putline(fp, &linebuf[1]) < 0)
E 29
					goto err;
				else
					break;
			}
			printf("Unknown tilde escape.\n");
			break;

		case 'C':
			/*
			 * Dump core.
			 */

			core();
			break;

		case '!':
			/*
			 * Shell escape, send the balance of the
			 * line to sh -c.
			 */

			shell(&linebuf[2]);
			break;

		case ':':
		case '_':
			/*
			 * Escape to command mode, but be nice!
			 */

D 3
			nofault = 0;
E 3
D 2
			execute(&linebuf[2]);
E 2
I 2
			execute(&linebuf[2], 1);
I 19
D 29
			printf("(continue)\n");
E 19
E 2
			break;
E 29
I 29
			goto cont;
E 29

		case '.':
			/*
			 * Simulate end of file on input.
			 */
D 15
			goto eof;
E 15
I 15
D 29
			goto eofl;
E 29
I 29
			goto out;
E 29
E 15

		case 'q':
		case 'Q':
			/*
			 * Force a quit of sending mail.
			 * Act like an interrupt happened.
			 */

D 3
			nofault = 0;
E 3
			hadintr++;
			collrub(SIGINT);
			exit(1);

		case 'h':
			/*
			 * Grab a bunch of headers.
			 */
			if (!intty || !outtty) {
				printf("~h: no can do!?\n");
				break;
			}
			grabh(hp, GTO|GSUBJECT|GCC|GBCC);
D 29
			printf("(continue)\n");
			break;
E 29
I 29
			goto cont;
E 29

		case 't':
			/*
			 * Add to the To list.
			 */

			hp->h_to = addto(hp->h_to, &linebuf[2]);
			hp->h_seq++;
			break;

		case 's':
			/*
			 * Set the Subject list.
			 */

			cp = &linebuf[2];
D 29
			while (any(*cp, " \t"))
E 29
I 29
			while (isspace(*cp))
E 29
				cp++;
			hp->h_subject = savestr(cp);
			hp->h_seq++;
			break;

		case 'c':
			/*
			 * Add to the CC list.
			 */

			hp->h_cc = addto(hp->h_cc, &linebuf[2]);
			hp->h_seq++;
			break;

		case 'b':
			/*
			 * Add stuff to blind carbon copies list.
			 */
			hp->h_bcc = addto(hp->h_bcc, &linebuf[2]);
			hp->h_seq++;
			break;

		case 'd':
D 29
			copy(deadletter, &linebuf[2]);
E 29
I 29
			strcpy(linebuf + 2, deadletter);
E 29
			/* fall into . . . */

		case 'r':
			/*
			 * Invoke a file:
			 * Search for the file name,
D 29
			 * then open it and copy the contents to obuf.
E 29
I 29
			 * then open it and copy the contents to fp.
E 29
			 */

			cp = &linebuf[2];
D 29
			while (any(*cp, " \t"))
E 29
I 29
			while (isspace(*cp))
E 29
				cp++;
			if (*cp == '\0') {
				printf("Interpolate what file?\n");
				break;
			}
			cp = expand(cp);
			if (cp == NOSTR)
				break;
			if (isdir(cp)) {
D 29
				printf("%s: directory\n");
E 29
I 29
				printf("%s: Directory\n", cp);
E 29
				break;
			}
			if ((fbuf = fopen(cp, "r")) == NULL) {
				perror(cp);
				break;
			}
			printf("\"%s\" ", cp);
D 25
			flush();
E 25
I 25
			fflush(stdout);
E 25
			lc = 0;
			cc = 0;
D 29
			while (readline(fbuf, linebuf) > 0) {
E 29
I 29
			while (readline(fbuf, linebuf) >= 0) {
E 29
				lc++;
D 29
				if ((t = putline(obuf, linebuf)) < 0) {
E 29
I 29
				if ((t = putline(fp, linebuf)) < 0) {
E 29
					fclose(fbuf);
					goto err;
				}
				cc += t;
			}
			fclose(fbuf);
			printf("%d/%d\n", lc, cc);
			break;

		case 'w':
			/*
			 * Write the message on a file.
			 */

			cp = &linebuf[2];
			while (any(*cp, " \t"))
				cp++;
			if (*cp == '\0') {
				fprintf(stderr, "Write what file!?\n");
				break;
			}
			if ((cp = expand(cp)) == NOSTR)
				break;
D 29
			fflush(obuf);
			rewind(ibuf);
			exwrite(cp, ibuf, 1);
E 29
I 29
			rewind(fp);
			exwrite(cp, fp, 1);
E 29
			break;

		case 'm':
		case 'f':
			/*
			 * Interpolate the named messages, if we
			 * are in receiving mail mode.  Does the
			 * standard list processing garbage.
			 * If ~f is given, we don't shift over.
			 */

			if (!rcvmode) {
				printf("No messages to send from!?!\n");
				break;
			}
			cp = &linebuf[2];
			while (any(*cp, " \t"))
				cp++;
D 29
			if (forward(cp, obuf, c) < 0)
E 29
I 29
			if (forward(cp, fp, c) < 0)
E 29
				goto err;
D 29
			printf("(continue)\n");
			break;
E 29
I 29
			goto cont;
E 29

		case '?':
D 3
			nofault = 0;
E 3
			if ((fbuf = fopen(THELPFILE, "r")) == NULL) {
D 21
				printf("No help just now.\n");
E 21
I 21
				perror(THELPFILE);
E 21
				break;
			}
D 29
			t = getc(fbuf);
			while (t != -1) {
E 29
I 29
D 31
			while ((t = getc(fp)) != EOF)
E 31
I 31
			while ((t = getc(fbuf)) != EOF)
E 31
E 29
				putchar(t);
D 29
				t = getc(fbuf);
			}
E 29
			fclose(fbuf);
			break;

		case 'p':
			/*
			 * Print out the current state of the
			 * message without altering anything.
			 */

D 29
			fflush(obuf);
			rewind(ibuf);
E 29
I 29
			rewind(fp);
E 29
D 3
			nofault = 0;
E 3
			printf("-------\nMessage contains:\n");
			puthead(hp, stdout, GTO|GSUBJECT|GCC|GBCC|GNL);
D 29
			t = getc(ibuf);
			while (t != EOF) {
E 29
I 29
			while ((t = getc(fp)) != EOF)
E 29
				putchar(t);
D 29
				t = getc(ibuf);
			}
			printf("(continue)\n");
			break;
E 29
I 29
			goto cont;
E 29

		case '^':
		case '|':
			/*
			 * Pipe message through command.
			 * Collect output as new message.
			 */

D 29
			obuf = mespipe(ibuf, obuf, &linebuf[2]);
			newo = obuf;
			ibuf = newi;
			newi = ibuf;
			printf("(continue)\n");
			break;
E 29
I 29
			rewind(fp);
			fp = mespipe(fp, &linebuf[2]);
			goto cont;
E 29

		case 'v':
		case 'e':
			/*
			 * Edit the current message.
			 * 'e' means to use EDITOR
			 * 'v' means to use VISUAL
			 */

D 29
			if ((obuf = mesedit(ibuf, obuf, c)) == NULL)
E 29
I 29
			rewind(fp);
			if ((fp = mesedit(fp, c)) == NULL)
E 29
				goto err;
D 29
			newo = obuf;
			ibuf = newi;
			printf("(continue)\n");
D 24
			break;
E 24
			break;
E 29
I 29
			goto cont;
E 29
		}
	}
D 15
eof:
E 15
I 15
D 29
eofl:
E 15
	fclose(obuf);
	rewind(ibuf);
D 3
	signal(SIGINT, savesig);
E 3
I 3
	sigset(SIGINT, savesig);
	sigset(SIGHUP, savehup);
I 15
# ifdef VMUNIX
E 15
I 6
	sigset(SIGCONT, savecont);
I 22
	sigsetmask(0);
E 22
I 15
# endif VMUNIX
E 15
E 6
E 3
	noreset = 0;
	return(ibuf);

E 29
I 29
	goto out;
E 29
err:
D 29
	if (ibuf != NULL)
		fclose(ibuf);
	if (obuf != NULL)
		fclose(obuf);
D 3
	signal(SIGINT, savesig);
E 3
I 3
	sigset(SIGINT, savesig);
	sigset(SIGHUP, savehup);
I 15
# ifdef VMUNIX
E 15
I 4
	sigset(SIGCONT, savecont);
I 22
	sigsetmask(0);
E 22
I 15
# endif VMUNIX
E 29
I 29
	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}
out:
	if (fp != NULL)
		rewind(fp);
	signal(SIGINT, saveint);
	signal(SIGHUP, savehup);
	signal(SIGCONT, savecont);
	sigsetmask(omask);
E 29
E 15
E 4
E 3
	noreset = 0;
D 29
	return(NULL);
E 29
I 29
	return(fp);
E 29
}

/*
D 29
 * Non destructively interrogate the value of the given signal.
 */

psig(n)
{
	register (*wassig)();

D 3
	wassig = signal(n, SIG_IGN);
	signal(n, wassig);
E 3
I 3
	wassig = sigset(n, SIG_IGN);
	sigset(n, wassig);
E 3
	return((int) wassig);
}

/*
E 29
 * Write a file, ex-like if f set.
 */

D 29
exwrite(name, ibuf, f)
E 29
I 29
exwrite(name, fp, f)
E 29
	char name[];
D 29
	FILE *ibuf;
E 29
I 29
	FILE *fp;
E 29
{
	register FILE *of;
	register int c;
	long cc;
	int lc;
	struct stat junk;

	if (f) {
		printf("\"%s\" ", name);
		fflush(stdout);
	}
D 12
	if (stat(name, &junk) >= 0) {
E 12
I 12
	if (stat(name, &junk) >= 0 && (junk.st_mode & S_IFMT) == S_IFREG) {
E 12
		if (!f)
			fprintf(stderr, "%s: ", name);
D 29
		fprintf(stderr, "File exists\n", name);
E 29
I 29
		fprintf(stderr, "File exists\n");
E 29
		return(-1);
	}
	if ((of = fopen(name, "w")) == NULL) {
		perror(NOSTR);
		return(-1);
	}
	lc = 0;
	cc = 0;
D 29
	while ((c = getc(ibuf)) != EOF) {
E 29
I 29
	while ((c = getc(fp)) != EOF) {
E 29
		cc++;
		if (c == '\n')
			lc++;
		putc(c, of);
		if (ferror(of)) {
			perror(name);
			fclose(of);
			return(-1);
		}
	}
	fclose(of);
	printf("%d/%ld\n", lc, cc);
	fflush(stdout);
	return(0);
}

/*
D 29
 * Edit the message being collected on ibuf and obuf.
E 29
I 29
 * Edit the message being collected on fp.
E 29
 * Write the message out onto some poorly-named temp file
 * and point an editor at it.
 *
 * On return, make the edit file the new temp file.
 */

FILE *
D 29
mesedit(ibuf, obuf, c)
	FILE *ibuf, *obuf;
E 29
I 29
mesedit(fp, c)
	FILE *fp;
E 29
{
D 29
	int pid, s;
E 29
I 29
	int pid;
	union wait s;
E 29
	FILE *fbuf;
	register int t;
D 6
	int (*sig)();
E 6
I 6
D 20
	int (*sig)(), (*scont)(), foonly();
E 20
I 20
D 29
	int (*sig)(), (*scont)(), signull();
E 29
I 29
	int (*sigint)(), (*sigcont)();
E 29
E 20
E 6
	struct stat sbuf;
D 30
	extern char tempMail[], tempEdit[];
E 30
I 30
	extern char tempEdit[];
E 30
	register char *edit;

D 3
	sig = signal(SIGINT, SIG_IGN);
E 3
I 3
D 29
	sig = sigset(SIGINT, SIG_IGN);
I 15
# ifdef VMUNIX
E 15
I 6
D 20
	scont = sigset(SIGCONT, foonly);
E 20
I 20
	scont = sigset(SIGCONT, signull);
E 20
I 15
# endif VMUNIX
E 29
I 29
	sigint = signal(SIGINT, SIG_IGN);
	sigcont = signal(SIGCONT, SIG_DFL);
E 29
E 15
E 6
E 3
	if (stat(tempEdit, &sbuf) >= 0) {
		printf("%s: file exists\n", tempEdit);
		goto out;
	}
	close(creat(tempEdit, 0600));
	if ((fbuf = fopen(tempEdit, "w")) == NULL) {
		perror(tempEdit);
		goto out;
	}
D 29
	fflush(obuf);
	rewind(ibuf);
	t = getc(ibuf);
	while (t != EOF) {
E 29
I 29
	while ((t = getc(fp)) != EOF)
E 29
		putc(t, fbuf);
D 29
		t = getc(ibuf);
	}
E 29
	fflush(fbuf);
	if (ferror(fbuf)) {
		perror(tempEdit);
		remove(tempEdit);
		goto fix;
	}
	fclose(fbuf);
	if ((edit = value(c == 'e' ? "EDITOR" : "VISUAL")) == NOSTR)
		edit = c == 'e' ? EDITOR : VISUAL;
	pid = vfork();
	if (pid == 0) {
I 17
D 29
		sigchild();
E 17
		if (sig != SIG_IGN)
D 3
			signal(SIGINT, SIG_DFL);
E 3
I 3
			sigsys(SIGINT, SIG_DFL);
E 29
I 29
		if (sigint != SIG_IGN)
			signal(SIGINT, SIG_DFL);
E 29
E 3
		execl(edit, edit, tempEdit, 0);
		perror(edit);
		_exit(1);
	}
	if (pid == -1) {
		perror("fork");
		remove(tempEdit);
		goto out;
	}
	while (wait(&s) != pid)
		;
D 13
	if (s != 0) {
E 13
I 13
D 29
	if ((s & 0377) != 0) {
E 29
I 29
	if (s.w_status != 0) {
E 29
E 13
		printf("Fatal error in \"%s\"\n", edit);
		remove(tempEdit);
		goto out;
	}

	/*
	 * Now switch to new file.
	 */

D 29
	if ((fbuf = fopen(tempEdit, "a")) == NULL) {
E 29
I 29
	if ((fbuf = fopen(tempEdit, "a+")) == NULL) {
E 29
		perror(tempEdit);
		remove(tempEdit);
		goto out;
	}
D 29
	if ((ibuf = fopen(tempEdit, "r")) == NULL) {
		perror(tempEdit);
		fclose(fbuf);
		remove(tempEdit);
		goto out;
	}
E 29
	remove(tempEdit);
D 29
	fclose(obuf);
	fclose(newi);
	obuf = fbuf;
E 29
I 29
	collf = fbuf;
	fclose(fp);
	fp = fbuf;
E 29
	goto out;
fix:
	perror(tempEdit);
out:
I 15
D 29
# ifdef VMUNIX
E 15
I 6
	sigset(SIGCONT, scont);
I 15
# endif VMUNIX
E 15
E 6
D 3
	signal(SIGINT, sig);
E 3
I 3
	sigset(SIGINT, sig);
E 3
	newi = ibuf;
	return(obuf);
E 29
I 29
	signal(SIGCONT, sigcont);
	signal(SIGINT, sigint);
	return(fp);
E 29
}

/*
I 6
D 20
 * Currently, Berkeley virtual VAX/UNIX will not let you change the
 * disposition of SIGCONT, except to trap it somewhere new.
 * Hence, sigset(SIGCONT, foonly) is used to ignore continue signals.
 */
foonly() {}

/*
E 20
E 6
 * Pipe the message through the command.
 * Old message is on stdin of command;
 * New message collected from stdout.
 * Sh -c must return 0 to accept the new message.
 */

FILE *
D 29
mespipe(ibuf, obuf, cmd)
	FILE *ibuf, *obuf;
E 29
I 29
mespipe(fp, cmd)
	FILE *fp;
E 29
	char cmd[];
{
I 30
	extern char tempEdit[];
E 30
D 29
	register FILE *ni, *no;
	int pid, s;
	int (*savesig)();
E 29
I 29
	register FILE *nf;
	int pid;
	union wait s;
	int (*saveint)();
E 29
	char *Shell;

D 29
	newi = ibuf;
	if ((no = fopen(tempEdit, "w")) == NULL) {
E 29
I 29
	if ((nf = fopen(tempEdit, "w+")) == NULL) {
E 29
		perror(tempEdit);
D 29
		return(obuf);
E 29
I 29
		return(fp);
E 29
	}
D 29
	if ((ni = fopen(tempEdit, "r")) == NULL) {
		perror(tempEdit);
		fclose(no);
		remove(tempEdit);
		return(obuf);
	}
E 29
	remove(tempEdit);
D 3
	savesig = signal(SIGINT, SIG_IGN);
E 3
I 3
D 29
	savesig = sigset(SIGINT, SIG_IGN);
E 3
	fflush(obuf);
	rewind(ibuf);
E 29
I 29
	saveint = signal(SIGINT, SIG_IGN);
E 29
	if ((Shell = value("SHELL")) == NULL)
		Shell = "/bin/sh";
	if ((pid = vfork()) == -1) {
		perror("fork");
		goto err;
	}
	if (pid == 0) {
I 29
		int fd;
E 29
		/*
		 * stdin = current message.
		 * stdout = new message.
		 */

I 17
D 29
		sigchild();
E 29
E 17
		close(0);
D 29
		dup(fileno(ibuf));
E 29
I 29
		dup(fileno(fp));
E 29
		close(1);
D 29
		dup(fileno(no));
		for (s = 4; s < 15; s++)
			close(s);
E 29
I 29
		dup(fileno(nf));
		for (fd = getdtablesize(); --fd > 2;)
			close(fd);
E 29
		execl(Shell, Shell, "-c", cmd, 0);
		perror(Shell);
		_exit(1);
	}
	while (wait(&s) != pid)
		;
D 29
	if (s != 0 || pid == -1) {
E 29
I 29
	if (s.w_status != 0 || pid == -1) {
E 29
		fprintf(stderr, "\"%s\" failed!?\n", cmd);
		goto err;
	}
D 29
	if (fsize(ni) == 0) {
E 29
I 29
	if (fsize(nf) == 0) {
E 29
		fprintf(stderr, "No bytes from \"%s\" !?\n", cmd);
		goto err;
	}

	/*
	 * Take new files.
	 */

D 29
	newi = ni;
	fclose(ibuf);
	fclose(obuf);
D 3
	signal(SIGINT, savesig);
E 3
I 3
	sigset(SIGINT, savesig);
E 3
	return(no);
E 29
I 29
	fseek(nf, 0L, 2);
	collf = nf;
	fclose(fp);
	signal(SIGINT, saveint);
	return(nf);
E 29

err:
D 29
	fclose(no);
	fclose(ni);
D 3
	signal(SIGINT, savesig);
E 3
I 3
	sigset(SIGINT, savesig);
E 3
	return(obuf);
E 29
I 29
	fclose(nf);
	signal(SIGINT, saveint);
	return(fp);
E 29
}

/*
 * Interpolate the named messages into the current
 * message, preceding each line with a tab.
 * Return a count of the number of characters now in
 * the message, or -1 if an error is encountered writing
 * the message temporary.  The flag argument is 'm' if we
 * should shift over and 'f' if not.
I 33
 *
 * We can automatically convert interpolated messages to KOI-8:
 * they are used in composing new messages and composing/editing
 * is much more convenient and reliable in KOI-8. Of course
 * when the new message is sent it'll be converted back to KOI-7.
E 33
 */
D 18

E 18
D 29
forward(ms, obuf, f)
E 29
I 29
forward(ms, fp, f)
E 29
	char ms[];
D 29
	FILE *obuf;
E 29
I 29
	FILE *fp;
E 29
{
	register int *msgvec, *ip;
	extern char tempMail[];

	msgvec = (int *) salloc((msgCount+1) * sizeof *msgvec);
	if (msgvec == (int *) NOSTR)
		return(0);
	if (getmsglist(ms, msgvec, 0) < 0)
		return(0);
	if (*msgvec == NULL) {
		*msgvec = first(0, MMNORM);
		if (*msgvec == NULL) {
			printf("No appropriate messages\n");
			return(0);
		}
		msgvec[1] = NULL;
	}
	printf("Interpolating:");
	for (ip = msgvec; *ip != NULL; ip++) {
		touch(*ip);
		printf(" %d", *ip);
D 33
		if (f == 'm') {
D 20
			if (transmit(&message[*ip-1], obuf) < 0) {
E 20
I 20
D 29
			if (transmit(&message[*ip-1], obuf) < 0L) {
E 29
I 29
			if (transmit(&message[*ip-1], fp) < 0L) {
E 29
E 20
				perror(tempMail);
				return(-1);
			}
		} else
D 18
			if (send(&message[*ip-1], obuf) < 0) {
E 18
I 18
D 29
			if (send(&message[*ip-1], obuf, 0) < 0) {
E 29
I 29
			if (send(&message[*ip-1], fp, 0) < 0) {
E 29
E 18
				perror(tempMail);
				return(-1);
			}
E 33
I 33
		if (transmit(&message[*ip-1], fp, f == 'm') < 0L) {
			perror(tempMail);
			return(-1);
		}
E 33
	}
	printf("\n");
	return(0);
}

/*
 * Send message described by the passed pointer to the
 * passed output buffer.  Insert a tab in front of each
 * line.  Return a count of the characters sent, or -1
 * on error.
 */

I 20
long
E 20
D 29
transmit(mailp, obuf)
E 29
I 29
D 33
transmit(mailp, fp)
E 33
I 33
transmit(mailp, fp, instab)
E 33
E 29
	struct message *mailp;
D 29
	FILE *obuf;
E 29
I 29
D 33
	FILE *fp;
E 33
I 33
	register FILE *fp;
	register int instab;
E 33
E 29
{
D 33
	register struct message *mp;
E 33
I 33
	struct message *mp;
E 33
D 20
	register int c, ch;
	int n, bol;
E 20
I 20
	register int ch;
	long c, n;
D 33
	int bol;
E 20
	FILE *ibuf;
E 33
I 33
	register int bol, rus;
	register FILE *ibuf;
	int koi8;
E 33

	mp = mailp;
	ibuf = setinput(mp);
D 20
	c = msize(mp);
E 20
I 20
	c = mp->m_size;
E 20
	n = c;
D 33
	bol = 1;
E 33
I 33
	bol = 1, rus = 0;
	koi8 = value("koi8edit") != NOSTR;
E 33
D 20
	while (c-- > 0) {
E 20
I 20
	while (c-- > 0L) {
E 20
D 29
		if (bol) {
E 29
I 29
		ch = getc(ibuf);
I 33
		if (ch == '\016' && koi8) {
			rus = 1;
			n--;
			continue;
		}
		if (ch == '\017' && koi8) {
			rus = 0;
			n--;
			continue;
		}
		if (ch >= 0100 && ch <= 0177 && rus)
			ch |= 0200;
E 33
		if (ch == '\n')
			bol = 1;
		else if (bol) {
E 29
			bol = 0;
D 29
			putc('\t', obuf);
E 29
I 29
D 33
			putc('\t', fp);
E 29
			n++;
E 33
I 33
			if (instab) {
				putc('\t', fp);
				n++;
			}
E 33
D 29
			if (ferror(obuf)) {
				perror("/tmp");
D 20
				return(-1);
E 20
I 20
				return(-1L);
E 20
			}
E 29
		}
D 29
		ch = getc(ibuf);
		if (ch == '\n')
			bol++;
		putc(ch, obuf);
		if (ferror(obuf)) {
E 29
I 29
		putc(ch, fp);
		if (ferror(fp)) {
E 29
			perror("/tmp");
D 20
			return(-1);
E 20
I 20
			return(-1L);
E 20
		}
	}
	return(n);
}

/*
I 4
 * Print (continue) when continued after ^Z.
 */
I 29
/*ARGSUSED*/
E 29
collcont(s)
{

D 29
	printf("(continue)\n");
	fflush(stdout);
E 29
I 29
	hadintr = 0;
	longjmp(coljmp, 1);
E 29
}

/*
E 4
 * On interrupt, go here to save the partial
D 3
 * message on #/dead.letter.
E 3
I 3
 * message on ~/dead.letter.
E 3
 * Then restore signals and execute the normal
 * signal routine.  We only come here if signals
 * were previously set anyway.
 */

I 15
D 29
# ifndef VMUNIX
collintsig()
{
	signal(SIGINT, SIG_IGN);
	collrub(SIGINT);
}

collhupsig()
{
	signal(SIGHUP, SIG_IGN);
	collrub(SIGHUP);
}
# endif VMUNIX

E 29
E 15
collrub(s)
{
	register FILE *dbuf;
	register int c;

I 4
D 6
	if (s == SIGINT)
		sigset(SIGCONT, collrub);
E 6
E 4
D 3
#ifdef V7
	signal(s, SIG_IGN);
#else
	signal(SIGINT, SIG_IGN);
#endif
	if (nofault) {
#ifdef V7
		signal(s, collrub);
#else
		signal(SIGINT, collrub);
#endif
		return;
	}
	if (hadintr == 0) {
E 3
I 3
	if (s == SIGINT && hadintr == 0) {
E 3
D 29
		hadintr++;
D 25
		clrbuf(stdout);
		printf("\n(Interrupt -- one more to kill letter)\n");
E 25
I 25
		fflush(stdout);
		fprintf(stderr, "\n(Interrupt -- one more to kill letter)\n");
E 29
I 29
		hadintr = 1;
E 29
E 25
I 15
D 22
# ifdef VMUNIX
E 15
D 3
#ifdef V7
		signal(s, collrub);
#else
		signal(SIGINT, collrub);
#endif
E 3
I 3
D 6
		sigset(s, collrub);
E 6
I 6
		sigrelse(s);
I 15
# endif VMUNIX
E 22
E 15
E 6
E 3
		longjmp(coljmp, 1);
	}
D 29
	fclose(newo);
	rewind(newi);
D 3
	if (value("nosave") != NOSTR || fsize(newi) == 0)
E 3
I 3
	if (s == SIGINT && value("nosave") != NOSTR || fsize(newi) == 0)
E 29
I 29
	rewind(collf);
	if (s == SIGINT && value("nosave") != NOSTR || fsize(collf) == 0)
E 29
E 3
		goto done;
	if ((dbuf = fopen(deadletter, "w")) == NULL)
		goto done;
	chmod(deadletter, 0600);
D 29
	while ((c = getc(newi)) != EOF)
E 29
I 29
	while ((c = getc(collf)) != EOF)
E 29
		putc(c, dbuf);
	fclose(dbuf);

done:
D 29
	fclose(newi);
D 3
	signal(SIGINT, savesig);
	if (rcvmode)
		stop();
E 3
I 3
	sigset(SIGINT, savesig);
	sigset(SIGHUP, savehup);
I 15
# ifdef VMUNIX
E 15
I 4
	sigset(SIGCONT, savecont);
I 15
# endif VMUNIX
E 29
I 29
	fclose(collf);
	signal(SIGINT, saveint);
	signal(SIGHUP, savehup);
	signal(SIGCONT, savecont);
E 29
E 15
E 4
	if (rcvmode) {
		if (s == SIGHUP)
			hangup(SIGHUP);
		else
D 4
			stop();
E 4
I 4
			stop(s);
E 4
D 29
	}
E 3
	else
E 29
I 29
	} else
E 29
		exit(1);
}

/*
 * Acknowledge an interrupt signal from the tty by typing an @
 */

I 29
/*ARGSUSED*/
E 29
intack(s)
{
D 29
	
E 29
I 29

E 29
I 4
D 11
	sigrelse(SIGCONT);
E 11
E 4
D 3
	signal(SIGINT, SIG_IGN);
E 3
	puts("@");
	fflush(stdout);
	clearerr(stdin);
D 3
	signal(SIGINT, intack);
E 3
}

/*
 * Add a string to the end of a header entry field.
 */

char *
addto(hf, news)
	char hf[], news[];
{
	register char *cp, *cp2, *linebuf;

	if (hf == NOSTR)
		hf = "";
	if (*news == '\0')
		return(hf);
	linebuf = salloc(strlen(hf) + strlen(news) + 2);
	for (cp = hf; any(*cp, " \t"); cp++)
		;
	for (cp2 = linebuf; *cp;)
		*cp2++ = *cp++;
	*cp2++ = ' ';
	for (cp = news; any(*cp, " \t"); cp++)
		;
	while (*cp != '\0')
		*cp2++ = *cp++;
	*cp2 = '\0';
	return(linebuf);
}
E 1
