h41245
s 00010/00005/00043
d D 4.5 88/06/29 21:54:27 bostic 5 4
c install approved copyright notice
e
s 00025/00022/00023
d D 4.4 87/12/05 18:23:08 bostic 4 3
c bug report usr.bin/118; rewrote, now Berkeley code
e
s 00018/00004/00027
d D 4.3 87/12/02 16:10:53 bostic 3 2
c bug report 4.3BSD/usr.bin/106; handle 1st arg as suffix of 2nd arg 
c new header
e
s 00002/00001/00029
d D 4.2 82/10/20 16:30:14 mckusick 2 1
c use <> for standard include files
e
s 00030/00000/00000
d D 4.1 80/10/01 17:25:06 bill 1 0
c date and time created 80/10/01 17:25:06 by bill
e
u
U
t
T
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
/*
 * Copyright (c) 1987 Regents of the University of California.
D 4
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
I 4
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
E 3
D 2
#include	"stdio.h"
E 2
I 2

D 3
#include	<stdio.h>
E 3
I 3
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */
E 3
E 2

I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

D 4
#include <stdio.h>

E 4
E 3
main(argc, argv)
D 4
char **argv;
E 4
I 4
	int argc;
	char **argv;
E 4
{
D 4
	register char *p1, *p2, *p3;
E 4
I 4
	register char *p, *t;
	char *base;
E 4

D 4
	if (argc < 2) {
E 4
I 4
	if (argc <= 1) {	/* backward compatible */
E 4
		putchar('\n');
		exit(1);
	}
D 4
	p1 = argv[1];
	p2 = p1;
	while (*p1) {
		if (*p1++ == '/')
			p2 = p1;
E 4
I 4
	for (p = base = *++argv; *p;)
		if (*p++ == '/')
			base = p;
	if (argc > 2) {		/* original version allows any # of args */
		for (t = *++argv; *t; ++t);
		do {
			if (t == *argv) {
				*p = '\0';
				break;
			}
		} while (p >= base && *--t == *--p);
E 4
	}
D 4
	if (argc>2) {
		for(p3=argv[2]; *p3; p3++) 
			;
D 3
		while(p1>p2 && p3>argv[2])
			if(*--p3 != *--p1)
E 3
I 3
		while(p3>argv[2])
			if(p1 <= p2 || *--p3 != *--p1)
E 3
				goto output;
		*p1 = '\0';
	}
output:
	puts(p2, stdout);
E 4
I 4
	puts(base);
E 4
	exit(0);
}
E 1
