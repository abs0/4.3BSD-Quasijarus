#ifndef lint
static char sccsid[] = "@(#)sqrt.c	4.4 9/15/04";
#endif

# include "e.h"

sqrt(p2) int p2; {
#ifndef NEQN
	int nps;
#endif

#ifdef CAT
	nps = EFFPS(((eht[p2]*9)/10+5)/6);
#endif
#ifdef PS
	nps = EFFPS(((eht[p2]*9)/10+59)/60);
#endif
	yyval = p2;
#ifndef NEQN
#ifdef CAT
	eht[yyval] = VERT( (nps*6*12)/10 );
#endif
#ifdef PS
	eht[yyval] = nps*6*12;
#endif
	if(dbg)printf(".\tsqrt: S%d <- S%d;b=%d, h=%d\n", 
		yyval, p2, ebase[yyval], eht[yyval]);
	if (rfont[yyval] == ITAL)
		printf(".as %d \\|\n", yyval);
#endif NEQN
	nrwid(p2, ps, p2);
#ifdef CAT
	printf(".ds %d \\v'%du'\\s%d\\v'-.2m'\\(sr\\l'\\n(%du\\(rn'\\v'.2m'\\s%d", 
		yyval, ebase[p2], nps, p2, ps);
	printf("\\v'%du'\\h'-\\n(%du'\\*(%d\n", -ebase[p2], p2, p2);
	lfont[yyval] = ROM;
#endif
#ifdef PS
	printf(".ds %d \\v'%du'\\s%d\\v'-.2m'\\(sr\\l'\\n(%du\\(sx'\\v'.2m'\\s%d", 
		yyval, ebase[p2], nps, p2, ps);
	printf("\\v'%du'\\h'-\\n(%du'\\*(%d\n", -ebase[p2], p2, p2);
	lfont[yyval] = ROM;
#endif
#ifdef NEQN
	printf(".ds %d \\v'%du'\\e\\L'%du'\\l'\\n(%du'",
		p2, ebase[p2], -eht[p2], p2);
	printf("\\v'%du'\\h'-\\n(%du'\\*(%d\n", eht[p2]-ebase[p2], p2, p2);
	eht[p2] += VERT(1);
	if(dbg)printf(".\tsqrt: S%d <- S%d;b=%d, h=%d\n", 
		p2, p2, ebase[p2], eht[p2]);
#endif
}
