h18738
s 00007/00003/00215
d D 5.1 85/06/05 14:19:28 dist 6 5
c Add copyright
e
s 00000/00000/00218
d D 2.1 84/02/08 20:42:14 aoki 5 4
c synchronize to version 2
e
s 00000/00000/00218
d D 1.4 83/09/19 06:58:43 thien 4 3
c Restoring to unlinted version
e
s 00010/00008/00208
d D 1.3 83/08/19 04:57:54 thien 3 2
c The changes were made to allow successful linting
e
s 00006/00006/00210
d D 1.2 81/03/08 19:25:49 mckusic 2 1
c merge in onyx changes
e
s 00216/00000/00000
d D 1.1 80/08/27 19:55:10 peter 1 0
c date and time created 80/08/27 19:55:10 by peter
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
D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
D 6
static char sccsid[] = "%Z%%M% %I% %G%";
I 3
#endif
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6
E 3
E 2

#include "whoami.h"
#ifdef OBJ
    /*
     *	and the rest of the file
     */
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"

/*
 * This array tells the type
 * returned by an arithmetic
 * operation.  It is indexed
 * by the logarithm of the
 * lengths base 2.
 */
#ifndef	DEBUG
char	arret[]	= {
	T4INT,		T4INT,		T4INT,		TDOUBLE,
	T4INT,		T4INT,		T4INT,		TDOUBLE,
	T4INT,		T4INT,		T4INT,		TDOUBLE,
	TDOUBLE,	TDOUBLE,	TDOUBLE,	TDOUBLE
};
#else
char	arret0[] = {
	T4INT,		T4INT,		T4INT,		TDOUBLE,
	T4INT,		T4INT,		T4INT,		TDOUBLE,
	T4INT,		T4INT,		T4INT,		TDOUBLE,
	TDOUBLE,	TDOUBLE,	TDOUBLE,	TDOUBLE
};
char	arret1[] = {
	T4INT,		T4INT,		T4INT,		TDOUBLE,
	T4INT,		T4INT,		T4INT,		TDOUBLE,
	T4INT,		T4INT,		T4INT,		TDOUBLE,
	TDOUBLE,	TDOUBLE,	TDOUBLE,	TDOUBLE
};
char	*arret = arret0;
#endif

/*
 * These array of arithmetic and set
 * operators are indexed by the
 * tree nodes and is highly dependent
 * on their order.  They thus take
 * on the flavor of magic.
 */
int	arop[] = {
	0, O_NEG2, O_MOD2, O_DIV2, O_DVD2, O_MUL2, O_ADD2, O_SUB2,
	O_REL2, O_REL2, O_REL2, O_REL2, O_REL2, O_REL2
};
int	setop[] = {
	O_MULT, O_ADDT, O_SUBT,
	O_RELT, O_RELT, O_RELT, O_RELT, O_RELT, O_RELT,
};

/*
 * The following array is
 * used when operating on
 * two reals since they are
 * shoved off in a corner in
 * the interpreter table.
 */
int	ar8op[] = {
	O_DVD8, O_MUL8, O_ADD8, O_SUB8,
	O_REL8, O_REL8, O_REL8, O_REL8, O_REL8, O_REL8,
};

/*
 * The following arrays, which are linearizations
 * of two dimensional arrays, are the offsets for
 * arithmetic, relational and assignment operations
 * indexed by the logarithms of the argument widths.
 */
#ifndef	DEBUG
char artab[] = {
	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD42-O_ADD2,	O_ADD82-O_ADD2,
	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD42-O_ADD2,	O_ADD82-O_ADD2,
	O_ADD24-O_ADD2,	O_ADD24-O_ADD2,	O_ADD4-O_ADD2,	O_ADD84-O_ADD2,
	O_ADD28-O_ADD2,	O_ADD28-O_ADD2,	O_ADD48-O_ADD2,	-1
};
#else
char artab0[] = {
	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD42-O_ADD2,	O_ADD82-O_ADD2,
	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD42-O_ADD2,	O_ADD82-O_ADD2,
	O_ADD24-O_ADD2,	O_ADD24-O_ADD2,	O_ADD4-O_ADD2,	O_ADD84-O_ADD2,
	O_ADD28-O_ADD2,	O_ADD28-O_ADD2,	O_ADD48-O_ADD2,	-1
};
char artab1[] = {
	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD82-O_ADD2,
	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD82-O_ADD2,
	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD2-O_ADD2,	O_ADD84-O_ADD2,
	O_ADD28-O_ADD2,	O_ADD28-O_ADD2,	O_ADD28-O_ADD2,	-1
};
char	*artab = artab0;
#endif
#ifndef DEBUG
char reltab[] = {
	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL42-O_REL2,	O_REL82-O_REL2,
	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL42-O_REL2,	O_REL82-O_REL2,
	O_REL24-O_REL2,	O_REL24-O_REL2,	O_REL4-O_REL2,	O_REL84-O_REL2,
	O_REL28-O_REL2,	O_REL28-O_REL2,	O_REL48-O_REL2,	O_REL8-O_REL2
};
#else
char reltab0[] = {
	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL42-O_REL2,	O_REL82-O_REL2,
	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL42-O_REL2,	O_REL82-O_REL2,
	O_REL24-O_REL2,	O_REL24-O_REL2,	O_REL4-O_REL2,	O_REL84-O_REL2,
	O_REL28-O_REL2,	O_REL28-O_REL2,	O_REL48-O_REL2,	O_REL8-O_REL2
};
char reltab1[] = {
	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL82-O_REL2,
	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL82-O_REL2,
	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL2-O_REL2,	O_REL82-O_REL2,
	O_REL28-O_REL2,	O_REL28-O_REL2,	O_REL28-O_REL2,	O_REL8-O_REL2
};
char *reltab = reltab0;
#endif

