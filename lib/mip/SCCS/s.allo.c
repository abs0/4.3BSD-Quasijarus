h50031
s 00012/00006/00581
d D 4.10 87/12/09 23:32:59 donn 11 9
c utah rcsid 1.6 87/08/24 00:44:32: Added a PBUSY bit to mark the first
c register in a pair in the 'busy' array.  New code in usable() uses this bit
c to identify sharable register pairs.  Other code that referred directly to
c the contents of the array had to be modified slightly...
e
s 00012/00006/00581
d R 4.10 87/11/29 20:55:59 donn 10 9
c Added a PBUSY bit to mark the first register in a pair in the 'busy' array.
c New code in usable() uses this bit to identify sharable register pairs.
c Other code that referred directly to the contents of the array had to
c be modified slightly...
c 
e
s 00003/00002/00584
d D 4.9 86/10/15 22:02:55 sam 9 8
c add even register need for tahoe
e
s 00012/00005/00574
d D 4.8 86/01/08 00:25:13 donn 8 7
c Extended the test in usable() for operations that require register pairs.
c Assignments of the form 'i *= d' require that the register temporary be
c a register pair -- the lhs must be widened.
e
s 00002/00000/00577
d D 4.7 85/08/22 19:02:39 mckusick 7 6
c update from donn@utah-cs
e
s 00000/00002/00577
d D 4.6 85/04/02 11:57:26 ralph 6 5
c remove duplicate definition of TBUSY
e
s 00001/00001/00578
d D 4.5 85/03/19 13:08:20 ralph 5 4
c use common header file for C, Fortran, Pascal.
e
s 00007/00001/00572
d D 4.4 85/01/24 10:58:20 ralph 4 3
c fix allocation of register pair for logop()'s.
e
s 00004/00001/00569
d D 4.3 85/01/18 16:12:56 ralph 3 2
c changes for single precision floats; lint cleanups
e
s 00012/00000/00558
d D 4.2 84/03/14 15:22:15 ralph 2 1
c merging f1 and c1
e
s 00558/00000/00000
d D 4.1 84/03/14 15:21:07 ralph 1 0
c date and time created 84/03/14 15:21:07 by ralph
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
D 5
# include "mfile2"
E 5
I 5
# include "pass2.h"
E 5

NODE resc[3];

int busy[REGSZ];

int maxa, mina, maxb, minb;

# ifndef ALLO0
allo0(){ /* free everything */

	register i;

	maxa = maxb = -1;
	mina = minb = 0;

	REGLOOP(i){
		busy[i] = 0;
		if( rstatus[i] & STAREG ){
			if( maxa<0 ) mina = i;
			maxa = i;
			}
		if( rstatus[i] & STBREG ){
			if( maxb<0 ) minb = i;
			maxb = i;
			}
		}
	}
# endif

D 6
# define TBUSY 01000

E 6
# ifndef ALLO
allo( p, q ) NODE *p; struct optab *q; {

	register n, i, j;
	int either;

	n = q->needs;
	either = ( EITHER & n );
	i = 0;

	while( n & NACOUNT ){
		resc[i].in.op = REG;
D 9
		resc[i].tn.rval = freereg( p, n&NAMASK );
E 9
I 9
		resc[i].tn.rval = freereg( p, n&(NAMASK|NEVEN) );
E 9
		resc[i].tn.lval = 0;
#ifdef FLEXNAMES
		resc[i].in.name = "";
#else
		resc[i].in.name[0] = '\0';
#endif
I 9
		n &= ~NEVEN;		/* only used for first need */
E 9
		n -= NAREG;
		++i;
		}

	if (either) { /* all or nothing at all */
		for( j = 0; j < i; j++ )
			if( resc[j].tn.rval < 0 ) { /* nothing */
				i = 0;
				break;
				}
		if( i != 0 ) goto ok; /* all */
		}

	while( n & NBCOUNT ){
		resc[i].in.op = REG;
		resc[i].tn.rval = freereg( p, n&NBMASK );
		resc[i].tn.lval = 0;
#ifdef FLEXNAMES
		resc[i].in.name = "";
#else
		resc[i].in.name[0] = '\0';
#endif
		n -= NBREG;
		++i;
		}
	if (either) { /* all or nothing at all */
		for( j = 0; j < i; j++ )
			if( resc[j].tn.rval < 0 ) { /* nothing */
				i = 0;
				break;
				}
		if( i != 0 ) goto ok; /* all */
		}

	if( n & NTMASK ){
		resc[i].in.op = OREG;
		resc[i].tn.rval = TMPREG;
		if( p->in.op == STCALL || p->in.op == STARG || p->in.op == UNARY STCALL || p->in.op == STASG ){
			resc[i].tn.lval = freetemp( (SZCHAR*p->stn.stsize + (SZINT-1))/SZINT );
			}
		else {
			resc[i].tn.lval = freetemp( (n&NTMASK)/NTEMP );
			}
#ifdef FLEXNAMES
		resc[i].in.name = "";
#else
		resc[i].in.name[0] = '\0';
#endif

		resc[i].tn.lval = BITOOR(resc[i].tn.lval);
		++i;
		}

	/* turn off "temporarily busy" bit */

	ok:
	REGLOOP(j){
		busy[j] &= ~TBUSY;
		}

	for( j=0; j<i; ++j ) if( resc[j].tn.rval < 0 ) return(0);
	return(1);

	}
