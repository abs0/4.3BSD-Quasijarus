# define CHAR 257
# define DOT 258
# define CCL 259
# define NCCL 260
# define OR 261
# define CAT 262
# define STAR 263
# define PLUS 264
# define QUEST 265

# line 16 "egrep.y"
static char *sccsid = "@(#)egrep.y	4.11 (Berkeley) 2012/03/03";
#include <stdio.h>
#include <ctype.h>
#include <sys/param.h>
#include <sys/stat.h>

extern char *malloc();

#define BLKSIZE 8192
#define MAXLIN 350
#define MAXPOS 4000
#define CCLMAX 512
#define NCHARS 256
#define NSTATES 256
#define FINAL -1
u_char gotofn[NSTATES][NCHARS];
int state[NSTATES];
char out[NSTATES];
int line = 1;
int name[MAXLIN];
int left[MAXLIN];
int right[MAXLIN];
int parent[MAXLIN];
int foll[MAXLIN];
int positions[MAXPOS];
u_char chars[CCLMAX];
int nxtpos;
int nxtchar = 0;
int tmpstat[MAXLIN];
int initstat[MAXLIN];
int xstate;
int count;
int icount;
u_char *input;
FILE *exprfile;

long	lnum;
int	bflag;
int	cflag;
int	fflag;
int	iflag;
int	lflag;
int	nflag;
int	sflag;
int	vflag;
int	print_filenames;
int	recurse_flag;
int	recurse_symlinks;
int	retcode = 0;
long	blkno;
long	tln;
int	nsucc;

int	f;
char	*fname;
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern short yyerrflag;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#ifndef YYSTYPE
#define YYSTYPE int
#endif
YYSTYPE yylval, yyval;
# define YYERRCODE 256

# line 117 "egrep.y"

yyerror(s) {
	fprintf(stderr, "egrep: %s\n", s);
	exit(2);
}

yylex() {
	extern int yylval;
	int cclcnt, x;
	register int c, d;
	switch(c = nextch()) {
		case '$':
		case '^': c = '\n';
			goto defchar;
		case '|': return (OR);
		case '*': return (STAR);
		case '+': return (PLUS);
		case '?': return (QUEST);
		case '(': return (c);
		case ')': return (c);
		case '.': return (DOT);
		case '\0': return (0);
		case '\n': return (OR);
		case '[': 
			x = CCL;
			cclcnt = 0;
			count = nxtchar++;
			if ((c = nextch()) == '^') {
				x = NCCL;
				c = nextch();
			}
			do {
				if (c == '\0') synerror();
				if (nxtchar >= CCLMAX) overflo();
				if (c == '-' && cclcnt > 0) {
					if ((d = nextch()) == 0) synerror();
					if (d == ']') {
						chars[nxtchar++] == '-';
						cclcnt++;
						break;
					}
					c = chars[nxtchar-1];
					while (c < d) {
						if (nxtchar >= CCLMAX)
							overflo();
						chars[nxtchar++] = ++c;
						cclcnt++;
					}
					continue;
				}
				chars[nxtchar++] = c;
				cclcnt++;
			} while ((c = nextch()) != ']');
			chars[count] = cclcnt;
			return (x);
		case '\\':
			if ((c = nextch()) == '\0') synerror();
		defchar: yylval = c; return (CHAR);
		default:
			if (!iflag || !islower(c))
				goto defchar;
			count = (c - 'a') * 3;
			return (CCL);
	}
}
nextch() {
	register int c;
	if (fflag) {
		if ((c = getc(exprfile)) == EOF) {
			fclose(exprfile);
			return(0);
		}
	}
	else c = *input++;
	return(c);
}

synerror() {
	fprintf(stderr, "egrep: syntax error\n");
	exit(2);
}

enter(x) int x; {
	if(line >= MAXLIN) overflo();
	name[line] = x;
	left[line] = 0;
	right[line] = 0;
	return(line++);
}

