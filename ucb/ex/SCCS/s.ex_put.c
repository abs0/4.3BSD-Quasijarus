h45117
s 00030/00028/01146
d D 7.12 03/04/13 15:18:57 msokolov 24 23
c 8-bit ex
e
s 00004/00004/01170
d D 7.11 88/01/02 23:12:26 bostic 23 22
c fix CTRL macro for ANSI C
e
s 00039/00033/01135
d D 7.10 87/03/09 12:46:51 conrad 22 21
c make ex/vi work on vms
e
s 00001/00001/01167
d D 7.9 85/06/07 18:19:30 bloom 21 20
c fix sccsid and copyright for xstr
e
s 00010/00002/01158
d D 7.8 85/05/31 13:55:21 dist 20 18
c Add copyright
e
s 00010/00002/01118
d D 5.2.1.1 85/05/31 12:04:24 dist 19 7
c Add copyright
e
s 00001/00001/01159
d D 7.7 81/10/16 09:06:40 mark 18 17
c fixed bug in nomesg that would chmod . to zero.
e
s 00003/00003/01157
d D 7.6 81/09/11 10:41:00 mark 17 16
c fixed bug causing OOPS when vi'ing multiple files
e
s 00001/00001/01159
d D 7.5 81/09/09 19:18:14 mark 16 15
c fixed bug with UP_PARM since that doesn't use costs
e
s 00090/00038/01070
d D 7.4 81/09/09 14:25:58 mark 15 14
c improved vt100 interface.  also uses parm termcap entries.
e
s 00001/00001/01107
d D 7.3 81/09/04 10:40:31 mark 14 13
c fixed USG tty driver bug not clearing ONLCR
e
s 00002/00002/01106
d D 7.2 81/09/03 11:44:34 mark 13 12
c updates for Unix/370 and ins/del line on vt100
e
s 00009/00003/01099
d D 7.1 81/07/08 22:30:00 mark 12 11
c release 3.7 - a few bug fixes and a few new features.
e
s 00000/00036/01102
d D 6.4 80/11/08 21:22:11 mark 11 10
c moved signal catching routines to ex_subr.c so they'll be in root ovly
e
s 00000/00014/01138
d D 6.3 80/11/03 09:11:37 mark 10 9
c final 3.6 release - took out TIMEBOMB code
e
s 00002/00002/01150
d D 6.2 80/10/23 22:21:59 mark 9 8
c fixed form of timebomb output
e
s 00041/00009/01111
d D 6.1 80/10/19 01:25:37 mark 8 7
c preliminary release 3.6, 10/18/80
e
s 00003/00003/01117
d D 5.2 80/09/12 08:32:00 mark 7 6
c separated TIOCLGET and SIGTSTP since Cory only has the former
e
s 00000/00000/01120
d D 5.1 80/08/20 16:10:17 mark 6 5
c Release 3.5, August 20, 1980
e
s 00002/00001/01118
d D 4.2 80/08/01 20:40:23 mark 5 4
c Bill added more buffers, and I put in sccs.
e
s 00285/00069/00834
d D 4.1 80/08/01 00:13:15 mark 4 3
c release 3.4, June 24, 1980
e
s 00021/00006/00882
d D 3.1 80/07/31 23:38:20 mark 3 2
c release 3.3, Feb 2, 1980
e
s 00000/00000/00888
d D 2.1 80/07/31 23:18:55 mark 2 1
c release 3.2, Jan 4, 1980
e
s 00888/00000/00000
d D 1.1 80/07/31 23:00:18 mark 1 0
c date and time created 80/07/31 23:00:18 by mark
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
D 12
D 19
/* Copyright (c) 1980 Regents of the University of California */
static char *sccsid = "%W% %G%";
E 19
I 19
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 19
E 12
I 12
D 20
/* Copyright (c) 1981 Regents of the University of California */
static char *sccsid = "%W%	%G%";
E 20
I 20
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
D 21
static char sccsid[] = "%W% (Berkeley) %G%";
E 21
I 21
static char *sccsid = "%W% (Berkeley) %G%";
E 21
#endif not lint

E 20
E 12
E 5
#include "ex.h"
#include "ex_tty.h"
#include "ex_vis.h"

/*
 * Terminal driving and line formatting routines.
 * Basic motion optimizations are done here as well
 * as formatting of lines (printing of control characters,
 * line numbering and the like).
 */

/*
 * The routines outchar, putchar and pline are actually
 * variables, and these variables point at the current definitions
 * of the routines.  See the routine setflav.
 * We sometimes make outchar be routines which catch the characters
 * to be printed, e.g. if we want to see how long a line is.
 * During open/visual, outchar and putchar will be set to
 * routines in the file ex_vput.c (vputchar, vinschar, etc.).
 */
int	(*Outchar)() = termchar;
D 22
int	(*Putchar)() = normchar;
E 22
I 22
int	(*Put_char)() = normchar;
E 22
int	(*Pline)() = normline;

int (*
setlist(t))()
	bool t;
{
	register int (*P)();

	listf = t;
D 22
	P = Putchar;
	Putchar = t ? listchar : normchar;
E 22
I 22
	P = Put_char;
	Put_char = t ? listchar : normchar;
E 22
	return (P);
}

int (*
setnumb(t))()
	bool t;
{
	register int (*P)();

	numberf = t;
	P = Pline;
	Pline = t ? numbline : normline;
	return (P);
}

/*
 * Format c for list mode; leave things in common
 * with normal print mode to be done by normchar.
 */
