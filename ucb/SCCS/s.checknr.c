h12997
s 00017/00017/00542
d D 5.2 85/12/05 17:05:27 bloom 9 8
c add .T& to the list of known commands (tbl)
e
s 00014/00001/00545
d D 5.1 85/05/31 09:07:31 dist 8 7
c Add copyright
e
s 00006/00001/00540
d D 4.7 84/02/02 09:01:04 rrh 7 6
c if a command is already in table, it tried to add it again
c in the wrong place.  F*k you, Horton
e
s 00032/00028/00509
d D 4.6 83/09/24 13:48:24 sam 6 5
c update for revised -ms macros
e
s 00000/00002/00537
d D 4.5 82/11/07 14:05:32 rrh 5 4
c Allow no arguments at all and take the input from stdin
e
s 00001/00001/00538
d D 4.4 81/05/13 15:39:22 mark 4 3
c added .DT macro which it didn't know about (-ms)
e
s 00063/00047/00476
d D 4.3 81/04/21 01:37:34 root 3 2
c added -mm (from chico!trb) and fixed comment bug; added refer macros and -me macro .xp
e
s 00060/00026/00463
d D 4.2 80/10/12 23:35:05 mark 2 1
c fixes per mark of -a, etc
e
s 00489/00000/00000
d D 4.1 80/10/01 17:25:20 bill 1 0
c date and time created 80/10/01 17:25:20 by bill
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 8
I 1
D 6
static char *sccsid = "%W% (Berkeley) %G%";
E 6
I 6
#ifndef lint
I 8
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 8
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif
E 8
I 8
#endif not lint

E 8
E 6
/*
 * checknr: check an nroff/troff input file for matching macro calls.
 * we also attempt to match size and font changes, but only the embedded
 * kind.  These must end in \s0 and \fP resp.  Maybe more sophistication
 * later but for now think of these restrictions as contributions to
 * structured typesetting.
 */
#include <stdio.h>
#include <ctype.h>

#define MAXSTK	100	/* Stack size */
#define MAXBR	100	/* Max number of bracket pairs known */
#define MAXCMDS	500	/* Max number of commands known */

/*
 * The stack on which we remember what we've seen so far.
 */
struct stkstr {
	int opno;	/* number of opening bracket */
	int pl;		/* '+', '-', ' ' for \s, 1 for \f, 0 for .ft */
	int parm;	/* parm to size, font, etc */
	int lno;	/* line number the thing came in in */
} stk[MAXSTK];
int stktop;

/*
 * The kinds of opening and closing brackets.
 */
struct brstr {
	char *opbr;
	char *clbr;
} br[MAXBR] = {
	/* A few bare bones troff commands */
#define SZ	0
	"sz",	"sz",	/* also \s */
#define FT	1
	"ft",	"ft",	/* also \f */
I 3
	/* the -mm package */
	"AL",	"LE",
	"AS",	"AE",
	"BL",	"LE",
	"BS",	"BE",
	"DF",	"DE",
	"DL",	"LE",
	"DS",	"DE",
	"FS",	"FE",
	"ML",	"LE",
	"NS",	"NE",
	"RL",	"LE",
	"VL",	"LE",
E 3
	/* the -ms package */
	"AB",	"AE",
I 6
	"BD",	"DE",
E 6
D 3
	"RS",	"RE",
	"LG",	"NL",
	"SM",	"NL",
	"FS",	"FE",
	"DS",	"DE",
E 3
	"CD",	"DE",
D 3
	"LD",	"DE",
E 3
I 3
	"DS",	"DE",
	"FS",	"FE",
E 3
	"ID",	"DE",
D 3
	"KS",	"KE",
E 3
	"KF",	"KE",
I 3
	"KS",	"KE",
	"LD",	"DE",
	"LG",	"NL",
E 3
	"QS",	"QE",
D 3
	/* Things needed by preprocessors */
	"TS",	"TE",
	"EQ",	"EN",
E 3
I 3
	"RS",	"RE",
	"SM",	"NL",
I 6
	"XA",	"XE",
	"XS",	"XE",
E 6
E 3
	/* The -me package */
D 3
	"(l",	")l",
	"(q",	")q",
E 3
	"(b",	")b",
D 3
	"(z",	")z",
E 3
	"(c",	")c",
	"(d",	")d",
	"(f",	")f",
I 3
	"(l",	")l",
	"(q",	")q",
E 3
	"(x",	")x",
I 3
	"(z",	")z",
	/* Things needed by preprocessors */
	"EQ",	"EN",
	"TS",	"TE",
	/* Refer */
	"[",	"]",
E 3
	0,	0
};

