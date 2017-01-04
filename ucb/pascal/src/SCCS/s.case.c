h62717
s 00000/00006/00241
d D 5.2 85/06/05 13:54:21 dist 8 7
c Add copyright
e
s 00010/00000/00237
d D 5.1 85/06/05 11:54:40 dist 7 6
c Add copyright
e
s 00000/00000/00237
d D 2.1 84/02/08 20:41:05 aoki 6 5
c synchronize to version 2
e
s 00000/00000/00237
d D 1.5 83/09/19 06:57:43 thien 5 4
c Restoring to unlinted version
e
s 00093/00047/00144
d D 1.4 83/08/19 04:55:41 thien 4 3
c The changes were made to allow successful linting
e
s 00010/00006/00181
d D 1.3 81/03/08 19:24:00 mckusic 3 2
c merge in onyx changes
e
s 00001/00001/00186
d D 1.2 80/11/24 18:58:22 peter 2 1
c malloc returns 0 on out of memory, not -1 as in version 6.
e
s 00187/00000/00000
d D 1.1 80/08/27 19:54:42 peter 1 0
c date and time created 80/08/27 19:54:42 by peter
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 7
I 1
D 8
/* Copyright (c) 1979 Regents of the University of California */

I 4
#ifndef lint
E 4
D 3
static	char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
static char sccsid[] = "%Z%%M% %I% %G%";
I 4
#endif
E 4
E 3

E 8
#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
I 4
#include "tree_ty.h"
E 4

/*
 * The structure used to
 * hold information about
 * each case label.
 */
struct ct {
	long	clong;
	int	cline;
};

#ifdef OBJ
/*
 * Caseop generates the
 * pascal case statement code
 */
D 4
caseop(r)
	int *r;
E 4
I 4
caseop(rnode)
	WHI_CAS *rnode;
