h43315
s 00121/00091/00137
d D 2.1 85/07/23 11:20:34 jaap 2 1
c Edition 8 Version of pic (May 1985). 
c Local hacks from jaap.
e
s 00228/00000/00000
d D 1.1 85/07/19 13:59:22 jaap 1 0
c date and time created 85/07/19 13:59:22 by jaap
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
I 2
%Start A str def sc br thru sh
%e 1700
%k 120
%a 1800
%o 1500
%p 5000
%n 700
E 2

D 2
%Start A str comment def sc br
%e 1300
%k 100
%a 1400
%o 1200
%p 4000
%n 600

E 2
%{
#undef	input
#undef	unput
#include <stdio.h>
#include <ctype.h>
#include "pic.h"
#include "y.tab.h"

extern	float	atof();
extern	struct	symtab	symtab[];
D 2
extern	char	*filename;
extern	int	synerr;
E 2
I 2
extern	char	*filename, *copythru();
E 2

#define	CADD	cbuf[clen++]=yytext[0]; if(clen>=CBUFLEN-1) {yyerror("string too long", cbuf); BEGIN A;}
D 2
#define	CBUFLEN	150
E 2
I 2
#define	CBUFLEN	500
E 2
char	cbuf[CBUFLEN];
D 2
int	clen, cflag;
E 2
I 2
int	c, clen, cflag, delim;
int	ifsw	= 0;	/* 1 if if statement in progress */
E 2
%}

A	[a-zA-Z_]
B	[a-zA-Z0-9_]
D	[0-9]
WS	[ \t]

%%
	switch (yybgin-yysvec-1) {	/* witchcraft */
	case 0:
		BEGIN A;
		break;
	case sc:
		BEGIN A;
		return('}');
	case br:
		BEGIN A;
		return(']');
	}

<A>{WS}		;
<A>"\\"\n	;
<A>\n		{ return(ST); }
<A>";"		{ return(ST); }
<A>"}"		{ BEGIN sc; return(ST); }
<A>"]"		{ BEGIN br; return(ST); }

