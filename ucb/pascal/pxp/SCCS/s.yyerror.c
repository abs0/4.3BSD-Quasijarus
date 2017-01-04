h62732
s 00010/00002/00112
d D 5.1 85/06/05 15:56:11 dist 4 3
c Add copyright
e
s 00000/00000/00114
d D 2.1 84/02/08 20:22:44 aoki 3 2
c synchronizing at version 2
e
s 00001/00000/00113
d D 1.2 83/05/11 21:49:02 peter 2 1
c since input buffer is variable sized, people who include yy.h need whoami.h.
e
s 00113/00000/00000
d D 1.1 81/03/02 21:29:31 peter 1 0
c date and time created 81/03/02 21:29:31 by peter
e
u
U
t
T
I 1
D 4
static	char *sccsid = "%W% (Berkeley) %G%";
/* Copyright (c) 1979 Regents of the University of California */
E 4
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 4
/*
 * pi - Pascal interpreter code translator
 *
 * Charles Haley, Bill Joy UCB
 * Version 1.2 January 1979
 *
 *
 * pxp - Pascal execution profiler
 *
 * Bill Joy UCB
 * Version 1.2 January 1979
 */

I 2
#include "whoami.h"
E 2
#include "0.h"
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
yerror(s, a1, a2, a3, a4, a5)
	char *s;
{
#ifdef PI
	char buf[256];
#endif
	register int i, j;
	static yySerrs;
#ifdef PXP
/*
	int ofout;
*/
#endif

	if (errpfx == 'w' && opt('w') != 0)
		return;
#ifdef PXP
/*
	flush();
	ofout = fout[0];
	fout[0] = errout;
*/
#endif
	yyResume = 0;
#ifdef PI
	geterr(s, buf);
	s = buf;
#endif
	yysync();
	putc(errpfx, stderr);
	putc(' ', stderr);
	for (i = 3; i < yyecol; i++)
		putc('-', stderr);
	fprintf(stderr, "^--- ");
/*
	if (yyecol > 60)
		printf("\n\t");
*/
	fprintf(stderr, s, a1, a2, a3, a4, a5);
	putc('\n', stderr);
	if (errpfx == 'E')
#ifdef PI
		eflg++, cgenflg++;
#endif
#ifdef PXP
		eflg++;
#endif
	errpfx = 'E';
	yySerrs++;
	if (yySerrs >= MAXSYNERR) {
		yySerrs = 0;
		yerror("Too many syntax errors - QUIT");
		pexit(ERRS);
	}
#ifdef PXP
/*
	flush();
	fout[0] = ofout;
*/
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
		error("End matched %s on line %d", what, where);
		return;
	}
	if (where < 0)
		where = -where;
	yerror("Inserted keyword end matching %s on line %d", what, where);
}
E 1
