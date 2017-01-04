h40137
s 00008/00002/00125
d D 5.1 85/05/31 11:26:06 dist 8 7
c Add copyright
e
s 00083/00189/00044
d D 1.5 85/03/01 20:21:03 linton 7 6
c update to version 3.0
e
s 00001/00003/00232
d D 1.4 84/06/23 11:40:00 sam 6 4
i 5
c merge linton branch delta trail
e
s 00003/00001/00232
d D 1.3.1.1 84/06/23 10:45:28 sam 5 4
c branch delta of linton changes from net.sources
e
s 00001/00001/00232
d D 1.3 83/05/18 23:21:22 csvaf 4 2
x 2
c sccsid
e
s 00001/00001/00232
d D 1.1.1.1 83/05/18 23:18:28 csvaf 3 1
c sccs id
e
s 00001/00001/00232
d D 1.2 83/05/18 23:15:47 csvaf 2 1
c added sccs id
e
s 00233/00000/00000
d D 1.1 83/05/18 23:10:35 csvaf 1 0
c date and time created 83/05/18 23:10:35 by csvaf
e
u
U
f b 
t
T
I 1
D 7

E 7
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

D 2
D 3
D 4
static char sccsid[] = "@(#)debug.c 1.6 4/8/83";
E 4
I 4
D 5
static char sccsid[] = "%W%	%G%";
E 5
I 5
D 6
static char sccsid[] = "@(#)debug.c	1.3	5/18/83";

static char rcsid[] = "$Header: debug.c,v 1.3 84/03/27 10:20:14 linton Exp $";
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
E 5
E 4
E 3
I 3
static char sccsid[] = "%W%\t%G%";
E 3
E 2
I 2
static char sccsid[] = "%W%\t%G%";
E 2

I 7
static char rcsid[] = "$Header: debug.c,v 1.5 84/12/26 10:39:01 linton Exp $";

E 7
/*
 *  Debug routines
 */

#include "defs.h"
#include "tree.h"
#include "operators.h"
#include "eval.h"
#include "events.h"
#include "symbols.h"
#include "scanner.h"
#include "source.h"
#include "object.h"
I 7
#include "main.h"
E 7
#include "mappings.h"
#include "process.h"
#include "machine.h"
I 7
#include "debug.h"
E 7
#include <signal.h>

I 7
public boolean tracetree;	/* trace building of parse trees */
public boolean traceeval;	/* trace tree evaluation */
E 7

D 7
public int debug_flag[20];
E 7
I 7
/*
 * Dynamically turn on/off a debug flag, or display some information.
 */
E 7

