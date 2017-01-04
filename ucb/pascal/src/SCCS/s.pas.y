h62745
s 00002/00002/00958
d D 5.4 88/01/03 00:13:40 bostic 19 18
c const is a reserved word for ANSI C
e
s 00002/00002/00958
d D 5.3 87/09/30 09:16:55 mckusick 18 17
c add second argument used by pxp (4.3BSD/ucb/17 Andrew Mack munnari)
e
s 00002/00004/00958
d D 5.2 85/06/20 17:21:55 mckusick 17 16
c copyright botch
e
s 00009/00001/00953
d D 5.1 85/06/05 16:03:34 dist 16 15
c Add copyright
e
s 00001/00024/00953
d D 2.2 85/01/10 18:42:16 mckusick 15 14
c remove -r1.13 conformant array productions for this release;
c hopefully they will be properly implemented some day
e
s 00000/00000/00977
d D 2.1 84/02/08 20:46:30 aoki 14 13
c synchronize to version 2
e
s 00024/00001/00953
d D 1.13 84/02/08 00:41:52 mckusick 13 12
c merge in conformant array code by Carol Nishizak
e
s 00001/00003/00953
d D 1.12 84/02/04 17:36:34 thien 12 11
c lint
e
s 00224/00165/00732
d D 1.11 83/08/19 05:08:36 thien 11 10
c Changed for linting
e
s 00002/00002/00895
d D 1.10 83/06/06 18:02:51 peter 10 9
c favor `procedure' over `function'.
e
s 00002/00000/00895
d D 1.9 82/08/30 16:24:31 peter 9 8
c fully expand reduce rules; so error recovery changes `external' to `forward'.
e
s 00000/00003/00895
d D 1.8 82/08/30 15:15:45 peter 8 7
c field_list ->* lambda so no special rule.
e
s 00003/00000/00895
d D 1.7 82/08/29 14:07:22 peter 7 6
c allowing no files list in program statement.
e
s 00001/00005/00894
d D 1.6 82/08/27 00:34:39 mckusick 6 5
c convert "assert" from being a reserved word to being a non-standard procedure
e
s 00000/00003/00899
d D 1.5 82/08/26 17:42:27 mckusick 5 4
c remove patch to "if-then-else" due to broken eyacc
e
s 00004/00004/00898
d D 1.4 81/03/18 21:17:53 mckusic 4 3
c mods for new formal routine syntax
e
s 00010/00014/00892
d D 1.3 80/09/02 22:06:30 peter 3 2
c interleaved declaration parts
e
s 00012/00012/00894
d D 1.2 80/08/27 22:40:59 peter 2 1
c @ => @@ to non-conflict sccsid
e
s 00906/00000/00000
d D 1.1 80/08/27 19:57:40 peter 1 0
c date and time created 80/08/27 19:57:40 by peter
e
u
U
t
T
I 1
D 16
/* Copyright (c) 1979 Regents of the University of California */
E 16
I 16
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
I 17
 *
 *	%W% (Berkeley) %G%
E 17
 */
D 17

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 17
E 16

/*
 * Yacc grammar for UNIX Pascal
 *
 * This grammar is processed by the commands in the shell script
 * "gram" to yield parse tables and semantic routines in the file
 * "y.tab.c" and a header defining the lexical tokens in "yy.h".
 *
 * In order for the syntactic error recovery possible with this
 * grammar to work, the grammar must be processed by a yacc which
 * has been modified to fully enumerate possibilities in states
 * which involve the symbol "error".
 * The parser used for Pascal also uses a different encoding of
 * the test entries in the action table which speeds the parse.
 * A version of yacc which will work for Pascal is included on
 * the distribution table as "eyacc".
 *
 * The "gram" script also makes the following changes to the "y.tab.c"
 * file:
 *
 *	1) Causes yyval to be declared int *.
 *
 *	2) Loads the variable yypv into a register as yyYpv so that
 *	   the arguments $1, ... are available as yyYpv[1] etc.
 *	   This produces much smaller code in the semantic actions.
 *
 *	3) Deletes the unused array yysterm.
 *
 *	4) Moves the declarations up to the flag line containing
 *	   '##' to the file yy.h so that the routines which use
 *	   these "magic numbers" don't have to all be compiled at
 *	   the same time.
 *
 *	5) Creates the semantic restriction checking routine yyEactr
D 2
 *	   by processing action lines containing `@'.
E 2
I 2
 *	   by processing action lines containing `@@'.
E 2
 *
 * This compiler uses a different version of the yacc parser, a
 * different yyerror which is called yerror, and requires more
 * lookahead sets than normally provided by yacc.
 *
 * Source for the yacc used with this grammar is included on
 * distribution tapes.
 */

/*
 * TERMINAL DECLARATIONS
 *
 * Some of the terminal declarations are out of the most natural
 * alphabetic order because the error recovery
 * will guess the first of equal cost non-terminals.
 * This makes, e.g. YTO preferable to YDOWNTO.
 */

%term
	YAND		YARRAY		YBEGIN		YCASE
	YCONST		YDIV		YDO		YDOTDOT
	YTO		YELSE		YEND		YFILE
D 10
	YFOR		YFORWARD	YFUNCTION	YGOTO
E 10
I 10
	YFOR		YFORWARD	YPROCEDURE	YGOTO
E 10
	YID		YIF		YIN		YINT
	YLABEL		YMOD		YNOT		YNUMB
	YOF		YOR		YPACKED		YNIL
D 10
	YPROCEDURE	YPROG		YRECORD		YREPEAT
E 10
I 10
	YFUNCTION	YPROG		YRECORD		YREPEAT
E 10
	YSET		YSTRING		YTHEN		YDOWNTO
	YTYPE		YUNTIL		YVAR		YWHILE
	YWITH		YBINT		YOCT		YHEX
D 3
	YASSERT		YCASELAB	YILLCH		YLAST
	YEXTERN
E 3
I 3
D 6
	YASSERT		YCASELAB	YILLCH		YEXTERN
	YLAST
