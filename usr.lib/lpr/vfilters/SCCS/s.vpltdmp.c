h63718
s 00010/00005/00131
d D 5.3 88/06/30 17:53:33 bostic 9 8
c install approved copyright notice
e
s 00016/00007/00120
d D 5.2 88/03/08 08:30:21 bostic 8 7
c add Berkeley specific header
e
s 00007/00001/00120
d D 5.1 85/05/15 11:33:34 dist 7 6
c Add copyright notice
e
s 00001/00001/00120
d D 4.6 84/03/12 16:06:07 ralph 6 5
c fix page accounting computation.
e
s 00007/00008/00114
d D 4.5 83/07/16 23:49:16 sam 5 4
c add useful sccs id's
e
s 00033/00017/00089
d D 4.4 83/06/24 15:50:04 ralph 4 3
c fixed partial buffer problems.
e
s 00016/00011/00090
d D 4.3 83/05/16 17:21:53 ralph 3 2
c changes for px and py printcap entries.
e
s 00003/00003/00098
d D 4.2 83/04/29 11:52:26 ralph 2 1
c changes for new printer daemon.
e
s 00101/00000/00000
d D 4.1 83/03/07 14:58:33 ralph 1 0
c date and time created 83/03/07 14:58:33 by ralph
e
u
U
t
T
I 7
/*
D 8
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * Copyright (c) 1981 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
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
E 9
E 8
 */

E 7
I 1
D 5
/****************************************************************/
/*								*/
/*								*/
/* Copyright (C) 1981, Regents of the University of California	*/
/*	All rights reserved					*/
/*								*/
/****************************************************************/
/*  VPLTDMP: version %I%			updated %G%
E 5
I 5
#ifndef lint
I 8
char copyright[] =
"%Z% Copyright (c) 1981 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 8
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif
E 7
I 7
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8
E 7

/*
D 8
 * Copyright (C) 1981, Regents of the University of California
 *	All rights reserved
E 5
 *
E 8
 *  reads raster file created by vplot and dumps it onto the
 *  Varian or Versatec plotter.
 *  Input comes from file descriptor 0, output is to file descriptor 1.
 */
#include <stdio.h>
D 4
#include <signal.h>
E 4
#include <sys/vcmd.h>

#define IN	0
#define OUT	1

static	char *Sid = "%W%\t%G%";

D 3
int	plotmd[] = { VPLOT, 0, 0 };
int	prtmd[]  = { VPRINT, 0, 0 };
E 3
I 3
int	plotmd[] = { VPLOT };
int	prtmd[]  = { VPRINT };
E 3

char	buf[BUFSIZ];		/* output buffer */

int	lines;			/* number of raster lines printed */
D 3
int	varian = 1;		/* default is the varian */
int	BytesPerLine = 264;	/* Number of bytes per raster line */
E 3
I 3
int	varian;			/* 0 for versatec, 1 for varian. */
int	BYTES_PER_LINE;		/* number of bytes per raster line. */
int	PAGE_LINES;		/* number of raster lines per page. */
E 3

char	*name, *host, *acctfile;

main(argc, argv)
D 4
char *argv[];
E 4
I 4
	int argc;
	char *argv[];
E 4
{
D 4
	register int n, bytes;
E 4
I 4
	register int n;
E 4

D 3
	if (argv[0][strlen(argv[0])-1] == 'W') {
		varian = 0;
		BytesPerLine = 880;
	}

E 3
	while (--argc) {
		if (**++argv == '-') {
			switch (argv[0][1]) {
I 3
			case 'x':
				BYTES_PER_LINE = atoi(&argv[0][2]) / 8;
				varian = BYTES_PER_LINE == 264;
				break;

			case 'y':
				PAGE_LINES = atoi(&argv[0][2]);
				break;

E 3
			case 'n':
				argc--;
				name = *++argv;
				break;

			case 'h':
				argc--;
				host = *++argv;
			}
		} else
			acctfile = *argv;
	}

D 4
	ioctl(OUT, VSETSTATE, plotmd);
E 4
I 4
	n = putplot();
E 4

D 4
	bytes = 0;
	while ((n = read(IN, buf, sizeof(buf))) > 0) {
		if (write(OUT, buf, n) != n)
			exit(1);
		bytes += n;
	}
	if (bytes & 1) {	/* make sure even number bytes are sent */
		write(OUT, "", 1);
		bytes++;
	}
D 3
	lines = bytes / BytesPerLine;
E 3
I 3
	lines = bytes / BYTES_PER_LINE;
E 3

E 4
	ioctl(OUT, VSETSTATE, prtmd);
	if (varian)
D 2
		write(OUT, "\014", 2);
E 2
I 2
		write(OUT, "\f", 2);
E 2
	else
		write(OUT, "\n\n\n\n\n", 6);
	account(name, host, *argv);
D 4
	exit(0);
E 4
I 4
	exit(n);
}

putplot()
{
	register char *cp;
	register int bytes, n;

	cp = buf;
	bytes = 0;
	ioctl(OUT, VSETSTATE, plotmd);
	while ((n = read(IN, cp, sizeof(buf))) > 0) {
		if (write(OUT, cp, n) != n)
			return(1);
		bytes += n;
	}
	/*
	 * Make sure we send complete raster lines.
	 */
	if ((n = bytes % BYTES_PER_LINE) > 0) {
		n = BYTES_PER_LINE - n;
		for (cp = &buf[n]; cp > buf; )
			*--cp = 0;
		if (write(OUT, cp, n) != n)
			return(1);
		bytes += n;
	}
	lines += bytes / BYTES_PER_LINE;
	return(0);
E 4
}

account(who, from, acctfile)
	char *who, *from, *acctfile;
{
	register FILE *a;

	if (who == NULL || acctfile == NULL)
		return;
	if (access(acctfile, 02) || (a = fopen(acctfile, "a")) == NULL)
		return;
	/*
D 2
	 * Varian accounting is done by 11 inch pages;
E 2
I 2
	 * Varian accounting is done by 8.5 inch pages;
E 2
	 * Versatec accounting is by the (12 inch) foot.
	 */
D 2
	fprintf(a, "t%6.2f\t", (lines / 200.0) / (varian ? 11.0 : 12.0));
E 2
I 2
D 3
	fprintf(a, "t%6.2f\t", (lines / 200.0) / (varian ? 8.5 : 12.0));
E 3
I 3
D 6
	fprintf(a, "t%6.2f\t", (lines / 200.0) / PAGE_LINES);
E 6
I 6
	fprintf(a, "t%6.2f\t", (double)lines / (double)PAGE_LINES);
E 6
E 3
E 2
	if (from != NULL)
		fprintf(a, "%s:", from);
	fprintf(a, "%s\n", who);
	fclose(a);
}
E 1
