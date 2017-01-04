h15583
s 00013/00002/00483
d D 5.5 88/07/06 15:23:17 bostic 12 11
c written by Mark Horton; add Berkeley specific copyright
e
s 00015/00069/00470
d D 5.4 88/01/05 12:52:51 bostic 11 10
c pass \f, remove getopt(3) copy, lint cleanups; bug report 4.3BSD/ucb/154
e
s 00001/00003/00538
d D 5.3 87/04/29 14:07:41 bostic 10 9
c ul/nroff conflict over accent marks; bug report 4.2BSD/ucb/153
e
s 00001/00001/00540
d D 5.2 86/12/09 14:28:51 bostic 9 8
c ul outputs wrong character in overstruck sequence; bug report 4.3BSD/ucb/49
e
s 00014/00002/00527
d D 5.1 85/05/31 09:35:30 dist 8 7
c Add copyright
e
s 00001/00010/00528
d D 4.7 85/03/31 18:27:19 sam 7 6
c use bzero to init buffer
e
s 00000/00003/00538
d D 4.6 84/09/17 10:46:29 ralph 6 5
c don't call setbuf.
e
s 00003/00002/00538
d D 4.5 83/08/11 21:31:18 sam 5 4
c standardize sccs keyword lines
e
s 00010/00004/00530
d D 4.4 83/05/26 09:53:55 ralph 4 3
c fixed extra line after EOF and bold mode when overstruck chars differ.
e
s 00006/00000/00528
d D 4.3 82/01/03 20:50:31 root 3 2
c arrange to turn off special modes when doing immediate font switches,
c e.g., bold to italic without roman inbetween.  Add SCCS Ids.  (EPA)
e
s 00448/00206/00080
d D 4.2 81/11/22 17:02:28 root 2 1
c Much smarter version dealing with attributes (MRH)
e
s 00286/00000/00000
d D 4.1 80/10/01 17:29:07 bill 1 0
c date and time created 80/10/01 17:29:07 by bill
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
D 12
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 12
I 12
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
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
E 12
 */

E 8
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
/*
 * ul
 */
E 2
I 2
D 4
/*	@(#)vcrt.c	3.13	*/
I 3
static char SccsId[] =	"%W%	(Berkeley)	%G%";
E 4
I 4
D 5
/*	%W%	%G%	*/
static char SccsId[] =	"%W% (Berkeley) %G%";
E 5
I 5
#ifndef lint
D 8
static char sccsid[] =	"%W% (Berkeley) %G%";
#endif
E 8
I 8
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 11
#endif not lint
E 11
I 11
#endif /* not lint */
E 11
E 8
E 5
E 4

E 3
E 2
#include <stdio.h>

I 2
#define	IESC	'\033'
#define	SO	'\016'
#define	SI	'\017'
#define	HFWD	'9'
#define	HREV	'8'
#define	FREV	'7'
#define	MAXBUF	512

#define	NORMAL	000
#define	ALTSET	001	/* Reverse */
#define	SUPERSC	002	/* Dim */
#define	SUBSC	004	/* Dim | Ul */
#define	UNDERL	010	/* Ul */
#define	BOLD	020	/* Bold */

int	must_use_uc, must_overstrike;
char	*CURS_UP, *CURS_RIGHT, *CURS_LEFT,
	*ENTER_STANDOUT, *EXIT_STANDOUT, *ENTER_UNDERLINE, *EXIT_UNDERLINE,
	*ENTER_DIM, *ENTER_BOLD, *ENTER_REVERSE, *UNDER_CHAR, *EXIT_ATTRIBUTES;

struct	CHAR	{
	char	c_mode;
	char	c_char;
} ;

E 2
D 6
char	buf[BUFSIZ];
D 2
char	isul[BUFSIZ];
char	termcap[1024];
char	ulbuf[BUFSIZ];
char	*stul, *endul, *chul;
char	*backspace;
char	*termtype;
int	outc();
char	*tgetstr();
char	*getenv();
E 2

E 6
I 2
struct	CHAR	obuf[MAXBUF];
int	col, maxcol;
int	mode;
int	halfpos;
int	upln;
int	iflag;

