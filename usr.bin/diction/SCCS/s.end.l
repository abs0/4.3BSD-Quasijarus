h40205
s 00052/00014/00187
d D 4.2 82/11/06 14:34:36 rrh 2 1
c Bill Jolitz @ Berkeley received this version from Lorindia Cherry
c around September 1981, as the ``most recent version''.  Deltas 
c seem to be progressive, rather than regressive, although the BTL sid for
c deroff.c is retrograde; this is probably a case of parallel development
e
s 00201/00000/00000
d D 4.1 82/11/06 13:47:55 rrh 1 0
c Oldest available version at Berkeley
e
u
U
t
T
I 1
%{
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%E%";
#endif not lint

#include <stdio.h>
I 2
#include <ctype.h>
E 2
#include "names.h"
#include "ehash.c"
#include "edict.c"
#define OUT1(c) putchar(c); putchar(':'); for(i=yyleng-1;i>=0;)putchar(yytext[i--])
I 2
#define POUT1(c) putchar(c); putchar(':'); for(i=yyleng-1;i>0;)putchar(yytext[i--])
E 2
int i;
int nomin = 0;
I 2
int NOCAPS = 0;		/*if set, all caps mapped to lower, plurals stripped*/
E 2
%}

C	[A-Z0-9a-z",;]
L	[a-zA-Z-]

%%
^{C}:.+	{
	ECHO;
	}
^ci.+	{
	look(ic,2,ADJ);
	}
^de.+	{
	look(ed,2,ED);
	}
^draw.+	{
I 2
	if(yytext[5] == 'E'){
		OUT1(NOUN_ADJ);
	}
E 2
	OUT1(ADJ_ADV);
	}
^eca.+	{
	look(ace,3,NOUN_VERB);
	}
^eci.+	{
	look(ice,3,NOUN_VERB);
	}
^ecne.+	{
D 2
	if(look(ence,4,NOUN))nomin++;
E 2
I 2
	if(look(ence,4,NOM))nomin++;
E 2
	}
^ecna.+	{
D 2
	if(look(ance,4,NOUN))nomin++;
E 2
I 2
	if(look(ance,4,NOM))nomin++;
E 2
	}
^ee.+	{
	look(ee,2,NOUN);
	}
^ega.+	{
	look(age,3,NOUN);
	}
^elba.+	{
	look(able,4,ADJ);
	}
^elbi.+	{
	look(ible,4,ADJ);
	}
^elc.+	{
	look(cle,3,NOUN);
	}
^eru.+	{
D 2
	if(look(ure,3,NOUN))nomin++;
E 2
I 2
	look(ure,3,NOUN);
E 2
	}
^eti.+	{
	look(ite,3,NOUN);
	}
^evi.+	{
	look(ive,3,ADJ);
	}
^ezi.+	{
	look(ize,3,VERB);
	}
^gni.+	{
	look(ing,3,ING);
	}
^hsi.+	{
	look(ish,3,ADJ);
	}
^lac.+	{
	look(cal,3,ADJ);
	}
^lanoi.+	{
	look(ional,5,ADJ);
	}
^luf.+	{
	look(ful,3,ADJ);
	}
^msi.+	{
	OUT1(NOUN);
	}
^nam.*	{
	look(man,3,NOUN);
	}
^nem.*	{
	OUT1(NV_PL);
	}
^noi.+	{
D 2
	if(look(ion,3,NOUN))nomin++;
E 2
I 2
	if(look(ion,3,NOM))nomin++;
E 2
	}
^pihs.+	{
	look(ship,4,NOUN);
	}
^ral.+	{
	look(lar,3,ADJ);
	}
^ronoh	{
	OUT1(NOUN_VERB);
	}
^ro.+	{
	OUT1(NOUN);
	}
^si.+	{
	look(is,2,NOUN);
	}
^ssel.+	{
	look(less,4,ADJ);
	}
^ssen.+	{
	look(ness,4,NOUN);
	}
^sse.+	{
	look(ess,3,NOUN);
	}
^ss.+	{
	look(ss,2,NOUN);
	}
^suo.+	{
	look(ous,3,ADJ);
	}
^su.+	{
	look(us,2,NOUN);
	}
I 2
^snoi.+	{
	if(look(ion,4,PNOUN))nomin++;
	}
^stnem.+	{
		if(look(ment,5,PNOUN))nomin++;
		}
^secne.+	{
		if(look(ence,5,PNOUN))nomin++;
		}
^secna.+	{
		if(look(ance,5,PNOUN))nomin++;
		}
E 2
^s.+	{
D 2
	if(yytext[yyleng-1] >= 'A' && yytext[yyleng-1]<= 'Z'){
		OUT1(NOUN);
E 2
I 2
	if(isupper(yytext[yyleng-1])){
		if(NOCAPS){
			yytext[yyleng-1] = tolower(yytext[yyleng-1]);
			POUT1(PNOUN);
		}
		else { OUT1(PNOUN); }
E 2
	}
	else {
D 2
		OUT1(NV_PL);
E 2
I 2
		if(NOCAPS){POUT1(NV_PL);}
		else{ OUT1(NV_PL); }
E 2
	}
	}
^tna.+	{
	look(ant,3,NOUN_ADJ);
	}
^tnem.+	{
D 2
	if(look(ment,4,NOUN))nomin++;
E 2
I 2
	if(look(ment,4,NOM))nomin++;
E 2
	}
^tse.+	{
	look(est,3,ADJ);
	}
^tsi.+	{
	look(ist,3,NOUN);
	}
[,\n]	{
	putchar(yytext[0]);
	}
{L}+	{
D 2
	if(yytext[yyleng-1] >= 'A' && yytext[yyleng-1] <= 'Z'){
E 2
I 2
	if(isupper(yytext[yyleng-1])){
		if(NOCAPS)
			yytext[yyleng-1] = tolower(yytext[yyleng-1]);
E 2
		if((yytext[0] == 'n' || yytext[0] == 'l') && yytext[1] == 'a'){
			OUT1(NOUN_ADJ);
		}
		else {
			OUT1(NOUN);
		}
	}
	else {
		OUT1(UNK);
	}
	}
D 2
:	{
E 2
I 2
^:[\n]	{
E 2
	egetd();
	}
I 2
^:.+[\n]	{
	printf("%s",yytext);
	}
E 2
%%
look(f,n,nc)
char (*f)();
int n;
char nc;
{
	int in,nn,ret;
	char sch;
	in=0;
	sch=yytext[yyleng-1];
D 2
	if(sch>= 'A' && sch <= 'Z'){
		yytext[yyleng-1] = sch -'A' +'a';
E 2
I 2
	if(isupper(sch)){
		yytext[yyleng-1] = tolower(sch);
E 2
		in=1;
	}
	if((*f)(&yytext[n],1,0) != 0){
		nn = (*f)(&yytext[n],1,0);
I 2
		if(nc == PNOUN)
			if(nn == NOUN_VERB){
				if(in == 1)nn=PNOUN;
				else nn=NV_PL;
			}
E 2
		ret = 0;
	}
	else {
		nn = nc;
		ret = 1;
	}
	if(in==1){
		if(nn == NOUN_VERB)nn=NOUN;
D 2
		yytext[yyleng-1]=sch;
E 2
I 2
		if(!NOCAPS)yytext[yyleng-1]=sch;	
E 2
	}
D 2
	OUT1(nn);
E 2
I 2
	if(nn==PNOUN && yytext[0] == 's' && NOCAPS){
		POUT1(nn);
	}
	else {
		OUT1(nn);
	}
E 2
	return(ret);
}
yywrap(){
	printf(";%d\n",nomin);
	return(1);
}
E 1
