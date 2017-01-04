h41331
s 00008/00002/00059
d D 5.1 85/06/06 15:58:18 dist 2 1
c Add copyright
e
s 00061/00000/00000
d D 1.1 82/01/18 19:21:32 linton 1 0
c date and time created 82/01/18 19:21:32 by linton
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
 * Free a tree; this is expensive but useful.
 */

#include "defs.h"
#include "tree.h"
#include "sym.h"
#include "tree.rep"

tfree(p)
register NODE *p;
{
	if (p == NIL) {
		return;
	}
	switch(degree(p->op)) {
		case LEAF:
			switch(p->op) {
				case O_CALL:
					tfree(p->left);
					tfree(p->right);
					break;

				case O_QLINE:
					dispose(p->left->sconval);
					dispose(p->left);
					tfree(p->right);
					break;

				case O_ALIAS:
					dispose(p->left->sconval);
					dispose(p->left);
					dispose(p->right->sconval);
					dispose(p->right);
					break;

				case O_SCON:
					unmkstring(p->nodetype);
					free(p->nodetype);
					free(p->sconval);
					p->sconval = NIL;
					break;
			}
			break;

		case BINARY:
			tfree(p->right);
			/* fall through */
		case UNARY:
			tfree(p->left);
			break;

		default:
			panic("bad op %d in tfree", p->op);
	}
	dispose(p);
}
E 1
