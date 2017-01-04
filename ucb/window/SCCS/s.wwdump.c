h15640
s 00010/00005/00085
d D 3.13 88/06/29 21:37:53 bostic 13 12
c install approved copyright notice
e
s 00013/00007/00077
d D 3.12 88/02/21 13:38:16 bostic 12 11
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00078
d D 3.11 85/04/24 16:16:38 edward 11 10
c copyright messages
e
s 00001/00001/00077
d D 3.10 84/05/23 01:58:47 edward 10 9
c new sccs id
e
s 00001/00015/00077
d D 3.9 83/11/23 16:36:36 edward 9 8
c New cover scheme
e
s 00005/00005/00087
d D 3.8 83/11/15 18:18:26 edward 8 7
c used wrong addresses for dumpnvis
e
s 00000/00002/00092
d D 3.7 83/09/15 17:11:24 edward 7 6
c The 'M' command and rearranged debugging commands ('&')
e
s 00006/00006/00088
d D 3.6 83/09/15 12:23:23 edward 6 5
c reworked tt stuff
e
s 00007/00007/00087
d D 3.5 83/09/15 10:10:08 edward 5 4
c Now uses screen address for all buffers.
e
s 00001/00007/00093
d D 3.4 83/08/19 15:03:29 edward 4 3
c removed extra tt_setinsert
e
s 00001/00000/00099
d D 3.3 83/08/15 18:15:12 edward 3 2
c tt cleanup
e
s 00000/00000/00099
d D 3.2 83/08/11 17:24:29 edward 2 1
i
c last few day's work
e
s 00099/00000/00000
d D 3.1 83/08/09 18:37:50 edward 1 0
c date and time created 83/08/09 18:37:50 by edward
e
u
U
t
T
I 1
D 12
#ifndef lint
D 10
static	char *sccsid = "%W% %E%";
E 10
I 10
static char sccsid[] = "%W% %G%";
E 10
#endif

E 12
I 11
/*
D 12
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 12
I 12
 * Copyright (c) 1983 Regents of the University of California.
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
I 12

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 12

E 11
#include "ww.h"
I 3
#include "tt.h"
E 3

static char cmap[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

D 9
wwdumpcov(w)
register struct ww *w;
{
	register i, j;

D 4
	(*tt.tt_setinsert)(0);
E 4
D 6
	(*tt.tt_setmodes)(0);
E 6
I 6
	tt.tt_nmodes = 0;
E 6
	(*tt.tt_clear)();
D 5
	for (i = 0; i < w->ww_w.nr; i++) {
		(*tt.tt_move)(w->ww_w.t + i, w->ww_w.l);
		for (j = 0; j < w->ww_w.nc; j++)
E 5
I 5
	for (i = w->ww_i.t; i < w->ww_i.b; i++) {
		(*tt.tt_move)(i, w->ww_i.l);
		for (j = w->ww_i.l; j < w->ww_i.r; j++)
E 5
			(*tt.tt_putc)(cmap[w->ww_cov[i][j]]);
	}
}

E 9
wwdumpwin(w)
register struct ww *w;
{
	register i, j;

D 4
	(*tt.tt_setinsert)(0);
E 4
D 6
	(*tt.tt_setmodes)(0);
E 6
I 6
	tt.tt_nmodes = 0;
E 6
	(*tt.tt_clear)();
D 5
	for (i = 0; i < w->ww_w.nr; i++) {
		(*tt.tt_move)(w->ww_w.t + i, w->ww_w.l);
		for (j = 0; j < w->ww_w.nc; j++)
E 5
I 5
	for (i = w->ww_i.t; i < w->ww_i.b; i++) {
		(*tt.tt_move)(i, w->ww_i.l);
		for (j = w->ww_i.l; j < w->ww_i.r; j++)
E 5
D 9
			(*tt.tt_putc)(w->ww_win[i][j] & WWM_COV ? 'C' : ' ');
E 9
I 9
			(*tt.tt_putc)(w->ww_win[i][j] & WWM_GLS ? 'G' : ' ');
E 9
	}
}

wwdumpnvis(w)
register struct ww *w;
{
	register i;
I 8
	char buf[20];
E 8

D 4
	(*tt.tt_setinsert)(0);
E 4
D 6
	(*tt.tt_setmodes)(0);
E 6
I 6
	tt.tt_nmodes = 0;
E 6
	(*tt.tt_clear)();
D 8
	for (i = 0; i < w->ww_w.nr; i++) {
D 5
		(*tt.tt_move)(w->ww_w.t + i, w->ww_w.l);
E 5
I 5
		(*tt.tt_move)(i, w->ww_w.l);
E 5
		(*tt.tt_putc)(w->ww_nvis[i] / 100 % 10 + '0');
		(*tt.tt_putc)(w->ww_nvis[i] / 10 % 10 + '0');
		(*tt.tt_putc)(w->ww_nvis[i] % 10 + '0');
E 8
I 8
	for (i = w->ww_i.t; i < w->ww_i.b; i++) {
		(*tt.tt_move)(i, w->ww_i.l);
		(void) sprintf(buf, "%d", w->ww_nvis[i]);
		(*tt.tt_write)(buf, strlen(buf));
E 8
	}
}

wwdumpsmap()
{
	register i, j;

D 4
	(*tt.tt_setinsert)(0);
E 4
D 6
	(*tt.tt_setmodes)(0);
E 6
I 6
	tt.tt_nmodes = 0;
E 6
	(*tt.tt_clear)();
	for (i = 0; i < wwnrow; i++) {
		(*tt.tt_move)(i, 0);
		for (j = 0; j < wwncol; j++)
			(*tt.tt_putc)(cmap[wwsmap[i][j]]);
	}
}

D 7
/*
E 7
wwdumpns()
{
	register i, j;

D 4
	(*tt.tt_setinsert)(0);
E 4
	(*tt.tt_clear)();
	for (i = 0; i < wwnrow; i++) {
		(*tt.tt_move)(i, 0);
		for (j = 0; j < wwncol; j++) {
D 6
			(*tt.tt_setmodes)(wwns[i][j].c_m);
E 6
I 6
			tt.tt_nmodes = wwns[i][j].c_m & tt.tt_availmodes;
E 6
			(*tt.tt_putc)(wwns[i][j].c_c);
		}
	}
}

wwdumpos()
{
	register i, j;

D 4
	(*tt.tt_setinsert)(0);
	(*tt.tt_clreos)();
E 4
I 4
	(*tt.tt_clear)();
E 4
	for (i = 0; i < wwnrow; i++) {
		(*tt.tt_move)(i, 0);
		for (j = 0; j < wwncol; j++) {
D 6
			(*tt.tt_setmodes)(wwns[i][j].c_m);
E 6
I 6
			tt.tt_nmodes = wwos[i][j].c_m & tt.tt_availmodes;
E 6
			(*tt.tt_putc)(wwns[i][j].c_c);
		}
	}
}
D 7
*/
E 7
E 1
