h12891
s 00008/00002/00123
d D 5.1 85/06/05 16:59:34 dist 2 1
c Add copyright
e
s 00125/00000/00000
d D 1.1 82/01/18 19:20:03 linton 1 0
c date and time created 82/01/18 19:20:03 by linton
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
 * trace condition list -- a list of conditions that are to be
 * checked before printing out the current source line or stopping.
 */

#include "defs.h"
#include "breakpoint.h"

typedef struct tr_cond_list {
	TRTYPE trtype;
	NODE *trace_condition;
	struct tr_cond_list *next_condition;
} TR_COND_LIST;

LOCAL TR_COND_LIST *cond_list;

/*
 * add a condition to be checked before giving single stepping information
 */

addcond(trtype, p)
TRTYPE trtype;
NODE *p;
{
	register TR_COND_LIST *c;

	if (p == NIL) {
		return;
	}
	c = alloc(1, TR_COND_LIST);
	c->trtype = trtype;
	c->trace_condition = p;
	c->next_condition = cond_list;
	cond_list = c;
}

/*
 * delete a condition from the list
 */

delcond(trtype, p)
TRTYPE trtype;
NODE *p;
{
	register TR_COND_LIST *c, *last;

	if (p == NIL) {
		return;
	}
	last = NIL;
	for (c = cond_list; c != NIL; c = c->next_condition) {
		if (c->trtype == trtype && c->trace_condition == p) {
			break;
		}
	}
	if (c == NIL) {
		panic("tried to delete non-existent condition");
	}
	if (last == NIL) {
		cond_list = c->next_condition;
	} else {
		last->next_condition = c->next_condition;
	}
	free(c);
}

/*
 * Determine if any trace condition on the list is true.
 * If the list is empty, return TRUE.
 */

BOOLEAN trcond()
{
	register TR_COND_LIST *c;
	BOOLEAN foundcond;

	foundcond = FALSE;
	for (c = cond_list; c != NIL; c = c->next_condition) {
		if (c->trtype == TRPRINT) {
			if (cond(c->trace_condition)) {
				return(TRUE);
			} else {
				foundcond = TRUE;
			}
		}
	}
	return !foundcond;
}

/*
 * Determine if any stop condition on the list is true.
 * If the list is empty, return FALSE.
 */

BOOLEAN stopcond()
{
	register TR_COND_LIST *c;

	for (c = cond_list; c != NIL; c = c->next_condition) {
		if (c->trtype == TRSTOP && cond(c->trace_condition)) {
			return(TRUE);
		}
	}
	return FALSE;
}

/*
 * Free all existing breakpoints.
 * Trace conditions have been freed elsewhere.
 */

condfree()
{
	TR_COND_LIST *c, *next;

	for (c = cond_list; c != NIL; c = next) {
		next = c->next_condition;
		dispose(c);
	}
	cond_list = NIL;
}
E 1
