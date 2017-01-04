# include "stdio.h"
# define U(x) x
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# define YYLMAX 200
# define output(c) putc(c,yyout)
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
# define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
int yyleng; extern char yytext[];
int yymorfg;
extern char *yysptr, yysbuf[];
int yytchar;
FILE *yyin ={stdin}, *yyout ={stdout};
extern int yylineno;
struct yysvf { 
	struct yywork *yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;

/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)config.l	5.6 (Berkeley) 3/2/04
 */

#include <ctype.h>
#include "y.tab.h"
#include "config.h"

#define tprintf if (do_trace) printf

/*
 * Key word table
 */

struct kt {
	char *kt_name;
	int kt_val;
} key_words[] = {
	{ "adapter",	CONTROLLER },
	{ "and",	AND },
	{ "args",	ARGS },
	{ "at",		AT },
	{ "config",	CONFIG },
	{ "controller",	CONTROLLER },
	{ "cpu",	CPU },
	{ "csr",	CSR },
	{ "device",	DEVICE },
	{ "disk",	DISK },
	{ "drive",	DRIVE },
	{ "dst",	DST },
	{ "dumps",	DUMPS },
	{ "flags",	FLAGS },
	{ "hz",		HZ },
	{ "ident",	IDENT },
	{ "machine",	MACHINE },
	{ "major",	MAJOR },
	{ "makeoptions", MAKEOPTIONS },
	{ "master",	MASTER },
	{ "maxusers",	MAXUSERS },
	{ "minor",	MINOR },
	{ "nexus",	NEXUS },
	{ "node",	NODE },
	{ "on",		ON },
	{ "options",	OPTIONS },
	{ "priority",	PRIORITY },
	{ "pseudo-device",PSEUDO_DEVICE },
	{ "root",	ROOT },
	{ "size",	SIZE },
	{ "slave",	SLAVE },
	{ "swap",	SWAP },
	{ "tape",	DEVICE },
	{ "timezone",	TIMEZONE },
	{ "trace",	TRACE },
	{ "vector",	VECTOR },
	{ 0, 0 },
};
# define YYNEWLINE 10
yylex(){
int nstr; extern int yyprevious;
while((nstr = yylook()) >= 0)
yyfussy: switch(nstr){
case 0:
if(yywrap()) return(0); break;
case 1:
	{
			int i;

			if ((i = kw_lookup(yytext)) == -1)
			{
				yylval.str = yytext;
				tprintf("id(%s) ", yytext);
				return ID;
			}
			tprintf("(%s) ", yytext);
			return i;
		}
break;
case 2:
{
			yytext[strlen(yytext)-1] = '\0';
			yylval.str = yytext + 1;
			return ID;
		}
break;
case 3:
	{
			yylval.val = octal(yytext);
			tprintf("#O:%o ", yylval.val);
			return NUMBER;
		}
break;
case 4:
{
			yylval.val = hex(yytext);
			tprintf("#X:%x ", yylval.val);
			return NUMBER;
		}
break;
case 5:
{
			yylval.val = atoi(yytext);
			tprintf("#D:%d ", yylval.val);
			return NUMBER;
		}
break;
case 6:
{
			double atof();
			yylval.val = (int) (60 * atof(yytext) + 0.5);
			return FPNUMBER;
		}
break;
case 7:
	{
			return MINUS;
		}
break;
case 8:
	{
			yylval.val = -1;
			tprintf("? ");
			return NUMBER;
		}
break;
case 9:
{
			yyline++;
			tprintf("\n... ");
		}
break;
case 10:
	{
			yyline++;
			tprintf("\n");
			return SEMICOLON;
		}
break;
case 11:
	{	/* Ignored (comment) */;	}
break;
case 12:
	{	/* Ignored (white space) */;	}
break;
case 13:
	{	return SEMICOLON;		}
break;
case 14:
	{	return COMMA;			}
break;
case 15:
	{	return EQUALS;			}
break;
case 16:
	{	return AT;			}
break;
case 17:
	{	return yytext[0];		}
break;
case -1:
break;
default:
fprintf(yyout,"bad switch yylook %d",nstr);
} return(0); }
/* end of yylex */
/*
 * kw_lookup
 *	Look up a string in the keyword table.  Returns a -1 if the
 *	string is not a keyword otherwise it returns the keyword number
 */

