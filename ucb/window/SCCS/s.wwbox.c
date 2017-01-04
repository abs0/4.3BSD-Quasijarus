h47749
s 00010/00005/00037
d D 3.6 88/06/29 21:37:23 bostic 6 5
c install approved copyright notice
e
s 00013/00007/00029
d D 3.5 88/02/21 13:38:00 bostic 5 4
c written by Edward Wang; attach Berkeley specific copyright
e
s 00006/00000/00030
d D 3.4 85/04/24 16:16:51 edward 4 3
c copyright messages
e
s 00001/00001/00029
d D 3.3 84/05/23 01:58:54 edward 3 2
c new sccs id
e
s 00008/00014/00022
d D 3.2 83/08/19 17:33:04 edward 2 1
c moved fmap into struct ww and added WWO_FRAME to allocate it.
e
s 00036/00000/00000
d D 3.1 83/08/18 17:17:12 edward 1 0
c date and time created 83/08/18 17:17:12 by edward
e
u
U
t
T
I 1
D 5
#ifndef lint
D 3
static	char *sccsid = "%W% %E%";
E 3
I 3
static char sccsid[] = "%W% %G%";
E 3
#endif

E 5
I 4
/*
D 5
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 5
I 5
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 6
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 6
I 6
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
E 6
E 5
 */
I 5

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 5

E 4
#include "ww.h"
#include "tt.h"

wwbox(w, r, c, nr, nc)
register struct ww *w;
register r, c;
int nr, nc;
{
	register r1, c1;
	register i;

	r1 = r + nr - 1;
	c1 = c + nc - 1;
D 2
	wwframec(w, r, c, WWF_D|WWF_R, 0);
E 2
I 2
	wwframec(w, r, c, WWF_D|WWF_R);
E 2
	for (i = c + 1; i < c1; i++)
D 2
		wwframec(w, r, i, WWF_L|WWF_R, 0);
	wwframec(w, r, i, WWF_L|WWF_D, 0);
E 2
I 2
		wwframec(w, r, i, WWF_L|WWF_R);
	wwframec(w, r, i, WWF_L|WWF_D);
E 2
	for (i = r + 1; i < r1; i++)
D 2
		wwframec(w, i, c1, WWF_U|WWF_D, 0);
	wwframec(w, i, c1, WWF_U|WWF_L, 0);
E 2
I 2
		wwframec(w, i, c1, WWF_U|WWF_D);
	wwframec(w, i, c1, WWF_U|WWF_L);
E 2
	for (i = c1 - 1; i > c; i--)
D 2
		wwframec(w, r1, i, WWF_R|WWF_L, 0);
	wwframec(w, r1, i, WWF_R|WWF_U, 0);
E 2
I 2
		wwframec(w, r1, i, WWF_R|WWF_L);
	wwframec(w, r1, i, WWF_R|WWF_U);
E 2
	for (i = r1 - 1; i > r; i--)
D 2
		wwframec(w, i, c, WWF_D|WWF_U, 0);
}

wwunbox(w)
struct ww *w;
{
	wwunframe1(w, 0);
E 2
I 2
		wwframec(w, i, c, WWF_D|WWF_U);
E 2
}
E 1
