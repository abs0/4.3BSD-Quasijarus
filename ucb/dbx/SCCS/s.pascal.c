h01692
s 00008/00002/00883
d D 5.1 85/05/31 10:13:12 dist 6 5
c Add copyright
e
s 00493/00182/00392
d D 1.4 85/03/01 20:27:42 linton 5 4
c update to version 3.0
e
s 00001/00003/00573
d D 1.3 84/06/23 11:42:40 sam 4 2
i 3
c merge linton branch delta trail
e
s 00153/00017/00423
d D 1.2.1.1 84/06/23 10:48:49 sam 3 2
c branch delta of linton changes from net.sources
e
s 00001/00001/00439
d D 1.2 82/12/15 04:21:27 linton 2 1
c fixed @(#) stuff
e
s 00440/00000/00000
d D 1.1 82/12/15 04:08:21 linton 1 0
c date and time created 82/12/15 04:08:21 by linton
e
u
U
f b 
t
T
I 1
D 6
/* Copyright (c) 1982 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 3
static char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
D 4
static char sccsid[] = "@(#)pascal.c 1.2 12/15/82";
E 3
E 2

I 3
static char rcsid[] = "$Header: pascal.c,v 1.3 84/03/27 10:23:04 linton Exp $";
E 4
I 4
D 6
static	char sccsid[] = "%W% (Berkeley) %G%";
E 6
I 6
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
E 4

I 5
static char rcsid[] = "$Header: pascal.c,v 1.5 84/12/26 10:41:18 linton Exp $";

E 5
E 3
/*
 * Pascal-dependent symbol routines.
 */

#include "defs.h"
#include "symbols.h"
#include "pascal.h"
#include "languages.h"
#include "tree.h"
#include "eval.h"
#include "mappings.h"
#include "process.h"
#include "runtime.h"
#include "machine.h"

#ifndef public
#endif

I 3
private Language pasc;
I 5
private boolean initialized;
E 5

E 3
/*
 * Initialize Pascal information.
 */

public pascal_init()
{
D 3
    Language lang;

    lang = language_define("pascal", ".p");
    language_setop(lang, L_PRINTDECL, pascal_printdecl);
    language_setop(lang, L_PRINTVAL, pascal_printval);
    language_setop(lang, L_TYPEMATCH, pascal_typematch);
E 3
I 3
    pasc = language_define("pascal", ".p");
    language_setop(pasc, L_PRINTDECL, pascal_printdecl);
    language_setop(pasc, L_PRINTVAL, pascal_printval);
    language_setop(pasc, L_TYPEMATCH, pascal_typematch);
    language_setop(pasc, L_BUILDAREF, pascal_buildaref);
    language_setop(pasc, L_EVALAREF, pascal_evalaref);
    language_setop(pasc, L_MODINIT, pascal_modinit);
    language_setop(pasc, L_HASMODULES, pascal_hasmodules);
    language_setop(pasc, L_PASSADDR, pascal_passaddr);
D 5
    initTypes();
E 5
I 5
    initialized = false;
E 5
E 3
}

/*
D 5
 * Compatible tests if two types are compatible.  The issue
 * is complicated a bit by ranges.
 *
 * Integers and reals are not compatible since they cannot always be mixed.
E 5
I 5
 * Typematch tests if two types are compatible.  The issue
 * is a bit complicated, so several subfunctions are used for
 * various kinds of compatibility.
E 5
 */

D 5
public Boolean pascal_typematch(type1, type2)
Symbol type1, type2;
E 5
I 5
private boolean builtinmatch (t1, t2)
register Symbol t1, t2;
E 5
{
D 5
    Boolean b;
    register Symbol t1, t2;
E 5
I 5
    boolean b;
E 5

D 5
    t1 = rtype(t1);
    t2 = rtype(t2);
    b = (Boolean)
	(t1->type == t2->type and (
	    (t1->class == RANGE and t2->class == RANGE) or
	    (t1->class == SCAL and t2->class == CONST) or
	    (t1->class == CONST and t2->class == SCAL) or
	    (t1->type == t_char and t1->class == ARRAY and t2->class == ARRAY)
	) or
E 5
I 5
    b = (boolean) (
	(
	    t2 == t_int->type and
	    t1->class == RANGE and istypename(t1->type, "integer")
	) or (
	    t2 == t_char->type and
	    t1->class == RANGE and istypename(t1->type, "char")
	) or (
	    t2 == t_real->type and
	    t1->class == RANGE and istypename(t1->type, "real")
	) or (
	    t2 == t_boolean->type and
	    t1->class == RANGE and istypename(t1->type, "boolean")
	)
    );
    return b;
}

private boolean rangematch (t1, t2)
register Symbol t1, t2;
{
    boolean b;
    register Symbol rt1, rt2;

    if (t1->class == RANGE and t2->class == RANGE) {
	rt1 = rtype(t1->type);
	rt2 = rtype(t2->type);
	b = (boolean) (rt1->type == rt2->type);
    } else {
	b = false;
    }
    return b;
}

private boolean nilMatch (t1, t2)
register Symbol t1, t2;
{
    boolean b;

    b = (boolean) (
E 5
	(t1 == t_nil and t2->class == PTR) or
	(t1->class == PTR and t2 == t_nil)
    );
    return b;
}

D 5
public pascal_printdecl(s)
E 5
I 5
private boolean enumMatch (t1, t2)
register Symbol t1, t2;
{
    boolean b;

    b = (boolean) (
	(t1->class == SCAL and t2->class == CONST and t2->type == t1) or
	(t1->class == CONST and t2->class == SCAL and t1->type == t2)
    );
    return b;
}

private boolean isConstString (t)
register Symbol t;
{
    boolean b;

    b = (boolean) (
	t->language == primlang and t->class == ARRAY and t->type == t_char
    );
    return b;
}

private boolean stringArrayMatch (t1, t2)
register Symbol t1, t2;
{
    boolean b;

    b = (boolean) (
	(
	    isConstString(t1) and
	    t2->class == ARRAY and compatible(t2->type, t_char->type)
	) or (
	    isConstString(t2) and
	    t1->class == ARRAY and compatible(t1->type, t_char->type)
	)
    );
    return b;
}

public boolean pascal_typematch (type1, type2)
Symbol type1, type2;
{
    boolean b;
    Symbol t1, t2, tmp;

    t1 = rtype(type1);
    t2 = rtype(type2);
    if (t1 == t2) {
	b = true;
    } else {
	if (t1 == t_char->type or t1 == t_int->type or
	    t1 == t_real->type or t1 == t_boolean->type
	) {
	    tmp = t1;
	    t1 = t2;
	    t2 = tmp;
	}
	b = (Boolean) (
	    builtinmatch(t1, t2) or rangematch(t1, t2) or
	    nilMatch(t1, t2) or enumMatch(t1, t2) or
	    stringArrayMatch(t1, t2)
	);
    }
    return b;
}

/*
 * Indent n spaces.
 */

private indent (n)
int n;
{
    if (n > 0) {
	printf("%*c", n, ' ');
    }
}

public pascal_printdecl (s)
E 5
Symbol s;
{
    register Symbol t;
    Boolean semicolon;

    semicolon = true;
I 5
    if (s->class == TYPEREF) {
	resolveRef(t);
    }
E 5
    switch (s->class) {
	case CONST:
	    if (s->type->class == SCAL) {
D 5
		printf("(enumeration constant, ord %ld)",
		    s->symvalue.iconval);
E 5
I 5
		semicolon = false;
		printf("enum constant, ord ");
		eval(s->symvalue.constval);
		pascal_printval(s);
E 5
	    } else {
		printf("const %s = ", symname(s));
D 5
		printval(s);
E 5
I 5
		eval(s->symvalue.constval);
		pascal_printval(s);
E 5
	    }
	    break;

	case TYPE:
	    printf("type %s = ", symname(s));
D 5
	    printtype(s, s->type);
E 5
I 5
	    printtype(s, s->type, 0);
E 5
	    break;

I 5
	case TYPEREF:
	    printf("type %s", symname(s));
	    break;

E 5
	case VAR:
	    if (isparam(s)) {
		printf("(parameter) %s : ", symname(s));
	    } else {
		printf("var %s : ", symname(s));
	    }
D 5
	    printtype(s, s->type);
E 5
I 5
	    printtype(s, s->type, 0);
E 5
	    break;

	case REF:
	    printf("(var parameter) %s : ", symname(s));
D 5
	    printtype(s, s->type);
E 5
I 5
	    printtype(s, s->type, 0);
E 5
	    break;

	case RANGE:
	case ARRAY:
	case RECORD:
	case VARNT:
	case PTR:
D 5
	    printtype(s, s);
E 5
I 5
	case FILET:
	    printtype(s, s, 0);
E 5
	    semicolon = false;
	    break;

	case FVAR:
	    printf("(function variable) %s : ", symname(s));
D 5
	    printtype(s, s->type);
E 5
I 5
	    printtype(s, s->type, 0);
E 5
	    break;

	case FIELD:
	    printf("(field) %s : ", symname(s));
D 5
	    printtype(s, s->type);
E 5
I 5
	    printtype(s, s->type, 0);
E 5
	    break;

	case PROC:
	    printf("procedure %s", symname(s));
	    listparams(s);
	    break;

	case PROG:
	    printf("program %s", symname(s));
D 5
	    t = s->chain;
	    if (t != nil) {
		printf("(%s", symname(t));
		for (t = t->chain; t != nil; t = t->chain) {
		    printf(", %s", symname(t));
		}
		printf(")");
	    }
E 5
I 5
	    listparams(s);
E 5
	    break;

	case FUNC:
	    printf("function %s", symname(s));
	    listparams(s);
	    printf(" : ");
D 5
	    printtype(s, s->type);
E 5
I 5
	    printtype(s, s->type, 0);
E 5
	    break;

I 5
	case MODULE:
	    printf("module %s", symname(s));
	    break;

	  /*
	   * the parameter list of the following should be printed
	   * eventually
	   */
	case  FPROC:
	    printf("procedure %s()", symname(s));
	    break;
	
	case FFUNC:
	    printf("function %s()", symname(s));
	    break;

E 5
	default:
D 5
	    error("class %s in printdecl", classname(s));
E 5
I 5
	    printf("%s : (class %s)", symname(s), classname(s));
	    break;
E 5
    }
    if (semicolon) {
	putchar(';');
    }
    putchar('\n');
}

/*
 * Recursive whiz-bang procedure to print the type portion
D 5
 * of a declaration.  Doesn't work quite right for variant records.
E 5
I 5
 * of a declaration.
E 5
 *
 * The symbol associated with the type is passed to allow
 * searching for type names without getting "type blah = blah".
 */

D 5
private printtype(s, t)
E 5
I 5
private printtype (s, t, n)
E 5
Symbol s;
Symbol t;
I 5
int n;
E 5
{
    register Symbol tmp;

I 5
    if (t->class == TYPEREF) {
	resolveRef(t);
    }
E 5
    switch (t->class) {
	case VAR:
	case CONST:
	case FUNC:
	case PROC:
	    panic("printtype: class %s", classname(t));
	    break;

	case ARRAY:
	    printf("array[");
	    tmp = t->chain;
	    if (tmp != nil) {
		for (;;) {
D 5
		    printtype(tmp, tmp);
E 5
I 5
		    printtype(tmp, tmp, n);
E 5
		    tmp = tmp->chain;
		    if (tmp == nil) {
			break;
		    }
		    printf(", ");
		}
	    }
	    printf("] of ");
D 5
	    printtype(t, t->type);
E 5
I 5
	    printtype(t, t->type, n);
E 5
	    break;

	case RECORD:
D 5
	    printf("record\n");
	    if (t->chain != nil) {
		printtype(t->chain, t->chain);
	    }
	    printf("end");
E 5
I 5
	    printRecordDecl(t, n);
E 5
	    break;

	case FIELD:
	    if (t->chain != nil) {
D 5
		printtype(t->chain, t->chain);
E 5
I 5
		printtype(t->chain, t->chain, n);
E 5
	    }
	    printf("\t%s : ", symname(t));
D 5
	    printtype(t, t->type);
E 5
I 5
	    printtype(t, t->type, n);
E 5
	    printf(";\n");
	    break;

D 5
	case RANGE: {
	    long r0, r1;

	    r0 = t->symvalue.rangev.lower;
	    r1 = t->symvalue.rangev.upper;
D 3
	    if (t == t_char) {
E 3
I 3
	    if (t == t_char or istypename(t,"char")) {
E 3
		if (r0 < 0x20 or r0 > 0x7e) {
		    printf("%ld..", r0);
		} else {
		    printf("'%c'..", (char) r0);
		}
		if (r1 < 0x20 or r1 > 0x7e) {
		    printf("\\%lo", r1);
		} else {
		    printf("'%c'", (char) r1);
		}
	    } else if (r0 > 0 and r1 == 0) {
		printf("%ld byte real", r0);
	    } else if (r0 >= 0) {
		printf("%lu..%lu", r0, r1);
	    } else {
		printf("%ld..%ld", r0, r1);
	    }
E 5
I 5
	case RANGE:
	    printRangeDecl(t);
E 5
	    break;
D 5
	}
E 5

	case PTR:
D 5
	    putchar('*');
	    printtype(t, t->type);
E 5
I 5
	    printf("^");
	    printtype(t, t->type, n);
E 5
	    break;

	case TYPE:
D 5
	    if (symname(t) != nil) {
		printf("%s", symname(t));
E 5
I 5
	    if (t->name != nil and ident(t->name)[0] != '\0') {
		printname(stdout, t);
E 5
	    } else {
D 5
		printtype(t, t->type);
E 5
I 5
		printtype(t, t->type, n);
E 5
	    }
	    break;

	case SCAL:
D 5
	    printf("(");
D 3
	    t = t->type->chain;
E 3
I 3
	    t = t->chain;
E 3
	    if (t != nil) {
		printf("%s", symname(t));
		t = t->chain;
		while (t != nil) {
		    printf(", %s", symname(t));
		    t = t->chain;
		}
	    } else {
		panic("empty enumeration");
	    }
	    printf(")");
E 5
I 5
	    printEnumDecl(t, n);
E 5
	    break;

I 5
	case SET:
	    printf("set of ");
	    printtype(t, t->type, n);
	    break;

	case FILET:
	    printf("file of ");
	    printtype(t, t->type, n);
	    break;

	case TYPEREF:
	    break;
	
	case FPROC:
	    printf("procedure");
	    break;
	    
	case FFUNC:
	    printf("function");
	    break;

E 5
	default:
	    printf("(class %d)", t->class);
	    break;
    }
}

/*
I 5
 * Print out a record declaration.
 */

private printRecordDecl (t, n)
Symbol t;
int n;
{
    register Symbol f;

    if (t->chain == nil) {
	printf("record end");
    } else {
	printf("record\n");
	for (f = t->chain; f != nil; f = f->chain) {
	    indent(n+4);
	    printf("%s : ", symname(f));
	    printtype(f->type, f->type, n+4);
	    printf(";\n");
	}
	indent(n);
	printf("end");
    }
}

/*
 * Print out the declaration of a range type.
 */

private printRangeDecl (t)
Symbol t;
{
    long r0, r1;

    r0 = t->symvalue.rangev.lower;
    r1 = t->symvalue.rangev.upper;
    if (t == t_char or istypename(t, "char")) {
	if (r0 < 0x20 or r0 > 0x7e) {
	    printf("%ld..", r0);
	} else {
	    printf("'%c'..", (char) r0);
	}
	if (r1 < 0x20 or r1 > 0x7e) {
	    printf("\\%lo", r1);
	} else {
	    printf("'%c'", (char) r1);
	}
    } else if (r0 > 0 and r1 == 0) {
	printf("%ld byte real", r0);
    } else if (r0 >= 0) {
	printf("%lu..%lu", r0, r1);
    } else {
	printf("%ld..%ld", r0, r1);
    }
}

/*
 * Print out an enumeration declaration.
 */

private printEnumDecl (e, n)
Symbol e;
int n;
{
    Symbol t;

    printf("(");
    t = e->chain;
    if (t != nil) {
	printf("%s", symname(t));
	t = t->chain;
	while (t != nil) {
	    printf(", %s", symname(t));
	    t = t->chain;
	}
    }
    printf(")");
}

/*
E 5
 * List the parameters of a procedure or function.
 * No attempt is made to combine like types.
 */

private listparams(s)
Symbol s;
{
    Symbol t;

    if (s->chain != nil) {
	putchar('(');
	for (t = s->chain; t != nil; t = t->chain) {
	    switch (t->class) {
		case REF:
		    printf("var ");
		    break;

D 5
		case FPROC:
		    printf("procedure ");
		    break;

		case FFUNC:
		    printf("function ");
		    break;

E 5
		case VAR:
		    break;

		default:
		    panic("unexpected class %d for parameter", t->class);
	    }
	    printf("%s : ", symname(t));
	    printtype(t, t->type);
	    if (t->chain != nil) {
		printf("; ");
	    }
	}
	putchar(')');
    }
}

/*
 * Print out the value on the top of the expression stack
 * in the format for the type of the given symbol.
 */

D 5
public pascal_printval(s)
E 5
I 5
public pascal_printval (s)
E 5
Symbol s;
{
I 5
    prval(s, size(s));
}

private prval (s, n)
Symbol s;
integer n;
{
E 5
    Symbol t;
    Address a;
D 5
    int len;
E 5
I 5
    integer len;
E 5
    double r;
I 5
    integer i;
E 5

I 5
    if (s->class == TYPEREF) {
	resolveRef(s);
    }
E 5
D 3
    if (s->class == REF) {
	s = s->type;
    }
E 3
    switch (s->class) {
I 3
	case CONST:
E 3
	case TYPE:
I 3
D 5
	case VAR:
E 5
	case REF:
I 5
	case VAR:
E 5
	case FVAR:
	case TAG:
I 5
	    prval(s->type, n);
	    break;

E 5
	case FIELD:
E 3
D 5
	    pascal_printval(s->type);
E 5
I 5
		prval(s->type, n);
E 5
	    break;

	case ARRAY:
	    t = rtype(s->type);
D 3
	    if (t==t_char or (t->class==RANGE and t->type==t_char)) {
E 3
I 3
D 5
	    if (t->class==RANGE and istypename(t->type,"char")) {
E 5
I 5
	    if (t == t_char->type or
		(t->class == RANGE and istypename(t->type, "char"))
	    ) {
E 5
E 3
		len = size(s);
		sp -= len;
		printf("'%.*s'", len, sp);
		break;
	    } else {
		printarray(s);
	    }
	    break;

	case RECORD:
	    printrecord(s);
	    break;

	case VARNT:
D 5
	    error("can't print out variant records");
E 5
I 5
	    printf("[variant]");
E 5
	    break;

D 5

E 5
	case RANGE:
D 5
	    if (s == t_boolean) {
		printf(((Boolean) popsmall(s)) == true ? "true" : "false");
D 3
	    } else if (s == t_char) {
E 3
I 3
	    } else if (s == t_char or istypename(s,"char")) {
E 3
		printf("'%c'", pop(char));
	    } else if (s->symvalue.rangev.upper == 0 and
			s->symvalue.rangev.lower > 0) {
		switch (s->symvalue.rangev.lower) {
		    case sizeof(float):
			prtreal(pop(float));
			break;
E 5
I 5
	    printrange(s, n);
	    break;
E 5

D 5
		    case sizeof(double):
			prtreal(pop(double));
			break;

		    default:
			panic("bad real size %d", s->symvalue.rangev.lower);
			break;
		}
	    } else if (s->symvalue.rangev.lower >= 0) {
		printf("%lu", popsmall(s));
E 5
I 5
	case FILET:
	    a = pop(Address);
	    if (a == 0) {
		printf("nil");
E 5
	    } else {
D 5
		printf("%ld", popsmall(s));
E 5
I 5
		printf("0x%x", a);
E 5
	    }
	    break;

D 5
	case FILET:
	case PTR: {
	    Address addr;

	    addr = pop(Address);
	    if (addr == 0) {
		printf("0, (nil)");
E 5
I 5
	case PTR:
	    a = pop(Address);
	    if (a == 0) {
		printf("nil");
E 5
	    } else {
D 5
		printf("0x%x, 0%o", addr, addr);
E 5
I 5
		printf("0x%x", a);
E 5
	    }
	    break;
D 5
	}
E 5

D 3
	case FIELD:
	    error("missing record specification");
	    break;
E 3
D 5

	case SCAL: {
	    int scalar;
	    Boolean found;

	    scalar = popsmall(s);
	    found = false;
	    for (t = s->chain; t != nil; t = t->chain) {
		if (t->symvalue.iconval == scalar) {
		    printf("%s", symname(t));
		    found = true;
		    break;
		}
E 5
I 5
	case SCAL:
	    i = 0;
	    popn(n, &i);
	    if (s->symvalue.iconval < 256) {
		i &= 0xff;
	    } else if (s->symvalue.iconval < 65536) {
		i &= 0xffff;
E 5
	    }
D 5
	    if (not found) {
		printf("(scalar = %d)", scalar);
	    }
E 5
I 5
	    printEnum(i, s);
E 5
	    break;
D 5
	}
E 5

	case FPROC:
	case FFUNC:
D 5
	{
	    Address a;

	    a = fparamaddr(pop(long));
E 5
I 5
	    a = pop(long);
E 5
	    t = whatblock(a);
	    if (t == nil) {
D 5
		printf("(proc %d)", a);
E 5
I 5
		printf("(proc 0x%x)", a);
E 5
	    } else {
		printf("%s", symname(t));
	    }
	    break;
D 5
	}
E 5

I 5
	case SET:
	    printSet(s);
	    break;

E 5
	default:
	    if (ord(s->class) < ord(BADUSE) or ord(s->class) > ord(TYPEREF)) {
		panic("printval: bad class %d", ord(s->class));
	    }
D 5
	    error("don't know how to print a %s", classname(s));
	    /* NOTREACHED */
E 5
I 5
	    printf("[%s]", classname(s));
	    break;
E 5
    }
I 3
}

/*
I 5
 * Print out the value of a scalar (non-enumeration) type.
 */

private printrange (s, n)
Symbol s;
integer n;
{
    double d;
    float f;
    integer i;

    if (s->symvalue.rangev.upper == 0 and s->symvalue.rangev.lower > 0) {
	if (n == sizeof(float)) {
	    popn(n, &f);
	    d = f;
	} else {
	    popn(n, &d);
	}
	prtreal(d);
    } else {
	i = 0;
	popn(n, &i);
	printRangeVal(i, s);
    }
}

/*
 * Print out a set.
 */

private printSet (s)
Symbol s;
{
    Symbol t;
    integer nbytes;

    nbytes = size(s);
    t = rtype(s->type);
    printf("[");
    sp -= nbytes;
    if (t->class == SCAL) {
	printSetOfEnum(t);
    } else if (t->class == RANGE) {
	printSetOfRange(t);
    } else {
	error("internal error: expected range or enumerated base type for set");
    }
    printf("]");
}

/*
 * Print out a set of an enumeration.
 */

private printSetOfEnum (t)
Symbol t;
{
    register Symbol e;
    register integer i, j, *p;
    boolean first;

    p = (int *) sp;
    i = *p;
    j = 0;
    e = t->chain;
    first = true;
    while (e != nil) {
	if ((i&1) == 1) {
	    if (first) {
		first = false;
		printf("%s", symname(e));
	    } else {
		printf(", %s", symname(e));
	    }
	}
	i >>= 1;
	++j;
	if (j >= sizeof(integer)*BITSPERBYTE) {
	    j = 0;
	    ++p;
	    i = *p;
	}
	e = e->chain;
    }
}

/*
 * Print out a set of a subrange type.
 */

private printSetOfRange (t)
Symbol t;
{
    register integer i, j, *p;
    long v;
    boolean first;

    p = (int *) sp;
    i = *p;
    j = 0;
    v = t->symvalue.rangev.lower;
    first = true;
    while (v <= t->symvalue.rangev.upper) {
	if ((i&1) == 1) {
	    if (first) {
		first = false;
		printf("%ld", v);
	    } else {
		printf(", %ld", v);
	    }
	}
	i >>= 1;
	++j;
	if (j >= sizeof(integer)*BITSPERBYTE) {
	    j = 0;
	    ++p;
	    i = *p;
	}
	++v;
    }
}

/*
E 5
 * Construct a node for subscripting.
 */

public Node pascal_buildaref (a, slist)
Node a, slist;
{
    register Symbol t;
    register Node p;
    Symbol etype, atype, eltype;
    Node esub, r;

D 5
    r = a;
E 5
    t = rtype(a->nodetype);
D 5
    eltype = t->type;
E 5
    if (t->class != ARRAY) {
	beginerrmsg();
	prtree(stderr, a);
	fprintf(stderr, " is not an array");
	enderrmsg();
    } else {
I 5
	r = a;
	eltype = t->type;
E 5
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
	    beginerrmsg();
	    if (p != nil) {
		fprintf(stderr, "too many subscripts for ");
	    } else {
		fprintf(stderr, "not enough subscripts for ");
	    }
	    prtree(stderr, a);
	    enderrmsg();
	}
    }
    return r;
}

/*
 * Evaluate a subscript index.
 */

D 5
public int pascal_evalaref (s, i)
E 5
I 5
public pascal_evalaref (s, base, i)
E 5
Symbol s;
I 5
Address base;
E 5
long i;
{
I 5
    Symbol t;
E 5
    long lb, ub;

D 5
    s = rtype(rtype(s)->chain);
    lb = s->symvalue.rangev.lower;
    ub = s->symvalue.rangev.upper;
E 5
I 5
    t = rtype(s);
    s = rtype(t->chain);
    findbounds(s, &lb, &ub);
E 5
    if (i < lb or i > ub) {
	error("subscript %d out of range [%d..%d]", i, lb, ub);
    }
D 5
    return (i - lb);
E 5
I 5
    push(long, base + (i - lb) * size(t->type));
E 5
}

/*
 * Initial Pascal type information.
 */

#define NTYPES 4

D 5
private Symbol inittype[NTYPES];
private integer count;
E 5
I 5
private Symbol inittype[NTYPES + 1];
E 5

D 5
private addType (s, lower, upper)
E 5
I 5
private addType (n, s, lower, upper)
integer n;
E 5
String s;
long lower, upper;
{
    register Symbol t;

D 5
    if (count > NTYPES) {
	panic("too many initial types");
E 5
I 5
    if (n > NTYPES) {
	panic("initial Pascal type number too large for '%s'", s);
E 5
    }
D 5
    t = maketype(s, lower, upper);
E 5
I 5
    t = insert(identname(s, true));
E 5
    t->language = pasc;
D 5
    inittype[count] = t;
    ++count;
E 5
I 5
    t->class = TYPE;
    t->type = newSymbol(nil, 0, RANGE, t, nil);
    t->type->symvalue.rangev.lower = lower;
    t->type->symvalue.rangev.upper = upper;
    t->type->language = pasc;
    inittype[n] = t;
E 5
}

private initTypes ()
{
D 5
    count = 1;
    addType("integer", 0x80000000L, 0x7fffffffL);
    addType("char", 0L, 255L);
    addType("boolean", 0L, 1L);
    addType("real", 4L, 0L);
E 5
I 5
    addType(1, "boolean", 0L, 1L);
    addType(2, "char", 0L, 255L);
    addType(3, "integer", 0x80000000L, 0x7fffffffL);
    addType(4, "real", 8L, 0L);
    initialized = true;
E 5
}

/*
 * Initialize typetable.
 */

public pascal_modinit (typetable)
Symbol typetable[];
{
    register integer i;

D 5
    for (i = 1; i < NTYPES; i++) {
E 5
I 5
    if (not initialized) {
	initTypes();
	initialized = true;
    }
    for (i = 1; i <= NTYPES; i++) {
E 5
	typetable[i] = inittype[i];
    }
}

public boolean pascal_hasmodules ()
{
    return false;
}

public boolean pascal_passaddr (param, exprtype)
Symbol param, exprtype;
{
    return false;
E 3
}
E 1
