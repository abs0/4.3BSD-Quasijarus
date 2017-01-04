h62703
s 00010/00005/00309
d D 5.3 88/06/30 17:22:01 bostic 13 12
c install approved copyright notice
e
s 00010/00004/00304
d D 5.2 88/06/08 13:57:41 bostic 12 11
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00002/00298
d D 5.1 85/06/07 20:58:15 mckusick 11 10
c Add copyright
e
s 00014/00002/00286
d D 1.10 85/06/07 20:53:28 mckusick 10 9
c fixes from arnold@ucsfcgl
e
s 00065/00032/00223
d D 1.9 85/05/01 17:31:44 bloom 9 8
c new version from arnold
e
s 00000/00002/00255
d D 1.8 83/05/12 13:22:07 arnold 8 7
c delete spurious debug abort()
e
s 00012/00004/00245
d D 1.7 83/05/10 15:11:40 arnold 7 6
c wrefresh(curscr) should put the cursor back where it was
e
s 00021/00014/00228
d D 1.6 83/03/27 15:08:18 arnold 6 5
c 
e
s 00004/00000/00238
d D 1.5 82/02/17 14:10:10 arnold 5 4
c don't move in standout unless MS is set
e
s 00003/00003/00235
d D 1.4 81/03/05 18:54:49 arnold 4 3
c fix bug that caused illegal scrolls
e
s 00003/00004/00235
d D 1.3 81/02/17 13:36:51 arnold 3 2
c fix bug in refresh if clear is set
e
s 00069/00039/00170
d D 1.2 81/01/27 12:28:48 arnold 2 1
c make wrefresh(curscr) make the screen look like curscr
e
s 00209/00000/00000
d D 1.1 81/01/26 17:03:10 arnold 1 0
c date and time created 81/01/26 17:03:10 by arnold
e
u
U
t
T
I 1
/*
I 11
D 12
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 13
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 13
I 13
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
E 13
E 12
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif not lint
E 12
I 12
#endif /* not lint */
E 12

/*
E 11
 * make the current screen look like "win" over the area coverd by
 * win.
D 11
 *
D 9
 * %G% (Berkeley) %W%
E 9
I 9
 * %W% (Berkeley) %G%
E 11
E 9
 */

# include	"curses.ext"

D 2
# ifndef DEBUG
static short	ly, lx;
E 2
I 2
# ifdef DEBUG
# define	STATIC
E 2
# else
D 2
short		ly, lx;
E 2
I 2
# define	STATIC	static
E 2
# endif

I 2
STATIC short	ly, lx;

STATIC bool	curwin;

E 2
WINDOW	*_win = NULL;

