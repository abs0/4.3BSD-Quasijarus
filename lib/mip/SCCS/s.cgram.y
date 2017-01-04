h27984
s 00002/00002/00964
d D 4.22 87/12/09 23:37:39 donn 22 21
c utah rcsid 1.18 87/07/13 21:17:28: Oops -- that sizeof hack broke 'int i;
c ... sizeof (i) ...'.  Hope this works a little better.
e
s 00009/00002/00957
d D 4.21 87/12/09 23:37:30 donn 21 20
c utah rcsid 1.17 87/07/10 22:45:50: A change to force lint (and cc?) to
c notice that initializations of auto, register or static variables count as
c uses of the variable.
e
s 00009/00003/00950
d D 4.20 87/12/09 23:37:20 donn 20 19
c utah rcsid 1.16 87/07/10 20:42:14: Slightly cleaner version of ado's hack
c for preventing 'sizeof' expressions from counting as a 'use' of a variable.
e
s 00004/00000/00949
d D 4.19 87/12/09 23:37:11 donn 19 18
c utah rcsid 1.15 87/07/06 18:36:00: Cause 'lint -h' to flag constant switch
c expressions.
e
s 00001/00001/00948
d D 4.18 87/12/09 23:37:03 donn 18 17
c utah rcsid 1.14 87/03/18 00:17:48: Fix stupid goof using the wrong union
c member in earlier fix for switches...
e
s 00001/00001/00948
d D 4.17 87/12/09 23:36:53 donn 17 16
c utah rcsid 1.13 87/02/26 18:53:50: Disallow case expressions which contain
c addresses, following K&R.
e
s 00001/00000/00948
d D 4.16 87/12/09 23:36:44 donn 16 15
c utah rcsid 1.12 87/01/15 05:51:41: Call fixinit() to recover from botched
c initializations.  fixinit() is used in the same situation as endinit()
c (from which it is derived).
e
s 00003/00003/00945
d D 4.15 87/12/09 23:36:34 donn 15 14
c utah rcsid 1.11 87/01/15 02:12:54: Some minor lint fixes.
e
s 00004/00003/00944
d D 4.14 87/12/09 23:36:24 donn 14 13
c utah rcsid 1.10 86/08/12 14:01:51: No more old-fashioned initializations.
c Since YACC doesn't have conditional ^&'compilation' directives, I just
c commented the rule out.
e
s 00004/00003/00943
d D 4.13 87/12/09 23:36:14 donn 13 12
c utah rcsid 1.9 86/08/10 17:38:47: Make '(&(a = b))->c' illegal (previously
c a synonym for '(a = b).c').  This and '(&(f())->c' now elicit the same
c error message that ordinary use of & on an rvalue elicits.
e
s 00002/00001/00944
d D 4.12 87/12/09 23:36:04 donn 12 11
c utah rcsid 1.8 86/08/10 16:49:55: Permit member references to the 'value'
c of a structure assignment.
e
s 00005/00004/00940
d D 4.11 87/12/09 23:35:53 donn 11 10
c utah rcsid 1.7 86/08/03 01:07:14: Don't emit stab information after errors.
e
s 00007/00000/00937
d D 4.10 87/12/09 23:35:43 donn 10 9
c utah rcsid 1.6 86/07/14 15:38:57: Close loophole with 'struct {int a, b;}
c f(); ... (&f())->b ...'.
e
s 00007/00024/00930
d D 4.9 87/12/09 23:35:33 donn 9 8
c utah rcsid 1.5 86/07/11 19:32:28: Permit member references to structures
c returned from functions.
e
s 00006/00000/00948
d D 4.8 87/05/01 08:48:17 bostic 8 7
c bug report 4.3BSD/lib/59
e
s 00011/00001/00937
d D 4.7 87/04/23 10:34:02 bostic 7 6
c bug report 4.3BSD/lib/55
e
s 00000/00004/00938
d D 4.6 87/04/22 15:12:42 bostic 6 5
c bug report 4.3BSD/usr.bin/51
e
s 00009/00000/00933
d D 4.5 87/04/22 15:11:27 bostic 5 4
c bug report 4.3BSD/usr.bin/51
e
s 00017/00003/00916
d D 4.4 85/08/22 19:02:46 mckusick 4 3
c update from donn@utah-cs
e
s 00007/00054/00912
d D 4.3 85/03/19 13:08:35 ralph 3 2
c use common header file for C, Fortran, Pascal.
e
s 00061/00080/00905
d D 4.2 85/01/18 16:13:10 ralph 2 1
c changes for single precision floats; lint cleanups
e
s 00985/00000/00000
d D 4.1 85/01/16 16:54:59 ralph 1 0
c date and time created 85/01/16 16:54:59 by ralph
e
u
U
t
T
I 1
D 2
%term NAME  2
%term STRING  3
%term ICON  4
%term FCON  5
%term PLUS   6
%term MINUS   8
%term MUL   11
%term AND   14
%term OR   17
%term ER   19
%term QUEST  21
%term COLON  22
%term ANDAND  23
%term OROR  24
E 2
I 2
D 3
%term NAME	2		/* identifier */
%term STRING	3		/* string constant, "..." */
%term ICON	4		/* integer constant */
%term FCON	5		/* single precision floating point constant */
%term DCON	6		/* double precision floating point constant */
/* 8 is used in the 2nd pass reader for BITYPE */
%term PLUS	9		/* + */
%term MINUS	11		/* - */
%term MUL	14		/* * */
%term AND	17		/* & */
%term OR	20		/* | */
%term ER	22		/* ^ */
%term QUEST	24		/* ? */
%term COLON	25		/* : */
%term ANDAND	26		/* && */
%term OROR	27		/* || */
E 3
I 3
/*	%M%	%I%	%E%	*/
E 3
E 2

