h59131
s 00002/00001/00257
d D 5.2 85/06/07 20:50:43 mckusick 4 3
c fix botched copyright
e
s 00009/00004/00249
d D 5.1 85/06/06 11:55:37 dist 3 2
c Add copyright
e
s 00184/00188/00069
d D 1.2 83/02/14 23:30:43 linton 2 1
c fixed some problems involving non-integer subrange types
e
s 00257/00000/00000
d D 1.1 82/01/18 19:21:17 linton 1 0
c date and time created 82/01/18 19:21:17 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */

static char sccsid[] = "%Z%%M% %I% %G%";

E 3
/*
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
D 4
*
E 4
I 4

/*
E 4
E 3
D 2
 * print out the type of a symbol
E 2
I 2
 * Print out the type of a symbol.
E 2
 */

#include "defs.h"
#include "sym.h"
#include "symtab.h"
#include "tree.h"
#include "btypes.h"
#include "classes.h"
#include "sym.rep"

printdecl(s)
SYM *s;
{
D 2
	register SYM *t;
	BOOLEAN semicolon;
E 2
I 2
    register SYM *t;
    BOOLEAN semicolon;
E 2

D 2
	semicolon = TRUE;
	switch(s->class) {
		case CONST:
			if (s->type->class == SCAL) {
				printf("(enumeration constant, ord %ld)",
					s->symvalue.iconval);
			} else {
				printf("const %s = ", s->symbol);
				if (s->type == t_real->type) {
					printf("%g", s->symvalue.fconval);
				} else {
					printf("%ld", s->symvalue.iconval);
				}
			}
			break;
E 2
I 2
    semicolon = TRUE;
    switch(s->class) {
	case CONST:
	    t = rtype(s->type);
	    if (t->class == SCAL) {
		printf("(enumeration constant, ord %ld)", s->symvalue.iconval);
	    } else {
		printf("const %s = ", s->symbol);
		if (t == t_real) {
		    printf("%g", s->symvalue.fconval);
		} else {
		    printordinal(s->symvalue.iconval, t);
		}
	    }
	    break;
E 2

D 2
		case TYPE:
			printf("type %s = ", s->symbol);
			printtype(s, s->type);
			break;
E 2
I 2
	case TYPE:
	    printf("type %s = ", s->symbol);
	    printtype(s, s->type);
	    break;
E 2

D 2
		case VAR:
			if (isparam(s)) {
				printf("(parameter) %s : ", s->symbol);
			} else {
				printf("var %s : ", s->symbol);
			}
			printtype(s, s->type);
			break;
E 2
I 2
	case VAR:
	    if (isparam(s)) {
		printf("(parameter) %s : ", s->symbol);
	    } else {
		printf("var %s : ", s->symbol);
	    }
	    printtype(s, s->type);
	    break;
E 2

D 2
		case REF:
			printf("(var parameter) %s : ", s->symbol);
			printtype(s, s->type);
			break;
E 2
I 2
	case REF:
	    printf("(var parameter) %s : ", s->symbol);
	    printtype(s, s->type);
	    break;
E 2

D 2
		case RANGE:
		case ARRAY:
		case RECORD:
		case VARNT:
		case PTR:
			printtype(s, s);
			semicolon = FALSE;
			break;
E 2
I 2
	case RANGE:
	case ARRAY:
	case RECORD:
	case VARNT:
	case PTR:
	    printtype(s, s);
	    semicolon = FALSE;
	    break;
E 2

D 2
		case FVAR:
			printf("(function variable) %s : ", s->symbol);
			printtype(s, s->type);
			break;
E 2
I 2
	case FVAR:
	    printf("(function variable) %s : ", s->symbol);
	    printtype(s, s->type);
	    break;
E 2

D 2
		case FIELD:
			printf("(field) %s : ", s->symbol);
			printtype(s, s->type);
			break;
E 2
I 2
	case FIELD:
	    printf("(field) %s : ", s->symbol);
	    printtype(s, s->type);
	    break;
E 2

D 2
		case PROC:
			printf("procedure %s", s->symbol);
			listparams(s);
			break;
E 2
I 2
	case PROC:
	    printf("procedure %s", s->symbol);
	    listparams(s);
	    break;
E 2

D 2
		case PROG:
			printf("program %s", s->symbol);
			t = s->chain;
			if (t != NIL) {
				printf("(%s", t->symbol);
				for (t = t->chain; t != NIL; t = t->chain) {
					printf(", %s", t->symbol);
				}
				printf(")");
			}
			break;
E 2
I 2
	case PROG:
	    printf("program %s", s->symbol);
	    t = s->chain;
	    if (t != NIL) {
		printf("(%s", t->symbol);
		for (t = t->chain; t != NIL; t = t->chain) {
		    printf(", %s", t->symbol);
		}
		printf(")");
	    }
	    break;
E 2

D 2
		case FUNC:
			printf("function %s", s->symbol);
			listparams(s);
			printf(" : ");
			printtype(s, s->type);
			break;
E 2
I 2
	case FUNC:
	    printf("function %s", s->symbol);
	    listparams(s);
	    printf(" : ");
	    printtype(s, s->type);
	    break;
E 2

D 2
		default:
			error("class %s in printdecl", classname(s));
	}
	if (semicolon) {
		putchar(';');
	}
	putchar('\n');
E 2
I 2
	default:
	    error("class %s in printdecl", classname(s));
    }
    if (semicolon) {
	putchar(';');
    }
    putchar('\n');
E 2
}

