h18041
s 00007/00003/00023
d D 4.4 04/09/15 04:22:11 msokolov 4 3
c PostScript mode added, compiles
e
s 00003/00001/00023
d D 4.3 83/08/11 20:39:17 sam 3 2
c standardize sccs keyword lines
e
s 00004/00000/00020
d D 4.2 83/02/12 18:03:44 shannon 2 1
c merge eqn and neqn
e
s 00020/00000/00000
d D 4.1 83/02/11 18:28:31 shannon 1 0
c date and time created 83/02/11 18:28:31 by shannon
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

move(dir, amt, p) int dir, amt, p; {
	int a;

	yyval = p;
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
	a = VERT( (EFFPS(ps) * 6 * amt) / 100);
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
	a = VERT( (EFFPS(ps) * 6 * amt) / 10);
#endif
#ifdef NEQN
E 4
	a = VERT( (amt+49)/50 );	/* nearest number of half-lines */
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
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
E 1
