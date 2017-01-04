h41502
s 00016/00016/00170
d D 4.5 04/09/17 22:12:46 msokolov 5 4
c only do the italic padding on CAT, not needed on PS with Adobe fonts
e
s 00012/00004/00174
d D 4.4 04/09/15 04:22:18 msokolov 4 3
c PostScript mode added, compiles
e
s 00003/00001/00175
d D 4.3 83/08/11 20:39:50 sam 3 2
c standardize sccs keyword lines
e
s 00004/00000/00172
d D 4.2 83/02/12 18:04:15 shannon 2 1
c merge eqn and neqn
e
s 00172/00000/00000
d D 4.1 83/02/11 18:28:52 shannon 1 0
c date and time created 83/02/11 18:28:52 by shannon
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
#ifndef lint
static char sccsid[] = "%W% %G%";
#endif
E 3

# include "e.h"
# include "e.def"

int	csp;
int	psp;
#define	CSSIZE	400
char	cs[420];

int	lf, rf;	/* temporary spots for left and right fonts */

text(t,p1) int t; char *p1; {
	int c;
	char *p;
	tbl *tp, *lookup();
	extern tbl *restbl;

	yyval = oalloc();
	ebase[yyval] = 0;
I 2
D 4
#ifndef NEQN
E 4
I 4
#ifdef CAT
E 4
E 2
	eht[yyval] = VERT(6 * ((ps>6)?ps:6));	/* ht in machine units */
I 2
D 4
#else NEQN
E 4
I 4
#endif
#ifdef PS
	eht[yyval] = VERT(60 * ((ps>4)?ps:4));	/* ht in machine units */
#endif
#ifdef NEQN
E 4
	eht[yyval] = VERT(2);	/* 2 half-spaces */
D 4
#endif NEQN
E 4
I 4
#endif
E 4
E 2
	lfont[yyval] = rfont[yyval] = ROM;
	if (t == QTEXT)
		p = p1;
	else if ( t == SPACE )
		p = "\\ ";
	else if ( t == THIN )
		p = "\\|";
	else if ( t == TAB )
		p = "\\t";
	else if ((tp = lookup(&restbl, p1, NULL)) != NULL)
		p = tp->defn;
	else {
		lf = rf = 0;
		for (csp=psp=0; (c=p1[psp++])!='\0';) {
			rf = trans(c, p1);
			if (lf == 0)
				lf = rf;	/* save first */
			if (csp>CSSIZE)
				error(FATAL,"converted token %.25s... too long",p1);
		}
		cs[csp] = '\0';
		p = cs;
		lfont[yyval] = lf;
		rfont[yyval] = rf;
	}
	if(dbg)printf(".\t%dtext: S%d <- %s; b=%d,h=%d,lf=%c,rf=%c\n",
		t, yyval, p, ebase[yyval], eht[yyval], lfont[yyval], rfont[yyval]);
	printf(".ds %d \"%s\n", yyval, p);
}

trans(c,p1) int c; char *p1; {
	int f;
	f = ROM;
	switch( c) {
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case ':': case ';': case '!': case '%':
	case '(': case '[': case ')': case ']':
	case ',':
D 5
		if (rf == ITAL)
			shim();
E 5
I 5
		itshim();
E 5
		roman(c); break;
	case '.':
		if (rf == ROM)
			roman(c);
		else
			cs[csp++] = c;
		f = rf;
		break;
	case '|':
D 5
		if (rf == ITAL)
			shim();
E 5
I 5
		itshim();
E 5
		shim(); roman(c); shim(); break;
	case '=':
D 5
		if (rf == ITAL)
			shim();
E 5
I 5
		itshim();
E 5
		name4('e','q');
		break;
	case '+':
D 5
		if (rf == ITAL)
			shim();
E 5
I 5
		itshim();
E 5
		name4('p', 'l');
		break;
	case '>': case '<':
D 5
		if (rf == ITAL)
			shim();
E 5
I 5
		itshim();
E 5
		if (p1[psp]=='=') {	/* look ahead for == <= >= */
			name4(c,'=');
			psp++;
		} else {
			cs[csp++] = c;  
		}
		break;
	case '-':
D 5
		if (rf == ITAL)
			shim();
E 5
I 5
		itshim();
E 5
		if (p1[psp]=='>') {
			name4('-','>'); psp++;
		} else {
			name4('m','i');
		}
		break;
	case '/':
D 5
		if (rf == ITAL)
			shim();
E 5
I 5
		itshim();
E 5
		name4('s','l');
		break;
	case '~': case ' ':
		shim(); shim(); break;
	case '^':
		shim(); break;
	case '\\':	/* troff - pass 2 or 3 more chars */
D 5
		if (rf == ITAL)
			shim();
E 5
I 5
		itshim();
E 5
		cs[csp++] = c; cs[csp++] = c = p1[psp++]; cs[csp++] = p1[psp++];
D 4
		if (c=='(') cs[csp++] = p1[psp++];
E 4
I 4
		if (c=='(' || c=='X' || c=='S') cs[csp++] = p1[psp++];
E 4
		if (c=='*' && cs[csp-1] == '(') {
			cs[csp++] = p1[psp++];
			cs[csp++] = p1[psp++];
		}
		break;
	case '\'':
I 4
#ifdef PS
		name4('M','i');
#else
E 4
		cs[csp++] = '\\'; cs[csp++] = 'f'; cs[csp++] = rf==ITAL ? ITAL : ROM;
		name4('f','m');
		cs[csp++] = '\\'; cs[csp++] = 'f'; cs[csp++] = 'P';
		f = rf==ITAL ? ITAL : ROM;
I 4
#endif
E 4
		break;

	case 'f':
		if (ft == ITAL) {
			cs[csp++] = '\\'; cs[csp++] = '^';
			cs[csp++] = 'f';
			cs[csp++] = '\\'; cs[csp++] = '|';	/* trying | instead of ^ */
			f = ITAL;
		}
		else
			cs[csp++] = 'f';
		break;
	case 'j':
		if (ft == ITAL) {
			cs[csp++] = '\\'; cs[csp++] = '^';
			cs[csp++] = 'j';
			f = ITAL;
		}
		else
			cs[csp++] = 'j';
		break;
	default:
		cs[csp++] = c;
		f = ft==ITAL ? ITAL : ROM;
		break;
	}
	return(f);
}

shim() {
	cs[csp++] = '\\'; cs[csp++] = '|';
I 5
}

itshim()
{
#ifdef CAT
	if (rf == ITAL)
		shim();
#endif
E 5
}

roman(c) int c; {
	cs[csp++] = '\\'; cs[csp++] = 'f'; cs[csp++] = ROM;
	cs[csp++] = c;
	cs[csp++] = '\\'; cs[csp++] = 'f'; cs[csp++] = 'P';
}

name4(c1,c2) int c1,c2; {
	cs[csp++] = '\\';
	cs[csp++] = '(';
	cs[csp++] = c1;
	cs[csp++] = c2;
}
E 1