/*
 * Recursive whiz-bang procedure to print the type portion
 * of a declaration.  Doesn't work quite right for variant records.
 *
 * The symbol associated with the type is passed to allow
 * searching for type names without getting "type blah = blah".
 */

LOCAL printtype(s, t)
SYM *s;
SYM *t;
{
D 2
	register SYM *tmp;
E 2
I 2
    register SYM *tmp;
    long r0, r1;
E 2

D 2
	tmp = findtype(t);
	if (tmp != NIL && tmp != s) {
		printf("%s", tmp->symbol);
		return;
	}
	switch(t->class) {
		case VAR:
		case CONST:
		case FUNC:
		case PROC:
			panic("printtype: class %s", classname(t));
			break;
E 2
I 2
    tmp = findtype(t);
    if (tmp != NIL && tmp != s) {
	printf("%s", tmp->symbol);
	return;
    }
    switch(t->class) {
	case VAR:
	case CONST:
	case FUNC:
	case PROC:
	    panic("printtype: class %s", classname(t));
	    break;
E 2

D 2
		case ARRAY:
			printf("array[");
			tmp = t->chain;
			for (;;) {
				printtype(tmp, tmp);
				tmp = tmp->chain;
				if (tmp == NIL) {
					break;
				}
				printf(", ");
			}
			printf("] of ");
			printtype(t, t->type);
			break;
E 2
I 2
	case ARRAY:
	    printf("array[");
	    tmp = t->chain;
	    for (;;) {
		printtype(tmp, tmp);
		tmp = tmp->chain;
		if (tmp == NIL) {
		    break;
		}
		printf(", ");
	    }
	    printf("] of ");
	    printtype(t, t->type);
	    break;
E 2

D 2
		case RECORD:
			printf("record\n");
			if (t->chain != NIL) {
				printtype(t->chain, t->chain);
			}
			printf("end");
			break;
E 2
I 2
	case RECORD:
	    printf("record\n");
	    if (t->chain != NIL) {
		printtype(t->chain, t->chain);
	    }
	    printf("end");
	    break;
E 2

D 2
		case FIELD:
			if (t->chain != NIL) {
				printtype(t->chain, t->chain);
			}
			printf("\t%s : ", t->symbol);
			printtype(t, t->type);
			printf(";\n");
			break;
E 2
I 2
	case FIELD:
	    if (t->chain != NIL) {
		printtype(t->chain, t->chain);
	    }
	    printf("\t%s : ", t->symbol);
	    printtype(t, t->type);
	    printf(";\n");
	    break;
E 2

D 2
		case RANGE: {
			long r0, r1;
E 2
I 2
	case RANGE:
	    r0 = t->symvalue.rangev.lower;
	    r1 = t->symvalue.rangev.upper;
	    printordinal(r0, rtype(t->type));
	    printf("..");
	    printordinal(r1, rtype(t->type));
	    break;
E 2

D 2
			r0 = t->symvalue.rangev.lower;
			r1 = t->symvalue.rangev.upper;
			if (t == t_char) {
				printf("'%c'..'%c'", (char) r0, (char) r1);
			} else {
				printf("%ld..%ld", r0, r1);
			}
			break;
		}
E 2
I 2
	case PTR:
	    putchar('^');
	    printtype(t, t->type);
	    break;
E 2

D 2
		case PTR:
			putchar('^');
			printtype(t, t->type);
			break;
E 2
I 2
	case TYPE:
	    if (t->symbol != NIL) {
		printf("%s", t->symbol);
	    } else {
		printtype(t, t->type);
	    }
	    break;
E 2

D 2
		case TYPE:
			if (t->symbol != NIL) {
				printf("%s", t->symbol);
			} else {
				printtype(t, t->type);
			}
			break;
E 2
I 2
	case SCAL:
	    printf("(");
	    t = t->type->chain;
	    if (t != NIL) {
		printf("%s", t->symbol);
		t = t->chain;
		while (t != NIL) {
		    printf(", %s", t->symbol);
		    t = t->chain;
		}
	    } else {
		panic("empty enumeration");
	    }
	    printf(")");
	    break;
E 2

D 2
		case SCAL:
			printf("(");
			t = t->type->chain;
			if (t != NIL) {
				printf("%s", t->symbol);
				t = t->chain;
				while (t != NIL) {
					printf(", %s", t->symbol);
					t = t->chain;
				}
			} else {
				panic("empty enumeration");
			}
			printf(")");
			break;

		default:
			printf("(class %d)", t->class);
			break;
	}
E 2
I 2
	default:
	    printf("(class %d)", t->class);
	    break;
    }
E 2
}