wrefresh(win)
reg WINDOW	*win;
{
	reg short	wy;
I 2
	reg int		retval;
I 9
	reg WINDOW	*orig;
E 9
E 2

	/*
	 * make sure were in visual state
	 */
	if (_endwin) {
		_puts(VS);
		_puts(TI);
		_endwin = FALSE;
	}
D 2
	if (win->_clear || curscr->_clear) {
E 2
I 2

	/*
	 * initialize loop parameters
	 */

	ly = curscr->_cury;
	lx = curscr->_curx;
	wy = 0;
	_win = win;
	curwin = (win == curscr);

	if (win->_clear || curscr->_clear || curwin) {
E 2
		if ((win->_flags & _FULLWIN) || curscr->_clear) {
			_puts(CL);
D 2
			curscr->_curx = curscr->_cury = 0;
			curscr->_clear = FALSE;
			werase(curscr);
E 2
I 2
D 3
			if (!curwin) {
				curscr->_curx = curscr->_cury = 0;
				curscr->_clear = FALSE;
E 3
I 3
D 7
			ly = lx = curscr->_curx = curscr->_cury = 0;
			curscr->_clear = FALSE;
			if (!curwin)
E 7
I 7
			ly = 0;
			lx = 0;
			if (!curwin) {
				curscr->_clear = FALSE;
				curscr->_cury = 0;
				curscr->_curx = 0;
E 7
E 3
				werase(curscr);
I 7
			}
E 7
D 3
			}
E 3
E 2
			touchwin(win);
		}
		win->_clear = FALSE;
	}
	if (!CA) {
		if (win->_curx != 0)
D 9
			putchar('\n');
E 9
I 9
			_putchar('\n');
E 9
D 2
		werase(curscr);
E 2
I 2
		if (!curwin)
			werase(curscr);
E 2
	}
# ifdef DEBUG
I 2
	fprintf(outf, "REFRESH(%0.2o): curwin = %d\n", win, curwin);
E 2
	fprintf(outf, "REFRESH:\n\tfirstch\tlastch\n");
# endif
D 2
	ly = curscr->_cury;
	lx = curscr->_curx;
	wy = 0;
	_win = win;
E 2
	for (wy = 0; wy < win->_maxy; wy++) {
# ifdef DEBUG
D 9
		fprintf(outf, "%d\t%d\t%d\n", wy, win->_firstch[wy], win->_lastch[wy]);
E 9
I 9
		fprintf(outf, "%d\t%d\t%d\n", wy, win->_firstch[wy],
			win->_lastch[wy]);
E 9
# endif
		if (win->_firstch[wy] != _NOCHANGE)
			if (makech(win, wy) == ERR)
				return ERR;
D 9
			else
				win->_firstch[wy] = _NOCHANGE;
E 9
I 9
			else {
				if (win->_firstch[wy] >= win->_ch_off)
					win->_firstch[wy] = win->_maxx +
							    win->_ch_off;
				if (win->_lastch[wy] < win->_maxx +
						       win->_ch_off)
					win->_lastch[wy] = win->_ch_off;
				if (win->_lastch[wy] < win->_firstch[wy])
					win->_firstch[wy] = _NOCHANGE;
			}
# ifdef DEBUG
		fprintf(outf, "\t%d\t%d\n", win->_firstch[wy],
			win->_lastch[wy]);
# endif
E 9
	}
I 9

E 9
D 7
	if (win->_leave) {
E 7
I 7
	if (win == curscr)
		domvcur(ly, lx, win->_cury, win->_curx);
D 9
	else if (win->_leave) {
E 7
		curscr->_cury = ly;
		curscr->_curx = lx;
		ly -= win->_begy;
		lx -= win->_begx;
		if (ly >= 0 && ly < win->_maxy && lx >= 0 && lx < win->_maxx) {
			win->_cury = ly;
			win->_curx = lx;
E 9
I 9
	else {
		if (win->_leave) {
			curscr->_cury = ly;
			curscr->_curx = lx;
			ly -= win->_begy;
			lx -= win->_begx;
			if (ly >= 0 && ly < win->_maxy && lx >= 0 &&
			    lx < win->_maxx) {
				win->_cury = ly;
				win->_curx = lx;
			}
			else
				win->_cury = win->_curx = 0;
E 9
		}
D 9
		else
			win->_cury = win->_curx = 0;
E 9
I 9
		else {
			domvcur(ly, lx, win->_cury + win->_begy,
				win->_curx + win->_begx);
			curscr->_cury = win->_cury + win->_begy;
			curscr->_curx = win->_curx + win->_begx;
		}
E 9
	}
D 9
	else {
D 6
		mvcur(ly, lx, win->_cury + win->_begy, win->_curx + win->_begx);
E 6
I 6
		domvcur(ly, lx, win->_cury+win->_begy, win->_curx+win->_begx);
E 6
		curscr->_cury = win->_cury + win->_begy;
		curscr->_curx = win->_curx + win->_begx;
	}
E 9
I 2
	retval = OK;
ret:
E 2
	_win = NULL;
	fflush(stdout);
D 2
	return OK;
E 2
I 2
	return retval;
E 2
}

/*
 * make a change on the screen
 */
D 2
# ifndef DEBUG
static
# endif
E 2
I 2
STATIC
E 2
makech(win, wy)
reg WINDOW	*win;
short		wy;
{
	reg char	*nsp, *csp, *ce;
	reg short	wx, lch, y;
	reg int		nlsp, clsp;	/* last space in lines		*/

D 9
	wx = win->_firstch[wy];
E 9
I 9
	wx = win->_firstch[wy] - win->_ch_off;
	if (wx >= win->_maxx)
		return OK;
	else if (wx < 0)
		wx = 0;
	lch = win->_lastch[wy] - win->_ch_off;
	if (lch < 0)
		return OK;
	else if (lch >= win->_maxx)
		lch = win->_maxx - 1;;
E 9
	y = wy + win->_begy;
D 9
	lch = win->_lastch[wy];
E 9
I 9

E 9
D 2
	csp = &curscr->_y[wy + win->_begy][wx + win->_begx];
E 2
I 2
	if (curwin)
		csp = " ";
	else
		csp = &curscr->_y[wy + win->_begy][wx + win->_begx];
I 9

E 9
E 2
	nsp = &win->_y[wy][wx];
D 2
	if (CE) {
E 2
I 2
	if (CE && !curwin) {
E 2
		for (ce = &win->_y[wy][win->_maxx - 1]; *ce == ' '; ce--)
			if (ce <= win->_y[wy])
				break;
		nlsp = ce - win->_y[wy];
	}
I 9

E 9
D 2
	ce = CE;
E 2
I 2
	if (!curwin)
		ce = CE;
	else
		ce = NULL;
I 9

E 9
E 2
	while (wx <= lch) {
		if (*nsp != *csp) {
D 6
			mvcur(ly, lx, y, wx + win->_begx);
E 6
I 6
			domvcur(ly, lx, y, wx + win->_begx);
E 6
# ifdef DEBUG
			fprintf(outf, "MAKECH: 1: wx = %d, lx = %d\n", wx, lx);
# endif	
			ly = y;
			lx = wx + win->_begx;
			while (*nsp != *csp && wx <= lch) {
D 2
				if (ce && wx >= nlsp && *nsp == ' ') {
E 2
I 2
				if (ce != NULL && wx >= nlsp && *nsp == ' ') {
E 2
					/*
					 * check for clear to end-of-line
					 */
					ce = &curscr->_y[ly][COLS - 1];
					while (*ce == ' ')
						if (ce-- <= csp)
							break;
					clsp = ce - curscr->_y[ly] - win->_begx;
# ifdef DEBUG
					fprintf(outf, "MAKECH: clsp = %d, nlsp = %d\n", clsp, nlsp);
# endif
					if (clsp - nlsp >= strlen(CE)
					    && clsp < win->_maxx) {
# ifdef DEBUG
						fprintf(outf, "MAKECH: using CE\n");
# endif
						_puts(CE);
						lx = wx + win->_begx;
						while (wx++ <= clsp)
							*csp++ = ' ';
D 9
						goto ret;
E 9
I 9
						return OK;
E 9
					}
					ce = NULL;
				}
				/*
				 * enter/exit standout mode as appropriate
				 */
				if (SO && (*nsp&_STANDOUT) != (curscr->_flags&_STANDOUT)) {
					if (*nsp & _STANDOUT) {
						_puts(SO);
						curscr->_flags |= _STANDOUT;
					}
					else {
						_puts(SE);
						curscr->_flags &= ~_STANDOUT;
					}
				}
				wx++;
D 4
				if (wx >= win->_maxx && wy == win->_maxy)
E 4
I 4
				if (wx >= win->_maxx && wy == win->_maxy - 1)
E 4
D 2
						if (win->_scroll) {
						    if ((win->_flags&(_ENDLINE|_STANDOUT)) == (_ENDLINE|_STANDOUT))
							if (!MS) {
								_puts(SE);
								win->_flags &= ~_STANDOUT;
							}
						    putchar((*csp = *nsp) & 0177);
						    scroll(win);
						    if (win->_flags&_FULLWIN)
							scroll(curscr);
						    ly = win->_begy+win->_cury;
						    lx = win->_begx+win->_curx;
						    return OK;
E 2
I 2
					if (win->_scroll) {
D 6
					    if ((win->_flags&(_ENDLINE|_STANDOUT)) == (_ENDLINE|_STANDOUT))
						if (!MS) {
D 4
							_puts(SE);
							win->_flags &= ~_STANDOUT;
E 4
I 4
						    _puts(SE);
						    win->_flags &= ~_STANDOUT;
E 4
E 2
						}
E 6
I 6
					    if ((curscr->_flags&_STANDOUT) &&
					        (win->_flags & _ENDLINE))
						    if (!MS) {
							_puts(SE);
							curscr->_flags &= ~_STANDOUT;
						    }
E 6
D 2
						else if (win->_flags&_SCROLLWIN) {
						    lx = --wx;
						    return ERR;
						}
				putchar((*csp++ = *nsp) & 0177);
E 2
I 2
					    if (!curwin)
D 9
						putchar((*csp = *nsp) & 0177);
E 9
I 9
						_putchar((*csp = *nsp) & 0177);
E 9
					    else
D 9
						putchar(*nsp & 0177);
					    scroll(win);
E 9
I 9
						_putchar(*nsp & 0177);
E 9
					    if (win->_flags&_FULLWIN && !curwin)
						scroll(curscr);
					    ly = win->_begy+win->_cury;
					    lx = win->_begx+win->_curx;
					    return OK;
					}
					else if (win->_flags&_SCROLLWIN) {
					    lx = --wx;
					    return ERR;
					}
				if (!curwin)
D 9
					putchar((*csp++ = *nsp) & 0177);
E 9
I 9
					_putchar((*csp++ = *nsp) & 0177);
E 9
				else
D 9
					putchar(*nsp & 0177);
E 9
I 9
					_putchar(*nsp & 0177);
# ifdef FULLDEBUG
				fprintf(outf,
					"MAKECH:putchar(%c)\n", *nsp & 0177);
# endif
E 9
E 2
				if (UC && (*nsp & _STANDOUT)) {
D 9
					putchar('\b');
E 9
I 9
					_putchar('\b');
E 9
					_puts(UC);
				}
				nsp++;
			}
I 5
D 6
			if (!MS && (*nsp & _STANDOUT)  && (*csp & _STANDOUT)) {
				_puts(SE);
				win->_flags &= ~_STANDOUT;
			}
E 6
E 5
# ifdef DEBUG
			fprintf(outf, "MAKECH: 2: wx = %d, lx = %d\n", wx, lx);
# endif	
			if (lx == wx + win->_begx)	/* if no change */
				break;
			lx = wx + win->_begx;
I 10
			if (lx >= COLS && AM) {
				lx = 0;
				ly++;
				/*
				 * xn glitch: chomps a newline after auto-wrap.
				 * we just feed it now and forget about it.
				 */
				if (XN) {
					_putchar('\n');
					_putchar('\r');
				}
			}
E 10
		}
D 10
		else if (wx < lch)
D 9
			while (*nsp == *csp) {
E 9
I 9
			while (*nsp == *csp && wx < lch) {
E 10
I 10
		else if (wx <= lch)
			while (*nsp == *csp && wx <= lch) {
E 10
E 9
D 2
				nsp++, csp++;
E 2
I 2
				nsp++;
				if (!curwin)
					csp++;
E 2
				++wx;
			}
		else
			break;
# ifdef DEBUG
		fprintf(outf, "MAKECH: 3: wx = %d, lx = %d\n", wx, lx);
# endif	
	}
D 9
ret:
E 9
D 6
	if ((win->_flags & _STANDOUT) && !MS) {
E 6
I 6
	return OK;
}

/*
 * perform a mvcur, leaving standout mode if necessary
 */
D 9
static
E 9
I 9
STATIC
E 9
domvcur(oy, ox, ny, nx)
int	oy, ox, ny, nx; {

I 7
D 8
	if (ny == 0 && nx == 0)
		abort();
E 8
E 7
	if (curscr->_flags & _STANDOUT && !MS) {
E 6
		_puts(SE);
D 6
		win->_flags &= ~_STANDOUT;
E 6
I 6
		curscr->_flags &= ~_STANDOUT;
E 6
	}
D 6
	return OK;
E 6
I 6
	mvcur(oy, ox, ny, nx);
E 6
}
E 1
