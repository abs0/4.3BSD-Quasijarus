h52320
s 00010/00005/00047
d D 5.3 88/06/29 21:50:59 bostic 4 3
c install approved copyright notice
e
s 00029/00037/00023
d D 5.2 87/12/31 13:25:55 bostic 3 2
c add Berkeley header; exit after match of name; use library comparison 
c routine; use puts, not printf
e
s 00016/00001/00044
d D 5.1 85/05/31 09:24:06 dist 2 1
c Add copyright
e
s 00045/00000/00000
d D 4.1 80/10/02 10:58:08 bill 1 0
c date and time created 80/10/02 10:58:08 by bill
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
D 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * Copyright (c) 1987 Regents of the University of California.
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

#ifndef lint
char copyright[] =
D 3
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 3
I 3
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
E 3
 All rights reserved.\n";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

E 2
/*
 * printenv
 *
 * Bill Joy, UCB
 * February, 1979
 */
D 3

extern	char **environ;

E 3
main(argc, argv)
	int argc;
D 3
	char *argv[];
E 3
I 3
	char **argv;
E 3
{
D 3
	register char **ep;
	int found = 0;
E 3
I 3
	extern char **environ;
	register char *cp, **ep;
	register int len;
E 3

D 3
	argc--, argv++;
	if (environ)
E 3
I 3
	if (argc < 2) {
E 3
		for (ep = environ; *ep; ep++)
D 3
			if (argc == 0 || prefix(argv[0], *ep)) {
				register char *cp = *ep;

				found++;
				if (argc) {
					while (*cp && *cp != '=')
						cp++;
					if (*cp == '=')
						cp++;
				}
				printf("%s\n", cp);
E 3
I 3
			puts(*ep);
		exit(0);
	}
	len = strlen(*++argv);
	for (ep = environ; *ep; ep++)
		if (!strncmp(*ep, *argv, len)) {
			cp = *ep + len;
			if (!*cp || *cp == '=') {
				puts(*cp ? cp + 1 : cp);
				exit(0);
E 3
			}
D 3
	exit (!found);
}

prefix(cp, dp)
	char *cp, *dp;
{

	while (*cp && *dp && *cp == *dp)
		cp++, dp++;
	if (*cp == 0)
		return (*dp == '=');
	return (0);
E 3
I 3
		}
	exit(1);
E 3
}
E 1
