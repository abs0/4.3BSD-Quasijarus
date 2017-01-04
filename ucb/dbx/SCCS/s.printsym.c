h08399
s 00022/00009/00757
d D 5.5 88/01/12 01:08:45 donn 20 19
c merge in latest Linton version
e
s 00009/00001/00757
d D 5.4 86/09/01 12:24:35 sam 19 18
c stop printing a string after 4 non-ascii characters are recognized; 
c correct printchar to mask sign-extended char before printing in octal
e
s 00001/00001/00757
d D 5.3 86/03/05 09:44:54 sam 18 17
c put back default printing language as c (so expressions et. al. work)
e
s 00007/00005/00751
d D 5.2 85/09/05 17:32:19 mckusick 17 16
c register printing (from Ralph Campbell)
e
s 00008/00002/00748
d D 5.1 85/05/31 10:13:51 dist 16 15
c Add copyright
e
s 00186/00039/00564
d D 1.14 85/03/01 20:28:10 linton 15 14
c update to version 3.0
e
s 00001/00003/00602
d D 1.13 84/06/23 11:42:51 sam 14 12
i 13
c merge linton branch delta trail
e
s 00050/00018/00555
d D 1.12.1.1 84/06/23 10:49:01 sam 13 12
c branch delta of linton changes from net.sources
e
s 00001/00001/00572
d D 1.12 83/08/10 04:18:51 linton 12 11
c forgot a newline in the last change (to psym)
e
s 00003/00000/00570
d D 1.11 83/08/10 03:46:12 linton 11 10
c changed psym to print out funcv.isinline attribute
e
s 00025/00023/00545
d D 1.10 83/08/05 21:34:57 linton 10 9
c changed psym for class PROG
e
s 00000/00001/00568
d D 1.9 83/08/05 03:52:04 linton 9 8
c undid last change -- whether or not to print a VARNT is 
c language dependent
e
s 00021/00005/00548
d D 1.8 83/08/05 03:47:55 linton 8 7
c changed should_print so that C unions (VARNTs) aren't printed
e
s 00018/00014/00535
d D 1.7 83/05/20 18:00:04 csvaf 7 6
c special cased printrtn for voids and printv for arrays
e
s 00001/00000/00548
d D 1.6 83/05/18 20:42:55 csvaf 6 5
c put back display of variable size in psym
e
s 00026/00003/00522
d D 1.5 83/05/18 20:35:51 csvaf 5 4
c print range type in psym, add common class
e
s 00001/00000/00524
d D 1.4 83/04/25 18:21:02 linton 4 3
c changed psym to print the size of variables
e
s 00017/00000/00507
d D 1.3 83/04/08 00:59:24 linton 3 2
c put an upper limit on the number of arguments to be printed 
c (just in the case the stack gets overwritten)
e
s 00001/00001/00506
d D 1.2 82/12/15 04:21:34 linton 2 1
c fixed @(#) stuff
e
s 00507/00000/00000
d D 1.1 82/12/15 04:08:25 linton 1 0
c date and time created 82/12/15 04:08:25 by linton
e
u
U
f b 
t
T
I 1
D 16
/* Copyright (c) 1982 Regents of the University of California */
E 16
I 16
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 16

D 2
static char sccsid[] = "@(#)%Z%%M% %I% %G%";
E 2
I 2
D 13
static char sccsid[] = "%Z%%M% %I% %G%";
E 13
I 13
D 14
static char sccsid[] = "@(#)printsym.c 1.12 8/10/83";
E 13
E 2

I 13
static char rcsid[] = "$Header: printsym.c,v 1.3 84/03/27 10:23:14 linton Exp $";
E 14
I 14
D 16
static	char sccsid[] = "%W% (Berkeley) %G%";
E 16
I 16
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 16
E 14

I 15
D 20
static char rcsid[] = "$Header: printsym.c,v 1.5 84/12/26 10:41:28 linton Exp $";
E 20
I 20
static char rcsid[] = "$Header: printsym.c,v 1.4 87/04/15 00:23:35 donn Exp $";
E 20

E 15
E 13
/*
 * Printing of symbolic information.
 */

#include "defs.h"
#include "symbols.h"
#include "languages.h"
#include "printsym.h"
#include "tree.h"
#include "eval.h"
#include "mappings.h"
#include "process.h"
#include "runtime.h"
#include "machine.h"
#include "names.h"
I 15
#include "keywords.h"
E 15
#include "main.h"
I 19
#include <ctype.h>
E 19

#ifndef public
#endif

/*
I 3
 * Maximum number of arguments to a function.
 * This is used as a check for the possibility that the stack has been
 * overwritten and therefore a saved argument pointer might indicate
 * to an absurdly large number of arguments.
 */

#define MAXARGSPASSED 20

/*
E 3
 * Return a pointer to the string for the name of the class that
 * the given symbol belongs to.
 */

private String clname[] = {
D 15
    "bad use", "constant", "type", "variable", "array", "fileptr",
    "record", "field", "procedure", "function", "funcvar",
E 15
I 15
D 20
    "bad use", "constant", "type", "variable", "array", "@dynarray",
    "@subarray", "fileptr", "record", "field",
E 20
I 20
    "bad use", "constant", "type", "variable", "array", "array",
    "dynarray", "subarray", "fileptr", "record", "field",
E 20
    "procedure", "function", "funcvar",
E 15
    "ref", "pointer", "file", "set", "range", "label", "withptr",
    "scalar", "string", "program", "improper", "variant",
D 5
    "procparam", "funcparam", "module", "typeref", "tag"
E 5
I 5
D 13
    "procparam", "funcparam", "module", "tag", "common", "typeref"
E 13
I 13
    "procparam", "funcparam", "module", "tag", "common", "extref", "typeref"
E 13
E 5
};

public String classname(s)
Symbol s;
{
    return clname[ord(s->class)];
}

/*
 * Note the entry of the given block, unless it's the main program.
 */

public printentry(s)
Symbol s;
{
    if (s != program) {
D 15
	printf("\nentering %s %s\n", classname(s), symname(s));
E 15
I 15
	printf("\nentering %s ", classname(s));
	printname(stdout, s);
	printf("\n");
E 15
    }
}

/*
 * Note the exit of the given block
 */

public printexit(s)
Symbol s;
{
    if (s != program) {
D 15
	printf("leaving %s %s\n\n", classname(s), symname(s));
E 15
I 15
	printf("leaving %s ", classname(s));
	printname(stdout, s);
	printf("\n\n");
E 15
    }
}

/*
 * Note the call of s from t.
 */

public printcall(s, t)
Symbol s, t;
{
D 15
    printf("calling %s", symname(s));
E 15
I 15
    printf("calling ");
    printname(stdout, s);
E 15
    printparams(s, nil);
D 15
    printf(" from %s %s\n", classname(t), symname(t));
E 15
I 15
    printf(" from %s ", classname(t));
    printname(stdout, t);
    printf("\n");
E 15
}

/*
 * Note the return from s.  If s is a function, print the value
 * it is returning.  This is somewhat painful, since the function
 * has actually just returned.
 */

public printrtn(s)
Symbol s;
{
    register Symbol t;
    register int len;
    Boolean isindirect;

    printf("returning ");
D 7
    if (s->class == FUNC) {
E 7
I 7
    if (s->class == FUNC && (!istypename(s->type,"void"))) {
E 7
	len = size(s->type);
	if (canpush(len)) {
	    t = rtype(s->type);
	    isindirect = (Boolean) (t->class == RECORD or t->class == VARNT);
	    pushretval(len, isindirect);
	    printval(s->type);
	    putchar(' ');
	} else {
	    printf("(value too large) ");
	}
    }
D 15
    printf("from %s\n", symname(s));
E 15
I 15
    printf("from ");
    printname(stdout, s);
    printf("\n");
E 15
}

/*
 * Print the values of the parameters of the given procedure or function.
 * The frame distinguishes recursive instances of a procedure.
I 13
 *
 * If the procedure or function is internal, the argument count is
 * not valid so we ignore it.
E 13
 */

public printparams(f, frame)
Symbol f;
Frame frame;
{
    Symbol param;
    int n, m, s;

    n = nargspassed(frame);
I 13
    if (isinternal(f)) {
	n = 0;
    }
I 15
    printf("(");
E 15
E 13
    param = f->chain;
    if (param != nil or n > 0) {
D 15
	printf("(");
E 15
	m = n;
	if (param != nil) {
	    for (;;) {
D 15
		s = size(param) div sizeof(Word);
E 15
I 15
		s = psize(param) div sizeof(Word);
E 15
		if (s == 0) {
		    s = 1;
		}
		m -= s;
D 15
		printv(param, frame);
E 15
I 15
		if (showaggrs) {
		    printv(param, frame);
		} else {
		    printparamv(param, frame);
		}
E 15
		param = param->chain;
	    if (param == nil) break;
		printf(", ");
	    }
	}
	if (m > 0) {
I 3
	    if (m > MAXARGSPASSED) {
		m = MAXARGSPASSED;
	    }
E 3
	    if (f->chain != nil) {
		printf(", ");
	    }
	    for (;;) {
		--m;
		printf("0x%x", argn(n - m, frame));
	    if (m <= 0) break;
		printf(", ");
	    }
	}
D 15
	printf(")");
E 15
    }
I 15
    printf(")");
E 15
}

/*
 * Test if a symbol should be printed.  We don't print files,
 * for example, simply because there's no good way to do it.
 * The symbol must be within the given function.
 */

public Boolean should_print(s)
Symbol s;
{
    Boolean b;
    register Symbol t;

    switch (s->class) {
	case VAR:
	case FVAR:
D 8
	    t = rtype(s->type);
	    b = (Boolean) (
		not isparam(s) and
		t != nil and t->class != FILET and t->class != SET
	    );
E 8
I 8
	    if (isparam(s)) {
		b = false;
	    } else {
		t = rtype(s->type);
		if (t == nil) {
		    b = false;
		} else {
		    switch (t->class) {
			case FILET:
			case SET:
D 9
			case VARNT:
E 9
			case BADUSE:
			    b = false;
			    break;

			default:
			    b = true;
			    break;
		    }
		}
	    }
E 8
	    break;

	default:
	    b = false;
	    break;
    }
    return b;
}

/*
I 15
 * Print out a parameter value.
 *
 * Since this is intended to be printed on a single line with other information
 * aggregate values are not printed.
 */

public printparamv (p, frame)
Symbol p;
Frame frame;
{
    Symbol t;

    t = rtype(p->type);
    switch (t->class) {
	case ARRAY:
I 20
	case OPENARRAY:
E 20
	case DYNARRAY:
	case SUBARRAY:
	    t = rtype(t->type);
	    if (compatible(t, t_char)) {
		printv(p, frame);
	    } else {
		printf("%s = (...)", symname(p));
	    }
	    break;

	case RECORD:
	    printf("%s = (...)", symname(p));
	    break;

	default:
	    printv(p, frame);
	    break;
    }
}

/*
E 15
 * Print the name and value of a variable.
 */

public printv(s, frame)
Symbol s;
Frame frame;
{
    Address addr;
    int len;
I 13
D 17
    Symbol t;
E 17
E 13

    if (isambiguous(s) and ismodule(container(s))) {
	printname(stdout, s);
	printf(" = ");
    } else {
	printf("%s = ", symname(s));
    }
D 7
    if (isvarparam(s)) {
	rpush(address(s, frame), sizeof(Address));
	addr = pop(Address);
	len = size(s->type);
E 7
I 7
D 13
    if(s->type->class == ARRAY && (! istypename(s->type->type,"char")) ) {
	printf(" ARRAY ");
E 13
I 13
D 15
/*
 * Not today.
    t = rtype(s->type);
    if (t->class == ARRAY and not istypename(t->type, "char")) {
	printf("ARRAY");
E 15
I 15
    if (isvarparam(s) and not isopenarray(s)) {
	rpush(address(s, frame), sizeof(Address));
	addr = pop(Address);
E 15
E 13
E 7
    } else {
I 13
D 15
 */
E 13
D 7
	addr = address(s, frame);
	len = size(s);
    }
    if (canpush(len)) {
	rpush(addr, len);
	printval(s->type);
    } else {
	printf("*** expression too large ***");
    }
E 7
I 7
       if (isvarparam(s)) {
	   rpush(address(s, frame), sizeof(Address));
	   addr = pop(Address);
	   len = size(s->type);
       } else {
	   addr = address(s, frame);
	   len = size(s);
       }
       if (canpush(len)) {
	   rpush(addr, len);
	   printval(s->type);
       } else {
	   printf("*** expression too large ***");
       }
I 13
/*
 * Matches brace commented out above.
E 13
   }
I 13
 */
E 15
I 15
	addr = address(s, frame);
    }
    len = size(s);
D 17
    if (canpush(len)) {
	rpush(addr, len);
E 17
I 17
    if (not canpush(len)) {
	printf("*** expression too large ***");
    } else if (isreg(s)) {
	push(Address, addr);
E 17
	printval(s->type);
    } else {
D 17
	printf("*** expression too large ***");
E 17
I 17
	rpush(addr, len);
	printval(s->type);
E 17
    }
E 15
E 13
E 7
}

/*
 * Print out the name of a symbol.
 */

public printname(f, s)
File f;
Symbol s;
{
    if (s == nil) {
	fprintf(f, "(noname)");
I 13
    } else if (s == program) {
	fprintf(f, ".");
E 13
    } else if (isredirected() or isambiguous(s)) {
	printwhich(f, s);
    } else {
	fprintf(f, "%s", symname(s));
    }
}

/*
 * Print the fully specified variable that is described by the given identifer.
 */

public printwhich(f, s)
File f;
Symbol s;
{
    printouter(f, container(s));
    fprintf(f, "%s", symname(s));
}

/*
 * Print the fully qualified name of each symbol that has the same name
 * as the given symbol.
 */

public printwhereis(f, s)
File f;
Symbol s;
{
    register Name n;
    register Symbol t;

    checkref(s);
    n = s->name;
    t = lookup(n);
    printwhich(f, t);
    t = t->next_sym;
    while (t != nil) {
	if (t->name == n) {
	    putc(' ', f);
	    printwhich(f, t);
	}
	t = t->next_sym;
    }
    putc('\n', f);
}

private printouter(f, s)
File f;
Symbol s;
{
    Symbol outer;

    if (s != nil) {
	outer = container(s);
	if (outer != nil and outer != program) {
	    printouter(f, outer);
	}
	fprintf(f, "%s.", symname(s));
    }
}

public printdecl(s)
Symbol s;
{
I 15
    Language lang;

E 15
    checkref(s);
D 15
    (*language_op(s->language, L_PRINTDECL))(s);
E 15
I 15
    if (s->language == nil or s->language == primlang) {
	lang = findlanguage(".s");
    } else {
	lang = s->language;
    }
    (*language_op(lang, L_PRINTDECL))(s);
E 15
}

/*
 * Straight dump of symbol information.
 */

public psym(s)
Symbol s;
{
    printf("name\t%s\n", symname(s));
    printf("lang\t%s\n", language_name(s->language));
    printf("level\t%d\n", s->level);
    printf("class\t%s\n", classname(s));
    printf("type\t0x%x", s->type);
    if (s->type != nil and s->type->name != nil) {
	printf(" (%s)", symname(s->type));
    }
    printf("\nchain\t0x%x", s->chain);
    if (s->chain != nil and s->chain->name != nil) {
	printf(" (%s)", symname(s->chain));
    }
    printf("\nblock\t0x%x", s->block);
D 20
    if (s->block->name != nil) {
E 20
I 20
    if (s->block != nil and s->block->name != nil) {
E 20
	printf(" (");
	printname(stdout, s->block);
	putchar(')');
    }
    putchar('\n');
    switch (s->class) {
I 15
	case TYPE:
	    printf("size\t%d\n", size(s));
	    break;

E 15
	case VAR:
	case REF:
D 20
	    if (s->level >= 3) {
		printf("address\t0x%x\n", s->symvalue.offset);
	    } else {
		printf("offset\t%d\n", s->symvalue.offset);
E 20
I 20
	    switch (s->storage) {
		case INREG:
		    printf("reg\t%d\n", s->symvalue.offset);
		    break;

		case STK:
		    printf("offset\t%d\n", s->symvalue.offset);
		    break;

		case EXT:
		    printf("address\t0x%x\n", s->symvalue.offset);
		    break;
E 20
	    }
I 6
	    printf("size\t%d\n", size(s));
E 6
I 4
D 5
	    printf("size\t%d\n", size(s));
E 5
E 4
	    break;

	case RECORD:
	case VARNT:
	    printf("size\t%d\n", s->symvalue.offset);
	    break;

	case FIELD:
	    printf("offset\t%d\n", s->symvalue.field.offset);
	    printf("size\t%d\n", s->symvalue.field.length);
	    break;

I 10
	case PROG:
E 10
	case PROC:
	case FUNC:
	    printf("address\t0x%x\n", s->symvalue.funcv.beginaddr);
I 11
	    if (isinline(s)) {
D 12
		printf("inline procedure");
E 12
I 12
		printf("inline procedure\n");
E 12
	    }
E 11
I 3
	    if (nosource(s)) {
		printf("does not have source information\n");
	    } else {
		printf("has source information\n");
	    }
E 3
	    break;

	case RANGE:
I 5
D 10
            switch(s->symvalue.rangev.lowertype) {
E 10
D 13

E 13
D 10
	      case R_CONST :  printf("CONST");
		              break;
	      case R_ARG :    printf("ARG");
			      break;
	      case R_TEMP :   printf("TEMP");
			      break;
	      case R_ADJUST : printf("ADJUST");
			      break;
            }
E 10
I 10
	    prangetype(s->symvalue.rangev.lowertype);
E 10
E 5
	    printf("lower\t%d\n", s->symvalue.rangev.lower);
I 5
D 10

            switch(s->symvalue.rangev.uppertype) {

	      case R_CONST :  printf("CONST");
		              break;
	      case R_ARG :    printf("ARG");
			      break;
	      case R_TEMP :   printf("TEMP");
			      break;
	      case R_ADJUST : printf("ADJUST");
			      break;
            }

E 10
I 10
	    prangetype(s->symvalue.rangev.uppertype);
E 10
E 5
	    printf("upper\t%d\n", s->symvalue.rangev.upper);
	    break;

	default:
	    /* do nothing */
I 10
	    break;
    }
}

private prangetype(r)
Rangetype r;
{
    switch (r) {
	case R_CONST:
	    printf("CONST");
	    break;

	case R_ARG:
	    printf("ARG");
	    break;

	case R_TEMP:
	    printf("TEMP");
	    break;

	case R_ADJUST:
	    printf("ADJUST");
E 10
	    break;
    }
}

/*
 * Print out the value on top of the stack according to the given type.
 */

public printval(t)
Symbol t;
{
    Symbol s;

    checkref(t);
I 13
    if (t->class == TYPEREF) {
	resolveRef(t);
    }
E 13
    switch (t->class) {
	case PROC:
	case FUNC:
	    s = pop(Symbol);
	    printf("%s", symname(s));
	    break;

	default:
D 15
	    if (t->language == nil) {
		error("unknown language");
I 13
	    } else if (t->language == primlang) {
E 15
I 15
	    if (t->language == nil or t->language == primlang) {
E 15
D 17
		(*language_op(findlanguage(".c"), L_PRINTVAL))(t);
E 17
I 17
D 18
		(*language_op(findlanguage(".s"), L_PRINTVAL))(t);
E 18
I 18
		(*language_op(findlanguage(".c"), L_PRINTVAL))(t);
E 18
E 17
E 13
	    } else {
		(*language_op(t->language, L_PRINTVAL))(t);
	    }
	    break;
    }
}

/*
 * Print out the value of a record, field by field.
 */

public printrecord(s)
Symbol s;
{
I 13
    Symbol f;

E 13
    if (s->chain == nil) {
	error("record has no fields");
    }
    printf("(");
    sp -= size(s);
D 13
    printfield(s->chain);
E 13
I 13
    f = s->chain;
    if (f != nil) {
	for (;;) {
	    printfield(f);
	    f = f->chain;
	if (f == nil) break;
	    printf(", ");
	}
    }
E 13
    printf(")");
}

/*
D 13
 * Print out a field, first printing out other fields.
 * This is done because the fields are chained together backwards.
E 13
I 13
 * Print out a field.
E 13
 */

D 13
private printfield(s)
Symbol s;
E 13
I 13
private printfield(f)
Symbol f;
E 13
{
    Stack *savesp;
I 13
    register int off, len;
E 13

D 13
    if (s->chain != nil) {
	printfield(s->chain);
	printf(", ");
    }
    printf("%s = ", symname(s));
E 13
I 13
    printf("%s = ", symname(f));
E 13
    savesp = sp;
D 13
    sp += ((s->symvalue.field.offset div BITSPERBYTE) + size(s->type));
    printval(s);
E 13
I 13
    off = f->symvalue.field.offset;
    len = f->symvalue.field.length;
    sp += ((off + len + BITSPERBYTE - 1) div BITSPERBYTE);
    printval(f);
E 13
    sp = savesp;
}

/*
 * Print out the contents of an array.
 * Haven't quite figured out what the best format is.
 *
 * This is rather inefficient.
 *
 * The "2*elsize" is there since "printval" drops the stack by elsize.
 */

public printarray(a)
Symbol a;
{
    Stack *savesp, *newsp;
    Symbol eltype;
    long elsize;
    String sep;

    savesp = sp;
D 5
    sp -= size(a);
E 5
I 5
    sp -= (size(a));
E 5
    newsp = sp;
    eltype = rtype(a->type);
    elsize = size(eltype);
    printf("(");
    if (eltype->class == RECORD or eltype->class == ARRAY or
      eltype->class == VARNT) {
	sep = "\n";
	putchar('\n');
    } else {
	sep = ", ";
    }
    for (sp += elsize; sp <= savesp; sp += 2*elsize) {
	if (sp - elsize != newsp) {
	    fputs(sep, stdout);
	}
	printval(eltype);
    }
    sp = newsp;
    if (streq(sep, "\n")) {
	putchar('\n');
    }
    printf(")");
}

/*
 * Print out the value of a real number in Pascal notation.
 * This is, unfortunately, different than what one gets
 * from "%g" in printf.
 */

public prtreal(r)
double r;
{
    extern char *index();
    char buf[256];

D 20
    sprintf(buf, "%g", r);
E 20
I 20
#   ifdef IRIS
	sprintf(buf, "%lg", r);
#   else
	sprintf(buf, "%g", r);
#   endif
E 20
    if (buf[0] == '.') {
	printf("0%s", buf);
    } else if (buf[0] == '-' and buf[1] == '.') {
	printf("-0%s", &buf[1]);
    } else {
	printf("%s", buf);
    }
    if (index(buf, '.') == nil) {
	printf(".0");
    }
}

/*
 * Print out a character using ^? notation for unprintables.
 */

public printchar(c)
char c;
{
    if (c == 0) {
	putchar('\\');
	putchar('0');
    } else if (c == '\n') {
	putchar('\\');
	putchar('n');
    } else if (c > 0 and c < ' ') {
	putchar('^');
	putchar(c - 1 + 'A');
D 13
    } else {
E 13
I 13
    } else if (c >= ' ' && c <= '~') {
E 13
	putchar(c);
I 13
    } else {
D 19
	printf("\\0%o",c);
E 19
I 19
	printf("\\0%o",c&0xff);
E 19
I 15
    }
}

/*
 * Print out a value for a range type (integer, char, or boolean).
 */

public printRangeVal (val, t)
long val;
Symbol t;
{
    if (t == t_boolean->type or istypename(t->type, "boolean")) {
	if ((boolean) val) {
	    printf("true");
	} else {
	    printf("false");
	}
    } else if (t == t_char->type or istypename(t->type, "char")) {
	if (varIsSet("$hexchars")) {
	    printf("0x%lx", val);
	} else {
	    putchar('\'');
	    printchar(val);
	    putchar('\'');
	}
    } else if (varIsSet("$hexints")) {
	printf("0x%lx", val);
    } else if (t->symvalue.rangev.lower >= 0) {
	printf("%lu", val);
    } else {
	printf("%ld", val);
    }
}

/*
 * Print out an enumerated value by finding the corresponding
 * name in the enumeration list.
 */

public printEnum (i, t)
integer i;
Symbol t;
{
    register Symbol e;

    e = t->chain;
    while (e != nil and e->symvalue.constval->value.lcon != i) {
	e = e->chain;
    }
    if (e != nil) {
	printf("%s", symname(e));
    } else {
	printf("%d", i);
    }
}

/*
 * Print out a null-terminated string (pointer to char)
 * starting at the given address.
 */

public printString (addr, quotes)
Address addr;
boolean quotes;
{
    register Address a;
    register integer i, len;
    register boolean endofstring;
I 19
    register int unprintables;
#define	MAXGARBAGE	4
E 19
    union {
	char ch[sizeof(Word)];
	int word;
    } u;

    if (varIsSet("$hexstrings")) {
	printf("0x%x", addr);
    } else {
	if (quotes) {
	    putchar('"');
	}
	a = addr;
I 19
	unprintables = 0;
E 19
	endofstring = false;
	while (not endofstring) {
	    dread(&u, a, sizeof(u));
	    i = 0;
	    do {
		if (u.ch[i] == '\0') {
		    endofstring = true;
		} else {
		    printchar(u.ch[i]);
I 19
		    if (!isascii(u.ch[i]) and ++unprintables > MAXGARBAGE) {
			endofstring = true;
			printf("...");
		    }
E 19
		}
		++i;
	    } while (i < sizeof(Word) and not endofstring);
	    a += sizeof(Word);
	}
	if (quotes) {
	    putchar('"');
	}
E 15
E 13
    }
}
E 1
