h37751
s 00001/00001/00400
d D 5.4 03/03/29 17:43:34 msokolov 11 10
c don't randomly spit out 8-bit chars as a side effect of cursor motion
e
s 00010/00005/00391
d D 5.3 88/06/30 17:21:20 bostic 10 9
c install approved copyright notice
e
s 00010/00004/00386
d D 5.2 88/06/08 13:56:50 bostic 9 8
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00002/00380
d D 5.1 85/06/07 20:59:03 mckusick 8 7
c Add copyright
e
s 00013/00025/00369
d D 1.6 85/06/07 20:53:55 mckusick 7 6
c fixes from arnold@ucsfcgl
e
s 00024/00023/00370
d D 1.5 85/05/01 16:46:21 bloom 6 4
c new version from arnold
e
s 00024/00023/00370
d R 1.5 85/05/01 16:44:51 bloom 5 4
c _putchar moved to separate file
e
s 00003/00004/00390
d D 1.4 83/03/27 15:08:24 arnold 4 3
c 
e
s 00005/00006/00389
d D 1.3 83/02/02 15:18:16 arnold 3 2
c format fixups
e
s 00156/00076/00239
d D 1.2 82/02/17 14:12:05 arnold 2 1
c adopt latest version of fgoto() and plod() from vi
e
s 00315/00000/00000
d D 1.1 81/01/26 17:02:42 arnold 1 0
c date and time created 81/01/26 17:02:42 by arnold
e
u
U
t
T
I 8
/*
D 9
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 10
E 9
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9

E 8
I 1
# include	"curses.ext"
D 2
# include	"cr_ex.h"
E 2

# define	HARDTABS	8

extern char	*tgoto();
int		plodput();

/*
 * Terminal driving and line formatting routines.
 * Basic motion optimizations are done here as well
 * as formatting of lines (printing of control characters,
 * line numbering and the like).
D 8
 *
D 6
 * %G% (Berkeley) %W%
E 6
I 6
 * %W% (Berkeley) %G%
E 8
E 6
 */

/*
 * Sync the position of the output cursor.
 * Most work here is rounding for terminal boundaries getting the
 * column position implied by wraparound or the lack thereof and
 * rolling up the screen to get destline on the screen.
 */

D 2
static int	outcol, outline, destcol, destline, plodcnt;
E 2
I 2
static int	outcol, outline, destcol, destline;
E 2

WINDOW		*_win;

mvcur(ly, lx, y, x)
int	ly, lx, y, x; {

#ifdef DEBUG
	fprintf(outf, "MVCUR: moving cursor from (%d,%d) to (%d,%d)\n", ly, lx, y, x);
#endif
	destcol = x;
	destline = y;
	outcol = lx;
	outline = ly;
	fgoto();
}

