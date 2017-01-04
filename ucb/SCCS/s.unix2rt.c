h47498
s 00035/00000/00000
d D 5.1 04/10/05 03:04:17 msokolov 1 0
c date and time created 04/10/05 03:04:17 by msokolov
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>

main(argc, argv)
	char **argv;
{
	register int ch;

	if (argc > 3) {
		fprintf(stderr, "usage: %s [infile [outfile]]\n", argv[0]);
		exit(1);
	}
	if (argc > 1) {
		if (freopen(argv[1], "r", stdin) == NULL) {
			perror(argv[1]);
			exit(1);
		}
	}
	if (argc > 2) {
		if (freopen(argv[2], "w", stdout) == NULL) {
			perror(argv[2]);
			exit(1);
		}
	}

	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			putchar('\r');
		putchar(ch);
	}
	return(0);
}
E 1
