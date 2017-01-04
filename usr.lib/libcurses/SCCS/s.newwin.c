h34244
s 00010/00005/00209
d D 5.3 88/06/30 17:21:52 bostic 10 9
c install approved copyright notice
e
s 00010/00004/00204
d D 5.2 88/06/08 13:57:32 bostic 9 8
c written by Ken Arnold; add Berkeley specific header
e
s 00010/00001/00198
d D 5.1 85/06/07 11:37:49 dist 8 7
c Add copyright
e
s 00079/00052/00120
d D 1.7 85/05/01 17:27:09 bloom 7 6
c new version from arnold
e
s 00007/00001/00165
d D 1.6 83/05/09 20:35:38 arnold 6 5
c integrate subwindows fully into all parts of curses
e
s 00007/00003/00159
d D 1.5 83/03/27 15:08:34 arnold 5 4
c 
e
s 00007/00005/00155
d D 1.4 82/02/16 17:05:56 arnold 4 3
c check boundary conditions properly
e
s 00001/00001/00159
d D 1.3 81/10/26 00:06:20 arnold 3 2
c use calloc to get window structure to guarantee all zero start
e
s 00003/00001/00157
d D 1.2 81/10/26 00:03:30 arnold 2 1
c return NULL at all appropriate places
e
s 00158/00000/00000
d D 1.1 81/01/26 17:03:04 arnold 1 0
c date and time created 81/01/26 17:03:04 by arnold
e
u
U
t
T
I 1
/*
I 8
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

/*
E 8
 * allocate space for and set up defaults for a new window
 *
D 5
 * %G% (Berkeley) %W
E 5
I 5
D 7
 * %G% (Berkeley) %W%
E 7
I 7
D 8
 * %W% (Berkeley) %G%
E 8
E 7
E 5
 */

# include	"curses.ext"

D 7
short	*calloc();
WINDOW	*malloc();
E 7
I 7
char	*malloc();
E 7

I 7
# define	SMALLOC	(short *) malloc

E 7
static WINDOW	*makenew();

# undef		nl	/* don't need it here, and it interferes	*/

WINDOW *
newwin(num_lines, num_cols, begy, begx)
int	num_lines, num_cols, begy, begx;
{
	reg WINDOW	*win;
	reg char	*sp;
	reg int		i, by, bx, nl, nc;
I 7
	reg int		j;
E 7

	by = begy;
	bx = begx;
	nl = num_lines;
	nc = num_cols;

	if (nl == 0)
		nl = LINES - by;
	if (nc == 0)
		nc = COLS - bx;
	if ((win = makenew(nl, nc, by, bx)) == NULL)
		return ERR;
I 7
	if ((win->_firstch = SMALLOC(nl * sizeof win->_firstch[0])) == NULL) {
		free(win->_y);
		free(win);
		return NULL;
	}
	if ((win->_lastch = SMALLOC(nl * sizeof win->_lastch[0])) == NULL) {
		free(win->_y);
		free(win->_firstch);
		free(win);
		return NULL;
	}
	win->_nextp = win;
	for (i = 0; i < nl; i++) {
		win->_firstch[i] = _NOCHANGE;
		win->_lastch[i] = _NOCHANGE;
	}
E 7
	for (i = 0; i < nl; i++)
D 7
		if ((win->_y[i] = (char *) calloc(nc, sizeof (char))) == NULL) {
			reg int		j;

E 7
I 7
		if ((win->_y[i] = malloc(nc * sizeof win->_y[0])) == NULL) {
E 7
			for (j = 0; j < i; j++)
D 7
				cfree(win->_y[j]);
			cfree(win->_firstch);
			cfree(win->_lastch);
			cfree(win->_y);
			cfree(win);
E 7
I 7
				free(win->_y[j]);
			free(win->_firstch);
			free(win->_lastch);
			free(win->_y);
			free(win);
E 7
			return ERR;
		}
		else
			for (sp = win->_y[i]; sp < win->_y[i] + nc; )
				*sp++ = ' ';
I 6
D 7
	win->_nextp = win;
E 7
I 7
	win->_ch_off = 0;
# ifdef DEBUG
	fprintf(outf, "NEWWIN: win->_ch_off = %d\n", win->_ch_off);
# endif
E 7
E 6
	return win;
}

WINDOW *
subwin(orig, num_lines, num_cols, begy, begx)
reg WINDOW	*orig;
D 7
int		num_lines, num_cols, begy, begx; {

E 7
I 7
int		num_lines, num_cols, begy, begx;
{
E 7
	reg int		i;
	reg WINDOW	*win;
	reg int		by, bx, nl, nc;
D 7
	reg int		j, k;
E 7

	by = begy;
	bx = begx;
	nl = num_lines;
	nc = num_cols;

	/*
	 * make sure window fits inside the original one
	 */
# ifdef	DEBUG
	fprintf(outf, "SUBWIN(%0.2o, %d, %d, %d, %d)\n", orig, nl, nc, by, bx);
# endif
	if (by < orig->_begy || bx < orig->_begx
D 4
	    || by + nl > orig->_maxy || bx + nc > orig->_maxx)
E 4
I 4
	    || by + nl > orig->_maxy + orig->_begy
D 5
	    || bx + nc > orig->_maxx + orig->_begx)
E 5
I 5
D 7
	    || bx + nc > orig->_maxx + orig->_begx) {
I 6
# ifdef	DEBUG
E 6
		fprintf(stderr, "returning ERR (1)\n");
I 6
		fprintf(stderr, "SUBWIN(begx = %d, begy = %d,maxx = %d, maxy = %d, nl = %d, nc = %d, by = %d, bx = %d)\n", orig->_begx,orig->_begy,orig->_maxx,orig->_maxy, nl, nc, by, bx);
# endif
E 7
I 7
	    || bx + nc > orig->_maxx + orig->_begx)
E 7
E 6
E 5
E 4
		return ERR;
I 5
D 7
	}
