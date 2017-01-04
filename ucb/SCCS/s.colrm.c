h50688
s 00010/00005/00100
d D 5.3 88/06/29 21:50:40 bostic 7 6
c install approved copyright notice
e
s 00011/00004/00094
d D 5.2 87/12/02 17:32:09 bostic 6 5
c bug report 4.3BSD/ucb/149; exit 0 on success
e
s 00016/00001/00082
d D 5.1 85/05/31 09:08:55 dist 5 4
c Add copyright
e
s 00021/00021/00062
d D 4.4 84/07/02 16:13:43 ralph 4 3
c fix line length limitations and don't use setbuf.
e
s 00008/00003/00075
d D 4.3 82/02/13 23:16:08 root 3 2
c change to really check for eof from stdin
e
s 00007/00002/00071
d D 4.2 80/10/10 00:42:07 bill 2 1
c handle tabs properly
e
s 00073/00000/00000
d D 4.1 80/10/01 17:25:49 bill 1 0
c date and time created 80/10/01 17:25:49 by bill
e
u
U
t
T
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
D 5
static	char *Sccsid = "%W% (Berkeley) %G%";
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
D 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
I 6
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific written prior permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 6
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif /* not lint */
E 6

E 5
E 2
#include <stdio.h>
/*
COLRM removes unwanted columns from a file
	Jeff Schriebman  UC Berkeley 11-74
*/


main(argc,argv)
char **argv;
{
D 4
	int first;
	register ct,last;
	register char c;
	char buffer[BUFSIZ];
E 4
I 4
	register c, ct, first, last;
E 4

D 4
	setbuf(stdout, buffer);
	first = 20000;
	last  = -1;
	if (argc>1) {
E 4
I 4
	first = 0;
	last = 0;
	if (argc > 1)
E 4
		first = getn(*++argv);
D 4
		last = 20000;
	}
	if (argc>2)
E 4
I 4
	if (argc > 2)
E 4
		last = getn(*++argv);

start:
	ct = 0;
loop1:
D 3
	if ((c=getc(stdin))<0)
E 3
I 3
	c = getc(stdin);
	if (feof(stdin))
E 3
		goto fin;
D 2
	ct++;
E 2
I 2
	if (c == '\t')
D 4
		ct = (ct + 8) &~ 7;
E 4
I 4
		ct = (ct + 8) & ~7;
E 4
	else if (c == '\b')
		ct = ct ? ct - 1 : 0;
	else
		ct++;
E 2
D 4
	if (c=='\n') {
		putc(c,stdout);
E 4
I 4
	if (c == '\n') {
		putc(c, stdout);
E 4
		goto start;
	}
D 4
	if (ct<first) {
		putc(c,stdout);
E 4
I 4
	if (!first || ct < first) {
		putc(c, stdout);
E 4
		goto loop1;
	}

/* Loop getting rid of characters */
D 4
	for (;ct<last;ct++) {
E 4
I 4
	while (!last || ct < last) {
E 4
D 3
		if ((c=getc(stdin))<0)
E 3
I 3
		c = getc(stdin);
		if (feof(stdin))
E 3
			goto fin;
D 4
		if (c=='\n') {
			putc(c,stdout);
E 4
I 4
		if (c == '\n') {
			putc(c, stdout);
E 4
			goto start;
		}
I 4
		if (c == '\t')
			ct = (ct + 8) & ~7;
		else if (c == '\b')
			ct = ct ? ct - 1 : 0;
		else
			ct++;
E 4
	}

/* Output last of the line */
D 3
	while ((c=getc(stdin))>0) {
E 3
I 3
	for (;;) {
		c = getc(stdin);
		if (feof(stdin))
			break;
E 3
D 4
		putc(c,stdout);
		if (c=='\n')
E 4
I 4
		putc(c, stdout);
		if (c == '\n')
E 4
			goto start;
	}
fin:
	fflush(stdout);
I 6
	exit(0);
E 6
}

getn(ap)
char *ap;
{
	register int n,c;
	register char *p;

	p = ap;
	n = 0;
	while ((c = *p++) >= '0' && c <= '9')
		n = n*10 + c - '0';
	return(n);
}
E 1
