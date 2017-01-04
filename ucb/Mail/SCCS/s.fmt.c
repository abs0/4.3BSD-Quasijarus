h35000
s 00001/00001/00439
d D 5.6 04/03/31 21:30:18 msokolov 12 11
c allow ISO-compliant 8-bit characters
e
s 00012/00006/00428
d D 5.5 88/02/18 17:03:53 bostic 11 10
c written by Kurt Shoens; added Berkeley specific header
e
s 00003/00003/00431
d D 5.4 87/05/18 12:28:43 edward 10 9
c major rework: made faster, cleaned up, obsolete code removed,
c the whole thing should be chucked and written from scratch
e
s 00073/00060/00361
d D 5.3 86/07/07 17:30:58 mckusick 9 8
c from torek
e
s 00002/00002/00419
d D 5.2 85/06/21 17:10:09 mckusick 8 7
c botched copyright
e
s 00013/00001/00408
d D 5.1 85/06/06 10:32:56 dist 7 6
c Add copyright
e
s 00000/00002/00409
d D 2.3 84/08/08 15:35:08 ralph 6 5
c don't need to call setbuf().
e
s 00003/00003/00408
d D 2.2 83/08/11 22:15:50 sam 5 4
c standardize sccs keyword lines
e
s 00000/00000/00411
d D 2.1 81/07/01 11:08:52 kurt 4 3
c Release to Heidi Stettner
e
s 00023/00007/00388
d D 1.3 81/03/11 15:55:34 kas 3 2
c now takes optional -(width) argument to get other than 72 char lines
e
s 00001/00001/00394
d D 1.2 81/01/05 17:34:27 kas 2 1
c added ? as a statement terminating character
e
s 00395/00000/00000
d D 1.1 80/10/08 09:49:52 kas 1 0
c date and time created 80/10/08 09:49:52 by kas
e
u
U
f b 
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
D 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
I 11
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
 */

E 7
I 1
D 5
#
E 5
I 5
#ifndef lint
I 7
D 8
char copyright[] =
E 8
I 8
D 11
char *copyright =
E 11
I 11
char copyright[] =
E 11
E 8
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11

#ifndef lint
E 7
D 8
static char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
D 11
static char *sccsid = "%W% (Berkeley) %G%";
E 8
D 7
#endif
E 7
I 7
#endif not lint
E 11
I 11
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 11
E 7
E 5

#include <stdio.h>
#include <ctype.h>

/*
 * fmt -- format the concatenation of input files or standard input
 * onto standard output.  Designed for use with Mail ~|
 *
D 3
 * Syntax: fmt [ name ... ]
E 3
I 3
D 9
 * Syntax: fmt [ -width ] [ name ... ]
E 3
 * Author: Kurt Shoens (UCB) 12/7/78
E 9
I 9
 * Syntax : fmt [ goal [ max ] ] [ name ... ]
 * Authors: Kurt Shoens (UCB) 12/7/78;
 *          Liz Allen (UMCP) 2/24/83 [Addition of goal length concept].
E 9
 */
D 5

static char *SccsId = "%W% %G%";
E 5

I 9
/* LIZ@UOM 6/18/85 -- Don't need LENGTH any more.
 * #define	LENGTH	72		Max line length in output
 */
E 9
D 3
#define	LENGTH	72		/* Max line length in output */
E 3
#define	NOSTR	((char *) 0)	/* Null string pointer for lint */

I 9
/* LIZ@UOM 6/18/85 --New variables goal_length and max_length */
int	goal_length = 65;	/* Target or goal line length in output */
int	max_length = 75;	/* Max line length in output */
E 9
int	pfx;			/* Current leading blank count */
int	lineno;			/* Current input line */
int	mark;			/* Last place we saw a head line */
I 3
D 9
int	width = 72;		/* Width that we will not exceed */
E 9
E 3

D 10
char	*calloc();		/* for lint . . . */
E 10
I 10
char	*malloc();		/* for lint . . . */
E 10
char	*headnames[] = {"To", "Subject", "Cc", 0};

/*
 * Drive the whole formatter by managing input files.  Also,
 * cause initialization of the output stuff and flush it out
 * at the end.
 */

main(argc, argv)
I 9
	int argc;