cclenter(x) int x; {
	register linno;
	linno = enter(x);
	right[linno] = count;
	return (linno);
}

node(x, l, r) {
	if(line >= MAXLIN) overflo();
	name[line] = x;
	left[line] = l;
	right[line] = r;
	parent[l] = line;
	parent[r] = line;
	return(line++);
}

unary(x, d) {
	if(line >= MAXLIN) overflo();
	name[line] = x;
	left[line] = d;
	right[line] = 0;
	parent[d] = line;
	return(line++);
}
overflo() {
	fprintf(stderr, "egrep: regular expression too long\n");
	exit(2);
}

cfoll(v) {
	register i;
	if (left[v] == 0) {
		count = 0;
		for (i=1; i<=line; i++) tmpstat[i] = 0;
		follow(v);
		add(foll, v);
	}
	else if (right[v] == 0) cfoll(left[v]);
	else {
		cfoll(left[v]);
		cfoll(right[v]);
	}
}
cgotofn() {
	register c, i, k;
	int n, s;
	char symbol[NCHARS];
	int j, nc, pc, pos;
	int curpos, num;
	int number, newpos;
	count = 0;
	for (n=3; n<=line; n++) tmpstat[n] = 0;
	if (cstate(line-1)==0) {
		tmpstat[line] = 1;
		count++;
		out[0] = 1;
	}
	for (n=3; n<=line; n++) initstat[n] = tmpstat[n];
	count--;		/*leave out position 1 */
	icount = count;
	tmpstat[1] = 0;
	add(state, 0);
	n = 0;
	for (s=0; s<=n; s++)  {
		if (out[s] == 1) continue;
		for (i=0; i<NCHARS; i++) symbol[i] = 0;
		num = positions[state[s]];
		count = icount;
		for (i=3; i<=line; i++) tmpstat[i] = initstat[i];
		pos = state[s] + 1;
		for (i=0; i<num; i++) {
			curpos = positions[pos];
			if ((c = name[curpos]) >= 0) {
				if (c < NCHARS) symbol[c] = 1;
				else if (c == DOT) {
					for (k=0; k<NCHARS; k++)
						if (k!='\n') symbol[k] = 1;
				}
				else if (c == CCL) {
					nc = chars[right[curpos]];
					pc = right[curpos] + 1;
					for (k=0; k<nc; k++) symbol[chars[pc++]] = 1;
				}
				else if (c == NCCL) {
					nc = chars[right[curpos]];
					for (j = 0; j < NCHARS; j++) {
						pc = right[curpos] + 1;
						for (k = 0; k < nc; k++)
							if (j==chars[pc++]) goto cont;
						if (j!='\n') symbol[j] = 1;
						cont:;
					}
				}
				else printf("something's funny\n");
			}
			pos++;
		}
		for (c=0; c<NCHARS; c++) {
			if (symbol[c] == 1) { /* nextstate(s,c) */
				count = icount;
				for (i=3; i <= line; i++) tmpstat[i] = initstat[i];
				pos = state[s] + 1;
				for (i=0; i<num; i++) {
					curpos = positions[pos];
					if ((k = name[curpos]) >= 0)
						if (
							(k == c)
							| (k == DOT)
							| (k == CCL && member(c, right[curpos], 1))
							| (k == NCCL && member(c, right[curpos], 0))
						) {
							number = positions[foll[curpos]];
							newpos = foll[curpos] + 1;
							for (k=0; k<number; k++) {
								if (tmpstat[positions[newpos]] != 1) {
									tmpstat[positions[newpos]] = 1;
									count++;
								}
								newpos++;
							}
						}
					pos++;
				} /* end nextstate */
				if (notin(n)) {
					if (n >= NSTATES) overflo();
					add(state, ++n);
					if (tmpstat[line] == 1) out[n] = 1;
					gotofn[s][c] = n;
				}
				else {
					gotofn[s][c] = xstate;
				}
			}
		}
	}
}

