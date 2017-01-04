h22522
s 00007/00003/00205
d D 5.1 85/06/05 15:12:59 dist 6 5
c Add copyright
e
s 00000/00000/00208
d D 2.1 84/02/08 20:44:35 aoki 5 4
c synchronize to version 2
e
s 00000/00000/00208
d D 1.4 83/09/19 07:02:19 thien 4 3
c Restoring to unlinted version
e
s 00011/00005/00197
d D 1.3 83/08/19 05:04:52 thien 3 2
c The changes were made to allow successful linting
e
s 00013/00013/00189
d D 1.2 81/03/08 19:30:26 mckusic 2 1
c merge in onyx changes
e
s 00202/00000/00000
d D 1.1 80/08/27 19:57:20 peter 1 0
c date and time created 80/08/27 19:57:20 by peter
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
#include "0.h"
I 3
#include "tree_ty.h"	/* must be included for yy.h */
E 3
#include "yy.h"

/*
 * Parser for 'yacc' output.
 * Specifially Modified for Berkeley Pascal
 */

int	yystate;	/* Current parser state */
D 3
int	*yypv;
E 3
I 3
union semstack *yypv;
E 3
D 2
unsigned yytshifts 1;	/* Number of "true" shifts */
E 2
I 2
unsigned yytshifts = 1;	/* Number of "true" shifts */
E 2

/*
 * Parse Tables
 */
int	yygo[];
int	yypgo[];
int	yyr1[];
int	yyr2[];
int	yyact[];
int	yypact[];

/*
 * Parse and parallel semantic stack
 */
D 3
int	yyv[MAXDEPTH];
E 3
I 3
union semstack	yyv[MAXDEPTH];
E 3
int	yys[MAXDEPTH];

/*
 * This routine parses the input stream, and
 * returns if it accepts, or if an unrecoverable syntax
 * error is encountered.
 */
yyparse()
{
	register int *ps, n, *p;
	int paniced, *panicps, idfail;

I 3
#ifdef lint
	panicps = (int *) 0;
#endif
E 3
	yystate = 0;
	yychar = yylex();
	OY.Yychar = -1;
	yyshifts = 3;
	paniced = 0;
	ps = &yys[0]-1;
	yypv = &yyv[0]-1;
#ifdef PXP
	yypw = &yyw[0]-1;
#endif

stack:
	/*
	 * Push new state and value.
	 */
	if (yypv >= &yyv[MAXDEPTH-1]) {
		yerror("Parse stack overflow");
		pexit(DIED);
	}
	*++ps = yystate;
	*++yypv = yyval;
#ifdef PXP
	yypw++;
#endif
newstate:
	/*
	 * Locate parsing actions for the
	 * new parser state.
	 */
	p = &yyact[ yypact[yystate+1] ]; 
D 3
actn:
E 3
	/*
	 * Search the parse actions table
	 * for something useful to do.
	 * While n is non-positive, it is the negation
	 * of the token we are testing for.
	 */
#ifdef PI
	if ((n = *p++) <= 0) {
		if (yychar < 0)
			yychar = yylex();
		do
D 2
			if ((n =+ yychar) != 0)
E 2
I 2
			if ((n += yychar) != 0)
E 2
				p++;
		while ((n = *p++) <= 0);
	}
#else
	while ((n = *p++) <= 0)
D 2
		if ((n =+ yychar) != 0)
E 2
I 2
		if ((n += yychar) != 0)
E 2
			p++;
#endif
	switch (n >> 12) {

		/*
		 * Shift.
		 */
		case 2:
#ifdef PXP
			yypw[1].Wseqid = yyseqid;
			yypw[1].Wcol = yycol;
#endif
			OYcopy();
			yystate = n & 07777;
D 3
			yyval = yylval;
E 3
I 3
			yyval.i_entry = yylval;
E 3
#ifdef PI
			yychar = -1;
#else
			yychar = yylex();
#endif
			yyshifts++;
			yytshifts++;
			goto stack;

		/*
		 * Reduce.
		 */
		case 3:
D 2
			n =& 07777;
E 2
I 2
			n &= 07777;
E 2
			N = yyr2[n];
D 3
			if (N == 1 && OY.Yychar == YID && !yyEactr(n, yypv[0])) {
E 3
I 3
			if (N == 1 && OY.Yychar == YID && !yyEactr(n,
							yypv[0].cptr)) {
E 3
				idfail = 1;
				goto errin;
			}
			OY.Yychar = -1;
D 2
			ps =- N;
			yypv =- N;
E 2
I 2
			ps -= N;
			yypv -= N;
E 2
#ifdef PXP
D 2
			yypw =- N;
E 2
I 2
			yypw -= N;
E 2
#endif
			yyval = yypv[1];
			yyactr(n);
			/*
			 * Use goto table to find next state.
			 */
			p = &yygo[yypgo[yyr1[n]]];
			while (*p != *ps && *p >= 0)
D 2
				p =+ 2;
E 2
I 2
				p += 2;
E 2
			yystate = p[1];
			goto stack;

		/*
		 * Accept.
		 */
		case 4:
			return;

		/*
		 * Error.
		 */
		case 1:
			idfail = 0;
errin:
			if ((paniced || yyshifts != 0) && yyrecover(ps, idfail)) {
				paniced = 0;
				ps = Ps;
				yystate = *ps;
				goto newstate;
			}
			/*
			 * Find a state where 'error' is a
			 * legal shift action.
			 */
			if (paniced && yyshifts <= 0 && ps >= panicps) {
D 2
				yypv =- (ps - panicps) + 1;
E 2
I 2
				yypv -= (ps - panicps) + 1;
E 2
#ifdef PXP
D 2
				yypw =- (ps - panicps) + 1;
E 2
I 2
				yypw -= (ps - panicps) + 1;
E 2
#endif
				ps = panicps - 1;
			}
			while (ps >= yys) {
D 2
				for (p = &yyact[ yypact[*ps+1] ] ; *p <= 0; p=+ 2)
E 2
I 2
				for (p = &yyact[ yypact[*ps+1] ] ; *p <= 0; p += 2)
E 2
					if (*p == -256) {
						panicps = ps;
						yystate= p[1] & 07777;
						yyOshifts = yyshifts;
						yyshifts = 0;
						paniced = 1;
						goto stack;
					}
				--ps;
				--yypv;
#ifdef PXP
				--yypw;
#endif
#ifdef PI
				if (OY.Yychar != YID)
D 2
					syneflg++;
E 2
I 2
					syneflg = TRUE;
E 2
#endif
				OY.Yychar = -1;
			}
			if (yychar == YEOF)
				yyunexeof();
			if (yystate == 1)
				yyexeof();
			yerror("Unrecoverable syntax error - QUIT");
			return;
	}
	panic("yyparse");
}
E 1
