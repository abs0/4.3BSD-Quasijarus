h46058
s 00001/00001/00239
d D 5.2 87/04/06 12:09:13 bostic 9 8
c printf format/argument mismatch
e
s 00007/00003/00233
d D 5.1 85/06/05 15:06:01 dist 8 7
c Add copyright
e
s 00000/00000/00236
d D 2.1 84/02/08 20:44:04 aoki 7 6
c synchronize to version 2
e
s 00000/00000/00236
d D 1.6 83/09/19 07:01:49 thien 6 5
c Restoring to unlinted version
e
s 00006/00003/00230
d D 1.5 83/08/19 05:04:00 thien 5 4
c The changes were made to allow successful linting
e
s 00002/00000/00231
d D 1.4 82/08/30 16:19:24 mckusick 4 3
c reduce cost for replacing identifier (ie external) with keyword forward
e
s 00000/00001/00231
d D 1.3 82/08/27 00:34:19 mckusick 3 2
c convert "assert" from being a reserved word to being a non-standard procedure
e
s 00003/00003/00229
d D 1.2 81/03/08 19:29:34 mckusic 2 1
c merge in onyx changes
e
s 00232/00000/00000
d D 1.1 80/08/27 19:57:01 peter 1 0
c date and time created 80/08/27 19:57:01 by peter
e
u
U
t
T
I 1
D 8
/* Copyright (c) 1979 Regents of the University of California */
E 8
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 8

I 5
#ifndef lint
E 5
D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
D 8
static char sccsid[] = "%Z%%M% %I% %G%";
I 5
#endif
E 8
I 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8
E 5
E 2

#include "whoami.h"
#include "0.h"
I 5
#include "tree_ty.h"	/* must be included for yy.h */
E 5
#include "yy.h"

/*
 * Symbol costs for Pascal.
 *
 * Cost strategy of August 14, 1977.
 *
 * The costs determined by the routines in this file are used by
 * the recovery in choosing appropriate corrections.
 * The cost vectors and the error productions in the grammar
 * work together to define the corrective capacity of the grammar.
 *
 * The costs here largely derive from those given in Steve Rhode's
 * thesis for the Pascal-I error correcting parser which he implemented.
 * Some minor changes have been made to adjust for the fact that
 * the current error recovery is not as "smart", both because of the
 * limited forward move and because of the lack of any type information
 * about identifiers.
 *
 * These adjustments largely take the form of increased costs for certain
 * tokens, noticeably keywords which are major brackets such as "begin"
 * "label", "procedure", etc.
 *
 * The overall weighting strategy is still similar to Rhodes' strategy.
 * The costs can be considered:
 *
 *	LOW	<= 3
 *	MEDIUM	4 or 5
 *	HIGH	>= 6
 */
 
/*
 * Insertion costs
 *
 * In addition to the normal symbol insertion costs,
 * there are zero cost insertions here.
 * The current error recovery system treats symbols
 * which have zero insertion cost in a special way,
 * inserting them but suppressing diagnostics.
 * This allows the system to hold of on bracketing
 * error diagnostics about missing end's until the
 * reduction occurs which knows the line number of the
 * corresponding "begin", "repeat", etc.
 * A more intelligent and useful diagnostic can then
 * be printed.
 *
 * Although this routine never allows the insertion
 * of the keyword begin, it can be inserted after a
 * procedure or function body starts, if it was omitted
 * by a special case in the panic routine, which notices
 * the keywords in the statement body of the procedure
 * and inserts the begin to recover.
 *
 * Similarly, we do not insert end-of-file, but
 * the fact that end-of-file is the unique input
 * is noticed by the recovery routines as a special
 * case and handled there.
 */
