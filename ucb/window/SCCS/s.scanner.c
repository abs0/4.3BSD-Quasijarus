h54328
s 00010/00005/00544
d D 3.11 88/06/29 21:36:27 bostic 11 10
c install approved copyright notice
e
s 00013/00007/00536
d D 3.10 88/02/21 13:37:23 bostic 10 9
c written by Edward Wang; attach Berkeley specific copyright
e
s 00008/00000/00535
d D 3.9 87/05/18 12:22:24 edward 9 8
c added [ and ] tokens for vectors, haven't done the real work yet.
e
s 00006/00000/00529
d D 3.8 85/04/24 16:20:28 edward 8 7
c copyright messages
e
s 00017/00006/00512
d D 3.7 84/07/13 23:57:01 edward 7 6
c $? added
e
s 00001/00001/00517
d D 3.6 84/05/23 02:00:12 edward 6 5
c new sccs id
e
s 00054/00038/00464
d D 3.5 84/04/15 16:57:15 edward 5 4
c fun
e
s 00079/00061/00423
d D 3.4 84/04/11 03:06:12 edward 4 3
c \ newline bug
e
s 00002/00002/00482
d D 3.3 83/12/12 14:50:52 edward 3 2
c made . an alpha
e
s 00001/00000/00483
d D 3.2 83/11/22 19:49:41 edward 2 1
c leading 0 bug
e
s 00483/00000/00000
d D 3.1 83/11/22 12:48:01 edward 1 0
c date and time created 83/11/22 12:48:01 by edward
e
u
U
t
T
I 1
D 10
#ifndef lint
D 6
static	char *sccsid = "%W% %E%";
E 6
I 6
static char sccsid[] = "%W% %G%";
E 6
#endif

E 10
I 8
/*
D 10
 * Copyright (c) 1983 Regents of the University of California,
 * All rights reserved.  Redistribution permitted subject to
 * the terms of the Berkeley Software License Agreement.
E 10
I 10
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 11
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 11
I 11
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
E 11
E 10
 */
I 10

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 10

E 8
#include <stdio.h>
#include "value.h"
#include "token.h"
#include "context.h"
#include "string.h"

s_getc()
{
	register c;

	switch (cx.x_type) {
	case X_FILE:
		c = getc(cx.x_fp);
		if (cx.x_bol && c != EOF) {
			cx.x_bol = 0;
			cx.x_lineno++;
		}
		if (c == '\n')
			cx.x_bol = 1;
		return c;
	case X_BUF:
		if (*cx.x_bufp != 0)
			return *cx.x_bufp++ & 0xff;
		else
			return EOF;
	}
	/*NOTREACHED*/
}

s_ungetc(c)
{
	if (c == EOF)
		return EOF;
	switch (cx.x_type) {
	case X_FILE:
		cx.x_bol = 0;
		return ungetc(c, cx.x_fp);
	case X_BUF:
		if (cx.x_bufp > cx.x_buf)
			return *--cx.x_bufp = c;
		else
			return EOF;
	}
	/*NOTREACHED*/
}