D 2
/*	special interfaces for yacc alone */
/*	These serve as abbreviations of 2 or more ops:
	ASOP	=, = ops
	RELOP	LE,LT,GE,GT
	EQUOP	EQ,NE
	DIVOP	DIV,MOD
	SHIFTOP	LS,RS
	ICOP	ICR,DECR
	UNOP	NOT,COMPL
	STROP	DOT,STREF
E 2
I 2
D 3
%term ASOP	28		/* =, =ops */
%term RELOP	29		/* LE, LT, GE, GT */
%term EQUOP	30		/* EQ, NE */
%term DIVOP	31		/* DIV, MOD */
%term SHIFTOP	32		/* LS, RS */
%term INCOP	33		/* INCR, DECR */
%term UNOP	34		/* NOT, COMPL */
%term STROP	35		/* DOT, STREF */
E 3
I 3
/*
 * Grammar for the C compiler.
 *
D 4
 * This grammar requires definitions of terminals extracted from pcclocal.h.
E 4
I 4
 * This grammar requires the definitions of terminals in the file 'pcctokens'.
 * (YACC doesn't have an 'include' mechanism, unfortunately.)
E 4
 */
E 3
E 2

D 2
	*/
%term ASOP  25
%term RELOP  26
%term EQUOP  27
%term DIVOP  28
%term SHIFTOP  29
%term INCOP  30
%term UNOP  31
%term STROP  32
E 2
I 2
D 3
/* reserved words, etc */
%term TYPE	36		/* symbol type */
%term CLASS	37		/* storage type */
%term STRUCT	38		/* struct */
%term RETURN	39		/* return */
%term GOTO	40		/* goto */
%term IF	41		/* if */
%term ELSE	42		/* else */
%term SWITCH	43		/* switch */
%term BREAK	44		/* break */
%term CONTINUE	45		/* continue */
%term WHILE	46		/* while */
%term DO	47		/* do */
%term FOR	48		/* for */
%term DEFAULT	49		/* default */
%term CASE	50		/* case */
%term SIZEOF	51		/* sizeof */
%term ENUM	52		/* enum */
E 3
E 2

D 2
/*	reserved words, etc */
%term TYPE  33
%term CLASS  34
%term STRUCT  35
%term RETURN  36
%term GOTO  37
%term IF  38
%term ELSE  39
%term SWITCH  40
%term BREAK  41
%term CONTINUE  42
%term WHILE  43
%term DO  44
%term FOR  45
%term DEFAULT  46
%term CASE  47
%term SIZEOF  48
%term ENUM 49
E 2
I 2
D 3
/* little symbols, etc. */
%term LP	53		/* ( */
%term RP	54		/* ) */
%term LC	55		/* { */
%term RC	56		/* } */
%term LB	57		/* [ */
%term RB	58		/* ] */
%term CM	59		/* , */
%term SM	60		/* ; */
%term ASSIGN	61		/* = */
E 2

E 3
D 2

/*	little symbols, etc. */
/*	namely,

	LP	(
	RP	)

	LC	{
	RC	}

	LB	[
	RB	]

	CM	,
	SM	;

	*/

%term LP  50
%term RP  51
%term LC  52
%term RC  53
%term LB  54
%term RB  55
%term CM  56
%term SM  57
%term ASSIGN  58

E 2
/* at last count, there were 7 shift/reduce, 1 reduce/reduce conflicts
/* these involved:
	if/else
	recognizing functions in various contexts, including declarations
	error recovery
	*/

%left CM
%right ASOP ASSIGN
%right QUEST COLON
%left OROR
%left ANDAND
%left OR
%left ER
%left AND
%left EQUOP
%left RELOP
%left SHIFTOP
%left PLUS MINUS
%left MUL DIVOP
%right UNOP
%right INCOP SIZEOF
%left LB LP STROP
%{
D 3
# include "mfile1"
E 3
I 3
# include "pass1.h"
E 3
%}

	/* define types */
