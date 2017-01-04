h14420
s 00005/00001/00216
d D 4.6 04/09/23 07:41:30 msokolov 6 5
c only do the italic padding on CAT, not needed on PS with Adobe fonts
e
s 00014/00006/00203
d D 4.5 04/09/15 04:22:09 msokolov 5 4
c PostScript mode added, compiles
e
s 00004/00002/00205
d D 4.4 83/09/03 15:18:56 rrh 4 3
c allow a file called '-' on the argument line to stand for stdin, so
c that eqn works like cat
e
s 00003/00001/00204
d D 4.3 83/08/11 20:38:45 sam 3 2
c standardize sccs keyword lines
e
s 00008/00000/00197
d D 4.2 83/02/12 18:03:39 shannon 2 1
c merge eqn and neqn
e
s 00197/00000/00000
d D 4.1 83/02/11 18:28:13 shannon 1 0
c date and time created 83/02/11 18:28:13 by shannon
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
#define	MAXLINE	1200	/* maximum input line */

char	in[MAXLINE];	/* input buffer */
int	eqnexit();
int noeqn;

main(argc,argv) int argc; char *argv[];{

	eqnexit(eqn(argc, argv));
}

eqnexit(n) {
#ifdef gcos
	if (n)
		fprintf(stderr, "run terminated due to eqn error\n");
	exit(0);
#endif
	exit(n);
}

eqn(argc,argv) int argc; char *argv[];{
	int i, type;

	setfile(argc,argv);
	init_tbl();	/* install keywords in tables */
	while ((type=getline(in)) != EOF) {
		eqline = linect;
		if (in[0]=='.' && in[1]=='E' && in[2]=='Q') {
			for (i=11; i<100; used[i++]=0);
			printf("%s",in);
			printf(".nr 99 \\n(.s\n.nr 98 \\n(.f\n");
			markline = 0;
			init();
			yyparse();
			if (eqnreg>0) {
				printf(".nr %d \\w'\\*(%d'\n", eqnreg, eqnreg);
				/* printf(".if \\n(%d>\\n(.l .tm too-long eqn, file %s, between lines %d-%d\n",	*/
				/*	eqnreg, svargv[ifile], eqline, linect);	*/
				printf(".nr MK %d\n", markline);	/* for -ms macros */
				printf(".if %d>\\n(.v .ne %du\n", eqnht, eqnht);
				printf(".rn %d 10\n", eqnreg);
				if(!noeqn)printf("\\*(10\n");
			}
			printf(".ps \\n(99\n.ft \\n(98\n");
			printf(".EN");
			if (lastchar == EOF) {
				putchar('\n');
				break;
			}
			if (putchar(lastchar) != '\n')
				while (putchar(gtc()) != '\n');
		}
		else if (type == lefteq)
			inline();
		else
			printf("%s",in);
	}
	return(0);
}

getline(s) register char *s; {
	register c;
	while((*s++=c=gtc())!='\n' && c!=EOF && c!=lefteq)
		if (s >= in+MAXLINE) {
			error( !FATAL, "input line too long: %.20s\n", in);
			in[MAXLINE] = '\0';
			break;
		}
	if (c==lefteq)
		s--;
	*s++ = '\0';
	return(c);
}

inline() {
	int ds;

	printf(".nr 99 \\n(.s\n.nr 98 \\n(.f\n");
	ds = oalloc();
	printf(".rm %d \n", ds);
	do{
		if (*in)
			printf(".as %d \"%s\n", ds, in);
		init();
		yyparse();
		if (eqnreg > 0) {
			printf(".as %d \\*(%d\n", ds, eqnreg);
			ofree(eqnreg);
		}
		printf(".ps \\n(99\n.ft \\n(98\n");
	} while (getline(in) == lefteq);
	if (*in)
		printf(".as %d \"%s", ds, in);
	printf(".ps \\n(99\n.ft \\n(98\n");
	printf("\\*(%d\n", ds);
	ofree(ds);
}

