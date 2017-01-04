h09778
s 00001/00000/00363
d D 4.4 87/02/09 12:09:43 bostic 4 3
c bug fix, 4.3BSD/usr.bin/41
e
s 00011/00007/00352
d D 4.3 86/02/17 23:44:19 donn 3 2
c Fixed a bug in comment() that caused it to miss newlines when they were
c preceded by stars.  Also fixed a bug that caused core dumps if EOF
c appeared before a comment end.  Didn't bother to add code to check for
c buffer overflow -- this whole program is a crock.
e
s 00004/00003/00355
d D 4.2 84/12/19 11:47:20 karels 2 1
c fix gets type confflict
e
s 00358/00000/00000
d D 4.1 80/10/01 17:25:14 bill 1 0
c date and time created 80/10/01 17:25:14 by bill
e
u
U
t
T
I 1
static char *sccsid = "%W% (Berkeley) %G%";
#include <stdio.h>
int	slevel[10];
int	clevel	= 0;
int	spflg[20][10];
int	sind[20][10];
int	siflev[10];
int	sifflg[10];
int	iflev	= 0;
int	ifflg	= -1;
int	level	= 0;
int	ind[10]	= {
	0,0,0,0,0,0,0,0,0,0 };
int	eflg	= 0;
int	paren	= 0;
int	pflg[10] = {
	0,0,0,0,0,0,0,0,0,0 };
char	lchar;
char	pchar;
int	aflg	= 0;
int	ct;
int	stabs[20][10];
int	qflg	= 0;
char	*wif[] = {
	"if",0};
char	*welse[] = {
	"else",0};
char	*wfor[] = {
	"for",0};
char	*wds[] = {
	"case","default",0};
