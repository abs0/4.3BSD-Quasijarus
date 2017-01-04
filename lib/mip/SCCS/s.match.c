h00699
s 00044/00011/00643
d D 4.7 87/12/10 00:14:07 donn 7 6
c utah rcsid 1.6 87/08/24 01:07:09: (1) Added MATCHSTATS code to help profile
c the match() routine.  This will probably be removed when I get around to
c optimizing table lookups.  (2) Check ISBUSY instead of busy[] in tshape(),
c to avoid PBUSY conflicts.
e
s 00017/00007/00637
d D 4.6 87/12/10 00:13:59 donn 6 5
c utah rcsid 1.5 87/04/19 23:20:26: Add SMCON -- a SPECIAL shape which checks
c for 'negative' constants; useful in hacking unsigned arithmetic.  Cleaned
c up the code in tshape() too.
e
s 00001/00001/00643
d D 4.5 86/10/15 22:03:25 sam 5 4
c add offset specification for upput
e
s 00003/00001/00641
d D 4.4 85/08/22 19:04:15 mckusick 4 3
c update from donn@utah-cs
e
s 00001/00001/00641
d D 4.3 85/03/19 13:09:01 ralph 3 2
c use common header file for C, Fortran, Pascal.
e
s 00005/00000/00637
d D 4.2 85/01/18 16:13:54 ralph 2 1
c changes for single precision floats; lint cleanups
e
s 00637/00000/00000
d D 4.1 85/01/16 16:55:40 ralph 1 0
c date and time created 85/01/16 16:55:40 by ralph
e
u
U
t
T
I 2
#ifndef lint
E 2
I 1
static char *sccsid ="%W% (Berkeley) %G%";
I 2
#endif lint

E 2
D 3
# include "mfile2"
E 3
I 3
# include "pass2.h"
E 3

# ifdef WCARD1
# ifdef WCARD2
# define NOINDIRECT
# endif
# endif

extern vdebug;

int fldsz, fldshf;

static int mamask[] = { /* masks for matching dope with shapes */
	SIMPFLG,		/* OPSIMP */
	SIMPFLG|ASGFLG,		/* ASG OPSIMP */
	COMMFLG,	/* OPCOMM */
	COMMFLG|ASGFLG,	/* ASG OPCOMM */
	MULFLG,		/* OPMUL */
	MULFLG|ASGFLG,	/* ASG OPMUL */
	DIVFLG,		/* OPDIV */
	DIVFLG|ASGFLG,	/* ASG OPDIV */
	UTYPE,		/* OPUNARY */
	TYFLG,		/* ASG OPUNARY is senseless */
	LTYPE,		/* OPLEAF */
	TYFLG,		/* ASG OPLEAF is senseless */
	0,		/* OPANY */
	ASGOPFLG|ASGFLG,	/* ASG OPANY */
	LOGFLG,		/* OPLOG */
	TYFLG,		/* ASG OPLOG is senseless */
	FLOFLG,		/* OPFLOAT */
	FLOFLG|ASGFLG,	/* ASG OPFLOAT */
	SHFFLG,		/* OPSHFT */
	SHFFLG|ASGFLG,	/* ASG OPSHIFT */
	SPFLG,		/* OPLTYPE */
	TYFLG,		/* ASG OPLTYPE is senseless */
	};

int sdebug = 0;