/*
D 3
 * All commands known to nroff, plus ms and me.
E 3
I 3
 * All commands known to nroff, plus macro packages.
E 3
 * Used so we can complain about unrecognized commands.
 */
char *knowncmds[MAXCMDS] = {
D 3
"$c", "$f", "$h", "$p", "$s", "(b", "(c", "(d", "(f", "(l",
"(q", "(t", "(x", "(z", ")b", ")c", ")d", ")f", ")l", ")q",
")t", ")x", ")z", "++", "+c", "1C", "1c", "2C", "2c", "@(",
"@)", "@C", "@D", "@F", "@I", "@M", "@c", "@e", "@f", "@h",
"@m", "@n", "@o", "@p", "@r", "@t", "@z", "AB", "AB", "AE",
"AE", "AI", "AI", "AT", "AU", "AU", "AX", "B",  "B1", "B2",
"BD", "BG", "BT", "BX", "C1", "C2", "CD", "CM", "CT", "D", 
"DA", "DE", "DF", "DS", "EG", "EM", "EN", "EQ", "EQ", "FA",
"FE", "FJ", "FK", "FL", "FN", "FO", "FQ", "FS", "FV", "FX",
"HO", "I",  "ID", "IE", "IH", "IM", "IP", "IZ", "KD", "KE",
"KF", "KQ", "KS", "LB", "LD", "LG", "LP", "MC", "ME", "MF",
"MH", "MR", "ND", "NH", "NL", "NP", "OK", "PP", "PT", "PY",
"QE", "QP", "QS", "R",  "RA", "RC", "RE", "RP", "RQ", "RS",
"RT", "S0", "S2", "S3", "SG", "SH", "SM", "SY", "TA", "TC",
"TD", "TE", "TH", "TL", "TL", "TM", "TQ", "TR", "TS", "TS",
"TX", "UL", "US", "UX", "WH", "XD", "XF", "XK", "XP", "[-",
"[0", "[1", "[2", "[3", "[4", "[5", "[<", "[>", "[]", "]-",
"]<", "]>", "][", "ab", "ac", "ad", "af", "am", "ar", "as",
"b",  "ba", "bc", "bd", "bi", "bl", "bp", "bp", "br", "bx",
"c.", "c2", "cc", "ce", "cf", "ch", "cs", "ct", "cu", "da",
"de", "di", "dl", "dn", "ds", "dt", "dw", "dy", "ec", "ef",
"eh", "el", "em", "eo", "ep", "ev", "ex", "fc", "fi", "fl",
"fo", "fp", "ft", "fz", "hc", "he", "hl", "hp", "ht", "hw",
"hx", "hy", "i",  "ie", "if", "ig", "in", "ip", "it", "ix",
"lc", "lg", "li", "ll", "ll", "ln", "lo", "lp", "ls", "lt",
"m1", "m2", "m3", "m4", "mc", "mk", "mo", "n1", "n2", "na",
"ne", "nf", "nh", "nl", "nm", "nn", "np", "nr", "ns", "nx",
"of", "oh", "os", "pa", "pc", "pi", "pl", "pm", "pn", "po",
"po", "pp", "ps", "q",  "r",  "rb", "rd", "re", "re", "rm",
"rn", "ro", "rr", "rs", "rt", "sb", "sc", "sh", "sk", "so",
"sp", "ss", "st", "sv", "sz", "ta", "tc", "th", "ti", "tl",
"tm", "tp", "tr", "u",  "uf", "uh", "ul", "vs", "wh", "yr",
E 3
I 3
"$c", "$f", "$h", "$p", "$s", "(b", "(c", "(d", "(f", "(l", "(q", "(t",
"(x", "(z", ")b", ")c", ")d", ")f", ")l", ")q", ")t", ")x", ")z", "++",
"+c", "1C", "1c", "2C", "2c", "@(", "@)", "@C", "@D", "@F", "@I", "@M",
"@c", "@e", "@f", "@h", "@m", "@n", "@o", "@p", "@r", "@t", "@z", "AB",
D 6
"AE", "AF", "AI", "AL", "AS", "AT", "AU", "AX", "B",  "B1", "B2", "BD",
"BE", "BG", "BL", "BS", "BT", "BX", "C1", "C2", "CD", "CM", "CT", "D", 
D 4
"DA", "DE", "DF", "DL", "DS", "EC", "EF", "EG", "EH", "EM", "EN", "EQ",
E 4
I 4
"DA", "DE", "DF", "DL", "DS", "DT", "EC", "EF", "EG", "EH", "EM", "EN", "EQ",
E 4
"EX", "FA", "FD", "FE", "FG", "FJ", "FK", "FL", "FN", "FO", "FQ", "FS",
"FV", "FX", "H",  "HC", "HM", "HO", "HU", "I",  "ID", "IE", "IH", "IM",
"IP", "IZ", "KD", "KE", "KF", "KQ", "KS", "LB", "LC", "LD", "LE", "LG",
"LI", "LP", "MC", "ME", "MF", "MH", "ML", "MR", "MT", "ND", "NE", "NH",
"NL", "NP", "NS", "OF", "OH", "OK", "OP", "P",  "PF", "PH", "PP", "PT",
"PY", "QE", "QP", "QS", "R",  "RA", "RC", "RE", "RL", "RP", "RQ", "RS",
"RT", "S",  "S0", "S2", "S3", "SA", "SG", "SH", "SK", "SM", "SP", "SY",
"TA", "TB", "TC", "TD", "TE", "TH", "TL", "TM", "TP", "TQ", "TR", "TS",
"TX", "UL", "US", "UX", "VL", "WC", "WH", "XD", "XF", "XK", "XP", "[",  "[-",
"[0", "[1", "[2", "[3", "[4", "[5", "[<", "[>", "[]", "]",  "]-", "]<", "]>",
"][", "ab", "ac", "ad", "af", "am", "ar", "as", "b",  "ba", "bc", "bd",
"bi", "bl", "bp", "br", "bx", "c.", "c2", "cc", "ce", "cf", "ch", "cs",
"ct", "cu", "da", "de", "di", "dl", "dn", "ds", "dt", "dw", "dy", "ec",
"ef", "eh", "el", "em", "eo", "ep", "ev", "ex", "fc", "fi", "fl", "fo",
"fp", "ft", "fz", "hc", "he", "hl", "hp", "ht", "hw", "hx", "hy", "i", 
"ie", "if", "ig", "in", "ip", "it", "ix", "lc", "lg", "li", "ll", "ln",
"lo", "lp", "ls", "lt", "m1", "m2", "m3", "m4", "mc", "mk", "mo", "n1",
"n2", "na", "ne", "nf", "nh", "nl", "nm", "nn", "np", "nr", "ns", "nx",
"of", "oh", "os", "pa", "pc", "pi", "pl", "pm", "pn", "po", "pp", "ps",
"q",  "r",  "rb", "rd", "re", "rm", "rn", "ro", "rr", "rs", "rt", "sb",
"sc", "sh", "sk", "so", "sp", "ss", "st", "sv", "sz", "ta", "tc", "th",
"ti", "tl", "tm", "tp", "tr", "u",  "uf", "uh", "ul", "vs", "wh", "xp", "yr",
E 6
I 6
"AE", "AF", "AI", "AL", "AM", "AS", "AT", "AU", "AX", "B",  "B1", "B2",
"BD", "BE", "BG", "BL", "BS", "BT", "BX", "C1", "C2", "CD", "CM", "CT",
"D",  "DA", "DE", "DF", "DL", "DS", "DT", "EC", "EF", "EG", "EH", "EM",
"EN", "EQ", "EX", "FA", "FD", "FE", "FG", "FJ", "FK", "FL", "FN", "FO",
"FQ", "FS", "FV", "FX", "H",  "HC", "HD", "HM", "HO", "HU", "I",  "ID",
"IE", "IH", "IM", "IP", "IX", "IZ", "KD", "KE", "KF", "KQ", "KS", "LB",
"LC", "LD", "LE", "LG", "LI", "LP", "MC", "ME", "MF", "MH", "ML", "MR",
"MT", "ND", "NE", "NH", "NL", "NP", "NS", "OF", "OH", "OK", "OP", "P",
"P1", "PF", "PH", "PP", "PT", "PX", "PY", "QE", "QP", "QS", "R",  "RA",
"RC", "RE", "RL", "RP", "RQ", "RS", "RT", "S",  "S0", "S2", "S3", "SA",
D 9
"SG", "SH", "SK", "SM", "SP", "SY", "TA", "TB", "TC", "TD", "TE", "TH",
"TL", "TM", "TP", "TQ", "TR", "TS", "TX", "UL", "US", "UX", "VL", "WC",
"WH", "XA", "XD", "XE", "XF", "XK", "XP", "XS", "[",  "[-", "[0", "[1",
"[2", "[3", "[4", "[5", "[<", "[>", "[]", "]",  "]-", "]<", "]>", "][",
"ab", "ac", "ad", "af", "am", "ar", "as", "b",  "ba", "bc", "bd", "bi",
"bl", "bp", "br", "bx", "c.", "c2", "cc", "ce", "cf", "ch", "cs", "ct",
"cu", "da", "de", "di", "dl", "dn", "ds", "dt", "dw", "dy", "ec", "ef",
"eh", "el", "em", "eo", "ep", "ev", "ex", "fc", "fi", "fl", "fo", "fp",
"ft", "fz", "hc", "he", "hl", "hp", "ht", "hw", "hx", "hy", "i",  "ie",
"if", "ig", "in", "ip", "it", "ix", "lc", "lg", "li", "ll", "ln", "lo",
"lp", "ls", "lt", "m1", "m2", "m3", "m4", "mc", "mk", "mo", "n1", "n2",
"na", "ne", "nf", "nh", "nl", "nm", "nn", "np", "nr", "ns", "nx", "of",
"oh", "os", "pa", "pc", "pi", "pl", "pm", "pn", "po", "pp", "ps", "q",
"r",  "rb", "rd", "re", "rm", "rn", "ro", "rr", "rs", "rt", "sb", "sc",
"sh", "sk", "so", "sp", "ss", "st", "sv", "sz", "ta", "tc", "th", "ti",
"tl", "tm", "tp", "tr", "u",  "uf", "uh", "ul", "vs", "wh", "xp", "yr",
E 6
E 3
0
E 9
I 9
"SG", "SH", "SK", "SM", "SP", "SY", "T&", "TA", "TB", "TC", "TD", "TE",
"TH", "TL", "TM", "TP", "TQ", "TR", "TS", "TX", "UL", "US", "UX", "VL",
"WC", "WH", "XA", "XD", "XE", "XF", "XK", "XP", "XS", "[",  "[-", "[0",
"[1", "[2", "[3", "[4", "[5", "[<", "[>", "[]", "]",  "]-", "]<", "]>",
"][", "ab", "ac", "ad", "af", "am", "ar", "as", "b",  "ba", "bc", "bd",
"bi", "bl", "bp", "br", "bx", "c.", "c2", "cc", "ce", "cf", "ch", "cs",
"ct", "cu", "da", "de", "di", "dl", "dn", "ds", "dt", "dw", "dy", "ec",
"ef", "eh", "el", "em", "eo", "ep", "ev", "ex", "fc", "fi", "fl", "fo",
"fp", "ft", "fz", "hc", "he", "hl", "hp", "ht", "hw", "hx", "hy", "i",
"ie", "if", "ig", "in", "ip", "it", "ix", "lc", "lg", "li", "ll", "ln",
"lo", "lp", "ls", "lt", "m1", "m2", "m3", "m4", "mc", "mk", "mo", "n1",
"n2", "na", "ne", "nf", "nh", "nl", "nm", "nn", "np", "nr", "ns", "nx",
"of", "oh", "os", "pa", "pc", "pi", "pl", "pm", "pn", "po", "pp", "ps",
"q",  "r",  "rb", "rd", "re", "rm", "rn", "ro", "rr", "rs", "rt", "sb",
"sc", "sh", "sk", "so", "sp", "ss", "st", "sv", "sz", "ta", "tc", "th",
"ti", "tl", "tm", "tp", "tr", "u",  "uf", "uh", "ul", "vs", "wh", "xp",
"yr", 0
E 9
};

