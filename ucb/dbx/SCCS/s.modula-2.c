h04007
s 00052/00050/01156
d D 5.2 88/01/12 00:57:31 donn 4 3
c merge in latest Linton version
e
s 00007/00003/01199
d D 5.1 85/05/31 10:07:02 dist 3 2
c Add copyright
e
s 00430/00105/00772
d D 1.2 85/03/07 17:39:00 linton 2 1
c update to version 3.0
e
s 00877/00000/00000
d D 1.1 84/06/23 10:59:14 sam 1 0
c date and time created 84/06/23 10:59:14 by sam
e
u
U
t
T
I 2
D 3
/* Copyright (c) 1982 Regents of the University of California */
E 3
I 3
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 3

E 2
I 1
#ifndef lint
D 3
static	char sccsid[] = "%W% (Berkeley) %G%"; /* from 1.4 84/03/27 10:22:04 linton Exp */
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 3

/*
 * Modula-2 specific symbol routines.
 */

I 2
D 4
static char rcsid[] = "$Header: modula-2.c,v 1.6 84/12/26 10:40:33 linton Exp $";
E 4
I 4
static char rcsid[] = "$Header: modula-2.c,v 1.2 87/03/26 20:12:54 donn Exp $";
E 4

E 2
#include "defs.h"
#include "symbols.h"
#include "modula-2.h"
#include "languages.h"
#include "tree.h"
#include "eval.h"
#include "mappings.h"
#include "process.h"
#include "runtime.h"
#include "machine.h"

#ifndef public
#endif

private Language mod2;
private boolean initialized;

I 2

#define ischar(t) ( \
    (t) == t_char->type or \
    ((t)->class == RANGE and istypename((t)->type, "char")) \
)

E 2
/*
 * Initialize Modula-2 information.
 */

public modula2_init ()
{
    mod2 = language_define("modula-2", ".mod");
    language_setop(mod2, L_PRINTDECL, modula2_printdecl);
    language_setop(mod2, L_PRINTVAL, modula2_printval);
    language_setop(mod2, L_TYPEMATCH, modula2_typematch);
    language_setop(mod2, L_BUILDAREF, modula2_buildaref);
    language_setop(mod2, L_EVALAREF, modula2_evalaref);
    language_setop(mod2, L_MODINIT, modula2_modinit);
    language_setop(mod2, L_HASMODULES, modula2_hasmodules);
    language_setop(mod2, L_PASSADDR, modula2_passaddr);
    initialized = false;
}

/*
 * Typematch tests if two types are compatible.  The issue
 * is a bit complicated, so several subfunctions are used for
 * various kinds of compatibility.
 */

I 2
private boolean builtinmatch (t1, t2)
register Symbol t1, t2;
{
    boolean b;

    b = (boolean) (
	(
	    t2 == t_int->type and t1->class == RANGE and
	    (
		istypename(t1->type, "integer") or
		istypename(t1->type, "cardinal")
	    )
	) or (
	    t2 == t_char->type and
	    t1->class == RANGE and istypename(t1->type, "char")
	) or (
	    t2 == t_real->type and
	    t1->class == RANGE and (
		istypename(t1->type, "real") or
		istypename(t1->type, "longreal")
	    )
	) or (
	    t2 == t_boolean->type and
	    t1->class == RANGE and istypename(t1->type, "boolean")
	)
    );
    return b;
}

D 4
private boolean rangematch (t1, t2)
register Symbol t1, t2;
{
    boolean b;
    register Symbol rt1, rt2;

    if (t1->class == RANGE and t2->class == RANGE) {
	b = (boolean) (
	    t1->symvalue.rangev.lower == t2->symvalue.rangev.lower and
	    t1->symvalue.rangev.upper == t2->symvalue.rangev.upper
	);
    } else {
	b = false;
    }
    return b;
}

E 4
E 2
private boolean nilMatch (t1, t2)
register Symbol t1, t2;
{
    boolean b;

    b = (boolean) (
	(t1 == t_nil and t2->class == PTR) or
	(t1->class == PTR and t2 == t_nil)
    );
    return b;
}

