h11368
s 00077/00004/00225
d D 5.2 87/04/07 15:56:39 mckusick 9 8
c port to tahoe by Nir peleg of CCI
e
s 00008/00002/00221
d D 5.1 85/06/06 11:56:53 dist 8 7
c Add copyright
e
s 00042/00035/00181
d D 1.7 83/02/14 23:30:18 linton 7 6
c fixed problems with non-integer subranges
e
s 00002/00002/00214
d D 1.6 82/03/09 00:00:21 linton 6 5
c changed "printreal" to "prtreal" for 7-character name compatibility
e
s 00001/00001/00215
d D 1.5 82/03/08 18:57:20 linton 5 4
c fixed printing of booleans
e
s 00027/00001/00189
d D 1.4 82/02/17 00:31:40 linton 4 3
c changed the way reals are printed.
e
s 00119/00120/00071
d D 1.3 82/02/13 17:19:45 linton 3 2
c small elements are now stored in their exact size rather than 
c always as longs on the evaluation stack
e
s 00001/00001/00190
d D 1.2 82/01/19 00:09:16 linton 2 1
c assigning to strings, large expressions
e
s 00191/00000/00000
d D 1.1 82/01/18 19:21:19 linton 1 0
c date and time created 82/01/18 19:21:19 by linton
e
u
U
t
T
I 1
D 8
/* Copyright (c) 1982 Regents of the University of California */
E 8
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 8

D 8
static char sccsid[] = "%Z%%M% %I% %G%";
E 8
I 8
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8

/*
 * Print out the value at the top of the stack using the given type.
 */

#include "defs.h"
#include "sym.h"
#include "btypes.h"
#include "classes.h"
#include "tree.h"
#include "process.h"
#include "mappings.h"
#include "sym.rep"

