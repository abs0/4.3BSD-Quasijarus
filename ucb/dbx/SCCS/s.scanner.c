h23413
s 00007/00001/00831
d D 5.1 85/05/31 10:16:22 dist 15 14
c Add copyright
e
s 00635/00446/00197
d D 1.12 85/03/01 20:30:50 linton 14 13
c update to version 3.0
e
s 00001/00001/00642
d D 1.11 84/08/17 21:25:00 sam 13 12
c remove \n from error call
e
s 00450/00445/00193
d D 1.10 84/08/12 13:22:30 sam 12 11
c add real aliases; rewrite lexical scanner
e
s 00001/00003/00637
d D 1.9 84/06/23 11:43:35 sam 11 8
i 10
c merge linton branch delta trail
e
s 00016/00017/00624
d D 1.8.1.1 84/06/23 10:50:06 sam 10 8
c branch delta of linton changes from net.sources
e
s 00001/00000/00641
d R 1.9 83/08/18 14:50:49 sam 9 8
c must clear EOF flag when reading from tty, else (since ignored) 
c you get an infinite stream of them....see changes in 4.2 or filbuf.c in libc.ca
e
s 00002/00001/00639
d D 1.8 83/08/05 00:47:19 linton 8 7
c fixed problem with not clearing input on an EOF (^D) and changed the prompt
e
s 00001/00000/00639
d D 1.7 83/05/17 22:39:01 linton 7 6
c fixed problem with setting curchar in getstring
e
s 00005/00001/00634
d D 1.6 83/04/29 11:46:30 linton 6 5
c fixed problem with numeric arguments to run
e
s 00002/00017/00633
d D 1.5 83/03/30 00:39:00 linton 5 4
c no longer prompts initially before beginning reading
e
s 00010/00013/00640
d D 1.4 83/03/13 15:19:27 linton 4 3
c cleaned up character constant processing
e
s 00002/00002/00651
d D 1.3 83/02/17 23:03:03 linton 3 2
c fixed string/character constant glitch
e
s 00001/00001/00652
d D 1.2 82/12/15 04:22:04 linton 2 1
c fixed @(#) stuff
e
s 00653/00000/00000
d D 1.1 82/12/15 04:08:41 linton 1 0
c date and time created 82/12/15 04:08:41 by linton
e
u
U
f b 
t
T
I 1
D 15
/* Copyright (c) 1982 Regents of the University of California */
E 15
I 15
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 15

I 15
#ifndef lint
E 15
D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 10
static char sccsid[] = "%Z%%M% %I% %G%";
E 10
I 10
D 11
static char sccsid[] = "@(#)scanner.c 1.8 8/5/83";
E 10
E 2

I 10
static char rcsid[] = "$Header: scanner.c,v 1.3 84/03/27 10:23:50 linton Exp $";
E 11
I 11
D 12
static	char sccsid[] = "%W% (Berkeley) %G%";
E 12
I 12
static char sccsid[] = "%W% (Berkeley) %G%";
I 15
#endif not lint
E 15
E 12
E 11

I 14
static char rcsid[] = "$Header: scanner.c,v 1.5 84/12/26 10:42:05 linton Exp $";

E 14
E 10
/*
 * Debugger scanner.
 */

I 12
D 14
#include <ctype.h>
E 14
E 12
#include "defs.h"
#include "scanner.h"
#include "main.h"
#include "keywords.h"
#include "tree.h"
#include "symbols.h"
#include "names.h"
#include "y.tab.h"

#ifndef public
typedef int Token;
D 14
#endif
E 14

D 12
public String initfile = ".dbxinit";
E 12
I 12
D 14
typedef struct {
	int	s_type;
#define	ST_FILE		0
#define	ST_ALIAS	1
	char	*s_name;
	int	s_lineno;
	union {
		File	su_file;
		struct sum {
			char	*sum_data;
			char	*sum_cur;
		} su_macro;
	} su;
#define	s_file	su.su_file
#define	s_macro	su.su_macro
#define	s_data	s_macro.sum_data
#define	s_cur	s_macro.sum_cur
} STREAM;
E 14
I 14
#define MAXLINESIZE 10240
E 14
E 12

D 12
typedef enum { WHITE, ALPHA, NUM, OTHER } Charclass;
E 12
I 12
D 14
#define	NSTREAMS	10
private	STREAM stack[NSTREAMS];
private	STREAM *sp = &stack[-1];
E 14
I 14
#endif
E 14
E 12

D 12
private Charclass class[256 + 1];
private Charclass *lexclass = class + 1;
E 12
I 12
public String initfile = ".dbxinit";
E 12

I 14
typedef enum { WHITE, ALPHA, NUM, OTHER } Charclass;

private Charclass class[256 + 1];
private Charclass *lexclass = class + 1;

#define isdigit(c) (lexclass[c] == NUM)
#define isalnum(c) (lexclass[c] == ALPHA or lexclass[c] == NUM)
#define ishexdigit(c) ( \
    isdigit(c) or (c >= 'a' and c <= 'f') or (c >= 'A' and c <= 'F') \
)

public boolean chkalias;
public char scanner_linebuf[MAXLINESIZE];

private File in;
private char *curchar, *prevchar;

#define MAXINCLDEPTH 10

private struct {
    File savefile;
    Filename savefn;
    int savelineno;
} inclinfo[MAXINCLDEPTH];

private unsigned int curinclindex;

E 14
D 12
#define isdigit(c) (lexclass[c] == NUM)
#define isalnum(c) (lexclass[c] == ALPHA or lexclass[c] == NUM)
#define ishexdigit(c) ( \
    isdigit(c) or (c >= 'a' and c <= 'f') or (c >= 'A' and c <= 'F') \
)

#define MAXLINESIZE 1024

private File in;
private Char linebuf[MAXLINESIZE];
D 10
private Char *curchar;
E 10
I 10
private Char *curchar, *prevchar;
E 10

#define MAXINCLDEPTH 10

private struct {
    File savefile;
    Filename savefn;
    int savelineno;
} inclinfo[MAXINCLDEPTH];

private unsigned int curinclindex;

E 12
D 5
private Boolean firsttoken = true;
private Boolean firstinit = true;

E 5
private Token getident();
private Token getnum();
private Token getstring();
D 12
private Boolean eofinput();
E 12
D 14
private Char charcon();
E 14
I 14
private Boolean eofinput();
private char charcon();
E 14
D 12
private Char charlookup();
E 12