#ifndef DEBUG
char asgntab[] = {
	O_AS21-O_AS2,	O_AS21-O_AS2,	O_AS41-O_AS2,	-1,
	O_AS2-O_AS2,	O_AS2-O_AS2,	O_AS42-O_AS2,	-1,
	O_AS24-O_AS2,	O_AS24-O_AS2,	O_AS4-O_AS2,	-1,
	O_AS28-O_AS2,	O_AS28-O_AS2,	O_AS48-O_AS2,	O_AS8-O_AS2,
};
#else
char asgntb0[] = {
	O_AS21-O_AS2,	O_AS21-O_AS2,	O_AS41-O_AS2,	-1,
	O_AS2-O_AS2,	O_AS2-O_AS2,	O_AS42-O_AS2,	-1,
	O_AS24-O_AS2,	O_AS24-O_AS2,	O_AS4-O_AS2,	-1,
	O_AS28-O_AS2,	O_AS28-O_AS2,	O_AS48-O_AS2,	O_AS8-O_AS2,
};
char asgntb1[] = {
	O_AS21-O_AS2,	O_AS21-O_AS2,	O_AS21-O_AS2,	-1,
	O_AS2-O_AS2,	O_AS2-O_AS2,	O_AS2-O_AS2,	-1,
	O_AS2-O_AS2,	O_AS2-O_AS2,	O_AS2-O_AS2,	-1,
	O_AS28-O_AS2,	O_AS28-O_AS2,	O_AS28-O_AS2,	O_AS4-O_AS2,
};
char *asgntab = asgntb0;
#endif

#ifdef DEBUG
genmx()
{

	arret = arret1;
	artab = artab1;
	reltab = reltab1;
	asgntab = asgntb1;
}
#endif

/*
 * Gen generates code for assignments,
 * and arithmetic and string operations
 * and comparisons.
 */
struct nl *
gen(p, o, w1, w2)
	int p, o, w1, w2;
{
	register i, j;
D 3
	int op, off;
E 3
I 3
	int op;
E 3

	switch (p) {
I 3
		default:
			panic("gen");
E 3
		case O_AS2:
		case NIL:
			i = j = -1;
			/*
			 * Take the log2 of the widths
			 * and linearize them for indexing.
			 * width for indexing.
			 */
#ifdef DEBUG
			if (hp21mx) {
				if (w1 == 4)
					w1 = 8;
				if (w2 == 4)
					w2 = 8;
			}
#endif
			do i++; while (w1 >>= 1);
			do j++; while (w2 >>= 1);
			i <<= 2;
			i |= j;
			if (p == O_AS2) {
D 2
				put1(O_AS2 + asgntab[i]);
E 2
I 2
D 3
				put(1, O_AS2 + asgntab[i]);
E 3
I 3
				(void) put(1, O_AS2 + asgntab[i]);
E 3
E 2
				return (NIL);
			}
			op = arop[o];
			if (op == O_REL2) {
D 2
				put1((op + reltab[i]) | (o - T_EQ) << 8+INDX);
E 2
I 2
D 3
				put(1, (op + reltab[i]) | (o - T_EQ) << 8+INDX);
E 3
I 3
				(void) put(1, (op + reltab[i]) | (o - T_EQ) << 8+INDX);
E 3
E 2
				return (nl+TBOOL);
			}
D 2
			put1(i == 15 ? ar8op[o-T_DIVD] : op | artab[i]);
E 2
I 2
D 3
			put(1, i == 15 ? ar8op[o-T_DIVD] : op | artab[i]);
E 3
I 3
			(void) put(1, i == 15 ? ar8op[o-T_DIVD] : op | artab[i]);
E 3
E 2
			return (op == O_DVD2 && !divchk ? nl+TDOUBLE : nl+arret[i]);
		case TREC:
		case TSTR:
D 2
			put2(O_RELG | (o - T_EQ) << 8+INDX, w1);
E 2
I 2
D 3
			put(2, O_RELG | (o - T_EQ) << 8+INDX, w1);
E 3
I 3
			(void) put(2, O_RELG | (o - T_EQ) << 8+INDX, w1);
E 3
E 2
			return (nl+TBOOL);
		case TSET:
			op = setop[o-T_MULT];
			if (op == O_RELT)
				op |= (o - T_EQ)<<8+INDX;
D 2
			put2(op, w1);
E 2
I 2
D 3
			put(2, op, w1);
E 3
I 3
			(void) put(2, op, w1);
E 3
E 2
			return (o >= T_EQ ? nl+TBOOL : nl+TSET);
D 3
		default:
			panic("gen");
E 3
	}
}
#endif OBJ
E 1
