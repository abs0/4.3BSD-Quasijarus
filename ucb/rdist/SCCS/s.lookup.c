h33436
s 00004/00000/00149
d D 5.5 04/10/23 22:02:34 msokolov 11 10
c buffer overflow fix from nivenh, adapted by msokolov
e
s 00010/00005/00139
d D 5.4 88/06/29 20:19:34 bostic 10 9
c install approved copyright notice
e
s 00009/00003/00135
d D 5.3 88/02/01 11:34:48 bostic 9 8
c add new Berkeley headers
e
s 00003/00002/00135
d D 5.2 87/10/22 19:35:30 bostic 8 7
c ANSI C; sprintf now returns an int.
e
s 00008/00002/00129
d D 5.1 85/06/06 08:51:47 dist 7 6
c Add copyright
e
s 00009/00004/00122
d D 4.6 85/02/04 14:34:15 ralph 6 5
c use yyerror instead of quitting on first error.
e
s 00002/00006/00124
d D 4.5 84/02/16 11:25:54 ralph 5 4
c fix command line defines (-d option).
e
s 00050/00062/00080
d D 4.4 84/02/09 16:06:55 ralph 4 3
c read entire distfile and sort entries by host.
e
s 00006/00010/00136
d D 4.3 83/10/10 16:17:36 ralph 3 2
c stable version that works.
e
s 00000/00000/00146
d D 4.2 83/09/27 14:39:44 ralph 2 1
c First stable version.
e
s 00146/00000/00000
d D 4.1 83/09/27 14:16:34 ralph 1 0
c date and time created 83/09/27 14:16:34 by ralph
e
u
U
t
T
I 7
/*
 * Copyright (c) 1983 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 10
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 10
I 10
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
E 10
E 9
 */

E 7
I 1
#ifndef lint
D 7
static	char *sccsid = "%W% (Berkeley) %E%";
#endif
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif /* not lint */
E 9
E 7

#include "defs.h"

I 4
	/* symbol types */
#define VAR	1
#define CONST	2

struct syment {
	int	s_type;
	char	*s_name;
	struct	namelist *s_value;
	struct	syment *s_next;
};

static struct syment *hashtab[HASHSIZE];

E 4
/*
 * Define a variable from a command line argument.
 */