s_gettok()
{
	char buf[100];
	register char *p = buf;
	register c;
	register state = 0;
D 4
	char quote = 0;
E 4
I 4
D 5
	char quote;
E 5
E 4

loop:
	c = s_getc();
	switch (state) {
D 5
	case 0:				/* blank skipping */
E 5
I 5
	case 0:
E 5
D 4
		if (c != ' ' && c != '\t') {
E 4
I 4
		switch (c) {
		case ' ':
		case '\t':
			break;
D 5
		default:
E 4
			(void) s_ungetc(c);
			state = 1;
		}
		break;
	case 1:				/* beginning of token */
		switch (c) {
E 5
		case '\n':
		case ';':
			cx.x_token = T_EOL;
			state = -1;
			break;
		case '#':
D 4
			state = 7;
E 4
I 4
D 5
			state = 4;
E 5
I 5
			state = 1;
E 5
E 4
			break;
		case EOF:
			cx.x_token = T_EOF;
			state = -1;
			break;
		case 'a': case 'b': case 'c': case 'd': case 'e':
		case 'f': case 'g': case 'h': case 'i': case 'j':
		case 'k': case 'l': case 'm': case 'n': case 'o':
		case 'p': case 'q': case 'r': case 's': case 't':
		case 'u': case 'v': case 'w': case 'x': case 'y':
		case 'z':
		case 'A': case 'B': case 'C': case 'D': case 'E':
		case 'F': case 'G': case 'H': case 'I': case 'J':
		case 'K': case 'L': case 'M': case 'N': case 'O':
		case 'P': case 'Q': case 'R': case 'S': case 'T':
		case 'U': case 'V': case 'W': case 'X': case 'Y':
		case 'Z':
D 3
		case '_':
E 3
I 3
		case '_': case '.':
E 3
			*p++ = c;
			state = 2;
			break;
		case '"':
D 5
		case '\'':
			quote = c;
E 5
			state = 3;
			break;
I 5
		case '\'':
			state = 4;
			break;
E 5
		case '\\':
D 4
			state = 4;
E 4
I 4
			switch (c = s_gettok1()) {
			case -1:
				break;
			case -2:
				state = 0;
				break;
			default:
				*p++ = c;
				state = 2;
			}
E 4
			break;
		case '0':
I 2
			cx.x_val.v_num = 0;
E 2
			state = 10;
			break;
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			cx.x_val.v_num = c - '0';
			state = 11;
			break;
		case '>':
			state = 20;
			break;
		case '<':
			state = 21;
			break;
		case '=':
			state = 22;
			break;
		case '!':
			state = 23;
			break;
		case '&':
			state = 24;
			break;
		case '|':
			state = 25;
			break;
I 7
		case '$':
			state = 26;
			break;
E 7
		case '~':
			cx.x_token = T_COMP;
			state = -1;
			break;
		case '+':
			cx.x_token = T_PLUS;
			state = -1;
			break;
		case '-':
			cx.x_token = T_MINUS;
			state = -1;
			break;
		case '*':
			cx.x_token = T_MUL;
			state = -1;
			break;
		case '/':
			cx.x_token = T_DIV;
			state = -1;
			break;
		case '%':
			cx.x_token = T_MOD;
			state = -1;
			break;
		case '^':
			cx.x_token = T_XOR;
			state = -1;
			break;
		case '(':
			cx.x_token = T_LP;
			state = -1;
			break;
		case ')':
			cx.x_token = T_RP;
			state = -1;
			break;
D 7
		case '$':
			cx.x_token = T_DOLLAR;
			state = -1;
			break;
E 7
		case ',':
			cx.x_token = T_COMMA;
			state = -1;
			break;
		case '?':
			cx.x_token = T_QUEST;
			state = -1;
			break;
		case ':':
			cx.x_token = T_COLON;
			state = -1;
			break;
I 9
		case '[':
			cx.x_token = T_LB;
			state = -1;
			break;
		case ']':
			cx.x_token = T_RB;
			state = -1;
			break;
E 9
		default:
			cx.x_val.v_num = c;
			cx.x_token = T_CHAR;
			state = -1;
			break;
		}
		break;
I 5
	case 1:				/* got # */
		if (c == '\n' || c == EOF) {
			(void) s_ungetc(c);
			state = 0;
		}
		break;
E 5
	case 2:				/* unquoted string */
		switch (c) {
		case 'a': case 'b': case 'c': case 'd': case 'e':
		case 'f': case 'g': case 'h': case 'i': case 'j':
		case 'k': case 'l': case 'm': case 'n': case 'o':
		case 'p': case 'q': case 'r': case 's': case 't':
		case 'u': case 'v': case 'w': case 'x': case 'y':
		case 'z':
		case 'A': case 'B': case 'C': case 'D': case 'E':
		case 'F': case 'G': case 'H': case 'I': case 'J':
		case 'K': case 'L': case 'M': case 'N': case 'O':
		case 'P': case 'Q': case 'R': case 'S': case 'T':
		case 'U': case 'V': case 'W': case 'X': case 'Y':
		case 'Z':
D 3
		case '_':
E 3
I 3
		case '_': case '.':
E 3
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			if (p < buf + sizeof buf - 1)
				*p++ = c;
			break;
		case '"':
D 5
		case '\'':
			quote = c;
E 5
			state = 3;
			break;
I 5
		case '\'':
			state = 4;
			break;
E 5
		case '\\':
D 4
			state = 4;
E 4
I 4
			switch (c = s_gettok1()) {
			case -2:
				(void) s_ungetc(' ');
			case -1:
				break;
			default:
				if (p < buf + sizeof buf - 1)
					*p++ = c;
			}
E 4
			break;
		default:
			(void) s_ungetc(c);
		case EOF:
			*p = 0;
			cx.x_token = T_STR;
			switch (*buf) {
			case 'i':
				if (buf[1] == 'f' && buf[2] == 0)
					cx.x_token = T_IF;
				break;
			case 't':
D 5
				if (strcmp(buf, "then") == 0)
E 5
I 5
				if (buf[1] == 'h' && buf[2] == 'e'
				    && buf[3] == 'n' && buf[4] == 0)
E 5
					cx.x_token = T_THEN;
				break;
			case 'e':
D 5
				switch (buf[1]) {
				case 'n':
					if (strcmp(buf, "endif") == 0)
						cx.x_token = T_ENDIF;
					break;
				case 'l':
					if (strcmp(buf, "else") == 0)
						cx.x_token = T_ELSE;
					if (strcmp(buf, "elsif") == 0)
E 5
I 5
				if (buf[1] == 'n' && buf[2] == 'd'
				    && buf[3] == 'i' && buf[4] == 'f'
				    && buf[5] == 0)
					cx.x_token = T_ENDIF;
				else if (buf[1] == 'l' && buf[2] == 's')
					if (buf[3] == 'i' && buf[4] == 'f'
					    && buf[5] == 0)
E 5
						cx.x_token = T_ELSIF;
D 5
					break;
				}
E 5
I 5
					else if (buf[3] == 'e' && buf[4] == 0)
						cx.x_token = T_ELSE;
E 5
				break;
			}
D 5
			if (cx.x_token == T_STR)
				if ((cx.x_val.v_str = str_cpy(buf)) == 0) {
					p_memerror();
					cx.x_token = T_EOF;
				}
E 5
I 5
			if (cx.x_token == T_STR
			    && (cx.x_val.v_str = str_cpy(buf)) == 0) {
				p_memerror();
				cx.x_token = T_EOF;
			}
E 5
			state = -1;
			break;
		}
		break;
D 5
	case 3:				/* quoted string */
E 5
I 5
	case 3:				/* " quoted string */
E 5
		switch (c) {
		case '\n':
			(void) s_ungetc(c);
		case EOF:
I 5
		case '"':
E 5
			state = 2;
			break;
		case '\\':
D 4
			state = 4;
E 4
I 4
			switch (c = s_gettok1()) {
			case -1:
			case -2:	/* newlines are invisible */
				break;
			default:
				if (p < buf + sizeof buf - 1)
					*p++ = c;
			}
E 4
			break;
		default:
D 4
			if (c == quote) {
				quote = 0;
E 4
I 4
D 5
			if (c == quote)
E 4
				state = 2;
D 4
			} else if (p < buf + sizeof buf - 1)
E 4
I 4
			else if (p < buf + sizeof buf - 1)
E 5
I 5
			if (p < buf + sizeof buf - 1)
E 5
E 4
				*p++ = c;
			break;
		}
		break;
D 4
	case 4:				/* got \ */
		switch (c) {
		case EOF:
			state = 2;
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7':
			if (p < buf + sizeof buf - 1)
				*p = c - '0';
			state = 5;
			break;
		case 'b':
			c = '\b';
			goto foo;
		case 'f':
			c = '\f';
			goto foo;
		case 'n':
			c = '\n';
			goto foo;
		case 'r':
			c = '\r';
			goto foo;
		case 't':
			c = '\t';
		foo:
		default:
			if (p < buf + sizeof buf - 1)
				*p++ = c;
		case '\n':		/* swallow the \n */
			state = quote == 0 ? 2 : 3;
		}
		break;
	case 5:				/* got \[0-7] */
		if (c >= '0' && c <= '7') {
			*p = *p * 8 + c - '0';
			state = 6;
		} else {
			(void) s_ungetc(c);
			p++;
			state = quote == 0 ? 2 : 3;
		}
		break;
	case 6:				/* got \[0-7][0-7] */
		if (c >= '0' && c <= '7')
			*p = *p * 8 + c - '0';
		else
			(void) s_ungetc(c);
		p++;
		state = quote == 0 ? 2 : 3;
		break;
	case 7:				/* got # */
E 4
I 4
D 5
	case 4:				/* got # */
E 4
		if (c == '\n' || c == EOF) {
E 5
I 5
	case 4:				/* ' quoted string */
		switch (c) {
		case '\n':
E 5
			(void) s_ungetc(c);
D 5
			state = 1;
E 5
I 5
		case EOF:
		case '\'':
			state = 2;
			break;
		case '\\':
			switch (c = s_gettok1()) {
			case -1:
			case -2:	/* newlines are invisible */
				break;
			default:
				if (p < buf + sizeof buf - 1)
					*p++ = c;
			}
			break;
		default:
			if (p < buf + sizeof buf - 1)
				*p++ = c;
			break;
E 5
		}
		break;
	case 10:			/* got 0 */
		switch (c) {
		case 'x':
		case 'X':
			cx.x_val.v_num = 0;
			state = 12;
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7':
			cx.x_val.v_num = c - '0';
			state = 13;
			break;
		case '8': case '9':
			cx.x_val.v_num = c - '0';
			state = 11;
			break;
		default:
			(void) s_ungetc(c);
			state = -1;
			cx.x_token = T_NUM;
		}
		break;
	case 11:			/* decimal number */
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			cx.x_val.v_num = cx.x_val.v_num * 10 + c - '0';
			break;
		default:
			(void) s_ungetc(c);
			state = -1;
			cx.x_token = T_NUM;
		}
		break;
	case 12:			/* hex number */
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			cx.x_val.v_num = cx.x_val.v_num * 16 + c - '0';
			break;
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
			cx.x_val.v_num = cx.x_val.v_num * 16 + c - 'a' + 10;
			break;
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
			cx.x_val.v_num = cx.x_val.v_num * 16 + c - 'A' + 10;
			break;
		default:
			(void) s_ungetc(c);
			state = -1;
			cx.x_token = T_NUM;
		}
		break;
	case 13:			/* octal number */
		switch (c) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7':
			cx.x_val.v_num = cx.x_val.v_num * 8 + c - '0';
			break;
		default:
			(void) s_ungetc(c);
			state = -1;
			cx.x_token = T_NUM;
		}
		break;
	case 20:			/* got > */
		switch (c) {
		case '=':
			cx.x_token = T_GE;
			state = -1;
			break;
		case '>':
			cx.x_token = T_RS;
			state = -1;
			break;
		default:
			(void) s_ungetc(c);
			cx.x_token = T_GT;
			state = -1;
		}
		break;
	case 21:			/* got < */
		switch (c) {
		case '=':
			cx.x_token = T_LE;
			state = -1;
			break;
		case '<':
			cx.x_token = T_LS;
			state = -1;
			break;
		default:
			(void) s_ungetc(c);
			cx.x_token = T_LT;
			state = -1;
		}
		break;
	case 22:			/* got = */
		switch (c) {
		case '=':
			cx.x_token = T_EQ;
			state = -1;
			break;
		default:
			(void) s_ungetc(c);
			cx.x_token = T_ASSIGN;
			state = -1;
		}
		break;
	case 23:			/* got ! */
		switch (c) {
		case '=':
			cx.x_token = T_NE;
			state = -1;
			break;
		default:
			(void) s_ungetc(c);
			cx.x_token = T_NOT;
			state = -1;
		}
		break;
D 7
	case 24:			/* and & */
E 7
I 7
	case 24:			/* got & */
E 7
		switch (c) {
		case '&':
			cx.x_token = T_ANDAND;
			state = -1;
			break;
		default:
			(void) s_ungetc(c);
			cx.x_token = T_AND;
			state = -1;
		}
		break;
D 7
	case 25:			/* and | */
E 7
I 7
	case 25:			/* got | */
E 7
		switch (c) {
		case '|':
			cx.x_token = T_OROR;
			state = -1;
			break;
		default:
			(void) s_ungetc(c);
			cx.x_token = T_OR;
I 7
			state = -1;
		}
		break;
	case 26:			/* got $ */
		switch (c) {
		case '?':
			cx.x_token = T_DQ;
			state = -1;
			break;
		default:
			(void) s_ungetc(c);
			cx.x_token = T_DOLLAR;
E 7
			state = -1;
		}
		break;
	default:
		abort();
	}
	if (state >= 0)
		goto loop;
	return cx.x_token;
I 4
}

s_gettok1()
{
	register c;
	register n;

	c = s_getc();			/* got \ */
	switch (c) {
	case EOF:
		return -1;
	case '\n':
		return -2;
	case 'b':
		return '\b';
	case 'f':
		return '\f';
	case 'n':
		return '\n';
	case 'r':
		return '\r';
	case 't':
		return '\t';
	default:
		return c;
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7':
		break;
	}
	n = c - '0';
	c = s_getc();			/* got \[0-7] */
	if (c < '0' || c > '7') {
		(void) s_ungetc(c);
		return n;
	}
	n = n * 8 + c - '0';
	c = s_getc();			/* got \[0-7][0-7] */
	if (c < '0' || c > '7') {
		(void) s_ungetc(c);
		return n;
	}
	return n * 8 + c - '0';
E 4
}
E 1