D 2
fgoto() {
E 2
I 2
D 6
char
_putchar(c)
reg char	c; {
E 2

I 2
	putchar(c);
#ifdef DEBUG
	fprintf(outf, "_PUTCHAR(%s)\n", unctrl(c));
#endif
}

E 6
fgoto()
{
E 2
	reg char	*cgp;
	reg int		l, c;

D 7
	if (destcol > COLS - 1) {
E 7
I 7
	if (destcol >= COLS) {
E 7
		destline += destcol / COLS;
		destcol %= COLS;
	}
D 7
	if (outcol > COLS - 1) {
E 7
I 7
	if (outcol >= COLS) {
E 7
		l = (outcol + 1) / COLS;
		outline += l;
		outcol %= COLS;
		if (AM == 0) {
			while (l > 0) {
D 2
				putchar('\n');
E 2
				if (_pfast)
D 2
					putchar('\r');
E 2
I 2
					if (CR)
D 6
						tputs(CR, 0, _putchar);
E 6
I 6
						_puts(CR);
E 6
					else
						_putchar('\r');
				if (NL)
D 6
					tputs(NL, 0, _putchar);
E 6
I 6
					_puts(NL);
E 6
				else
					_putchar('\n');
E 2
				l--;
			}
			outcol = 0;
		}
		if (outline > LINES - 1) {
			destline -= outline - (LINES - 1);
			outline = LINES - 1;
		}
	}
D 7
	if (destline > LINES - 1) {
E 7
I 7
	if (destline >= LINES) {
E 7
		l = destline;
		destline = LINES - 1;
		if (outline < LINES - 1) {
			c = destcol;
			if (_pfast == 0 && !CA)
				destcol = 0;
			fgoto();
			destcol = c;
		}
D 7
		while (l > LINES - 1) {
E 7
I 7
		while (l >= LINES) {
E 7
D 2
			putchar('\n');
E 2
I 2
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
			if (NL /* && !XB */ && _pfast)
D 6
				tputs(NL, 0, _putchar);
E 6
I 6
				_puts(NL);
E 6
			else
				_putchar('\n');
E 2
			l--;
			if (_pfast == 0)
				outcol = 0;
		}
	}
D 2
	if (destline < outline && !(CA || UP != NULL))
E 2
I 2
	if (destline < outline && !(CA || UP))
E 2
		destline = outline;
D 2
	cgp = tgoto(CM, destcol, destline);
E 2
D 7
	if (CA)
I 2
	{
E 7
I 7
	if (CA) {
E 7
		cgp = tgoto(CM, destcol, destline);
E 2
		if (plod(strlen(cgp)) > 0)
			plod(0);
		else
			tputs(cgp, 0, _putchar);
I 2
	}
E 2
	else
		plod(0);
	outline = destline;
	outcol = destcol;
}

D 2
char
_putchar(c)
reg char	c; {
E 2
I 2
/*
 * Move (slowly) to destination.
 * Hard thing here is using home cursor on really deficient terminals.
 * Otherwise just use cursor motions, hacking use of tabs and overtabbing
 * and backspace.
 */
E 2

D 2
	putchar(c);
#ifdef DEBUG
	fprintf(outf, "_PUTCHAR(%s)\n", unctrl(c));
#endif
E 2
I 2
static int plodcnt, plodflg;

plodput(c)
{
	if (plodflg)
		plodcnt--;
	else
		_putchar(c);
E 2
}

D 2
extern bool	plodflg;
extern int	plodcnt;

E 2
plod(cnt)
D 2
int	cnt; {
E 2
I 2
{
	register int i, j, k;
	register int soutcol, soutline;
E 2

D 2
	reg int		i, j, k;
	reg int		soutcol, soutline;
	reg char	c;

E 2
	plodcnt = plodflg = cnt;
	soutcol = outcol;
	soutline = outline;
I 2
	/*
	 * Consider homing and moving down/right from there, vs moving
	 * directly with local motions to the right spot.
	 */
E 2
	if (HO) {
I 2
		/*
		 * i is the cost to home and tab/space to the right to
		 * get to the proper column.  This assumes ND space costs
		 * 1 char.  So i+destcol is cost of motion with home.
		 */
E 2
		if (GT)
			i = (destcol / HARDTABS) + (destcol % HARDTABS);
		else
			i = destcol;
D 2
        if (destcol >= outcol) {
                j = destcol / HARDTABS - outcol / HARDTABS;
                if (GT && j)
                        j += destcol % HARDTABS;
E 2
I 2
		/*
		 * j is cost to move locally without homing
		 */
		if (destcol >= outcol) {	/* if motion is to the right */
			j = destcol / HARDTABS - outcol / HARDTABS;
			if (GT && j)
				j += destcol % HARDTABS;
			else
				j = destcol - outcol;
		}
E 2
		else
D 2
			j = destcol - outcol;
        } else
E 2
I 2
			/* leftward motion only works if we can backspace. */
E 2
			if (outcol - destcol <= i && (BS || BC))
D 2
				i = j = outcol - destcol;
E 2
I 2
				i = j = outcol - destcol; /* cheaper to backspace */
E 2
			else
D 2
				j = i + 1;
E 2
I 2
				j = i + 1; /* impossibly expensive */

		/* k is the absolute value of vertical distance */
E 2
		k = outline - destline;
		if (k < 0)
			k = -k;
		j += k;
D 2
		if (i + destline < j) {
E 2
I 2

		/*
		 * Decision.  We may not have a choice if no UP.
		 */
		if (i + destline < j || (!UP && destline < outline)) {
			/*
			 * Cheaper to home.  Do it now and pretend it's a
			 * regular local motion.
			 */
E 2
			tputs(HO, 0, plodput);
			outcol = outline = 0;
D 2
		} else if (LL) {
E 2
I 2
		}
		else if (LL) {
			/*
			 * Quickly consider homing down and moving from there.
			 * Assume cost of LL is 2.
			 */
E 2
			k = (LINES - 1) - destline;
D 2
			if (i + k + 2 < j) {
E 2
I 2
			if (i + k + 2 < j && (k<=0 || UP)) {
E 2
				tputs(LL, 0, plodput);
				outcol = 0;
				outline = LINES - 1;
			}
		}
	}
I 2
	else
	/*
D 4
	 * No home and no up means it's impossible, so we return an
	 * incredibly big number to make cursor motion win out.
E 4
I 4
	 * No home and no up means it's impossible.
E 4
	 */
		if (!UP && destline < outline)
D 4
			return (500);
E 4
I 4
			return -1;
E 4
E 2
	if (GT)
D 2
        i = destcol % HARDTABS + destcol / HARDTABS;
E 2
I 2
D 3
		i = destcol % HARDTABS
		    + destcol / HARDTABS;
E 3
I 3
		i = destcol % HARDTABS + destcol / HARDTABS;
E 3
E 2
	else
		i = destcol;
/*
	if (BT && outcol > destcol && (j = (((outcol+7) & ~7) - destcol - 1) >> 3)) {
		j *= (k = strlen(BT));
		if ((k += (destcol&7)) > 4)
			j += 8 - (destcol&7);
		else
			j += k;
D 2
	} else
E 2
I 2
	}
	else
E 2
*/
		j = outcol - destcol;
	/*
	 * If we will later need a \n which will turn into a \r\n by
	 * the system or the terminal, then don't bother to try to \r.
	 */
	if ((NONL || !_pfast) && outline < destline)
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
D 2
		plodput('\r');
E 2
I 2
		/*
		 * BUG: this doesn't take the (possibly long) length
		 * of CR into account.
		 */
		if (CR)
			tputs(CR, 0, plodput);
		else
			plodput('\r');
E 2
		if (NC) {
D 2
			plodput('\n');
E 2
I 2
D 6
			if (NL)
				tputs(NL, 0, plodput);
			else
				plodput('\n');
E 6
I 6
D 7
			put_nl();
E 7
I 7
			if (NL)
				tputs(NL, 0, plodput);
			else
				plodput('\n');
E 7
E 6
E 2
			outline++;
		}
		outcol = 0;
	}
dontcr:
	while (outline < destline) {
		outline++;
D 2
		plodput('\n');
E 2
I 2
D 6
		if (NL && _pfast)
			tputs(NL, 0, plodput);
		else
			plodput('\n');
E 6
I 6
D 7
		put_nl();
E 7
I 7
		if (NL)
			tputs(NL, 0, plodput);
		else
			plodput('\n');
E 7
E 6
E 2
		if (plodcnt < 0)
			goto out;
		if (NONL || _pfast == 0)
			outcol = 0;
	}
	if (BT)
		k = strlen(BT);
	while (outcol > destcol) {
		if (plodcnt < 0)
			goto out;
/*
D 2
		if (BT && outcol - destcol > 4+k) {
E 2
I 2
		if (BT && outcol - destcol > k + 4) {
E 2
			tputs(BT, 0, plodput);
			outcol--;
			outcol &= ~7;
			continue;
		}
*/
		outcol--;
		if (BC)
			tputs(BC, 0, plodput);
		else
			plodput('\b');
	}
	while (outline > destline) {
		outline--;
		tputs(UP, 0, plodput);
		if (plodcnt < 0)
			goto out;
	}
	if (GT && destcol - outcol > 1) {
D 2
        for (;;) {
                i = (outcol / HARDTABS + 1) * HARDTABS;
                if (i > destcol)
                        break;
E 2
I 2
D 3
	for (;;) {
		i = tabcol(outcol, HARDTABS);
		if (i > destcol)
			break;
E 3
I 3
		for (;;) {
			i = tabcol(outcol, HARDTABS);
			if (i > destcol)
				break;
E 3
E 2
			if (TA)
				tputs(TA, 0, plodput);
			else
				plodput('\t');
			outcol = i;
		}
		if (destcol - outcol > 4 && i < COLS && (BC || BS)) {
			if (TA)
				tputs(TA, 0, plodput);
			else
				plodput('\t');
			outcol = i;
			while (outcol > destcol) {
				outcol--;
				if (BC)
					tputs(BC, 0, plodput);
				else
					plodput('\b');
			}
		}
	}
	while (outcol < destcol) {
I 2
		/*
		 * move one char to the right.  We don't use ND space
		 * because it's better to just print the char we are
		 * moving over.
		 */
E 2
		if (_win != NULL)
			if (plodflg)	/* avoid a complex calculation */
				plodcnt--;
			else {
D 2
				c = _win->_y[outline-_win->_begy][outcol-_win->_begx];
				if ((c&_STANDOUT) == (curscr->_flags&_STANDOUT))
					putchar(c);
E 2
I 2
D 4
				i = _win->_y[outline-_win->_begy][outcol-_win->_begx];
E 4
I 4
				i = curscr->_y[outline][outcol];
E 4
				if ((i&_STANDOUT) == (curscr->_flags&_STANDOUT))
D 6
					putchar(i);
E 6
I 6
D 11
					_putchar(i);
E 11
I 11
					_putchar(i & 0177);
E 11
E 6
E 2
				else
					goto nondes;
			}
		else
nondes:
		     if (ND)
			tputs(ND, 0, plodput);
		else
			plodput(' ');
		outcol++;
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
D 2
 * Move (slowly) to destination.
 * Hard thing here is using home cursor on really deficient terminals.
 * Otherwise just use cursor motions, hacking use of tabs and overtabbing
 * and backspace.
E 2
I 2
 * Return the column number that results from being in column col and
 * hitting a tab, where tabs are set every ts columns.  Work right for
 * the case where col > COLS, even if ts does not divide COLS.
E 2
 */
I 2
tabcol(col, ts)
int col, ts;
{
	int offset, result;
E 2

D 2
static	bool	plodflg;

plodput(c)
reg char	c; {

	if (plodflg)
		plodcnt--;
	else {
		putchar(c);
#ifdef DEBUG
		fprintf(outf, "PLODPUT(%s)\n", unctrl(c));
#endif
E 2
I 2
	if (col >= COLS) {
		offset = COLS * (col / COLS);
		col -= offset;
E 2
	}
D 2
}

/*
 * Put with padding
 */
putpad(cp)
reg char	*cp; {

	fflush(stdout);
#ifdef DEBUG
	fprintf(outf, "PUTPAD: _puts(\"%s\")\n", cp);
#endif
	_puts(cp);
E 2
I 2
	else
		offset = 0;
	return col + ts - (col % ts) + offset;
I 6
D 7
}

/*
 * put out a newline appropriately, twice if necessary (uck)
 */
static
put_nl()
{
	if (NL)
		tputs(NL, 0, plodput);
	else
		plodput('\n');
	if (AM && XN && outcol == COLS - 1)
		if (NL)
			tputs(NL, 0, plodput);
		else
			plodput('\n');
E 7
E 6
E 2
}
E 1
