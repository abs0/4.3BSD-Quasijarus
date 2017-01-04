h48844
s 00007/00003/00344
d D 5.1 85/06/05 15:08:58 dist 7 6
c Add copyright
e
s 00000/00000/00347
d D 2.1 84/02/08 20:45:05 aoki 6 5
c synchronize to version 2
e
s 00001/00001/00346
d D 1.5 83/09/19 07:02:03 thien 5 4
c Restoring to unlinted version
e
s 00013/00010/00334
d D 1.4 83/08/19 05:04:27 thien 4 3
c The changes were made to allow successful linting
e
s 00010/00004/00334
d D 1.3 82/08/29 14:06:19 peter 3 2
c checking for non-standard `#', `|', `&', and `~'.
e
s 00002/00002/00336
d D 1.2 81/03/08 19:30:04 mckusic 2 1
c merge in onyx changes
e
s 00338/00000/00000
d D 1.1 80/08/27 19:57:11 peter 1 0
c date and time created 80/08/27 19:57:11 by peter
e
u
U
t
T
I 1
D 7
/* Copyright (c) 1979 Regents of the University of California */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 7

D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
D 4
static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
#ifndef lint
D 5
static char sccsid[] = "%Z%%M% %I% %G%"; */
E 5
I 5
D 7
static char sccsid[] = "%Z%%M% %I% %G%";
E 5
#endif
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7
E 4
E 2

#include "whoami.h"
#include "0.h"
I 4
#include "tree_ty.h"	/* must be included for yy.h */
E 4
#include "yy.h"

/*
 * Scanner
 */
int	yylacnt;

#define	YYLASIZ	10

struct	yytok Yla[YYLASIZ];

unyylex(y)
D 4
	struct yylex *y;
E 4
I 4
	struct yytok *y;
E 4
{

	if (yylacnt == YYLASIZ)
		panic("unyylex");
D 4
	copy(&Yla[yylacnt], y, sizeof Yla[0]);
E 4
I 4
	copy((char *) &Yla[yylacnt], (char *) y, sizeof Yla[0]);
E 4
	yylacnt++;

}

yylex()
{
	register c;
D 4
	register **ip;
E 4
I 4
	register int **ip;
E 4
	register char *cp;
	int f;
	char delim;

	if (yylacnt != 0) {
		yylacnt--;
D 4
		copy(&Y, &Yla[yylacnt], sizeof Y);
E 4
I 4
		copy((char *) &Y, (char *) &Yla[yylacnt], sizeof Y);
E 4
		return (yychar);
	}
	if (c = yysavc)
		yysavc = 0;
	else
		c = readch();
#ifdef PXP
	yytokcnt++;
#endif

next:
	/*
	 * skip white space
	 */
#ifdef PXP
	yywhcnt = 0;
#endif
	while (c == ' ' || c == '\t') {
#ifdef PXP
		if (c == '\t')
			yywhcnt++;
		yywhcnt++;
#endif
		c = readch();
	}
	yyecol = yycol;
	yyeline = yyline;
	yyefile = filename;
	yyeseqid = yyseqid;
	yyseekp = yylinpt;
	cp = token;
	yylval = yyline;
	switch (c) {
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': 
		case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': 
		case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': 
		case 'v': case 'w': case 'x': case 'y': case 'z': 
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': 
		case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': 
		case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': 
		case 'V': case 'W': case 'X': case 'Y': case 'Z': 
			do {
				*cp++ = c;
				c = readch();
			} while (alph(c) || digit(c));
			*cp = 0;
			if (opt('s'))
				for (cp = token; *cp; cp++)
					if (*cp >= 'A' && *cp <= 'Z') {
D 2
						*cp =| ' ';
E 2
I 2
						*cp |= ' ';
E 2
					}
			yysavc = c;
D 4
			ip = hash(0, 1);
			if (*ip < yykey || *ip >= lastkey) {
				yylval = *ip;
E 4
I 4
			ip = (int **) hash((char *) 0, 1);
			if (*ip < (int *) yykey || *ip >= (int *) lastkey) {
				yylval = (int) *ip;
E 4
				return (YID);
			}
			yylval = yyline;
			/*
			 * For keywords
			 * the lexical token
			 * is magically retrieved
			 * from the keyword table.
			 */
			return ((*ip)[1]);
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			f = 0;
			do {
				*cp++ = c;
				c = readch();
			} while (digit(c));
			if (c == 'b' || c == 'B') {
				/*
				 * nonstandard - octal constants
				 */
				if (opt('s')) {
					standard();
					yerror("Octal constants are non-standard");
				}
				*cp = 0;
				yylval = copystr(token);
				return (YBINT);
			}
			if (c == '.') {
				c = readch();
				if (c == '.') {
					*cp = 0;
					yysavc = YDOTDOT;
					yylval = copystr(token);
					return (YINT);
				}
infpnumb:
				f++;
				*cp++ = '.';
				if (!digit(c)) {
					yyset();
					recovered();
					yerror("Digits required after decimal point");
					*cp++ = '0';
				} else
					while (digit(c)) {
						*cp++ = c;
						c = readch();
					}
			}
			if (c == 'e' || c == 'E') {
				f++;
				*cp++ = c;
				if ((c = yysavc) == 0)
					c = readch();
				if (c == '+' || c == '-') {
					*cp++ = c;
					c = readch();
				}
				if (!digit(c)) {
					yyset();
					yerror("Digits required in exponent");
					*cp++ = '0';
				} else
					while (digit(c)) {
						*cp++ = c;
						c = readch();
					}
			}
			*cp = 0;
			yysavc = c;
			yylval = copystr(token);
			if (f)
				return (YNUMB);
			return (YINT);
		case '"':
		case '`':
