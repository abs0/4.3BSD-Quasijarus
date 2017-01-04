h46266
s 00009/00001/01289
d D 2.15 87/12/10 00:42:57 donn 23 22
c utah rcsid 1.14 87/11/26 16:30:10: Make all ordinary floating constants
c have type double, like ANSI.  Also like ANSI, permit 'f' or 'F' suffix on
c floating constants to indicate a float type constant.
e
s 00025/00008/01265
d D 2.14 87/12/10 00:42:47 donn 22 21
c utah rcsid 1.13 87/07/10 23:44:34: (1) Added lint warning about superfluous
c backslashes in char or string constants.  (2) Made '$' in identifiers
c dependent on 'VMS'.  (3) Made gcos BCD constants completely dependent on
c 'gcos'.  (4) Caused yylex() to loop rather than punt when it sees a funny
c character.
e
s 00007/00001/01266
d D 2.13 87/12/10 00:42:37 donn 21 20
c utah rcsid 1.12 87/07/06 15:49:59: Don't lose track of string boundaries
c after a syntax error -- yylex() checks for broken strings and eats them
c with lxstr().
e
s 00009/00005/01258
d D 2.12 87/12/10 00:42:26 donn 20 19
c utah rcsid 1.11 87/01/15 02:11:51: Some minor lint fixes.
e
s 00001/00001/01262
d D 2.11 87/12/10 00:42:16 donn 19 18
c utah rcsid 1.10 86/11/27 19:18:46: Update for ucb sid 2.2 -- 'move release
c definition to external file' (sam).
e
s 00016/00001/01247
d D 2.10 87/12/10 00:42:06 donn 18 17
c utah rcsid 1.9 86/09/18 18:51:36: Be a little nicer about illegal character
c errors...
e
s 00014/00004/01234
d D 2.9 87/12/10 00:41:56 donn 17 16
c utah rcsid 1.8 86/08/14 21:59:59: Pick up #line control lines and convert
c them to ordinary # lines.
e
s 00082/00001/01156
d D 2.8 87/12/10 00:41:46 donn 16 15
c utah rcsid 1.7 86/08/14 21:13:58: Add support for #ident and #pragma.
e
s 00002/00000/01155
d D 2.7 87/12/10 00:41:37 donn 15 14
c utah rcsid 1.6 86/08/03 01:32:40: Eliminate silly 'unreachable code'
c warning created by ifdeffing out the stuff for old-style assignment
c operators...
e
s 00001/00001/01154
d D 2.6 87/12/10 00:41:29 donn 14 13
c utah rcsid 1.5 86/08/03 01:06:34: Don't emit line number symbols after
c errors.
e
s 00003/00013/01152
d D 2.5 87/12/10 00:41:17 donn 13 12
c utah rcsid 1.4 86/07/11 14:02:11: Old-style (=+, =- etc.) assignment
c operators are ifdef'ed out.  No more 'ambiguous assignment: assignment op
c taken' messages!
e
s 00006/00000/01159
d D 2.4 87/04/22 15:09:42 bostic 12 11
c bug report 4.3BSD/usr.bin/51
e
s 00006/00000/01153
d D 2.3 87/04/22 11:13:48 bostic 11 10
c bug report 4.3BSD/lib/54
e
s 00001/00001/01152
d D 2.2 86/10/15 22:03:50 sam 10 9
c move release definition to external file
e
s 00001/00001/01152
d D 2.1 86/04/23 19:44:17 mckusick 9 8
c raise rev level; more reasonable release string
e
s 00001/00001/01152
d D 1.8 86/04/23 18:38:42 mckusick 8 7
c update the release string
e
s 00007/00000/01146
d D 1.7 85/08/22 19:08:18 mckusick 7 6
c update from donn@utah-cs
e
s 00001/00001/01145
d D 1.6 85/03/19 13:09:47 ralph 6 5
c use common header file for C, Fortran, Pascal.
e
s 00012/00003/01134
d D 1.5 85/01/18 16:15:29 ralph 5 4
c changes for single precision floats; lint cleanups
e
s 00002/00002/01135
d D 1.4 85/01/02 09:31:08 ralph 4 3
c init lineno before lxtitle is called so its not reinitialized.
e
s 00001/00001/01136
d D 1.3 82/12/24 18:21:39 sam 3 2
c cleanup after mark (broke lint)
e
s 00005/00000/01132
d D 1.2 82/12/18 11:37:13 linton 2 1
c added "-XG" flag for old sdb style symbol information
e
s 01132/00000/00000
d D 1.1 82/12/17 23:51:37 linton 1 0
c date and time created 82/12/17 23:51:37 by linton
e
u
U
t
T
I 5
#ifndef lint
E 5
I 1
static char *sccsid ="%W% (Berkeley) %G%";
I 5
#endif lint

E 5
D 6
# include "mfile1"
E 6
I 6
# include "pass1.h"
E 6
# include <a.out.h>
# include <stab.h>
# include <ctype.h>
I 7
# include <signal.h>

E 7
	/* temporarily */

int asm_esc = 0; /* asm escaped used in file */
	/* lexical actions */

