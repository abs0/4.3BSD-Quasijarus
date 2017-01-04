h49414
s 00011/00006/00536
d D 5.8 88/06/29 19:40:47 bostic 9 8
c install approved copyright notice
e
s 00001/00001/00541
d D 5.7 88/03/22 17:42:50 bostic 8 7
c fix handling of '$'; bug report 4.3BSD/ucb/166
e
s 00012/00014/00530
d D 5.6 88/03/22 17:31:38 bostic 7 6
c add Berkeley and University of Illinois specific copyright
e
s 00002/00002/00542
d D 5.5 88/01/02 23:58:58 bostic 6 5
c remove trailing semi-colons on include lines for ANSI C
e
s 00006/00004/00538
d D 5.4 85/09/10 14:42:03 mckusick 5 4
c further updates from Chris Torek
e
s 00008/00005/00534
d D 5.3 85/09/08 15:41:22 mckusick 4 3
c update on Sun stuff by Chris Torek
e
s 00341/00267/00198
d D 5.2 85/08/28 13:47:35 mckusick 3 2
c kernel normal form (from sun!shannon)
e
s 00009/00001/00456
d D 5.1 85/06/04 13:36:10 dist 2 1
c Add copyright
e
s 00457/00000/00000
d D 4.1 82/10/21 23:58:29 mckusick 1 0
c date and time created 82/10/21 23:58:29 by mckusick
e
u
U
t
T
I 1
D 2
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
I 7
 * Copyright (c) 1976 Board of Trustees of the University of Illinois.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley and the University of
 * Illinois at Urbana.  The name of either University may not be used
 * to endorse or promote products derived from this software without
 * specific prior written permission. This software is provided
 * ``as is'' without express or implied warranty.
E 9
I 9
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley and the University
 * of Illinois, Urbana.  The name of either
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 9
E 7
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif not lint
E 7
I 7
#endif /* not lint */
E 7
E 2

D 3
/*

			  Copyright (C) 1976
				by the
			  Board of Trustees
				of the
			University of Illinois
E 3
I 3
D 7
/*-
 *
 *			  Copyright (C) 1976
 *				by the
 *			  Board of Trustees
 *				of the
 *			University of Illinois
 *
 *			 All rights reserved
 *
 *
E 7
I 7
/*
E 7
 * NAME:
 *	lexi
 *
 * FUNCTION:
 *	This is the token scanner for indent
 *
 * ALGORITHM:
 *	1) Strip off intervening blanks and/or tabs.
 *	2) If it is an alphanumeric token, move it to the token buffer "token".
 *	   Check if it is a special reserved word that indent will want to
 *	   know about.
 *	3) Non-alphanumeric tokens are handled with a big switch statement.  A
 *	   flag is kept to remember if the last token was a "unary delimiter",
 *	   which forces a following operator to be unary as opposed to binary.
 *
 * PARAMETERS:
 *	None
 *
 * RETURNS:
 *	An integer code indicating the type of token scanned.
 *
 * GLOBALS:
 *	buf_ptr =
 *	had_eof
 *	ps.last_u_d =	Set to true iff this token is a "unary delimiter"
 *
 * CALLS:
 *	fill_buffer
 *	printf (lib)
 *
 * CALLED BY:
 *	main
 *
 * NOTES:
 *	Start of comment is passed back so that the comment can be scanned by
 *	pr_comment.
 *
 *	Strings and character literals are returned just like identifiers.
 *
 * HISTORY:
 *	initial coding 	November 1976	D A Willcox of CAC
 *	1/7/77		D A Willcox of CAC	Fix to provide proper handling
 *						of "int a -1;"
 *
 */
E 3

D 3
			 All rights reserved
E 3
I 3
/*
 * Here we have the token scanner for indent.  It scans off one token and
 * puts it in the global variable "token".  It returns a code, indicating
 * the type of token scanned. 
 */
E 3

D 3

NAME:
	lexi

FUNCTION:
	This is the token scanner for indent

ALGORITHM:
	1) Strip off intervening blanks and/or tabs.
	2) If it is an alphanumeric token, move it to the token buffer "token".
	   Check if it is a special reserved word that indent will want to
	   know about.
	3) Non-alphanumeric tokens are handled with a big switch statement.  A
	   flag is kept to remember if the last token was a "unary delimiter",
	   which forces a following operator to be unary as opposed to binary.