E 7
E 5
	if (nl == 0)
D 4
		nl = orig->_maxy - orig->_begy - by;
E 4
I 4
		nl = orig->_maxy + orig->_begy - by;
E 4
	if (nc == 0)
D 4
		nc = orig->_maxx - orig->_begx - bx;
E 4
I 4
		nc = orig->_maxx + orig->_begx - bx;
E 4
D 5
	if ((win = makenew(nl, nc, by, bx)) == NULL)
E 5
I 5
D 7
	if ((win = makenew(nl, nc, by, bx)) == NULL) {
		fprintf(stderr, "returning ERR (2)\n");
E 7
I 7
	if ((win = makenew(nl, nc, by, bx)) == NULL)
E 7
E 5
		return ERR;
I 5
D 7
	}
E 5
D 4
	j = orig->_begy + by;
	k = orig->_begx + bx;
E 4
I 4
	j = by - orig->_begy;
	k = bx - orig->_begx;
E 4
	for (i = 0; i < nl; i++)
		win->_y[i] = &orig->_y[j++][k];
E 7
D 6
	win->_flags = _SUBWIN;
E 6
I 6
	win->_nextp = orig->_nextp;
	orig->_nextp = win;
	win->_orig = orig;
I 7
	_set_subwin_(orig, win);
E 7
E 6
	return win;
}

/*
I 7
 * this code is shared with mvwin()
 */
_set_subwin_(orig, win)
register WINDOW	*orig, *win;
{
	register int	i, j, k;

	j = win->_begy - orig->_begy;
	k = win->_begx - orig->_begx;
	win->_ch_off = k;
# ifdef DEBUG
	fprintf(outf, "_SET_SUBWIN_: win->_ch_off = %d\n", win->_ch_off);
# endif
	win->_firstch = &orig->_firstch[j];
	win->_lastch = &orig->_lastch[j];
	for (i = 0; i < win->_maxy; i++, j++)
		win->_y[i] = &orig->_y[j][k];

}

/*
E 7
 *	This routine sets up a window buffer and returns a pointer to it.
 */
