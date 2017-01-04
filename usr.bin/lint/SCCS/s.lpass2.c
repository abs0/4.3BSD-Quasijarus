h38845
s 00003/00003/00809
d D 1.9 87/12/11 19:28:49 donn 9 8
c utah rcsid 1.3 87/07/15 20:51:25: Use ~nargs rather than -nargs to identify
c VARARGS functions so that VARARGS0 can be distinguished from a function
c with fixed 0 arguments.
e
s 00009/00003/00803
d D 1.8 87/04/22 15:32:29 bostic 8 7
c bug report 4.3BSD/usr.bin/54
e
s 00025/00004/00781
d D 1.7 87/04/22 15:28:00 bostic 7 6
c bug report 4.3BSD/usr.bin/53
e
s 00001/00001/00784
d D 1.6 86/02/21 19:02:39 karels 6 5
c more symbol definitions
e
s 00003/00002/00782
d D 1.5 85/04/08 11:46:10 ralph 5 4
c changes due to pcc restructuring for common header files.
e
s 00000/00001/00784
d D 1.4 83/08/11 20:52:17 sam 4 3
c standardize sccs keyword lines
e
s 00190/00073/00595
d D 1.3 83/03/29 11:54:40 edward 3 2
c Statics are now treated correctly.
c 	Structure type matching in second pass done by hashed name
c 	and size.
c 	-z flag added to ignore undeclared structure errors.
e
s 00001/00001/00667
d D 1.2 83/03/12 19:39:30 sam 2 1
c raise number of files limit so we can lint the kernel
e
s 00668/00000/00000
d D 1.1 82/08/30 13:15:57 rrh 1 0
c date and time created 82/08/30 13:15:57 by rrh
e
u
U
t
T
I 1
D 4

E 4
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif lint

D 5
# include "manifest"
# include "lmanifest"
E 5
I 5
# include "macdefs.h"
# include "manifest.h"
# include "lmanifest.h"
E 5

# define USED 01
# define VUSED 02
# define EUSED 04
# define RVAL 010
# define VARARGS 0100

D 6
# define NSZ 2048
E 6
I 6
# define NSZ 4096
E 6
# define TYSZ 3500
D 2
# define FSZ 250
E 2
I 2
# define FSZ 500
E 2
# define NTY 50

typedef struct sty STYPE;
struct sty { ATYPE t; STYPE *next; };

typedef struct sym {
#ifndef FLEXNAMES
	char name[LCHNM];
#else
	char *name;
#endif
	short nargs;
	int decflag;
	int fline;
	STYPE symty;
	int fno;
	int use;
	} STAB;

STAB stab[NSZ];
STAB *find();

STYPE tary[TYSZ];
STYPE *tget();

#ifndef FLEXNAMES
char fnm[FSZ][LFNM];
#else
char *fnm[FSZ];
#endif

#ifdef FLEXNAMES
char *getstr();
#endif

int tfree;  /* used to allocate types */
int ffree;  /* used to save filenames */

struct ty atyp[NTY];
	/* r is where all the input ends up */
union rec r;

int hflag = 0;
int pflag = 0;
int xflag = 0;
int uflag = 1;
int ddddd = 0;
I 3
int zflag = 0;
int Pflag = 0;
E 3

int cfno;  /* current file number */

main( argc, argv ) char *argv[]; {
	register char *p;

	/* first argument is intermediate file */
	/* second argument is - options */

	for( ; argc>2 && argv[argc-1][0] == '-' ; --argc ){
		for( p=argv[argc-1]; *p; ++p ){
			switch( *p ){

			case 'h':
				hflag = 1;
				break;

			case 'p':
				pflag = 1;
				break;

			case 'x':
				xflag = 1;
				break;

			case 'X':
				ddddd = 1;
				break;

			case 'u':
				uflag = 0;
				break;

I 3
			case 'z':
				zflag = 1;
				break;

			case 'P':
				Pflag = 1;
				break;

E 3
				}
			}
		}

	if( argc < 2 || !freopen( argv[1], "r", stdin ) ){
		error( "cannot open intermediate file" );
		exit( 1 );
		}
D 3

	mloop( LDI|LIB );
E 3
I 3
	if( Pflag ){
		pfile();
		return( 0 );
		}
	mloop( LDI|LIB|LST );
E 3
	rewind( stdin );
	mloop( LDC|LDX );
	rewind( stdin );
	mloop( LRV|LUV|LUE|LUM );
	cleanup();
	return(0);
	}