E 2
main(argc, argv)
	int argc;
	char **argv;
{
I 11
	extern int optind;
	extern char *optarg;
E 11
D 2
	register int i;
	char *cp;
E 2
I 2
	int c;
D 11
	char *cp, *termtype;
E 11
I 11
	char *termtype;
E 11
E 2
	FILE *f;
I 2
	char termcap[1024];
D 11
	char *getenv();
	extern int optind;
	extern char *optarg;
E 11
I 11
	char *getenv(), *strcpy();
E 11
E 2

D 2
	argc--, argv++;
E 2
	termtype = getenv("TERM");
D 2
	if (termtype == NULL)
		termtype = "dumb";
	while (argc > 0 && argv[0][0] == '-') {
		switch(argv[0][1]) {
E 2
I 2
	if (termtype == NULL || (argv[0][0] == 'c' && !isatty(1)))
		termtype = "lpr";
	while ((c=getopt(argc, argv, "it:T:")) != EOF)
		switch(c) {
E 2

		case 't':
		case 'T': /* for nroff compatibility */
D 2
			if (argv[0][2])
				termtype = &argv[0][2];
			else {
				termtype = argv[1];
				argc--;
				argv++;
			}
E 2
I 2
				termtype = optarg;
E 2
			break;
		case 'i':
D 2
			argc--, argv++;
			iul(argc, argv);
			exit(0);
E 2
I 2
			iflag = 1;
			break;
E 2

		default:
D 2
			printf("Usage: ul [ -i ] [ -tTerm ] file...\n");
E 2
I 2
			fprintf(stderr,
D 11
				"Usage: %s [ -i ] [ -tTerm ] file...\n",
E 11
I 11
				"usage: %s [ -i ] [ -tTerm ] file...\n",
E 11
				argv[0]);
E 2
			exit(1);
		}
D 2
	}
E 2
I 2

E 2
	switch(tgetent(termcap, termtype)) {

	case 1:
D 2
		if (tgetflag("os"))
			execv("/bin/cat",argv);
		cp = ulbuf;
		if ((backspace = tgetstr("bc",&cp)) == NULL)
			backspace = "\b";
		/*
		 * Handle terminals that have start underline/stop
		 * underline sequences, as well as those with
		 * underline char sequences (we assume the sequence
		 * moves the cursor forward one character).
		 * If we can't find underline sequences, we
		 * settle for standout sequences.
		 */
		if ((chul=tgetstr("uc",&cp)) == NULL)
			chul = "";
		if ((stul=tgetstr("us",&cp)) == NULL && !tgetflag("ul") &&
		    (!*chul) && (stul=tgetstr("so",&cp)) == NULL)
			stul = "";
		if ((endul=tgetstr("ue",&cp)) == NULL && !tgetflag("ul") &&
		    (!*chul) && (endul=tgetstr("se",&cp)) == NULL)
			endul = "";
		if (chul==0&&stul==0&&endul==0&&tgetflag("ul"))
			execv("/bin/cat",argv);
E 2
		break;

	default:
		fprintf(stderr,"trouble reading termcap");
		/* fall through to ... */

	case 0:
		/* No such terminal type - assume dumb */
D 2
		stul = endul = chul = "";
E 2
I 2
D 11
		strcpy(termcap, "dumb:os:col#80:cr=^M:sf=^J:am:");
E 11
I 11
		(void)strcpy(termcap, "dumb:os:col#80:cr=^M:sf=^J:am:");
E 11
E 2
		break;
	}
D 2
	if (argc == 0)
E 2
I 2
	initcap();
	if (    (tgetflag("os") && ENTER_BOLD==NULL ) ||
		(tgetflag("ul") && ENTER_UNDERLINE==NULL && UNDER_CHAR==NULL))
			must_overstrike = 1;
D 6
	setbuf(stdout, buf);
E 6
	initbuf();
	if (optind == argc)
E 2
		filter(stdin);
D 2
	else for (i=0; i<argc; i++) {
		f = fopen(argv[i],"r");
E 2
I 2
	else for (; optind<argc; optind++) {
		f = fopen(argv[optind],"r");
E 2
		if (f == NULL) {
D 2
			perror(argv[i]);
E 2
I 2
			perror(argv[optind]);
E 2
			exit(1);
		} else
			filter(f);
	}
	exit(0);
}

filter(f)
FILE *f;
{
D 2
	register int p, n;
	register char c;
	int state;
E 2
I 2
	register c;
E 2

D 2
	n = 0;
	for (;;) {
		p = 0;
		for (p=0; p<n; p++) {
			buf[p] = '\0';
			isul[p] = 0;
		}
		p = n = 0;
E 2
I 2
	while((c = getc(f)) != EOF) switch(c) {
E 2

D 2
		for (;;) {
			c = getc(f);
			if (c==EOF)
				break;
			if (c=='\b') {
				if (p > 0) {
					p--;
				}
			} else if (c=='_' && isul[p]==0 && buf[p]) {
				isul[p] = 1;
				p++;
E 2
I 2
	case '\b':
		if (col > 0)
			col--;
		continue;

	case '\t':
		col = (col+8) & ~07;
		if (col > maxcol)
			maxcol = col;
		continue;

	case '\r':
		col = 0;
		continue;

	case SO:
		mode |= ALTSET;
		continue;

	case SI:
		mode &= ~ALTSET;
		continue;

	case IESC:
		switch (c = getc(f)) {

		case HREV:
			if (halfpos == 0) {
				mode |= SUPERSC;
				halfpos--;
			} else if (halfpos > 0) {
				mode &= ~SUBSC;
				halfpos--;
E 2
			} else {
D 2
				if (buf[p] == '_')
					isul[p] = 1;
				buf[p] = c;
				p++;
				if (n < p)
					n = p;
E 2
I 2
				halfpos = 0;
				reverse();
E 2
			}
D 2
			if (c=='\n')
				break;
		}
E 2
I 2
			continue;
E 2

D 2
		state = 0;
		for (p=0; p<n; p++) {
			if (isul[p] != state)
				tputs(isul[p] ? stul : endul, 1, outc);
			state = isul[p];
			putchar(buf[p]);
			if (isul[p] && *chul) {
				printf("%s",backspace);
				tputs(chul, 1, outc);
E 2
I 2
		case HFWD:
			if (halfpos == 0) {
				mode |= SUBSC;
				halfpos++;
			} else if (halfpos < 0) {
				mode &= ~SUPERSC;
				halfpos++;
			} else {
				halfpos = 0;
				fwd();
E 2
			}
I 2
			continue;

		case FREV:
			reverse();
			continue;

		default:
			fprintf(stderr,
				"Unknown escape sequence in input: %o, %o\n",
				IESC, c);
			exit(1);
E 2
		}
D 2
		if (c==EOF) break;
E 2
I 2
		continue;

	case '_':
		if (obuf[col].c_char)
			obuf[col].c_mode |= UNDERL | mode;
		else
			obuf[col].c_char = '_';
	case ' ':
		col++;
		if (col > maxcol)
			maxcol = col;
		continue;

	case '\n':
		flushln();
I 4
		continue;
E 4

I 11
	case '\f':
		flushln();
		putchar('\f');
		continue;

E 11
	default:
		if (c < ' ')	/* non printing */
			continue;
		if (obuf[col].c_char == '\0') {
			obuf[col].c_char = c;
			obuf[col].c_mode = mode;
		} else if (obuf[col].c_char == '_') {
			obuf[col].c_char = c;
			obuf[col].c_mode |= UNDERL|mode;
D 4
		} else
E 4
I 4
		} else if (obuf[col].c_char == c)
E 4
			obuf[col].c_mode |= BOLD|mode;
I 4
D 10
		else {
D 9
			obuf[col].c_mode = c;
E 9
I 9
			obuf[col].c_char = c;
E 10
I 10
		else
E 10
E 9
			obuf[col].c_mode = mode;
D 10
		}
E 10
E 4
		col++;
		if (col > maxcol)
			maxcol = col;
		continue;
E 2
	}
I 2
D 4
	flushln();
E 4
I 4
	if (maxcol)
		flushln();
E 4
E 2
}

D 2
outc(c)
char c;
E 2
I 2
flushln()
E 2
{
D 2
	putchar(c);
E 2
I 2
	register lastmode;
	register i;
	int hadmodes = 0;

	lastmode = NORMAL;
	for (i=0; i<maxcol; i++) {
		if (obuf[i].c_mode != lastmode) {
			hadmodes++;
			setmode(obuf[i].c_mode);
			lastmode = obuf[i].c_mode;
		}
		if (obuf[i].c_char == '\0') {
			if (upln) {
				puts(CURS_RIGHT);
			} else
				outc(' ');
		} else
			outc(obuf[i].c_char);
	}
	if (lastmode != NORMAL) {
		setmode(0);
	}
	if (must_overstrike && hadmodes)
		overstrike();
	putchar('\n');
	if (iflag && hadmodes)
		iattr();
D 11
	fflush(stdout);
E 11
I 11
	(void)fflush(stdout);
E 11
	if (upln)
		upln--;
	initbuf();
E 2
}

D 2
#define BACKSPACE 0
#define	QUOTE	0200
E 2
I 2
/*
 * For terminals that can overstrike, overstrike underlines and bolds.
 * We don't do anything with halfline ups and downs, or Greek.
 */
overstrike()
{
	register int i;
	char lbuf[256];
	register char *cp = lbuf;
	int hadbold=0;
E 2

D 2
char	linebuf[BUFSIZ], genbuf[BUFSIZ];
char	*strcpy();
E 2
I 2
	/* Set up overstrike buffer */
	for (i=0; i<maxcol; i++)
		switch (obuf[i].c_mode) {
		case NORMAL:
		default:
			*cp++ = ' ';
			break;
		case UNDERL:
			*cp++ = '_';
			break;
		case BOLD:
			*cp++ = obuf[i].c_char;
			hadbold=1;
			break;
		}
	putchar('\r');
	for (*cp=' '; *cp==' '; cp--)
		*cp = 0;
	for (cp=lbuf; *cp; cp++)
		putchar(*cp);
	if (hadbold) {
		putchar('\r');
		for (cp=lbuf; *cp; cp++)
			putchar(*cp=='_' ? ' ' : *cp);
		putchar('\r');
		for (cp=lbuf; *cp; cp++)
			putchar(*cp=='_' ? ' ' : *cp);
	}
}
E 2

D 2
iul(argc, argv)
	int argc;
	char *argv[];
E 2
I 2
iattr()
E 2
{
D 2
	register c;
	register char *lp;
E 2
I 2
	register int i;
	char lbuf[256];
	register char *cp = lbuf;
E 2

D 2
	do {
		if (argc > 0) {
			if (freopen(argv[0], "r", stdin) == NULL) {
				perror(argv[0]);
				exit(1);
			}
			argc--; argv++;
E 2
I 2
	for (i=0; i<maxcol; i++)
		switch (obuf[i].c_mode) {
		case NORMAL:	*cp++ = ' '; break;
		case ALTSET:	*cp++ = 'g'; break;
		case SUPERSC:	*cp++ = '^'; break;
		case SUBSC:	*cp++ = 'v'; break;
		case UNDERL:	*cp++ = '_'; break;
		case BOLD:	*cp++ = '!'; break;
		default:	*cp++ = 'X'; break;
E 2
		}
D 2
		while (fgets(linebuf, sizeof linebuf, stdin) != 0) {
			for (lp = linebuf; *lp; lp++)
				continue;
			*--lp = 0;
			doulg();
			dographic();
			if (genbuf[0])
				printf("\n%s", genbuf);
			putchar('\n');
			fflush(stdout);
		}
	} while (argc > 0);
	exit(0);
E 2
I 2
	for (*cp=' '; *cp==' '; cp--)
		*cp = 0;
	for (cp=lbuf; *cp; cp++)
		putchar(*cp);
	putchar('\n');
E 2
}

D 2
dographic()
E 2
I 2
initbuf()
E 2
{
D 2
	register char *lp;
	register c;
E 2
I 2
D 7
	register i;
E 7
E 2

D 2
	for (lp = linebuf; c = *lp++;) {
		switch (c) {
			case '\b':
				if (BACKSPACE == 0)
					c = '?';
				break;
			default:
				if (c < ' ' || c == 0177)
					c = '?';
				break;
			case '\t':
				break;
		}
		putchar(c);
E 2
I 2
D 7
	for (i=0; i<MAXBUF; i++) {
		obuf[i].c_char = '\0';
		obuf[i].c_mode = NORMAL;
E 2
	}
E 7
I 7
D 11
	bzero(obuf, sizeof (obuf));		/* depends on NORMAL == 0 */
E 11
I 11
	bzero((char *)obuf, sizeof (obuf));	/* depends on NORMAL == 0 */
E 11
E 7
I 2
	col = 0;
	maxcol = 0;
	mode &= ALTSET;
E 2
}

D 2
doulg()
E 2
I 2
fwd()
E 2
{
D 2
	register char *lp, *gp;
	char *maxgp;
	register c;
	char csw;
	int col;
E 2
I 2
	register oldcol, oldmax;
E 2

D 2
	gp = genbuf;
	*gp = 0;
	maxgp = gp;
	col = 0;
	for (lp = linebuf; c = *lp++;) {
		switch (c) {
			case '\t':
				while ((col & 7) != 7) {
					*gp++ = ' ';
					if (gp >= &genbuf[BUFSIZ - 2])
						goto ovflo;
					col++;
				}
E 2
I 2
	oldcol = col;
	oldmax = maxcol;
	flushln();
	col = oldcol;
	maxcol = oldmax;
}

reverse()
{
	upln++;
	fwd();
	puts(CURS_UP);
	puts(CURS_UP);
	upln++;
}

initcap()
{
	static char tcapbuf[512];
D 11
	char *termtype;
E 11
	char *bp = tcapbuf;
	char *getenv(), *tgetstr();

	/* This nonsense attempts to work with both old and new termcap */
	CURS_UP =		tgetstr("up", &bp);
	CURS_RIGHT =		tgetstr("ri", &bp);
	if (CURS_RIGHT == NULL)
		CURS_RIGHT =	tgetstr("nd", &bp);
	CURS_LEFT =		tgetstr("le", &bp);
	if (CURS_LEFT == NULL)
		CURS_LEFT =	tgetstr("bc", &bp);
	if (CURS_LEFT == NULL && tgetflag("bs"))
		CURS_LEFT =	"\b";

	ENTER_STANDOUT =	tgetstr("so", &bp);
	EXIT_STANDOUT =		tgetstr("se", &bp);
	ENTER_UNDERLINE =	tgetstr("us", &bp);
	EXIT_UNDERLINE =	tgetstr("ue", &bp);
	ENTER_DIM =		tgetstr("mh", &bp);
	ENTER_BOLD =		tgetstr("md", &bp);
	ENTER_REVERSE =		tgetstr("mr", &bp);
	EXIT_ATTRIBUTES =	tgetstr("me", &bp);

	if (!ENTER_BOLD && ENTER_REVERSE)
		ENTER_BOLD = ENTER_REVERSE;
	if (!ENTER_BOLD && ENTER_STANDOUT)
		ENTER_BOLD = ENTER_STANDOUT;
	if (!ENTER_UNDERLINE && ENTER_STANDOUT) {
		ENTER_UNDERLINE = ENTER_STANDOUT;
		EXIT_UNDERLINE = EXIT_STANDOUT;
	}
	if (!ENTER_DIM && ENTER_STANDOUT)
		ENTER_DIM = ENTER_STANDOUT;
	if (!ENTER_REVERSE && ENTER_STANDOUT)
		ENTER_REVERSE = ENTER_STANDOUT;
	if (!EXIT_ATTRIBUTES && EXIT_STANDOUT)
		EXIT_ATTRIBUTES = EXIT_STANDOUT;
	
	/*
	 * Note that we use REVERSE for the alternate character set,
	 * not the as/ae capabilities.  This is because we are modelling
	 * the model 37 teletype (since that's what nroff outputs) and
	 * the typical as/ae is more of a graphics set, not the greek
	 * letters the 37 has.
	 */

D 7
#ifdef notdef
printf("so %s se %s us %s ue %s me %s\n",
	ENTER_STANDOUT, EXIT_STANDOUT, ENTER_UNDERLINE,
	EXIT_UNDERLINE, EXIT_ATTRIBUTES);
#endif
E 7
	UNDER_CHAR =		tgetstr("uc", &bp);
	must_use_uc = (UNDER_CHAR && !ENTER_UNDERLINE);
}

outchar(c)
char c;
{
	putchar(c&0177);
}

puts(str)
char *str;
{
	if (str)
		tputs(str, 1, outchar);
}

static curmode = 0;
outc(c)
char c;
{
	putchar(c);
	if (must_use_uc &&  (curmode&UNDERL)) {
		puts(CURS_LEFT);
		puts(UNDER_CHAR);
	}
}

setmode(newmode)
int newmode;
{
	if (!iflag)
I 3
	{
		if (curmode != NORMAL && newmode != NORMAL)
			setmode(NORMAL);
E 3
		switch (newmode) {
		case NORMAL:
			switch(curmode) {
			case NORMAL:
E 2
				break;
I 2
			case UNDERL:
				puts(EXIT_UNDERLINE);
				break;
E 2
			default:
D 2
				if (gp >= maxgp)
					break;
				c |= (*gp & QUOTE);
E 2
I 2
				/* This includes standout */
				puts(EXIT_ATTRIBUTES);
E 2
				break;
D 2
			case '_':
				if (gp >= maxgp)
					c = QUOTE;
				else
					c = *gp | QUOTE;
				break;
			case '\b':
				if (gp > genbuf) {
					gp--;
					col--;
				}
				continue;
E 2
I 2
			}
			break;
		case ALTSET:
			puts(ENTER_REVERSE);
			break;
		case SUPERSC:
			/*
			 * This only works on a few terminals.
			 * It should be fixed.
			 */
			puts(ENTER_UNDERLINE);
			puts(ENTER_DIM);
			break;
		case SUBSC:
			puts(ENTER_DIM);
			break;
		case UNDERL:
			puts(ENTER_UNDERLINE);
			break;
		case BOLD:
			puts(ENTER_BOLD);
			break;
		default:
			/*
			 * We should have some provision here for multiple modes
			 * on at once.  This will have to come later.
			 */
			puts(ENTER_STANDOUT);
			break;
E 2
		}
I 3
	}
E 3
D 2
		if (gp >= &genbuf[BUFSIZ - 2]) {
ovflo:
			fprintf(stderr, "Line too long\n");
			exit(1);
E 2
I 2
	curmode = newmode;
D 11
}
/*	@(#)getopt.c	3.2	*/
#define	ERR(s, c)	if(opterr){\
	fputs(argv[0], stderr);\
	fputs(s, stderr);\
	fputc(c, stderr);\
	fputc('\n', stderr);}

int	opterr = 1;
int	optind = 1;
char	*optarg;
char	*index();

int
getopt (argc, argv, opts)
	char **argv, *opts;
{
	static int sp = 1;
	char c;
	char *cp;

	if (sp == 1)
		if (optind >= argc ||
		   argv[optind][0] != '-' || argv[optind][1] == '\0')
			return EOF;
		else if (strcmp(argv[optind], "--") == NULL) {
			optind++;
			return EOF;
E 2
		}
D 2
		*gp++ = c;
		if (gp > maxgp)
			maxgp = gp;
		col++;
E 2
I 2
		else if (strcmp(argv[optind], "-?") == NULL) {
			optind++;
			return '?';
		}
	c = argv[optind][sp];
	if (c == ':' || (cp=index(opts, c)) == NULL) {
		ERR (": illegal option -- ", c);
		if (argv[optind][++sp] == '\0') {
			optind++;
			sp = 1;
		}
		return '?';
E 2
	}
D 2
	*maxgp = 0;
	strcpy(linebuf, genbuf);
	for (lp = linebuf, gp = genbuf; c = *lp; gp++, lp++)
		if (c & QUOTE) {
			c &= 0177;
			if (c == 0)
				*lp = '_', *gp = ' ';
			else
				*lp = c, *gp = '-';
E 2
I 2
	if (*++cp == ':') {
		if (argv[optind][2] != '\0')
			optarg = &argv[optind++][sp+1];
		else if (++optind >= argc) {
			ERR (": option requires an argument -- ", c);
			sp = 1;
			return '?';
E 2
		} else
D 2
			*gp = ' ';
	--gp;
	while (gp >= genbuf && *gp == ' ')
		--gp;
	gp[1] = 0;
E 2
I 2
			optarg = argv[optind++];
		sp = 1;
	}
	else if (argv[optind][++sp] == '\0') {
		sp = 1;
		optind++;
	}
	return c;
E 11
E 2
}
E 1