D 2
<A>^".".*	{ if (yytext[1] == 'P' && (yytext[2] == 'E' || yytext[2] == 'F')) {
E 2
I 2
<A>^".PS".*	{ if (curfile == infile) yyerror(".PS found inside .PS/.PE"); }
<A>^"."P[EF].*	{ if (curfile == infile) {
E 2
			yylval.i = yytext[2];
			return(EOF);
D 2
		  } else {
			yylval.p = tostring(yytext);
			return(TROFF);
E 2
		  }
		}
I 2
<A>^".".*	{ yylval.p = tostring(yytext); return(TROFF); }
E 2

<A>print	return(yylval.i = PRINT);
<A>box		return(yylval.i = BOX);
<A>circle	return(yylval.i = CIRCLE);
<A>arc		return(yylval.i = ARC);
<A>ellipse	return(yylval.i = ELLIPSE);
<A>arrow	return(yylval.i = ARROW);
<A>spline	return(yylval.i = SPLINE);
<A>line		return(yylval.i = LINE);
<A>move		return(yylval.i = MOVE);
<A>"[]"		return(yylval.i = BLOCK);
I 2
<A>reset	return(RESET);
<A>sprintf	return(SPRINTF);
E 2

<A>same		return(SAME);
<A>between	return(BETWEEN);
<A>and		return(AND);

<A>of		;
<A>the		;
<A>way		;

D 2
<A>".e"		{ yylval.i = EAST; return(CORNER); }
<A>".east"	{ yylval.i = EAST; return(CORNER); }
<A>".r"		{ yylval.i = EAST; return(CORNER); }
<A>".right"	{ yylval.i = EAST; return(CORNER); }
<A>".w"		{ yylval.i = WEST; return(CORNER); }
<A>".west"	{ yylval.i = WEST; return(CORNER); }
<A>".l"		{ yylval.i = WEST; return(CORNER); }
<A>".left"	{ yylval.i = WEST; return(CORNER); }
<A>".n"		{ yylval.i = NORTH; return(CORNER); }
<A>".north"	{ yylval.i = NORTH; return(CORNER); }
<A>".t"		{ yylval.i = NORTH; return(CORNER); }
<A>".top"	{ yylval.i = NORTH; return(CORNER); }
<A>".s"		{ yylval.i = SOUTH; return(CORNER); }
<A>".south"	{ yylval.i = SOUTH; return(CORNER); }
<A>".b"		{ yylval.i = SOUTH; return(CORNER); }
<A>".bot"	{ yylval.i = SOUTH; return(CORNER); }
<A>".bottom"	{ yylval.i = SOUTH; return(CORNER); }
<A>".c"		{ yylval.i = CENTER; return(CORNER); }
<A>".center"	{ yylval.i = CENTER; return(CORNER); }
<A>".start"	{ yylval.i = START; return(CORNER); }
<A>".end"	{ yylval.i = END; return(CORNER); }
E 2
I 2
<A>"."(e|east)		{ yylval.i = EAST; return(CORNER); }
<A>"."(r|right)		{ yylval.i = EAST; return(CORNER); }
<A>"."(w|west)		{ yylval.i = WEST; return(CORNER); }
<A>"."(l|left)		{ yylval.i = WEST; return(CORNER); }
<A>"."(n|north)		{ yylval.i = NORTH; return(CORNER); }
<A>"."(t|top)		{ yylval.i = NORTH; return(CORNER); }
<A>"."(s|south)		{ yylval.i = SOUTH; return(CORNER); }
<A>"."(b|bot|bottom)	{ yylval.i = SOUTH; return(CORNER); }
<A>"."(c|center)	{ yylval.i = CENTER; return(CORNER); }
<A>".start"		{ yylval.i = START; return(CORNER); }
<A>".end"		{ yylval.i = END; return(CORNER); }
E 2
<A>".ne"		{ yylval.i = NE; return(CORNER); }
D 2
<A>"."upper" "*right	{ yylval.i = NE; return(CORNER); }
E 2
<A>".se"		{ yylval.i = SE; return(CORNER); }
D 2
<A>"."lower" "*right	{ yylval.i = SE; return(CORNER); }
E 2
<A>".nw"		{ yylval.i = NW; return(CORNER); }
D 2
<A>"."upper" "*left	{ yylval.i = NW; return(CORNER); }
E 2
<A>".sw"		{ yylval.i = SW; return(CORNER); }
D 2
<A>"."lower" "*left	{ yylval.i = SW; return(CORNER); }
E 2

<A>top" "+of		{ yylval.i = NORTH; return(CORNER); }
<A>north" "+of		{ yylval.i = NORTH; return(CORNER); }
<A>bottom" "+of		{ yylval.i = SOUTH; return(CORNER); }
<A>south" "+of		{ yylval.i = SOUTH; return(CORNER); }
<A>left" "+of		{ yylval.i = WEST; return(CORNER); }
<A>west" "+of		{ yylval.i = WEST; return(CORNER); }
<A>right" "+of		{ yylval.i = EAST; return(CORNER); }
<A>east" "+of		{ yylval.i = EAST; return(CORNER); }
<A>center" "+of		{ yylval.i = CENTER; return(CORNER); }
<A>start" "+of		{ yylval.i = START; return(CORNER); }
<A>end" "+of		{ yylval.i = END; return(CORNER); }
D 2
<A>upper" "+right" "+of	{ yylval.i = NE; return(CORNER); }
<A>upper" "+left" "+of	{ yylval.i = NW; return(CORNER); }
<A>lower" "+right" "+of	{ yylval.i = SE; return(CORNER); }
<A>lower" "+left" "+of	{ yylval.i = SW; return(CORNER); }
E 2

D 2
<A>height	{ yylval.i = HEIGHT; return(ATTR); }
<A>ht		{ yylval.i = HEIGHT; return(ATTR); }
<A>wid		{ yylval.i = WIDTH; return(ATTR); }
<A>width	{ yylval.i = WIDTH; return(ATTR); }
<A>rad		{ yylval.i = RADIUS; return(ATTR); }
<A>radius	{ yylval.i = RADIUS; return(ATTR); }
<A>diam		{ yylval.i = DIAMETER; return(ATTR); }
<A>diameter	{ yylval.i = DIAMETER; return(ATTR); }
E 2
I 2
<A>height|ht	{ yylval.i = HEIGHT; return(ATTR); }
<A>width|wid	{ yylval.i = WIDTH; return(ATTR); }
<A>radius|rad	{ yylval.i = RADIUS; return(ATTR); }
<A>diameter|diam { yylval.i = DIAMETER; return(ATTR); }
E 2
<A>size		{ yylval.i = SIZE; return(ATTR); }
<A>left		{ yylval.i = LEFT; return(DIR); }
<A>right	{ yylval.i = RIGHT; return(DIR); }
<A>up		{ yylval.i = UP; return(DIR); }
<A>down		{ yylval.i = DOWN; return(DIR); }
<A>cw		{ yylval.i = CW; return(ATTR); }
<A>clockwise	{ yylval.i = CW; return(ATTR); }
<A>ccw		{ yylval.i = CCW; return(ATTR); }
D 2
<A>then		{ yylval.i = THEN; return(ATTR); }
<A>invis	{ yylval.i = INVIS; return(ATTR); }
<A>invisible	{ yylval.i = INVIS; return(ATTR); }
<A>dot		return(yylval.i = DOT);
<A>dotted	return(yylval.i = DOT);
<A>dash		return(yylval.i = DASH);
<A>dashed	return(yylval.i = DASH);
E 2
I 2
<A>invis(ible)?	{ yylval.i = INVIS; return(ATTR); }
<A>dot(ted)?	return(yylval.i = DOT);
<A>dash(ed)?	return(yylval.i = DASH);
E 2
<A>chop		return(yylval.i = CHOP);

D 2
<A>spread	return(yylval.i = SPREAD);
<A>fill		return(yylval.i = FILL);
<A>ljust	return(yylval.i = LJUST);
<A>rjust	return(yylval.i = RJUST);
<A>above	return(yylval.i = ABOVE);
<A>below	return(yylval.i = BELOW);
E 2
I 2
<A>spread	{ yylval.i = SPREAD; return TEXTATTR; }
<A>fill		{ yylval.i = FILL; return TEXTATTR; }
<A>ljust	{ yylval.i = LJUST; return TEXTATTR; }
<A>rjust	{ yylval.i = RJUST; return TEXTATTR; }
<A>above	{ yylval.i = ABOVE; return TEXTATTR; }
<A>below	{ yylval.i = BELOW; return TEXTATTR; }
<A>center	{ yylval.i = CENTER; return TEXTATTR; }
E 2

<A>"<-"		{ yylval.i = HEAD1; return(HEAD); }
<A>"->"		{ yylval.i = HEAD2; return(HEAD); }
<A>"<->"	{ yylval.i = HEAD12; return(HEAD); }

D 2
<A>".x"		return(yylval.i = DOTX);
<A>".y"		return(yylval.i = DOTY);
<A>".ht"	return(yylval.i = DOTHT);
<A>".height"	return(yylval.i = DOTHT);
<A>".wid"	return(yylval.i = DOTWID);
<A>".width"	return(yylval.i = DOTWID);
<A>".rad"	return(yylval.i = DOTRAD);
<A>".radius"	return(yylval.i = DOTRAD);
E 2
I 2
<A>".x"			return(yylval.i = DOTX);
<A>".y"			return(yylval.i = DOTY);
<A>"."(ht|height)	return(yylval.i = DOTHT);
<A>"."(wid|width)	return(yylval.i = DOTWID);
<A>"."(rad|radius)	return(yylval.i = DOTRAD);
E 2

<A>from		return(yylval.i = FROM);
<A>to		return(yylval.i = TO);
<A>at		return(yylval.i = AT);
<A>by		return(yylval.i = BY);
<A>with		return(yylval.i = WITH);
<A>last		return(yylval.i = LAST);

I 2
<A>log		return(LOG);
<A>exp		return(EXP);
<A>sin		return(SIN);
<A>cos		return(COS);
<A>atan2	return(ATAN2);
<A>sqrt		return(SQRT);
<A>rand		return(RAND);
<A>max		return(MAX);
<A>min		return(MIN);
<A>int		return(INT);

<A>"=="		return(EQ);
<A>">="		return(GE);
<A>"<="		return(LE);
<A>"!="		return(NEQ);
<A>">"		return(GT);
<A>"<"		return(LT);
<A>"&&"		return(ANDAND);
<A>"||"		return(OROR);
<A>"!"		return(NOT);	

E 2
<A>Here		return(yylval.i = HERE);
D 2
<A>define{WS}+	{ BEGIN def; }
<def>{A}{B}*	{ definition(yytext); BEGIN A; }
E 2

I 2
<A>for		return(FOR);
<A>^Endfor\n	{ endfor(); }
<A>do		{ yylval.p = delimstr("loop body"); return(DOSTR); }

<A>copy|include		return(COPY);
<A>(thru|through){WS}+	{ BEGIN thru; return(THRU); }
<thru>{A}{B}*|.		{ yylval.p = copythru(yytext); BEGIN A; return(DEFNAME); }
<A>until		return(UNTIL);

<A>if		{ ifsw = 1; return(IF); }
<A>then		{ if (!ifsw) { yylval.i = THEN; return(ATTR); }
		  yylval.p = delimstr("then part"); ifsw = 0;
		  return(THENSTR); }
<A>else		{ yylval.p = delimstr("else part"); return(ELSESTR); }

<A>sh{WS}+	{ BEGIN sh;
		  if ((delim = input()) == '{') delim = '}';	/* no nested {} */
		  shell_init(); }
<sh>{A}{B}*	{ struct symtab *p;
		  if (yytext[0] == delim) {
			shell_exec();
			BEGIN A;
		  } else {
			p = lookup(yytext, 0);
			if (p != NULL && p->s_type == DEFNAME) {
				c = input();
				unput(c);
				if (c == '(')
					dodef(p);
				else
					pbstr(p->s_val.p);
			} else
				shell_text(yytext);
		  }
		}
<sh>.|\n	{ if (yytext[0] == delim) {
			shell_exec();
			BEGIN A;
		  } else
			shell_text(yytext);
		}

<A>define{WS}+		{ BEGIN def; }
<def>{A}{B}*		{ definition(yytext); BEGIN A; }
<A>undef(ine)?{WS}+{A}{B}*	{ undefine(yytext); }

E 2
<A>first		{ yylval.i = 1; return(NTH); }
<A>{D}+(th|nd|rd|st)	{ yylval.i = atoi(yytext); return(NTH); }
D 2
<A>({D}+("."?){D}*|"."{D}+)i?	{ yylval.f = atof(yytext); return(NUMBER); }
E 2
I 2
<A>({D}+("."?){D}*|"."{D}+)((e|E)("+"|-)?{D}+)?i? {
		  	yylval.f = atof(yytext); return(NUMBER); }
E 2

D 2
<A>{A}{B}* {
		int c;
		struct symtab *p;
E 2
I 2
<A>{A}{B}* {	struct symtab *p;
E 2
		p = lookup(yytext);
		if (p != NULL && p->s_type == DEFNAME) {
			c = input();
			unput(c);
			if (c == '(')	/* it's name(...) */
				dodef(p);
			else {	/* no argument list */
				pbstr(p->s_val);
				dprintf("pushing back `%s'\n", p->s_val);
			}
		} else if (islower(yytext[0])) {
			yylval.p = tostring(yytext);
			return(VARNAME);
		} else {
			yylval.p = tostring(yytext);
			return(PLACENAME);
		}
	}

<A>\"		{ BEGIN str; clen=0; }
D 2

<A>#		{ BEGIN comment; }
<comment>\n	{ BEGIN A; return(ST); }
<comment>.	;

<A>.		{ yylval.i = yytext[0]; return(yytext[0]); }

<str>\"		{ BEGIN A; cbuf[clen]=0; yylval.p = tostring(cbuf); return(TEXT); }
E 2
I 2
<str>\"		{ cbuf[clen]=0; yylval.p = tostring(cbuf); BEGIN A; return(TEXT); }
E 2
<str>\n		{ yyerror("newline in string"); BEGIN A; return(ST); }
<str>"\\\""	{ cbuf[clen++]='"'; }
<str>"\\"t	{ cbuf[clen++]='\t'; }
<str>"\\\\"	{ cbuf[clen++]='\\'; }
<str>.		{ CADD; }
I 2

<A>#.*		;

<A>.		return(yylval.i = yytext[0]);
E 2

%%
E 1