mloop( m ){
	/* do the main loop */
	register STAB *q;

	while( lread(m) ){
		q = find();
		if( q->decflag ) chkcompat(q);
		else setuse(q);
		}
	}

lread(m){ /* read a line into r.l */

	register n;

	for(;;) {
		if( fread( (char *)&r, sizeof(r), 1, stdin ) <= 0 ) return(0);
		if( r.l.decflag & LFN ){
			/* new filename */
#ifdef FLEXNAMES
D 7
			r.f.fn = getstr();
E 7
I 7
			r.f.fn = getstr(0);
E 7
#endif
I 3
			if( Pflag ) return( 1 );
E 3
			setfno( r.f.fn );
			continue;
			}
#ifdef FLEXNAMES
D 7
		r.l.name = getstr();
#endif
E 7
I 7
		r.l.name = getstr(1);
#else /* !FLEXNAMES */
		portify(r.l.name);
#endif /* !FLEXNAMES */
E 7
D 3

E 3
		n = r.l.nargs;
D 9
		if( n<0 ) n = -n;
E 9
I 9
		if( n<0 ) n = ~n;
E 9
D 3
		if( n ){
			if( n>=NTY ) error( "more than %d args?", n );
			fread( (char *)atyp, sizeof(ATYPE), n, stdin );
			}
E 3
I 3
		if( n>=NTY ) error( "more than %d args?", n );
		fread( (char *)atyp, sizeof(ATYPE), n, stdin );
E 3
		if( ( r.l.decflag & m ) ) return( 1 );
		}
	}