/*
 * List the parameters of a procedure or function.
 * No attempt is made to combine like types.
 */

listparams(s)
SYM *s;
{
D 2
	SYM *t;
E 2
I 2
    SYM *t;
E 2

D 2
	if (s->chain != NIL) {
		putchar('(');
		for (t = s->chain; t != NIL; t = t->chain) {
			switch (t->class) {
				case REF:
					printf("var ");
					break;
E 2
I 2
    if (s->chain != NIL) {
	putchar('(');
	for (t = s->chain; t != NIL; t = t->chain) {
	    switch (t->class) {
		case REF:
		    printf("var ");
		    break;
E 2

D 2
				case FPROC:
					printf("procedure ");
					break;
E 2
I 2
		case FPROC:
		    printf("procedure ");
		    break;
E 2

D 2
				case FFUNC:
					printf("function ");
					break;
E 2
I 2
		case FFUNC:
		    printf("function ");
		    break;
E 2

D 2
				case VAR:
					break;
E 2
I 2
		case VAR:
		    break;
E 2

D 2
				default:
					panic("unexpected class %d for parameter", t->class);
			}
			printf("%s : ", t->symbol);
			printtype(t, t->type);
			if (t->chain != NIL) {
				printf("; ");
			}
		}
		putchar(')');
E 2
I 2
		default:
		    panic("unexpected class %d for parameter", t->class);
	    }
	    printf("%s : ", t->symbol);
	    printtype(t, t->type);
	    if (t->chain != NIL) {
		printf("; ");
	    }
E 2
	}
I 2
	putchar(')');
    }
E 2
}
E 1