%start ext_def_list

%type <intval> con_e ifelprefix ifprefix whprefix forprefix doprefix switchpart
		enum_head str_head name_lp
%type <nodep> e .e term attributes oattributes type enum_dcl struct_dcl
		cast_type null_decl funct_idn declarator fdeclarator nfdeclarator
		elist

%token <intval> CLASS NAME STRUCT RELOP CM DIVOP PLUS MINUS SHIFTOP MUL AND OR ER ANDAND OROR
		ASSIGN STROP INCOP UNOP ICON
%token <nodep> TYPE

%%

%{
	static int fake = 0;
#ifndef FLEXNAMES
	static char fakename[NCHNAM+1];
#else
	static char fakename[24];
#endif
I 20
	static int nsizeof = 0;
E 20
%}

ext_def_list:	   ext_def_list external_def
		|
			=ftnend();
		;
external_def:	   data_def
			={ curclass = SNULL;  blevel = 0; }
		|  error
			={ curclass = SNULL;  blevel = 0; }
		;
data_def:
		   oattributes  SM
D 7
			={  $1->in.op = FREE; }
E 7
I 7
D 9
			={
			    if ($1->in.type != STRTY &&
				$1->in.type != UNIONTY &&
				$1->in.type != ENUMTY &&
				(curclass != SNULL ||
				$1->in.type != INT ||
				$1->fn.cdim != 0 ||
				$1->fn.csiz != INT))
					werror("null declaration");
			    $1->in.op = FREE;
			}
E 9
I 9
			={  $1->in.op = FREE; }
E 9
E 7
		|  oattributes init_dcl_list  SM
			={  $1->in.op = FREE; }
		|  oattributes fdeclarator {
				defid( tymerge($1,$2), curclass==STATIC?STATIC:EXTDEF );
#ifndef LINT
D 11
				pfstab(stab[$2->tn.rval].sname);
E 11
I 11
				if( nerrors == 0 )
					pfstab(stab[$2->tn.rval].sname);
E 11
#endif
				}  function_body
			={  
			    if( blevel ) cerror( "function level error" );
			    if( reached ) retstat |= NRETVAL; 
			    $1->in.op = FREE;
			    ftnend();
			    }
		;

function_body:	   arg_dcl_list compoundstmt
		;
arg_dcl_list:	   arg_dcl_list declaration
		| 	={  blevel = 1; }
		;

stmt_list:	   stmt_list statement
		|  /* empty */
			={  bccode();
D 15
			    locctr(PROG);
E 15
I 15
			    (void) locctr(PROG);
E 15
			    }
		;

r_dcl_stat_list	:  dcl_stat_list attributes SM
			={  $2->in.op = FREE; 
#ifndef LINT
D 11
			    plcstab(blevel);
E 11
I 11
			    if( nerrors == 0 ) plcstab(blevel);
E 11
#endif
			    }
		|  dcl_stat_list attributes init_dcl_list SM
			={  $2->in.op = FREE; 
#ifndef LINT
D 11
			    plcstab(blevel);
E 11
I 11
			    if( nerrors == 0 ) plcstab(blevel);
E 11
#endif
			    }
		;

dcl_stat_list	:  dcl_stat_list attributes SM
			={  $2->in.op = FREE; }
		|  dcl_stat_list attributes init_dcl_list SM
			={  $2->in.op = FREE; }
		|  /* empty */
		;
declaration:	   attributes declarator_list  SM
			={ curclass = SNULL;  $1->in.op = FREE; }
		|  attributes SM
			={ curclass = SNULL;  $1->in.op = FREE; }
		|  error  SM
			={  curclass = SNULL; }
		;
oattributes:	  attributes
		|  /* VOID */
			={  $$ = mkty(INT,0,INT);  curclass = SNULL; }
		;
attributes:	   class type
			={  $$ = $2; }
		|  type class
		|  class
			={  $$ = mkty(INT,0,INT); }
		|  type
			={ curclass = SNULL ; }
		|  type class type
			={  $1->in.type = types( $1->in.type, $3->in.type, UNDEF );
			    $3->in.op = FREE;
			    }
		;


class:		  CLASS
			={  curclass = $1; }
		;

type:		   TYPE
		|  TYPE TYPE
			={  $1->in.type = types( $1->in.type, $2->in.type, UNDEF );
			    $2->in.op = FREE;
			    }
		|  TYPE TYPE TYPE
			={  $1->in.type = types( $1->in.type, $2->in.type, $3->in.type );
			    $2->in.op = $3->in.op = FREE;
			    }
		|  struct_dcl
		|  enum_dcl
		;

