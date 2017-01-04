h08737
s 00008/00002/00115
d D 5.1 85/05/31 10:01:20 dist 7 6
c Add copyright
e
s 00002/00000/00115
d D 1.5 85/03/01 20:24:06 linton 6 5
c update to version 3.0
e
s 00001/00003/00114
d D 1.4 84/06/23 11:40:59 sam 5 3
i 4
c merge linton branch delta trail
e
s 00015/00004/00102
d D 1.3.1.1 84/06/23 10:46:46 sam 4 3
c branch delta of linton changes from net.sources
e
s 00003/00002/00103
d D 1.3 83/05/18 19:43:25 csvaf 3 2
c added fortran_init and array build/evaluate operators
e
s 00001/00001/00104
d D 1.2 82/12/15 04:20:25 linton 2 1
c fixed @(#) stuff
e
s 00105/00000/00000
d D 1.1 82/12/15 04:07:38 linton 1 0
c date and time created 82/12/15 04:07:38 by linton
e
u
U
f b 
t
T
I 1
D 7
/* Copyright (c) 1982 Regents of the University of California */
E 7
I 7
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 7

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 4
static char sccsid[] = "%Z%%M% %I% %G%";
E 4
I 4
D 5
static char sccsid[] = "@(#)languages.c 1.3 5/18/83";
E 4
E 2

I 4
static char rcsid[] = "$Header: languages.c,v 1.3 84/03/27 10:21:09 linton Exp $";
E 5
I 5
D 7
static	char sccsid[] = "%W% (Berkeley) %G%";
E 7
I 7
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7
E 5

I 6
static char rcsid[] = "$Header: languages.c,v 1.5 84/12/26 10:39:49 linton Exp $";

E 6
E 4
/*
 * Language management.
 */

#include "defs.h"
#include "languages.h"
#include "c.h"
#include "pascal.h"
I 4
#include "modula-2.h"
E 4
#include "asm.h"

#ifndef public
I 4

E 4
typedef struct Language *Language;

typedef enum {
D 3
    L_PRINTDECL, L_PRINTVAL, L_TYPEMATCH
E 3
I 3
D 4
    L_PRINTDECL, L_PRINTVAL, L_TYPEMATCH, L_BUILDAREF, L_EVALAREF
E 4
I 4
    L_PRINTDECL, L_PRINTVAL, L_TYPEMATCH, L_BUILDAREF, L_EVALAREF,
    L_MODINIT, L_HASMODULES, L_PASSADDR,
    L_ENDOP
E 4
E 3
} LanguageOp;

typedef LanguageOperation();
I 4

Language primlang;

E 4
#endif

struct Language {
    String name;
    String suffix;
D 4
    LanguageOperation *op[10];
E 4
I 4
    LanguageOperation *op[20];
E 4
    Language next;
};

private Language head;

/*
 * Initialize language information.
 *
 * The last language initialized will be the default one
 * for otherwise indistinguised symbols.
 */

public language_init()
{
I 4
    primlang = language_define("$builtin symbols", ".?");
E 4
    c_init();
I 3
    fortran_init();
E 3
    pascal_init();
I 4
    modula2_init();
E 4
    asm_init();
}

public Language findlanguage(suffix)
String suffix;
{
    Language lang;

    lang = head;
    if (suffix != nil) {
	while (lang != nil and not streq(lang->suffix, suffix)) {
	    lang = lang->next;
	}
	if (lang == nil) {
	    lang = head;
	}
    }
    return lang;
}

public String language_name(lang)
Language lang;
{
    return (lang == nil) ? "(nil)" : lang->name;
}

public Language language_define(name, suffix)
String name;
String suffix;
{
    Language p;

    p = new(Language);
    p->name = name;
    p->suffix = suffix;
    p->next = head;
    head = p;
    return p;
}

public language_setop(lang, op, operation)
Language lang;
LanguageOp op;
LanguageOperation *operation;
{
    checkref(lang);
D 3
    assert(ord(op) <= ord(L_TYPEMATCH));
E 3
I 3
D 4
    assert(ord(op) <= ord(L_EVALAREF));
E 4
I 4
    assert(ord(op) < ord(L_ENDOP));
E 4
E 3
    lang->op[ord(op)] = operation;
}

public LanguageOperation *language_op(lang, op)
Language lang;
LanguageOp op;
{
    LanguageOperation *o;

    checkref(lang);
    o = lang->op[ord(op)];
    checkref(o);
    return o;
}
E 1
