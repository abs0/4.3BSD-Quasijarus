h44273
s 00007/00007/00461
d D 7.5 03/04/13 15:19:40 msokolov 12 11
c 8-bit ex
e
s 00008/00009/00460
d D 7.4 87/03/09 12:46:10 conrad 11 10
c make ex/vi work on vms
e
s 00001/00001/00468
d D 7.3 85/06/07 18:25:31 bloom 10 9
c fix sccsid and copyright for xstr
e
s 00010/00002/00459
d D 7.2 85/05/31 15:18:08 dist 9 8
c Add copyright
e
s 00002/00002/00459
d D 7.1 81/07/08 22:36:13 mark 8 7
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00000/00461
d D 6.1 80/10/19 01:23:04 mark 7 6
c preliminary release 3.6 10/18/80
e
s 00000/00000/00461
d D 5.1 80/08/20 16:16:32 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/00459
d D 4.2 80/08/01 20:44:29 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00000/00000/00460
d D 4.1 80/08/01 00:20:12 mark 4 3
c release 3.4, June 24, 1980
e
s 00000/00000/00460
d D 3.1 80/07/31 23:45:30 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00460
d D 2.1 80/07/31 23:22:10 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00460/00000/00000
d D 1.1 80/07/31 23:01:04 mark 1 0
c date and time created 80/07/31 23:01:04 by mark
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
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 8
I 8
D 9
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 9
I 9
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 10
static char sccsid[] = "%W% (Berkeley) %G%";
E 10
I 10
static char *sccsid = "%W% (Berkeley) %G%";
E 10
#endif not lint

E 9
E 8
E 5
#include "ex.h"
#include "ex_tty.h"
#include "ex_vis.h"

/*
 * Routines to adjust the window, showing specified lines
 * in certain positions on the screen, and scrolling in both
 * directions.  Code here is very dependent on mode (open versus visual).
 */

/*
 * Move in a nonlocal way to line addr.
 * If it isn't on screen put it in specified context.
 * New position for cursor is curs.
 * Like most routines here, we vsave().
 */
vmoveto(addr, curs, context)
	register line *addr;
D 12
	char *curs;
	char context;
E 12
I 12
	u_char *curs;
	u_char context;
E 12
{

	markit(addr);
	vsave();
	vjumpto(addr, curs, context);
}

/*
 * Vjumpto is like vmoveto, but doesn't mark previous
 * context or save linebuf as current line.
 */
vjumpto(addr, curs, context)
	register line *addr;
D 12
	char *curs;
	char context;
E 12
I 12
	u_char *curs;
	u_char context;
E 12
{

D 11
	noteit(0);
E 11
I 11
	ignore(noteit(0));
E 11
	if (context != 0)
		vcontext(addr, context);
	else
		vshow(addr, NOLINE);
D 11
	noteit(1);
E 11
I 11
	ignore(noteit(1));
E 11
	vnline(curs);
}

/*
 * Go up or down cnt (negative is up) to new position curs.
 */
vupdown(cnt, curs)
	register int cnt;
D 12
	char *curs;
E 12
I 12
	u_char *curs;
E 12
{

	if (cnt > 0)
		vdown(cnt, 0, 0);
	else if (cnt < 0)
		vup(-cnt, 0, 0);
	if (vcnt == 0)
		vrepaint(curs);
	else
		vnline(curs);
}

/*
 * Go up cnt lines, afterwards preferring to be ind
 * logical lines from the top of the screen.
 * If scroll, then we MUST use a scroll.
 * Otherwise clear and redraw if motion is far.
 */
vup(cnt, ind, scroll)
	register int cnt, ind;
	bool scroll;
{
	register int i, tot;

	if (dot == one) {
		beep();
		return;
	}
	vsave();
	i = lineDOT() - 1;
	if (cnt > i) {
		ind -= cnt - i;
		if (ind < 0)
			ind = 0;
		cnt = i;
	}
	if (!scroll && cnt <= vcline) {
		vshow(dot - cnt, NOLINE);
		return;
	}
	cnt -= vcline, dot -= vcline, vcline = 0;
	if (hold & HOLDWIG)
		goto contxt;
	if (state == VISUAL && !AL && !SR &&
D 11
	    cnt <= WTOP - ZERO && vfit(dot - cnt, cnt) <= WTOP - ZERO)
E 11
I 11
	    cnt <= WTOP - ex_ZERO && vfit(dot - cnt, cnt) <= WTOP - ex_ZERO)
E 11
		goto okr;
D 11
	tot = WECHO - ZERO;
E 11
I 11
	tot = WECHO - ex_ZERO;
