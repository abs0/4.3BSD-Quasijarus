h28981
s 00010/00005/00082
d D 5.4 88/06/18 19:55:36 bostic 7 6
c install approved copyright notice
e
s 00000/00002/00087
d D 5.3 88/04/04 20:44:16 bostic 6 5
c remove sobuf construct
e
s 00011/00005/00078
d D 5.2 88/03/09 12:24:41 bostic 5 4
c written by David Riggle and Edward Wang; add Berkeley specific copyright
e
s 00011/00005/00072
d D 5.1 85/05/29 16:04:15 dist 4 3
c Add copyright
e
s 00006/00000/00071
d D 2.3 85/04/23 21:53:36 edward 3 2
c copyright message
e
s 00003/00000/00068
d D 2.2 85/04/22 01:48:15 edward 2 1
c -b flag for no bells
e
s 00068/00000/00000
d D 2.1 85/03/04 18:08:52 edward 1 0
c date and time created 85/03/04 18:08:52 by edward
e
u
U
t
T
I 3
/*
D 4
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 4
I 4
 * Copyright (c) 1983 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
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
E 5
E 4
 */

E 3
I 1
#ifndef lint
D 4
static	char *sccsid = "%W% %E%";
#endif
E 4
I 4
char copyright[] =
D 5
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 5
I 5
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 5
 All rights reserved.\n";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5
E 4

#include "externs.h"

/*ARGSUSED*/
main(argc, argv)
	int argc;
	register char **argv;
{
	register char *p;
	int i;
D 6
	extern char _sobuf[];
E 6

D 6
	setbuf(stdout, _sobuf);
E 6
	(void) srand(getpid());
	issetuid = getuid() != geteuid();
	if (p = rindex(*argv, '/'))
		p++;
	else
		p = *argv;
	if (strcmp(p, "driver") == 0 || strcmp(p, "saildriver") == 0)
		mode = MODE_DRIVER;
	else if (strcmp(p, "sail.log") == 0)
		mode = MODE_LOGGER;
	else
		mode = MODE_PLAYER;
	while ((p = *++argv) && *p == '-')
		switch (p[1]) {
		case 'd':
			mode = MODE_DRIVER;
			break;
		case 's':
			mode = MODE_LOGGER;
			break;
		case 'D':
			debug++;
			break;
		case 'x':
			randomize;
			break;
		case 'l':
			longfmt++;
			break;
I 2
		case 'b':
			nobells++;
			break;
E 2
		default:
			fprintf(stderr, "SAIL: Unknown flag %s.\n", p);
			exit(1);
		}
	if (*argv)
		game = atoi(*argv);
	else
		game = -1;
	if (i = setjmp(restart))
		mode = i;
	switch (mode) {
	case MODE_PLAYER:
		return pl_main();
	case MODE_DRIVER:
		return dr_main();
	case MODE_LOGGER:
		return lo_main();
	default:
		fprintf(stderr, "SAIL: Unknown mode %d.\n", mode);
		abort();
	}
	/*NOTREACHED*/
}
E 1
