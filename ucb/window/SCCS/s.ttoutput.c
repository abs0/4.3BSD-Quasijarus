h07499
s 00010/00005/00109
d D 3.6 88/06/29 21:36:50 bostic 6 5
c install approved copyright notice
e
s 00013/00007/00101
d D 3.5 88/02/21 13:37:41 bostic 5 4
c written by Edward Wang; attach Berkeley specific copyright
e
s 00056/00000/00052
d D 3.4 85/09/19 14:12:56 edward 4 3
c ttwrite added
e
s 00006/00000/00046
d D 3.3 85/04/24 16:23:14 edward 3 2
c copyright messages
e
s 00001/00001/00045
d D 3.2 84/05/23 02:00:56 edward 2 1
c new sccs id
e
s 00046/00000/00000
d D 3.1 84/03/03 22:50:22 edward 1 0
c date and time created 84/03/03 22:50:22 by edward
e
u
U
t
T
I 1
D 5
#ifndef lint
D 2
static	char *sccsid = "%W% %E%";
E 2
I 2
static char sccsid[] = "%W% %G%";
E 2
#endif

E 5
I 3
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

E 3
#include "ww.h"
#include "tt.h"
#include <sys/errno.h>

/*
 * Buffered output package.
 * We need this because stdio fails on non-blocking writes.
 */

ttflush()
{
	register char *p;
	register n;
	extern errno;

	wwnflush++;
	for (p = tt_ob; p < tt_obp;) {
		wwnwr++;
		n = write(1, p, tt_obp - p);
		if (n < 0) {
			wwnwre++;
			if (errno != EWOULDBLOCK) {
				/* can't deal with this */
				p = tt_obp;
			}
		} else if (n == 0) {
			/* what to do? */
			wwnwrz++;
		} else {
			wwnwrc += n;
			p += n;
		}
	}
	tt_obp = tt_ob;
}

ttputs(s)
register char *s;
{
	while (*s)
		ttputc(*s++);
}
I 4

ttwrite(s, n)
	register char *s;
	register n;
{
	switch (n) {
	case 0:
		break;
	case 1:
		ttputc(*s);
		break;
	case 2:
		if (tt_obe - tt_obp < 2)
			ttflush();
		*tt_obp++ = *s++;
		*tt_obp++ = *s;
		break;
	case 3:
		if (tt_obe - tt_obp < 3)
			ttflush();
		*tt_obp++ = *s++;
		*tt_obp++ = *s++;
		*tt_obp++ = *s;
		break;
	case 4:
		if (tt_obe - tt_obp < 4)
			ttflush();
		*tt_obp++ = *s++;
		*tt_obp++ = *s++;
		*tt_obp++ = *s++;
		*tt_obp++ = *s;
		break;
	case 5:
		if (tt_obe - tt_obp < 5)
			ttflush();
		*tt_obp++ = *s++;
		*tt_obp++ = *s++;
		*tt_obp++ = *s++;
		*tt_obp++ = *s++;
		*tt_obp++ = *s;
		break;
	default:
		while (n > 0) {
			register m;

			while ((m = tt_obe - tt_obp) == 0)
				ttflush();
			if ((m = tt_obe - tt_obp) > n)
				m = n;
			bcopy(s, tt_obp, m);
			tt_obp += m;
			s += m;
			n -= m;
		}
	}
}
E 4
E 1
