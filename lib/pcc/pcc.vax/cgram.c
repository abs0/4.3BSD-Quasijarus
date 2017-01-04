# define TOKENS 0
# define ERROR 1
# define FREE 2
# define STRING 3
# define ICON 4
# define FCON 5
# define DCON 6
# define NAME 7
# define REG 8
# define OREG 9
# define CCODES 10
# define FLD 11
# define PLUS 12
# define PLUSEQ 13
# define UPLUS 14
# define MINUS 15
# define MINUSEQ 16
# define UMINUS 17
# define MUL 18
# define MULEQ 19
# define DIV 21
# define DIVEQ 22
# define MOD 23
# define MODEQ 24
# define INCR 25
# define DECR 26
# define ASSIGN 27
# define AND 28
# define ANDEQ 29
# define OR 31
# define OREQ 32
# define ER 33
# define EREQ 34
# define LS 35
# define LSEQ 36
# define RS 37
# define RSEQ 38
# define COMPL 39
# define EQ 40
# define NE 41
# define LE 42
# define LT 43
# define GE 44
# define GT 45
# define ULE 46
# define ULT 47
# define UGE 48
# define UGT 49
# define QUEST 50
# define COLON 51
# define ANDAND 52
# define OROR 53
# define NOT 54
# define CALL 55
# define UCALL 57
# define FORTCALL 58
# define UFORTCALL 60
# define INLINE 61
# define UINLINE 63
# define DEREF 20
# define ADDROF 30
# define DOT 64
# define STREF 65
# define STASG 66
# define STARG 67
# define STCALL 68
# define USTCALL 70
# define SCONV 71
# define PCONV 72
# define PMCONV 73
# define PVCONV 74
# define CAST 75
# define LB 76
# define RB 77
# define COMOP 78
# define CM 79
# define FORCE 80
# define GOTO 81
# define CBRANCH 82
# define RETURN 83
# define INIT 84
# define TYPE 85
# define CLASS 86
# define MAXOP 86
# define LOCALTOKENS 100
# define ASOP 100
# define RELOP 101
# define EQUOP 102
# define DIVOP 103
# define SHIFTOP 104
# define INCOP 105
# define UNOP 106
# define STROP 107
# define LP 108
# define RP 109
# define LC 110
# define RC 111
# define STRUCT 112
# define IF 113
# define ELSE 114
# define SWITCH 115
# define BREAK 116
# define CONTINUE 117
# define WHILE 118
# define DO 119
# define FOR 120
# define DEFAULT 121
# define CASE 122
# define SIZEOF 123
# define ENUM 124
# define SM 125

# line 146 "gram.in"
# include "pass1.h"
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern short yyerrflag;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
YYSTYPE yylval, yyval;

# line 165 "gram.in"
	static int fake = 0;
#ifndef FLEXNAMES
	static char fakename[NCHNAM+1];
#else
	static char fakename[24];
#endif
	static int nsizeof = 0;
# define YYERRCODE 256

# line 932 "gram.in"


NODE *
mkty( t, d, s ) unsigned t; {
	return( block( TYPE, NIL, NIL, t, d, s ) );
	}

NODE *
bdty( op, p, v ) NODE *p; {
	register NODE *q;

	q = block( op, p, NIL, INT, 0, INT );

	switch( op ){

	case UNARY MUL:
	case UNARY CALL:
		break;

	case LB:
		q->in.right = bcon(v);
		break;

	case NAME:
		q->tn.rval = v;
		break;

	default:
		cerror( "bad bdty" );
		}

	return( q );
	}

dstash( n ){ /* put n into the dimension table */
	if( curdim >= DIMTABSZ-1 ){
		cerror( "dimension table overflow");
		}
	dimtab[ curdim++ ] = n;
	}

savebc() {
	if( psavbc > & asavbc[BCSZ-4 ] ){
		cerror( "whiles, fors, etc. too deeply nested");
		}
	*psavbc++ = brklab;
	*psavbc++ = contlab;
	*psavbc++ = flostat;
	*psavbc++ = swx;
	flostat = 0;
	}

resetbc(mask){

	swx = *--psavbc;
	flostat = *--psavbc | (flostat&mask);
	contlab = *--psavbc;
	brklab = *--psavbc;

	}

addcase(p) NODE *p; { /* add case to switch */

	p = optim( p );  /* change enum to ints */
	if( p->in.op != ICON || p->tn.rval != NONAME ){
		uerror( "non-constant case expression");
		return;
		}
	if( swp == swtab ){
		uerror( "case not in switch");
		return;
		}
	if( swp >= &swtab[SWITSZ] ){
		cerror( "switch table overflow");
		}
	swp->sval = p->tn.lval;
	deflab( swp->slab = getlab() );
	++swp;
	tfree(p);
	}

adddef(){ /* add default case to switch */
	if( swtab[swx].slab >= 0 ){
		uerror( "duplicate default in switch");
		return;
		}
	if( swp == swtab ){
		uerror( "default not inside switch");
		return;
		}
	deflab( swtab[swx].slab = getlab() );
	}

