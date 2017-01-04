h20875
s 00001/00001/00180
d D 5.2 85/10/21 17:52:42 karels 5 4
c don't quit if one file isn't readable
e
s 00008/00002/00173
d D 5.1 85/04/30 12:56:09 dist 4 3
c Add copyright
e
s 00022/00001/00153
d D 4.3 83/07/10 20:08:28 sam 3 2
c need different style reference name for intro sections
e
s 00076/00021/00078
d D 4.2 83/07/10 20:00:38 sam 2 1
c add -i for building intro sections
e
s 00099/00000/00000
d D 4.1 80/10/01 17:26:57 bill 1 0
c date and time created 80/10/01 17:26:57 by bill
e
u
U
t
T
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
I 2
#ifndef lint
E 2
I 1
D 4
static char *sccsid = "%W% (Berkeley) %G%";
I 2
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

/*
 * Get name sections from manual pages.
 *	-t	for building toc
 *	-i	for building intro entries
 *	other	apropos database
 */
#include <strings.h>
E 2
#include <stdio.h>

int tocrc;
I 2
int intro;
E 2

main(argc, argv)
	int argc;
	char *argv[];
{

	argc--, argv++;
	if (!strcmp(argv[0], "-t"))
		argc--, argv++, tocrc++;
I 2
	if (!strcmp(argv[0], "-i"))
		argc--, argv++, intro++;
E 2
	while (argc > 0)
		getfrom(*argv++), argc--;
	exit(0);
}

getfrom(name)
	char *name;
{
	char headbuf[BUFSIZ];
	char linbuf[BUFSIZ];
	register char *cp;
	int i = 0;

	if (freopen(name, "r", stdin) == 0) {
		perror(name);
D 5
		exit(1);
E 5
I 5
		return;
E 5
	}
	for (;;) {
		if (fgets(headbuf, sizeof headbuf, stdin) == NULL)
			return;
		if (headbuf[0] != '.')
			continue;
		if (headbuf[1] == 'T' && headbuf[2] == 'H')
			break;
		if (headbuf[1] == 't' && headbuf[2] == 'h')
			break;
	}
	for (;;) {
		if (fgets(linbuf, sizeof linbuf, stdin) == NULL)
			return;
		if (linbuf[0] != '.')
			continue;
		if (linbuf[1] == 'S' && linbuf[2] == 'H')
			break;
		if (linbuf[1] == 's' && linbuf[2] == 'h')
			break;
	}
	trimln(headbuf);
D 2
	if (tocrc) {
		register char *dp = name, *ep;

again:
		while (*dp && *dp != '.')
			putchar(*dp++);
		if (*dp)
			for (ep = dp+1; *ep; ep++)
				if (*ep == '.') {
					putchar(*dp++);
					goto again;
				}
		putchar('(');
		if (*dp)
			dp++;
		while (*dp)
			putchar (*dp++);
		putchar(')');
		putchar(' ');
	}
	printf("%s\t", headbuf);
E 2
I 2
	if (tocrc)
		doname(name);
	if (!intro)
		printf("%s\t", headbuf);
E 2
	for (;;) {
		if (fgets(linbuf, sizeof linbuf, stdin) == NULL)
			break;
		if (linbuf[0] == '.') {
			if (linbuf[1] == 'S' && linbuf[2] == 'H')
				break;
			if (linbuf[1] == 's' && linbuf[2] == 'h')
				break;
		}
		trimln(linbuf);
I 2
		if (intro) {
			split(linbuf, name);
			continue;
		}
E 2
		if (i != 0)
			printf(" ");
		i++;
		printf("%s", linbuf);
	}
	printf("\n");
}

trimln(cp)
	register char *cp;
{

	while (*cp)
		cp++;
	if (*--cp == '\n')
		*cp = 0;
I 2
}

doname(name)
	char *name;
{
	register char *dp = name, *ep;

again:
	while (*dp && *dp != '.')
		putchar(*dp++);
	if (*dp)
		for (ep = dp+1; *ep; ep++)
			if (*ep == '.') {
				putchar(*dp++);
				goto again;
			}
	putchar('(');
	if (*dp)
		dp++;
	while (*dp)
		putchar (*dp++);
	putchar(')');
	putchar(' ');
}

split(line, name)
	char *line, *name;
{
	register char *cp, *dp;
	char *sp, *sep;

	cp = index(line, '-');
	if (cp == 0)
		return;
	sp = cp + 1;
	for (--cp; *cp == ' ' || *cp == '\t' || *cp == '\\'; cp--)
		;
	*++cp = '\0';
	while (*sp && (*sp == ' ' || *sp == '\t'))
		sp++;
	for (sep = "", dp = line; dp && *dp; dp = cp, sep = "\n") {
		cp = index(dp, ',');
		if (cp) {
			register char *tp;

			for (tp = cp - 1; *tp == ' ' || *tp == '\t'; tp--)
				;
			*++tp = '\0';
			for (++cp; *cp == ' ' || *cp == '\t'; cp++)
				;
		}
		printf("%s%s\t", sep, dp);
D 3
		doname(name);
E 3
I 3
		dorefname(name);
E 3
		printf("\t%s", sp);
	}
I 3
}

dorefname(name)
	char *name;
{
	register char *dp = name, *ep;

again:
	while (*dp && *dp != '.')
		putchar(*dp++);
	if (*dp)
		for (ep = dp+1; *ep; ep++)
			if (*ep == '.') {
				putchar(*dp++);
				goto again;
			}
	putchar('.');
	if (*dp)
		dp++;
	while (*dp)
		putchar (*dp++);
E 3
E 2
}
E 1