D 12
private enterlexclass(class, s)
Charclass class;
String s;
{
    register char *p;
E 12
I 12
D 14
#define MAXLINESIZE 1024
private Char yytext[MAXLINESIZE];
private Boolean shellmode;
private	Boolean doaliases;
E 14
I 14
private enterlexclass(class, s)
Charclass class;
String s;
{
    register char *p;
E 14
E 12

I 14
    for (p = s; *p != '\0'; p++) {
	lexclass[*p] = class;
    }
}

E 14
D 12
    for (p = s; *p != '\0'; p++) {
	lexclass[*p] = class;
    }
}

E 12
public scanner_init()
{
D 12
    register Integer i;
E 12
I 12
D 14
	register Integer i;
E 14
I 14
    register Integer i;
E 14
E 12

D 12
    for (i = 0; i < 257; i++) {
	class[i] = OTHER;
    }
    enterlexclass(WHITE, " \t");
    enterlexclass(ALPHA, "abcdefghijklmnopqrstuvwxyz");
    enterlexclass(ALPHA, "ABCDEFGHIJKLMNOPQRSTUVWXYZ_$");
    enterlexclass(NUM, "0123456789");
    in = stdin;
    errfilename = nil;
    errlineno = 0;
    curchar = linebuf;
    linebuf[0] = '\0';
E 12
I 12
D 14
	if (sp < stack)
		(void) pushinput(ST_FILE, nil, stdin);
	shellmode = false;
	doaliases = true;
	errfilename = nil;
	errlineno = sp->s_lineno = 0;
	yytext[0] = '\0';
E 14
I 14
    for (i = 0; i < 257; i++) {
	class[i] = OTHER;
    }
    enterlexclass(WHITE, " \t");
    enterlexclass(ALPHA, "abcdefghijklmnopqrstuvwxyz");
    enterlexclass(ALPHA, "ABCDEFGHIJKLMNOPQRSTUVWXYZ_$");
    enterlexclass(NUM, "0123456789");
    in = stdin;
    errfilename = nil;
    errlineno = 0;
    curchar = scanner_linebuf;
    scanner_linebuf[0] = '\0';
    chkalias = true;
E 14
E 12
D 5
    if (runfirst) {
	firstinit = false;
	firsttoken = false;
    } else if (firstinit and isterm(in)) {
	firstinit = false;
	printf("> ");
	fflush(stdout);
    }
E 5
}

I 12
D 14
#define	MAXDEPTH	25
E 14
E 12
/*
 * Read a single token.
I 14
 *
 * The input is line buffered.  Tokens cannot cross line boundaries.
 *
E 14
D 12
 *
 * Input is line buffered.
 *
E 12
 * There are two "modes" of operation:  one as in a compiler,
D 14
 * and one for reading shell-like syntax.
E 14
I 14
 * and one for reading shell-like syntax.  In the first mode
 * there is the additional choice of doing alias processing.
E 14
 */
I 14

private Boolean shellmode;

E 14
D 12

private Boolean shellmode;