E 11
	if (state != VISUAL || (!AL && !SR) || (!scroll && (cnt > tot || vfit(dot - cnt, cnt) > tot / 3 + 1))) {
		if (ind > basWLINES / 2)
			ind = basWLINES / 3;
contxt:
		vcontext(dot + ind - cnt, '.');
		return;
	}
okr:
	vrollR(cnt);
	if (scroll) {
		vcline += ind, dot += ind;
		if (vcline >= vcnt)
			dot -= vcline - vcnt + 1, vcline = vcnt - 1;
		getDOT();
	}
}

/*
 * Like vup, but scrolling down.
 */
vdown(cnt, ind, scroll)
	register int cnt, ind;
	bool scroll;
{
	register int i, tot;

	if (dot == dol) {
		beep();
		return;
	}
	vsave();
	i = dol - dot;
	if (cnt > i) {
		ind -= cnt - i;
		if (ind < 0)
			ind = 0;
		cnt = i;
	}
	i = vcnt - vcline - 1;
	if (!scroll && cnt <= i) {
		vshow(dot + cnt, NOLINE);
		return;
	}
	cnt -= i, dot += i, vcline += i;
	if (hold & HOLDWIG)
		goto dcontxt;
	if (!scroll) {
D 11
		tot = WECHO - ZERO;
E 11
I 11
		tot = WECHO - ex_ZERO;
E 11
		if (state != VISUAL || cnt - tot > 0 || vfit(dot, cnt) > tot / 3 + 1) {
dcontxt:
			vcontext(dot + cnt, '.');
			return;
		}
	}
	if (cnt > 0)
		vroll(cnt);
	if (state == VISUAL && scroll) {
		vcline -= ind, dot -= ind;
		if (vcline < 0)
			dot -= vcline, vcline = 0;
		getDOT();
	}
}

/*
 * Show line addr in context where on the screen.
 * Work here is in determining new top line implied by
 * this placement of line addr, since we always draw from the top.
 */
vcontext(addr, where)
	register line *addr;
D 12
	char where;
E 12
I 12
	u_char where;
E 12
{
	register line *top;

	getline(*addr);
	if (state != VISUAL)
		top = addr;
	else switch (where) {

	case '^':
		addr = vback(addr, basWLINES - vdepth());
		getline(*addr);
		/* fall into ... */

	case '-':
		top = vback(addr, basWLINES - vdepth());
		getline(*addr);
		break;

	case '.':
		top = vback(addr, basWLINES / 2 - vdepth());
		getline(*addr);
		break;

	default:
		top = addr;
		break;
	}
	if (state == ONEOPEN && LINE(0) == WBOT)
		vup1();
	vcnt = vcline = 0;
	vclean();
	if (state == CRTOPEN)
		vup1();
	vshow(addr, top);
}

/*
 * Get a clean line.  If we are in a hard open
 * we may be able to reuse the line we are on
 * if it is blank.  This is a real win.
 */
vclean()
{

	if (state != VISUAL && state != CRTOPEN) {
		destcol = 0;
		if (!ateopr())
			vup1();
		vcnt = 0;
	}
}

/*
 * Show line addr with the specified top line on the screen.
 * Top may be 0; in this case have vcontext compute the top
 * (and call us recursively).  Eventually, we clear the screen
 * (or its open mode equivalent) and redraw.
 */
vshow(addr, top)
	line *addr, *top;
{
#ifndef CBREAK
	register bool fried = 0;
#endif
	register int cnt = addr - dot;
	register int i = vcline + cnt;
	short oldhold = hold;

	if (state != HARDOPEN && state != ONEOPEN && i >= 0 && i < vcnt) {
		dot = addr;
		getDOT();
		vcline = i;
		return;
	}
	if (state != VISUAL) {
		dot = addr;
		vopen(dot, WBOT);
		return;
	}
	if (top == 0) {
		vcontext(addr, '.');
		return;
	}
	dot = top;
#ifndef CBREAK
	if (vcookit(2))
		fried++, vcook();
#endif
	oldhold = hold;
	hold |= HOLDAT;
	vclear();
	vreset(0);
	vredraw(WTOP);
	/* error if vcline >= vcnt ! */
	vcline = addr - top;
	dot = addr;
	getDOT();
	hold = oldhold;
	vsync(LASTLINE);
#ifndef CBREAK
	if (fried)
		flusho(), vraw();
#endif
}

/*
 * reset the state.
 * If inecho then leave us at the beginning of the echo
 * area;  we are called this way in the middle of a :e escape
 * from visual, e.g.
 */