swstart(){
	/* begin a switch block */
	if( swp >= &swtab[SWITSZ] ){
		cerror( "switch table overflow");
		}
	swx = swp - swtab;
	swp->slab = -1;
	++swp;
	}

swend(){ /* end a switch block */

	register struct sw *swbeg, *p, *q, *r, *r1;
	CONSZ temp;
	int tempi;

	swbeg = &swtab[swx+1];

	/* sort */

	r1 = swbeg;
	r = swp-1;

	while( swbeg < r ){
		/* bubble largest to end */
		for( q=swbeg; q<r; ++q ){
			if( q->sval > (q+1)->sval ){
				/* swap */
				r1 = q+1;
				temp = q->sval;
				q->sval = r1->sval;
				r1->sval = temp;
				tempi = q->slab;
				q->slab = r1->slab;
				r1->slab = tempi;
				}
			}
		r = r1;
		r1 = swbeg;
		}

	/* it is now sorted */

	for( p = swbeg+1; p<swp; ++p ){
		if( p->sval == (p-1)->sval ){
			uerror( "duplicate case in switch, %d", p->sval );
			return;
			}
		}

	genswitch( swbeg-1, swp-swbeg );
	swp = swbeg-1;
	}
extern short  yyexca[];
# define YYNPROD 188
# define YYLAST 1292
extern short  yyact[];
extern short  yypact[];
extern short  yypgo[];
extern short  yyr1[];
extern short  yyr2[];
extern short  yychk[];
extern short  yydef[];
#ifndef lint
static char yaccpar_sccsid[] = "@(#)yaccpar	4.1	(Berkeley)	2/11/83";
#endif not lint

#
# define YYFLAG -1000
# define YYERROR goto yyerrlab
# define YYACCEPT return(0)
# define YYABORT return(1)

/*	parser for yacc output	*/

#ifdef YYDEBUG
int yydebug = 0; /* 1 for debugging */
#endif
YYSTYPE yyv[YYMAXDEPTH]; /* where the values are stored */
int yychar = -1; /* current input token number */
int yynerrs = 0;  /* number of errors */
short yyerrflag = 0;  /* error recovery flag */