E 6
I 6
	YCASELAB	YILLCH		YEXTERN		YLAST
E 6
E 3

/*
 * PRECEDENCE DECLARATIONS
 *
 * Highest precedence is the unary logical NOT.
 * Next are the multiplying operators, signified by '*'.
 * Lower still are the binary adding operators, signified by '+'.
 * Finally, at lowest precedence and non-associative are the relationals.
 */

%binary	'<'	'='	'>'	YIN
%left	'+'	'-'	YOR	'|'
%left	UNARYSIGN
%left	'*'	'/'	YDIV	YMOD	YAND	'&'
%left	YNOT

%{
/*
 * GLOBALS FOR ACTIONS
 */

/* Copyright (c) 1979 Regents of the University of California */

D 11
/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 11
I 11
D 12
#ifndef lint
static	char sccsid[] = "%Z%%M% %I% %G%";
#endif
E 12
I 12
/* static	char sccsid[] = "%Z%%M% %I% %G%"; */
E 12
E 11

/*
 * The following line marks the end of the yacc
 * Constant definitions which are removed from
 * y.tab.c and placed in the file y.tab.h.
 */
##
/* Copyright (c) 1979 Regents of the University of California */

static	char sccsid[] = "%Z%%M% %I% %G%";

#include "whoami.h"
#include "0.h"
I 11
#include "tree_ty.h"		/* must be included for yy.h */
E 11
#include "yy.h"
#include "tree.h"

#ifdef PI
#define	lineof(l)	l
#define	line2of(l)	l
#endif

%}

%%

/*
 * PRODUCTIONS
 */

goal:
D 3
	prog_hedr decls procs block '.'
		= funcend($1, $4, lineof($5));
E 3
I 3
	prog_hedr decls block '.'
D 11
		= funcend($1, $3, lineof($4));
E 11
I 11
		= funcend($1.nl_entry, $3.tr_entry, lineof($4.i_entry));
E 11
E 3
		|
D 3
	decls procs
E 3
I 3
	decls
E 3
		= segend();
		;
	

prog_hedr:
	YPROG YID '(' id_list ')' ';' 
D 11
		= $$ = funcbody(funchdr(tree5(T_PROG, lineof($1), $2, fixlist($4), NIL)));
E 11
I 11
		= $$.nl_entry = funcbody(funchdr(tree5(T_PROG, lineof($1.i_entry), $2.tr_entry, fixlist($4.tr_entry), TR_NIL)));
E 11
		|
I 7
	YPROG YID ';'
D 11
		= $$ = funcbody(funchdr(tree5(T_PROG, lineof($1), $2, NIL, NIL)));
E 11
I 11
		= $$.nl_entry = funcbody(funchdr(tree5(T_PROG, lineof($1.i_entry),  $2.tr_entry, TR_NIL, TR_NIL)));
E 11
		|
E 7
	YPROG error
		= {
			yyPerror("Malformed program statement", PPROG);
			/*
			 * Should make a program statement
			 * with "input" and "output" here.
			 */
D 11
			$$ = funcbody(funchdr(tree5(T_PROG, lineof($1), NIL, NIL, NIL)));
E 11
I 11
			$$.nl_entry = funcbody(funchdr(tree5(T_PROG, lineof($1.i_entry), TR_NIL, TR_NIL, TR_NIL)));
E 11
		  }
		;
block:
	YBEGIN stat_list YEND
		= {
D 11
			$$ = tree3(T_BSTL, lineof($1), fixlist($2));
			if ($3 < 0)
				brerror($1, "begin");
E 11
I 11
			$$.tr_entry = tree3(T_BSTL, lineof($1.i_entry), fixlist($2.tr_entry));
			if ($3.i_entry < 0)
				brerror($1.i_entry, "begin");
E 11
		  }
		;


/*
 * DECLARATION PART
 */
decls:
	decls decl
		= trfree();
		|
	decls error
		= {
D 11
Derror:
E 11
			constend(), typeend(), varend(), trfree();
			yyPerror("Malformed declaration", PDECL);
		  }
		|
	/* lambda */
		= trfree();
		;

decl:
	labels
		|
	const_decl
		= constend();
		|
	type_decl
		= typeend();
		|
	var_decl
		= varend();
I 3
		|
	proc_decl
E 3
		;

/*
 * LABEL PART
 */

labels:
	YLABEL label_decl ';'
D 11
		= label(fixlist($2), lineof($1));
E 11
I 11
		= label(fixlist($2.tr_entry), lineof($1.i_entry));
E 11
		;
label_decl:
	YINT
D 11
		= $$ = newlist($1 == NIL ? NIL : *hash($1, 1));
E 11
I 11
		= $$.tr_entry = newlist($1.i_entry == NIL ? TR_NIL :
					(struct tnode *) *hash($1.cptr, 1));
E 11
		|
	label_decl ',' YINT
D 11
		= $$ = addlist($1, $3 == NIL ? NIL : *hash($3, 1));
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.i_entry == NIL ?
				TR_NIL : (struct tnode *) *hash($3.cptr, 1));
E 11
		;

/*
 * CONST PART
 */

const_decl:
	YCONST YID '=' const ';'
D 11
		= constbeg($1, line2of($2)), const(lineof($3), $2, $4);
E 11
I 11
D 18
		= constbeg($1.i_entry), const(lineof($3.i_entry), $2.cptr,
						$4.tr_entry);
E 18
I 18
		= constbeg($1.i_entry, lineof($1.i_entry)),
D 19
		  const(lineof($3.i_entry), $2.cptr, $4.tr_entry);
E 19
I 19
		  constant(lineof($3.i_entry), $2.cptr, $4.tr_entry);
E 19
E 18
E 11
		|
	const_decl YID '=' const ';'
D 11
		= const(lineof($3), $2, $4);
E 11
I 11
D 19
		= const(lineof($3.i_entry), $2.cptr, $4.tr_entry);
E 19
I 19
		= constant(lineof($3.i_entry), $2.cptr, $4.tr_entry);
