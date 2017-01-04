h36316
s 00001/00001/00062
d D 7.4 88/09/12 12:46:41 bostic 4 3
c erase chars on DEL
e
s 00010/00005/00053
d D 7.3 88/06/29 18:19:16 bostic 3 2
c install approved copyright notice
e
s 00009/00000/00049
d D 7.2 88/02/24 10:14:54 bostic 2 1
c implement ^R and ^W
e
s 00049/00000/00000
d D 7.1 88/02/05 16:58:19 bostic 1 0
c date and time created 88/02/05 16:58:19 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 3
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 3
I 3
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
E 3
 *
 *	%W% (Berkeley) %G%
 */

gets(buf)
	char *buf;
{
	register int c;
	register char *lp;

	for (lp = buf;;)
		switch(c = getchar() & 0177) {
		case '\n':
		case '\r':
			*lp = '\0';
			return;
		case '\b':
I 4
		case '\177':
E 4
			if (lp > buf) {
				lp--;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			break;
		case '#':
D 4
		case '\177':
E 4
			if (lp > buf)
				--lp;
			break;
I 2
		case 'r'&037: {
			register char *p;

			putchar('\n');
			for (p = buf; p < lp; ++p)
				putchar(*p);
			break;
		}
E 2
		case '@':
		case 'u'&037:
I 2
		case 'w'&037:
E 2
			lp = buf;
			putchar('\n');
			break;
		default:
			*lp++ = c;
		}
	/*NOTREACHED*/
}
E 1