int	j	= 0;
char	string[200];
char	cc;
int	sflg	= 1;
int	peek	= -1;
int	tabs	= 0;
int	lastchar;
int	c;
I 2
int	getstr();
E 2
main(argc,argv) int argc;
char argv[];
{
	while((c = getch()) != EOF){
		switch(c){
		case ' ':
		case '\t':
			if(lookup(welse) == 1){
				gotelse();
				if(sflg == 0 || j > 0)string[j++] = c;
				puts();
				sflg = 0;
				continue;
			}
			if(sflg == 0 || j > 0)string[j++] = c;
			continue;
		case '\n':
			if((eflg = lookup(welse)) == 1)gotelse();
			puts();
			printf("\n");
			sflg = 1;
			if(eflg == 1){
				pflg[level]++;
				tabs++;
			}
			else
				if(pchar == lchar)
					aflg = 1;
			continue;
		case '{':
			if(lookup(welse) == 1)gotelse();
			siflev[clevel] = iflev;
			sifflg[clevel] = ifflg;
			iflev = ifflg = 0;
			clevel++;
			if(sflg == 1 && pflg[level] != 0){
				pflg[level]--;
				tabs--;
			}
			string[j++] = c;
			puts();
			getnl();
			puts();
			printf("\n");
			tabs++;
			sflg = 1;
			if(pflg[level] > 0){
				ind[level] = 1;
				level++;
				slevel[level] = clevel;
			}
			continue;
		case '}':
			clevel--;
			if((iflev = siflev[clevel]-1) < 0)iflev = 0;
			ifflg = sifflg[clevel];
			if(pflg[level] >0 && ind[level] == 0){
				tabs -= pflg[level];
				pflg[level] = 0;
			}
			puts();
			tabs--;
			ptabs();
			if((peek = getch()) == ';'){
				printf("%c;",c);
				peek = -1;
			}
			else printf("%c",c);
			getnl();
			puts();
			printf("\n");
			sflg = 1;
			if(clevel < slevel[level])if(level > 0)level--;
			if(ind[level] != 0){
				tabs -= pflg[level];
				pflg[level] = 0;
				ind[level] = 0;
			}
			continue;
		case '"':
		case '\'':
			string[j++] = c;
			while((cc = getch()) != c){
				string[j++] = cc;
				if(cc == '\\'){
					string[j++] = getch();
				}
				if(cc == '\n'){
					puts();
					sflg = 1;
				}
			}
			string[j++] = cc;
			if(getnl() == 1){
				lchar = cc;
				peek = '\n';
			}
			continue;
		case ';':
			string[j++] = c;
			puts();
			if(pflg[level] > 0 && ind[level] == 0){
				tabs -= pflg[level];
				pflg[level] = 0;
			}
			getnl();
			puts();
			printf("\n");
			sflg = 1;
			if(iflev > 0)
				if(ifflg == 1){iflev--;
					ifflg = 0;
				}
				else iflev = 0;
			continue;
		case '\\':
			string[j++] = c;
			string[j++] = getch();
			continue;
		case '?':
			qflg = 1;
			string[j++] = c;
			continue;
		case ':':
			string[j++] = c;
			if(qflg == 1){
				qflg = 0;
				continue;
			}
			if(lookup(wds) == 0){
				sflg = 0;
				puts();
			}
			else{
				tabs--;
				puts();
				tabs++;
			}
			if((peek = getch()) == ';'){
				printf(";");
				peek = -1;
			}
			getnl();
			puts();
			printf("\n");
			sflg = 1;
			continue;
		case '/':
			string[j++] = c;
			if((peek = getch()) != '*')continue;
			string[j++] = peek;
			peek = -1;
			comment();
			continue;
		case ')':
			paren--;
			string[j++] = c;
			puts();
			if(getnl() == 1){
				peek = '\n';
				if(paren != 0)aflg = 1;
				else if(tabs > 0){
					pflg[level]++;
					tabs++;
					ind[level] = 0;
				}
			}
			continue;
		case '#':
			string[j++] = c;
			while((cc = getch()) != '\n')string[j++] = cc;
			string[j++] = cc;
			sflg = 0;
			puts();
			sflg = 1;
			continue;
		case '(':
			string[j++] = c;
			paren++;
			if(lookup(wfor) == 1){
D 2
				while((c = gets()) != ';');
E 2
I 2
				while((c = getstr()) != ';');
E 2
				ct=0;
cont:
D 2
				while((c = gets()) != ')'){
E 2
I 2
				while((c = getstr()) != ')'){
E 2
					if(c == '(') ct++;
				}
				if(ct != 0){
					ct--;
					goto cont;
				}
				paren--;
				puts();
				if(getnl() == 1){
					peek = '\n';
					pflg[level]++;
					tabs++;
					ind[level] = 0;
				}
				continue;
			}
			if(lookup(wif) == 1){
				puts();
				stabs[clevel][iflev] = tabs;
				spflg[clevel][iflev] = pflg[level];
				sind[clevel][iflev] = ind[level];
				iflev++;
				ifflg = 1;
			}
			continue;
		default:
			string[j++] = c;
			if(c != ',')lchar = c;
		}
	}
}
ptabs(){
	int i;
	for(i=0; i < tabs; i++)printf("\t");
}
getch(){
	if(peek < 0 && lastchar != ' ' && lastchar != '\t')pchar = lastchar;
	lastchar = (peek<0) ? getc(stdin):peek;
	peek = -1;
	return(lastchar);
}
puts(){
	if(j > 0){
		if(sflg != 0){
			ptabs();
			sflg = 0;
			if(aflg == 1){
				aflg = 0;
				if(tabs > 0)printf("    ");
			}
		}
		string[j] = '\0';
		printf("%s",string);
		j = 0;
	}
	else{
		if(sflg != 0){
			sflg = 0;
			aflg = 0;
		}
	}
}
lookup(tab)
char *tab[];
{
	char r;
	int l,kk,k,i;
	if(j < 1)return(0);
	kk=0;
	while(string[kk] == ' ')kk++;
	for(i=0; tab[i] != 0; i++){
		l=0;
		for(k=kk;(r = tab[i][l++]) == string[k] && r != '\0';k++);
		if(r == '\0' && (string[k] < 'a' || string[k] > 'z' || k >= j))return(1);
	}
	return(0);
}
D 2
gets(){
E 2
I 2
getstr(){
E 2
	char ch;
beg:
	if((ch = string[j++] = getch()) == '\\'){
		string[j++] = getch();
		goto beg;
	}
	if(ch == '\'' || ch == '"'){
		while((cc = string[j++] = getch()) != ch)if(cc == '\\')string[j++] = getch();
		goto beg;
	}
	if(ch == '\n'){
		puts();
		aflg = 1;
		goto beg;
	}
	else return(ch);
}
gotelse(){
	tabs = stabs[clevel][iflev];
	pflg[level] = spflg[clevel][iflev];
	ind[level] = sind[clevel][iflev];
	ifflg = 1;
}
getnl(){
	while((peek = getch()) == '\t' || peek == ' '){
		string[j++] = peek;
		peek = -1;
	}
	if((peek = getch()) == '/'){
		peek = -1;
		if((peek = getch()) == '*'){
			string[j++] = '/';
			string[j++] = '*';
			peek = -1;
			comment();
		}
		else string[j++] = '/';
	}
	if((peek = getch()) == '\n'){
		peek = -1;
		return(1);
	}
	return(0);
}
comment(){
D 3
rep:
	while((c = string[j++] = getch()) != '*')
		if(c == '\n'){
E 3
I 3
	int i = j;

	while ((c = getch()) != EOF) {
		string[j++] = c;
		switch(c) {
		case '/':
			if (j > i + 1 && string[j-2] == '*')
				return;
			break;
		case '\n':
E 3
			puts();
I 4
			i = 0;
E 4
			sflg = 1;
I 3
			break;
E 3
		}
D 3
gotstar:
	if((c = string[j++] = getch()) != '/'){
		if(c == '*')goto gotstar;
		goto rep;
E 3
	}
}
E 1
