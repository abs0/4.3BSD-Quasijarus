h34361
s 00011/00005/00213
d D 5.5 88/02/18 17:04:29 bostic 17 16
c written by Kurt Shoens; added Berkeley specific header
e
s 00001/00002/00217
d D 5.4 88/01/02 22:37:10 bostic 16 15
c fix extern declarations for ANSI C
e
s 00014/00030/00205
d D 5.3 87/05/18 12:28:47 edward 15 14
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00001/00001/00234
d D 5.2 85/06/21 17:14:31 mckusick 14 13
c botched copyright
e
s 00007/00001/00228
d D 5.1 85/06/06 10:44:53 dist 13 12
c Add copyright
e
s 00003/00003/00226
d D 2.7 83/08/11 22:20:20 sam 12 11
c standardize sccs keyword lines
e
s 00001/00000/00228
d D 2.6 83/07/26 17:55:41 sam 11 10
c stdio and tty's require clearerr to insure EOF is reset
e
s 00000/00001/00228
d D 2.5 83/06/12 11:17:07 sam 10 9
c new signals
e
s 00004/00003/00225
d D 2.4 83/02/09 15:25:21 sam 9 8
c from sun
e
s 00000/00000/00228
d D 2.3 82/03/15 09:44:39 kurt 8 6
i 7
c Included Eric's branch changes to remove vax and vmunix 
c dependencies. 
c 
e
s 00012/00002/00217
d D 2.1.1.1 82/03/15 09:34:16 kurt 7 5
c Eric Allman's fixes to remove VAX and VMUNIX dependencies
e
s 00000/00001/00218
d D 2.2 81/12/14 14:47:56 kurt 6 5
c removed redundant include of sgtty.h 
c 
e
s 00000/00000/00219
d D 2.1 81/07/01 11:10:37 kurt 5 4
c Release to Heidi Stettner
e
s 00051/00007/00168
d D 1.4 81/04/01 17:52:43 kurt 4 3
c changed to reprint prompt when resumed after ^Z
e
s 00003/00003/00172
d D 1.3 81/04/01 12:59:55 kurt 3 2
c changed calls on signal to sigset
e
s 00004/00001/00171
d D 1.2 81/03/02 19:46:54 kas 2 1
c more careful about clobbering the supposed newline at the end of the string
c when reading in a header line; careful to clear string initially when using
c the enhanced tty driver to avoid picking up a ghost from previous header
e
s 00172/00000/00000
d D 1.1 80/10/08 09:52:04 kas 1 0
c date and time created 80/10/08 09:52:04 by kas
e
u
U
f b 
t
T
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
D 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 17
I 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
 */

E 13
I 1
D 12
#
E 12
I 12
D 17
#ifndef lint
D 14
static char sccsid[] = "%W% (Berkeley) %G%";
E 14
I 14
static char *sccsid = "%W% (Berkeley) %G%";
E 14
D 13
#endif
E 13
I 13
#endif not lint
E 17
I 17
#ifdef notdef
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* notdef */
E 17
E 13
E 12

/*
 * Mail -- a mail program
 *
 * Generally useful tty stuff.
 */

#include "rcv.h"
D 6
#include <sgtty.h>
E 6
D 12

static char *SccsId = "%W% %G%";
E 12

static	int	c_erase;		/* Current erase char */
static	int	c_kill;			/* Current kill char */
I 4
static	int	hadcont;		/* Saw continue signal */
static	jmp_buf	rewrite;		/* Place to go when continued */
E 4
#ifndef TIOCSTI
static	int	ttyset;			/* We must now do erase/kill */
#endif

/*
 * Read all relevant header fields.
 */

