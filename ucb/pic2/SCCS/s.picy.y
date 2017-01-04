h31079
s 00006/00001/00308
d D 3.1 85/07/30 15:05:42 jaap 3 2
c Edition 8 Version of pic (July 1985). 
c Local hacks from jaap.
e
s 00175/00075/00134
d D 2.1 85/07/23 11:20:45 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00209/00000/00000
d D 1.1 85/07/19 13:59:25 jaap 1 0
c date and time created 85/07/19 13:59:25 by jaap
e
u
U
t
T
I 1
D 2
#ifndef lint
static char sccsid[] = "%W% (CWI) %E%";
#endif lint

E 2
%{
D 2
#include	<stdio.h>
#include	"pic.h"
E 2
I 2
#include <stdio.h>
#include "pic.h"
#include <math.h>
E 2
YYSTYPE	y;
%}

D 2
%token	<i>	BOX	1
%token	<i>	ARROW	2
%token	<i>	CIRCLE	3
%token	<i>	ARC	4
E 2
I 2
%token	<i>	BOX	1	/* DON'T CHANGE THESE! */
%token	<i>	LINE	2
%token	<i>	ARROW	3
%token	<i>	CIRCLE	4
E 2
%token	<i>	ELLIPSE	5
D 2
%token	<i>	LINE	6
%token	<i>	MOVE	7
%token	<i>	TEXT	8
%token	<i>	TROFF	9
%token	<i>	SPLINE	10
%token	<i>	BLOCK	11
E 2
I 2
%token	<i>	ARC	6
%token	<i>	SPLINE	7
%token	<i>	BLOCK	8
%token	<p>	TEXT	9
%token	<i>	TROFF	10
%token	<i>	MOVE	11
E 2
%token	<i>	BLOCKEND 12
D 2
%token	<i>	PRINT
E 2
%token	<i>	PLACE
D 2
%token	<i>	ATTR
%token	<i>	SPREAD FILL LJUST RJUST ABOVE BELOW
E 2
I 2
%token	<i>	PRINT RESET THRU UNTIL
%token	<o>	FOR IF COPY
%token	<p>	THENSTR ELSESTR DOSTR DEFNAME PLACENAME VARNAME SPRINTF
%token	<i>	ATTR TEXTATTR
E 2
%token	<i>	LEFT RIGHT UP DOWN FROM TO AT BY WITH HEAD CW CCW THEN
%token	<i>	HEIGHT WIDTH RADIUS DIAMETER LENGTH SIZE
D 2
%token	<i>	PLACENAME VARNAME DEFNAME CORNER HERE LAST NTH SAME BETWEEN AND
%token	<i>	EAST WEST NORTH SOUTH NE NW SE SW CENTER START END
E 2
I 2
%token	<i>	CORNER HERE LAST NTH SAME BETWEEN AND
%token	<i>	EAST WEST NORTH SOUTH NE NW SE SW START END
E 2
%token	<i>	DOTX DOTY DOTHT DOTWID DOTRAD
%token	<f>	NUMBER
I 2
%token	<f>	LOG EXP SIN COS ATAN2 SQRT RAND MIN MAX INT
E 2
%token	<i>	DIR
%token	<i>	DOT DASH CHOP
%token	<o>	ST	/* statement terminator */

I 2
%right	<f>	'='
%left	<f>	OROR
%left	<f>	ANDAND
%nonassoc <f>	GT LT LE GE EQ NEQ
E 2
%left	<f>	'+' '-'
%left	<f>	'*' '/' '%'
D 2
%right	<f>	UMINUS
E 2
I 2
%right	<f>	UMINUS NOT
E 2

D 2
%type	<f>	expr opt_expr
E 2
I 2
%type	<f>	expr if_expr asgn
%type	<p>	name text
%type	<i>	optop exprlist
%type	<o>	if for copy