int	lineno;		/* current line number in input file */
char	line[256];	/* the current line */
char	*cfilename;	/* name of current file */
int	nfiles;		/* number of files to process */
int	fflag;		/* -f: ignore \f */
int	sflag;		/* -s: ignore \s */
int	ncmds;		/* size of knowncmds */
int	slot;		/* slot in knowncmds found by binsrch */

char	*malloc();

main(argc, argv)
int argc;
char **argv;
{
	FILE *f;
	int i;
	char *cp;
I 2
	char b1[4];
E 2

D 5
	if (argc <= 1)
D 2
		goto usage;
E 2
I 2
		usage();
E 5
	/* Figure out how many known commands there are */
	while (knowncmds[ncmds])
		ncmds++;
E 2
	while (argc > 1 && argv[1][0] == '-') {
		switch(argv[1][1]) {
I 2

		/* -a: add pairs of macros */
E 2
		case 'a':
D 2
			/* -a: add pairs of macros */
E 2
			i = strlen(argv[1]) - 2;
D 2
			if (i % 6 != 0) {
usage:
				printf("Usage: nrc -s -f -a.xx.yy.xx.yy... (.xx, .yy)\n");
				break;
			}
E 2
I 2
			if (i % 6 != 0)
				usage();
E 2
			/* look for empty macro slots */
			for (i=0; br[i].opbr; i++)
				;
			for (cp=argv[1]+3; cp[-1]; cp += 6) {
D 2
				br[i].opbr = cp;
				br[i].clbr = cp+3;
				cp[2] = cp[5] = 0;
E 2
I 2
				br[i].opbr = malloc(3);
				strncpy(br[i].opbr, cp, 2);
				br[i].clbr = malloc(3);
				strncpy(br[i].clbr, cp+3, 2);
				addmac(br[i].opbr);	/* knows pairs are also known cmds */
				addmac(br[i].clbr);
E 2
				i++;
			}
			break;
I 2

		/* -c: add known commands */
		case 'c':
			i = strlen(argv[1]) - 2;
			if (i % 3 != 0)
				usage();
			for (cp=argv[1]+3; cp[-1]; cp += 3) {
				if (cp[2] && cp[2] != '.')
					usage();
				strncpy(b1, cp, 2);
				addmac(b1);
			}
			break;

		/* -f: ignore font changes */
E 2
		case 'f':
			fflag = 1;
			break;
I 2

		/* -s: ignore size changes */
E 2
		case 's':
			sflag = 1;
			break;
		default:
D 2
			printf("Illegal flag: %s\n", argv[1]);
			break;
E 2
I 2
			usage();
E 2
		}
		argc--; argv++;
	}

	nfiles = argc - 1;

	if (nfiles > 0) {
		for (i=1; i<argc; i++) {
			cfilename = argv[i];
			f = fopen(cfilename, "r");
			if (f == NULL)
				perror(cfilename);
			else
				process(f);
		}
	} else {
		cfilename = "stdin";
		process(stdin);
	}
	exit(0);
}

