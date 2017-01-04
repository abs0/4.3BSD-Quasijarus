h60414
s 00010/00005/00144
d D 3.19 88/06/29 21:39:01 bostic 19 18
c install approved copyright notice
e
s 00013/00007/00136
d D 3.18 88/02/21 13:39:02 bostic 18 17
c written by Edward Wang; attach Berkeley specific copyright
e
s 00002/00002/00141
d D 3.17 86/08/05 00:15:56 edward 17 16
c make sure unavailable mode bits are not set,
c so wwupdate1() doesn't have to mask them out.
e
s 00006/00000/00137
d D 3.16 85/04/24 16:17:09 edward 16 15
c copyright messages
e
s 00004/00002/00133
d D 3.15 84/07/12 13:37:30 edward 15 14
c now it really works
e
s 00003/00002/00132
d D 3.14 84/07/08 17:22:49 edward 14 13
c improved last col, last line update
e
s 00001/00001/00133
d D 3.13 84/05/23 01:59:02 edward 13 12
c new sccs id
e
s 00003/00002/00131
d D 3.12 84/03/03 22:46:58 edward 12 11
c interrupt driven input
e
s 00040/00025/00093
d D 3.11 84/01/06 16:20:09 edward 11 10
c smart clreol algorithm
e
s 00021/00007/00097
d D 3.10 83/12/21 13:26:59 edward 10 9
c write last char bug
e
s 00029/00004/00075
d D 3.9 83/12/02 22:45:58 edward 9 8
c WWU_MAJOR, clreol in wwupdate(), and more optimizations.
e
s 00013/00018/00066
d D 3.8 83/09/15 12:23:43 edward 8 7
c reworked tt stuff
e
s 00000/00001/00084
d D 3.7 83/08/19 15:00:18 edward 7 6
c took out useless tt_setinsert()
e
s 00023/00003/00062
d D 3.6 83/08/17 17:41:21 edward 6 5
c better wrap around handling.
e
s 00037/00009/00028
d D 3.5 83/08/16 15:25:57 edward 5 4
c smart update:  do it by chunks.
e
s 00012/00001/00025
d D 3.4 83/08/16 12:55:31 edward 4 3
c wwtouched added
e
s 00001/00000/00025
d D 3.3 83/08/15 18:15:23 edward 3 2
c tt cleanup
e
s 00000/00000/00025
d D 3.2 83/08/11 17:24:56 edward 2 1
i
c last few day's work
e
s 00025/00000/00000
d D 3.1 83/08/09 18:37:55 edward 1 0
c date and time created 83/08/09 18:37:55 by edward
e
u
U
t
T
I 1
D 18
#ifndef lint
D 13
static	char *sccsid = "%W% %E%";
E 13
I 13
static char sccsid[] = "%W% %G%";
E 13
#endif

E 18
I 16
/*
D 18
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 18
I 18
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 19
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 19
I 19
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
E 19
E 18
 */
I 18

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 18

E 16
#include "ww.h"
I 3
#include "tt.h"
E 3