PARAMETERS:
	None

RETURNS:
	An integer code indicating the type of token scanned.

GLOBALS:
	buf_ptr =
	had_eof
	last_u_d =	Set to true iff this token is a "unary delimiter"

CALLS:
	fill_buffer
	printf (lib)

CALLED BY:
	main

NOTES:
	Start of comment is passed back so that the comment can be scanned by
	pr_comment.

	Strings and character literals are returned just like identifiers.

HISTORY:
	initial coding 	November 1976	D A Willcox of CAC
	1/7/77		D A Willcox of CAC	Fix to provide proper handling
						of "int a -1;"

*/

/* Here we have the token scanner for indent.  It scans off one token and
   puts it in the global variable "token".  It returns a code, indicating the
   type of token scanned. */

E 3
D 6
#include "indent_globs.h";
#include "indent_codes.h";
E 6
I 6
#include "indent_globs.h"
#include "indent_codes.h"
E 6
I 3
#include "ctype.h"
E 3

D 3


E 3
#define alphanum 1
#define opchar 3

struct templ {
D 3
    char   *rwd;
    int     rwcode;
E 3
I 3
    char       *rwd;
    int         rwcode;
E 3
};

D 3
struct templ    specials[] =
E 3
I 3
struct templ specials[100] =
E 3
{
    "switch", 1,
    "case", 2,
I 3
    "break", 0,
E 3
    "struct", 3,
I 3
    "union", 3,
    "enum", 3,
E 3
    "default", 2,
    "int", 4,
    "char", 4,
    "float", 4,
    "double", 4,
    "long", 4,
    "short", 4,
    "typdef", 4,
    "unsigned", 4,
    "register", 4,
    "static", 4,
    "global", 4,
    "extern", 4,
I 3
    "void", 4,
    "goto", 0,
    "return", 0,
E 3
    "if", 5,
    "while", 5,
    "for", 5,
    "else", 6,
    "do", 6,
D 3
    "sizeof", 0,
E 3
I 3
    "sizeof", 7,
E 3
    0, 0
};

