#ifndef lint
static char sccsid[] = "@(#)rusdos2unix.c	5.2 (Berkeley) 10/5/04";
#endif

#include <sys/param.h>
#include <stdio.h>

u_char xlatbl[128] = {
	0xE1, 0xE2, 0xF7, 0xE7, 0xE4, 0xE5, 0xF6, 0xFA,
	0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0,
	0xF2, 0xF3, 0xF4, 0xF5, 0xE6, 0xE8, 0xE3, 0xFE,
	0xFB, 0xFD, 0xFF, 0xF9, 0xF8, 0xFC, 0xE0, 0xF1,
	0xC1, 0xC2, 0xD7, 0xC7, 0xC4, 0xC5, 0xD6, 0xDA,
	0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0xD2, 0xD3, 0xD4, 0xD5, 0xC6, 0xC8, 0xC3, 0xDE,
	0xDB, 0xDD, 0xDF, 0xD9, 0xD8, 0xDC, 0xC0, 0xD1,
	0xB3, 0xA3, 0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0};

main(argc, argv)
	char **argv;
{
	register int ch;
	int badch = 0;

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
		if (ch <= 0x7F) {
			if (ch == '\r')
				continue;
			putchar(ch);
		} else {
			ch = xlatbl[ch-0x80];
			if (ch)
				putchar(ch);
			else
				badch++;
		}
	}

	if (badch)
		fprintf(stderr,
			"%s: %s: %d high characters could not be converted\n",
			argv[0], argc >= 2 ? argv[1] : "stdin", badch);
	return(badch != 0);
}
