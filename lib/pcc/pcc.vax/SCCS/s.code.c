h19544
s 00005/00002/00554
d D 1.13 00/08/30 10:33:10 msokolov 13 12
c change -J to -XJ
e
s 00046/00013/00510
d D 1.12 00/08/30 01:41:28 msokolov 12 11
c generate long switch tables without word displacement limits if -J is given
e
s 00002/00001/00521
d D 1.11 00/08/04 11:20:41 msokolov 11 10
c (genswitch direct switch case): clean up redundant construct
e
s 00001/00002/00521
d D 1.10 88/05/31 20:56:16 donn 10 9
c Bleah -- deflab() can't be a macro, too many things use the side
c effects from expressions passed as arguments.
e
s 00014/00009/00509
d D 1.9 87/12/11 00:18:29 donn 9 8
c utah rcsid 1.7 87/07/17 17:30:26: Some fixes from the tahoe compiler.  (1)
c Fix 'sizeof (int)' to SZINT/SZCHAR.  (2) Don't call toreg() unless we've
c fixed the bugs with register chars.  (3) Sort the toreg() table by
c frequency (if we ever do call it, it'll be faster!).
e
s 00006/00004/00512
d D 1.8 87/12/11 00:18:18 donn 8 7
c utah rcsid 1.6 87/01/15 01:35:32: Some minor lint fixes.
e
s 00005/00000/00511
d D 1.7 87/12/11 00:18:11 donn 7 6
c utah rcsid 1.5 86/11/28 21:29:44: Add some ARGSUSED comments to shut lint
c up.
e
s 00014/00001/00497
d D 1.6 87/12/11 00:18:02 donn 6 5
c utah rcsid 1.4 86/08/03 00:59:14: Speed hacks -- turn some routines into
c macros, don't generate any code after an error.
e
s 00024/00022/00474
d D 1.5 85/08/23 15:03:04 mckusick 5 4
c update from donn@utah-cs
e
s 00001/00001/00495
d D 1.4 85/04/02 11:52:24 ralph 4 3
c use common header file for intermediate language defs.
e
s 00005/00003/00491
d D 1.3 85/01/18 15:23:12 ralph 3 2
c changes for single precision floats; lint cleanups
e
s 00009/00009/00485
d D 1.2 84/01/25 23:03:52 sam 2 1
c move .stab defining first line of a function past the entry 
c code for profiling and setting up register variables so that dbx can 
c access register variables after they've been set up and so that dbx works 
c properly with programs compiled with -p (from sun!wendy)
e
s 00494/00000/00000
d D 1.1 82/12/15 13:23:49 linton 1 0
c date and time created 82/12/15 13:23:49 by linton
e
u
U
t
T
I 3
#ifndef lint
E 3
I 1
static char *sccsid ="%W% (Berkeley) %G%";
I 3
#endif lint

E 3
D 4
# include "mfile1"
E 4
I 4
# include "pass1.h"
E 4
# include <sys/types.h>
# include <a.out.h>
# include <stab.h>

int proflg = 0;	/* are we generating profiling code? */
int strftn = 0;  /* is the current function one which returns a value */
int gdebug;
I 12
int jflag;
E 12
int fdefflag;  /* are we within a function definition ? */
I 8
#ifndef STABDOT
E 8
char NULLNAME[8];
I 8
#endif
E 8
int labelno;

I 5
# define putstr(s)	fputs((s), stdout)

E 5
branch( n ){
	/* output a branch to label n */
	/* exception is an ordinary function branching to retlab: then, return */
I 6
	if( nerrors ) return;
E 6
	if( n == retlab && !strftn ){
D 5
		printf( "	ret\n" );
E 5
I 5
		putstr( "	ret\n" );
E 5
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
I 6
	if( nerrors ) return(temp);
E 6
	switch( l ){

	case PROG:
D 5
		printf( "	.text\n" );
E 5
I 5
		putstr( "	.text\n" );
E 5
		psline();
		break;

	case DATA:
	case ADATA:
D 5
		printf( "	.data\n" );
E 5
I 5
		putstr( "	.data\n" );
E 5
		break;

	case STRNG:
D 5
		printf( "	.data	1\n" );
E 5
I 5
		putstr( "	.data	1\n" );
E 5
		break;

	case ISTRNG:
D 5
		printf( "	.data	2\n" );
E 5
I 5
		putstr( "	.data	2\n" );
E 5
		break;

	case STAB:
D 5
		printf( "	.stab\n" );
E 5
I 5
		putstr( "	.stab\n" );
E 5
		break;

	default:
		cerror( "illegal location counter" );
		}

	return( temp );
	}

I 6
D 10
#ifndef deflab
E 10
E 6
deflab( n ){
	/* output something to define the current position as label n */
I 10
	if (nerrors) return;
E 10
	printf( "L%d:\n", n );
	}
I 6
D 9
#endif deflab
E 9
I 9
D 10
#endif
E 10
E 9
E 6

int crslab = 10;

getlab(){
	/* return a number usable for a label */
	return( ++crslab );
	}


int ent_mask[] = {
	0,0,0,0,0, 0xfc0, 0xf80, 0xf00, 0xe00, 0xc00, 0x800, 0};

int reg_use = 11;

efcode(){
	/* code for the end of a function */

	if( strftn ){  /* copy output (in R2) to caller */
		register NODE *l, *r;
		register struct symtab *p;
		register TWORD t;
D 3
		register int j;
E 3
		int i;

		p = &stab[curftn];
		t = p->stype;
		t = DECREF(t);

		deflab( retlab );

		i = getlab();	/* label for return area */
#ifndef LCOMM
D 5
		printf("	.data\n" );
		printf("	.align	2\n" );
E 5
I 5
		putstr("	.data\n" );
		putstr("	.align	2\n" );
E 5
		printf("L%d:	.space	%d\n", i, tsize(t, p->dimoff, p->sizoff)/SZCHAR );
D 5
		printf("	.text\n" );
E 5
I 5
		putstr("	.text\n" );
E 5
#else
		{ int sz = tsize(t, p->dimoff, p->sizoff) / SZCHAR;
D 9
		if (sz % sizeof (int))
			sz += sizeof (int) - (sz % sizeof (int));
E 9
I 9
		if (sz % (SZINT/SZCHAR))
			sz += (SZINT/SZCHAR) - (sz % (SZINT/SZCHAR));
E 9
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
#ifndef VMS
	printf( "	.set	L%d,0x%x\n", ftnno, ent_mask[reg_use] );
#else
	printf( "	.set	L%d,%d	# Hex = 0x%x\n", ftnno, 0x3c| ent_mask[reg_use], ent_mask[reg_use]  );
	/* KLS kludge, under VMS if you use regs 2-5, you must save them. */
#endif
	reg_use = 11;
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
I 9
#ifdef TRUST_REG_CHAR_AND_REG_SHORT
E 9
	char *toreg();
I 9
#endif
E 9

I 6
	if( nerrors ) return;
E 6
D 8
	locctr( PROG );
E 8
I 8
	(void) locctr( PROG );
E 8
	p = &stab[curftn];
D 5
	printf( "	.align	1\n");
E 5
I 5
	putstr( "	.align	1\n");
E 5
	defnam( p );
	temp = p->stype;
	temp = DECREF(temp);
	strftn = (temp==STRTY) || (temp==UNIONTY);

	retlab = getlab();

	/* routine prolog */

	printf( "	.word	L%d\n", ftnno);
D 2
	if (gdebug) {
#ifdef STABDOT
		pstabdot(N_SLINE, lineno);
#else
		pstab(NULLNAME, N_SLINE);
		printf("0,%d,LL%d\n", lineno, labelno);
		printf("LL%d:\n", labelno++);
#endif
	}
E 2
	ftlab1 = getlab();
	ftlab2 = getlab();
	printf( "	jbr 	L%d\n", ftlab1);
	printf( "L%d:\n", ftlab2);
	if( proflg ) {	/* profile code */
		i = getlab();
		printf("	movab	L%d,r0\n", i);
D 5
		printf("	jsb 	mcount\n");
		printf("	.data\n");
		printf("	.align	2\n");
E 5
I 5
		putstr("	jsb 	mcount\n");
		putstr("	.data\n");
		putstr("	.align	2\n");
E 5
		printf("L%d:	.long	0\n", i);
D 5
		printf("	.text\n");
E 5
I 5
		putstr("	.text\n");
E 5
		psline();
		}

	off = ARGINIT;

	for( i=0; i<n; ++i ){
		p = &stab[a[i]];
		if( p->sclass == REGISTER ){
			temp = p->offset;  /* save register number */
			p->sclass = PARAM;  /* forget that it is a register */
			p->offset = NOOFFSET;
D 8
			oalloc( p, &off );
E 8
I 8
			(void) oalloc( p, &off );
I 9
#ifdef TRUST_REG_CHAR_AND_REG_SHORT /* and reg double */
E 9
E 8
/*tbl*/		printf( "	%s	%d(ap),r%d\n", toreg(p->stype), p->offset/SZCHAR, temp );
I 9
#else
/*tbl*/		printf( "	movl	%d(ap),r%d\n", p->offset/SZCHAR, temp );
#endif
E 9
			p->offset = temp;  /* remember register number */
			p->sclass = REGISTER;   /* remember that it is a register */
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
I 2
D 6
	if (gdebug) {
E 6
I 6
	if (gdebug && !nerrors) {
E 6
#ifdef STABDOT
		pstabdot(N_SLINE, lineno);
#else
		pstab(NULLNAME, N_SLINE);
		printf("0,%d,LL%d\n", lineno, labelno);
		printf("LL%d:\n", labelno++);
#endif
	}
E 2
	fdefflag = 1;
	}

bccode(){ /* called just before the first executable statment */
		/* by now, the automatics and register variables are allocated */
	SETOFF( autooff, SZINT );
	/* set aside store area offset */
	p2bbeg( autooff, regvar );
	reg_use = (reg_use > regvar ? regvar : reg_use);
	}

I 7
/*ARGSUSED*/
E 7
ejobcode( flag ){
	/* called just before final exit */
	/* flag is 1 if errors, 0 if none */
	}

I 6
#ifndef aobeg
E 6
aobeg(){
	/* called before removing automatics from stab */
	}
I 6
#endif aobeg
E 6

I 6
#ifndef aocode
I 7
/*ARGSUSED*/
E 7
E 6
aocode(p) struct symtab *p; {
	/* called when automatic p removed from stab */
	}
I 6
#endif aocode
E 6

I 6
#ifndef aoend
E 6
aoend(){
	/* called after removing all automatics from stab */
	}
I 6
#endif aoend
E 6

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

I 6
	if ( nerrors ) return;
E 6
#ifdef ASSTRINGS

	i &= 077;
	if ( t < 0 ){
D 5
		if ( i != 0 )	printf( "\"\n" );
E 5
I 5
		if ( i != 0 )	putstr( "\"\n" );
E 5
	} else {
D 5
		if ( i == 0 ) printf("\t.ascii\t\"");
E 5
I 5
		if ( i == 0 ) putstr("\t.ascii\t\"");
E 5
		if ( t == '\\' || t == '"'){
			lastoctal = 0;
			printf("\\%c", t);
		}
			/*
			 *	We escape the colon in strings so that
			 *	c2 will, in its infinite wisdom, interpret
			 *	the characters preceding the colon as a label.
			 *	If we didn't escape the colon, c2 would
			 *	throw away any trailing blanks or tabs after
			 *	the colon, but reconstruct a assembly
			 *	language semantically correct program.
			 *	C2 hasn't been taught about strings.
			 */
		else if ( t == ':' || t < 040 || t >= 0177 ){
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
D 5
		if ( i == 077 ) printf("\"\n");
E 5
I 5
		if ( i == 077 ) putstr("\"\n");
E 5
	}
#else

	i &= 07;
	if( t < 0 ){ /* end of the string */
D 5
		if( i != 0 ) printf( "\n" );
E 5
I 5
		if( i != 0 ) putchar( '\n' );
E 5
		}

	else { /* stash byte t into string */
D 5
		if( i == 0 ) printf( "	.byte	" );
		else printf( "," );
E 5
I 5
		if( i == 0 ) putstr( "	.byte	" );
		else putchar( ',' );
E 5
		printf( "0x%x", t );
D 5
		if( i == 07 ) printf( "\n" );
E 5
I 5
		if( i == 07 ) putchar( '\n' );
E 5
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

I 7
/*ARGSUSED*/
E 7
fldal( t ) unsigned t; { /* return the alignment of field of type t */
	uerror( "illegal field type" );
	return( ALINT );
	}

I 7
/*ARGSUSED*/
E 7
fldty( p ) struct symtab *p; { /* fix up type of field p */
	;
	}

I 7
/*ARGSUSED*/
E 7
where(c){ /* print location of error  */
	/* c is either 'u', 'c', or 'w' */
	/* GCOS version */
	fprintf( stderr, "%s, line %d: ", ftitle, lineno );
	}


I 9
#ifdef TRUST_REG_CHAR_AND_REG_SHORT
E 9
/* tbl - toreg() returns a pointer to a char string
		  which is the correct  "register move" for the passed type 
 */
struct type_move {TWORD fromtype; char tostrng[8];} toreg_strs[] =
	{
I 9
	INT, "movl",
	UNSIGNED,	"movl",
	DOUBLE, "movq",
E 9
	CHAR, "cvtbl",
	SHORT, "cvtwl",
D 9
	INT, "movl",
	LONG, "movl",
	FLOAT, "movf",
	DOUBLE, "movd",
E 9
	UCHAR,	"movzbl",
	USHORT,	"movzwl",
D 9
	UNSIGNED,	"movl",
	ULONG,	"movl",
E 9
D 3
	-1, ""
E 3
I 3
	0, ""
E 3
	};

char
*toreg(type)
	TWORD type;
{
	struct type_move *p;

D 3
	for ( p=toreg_strs; p->fromtype > 0; p++)
E 3
I 3
	for ( p=toreg_strs; p->fromtype != 0; p++)
E 3
		if (p->fromtype == type) return(p->tostrng);

	/* type not found, must be a pointer type */
	return("movl");
}
/* tbl */
I 9
#endif
E 9


D 12
main( argc, argv ) char *argv[]; {
E 12
I 12
main(argc, argv)
	char *argv[];
{
	register int i;
I 13
	register char *cp;
E 13
E 12
#ifdef BUFSTDERR
	char errbuf[BUFSIZ];
	setbuf(stderr, errbuf);
#endif
D 12
	return(mainp1( argc, argv ));
	}
E 12
I 12
	for (i = 1; i < argc; i++)
D 13
		if (argv[i][0] == '-' && argv[i][1] == 'J')
			jflag++;
E 13
I 13
		if (argv[i][0] == '-' && argv[i][1] == 'X')
			for (cp = &argv[i][2]; *cp; cp++)
				if (*cp == 'J')
					jflag++;
E 13
	return(mainp1(argc, argv));
}
E 12

struct sw heapsw[SWITSZ];	/* heap for switches */

genswitch(p,n) register struct sw *p;{
	/*	p points to an array of structures, each consisting
		of a constant value and a label.
		The first is >=0 if there is a default label;
		its value is the label number
		The entries p[1] to p[n] are the nontrivial cases
		*/
	register i;
	register CONSZ j, range;
	register dlab, swlab;

I 6
	if( nerrors ) return;
E 6
	range = p[n].sval-p[1].sval;

	if( range>0 && range <= 3*n && n>=4 ){ /* implement a direct switch */

I 12
		/* the switch expression value in r0 */
E 12
		swlab = getlab();
		dlab = p->slab >= 0 ? p->slab : getlab();

D 12
		/* already in r0 */
		printf("	casel	r0,$%ld,$%ld\n", p[1].sval, range);
		printf("L%d:\n", swlab);
		for( i=1,j=p[1].sval; i<=n; j++) {
D 11
			printf("	.word	L%d-L%d\n", (j == p[i].sval ? ((j=p[i++].sval), p[i-1].slab) : dlab),
E 11
I 11
			printf("	.word	L%d-L%d\n",
				(j == p[i].sval ? p[i++].slab : dlab),
E 11
				swlab);
			}
E 12
I 12
		if (!jflag) {
			/*
			 * Generate a CASEL instruction. Nice and efficient,
			 * but limited to word displacements.
			 */
			printf("	casel	r0,$%ld,$%ld\n", p[1].sval,
			       range);
			printf("L%d:\n", swlab);
			for (i = 1, j = p[1].sval; i <= n; j++)
				printf("	.word	L%d-L%d\n",
				       (j == p[i].sval ? p[i++].slab : dlab),
				       swlab);
		} else {
			/*
			 * Generate a table of absolute addresses. Longer and
			 * can't use the nice CASEL instruction, but no limit
			 * on displacements.
			 */
			if (p[1].sval > 0)
				printf("	subl2	$%ld,r0\n", p[1].sval);
			if (p[1].sval < 0)
				printf("	addl2	$%ld,r0\n", -p[1].sval);
			printf("	cmpl	$%ld,r0\n", range);
			printf("	jlssu	L%d\n", dlab);
			printf("	ashl	$2,r0,r0\n");
			printf("	jmp	*L%d(r0)\n", swlab);
			printf("L%d:\n", swlab);
			for (i = 1, j = p[1].sval; i <= n; j++)
				printf("	.long	L%d\n",
				       (j == p[i].sval ? p[i++].slab : dlab));
		}
E 12

D 12
		if( p->slab >= 0 ) branch( dlab );
		else printf("L%d:\n", dlab);
E 12
I 12
		if (p->slab >= 0 && !jflag)
			branch(dlab);
		if (p->slab < 0)
			printf("L%d:\n", dlab);
E 12
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

D 5
		printf( "	cmpl	r0,$" );
E 5
I 5
		putstr( "	cmpl	r0,$" );
E 5
		printf( CONFMT, p[i].sval );
		printf( "\n	jeql	L%d\n", p[i].slab );
		}

	if( p->slab>=0 ) branch( p->slab );
	}

makeheap(p, m, n)
register struct sw *p;
{
	register int q;

D 8
	q = select(m);
E 8
I 8
	q = selectheap(m);
E 8
	heapsw[n] = p[q];
	if( q>1 ) makeheap(p, q-1, 2*n);
	if( q<m ) makeheap(p+q, m-q, 2*n+1);
}

D 8
select(m) {
E 8
I 8
selectheap(m) {
E 8
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
	printf("	cmpl	r0,$%d\n",  heapsw[start].sval);
	printf("	jeql	L%d\n", heapsw[start].slab);
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