D 12
wwupdate()
E 12
I 12
wwupdate1(top, bot)
E 12
{
D 5
	register i, j;
E 5
I 5
	int i;
	register j;
D 11
	int c, x;
E 11
E 5
	register union ww_char *ns, *os;
I 4
D 5
	register char *touched;
E 5
I 5
D 11
	register char *p, *q;
	char m;
E 11
	char *touched;
E 5
D 11
	register didit;
I 5
	char buf[512];			/* > wwncol */
I 6
	union ww_char lastc;
E 11
I 11
	char didit;
E 11
E 6
E 5
E 4

I 4
	wwnupdate++;
E 4
D 7
	(*tt.tt_setinsert)(0);
E 7
D 4
	for (i = 0; i < wwnrow; i++) {
E 4
I 4
D 12
	for (i = 0, touched = wwtouched; i < wwnrow; i++, touched++) {
E 12
I 12
	for (i = top, touched = &wwtouched[i]; i < bot && !wwinterrupt();
	     i++, touched++) {
E 12
		if (!*touched)
			continue;
D 9
		wwntouched++;
		*touched = 0;
E 9
I 9
D 11
		if (*touched & WWU_MAJOR) {
			int ncleared = 0;
			int nsame = 0;
E 11
I 11
		if (*touched & WWU_MAJOR && tt.tt_clreol != 0) {
			register gain = 0;
			register best_gain = 0;
			register best;
E 11
E 9
I 5

I 9
			wwnmajline++;
			j = wwncol;
D 11
			ns = wwns[i];
			os = wwos[i];
E 11
I 11
			ns = &wwns[i][j];
			os = &wwos[i][j];
E 11
			while (--j >= 0) {
D 11
				if (ns->c_w == ' ') {
					if (ns->c_w != os->c_w)
						ncleared++;
				} else
					if (ns->c_w == os->c_w)
						nsame++;
				ns++;
				os++;
E 11
I 11
				/*
				 * The cost of clearing is:
				 *	ncol - nblank + X
				 * The cost of straight update is:
				 *	ncol - nsame
				 * We clear if:  nblank - nsame > X
				 * X is the clreol overhead.
				 * So we make gain = nblank - nsame.
				 */
				if ((--ns)->c_w == (--os)->c_w)
					gain--;
				else
					best_gain--;
				if (ns->c_w == ' ')
					gain++;
				if (gain >= best_gain) {
					best = j;
					best_gain = gain;
				}
E 11
			}
D 11
			if (tt.tt_clreol != 0 && ncleared > nsame + 4) {
				(*tt.tt_move)(i, 0);
E 11
I 11
			if (best_gain > 4) {
				(*tt.tt_move)(i, best);
E 11
				(*tt.tt_clreol)();
D 11
				for (j = wwncol, os = wwos[i]; --j >= 0;)
E 11
I 11
				for (j = wwncol - best, os = &wwos[i][best];
				     --j >= 0;)
E 11
					os++->c_w = ' ';
			} else
				wwnmajmiss++;
		}
I 14
		*touched = 0;
E 14
		wwnupdline++;
		didit = 0;
E 9
E 5
E 4
		ns = wwns[i];
		os = wwos[i];
I 4
D 9
		didit = 0;
E 9
E 4
D 5
		for (j = 0; j < wwncol; j++, ns++, os++) {
			if (ns->c_w != os->c_w) {
				(*tt.tt_move)(i, j);
				(*tt.tt_setmodes)(ns->c_m);
				(*tt.tt_putc)(ns->c_c);
				*os = *ns;
I 4
				didit++;
E 5
I 5
		for (j = 0; j < wwncol;) {
I 11
			register char *p, *q;
			char m;
			int c;
			register n;
			char buf[512];			/* > wwncol */
			union ww_char lastc;

E 11
			for (; j++ < wwncol && ns++->c_w == os++->c_w;)
				;
			if (j > wwncol)
				break;
			p = buf;
D 8
			m = ns[-1].c_m;
E 8
I 8
D 17
			m = ns[-1].c_m & tt.tt_availmodes;
E 17
I 17
			m = ns[-1].c_m;
E 17
E 8
			c = j - 1;
			os[-1] = ns[-1];
			*p++ = ns[-1].c_c;
D 11
			x = 5;
E 11
I 11
			n = 5;
E 11
			q = p;
D 8
			while (j < wwncol && ns->c_m == m) {
E 8
I 8
D 17
			while (j < wwncol && (ns->c_m&tt.tt_availmodes) == m) {
E 17
I 17
			while (j < wwncol && ns->c_m == m) {
E 17
E 8
				*p++ = ns->c_c;
				if (ns->c_w == os->c_w) {
D 11
					if (--x <= 0)
E 11
I 11
					if (--n <= 0)
E 11
						break;
					os++;
					ns++;
				} else {
D 11
					x = 5;
E 11
I 11
					n = 5;
E 11
					q = p;
I 6
					lastc = *os;
E 6
					*os++ = *ns++;
				}
				j++;
E 5
E 4
			}
I 8
			tt.tt_nmodes = m;
D 10
			(*tt.tt_move)(i, c);
E 10
E 8
I 5
D 6
			(*tt.tt_move)(i, c);
			(*tt.tt_setmodes)(m);
			(*tt.tt_write)(buf, q - 1);
E 6
I 6
			if (wwwrap
			    && i == wwnrow - 1 && q - buf + c == wwncol) {
D 8
				if (tt.tt_setinsert != 0) {
					(*tt.tt_move)(i, c);
					(*tt.tt_setmodes)(m);
					(*tt.tt_write)(buf + 1, q - 1);
					(*tt.tt_move)(i, c);
					(*tt.tt_setinsert)(1);
					(*tt.tt_write)(buf, buf);
					(*tt.tt_setinsert)(0);
E 8
I 8
				if (tt.tt_hasinsert) {
D 10
					(*tt.tt_write)(buf + 1, q - buf - 1);
					(*tt.tt_move)(i, c);
					tt.tt_ninsert = 1;
					(*tt.tt_write)(buf, 1);
					tt.tt_ninsert = 0;
E 10
I 10
					if (q - buf != 1) {
						(*tt.tt_move)(i, c);
						(*tt.tt_write)(buf + 1,
							q - buf - 1);
						(*tt.tt_move)(i, c);
						tt.tt_ninsert = 1;
						(*tt.tt_write)(buf, 1);
						tt.tt_ninsert = 0;
					} else {
						(*tt.tt_move)(i, c - 1);
						(*tt.tt_write)(buf, 1);
						tt.tt_nmodes = ns[-2].c_m;
						(*tt.tt_move)(i, c - 1);
						tt.tt_ninsert = 1;
						(*tt.tt_write)(&ns[-2].c_c, 1);
						tt.tt_ninsert = 0;
					}
E 10
E 8
				} else {
I 10
D 15
					(*tt.tt_move)(i, c);
E 10
D 14
					os[-1] = lastc;
E 14
D 8
					(*tt.tt_move)(i, c);
					(*tt.tt_setmodes)(m);
					(*tt.tt_write)(buf, q - 2);
E 8
I 8
					(*tt.tt_write)(buf, q - buf - 1);
E 15
I 15
					if (q - buf > 1) {
						(*tt.tt_move)(i, c);
						(*tt.tt_write)(buf, q-buf-1);
					}
E 15
I 14
					os[-1] = lastc;
					*touched = WWU_TOUCHED;
E 14
E 8
				}
D 8
			} else {
				(*tt.tt_move)(i, c);
				(*tt.tt_setmodes)(m);
				(*tt.tt_write)(buf, q - 1);
			}
E 8
I 8
D 10
			} else
E 10
I 10
			} else {
				(*tt.tt_move)(i, c);
E 10
				(*tt.tt_write)(buf, q - buf);
I 10
			}
E 10
E 8
E 6
			didit++;
E 5
		}
I 4
		if (!didit)
D 9
			wwnmiss++;
E 9
I 9
			wwnupdmiss++;
D 14
		*touched = 0;
E 14
E 9
E 4
	}
}
E 1
