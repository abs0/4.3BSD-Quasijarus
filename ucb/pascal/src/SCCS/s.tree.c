h54307
s 00007/00003/00180
d D 5.1 85/06/05 15:02:26 dist 7 6
c Add copyright
e
s 00000/00000/00183
d D 2.1 84/02/08 20:43:57 aoki 6 5
c synchronize to version 2
e
s 00001/00001/00182
d D 1.5 84/02/04 17:28:27 thien 5 4
c lint
e
s 00000/00000/00183
d D 1.4 83/09/19 07:01:23 thien 4 3
c Restoring to unlinted version
e
s 00015/00011/00168
d D 1.3 83/08/19 05:03:25 thien 3 2
c The changes were made to allow successful linting
e
s 00001/00001/00178
d D 1.2 80/11/24 19:00:10 peter 2 1
c malloc returns 0 on out of memory, not -1 as in version 6.
e
s 00179/00000/00000
d D 1.1 80/08/27 19:56:43 peter 1 0
c date and time created 80/08/27 19:56:43 by peter
e
u
U
t
T
I 1
D 7
/* Copyright (c) 1979 Regents of the University of California */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 7

I 3
#ifndef lint
E 3
D 7
static	char sccsid[] = "%Z%%M% %I% %G%";
I 3
#endif
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7
E 3

#include "whoami.h"
#include "0.h"

/*
 * TREE SPACE DECLARATIONS
 */
struct tr {
	int	*tr_low;
	int	*tr_high;
} ttab[MAXTREE], *tract;

/*
 * The variable space is the
 * absolute base of the tree segments.
 * (exactly the same as ttab[0].tr_low)
 * Spacep is maintained to point at the
 * beginning of the next tree slot to
 * be allocated for use by the grammar.
 * Spacep is used "extern" by the semantic
 * actions in pas.y.
 * The variable tract is maintained to point
 * at the tree segment out of which we are
 * allocating (the active segment).
 */
int	*space, *spacep;

/*
 * TREENMAX is the maximum width
 * in words that any tree node 
 * due to the way in which the parser uses
 * the pointer spacep.
 */
#define	TREENMAX	6

int	trspace[ITREE];
int	*space	= trspace;
int	*spacep	= trspace;
struct	tr *tract	= ttab;

/*
 * Inittree allocates the first tree slot
 * and sets up the first segment descriptor.
 * A lot of this work is actually done statically
 * above.
 */
inittree()
{

	ttab[0].tr_low = space;
	ttab[0].tr_high = &space[ITREE];
}

/*
 * Tree builds the nodes in the
 * parse tree. It is rarely called
 * directly, rather calls are made
 * to tree[12345] which supplies the
 * first argument to save space in
 * the code. Tree also guarantees
 * that spacep points to the beginning
 * of the next slot it will return,
 * a property required by the parser
 * which was always true before we
 * segmented the tree space.
 */
D 3
int *tree(cnt, a)
E 3
I 3
D 5
/*VARARGS*/
E 5
I 5
/*VARARGS1*/
E 5
struct tnode *
tree(cnt, a)
E 3
	int cnt;
{
	register int *p, *q;
	register int i;

	i = cnt;
	p = spacep;
	q = &a;
	do
		*p++ = *q++;
	while (--i);
	q = spacep;
	spacep = p;
	if (p+TREENMAX >= tract->tr_high)
		/*
		 * this peek-ahead should
		 * save a great number of calls
		 * to tralloc.
		 */
		tralloc(TREENMAX);
D 3
	return (q);
E 3
I 3
	return ((struct tnode *) q);
E 3
}

/*
 * Tralloc preallocates enough
 * space in the tree to allow
 * the grammar to use the variable
 * spacep, as it did before the
 * tree was segmented.
 */
tralloc(howmuch)
{
	register char *cp;
	register i;

	if (spacep + howmuch >= tract->tr_high) {
		i = TRINC;
D 3
		cp = malloc(i * sizeof ( int ));
E 3
I 3
		cp = malloc((unsigned) (i * sizeof ( int )));
E 3
D 2
		if (cp == -1) {
E 2
I 2
		if (cp == 0) {
E 2
			yerror("Ran out of memory (tralloc)");
			pexit(DIED);
		}
D 3
		spacep = cp;
E 3
I 3
		spacep = (int *) cp;
E 3
		tract++;
		if (tract >= &ttab[MAXTREE]) {
			yerror("Ran out of tree tables");
			pexit(DIED);
		}
D 3
		tract->tr_low = cp;
E 3
I 3
		tract->tr_low = (int *) cp;
E 3
		tract->tr_high = tract->tr_low+i;
	}
}

extern	int yylacnt;
D 3
extern	bottled;
E 3
I 3
extern	struct B *bottled;
E 3
#ifdef PXP
#endif
/*
 * Free up the tree segments
 * at the end of a block.
 * If there is scanner lookahead,
 * i.e. if yylacnt != 0 or there is bottled output, then we
 * cannot free the tree space.
 * This happens only when errors
 * occur and the forward move extends
 * across "units".
 */
trfree()
{

	if (yylacnt != 0 || bottled != NIL)
		return;
#ifdef PXP
	if (needtree())
		return;
#endif
	spacep = space;
	while (tract->tr_low > spacep || tract->tr_high <= spacep) {
D 3
		free(tract->tr_low);
E 3
I 3
		free((char *) tract->tr_low);
E 3
		tract->tr_low = NIL;
		tract->tr_high = NIL;
		tract--;
		if (tract < ttab)
			panic("ttab");
	}
#ifdef PXP
	packtree();
#endif
}

/*
 * Copystr copies a token from
 * the "token" buffer into the
 * tree space.
 */
copystr(token)
	register char *token;
{
	register char *cp;
	register int i;

	i = (strlen(token) + sizeof ( int )) & ~( ( sizeof ( int ) ) - 1 );
	tralloc(i / sizeof ( int ));
D 3
	strcpy(spacep, token);
	cp = spacep;
	spacep = cp + i;
E 3
I 3
	(void) pstrcpy((char *) spacep, token);
	cp = (char *) spacep;
	spacep = ((int *) cp + i);
E 3
	tralloc(TREENMAX);
D 3
	return (cp);
E 3
I 3
	return ((int) cp);
E 3
}
E 1