/* this is a lie:  picture and position are really the whole union */
E 2
%type	<o>	leftbrace picture piclist position lbracket
%type	<o>	prim place blockname
D 2
%type	<i>	textattr last type
E 2
I 2
%type	<i>	textlist textattr	/* not a sensible value */
%type	<i>	last type
E 2

D 2

E 2
%%

top:
	  piclist
	| /* empty */
	| error		{ yyerror("syntax error"); }
	;

piclist:
	  picture
	| piclist picture
	;

picture:
D 2
	  prim ST			{ codegen = 1; }
E 2
I 2
	  prim ST			{ codegen = 1; makeiattr(0, 0); }
E 2
	| leftbrace piclist '}'		{ rightthing($1, '}'); $$ = $2; }
D 2
	| PLACENAME ':' picture		{ makevar($1, PLACENAME, $3); $$ = $3; }
	| PLACENAME ':' ST picture	{ makevar($1, PLACENAME, $4); $$ = $4; }
	| PLACENAME ':' position ST	{ makevar($1, PLACENAME, $3); $$ = $3; }
        | VARNAME '=' expr ST	{ makevar($1, VARNAME, $3); checkscale($1); }
E 2
I 2
	| PLACENAME ':' picture		{ y.o=$3; makevar($1,PLACENAME,y); $$ = $3; }
	| PLACENAME ':' ST picture	{ y.o=$4; makevar($1,PLACENAME,y); $$ = $4; }
	| PLACENAME ':' position ST	{ y.o=$3; makevar($1,PLACENAME,y); $$ = $3; }
	| asgn ST			{ y.f = $1; $$ = y.o; }
E 2
	| DIR				{ setdir($1); }
	| PRINT expr ST			{ printexpr($2); }
	| PRINT position ST		{ printpos($2); }
I 2
	| PRINT text ST			{ printf("%s\n", $2); free($2); }
	| RESET varlist ST		{ resetvar(); makeiattr(0, 0); }
	| copy
	| for
	| if
E 2
	| ST
	;

I 2
varlist:
	  /* empty */
	| VARNAME		{ makevattr($1); }
	| varlist VARNAME	{ makevattr($2); }
	| varlist ',' VARNAME	{ makevattr($3); }
	;

asgn:
	  VARNAME '=' expr	{ $$=y.f=$3; makevar($1,VARNAME,y); checkscale($1); }
	;

copy:
	  COPY copylist		{ copy(); }
	;
copylist:
	  copyattr
	| copylist copyattr
	;
copyattr:
	  text			{ copyfile($1); }
	| THRU DEFNAME		{ copydef($2); }
	| UNTIL text		{ copyuntil($2); }
	;

for:
	  FOR name FROM expr TO expr BY optop expr DOSTR
		{ forloop($2, $4, $6, $8, $9, $10); }
	| FOR name FROM expr TO expr DOSTR
		{ forloop($2, $4, $6, '+', 1.0, $7); }
	| FOR name '=' expr TO expr BY optop expr DOSTR
		{ forloop($2, $4, $6, $8, $9, $10); }
	| FOR name '=' expr TO expr DOSTR
		{ forloop($2, $4, $6, '+', 1.0, $7); }
	;

if:
	  IF if_expr THENSTR ELSESTR	{ ifstat($2, $3, $4); }
	| IF if_expr THENSTR		{ ifstat($2, $3, (char *) 0); }
	;
if_expr:
	  expr
	| text EQ text		{ $$ = strcmp($1,$3) == 0; free($1); free($3); }
	| text NEQ text		{ $$ = strcmp($1,$3) != 0; free($1); free($3); }
	;

name:
	  VARNAME	{ y.f = 0; makevar($1, VARNAME, y); }
	;
optop:
	  '+'		{ $$ = '+'; }
	| '-'		{ $$ = '-'; }
	| '*'		{ $$ = '*'; }
	| '/'		{ $$ = '/'; }
	| /* empty */	{ $$ = ' '; }
	;


E 2
leftbrace:
	  '{'			{ $$ = leftthing('{'); }
	;

