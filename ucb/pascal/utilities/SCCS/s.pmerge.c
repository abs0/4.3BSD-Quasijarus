h11100
s 00014/00002/00406
d D 5.1 85/06/05 16:29:42 dist 5 4
c Add copyright
e
s 00013/00013/00395
d D 1.4 83/12/08 05:28:53 peter 4 3
c strcmpn changes to strncmp to confuse the innocent
e
s 00047/00010/00361
d D 1.3 82/12/07 11:55:08 garrison 3 2
c Added multiple string tables. Fixed bugs in handling of proc params.
e
s 00004/00002/00367
d D 1.2 81/06/09 12:32:39 mckusic 2 1
c allow non-alphanumerics in include file names
e
s 00369/00000/00000
d D 1.1 81/04/21 00:22:14 mckusick 1 0
c date and time created 81/04/21 00:22:14 by mckusick
e
u
U
t
T
I 1
D 5
/* Copyright (c) 1979 Regents of the University of California */
E 5
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 5

D 5
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5

#include <ctype.h>
#include <stdio.h>
#include <signal.h>

#define PRGFILE 0
#define LABELFILE 1
#define CONSTFILE 2
#define TYPEFILE 3
#define VARFILE 4
#define RTNFILE 5
#define BODYFILE 6
#define NUMFILES 7

#define TRUE 1
#define FALSE 0
#define MAXINCL 9
#define MAXNAM 75
#define TMPNAME "/usr/tmp/MGXXXXXX"

FILE	*files[NUMFILES];
char	*names[NUMFILES];
FILE	*curfile;		/* current output file */
FILE	*fopen();
char	labelopen = FALSE, constopen = FALSE, typeopen = FALSE, varopen = FALSE;
char	*mktemp();
I 3
char	*malloc();
E 3

/*
 * Remove temporary files if interrupted
 */
onintr()
{
	int i;

	for (i = 0; i < NUMFILES; i++)
		if (files[i] != NULL)
			unlink(names[i]);
}

/*
 * Program to merge separately compiled pascal modules into a
 * single standard Pascal program.
 */
