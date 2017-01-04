h39426
s 00016/00016/00541
d D 7.5 03/04/13 15:19:35 msokolov 13 12
c 8-bit ex
e
s 00004/00003/00553
d D 7.4 87/03/09 12:46:12 conrad 12 11
c make ex/vi work on vms
e
s 00001/00001/00555
d D 7.3 85/06/07 18:24:58 bloom 11 10
c fix sccsid and copyright for xstr
e
s 00010/00002/00546
d D 7.2 85/05/31 15:15:12 dist 10 9
c Add copyright
e
s 00002/00002/00546
d D 7.1 81/07/08 22:35:20 mark 9 8
c release 3.7 - a few bug fixes and a few new features.
e
s 00003/00001/00545
d D 6.2 80/10/23 16:20:06 mark 8 7
c fixed various bugs prior to 3.6 release
e
s 00000/00000/00546
d D 6.1 80/10/19 01:23:00 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00546
d D 5.1 80/08/20 16:15:43 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00544
d D 4.2 80/08/01 20:43:59 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00009/00003/00536
d D 4.1 80/08/01 00:19:02 mark 4 3
c release 3.4, June 24, 1980
e
s 00000/00000/00539
d D 3.1 80/07/31 23:44:17 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00539
d D 2.1 80/07/31 23:21:42 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00539/00000/00000
d D 1.1 80/07/31 23:00:58 mark 1 0
c date and time created 80/07/31 23:00:58 by mark
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
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 9
I 9
D 10
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 11
static char sccsid[] = "%W% (Berkeley) %G%";
E 11
I 11
static char *sccsid = "%W% (Berkeley) %G%";
E 11
#endif not lint

E 10
E 9
E 5
#include "ex.h"
#include "ex_tty.h"
#include "ex_vis.h"

/*
 * Routines to handle structure.
 * Operations supported are:
 *	( ) { } [ ]
 *
 * These cover:		LISP		TEXT
 *	( )		s-exprs		sentences
 *	{ }		list at same	paragraphs
 *	[ ]		defuns		sections
 *
 * { and } for C used to attempt to do something with matching {}'s, but
 * I couldn't find definitions which worked intuitively very well, so I
 * scrapped this.
 *
 * The code here is very hard to understand.
 */
line	*llimit;
int	(*lf)();

#ifdef LISPCODE
int	lindent();
#endif

bool	wasend;

/*
 * Find over structure, repeated count times.
 * Don't go past line limit.  F is the operation to
 * be performed eventually.  If pastatom then the user said {}
 * rather than (), implying past atoms in a list (or a paragraph
 * rather than a sentence.
 */