prim:
	  BOX attrlist		{ $$ = boxgen($1); }
	| CIRCLE attrlist	{ $$ = circgen($1); }
	| ELLIPSE attrlist	{ $$ = circgen($1); }
	| ARC attrlist		{ $$ = arcgen($1); }
	| LINE attrlist		{ $$ = linegen($1); }
	| ARROW attrlist	{ $$ = linegen($1); }
D 2
	| SPLINE attrlist	{ $$ = splinegen($1); }
E 2
I 2
	| SPLINE attrlist	{ $$ = linegen($1); }
E 2
	| MOVE attrlist		{ $$ = movegen($1); }
D 2
	| TEXT attrlist		{ $$ = textgen($1); }
E 2
I 2
	| textlist attrlist	{ $$ = textgen($1); }
E 2
	| TROFF			{ $$ = troffgen($1); }
	| lbracket piclist ']' { $<o>$=rightthing($1,']'); } attrlist
				{ $$ = blockgen($1, $2, $<o>4); }
	;

lbracket:
	  '['			{ $$ = leftthing('['); }
	;

attrlist:
	  attrlist attr
D 2
	| /* empty */		{ makeattr(0, 0); }
E 2
I 2
	| /* empty */
E 2
	;

attr:
D 2
	  ATTR opt_expr		{ makeattr($1, $2); }
	| DIR opt_expr		{ makeattr($1, $2); }
	| FROM position		{ makeattr($1, $2); }
	| TO position		{ makeattr($1, $2); }
	| AT position		{ makeattr($1, $2); }
	| BY position		{ makeattr($1, $2); }
	| WITH CORNER		{ makeattr(WITH, $2); }
	| WITH '.' PLACENAME	{ makeattr(PLACE, getblock(getlast(1,BLOCK), $3)); }
	| WITH position		{ makeattr(PLACE, $2); }
	| SAME			{ makeattr(SAME, $1); }
	| textattr		{ makeattr($1, 0); }
	| HEAD			{ makeattr(HEAD, $1); }
	| DOT opt_expr		{ makeattr(DOT, $2); }
	| DASH opt_expr		{ makeattr(DASH, $2); }
	| CHOP opt_expr		{ makeattr(CHOP, $2); }
E 2
I 2
	  ATTR expr		{ makefattr($1, !DEFAULT, $2); }
	| ATTR			{ makefattr($1, DEFAULT, 0.0); }
	| expr			{ makefattr(curdir(), !DEFAULT, $1); }
	| DIR expr		{ makefattr($1, !DEFAULT, $2); }
	| DIR			{ makefattr($1, DEFAULT, 0.0); }
	| FROM position		{ makeoattr($1, $2); }
	| TO position		{ makeoattr($1, $2); }
	| AT position		{ makeoattr($1, $2); }
	| BY position		{ makeoattr($1, $2); }
	| WITH CORNER		{ makeiattr(WITH, $2); }
	| WITH '.' PLACENAME	{ makeoattr(PLACE, getblock(getlast(1,BLOCK), $3)); }
	| WITH '.' PLACENAME CORNER
		{ makeoattr(PLACE, getpos(getblock(getlast(1,BLOCK), $3), $4)); }
	| WITH position		{ makeoattr(PLACE, $2); }
	| SAME			{ makeiattr(SAME, $1); }
	| TEXTATTR		{ maketattr($1, 0); }
	| HEAD			{ makeiattr(HEAD, $1); }
	| DOT expr		{ makefattr(DOT, !DEFAULT, $2); }
	| DOT			{ makefattr(DOT, DEFAULT, 0.0); }
	| DASH expr		{ makefattr(DASH, !DEFAULT, $2); }
	| DASH			{ makefattr(DASH, DEFAULT, 0.0); }
	| CHOP expr		{ makefattr(CHOP, !DEFAULT, $2); }
	| CHOP			{ makefattr(CHOP, DEFAULT, 0.0); }
