h46203
s 00015/00001/00118
d D 5.1 85/05/31 09:33:42 dist 5 4
c Add copyright
e
s 00006/00002/00113
d D 4.4 83/06/28 10:34:17 ralph 4 3
c only .so's at the beginning of a line are expanded now.
e
s 00011/00005/00104
d D 4.3 83/06/13 16:40:10 mckusick 3 2
c if can't open the file, just (effectively) echo the line.
e
s 00015/00007/00094
d D 4.2 82/09/16 16:24:20 mckusick 2 1
c peter's fixes to allow reading from standard input.
e
s 00101/00000/00000
d D 4.1 80/10/01 17:28:28 bill 1 0
c date and time created 80/10/01 17:28:28 by bill
e
u
U
t
T
I 1
D 5
static char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5
I 2

E 2
#include <stdio.h>
/*
 * soelim - a filter to process n/troff input eliminating .so's
 *
 * Author: Bill Joy UCB July 8, 1977
 *
 * This program eliminates .so's from a n/troff input stream.
 * It can be used to prepare safe input for submission to the
 * phototypesetter since the software supporting the operator
 * doesn't let him do chdir.
 *
 * This is a kludge and the operator should be given the
 * ability to do chdir.
 *
 * This program is more generally useful, it turns out, because
 * the program tbl doesn't understand ".so" directives.
 */
I 2
#define	STDIN_NAME	"-"
E 2

main(argc, argv)
	int argc;
	char *argv[];
{

	argc--;
	argv++;
	if (argc == 0) {
D 2
		fprintf(stderr, "Usage: %s file [ file ... ]\n", argv[-1]);
		exit(1);
E 2
I 2
D 3
		process(STDIN_NAME);
E 3
I 3
		(void)process(STDIN_NAME);
E 3
		exit(0);
E 2
	}
	do {
D 3
		process(argv[0]);
E 3
I 3
		(void)process(argv[0]);
E 3
		argv++;
		argc--;
	} while (argc > 0);
	exit(0);
}

D 3
process(file)
E 3
I 3
int process(file)
E 3
	char *file;
{
	register char *cp;
	register int c;
	char fname[BUFSIZ];
	FILE *soee;
I 3
	int isfile;
E 3

D 2
	soee = fopen(file, "r");
	if (soee == NULL) {
		perror(file);
		return;
E 2
I 2
	if (!strcmp(file, STDIN_NAME)) {
		soee = stdin;
	} else {
		soee = fopen(file, "r");
		if (soee == NULL) {
			perror(file);
D 3
			return;
E 3
I 3
			return(-1);
E 3
		}
E 2
	}
	for (;;) {
		c = getc(soee);
D 4
		if (c < 0)
E 4
I 4
		if (c == EOF)
E 4
			break;
		if (c != '.')
			goto simple;
		c = getc(soee);
		if (c != 's') {
			putchar('.');
			goto simple;
		}
		c = getc(soee);
		if (c != 'o') {
			printf(".s");
			goto simple;
		}
		do
			c = getc(soee);
		while (c == ' ' || c == '\t');
		cp = fname;
I 3
		isfile = 0;
E 3
		for (;;) {
			switch (c) {

			case ' ':
			case '\t':
			case '\n':
			case EOF:
				goto donename;

			default:
				*cp++ = c;
				c = getc(soee);
I 3
				isfile++;
E 3
				continue;
			}
		}
donename:
		if (cp == fname) {
			printf(".so");
			goto simple;
		}
D 4
		*cp++ = 0;
E 4
I 4
		*cp = 0;
E 4
D 3
		process(fname);
E 3
I 3
		if (process(fname) < 0)
			if (isfile)
				printf(".so %s\n", fname);
E 3
		continue;
simple:
		if (c == EOF)
			break;
		putchar(c);
I 4
		if (c != '\n') {
			c = getc(soee);
			goto simple;
		}
E 4
	}
D 2
	fclose(soee);
E 2
I 2
	if (soee != stdin) {
		fclose(soee);
	}
I 3
	return(0);
E 3
E 2
}
E 1