D 3
char    chartype[128] =
{		   /* this is used to facilitate the decision of what type
		      (alphanumeric, operator) each character is */
E 3
I 3
char        chartype[128] =
{				/* this is used to facilitate the decision
				 * of what type (alphanumeric, operator)
				 * each character is */
E 3
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
D 8
    0, 3, 0, 0, 0, 3, 3, 0,
E 8
I 8
    0, 3, 0, 0, 1, 3, 3, 0,
E 8
    0, 0, 3, 3, 0, 3, 3, 3,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 0, 0, 3, 3, 3, 3,
    0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 3, 1,
    0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 3, 0, 3, 0
};

D 3
int     last_nl = true;
 /* this is true if the last thing scanned was a newline */
E 3



D 3
int     lexi () {
    register char  *tok;
 /* local pointer to next char in token */
    register int    i;
 /* local loop counter */
    register char  *j;
 /* used for searching thru list of reserved words */
    int     unary_delim;
 /* this is set to 1 if the current token forces a following operator to be
    unary */
    static int  last_code;
 /* the last token type returned */
    static int  l_struct;
 /* set to 1 if the last token was 'struct' */
    int     found_it;
    int     code;  /* internal code to be returned */
    char    qchar; /* the delimiter character for a string */
E 3
I 3
int 
lexi()
{
    register char *tok;		/* local pointer to next char in token */
    int         unary_delim;	/* this is set to 1 if the current token 
				 *
				 * forces a following operator to be unary */
    static int  last_code;	/* the last token type returned */
    static int  l_struct;	/* set to 1 if the last token was 'struct' */
    int         code;		/* internal code to be returned */
    char        qchar;		/* the delimiter character for a string */
E 3

D 3
    tok = token;	       /* point to start of place to save token */
E 3
I 3
    tok = token;		/* point to start of place to save token */
E 3
    unary_delim = false;
D 3
    col_1 = last_nl;	       /* tell world that this token started in column
			          1 iff the last thing scanned was nl */
    last_nl = false;
E 3
I 3
    ps.col_1 = ps.last_nl;	/* tell world that this token started in
				 * column 1 iff the last thing scanned was
				 * nl */
    ps.last_nl = false;
E 3

D 3
    while (*buf_ptr == ' ' || *buf_ptr == '\t') {
    /* get rid of blanks */
	col_1 = false;	       /* leading blanks imply token is not in column 1
			          */
E 3
I 3
    while (*buf_ptr == ' ' || *buf_ptr == '\t') {	/* get rid of blanks */
	ps.col_1 = false;	/* leading blanks imply token is not in
				 * column 1 */
E 3
	if (++buf_ptr >= buf_end)
D 3
	    fill_buffer ();
E 3
I 3
	    fill_buffer();
E 3
    }

D 3
/*----------------------------------------------------------*\ 
|    Scan an alphanumeric token
\*----------------------------------------------------------*/
E 3
I 3
D 4
    /* Scan an alphanumeric token */
E 4
I 4
    /* Scan an alphanumeric token.  Note that we must also handle
     * stuff like "1.0e+03" and "7e-6". */
E 4
    if (chartype[*buf_ptr & 0177] == alphanum) {	/* we have a character
							 * or number */
	register char *j;	/* used for searching thru list of 
D 4
				 *
E 4
				 * reserved words */
	register struct templ *p;
I 4
	register int c;
E 4
E 3

D 3
    if (chartype[*buf_ptr & 0177] == alphanum) {
    /* we have a character or number */
	while (chartype[*buf_ptr & 0177] == alphanum) {
	/* copy it over */
E 3
I 3
D 4
	while (chartype[*buf_ptr & 0177] == alphanum) {	/* copy it over */
E 4
I 4
	do {			/* copy it over */
E 4
E 3
	    *tok++ = *buf_ptr++;
	    if (buf_ptr >= buf_end)
D 3
		fill_buffer ();
E 3
I 3
		fill_buffer();
E 3
D 4
	}
E 4
I 4
	} while (chartype[c = *buf_ptr & 0177] == alphanum ||
		isdigit(token[0]) && (c == '+' || c == '-') &&
		(tok[-1] == 'e' || tok[-1] == 'E'));
E 4
D 3

E 3
	*tok++ = '\0';
D 3

	if (l_struct) {	       /* if last token was 'struct', then this token
			          should be treated as a declaration */
E 3
I 3
	while (*buf_ptr == ' ' || *buf_ptr == '\t') {	/* get rid of blanks */
	    if (++buf_ptr >= buf_end)
		fill_buffer();
	}
	ps.its_a_keyword = false;
	ps.sizeof_keyword = false;
	if (l_struct) {		/* if last token was 'struct', then this
				 * token should be treated as a
				 * declaration */
E 3
	    l_struct = false;
	    last_code = ident;
D 3
	    last_u_d = true;
E 3
I 3
	    ps.last_u_d = true;
E 3
	    return (decl);
	}
I 3
	ps.last_u_d = false;	/* Operator after indentifier is binary */
	last_code = ident;	/* Remember that this is the code we will
				 * return */
E 3

D 3
	last_u_d = false;      /* operator after indentifier is binary */
E 3
I 3
	/*
	 * This loop will check if the token is a keyword. 
	 */
	for (p = specials; (j = p->rwd) != 0; p++) {
	    tok = token;	/* point at scanned token */
	    if (*j++ != *tok++ || *j++ != *tok++)
		continue;	/* This test depends on the fact that
				 * identifiers are always at least 1
				 * character long (ie. the first two bytes
				 * of the identifier are always
				 * meaningful) */
	    if (tok[-1] == 0)
		break;		/* If its a one-character identifier */
	    while (*tok++ == *j)
		if (*j++ == 0)
		    goto found_keyword;	/* I wish that C had a multi-level
					 * break... */
	}
	if (p->rwd) {		/* we have a keyword */
    found_keyword:
	    ps.its_a_keyword = true;
	    ps.last_u_d = true;
	    switch (p->rwcode) {
		case 1:	/* it is a switch */
		    return (swstmt);
		case 2:	/* a case or default */
		    return (casestmt);
E 3

D 3
	for (i = 0; specials[i].rwd != 0; ++i) {
	/* this loop will check if the token is a keyword.  if so, a following
	   operator is unary */
	    last_code = ident; /* remember that this is the code we will return
			          */
	    j = specials[i].rwd;
	/* point at ith reserved word */
	    tok = token;       /* point at scanned toekn */
	    found_it = true;   /* set to false if not found */
	    do {
		if (*tok++ != *j) {
		    found_it = false;
		    break;
		}
	    } while (*j++);
E 3
I 3
		case 3:	/* a "struct" */
		    if (ps.p_l_follow)
			break;	/* inside parens: cast */
		    l_struct = true;
E 3

D 3
	    if (found_it) {    /* we have a keyword */
		last_u_d = true;
		switch (specials[i].rwcode) {
		    case 1:    /* it is a switch */
			return (swstmt);
		    case 2:    /* a case or default */
			return (casestmt);
E 3
I 3
		    /*
		     * Next time around, we will want to know that we have
		     * had a 'struct' 
		     */
		case 4:	/* one of the declaration keywords */
		    if (ps.p_l_follow) {
			ps.cast_mask |= 1 << ps.p_l_follow;
			break;	/* inside parens: cast */
		    }
		    last_code = decl;
		    return (decl);
E 3

D 3
		    case 3:    /* a "struct" */
			l_struct = true;
		    /* Next time around, we will want to know that we have had
		       a 'struct' */
		    case 4:    /* one of the declaration keywords */
			if(p_l_follow) break;	/* inside parens: cast */
			last_code = decl;
			return (decl);
E 3
I 3
		case 5:	/* if, while, for */
		    return (sp_paren);
E 3

D 3
		    case 5:    /* if, while, for */
			return (sp_paren);
E 3
I 3
		case 6:	/* do, else */
		    return (sp_nparen);
E 3

D 3
		    case 6:    /* do, else */
			return (sp_nparen);

		    default:   /* all others are treated like any other
			          identifier */
			return (ident);
		}	       /* end of switch */
	    }		       /* end of if (found_it) */

E 3
I 3
		case 7:
		    ps.sizeof_keyword = true;
		default:	/* all others are treated like any other
				 * identifier */
		    return (ident);
	    }			/* end of switch */
	}			/* end of if (found_it) */
	if (*buf_ptr == '(' && ps.tos <= 1 && ps.ind_level == 0
	    && (buf_ptr[1] != ')' || buf_ptr[2] != ';')) {
	    strncpy(ps.procname, token, sizeof ps.procname - 1);
	    ps.in_parameter_declaration = 1;
E 3
	}

D 3
	if (last_code == decl) /* if this is a declared variable, then
			          following sign is unary */
	    last_u_d = true;   /* will make "int a -1" work */
E 3
I 3
	/*
	 * The following hack attempts to guess whether or not the current
	 * token is in fact a declaration keyword -- one that has been
	 * typedefd 
	 */
	if (((*buf_ptr == '*' && buf_ptr[1] != '=') || isalpha(*buf_ptr))
	    && !ps.p_l_follow
	    && (ps.last_token == rparen || ps.last_token == semicolon ||
		ps.last_token == decl ||
		ps.last_token == lbrace || ps.last_token == rbrace)) {
	    ps.its_a_keyword = true;
	    ps.last_u_d = true;
	    last_code = decl;
	    return decl;
	}
	if (last_code == decl)	/* if this is a declared variable, then
				 * following sign is unary */
	    ps.last_u_d = true;	/* will make "int a -1" work */
E 3
	last_code = ident;
D 3
	return (ident);	       /* the ident is not in the list */
    }			       /* end of procesing for alpanum character */
E 3
I 3
	return (ident);		/* the ident is not in the list */
    }				/* end of procesing for alpanum character */
D 4
    /* l l Scan a non-alphanumeric token */
E 4
I 4
    /* Scan a non-alphanumeric token */
E 4
E 3

D 3


/*----------------------------------------------------------*\ 
|   Scan a non-alphanumeric token
\*----------------------------------------------------------*/

    *tok++ = *buf_ptr;	       /* if it is only a one-character token, it is
			          moved here */
E 3
I 3
    *tok++ = *buf_ptr;		/* if it is only a one-character token, it
				 * is moved here */
E 3
    *tok = '\0';
    if (++buf_ptr >= buf_end)
D 3
	fill_buffer ();
E 3
I 3
	fill_buffer();
E 3

    switch (*token) {
D 3
	case '\n': 
	    unary_delim = last_u_d;
	    last_nl = true;    /* remember that we just had a newline */
E 3
I 3
	case '\n':
	    unary_delim = ps.last_u_d;
	    ps.last_nl = true;	/* remember that we just had a newline */
E 3
	    code = (had_eof ? 0 : newline);
D 3
	/* if data has been exausted, the newline is a dummy, and we should
	   return code to stop */
E 3
I 3

	    /*
	     * if data has been exausted, the newline is a dummy, and we
	     * should return code to stop 
	     */
E 3
	    break;

D 3
	case '\'': 	       /* start of quoted character */
	    qchar = '\'';      /* remember final delimiter */
	    goto copy_lit;     /* and go to common literal code */

	case '"': 	       /* start of string */
	    qchar = '"';

    copy_lit: 
	    do {	       /* copy the string */
		while (1) {    /* move one character or [/<char>]<char> */
E 3
I 3
	case '\'':		/* start of quoted character */
	case '"':		/* start of string */
	    qchar = *token;
	    if (troff) {
		tok[-1] = '`';
		if (qchar == '"')
		    *tok++ = '`';
		*tok++ = BACKSLASH;
		*tok++ = 'f';
		*tok++ = 'L';
	    }
	    do {		/* copy the string */
		while (1) {	/* move one character or [/<char>]<char> */
E 3
		    if (*buf_ptr == '\n') {
D 3
		    /* check for unterminated literal */
			printf ("%d: Unterminated literal\n", line_no);
E 3
I 3
			printf("%d: Unterminated literal\n", line_no);
E 3
			goto stop_lit;
D 3
		    /* Don't copy any more */
E 3
		    }
D 3

E 3
		    *tok = *buf_ptr++;
		    if (buf_ptr >= buf_end)
D 3
			fill_buffer ();
E 3
I 3
			fill_buffer();
E 3
		    if (had_eof || ((tok - token) > (bufsize - 2))) {
D 3
			printf ("Unterminated literal\n");
E 3
I 3
			printf("Unterminated literal\n");
E 3
			++tok;
			goto stop_lit;
D 3
		    /* get outof literal copying loop */
E 3
I 3
			/* get outof literal copying loop */
E 3
		    }
D 3

		    if (*tok == '\\') {
		    /* if escape, copy extra char */
			if (*buf_ptr == '\n')
			       /* check for escaped newline */
E 3
I 3
		    if (*tok == BACKSLASH) {	/* if escape, copy extra
						 * char */
			if (*buf_ptr == '\n')	/* check for escaped
						 * newline */
E 3
			    ++line_no;
D 3
			*(++tok) = *buf_ptr++;
			++tok; /* we must increment this again because we
			          copied two chars */
E 3
I 3
			if (troff) {
			    *++tok = BACKSLASH;
			    if (*buf_ptr == BACKSLASH)
				*++tok = BACKSLASH;
			}
			*++tok = *buf_ptr++;
			++tok;	/* we must increment this again because we
				 * copied two chars */
E 3
			if (buf_ptr >= buf_end)
D 3
			    fill_buffer ();
E 3
I 3
			    fill_buffer();
E 3
		    }
		    else
D 3
			break; /* we copied one character */
		}	       /* end of while (1) */
E 3
I 3
			break;	/* we copied one character */
		}		/* end of while (1) */
E 3
	    } while (*tok++ != qchar);
D 3

    stop_lit: 
E 3
I 3
	    if (troff) {
		tok[-1] = BACKSLASH;
		*tok++ = 'f';
		*tok++ = 'R';
		*tok++ = '\'';
		if (qchar == '"')
		    *tok++ = '\'';
	    }
    stop_lit:
E 3
	    code = ident;
	    break;

D 3
	case ('('): 
	case ('['): 
E 3
I 3
	case ('('):
	case ('['):
E 3
	    unary_delim = true;
	    code = lparen;
	    break;

D 3
	case (')'): 
	case (']'): 
E 3
I 3
	case (')'):
	case (']'):
E 3
	    code = rparen;
	    break;

D 3
	case '#': 
	    unary_delim = last_u_d;
E 3
I 3
	case '#':
	    unary_delim = ps.last_u_d;
E 3
	    code = preesc;
	    break;

D 3
	case '?': 
E 3
I 3
	case '?':
E 3
	    unary_delim = true;
	    code = question;
	    break;

D 3
	case (':'): 
E 3
I 3
	case (':'):
E 3
	    code = colon;
	    unary_delim = true;
	    break;

D 3
	case (';'): 
E 3
I 3
	case (';'):
E 3
	    unary_delim = true;
	    code = semicolon;
	    break;

D 3
	case ('{'): 
E 3
I 3
	case ('{'):
E 3
	    unary_delim = true;
D 3
	    code = lbrace;
E 3
I 3

	    /*
	     * if (ps.in_or_st) ps.block_init = 1; 
	     */
	    code = ps.block_init ? lparen : lbrace;
E 3
	    break;

D 3
	case ('}'): 
E 3
I 3
	case ('}'):
E 3
	    unary_delim = true;
D 3
	    code = rbrace;
E 3
I 3
	    code = ps.block_init ? rparen : rbrace;
E 3
	    break;

D 3
	case 014: 	       /* a form feed */
	    unary_delim = last_u_d;
	    last_nl = true;    /* remember this so we can set 'col_1' right */
E 3
I 3
	case 014:		/* a form feed */
	    unary_delim = ps.last_u_d;
	    ps.last_nl = true;	/* remember this so we can set 'ps.col_1'
				 * right */
E 3
	    code = form_feed;
	    break;

D 3
	case (','): 
E 3
I 3
	case (','):
E 3
	    unary_delim = true;
	    code = comma;
	    break;

D 3
	case '.': 
E 3
I 3
	case '.':
E 3
	    unary_delim = false;
	    code = period;
	    break;

D 3
	case '-': 
	case '+': 	       /* check for -, +, --, ++ */
	    code = (last_u_d ? unary_op : binary_op);
E 3
I 3
	case '-':
	case '+':		/* check for -, +, --, ++ */
	    code = (ps.last_u_d ? unary_op : binary_op);
E 3
	    unary_delim = true;

	    if (*buf_ptr == token[0]) {
D 3
	    /* check for doubled character */
E 3
I 3
		/* check for doubled character */
E 3
		*tok++ = *buf_ptr++;
D 3
	    /* buffer overflow will be checked at end of loop */
E 3
I 3
		/* buffer overflow will be checked at end of loop */
E 3
		if (last_code == ident || last_code == rparen) {
D 3
		    code = (last_u_d ? unary_op : postop);
		/* check for following ++ or -- */
E 3
I 3
		    code = (ps.last_u_d ? unary_op : postop);
		    /* check for following ++ or -- */
E 3
		    unary_delim = false;
		}
	    }
D 3
	    else
		if (*buf_ptr == '>' || *buf_ptr == '=')
			       /* check for operator -> or += */
		    *tok++ = *buf_ptr++;
	/* buffer overflow will be checked at end of switch */
E 3
I 3
	    else if (*buf_ptr == '=')
		/* check for operator += */
		*tok++ = *buf_ptr++;
D 5
	    else if (*buf_ptr == '>') {
E 5
I 5
	    else if (token[0] == '-' && *buf_ptr == '>') {
E 5
		/* check for operator -> */
		*tok++ = *buf_ptr++;
D 5
		code = unary_op;
		unary_delim = false;
		ps.want_blank = false;
E 5
I 5
		if (!pointer_as_binop) {
		    code = unary_op;
		    unary_delim = false;
		    ps.want_blank = false;
		}
E 5
	    }
	    /* buffer overflow will be checked at end of switch */
E 3

	    break;

D 3
	case '=': 
	    if (chartype[*buf_ptr] == opchar) {
	    /* we have two char assignment */
		*tok++ = *buf_ptr;
	    /* move second character */
		if (++buf_ptr >= buf_end)
		    fill_buffer ();
E 3
I 3
	case '=':
	    if (ps.in_or_st)
		ps.block_init = 1;
	    if (chartype[*buf_ptr] == opchar) {	/* we have two char
						 * assignment */
		tok[-1] = *buf_ptr++;
		if ((tok[-1] == '<' || tok[-1] == '>') && tok[-1] == *buf_ptr)
		    *tok++ = *buf_ptr++;
		*tok++ = '=';	/* Flip =+ to += */
		*tok = 0;
E 3
	    }
D 3

E 3
	    code = binary_op;
	    unary_delim = true;
D 3
	    if (token[1] != '<' && token[1] != '>')
			       /* check for possible 3 char operator */
		break;
	/* can drop thru!!! */
E 3
I 3
	    break;
	    /* can drop thru!!! */
E 3

D 3
	case '>': 
	case '<': 
	case '!': 	       /* ops like <, <<, <=, !=, etc */
E 3
I 3
	case '>':
	case '<':
	case '!':		/* ops like <, <<, <=, !=, etc */
E 3
	    if (*buf_ptr == '>' || *buf_ptr == '<' || *buf_ptr == '=') {
		*tok++ = *buf_ptr;
		if (++buf_ptr >= buf_end)
D 3
		    fill_buffer ();
E 3
I 3
		    fill_buffer();
E 3
	    }
D 3

E 3
	    if (*buf_ptr == '=')
D 3
		 *tok++ = *buf_ptr++;
	    code = (last_u_d ? unary_op : binary_op);
E 3
I 3
		*tok++ = *buf_ptr++;
	    code = (ps.last_u_d ? unary_op : binary_op);
E 3
	    unary_delim = true;
	    break;

D 3
	default: 
E 3
I 3
	default:
E 3
	    if (token[0] == '/' && *buf_ptr == '*') {
D 3
	    /* it is start of comment */
E 3
I 3
		/* it is start of comment */
E 3
		*tok++ = '*';

		if (++buf_ptr >= buf_end)
D 3
		    fill_buffer ();
E 3
I 3
		    fill_buffer();
E 3

		code = comment;
D 3
		unary_delim = last_u_d;
E 3
I 3
		unary_delim = ps.last_u_d;
E 3
		break;
	    }
D 3

	    while (*(tok - 1) == *buf_ptr || *buf_ptr=='=') {
	    /* handle ||, &&, etc, and also things as in int *****i */
E 3
I 3
	    while (*(tok - 1) == *buf_ptr || *buf_ptr == '=') {
		/* handle ||, &&, etc, and also things as in int *****i */
E 3
		*tok++ = *buf_ptr;
		if (++buf_ptr >= buf_end)
D 3
		    fill_buffer ();
E 3
I 3
		    fill_buffer();
E 3
	    }
D 3


	    code = (last_u_d ? unary_op : binary_op);
E 3
I 3
	    code = (ps.last_u_d ? unary_op : binary_op);
E 3
	    unary_delim = true;


D 3
    }			       /* end of switch */

E 3
I 3
    }				/* end of switch */
E 3
    if (code != newline) {
	l_struct = false;
	last_code = code;
    }
D 3

    if (buf_ptr >= buf_end)    /* check for input buffer empty */
	fill_buffer ();
    last_u_d = unary_delim;
    *tok = '\0';	       /* null terminate the token */
E 3
I 3
    if (buf_ptr >= buf_end)	/* check for input buffer empty */
	fill_buffer();
    ps.last_u_d = unary_delim;
    *tok = '\0';		/* null terminate the token */
E 3
    return (code);
};
I 3

/* Add the given keyword to the keyword table, using val as the keyword type
   */
addkey (key, val)
char       *key;
{
    register struct templ *p = specials;
    while (p->rwd)
	if (p->rwd[0] == key[0] && strcmp(p->rwd, key) == 0)
	    return;
	else
	    p++;
    if (p >= specials + sizeof specials / sizeof specials[0])
	return;			/* For now, table overflows are silently
				   ignored */
    p->rwd = key;
    p->rwcode = val;
    p[1].rwd = 0;
    p[1].rwcode = 0;
    return;
}
E 3
E 1