inscost(sy, before)
	register int sy, before;
{

	switch (before) {
		case YEND:
			if (sy == YEND)
				break;
		case YPROCEDURE:
		case YFUNCTION:
			if (sy == YUNTIL || sy == YEND)
				return (0);
	}
	switch (sy) {
		case ';':
			return (1);
		case ',':
		case ':':
		case YOF:
		case YDO:
			return (2);
		case YARRAY:
		case '+':
		case '*':
			return (3);
		default:
			return (4);
		case '^':
		case YNOT:
		case YLABEL:
		case YCONST:
		case YTYPE:
		case YVAR:
		case YUNTIL:
		case '(':
		case '[':
		case YWHILE:
		case YWITH:
D 3
		case YASSERT:
E 3
			return (5);
		case YPROCEDURE:
		case YFUNCTION:
		case YCASE:
			return (6);
		case YEND:
			return (8);
		case YBEGIN:
		case YEOF:
		case YREPEAT:
		case YRECORD:
			return (INFINITY);
	}
}

/*
 * Replacement costs
 *
 * Most replacement costs are the same as an insertion
 * plus a deletion cost.  One special case is the replacement
 * of a large number of keywords by an identifier.
 * These are given lower costs, especially the keyword "to".
 */
repcost(what, with)
	register int what, with;
{
	register int c;

	if (with == what)
		return (INFINITY);
	if (with == YID && what > ERROR)
		switch (what) {
			case YID:
			case YDOTDOT:
			case YINT:
			case YBINT:
			case YSTRING:
			case YNUMB:
				break;
			case YTO:
				return (3);
			default:
				return (5);
			case YRECORD:
			case YTHEN:
				return (6);
			case YBEGIN:
				break;
		}
I 4
	if (what == YID && with == YFORWARD)
		return(5);
E 4
	if (what == ';' && (with == ',' || with == '.'))
		return (CLIMIT - 1);
D 5
	c = delcost(what) + inscost(with);
E 5
I 5
	c = delcost(what) + inscost(with, what);
E 5
	/*
	 * It costs extra to replace something which has
	 * semantics by something which doesn't.
	 */
	if (nullsem(what) == NIL && nullsem(with) != NIL)
D 2
		c =+ 4;
E 2
I 2
		c += 4;
E 2
	return (c);
}

/*
 * Deletion costs
 */
delcost(what)
	int what;
{

	switch (what) {
		case '.':
		case ':':
		case ',':
		case '=':
		case '(':
			return (3);
		case YELSE:
		case YTHEN:
			return (4);
		default:
			return (5);
		case YLABEL:
		case YCONST:
		case YTYPE:
		case YVAR:
			return (10);
		case YPROCEDURE:
		case YFUNCTION:
		case YBEGIN:
		case YEND:
			return ((CLIMIT * 3) / 4);
		case ';':
		case YEOF:
			return (INFINITY);
	}
}
#ifdef DEBUG

/*
 * Routine to print out costs with "-K" option.
 */
D 2
char	yysyms[]	";,:=*+/-|&()[]<>~^";
E 2
I 2
char	yysyms[] = ";,:=*+/-|&()[]<>~^";
E 2


yycosts()
{
	register int c;
	register char *cp;

	printf("Insert\tDelete\tRep(ID)\tSymbol\n");
	for (cp = yysyms; *cp; cp++)
		yydocost(*cp);
	for (c = ERROR + 1; c < YLAST; c++)
		yydocost(c);
#ifdef PXP
	flush();
#endif
}

yydocost(c)
	int c;
{

	printf("%4d\t", inscost(c, -1));
	printf("%4d\t", delcost(c));
D 5
	if (repcost(c, YID) != inscost(YID) + delcost(c))
E 5
I 5
	if (repcost(c, YID) != inscost(YID, c) + delcost(c))
E 5
		printf("%4d", repcost(c, YID));
D 5
	printf("\t%s%s\n", charname(c));
E 5
I 5
D 9
	printf("\t%s%s\n", charname(c,1));
E 9
I 9
	printf("\t%s\n", charname(c,1));
E 9
E 5
}
#endif
E 1
