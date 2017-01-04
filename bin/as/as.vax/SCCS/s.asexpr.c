h06705
s 00001/00001/00508
d D 5.4 87/10/22 10:05:10 bostic 9 8
c ANSI C; sprintf now returns an int.
e
s 00001/00001/00508
d D 5.3 86/11/17 19:39:43 donn 8 7
c LCSYM stabs need to know about their referenced symbol even after the
c symbol has gone through pass 1; we kluge around and hide the symbol's
c address in 'exprisname'.
e
s 00000/00001/00509
d D 5.2 85/06/19 16:16:29 mckusick 7 6
c copyright botch
e
s 00006/00002/00504
d D 5.1 85/04/30 13:56:30 dist 6 5
c Add copyright
e
s 00000/00001/00506
d D 4.5 83/06/30 09:56:39 rrh 5 4
c assembly language source file reading now does end of buffer 
c detection on a per character basis, not  on a per line basis, thereby 
c simplifying the monkey business with reading lines in asscan2.c; slight 
c execution penalty
e
s 00128/00089/00379
d D 4.4 83/06/09 11:32:31 rrh 4 3
c improve token printing, and use this with error reporting
e
s 00164/00119/00304
d D 4.3 82/02/14 16:31:41 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00043/00044/00380
d D 4.2 80/08/15 18:02:51 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 00424/00000/00000
d D 4.1 80/08/13 18:55:10 bill 1 0
c date and time created 80/08/13 18:55:10 by bill
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1980 Regents of the University of California */
static	char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
/*
D 6
 *	Copyright (c) 1982 Regents of the University of California
E 6
I 6
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 6
 */
I 6

E 6
#ifndef lint
D 6
static char sccsid[] = "%Z%%M% %I% %G%";
E 6
I 6
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 6

D 7
#endif not lint
E 7
E 3
#include <stdio.h>
D 2
#include <sys/types.h>
E 2
#include "as.h"
I 3
#include "asscan.h"
E 3
#include "asexpr.h"

/*
 * Tables for combination of operands.
 */
#define	XTXRN	5<<1		/* indexes last row/column when right shifted */

/*
 *	table for +
 */
readonly char pltab[6][6] = {
/*		UND	ABS	TXT	DAT	BSS	EXT */

/*UND*/		XUNDEF,	XUNDEF,	XUNDEF,	XUNDEF,	XUNDEF,	XUNDEF,
/*ABS*/		XUNDEF,	XABS,	XTEXT,	XDATA,	XBSS,	XXTRN,
/*TXT*/		XUNDEF,	XTEXT,	ERR,	ERR,	ERR,	ERR,
/*DAT*/		XUNDEF,	XDATA,	ERR,	ERR,	ERR,	ERR,
/*BSS*/		XUNDEF,	XBSS,	ERR,	ERR,	ERR,	ERR,
/*EXT*/		XUNDEF,	XXTRN,	ERR,	ERR,	ERR,	ERR,
};

/*
 *	table for -
 */
readonly char mintab[6][6] = {
/*		UND	ABS	TXT	DAT	BSS	EXT */

/*UND*/		XUNDEF,	XUNDEF,	XUNDEF,	XUNDEF,	XUNDEF,	XUNDEF,
/*ABS*/		XUNDEF,	XABS,	ERR,	ERR,	ERR,	ERR,
/*TXT*/		XUNDEF,	XTEXT,	XABS,	ERR,	ERR,	ERR,
/*DAT*/		XUNDEF,	XDATA,	ERR,	XABS,	ERR,	ERR,
/*BSS*/		XUNDEF,	XBSS,	ERR,	ERR,	XABS,	ERR,
/*EXT*/		XUNDEF,	XXTRN,	ERR,	ERR,	ERR,	ERR,
};

/* 
 *	table for other operators
 */
