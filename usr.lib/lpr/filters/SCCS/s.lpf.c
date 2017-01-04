h54481
s 00010/00005/00188
d D 5.3 88/06/30 17:53:49 bostic 18 17
c install approved copyright notice
e
s 00015/00003/00178
d D 5.2 88/03/08 08:20:06 bostic 17 16
c add Berkeley copyright notice
e
s 00007/00001/00174
d D 5.1 85/05/15 11:32:18 dist 16 15
c Add copyright notice
e
s 00001/00000/00174
d D 4.13 85/04/05 16:17:19 ralph 15 14
c flush after page break to get data out in timely manner.
e
s 00005/00001/00169
d D 4.12 83/07/16 23:53:13 sam 14 12
c add useful sccs id's
e
s 00004/00001/00169
d R 4.12 83/07/16 23:47:13 sam 13 12
c add useful sccs id's
e
s 00013/00006/00157
d D 4.11 83/05/19 16:34:55 ralph 12 11
c added indentation.
e
s 00001/00011/00162
d D 4.10 83/05/02 10:03:18 ralph 11 9
c changes for new printer daemon.
e
s 00000/00012/00161
d R 4.10 83/04/29 11:52:20 ralph 10 9
c changes for new printer daemon.
e
s 00007/00005/00166
d D 4.9 83/04/13 14:50:45 ralph 9 8
c fixed line counting and extra line caused by EOF.
e
s 00014/00003/00157
d D 4.8 83/03/17 15:50:35 ralph 8 7
c standardized signal handling
e
s 00056/00004/00104
d D 4.7 83/03/07 10:49:31 ralph 7 6
c added acounting
e
s 00017/00005/00091
d D 4.6 83/03/01 11:22:35 ralph 6 5
c fixed several bugs.
e
s 00077/00124/00019
d D 4.5 83/02/10 17:06:35 ralph 5 4
c bugs fixed and vpr options merged into lpr.
e
s 00019/00031/00124
d D 4.4 83/01/05 11:26:55 root 4 3
c Working version of remote spooling.
e
s 00009/00004/00146
d D 4.3 81/06/02 17:09:48 sam 3 2
c fix problems with form feeds (sorta a kludge)
e
s 00003/00000/00147
d D 4.2 81/06/02 10:16:51 sam 2 1
c ifdef output to eliminate siphoning of control characters
e
s 00147/00000/00000
d D 4.1 81/05/09 16:40:12 root 1 0
c date and time created 81/05/09 16:40:12 by root
e
u
U
t
T
I 16
/*
 * Copyright (c) 1983 Regents of the University of California.
D 17
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 17
I 17
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 18
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 18
I 18
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
E 18
E 17
 */

E 16
I 1
D 5
/*	%M%	%I%	%E%	*/
/*
 * lpf -- Line printer filter: handles underlines for those printers/
 *	  device drivers that won't
E 5
I 5
D 14
/*		%M%	%I%	%E%
E 14
I 14
#ifndef lint
I 17
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif /* not lint */

#ifndef lint
E 17
static char sccsid[] = "%W% (Berkeley) %G%";
D 16
#endif
E 16
I 16
D 17
#endif not lint
E 17
I 17
#endif /* not lint */
E 17
E 16

/*
E 14
 * 	filter which reads the output of nroff and converts lines
 *	with ^H's to overwritten lines.  Thus this works like 'ul'
 *	but is much better: it can handle more than 2 overwrites
 *	and it is written with some style.
 *	modified by kls to use register references instead of arrays
 *	to try to gain a little speed.
E 5
 */
I 11

E 11
D 5

E 5
#include <stdio.h>
#include <signal.h>

D 5
#define	LINELN	132
E 5
I 5
#define MAXWIDTH  132
#define MAXREP    10
E 5
I 2
D 3
#define output(c) (putchar(c))
E 3
E 2

D 5
char	linebuf[LINELN+2];
int	ov;
I 3
int	ff;
E 3
char	ovbuf[LINELN];
E 5
I 5
char	buf[MAXREP][MAXWIDTH];
int	maxcol[MAXREP] = {-1};
I 7
int	lineno;
int	width = 132;	/* default line length */
int	length = 66;	/* page length */
I 12
int	indent;		/* indentation length */
E 12
int	npages = 1;
int	literal;	/* print control characters */
char	*name;		/* user's login name */
char	*host;		/* user's machine name */
char	*acctfile;	/* accounting information file */
E 7
E 5

