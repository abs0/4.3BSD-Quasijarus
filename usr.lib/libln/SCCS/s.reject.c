h26875
s 00004/00003/00040
d D 4.2 87/12/21 11:41:37 bostic 2 1
c make ANSI C compatible
e
s 00043/00000/00000
d D 4.1 82/12/25 10:41:40 sam 1 0
c date and time created 82/12/25 10:41:40 by sam
e
u
U
t
T
I 1
/*	%W%	%G%	*/

# include <stdio.h>
D 2
extern struct {int *yyaa, *yybb; int *yystops;} *yylstate [], **yylsp, **yyolsp;
yyreject ()
{
E 2
extern FILE *yyout, *yyin;
extern int yyprevious , *yyfnd;
extern char yyextra[];
extern char yytext[];
extern int yyleng;
I 2
extern struct {int *yyaa, *yybb; int *yystops;} *yylstate [], **yylsp, **yyolsp;

yyreject ()
{
E 2
for( ; yylsp < yyolsp; yylsp++)
	yytext[yyleng++] = yyinput();
if (*yyfnd > 0)
	return(yyracc(*yyfnd++));
while (yylsp-- > yylstate)
	{
	yyunput(yytext[yyleng-1]);
	yytext[--yyleng] = 0;
	if (*yylsp != 0 && (yyfnd= (*yylsp)->yystops) && *yyfnd > 0)
		return(yyracc(*yyfnd++));
	}
if (yytext[0] == 0)
	return(0);
yyoutput(yyprevious = yyinput());
yyleng=0;
return(-1);
}
yyracc(m)
{
yyolsp = yylsp;
if (yyextra[m])
	{
	while (yyback((*yylsp)->yystops, -m) != 1 && yylsp>yylstate)
		{
		yylsp--;
		yyunput(yytext[--yyleng]);
		}
	}
yyprevious = yytext[yyleng-1];
yytext[yyleng] = 0;
return(m);
}
E 1