main(argc, argv)
	long argc;
	char **argv;
{
	FILE	*incl[MAXINCL];	/* include stack */
	long	inclcnt = 0;	/* incl index */
	char	*name[MAXNAM];	/* include names seen so far */
	long	namcnt = 0;	/* next name ptr slot available */
D 3
	char	nambuf[BUFSIZ];	/* string table for names */
E 3
I 3
	char	*nambuf;	/* string table for names */
E 3
	char	line[BUFSIZ];	/* input line buffer */
D 3
	char	*next = nambuf;	/* next name space available */
E 3
I 3
	char	*next;		/* next name space available */
E 3
	FILE	*input = stdin;	/* current input file */
	long	ac = 0;		/* argv index */
	char	**cpp, *cp, *fp;/* char ptrs */
I 2
	char	quote;		/* include quote character */
E 2
	int	i;		/* index var */

I 3
	for (i = 0; i < MAXNAM ; i++)
		name[i] = 0;

E 3
	signal(SIGINT, onintr);
I 3

E 3
	curfile = files[PRGFILE] = fopen(names[PRGFILE] = mktemp(TMPNAME), "w");
	files[LABELFILE] = fopen(names[LABELFILE] = mktemp(TMPNAME), "w");
	files[CONSTFILE] = fopen(names[CONSTFILE] = mktemp(TMPNAME), "w");
	files[TYPEFILE] = fopen(names[TYPEFILE] = mktemp(TMPNAME), "w");
	files[VARFILE] = fopen(names[VARFILE] = mktemp(TMPNAME), "w");
	files[RTNFILE] = fopen(names[RTNFILE] = mktemp(TMPNAME), "w");
	files[BODYFILE] = fopen(names[BODYFILE] = mktemp(TMPNAME), "w");
I 3

E 3
	for (i = 0; i < NUMFILES; i++)
		if (files[i] == NULL)
			quit(names[i]);
I 3
	if ((nambuf = malloc(BUFSIZ)) == NULL) {
		fputs("no space for string table\n", stderr);
		quit(NULL);
	}
	next = nambuf;
E 3
	name[namcnt] = next;
	for(;;) {
		if (inclcnt > 0) {
			inclcnt--;
			fclose(input);
			input = incl[inclcnt];
		} else if (++ac < argc) {
			input = freopen(argv[ac], "r", input);
			if (input == NULL)
				quit(argv[ac]);
		} else {
			printout();
			onintr();
			exit(0);
		}
		fgets(line, BUFSIZ, input);
		while (!feof(input)) {
			if (line[0] != '#') {
				split(line);
				fgets(line, BUFSIZ, input);
				continue;
			}
			for (cp = &line[1]; isspace(*cp); cp++)
				/* void */;
D 4
			if (strcmpn("include", cp, 7))
E 4
I 4
			if (strncmp("include", cp, 7))
E 4
				goto bad;
			for (cp += 7; isspace(*cp); cp++)
				/* void */;
			if (*cp != '\'' && *cp != '"')
				goto bad;
I 3
			if (&nambuf[BUFSIZ] < next + strlen(cp)) {
				if ((nambuf = malloc(BUFSIZ)) == NULL) {
					fputs("no space for string table\n",
						stderr);
					quit(NULL);
				}
				next = nambuf;
				name[namcnt] = next;
			}
E 3
D 2
			for (fp = next, cp++; isalnum(*cp) || *cp == '.';)
E 2
I 2
			for (fp = next, quote = *cp++;
			     *cp != '\0' && *cp != quote; )
E 2
				*fp++ = *cp++;
D 2
			if ((*cp != '\'' || *cp != '"') &&
E 2
I 2
			if (*cp != quote &&
E 2
			    (fp[-1] != 'i' || fp[-1] != 'h') &&
			    (fp[-2] != '.'))
				goto bad;
			*fp++ = '\0';
			for (cpp = name; *cpp < next && strcmp(*cpp, next); )
				cpp++;
			if (*cpp == next) {
				if (inclcnt == MAXINCL) {
					fputs("include table overflow\n",
						stderr);
					quit(NULL);
				}
D 3
				if (namcnt++ == MAXNAM) {
E 3
I 3
				if (++namcnt == MAXNAM) {
E 3
					fputs("include name table overflow\n",
						stderr);
					quit(NULL);
				}
				incl[inclcnt] = input;
				inclcnt++;
				input = fopen(next, "r");
				if (input == NULL)
					quit(next);
				next = fp;
				name[namcnt] = next;
			}
			fgets(line, BUFSIZ, input);
		}
	}
bad:
	fputs("bad include format:", stderr);
	fputs(line, stderr);
	quit(NULL);
}

/*
 * Split up output into the approprite files
 */
char incom = FALSE;	/* TRUE => in comment */
char incur = FALSE;	/* TRUE => in (* *) style comment */
char inbrac = FALSE;	/* TRUE => in { } style comment */
char instr = FALSE;	/* TRUE => in quoted string */
char inprog = FALSE;	/* TRUE => program statement has been found */
int  beginnest = 0;	/* routine nesting level */
int  nest = 0;		/* begin block nesting level */
I 3
int  paren_level = 0;	/* nesting level of parentheses */
E 3

split(line)
	char *line;
{
	char ch1, *cp;		/* input window */
	char *word;		/* ptr to current word */
	int len;		/* length of current word */
	char prt = TRUE;	/* TRUE => print current word */

	ch1 = ' ';
	cp = line;
	while (*cp) {
		switch(*cp) {
D 3
		case '*':
			if (!incom && ch1 == '(') {
E 3
I 3
		case '(':
			if (incom)
				break;
			if (*(cp+1) == '*') {
				fputc(*cp, curfile);
				cp++;
E 3
				incom = TRUE;
				incur = TRUE;
I 3
			} else {
				paren_level++;
E 3
			}
			break;
		case ')':
			if (incur && ch1 == '*') {
				incom = FALSE;
				incur = FALSE;
I 3
			} else if (!incom) {
				paren_level--;
E 3
			}
			break;
		case '{':
			if (!incom) {
				inbrac = TRUE;
				incom = TRUE;
			}
			break;
		case '}':
			if (inbrac) {
				inbrac = FALSE;
				incom = FALSE;
			}
			break;
		case '\'':
			if (!incom) {
				incom = TRUE;
				instr = TRUE;
			} else if (instr) {
				incom = FALSE;
				instr = FALSE;
			}
			break;
		}
		if (incom || !isalpha(*cp)) {
			fputc(*cp, curfile);
			ch1 = *cp++;
			continue;
		}
		word = cp;
D 3
		while (isalpha(*cp))
E 3
I 3
		while (isalnum(*cp))
E 3
			cp++;
		len = cp - word;
		switch (*word) {
		case 'b':
D 4
			if (len == 5 && !strcmpn(word, "begin", 5)) {
E 4
I 4
			if (len == 5 && !strncmp(word, "begin", 5)) {
E 4
				if (nest == 0 && beginnest == 0) {
					if (inprog != 1) {
						fprintf(stderr,
						    "improper program body");
						quit(NULL);
					}
					curfile = files[BODYFILE];
				} else {
					beginnest++;
				}
			}
			break;
		case 'c':
D 4
			if (len == 4 && !strcmpn(word, "case", 4)) {
E 4
I 4
			if (len == 4 && !strncmp(word, "case", 4)) {
E 4
				if (beginnest > 0) {
					beginnest++;
				}
				break;
			}
D 4
			if (len == 5 && !strcmpn(word, "const", 5)) {
E 4
I 4
			if (len == 5 && !strncmp(word, "const", 5)) {
E 4
				if (nest == 0) {
					prt = FALSE;
					if (!constopen) {
						constopen = TRUE;
						prt = TRUE;
					}
					curfile = files[CONSTFILE];
				}
			}
			break;
		case 'e':
D 4
			if (len == 3 && !strcmpn(word, "end", 3)) {
E 4
I 4
			if (len == 3 && !strncmp(word, "end", 3)) {
E 4
				if (beginnest == 1) {
					nest--;
				}
				if (beginnest > 0) {
					beginnest--;
				}
				if (nest < 0) {
					if (inprog == 1) {
						inprog = 0;
						nest = 0;
					} else {
						fprintf(stderr, "too many end statements");
						quit(NULL);
					}
				}
				break;
			}
D 4
			if (len == 8 && !strcmpn(word, "external", 8)) {
E 4
I 4
			if (len == 8 && !strncmp(word, "external", 8)) {
E 4
				fputs("forward", curfile);
				prt = FALSE;
D 3
				nest--;
E 3
I 3
				if (paren_level == 0) {
					nest--;
				}
E 3
			}
			break;
		case 'f':
D 4
			if (len == 8 && !strcmpn(word, "function", 8)) {
E 4
I 4
			if (len == 8 && !strncmp(word, "function", 8)) {
E 4
				if (nest == 0) {
					curfile = files[RTNFILE];
				}
D 3
				nest++;
E 3
I 3
				if (paren_level == 0) {
					nest++;
				}
E 3
				break;
			}
D 4
			if (len == 7 && !strcmpn(word, "forward", 7)) {
E 4
I 4
			if (len == 7 && !strncmp(word, "forward", 7)) {
E 4
D 3
				nest--;
E 3
I 3
				if (paren_level == 0) {
					nest--;
				}
E 3
			}
			break;
		case 'l':
D 4
			if (len == 5 && !strcmpn(word, "label", 5)) {
E 4
I 4
			if (len == 5 && !strncmp(word, "label", 5)) {
E 4
				if (nest == 0) {
					prt = FALSE;
					if (!labelopen) {
						labelopen = TRUE;
						prt = TRUE;
					}
					curfile = files[LABELFILE];
				}
			}
			break;
		case 'p':
D 4
			if (len == 9 && !strcmpn(word, "procedure", 9)) {
E 4
I 4
			if (len == 9 && !strncmp(word, "procedure", 9)) {
E 4
				if (nest == 0) {
					curfile = files[RTNFILE];
				}
D 3
				nest++;
E 3
I 3
				if (paren_level == 0) {
					nest++;
				}
E 3
				break;
			}
D 4
			if (len == 7 && !strcmpn(word, "program", 7)) {
E 4
I 4
			if (len == 7 && !strncmp(word, "program", 7)) {
E 4
				if (nest != 0) {
					fprintf(stderr, "improper program nesting");
					quit(NULL);
				}
				inprog = 1;
				curfile = files[PRGFILE];
			}
			break;
		case 't':
D 4
			if (len == 4 && !strcmpn(word, "type", 4)) {
E 4
I 4
			if (len == 4 && !strncmp(word, "type", 4)) {
E 4
				if (nest == 0) {
					prt = FALSE;
					if (!typeopen) {
						typeopen = TRUE;
						prt = TRUE;
					}
					curfile = files[TYPEFILE];
				}
			}
			break;
		case 'v':
D 4
			if (len == 3 && !strcmpn(word, "var", 3)) {
E 4
I 4
			if (len == 3 && !strncmp(word, "var", 3)) {
E 4
				if (nest == 0) {
					prt = FALSE;
					if (!varopen) {
						varopen = TRUE;
						prt = TRUE;
					}
					curfile = files[VARFILE];
				}
			}
			break;
		}
		if (prt)
			fprintf(curfile, "%.*s", len, word);
		prt = TRUE;
		ch1 = ' ';
	}
}

/*
 * Print out the merged result
 */
printout()
{
	FILE *fp;
	int i;
	char ch;

	for(i = 0; i < NUMFILES; i++) {
		fp = freopen(names[i], "r", files[i]);
		if (fp == NULL)
			quit(names[i]);
		ch = getc(fp);
		while (!feof(fp)) {
			putc(ch,stdout);
			ch = getc(fp);
		}
	}
}

/*
 * Die gracefully
 */
quit(fp)
	char *fp;
{
	if (fp != NULL)
		perror(fp);
	onintr();
	exit(1);
}
E 1
