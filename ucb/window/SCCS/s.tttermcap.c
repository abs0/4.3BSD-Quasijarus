h39252
s 00010/00005/00081
d D 3.9 88/06/29 21:36:52 bostic 10 9
c install approved copyright notice
e
s 00013/00007/00073
d D 3.8 88/02/21 13:37:42 bostic 9 8
c written by Edward Wang; attach Berkeley specific copyright
e
s 00011/00000/00069
d D 3.7 86/08/05 00:30:21 edward 8 6
c handle xn, check for UL == SO, ttstrcmp() added
e
s 00011/00000/00069
d R 3.7 86/08/04 14:20:56 edward 7 6
c handle xn, check for US == SO, ttstrcmp() added
e
s 00037/00007/00032
d D 3.6 85/09/20 15:15:28 edward 6 5
c correct padding
e
s 00006/00000/00033
d D 3.5 85/04/24 16:17:16 edward 5 4
c copyright messages
e
s 00001/00001/00032
d D 3.4 84/05/23 01:59:05 edward 4 3
c new sccs id
e
s 00006/00007/00027
d D 3.3 84/03/03 22:47:07 edward 3 2
c interrupt driven input
e
s 00000/00000/00034
d D 3.2 83/12/17 15:38:43 edward 2 1
c WWM_GRP added
e
s 00034/00000/00000
d D 3.1 83/08/17 15:48:20 edward 1 0
c date and time created 83/08/17 15:48:20 by edward
e
u
U
t
T
I 1
D 9
#ifndef lint
D 4
static	char *sccsid = "%W% %E%";
E 4
I 4
static char sccsid[] = "%W% %G%";
E 4
#endif

E 9
I 5
/*
D 9
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 9
I 9
 * Copyright (c) 1983 Regents of the University of California.
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
I 9

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 9

E 5
D 3
#include "ww.h"
E 3
#include "tt.h"

char *tgetstr();
I 6
char *tgoto();
char *malloc();
E 6

D 3
tt_pc(c)
E 3
I 3
tttputc(c)
E 3
{
D 3
	putchar(c);
E 3
I 3
	ttputc(c);
E 3
}

D 3
tt_sc(c)
E 3
I 3
ttxputc(c)
E 3
{
	*tt_strp++ = c;
}

D 6
char *
E 6
I 6
struct tt_str *
tttgetstr(str)
	char *str;
{
	register struct tt_str *s;

	if ((str = tgetstr(str, &tt_strp)) == 0)
		return 0;
	if ((s = (struct tt_str *) malloc(sizeof *s)) == 0)
		return 0;
	s->ts_str = str;
	s->ts_n = tt_strp - s->ts_str - 1;
	return s;
}

struct tt_str *
E 6
D 3
tt_xgetstr(str)
E 3
I 3
ttxgetstr(str)
E 3
D 6
char *str;
E 6
I 6
	char *str;
E 6
{
I 6
	register struct tt_str *s;
E 6
	char buf[100];
	char *bufp = buf;

D 6
	str = tgetstr(str, &bufp);
	if (str == 0)
E 6
I 6
	if (tgetstr(str, &bufp) == 0)
E 6
		return 0;
D 6
	str = tt_strp;
E 6
I 6
	if ((s = (struct tt_str *) malloc(sizeof *s)) == 0)
		return 0;
	s->ts_str = tt_strp;
E 6
D 3
	tputs(buf, 1, tt_sc);
	tt_sc(0);
E 3
I 3
	tputs(buf, 1, ttxputc);
D 6
	ttxputc(0);
E 3
	return str;
E 6
I 6
	s->ts_n = tt_strp - s->ts_str;
	*tt_strp++ = 0;
	return s;
}

tttgoto(s, col, row)
	struct tt_str *s;
{
	register char *p = s->ts_str;

	ttputs(tgoto(p, col, row));
	for (p += s->ts_n; *--p == 0;)
		ttputc(0);
E 6
}
I 8

ttstrcmp(a, b)
	register struct tt_str *a, *b;
{
	int n, r;

	if (r = bcmp(a->ts_str, b->ts_str,
			(n = a->ts_n - b->ts_n) < 0 ? a->ts_n : b->ts_n))
		return r;
	return n;
}
E 8
E 1
