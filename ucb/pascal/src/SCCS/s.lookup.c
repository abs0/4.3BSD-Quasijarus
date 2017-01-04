h53310
s 00007/00003/00114
d D 5.1 85/06/05 14:22:29 dist 6 5
c Add copyright
e
s 00000/00000/00117
d D 2.1 84/02/08 20:42:09 aoki 5 4
c synchronize to version 2
e
s 00000/00000/00117
d D 1.4 83/09/19 06:58:55 thien 4 3
c Restoring to unlinted version
e
s 00012/00010/00105
d D 1.3 83/08/19 04:58:17 thien 3 2
c The changes were made to allow successful linting
e
s 00002/00000/00113
d D 1.2 82/08/27 00:32:59 mckusick 2 1
c convert namelist structure to use unions
e
s 00113/00000/00000
d D 1.1 80/08/27 19:55:16 peter 1 0
c date and time created 80/08/27 19:55:16 by peter
e
u
U
t
T
I 1
D 6
/* Copyright (c) 1979 Regents of the University of California */
E 6
I 6
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 6

I 3
#ifndef lint
E 3
D 6
static	char sccsid[] = "%Z%%M% %I% %G%";
I 3
#endif
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
E 3

#include "whoami.h"
#include "0.h"

I 2
struct nl *disptab[077+1];

E 2
/*
 * Lookup is called to
 * find a symbol in the
 * block structure symbol
 * table and returns a pointer to
 * its namelist entry.
 */
struct nl *
lookup(s)
	register char *s;
{
	register struct nl *p;
D 3
	register struct udinfo *udp;
E 3
I 3
	register struct udinfo;
E 3

	if (s == NIL) {
		nocascade();
D 3
		return (NIL);
E 3
I 3
		return (NLNIL);
E 3
	}
	p = lookup1(s);
D 3
	if (p == NIL) {
E 3
I 3
	if (p == NLNIL) {
E 3
		derror("%s is undefined", s);
D 3
		return (NIL);
E 3
I 3
		return (NLNIL);
E 3
	}
	if (p->class == FVAR) {
		p = p->chain;
		bn--;
	}
	return (p);
}

#ifndef PI0
int	flagwas;
#endif
/*
 * Lookup1 is an internal lookup.
 * It is not an error to call lookup1
 * if the symbol is not defined.  Also
 * lookup1 will return FVARs while
 * lookup never will, thus asgnop
 * calls it when it thinks you are
 * assigning to the function variable.
 */

struct nl *
lookup1(s)
	register char *s;
{
	register struct nl *p;
#ifndef PI0
	register struct nl *q;
#endif
	register int i;

	if (s == NIL)
D 3
		return (NIL);
E 3
I 3
		return (NLNIL);
E 3
	bn = cbn;
#ifndef PI0
	/*
	 * We first check the field names
	 * of the currently active with
	 * statements (expensive since they
	 * are not hashed).
	 */
D 3
	for (p = withlist; p != NIL; p = p->nl_next) {
E 3
I 3
	for (p = withlist; p != NLNIL; p = p->nl_next) {
E 3
		q = p->type;
D 3
		if (q == NIL)
E 3
I 3
		if (q == NLNIL)
E 3
			continue;
		if (reclook(q, s) != NIL)
			/*
			 * Return the WITHPTR, lvalue understands.
			 */
			return (p);
	}
#endif
	/*
	 * Symbol table is a 64 way hash
	 * on the low bits of the character
	 * pointer value. (Simple, but effective)
	 */
	i = (int) s & 077;
D 3
	for (p = disptab[i]; p != NIL; p = p->nl_next)
E 3
I 3
	for (p = disptab[i]; p != NLNIL; p = p->nl_next)
E 3
		if (p->symbol == s && p->class != FIELD && p->class != BADUSE) {
			bn = (p->nl_block & 037);
#ifndef PI0
			flagwas = p->nl_flags;
			p->nl_flags |= NUSED;
#endif
			return (p);
		}
D 3
	return (NIL);
E 3
I 3
	return (NLNIL);
E 3
}

#ifndef PI01
nlfund(sp)
	char *sp;
{
	register struct nl *p;
	register int i;

	i = (int) sp & 077;
D 3
	for (p = disptab[i]; p != NIL; p = p->nl_next)
E 3
I 3
	for (p = disptab[i]; p != NLNIL; p = p->nl_next)
E 3
	if (p->symbol == sp && (p->nl_block & 037) == 0)
		return (nloff(p));
	return (0);
}
#endif
E 1
