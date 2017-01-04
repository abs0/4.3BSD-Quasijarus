h30386
s 00007/00005/00662
d D 5.2 86/07/17 14:52:19 donn 19 18
c Fix bug that put the date of the next file in the footer on the last page
c of the current file.
e
s 00009/00001/00658
d D 5.1 85/06/05 09:43:33 dist 18 17
c Add copyright
e
s 00002/00001/00657
d D 4.2 84/12/11 16:59:38 ralph 17 16
c null pointer & missing subroutine argument fixes
e
s 00002/00000/00656
d D 4.1 82/10/21 18:03:39 mckusick 16 15
c add sccs keywords
e
s 00041/00003/00615
d D 1.13 81/06/11 17:00:46 presott 15 14
c I've added an alternate comment to allow comment nesting in PASCAL - resotto
e
s 00004/00004/00614
d D 1.12 81/03/29 01:22:31 presott 14 13
c The macro definition names have been changed to not interfere
c with other macro packages for troff.
e
s 00002/00002/00616
d D 1.11 81/03/15 16:15:32 presott 13 12
c fix the last delta
e
s 00002/00000/00616
d D 1.10 81/03/15 16:13:44 presott 12 11
c make the header and footer info dependent on the -f option
e
s 00005/00001/00611
d D 1.9 81/02/14 14:18:22 root 11 10
c I made the asterisks in the 'c' comments line up
c correctly once again. -- presotto
e
s 00012/00013/00600
d D 1.8 81/01/31 03:12:45 root 10 8
c I broke the index feature when I threw my stuff in.  This fixes it.
c -- presotto
e
s 00200/00496/00117
d R 1.8 81/01/31 02:58:48 root 9 8
c I broke the index feature when I table drove vgrind.  This is a
c simple fix to get it back.
e
s 00001/00001/00612
d D 1.7 81/01/27 15:47:45 root 8 7
c When the procedure name stack overflowed a new line didn't get printed
c after an FN.  I fixed this. -- presotto
e
s 00004/00004/00609
d D 1.6 81/01/21 00:15:03 root 7 6
c My brain was in neutral when last I worked on this.  I've
c just fixed some typeo's that caused errors when both strings and
c blocks started on the same line. -- presotto
e
s 00460/00700/00153
d D 1.5 81/01/20 00:52:41 root 6 5
c a totally new table driven vgrind -- presotto
e
s 00001/00001/00852
d D 1.4 81/01/11 16:22:44 root 5 4
c Fixed the number of languages -- presotto
e
s 00234/00040/00619
d D 1.3 80/12/07 03:46:46 root 4 2
c Three changes:
c 1) ISP was added to vgrind (using the -i option)
c 2) The second comment type was added for PASCAL
c 3) a -s switch was added to control font size
e
s 00006/00001/00658
d D 1.2.1.1 80/11/30 16:46:26 eric 3 2
c handle form feeds anywhere
e
s 00411/00069/00248
d D 1.2 80/11/30 16:16:51 root 2 1
c (presotto) make table-driven
e
s 00317/00000/00000
d D 1.1 80/11/30 15:55:21 root 1 0
c date and time created 80/11/30 15:55:21 by root
e
u
U
t
T
I 16
D 18
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 18
I 18
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 18

E 16
I 1
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

I 6
#define boolean int
#define TRUE 1
#define FALSE 0
#define NIL 0
I 15
#define STANDARD 0
#define ALTERNATE 1
E 15

E 6
/*
 * Vfontedpr.
 *
D 6
 * Bill Joy, Apr. 1979.
I 2
D 4
 * (made table driven - Dave Presotto 11/17/80)
E 4
I 4
 * (made somewhat table driven - Dave Presotto 11/17/80)
E 6
I 6
 * Dave Presotto 1/12/81 (adapted from an earlier version by Bill Joy)
E 6
E 4
 *
I 4
D 6
 * To add a new language:
 *	1) add a new keyword table
 *	2) add a new entry to "struct langdef ld[]" to
 *	   describe comments, strings, etc.
 *	3) add two routines to recognize start and end of 
 *	   procedures
 *
E 6
E 4
E 2
 */
I 2
D 6
#define NOLANG -1		/* indicates no language chosen */
#define C 0
#define PASCAL 1
#define MODEL 2
D 5
#define NLANG 3			/* total number of languages */
E 5
I 5
#define NLANG 4			/* total number of languages */
E 6
E 5

#define STRLEN 10		/* length of strings introducing things */
#define PNAMELEN 40		/* length of a function/procedure name */
I 6
#define PSMAX 20		/* size of procedure name stacking */
E 6

D 6
/* routines used by the different languages */
E 6
I 6
/* regular expression routines */
E 6

D 6
int	cprbegin();
int	cprend();
I 4
int	iprbegin();
int	iprend();
E 4
int	pprbegin();
int	pprend();
int	mprbegin();
int	mprend();
E 6
I 6
char	*expmatch();		/* match a string to an expression */
char	*STRNCMP();		/* a different kindof strncmp */
char	*convexp();		/* convert expression to internal form */
I 17
char	*tgetstr();
E 17
E 6

D 6
/* keywords for the model language */
E 6
I 6
boolean	isproc();
E 6

D 6
char	*mkw[] = {
	"abs",
	"and",
	"array",
	"beginproc",
	"boolean",
	"by",
	"case",
	"cdnl",
	"char",
	"copied",
	"dispose",
	"div",
	"do",
	"dynamic",
	"else",
	"elsif",
	"end",
	"endproc",
	"entry",
	"external",
	"f",
	"FALSE",
	"false",
	"fi",
	"file",
	"for",
	"formal",
	"fortran",
	"global",
	"if",
	"in",
	"include",
	"inline",
	"is",
	"lbnd",
	"max",
	"min",
	"mod",
	"new",
	"NIL",
	"nil",
	"noresult",
	"not",
	"notin",
	"od",
	"of",
	"or",
	"procedure",
	"public",
	"read",
	"readln",
	"readonly",
	"record",
	"recursive",
	"rem",
	"rep",
	"repeat",
	"result",
	"return",
	"set",
	"space",
	"string",
	"subscript",
	"such",
	"then",
	"TRUE",
	"true",
	"type",
	"ubnd",
	"union",
	"until",
	"varies",
	"while",
	"width",
	"write",
	"writeln",
	0,
};
E 6