# define A_ERR 0		/* illegal character */
# define A_LET 1		/* saw a letter */
# define A_DIG 2		/* saw a digit */
# define A_1C 3			/* return a single character */
# define A_STR 4		/* string */
# define A_CC 5			/* character constant */
# define A_BCD 6		/* GCOS BCD constant */
# define A_SL 7			/* saw a / */
# define A_DOT 8		/* saw a . */
# define A_PL 9		/* + */
# define A_MI 10		/* - */
# define A_EQ 11		/* = */
# define A_NOT 12		/* ! */
# define A_LT 13		/* < */
# define A_GT 14		/* > */
# define A_AND 16		/* & */
# define A_OR 17		/* | */
# define A_WS 18		/* whitespace (not \n) */
# define A_NL 19		/* \n */

	/* character classes */

# define LEXLET 01
# define LEXDIG 02
# define LEXOCT 04
# define LEXHEX 010
# define LEXWS 020
# define LEXDOT 040

	/* reserved word actions */

# define AR_TY 0		/* type word */
# define AR_RW 1		/* simple reserved word */
# define AR_CL 2		/* storage class word */
# define AR_S 3		/* struct */
# define AR_U 4		/* union */
# define AR_E 5		/* enum */
# define AR_A 6		/* asm */

	/* text buffer */
#ifndef FLEXNAMES
# define LXTSZ 100
#else
#define	LXTSZ	BUFSIZ
#endif
char yytext[LXTSZ];
char * lxgcp;

extern int proflg;
extern int gdebug;
I 7
extern int fpe();
struct sigvec fpe_sigvec;
E 7
I 2
D 3
extern int oldway;
E 3
I 3
int oldway;		/* allocate storage so lint will compile as well */
E 3
E 2
#ifndef LINT
extern int lastloc;
#endif

unsigned caloff();
	/* ARGSUSED */
mainp1( argc, argv ) int argc; char *argv[]; {  /* control multiple files */

	register i;
	register char *cp;
D 5
	extern int idebug, bdebug, tdebug, edebug, ddebug, xdebug, gdebug;
E 5
I 5
	extern int idebug, bdebug, tdebug, edebug;
	extern int ddebug, xdebug, gdebug, adebug;
E 5
	extern unsigned int offsz;
	int fdef = 0;
D 8
	char *release = "PCC/364r1 vax uts3.0";
E 8
I 8
D 9
	char *release = "PCC/%W% (Berkeley) %G%";
E 9
I 9
D 10
	char *release = "PCC/%I% (Berkeley) %G%";
E 10
I 10
D 13
	extern char *release;
E 13
I 13
D 19
	char *release = "PCC/364r1 vax uts3.0";
E 19
I 19
	extern char *release;
E 19
E 13
E 10
E 9
E 8

	offsz = caloff();
	for( i=1; i<argc; ++i ){
		if( *(cp=argv[i]) == '-' && *++cp == 'X' ){
			while( *++cp ){
				switch( *cp ){

				case 'r':
					fprintf( stderr, "Release: %s\n",
						release );
					break;

				case 'd':
					++ddebug;
					break;
				case 'i':
					++idebug;
					break;
				case 'b':
					++bdebug;
					break;
				case 't':
					++tdebug;
					break;
				case 'e':
					++edebug;
					break;
				case 'x':
					++xdebug;
					break;
				case 'P':	/* profiling */
					++proflg;
					break;
				case 'g':
					++gdebug;
I 2
					break;
I 5
				case 'a':
					++adebug;
					break;
E 5
				case 'G':
					++gdebug;
					oldway = 1;
E 2
					break;
					}
				}
			}
			else {
			if( *(argv[i]) != '-' ) switch( fdef++ ) {
				case 0:
				case 1:
					if( freopen(argv[i], fdef==1 ? "r" : "w", fdef==1 ? stdin : stdout) == NULL) {
						fprintf(stderr, "ccom:can't open %s\n", argv[i]);
						exit(1);
					}
					break;

				default:
					;
				}
			}
		}

# ifdef ONEPASS
D 20
	p2init( argc, argv );
E 20
I 20
	(void) p2init( argc, argv );
E 20
# endif

	for( i=0; i<SYMTSZ; ++i ) stab[i].stype = TNULL;

I 4
	lineno = 1;

E 4
	lxinit();
	tinit();
	mkdope();
D 4

	lineno = 1;
E 4

	/* dimension table initialization */

	dimtab[NULL] = 0;
	dimtab[CHAR] = SZCHAR;
	dimtab[INT] = SZINT;
	dimtab[FLOAT] = SZFLOAT;
	dimtab[DOUBLE] = SZDOUBLE;
	dimtab[LONG] = SZLONG;
	dimtab[SHORT] = SZSHORT;
	dimtab[UCHAR] = SZCHAR;
	dimtab[USHORT] = SZSHORT;
	dimtab[UNSIGNED] = SZINT;
	dimtab[ULONG] = SZLONG;
	/* starts past any of the above */
	curdim = 16;
	reached = 1;
I 7

	fpe_sigvec.sv_handler = fpe;
	(void) sigvec(SIGFPE, &fpe_sigvec, (struct sigvec *) NULL);
E 7

D 20
	yyparse();
E 20
I 20
	(void) yyparse();
E 20
	yyaccpt();

	ejobcode( nerrors ? 1 : 0 );
	return(nerrors?1:0);

	}