kw_lookup(word)
register char *word;
{
	register struct kt *kp;

	for (kp = key_words; kp->kt_name != 0; kp++)
		if (eq(word, kp->kt_name))
			return kp->kt_val;
	return -1;
}

/*
 * Number conversion routines
 */

octal(str)
char *str;
{
	int num;

	(void) sscanf(str, "%o", &num);
	return num;
}

hex(str)
char *str;
{
	int num;

	(void) sscanf(str+2, "%x", &num);
	return num;
}
int yyvstop[] ={
0,

12,
0,

12,
0,

17,
0,

12,
17,
0,

10,
-9,
0,

17,
0,

11,
17,
0,

14,
17,
0,

7,
17,
0,

3,
17,
0,

5,
17,
0,

13,
17,
0,

15,
17,
0,

8,
17,
0,

16,
17,
0,

1,
17,
0,

12,
0,

9,
0,

11,
0,

6,
0,

3,
0,

5,
0,

1,
0,

2,
0,

4,
0,
0};
# define YYTYPE char
struct yywork { YYTYPE verify, advance; } yycrank[] ={
0,0,	0,0,	1,3,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	1,4,	1,5,	
0,0,	0,0,	4,17,	5,18,	
0,0,	0,0,	20,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	6,19,	1,6,	
1,7,	4,17,	5,18,	0,0,	
0,0,	0,0,	6,19,	6,19,	
7,20,	1,8,	1,9,	2,7,	
19,26,	1,10,	1,11,	0,0,	
7,20,	7,0,	0,0,	0,0,	
2,8,	1,11,	0,0,	0,0,	
1,12,	0,0,	1,13,	0,0,	
1,14,	1,15,	1,16,	6,0,	
0,0,	0,0,	0,0,	2,12,	
1,16,	2,13,	0,0,	2,14,	
2,15,	7,20,	6,19,	0,0,	
0,0,	6,19,	6,19,	0,0,	
0,0,	0,0,	0,0,	0,0,	
7,20,	6,19,	0,0,	7,20,	
7,20,	0,0,	0,0,	0,0,	
0,0,	0,0,	6,19,	7,20,	
0,0,	0,0,	0,0,	0,0,	
6,19,	0,0,	0,0,	0,0,	
7,20,	0,0,	0,0,	0,0,	
0,0,	10,21,	7,20,	10,22,	
10,22,	10,22,	10,22,	10,22,	
10,22,	10,22,	10,22,	11,21,	
0,0,	11,24,	11,24,	11,24,	
11,24,	11,24,	11,24,	11,24,	
11,24,	11,24,	11,24,	0,0,	
16,25,	21,21,	21,21,	21,21,	
21,21,	21,21,	21,21,	21,21,	
21,21,	21,21,	21,21,	22,22,	
22,22,	22,22,	22,22,	22,22,	
22,22,	22,22,	22,22,	0,0,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	0,0,	0,0,	
0,0,	0,0,	16,25,	10,23,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	16,25,	16,25,	
16,25,	16,25,	23,27,	23,27,	
23,27,	23,27,	23,27,	23,27,	
23,27,	23,27,	23,27,	23,27,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	23,27,	
23,27,	23,27,	23,27,	23,27,	
23,27,	24,24,	24,24,	24,24,	
24,24,	24,24,	24,24,	24,24,	
24,24,	24,24,	24,24,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	23,27,	
23,27,	23,27,	23,27,	23,27,	
23,27,	0,0,	0,0,	0,0,	
0,0};
struct yysvf yysvec[] ={
0,	0,	0,
yycrank+-1,	0,		yyvstop+1,
yycrank+-12,	yysvec+1,	yyvstop+3,
yycrank+0,	0,		yyvstop+5,
yycrank+5,	0,		yyvstop+7,
yycrank+6,	0,		yyvstop+10,
yycrank+-33,	0,		yyvstop+13,
yycrank+-43,	0,		yyvstop+15,
yycrank+0,	0,		yyvstop+18,
yycrank+0,	0,		yyvstop+21,
yycrank+67,	0,		yyvstop+24,
yycrank+77,	0,		yyvstop+27,
yycrank+0,	0,		yyvstop+30,
yycrank+0,	0,		yyvstop+33,
yycrank+0,	0,		yyvstop+36,
yycrank+0,	0,		yyvstop+39,
yycrank+91,	0,		yyvstop+42,
yycrank+0,	yysvec+4,	yyvstop+45,
yycrank+0,	0,		yyvstop+47,
yycrank+-14,	yysvec+6,	0,	
yycrank+-8,	yysvec+7,	yyvstop+49,
yycrank+89,	0,		yyvstop+51,
yycrank+99,	0,		yyvstop+53,
yycrank+166,	0,		0,	
yycrank+189,	0,		yyvstop+55,
yycrank+0,	yysvec+16,	yyvstop+57,
yycrank+0,	0,		yyvstop+59,
yycrank+0,	yysvec+23,	yyvstop+61,
0,	0,	0};
struct yywork *yytop = yycrank+268;
struct yysvf *yybgin = yysvec+1;
char yymatch[] ={
00  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,011 ,012 ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
011 ,01  ,'"' ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,'-' ,01  ,01  ,
'0' ,'1' ,'1' ,'1' ,'1' ,'1' ,'1' ,'1' ,
'8' ,'8' ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'G' ,
'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,
'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,
'G' ,'G' ,'G' ,01  ,01  ,01  ,01  ,'G' ,
01  ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'G' ,
'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,
'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,'G' ,
'G' ,'G' ,'G' ,01  ,01  ,01  ,01  ,01  ,
0};
char yyextra[] ={
0,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
/*	ncform	4.1	83/08/11	*/

int yylineno =1;
# define YYU(x) x
# define NLSTATE yyprevious=YYNEWLINE
char yytext[YYLMAX];
struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
char yysbuf[YYLMAX];
char *yysptr = yysbuf;
int *yyfnd;
extern struct yysvf *yyestate;
int yyprevious = YYNEWLINE;
yylook(){
	register struct yysvf *yystate, **lsp;
	register struct yywork *yyt;
	struct yysvf *yyz;
	int yych;
	struct yywork *yyr;
# ifdef LEXDEBUG
	int debug;
# endif
	char *yylastch;
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	if (!yymorfg)
		yylastch = yytext;
	else {
		yymorfg=0;
		yylastch = yytext+yyleng;
		}
	for(;;){
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;){
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = yystate->yystoff;
			if(yyt == yycrank){		/* may not be any transitions */
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == yycrank)break;
				}
			*yylastch++ = yych = input();
		tryagain:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"char ");
				allprint(yych);
				putchar('\n');
				}
