h00320
s 00018/00008/00050
d D 5.2 04/10/05 04:12:15 msokolov 2 1
c convert Russian IO too
e
s 00058/00000/00000
d D 5.1 04/10/05 03:34:34 msokolov 1 0
c date and time created 04/10/05 03:34:34 by msokolov
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <sys/param.h>
#include <stdio.h>

D 2
u_char xlatbl[64] = {
E 2
I 2
u_char xlatbl[128] = {
E 2
	0xE1, 0xE2, 0xF7, 0xE7, 0xE4, 0xE5, 0xF6, 0xFA,
	0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0,
	0xF2, 0xF3, 0xF4, 0xF5, 0xE6, 0xE8, 0xE3, 0xFE,
	0xFB, 0xFD, 0xFF, 0xF9, 0xF8, 0xFC, 0xE0, 0xF1,
	0xC1, 0xC2, 0xD7, 0xC7, 0xC4, 0xC5, 0xD6, 0xDA,
	0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0,
I 2
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0,
E 2
	0xD2, 0xD3, 0xD4, 0xD5, 0xC6, 0xC8, 0xC3, 0xDE,
D 2
	0xDB, 0xDD, 0xDF, 0xD9, 0xD8, 0xDC, 0xC0, 0xD1};
E 2
I 2
	0xDB, 0xDD, 0xDF, 0xD9, 0xD8, 0xDC, 0xC0, 0xD1,
	0xB3, 0xA3, 0,    0,    0,    0,    0,    0,
	0,    0,    0,    0,    0,    0,    0,    0};
E 2

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
D 2
		} else if (ch >= 0x80 && ch <= 0xAF)
			putchar(xlatbl[ch-0x80]);
		else if (ch >= 0xE0 && ch <= 0xEF)
			putchar(xlatbl[ch-0xB0]);
		else
			badch++;
E 2
I 2
		} else {
			ch = xlatbl[ch-0x80];
			if (ch)
				putchar(ch);
			else
				badch++;
		}
E 2
	}
I 2

E 2
	if (badch)
		fprintf(stderr,
			"%s: %s: %d high characters could not be converted\n",
			argv[0], argc >= 2 ? argv[1] : "stdin", badch);
	return(badch != 0);
}
E 1
