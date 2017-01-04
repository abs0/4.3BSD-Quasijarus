h63225
s 00010/00013/00654
d D 5.4 88/01/12 00:36:48 donn 11 10
c merge in latest Linton version
e
s 00034/00010/00633
d D 5.3 86/01/10 16:26:41 donn 10 9
c Distinguish logical and logical*2 types, and print both types correctly;
c print dummy procedures and parameter variables more-or-less correctly.
e
s 00011/00001/00632
d D 5.2 85/09/05 15:51:16 mckusick 9 8
c fix from jerry
e
s 00008/00002/00625
d D 5.1 85/05/31 09:59:57 dist 8 7
c Add copyright
e
s 00039/00023/00588
d D 1.6 85/03/01 20:23:20 linton 7 6
c update to version 3.0
e
s 00001/00003/00610
d D 1.5 84/06/23 11:40:42 sam 6 4
i 5
c merge linton branch delta trail
e
s 00046/00020/00567
d D 1.4.1.1 84/06/23 10:46:25 sam 5 4
c branch delta of linton changes from net.sources
e
s 00011/00010/00576
d D 1.4 83/08/16 00:54:59 linton 4 3
c changed "source file %s.c" to "... %s.f"
e
s 00002/00002/00584
d D 1.3 83/05/20 17:58:29 csvaf 3 2
c subroutines become void functions so printrtn won't 
c print a return value; fixed getbound bug
e
s 00004/00000/00582
d D 1.2 83/05/18 23:25:27 csvaf 2 1
c added sccs id
e
s 00582/00000/00000
d D 1.1 83/05/18 23:09:54 csvaf 1 0
c date and time created 83/05/18 23:09:54 by csvaf
e
u
U
f b 
t
T
I 2
D 8
/* Copyright (c) 1982 Regents of the University of California */
E 8
I 8
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 8

D 5
static char sccsid[] = "%W%	%G%";
E 5
I 5
D 6
static char sccsid[] = "@(#)fortran.c	1.3	5/20/83";
E 5

I 5
static char rcsid[] = "$Header: fortran.c,v 1.3 84/03/27 10:20:53 linton Exp $";
E 6
I 6
D 8
static	char sccsid[] = "%W% (Berkeley) %G%";
E 8
I 8
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8
E 6

I 7
D 11
static char rcsid[] = "$Header: fortran.c,v 1.5 84/12/26 10:39:37 linton Exp $";
E 11
I 11
static char rcsid[] = "$Header: fortran.c,v 1.3 87/03/25 20:00:03 donn Exp $";
E 11

E 7
E 5
E 2
I 1
/*
 * FORTRAN dependent symbol routines.
 */

#include "defs.h"
#include "symbols.h"
#include "printsym.h"
#include "languages.h"
#include "fortran.h"
#include "tree.h"
#include "eval.h"
#include "operators.h"
#include "mappings.h"
#include "process.h"
#include "runtime.h"
#include "machine.h"

D 10
#define isfloat(range) ( \
E 10
I 10
#define isspecial(range) ( \
E 10
    range->symvalue.rangev.upper == 0 and range->symvalue.rangev.lower > 0 \
)

#define isrange(t, name) (t->class == RANGE and istypename(t->type, name))

#define MAXDIM  20
I 5

private Language fort;

E 5
/*
 * Initialize FORTRAN language information.
 */

public fortran_init()
{
D 5
    Language lang;

    lang = language_define("fortran", ".f");
    language_setop(lang, L_PRINTDECL, fortran_printdecl);
    language_setop(lang, L_PRINTVAL, fortran_printval);
    language_setop(lang, L_TYPEMATCH, fortran_typematch);
    language_setop(lang, L_BUILDAREF, fortran_buildaref);
    language_setop(lang, L_EVALAREF, fortran_evalaref);
E 5
I 5
    fort = language_define("fortran", ".f");
    language_setop(fort, L_PRINTDECL, fortran_printdecl);
    language_setop(fort, L_PRINTVAL, fortran_printval);
    language_setop(fort, L_TYPEMATCH, fortran_typematch);
    language_setop(fort, L_BUILDAREF, fortran_buildaref);
    language_setop(fort, L_EVALAREF, fortran_evalaref);
    language_setop(fort, L_MODINIT, fortran_modinit);
    language_setop(fort, L_HASMODULES, fortran_hasmodules);
    language_setop(fort, L_PASSADDR, fortran_passaddr);
E 5
}

/*
 * Test if two types are compatible.
 *
 * Integers and reals are not compatible since they cannot always be mixed.
 */