readonly char othtab[6][6] = {
/*		UND	ABS	TXT	DAT	BSS	EXT */

/*UND*/		XUNDEF,	XUNDEF,	XUNDEF,	XUNDEF,	XUNDEF,	XUNDEF,
/*ABS*/		XUNDEF,	XABS,	ERR,	ERR,	ERR,	ERR,
/*TXT*/		XUNDEF,	ERR,	ERR,	ERR,	ERR,	ERR,
/*DAT*/		XUNDEF,	ERR,	ERR,	ERR,	ERR,	ERR,
/*BSS*/		XUNDEF,	ERR,	ERR,	ERR,	ERR,	ERR,
/*EXT*/		XUNDEF,	ERR,	ERR,	ERR,	ERR,	ERR,
};

D 3
struct exp *
combine(op, exp1, exp2)
	register struct exp *exp1, *exp2;
E 3
I 3
struct exp *combine(op, exp1, exp2)
	reg struct exp *exp1, *exp2;
E 3
{
D 3
	register 	e1_type, e2_type;
D 2
	register	type;
E 2
I 2
	register	back_type;
E 3
I 3
	reg 	e1_type, e2_type;
	reg	back_type;
	char	*btype = "The assembler can only do arithmetic on 1,2, or 4 byte integers";
E 3
E 2

	lastnam=0; 			/* kludge for jxxx instructions */

D 2
	e1_type = exp1->xtype&XTYPE;
	e2_type = exp2->xtype&XTYPE;
E 2
I 2
	e1_type = exp1->e_xtype&XTYPE;
	e2_type = exp2->e_xtype&XTYPE;
E 2

D 2
	if (exp1->xtype==XXTRN+XUNDEF)
E 2
I 2
	if (exp1->e_xtype==XXTRN+XUNDEF)
E 2
		e1_type = XTXRN;
D 2
	if (exp2->xtype==XXTRN+XUNDEF)
E 2
I 2
	if (exp2->e_xtype==XXTRN+XUNDEF)
E 2
		e2_type = XTXRN;
	if (passno==1)
D 2
		if (exp1->xloc!=exp2->xloc && e1_type==e2_type)
E 2
I 2
		if (exp1->e_xloc!=exp2->e_xloc && e1_type==e2_type)
E 2
			e1_type = e2_type = XTXRN;	/* error on != loc ctrs */
	e1_type >>= 1;		/*dispose of the external (XXTRN) bit*/
	e2_type >>= 1;

D 3
	switch (op) {
E 3
I 3
	switch(exp1->e_number.num_tag){
	case TYPB:
	case TYPW:
	case TYPL:
		break;
	default:
		yyerror(btype);
		return(exp1);
	}
	switch(exp2->e_number.num_tag){
	case TYPB:
	case TYPW:
	case TYPL:
		break;
	default:
		yyerror(btype);
		return(exp1);
	}
	switch (op){
E 3
	case PLUS:
D 2
		exp1->xvalue += exp2->xvalue;
		type = pltab[e1_type][e2_type];
E 2
I 2
		exp1->e_xvalue += exp2->e_xvalue;
		back_type = pltab[e1_type][e2_type];
E 2
		break;
	case MINUS:
D 2
		exp1->xvalue -= exp2->xvalue;
		type = mintab[e1_type][e2_type];
E 2
I 2
		exp1->e_xvalue -= exp2->e_xvalue;
		back_type = mintab[e1_type][e2_type];
E 2
		break;
	case IOR:
D 2
		exp1->xvalue |= exp2->xvalue;
E 2
I 2
		exp1->e_xvalue |= exp2->e_xvalue;
E 2
		goto comm;
	case XOR:
D 2
		exp1->xvalue ^= exp2->xvalue;
E 2
I 2
		exp1->e_xvalue ^= exp2->e_xvalue;
E 2
		goto comm;
	case AND:
D 2
		exp1->xvalue &= exp2->xvalue;
E 2
I 2
		exp1->e_xvalue &= exp2->e_xvalue;
E 2
		goto comm;
	case ORNOT:
D 2
		exp1->xvalue |= ~exp2->xvalue;
E 2
I 2
		exp1->e_xvalue |= ~exp2->e_xvalue;
E 2
		goto comm;
	case LSH:
D 2
		exp1->xvalue <<= exp2->xvalue;
E 2
I 2
		exp1->e_xvalue <<= exp2->e_xvalue;
E 2
		goto comm;
	case RSH:
D 2
		exp1->xvalue >>= exp2->xvalue;
E 2
I 2
		exp1->e_xvalue >>= exp2->e_xvalue;
E 2
		goto comm;
	case TILDE:
D 2
		exp1->xvalue |= ~ exp2->xvalue;
E 2
I 2
		exp1->e_xvalue |= ~ exp2->e_xvalue;
E 2
		goto comm;
	case MUL:
D 2
		exp1->xvalue *= exp2->xvalue;
E 2
I 2
		exp1->e_xvalue *= exp2->e_xvalue;
E 2
		goto comm;
	case DIV:
D 2
		if (exp2->xvalue == 0)
E 2
I 2
		if (exp2->e_xvalue == 0)
E 2
			yyerror("Divide check");
		else
D 2
			exp1->xvalue /= exp2->xvalue;
E 2
I 2
			exp1->e_xvalue /= exp2->e_xvalue;
E 2
		goto comm;
	case REGOP:
D 2
		if (exp2->xvalue == 0)
E 2
I 2
		if (exp2->e_xvalue == 0)
E 2
			yyerror("Divide check (modulo)");
		else
D 2
			exp1->xvalue %= exp2->xvalue;
E 2
I 2
			exp1->e_xvalue %= exp2->e_xvalue;
E 2
		goto comm;
	
	comm:
D 2
		type = othtab[e1_type][e2_type];
E 2
I 2
		back_type = othtab[e1_type][e2_type];
E 2
		break;
	default:
		yyerror("Internal error: unknown operator");
	}

	if (e2_type==(XTXRN>>1))
D 2
		exp1->xname = exp2->xname;
	exp1->xtype = type | (
			(exp1->xtype|exp2->xtype) & (XFORW|XXTRN) );
	if (type==ERR)
E 2
I 2
		exp1->e_xname = exp2->e_xname;
	exp1->e_xtype = back_type | (
			(exp1->e_xtype|exp2->e_xtype) & (XFORW|XXTRN) );
	if (back_type==ERR)
E 2
		yyerror("Relocation error");
	return(exp1);
}

buildtokensets()
{
#define clobber(val, set) tokensets[(val)] |= (set)

	clobber(SEMI,	LINSTBEGIN);
	clobber(NL,	LINSTBEGIN);
	clobber(INT,	LINSTBEGIN);

	clobber(NAME,	YUKKYEXPRBEG + LINSTBEGIN);
	clobber(INSTn,	YUKKYEXPRBEG);
	clobber(INST0,	YUKKYEXPRBEG);
	clobber(REG,	YUKKYEXPRBEG);
	clobber(BFINT,	YUKKYEXPRBEG);

	clobber(INT,	SAFEEXPRBEG);
D 3
	clobber(FLTNUM,	SAFEEXPRBEG);
E 3
I 3
	clobber(BIGNUM,	SAFEEXPRBEG);
E 3

	clobber(PLUS,	ADDOPS);
	clobber(MINUS,	ADDOPS + EBEGOPS);

	clobber(LP,	EBEGOPS);

	clobber(IOR,	BOOLOPS);
	clobber(XOR,	BOOLOPS);
	clobber(AND,	BOOLOPS);
	clobber(ORNOT,	BOOLOPS);

	clobber(TILDE,	MULOPS + EBEGOPS);
	clobber(LSH,	MULOPS);
	clobber(RSH,	MULOPS);
	clobber(MUL,	MULOPS);
	clobber(DIV,	MULOPS);
	clobber(REGOP,	MULOPS);	/* % */

}

/*
 *	We keep the current token class in this global variable, so 
 *	the recursive descent expression analyzers can talk amongst
 *	themselves, and so that we may use the macros shift and shift over
 */

extern	int	yylval;		/*the value of the lexical value*/
extern	struct	exp	*xp;	/*the next free expression slot*/

D 3
static int	val;
int exprparse(inval, backexpr)	/*return the value the read head is sitting on*/
	int	inval;
E 3
I 3
static	inttoktype	val;

/*
 *	return the value the read head is sitting on
 */
inttoktype exprparse(inval, backexpr)
	inttoktype	inval;
E 3
	struct	exp **backexpr;
{
D 3
	register struct exp *lexpr;
	int	op;
E 3
I 3
	reg	struct exp *lexpr;
	inttoktype	op;
E 3

	val = inval;
	lexpr = boolterm();
	while (INTOKSET(val, ADDOPS)){
		op = val;
		shift;
		lexpr = combine(op, lexpr, boolterm());
	}
	*backexpr = lexpr;
	return(val);
}

struct exp *boolterm()
{
D 3
	register	struct exp *lexpr;
	int	op;
E 3
I 3
	reg	struct exp *lexpr;
	inttoktype	op;
E 3

	lexpr = term();
	while(INTOKSET(val, BOOLOPS)){
		op = val;
		shift;
		lexpr = combine(op, lexpr, term());
	}
	return(lexpr);
}

struct exp *term()
{
D 3
	register	struct	exp	*lexpr;
	int		op;
E 3
I 3
	reg	struct	exp	*lexpr;
	inttoktype	op;
E 3

	lexpr = factor();
	while(INTOKSET(val, MULOPS)){
		op = val;
		shift;
		lexpr = combine(op, lexpr, factor());
	}
	return(lexpr);
}

struct exp *factor()
{
	struct	exp *lexpr;
D 3
	int		op;
E 3
I 3
	inttoktype	op;
E 3
	extern		int	droppedLP;	/*called exprparse after consuming an LP*/

	if (val == LP || droppedLP){
		if (droppedLP)
			droppedLP = 0;
		else
			shift;		/*the LP*/
		val = exprparse(val, &lexpr);
		if (val != RP)
			yyerror("right parenthesis expected");
		else
			shift;
	} else
	if (INTOKSET(val, YUKKYEXPRBEG)){
		lexpr = yukkyexpr(val, yylval);
		shift;
	}
	else if (INTOKSET(val, SAFEEXPRBEG)){
		lexpr = (struct exp *)yylval;
		shift;
	}
	else if ( (val == TILDE) || (val == MINUS) ){
		op = val;
		shift;
		lexpr = xp++;
D 2
		lexpr->xtype = XABS;
		lexpr->xvalue = 0;
E 2
I 2
		lexpr->e_xtype = XABS;
D 3
		lexpr->e_xvalue = 0;
E 3
I 3
		lexpr->e_number = Znumber;
		lexpr->e_number.num_tag = TYPL;
E 3
E 2
		lexpr = combine(op, lexpr, factor());
D 3
	}
	else {
E 3
I 3
	} else {
E 3
		yyerror("Bad expression syntax");
		lexpr = xp++;
D 2
		lexpr->xtype = XABS;
		lexpr->xvalue = 0;
E 2
I 2
		lexpr->e_xtype = XABS;
D 3
		lexpr->e_xvalue = 0;
E 3
I 3
		lexpr->e_number = Znumber;
		lexpr->e_number.num_tag = TYPL;
E 3
E 2
	}
	return(lexpr);
}

struct exp *yukkyexpr(val, np)
	int	val;
D 3
	register	np;
E 3
I 3
	reg	np;
E 3
{
D 3
	register	struct exp *locxp;
	extern		int	exprisname;	/*last factor is a name*/
E 3
I 3
	reg	struct exp *locxp;
	extern	int	exprisname;	/*last factor is a name*/
		int	off = 0;
E 3

	exprisname = 0;
	locxp = xp++;
D 3
	if (val == NAME || val == BFINT){
		if (val == BFINT) {
			int off = 0;
D 2
			yylval = ((struct exp *)np)->xvalue;
E 2
I 2
			yylval = ((struct exp *)np)->e_xvalue;
E 2
			if (yylval < 0) {
				yylval = -yylval;
				yylval--;
				off = -1;
				if (lgensym[yylval] == 1)
					yyerror("Reference to undefined local label %db", yylval);
			} else {
				yylval--;
				genref[yylval] = 1;
			}
			sprintf(yytext, "L%d\001%d", yylval, lgensym[yylval] + off);
			yylval = np = (int)*lookup(passno == 1);
			lastnam = (struct symtab *)np;
E 3
I 3
	locxp->e_number = Znumber;
	locxp->e_number.num_tag = TYPL;

	switch(val){
	case BFINT:
		yylval = ((struct exp *)np)->e_xvalue;
		if (yylval < 0) {
			yylval = -yylval;
			yylval--;
			off = -1;
			if (lgensym[yylval] == 1)
				yyerror("Reference to undefined local label %db", yylval);
		} else {
			yylval--;
			genref[yylval] = 1;
E 3
		}
I 3
		(void)sprintf(yytext, "L%d\001%d", yylval, lgensym[yylval] + off);
		yylval = np = (int)*lookup(passno == 1);
		lastnam = (struct symtab *)np;
		/* FALLTHROUGH */
	case NAME:
E 3
D 8
		exprisname++;
E 8
I 8
		exprisname = (int) np;
E 8
D 2
		locxp->xtype = ((struct symtab *)np)->type;
		if (( ((struct symtab *)np)->type&XTYPE)==XUNDEF) { /*forward*/
			locxp->xname = (struct symtab *)np;
			locxp->xvalue = 0;
E 2
I 2
		locxp->e_xtype = ((struct symtab *)np)->s_type;
		if (( ((struct symtab *)np)->s_type&XTYPE)==XUNDEF) { /*forward*/
			locxp->e_xname = (struct symtab *)np;
			locxp->e_xvalue = 0;
E 2
			if (passno==1)
D 2
				((struct symtab *)np)->type |= XFORW;
E 2
I 2
				((struct symtab *)np)->s_type |= XFORW;
E 2
		} else {	/*otherwise, just get the value*/
D 2
			locxp->xvalue = ((struct symtab *)np)->value;
			locxp->xname = NULL;
E 2
I 2
			locxp->e_xvalue = ((struct symtab *)np)->s_value;
			locxp->e_xname = NULL;
E 2
		}
D 3
	} else {	/*INSTn or INST0 or REG*/
E 3
I 3
		break;
	default:
		yyerror("Internal Error in yukkyexpr");
		/* FALLTHROUGH */

	case INSTn:
	case INST0:
	case REG:
E 3
D 2
		locxp->xtype = XABS;
		locxp->xvalue = ( (int)np) & 0xFF;
		locxp->xloc = 0;
		locxp->xname = NULL;
E 2
I 2
		locxp->e_xtype = XABS;
		locxp->e_xvalue = ( (int)np) & 0xFF;
		locxp->e_xloc = 0;
		locxp->e_xname = NULL;
I 3
		break;
E 3
E 2
	}

	return(locxp);
}

I 4
/*
 *	Print definitions for token kinds
 */
static char pdirect[]	= "directive";
static char pinstr[]	= "instruction";
static char phunk[]	= "lexeme";
static char psmall[]	= "small symbol";
static char pcntrl[]	= "control token";
E 4

D 4
#ifdef DEBUG
char	*tok_name[LASTTOKEN - FIRSTTOKEN + 1];
E 4
I 4
#define	DIRECT	pdirect
#define	INSTR	pinstr
#define	HUNK	phunk
#define	SMALL	psmall
#define	CNTRL	pcntrl

E 4
struct Tok_Desc{
	int		tok_which;
I 4
	char		*tok_kind;
E 4
	char		*tok_name;
D 4
} tok_desc[] = {
D 3
	FIRSTTOKEN,	"firsttoken",	/* 0 */
	ISPACE,		"ispace", 	/* 1 */
	IBYTE,		"ibyte", 	/* 2 */
	IWORD,		"iword", 	/* 3 */
	IINT,		"iint", 	/* 4 */
	ILONG,		"ilong", 	/* 5 */
	IDATA,		"idata", 	/* 6 */
	IGLOBAL,	"iglobal", 	/* 7 */
	ISET,		"iset", 	/* 8 */
	ITEXT,		"itext", 	/* 9 */
	ICOMM,		"icomm", 	/* 10 */
	ILCOMM,		"ilcomm", 	/* 11 */
	IFLOAT,		"ifloat", 	/* 12 */
	IDOUBLE,	"idouble", 	/* 13 */
	IORG,		"iorg", 	/* 14 */
	IASCII,		"iascii", 	/* 15 */
	IASCIZ,		"iasciz", 	/* 16 */
	ILSYM,		"ilsym", 	/* 17 */
	IFILE,		"ifile", 	/* 18 */
	ILINENO,	"ilineno", 	/* 19 */
	IABORT,		"iabort", 	/* 20 */
	ISTAB,		"istab", 	/* 23 */
	ISTABSTR,	"istabstr", 	/* 24 */
	ISTABNONE,	"istabnone", 	/* 25 */
	ISTABDOT,	"istabdot", 	/* 26 */
	IJXXX,		"ijxxx", 	/* 27 */
	IALIGN,		"ialign", 	/* 28 */
	INST0,		"inst0", 	/* 29 */
	INSTn,		"instn", 	/* 30 */
	BFINT,		"bfint",	/* 31 */
	PARSEEOF,	"parseeof",	/* 32 */
	ILINESKIP,	"ilineskip",	/* 33 */
	VOID,		"void",		/* 34 */
	SKIP,		"skip",		/* 35 */
	INT,		"int",		/* 36 */
	FLTNUM,		"fltnum",	/* 37 */
	NAME,		"name",		/* 38 */
	STRING,		"string",	/* 39 */
	QUAD,		"quad",		/* 40 */
	SIZESPEC,	"sizespec", 	/* 41 */
	REG,		"reg",		/* 42 */
	MUL,		"mul",		/* 43 */
	LITOP,		"litop",	/* 44 */
	LP,		"lp",		/* 45 */
	MP,		"mp",		/* 46 */
	NEEDSBUF,	"needsbuf",	/* 48 */	
	REGOP,		"regop",	/* 49 */
	NL,		"nl",		/* 50 */
	SCANEOF,	"scaneof",	/* 51 */
	BADCHAR,	"badchar",	/* 52 */
	SP,		"sp",		/* 53 */
	ALPH,		"alph",		/* 54 */
	DIG,		"dig",		/* 55 */
	SQ,		"sq",		/* 56 */
	DQ,		"dq",		/* 57 */
	SH,		"sh",		/* 58 */
	LSH,		"lsh",		/* 59 */
	RSH,		"rsh",		/* 60 */
	MINUS,		"minus",	/* 61 */
	SIZEQUOTE,	"sizequote",	/* 62 */
	XOR,		"xor",		/* 64 */
	DIV,		"div",		/* 65 */
	SEMI,		"semi",		/* 66 */
	COLON,		"colon",	/* 67 */
	PLUS,		"plus",		/* 68 */
	IOR,		"ior",		/* 69 */ 
	AND,		"and",		/* 70 */
	TILDE,		"tilde",	/* 71 */
	ORNOT,		"ornot",	/* 72 */
	CM,		"cm",		/* 73 */
	LB,		"lb",		/* 74 */
	RB,		"rb",		/* 75 */
	RP,		"rp",		/* 76 */
	LASTTOKEN,	"lasttoken"	/* 80 */
E 3
I 3
	FIRSTTOKEN,	"firsttoken",
	ISPACE,		"ispace", 
	IBYTE,		"ibyte", 
	IWORD,		"iword", 
	IINT,		"iint", 
	ILONG,		"ilong", 
	IQUAD,		"quad",	
	IOCTA,		"octa",	
	IDATA,		"idata", 
	IGLOBAL,	"iglobal", 
	ISET,		"iset", 
	ITEXT,		"itext", 
	ICOMM,		"icomm", 
	ILCOMM,		"ilcomm", 
	IFFLOAT,	"iffloat", 
	IDFLOAT,	"idfloat", 
	IGFLOAT,	"igfloat", 
	IHFLOAT,	"ihfloat", 
	IORG,		"iorg", 
	IASCII,		"iascii", 
	IASCIZ,		"iasciz", 
	ILSYM,		"ilsym", 
	IFILE,		"ifile", 
	ILINENO,	"ilineno", 
	IABORT,		"iabort", 
	ISTAB,		"istab", 
	ISTABSTR,	"istabstr", 
	ISTABNONE,	"istabnone", 
	ISTABDOT,	"istabdot", 
	IJXXX,		"ijxxx", 
	IALIGN,		"ialign", 
	INST0,		"inst0", 
	INSTn,		"instn", 
	BFINT,		"bfint",
	PARSEEOF,	"parseeof",
	ILINESKIP,	"ilineskip",
	VOID,		"void",	
	SKIP,		"skip",	
	INT,		"int",	
	BIGNUM,		"bignum",
	NAME,		"name",	
	STRING,		"string",
	SIZESPEC,	"sizespec", 
	REG,		"reg",	
	MUL,		"mul",	
	LITOP,		"litop",
	LP,		"lp",	
	MP,		"mp",	
	NEEDSBUF,	"needsbuf",
	REGOP,		"regop",
	NL,		"nl",	
	SCANEOF,	"scaneof",
	BADCHAR,	"badchar",
	SP,		"sp",	
	ALPH,		"alph",	
	DIG,		"dig",	
	SQ,		"sq",	
	DQ,		"dq",	
	SH,		"sh",	
	LSH,		"lsh",	
	RSH,		"rsh",	
	MINUS,		"minus",
	SIZEQUOTE,	"sizequote",
	XOR,		"xor",	
	DIV,		"div",	
	SEMI,		"semi",	
	COLON,		"colon",
	PLUS,		"plus",	
	IOR,		"ior",	
	AND,		"and",	
	TILDE,		"tilde",
	ORNOT,		"ornot",
	CM,		"cm",	
	LB,		"lb",	
	RB,		"rb",	
	RP,		"rp",	
	LASTTOKEN,	"lasttoken"
E 4
E 3
};
I 4
struct Tok_Desc *tok_name[LASTTOKEN - FIRSTTOKEN + 1];

struct Tok_Desc tok_desc[] = {
	FIRSTTOKEN,	DIRECT,	"first token",

	IBYTE,		DIRECT,	".byte",
	IWORD,		DIRECT,	".word",
	IINT,		DIRECT,	".int",
	ILONG,		DIRECT,	".long",
	IQUAD,		DIRECT,	".quad",
	IOCTA,		DIRECT,	".octa",
	IFFLOAT,	DIRECT,	".ffloat",
	IDFLOAT,	DIRECT,	".dfloat",
	IGFLOAT,	DIRECT,	".gfloat",
	IHFLOAT,	DIRECT,	".hfloat",
	IASCII,		DIRECT,	".ascii",
	IASCIZ,		DIRECT,	".asciz",
	IFILL,		DIRECT,	".fill",
	ISPACE,		DIRECT,	".space",

	IDATA,		DIRECT,	".data",
	ITEXT,		DIRECT,	".text",
	IGLOBAL,	DIRECT,	".global",
	IALIGN,		DIRECT,	".align",

	ISET,		DIRECT,	".set",
	ICOMM,		DIRECT,	".comm",
	ILCOMM,		DIRECT,	".lcomm",
	IORG,		DIRECT,	".org",
	ILSYM,		DIRECT,	".lsym",

	ISTAB,		DIRECT,	".stab",
	ISTABSTR,	DIRECT,	".stabstr",
	ISTABNONE,	DIRECT,	".stabnone",
	ISTABDOT,	DIRECT,	".stabdot",

	IFILE,		DIRECT,	".file",
	ILINENO,	DIRECT,	".lineno",
	IABORT,		DIRECT,	".abort",

	IJXXX,		INSTR,	"jump pseudo",
	INST0,		INSTR,	"0 argument inst",
	INSTn,		INSTR,	"n argument inst",

	PARSEEOF,	CNTRL,	"parse end of file",
	ILINESKIP,	CNTRL,	"skip lines",
	VOID,		CNTRL,	"void",
	SKIP,		CNTRL,	"skip",
D 5
	NEEDSBUF,	CNTRL,	"need scanner buffer",
E 5
	NL,		CNTRL,	"new line",
	SCANEOF,	CNTRL,	"scanner end of file",
	BADCHAR,	CNTRL,	"bad character",
	SH,		CNTRL,	"comment, #",

	INT,		HUNK,	"int",
	BFINT,		HUNK,	"local label",
	BIGNUM,		HUNK,	"big number",
	NAME,		HUNK,	"name",
	STRING,		HUNK,	"string",
	REG,		HUNK,	"register specifier",

	SIZESPEC,	SMALL,	"size specifier, [BWLbwl]",
	SIZEQUOTE,	SMALL,	"sizequote, [^']",
	LITOP,		SMALL,	"litop",

	MP,		SMALL,	"minus parenthesis, -(",
	REGOP,		SMALL,	"register operator, %",

	SP,		SMALL,	"space",
	ALPH,		SMALL,	"alphabetic character, [A-Za-z_]",
	DIG,		SMALL,	"digit character, [A-Fa-f0-9]",

	SQ,		SMALL,	"single quote, '",
	DQ,		SMALL,	"double quote, \"",

	LSH,		SMALL,	"arithmetic left shift, <",
	RSH,		SMALL,	"arithmetic right shift, >",
	XOR,		SMALL,	"exclusive or, ^",

	PLUS,		SMALL,	"plus, +",
	MINUS,		SMALL,	"minus, -",
	MUL,		SMALL,	"multiply, *",
	DIV,		SMALL,	"divide, /",
	SEMI,		SMALL,	"semi colon, ;",
	COLON,		SMALL,	"colon, :",
	IOR,		SMALL,	"inclusive or, |",
	AND,		SMALL,	"and, &",

	TILDE,		SMALL,	"one's complement, ~",
	ORNOT,		SMALL,	"ornot, !",
	CM,		SMALL,	"comma",

	LB,		SMALL,	"left bracket, [",
	RB,		SMALL,	"right bracket, ]",
	LP,		SMALL,	"left parenthesis, (",
	RP,		SMALL,	"right parentheis, )",

	LASTTOKEN,	SMALL,	"last token",
};
E 4
/*
 *	turn a token type into a string
 */
D 3
static	int	fixed = 0;
E 3
char *tok_to_name(token)
{
I 3
	static	int	fixed = 0;
I 4
	static	char	buf[64];
	static	struct	Tok_Desc 	NA = {0, (char *)0, "NOT ASSIGNED"};
		int	i;
		char	*cp;
E 4

E 3
	if (!fixed){
D 4
		int	i;
E 4
		for (i = FIRSTTOKEN; i <= LASTTOKEN; i++)
D 4
			tok_name[i] = "NOT ASSIGNED";
		for (i = FIRSTTOKEN; i <= sizeof(tok_desc)/sizeof(struct Tok_Desc); i++){
			tok_name[tok_desc[i].tok_which] = tok_desc[i].tok_name;
E 4
I 4
			tok_name[i] = &NA;
		for (i = 0; i <= sizeof(tok_desc)/sizeof(struct Tok_Desc); i++){
			tok_name[tok_desc[i].tok_which] = &tok_desc[i];
E 4
		}
		fixed = 1;
	}
D 4
	if (FIRSTTOKEN <= token && token <= LASTTOKEN)
		return(tok_name[token]);
	else
E 4
I 4
	if (FIRSTTOKEN <= token && token <= LASTTOKEN){
D 9
		sprintf(buf, "%s %s", tok_name[token]->tok_kind,
E 9
I 9
		(void)sprintf(buf, "%s %s", tok_name[token]->tok_kind,
E 9
			tok_name[token]->tok_name);
		return(buf);
	} else {
E 4
		panic("Unknown token number, %d\n", token);
D 4
	/*NOTREACHED*/
E 4
I 4
		/*NOTREACHED*/
	}
E 4
}
D 4
#endif DEBUG
E 4
E 1
