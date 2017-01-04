h00027
s 00010/00005/00055
d D 3.5 88/06/29 21:35:49 bostic 5 4
c install approved copyright notice
e
s 00013/00007/00047
d D 3.4 88/02/21 13:36:48 bostic 4 3
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00048
d D 3.3 85/04/24 16:24:23 edward 3 2
c copyright messages
e
s 00000/00028/00048
d D 3.2 85/04/03 22:21:00 edward 2 1
c lint, and others
e
s 00076/00000/00000
d D 3.1 85/03/01 17:49:15 edward 1 0
c date and time created 85/03/01 17:49:15 by edward
e
u
U
t
T
I 1
D 4
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif

E 4
I 3
/*
D 4
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 4
I 4
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 5
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 5
I 5
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
E 5
E 4
 */
I 4

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 4

E 3
#include "defs.h"

/*
 * Window size.
 */

c_size(w)
register struct ww *w;
{
	int col, row;

	if (!terse)
		wwputs("New window size (lower right corner): ", cmdwin);
	col = MIN(w->ww_w.r, wwncol) - 1;
	row = MIN(w->ww_w.b, wwnrow) - 1;
	wwadd(boxwin, framewin->ww_back);
	for (;;) {
		wwbox(boxwin, w->ww_w.t - 1, w->ww_w.l - 1,
			row - w->ww_w.t + 3, col - w->ww_w.l + 3);
		wwsetcursor(row, col);
		while (wwpeekc() < 0)
			wwiomux();
		switch (getpos(&row, &col, w->ww_w.t, w->ww_w.l,
			wwnrow - 1, wwncol - 1)) {
		case 3:
			wwunbox(boxwin);
			wwdelete(boxwin);
			return;
		case 2:
			wwunbox(boxwin);
			break;
		case 1:
			wwunbox(boxwin);
		case 0:
			continue;
		}
		break;
	}
	wwdelete(boxwin);
	if (!terse)
		wwputc('\n', cmdwin);
	wwcurtowin(cmdwin);
	sizewin(w, row - w->ww_w.t + 1, col - w->ww_w.l + 1);
}
D 2

sizewin(w, nrow, ncol)
register struct ww *w;
{
	struct ww *back = w->ww_back;

	w->ww_alt.nr = w->ww_w.nr;
	w->ww_alt.nc = w->ww_w.nc;
	wwdelete(w);
	wwsize(w, nrow, ncol);
	wwadd(w, back);
	reframe();
}

iconwin(w)
register struct ww *w;
{
	struct ww_dim new;
	struct ww *back = w->ww_back;

	new = w->ww_alt;
	w->ww_alt = w->ww_w;
	wwdelete(w);
	wwsize(w, new.nr, new.nc);
	wwmove(w, new.t, new.l);
	wwadd(w, back);
	reframe();
}
E 2
E 1
