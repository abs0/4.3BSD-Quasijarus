h53734
s 00003/00007/01687
d D 5.5 88/05/11 02:01:27 donn 23 22
c Some tweaks were required in convert() to get 'print float1 / float2' to
c work.  A clause that specifically treats floats as ints ('op != O_NOP...')
c was deleted; the error code was changed so that 'print float1 div
c float2' generates a reasonable message (rather than treating the floats as
c ints, sigh).
e
s 00044/00024/01650
d D 5.4 88/01/12 01:25:51 donn 22 21
c merge in latest Linton version
e
s 00002/00002/01672
d D 5.3 86/02/23 16:16:21 sam 21 20
c purge bitfields for tahoe (doesn't handle signed stuff well)
e
s 00002/00001/01672
d D 5.2 85/09/05 17:32:28 mckusick 20 19
c register printing (from Ralph Campbell)
e
s 00008/00002/01665
d D 5.1 85/05/31 10:18:12 dist 19 18
c Add copyright
e
s 00383/00284/01284
d D 1.17 85/03/01 20:31:56 linton 18 17
c update to version 3.0
e
s 00003/00002/01565
d D 1.16 84/09/01 13:08:53 sam 17 16
c put back old fix -- can't reference function if enclosing module has same name
e
s 00001/00001/01566
d D 1.15 84/08/18 19:52:40 sam 16 15
c add support for tracing register variables
e
s 00002/00003/01565
d D 1.14 84/06/30 17:49:24 sam 15 14
c take out MODULE hack -- who knows how it interacts with modula-2
e
s 00001/00003/01567
d D 1.13 84/06/23 11:43:52 sam 14 12
i 13
c merge linton branch delta trail
e
s 00406/00140/01174
d D 1.11.1.1 84/06/23 10:50:25 sam 13 11
c branch delta of linton changes from net.sources
e
s 00006/00016/01298
d D 1.12 83/12/30 14:36:15 sam 12 11
c skip modules when searching for program symbols so that, for example, 
c functions may be named the same thing as the file they're contained in
e
s 00024/00010/01290
d D 1.11 83/08/16 02:17:16 linton 11 10
c added "symbols_init" from object to initialize t_int, t_char, ...
e
s 00003/00001/01297
d D 1.10 83/08/10 04:56:36 linton 10 9
c added a flag for functions which indicates they are "inline", 
c meaning they have no activation record associated with them -- currently 
c this is only used for C unnamed blocks with declarations inside them
e
s 00021/00014/01277
d D 1.9 83/05/20 10:59:19 linton 9 8
c fixed problem with size of enumerated types in C
e
s 00107/00078/01184
d D 1.8 83/05/18 21:49:25 csvaf 8 7
c support for f77 : rangetypes; ref parameters; typematch
e
s 00003/00003/01259
d D 1.7 83/04/29 12:09:45 linton 7 6
c changed parameter size calculation
e
s 00011/00003/01251
d D 1.6 83/04/25 18:39:20 linton 6 5
c fixed size computation for small variables
e
s 00006/00003/01248
d D 1.5 83/04/08 01:01:49 linton 5 4
c added information to tell if a function had source information 
c associated with it
e
s 00040/00028/01211
d D 1.4 83/03/30 02:24:47 linton 4 3
c put in a temporary fix for subscripting with pointers in C. 
c In the long run, subscripting should be treated as a language-dependent 
c operation.
e
s 00007/00020/01232
d D 1.3 83/02/20 17:09:17 linton 3 2
c now uses "bzero" instead of static sympool structure, 
c also added support for type-rename operator
e
s 00001/00001/01251
d D 1.2 82/12/15 04:22:19 linton 2 1
c fixed @(#) stuff
e
s 01252/00000/00000
d D 1.1 82/12/15 04:05:59 linton 1 0
c date and time created 82/12/15 04:05:59 by linton
e
u
U
f b 
t
T
I 1
D 19
/* Copyright (c) 1982 Regents of the University of California */
E 19
I 19
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 19

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 13
static char sccsid[] = "%Z%%M% %I% %G%";
E 13
I 13
D 14
static char sccsid[] = "@(#)symbols.c 1.10 8/10/83";
E 13
E 2

I 13
static char rcsid[] = "$Header: symbols.c,v 1.4 84/03/27 10:24:18 linton Exp $";
E 14
I 14
D 19
static	char sccsid[] = "%W% (Berkeley) %G%";
E 19
I 19
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 19
E 14

I 18
D 22
static char rcsid[] = "$Header: symbols.c,v 1.6 84/12/26 10:42:31 linton Exp $";
E 22
I 22
D 23
static char rcsid[] = "$Header: symbols.c,v 1.3 87/03/26 23:17:35 donn Exp $";
E 23
I 23
static char rcsid[] = "$Header: symbols.c,v 1.4 88/04/02 01:29:03 donn Exp $";
E 23
E 22

E 18
E 13
/*
 * Symbol management.
 */

#include "defs.h"
#include "symbols.h"
#include "languages.h"
#include "printsym.h"
#include "tree.h"
#include "operators.h"
#include "eval.h"
#include "mappings.h"
#include "events.h"
#include "process.h"
#include "runtime.h"
#include "machine.h"
#include "names.h"

#ifndef public
typedef struct Symbol *Symbol;

#include "machine.h"
#include "names.h"
#include "languages.h"
I 18
#include "tree.h"
E 18

/*
 * Symbol classes
 */

typedef enum {
D 18
    BADUSE, CONST, TYPE, VAR, ARRAY, PTRFILE, RECORD, FIELD,
E 18
I 18
D 22
    BADUSE, CONST, TYPE, VAR, ARRAY, DYNARRAY, SUBARRAY, PTRFILE, RECORD, FIELD,
E 22
I 22
    BADUSE, CONST, TYPE, VAR, ARRAY, OPENARRAY, DYNARRAY, SUBARRAY,
    PTRFILE, RECORD, FIELD,
E 22
E 18
D 8
    PROC, FUNC, FVAR, REF, PTR, FILET, SET, RANGE,
E 8
I 8
    PROC, FUNC, FVAR, REF, PTR, FILET, SET, RANGE, 
E 8
    LABEL, WITHPTR, SCAL, STR, PROG, IMPROPER, VARNT,
D 8
    FPROC, FFUNC, MODULE, TYPEREF, TAG
E 8
I 8
D 13
    FPROC, FFUNC, MODULE, TAG, COMMON, TYPEREF
E 13
I 13
    FPROC, FFUNC, MODULE, TAG, COMMON, EXTREF, TYPEREF
E 13
E 8
} Symclass;

I 8
typedef enum { R_CONST, R_TEMP, R_ARG, R_ADJUST } Rangetype; 

I 22
#define INREG 0
#define STK 1
#define EXT 2

typedef unsigned integer Storage;

E 22
E 8
struct Symbol {
    Name name;
    Language language;
D 21
    Symclass class : 8;
    Integer level : 8;
E 21
I 21
D 22
    Symclass class;
    Integer level;
E 22
I 22
    Symclass class : 8;
    Storage storage : 2;
    unsigned int level : 6;	/* for variables stored on stack only */
E 22
E 21
    Symbol type;
    Symbol chain;
    union {
I 18
	Node constval;		/* value of constant symbol */
E 18
	int offset;		/* variable address */
	long iconval;		/* integer constant value */
	double fconval;		/* floating constant value */
I 18
	int ndims;		/* no. of dimensions for dynamic/sub-arrays */
E 18
	struct {		/* field offset and size (both in bits) */
	    int offset;
	    int length;
	} field;
I 8
	struct {		/* common offset and chain; used to relocate */
	    int offset;         /* vars in global BSS */
	    Symbol chain;
	} common;
E 8
	struct {		/* range bounds */
I 8
            Rangetype lowertype : 16; 
            Rangetype uppertype : 16;  
E 8
	    long lower;
	    long upper;
	} rangev;
D 5
	struct {		/* address of function value, code */
	    int offset;
	    Address beginaddr;
E 5
I 5
	struct {
	    int offset : 16;	/* offset for of function value */
D 10
	    Boolean src : 16;	/* true if there is source line info */
E 10
I 10
D 13
	    Boolean src : 8;	/* true if there is source line info */
	    Boolean inline : 8;	/* true if no separate act. rec. */
E 13
I 13
	    Boolean src : 1;	/* true if there is source line info */
	    Boolean inline : 1;	/* true if no separate act. rec. */
	    Boolean intern : 1; /* internal calling sequence */
	    int unused : 13;
E 13
E 10
	    Address beginaddr;	/* address of function code */
E 5
	} funcv;
	struct {		/* variant record info */
	    int size;
	    Symbol vtorec;
	    Symbol vtag;
	} varnt;
I 13
	String typeref;		/* type defined by "<module>:<type>" */
	Symbol extref;		/* indirect symbol for external reference */
E 13
    } symvalue;
    Symbol block;		/* symbol containing this symbol */
    Symbol next_sym;		/* hash chain */
};

/*
 * Basic types.
 */

Symbol t_boolean;
Symbol t_char;
Symbol t_int;
Symbol t_real;
Symbol t_nil;
I 13
D 18
Symbol t_open;
E 18
I 18
Symbol t_addr;
E 18
E 13

Symbol program;
Symbol curfunc;

I 18
boolean showaggrs;

E 18
#define symname(s) ident(s->name)
#define codeloc(f) ((f)->symvalue.funcv.beginaddr)
#define isblock(s) (Boolean) ( \
    s->class == FUNC or s->class == PROC or \
    s->class == MODULE or s->class == PROG \
)
I 13
#define isroutine(s) (Boolean) ( \
    s->class == FUNC or s->class == PROC \
)
I 16
D 18
#define isreg(s)	(s->level < 0)
E 18
E 16
E 13
I 5

#define nosource(f) (not (f)->symvalue.funcv.src)
I 10
#define isinline(f) ((f)->symvalue.funcv.inline)
E 10
E 5

I 20
D 22
#define isreg(s)		(s->level < 0)
E 22
I 22
#define isreg(s)		(s->storage == INREG)
E 22

E 20
#include "tree.h"

/*
 * Some macros to make finding a symbol with certain attributes.
 */

#define find(s, withname) \
{ \
    s = lookup(withname); \
    while (s != nil and not (s->name == (withname) and

#define where /* qualification */

#define endfind(s) )) { \
	s = s->next_sym; \
    } \
}

#endif

/*
 * Symbol table structure currently does not support deletions.
I 22
 * Hash table size is a power of two to make hashing faster.
 * Using a non-prime is ok since we aren't doing rehashing.
E 22
 */

D 22
#define HASHTABLESIZE 2003
E 22
I 22
#define HASHTABLESIZE 8192
E 22

private Symbol hashtab[HASHTABLESIZE];

D 22
#define hash(name) ((((unsigned) name) >> 2) mod HASHTABLESIZE)
E 22
I 22
#define hash(name) ((((unsigned) name) >> 2) & (HASHTABLESIZE - 1))
E 22

/*
 * Allocate a new symbol.
 */

D 3
#define SYMBLOCKSIZE 1000
E 3
I 3
D 22
#define SYMBLOCKSIZE 100
E 22
I 22
#define SYMBLOCKSIZE 1000
E 22
E 3

typedef struct Sympool {
    struct Symbol sym[SYMBLOCKSIZE];
    struct Sympool *prevpool;
} *Sympool;

private Sympool sympool = nil;
private Integer nleft = 0;
D 3
private struct Sympool zeropool;
E 3

public Symbol symbol_alloc()
{
    register Sympool newpool;

    if (nleft <= 0) {
	newpool = new(Sympool);
D 3
	*newpool = zeropool;
E 3
I 3
D 22
	bzero(newpool, sizeof(newpool));
E 22
I 22
	bzero(newpool, sizeof(*newpool));
E 22
E 3
	newpool->prevpool = sympool;
	sympool = newpool;
	nleft = SYMBLOCKSIZE;
    }
    --nleft;
    return &(sympool->sym[nleft]);
}

I 8
D 18

public symbol_dump(func)
E 18
I 18
public symbol_dump (func)
E 18
Symbol func;
{
D 11
  register Symbol s;
  register Integer i;
E 11
I 11
D 13
    register Symbol s;
    register Integer i;
E 13
I 13
D 18
  register Symbol s;
  register Integer i;
E 18
I 18
    register Symbol s;
    register integer i;
E 18
E 13
E 11

D 11
	printf(" symbols in %s \n",symname(func));
	for(i=0; i< HASHTABLESIZE; i++)
	   for(s=hashtab[i]; s != nil; s=s->next_sym)  {
		if (s->block == func) psym(s);
		}
E 11
I 11
D 13
    printf(" symbols in %s \n",symname(func));
    for (i = 0; i< HASHTABLESIZE; i++) {
	for (s = hashtab[i]; s != nil; s = s->next_sym) {
	    if (s->block == func) {
		psym(s);
	    }
	}
    }
E 13
I 13
D 18
	printf(" symbols in %s \n",symname(func));
	for(i=0; i< HASHTABLESIZE; i++)
	   for(s=hashtab[i]; s != nil; s=s->next_sym)  {
		if (s->block == func) psym(s);
		}
E 18
I 18
    printf(" symbols in %s \n",symname(func));
    for (i = 0; i < HASHTABLESIZE; i++) {
	for (s = hashtab[i]; s != nil; s = s->next_sym) {
	    if (s->block == func) {
		psym(s);
	    }
	}
    }
E 18
E 13
E 11
}

E 8
/*
 * Free all the symbols currently allocated.
 */
I 18

E 18
I 11
D 13

E 13
E 11
D 8

E 8
public symbol_free()
{
    Sympool s, t;
    register Integer i;

    s = sympool;
    while (s != nil) {
	t = s->prevpool;
	dispose(s);
	s = t;
    }
    for (i = 0; i < HASHTABLESIZE; i++) {
	hashtab[i] = nil;
    }
    sympool = nil;
    nleft = 0;
}

/*
 * Create a new symbol with the given attributes.
 */

public Symbol newSymbol(name, blevel, class, type, chain)
Name name;
Integer blevel;
Symclass class;
Symbol type;
Symbol chain;
{
    register Symbol s;

    s = symbol_alloc();
    s->name = name;
I 18
    s->language = primlang;
I 22
    s->storage = EXT;
E 22
E 18
    s->level = blevel;
    s->class = class;
    s->type = type;
    s->chain = chain;
    return s;
}

/*
 * Insert a symbol into the hash table.
 */

public Symbol insert(name)
Name name;
{
    register Symbol s;
    register unsigned int h;

    h = hash(name);
    s = symbol_alloc();
    s->name = name;
    s->next_sym = hashtab[h];
    hashtab[h] = s;
    return s;
}

/*
 * Symbol lookup.
 */

public Symbol lookup(name)
Name name;
{
    register Symbol s;
    register unsigned int h;

    h = hash(name);
    s = hashtab[h];
    while (s != nil and s->name != name) {
	s = s->next_sym;
    }
    return s;
}

/*
I 13
 * Delete a symbol from the symbol table.
 */

public delete (s)
Symbol s;
{
    register Symbol t;
    register unsigned int h;

    h = hash(s->name);
    t = hashtab[h];
    if (t == nil) {
	panic("delete of non-symbol '%s'", symname(s));
    } else if (t == s) {
	hashtab[h] = s->next_sym;
    } else {
	while (t->next_sym != s) {
	    t = t->next_sym;
	    if (t == nil) {
		panic("delete of non-symbol '%s'", symname(s));
	    }
	}
	t->next_sym = s->next_sym;
    }
}

/*
E 13
 * Dump out all the variables associated with the given
D 18
 * procedure, function, or program at the given recursive level.
E 18
I 18
 * procedure, function, or program associated with the given stack frame.
E 18
 *
 * This is quite inefficient.  We traverse the entire symbol table
 * each time we're called.  The assumption is that this routine
 * won't be called frequently enough to merit improved performance.
 */

public dumpvars(f, frame)
Symbol f;
Frame frame;
{
    register Integer i;
    register Symbol s;

    for (i = 0; i < HASHTABLESIZE; i++) {
	for (s = hashtab[i]; s != nil; s = s->next_sym) {
	    if (container(s) == f) {
		if (should_print(s)) {
		    printv(s, frame);
		    putchar('\n');
		} else if (s->class == MODULE) {
		    dumpvars(s, frame);
		}
	    }
	}
    }
}

/*
I 11
D 13
 * Create base types.
 */

public symbols_init()
{
    t_boolean = maketype("$boolean", 0L, 1L);
    t_int = maketype("$integer", 0x80000000L, 0x7fffffffL);
    t_char = maketype("$char", 0L, 127L);
    t_real = maketype("$real", 8L, 0L);
    t_nil = maketype("$nil", 0L, 0L);
}

/*
E 13
E 11
 * Create a builtin type.
 * Builtin types are circular in that btype->type->type = btype.
 */

D 18
public Symbol maketype(name, lower, upper)
E 18
I 18
private Symbol maketype(name, lower, upper)
E 18
String name;
long lower;
long upper;
{
    register Symbol s;
I 18
    Name n;
E 18

D 18
    s = newSymbol(identname(name, true), 0, TYPE, nil, nil);
E 18
I 18
    if (name == nil) {
	n = nil;
    } else {
	n = identname(name, true);
    }
    s = insert(n);
E 18
D 13
    s->language = findlanguage(".c");
E 13
I 13
    s->language = primlang;
I 18
    s->level = 0;
    s->class = TYPE;
    s->type = nil;
    s->chain = nil;
E 18
E 13
    s->type = newSymbol(nil, 0, RANGE, s, nil);
I 13
D 18
    s->type->language = s->language;
E 18
E 13
    s->type->symvalue.rangev.lower = lower;
    s->type->symvalue.rangev.upper = upper;
    return s;
}

/*
D 18
 * These functions are now compiled inline.
 *
 * public String symname(s)
Symbol s;
{
    checkref(s);
    return ident(s->name);
}
E 18
I 18
 * Create the builtin symbols.
 */
E 18

D 18
 *
 * public Address codeloc(f)
Symbol f;
E 18
I 18
public symbols_init ()
E 18
{
D 18
    checkref(f);
    if (not isblock(f)) {
	panic("codeloc: \"%s\" is not a block", ident(f->name));
    }
    return f->symvalue.funcv.beginaddr;
E 18
I 18
    Symbol s;

    t_boolean = maketype("$boolean", 0L, 1L);
    t_int = maketype("$integer", 0x80000000L, 0x7fffffffL);
    t_char = maketype("$char", 0L, 255L);
    t_real = maketype("$real", 8L, 0L);
    t_nil = maketype("$nil", 0L, 0L);
    t_addr = insert(identname("$address", true));
    t_addr->language = primlang;
    t_addr->level = 0;
    t_addr->class = TYPE;
    t_addr->type = newSymbol(nil, 1, PTR, t_int, nil);
    s = insert(identname("true", true));
    s->class = CONST;
    s->type = t_boolean;
    s->symvalue.constval = build(O_LCON, 1L);
    s->symvalue.constval->nodetype = t_boolean;
    s = insert(identname("false", true));
    s->class = CONST;
    s->type = t_boolean;
    s->symvalue.constval = build(O_LCON, 0L);
    s->symvalue.constval->nodetype = t_boolean;
E 18
}
D 18
 *
 */
E 18

/*
 * Reduce type to avoid worrying about type names.
 */

public Symbol rtype(type)
Symbol type;
{
    register Symbol t;

    t = type;
    if (t != nil) {
D 8
	if (t->class == VAR or t->class == FIELD) {
E 8
I 8
D 18
	if (t->class == VAR or t->class == FIELD or t->class == REF ) {
E 18
I 18
	if (t->class == VAR or t->class == CONST or
	    t->class == FIELD or t->class == REF
	) {
E 18
E 8
	    t = t->type;
	}
I 13
	if (t->class == TYPEREF) {
	    resolveRef(t);
	}
E 13
	while (t->class == TYPE or t->class == TAG) {
	    t = t->type;
I 13
	    if (t->class == TYPEREF) {
		resolveRef(t);
	    }
E 13
	}
    }
    return t;
}

I 13
/*
 * Find the end of a module name.  Return nil if there is none
 * in the given string.
 */

private String findModuleMark (s)
String s;
{
    register char *p, *r;
    register boolean done;

    p = s;
    done = false;
    do {
	if (*p == ':') {
	    done = true;
	    r = p;
	} else if (*p == '\0') {
	    done = true;
	    r = nil;
	} else {
	    ++p;
	}
    } while (not done);
    return r;
}

/*
 * Resolve a type reference by modifying to be the appropriate type.
 *
 * If the reference has a name, then it refers to an opaque type and
 * the actual type is directly accessible.  Otherwise, we must use
 * the type reference string, which is of the form "module:{module:}name".
 */

public resolveRef (t)
Symbol t;
{
    register char *p;
    char *start;
    Symbol s, m, outer;
    Name n;

    if (t->name != nil) {
	s = t;
    } else {
	start = t->symvalue.typeref;
	outer = program;
	p = findModuleMark(start);
	while (p != nil) {
	    *p = '\0';
	    n = identname(start, true);
	    find(m, n) where m->block == outer endfind(m);
	    if (m == nil) {
		p = nil;
		outer = nil;
		s = nil;
	    } else {
		outer = m;
		start = p + 1;
		p = findModuleMark(start);
	    }
	}
	if (outer != nil) {
	    n = identname(start, true);
	    find(s, n) where s->block == outer endfind(s);
	}
    }
    if (s != nil and s->type != nil) {
	t->name = s->type->name;
	t->class = s->type->class;
	t->type = s->type->type;
	t->chain = s->type->chain;
	t->symvalue = s->type->symvalue;
	t->block = s->type->block;
    }
}

E 13
D 18
public Integer level(s)
E 18
I 18
public integer regnum (s)
E 18
Symbol s;
{
I 18
    integer r;

E 18
    checkref(s);
D 18
    return s->level;
E 18
I 18
D 22
    if (s->level < 0) {
E 22
I 22
    if (s->storage == INREG) {
E 22
	r = s->symvalue.offset;
    } else {
	r = -1;
    }
    return r;
E 18
}

public Symbol container(s)
Symbol s;
{
    checkref(s);
    return s->block;
}

I 18
public Node constval(s)
Symbol s;
{
    checkref(s);
    if (s->class != CONST) {
	error("[internal error: constval(non-CONST)]");
    }
    return s->symvalue.constval;
}

E 18
/*
 * Return the object address of the given symbol.
 *
 * There are the following possibilities:
 *
 *	globals		- just take offset
 *	locals		- take offset from locals base
 *	arguments	- take offset from argument base
 *	register	- offset is register number
 */

D 13
#define isglobal(s)		(s->level == 1 or s->level == 2)
#define islocaloff(s)		(s->level >= 3 and s->symvalue.offset < 0)
#define isparamoff(s)		(s->level >= 3 and s->symvalue.offset >= 0)
E 13
I 13
D 22
#define isglobal(s)		(s->level == 1)
#define islocaloff(s)		(s->level >= 2 and s->symvalue.offset < 0)
#define isparamoff(s)		(s->level >= 2 and s->symvalue.offset >= 0)
E 22
I 22
#define isglobal(s)		(s->storage == EXT)
#define islocaloff(s)		(s->storage == STK and s->symvalue.offset < 0)
#define isparamoff(s)		(s->storage == STK and s->symvalue.offset >= 0)
E 22
I 18
D 20
#define isreg(s)		(s->level < 0)
E 20
E 18
E 13
D 16
#define isreg(s)		(s->level < 0)
E 16

D 18
public Address address(s, frame)
E 18
I 18
public Address address (s, frame)
E 18
Symbol s;
Frame frame;
{
    register Frame frp;
    register Address addr;
    register Symbol cur;

    checkref(s);
    if (not isactive(s->block)) {
	error("\"%s\" is not currently defined", symname(s));
    } else if (isglobal(s)) {
	addr = s->symvalue.offset;
    } else {
	frp = frame;
	if (frp == nil) {
	    cur = s->block;
	    while (cur != nil and cur->class == MODULE) {
		cur = cur->block;
	    }
	    if (cur == nil) {
D 18
		cur = whatblock(pc);
E 18
I 18
		frp = nil;
	    } else {
		frp = findframe(cur);
		if (frp == nil) {
		    error("[internal error: unexpected nil frame for \"%s\"]",
			symname(s)
		    );
		}
E 18
	    }
D 18
	    frp = findframe(cur);
	    if (frp == nil) {
		panic("unexpected nil frame for \"%s\"", symname(s));
	    }
E 18
	}
	if (islocaloff(s)) {
	    addr = locals_base(frp) + s->symvalue.offset;
	} else if (isparamoff(s)) {
	    addr = args_base(frp) + s->symvalue.offset;
	} else if (isreg(s)) {
	    addr = savereg(s->symvalue.offset, frp);
	} else {
	    panic("address: bad symbol \"%s\"", symname(s));
	}
    }
    return addr;
}

/*
 * Define a symbol used to access register values.
 */

D 18
public defregname(n, r)
E 18
I 18
public defregname (n, r)
E 18
Name n;
D 18
Integer r;
E 18
I 18
integer r;
E 18
{
D 18
    register Symbol s, t;
E 18
I 18
    Symbol s;
E 18

    s = insert(n);
D 18
    t = newSymbol(nil, 0, PTR, t_int, nil);
D 13
    t->language = findlanguage(".s");
E 13
I 13
    t->language = primlang;
E 13
    s->language = t->language;
E 18
I 18
    s->language = t_addr->language;
E 18
    s->class = VAR;
D 22
    s->level = -3;
E 22
I 22
    s->storage = INREG;
    s->level = 3;
E 22
D 18
    s->type = t;
    s->block = program;
E 18
I 18
    s->type = t_addr;
E 18
    s->symvalue.offset = r;
}

/*
 * Resolve an "abstract" type reference.
 *
 * It is possible in C to define a pointer to a type, but never define
 * the type in a particular source file.  Here we try to resolve
 * the type definition.  This is problematic, it is possible to
 * have multiple, different definitions for the same name type.
 */

public findtype(s)
Symbol s;
{
    register Symbol t, u, prev;

    u = s;
    prev = nil;
    while (u != nil and u->class != BADUSE) {
	if (u->name != nil) {
	    prev = u;
	}
	u = u->type;
    }
    if (prev == nil) {
	error("couldn't find link to type reference");
    }
D 18
    find(t, prev->name) where
D 13
	t->type != nil and t->class == prev->class and
	t->type->class != BADUSE and t->block->class == MODULE
E 13
I 13
	t != prev and t->block->class == MODULE and t->class == prev->class and
	t->type != nil and t->type->type != nil and
	t->type->type->class != BADUSE
E 13
    endfind(t);
E 18
I 18
    t = lookup(prev->name);
    while (t != nil and
	not (
	    t != prev and t->name == prev->name and
	    t->block->class == MODULE and t->class == prev->class and
	    t->type != nil and t->type->type != nil and
	    t->type->type->class != BADUSE
	)
    ) {
	t = t->next_sym;
    }
E 18
    if (t == nil) {
	error("couldn't resolve reference");
    } else {
	prev->type = t->type;
    }
}

/*
 * Find the size in bytes of the given type.
 *
 * This is probably the WRONG thing to do.  The size should be kept
 * as an attribute in the symbol information as is done for structures
 * and fields.  I haven't gotten around to cleaning this up yet.
 */

I 8
#define MAXUCHAR 255
#define MAXUSHORT 65535L
E 8
#define MINCHAR -128
#define MAXCHAR 127
I 6
D 8
#define MAXUCHAR 255
E 8
E 6
#define MINSHORT -32768
#define MAXSHORT 32767
I 6
D 8
#define MAXUSHORT 65535L
E 8
E 6

D 13
public Integer size(sym)
E 13
I 13
D 18
/*
 * When necessary, compute the upper bound for an open array (Modula-2 style).
 */

public chkOpenArray (sym)
E 13
Symbol sym;
{
D 13
    register Symbol s, t;
    register int nel, elsize;
E 13
I 13
    Symbol t;
    Address a;
    integer n;

    if (sym->class == REF or sym->class == VAR) {
	t = rtype(sym->type);
	if (t->class == ARRAY and t->chain == t_open) {
	    a = address(sym, nil);
	    dread(&n, a + sizeof(Word), sizeof(n));
	    t->chain->type->symvalue.rangev.upper = n - 1;
	}
    }
}

E 18
public findbounds (u, lower, upper)
Symbol u;
long *lower, *upper;
{
    Rangetype lbt, ubt;
    long lb, ub;

    if (u->class == RANGE) {
	lbt = u->symvalue.rangev.lowertype;
	ubt = u->symvalue.rangev.uppertype;
	lb = u->symvalue.rangev.lower;
	ub = u->symvalue.rangev.upper;
	if (lbt == R_ARG or lbt == R_TEMP) {
	    if (not getbound(u, lb, lbt, lower)) {
		error("dynamic bounds not currently available");
	    }
	} else {
	    *lower = lb;
	}
	if (ubt == R_ARG or ubt == R_TEMP) {
	    if (not getbound(u, ub, ubt, upper)) {
		error("dynamic bounds not currently available");
	    }
	} else {
	    *upper = ub;
	}
    } else if (u->class == SCAL) {
	*lower = 0;
	*upper = u->symvalue.iconval - 1;
    } else {
D 18
	panic("unexpected array bound type");
E 18
I 18
	error("[internal error: unexpected array bound type]");
E 18
    }
}

public integer size(sym)
Symbol sym;
{
    register Symbol s, t, u;
    register integer nel, elsize;
E 13
    long lower, upper;
D 13
    int r;
E 13
I 13
    integer r, off, len;
E 13

    t = sym;
    checkref(t);
I 13
    if (t->class == TYPEREF) {
	resolveRef(t);
    }
E 13
    switch (t->class) {
	case RANGE:
	    lower = t->symvalue.rangev.lower;
	    upper = t->symvalue.rangev.upper;
D 13
	    if (upper == 0 and lower > 0) {		/* real */
E 13
I 13
	    if (upper == 0 and lower > 0) {
		/* real */
E 13
		r = lower;
I 13
	    } else if (lower > upper) {
		/* unsigned long */
		r = sizeof(long);
E 13
D 6
	    } else if (lower >= MINCHAR and upper <= MAXCHAR) {
E 6
I 6
	    } else if (
D 8
		(lower >= MINCHAR and upper <= MAXCHAR) or
		(lower >= 0 and upper <= MAXUCHAR)
	      ) {
E 8
I 8
  		(lower >= MINCHAR and upper <= MAXCHAR) or
  		(lower >= 0 and upper <= MAXUCHAR)
  	      ) {
E 8
E 6
		r = sizeof(char);
D 6
	    } else if (lower >= MINSHORT and upper <= MAXSHORT) {
E 6
I 6
D 8
	    } else if (
		(lower >= MINSHORT and upper <= MAXSHORT) or
		(lower >= 0 and upper <= MAXUSHORT)
	      ) {
E 8
I 8
  	    } else if (
  		(lower >= MINSHORT and upper <= MAXSHORT) or
  		(lower >= 0 and upper <= MAXUSHORT)
  	      ) {
E 8
E 6
		r = sizeof(short);
	    } else {
		r = sizeof(long);
	    }
	    break;

	case ARRAY:
	    elsize = size(t->type);
	    nel = 1;
	    for (t = t->chain; t != nil; t = t->chain) {
D 8
		s = rtype(t);
		lower = s->symvalue.rangev.lower;
		upper = s->symvalue.rangev.upper;
E 8
I 8
D 9

		if(t->symvalue.rangev.lowertype == R_ARG
                   or t->symvalue.rangev.lowertype == R_TEMP )  {
			if( ! getbound(t, t->symvalue.rangev.lower,
		                         t->symvalue.rangev.lowertype, &lower))
			error(" dynamic bounds not currently available ");
E 9
I 9
D 13
		if (t->symvalue.rangev.lowertype == R_ARG or
		  t->symvalue.rangev.lowertype == R_TEMP)  {
		    if (not getbound(t, t->symvalue.rangev.lower,
		      t->symvalue.rangev.lowertype, &lower)) {
			error("dynamic bounds not currently available");
		    }
		} else {
		    lower = t->symvalue.rangev.lower;
E 9
		}
D 9
		else lower = t->symvalue.rangev.lower;

		if(t->symvalue.rangev.uppertype == R_ARG
                   or t->symvalue.rangev.uppertype == R_TEMP )  {
			if( ! getbound(t, t->symvalue.rangev.upper,
		                         t->symvalue.rangev.uppertype, &upper))
			error(" dynamic bounds not currently available ");
E 9
I 9
		if (t->symvalue.rangev.uppertype == R_ARG or
		  t->symvalue.rangev.uppertype == R_TEMP) {
		    if (not getbound(t, t->symvalue.rangev.upper,
		      t->symvalue.rangev.uppertype, &upper)) {
			error("dynamic bounds nor currently available");
		    }
		} else {
		    upper = t->symvalue.rangev.upper;
E 9
		}
E 13
I 13
		u = rtype(t);
		findbounds(u, &lower, &upper);
E 13
D 9
		else upper = t->symvalue.rangev.upper;
E 9
E 8
		nel *= (upper-lower+1);
	    }
	    r = nel*elsize;
	    break;

I 22
	case OPENARRAY:
E 22
I 18
	case DYNARRAY:
	    r = (t->symvalue.ndims + 1) * sizeof(Word);
	    break;

	case SUBARRAY:
	    r = (2 * t->symvalue.ndims + 1) * sizeof(Word);
	    break;

E 18
I 8
	case REF:
E 8
	case VAR:
D 18
	case FVAR:
I 13
	    chkOpenArray(t);
E 18
E 13
	    r = size(t->type);
I 7
	    /*
	     *
E 7
D 6
	    if (r < sizeof(Word)) {
E 6
I 6
	    if (r < sizeof(Word) and isparam(t)) {
E 6
		r = sizeof(Word);
	    }
I 7
D 8
	     */
E 8
I 8
	    */
E 8
E 7
	    break;

I 18
	case FVAR:
E 18
	case CONST:
I 18
	case TAG:
E 18
	    r = size(t->type);
	    break;

	case TYPE:
I 22
	    /*
	     * This causes problems on the IRIS because of the compiler bug
	     * with stab offsets for parameters.  Not sure it's really
	     * necessary anyway.
	     */
#	    ifndef IRIS
E 22
	    if (t->type->class == PTR and t->type->type->class == BADUSE) {
		findtype(t);
	    }
I 22
#	    endif
E 22
	    r = size(t->type);
	    break;

D 18
	case TAG:
	    r = size(t->type);
	    break;

E 18
	case FIELD:
D 13
	    r = (t->symvalue.field.length + 7) div 8;
E 13
I 13
	    off = t->symvalue.field.offset;
	    len = t->symvalue.field.length;
	    r = (off + len + 7) div 8 - (off div 8);
D 18
	    /* r = (t->symvalue.field.length + 7) div 8; */
E 18
E 13
	    break;

	case RECORD:
	case VARNT:
	    r = t->symvalue.offset;
	    if (r == 0 and t->chain != nil) {
		panic("missing size information for record");
	    }
	    break;

	case PTR:
I 18
	case TYPEREF:
E 18
D 8
	case REF:
E 8
	case FILET:
	    r = sizeof(Word);
	    break;

	case SCAL:
I 9
	    r = sizeof(Word);
	    /*
	     *
E 9
	    if (t->symvalue.iconval > 255) {
		r = sizeof(short);
	    } else {
		r = sizeof(char);
	    }
I 9
	     *
	     */
E 9
	    break;

	case FPROC:
	case FFUNC:
	    r = sizeof(Word);
	    break;

	case PROC:
	case FUNC:
	case MODULE:
	case PROG:
	    r = sizeof(Symbol);
	    break;

I 13
	case SET:
	    u = rtype(t->type);
	    switch (u->class) {
		case RANGE:
		    r = u->symvalue.rangev.upper - u->symvalue.rangev.lower + 1;
		    break;

		case SCAL:
		    r = u->symvalue.iconval;
		    break;

		default:
		    error("expected range for set base type");
		    break;
	    }
	    r = (r + BITSPERBYTE - 1) div BITSPERBYTE;
	    break;

I 18
	/*
	 * These can happen in C (unfortunately) for unresolved type references
	 * Assume they are pointers.
	 */
	case BADUSE:
	    r = sizeof(Address);
	    break;

E 18
E 13
	default:
	    if (ord(t->class) > ord(TYPEREF)) {
		panic("size: bad class (%d)", ord(t->class));
	    } else {
D 13
		error("improper operation on a %s", classname(t));
E 13
I 13
D 18
		fprintf(stderr, "!! size(%s) ??", classname(t));
E 18
I 18
		fprintf(stderr, "can't compute size of a %s\n", classname(t));
E 18
E 13
	    }
D 13
	    /* NOTREACHED */
E 13
I 13
	    r = 0;
	    break;
E 13
D 7
    }
    if (r < sizeof(Word) and isparam(sym)) {
	r = sizeof(Word);
E 7
    }
    return r;
}

/*
I 18
 * Return the size associated with a symbol that takes into account
 * reference parameters.  This might be better as the normal size function, but
 * too many places already depend on it working the way it does.
 */

public integer psize (s)
Symbol s;
{
    integer r;
    Symbol t;

    if (s->class == REF) {
	t = rtype(s->type);
D 22
	if (t->class == DYNARRAY) {
E 22
I 22
	if (t->class == OPENARRAY) {
E 22
	    r = (t->symvalue.ndims + 1) * sizeof(Word);
	} else if (t->class == SUBARRAY) {
	    r = (2 * t->symvalue.ndims + 1) * sizeof(Word);
	} else {
	    r = sizeof(Word);
	}
    } else {
	r = size(s);
    }
    return r;
}

/*
E 18
 * Test if a symbol is a parameter.  This is true if there
 * is a cycle from s->block to s via chain pointers.
 */

public Boolean isparam(s)
Symbol s;
{
    register Symbol t;

    t = s->block;
    while (t != nil and t != s) {
	t = t->chain;
    }
    return (Boolean) (t != nil);
}

/*
D 13
 * Test if a symbol is a var parameter, i.e. has class REF.
E 13
I 13
 * Test if a type is an open array parameter type.
E 13
 */

I 13
D 18
public Boolean isopenarray (t)
Symbol t;
E 18
I 18
public boolean isopenarray (type)
Symbol type;
E 18
{
D 18
    return (Boolean) (t->class == ARRAY and t->chain == t_open);
E 18
I 18
    Symbol t;

    t = rtype(type);
D 22
    return (boolean) (t->class == DYNARRAY);
E 22
I 22
    return (boolean) (t->class == OPENARRAY);
E 22
E 18
}

/*
D 18
 * Test if a symbol is a var parameter, i.e. has class REF but
 * is not an open array parameter (those are treated special).
E 18
I 18
 * Test if a symbol is a var parameter, i.e. has class REF.
E 18
 */

E 13
public Boolean isvarparam(s)
Symbol s;
{
    return (Boolean) (s->class == REF);
}

/*
 * Test if a symbol is a variable (actually any addressible quantity
 * with do).
 */

public Boolean isvariable(s)
D 18
register Symbol s;
E 18
I 18
Symbol s;
E 18
{
    return (Boolean) (s->class == VAR or s->class == FVAR or s->class == REF);
}

/*
D 18
 * Test if a symbol is a block, e.g. function, procedure, or the
 * main program.
 *
 * This function is now expanded inline for efficiency.
 *
 * public Boolean isblock(s)
register Symbol s;
E 18
I 18
 * Test if a symbol is a constant.
 */

public Boolean isconst(s)
Symbol s;
E 18
{
D 18
    return (Boolean) (
	s->class == FUNC or s->class == PROC or
	s->class == MODULE or s->class == PROG
    );
E 18
I 18
    return (Boolean) (s->class == CONST);
E 18
}
D 18
 *
 */
E 18

/*
 * Test if a symbol is a module.
 */

public Boolean ismodule(s)
register Symbol s;
{
    return (Boolean) (s->class == MODULE);
}

/*
D 18
 * Test if a symbol is builtin, that is, a predefined type or
 * reserved word.
 */

public Boolean isbuiltin(s)
register Symbol s;
{
    return (Boolean) (s->level == 0 and s->class != PROG and s->class != VAR);
}

/*
E 18
I 13
 * Mark a procedure or function as internal, meaning that it is called
 * with a different calling sequence.
 */

public markInternal (s)
Symbol s;
{
    s->symvalue.funcv.intern = true;
}

public boolean isinternal (s)
Symbol s;
{
    return s->symvalue.funcv.intern;
}

/*
I 18
 * Decide if a field begins or ends on a bit rather than byte boundary.
 */

public Boolean isbitfield(s)
register Symbol s;
{
    boolean b;
    register integer off, len;
    register Symbol t;

    off = s->symvalue.field.offset;
    len = s->symvalue.field.length;
    if ((off mod BITSPERBYTE) != 0 or (len mod BITSPERBYTE) != 0) {
	b = true;
    } else {
	t = rtype(s->type);
	b = (Boolean) (
	    (t->class == SCAL and len != (sizeof(int)*BITSPERBYTE)) or
	    len != (size(t)*BITSPERBYTE)
	);
    }
    return b;
}

private boolean primlang_typematch (t1, t2)
Symbol t1, t2;
{
    return (boolean) (
	(t1 == t2) or
	(
	    t1->class == RANGE and t2->class == RANGE and
	    t1->symvalue.rangev.lower == t2->symvalue.rangev.lower and
	    t1->symvalue.rangev.upper == t2->symvalue.rangev.upper
	) or (
	    t1->class == PTR and t2->class == RANGE and
	    t2->symvalue.rangev.upper >= t2->symvalue.rangev.lower
	) or (
	    t2->class == PTR and t1->class == RANGE and
	    t1->symvalue.rangev.upper >= t1->symvalue.rangev.lower
	)
    );
}

/*
E 18
E 13
 * Test if two types match.
 * Equivalent names implies a match in any language.
 *
 * Special symbols must be handled with care.
 */

public Boolean compatible(t1, t2)
register Symbol t1, t2;
{
    Boolean b;
I 13
    Symbol rt1, rt2;
E 13

    if (t1 == t2) {
	b = true;
    } else if (t1 == nil or t2 == nil) {
	b = false;
    } else if (t1 == procsym) {
	b = isblock(t2);
    } else if (t2 == procsym) {
	b = isblock(t1);
I 13
D 22
    } else if (t1->language == primlang) {
	if (t2->language == primlang) {
D 18
	    rt1 = rtype(t1);
	    rt2 = rtype(t2);
	    b = (boolean) (
		(rt1->type == t_open and rt2->type == t_int) or
		(rt2->type == t_open and rt1->type == t_int) or
		rt1 == rt2
	    );
E 18
I 18
	    b = primlang_typematch(rtype(t1), rtype(t2));
E 18
	} else {
	    b = (boolean) (*language_op(t2->language, L_TYPEMATCH))(t1, t2);
	}
    } else if (t2->language == primlang) {
	b = (boolean) (*language_op(t1->language, L_TYPEMATCH))(t1, t2);
E 22
E 13
    } else if (t1->language == nil) {
D 13
	b = (Boolean) (t2->language == nil or
	    (*language_op(t2->language, L_TYPEMATCH))(t1, t2));
E 13
I 13
	if (t2->language == nil) {
	    b = false;
I 22
	} else if (t2->language == primlang) {
	    b = (boolean) primlang_typematch(rtype(t1), rtype(t2));
	} else {
	    b = (boolean) (*language_op(t2->language, L_TYPEMATCH))(t1, t2);
	}
    } else if (t1->language == primlang) {
	if (t2->language == primlang or t2->language == nil) {
	    b = primlang_typematch(rtype(t1), rtype(t2));
E 22
	} else {
	    b = (boolean) (*language_op(t2->language, L_TYPEMATCH))(t1, t2);
	}
E 13
I 8
D 18
    } else if (t2->language == nil) {
D 13
	b = (Boolean) (*language_op(t1->language, L_TYPEMATCH))(t1, t2);
    } else if ( isbuiltin(t1) or isbuiltin(t1->type) ) {
	b = (Boolean) (*language_op(t2->language, L_TYPEMATCH))(t1, t2);
E 13
I 13
	b = (boolean) (*language_op(t1->language, L_TYPEMATCH))(t1, t2);
    } else if (isbuiltin(t1) or isbuiltin(t1->type)) {
	b = (boolean) (*language_op(t2->language, L_TYPEMATCH))(t1, t2);
E 18
E 13
E 8
    } else {
D 13
	b = (Boolean) (*language_op(t1->language, L_TYPEMATCH))(t1, t2);
E 13
I 13
	b = (boolean) (*language_op(t1->language, L_TYPEMATCH))(t1, t2);
E 13
    }
    return b;
}

/*
 * Check for a type of the given name.
 */

public Boolean istypename(type, name)
Symbol type;
String name;
{
D 18
    Symbol t;
E 18
I 18
    register Symbol t;
E 18
    Boolean b;

    t = type;
D 18
    checkref(t);
    b = (Boolean) (
D 13
	t->class == TYPE and t->name == identname(name, true)
E 13
I 13
	t->class == TYPE and streq(ident(t->name), name)
E 13
    );
E 18
I 18
    if (t == nil) {
	b = false;
    } else {
	b = (Boolean) (
	    t->class == TYPE and streq(ident(t->name), name)
	);
    }
E 18
    return b;
}

/*
I 13
 * Determine if a (value) parameter should actually be passed by address.
 */

public boolean passaddr (p, exprtype)
Symbol p, exprtype;
{
    boolean b;
    Language def;

    if (p == nil) {
	def = findlanguage(".c");
	b = (boolean) (*language_op(def, L_PASSADDR))(p, exprtype);
    } else if (p->language == nil or p->language == primlang) {
	b = false;
    } else if (isopenarray(p->type)) {
	b = true;
    } else {
	b = (boolean) (*language_op(p->language, L_PASSADDR))(p, exprtype);
    }
    return b;
}

/*
E 13
 * Test if the name of a symbol is uniquely defined or not.
 */

public Boolean isambiguous(s)
register Symbol s;
{
    register Symbol t;

    find(t, s->name) where t != s endfind(t);
    return (Boolean) (t != nil);
}

typedef char *Arglist;

#define nextarg(type)  ((type *) (ap += sizeof(type)))[-1]

private Symbol mkstring();
D 18
private Symbol namenode();
E 18

/*
 * Determine the type of a parse tree.
I 18
 *
E 18
 * Also make some symbol-dependent changes to the tree such as
D 18
 * changing removing RVAL nodes for constant symbols.
E 18
I 18
 * removing indirection for constant or register symbols.
E 18
 */

D 18
public assigntypes(p)
E 18
I 18
public assigntypes (p)
E 18
register Node p;
{
    register Node p1;
    register Symbol s;

    switch (p->op) {
	case O_SYM:
D 18
	    p->nodetype = namenode(p);
E 18
I 18
	    p->nodetype = p->value.sym;
E 18
	    break;

	case O_LCON:
	    p->nodetype = t_int;
	    break;

I 18
	case O_CCON:
	    p->nodetype = t_char;
	    break;

E 18
	case O_FCON:
	    p->nodetype = t_real;
	    break;

	case O_SCON:
D 18
	    p->value.scon = strdup(p->value.scon);
	    s = mkstring(p->value.scon);
	    if (s == t_char) {
		p->op = O_LCON;
		p->value.lcon = p->value.scon[0];
	    }
	    p->nodetype = s;
E 18
I 18
	    p->nodetype = mkstring(p->value.scon);
E 18
	    break;

	case O_INDIR:
	    p1 = p->value.arg[0];
D 18
	    chkclass(p1, PTR);
E 18
I 18
	    s = rtype(p1->nodetype);
	    if (s->class != PTR) {
		beginerrmsg();
		fprintf(stderr, "\"");
		prtree(stderr, p1);
		fprintf(stderr, "\" is not a pointer");
		enderrmsg();
	    }
E 18
	    p->nodetype = rtype(p1->nodetype)->type;
	    break;

	case O_DOT:
	    p->nodetype = p->value.arg[1]->value.sym;
	    break;

	case O_RVAL:
	    p1 = p->value.arg[0];
	    p->nodetype = p1->nodetype;
	    if (p1->op == O_SYM) {
D 18
		if (p1->nodetype->class == FUNC) {
		    p->op = O_CALL;
		    p->value.arg[1] = nil;
E 18
I 18
		if (p1->nodetype->class == PROC or p->nodetype->class == FUNC) {
		    p->op = p1->op;
		    p->value.sym = p1->value.sym;
		    p->nodetype = p1->nodetype;
		    dispose(p1);
E 18
		} else if (p1->value.sym->class == CONST) {
D 18
		    if (compatible(p1->value.sym->type, t_real)) {
			p->op = O_FCON;
			p->value.fcon = p1->value.sym->symvalue.fconval;
			p->nodetype = t_real;
			dispose(p1);
		    } else {
			p->op = O_LCON;
			p->value.lcon = p1->value.sym->symvalue.iconval;
			p->nodetype = p1->value.sym->type;
			dispose(p1);
		    }
E 18
I 18
		    p->op = p1->op;
		    p->value = p1->value;
		    p->nodetype = p1->nodetype;
		    dispose(p1);
E 18
		} else if (isreg(p1->value.sym)) {
		    p->op = O_SYM;
		    p->value.sym = p1->value.sym;
		    dispose(p1);
		}
	    } else if (p1->op == O_INDIR and p1->value.arg[0]->op == O_SYM) {
		s = p1->value.arg[0]->value.sym;
		if (isreg(s)) {
		    p1->op = O_SYM;
		    dispose(p1->value.arg[0]);
		    p1->value.sym = s;
		    p1->nodetype = s;
		}
	    }
	    break;

I 13
D 18
	/*
	 * Perform a cast if the call is of the form "type(expr)".
	 */
E 18
I 18
	case O_COMMA:
	    p->nodetype = p->value.arg[0]->nodetype;
	    break;

	case O_CALLPROC:
E 18
E 13
D 11
	/*
	 * Perform a cast if the call is of the form "type(expr)".
	 */
E 11
	case O_CALL:
	    p1 = p->value.arg[0];
D 3
	    if (p1->op == O_SYM and
	      (p1->value.sym->class == TYPE or p1->value.sym->class == TAG)) {
		s = p1->value.sym;
		dispose(p1);
		p1 = p->value.arg[1];
		assert(p1->op == O_COMMA);
		if (p1->value.arg[1] != nil) {
		    error("unexpected comma within type conversion");
		}
		p->op = O_RVAL;
		p->value.arg[0] = p1->value.arg[0];
		p->nodetype = s;
		p->value.arg[0]->nodetype = s;
		dispose(p1);
	    } else {
		p->nodetype = rtype(p1->nodetype)->type;
	    }
E 3
I 3
	    p->nodetype = rtype(p1->nodetype)->type;
	    break;

	case O_TYPERENAME:
	    p->nodetype = p->value.arg[1]->nodetype;
E 3
	    break;

	case O_ITOF:
	    p->nodetype = t_real;
	    break;

	case O_NEG:
	    s = p->value.arg[0]->nodetype;
	    if (not compatible(s, t_int)) {
		if (not compatible(s, t_real)) {
		    beginerrmsg();
I 13
		    fprintf(stderr, "\"");
E 13
		    prtree(stderr, p->value.arg[0]);
D 13
		    fprintf(stderr, "is improper type");
E 13
I 13
		    fprintf(stderr, "\" is improper type");
E 13
		    enderrmsg();
		} else {
		    p->op = O_NEGF;
		}
	    }
	    p->nodetype = s;
	    break;

	case O_ADD:
	case O_SUB:
	case O_MUL:
I 13
	    binaryop(p, nil);
	    break;

E 13
	case O_LT:
	case O_LE:
	case O_GT:
	case O_GE:
	case O_EQ:
	case O_NE:
D 13
	{
	    Boolean t1real, t2real;
	    Symbol t1, t2;

	    t1 = rtype(p->value.arg[0]->nodetype);
	    t2 = rtype(p->value.arg[1]->nodetype);
	    t1real = compatible(t1, t_real);
	    t2real = compatible(t2, t_real);
	    if (t1real or t2real) {
		p->op = (Operator) (ord(p->op) + 1);
		if (not t1real) {
		    p->value.arg[0] = build(O_ITOF, p->value.arg[0]);
		} else if (not t2real) {
		    p->value.arg[1] = build(O_ITOF, p->value.arg[1]);
		}
	    } else {
		if (t1real) {
		    convert(&(p->value.arg[0]), t_int, O_NOP);
		}
		if (t2real) {
		    convert(&(p->value.arg[1]), t_int, O_NOP);
		}
	    }
	    if (ord(p->op) >= ord(O_LT)) {
		p->nodetype = t_boolean;
	    } else {
		if (t1real or t2real) {
		    p->nodetype = t_real;
		} else {
		    p->nodetype = t_int;
		}
	    }
E 13
I 13
	    binaryop(p, t_boolean);
E 13
	    break;
D 13
	}
E 13

	case O_DIVF:
	    convert(&(p->value.arg[0]), t_real, O_ITOF);
	    convert(&(p->value.arg[1]), t_real, O_ITOF);
	    p->nodetype = t_real;
	    break;

	case O_DIV:
	case O_MOD:
	    convert(&(p->value.arg[0]), t_int, O_NOP);
	    convert(&(p->value.arg[1]), t_int, O_NOP);
	    p->nodetype = t_int;
	    break;

	case O_AND:
	case O_OR:
	    chkboolean(p->value.arg[0]);
	    chkboolean(p->value.arg[1]);
	    p->nodetype = t_boolean;
	    break;

	case O_QLINE:
	    p->nodetype = t_int;
	    break;

	default:
	    p->nodetype = nil;
	    break;
    }
}

/*
I 13
 * Process a binary arithmetic or relational operator.
 * Convert from integer to real if necessary.
 */

private binaryop (p, t)
Node p;
Symbol t;
{
    Node p1, p2;
    Boolean t1real, t2real;
    Symbol t1, t2;

    p1 = p->value.arg[0];
    p2 = p->value.arg[1];
    t1 = rtype(p1->nodetype);
    t2 = rtype(p2->nodetype);
    t1real = compatible(t1, t_real);
    t2real = compatible(t2, t_real);
    if (t1real or t2real) {
	p->op = (Operator) (ord(p->op) + 1);
	if (not t1real) {
	    p->value.arg[0] = build(O_ITOF, p1);
	} else if (not t2real) {
	    p->value.arg[1] = build(O_ITOF, p2);
	}
	p->nodetype = t_real;
    } else {
	if (size(p1->nodetype) > sizeof(integer)) {
	    beginerrmsg();
	    fprintf(stderr, "operation not defined on \"");
	    prtree(stderr, p1);
	    fprintf(stderr, "\"");
	    enderrmsg();
	} else if (size(p2->nodetype) > sizeof(integer)) {
	    beginerrmsg();
	    fprintf(stderr, "operation not defined on \"");
	    prtree(stderr, p2);
	    fprintf(stderr, "\"");
	    enderrmsg();
	}
	p->nodetype = t_int;
    }
    if (t != nil) {
	p->nodetype = t;
    }
}

/*
E 13
D 18
 * Create a node for a name.  The symbol for the name has already
 * been chosen, either implicitly with "which" or explicitly from
 * the dot routine.
 */

private Symbol namenode(p)
Node p;
{
    register Symbol r, s;
    register Node np;

    s = p->value.sym;
    if (s->class == REF) {
	np = new(Node);
	np->op = p->op;
	np->nodetype = s;
	np->value.sym = s;
	p->op = O_INDIR;
	p->value.arg[0] = np;
    }
/*
 * Old way
 *
    if (s->class == CONST or s->class == VAR or s->class == FVAR) {
	r = s->type;
    } else {
	r = s;
    }
 *
 */
    return s;
}

/*
E 18
 * Convert a tree to a type via a conversion operator;
 * if this isn't possible generate an error.
D 23
 *
 * Note the tree is call by address, hence the #define below.
E 23
 */

private convert(tp, typeto, op)
Node *tp;
Symbol typeto;
Operator op;
{
D 13
#define tree    (*tp)
E 13
I 13
    Node tree;
    Symbol s, t;
E 13

D 13
    Symbol s;

E 13
I 13
    tree = *tp;
E 13
    s = rtype(tree->nodetype);
D 13
    typeto = rtype(typeto);
    if (compatible(typeto, t_real) and compatible(s, t_int)) {
E 13
I 13
    t = rtype(typeto);
    if (compatible(t, t_real) and compatible(s, t_int)) {
I 23
	/* we can convert int => floating but not the reverse */
E 23
E 13
	tree = build(op, tree);
D 13
    } else if (not compatible(s, typeto)) {
E 13
I 13
    } else if (not compatible(s, t)) {
E 13
	beginerrmsg();
D 13
	prtree(stderr, s);
	fprintf(stderr, " is improper type");
E 13
I 13
D 23
	fprintf(stderr, "expected integer or real, found \"");
E 23
	prtree(stderr, tree);
D 23
	fprintf(stderr, "\"");
E 23
I 23
	fprintf(stderr, ": illegal type in operation");
E 23
E 13
	enderrmsg();
D 13
    } else if (op != O_NOP and s != typeto) {
E 13
I 13
D 23
    } else if (op != O_NOP and s != t) {
E 13
	tree = build(op, tree);
E 23
    }
D 13

#undef tree
E 13
I 13
    *tp = tree;
E 13
}

/*
 * Construct a node for the dot operator.
 *
 * If the left operand is not a record, but rather a procedure
 * or function, then we interpret the "." as referencing an
 * "invisible" variable; i.e. a variable within a dynamically
 * active block but not within the static scope of the current procedure.
 */

public Node dot(record, fieldname)
Node record;
Name fieldname;
{
D 18
    register Node p;
E 18
I 18
    register Node rec, p;
E 18
    register Symbol s, t;

D 18
    if (isblock(record->nodetype)) {
E 18
I 18
    rec = record;
    if (isblock(rec->nodetype)) {
E 18
	find(s, fieldname) where
D 18
	    s->block == record->nodetype and
	    s->class != FIELD and s->class != TAG
E 18
I 18
	    s->block == rec->nodetype and
	    s->class != FIELD
E 18
	endfind(s);
	if (s == nil) {
	    beginerrmsg();
	    fprintf(stderr, "\"%s\" is not defined in ", ident(fieldname));
D 18
	    printname(stderr, record->nodetype);
E 18
I 18
	    printname(stderr, rec->nodetype);
E 18
	    enderrmsg();
	}
	p = new(Node);
	p->op = O_SYM;
	p->value.sym = s;
D 18
	p->nodetype = namenode(p);
E 18
I 18
	p->nodetype = s;
E 18
    } else {
D 18
	p = record;
E 18
I 18
	p = rec;
E 18
	t = rtype(p->nodetype);
	if (t->class == PTR) {
	    s = findfield(fieldname, t->type);
	} else {
	    s = findfield(fieldname, t);
	}
	if (s == nil) {
	    beginerrmsg();
	    fprintf(stderr, "\"%s\" is not a field in ", ident(fieldname));
D 18
	    prtree(stderr, record);
E 18
I 18
	    prtree(stderr, rec);
E 18
	    enderrmsg();
	}
D 18
	if (t->class == PTR and not isreg(record->nodetype)) {
	    p = build(O_INDIR, record);
E 18
I 18
	if (t->class != PTR or isreg(rec->nodetype)) {
	    p = unrval(p);
E 18
	}
I 18
	p->nodetype = t_addr;
E 18
	p = build(O_DOT, p, build(O_SYM, s));
    }
D 18
    return p;
E 18
I 18
    return build(O_RVAL, p);
E 18
}

/*
 * Return a tree corresponding to an array reference and do the
 * error checking.
 */

public Node subscript(a, slist)
Node a, slist;
{
D 8
    register Symbol t;
    register Node p;
    Symbol etype, atype, eltype;
D 4
    Node esub, olda;
E 4
I 4
    Node esub, r;
E 8
I 8
D 13
Symbol t;
E 13
I 13
    Symbol t;
I 18
    Node p;
E 18
E 13
E 8
E 4

D 4
    olda = a;
E 4
I 4
D 8
    r = a;
E 4
    t = rtype(a->nodetype);
D 4
    if (t->class != ARRAY) {
E 4
I 4
    eltype = t->type;
    if (t->class == PTR) {
	p = slist->value.arg[0];
	if (not compatible(p->nodetype, t_int)) {
	    beginerrmsg();
	    fprintf(stderr, "bad type for subscript of ");
	    prtree(stderr, a);
	    enderrmsg();
	}
	r = build(O_MUL, p, build(O_LCON, (long) size(eltype)));
	r = build(O_ADD, build(O_RVAL, a), r);
	r->nodetype = eltype;
    } else if (t->class != ARRAY) {
E 4
	beginerrmsg();
	prtree(stderr, a);
	fprintf(stderr, " is not an array");
	enderrmsg();
D 4
    }
    eltype = t->type;
    p = slist;
    t = t->chain;
    for (; p != nil and t != nil; p = p->value.arg[1], t = t->chain) {
	esub = p->value.arg[0];
	etype = rtype(esub->nodetype);
	atype = rtype(t);
	if (not compatible(atype, etype)) {
E 4
I 4
    } else {
	p = slist;
	t = t->chain;
	for (; p != nil and t != nil; p = p->value.arg[1], t = t->chain) {
	    esub = p->value.arg[0];
	    etype = rtype(esub->nodetype);
	    atype = rtype(t);
	    if (not compatible(atype, etype)) {
		beginerrmsg();
		fprintf(stderr, "subscript ");
		prtree(stderr, esub);
		fprintf(stderr, " is the wrong type");
		enderrmsg();
	    }
	    r = build(O_INDEX, r, esub);
	    r->nodetype = eltype;
	}
	if (p != nil or t != nil) {
E 4
	    beginerrmsg();
D 4
	    fprintf(stderr, "subscript ");
	    prtree(stderr, esub);
	    fprintf(stderr, " is the wrong type");
E 4
I 4
	    if (p != nil) {
		fprintf(stderr, "too many subscripts for ");
	    } else {
		fprintf(stderr, "not enough subscripts for ");
	    }
	    prtree(stderr, a);
E 4
	    enderrmsg();
	}
D 4
	a = build(O_INDEX, a, esub);
	a->nodetype = eltype;
E 4
    }
D 4
    if (p != nil or t != nil) {
	beginerrmsg();
	if (p != nil) {
	    fprintf(stderr, "too many subscripts for ");
	} else {
	    fprintf(stderr, "not enough subscripts for ");
	}
	prtree(stderr, olda);
	enderrmsg();
    }
    return a;
E 4
I 4
    return r;
E 8
I 8
D 13
   t = rtype(a->nodetype);
   if(t->language == nil) {
E 13
I 13
    t = rtype(a->nodetype);
D 18
    if (t->language == nil) {
E 13
	error("unknown language");
E 18
I 18
    if (t->language == nil or t->language == primlang) {
	p = (Node) (*language_op(findlanguage(".s"), L_BUILDAREF))(a, slist);
E 18
D 13
   }
   else {
        return ( (Node)
        (*language_op(t->language, L_BUILDAREF)) (a,slist)
               );
   }
E 13
I 13
    } else {
D 18
	return (Node) (*language_op(t->language, L_BUILDAREF))(a, slist);
E 18
I 18
	p = (Node) (*language_op(t->language, L_BUILDAREF))(a, slist);
E 18
    }
I 18
    return build(O_RVAL, p);
E 18
E 13
E 8
E 4
}

/*
 * Evaluate a subscript index.
 */

D 18
public int evalindex(s, i)
E 18
I 18
public int evalindex(s, base, i)
E 18
Symbol s;
I 18
Address base;
E 18
long i;
{
D 8
    long lb, ub;
E 8
I 8
D 13
Symbol t;
E 13
I 13
    Symbol t;
I 18
    int r;
E 18
E 13
E 8

D 8
    s = rtype(s)->chain;
    lb = s->symvalue.rangev.lower;
    ub = s->symvalue.rangev.upper;
    if (i < lb or i > ub) {
	error("subscript out of range");
    }
    return (i - lb);
E 8
I 8
D 13
   t = rtype(s);
   if(t->language == nil) {
E 13
I 13
    t = rtype(s);
D 18
    if (t->language == nil) {
E 13
	error("unknown language");
E 18
I 18
    if (t->language == nil or t->language == primlang) {
	r = ((*language_op(findlanguage(".s"), L_EVALAREF)) (s, base, i));
E 18
D 13
   }
   else {
        return (
             (*language_op(t->language, L_EVALAREF)) (s,i)
               );
   }
E 13
I 13
    } else {
D 18
	return ((*language_op(t->language, L_EVALAREF)) (s, i));
E 18
I 18
	r = ((*language_op(t->language, L_EVALAREF)) (s, base, i));
E 18
    }
I 18
    return r;
E 18
E 13
E 8
}

/*
 * Check to see if a tree is boolean-valued, if not it's an error.
 */

public chkboolean(p)
register Node p;
{
    if (p->nodetype != t_boolean) {
	beginerrmsg();
	fprintf(stderr, "found ");
	prtree(stderr, p);
	fprintf(stderr, ", expected boolean expression");
	enderrmsg();
    }
}

/*
D 18
 * Check to make sure the given tree has a type of the given class.
 */

private chkclass(p, class)
Node p;
Symclass class;
{
    struct Symbol tmpsym;

    tmpsym.class = class;
    if (rtype(p->nodetype)->class != class) {
	beginerrmsg();
	fprintf(stderr, "\"");
	prtree(stderr, p);
	fprintf(stderr, "\" is not a %s", classname(&tmpsym));
	enderrmsg();
    }
}

/*
E 18
D 13
 * Construct a node for the type of a string.  While we're at it,
 * scan the string for '' that collapse to ', and chop off the ends.
E 13
I 13
 * Construct a node for the type of a string.
E 13
 */

private Symbol mkstring(str)
String str;
{
D 18
    register char *p, *q;
E 18
    register Symbol s;
I 13
D 18
    integer len;
E 18
E 13

D 18
    p = str;
    q = str;
    while (*p != '\0') {
	if (*p == '\\') {
	    ++p;
	}
	*q = *p;
	++p;
	++q;
    }
    *q = '\0';
D 13
    s = newSymbol(nil, 0, ARRAY, t_char, nil);
    s->language = findlanguage(".s");
    s->chain = newSymbol(nil, 0, RANGE, t_int, nil);
    s->chain->language = s->language;
    s->chain->symvalue.rangev.lower = 1;
    s->chain->symvalue.rangev.upper = p - str + 1;
E 13
I 13
    len = p - str;
    if (len == 1) {
	s = t_char;
    } else {
	s = newSymbol(nil, 0, ARRAY, t_char, nil);
	s->language = primlang;
	s->chain = newSymbol(nil, 0, RANGE, t_int, nil);
	s->chain->language = s->language;
	s->chain->symvalue.rangev.lower = 1;
	s->chain->symvalue.rangev.upper = len + 1;
    }
E 18
I 18
    s = newSymbol(nil, 0, ARRAY, t_char, nil);
    s->chain = newSymbol(nil, 0, RANGE, t_int, nil);
    s->chain->language = s->language;
    s->chain->symvalue.rangev.lower = 1;
    s->chain->symvalue.rangev.upper = strlen(str) + 1;
E 18
E 13
    return s;
}

/*
 * Free up the space allocated for a string type.
 */

public unmkstring(s)
Symbol s;
{
    dispose(s->chain);
}

/*
D 18
 * Figure out the "current" variable or function being referred to,
 * this is either the active one or the most visible from the
 * current scope.
E 18
I 18
 * Figure out the "current" variable or function being referred to
 * by the name n.
E 18
 */

D 18
public Symbol which(n)
E 18
I 18
private boolean stwhich(), dynwhich();

public Symbol which (n)
E 18
Name n;
{
D 18
    register Symbol s, p, t, f;
E 18
I 18
    Symbol s;
E 18

D 12
    find(s, n) where s->class != FIELD and s->class != TAG endfind(s);
E 12
I 12
D 18
    find(s, n)
D 15
	where s->class != FIELD and s->class != TAG and s->class != MODULE
E 15
I 15
D 17
	where s->class != FIELD and s->class != TAG
E 17
I 17
	where s->class != FIELD and s->class != TAG and s->class != MODULE
E 17
E 15
    endfind(s);
E 18
I 18
    s = lookup(n);
E 18
E 12
    if (s == nil) {
D 18
	s = lookup(n);
    }
    if (s == nil) {
E 18
	error("\"%s\" is not defined", ident(n));
D 18
    } else if (s == program or isbuiltin(s)) {
	t = s;
E 18
I 18
    } else if (not stwhich(&s) and isambiguous(s) and not dynwhich(&s)) {
	printf("[using ");
	printname(stdout, s);
	printf("]\n");
    }
    return s;
}

/*
 * Static search.
 */

private boolean stwhich (var_s)
Symbol *var_s;
{
    Name n;		/* name of desired symbol */
    Symbol s;		/* iteration variable for symbols with name n */
    Symbol f;		/* iteration variable for blocks containing s */
    integer count;	/* number of levels from s->block to curfunc */
    Symbol t;		/* current best answer for stwhich(n) */
    integer mincount;	/* relative level for current best answer (t) */
    boolean b;		/* return value, true if symbol found */

    s = *var_s;
    n = s->name;
    t = s;
    mincount = 10000; /* force first match to set mincount */
    do {
	if (s->name == n and s->class != FIELD and s->class != TAG) {
	    f = curfunc;
	    count = 0;
	    while (f != nil and f != s->block) {
		++count;
		f = f->block;
	    }
	    if (f != nil and count < mincount) {
		t = s;
		mincount = count;
		b = true;
	    }
	}
	s = s->next_sym;
    } while (s != nil);
    if (mincount != 10000) {
	*var_s = t;
	b = true;
E 18
    } else {
D 12
    /*
     * Old way
     *
	if (not isactive(program)) {
	    f = program;
	} else {
	    f = whatblock(pc);
	    if (f == nil) {
		panic("no block for addr 0x%x", pc);
	    }
	}
     *
     * Now start with curfunc.
     */
E 12
I 12
D 18
       /* start with current function */
E 12
	p = curfunc;
	do {
	    find(t, n) where
D 12
		t->block == p and t->class != FIELD and t->class != TAG
E 12
I 12
D 15
		t->block == p and t->class != FIELD and
		t->class != TAG and t->class != MODULE
E 15
I 15
D 17
		t->block == p and t->class != FIELD and t->class != TAG
E 17
I 17
		t->block == p and
		t->class != FIELD and t->class != TAG and t->class != MODULE
E 17
E 15
E 12
	    endfind(t);
	    p = p->block;
	} while (t == nil and p != nil);
	if (t == nil) {
	    t = s;
E 18
I 18
	b = false;
    }
    return b;
}

/*
 * Dynamic search.
 */

private boolean dynwhich (var_s)
Symbol *var_s;
{
    Name n;		/* name of desired symbol */
    Symbol s;		/* iteration variable for possible symbols */
    Symbol f;		/* iteration variable for active functions */
    Frame frp;		/* frame associated with stack walk */
    boolean b;		/* return value */

    f = curfunc;
    frp = curfuncframe();
    n = (*var_s)->name;
    b = false;
    if (frp != nil) {
	frp = nextfunc(frp, &f);
	while (frp != nil) {
	    s = *var_s;
	    while (s != nil and
		(
		    s->name != n or s->block != f or
		    s->class == FIELD or s->class == TAG
		)
	    ) {
		s = s->next_sym;
	    }
	    if (s != nil) {
		*var_s = s;
		b = true;
		break;
	    }
	    if (f == program) {
		break;
	    }
	    frp = nextfunc(frp, &f);
E 18
	}
    }
D 18
    return t;
E 18
I 18
    return b;
E 18
}

/*
D 18
 * Find the symbol which is has the same name and scope as the
E 18
I 18
 * Find the symbol that has the same name and scope as the
E 18
 * given symbol but is of the given field.  Return nil if there is none.
 */

D 18
public Symbol findfield(fieldname, record)
E 18
I 18
public Symbol findfield (fieldname, record)
E 18
Name fieldname;
Symbol record;
{
    register Symbol t;

    t = rtype(record)->chain;
    while (t != nil and t->name != fieldname) {
	t = t->chain;
    }
    return t;
I 8
}

public Boolean getbound(s,off,type,valp)
Symbol s;
int off;
Rangetype type;
int *valp;
{
    Frame frp;
    Address addr;
    Symbol cur;

    if (not isactive(s->block)) {
	return(false);
    }
    cur = s->block;
    while (cur != nil and cur->class == MODULE) {  /* WHY*/
    		cur = cur->block;
    }
    if(cur == nil) {
		cur = whatblock(pc);
    }
    frp = findframe(cur);
    if (frp == nil) {
	return(false);
    }
    if(type == R_TEMP) addr = locals_base(frp) + off;
    else if (type == R_ARG) addr = args_base(frp) + off;
    else return(false);
    dread(valp,addr,sizeof(long));
    return(true);
E 8
}
E 1