tshape( p, shape ) NODE *p; {
	/* return true if shape is appropriate for the node p
	   side effect for SFLD is to set up fldsz,etc */
	register o, mask;

	o = p->in.op;

# ifndef BUG3
	if( sdebug ){
D 4
		printf( "tshape( %o, %o), op = %d\n", p, shape, o );
E 4
I 4
		printf( "tshape( %o, ", p );
		prcook( shape );
		printf( " ) op = %s\n", opst[o] );
E 4
		}
# endif

	if( shape & SPECIAL ){

		switch( shape ){
D 6

E 6
		case SZERO:
		case SONE:
		case SMONE:
		case SSCON:
		case SCCON:
I 6
		case SMCON:
E 6
			if( o != ICON || p->in.name[0] ) return(0);
D 6
			if( p->tn.lval == 0 && shape == SZERO ) return(1);
			else if( p->tn.lval == 1 && shape == SONE ) return(1);
			else if( p->tn.lval == -1 && shape == SMONE ) return(1);
			else if( p->tn.lval > -129 && p->tn.lval < 128 && shape == SCCON ) return(1);
			else if( p->tn.lval > -32769 && p->tn.lval < 32768 && shape == SSCON ) return(1);
			else return(0);
E 6
I 6
			}

		switch( shape ){

		case SZERO:
			return( p->tn.lval == 0 );
		case SONE:
			return( p->tn.lval == 1 );
		case SMONE:
			return( p->tn.lval == -1 );
		case SSCON:
			return( p->tn.lval > -32769 && p->tn.lval < 32768 );
		case SCCON:
			return( p->tn.lval > -129 && p->tn.lval < 128 );
		case SMCON:
			return( p->tn.lval < 0 );
E 6

		case SSOREG:	/* non-indexed OREG */
			if( o == OREG && !R2TEST(p->tn.rval) ) return(1);
			else return(0);

		default:
# ifdef MULTILEVEL
			if( shape & MULTILEVEL )
				return( mlmatch(p,shape,0) );
			else
# endif
			return( special( p, shape ) );
			}
		}

	if( shape & SANY ) return(1);

	if( (shape&INTEMP) && shtemp(p) ) return(1);

	if( (shape&SWADD) && (o==NAME||o==OREG) ){
		if( BYTEOFF(p->tn.lval) ) return(0);
		}

# ifdef WCARD1
	if( shape & WCARD1 )
		return( wcard1(p) & shape );
# endif

# ifdef WCARD2
	if( shape & WCARD2 )
		return( wcard2(p) & shape );
# endif
	switch( o ){

	case NAME:
		return( shape&SNAME );
	case ICON:
		mask = SCON;
		return( shape & mask );

	case FLD:
		if( shape & SFLD ){
			if( !flshape( p->in.left ) ) return(0);
			/* it is a FIELD shape; make side-effects */
			o = p->tn.rval;
			fldsz = UPKFSZ(o);
# ifdef RTOLBYTES
			fldshf = UPKFOFF(o);
# else
			fldshf = SZINT - fldsz - UPKFOFF(o);
# endif
			return(1);
			}
		return(0);

	case CCODES:
		return( shape&SCC );

	case REG:
		/* distinctions:
		SAREG	any scalar register
		STAREG	any temporary scalar register
		SBREG	any lvalue (index) register
		STBREG	any temporary lvalue register
		*/
		mask = isbreg( p->tn.rval ) ? SBREG : SAREG;
D 7
		if( istreg( p->tn.rval ) && busy[p->tn.rval]<=1 ) mask |= mask==SAREG ? STAREG : STBREG;
E 7
I 7
		if( istreg( p->tn.rval ) && !ISBUSY(p->tn.rval) ) mask |= mask==SAREG ? STAREG : STBREG;
E 7
		return( shape & mask );

	case OREG:
		return( shape & SOREG );

# ifndef NOINDIRECT
	case UNARY MUL:
		/* return STARNM or STARREG or 0 */
		return( shumul(p->in.left) & shape );
# endif

		}

	return(0);
	}

int tdebug = 0;