# endif
			yyr = yyt;
			if ( (int)yyt > (int)yycrank){
				yyt = yyr + yych;
				if (yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
# ifdef YYOPTIM
			else if((int)yyt < (int)yycrank) {		/* r < yycrank */
				yyt = yyr = yycrank+(yycrank-yyt);
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				yyt = yyr + YYU(yymatch[yych]);
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
					}
# endif
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
			if ((yystate = yystate->yyother) && (yyt= yystate->yystoff) != yycrank){
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
				}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
				}
# endif
			;
			}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",*(lsp-1)-yysvec-1);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
				yyleng = yylastch-yytext+1;
				yytext[yyleng] = 0;
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch ");
					sprint(yytext);
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
		if (yytext[0] == 0  /* && feof(yyin) */)
			{
			yysptr=yysbuf;
			return(0);
			}
		yyprevious = yytext[0] = input();
		if (yyprevious>0)
			output(yyprevious);
		yylastch=yytext;
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	}
yyback(p, m)
	int *p;
{
if (p==0) return(0);
while (*p)
	{
	if (*p++ == m)
		return(1);
	}
return(0);
}
	/* the following are only used in the lex library */
yyinput(){
	return(input());
	}
yyoutput(c)
  int c; {
	output(c);
	}
yyunput(c)
   int c; {
	unput(c);
	}
