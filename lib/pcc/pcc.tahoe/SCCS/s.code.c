h59388
s 00001/00002/00522
d D 1.6 88/05/31 21:22:31 donn 6 5
c Bleah -- deflab() can't be a macro, too many things use the side
c effects from expressions passed as arguments.
e
s 00026/00008/00498
d D 1.5 87/12/10 20:30:07 donn 5 4
c utah rcsid 1.2 87/05/02 14:44:07: Permit some tiny functions to be macros;
c change select() to selectheap() to avoid Unix problems; add 'if (nerrors)'
c tests to avoid output after errors; some lint tidbits.
c utah rcsid 1.4 87/07/17 19:09:35: Minor tweaking to bring format in line
c with vax version.
e
s 00009/00009/00497
d D 1.4 87/07/02 21:29:02 sam 4 3
c move stab definition of beginning of function to after the prologue 
c so that dbx can access register variables and so on (brought over from vax 
c version of code.c)
e
s 00027/00025/00479
d D 1.3 86/02/12 20:44:20 sam 3 2
c purge as many printf calls as possible
e
s 00001/00001/00503
d D 1.2 86/02/04 22:18:51 sam 2 1
c new include files
e
s 00504/00000/00000
d D 1.1 86/01/11 11:00:52 sam 1 0
c date and time created 86/01/11 11:00:52 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

D 2
# include "mfile1"
E 2
I 2
# include "pass1.h"
E 2
# include <sys/types.h>
# include <a.out.h>
# include <stab.h>

I 3
D 5
# define putstr(s)	fputs((s), stdout)

E 5
E 3
int proflg = 0;	/* are we generating profiling code? */
int strftn = 0;  /* is the current function one which returns a value */
int gdebug;
int fdefflag;  /* are we within a function definition ? */
#ifndef STABDOT
char NULLNAME[8];
#endif
int labelno;

I 5
# define putstr(s)	fputs((s), stdout)

E 5
branch( n ){
	/* output a branch to label n */
	/* exception is an ordinary function branching to retlab: then, return */
I 5
	if( nerrors ) return;
E 5
	if( n == retlab && !strftn ){
		register TWORD t;
		register r;
			/* set number of regs in assem comment field */
			/* so optimizers can do a better job */
		r = 0;
		if( retstat & RETVAL ){ /* the function rets a val somewhere */
			t = (&stab[curftn])->stype;
			t = DECREF(t);
			r++;	/* it is at least one */
			if(t == DOUBLE)
				r++;	/* it takes two */
		} else		/* the fn does not ret a val	*/
			r = 2;
		printf( "	ret#%d\n", r );
		}
	else printf( "	jbr 	L%d\n", n );
	}

int lastloc = { -1 };

short log2tab[] = {0, 0, 1, 2, 2, 3, 3, 3, 3};
#define LOG2SZ 9

defalign(n) {
	/* cause the alignment to become a multiple of n */
	n /= SZCHAR;
	if( lastloc != PROG && n > 1 ) printf( "	.align	%d\n", n >= 0 && n < LOG2SZ ? log2tab[n] : 0 );
	}

locctr( l ){
	register temp;
	/* l is PROG, ADATA, DATA, STRNG, ISTRNG, or STAB */

	if( l == lastloc ) return(l);
	temp = lastloc;
	lastloc = l;
I 5
	if( nerrors ) return(temp);
E 5
	switch( l ){

	case PROG:
D 3
		printf( "	.text\n" );
E 3
I 3
		putstr( "	.text\n" );
E 3
		psline();
		break;

	case DATA:
	case ADATA:
D 3
		printf( "	.data\n" );
E 3
I 3
		putstr( "	.data\n" );
E 3
		break;

	case STRNG:
D 3
		printf( "	.data	1\n" );
E 3
I 3
		putstr( "	.data	1\n" );
E 3
		break;

	case ISTRNG:
D 3
		printf( "	.data	2\n" );
E 3
I 3
		putstr( "	.data	2\n" );
E 3
		break;

	case STAB:
D 3
		printf( "	.stab\n" );
E 3
I 3
		putstr( "	.stab\n" );
E 3
		break;

	default:
		cerror( "illegal location counter" );
		}

	return( temp );
	}

I 5
D 6
#ifndef deflab
E 6
E 5
deflab( n ){
	/* output something to define the current position as label n */
I 6
	if (nerrors) return;
E 6
	printf( "L%d:\n", n );
	}
I 5
D 6
#endif
E 6
E 5

int crslab = 10;

getlab(){
	/* return a number usable for a label */
	return( ++crslab );
	}