vreset(inecho)
	bool inecho;
{

	vcnt = vcline = 0;
	WTOP = basWTOP;
	WLINES = basWLINES;
	if (inecho)
		splitw = 1, vgoto(WECHO, 0);
}

/*
 * Starting from which line preceding tp uses almost (but not more
 * than) cnt physical lines?
 */
line *
vback(tp, cnt)
	register int cnt;
	register line *tp;
{
	register int d;

	if (cnt > 0)
		for (; tp > one; tp--) {
			getline(tp[-1]);
			d = vdepth();
			if (d > cnt)
				break;
			cnt -= d;
		}
	return (tp);
}

/*
 * How much scrolling will it take to roll cnt lines starting at tp?
 */
vfit(tp, cnt)
	register line *tp;
	int cnt;
{
	register int j;

	j = 0;
	while (cnt > 0) {
		cnt--;
		getline(tp[cnt]);
		j += vdepth();
	}
	if (tp > dot)
		j -= WBOT - LASTLINE;
	return (j);
}

/*
 * Roll cnt lines onto the screen.
 */
vroll(cnt)
	register int cnt;
{
#ifndef CBREAK
	register bool fried = 0;
#endif
	short oldhold = hold;

#ifdef ADEBUG
	if (trace)
		tfixnl(), fprintf(trace, "vroll(%d)\n", cnt);
#endif
	if (state != VISUAL)
		hold |= HOLDAT|HOLDROL;
	if (WBOT == WECHO) {
		vcnt = 0;
		if (state == ONEOPEN)
			vup1();
	}
#ifndef CBREAK
	if (vcookit(cnt))
		fried++, vcook();
#endif
D 11
	for (; cnt > 0 && Peekkey != ATTN; cnt--) {
E 11
I 11
	for (; cnt > 0 && Peek_key != ATTN; cnt--) {
E 11
		dot++, vcline++;
		vopen(dot, LASTLINE);
		vscrap();
	}
	hold = oldhold;
	if (state == HARDOPEN)
		sethard();
	vsyncCL();
#ifndef CBREAK
	if (fried)
		flusho(), vraw();
#endif
}

/*
 * Roll backwards (scroll up).
 */
vrollR(cnt)
	register int cnt;
{
D 11
	register bool fried = 0;
E 11
	short oldhold = hold;

#ifdef ADEBUG
	if (trace)
		tfixnl(), fprintf(trace, "vrollR(%d), dot=%d\n", cnt, lineDOT());
#endif
#ifndef CBREAK
	if (vcookit(cnt))
		fried++, vcook();
#endif
	if (WBOT == WECHO)
		vcnt = 0;
	heldech = 0;
	hold |= HOLDAT|HOLDECH;
D 11
	for (; cnt > 0 && Peekkey != ATTN; cnt--) {
E 11
I 11
	for (; cnt > 0 && Peek_key != ATTN; cnt--) {
E 11
		dot--;
		vopen(dot, WTOP);
		vscrap();
	}
	hold = oldhold;
	if (heldech)
		vclrech(0);
	vsync(LINE(vcnt-1));
#ifndef CBREAK
	if (fried)
		flusho(), vraw();
#endif
}

/*
 * Go into cooked mode (allow interrupts) during
 * a scroll if we are at less than 1200 baud and not
 * a 'vi' command, of if we are in a 'vi' command and the
 * scroll is more than 2 full screens.
 *
 * BUG:		An interrupt during a scroll in this way
 *		dumps to command mode.
 */
vcookit(cnt)
	register int cnt;
{

	return (cnt > 1 && (ospeed < B1200 && !initev || cnt > LINES * 2));
}

/*
 * Determine displayed depth of current line.
 */
vdepth()
{
	register int d;

D 11
	d = (column(NOSTR) + WCOLS - 1 + (Putchar == listchar) + IN) / WCOLS;
E 11
I 11
	d = (column(NOSTR) + WCOLS - 1 + (Put_char == listchar) + IN) / WCOLS;
E 11
#ifdef ADEBUG
	if (trace)
		tfixnl(), fprintf(trace, "vdepth returns %d\n", d == 0 ? 1 : d);
#endif
	return (d == 0 ? 1 : d);
}

/*
 * Move onto a new line, with cursor at position curs.
 */
vnline(curs)
D 12
	char *curs;
E 12
I 12
	u_char *curs;
E 12
{

	if (curs)
		wcursor = curs;
	else if (vmoving)
		wcursor = vfindcol(vmovcol);
	else
		wcursor = vskipwh(linebuf);
	cursor = linebuf;
	vmove();
}
E 1
