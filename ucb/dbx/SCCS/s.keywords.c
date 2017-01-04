h53518
s 00001/00000/00488
d D 5.2 85/06/04 18:33:30 sam 10 9
c this was a bitch to find
e
s 00008/00002/00480
d D 5.1 85/05/31 10:00:38 dist 9 8
c Add copyright
e
s 00360/00137/00122
d D 1.7 85/03/01 20:23:43 linton 8 7
c update to version 3.0
e
s 00028/00008/00231
d D 1.6 84/08/17 21:24:51 sam 7 6
c add unalias facility
e
s 00110/00098/00129
d D 1.5 84/08/12 13:22:09 sam 6 5
c add real aliases; rewrite lexical scanner
e
s 00001/00003/00226
d D 1.4 84/06/23 11:40:54 sam 5 3
i 4
c merge linton branch delta trail
e
s 00044/00010/00185
d D 1.3.1.1 84/06/23 10:46:40 sam 4 3
c branch delta of linton changes from net.sources
e
s 00001/00001/00194
d D 1.3 83/05/18 19:34:54 csvaf 3 2
c added debug keyword
e
s 00001/00001/00194
d D 1.2 82/12/15 04:20:21 linton 2 1
c fixed @(#) stuff
e
s 00195/00000/00000
d D 1.1 82/12/15 04:07:34 linton 1 0
c date and time created 82/12/15 04:07:34 by linton
e
u
U
f b 
t
T
I 1
D 9
/* Copyright (c) 1982 Regents of the University of California */
E 9
I 9
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 9

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 4
static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
D 5
static char sccsid[] = "@(#)keywords.c 1.3 5/18/83";
E 4
E 2

I 4
static char rcsid[] = "$Header: keywords.c,v 1.3 84/03/27 10:21:05 linton Exp $";
E 5
I 5
D 9
static	char sccsid[] = "%W% (Berkeley) %G%";
E 9
I 9
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 9
E 5

I 8
static char rcsid[] = "$Header: keywords.c,v 1.5 84/12/26 10:39:45 linton Exp $";

E 8
E 4
/*
D 6
 * Keyword management.
E 6
I 6
D 8
 * Keyword and alias management.
E 8
I 8
 * Keywords, variables, and aliases (oh my!).
E 8
E 6
 */

#include "defs.h"
#include "keywords.h"
#include "scanner.h"
#include "names.h"
#include "symbols.h"
#include "tree.h"
I 8
#include "lists.h"
#include "main.h"
E 8
#include "y.tab.h"

#ifndef public
I 8

E 8
#include "scanner.h"
I 8
#include "tree.h"

E 8
#endif

private String reserved[] ={
    "alias", "and", "assign", "at", "call", "catch", "cont",
D 3
    "delete", "div", "dump", "edit", "file", "func",
E 3
I 3
D 4
    "debug", "delete", "div", "dump", "edit", "file", "func",
E 4
I 4
    "debug", "delete", "div", "down", "dump", "edit", "file", "func",
E 4
E 3
    "gripe", "help", "if", "ignore", "in",
    "list", "mod", "next", "nexti", "nil", "not", "or",
D 4
    "print", "psym", "quit", "run",
E 4
I 4
    "print", "psym", "quit", "rerun", "return", "run",
E 4
D 8
    "sh", "skip", "source", "status", "step", "stepi",
D 4
    "stop", "stopi", "trace", "tracei",
E 4
I 4
    "stop", "stopi", "trace", "tracei", "up",
E 4
    "use", "whatis", "when", "where", "whereis", "which",
    "INT", "REAL", "NAME", "STRING",
    "LFORMER", "RFORMER", "#^", "->"
E 8
I 8
    "set", "sh", "skip", "source", "status", "step", "stepi",
    "stop", "stopi", "trace", "tracei", "unalias", "unset", "up", "use",
    "whatis", "when", "where", "whereis", "which",
    "INT", "CHAR", "REAL", "NAME", "STRING", "->"
E 8
};

/*
 * The keyword table is a traditional hash table with collisions
 * resolved by chaining.
 */
I 8

#define HASHTABLESIZE 1007

typedef enum { ISKEYWORD, ISALIAS, ISVAR } KeywordType;

E 8
D 6

#define HASHTABLESIZE 503

E 6
typedef struct Keyword {
    Name name;
D 8
    Token toknum : 16;
E 8
I 8
    KeywordType class : 16;
    union {
	/* ISKEYWORD: */
	    Token toknum;

	/* ISALIAS: */
	    struct {
		List paramlist;
		String expansion;
	    } alias;

	/* ISVAR: */
	    Node var;
    } value;
E 8
D 6
    Boolean isalias : 16;
E 6
    struct Keyword *chain;
} *Keyword;

typedef unsigned int Hashvalue;

D 6
private Keyword hashtab[HASHTABLESIZE];
E 6
I 6
D 8
#define KEYWORDHASH	101
private Keyword hashtab[KEYWORDHASH];
#define keyhash(n) ((((unsigned) n) >> 2) mod KEYWORDHASH)
E 8
I 8
private Keyword hashtab[HASHTABLESIZE];
E 8
E 6

D 6
#define hash(n) ((((unsigned) n) >> 2) mod HASHTABLESIZE)
E 6
I 6
D 8
/*
 * The alias table is virtually the same, just
 * replace the token id with a string to which
 * the alias expands.
 */
typedef struct Alias {
     Name name;
     Name expansion;
     struct Alias *chain;
} *Alias;
E 8
I 8
#define hash(n) ((((unsigned) n) >> 2) mod HASHTABLESIZE)
E 8
E 6

I 6
D 8
#define	ALIASHASH	503
private	Alias aliashashtab[ALIASHASH];
#define aliashash(n) ((((unsigned) n) >> 2) mod ALIASHASH)

E 8
E 6
/*
 * Enter all the reserved words into the keyword table.
I 8
 *
 * If the vaddrs flag is set (through the -k command line option) then
 * set the special "$mapaddrs" variable.  This assumes that the
 * command line arguments are scanned before this routine is called.
E 8
 */
I 8

E 8
D 6

E 6
public enterkeywords()
{
D 8
    register Integer i;
E 8
I 8
    register integer i;
E 8

D 6
    for (i = ALIAS; i <= WHICH; i++) {
	keyword(reserved[ord(i) - ord(ALIAS)], i, false);
    }
    keyword("set", ASSIGN, false);
I 4
    keyword("c", CONT, true);
    keyword("d", DELETE, true);
    keyword("h", HELP, true);
    keyword("e", EDIT, true);
    keyword("l", LIST, true);
    keyword("n", NEXT, true);
    keyword("p", PRINT, true);
    keyword("q", QUIT, true);
    keyword("r", RUN, true);
    keyword("s", STEP, true);
    keyword("st", STOP, true);
    keyword("j", STATUS, true);
    keyword("t", WHERE, true);
E 6
I 6
D 8
    for (i = ALIAS; i <= WHICH; i++)
E 8
I 8
    for (i = ALIAS; i <= WHICH; i++) {
E 8
	keyword(reserved[ord(i) - ord(ALIAS)], i);
D 8
    keyword("set", ASSIGN);

    alias(identname("c", true), identname(keywdstring(CONT), true));
    alias(identname("d", true), identname(keywdstring(DELETE), true));
    alias(identname("h", true), identname(keywdstring(HELP), true));
    alias(identname("e", true), identname(keywdstring(EDIT), true));
    alias(identname("l", true), identname(keywdstring(LIST), true));
    alias(identname("n", true), identname(keywdstring(NEXT), true));
    alias(identname("p", true), identname(keywdstring(PRINT), true));
    alias(identname("q", true), identname(keywdstring(QUIT), true));
    alias(identname("r", true), identname(keywdstring(RUN), true));
    alias(identname("s", true), identname(keywdstring(STEP), true));
    alias(identname("st", true), identname(keywdstring(STOP), true));
    alias(identname("j", true), identname(keywdstring(STATUS), true));
    alias(identname("t", true), identname(keywdstring(WHERE), true));
E 8
I 8
    }
    defalias("c", "cont");
    defalias("d", "delete");
    defalias("h", "help");
    defalias("e", "edit");
    defalias("l", "list");
    defalias("n", "next");
    defalias("p", "print");
    defalias("q", "quit");
    defalias("r", "run");
    defalias("s", "step");
    defalias("st", "stop");
    defalias("j", "status");
    defalias("t", "where");
    if (vaddrs) {
	defvar(identname("$mapaddrs", true), nil);
    }
E 8
E 6
E 4
}

/*
D 6
 * Deallocate the keyword table.
E 6
I 6
D 8
 * Deallocate the keyword and alias tables.
E 8
I 8
 * Deallocate the keyword table.
E 8
E 6
 */
I 8

E 8
D 6

E 6
public keywords_free()
{
    register Integer i;
    register Keyword k, nextk;
I 6
D 8
    register Alias a, nexta;
E 8
E 6

D 6
    for (i = 0; i < HASHTABLESIZE; i++) {
	k = hashtab[i];
	while (k != nil) {
E 6
I 6
D 8
    for (i = 0; i < KEYWORDHASH; i++) {
	for (k = hashtab[i]; k != nil; k = nextk) {
E 8
I 8
    for (i = 0; i < HASHTABLESIZE; i++) {
	k = hashtab[i];
	while (k != nil) {
E 8
E 6
	    nextk = k->chain;
	    dispose(k);
I 8
	    k = nextk;
E 8
D 6
	    k = nextk;
E 6
	}
	hashtab[i] = nil;
    }
I 6
D 8
    for (i = 0; i < ALIASHASH; i++) {
	for (a = aliashashtab[i]; a != nil; a = nexta) {
	    nexta = a->chain;
	    dispose(a);
E 8
I 8
}

/*
 * Insert a name into the keyword table and return the keyword for it.
 */

private Keyword keywords_insert (n)
Name n;
{
    Hashvalue h;
    Keyword k;

    h = hash(n);
    k = new(Keyword);
    k->name = n;
    k->chain = hashtab[h];
    hashtab[h] = k;
    return k;
}

/*
 * Find the keyword associated with the given name.
 */

private Keyword keywords_lookup (n)
Name n;
{
    Hashvalue h;
    register Keyword k;

    h = hash(n);
    k = hashtab[h];
    while (k != nil and k->name != n) {
	k = k->chain;
    }
    return k;
}

/*
 * Delete the given keyword of the given class.
 */

private boolean keywords_delete (n, class)
Name n;
KeywordType class;
{
    Hashvalue h;
    register Keyword k, prevk;
    boolean b;

    h = hash(n);
    k = hashtab[h];
    prevk = nil;
    while (k != nil and (k->name != n or k->class != class)) {
	prevk = k;
	k = k->chain;
    }
    if (k != nil) {
	b = true;
	if (prevk == nil) {
	    hashtab[h] = k->chain;
	} else {
	    prevk->chain = k->chain;
E 8
	}
D 8
	aliashashtab[i] = nil;
E 8
I 8
	dispose(k);
    } else {
	b = false;
E 8
    }
I 8
    return b;
E 8
E 6
}

/*
D 6
 * Enter a keyword into the name table.  It is assumed to not be there already.
E 6
I 6
D 8
 * Enter a keyword into the name table. 
 * It is assumed to not be there already.
E 8
I 8
 * Enter a keyword into the table.  It is assumed to not be there already.
E 8
E 6
 * The string is assumed to be statically allocated.
 */
D 6

private keyword(s, t, isalias)
E 6
I 6
D 8
private keyword(s, t)
E 8
I 8

private keyword (s, t)
E 8
E 6
String s;
Token t;
D 6
Boolean isalias;
E 6
{
D 6
    register Hashvalue h;
E 6
D 8
    register Keyword k;
I 6
    Hashvalue h;
E 8
I 8
    Keyword k;
E 8
E 6
    Name n;

    n = identname(s, true);
D 6
    h = hash(n);
E 6
I 6
D 8
    h = keyhash(n);
E 6
    k = new(Keyword);
    k->name = n;
    k->toknum = t;
D 6
    k->isalias = isalias;
E 6
    k->chain = hashtab[h];
    hashtab[h] = k;
E 8
I 8
    k = keywords_insert(n);
    k->class = ISKEYWORD;
    k->value.toknum = t;
E 8
}

/*
D 8
 * Return the string associated with a token corresponding to a keyword.
E 8
I 8
 * Define a builtin command name alias.
E 8
 */
D 6

E 6
D 8
public String keywdstring(t)
Token t;
E 8
I 8

private defalias (s1, s2)
String s1, s2;
E 8
{
D 8
    return reserved[ord(t) - ord(ALIAS)];
E 8
I 8
    alias(identname(s1, true), nil, s2);
E 8
}

/*
D 4
 * Find a keyword in the keyword table.
 * We assume that tokens cannot legitimately be nil (0).
E 4
I 4
D 6
 * Find the keyword associated with the given string.
E 6
I 6
D 8
 * Return the token associated with a given keyword string.
 * We assume that tokens cannot legitimately be nil (0).
E 8
I 8
 * Look for a word of a particular class.
E 8
E 6
E 4
 */

D 4
public Token findkeyword(n)
E 4
I 4
D 6
private Keyword kwlookup (n)
E 6
I 6
D 8
public Token findkeyword(n)
E 8
I 8
private Keyword findword (n, class)
E 8
E 6
E 4
Name n;
I 8
KeywordType class;
E 8
{
D 4
    register Hashvalue h;
E 4
I 4
D 6
    Hashvalue h;
E 6
E 4
    register Keyword k;
D 4
    Token t;
E 4

D 6
    h = hash(n);
    k = hashtab[h];
    while (k != nil and k->name != n) {
	k = k->chain;
    }
I 4
    return k;
E 6
I 6
D 8
    for (k = hashtab[keyhash(n)]; k != nil && k->name != n; k = k->chain)
	;
    return (k == nil ? nil : k->toknum);
E 8
I 8
    k = keywords_lookup(n);
    while (k != nil and (k->name != n or k->class != class)) {
	k = k->chain;
    }
    return k;
E 8
E 6
}

D 6
/*
 * Return the token associated with a given keyword string.
 * We assume that tokens cannot legitimately be nil (0).
 */

public Token findkeyword(n)
E 6
I 6
D 8
public String findalias(n)
E 8
I 8
/*
 * Return the token associated with a given keyword string.
 * If there is none, return the given default value.
 */

public Token findkeyword (n, def)
E 8
E 6
Name n;
I 8
Token def;
E 8
{
D 6
    Keyword k;
    Token t;
E 6
I 6
D 8
    register Alias a;
E 8
I 8
    Keyword k;
    Token t;
E 8
E 6

D 6
    k = kwlookup(n);
E 4
    if (k == nil) {
	t = nil;
    } else {
	t = k->toknum;
    }
    return t;
E 6
I 6
D 8
    for (a = aliashashtab[aliashash(n)]; a != nil && a->name != n; a = a->chain)
	;
    return (a == nil ? nil : ident(a->expansion));
E 8
I 8
    k = findword(n, ISKEYWORD);
    if (k == nil) {
	t = def;
    } else {
	t = k->value.toknum;
    }
    return t;
E 8
E 6
}

/*
D 8
 * Create an alias.
E 8
I 8
 * Return the associated string if there is an alias with the given name.
E 8
 */
D 6

public enter_alias(newcmd, oldcmd)
Name newcmd;
Name oldcmd;
E 6
I 6
D 8
public enter_alias(cmd, p)
E 8
I 8

public boolean findalias (n, pl, str)
Name n;
List *pl;
String *str;
{
    Keyword k;
    boolean b;

    k = findword(n, ISALIAS);
    if (k == nil) {
	b = false;
    } else {
	*pl = k->value.alias.paramlist;
	*str = k->value.alias.expansion;
I 10
	b = true;
E 10
    }
    return b;
}

/*
 * Return the string associated with a token corresponding to a keyword.
 */

public String keywdstring (t)
Token t;
{
    return reserved[ord(t) - ord(ALIAS)];
}

/*
 * Process an alias command, either entering a new alias or printing out
 * an existing one.
 */

public alias (newcmd, args, str)
Name newcmd;
List args;
String str;
{
    Keyword k;

    if (str == nil) {
	print_alias(newcmd);
    } else {
	k = findword(newcmd, ISALIAS);
	if (k == nil) {
	    k = keywords_insert(newcmd);
	}
	k->class = ISALIAS;
	k->value.alias.paramlist = args;
	k->value.alias.expansion = str;
    }
}

/*
 * Print out an alias.
 */

private print_alias (cmd)
E 8
Name cmd;
D 8
Node p;
E 8
E 6
{
D 8
    Token t;
E 8
I 8
    register Keyword k;
    register Integer i;
E 8
I 4
D 6
    Keyword k;
E 6
I 6
    Name n;
E 6
E 4

D 6
    t = findkeyword(oldcmd);
    if (t == nil) {
	error("\"%s\" is not a command", ident(oldcmd));
    } else {
D 4
	keyword(ident(newcmd), t, true);
E 4
I 4
	k = kwlookup(newcmd);
	if (k == nil) {
	    keyword(ident(newcmd), t, true);
	} else {
	    k->toknum = t;
	}
E 6
I 6
D 8
    t = findkeyword(cmd);
    if (t != nil) {
D 7
	error("\"%s\" can't redefine a command", ident(cmd));
E 7
I 7
	error("\"%s\" can't alias a command", ident(cmd));
E 7
	return;
E 8
I 8
    if (cmd == nil) {
	for (i = 0; i < HASHTABLESIZE; i++) {
	    for (k = hashtab[i]; k != nil; k = k->chain) {
		if (k->class == ISALIAS) {
		    if (isredirected()) {
			printf("alias %s", ident(k->name));
			printparams(k->value.alias.paramlist);
			printf("\t\"%s\"\n", k->value.alias.expansion);
		    } else {
			printf("%s", ident(k->name));
			printparams(k->value.alias.paramlist);
			printf("\t%s\n", k->value.alias.expansion);
		    }
		}
	    }
	}
    } else {
	k = findword(cmd, ISALIAS);
	if (k == nil) {
	    printf("\n");
	} else {
	    printparams(k->value.alias.paramlist);
	    printf("%s\n", k->value.alias.expansion);
	}
E 8
E 6
E 4
    }
I 6
D 8
    if (p->op == O_SCON)
	n = identname(p->value.scon, true);
    else
	n = identname(ident(p->value.name), true);
    alias(cmd, n);
E 8
E 6
}

I 6
D 8
private alias(cmd, n)
Name cmd, n;
E 8
I 8
private printparams (pl)
List pl;
E 8
{
D 8
    register Alias a;
    Hashvalue h;
E 8
I 8
    Name n;
E 8

D 8
    h = aliashash(cmd);
    for (a = aliashashtab[h]; a != nil && a->name != cmd; a = a->chain)
	;
    if (a != nil) {
D 7
	a->expansion = n;
E 7
I 7
	/* interpret ``alias x x'' as ``unalias x'' */
	if (streq(ident(cmd), ident(n)))
	    unalias(h, a);
	else
	    a->expansion = n;
E 7
	return;
E 8
I 8
    if (pl != nil) {
	printf("(");
	foreach(Name, n, pl)
	    printf("%s", ident(n));
	    if (not list_islast()) {
		printf(", ");
	    }
	endfor
	printf(")");
E 8
    }
D 7
    a = new(Alias);
    a->name = cmd;
    a->expansion = n;
    a->chain = aliashashtab[h];
    aliashashtab[h] = a;
E 7
I 7
D 8
    if (!streq(ident(cmd), ident(n))) {		/* as above */
	a = new(Alias);
	a->name = cmd;
	a->expansion = n;
	a->chain = aliashashtab[h];
	aliashashtab[h] = a;
E 8
I 8
}

/*
 * Remove an alias.
 */

public unalias (n)
Name n;
{
    if (not keywords_delete(n, ISALIAS)) {
	error("%s is not aliased", ident(n));
E 8
    }
E 7
}

I 7
D 8
private unalias(h, a)
Alias a;
Hashvalue h;
E 8
I 8
/*
 * Define a variable.
 */

public defvar (n, val)
Name n;
Node val;
E 8
{
D 8
    register Alias *ap;
E 8
I 8
    Keyword k;
E 8

D 8
    for (ap = &aliashashtab[h]; *ap != nil && *ap != a; ap = &(*ap)->chain)
	;
    assert(*ap == a);
    *ap = a->chain;
    dispose(a);
E 8
I 8
    if (n == nil) {
	print_vars();
    } else {
	if (lookup(n) != nil) {
	    error("\"%s\" is a program symbol -- use assign", ident(n));
	}
	k = findword(n, ISVAR);
	if (k == nil) {
	    k = keywords_insert(n);
	}
	k->class = ISVAR;
	k->value.var = val;
	if (n == identname("$mapaddrs", true)) {
	    vaddrs = true;
	}
    }
E 8
}

E 7
E 6
/*
D 8
 * Print out an alias.
E 8
I 8
 * Return the value associated with a variable.
E 8
 */
D 6

E 6
D 8
public print_alias(cmd)
Name cmd;
E 8
I 8

public Node findvar (n)
Name n;
E 8
{
D 6
    register Keyword k;
E 6
I 6
D 8
    register Alias a;
E 6
    register Integer i;
D 6
    Token t;
E 6
I 6
    String s;
E 8
I 8
    Keyword k;
    Node val;
E 8
E 6

D 6
    if (cmd == nil) {
	for (i = 0; i < HASHTABLESIZE; i++) {
	    for (k = hashtab[i]; k != nil; k = k->chain) {
		if (k->isalias) {
		    if (isredirected()) {
			printf("alias ");
		    }
		    printf("%s\t%s\n", ident(k->name), keywdstring(k->toknum));
		}
	    }
	}
    } else {
	t = findkeyword(cmd);
	if (t == nil) {
	    printf("\n");
	} else {
	    printf("%s\n", keywdstring(t));
E 6
I 6
D 8
    if (cmd != nil) {
	s = findalias(cmd);
D 7
	printf(s == nil ? "\n" : "%s\n", s);
E 7
I 7
	if (s != nil)
	    printf("%s\n", s);
E 7
	return;
E 8
I 8
    k = findword(n, ISVAR);
    if (k == nil) {
	val = nil;
    } else {
	val = k->value.var;
E 8
    }
D 8
    /*
     * Dump the alias table.
     */
    for (i = 0; i < ALIASHASH; i++) {
	for (a = aliashashtab[i]; a != nil; a = a->chain) {
	    if (isredirected())
		printf("alias ");
	    printf("%s\t%s\n", ident(a->name), ident(a->expansion));
E 8
I 8
    return val;
}

/*
 * Return whether or not a variable is set.
 */

public boolean varIsSet (s)
String s;
{
    return (boolean) (findword(identname(s, false), ISVAR) != nil);
}

/*
 * Delete a variable.
 */

public undefvar (n)
Name n;
{
    if (not keywords_delete(n, ISVAR)) {
	error("%s is not set", ident(n));
    }
    if (n == identname("$mapaddrs", true)) {
	vaddrs = false;
    }
}

/*
 * Print out all the values of set variables.
 */

private print_vars ()
{
    register integer i;
    register Keyword k;

    for (i = 0; i < HASHTABLESIZE; i++) {
	for (k = hashtab[i]; k != nil; k = k->chain) {
	    if (k->class == ISVAR) {
		if (isredirected()) {
		    printf("set ");
		}
		printf("%s", ident(k->name));
		if (k->value.var != nil) {
		    printf("\t");
		    prtree(stdout, k->value.var);
		}
		printf("\n");
	    }
E 8
E 6
	}
    }
}
E 1
