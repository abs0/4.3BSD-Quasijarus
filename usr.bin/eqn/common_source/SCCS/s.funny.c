h43261
s 00017/00003/00033
d D 4.4 04/09/15 04:22:07 msokolov 4 3
c PostScript mode added, compiles
e
s 00003/00001/00033
d D 4.3 83/08/11 20:38:30 sam 3 2
c standardize sccs keyword lines
e
s 00006/00000/00028
d D 4.2 83/02/12 18:03:29 shannon 2 1
c merge eqn and neqn
e
s 00028/00000/00000
d D 4.1 83/02/11 18:28:04 shannon 1 0
c date and time created 83/02/11 18:28:04 by shannon
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 3

# include "e.h"
# include "e.def"

funny(n) int n; {
	char *f;

	yyval = oalloc();
	switch(n) {
	case SUM:
I 4
#ifdef PS
		f = "\\SE5"; break;
#else
E 4
		f = "\\(*S"; break;
I 4
#endif
E 4
	case UNION:
		f = "\\(cu"; break;
	case INTER:	/* intersection */
		f = "\\(ca"; break;
	case PROD:
I 4
#ifdef PS
		f = "\\SD5"; break;
#else
E 4
		f = "\\(*P"; break;
I 4
#endif
E 4
	default:
		error(FATAL, "funny type %d in funny", n);
	}
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
	printf(".ds %d \\s%d\\v'.3m'\\s+5%s\\s-5\\v'-.3m'\\s%d\n", yyval, ps, f, ps);
	eht[yyval] = VERT( (ps+5)*6 -(ps*6*2)/10 );
	ebase[yyval] = VERT( (ps*6*3)/10 );
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
	printf(".ds %d \\s%d\\v'.3m'\\s+5%s\\s-5\\v'-.3m'\\s%d\n", yyval, ps, f, ps);
	eht[yyval] = (ps+5)*60 -(ps*6*2);
	ebase[yyval] = ps*6*3;
#endif
#ifdef NEQN
E 4
	printf(".ds %d %s\n", yyval, f);
	eht[yyval] = VERT(2);
	ebase[yyval] = 0;
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
	if(dbg)printf(".\tfunny: S%d <- %s; h=%d b=%d\n", 
		yyval, f, eht[yyval], ebase[yyval]);
	lfont[yyval] = rfont[yyval] = ROM;
}
E 1