cstate(v) {
	register b;
	if (left[v] == 0) {
		if (tmpstat[v] != 1) {
			tmpstat[v] = 1;
			count++;
		}
		return(1);
	}
	else if (right[v] == 0) {
		if (cstate(left[v]) == 0) return (0);
		else if (name[v] == PLUS) return (1);
		else return (0);
	}
	else if (name[v] == CAT) {
		if (cstate(left[v]) == 0 && cstate(right[v]) == 0) return (0);
		else return (1);
	}
	else { /* name[v] == OR */
		b = cstate(right[v]);
		if (cstate(left[v]) == 0 || b == 0) return (0);
		else return (1);
	}
}


member(symb, set, torf) {
	register i, num, pos;
	num = chars[set];
	pos = set + 1;
	for (i=0; i<num; i++)
		if (symb == chars[pos++]) return (torf);
	return (!torf);
}

notin(n) {
	register i, j, pos;
	for (i=0; i<=n; i++) {
		if (positions[state[i]] == count) {
			pos = state[i] + 1;
			for (j=0; j < count; j++)
				if (tmpstat[positions[pos++]] != 1) goto nxt;
			xstate = i;
			return (0);
		}
		nxt: ;
	}
	return (1);
}

add(array, n) int *array; {
	register i;
	if (nxtpos + count > MAXPOS) overflo();
	array[n] = nxtpos;
	positions[nxtpos++] = count;
	for (i=3; i <= line; i++) {
		if (tmpstat[i] == 1) {
			positions[nxtpos++] = i;
		}
	}
}

follow(v) int v; {
	int p;
	if (v == line) return;
	p = parent[v];
	switch(name[p]) {
		case STAR:
		case PLUS:	cstate(v);
				follow(p);
				return;

		case OR:
		case QUEST:	follow(p);
				return;

		case CAT:	if (v == left[p]) {
					if (cstate(right[p]) == 0) {
						follow(p);
						return;
					}
				}
				else follow(p);
				return;
		case FINAL:	if (tmpstat[line] != 1) {
					tmpstat[line] = 1;
					count++;
				}
				return;
	}
}

iflag_ccl_prep()
{
	register int i;
	register u_char *p;

	for (p = chars, i = 'A'; i <= 'Z'; i++) {
		*p++ = 2;
		*p++ = i;
		*p++ = tolower(i);
	}
	nxtchar = p - chars;
}

main(argc, argv)
char **argv;
{
	while (--argc > 0 && (++argv)[0][0]=='-')
		switch (argv[0][1]) {

		case 's':
			sflag++;
			continue;

		case 'h':
			print_filenames = -1;
			continue;

		case 'o':	/* Berkeley */
		case 'H':	/* compat with "modern" systems */
			print_filenames = 1;
			continue;

		case 'b':
			bflag++;
			continue;

		case 'c':
			cflag++;
			continue;

		case 'e':
			argc--;
			argv++;
			goto out;

		case 'f':
			fflag++;
			continue;

		case 'i':	/* Berkeley */
		case 'y':	/* BTL */
			iflag++;
			iflag_ccl_prep();
			continue;

		case 'l':
			lflag++;
			continue;

		case 'n':
			nflag++;
			continue;

		case 'v':
			vflag++;
			continue;

		/*
		 * the semantics of -r vs -R have been chosen
		 * to match Gunnar Ritter's "Heirloom" version
		 */

		case 'r':
			recurse_symlinks++;
			/* FALL THRU */
		case 'R':
			recurse_flag++;
			continue;

		default:
			fprintf(stderr, "egrep: unknown flag\n");
			continue;
		}
out:
	if (argc<=0)
		exit(2);
	if (fflag) {
		fname = *argv;
		exprfile = fopen(fname, "r");
		if (exprfile == (FILE *)NULL) {
			fprintf(stderr, "egrep: can't open %s\n", fname);
			exit(2);
		}
	}
	else input = (u_char *) *argv;
	argc--;
	argv++;

	yyparse();

	cfoll(line-1);
	cgotofn();
	if (argc > 1 || recurse_flag)
		print_filenames++;
	if (argc<=0) {
		if (lflag) exit(1);
		print_filenames = 0;
		execute(0);
	}
	else while (--argc >= 0) {
		if (recurse_flag)
			recurse(*argv, 1);
		else
			execute(*argv);
		argv++;
	}
	exit(retcode != 0 ? retcode : nsucc == 0);
}