# endif

extern unsigned int offsz;
freetemp( k ){ /* allocate k integers worth of temp space */
	/* we also make the convention that, if the number of words is more than 1,
	/* it must be aligned for storing doubles... */

# ifndef BACKTEMP
	int t;

	if( k>1 ){
		SETOFF( tmpoff, ALDOUBLE );
		}

	t = tmpoff;
	tmpoff += k*SZINT;
	if( tmpoff > maxoff ) maxoff = tmpoff;
	if( tmpoff >= offsz )
		cerror( "stack overflow" );
	if( tmpoff-baseoff > maxtemp ) maxtemp = tmpoff-baseoff;
	return(t);

# else
	tmpoff += k*SZINT;
	if( k>1 ) {
		SETOFF( tmpoff, ALDOUBLE );
		}
	if( tmpoff > maxoff ) maxoff = tmpoff;
	if( tmpoff >= offsz )
		cerror( "stack overflow" );
	if( tmpoff-baseoff > maxtemp ) maxtemp = tmpoff-baseoff;
	return( -tmpoff );
# endif
	}

freereg( p, n ) NODE *p; {
	/* allocate a register of type n */
	/* p gives the type, if floating */

	register j;

	/* not general; means that only one register (the result) OK for call */
	if( callop(p->in.op) ){
		j = callreg(p);
		if( usable( p, n, j ) ) return( j );
		/* have allocated callreg first */
		}
	j = p->in.rall & ~MUSTDO;
	if( j!=NOPREF && usable(p,n,j) ){ /* needed and not allocated */
		return( j );
		}
	if( n&NAMASK ){
		for( j=mina; j<=maxa; ++j ) if( rstatus[j]&STAREG ){
			if( usable(p,n,j) ){
				return( j );
				}
			}
		}
	else if( n &NBMASK ){
		for( j=minb; j<=maxb; ++j ) if( rstatus[j]&STBREG ){
			if( usable(p,n,j) ){
				return(j);
				}
			}
		}

	return( -1 );
	}

