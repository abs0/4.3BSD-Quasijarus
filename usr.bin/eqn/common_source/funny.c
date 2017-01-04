#ifndef lint
static char sccsid[] = "@(#)funny.c	4.4 9/15/04";
#endif

# include "e.h"
# include "e.def"

funny(n) int n; {
	char *f;

	yyval = oalloc();
	switch(n) {
	case SUM:
#ifdef PS
		f = "\\SE5"; break;
#else
		f = "\\(*S"; break;
#endif
	case UNION:
		f = "\\(cu"; break;
	case INTER:	/* intersection */
		f = "\\(ca"; break;
	case PROD:
#ifdef PS
		f = "\\SD5"; break;
#else
		f = "\\(*P"; break;
#endif
	default:
		error(FATAL, "funny type %d in funny", n);
	}
#ifdef CAT
	printf(".ds %d \\s%d\\v'.3m'\\s+5%s\\s-5\\v'-.3m'\\s%d\n", yyval, ps, f, ps);
	eht[yyval] = VERT( (ps+5)*6 -(ps*6*2)/10 );
	ebase[yyval] = VERT( (ps*6*3)/10 );
#endif
#ifdef PS
	printf(".ds %d \\s%d\\v'.3m'\\s+5%s\\s-5\\v'-.3m'\\s%d\n", yyval, ps, f, ps);
	eht[yyval] = (ps+5)*60 -(ps*6*2);
	ebase[yyval] = ps*6*3;
#endif
#ifdef NEQN
	printf(".ds %d %s\n", yyval, f);
	eht[yyval] = VERT(2);
	ebase[yyval] = 0;
#endif
	if(dbg)printf(".\tfunny: S%d <- %s; h=%d b=%d\n", 
		yyval, f, eht[yyval], ebase[yyval]);
	lfont[yyval] = rfont[yyval] = ROM;
}
