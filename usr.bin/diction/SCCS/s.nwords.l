h60557
s 00123/00061/00377
d D 4.2 82/11/06 14:34:42 rrh 2 1
c Bill Jolitz @ Berkeley received this version from Lorindia Cherry
c around September 1981, as the ``most recent version''.  Deltas 
c seem to be progressive, rather than regressive, although the BTL sid for
c deroff.c is retrograde; this is probably a case of parallel development
e
s 00438/00000/00000
d D 4.1 82/11/06 13:47:56 rrh 1 0
c Oldest available version at Berkeley
e
u
U
t
T
I 1
%{
/* break out words, output cap + word(inverted) */

#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%E%";
#endif not lint

#include <stdio.h>
I 2
#include <ctype.h>
E 2
#define OUT()	for(i=yyleng-1;i>=0; i--)putchar(yytext[i]); putchar('\n')
#define OUT1(nam)	printf("%c:%s\n",nam,yytext)
#define OUTN(string)	printf("%s\n",string)
#include "names.h"
#include "nhash.c"
#include "dict.c"
#include "ydict.c"
I 2
#include "abbrev.c"
E 2
char nt[]  = "D:n't";
char qs[]  = "c:'s";
char fin[]  = "E:.";
I 2
int NOCAPS = 0;		/* if set all caps are turned to lower case */
E 2
int i,j;
int dot = 0;
int first  = 1;
int qflg,nflg;
int cap  = 0;
%}
%p 3000
D 2
%a 2500
E 2
I 2
%a 3300
%o 4500
E 2

L	[a-z]
N	[0-9]
C	[A-Z]
I 2
A	[a-zA-Z]
P	[a-zA-Z0-9]
E 2

%%
D 2
(St|Dr|Drs|Mr|Mrs|Ms)"."	{
E 2
I 2
^[.!].+[\n]	{
	if(dot){
		OUTN(fin);
		dot = 0;
		first = 1;
	}
	printf(":%s",yytext);
	}
May	{
		if(first == 0){
			OUT1(NOUN);
		}
		else {
			first = 0;
			yytext[0] = tolower(yytext[0]);
			cap = 1;
			goto wd;
		}
	}
"U.S."		{
E 2
		OUT1(NOUN);
		}
{C}{L}*'[s]	{
		pos(1);
		if(first==1)first=0;
		}