listchar(c)
	register short c;
{

D 24
	c &= (TRIM|QUOTE);
E 24
I 24
	c &= (QUOTE|TRIM8);
E 24
	switch (c) {

	case '\t':
	case '\b':
		outchar('^');
		c = ctlof(c);
		break;

	case '\n':
		break;

	case '\n' | QUOTE:
		outchar('$');
		break;

	default:
		if (c & QUOTE)
			break;
		if (c < ' ' && c != '\n' || c == DELETE)
			outchar('^'), c = ctlof(c);
I 24
		if (isC1(c))
			outchar('~'), c = ctlof(c & TRIM7);
E 24
		break;
	}
	normchar(c);
}

/*
 * Format c for printing.  Handle funnies of upper case terminals
 * and crocky hazeltines which don't have ~.
 */
normchar(c)
	register short c;
{
D 24
	register char *colp;
E 24
I 24
	register u_char *colp;
E 24

D 24
	c &= (TRIM|QUOTE);
E 24
I 24
	c &= (QUOTE|TRIM8);
E 24
	if (c == '~' && HZ) {
		normchar('\\');
		c = '^';
	}
	if (c & QUOTE)
		switch (c) {

		case ' ' | QUOTE:
		case '\b' | QUOTE:
			break;

		case QUOTE:
			return;

		default:
D 24
			c &= TRIM;
E 24
I 24
			c &= TRIM8;
E 24
		}
	else if (c < ' ' && (c != '\b' || !OS) && c != '\n' && c != '\t' || c == DELETE)
D 22
		putchar('^'), c = ctlof(c);
E 22
I 22
		ex_putchar('^'), c = ctlof(c);
I 24
	else if (isC1(c))
		ex_putchar('~'), c = ctlof(c & TRIM7);
E 24
E 22
	else if (UPPERCASE)
		if (isupper(c)) {
			outchar('\\');
			c = tolower(c);
		} else {
			colp = "({)}!|^~'`";
			while (*colp++)
				if (c == *colp++) {
					outchar('\\');
					c = colp[-2];
					break;
				}
		}
	outchar(c);
}

/*
 * Print a line with a number.
 */
numbline(i)
	int i;
{

	if (shudclob)
		slobber(' ');
D 22
	printf("%6d  ", i);
E 22
I 22
	ex_printf("%6d  ", i);
E 22
	normline();
}

/*
 * Normal line output, no numbering.
 */
normline()
{
D 24
	register char *cp;
E 24
I 24
	register u_char *cp;
E 24

	if (shudclob)
		slobber(linebuf[0]);
	/* pdp-11 doprnt is not reentrant so can't use "printf" here
	   in case we are tracing */
	for (cp = linebuf; *cp;)
D 22
		putchar(*cp++);
E 22
I 22
		ex_putchar(*cp++);
E 22
	if (!inopen)
D 22
		putchar('\n' | QUOTE);
E 22
I 22
		ex_putchar('\n' | QUOTE);
E 22
}

/*
 * Given c at the beginning of a line, determine whether
 * the printing of the line will erase or otherwise obliterate
 * the prompt which was printed before.  If it won't, do it now.
 */
slobber(c)
	int c;
{

	shudclob = 0;
	switch (c) {

	case '\t':
D 22
		if (Putchar == listchar)
E 22
I 22
		if (Put_char == listchar)
E 22
			return;
		break;

	default:
		return;

	case ' ':
	case 0:
		break;
	}
	if (OS)
		return;
	flush();
	putch(' ');
	if (BC)
		tputs(BC, 0, putch);
	else
		putch('\b');
}

/*
D 24
 * The output buffer is initialized with a useful error
 * message so we don't have to keep it in data space.
E 24
I 24
 * linb stores shorts rather than chars now because we have to preserve QUOTE
 * without mangling 8-bit chars.
E 24
 */
D 4
static	char linb[66] = {
	'E', 'r', 'r', 'o', 'r', ' ', 'm', 'e', 's', 's', 'a', 'g', 'e', ' ',
	'f', 'i', 'l', 'e', ' ', 'n', 'o', 't', ' ',
	'a', 'v', 'a', 'i', 'l', 'a', 'b', 'l', 'e', '\n', 0
};
static	char *linp = linb + 33;
E 4
I 4
D 24
static	char linb[66];
D 13
static	char *linp = linb;
E 13
I 13
char *linp = linb;
E 24
I 24
static	short linb[66];
static	short *linp = linb;
E 24
E 13
E 4

/*
 * Phadnl records when we have already had a complete line ending with \n.
 * If another line starts without a flush, and the terminal suggests it,
 * we switch into -nl mode so that we can send lineffeeds to avoid
 * a lot of spacing.
 */
static	bool phadnl;

/*
 * Indirect to current definition of putchar.
 */
D 22
putchar(c)
E 22
I 22
ex_putchar(c)
E 22
	int c;
{

D 22
	(*Putchar)(c);
E 22
I 22
	(*Put_char)(c);
E 22
}

/*
 * Termchar routine for command mode.
 * Watch for possible switching to -nl mode.
 * Otherwise flush into next level of buffering when
 * small buffer fills or at a newline.
 */
termchar(c)
	int c;
{

	if (pfast == 0 && phadnl)
		pstart();
	if (c == '\n')
		phadnl = 1;
	else if (linp >= &linb[63])
		flush1();
	*linp++ = c;
	if (linp >= &linb[63]) {
		fgoto();
		flush1();
	}
}

flush()
{

	flush1();
	flush2();
}

/*
 * Flush from small line buffer into output buffer.
 * Work here is destroying motion into positions, and then
 * letting fgoto do the optimized motion.
 */