E 2
	| textlist
	;

D 2
opt_expr:
	  expr
	| /* empty */		{ $$ = 0; }
	;

E 2
textlist:
D 2
	  TEXT			{ makeattr(CENTER, $1); }
	| TEXT textattr		{ makeattr($2, $1); }
	| textlist TEXT		{ makeattr(CENTER, $2); }
	| textlist TEXT textattr { makeattr($3, $2); }
E 2
I 2
	  textattr
	| textlist textattr
E 2
	;
D 2

E 2
textattr:
D 2
	  LJUST
	| RJUST
	| SPREAD
	| FILL
	| CENTER
	| ABOVE
	| BELOW
E 2
I 2
	  text			{ maketattr(CENTER, $1); }
	| text TEXTATTR		{ maketattr($2, $1); }
	| textattr TEXTATTR	{ addtattr($2); }
E 2
	;
I 2
text:
	  TEXT
	| SPRINTF '(' text ')'			{ $$ = sprintgen($3); }
	| SPRINTF '(' text ',' exprlist ')'	{ $$ = sprintgen($3); }
	;
E 2

I 2
exprlist:
	  expr			{ exprsave($1); $$ = 0; }
	| exprlist ',' expr	{ exprsave($3); }
	;

E 2
position:		/* absolute, not relative */
	  place
D 2
	| expr ',' expr			{ $$ = makepos($1, $3); }
	| position '+' expr ',' expr	{ $$ = fixpos($1, $3, $5); }
	| position '-' expr ',' expr	{ $$ = fixpos($1, -$3, -$5); }
	| '(' expr ',' expr ')'			{ $$ = makepos($2, $4); }
E 2
I 2
	| '(' position ')'			{ $$ = $2; }
	| expr ',' expr				{ $$ = makepos($1, $3); }
	| position '+' expr ',' expr		{ $$ = fixpos($1, $3, $5); }
	| position '-' expr ',' expr		{ $$ = fixpos($1, -$3, -$5); }
E 2
	| position '+' '(' expr ',' expr ')'	{ $$ = fixpos($1, $4, $6); }
	| position '-' '(' expr ',' expr ')'	{ $$ = fixpos($1, -$4, -$6); }
I 3
	| position '+' place			{ $$ = addpos($1, $3); }
	| position '-' place			{ $$ = subpos($1, $3); }
E 3
	| '(' place ',' place ')'	{ $$ = makepos(getcomp($2,DOTX), getcomp($4,DOTY)); }
D 2
	| expr '<' position ',' position '>'	{ $$ = makebetween($1, $3, $5); }
E 2
I 2
	| expr LT position ',' position GT	{ $$ = makebetween($1, $3, $5); }
E 2
	| expr BETWEEN position AND position	{ $$ = makebetween($1, $3, $5); }
	;

place:
	  PLACENAME		{ y = getvar($1); $$ = y.o; }
	| PLACENAME CORNER	{ y = getvar($1); $$ = getpos(y.o, $2); }
	| CORNER PLACENAME	{ y = getvar($2); $$ = getpos(y.o, $1); }
	| HERE			{ $$ = gethere($1); }
	| last type		{ $$ = getlast($1, $2); }
	| last type CORNER	{ $$ = getpos(getlast($1, $2), $3); }
	| CORNER last type	{ $$ = getpos(getlast($2, $3), $1); }
	| NTH type		{ $$ = getfirst($1, $2); }
	| NTH type CORNER	{ $$ = getpos(getfirst($1, $2), $3); }
	| CORNER NTH type	{ $$ = getpos(getfirst($2, $3), $1); }
	| blockname
	| blockname CORNER	{ $$ = getpos($1, $2); }
	| CORNER blockname	{ $$ = getpos($2, $1); }
	;

