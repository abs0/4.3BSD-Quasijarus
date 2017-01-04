h54737
s 00011/00010/00266
d D 7.9 03/04/13 15:18:53 msokolov 17 16
c 8-bit ex
e
s 00005/00005/00271
d D 7.8 88/01/02 23:12:24 bostic 16 15
c fix CTRL macro for ANSI C
e
s 00010/00011/00266
d D 7.7 87/03/09 12:46:41 conrad 15 14
c make ex/vi work on vms
e
s 00001/00001/00276
d D 7.6 85/06/07 18:19:12 bloom 14 13
c fix sccsid and copyright for xstr
e
s 00010/00002/00267
d D 7.5 85/05/31 13:54:29 dist 13 11
c Add copyright
e
s 00010/00002/00264
d D 5.1.1.1 85/05/31 12:03:30 dist 12 6
c Add copyright
e
s 00003/00011/00266
d D 7.4 85/03/27 12:04:10 bloom 11 10
c backout fix from sun and terminate input buffer
e
s 00001/00001/00276
d D 7.3 85/03/19 19:10:52 mckusick 10 9
c merge from sun!shannon
e
s 00009/00001/00268
d D 7.2 85/01/23 14:22:12 ralph 9 8
c fix 128 byte limit on .exrc
e
s 00007/00004/00262
d D 7.1 81/07/08 22:29:38 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00266
d D 6.1 80/10/19 01:20:53 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00266
d D 5.1 80/08/20 16:09:55 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00264
d D 4.2 80/08/01 20:39:57 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00000/00000/00265
d D 4.1 80/08/01 00:12:07 mark 4 3
c release 3.4, June 24, 1980
e
s 00003/00007/00262
d D 3.1 80/07/31 23:37:45 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00269
d D 2.1 80/07/31 23:18:24 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00269/00000/00000
d D 1.1 80/07/31 23:00:14 mark 1 0
c date and time created 80/07/31 23:00:14 by mark
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
D 8
D 12
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 12
E 8
I 8
D 13
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 13
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 14
static char sccsid[] = "%W% (Berkeley) %G%";
E 14
I 14
static char *sccsid = "%W% (Berkeley) %G%";
E 14
#endif not lint

E 13
E 8
E 5
#include "ex.h"
#include "ex_tty.h"

/*
 * Input routines for command mode.
 * Since we translate the end of reads into the implied ^D's
 * we have different flavors of routines which do/don't return such.
 */
static	bool junkbs;
short	lastc = '\n';

ignchar()
{
D 3
	register int c;

	do
		c = getcd();
	while (c == CTRL(d));
E 3
I 3
D 15
	ignore(getchar());
E 15
I 15
	ignore(ex_getchar());
E 15
E 3
}

D 15
getchar()
E 15
I 15
ex_getchar()
E 15
{
	register int c;

	do
		c = getcd();
D 3
	while (c == CTRL(d));
E 3
I 3
D 16
	while (!globp && c == CTRL(d));
E 16
I 16
	while (!globp && c == CTRL('d'));
E 16
E 3
	return (c);
}

getcd()
{
	register int c;

again:
	c = getach();
	if (c == EOF)
		return (c);
D 17
	c &= TRIM;
E 17
	if (!inopen)
D 3
		if (c == CTRL(d))
E 3
I 3
D 16
		if (!globp && c == CTRL(d))
E 16
I 16
		if (!globp && c == CTRL('d'))
E 16
E 3
			setlastchar('\n');
		else if (junk(c)) {
			checkjunk(c);
			goto again;
		}
	return (c);
}

peekchar()
{

	if (peekc == 0)
D 15
		peekc = getchar();
E 15
I 15
		peekc = ex_getchar();
E 15
	return (peekc);
}

peekcd()
{
D 8

E 8
	if (peekc == 0)
		peekc = getcd();
	return (peekc);
}