D 7
public debug(p)
E 7
I 7
public debug (p)
E 7
Node p;
{
D 7
   int code;
   code = p->value.lcon;
E 7
I 7
    int code;
E 7

D 7
   if ( (code >= 0) and (code < 10) ) {
   	switch(code)  {
	case 2:   if(debug_flag[2])  debug_flag[2]=0;
		  else debug_flag[2] =1;
                  printf(" flag 2 is %d \n",debug_flag[2]);
	          break;
E 7
I 7
    code = p->value.lcon;
    switch (code) {
	case 0:
	    puts("debugging flags:");
	    puts("    1        trace scanner return values");
	    puts("    2        trace breakpoints");
	    puts("    3        trace execution");
	    puts("    4        trace tree building");
	    puts("    5        trace tree evaluation");
	    puts("   -[12345]  turns off corresponding flag");
	    puts("    6        dump function table");
	    break;
E 7

D 7
	case 3:   if(debug_flag[3])  debug_flag[3]=0;
		  else debug_flag[3] =1;
                  printf(" flag 3 is %d \n",debug_flag[3]);
	          break;
E 7
I 7
	case 1:
	case -1:
#           ifdef LEXDEBUG
		lexdebug = (boolean) (code > 0);
#           else
		error("can't debug scanner (not compiled with LEXDEBUG)");
#           endif
	    break;
E 7

D 7
	case 4:   if(debug_flag[4])  debug_flag[4]=0;
		  else debug_flag[4] =1;
                  printf(" flag 4 is %d \n",debug_flag[4]);
	          break;
E 7
I 7
	case 2:
	case -2:
	    tracebpts = (boolean) (code > 0);
	    break;
E 7

D 7
	case 5:   if(debug_flag[5])  debug_flag[5]=0;
		  else debug_flag[5] =1;
                  printf(" flag 5 is %d \n",debug_flag[5]);
	          break;
E 7
I 7
	case 3:
	case -3:
	    traceexec = (boolean) (code > 0);
	    break;
E 7

D 7
	case 6:   dumpfunctab();
	          break;
E 7
I 7
	case 4:
	case -4:
	    tracetree = (boolean) (code > 0);
	    break;
E 7

D 7
	default:  printf(" unknown debug code %ld \n",p->value.lcon);
                  break;
        }
   }
   else if (debug_flag[3]) symbol_dump(code);
   else if (debug_flag[4]) psym(code);
}
E 7
I 7
	case 5:
	case -5:
	    traceeval = (boolean) (code > 0);
	    break;
E 7

D 7
public char *showoperator(op)
Operator op;
{
static char *operator_str[] = {
"O_NOP", "O_NAME", "O_SYM", "O_LCON", "O_FCON", "O_SCON", "O_RVAL", "O_INDEX",
"O_INDIR", "O_DOT", "O_COMMA", "O_ITOF", "O_ADD", "O_ADDF", "O_SUB", "O_SUBF",
"O_NEG", "O_NEGF", "O_MUL", "O_MULF", "O_DIVF", "O_DIV", "O_MOD", "O_AND",
"O_OR", "O_LT", "O_LTF", "O_LE", "O_LEF", "O_GT", "O_GTF", "O_GE", "O_GEF",
"O_EQ", "O_EQF", "O_NE", "O_NEF", "O_ALIAS", "O_ASSIGN", "O_CALL", "O_CATCH",
"O_CHFILE", "O_CONT", "O_DEBUG", "O_DELETE", "O_DUMP", "O_EDIT", "O_FUNC",
"O_GRIPE", "O_HELP", "O_IGNORE", "O_LIST", "O_PRINT", "O_PSYM", "O_RUN",
"O_SKIP", "O_SOURCE", "O_STATUS", "O_STEP", "O_STOP", "O_STOPI", "O_TRACE",
"O_TRACEI", "O_WHATIS", "O_WHERE", "O_WHEREIS", "O_WHICH", "O_EXAMINE",
"O_ADDEVENT", "O_ENDX", "O_IF", "O_ONCE", "O_PRINTCALL", "O_PRINTIFCHANGED",
"O_PRINTRTN", "O_PRINTSRCPOS", "O_PROCRTN", "O_QLINE", "O_STOPIFCHANGED",
"O_STOPX", "O_TRACEON", "O_TRACEOFF", "O_TYPERENAME", "O_LASTOP" };
return( operator_str[ord(op)] );
E 7
I 7
	case 6:
	    dumpfunctab();
	    break;

	default:
	    error("unknown debug flag");
	    break;
    }
E 7
}

D 7
/*
 * Dump a tree recursively
 */
E 7
I 7
private String leafname[] = {
    "nop", "name", "sym", "lcon", "fcon", "scon", "rval", "index"
};
E 7

