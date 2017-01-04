h17467
s 00004/00003/00891
d D 5.10 88/06/30 13:35:16 bostic 12 11
c fix for old MAKEHOSTS script
c grep ucb /etc/hosts | grep -v -e '-' didn't work
e
s 00004/00004/00890
d D 5.9 87/10/22 19:34:43 bostic 11 10
c ANSI C; sprintf now returns an int.
e
s 00002/00002/00892
d D 5.8 87/10/08 11:26:11 bostic 10 8
c fix flags in usage statements
e
s 00003/00003/00891
d R 5.8 87/10/07 18:27:03 bostic 9 8
c change usage statements
e
s 00011/00007/00883
d D 5.7 87/10/07 17:25:13 bostic 8 7
c implement -o flag; *always* print the file name
e
s 00003/00003/00887
d D 5.6 87/10/07 16:52:28 bostic 7 6
c everybody has the -h flag, now
e
s 00002/00001/00888
d D 5.5 87/10/07 11:20:28 bostic 6 5
c fix nalt incrementation on 'foo|bar' pattern
e
s 00032/00026/00857
d D 5.4 87/10/05 14:04:52 bostic 5 3
c fix alt buffer overflow; rewrite alternate() 
c minor lint fixes
e
s 00032/00025/00858
d R 5.4 87/10/05 12:56:11 bostic 4 3
c fix alternate buffer overflow; rewrote alternate() 
c minor lint fixes
e
s 00002/00000/00881
d D 5.3 87/10/05 12:14:31 bostic 3 2
c kanji() should be ifdef'd on NOKANJI
e
s 00006/00006/00875
d D 5.2 87/10/05 12:13:42 bostic 2 1
c pfile doesn't need to use stdio
e
s 00881/00000/00000
d D 5.1 87/10/03 16:27:25 bostic 1 0
c date and time created 87/10/03 16:27:25 by bostic
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

/*
     Hybrid Boyer/Moore/Gosper-assisted 'grep/egrep/fgrep' search, with delta0
     table as in original paper (CACM, October, 1977).  No delta1 or delta2.
     According to experiment (Horspool, Soft. Prac. Exp., 1982), delta2 is of
     minimal practical value.  However, to improve for worst case input,
     integrating the improved Galil strategies (Apostolico/Giancarlo, SIAM. J.
     Comput., Feb. 1986) deserves consideration.

     Method: 	extract longest metacharacter-free string from expression.
		this is done using a side-effect from henry spencer's regcomp().
		use boyer-moore to match such, then pass submatching lines
		to either regexp() or standard 'egrep', depending on certain
		criteria within execstrategy() below.  [this tradeoff is due
		to the general slowness of the regexp() nondeterministic
		machine on complex expressions, as well as the startup time
		of standard 'egrep' on short files.]  alternatively, one may
		change the vendor-supplied 'egrep' automaton to include
		boyer-moore directly.  see accompanying writeup for discussion
		of kanji expression treatment.

		late addition:  apply trickbag for fast match of simple
		alternations (sublinear, in common low-cardinality cases).
		trap fgrep into this lair.

		gnu additions:  -f, newline as |, \< and \> [in regexec()], more
				comments.  inspire better dfa exec() strategy.
				serious testing and help with special cases.

     Algorithm amalgam summary:

		dfa e?grep 		(aho/thompson)
		ndfa regexp() 		(spencer/aho)
		bmg			(boyer/moore/gosper)
		"superimposed" bmg   	(jaw)
		fgrep			(aho/corrasick)

		sorry, but the knuth/morris/pratt machine, horspool's
		"frequentist" code, and the rabin/karp matcher, however cute,
		just don't cut it for this production.

     James A. Woods				Copyright (c) 1986
     NASA Ames Research Center
*/
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
I 2
#include <sys/file.h>
E 2
#include <regexp.h>		/* must be henry spencer's version */

#define	MIN(A, B)	((A) > (B) ? (B) : (A))

#ifdef	SLOWSYS
#define read	xread
#endif
/*
 * define existing [ef]?grep program locations below for use by execvp().
 * [execlp() would be used were it not for the possibility of
 * installation-dependent recursion.] 
 */