setfno( s ) char *s; {
	/* look up current file names */
	/* first, strip backwards to the beginning or to the first / */
	int i;

	/* now look up s */
	for( i=0; i<ffree; ++i ){
#ifndef FLEXNAMES
D 3
		if( !strncmp( s, fnm[i], LFNM ) ){
E 3
I 3
		if( !strncmp( s, fnm[i], LFNM ) )
E 3
#else
D 3
		if (fnm[i] == s){
E 3
I 3
		if (fnm[i] == s)
E 3
#endif
I 3
			{
E 3
			cfno = i;
			return;
			}
		}
	/* make a new entry */
	if( ffree >= FSZ ) error( "more than %d files", FSZ );
#ifndef FLEXNAMES
	strncpy( fnm[ffree], s, LFNM );
#else
	fnm[ffree] = s;
#endif
	cfno = ffree++;
	}

/* VARARGS */
error( s, a ) char *s; {

#ifndef FLEXNAMES
	fprintf( stderr, "pass 2 error:(file %.*s) ", LFNM, fnm[cfno] );
#else
	fprintf( stderr, "pass 2 error:(file %s) ", fnm[cfno] );
#endif
	fprintf( stderr, s, a );
	fprintf( stderr, "\n" );
	exit(1);
	}

STAB *
find(){
D 3
	/* for this to work, NSZ should be a power of 2 */
E 3
	register h=0;
#ifndef FLEXNAMES
D 3
	{	register char *p, *q;
		for( h=0,p=r.l.name,q=p+LCHNM; *p&&p<q; ++p) {
			h = (h<<1)+ *p;
			if( h>=NSZ ){
				h = (h+1)&(NSZ-1);
				}
			}
		}
E 3
I 3
	h = hashstr(r.l.name, LCHNM) % NSZ;
E 3
#else
D 3
		h = ((int)r.l.name)%NSZ;
E 3
I 3
	h = (int)r.l.name % NSZ;
E 3
#endif
	{	register STAB *p, *q;
		for( p=q= &stab[h]; q->decflag; ){
D 3
			/* this call to strncmp should be taken out... */
E 3
#ifndef FLEXNAMES
D 3
			if( !strncmp( r.l.name, q->name, LCHNM)) return(q);
E 3
I 3
			if( !strncmp( r.l.name, q->name, LCHNM))
E 3
#else
D 3
			if (r.l.name == q->name) return (q);
E 3
I 3
			if (r.l.name == q->name)
E 3
#endif
I 3
				if( ((q->decflag|r.l.decflag)&LST)==0 || q->fno==cfno )
					return(q);
E 3
			if( ++q >= &stab[NSZ] ) q = stab;
			if( q == p ) error( "too many names defined" );
			}
#ifndef FLEXNAMES
		strncpy( q->name, r.l.name, LCHNM );
#else
		q->name = r.l.name;
#endif
		return( q );
		}
	}

STYPE *
tget(){
	if( tfree >= TYSZ ){
		error( "too many types needed" );
		}
	return( &tary[tfree++] );
	}

chkcompat(q) STAB *q; {
	/* are the types, etc. in r.l and q compatible */
	register int i;
	STYPE *qq;

	setuse(q);

	/* argument check */

D 3
	if( q->decflag & (LDI|LIB|LUV|LUE) ){
E 3
I 3
	if( q->decflag & (LDI|LIB|LUV|LUE|LST) ){
E 3
		if( r.l.decflag & (LUV|LIB|LUE) ){
			if( q->nargs != r.l.nargs ){
				if( !(q->use&VARARGS) ){
#ifndef FLEXNAMES
					printf( "%.8s: variable # of args.", q->name );
#else
					printf( "%s: variable # of args.", q->name );
#endif
					viceversa(q);
					}
				if( r.l.nargs > q->nargs ) r.l.nargs = q->nargs;
D 3
				if( !(q->decflag & (LDI|LIB) ) ) {
E 3
I 3
				if( !(q->decflag & (LDI|LIB|LST) ) ) {
E 3
					q->nargs = r.l.nargs;
					q->use |= VARARGS;
					}
				}
			for( i=0,qq=q->symty.next; i<r.l.nargs; ++i,qq=qq->next){
D 8
				if( chktype( &qq->t, &atyp[i] ) ){
E 8
I 8
				if( chktype( &qq->t, &atyp[i], q->fno ) ){
E 8
#ifndef FLEXNAMES
					printf( "%.8s, arg. %d used inconsistently",
#else
					printf( "%s, arg. %d used inconsistently",
#endif
						q->name, i+1 );
					viceversa(q);
					}
				}
			}
		}

D 3
	if( (q->decflag&(LDI|LIB|LUV)) && r.l.decflag==LUV ){
E 3
I 3
	if( (q->decflag&(LDI|LIB|LUV|LST)) && r.l.decflag==LUV ){
E 3
D 8
		if( chktype( &r.l.type, &q->symty.t ) ){
E 8
I 8
		if( chktype( &r.l.type, &q->symty.t, q->fno ) ){
E 8
#ifndef FLEXNAMES
			printf( "%.8s value used inconsistently", q->name );
#else
			printf( "%s value used inconsistently", q->name );
#endif
			viceversa(q);
			}
		}

	/* check for multiple declaration */

D 3
	if( (q->decflag&LDI) && (r.l.decflag&(LDI|LIB)) ){
E 3
I 3
	if( (q->decflag&(LDI|LST)) && (r.l.decflag&(LDI|LIB|LST)) ){
E 3
#ifndef FLEXNAMES
		printf( "%.8s multiply declared", q->name );
#else
		printf( "%s multiply declared", q->name );
#endif
		viceversa(q);
		}

	/* do a bit of checking of definitions and uses... */

D 3
	if( (q->decflag & (LDI|LIB|LDX|LDC|LUM)) && (r.l.decflag & (LDX|LDC|LUM)) && q->symty.t.aty != r.l.type.aty ){
E 3
I 3
	if( (q->decflag & (LDI|LIB|LDX|LDC|LUM|LST)) && (r.l.decflag & (LDX|LDC|LUM)) && q->symty.t.aty != r.l.type.aty ){
E 3
#ifndef FLEXNAMES
		printf( "%.8s value declared inconsistently", q->name );
#else
		printf( "%s value declared inconsistently", q->name );
#endif
		viceversa(q);
		}

	/* better not call functions which are declared to be structure or union returning */

D 3
	if( (q->decflag & (LDI|LIB|LDX|LDC)) && (r.l.decflag & LUE) && q->symty.t.aty != r.l.type.aty ){
E 3
I 3
	if( (q->decflag & (LDI|LIB|LDX|LDC|LST)) && (r.l.decflag & LUE) && q->symty.t.aty != r.l.type.aty ){
E 3
		/* only matters if the function returns union or structure */
		TWORD ty;
		ty = q->symty.t.aty;
		if( ISFTN(ty) && ((ty = DECREF(ty))==STRTY || ty==UNIONTY ) ){
#ifndef FLEXNAMES
			printf( "%.8s function value type must be declared before use", q->name );
#else
			printf( "%s function value type must be declared before use", q->name );
#endif
			viceversa(q);
			}
		}

	if( pflag && q->decflag==LDX && r.l.decflag == LUM && !ISFTN(q->symty.t.aty) ){
		/* make the external declaration go away */
		/* in effect, it was used without being defined */
		}
	}

viceversa(q) STAB *q; {
	/* print out file comparison */
#ifndef FLEXNAMES
	printf( "	%.*s(%d)  ::  %.*s(%d)\n",
		LFNM, fnm[q->fno], q->fline,
		LFNM, fnm[cfno], r.l.fline );
#else
	printf( "	%s(%d)  ::  %s(%d)\n",
		fnm[q->fno], q->fline,
		fnm[cfno], r.l.fline );
#endif
	}

	/* messages for defintion/use */
char *
mess[2][2] ={
	"",
#ifndef FLEXNAMES
	"%.8s used( %.*s(%d) ), but not defined\n",
	"%.8s defined( %.*s(%d) ), but never used\n",
	"%.8s declared( %.*s(%d) ), but never used or defined\n"
#else
	"%s used( %s(%d) ), but not defined\n",
	"%s defined( %s(%d) ), but never used\n",
	"%s declared( %s(%d) ), but never used or defined\n"
#endif
	};

lastone(q) STAB *q; {

	register nu, nd, uses;

	if( ddddd ) pst(q);

	nu = nd = 0;
	uses = q->use;

	if( !(uses&USED) && q->decflag != LIB ) {
#ifndef FLEXNAMES
		if( strncmp(q->name,"main",7) )
#else
		if (strcmp(q->name, "main"))
#endif
			nu = 1;
		}

	if( !ISFTN(q->symty.t.aty) ){
		switch( q->decflag ){

		case LIB:
			nu = nd = 0;  /* don't complain about uses on libraries */
			break;
		case LDX:
			if( !xflag ) break;
		case LUV:
		case LUE:
/* 01/04/80 */	case LUV | LUE:
		case LUM:
			nd = 1;
			}
		}
D 3
	if( uflag && ( nu || nd ) ) printf( mess[nu][nd],
E 3
I 3
	if( uflag && ( nu || nd ) )
E 3
#ifndef FLEXNAMES
D 3
		 q->name, LFNM, fnm[q->fno], q->fline );
E 3
I 3
		printf( mess[nu][nd], q->name, LFNM, fnm[q->fno], q->fline );
E 3
#else
D 3
		 q->name, fnm[q->fno], q->fline );
E 3
I 3
		printf( mess[nu][nd], q->name, fnm[q->fno], q->fline );
E 3
#endif

	if( (uses&(RVAL+EUSED)) == (RVAL+EUSED) ){
I 3
		/* if functions is static, then print the file name too */
		if( q->decflag & LST )
E 3
#ifndef FLEXNAMES
D 3
		printf( "%.8s returns value which is %s ignored\n", q->name,
E 3
I 3
			printf( "%.*s(%d):", LFNM, fnm[q->fno], q->fline );
E 3
#else
D 3
		printf( "%s returns value which is %s ignored\n", q->name,
E 3
I 3
			printf( "%s(%d):", fnm[q->fno], q->fline );
E 3
#endif
D 3
			uses&VUSED ? "sometimes" : "always" );
E 3
I 3
#ifndef FLEXNAMES
		printf( "%.*s returns value which is %s ignored\n",
			LCHNM, q->name, uses&VUSED ? "sometimes" : "always" );
#else
		printf( "%s returns value which is %s ignored\n",
			q->name, uses&VUSED ? "sometimes" : "always" );
#endif
E 3
		}

D 3
	if( (uses&(RVAL+VUSED)) == (VUSED) && (q->decflag&(LDI|LIB)) ){
E 3
I 3
	if( (uses&(RVAL+VUSED)) == (VUSED) && (q->decflag&(LDI|LIB|LST)) ){
		if( q->decflag & LST )
E 3
#ifndef FLEXNAMES
D 3
		printf( "%.8s value is used, but none returned\n", q->name );
E 3
I 3
			printf( "%.*s(%d):", LFNM, fnm[q->fno], q->fline );
E 3
#else
D 3
		printf( "%s value is used, but none returned\n", q->name );
E 3
I 3
			printf( "%s(%d):", fnm[q->fno], q->fline );
E 3
#endif
I 3
#ifndef FLEXNAMES
		printf( "%.*s value is used, but none returned\n",
			LCHNM, q->name);
#else
		printf( "%s value is used, but none returned\n", q->name);
#endif
E 3
		}
	}

cleanup(){ /* call lastone and die gracefully */
	STAB *q;
	for( q=stab; q< &stab[NSZ]; ++q ){
		if( q->decflag ) lastone(q);
		}
	exit(0);
	}

setuse(q) STAB *q; { /* check new type to ensure that it is used */

	if( !q->decflag ){ /* new one */
		q->decflag = r.l.decflag;
		q->symty.t = r.l.type;
		if( r.l.nargs < 0 ){
D 9
			q->nargs = -r.l.nargs;
E 9
I 9
			q->nargs = ~r.l.nargs;
E 9
			q->use = VARARGS;
			}
		else {
			q->nargs = r.l.nargs;
			q->use = 0;
			}
		q->fline = r.l.fline;
		q->fno = cfno;
		if( q->nargs ){
			int i;
			STYPE *qq;
			for( i=0,qq= &q->symty; i<q->nargs; ++i,qq=qq->next ){
				qq->next = tget();
				qq->next->t = atyp[i];
				}
			}
		}

	switch( r.l.decflag ){

	case LRV:
		q->use |= RVAL;
		return;
	case LUV:
		q->use |= VUSED+USED;
		return;
	case LUE:
		q->use |= EUSED+USED;
		return;
/* 01/04/80 */	case LUV | LUE:
	case LUM:
		q->use |= USED;
		return;

		}
	}

D 8
chktype( pt1, pt2 ) register ATYPE *pt1, *pt2; {
E 8
I 8
chktype( pt1, pt2, fno ) register ATYPE *pt1, *pt2; {
E 8
	TWORD t;

	/* check the two type words to see if they are compatible */
	/* for the moment, enums are turned into ints, and should be checked as such */
	if( pt1->aty == ENUMTY ) pt1->aty =  INT;
	if( pt2->aty == ENUMTY ) pt2->aty = INT;

	if( (t=BTYPE(pt1->aty)==STRTY) || t==UNIONTY ){
D 3
		return( pt1->aty!=pt2->aty || (
			pt1->extra!=pt2->extra ) );
E 3
I 3
		if( pt1->aty != pt2->aty || pt1->extra1 != pt2->extra1 )
			return 1;
		/* if -z then don't worry about undefined structures,
		   as long as the names match */
		if( zflag && (pt1->extra == 0 || pt2->extra == 0) ) return 0;
I 8
		/* if -p and pt1 is "too big" and
		** pt1 came from a llib-l file, we can't pass judgment on it.
		*/
		if ( pflag && pt1->extra > pt2->extra &&
			strncmp(fnm[fno], "llib-l", 6) == 0)
				return 0;
E 8
		return pt1->extra != pt2->extra;
E 3
		}

	if( pt2->extra ){ /* constant passed in */
		if( pt1->aty == UNSIGNED && pt2->aty == INT ) return( 0 );
		else if( pt1->aty == ULONG && pt2->aty == LONG ) return( 0 );
		}
	else if( pt1->extra ){ /* for symmetry */
		if( pt2->aty == UNSIGNED && pt1->aty == INT ) return( 0 );
		else if( pt2->aty == ULONG && pt1->aty == LONG ) return( 0 );
		}

	return( pt1->aty != pt2->aty );
	}

struct tb { int m; char * nm };
I 3

struct tb dfs[] = {
	LDI, "LDI",
	LIB, "LIB",
	LDC, "LDC",
	LDX, "LDX",
	LRV, "LRV",
	LUV, "LUV",
	LUE, "LUE",
	LUM, "LUM",
	LST, "LST",
	LFN, "LFN",
	0, "" };

struct tb us[] = {
	USED, "USED",
	VUSED, "VUSED",
	EUSED, "EUSED",
	RVAL, "RVAL",
	VARARGS, "VARARGS",
	0, "" };

E 3
ptb( v, tp ) struct tb *tp; {
	/* print a value from the table */
	int flag;
	flag = 0;
	for( ; tp->m; ++tp ){
		if( v&tp->m ){
			if( flag++ ) putchar( '|' );
			printf( "%s", tp->nm );
			}
		}
	}

pst( q ) STAB *q; {
	/* give a debugging output for q */
D 3
	static struct tb dfs[] = {
		LDI, "LDI",
		LIB, "LIB",
		LDC, "LDC",
		LDX, "LDX",
		LRV, "LRV",
		LUV, "LUV",
		LUE, "LUE",
		LUM, "LUM",
		0, "" };
E 3

D 3
	static struct tb us[] = {
		USED, "USED",
		VUSED, "VUSED",
		EUSED, "EUSED",
		RVAL, "RVAL",
		VARARGS, "VARARGS",
		0,	0,
		};

E 3
#ifndef FLEXNAMES
	printf( "%.8s (", q->name );
#else
	printf( "%s (", q->name );
#endif
	ptb( q->decflag, dfs );
	printf( "), use= " );
	ptb( q->use, us );
	printf( ", line %d, nargs=%d\n", q->fline, q->nargs );
	}

I 3
pfile() {
	/* print the input file in readable form */
	while( lread( LDI|LIB|LDC|LDX|LRV|LUV|LUE|LUM|LST|LFN ) )
		prc();
	}

prc() {
	/* print out 'r' for debugging */
	register i, j, k;

	printf( "decflag\t" );
	ptb( r.l.decflag, dfs );
	putchar( '\n' );
	if( r.l.decflag & LFN ){
E 3
#ifdef FLEXNAMES
I 3
		printf( "fn\t\t%s\n", r.f.fn );
#else
		printf( "fn\t%\t.*s\n", LFNM, r.f.fn );
#endif
		}
	else {
#ifdef FLEXNAMES
		printf( "name\t%s\n", r.l.name );
#else
		printf( "name\t%.*s\n", LCHNM, r.l.name );
#endif
		printf( "nargs\t%d\n", r.l.nargs );
		printf( "fline\t%d\n", r.l.fline );
		printf( "type.aty\t0%o (", r.l.type.aty );
		pty( r.l.type.aty, r.l.name );
		printf( ")\ntype.extra\t%d\n", r.l.type.extra );
		j = r.l.type.extra1;
		printf( "type.extra1\t0x%x (%d,%d)\n",
			j, j & X_NONAME ? 1 : 0, j & ~X_NONAME );
		k = r.l.nargs;
D 9
		if( k < 0 ) k = -k;
E 9
I 9
		if( k < 0 ) k = ~k;
E 9
		for( i = 0; i < k; i++ ){
			printf( "atyp[%d].aty\t0%o (", i, atyp[i].aty );
			pty( atyp[i].aty, "" );
			printf( ")\natyp[%d].extra\t%d\n", i, atyp[i].extra);
			j = atyp[i].extra1;
			printf( "atyp[%d].extra1\t0x%x (%d,%d)\n",
				i, j, j & X_NONAME ? 1 : 0, j & ~X_NONAME );
			}
		}
		putchar( '\n' );
	}

pty( t, name )  TWORD t; {
	static char * tnames[] = {
		"void", "farg", "char", "short",
		"int", "long", "float", "double",
		"struct xxx", "union %s", "enum", "moety",
		"unsigned char", "unsigned short", "unsigned", "unsigned long",
		"?", "?"
		};

	printf( "%s ", tnames[BTYPE(t)] );
	pty1( t, name, (8 * sizeof (int) - BTSHIFT) / TSHIFT );
	}

pty1( t, name, level ) TWORD t; {
	register TWORD u;

	if( level < 0 ){
		printf( "%s", name );
		return;
		}
	u = t >> level * TSHIFT;
	if( ISPTR(u) ){
		printf( "*" );
		pty1( t, name, level-1 );
		}
	else if( ISFTN(u) ){
		if( level > 0 && ISPTR(u << TSHIFT) ){
			printf( "(" );
			pty1( t, name, level-1 );
			printf( ")()" );
			}
		else {
			pty1( t, name, level-1 );
			printf( "()" );
			}
		}
	else if( ISARY(u) ){
		if( level > 0 && ISPTR(u << TSHIFT) ){
			printf( "(" );
			pty1( t, name, level-1 );
			printf( ")[]" );
			}
		else {
			pty1( t, name, level-1 );
			printf( "[]" );
			}
		}
	else {
		pty1( t, name, level-1 );
		}
	}

#ifdef FLEXNAMES
E 3
char *
D 7
getstr()
E 7
I 7
getstr(doport)
E 7
{
	char buf[BUFSIZ];
	register char *cp = buf;
	register int c;

	if (feof(stdin) || ferror(stdin))
		return("");
	while ((c = getchar()) > 0)
		*cp++ = c;
	if (c < 0) {
D 3
		fprintf(stderr, "pass 2 error: intermediate file format error (getstr)");
E 3
I 3
		error("intermediate file format error (getstr)");
E 3
		exit(1);
	}
	*cp++ = 0;
I 7
	if (doport)
		portify(buf);
E 7
	return (hash(buf));
}

#define	NSAVETAB	4096
char	*savetab;
int	saveleft;

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
		savetab = (char *)malloc(saveleft);
		if (savetab == 0) {
D 3
			fprintf(stderr, "pass 2 error: ran out of memory (savestr)");
E 3
I 3
			error("ran out of memory (savestr)");
E 3
			exit(1);
		}
	}
	strncpy(savetab, cp, len);
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

D 3
	/*
	 * The hash function is a modular hash of
	 * the sum of the characters with the sum
	 * doubled before each successive character
	 * is added.
	 */
E 3
I 3
	sh = hashstr(s) % HASHINC;
E 3
	cp = s;
D 3
	i = 0;
	while (*cp)
		i = i*2 + *cp++;
	sh = (i&077777) % HASHINC;
	cp = s;
E 3
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
			if (hp == 0) {
D 3
				fprintf(stderr, "pass 2 error: ran out of memory (hash)");
E 3
I 3
				error("ran out of memory (hash)");
E 3
				exit(1);
			}
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
D 3
	fprintf(stderr, "pass 2 error: ran out of hash tables");
E 3
I 3
	error("ran out of hash tables");
E 3
	exit(1);
}
char	*tstrbuf[1];
#endif
I 7

#include "ctype.h"

portify(cp)
register char *	cp;
{
	register int	i;

	if (!pflag)
		return;
	for (i = 0; i < 6; ++i)
		if (cp[i] == '\0')
			return;
		else if (isascii(cp[i]) && isupper(cp[i]))
			cp[i] = tolower(cp[i]);
	cp[i] = '\0';
}
E 7
E 1
