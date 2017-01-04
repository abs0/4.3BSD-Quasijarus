h25495
s 00010/00005/00281
d D 5.3 88/06/30 17:53:35 bostic 10 9
c install approved copyright notice
e
s 00015/00003/00271
d D 5.2 88/03/08 08:30:22 bostic 9 8
c add Berkeley specific header
e
s 00007/00001/00267
d D 5.1 85/05/15 11:33:38 dist 8 7
c Add copyright notice
e
s 00046/00032/00222
d D 4.6 83/08/16 15:38:54 ralph 7 6
c fixes for indentation made by arch.
e
s 00004/00001/00250
d D 4.5 83/07/16 23:49:23 sam 6 5
c add useful sccs id's
e
s 00002/00002/00249
d D 4.4 83/05/16 17:21:58 ralph 5 4
c changes for px and py printcap entries.
e
s 00000/00012/00251
d D 4.3 83/04/29 11:52:40 ralph 4 3
c changes for new printer daemon.
e
s 00014/00004/00249
d D 4.2 83/03/17 15:46:54 ralph 3 1
c standardized signal handling
e
s 00014/00004/00249
d R 4.2 83/03/17 15:39:57 ralph 2 1
c 
e
s 00253/00000/00000
d D 4.1 83/03/07 14:58:50 ralph 1 0
c date and time created 83/03/07 14:58:50 by ralph
e
u
U
t
T
I 8
/*
 * Copyright (c) 1983 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */

E 8
I 1
D 6
/*	%M%	%I%	%E%	*/
E 6
I 6
#ifndef lint
I 9
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif
E 8
I 8
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9
E 8

E 6
/*
 * Versatec printer filter
 * 	make wide listings by placing pages side by side
 */

D 4
#include <signal.h>
E 4
#include <stdio.h>
D 3
#include <sgtty.h>
E 3
#include <sys/vcmd.h>

#define	LINELN 440
D 7
#define	PAGELN	86
#define	LMARG	10
E 7
I 7
#define	PAGELN  86
#define	LMARG   10
E 7

D 5
int	pltmode[] = {VPLOT, 0, 0};
int	prtmode[] = {VPRINT, 0, 0};
E 5
I 5
int	pltmode[] = {VPLOT};
int	prtmode[] = {VPRINT};
E 5

char	screen[PAGELN][LINELN];
char	ul[PAGELN][LINELN];
char	anyul[PAGELN];
D 7
int	origin;
int	outline;
int	outcol;
E 7
I 7
int	origin;		/* first column of a page */
int	origin_ind;	/* origin plus indent */
int	outline;	/* current line number */
int	outcol;		/* current column number */
E 7
int	npages;
D 7
int	width = 106;	/* page width */
int	length = 86;	/* page length */
E 7
I 7
int	width = 106;	/* default page width */
int	length = 86;	/* default page length */
int	indent = 0;	/* default indent */
E 7

int	literal;
char	*name;		/* user's login name */
char	*host;		/* user's machine name */
char	*acctfile;	/* accounting information file */

D 3
main(argc, argv)
int argc;
char *argv[];
E 3
I 3
D 4
onintr()
E 3
{
I 3
	signal(SIGTERM, SIG_IGN);
	exit(1);
}

E 4
D 7
main(argc, argv) 
E 7
I 7
main(argc, argv)
E 7
	int argc;
	char *argv[];
{
E 3
	register int i;
I 3
D 4

	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, onintr);
E 4
E 3

	while (--argc) {
		if (*(*++argv) == '-') {
			switch (argv[0][1]) {
			case 'n':
				argc--;
				name = *++argv;
				break;

			case 'h':
				argc--;
				host = *++argv;
				break;

			case 'w':
				if ((i = atoi(&argv[0][2])) > 0 && i <= LINELN)
					width = i;
				break;

			case 'l':
				if ((i = atoi(&argv[0][2])) > 0 && i <= PAGELN)
					length = i;
				break;

I 7
			case 'i':
				if ((i = atoi(&argv[0][2])) >= 0 &&
				    i < LINELN - 1)
					indent = i;
				break;

E 7
			case 'c':	/* Print input without throwing away
					   control chars and without putting
					   in page breaks. */
				literal++;
				break;
			}
		} else
			acctfile = *argv;
	}
I 7
	indent += literal ? 1 : LMARG;
	if (indent >= width)
		indent = width - 1;