enum_dcl:	   enum_head LC moe_list optcomma RC
			={ $$ = dclstruct($1); }
		|  ENUM NAME
			={  $$ = rstruct($2,0);  stwart = instruct; }
		;

enum_head:	   ENUM
			={  $$ = bstruct(-1,0); stwart = SEENAME; }
		|  ENUM NAME
			={  $$ = bstruct($2,0); stwart = SEENAME; }
		;

moe_list:	   moe
		|  moe_list CM moe
		;

moe:		   NAME
			={  moedef( $1 ); }
		|  NAME ASSIGN con_e
			={  strucoff = $3;  moedef( $1 ); }
		;

struct_dcl:	   str_head LC type_dcl_list optsemi RC
			={ $$ = dclstruct($1);  }
		|  STRUCT NAME
			={  $$ = rstruct($2,$1); }
		;

str_head:	   STRUCT
			={  $$ = bstruct(-1,$1);  stwart=0; }
		|  STRUCT NAME
			={  $$ = bstruct($2,$1);  stwart=0;  }
		;

type_dcl_list:	   type_declaration
		|  type_dcl_list SM type_declaration
		;

type_declaration:  type declarator_list
			={ curclass = SNULL;  stwart=0; $1->in.op = FREE; }
		|  type
			={  if( curclass != MOU ){
				curclass = SNULL;
				}
			    else {
				sprintf( fakename, "$%dFAKE", fake++ );
#ifdef FLEXNAMES
				/* No need to hash this, we won't look it up */
				defid( tymerge($1, bdty(NAME,NIL,lookup( savestr(fakename), SMOS ))), curclass );
#else
				defid( tymerge($1, bdty(NAME,NIL,lookup( fakename, SMOS ))), curclass );
#endif
				werror("structure typed union member must be named");
				}
			    stwart = 0;
			    $1->in.op = FREE;
			    }
		;


declarator_list:   declarator
			={ defid( tymerge($<nodep>0,$1), curclass);  stwart = instruct; }
		|  declarator_list  CM {$<nodep>$=$<nodep>0;}  declarator
			={ defid( tymerge($<nodep>0,$4), curclass);  stwart = instruct; }
		;
declarator:	   fdeclarator
		|  nfdeclarator
		|  nfdeclarator COLON con_e
			%prec CM
			={  if( !(instruct&INSTRUCT) ) uerror( "field outside of structure" );
			    if( $3<0 || $3 >= FIELD ){
				uerror( "illegal field size" );
				$3 = 1;
				}
			    defid( tymerge($<nodep>0,$1), FIELD|$3 );
			    $$ = NIL;
			    }
		|  COLON con_e
			%prec CM
			={  if( !(instruct&INSTRUCT) ) uerror( "field outside of structure" );
D 15
			    falloc( stab, $2, -1, $<nodep>0 );  /* alignment or hole */
E 15
I 15
			    (void) falloc( stab, $2, -1, $<nodep>0 );  /* alignment or hole */
E 15
			    $$ = NIL;
			    }
		|  error
			={  $$ = NIL; }
		;

		/* int (a)();   is not a function --- sorry! */
nfdeclarator:	   MUL nfdeclarator		
			={  umul:
				$$ = bdty( UNARY MUL, $2, 0 ); }
		|  nfdeclarator  LP   RP		
			={  uftn:
				$$ = bdty( UNARY CALL, $1, 0 );  }
		|  nfdeclarator LB RB		
			={  uary:
				$$ = bdty( LB, $1, 0 );  }
		|  nfdeclarator LB con_e RB	
			={  bary:
				if( (int)$3 <= 0 ) werror( "zero or negative subscript" );
				$$ = bdty( LB, $1, $3 );  }
		|  NAME  		
			={  $$ = bdty( NAME, NIL, $1 );  }
		|   LP  nfdeclarator  RP 		
			={ $$=$2; }
		;
fdeclarator:	   MUL fdeclarator
			={  goto umul; }
		|  fdeclarator  LP   RP
			={  goto uftn; }
		|  fdeclarator LB RB
			={  goto uary; }
		|  fdeclarator LB con_e RB
			={  goto bary; }
		|   LP  fdeclarator  RP
			={ $$ = $2; }
		|  name_lp  name_list  RP
			={
				if( blevel!=0 ) uerror("function declaration in bad context");
				$$ = bdty( UNARY CALL, bdty(NAME,NIL,$1), 0 );
				stwart = 0;
				}
		|  name_lp RP
			={
				$$ = bdty( UNARY CALL, bdty(NAME,NIL,$1), 0 );
				stwart = 0;
				}
		;

name_lp:	  NAME LP
			={
				/* turn off typedefs for argument names */
				stwart = SEENAME;
				if( stab[$1].sclass == SNULL )
				    stab[$1].stype = FTN;
				}
		;

