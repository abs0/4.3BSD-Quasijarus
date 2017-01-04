h41282
s 00001/00001/00019
d D 4.2 85/01/09 10:15:09 ralph 2 1
c fix compiler warning
e
s 00020/00000/00000
d D 4.1 82/12/25 10:41:41 sam 1 0
c date and time created 82/12/25 10:41:41 by sam
e
u
U
t
T
I 1
/*	%W%	%G%	*/

yyless(x)
{
extern char yytext[];
register char *lastch, *ptr;
extern int yyleng;
extern int yyprevious;
lastch = yytext+yyleng;
if (x>=0 && x <= yyleng)
	ptr = x + yytext;
else
D 2
	ptr = x;
E 2
I 2
	ptr = (char *) x;
E 2
while (lastch > ptr)
	yyunput(*--lastch);
*lastch = 0;
if (ptr >yytext)
	yyprevious = *--lastch;
yyleng = ptr-yytext;
}
E 1