I 2
usage()
{
	printf("Usage: checknr -s -f -a.xx.yy.xx.yy... -c.xx.xx.xx...\n");
	exit(1);
}

E 2
process(f)
FILE *f;
{
	register int i, n;
	char mac[5];	/* The current macro or nroff command */
	int pl;

	stktop = -1;
	for (lineno = 1; fgets(line, sizeof line, f); lineno++) {
		if (line[0] == '.') {
			/*
			 * find and isolate the macro/command name.
			 */
			strncpy(mac, line+1, 4);
			if (isspace(mac[0])) {
				pe(lineno);
				printf("Empty command\n");
			} else if (isspace(mac[1])) {
				mac[1] = 0;
			} else if (isspace(mac[2])) {
				mac[2] = 0;
D 3
			} else if (mac[2] != '\\' || mac[3] != '\"') {
E 3
I 3
			} else if (mac[0] != '\\' || mac[1] != '\"') {
E 3
				pe(lineno);
				printf("Command too long\n");
			}

			/*
			 * Is it a known command?
			 */
			checkknown(mac);

			/*
			 * Should we add it?
			 */
			if (eq(mac, "de"))
				addcmd(line);

			chkcmd(line, mac);
		}

		/*
		 * At this point we process the line looking
		 * for \s and \f.
		 */
		for (i=0; line[i]; i++)
			if (line[i]=='\\' && (i==0 || line[i-1]!='\\')) {
				if (!sflag && line[++i]=='s') {
					pl = line[++i];
					if (isdigit(pl)) {
						n = pl - '0';
						pl = ' ';
					} else
						n = 0;
					while (isdigit(line[++i]))
						n = 10 * n + line[i] - '0';
					i--;
					if (n == 0) {
						if (stk[stktop].opno == SZ) {
							stktop--;
						} else {
							pe(lineno);
							printf("unmatched \\s0\n");
						}
					} else {
						stk[++stktop].opno = SZ;
						stk[stktop].pl = pl;
						stk[stktop].parm = n;
						stk[stktop].lno = lineno;
					}
				} else if (!fflag && line[i]=='f') {
					n = line[++i];
					if (n == 'P') {
						if (stk[stktop].opno == FT) {
							stktop--;
						} else {
							pe(lineno);
							printf("unmatched \\fP\n");
						}
					} else {
						stk[++stktop].opno = FT;
						stk[stktop].pl = 1;
						stk[stktop].parm = n;
						stk[stktop].lno = lineno;
					}
				}
			}
	}
	/*
	 * We've hit the end and look at all this stuff that hasn't been
	 * matched yet!  Complain, complain.
	 */
	for (i=stktop; i>=0; i--) {
		complain(i);
	}
}