E 4
{
	register struct nl *p;
	register struct ct *ctab;
D 4
	register *cs;
	int *cl;
E 4
I 4
	register struct tnode *cs;
	extern char *lc;
E 4
	double low, high;
	short *brtab;
	char *brtab0;
	char *csend;
D 4
	int w, i, j, m, n;
E 4
I 4
	int w, j, m, n;
E 4
D 3
	int nr, goc;
E 3
I 3
	int goc;
	bool nr;
E 3

	goc = gocnt;
	/*
	 * Obtain selector attributes:
	 *	p	type
	 *	w	width
	 *	low	lwb(p)
	 *	high	upb(p)
	 */
D 4
	p = rvalue((int *) r[2], NLNIL , RREQ );
	if (p != NIL) {
E 4
I 4
	p = rvalue(rnode->expr, NLNIL , RREQ );

	{
	    register struct nl	*cl;

	if (p != NLNIL) {
E 4
		if (isnta(p, "bcsi")) {
			error("Case selectors cannot be %ss", nameof(p));
D 4
			p = NIL;
E 4
I 4
			p = NLNIL;
E 4
		} else {
			cl = p;
D 4
			if (p->class != RANGE)
E 4
I 4
			if (p->class != (char) RANGE)
E 4
				cl = p->type;
D 4
			if (cl == NIL)
				p = NIL;
E 4
I 4
			if (cl == NLNIL)
				p = NLNIL;
E 4
			else {
				w = width(p);
#ifdef DEBUG
				if (hp21mx)
					w = 2;
#endif
				low = cl->range[0];
				high = cl->range[1];
			}
		}
	}
I 4
	} /* local declaration */
	{
	    struct tnode	*cl;	/* list node */
E 4
	/*
	 * Count # of cases
	 */
	n = 0;
D 4
	for (cl = r[3]; cl != NIL; cl = cl[2]) {
		cs = cl[1];
		if (cs == NIL)
E 4
I 4
	for (cl = rnode->stmnt_list; cl != TR_NIL;
		cl = cl->list_node.next) {
		cs = cl->list_node.list;;
		if (cs == TR_NIL)
E 4
			continue;
D 4
		for (cs = cs[2]; cs != NIL; cs = cs[2])
E 4
I 4
		for (cs = cs->c_stmnt.const_list; cs != TR_NIL;
				cs = cs->list_node.next)
E 4
			n++;
	}
I 4
	} /* local declaration */
E 4
	/*
	 * Allocate case table space
	 */
D 4
	ctab = i = malloc(n * sizeof *ctab);
E 4
I 4
	{
		char *i;
	i = malloc((unsigned) n * sizeof *ctab);
E 4
D 2
	if (i == -1) {
E 2
I 2
	if (i == 0) {
E 2
		error("Ran out of memory (case)");
		pexit(DIED);
	}
I 4
	ctab = (struct ct *) i;
	}
E 4
	/*
	 * Check the legality of the
	 * labels and count the number
	 * of good labels
	 */
I 4
	{
	    register struct tnode *cl;
E 4
	m = 0;
D 4
	for (cl = r[3]; cl != NIL; cl = cl[2]) {
		cs = cl[1];
		if (cs == NIL)
E 4
I 4
	for (cl = rnode->stmnt_list; cl != TR_NIL;
		cl = cl->list_node.next) {
		cs = cl->list_node.list;
		if (cs == TR_NIL)
E 4
			continue;
D 4
		line = cs[1];
		for (cs = cs[2]; cs != NIL; cs = cs[2]) {
			gconst(cs[1]);
			if (p == NIL || con.ctype == NIL)
E 4
I 4
		line = cs->c_stmnt.line_no;
		for (cs = cs->c_stmnt.const_list; cs != TR_NIL;
				cs =  cs->list_node.next) {
			gconst(cs->list_node.list);
			if (p == NLNIL || con.ctype == NIL)
E 4
				continue;
D 4
			if (incompat(con.ctype, p, NIL )) {
E 4
I 4
			if (incompat(con.ctype, p, TR_NIL )) {
E 4
				cerror("Case label type clashed with case selector expression type");
				continue;
			}
			if (con.crval < low || con.crval > high) {
				error("Case label out of range");
				continue;
			}
			ctab[m].clong = con.crval;
			ctab[m].cline = line;
			m++;
		}
	}
D 4

E 4
I 4
	} /* decl of cl */
	{
		register int i;
E 4
	/*
	 * Check for duplicate labels
	 */
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			if (ctab[i].clong == ctab[j].clong) {
				if (i == j)
					continue;
				if (j < i)
					break;
D 4
				error("Multiply defined label in case, lines %d and %d", ctab[i].cline, ctab[j].cline);
E 4
I 4
				error("Multiply defined label in case, lines %d and %d", (char *) ctab[i].cline, (char *) ctab[j].cline);
E 4
			}
I 4
	}
E 4
	/*
	 * Put out case operator and
	 * leave space for the
	 * branch table
	 */
D 4
	if (p != NIL) {
		put(2, O_CASE1OP + (w >> 1), n);
		brtab = brtab0 = lc;
E 4
I 4
	if (p != NLNIL) {
		(void) put(2, O_CASE1OP + (w >> 1), n);
		brtab0 = lc;
		brtab = ((short *) brtab0);
E 4
		putspace(n * 2);
D 4
		put(1, O_CASEBEG);
E 4
I 4
		(void) put(1, O_CASEBEG);
		{
		    int i;
E 4
		for (i=0; i<m; i++)
D 3
			put( 2 , O_CASE1 + (w >> 1), ctab[i].clong);
E 3
I 3
			if (w <= 2)
D 4
				put(2 ,O_CASE1 + (w >> 1), (int)ctab[i].clong);
E 4
I 4
				(void) put(2 ,O_CASE1 + (w >> 1), (int)ctab[i].clong);
E 4
			else
D 4
				put(2 ,O_CASE4, ctab[i].clong);
E 3
		put(1, O_CASEEND);
E 4
I 4
				(void) put(2 ,O_CASE4, ctab[i].clong);
		}
		(void) put(1, O_CASEEND);
E 4
	}
	csend = getlab();
D 4
	put(2, O_TRA, csend);
E 4
I 4
	(void) put(2, O_TRA, csend);
E 4
	/*
	 * Free the case
	 * table space.
	 */
D 4
	free(ctab);
E 4
I 4
	free((char *) ctab);
E 4
	/*
	 * Generate code for each
	 * statement. Patch branch
	 * table to beginning of each
	 * statement and follow each
	 * statement with a branch back
	 * to the TRA above.
	 */
I 4
	{
	    register struct tnode *cl;
E 4
D 3
	nr = 1;
E 3
I 3
	nr = TRUE;
E 3
D 4
	for (cl = r[3]; cl != NIL; cl = cl[2]) {
		cs = cl[1];
		if (cs == NIL)
E 4
I 4
	for (cl = rnode->stmnt_list; cl != TR_NIL;
			cl = cl->list_node.next) {
		cs = cl->list_node.list;
		if (cs == TR_NIL)
E 4
			continue;
D 4
		if (p != NIL)
			for (cs = cs[2]; cs != NIL; cs = cs[2]) {
D 3
				patchfil(brtab - 1, lc - brtab0, 1);
E 3
I 3
				patchfil(brtab - 1, (long)(lc - brtab0), 1);
E 4
I 4
		if (p != NLNIL)
			for (cs = cs->c_stmnt.const_list; cs != TR_NIL;
				cs =  cs->list_node.next) {
#ifdef ADDR16
				patchfil(((char *) (brtab - 1)),
					(long)(lc - brtab0), 1);
#endif ADDR16
#ifdef ADDR32
				
				patchfil( ((unsigned long) (brtab - 1)),
					(long)(lc - brtab0), 1);
#endif ADDR32
E 4
E 3
				brtab++;
			}
D 4
		cs = cl[1];
E 4
I 4
		cs = cl->list_node.list;
E 4
		putcnt();
		level++;
D 4
		statement(cs[3]);
D 3
		nr &= noreach;
E 3
I 3
		nr = (noreach && nr);
E 3
		noreach = 0;
		put(2, O_TRA, csend);
E 4
I 4
		statement(cs->c_stmnt.stmnt);
		nr = (bool)(noreach && nr);
		noreach = FALSE;
		(void) put(2, O_TRA, csend);
E 4
		level--;
		if (gotos[cbn])
			ungoto();
	}
I 4
	} /* decl of cl */
E 4
	/*
	 * Patch the termination branch
	 */
D 4
	patch(csend);
E 4
I 4
#ifdef ADDR16
	patch((char *) csend);
#endif ADDR16
#ifdef ADDR32
	patch((unsigned long) csend);
#endif ADDR32
E 4
	noreach = nr;
	if (goc != gocnt)
		putcnt();
}
#endif OBJ
E 1