grabh(hp, gflags)
	struct header *hp;
{
	struct sgttyb ttybuf;
I 4
D 15
	int ttycont(), signull();
E 15
I 15
D 16
	int ttycont();
E 16
E 15
E 4
#ifndef TIOCSTI
D 15
	int (*savesigs[2])();
E 15
I 15
	int (*saveint)(), (*savequit)();
E 15
#endif
I 4
	int (*savecont)();
E 4
D 15
	register int s;
E 15
	int errs;

I 7
D 15
# ifdef VMUNIX
E 7
I 4
	savecont = sigset(SIGCONT, signull);
I 7
# endif VMUNIX
E 15
I 15
	savecont = signal(SIGCONT, SIG_DFL);
E 15
E 7
E 4
	errs = 0;
#ifndef TIOCSTI
	ttyset = 0;
#endif
	if (gtty(fileno(stdin), &ttybuf) < 0) {
		perror("gtty");
		return(-1);
	}
	c_erase = ttybuf.sg_erase;
	c_kill = ttybuf.sg_kill;
#ifndef TIOCSTI
	ttybuf.sg_erase = 0;
	ttybuf.sg_kill = 0;
D 15
	for (s = SIGINT; s <= SIGQUIT; s++)
D 3
		if ((savesigs[s-SIGINT] = signal(s, SIG_IGN)) == SIG_DFL)
			signal(s, SIG_DFL);
E 3
I 3
		if ((savesigs[s-SIGINT] = sigset(s, SIG_IGN)) == SIG_DFL)
			sigset(s, SIG_DFL);
E 15
I 15
	if ((saveint = signal(SIGINT, SIG_IGN)) == SIG_DFL)
		signal(SIGINT, SIG_DFL);
	if ((savequit = signal(SIGQUIT, SIG_IGN)) == SIG_DFL)
		signal(SIGQUIT, SIG_DFL);
E 15
E 3
#endif
	if (gflags & GTO) {
#ifndef TIOCSTI
		if (!ttyset && hp->h_to != NOSTR)
			ttyset++, stty(fileno(stdin), &ttybuf);
#endif
		hp->h_to = readtty("To: ", hp->h_to);
		if (hp->h_to != NOSTR)
			hp->h_seq++;
	}
	if (gflags & GSUBJECT) {
#ifndef TIOCSTI
		if (!ttyset && hp->h_subject != NOSTR)
			ttyset++, stty(fileno(stdin), &ttybuf);
#endif
		hp->h_subject = readtty("Subject: ", hp->h_subject);
		if (hp->h_subject != NOSTR)
			hp->h_seq++;
	}
	if (gflags & GCC) {
#ifndef TIOCSTI
		if (!ttyset && hp->h_cc != NOSTR)
			ttyset++, stty(fileno(stdin), &ttybuf);
#endif
		hp->h_cc = readtty("Cc: ", hp->h_cc);
		if (hp->h_cc != NOSTR)
			hp->h_seq++;
	}
	if (gflags & GBCC) {
#ifndef TIOCSTI
		if (!ttyset && hp->h_bcc != NOSTR)
			ttyset++, stty(fileno(stdin), &ttybuf);
#endif
		hp->h_bcc = readtty("Bcc: ", hp->h_bcc);
		if (hp->h_bcc != NOSTR)
			hp->h_seq++;
	}
I 7
D 15
# ifdef VMUNIX
E 7
I 4
	sigset(SIGCONT, savecont);
I 7
# endif VMUNIX
E 15
I 15
	signal(SIGCONT, savecont);
E 15
E 7
E 4
#ifndef TIOCSTI
	ttybuf.sg_erase = c_erase;
	ttybuf.sg_kill = c_kill;
	if (ttyset)
		stty(fileno(stdin), &ttybuf);
D 15
	for (s = SIGINT; s <= SIGQUIT; s++)
D 3
		signal(s, savesigs[s-SIGINT]);
E 3
I 3
		sigset(s, savesigs[s-SIGINT]);
E 15
I 15
	signal(SIGINT, saveint);
	signal(SIGQUIT, savequit);
E 15
E 3
#endif
	return(errs);
}

/*
 * Read up a header from standard input.
 * The source string has the preliminary contents to
 * be read.
 *
 */