flush1()
{
D 24
	register char *lp;
	register short c;
E 24
I 24
	register short *lp;
	register int c;
E 24

	*linp = 0;
	lp = linb;
	while (*lp)
		switch (c = *lp++) {

		case '\r':
			destline += destcol / COLUMNS;
			destcol = 0;
			continue;

		case '\b':
			if (destcol)
				destcol--;
			continue;

		case ' ':
			destcol++;
			continue;

		case '\t':
			destcol += value(TABSTOP) - destcol % value(TABSTOP);
			continue;

		case '\n':
			destline += destcol / COLUMNS + 1;
			if (destcol != 0 && destcol % COLUMNS == 0)
				destline--;
			destcol = 0;
			continue;

		default:
			fgoto();
			for (;;) {
				if (AM == 0 && outcol == COLUMNS)
					fgoto();
D 24
				c &= TRIM;
E 24
I 24
				c &= TRIM8;
E 24
				putch(c);
				if (c == '\b') {
					outcol--;
					destcol--;
				} else if (c >= ' ' && c != DELETE) {
					outcol++;
					destcol++;
					if (XN && outcol % COLUMNS == 0)
D 12
						putch('\n');
E 12
I 12
						putch('\r'), putch('\n');
E 12
				}
				c = *lp++;
				if (c <= ' ')
					break;
			}
			--lp;
			continue;
		}
	linp = linb;
}

flush2()
{

	fgoto();
	flusho();
	pstop();
}

/*
 * Sync the position of the output cursor.
 * Most work here is rounding for terminal boundaries getting the
 * column position implied by wraparound or the lack thereof and
 * rolling up the screen to get destline on the screen.
 */
fgoto()
{
	register int l, c;

	if (destcol > COLUMNS - 1) {
		destline += destcol / COLUMNS;
		destcol %= COLUMNS;
	}
	if (outcol > COLUMNS - 1) {
		l = (outcol + 1) / COLUMNS;
		outline += l;
		outcol %= COLUMNS;
		if (AM == 0) {
			while (l > 0) {
				if (pfast)
D 4
					putch('\r');
				putch('\n');
E 4
I 4
					if (xCR)
						tputs(xCR, 0, putch);
					else
						putch('\r');
				if (xNL)
					tputs(xNL, 0, putch);
				else
					putch('\n');
E 4
				l--;
			}
			outcol = 0;
		}
		if (outline > LINES - 1) {
			destline -= outline - (LINES - 1);
			outline = LINES - 1;
		}
	}
	if (destline > LINES - 1) {
		l = destline;
		destline = LINES - 1;
		if (outline < LINES - 1) {
			c = destcol;
			if (pfast == 0 && (!CA || holdcm))
				destcol = 0;
			fgoto();
			destcol = c;
		}
		while (l > LINES - 1) {
D 4
			putch('\n');
E 4
I 4
			/*
			 * The following linefeed (or simulation thereof)
			 * is supposed to scroll up the screen, since we
			 * are on the bottom line.  We make the assumption
			 * that linefeed will scroll.  If ns is in the
			 * capability list this won't work.  We should
			 * probably have an sc capability but sf will
			 * generally take the place if it works.
			 *
			 * Superbee glitch:  in the middle of the screen we
			 * have to use esc B (down) because linefeed screws up
			 * in "Efficient Paging" (what a joke) mode (which is
			 * essential in some SB's because CRLF mode puts garbage
			 * in at end of memory), but you must use linefeed to
			 * scroll since down arrow won't go past memory end.
			 * I turned this off after recieving Paul Eggert's
			 * Superbee description which wins better.
			 */
			if (xNL /* && !XB */ && pfast)
				tputs(xNL, 0, putch);
			else
				putch('\n');
E 4
			l--;
			if (pfast == 0)
				outcol = 0;
		}
	}
	if (destline < outline && !(CA && !holdcm || UP != NOSTR))
		destline = outline;
	if (CA && !holdcm)
		if (plod(costCM) > 0)
			plod(0);
		else
			tputs(tgoto(CM, destcol, destline), 0, putch);
	else
		plod(0);
	outline = destline;
	outcol = destcol;
}

/*
 * Tab to column col by flushing and then setting destcol.
 * Used by "set all".
 */
tab(col)
	int col;
{

	flush1();
	destcol = col;
}

/*
 * Move (slowly) to destination.
 * Hard thing here is using home cursor on really deficient terminals.
 * Otherwise just use cursor motions, hacking use of tabs and overtabbing
 * and backspace.
 */

static int plodcnt, plodflg;

plodput(c)
{

	if (plodflg)
		plodcnt--;
	else
		putch(c);
}