E 19
E 11
		|
	YCONST error
		= {
D 11
			constbeg($1, line2of($1));
E 11
I 11
			constbeg($1.i_entry);
E 11
Cerror:
			yyPerror("Malformed const declaration", PDECL);
		  }
		|
	const_decl error
		= goto Cerror;
		;

/*
 * TYPE PART
 */

type_decl:
	YTYPE YID '=' type ';'
D 11
		= typebeg($1, line2of($2)), type(lineof($3), $2, $4);
E 11
I 11
		= typebeg($1.i_entry, line2of($2.i_entry)), type(lineof($3.i_entry), $2.cptr, $4.tr_entry);
E 11
		|
	type_decl YID '=' type ';'
D 11
		= type(lineof($3), $2, $4);
E 11
I 11
		= type(lineof($3.i_entry), $2.cptr, $4.tr_entry);
E 11
		|
	YTYPE error
		= {
D 11
			typebeg($1, line2of($1));
E 11
I 11
			typebeg($1.i_entry, line2of($1.i_entry));
E 11
Terror:
			yyPerror("Malformed type declaration", PDECL);
		  }
		|
	type_decl error
		= goto Terror;
		;

/*
 * VAR PART
 */

var_decl:
	YVAR id_list ':' type ';'
D 11
		= varbeg($1, line2of($3)), var(lineof($3), fixlist($2), $4);
E 11
I 11
		= varbeg($1.i_entry, line2of($3.i_entry)), var(lineof($3.i_entry), fixlist($2.tr_entry), $4.tr_entry);
E 11
		|
	var_decl id_list ':' type ';'
D 11
		= var(lineof($3), fixlist($2), $4);
E 11
I 11
		= var(lineof($3.i_entry), fixlist($2.tr_entry), $4.tr_entry);
E 11
		|
	YVAR error 
		= {
D 11
			varbeg($1, line2of($1));
E 11
I 11
			varbeg($1.i_entry, line2of($1.i_entry));
E 11
Verror:
			yyPerror("Malformed var declaration", PDECL);
		  }
		|
	var_decl error
		= goto Verror;
		;

/*
 * PROCEDURE AND FUNCTION DECLARATION PART
 */

D 3
procs:
	/* lambda */
		|
	procs proc
		= trfree();
		;
proc:
E 3
I 3
proc_decl:
E 3
	phead YFORWARD ';'
D 11
		= funcfwd($1);
E 11
I 11
		= funcfwd($1.nl_entry);
E 11
		|
	phead YEXTERN ';'
D 11
		= funcext($1);
E 11
I 11
		= (void) funcext($1.nl_entry);
E 11
		|
D 3
	pheadres decls procs block ';'
		= funcend($1, $4, lineof($5));
E 3
I 3
	pheadres decls block ';'
D 11
		= funcend($1, $3, lineof($4));
E 11
I 11
		= funcend($1.nl_entry, $3.tr_entry, lineof($4.i_entry));
E 11
I 9
		|
	phead error
E 9
E 3
		;
pheadres:
	phead
D 11
		= funcbody($1);
E 11
I 11
		= (void) funcbody($1.nl_entry);
E 11
		;
phead:
	porf YID params ftype ';'
D 11
		= $$ = funchdr(tree5($1, lineof($5), $2, $3, $4));
E 11
I 11
		= $$.nl_entry = funchdr(tree5($1.i_entry, lineof($5.i_entry),
				$2.tr_entry, $3.tr_entry, $4.tr_entry));
E 11
		;
porf:
	YPROCEDURE
D 11
		= $$ = T_PDEC;
E 11
I 11
		= $$.i_entry = T_PDEC;
E 11
		|
	YFUNCTION
D 11
		= $$ = T_FDEC;
E 11
I 11
		= $$.i_entry = T_FDEC;
E 11
		;
params:
	'(' param_list ')'
D 11
		= $$ = fixlist($2);
E 11
I 11
		= $$.tr_entry = fixlist($2.tr_entry);
E 11
		|
	/* lambda */
D 11
		= $$ = NIL;
E 11
I 11
		= $$.tr_entry = TR_NIL;
E 11
		;

/*
 * PARAMETERS
 */

param:
	id_list ':' type
D 11
		= $$ = tree3(T_PVAL, fixlist($1), $3);
E 11
I 11
		= $$.tr_entry = tree3(T_PVAL, (int) fixlist($1.tr_entry), $3.tr_entry);
E 11
		|
D 13
	YVAR id_list ':' type
E 13
I 13
D 15
	YVAR id_list ':' vtype
E 15
I 15
	YVAR id_list ':' type
E 15
E 13
D 11
		= $$ = tree3(T_PVAR, fixlist($2), $4);
E 11
I 11
		= $$.tr_entry = tree3(T_PVAR, (int) fixlist($2.tr_entry), $4.tr_entry);
E 11
		|
D 4
	YFUNCTION id_list ':' type
		= $$ = tree3(T_PFUNC, fixlist($2), $4);
E 4
I 4
	YFUNCTION id_list params ftype
D 11
		= $$ = tree5(T_PFUNC, fixlist($2), $4, $3, lineof($1));
E 11
I 11
		= $$.tr_entry = tree5(T_PFUNC, (int) fixlist($2.tr_entry),
				$4.tr_entry, $3.tr_entry, 
				(struct tnode *) lineof($1.i_entry));
E 11
E 4
		|
D 4
	YPROCEDURE id_list
		= $$ = tree2(T_PPROC, fixlist($2));
E 4
I 4
	YPROCEDURE id_list params ftype
D 11
		= $$ = tree5(T_PPROC, fixlist($2), $4, $3, lineof($1));
E 11
I 11
		= $$.tr_entry = tree5(T_PPROC, (int) fixlist($2.tr_entry),
				$4.tr_entry, $3.tr_entry, 
				(struct tnode *) lineof($1.i_entry));
E 11
E 4
		;
