h15550
s 00007/00003/00161
d D 5.1 85/06/05 15:12:18 dist 7 6
c Add copyright
e
s 00000/00000/00164
d D 2.1 84/02/08 20:44:29 aoki 6 5
c synchronize to version 2
e
s 00000/00000/00164
d D 1.5 83/09/19 07:02:16 thien 5 4
c Restoring to unlinted version
e
s 00005/00002/00159
d D 1.4 83/08/19 05:04:45 thien 4 3
c The changes were made to allow successful linting
e
s 00012/00000/00149
d D 1.3 82/03/29 15:32:13 peter 3 2
c force error message when separate compilation decls are incomplete.
e
s 00001/00001/00148
d D 1.2 81/03/08 19:30:18 mckusic 2 1
c merge in onyx changes
e
s 00149/00000/00000
d D 1.1 80/08/27 19:57:18 peter 1 0
c date and time created 80/08/27 19:57:18 by peter
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

I 4
#ifndef lint
E 4
D 7
static	char sccsid[] = "%Z%%M% %I% %G%";
I 4
#endif
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7
E 4

#include "whoami.h"
#include "0.h"
I 4
#include "tree_ty.h"	/* must be included for yy.h */
E 4
#include "yy.h"

struct yytok oldpos;
/*
 * The routine yyPerror coordinates the panic when
 * the correction routines fail. Three types of panics
 * are possible - those in a declaration part, those
 * in a statement part, and those in an expression.
 *
 * Declaration part panics consider insertion of "begin",
 * expression part panics will stop on more symbols.
 * The panics are otherwise the same.
 *
 * ERROR MESSAGE SUPPRESSION STRATEGY: August 11, 1977
 *
 * If the parser has not made at least 2 moves since the last point of
 * error then we want to suppress the supplied error message.
 * Otherwise we print it.
 * We then skip input up to the next solid symbol.
 */
yyPerror(cp, kind)
	char *cp;
	register int kind;
{
	register int ishifts, brlev;

D 4
	copy(&oldpos, &Y, sizeof oldpos);
E 4
I 4
	copy((char *) (&oldpos), (char *) (&Y), sizeof oldpos);
E 4
	brlev = 0;
	if (yychar < 0)
		yychar = yylex();
	for (ishifts = yyshifts; ; yychar = yylex(), yyshifts++)
		switch (yychar) {
			case YILLCH:
				yerror("Illegal character");
				if (ishifts == yyshifts)
					yyOshifts = 0;
				continue;
			case YEOF:
I 3
				if (kind == PDECL) {
					/*
					 * we have paniced to end of file
					 * during declarations. Separately
					 * compiled segments can syntactically
					 * exit without any error message, so
					 * we force one here.
					 */
					yerror(cp);
					continuation();
					yyunexeof();
				}
E 3
				goto quiet;
			case ';':
				if (kind == PPROG)
					continue;
				if (kind == PDECL)
					yychar = yylex();
				goto resume;
			case YEND:
				if (kind == PPROG)
					continue;
			case YPROCEDURE:
			case YFUNCTION:
				goto resume;
			case YLABEL:
			case YTYPE:
			case YCONST:
			case YVAR:
				if (kind == PSTAT) {
					yerror("Declaration found when statement expected");
					goto quiet;
				}
			case YBEGIN:
				goto resume;
			case YFOR:
			case YREPEAT:
			case YWHILE:
			case YGOTO:
			case YIF:
				if (kind != PDECL)
					goto resume;
				yerror("Expected keyword begin after declarations, before statements");
				unyylex(&Y);
				yychar = YBEGIN;
				yylval = nullsem(YBEGIN);
				goto quiet;
			case YTHEN:
			case YELSE:
			case YDO:
				if (kind == PSTAT) {
					yychar = yylex();
					goto resume;
				}
				if (kind == PEXPR)
					goto resume;
				continue;
			case ')':
			case ']':
				if (kind != PEXPR)
					continue;
				if (brlev == 0)
					goto resume;
				if (brlev > 0)
					brlev--;
				continue;
			case '(':
			case '[':
				brlev++;
				continue;
			case ',':
				if (brlev != 0)
					continue;
			case YOF:
			case YTO:
			case YDOWNTO:
				if (kind == PEXPR)
					goto resume;
				continue;
#ifdef PI
			/*
			 * A rough approximation for now
			 * Should be much more lenient on suppressing
			 * warnings.
			 */
			case YID:
D 2
				syneflg++;
E 2
I 2
				syneflg = TRUE;
E 2
				continue;
#endif
		}
resume:
	if (yyOshifts >= 2) {
		if (yychar != -1)
			unyylex(&Y);
D 4
		copy(&Y, &oldpos, sizeof Y);
E 4
I 4
		copy((char *) (&Y), (char *) (&oldpos), sizeof Y);
E 4
		yerror(cp);
		yychar = yylex();
	}
quiet:
	if (yyshifts - ishifts > 2 && opt('r')) {
		setpfx('r');
		yerror("Parsing resumes");
	}
	/*
	 * If we paniced in the statement part,
	 * and didn't stop at a ';', then we insert
	 * a ';' to prevent the recovery from immediately
	 * inserting one and complaining about it.
	 */
	if (kind == PSTAT && yychar != ';') {
		unyylex(&Y);
		yyshifts--;
		yytshifts--;
		yychar = ';';
		yylval = nullsem(';');
	}
}
E 1
