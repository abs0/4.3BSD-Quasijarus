h51307
s 00003/00005/00147
d D 5.2 87/04/07 15:57:54 mckusick 3 2
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00144
d D 5.1 85/06/06 15:55:22 dist 2 1
c Add copyright
e
s 00147/00000/00000
d D 1.1 82/01/18 19:21:35 linton 1 0
c date and time created 82/01/18 19:21:35 by linton
e
u
U
t
T
I 1
D 2
/* Copyright (c) 1982 Regents of the University of California */
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 2

D 2
static char sccsid[] = "%Z%%M% %I% %G%";

E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 2
/*
 * parse tree building routines
 *
 * Semantics is not checked here, this is done by the "treetype" routine
 * in the SYM directory which returns the type of the newly built tree.
 */

#include "defs.h"
#include "tree.h"
#include "sym.h"
#include "source.h"
#include "tree.rep"

/*
 * header for using routines with unknown number and types of arguments
 * I didn't like the looks of the standard varargs.h.
 */

typedef char *ARGLIST;

#define nextarg(arglist, type)	((type *) (arglist += sizeof(type)))[-1]

/*
 * build a tree
 */

/*VARARGS1*/
NODE *build(op, args)
OP op;
{
	register NODE *p;
D 3
	NODE *p1, *p2;
E 3
	register ARGLIST ap;
D 3
	SYM *s;
E 3

	p = alloc(1, NODE);
	p->op = op;
	ap = (ARGLIST) &args;
	switch(degree(op)) {
		case BINARY:
D 3
			p->left = p1 = nextarg(ap, NODE *);
			p->right = p2 = nextarg(ap, NODE *);
E 3
I 3
			p->left = nextarg(ap, NODE *);
			p->right = nextarg(ap, NODE *);
E 3
			break;

		case UNARY:
D 3
			p->left = p1 = nextarg(ap, NODE *);
E 3
I 3
			p->left = nextarg(ap, NODE *);
E 3
			p->right = NIL;
			break;

	}
	switch(op) {
		case O_NAME:
		case O_WHICH:
			p->nameval = nextarg(ap, SYM *);
			break;

		case O_LCON:
			p->lconval = nextarg(ap, long);
			break;

		case O_FCON:
			p->fconval = nextarg(ap, double);
			break;

		case O_SCON:
			p->sconval = nextarg(ap, char *);
			break;

		case O_CALL:
			p->left = nextarg(ap, NODE *);
			p->right = nextarg(ap, NODE *);
			break;

		case O_CHFILE:
			p->sconval = nextarg(ap, char *);
			break;

		case O_EDIT:
			p->sconval = nextarg(ap, char *);
			if (p->sconval == NIL) {
				p->sconval = cursource;
			}
			break;

		case O_SOURCE:
			p->sconval = nextarg(ap, char *);
			break;

		case O_PRINT:
		case O_WHATIS:
		case O_LIST:
		case O_XI:
		case O_XD:
			p->left = nextarg(ap, NODE *);
			break;

		case O_TRACE:
		case O_TRACEI:
		case O_STOP:
		case O_STOPI:
			p->what = nextarg(ap, NODE *);
			p->where = nextarg(ap, NODE *);
			p->cond = nextarg(ap, NODE *);
			break;

		case O_DELETE:
			p->left = build(O_LCON, nextarg(ap, long));
			break;

		case O_QLINE: {
			char *s;

			s = nextarg(ap, char *);
			p->left = alloc(1, NODE);
			p->left->op = O_SCON;
			if (s != cursource) {
				p->left->sconval = s;
				s[strlen(s) - 1] = '\0';
			} else {
				p->left->sconval = strdup(s);
			}
			p->right = nextarg(ap, NODE *);
			break;
		}

		case O_ALIAS:
			p->left = alloc(1, NODE);
			p->left->op = O_SCON;
			p->left->sconval = nextarg(ap, char *);
			p->right = alloc(1, NODE);
			p->right->op = O_SCON;
			p->right->sconval = nextarg(ap, char *);
			break;
			
		default:
			if (op < O_NOP || op > O_LASTOP) {
				panic("build: bad op %d", op);
			}
			break;
	}
	p->nodetype = treetype(p, (ARGLIST) &args);
	return(p);
}
E 1
