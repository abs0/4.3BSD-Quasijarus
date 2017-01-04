h06930
s 00021/00008/00048
d D 5.2 04/10/05 04:07:36 msokolov 2 1
c convert a few KOI8-E characters too
e
s 00056/00000/00000
d D 5.1 04/10/05 03:29:48 msokolov 1 0
c date and time created 04/10/05 03:29:48 by msokolov
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
u_char xlatbl[96] = {
	' ',  0,    0,    0xF1, 0,    0,    0,    0,
	0,    0,    0,    0,    0,    '-',  0,    0,
	'N',  0,    0,    0xF0, 0,    0,    0,    0,
	0,    0,    0,    0,    0,    '$',  0,    0,
E 2
	0xEE, 0xA0, 0xA1, 0xE6, 0xA4, 0xA5, 0xE4, 0xA3,
	0xE5, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE,
	0xAF, 0xEF, 0xE0, 0xE1, 0xE2, 0xE3, 0xA6, 0xA2,
	0xEC, 0xEB, 0xA7, 0xE8, 0xED, 0xE9, 0xE7, 0xEA,
	0x9E, 0x80, 0x81, 0x96, 0x84, 0x85, 0x94, 0x83,
	0x95, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E,
	0x8F, 0x9F, 0x90, 0x91, 0x92, 0x93, 0x86, 0x82,
	0x9C, 0x9B, 0x87, 0x98, 0x9D, 0x99, 0x97, 0x9A};

main(argc, argv)
	char **argv;
{
	register int ch;
D 2
	int badch = 0;
E 2
I 2
	int badch = 0, c1 = 0;
E 2

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
			if (ch == '\n')
				putchar('\r');
			putchar(ch);
D 2
		} else if (ch >= 0xC0)
			putchar(xlatbl[ch-0xC0]);
		else
			badch++;
E 2
I 2
		} else if (ch >= 0xA0) {
			ch = xlatbl[ch-0xA0];
			if (ch)
				putchar(ch);
			else
				badch++;
		} else
			c1++;
E 2
	}
I 2

E 2
	if (badch)
		fprintf(stderr,
D 2
			"%s: %s: %d high characters could not be converted\n",
E 2
I 2
			"%s: %s: %d KOI8-E characters could not be converted\n",
E 2
			argv[0], argc >= 2 ? argv[1] : "stdin", badch);
D 2
	return(badch != 0);
E 2
I 2
	if (c1)
		fprintf(stderr,
			"%s: %s: %d C1 characters could not be converted\n",
			argv[0], argc >= 2 ? argv[1] : "stdin", c1);
	return(badch != 0 || c1 != 0);
E 2
}
E 1