# ifdef ibm

# define CSMASK 0377
# define CSSZ 256

# else

# define CSMASK 0177
# define CSSZ 128

# endif

short lxmask[CSSZ+1];

lxenter( s, m ) register char *s; register short m; {
	/* enter a mask into lxmask */
	register c;

	while( c= *s++ ) lxmask[c+1] |= m;

	}


# define lxget(c,m) (lxgcp=yytext,lxmore(c,m))

lxmore( c, m )  register c, m; {
	register char *cp;

	*(cp = lxgcp) = c;
	while( c=getchar(), lxmask[c+1]&m ){
		if( cp < &yytext[LXTSZ-1] ){
			*++cp = c;
			}
		}
	ungetc(c,stdin);
	*(lxgcp = cp+1) = '\0';
	}

struct lxdope {
	short lxch;	/* the character */
	short lxact;	/* the action to be performed */
	short lxtok;	/* the token number to be returned */
	short lxval;	/* the value to be returned */
	} lxdope[] = {

	'@',	A_ERR,	0,	0,	/* illegal characters go here... */
	'_',	A_LET,	0,	0,	/* letters point here */
	'0',	A_DIG,	0,	0,	/* digits point here */
	' ',	A_WS,	0,	0,	/* whitespace goes here */
	'\n',	A_NL,	0,	0,
	'"',	A_STR,	0,	0,	/* character string */
	'\'',	A_CC,	0,	0,	/* character constant */
I 22
#ifdef gcos
E 22
	'`',	A_BCD,	0,	0,	/* GCOS BCD constant */
I 22
#endif
E 22
	'(',	A_1C,	LP,	0,
	')',	A_1C,	RP,	0,
	'{',	A_1C,	LC,	0,
	'}',	A_1C,	RC,	0,
	'[',	A_1C,	LB,	0,
	']',	A_1C,	RB,	0,
	'*',	A_1C,	MUL,	MUL,
	'?',	A_1C,	QUEST,	0,
	':',	A_1C,	COLON,	0,
	'+',	A_PL,	PLUS,	PLUS,
	'-',	A_MI,	MINUS,	MINUS,
	'/',	A_SL,	DIVOP,	DIV,
	'%',	A_1C,	DIVOP,	MOD,
	'&',	A_AND,	AND,	AND,
	'|',	A_OR,	OR,	OR,
	'^',	A_1C,	ER,	ER,
	'!',	A_NOT,	UNOP,	NOT,
	'~',	A_1C,	UNOP,	COMPL,
	',',	A_1C,	CM,	CM,
	';',	A_1C,	SM,	0,
	'.',	A_DOT,	STROP,	DOT,
	'<',	A_LT,	RELOP,	LT,
	'>',	A_GT,	RELOP,	GT,
	'=',	A_EQ,	ASSIGN,	ASSIGN,
	-1,	A_1C,	0,	0,
	};

struct lxdope *lxcp[CSSZ+1];

