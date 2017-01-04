h28487
s 00008/00001/00168
d D 5.2 88/01/11 23:40:43 donn 8 6
c merge in latest Linton version
e
s 00000/00000/00169
d R 5.2 88/01/11 23:39:54 donn 7 6
c merge in latest Linton version
e
s 00008/00002/00161
d D 5.1 85/05/31 09:54:35 dist 6 5
c Add copyright
e
s 00052/00001/00111
d D 1.4 85/03/01 20:18:18 linton 5 4
c update to version 3.0
e
s 00001/00003/00111
d D 1.3 84/06/23 11:39:20 sam 4 2
i 3
c merge linton branch delta trail
e
s 00016/00001/00098
d D 1.2.1.1 84/06/23 10:44:26 sam 3 2
c branch delta of linton changes from net.sources
e
s 00001/00001/00098
d D 1.2 82/12/15 04:19:29 linton 2 1
c fixed @(#) stuff
e
s 00099/00000/00000
d D 1.1 82/12/15 04:07:07 linton 1 0
c date and time created 82/12/15 04:07:07 by linton
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
static char sccsid[] = "@(#)asm.c 1.2 12/15/82";
E 3
E 2

I 3
static char rcsid[] = "$Header: asm.c,v 1.3 84/03/27 10:19:36 linton Exp $";
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
D 8
static char rcsid[] = "$Header: asm.c,v 1.5 84/12/26 10:38:19 linton Exp $";
E 8
I 8
static char rcsid[] = "$Header: asm.c,v 1.2 87/03/25 19:24:09 donn Exp $";
E 8

E 5
E 3
/*
 * Assembly language dependent symbol routines.
 */

#include "defs.h"
#include "symbols.h"
#include "asm.h"
#include "languages.h"
#include "tree.h"
#include "eval.h"
#include "operators.h"
#include "mappings.h"
#include "process.h"
#include "runtime.h"
#include "machine.h"

#define isdouble(range) ( \
    range->symvalue.rangev.upper == 0 and range->symvalue.rangev.lower > 0 \
)

/*
 * Initialize assembly language information.
 */

public asm_init()
{
    Language lang;

    lang = language_define("assembler", ".s");
    language_setop(lang, L_PRINTDECL, asm_printdecl);
    language_setop(lang, L_PRINTVAL, asm_printval);
    language_setop(lang, L_TYPEMATCH, asm_typematch);
I 5
    language_setop(lang, L_BUILDAREF, asm_buildaref);
    language_setop(lang, L_EVALAREF, asm_evalaref);
I 8
    language_setop(lang, L_MODINIT, asm_modinit);
E 8
E 5
I 3
    language_setop(lang, L_HASMODULES, asm_hasmodules);
    language_setop(lang, L_PASSADDR, asm_passaddr);
E 3
}

/*
 * Test if two types are compatible.
 */

public Boolean asm_typematch(type1, type2)
Symbol type1, type2;
{
    Boolean b;

    b = false;
    return b;
}

public asm_printdecl(s)
Symbol s;
{
    switch (s->class) {
I 5
	case CONST:
	    printf("%s = %d", symname(s), s->symvalue.constval->value.lcon);
	    break;

E 5
	case VAR:
	case REF:
	    printf("&%s = 0x%x", symname(s), s->symvalue.offset);
	    break;

	case PROC:
	case FUNC:
	    printf("%s (0x%x):", symname(s), codeloc(s));
	    break;

I 5
	case TYPE:
	    printf("%s", symname(s));
	    break;

	case ARRAY:
	    printf("$string");
	    break;

E 5
	default:
D 5
	    error("class %s in c_printdecl", classname(s));
E 5
I 5
	    printf("[%s]", classname(s));
	    break;
E 5
    }
    putchar('\n');
}

/*
 * Print out the value on the top of the expression stack
 * in the format for the type of the given symbol.
 */

public asm_printval(s)
register Symbol s;
{
    register Symbol t;
    register Integer len;

    switch (s->class) {
	case ARRAY:
	    t = rtype(s->type);
	    if (t->class == RANGE and istypename(t->type, "$char")) {
		len = size(s);
		sp -= len;
		printf("\"%.*s\"", len, sp);
	    } else {
		printarray(s);
	    }
	    break;

	default:
	    printf("0x%x", pop(Integer));
	    break;
    }
I 5
}

/*
 * Treat subscripting as indirection through pointer to integer.
 */

public Node asm_buildaref(a, slist)
Node a, slist;
{
    Symbol t, eltype;
    Node p, r;

    t = rtype(a->nodetype);
    eltype = t->type;
    p = slist->value.arg[0];
    r = build(O_MUL, p, build(O_LCON, (long) size(eltype)));
    r = build(O_ADD, build(O_RVAL, a), r);
    r->nodetype = eltype;
    return r;
}

/*
 * Evaluate a subscript index.  Assumes dimension is [0..n].
 */

public asm_evalaref(s, base, i)
Symbol s;
Address base;
long i;
{
    Symbol t;

    t = rtype(s);
    push(long, base + i * size(t->type));
I 8
}

public asm_modinit (typetable)
Symbol typetable[];
{
    /* nothing for right now */
E 8
E 5
I 3
}

public boolean asm_hasmodules ()
{
    return false;
}

public boolean asm_passaddr (param, exprtype)
Symbol param, exprtype;
{
    return false;
E 3
}
E 1