D 7
main()
E 7
I 7
D 8
main(argc, argv)
int argc;
char *argv[];
E 8
I 8
D 11
onintr()
E 8
E 7
{
I 8
	signal(SIGTERM, SIG_IGN);
	exit(1);
}

E 11
main(argc, argv) 
	int argc;
	char *argv[];
{
E 8
D 5
	extern char _sobuf[BUFSIZ];
E 5
I 5
	register FILE *p = stdin, *o = stdout;
	register int i, col;
	register char *cp;
	int done, linedone, maxrep;
	char ch, *limit;
I 8
D 11

	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, onintr);
E 11
E 8
E 5

I 7
	while (--argc) {
		if (*(cp = *++argv) == '-') {
			switch (cp[1]) {
			case 'n':
				argc--;
				name = *++argv;
				break;

			case 'h':
				argc--;
				host = *++argv;
				break;

			case 'w':
				if ((i = atoi(&cp[2])) > 0 && i <= MAXWIDTH)
					width = i;
				break;

			case 'l':
				length = atoi(&cp[2]);
				break;

I 12
			case 'i':
				indent = atoi(&cp[2]);
				break;

E 12
			case 'c':	/* Print control chars */
				literal++;
				break;
			}
		} else
			acctfile = cp;
	}

E 7
D 5
	setbuf(stdout, _sobuf);
	while (getline())
		putline();
	fflush(stdout);
	if (ferror(stdout))
		exit(1);
	exit(0);
}
E 5
I 5
	for (cp = buf[0], limit = buf[MAXREP]; cp < limit; *cp++ = ' ');
	done = 0;
	
	while (!done) {
D 12
		col = 0;
E 12
I 12
		col = indent;
E 12
D 9
		maxrep = 0;
E 9
I 9
		maxrep = -1;
E 9
		linedone = 0;
		while (!linedone) {
			switch (ch = getc(p)) {
			case EOF:
				linedone = done = 1;
				ch = '\n';
				break;
E 5

D 5
getline()
{
	register int col, maxcol, c;
E 5
I 5
D 6
			case '\031':
				fflush(stdout);
				kill(getpid(), SIGSTOP);
				break;
E 5

E 6
D 5
	ov = 0;
D 4
	for (col=0; col<LINELN; col++) {
E 4
I 4
	for (col = 0; col < LINELN; col++) {
E 4
		linebuf[col] = ' ';
		ovbuf[col] = 0;
	}
	col = 0;
	maxcol = 0;
	for (;;) switch (c = getchar()) {
E 5
I 5
			case '\f':
I 7
				lineno = length;
E 7
			case '\n':
I 7
D 9
				if (++lineno >= length) {
					npages++;
					lineno = 0;
				}
E 9
I 9
				if (maxrep < 0)
					maxrep = 0;
E 9
E 7
				linedone = 1;
				break;
E 5

D 5
	case EOF:
		return(0);
E 5
I 5
			case '\b':
D 12
				if (col-- < 0)
					col = 0;
E 12
I 12
				if (--col < indent)
					col = indent;
E 12
				break;
E 5

D 5
	default:
D 4
		if (c>=' ') {
E 4
I 4
		if (c >= ' ') {
E 4
			if (col < LINELN) {
D 4
				if (linebuf[col]=='_') {
E 4
I 4
				if (linebuf[col] != ' ') {
E 4
					ov++;
D 4
					ovbuf[col] = '_';
				}
				linebuf[col++] = c;
				if (col > maxcol)
E 4
I 4
					ovbuf[col] = c;
				} else
					linebuf[col] = c;
				if (++col > maxcol)
E 4
					maxcol = col;
E 5
I 5
			case '\r':
D 12
				col = 0;
E 12
I 12
				col = indent;
E 12
				break;

			case '\t':
D 12
				col = (col | 07) + 1;
E 12
I 12
				col = ((col - indent) | 07) + indent + 1;
E 12
				break;
I 6

D 7
#ifdef WAITCHAR
E 7
			case '\031':
				/*
				 * lpd needs to use a different filter to
				 * print data so stop what we are doing and
				 * wait for lpd to restart us.
				 */
				if ((ch = getchar()) == '\1') {
					fflush(stdout);
					kill(getpid(), SIGSTOP);
					break;
				} else {
					ungetc(ch, stdin);
					ch = '\031';
				}
D 7
#endif
E 7
E 6

			default:
D 7
				if (col >= MAXWIDTH)
E 7
I 7
D 12
				if (col >= width || !literal && ch < ' ')
E 12
I 12
				if (col >= width || !literal && ch < ' ') {
					col++;
E 12
E 7
					break;
I 12
				}
E 12
				cp = &buf[0][col];
				for (i = 0; i < MAXREP; i++) {
					if (i > maxrep)
						maxrep = i;
					if (*cp == ' ') {
						*cp = ch;
						if (col > maxcol[i])
							maxcol[i] = col;
						break;
					}
					cp += MAXWIDTH;
				}
				col++;
				break;
E 5
			}
		}
D 5
		continue;
E 5

D 5
	case ' ':
		col++;
		continue;

	case '\t':
		col = (col|07) + 1;
D 4
		if (col>maxcol)
E 4
I 4
		if (col > maxcol)
E 4
			maxcol = col;
		continue;

	case '\r':
		col = 0;
		continue;

D 4
	case '_':
		if (col>=LINELN) {
			col++;
			continue;
		}
		if (linebuf[col]!=' ') {
			ovbuf[col] = '_';
			ov++;
		} else
			linebuf[col] = c;
		col++;
		if (col>maxcol)
			maxcol = col;
		continue;

E 4
I 3
	case '\f':
		ff = 1;		/* force form feed */
E 3
	case '\n':
D 4
		if (maxcol>=LINELN)
E 4
I 4
		if (maxcol >= LINELN)
E 4
			maxcol = LINELN;
		linebuf[maxcol] = 0;
		return(1);

	case '\b':
D 4
		if (col>0)
E 4
I 4
		if (col > 0)
E 4
			col--;
		continue;
	}
}

putline()
{
D 4
	register char *lp, *ep;
	register int c;
E 4
I 4
	register char c, *lp;
E 4
I 3

E 3
	lp = linebuf;
	while (c = *lp++)
		output(c);
	if (ov) {
		putchar('\r');
D 4
		for (ep= &ovbuf[LINELN-1]; *ep == 0; ep--)
			continue;
		for (lp=ovbuf; lp <= ep; lp++)
			output(*lp ? *lp : ' ');
E 4
I 4
		lp = ovbuf;
		while (ov) {
			if (c = *lp++) {
				output(c);
				ov--;
			} else
				output(' ');
E 5
I 5
		/* print out lines */
		for (i = 0; i <= maxrep; i++) {
			for (cp = buf[i], limit = cp+maxcol[i]; cp <= limit;) {
				putc(*cp, o);
				*cp++ = ' ';
			}
			if (i < maxrep)
				putc('\r', o);
			else
				putc(ch, o);
I 9
			if (++lineno >= length) {
I 15
				fflush(o);
E 15
				npages++;
				lineno = 0;
			}
E 9
			maxcol[i] = -1;
E 5
		}
E 4
	}
I 7
	if (lineno) {		/* be sure to end on a page boundary */
		putchar('\f');
		npages++;
	}
	if (name && acctfile && access(acctfile, 02) >= 0 &&
	    freopen(acctfile, "a", stdout) != NULL) {
		printf("%7.2f\t%s:%s\n", (float)npages, host, name);
	}
	exit(0);
E 7
D 5
	putchar('\n');
I 3
	if (ff) {
		ff = 0;
		putchar('\f');
	}
E 3
	if (ferror(stdout))
		exit(1);
}

I 2
D 3
#ifndef output
E 3
E 2
output(c)
register char c;
{

	if (c == -1)
		return;
	c &= 0177;
	if (c == 0177)
		putchar('^'), c = '?';
	if (c == 033)
		c = '$';
	if (c < ' ') switch (c) {

	case '\n':
		break;

	case '\f':
	case '\b':
	case '\t':
	case '\r':
		break;

	default:
		putchar('^');
D 3
			c |= 0100;
E 3
I 3
		c |= 0100;
E 3
	}
	putchar(c);
E 5
}
I 2
D 3
#endif
E 3
E 2
E 1