yyparse() {

	short yys[YYMAXDEPTH];
	short yyj, yym;
	register YYSTYPE *yypvt;
	register short yystate, *yyps, yyn;
	register YYSTYPE *yypv;
	register short *yyxi;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyps= &yys[-1];
	yypv= &yyv[-1];

 yystack:    /* put a state and value onto the stack */

#ifdef YYDEBUG
	if( yydebug  ) printf( "state %d, char 0%o\n", yystate, yychar );
#endif
		if( ++yyps> &yys[YYMAXDEPTH] ) { yyerror( "yacc stack overflow" ); return(1); }
		*yyps = yystate;
		++yypv;
		*yypv = yyval;

 yynewstate:

	yyn = yypact[yystate];

	if( yyn<= YYFLAG ) goto yydefault; /* simple state */

	if( yychar<0 ) if( (yychar=yylex())<0 ) yychar=0;
	if( (yyn += yychar)<0 || yyn >= YYLAST ) goto yydefault;

	if( yychk[ yyn=yyact[ yyn ] ] == yychar ){ /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if( yyerrflag > 0 ) --yyerrflag;
		goto yystack;
		}

 yydefault:
	/* default state action */

	if( (yyn=yydef[yystate]) == -2 ) {
		if( yychar<0 ) if( (yychar=yylex())<0 ) yychar = 0;
		/* look through exception table */

		for( yyxi=yyexca; (*yyxi!= (-1)) || (yyxi[1]!=yystate) ; yyxi += 2 ) ; /* VOID */

		while( *(yyxi+=2) >= 0 ){
			if( *yyxi == yychar ) break;
			}
		if( (yyn = yyxi[1]) < 0 ) return(0);   /* accept */
		}

	if( yyn == 0 ){ /* error */
		/* error ... attempt to resume parsing */

		switch( yyerrflag ){

		case 0:   /* brand new error */

			yyerror( "syntax error" );
		yyerrlab:
			++yynerrs;

		case 1:
		case 2: /* incompletely recovered error ... try again */

			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */

			while ( yyps >= yys ) {
			   yyn = yypact[*yyps] + YYERRCODE;
			   if( yyn>= 0 && yyn < YYLAST && yychk[yyact[yyn]] == YYERRCODE ){
			      yystate = yyact[yyn];  /* simulate a shift of "error" */
			      goto yystack;
			      }
			   yyn = yypact[*yyps];

			   /* the current yyps has no shift onn "error", pop stack */

#ifdef YYDEBUG
			   if( yydebug ) printf( "error recovery pops state %d, uncovers %d\n", *yyps, yyps[-1] );
#endif
			   --yyps;
			   --yypv;
			   }

			/* there is no state on the stack with an error shift ... abort */

	yyabort:
			return(1);


		case 3:  /* no shift yet; clobber input char */

#ifdef YYDEBUG
			if( yydebug ) printf( "error recovery discards char %d\n", yychar );
#endif

			if( yychar == 0 ) goto yyabort; /* don't discard EOF, quit */
			yychar = -1;
			goto yynewstate;   /* try again in the same state */

			}

		}

	/* reduction by production yyn */

#ifdef YYDEBUG
		if( yydebug ) printf("reduce %d\n",yyn);
#endif
		yyps -= yyr2[yyn];
		yypvt = yypv;
		yypv -= yyr2[yyn];
		yyval = yypv[1];
		yym=yyn;
			/* consult goto table to find next state */
		yyn = yyr1[yyn];
		yyj = yypgo[yyn] + *yyps + 1;
		if( yyj>=YYLAST || yychk[ yystate = yyact[yyj] ] != -yyn ) yystate = yyact[yypgo[yyn]];
		switch(yym){
			
case 2:
# line 176 "gram.in"
ftnend(); break;
case 3:
# line 179 "gram.in"
{ curclass = SNULL;  blevel = 0; } break;
case 4:
# line 181 "gram.in"
{ curclass = SNULL;  blevel = 0; } break;
case 5:
# line 185 "gram.in"
{  yypvt[-1].nodep->in.op = FREE; } break;
case 6:
# line 187 "gram.in"
{  yypvt[-2].nodep->in.op = FREE; } break;
case 7:
# line 188 "gram.in"
{
				defid( tymerge(yypvt[-1].nodep,yypvt[-0].nodep), curclass==STATIC?STATIC:EXTDEF );
#ifndef LINT
				if( nerrors == 0 )
					pfstab(stab[yypvt[-0].nodep->tn.rval].sname);
#endif
				} break;
case 8:
# line 195 "gram.in"
{  
			    if( blevel ) cerror( "function level error" );
			    if( reached ) retstat |= NRETVAL; 
			    yypvt[-3].nodep->in.op = FREE;
			    ftnend();
			    } break;
case 11:
# line 206 "gram.in"
{  blevel = 1; } break;
case 13:
# line 211 "gram.in"
{  bccode();
			    (void) locctr(PROG);
			    } break;
case 14:
# line 217 "gram.in"
{  yypvt[-1].nodep->in.op = FREE; 
#ifndef LINT
			    if( nerrors == 0 ) plcstab(blevel);
#endif
			    } break;
case 15:
# line 223 "gram.in"
{  yypvt[-2].nodep->in.op = FREE; 
#ifndef LINT
			    if( nerrors == 0 ) plcstab(blevel);
#endif
			    } break;
case 16:
# line 231 "gram.in"
{  yypvt[-1].nodep->in.op = FREE; } break;
case 17:
# line 233 "gram.in"
{  yypvt[-2].nodep->in.op = FREE; } break;
case 19:
# line 237 "gram.in"
{ curclass = SNULL;  yypvt[-2].nodep->in.op = FREE; } break;
case 20:
# line 239 "gram.in"
{ curclass = SNULL;  yypvt[-1].nodep->in.op = FREE; } break;
case 21:
# line 241 "gram.in"
{  curclass = SNULL; } break;
case 23:
# line 245 "gram.in"
{  yyval.nodep = mkty(INT,0,INT);  curclass = SNULL; } break;
case 24:
# line 248 "gram.in"
{  yyval.nodep = yypvt[-0].nodep; } break;
case 26:
# line 251 "gram.in"
{  yyval.nodep = mkty(INT,0,INT); } break;
case 27:
# line 253 "gram.in"
{ curclass = SNULL ; } break;
case 28:
# line 255 "gram.in"
{  yypvt[-2].nodep->in.type = types( yypvt[-2].nodep->in.type, yypvt[-0].nodep->in.type, UNDEF );
			    yypvt[-0].nodep->in.op = FREE;
			    } break;
case 29:
# line 262 "gram.in"
{  curclass = yypvt[-0].intval; } break;
case 31:
# line 267 "gram.in"
{  yypvt[-1].nodep->in.type = types( yypvt[-1].nodep->in.type, yypvt[-0].nodep->in.type, UNDEF );
			    yypvt[-0].nodep->in.op = FREE;
			    } break;
case 32:
# line 271 "gram.in"
{  yypvt[-2].nodep->in.type = types( yypvt[-2].nodep->in.type, yypvt[-1].nodep->in.type, yypvt[-0].nodep->in.type );
			    yypvt[-1].nodep->in.op = yypvt[-0].nodep->in.op = FREE;
			    } break;
case 35:
# line 279 "gram.in"
{ yyval.nodep = dclstruct(yypvt[-4].intval); } break;
case 36:
# line 281 "gram.in"
{  yyval.nodep = rstruct(yypvt[-0].intval,0);  stwart = instruct; } break;
case 37:
# line 285 "gram.in"
{  yyval.intval = bstruct(-1,0); stwart = SEENAME; } break;
case 38:
# line 287 "gram.in"
{  yyval.intval = bstruct(yypvt[-0].intval,0); stwart = SEENAME; } break;
case 41:
# line 295 "gram.in"
{  moedef( yypvt[-0].intval ); } break;
case 42:
# line 297 "gram.in"
{  strucoff = yypvt[-0].intval;  moedef( yypvt[-2].intval ); } break;
case 43:
# line 301 "gram.in"
{ yyval.nodep = dclstruct(yypvt[-4].intval);  } break;
case 44:
# line 303 "gram.in"
{  yyval.nodep = rstruct(yypvt[-0].intval,yypvt[-1].intval); } break;
case 45:
# line 307 "gram.in"
{  yyval.intval = bstruct(-1,yypvt[-0].intval);  stwart=0; } break;
case 46:
# line 309 "gram.in"
{  yyval.intval = bstruct(yypvt[-0].intval,yypvt[-1].intval);  stwart=0;  } break;
case 49:
# line 317 "gram.in"
{ curclass = SNULL;  stwart=0; yypvt[-1].nodep->in.op = FREE; } break;
case 50:
# line 319 "gram.in"
{  if( curclass != MOU ){
				curclass = SNULL;
				}
			    else {
				sprintf( fakename, "$%dFAKE", fake++ );
#ifdef FLEXNAMES
				/* No need to hash this, we won't look it up */
				defid( tymerge(yypvt[-0].nodep, bdty(NAME,NIL,lookup( savestr(fakename), SMOS ))), curclass );
#else
				defid( tymerge(yypvt[-0].nodep, bdty(NAME,NIL,lookup( fakename, SMOS ))), curclass );
#endif
				werror("structure typed union member must be named");
				}
			    stwart = 0;
			    yypvt[-0].nodep->in.op = FREE;
			    } break;
case 51:
# line 339 "gram.in"
{ defid( tymerge(yypvt[-1].nodep,yypvt[-0].nodep), curclass);  stwart = instruct; } break;
case 52:
# line 340 "gram.in"
{yyval.nodep=yypvt[-2].nodep;} break;
case 53:
# line 341 "gram.in"
{ defid( tymerge(yypvt[-4].nodep,yypvt[-0].nodep), curclass);  stwart = instruct; } break;
case 56:
# line 347 "gram.in"
{  if( !(instruct&INSTRUCT) ) uerror( "field outside of structure" );
			    if( yypvt[-0].intval<0 || yypvt[-0].intval >= FIELD ){
				uerror( "illegal field size" );
				yypvt[-0].intval = 1;
				}
			    defid( tymerge(yypvt[-3].nodep,yypvt[-2].nodep), FIELD|yypvt[-0].intval );
			    yyval.nodep = NIL;
			    } break;
case 57:
# line 357 "gram.in"
{  if( !(instruct&INSTRUCT) ) uerror( "field outside of structure" );
			    (void) falloc( stab, yypvt[-0].intval, -1, yypvt[-2].nodep );  /* alignment or hole */
			    yyval.nodep = NIL;
			    } break;
case 58:
# line 362 "gram.in"
{  yyval.nodep = NIL; } break;
case 59:
# line 367 "gram.in"
{  umul:
				yyval.nodep = bdty( UNARY MUL, yypvt[-0].nodep, 0 ); } break;
case 60:
# line 370 "gram.in"
{  uftn:
				yyval.nodep = bdty( UNARY CALL, yypvt[-2].nodep, 0 );  } break;
case 61:
# line 373 "gram.in"
{  uary:
				yyval.nodep = bdty( LB, yypvt[-2].nodep, 0 );  } break;
case 62:
# line 376 "gram.in"
{  bary:
				if( (int)yypvt[-1].intval <= 0 ) werror( "zero or negative subscript" );
				yyval.nodep = bdty( LB, yypvt[-3].nodep, yypvt[-1].intval );  } break;
case 63:
# line 380 "gram.in"
{  yyval.nodep = bdty( NAME, NIL, yypvt[-0].intval );  } break;
case 64:
# line 382 "gram.in"
{ yyval.nodep=yypvt[-1].nodep; } break;
case 65:
# line 385 "gram.in"
{  goto umul; } break;
case 66:
# line 387 "gram.in"
{  goto uftn; } break;
case 67:
# line 389 "gram.in"
{  goto uary; } break;
case 68:
# line 391 "gram.in"
{  goto bary; } break;
case 69:
# line 393 "gram.in"
{ yyval.nodep = yypvt[-1].nodep; } break;
case 70:
# line 395 "gram.in"
{
				if( blevel!=0 ) uerror("function declaration in bad context");
				yyval.nodep = bdty( UNARY CALL, bdty(NAME,NIL,yypvt[-2].intval), 0 );
				stwart = 0;
				} break;
case 71:
# line 401 "gram.in"
{
				yyval.nodep = bdty( UNARY CALL, bdty(NAME,NIL,yypvt[-1].intval), 0 );
				stwart = 0;
				} break;
case 72:
# line 408 "gram.in"
{
				/* turn off typedefs for argument names */
				stwart = SEENAME;
				if( stab[yypvt[-1].intval].sclass == SNULL )
				    stab[yypvt[-1].intval].stype = FTN;
				} break;
case 73:
# line 417 "gram.in"
{ ftnarg( yypvt[-0].intval );  stwart = SEENAME; } break;
case 74:
# line 419 "gram.in"
{ ftnarg( yypvt[-0].intval );  stwart = SEENAME; } break;
case 77:
# line 425 "gram.in"
{yyval.nodep=yypvt[-2].nodep;} break;
case 79:
# line 429 "gram.in"
{  int id;

			    defid( yypvt[-0].nodep = tymerge(yypvt[-1].nodep,yypvt[-0].nodep), curclass);
			    id = yypvt[-0].nodep->tn.rval;
			    beginit(id);
			    if( stab[id].sclass == AUTO ||
				stab[id].sclass == REGISTER ||
				stab[id].sclass == STATIC )
				stab[id].suse = -lineno;
			    } break;
case 81:
# line 443 "gram.in"
{  nidcl( tymerge(yypvt[-1].nodep,yypvt[-0].nodep) ); } break;
case 82:
# line 445 "gram.in"
{  defid( tymerge(yypvt[-1].nodep,yypvt[-0].nodep), uclass(curclass) );
			    if( paramno > 0 ){
				uerror( "illegal argument" );
				paramno = 0;
				}
			} break;
case 83:
# line 453 "gram.in"
{  doinit( yypvt[-0].nodep );
			    endinit(); } break;
case 84:
# line 456 "gram.in"
{  endinit(); } break;
case 85:
# line 458 "gram.in"
{  fixinit(); } break;
case 88:
# line 467 "gram.in"
{  doinit( yypvt[-0].nodep ); } break;
case 89:
# line 469 "gram.in"
{  irbrace(); } break;
case 95:
# line 487 "gram.in"
{  ilbrace(); } break;
case 98:
# line 497 "gram.in"
{  
#ifndef LINT
			    if( nerrors == 0 ) prcstab(blevel);
#endif
			    --blevel;
			    if( blevel == 1 ) blevel = 0;
			    clearst( blevel );
			    checkst( blevel );
			    autooff = *--psavbc;
			    regvar = *--psavbc;
			    } break;
case 99:
# line 511 "gram.in"
{  --blevel;
			    if( blevel == 1 ) blevel = 0;
			    clearst( blevel );
			    checkst( blevel );
			    autooff = *--psavbc;
			    regvar = *--psavbc;
			    } break;
case 100:
# line 521 "gram.in"
{  if( blevel == 1 ) dclargs();
			    ++blevel;
			    if( psavbc > &asavbc[BCSZ-2] ) cerror( "nesting too deep" );
			    *psavbc++ = regvar;
			    *psavbc++ = autooff;
			    } break;
case 101:
# line 530 "gram.in"
{ ecomp( yypvt[-1].nodep ); } break;
case 103:
# line 533 "gram.in"
{ deflab(yypvt[-1].intval);
			   reached = 1;
			   } break;
case 104:
# line 537 "gram.in"
{  if( yypvt[-1].intval != NOLAB ){
				deflab( yypvt[-1].intval );
				reached = 1;
				}
			    } break;
case 105:
# line 543 "gram.in"
{  branch(  contlab );
			    deflab( brklab );
			    if( (flostat&FBRK) || !(flostat&FLOOP)) reached = 1;
			    else reached = 0;
			    resetbc(0);
			    } break;
case 106:
# line 550 "gram.in"
{  deflab( contlab );
			    if( flostat & FCONT ) reached = 1;
			    ecomp( buildtree( CBRANCH, buildtree( NOT, yypvt[-2].nodep, NIL ), bcon( yypvt[-6].intval ) ) );
			    deflab( brklab );
			    reached = 1;
			    resetbc(0);
			    } break;
case 107:
# line 558 "gram.in"
{  deflab( contlab );
			    if( flostat&FCONT ) reached = 1;
			    if( yypvt[-2].nodep ) ecomp( yypvt[-2].nodep );
			    branch( yypvt[-3].intval );
			    deflab( brklab );
			    if( (flostat&FBRK) || !(flostat&FLOOP) ) reached = 1;
			    else reached = 0;
			    resetbc(0);
			    } break;
case 108:
# line 568 "gram.in"
{  if( reached ) branch( brklab );
			    deflab( yypvt[-1].intval );
			   swend();
			    deflab(brklab);
			    if( (flostat&FBRK) || !(flostat&FDEF) ) reached = 1;
			    resetbc(FCONT);
			    } break;
case 109:
# line 576 "gram.in"
{  if( brklab == NOLAB ) uerror( "illegal break");
			    else if(reached) branch( brklab );
			    flostat |= FBRK;
			    if( brkflag ) goto rch;
			    reached = 0;
			    } break;
case 110:
# line 583 "gram.in"
{  if( contlab == NOLAB ) uerror( "illegal continue");
			    else branch( contlab );
			    flostat |= FCONT;
			    goto rch;
			    } break;
case 111:
# line 589 "gram.in"
{  retstat |= NRETVAL;
			    branch( retlab );
			rch:
			    if( !reached ) werror( "statement not reached");
			    reached = 0;
			    } break;
case 112:
# line 596 "gram.in"
{  register NODE *temp;
			    idname = curftn;
			    temp = buildtree( NAME, NIL, NIL );
			    if(temp->in.type == TVOID)
				uerror("void function %s cannot return value",
					stab[idname].sname);
			    temp->in.type = DECREF( temp->in.type );
			    temp = buildtree( RETURN, temp, yypvt[-1].nodep );
			    /* now, we have the type of the RHS correct */
			    temp->in.left->in.op = FREE;
			    temp->in.op = FREE;
			    ecomp( buildtree( FORCE, temp->in.right, NIL ) );
			    retstat |= RETVAL;
			    branch( retlab );
			    reached = 0;
			    } break;
case 113:
# line 613 "gram.in"
{  register NODE *q;
			    q = block( FREE, NIL, NIL, INT|ARY, 0, INT );
			    q->tn.rval = idname = yypvt[-1].intval;
			    defid( q, ULABEL );
			    stab[idname].suse = -lineno;
			    branch( stab[idname].offset );
			    goto rch;
			    } break;
case 118:
# line 627 "gram.in"
{  register NODE *q;
			    q = block( FREE, NIL, NIL, INT|ARY, 0, LABEL );
			    q->tn.rval = yypvt[-1].intval;
			    defid( q, LABEL );
			    reached = 1;
			    } break;
case 119:
# line 634 "gram.in"
{  addcase(yypvt[-1].nodep);
			    reached = 1;
			    } break;
case 120:
# line 638 "gram.in"
{  reached = 1;
			    adddef();
			    flostat |= FDEF;
			    } break;
case 121:
# line 644 "gram.in"
{  savebc();
			    if( !reached ) werror( "loop not entered at top");
			    brklab = getlab();
			    contlab = getlab();
			    deflab( yyval.intval = getlab() );
			    reached = 1;
			    } break;
case 122:
# line 653 "gram.in"
{  ecomp( buildtree( CBRANCH, yypvt[-1].nodep, bcon( yyval.intval=getlab()) ) ) ;
			    reached = 1;
			    } break;
case 123:
# line 658 "gram.in"
{  if( reached ) branch( yyval.intval = getlab() );
			    else yyval.intval = NOLAB;
			    deflab( yypvt[-2].intval );
			    reached = 1;
			    } break;
case 124:
# line 666 "gram.in"
{  savebc();
			    if( !reached ) werror( "loop not entered at top");
			    if( yypvt[-1].nodep->in.op == ICON && yypvt[-1].nodep->tn.lval != 0 ) flostat = FLOOP;
			    deflab( contlab = getlab() );
			    reached = 1;
			    brklab = getlab();
			    if( flostat == FLOOP ) tfree( yypvt[-1].nodep );
			    else ecomp( buildtree( CBRANCH, yypvt[-1].nodep, bcon( brklab) ) );
			    } break;
case 125:
# line 677 "gram.in"
{  if( yypvt[-3].nodep ) ecomp( yypvt[-3].nodep );
			    else if( !reached ) werror( "loop not entered at top");
			    savebc();
			    contlab = getlab();
			    brklab = getlab();
			    deflab( yyval.intval = getlab() );
			    reached = 1;
			    if( yypvt[-1].nodep ) ecomp( buildtree( CBRANCH, yypvt[-1].nodep, bcon( brklab) ) );
			    else flostat |= FLOOP;
			    } break;
case 126:
# line 689 "gram.in"
{  register NODE *q;
			
			    savebc();
			    brklab = getlab();
			    q = yypvt[-1].nodep;
			    switch( q->in.type ) {
			    case CHAR:	case UCHAR:
			    case SHORT:	case USHORT:
			    case INT:	case UNSIGNED:
			    case MOE:	case ENUMTY:
				    break;
			    default:
				werror("switch expression not type int");
				q = makety( q, INT, q->fn.cdim, q->fn.csiz );
				}
#ifdef LINT
			    if( hflag && q->in.op == ICON )
				werror( "constant switch expression" );
#endif
			    ecomp( buildtree( FORCE, q, NIL ) );
			    branch( yyval.intval = getlab() );
			    swstart();
			    reached = 0;
			    } break;
case 127:
# line 715 "gram.in"
{ yyval.intval=instruct; stwart=instruct=0; } break;
case 128:
# line 717 "gram.in"
{  yyval.intval = icons( yypvt[-0].nodep );  instruct=yypvt[-1].intval; } break;
case 130:
# line 721 "gram.in"
{ yyval.nodep=0; } break;
case 132:
# line 726 "gram.in"
{  goto bop; } break;
case 133:
# line 730 "gram.in"
{
			preconf:
			    if( yychar==RELOP||yychar==EQUOP||yychar==AND||yychar==OR||yychar==ER ){
			    precplaint:
				if( hflag ) werror( "precedence confusion possible: parenthesize!" );
				}
			bop:
			    yyval.nodep = buildtree( yypvt[-1].intval, yypvt[-2].nodep, yypvt[-0].nodep );
			    } break;
case 134:
# line 740 "gram.in"
{  yypvt[-1].intval = COMOP;
			    goto bop;
			    } break;
case 135:
# line 744 "gram.in"
{  goto bop; } break;
case 136:
# line 746 "gram.in"
{  if(yychar==SHIFTOP) goto precplaint; else goto bop; } break;
case 137:
# line 748 "gram.in"
{  if(yychar==SHIFTOP ) goto precplaint; else goto bop; } break;
case 138:
# line 750 "gram.in"
{  if(yychar==PLUS||yychar==MINUS) goto precplaint; else goto bop; } break;
case 139:
# line 752 "gram.in"
{  goto bop; } break;
case 140:
# line 754 "gram.in"
{  goto preconf; } break;
case 141:
# line 756 "gram.in"
{  if( yychar==RELOP||yychar==EQUOP ) goto preconf;  else goto bop; } break;
case 142:
# line 758 "gram.in"
{  if(yychar==RELOP||yychar==EQUOP) goto preconf; else goto bop; } break;
case 143:
# line 760 "gram.in"
{  if(yychar==RELOP||yychar==EQUOP) goto preconf; else goto bop; } break;
case 144:
# line 762 "gram.in"
{  goto bop; } break;
case 145:
# line 764 "gram.in"
{  goto bop; } break;
case 146:
# line 766 "gram.in"
{  abop:
				yyval.nodep = buildtree( ASG yypvt[-2].intval, yypvt[-3].nodep, yypvt[-0].nodep );
				} break;
case 147:
# line 770 "gram.in"
{  goto abop; } break;
case 148:
# line 772 "gram.in"
{  goto abop; } break;
case 149:
# line 774 "gram.in"
{  goto abop; } break;
case 150:
# line 776 "gram.in"
{  goto abop; } break;
case 151:
# line 778 "gram.in"
{  goto abop; } break;
case 152:
# line 780 "gram.in"
{  goto abop; } break;
case 153:
# line 782 "gram.in"
{  goto abop; } break;
case 154:
# line 784 "gram.in"
{  yyval.nodep=buildtree(QUEST, yypvt[-4].nodep, buildtree( COLON, yypvt[-2].nodep, yypvt[-0].nodep ) );
			    } break;
case 155:
# line 787 "gram.in"
{  werror( "old-fashioned assignment operator" );  goto bop; } break;
case 156:
# line 789 "gram.in"
{  goto bop; } break;
case 158:
# line 793 "gram.in"
{  yyval.nodep = buildtree( yypvt[-0].intval, yypvt[-1].nodep, bcon(1) ); } break;
case 159:
# line 795 "gram.in"
{ ubop:
			    yyval.nodep = buildtree( UNARY yypvt[-1].intval, yypvt[-0].nodep, NIL );
			    } break;
case 160:
# line 799 "gram.in"
{  if( ISFTN(yypvt[-0].nodep->in.type) || ISARY(yypvt[-0].nodep->in.type) ){
				werror( "& before array or function: ignored" );
				yyval.nodep = yypvt[-0].nodep;
				}
			    else if( yypvt[-0].nodep->in.op == UNARY MUL &&
				     (yypvt[-0].nodep->in.left->in.op == STASG ||
				      yypvt[-0].nodep->in.left->in.op == STCALL ||
				      yypvt[-0].nodep->in.left->in.op == UNARY STCALL) ){
				/* legal trees but not available to users */
				uerror( "unacceptable operand of &" );
				goto ubop;
				}
			    else goto ubop;
			    } break;
case 161:
# line 814 "gram.in"
{  goto ubop; } break;
case 162:
# line 816 "gram.in"
{
			    yyval.nodep = buildtree( yypvt[-1].intval, yypvt[-0].nodep, NIL );
			    } break;
case 163:
# line 820 "gram.in"
{  yyval.nodep = buildtree( yypvt[-1].intval==INCR ? ASG PLUS : ASG MINUS,
						yypvt[-0].nodep,
						bcon(1)  );
			    } break;
case 164:
# line 825 "gram.in"
{  yyval.nodep = doszof( yypvt[-0].nodep ); --nsizeof; } break;
case 165:
# line 827 "gram.in"
{  yyval.nodep = buildtree( CAST, yypvt[-2].nodep, yypvt[-0].nodep );
			    yyval.nodep->in.left->in.op = FREE;
			    yyval.nodep->in.op = FREE;
			    yyval.nodep = yyval.nodep->in.right;
			    } break;
case 166:
# line 833 "gram.in"
{  yyval.nodep = doszof( yypvt[-1].nodep ); --nsizeof; } break;
case 167:
# line 835 "gram.in"
{  yyval.nodep = buildtree( UNARY MUL, buildtree( PLUS, yypvt[-3].nodep, yypvt[-1].nodep ), NIL ); } break;
case 168:
# line 837 "gram.in"
{  yyval.nodep=buildtree(UNARY CALL,yypvt[-1].nodep,NIL); } break;
case 169:
# line 839 "gram.in"
{  yyval.nodep=buildtree(CALL,yypvt[-2].nodep,yypvt[-1].nodep); } break;
case 170:
# line 841 "gram.in"
{  if( yypvt[-1].intval == DOT ){
				if( notlval( yypvt[-2].nodep ) &&
				    !(yypvt[-2].nodep->in.op == UNARY MUL &&
				      (yypvt[-2].nodep->in.left->in.op == STASG ||
				       yypvt[-2].nodep->in.left->in.op == STCALL ||
				       yypvt[-2].nodep->in.left->in.op == UNARY STCALL)) )
				    uerror("structure reference must be addressable");
				yypvt[-2].nodep = buildtree( UNARY AND, yypvt[-2].nodep, NIL );
				}
			    idname = yypvt[-0].intval;
			    yyval.nodep = buildtree( STREF, yypvt[-2].nodep, buildtree( NAME, NIL, NIL ) );
			    } break;
case 171:
# line 854 "gram.in"
{  idname = yypvt[-0].intval;
			    /* recognize identifiers in initializations */
			    if( blevel==0 && stab[idname].stype == UNDEF ) {
				register NODE *q;
#ifndef FLEXNAMES
				werror( "undeclared initializer name %.8s", stab[idname].sname );
#else
				werror( "undeclared initializer name %s", stab[idname].sname );
#endif
				q = block( FREE, NIL, NIL, INT, 0, INT );
				q->tn.rval = idname;
				defid( q, EXTERN );
				}
			    yyval.nodep=buildtree(NAME,NIL,NIL);
			    if( nsizeof == 0 )
				stab[yypvt[-0].intval].suse = -lineno;
			} break;
case 172:
# line 872 "gram.in"
{  yyval.nodep=bcon(0);
			    yyval.nodep->tn.lval = lastcon;
			    yyval.nodep->tn.rval = NONAME;
			    if( yypvt[-0].intval ) yyval.nodep->fn.csiz = yyval.nodep->in.type = ctype(LONG);
			    } break;
case 173:
# line 878 "gram.in"
{  yyval.nodep=buildtree(FCON,NIL,NIL);
			    yyval.nodep->fpn.fval = fcon;
			    } break;
case 174:
# line 882 "gram.in"
{  yyval.nodep=buildtree(DCON,NIL,NIL);
			    yyval.nodep->dpn.dval = dcon;
			    } break;
case 175:
# line 886 "gram.in"
{  yyval.nodep = getstr(); /* get string contents */ } break;
case 176:
# line 888 "gram.in"
{ yyval.nodep=yypvt[-1].nodep; } break;
case 177:
# line 892 "gram.in"
{
			yyval.nodep = tymerge( yypvt[-1].nodep, yypvt[-0].nodep );
			yyval.nodep->in.op = NAME;
			yypvt[-1].nodep->in.op = FREE;
			} break;
case 178:
# line 900 "gram.in"
{ ++nsizeof; } break;
case 179:
# line 904 "gram.in"
{ yyval.nodep = bdty( NAME, NIL, -1 ); } break;
case 180:
# line 906 "gram.in"
{ yyval.nodep = bdty( UNARY CALL, bdty(NAME,NIL,-1),0); } break;
case 181:
# line 908 "gram.in"
{  yyval.nodep = bdty( UNARY CALL, yypvt[-3].nodep, 0 ); } break;
case 182:
# line 910 "gram.in"
{  goto umul; } break;
case 183:
# line 912 "gram.in"
{  goto uary; } break;
case 184:
# line 914 "gram.in"
{  goto bary;  } break;
case 185:
# line 916 "gram.in"
{ yyval.nodep = yypvt[-1].nodep; } break;
case 186:
# line 920 "gram.in"
{  if( stab[yypvt[-1].intval].stype == UNDEF ){
				register NODE *q;
				q = block( FREE, NIL, NIL, FTN|INT, 0, INT );
				q->tn.rval = yypvt[-1].intval;
				defid( q, EXTERN );
				}
			    idname = yypvt[-1].intval;
			    yyval.nodep=buildtree(NAME,NIL,NIL);
			    stab[idname].suse = -lineno;
			} break;
		}
		goto yystack;  /* stack new state and value */

	}
