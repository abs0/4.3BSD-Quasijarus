h53081
s 00043/00038/00907
d D 7.7 03/04/13 15:19:00 msokolov 16 15
c 8-bit ex
e
s 00021/00023/00924
d D 7.6 87/03/09 12:47:21 conrad 15 14
c make ex/vi work on vms
e
s 00001/00001/00946
d D 7.5 85/06/07 18:19:52 bloom 14 13
c fix sccsid and copyright for xstr
e
s 00010/00002/00937
d D 7.4 85/05/31 13:55:57 dist 13 11
c Add copyright
e
s 00010/00002/00879
d D 5.1.1.1 85/05/31 12:05:03 dist 12 6
c Add copyright
e
s 00001/00001/00938
d D 7.3 83/06/18 18:24:26 sam 11 10
c \< searchs didn't match at beginning of line (from wnj@sun.UUCP)
e
s 00002/00002/00937
d D 7.2 81/10/16 08:30:59 mark 10 9
c last minute fixes before release of 3.7
e
s 00006/00002/00933
d D 7.1 81/07/08 22:30:24 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00009/00000/00926
d D 6.2 80/10/23 16:10:49 mark 8 7
c fixed various bugs prior to 3.6 release
e
s 00057/00012/00869
d D 6.1 80/10/19 01:21:06 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00881
d D 5.1 80/08/20 16:10:48 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00879
d D 4.2 80/08/01 20:40:48 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00011/00013/00869
d D 4.1 80/08/01 00:14:04 mark 4 3
c release 3.4, June 24, 1980
e
s 00006/00004/00876
d D 3.1 80/07/31 23:38:49 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00001/00001/00879
d D 2.1 80/07/31 23:19:05 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00880/00000/00000
d D 1.1 80/07/31 23:00:20 mark 1 0
c date and time created 80/07/31 23:00:20 by mark
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
D 9
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
E 9
I 9
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
E 9
E 5
#include "ex.h"
#include "ex_re.h"

/*
 * Global, substitute and regular expressions.
 * Very similar to ed, with some re extensions and
 * confirmed substitute.
 */
