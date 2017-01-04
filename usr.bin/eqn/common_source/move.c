#ifndef lint
static char sccsid[] = "@(#)move.c	4.4 9/15/04";
#endif

# include "e.h"
# include "e.def"

move(dir, amt, p) int dir, amt, p; {
	int a;

	yyval = p;
#ifdef CAT
	a = VERT( (EFFPS(ps) * 6 * amt) / 100);
#endif
#ifdef PS
	a = VERT( (EFFPS(ps) * 6 * amt) / 10);
#endif
#ifdef NEQN
	a = VERT( (amt+49)/50 );	/* nearest number of half-lines */
#endif
	printf(".ds %d ", yyval);
	if( dir == FWD || dir == BACK )	/* fwd, back */
		printf("\\h'%s%du'\\*(%d\n", (dir==BACK) ? "-" : "", a, p);
	else if (dir == UP)
		printf("\\v'-%du'\\*(%d\\v'%du'\n", a, p, a);
	else if (dir == DOWN)
		printf("\\v'%du'\\*(%d\\v'-%du'\n", a, p, a);
	if(dbg)printf(".\tmove %d dir %d amt %d; h=%d b=%d\n", 
		p, dir, a, eht[yyval], ebase[yyval]);
}
