h36701
s 00010/00005/00068
d D 5.4 88/06/29 21:50:45 bostic 6 5
c install approved copyright notice
e
s 00010/00004/00063
d D 5.3 88/04/19 19:20:27 bostic 5 4
c add Berkeley specific copyright
e
s 00041/00064/00026
d D 5.2 87/11/14 14:30:40 bostic 4 3
c standardize error messages; don't close and then freopen stdin; 
c don't flush stdout after every line; use C library atoi; don't limit line 
c length; do lint cleanup
e
s 00016/00001/00074
d D 5.1 85/05/31 09:17:05 dist 3 2
c Add copyright
e
s 00000/00002/00075
d D 4.2 84/09/17 10:46:26 ralph 2 1
c don't call setbuf.
e
s 00077/00000/00000
d D 4.1 80/10/01 17:27:05 bill 1 0
c date and time created 80/10/01 17:27:05 by bill
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
D 4
 * Copyright (c) 1980 Regents of the University of California.
E 4
I 4
 * Copyright (c) 1980, 1987 Regents of the University of California.
E 4
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
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

#ifndef lint
char copyright[] =
D 4
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 4
I 4
"%Z% Copyright (c) 1980, 1987 Regents of the University of California.\n\
E 4
 All rights reserved.\n";
D 4
#endif not lint
E 4
I 4
D 5
#endif /* !lint */
E 5
I 5
#endif /* not lint */
E 5
E 4

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
D 5
#endif /* !lint */
E 5
I 5
#endif /* not lint */
E 5
E 4

E 3
#include <stdio.h>
I 4
#include <ctype.h>
E 4
/*
 * head - give the first few lines of a stream or of each of a set of files
 *
 * Bill Joy UCB August 24, 1977
 */

D 4
int	linecnt	= 10;
int	argc;

main(Argc, argv)
	int Argc;
	char *argv[];
E 4
I 4
main(argc, argv)
	int	argc;
	char	**argv;
E 4
{
D 4
	register int argc;
	char *name;
	register char *argp;
	static int around;
E 4
I 4
	register int	ch, cnt;
	int	firsttime, linecnt = 10;
E 4
D 2
	char obuf[BUFSIZ];
E 2

D 2
	setbuf(stdout, obuf);
E 2
D 4
	Argc--, argv++;
	argc = Argc;
	do {
		while (argc > 0 && argv[0][0] == '-') {
			linecnt = getnum(argv[0] + 1);
			argc--, argv++, Argc--;
E 4
I 4
	if (argc > 1 && argv[1][0] == '-') {
		if (!isdigit(argv[1][1])) {
			fprintf(stderr, "head: illegal option -- %c\n", argv[1][1]);
			goto usage;
E 4
		}
D 4
		if (argc == 0 && around)
			break;
		if (argc > 0) {
			close(0);
			if (freopen(argv[0], "r", stdin) == NULL) {
				perror(argv[0]);
E 4
I 4
		if ((linecnt = atoi(argv[1] + 1)) < 0) {
usage:			fputs("usage: head [-line_count] [file ...]\n", stderr);
			exit(1);
		}
		--argc; ++argv;
	}
	/* setlinebuf(stdout); */
	for (firsttime = 1, --argc, ++argv;; firsttime = 0) {
		if (!*argv) {
			if (!firsttime)
				exit(0);
		}
		else {
			if (!freopen(*argv, "r", stdin)) {
				fprintf(stderr, "head: can't read %s.\n", *argv);
E 4
				exit(1);
			}
D 4
			name = argv[0];
			argc--, argv++;
		} else
			name = 0;
		if (around)
			putchar('\n');
		around++;
		if (Argc > 1 && name)
			printf("==> %s <==\n", name);
		copyout(linecnt);
		fflush(stdout);
	} while (argc > 0);
}

copyout(cnt)
	register int cnt;
{
	register int c;
	char lbuf[BUFSIZ];

	while (cnt > 0 && fgets(lbuf, sizeof lbuf, stdin) != 0) {
		printf("%s", lbuf);
		fflush(stdout);
		cnt--;
E 4
I 4
			if (argc > 1) {
				if (!firsttime)
					putchar('\n');
				printf("==> %s <==\n", *argv);
			}
			++argv;
		}
		for (cnt = linecnt; cnt; --cnt)
			while ((ch = getchar()) != EOF)
				if (putchar(ch) == '\n')
					break;
E 4
	}
D 4
}

getnum(cp)
	register char *cp;
{
	register int i;

	for (i = 0; *cp >= '0' && *cp <= '9'; cp++)
		i *= 10, i += *cp - '0';
	if (*cp) {
		fprintf(stderr, "Badly formed number\n");
		exit(1);
	}
	return (i);
E 4
I 4
	/*NOTREACHED*/
E 4
}
E 1
