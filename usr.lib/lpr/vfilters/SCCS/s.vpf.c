h48851
s 00010/00005/00245
d D 5.3 88/06/30 17:53:30 bostic 14 13
c install approved copyright notice
e
s 00015/00003/00235
d D 5.2 88/03/08 08:30:17 bostic 13 12
c add Berkeley specific header
e
s 00007/00001/00231
d D 5.1 85/05/15 11:33:21 dist 12 11
c Add copyright notice
e
s 00009/00002/00223
d D 4.8 83/08/16 15:38:49 ralph 11 10
c fixes for indentation made by arch.
e
s 00004/00001/00221
d D 4.7 83/07/16 23:48:59 sam 10 9
c add useful sccs id's
e
s 00002/00002/00220
d D 4.6 83/05/16 17:21:39 ralph 9 8
c changes for px and py printcap entries.
e
s 00000/00011/00222
d D 4.5 83/04/29 16:08:16 ralph 8 6
c changes for new printer daemon.
e
s 00000/00012/00221
d R 4.5 83/04/29 11:52:30 ralph 7 6
c changes for new printer daemon.
e
s 00010/00013/00223
d D 4.4 83/04/05 14:50:58 ralph 6 4
c fixed line number counting
e
s 00004/00008/00228
d R 4.4 83/04/05 14:34:28 ralph 5 4
c line number counting was off by one.
e
s 00000/00008/00236
d D 4.3 83/03/30 09:16:52 ralph 4 3
c fixes lpr -p to the varian by not deleting blank lines at the top.
e
s 00014/00004/00230
d D 4.2 83/03/17 15:46:48 ralph 3 1
c standardized signal handling
e
s 00014/00004/00230
d R 4.2 83/03/17 15:39:52 ralph 2 1
c 
e
s 00234/00000/00000
d D 4.1 80/11/30 15:56:28 root 1 0
c date and time created 80/11/30 15:56:28 by root
e
u
U
t
T
I 12
/*
 * Copyright (c) 1983 Regents of the University of California.
D 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
I 13
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 14
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 14
I 14
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
E 14
E 13
 */

E 12
I 1
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
#ifndef lint
I 13
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 13
static char sccsid[] = "%W% (Berkeley) %G%";
D 12
#endif
E 12
I 12
D 13
#endif not lint
E 13
I 13
#endif /* not lint */
E 13
E 12

E 10
/*
 * Varian/Versatec printer filter
 */

#include <signal.h>
#include <stdio.h>
D 3
#include <sgtty.h>
E 3
#include <sys/vcmd.h>

#define LINELN 440

D 9
int	pltmode[] = {VPLOT, 0, 0};
int	prtmode[] = {VPRINT, 0, 0};
E 9
I 9
int	pltmode[] = {VPLOT};
int	prtmode[] = {VPRINT};
E 9
char	linebuf[LINELN+1];
char	ovbuf[LINELN];
int	ov;
int	lineno;
int	varian = 1;	/* default is the varian */
int	width = 132;	/* default line length */
I 11
int	indent = 0;	/* default indent length */
E 11
int	length = 58;	/* 80 for 11" long paper */
int	npages = 1;
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
D 8
onintr()
E 3
{
I 3
	signal(SIGTERM, SIG_IGN);
	exit(1);
}

E 8
D 11
main(argc, argv) 
E 11
I 11
main(argc, argv)
E 11
	int argc;
	char *argv[];
{
E 3
	register int i;
I 3
D 8

	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, onintr);
E 8
E 3

	if (argv[0][strlen(argv[0])-1] == 'W') { /* Wide: the versatec. */
		varian = 0;
		width = 440;
		length = 66;
	}

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
				if ((i = atoi(&argv[0][2])) > 0 && i < LINELN)
					width = i;
				break;

			case 'l':
				length = atoi(&argv[0][2]);
				break;

I 11
			case 'i':
				if ((i = atoi(&argv[0][2])) >= 0 &&
				    i < LINELN - 1)
					indent = i;
				break;

