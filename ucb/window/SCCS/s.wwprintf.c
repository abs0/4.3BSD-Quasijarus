h64359
s 00010/00005/00039
d D 3.8 88/06/29 21:38:33 bostic 14 13
c install approved copyright notice
e
s 00013/00007/00031
d D 3.7 88/02/21 13:38:42 bostic 13 12
c written by Edward Wang; attach Berkeley specific copyright
e
s 00007/00002/00031
d D 3.6 87/10/02 19:36:54 edward 12 11
c changes from mips!dce, most compatibility stuff
e
s 00006/00000/00027
d D 3.5 85/04/24 16:13:20 edward 11 10
c copyright messages
e
s 00001/00001/00026
d D 3.4 84/05/23 01:57:04 edward 10 9
c new sccs id
e
s 00001/00001/00026
d D 3.3 84/03/23 18:16:36 edward 9 8
c compile with -R
e
s 00002/00001/00025
d D 3.2 84/03/03 22:44:41 edward 8 7
c interrupt driven input
e
s 00000/00000/00026
d D 3.1 83/08/11 17:22:03 edward 7 5
i 6
c last few day's work
e
s 00001/00032/00025
d D 2.1.1.1 83/08/09 18:35:21 edward 6 5
c mile stone
e
s 00000/00000/00057
d D 2.1 83/07/30 13:27:07 edward 5 4
c prepare for major change
e
s 00000/00000/00057
d D 1.4 83/07/22 17:09:48 edward 4 3
c scrolling.
c uses Wscreensize() to get screen size.
c More intelligent framing.
c etc.
e
s 00002/00002/00055
d D 1.3 83/07/19 20:08:00 edward 3 2
c today's work
e
s 00000/00000/00057
d D 1.2 83/07/18 21:04:05 edward 2 1
c multiple window
e
s 00057/00000/00000
d D 1.1 83/07/17 15:19:07 edward 1 0
c date and time created 83/07/17 15:19:07 by edward
e
u
U
f b 
t
T
I 1
D 13
#ifndef lint
D 10
static	char *sccsid = "%W% %E%";
E 10
I 10
static char sccsid[] = "%W% %G%";
E 10
#endif

E 13
I 11
/*
D 13
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 13
I 13
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
E 13
 */
I 13

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 13

E 11
#include "ww.h"
I 12
#include <varargs.h>
E 12

I 6
/*VARARGS2*/
E 6
D 12
wwprintf(w, fmt, args)
E 12
I 12
wwprintf(w, fmt, va_alist)
E 12
struct ww *w;
char *fmt;
I 12
va_dcl
E 12
{
I 8
#include <stdio.h>
E 8
	struct _iobuf _wwbuf;
D 9
	static char buf[1024];
E 9
I 9
	char buf[1024];
I 12
	va_list ap;
E 12
E 9

	/*
	 * A danger is that when buf overflows, _flsbuf() will be
	 * called automatically.  It doesn't check for _IOSTR.
	 * We set the file descriptor to -1 so no actual io will be done.
	 */
	_wwbuf._flag = _IOWRT+_IOSTRG;
	_wwbuf._base = _wwbuf._ptr = buf;
	_wwbuf._cnt = sizeof buf;
	_wwbuf._file = -1;			/* safe */
D 12
	_doprnt(fmt, &args, &_wwbuf);
E 12
I 12
	va_start(ap);
	_doprnt(fmt, ap, &_wwbuf);
	va_end(ap);
E 12
D 8
	return wwwrite(w, buf, _wwbuf._ptr - buf);
E 8
I 8
	(void) wwwrite(w, buf, _wwbuf._ptr - buf);
E 8
}
D 6

D 3
#ifdef notdef
E 3
I 3
/*
E 3
wwprintf(w, fmt, args)
struct ww *w;
char *fmt;
{
	_doprnt(fmt, &args, w);
	return 0;
}

_strout(count, string, adjust, file, fillch)
register char *string;
register count;
int adjust;
register struct ww *file;
{
	while (adjust < 0) {
		if (*string=='-' && fillch=='0') {
			wputc(*string++, file);
			count--;
		}
		wputc(fillch, file);
		adjust++;
	}
	while (--count>=0)
		wputc(*string++, file);
	while (adjust) {
		wputc(fillch, file);
		adjust--;
	}
}
D 3
#endif
E 3
I 3
*/
E 6
E 3
E 1
