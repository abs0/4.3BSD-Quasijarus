h08154
s 00010/00005/00054
d D 5.3 88/06/30 18:00:02 bostic 4 3
c install approved copyright notice
e
s 00010/00004/00049
d D 5.2 88/05/05 18:08:17 bostic 3 2
c written by Ralph Campbell; add Berkeley specific header
e
s 00013/00001/00040
d D 5.1 85/06/06 10:05:50 dist 2 1
c Add copyright
e
s 00041/00000/00000
d D 4.1 83/10/14 11:28:40 ralph 1 0
c date and time created 83/10/14 11:28:40 by ralph
e
u
U
t
T
I 2
/*
 * Copyright (c) 1983 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
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
E 4
E 3
 */

E 2
I 1
#ifndef lint
I 2
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

#ifndef lint
E 2
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif
E 2
I 2
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3
E 2

/*
 * lptest -- line printer test program (and other devices).
 */

#include <stdio.h>

main(argc, argv)
	int argc;
	char **argv;
{
	int len, count;
	register i, j, fc, nc;
	char outbuf[BUFSIZ];

	setbuf(stdout, outbuf);
	if (argc >= 2)
		len = atoi(argv[1]);
	else
		len = 79;
	if (argc >= 3)
		count = atoi(argv[2]);
	else
		count = 200;
	fc = ' ';
	for (i = 0; i < count; i++) {
		if (++fc == 0177)
			fc = ' ';
		nc = fc;
		for (j = 0; j < len; j++) {
			putchar(nc);
			if (++nc == 0177)
				nc = ' ';
		}
		putchar('\n');
	}
	(void) fflush(stdout);
}
E 1