char *
readtty(pr, src)
	char pr[], src[];
{
D 9
	char canonb[BUFSIZ];
D 4
	int c, ch;
E 4
I 4
	int c, ch, signull();
E 9
I 9
	char ch, canonb[BUFSIZ];
D 15
	int c, signull();
E 15
I 15
	int c;
E 15
E 9
E 4
	register char *cp, *cp2;
I 16
	int ttycont();
E 16

D 4
	fputs(pr, stdout); fflush(stdout);
E 4
I 4
	fputs(pr, stdout);
	fflush(stdout);
E 4
	if (src != NOSTR && strlen(src) > BUFSIZ - 2) {
		printf("too long to edit\n");
		return(src);
	}
#ifndef TIOCSTI
	if (src != NOSTR)
		cp = copy(src, canonb);
	else
		cp = copy("", canonb);
	fputs(canonb, stdout);
	fflush(stdout);
#else
D 4
	for (cp = src; c = *cp; cp++) {
E 4
I 4
	cp = src == NOSTR ? "" : src;
	while (c = *cp++) {
E 4
		if (c == c_erase || c == c_kill) {
			ch = '\\';
			ioctl(0, TIOCSTI, &ch);
		}
D 9
		ioctl(0, TIOCSTI, &c);
E 9
I 9
		ch = c;
		ioctl(0, TIOCSTI, &ch);
E 9
	}
	cp = canonb;
I 2
	*cp = 0;
E 2
#endif
D 4
	cp2 = fgets(cp, BUFSIZ - (cp - canonb), stdin);
D 2
	canonb[strlen(canonb) - 1] = '\0';
E 2
I 2
	cp = index(canonb, '\n');
	if (cp != NOSTR)
		*cp = 0;
E 4
I 4
	cp2 = cp;
	while (cp2 < canonb + BUFSIZ)
		*cp2++ = 0;
	cp2 = cp;
	if (setjmp(rewrite))
		goto redo;
I 7
D 15
# ifdef VMUNIX
E 7
	sigset(SIGCONT, ttycont);
I 7
# endif VMUNIX
E 15
I 15
	signal(SIGCONT, ttycont);
E 15
I 11
	clearerr(stdin);
E 11
E 7
	while (cp2 < canonb + BUFSIZ) {
		c = getc(stdin);
		if (c == EOF || c == '\n')
			break;
		*cp2++ = c;
	}
	*cp2 = 0;
I 7
D 15
# ifdef VMUNIX
E 7
	sigset(SIGCONT, signull);
I 7
# endif VMUNIX
E 15
I 15
	signal(SIGCONT, SIG_DFL);
E 15
E 7
	if (c == EOF && ferror(stdin) && hadcont) {
redo:
		hadcont = 0;
		cp = strlen(canonb) > 0 ? canonb : NOSTR;
		clearerr(stdin);
		return(readtty(pr, cp));
	}
E 4
E 2
#ifndef TIOCSTI
D 7
	if (cp2 == NOSTR || *cp2 == '\0')
E 7
I 7
	if (cp == NOSTR || *cp == '\0')
E 7
		return(src);
D 7
	cp = cp2;
E 7
I 7
	cp2 = cp;
E 7
	if (!ttyset)
		return(strlen(canonb) > 0 ? savestr(canonb) : NOSTR);
	while (*cp != '\0') {
		c = *cp++;
		if (c == c_erase) {
			if (cp2 == canonb)
				continue;
			if (cp2[-1] == '\\') {
				cp2[-1] = c;
				continue;
			}
			cp2--;
			continue;
		}
		if (c == c_kill) {
			if (cp2 == canonb)
				continue;
			if (cp2[-1] == '\\') {
				cp2[-1] = c;
				continue;
			}
			cp2 = canonb;
			continue;
		}
		*cp2++ = c;
	}
	*cp2 = '\0';
#endif
	if (equal("", canonb))
		return(NOSTR);
	return(savestr(canonb));
}
I 4

I 7
D 15
# ifdef VMUNIX
E 15
E 7
/*
 * Receipt continuation.
 */
I 15
/*ARGSUSED*/
E 15
ttycont(s)
{
D 16

E 16
	hadcont++;
D 10
	sigrelse(SIGCONT);
E 10
	longjmp(rewrite, 1);
}
I 7
D 15
# endif VMUNIX
E 7

/*
 * Null routine to satisfy
 * silly system bug that denies us holding SIGCONT
 */
signull(s)
{}
E 15
E 4
E 1