lfind(pastatom, cnt, f, limit)
	bool pastatom;
	int cnt, (*f)();
	line *limit;
{
	register int c;
	register int rc = 0;
D 13
	char save[LBSIZE];
E 13
I 13
	u_char save[LBSIZE];
E 13

	/*
	 * Initialize, saving the current line buffer state
	 * and computing the limit; a 0 argument means
	 * directional end of file.
	 */
	wasend = 0;
	lf = f;
	strcpy(save, linebuf);
	if (limit == 0)
		limit = dir < 0 ? one : dol;
	llimit = limit;
	wdot = dot;
	wcursor = cursor;

	if (pastatom >= 2) {
		while (cnt > 0 && word(f, cnt))
			cnt--;
		if (pastatom == 3)
			eend(f);
		if (dot == wdot) {
			wdot = 0;
			if (cursor == wcursor)
				rc = -1;
		}
	}
#ifdef LISPCODE
	else if (!value(LISP)) {
#else
	else {
#endif
D 13
		char *icurs;
E 13
I 13
		u_char *icurs;
E 13
		line *idot;

		if (linebuf[0] == 0) {
			do
				if (!lnext())
					goto ret;
			while (linebuf[0] == 0);
			if (dir > 0) {
				wdot--;
				linebuf[0] = 0;
				wcursor = linebuf;
				/*
				 * If looking for sentence, next line
				 * starts one.
				 */
				if (!pastatom) {
					icurs = wcursor;
					idot = wdot;
					goto begin;
				}
			}
		}
		icurs = wcursor;
		idot = wdot;

		/*
		 * Advance so as to not find same thing again.
		 */
		if (dir > 0) {
			if (!lnext()) {
				rc = -1;
				goto ret;
			}
		} else
			ignore(lskipa1(""));

		/*
		 * Count times find end of sentence/paragraph.
		 */
begin:
		for (;;) {
			while (!endsent(pastatom))
				if (!lnext())
					goto ret;
			if (!pastatom || wcursor == linebuf && endPS())
				if (--cnt <= 0)
					break;
			if (linebuf[0] == 0) {
				do
					if (!lnext())
						goto ret;
				while (linebuf[0] == 0);
			} else
				if (!lnext())
					goto ret;
		}

		/*
		 * If going backwards, and didn't hit the end of the buffer,
		 * then reverse direction.
		 */
		if (dir < 0 && (wdot != llimit || wcursor != linebuf)) {
			dir = 1;
			llimit = dot;
			/*
			 * Empty line needs special treatement.
			 * If moved to it from other than begining of next line,
			 * then a sentence starts on next line.
			 */
			if (linebuf[0] == 0 && !pastatom && 
			   (wdot != dot - 1 || cursor != linebuf)) {
D 12
				lnext();
E 12
I 12
				ignore(lnext());
E 12
				goto ret;
			}
		}

		/*
		 * If we are not at a section/paragraph division,
		 * advance to next.
		 */
		if (wcursor == icurs && wdot == idot || wcursor != linebuf || !endPS())
			ignore(lskipa1(""));
	}
#ifdef LISPCODE
	else {
		c = *wcursor;
		/*
		 * Startup by skipping if at a ( going left or a ) going
		 * right to keep from getting stuck immediately.
		 */
		if (dir < 0 && c == '(' || dir > 0 && c == ')') {
			if (!lnext()) {
				rc = -1;
				goto ret;
			}
		}
		/*
		 * Now chew up repitition count.  Each time around
		 * if at the beginning of an s-exp (going forwards)
		 * or the end of an s-exp (going backwards)
		 * skip the s-exp.  If not at beg/end resp, then stop
		 * if we hit a higher level paren, else skip an atom,
		 * counting it unless pastatom.
		 */
		while (cnt > 0) {
			c = *wcursor;
			if (dir < 0 && c == ')' || dir > 0 && c == '(') {
				if (!lskipbal("()"))
					goto ret;
				/*
 				 * Unless this is the last time going
				 * backwards, skip past the matching paren
				 * so we don't think it is a higher level paren.
				 */
				if (dir < 0 && cnt == 1)
					goto ret;
				if (!lnext() || !ltosolid())
					goto ret;
				--cnt;
			} else if (dir < 0 && c == '(' || dir > 0 && c == ')')
				/* Found a higher level paren */
				goto ret;
			else {
				if (!lskipatom())
					goto ret;
				if (!pastatom)
					--cnt;
			}
		}
	}
#endif
ret:
	strcLIN(save);
	return (rc);
}

/*
 * Is this the end of a sentence?
 */
I 12
/* ARGSUSED */
E 12
endsent(pastatom)
	bool pastatom;
{
D 13
	register char *cp = wcursor;
E 13
I 13
	register u_char *cp = wcursor;
E 13
D 12
	register int c, d;
E 12
I 12
	register int d;
E 12

	/*
	 * If this is the beginning of a line, then
	 * check for the end of a paragraph or section.
	 */
	if (cp == linebuf)
		return (endPS());

	/*
	 * Sentences end with . ! ? not at the beginning
	 * of the line, and must be either at the end of the line,
	 * or followed by 2 spaces.  Any number of intervening ) ] ' "
	 * characters are allowed.
	 */
D 12
	if (!any(c = *cp, ".!?"))
E 12
I 12
	if (!any(*cp, ".!?"))
E 12
		goto tryps;
	do
		if ((d = *++cp) == 0)
			return (1);
	while (any(d, ")]'"));
	if (*cp == 0 || *cp++ == ' ' && *cp == ' ')
		return (1);
tryps:
	if (cp[1] == 0)
		return (endPS());
	return (0);
}

/*
 * End of paragraphs/sections are respective
 * macros as well as blank lines and form feeds.
 */
endPS()
{

	return (linebuf[0] == 0 ||
		isa(svalue(PARAGRAPHS)) || isa(svalue(SECTIONS)));
	    
}

#ifdef LISPCODE
lindent(addr)
	line *addr;
{
	register int i;
D 13
	char *swcurs = wcursor;
E 13
I 13
	u_char *swcurs = wcursor;
E 13
	line *swdot = wdot;

again:
	if (addr > one) {
D 13
		register char *cp;
E 13
I 13
		register u_char *cp;
E 13
		register int cnt = 0;

		addr--;
		getline(*addr);
		for (cp = linebuf; *cp; cp++)
			if (*cp == '(')
				cnt++;
			else if (*cp == ')')
				cnt--;
		cp = vpastwh(linebuf);
		if (*cp == 0)
			goto again;
		if (cnt == 0)
			return (whitecnt(linebuf));
		addr++;
	}
	wcursor = linebuf;
	linebuf[0] = 0;
	wdot = addr;
	dir = -1;
	llimit = one;
	lf = lindent;
	if (!lskipbal("()"))
		i = 0;
	else if (wcursor == linebuf)
		i = 2;
	else {
D 13
		register char *wp = wcursor;
E 13
I 13
		register u_char *wp = wcursor;
E 13

		dir = 1;
		llimit = wdot;
		if (!lnext() || !ltosolid() || !lskipatom()) {
			wcursor = wp;
			i = 1;
		} else
			i = 0;
		i += column(wcursor) - 1;
		if (!inopen)
			i--;
	}
	wdot = swdot;
	wcursor = swcurs;
	return (i);
}
#endif

lmatchp(addr)
	line *addr;
{
	register int i;
D 13
	register char *parens, *cp;
E 13
I 13
	register u_char *parens, *cp;
E 13

D 4
	for (cp = cursor; !any(*cp, "({)}");)
E 4
I 4
	for (cp = cursor; !any(*cp, "({[)}]");)
E 4
		if (*cp++ == 0)
			return (0);
	lf = 0;
D 4
	parens = any(*cp, "()") ? "()" : "{}";
E 4
I 4
	parens = any(*cp, "()") ? "()" : any(*cp, "[]") ? "[]" : "{}";
E 4
	if (*cp == parens[1]) {
		dir = -1;
		llimit = one;
	} else {
		dir = 1;
		llimit = dol;
	}
	if (addr)
		llimit = addr;
	if (splitw)
		llimit = dot;
	wcursor = cp;
	wdot = dot;
	i = lskipbal(parens);
	return (i);
}

lsmatch(cp)
D 13
	char *cp;
E 13
I 13
	u_char *cp;
E 13
{
D 13
	char save[LBSIZE];
	register char *sp = save;
	register char *scurs = cursor;
E 13
I 13
	u_char save[LBSIZE];
	register u_char *sp = save;
	register u_char *scurs = cursor;
E 13

	wcursor = cp;
	strcpy(sp, linebuf);
	*wcursor = 0;
	strcpy(cursor, genbuf);
	cursor = strend(linebuf) - 1;
	if (lmatchp(dot - vcline)) {
		register int i = insmode;
		register int c = outcol;
		register int l = outline;

		if (!MI)
			endim();
		vgoto(splitw ? WECHO : LINE(wdot - llimit), column(wcursor) - 1);
		flush();
		sleep(1);
		vgoto(l, c);
		if (i)
			goim();
	}
I 4
	else {
		strcLIN(sp);
		strcpy(scurs, genbuf);
		if (!lmatchp((line *) 0))
			beep();
	}
E 4
	strcLIN(sp);
	wdot = 0;
	wcursor = 0;
	cursor = scurs;
}

ltosolid()
{

	return (ltosol1("()"));
}

ltosol1(parens)
D 13
	register char *parens;
E 13
I 13
	register u_char *parens;
E 13
{
D 13
	register char *cp;
E 13
I 13
	register u_char *cp;
E 13

	if (*parens && !*wcursor && !lnext())
		return (0);
	while (isspace(*wcursor) || (*wcursor == 0 && *parens))
		if (!lnext())
			return (0);
	if (any(*wcursor, parens) || dir > 0)
		return (1);
	for (cp = wcursor; cp > linebuf; cp--)
		if (isspace(cp[-1]) || any(cp[-1], parens))
			break;
	wcursor = cp;
	return (1);
}

lskipbal(parens)
D 13
	register char *parens;
E 13
I 13
	register u_char *parens;
E 13
{
	register int level = dir;
	register int c;

	do {
D 8
		if (!lnext())
E 8
I 8
		if (!lnext()) {
			wdot = NOLINE;
E 8
			return (0);
I 8
		}
E 8
		c = *wcursor;
		if (c == parens[1])
			level--;
		else if (c == parens[0])
			level++;
	} while (level);
	return (1);
}

lskipatom()
{

	return (lskipa1("()"));
}

lskipa1(parens)
D 13
	register char *parens;
E 13
I 13
	register u_char *parens;
E 13
{
	register int c;

	for (;;) {
		if (dir < 0 && wcursor == linebuf) {
			if (!lnext())
				return (0);
			break;
		}
		c = *wcursor;
		if (c && (isspace(c) || any(c, parens)))
			break;
		if (!lnext())
			return (0);
		if (dir > 0 && wcursor == linebuf)
			break;
	}
	return (ltosol1(parens));
}

lnext()
{

	if (dir > 0) {
		if (*wcursor)
			wcursor++;
		if (*wcursor)
			return (1);
		if (wdot >= llimit) {
D 4
			if (wcursor > linebuf)
E 4
I 4
			if (lf == vmove && wcursor > linebuf)
E 4
				wcursor--;
			return (0);
		}
		wdot++;
		getline(*wdot);
		wcursor = linebuf;
		return (1);
	} else {
		--wcursor;
		if (wcursor >= linebuf)
			return (1);
#ifdef LISPCODE
		if (lf == lindent && linebuf[0] == '(')
			llimit = wdot;
#endif
		if (wdot <= llimit) {
			wcursor = linebuf;
			return (0);
		}
		wdot--;
		getline(*wdot);
		wcursor = linebuf[0] == 0 ? linebuf : strend(linebuf) - 1;
		return (1);
	}
}

lbrack(c, f)
	register int c;
	int (*f)();
{
	register line *addr;

	addr = dot;
	for (;;) {
		addr += dir;
		if (addr < one || addr > dol) {
			addr -= dir;
			break;
		}
		getline(*addr);
		if (linebuf[0] == '{' ||
#ifdef LISPCODE
		    value(LISP) && linebuf[0] == '(' ||
#endif
		    isa(svalue(SECTIONS))) {
			if (c == ']' && f != vmove) {
				addr--;
				getline(*addr);
			}
			break;
		}
		if (c == ']' && f != vmove && linebuf[0] == '}')
			break;
	}
	if (addr == dot)
		return (0);
	if (f != vmove)
		wcursor = c == ']' ? strend(linebuf) : linebuf;
	else
		wcursor = 0;
	wdot = addr;
	vmoving = 0;
	return (1);
}

isa(cp)
D 13
	register char *cp;
E 13
I 13
	register u_char *cp;
E 13
{

	if (linebuf[0] != '.')
		return (0);
	for (; cp[0] && cp[1]; cp += 2)
		if (linebuf[1] == cp[0]) {
			if (linebuf[2] == cp[1])
				return (1);
			if (linebuf[2] == 0 && cp[1] == ' ')
				return (1);
		}
	return (0);
}
E 1