execute(file)
char *file;
{
	register u_char *p;
	register cstat;
	register ccount;
	static u_char *buf;
	static int blksize;
	struct stat stb;
	u_char *nlp;
	int istat;
	if (file) {
		if ((f = open(file, 0)) < 0) {
			fprintf(stderr, "egrep: can't open %s\n", file);
			retcode = 2;
			return;
		}
	}
	else f = 0;
	if (buf == NULL) {
		if (fstat(f, &stb) > 0 && stb.st_blksize > 0)
			blksize = stb.st_blksize;
		else
			blksize = BLKSIZE;
		buf = (u_char *)malloc(2*blksize);
		if (buf == NULL) {
			fprintf(stderr, "egrep: no memory for %s\n", file);
			retcode = 2;
			return;
		}
	}
	ccount = 0;
	lnum = 1;
	tln = 0;
	blkno = 0;
	p = buf;
	nlp = p;
	if ((ccount = read(f,p,blksize))<=0) goto done;
	istat = cstat = gotofn[0]['\n'];
	if (out[cstat]) goto found;
	for (;;) {
		cstat = gotofn[cstat][*p];
		if (out[cstat]) {
		found:	for(;;) {
				if (*p++ == '\n') {
					if (vflag == 0) {
				succeed:	nsucc = 1;
						if (cflag) tln++;
						else if (sflag)
							;	/* ugh */
						else if (lflag) {
							printf("%s\n", file);
							close(f);
							return;
						}
						else {
							if (print_filenames > 0) printf("%s:", file);
							if (bflag) printf("%ld:", (blkno-ccount-1)/DEV_BSIZE);
							if (nflag) printf("%ld:", lnum);
							if (p <= nlp) {
								while (nlp < &buf[2*blksize]) putchar(*nlp++);
								nlp = buf;
							}
							while (nlp < p) putchar(*nlp++);
						}
					}
					lnum++;
					nlp = p;
					if ((out[(cstat=istat)]) == 0) goto brk2;
				}
				cfound:
				if (--ccount <= 0) {
					if (p <= &buf[blksize]) {
						if ((ccount = read(f, p, blksize)) <= 0) goto done;
					}
					else if (p == &buf[2*blksize]) {
						p = buf;
						if ((ccount = read(f, p, blksize)) <= 0) goto done;
					}
					else {
						if ((ccount = read(f, p, &buf[2*blksize]-p)) <= 0) goto done;
					}
					blkno += ccount;
				}
			}
		}
		if (*p++ == '\n') {
			if (vflag) goto succeed;
			else {
				lnum++;
				nlp = p;
				if (out[(cstat=istat)]) goto cfound;
			}
		}
		brk2:
		if (--ccount <= 0) {
			if (p <= &buf[blksize]) {
				if ((ccount = read(f, p, blksize)) <= 0) break;
			}
			else if (p == &buf[2*blksize]) {
				p = buf;
				if ((ccount = read(f, p, blksize)) <= 0) break;
			}
			else {
				if ((ccount = read(f, p, &buf[2*blksize] - p)) <= 0) break;
			}
			blkno += ccount;
		}
	}
done:	close(f);
	if (cflag) {
		if (print_filenames > 0)
			printf("%s:", file);
		printf("%ld\n", tln);
	}
}
short yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
	};