ttype( t, tword ) TWORD t; {
	/* does the type t match tword */

	if( tword & TANY ) return(1);

	if( t == UNDEF ) t=INT; /* void functions eased thru tables */
# ifndef BUG3
	if( tdebug ){
		printf( "ttype( %o, %o )\n", t, tword );
		}
# endif
	if( ISPTR(t) && (tword&TPTRTO) ) {
		do {
			t = DECREF(t);
		} while ( ISARY(t) );
			/* arrays that are left are usually only
			   in structure references... */
		return( ttype( t, tword&(~TPTRTO) ) );
		}
	if( t != BTYPE(t) ) return( tword & TPOINT ); /* TPOINT means not simple! */
	if( tword & TPTRTO ) return(0);

	switch( t ){

	case CHAR:
		return( tword & TCHAR );
	case SHORT:
		return( tword & TSHORT );
	case STRTY:
	case UNIONTY:
		return( tword & TSTRUCT );
	case INT:
		return( tword & TINT );
	case UNSIGNED:
		return( tword & TUNSIGNED );
	case USHORT:
		return( tword & TUSHORT );
	case UCHAR:
		return( tword & TUCHAR );
	case ULONG:
		return( tword & TULONG );
	case LONG:
		return( tword & TLONG );
	case FLOAT:
		return( tword & TFLOAT );
	case DOUBLE:
		return( tword & TDOUBLE );
		}

	return(0);
	}

struct optab *rwtable;

struct optab *opptr[DSIZE];

setrew(){
	/* set rwtable to first value which allows rewrite */
	register struct optab *q;
	register int i;

# ifdef MULTILEVEL
	/* also initialize multi-level tree links */
	mlinit();
# endif

	for( q = table; q->op != FREE; ++q ){
		if( q->needs == REWRITE ){
			rwtable = q;
			goto more;
			}
		}
	cerror( "bad setrew" );


	more:
	for( i=0; i<DSIZE; ++i ){
		if( dope[i] ){ /* there is an op... */
			for( q=table; q->op != FREE; ++q ){
				/*  beware; things like LTYPE that match
				    multiple things in the tree must
				    not try to look at the NIL at this
				    stage of things!  Put something else
				    first in table.c  */
				/* at one point, the operator matching was 15% of the
				    total comile time; thus, the function
				    call that was here was removed...
				*/

				if( q->op < OPSIMP ){
					if( q->op==i ) break;
					}
				else {
					register opmtemp;
					if((opmtemp=mamask[q->op - OPSIMP])&SPFLG){
						if( i==NAME || i==ICON || i==OREG ) break;
						else if( shltype( i, NIL ) ) break;
						}
					else if( (dope[i]&(opmtemp|ASGFLG)) == opmtemp ) break;
					}
				}
			opptr[i] = q;
			}
		}
	}

I 7
#ifdef MATCHSTATS
struct matchstats {
	unsigned ms_total;
	unsigned ms_opsimp;
	unsigned ms_opglob;
	unsigned ms_cookie;
	unsigned ms_shape;
	unsigned ms_type;
	unsigned ms_rewrite;
	unsigned ms_allo;
	unsigned ms_done;
	unsigned ms_nope;
} ms;
#define CMS(x) { ++x; continue; }
#else
#define CMS(x) continue;
#endif

