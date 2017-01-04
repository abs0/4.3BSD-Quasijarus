h10919
s 00011/00005/00065
d D 5.4 88/06/29 22:00:48 bostic 4 3
c install approved copyright notice
e
s 00050/00022/00020
d D 5.3 88/04/21 17:01:39 bostic 3 2
c bring it up to date
e
s 00001/00001/00041
d D 5.2 87/04/06 14:43:02 bostic 2 1
c print format/argument mismatch
e
s 00042/00000/00000
d D 5.1 87/04/06 14:41:49 bostic 1 0
c date and time created 87/04/06 14:41:49 by bostic
e
u
U
t
T
I 1
D 3
# include "sendmail.h"
E 3
I 3
/*
I 4
 * Copyright (c) 1983 Eric P. Allman
E 4
 * Copyright (c) 1988 Regents of the University of California.
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
 */
E 3

D 3
static	char sccsid[] = "%W%	%G%";
E 3
I 3
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1988 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */
E 3

D 3
typedef struct { char *dptr; int dsize; } datum;
datum	firstkey(), nextkey(), fetch();
char	*filename = ALIASFILE;
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 3

I 3
#include <sendmail.h>

typedef struct {
	char *dptr;
	int dsize;
} datum;


E 3
main(argc, argv)
	char **argv;
{
D 3
	datum content, key;
E 3
I 3
	extern char *optarg;
	extern int optind;
	static char *filename = "/usr/lib/aliases";
	datum content, key, firstkey(), nextkey(), fetch();
	int ch;
E 3

D 3
	if (argc > 2 && strcmp(argv[1], "-f") == 0)
	{
		argv++;
		filename = *++argv;
		argc -= 2;
	}
E 3
I 3
	while ((ch = getopt(argc, argv, "f:")) != EOF)
		switch((char)ch) {
		case 'f':
			filename = optarg;
			break;
		case '?':
		default:
			fputs("usage: praliases [-f file]\n", stderr);
			exit(EX_USAGE);
		}
	argc -= optind;
	argv += optind;
E 3

	if (dbminit(filename) < 0)
		exit(EX_OSFILE);
D 3
	argc--, argv++;
	if (argc == 0) {
E 3
I 3
	if (!argc)
E 3
		for (key = firstkey(); key.dptr; key = nextkey(key)) {
			content = fetch(key);
D 3
			printf("\n%s:%s\n", key.dptr, content.dptr);
E 3
I 3
			printf("%s:%s\n", key.dptr, content.dptr);
E 3
		}
D 3
		exit(EX_OK);
	}
	while (argc) {
E 3
I 3
	else for (; *argv; ++argv) {
E 3
		key.dptr = *argv;
D 3
		key.dsize = strlen(*argv)+1;
E 3
I 3
		key.dsize = strlen(*argv) + 1;
E 3
		content = fetch(key);
D 3
		if (content.dptr == 0)
E 3
I 3
		if (!content.dptr)
E 3
D 2
			printf("%s: No such key\n");
E 2
I 2
			printf("%s: No such key\n", key.dptr);
E 2
		else
D 3
			printf("\n%s:%s\n", key.dptr, content.dptr);
		argc--, argv++;
E 3
I 3
			printf("%s:%s\n", key.dptr, content.dptr);
E 3
	}
	exit(EX_OK);
}
E 1