efcode(){
	/* code for the end of a function */

	if( strftn ){  /* copy output (in R2) to caller */
		register NODE *l, *r;
		register struct symtab *p;
		register TWORD t;
		register int i;

		p = &stab[curftn];
		t = p->stype;
		t = DECREF(t);

		deflab( retlab );

		i = getlab();	/* label for return area */
#ifndef LCOMM
D 3
		printf("	.data\n" );
		printf("	.align	2\n" );
E 3
I 3
		putstr("	.data\n" );
		putstr("	.align	2\n" );
E 3
		printf("L%d:	.space	%d\n", i, tsize(t, p->dimoff, p->sizoff)/SZCHAR );
D 3
		printf("	.text\n" );
E 3
I 3
		putstr("	.text\n" );
E 3
#else
		{ int sz = tsize(t, p->dimoff, p->sizoff) / SZCHAR;
		if (sz % (SZINT/SZCHAR))
			sz += (SZINT/SZCHAR) - (sz % (SZINT/SZCHAR));
		printf("	.lcomm	L%d,%d\n", i, sz);
		}
#endif
		psline();
		printf("	movab	L%d,r1\n", i);

		reached = 1;
		l = block( REG, NIL, NIL, PTR|t, p->dimoff, p->sizoff );
		l->tn.rval = 1;  /* R1 */
		l->tn.lval = 0;  /* no offset */
		r = block( REG, NIL, NIL, PTR|t, p->dimoff, p->sizoff );
		r->tn.rval = 0;  /* R0 */
		r->tn.lval = 0;
		l = buildtree( UNARY MUL, l, NIL );
		r = buildtree( UNARY MUL, r, NIL );
		l = buildtree( ASSIGN, l, r );
		l->in.op = FREE;
		ecomp( l->in.left );
		printf( "	movab	L%d,r0\n", i );
		/* turn off strftn flag, so return sequence will be generated */
		strftn = 0;
		}
	branch( retlab );
	p2bend();
	fdefflag = 0;
	}

int ftlab1, ftlab2;

bfcode( a, n ) int a[]; {
	/* code for the beginning of a function; a is an array of
		indices in stab for the arguments; n is the number */
	register i;
	register temp;
	register struct symtab *p;
	int off;
#ifdef REG_CHAR
	char *toreg();
#endif
	char *rname();

D 5
	locctr( PROG );
E 5
I 5
	if( nerrors ) return;
	(void) locctr( PROG );
E 5
	p = &stab[curftn];
D 3
	printf( "	.align	1\n");
E 3
I 3
	putstr( "	.align	1\n");
E 3
	defnam( p );
	temp = p->stype;
	temp = DECREF(temp);
	strftn = (temp==STRTY) || (temp==UNIONTY);

	retlab = getlab();

	/* routine prolog */

	printf( "	.word	L%d\n", ftnno);
D 4
	if (gdebug) {
#ifdef STABDOT
		pstabdot(N_SLINE, lineno);
#else
		pstab(NULLNAME, N_SLINE);
		printf("0,%d,LL%d\n", lineno, labelno);
		printf("LL%d:\n", labelno++);
#endif
	}
E 4
	ftlab1 = getlab();
	ftlab2 = getlab();
	printf( "	jbr 	L%d\n", ftlab1);
	printf( "L%d:\n", ftlab2);
	if( proflg ) {	/* profile code */
		i = getlab();
		printf("	pushl	$L%d\n", i);
D 3
		printf("	callf	$8,mcount\n");
		printf("	.data\n");
		printf("	.align	2\n");
E 3
I 3
		putstr("	callf	$8,mcount\n");
		putstr("	.data\n");
		putstr("	.align	2\n");
E 3
		printf("L%d:	.long	0\n", i);
D 3
		printf("	.text\n");
E 3
I 3
		putstr("	.text\n");
E 3
		psline();
		}

	off = ARGINIT;

	for( i=0; i<n; ++i ){
		p = &stab[a[i]];
		if( p->sclass == REGISTER ){
			temp = p->offset;  /* save register number */
			p->sclass = PARAM;  /* forget that it is a register */
			p->offset = NOOFFSET;
D 5
			oalloc( p, &off );
E 5
I 5
			(void) oalloc( p, &off );
E 5
#ifdef REG_CHAR
			printf( "	%s", toreg(p->stype)) );
#else
D 3
			printf("	movl");
E 3
I 3
			putstr("	movl");
E 3
#endif
			printf( "	%d(fp),%s\n", p->offset/SZCHAR, rname(temp) );
			p->offset = temp;  /* remember register number */
			p->sclass = REGISTER;   /* remember that it is a register */
#ifdef REG_CHAR
			temp = p->stype;
			if( temp==CHAR || temp==SHORT )
				p->stype = INT;
			else if( temp==UCHAR || temp==USHORT )
				p->stype = UNSIGNED;
#endif
			}
		else if( p->stype == STRTY || p->stype == UNIONTY ) {
			p->offset = NOOFFSET;
			if( oalloc( p, &off ) ) cerror( "bad argument" );
			SETOFF( off, ALSTACK );
			}
		else {
			if( oalloc( p, &off ) ) cerror( "bad argument" );
			}

		}