E 7
match( p, cookie ) NODE *p; {
	/* called by: order, gencall
	   look for match in table and generate code if found unless
	   entry specified REWRITE.
	   returns MDONE, MNOPE, or rewrite specification from table */

	register struct optab *q;
	register NODE *r;

	rcount();
	if( cookie == FORREW ) q = rwtable;
	else q = opptr[p->in.op];

	for( ; q->op != FREE; ++q ){

		/* at one point the call that was here was over 15% of the total time;
		    thus the function call was expanded inline */
I 7
#ifdef MATCHSTATS
		++ms.ms_total;
#endif
E 7
		if( q->op < OPSIMP ){
D 7
			if( q->op!=p->in.op ) continue;
E 7
I 7
			if( q->op!=p->in.op ) CMS(ms.ms_opsimp)
E 7
			}
		else {
			register opmtemp;
			if((opmtemp=mamask[q->op - OPSIMP])&SPFLG){
				if( p->in.op!=NAME && p->in.op!=ICON && p->in.op!= OREG &&
D 7
					! shltype( p->in.op, p ) ) continue;
E 7
I 7
					! shltype( p->in.op, p ) ) CMS(ms.ms_opglob)
E 7
				}
D 7
			else if( (dope[p->in.op]&(opmtemp|ASGFLG)) != opmtemp ) continue;
E 7
I 7
			else if( (dope[p->in.op]&(opmtemp|ASGFLG)) != opmtemp ) CMS(ms.ms_opglob)
E 7
			}

D 7
		if( !(q->visit & cookie ) ) continue;
E 7
I 7
		if( !(q->visit & cookie ) ) CMS(ms.ms_cookie)
E 7
		r = getlr( p, 'L' );			/* see if left child matches */
D 7
		if( !tshape( r, q->lshape ) ) continue;
		if( !ttype( r->in.type, q->ltype ) ) continue;
E 7
I 7
		if( !tshape( r, q->lshape ) ) CMS(ms.ms_shape)
		if( !ttype( r->in.type, q->ltype ) ) CMS(ms.ms_type)
E 7
		r = getlr( p, 'R' );			/* see if right child matches */
D 7
		if( !tshape( r, q->rshape ) ) continue;
		if( !ttype( r->in.type, q->rtype ) ) continue;
E 7
I 7
		if( !tshape( r, q->rshape ) ) CMS(ms.ms_shape)
		if( !ttype( r->in.type, q->rtype ) ) CMS(ms.ms_type)
E 7

			/* REWRITE means no code from this match but go ahead
			   and rewrite node to help future match */
D 7
		if( q->needs & REWRITE ) return( q->rewrite );
		if( !allo( p, q ) ) continue;			/* if can't generate code, skip entry */
E 7
I 7
		if( q->needs & REWRITE ) {
#ifdef MATCHSTATS
			++ms.ms_rewrite;
#endif
			return( q->rewrite );
			}
		if( !allo( p, q ) ) CMS(ms.ms_allo)			/* if can't generate code, skip entry */
E 7

		/* resources are available */

		expand( p, cookie, q->cstring );		/* generate code */
		reclaim( p, q->rewrite, cookie );
I 7
#ifdef MATCHSTATS
		++ms.ms_done;
#endif
E 7

		return(MDONE);

		}
I 7

#ifdef MATCHSTATS
	++ms.ms_nope;
#endif
E 7

	return(MNOPE);
	}

int rtyflg = 0;

expand( p, cookie, cp ) NODE *p;  register char *cp; {
	/* generate code by interpreting table entry */

I 2
# ifdef NEWZZZ
E 2
	register char c;
I 2
# endif
E 2
	CONSZ val;

	rtyflg = 0;

	for( ; *cp; ++cp ){
		switch( *cp ){

		default:
			PUTCHAR( *cp );
			continue;  /* this is the usual case... */

		case 'T':
			/* rewrite register type is suppressed */
			rtyflg = 1;
			continue;

		case 'Z':  /* special machine dependent operations */
# ifdef NEWZZZ
			switch( c = *++cp ) {

			case '1':
			case '2':
			case '3':
			case 'R':
			case 'L':	/* get down first */
				zzzcode( getlr( p, c ), *++cp );
				break;
			default:   /* normal zzzcode processing otherwise */
				zzzcode( p, c );
				break;
			}
# else
			zzzcode( p, *++cp );
# endif
			continue;

		case 'F':  /* this line deleted if FOREFF is active */
			if( cookie & FOREFF ) while( *++cp != '\n' ) ; /* VOID */
			continue;

		case 'S':  /* field size */
			printf( "%d", fldsz );
			continue;

		case 'H':  /* field shift */
			printf( "%d", fldshf );
			continue;

		case 'M':  /* field mask */
		case 'N':  /* complement of field mask */
			val = 1;
			val <<= fldsz;
			--val;
			val <<= fldshf;
			adrcon( *cp=='M' ? val : ~val );
			continue;

		case 'L':  /* output special label field */
			printf( "%d", p->bn.label );
			continue;

		case 'O':  /* opcode string */
			hopcode( *++cp, p->in.op );
			continue;

		case 'B':  /* byte offset in word */
			val = getlr(p,*++cp)->tn.lval;
			val = BYTEOFF(val);
			printf( CONFMT, val );
			continue;

		case 'C': /* for constant value only */
			conput( getlr( p, *++cp ) );
			continue;

		case 'I': /* in instruction */
			insput( getlr( p, *++cp ) );
			continue;

		case 'A': /* address of */
			adrput( getlr( p, *++cp ) );
			continue;

		case 'U': /* for upper half of address, only */
D 5
			upput( getlr( p, *++cp ) );
E 5
I 5
			upput( getlr( p, *++cp ), SZLONG );
E 5
			continue;

			}

		}

	}

