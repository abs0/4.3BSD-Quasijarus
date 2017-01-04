h04216
s 00003/00003/00721
d D 5.8 88/05/11 02:03:53 donn 19 18
c The C stab code only distinguishes 'char' from 'int' range types; char has
c a 'char' range, everything else has an 'int' range, including floating
c types.  This seems completely bogus, but it's easy enough to adapt the
c c_typematch() routine to handle this 'feature'.  This cures problems where
c 'float' appeared to have 'int' type in division operations.
e
s 00016/00007/00708
d D 5.7 88/01/11 23:55:15 donn 18 17
c merge in latest Linton version
e
s 00001/00001/00714
d D 5.6 87/07/02 21:21:24 sam 17 16
c correct bostic correction
e
s 00001/00001/00714
d D 5.5 87/04/06 12:01:48 bostic 16 15
c printf format/argument mismatch
e
s 00000/00000/00715
d D 5.4 86/10/14 21:16:34 mckusick 15 13
i 14
c merge of 5.1.1.1
e
s 00001/00002/00706
d D 5.1.1.1 86/10/14 21:14:27 mckusick 14 11
c update from CCI release
e
s 00004/00002/00712
d D 5.3 86/09/01 12:54:49 sam 13 12
c for compatibility must not print trailing nulls on c char arrays
e
s 00012/00006/00702
d D 5.2 86/09/01 12:25:38 sam 12 11
c print character arrays one char at a time with printchar to get 
c unprintables; change subscript checking to a warning (it's c after all)
e
s 00008/00002/00700
d D 5.1 85/05/31 09:55:11 dist 11 10
c Add copyright
e
s 00062/00139/00640
d D 1.9 85/03/01 20:18:25 linton 10 9
c update to version 3.0
e
s 00001/00003/00778
d D 1.8 84/06/23 11:39:24 sam 9 7
i 8
c merge linton branch delta trail
e
s 00060/00028/00721
d D 1.7.1.1 84/06/23 10:44:30 sam 8 7
c branch delta of linton changes from net.sources
e
s 00001/00001/00748
d D 1.7 83/08/16 12:18:21 linton 7 6
c changed printing of type names to not include enclosing module name
e
s 00003/00003/00746
d D 1.6 83/08/05 21:35:55 linton 6 5
c union objects cannot be printed, they must be qualified
e
s 00003/00003/00746
d D 1.5 83/07/07 23:02:35 linton 5 4
c fixed slight problem with operations on C doubles, things still 
c don't quite work for floats
e
s 00004/00000/00745
d D 1.4 83/05/19 01:37:08 csvaf 4 3
c fixed missing typedef
e
s 00078/00000/00667
d D 1.3 83/05/18 18:30:12 csvaf 3 2
c language specific functions to build and evaluate array reference trees
e
s 00001/00001/00666
d D 1.2 82/12/15 04:19:33 linton 2 1
c fixed @(#) stuff
e
s 00667/00000/00000
d D 1.1 82/12/15 04:07:11 linton 1 0
c date and time created 82/12/15 04:07:11 by linton
e
u
U
f b 
t
T
I 1
D 11
/* Copyright (c) 1982 Regents of the University of California */
E 11
I 11
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 11

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 8
static char sccsid[] = "%Z%%M% %I% %G%";
E 8
I 8
D 9
static char sccsid[] = "@(#)c.c 1.6 8/5/83";
E 8
E 2

I 8
static char rcsid[] = "$Header: c.c,v 1.3 84/03/27 10:19:40 linton Exp $";
E 9
I 9
D 11
static	char sccsid[] = "%W% (Berkeley) %G%";
E 11
I 11
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 11
E 9

I 10
D 18
static char rcsid[] = "$Header: c.c,v 1.5 84/12/26 10:38:23 linton Exp $";
E 18
I 18
D 19
static char rcsid[] = "$Header: c.c,v 1.4 88/01/12 00:46:21 donn Exp $";
E 19
I 19
static char rcsid[] = "$Header: c.c,v 1.5 88/04/02 01:25:44 donn Exp $";
E 19
E 18

E 10
E 8
/*
 * C-dependent symbol routines.
 */

#include "defs.h"
#include "symbols.h"
#include "printsym.h"
#include "languages.h"
#include "c.h"
#include "tree.h"
#include "eval.h"
#include "operators.h"
#include "mappings.h"
#include "process.h"
#include "runtime.h"
#include "machine.h"

I 4
#ifndef public
D 18
# include "tree.h"
E 18
I 18
#   include "tree.h"
E 18
#endif

E 4
#define isdouble(range) ( \
    range->symvalue.rangev.upper == 0 and range->symvalue.rangev.lower > 0 \
)

#define isrange(t, name) (t->class == RANGE and istypename(t->type, name))

I 8
private Language langC;
I 18
private Language langCplpl;
E 18

E 8
/*
 * Initialize C language information.
 */

public c_init()
{
D 8
    Language lang;

    lang = language_define("c", ".c");
    language_setop(lang, L_PRINTDECL, c_printdecl);
    language_setop(lang, L_PRINTVAL, c_printval);
    language_setop(lang, L_TYPEMATCH, c_typematch);
I 3
    language_setop(lang, L_BUILDAREF, c_buildaref);
    language_setop(lang, L_EVALAREF, c_evalaref);
E 8
I 8
    langC = language_define("c", ".c");
    language_setop(langC, L_PRINTDECL, c_printdecl);
    language_setop(langC, L_PRINTVAL, c_printval);
    language_setop(langC, L_TYPEMATCH, c_typematch);
    language_setop(langC, L_BUILDAREF, c_buildaref);
    language_setop(langC, L_EVALAREF, c_evalaref);
    language_setop(langC, L_MODINIT, c_modinit);
    language_setop(langC, L_HASMODULES, c_hasmodules);
    language_setop(langC, L_PASSADDR, c_passaddr);
I 18

    langCplpl = language_define("c++", "..c");
    language_setop(langCplpl, L_PRINTDECL, c_printdecl);
    language_setop(langCplpl, L_PRINTVAL, c_printval);
    language_setop(langCplpl, L_TYPEMATCH, c_typematch);
    language_setop(langCplpl, L_BUILDAREF, c_buildaref);
    language_setop(langCplpl, L_EVALAREF, c_evalaref);
    language_setop(langCplpl, L_MODINIT, c_modinit);
    language_setop(langCplpl, L_HASMODULES, c_hasmodules);
    language_setop(langCplpl, L_PASSADDR, c_passaddr);
E 18
E 8
E 3
}

/*
 * Test if two types are compatible.
D 5
 *
 * Integers and reals are not compatible since they cannot always be mixed.
E 5
 */

public Boolean c_typematch(type1, type2)
Symbol type1, type2;
{
    Boolean b;
    register Symbol t1, t2, tmp;

    t1 = type1;
    t2 = type2;
    if (t1 == t2) {
	b = true;
    } else {
	t1 = rtype(t1);
	t2 = rtype(t2);
D 5
	if (t1->type == t_int or t1->type == t_char) {
E 5
I 5
D 8
	if (t1->type == t_char or t1->type == t_int or t1->type == t_real) {
E 8
I 8
	if (t1 == t_char->type or t1 == t_int->type or t1 == t_real->type) {
E 8
E 5
	    tmp = t1;
	    t1 = t2;
	    t2 = tmp;
	}
	b = (Boolean) (
	    (
D 19
		isrange(t1, "int") and
E 19
I 19
		isrange(t1, "int") and !isdouble(t1) /* sigh */ and
E 19
D 8
		(t2->type == t_int or t2->type == t_char)
E 8
I 8
		(t2 == t_int->type or t2 == t_char->type)
E 8
	    ) or (
		isrange(t1, "char") and
D 8
		(t2->type == t_char or t2->type == t_int)
E 8
I 8
		(t2 == t_char->type or t2 == t_int->type)
E 8
I 5
	    ) or (
D 8
		t1->class == RANGE and isdouble(t1) and t2->type == t_real
E 8
I 8
		t1->class == RANGE and isdouble(t1) and t2 == t_real->type
E 8
E 5
	    ) or (
I 10
		t1->class == RANGE and t2->class == RANGE and
		t1->symvalue.rangev.lower == t2->symvalue.rangev.lower and
		t1->symvalue.rangev.upper == t2->symvalue.rangev.upper
	    ) or (
E 10
D 19
		t1->type == t2->type and (
E 19
I 19
		t1->class != RANGE and t1->type == t2->type and (
E 19
		    (t1->class == t2->class) or
		    (t1->class == SCAL and t2->class == CONST) or
		    (t1->class == CONST and t2->class == SCAL)
		)
I 8
	    ) or (
		t1->class == PTR and c_typematch(t1->type, t_char) and
		t2->class == ARRAY and c_typematch(t2->type, t_char) and
		t2->language == primlang
E 8
	    )
	);
    }
    return b;
}

/*
D 10
 * Decide if a field is a bit field.
 */

private Boolean isbitfield(s)
register Symbol s;
{
    Boolean b;
    register Integer off, len;
    register Symbol t;

    off = s->symvalue.field.offset;
    len = s->symvalue.field.length;
    if ((off mod BITSPERBYTE) != 0 or (len mod BITSPERBYTE) != 0) {
	b = true;
    } else {
	t = rtype(s->type);
	b = (Boolean)
	    (t->class == SCAL and len != (sizeof(int)*BITSPERBYTE) or
	    len != (size(t)*BITSPERBYTE)
	);
    }
    return b;
}

/*
E 10
 * Print out the declaration of a C variable.
 */

public c_printdecl(s)
Symbol s;
{
    printdecl(s, 0);
}

private printdecl(s, indent)
register Symbol s;
Integer indent;
{
    register Symbol t;
    Boolean semicolon, newline;

    semicolon = true;
    newline = true;
    if (indent > 0) {
	printf("%*c", indent, ' ');
    }
    if (s->class == TYPE) {
	printf("typedef ");
    }
    switch (s->class) {
	case CONST:
	    if (s->type->class == SCAL) {
D 10
		printf("(enumeration constant, ord %ld)",
		    s->symvalue.iconval);
E 10
I 10
		printf("enumeration constant with value ");
		eval(s->symvalue.constval);
		c_printval(s);
E 10
	    } else {
		printf("const %s = ", symname(s));
		printval(s);
	    }
	    break;

	case TYPE:
	case VAR:
D 10
	    if (s->class != TYPE) {
D 8
		if (s->level == 2) {
E 8
I 8
		if (s->level == 1 and s->block != program) {
E 8
		    printf("static ");
		} else if (s->level < 0) {
		    printf("register ");
		}
E 10
I 10
D 18
	    if (s->class != TYPE and s->level < 0) {
E 18
I 18
	    if (s->class != TYPE and s->storage == INREG) {
E 18
		printf("register ");
E 10
	    }
	    if (s->type->class == ARRAY) {
		printtype(s->type, s->type->type, indent);
		t = rtype(s->type->chain);
		assert(t->class == RANGE);
		printf(" %s[%d]", symname(s), t->symvalue.rangev.upper + 1);
	    } else {
		printtype(s, s->type, indent);
		if (s->type->class != PTR) {
		    printf(" ");
		}
		printf("%s", symname(s));
	    }
	    break;

	case FIELD:
	    if (s->type->class == ARRAY) {
		printtype(s->type, s->type->type, indent);
		t = rtype(s->type->chain);
		assert(t->class == RANGE);
		printf(" %s[%d]", symname(s), t->symvalue.rangev.upper + 1);
	    } else {
		printtype(s, s->type, indent);
		if (s->type->class != PTR) {
		    printf(" ");
		}
		printf("%s", symname(s));
	    }
	    if (isbitfield(s)) {
		printf(" : %d", s->symvalue.field.length);
	    }
	    break;

	case TAG:
	    if (s->type == nil) {
		findtype(s);
		if (s->type == nil) {
		    error("unexpected missing type information");
		}
	    }
	    printtype(s, s->type, indent);
	    break;

	case RANGE:
	case ARRAY:
	case RECORD:
	case VARNT:
	case PTR:
I 10
	case FFUNC:
E 10
	    semicolon = false;
	    printtype(s, s, indent);
	    break;

I 10
	case SCAL:
	    printf("(enumeration constant, value %d)", s->symvalue.iconval);
	    break;

E 10
	case PROC:
	    semicolon = false;
	    printf("%s", symname(s));
	    c_listparams(s);
	    newline = false;
	    break;

	case FUNC:
	    semicolon = false;
	    if (not istypename(s->type, "void")) {
		printtype(s, s->type, indent);
		printf(" ");
	    }
	    printf("%s", symname(s));
	    c_listparams(s);
	    newline = false;
	    break;

	case MODULE:
	    semicolon = false;
	    printf("source file \"%s.c\"", symname(s));
	    break;

	case PROG:
	    semicolon = false;
	    printf("executable file \"%s\"", symname(s));
	    break;

	default:
D 10
	    error("class %s in c_printdecl", classname(s));
E 10
I 10
	    printf("[%s]", classname(s));
	    break;
E 10
    }
    if (semicolon) {
	putchar(';');
    }
    if (newline) {
	putchar('\n');
    }
}

/*
 * Recursive whiz-bang procedure to print the type portion
 * of a declaration.
 *
 * The symbol associated with the type is passed to allow
 * searching for type names without getting "type blah = blah".
 */

private printtype(s, t, indent)
Symbol s;
Symbol t;
Integer indent;
{
    register Symbol i;
    long r0, r1;
    register String p;

    checkref(s);
    checkref(t);
    switch (t->class) {
	case VAR:
	case CONST:
	case PROC:
	    panic("printtype: class %s", classname(t));
	    break;

	case ARRAY:
	    printf("array[");
	    i = t->chain;
	    if (i != nil) {
		for (;;) {
		    printtype(i, i, indent);
		    i = i->chain;
		    if (i == nil) {
			break;
		    }
		    printf(", ");
		}
	    }
	    printf("] of ");
	    printtype(t, t->type, indent);
	    break;

	case RECORD:
	case VARNT:
	    printf("%s ", c_classname(t));
	    if (s->name != nil and s->class == TAG) {
		p = symname(s);
		if (p[0] == '$' and p[1] == '$') {
		    printf("%s ", &p[2]);
		} else {
		    printf("%s ", p);
		}
	    }
D 16
	    printf("{\n", t->class == RECORD ? "struct" : "union");
E 16
I 16
D 17
	    printf("%s {\n", t->class == RECORD ? "struct" : "union");
E 17
I 17
	    printf("{\n");
E 17
E 16
	    for (i = t->chain; i != nil; i = i->chain) {
		assert(i->class == FIELD);
		printdecl(i, indent+4);
	    }
	    if (indent > 0) {
		printf("%*c", indent, ' ');
	    }
	    printf("}");
	    break;

	case RANGE:
	    r0 = t->symvalue.rangev.lower;
	    r1 = t->symvalue.rangev.upper;
	    if (istypename(t->type, "char")) {
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
	    break;

	case PTR:
	    printtype(t, t->type, indent);
	    if (t->type->class != PTR) {
		printf(" ");
	    }
	    printf("*");
	    break;

	case FUNC:
I 8
	case FFUNC:
E 8
	    printtype(t, t->type, indent);
	    printf("()");
	    break;

	case TYPE:
	    if (t->name != nil) {
D 7
		printname(stdout, t);
E 7
I 7
D 8
		printf("%s", symname(t));
E 8
I 8
		printname(stdout, t);
E 8
E 7
	    } else {
		printtype(t, t->type, indent);
	    }
	    break;

	case TYPEREF:
	    printf("@%s", symname(t));
	    break;

	case SCAL:
	    printf("enum ");
	    if (s->name != nil and s->class == TAG) {
		printf("%s ", symname(s));
	    }
	    printf("{ ");
	    i = t->chain;
	    if (i != nil) {
		for (;;) {
		    printf("%s", symname(i));
		    i = i->chain;
		if (i == nil) break;
		    printf(", ");
		}
	    }
	    printf(" }");
	    break;

	case TAG:
	    if (t->type == nil) {
		printf("unresolved tag %s", symname(t));
	    } else {
		i = rtype(t->type);
		printf("%s %s", c_classname(i), symname(t));
	    }
	    break;

	default:
	    printf("(class %d)", t->class);
	    break;
    }
}

/*
 * List the parameters of a procedure or function.
 * No attempt is made to combine like types.
 */

public c_listparams(s)
Symbol s;
{
    register Symbol t;

    putchar('(');
    for (t = s->chain; t != nil; t = t->chain) {
	printf("%s", symname(t));
	if (t->chain != nil) {
	    printf(", ");
	}
    }
    putchar(')');
    if (s->chain != nil) {
	printf("\n");
	for (t = s->chain; t != nil; t = t->chain) {
	    if (t->class != VAR) {
		panic("unexpected class %d for parameter", t->class);
	    }
	    printdecl(t, 0);
	}
    } else {
	putchar('\n');
    }
}

/*
 * Print out the value on the top of the expression stack
 * in the format for the type of the given symbol.
 */

public c_printval(s)
Symbol s;
{
    register Symbol t;
    register Address a;
D 8
    register int i, len;
E 8
I 8
    integer i, len;
I 12
    register String str;
E 12
E 8

    switch (s->class) {
	case CONST:
	case TYPE:
	case VAR:
	case REF:
	case FVAR:
	case TAG:
	    c_printval(s->type);
	    break;

	case FIELD:
	    if (isbitfield(s)) {
D 8
		len = s->symvalue.field.length;
		if (len <= BITSPERBYTE) {
		    i = pop(char);
		} else if (len <= sizeof(short)*BITSPERBYTE) {
		    i = pop(short);
		} else {
		    i = pop(long);
		}
E 8
I 8
D 18
		i = 0;
		popn(size(s), &i);
E 8
D 14
		i >>= (s->symvalue.field.offset mod BITSPERBYTE);
D 8
		i &= ((1 << len) - 1);
E 8
I 8
		i &= ((1 << s->symvalue.field.length) - 1);
E 14
I 14
		i = extractfield(i, s);
E 18
I 18
		i = extractField(s);
E 18
E 14
E 8
		t = rtype(s->type);
		if (t->class == SCAL) {
D 10
		    printenum(i, t);
E 10
I 10
		    printEnum(i, t);
E 10
		} else {
D 10
		    printrange(i, t);
E 10
I 10
		    printRangeVal(i, t);
E 10
		}
	    } else {
		c_printval(s->type);
	    }
	    break;

	case ARRAY:
	    t = rtype(s->type);
D 8
	    if (t->class == RANGE and istypename(t->type, "char")) {
E 8
I 8
	    if ((t->class == RANGE and istypename(t->type, "char")) or
		t == t_char->type
	    ) {
E 8
		len = size(s);
D 12
		sp -= len;
D 10
		printf("\"%.*s\"", len, sp);
E 10
I 10
		if (s->language == primlang) {
		    printf("%.*s", len, sp);
		} else {
		    printf("\"%.*s\"", len, sp);
E 12
I 12
		str = (String) (sp -= len);
		if (s->language != primlang) {
		    putchar('"');
E 12
		}
I 12
D 13
		while (len > 0) {
E 13
I 13
		while (--len > 0 and *str != '\0') {
E 13
		    printchar(*str++);
D 13
		    len--;
E 13
I 13
		}
		if (*str != '\0') {	/* XXX - pitch trailing null */
		    printchar(*str);
E 13
		}
		if (s->language != primlang) {
		    putchar('"');
		}
E 12
E 10
	    } else {
		printarray(s);
	    }
	    break;

	case RECORD:
D 6
	case VARNT:
E 6
	    c_printstruct(s);
	    break;

	case RANGE:
D 10
	    if (istypename(s->type, "boolean")) {
		printrange(popsmall(s), s);
	    } else if (istypename(s->type, "char")) {
		printrange(pop(char), s);
	    } else if (isdouble(s)) {
E 10
I 10
	    if (s == t_boolean->type or istypename(s->type, "boolean")) {
		printRangeVal(popsmall(s), s);
	    } else if (s == t_char->type or istypename(s->type, "char")) {
		printRangeVal(pop(char), s);
	    } else if (s == t_real->type or isdouble(s)) {
E 10
		switch (s->symvalue.rangev.lower) {
		    case sizeof(float):
D 18
			prtreal(pop(float));
E 18
I 18
			prtreal((double) (pop(float)));
E 18
			break;

		    case sizeof(double):
			prtreal(pop(double));
			break;

		    default:
			panic("bad real size %d", t->symvalue.rangev.lower);
			break;
		}
	    } else {
D 10
		printrange(popsmall(s), s);
E 10
I 10
		printRangeVal(popsmall(s), s);
E 10
	    }
	    break;

	case PTR:
	    t = rtype(s->type);
	    a = pop(Address);
	    if (a == 0) {
		printf("(nil)");
	    } else if (t->class == RANGE and istypename(t->type, "char")) {
D 10
		printstring(a);
E 10
I 10
		printString(a, (boolean) (s->language != primlang));
E 10
	    } else {
		printf("0x%x", a);
	    }
	    break;

	case SCAL:
	    i = pop(Integer);
D 10
	    printenum(i, s);
E 10
I 10
	    printEnum(i, s);
E 10
	    break;

I 10
	/*
	 * Unresolved structure pointers?
	 */
	case BADUSE:
	    a = pop(Address);
	    printf("@%x", a);
	    break;

E 10
	default:
	    if (ord(s->class) > ord(TYPEREF)) {
		panic("printval: bad class %d", ord(s->class));
	    }
D 6
	    error("don't know how to print a %s", c_classname(s));
	    /* NOTREACHED */
E 6
I 6
	    sp -= size(s);
D 8
	    printf("<%s>", c_classname(s));
E 8
I 8
	    printf("[%s]", c_classname(s));
E 8
	    break;
E 6
    }
}

/*
 * Print out a C structure.
 */

D 10
private c_printstruct(s)
E 10
I 10
private c_printstruct (s)
E 10
Symbol s;
{
D 10
    register Symbol f;
    register Stack *savesp;
    register Integer n, off, len;
E 10
I 10
    Symbol f;
    Stack *savesp;
    integer n, off, len;
E 10

    sp -= size(s);
    savesp = sp;
    printf("(");
    f = s->chain;
    for (;;) {
	off = f->symvalue.field.offset;
	len = f->symvalue.field.length;
D 8
	n = (off + len + 7) div BITSPERBYTE;
E 8
I 8
	n = (off + len + BITSPERBYTE - 1) div BITSPERBYTE;
E 8
	sp += n;
	printf("%s = ", symname(f));
	c_printval(f);
	sp = savesp;
	f = f->chain;
    if (f == nil) break;
	printf(", ");
    }
    printf(")");
}

/*
D 10
 * Print out a range type (integer, char, or boolean).
 */

private printrange(i, t)
Integer i;
register Symbol t;
{
    if (istypename(t->type, "boolean")) {
	printf(((Boolean) i) == true ? "true" : "false");
    } else if (istypename(t->type, "char")) {
	putchar('\'');
	printchar(i);
	putchar('\'');
    } else if (t->symvalue.rangev.lower >= 0) {
	printf("%lu", i);
    } else {
	printf("%ld", i);
    }
}

/*
 * Print out a null-terminated string (pointer to char)
 * starting at the given address.
 */

private printstring(addr)
Address addr;
{
    register Address a;
    register Integer i, len;
    register Boolean endofstring;
    union {
	char ch[sizeof(Word)];
	int word;
    } u;

    putchar('"');
    a = addr;
    endofstring = false;
    while (not endofstring) {
	dread(&u, a, sizeof(u));
	i = 0;
	do {
	    if (u.ch[i] == '\0') {
		endofstring = true;
	    } else {
		printchar(u.ch[i]);
	    }
	    ++i;
	} while (i < sizeof(Word) and not endofstring);
	a += sizeof(Word);
    }
    putchar('"');
}

/*
 * Print out an enumerated value by finding the corresponding
 * name in the enumeration list.
 */

private printenum(i, t)
Integer i;
Symbol t;
{
    register Symbol e;

    e = t->chain;
    while (e != nil and e->symvalue.iconval != i) {
	e = e->chain;
    }
    if (e != nil) {
	printf("%s", symname(e));
    } else {
	printf("%d", i);
    }
}

/*
E 10
 * Return the C name for the particular class of a symbol.
 */

public String c_classname(s)
Symbol s;
{
    String str;

    switch (s->class) {
	case RECORD:
	    str = "struct";
	    break;

	case VARNT:
	    str = "union";
	    break;

	case SCAL:
	    str = "enum";
	    break;

	default:
	    str = classname(s);
    }
    return str;
I 3
}
I 10

E 10
public Node c_buildaref(a, slist)
Node a, slist;
{
    register Symbol t;
    register Node p;
    Symbol etype, atype, eltype;
D 10
    Node esub, r;
E 10
I 10
    Node r, esub;
E 10

D 10
    r = a;
E 10
    t = rtype(a->nodetype);
    eltype = t->type;
    if (t->class == PTR) {
	p = slist->value.arg[0];
	if (not compatible(p->nodetype, t_int)) {
	    beginerrmsg();
D 10
	    fprintf(stderr, "bad type for subscript of ");
	    prtree(stderr, a);
E 10
I 10
	    fprintf(stderr, "subscript must be integer-compatible");
E 10
	    enderrmsg();
	}
	r = build(O_MUL, p, build(O_LCON, (long) size(eltype)));
	r = build(O_ADD, build(O_RVAL, a), r);
	r->nodetype = eltype;
    } else if (t->class != ARRAY) {
	beginerrmsg();
I 10
	fprintf(stderr, "\"");
E 10
	prtree(stderr, a);
D 10
	fprintf(stderr, " is not an array");
E 10
I 10
	fprintf(stderr, "\" is not an array");
E 10
	enderrmsg();
    } else {
I 10
	r = a;
E 10
	p = slist;
	t = t->chain;
	for (; p != nil and t != nil; p = p->value.arg[1], t = t->chain) {
	    esub = p->value.arg[0];
	    etype = rtype(esub->nodetype);
	    atype = rtype(t);
	    if (not compatible(atype, etype)) {
		beginerrmsg();
D 10
		fprintf(stderr, "subscript ");
E 10
I 10
		fprintf(stderr, "subscript \"");
E 10
		prtree(stderr, esub);
D 10
		fprintf(stderr, " is the wrong type");
E 10
I 10
		fprintf(stderr, "\" is the wrong type");
E 10
		enderrmsg();
	    }
	    r = build(O_INDEX, r, esub);
	    r->nodetype = eltype;
	}
	if (p != nil or t != nil) {
	    beginerrmsg();
	    if (p != nil) {
D 10
		fprintf(stderr, "too many subscripts for ");
E 10
I 10
		fprintf(stderr, "too many subscripts for \"");
E 10
	    } else {
D 10
		fprintf(stderr, "not enough subscripts for ");
E 10
I 10
		fprintf(stderr, "not enough subscripts for \"");
E 10
	    }
	    prtree(stderr, a);
I 10
	    fprintf(stderr, "\"");
E 10
	    enderrmsg();
	}
    }
    return r;
}

/*
 * Evaluate a subscript index.
 */

D 10
public int c_evalaref(s, i)
E 10
I 10
public c_evalaref(s, base, i)
E 10
Symbol s;
I 10
Address base;
E 10
long i;
{
I 10
    Symbol t;
E 10
    long lb, ub;

D 10
    s = rtype(s)->chain;
E 10
I 10
    t = rtype(s);
    s = t->chain;
E 10
    lb = s->symvalue.rangev.lower;
    ub = s->symvalue.rangev.upper;
    if (i < lb or i > ub) {
D 12
	error("subscript out of range");
E 12
I 12
	warning("subscript out of range");
E 12
    }
D 10
    return (i - lb);
E 10
I 10
    push(long, base + (i - lb) * size(t->type));
E 10
I 8
}

/*
 * Initialize typetable information.
 */

public c_modinit (typetable)
Symbol typetable[];
{
    /* nothing right now */
}

public boolean c_hasmodules ()
{
    return false;
}

public boolean c_passaddr (param, exprtype)
Symbol param, exprtype;
{
    boolean b;
    Symbol t;

    t = rtype(exprtype);
    b = (boolean) (t->class == ARRAY);
    return b;
E 8
E 3
}
E 1