complain(i)
{
	pe(stk[i].lno);
	printf("Unmatched ");
	prop(i);
	printf("\n");
}

prop(i)
{
	if (stk[i].pl == 0)
		printf(".%s", br[stk[i].opno].opbr);
	else switch(stk[i].opno) {
	case SZ:
		printf("\\s%c%d", stk[i].pl, stk[i].parm);
		break;
	case FT:
		printf("\\f%c", stk[i].parm);
		break;
	default:
		printf("Bug: stk[%d].opno = %d = .%s, .%s",
			i, stk[i].opno, br[stk[i].opno].opbr, br[stk[i].opno].clbr);
	}
}

chkcmd(line, mac)
char *line;
char *mac;
{
	register int i, n;

	/*
	 * Check to see if it matches top of stack.
	 */
	if (stktop >= 0 && eq(mac, br[stk[stktop].opno].clbr))
		stktop--;	/* OK. Pop & forget */
	else {
		/* No. Maybe it's an opener */
		for (i=0; br[i].opbr; i++) {
			if (eq(mac, br[i].opbr)) {
				/* Found. Push it. */
				stktop++;
				stk[stktop].opno = i;
				stk[stktop].pl = 0;
				stk[stktop].parm = 0;
				stk[stktop].lno = lineno;
				break;
			}
			/*
			 * Maybe it's an unmatched closer.
			 * NOTE: this depends on the fact
			 * that none of the closers can be
			 * openers too.
			 */
			if (eq(mac, br[i].clbr)) {
				nomatch(mac);
				break;
			}
		}
	}
}

