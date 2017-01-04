h12007
s 00010/00005/00249
d D 1.4 88/06/30 17:53:22 bostic 4 3
c install approved copyright notice
e
s 00010/00004/00244
d D 1.3 88/03/08 08:30:08 bostic 3 2
c add Berkeley specific header
e
s 00016/00000/00232
d D 1.2 87/11/04 20:41:37 bostic 2 1
c add copyright notice
e
s 00232/00000/00000
d D 1.1 80/11/30 15:56:16 root 1 0
c date and time created 80/11/30 15:56:16 by root
e
u
U
t
T
I 2
/*
 * Copyright (c) 1987 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 4
E 3
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

E 2
I 1
#include <stdio.h>
/*
 * sidebyside -- make wide listings by placing pages side by side
 */
int	width = 90;

#define	LINELN 440
#define	EJLINE	86
#define	LMARG	10

char	screen[EJLINE][LINELN];
char	ul[EJLINE][LINELN];
char	anyul[EJLINE];
int	frame;
int	origin;
int	outline;
int	outcol;

main(argc, argv)
	int argc;
	char *argv[];
{

	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		switch (argv[0][1]) {

		case 'w':
			width = atoi(argv[0]+2);
			break;
		
		default:
			fprintf(stderr, "usage: sidebyside [ -wwidth ] file ...\n");
			break;
		}
		argc--, argv++;
	}
	clear(screen, EJLINE * LINELN);
	origin = LMARG;
	outcol = LMARG;
	cutmark(LMARG);
	do {
		if (argc > 0) {
			if (freopen(argv[0], "r", stdin) == NULL) {
				perror(argv[0]);
				argc--, argv++;
				continue;
			}
			argc--, argv++;
		}
		process();
	} while (argc > 0);
	exit(0);
}

process()
{
	char linebuf[BUFSIZ];
	register char *cp;
	register int c;

	while (fgets(linebuf, sizeof linebuf, stdin)) {
		for (cp = linebuf; c = *cp; cp++) switch (c) {

		case '\t':
			do {
				int ooutcol = outcol;
				outchar(' ');
				if (outcol == ooutcol)
					break;
			} while ((outcol - origin) % 8 != 0);
			break;

		case '\b':
			if (outcol > origin)
				outcol--;
			break;

		case '\r':
			outcol = origin + LMARG; 
			break;

		case '\f':
			outline = EJLINE - 1;
			/* fall into ... */

		case '\n':
			outline++;
			if (outline == EJLINE) {
				origin += width;
				if (origin + width > LINELN) {
					cutmark(origin);
					oflush();
					break;
				}
/*
				if (origin * 2 + LMARG < LINELN && origin * 3 > LINELN) {
					cutmark(origin);
					origin += LMARG;
				}
*/
				outline = 0;
				cutmark(origin);
			}
			outcol = origin;
			break;

		default:
			outchar(c);
			break;
		}
	}
	if (outline || origin != LMARG) {
		cutmark(origin + width);
		oflush();
	}
}

outchar(c)
	register int c;
{
	register char *cp = screen[outline];
	register char *up;
	register int d;

	if (c < 040 || c >= 0177)
		return;
	if (outcol < LINELN) {
		cp += outcol;
		d = *cp;
		if (d == ' ') {
			*cp = c;
			outcol++;
			return;
		}
		if (d == '_' || c == '_') {
			if (c == d) {
				outcol++;
				return;
			}
			if (anyul[outline] == 0)
				clear(ul[outline], LINELN);
			anyul[outline] = 1;
			ul[outline][outcol] = '_';
			if (c == '_')
				c = d;
		}
		*cp = c;
		outcol++;
	}
}

oflush()
{
	register char *cp, *dp;
	register int i, j, oc, dc, c;

	frame++;
/*
	if (frame > 1) {
		printf("\n\n\n");
		for (j = 0; j < LINELN; j++)
			putchar('_');
		printf("\n");
	}
*/
	printf("\n");
	for (i = 0; i < EJLINE; i++) {
		putline(screen[i]);
		if (anyul[i]) {
			putchar('\r');
			putline(ul[i]);
			anyul[i] = 0;
		}
		putchar('\n');
	}
	for (i = 0; i < LINELN; i++)
		putchar('_');
	putchar('\n');
	clear(screen, EJLINE * LINELN);
	outline = 0;
	outcol = LMARG;
	origin = LMARG;
	cutmark(LMARG);
}

clear(cp, i)
	register char *cp;
	register int i;
{

	if (i > 0)
		do
			*cp++ = ' ';
		while (--i);
}

cutmark(o)
	register int o;
{
	register int i;

	screen[0][o - LMARG] = '|';
	screen[1][o - LMARG] = '|';
	screen[EJLINE - 1][o - LMARG] = '|';
	screen[EJLINE - 2][o - LMARG] = '|';
}

putline(cp)
	register char *cp;
{
	register int j = LINELN;
	register int c, oc, dc;

	oc = dc = 0;
	do {
		if ((c = *cp++) == ' ') {
			dc++;
			continue;
		}
		while (((oc + 8) &~ 7) < dc) {
			putchar('\t');
			oc = (oc + 8) &~ 7;
		}
		while (oc < dc) {
			putchar(' ');
			oc++;
		}
		putchar(c);
		oc++, dc++;
	} while (--j != 0);
}
E 1