blockname:
	  last BLOCK '.' PLACENAME	{ $$ = getblock(getlast($1,$2), $4); }
	| NTH BLOCK '.' PLACENAME	{ $$ = getblock(getfirst($1,$2), $4); }
	| PLACENAME '.' PLACENAME	{ y = getvar($1); $$ = getblock(y.o, $3); }
	;

last:
	  last LAST		{ $$ = $1 + 1; }
	| NTH LAST		{ $$ = $1; }
	| LAST			{ $$ = 1; }
	;

type:
	  BOX
	| CIRCLE
	| ELLIPSE
	| ARC
	| LINE
	| ARROW
	| SPLINE
	| BLOCK
	;

expr:
D 2
	  expr '+' expr		{ $$ = $1 + $3; }
E 2
I 2
	  NUMBER
	| VARNAME		{ $$ = getfval($1); }
	| asgn
	| expr '+' expr		{ $$ = $1 + $3; }
E 2
	| expr '-' expr		{ $$ = $1 - $3; }
	| expr '*' expr		{ $$ = $1 * $3; }
D 2
	| expr '/' expr		{ $$ = $1 / $3; }
	| expr '%' expr		{ $$ = (long)$1 % (long)$3; }
E 2
I 2
	| expr '/' expr		{ if ($3 == 0.0) {
					yyerror("division by 0"); $3 = 1; }
				  $$ = $1 / $3; }
	| expr '%' expr		{ if ((long)$3 == 0) {
D 3
					yyerror("mod does division by 0"); $3 = 1; }
E 3
I 3
					yyerror("mod division by 0"); $3 = 1; }
E 3
				  $$ = (long)$1 % (long)$3; }
E 2
	| '-' expr %prec UMINUS	{ $$ = -$2; }
	| '(' expr ')'		{ $$ = $2; }
D 2
	| VARNAME		{ $$ = getfval($1); }
	| NUMBER
E 2
	| place DOTX		{ $$ = getcomp($1, $2); }
	| place DOTY		{ $$ = getcomp($1, $2); }
	| place DOTHT		{ $$ = getcomp($1, $2); }
	| place DOTWID		{ $$ = getcomp($1, $2); }
	| place DOTRAD		{ $$ = getcomp($1, $2); }
I 3
	| PLACENAME '.' VARNAME	{ y = getvar($1); $$ = getblkvar(y.o, $3); }
	| last BLOCK '.' VARNAME { $$ = getblkvar(getlast($1,$2), $4); }
	| NTH BLOCK '.' VARNAME	{ $$ = getblkvar(getfirst($1,$2), $4); }
E 3
I 2
	| expr GT expr		{ $$ = $1 > $3; }
	| expr LT expr		{ $$ = $1 < $3; }
	| expr LE expr		{ $$ = $1 <= $3; }
	| expr GE expr		{ $$ = $1 >= $3; }
	| expr EQ expr		{ $$ = $1 == $3; }
	| expr NEQ expr		{ $$ = $1 != $3; }
	| expr ANDAND expr	{ $$ = $1 && $3; }
	| expr OROR expr	{ $$ = $1 || $3; }
	| NOT expr		{ $$ = !($2); }
	| LOG '(' expr ')'		{ $$ = Log10($3); }
	| EXP '(' expr ')'		{ $$ = Exp($3 * log(10.0)); }
	| SIN '(' expr ')'		{ $$ = sin($3); }
	| COS '(' expr ')'		{ $$ = cos($3); }
	| ATAN2 '(' expr ',' expr ')'	{ $$ = atan2($3, $5); }
	| SQRT '(' expr ')'		{ $$ = Sqrt($3); }
	| RAND '(' ')'			{ $$ = (float)rand() / 32767.0; /* might be 2^31-1 */ }
	| MAX '(' expr ',' expr ')'	{ $$ = $3 >= $5 ? $3 : $5; }
	| MIN '(' expr ',' expr ')'	{ $$ = $3 <= $5 ? $3 : $5; }
	| INT '(' expr ')'		{ $$ = (long) $3; }
E 2
	;
E 1