printval(s)
SYM *s;
{
D 3
	SYM *t;
	ADDRESS a;
	int len;
E 3
I 3
    SYM *t;
    ADDRESS a;
    int len;
I 4
    double r;
E 4
E 3

D 3
	if (s->class == REF) {
		s = s->type;
	}
	switch(s->class) {
		case ARRAY:
			t = rtype(s->type);
			if (t==t_char || (t->class==RANGE && t->type==t_char)) {
				len = size(s);
				sp -= len;
D 2
				printf("'%s'", sp);
E 2
I 2
				printf("'%.*s'", len, sp);
E 2
				break;
			} else {
				printarray(s);
			}
			break;
E 3
I 3
    if (s->class == REF) {
	s = s->type;
    }
D 7
    switch(s->class) {
E 7
I 7
    switch (s->class) {
E 7
	case ARRAY:
	    t = rtype(s->type);
D 7
	    if (t==t_char || (t->class==RANGE && t->type==t_char)) {
E 7
I 7
	    if (t == t_char || (t->class == RANGE && t->type == t_char)) {
E 7
		len = size(s);
		sp -= len;
I 9
#ifdef tahoe
		downalignstack();
#endif
E 9
		printf("'%.*s'", len, sp);
		break;
	    } else {
		printarray(s);
	    }
	    break;
E 3

D 3
		case RECORD:
			printrecord(s);
			break;
E 3
I 3
	case RECORD:
	    printrecord(s);
	    break;
E 3

D 3
		case VARNT:
			error("can't print out variant records");
			break;
E 3
I 3
	case VARNT:
	    error("can't print out variant records");
	    break;
E 3

D 3
		case RANGE:
			if (s == t_real) {
				printf("%g", pop(double));
			} else if (s == t_char) {
				printf("'%c'", pop(long));
			} else if (s == t_boolean) {
				printf(pop(BOOLEAN)==TRUE ? "true" : "false");
			} else {
				printf("%ld", pop(long));
			}
			break;
E 3
I 3
	case RANGE:
	    if (s == t_real) {
D 4
		printf("%g", pop(double));
E 4
I 4
D 6
		printreal(pop(double));
E 6
I 6
		prtreal(pop(double));
E 6
E 4
D 7
	    } else if (s == t_char) {
		printf("'%c'", pop(char));
	    } else if (s == t_boolean) {
D 5
		printf(pop(BOOLEAN)==TRUE ? "true" : "false");
E 5
I 5
		printf(popsmall(s) == TRUE ? "true" : "false");
E 7
E 5
	    } else {
D 7
		printf("%ld", popsmall(s));
E 7
I 7
		printordinal(popsmall(s), rtype(s->type));
E 7
	    }
	    break;
E 3

D 3
		case FILET:
		case PTR: {
			ADDRESS addr;
E 3
I 3
	case FILET:
D 7
	case PTR: {
	    ADDRESS addr;
E 3

D 3
			addr = pop(ADDRESS);
			if (addr == 0) {
				printf("nil");
			} else {
				printf("0%o", addr);
			}
			break;
		}
E 3
I 3
	    addr = pop(ADDRESS);
	    if (addr == 0) {
E 7
I 7
	case PTR:
	    a = pop(ADDRESS);
	    if (a == 0) {
E 7
		printf("nil");
	    } else {
D 7
		printf("0%o", addr);
E 7
I 7
		printf("0%o", a);
E 7
	    }
	    break;
D 7
	}
E 7
E 3

D 3
		case FIELD:
			error("missing record specification");
			break;
E 3
I 3
	case FIELD:
	    error("missing record specification");
	    break;
E 3

D 3
		case SCAL: {
			int scalar;
			BOOLEAN found;
E 3
I 3
D 7
	case SCAL: {
	    int scalar;
	    BOOLEAN found;
E 3

D 3
			scalar = pop(long);
			found = FALSE;
			for (t = s->chain; t != NIL; t = t->chain) {
				if (t->symvalue.iconval == scalar) {
					printf("%s", t->symbol);
					found = TRUE;
					break;
				}
			}
			if (!found) {
				printf("(scalar = %d)", scalar);
			}
			break;
E 3
I 3
	    scalar = popsmall(s);
	    found = FALSE;
	    for (t = s->chain; t != NIL; t = t->chain) {
		if (t->symvalue.iconval == scalar) {
		    printf("%s", t->symbol);
		    found = TRUE;
		    break;
E 3
		}
I 3
	    }
	    if (!found) {
		printf("(scalar = %d)", scalar);
	    }
E 7
I 7
	case SCAL:
	    printordinal(popsmall(s), s);
E 7
	    break;
D 7
	}
E 7
E 3

D 3
		case FPROC:
		case FFUNC:
		{
			ADDRESS a;
E 3
I 3
	case FPROC:
	case FFUNC:
D 7
	{
	    ADDRESS a;
E 3

E 7
D 3
			a = fparamaddr(pop(long));
			t = whatblock(a);
			if (t == NIL) {
				printf("(proc %d)", a);
			} else {
				printf("%s", t->symbol);
			}
			break;
		}

		default:
			if (s->class < BADUSE || s->class > VARNT) {
				panic("printval: bad class %d", s->class);
			}
			error("don't know how to print a %s", classname(s));
			/* NOTREACHED */
E 3
I 3
	    a = fparamaddr(pop(long));
	    t = whatblock(a);
	    if (t == NIL) {
		printf("(proc %d)", a);
	    } else {
		printf("%s", t->symbol);
	    }
	    break;
E 3
D 7
	}
E 7
I 3

	default:
	    if (s->class < BADUSE || s->class > VARNT) {
		panic("printval: bad class %d", s->class);
	    }
	    error("don't know how to print a %s", classname(s));
	    /* NOTREACHED */
I 7
    }
}

/*
 * Print out an ordinal value (either an integer, character, or
 * an enumeration constant).
 */

printordinal(v, t)
long v;
SYM *t;
{
D 9
    BOOLEAN found;
E 9
    SYM *c;
    int iv;

    iv = v;
    if (t->class == SCAL) {
	c = t->chain;
	while (c != NIL && c->symvalue.iconval != iv) {
	    c = c->chain;
	}
	if (c == NIL) {
	    printf("(scalar = %d)", iv);
	} else {
	    printf("%s", c->symbol);
	}
    } else if (t == t_char) {
	printf("'%c'", iv);
    } else if (t == t_boolean) {
	printf("%s", (iv == TRUE) ? "true" : "false");
    } else {
	printf("%ld", v);
E 7
    }
E 3
}

/*
 * Print out the value of a record, field by field.
 */

LOCAL printrecord(s)
SYM *s;
{
D 3
	SYM *t;
E 3
I 3
    SYM *t;
E 3

D 3
	if ((t = s->chain) == NIL) {
		error("record has no fields");
	}
	printf("(");
	sp -= size(s);
	printfield(t);
	printf(")");
E 3
I 3
    if ((t = s->chain) == NIL) {
	error("record has no fields");
    }
    printf("(");
    sp -= size(s);
I 9
#ifdef tahoe
    downalignstack();
#endif
E 9
    printfield(t);
    printf(")");
E 3
}

/*
 * Print out a field, first printing out other fields.
 * This is done because the fields are chained together backwards.
 */

LOCAL printfield(s)
SYM *s;
{
D 3
	STACK *savesp;
E 3
I 3
    STACK *savesp;
E 3

D 3
	if (s->chain != NIL) {
		printfield(s->chain);
		printf(", ");
	}
	printf("%s = ", s->symbol);
	savesp = sp;
	sp += (s->symvalue.offset + size(s->type));
	alignstack();
	printval(s->type);
	sp = savesp;
E 3
I 3
    if (s->chain != NIL) {
	printfield(s->chain);
	printf(", ");
    }
    printf("%s = ", s->symbol);
    savesp = sp;
    sp += (s->symvalue.offset + size(s->type));
I 9
#ifdef tahoe
    alignstack();
#endif
E 9
    printval(s->type);
    sp = savesp;
E 3
}

/*
 * Print out the contents of an array.
 * Haven't quite figured out what the best format is.
 *
 * This is rather inefficient.
 *
 * The "2*elsize" is there since "printval" drops the stack by elsize.
 */

I 9
#ifdef tahoe
E 9
LOCAL printarray(a)
SYM *a;
{
D 3
	STACK *savesp, *newsp;
	SYM *eltype;
	long elsize;
E 3
I 3
    STACK *savesp, *newsp;
    SYM *eltype;
    long elsize;
E 3

I 9
    savesp = (STACK *)(((int)sp + 3) & ~3);
    eltype = a->type;
    printf("(");
    elsize = size(eltype);
    if (eltype->class == ARRAY)
	savesp += elsize;
    if (elsize < sizeof(int)) {
	register char *cp = sp - ((size(a) + 3) & ~3);
	int psh;
	register char *cp1, *end = cp + size(a);
	register int savestack;

	while (cp < end) {
	    psh = 0;
	    cp1 = (char *)&psh + sizeof(int) - elsize;
	    while (cp1 < (char *)&psh + sizeof psh)
		*cp1++ = *cp++;
	    if (end - size(a) != cp - elsize) {
		printf(", ");
	    }
	    switch (elsize) {
		case sizeof(char):
		    savestack = *(char *)sp;
		    push(char, psh);
	    	    printval(eltype);
		    *(char *)sp = savestack;
		    break;
		case sizeof(short):
		    savestack = *(short *)sp;
		    push(short, psh);
	    	    printval(eltype);
		    *(short *)sp = savestack;
		    break;
		default:
		   panic("bad size on runtime stack");
	    }
	}
    } else {
	sp -= size(a);
	downalignstack();
	newsp = sp;
	for (sp += elsize, alignstack(); sp <= savesp; sp += 2*elsize) {
	    if (sp - 2*elsize >= newsp) {
		printf(", ");
	    }
	    printval(eltype);
	    if (eltype->class == ARRAY) {
		sp -= elsize;
	    }
	}
	sp = newsp;
    }
    printf(")");
}
#else

LOCAL printarray(a)
SYM *a;
{
    STACK *savesp, *newsp;
    SYM *eltype;
    long elsize;

E 9
D 3
	savesp = sp;
	sp -= size(a);
	newsp = sp;
	eltype = a->type;
	elsize = size(eltype);
	printf("(");
	for (sp += elsize; sp <= savesp; sp += 2*elsize) {
		if (sp - elsize != newsp) {
			printf(", ");
		}
		printval(eltype);
E 3
I 3
    savesp = sp;
D 9
    sp -= size(a);
    newsp = sp;
E 9
    eltype = a->type;
    elsize = size(eltype);
I 9
    sp -= size(a);
    newsp = sp;
E 9
    printf("(");
    for (sp += elsize; sp <= savesp; sp += 2*elsize) {
	if (sp - elsize != newsp) {
	    printf(", ");
E 3
	}
D 3
	sp = newsp;
	printf(")");
E 3
I 3
	printval(eltype);
    }
    sp = newsp;
    printf(")");
I 4
}
I 9
#endif tahoe
E 9

/*
 * Print out the value of a real number.
 * Pascal notation is somewhat different that what one gets
 * from "%g" in printf.
 */

D 6
LOCAL printreal(r)
E 6
I 6
LOCAL prtreal(r)
E 6
double r;
{
    extern char *index();
D 9
    char *p, buf[256];
E 9
I 9
    char buf[256];
E 9

    sprintf(buf, "%g", r);
    if (buf[0] == '.') {
	printf("0%s", buf);
    } else if (buf[0] == '-' && buf[1] == '.') {
	printf("-0%s", &buf[1]);
    } else {
	printf("%s", buf);
    }
    if (index(buf, '.') == NIL) {
	printf(".0");
    }
E 4
E 3
}
E 1
