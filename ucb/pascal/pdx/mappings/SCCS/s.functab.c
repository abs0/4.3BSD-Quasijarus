h31907
s 00000/00001/00095
d D 5.2 87/04/06 18:34:13 mckusick 3 2
c lint
e
s 00008/00003/00088
d D 5.1 85/06/06 11:26:08 dist 2 1
c Add copyright
e
s 00091/00000/00000
d D 1.1 82/01/18 19:20:32 linton 1 0
c date and time created 82/01/18 19:20:32 by linton
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
 * This file contains the implementation of a table for going
 * from object addresses to the functions in which they belong.
 */

#include "defs.h"
#include "mappings.h"
#include "sym.h"

#define MAXNFUNCS 1001		/* maximum number of functions allowed */

LOCAL SYM *functab[MAXNFUNCS];
LOCAL int nfuncs;

/*
 * Insert a new function into the table.
 * The table is ordered by object address.
 */

newfunc(f)
SYM *f;
{
	register int i, j;
	ADDRESS a;

	if (nfuncs >= MAXNFUNCS) {
		panic("too many procedures/functions");
	}
	a = codeloc(f);
	i = 0;
	while (i < nfuncs && codeloc(functab[i]) < a) {
		i++;
	}
	for (j = nfuncs; j > i; j--) {
		functab[j] = functab[j - 1];
	}
	functab[i] = f;
	nfuncs++;
}

/*
 * Return the function that begins at the given address.
 */

SYM *whatblock(addr)
ADDRESS addr;
{
D 3
	register SYM *p;
E 3
	register int i, j, k;
	ADDRESS a;

	i = 0;
	j = nfuncs - 1;
	if (addr < codeloc(functab[i])) {
		return program;
	} else if (addr == codeloc(functab[i])) {
		return functab[i];
	} else if (addr >= codeloc(functab[j])) {
		return functab[j];
	}
	while (i <= j) {
		k = (i + j) / 2;
		a = codeloc(functab[k]);
		if (a == addr) {
			return functab[k];
		} else if (addr > a) {
			i = k+1;
		} else {
			j = k-1;
		}
	}
	if (addr > codeloc(functab[i])) {
		return functab[i];
	} else {
		return functab[i-1];
	}
	/* NOTREACHED */
}

/*
 * Clear out the functab, used when re-reading the object information.
 */

clrfunctab()
{
	nfuncs = 0;
}
E 1