D 2
{C}+['][s]*	{
E 2
I 2
{C}+['][s]	{
		if(NOCAPS)
			for(i=0;i<yyleng;i++)
				if(isupper(yytext[i]))yytext[i] = tolower(yytext[i]);
E 2
		OUT1(POS);
		}
D 2
(({C}+{L}*)|({C}*{L}+))+([-](({C}*{L}+)|({C}+{L}*))+)+	{
E 2
I 2
{P}+([-]{P}+)+	{
		if(NOCAPS)
			for(i=0;i<yyleng;i++)
				if(isupper(yytext[i]))yytext[i] = tolower(yytext[i]);
E 2
		OUT1(NOUN_ADJ);
		}
{C}{C}+	{
I 2
		if(NOCAPS)
			for(i=0;i<yyleng;i++)
				yytext[i] = tolower(yytext[i]);
E 2
		if((i=input()) == 's'){
			yytext[yyleng++] = 's';
			yytext[yyleng] = '\0';
D 2
			OUT1(NOUN);
E 2
I 2
			OUT1(PNOUN);
E 2
		}
		else {
			unput(i);
D 2
			for(i=0;i<yyleng;i++)yytext[i]+= 'a' - 'A';
E 2
I 2
			if(!NOCAPS)
				for(i=0;i<yyleng;i++)yytext[i] = tolower(yytext[i]);
E 2
				goto wd;
		}
		}
[LD][']{C}{L}*	{
I 2
		if(NOCAPS){
			yytext[0] = tolower(yytext[0]);
			yytext[2] = tolower(yytext[2]);
		}
E 2
		OUT1(NOUN_ADJ);
		}
{C}{L}*	{
		if(first==1)
			first=0;
		else cap = 1;
		if(yyleng==1 && yytext[0] == 'I'){
			cap = 0;
			goto wd;
		}
D 2
		yytext[0]+= 'a' - 'A';
E 2
I 2
		yytext[0] = tolower(yytext[0]);
E 2
		goto wd;
	}
D 2
({N}+[-]{N}+[-]*)+	{
E 2
I 2
{N}":"{N}{N}	{
E 2
		OUT1(NOUN_ADJ);
		}
D 2
({N}+[-]*{L}+[-]*)+	{
		OUT1(NOUN_ADJ);
		}
E 2
({N}*[,])*({N}+".")+[ \t\n]+{C}	{
		for(i=yyleng-1;i>0;i--)
			if(yytext[i] == '.')break;
		unput(yytext[yyleng-1]);
		yytext[i] = '\0';
		OUT1(NOUN_ADJ);
		OUTN(fin);
		first = 1;
	}
D 2
[ \t`][a-zA-Z0-9.]*("\/"[a-zA-Z0-9]+"."*)+[']*	{
		if(yytext[yyleng-1] == '.')dot=1;
E 2
I 2
([hH]e"/"[sS]he)|([sS]he"/"[hH]e)		{
	if(NOCAPS)
		if(isupper(yytext[0]))yytext[0] = tolower(yytext[0]);
	OUT1(PRONS);
	}
([hH]is"/"[hH]er)|([hH]er"/"[hH]is)	{
	if(NOCAPS)
		if(isupper(yytext[0]))yytext[0] = tolower(yytext[0]);
	OUT1(POS);
	}
[ \t`]*[a-zA-Z0-9.]*("\/"[a-zA-Z0-9.]+)+[']*	{
		if(yytext[yyleng-1] == '.'){
			if(ahead() == 0)dot=1;
		}
		if(NOCAPS)
			for(i=0;i<yyleng;i++)
				if(isupper(yytext[i]))yytext[i] = tolower(yytext[i]);
E 2
		OUT1(NOUN_ADJ);
		}
{N}+([,]{N}+)*("."{N}+)*[']*[s]*	{
	OUT1(NOUN_ADJ);
	}
{N}*([,]{N}+)*("."{N}+)+[']*[s]*	{
	OUT1(NOUN_ADJ);
	}
{N}+([,]{N}+)*("."{N}*)*[']*[s]*	{
	if(yytext[yyleng-1] == '.')dot=1;
	OUT1(NOUN_ADJ);
	}
D 2
{L}+[-]*{N}+	{
		OUT1(NOUN_ADJ);
		}
{C}+[-]*{N}+	{
E 2
I 2
({A}*{N}+{A}*)+	{
	if(input() == '.')
		ahead();
	if(NOCAPS)
		for(i=0;i<yyleng;i++)
			if(isupper(yytext[i]))yytext[i]=tolower(yytext[i]);
E 2
	OUT1(NOUN_ADJ);
	}
D 2
{N}+[-]+{C}+	{
	OUT1(NOUN_ADJ);
		}
E 2
{N}+[%]		{
		OUT1(NOUN_ADJ);
		}
"$"{N}+([,]{N}+)*("."{N}*)*	{
		if(yytext[yyleng-1] == '.')dot=1;
		OUT1(NOUN);
		}
[Aa]"."[ ]*[Mm]"."	{
		OUT1(ADJ_ADV);
		}
[Pp]"."[ ]*[Mm]"."	{
		OUT1(ADJ_ADV);
		}
"a."[ ]*"d."	{
		OUT1(ADJ_ADV);
		}
"b."[ ]*"c."	{
		OUT1(ADJ_ADV);
		}
"i."[ ]*"e."	{
		OUT1(PREP);
		}
"e."[ ]*"g."	{
		OUT1(PREP);
		}
"etc."[ \n]*[,)]*	{
		i = yytext[4];
		yytext[4] = '\0';
		OUT1(NOUN);
		yytext[4] = i;
		yytext[0] = yytext[yyleng-1];
		yytext[1] = '\0';
		if(yytext[0] == ',' || yytext[0] == ')')
			OUT1(',');
		else {
			OUTN(fin);
			first = 1;
		}
	}
"et al."	{
		OUT1(NOUN);
		}
D 2
[Nn][Oo][s]*"."	{
		OUT1(NOUN_ADJ);
		}
[Ff]ig[s]*"."	{
		OUT1(NOUN_ADJ);
		}
[Dd]ept[s]*"."	{
		OUT1(NOUN_ADJ);
	}
[Ee]q"."	{
		OUT1(NOUN_ADJ);
		}
dB"."	{
		OUT1(NOUN_ADJ);
		}
vs"."	{
	OUT1(PREP);
	}
E 2
in"."[ \n]*{C}	{
		unput(yytext[yyleng-1]);
		yytext[2] = '\0';
		OUT1(PREP);
		OUTN(fin);
		first = 1;
		}
D 2
(in|ft|yr|ckts|mi)"."	{
		OUT1(NOUN_ADJ);
		}
E 2
Ph"."[ ]*[Dd]"."	{
		OUT1(ADJ);
		}
D 2
[Jj]r"."	{
	OUT1(ADJ);
	}
[Cc]h"."	{
		OUT1(NOUN_ADJ);
	}
[Rr]ef[s]*"."	{
		OUT1(NOUN_ADJ);
	}
Inc"."	{
		OUT1(ADJ);
	}
E 2
[A-Z]"."	{
		dot=1;
		OUT1(NOUN);
		}
can't		{
		yytext[3]='\0';
		yyleng -= 2;
		nflg=1;
		goto wd;
		}
won't		{
		OUT1('X');
		}
I 2
ain't		{
		OUT1('g');
		}
