h47078
s 00006/00002/00094
d D 5.1 85/04/30 14:05:01 dist 5 4
c Add copyright
e
s 00001/00001/00095
d D 4.4 83/06/09 11:33:09 rrh 4 3
c shiftover calls special complaint function to get reasonable error messages
e
s 00008/00002/00088
d D 4.3 82/02/14 16:35:58 rrh 3 2
c Fix reported and outstanding bugs. Reformat some text for
c readability/understandability. Assembles new instructions  for G and H
c format floating numbers & new queue instructions
c asscan.c split into 4 files; two additional files to construct and
c manipulate G and H format numbers, with analog for atof()
c Numerical accuracy of new atof() not verified; standard atof() used
c for F and D floating numbers.  As does NOT use G and H instructions itself
e
s 00004/00004/00086
d D 4.2 80/08/15 18:04:20 henry 2 1
c use struct nlist; change field names; vgrind format fixes
e
s 00090/00000/00000
d D 4.1 80/08/13 18:55:52 bill 1 0
c date and time created 80/08/13 18:55:52 by bill
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1980 Regents of the University of California */
/* "%Z%%M% %I% %G%" */
E 3
/*
I 3
D 5
 *	Copyright (c) 1982 Regents of the University of California
 *	%Z%%M% %I% %G%
E 5
I 5
 * Copyright (c) 1982 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
E 5
 */
I 5

E 5
/*
E 3
 *	Definitions to parse tokens
 */

#define ERROR(string)		yyerror(string); goto errorfix

#define peekahead (*tokptr)

#define shift 			val = yylex()
#define advance 	shift

#define shiftover(token)	if (val != token) { \
D 4
					yyerror("token expected"); \
E 4
I 4
					shiftoerror(token); \
E 4
					goto errorfix; \
				} \
				shift

#define advanceover 	shiftover

/*
 *	To speed up the expression processing, we class the input tokens
 *	into various sets.
 *
 *	We don't call the recursive descent expression analyzer if we can
 *	determine by looking at the next token after the first token in
 *	an expression that the expression is simple (name, integer or floating
 *	point value).  Expressions with operators are parsed using the recursive
 *	descent method.
 */

/*
 *	Functional forwards for expression utility routines
 */
struct	exp	*combine();
struct	exp	*boolterm();
struct	exp	*term();
struct	exp	*factor();
struct	exp	*yukkyexpr();

/*
 *	The set definitions
 */

extern	char	tokensets[(LASTTOKEN) - (FIRSTTOKEN) + 1];

D 2
#define LINSTBEGIN	01	/*SEMI, NL, NAME*/
E 2
I 2
#define	LINSTBEGIN	01	/*SEMI, NL, NAME*/
E 2
#define	EBEGOPS		02	/*LP, MINUS, TILDE*/
D 2
#define	YUKKYEXPRBEG	04	/*NAME, INSTn, INST0, REG, DOT*/
E 2
I 2
#define	YUKKYEXPRBEG	04	/*NAME, INSTn, INST0, REG, BFINT*/
E 2
#define	SAFEEXPRBEG	010	/*INT, FLTNUM*/
D 2
#define ADDOPS		020	/*PLUS, MINUS*/
E 2
I 2
#define	ADDOPS		020	/*PLUS, MINUS*/
E 2
#define	BOOLOPS		040	/*IOR, XOR, AND*/
D 2
#define MULOPS		0100	/*LSH, RSH, MUL, DIV, TILDE*/
E 2
I 2
#define	MULOPS		0100	/*LSH, RSH, MUL, DIV, TILDE*/
E 2

#define	INTOKSET(val, set)	(tokensets[(val)] & (set) )
I 3

inttoktype	exprparse();
inttoktype	funnyreg();
inttoktype	yylex();
E 3

#define expr(xp, val) { \
	if ( (!INTOKSET(val, EBEGOPS)) && (!INTOKSET(peekahead, ADDOPS+BOOLOPS+MULOPS))) { \
		if (INTOKSET(val, YUKKYEXPRBEG)) xp = yukkyexpr(val, yylval); \
		else xp = (struct exp *) yylval; \
		shift; \
	} else { \
		val = exprparse(val, ptrloc1xp); \
		xp = loc1xp; \
	} \
    }

/*
 *	Registers can be either of the form r0...pc, or
 *	of the form % <expression>
 *	NOTE:	Reizers documentation on the assembler says that it
 *	can be of the form r0 + <expression>.. That's not true.
 *
 *	NOTE:	Reizer's yacc grammar would seem to allow an expression
 *	to be: (This is undocumented)
 *		a)	a register
 *		b)	an Instruction (INSTn or INST0)
 */

#define findreg(regno) \
	if (val == REG) { \
		regno = yylval; \
		shift; \
	} else \
	if (val == REGOP) { \
		shift;	/*over the REGOP*/ \
		val = funnyreg(val, ptrregno); \
	} \
	else { ERROR ("register expected"); }
E 1