D 6
/* keywords for the pascal language */
E 6
I 6
char	*ctime();
E 6

D 6
char	*pkw[] = {
	"and",
	"array",
	"assert",
	"begin",
	"case",
	"const",
	"div",
	"do",
	"downto",
	"else",
	"end",
	"file",
	"for",
	"forward",
	"function",
	"goto",
	"if",
	"in",
	"label",
	"mod",
	"nil",
	"not",
	"of",
	"or",
	"packed",
	"procedure",
	"program",
	"record",
	"repeat",
	"set",
	"then",
	"to",
	"type",
	"until",
	"var",
	"while",
	"with",
	"oct",
	"hex",
	"external",
	0,
};
E 6
I 6
/*
 *	The state variables
 */
E 6

D 6
/* keywords for the C language */
E 6
I 6
boolean	incomm;			/* in a comment of the primary type */
boolean	instr;			/* in a string constant */
boolean	inchr;			/* in a string constant */
boolean	nokeyw = FALSE;		/* no keywords being flagged */
boolean	index = FALSE;		/* form an index */
boolean filter = FALSE;		/* act as a filter (like eqn) */
boolean pass = FALSE;		/* when acting as a filter, pass indicates
				 * whether we are currently processing
				 * input.
				 */
boolean prccont;		/* continue last procedure */
I 15
int	comtype;		/* type of comment */
E 15
int	margin;
int	psptr;			/* the stack index of the current procedure */
char	pstack[PSMAX][PNAMELEN+1];	/* the procedure name stack */
int	plstack[PSMAX];		/* the procedure nesting level stack */
int	blklevel;		/* current nesting level */
char	*defsfile = "/usr/lib/vgrindefs";	/* name of language definitions file */
char	pname[BUFSIZ+1];
E 6

D 6
char	*ckw[] = {
	"asm",
	"auto",
	"break",
	"case",
	"char",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extern",
	"float",
	"for",
	"fortran",
	"goto",
	"if",
	"int",
	"long",
	"register",
	"return",
	"short",
	"sizeof",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"while",
	"#define",
	"#else",
	"#endif",
	"#if",
	"#ifdef",
	"#ifndef",
	"#include",
	"#undef",
	"#",
	"define",
	"else",
	"endif",
	"if",
	"ifdef",
	"ifndef",
	"include",
	"undef",
	0,
};
E 6
I 6
/*
 *	The language specific globals
 */
E 6

I 4
D 6
/* keywords for the ISP language */
E 6
I 6
char	*language = "c";	/* the language indicator */
char	*l_keywds[BUFSIZ/2];	/* keyword table address */
char	*l_prcbeg;		/* regular expr for procedure begin */
char	*l_combeg;		/* string introducing a comment */
char	*l_comend;		/* string ending a comment */
I 15
char	*l_acmbeg;		/* string introducing a comment */
char	*l_acmend;		/* string ending a comment */
E 15
char	*l_blkbeg;		/* string begining of a block */
char	*l_blkend;		/* string ending a block */
char    *l_strbeg;		/* delimiter for string constant */
char    *l_strend;		/* delimiter for string constant */
char    *l_chrbeg;		/* delimiter for character constant */
char    *l_chrend;		/* delimiter for character constant */
char	l_escape;		/* character used to  escape characters */
boolean	l_toplex;		/* procedures only defined at top lex level */
E 6

D 6
char	*ikw[] = {
	"and",
	"begin",
	"decode",
	"define",
	"end",
	"eql",
	"eqv",
	"geq",
	"gtr",
	"if",
	"leave",
	"leq",
	"lss",
	"mod",
	"neq",
	"next",
	"not",
	"or",
	"otherwise",
	"repeat",
	"restart",
	"resume",
	"sr0",
	"sr1",
	"srd",
	"srr",
	"sl0",
	"sl1",
	"sld",
	"slr",
	"tst",
	"xor",
	0,
};

E 6
E 4
/*
D 6
 * the following structure defines a language
E 6
I 6
 *  global variables also used by expmatch
E 6
 */
I 6
boolean _escaped;		/* if last character was an escape */
char *_start;			/* start of the current string */
boolean	l_onecase;		/* upper and lower case are equivalent */
E 6

D 6
struct langdef {
	char	*option;	/* its option switch */
	char	**kwd;		/* address of its keyword table */
	int	(*isproc)();	/* test for procedure begin */
	int	(*ispend)();	/* test for procedure end */
	char	*combeg;	/* string introducing a comment */
	char	*comend;	/* string ending a comment */
	char	*comout;	/* string output in place of combeg string */
I 4
	char	*acmbeg;	/* alternate comment start */
	char	*acmend;	/* alternate comment end */
	char	*acmout;	/* alternate comment start preface */
E 4
	char    strdel;		/* delimiter for string constant */
	char	chrdel;		/* delimiter for character constant */
	int	onelncom;	/* comments do not continue on next line */
	int	onelnstr;	/* string constants do not continue on next */
I 4
	int	onecase;	/* upper and lower case are equivalent */
E 4
};
E 6
I 6
#define	ps(x)	printf("%s", x)
E 6