E 2
{L}+n't		{
		nflg=1;
		yytext[yyleng-3]='\0';
		yyleng -= 3;
		goto wd;
		}
[A-Z]{L}+n't	{
D 2
		yytext[0]+= 'a' - 'A';
E 2
I 2
		yytext[0] = tolower(yytext[0]);
E 2
		nflg=1;
		yytext[yyleng-3]='\0';
		yyleng -= 3;
		goto wd;
		}
D 2
o'clock	{
E 2
I 2
o'clock		{
E 2
		OUT1(ADV);
	}
{L}+'[s]	{
		pos(0);
		}
'll	{
		OUT1(lookup("will",1,0));
	}
've	{
		OUT1(lookup("have",1,0));
	}
're	{
		OUT1(lookup("are",1,0));
	}
'd	{
		OUT1(lookup("had",1,0));
	}
'm	{
		OUT1(lookup("am",1,0));
	}
'ld	{
		OUT1(lookup("would",1,0));
	}
{L}+	{
wd:
	if((j = lookup(yytext,1,0)) != 0){
		first=0;
		if(cap){
D 2
			yytext[0] += 'A' - 'a';
E 2
I 2
			if(!NOCAPS)
				yytext[0] = toupper(yytext[0]);
E 2
			cap = 0;
			if(dot)OUTN(fin);
		}
		dot=0;
		OUT1(j);
		if(nflg==1){
			nflg=0;
			OUTN(nt);
		}
	}
	else{
		first = dot=0;
		if(yytext[yyleng-1] == 'y' && cap == 0){
			switch(yytext[yyleng-2]){
			case 'c': look(cy,yyleng-2,NOUN);
					break;
			case 'f': look(fy,yyleng-2,VERB);
					break;
			case 'l': look(ly,yyleng-2,ADV);
					break;
			case 'g': if(yytext[yyleng-3] == 'o'){
					OUT1(NOUN);
					break;
				}
D 2
				 look(gy,yyleng-2,ADJ);
E 2
I 2
				look(gy,yyleng-2,ADJ);
E 2
				break;
			case 'r':	switch(yytext[yyleng-3]){
				case 'a': look(ary,yyleng-3,ADJ);
						break;
				case 'o': look(ory,yyleng-3,ADJ);
						break;
				case 'e': look(ery,yyleng-3,NOUN);
						break;
				default: look(ry,yyleng-2,NOUN);
				}
				break;
			case 't': if(yytext[yyleng-3] == 'i')look(ity,yyleng-3,NOUN);
				else look(ty,yyleng-2,ADJ);
				break;
			default: OUT();
			}
D 2
		}
E 2
I 2
	}
E 2
		else {
			if(cap){
D 2
				yytext[0] += 'A' - 'a';
E 2
I 2
				if(!NOCAPS)yytext[0] = toupper(yytext[0]);
E 2
				cap = 0;
				OUT1(NOUN_ADJ);
			}
			else {
				OUT();
			}
		}
	}
	}