NODE *
getlr( p, c ) NODE *p; {

	/* return the pointer to the left or right side of p, or p itself,
	   depending on the optype of p */

	switch( c ) {

	case '1':
	case '2':
	case '3':
		return( &resc[c-'1'] );

	case 'L':
		return( optype( p->in.op ) == LTYPE ? p : p->in.left );

	case 'R':
		return( optype( p->in.op ) != BITYPE ? p : p->in.right );

		}
	cerror( "bad getlr: %c", c );
	/* NOTREACHED */
	}
# ifdef MULTILEVEL

union mltemplate{
	struct ml_head{
		int tag; /* identifies class of tree */
		int subtag; /* subclass of tree */
		union mltemplate * nexthead; /* linked by mlinit() */
		} mlhead;
	struct ml_node{
		int op; /* either an operator or op description */
		int nshape; /* shape of node */
		/* both op and nshape must match the node.
		 * where the work is to be done entirely by
		 * op, nshape can be SANY, visa versa, op can
		 * be OPANY.
		 */
		int ntype; /* type descriptor from mfile2 */
		} mlnode;
	};

# define MLSZ 30

extern union mltemplate mltree[];
int mlstack[MLSZ];
int *mlsp; /* pointing into mlstack */
NODE * ststack[MLSZ];
NODE **stp; /* pointing into ststack */

mlinit(){
	union mltemplate **lastlink;
	register union mltemplate *n;
	register mlop;

	lastlink = &(mltree[0].nexthead);
	n = &mltree[0];
	for( ; (n++)->mlhead.tag != 0;
		*lastlink = ++n, lastlink = &(n->mlhead.nexthead) ){
# ifndef BUG3
		if( vdebug )printf("mlinit: %d\n",(n-1)->mlhead.tag);
# endif
	/* wander thru a tree with a stack finding
	 * its structure so the next header can be located.
	 */
		mlsp = mlstack;

		for( ;; ++n ){
			if( (mlop = n->mlnode.op) < OPSIMP ){
				switch( optype(mlop) ){

					default:
						cerror("(1)unknown opcode: %o",mlop);
					case BITYPE:
						goto binary;
					case UTYPE:
						break;
					case LTYPE:
						goto leaf;
					}
				}
			else{
				if( mamask[mlop-OPSIMP] &
					(SIMPFLG|COMMFLG|MULFLG|DIVFLG|LOGFLG|FLOFLG|SHFFLG) ){
				binary:
					*mlsp++ = BITYPE;
					}
				else if( ! (mamask[mlop-OPSIMP] & UTYPE) ){/* includes OPANY */

				leaf:
					if( mlsp == mlstack )
						goto tree_end;
					else if ( *--mlsp != BITYPE )
						cerror("(1)bad multi-level tree descriptor around mltree[%d]",
						n-mltree);
					}
				}
			}
		tree_end: /* n points to final leaf */
		;
		}
# ifndef BUG3
		if( vdebug > 3 ){
			printf("mltree={\n");
			for( n= &(mltree[0]); n->mlhead.tag != 0; ++n)
				printf("%o: %d, %d, %o,\n",n,
				n->mlhead.tag,n->mlhead.subtag,n->mlhead.nexthead);
			printf("	}\n");
			}
# endif
	}

