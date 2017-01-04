h33052
s 00002/00001/00121
d D 5.2 87/04/07 15:53:36 mckusick 3 2
c port to tahoe by Nir peleg of CCI
e
s 00008/00003/00114
d D 5.1 85/06/06 08:20:02 dist 2 1
c Add copyright
e
s 00117/00000/00000
d D 1.1 82/01/18 19:20:26 linton 1 0
c date and time created 82/01/18 19:20:26 by linton
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
 * Breakpoint/machine interface.
 */

#include "defs.h"
#include <signal.h>
#include "machine.h"
#include "process.h"
#include "main.h"
#include "pxops.h"
#include "process/process.rep"
I 3
#include "process/pxinfo.h"
E 3

#define BP_OP		O_BPT		/* breakpoint trap */
#define BP_ERRNO	SIGILL		/* signal received at a breakpoint */

/*
 * Setting a breakpoint at a location consists of saving
 * the half-word at the location and poking a BP_OP there.
 *
 * We save the locations and half-words on a list for use in unsetting.
 */

typedef struct savelist SAVELIST;

struct savelist {
	ADDRESS location;
	short save;
	short refcount;
	SAVELIST *link;
};

LOCAL SAVELIST *savelist;

/*
 * Set a breakpoint at the given address.  Only save the half-word there
 * if it's not already a breakpoint.
 */

setbp(addr)
ADDRESS addr;
{
D 3
	short w;
E 3
I 3
	unsigned char w;
E 3
	short save;
	register SAVELIST *newsave, *s;

	if (option('b')) {
		printf("setting breakpoint at %d\n", addr);
		fflush(stdout);
	}
	for (s = savelist; s != NIL; s = s->link) {
		if (s->location == addr) {
			s->refcount++;
			return;
		}
	}
	iread(&save, addr, sizeof(save));
	newsave = alloc(1, SAVELIST);
	newsave->location = addr;
	newsave->save = save;
	newsave->refcount = 1;
	newsave->link = savelist;
	savelist = newsave;
	w = BP_OP;
	iwrite(&w, addr, sizeof(w));
}

/*
 * Unset a breakpoint; unfortunately we have to search the SAVELIST
 * to find the saved value.  The assumption is that the SAVELIST will
 * usually be quite small.
 */

unsetbp(addr)
ADDRESS addr;
{
	register SAVELIST *s, *prev;

	if (option('b')) {
		printf("unsetting breakpoint at %d\n", addr);
		fflush(stdout);
	}
	prev = NIL;
	for (s = savelist; s != NIL; s = s->link) {
		if (s->location == addr) {
			iwrite(&s->save, addr, sizeof(s->save));
			s->refcount--;
			if (s->refcount == 0) {
				if (prev == NIL) {
					savelist = s->link;
				} else {
					prev->link = s->link;
				}
				dispose(s);
			}
			return;
		}
		prev = s;
	}
	panic("unsetbp: couldn't find address %d", addr);
}

/*
 * Predicate to test if the reason the process stopped was because
 * of a breakpoint.
 */

BOOLEAN isbperr()
{
	register PROCESS *p;

	p = process;
	return(p->status==STOPPED && p->signo==BP_ERRNO);
}
E 1