private boolean enumMatch (t1, t2)
register Symbol t1, t2;
{
    boolean b;

    b = (boolean) (
D 2
	t1->type == t2->type and (
	    (t1->class == t2->class) or
	    (t1->class == SCAL and t2->class == CONST) or
	    (t1->class == CONST and t2->class == SCAL)
	)
E 2
I 2
	(t1->class == SCAL and t2->class == CONST and t2->type == t1) or
	(t1->class == CONST and t2->class == SCAL and t1->type == t2)
E 2
    );
    return b;
}

private boolean openArrayMatch (t1, t2)
register Symbol t1, t2;
{
    boolean b;

    b = (boolean) (
	(
D 2
	    t1->class == ARRAY and t1->chain == t_open and
E 2
I 2
D 4
	    t1->class == DYNARRAY and t1->symvalue.ndims == 1 and
E 4
I 4
	    t1->class == OPENARRAY and t1->symvalue.ndims == 1 and
E 4
E 2
	    t2->class == ARRAY and
	    compatible(rtype(t2->chain)->type, t_int) and
	    compatible(t1->type, t2->type)
	) or (
D 2
	    t2->class == ARRAY and t2->chain == t_open and
E 2
I 2
D 4
	    t2->class == DYNARRAY and t2->symvalue.ndims == 1 and
E 4
I 4
	    t2->class == OPENARRAY and t2->symvalue.ndims == 1 and
E 4
E 2
	    t1->class == ARRAY and
	    compatible(rtype(t1->chain)->type, t_int) and
	    compatible(t1->type, t2->type)
	)
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

public boolean modula2_typematch (type1, type2)
Symbol type1, type2;
{
D 2
    Boolean b;
E 2
I 2
    boolean b;
E 2
    Symbol t1, t2, tmp;

    t1 = rtype(type1);
    t2 = rtype(type2);
    if (t1 == t2) {
	b = true;
    } else {
D 2
	if (t1 == t_char->type or t1 == t_int->type or t1 == t_real->type) {
E 2
I 2
	if (t1 == t_char->type or t1 == t_int->type or
	    t1 == t_real->type or t1 == t_boolean->type
	) {
E 2
	    tmp = t1;
	    t1 = t2;
	    t2 = tmp;
	}
	b = (Boolean) (
D 2
	    (
		t2 == t_int->type and
		t1->class == RANGE and (
		    istypename(t1->type, "integer") or
		    istypename(t1->type, "cardinal")
		)
	    ) or (
		t2 == t_char->type and
		t1->class == RANGE and istypename(t1->type, "char")
	    ) or (
		t2 == t_real->type and
		t1->class == RANGE and (
		    istypename(t1->type, "real") or
		    istypename(t1->type, "longreal")
		)
	    ) or (
		nilMatch(t1, t2)
	    ) or (
		enumMatch(t1, t2)
	    ) or (
		openArrayMatch(t1, t2)
	    ) or (
		stringArrayMatch(t1, t2)
	    )
E 2
I 2
D 4
	    builtinmatch(t1, t2) or rangematch(t1, t2) or
E 4
I 4
	    builtinmatch(t1, t2) or
E 4
	    nilMatch(t1, t2) or enumMatch(t1, t2) or
	    openArrayMatch(t1, t2) or stringArrayMatch(t1, t2)
E 2
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

public modula2_printdecl (s)
Symbol s;
{
    register Symbol t;
    Boolean semicolon;

    semicolon = true;
    if (s->class == TYPEREF) {
	resolveRef(t);
    }
    switch (s->class) {
	case CONST:
	    if (s->type->class == SCAL) {
D 2
		printf("(enumeration constant, ord %ld)",
		    s->symvalue.iconval);
E 2
I 2
		semicolon = false;
		printf("enumeration constant with value ");
		eval(s->symvalue.constval);
		modula2_printval(s);
E 2
	    } else {
		printf("const %s = ", symname(s));
I 2
		eval(s->symvalue.constval);
E 2
		modula2_printval(s);
	    }
	    break;

	case TYPE:
	    printf("type %s = ", symname(s));
	    printtype(s, s->type, 0);
	    break;

	case TYPEREF:
	    printf("type %s", symname(s));
	    break;

	case VAR:
	    if (isparam(s)) {
		printf("(parameter) %s : ", symname(s));
	    } else {
		printf("var %s : ", symname(s));
	    }
	    printtype(s, s->type, 0);
	    break;

	case REF:
	    printf("(var parameter) %s : ", symname(s));
	    printtype(s, s->type, 0);
	    break;

	case RANGE:
	case ARRAY:
I 4
	case OPENARRAY:
E 4
I 2
	case DYNARRAY:
	case SUBARRAY:
E 2
	case RECORD:
	case VARNT:
	case PTR:
	    printtype(s, s, 0);
	    semicolon = false;
	    break;

	case FVAR:
	    printf("(function variable) %s : ", symname(s));
	    printtype(s, s->type, 0);
	    break;

	case FIELD:
	    printf("(field) %s : ", symname(s));
	    printtype(s, s->type, 0);
	    break;

	case PROC:
	    printf("procedure %s", symname(s));
	    listparams(s);
	    break;

	case PROG:
	    printf("program %s", symname(s));
	    listparams(s);
	    break;

	case FUNC:
D 2
	    printf("function %s", symname(s));
E 2
I 2
	    printf("procedure %s", symname(s));
E 2
	    listparams(s);
	    printf(" : ");
	    printtype(s, s->type, 0);
	    break;

	case MODULE:
	    printf("module %s", symname(s));
	    break;

	default:
D 2
	    printf("%s : (class %s)", symname(s), classname(s));
E 2
I 2
	    printf("[%s]", classname(s));
E 2
	    break;
    }
    if (semicolon) {
	putchar(';');
    }
    putchar('\n');
}

/*
 * Recursive whiz-bang procedure to print the type portion
 * of a declaration.
 *
 * The symbol associated with the type is passed to allow
 * searching for type names without getting "type blah = blah".
 */

private printtype (s, t, n)
Symbol s;
Symbol t;
int n;
{
D 2
    register Symbol tmp;
E 2
I 2
    Symbol tmp;
    int i;
E 2

    if (t->class == TYPEREF) {
	resolveRef(t);
    }
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
		    printtype(tmp, tmp, n);
		    tmp = tmp->chain;
		    if (tmp == nil) {
			break;
		    }
		    printf(", ");
		}
	    }
	    printf("] of ");
	    printtype(t, t->type, n);
	    break;

I 4
	case OPENARRAY:
	    printf("array of ");
	    for (i = 1; i < t->symvalue.ndims; i++) {
		printf("array of ");
	    }
	    printtype(t, t->type, n);
	    break;

E 4
I 2
	case DYNARRAY:
	    printf("dynarray of ");
	    for (i = 1; i < t->symvalue.ndims; i++) {
		printf("array of ");
	    }
	    printtype(t, t->type, n);
	    break;

	case SUBARRAY:
	    printf("subarray of ");
	    for (i = 1; i < t->symvalue.ndims; i++) {
		printf("array of ");
	    }
	    printtype(t, t->type, n);
	    break;

E 2
	case RECORD:
	    printRecordDecl(t, n);
	    break;

	case FIELD:
	    if (t->chain != nil) {
		printtype(t->chain, t->chain, n);
	    }
	    printf("\t%s : ", symname(t));
	    printtype(t, t->type, n);
	    printf(";\n");
	    break;

	case RANGE:
	    printRangeDecl(t);
	    break;

	case PTR:
	    printf("pointer to ");
	    printtype(t, t->type, n);
	    break;

	case TYPE:
	    if (t->name != nil and ident(t->name)[0] != '\0') {
		printname(stdout, t);
	    } else {
		printtype(t, t->type, n);
	    }
	    break;

	case SCAL:
	    printEnumDecl(t, n);
	    break;

	case SET:
	    printf("set of ");
	    printtype(t, t->type, n);
	    break;

	case TYPEREF:
	    break;

I 2
	case FPROC:
	case FFUNC:
	    printf("procedure");
	    break;

E 2
	default:
D 2
	    printf("(class %d)", t->class);
E 2
I 2
	    printf("[%s]", classname(t));
E 2
	    break;
    }
}

/*
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
D 2
    if (t == t_char or istypename(t, "char")) {
E 2
I 2
    if (ischar(t)) {
E 2
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
 * List the parameters of a procedure or function.
 * No attempt is made to combine like types.
 */

private listparams (s)
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

		case FPROC:
		case FFUNC:
		    printf("procedure ");
		    break;

		case VAR:
		    break;

		default:
		    panic("unexpected class %d for parameter", t->class);
	    }
	    printf("%s", symname(t));
	    if (s->class == PROG) {
		printf(", ");
	    } else {
		printf(" : ");
		printtype(t, t->type, 0);
		if (t->chain != nil) {
		    printf("; ");
		}
	    }
	}
	putchar(')');
    }
}

