h30802
s 00067/00008/00113
d D 4.4 04/09/15 04:22:13 msokolov 4 3
c PostScript mode added, compiles
e
s 00003/00001/00118
d D 4.3 83/08/11 20:39:25 sam 3 2
c standardize sccs keyword lines
e
s 00012/00000/00107
d D 4.2 83/02/12 18:03:53 shannon 2 1
c merge eqn and neqn
e
s 00107/00000/00000
d D 4.1 83/02/11 18:28:36 shannon 1 0
c date and time created 83/02/11 18:28:36 by shannon
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

paren(leftc, p1, rightc) int p1, leftc, rightc; {
	int n, m, h1, j, b1, v;
	h1 = eht[p1]; b1 = ebase[p1];
	yyval = p1;
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
	lfont[yyval] = rfont[yyval] = 0;
	n = (h1+(6*EFFPS(ps)-1))/(6*EFFPS(ps));
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
	lfont[yyval] = rfont[yyval] = 0;
	n = (h1+(60*EFFPS(ps)-1))/(60*EFFPS(ps));
#endif
#ifdef NEQN
E 4
	n = max(b1+VERT(1), h1-b1-VERT(1)) / VERT(1);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
	if( n<2 ) n = 1;
	m = n-2;
	if (leftc=='{' || rightc == '}') {
		n = n%2 ? n : ++n;
		if( n<3 ) n=3;
		m = n-3;
	}
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
	eht[yyval] = VERT(6 * ps * n);
	ebase[yyval] = b1 + (eht[yyval]-h1)/2;
	v = b1 - h1/2 + VERT( (ps*6*4)/10 );
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
	eht[yyval] = 60 * ps * n;
	ebase[yyval] = b1 + (eht[yyval]-h1)/2;
	v = b1 - h1/2 + ps*6*4;
#endif
#ifdef NEQN
E 4
	eht[yyval] = VERT(2 * n);
	ebase[yyval] = (n)/2 * VERT(2);
	if (n%2 == 0)
		ebase[yyval] -= VERT(1);
	v = b1 - h1/2 + VERT(1);
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
	printf(".ds %d \\|\\v'%du'", yyval, v);
	switch( leftc ) {
		case 'n':	/* nothing */
		case '\0':
			break;
		case 'f':	/* floor */
			if (n <= 1)
				printf("\\(lf");
			else
I 4
#ifdef PS
				brack(m, "\\(lx", "\\(lx", "\\(lf");
#else
E 4
				brack(m, "\\(bv", "\\(bv", "\\(lf");
I 4
#endif
E 4
			break;
		case 'c':	/* ceiling */
			if (n <= 1)
				printf("\\(lc");
			else
I 4
#ifdef PS
				brack(m, "\\(lc", "\\(lx", "\\(lx");
#else
E 4
				brack(m, "\\(lc", "\\(bv", "\\(bv");
I 4
#endif
E 4
			break;
		case '{':
			printf("\\b'\\(lt");
I 4
#ifdef PS
			for(j = 0; j < m; j += 2) printf("\\(bx");
#else
E 4
			for(j = 0; j < m; j += 2) printf("\\(bv");
I 4
#endif
E 4
			printf("\\(lk");
I 4
#ifdef PS
			for(j = 0; j < m; j += 2) printf("\\(bx");
#else
E 4
			for(j = 0; j < m; j += 2) printf("\\(bv");
I 4
#endif
E 4
			printf("\\(lb'");
			break;
		case '(':
I 4
#ifdef PS
			brack(m, "\\SE6", "\\SE7", "\\SE8");
#else
E 4
			brack(m, "\\(lt", "\\(bv", "\\(lb");
I 4
#endif
E 4
			break;
		case '[':
I 4
#ifdef PS
			brack(m, "\\(lc", "\\(lx", "\\(lf");
#else
E 4
			brack(m, "\\(lc", "\\(bv", "\\(lf");
I 4
#endif
E 4
			break;
		case '|':
			brack(m, "|", "|", "|");
			break;
		default:
			brack(m, (char *) &leftc, (char *) &leftc, (char *) &leftc);
			break;
		}
	printf("\\v'%du'\\*(%d", -v, p1);
	if( rightc ) {
		printf("\\|\\v'%du'", v);
		switch( rightc ) {
			case 'f':	/* floor */
				if (n <= 1)
					printf("\\(rf");
				else
I 4
#ifdef PS
					brack(m, "\\(rx", "\\(rx", "\\(rf");
#else
E 4
					brack(m, "\\(bv", "\\(bv", "\\(rf");
I 4
#endif
E 4
				break;
			case 'c':	/* ceiling */
				if (n <= 1)
					printf("\\(rc");
				else
I 4
#ifdef PS
					brack(m, "\\(rc", "\\(rx", "\\(rx");
#else
E 4
					brack(m, "\\(rc", "\\(bv", "\\(bv");
I 4
#endif
E 4
				break;
			case '}':
				printf("\\b'\\(rt");
D 4
				for(j = 0; j< m; j += 2)printf("\\(bv");
E 4
I 4
#ifdef PS
				for(j = 0; j < m; j += 2) printf("\\(bx");
#else
				for(j = 0; j < m; j += 2) printf("\\(bv");
#endif
E 4
				printf("\\(rk");
D 4
				for(j = 0; j< m; j += 2) printf("\\(bv");
E 4
I 4
#ifdef PS
				for(j = 0; j < m; j += 2) printf("\\(bx");
#else
				for(j = 0; j < m; j += 2) printf("\\(bv");
#endif
E 4
				printf("\\(rb'");
				break;
			case ']':
I 4
#ifdef PS
				brack(m, "\\(rc", "\\(rx", "\\(rf");
#else
E 4
				brack(m, "\\(rc", "\\(bv", "\\(rf");
I 4
#endif
E 4
				break;
			case ')':
I 4
#ifdef PS
				brack(m, "\\SF6", "\\SF7", "\\SF8");
#else
E 4
				brack(m, "\\(rt", "\\(bv", "\\(rb");
I 4
#endif
E 4
				break;
			case '|':
				brack(m, "|", "|", "|");
				break;
			default:
				brack(m, (char *) &rightc, (char *) &rightc, (char *) &rightc);
				break;
		}
		printf("\\v'%du'", -v);
	}
	printf("\n");
	if(dbg)printf(".\tcurly: h=%d b=%d n=%d v=%d l=%c, r=%c\n", 
		eht[yyval], ebase[yyval], n, v, leftc, rightc);
}

brack(m, t, c, b) int m; char *t, *c, *b; {
	int j;
	printf("\\b'%s", t);
	for( j=0; j<m; j++)
		printf("%s", c);
	printf("%s'", b);
}
E 1
