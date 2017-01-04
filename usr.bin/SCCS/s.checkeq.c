h57327
s 00017/00001/00085
d D 4.3 87/12/02 16:38:26 bostic 3 2
c bug report 4.3BSD/usr.bin/108; exit 0 on success
e
s 00001/00001/00085
d D 4.2 83/04/29 01:46:33 mckusick 2 1
c added perror
e
s 00086/00000/00000
d D 4.1 80/10/01 17:25:18 bill 1 0
c date and time created 80/10/01 17:25:18 by bill
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
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */

E 3
#include <stdio.h>
FILE	*fin;
int	delim	= '$';

main(argc, argv) char **argv; {

	if (argc <= 1)
		check(stdin);
	else
		while (--argc > 0) {
			if ((fin = fopen(*++argv, "r")) == NULL) {
D 2
				printf("Can't open %s\n", *argv);
E 2
I 2
				perror(*argv);
E 2
				exit(1);
			}
			printf("%s:\n", *argv);
			check(fin);
			fclose(fin);
		}
I 3
	exit(0);
E 3
}

check(f)
FILE	*f;
{
	int start, line, eq, ndel, totdel;
	char in[600], *p;

	start = eq = line = ndel = totdel = 0;
	while (fgets(in, 600, f) != NULL) {
		line++;
		ndel = 0;
		for (p = in; *p; p++)
			if (*p == delim)
				ndel++;
		if (*in=='.' && *(in+1)=='E' && *(in+2)=='Q') {
			if (eq++)
				printf("   Spurious EQ, line %d\n", line);
			if (totdel)
				printf("   EQ in %c%c, line %d\n", delim, delim, line);
		} else if (*in=='.' && *(in+1)=='E' && *(in+2)=='N') {
			if (eq==0)
				printf("   Spurious EN, line %d\n", line);
			else
				eq = 0;
			if (totdel > 0)
				printf("   EN in %c%c, line %d\n", delim, delim, line);
			start = 0;
		} else if (eq && *in=='d' && *(in+1)=='e' && *(in+2)=='l' && *(in+3)=='i' && *(in+4)=='m') {
			for (p=in+5; *p; p++)
				if (*p != ' ') {
					if (*p == 'o' && *(p+1) == 'f')
						delim = 0;
					else
						delim = *p;
					break;
				}
			if (delim == 0)
				printf("   Delim off, line %d\n", line);
			else
				printf("   New delims %c%c, line %d\n", delim, delim, line);
		}
		if (ndel > 0 && eq > 0)
			printf("   %c%c in EQ, line %d\n", delim, delim, line);
		if (ndel == 0)
			continue;
		totdel += ndel;
		if (totdel%2) {
			if (start == 0)
				start = line;
			else {
				printf("   %d line %c%c, lines %d-%d\n", line-start+1, delim, delim, start, line);
				start = line;
			}
		} else {
			if (start > 0) {
				printf("   %d line %c%c, lines %d-%d\n", line-start+1, delim, delim, start, line);
				start = 0;
			}
			totdel = 0;
		}
	}
	if (totdel)
		printf("   Unfinished %c%c\n", delim, delim);
	if (eq)
		printf("   Unfinished EQ\n");
}
E 1
