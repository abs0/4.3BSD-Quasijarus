h45444
s 00010/00005/00476
d D 5.4 88/06/29 20:19:32 bostic 17 16
c install approved copyright notice
e
s 00011/00005/00470
d D 5.3 88/02/01 11:34:44 bostic 16 15
c add new Berkeley headers
e
s 00006/00006/00469
d D 5.2 85/06/21 19:04:37 mckusick 15 14
c botched copyright
e
s 00006/00000/00469
d D 5.1 85/06/06 08:57:08 dist 14 13
c Add copyright
e
s 00001/00001/00468
d D 4.13 85/04/03 10:17:15 ralph 13 12
c fix problems with '\' for except_pat.
e
s 00001/00001/00468
d D 4.12 85/02/04 14:29:52 ralph 12 11
c change exp_pat to except_pat.
e
s 00008/00000/00461
d D 4.11 84/06/28 11:45:04 ralph 11 10
c handle symbolic and hard links.
e
s 00016/00003/00445
d D 4.10 84/05/03 11:41:50 ralph 10 9
c added regular expressions for exception pattern matching.
e
s 00029/00016/00419
d D 4.9 84/04/06 15:48:34 ralph 9 8
c added labels for partial updates.
e
s 00173/00050/00262
d D 4.8 84/02/09 16:06:43 ralph 8 7
c read entire distfile and sort entries by host.
e
s 00070/00018/00242
d D 4.7 83/11/29 16:00:33 ralph 7 6
c bug fixes and added `special' command.
e
s 00007/00002/00253
d D 4.6 83/10/26 11:42:29 ralph 6 5
c added -b option for binary compare. Fixed -r w/ except.
e
s 00037/00016/00218
d D 4.5 83/10/20 12:14:54 ralph 5 4
c added -r option to remove extra files.
e
s 00001/00001/00233
d D 4.4 83/10/12 16:38:56 ralph 4 3
c fixed install flags, file comparisons, mail addresses, added -c.
e
s 00035/00022/00199
d D 4.3 83/10/10 16:16:00 ralph 3 2
c stable version that works.
e
s 00103/00091/00118
d D 4.2 83/09/27 14:38:50 ralph 2 1
c First stable version.
e
s 00209/00000/00000
d D 4.1 83/09/07 13:19:54 ralph 1 0
c date and time created 83/09/07 13:19:54 by ralph
e
u
U
t
T
I 1
%{
I 14
D 15
#
# Copyright (c) 1980 Regents of the University of California.
# All rights reserved.  The Berkeley software License Agreement
# specifies the terms and conditions for redistribution.
#
#
E 15
I 15
/*
D 16
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 16
I 16
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 17
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 17
I 17
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
E 17
E 16
 */

E 15
E 14
#ifndef lint
D 16
static	char *sccsid = "%W% (Berkeley) %E%";
#endif
E 16
I 16
static char sccsid[] = "%W% (Berkeley) %G%";
#endif /* not lint */
E 16

#include "defs.h"

D 2
struct	block *last;
E 2
I 2
D 8
struct	block *lastn;
struct	block *lastc;
E 8
I 8
struct	cmd *cmds = NULL;
struct	cmd *last_cmd;
struct	namelist *last_n;
struct	subcmd *last_sc;
E 8
E 2

%}

D 7
%term EQUAL 1
D 2
%term ARROW 2
%term LP 3
%term RP 4
%term NAME 5
%term INSTALL 6
%term VERIFY 7
%term NOTIFY 8
%term EXCEPT 9
E 2
I 2
%term LP 2
%term RP 3
D 5
%term ARROW 4
%term DCOLON 5
%term NAME 6
%term INSTALL 7
D 3
%term VERIFY 8
%term NOTIFY 9
%term EXCEPT 10
E 3
I 3
%term NOTIFY 8
%term EXCEPT 9
%term OPTION 10
E 5
I 5
%term SM 4
%term ARROW 5
%term DCOLON 6
%term NAME 7
%term INSTALL 8
%term NOTIFY 9
%term EXCEPT 10
%term OPTION 11
E 7
I 7
%term EQUAL	1
%term LP	2
%term RP	3
%term SM	4
%term ARROW	5
D 9
%term DCOLON	6
%term NAME	7
%term STRING	8
%term INSTALL	9
%term NOTIFY	10
%term EXCEPT	11
%term SPECIAL	12
%term OPTION	13
E 9
I 9
%term COLON	6
%term DCOLON	7
%term NAME	8
%term STRING	9
%term INSTALL	10
%term NOTIFY	11
%term EXCEPT	12
D 10
%term SPECIAL	13
%term OPTION	14
E 10
I 10
%term PATTERN	13
%term SPECIAL	14
%term OPTION	15
E 10
E 9
E 7
E 5
E 3
E 2

D 3
%union
	{
E 3
I 3
%union {
E 3
D 8
	struct block *blk;
E 8
D 3
	}
E 3
I 3
	int intval;
I 7
	char *string;
I 8
	struct subcmd *subcmd;
	struct namelist *namel;
E 8
E 7
}
E 3

D 3
%type <blk> NAME, INSTALL, VERIFY, NOTIFY, EXCEPT, namelist, names, cmdlist, cmd
E 3
I 3
D 5
%type <blk> NAME, INSTALL, NOTIFY, EXCEPT, namelist, names, cmdlist, cmd
E 5
I 5
D 7
%type <blk> NAME, INSTALL, NOTIFY, EXCEPT
%type <blk> namelist, names, opt_name, cmdlist, cmd
E 7
I 7
D 8
%type <blk> NAME, INSTALL, NOTIFY, EXCEPT, SPECIAL
%type <blk> namelist, names, opt_name, opt_namelist, cmdlist, cmd
E 8
E 7
E 5
%type <intval> OPTION, options
I 7
D 8
%type <string> STRING
E 8
I 8
%type <string> NAME, STRING
D 10
%type <subcmd> INSTALL, NOTIFY, EXCEPT, SPECIAL, cmdlist, cmd
E 10
I 10
%type <subcmd> INSTALL, NOTIFY, EXCEPT, PATTERN, SPECIAL, cmdlist, cmd
E 10
%type <namel> namelist, names, opt_namelist
E 8
E 7
E 3

%%

file:		  /* VOID */
		| file command
		;

command:	  NAME EQUAL namelist = {
D 8
			$1->b_args = $3;
D 2
			(void) lookup($1->b_name, 1, $1);
E 2
I 2
			(void) lookup($1->b_name, $1, 1);
E 8
I 8
			(void) lookup($1, INSERT, $3);
E 8
E 2
		}
		| namelist ARROW namelist cmdlist = {
D 2
			docmd($1, $3, $4);
E 2
I 2
D 8
			dohcmds($1, $3, $4);
E 8
I 8
D 9
			insert($1, $3, $4);
E 9
I 9
			insert(NULL, $1, $3, $4);
E 9
E 8
E 2
		}
I 9
		| NAME COLON namelist ARROW namelist cmdlist = {
			insert($1, $3, $5, $6);
		}
E 9
I 2
D 7
		| namelist DCOLON namelist cmdlist = {
E 7
I 7
		| namelist DCOLON NAME cmdlist = {
E 7
D 8
			dofcmds($1, $3, $4);
E 8
I 8
D 9
			append($1, $3, $4);
E 9
I 9
			append(NULL, $1, $3, $4);
E 9
E 8
		}
I 9
		| NAME COLON namelist DCOLON NAME cmdlist = {
			append($1, $3, $5, $6);
		}
E 9
E 2
		| error
		;

namelist:	  NAME = {
D 8
			$$ = $1;
E 8
I 8
			$$ = makenl($1);
E 8
		}
		| LP names RP = {
			$$ = $2;
		}
		;

names:		  /* VOID */ {
D 2
			$$ = last = NULL;
E 2
I 2
D 8
			$$ = lastn = NULL;
E 8
I 8
			$$ = last_n = NULL;
E 8
E 2
		}
		| names NAME = {
D 2
			if (last == NULL)
				$$ = last = $2;
E 2
I 2
D 8
			if (lastn == NULL)
				$$ = lastn = $2;
E 8
I 8
			if (last_n == NULL)
				$$ = last_n = makenl($2);
E 8
E 2
			else {
D 2
				last->b_next = $2;
				last = $2;
E 2
I 2
D 8
				lastn->b_next = $2;
				lastn = $2;
E 8
I 8
				last_n->n_next = makenl($2);
				last_n = last_n->n_next;
E 8
E 2
				$$ = $1;
			}
		}
		;

cmdlist:	  /* VOID */ {
D 2
			$$ = last = NULL;
E 2
I 2
D 8
			$$ = lastc = NULL;
E 8
I 8
			$$ = last_sc = NULL;
E 8
E 2
		}
		| cmdlist cmd = {
D 2
			if (last == NULL)
				$$ = last = $2;
E 2
I 2
D 8
			if (lastc == NULL)
				$$ = lastc = $2;
E 8
I 8
			if (last_sc == NULL)
				$$ = last_sc = $2;
E 8
E 2
			else {
D 2
				last->b_next = $2;
				last = $2;
E 2
I 2
D 8
				lastc->b_next = $2;
				lastc = $2;
E 8
I 8
				last_sc->sc_next = $2;
				last_sc = $2;
E 8
E 2
				$$ = $1;
			}
		}
		;

D 3
cmd:		  INSTALL NAME = {
E 3
I 3
D 5
cmd:		  INSTALL options NAME = {
E 5
I 5
D 8
cmd:		  INSTALL options opt_name SM = {
E 5
E 3
D 2
			$1->b_name = $2->b_name;
E 2
I 2
			register struct block *b;
E 8
I 8
cmd:		  INSTALL options opt_namelist SM = {
			register struct namelist *nl;
E 8

D 3
		inst_name:
			b = expand($2, 0);
E 3
I 3
D 4
			$1->b_options = $2;
E 4
I 4
D 8
			$1->b_options = $2 | options;
E 8
I 8
			$1->sc_options = $2 | options;
E 8
E 4
D 5
			b = expand($3, 0);
E 3
			if (b == NULL || b->b_next != NULL)
				fatal("exactly one name allowed\n");
			$1->b_name = b->b_name;
E 5
I 5
			if ($3 != NULL) {
D 7
				b = expand($3, 0);
E 7
I 7
D 8
				b = expand($3, E_VARS|E_SHELL);
E 7
				if (b->b_next != NULL)
E 8
I 8
				nl = expand($3, E_VARS);
				if (nl->n_next != NULL)
E 8
D 6
					fatal("exactly one name allowed\n");
E 6
I 6
					yyerror("only one name allowed\n");
E 6
D 8
				$1->b_name = b->b_name;
E 8
I 8
				$1->sc_name = nl->n_name;
				free(nl);
E 8
			}
E 5
E 2
D 3
			free($2);
E 3
			$$ = $1;
		}
D 3
		| VERIFY NAME = {
D 2
			$1->b_name = $2->b_name;
			free($2);
			$$ = $1;
E 2
I 2
			goto inst_name;
E 2
		}
E 3
D 5
		| NOTIFY namelist = {
E 5
I 5
		| NOTIFY namelist SM = {
E 5
D 2
			$1->b_args = $2;
E 2
I 2
D 7
			$1->b_args = expand($2, 1);
E 7
I 7
D 8
			$1->b_args = expand($2, E_VARS);
E 8
I 8
			if ($2 != NULL)
				$1->sc_args = expand($2, E_VARS);
E 8
E 7
E 2
			$$ = $1;
		}
D 5
		| EXCEPT namelist = {
E 5
I 5
		| EXCEPT namelist SM = {
E 5
D 2
			$1->b_args = expand($2);
E 2
I 2
D 6
			$1->b_args = expand($2, 0);
E 6
I 6
D 8
			$1->b_args = $2;
E 8
I 8
			if ($2 != NULL)
				$1->sc_args = expand($2, E_ALL);
E 8
E 6
E 2
			$$ = $1;
		}
I 10
		| PATTERN namelist SM = {
			struct namelist *nl;
			char *cp, *re_comp();

			for (nl = $2; nl != NULL; nl = nl->n_next)
				if ((cp = re_comp(nl->n_name)) != NULL)
					yyerror(cp);
D 13
			$1->sc_args = $2;
E 13
I 13
			$1->sc_args = expand($2, E_VARS);
E 13
			$$ = $1;
		}
E 10
I 7
		| SPECIAL opt_namelist STRING SM = {
			if ($2 != NULL)
D 8
				$1->b_args = expand($2, E_ALL);
			$1->b_name = $3;
E 8
I 8
				$1->sc_args = expand($2, E_ALL);
			$1->sc_name = $3;
E 8
			$$ = $1;
		}
E 7
		;
I 5

E 5
I 3
options:	  /* VOID */ = {
			$$ = 0;
		}
		| options OPTION = {
			$$ |= $2;
		}
		;
E 3

I 5
D 8
opt_name:	  /* VOID */ = {
			$$ = NULL;
		}
		| NAME = {
			$$ = $1;
		}
		;

E 8
I 7
opt_namelist:	  /* VOID */ = {
			$$ = NULL;
		}
		| namelist = {
			$$ = $1;
		}
		;

E 7
E 5
%%

int	yylineno = 1;
extern	FILE *fin;

yylex()
{
	static char yytext[INMAX];
	register int c;
	register char *cp1, *cp2;
D 3
	register struct block *bp;
I 2
	static char quotechars[] = "[]{}*?";
E 3
I 3
	static char quotechars[] = "[]{}*?$";
E 3
E 2
	
D 2
	for (;;) {
		switch (c = getc(fin)) {
		case EOF:  /* end of file */
E 2
I 2
again:
	switch (c = getc(fin)) {
	case EOF:  /* end of file */
		return(0);

	case '#':  /* start of comment */
		while ((c = getc(fin)) != EOF && c != '\n')
			;
		if (c == EOF)
E 2
			return(0);
I 2
	case '\n':
		yylineno++;
	case ' ':
	case '\t':  /* skip blanks */
		goto again;
E 2

D 2
		case '#':  /* start of comment */
			while ((c = getc(fin)) != EOF && c != '\n')
				;
			if (c == EOF)
				return(0);
		case '\n':
			yylineno++;
		case ' ':
		case '\t':  /* skip blanks */
			continue;
E 2
I 2
	case '=':  /* EQUAL */
		return(EQUAL);
E 2

D 2
		case '=':  /* EQUAL */
			return(EQUAL);
E 2
I 2
	case '(':  /* LP */
		return(LP);
E 2

D 2
		case '(':  /* LP */
			return(LP);
E 2
I 2
	case ')':  /* RP */
		return(RP);
E 2

I 5
	case ';':  /* SM */
		return(SM);

E 5
D 2
		case ')':  /* RP */
			return(RP);
E 2
I 2
	case '-':  /* -> */
		if ((c = getc(fin)) == '>')
			return(ARROW);
		ungetc(c, fin);
		c = '-';
		break;
E 2

I 7
	case '"':  /* STRING */
		cp1 = yytext;
		cp2 = &yytext[INMAX - 1];
		for (;;) {
			if (cp1 >= cp2) {
				yyerror("command string too long\n");
				break;
			}
			c = getc(fin);
			if (c == EOF || c == '"')
				break;
			if (c == '\\') {
				if ((c = getc(fin)) == EOF) {
					*cp1++ = '\\';
					break;
				}
			}
D 9
			if (c == '\n')
E 9
I 9
			if (c == '\n') {
				yylineno++;
E 9
				c = ' '; /* can't send '\n' */
I 9
			}
E 9
			*cp1++ = c;
		}
		if (c != '"')
			yyerror("missing closing '\"'\n");
D 8
		*cp1++ = '\0';
		yylval.string = cp2 = malloc(cp1 - yytext);
		if (cp2 == NULL)
			fatal("ran out of memory\n");
		cp1 = yytext;
		while (*cp2++ = *cp1++)
			;
E 8
I 8
		*cp1 = '\0';
		yylval.string = makestr(yytext);
E 8
		return(STRING);

E 7
D 2
		case '-':  /* -> */
			if ((c = getc(fin)) == '>')
				return(ARROW);
			ungetc(c, fin);
			c = '-';
E 2
I 2
D 9
	case ':':  /* :: */
E 9
I 9
	case ':':  /* : or :: */
E 9
		if ((c = getc(fin)) == ':')
			return(DCOLON);
		ungetc(c, fin);
D 9
		c = ':';
E 9
I 9
		return(COLON);
E 9
	}
D 3
	/*
	 * Start of a name.
	 */
E 3
	cp1 = yytext;
	cp2 = &yytext[INMAX - 1];
	for (;;) {
		if (cp1 >= cp2) {
D 7
			fatal("input line too long\n");
E 7
I 7
			yyerror("input line too long\n");
E 7
			break;
E 2
		}
D 2
		/*
		 * Start of a name.
		 */
		cp1 = yytext;
		cp2 = &yytext[INMAX - 1];
		for (;;) {
			if (cp1 >= cp2) {
				fatal("input line too long\n");
E 2
I 2
		if (c == '\\') {
			if ((c = getc(fin)) != EOF) {
				if (any(c, quotechars))
					c |= QUOTE;
			} else {
				*cp1++ = '\\';
E 2
				break;
			}
D 2
			*cp1++ = c;
			c = getc(fin);
			if (c == EOF || any(c, " \t()=\n")) {
				ungetc(c, fin);
				break;
			}
E 2
		}
D 2
		*cp1 = '\0';
		yylval.blk = bp = ALLOC(block);
		if (bp == NULL)
			fatal("ran out of memory\n");
		if (!strcmp(yytext, "install"))
			c = INSTALL;
		else if (!strcmp(yytext, "verify"))
			c = VERIFY;
		else if (!strcmp(yytext, "notify"))
			c = NOTIFY;
		else if (!strcmp(yytext, "except"))
			c = EXCEPT;
		else
			c = NAME;
		bp->b_type = c;
		bp->b_next = bp->b_args = NULL;
		if (c == NAME) {
			c = strlen(yytext) + 1;
			bp->b_name = cp1 = (char *) malloc(c);
			if (cp1 == NULL)
				fatal("ran out of memory\n");
			for (cp2 = yytext; *cp1++ = *cp2++; )
				;
		} else
			bp->b_name = NULL;
		return(bp->b_type);
E 2
I 2
		*cp1++ = c;
		c = getc(fin);
D 5
		if (c == EOF || any(c, " \t()=\n")) {
E 5
I 5
D 9
		if (c == EOF || any(c, " \t()=;\n")) {
E 9
I 9
		if (c == EOF || any(c, " \"'\t()=;:\n")) {
E 9
E 5
			ungetc(c, fin);
			break;
		}
E 2
	}
I 2
	*cp1 = '\0';
I 3
	if (yytext[0] == '-' && yytext[2] == '\0') {
		switch (yytext[1]) {
I 6
		case 'b':
			yylval.intval = COMPARE;
			return(OPTION);

E 6
I 5
D 7
		case 'r':
E 7
I 7
		case 'R':
E 7
			yylval.intval = REMOVE;
			return(OPTION);

E 5
		case 'v':
			yylval.intval = VERIFY;
			return(OPTION);

		case 'w':
			yylval.intval = WHOLE;
			return(OPTION);

		case 'y':
			yylval.intval = YOUNGER;
			return(OPTION);
I 11

		case 'h':
			yylval.intval = FOLLOW;
			return(OPTION);

		case 'i':
			yylval.intval = IGNLNKS;
			return(OPTION);
E 11
		}
	}
E 3
	if (!strcmp(yytext, "install"))
		c = INSTALL;
D 3
	else if (!strcmp(yytext, "verify"))
		c = VERIFY;
E 3
	else if (!strcmp(yytext, "notify"))
		c = NOTIFY;
	else if (!strcmp(yytext, "except"))
		c = EXCEPT;
I 10
D 12
	else if (!strcmp(yytext, "exp_pat"))
E 12
I 12
	else if (!strcmp(yytext, "except_pat"))
E 12
		c = PATTERN;
E 10
I 7
	else if (!strcmp(yytext, "special"))
		c = SPECIAL;
E 7
D 8
	else
		c = NAME;
D 3
	yylval.blk = bp = makeblock(c, yytext);
E 3
I 3
	yylval.blk = makeblock(c, yytext);
E 8
I 8
	else {
		yylval.string = makestr(yytext);
		return(NAME);
	}
	yylval.subcmd = makesubcmd(c);
E 8
E 3
	return(c);
E 2
}

any(c, str)
	register int c;
	register char *str;
{
	while (*str)
		if (c == *str++)
			return(1);
	return(0);
}

/*
I 8
 * Insert or append ARROW command to list of hosts to be updated.
 */
D 9
insert(files, hosts, subcmds)
E 9
I 9
insert(label, files, hosts, subcmds)
	char *label;
E 9
	struct namelist *files, *hosts;
	struct subcmd *subcmds;
{
	register struct cmd *c, *prev, *nc;
	register struct namelist *h;

	files = expand(files, E_VARS|E_SHELL);
	hosts = expand(hosts, E_ALL);
	for (h = hosts; h != NULL; free(h), h = h->n_next) {
		/*
		 * Search command list for an update to the same host.
		 */
		for (prev = NULL, c = cmds; c!=NULL; prev = c, c = c->c_next) {
			if (strcmp(c->c_name, h->n_name) == 0) {
				do {
					prev = c;
					c = c->c_next;
				} while (c != NULL &&
					strcmp(c->c_name, h->n_name) == 0);
				break;
			}
		}
		/*
		 * Insert new command to update host.
		 */
		nc = ALLOC(cmd);
		if (nc == NULL)
			fatal("ran out of memory\n");
		nc->c_type = ARROW;
		nc->c_name = h->n_name;
I 9
		nc->c_label = label;
E 9
		nc->c_files = files;
		nc->c_cmds = subcmds;
		nc->c_next = c;
		if (prev == NULL)
			cmds = nc;
		else
			prev->c_next = nc;
		/* update last_cmd if appending nc to cmds */
		if (c == NULL)
			last_cmd = nc;
	}
}

/*
 * Append DCOLON command to the end of the command list since these are always
 * executed in the order they appear in the distfile.
 */
D 9
append(files, stamp, subcmds)
E 9
I 9
append(label, files, stamp, subcmds)
	char *label;
E 9
	struct namelist *files;
	char *stamp;
	struct subcmd *subcmds;
{
	register struct cmd *c;

	c = ALLOC(cmd);
	if (c == NULL)
		fatal("ran out of memory\n");
	c->c_type = DCOLON;
	c->c_name = stamp;
I 9
	c->c_label = label;
E 9
	c->c_files = expand(files, E_ALL);
	c->c_cmds = subcmds;
	c->c_next = NULL;
	if (cmds == NULL)
		cmds = last_cmd = c;
	else {
		last_cmd->c_next = c;
		last_cmd = c;
	}
}

/*
E 8
 * Error printing routine in parser.
 */
yyerror(s)
	char *s;
{
	extern int yychar;

I 5
D 8
	errs++;
E 8
I 8
	nerrs++;
E 8
I 6
	fflush(stdout);
E 6
E 5
	fprintf(stderr, "rdist: line %d: %s\n", yylineno, s);
I 8
}

/*
 * Return a copy of the string.
 */
char *
makestr(str)
	char *str;
{
	register char *cp, *s;

	str = cp = malloc(strlen(s = str) + 1);
	if (cp == NULL)
		fatal("ran out of memory\n");
	while (*cp++ = *s++)
		;
	return(str);
}

/*
 * Allocate a namelist structure.
 */
struct namelist *
makenl(name)
	char *name;
{
	register struct namelist *nl;

	nl = ALLOC(namelist);
	if (nl == NULL)
		fatal("ran out of memory\n");
	nl->n_name = name;
	nl->n_next = NULL;
	return(nl);
}

/*
 * Make a sub command for lists of variables, commands, etc.
 */
struct subcmd *
makesubcmd(type, name)
	int type;
	register char *name;
{
	register char *cp;
	register struct subcmd *sc;

	sc = ALLOC(subcmd);
	if (sc == NULL)
		fatal("ran out of memory\n");
	sc->sc_type = type;
	sc->sc_args = NULL;
	sc->sc_next = NULL;
	sc->sc_name = NULL;
	return(sc);
E 8
}
E 1
