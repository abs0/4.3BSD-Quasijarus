h64180
s 00008/00003/00043
d D 4.4 04/09/15 04:22:12 msokolov 4 3
c PostScript mode added, compiles
e
s 00003/00001/00043
d D 4.3 83/08/11 20:39:21 sam 3 2
c standardize sccs keyword lines
e
s 00013/00000/00031
d D 4.2 83/02/12 18:03:48 shannon 2 1
c merge eqn and neqn
e
s 00031/00000/00000
d D 4.1 83/02/11 18:28:33 shannon 1 0
c date and time created 83/02/11 18:28:33 by shannon
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

boverb(p1, p2) int p1, p2; {
	int h, b, treg, d;

	treg = oalloc();
	yyval = p1;
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
	d = VERT((ps*6*3) / 10);	/* 0.3m */
	h = eht[p1] + eht[p2] + d;
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
	d = ps*6*3;			/* 0.3m */
	h = eht[p1] + eht[p2] + d;
#endif
#ifdef NEQN
E 4
	d = VERT(1);
	h = eht[p1] + eht[p2];
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
	b = eht[p2] - d;
	if(dbg)printf(".\tb:bob: S%d <- S%d over S%d; b=%d, h=%d\n", 
		yyval, p1, p2, b, h);
	nrwid(p1, ps, p1);
	nrwid(p2, ps, p2);
	printf(".nr %d \\n(%d\n", treg, p1);
	printf(".if \\n(%d>\\n(%d .nr %d \\n(%d\n", p2, treg, treg, p2);
I 2
#ifndef NEQN
E 2
	printf(".nr %d \\n(%d+\\s%d.5m\\s0\n", treg, treg, EFFPS(ps));
I 2
#endif NEQN
E 2
	printf(".ds %d \\v'%du'\\h'\\n(%du-\\n(%du/2u'\\*(%d\\\n", 
		yyval, eht[p2]-ebase[p2]-d, treg, p2, p2);
	printf("\\h'-\\n(%du-\\n(%du/2u'\\v'%du'\\*(%d\\\n", 
I 2
#ifndef NEQN
E 2
		p2, p1, -(eht[p2]-ebase[p2]+d+ebase[p1]), p1);
	printf("\\h'-\\n(%du-\\n(%du/2u+.1m'\\v'%du'\\l'\\n(%du-.2m'\\h'.1m'\\v'%du'\n", 
		 treg, p1, ebase[p1]+d, treg, d);
I 2
#else NEQN
		p2, p1, -eht[p2]+ebase[p2]-ebase[p1], p1);
	printf("\\h'-\\n(%du-\\n(%du-2u/2u'\\v'%du'\\l'\\n(%du'\\v'%du'\n", 
		 treg, p1, ebase[p1], treg, d);
#endif NEQN
E 2
	ebase[yyval] = b;
	eht[yyval] = h;
	lfont[yyval] = rfont[yyval] = 0;
	ofree(p2);
	ofree(treg);
}
E 1
