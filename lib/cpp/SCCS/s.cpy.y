h14919
s 00001/00001/00082
d D 1.2 83/01/02 16:09:15 sam 2 1
c from sun
e
s 00083/00000/00000
d D 1.1 82/08/30 09:57:35 rrh 1 0
c date and time created 82/08/30 09:57:35 by rrh
e
u
U
t
T
I 1
/*
 * %Z%%M% %I% %G%
 */
%term number stop DEFINED
%term EQ NE LE GE LS RS
%term ANDAND OROR
%left ','
%right '='
%right '?' ':'
%left OROR
%left ANDAND
%left '|' '^'
%left '&'
%binary EQ NE
%binary '<' '>' LE GE
%left LS RS
%left '+' '-'
%left '*' '/' '%'
%right '!' '~' UMINUS
%left '(' '.'
%%
S:	e stop	={return($1);}


e:	  e '*' e
		={$$ = $1 * $3;}
	| e '/' e
		={$$ = $1 / $3;}
	| e '%' e
		={$$ = $1 % $3;}
	| e '+' e
		={$$ = $1 + $3;}
	| e '-' e
		={$$ = $1 - $3;}
	| e LS e
		={$$ = $1 << $3;}
	| e RS e
		={$$ = $1 >> $3;}
	| e '<' e
		={$$ = $1 < $3;}
	| e '>' e
		={$$ = $1 > $3;}
	| e LE e
		={$$ = $1 <= $3;}
	| e GE e
		={$$ = $1 >= $3;}
	| e EQ e
		={$$ = $1 == $3;}
	| e NE e
		={$$ = $1 != $3;}
	| e '&' e
		={$$ = $1 & $3;}
	| e '^' e
		={$$ = $1 ^ $3;}
	| e '|' e
		={$$ = $1 | $3;}
	| e ANDAND e
		={$$ = $1 && $3;}
	| e OROR e
		={$$ = $1 || $3;}
	| e '?' e ':' e
		={$$ = $1 ? $3 : $5;}
	| e ',' e
		={$$ = $3;}
	| term
		={$$ = $1;}
term:
	  '-' term %prec UMINUS
D 2
		={$$ = -$1;}
E 2
I 2
		={$$ = -$2;}
E 2
	| '!' term
		={$$ = !$2;}
	| '~' term
		={$$ = ~$2;}
	| '(' e ')'
		={$$ = $2;}
	| DEFINED '(' number ')'
		={$$= $3;}
	| DEFINED number
		={$$ = $2;}
	| number
		={$$= $1;}
%%
# include "yylex.c"
E 1