# define YYNPROD 18
# define YYLAST 261
short yyact[]={

  10,  22,   4,  14,  11,   2,   1,   5,   0,   0,
  10,  15,  16,  17,  18,   0,  19,  20,   3,   0,
  10,   0,   0,  12,   0,  20,   0,  20,   0,   0,
  10,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  10,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  11,   6,   7,   8,
   9,  21,   0,  15,  16,  17,  11,   6,   7,   8,
   9,  23,   0,  15,  16,  17,  11,   6,   7,   8,
   9,  13,   0,  15,  16,  17,  11,   6,   7,   8,
   9,   0,   0,  15,  16,  17,  11,   6,   7,   8,
   9 };
short yypact[]={

-259,-1000,-1000,   0,-1000, -20,-1000,-1000,-1000,-1000,
   0,-1000,   0,   0,-252,-1000,-1000,-1000, -40, -30,
 -10,   0,-1000,   0 };
short yypgo[]={

   0,   6,   5,  18,   3 };
short yyr1[]={

   0,   1,   2,   2,   2,   2,   3,   4,   4,   4,
   4,   4,   4,   4,   4,   4,   4,   4 };
short yyr2[]={

   0,   1,   2,   4,   3,   3,   0,   1,   1,   1,
   1,   3,   2,   2,   2,   2,   3,   1 };
short yychk[]={

-1000,  -1,  -2,  -3, 261,  -4, 257, 258, 259, 260,
  40, 256,  -3, 261,  -4, 263, 264, 265,  -4,  -4,
  -4, 261,  41, 261 };
short yydef[]={

   6,  -2,   1,   0,   6,   2,   7,   8,   9,  10,
   0,  17,   0,   5,  12,  13,  14,  15,   0,   4,
  11,   0,  16,   3 };
#ifndef lint
static char yaccpar_sccsid[] = "@(#)yaccpar	4.1	(Berkeley)	2/11/83";
#endif not lint

#
# define YYFLAG -1000
# define YYERROR goto yyerrlab
# define YYACCEPT return(0)
# define YYABORT return(1)

/*	parser for yacc output	*/

#ifdef YYDEBUG
int yydebug = 0; /* 1 for debugging */
#endif
YYSTYPE yyv[YYMAXDEPTH]; /* where the values are stored */
int yychar = -1; /* current input token number */
int yynerrs = 0;  /* number of errors */
short yyerrflag = 0;  /* error recovery flag */

