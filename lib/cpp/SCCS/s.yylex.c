h40372
s 00001/00001/00093
d D 1.4 86/10/15 21:11:59 sam 4 3
c add tahoe
e
s 00001/00001/00093
d D 1.3 83/07/01 03:24:45 sam 3 2
c for sun
e
s 00007/00003/00087
d D 1.2 83/06/10 23:06:21 sam 2 1
c handle hex properly (from robert)
e
s 00090/00000/00000
d D 1.1 82/08/30 09:57:37 rrh 1 0
c date and time created 82/08/30 09:57:37 by rrh
e
u
U
t
T
I 1
#ifndef lint
D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
static char sccsid[] = "%W% %G%";
E 2
#endif lint

#define isid(a)  ((fastab+COFF)[a]&IB)
#define IB 1
/*	#if '\377' < 0		it would be nice if this worked properly!!!!! */
D 3
#if pdp11 | vax
E 3
I 3
D 4
#if pdp11 | vax | mc68000
E 4
I 4
#if pdp11 | vax | mc68000 | tahoe
E 4
E 3
#define COFF 128
#else
#define COFF 0
#endif

yylex() {
	static int ifdef=0;
	static char *op2[]={"||",  "&&" , ">>", "<<", ">=", "<=", "!=", "=="};
	static int  val2[]={OROR, ANDAND,  RS,   LS,   GE,   LE,   NE,   EQ};
	static char *opc="b\bt\tn\nf\fr\r\\\\";
	extern char fastab[];
	extern char *outp,*inp,*newp; extern int flslvl;
	register char savc, *s; char *skipbl(); int val;
	register char **p2;
	struct symtab {
		char *name;
		char *value;
	} *sp, *lookup();

for (;;) {
I 2
	extern int passcom;		/* this crap makes #if's work */
	int opt_passcom = passcom;	/* even with -C option */
	passcom = 0;			/* (else comments make syntax errs) */
E 2
	newp=skipbl(newp);
I 2
	passcom = opt_passcom;		/* nb: lint uses -C so its useful! */
E 2
	if (*inp=='\n') return(stop);	/* end of #if */
	savc= *newp; *newp='\0';
	for (p2=op2+8; --p2>=op2; )	/* check 2-char ops */
		if (0==strcmp(*p2,inp)) {val=val2[p2-op2]; goto ret;}
	s="+-*/%<>&^|?:!~(),";	/* check 1-char ops */
	while (*s) if (*s++== *inp) {val= *--s; goto ret;}
	if (*inp<='9' && *inp>='0') {/* a number */
		if (*inp=='0') yylval= (inp[1]=='x' || inp[1]=='X') ?
			tobinary(inp+2,16) : tobinary(inp+1,8);
		else yylval=tobinary(inp,10);
		val=number;
	} else if (isid(*inp)) {
		if (0==strcmp(inp,"defined")) {ifdef=1; ++flslvl; val=DEFINED;}
		else {
			sp=lookup(inp,-1); if (ifdef!=0) {ifdef=0; --flslvl;}
			yylval= (sp->value==0) ? 0 : 1;
			val=number;
		}
	} else 	if (*inp=='\'') {/* character constant */
		val=number;
		if (inp[1]=='\\') {/* escaped */
			char c; if (newp[-1]=='\'') newp[-1]='\0';
			s=opc;
			while (*s) if (*s++!=inp[2]) ++s; else {yylval= *s; goto ret;}
			if (inp[2]<='9' && inp[2]>='0') yylval=c=tobinary(inp+2,8);
			else yylval=inp[2];
		} else yylval=inp[1];
	} else if (0==strcmp("\\\n",inp)) {*newp=savc; continue;}
	else {
		*newp=savc; pperror("Illegal character %c in preprocessor if", *inp);
		continue;
	}
ret:
	*newp=savc; outp=inp=newp; return(val);
}
}

tobinary(st, b) char *st; {
	int n, c, t;
	char *s;
	n=0;
	s=st;
	while (c = *s++) {
	switch(c) {
		case '0': case '1': case '2': case '3': case '4': 
		case '5': case '6': case '7': case '8': case '9': 
			t = c-'0'; break;
		case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': 
D 2
			t = c-'a'; if (b>10) break;
E 2
I 2
			t = c-'a'+10; if (b>10) break;
E 2
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': 
D 2
			t = c - 'A'; if (b>10) break;
E 2
I 2
			t = c - 'A'+10; if (b>10) break;
E 2
		default:
			t = -1;
			if ( c=='l' || c=='L') if (*s=='\0') break;
			pperror("Illegal number %s", st);
	}
	if (t<0) break;
	n = n*b+t;
	}
return(n);
}
E 1