global(k)
	bool k;
{
D 16
	register char *gp;
E 16
I 16
	register u_char *gp;
E 16
	register int c;
	register line *a1;
D 16
	char globuf[GBSIZE], *Cwas;
E 16
I 16
	u_char globuf[GBSIZE], *Cwas;
E 16
	int lines = lineDOL();
	int oinglobal = inglobal;
D 16
	char *oglobp = globp;
E 16
I 16
	u_char *oglobp = globp;
E 16

	Cwas = Command;
	/*
	 * States of inglobal:
	 *  0: ordinary - not in a global command.
	 *  1: text coming from some buffer, not tty.
	 *  2: like 1, but the source of the buffer is a global command.
	 * Hence you're only in a global command if inglobal==2. This
	 * strange sounding convention is historically derived from
	 * everybody simulating a global command.
	 */
	if (inglobal==2)
		error("Global within global@not allowed");
	markDOT();
	setall();
	nonzero();
	if (skipend())
		error("Global needs re|Missing regular expression for global");
D 15
	c = getchar();
E 15
I 15
	c = ex_getchar();
E 15
	ignore(compile(c, 1));
	savere(scanre);
	gp = globuf;
D 15
	while ((c = getchar()) != '\n') {
E 15
I 15
	while ((c = ex_getchar()) != '\n') {
E 15
		switch (c) {

		case EOF:
			c = '\n';
			goto brkwh;

		case '\\':
D 15
			c = getchar();
E 15
I 15
			c = ex_getchar();
E 15
			switch (c) {

			case '\\':
				ungetchar(c);
				break;

			case '\n':
				break;

			default:
				*gp++ = '\\';
				break;
			}
			break;
		}
		*gp++ = c;
		if (gp >= &globuf[GBSIZE - 2])
			error("Global command too long");
	}
brkwh:
	ungetchar(c);
D 15
out:
E 15
	newline();
	*gp++ = c;
	*gp++ = 0;
I 3
	saveall();
E 3
	inglobal = 2;
	for (a1 = one; a1 <= dol; a1++) {
		*a1 &= ~01;
		if (a1 >= addr1 && a1 <= addr2 && execute(0, a1) == k)
			*a1 |= 01;
	}
I 8
#ifdef notdef
/*
 * This code is commented out for now.  The problem is that we don't
 * fix up the undo area the way we should.  Basically, I think what has
 * to be done is to copy the undo area down (since we shrunk everything)
 * and move the various pointers into it down too.  I will do this later
 * when I have time. (Mark, 10-20-80)
 */
E 8
D 7
	/* should use gdelete from ed to avoid n**2 here on g/.../d */
E 7
I 7
	/*
	 * Special case: g/.../d (avoid n^2 algorithm)
	 */
	if (globuf[0]=='d' && globuf[1]=='\n' && globuf[2]=='\0') {
		gdelete();
		return;
	}
I 8
#endif
E 8
E 7
D 3
	saveall();
E 3
	if (inopen)
		inopen = -1;
I 7
	/*
	 * Now for each marked line, set dot there and do the commands.
	 * Note the n^2 behavior here for lots of lines matching.
	 * This is really needed: in some cases you could delete lines,
	 * causing a marked line to be moved before a1 and missed if
	 * we didn't restart at zero each time.
	 */
E 7
	for (a1 = one; a1 <= dol; a1++) {
		if (*a1 & 01) {
			*a1 &= ~01;
			dot = a1;
			globp = globuf;
			commands(1, 1);
			a1 = zero;
		}
	}
	globp = oglobp;
	inglobal = oinglobal;
	endline = 1;
	Command = Cwas;
	netchHAD(lines);
	setlastchar(EOF);
	if (inopen) {
		ungetchar(EOF);
		inopen = 1;
	}
}

I 7
/*
 * gdelete: delete inside a global command. Handles the
 * special case g/r.e./d. All lines to be deleted have
 * already been marked. Squeeze the remaining lines together.
 * Note that other cases such as g/r.e./p, g/r.e./s/r.e.2/rhs/,
 * and g/r.e./.,/r.e.2/d are not treated specially.  There is no
 * good reason for this except the question: where to you draw the line?
 */
gdelete()
{
	register line *a1, *a2, *a3;

	a3 = dol;
	/* find first marked line. can skip all before it */
	for (a1=zero; (*a1&01)==0; a1++)
		if (a1>=a3)
			return;
	/* copy down unmarked lines, compacting as we go. */
	for (a2=a1+1; a2<=a3;) {
		if (*a2&01) {
			a2++;		/* line is marked, skip it */
			dot = a1;	/* dot left after line deletion */
		} else
			*a1++ = *a2++;	/* unmarked, copy it */
	}
	dol = a1-1;
	if (dot>dol)
		dot = dol;
	change();
}

E 7
D 4
bool	xflag;
E 4
I 4
bool	cflag;
E 4
int	scount, slines, stotal;

substitute(c)
	int c;
{
	register line *addr;
	register int n;
D 7
	int gsubf;
E 7
I 7
D 10
	int gsubf, hopcount = 0;
E 10
I 10
	int gsubf, hopcount;
E 10
E 7

	gsubf = compsub(c);
D 3
	if (!inglobal)
E 3
I 3
	if(FIXUNDO)
E 3
		save12(), undkind = UNDCHANGE;
	stotal = 0;
	slines = 0;
	for (addr = addr1; addr <= addr2; addr++) {
D 10
		scount = 0;
E 10
I 10
		scount = hopcount = 0;
E 10
		if (dosubcon(0, addr) == 0)
			continue;
		if (gsubf) {
D 7
#ifdef notdef
E 7
			/*
D 7
			 * should check but loc2 is already munged.
			 * This needs a fancier check later.
E 7
I 7
			 * The loop can happen from s/\</&/g
			 * but we don't want to break other, reasonable cases.
E 7
			 */
D 7
			if (loc1 == loc2)
				error("substitution loop");
#endif
			while (*loc2)
E 7
I 7
			while (*loc2) {
				if (++hopcount > sizeof linebuf)
					error("substitution loop");
E 7
				if (dosubcon(1, addr) == 0)
					break;
I 7
			}
E 7
		}
		if (scount) {
			stotal += scount;
			slines++;
			putmark(addr);
			n = append(getsub, addr);
			addr += n;
			addr2 += n;
		}
	}
D 4
	if (stotal == 0 && !inglobal && !xflag)
E 4
I 4
	if (stotal == 0 && !inglobal && !cflag)
E 4
		error("Fail|Substitute pattern match failed");
	snote(stotal, slines);
	return (stotal);
}

compsub(ch)
{
	register int seof, c, uselastre;
	static int gsubf;

	if (!value(EDCOMPATIBLE))
D 4
		gsubf = xflag = 0;
E 4
I 4
		gsubf = cflag = 0;
E 4
	uselastre = 0;
	switch (ch) {

	case 's':
		ignore(skipwh());
D 15
		seof = getchar();
E 15
I 15
		seof = ex_getchar();
E 15
		if (endcmd(seof) || any(seof, "gcr")) {
			ungetchar(seof);
			goto redo;
		}
		if (isalpha(seof) || isdigit(seof))
			error("Substitute needs re|Missing regular expression for substitute");
		seof = compile(seof, 1);
		uselastre = 1;
		comprhs(seof);
		gsubf = 0;
D 4
		xflag = 0;
E 4
I 4
		cflag = 0;
E 4
		break;

	case '~':
		uselastre = 1;
		/* fall into ... */
	case '&':
	redo:
		if (re.Expbuf[0] == 0)
			error("No previous re|No previous regular expression");
I 4
		if (subre.Expbuf[0] == 0)
			error("No previous substitute re|No previous substitute to repeat");
E 4
		break;
	}
	for (;;) {
D 15
		c = getchar();
E 15
I 15
		c = ex_getchar();
E 15
		switch (c) {

		case 'g':
			gsubf = !gsubf;
			continue;

		case 'c':
D 4
			xflag = !xflag;
E 4
I 4
			cflag = !cflag;
E 4
			continue;

		case 'r':
			uselastre = 1;
			continue;

		default:
			ungetchar(c);
			setcount();
			newline();
			if (uselastre)
				savere(subre);
			else
				resre(subre);
			return (gsubf);
		}
	}
}

comprhs(seof)
	int seof;
{
D 16
	register char *rp, *orp;
E 16
I 16
	register u_char *rp, *orp;
E 16
	register int c;
D 7
	char orhsbuf[LBSIZE / 2];
E 7
I 7
D 16
	char orhsbuf[RHSSIZE];
E 16
I 16
	u_char orhsbuf[RHSSIZE];
E 16
E 7

	rp = rhsbuf;
	CP(orhsbuf, rp);
	for (;;) {
D 15
		c = getchar();
E 15
I 15
		c = ex_getchar();
E 15
		if (c == seof)
			break;
		switch (c) {

		case '\\':
D 15
			c = getchar();
E 15
I 15
			c = ex_getchar();
E 15
			if (c == EOF) {
				ungetchar(c);
				break;
			}
			if (value(MAGIC)) {
				/*
				 * When "magic", \& turns into a plain &,
				 * and all other chars work fine quoted.
				 */
				if (c != '&')
					c |= QUOTE;
				break;
			}
magic:
			if (c == '~') {
				for (orp = orhsbuf; *orp; *rp++ = *orp++)
D 7
					if (rp >= &rhsbuf[LBSIZE / 2 + 1])
E 7
I 7
					if (rp >= &rhsbuf[RHSSIZE - 1])
E 7
						goto toobig;
				continue;
			}
			c |= QUOTE;
			break;

		case '\n':
		case EOF:
D 3
			ungetchar(c);
			goto endrhs;
E 3
I 3
			if (!(globp && globp[0])) {
				ungetchar(c);
				goto endrhs;
			}
E 3

		case '~':
		case '&':
			if (value(MAGIC))
				goto magic;
			break;
		}
I 16
		if ((c&TRIM8) == RHSQUOTE) {
			*rp = 0;
			error("~@ is not allowed in replacement patterns");
		}
		if (c & QUOTE) {
			if (rp >= &rhsbuf[RHSSIZE - 1])
				goto toobig;
			*rp++ = RHSQUOTE;
		}
E 16
D 7
		if (rp >= &rhsbuf[LBSIZE / 2 - 1])
E 7
I 7
		if (rp >= &rhsbuf[RHSSIZE - 1]) {
E 7
toobig:
I 7
			*rp = 0;
E 7
			error("Replacement pattern too long@- limit 256 characters");
I 7
		}
E 7
		*rp++ = c;
	}
endrhs:
	*rp++ = 0;
}

getsub()
{
D 16
	register char *p;
E 16
I 16
	register u_char *p;
E 16

	if ((p = linebp) == 0)
		return (EOF);
	strcLIN(p);
	linebp = 0;
	return (0);
}

dosubcon(f, a)
	bool f;
	line *a;
{

	if (execute(f, a) == 0)
		return (0);
	if (confirmed(a)) {
		dosub();
		scount++;
	}
	return (1);
}

confirmed(a)
	line *a;
{
	register int c, ch;

D 4
	if (xflag == 0)
E 4
I 4
	if (cflag == 0)
E 4
		return (1);
	pofix();
	pline(lineno(a));
	if (inopen)
D 15
		putchar('\n' | QUOTE);
E 15
I 15
		ex_putchar('\n' | QUOTE);
E 15
	c = column(loc1 - 1);
	ugo(c - 1 + (inopen ? 1 : 0), ' ');
	ugo(column(loc2 - 1) - c, '^');
	flush();
	ch = c = getkey();
again:
	if (c == '\r')
		c = '\n';
	if (inopen)
D 15
		putchar(c), flush();
E 15
I 15
		ex_putchar(c), flush();
E 15
	if (c != '\n' && c != EOF) {
		c = getkey();
		goto again;
	}
	noteinp();
	return (ch == 'y');
}

D 16
getch()
{
	char c;

	if (read(2, &c, 1) != 1)
		return (EOF);
	return (c & TRIM);
}

E 16
ugo(cnt, with)
	int with;
	int cnt;
{

	if (cnt > 0)
		do
D 15
			putchar(with);
E 15
I 15
			ex_putchar(with);
E 15
		while (--cnt > 0);
}

int	casecnt;
bool	destuc;

dosub()
{
D 16
	register char *lp, *sp, *rp;
E 16
I 16
	register u_char *lp, *sp, *rp;
E 16
	int c;

	lp = linebuf;
	sp = genbuf;
	rp = rhsbuf;
	while (lp < loc1)
		*sp++ = *lp++;
	casecnt = 0;
D 16
	while (c = *rp++) {
E 16
I 16
	while (c = *rp++ & TRIM8) {
E 16
I 9
		/* ^V <return> from vi to split lines */
		if (c == '\r')
			c = '\n';

I 16
		if (c == RHSQUOTE)
			c = QUOTE | *rp++ & TRIM8;

E 16
E 9
		if (c & QUOTE)
D 16
			switch (c & TRIM) {
E 16
I 16
			switch (c & TRIM8) {
E 16

			case '&':
				sp = place(sp, loc1, loc2);
				if (sp == 0)
					goto ovflo;
				continue;

			case 'l':
				casecnt = 1;
				destuc = 0;
				continue;

			case 'L':
				casecnt = LBSIZE;
				destuc = 0;
				continue;

			case 'u':
				casecnt = 1;
				destuc = 1;
				continue;

			case 'U':
				casecnt = LBSIZE;
				destuc = 1;
				continue;

			case 'E':
			case 'e':
				casecnt = 0;
				continue;
			}
D 16
		if (c < 0 && (c &= TRIM) >= '1' && c < nbra + '1') {
E 16
I 16
		if ((c & QUOTE) && (c &= TRIM8) >= '1' && c < nbra + '1') {
E 16
			sp = place(sp, braslist[c - '1'], braelist[c - '1']);
			if (sp == 0)
				goto ovflo;
			continue;
		}
		if (casecnt)
D 16
			*sp++ = fixcase(c & TRIM);
E 16
I 16
			*sp++ = fixcase(c & TRIM8);
E 16
		else
D 16
			*sp++ = c & TRIM;
E 16
I 16
			*sp++ = c & TRIM8;
E 16
		if (sp >= &genbuf[LBSIZE])
ovflo:
D 2
			error("Line overflow@in substitute - limit 512 chars");
E 2
I 2
			error("Line overflow@in substitute");
E 2
	}
	lp = loc2;
	loc2 = sp + (linebuf - genbuf);
	while (*sp++ = *lp++)
		if (sp >= &genbuf[LBSIZE])
			goto ovflo;
	strcLIN(genbuf);
}

fixcase(c)
	register int c;
{

	if (casecnt == 0)
		return (c);
	casecnt--;
	if (destuc) {
		if (islower(c))
			c = toupper(c);
	} else
		if (isupper(c))
			c = tolower(c);
	return (c);
}

D 16
char *
E 16
I 16
u_char *
E 16
place(sp, l1, l2)
D 16
	register char *sp, *l1, *l2;
E 16
I 16
	register u_char *sp, *l1, *l2;
E 16
{

	while (l1 < l2) {
		*sp++ = fixcase(*l1++);
		if (sp >= &genbuf[LBSIZE])
			return (0);
	}
	return (sp);
}

snote(total, lines)
	register int total, lines;
{

	if (!notable(total))
		return;
D 15
	printf(mesg("%d subs|%d substitutions"), total);
E 15
I 15
	ex_printf(mesg("%d subs|%d substitutions"), total);
E 15
	if (lines != 1 && lines != total)
D 15
		printf(" on %d lines", lines);
E 15
I 15
		ex_printf(" on %d lines", lines);
E 15
	noonl();
	flush();
}

compile(eof, oknl)
	int eof;
	int oknl;
{
	register int c;
D 16
	register char *ep;
	char *lastep;
	char bracket[NBRA], *bracketp, *rhsp;
E 16
I 16
	register u_char *ep;
	u_char *lastep;
	u_char bracket[NBRA], *bracketp, *rhsp;
E 16
	int cclcnt;

	if (isalpha(eof) || isdigit(eof))
		error("Regular expressions cannot be delimited by letters or digits");
	ep = expbuf;
D 15
	c = getchar();
E 15
I 15
	c = ex_getchar();
E 15
	if (eof == '\\')
		switch (c) {

		case '/':
		case '?':
			if (scanre.Expbuf[0] == 0)
error("No previous scan re|No previous scanning regular expression");
			resre(scanre);
			return (c);

		case '&':
			if (subre.Expbuf[0] == 0)
error("No previous substitute re|No previous substitute regular expression");
			resre(subre);
			return (c);

		default:
			error("Badly formed re|Regular expression \\ must be followed by / or ?");
		}
	if (c == eof || c == '\n' || c == EOF) {
		if (*ep == 0)
			error("No previous re|No previous regular expression");
		if (c == '\n' && oknl == 0)
			error("Missing closing delimiter@for regular expression");
		if (c != eof)
			ungetchar(c);
		return (eof);
	}
	bracketp = bracket;
	nbra = 0;
	circfl = 0;
	if (c == '^') {
D 15
		c = getchar();
E 15
I 15
		c = ex_getchar();
E 15
		circfl++;
	}
	ungetchar(c);
	for (;;) {
		if (ep >= &expbuf[ESIZE - 2])
complex:
			cerror("Re too complex|Regular expression too complicated");
D 15
		c = getchar();
E 15
I 15
		c = ex_getchar();
E 15
		if (c == eof || c == EOF) {
			if (bracketp != bracket)
cerror("Unmatched \\(|More \\('s than \\)'s in regular expression");
D 4
			*ep++ = CEOF;
E 4
I 4
			*ep++ = CEOFC;
E 4
			if (c == EOF)
				ungetchar(c);
			return (eof);
		}
		if (value(MAGIC)) {
			if (c != '*' || ep == expbuf)
				lastep = ep;
		} else
			if (c != '\\' || peekchar() != '*' || ep == expbuf)
				lastep = ep;
		switch (c) {

		case '\\':
D 15
			c = getchar();
E 15
I 15
			c = ex_getchar();
E 15
			switch (c) {

			case '(':
				if (nbra >= NBRA)
cerror("Awash in \\('s!|Too many \\('d subexressions in a regular expression");
				*bracketp++ = nbra;
				*ep++ = CBRA;
				*ep++ = nbra++;
				continue;

			case ')':
				if (bracketp <= bracket)
cerror("Extra \\)|More \\)'s than \\('s in regular expression");
				*ep++ = CKET;
				*ep++ = *--bracketp;
				continue;

			case '<':
				*ep++ = CBRC;
				continue;

			case '>':
				*ep++ = CLET;
				continue;
			}
			if (value(MAGIC) == 0)
magic:
			switch (c) {

			case '.':
				*ep++ = CDOT;
				continue;

			case '~':
				rhsp = rhsbuf;
				while (*rhsp) {
D 16
					if (*rhsp & QUOTE) {
						c = *rhsp & TRIM;
E 16
I 16
					if ((*rhsp&TRIM8) == RHSQUOTE) {
						c = *++rhsp & TRIM8;
E 16
						if (c == '&')
error("Replacement pattern contains &@- cannot use in re");
						if (c >= '1' && c <= '9')
error("Replacement pattern contains \\d@- cannot use in re");
					}
					if (ep >= &expbuf[ESIZE-2])
						goto complex;
					*ep++ = CCHR;
D 16
					*ep++ = *rhsp++ & TRIM;
E 16
I 16
					*ep++ = *rhsp++;
E 16
				}
				continue;

			case '*':
				if (ep == expbuf)
					break;
				if (*lastep == CBRA || *lastep == CKET)
cerror("Illegal *|Can't * a \\( ... \\) in regular expression");
I 16
/*
E 16
				if (*lastep == CCHR && (lastep[1] & QUOTE))
cerror("Illegal *|Can't * a \\n in regular expression");
I 16
*/
E 16
				*lastep |= STAR;
				continue;

			case '[':
				*ep++ = CCL;
				*ep++ = 0;
				cclcnt = 1;
D 15
				c = getchar();
E 15
I 15
				c = ex_getchar();
E 15
				if (c == '^') {
D 15
					c = getchar();
E 15
I 15
					c = ex_getchar();
E 15
					ep[-2] = NCCL;
				}
				if (c == ']')
cerror("Bad character class|Empty character class '[]' or '[^]' cannot match");
				while (c != ']') {
					if (c == '\\' && any(peekchar(), "]-^\\"))
D 15
						c = getchar() | QUOTE;
E 15
I 15
D 16
						c = ex_getchar() | QUOTE;
E 16
I 16
						c = ex_getchar();
E 16
E 15
					if (c == '\n' || c == EOF)
						cerror("Missing ]");
					*ep++ = c;
					cclcnt++;
					if (ep >= &expbuf[ESIZE])
						goto complex;
D 15
					c = getchar();
E 15
I 15
					c = ex_getchar();
E 15
				}
				lastep[1] = cclcnt;
				continue;
			}
			if (c == EOF) {
				ungetchar(EOF);
				c = '\\';
				goto defchar;
			}
			*ep++ = CCHR;
			if (c == '\n')
cerror("No newlines in re's|Can't escape newlines into regular expressions");
/*
			if (c < '1' || c > NBRA + '1') {
*/
				*ep++ = c;
				continue;
/*
			}
			c -= '1';
			if (c >= nbra)
cerror("Bad \\n|\\n in regular expression with n greater than the number of \\('s");
			*ep++ = c | QUOTE;
			continue;
*/

		case '\n':
			if (oknl) {
				ungetchar(c);
D 4
				*ep++ = CEOF;
E 4
I 4
				*ep++ = CEOFC;
E 4
				return (eof);
			}
cerror("Badly formed re|Missing closing delimiter for regular expression");

		case '$':
			if (peekchar() == eof || peekchar() == EOF || oknl && peekchar() == '\n') {
				*ep++ = CDOL;
				continue;
			}
			goto defchar;

		case '.':
		case '~':
		case '*':
		case '[':
			if (value(MAGIC))
				goto magic;
defchar:
		default:
			*ep++ = CCHR;
			*ep++ = c;
			continue;
		}
	}
}

cerror(s)
D 16
	char *s;
E 16
I 16
	u_char *s;
E 16
{

	expbuf[0] = 0;
	error(s);
}

same(a, b)
	register int a, b;
{

	return (a == b || value(IGNORECASE) &&
	   ((islower(a) && toupper(a) == b) || (islower(b) && toupper(b) == a)));
}

D 16
char	*locs;
E 16
I 16
u_char	*locs;
E 16

I 15
/* VARARGS1 */
E 15
execute(gf, addr)
	line *addr;
{
D 16
	register char *p1, *p2;
E 16
I 16
	register u_char *p1, *p2;
E 16
	register int c;

	if (gf) {
		if (circfl)
			return (0);
D 4
#ifdef notdef
		if (loc1 == loc2)
			loc2++;
#endif
E 4
		locs = p1 = loc2;
	} else {
		if (addr == zero)
			return (0);
		p1 = linebuf;
		getline(*addr);
		locs = 0;
	}
	p2 = expbuf;
	if (circfl) {
		loc1 = p1;
		return (advance(p1, p2));
	}
	/* fast check for first character */
	if (*p2 == CCHR) {
		c = p2[1];
		do {
			if (c != *p1 && (!value(IGNORECASE) ||
			   !((islower(c) && toupper(c) == *p1) ||
			   (islower(*p1) && toupper(*p1) == c))))
				continue;
			if (advance(p1, p2)) {
				loc1 = p1;
				return (1);
			}
		} while (*p1++);
		return (0);
	}
	/* regular algorithm */
	do {
		if (advance(p1, p2)) {
			loc1 = p1;
			return (1);
		}
	} while (*p1++);
	return (0);
}

#define	uletter(c)	(isalpha(c) || c == '_')

advance(lp, ep)
D 16
	register char *lp, *ep;
E 16
I 16
	register u_char *lp, *ep;
E 16
{
D 16
	register char *curlp;
E 16
I 16
	register u_char *curlp;
E 16
D 15
	char *sp, *sp1;
	int c;
E 15

	for (;;) switch (*ep++) {

	case CCHR:
/* useless
		if (*ep & QUOTE) {
			c = *ep++ & TRIM;
			sp = braslist[c];
			sp1 = braelist[c];
			while (sp < sp1) {
				if (!same(*sp, *lp))
					return (0);
				sp++, lp++;
			}
			continue;
		}
*/
		if (!same(*ep, *lp))
			return (0);
		ep++, lp++;
		continue;

	case CDOT:
		if (*lp++)
			continue;
		return (0);

	case CDOL:
		if (*lp == 0)
			continue;
		return (0);

D 4
	case CEOF:
E 4
I 4
	case CEOFC:
E 4
		loc2 = lp;
		return (1);

	case CCL:
		if (cclass(ep, *lp++, 1)) {
			ep += *ep;
			continue;
		}
		return (0);

	case NCCL:
		if (cclass(ep, *lp++, 0)) {
			ep += *ep;
			continue;
		}
		return (0);

	case CBRA:
		braslist[*ep++] = lp;
		continue;

	case CKET:
		braelist[*ep++] = lp;
		continue;

	case CDOT|STAR:
		curlp = lp;
		while (*lp++)
			continue;
		goto star;

	case CCHR|STAR:
		curlp = lp;
		while (same(*lp, *ep))
			lp++;
		lp++;
		ep++;
		goto star;

	case CCL|STAR:
	case NCCL|STAR:
		curlp = lp;
		while (cclass(ep, *lp++, ep[-1] == (CCL|STAR)))
			continue;
		ep += *ep;
		goto star;
star:
		do {
			lp--;
			if (lp == locs)
				break;
			if (advance(lp, ep))
				return (1);
		} while (lp > curlp);
		return (0);

	case CBRC:
D 11
		if (lp == expbuf)
E 11
I 11
		if (lp == linebuf)
E 11
			continue;
		if ((isdigit(*lp) || uletter(*lp)) && !uletter(lp[-1]) && !isdigit(lp[-1]))
			continue;
		return (0);

	case CLET:
		if (!uletter(*lp) && !isdigit(*lp))
			continue;
		return (0);

	default:
		error("Re internal error");
	}
}

cclass(set, c, af)
D 16
	register char *set;
E 16
I 16
	register u_char *set;
E 16
	register int c;
	int af;
{
	register int n;

	if (c == 0)
		return (0);
	if (value(IGNORECASE) && isupper(c))
		c = tolower(c);
	n = *set++;
	while (--n)
		if (n > 2 && set[1] == '-') {
D 16
			if (c >= (set[0] & TRIM) && c <= (set[2] & TRIM))
E 16
I 16
			if (c >= set[0] && c <= set[2])
E 16
				return (af);
			set += 3;
			n -= 2;
		} else
D 16
			if ((*set++ & TRIM) == c)
E 16
I 16
			if (*set++ == c)
E 16
				return (af);
	return (!af);
}
E 1
