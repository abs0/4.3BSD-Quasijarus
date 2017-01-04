h05668
s 00008/00002/00144
d D 5.1 85/06/06 15:57:49 dist 2 1
c Add copyright
e
s 00146/00000/00000
d D 1.1 82/01/18 19:21:30 linton 1 0
c date and time created 82/01/18 19:21:30 by linton
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
 * Print a tree back out in Pascal form.
 */

#include "defs.h"
#include "tree.h"
#include "sym.h"
#include "sym/btypes.h"
#include "tree.rep"

prtree(p)
NODE *p;
{
	OP op;

	if (p == NIL) {
		return;
	}
	op = p->op;
	if (op < O_NOP || op > O_LASTOP) {
		panic("bad op %d in prtree", p->op);
	}
	switch (op) {
		case O_NAME: {
			SYM *s;

			s = p->nameval;
			if (isredirected() || isambiguous(s)) {
				printwhich(s);
			} else {
				printf("%s", name(s));
			}
			break;
		}

		case O_QNAME:
			prtree(p->left);
			printf(".%s", name(p->right->nameval));
			break;

		case O_QLINE:
			prtree(p->left);
			printf(":");
			prtree(p->right);
			break;

		case O_LCON:
			push(long, p->lconval);
			printval(p->nodetype);
			break;

		case O_FCON:
			printf("%g", p->fconval);
			break;

		case O_SCON:
			printf("'%s'", p->sconval);
			break;

		case O_INDEX:
			prtree(p->left);
			printf("[");
			prtree(p->right);
			printf("]");
			break;

		case O_COMMA:
			prtree(p->left);
			if (p->right != NIL) {
				printf(", ");
				prtree(p->right);
			}
			break;

		case O_RVAL:
		case O_ITOF:
			prtree(p->left);
			break;

		case O_CALL:
			prtree(p->left);
			if (p->right != NIL) {
				printf("(");
				prtree(p->right);
				printf(")");
			}
			break;

		case O_INDIR:
			prtree(p->left);
			if (!isvarparam(p->left->nodetype)) {
				printf("^");
			}
			break;

		default:
			switch(degree(op)) {
				case BINARY:
					prtree(p->left);
					printf("%s", opinfo[op].opstring);
					prtree(p->right);
					break;

				case UNARY:
					printf("%s", opinfo[op].opstring);
					prtree(p->left);
					break;

				default:
					panic("bad op %d in prtree", op);
			}
			break;
	}
}

/*
 * Print an error associated with a particular tree.
 * The string is searched for a "%t" which is replaced by
 * the printed representation of the tree.
 */

/* VARARGS2 */
trerror(s, tree, a, b, c, d, e, f, g, h, i, j)
char *s;
NODE *tree;
{
	register char *p;

	fflush(stdout);
	for (p = s; *p != '\0'; p++) {
		if (p[0] == '%' && p[1] == 't') {
			fputc('"', stderr);
			prtree(tree);
			fflush(stdout);
			fputc('"', stderr);
			error(&p[2], a, b, c, d, e, f, g, h, i, j);
			/* NOTREACHED */
		}
		fputc(*p, stderr);
	}
	panic("bad call to trerror");
}
E 1