#ifndef EGREPSTD
#define	EGREPSTD	"/usr/bin/egrep"
#endif
#ifndef GREPSTD
#define	GREPSTD		"/bin/grep"
#endif
#ifndef FGREPSTD
#define	FGREPSTD	"/usr/bin/fgrep"
#endif

#define BUFSIZE	8192		/* make higher for cray */
#define PATSIZE 6000
#define LARGE 	BUFSIZE + PATSIZE

D 5
#define ALTSIZE	100		/* generous? */
E 5
#define NALT	7		/* tied to scanf() size in alternate() */
#define NMUSH	6		/* loosely relates to expected alt length */

#define	FIRSTFEW	33 	/* Always do FIRSTFEW matches with regexec() */
#define	PUNTPERCENT	10	/* After FIRSTFEW, if PUNTPERCENT of the input
				 * was processed by regexp(), exec std egrep. */
#define NL	'\n'
#define	EOS	'\0'
#define	NONASCII	0200	/* Bit mask for Kanji non-ascii chars */
#define META	"\n^$.[]()?+*|\\"	/* egrep meta-characters */
#define SS2	'\216'		/* EUC Katakana (or Chinese2) prefix */
#define SS3	'\217'		/* EUC Kanji2 (or Chinese3) prefix */

extern char *optarg;
extern int optind;
char *progname;

int cflag, iflag, eflag, fflag, lflag, nflag;	/* SVID flags */
int sflag, hflag;		/* v7, v8, bsd */

int firstflag;			/* Stop at first match */
int grepflag;			/* Called as "grep" */
int fgrepflag;			/* Called as "fgrep" */
int altflag;			/* Simple alternation in pattern */
int boyonly;			/* No regexp needed -- all simple */
int flushflag;
int grepold, egrepold, fgrepold;

int nalt;			/* Number of alternatives */
int nsuccess;			/* 1 for match, 2 for error */
int altmin;			/* Minimum length of all the alternate
				 * strings */
int firstfile;			/* argv index of first file argument */
int patind;			/* argv index of pattern */
long nmatch;			/* Number of matches in this file */
long incount, counted;		/* Amount of input consumed */
long rxcount;			/* Bytes of input processed by regexec() */
int boyfound;			/* accumulated partial matches (tripped by
				 * FIRSTFEW) */
int prevmatch;			/* next three lines aid fast -n */
long nline, prevnline;
char *prevloc;

regexp *rspencer;
char *pattern;
char *patboy;			/* Pattern for simple Boyer-Moore */
char *patfile;			/* Filename containing pattern(s) */

int delta0[256];		/* Boyer-Moore algorithm core */
char cmap[256];			/* Usually 0-255, but if -i, maps upper to
				 * lower case */
char str[BUFSIZE + 2];
int nleftover;
char linetemp[BUFSIZE];
D 5
char altpat[NALT][ALTSIZE];	/* alternation component storage */
E 5
I 5
char *altpat[NALT];		/* alternation component storage */
E 5
int altlen[NALT];
short altset[NMUSH + 1][256];
char preamble[200];		/* match prefix (filename, line no.) */

int fd;
char *
D 11
strchr(), *strrchr(), *strcpy(), *strncpy(), *strpbrk(), *sprintf(), *malloc();
E 11
I 11
strchr(), *strrchr(), *strcpy(), *strncpy(), *strpbrk(), *malloc();
E 11
char *
grepxlat(), *fold(), *pfile(), *alternate(), *isolate();
char **args;