E 11
			case 'c':	/* Print input without throwing away
					   control chars and without putting
					   in page breaks. */
				literal++;
				break;
			}
		} else
			acctfile = *argv;
	}
	/*
	 * device should be open on file descriptor 1.
	 */
	ioctl(1, VSETSTATE, prtmode);
	send();
	if (name && acctfile && access(acctfile, 02) >= 0 &&
	    freopen(acctfile, "a", stdout) != NULL) {
		printf("%7.2f\t%s:%s\n", (float)npages, host, name);
	}
	exit(0);
}

send()
{
D 4
	register nskipped;

E 4
	lineno = 0;
D 4
	nskipped = 0;
E 4
	while (getline()) {
D 4
		if (!literal && varian && lineno==0 && linebuf[0]==0 && nskipped<3) {
			nskipped++;
			continue;
		}
E 4
D 6
		if (varian && lineno >= length) {
E 6
I 6
		if (varian && !literal && lineno >= length) {
E 6
D 4
			nskipped = 0;
E 4
			putline(1);
			lineno = 0;
D 6
		} else {
E 6
I 6
		} else
E 6
			putline(0);
D 6
			if (literal)	/* Don't make page breaks if -l. */
				lineno = 1;
			else
				lineno++;
		}
E 6
	}
D 6
	if (varian && lineno)
E 6
I 6
	if (varian && lineno) {
E 6
		putchar('\f');	/* be sure to end on a page boundary */
I 6
		npages++;
	}
E 6
	/*
	 * Put out an extra null to ensure varian will get an even
	 * number of good characters.
	 */
	putchar('\0');
D 6
	npages += (lineno + length - 1) / length;
E 6
}

getline()
{
	register col, maxcol, c;

	ov = 0;
	for (col = 0; col < width; col++) {
		linebuf[col] = ' ';
		ovbuf[col] = 0;
	}
D 11
	col = 0;
E 11
I 11
	col = indent;
E 11
	maxcol = 0;
	for (;;) switch (c = getchar()) {

	case EOF:
		return(0);

	case '\031':
		/*
		 * lpd needs to use a different filter to print data so
		 * stop what we are doing and wait for lpd to restart us.
		 */
		if ((c = getchar()) == '\1') {
			putchar('\0');		/* make sure even # sent */
			fflush(stdout);
			kill(getpid(), SIGSTOP);
			ioctl(1, VSETSTATE, prtmode);
			continue;
		}
		ungetc(c, stdin);
		c = '\031';
		/* fall through if not stop sequence */
	default:
		if (c >= ' ' || literal) {
			if (col < width) {
				if (linebuf[col] == '_') {
					ovbuf[col] = 0377;
					ov++;
				}
				linebuf[col++] = c;
				if (col > maxcol)
					maxcol = col;
			} else
				col++;
		}
		continue;

	case ' ':
		col++;
		continue;

	case '\t':
		col = (col|07) + 1;
		continue;

	case '\r':
		col = 0;
		continue;

	case '_':
		if (col < width) {
			if (linebuf[col] != ' ') {
				ovbuf[col] = 0377;
				ov++;
			} else
				linebuf[col] = c;
			col++;
			if (col > maxcol)
				maxcol = col;
		} else
			col++;
		continue;

	case '\f':
		/* Fall through, treating a ff as a line break, too... */
D 6
		lineno = length;
E 6
I 6
		lineno = length - 1;
E 6
	case '\n':
		if (maxcol > width)
			maxcol = width;
		linebuf[maxcol] = '\0';
I 6
		if (++lineno % length == 0)
			npages++;
E 6
		return(1);

	case '\b':
		if (col > 0)
			col--;
		continue;
	}
}

putline(ff)
int ff;
{
	register char *lp;
	register c, i;

	lp = linebuf;
	while (c = *lp++)
		putchar(c);
	if (ov) {
		putchar('\n');
		putchar('\0');
		fflush(stdout);
		ioctl(1, VSETSTATE, pltmode);
		for (lp = ovbuf, i = ov; ov--; ) {
			putchar(*lp & 0377);
			putchar(*lp++ & 0377);
		}
		if (ov & 1)
			putchar('\0');
		fflush(stdout);
		ioctl(1, VSETSTATE, prtmode);
	}
D 6
	if (ff) {
E 6
I 6
	if (ff)
E 6
		putchar('\f');
D 6
		npages++;
	} else if (ov == 0)
E 6
I 6
	else if (ov == 0)
E 6
		putchar('\n');
	if (ferror(stdout))
		exit(1);
}
E 1