plod(cnt)
{
	register int i, j, k;
	register int soutcol, soutline;

	plodcnt = plodflg = cnt;
	soutcol = outcol;
	soutline = outline;
I 4
	/*
	 * Consider homing and moving down/right from there, vs moving
	 * directly with local motions to the right spot.
	 */
E 4
	if (HO) {
I 4
		/*
		 * i is the cost to home and tab/space to the right to
		 * get to the proper column.  This assumes ND space costs
		 * 1 char.  So i+destcol is cost of motion with home.
		 */
E 4
		if (GT)
D 4
		i = (destcol / value(HARDTABS)) + (destcol % value(HARDTABS));
E 4
I 4
			i = (destcol / value(HARDTABS)) + (destcol % value(HARDTABS));
E 4
		else
			i = destcol;
D 4
	if (destcol >= outcol) {
		j = destcol / value(HARDTABS) - outcol / value(HARDTABS);
		if (GT && j)
			j += destcol % value(HARDTABS);
E 4
I 4
		/*
		 * j is cost to move locally without homing
		 */
		if (destcol >= outcol) {	/* if motion is to the right */
			j = destcol / value(HARDTABS) - outcol / value(HARDTABS);
			if (GT && j)
				j += destcol % value(HARDTABS);
E 4
			else
				j = destcol - outcol;
D 4
	} else
E 4
I 4
		} else
			/* leftward motion only works if we can backspace. */
E 4
			if (outcol - destcol <= i && (BS || BC))
D 4
				i = j = outcol - destcol;
E 4
I 4
				i = j = outcol - destcol; /* cheaper to backspace */
E 4
			else
D 4
				j = i + 1;
E 4
I 4
				j = i + 1; /* impossibly expensive */

		/* k is the absolute value of vertical distance */
E 4
		k = outline - destline;
		if (k < 0)
			k = -k;
		j += k;
D 4
		if (i + destline < j) {
E 4
I 4

		/*
		 * Decision.  We may not have a choice if no UP.
		 */
		if (i + destline < j || (!UP && destline < outline)) {
			/*
			 * Cheaper to home.  Do it now and pretend it's a
			 * regular local motion.
			 */
E 4
			tputs(HO, 0, plodput);
			outcol = outline = 0;
		} else if (LL) {
I 4
			/*
			 * Quickly consider homing down and moving from there.
			 * Assume cost of LL is 2.
			 */
E 4
			k = (LINES - 1) - destline;
D 4
			if (i + k + 2 < j) {
E 4
I 4
			if (i + k + 2 < j && (k<=0 || UP)) {
E 4
				tputs(LL, 0, plodput);
				outcol = 0;
				outline = LINES - 1;
			}
		}
D 4
	}
E 4
I 4
	} else
	/*
	 * No home and no up means it's impossible, so we return an
	 * incredibly big number to make cursor motion win out.
	 */
		if (!UP && destline < outline)
			return (500);
E 4
	if (GT)
D 4
	i = destcol % value(HARDTABS) + destcol / value(HARDTABS);
E 4
I 4
		i = destcol % value(HARDTABS)
		    + destcol / value(HARDTABS);
E 4
	else
		i = destcol;
/*
	if (BT && outcol > destcol && (j = (((outcol+7) & ~7) - destcol - 1) >> 3)) {
		j *= (k = strlen(BT));
		if ((k += (destcol&7)) > 4)
			j += 8 - (destcol&7);
		else
			j += k;
	} else
*/
		j = outcol - destcol;
	/*
	 * If we will later need a \n which will turn into a \r\n by
	 * the system or the terminal, then don't bother to try to \r.
	 */
	if ((NONL || !pfast) && outline < destline)
		goto dontcr;
	/*
	 * If the terminal will do a \r\n and there isn't room for it,
	 * then we can't afford a \r.
	 */
	if (NC && outline >= destline)
		goto dontcr;
	/*
	 * If it will be cheaper, or if we can't back up, then send
	 * a return preliminarily.
	 */
	if (j > i + 1 || outcol > destcol && !BS && !BC) {
D 4
		plodput('\r');
E 4
I 4
		/*
		 * BUG: this doesn't take the (possibly long) length
		 * of xCR into account.
		 */
		if (xCR)
			tputs(xCR, 0, plodput);
		else
			plodput('\r');
E 4
		if (NC) {
D 4
			plodput('\n');
E 4
I 4
			if (xNL)
				tputs(xNL, 0, plodput);
			else
				plodput('\n');
E 4
			outline++;
		}
		outcol = 0;
	}
dontcr:
I 15
	/* Move down, if necessary, until we are at the desired line */
E 15
	while (outline < destline) {
D 15
		outline++;
D 4
		plodput('\n');
E 4
I 4
		if (xNL && pfast)
			tputs(xNL, 0, plodput);
		else
			plodput('\n');
E 15
I 15
		j = destline - outline;
D 17
		if (j > costDP) {
E 17
I 17
		if (j > costDP && DOWN_PARM) {
E 17
			/* Win big on Tek 4025 */
			tputs(tgoto(DOWN_PARM, 0, j), j, plodput);
			outline += j;
		}
		else {
			outline++;
			if (xNL && pfast)
				tputs(xNL, 0, plodput);
			else
				plodput('\n');
		}
E 15
E 4
		if (plodcnt < 0)
			goto out;
		if (NONL || pfast == 0)
			outcol = 0;
	}
	if (BT)
D 15
		k = strlen(BT);
E 15
I 15
		k = strlen(BT);	/* should probably be cost(BT) and moved out */
	/* Move left, if necessary, to desired column */
E 15
	while (outcol > destcol) {
		if (plodcnt < 0)
			goto out;
D 15
/*
E 15
		if (BT && !insmode && outcol - destcol > 4+k) {
			tputs(BT, 0, plodput);
			outcol--;
D 15
			outcol &= ~7;
E 15
I 15
			outcol -= outcol % value(HARDTABS); /* outcol &= ~7; */
E 15
			continue;
		}
D 15
*/
		outcol--;
		if (BC)
			tputs(BC, 0, plodput);
		else
			plodput('\b');
E 15
I 15
		j = outcol - destcol;
D 17
		if (j > costLP) {
E 17
I 17
		if (j > costLP && LEFT_PARM) {
E 17
			tputs(tgoto(LEFT_PARM, 0, j), j, plodput);
			outcol -= j;
		}
		else {
			outcol--;
			if (BC)
				tputs(BC, 0, plodput);
			else
				plodput('\b');
		}
E 15
	}
I 15
	/* Move up, if necessary, to desired row */
E 15
	while (outline > destline) {
D 15
		outline--;
		tputs(UP, 0, plodput);
E 15
I 15
		j = outline - destline;
D 16
		if (j > 1) {
E 16
I 16
		if (UP_PARM && j > 1) {
E 16
			/* Win big on Tek 4025 */
			tputs(tgoto(UP_PARM, 0, j), j, plodput);
			outline -= j;
		}
		else {
			outline--;
			tputs(UP, 0, plodput);
		}
E 15
		if (plodcnt < 0)
			goto out;
	}
I 15
	/*
	 * Now move to the right, if necessary.  We first tab to
	 * as close as we can get.
	 */
E 15
	if (GT && !insmode && destcol - outcol > 1) {
D 15
	for (;;) {
D 4
		i = (outcol / value(HARDTABS) + 1) * value(HARDTABS);
E 4
I 4
		i = tabcol(outcol, value(HARDTABS));
E 4
		if (i > destcol)
			break;
E 15
I 15
		/* tab to right as far as possible without passing col */
		for (;;) {
			i = tabcol(outcol, value(HARDTABS));
			if (i > destcol)
				break;
E 15
			if (TA)
				tputs(TA, 0, plodput);
			else
				plodput('\t');
			outcol = i;
		}
I 15
		/* consider another tab and then some backspaces */
E 15
		if (destcol - outcol > 4 && i < COLUMNS && (BC || BS)) {
			if (TA)
				tputs(TA, 0, plodput);
			else
				plodput('\t');
			outcol = i;
I 15
			/*
			 * Back up.  Don't worry about LEFT_PARM because
			 * it's never more than 4 spaces anyway.
			 */
E 15
			while (outcol > destcol) {
				outcol--;
				if (BC)
					tputs(BC, 0, plodput);
				else
					plodput('\b');
			}
		}
	}
I 15
	/*
	 * We've tabbed as much as possible.  If we still need to go
	 * further (not exact or can't tab) space over.  This is a
	 * very common case when moving to the right with space.
	 */
E 15
	while (outcol < destcol) {
D 3
		if (inopen && ND)
E 3
I 3
D 15
		/*
		 * move one char to the right.  We don't use ND space
		 * because it's better to just print the char we are
		 * moving over.  There are various exceptions, however.
		 * If !inopen, vtube contains garbage.  If the char is
		 * a null or a tab we want to print a space.  Other random
		 * chars we use space for instead, too.
		 */
D 4
#ifdef TRACE
		if (trace)
			fprintf(trace, "ND: inopen=%d, i=%d, outline=%d, outcol=%d\n", inopen, i, outline, outcol);
#endif
E 4
		if (!inopen || vtube[outline]==NULL ||
			(i=vtube[outline][outcol]) < ' ')
			i = ' ';
I 12
		if(i & QUOTE)		/* mjm: no sign extension on 3B */
			i = ' ';
E 12
		if (insmode && ND)
E 3
			tputs(ND, 0, plodput);
		else
D 3
			plodput(' ');
E 3
I 3
			plodput(i);
E 3
		outcol++;
E 15
I 15
		j = destcol - outcol;
D 17
		if (j > costRP) {
E 17
I 17
		if (j > costRP && RIGHT_PARM) {
E 17
			/*
			 * This probably happens rarely, if at all.
			 * It seems mainly useful for ANSI terminals
			 * with no hardware tabs, and I don't know
			 * of any such terminal at the moment.
			 */
			tputs(tgoto(RIGHT_PARM, 0, j), j, plodput);
			outcol += j;
		}
		else {
			/*
			 * move one char to the right.  We don't use ND space
			 * because it's better to just print the char we are
			 * moving over.  There are various exceptions, however.
			 * If !inopen, vtube contains garbage.  If the char is
			 * a null or a tab we want to print a space.  Other
			 * random chars we use space for instead, too.
			 */
			if (!inopen || vtube[outline]==NULL ||
D 24
				(i=vtube[outline][outcol]) < ' ')
E 24
I 24
			    (i=vtube[outline][outcol]&TRIM8) < ' ' || isC1(i))
E 24
				i = ' ';
D 24
			if(i & QUOTE)	/* mjm: no sign extension on 3B */
				i = ' ';
E 24
			if (insmode && ND)
				tputs(ND, 0, plodput);
			else
				plodput(i);
			outcol++;
		}
E 15
		if (plodcnt < 0)
			goto out;
	}
out:
	if (plodflg) {
		outcol = soutcol;
		outline = soutline;
	}
	return(plodcnt);
}

/*
 * An input line arrived.
 * Calculate new (approximate) screen line position.
 * Approximate because kill character echoes newline with
 * no feedback and also because of long input lines.
 */
noteinp()
{

	outline++;
	if (outline > LINES - 1)
		outline = LINES - 1;
	destline = outline;
	destcol = outcol = 0;
}

/*
 * Something weird just happened and we
 * lost track of whats happening out there.
 * Since we cant, in general, read where we are
 * we just reset to some known state.
 * On cursor addressible terminals setting to unknown
 * will force a cursor address soon.
 */
termreset()
{

	endim();
	if (TI)	/* otherwise it flushes anyway, and 'set tty=dumb' vomits */
		putpad(TI);	 /*adb change -- emit terminal initial sequence */
	destcol = 0;
	destline = LINES - 1;
	if (CA) {
		outcol = UKCOL;
		outline = UKCOL;
	} else {
		outcol = destcol;
		outline = destline;
	}
}

/*
 * Low level buffering, with the ability to drain
 * buffered output without printing it.
 */
D 24
char	*obp = obuf;
E 24
I 24
u_char	*obp = obuf;
E 24

draino()
{

	obp = obuf;
}

flusho()
{

	if (obp != obuf) {
I 22
#ifndef vms
E 22
		write(1, obuf, obp - obuf);
I 22
#else
		vms_write(1, obuf, obp - obuf);
#endif
E 22
		obp = obuf;
	}
}

putnl()
{

D 22
	putchar('\n');
E 22
I 22
	ex_putchar('\n');
E 22
}

D 22
putS(cp)
E 22
I 22
ex_putS(cp)
E 22
D 24
	char *cp;
E 24
I 24
	u_char *cp;
E 24
{

	if (cp == NULL)
		return;
	while (*cp)
		putch(*cp++);
}


putch(c)
	int c;
{

I 12
#ifdef OLD3BTTY		/* mjm */
	if(c == '\n')	/* mjm: Fake "\n\r" for '\n' til fix in 3B firmware */
		putch('\r');	/* mjm: vi does "stty -icanon" => -onlcr !! */
#endif
E 12
D 4
	*obp++ = c;
E 4
I 4
D 24
	*obp++ = c & 0177;
E 24
I 24
	*obp++ = c;
E 24
E 4
	if (obp >= &obuf[sizeof obuf])
		flusho();
}

/*
 * Miscellaneous routines related to output.
 */

/*
D 4
 * Cursor motion.
 */
char *
cgoto()
{

	return (tgoto(CM, destcol, destline));
}

/*
E 4
 * Put with padding
 */
putpad(cp)
D 24
	char *cp;
E 24
I 24
	u_char *cp;
E 24
{

	flush();
	tputs(cp, 0, putch);
}

/*
 * Set output through normal command mode routine.
 */
setoutt()
{

	Outchar = termchar;
}

/*
 * Printf (temporarily) in list mode.
 */
D 22
/*VARARGS2*/
E 22
I 22
/*VARARGS1*/
E 22
lprintf(cp, dp)
D 24
	char *cp, *dp;
E 24
I 24
	u_char *cp, *dp;
E 24
{
	register int (*P)();

	P = setlist(1);
D 22
	printf(cp, dp);
	Putchar = P;
E 22
I 22
	ex_printf(cp, dp);
	Put_char = P;
E 22
}

/*
 * Newline + flush.
 */
putNFL()
{

	putnl();
	flush();
}

/*
 * Try to start -nl mode.
 */
pstart()
{

	if (NONL)
		return;
 	if (!value(OPTIMIZE))
		return;
	if (ruptible == 0 || pfast)
		return;
	fgoto();
	flusho();
	pfast = 1;
	normtty++;
I 4
#ifndef USG3TTY
E 4
	tty.sg_flags = normf & ~(ECHO|XTABS|CRMOD);
I 4
#else
	tty = normf;
	tty.c_oflag &= ~(ONLCR|TAB3);
	tty.c_lflag &= ~ECHO;
#endif
E 4
D 22
	sTTY(1);
E 22
I 22
	ex_sTTY(1);
E 22
}

/*
 * Stop -nl mode.
 */
pstop()
{

	if (inopen)
		return;
	phadnl = 0;
	linp = linb;
	draino();
	normal(normf);
	pfast &= ~1;
}

/*
 * Prep tty for open mode.
 */
I 4
ttymode
E 4
ostart()
{
D 4
	int f;
E 4
I 4
	ttymode f;
E 4

	if (!intty)
		error("Open and visual must be used interactively");
D 22
	gTTY(1);
E 22
I 22
	ex_gTTY(1);
E 22
	normtty++;
I 4
#ifndef USG3TTY
E 4
	f = tty.sg_flags;
D 4
#ifdef CBREAK
	tty.sg_flags = (normf &~ (ECHO|XTABS|CRMOD)) | CBREAK;
E 4
I 4
	tty.sg_flags = (normf &~ (ECHO|XTABS|CRMOD)) |
# ifdef CBREAK
							CBREAK;
# else
							RAW;
# endif
# ifdef TIOCGETC
	ttcharoff();
# endif
E 4
#else
D 4
	tty.sg_flags = (normf &~ (ECHO|XTABS|CRMOD)) | RAW;
E 4
I 4
	f = tty;
	tty = normf;
	tty.c_iflag &= ~ICRNL;
	tty.c_lflag &= ~(ECHO|ICANON);
D 14
	tty.c_oflag &= ~TAB3;
E 14
I 14
	tty.c_oflag &= ~(TAB3|ONLCR);
E 14
	tty.c_cc[VMIN] = 1;
	tty.c_cc[VTIME] = 1;
	ttcharoff();
E 4
#endif
D 3
#ifdef TIOCGETC
E 3
I 3
D 4
#ifdef EATQS
E 3
	nttyc.t_quitc = nttyc.t_startc = nttyc.t_stopc = '\377';
#endif
E 4
D 22
	sTTY(1);
E 22
I 22
	ex_sTTY(1);
E 22
D 4
	putpad(VS);
	putpad(KS);
E 4
I 4
	tostart();
E 4
	pfast |= 2;
	return (f);
}

I 4
/* actions associated with putting the terminal in open mode */
tostart()
{
	putpad(VS);
	putpad(KS);
D 8
	if (!value(MESG))
		chmod(ttynbuf, 0611);	/* 11 = urgent only allowed */
E 8
I 8
	if (!value(MESG)) {
		if (ttynbuf[0] == 0) {
D 24
			register char *tn;
E 24
I 24
			register u_char *tn;
E 24
			if ((tn=ttyname(2)) == NULL &&
			    (tn=ttyname(1)) == NULL &&
			    (tn=ttyname(0)) == NULL)
				ttynbuf[0] = 1;
			else
				strcpy(ttynbuf, tn);
		}
		if (ttynbuf[0] != 1) {
			struct stat sbuf;
			stat(ttynbuf, &sbuf);
			ttymesg = sbuf.st_mode & 0777;
			chmod(ttynbuf,
#ifdef UCBV7
	/*
	 * This applies to the UCB V7 Pdp-11 system with the
	 * -u write option only.
	 */
					0611	/* 11 = urgent only allowed */
#else
					0600
#endif
						);
		}
	}
E 8
}

E 4
/*
I 4
 * Turn off start/stop chars if they aren't the default ^S/^Q.
 * This is so idiots who make esc their start/stop don't lose.
 * We always turn off quit since datamedias send ^\ for their
 * right arrow key.
 */
#ifdef TIOCGETC
ttcharoff()
{
	nttyc.t_quitc = '\377';
D 23
	if (nttyc.t_startc != CTRL(q))
E 23
I 23
	if (nttyc.t_startc != CTRL('q'))
E 23
		nttyc.t_startc = '\377';
D 23
	if (nttyc.t_stopc != CTRL(s))
E 23
I 23
	if (nttyc.t_stopc != CTRL('s'))
E 23
		nttyc.t_stopc = '\377';
# ifdef TIOCLGET
	nlttyc.t_suspc = '\377';	/* ^Z */
	nlttyc.t_dsuspc = '\377';	/* ^Y */
	nlttyc.t_flushc = '\377';	/* ^O */
	nlttyc.t_lnextc = '\377';	/* ^V */
# endif
}
#endif

#ifdef USG3TTY
ttcharoff()
{
	tty.c_cc[VQUIT] = '\377';
# ifdef VSTART
	/*
	 * The following is sample code if USG ever lets people change
	 * their start/stop chars.  As long as they can't we can't get
	 * into trouble so we just leave them alone.
	 */
D 23
	if (tty.c_cc[VSTART] != CTRL(q))
E 23
I 23
	if (tty.c_cc[VSTART] != CTRL('q'))
E 23
		tty.c_cc[VSTART] = '\377';
D 23
	if (tty.c_cc[VSTOP] != CTRL(s))
E 23
I 23
	if (tty.c_cc[VSTOP] != CTRL('s'))
E 23
		tty.c_cc[VSTOP] = '\377';
# endif
}
#endif

/*
E 4
 * Stop open, restoring tty modes.
 */
ostop(f)
D 4
	int f;
E 4
I 4
	ttymode f;
E 4
{

I 4
#ifndef USG3TTY
E 4
	pfast = (f & CRMOD) == 0;
I 4
#else
D 13
	pfast = (f.c_oflag & OCRNL) == 0;
E 13
I 13
	pfast = (f.c_oflag & ONLCR) == 0;
E 13
#endif
E 4
	termreset(), fgoto(), flusho();
	normal(f);
I 4
	tostop();
}

/* Actions associated with putting the terminal in the right mode. */
tostop()
{
E 4
	putpad(VE);
	putpad(KE);
I 4
D 18
	if (!value(MESG))
E 18
I 18
	if (!value(MESG) && ttynbuf[0]>1)
E 18
		chmod(ttynbuf, ttymesg);
E 4
}

#ifndef CBREAK
/*
 * Into cooked mode for interruptibility.
 */
vcook()
{

	tty.sg_flags &= ~RAW;
D 22
	sTTY(1);
E 22
I 22
	ex_sTTY(1);
E 22
}

/*
 * Back into raw mode.
 */
vraw()
{

	tty.sg_flags |= RAW;
D 22
	sTTY(1);
E 22
I 22
	ex_sTTY(1);
E 22
}
#endif

/*
 * Restore flags to normal state f.
 */
normal(f)
D 4
	int f;
E 4
I 4
	ttymode f;
E 4
{

	if (normtty > 0) {
D 22
		setty(f);
E 22
I 22
		ignore(setty(f));
E 22
		normtty--;
	}
}

/*
 * Straight set of flags to state f.
 */
I 4
ttymode
E 4
setty(f)
D 4
	int f;
E 4
I 4
	ttymode f;
E 4
{
I 4
#ifndef USG3TTY
E 4
	register int ot = tty.sg_flags;
I 4
#else
	ttymode ot;
	ot = tty;
#endif
E 4

D 3
#ifdef TIOCGETC
E 3
I 3
D 4
#ifdef EATQS
E 3
	if (f == normf)
E 4
I 4
#ifndef USG3TTY
I 22
# ifdef TIOCGETC
E 22
	if (f == normf) {
E 4
		nttyc = ottyc;
D 4
	else
		nttyc.t_quitc = nttyc.t_startc = nttyc.t_stopc = '\377';
#endif
E 4
I 4
# ifdef TIOCLGET
		nlttyc = olttyc;
# endif
	} else
		ttcharoff();
I 22
# endif
E 22
E 4
	tty.sg_flags = f;
I 4
#else
	if (tty.c_lflag & ICANON)
		ttcharoff();
	tty = f;
#endif
I 8
D 10
#ifdef TIMEBOMB
	/*
	 * The following is a TEMPORARY hack to help track down a bug.
	 * It is never intended to get off Ernie CoVax.
	 */
	if (f == normf && nlttyc.t_suspc == '\377') {
D 9
		printf("\n\nPlease tell mark suspc is 377, and let him know\n");
		printf("what you just did.  Did you hit del?\n");
E 9
I 9
		printf("\r\n\nPlease tell mark suspc is 377, and let him know\r\n");
		printf("what you just did.  Did you hit del?\r\n");
E 9
		nlttyc.t_suspc = CTRL(z);
		nlttyc.t_dsuspc = CTRL(y);
		nlttyc.t_flushc = CTRL(o);
		nlttyc.t_lnextc = CTRL(v);
	}
#endif
E 10
E 8
E 4
D 22
	sTTY(1);
E 22
I 22
	ex_sTTY(1);
E 22
	return (ot);
}

D 22
gTTY(i)
E 22
I 22
ex_gTTY(i)
E 22
	int i;
{
I 4
D 8
	char *tn;
	struct stat sbuf;
E 8
E 4

I 4
#ifndef USG3TTY
E 4
	ignore(gtty(i, &tty));
D 3
#ifdef TIOCGETC
E 3
I 3
D 4
#ifdef EATQS
E 4
I 4
# ifdef TIOCGETC
E 4
E 3
D 22
	ioctl(i, TIOCGETC, &ottyc);
E 22
I 22
D 24
	ioctl(i, TIOCGETC, (char *) &ottyc);
E 24
I 24
	ioctl(i, TIOCGETC, (u_char *) &ottyc);
E 24
E 22
	nttyc = ottyc;
I 4
# endif
D 7
# ifdef TIOCLGET
E 7
I 7
# ifdef TIOCGLTC
E 7
D 22
	ioctl(i, TIOCGLTC, &olttyc);
E 22
I 22
D 24
	ioctl(i, TIOCGLTC, (char *) &olttyc);
E 24
I 24
	ioctl(i, TIOCGLTC, (u_char *) &olttyc);
E 24
E 22
	nlttyc = olttyc;
# endif
#else
D 22
	ioctl(i, TCGETA, &tty);
E 22
I 22
D 24
	ioctl(i, TCGETA, (char *) &tty);
E 24
I 24
	ioctl(i, TCGETA, (u_char *) &tty);
E 24
E 22
E 4
#endif
I 4
D 8
	if ((tn=ttyname(0)) == NULL && (tn=ttyname(1)) == NULL && (tn=ttyname(2)) == NULL)
		tn = "/dev/tty";
	strcpy(ttynbuf, tn);
	stat(ttynbuf, &sbuf);
	ttymesg = sbuf.st_mode & 0777;
E 8
E 4
}

I 4
/*
D 22
 * sTTY: set the tty modes on file descriptor i to be what's
E 22
I 22
 * ex_sTTY: set the tty modes on file descriptor i to be what's
E 22
 * currently in global "tty".  (Also use nttyc if needed.)
 */
E 4
D 22
sTTY(i)
E 22
I 22
ex_sTTY(i)
E 22
	int i;
{

D 4
/*
 * Bug in USG tty driver, put out a null char as a patch.
 */
#ifdef USG
	if (tty.sg_ospeed == B1200)
		write(1, "", 1);
#endif
#ifdef TIOCSETN
E 4
I 4
#ifndef USG3TTY
# ifdef USG
	/* Bug in USG tty driver, put out a DEL as a patch. */
	if (tty.sg_ospeed >= B1200)
		write(1, "\377", 1);
# endif

# ifdef TIOCSETN
	/* Don't flush typeahead if we don't have to */
E 4
D 22
	ioctl(i, TIOCSETN, &tty);
E 22
I 22
D 24
	ioctl(i, TIOCSETN, (char *) &tty);
E 24
I 24
	ioctl(i, TIOCSETN, (u_char *) &tty);
E 24
E 22
D 4
#else
E 4
I 4
# else
	/* We have to.  Too bad. */
E 4
	stty(i, &tty);
D 4
#endif
D 3
#ifdef TIOCSETC
E 3
I 3
#ifdef EATQS
E 4
I 4
# endif

# ifdef TIOCGETC
	/* Update the other random chars while we're at it. */
E 4
E 3
D 22
	ioctl(i, TIOCSETC, &nttyc);
E 22
I 22
D 24
	ioctl(i, TIOCSETC, (char *) &nttyc);
E 24
I 24
	ioctl(i, TIOCSETC, (u_char *) &nttyc);
E 24
E 22
I 4
# endif
D 7
# ifdef TIOCLGET
E 7
I 7
# ifdef TIOCSLTC
E 7
D 22
	ioctl(i, TIOCSLTC, &nlttyc);
E 22
I 22
D 24
	ioctl(i, TIOCSLTC, (char *) &nlttyc);
E 24
I 24
	ioctl(i, TIOCSLTC, (u_char *) &nlttyc);
E 24
E 22
# endif

#else
	/* USG 3 very simple: just set everything */
D 22
	ioctl(i, TCSETAW, &tty);
E 22
I 22
D 24
	ioctl(i, TCSETAW, (char *) &tty);
E 24
I 24
	ioctl(i, TCSETAW, (u_char *) &tty);
E 24
E 22
E 4
#endif
}

/*
 * Print newline, or blank if in open/visual
 */
noonl()
{

D 22
	putchar(Outchar != termchar ? ' ' : '\n');
E 22
I 22
	ex_putchar(Outchar != termchar ? ' ' : '\n');
E 22
I 4
}
D 11

D 7
#ifdef TIOCLGET
E 7
I 7
#ifdef SIGTSTP
E 7
/*
 * We have just gotten a susp.  Suspend and prepare to resume.
 */
onsusp()
{
	ttymode f;

	f = setty(normf);
	vnfl();
	putpad(TE);
	flush();

	signal(SIGTSTP, SIG_DFL);
	kill(0, SIGTSTP);

	/* the pc stops here */

	signal(SIGTSTP, onsusp);
	vcontin(0);
	setty(f);
	if (!inopen)
		error(0);
	else {
		if (vcnt < 0) {
			vcnt = -vcnt;
			if (state == VISUAL)
				vclear();
			else if (state == CRTOPEN)
				vcnt = 0;
		}
		vdirty(0, LINES);
		vrepaint(cursor);
	}
E 4
}
E 11
E 1