main(argc, argv)
	int argc;
	char *argv[];
{
D 8
	int c;
E 8
I 8
	int c, oflag;
E 8
	int errflag = 0;

	args = argv;

	if ((progname = strrchr(argv[0], '/')) != 0)
		progname++;
	else
		progname = argv[0];
	if (strcmp(progname, "grep") == 0)
		grepflag++;
D 8
	if (strcmp(progname, "fgrep") == 0)
E 8
I 8
	else if (strcmp(progname, "fgrep") == 0)
E 8
		fgrepflag++;

D 8
	while ((c = getopt(argc, argv, "bchie:f:lnsvwxy1")) != EOF) {
E 8
I 8
	oflag = 0;
	while ((c = getopt(argc, argv, "bchie:f:lnosvwxy1")) != EOF) {
E 8
		switch (c) {

		case 'f':
			fflag++;
			patfile = optarg;
			continue;
		case 'b':
		case 'v':
			egrepold++;	/* boyer-moore of little help here */
			continue;
		case 'c':
			cflag++;
			continue;
		case 'e':
			eflag++;
			pattern = optarg;
			continue;
		case 'h':
			hflag++;
			continue;
I 8
		case 'o':
			oflag++;
			continue;
E 8
		case '1':	/* Stop at very first match */
			firstflag++;	/* spead freaks only */
			continue;
		case 'i':
			iflag++;
			continue;
		case 'l':
			lflag++;
			continue;
		case 'n':
			nflag++;
			continue;
		case 's':
			sflag++;
			continue;
		case 'w':
		case 'y':
			if (!grepflag)
				errflag++;
			grepold++;
			continue;
		case 'x':	/* needs more work, like -b above */
			if (!fgrepflag)
				errflag++;
			fgrepold++;
			continue;
		case '?':
			errflag++;
		}
	}
	if (errflag || ((argc <= optind) && !fflag && !eflag)) {
		if (grepflag)
D 7
oops("usage: grep [-bcihlnsvwy] [-e] pattern [file ...]");
E 7
I 7
D 8
oops("usage: grep [-bchilnsvwy] [-e] pattern [file ...]");
E 8
I 8
oops("usage: grep [-bchilnosvwy] [-e] pattern [file ...]");
E 8
E 7
		else if (fgrepflag)
D 7
oops("usage: fgrep [-bcilnv] {-f patfile | [-e] strings} [file ...]");
E 7
I 7
D 8
oops("usage: fgrep [-bchilnv] {-f patfile | [-e] strings} [file ...]");
E 8
I 8
D 10
oops("usage: fgrep [-bchilnov] {-f patfile | [-e] strings} [file ...]");
E 10
I 10
oops("usage: fgrep [-bchilnosvx] {-f patfile | [-e] strings} [file ...]");
E 10
E 8
E 7
		else		/* encourage SVID options, though we provide
				 * others */
D 7
oops("usage: egrep [-bcilnv] {-f patfile | [-e] pattern} [file ...]");
E 7
I 7
D 8
oops("usage: egrep [-bchilnv] {-f patfile | [-e] pattern} [file ...]");
E 8
I 8
D 10
oops("usage: egrep [-bchilnov] {-f patfile | [-e] pattern} [file ...]");
E 10
I 10
oops("usage: egrep [-bchilnosv] {-f patfile | [-e] pattern} [file ...]");
E 10
E 8
E 7
	}
D 12
	patind = optind;
E 12
	if (fflag)
D 12
		pattern = pfile(patfile), patind = 0;
	else if (!eflag)
E 12
I 12
		pattern = pfile(patfile);
	else if (!eflag) {
		patind = optind;
E 12
		pattern = argv[optind++];
I 12
	}
E 12

D 8
	if ((argc - optind) <= 1)	/* Filename invisible given < 2 files */
E 8
I 8
	if (!oflag && (argc - optind) <= 1)	/* Filename invisible given < 2 files */
E 8
		hflag++;
	if (pattern[0] == EOS)
		kernighan(argv);	/* same as it ever was */
	/*
	 * 'grep/egrep' merger -- "old" grep is called to handle: tagged
	 * exprs \( \), word matches \< and \>, -w and -y options, char
	 * classes with '-' at end (egrep bug?), and patterns beginning with
	 * an asterisk (don't ask why). otherwise, characters meaningful to
	 * 'egrep' but not to 'grep' are escaped; the entire expr is then
	 * passed to 'egrep'. 
	 */
	if (grepflag && !grepold) {
		if (strindex(pattern, "\\(") >= 0 ||
		    strindex(pattern, "\\<") >= 0 ||
		    strindex(pattern, "\\>") >= 0 ||
		    strindex(pattern, "-]") >= 0 ||
		    pattern[0] == '*')	/* grep bug */
			grepold++;
		else
			pattern = grepxlat(pattern);
	}
	if (grepold || egrepold || fgrepold)
		kernighan(argv);

	if (iflag)
		strcpy(pattern, fold(pattern));
	/*
	 * If the pattern is a plain string, just run boyer-moore. If it
	 * consists of meta-free alternatives, run "superimposed" bmg.
	 * Otherwise, find best string, and compile pattern for regexec(). 
	 */
	if (strpbrk(pattern, META) == NULL) {	/* do boyer-moore only */
		boyonly++;
		patboy = pattern;
	} else {
		if ((patboy = alternate(pattern)) != NULL)
			boyonly++;
		else {
			if ((patboy = isolate(pattern)) == NULL)
				kernighan(argv);	/* expr too involved */
#ifndef NOKANJI
			for (c = 0; pattern[c] != EOS; c++)
				if (pattern[c] & NONASCII)	/* kanji + meta */
					kernighan(argv);
#endif
			if ((rspencer = regcomp(pattern)) == NULL)
				oops("regcomp failure");
		}
	}
	gosper(patboy);		/* "pre-conditioning is wonderful"
				 * -- v. strassen */

	if ((firstfile = optind) >= argc) {
		/* Grep standard input */
		if (lflag)	/* We don't know its name! */
			exit(1);
		egsecute((char *) NULL);
	} else {
		while (optind < argc) {
			egsecute(argv[optind]);
			optind++;
			if (firstflag && (nsuccess == 1))
				break;
		}
	}
	exit((nsuccess == 2) ? 2 : (nsuccess == 0));
}

char *
pfile(pfname)			/* absorb expression from file */
	char *pfname;
{
D 2
	FILE *pf;
E 2
I 2
	int fd;
E 2
	struct stat patstat;
	static char *pat;

D 2
	if ((pf = fopen(pfname, "r")) == NULL)
E 2
I 2
	if ((fd = open(pfname, O_RDONLY, 0)) < 0)
E 2
		oops("can't read pattern file");
D 2
	if (fstat(fileno(pf), &patstat) != 0)
E 2
I 2
	if (fstat(fd, &patstat) != 0)
E 2
		oops("can't stat pattern file");
	if (patstat.st_size > PATSIZE) {
		if (fgrepflag) {	/* defer to unix version */
			fgrepold++;
			return "dummy";
		} else
			oops("pattern file too big");
	}
	if ((pat = malloc((unsigned) patstat.st_size + 1)) == NULL)
		oops("out of memory to read pattern file");
D 2
	if (patstat.st_size !=
	    fread(pat, sizeof(char), (int) patstat.st_size + 1, pf))
E 2
I 2
	if (patstat.st_size != read(fd, pat, (int)patstat.st_size))
E 2
		oops("error reading pattern file");
D 2
	(void) fclose(pf);
E 2
I 2
	(void) close(fd);
E 2

	pat[patstat.st_size] = EOS;
	if (pat[patstat.st_size - 1] == NL)	/* NOP for egrep; helps grep */
		pat[patstat.st_size - 1] = EOS;

	if (nlcount(pat, &pat[patstat.st_size]) > NALT) {
		if (fgrepflag)
			fgrepold++;	/* "what's it all about, alfie?" */
		else
			egrepold++;
	}
	return (pat);
}

egsecute(file)
	char *file;
{
	if (file == NULL)
		fd = 0;
D 5
	else if ((fd = open(file, 0)) <= 0) {
E 5
I 5
	else if ((fd = open(file, O_RDONLY, 0)) <= 0) {
E 5
		fprintf(stderr, "%s: can't open %s\n", progname, file);
		nsuccess = 2;
		return;
	}
	chimaera(file, patboy);

	if (!boyonly && !flushflag && file != NULL)
		flushmatches();
	if (file != NULL)
		close(fd);
}

chimaera(file, pat)		/* "reach out and boyer-moore search someone" */
	char *file, *pat;	/* -- soon-to-be-popular bumper sticker */
{
	register char *k, *strend, *s;
	register int j, count;
	register int *deltazero = delta0;
	int patlen = altmin;
	char *t;
	char *gotamatch(), *kanji(), *linesave(), *submatch();

	nleftover = boyfound = flushflag = 0;
	nline = 1L;
	prevmatch = 0;
	nmatch = counted = rxcount = 0L;

	while ((count = read(fd, str + nleftover, BUFSIZE - nleftover)) > 0) {

		counted += count;
		strend = linesave(str, count);

		for (k = str + patlen - 1; k < strend;) {
			/*
			 * for a large class of patterns, upwards of 80% of
			 * match time is spent on the next line.  we beat
			 * existing microcode (vax 'matchc') this way. 
			 */
			while ((k += deltazero[*(unsigned char *) k]) < strend);
			if (k < (str + LARGE))
				break;
			k -= LARGE;

			if (altflag) {
				/*
				 * Parallel Boyer-Moore.  Check whether each
				 * of the previous <altmin> chars COULD be
				 * from one of the alternative strings. 
				 */
				s = k - 1;
				j = altmin;
				while (altset[--j][(unsigned char)
					     cmap[*(unsigned char *) s--]]);
				/*
				 * quick test fails. in this life, compare
				 * 'em all.  but, a "reverse trie" would
				 * attenuate worst case (linear w/delta2?). 
				 */
				if (--j < 0) {
					count = nalt - 1;
					do {
						s = k;
						j = altlen[count];
						t = altpat[count];

						while
							(cmap[*(unsigned char *) s--]
							 == t[--j]);
						if (j < 0)
							break;
					}
					while (count--);
				}
			} else {
				/* One string -- check it */
				j = patlen - 1;
				s = k - 1;
				while (cmap[*(unsigned char *) s--] == pat[--j]);
			}
			/*
			 * delta-less shortcut for literati. short shrift for
			 * genetic engineers? 
			 */
			if (j >= 0) {
				k++;	/* no match; restart next char */
				continue;
			}
			k = submatch(file, pat, str, strend, k, count);
			if (k == NULL)
				return;
		}
		if (nflag) {
			if (prevmatch)
				nline = prevnline + nlcount(prevloc, k);
			else
				nline = nline + nlcount(str, k);
			prevmatch = 0;
		}
		strncpy(str, linetemp, nleftover);
	}
	if (cflag) {
		/* Bug from old grep: -c overrides -h.  We fix the bug. */
		if (!hflag)
			printf("%s:", file);
		printf("%ld\n", nmatch);
	}
}

char *
linesave(str, count)		/* accumulate partial line at end of buffer */
	char str[];
	register int count;
{
	register int j;

	count += nleftover;
	if (count != BUFSIZE && fd != 0)
		str[count++] = NL;	/* insurance for broken last line */
	str[count] = EOS;
	for (j = count - 1; str[j] != NL && j >= 0;)
		j--;
	/*
	 * break up these lines: long line (> BUFSIZE), last line of file, or
	 * short return from read(), as from tee(1) input 
	 */
	if (j < 0 && (count == (BUFSIZE - nleftover))) {
		str[count++] = NL;
		str[count] = EOS;
		linetemp[0] = EOS;
		nleftover = 0;
		return (str + count);
	} else {
		nleftover = count - j - 1;
		strncpy(linetemp, str + j + 1, nleftover);
		return (str + j);
	}
}

/*
 * Process partial match. First check for mis-aligned Kanji, then match line
 * against full compiled r.e. if statistics do not warrant handing off to
 * standard egrep. 
 */
char *
submatch(file, pat, str, strend, k, altindex)
	char file[], pat[], str[];
	register char *strend, *k;
	int altindex;
{
	register char *s;
	char *t, c;

	t = k;
	s = ((altflag) ? k - altlen[altindex] + 1 : k - altmin + 1);
#ifndef NOKANJI
	c = ((altflag) ? altpat[altindex][0] : pat[0]);
	if (c & NONASCII)
		if ((s = kanji(str, s, k)) == NULL)
			return (++k);	/* reject false kanji */
#endif
	do;
	while (*s != NL && --s >= str);
	k = s + 1;		/* now at line start */

	if (boyonly)
		return (gotamatch(file, k));

	incount = counted - (strend - k);
	if (boyfound++ == FIRSTFEW)
		execstrategy(file);

	s = t;
	do
		rxcount++;
	while (*s++ != NL);
	*--s = EOS;
	/*
	 * "quick henry -- the flit" (after theodor geisel) 
	 */
	if (regexec(rspencer, ((iflag) ? fold(k) : k)) == 1) {
		*s = NL;
		if (gotamatch(file, k) == NULL)
			return (NULL);
	}
	*s = NL;
	return (s + 1);
}

I 3
#ifndef NOKANJI
E 3
/*
 * EUC code disambiguation -- scan backwards to first 7-bit code, while
 * counting intervening 8-bit codes.  If odd, reject unaligned Kanji pattern. 
 * SS2/3 checks are for intermixed Japanase Katakana or Kanji2. 
 */
char *
kanji(str, s, k)
	register char *str, *s, *k;
{
	register int j = 0;

	for (s--; s >= str; s--) {
		if (*s == SS2 || *s == SS3 || (*s & NONASCII) == 0)
			break;
		j++;
	}
#ifndef CHINESE
	if (*s == SS2)
		j -= 1;
#endif  CHINESE
	return ((j & 01) ? NULL : k);
}
I 3
#endif
E 3

/*
 * Compute "Boyer-Moore" delta table -- put skip distance in delta0[c] 
 */
gosper(pattern)
	char *pattern;		/* ... HAKMEM lives ... */
{
	register int i, j;
	unsigned char c;

	/* Make one-string case look like simple alternatives case */
	if (!altflag) {
		nalt = 1;
		altmin = altlen[0] = strlen(pattern);
D 5
		strcpy(altpat[0], pattern);
E 5
I 5
		altpat[0] = pattern;
E 5
	}
	/* For chars that aren't in any string, skip by string length. */
	for (j = 0; j < 256; j++) {
		delta0[j] = altmin;
		cmap[j] = j;	/* Sneak in initialization of cmap */
	}

	/* For chars in a string, skip distance from char to end of string. */
	/* (If char appears more than once, skip minimum distance.) */
	for (i = 0; i < nalt; i++)
		for (j = 0; j < altlen[i] - 1; j++) {
			c = altpat[i][j];
			delta0[c] = MIN(delta0[c], altlen[i] - j - 1);
			if (iflag && islower((int) c))
				delta0[toupper((int) c)] = delta0[c];
		}

	/* For last char of each string, fall out of search loop. */
	for (i = 0; i < nalt; i++) {
		c = altpat[i][altlen[i] - 1];
		delta0[c] = LARGE;
		if (iflag && islower((int) c))
			delta0[toupper((int) c)] = LARGE;
	}
	if (iflag)
		for (j = 'A'; j <= 'Z'; j++)
			cmap[j] = tolower((int) j);
}

/*
 * Print, count, or stop on full match. Result is either the location for
 * continued search, or NULL to stop. 
 */
char *
gotamatch(file, s)
	register char *file, *s;
{
	char *savematch();
	int squirrel = 0;	/* nonzero to squirrel away FIRSTFEW matches */

	nmatch++;
	nsuccess = 1;
	if (!boyonly && boyfound <= FIRSTFEW && file != NULL)
		squirrel = 1;

	if (sflag)
		return (NULL);	/* -s usurps all flags (unlike some versions) */
	if (cflag) {		/* -c overrides -l, we guess */
		do;
		while (*s++ != NL);
	} else if (lflag) {
		puts(file);
		return (NULL);
	} else {
		if (!hflag)
			if (!squirrel)
				printf("%s:", file);
			else
D 11
				sprintf(preamble, "%s:", file);
E 11
I 11
				(void)sprintf(preamble, "%s:", file);
E 11
		if (nflag) {
			if (prevmatch)
				prevnline = prevnline + nlcount(prevloc, s);
			else
				prevnline = nline + nlcount(str, s);
			prevmatch = 1;

			if (!squirrel)
				printf("%ld:", prevnline);
			else
D 11
				sprintf(preamble + strlen(preamble),
E 11
I 11
				(void)sprintf(preamble + strlen(preamble),
E 11
					"%ld:", prevnline);
		}
		if (!squirrel) {
			do
				putchar(*s);
			while (*s++ != NL);
		} else
			s = savematch(s);

		if (nflag)
			prevloc = s - 1;
	}
	return ((firstflag && !cflag) ? NULL : s);
}

char *
fold(line)
	char *line;
{
	static char fline[BUFSIZE];
	register char *s, *t = fline;

	for (s = line; *s != EOS; s++)
		*t++ = (isupper((int) *s) ? (char) tolower((int) *s) : *s);
	*t = EOS;
	return (fline);
}

strindex(s, t)			/* the easy way, as in K&P, p. 192 */
	char *s, *t;
{
	int i, n;

	n = strlen(t);
	for (i = 0; s[i] != '\0'; i++)
		if (strncmp(s + i, t, n) == 0)
			return (i);
	return (-1);
}

char *
grepxlat(pattern)		/* grep pattern meta conversion */
	char *pattern;
{
	register char *p, *s;
	static char newpat[BUFSIZE];

	for (s = newpat, p = pattern; *p != EOS;) {
		if (*p == '\\') {	/* skip escapes ... */
			*s++ = *p++;
			if (*p)
				*s++ = *p++;
		} else if (*p == '[') {	/* ... and char classes */
			while (*p != EOS && *p != ']')
				*s++ = *p++;
		} else if (strchr("+?|()", *p) != NULL) {
			*s++ = '\\';	/* insert protection */
			*s++ = *p++;
		} else
			*s++ = *p++;
	}
	*s = EOS;
	grepflag = ((patind) ? 0 : 1);
	return (newpat);
}

/*
 * Test for simple alternation.  Result is NULL if it's not so simple, or is
 * a pointer to the first string if it is. Warning:  sscanf size is a
 * fixpoint, beyond which the speedup linearity starts to break down.  In the
 * wake of the elegant aho/corrasick "trie"-based fgrep, generalizing
 * altpat[] to arbitrary size is not useful. 
 */
char *
alternate(regexpr)
	char *regexpr;
{
D 5
	register i, j, min;
E 5
I 5
	register int i, j;
	register char *start, *stop;
E 5
	unsigned char c;
D 5
	char oflow[100];
E 5

	if (fgrepflag && strchr(regexpr, '|'))
D 5
		return (NULL);
E 5
I 5
			return (NULL);
E 5

D 5
	i = strlen(regexpr);
	for (j = 0; j < i; j++)
		if (regexpr[j] == NL)
			regexpr[j] = '|';

E 5
I 5
	/*
	 * break pattern up into altpat array; delimit on newline, bar,
	 * or EOS.  We know we won't overflow, we've already checked the
	 * number of patterns we're going to find against NALT.
	 * Also, set length of pattern and find minimum pattern length.
	 */
	nalt = 0;
	altmin = NMUSH;
	for (start = stop = regexpr;; ++stop)
		if (!*stop || *stop == '|' || *stop == NL) {
			altlen[nalt] = j = stop - start;
			if (j < altmin)
				altmin = j;
			if (!(altpat[nalt] = malloc((u_int)(j + 1))))
				oops("out of memory");
			bcopy(start, altpat[nalt], j);
			altpat[nalt][j] = EOS;
I 6
			++nalt;
E 6
			if (!*stop)
				break;
D 6
			if (++nalt == NALT)
E 6
I 6
			if (nalt == NALT)
E 6
				return(NULL);
			if (*stop == NL)
				*stop = '|';
			start = stop + 1;
		}
E 5
	if (!fgrepflag) {
		if (strchr(regexpr, '|') == NULL || regexpr[0] == '|')
			return (NULL);
		if (strpbrk(regexpr, "^$.[]()?+*\\") != NULL
		    || strindex(regexpr, "||") >= 0)
			return (NULL);
	}
D 5
	oflow[0] = EOS;
	nalt = sscanf(regexpr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]",
		      altpat[0], altpat[1], altpat[2], altpat[3], altpat[4], altpat[5], altpat[6], oflow);
E 5

D 5
	if (nalt < 1 || oflow[0] != EOS)
		return (NULL);

	altmin = NMUSH;
	for (j = 0; j < nalt; j++) {
		min = altlen[j] = strlen(altpat[j]);
		if (min > ALTSIZE)
			return (NULL);
		altmin = MIN(altmin, min);
	}
E 5
	if (nalt > 1) {		/* build superimposed "pre-match" sets per
				 * char */
		altflag++;
		for (j = 0; j < nalt; j++)
			for (i = 0; i < altmin; i++) {
				c = altpat[j][altlen[j] - altmin + i];
				altset[i + 1][c] = 1;	/* offset for sentinel */
			}
	}
	return (altpat[0]);
}

/*
 * Grapple with the dfa (std egrep) vs. ndfa (regexp) tradeoff. Criteria to
 * determine whether to use dfa-based egrep:  We do FIRSTFEW matches with
 * regexec().  If Boyer-Moore up to now matched more than PUNTPERCENT
 * of the input, the r.e. is likely to be underspecified, so do old *grep,
 * which is faster on complex patterns than regexp().  At FIRSTFEW,
 * dump the saved matches collected by savematch(). They are saved
 * so that a "PUNT" can "rewind" to ignore them.  Stdin is problematic,
 * since it's hard to rewind. 
 */

execstrategy(file)
	char *file;
{
	int pctmatch;

	pctmatch = (100 * rxcount) / incount;
	if (pctmatch > PUNTPERCENT && file != NULL)
		kernighan(args);
	if (file != NULL)
		flushmatches();
}

nlcount(bstart, bstop)		/* flail interval to totalize newlines. */
	char *bstart, *bstop;
{
	register char *s = bstart;
	register char *t = bstop;
	register int count = 0;

	do {			/* loop unroll for older architectures */
		if (*t == NL)	/* ... ask ames!jaw for sample code */
			count++;
	} while (t-- > s);

	return (count);
}

char *
isolate(regexpr)		/* isolate longest metacharacter-free string */
	char *regexpr;
{
	char *dummyexpr;

	/*
	 * We add (.)* because Henry's regcomp only figures regmust if it
	 * sees a leading * pattern.  Foo! 
	 */
	dummyexpr = malloc((unsigned) strlen(regexpr) + 5);
D 11
	sprintf(dummyexpr, "(.)*%s", regexpr);
E 11
I 11
	(void)sprintf(dummyexpr, "(.)*%s", regexpr);
E 11
	if ((rspencer = regcomp(dummyexpr)) == NULL)
		kernighan(args);
	return (rspencer->regmust);
}

char *matches[FIRSTFEW];
static int mcount = 0;

char *
savematch(s)			/* horde matches during statistics gathering */
	register char *s;
{
	char *p;
	char *start = s;
	int msize = 0;
	int psize = strlen(preamble);

	while (*s++ != NL)
		msize++;
	*--s = EOS;

	p = malloc((unsigned) msize + 1 + psize);
	strcpy(p, preamble);
	strcpy(p + psize, start);
	matches[mcount++] = p;

	preamble[0] = 0;
	*s = NL;
	return (s);
}

flushmatches()
{
	int n;

	flushflag = 1;
	for (n = 0; n < mcount; n++)
		printf("%s\n", matches[n]);
	mcount = 0;
}

oops(message)
	char *message;
{
	fprintf(stderr, "%s: %s\n", progname, message);
	exit(2);
}

kernighan(args)			/* "let others do the hard part ..." */
	char *args[];
{
	/*
	 * We may have already run grep on some of the files; remove them
	 * from the arg list we pass on.  Note that we can't delete them
	 * totally because the number of file names affects the output
	 * (automatic -h). 
	 */
	/* better would be fork/exec per punted file -- jaw */

	while (firstfile && optind > firstfile)
		args[firstfile++] = "/dev/null";
	if (patind)
		args[patind] = pattern;
D 5
	fflush(stdout);
E 5
I 5
	(void) fflush(stdout);
E 5

	if (grepflag)
		execvp(GREPSTD, args), oops("can't exec old 'grep'");
	else if (fgrepflag)
		execvp(FGREPSTD, args), oops("can't exec old 'fgrep'");
	else
		execvp(EGREPSTD, args), oops("can't exec old 'egrep'");
}
E 1