lxinit(){
	register struct lxdope *p;
	register i;
	register char *cp;
	/* set up character classes */

D 22
	lxenter( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_$", LEXLET );
E 22
I 22
	lxenter( "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_", LEXLET );
#ifdef VMS
	lxmask['$'+1] |= LEXLET;
#endif
E 22
	lxenter( "0123456789", LEXDIG );
	lxenter( "0123456789abcdefABCDEF", LEXHEX );
D 22
		/* \013 should become \v someday; \013 is OK for ASCII and EBCDIC */
	lxenter( " \t\r\b\f\013", LEXWS );
E 22
I 22
	lxenter( " \t\r\b\f\v", LEXWS );
E 22
	lxenter( "01234567", LEXOCT );
	lxmask['.'+1] |= LEXDOT;

	/* make lxcp point to appropriate lxdope entry for each character */

	/* initialize error entries */

	for( i= 0; i<=CSSZ; ++i ) lxcp[i] = lxdope;

	/* make unique entries */

	for( p=lxdope; ; ++p ) {
		lxcp[p->lxch+1] = p;
		if( p->lxch < 0 ) break;
		}

	/* handle letters, digits, and whitespace */
	/* by convention, first, second, and third places */

D 22
	cp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ$";
E 22
I 22
	cp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
E 22
	while( *cp ) lxcp[*cp++ + 1] = &lxdope[1];
I 22
#ifdef VMS
	lxcp['$'+1] = &lxdope[1];
#endif
E 22
	cp = "123456789";
	while( *cp ) lxcp[*cp++ + 1] = &lxdope[2];
D 22
	cp = "\t\b\r\f\013";
E 22
I 22
	cp = "\t\b\r\f\v";
E 22
	while( *cp ) lxcp[*cp++ + 1] = &lxdope[3];

	/* first line might have title */
	lxtitle();

	}

D 21
int lxmatch;  /* character to be matched in char or string constant */
E 21
I 21
int lxmatch = 0;  /* character to be matched in char or string constant */
E 21

lxstr(ct){
	/* match a string or character constant, up to lxmatch */

	register c;
	register val;
	register i;

	i=0;
	while( (c=getchar()) != lxmatch ){
		switch( c ) {

		case EOF:
			uerror( "unexpected EOF" );
			break;

		case '\n':
			uerror( "newline in string or char constant" );
			++lineno;
			break;

		case '\\':
			switch( c = getchar() ){

			case '\n':
				++lineno;
				continue;

			default:
I 22
#ifdef LINT
				if( hflag )
					uerror( "superfluous backslash in %s constant", lxmatch == '\'' ? "char" : "string" );
				/*FALLTHROUGH*/
#endif
			case '\\':
			case '\"':
			case '\'':
E 22
I 11
D 13
				if (hflag)
					uerror("superfluous backslash in string/character constant");
				/*FALLTHROUGH*/
			case '\\':
			case '\"':
			case '\'':
E 13
E 11
				val = c;
				goto mkcc;

			case 'n':
				val = '\n';
				goto mkcc;

			case 'r':
				val = '\r';
				goto mkcc;

			case 'b':
				val = '\b';
				goto mkcc;

			case 't':
				val = '\t';
				goto mkcc;

			case 'f':
				val = '\f';
				goto mkcc;

			case 'v':
D 22
				val = '\013';
E 22
I 22
				val = '\v';
E 22
				goto mkcc;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
				val = c-'0';
				c=getchar();  /* try for 2 */
				if( lxmask[c+1] & LEXOCT ){
					val = (val<<3) | (c-'0');
					c = getchar();  /* try for 3 */
					if( lxmask[c+1] & LEXOCT ){
						val = (val<<3) | (c-'0');
						}
					else ungetc( c ,stdin);
					}
				else ungetc( c ,stdin);

				goto mkcc1;

				}
		default:
			val =c;
		mkcc:
			val = CCTRANS(val);
		mkcc1:
			if( lxmatch == '\'' ){
				val = CHARCAST(val);  /* it is, after all, a "character" constant */
				makecc( val, i );
				}
			else { /* stash the byte into the string */
				if( strflg ) {
					if( ct==0 || i<ct ) putbyte( val );
					else if( i == ct ) werror( "non-null byte ignored in string initializer" );
					}
				else bycode( val, i );
				}
			++i;
			continue;
			}
		break;
		}
	/* end of string or  char constant */

	if( lxmatch == '"' ){
		if( strflg ){ /* end the string */
			if( ct==0 || i<ct ) putbyte( 0 );  /* the null at the end */
			}
		else {  /* the initializer gets a null byte */
			bycode( 0, i++ );
			bycode( -1, i );
			dimtab[curdim] = i;  /* in case of later sizeof ... */
			}
		}
	else { /* end the character constant */
		if( i == 0 ) uerror( "empty character constant" );
		if( i>(SZINT/SZCHAR) || ( (pflag||hflag)&&i>1) )
			uerror( "too many characters in character constant" );
		}
I 21
	lxmatch = 0;	/* handshake with yylex() */
E 21
	}

lxcom(){
	register c;
	/* saw a /*: process a comment */

	for(;;){

		switch( c = getchar() ){

		case EOF:
			uerror( "unexpected EOF" );
			return;

		case '\n':
			++lineno;

		default:
			continue;

		case '*':
			if( (c = getchar()) == '/' ) return;
			else ungetc( c ,stdin);
			continue;

# ifdef LINT
		case 'V':
			lxget( c, LEXLET|LEXDIG );
			{
				extern int vaflag;
				int i;
				i = yytext[7]?yytext[7]-'0':0;
				yytext[7] = '\0';
				if( strcmp( yytext, "VARARGS" ) ) continue;
				vaflag = i;
				continue;
				}
		case 'L':
			lxget( c, LEXLET );
			if( strcmp( yytext, "LINTLIBRARY" ) ) continue;
			{
				extern int libflag;
				libflag = 1;
				}
			continue;

		case 'A':
			lxget( c, LEXLET );
			if( strcmp( yytext, "ARGSUSED" ) ) continue;
			{
				extern int argflag, vflag;
				argflag = 1;
				vflag = 0;
				}
			continue;

		case 'N':
			lxget( c, LEXLET );
			if( strcmp( yytext, "NOTREACHED" ) ) continue;
			reached = 0;
			continue;
# endif
			}
		}
	}

yylex(){
I 23
	double atof();

E 23
I 21
	if (lxmatch != 0) {
		/* recover from a syntax error that consumes a STRING token */
		strflg = 1;
		lxstr(0);
	}
E 21
	for(;;){

		register lxchar;
		register struct lxdope *p;
		register struct symtab *sp;
		int id;
I 18
		char *s;
		static char sc[5];
E 18

		switch( (p=lxcp[(lxchar=getchar())+1])->lxact ){

		onechar:
			ungetc( lxchar ,stdin);

		case A_1C:
			/* eat up a single character, and return an opcode */

			yylval.intval = p->lxval;
			return( p->lxtok );

		case A_ERR:
D 18
			uerror( "illegal character: %03o (octal)", lxchar );
E 18
I 18
			switch( lxchar ){
			case '\\':	s = "\\\\"; break;
			case '\0':	s = "\\0"; break;
			default:
				if( isgraph( lxchar ) ){
					sc[0] = lxchar;
					sc[1] = '\0';
					}
				else
					sprintf( sc, "\\%03.3o", (unsigned char) lxchar );
				s = sc;
				break;
				}
			uerror( "illegal character: '%s'", s );
E 18
D 22
			break;
E 22
I 22
			continue; /* ignore it and see if we find more */
E 22

		case A_LET:
			/* collect an identifier, check for reserved word, and return */
			lxget( lxchar, LEXLET|LEXDIG );
			if( (lxchar=lxres()) > 0 ) return( lxchar ); /* reserved word */
			if( lxchar== 0 ) continue;
#ifdef FLEXNAMES
			id = lookup( hash(yytext),
#else
			id = lookup( yytext,
#endif
				/* tag name for struct/union/enum */
				(stwart&TAGNAME)? STAG:
				/* member name for struct/union */
				(stwart&(INSTRUCT|INUNION|FUNNYNAME))?SMOS:0 );
			sp = &stab[id];
			if( sp->sclass == TYPEDEF && !stwart ){
				stwart = instruct;
				yylval.nodep = mkty( sp->stype, sp->dimoff, sp->sizoff );
				return( TYPE );
				}
			stwart = (stwart&SEENAME) ? instruct : 0;
			yylval.intval = id;
			return( NAME );

		case A_DIG:
			/* collect a digit string, then look at last one... */
			lastcon = 0;
			lxget( lxchar, LEXDIG );
			switch( lxchar=getchar() ){

			case 'x':
			case 'X':
				if( yytext[0] != '0' && !yytext[1] ) uerror( "illegal hex constant" );
				lxmore( lxchar, LEXHEX );
				/* convert the value */
				{
					register char *cp;
					for( cp = yytext+2; *cp; ++cp ){
						/* this code won't work for all wild character sets,
						   but seems ok for ascii and ebcdic */
						lastcon <<= 4;
						if( isdigit( *cp ) ) lastcon += *cp-'0';
						else if( isupper( *cp ) ) lastcon += *cp - 'A'+ 10;
						else lastcon += *cp - 'a'+ 10;
						}
					}

			hexlong:
				/* criterion for longness for hex and octal constants is that it
				   fit within 0177777 */
				if( lastcon & ~0177777L ) yylval.intval = 1;
				else yylval.intval = 0;

				goto islong;

			case '.':
				lxmore( lxchar, LEXDIG );

			getfp:
				if( (lxchar=getchar()) == 'e' || lxchar == 'E' ){ /* exponent */

			case 'e':
			case 'E':
					if( (lxchar=getchar()) == '+' || lxchar == '-' ){
						*lxgcp++ = 'e';
						}
					else {
						ungetc(lxchar,stdin);
						lxchar = 'e';
						}
					lxmore( lxchar, LEXDIG );
					/* now have the whole thing... */
					}
				else {  /* no exponent */
					ungetc( lxchar ,stdin);
					}
D 23
				return( isitfloat( yytext ) );
E 23
I 23
				dcon = atof( yytext );
				if( (lxchar = getchar()) == 'F' || lxchar == 'f' ){
					fcon = dcon;
					return( FCON );
					}
				else ungetc( lxchar ,stdin);
				return( DCON );
E 23

			default:
				ungetc( lxchar ,stdin);
				if( yytext[0] == '0' ){
					/* convert in octal */
					register char *cp;
					for( cp = yytext+1; *cp; ++cp ){
						lastcon <<= 3;
						lastcon += *cp - '0';
						}
					goto hexlong;
					}
				else {
					/* convert in decimal */
					register char *cp;
					for( cp = yytext; *cp; ++cp ){
						lastcon = lastcon * 10 + *cp - '0';
						}
					}

				/* decide if it is long or not (decimal case) */

				/* if it is positive and fits in 15 bits, or negative and
				   and fits in 15 bits plus an extended sign, it is int; otherwise long */
				/* if there is an l or L following, all bets are off... */

				{	CONSZ v;
					v = lastcon & ~077777L;
					if( v == 0 || v == ~077777L ) yylval.intval = 0;
					else yylval.intval = 1;
					}

			islong:
				/* finally, look for trailing L or l */
				if( (lxchar = getchar()) == 'L' || lxchar == 'l' ) yylval.intval = 1;
				else ungetc( lxchar ,stdin);
				return( ICON );
				}

		case A_DOT:
			/* look for a dot: if followed by a digit, floating point */
			lxchar = getchar();
			if( lxmask[lxchar+1] & LEXDIG ){
				ungetc(lxchar,stdin);
				lxget( '.', LEXDIG );
				goto getfp;
				}
			stwart = FUNNYNAME;
			goto onechar;

		case A_STR:
			/* string constant */
			lxmatch = '"';
			return( STRING );

		case A_CC:
			/* character constant */
			lxmatch = '\'';
			lastcon = 0;
			lxstr(0);
			yylval.intval = 0;
			return( ICON );

I 22
#ifdef gcos
E 22
		case A_BCD:
			{
				register i;
				int j;
				for( i=0; i<LXTSZ; ++i ){
					if( ( j = getchar() ) == '`' ) break;
					if( j == '\n' ){
						uerror( "newline in BCD constant" );
						break;
						}
					yytext[i] = j;
					}
				yytext[i] = '\0';
				if( i>6 ) uerror( "BCD constant exceeds 6 characters" );
D 22
# ifdef gcos
E 22
I 22
# ifndef unix
E 22
				else strtob( yytext, &lastcon, i );
				lastcon >>= 6*(6-i);
# else
				uerror( "gcos BCD constant illegal" );
# endif
				yylval.intval = 0;  /* not long */
				return( ICON );
				}
I 22
#endif
E 22

		case A_SL:
			/* / */
			if( (lxchar=getchar()) != '*' ) goto onechar;
			lxcom();
		case A_WS:
			continue;

		case A_NL:
			++lineno;
			lxtitle();
			continue;

		case A_NOT:
			/* ! */
			if( (lxchar=getchar()) != '=' ) goto onechar;
			yylval.intval = NE;
			return( EQUOP );

		case A_MI:
			/* - */
			if( (lxchar=getchar()) == '-' ){
				yylval.intval = DECR;
				return( INCOP );
				}
			if( lxchar != '>' ) goto onechar;
			stwart = FUNNYNAME;
			yylval.intval=STREF;
			return( STROP );

		case A_PL:
			/* + */
			if( (lxchar=getchar()) != '+' ) goto onechar;
			yylval.intval = INCR;
			return( INCOP );

		case A_AND:
			/* & */
			if( (lxchar=getchar()) != '&' ) goto onechar;
			return( yylval.intval = ANDAND );

		case A_OR:
			/* | */
			if( (lxchar=getchar()) != '|' ) goto onechar;
			return( yylval.intval = OROR );

		case A_LT:
			/* < */
			if( (lxchar=getchar()) == '<' ){
				yylval.intval = LS;
				return( SHIFTOP );
				}
			if( lxchar != '=' ) goto onechar;
			yylval.intval = LE;
			return( RELOP );

		case A_GT:
			/* > */
			if( (lxchar=getchar()) == '>' ){
				yylval.intval = RS;
				return(SHIFTOP );
				}
			if( lxchar != '=' ) goto onechar;
			yylval.intval = GE;
			return( RELOP );

		case A_EQ:
			/* = */
			switch( lxchar = getchar() ){

			case '=':
				yylval.intval = EQ;
				return( EQUOP );

I 13
#ifdef old_assignment_ops
E 13
			case '+':
				yylval.intval = ASG PLUS;
				break;

			case '-':
				yylval.intval = ASG MINUS;

			warn:
				if( lxmask[ (lxchar=getchar())+1] & (LEXLET|LEXDIG|LEXDOT) ){
					werror( "ambiguous assignment: assignment op taken" );
					}
				ungetc( lxchar ,stdin);
				break;

			case '*':
				yylval.intval = ASG MUL;
				goto warn;

			case '/':
				yylval.intval = ASG DIV;
				break;

			case '%':
				yylval.intval = ASG MOD;
				break;

			case '&':
				yylval.intval = ASG AND;
				break;

			case '|':
				yylval.intval = ASG OR;
				break;

			case '^':
				yylval.intval = ASG ER;
				break;

			case '<':
				if( (lxchar=getchar()) != '<' ){
					uerror( "=<%c illegal", lxchar );
					}
				yylval.intval = ASG LS;
				break;

			case '>':
				if( (lxchar=getchar()) != '>' ){
					uerror( "=>%c illegal", lxchar );
					}
				yylval.intval = ASG RS;
				break;
I 13
#endif old_assignment_ops
E 13

			default:
				goto onechar;

				}

I 15
#ifdef old_assignment_ops	/* defeat 'unreachable code' warning */
E 15
			return( ASOP );
I 15
#endif old_assignment_ops
E 15

		default:
			cerror( "yylex error, character %03o (octal)", lxchar );

			}

		/* ordinarily, repeat here... */
		cerror( "out of switch in yylex" );

		}

	}

struct lxrdope {
	/* dope for reserved, in alphabetical order */

	char *lxrch;	/* name of reserved word */
	short lxract;	/* reserved word action */
	short lxrval;	/* value to be returned */
	} lxrdope[] = {

	"asm",		AR_A,	0,
	"auto",		AR_CL,	AUTO,
	"break",	AR_RW,	BREAK,
	"char",		AR_TY,	CHAR,
	"case",		AR_RW,	CASE,
	"continue",	AR_RW,	CONTINUE,
	"double",	AR_TY,	DOUBLE,
	"default",	AR_RW,	DEFAULT,
	"do",		AR_RW,	DO,
	"extern",	AR_CL,	EXTERN,
	"else",		AR_RW,	ELSE,
	"enum",		AR_E,	ENUM,
	"for",		AR_RW,	FOR,
	"float",	AR_TY,	FLOAT,
	"fortran",	AR_CL,	FORTRAN,
	"goto",		AR_RW,	GOTO,
	"if",		AR_RW,	IF,
	"int",		AR_TY,	INT,
	"long",		AR_TY,	LONG,
	"return",	AR_RW,	RETURN,
	"register",	AR_CL,	REGISTER,
	"switch",	AR_RW,	SWITCH,
	"struct",	AR_S,	0,
	"sizeof",	AR_RW,	SIZEOF,
	"short",	AR_TY,	SHORT,
	"static",	AR_CL,	STATIC,
	"typedef",	AR_CL,	TYPEDEF,
	"unsigned",	AR_TY,	UNSIGNED,
	"union",	AR_U,	0,
	"void",		AR_TY,	UNDEF, /* tymerge adds FTN */
	"while",	AR_RW,	WHILE,
	"",		0,	0,	/* to stop the search */
	};

lxres() {
	/* check to see of yytext is reserved; if so,
	/* do the appropriate action and return */
	/* otherwise, return -1 */

	register c, ch;
	register struct lxrdope *p;

	ch = yytext[0];

	if( !islower(ch) ) return( -1 );

	switch( ch ){

	case 'a':
		c=0; break;
	case 'b':
		c=2; break;
	case 'c':
		c=3; break;
	case 'd':
		c=6; break;
	case 'e':
		c=9; break;
	case 'f':
		c=12; break;
	case 'g':
		c=15; break;
	case 'i':
		c=16; break;
	case 'l':
		c=18; break;
	case 'r':
		c=19; break;
	case 's':
		c=21; break;
	case 't':
		c=26; break;
	case 'u':
		c=27; break;
	case 'v':
		c=29; break;
	case 'w':
		c=30; break;

	default:
		return( -1 );
		}

	for( p= lxrdope+c; p->lxrch[0] == ch; ++p ){
		if( !strcmp( yytext, p->lxrch ) ){ /* match */
			switch( p->lxract ){

			case AR_TY:
				/* type word */
				stwart = instruct;
				yylval.nodep = mkty( (TWORD)p->lxrval, 0, p->lxrval );
				return( TYPE );

			case AR_RW:
I 12
D 13
				{
					extern int	nsizeof;

					if (p->lxrval == SIZEOF)
						++nsizeof;
				}
E 13
E 12
				/* ordinary reserved word */
				return( yylval.intval = p->lxrval );

			case AR_CL:
				/* class word */
				yylval.intval = p->lxrval;
				return( CLASS );

			case AR_S:
				/* struct */
				stwart = INSTRUCT|SEENAME|TAGNAME;
				yylval.intval = INSTRUCT;
				return( STRUCT );

			case AR_U:
				/* union */
				stwart = INUNION|SEENAME|TAGNAME;
				yylval.intval = INUNION;
				return( STRUCT );

			case AR_E:
				/* enums */
				stwart = SEENAME|TAGNAME;
				return( yylval.intval = ENUM );

			case AR_A:
				/* asm */
				asm_esc = 1; /* warn the world! */
				lxget( ' ', LEXWS );
				if( getchar() != '(' ) goto badasm;
				lxget( ' ', LEXWS );
				if( getchar() != '"' ) goto badasm;
# ifndef ONEPASS
# ifndef LINT
				putchar(')');
# endif
# endif
				while( (c=getchar()) != '"' ){
					if( c=='\n' || c==EOF ) goto badasm;
# ifndef LINT
					putchar(c);
# endif
					}
				lxget( ' ', LEXWS );
				if( getchar() != ')' ) goto badasm;
# ifndef LINT
				putchar('\n');
# endif
				return( 0 );

			badasm:
				uerror( "bad asm construction" );
				return( 0 );

			default:
				cerror( "bad AR_?? action" );
				}
			}
		}
	return( -1 );
	}

extern int	labelno;

lxtitle(){
	/* called after a newline; set linenumber and file name */

	register c, val;
	register char *cp, *cq;

	for(;;){  /* might be several such lines in a row */
		if( (c=getchar()) != '#' ){
			if( c != EOF ) ungetc(c,stdin);
#ifndef LINT
			if ( lastloc != PROG) return;
			cp = ftitle;
			cq = ititle;
			while ( *cp ) if (*cp++ != *cq++) return;
			if ( *cq ) return;
D 14
			psline();
E 14
I 14
			if( nerrors == 0 ) psline();
E 14
#endif
			return;
			}

		lxget( ' ', LEXWS );
I 16
		c = getchar();
D 17
		if( c == '\n' )
			continue;
E 17
		if( c == 'i' ){
			/* #ident -- currently a no-op */
			lxget( c, LEXLET );
			if( strcmp( yytext, "ident" ) )
				werror( "%s: undefined control", yytext );
			while( (c = getchar()) != '\n' && c != EOF )
				;
			continue;
			}
		if( c == 'p' ){
			/* #pragma -- special instructions */
			lxget( c, LEXLET );
			if( strcmp( yytext, "pragma" ) ) {
				werror( "%s: undefined control", yytext );
				while( (c = getchar()) != '\n' && c != EOF )
					;
				continue;
				}
			lxget( ' ' , LEXWS );
			switch( c = getchar() ){
# ifdef LINT
			case 'V':
				lxget( c, LEXLET|LEXDIG );
				{
					extern int vaflag;
					int i;
					i = yytext[7]?yytext[7]-'0':0;
					yytext[7] = '\0';
					if( strcmp( yytext, "VARARGS" ) ) break;
					vaflag = i;
					break;
					}
			case 'L':
				lxget( c, LEXLET );
				if( strcmp( yytext, "LINTLIBRARY" ) ) break;
				{
					extern int libflag;
					libflag = 1;
					}
				break;

			case 'A':
				lxget( c, LEXLET );
				if( strcmp( yytext, "ARGSUSED" ) ) break;
				{
					extern int argflag, vflag;
					argflag = 1;
					vflag = 0;
					}
				break;

			case 'N':
				lxget( c, LEXLET );
				if( strcmp( yytext, "NOTREACHED" ) ) break;
				reached = 0;
				break;
#endif

			case '\n':
			case EOF:
				continue;
				}
			while( (c = getchar()) != '\n' && c != EOF )
				;
			continue;
			}
I 17
		if( c == 'l' ){
			/* #line -- just like # */
			lxget( c, LEXLET );
			if( strcmp( yytext, "line" ) ){
				werror( "%s: undefined control", yytext );
				while( (c = getchar()) != '\n' && c != EOF )
					;
				continue;
				}
			lxget( ' ', LEXWS );
			c = getchar();
			}
E 17
		if( !isdigit(c) ){
			if( isalpha(c) ){
				lxget( c, LEXLET );
				werror( "%s: undefined control", yytext );
				}
D 17
			while( (c = getchar()) != '\n' && c != EOF )
				;
E 17
I 17
			while( c != '\n' && c != EOF )
				c = getchar();
E 17
			continue;
			}
			
E 16
		val = 0;
D 16
		for( c=getchar(); isdigit(c); c=getchar() ){
E 16
I 16
		do {
E 16
			val = val*10+ c - '0';
			}
I 16
		while( isdigit( c = getchar() ) );

E 16
I 5
		if( c == EOF )
			continue;
E 5
		ungetc( c, stdin );
		lineno = val;
		lxget( ' ', LEXWS );
D 5
		if( (c=getchar()) != '\n' ){
			for( cp=ftitle; c!='\n'; c=getchar(),++cp ){
E 5
I 5
		if( (c=getchar()) != '\n' && c != EOF ){
			for( cp=ftitle; c!=EOF && c!='\n'; c=getchar(),++cp ){
E 5
				*cp = c;
				}
			*cp = '\0';
#ifndef LINT
			if (ititle[0] == '\0') {
				cp = ftitle;
				cq = ititle;
				while ( *cp )  
					*cq++ = *cp++;
				*cq = '\0';
				*--cq = '\0';
#ifndef FLEXNAMES
				for ( cp = ititle+1; *(cp-1); cp += 8 ) {
					pstab(cp, N_SO);
					if (gdebug) printf("0,0,LL%d\n", labelno);
					}
#else
				pstab(ititle+1, N_SO);
				if (gdebug) printf("0,0,LL%d\n", labelno);
#endif

				*cq = '"';
				printf("LL%d:\n", labelno++);
				}
#endif
			}
		}
	}

#ifdef FLEXNAMES
#define	NSAVETAB	4096
char	*savetab;
D 20
int	saveleft;
E 20
I 20
unsigned saveleft;
char	*malloc();
char	*calloc();
char	*strncpy();
E 20

char *
savestr(cp)
	register char *cp;
{
	register int len;

	len = strlen(cp) + 1;
	if (len > saveleft) {
		saveleft = NSAVETAB;
		if (len > saveleft)
			saveleft = len;
D 20
		savetab = (char *)malloc(saveleft);
E 20
I 20
		savetab = malloc(saveleft);
E 20
		if (savetab == 0)
			cerror("Ran out of memory (savestr)");
	}
D 20
	strncpy(savetab, cp, len);
E 20
I 20
	(void) strncpy(savetab, cp, len);
E 20
	cp = savetab;
	savetab += len;
	saveleft -= len;
	return (cp);
}

/*
 * The definition for the segmented hash tables.
 */
#define	MAXHASH	20
#define	HASHINC	1013
struct ht {
	char	**ht_low;
	char	**ht_high;
	int	ht_used;
} htab[MAXHASH];

char *
hash(s)
	char *s;
{
	register char **h;
	register i;
	register char *cp;
	struct ht *htp;
	int sh;

	/*
	 * The hash function is a modular hash of
	 * the sum of the characters with the sum
	 * doubled before each successive character
	 * is added.
	 */
	cp = s;
	i = 0;
	while (*cp)
		i = i*2 + *cp++;
	sh = (i&077777) % HASHINC;
	cp = s;
	/*
	 * There are as many as MAXHASH active
	 * hash tables at any given point in time.
	 * The search starts with the first table
	 * and continues through the active tables
	 * as necessary.
	 */
	for (htp = htab; htp < &htab[MAXHASH]; htp++) {
		if (htp->ht_low == 0) {
			register char **hp =
			    (char **) calloc(sizeof (char **), HASHINC);
			if (hp == 0)
				cerror("ran out of memory (hash)");
			htp->ht_low = hp;
			htp->ht_high = htp->ht_low + HASHINC;
		}
		h = htp->ht_low + sh;
		/*
		 * quadratic rehash increment
		 * starts at 1 and incremented
		 * by two each rehash.
		 */
		i = 1;
		do {
			if (*h == 0) {
				if (htp->ht_used > (HASHINC * 3)/4)
					break;
				htp->ht_used++;
				*h = savestr(cp);
				return (*h);
			}
			if (**h == *cp && strcmp(*h, cp) == 0)
				return (*h);
			h += i;
			i += 2;
			if (h >= htp->ht_high)
				h -= HASHINC;
		} while (i < HASHINC);
	}
	cerror("ran out of hash tables");
I 20
	/*NOTREACHED*/
E 20
}
#endif
E 1