static WINDOW *
makenew(num_lines, num_cols, begy, begx)
int	num_lines, num_cols, begy, begx; {

	reg int		i;
	reg WINDOW	*win;
	reg int		by, bx, nl, nc;

	by = begy;
	bx = begx;
	nl = num_lines;
	nc = num_cols;

# ifdef	DEBUG
	fprintf(outf, "MAKENEW(%d, %d, %d, %d)\n", nl, nc, by, bx);
# endif
D 3
	if ((win = (WINDOW *) malloc(sizeof (WINDOW))) == NULL)
E 3
I 3
D 7
	if ((win = (WINDOW *) calloc(1, sizeof (WINDOW))) == NULL)
E 7
I 7
	if ((win = (WINDOW *) malloc(sizeof *win)) == NULL)
E 7
E 3
		return NULL;
# ifdef DEBUG
	fprintf(outf, "MAKENEW: nl = %d\n", nl);
# endif
D 7
	if ((win->_y = (char **) calloc(nl, sizeof (char *))) == NULL) {
		cfree(win);
E 7
I 7
	if ((win->_y = (char **) malloc(nl * sizeof win->_y[0])) == NULL) {
		free(win);
E 7
D 2
		return (WINDOW *) NULL;
E 2
I 2
		return NULL;
E 2
	}
D 7
	if ((win->_firstch = calloc(nl, sizeof (short))) == NULL) {
		cfree(win);
		cfree(win->_y);
I 2
		return NULL;
E 2
	}
	if ((win->_lastch = calloc(nl, sizeof (short))) == NULL) {
		cfree(win);
		cfree(win->_y);
		cfree(win->_firstch);
I 2
		return NULL;
E 2
	}
E 7
# ifdef DEBUG
	fprintf(outf, "MAKENEW: nc = %d\n", nc);
# endif
	win->_cury = win->_curx = 0;
D 7
	win->_clear = (nl == LINES && nc == COLS);
E 7
I 7
	win->_clear = FALSE;
E 7
	win->_maxy = nl;
	win->_maxx = nc;
	win->_begy = by;
	win->_begx = bx;
I 4
	win->_flags = 0;
E 4
	win->_scroll = win->_leave = FALSE;
D 7
	for (i = 0; i < nl; i++)
		win->_firstch[i] = win->_lastch[i] = _NOCHANGE;
	if (bx + nc == COLS) {
		win->_flags |= _ENDLINE;
		if (bx == 0 && nl == LINES && by == 0)
			win->_flags |= _FULLWIN;
		if (by + nl == LINES)
			win->_flags |= _SCROLLWIN;
	}
E 7
I 7
	_swflags_(win);
E 7
# ifdef DEBUG
	fprintf(outf, "MAKENEW: win->_clear = %d\n", win->_clear);
	fprintf(outf, "MAKENEW: win->_leave = %d\n", win->_leave);
	fprintf(outf, "MAKENEW: win->_scroll = %d\n", win->_scroll);
	fprintf(outf, "MAKENEW: win->_flags = %0.2o\n", win->_flags);
	fprintf(outf, "MAKENEW: win->_maxy = %d\n", win->_maxy);
	fprintf(outf, "MAKENEW: win->_maxx = %d\n", win->_maxx);
	fprintf(outf, "MAKENEW: win->_begy = %d\n", win->_begy);
	fprintf(outf, "MAKENEW: win->_begx = %d\n", win->_begx);
# endif
	return win;
I 7
}

_swflags_(win)
register WINDOW	*win;
{
	win->_flags &= ~(_ENDLINE|_FULLLINE|_FULLWIN|_SCROLLWIN);
	if (win->_begx + win->_maxx == COLS) {
		win->_flags |= _ENDLINE;
		if (win->_begx == 0) {
			if (AL && DL)
				win->_flags |= _FULLLINE;
			if (win->_maxy == LINES && win->_begy == 0)
				win->_flags |= _FULLWIN;
		}
		if (win->_begy + win->_maxy == LINES)
			win->_flags |= _SCROLLWIN;
	}
E 7
}
E 1