public Boolean fortran_typematch(type1, type2)
Symbol type1, type2;
{

/* only does integer for now; may need to add others
*/

    Boolean b;
    register Symbol t1, t2, tmp;

    t1 = rtype(type1);
    t2 = rtype(type2);
    if(t1 == nil or t1->type == nil or t2 == nil or t2->type == nil ) b = false;
    else { b = (Boolean)   (
            (t1 == t2)  or 
	    (t1->type == t_int and (istypename(t2->type, "integer") or
                                    istypename(t2->type, "integer*2"))  ) or
	    (t2->type == t_int and (istypename(t1->type, "integer") or
                                    istypename(t1->type, "integer*2"))  ) 
                    );
         }
    /*OUT fprintf(stderr," %d compat %s %s \n", b,
      (t1 == nil or t1->type == nil ) ? "nil" : symname(t1->type),
      (t2 == nil or t2->type == nil ) ? "nil" : symname(t2->type)  );*/
    return b;
}

private String typename(s)
Symbol s;
{
int ub;
static char buf[20];
char *pbuf;
Symbol st,sc;

     if(s->type->class == TYPE) return(symname(s->type));

     for(st = s->type; st->type->class != TYPE; st = st->type);

     pbuf=buf;

     if(istypename(st->type,"char"))  { 
	  sprintf(pbuf,"character*");
          pbuf += strlen(pbuf);
	  sc = st->chain;
          if(sc->symvalue.rangev.uppertype == R_ARG or
             sc->symvalue.rangev.uppertype == R_TEMP) {
	      if( ! getbound(s,sc->symvalue.rangev.upper, 
                    sc->symvalue.rangev.uppertype, &ub) )
		sprintf(pbuf,"(*)");
	      else 
		sprintf(pbuf,"%d",ub);
          }
 	  else sprintf(pbuf,"%d",sc->symvalue.rangev.upper);
     }
     else {
          sprintf(pbuf,"%s ",symname(st->type));
     }
     return(buf);
}

private Symbol mksubs(pbuf,st)
Symbol st;
char  **pbuf;
{   
   int lb, ub;
   Symbol r, eltype;

   if(st->class != ARRAY or (istypename(st->type, "char")) ) return;
   else {
          mksubs(pbuf,st->type);
          assert( (r = st->chain)->class == RANGE);

          if(r->symvalue.rangev.lowertype == R_ARG or
             r->symvalue.rangev.lowertype == R_TEMP) {
	      if( ! getbound(st,r->symvalue.rangev.lower, 
                    r->symvalue.rangev.lowertype, &lb) )
		sprintf(*pbuf,"?:");
	      else 
		sprintf(*pbuf,"%d:",lb);
	  }
          else {
		lb = r->symvalue.rangev.lower;
		sprintf(*pbuf,"%d:",lb);
		}
    	  *pbuf += strlen(*pbuf);

          if(r->symvalue.rangev.uppertype == R_ARG or
             r->symvalue.rangev.uppertype == R_TEMP) {
	      if( ! getbound(st,r->symvalue.rangev.upper, 
                    r->symvalue.rangev.uppertype, &ub) )
		sprintf(*pbuf,"?,");
	      else 
		sprintf(*pbuf,"%d,",ub);
	  }
          else {
		ub = r->symvalue.rangev.upper;
		sprintf(*pbuf,"%d,",ub);
		}
    	  *pbuf += strlen(*pbuf);

       }
}

/*
 * Print out the declaration of a FORTRAN variable.
 */

