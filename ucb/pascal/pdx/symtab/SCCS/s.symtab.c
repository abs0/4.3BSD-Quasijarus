h22901
s 00001/00001/00263
d D 5.2 87/04/07 15:57:08 mckusick 4 3
c port to tahoe by Nir peleg of CCI
e
s 00008/00002/00256
d D 5.1 85/06/06 16:01:37 dist 3 2
c Add copyright
e
s 00116/00116/00142
d D 1.2 82/05/19 17:43:23 linton 2 1
c reformatting for 4-character indentation
e
s 00258/00000/00000
d D 1.1 82/01/18 19:21:25 linton 1 0
c date and time created 82/01/18 19:21:25 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 3

D 3
static char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

/*
D 2
 * symbol table implementation
E 2
I 2
 * Symbol table implementation.
E 2
 */

#include "defs.h"
#include "symtab.h"
#include "sym.h"
#include "sym/classes.h"
#include "sym/sym.rep"

/*
D 2
 * symbol table structure definition, no deletions allowed.
E 2
I 2
 * The symbol table structure is currently assumes no deletions.
E 2
 */

D 2
#define MAXHASHSIZE 1009	/* largest allowable hash table */
E 2
I 2
#define MAXHASHSIZE 1009    /* largest allowable hash table */
E 2

struct symtab {
D 2
	int size;
	int hshsize;
	SYM **symhsh;
	SYM *symarray;
	int symindex;
E 2
I 2
    int size;
    int hshsize;
    SYM **symhsh;
    SYM *symarray;
    int symindex;
E 2
};

/*
D 2
 * symbol table hash macro
E 2
I 2
 * Macro to hash a string.
E 2
 *
 * The hash value is returned through the "h" parameter which should
 * an unsigned integer.  The other parameters are the symbol table, "st",
 * and a pointer to the string to be hashed, "name".
 */

#define hash(h, st, name) \
{ \
D 2
	register char *cp; \
E 2
I 2
    register char *cp; \
E 2
\
D 2
	h = 0; \
	for (cp = name; *cp != '\0'; cp++) { \
		h = (h << 1) | (*cp); \
	} \
	h %= st->hshsize; \
E 2
I 2
    h = 0; \
    for (cp = name; *cp != '\0'; cp++) { \
	h = (h << 1) | (*cp); \
    } \
    h %= st->hshsize; \
E 2
}

/*
 * To create a symbol table, we allocate space for the symbols and
 * for a hash table that's twice as big (+1 to make it odd).
 */

SYMTAB *st_creat(size)
int size;
{
D 2
	register SYMTAB *st;
	register int i;
E 2
I 2
    register SYMTAB *st;
    register int i;
E 2

D 2
	st = alloc(1, SYMTAB);
	st->size = size;
	st->hshsize = 2*size + 1;
	if (st->hshsize > MAXHASHSIZE) {
		st->hshsize = MAXHASHSIZE;
	}
	st->symhsh = alloc(st->hshsize, SYM *);
	st->symarray = alloc(st->size, SYM);
	st->symindex = 0;
	for (i = 0; i < st->hshsize; i++) {
		st->symhsh[i] = NIL;
	}
	return(st);
E 2
I 2
    st = alloc(1, SYMTAB);
    st->size = size;
    st->hshsize = 2*size + 1;
    if (st->hshsize > MAXHASHSIZE) {
	st->hshsize = MAXHASHSIZE;
    }
    st->symhsh = alloc(st->hshsize, SYM *);
    st->symarray = alloc(st->size, SYM);
    st->symindex = 0;
    for (i = 0; i < st->hshsize; i++) {
	st->symhsh[i] = NIL;
    }
    return(st);
E 2
}

st_destroy(st)
SYMTAB *st;
{
D 2
	dispose(st->symhsh);
	dispose(st->symarray);
	dispose(st);
E 2
I 2
    dispose(st->symhsh);
    dispose(st->symarray);
    dispose(st);
E 2
}

/*
 * insert a symbol into a table
 */

SYM *st_insert(st, name)
register SYMTAB *st;
char *name;
{
D 2
	register SYM *s;
	register unsigned int h;
	static SYM zerosym;
E 2
I 2
    register SYM *s;
    register unsigned int h;
    static SYM zerosym;
E 2

D 2
	if (st == NIL) {
		panic("tried to insert into NIL table");
	}
	if (st->symindex >= st->size) {
		panic("too many symbols");
	}
	hash(h, st, name);
	s = &(st->symarray[st->symindex++]);
	*s = zerosym;
	s->symbol = name;
	s->next_sym = st->symhsh[h];
	st->symhsh[h] = s;
	return(s);
E 2
I 2
    if (st == NIL) {
	panic("tried to insert into NIL table");
    }
    if (st->symindex >= st->size) {
	panic("too many symbols");
    }
    hash(h, st, name);
    s = &(st->symarray[st->symindex++]);
    *s = zerosym;
    s->symbol = name;
    s->next_sym = st->symhsh[h];
    st->symhsh[h] = s;
    return(s);
E 2
}

/*
 * symbol lookup
 */