ftype:
	':' type
		= $$ = $2;
		|
	/* lambda */
D 11
		= $$ = NIL;
E 11
I 11
		= $$.tr_entry = TR_NIL;
E 11
		;
I 13
D 15
vtype:
	type_id
		|
	c_ary
		;
c_ary:
	YARRAY '[' i_type_list ']' YOF vtype
		= $$.tr_entry = tree4(T_TYCARY, lineof($1.i_entry),
				fixlist($3.tr_entry), $6.tr_entry);
		;
i_type_list:
	i_type
		= $$.tr_entry = newlist($1.tr_entry);
		|
	i_type_list ';' i_type
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
		;
i_type:
	YID YDOTDOT YID ':' type_id
		= $$.tr_entry = tree5(T_TYCRANG,lineof($2.i_entry), $1.tr_entry,
				$3.tr_entry, $5.tr_entry);
		;
E 15
E 13
param_list:
	param
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	param_list ';' param
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		;
I 13
D 15

E 15
E 13

/*
 * CONSTANTS
 */

const:
	YSTRING
D 11
		= $$ = tree2(T_CSTRNG, $1);
E 11
I 11
		= $$.tr_entry = tree2(T_CSTRNG, $1.i_entry);
E 11
		|
	number
		|
	'+' number
D 11
		= $$ = tree2(T_PLUSC, $2);
E 11
I 11
		= $$.tr_entry = tree2(T_PLUSC, $2.i_entry);
E 11
		|
	'-' number
D 11
		= $$ = tree2(T_MINUSC, $2);
E 11
I 11
		= $$.tr_entry = tree2(T_MINUSC, $2.i_entry);
E 11
		;
number:
	const_id
D 11
		= $$ = tree2(T_ID, $1);
E 11
I 11
		= $$.tr_entry = tree2(T_ID, $1.i_entry);
E 11
		|
	YINT
D 11
		= $$ = tree2(T_CINT, $1);
E 11
I 11
		= $$.tr_entry = tree2(T_CINT, $1.i_entry);
E 11
		|
	YBINT
D 11
		= $$ = tree2(T_CBINT, $1);
E 11
I 11
		= $$.tr_entry = tree2(T_CBINT, $1.i_entry);
E 11
		|
	YNUMB
D 11
		= $$ = tree2(T_CFINT, $1);
E 11
I 11
		= $$.tr_entry = tree2(T_CFINT, $1.i_entry);
E 11
		;
const_list:
	const
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	const_list ',' const
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		;

/*
 * TYPES
 */

type:
	simple_type
		|
	'^' YID
D 11
		= $$ = tree3(T_TYPTR, lineof($1), tree2(T_ID, $2));
E 11
I 11
		= $$.tr_entry = tree3(T_TYPTR, lineof($1.i_entry), tree2(T_ID,
								$2.i_entry));
E 11
		|
	struct_type
		|
	YPACKED struct_type
D 11
		= $$ = tree3(T_TYPACK, lineof($1), $2);
E 11
I 11
		= $$.tr_entry = tree3(T_TYPACK, lineof($1.i_entry), $2.tr_entry);
E 11
		;
simple_type:
	type_id
		|
	'(' id_list ')'
D 11
		= $$ = tree3(T_TYSCAL, lineof($1), fixlist($2));
E 11
I 11
		= $$.tr_entry = tree3(T_TYSCAL, lineof($1.i_entry), fixlist($2.tr_entry));
E 11
		|
	const YDOTDOT const
D 11
		= $$ = tree4(T_TYRANG, lineof($2), $1, $3);
E 11
I 11
		= $$.tr_entry = tree4(T_TYRANG, lineof($2.i_entry), $1.tr_entry,
				$3.tr_entry);
E 11
		;
struct_type:
	YARRAY '[' simple_type_list ']' YOF type
D 11
		= $$ = tree4(T_TYARY, lineof($1), fixlist($3), $6);
E 11
I 11
		= $$.tr_entry = tree4(T_TYARY, lineof($1.i_entry),
					fixlist($3.tr_entry), $6.tr_entry);
E 11
		|
	YFILE YOF type
D 11
		= $$ = tree3(T_TYFILE, lineof($1), $3);
E 11
I 11
		= $$.tr_entry = tree3(T_TYFILE, lineof($1.i_entry), $3.tr_entry);
E 11
		|
	YSET YOF simple_type
D 11
		= $$ = tree3(T_TYSET, lineof($1), $3);
E 11
I 11
		= $$.tr_entry = tree3(T_TYSET, lineof($1.i_entry), $3.tr_entry);
E 11
		|
	YRECORD field_list YEND
		= {
D 11
			$$ = setuptyrec( lineof( $1 ) , $2 );
			if ($3 < 0)
				brerror($1, "record");
E 11
I 11
			$$.tr_entry = setuptyrec( lineof( $1.i_entry ) , $2.tr_entry);
			if ($3.i_entry < 0)
				brerror($1.i_entry, "record");
E 11
		  }
		;
simple_type_list:
	simple_type
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	simple_type_list ',' simple_type
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		;

/*
 * RECORD TYPE
 */
field_list:
	fixed_part variant_part
D 11
		= $$ = tree4(T_FLDLST, lineof(NIL), fixlist($1), $2);
E 11
I 11
		= $$.tr_entry = tree4(T_FLDLST, lineof(NIL), 
				fixlist($1.tr_entry), $2.tr_entry);
E 11
		;
fixed_part:
	field
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	fixed_part ';' field
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		|
	fixed_part error
		= yyPerror("Malformed record declaration", PDECL);
		;
field:
	/* lambda */
D 11
		= $$ = NIL;
E 11
I 11
		= $$.tr_entry = TR_NIL;
E 11
		|
	id_list ':' type
D 11
		= $$ = tree4(T_RFIELD, lineof($2), fixlist($1), $3);
E 11
I 11
		= $$.tr_entry = tree4(T_RFIELD, lineof($2.i_entry),
				fixlist($1.tr_entry), $3.tr_entry);