name_list:	   NAME			
			={ ftnarg( $1 );  stwart = SEENAME; }
		|  name_list  CM  NAME 
			={ ftnarg( $3 );  stwart = SEENAME; }
		| error
		;
		/* always preceeded by attributes: thus the $<nodep>0's */
init_dcl_list:	   init_declarator
			%prec CM
		|  init_dcl_list  CM {$<nodep>$=$<nodep>0;}  init_declarator
		;
		/* always preceeded by attributes */
xnfdeclarator:	   nfdeclarator
D 21
			={  defid( $1 = tymerge($<nodep>0,$1), curclass);
			    beginit($1->tn.rval);
E 21
I 21
			={  int id;

			    defid( $1 = tymerge($<nodep>0,$1), curclass);
			    id = $1->tn.rval;
			    beginit(id);
			    if( stab[id].sclass == AUTO ||
				stab[id].sclass == REGISTER ||
				stab[id].sclass == STATIC )
				stab[id].suse = -lineno;
E 21
			    }
		|  error
		;
		/* always preceeded by attributes */
init_declarator:   nfdeclarator
			={  nidcl( tymerge($<nodep>0,$1) ); }
		|  fdeclarator
			={  defid( tymerge($<nodep>0,$1), uclass(curclass) );
I 2
			    if( paramno > 0 ){
				uerror( "illegal argument" );
				paramno = 0;
				}
E 2
			}
		|  xnfdeclarator optasgn e
			%prec CM
			={  doinit( $3 );
			    endinit(); }
		|  xnfdeclarator optasgn LC init_list optcomma RC
			={  endinit(); }
		| error
I 16
			={  fixinit(); }
E 16
		;

init_list:	   initializer
			%prec CM
		|  init_list  CM  initializer
		;
initializer:	   e
			%prec CM
			={  doinit( $1 ); }
		|  ibrace init_list optcomma RC
			={  irbrace(); }
		;

optcomma	:	/* VOID */
		|  CM
		;

optsemi		:	/* VOID */
		|  SM
		;

D 14
optasgn		:	/* VOID */
			={  werror( "old-fashioned initialization: use =" ); }
		|  ASSIGN
E 14
I 14
optasgn		:	/* uncomment for old-fashioned initializations */
			/* /* VOID */
			/* ={  werror( "old-fashioned initialization: use =" ); }
		/* | */  ASSIGN
E 14
		;

ibrace		: LC
			={  ilbrace(); }
		;

/*	STATEMENTS	*/

compoundstmt:	   dcmpstmt
		|  cmpstmt
		;

dcmpstmt:	   begin r_dcl_stat_list stmt_list RC
			={  
#ifndef LINT
D 11
			    prcstab(blevel);
E 11
I 11
			    if( nerrors == 0 ) prcstab(blevel);
E 11
#endif
			    --blevel;
			    if( blevel == 1 ) blevel = 0;
			    clearst( blevel );
			    checkst( blevel );
			    autooff = *--psavbc;
			    regvar = *--psavbc;
			    }
		;

cmpstmt:	   begin stmt_list RC
			={  --blevel;
			    if( blevel == 1 ) blevel = 0;
			    clearst( blevel );
			    checkst( blevel );
			    autooff = *--psavbc;
			    regvar = *--psavbc;
			    }
		;

begin:		  LC
			={  if( blevel == 1 ) dclargs();
			    ++blevel;
			    if( psavbc > &asavbc[BCSZ-2] ) cerror( "nesting too deep" );
			    *psavbc++ = regvar;
			    *psavbc++ = autooff;
			    }
		;

statement:	   e   SM
			={ ecomp( $1 ); }
		|  compoundstmt
		|  ifprefix statement
			={ deflab($1);
			   reached = 1;
			   }
		|  ifelprefix statement
			={  if( $1 != NOLAB ){
				deflab( $1 );
				reached = 1;
				}
			    }
		|  whprefix statement
			={  branch(  contlab );
			    deflab( brklab );
			    if( (flostat&FBRK) || !(flostat&FLOOP)) reached = 1;
			    else reached = 0;
			    resetbc(0);
			    }
		|  doprefix statement WHILE  LP  e  RP   SM
			={  deflab( contlab );
			    if( flostat & FCONT ) reached = 1;
			    ecomp( buildtree( CBRANCH, buildtree( NOT, $5, NIL ), bcon( $1 ) ) );
			    deflab( brklab );
			    reached = 1;
			    resetbc(0);
			    }
		|  forprefix .e RP statement
			={  deflab( contlab );
			    if( flostat&FCONT ) reached = 1;
			    if( $2 ) ecomp( $2 );
			    branch( $1 );
			    deflab( brklab );
			    if( (flostat&FBRK) || !(flostat&FLOOP) ) reached = 1;
			    else reached = 0;
			    resetbc(0);
			    }
		| switchpart statement
			={  if( reached ) branch( brklab );
			    deflab( $1 );
			   swend();
			    deflab(brklab);
			    if( (flostat&FBRK) || !(flostat&FDEF) ) reached = 1;
			    resetbc(FCONT);
			    }
		|  BREAK  SM
			={  if( brklab == NOLAB ) uerror( "illegal break");
			    else if(reached) branch( brklab );
			    flostat |= FBRK;
			    if( brkflag ) goto rch;
			    reached = 0;
			    }
		|  CONTINUE  SM
			={  if( contlab == NOLAB ) uerror( "illegal continue");
			    else branch( contlab );
			    flostat |= FCONT;
			    goto rch;
			    }
		|  RETURN  SM
			={  retstat |= NRETVAL;
			    branch( retlab );
			rch:
			    if( !reached ) werror( "statement not reached");
			    reached = 0;
			    }
		|  RETURN e  SM
			={  register NODE *temp;
			    idname = curftn;
			    temp = buildtree( NAME, NIL, NIL );
			    if(temp->in.type == TVOID)
				uerror("void function %s cannot return value",
					stab[idname].sname);
			    temp->in.type = DECREF( temp->in.type );
			    temp = buildtree( RETURN, temp, $2 );
			    /* now, we have the type of the RHS correct */
			    temp->in.left->in.op = FREE;
			    temp->in.op = FREE;
			    ecomp( buildtree( FORCE, temp->in.right, NIL ) );
			    retstat |= RETVAL;
			    branch( retlab );
			    reached = 0;
			    }
		|  GOTO NAME SM
			={  register NODE *q;
			    q = block( FREE, NIL, NIL, INT|ARY, 0, INT );
			    q->tn.rval = idname = $2;
			    defid( q, ULABEL );
			    stab[idname].suse = -lineno;
			    branch( stab[idname].offset );
			    goto rch;
			    }
		|   SM
		|  error  SM
		|  error RC
		|  label statement
		;
label:		   NAME COLON
			={  register NODE *q;
			    q = block( FREE, NIL, NIL, INT|ARY, 0, LABEL );
			    q->tn.rval = $1;
			    defid( q, LABEL );
			    reached = 1;
			    }
		|  CASE e COLON
			={  addcase($2);
			    reached = 1;
			    }
		|  DEFAULT COLON
			={  reached = 1;
			    adddef();
			    flostat |= FDEF;
			    }
		;
doprefix:	DO
			={  savebc();
			    if( !reached ) werror( "loop not entered at top");
			    brklab = getlab();
			    contlab = getlab();
			    deflab( $$ = getlab() );
			    reached = 1;
			    }
		;
ifprefix:	IF LP e RP
			={  ecomp( buildtree( CBRANCH, $3, bcon( $$=getlab()) ) ) ;
			    reached = 1;
			    }
		;
ifelprefix:	  ifprefix statement ELSE
			={  if( reached ) branch( $$ = getlab() );
			    else $$ = NOLAB;
			    deflab( $1 );
			    reached = 1;
			    }
		;

whprefix:	  WHILE  LP  e  RP
			={  savebc();
			    if( !reached ) werror( "loop not entered at top");
			    if( $3->in.op == ICON && $3->tn.lval != 0 ) flostat = FLOOP;
			    deflab( contlab = getlab() );
			    reached = 1;
			    brklab = getlab();
			    if( flostat == FLOOP ) tfree( $3 );
			    else ecomp( buildtree( CBRANCH, $3, bcon( brklab) ) );
			    }
		;
forprefix:	  FOR  LP  .e  SM .e  SM 
			={  if( $3 ) ecomp( $3 );
			    else if( !reached ) werror( "loop not entered at top");
			    savebc();
			    contlab = getlab();
			    brklab = getlab();
			    deflab( $$ = getlab() );
			    reached = 1;
			    if( $5 ) ecomp( buildtree( CBRANCH, $5, bcon( brklab) ) );
			    else flostat |= FLOOP;
			    }
		;
switchpart:	   SWITCH  LP  e  RP
D 4
			={  savebc();
E 4
I 4
			={  register NODE *q;
			
			    savebc();
E 4
			    brklab = getlab();
D 4
			    ecomp( buildtree( FORCE, $3, NIL ) );
E 4
I 4
			    q = $3;
			    switch( q->in.type ) {
			    case CHAR:	case UCHAR:
			    case SHORT:	case USHORT:
			    case INT:	case UNSIGNED:
			    case MOE:	case ENUMTY:
				    break;
I 8
D 9
			    case FLOAT:	case DOUBLE:
				    if (pflag)
					werror("switch (double) muffed by 4.[12]bsd");
				    /*FALLTHROUGH*/
E 9
E 8
			    default:
				werror("switch expression not type int");
				q = makety( q, INT, q->fn.cdim, q->fn.csiz );
				}
I 19
#ifdef LINT
			    if( hflag && q->in.op == ICON )
				werror( "constant switch expression" );
#endif
E 19
I 8
D 9
			    if (hflag && q->in.op == ICON)
				werror( "constant in switch" );
E 9
E 8
			    ecomp( buildtree( FORCE, q, NIL ) );
E 4
			    branch( $$ = getlab() );
			    swstart();
			    reached = 0;
			    }
		;
/*	EXPRESSIONS	*/
con_e:		   { $<intval>$=instruct; stwart=instruct=0; } e
			%prec CM
			={  $$ = icons( $2 );  instruct=$<intval>1; }
		;
.e:		   e
		|
			={ $$=0; }
		;
elist:		   e
			%prec CM
		|  elist  CM  e
			={  goto bop; }
		;

e:		   e RELOP e
			={
			preconf:
			    if( yychar==RELOP||yychar==EQUOP||yychar==AND||yychar==OR||yychar==ER ){
			    precplaint:
				if( hflag ) werror( "precedence confusion possible: parenthesize!" );
				}
			bop:
			    $$ = buildtree( $2, $1, $3 );
			    }
		|  e CM e
			={  $2 = COMOP;
			    goto bop;
			    }
		|  e DIVOP e
			={  goto bop; }
		|  e PLUS e
			={  if(yychar==SHIFTOP) goto precplaint; else goto bop; }
		|  e MINUS e
			={  if(yychar==SHIFTOP ) goto precplaint; else goto bop; }
		|  e SHIFTOP e
			={  if(yychar==PLUS||yychar==MINUS) goto precplaint; else goto bop; }
		|  e MUL e
			={  goto bop; }
		|  e EQUOP  e
			={  goto preconf; }
		|  e AND e
			={  if( yychar==RELOP||yychar==EQUOP ) goto preconf;  else goto bop; }
		|  e OR e
			={  if(yychar==RELOP||yychar==EQUOP) goto preconf; else goto bop; }
		|  e ER e
			={  if(yychar==RELOP||yychar==EQUOP) goto preconf; else goto bop; }
		|  e ANDAND e
			={  goto bop; }
		|  e OROR e
			={  goto bop; }
		|  e MUL ASSIGN e
			={  abop:
				$$ = buildtree( ASG $2, $1, $4 );
				}
		|  e DIVOP ASSIGN e
			={  goto abop; }
		|  e PLUS ASSIGN e
			={  goto abop; }
		|  e MINUS ASSIGN e
			={  goto abop; }
		|  e SHIFTOP ASSIGN e
			={  goto abop; }
		|  e AND ASSIGN e
			={  goto abop; }
		|  e OR ASSIGN e
			={  goto abop; }
		|  e ER ASSIGN e
			={  goto abop; }
		|  e QUEST e COLON e
			={  $$=buildtree(QUEST, $1, buildtree( COLON, $3, $5 ) );
			    }
		|  e ASOP e
			={  werror( "old-fashioned assignment operator" );  goto bop; }
		|  e ASSIGN e
			={  goto bop; }
		|  term
		;
term:		   term INCOP
			={  $$ = buildtree( $2, $1, bcon(1) ); }
		|  MUL term
			={ ubop:
			    $$ = buildtree( UNARY $1, $2, NIL );
			    }
		|  AND term
			={  if( ISFTN($2->in.type) || ISARY($2->in.type) ){
				werror( "& before array or function: ignored" );
				$$ = $2;
				}
I 10
			    else if( $2->in.op == UNARY MUL &&
D 13
				     ($2->in.left->in.op == STCALL ||
E 13
I 13
				     ($2->in.left->in.op == STASG ||
				      $2->in.left->in.op == STCALL ||
E 13
				      $2->in.left->in.op == UNARY STCALL) ){
D 13
				/* a legal tree but not available to users */
				uerror( "can't take address of function return value" );
E 13
I 13
				/* legal trees but not available to users */
				uerror( "unacceptable operand of &" );
E 13
				goto ubop;
				}
E 10
			    else goto ubop;
			    }
		|  MINUS term
			={  goto ubop; }
		|  UNOP term
			={
			    $$ = buildtree( $1, $2, NIL );
			    }
		|  INCOP term
			={  $$ = buildtree( $1==INCR ? ASG PLUS : ASG MINUS,
						$2,
						bcon(1)  );
			    }
D 20
		|  SIZEOF term
			={  $$ = doszof( $2 ); }
E 20
I 20
		|  pushsizeof term  %prec SIZEOF
			={  $$ = doszof( $2 ); --nsizeof; }
E 20
		|  LP cast_type RP term  %prec INCOP
			={  $$ = buildtree( CAST, $2, $4 );
			    $$->in.left->in.op = FREE;
			    $$->in.op = FREE;
			    $$ = $$->in.right;
			    }
D 22
		|  SIZEOF LP cast_type RP  %prec SIZEOF
			={  $$ = doszof( $3 ); }
E 22
I 22
		|  pushsizeof LP cast_type RP  %prec SIZEOF
			={  $$ = doszof( $3 ); --nsizeof; }
E 22
		|  term LB e RB
			={  $$ = buildtree( UNARY MUL, buildtree( PLUS, $1, $3 ), NIL ); }
		|  funct_idn  RP
			={  $$=buildtree(UNARY CALL,$1,NIL); }
		|  funct_idn elist  RP
			={  $$=buildtree(CALL,$1,$2); }
		|  term STROP NAME
			={  if( $2 == DOT ){
D 9
				if( notlval( $1 ) )uerror("structure reference must be addressable");
E 9
I 9
				if( notlval( $1 ) &&
				    !($1->in.op == UNARY MUL &&
D 12
				      ($1->in.left->in.op == STCALL ||
E 12
I 12
				      ($1->in.left->in.op == STASG ||
				       $1->in.left->in.op == STCALL ||
E 12
				       $1->in.left->in.op == UNARY STCALL)) )
				    uerror("structure reference must be addressable");
E 9
				$1 = buildtree( UNARY AND, $1, NIL );
				}
			    idname = $3;
			    $$ = buildtree( STREF, $1, buildtree( NAME, NIL, NIL ) );
			    }
		|  NAME
			={  idname = $1;
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
			    $$=buildtree(NAME,NIL,NIL);
I 5
D 6
#ifdef ASWAS
E 5
			    stab[$1].suse = -lineno;
I 5
#else /* !ASWAS */
E 6
D 9
			    {
				extern int	nsizeof;

				if (nsizeof == 0)
					stab[$1].suse = -lineno;
			    }
E 9
I 9
D 20
			    stab[$1].suse = -lineno;
E 20
I 20
			    if( nsizeof == 0 )
				stab[$1].suse = -lineno;
E 20
E 9
D 6
#endif /* !ASWAS */
E 6
E 5
			}
		|  ICON
			={  $$=bcon(0);
			    $$->tn.lval = lastcon;
			    $$->tn.rval = NONAME;
			    if( $1 ) $$->fn.csiz = $$->in.type = ctype(LONG);
			    }
		|  FCON
			={  $$=buildtree(FCON,NIL,NIL);
D 2
			    $$->fpn.dval = dcon;
E 2
I 2
			    $$->fpn.fval = fcon;
			    }
		|  DCON
			={  $$=buildtree(DCON,NIL,NIL);
			    $$->dpn.dval = dcon;
E 2
			    }
		|  STRING
			={  $$ = getstr(); /* get string contents */ }
		|   LP  e  RP
			={ $$=$2; }
		;

cast_type:	  type null_decl
			={
			$$ = tymerge( $1, $2 );
			$$->in.op = NAME;
			$1->in.op = FREE;
			}
I 20
		;

pushsizeof:	  SIZEOF
			={ ++nsizeof; }
E 20
		;

null_decl:	   /* empty */
			={ $$ = bdty( NAME, NIL, -1 ); }
		|  LP RP
			={ $$ = bdty( UNARY CALL, bdty(NAME,NIL,-1),0); }
		|  LP null_decl RP LP RP
			={  $$ = bdty( UNARY CALL, $2, 0 ); }
		|  MUL null_decl
			={  goto umul; }
		|  null_decl LB RB
			={  goto uary; }
		|  null_decl LB con_e RB
			={  goto bary;  }
		|  LP null_decl RP
			={ $$ = $2; }
		;

funct_idn:	   NAME  LP 
			={  if( stab[$1].stype == UNDEF ){
				register NODE *q;
				q = block( FREE, NIL, NIL, FTN|INT, 0, INT );
				q->tn.rval = $1;
				defid( q, EXTERN );
				}
			    idname = $1;
			    $$=buildtree(NAME,NIL,NIL);
			    stab[idname].suse = -lineno;
			}
		|  term  LP 
		;
%%

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
D 17
	if( p->in.op != ICON ){
E 17
I 17
D 18
	if( p->in.op != ICON || p->in.rval != NONAME ){
E 18
I 18
	if( p->in.op != ICON || p->tn.rval != NONAME ){
E 18
E 17
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
D 15
			uerror( "duplicate case in switch, %d", tempi=p->sval );
E 15
I 15
			uerror( "duplicate case in switch, %d", p->sval );
E 15
			return;
			}
		}

	genswitch( swbeg-1, swp-swbeg );
	swp = swbeg-1;
	}
E 1