nomatch(mac)
char *mac;
{
	register int i, j;

	/*
	 * Look for a match further down on stack
	 * If we find one, it suggests that the stuff in
	 * between is supposed to match itself.
	 */
	for (j=stktop; j>=0; j--)
		if (eq(mac,br[stk[j].opno].clbr)) {
			/* Found.  Make a good diagnostic. */
			if (j == stktop-2) {
				/*
				 * Check for special case \fx..\fR and don't
				 * complain.
				 */
				if (stk[j+1].opno==FT && stk[j+1].parm!='R'
				 && stk[j+2].opno==FT && stk[j+2].parm=='R') {
					stktop = j -1;
					return;
				}
				/*
				 * We have two unmatched frobs.  Chances are
				 * they were intended to match, so we mention
				 * them together.
				 */
				pe(stk[j+1].lno);
				prop(j+1);
				printf(" does not match %d: ", stk[j+2].lno);
				prop(j+2);
				printf("\n");
			} else for (i=j+1; i <= stktop; i++) {
				complain(i);
			}
			stktop = j-1;
			return;
		}
	/* Didn't find one.  Throw this away. */
	pe(lineno);
	printf("Unmatched .%s\n", mac);
}

/* eq: are two strings equal? */
eq(s1, s2)
char *s1, *s2;
{
	return (strcmp(s1, s2) == 0);
}