[\n]	;
[ ]+	;
[\t]+	;
";"	{
	OUT1(';');
	first=1;
	}
(\"|`|')+	{
	if(dot){
		OUTN(fin);
		dot=0;
	}
	if(qflg==1){
		qflg=0;
		OUT1('"');
	}
	else {
		qflg=1;
		first=1;
		OUT1('"');
	}
	}
".\""	{
	qflg=0;
	first=1;
	OUT1(END);
	}
"..."	{
	OUT1(',');
	}
"/."	{
	first = 1;
	OUT1(END);
	}
I 2
{A}{A}+"."	{
		yytext[yyleng-1] = '\0';
		if((j=abbrev(yytext,1,0)) != 0){
			if(isupper(yytext[0])){
				if(NOCAPS)yytext[0] = tolower(yytext[0]);
				if(first == 1)first=0;
			}
			yytext[yyleng-1] = '.';
			OUT1(j);
		}
		else {
			j = ahead();
			if(j == 0)
				yyleng--;
			for(i=0;i<yyleng;i++)
				if(isupper(yytext[i])){
					yytext[i] = tolower(yytext[i]);
					if(i == 0)cap = 1;
					else cap = 0;
				}
			if(j == 0)goto wd;
			OUT1(NOUN_ADJ);
		}
	}
E 2
"."	{
	first=1;
	OUT1(END);
	}
"!\""	{
	qflg=0;
	first=1;
	OUT1(END);
	}
"!"	{
	first=1;
	OUT1(END);
	}
"?\""	{
	qflg=0;
	first=1;
	OUT1(END);
	}
"?"	{
	first=1;
	OUT1(END);
	}
":"	{
	OUT1(',');
	first=1;
	}
[-]+	{
	OUT1(',');
	first=1;
	}
","	{
	OUT1(',');
	}
(\[|\(|\{|\]|\)|\})	{
	OUT1(',');
	}
.	{
/*	fprintf(stderr,"nwords funny char: %c\n",yytext[0])*/ ;
	}
%%
look(f,n,cc)
char (*f)();
int n;
char cc;
{
	int nn;
	char  save;
	save=yytext[n];
	yytext[n] = '\0';
	nn=(*f)(yytext,1,0);
	yytext[n] = save;
	if(nn != 0){
		OUT1(nn);
	}
	else {
		OUT1(cc);
	}
}
pos(flg){
	int ii,j;
D 2
	if(flg==1)yytext[0] += 'a' - 'A';
E 2
I 2
	if(flg == 1)yytext[0] = tolower(yytext[0]);
E 2
	for(ii=yyleng-1;yytext[ii] != '\''; ii--);
	yytext[ii] = '\0';
	if((j=lookup(yytext,1,0)) != 0){
		yyleng = ii;
		OUT1(j);
		OUTN(qs);
	}
	else{
D 2
		if(flg==1)yytext[0] += 'A' - 'a';
E 2
I 2
		if(flg==1 && !NOCAPS)yytext[0] = toupper(yytext[0]);
E 2
		yytext[ii] = '\'';
		OUT1(POS);
	}
}
char	*filename="-";

main(argc,argv)
int	argc;
char	*argv[];
{
	register int rc=0;
	putchar(':'); putchar('\n');
	getd();
I 2
	getab();
E 2
	ygetd();
	if(argc<=1) {
		yylex();
I 2
		OUTN(fin);
E 2
	}else{
		while(argc>1) {
			if(freopen(argv[1],"r",stdin)==NULL) {
				fprintf(stderr,"%s: cannot open\n", argv[1]);
				rc++;
			}else{
				filename=argv[1];
				yylex();
I 2
				OUTN(fin);
E 2
			}
			argc--; argv++;
		}
	}
	return(rc);
I 2
}
ahead(){
	register int c;
	if(isalnum((c=input()))){
		yytext[yyleng++] = '.';
		while(!isspace((c=input() )))
			yytext[yyleng++] = c;
		yytext[yyleng] = '\0';
		unput(c);
		return(1);
	}
	unput(c);
	unput('.');
	return(0);
E 2
}
E 1