E 11
		;

variant_part:
	/* lambda */
D 11
		= $$ = NIL;
E 11
I 11
		= $$.tr_entry = TR_NIL;
E 11
		|
	YCASE type_id YOF variant_list
D 11
		= $$ = tree5(T_TYVARPT, lineof($1), NIL, $2, fixlist($4));
E 11
I 11
		= $$.tr_entry = tree5(T_TYVARPT, lineof($1.i_entry), TR_NIL, 
				$2.tr_entry, fixlist($4.tr_entry));
E 11
		|
	YCASE YID ':' type_id YOF variant_list
D 11
		= $$ = tree5(T_TYVARPT, lineof($1), $2, $4, fixlist($6));
E 11
I 11
		= $$.tr_entry = tree5(T_TYVARPT, lineof($1.i_entry),
				$2.tr_entry, $4.tr_entry,
					fixlist($6.tr_entry));
E 11
		;
variant_list:
	variant
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	variant_list ';' variant
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		|
	variant_list error
		= yyPerror("Malformed record declaration", PDECL);
		;
variant:
	/* lambda */
D 11
		= $$ = NIL;
E 11
I 11
		= $$.tr_entry = TR_NIL;
E 11
		|
	const_list ':' '(' field_list ')'
D 11
		= $$ = tree4(T_TYVARNT, lineof($2), fixlist($1), $4);
E 11
I 11
		= $$.tr_entry = tree4(T_TYVARNT,lineof($2.i_entry), fixlist($1.tr_entry),
				$4.tr_entry);
E 11
D 8
		|
	const_list ':' '(' ')'
		= $$ = tree4(T_TYVARNT, lineof($2), fixlist($1), NIL);
E 8
		;

/*
 * STATEMENT LIST
 */