/* print the first part of an error message, given the line number */
pe(lineno)
int lineno;
{
	if (nfiles > 1)
		printf("%s: ", cfilename);
	printf("%d: ", lineno);
}

checkknown(mac)
char *mac;
{
D 2
	/* First time figure out ncmds. */
	if (ncmds == 0) {
		while (knowncmds[ncmds])
			ncmds++;
	}
E 2

	if (eq(mac, "."))
		return;
	if (binsrch(mac) >= 0)
		return;
I 3
	if (mac[0] == '\\' && mac[1] == '"')	/* comments */
		return;
E 3

	pe(lineno);
	printf("Unknown command: .%s\n", mac);
}

/*
 * We have a .de xx line in "line".  Add xx to the list of known commands.
 */
addcmd(line)
char *line;
{
	char *mac;
D 2
	register char **src, **dest, **loc;
E 2

	/* grab the macro being defined */
	mac = line+4;
	while (isspace(*mac))
		mac++;
	if (*mac == 0) {
		pe(lineno);
		printf("illegal define: %s\n", line);
		return;
	}
	mac[2] = 0;
	if (isspace(mac[1]) || mac[1] == '\\')
		mac[1] = 0;
	if (ncmds >= MAXCMDS) {
		printf("Only %d known commands allowed\n", MAXCMDS);
		exit(1);
	}
D 2
	
	/*
	 * Add mac to the list.  We should really have some kind of tree
	 * structure here but this is a quick-and-dirty job and I just don't
	 * have time to mess with it.  (I wonder if this will come back to haunt
	 * me someday?)  Anyway, I claim that .de is fairly rare in user
	 * nroff programs, and the register loop below is pretty fast.
	 */
E 2
I 2
	addmac(mac);
}

/*
 * Add mac to the list.  We should really have some kind of tree
 * structure here but this is a quick-and-dirty job and I just don't
 * have time to mess with it.  (I wonder if this will come back to haunt
 * me someday?)  Anyway, I claim that .de is fairly rare in user
 * nroff programs, and the register loop below is pretty fast.
 */
addmac(mac)
char *mac;
{
	register char **src, **dest, **loc;

E 2
D 7
	binsrch(mac);	/* it's OK to redefine something */
E 7
I 7
	if (binsrch(mac) >= 0){	/* it's OK to redefine something */
#ifdef DEBUG
		printf("binsrch(%s) -> already in table\n", mac);
#endif DEBUG
		return;
	}
E 7
	/* binsrch sets slot as a side effect */
I 2
#ifdef DEBUG
printf("binsrch(%s) -> %d\n", mac, slot);
#endif
E 2
	loc = &knowncmds[slot];
	src = &knowncmds[ncmds-1];
	dest = src+1;
	while (dest > loc)
		*dest-- = *src--;
	*loc = malloc(3);
	strcpy(*loc, mac);
	ncmds++;
I 2
#ifdef DEBUG
printf("after: %s %s %s %s %s, %d cmds\n", knowncmds[slot-2], knowncmds[slot-1], knowncmds[slot], knowncmds[slot+1], knowncmds[slot+2], ncmds);
#endif
E 2
}

/*
 * Do a binary search in knowncmds for mac.
 * If found, return the index.  If not, return -1.
 */
binsrch(mac)
char *mac;
{
	register char *p;	/* pointer to current cmd in list */
	register int d;		/* difference if any */
	register int mid;	/* mid point in binary search */
	register int top, bot;	/* boundaries of bin search, inclusive */

	top = ncmds-1;
	bot = 0;
	while (top >= bot) {
		mid = (top+bot)/2;
		p = knowncmds[mid];
		d = p[0] - mac[0];
		if (d == 0)
			d = p[1] - mac[1];
		if (d == 0)
			return mid;
		if (d < 0)
			bot = mid + 1;
		else
			top = mid - 1;
	}
	slot = bot;	/* place it would have gone */
	return -1;
}
I 3
D 6


E 6
E 3
E 1