E 9
	char **argv;
{
	register FILE *fi;
	register int errs = 0;
I 3
D 6
	char sobuf[BUFSIZ];
E 6
D 9
	register char *cp;
	int nofile;
E 9
I 9
	int number;		/* LIZ@UOM 6/18/85 */
E 9
E 3

	setout();
	lineno = 1;
	mark = -10;
I 9
	/*
	 * LIZ@UOM 6/18/85 -- Check for goal and max length arguments 
	 */
	if (argc > 1 && (1 == (sscanf(argv[1], "%d", &number)))) {
		argv++;
		argc--;
		goal_length = number;
		if (argc > 1 && (1 == (sscanf(argv[1], "%d", &number)))) {
			argv++;
			argc--;
			max_length = number;
		}
	}
	if (max_length <= goal_length) {
		fprintf(stderr, "Max length must be greater than %s\n",
			"goal length");
		exit(1);
	}
E 9
D 3
	setbuf(stdout, calloc(1, BUFSIZ));
E 3
I 3
D 6
	setbuf(stdout, sobuf);
E 6
E 3
	if (argc < 2) {
D 3
		setbuf(stdin, calloc(1, BUFSIZ));
E 3
I 3
D 9
single:
E 9
E 3
		fmt(stdin);
		oflush();
		exit(0);
	}
I 3
D 9
	nofile = 1;
E 9
E 3
	while (--argc) {
D 3
		if ((fi = fopen(*++argv, "r")) == NULL) {
			perror(*argv);
E 3
I 3
D 9
		cp = *++argv;
		if (*cp == '-') {
			width = atoi(cp+1);
			if (width <= 0 || width >= BUFSIZ-2) {
				fprintf(stderr, "fmt:  bad width: %d\n", width);
				exit(1);
			}
			continue;
		}
		nofile = 0;
		if ((fi = fopen(cp, "r")) == NULL) {
			perror(cp);
E 9
I 9
		if ((fi = fopen(*++argv, "r")) == NULL) {
			perror(*argv);
E 9
E 3
			errs++;
			continue;
		}
		fmt(fi);
		fclose(fi);
	}
I 3
D 9
	if (nofile)
		goto single;
E 9
E 3
	oflush();
	exit(errs);
}

/*
 * Read up characters from the passed input file, forming lines,
 * doing ^H processing, expanding tabs, stripping trailing blanks,
 * and sending each line down for analysis.
 */
D 9

E 9
fmt(fi)
	FILE *fi;
{
	char linebuf[BUFSIZ], canonb[BUFSIZ];
	register char *cp, *cp2;
	register int c, col;

	c = getc(fi);
	while (c != EOF) {
D 9
		
E 9
		/*
		 * Collect a line, doing ^H processing.
		 * Leave tabs for now.
		 */
D 9

E 9
		cp = linebuf;
		while (c != '\n' && c != EOF && cp-linebuf < BUFSIZ-1) {
			if (c == '\b') {
				if (cp > linebuf)
					cp--;
				c = getc(fi);
				continue;
			}
D 12
			if ((c < ' ' || c >= 0177) && c != '\t') {
E 12
I 12
			if ((c < ' ' || c >= 0177 && c < 0240) && c != '\t') {
E 12
				c = getc(fi);
				continue;
			}
			*cp++ = c;
			c = getc(fi);
		}
		*cp = '\0';

		/*
		 * Toss anything remaining on the input line.
		 */
D 9

E 9
		while (c != '\n' && c != EOF)
			c = getc(fi);
		
		/*
		 * Expand tabs on the way to canonb.
		 */
D 9

E 9
		col = 0;
		cp = linebuf;
		cp2 = canonb;
		while (c = *cp++) {
			if (c != '\t') {
				col++;
				if (cp2-canonb < BUFSIZ-1)
					*cp2++ = c;
				continue;
			}
			do {
				if (cp2-canonb < BUFSIZ-1)
					*cp2++ = ' ';
				col++;
			} while ((col & 07) != 0);
		}

		/*
		 * Swipe trailing blanks from the line.
		 */
D 9

E 9
		for (cp2--; cp2 >= canonb && *cp2 == ' '; cp2--)
			;
		*++cp2 = '\0';
		prefix(canonb);
		if (c != EOF)
			c = getc(fi);
	}
}

/*
 * Take a line devoid of tabs and other garbage and determine its
 * blank prefix.  If the indent changes, call for a linebreak.
 * If the input line is blank, echo the blank line on the output.
 * Finally, if the line minus the prefix is a mail header, try to keep
 * it on a line by itself.
 */
D 9

E 9
prefix(line)
	char line[];
{
	register char *cp, **hp;
	register int np, h;

	if (strlen(line) == 0) {
		oflush();
		putchar('\n');
		return;
	}
	for (cp = line; *cp == ' '; cp++)
		;
	np = cp - line;

	/*
	 * The following horrible expression attempts to avoid linebreaks
	 * when the indent changes due to a paragraph.
	 */
D 9

E 9
	if (np != pfx && (np > pfx || abs(pfx-np) > 8))
		oflush();
	if (h = ishead(cp))
		oflush(), mark = lineno;
	if (lineno - mark < 3 && lineno - mark > 0)
		for (hp = &headnames[0]; *hp != (char *) 0; hp++)
			if (ispref(*hp, cp)) {
				h = 1;
				oflush();
				break;
			}
	if (!h && (h = (*cp == '.')))
		oflush();
	pfx = np;
	split(cp);
	if (h)
		oflush();
	lineno++;
}

/*
 * Split up the passed line into output "words" which are
 * maximal strings of non-blanks with the blank separation
 * attached at the end.  Pass these words along to the output
 * line packer.
 */
D 9

E 9
split(line)
	char line[];
{
	register char *cp, *cp2;
	char word[BUFSIZ];
I 9
	int wordl;		/* LIZ@UOM 6/18/85 */
E 9

	cp = line;
	while (*cp) {
		cp2 = word;
I 9
		wordl = 0;	/* LIZ@UOM 6/18/85 */
E 9

		/*
D 9
		 * Collect a 'word,' allowing it to contain escaped
		 * white space.
E 9
I 9
		 * Collect a 'word,' allowing it to contain escaped white
		 * space. 
E 9
		 */
D 9

E 9
		while (*cp && *cp != ' ') {
			if (*cp == '\\' && isspace(cp[1]))
				*cp2++ = *cp++;
			*cp2++ = *cp++;
I 9
			wordl++;/* LIZ@UOM 6/18/85 */
E 9
		}

		/*
D 9
		 * Guarantee a space at end of line.
		 * Two spaces after end of sentence punctuation.
E 9
I 9
		 * Guarantee a space at end of line. Two spaces after end of
		 * sentence punctuation. 
E 9
		 */
D 9

E 9
		if (*cp == '\0') {
			*cp2++ = ' ';
D 2
			if (any(cp[-1], ".:!"))
E 2
I 2
D 9
			if (any(cp[-1], ".:!?"))
E 9
I 9
			if (any(cp[-1], ".:!"))
E 9
E 2
				*cp2++ = ' ';
		}
		while (*cp == ' ')
			*cp2++ = *cp++;
		*cp2 = '\0';
D 9
		pack(word);
E 9
I 9
		/*
		 * LIZ@UOM 6/18/85 pack(word); 
		 */
		pack(word, wordl);
E 9
	}
}

/*
 * Output section.
 * Build up line images from the words passed in.  Prefix
 * each line with correct number of blanks.  The buffer "outbuf"
 * contains the current partial line image, including prefixed blanks.
 * "outp" points to the next available space therein.  When outp is NOSTR,
 * there ain't nothing in there yet.  At the bottom of this whole mess,
 * leading tabs are reinserted.
 */
D 9

E 9
char	outbuf[BUFSIZ];			/* Sandbagged output line image */
char	*outp;				/* Pointer in above */

/*
 * Initialize the output section.
 */
D 9

E 9
setout()
{
	outp = NOSTR;
}

/*
 * Pack a word onto the output line.  If this is the beginning of
 * the line, push on the appropriately-sized string of blanks first.
 * If the word won't fit on the current line, flush and begin a new
 * line.  If the word is too long to fit all by itself on a line,
 * just give it its own and hope for the best.
I 9
 *
 * LIZ@UOM 6/18/85 -- If the new word will fit in at less than the
 *	goal length, take it.  If not, then check to see if the line
 *	will be over the max length; if so put the word on the next
 *	line.  If not, check to see if the line will be closer to the
 *	goal length with or without the word and take it or put it on
 *	the next line accordingly.
E 9
 */

D 9
pack(word)
E 9
I 9
/*
 * LIZ@UOM 6/18/85 -- pass in the length of the word as well
 * pack(word)
 *	char word[];
 */
pack(word,wl)
E 9
	char word[];
I 9
	int wl;
E 9
{
	register char *cp;
	register int s, t;

	if (outp == NOSTR)
		leadin();
D 9
	t = strlen(word);
	s = outp-outbuf;
D 3
	if (t+s <= LENGTH) {
E 3
I 3
	if (t+s <= width) {
E 3
		
E 9
I 9
	/*
	 * LIZ@UOM 6/18/85 -- change condition to check goal_length; s is the
	 * length of the line before the word is added; t is now the length
	 * of the line after the word is added
	 *	t = strlen(word);
	 *	if (t+s <= LENGTH) 
	 */
	s = outp - outbuf;
	t = wl + s;
	if ((t <= goal_length) ||
	    ((t <= max_length) && (t - goal_length <= goal_length - s))) {
E 9
		/*
D 9
		 * In like flint!
E 9
I 9
		 * In like flint! 
E 9
		 */
D 9

		for (cp = word; *cp; *outp++ = *cp++)
			;
E 9
I 9
		for (cp = word; *cp; *outp++ = *cp++);
E 9
		return;
	}
	if (s > pfx) {
		oflush();
		leadin();
	}
D 9
	for (cp = word; *cp; *outp++ = *cp++)
		;
E 9
I 9
	for (cp = word; *cp; *outp++ = *cp++);
E 9
}

/*
 * If there is anything on the current output line, send it on
 * its way.  Set outp to NOSTR to indicate the absence of the current
 * line prefix.
 */
D 9

E 9
oflush()
{
	if (outp == NOSTR)
		return;
	*outp = '\0';
	tabulate(outbuf);
	outp = NOSTR;
}

/*
 * Take the passed line buffer, insert leading tabs where possible, and
 * output on standard output (finally).
 */
D 9

E 9
tabulate(line)
	char line[];
{
	register char *cp, *cp2;
	register int b, t;

	/*
	 * Toss trailing blanks in the output line.
	 */
D 9

E 9
	cp = line + strlen(line) - 1;
	while (cp >= line && *cp == ' ')
		cp--;
	*++cp = '\0';
	
	/*
	 * Count the leading blank space and tabulate.
	 */
D 9

E 9
	for (cp = line; *cp == ' '; cp++)
		;
	b = cp-line;
	t = b >> 3;
	b &= 07;
	if (t > 0)
		do
			putc('\t', stdout);
		while (--t);
	if (b > 0)
		do
			putc(' ', stdout);
		while (--b);
	while (*cp)
		putc(*cp++, stdout);
	putc('\n', stdout);
}

/*
 * Initialize the output line with the appropriate number of
 * leading blanks.
 */
D 9

E 9
leadin()
{
	register int b;
	register char *cp;

	for (b = 0, cp = outbuf; b < pfx; b++)
		*cp++ = ' ';
	outp = cp;
}

/*
 * Save a string in dynamic space.
 * This little goodie is needed for
 * a headline detector in head.c
 */
D 9

E 9
char *
savestr(str)
	char str[];
{
	register char *top;

D 10
	top = calloc(strlen(str) + 1, 1);
E 10
I 10
	top = malloc(strlen(str) + 1);
E 10
	if (top == NOSTR) {
		fprintf(stderr, "fmt:  Ran out of memory\n");
		exit(1);
	}
D 10
	copy(str, top);
E 10
I 10
	strcpy(top, str);
E 10
D 9
	return(top);
E 9
I 9
	return (top);
E 9
}

/*
 * Is s1 a prefix of s2??
 */
D 9

E 9
ispref(s1, s2)
	register char *s1, *s2;
{

	while (*s1++ == *s2)
		;
D 9
	return(*s1 == '\0');
E 9
I 9
	return (*s1 == '\0');
E 9
}
E 1
