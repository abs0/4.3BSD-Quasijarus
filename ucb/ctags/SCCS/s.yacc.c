h31263
s 00000/00002/00116
d D 5.2 87/03/16 18:15:54 bostic 2 1
c fixed line numbers for xflag
e
s 00118/00000/00000
d D 5.1 87/03/16 17:57:37 bostic 1 0
c date and time created 87/03/16 17:57:37 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1987 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

#include <ctags.h>
#include <strings.h>

/*
 * y_entries:
 *	find the yacc tags and put them in.
 */
y_entries()
{
	register int	c;
	register char	*sp;
	register bool	in_rule;
	char	tok[MAXTOKEN];

D 2
	(void)strcpy(lbuf,"%%$");		/* special case, "%%" */
	pfnote("yyparse",lineno);
E 2
	while (GETC(!=,EOF))
		switch ((char)c) {
		case '\n':
			SETLINE;
			/* FALLTHROUGH */
		case ' ':
		case '\f':
		case '\r':
		case '\t':
			break;
		case '{':
			if (skip_key((int)'}'))
				in_rule = NO;
			break;
		case '\'':
		case '"':
			if (skip_key(c))
				in_rule = NO;
			break;
		case '%':
			if (GETC(==,'%'))
				return;
			(void)ungetc(c,inf);
			break;
		case '/':
			if (GETC(==,'*'))
				skip_comment();
			else
				(void)ungetc(c,inf);
			break;
		case '|':
		case ';':
			in_rule = NO;
			break;
		default:
			if (in_rule || !isalpha(c) && c != (int)'.'
			    && c != (int)'_')
				break;
			sp = tok;
			*sp++ = c;
			while (GETC(!=,EOF) && (intoken(c) || c == (int)'.'))
				*sp++ = c;
			*sp = EOS;
			getline();		/* may change before ':' */
			while (iswhite(c)) {
				if (c == (int)'\n')
					SETLINE;
				if (GETC(==,EOF))
					return;
			}
			if (c == (int)':') {
				pfnote(tok,lineno);
				in_rule = YES;
			}
			else
				(void)ungetc(c,inf);
		}
}

/*
 * toss_yysec --
 *	throw away lines up to the next "\n%%\n"
 */
toss_yysec()
{
	register int	c,			/* read character */
			state;

	/*
	 * state == 0 : waiting
	 * state == 1 : received a newline
	 * state == 2 : received first %
	 * state == 3 : recieved second %
	 */
	lineftell = ftell(inf);
	for (state = 0;GETC(!=,EOF);)
		switch ((char)c) {
			case '\n':
				++lineno;
				lineftell = ftell(inf);
				if (state == 3)		/* done! */
					return;
				state = 1;		/* start over */
				break;
			case '%':
				if (state)		/* if 1 or 2 */
					++state;	/* goto 3 */
				break;
			default:
				state = 0;		/* reset */
		}
}
E 1
