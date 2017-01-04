h17660
s 00003/00001/00094
d D 5.2 85/11/04 11:04:25 bloom 4 3
c add error if can't open requested mailbox
e
s 00015/00001/00080
d D 5.1 85/05/31 09:13:27 dist 3 2
c Add copyright
e
s 00007/00018/00074
d D 4.2 84/08/25 11:41:13 sam 2 1
c eliminate internal version of library func
e
s 00092/00000/00000
d D 4.1 80/10/01 17:26:50 bill 1 0
c date and time created 80/10/01 17:26:50 by bill
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
E 3
I 2

E 2
#include <stdio.h>
#include <ctype.h>
#include <pwd.h>

struct	passwd *getpwuid();

main(argc, argv)
D 2
int argc;
register char **argv;
E 2
I 2
	int argc;
	register char **argv;
E 2
{
	char lbuf[BUFSIZ];
	char lbuf2[BUFSIZ];
	register struct passwd *pp;
	int stashed = 0;
	register char *name;
	char *sender;
	char *getlogin();

	if (argc > 1 && *(argv[1]) == '-' && (*++argv)[1] == 's') {
		if (--argc <= 1) {
			fprintf (stderr, "Usage: from [-s sender] [user]\n");
			exit (1);
		}
		--argc;
		sender = *++argv;
		for (name = sender; *name; name++)
			if (isupper(*name))
				*name = tolower(*name);

D 2
	}
	else
E 2
I 2
	} else
E 2
		sender = NULL;
	if (chdir("/usr/spool/mail") < 0)
		exit(1);
	if (argc > 1)
		name = argv[1];
	else {
		name = getlogin ();
		if (name == NULL || strlen(name) == 0) {
			pp = getpwuid(getuid());
			if (pp == NULL) {
				fprintf(stderr, "Who are you?\n");
				exit(1);
			}
			name = pp->pw_name;
		}
	}
D 4
	if (freopen(name, "r", stdin) == NULL)
E 4
I 4
	if (freopen(name, "r", stdin) == NULL) {
		fprintf(stderr, "Can't open /usr/spool/mail/%s\n", name);
E 4
		exit(0);
I 4
	}
E 4
D 2
	while(fgets(lbuf, sizeof lbuf, stdin) != NULL)
E 2
I 2
	while (fgets(lbuf, sizeof lbuf, stdin) != NULL)
E 2
		if (lbuf[0] == '\n' && stashed) {
			stashed = 0;
			printf("%s", lbuf2);
D 2
		}
		else if (bufcmp(lbuf, "From ", 5) &&
E 2
I 2
		} else if (strncmp(lbuf, "From ", 5) == 0 &&
E 2
		    (sender == NULL || match(&lbuf[4], sender))) {
			strcpy(lbuf2, lbuf);
			stashed = 1;
		}
	if (stashed)
		printf("%s", lbuf2);
	exit(0);
}

D 2
bufcmp (b1, b2, n)
register char *b1, *b2;
register int n;
{
	while (n-- > 0)
		if (*b1++ != *b2++)
			return (0);
	return (1);
}

E 2
match (line, str)
D 2
register char *line, *str;
E 2
I 2
	register char *line, *str;
E 2
{
	register char ch;

	while (*line == ' ' || *line == '\t')
		++line;
	if (*line == '\n')
		return (0);
	while (*str && *line != ' ' && *line != '\t' && *line != '\n') {
		ch = isupper(*line) ? tolower(*line) : *line;
		if (ch != *str++)
			return (0);
		line++;
	}
	return (*str == '\0');
}
E 1