SYM *st_lookup(st, name)
SYMTAB *st;
char *name;
{
D 2
	register SYM *s;
	register unsigned int h;
E 2
I 2
    register SYM *s;
    register unsigned int h;
E 2

D 2
	if (st == NIL) {
		panic("tried to lookup in NIL table");
E 2
I 2
    if (st == NIL) {
	panic("tried to lookup in NIL table");
    }
    hash(h, st, name);
    for (s = st->symhsh[h]; s != NIL; s = s->next_sym) {
	if (strcmp(s->symbol, name) == 0) {
	    break;
E 2
	}
D 2
	hash(h, st, name);
	for (s = st->symhsh[h]; s != NIL; s = s->next_sym) {
		if (strcmp(s->symbol, name) == 0) {
			break;
		}
	}
	return(s);
E 2
I 2
    }
    return(s);
E 2
}

/*
 * Dump out all the variables associated with the given
 * procedure, function, or program at the given recursive level.
 *
 * This is quite inefficient.  We traverse the entire symbol table
 * each time we're called.  The assumption is that this routine
 * won't be called frequently enough to merit improved performance.
 */

dumpvars(f, frame)
SYM *f;
FRAME *frame;
{
D 2
	register SYM *s;
	SYM *first, *last;
E 2
I 2
    register SYM *s;
    SYM *first, *last;
E 2

D 2
	first = symtab->symarray;
	last = first + symtab->symindex - 1;
	for (s = first; s <= last; s++) {
		if (should_print(s, f)) {
			printv(s, frame);
			putchar('\n');
		}
E 2
I 2
    first = symtab->symarray;
    last = first + symtab->symindex - 1;
    for (s = first; s <= last; s++) {
	if (should_print(s, f)) {
	    printv(s, frame);
	    putchar('\n');
E 2
	}
I 2
    }
E 2
}

/*
 * Create an alias for a command.
 *
 * We put it into the given table with block 1, which is how it
 * is distinguished for printing purposes.
 */

enter_alias(table, new, old)
SYMTAB *table;
char *new, *old;
{
D 2
	SYM *s, *t;
E 2
I 2
    SYM *s, *t;
E 2

D 2
	if ((s = st_lookup(table, old)) == NIL) {
		error("%s is not a known command", old);
	}
	if (st_lookup(table, new) != NIL) {
		error("cannot alias command names");
	}
	make_keyword(table, new, s->symvalue.token.toknum);
	t = st_insert(table, new);
	t->blkno = 1;
	t->symvalue.token.toknum = s->symvalue.token.toknum;
	t->type = s;
E 2
I 2
    if ((s = st_lookup(table, old)) == NIL) {
	error("%s is not a known command", old);
    }
    if (st_lookup(table, new) != NIL) {
	error("cannot alias command names");
    }
    make_keyword(table, new, s->symvalue.token.toknum);
    t = st_insert(table, new);
    t->blkno = 1;
    t->symvalue.token.toknum = s->symvalue.token.toknum;
    t->type = s;
E 2
}

/*
 * Print out the currently active aliases.
 * The kludge is that the type pointer for an alias points to the
 * symbol it is aliased to.
 */

print_alias(table, name)
SYMTAB *table;
char *name;
{
D 2
	SYM *s, *t;
	SYM *first, *last;
E 2
I 2
D 4
    SYM *s, *t;
E 4
I 4
    SYM *s;
E 4
    SYM *first, *last;
E 2

D 2
	if (name != NIL) {
		s = st_lookup(table, name);
		if (s == NIL) {
			error("\"%s\" is not an alias", name);
		}
		printf("%s\n", s->type->symbol);
	} else {
		first = table->symarray;
		last = first + table->symindex - 1;
		for (s = first; s <= last; s++) {
			if (s->blkno == 1) {
				printf("%s\t%s\n", s->symbol, s->type->symbol);
			}
		}
E 2
I 2
    if (name != NIL) {
	s = st_lookup(table, name);
	if (s == NIL) {
	    error("\"%s\" is not an alias", name);
E 2
	}
I 2
	printf("%s\n", s->type->symbol);
    } else {
	first = table->symarray;
	last = first + table->symindex - 1;
	for (s = first; s <= last; s++) {
	    if (s->blkno == 1) {
		printf("%s\t%s\n", s->symbol, s->type->symbol);
	    }
	}
    }
E 2
}

/*
 * Find a named type that points to t; return NIL if there is none.
 * This is necessary because of the way pi keeps symbols.
 */

D 2
#define NSYMS_BACK 20		/* size of local context to try */
E 2
I 2
#define NSYMS_BACK 20       /* size of local context to try */
E 2

LOCAL SYM *search();

SYM *findtype(t)
SYM *t;
{
D 2
	SYM *s;
	SYM *first, *last;
	SYM *lower;
E 2
I 2
    SYM *s;
    SYM *first, *last;
    SYM *lower;
E 2

D 2
	first = symtab->symarray;
	last = first + symtab->symindex - 1;
	if ((lower = t - NSYMS_BACK) < first) {
		lower = first;
	}
	if ((s = search(t, lower, last)) == NIL) {
		s = search(t, first, last);
	}
	return(s);
E 2
I 2
    first = symtab->symarray;
    last = first + symtab->symindex - 1;
    if ((lower = t - NSYMS_BACK) < first) {
	lower = first;
    }
    if ((s = search(t, lower, last)) == NIL) {
	s = search(t, first, last);
    }
    return(s);
E 2
}

/*
 * Search the symbol table from first to last, looking for a
 * named type pointing to the given type symbol.
 */

LOCAL SYM *search(t, first, last)
SYM *t;
register SYM *first, *last;
{
D 2
	register SYM *s;
E 2
I 2
    register SYM *s;
E 2

D 2
	for (s = first; s <= last; s++) {
		if (s->class == TYPE && s->type == t && s->symbol != NIL) {
			return(s);
		}
E 2
I 2
    for (s = first; s <= last; s++) {
	if (s->class == TYPE && s->type == t && s->symbol != NIL) {
	    return(s);
E 2
	}
D 2
	return(NIL);
E 2
I 2
    }
    return(NIL);
E 2
}
E 1