yyparse() {

	short yys[YYMAXDEPTH];
	short yyj, yym;
	register YYSTYPE *yypvt;
	register short yystate, *yyps, yyn;
	register YYSTYPE *yypv;
	register short *yyxi;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyps= &yys[-1];
	yypv= &yyv[-1];

 yystack:    /* put a state and value onto the stack */

#ifdef YYDEBUG
	if( yydebug  ) printf( "state %d, char 0%o\n", yystate, yychar );
#endif
		if( ++yyps> &yys[YYMAXDEPTH] ) { yyerror( "yacc stack overflow" ); return(1); }
		*yyps = yystate;
		++yypv;
		*yypv = yyval;

 yynewstate:

	yyn = yypact[yystate];

	if( yyn<= YYFLAG ) goto yydefault; /* simple state */

	if( yychar<0 ) if( (yychar=yylex())<0 ) yychar=0;
	if( (yyn += yychar)<0 || yyn >= YYLAST ) goto yydefault;

	if( yychk[ yyn=yyact[ yyn ] ] == yychar ){ /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if( yyerrflag > 0 ) --yyerrflag;
		goto yystack;
		}

 yydefault:
	/* default state action */

	if( (yyn=yydef[yystate]) == -2 ) {
		if( yychar<0 ) if( (yychar=yylex())<0 ) yychar = 0;
		/* look through exception table */

		for( yyxi=yyexca; (*yyxi!= (-1)) || (yyxi[1]!=yystate) ; yyxi += 2 ) ; /* VOID */

		while( *(yyxi+=2) >= 0 ){
			if( *yyxi == yychar ) break;
			}
		if( (yyn = yyxi[1]) < 0 ) return(0);   /* accept */
		}

	if( yyn == 0 ){ /* error */
		/* error ... attempt to resume parsing */

		switch( yyerrflag ){

		case 0:   /* brand new error */

			yyerror( "syntax error" );
		yyerrlab:
			++yynerrs;

		case 1:
		case 2: /* incompletely recovered error ... try again */

			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */

			while ( yyps >= yys ) {
			   yyn = yypact[*yyps] + YYERRCODE;
			   if( yyn>= 0 && yyn < YYLAST && yychk[yyact[yyn]] == YYERRCODE ){
			      yystate = yyact[yyn];  /* simulate a shift of "error" */
			      goto yystack;
			      }
			   yyn = yypact[*yyps];

			   /* the current yyps has no shift onn "error", pop stack */

#ifdef YYDEBUG
			   if( yydebug ) printf( "error recovery pops state %d, uncovers %d\n", *yyps, yyps[-1] );
#endif
			   --yyps;
			   --yypv;
			   }

			/* there is no state on the stack with an error shift ... abort */

	yyabort:
			return(1);


		case 3:  /* no shift yet; clobber input char */

#ifdef YYDEBUG
			if( yydebug ) printf( "error recovery discards char %d\n", yychar );
#endif

			if( yychar == 0 ) goto yyabort; /* don't discard EOF, quit */
			yychar = -1;
			goto yynewstate;   /* try again in the same state */

			}

		}

	/* reduction by production yyn */

#ifdef YYDEBUG
		if( yydebug ) printf("reduce %d\n",yyn);
#endif
		yyps -= yyr2[yyn];
		yypvt = yypv;
		yypv -= yyr2[yyn];
		yyval = yypv[1];
		yym=yyn;
			/* consult goto table to find next state */
		yyn = yyr1[yyn];
		yyj = yypgo[yyn] + *yyps + 1;
		if( yyj>=YYLAST || yychk[ yystate = yyact[yyj] ] != -yyn ) yystate = yyact[yypgo[yyn]];
		switch(yym){
			
case 1:
# line 75 "egrep.y"
{ unary(FINAL, yypvt[-0]);
		  line--;
		} break;
case 2:
# line 80 "egrep.y"
{ yyval = node(CAT, yypvt[-1], yypvt[-0]); } break;
case 3:
# line 82 "egrep.y"
{ yyval = node(CAT, yypvt[-2], yypvt[-1]); } break;
case 4:
# line 84 "egrep.y"
{ yyval = node(CAT, yypvt[-1], yypvt[-0]); } break;
case 5:
# line 86 "egrep.y"
{ yyval = node(CAT, yypvt[-2], yypvt[-1]); } break;
case 6:
# line 89 "egrep.y"
{ yyval = enter(DOT);
		   yyval = unary(STAR, yyval); } break;
case 7:
# line 93 "egrep.y"
{ yyval = enter(yypvt[-0]); } break;
case 8:
# line 95 "egrep.y"
{ yyval = enter(DOT); } break;
case 9:
# line 97 "egrep.y"
{ yyval = cclenter(CCL); } break;
case 10:
# line 99 "egrep.y"
{ yyval = cclenter(NCCL); } break;
case 11:
# line 103 "egrep.y"
{ yyval = node(OR, yypvt[-2], yypvt[-0]); } break;
case 12:
# line 105 "egrep.y"
{ yyval = node(CAT, yypvt[-1], yypvt[-0]); } break;
case 13:
# line 107 "egrep.y"
{ yyval = unary(STAR, yypvt[-1]); } break;
case 14:
# line 109 "egrep.y"
{ yyval = unary(PLUS, yypvt[-1]); } break;
case 15:
# line 111 "egrep.y"
{ yyval = unary(QUEST, yypvt[-1]); } break;
case 16:
# line 113 "egrep.y"
{ yyval = yypvt[-1]; } break;
		}
		goto yystack;  /* stack new state and value */

	}