getach()
{
	register int c;
D 9
	static char inline[128];
E 9
I 9
D 17
	static char inline[BUFSIZ];
E 17
I 17
	static u_char inline[BUFSIZ];
E 17
E 9
I 8
D 15
	struct stat statb;
E 15
E 8

	c = peekc;
	if (c != 0) {
		peekc = 0;
		return (c);
	}
	if (globp) {
		if (*globp)
			return (*globp++);
		globp = 0;
		return (lastc = EOF);
	}
top:
	if (input) {
		if (c = *input++) {
D 17
			if (c &= TRIM)
E 17
I 17
			if (!value(EIGHTBIT) && !isascii(c))
				c &= TRIM7;
			if (c)
E 17
				return (lastc = c);
			goto top;
		}
		input = 0;
	}
	flush();
D 10
	if (intty) {
E 10
I 10
D 11
	if (!intty) {
E 11
I 11
	if (intty) {
E 11
E 10
		c = read(0, inline, sizeof inline - 4);
		if (c < 0)
			return (lastc = EOF);
		if (c == 0 || inline[c-1] != '\n')
D 16
			inline[c++] = CTRL(d);
E 16
I 16
			inline[c++] = CTRL('d');
E 16
		if (inline[c-1] == '\n')
			noteinp();
		inline[c] = 0;
		for (c--; c >= 0; c--)
			if (inline[c] == 0)
D 17
				inline[c] = QUOTE;
E 17
I 17
				inline[c] = 0200;
E 17
		input = inline;
		goto top;
	}
I 9
D 11
#ifdef notdef
E 9
D 8
	if (read(0, (char *) &lastc, 1) != 1)
E 8
I 8
/* mjm:	if (read(0, (char *) &lastc, 1) != 1)	CHANGED and added else */
	if (read(0, inline, 1) != 1)
E 8
		lastc = EOF;
I 8
	else				/* mjm: lastc is a short! */
		lastc = inline[0];	/* mjm: in rightmost 8 bits ! */
E 8
	return (lastc);
I 9
#else
	c = read(0, inline, sizeof inline);
E 11
I 11
	c = read(0, inline, sizeof inline - 1);
E 11
	if(c <= 0)
		return(lastc = EOF);
I 11
	inline[c] = '\0';
E 11
	input = inline;
	goto top;
D 11
#endif
E 11
E 9
}

/*
 * Input routine for insert/append/change in command mode.
 * Most work here is in handling autoindent.
 */
static	short	lastin;

gettty()
{
	register int c = 0;
D 17
	register char *cp = genbuf;
	char hadup = 0;
E 17
I 17
	register u_char *cp = genbuf;
	u_char hadup = 0;
E 17
	int numbline();
	extern int (*Pline)();
	int offset = Pline == numbline ? 8 : 0;
	int ch;

	if (intty && !inglobal) {
		if (offset) {
			holdcm = 1;
D 15
			printf("  %4d  ", lineDOT() + 1);
E 15
I 15
			ex_printf("  %4d  ", lineDOT() + 1);
E 15
			flush();
			holdcm = 0;
		}
		if (value(AUTOINDENT) ^ aiflag) {
			holdcm = 1;
#ifdef LISPCODE
			if (value(LISP))
				lastin = lindent(dot + 1);
#endif
			tab(lastin + offset);
D 16
			while ((c = getcd()) == CTRL(d)) {
E 16
I 16
			while ((c = getcd()) == CTRL('d')) {
E 16
				if (lastin == 0 && isatty(0) == -1) {
					holdcm = 0;
					return (EOF);
				}
				lastin = backtab(lastin);
				tab(lastin + offset);
			}
			switch (c) {

			case '^':
			case '0':
				ch = getcd();
D 16
				if (ch == CTRL(d)) {
E 16
I 16
				if (ch == CTRL('d')) {
E 16
					if (c == '0')
						lastin = 0;
					if (!OS) {
D 15
						putchar('\b' | QUOTE);
						putchar(' ' | QUOTE);
						putchar('\b' | QUOTE);
E 15
I 15
						ex_putchar('\b' | QUOTE);
						ex_putchar(' ' | QUOTE);
						ex_putchar('\b' | QUOTE);
E 15
					}
					tab(offset);
					hadup = 1;
D 15
					c = getchar();
E 15
I 15
					c = ex_getchar();
E 15
				} else
					ungetchar(ch);
				break;

			case '.':
				if (peekchar() == '\n') {
					ignchar();
					noteinp();
					holdcm = 0;
					return (EOF);
				}
				break;

			case '\n':
				hadup = 1;
				break;
			}
		}
		flush();
		holdcm = 0;
	}
	if (c == 0)
D 15
		c = getchar();
E 15
I 15
		c = ex_getchar();
E 15
	while (c != EOF && c != '\n') {
		if (cp > &genbuf[LBSIZE - 2])
			error("Input line too long");
		*cp++ = c;
D 15
		c = getchar();
E 15
I 15
		c = ex_getchar();
E 15
	}
	if (c == EOF) {
		if (inglobal)
			ungetchar(EOF);
		return (EOF);
	}
	*cp = 0;
	cp = linebuf;
	if ((value(AUTOINDENT) ^ aiflag) && hadup == 0 && intty && !inglobal) {
		lastin = c = smunch(lastin, genbuf);
		for (c = lastin; c >= value(TABSTOP); c -= value(TABSTOP))
			*cp++ = '\t';
		for (; c > 0; c--)
			*cp++ = ' ';
	}
	CP(cp, genbuf);
	if (linebuf[0] == '.' && linebuf[1] == 0)
		return (EOF);
	return (0);
}

/*
 * Crunch the indent.
 * Hard thing here is that in command mode some of the indent
 * is only implicit, so we must seed the column counter.
 * This should really be done differently so as to use the whitecnt routine
 * and also to hack indenting for LISP.
 */
smunch(col, ocp)
	register int col;
D 17
	char *ocp;
E 17
I 17
	u_char *ocp;
E 17
{
D 17
	register char *cp;
E 17
I 17
	register u_char *cp;
E 17

	cp = ocp;
	for (;;)
		switch (*cp++) {

		case ' ':
			col++;
			continue;

		case '\t':
			col += value(TABSTOP) - (col % value(TABSTOP));
			continue;

		default:
			cp--;
			CP(ocp, cp);
			return (col);
		}
}

D 17
char	*cntrlhm =	"^H discarded\n";
E 17
I 17
u_char	*cntrlhm =	"^H discarded\n";
E 17

checkjunk(c)
D 17
	char c;
E 17
I 17
	u_char c;
E 17
{

	if (junkbs == 0 && c == '\b') {
		write(2, cntrlhm, 13);
		junkbs = 1;
	}
}

line *
setin(addr)
	line *addr;
{

	if (addr == zero)
		lastin = 0;
	else
		getline(*addr), lastin = smunch(0, linebuf);
}
E 1
