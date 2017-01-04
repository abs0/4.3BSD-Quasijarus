#ifndef lint
static char sccsid[] = "@(#)paren.c	4.4 9/15/04";
#endif

# include "e.h"

paren(leftc, p1, rightc) int p1, leftc, rightc; {
	int n, m, h1, j, b1, v;
	h1 = eht[p1]; b1 = ebase[p1];
	yyval = p1;
#ifdef CAT
	lfont[yyval] = rfont[yyval] = 0;
	n = (h1+(6*EFFPS(ps)-1))/(6*EFFPS(ps));
#endif
#ifdef PS
	lfont[yyval] = rfont[yyval] = 0;
	n = (h1+(60*EFFPS(ps)-1))/(60*EFFPS(ps));
#endif
#ifdef NEQN
	n = max(b1+VERT(1), h1-b1-VERT(1)) / VERT(1);
#endif
	if( n<2 ) n = 1;
	m = n-2;
	if (leftc=='{' || rightc == '}') {
		n = n%2 ? n : ++n;
		if( n<3 ) n=3;
		m = n-3;
	}
#ifdef CAT
	eht[yyval] = VERT(6 * ps * n);
	ebase[yyval] = b1 + (eht[yyval]-h1)/2;
	v = b1 - h1/2 + VERT( (ps*6*4)/10 );
#endif
#ifdef PS
	eht[yyval] = 60 * ps * n;
	ebase[yyval] = b1 + (eht[yyval]-h1)/2;
	v = b1 - h1/2 + ps*6*4;
#endif
#ifdef NEQN
	eht[yyval] = VERT(2 * n);
	ebase[yyval] = (n)/2 * VERT(2);
	if (n%2 == 0)
		ebase[yyval] -= VERT(1);
	v = b1 - h1/2 + VERT(1);
#endif
	printf(".ds %d \\|\\v'%du'", yyval, v);
	switch( leftc ) {
		case 'n':	/* nothing */
		case '\0':
			break;
		case 'f':	/* floor */
			if (n <= 1)
				printf("\\(lf");
			else
#ifdef PS
				brack(m, "\\(lx", "\\(lx", "\\(lf");
#else
				brack(m, "\\(bv", "\\(bv", "\\(lf");
#endif
			break;
		case 'c':	/* ceiling */
			if (n <= 1)
				printf("\\(lc");
			else
#ifdef PS
				brack(m, "\\(lc", "\\(lx", "\\(lx");
#else
				brack(m, "\\(lc", "\\(bv", "\\(bv");
#endif
			break;
		case '{':
			printf("\\b'\\(lt");
#ifdef PS
			for(j = 0; j < m; j += 2) printf("\\(bx");
#else
			for(j = 0; j < m; j += 2) printf("\\(bv");
#endif
			printf("\\(lk");
#ifdef PS
			for(j = 0; j < m; j += 2) printf("\\(bx");
#else
			for(j = 0; j < m; j += 2) printf("\\(bv");
#endif
			printf("\\(lb'");
			break;
		case '(':
#ifdef PS
			brack(m, "\\SE6", "\\SE7", "\\SE8");
#else
			brack(m, "\\(lt", "\\(bv", "\\(lb");
#endif
			break;
		case '[':
#ifdef PS
			brack(m, "\\(lc", "\\(lx", "\\(lf");
#else
			brack(m, "\\(lc", "\\(bv", "\\(lf");
#endif
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
#ifdef PS
					brack(m, "\\(rx", "\\(rx", "\\(rf");
#else
					brack(m, "\\(bv", "\\(bv", "\\(rf");
#endif
				break;
			case 'c':	/* ceiling */
				if (n <= 1)
					printf("\\(rc");
				else
#ifdef PS
					brack(m, "\\(rc", "\\(rx", "\\(rx");
#else
					brack(m, "\\(rc", "\\(bv", "\\(bv");
#endif
				break;
			case '}':
				printf("\\b'\\(rt");
#ifdef PS
				for(j = 0; j < m; j += 2) printf("\\(bx");
#else
				for(j = 0; j < m; j += 2) printf("\\(bv");
#endif
				printf("\\(rk");
#ifdef PS
				for(j = 0; j < m; j += 2) printf("\\(bx");
#else
				for(j = 0; j < m; j += 2) printf("\\(bv");
#endif
				printf("\\(rb'");
				break;
			case ']':
#ifdef PS
				brack(m, "\\(rc", "\\(rx", "\\(rf");
#else
				brack(m, "\\(rc", "\\(bv", "\\(rf");
#endif
				break;
			case ')':
#ifdef PS
				brack(m, "\\SF6", "\\SF7", "\\SF8");
#else
				brack(m, "\\(rt", "\\(bv", "\\(rb");
#endif
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
