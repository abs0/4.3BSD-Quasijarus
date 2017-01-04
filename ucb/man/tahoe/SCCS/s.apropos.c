h32074
s 00010/00005/00207
d D 5.6 88/06/29 19:42:45 bostic 7 6
c install approved copyright notice
e
s 00092/00061/00120
d D 5.5 88/03/28 11:22:20 bostic 6 5
c kernel normal format; fix whatis to look for full word tokens;
c redo match routines for both apropos and whatis, other minor whacking
e
s 00010/00004/00171
d D 5.4 87/12/16 15:39:12 bostic 5 4
c add Berkeley headers
e
s 00001/00002/00174
d D 5.3 87/07/30 10:25:59 bostic 4 3
c change DEFPATH to include new and local
e
s 00003/00003/00173
d D 5.2 87/06/30 19:17:14 bostic 3 1
c MAXLINELEN of 500 too small, lint fixes
e
s 00005/00005/00171
d R 5.2 87/06/30 19:16:03 bostic 2 1
c MAXLINELEN of 500 too small; lint errors
e
s 00176/00000/00000
d D 5.1 87/06/29 20:53:49 bostic 1 0
c date and time created 87/06/29 20:53:49 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
D 5
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
I 5
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 7
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 7
I 7
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
E 7
E 5
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1987 Regents of the University of California.\n\
 All rights reserved.\n";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif /* not lint */
E 5

#include <sys/param.h>
#include <stdio.h>
#include <ctype.h>
I 6
#include <strings.h>
E 6

D 4
#define	DEF_PATH	"/usr/man"		/* default man path */
E 4
I 4
#define	DEF_PATH	"/usr/man:/usr/new/man:/usr/local/man"
E 4
D 3
#define	MAXLINELEN	500			/* max line handled */
E 3
I 3
#define	MAXLINELEN	1000			/* max line handled */
E 3
D 6
#define	NO		0			/* no/false */
E 6
#define	WHATIS		"whatis"		/* database name */
D 6
#define	YES		1			/* yes/true */
E 6

D 6
static char	*myname;
E 6
I 6
#define	NO	0				/* no/false */
#define	YES	1				/* yes/true */
E 6

I 6
static char *myname;

E 6
main(argc, argv)
D 6
	int	argc;
	char	**argv;
E 6
I 6
	int argc;
	char **argv;