E 12
public Token yylex()
{
D 12
    register int c;
    register char *p;
    register Token t;
    String line;
E 12
I 12
D 14
	register int c;
	register char *p;
	register Token t;
	static int depth = 0;
E 14
I 14
    register int c;
    register char *p;
    register Token t;
    String line;
    integer n;
E 14
E 12

D 12
    p = curchar;
    if (*p == '\0') {
	do {
	    if (isterm(in)) {
D 5
		if (firsttoken) {
		    firsttoken = false;
		} else {
		    printf("> ");
		    fflush(stdout);
		}
E 5
I 5
D 8
		printf("> ");
E 8
I 8
		printf("(%s) ", cmdname);
E 8
		fflush(stdout);
E 5
	    }
	    line = fgets(linebuf, MAXLINESIZE, in);
	} while (line == nil and not eofinput());
	if (line == nil) {
	    c = EOF;
	} else {
	    p = linebuf;
	    while (lexclass[*p] == WHITE) {
		p++;
	    }
	    shellmode = false;
E 12
I 12
D 14
	depth++;
	if (depth > MAXDEPTH) {
	    depth = 0;
D 13
	    error("Alias loop (maximum %d deep).\n", MAXDEPTH);
E 13
I 13
	    error("alias loop (maximum %d deep)", MAXDEPTH);
E 14
I 14
    p = curchar;
    if (*p == '\0') {
	do {
	    if (isterm(in)) {
		printf("(%s) ", cmdname);
	    }
	    fflush(stdout);
	    line = fgets(scanner_linebuf, MAXLINESIZE, in);
	} while (line == nil and not eofinput());
	if (line == nil) {
	    c = EOF;
	} else {
	    p = scanner_linebuf;
	    while (lexclass[*p] == WHITE) {
		p++;
	    }
	    shellmode = false;
E 14
E 13
E 12
	}
D 12
    } else {
	while (lexclass[*p] == WHITE) {
	    p++;
E 12
I 12
D 14
again:
	do
		c = getch();
	while (c == ' ' || c == '\t');
	if (isalpha(c) || c == '_' || c == '$') {
		t = getident(c);
		if (t == NAME && doaliases) {
			p = findalias(yylval.y_name);
			if (p != nil) {
				if (lexdebug)
					fprintf(stderr, "alias %s to \"%s\"\n",
					    ident(yylval.y_name), p);
				if (!pushinput(ST_ALIAS, "", p)) {
					unwindinput(ST_ALIAS);
					error("Alias stack overflow.");
				}
				t = yylex();
			}
		}
		goto done;
E 14
I 14
	chkalias = true;
    } else {
	while (lexclass[*p] == WHITE) {
	    p++;
E 14
E 12
	}
D 12
    }
    curchar = p;
I 10
    prevchar = curchar;
E 10
    c = *p;
    if (lexclass[c] == ALPHA) {
	t = getident();
    } else if (lexclass[c] == NUM) {
D 6
	t = getnum();
E 6
I 6
	if (shellmode) {
	    t = getident();
	} else {
	    t = getnum();
E 12
I 12
D 14
	if (isdigit(c)) {
		t = shellmode ? getident(c) : getnum(c);
		goto done;
E 14
I 14
    }
    curchar = p;
    prevchar = curchar;
    c = *p;
    if (lexclass[c] == ALPHA) {
	t = getident(chkalias);
    } else if (lexclass[c] == NUM) {
	if (shellmode) {
	    t = getident(chkalias);
	} else {
	    t = getnum();
E 14
E 12
	}
I 14
    } else {
	++curchar;
E 14
E 6
D 12
    } else {
	++curchar;
E 12
	switch (c) {
D 12
	    case '\n':
E 12
I 12
D 14

	case '\n':
E 14
I 14
	    case '\n':
E 14
E 12
		t = '\n';
D 12
		if (errlineno != 0) {
		    errlineno++;
E 12
I 12
D 14
		if (sp->s_lineno != 0) {
			sp->s_lineno++;
			if (sp->s_type == ST_FILE)
				errlineno = sp->s_lineno;
E 14
I 14
		if (errlineno != 0) {
		    errlineno++;
E 14
E 12
		}
		break;

D 12
	    case '"':
	    case '\'':
		t = getstring();
E 12
I 12
D 14
	case '"':
	case '\'':
E 14
I 14
	    case '"':
	    case '\'':
E 14
		t = getstring(c);
E 12
		break;

D 12
	    case '.':
E 12
I 12
D 14
	case '.':
E 14
I 14
	    case '.':
E 14
E 12
		if (shellmode) {
D 12
		    --curchar;
		    t = getident();
		} else if (isdigit(*curchar)) {
		    --curchar;
		    t = getnum();
		} else {
		    t = '.';
E 12
I 12
D 14
			t = getident(c);
			break;
E 14
I 14
		    --curchar;
		    t = getident(chkalias);
		} else if (isdigit(*curchar)) {
		    --curchar;
		    t = getnum();
		} else {
		    t = '.';
E 14
E 12
		}
I 12
D 14
		c = getch();
		ungetch(c);
		t = isdigit(c) ? getnum('.') : '.';
E 14
E 12
		break;

D 12
	    case '<':
		if (not shellmode and *curchar == '<') {
		    ++curchar;
		    t = LFORMER;
		} else {
		    t = '<';
		}
E 12
I 12
D 14
	case '<':
		c = getch();
		if (shellmode || c != '<') {
			ungetch(c);
			t = '<';
		} else
			t = LFORMER;
E 14
I 14
	    case '-':
		if (shellmode) {
		    --curchar;
		    t = getident(chkalias);
		} else if (*curchar == '>') {
		    ++curchar;
		    t = ARROW;
		} else {
		    t = '-';
		}
E 14
E 12
		break;

D 12
	    case '>':
		if (not shellmode and *curchar == '>') {
		    ++curchar;
		    t = RFORMER;
		} else {
		    t = '>';
		}
E 12
I 12
D 14
	case '>':
		c = getch();
		if (shellmode || c != '>') {
			ungetch(c);
			t = '>';
		} else
			t = RFORMER;
E 14
I 14
	    case '#':
		if (not isterm(in)) {
		    *p = '\0';
		    curchar = p;
		    t = '\n';
		    ++errlineno;
		} else {
		    t = '#';
		}
E 14
E 12
		break;

D 12
	    case '#':
		if (*curchar == '^') {
		    ++curchar;
		    t = ABSTRACTION;
		} else {
		    t = '#';
		}
E 12
I 12
D 14
	case '#':
		c = getch();
		if (c != '^') {
			ungetch(c);
			t = '#';
		} else
			t = ABSTRACTION;
E 12
		break;

D 12
	    case '-':
E 12
I 12
	case '-':
E 12
		if (shellmode) {
D 12
		    --curchar;
		    t = getident();
		} else if (*curchar == '>') {
		    ++curchar;
		    t = ARROW;
		} else {
		    t = '-';
E 12
I 12
			t = getident(c);
			break;
E 14
I 14
	    case '\\':
		if (*(p+1) == '\n') {
		    n = MAXLINESIZE - (p - &scanner_linebuf[0]);
		    if (n > 1) {
			if (fgets(p, n, in) == nil) {
			    t = 0;
			} else {
			    curchar = p;
			    t = yylex();
			}
		    } else {
			t = '\\';
		    }
		} else {
		    t = '\\';
E 14
E 12
		}
I 12
D 14
		c = getch();
		if (c != '>') {
			ungetch(c);
			t = '-';
		} else
			t = ARROW;
E 14
E 12
		break;

D 12
	    case EOF:
E 12
I 12
D 14
	case EOF:
E 14
I 14
	    case EOF:
E 14
E 12
		t = 0;
		break;

D 12
	    default:
		if (shellmode and index("!&*()[]", c) == nil) {
		    --curchar;
		    t = getident();
		} else {
		    t = c;
		}
E 12
I 12
D 14
	default:
		t = shellmode && index("!&*()[];", c) == nil ?
		    getident(c) : c;
E 14
I 14
	    default:
		if (shellmode and index("!&*<>()[]", c) == nil) {
		    --curchar;
		    t = getident(chkalias);
		} else {
		    t = c;
		}
E 14
E 12
		break;
	}
D 12
    }
#   ifdef LEXDEBUG
E 12
I 12
D 14
done:
E 14
I 14
    }
    chkalias = false;
#   ifdef LEXDEBUG
E 14
E 12
	if (lexdebug) {
D 12
	    fprintf(stderr, "yylex returns ");
	    print_token(stderr, t);
	    fprintf(stderr, "\n");
E 12
I 12
D 14
		fprintf(stderr, "token ");
		print_token(stderr, t);
		fprintf(stderr, "\n");
E 14
I 14
	    fprintf(stderr, "yylex returns ");
	    print_token(stderr, t);
	    fprintf(stderr, "\n");
E 14
E 12
	}
D 12
#   endif
    return t;
E 12
I 12
D 14
	depth--;
	return (t);
E 14
I 14
#   endif
    return t;
E 14
E 12
}

/*
D 12
 * Parser error handling.
E 12
I 12
D 14
 * Scan an identifier and check to see if it's a keyword.
E 14
I 14
 * Put the given string before the current character
 * in the current line, thus inserting it into the input stream.
E 14
E 12
 */
D 12

public yyerror(s)
String s;
E 12
I 12
D 14
private Token getident(c)
Char c;
E 12
{
D 10
    register Char *p, *tokenbegin, *tokenend;
    register Integer len;
E 10
I 10
D 12
    register char *p;
    register integer start;
E 12
I 12
	register Char *p, *q;
	Token t;
E 14
E 12
E 10

D 12
    if (streq(s, "syntax error")) {
	beginerrmsg();
D 10
	tokenend = curchar - 1;
	tokenbegin = tokenend;
	while (lexclass[*tokenbegin] != WHITE and tokenbegin > &linebuf[0]) {
	    --tokenbegin;
	}
	len = tokenend - tokenbegin + 1;
	p = tokenbegin;
E 10
I 10
	p = prevchar;
	start = p - &linebuf[0];
E 10
	if (p > &linebuf[0]) {
	    while (lexclass[*p] == WHITE and p > &linebuf[0]) {
		--p;
	    }
	}
I 10
	fprintf(stderr, "%s", linebuf);
	if (start != 0) {
	    fprintf(stderr, "%*c", start, ' ');
	}
E 10
	if (p == &linebuf[0]) {
D 10
	    fprintf(stderr, "unrecognized command \"%.*s\"", len, tokenbegin);
E 10
I 10
	    fprintf(stderr, "^ unrecognized command");
E 12
I 12
D 14
	q = yytext;
	if (shellmode) {
		do {
			*q++ = c;
			c = getch();
		} while (index(" \t\n!&<>*[]();", c) == nil);
E 12
E 10
	} else {
D 10
	    fprintf(stderr, "syntax error");
	    if (len != 0) {
		fprintf(stderr, " on \"%.*s\"", len, tokenbegin);
	    }
E 10
I 10
D 12
	    fprintf(stderr, "^ syntax error");
E 12
I 12
		do {
			*q++ = c;
			c = getch();
		} while (isalnum(c) || c == '_' || c == '$');
E 12
E 10
	}
D 12
	enderrmsg();
    } else {
	error(s);
    }
}

/*
 * Eat the current line.
 */

public gobble()
{
    curchar = linebuf;
    linebuf[0] = '\0';
}

/*
 * Scan an identifier and check to see if it's a keyword.
 */

private Token getident()
{
    char buf[256];
    register Char *p, *q;
    register Token t;

    p = curchar;
    q = buf;
    if (shellmode) {
	do {
	    *q++ = *p++;
D 10
	} while (index(" \t\n!&<>*[]()", *p) == nil);
E 10
I 10
	} while (index(" \t\n!&<>*[]()'\"", *p) == nil);
E 10
    } else {
	do {
	    *q++ = *p++;
	} while (isalnum(*p));
    }
    curchar = p;
    *q = '\0';
    yylval.y_name = identname(buf, false);
    if (not shellmode) {
E 12
I 12
	ungetch(c);
	*q = '\0';
	yylval.y_name = identname(yytext, false);
	if (shellmode)
		return (NAME);
E 12
	t = findkeyword(yylval.y_name);
D 12
	if (t == nil) {
	    t = NAME;
	}
    } else {
	t = NAME;
    }
    return t;
E 12
I 12
	return (t == nil ? NAME : t);
E 12
}

/*
 * Scan a number.
 */
D 12

private Token getnum()
E 12
I 12
private Token getnum(c)
Char c;
E 14
I 14
public insertinput (s)
String s;
E 14
E 12
{
D 12
    char buf[256];
    register Char *p, *q;
    register Token t;
    Integer base;
E 12
I 12
D 14
	register Char *q;
	register Token t;
	Integer base = 10;
E 14
I 14
    register char *p, *q;
    int need, avail, shift;
E 14
E 12

D 12
    p = curchar;
    q = buf;
    if (*p == '0') {
	if (*(p+1) == 'x') {
	    p += 2;
	    base = 16;
E 12
I 12
D 14
	q = yytext;
	if (c == '0') {
		c = getch();
		if (c == 'x') {
			base = 16;
		} else {
			base = 8;
			ungetch(c);
			c = '0';
		}
E 14
I 14
    q = s;
    need = strlen(q);
    avail = curchar - &scanner_linebuf[0];
    if (need <= avail) {
	curchar = &scanner_linebuf[avail - need];
	p = curchar;
	while (*q != '\0') {
	    *p++ = *q++;
E 14
	}
D 14
	if (base == 16) {
		while (isdigit(c = getch()) ||
		    (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
			*q++ = c;
E 12
	} else {
D 12
	    base = 8;
E 12
I 12
		do {
			*q++ = c;
			c = getch();
		} while (isdigit(c));
E 14
I 14
    } else {
	p = curchar;
	while (*p != '\0') {
	    ++p;
E 14
E 12
	}
D 12
    } else {
	base = 10;
    }
    if (base == 16) {
	do {
	    *q++ = *p++;
	} while (ishexdigit(*p));
    } else {
	do {
	    *q++ = *p++;
	} while (isdigit(*p));
    }
    if (*p == '.') {
	do {
	    *q++ = *p++;
	} while (isdigit(*p));
	if (*p == 'e' or *p == 'E') {
	    p++;
	    if (*p == '+' or *p == '-' or isdigit(*p)) {
		*q++ = 'e';
E 12
I 12
D 14
	if (c == '.') {
E 12
		do {
D 12
		    *q++ = *p++;
		} while (isdigit(*p));
	    }
E 12
I 12
			*q++ = c;
			c = getch();
		} while (isdigit(c));
		if (c == 'e' || c == 'E') {
			c = getch();
			if (c == '+' || c == '-' || isdigit(c)) {
				*q++ = 'e';
				do {
					*q++ = c;
					c = getch();
				} while (isdigit(c));
			}
		}
		ungetch(c);
		*q = '\0';
		yylval.y_real = atof(yytext);
		return (REAL);
E 14
I 14
	shift = need - avail;
	if (p + shift >= &scanner_linebuf[MAXLINESIZE]) {
	    error("alias expansion too large");
E 14
E 12
	}
I 12
D 14
	ungetch(c);
E 12
	*q = '\0';
D 12
	yylval.y_real = atof(buf);
	t = REAL;
    } else {
	*q = '\0';
E 12
	switch (base) {
D 12
	    case 10:
		yylval.y_int = atol(buf);
E 12
I 12

	case 10:
		yylval.y_int = atol(yytext);
E 14
I 14
	for (;;) {
	    *(p + shift) = *p;
	    if (p == curchar) {
E 14
E 12
		break;
D 14

D 12
	    case 8:
		yylval.y_int = octal(buf);
E 12
I 12
	case 8:
		yylval.y_int = octal(yytext);
E 12
		break;

D 12
	    case 16:
		yylval.y_int = hex(buf);
E 12
I 12
	case 16:
		yylval.y_int = hex(yytext);
E 12
		break;

D 12
	    default:
E 12
I 12
	default:
E 12
		badcaseval(base);
E 14
I 14
	    }
	    --p;
E 14
	}
D 12
	t = INT;
    }
    curchar = p;
    return t;
E 12
I 12
D 14
	return (INT);
E 14
I 14
	p = &scanner_linebuf[0];
	while (*q != '\0') {
	    *p++ = *q++;
	}
	curchar = &scanner_linebuf[0];
    }
E 14
E 12
}

/*
D 14
 * Convert a string of octal digits to an integer.
E 14
I 14
 * Get the actuals for a macro call.
E 14
 */
D 12

E 12
D 14
private int octal(s)
String s;
{
D 12
    register Char *p;
    register Integer n;
E 12
I 12
	register Char *p;
	register Integer n;
E 14
E 12

D 12
    n = 0;
    for (p = s; *p != '\0'; p++) {
	n = 8*n + (*p - '0');
    }
    return n;
E 12
I 12
D 14
	n = 0;
	for (p = s; *p != '\0'; p++)
		n = (n << 3) + (*p - '0');
	return (n);
E 12
}

/*
 * Convert a string of hexadecimal digits to an integer.
 */
D 12

E 12
private int hex(s)
String s;
E 14
I 14
private String movetochar (str, c)
String str;
char c;
E 14
{
D 12
    register Char *p;
    register Integer n;
E 12
I 12
D 14
	register Char *p;
	register Integer n;
E 14
I 14
    register char *p;
E 14
E 12

D 12
    n = 0;
    for (p = s; *p != '\0'; p++) {
	n *= 16;
	if (*p >= 'a' and *p <= 'f') {
	    n += (*p - 'a' + 10);
	} else if (*p >= 'A' and *p <= 'F') {
	    n += (*p - 'A' + 10);
	} else {
	    n += (*p - '0');
E 12
I 12
D 14
	n = 0;
	for (p = s; *p != '\0'; p++) {
		n <<= 4;
		if (*p >= 'a' && *p <= 'f')
			n += (*p - 'a' + 10);
		else if (*p >= 'A' && *p <= 'F')
			n += (*p - 'A' + 10);
		else
			n += (*p - '0');
E 14
I 14
    while (*p != c) {
	if (*p == '\0') {
	    error("missing ')' in macro call");
	} else if (*p == ')') {
	    error("not enough parameters in macro call");
	} else if (*p == ',') {
	    error("too many parameters in macro call");
E 14
E 12
	}
D 12
    }
    return n;
E 12
I 12
D 14
	return (n);
E 14
I 14
	++p;
    }
    return p;
E 14
E 12
}

D 14
/*
 * Scan a string.
 */
D 12

private Token getstring()
E 12
I 12
private Token getstring(match)
Char match;
E 14
I 14
private String *getactuals (n)
integer n;
E 14
E 12
{
D 12
    char buf[256];
    register Char *p, *q;
    Boolean endofstring;
E 12
I 12
D 14
	register Char *q, c;
E 14
I 14
    String *a;
    register char *p;
    int i;
E 14
E 12

D 12
    p = curchar;
    q = buf;
    endofstring = false;
    while (not endofstring) {
	if (*p == '\n' or *p == '\0') {
	    error("non-terminated string");
	    endofstring = true;
D 3
	} else if (*p == '"') {
	    if (*(p+1) != '"') {
E 3
I 3
	} else if (*p == '"' or *p == '\'') {
	    if (*(p+1) != *p) {
E 3
		endofstring = true;
	    } else {
		*q++ = *p;
	    }
	} else {
I 7
	    curchar = p;
E 7
D 4
	    *q++ = charcon(*p);
E 4
I 4
	    *q++ = charcon(p);
	    p = curchar;
E 12
I 12
D 14
	q = yytext;
	for (;;) {
		c = getch();
		if (c == '\n' || c == EOF) {
			error("Unterminated string.");
			break;
		}
		if (c == match)
			break;
		*q++ = charcon(c);
E 14
I 14
    a = newarr(String, n);
    p = curchar;
    while (*p != '(') {
	if (lexclass[*p] != WHITE) {
	    error("missing actuals for macro");
E 14
E 12
E 4
	}
D 12
	p++;
    }
    curchar = p;
    *q = '\0';
    yylval.y_string = strdup(buf);
    return STRING;
E 12
I 12
D 14
	*q = '\0';
	yylval.y_string = strdup(yytext);
	return (STRING);
E 14
I 14
	++p;
    }
    ++p;
    for (i = 0; i < n - 1; i++) {
	a[i] = p;
	p = movetochar(p, ',');
	*p = '\0';
	++p;
    }
    a[n-1] = p;
    p = movetochar(p, ')');
    *p = '\0';
    curchar = p + 1;
    return a;
E 14
E 12
}

/*
D 14
 * Process a character constant.
 * Watch out for backslashes.
E 14
I 14
 * Do command macro expansion, assuming curchar points to the beginning
 * of the actuals, and we are not in shell mode.
E 14
 */
D 12

D 4
private Char charcon(ch)
Char ch;
E 4
I 4
private Char charcon(p)
char *p;
E 12
I 12
D 14
private Char charcon(c)
Char c;
E 14
I 14

private expand (pl, str)
List pl;
String str;
E 14
E 12
E 4
{
D 4
    Char c, buf[10], *p, *q;
E 4
I 4
D 12
    char c, buf[10], *q;
E 12
I 12
D 14
	register char *cp;
E 14
I 14
    char buf[4096], namebuf[100];
    register char *p, *q, *r;
    String *actual;
    Name n;
    integer i;
    boolean match;
E 14
E 12
E 4

D 4
    p = curchar;
    if (ch == '\\') {
E 4
I 4
D 12
    if (*p == '\\') {
	++p;
E 4
	if (*p != '\\') {
	    q = buf;
	    do {
		*q++ = *p++;
D 4
	    } while (*p != '\\' and *p != '\n' and *p != '\0');
	    if (*p != '\\') {
		ungetc(*p, in);
		error("non-terminated character constant");
	    }
E 4
I 4
	    } while (*p != '\\' and *p != '\'' and *p != '\n' and *p != '\0');
E 4
	    *q = '\0';
	    if (isdigit(buf[0])) {
		c = (Char) octal(buf);
	    } else {
		c = charlookup(buf);
	    }
D 4
	    curchar = p;
E 4
I 4
	    curchar = p - 1;
E 4
	} else {
	    c = '\\';
E 12
I 12
D 14
	if (c == '\\') {
		c = getch();
		if (isdigit(c)) {
			int v;

			v = 0;
			do {
				v = (v << 3) + (c - '0');
				c = getch();
			} while (isdigit(c));
			ungetch(c);
			return (v);
E 14
I 14
    if (pl == nil) {
	insertinput(str);
    } else {
	actual = getactuals(list_size(pl));
	p = buf;
	q = str;
	while (*q != '\0') {
	    if (p >= &buf[4096]) {
		error("alias expansion too large");
	    }
	    if (lexclass[*q] == ALPHA) {
		r = namebuf;
		do {
		    *r++ = *q++;
		} while (isalnum(*q));
		*r = '\0';
		i = 0;
		match = false;
		foreach(Name, n, pl)
		    if (streq(ident(n), namebuf)) {
			match = true;
			break;
		    }
		    ++i;
		endfor
		if (match) {
		    r = actual[i];
		} else {
		    r = namebuf;
E 14
		}
D 14
		for (cp = "f\ft\tb\bn\nr\rv\v"; *cp != c; cp += 2)
			;
		if (*cp != '\0')
			c = *cp;
E 14
I 14
		while (*r != '\0') {
		    *p++ = *r++;
		}
	    } else {
		*p++ = *q++;
	    }
E 14
E 12
	}
D 12
    } else {
D 4
	c = ch;
E 4
I 4
	c = *p;
E 4
    }
    return c;
E 12
I 12
D 14
	return (c);
E 14
I 14
	*p = '\0';
	insertinput(buf);
    }
E 14
E 12
}

/*
D 12
 * Do a lookup for a ASCII character name.
E 12
I 12
 * Parser error handling.
E 12
 */
I 14

E 14
D 12

private String ascii[] = {
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    "BS",  "HT",  "NL",  "VT",  "NP",  "CR",  "SO",  "SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM",  "SUB", "ESC", "FS",  "GS",  "RS",  "US",
    "SP", nil
};

private char charlookup(s)
E 12
I 12
public yyerror(s)
E 12
String s;
{
I 14
    register char *p;
    register integer start;
E 14
D 12
    register int i;
E 12

D 12
    for (i = 0; ascii[i] != NULL; i++) {
	if (streq(s, ascii[i])) {
	    return i;
E 12
I 12
D 14
	if (streq(s, "syntax error")) {
		beginerrmsg();
		fprintf(stderr, "Syntax error");
		if (yytext[0] != '\0')
			fprintf(stderr, " on \"%s\".", yytext);
		enderrmsg();
		return;
E 14
I 14
    if (streq(s, "syntax error")) {
	beginerrmsg();
	p = prevchar;
	start = p - &scanner_linebuf[0];
	if (p > &scanner_linebuf[0]) {
	    while (lexclass[*p] == WHITE and p > &scanner_linebuf[0]) {
		--p;
	    }
E 14
E 12
	}
I 14
	fprintf(stderr, "%s", scanner_linebuf);
	if (start != 0) {
	    fprintf(stderr, "%*c", start, ' ');
	}
	if (p == &scanner_linebuf[0]) {
	    fprintf(stderr, "^ unrecognized command");
	} else {
	    fprintf(stderr, "^ syntax error");
	}
	enderrmsg();
    } else {
E 14
D 12
    }
    if (streq(s, "DEL")) {
	return 0177;
    }
    error("unknown ascii name \"%s\"", s);
    return '?';
E 12
I 12
	error(s);
I 14
    }
E 14
E 12
}

/*
D 12
 * Input file management routines.
E 12
I 12
 * Eat the current line.
E 12
 */
I 12
D 14
private Char lastc = '\0';
E 14
E 12

I 12
D 14
public gobble()
E 14
I 14
public gobble ()
E 14
{
D 14
	register char c;

	if (lastc != '\n' && lastc != EOF)
		while ((c = getch()) != EOF && c != '\n')
			;
E 14
I 14
    curchar = scanner_linebuf;
    scanner_linebuf[0] = '\0';
E 14
}

/*
D 14
 * Input file management routines.
E 14
I 14
 * Scan an identifier.
 *
 * If chkalias is true, check first to see if it's an alias.
 * Otherwise, check to see if it's a keyword.
E 14
 */
E 12
D 14
public setinput(filename)
Filename filename;
E 14
I 14

private Token getident (chkalias)
boolean chkalias;
E 14
{
D 12
    File f;
E 12
I 12
D 14
	File f;
E 14
I 14
    char buf[1024];
    register char *p, *q;
    register Token t;
    List pl;
    String str;
E 14
E 12

D 12
    f = fopen(filename, "r");
    if (f == nil) {
	error("can't open %s", filename);
    } else {
	if (curinclindex >= MAXINCLDEPTH) {
	    error("unreasonable input nesting on \"%s\"", filename);
E 12
I 12
D 14
	f = fopen(filename, "r");
	if (f == nil)
		error("%s: Can't open.", filename);
	if (!pushinput(ST_FILE, filename, f)) {
		unwindinput(ST_FILE);
		error("Source file nesting too deep.");
E 14
I 14
    p = curchar;
    q = buf;
    if (shellmode) {
	do {
	    *q++ = *p++;
	} while (index(" \t\n!&<>*[]()'\"", *p) == nil);
    } else {
	do {
	    *q++ = *p++;
	} while (isalnum(*p));
    }
    curchar = p;
    *q = '\0';
    yylval.y_name = identname(buf, false);
    if (chkalias) {
	if (findalias(yylval.y_name, &pl, &str)) {
	    expand(pl, str);
	    while (lexclass[*curchar] == WHITE) {
		++curchar;
	    }
	    if (pl == nil) {
		t = getident(false);
	    } else {
		t = getident(true);
	    }
	} else if (shellmode) {
	    t = NAME;
	} else {
	    t = findkeyword(yylval.y_name, NAME);
E 14
E 12
	}
I 14
    } else if (shellmode) {
	t = NAME;
    } else {
	t = findkeyword(yylval.y_name, NAME);
    }
    return t;
E 14
D 12
	inclinfo[curinclindex].savefile = in;
	inclinfo[curinclindex].savefn = errfilename;
	inclinfo[curinclindex].savelineno = errlineno;
	curinclindex++;
	in = f;
	errfilename = filename;
	errlineno = 1;
    }
E 12
}

D 12
private Boolean eofinput()
E 12
I 12
/*
D 14
 * Send the current line to the shell.
E 14
I 14
 * Scan a number.
E 14
 */
D 14
public shellline()
E 14
I 14

private Token getnum()
E 14
E 12
{
D 12
    register Boolean b;
E 12
I 12
D 14
	register Char *p, c;
E 14
I 14
    char buf[1024];
    register Char *p, *q;
    register Token t;
    Integer base;
E 14
E 12

D 12
    if (curinclindex == 0) {
	if (isterm(in)) {
	    putchar('\n');
I 8
	    clearerr(in);
E 8
	    b = false;
	} else {
	    b = true;
	}
    } else {
	fclose(in);
	--curinclindex;
	in = inclinfo[curinclindex].savefile;
	errfilename = inclinfo[curinclindex].savefn;
	errlineno = inclinfo[curinclindex].savelineno;
	b = false;
    }
    return b;
E 12
I 12
D 14
	for (p = yytext; (c = getch()) != EOF && c != '\n'; *p++ = c)
		;
	*p = '\0';
	shell(yytext);
	erecover();
E 14
I 14
    p = curchar;
    q = buf;
    if (*p == '0') {
	if (*(p+1) == 'x') {
	    p += 2;
	    base = 16;
	} else if (*(p+1) == 't') {
	    base = 10;
	} else if (varIsSet("$hexin")) {
	    base = 16;
	} else {
	    base = 8;
	}
    } else if (varIsSet("$hexin")) {
	base = 16;
    } else if (varIsSet("$octin")) {
	base = 8;
    } else {
	base = 10;
    }
    if (base == 16) {
	do {
	    *q++ = *p++;
	} while (ishexdigit(*p));
    } else {
	do {
	    *q++ = *p++;
	} while (isdigit(*p));
    }
    if (*p == '.') {
	do {
	    *q++ = *p++;
	} while (isdigit(*p));
	if (*p == 'e' or *p == 'E') {
	    p++;
	    if (*p == '+' or *p == '-' or isdigit(*p)) {
		*q++ = 'e';
		do {
		    *q++ = *p++;
		} while (isdigit(*p));
	    }
	}
	*q = '\0';
	yylval.y_real = atof(buf);
	t = REAL;
    } else {
	*q = '\0';
	switch (base) {
	    case 10:
		yylval.y_int = atol(buf);
		break;

	    case 8:
		yylval.y_int = octal(buf);
		break;

	    case 16:
		yylval.y_int = hex(buf);
		break;

	    default:
		badcaseval(base);
	}
	t = INT;
    }
    curchar = p;
    return t;
E 14
E 12
}

/*
D 12
 * Pop the current input.  Return whether successful.
E 12
I 12
D 14
 * Read the rest of the current line in "shell mode".
E 14
I 14
 * Convert a string of octal digits to an integer.
E 14
E 12
 */
I 12
D 14
public beginshellmode()
{
E 14
E 12

D 12
public Boolean popinput()
E 12
I 12
D 14
	shellmode = true;
}

public endshellmode()
E 14
I 14
private int octal(s)
String s;
E 14
E 12
{
I 14
    register Char *p;
    register Integer n;
E 14
D 12
    Boolean b;
E 12

D 12
    if (curinclindex == 0) {
	b = false;
    } else {
	b = (Boolean) (not eofinput());
    }
    return b;
E 12
I 12
D 14
	shellmode = false;
E 14
I 14
    n = 0;
    for (p = s; *p != '\0'; p++) {
	n = 8*n + (*p - '0');
    }
    return n;
E 14
E 12
}

I 12
D 14
public stopaliasing()
{
E 14
I 14
/*
 * Convert a string of hexadecimal digits to an integer.
 */
E 14

D 14
	doaliases = false;
}

public startaliasing()
E 14
I 14
private int hex(s)
String s;
E 14
{
I 14
    register Char *p;
    register Integer n;
E 14

D 14
	doaliases = true;
E 14
I 14
    n = 0;
    for (p = s; *p != '\0'; p++) {
	n *= 16;
	if (*p >= 'a' and *p <= 'f') {
	    n += (*p - 'a' + 10);
	} else if (*p >= 'A' and *p <= 'F') {
	    n += (*p - 'A' + 10);
	} else {
	    n += (*p - '0');
	}
    }
    return n;
E 14
}

E 12
/*
D 12
 * Return whether we are currently reading from standard input.
E 12
I 12
D 14
 * Print out a token for debugging.
E 14
I 14
 * Scan a string.
E 14
E 12
 */
I 12
D 14
public print_token(f, t)
File f;
Token t;
E 14
I 14

private Token getstring (quote)
char quote;
E 14
{
I 14
    register char *p, *q;
    char buf[MAXLINESIZE];
    boolean endofstring;
    Token t;
E 14
E 12

D 12
public Boolean isstdin()
E 12
I 12
D 14
	switch (t) {

	case '\n':
		fprintf(f, "char '\\n'");
		return;

	case EOF:
		fprintf(f, "EOF");
		return;

	case NAME:
	case STRING:
		fprintf(f, "%s, \"%s\"", keywdstring(t), ident(yylval.y_name));
		return;
E 14
I 14
    p = curchar;
    q = buf;
    endofstring = false;
    while (not endofstring) {
	if (*p == '\\' and *(p+1) == '\n') {
	    if (fgets(scanner_linebuf, MAXLINESIZE, in) == nil) {
		error("non-terminated string");
	    }
	    p = &scanner_linebuf[0] - 1;
	} else if (*p == '\n' or *p == '\0') {
	    error("non-terminated string");
	    endofstring = true;
	} else if (*p == quote) {
	    endofstring = true;
	} else {
	    curchar = p;
	    *q++ = charcon(p);
	    p = curchar;
E 14
	}
D 14
	if (t < 256)
		fprintf(f, "char '%c'", t);
	else
		fprintf(f, "%s", keywdstring(t));
E 14
I 14
	p++;
    }
    curchar = p;
    *q = '\0';
    if (quote == '\'' and buf[1] == '\0') {
	yylval.y_char = buf[0];
	t = CHAR;
    } else {
	yylval.y_string = strdup(buf);
	t = STRING;
    }
    return t;
E 14
}

D 14
public int getch()
E 14
I 14
/*
 * Process a character constant.
 * Watch out for backslashes.
 */

private char charcon (s)
String s;
E 14
E 12
{
D 12
    return (Boolean) (in == stdin);
E 12
I 12
D 14
	int c;
E 14
I 14
    register char *p, *q;
    char c, buf[10];
E 14

D 14
again:
	switch (sp->s_type) {
E 14
I 14
    p = s;
    if (*p == '\\') {
	++p;
	switch (*p) {
	    case '\\':
		c = '\\';
		break;
E 14

D 14
	case ST_FILE:
		c = getc(sp->s_file);
		if (c == EOF && isterm(sp->s_file)) {
			clearerr(sp->s_file);
			putchar('\n');
			c = '\n';
		}
E 14
I 14
	    case 'n':
		c = '\n';
E 14
		break;

D 14
	case ST_ALIAS:
		c = *sp->s_cur++;
		if (c == '\0') {
			c = EOF;
			--sp->s_cur;
		}
E 14
I 14
	    case 'r':
		c = '\r';
E 14
		break;

D 14
	default:
		panic("Invalid input stream (type %d) to getch.",
		    sp->s_type);
	}
	if (c == EOF && popinput())
		goto again;
	return (lastc = c);
E 12
}

I 12
private int ungetch(c)
Char c;
{
	Char uc;

	if (c != EOF) switch (sp->s_type) {

	case ST_FILE:
		uc = ungetc(c, sp->s_file);
E 14
I 14
	    case 't':
		c = '\t';
E 14
		break;

D 14
	case ST_ALIAS:
		if (sp->s_cur == sp->s_data)
			panic("Illegal ungetch on alias.");
		*--sp->s_cur = c;
		uc = c;
E 14
I 14
	    case '\'':
	    case '"':
		c = *p;
E 14
		break;

D 14
	default:
		panic("Invalid input stream (type %d) to ungetch.",
		    sp->s_type);
E 14
I 14
	    default:
		if (isdigit(*p)) {
		    q = buf;
		    do {
			*q++ = *p++;
		    } while (isdigit(*p));
		    *q = '\0';
		    c = (char) octal(buf);
		}
		--p;
		break;
E 14
	}
D 14
	lastc = '\0';
	return (uc);
E 14
I 14
	curchar = p;
    } else {
	c = *p;
    }
    return c;
E 14
}

E 12
/*
D 12
 * Send the current line to the shell.
E 12
I 12
D 14
 * Push the current input stream and
 * make the supplied stream the current.
E 14
I 14
 * Input file management routines.
E 14
E 12
 */
I 12
D 14
/*VARARGS3*/
public pushinput(type, name, info)
int type;
Filename name;
E 14
I 14

public setinput(filename)
Filename filename;
E 14
{
I 14
    File f;
E 14
E 12

D 12
public shellline()
E 12
I 12
D 14
	if (sp >= &stack[NSTREAMS])
		return (0);
	++sp;
	sp->s_type = type;
	switch (type) {

	case ST_FILE:
		sp->s_file = (File)info;
		errfilename = sp->s_name = name;
		errlineno = sp->s_lineno = 1;
		break;

	case ST_ALIAS:
		sp->s_cur = sp->s_data = (char *)info;
		break;

	default:
		panic("Invalid input stream (type %d) to pushinput.", type);
E 14
I 14
    f = fopen(filename, "r");
    if (f == nil) {
	error("can't open %s", filename);
    } else {
	if (curinclindex >= MAXINCLDEPTH) {
	    error("unreasonable input nesting on \"%s\"", filename);
E 14
	}
D 14
	return (1);
E 14
I 14
	inclinfo[curinclindex].savefile = in;
	inclinfo[curinclindex].savefn = errfilename;
	inclinfo[curinclindex].savelineno = errlineno;
	curinclindex++;
	in = f;
	errfilename = filename;
	errlineno = 1;
    }
E 14
}

D 14
public popinput()
E 14
I 14
private Boolean eofinput()
E 14
E 12
{
I 14
    register Boolean b;
E 14
D 12
    register char *p;
E 12

D 12
    p = curchar;
    while (*p != '\0' and (*p == '\n' or lexclass[*p] == WHITE)) {
	++p;
    }
    shell(p);
    if (*p == '\0' and isterm(in)) {
	putchar('\n');
    }
    erecover();
E 12
I 12
D 14
	if (sp <= &stack[0])		/* never pop stdin or equivalent */
		return (0);
	if (sp->s_type == ST_FILE && sp->s_file != stdin)
		fclose(sp->s_file);
	--sp;
	if (sp->s_type == ST_FILE)
		errfilename = sp->s_name;
	errlineno = sp->s_lineno;
	return (1);
E 14
I 14
    if (curinclindex == 0) {
	if (isterm(in)) {
	    putchar('\n');
	    clearerr(in);
	    b = false;
	} else {
	    b = true;
	}
    } else {
	fclose(in);
	--curinclindex;
	in = inclinfo[curinclindex].savefile;
	errfilename = inclinfo[curinclindex].savefn;
	errlineno = inclinfo[curinclindex].savelineno;
	b = false;
    }
    return b;
E 14
E 12
}

/*
D 12
 * Read the rest of the current line in "shell mode".
E 12
I 12
D 14
 * Unwind the input stack of all input types specified.
 * This is called to recover from an infinite
 * loop in alias processing or source file including.
E 14
I 14
 * Pop the current input.  Return whether successful.
E 14
E 12
 */
D 12

public beginshellmode()
E 12
I 12
D 14
public unwindinput(type)
Integer type;
E 14
I 14

public Boolean popinput()
E 14
E 12
{
I 14
    Boolean b;
E 14
D 12
    shellmode = true;
E 12
I 12

D 14
	while (sp->s_type == type && popinput())
		;
E 14
I 14
    if (curinclindex == 0) {
	b = false;
    } else {
	b = (Boolean) (not eofinput());
    }
    return b;
E 14
E 12
}

/*
D 12
 * Print out a token for debugging.
E 12
I 12
 * Return whether we are currently reading from standard input.
E 12
 */
I 14

E 14
I 12
public Boolean isstdin()
{
I 14
    return (Boolean) (in == stdin);
}
E 14
E 12

D 12
public print_token(f, t)
File f;
Token t;
E 12
I 12
D 14
	return ((Boolean)(sp->s_type == ST_FILE && sp->s_file == stdin));
E 14
I 14
/*
 * Send the current line to the shell.
 */

public shellline()
{
    register char *p;

    p = curchar;
    while (*p != '\0' and (*p == '\n' or lexclass[*p] == WHITE)) {
	++p;
    }
    shell(p);
    if (*p == '\0' and isterm(in)) {
	putchar('\n');
    }
    erecover();
E 14
}

D 14
public Boolean istty()
E 14
I 14
/*
 * Read the rest of the current line in "shell mode".
 */

public beginshellmode()
E 14
E 12
{
I 14
    shellmode = true;
}
E 14
D 12
    if (t == '\n') {
	fprintf(f, "char '\\n'");
    } else if (t == EOF) {
	fprintf(f, "EOF");
    } else if (t < 256) {
	fprintf(f, "char '%c'", t);
    } else {
	fprintf(f, "\"%s\"", keywdstring(t));
    }
E 12
I 12

D 14
	return ((Boolean)isterm(sp->s_file));
E 14
I 14
/*
 * Print out a token for debugging.
 */

public print_token(f, t)
File f;
Token t;
{
    if (t == '\n') {
	fprintf(f, "char '\\n'");
    } else if (t == EOF) {
	fprintf(f, "EOF");
    } else if (t < 256) {
	fprintf(f, "char '%c'", t);
    } else {
	fprintf(f, "\"%s\"", keywdstring(t));
    }
E 14
E 12
}
E 1
