h04143
s 00053/00000/00000
d D 5.1 05/09/16 04:44:51 msokolov 1 0
c adopted for Quasijarus
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %E%";
#endif

#include <stdio.h>
#include <ctype.h>
#include <strings.h>

main(argc, argv)
	char **argv;
{
	char line[1024];
	register char *cp, *np;

	if (argc >= 2 && !freopen(argv[1], "r", stdin)) {
		perror(argv[1]);
		exit(1);
	}
	if (argc >= 3 && !freopen(argv[2], "w", stdout)) {
		perror(argv[2]);
		exit(1);
	}
	while (fgets(line, sizeof line, stdin)) {
		if (strncmp(line, "%%IncludeFile:", 14))
			fputs(line, stdout);
		else {
			cp = line + 14;
			while (isspace(*cp))
				cp++;
			for (np = cp; *cp && !isspace(*cp); cp++)
				;
			*cp = '\0';
			includefile(np);
		}
	}
	exit(0);
}

includefile(filename)
	char *filename;
{
	register FILE *f;
	register int c;

	f = fopen(filename, "r");
	if (!f) {
		perror(filename);
		exit(1);
	}
	while ((c = getc(f)) != EOF)
		putchar(c);
	fclose(f);
}
E 1
