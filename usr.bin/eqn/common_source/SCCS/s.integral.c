h42114
s 00010/00003/00039
d D 4.4 04/09/15 04:22:08 msokolov 4 3
c PostScript mode added, compiles
e
s 00003/00001/00039
d D 4.3 83/08/11 20:38:38 sam 3 2
c standardize sccs keyword lines
e
s 00008/00000/00032
d D 4.2 83/02/12 18:03:34 shannon 2 1
c merge eqn and neqn
e
s 00032/00000/00000
d D 4.1 83/02/11 18:28:11 shannon 1 0
c date and time created 83/02/11 18:28:11 by shannon
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

integral(p, p1, p2) {
I 2
#ifndef	NEQN
E 2
	if (p1 != 0)
		printf(".ds %d \\h'-0.4m'\\v'0.4m'\\*(%d\\v'-0.4m'\n", p1, p1);
	if (p2 != 0)
		printf(".ds %d \\v'-0.3m'\\*(%d\\v'0.3m'\n", p2, p2);
I 2
#endif
E 2
	if (p1 != 0 && p2 != 0)
		shift2(p, p1, p2);
	else if (p1 != 0)
		bshiftb(p, SUB, p1);
	else if (p2 != 0)
		bshiftb(p, SUP, p2);
	if(dbg)printf(".\tintegral: S%d; h=%d b=%d\n", 
		p, eht[p], ebase[p]);
	lfont[p] = ROM;
}

setintegral() {
	char *f;

	yyval = oalloc();
	f = "\\(is";
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
	printf(".ds %d \\s%d\\v'.1m'\\s+4%s\\s-4\\v'-.1m'\\s%d\n", 
		yyval, ps, f, ps);
	eht[yyval] = VERT( (((ps+4)*12)/10)*6 );
	ebase[yyval] = VERT( (ps*6*3)/10 );
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
	printf(".ds %d \\s%d\\v'.1m'\\s+4%s\\s-4\\v'-.1m'\\s%d\n", 
		yyval, ps, f, ps);
	eht[yyval] = VERT( ((ps+4)*12)*6 );
	ebase[yyval] = VERT( ps*6*3 );
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
	lfont[yyval] = rfont[yyval] = ROM;
}
E 1
