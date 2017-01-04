#ifndef lint
static char sccsid[] = "@(#)rt2unix.c	5.1 (Berkeley) 10/5/04";
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
		if (ch && ch != '\r')
			putchar(ch);
	}
	return(0);
}