mlmatch( subtree, target, subtarget ) NODE * subtree; int target,subtarget;{
	/*
	 * does subtree match a multi-level tree with
	 * tag "target"?  Return zero on failure,
	 * non-zero subtag on success (or MDONE if
	 * there is a zero subtag field).
	 */
	union mltemplate *head; /* current template header */
	register union mltemplate *n; /* node being matched */
	NODE * st; /* subtree being matched */
	register int mlop;

# ifndef BUG3
	if( vdebug ) printf("mlmatch(%o,%d)\n",subtree,target);
# endif
	for( head = &(mltree[0]); head->mlhead.tag != 0;
		head=head->mlhead.nexthead){
# ifndef BUG3
		if( vdebug > 1 )printf("mlmatch head(%o) tag(%d)\n",
			head->mlhead.tag);
# endif
		if( head->mlhead.tag != target )continue;
		if( subtarget && head->mlhead.subtag != subtarget)continue;
# ifndef BUG3
		if( vdebug ) printf("mlmatch for %d\n",target);
# endif

		/* potential for match */

		n = head + 1;
		st = subtree;
		stp = ststack;
		mlsp = mlstack;
		/* compare n->op, ->nshape, ->ntype to
		 * the subtree node st
		 */
		for( ;; ++n ){ /* for each node in multi-level template */
			/* opmatch */
			if( n->op < OPSIMP ){
				if( st->op != n->op )break;
				}
			else {
				register opmtemp;
				if((opmtemp=mamask[n->op-OPSIMP])&SPFLG){
					if(st->op!=NAME && st->op!=ICON && st->op!=OREG && 
						! shltype(st->op,st)) break;
					}
				else if((dope[st->op]&(opmtemp|ASGFLG))!=opmtemp) break;
				}
			/* check shape and type */

			if( ! tshape( st, n->mlnode.nshape ) ) break;
			if( ! ttype( st->type, n->mlnode.ntype ) ) break;

			/* that node matched, let's try another */
			/* must advance both st and n and halt at right time */

			if( (mlop = n->mlnode.op) < OPSIMP ){
				switch( optype(mlop) ){

					default:
						cerror("(2)unknown opcode: %o",mlop);
					case BITYPE:
						goto binary;
					case UTYPE:
						st = st->left;
						break;
					case LTYPE:
						goto leaf;
					}
				}
			else{
				if( mamask[mlop - OPSIMP] &
					(SIMPFLG|COMMFLG|MULFLG|DIVFLG|LOGFLG|FLOFLG|SHFFLG) ){
				binary:
					*mlsp++ = BITYPE;
					*stp++ = st;
					st = st->left;
					}
				else if( ! (mamask[mlop-OPSIMP] & UTYPE) ){/* includes OPANY */

				leaf:
					if( mlsp == mlstack )
						goto matched;
					else if ( *--mlsp != BITYPE )
						cerror("(2)bad multi-level tree descriptor around mltree[%d]",
						n-mltree);
					st = (*--stp)->right;
					}
				else /* UNARY */ st = st->left;
				}
			continue;

			matched:
			/* complete multi-level match successful */
# ifndef BUG3
			if( vdebug ) printf("mlmatch() success\n");
# endif
			if( head->mlhead.subtag == 0 ) return( MDONE );
			else {
# ifndef BUG3
				if( vdebug )printf("\treturns %d\n",
					head->mlhead.subtag );
# endif
				return( head->mlhead.subtag );
				}
			}
		}
	return( 0 );
	}
# endif
E 1