E 6
{
D 6
	extern char	*optarg;
	extern int	optind;
	register char	*beg, *end, **C;
	int	ch, foundman = NO, *found, isapropos,
		a_match(), w_match(), (*match)();
	char	*manpath = NULL,
		buf[MAXLINELEN + 1], fname[MAXPATHLEN + 1],
		wbuf[MAXLINELEN + 1],
		*getenv(), *index(), *malloc(), *rindex();
E 6
I 6
	extern char *optarg;
	extern int optind;
	register char *beg, *end, **C;
	int ch, foundman = NO, *found, isapropos;
	int a_match(), w_match(), (*match)();
	char *manpath = NULL, buf[MAXLINELEN + 1], fname[MAXPATHLEN + 1];
	char wbuf[MAXLINELEN + 1], *getenv(), *malloc();
E 6

	myname = (beg = rindex(*argv, '/')) ? beg + 1 : *argv;
	if (!strcmp(myname, "apropos")) {
		isapropos = YES;
		match = a_match;
	}
	else {
		isapropos = NO;
		match = w_match;
	}
	while ((ch = getopt(argc, argv, "M:P:")) != EOF)
		switch((char)ch) {
			case 'M':
			case 'P':		/* backward contemptible */
				manpath = optarg;
				break;
			case '?':
			default:
				usage();
		}
	argv += optind;
	argc -= optind;
	if (argc < 1)
		usage();

	if (!(manpath = getenv("MANPATH")))
		manpath = DEF_PATH;

	/*NOSTRICT*/
	if (!(found = (int *)malloc((u_int)argc))) {
		fprintf(stderr, "%s: out of space.\n", myname);
		exit(1);
	}
D 3
	bzero(found, argc * sizeof(int));	/* calloc is silly */
E 3
I 3
D 6
	bzero((char *)found, argc * sizeof(int));	/* calloc is silly */
E 6
I 6
	bzero((char *)found, argc * sizeof(int));
E 6
E 3

D 6
	if (!isapropos)
D 3
		for (C = argv; *C; ++C) {	/* trim full paths */
E 3
I 3
		for (C = argv; *C; ++C) {		/* trim full paths */
E 3
			if (beg = rindex(*C, '/'))
				*C = beg + 1;
		}
	for (C = argv; *C; ++C)			/* convert to lower-case */
		lowstr(*C, *C);
E 6
I 6
	if (isapropos)
		for (C = argv; *C; ++C)		/* convert to lower-case */
			lowstr(*C, *C);
	else for (C = argv; *C; ++C)		/* trim full paths */
		if (beg = rindex(*C, '/'))
			*C = beg + 1;
E 6

	for (beg = manpath; beg; beg = end) {	/* through path list */
		end = index(beg, ':');
		if (!end)
			(void)sprintf(fname, "%s/%s", beg, WHATIS);
		else {
			(void)sprintf(fname, "%.*s/%s", end - beg, beg, WHATIS);
			++end;
		}
I 6
		if (!freopen(fname, "r", stdin))
			continue;

E 6
						/* for each file found */
D 6
		if (freopen(fname, "r", stdin)) {
			foundman = YES;
			while (gets(buf)) {	/* read & convert to lcase */
E 6
I 6
		for (foundman = YES; gets(buf);) {
			if (isapropos)
E 6
				lowstr(buf, wbuf);
D 6
				for (C = argv; *C; ++C)
					if ((*match)(wbuf, *C)) {
						puts(buf);
						found[C - argv] = YES;
E 6
I 6
			else
				dashtrunc(buf, wbuf);
			for (C = argv; *C; ++C)
				if ((*match)(wbuf, *C)) {
					puts(buf);
					found[C - argv] = YES;
E 6

D 6
						/* only print line once */
						while (*++C)
							if ((*match)(wbuf, *C))
								found[C - argv] = YES;
						break;
					}
			}
E 6
I 6
					/* only print line once */
					while (*++C)
						if ((*match)(wbuf, *C))
							found[C - argv] = YES;
					break;
				}
E 6
		}
	}
	if (!foundman) {
		fprintf(stderr, "%s: no %s file found in %s.\n", myname, WHATIS, manpath);
		exit(1);
	}
D 6
	for (C = argv; *C; C++)
E 6
I 6
	for (C = argv; *C; ++C)
E 6
		if (!found[C - argv])
			printf("%s: %s\n", *C, isapropos ? "nothing appropriate" : "not found");
}

I 6
/*
 * a_match --
 *	match for apropos; anywhere the string appears
 */
E 6
static
a_match(bp, str)
D 6
	register char	*bp, *str;
E 6
I 6
	register char *bp, *str;
E 6
{
D 6
	register char	test, *Cs, *Cb;
E 6
I 6
	register int len;
	register char test;
E 6

	if (!*bp)
		return(NO);
D 6
	/* backward contemptible: everything matches empty string */
E 6
I 6
	/* backward compatible: everything matches empty string */
E 6
	if (!*str)
		return(YES);
D 6
	for (test = *str++; *bp;)
		if (test == *bp++) {
			Cs = str;
			Cb = bp;
			do {
				if (!*Cs)
					return(YES);
			} while (*Cb++ == *Cs++);
		}
E 6
I 6
	for (test = *str++, len = strlen(str); *bp;)
		if (test == *bp++ && !strncmp(bp, str, len))
			return(YES);
E 6
	return(NO);
}

I 6
/*
 * w_match --
 *	match for whatis; looks for full word match
 */
E 6
static
w_match(bp, str)
D 6
	register char	*bp, *str;
E 6
I 6
	register char *bp, *str;
E 6
{
D 6
	register char	test, *Cs, *Cb;
E 6
I 6
	register int len;
	register char *start;
E 6

	if (!*str || !*bp)
		return(NO);
D 6
	for (test = *str++; *bp;)
		if (test == *bp++) {
			for (Cs = str, Cb = bp; *Cs == *Cb; ++Cs, ++Cb);
			if (!*Cs && (isspace(*Cb) || *Cb == '(' || *Cb == ','))
				return(YES);
		}
E 6
I 6
	for (len = strlen(str);;) {
		for (; *bp && !isdigit(*bp) && !isalpha(*bp); ++bp);
		if (!*bp)
			break;
		for (start = bp++; *bp && (isdigit(*bp) || isalpha(*bp)); ++bp);
		if (bp - start == len && !strncasecmp(start, str, len))
			return(YES);
	}
E 6
	return(NO);
}

I 6
/*
 * dashtrunc --
 *	truncate a string at " - "
 */
E 6
static
D 6
lowstr(from, to)
	register char	*from, *to;
E 6
I 6
dashtrunc(from, to)
	register char *from, *to;
E 6
{
D 6
	for (; *from; ++from, ++to)
		*to = isupper(*from) ? tolower(*from) : *from;
E 6
I 6
	do {
		if (from[0] == ' ' && from[1] == '-' && from[2] == ' ')
			break;
	} while (*to++ = *from++);
E 6
	*to = '\0';
}

I 6
/*
 * lowstr --
 *	convert a string to lower case
 */
static
lowstr(from, to)
	register char *from, *to;
{
	do {
		*to++ = isupper(*from) ? tolower(*from) : *from;
	} while (*from++);
}

/*
 * usage --
 *	print usage message and die
 */
E 6
static
usage()
{
	fprintf(stderr, "usage: %s [-M path] string ...\n", myname);
	exit(1);
}
D 4

E 4
E 1
