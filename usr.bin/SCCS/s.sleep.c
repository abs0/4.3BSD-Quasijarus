h52919
s 00010/00005/00033
d D 5.3 88/06/29 21:54:33 bostic 3 2
c install approved copyright notice
e
s 00033/00017/00005
d D 5.2 88/06/06 15:58:18 bostic 2 1
c rewrite and add Berkeley specific header; atoi is in the C library
c yank to rev. level 5
e
s 00022/00000/00000
d D 4.1 80/10/01 17:28:26 bill 1 0
c date and time created 80/10/01 17:28:26 by bill
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
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

#include <stdio.h>

E 2
main(argc, argv)
D 2
char **argv;
E 2
I 2
	int argc;
	char **argv;
E 2
{
D 2
	int c, n;
	char *s;
E 2
I 2
	int secs;
E 2

D 2
	n = 0;
	if(argc < 2) {
		printf("arg count\n");
		exit(0);
E 2
I 2
	if (argc != 2) {
		fputs("usage: sleep time\n", stderr);
		exit(1);
E 2
	}
D 2
	s = argv[1];
	while(c = *s++) {
		if(c<'0' || c>'9') {
			printf("bad character\n");
			exit(0);
		}
		n = n*10 + c - '0';
	}
	sleep(n);
E 2
I 2
	if ((secs = atoi(argv[1])) > 0)
		(void)sleep(secs);
	exit(0);
E 2
}
E 1