stat_list:
	stat
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	stat_lsth stat
		= {
D 11
			if ((p = $1) != NIL && (q = p[1])[0] == T_IFX) {
				q[0] = T_IFEL;
				q[4] = $2;
E 11
I 11
			if ((p = $1.tr_entry) != TR_NIL && (q = p->list_node.list)->tag == T_IFX) {
				q->tag = T_IFEL;
				q->if_node.else_stmnt = $2.tr_entry;
E 11
			} else
D 11
				$$ = addlist($1, $2);
E 11
I 11
				$$.tr_entry= addlist($1.tr_entry, $2.tr_entry);
E 11
		  }
		;

stat_lsth:
	stat_list ';'
D 11
		= if ((q = $1) != NIL && (p = q[1]) != NIL && p[0] == T_IF) {
E 11
I 11
		= if ((q = $1.tr_entry) != TR_NIL && (p = q->list_node.list) != TR_NIL && p->tag == T_IF) {
E 11
			if (yychar < 0)
				yychar = yylex();
			if (yyshifts >= 2 && yychar == YELSE) {
				recovered();
D 11
				copy(&Y, &OY, sizeof Y);
E 11
I 11
				copy((char *) (&Y), (char *) (&OY), sizeof Y);
E 11
				yerror("Deleted ';' before keyword else");
				yychar = yylex();
D 11
				p[0] = T_IFX;
E 11
I 11
				p->tag = T_IFX;
E 11
			}
		  }
		;

/*
 * CASE STATEMENT LIST
 */

cstat_list:
	cstat
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	cstat_list ';' cstat
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		|
	error
		= {
D 11
			$$ = NIL;
E 11
I 11
			$$.tr_entry = TR_NIL;
E 11
Kerror:
			yyPerror("Malformed statement in case", PSTAT);
		  }
		|
	cstat_list error
		= goto Kerror;
		;

cstat:
	const_list ':' stat
D 11
		= $$ = tree4(T_CSTAT, lineof($2), fixlist($1), $3);
E 11
I 11
		= $$.tr_entry = tree4(T_CSTAT, lineof($2.i_entry),
				fixlist($1.tr_entry), $3.tr_entry);
E 11
		|
	YCASELAB stat
D 11
		= $$ = tree4(T_CSTAT, lineof($1), NIL, $2);
E 11
I 11
		= $$.tr_entry = tree4(T_CSTAT, lineof($1.i_entry), TR_NIL,
					$2.tr_entry);
E 11
		|
	/* lambda */
D 11
		= $$ = NIL;
E 11
I 11
		= $$.tr_entry = TR_NIL;
E 11
		;

/*
 * STATEMENT
 */

stat:
	/* lambda */
D 11
		= $$ = NIL;
E 11
I 11
		= $$.tr_entry = TR_NIL;
E 11
		|
	YINT ':' stat
D 11
		= $$ = tree4(T_LABEL, lineof($2), $1 == NIL ? NIL : *hash($1, 1), $3);
E 11
I 11
		= $$.tr_entry = tree4(T_LABEL, lineof($2.i_entry),
				$1.tr_entry == TR_NIL ? TR_NIL :
					    (struct tnode *) *hash($1.cptr, 1), $3.tr_entry);
E 11
		|
	proc_id
D 11
		= $$ = tree4(T_PCALL, lineof(yyline), $1, NIL);
E 11
I 11
		= $$.tr_entry = tree4(T_PCALL, lineof(yyline), $1.tr_entry,
						TR_NIL);
E 11
		|
	proc_id '(' wexpr_list ')'
D 11
		= $$ = tree4(T_PCALL, lineof($2), $1, fixlist($3));
E 11
I 11
		= $$.tr_entry = tree4(T_PCALL, lineof($2.i_entry), $1.tr_entry,
					fixlist($3.tr_entry));
E 11
		|
	YID error
		= goto NSerror;
		|
	assign
		|
	YBEGIN stat_list YEND
		= {
D 11
			$$ = tree3(T_BLOCK, lineof($1), fixlist($2));
			if ($3 < 0)
				brerror($1, "begin");
E 11
I 11
			$$.tr_entry = tree3(T_BLOCK, lineof($1.i_entry),
						fixlist($2.tr_entry));
			if ($3.i_entry < 0)
				brerror($1.i_entry, "begin");
E 11
		  }
		|
	YCASE expr YOF cstat_list YEND
		= {
D 11
			$$ = tree4(T_CASE, lineof($1), $2, fixlist($4));
			if ($5 < 0)
				brerror($1, "case");
E 11
I 11
			$$.tr_entry = tree4(T_CASE, lineof($1.i_entry),
					$2.tr_entry, fixlist($4.tr_entry));
			if ($5.i_entry < 0)
				brerror($1.i_entry, "case");
E 11
		  }
		|
	YWITH var_list YDO stat
D 11
		= $$ = tree4(T_WITH, lineof($1), fixlist($2), $4);
E 11
I 11
		= $$.tr_entry = tree4(T_WITH, lineof($1.i_entry),
				fixlist($2.tr_entry), $4.tr_entry);
E 11
		|
	YWHILE expr YDO stat
D 11
		= $$ = tree4(T_WHILE, lineof($1), $2, $4);
E 11
I 11
		= $$.tr_entry = tree4(T_WHILE, lineof($1.i_entry), $2.tr_entry,
					$4.tr_entry);
E 11
		|
	YREPEAT stat_list YUNTIL expr
D 11
		= $$ = tree4(T_REPEAT, lineof($3), fixlist($2), $4);
E 11
I 11
		= $$.tr_entry = tree4(T_REPEAT, lineof($3.i_entry),
				fixlist($2.tr_entry), $4.tr_entry);
E 11
		|
	YFOR assign YTO expr YDO stat
D 11
		= $$ = tree5(T_FORU, lineof($1), $2, $4, $6);
E 11
I 11
		= $$.tr_entry = tree5(T_FORU, lineof($1.i_entry), $2.tr_entry,
				$4.tr_entry, $6.tr_entry);
E 11
		|
	YFOR assign YDOWNTO expr YDO stat
D 11
		= $$ = tree5(T_FORD, lineof($1), $2, $4, $6);
E 11
I 11
		= $$.tr_entry = tree5(T_FORD, lineof($1.i_entry), $2.tr_entry,
				$4.tr_entry, $6.tr_entry);
E 11
		|
	YGOTO YINT
D 11
		= $$ = tree3(T_GOTO, lineof($1), *hash($2, 1));
E 11
I 11
		= $$.tr_entry = tree3(T_GOTO, lineof($1.i_entry),
				(struct tnode *) *hash($2.cptr, 1));
E 11
		|
	YIF expr YTHEN stat
D 11
		= $$ = tree5(T_IF, lineof($1), $2, $4, NIL);
E 11
I 11
		= $$.tr_entry = tree5(T_IF, lineof($1.i_entry), $2.tr_entry,
				$4.tr_entry, TR_NIL);
E 11
		|
	YIF expr YTHEN stat YELSE stat
D 11
		= $$ = tree5(T_IFEL, lineof($1), $2, $4, $6);
E 11
I 11
		= $$.tr_entry = tree5(T_IFEL, lineof($1.i_entry), $2.tr_entry,
					$4.tr_entry, $6.tr_entry);
E 11
D 6
		|
D 5
	YIF expr YTHEN stat YELSE
		= $$ = tree5(T_IFEL, lineof($1), $2, $4, NIL);
		|
E 5
	YASSERT '(' expr ')'
		= $$ = tree3(T_ASRT, lineof($1), $3);
E 6
		|
	error
		= {
NSerror:
D 11
			$$ = NIL;
Serror:
E 11
I 11
			$$.tr_entry = TR_NIL;
E 11
			yyPerror("Malformed statement", PSTAT);
		  }
		;
assign:
	variable ':' '=' expr
D 11
		= $$ = tree4(T_ASGN, lineof($2), $1, $4);
E 11
I 11
		= $$.tr_entry = tree4(T_ASGN, lineof($2.i_entry), $1.tr_entry,
				    $4.tr_entry);
E 11
		;

/*
 * EXPRESSION
 */

expr:
	error
		= {
NEerror:
D 11
			$$ = NIL;
Eerror:
E 11
I 11
			$$.tr_entry = TR_NIL;
E 11
			yyPerror("Missing/malformed expression", PEXPR);
		  }
		|
	expr relop expr			%prec '<'
D 11
		= $$ = tree4($2, $1[1] == SAWCON ? $3[1] : $1[1], $1, $3);
E 11
I 11
		= $$.tr_entry = tree4($2.i_entry,
			$1.tr_entry->expr_node.const_tag == SAWCON ?
			$3.tr_entry->expr_node.const_tag :
			$1.tr_entry->expr_node.const_tag,
			$1.tr_entry, $3.tr_entry);
E 11
		|
	'+' expr			%prec UNARYSIGN
D 11
		= $$ = tree3(T_PLUS, $2[1], $2);
E 11
I 11
		= $$.tr_entry = tree3(T_PLUS, $2.tr_entry->expr_node.const_tag,
				$2.tr_entry);
E 11
		|
	'-' expr			%prec UNARYSIGN
D 11
		= $$ = tree3(T_MINUS, $2[1], $2);
E 11
I 11
		= $$.tr_entry = tree3(T_MINUS, $2.tr_entry->expr_node.const_tag,
				$2.tr_entry);
E 11
		|
	expr addop expr			%prec '+'
D 11
		= $$ = tree4($2, $1[1] == SAWCON ? $3[1] : $1[1], $1, $3);
E 11
I 11
		= $$.tr_entry = tree4($2.i_entry,
			$1.tr_entry->expr_node.const_tag == SAWCON ?
			$3.tr_entry->expr_node.const_tag :
			$1.tr_entry->expr_node.const_tag, $1.tr_entry,
			$3.tr_entry);
E 11
		|
	expr divop expr			%prec '*'
D 11
		= $$ = tree4($2, $1[1] == SAWCON ? $3[1] : $1[1], $1, $3);
E 11
I 11
		= $$.tr_entry = tree4($2.i_entry,
			$1.tr_entry->expr_node.const_tag == SAWCON ?
			$3.tr_entry->expr_node.const_tag :
			$1.tr_entry->expr_node.const_tag, $1.tr_entry,
			$3.tr_entry);
E 11
		|
	YNIL
D 11
		= $$ = tree2(T_NIL, NOCON);
E 11
I 11
		= $$.tr_entry = tree2(T_NIL, NOCON);
E 11
		|
	YSTRING
D 11
		= $$ = tree3(T_STRNG, SAWCON, $1);
E 11
I 11
		= $$.tr_entry = tree3(T_STRNG, SAWCON, $1.tr_entry);
E 11
		|
	YINT
D 11
		= $$ = tree3(T_INT, NOCON, $1);
E 11
I 11
		= $$.tr_entry = tree3(T_INT, NOCON, $1.tr_entry);
E 11
		|
	YBINT
D 11
		= $$ = tree3(T_BINT, NOCON, $1);
E 11
I 11
		= $$.tr_entry = tree3(T_BINT, NOCON, $1.tr_entry);
E 11
		|
	YNUMB
D 11
		= $$ = tree3(T_FINT, NOCON, $1);
E 11
I 11
		= $$.tr_entry = tree3(T_FINT, NOCON, $1.tr_entry);
E 11
		|
	variable
		|
	YID error
		= goto NEerror;
		|
	func_id '(' wexpr_list ')'
D 11
		= $$ = tree4(T_FCALL, NOCON, $1, fixlist($3));
E 11
I 11
		= $$.tr_entry = tree4(T_FCALL, NOCON, $1.tr_entry,
			fixlist($3.tr_entry));
E 11
		|
	'(' expr ')'
D 11
		= $$ = $2;
E 11
I 11
		= $$.tr_entry = $2.tr_entry;
E 11
		|
	negop expr			%prec YNOT
D 11
		= $$ = tree3(T_NOT, NOCON, $2);
E 11
I 11
		= $$.tr_entry = tree3(T_NOT, NOCON, $2.tr_entry);
E 11
		|
	'[' element_list ']'
D 11
		= $$ = tree3(T_CSET, SAWCON, fixlist($2));
E 11
I 11
		= $$.tr_entry = tree3(T_CSET, SAWCON, fixlist($2.tr_entry));
E 11
		|
	'[' ']'
D 11
		= $$ = tree3(T_CSET, SAWCON, NIL);
E 11
I 11
		= $$.tr_entry = tree3(T_CSET, SAWCON, TR_NIL);
E 11
		;

element_list:
	element
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	element_list ',' element
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		;
element:
	expr
		|
	expr YDOTDOT expr
D 11
		= $$ = tree3(T_RANG, $1, $3);
E 11
I 11
		= $$.tr_entry = tree3(T_RANG, $1.i_entry, $3.tr_entry);
E 11
		;

/*
 * QUALIFIED VARIABLES
 */

variable:
	YID
		= {
D 2
			@ return (identis(var, VAR));
E 2
I 2
			@@ return (identis(var, VAR));
E 2
D 11
			$$ = setupvar($1, NIL);
E 11
I 11
			$$.tr_entry = setupvar($1.cptr, TR_NIL);
E 11
		  }
		|
	qual_var
D 11
		= $1[3] = fixlist($1[3]);
E 11
I 11
		= $1.tr_entry->var_node.qual = 
					fixlist($1.tr_entry->var_node.qual);
E 11
		;
qual_var:
	array_id '[' expr_list ']'
D 11
		= $$ = setupvar($1, tree2(T_ARY, fixlist($3)));
E 11
I 11
		= $$.tr_entry = setupvar($1.cptr, tree2(T_ARY, 
				(int) fixlist($3.tr_entry)));
E 11
		|
	qual_var '[' expr_list ']'
D 11
		= $1[3] = addlist($1[3], tree2(T_ARY, fixlist($3)));
E 11
I 11
		= $1.tr_entry->var_node.qual =
				addlist($1.tr_entry->var_node.qual,
				tree2(T_ARY, (int) fixlist($3.tr_entry)));
E 11
		|
	record_id '.' field_id
D 11
		= $$ = setupvar($1, setupfield($3, NIL));
E 11
I 11
		= $$.tr_entry = setupvar($1.cptr, setupfield($3.tr_entry,
							TR_NIL));
E 11
		|
	qual_var '.' field_id
D 11
		= $1[3] = addlist($1[3], setupfield($3, NIL));
E 11
I 11
		= $1.tr_entry->var_node.qual =
		    addlist($1.tr_entry->var_node.qual,
		    setupfield($3.tr_entry, TR_NIL));
E 11
		|
	ptr_id '^'
D 11
		= $$ = setupvar($1, tree1(T_PTR));
E 11
I 11
		= $$.tr_entry = setupvar($1.cptr, tree1(T_PTR));
E 11
		|
	qual_var '^'
D 11
		= $1[3] = addlist($1[3], tree1(T_PTR));
E 11
I 11
		= $1.tr_entry->var_node.qual = 
			addlist($1.tr_entry->var_node.qual, tree1(T_PTR));
E 11
		;

/*
 * Expression with write widths
 */
wexpr:
	expr
		|
	expr ':' expr
D 11
		= $$ = tree4(T_WEXP, $1, $3, NIL);
E 11
I 11
		= $$.tr_entry = tree4(T_WEXP, $1.i_entry, $3.tr_entry, TR_NIL);
E 11
		|
	expr ':' expr ':' expr
D 11
		= $$ = tree4(T_WEXP, $1, $3, $5);
E 11
I 11
		= $$.tr_entry = tree4(T_WEXP, $1.i_entry, $3.tr_entry,
						$5.tr_entry);
E 11
		|
	expr octhex
D 11
		= $$ = tree4(T_WEXP, $1, NIL, $2);
E 11
I 11
		= $$.tr_entry = tree4(T_WEXP, $1.i_entry, TR_NIL, $2.tr_entry);
E 11
		|
	expr ':' expr octhex
D 11
		= $$ = tree4(T_WEXP, $1, $3, $4);
E 11
I 11
		= $$.tr_entry = tree4(T_WEXP, $1.i_entry, $3.tr_entry,
					$4.tr_entry);
E 11
		;
octhex:
	YOCT
D 11
		= $$ = OCT;
E 11
I 11
		= $$.i_entry = OCT;
E 11
		|
	YHEX
D 11
		= $$ = HEX;
E 11
I 11
		= $$.i_entry = HEX;
E 11
		;

expr_list:
	expr
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	expr_list ',' expr
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		;

wexpr_list:
	wexpr
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	wexpr_list ',' wexpr
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		;

/*
 * OPERATORS
 */

relop:
D 11
	'='	= $$ = T_EQ;
E 11
I 11
	'='	= $$.i_entry = T_EQ;
E 11
		|
D 11
	'<'	= $$ = T_LT;
E 11
I 11
	'<'	= $$.i_entry = T_LT;
E 11
		|
D 11
	'>'	= $$ = T_GT;
E 11
I 11
	'>'	= $$.i_entry = T_GT;
E 11
		|
D 11
	'<' '>'	= $$ = T_NE;
E 11
I 11
	'<' '>'	= $$.i_entry = T_NE;
E 11
		|
D 11
	'<' '='	= $$ = T_LE;
E 11
I 11
	'<' '='	= $$.i_entry = T_LE;
E 11
		|
D 11
	'>' '='	= $$ = T_GE;
E 11
I 11
	'>' '='	= $$.i_entry = T_GE;
E 11
		|
D 11
	YIN	= $$ = T_IN;
E 11
I 11
	YIN	= $$.i_entry = T_IN;
E 11
		;
addop:
D 11
	'+'	= $$ = T_ADD;
E 11
I 11
	'+'	= $$.i_entry = T_ADD;
E 11
		|
D 11
	'-'	= $$ = T_SUB;
E 11
I 11
	'-'	= $$.i_entry = T_SUB;
E 11
		|
D 11
	YOR	= $$ = T_OR;
E 11
I 11
	YOR	= $$.i_entry = T_OR;
E 11
		|
D 11
	'|'	= $$ = T_OR;
E 11
I 11
	'|'	= $$.i_entry = T_OR;
E 11
		;
divop:
D 11
	'*'	= $$ = T_MULT;
E 11
I 11
	'*'	= $$.i_entry = T_MULT;
E 11
		|
D 11
	'/'	= $$ = T_DIVD;
E 11
I 11
	'/'	= $$.i_entry = T_DIVD;
E 11
		|
D 11
	YDIV	= $$ = T_DIV;
E 11
I 11
	YDIV	= $$.i_entry = T_DIV;
E 11
		|
D 11
	YMOD	= $$ = T_MOD;
E 11
I 11
	YMOD	= $$.i_entry = T_MOD;
E 11
		|
D 11
	YAND	= $$ = T_AND;
E 11
I 11
	YAND	= $$.i_entry = T_AND;
E 11
		|
D 11
	'&'	= $$ = T_AND;
E 11
I 11
	'&'	= $$.i_entry = T_AND;
E 11
		;

negop:
	YNOT
		|
	'~'
		;

/*
 * LISTS
 */

var_list:
	variable
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	var_list ',' variable
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		;

id_list:
	YID
D 11
		= $$ = newlist($1);
E 11
I 11
		= $$.tr_entry = newlist($1.tr_entry);
E 11
		|
	id_list ',' YID
D 11
		= $$ = addlist($1, $3);
E 11
I 11
		= $$.tr_entry = addlist($1.tr_entry, $3.tr_entry);
E 11
		;

/*
 * Identifier productions with semantic restrictions
 *
D 2
 * For these productions, the character @ signifies
E 2
I 2
 * For these productions, the characters @@ signify
E 2
 * that the associated C statement is to provide
 * the semantic restriction for this reduction.
 * These lines are made into a procedure yyEactr, similar to
 * yyactr, which determines whether the corresponding reduction
 * is permitted, or whether an error is to be signaled.
 * A zero return from yyEactr is considered an error.
 * YyEactr is called with an argument "var" giving the string
 * name of the variable in question, essentially $1, although
 * $1 will not work because yyEactr is called from loccor in
 * the recovery routines.
 */

const_id:
	YID
D 2
		= @ return (identis(var, CONST));
E 2
I 2
		= @@ return (identis(var, CONST));
E 2
		;
type_id:
	YID
		= {
D 2
			@ return (identis(var, TYPE));
E 2
I 2
			@@ return (identis(var, TYPE));
E 2
D 11
			$$ = tree3(T_TYID, lineof(yyline), $1);
E 11
I 11
			$$.tr_entry = tree3(T_TYID, lineof(yyline), $1.tr_entry);
E 11
		  }
		;
var_id:
	YID
D 2
		= @ return (identis(var, VAR));
E 2
I 2
		= @@ return (identis(var, VAR));
E 2
		;
array_id:
	YID
D 2
		= @ return (identis(var, ARRAY));
E 2
I 2
		= @@ return (identis(var, ARRAY));
E 2
		;
ptr_id:
	YID
D 2
		= @ return (identis(var, PTRFILE));
E 2
I 2
		= @@ return (identis(var, PTRFILE));
E 2
		;
record_id:
	YID
D 2
		= @ return (identis(var, RECORD));
E 2
I 2
		= @@ return (identis(var, RECORD));
E 2
		;
field_id:
	YID
D 2
		= @ return (identis(var, FIELD));
E 2
I 2
		= @@ return (identis(var, FIELD));
E 2
		;
proc_id:
	YID
D 2
		= @ return (identis(var, PROC));
E 2
I 2
		= @@ return (identis(var, PROC));
E 2
		;
func_id:
	YID
D 2
		= @ return (identis(var, FUNC));
E 2
I 2
		= @@ return (identis(var, FUNC));
E 2
		;
E 1