I 4
D 5
	if (gdebug) {
E 5
I 5
	if (gdebug && !nerrors) {
E 5
#ifdef STABDOT
		pstabdot(N_SLINE, lineno);
#else
		pstab(NULLNAME, N_SLINE);
		printf("0,%d,LL%d\n", lineno, labelno);
		printf("LL%d:\n", labelno++);
#endif
D 5
	}
E 5
I 5
		}
E 5
E 4
	fdefflag = 1;
	}

bccode(){ /* called just before the first executable statment */
		/* by now, the automatics and register variables are allocated */
	SETOFF( autooff, SZINT );
	/* set aside store area offset */
	p2bbeg( autooff, regvar );
	}

I 5
/*ARGSUSED*/
E 5
ejobcode( flag ){
	/* called just before final exit */
	/* flag is 1 if errors, 0 if none */
	}

I 5
#ifndef aobeg
E 5
aobeg(){
	/* called before removing automatics from stab */
	}
I 5
#endif aobeg
E 5

I 5
#ifndef aocode
/*ARGSUSED*/
E 5
aocode(p) struct symtab *p; {
	/* called when automatic p removed from stab */
	}
I 5
#endif aocode
E 5

I 5
#ifndef aoend
E 5
aoend(){
	/* called after removing all automatics from stab */
	}
I 5
#endif aoend
E 5

defnam( p ) register struct symtab *p; {
	/* define the current location as the name p->sname */

	if( p->sclass == EXTDEF ){
		printf( "	.globl	%s\n", exname( p->sname ) );
		}
	if( p->sclass == STATIC && p->slevel>1 ) deflab( p->offset );
	else printf( "%s:\n", exname( p->sname ) );

	}

bycode( t, i ){
#ifdef ASSTRINGS
static	int	lastoctal = 0;
#endif

	/* put byte i+1 in a string */

I 5
	if ( nerrors ) return;
E 5
#ifdef ASSTRINGS

	i &= 077;
	if ( t < 0 ){
D 3
		if ( i != 0 )	printf( "\"\n" );
E 3
I 3
		if ( i != 0 )	putstr( "\"\n" );
E 3
	} else {
D 3
		if ( i == 0 ) printf("\t.ascii\t\"");
E 3
I 3
		if ( i == 0 ) putstr("\t.ascii\t\"");
E 3
		if ( t == '\\' || t == '"'){
			lastoctal = 0;
			printf("\\%c", t);
		}
		else if ( t < 040 || t >= 0177 ){
			lastoctal++;
			printf("\\%o",t);
		}
		else if ( lastoctal && '0' <= t && t <= '9' ){
			lastoctal = 0;
			printf("\"\n\t.ascii\t\"%c", t );
		}
		else
		{	
			lastoctal = 0;
			putchar(t);
		}
D 3
		if ( i == 077 ) printf("\"\n");
E 3
I 3
		if ( i == 077 ) putstr("\"\n");
E 3
	}
#else

	i &= 07;
	if( t < 0 ){ /* end of the string */
D 3
		if( i != 0 ) printf( "\n" );
E 3
I 3
		if( i != 0 ) putchar( '\n' );
E 3
		}

	else { /* stash byte t into string */
D 3
		if( i == 0 ) printf( "	.byte	" );
		else printf( "," );
E 3
I 3
		if( i == 0 ) putstr( "	.byte	" );
		else putchar( ',' );
E 3
		printf( "0x%x", t );
D 3
		if( i == 07 ) printf( "\n" );
E 3
I 3
		if( i == 07 ) putchar( '\n' );
E 3
		}
#endif
	}

zecode( n ){
	/* n integer words of zeros */
	OFFSZ temp;
	if( n <= 0 ) return;
	printf( "	.space	%d\n", (SZINT/SZCHAR)*n );
	temp = n;
	inoff += temp*SZINT;
	}

I 5
/*ARGSUSED*/
E 5
fldal( t ) unsigned t; { /* return the alignment of field of type t */
	uerror( "illegal field type" );
	return( ALINT );
	}

I 5
/*ARGSUSED*/
E 5
fldty( p ) struct symtab *p; { /* fix up type of field p */
	;
	}

I 5
/*ARGSUSED*/
E 5
where(c){ /* print location of error  */
	/* c is either 'u', 'c', or 'w' */
	/* GCOS version */
	fprintf( stderr, "%s, line %d: ", ftitle, lineno );
	}


