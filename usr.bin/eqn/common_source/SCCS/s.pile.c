h48715
s 00015/00007/00067
d D 4.4 04/09/15 04:22:14 msokolov 4 3
c PostScript mode added, compiles
e
s 00003/00001/00071
d D 4.3 83/08/11 20:39:30 sam 3 2
c standardize sccs keyword lines
e
s 00008/00000/00064
d D 4.2 83/02/12 18:03:58 shannon 2 1
c merge eqn and neqn
e
s 00064/00000/00000
d D 4.1 83/02/11 18:28:39 shannon 1 0
c date and time created 83/02/11 18:28:39 by shannon
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

lpile(type, p1, p2) int type, p1, p2; {
	int bi, hi, i, gap, h, b, nlist, nlist2, mid;
	yyval = oalloc();
I 2
D 4
#ifndef NEQN
E 2
	gap = VERT( (ps*6*4)/10 ); /* 4/10 m between blocks */
I 2
#else NEQN
E 4
I 4
#ifdef CAT
	gap = VERT( (ps*6*4)/10 );	/* 4/10 m between blocks */
#endif
#ifdef PS
	gap = ps*6*4;			/* 4/10 m between blocks */
#endif
#ifdef NEQN
E 4
	gap = VERT(1);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
	if( type=='-' ) gap = 0;
	nlist = p2 - p1;
	nlist2 = (nlist+1)/2;
	mid = p1 + nlist2 -1;
	h = 0;
	for( i=p1; i<p2; i++ )
		h += eht[lp[i]];
	eht[yyval] = h + (nlist-1)*gap;
	b = 0;
	for( i=p2-1; i>mid; i-- )
		b += eht[lp[i]] + gap;
	ebase[yyval] = (nlist%2) ? b + ebase[lp[mid]]
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
			: b - VERT( (ps*6*5)/10 ) - gap;
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
			: b - (ps*6*5) - gap;
#endif
#ifdef NEQN
E 4
			: b - VERT(1) - gap;
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
	if(dbg) {
		printf(".\tS%d <- %c pile of:", yyval, type);
		for( i=p1; i<p2; i++)
			printf(" S%d", lp[i]);
		printf(";h=%d b=%d\n", eht[yyval], ebase[yyval]);
	}
	nrwid(lp[p1], ps, lp[p1]);
	printf(".nr %d \\n(%d\n", yyval, lp[p1]);
	for( i = p1+1; i<p2; i++ ) {
		nrwid(lp[i], ps, lp[i]);
		printf(".if \\n(%d>\\n(%d .nr %d \\n(%d\n", 
			lp[i], yyval, yyval, lp[i]);
	}
	printf(".ds %d \\v'%du'\\h'%du*\\n(%du'\\\n", yyval, ebase[yyval], 
		type=='R' ? 1 : 0, yyval);
	for(i = p2-1; i >=p1; i--) {
		hi = eht[lp[i]]; 
		bi = ebase[lp[i]];
	switch(type) {

	case 'L':
		printf("\\v'%du'\\*(%d\\h'-\\n(%du'\\v'0-%du'\\\n", 
			-bi, lp[i], lp[i], hi-bi+gap);
		continue;
	case 'R':
		printf("\\v'%du'\\h'-\\n(%du'\\*(%d\\v'0-%du'\\\n", 
			-bi, lp[i], lp[i], hi-bi+gap);
		continue;
	case 'C':
	case '-':
		printf("\\v'%du'\\h'\\n(%du-\\n(%du/2u'\\*(%d", 
			-bi, yyval, lp[i], lp[i]);
		printf("\\h'-\\n(%du-\\n(%du/2u'\\v'0-%du'\\\n", 
			yyval, lp[i], hi-bi+gap);
		continue;
		}
	}
	printf("\\v'%du'\\h'%du*\\n(%du'\n", eht[yyval]-ebase[yyval]+gap, 
		type!='R' ? 1 : 0, yyval);
	for( i=p1; i<p2; i++ )
		ofree(lp[i]);
	lfont[yyval] = rfont[yyval] = 0;
}
E 1