# ifndef USABLE
usable( p, n, r ) NODE *p; {
	/* decide if register r is usable in tree p to satisfy need n */

	/* checks, for the moment */
	if( !istreg(r) ) cerror( "usable asked about nontemp register" );

D 11
	if( busy[r] > 1 ) return(0);
E 11
I 11
	if( ISBUSY(r) ) return(0);
E 11
	if( isbreg(r) ){
		if( n&NAMASK ) return(0);
		}
	else {
		if( n & NBMASK ) return(0);
		}
D 4
	if( (n&NAMASK) && (szty(p->in.type) == 2) ){ /* only do the pairing for real regs */
E 4
I 4
	/*
D 8
	 * Have to check for ==, <=, etc. because the result is type INT
	 * but need a register pair temp if either side is real.
E 8
I 8
	 * Some special cases that require register pairs...
	 * Have to check for ==, <=, etc. because the result is type int
	 * but need a register pair temp if either side is wide.
	 * For +=, *= etc. where lhs is narrow and rhs is wide, the temp
	 * register must be wide.
E 8
	 */
D 8
	if( (n&NAMASK) && (szty(p->in.type) == 2 ||
	    logop(p->in.op) && (szty(p->in.left->in.type) == 2 ||
	    szty(p->in.right->in.type) == 2)) ){ /* only do the pairing for real regs */
E 8
I 8
	if( (n&NAMASK) &&
D 9
	    (szty(p->in.type) == 2 ||
E 9
I 9
	    (szty(p->in.type) == 2 || (n&NEVEN) ||
E 9
	     (logop(p->in.op) && (szty(p->in.left->in.type) == 2 ||
	      szty(p->in.right->in.type) == 2)) ||
	     (asgop(p->in.op) && szty(p->in.right->in.type) == 2 &&
	      szty(p->in.left->in.type) == 1))
	){
E 8
E 4
I 2
#ifndef NOEVENODD
E 2
		if( r&01 ) return(0);
I 2
#endif
E 2
		if( !istreg(r+1) ) return( 0 );
		if( busy[r+1] > 1 ) return( 0 );
		if( busy[r] == 0 && busy[r+1] == 0  ||
D 11
		    busy[r+1] == 0 && shareit( p, r, n ) ||
E 11
I 11
		    (busy[r+1] == 0 || (busy[r] & PBUSY)) &&
			shareit( p, r, n ) ||
E 11
		    busy[r] == 0 && shareit( p, r+1, n ) ){
			busy[r] |= TBUSY;
			busy[r+1] |= TBUSY;
			return(1);
			}
		else return(0);
		}
	if( busy[r] == 0 ) {
		busy[r] |= TBUSY;
		return(1);
		}

	/* busy[r] is 1: is there chance for sharing */
	return( shareit( p, r, n ) );

	}
# endif

shareit( p, r, n ) NODE *p; {
	/* can we make register r available by sharing from p
	   given that the need is n */
	if( (n&(NASL|NBSL)) && ushare( p, 'L', r ) ) return(1);
	if( (n&(NASR|NBSR)) && ushare( p, 'R', r ) ) return(1);
	return(0);
	}

ushare( p, f, r ) NODE *p; {
	/* can we find a register r to share on the left or right
		(as f=='L' or 'R', respectively) of p */
	p = getlr( p, f );
	if( p->in.op == UNARY MUL ) p = p->in.left;
	if( p->in.op == OREG ){
		if( R2TEST(p->tn.rval) ){
			return( r==R2UPK1(p->tn.rval) || r==R2UPK2(p->tn.rval) );
			}
		else return( r == p->tn.rval );
		}
	if( p->in.op == REG ){
		return( r == p->tn.rval || ( szty(p->in.type) == 2 && r==p->tn.rval+1 ) );
		}
	return(0);
	}

recl2( p ) register NODE *p; {
	register r = p->tn.rval;
#ifndef OLD
	int op = p->in.op;
	if (op == REG && r >= REGSZ)
		op = OREG;
	if( op == REG ) rfree( r, p->in.type );
	else if( op == OREG ) {
		if( R2TEST( r ) ) {
			if( R2UPK1( r ) != 100 ) rfree( R2UPK1( r ), PTR+INT );
			rfree( R2UPK2( r ), INT );
			}
		else {
			rfree( r, PTR+INT );
			}
		}
#else
	if( p->in.op == REG ) rfree( r, p->in.type );
	else if( p->in.op == OREG ) {
		if( R2TEST( r ) ) {
			if( R2UPK1( r ) != 100 ) rfree( R2UPK1( r ), PTR+INT );
			rfree( R2UPK2( r ), INT );
			}
		else {
			rfree( r, PTR+INT );
			}
		}
#endif
	}

int rdebug = 0;

# ifndef RFREE
rfree( r, t ) TWORD t; {
	/* mark register r free, if it is legal to do so */
	/* t is the type */

# ifndef BUG3
	if( rdebug ){
		printf( "rfree( %s ), size %d\n", rnames[r], szty(t) );
		}
# endif

	if( istreg(r) ){
		if( --busy[r] < 0 ) cerror( "register overfreed");
I 11
		if( busy[r] == PBUSY )
			busy[r] = 0;
E 11
		if( szty(t) == 2 ){
I 2
#ifdef NOEVENODD
			if( istreg(r) ^ istreg(r+1) ) cerror( "illegal free" );
#else
E 2
			if( (r&01) || (istreg(r)^istreg(r+1)) ) cerror( "illegal free" );
I 2
#endif
E 2
			if( --busy[r+1] < 0 ) cerror( "register overfreed" );
			}
		}
	}
# endif

# ifndef RBUSY
rbusy(r,t) TWORD t; {
	/* mark register r busy */
	/* t is the type */

# ifndef BUG3
	if( rdebug ){
		printf( "rbusy( %s ), size %d\n", rnames[r], szty(t) );
		}
# endif

	if( istreg(r) ) ++busy[r];
	if( szty(t) == 2 ){
D 11
		if( istreg(r+1) ) ++busy[r+1];
E 11
I 11
		if( istreg(r+1) ) {
			++busy[r+1];
			busy[r] |= PBUSY;
			}
E 11
I 2
#ifdef NOEVENODD
		if( istreg(r) ^ istreg(r+1) ) cerror( "illegal register pair freed" );
#else
E 2
		if( (r&01) || (istreg(r)^istreg(r+1)) ) cerror( "illegal register pair freed" );
I 2
#endif
E 2
		}
	}
# endif

# ifndef BUG3
rwprint( rw ){ /* print rewriting rule */
	register i, flag;
	static char * rwnames[] = {

		"RLEFT",
		"RRIGHT",
		"RESC1",
		"RESC2",
		"RESC3",
		0,
		};

	if( rw == RNULL ){
		printf( "RNULL" );
		return;
		}

	if( rw == RNOP ){
		printf( "RNOP" );
		return;
		}

	flag = 0;
	for( i=0; rwnames[i]; ++i ){
		if( rw & (1<<i) ){
			if( flag ) printf( "|" );
			++flag;
			printf( rwnames[i] );
			}
		}
	}
# endif

reclaim( p, rw, cookie ) NODE *p; {
	register NODE **qq;
	register NODE *q;
	register i;
	NODE *recres[5];
	struct respref *r;

	/* get back stuff */

# ifndef BUG3
	if( rdebug ){
		printf( "reclaim( %o, ", p );
		rwprint( rw );
		printf( ", " );
		prcook( cookie );
		printf( " )\n" );
		}
# endif

	if( rw == RNOP || ( p->in.op==FREE && rw==RNULL ) ) return;  /* do nothing */

	walkf( p, recl2 );

	if( callop(p->in.op) ){
		/* check that all scratch regs are free */
		callchk(p);  /* ordinarily, this is the same as allchk() */
		}

	if( rw == RNULL || (cookie&FOREFF) ){ /* totally clobber, leaving nothing */
		tfree(p);
		return;
		}

	/* handle condition codes specially */

	if( (cookie & FORCC) && (rw&RESCC)) {
		/* result is CC register */
		tfree(p);
		p->in.op = CCODES;
		p->tn.lval = 0;
		p->tn.rval = 0;
		return;
		}

	/* locate results */

	qq = recres;

	if( rw&RLEFT) *qq++ = getlr( p, 'L' );;
	if( rw&RRIGHT ) *qq++ = getlr( p, 'R' );
	if( rw&RESC1 ) *qq++ = &resc[0];
	if( rw&RESC2 ) *qq++ = &resc[1];
	if( rw&RESC3 ) *qq++ = &resc[2];

	if( qq == recres ){
		cerror( "illegal reclaim");
		}

	*qq = NIL;

	/* now, select the best result, based on the cookie */

	for( r=respref; r->cform; ++r ){
		if( cookie & r->cform ){
			for( qq=recres; (q= *qq) != NIL; ++qq ){
				if( tshape( q, r->mform ) ) goto gotit;
				}
			}
		}

	/* we can't do it; die */
	cerror( "cannot reclaim");

	gotit:

	if( p->in.op == STARG ) p = p->in.left;  /* STARGs are still STARGS */

	q->in.type = p->in.type;  /* to make multi-register allocations work */
		/* maybe there is a better way! */
	q = tcopy(q);

	tfree(p);

	p->in.op = q->in.op;
	p->tn.lval = q->tn.lval;
	p->tn.rval = q->tn.rval;
#ifdef FLEXNAMES
	p->in.name = q->in.name;
#ifdef ONEPASS
	p->in.stalign = q->in.stalign;
#endif
#else
	for( i=0; i<NCHNAM; ++i )
		p->in.name[i] = q->in.name[i];
#endif

	q->in.op = FREE;

	/* if the thing is in a register, adjust the type */

	switch( p->in.op ){

	case REG:
		if( !rtyflg ){
			/* the C language requires intermediate results to change type */
			/* this is inefficient or impossible on some machines */
			/* the "T" command in match supresses this type changing */
			if( p->in.type == CHAR || p->in.type == SHORT ) p->in.type = INT;
			else if( p->in.type == UCHAR || p->in.type == USHORT ) p->in.type = UNSIGNED;
I 2
D 3
#ifndef FORT
E 3
I 3
#if !defined(FORT) && !defined(SPRECC)
E 3
E 2
			else if( p->in.type == FLOAT ) p->in.type = DOUBLE;
I 2
#endif
E 2
			}
		if( ! (p->in.rall & MUSTDO ) ) return;  /* unless necessary, ignore it */
		i = p->in.rall & ~MUSTDO;
		if( i & NOPREF ) return;
		if( i != p->tn.rval ){
			if( busy[i] || ( szty(p->in.type)==2 && busy[i+1] ) ){
				cerror( "faulty register move" );
				}
			rbusy( i, p->in.type );
			rfree( p->tn.rval, p->in.type );
			rmove( i, p->tn.rval, p->in.type );
			p->tn.rval = i;
			}

	case OREG:
		if( p->in.op == REG || !R2TEST(p->tn.rval) ) {
D 11
			if( busy[p->tn.rval]>1 && istreg(p->tn.rval) ) cerror( "potential register overwrite");
E 11
I 11
			if( ISBUSY(p->tn.rval) && istreg(p->tn.rval) ) cerror( "potential register overwrite");
E 11
			}
		else
D 11
			if( (R2UPK1(p->tn.rval) != 100 && busy[R2UPK1(p->tn.rval)]>1 && istreg(R2UPK1(p->tn.rval)) )
				|| (busy[R2UPK2(p->tn.rval)]>1 && istreg(R2UPK2(p->tn.rval)) ) )
E 11
I 11
			if( (R2UPK1(p->tn.rval) != 100 && ISBUSY(R2UPK1(p->tn.rval)) && istreg(R2UPK1(p->tn.rval)) )
				|| (ISBUSY(R2UPK2(p->tn.rval)) && istreg(R2UPK2(p->tn.rval)) ) )
E 11
			   cerror( "potential register overwrite");
		}

	}

I 7
#ifndef ncopy
E 7
ncopy( q, p ) NODE *p, *q; {
	/* copy the contents of p into q, without any feeling for
	   the contents */
	/* this code assume that copying rval and lval does the job;
	   in general, it might be necessary to special case the
	   operator types */
	register i;

	q->in.op = p->in.op;
	q->in.rall = p->in.rall;
	q->in.type = p->in.type;
	q->tn.lval = p->tn.lval;
	q->tn.rval = p->tn.rval;
#ifdef FLEXNAMES
	q->in.name = p->in.name;
#ifdef ONEPASS
	q->in.stalign = p->in.stalign;
#endif
#else
	for( i=0; i<NCHNAM; ++i ) q->in.name[i]  = p->in.name[i];
#endif

	}
I 7
#endif
E 7

NODE *
tcopy( p ) register NODE *p; {
	/* make a fresh copy of p */

	register NODE *q;
	register r;

	ncopy( q=talloc(), p );

	r = p->tn.rval;
	if( p->in.op == REG ) rbusy( r, p->in.type );
	else if( p->in.op == OREG ) {
		if( R2TEST(r) ){
			if( R2UPK1(r) != 100 ) rbusy( R2UPK1(r), PTR+INT );
			rbusy( R2UPK2(r), INT );
			}
		else {
			rbusy( r, PTR+INT );
			}
		}

	switch( optype(q->in.op) ){

	case BITYPE:
		q->in.right = tcopy(p->in.right);
	case UTYPE:
		q->in.left = tcopy(p->in.left);
		}

	return(q);
	}

allchk(){
	/* check to ensure that all register are free */

	register i;

	REGLOOP(i){
		if( istreg(i) && busy[i] ){
			cerror( "register allocation error");
			}
		}

	}
E 1