#ifdef REG_CHAR
/* tbl - toreg() returns a pointer to a char string
		  which is the correct  "register move" for the passed type 
 */
struct type_move {TWORD fromtype; char tostrng[8];} toreg_strs[] =
	{
	CHAR, "cvtbl",
	SHORT, "cvtwl",
	UCHAR,	"movzbl",
	USHORT,	"movzwl",
	0, "movl"
	};

char
*toreg(type)
	TWORD type;
{
	struct type_move *p;

	for ( p=toreg_strs; p->fromtype != 0; p++)
		if (p->fromtype == type) return(p->tostrng);

	/* type not found, must be a word type */
	return(p->tostrng);
}
/* tbl */
#endif


main( argc, argv ) char *argv[]; {
#ifdef BUFSTDERR
	char errbuf[BUFSIZ];
	setbuf(stderr, errbuf);
#endif
	return(mainp1( argc, argv ));
	}

struct sw heapsw[SWITSZ];	/* heap for switches */

genswitch(p,n) register struct sw *p;{
	/*	p points to an array of structures, each consisting
		of a constant value and a label.
		The first is >=0 if there is a default label;
		its value is the label number
		The entries p[1] to p[n] are the nontrivial cases
		*/
	register i;
	register CONSZ j;
	register CONSZ unsigned range;
	register dlab, swlab;

I 5
	if( nerrors ) return;
E 5
	range = p[n].sval-p[1].sval;

	if( range <= 3*n && n>=4 ){ /* implement a direct switch */

		swlab = getlab();
		dlab = p->slab >= 0 ? p->slab : getlab();

		/* already in r0 */
D 3
		printf( "	casel	r0,$" );
E 3
I 3
		putstr( "	casel	r0,$" );
E 3
		printf( CONFMT, p[1].sval );
D 3
		printf(",$");
E 3
I 3
		putstr(",$");
E 3
		printf( CONFMT, range);
		printf("\n	.align 1\nL%d:\n", swlab);
		for( i=1,j=p[1].sval; i<=n; j++) {
			printf("	.word	L%d-L%d\n", (j == p[i].sval ? ((j=p[i++].sval), p[i-1].slab) : dlab),
				swlab);
			}

		if( p->slab >= 0 ) branch( dlab );
		else printf("L%d:\n", dlab);
		return;

		}

	if( n>8 ) {	/* heap switch */

		heapsw[0].slab = dlab = p->slab >= 0 ? p->slab : getlab();
		makeheap(p, n, 1);	/* build heap */

		walkheap(1, n);	/* produce code */

		if( p->slab >= 0 )
			branch( dlab );
		else
			printf("L%d:\n", dlab);
		return;
	}

	/* debugging code */

	/* out for the moment
	if( n >= 4 ) werror( "inefficient switch: %d, %d", n, (int) (range/n) );
	*/

	/* simple switch code */

	for( i=1; i<=n; ++i ){
		/* already in r0 */

D 3
		printf( "	cmpl	r0,$" );
E 3
I 3
		putstr( "	cmpl	r0,$" );
E 3
		printf( CONFMT, p[i].sval );
		printf( "\n	jeql	L%d\n", p[i].slab );
		}

	if( p->slab>=0 ) branch( p->slab );
	}

makeheap(p, m, n)
register struct sw *p;
{
	register int q;

D 5
	q = select(m);
E 5
I 5
	q = selectheap(m);
E 5
	heapsw[n] = p[q];
	if( q>1 ) makeheap(p, q-1, 2*n);
	if( q<m ) makeheap(p+q, m-q, 2*n+1);
}

D 5
select(m) {
E 5
I 5
selectheap(m) {
E 5
	register int l,i,k;

	for(i=1; ; i*=2)
		if( (i-1) > m ) break;
	l = ((k = i/2 - 1) + 1)/2;
	return( l + (m-k < l ? m-k : l));
}

walkheap(start, limit)
{
	int label;


	if( start > limit ) return;
D 3
	printf( "	cmpl	r0,$" );
E 3
I 3
	putstr( "	cmpl	r0,$" );
E 3
	printf( CONFMT, heapsw[start].sval);
	printf("\n	jeql	L%d\n", heapsw[start].slab);
	if( (2*start) > limit ) {
		printf("	jbr 	L%d\n", heapsw[0].slab);
		return;
	}
	if( (2*start+1) <= limit ) {
		label = getlab();
		printf("	jgtr	L%d\n", label);
	} else
		printf("	jgtr	L%d\n", heapsw[0].slab);
	walkheap( 2*start, limit);
	if( (2*start+1) <= limit ) {
		printf("L%d:\n", label);
		walkheap( 2*start+1, limit);
	}
}
E 1