define(name)
	char *name;
{
	register char *cp, *s;
D 4
	register struct block *bp, *value;
E 4
I 4
	register struct namelist *nl;
	struct namelist *value;
E 4

I 11
	if (strlen(name) > 128) {
		fprintf(stderr, "rdist: -d arg is too long.\n");
		exit(1);
	}
E 11
	if (debug)
		printf("define(%s)\n", name);

	cp = index(name, '=');
D 3
	if (cp == NULL || cp[1] == '\0')
E 3
I 3
	if (cp == NULL)
E 3
		value = NULL;
D 3
	else if (cp[1] != '(') {
E 3
I 3
	else if (cp[1] == '\0') {
E 3
D 4
		*cp++ = '\0';
E 4
I 4
		*cp = '\0';
E 4
I 3
		value = NULL;
	} else if (cp[1] != '(') {
		*cp++ = '\0';
E 3
D 4
		value = makeblock(NAME, cp);
E 4
I 4
D 5
		value = makenl(name);
E 5
I 5
		value = makenl(cp);
E 5
E 4
	} else {
D 4
		bp = NULL;
E 4
I 4
		nl = NULL;
E 4
		*cp++ = '\0';
		do
			cp++;
		while (*cp == ' ' || *cp == '\t');
		for (s = cp; ; s++) {
			switch (*s) {
			case ')':
				*s = '\0';
			case '\0':
				break;
			case ' ':
			case '\t':
				*s++ = '\0';
				while (*s == ' ' || *s == '\t')
					s++;
				if (*s == ')')
					*s = '\0';
				break;
			default:
				continue;
			}
D 4
			if (bp == NULL)
				value = bp = makeblock(NAME, cp);
E 4
I 4
			if (nl == NULL)
				value = nl = makenl(cp);
E 4
			else {
D 4
				bp->b_next = makeblock(NAME, cp);
				bp = bp->b_next;
E 4
I 4
				nl->n_next = makenl(cp);
				nl = nl->n_next;
E 4
			}
			if (*s == '\0')
				break;
			cp = s;
		}
	}
D 4
	bp = makeblock(VAR, name);
	bp->b_args = value;
	(void) lookup(bp->b_name, bp, 1);
E 4
I 4
	(void) lookup(name, REPLACE, value);
E 4
}

D 4
static struct block *hashtab[HASHSIZE];

E 4
/*
 * Lookup name in the table and return a pointer to it.
D 4
 * Insert == 0 - just do lookup, return NULL if not found.
 * insert == 1 - insert name with value, error if already defined.
 * insert == 2 - replace name with value if not entered with insert == 1.
E 4
I 4
 * LOOKUP - just do lookup, return NULL if not found.
 * INSERT - insert name with value, error if already defined.
 * REPLACE - insert or replace name with value.
E 4
 */

D 4
struct block *
lookup(name, value, insert)
E 4
I 4
struct namelist *
lookup(name, action, value)
E 4
	char *name;
D 4
	struct block *value;
	int insert;
E 4
I 4
	int action;
	struct namelist *value;
E 4
{
	register unsigned n;
	register char *cp;
D 4
	register struct block *b, *f;
E 4
I 4
	register struct syment *s;
I 6
	char buf[256];
E 6
E 4

	if (debug)
D 4
		printf("lookup(%s, %x, %d)\n", name, value, insert);
E 4
I 4
		printf("lookup(%s, %d, %x)\n", name, action, value);
E 4

	n = 0;
	for (cp = name; *cp; )
		n += *cp++;
	n %= HASHSIZE;

D 4
	for (b = hashtab[n]; b != NULL; b = b->b_next) {
		if (strcmp(name, b->b_name))
E 4
I 4
	for (s = hashtab[n]; s != NULL; s = s->s_next) {
		if (strcmp(name, s->s_name))
E 4
			continue;
D 4
		if (insert) {
			if (b->b_type == NAME) {
				warn("%s redefined\n", name);
				f = b->b_args;
				b->b_args = value->b_args;
				value->b_args = f;
			} else if (value->b_type == VAR)
E 4
I 4
		if (action != LOOKUP) {
D 5
			if (s->s_type == CONST)
E 5
I 5
D 6
			if (action != INSERT || s->s_type != CONST)
E 5
E 4
				fatal("%s redefined\n", name);
E 6
I 6
			if (action != INSERT || s->s_type != CONST) {
D 8
				sprintf(buf, "%s redefined", name);
E 8
I 8
				(void)sprintf(buf, "%s redefined", name);
E 8
				yyerror(buf);
			}
E 6
I 4
D 5
			if (action == INSERT) {
				warn("%s redefined\n", name);
				s->s_value = value;
			}
E 5
E 4
D 3
			while (f = value->b_next) {
				value->b_next = f->b_next;
				free(f->b_name);
				free(f);
			}
			free(value->b_name);
			free(value);
E 3
		}
D 4
		return(b);
E 4
I 4
		return(s->s_value);
E 4
	}

D 4
	if (!insert)
E 4
I 4
D 6
	if (action == LOOKUP)
E 4
		fatal("%s not defined", name);
E 6
I 6
	if (action == LOOKUP) {
D 8
		yyerror(sprintf(buf, "%s undefined", name));
E 8
I 8
		(void)sprintf(buf, "%s undefined", name);
		yyerror(buf);
E 8
		return(NULL);
	}
E 6

D 4
	value->b_next = hashtab[n];
	hashtab[n] = value;
	return(value);
}

/*
 * Make a block for lists of variables, commands, etc.
 */
struct block *
makeblock(type, name)
	int type;
	register char *name;
{
	register char *cp;
	register struct block *bp;

	bp = ALLOC(block);
	if (bp == NULL)
E 4
I 4
	s = ALLOC(syment);
	if (s == NULL)
E 4
		fatal("ran out of memory\n");
D 4
	bp->b_type = type;
	bp->b_next = bp->b_args = NULL;
	if (type == NAME || type == VAR) {
D 3
		bp->b_name = cp = (char *) malloc(strlen(name) + 1);
E 3
I 3
		bp->b_name = cp = malloc(strlen(name) + 1);
E 3
		if (cp == NULL)
			fatal("ran out of memory\n");
		while (*cp++ = *name++)
			;
	} else
		bp->b_name = NULL;
	return(bp);
E 4
I 4
	s->s_next = hashtab[n];
	hashtab[n] = s;
	s->s_type = action == INSERT ? VAR : CONST;
	s->s_name = name;
	s->s_value = value;
	return(value);
E 4
}
E 1