putout(p1) int p1; {
	extern int gsize, gfont;
	int before, after;
	if(dbg)printf(".\tanswer <- S%d, h=%d,b=%d\n",p1, eht[p1], ebase[p1]);
	eqnht = eht[p1];
	printf(".ds %d \\x'0'", p1);
	/* suppposed to leave room for a subscript or superscript */
I 2
D 5
#ifndef NEQN
E 5
I 5
#ifdef CAT
E 5
E 2
	before = eht[p1] - ebase[p1] - VERT((ps*6*12)/10);
I 2
D 5
#else NEQN
E 5
I 5
#endif
#ifdef PS
	before = eht[p1] - ebase[p1] - VERT(ps*6*12);
#endif
#ifdef NEQN
E 5
	before = eht[p1] - ebase[p1] - VERT(3);	/* 3 = 1.5 lines */
D 5
#endif NEQN
E 5
I 5
#endif
E 5
E 2
	if (before > 0)
		printf("\\x'0-%du'", before);
	printf("\\f%c\\s%d\\*(%d%s\\s\\n(99\\f\\n(98",
D 6
		gfont, gsize, p1, rfont[p1] == ITAL ? "\\|" : "");
E 6
I 6
		gfont, gsize, p1,
#ifdef CAT
		rfont[p1] == ITAL ? "\\|" :
#endif
		"");
E 6
I 2
D 5
#ifndef NEQN
E 5
I 5
#ifdef CAT
E 5
E 2
	after = ebase[p1] - VERT((ps*6*2)/10);
I 2
D 5
#else NEQN
E 5
I 5
#endif
#ifdef PS
	after = ebase[p1] - VERT(ps*6*2);
#endif
#ifdef NEQN
E 5
	after = ebase[p1] - VERT(1);
D 5
#endif NEQN
E 5
I 5
#endif
E 5
E 2
	if (after > 0)
		printf("\\x'%du'", after);
	putchar('\n');
	eqnreg = p1;
}

max(i,j) int i,j; {
	return (i>j ? i : j);
}

oalloc() {
	int i;
	for (i=11; i<100; i++)
		if (used[i]++ == 0) return(i);
	error( FATAL, "no eqn strings left", i);
	return(0);
}

ofree(n) int n; {
	used[n] = 0;
}

setps(p) int p; {
	printf(".ps %d\n", EFFPS(p));
}

nrwid(n1, p, n2) int n1, p, n2; {
	printf(".nr %d \\w'\\s%d\\*(%d'\n", n1, EFFPS(p), n2);
}

setfile(argc, argv) int argc; char *argv[]; {
	static char *nullstr = "-";

	svargc = --argc;
	svargv = argv;
	while (svargc > 0 && svargv[1][0] == '-') {
		switch (svargv[1][1]) {

		case 'd': lefteq=svargv[1][2]; righteq=svargv[1][3]; break;
		case 's': gsize = atoi(&svargv[1][2]); break;
		case 'p': deltaps = atoi(&svargv[1][2]); break;
		case 'f': gfont = svargv[1][2]; break;
		case 'e': noeqn++; break;
I 4
		case 0:	goto endargs; 
E 4
		default: dbg = 1;
		}
		svargc--;
		svargv++;
	}
I 4
  endargs:
E 4
	ifile = 1;
	linect = 1;
	if (svargc <= 0) {
		curfile = stdin;
		svargv[1] = nullstr;
	}
D 4
	else if ((curfile = fopen(svargv[1], "r")) == NULL)
		error( FATAL,"can't open file %s", svargv[1]);
E 4
I 4
	else
		openinfile();	/* opens up the first input file */
E 4
}

yyerror() {;}

init() {
	ct = 0;
	ps = gsize;
	ft = gfont;
	setps(ps);
	printf(".ft %c\n", ft);
}

error(fatal, s1, s2) int fatal; char *s1, *s2; {
	if (fatal>0)
		printf("eqn fatal error: ");
	printf(s1,s2);
	printf("\nfile %s, between lines %d and %d\n",
		 svargv[ifile], eqline, linect);
	fprintf(stderr, "eqn: ");
	if (fatal>0)
		fprintf(stderr, "fatal error: ");
	fprintf(stderr, s1, s2);
	fprintf(stderr, "\nfile %s, between lines %d and %d\n",
		 svargv[ifile], eqline, linect);
	if (fatal > 0)
		eqnexit(1);
}
E 1