D 6
struct langdef ld[] = {
	/* the C language */
	"-c",
D 4
	ckw,
	cprbegin,
	cprend,
	"/*",
	"*/",
	"\\*(/*",
	'"',
	'\'',
	0,
	0,
E 4
I 4
	ckw,		/* kwd */
	cprbegin,	/* isproc */
	cprend,		/* ispend */
	"/*",		/* combeg */
	"*/",		/* comend */
	"\\*(/*",	/* comout */
	0,		/* acmbeg */
	0,		/* acmend */
	0,		/* acmout */
	'"',		/* strdel */
	'\'',		/* chrdel */
	0,		/* onelncom */
	0,		/* onelnstr */
	0,		/* onecase */
E 6
I 6
main(argc, argv)
    int argc;
    char *argv[];
{
    int lineno;
    char *fname = "";
    char *ptr;
    struct stat stbuf;
    char buf[BUFSIZ];
    char strings[2 * BUFSIZ];
    char defs[2 * BUFSIZ];
    int needbp = 0;
E 6
E 4

I 4
D 6
	/* the ISP language */
	"-i",
	ikw,		/* kwd */
	iprbegin,	/* isproc */
	iprend,		/* ispend */
	"!",		/* combeg */
	0,		/* comend */
	"!",		/* comout */
	0,		/* acmbeg */
	0,		/* acmend */
	0,		/* acmout */
	0,		/* strdel */
	0,		/* chrdel */
	1,		/* onelncom */
	1,		/* onelnstr */
	1,		/* onecase */
E 6
I 6
    argc--, argv++;
    do {
	char *cp;
	int i;
E 6

E 4
D 6
	/* the pascal language */
	"-p",
D 4
	pkw,
	pprbegin,
	pprend,
	"{",
	"}",
	"{",
	'\'',
	0,
	0,
	0,
E 4
I 4
	pkw,		/* kwd */
	pprbegin,	/* isproc */
	pprend,		/* ispend */
	"{",		/* combeg */
	"}",		/* comend */
	"{",		/* comout */
	"(*",		/* acmbeg */
	"*)",		/* acmend */
	"(*",		/* acmout */
	'\'',		/* strdel */
	0,		/* chrdel */
	0,		/* onelncom */
	0,		/* onelnstr */
	0,		/* onecase */
E 6
I 6
	if (argc > 0) {
	    if (!strcmp(argv[0], "-h")) {
		if (argc == 1) {
		    printf("'ds =H\n");
		    argc = 0;
		    goto rest;
		}
		printf("'ds =H %s\n", argv[1]);
D 14
		argc -= 2;
		argv += 2;
E 14
I 14
		argc--, argv++;
		argc--, argv++;
E 14
		if (argc > 0)
		    continue;
		goto rest;
	    }
E 6
E 4

D 6
	/* the model language */
	"-m",
D 4
	mkw,
	mprbegin,
	mprend,
	"$",
	"$",
	"$",
	'"',
	'\'',
	1,
	0
E 4
I 4
	mkw,		/* kwd */
	mprbegin,	/* isproc */
	mprend,		/* ispend */
	"$",		/* combeg */
	"$",		/* comend */
	"$",		/* comout */
	0,		/* acmbeg */
	0,		/* acmend */
	0,		/* acmout */
	'"',		/* strdel */
	'\'',		/* chrdel */
	1,		/* onelncom */
	0,		/* onelnstr */
	0,		/* onecase */
E 4
};
E 6
I 6
	    /* act as a filter like eqn */
	    if (!strcmp(argv[0], "-f")) {
		filter++;
		argv[0] = argv[argc-1];
		argv[argc-1] = "-";
		continue;
	    }
E 6

E 2
D 6
char	*ctime();
D 4
int	incomm;
int	instr;
E 4
I 4
int	incomm;			/* in a comment of the primary type */
int	inacomm;		/* in the alternate type of comment */
int	instr;			/* in a string constant */
E 4
int	nokeyw;
int	index;
int	margin;
E 6
I 6
	    /* take input from the standard place */
	    if (!strcmp(argv[0], "-")) {
		argc = 0;
		goto rest;
	    }
E 6
I 4

E 4
I 2
D 6
char	*comcol;		/* character position comment starts in */
int	language = NOLANG;	/* the language indicator */
char	**keywds;		/* keyword table address */
int	(*isprbeg)();		/* test for beginning of procedure */
int	(*isprend)();		/* test for end of procedure */
char	*cstart;		/* start of comment string */
char	*cstop;			/* end of comment string */
char	*cout;			/* string to substitute for cstart */
int	lcstart;		/* length of comment string starter */
int	lcstop;			/* length of comment string terminator */
I 4
char	*acstart;		/* start of comment string */
char	*acstop;		/* end of comment string */
char	*acout;			/* string to substitute for cstart */
int	lacstart;		/* length of comment string starter */
int	lacstop;		/* length of comment string terminator */
E 4
char	sdelim;			/* string constant delimiter */
char	cdelim;			/* character constant delimiter */
int	com1line;		/* one line comments */
int	str1line;		/* one line strings */
I 4
int	upeqlow;		/* upper and lower case equivalent */
E 4
char	pname[PNAMELEN];
E 6
I 6
	    /* build an index */
	    if (!strcmp(argv[0], "-x")) {
		index++;
		argv[0] = "-n";
	    }
E 6
E 2

I 2
D 6
#define	ps(x)	printf("%s", x)
E 6
I 6
	    /* indicate no keywords */
	    if (!strcmp(argv[0], "-n")) {
		nokeyw++;
		argc--, argv++;
		continue;
	    }
E 6

E 2
D 6
main(argc, argv)
	int argc;
	char *argv[];
{
	int lineno;
	char *fname = "";
	struct stat stbuf;
	char buf[BUFSIZ];
	int needbp = 0;
E 6
I 6
	    /* specify the font size */
	    if (!strncmp(argv[0], "-s", 2)) {
		i = 0;
		cp = argv[0] + 2;
		while (*cp)
		    i = i * 10 + (*cp++ - '0');
		printf("'ps %d\n'vs %d\n", i, i+1);
		argc--, argv++;
		continue;
	    }
E 6

D 6
	argc--, argv++;
	do {
		char *cp;
I 2
		int i;
E 6
I 6
	    /* specify the language */
	    if (!strncmp(argv[0], "-l", 2)) {
		language = argv[0]+2;
		argc--, argv++;
		continue;
	    }
E 6
E 2

D 6
		if (argc > 0) {
			if (!strcmp(argv[0], "-h")) {
				if (argc == 1) {
					printf("'ds =H\n");
					argc = 0;
					goto rest;
				}
				printf("'ds =H %s\n", argv[1]);
				argc -= 2;
				argv += 2;
				if (argc > 0)
					continue;
				goto rest;
			}
			if (!strcmp(argv[0], "-x")) {
				index++;
				argv[0] = "-n";
			}
			if (!strcmp(argv[0], "-n")) {
				nokeyw++;
				argc--, argv++;
				continue;
			}
I 4
			if (!strncmp(argv[0], "-s", 2)) {
				i = 0;
				cp = argv[0] + 2;
				while (*cp)
					i = i * 10 + (*cp++ - '0');
				printf("'ps %d\n'vs %d\n", i, i+1);
				argc--, argv++;
				continue;
			}
E 4
I 2
			for (i = 0; i < NLANG; i++)
				if (!strcmp(argv[0], ld[i].option)) {
					language = i;
					break;
				}
			if (i != NLANG) {
				argc--, argv++;
				continue;
			}
E 2
			if (freopen(argv[0], "r", stdin) == NULL) {
				perror(argv[0]);
				exit(1);
			}
			if (index)
				printf("'ta 4i 4.25i 5.5iR\n'in .5i\n");
			fname = argv[0];
			argc--, argv++;
		}
rest:
I 2
		if (language == NOLANG)
			language = C;		/* C is the default */
E 6
I 6
	    /* specify the language description file */
	    if (!strncmp(argv[0], "-d", 2)) {
		defsfile = argv[1];
		argc--, argv++;
		argc--, argv++;
		continue;
	    }
E 6

D 6
		/* initialize for the appropriate language */
I 4
		/* This is done because subscripting is too */
		/* damned slow to be done every reference */
E 6
I 6
	    /* open the file for input */
	    if (freopen(argv[0], "r", stdin) == NULL) {
		perror(argv[0]);
		exit(1);
	    }
	    if (index)
		printf("'ta 4i 4.25i 5.5iR\n'in .5i\n");
	    fname = argv[0];
	    argc--, argv++;
	}
    rest:
E 6
E 4

D 6
		keywds = ld[language].kwd;
		isprbeg = ld[language].isproc;
		isprend = ld[language].ispend;
E 6
I 6
	/*
	 *  get the  language definition from the defs file
	 */
	i = tgetent (defs, language, defsfile);
	if (i == 0) {
	    fprintf (stderr, "no entry for language %s\n", language);
	    exit (0);
	} else  if (i < 0) {
	    fprintf (stderr,  "cannot find vgrindefs file %s\n", defsfile);
	    exit (0);
	}
	cp = strings;
	if (tgetstr ("kw", &cp) == NIL)
	    nokeyw = TRUE;
	else  {
	    char **cpp;
E 6
I 4

E 4
D 6
		cstart = ld[language].combeg;
		cstop = ld[language].comend;
		cout = ld[language].comout;
		lcstart = strlen (cstart);
		lcstop = strlen (cstop);
E 6
I 6
	    cpp = l_keywds;
	    cp = strings;
	    while (*cp) {
		while (*cp == ' ' || *cp =='\t')
		    *cp++ = NULL;
		if (*cp)
		    *cpp++ = cp;
		while (*cp != ' ' && *cp  != '\t' && *cp)
		    cp++;
	    }
	    *cpp = NIL;
	}
	cp = buf;
	l_prcbeg = convexp (tgetstr ("pb", &cp));
	cp = buf;
	l_combeg = convexp (tgetstr ("cb", &cp));
	cp = buf;
	l_comend = convexp (tgetstr ("ce", &cp));
	cp = buf;
I 15
	l_acmbeg = convexp (tgetstr ("ab", &cp));
	cp = buf;
	l_acmend = convexp (tgetstr ("ae", &cp));
	cp = buf;
E 15
	l_strbeg = convexp (tgetstr ("sb", &cp));
	cp = buf;
	l_strend = convexp (tgetstr ("se", &cp));
	cp = buf;
	l_blkbeg = convexp (tgetstr ("bb", &cp));
	cp = buf;
	l_blkend = convexp (tgetstr ("be", &cp));
	cp = buf;
	l_chrbeg = convexp (tgetstr ("lb", &cp));
	cp = buf;
	l_chrend = convexp (tgetstr ("le", &cp));
	l_escape = '\\';
	l_onecase = tgetflag ("oc");
	l_toplex = tgetflag ("tl");
I 15

E 15
	/* initialize the program */
E 6
I 4

D 6
		acstart = ld[language].acmbeg;
		acstop = ld[language].acmend;
		acout = ld[language].acmout;
		lacstart = strlen (acstart);
		lacstop = strlen (acstop);
E 6
I 6
	incomm = FALSE;
	instr = FALSE;
	inchr = FALSE;
	_escaped = FALSE;
	blklevel = 0;
	for (psptr=0; psptr<PSMAX; psptr++) {
	    pstack[psptr][0] = NULL;
	    plstack[psptr] = 0;
	}
	psptr = -1;
	ps("'-F\n");
	if (!filter) {
	    printf(".ds =F %s\n", fname);
D 19
	    fstat(fileno(stdin), &stbuf);
	    cp = ctime(&stbuf.st_mtime);
	    cp[16] = '\0';
	    cp[24] = '\0';
	    printf(".ds =M %s %s\n", cp+4, cp+20);
E 19
I 12
D 13
	    ps("'wh 0 he");
	    ps("'wh -1i fo");
E 13
I 13
D 14
	    ps("'wh 0 he\n");
	    ps("'wh -1i fo\n");
E 14
I 14
	    ps("'wh 0 vH\n");
	    ps("'wh -1i vF\n");
E 14
E 13
E 12
	}
	if (needbp) {
	    needbp = 0;
	    printf(".()\n");
	    printf(".bp\n");
I 19
	}
	if (!filter) {
	    fstat(fileno(stdin), &stbuf);
	    cp = ctime(&stbuf.st_mtime);
	    cp[16] = '\0';
	    cp[24] = '\0';
	    printf(".ds =M %s %s\n", cp+4, cp+20);
E 19
	}
E 6

E 4
D 6
		sdelim = ld[language].strdel;
		cdelim = ld[language].chrdel;
		com1line = ld[language].onelncom;
		str1line = ld[language].onelnstr;
I 4
		upeqlow = ld[language].onecase;
E 4
		pname[0] = 0;

		/* initialize the program */

E 2
		incomm = 0;
I 4
		inacomm = 0;
E 4
		instr = 0;
I 4
		ps("'-F\n");
E 4
		printf(".ds =F %s\n", fname);
		fstat(fileno(stdin), &stbuf);
		cp = ctime(&stbuf.st_mtime);
		cp[16] = '\0';
		cp[24] = '\0';
		printf(".ds =M %s %s\n", cp+4, cp+20);
		if (needbp) {
			needbp = 0;
			printf(".()\n");
			printf(".bp\n");
		}
		while (fgets(buf, sizeof buf, stdin) != NULL) {
D 3
			if (buf[0] == '\f') {
E 3
I 3
			if (buf[0] == '\f' && buf[1] == '\n') {
E 3
				printf(".bp\n");
				continue;
			}
I 2
D 4
			if (com1line && incomm) {
E 4
I 4
			if (com1line && (incomm || inacomm)) {
E 4
				incomm = 0;
I 4
				inacomm = 0;
E 4
				ps("\\c\n'-C\n");
			}
			if (str1line)
				instr = 0;
			comcol = NULL;
E 2
			putScp(buf);
			if (buf[strlen(buf) - 2] != '\\')
				instr = 0;
			margin = 0;
		}
		needbp = 1;
	} while (argc > 0);
	exit(0);
E 6
I 6
	/*
	 *	MAIN LOOP!!!
	 */
	while (fgets(buf, sizeof buf, stdin) != NULL) {
	    if (buf[0] == '\f') {
		printf(".bp\n");
	    }
	    if (buf[0] == '.') {
		printf("%s", buf);
		if (!strncmp (buf+1, "vS", 2))
		    pass = TRUE;
		if (!strncmp (buf+1, "vE", 2))
		    pass = FALSE;
		continue;
	    }
	    prccont = FALSE;
	    if (!filter || pass)
		putScp(buf);
	    else
		printf("%s", buf);
	    if (prccont && (psptr >= 0)) {
		ps("'FC ");
		ps(pstack[psptr]);
		ps("\n");
	    }
#ifdef DEBUG
	    printf ("com %o str %o chr %o ptr %d\n", incomm, instr, inchr, psptr);
#endif
	    margin = 0;
	}
	needbp = 1;
    } while (argc > 0);
    exit(0);
E 6
}

D 2
#define	ps(x)	printf("%s", x)
E 2
#define isidchr(c) (isalnum(c) || (c) == '_')

putScp(os)
D 6
	char *os;
E 6
I 6
    char *os;
E 6
{
D 6
	register char *s = os;
	register int i;
	int xfld = 0;
E 6
I 6
    register char *s = os;		/* pointer to unmatched string */
    char dummy[BUFSIZ];			/* dummy to be used by expmatch */
D 10
    int xfld = 0;
E 10
    char *comptr;			/* end of a comment delimiter */
I 15
    char *acmptr;			/* end of a comment delimiter */
E 15
    char *strptr;			/* end of a string delimiter */
    char *chrptr;			/* end of a character const delimiter */
    char *blksptr;			/* end of a lexical block start */
    char *blkeptr;			/* end of a lexical block end */
E 6

D 2
	if (nokeyw)
E 2
I 2
D 4
	if (nokeyw || incomm || instr)
E 4
I 4
D 6
	if (nokeyw || incomm || inacomm || instr)
E 4
E 2
		goto skip;
D 2
	if ((*s == '_' || isalpha(*s)) && s[strlen(s) - 2] == ')') {
		register char *t = s + 1;

		while (isidchr(*t))
			t++;
E 2
I 2
	if ((*isprbeg)(s)) {
E 2
		ps("'FN ");
D 2
		while (s < t)
			putchar(*s++);
E 2
I 2
		ps(pname);
E 2
		ps("\n");
D 2
	} else if (!strcmp(s, "}\n"))
E 2
I 2
	} else if ((*isprend)(s))
E 2
		ps("'-F\n");
E 6
I 6
    _start = os;			/* remember the start for expmatch */
    _escaped = FALSE;
    if (nokeyw || incomm || instr)
	goto skip;
    if (isproc(s)) {
	ps("'FN ");
	ps(pname);
I 8
        ps("\n");
E 8
	if (psptr < PSMAX) {
	    ++psptr;
	    strncpy (pstack[psptr], pname, PNAMELEN);
	    pstack[psptr][PNAMELEN] = NULL;
D 8
	    ps("\n");
E 8
	    plstack[psptr] = blklevel;
	}
    } 
E 6
skip:
D 6
	while (*s) {
I 3
		if (*s == '\f') {
			ps("\n.bp\n");
			s++;
			continue;
		}
E 3
		if (index) {
			if (*s == ' ' || *s == '\t') {
				if (xfld == 0)	
					printf("");
				printf("\t");
				xfld = 1;
				while (*s == ' ' || *s == '\t')
					s++;
				continue;
			}
		}
E 6
I 6
    do {
D 10
	if (index) {
	    if (*s == ' ' || *s == '\t') {
		if (xfld == 0)	
		    printf("");
		printf("\t");
		xfld = 1;
		while (*s == ' ' || *s == '\t')
		    s++;
		continue;
	    }
	}
E 6
D 2
		if (!nokeyw && !incomm && *s == '"') {
E 2
I 2
D 4
		if (!nokeyw && !incomm && *s == sdelim) {
E 4
I 4

E 10
D 6
		/* 
		 *  for the following "really" hacked code, I
		 *  apologize. Creeping featurism got me. DLP
		 */
E 6
I 6
	/* check for string, comment, blockstart, etc */
	if (!incomm && !instr && !inchr) {
E 6

D 6
		/* check for the start of a string */
		if (!nokeyw && !(incomm || inacomm) && *s == sdelim) {
E 4
E 2
			if (instr) {
				if (s[-1] != '\\')
					instr = 0;
			} else
D 2
				if (s[-1] != '\'')
E 2
I 2
				if (s[-1] != cdelim)
E 2
					instr = 1;
E 6
I 6
	    blkeptr = expmatch (s, l_blkend, dummy);
	    blksptr = expmatch (s, l_blkbeg, dummy);
	    comptr = expmatch (s, l_combeg, dummy);
I 15
	    acmptr = expmatch (s, l_acmbeg, dummy);
E 15
	    strptr = expmatch (s, l_strbeg, dummy);
	    chrptr = expmatch (s, l_chrbeg, dummy);

	    /* start of a comment? */
	    if (comptr != NIL)
		if ((comptr < strptr || strptr == NIL)
I 15
		  && (comptr < acmptr || acmptr == NIL)
E 15
		  && (comptr < chrptr || chrptr == NIL)
		  && (comptr < blksptr || blksptr == NIL)
		  && (comptr < blkeptr || blkeptr == NIL)) {
		    putKcp (s, comptr-1, FALSE);
		    s = comptr;
		    incomm = TRUE;
I 15
		    comtype = STANDARD;
E 15
		    if (s != os)
			ps ("\\c");
		    ps ("\\c\n'+C\n");
		    continue;
E 6
		}
D 2
		if (incomm && s - os >= 2 && !strncmp("*/", s - 2, 2)) {
E 2
I 2
D 4
		if (incomm && comcol != s-1 && s - os >= lcstop && !strncmp(cstop, s - lcstop, lcstop)) {
E 4
I 4

I 15
	    /* start of a comment? */
	    if (acmptr != NIL)
		if ((acmptr < strptr || strptr == NIL)
		  && (acmptr < chrptr || chrptr == NIL)
		  && (acmptr < blksptr || blksptr == NIL)
		  && (acmptr < blkeptr || blkeptr == NIL)) {
		    putKcp (s, acmptr-1, FALSE);
		    s = acmptr;
		    incomm = TRUE;
		    comtype = ALTERNATE;
		    if (s != os)
			ps ("\\c");
		    ps ("\\c\n'+C\n");
		    continue;
		}

E 15
D 6
		/* check for the end of a comment */
		if (incomm && lcstop != 0 && comcol != s-1 && s - os >= lcstop 
		    && !strncmp(cstop, s - lcstop, lcstop)) {
E 4
E 2
			incomm = 0;
			ps("\\c\n'-C\n");
E 6
I 6
	    /* start of a string? */
	    if (strptr != NIL)
		if ((strptr < chrptr || chrptr == NIL)
D 7
		  && (comptr < blksptr || blksptr == NIL)
		  && (comptr < blkeptr || blkeptr == NIL)) {
E 7
I 7
		  && (strptr < blksptr || blksptr == NIL)
		  && (strptr < blkeptr || blkeptr == NIL)) {
E 7
		    putKcp (s, strptr-1, FALSE);
		    s = strptr;
		    instr = TRUE;
		    continue;
		}
E 6
D 2
		} else if (!nokeyw && !incomm && !strncmp("/*", s, 2)) {
E 2
I 2
D 4
		} else if (!instr && !nokeyw && !incomm && !strncmp(cstart, s, lcstart)) {
E 4
I 4

D 6
		/* check for the end of a comment of the alternate type */
		} else if (inacomm && lacstop != 0 && comcol != s-1 
		    && s - os >= lacstop 
		    && !strncmp(acstop, s - lacstop, lacstop)) {
			inacomm = 0;
			ps("\\c\n'-C\n");
E 6
I 6
	    /* start of a character string? */
	    if (chrptr != NIL)
D 7
		if ((comptr < blksptr || blksptr == NIL)
		  && (comptr < blkeptr || blkeptr == NIL)) {
E 7
I 7
		if ((chrptr < blksptr || blksptr == NIL)
		  && (chrptr < blkeptr || blkeptr == NIL)) {
E 7
		    putKcp (s, chrptr-1, FALSE);
		    s = chrptr;
		    inchr = TRUE;
		    continue;
		}
E 6

D 6
		/* check for the start of a comment */
		} else if (!instr && !nokeyw && !(incomm || inacomm)
		    && lcstart != 0
		    && !strncmp(cstart, s, lcstart)) {
E 4
			comcol = s;
E 2
			incomm = 1;
			if (s != os)
				ps("\\c");
			ps("\\c\n'+C\n");
			margin = width(os, s);
D 2
			ps("\\*(/*");
			s += 2;
E 2
I 2
			ps(cout);
			s += lcstart;
E 2
			continue;
E 6
I 6
	    /* end of a lexical block */
	    if (blkeptr != NIL) {
		if (blkeptr < blksptr || blksptr == NIL) {
		    putKcp (s, blkeptr - 1, FALSE);
		    s = blkeptr;
		    blklevel--;
		    if (psptr >= 0 && plstack[psptr] >= blklevel) {
E 6
I 4

D 6
		/* check for the start of a comment of the alternate type */
		} else if (!instr && !nokeyw && !(incomm || inacomm)
		    && lacstart != 0
		    && !strncmp(acstart, s, lacstart)) {
			comcol = s;
			inacomm = 1;
E 6
I 6
			/* end of current procedure */
E 6
			if (s != os)
D 6
				ps("\\c");
			ps("\\c\n'+C\n");
			margin = width(os, s);
			ps(acout);
			s += lacstart;
			continue;
E 4
		}
E 6
I 6
			    ps ("\\c");
			ps ("\\c\n'-F\n");
			blklevel = plstack[psptr];
E 6
I 4

D 6
		/* take care of nice tab stops */
E 4
		if (*s == '\t') {
			while (*s == '\t')
				s++;
			i = tabs(os, s) - margin / 8;
			printf("\\h'|%dn'", i * 10 + 1 - margin % 8);
			continue;
E 6
I 6
			/* see if we should print the last proc name */
			if (--psptr >= 0)
			    prccont = TRUE;
			else
			    psptr = -1;
		    }
		    continue;
E 6
		}
D 6
/*
		if (*s == '-' && s[1] == '>') {
			s += 2;
			ps("\\(->");
			continue;
		}
*/
D 2
		if (!nokeyw && !instr && (*s == '#' || isalpha(*s)) && (s == os || !isidchr(s[-1]))) {
E 2
I 2
D 4
		if (!incomm && !nokeyw && !instr && (*s == '#' || isalpha(*s)) && (s == os || !isidchr(s[-1]))) {
E 4
I 4
		if (!incomm && !nokeyw && !instr && (*s == '#' || isalpha(*s)) 
		    && (s == os || !isidchr(s[-1]))) {
E 4
E 2
			i = iskw(s);
			if (i > 0) {
				ps("\\*(+K");
				do 
					putcp(*s++);
				while (--i > 0);
				ps("\\*(-K");
				continue;
			}
		}
		putcp(*s++);
E 6
I 6
	    }

	    /* start of a lexical block */
	    if (blksptr != NIL) {
		putKcp (s, blksptr - 1, FALSE);
		s = blksptr;
		blklevel++;
		continue;
	    }

	/* check for end of comment */
	} else if (incomm) {
D 15
	    if ((comptr = expmatch (s, l_comend, dummy)) != NIL) {
		putKcp (s, comptr-1, TRUE);
		s = comptr;
E 15
I 15
	    comptr = expmatch (s, l_comend, dummy);
	    acmptr = expmatch (s, l_acmend, dummy);
	    if (((comtype == STANDARD) && (comptr != NIL)) ||
	        ((comtype == ALTERNATE) && (acmptr != NIL))) {
		if (comtype == STANDARD) {
		    putKcp (s, comptr-1, TRUE);
		    s = comptr;
		} else {
		    putKcp (s, acmptr-1, TRUE);
		    s = acmptr;
		}
E 15
		incomm = FALSE;
		ps("\\c\n'-C\n");
		continue;
	    } else {
D 17
		putKcp (s, s + strlen(s) -1);
E 17
I 17
		putKcp (s, s + strlen(s) -1, TRUE);
E 17
		s = s + strlen(s);
		continue;
	    }

	/* check for end of string */
	} else if (instr) {
	    if ((strptr = expmatch (s, l_strend, dummy)) != NIL) {
		putKcp (s, strptr-1, TRUE);
		s = strptr;
		instr = FALSE;
		continue;
	    } else {
		putKcp (s, s+strlen(s)-1, TRUE);
		s = s + strlen(s);
		continue;
	    }

	/* check for end of character string */
	} else if (inchr) {
	    if ((chrptr = expmatch (s, l_chrend, dummy)) != NIL) {
		putKcp (s, chrptr-1, TRUE);
		s = chrptr;
		inchr = FALSE;
		continue;
	    } else {
		putKcp (s, s+strlen(s)-1, TRUE);
		s = s + strlen(s);
		continue;
	    }
E 6
	}
I 6

	/* print out the line */
	putKcp (s, s + strlen(s) -1, FALSE);
	s = s + strlen(s);
    } while (*s);
E 6
}

I 6
putKcp (start, end, force)
    char	*start;		/* start of string to write */
    char	*end;		/* end of string to write */
    boolean	force;		/* true if we should force nokeyw */
{
    int i;
I 10
    int xfld = 0;
E 10

    while (start <= end) {
I 10
	if (index) {
	    if (*start == ' ' || *start == '\t') {
		if (xfld == 0)	
		    printf("");
		printf("\t");
		xfld = 1;
		while (*start == ' ' || *start == '\t')
		    start++;
		continue;
	    }
	}
E 10

	/* take care of nice tab stops */
	if (*start == '\t') {
	    while (*start == '\t')
		start++;
	    i = tabs(_start, start) - margin / 8;
	    printf("\\h'|%dn'", i * 10 + 1 - margin % 8);
	    continue;
	}

	if (!nokeyw && !force)
	    if ((*start == '#' || isidchr(*start)) 
	    && (start == _start || !isidchr(start[-1]))) {
		i = iskw(start);
		if (i > 0) {
		    ps("\\*(+K");
		    do 
			putcp(*start++);
		    while (--i > 0);
		    ps("\\*(-K");
		    continue;
		}
	    }

	putcp (*start++);
    }
}


E 6
tabs(s, os)
D 6
	char *s, *os;
E 6
I 6
    char *s, *os;
E 6
{

D 6
	return (width(s, os) / 8);
E 6
I 6
    return (width(s, os) / 8);
E 6
}

width(s, os)
	register char *s, *os;
{
	register int i = 0;

	while (s < os) {
		if (*s == '\t') {
			i = (i + 8) &~ 7;
			s++;
			continue;
		}
		if (*s < ' ')
			i += 2;
		else
			i++;
		s++;
	}
	return (i);
}

putcp(c)
	register int c;
{

	switch(c) {

I 6
	case 0:
		break;

	case '\f':
		break;

E 6
	case '{':
		ps("\\*(+K{\\*(-K");
		break;

	case '}':
		ps("\\*(+K}\\*(-K");
		break;

	case '\\':
		ps("\\e");
		break;

	case '_':
		ps("\\*_");
		break;

	case '-':
		ps("\\*-");
		break;

	case '`':
		ps("\\`");
		break;

	case '\'':
		ps("\\'");
		break;

	case '.':
		ps("\\&.");
		break;

I 11
	case '*':
		ps("\\fI*\\fP");
		break;

E 11
I 6
	case '/':
D 11
		ps("\\*/");
E 11
I 11
		ps("\\fI\\h'\\w' 'u-\\w'/'u'/\\fP");
E 11
		break;

E 6
	default:
		if (c < 040)
			putchar('^'), c |= '@';
	case '\t':
	case '\n':
		putchar(c);
	}
}

I 4
D 6

/*  STRNCMP -	like strncmp except that we convert the
 *	 	first string to lower case before comparing.
E 6
I 6
/*
 *	look for a process beginning on this line
E 6
 */
D 6
#define makelower(c) (isupper((c)) ? tolower((c)) : (c))

STRNCMP(s1, s2, len)
	register char *s1,*s2;
	register int len;
E 6
I 6
boolean
isproc(s)
    char *s;
E 6
{
D 6
	do
	    if (*s2 - makelower(*s1))
		    return (*s2 - makelower(*s1));
	    else {
		    s2++;
		    s1++;
	    }
	while (--len);
	return(0);
E 6
I 6
    pname[0] = NULL;
    if (!l_toplex || blklevel == 0)
	if (expmatch (s, l_prcbeg, pname) != NIL) {
	    return (TRUE);
	}
    return (FALSE);
E 6
}

I 6

E 6
/*  iskw -	check to see if the next word is a keyword
 */

E 4
D 2
char	*ckw[] = {
	"asm",
	"auto",
	"break",
	"case",
	"char",
	"continue",
	"default",
	"do",
	"double",
	"else",
	"enum",
	"extern",
	"float",
	"for",
	"fortran",
	"goto",
	"if",
	"int",
	"long",
	"register",
	"return",
	"short",
	"sizeof",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"while",
	"#define",
	"#else",
	"#endif",
	"#if",
	"#ifdef",
	"#ifndef",
	"#include",
	"#undef",
	"#",
	"define",
	"else",
	"endif",
	"if",
	"ifdef",
	"ifndef",
	"include",
	"undef",
	0,
};

E 2
iskw(s)
	register char *s;
{
D 2
	register char **ss = ckw;
E 2
I 2
D 6
	register char **ss = keywds;
E 6
I 6
	register char **ss = l_keywds;
E 6
E 2
	register int i = 1;
	register char *cp = s;

	while (++cp, isidchr(*cp))
		i++;
	while (cp = *ss++)
D 4
		if (*s == *cp && !strncmp(s, cp, i) && !isidchr(cp[i]))
E 4
I 4
D 6
		if (!(upeqlow?STRNCMP(s,cp,i):strncmp(s,cp,i)) 
		    && !isidchr(cp[i]))
E 6
I 6
		if (!STRNCMP(s,cp,i) && !isidchr(cp[i]))
E 6
E 4
			return (i);
	return (0);
I 2
D 6
}

cprbegin(s)
	register char *s;
{
	register char *p;

	p = pname;
I 4

	/*
	 * some people like to start the names of routines that return
	 * a pointer with a '*'.
	 */
	if (*s == '*')
		s++;

E 4
	if ((*s == '_' || isalpha(*s)) && s[strlen(s) - 2] == ')') {
		while (isidchr(*s))
			*p++ = *s++;
		*p = 0;
		return (1);
	}
	return (0);
}

cprend(s)
	register char *s;
{
	if (!strcmp(s, "}\n"))
		return (1);
	else
		return (0);
I 4
}

iprbegin(s)
	register char *s;
{
	return(0);
}

iprend(s)
	register char *s;
{
	return(0);
E 4
}

pprbegin(s)
	register char *s;
{
	register char *p;

	p = pname;
	while ((*s == ' ') || (*s == '\t'))
		s++;
	if (strncmp(s, "procedure", 9) == 0)
		s += 9;
	else if (strncmp(s, "function", 8) ==0)
		s += 8;
	else
		return (0);
	while ((*s == ' ') || (*s == '\t'))
		s++;
	while ((*s != ' ') && (*s != '\t') && (*s != '(') && (*s != ';'))
		*p++ = *s++;
	*p = 0;
	return (1);
}

pprend(s)
	register char *s;
{
	if (strncmp (s, "end", 3) == 0)
		return (1);
	else
		return (0);
}

mprbegin(s)
	register char *s;
{
	register char *p;

	p = pname;
	if (strcmp(&s[strlen(s) - 10], "beginproc\n") == 0) {

		while ((*s == ' ') || (*s == '\t'))
			s++;

		while (*s != ' ')
			*p++ = *s++;
		*p = 0;
		return (1);
	} else
		return (0);
}

mprend(s)
	register char *s;
{
	if (!strcmp(&s[strlen(s) - 9], "endproc;\n"))
		return (1);
	else
		return (0);
E 6
E 2
}
E 1
