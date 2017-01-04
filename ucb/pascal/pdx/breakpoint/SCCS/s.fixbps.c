h60043
s 00008/00003/00069
d D 5.1 85/06/05 16:57:32 dist 2 1
c Add copyright
e
s 00072/00000/00000
d D 1.1 82/01/18 19:19:56 linton 1 0
c date and time created 82/01/18 19:19:56 by linton
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
 * fix up breakpoint information before continuing execution
 *
 * It's necessary to destroy breakpoints that were created temporarily
 * and still exist because the program terminated abnormally.
 */

#include "defs.h"
#include "breakpoint.h"
#include "bp.rep"

fixbps()
{
	register BPINFO *p, *last, *next;

	last = NIL;
	p = bphead;
	while (p != NIL) {
		next = p->bpnext;
		switch(p->bptype) {
			case ALL_OFF:
				if (p->bpline >= 0) {
					--tracing;
				} else {
					--inst_tracing;
				}
				if (p->bpcond != NIL) {
					delcond(TRPRINT, p->bpcond);
				}
				goto delete;

			case STOP_OFF:
				var_tracing--;
				delcond(TRSTOP, p->bpcond);
				goto delete;

			case TERM_OFF:
				--var_tracing;
				delvar(TRPRINT, p->bpnode, p->bpcond);
				goto delete;

			case CALL:
			case RETURN:
			case BLOCK_OFF:
			case CALLPROC:
			case END_BP:

			delete:
				if (last == NIL) {
					bphead = next;
				} else {
					last->bpnext = next;
				}
				dispose(p);
				break;

			default:
				last = p;
				break;
		}
		p = next;
	}
	tracing = 0;
	var_tracing = 0;
	inst_tracing = 0;
	trfree();
	condfree();
}
E 1
