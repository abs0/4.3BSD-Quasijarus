h31549
s 00003/00000/00108
d D 5.2 86/05/06 16:44:10 mckusick 7 6
c cannot have error continuations for fatal errors
e
s 00007/00003/00101
d D 5.1 85/06/05 15:06:46 dist 6 5
c Add copyright
e
s 00000/00000/00104
d D 2.1 84/02/08 20:43:21 aoki 5 4
c synchronize to version 2
e
s 00000/00000/00104
d D 1.4 83/09/19 07:01:52 thien 4 3
c Restoring to unlinted version
e
s 00009/00004/00095
d D 1.3 83/08/19 05:04:07 thien 3 2
c The changes were made to allow successful linting
e
s 00002/00002/00097
d D 1.2 81/03/08 19:29:47 mckusic 2 1
c merge in onyx changes
e
s 00099/00000/00000
d D 1.1 80/08/27 19:57:04 peter 1 0
c date and time created 80/08/27 19:57:04 by peter
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
I 3
#include "tree_ty.h"	/* must be included for yy.h */
E 3
#include "yy.h"

/*
 * Yerror prints an error
 * message and then returns
 * NIL for the tree if needed.
 * The error is flagged on the
 * current line which is printed
 * if the listing is turned off.
#ifdef PXP
 *
 * As is obvious from the fooling around
 * with fout below, the Pascal system should
 * be changed to use the new library "lS".
#endif
 */
I 3
/*VARARGS*/
E 3
yerror(s, a1, a2, a3, a4, a5)
	char *s;
I 3
	char *a1, *a2, *a3, *a4, *a5;
E 3
{
#ifdef PI
	char buf[256];
#endif
D 3
	register int i, j;
E 3
I 3
	register int i;
E 3
	static yySerrs;
#ifdef PXP
	int ofout;
#endif

	if (errpfx == 'w' && opt('w') != 0) {
		errpfx = 'E';
		return;
	}
I 7
	/* no continuations allowed here */
	if (errpfx == ' ')
		errpfx = 'E';
E 7
#ifdef PXP
	flush();
	ofout = fout[0];
	fout[0] = errout;
#endif
	yyResume = 0;
#ifdef PI
D 3
	geterr(s, buf);
E 3
I 3
	geterr((int) s, buf);
E 3
	s = buf;
#endif
	yysync();
	pchr(errpfx);
	pchr(' ');
	for (i = 3; i < yyecol; i++)
		pchr('-');
	printf("^--- ");
/*
	if (yyecol > 60)
		printf("\n\t");
*/
	printf(s, a1, a2, a3, a4, a5);
	pchr('\n');
	if (errpfx == 'E')
#ifdef PI
D 2
		eflg++, codeoff();
E 2
I 2
		eflg = TRUE, codeoff();
E 2
#endif
#ifdef PXP
D 2
		eflg++;
E 2
I 2
		eflg = TRUE;
E 2
#endif
	errpfx = 'E';
	yySerrs++;
	if (yySerrs >= MAXSYNERR) {
		yySerrs = 0;
		yerror("Too many syntax errors - QUIT");
		pexit(ERRS);
	}
#ifdef PXP
	flush();
	fout[0] = ofout;
	return (0);
#endif
}

/*
 * A bracketing error message
 */
brerror(where, what)
	int where;
	char *what;
{

	if (where == 0) {
		line = yyeline;
		setpfx(' ');
D 3
		error("End matched %s on line %d", what, where);
E 3
I 3
		error("End matched %s on line %d", what, (char *) where);
E 3
		return;
	}
	if (where < 0)
		where = -where;
D 3
	yerror("Inserted keyword end matching %s on line %d", what, where);
E 3
I 3
	yerror("Inserted keyword end matching %s on line %d", what, (char *) where);
E 3
}
E 1