E 7

	/*
	 * input file is open on file descriptor 0.
	 * vp should be open on file descriptor 1.
	 * The error log file is open on file descriptor 2.
	 */
	ioctl(1, VSETSTATE, prtmode);
	process();

	/*
	 * Put out an extra null to ensure versatec will get an even
	 * number of good characters.
	 */
	putchar('\0');

	if (ferror(stdout))
		exit(1);
	if (name && acctfile && access(acctfile, 02) >= 0 &&
	    freopen(acctfile, "a", stdout) != NULL) {
		if (host)
			printf("%7.2f\t%s:%s\n", (float)npages, host, name);
		else
			printf("%7.2f\t%s\n", (float)npages, name);
	}
	exit(0);
}

I 7
set_up()
{
	clear(screen, sizeof(screen));
	origin = 0;
	origin_ind = outcol = origin + indent;
	outline = 0;
	cutmark(origin);
}

E 7
process()
{
	register int c;

D 7
	clear(screen, sizeof(screen));
	origin = LMARG;
	outcol = LMARG;
	cutmark(LMARG);
E 7
I 7
	set_up();
E 7

	while ((c = getchar()) != EOF)
		switch (c) {
		case ' ':
			outcol++;
			break;

		case '\t':
D 7
			outcol = ((outcol - origin) | 07) + origin + 1;
E 7
I 7
			outcol = ((outcol - origin_ind) | 07) + origin_ind + 1;
E 7
			break;

		case '\b':
D 7
			if (outcol > origin)
E 7
I 7
			if (outcol > origin_ind)
E 7
				outcol--;
			break;

		case '\r':
D 7
			outcol = origin; 
E 7
I 7
			outcol = origin_ind;
E 7
			break;

		case '\f':
			outline = length;
			/* fall into ... */

		case '\n':
			if (++outline >= length) {
D 7
				origin += width;
				if (origin + width > LINELN) {
					cutmark(origin);
E 7
I 7
				origin += width + 1;
 				origin_ind += width + 1;
				cutmark(origin);
				if (origin + width + 1 >= LINELN) {
E 7
					oflush();
					break;
				}
				outline = 0;
D 7
				cutmark(origin);
E 7
			}
D 7
			outcol = origin;
E 7
I 7
			outcol = origin_ind;
E 7
			break;

		default:
			outchar(c);
			break;
		}

D 7
	if (outline || origin != LMARG) {
		cutmark(origin + width);
E 7
I 7
	if (outline || origin) {
		cutmark(origin + width + 1);
E 7
		oflush();
	}
	printf("\n\n\n\n\n");
}

outchar(c)
	register int c;
{
	register char *cp;
	register int d;

	if (!literal && (c < 040 || c >= 0177))
		return;
D 7
	if (outcol >= LINELN) {
E 7
I 7
	if (outcol >= origin + width + 1) {
E 7
		outcol++;
		return;
	}
	cp = &screen[outline][outcol];
	d = *cp;
	if (d != ' ') {
		if (d == '_' || c == '_') {
			if (c == d) {
				outcol++;
				return;
			}
			if (anyul[outline] == 0)
				clear(ul[outline], LINELN);
			anyul[outline] = 1;
			ul[outline][outcol] = 0377;
			if (c == '_')
				c = d;
		}
	}
	*cp = c;
	outcol++;
}

oflush()
{
	register char *cp, *dp;
	register int i, j, oc, dc, c;

	npages++;
	putchar('\n');
	for (i = 0; i < length; i++)
		putline(i);
	for (i = 0; i < LINELN; i++)
		putchar('_');
	putchar('\n');
D 7
	clear(screen, sizeof(screen));
	outline = 0;
	outcol = LMARG;
	origin = LMARG;
	cutmark(LMARG);
E 7
I 7

	set_up();
E 7
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

D 7
	screen[0][o - LMARG] = '|';
	screen[1][o - LMARG] = '|';
	screen[length - 1][o - LMARG] = '|';
	screen[length - 2][o - LMARG] = '|';
E 7
I 7
	screen[0][o] = '|';
	screen[1][o] = '|';
	screen[length - 1][o] = '|';
	screen[length - 2][o] = '|';
E 7
}

putline(n)
	register int n;
{
	register char *cp;
	register int j;

	fwrite(screen[n], sizeof(char), sizeof(screen[0]), stdout);
	if (anyul[n]) {
		putchar('\n');
		putchar('\0');
		fflush(stdout);
		ioctl(1, VSETSTATE, pltmode);
		cp = ul[n];
		j = LINELN;
		do {
			putchar(*cp & 0377);
			putchar(*cp++ & 0377);
		} while (--j);
		fflush(stdout);
		ioctl(1, VSETSTATE, prtmode);
	} else
		putchar('\n');
	if (ferror(stdout))
		exit(1);
}
E 1
