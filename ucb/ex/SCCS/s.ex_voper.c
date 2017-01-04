h55034
s 00008/00008/00856
d D 7.7 03/04/13 15:19:28 msokolov 16 15
c 8-bit ex
e
s 00003/00003/00861
d D 7.6 88/01/02 23:12:38 bostic 15 14
c fix CTRL macro for ANSI C
e
s 00003/00002/00861
d D 7.5 87/03/09 12:47:11 conrad 14 13
c make ex/vi work on vms
e
s 00001/00001/00862
d D 7.4 85/06/07 18:23:16 bloom 13 12
c fix sccsid and copyright for xstr
e
s 00010/00002/00853
d D 7.3 85/05/31 14:03:17 dist 12 10
c Add copyright
e
s 00010/00002/00849
d D 5.1.1.1 85/05/31 12:13:13 dist 11 6
c Add copyright
e
s 00001/00001/00854
d D 7.2 81/10/31 14:49:54 mark 10 9
c fixed C/70 bug with peekc being saved in a char
e
s 00002/00002/00853
d D 7.1 81/07/08 22:34:06 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00004/00000/00851
d D 6.2 80/10/23 16:16:31 mark 8 7
c fixed various bugs prior to 3.6 release
e
s 00001/00001/00850
d D 6.1 80/10/19 01:22:30 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00003/00006/00848
d D 5.1 80/08/28 20:25:52 mark 6 5
c Release 3.5, 8/28/80, previous "release" not released
c fixed rewind, deleted misfeature where arguments to :, ^^,
c ]], [[, ``, '', /, and ? reset the window size.
e
s 00002/00001/00852
d D 4.2 80/08/01 20:43:16 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00003/00000/00850
d D 4.1 80/08/01 00:18:15 mark 4 3
c release 3.4, June 24, 1980
e
s 00030/00008/00820
d D 3.1 80/07/31 23:42:10 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00828
d D 2.1 80/07/31 23:21:05 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00828/00000/00000
d D 1.1 80/07/31 23:00:49 mark 1 0
c date and time created 80/07/31 23:00:49 by mark
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
D 11
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 11
I 11
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 11
E 9
I 9
D 12
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 12
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 13
static char sccsid[] = "%W% (Berkeley) %G%";
E 13
I 13
static char *sccsid = "%W% (Berkeley) %G%";
E 13
#endif not lint

E 12
E 9
E 5
#include "ex.h"
#include "ex_tty.h"
#include "ex_vis.h"

#define	blank()		isspace(wcursor[0])
#define	forbid(a)	if (a) goto errlab;

D 16
char	vscandir[2] =	{ '/', 0 };
E 16
I 16
u_char	vscandir[2] =	{ '/', 0 };
E 16

/*
 * Decode an operator/operand type command.
 * Eventually we switch to an operator subroutine in ex_vops.c.
 * The work here is setting up a function variable to point
 * to the routine we want, and manipulation of the variables
 * wcursor and wdot, which mark the other end of the affected
 * area.  If wdot is zero, then the current line is the other end,
 * and if wcursor is zero, then the first non-blank location of the
 * other line is implied.
 */
operate(c, cnt)
	register int c, cnt;
{
	register int i;
	int (*moveop)(), (*deleteop)();
	register int (*opf)();
	bool subop = 0;
D 16
	char *oglobp, *ocurs;
E 16
I 16
	u_char *oglobp, *ocurs;
E 16
	register line *addr;
I 3
	line *odot;
E 3
D 16
	static char lastFKND, lastFCHR;
E 16
I 16
	static u_char lastFKND, lastFCHR;
E 16
D 10
	char d;
E 10
I 10
	short d;
E 10

	moveop = vmove, deleteop = vdelete;
	wcursor = cursor;
	wdot = NOLINE;
	notecnt = 0;
	dir = 1;
	switch (c) {

	/*
	 * d		delete operator.
	 */
	case 'd':
		moveop = vdelete;
		deleteop = beep;
		break;

	/*
	 * s		substitute characters, like c\040, i.e. change space.
	 */
	case 's':
		ungetkey(' ');
		subop++;
		/* fall into ... */

	/*
	 * c		Change operator.
	 */
	case 'c':
		if (c == 'c' && workcmd[0] == 'C' || workcmd[0] == 'S')
			subop++;
		moveop = vchange;
		deleteop = beep;
		break;

	/*
	 * !		Filter through a UNIX command.
	 */
	case '!':
		moveop = vfilter;
		deleteop = beep;
		break;

	/*
	 * y		Yank operator.  Place specified text so that it
	 *		can be put back with p/P.  Also yanks to named buffers.
	 */
	case 'y':
		moveop = vyankit;
		deleteop = beep;
		break;

	/*
	 * =		Reformat operator (for LISP).
	 */
#ifdef LISPCODE
	case '=':
		forbid(!value(LISP));
		/* fall into ... */
#endif

	/*
	 * >		Right shift operator.
	 * <		Left shift operator.
	 */
	case '<':
	case '>':
		moveop = vshftop;
		deleteop = beep;
		break;

	/*
	 * r		Replace character under cursor with single following
	 *		character.
	 */
	case 'r':
D 7
		vrep(cnt);
E 7
I 4
		vmacchng(1);
I 7
		vrep(cnt);
E 7
E 4
		return;

	default:
		goto nocount;
	}
I 4
	vmacchng(1);
E 4
	/*
	 * Had an operator, so accept another count.
	 * Multiply counts together.
	 */
	if (isdigit(peekkey()) && peekkey() != '0') {
		cnt *= vgetcnt();
		Xcnt = cnt;
		forbid (cnt <= 0);
	}

	/*
	 * Get next character, mapping it and saving as
	 * part of command for repeat.
	 */
	c = map(getesc(),arrows);
	if (c == 0)
		return;
	if (!subop)
		*lastcp++ = c;
nocount:
	opf = moveop;
	switch (c) {

	/*
	 * b		Back up a word.
	 * B		Back up a word, liberal definition.
	 */
	case 'b':
	case 'B':
		dir = -1;
		/* fall into ... */

	/*
	 * w		Forward a word.
	 * W		Forward a word, liberal definition.
	 */
	case 'W':
	case 'w':
		wdkind = c & ' ';
D 14
		forbid(lfind(2, cnt, opf, 0) < 0);
E 14
I 14
		forbid(lfind(2, cnt, opf, (line *) 0) < 0);
E 14
		vmoving = 0;
		break;

	/*
	 * E		to end of following blank/nonblank word
	 */
	case 'E':
		wdkind = 0;
		goto ein;

	/*
	 * e		To end of following word.
	 */
	case 'e':
		wdkind = 1;
ein:
D 14
		forbid(lfind(3, cnt - 1, opf, 0) < 0);
E 14
I 14
		forbid(lfind(3, cnt - 1, opf, (line *) 0) < 0);
E 14
		vmoving = 0;
		break;

	/*
	 * (		Back an s-expression.
	 */
	case '(':
		dir = -1;
		/* fall into... */

	/*
	 * )		Forward an s-expression.
	 */
	case ')':
		forbid(lfind(0, cnt, opf, (line *) 0) < 0);
		markDOT();
		break;

	/*
	 * {		Back an s-expression, but don't stop on atoms.
	 *		In text mode, a paragraph.  For C, a balanced set
	 *		of {}'s.
	 */
	case '{':
		dir = -1;
		/* fall into... */

	/*
	 * }		Forward an s-expression, but don't stop on atoms.
	 *		In text mode, back paragraph.  For C, back a balanced
	 *		set of {}'s.
	 */
	case '}':
		forbid(lfind(1, cnt, opf, (line *) 0) < 0);
		markDOT();
		break;

	/*
	 * %		To matching () or {}.  If not at ( or { scan for
	 *		first such after cursor on this line.
	 */
	case '%':
		vsave();
		i = lmatchp((line *) 0);
I 8
#ifdef TRACE
		if (trace)
			fprintf(trace, "after lmatchp in %, dot=%d, wdot=%d, dol=%d\n", lineno(dot), lineno(wdot), lineno(dol));
#endif
E 8
		getDOT();
		forbid(!i);
		if (opf != vmove)
			if (dir > 0)
				wcursor++;
			else
				cursor++;
		else
			markDOT();
		vmoving = 0;
		break;

	/*
	 * [		Back to beginning of defun, i.e. an ( in column 1.
	 *		For text, back to a section macro.
	 *		For C, back to a { in column 1 (~~ beg of function.)
	 */
	case '[':
		dir = -1;
		/* fall into ... */

	/*
	 * ]		Forward to next defun, i.e. a ( in column 1.
	 *		For text, forward section.
	 *		For C, forward to a } in column 1 (if delete or such)
	 *		or if a move to a { in column 1.
	 */
	case ']':
		if (!vglobp)
			forbid(getkey() != c);
D 6
		if (Xhadcnt)
			vsetsiz(Xcnt);
E 6
I 6
		forbid (Xhadcnt);
E 6
		vsave();
		i = lbrack(c, opf);
		getDOT();
		forbid(!i);
		markDOT();
		if (ospeed > B300)
			hold |= HOLDWIG;
		break;

	/*
	 * ,		Invert last find with f F t or T, like inverse
	 *		of ;.
	 */
	case ',':
		forbid (lastFKND == 0);
		c = isupper(lastFKND) ? tolower(lastFKND) : toupper(lastFKND);
D 3
		ungetkey(lastFCHR);
E 3
I 3
		i = lastFCHR;
E 3
		if (vglobp == 0)
			vglobp = "";
		subop++;
		goto nocount;

	/*
	 * 0		To beginning of real line.
	 */
	case '0':
		wcursor = linebuf;
		vmoving = 0;
		break;

	/*
	 * ;		Repeat last find with f F t or T.
	 */
	case ';':
		forbid (lastFKND == 0);
		c = lastFKND;
D 3
		ungetkey(lastFCHR);
E 3
I 3
		i = lastFCHR;
E 3
		subop++;
		goto nocount;

	/*
	 * F		Find single character before cursor in current line.
	 * T		Like F, but stops before character.
	 */
	case 'F':	/* inverted find */
	case 'T':
		dir = -1;
		/* fall into ... */

	/*
	 * f		Find single character following cursor in current line.
	 * t		Like f, but stope before character.
	 */
	case 'f':	/* find */
	case 't':
D 3
		i = getesc();
		if (i == 0)
			return;
		if (!subop)
E 3
I 3
		if (!subop) {
			i = getesc();
			if (i == 0)
				return;
E 3
			*lastcp++ = i;
I 3
		}
E 3
		if (vglobp == 0)
			lastFKND = c, lastFCHR = i;
		for (; cnt > 0; cnt--)
			forbid (find(i) == 0);
		vmoving = 0;
		switch (c) {

		case 'T':
			wcursor++;
			break;

		case 't':
			wcursor--;
		case 'f':
fixup:
			if (moveop != vmove)
				wcursor++;
			break;
		}
		break;

	/*
	 * |		Find specified print column in current line.
	 */
	case '|':
		if (Pline == numbline)
			cnt += 8;
		vmovcol = cnt;
		vmoving = 1;
		wcursor = vfindcol(cnt);
		break;

	/*
	 * ^		To beginning of non-white space on line.
	 */
	case '^':
		wcursor = vskipwh(linebuf);
		vmoving = 0;
		break;

	/*
	 * $		To end of line.
	 */
	case '$':
		if (opf == vmove) {
			vmoving = 1;
			vmovcol = 20000;
		} else
			vmoving = 0;
		if (cnt > 1) {
			if (opf == vmove) {
				wcursor = 0;
				cnt--;
			} else
				wcursor = linebuf;
			/* This is wrong at EOF */
			wdot = dot + cnt;
			break;
		}
		if (linebuf[0]) {
			wcursor = strend(linebuf) - 1;
			goto fixup;
		}
		wcursor = linebuf;
		break;

	/*
	 * h		Back a character.
	 * ^H		Back a character.
	 */
	case 'h':
D 15
	case CTRL(h):
E 15
I 15
	case CTRL('h'):
E 15
		dir = -1;
		/* fall into ... */

	/*
	 * space	Forward a character.
	 */
	case 'l':
	case ' ':
		forbid (margin() || opf == vmove && edge());
		while (cnt > 0 && !margin())
			wcursor += dir, cnt--;
		if (margin() && opf == vmove || wcursor < linebuf)
			wcursor -= dir;
		vmoving = 0;
		break;

	/*
	 * D		Delete to end of line, short for d$.
	 */
	case 'D':
		cnt = INF;
		goto deleteit;

	/*
	 * X		Delete character before cursor.
	 */
	case 'X':
		dir = -1;
		/* fall into ... */
deleteit:
	/*
	 * x		Delete character at cursor, leaving cursor where it is.
	 */
	case 'x':
		if (margin())
			goto errlab;
I 4
		vmacchng(1);
E 4
		while (cnt > 0 && !margin())
			wcursor += dir, cnt--;
		opf = deleteop;
		vmoving = 0;
		break;

	default:
		/*
		 * Stuttered operators are equivalent to the operator on
		 * a line, thus turn dd into d_.
		 */
		if (opf == vmove || c != workcmd[0]) {
errlab:
			beep();
			vmacp = 0;
			return;
		}
		/* fall into ... */

	/*
	 * _		Target for a line or group of lines.
	 *		Stuttering is more convenient; this is mostly
	 *		for aesthetics.
	 */
	case '_':
		wdot = dot + cnt - 1;
		vmoving = 0;
		wcursor = 0;
		break;

	/*
	 * H		To first, home line on screen.
	 *		Count is for count'th line rather than first.
	 */
	case 'H':
		wdot = (dot - vcline) + cnt - 1;
		if (opf == vmove)
			markit(wdot);
		vmoving = 0;
		wcursor = 0;
		break;

	/*
	 * -		Backwards lines, to first non-white character.
	 */
	case '-':
		wdot = dot - cnt;
		vmoving = 0;
		wcursor = 0;
		break;

	/*
	 * ^P		To previous line same column.  Ridiculous on the
	 *		console of the VAX since it puts console in LSI mode.
	 */
	case 'k':
D 15
	case CTRL(p):
E 15
I 15
	case CTRL('p'):
E 15
		wdot = dot - cnt;
		if (vmoving == 0)
			vmoving = 1, vmovcol = column(cursor);
		wcursor = 0;
		break;

	/*
	 * L		To last line on screen, or count'th line from the
	 *		bottom.
	 */
	case 'L':
		wdot = dot + vcnt - vcline - cnt;
		if (opf == vmove)
			markit(wdot);
		vmoving = 0;
		wcursor = 0;
		break;

	/*
	 * M		To the middle of the screen.
	 */
	case 'M':
		wdot = dot + ((vcnt + 1) / 2) - vcline - 1;
		if (opf == vmove)
			markit(wdot);
		vmoving = 0;
		wcursor = 0;
		break;

	/*
	 * +		Forward line, to first non-white.
	 *
	 * CR		Convenient synonym for +.
	 */
	case '+':
	case CR:
		wdot = dot + cnt;
		vmoving = 0;
		wcursor = 0;
		break;

	/*
	 * ^N		To next line, same column if possible.
	 *
	 * LF		Linefeed is a convenient synonym for ^N.
	 */
D 15
	case CTRL(n):
E 15
I 15
	case CTRL('n'):
E 15
	case 'j':
	case NL:
		wdot = dot + cnt;
		if (vmoving == 0)
			vmoving = 1, vmovcol = column(cursor);
		wcursor = 0;
		break;

	/*
	 * n		Search to next match of current pattern.
	 */
	case 'n':
		vglobp = vscandir;
		c = *vglobp++;
		goto nocount;

	/*
	 * N		Like n but in reverse direction.
	 */
	case 'N':
		vglobp = vscandir[0] == '/' ? "?" : "/";
		c = *vglobp++;
		goto nocount;

	/*
	 * '		Return to line specified by following mark,
	 *		first white position on line.
	 *
	 * `		Return to marked line at remembered column.
	 */
	case '\'':
	case '`':
		d = c;
		c = getesc();
		if (c == 0)
			return;
		c = markreg(c);
		forbid (c == 0);
		wdot = getmark(c);
		forbid (wdot == NOLINE);
D 6
		if (Xhadcnt)
			vsetsiz(Xcnt);
E 6
I 6
		forbid (Xhadcnt);
E 6
		vmoving = 0;
		wcursor = d == '`' ? ncols[c - 'a'] : 0;
		if (opf == vmove && (wdot != dot || (d == '`' && wcursor != cursor)))
			markDOT();
		if (wcursor) {
			vsave();
			getline(*wdot);
			if (wcursor > strend(linebuf))
				wcursor = 0;
			getDOT();
		}
		if (ospeed > B300)
			hold |= HOLDWIG;
		break;

	/*
	 * G		Goto count'th line, or last line if no count
	 *		given.
	 */
	case 'G':
		if (!Xhadcnt)
			cnt = lineDOL();
		wdot = zero + cnt;
		forbid (wdot < one || wdot > dol);
		if (opf == vmove)
			markit(wdot);
		vmoving = 0;
		wcursor = 0;
		break;

	/*
	 * /		Scan forward for following re.
	 * ?		Scan backward for following re.
	 */
	case '/':
	case '?':
D 6
		if (Xhadcnt)
			vsetsiz(Xcnt);
E 6
I 6
		forbid (Xhadcnt);
E 6
		vsave();
		ocurs = cursor;
I 3
		odot = dot;
E 3
		wcursor = 0;
		if (readecho(c))
			return;
		if (!vglobp)
			vscandir[0] = genbuf[0];
		oglobp = globp; CP(vutmp, genbuf); globp = vutmp;
D 3
		d = peekc; ungetchar(0); fixech();
E 3
I 3
		d = peekc;
fromsemi:
		ungetchar(0);
		fixech();
E 3
		CATCH
#ifndef CBREAK
			/*
			 * Lose typeahead (ick).
			 */
			vcook();
#endif
			addr = address(cursor);
#ifndef CBREAK
			vraw();
#endif
		ONERR
#ifndef CBREAK
			vraw();
#endif
I 3
slerr:
E 3
			globp = oglobp;
I 3
			dot = odot;
			cursor = ocurs;
E 3
			ungetchar(d);
			splitw = 0;
			vclean();
			vjumpto(dot, ocurs, 0);
			return;
		ENDCATCH
		if (globp == 0)
			globp = "";
		else if (peekc)
			--globp;
I 3
		if (*globp == ';') {
			/* /foo/;/bar/ */
			globp++;
			dot = addr;
			cursor = loc1;
			goto fromsemi;
		}
		dot = odot;
E 3
		ungetchar(d);
		c = 0;
		if (*globp == 'z')
			globp++, c = '\n';
		if (any(*globp, "^+-."))
			c = *globp++;
		i = 0;
		while (isdigit(*globp))
			i = i * 10 + *globp++ - '0';
D 3
		if (*globp)
E 3
I 3
		if (any(*globp, "^+-."))
E 3
			c = *globp++;
I 3
		if (*globp) {
			/* random junk after the pattern */
			beep();
			goto slerr;
		}
E 3
		globp = oglobp;
		splitw = 0;
		vmoving = 0;
		wcursor = loc1;
		if (i != 0)
			vsetsiz(i);
		if (opf == vmove) {
			if (state == ONEOPEN || state == HARDOPEN)
				outline = destline = WBOT;
			if (addr != dot || loc1 != cursor)
				markDOT();
			if (loc1 > linebuf && *loc1 == 0)
				loc1--;
			if (c)
				vjumpto(addr, loc1, c);
			else {
				vmoving = 0;
				if (loc1) {
					vmoving++;
					vmovcol = column(loc1);
				}
				getDOT();
				if (state == CRTOPEN && addr != dot)
					vup1();
				vupdown(addr - dot, NOSTR);
			}
			return;
		}
		lastcp[-1] = 'n';
		getDOT();
		wdot = addr;
		break;
	}
	/*
	 * Apply.
	 */
	if (vreg && wdot == 0)
		wdot = dot;
	(*opf)(c);
I 14
flusho();
E 14
	wdot = NOLINE;
}

/*
 * Find single character c, in direction dir from cursor.
 */
find(c)
D 16
	char c;
E 16
I 16
	u_char c;
E 16
{

	for(;;) {
		if (edge())
			return (0);
		wcursor += dir;
		if (*wcursor == c)
			return (1);
	}
}

/*
 * Do a word motion with operator op, and cnt more words
 * to go after this.
 */
word(op, cnt)
	register int (*op)();
	int cnt;
{
	register int which;
D 16
	register char *iwc;
E 16
I 16
	register u_char *iwc;
E 16
	register line *iwdot = wdot;

	if (dir == 1) {
		iwc = wcursor;
		which = wordch(wcursor);
		while (wordof(which, wcursor)) {
			if (cnt == 1 && op != vmove && wcursor[1] == 0) {
				wcursor++;
				break;
			}
			if (!lnext())
				return (0);
			if (wcursor == linebuf)
				break;
		}
		/* Unless last segment of a change skip blanks */
		if (op != vchange || cnt > 1)
			while (!margin() && blank())
				wcursor++;
		else
			if (wcursor == iwc && iwdot == wdot && *iwc)
				wcursor++;
		if (op == vmove && margin())
			wcursor--;
	} else {
		if (!lnext())
			return (0);
		while (blank())
			if (!lnext())
				return (0);
		if (!margin()) {
			which = wordch(wcursor);
			while (!margin() && wordof(which, wcursor))
				wcursor--;
		}
		if (wcursor < linebuf || !wordof(which, wcursor))
			wcursor++;
	}
	return (1);
}

/*
 * To end of word, with operator op and cnt more motions
 * remaining after this.
 */
eend(op)
	register int (*op)();
{
	register int which;

	if (!lnext())
		return;
	while (blank())
		if (!lnext())
			return;
	which = wordch(wcursor);
	while (wordof(which, wcursor)) {
		if (wcursor[1] == 0) {
			wcursor++;
			break;
		}
		if (!lnext())
			return;
	}
	if (op != vchange && op != vdelete && wcursor > linebuf)
		wcursor--;
}

/*
 * Wordof tells whether the character at *wc is in a word of
 * kind which (blank/nonblank words are 0, conservative words 1).
 */
wordof(which, wc)
D 16
	char which;
	register char *wc;
E 16
I 16
	u_char which;
	register u_char *wc;
E 16
{

	if (isspace(*wc))
		return (0);
	return (!wdkind || wordch(wc) == which);
}

/*
 * Wordch tells whether character at *wc is a word character
 * i.e. an alfa, digit, or underscore.
 */
wordch(wc)
D 16
	char *wc;
E 16
I 16
	u_char *wc;
E 16
{
	register int c;

	c = wc[0];
	return (isalpha(c) || isdigit(c) || c == '_');
}

/*
 * Edge tells when we hit the last character in the current line.
 */
edge()
{

	if (linebuf[0] == 0)
		return (1);
	if (dir == 1)
		return (wcursor[1] == 0);
	else
		return (wcursor == linebuf);
}

/*
 * Margin tells us when we have fallen off the end of the line.
 */
margin()
{

	return (wcursor < linebuf || wcursor[0] == 0);
}
E 1