I 3
		case '#':
E 3
			if (!any(bufp + 1, c))
				goto illch;
			if (!dquote) {
				recovered();
				dquote++;
				yerror("Character/string delimiter is '");
			}
		case '\'':
D 3
		case '#':
E 3
			delim = c;
			do {
				do {
					c = readch();
					if (c == '\n') {
D 4
						yerror("Unmatched %c for string", delim);
E 4
I 4
						yerror("Unmatched %c for string", (char *) delim);
E 4
						if (cp == token)
							*cp++ = ' ', cp++;
						break;
					}
					*cp++ = c;
				} while (c != delim);
				c = readch();
			} while (c == delim);
			*--cp = 0;
			if (cp == token) {
				yerror("Null string not allowed");
				*cp++ = ' ';
				*cp++ = 0;
			}
			yysavc = c;
			yylval = copystr(token);
			return (YSTRING);
		case '.':
			c = readch();
			if (c == '.')
				return (YDOTDOT);
			if (digit(c)) {
				recovered();
				yerror("Digits required before decimal point");
				*cp++ = '0';
				goto infpnumb;
			}
			yysavc = c;
			return ('.');
		case '{':
			/*
			 * { ... } comment
			 */
#ifdef PXP
			getcm(c);
#endif
#ifdef PI
			c = options();
			while (c != '}') {
				if (c <= 0)
					goto nonterm;
				if (c == '{') {
					warning();
					yyset();
					yerror("{ in a { ... } comment");
				}
				c = readch();
			}
#endif
			c = readch();
			goto next;
		case '(':
			if ((c = readch()) == '*') {
				/*
				 * (* ... *) comment
				 */
#ifdef PXP
				getcm(c);
				c = readch();
				goto next;
#endif
#ifdef PI
				c = options();
				for (;;) {
					if (c < 0) {
nonterm:
						yerror("Comment does not terminate - QUIT");
						pexit(ERRS);
					}
					if (c == '(' && (c = readch()) == '*') {
						warning();
						yyset();
						yerror("(* in a (* ... *) comment");
					}
					if (c == '*') {
						if ((c = readch()) != ')')
							continue;
						c = readch();
						goto next;
					}
					c = readch();
				}
#endif
			}
			yysavc = c;
			c = '(';
		case ';':
		case ',':
		case ':':
		case '=':
		case '*':
		case '+':
		case '/':
		case '-':
D 3
		case '|':
		case '&':
E 3
		case ')':
		case '[':
		case ']':
		case '<':
		case '>':
D 3
		case '~':
E 3
		case '^':
			return (c);
I 3
		case '~':
		case '|':
		case '&':
			if ( opt('s') ) {
			    yyset();
			    standard();
D 4
			    yerror("%c is non-standard", c);
E 4
I 4
			    yerror("%c is non-standard", (char *) c);
E 4
			}
			return c;
E 3
		default:
			switch (c) {
				case YDOTDOT:
					return (c);
				case '\n':
					c = readch();
#ifdef PXP
					yytokcnt++;
#endif
					goto next;
				case '\f':
					c = readch();
					goto next;
			}
			if (c <= 0)
				return (YEOF);
illch:
			do
				yysavc = readch();
			while (yysavc == c);
			yylval = c;
			return (YILLCH);
	}
}

yyset()
{

	yyecol = yycol;
	yyeline = yyline;
	yyefile = filename;
	yyseekp = yylinpt;
}

/*
 * Setuflg trims the current
 * input line to at most 72 chars
 * for the u option.
 */
setuflg()
{

	if (charbuf[71] != '\n') {
		charbuf[72] = '\n';
		charbuf[73] = 0;
	}
}
E 1