/*
I 2
 * Test if a pointer type should be treated as a null-terminated string.
 * The type given is the type that is pointed to.
 */

private boolean isCstring (type)
Symbol type;
{
    boolean b;
    register Symbol a, t;

    a = rtype(type);
    if (a->class == ARRAY) {
	t = rtype(a->chain);
	b = (boolean) (
	    t->class == RANGE and istypename(a->type, "char") and
	    (t->symvalue.rangev.upper - t->symvalue.rangev.lower + 1) <= 0
	);
    } else {
	b = false;
    }
    return b;
}

/*
E 2
 * Modula 2 interface to printval.
 */

public modula2_printval (s)
Symbol s;
{
    prval(s, size(s));
}

/*
 * Print out the value on the top of the expression stack
 * in the format for the type of the given symbol, assuming
 * the size of the object is n bytes.
 */

private prval (s, n)
Symbol s;
integer n;
{
    Symbol t;
    Address a;
    integer len;
    double r;
D 2
    integer scalar;
    boolean found;
E 2
I 2
    integer i;
E 2

    if (s->class == TYPEREF) {
	resolveRef(s);
    }
    switch (s->class) {
	case CONST:
	case TYPE:
D 2
	case VAR:
E 2
	case REF:
I 2
	case VAR:
E 2
	case FVAR:
	case TAG:
D 2
	case FIELD:
E 2
	    prval(s->type, n);
	    break;

I 2
	case FIELD:
	    if (isbitfield(s)) {
D 4
		i = 0;
		popn(size(s), &i);
		i >>= (s->symvalue.field.offset mod BITSPERBYTE);
		i &= ((1 << s->symvalue.field.length) - 1);
E 4
I 4
		i = extractField(s);
E 4
		t = rtype(s->type);
		if (t->class == SCAL) {
		    printEnum(i, t);
		} else {
		    printRangeVal(i, t);
		}
	    } else {
		prval(s->type, n);
	    }
	    break;

E 2
	case ARRAY:
	    t = rtype(s->type);
D 2
	    if (t->class == RANGE and istypename(t->type, "char")) {
E 2
I 2
	    if (ischar(t)) {
E 2
		len = size(s);
		sp -= len;
D 2
		printf("'%.*s'", len, sp);
E 2
I 2
		printf("\"%.*s\"", len, sp);
E 2
		break;
	    } else {
		printarray(s);
	    }
	    break;

I 4
	case OPENARRAY:
E 4
I 2
	case DYNARRAY:
	    printDynarray(s);
	    break;

	case SUBARRAY:
	    printSubarray(s);
	    break;

E 2
	case RECORD:
	    printrecord(s);
	    break;

	case VARNT:
D 2
	    printf("can't print out variant records");
E 2
I 2
	    printf("[variant]");
E 2
	    break;

	case RANGE:
	    printrange(s, n);
	    break;

I 2
	/*
	 * Unresolved opaque type.
	 * Probably a pointer.
	 */
	case TYPEREF:
	    a = pop(Address);
	    printf("@%x", a);
	    break;

E 2
	case FILET:
I 2
	    a = pop(Address);
	    if (a == 0) {
		printf("nil");
	    } else {
		printf("0x%x", a);
	    }
	    break;

E 2
	case PTR:
	    a = pop(Address);
	    if (a == 0) {
		printf("nil");
I 2
	    } else if (isCstring(s->type)) {
		printString(a, true);
E 2
	    } else {
		printf("0x%x", a);
	    }
	    break;

	case SCAL:
D 2
	    popn(n, &scalar);
	    found = false;
	    for (t = s->chain; t != nil; t = t->chain) {
		if (t->symvalue.iconval == scalar) {
		    printf("%s", symname(t));
		    found = true;
		    break;
		}
	    }
	    if (not found) {
		printf("(scalar = %d)", scalar);
	    }
E 2
I 2
	    i = 0;
	    popn(n, &i);
	    printEnum(i, s);
E 2
	    break;

	case FPROC:
	case FFUNC:
	    a = pop(long);
	    t = whatblock(a);
	    if (t == nil) {
D 2
		printf("(proc 0x%x)", a);
E 2
I 2
		printf("0x%x", a);
E 2
	    } else {
D 2
		printf("%s", symname(t));
E 2
I 2
		printname(stdout, t);
E 2
	    }
	    break;

	case SET:
	    printSet(s);
	    break;

	default:
	    if (ord(s->class) < ord(BADUSE) or ord(s->class) > ord(TYPEREF)) {
		panic("printval: bad class %d", ord(s->class));
	    }
	    printf("[%s]", classname(s));
	    break;
    }
}

/*
I 2
 * Print out a dynamic array.
 */

private Address printDynSlice();

private printDynarray (t)
Symbol t;
{
    Address base;
    integer n;
    Stack *savesp, *newsp;
    Symbol eltype;

    savesp = sp;
    sp -= (t->symvalue.ndims * sizeof(Word));
    base = pop(Address);
    newsp = sp;
    sp = savesp;
    eltype = rtype(t->type);
    if (t->symvalue.ndims == 0) {
	if (ischar(eltype)) {
	    printString(base, true);
	} else {
	    printf("[dynarray @nocount]");
	}
    } else {
	n = ((long *) sp)[-(t->symvalue.ndims)];
	base = printDynSlice(base, n, t->symvalue.ndims, eltype, size(eltype));
    }
    sp = newsp;
}

/*
 * Print out one dimension of a multi-dimension dynamic array.
 *
 * Return the address of the element that follows the printed elements.
 */

private Address printDynSlice (base, count, ndims, eltype, elsize)
Address base;
integer count, ndims;
Symbol eltype;
integer elsize;
{
    Address b;
    integer i, n;
    char *slice;
    Stack *savesp;

    b = base;
    if (ndims > 1) {
	n = ((long *) sp)[-ndims + 1];
    }
    if (ndims == 1 and ischar(eltype)) {
	slice = newarr(char, count);
	dread(slice, b, count);
	printf("\"%.*s\"", count, slice);
	dispose(slice);
	b += count;
    } else {
	printf("(");
	for (i = 0; i < count; i++) {
	    if (i != 0) {
		printf(", ");
	    }
	    if (ndims == 1) {
		slice = newarr(char, elsize);
		dread(slice, b, elsize);
		savesp = sp;
		sp = slice + elsize;
		printval(eltype);
		sp = savesp;
		dispose(slice);
		b += elsize;
	    } else {
		b = printDynSlice(b, n, ndims - 1, eltype, elsize);
	    }
	}
	printf(")");
    }
    return b;
}

private printSubarray (t)
Symbol t;
{
    printf("[subarray]");
}

/*
E 2
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
D 2
	if (s == t_boolean) {
	    printf(((Boolean) i) == true ? "true" : "false");
	} else if (s == t_char or istypename(s->type, "char")) {
	    printf("'%c'", i);
	} else if (s->symvalue.rangev.lower >= 0) {
	    printf("%lu", i);
	} else {
	    printf("%ld", i);
	}
E 2
I 2
	printRangeVal(i, s);
E 2
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
    printf("{");
    sp -= nbytes;
    if (t->class == SCAL) {
	printSetOfEnum(t);
    } else if (t->class == RANGE) {
	printSetOfRange(t);
    } else {
	panic("expected range or enumerated base type for set");
    }
    printf("}");
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
I 2
 * Construct a node for subscripting a dynamic or subarray.
 * The list of indices is left for processing in evalaref,
 * unlike normal subscripting in which the list is expanded
 * across individual INDEX nodes.
 */

private Node dynref (a, t, slist)
Node a;
Symbol t;
Node slist;
{
    Node p, r;
    integer n;

    p = slist;
    n = 0;
    while (p != nil) {
	if (not compatible(p->value.arg[0]->nodetype, t_int)) {
	    suberror("subscript \"", p->value.arg[0], "\" is the wrong type");
	}
	++n;
	p = p->value.arg[1];
    }
    if (n > t->symvalue.ndims and (t->symvalue.ndims != 0 or n != 1)) {
	suberror("too many subscripts for ", a, nil);
    } else if (n < t->symvalue.ndims) {
	suberror("not enough subscripts for ", a, nil);
    }
    r = build(O_INDEX, a, slist);
    r->nodetype = rtype(t->type);
    return r;
}

/*
E 2
 * Construct a node for subscripting.
 */

public Node modula2_buildaref (a, slist)
Node a, slist;
{
    register Symbol t;
    register Node p;
D 2
    Symbol etype, atype, eltype;
E 2
I 2
    Symbol eltype;
E 2
    Node esub, r;
I 2
    integer n;
E 2

D 2
    r = a;
E 2
    t = rtype(a->nodetype);
D 2
    eltype = t->type;
    if (t->class != ARRAY) {
	beginerrmsg();
	prtree(stderr, a);
	fprintf(stderr, " is not an array");
	enderrmsg();
    } else {
E 2
I 2
D 4
    if (t->class == DYNARRAY or t->class == SUBARRAY) {
	r = dynref(a, t, slist);
    } else if (t->class == ARRAY) {
	r = a;
	eltype = rtype(t->type);
E 2
	p = slist;
	t = t->chain;
D 2
	for (; p != nil and t != nil; p = p->value.arg[1], t = t->chain) {
E 2
I 2
	while (p != nil and t != nil) {
E 2
	    esub = p->value.arg[0];
D 2
	    etype = rtype(esub->nodetype);
	    atype = rtype(t);
	    if (not compatible(atype, etype)) {
		beginerrmsg();
		fprintf(stderr, "subscript ");
		prtree(stderr, esub);
		fprintf(stderr, " is the wrong type");
		enderrmsg();
E 2
I 2
	    if (not compatible(rtype(t), rtype(esub->nodetype))) {
		suberror("subscript \"", esub, "\" is the wrong type");
E 2
	    }
	    r = build(O_INDEX, r, esub);
	    r->nodetype = eltype;
I 2
	    p = p->value.arg[1];
E 4
I 4
    switch (t->class) {
	case OPENARRAY:
	case DYNARRAY:
	case SUBARRAY:
	    r = dynref(a, t, slist);
	    break;

	case ARRAY:
	    r = a;
	    eltype = rtype(t->type);
	    p = slist;
E 4
	    t = t->chain;
E 2
D 4
	}
D 2
	if (p != nil or t != nil) {
	    beginerrmsg();
	    if (p != nil) {
		fprintf(stderr, "too many subscripts for ");
	    } else {
		fprintf(stderr, "not enough subscripts for ");
	    }
	    prtree(stderr, a);
	    enderrmsg();
E 2
I 2
	if (p != nil) {
	    suberror("too many subscripts for ", a, nil);
	} else if (t != nil) {
	    suberror("not enough subscripts for ", a, nil);
E 2
	}
I 2
    } else {
	suberror("\"", a, "\" is not an array");
E 4
I 4
	    while (p != nil and t != nil) {
		esub = p->value.arg[0];
		if (not compatible(rtype(t), rtype(esub->nodetype))) {
		    suberror("subscript \"", esub, "\" is the wrong type");
		}
		r = build(O_INDEX, r, esub);
		r->nodetype = eltype;
		p = p->value.arg[1];
		t = t->chain;
	    }
	    if (p != nil) {
		suberror("too many subscripts for ", a, nil);
	    } else if (t != nil) {
		suberror("not enough subscripts for ", a, nil);
	    }
	    break;

	default:
	    suberror("\"", a, "\" is not an array");
	    break;
E 4
E 2
    }
    return r;
}

/*
I 2
 * Subscript usage error reporting.
 */

private suberror (s1, e1, s2)
String s1, s2;
Node e1;
{
    beginerrmsg();
    if (s1 != nil) {
	fprintf(stderr, s1);
    }
    if (e1 != nil) {
	prtree(stderr, e1);
    }
    if (s2 != nil) {
	fprintf(stderr, s2);
    }
    enderrmsg();
}

/*
 * Check that a subscript value is in the appropriate range.
 */

private subchk (value, lower, upper)
long value, lower, upper;
{
    if (value < lower or value > upper) {
	error("subscript value %d out of range [%d..%d]", value, lower, upper);
    }
}

/*
 * Compute the offset for subscripting a dynamic array.
 */

private getdynoff (ndims, sub)
integer ndims;
long *sub;
{
    long k, off, *count;

    count = (long *) sp;
    off = 0;
    for (k = 0; k < ndims - 1; k++) {
	subchk(sub[k], 0, count[k] - 1);
	off += (sub[k] * count[k+1]);
    }
    subchk(sub[ndims - 1], 0, count[ndims - 1] - 1);
    return off + sub[ndims - 1];
}

/*
 * Compute the offset associated with a subarray.
 */

private getsuboff (ndims, sub)
integer ndims;
long *sub;
{
    long k, off;
    struct subarrayinfo {
	long count;
	long mult;
    } *info;

    info = (struct subarrayinfo *) sp;
    off = 0;
    for (k = 0; k < ndims; k++) {
	subchk(sub[k], 0, info[k].count - 1);
	off += sub[k] * info[k].mult;
    }
    return off;
}

/*
E 2
 * Evaluate a subscript index.
 */

D 2
public int modula2_evalaref (s, i)
E 2
I 2
public modula2_evalaref (s, base, i)
E 2
Symbol s;
I 2
Address base;
E 2
long i;
{
D 2
    long lb, ub;
E 2
I 2
    Symbol t;
    long lb, ub, off;
    long *sub;
    Address b;
E 2

D 2
    chkOpenArray(s);
    s = rtype(rtype(s)->chain);
    findbounds(s, &lb, &ub);
    if (i < lb or i > ub) {
	error("subscript %d out of range [%d..%d]", i, lb, ub);
E 2
I 2
    t = rtype(s);
    if (t->class == ARRAY) {
	findbounds(rtype(t->chain), &lb, &ub);
	if (i < lb or i > ub) {
	    error("subscript %d out of range [%d..%d]", i, lb, ub);
	}
	push(long, base + (i - lb) * size(t->type));
D 4
    } else if (t->class == DYNARRAY and t->symvalue.ndims == 0) {
E 4
I 4
    } else if ((t->class == OPENARRAY or t->class == DYNARRAY) and
	t->symvalue.ndims == 0
    ) {
E 4
	push(long, base + i * size(t->type));
D 4
    } else if (t->class == DYNARRAY or t->class == SUBARRAY) {
E 4
I 4
    } else if (t->class == OPENARRAY or t->class == DYNARRAY or
	t->class == SUBARRAY
    ) {
E 4
	push(long, i);
	sub = (long *) (sp - (t->symvalue.ndims * sizeof(long)));
	rpush(base, size(t));
	sp -= (t->symvalue.ndims * sizeof(long));
	b = pop(Address);
	sp += sizeof(Address);
	if (t->class == SUBARRAY) {
	    off = getsuboff(t->symvalue.ndims, sub);
	} else {
	    off = getdynoff(t->symvalue.ndims, sub);
	}
	sp = (Stack *) sub;
	push(long, b + off * size(t->type));
    } else {
	error("[internal error: expected array in evalaref]");
E 2
    }
D 2
    return (i - lb);
E 2
}

/*
 * Initial Modula-2 type information.
 */

#define NTYPES 12

private Symbol inittype[NTYPES + 1];

private addType (n, s, lower, upper)
integer n;
String s;
long lower, upper;
{
    register Symbol t;

    if (n > NTYPES) {
	panic("initial Modula-2 type number too large for '%s'", s);
    }
    t = insert(identname(s, true));
    t->language = mod2;
    t->class = TYPE;
    t->type = newSymbol(nil, 0, RANGE, t, nil);
    t->type->symvalue.rangev.lower = lower;
    t->type->symvalue.rangev.upper = upper;
    t->type->language = mod2;
    inittype[n] = t;
}

private initModTypes ()
{
    addType(1, "integer", 0x80000000L, 0x7fffffffL);
    addType(2, "char", 0L, 255L);
    addType(3, "boolean", 0L, 1L);
    addType(4, "unsigned", 0L, 0xffffffffL);
    addType(5, "real", 4L, 0L);
    addType(6, "longreal", 8L, 0L);
    addType(7, "word", 0L, 0xffffffffL);
    addType(8, "byte", 0L, 255L);
    addType(9, "address", 0L, 0xffffffffL);
    addType(10, "file", 0L, 0xffffffffL);
    addType(11, "process", 0L, 0xffffffffL);
    addType(12, "cardinal", 0L, 0x7fffffffL);
}

/*
 * Initialize typetable.
 */

public modula2_modinit (typetable)
Symbol typetable[];
{
    register integer i;

    if (not initialized) {
	initModTypes();
I 2
	initialized = true;
E 2
    }
    for (i = 1; i <= NTYPES; i++) {
	typetable[i] = inittype[i];
    }
}

public boolean modula2_hasmodules ()
{
    return true;
}

public boolean modula2_passaddr (param, exprtype)
Symbol param, exprtype;
{
    return false;
}
E 1