D 7
public dumptree(f, p)
File f;
register Node p;
E 7
I 7
public String opname (op)
Operator op;
E 7
{
D 7
    register Node q;
    Operator op;
    static recurse  =0;
    ++recurse;
E 7
I 7
    String s;
    static char buf[100];
E 7

D 7
    if (p != nil) {
	op = p->op;
	if (ord(op) > ord(O_LASTOP)) {
	    panic("bad op %d in dumptree", p->op);
	}
        { int n_args;
	  fprintf(f, "\n level %d op %s node %ld ",recurse,showoperator(op), p);
          for(n_args=0;n_args < nargs(op); n_args++) 
            fprintf(f," arg%d %ld ",n_args,p->value.arg[n_args]);
          fprintf(f,"\n");
        }
        if(p->nodetype) {fprintf(f,"nodetype: "); psym(p->nodetype);}
	switch (op) {
	    case O_NAME:
		fprintf(f, "%s", ident(p->value.name));
		break;
E 7
I 7
    switch (op) {
	case O_ITOF:
	    s = "itof";
	    break;
E 7

D 7
	    case O_SYM:
		printname(f, p->value.sym);
		break;
E 7
I 7
	case O_ENDX:
	    s = "endx";
	    break;
E 7

D 7
	    case O_QLINE:
		if (nlhdr.nfiles > 1) {
		    dumptree(f, p->value.arg[0]);
		    fprintf(f, ":");
		}
		dumptree(f, p->value.arg[1]);
		break;
E 7
I 7
	case O_QLINE:
	    s = "qline";
	    break;
E 7

D 7
	    case O_LCON:
		if (compatible(p->nodetype, t_char)) {
		    fprintf(f, "'%c'", p->value.lcon);
		} else {
		    fprintf(f, "%d", p->value.lcon);
E 7
I 7
	default:
	    if (ord(op) <= ord(O_INDEX)) {
		s = leafname[ord(op)];
	    } else {
		s = opinfo[ord(op)].opstring;
		if (s == nil) {
		    sprintf(buf, "[op %d]", op);
		    s = buf;
E 7
		}
D 7
		break;

	    case O_FCON:
		fprintf(f, "%g", p->value.fcon);
		break;

	    case O_SCON:
		fprintf(f, "\"%s\"", p->value.scon);
		break;

	    case O_INDEX:
		dumptree(f, p->value.arg[0]);
		fprintf(f, "[");
		dumptree(f, p->value.arg[1]);
		fprintf(f, "]");
		break;

	    case O_COMMA:
		dumptree(f, p->value.arg[0]);
		if (p->value.arg[1] != nil) {
		    fprintf(f, ", ");
		    dumptree(f, p->value.arg[1]);
		}
		break;

	    case O_RVAL:
		if (p->value.arg[0]->op == O_SYM) {
		    printname(f, p->value.arg[0]->value.sym);
		} else {
		    dumptree(f, p->value.arg[0]);
		}
		break;

	    case O_ITOF:
		dumptree(f, p->value.arg[0]);
		break;

	    case O_CALL:
		dumptree(f, p->value.arg[0]);
		if (p->value.arg[1]!= nil) {
		    fprintf(f, "(");
		    dumptree(f, p->value.arg[1]);
		    fprintf(f, ")");
		}
		break;

	    case O_INDIR:
		q = p->value.arg[0];
		if (isvarparam(q->nodetype)) {
		    dumptree(f, q);
		} else {
		    if (q->op == O_SYM or q->op == O_LCON or q->op == O_DOT) {
			dumptree(f, q);
			fprintf(f, "^");
		    } else {
			fprintf(f, "*(");
			dumptree(f, q);
			fprintf(f, ")");
		    }
		}
		break;

	    case O_DOT:
		q = p->value.arg[0];
		if (q->op == O_INDIR) {
		    dumptree(f, q->value.arg[0]);
		} else {
		    dumptree(f, q);
		}
		fprintf(f, ".%s", symname(p->value.arg[1]->value.sym));
		break;

	    default:
		switch (degree(op)) {
		    case BINARY:
			dumptree(f, p->value.arg[0]);
			fprintf(f, "%s", opinfo[ord(op)].opstring);
			dumptree(f, p->value.arg[1]);
			break;

		    case UNARY:
			fprintf(f, "%s", opinfo[ord(op)].opstring);
			dumptree(f, p->value.arg[0]);
			break;

		    default:
                        if(degree(op) < ord(O_LASTOP) )
                        {      int i;
                               if( nargs(op)  != 0) 
                                 for(i=0;i<nargs(op);i++) 
                                  dumptree(f, p->value.arg[i]);
			} 
			else
                          error("internal error: bad op %d in dumptree", op);
		}
		break;
	}
E 7
I 7
	    }
	    break;
E 7
    }
D 7
   recurse--;
   fflush(f);
E 7
I 7
    return s;
E 7
}
E 1
