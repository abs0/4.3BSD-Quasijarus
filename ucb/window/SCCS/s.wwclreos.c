h07450
s 00010/00005/00049
d D 3.8 88/06/29 21:37:36 bostic 8 7
c install approved copyright notice
e
s 00013/00007/00041
d D 3.7 88/02/21 13:38:06 bostic 7 6
c written by Edward Wang; attach Berkeley specific copyright
e
s 00029/00002/00019
d D 3.6 87/05/18 12:11:19 edward 6 5
c use \n at bottom to scroll entire screen,
c use clear to eos to clear entire screen
e
s 00006/00000/00015
d D 3.5 85/04/24 16:17:20 edward 5 4
c copyright messages
e
s 00001/00001/00014
d D 3.4 84/05/23 01:59:07 edward 4 3
c new sccs id
e
s 00004/00004/00011
d D 3.3 83/09/15 10:10:19 edward 3 2
c Now uses screen address for all buffers.
e
s 00006/00002/00009
d D 3.2 83/08/11 17:25:00 edward 2 1
i
c last few day's work
e
s 00011/00000/00000
d D 3.1 83/08/09 18:40:17 edward 1 0
c date and time created 83/08/09 18:40:17 by edward
e
u
U
t
T
I 1
D 7
#ifndef lint
D 4
static	char *sccsid = "%W% %E%";
E 4
I 4
static char sccsid[] = "%W% %G%";
E 4
#endif

E 7
I 5
/*
D 7
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 7
I 7
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 8
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 8
I 8
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
E 8
E 7
 */
I 7

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 7

E 5
#include "ww.h"
I 6
#include "tt.h"
E 6

D 2
wwclreos(w)
E 2
I 2
D 3
wwclreos(w, line, col)
E 3
I 3
wwclreos(w, row, col)
E 3
E 2
register struct ww *w;
{
D 2
	w = w;
E 2
I 2
	register i;
I 6
	int cleared = 0;
E 6

D 3
	wwclreol(w, line, col);
	for (i = line + 1; i < w->ww_nline; i++)
		wwclreol(w, i, 0);
E 3
I 3
D 6
	wwclreol(w, row, col);
E 6
I 6
	/*
	 * Quick and dirty check for windows that cover the bottom
	 * portion of the screen.  Not meant to be complete.
	 */
	if (tt.tt_clreos && w->ww_i.b == wwnrow && w->ww_i.l == 0 &&
	    w->ww_i.r == wwncol && wwvisible(w)) {
		register j;
		register union ww_char *s;

		i = row;
		(*tt.tt_move)(i, col);
		(*tt.tt_clreos)();
		/*
		 * We have to fix wwos becuase wwclreol1 won't do that.
		 */
		s = &wwos[i][col];
		for (j = wwncol - col; --j >= 0;)
			s++->c_w = ' ';
		for (i++; i < wwnrow; i++) {
			s = wwos[i];
			for (j = wwncol; --j >= 0;)
				s++->c_w = ' ';
		}
		cleared = 1;
	}
	wwclreol1(w, row, col, cleared);
E 6
	for (i = row + 1; i < w->ww_b.b; i++)
D 6
		wwclreol(w, i, w->ww_b.l);
E 6
I 6
		wwclreol1(w, i, w->ww_b.l, cleared);
E 6
E 3
E 2
}
E 1
