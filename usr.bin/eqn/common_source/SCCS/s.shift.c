h07133
s 00011/00009/00175
d D 4.5 04/09/17 22:12:45 msokolov 5 4
c only do the italic padding on CAT, not needed on PS with Adobe fonts
e
s 00024/00009/00160
d D 4.4 04/09/15 04:22:15 msokolov 4 3
c PostScript mode added, compiles
e
s 00003/00001/00166
d D 4.3 83/08/11 20:39:35 sam 3 2
c standardize sccs keyword lines
e
s 00066/00004/00101
d D 4.2 83/02/12 18:04:03 shannon 2 1
c merge eqn and neqn
e
s 00105/00000/00000
d D 4.1 83/02/11 18:28:41 shannon 1 0
c date and time created 83/02/11 18:28:41 by shannon
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
#include "e.def"

bshiftb(p1, dir, p2) int p1, dir, p2; {
D 2
	int shval, diffps, effps, effps2, d1, h1, b1, h2, b2;
E 2
I 2
	int shval, d1, h1, b1, h2, b2;
#ifndef NEQN
	int diffps, effps, effps2;
E 2
	char *sh1, *sh2;
I 2
#endif NEQN
E 2

	yyval = p1;
	h1 = eht[p1];
	b1 = ebase[p1];
	h2 = eht[p2];
	b2 = ebase[p2];
I 2
#ifndef NEQN
E 2
	effps = EFFPS(ps);
	effps2 = EFFPS(ps+deltaps);
	diffps = deltaps;
	sh1 = sh2 = "";
D 2
	if( dir == SUB ) {
E 2
I 2
#endif NEQN
	if( dir == SUB ) {	/* subscript */
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
		/* top 1/2m above bottom of main box */
		d1 = VERT( (effps2*6)/2 );
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
		/* top 1/2m above bottom of main box */
		d1 = VERT( effps2*30 );
#endif
#ifdef NEQN
E 4
		d1 = VERT(1);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
		shval = - d1 + h2 - b2;
		if( d1+b1 > h2 ) /* move little sub down */
			shval = b1-b2;
		ebase[yyval] = b1 + max(0, h2-b1-d1);
		eht[yyval] = h1 + max(0, h2-b1-d1);
I 2
D 5
#ifndef NEQN
E 5
I 5
#ifdef CAT
E 5
E 2
		if (rfont[p1] == ITAL && lfont[p2] == ROM)
			sh1 = "\\|";
		if (rfont[p2] == ITAL)
			sh2 = "\\|";
I 2
D 5
#endif NEQN
E 5
I 5
#endif
E 5
E 2
	} else {	/* superscript */
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
		/* 4/10 up main box */
		d1 = VERT( (effps*6*2)/10 );
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
		/* 4/10 up main box */
		d1 = VERT( effps*6*2 );
#endif
#ifdef NEQN
E 4
		d1 = VERT(1);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
		ebase[yyval] = b1;
I 2
#ifndef NEQN
E 2
		shval = -VERT( (4 * (h1-b1)) / 10 ) - b2;
		if( VERT(4*(h1-b1)/10) + h2 < h1-b1 )	/* raise little super */
I 2
#else NEQN
		shval = -VERT(1) - b2;
		if( VERT(1) + h2 < h1-b1 )	/* raise little super */
#endif NEQN
E 2
			shval = -(h1-b1) + h2-b2 - d1;
I 2
#ifndef NEQN
E 2
		eht[yyval] = h1 + max(0, h2-VERT((6*(h1-b1))/10));
I 5
#else NEQN
		eht[yyval] = h1 + max(0, h2 - VERT(1));
#endif NEQN
#ifdef CAT
E 5
		if (rfont[p1] == ITAL)
			sh1 = "\\|";
		if (rfont[p2] == ITAL)
			sh2 = "\\|";
I 2
D 5
#else NEQN
		eht[yyval] = h1 + max(0, h2 - VERT(1));
#endif NEQN
E 5
I 5
#endif
E 5
E 2
	}
	if(dbg)printf(".\tb:b shift b: S%d <- S%d vert %d S%d vert %d; b=%d, h=%d\n", 
		yyval, p1, shval, p2, -shval, ebase[yyval], eht[yyval]);
I 2
#ifndef NEQN
E 2
	printf(".as %d \\v'%du'\\s-%d%s\\*(%d\\s+%d%s\\v'%du'\n", 
		yyval, shval, diffps, sh1, p2, diffps, sh2, -shval);
	ps += deltaps;
	if (rfont[p2] == ITAL)
		rfont[p1] = 0;
	else
		rfont[p1] = rfont[p2];
I 2
#else NEQN
	printf(".as %d \\v'%du'\\*(%d\\v'%du'\n", 
		yyval, shval, p2, -shval);
#endif NEQN
E 2
	ofree(p2);
}

shift(p1) int p1; {
	ps -= deltaps;
	yyval = p1;
	if(dbg)printf(".\tshift: %d;ps=%d\n", yyval, ps);
}

shift2(p1, p2, p3) int p1, p2, p3; {
D 2
	int effps, effps2, h1, h2, h3, b1, b2, b3, subsh, d1, d2, supsh;
	int treg;
E 2
I 2
	int effps, h1, h2, h3, b1, b2, b3, subsh, d1, d2, supsh, treg;
#ifndef NEQN
	int effps2;
#endif NEQN

E 2
	treg = oalloc();
	yyval = p1;
	if(dbg)printf(".\tshift2 s%d <- %d %d %d\n", yyval, p1, p2, p3);
	effps = EFFPS(ps+deltaps);
I 2
#ifndef NEQN
E 2
	eht[p3] = h3 = VERT( (eht[p3] * effps) / EFFPS(ps) );
	ps += deltaps;
	effps2 = EFFPS(ps+deltaps);
I 2
#endif NEQN
E 2
	h1 = eht[p1]; b1 = ebase[p1];
	h2 = eht[p2]; b2 = ebase[p2];
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
	b3 = ebase[p3];
	d1 = VERT( (effps2*6)/2 );
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
	b3 = ebase[p3];
	d1 = VERT( effps2*30 );
#endif
#ifdef NEQN
E 4
	h3 = eht[p3]; b3 = ebase[p3];
	d1 = VERT(1);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
	subsh = -d1+h2-b2;
	if( d1+b1 > h2 ) /* move little sub down */
		subsh = b1-b2;
I 2
#ifndef NEQN
E 2
	supsh = -VERT( (4*(h1-b1))/10 ) - b3;
	d2 = VERT( (effps*6*2)/10 );
	if( VERT(4*(h1-b1)/10)+h3 < h1-b1 )
I 2
#else NEQN
	supsh = - VERT(1) - b3;
	d2 = VERT(1);
	if( VERT(1)+h3 < h1-b1 )
#endif NEQN
E 2
		supsh = -(h1-b1) + (h3-b3) - d2;
I 2
#ifndef NEQN
E 2
	eht[yyval] = h1 + max(0, h3-VERT( (6*(h1-b1))/10 )) + max(0, h2-b1-d1);
I 2
#else NEQN
	eht[yyval] = h1 + max(0, h3-VERT(1)) + max(0, h2-b1-d1);
#endif NEQN
E 2
	ebase[yyval] = b1+max(0, h2-b1-d1);
I 2
D 5
#ifndef NEQN
E 5
I 5
#ifdef CAT
E 5
E 2
	if (rfont[p1] == ITAL && lfont[p2] == ROM)
		printf(".ds %d \\|\\*(%d\n", p2, p2);
	if (rfont[p2] == ITAL)
		printf(".as %d \\|\n", p2);
I 2
D 5
#endif NEQN
E 5
I 5
#endif
E 5
E 2
	nrwid(p2, effps, p2);
I 2
D 5
#ifndef NEQN
E 5
I 5
#ifdef CAT
E 5
E 2
	if (rfont[p1] == ITAL && lfont[p3] == ROM)
		printf(".ds %d \\|\\|\\*(%d\n", p3, p3);
	else
		printf(".ds %d \\|\\*(%d\n", p3, p3);
I 2
D 5
#endif NEQN
E 5
I 5
#endif
E 5
E 2
	nrwid(p3, effps, p3);
	printf(".nr %d \\n(%d\n", treg, p3);
	printf(".if \\n(%d>\\n(%d .nr %d \\n(%d\n", p2, treg, treg, p2);
I 2
#ifndef NEQN
E 2
	printf(".as %d \\v'%du'\\s%d\\*(%d\\h'-\\n(%du'\\v'%du'\\\n", 
		p1, subsh, effps, p2, p2, -subsh+supsh);
	printf("\\s%d\\*(%d\\h'-\\n(%du+\\n(%du'\\s%d\\v'%du'\n", 
		effps, p3, p3, treg, effps2, -supsh);
I 2
#else NEQN
	printf(".as %d \\v'%du'\\*(%d\\h'-\\n(%du'\\v'%du'\\\n", 
		p1, subsh, p2, p2, -subsh+supsh);
	printf("\\*(%d\\h'-\\n(%du+\\n(%du'\\v'%du'\n", 
		p3, p3, treg, -supsh);
#endif NEQN
E 2
	ps += deltaps;
I 2
#ifndef NEQN
E 2
	if (rfont[p2] == ITAL)
		rfont[yyval] = 0;	/* lie */
I 2
#endif NEQN
E 2
	ofree(p2); ofree(p3); ofree(treg);
}
E 1
