h02755
s 00007/00003/00097
d D 5.1 85/06/05 15:14:22 dist 6 5
c Add copyright
e
s 00000/00000/00100
d D 2.1 84/02/08 20:44:41 aoki 5 4
c synchronize to version 2
e
s 00000/00000/00100
d D 1.4 83/09/19 07:02:22 thien 4 3
c Restoring to unlinted version
e
s 00004/00001/00096
d D 1.3 83/08/19 05:04:57 thien 3 2
c The changes were made to allow successful linting
e
s 00001/00001/00096
d D 1.2 81/03/08 19:30:39 mckusic 2 1
c merge in onyx changes
e
s 00097/00000/00000
d D 1.1 80/08/27 19:57:25 peter 1 0
c date and time created 80/08/27 19:57:25 by peter
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

char	*tokname();

D 2
STATIC	bool bounce;
E 2
I 2
STATIC	short bounce;
E 2

/*
 * Printing representation of a
 * "character" - a lexical token
 * not in a yytok structure.
 * 'which' indicates which char * you want
 * should always be called as "charname(...,0),charname(...,1)"
 */
char *
charname(ch , which )
	int ch;
	int which;
{
	struct yytok Ych;

	Ych.Yychar = ch;
	Ych.Yylval = nullsem(ch);
	return (tokname(&Ych , which ));
}

/*
 * Printing representation of a token
 * 'which' as above.
 */
char *
tokname(tp , which )
	register struct yytok *tp;
	int	 	      which;
{
	register char *cp;
	register struct kwtab *kp;
	char	*cp2;

	cp2 = "";
	switch (tp->Yychar) {
		case YCASELAB:
			cp = "case-label";
			break;
		case YEOF:
			cp = "end-of-file";
			break;
		case YILLCH:
			cp = "illegal character";
			break;
		case 256:
			/* error token */
			cp = "error";
			break;
		case YID:
			cp = "identifier";
			break;
		case YNUMB:
			cp = "real number";
			break;
		case YINT:
		case YBINT:
			cp = "number";
			break;
		case YSTRING:
D 3
			cp = tp->Yylval;
E 3
I 3
			cp = (char *) tp->Yylval;
E 3
			cp = cp == NIL || cp[1] == 0 ? "character" : "string";
			break;
		case YDOTDOT:
			cp = "'..'";
			break;
		default:
			if (tp->Yychar < 256) {
				cp = "'x'\0'x'\0'x'\0'x'";
				/*
				 * for four times reentrant code!
				 * used to be:
				 * if (bounce = ((bounce + 1) & 1))
				 *	cp += 4;
				 */
				bounce = ( bounce + 1 ) % 4;
				cp += (4 * bounce);	/* 'x'\0 is 4 chars */
				cp[1] = tp->Yychar;
				break;
			}
			for (kp = yykey; kp->kw_str != NIL && kp->kw_val != tp->Yychar; kp++)
				continue;
			cp = "keyword ";
			cp2 = kp->kw_str;
	}
	return ( which ? cp2 : cp );
}
E 1