public fortran_printdecl(s)
Symbol s;
{
I 11
    Symbol eltype;
E 11

D 11

Symbol eltype;

E 11
    switch (s->class) {
I 5
D 11

E 11
E 5
D 4

E 4
	case CONST:
I 5
D 11
	    
E 11
E 5
D 4
	    
E 4
	    printf("parameter %s = ", symname(s));
I 10
	    eval(s->symvalue.constval);
E 10
            printval(s);
	    break;

        case REF:
            printf(" (dummy argument) ");
D 4

E 4
I 4
D 5
	    /* fall through */
E 4
	case VAR:
D 4
	    if (s->type->class == ARRAY &&
		 (not istypename(s->type->type,"char")) ) {
                char bounds[130], *p1, **p;
E 4
I 4
	    if (s->type->class == ARRAY and
	        (not istypename(s->type->type, "char"))
	    ) {
		char bounds[130], *p1, **p;
E 5

I 5
	case VAR:
	    if (s->type->class == ARRAY &&
		 (not istypename(s->type->type,"char")) ) {
                char bounds[130], *p1, **p;
E 5
E 4
		p1 = bounds;
                p = &p1;
D 4
                mksubs(p,s->type);
E 4
I 4
D 5
                mksubs(p, s->type);
E 5
I 5
                mksubs(p,s->type);
E 5
E 4
                *p -= 1; 
                **p = '\0';   /* get rid of trailing ',' */
D 4
		printf(" %s %s[%s] ",typename(s), symname(s), bounds);
E 4
I 4
D 5
		printf(" %s %s[%s] ", typename(s), symname(s), bounds);
E 5
I 5
		printf(" %s %s[%s] ",typename(s), symname(s), bounds);
E 5
E 4
	    } else {
		printf("%s %s", typename(s), symname(s));
	    }
	    break;

	case FUNC:
D 3
	    if (not istypename(s->type, "subroutine")) {
E 3
I 3
	    if (not istypename(s->type, "void")) {
E 3
                printf(" %s function ", typename(s) );
I 4
D 5
	    } else {
		printf(" subroutine");
E 5
E 4
	    }
I 5
	    else printf(" subroutine");
E 5
D 4
	    else printf(" subroutine");
E 4
	    printf(" %s ", symname(s));
	    fortran_listparams(s);
	    break;

	case MODULE:
D 4
	    printf("source file \"%s.c\"", symname(s));
E 4
I 4
D 5
	    printf("source file \"%s.f\"", symname(s));
E 5
I 5
	    printf("source file \"%s.c\"", symname(s));
E 5
E 4
	    break;

	case PROG:
	    printf("executable file \"%s\"", symname(s));
	    break;

	default:
	    error("class %s in fortran_printdecl", classname(s));
    }
    putchar('\n');
}

/*
 * List the parameters of a procedure or function.
 * No attempt is made to combine like types.
 */

public fortran_listparams(s)
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
	    if (t->class != REF) {
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

public fortran_printval(s)
Symbol s;
{
    register Symbol t;
    register Address a;
    register int i, len;
I 7
    double d1, d2;
E 7

D 7
    /* printf("fortran_printval with class %s \n",classname(s)); OUT*/
E 7
    switch (s->class) {
	case CONST:
	case TYPE:
	case VAR:
	case REF:
	case FVAR:
	case TAG:
	    fortran_printval(s->type);
	    break;

	case ARRAY:
	    t = rtype(s->type);
	    if (t->class == RANGE and istypename(t->type, "char")) {
		len = size(s);
		sp -= len;
		printf("\"%.*s\"", len, sp);
	    } else {
		fortran_printarray(s);
	    }
	    break;

	case RANGE:
D 10
	     if (isfloat(s)) {
E 10
I 10
D 11
	    if (isspecial(s)) {
E 11
I 11
	     if (isspecial(s)) {
E 11
E 10
		switch (s->symvalue.rangev.lower) {
I 10
		    case sizeof(short):
			if (istypename(s->type, "logical*2")) {
			    printlogical(pop(short));
			}
			break;

E 10
		    case sizeof(float):
D 10
			prtreal(pop(float));
E 10
I 10
			if (istypename(s->type, "logical")) {
			    printlogical(pop(long));
			} else {
			    prtreal(pop(float));
			}
E 10
			break;

		    case sizeof(double):
D 7
			if(istypename(s->type,"complex")) {
			   printf("(");
			prtreal(pop(float));
			   printf(",");
			prtreal(pop(float));
			   printf(")");
E 7
I 7
D 10
			if (istypename(s->type,"complex")) {
E 10
I 10
D 11
			if (istypename(s->type, "complex")) {
E 11
I 11
			if (istypename(s->type,"complex")) {
E 11
E 10
			    d2 = pop(float);
			    d1 = pop(float);
			    printf("(");
			    prtreal(d1);
			    printf(",");
			    prtreal(d2);
			    printf(")");
			} else {
			    prtreal(pop(double));
E 7
			}
D 7
			else prtreal(pop(double));
E 7
			break;

I 9
		    case 2*sizeof(double):
			d2 = pop(double);
			d1 = pop(double);
			printf("(");
			prtreal(d1);
			printf(",");
			prtreal(d2);
			printf(")");
			break;
D 11
		
E 11
I 11

E 11
E 9
		    default:
D 10
			panic("bad size \"%d\" for real",
E 10
I 10
			panic("bad size \"%d\" for special",
E 10
D 9
                                  t->symvalue.rangev.lower);
E 9
I 9
                                  s->symvalue.rangev.lower);
E 9
			break;
		}
	    } else {
		printint(popsmall(s), s);
	    }
	    break;

	default:
	    if (ord(s->class) > ord(TYPEREF)) {
		panic("printval: bad class %d", ord(s->class));
	    }
	    error("don't know how to print a %s", fortran_classname(s));
	    /* NOTREACHED */
    }
}

/*
I 10
 * Print out a logical
 */

D 11
private printlogical(i)
Integer i;
E 11
I 11
private printlogical (i)
integer i;
E 11
{
    if (i == 0) {
	printf(".false.");
    } else {
	printf(".true.");
    }
}

/*
E 10
 * Print out an int 
 */

private printint(i, t)
Integer i;
register Symbol t;
{
D 10
    if (istypename(t->type, "logical")) {
	printf(((Boolean) i) == true ? "true" : "false");
    }
    else if ( (t->type == t_int) or istypename(t->type, "integer") or
E 10
I 10
D 11
    if ( (t->type == t_int) or istypename(t->type, "integer") or
E 10
                  istypename(t->type,"integer*2") ) {
E 11
I 11
    if (t->type == t_int or istypename(t->type, "integer") or
	istypename(t->type,"integer*2")
    ) {
E 11
	printf("%ld", i);
I 10
    } else if (istypename(t->type, "addr")) {
	printf("0x%lx", i);
E 10
    } else {
D 10
      error("unkown type in fortran printint");
E 10
I 10
	error("unknown type in fortran printint");
E 10
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
 * Return the FORTRAN name for the particular class of a symbol.
 */

public String fortran_classname(s)
Symbol s;
{
    String str;

    switch (s->class) {
	case REF:
	    str = "dummy argument";
	    break;

	case CONST:
	    str = "parameter";
	    break;

	default:
	    str = classname(s);
    }
    return str;
}

/* reverses the indices from the expr_list; should be folded into buildaref
 * and done as one recursive routine
 */
Node private rev_index(here,n)
register Node here,n;
{
 
  register Node i;

  if( here == nil  or  here == n) i=nil;
  else if( here->value.arg[1] == n) i = here;
  else i=rev_index(here->value.arg[1],n);
  return i;
}

public Node fortran_buildaref(a, slist)
Node a, slist;
{
    register Symbol as;      /* array of array of .. cursor */
    register Node en;        /* Expr list cursor */
    Symbol etype;            /* Type of subscript expr */
    Node esub, tree;         /* Subscript expression ptr and tree to be built*/

    tree=a;

    as = rtype(tree->nodetype);     /* node->sym.type->array*/
    if ( not (
               (tree->nodetype->class == VAR or tree->nodetype->class == REF)
                and as->class == ARRAY
             ) ) {
	beginerrmsg();
	prtree(stderr, a);
	fprintf(stderr, " is not an array");
	/*fprintf(stderr, " a-> %x as %x ", tree->nodetype, as ); OUT*/
	enderrmsg();
    } else {
	for (en = rev_index(slist,nil); en != nil and as->class == ARRAY;
                     en = rev_index(slist,en), as = as->type) {
	    esub = en->value.arg[0];
	    etype = rtype(esub->nodetype);
            assert(as->chain->class == RANGE);
	    if ( not compatible( t_int, etype) ) {
		beginerrmsg();
		fprintf(stderr, "subscript ");
		prtree(stderr, esub);
		fprintf(stderr, " is type %s ",symname(etype->type) );
		enderrmsg();
	    }
	    tree = build(O_INDEX, tree, esub);
	    tree->nodetype = as->type;
	}
	if (en != nil or
             (as->class == ARRAY && (not istypename(as->type,"char"))) ) {
	    beginerrmsg();
	    if (en != nil) {
		fprintf(stderr, "too many subscripts for ");
	    } else {
		fprintf(stderr, "not enough subscripts for ");
	    }
	    prtree(stderr, tree);
	    enderrmsg();
	}
    }
    return tree;
}

/*
 * Evaluate a subscript index.
 */

D 7
public int fortran_evalaref(s, i)
E 7
I 7
public fortran_evalaref(s, base, i)
E 7
Symbol s;
I 7
Address base;
E 7
long i;
{
D 7
    Symbol r;
E 7
I 7
    Symbol r, t;
E 7
    long lb, ub;

D 7
    r = rtype(s)->chain;
    if(r->symvalue.rangev.lowertype == R_ARG or
       r->symvalue.rangev.lowertype == R_TEMP  ) {
	if(! getbound(s,r->symvalue.rangev.lower,
		        r->symvalue.rangev.lowertype,&lb))
E 7
I 7
    t = rtype(s);
    r = t->chain;
    if (
	r->symvalue.rangev.lowertype == R_ARG or
        r->symvalue.rangev.lowertype == R_TEMP
    ) {
	if (not getbound(
	    s, r->symvalue.rangev.lower, r->symvalue.rangev.lowertype, &lb
	)) {
E 7
          error("dynamic bounds not currently available");
I 7
	}
    } else {
	lb = r->symvalue.rangev.lower;
E 7
    }
D 7
    else lb = r->symvalue.rangev.lower;

    if(r->symvalue.rangev.uppertype == R_ARG or
       r->symvalue.rangev.uppertype == R_TEMP  ) {
	if(! getbound(s,r->symvalue.rangev.upper,
		        r->symvalue.rangev.uppertype,&ub))
E 7
I 7
    if (
	r->symvalue.rangev.uppertype == R_ARG or
        r->symvalue.rangev.uppertype == R_TEMP
    ) {
	if (not getbound(
	    s, r->symvalue.rangev.upper, r->symvalue.rangev.uppertype, &ub
	)) {
E 7
          error("dynamic bounds not currently available");
I 7
	}
    } else {
	ub = r->symvalue.rangev.upper;
E 7
    }
D 7
    else ub = r->symvalue.rangev.upper;
E 7

    if (i < lb or i > ub) {
	error("subscript out of range");
    }
D 7
    return (i - lb);
E 7
I 7
    push(long, base + (i - lb) * size(t->type));
E 7
}

private fortran_printarray(a)
Symbol a;
{
struct Bounds { int lb, val, ub} dim[MAXDIM];

Symbol sc,st,eltype;
char buf[50];
char *subscr;
int i,ndim,elsize;
Stack *savesp;
Boolean done;

st = a;

savesp = sp;
sp -= size(a);
ndim=0;

for(;;){
          sc = st->chain;
          if(sc->symvalue.rangev.lowertype == R_ARG or
             sc->symvalue.rangev.lowertype == R_TEMP) {
	      if( ! getbound(a,sc->symvalue.rangev.lower, 
D 3
                    sc->symvalue.rangev.lowertype, &dim[i].lb) )
E 3
I 3
                    sc->symvalue.rangev.lowertype, &dim[ndim].lb) )
E 3
		error(" dynamic bounds not currently available");
	  }
	  else dim[ndim].lb = sc->symvalue.rangev.lower;

          if(sc->symvalue.rangev.uppertype == R_ARG or
             sc->symvalue.rangev.uppertype == R_TEMP) {
	      if( ! getbound(a,sc->symvalue.rangev.upper, 
                    sc->symvalue.rangev.uppertype, &dim[ndim].ub) )
		error(" dynamic bounds not currently available");
	  }
	  else dim[ndim].ub = sc->symvalue.rangev.upper;

          ndim ++;
          if (st->type->class == ARRAY) st=st->type;
	  else break;
     }

if(istypename(st->type,"char")) {
		eltype = st;
		ndim--;
	}
else eltype=st->type;
elsize=size(eltype);
sp += elsize;
 /*printf("ndim %d elsize %lx in fortran_printarray\n",ndim,elsize);OUT*/

ndim--;
for (i=0;i<=ndim;i++){
	  dim[i].val=dim[i].lb;
	  /*OUT printf(" %d %d %d \n",i,dim[i].lb,dim[i].ub);
	    fflush(stdout); OUT*/
}


for(;;) {
	buf[0]=',';
	subscr = buf+1;

	for (i=ndim-1;i>=0;i--)  {

		sprintf(subscr,"%d,",dim[i].val);
        	subscr += strlen(subscr);
	}
        *--subscr = '\0';

	for(i=dim[ndim].lb;i<=dim[ndim].ub;i++) {
	      	printf("[%d%s]\t",i,buf);
		printval(eltype);
	      	printf("\n");
		sp += 2*elsize;
	}
        dim[ndim].val=dim[ndim].ub;

        i=ndim-1;
        if (i<0) break;

        done=false;
        do {
		dim[i].val++;
		if(dim[i].val > dim[i].ub) { 
			dim[i].val = dim[i].lb;
			if(--i<0) done=true;
		}
		else done=true;
         }
	 while (not done);
         if (i<0) break;
     }
I 5
}

/*
 * Initialize typetable at beginning of a module.
 */

public fortran_modinit (typetable)
Symbol typetable[];
{
    /* nothing for now */
}

public boolean fortran_hasmodules ()
{
    return false;
}

public boolean fortran_passaddr (param, exprtype)
Symbol param, exprtype;
{
    return false;
E 5
}
E 1
