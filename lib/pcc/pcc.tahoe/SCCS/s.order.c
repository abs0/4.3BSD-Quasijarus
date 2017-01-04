h63655
s 00001/00002/00493
d D 1.7 88/05/31 21:25:26 donn 7 6
c Bleah -- deflab() can't be a macro, too many things use the side
c effects from expressions passed as arguments.
e
s 00002/00002/00493
d D 1.6 88/02/20 01:46:38 donn 6 5
c Better estimate of ediv register requirements in sucomp() -- a function call
c in the right operand failed to force a store.
e
s 00001/00001/00494
d D 1.5 87/12/10 23:08:42 donn 5 4
c utah rcsid 1.4 87/11/29 20:23:26: Fix a syntax error in sucomp() (sigh...).
e
s 00012/00014/00483
d D 1.4 87/12/10 23:08:32 donn 4 3
c utah rcsid 1.3 87/07/19 19:48:42: Minor bug fixes and enhancements from the
c vax compiler.  (1) Add more permitted types for in-memory objects in
c sucomp().  (2) Delete redundant SCONV case in sucomp().  (3) Replace sizeof
c (int) with SZINT/SCHAR.  (4) Fix bug in call to offstar() in setincr().
c (5) Add lint food.
e
s 00006/00001/00491
d D 1.3 87/12/10 23:08:19 donn 3 2
c utah rcsid 1.2 87/05/02 14:40:36: Permit deflab() to be a macro; bump the
c starting value of crslab so that huge sources don't run out of labels; add
c some ARGSUSED lint tidbits.
e
s 00001/00001/00491
d D 1.2 86/02/04 22:19:50 sam 2 1
c new include files
e
s 00492/00000/00000
d D 1.1 86/01/11 11:00:55 sam 1 0
c date and time created 86/01/11 11:00:55 by sam
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
# include "mfile2"
E 2
I 2
# include "pass2.h"
E 2

int maxargs = { -1 };

I 3
/*ARGSUSED*/
E 3
stoasg( p, o ) NODE *p; {
	/* should the assignment op p be stored,
	   given that it lies as the right operand of o
	   (or the left, if o==UNARY MUL) */
	}

deltest( p ) register NODE *p; {
	/* should we delay the INCR or DECR operation p */
	p = p->in.left;
	return( p->in.op == REG || p->in.op == NAME || p->in.op == OREG );
	}

I 3
/*ARGSUSED*/
E 3
autoincr( p ) NODE *p; {

	return(0);
	}

mkadrs(p) register NODE *p; {
	register int o;

	o = p->in.op;

	if( asgop(o) ){
		if( p->in.left->in.su >= p->in.right->in.su ){
			if( p->in.left->in.op == UNARY MUL ){
				SETSTO( p->in.left->in.left, INTEMP );
				}
			else if( p->in.left->in.op == FLD && p->in.left->in.left->in.op == UNARY MUL ){
				SETSTO( p->in.left->in.left->in.left, INTEMP );
				}
			else { /* should be only structure assignment */
				SETSTO( p->in.left, INTEMP );
				}
			}
		else SETSTO( p->in.right, INTEMP );
		}
	else {
		if( p->in.left->in.su > p->in.right->in.su ){
			SETSTO( p->in.left, INTEMP );
			}
		else {
			SETSTO( p->in.right, INTEMP );
			}
		}
	}

I 3
/*ARGSUSED*/
E 3
notoff( t, r, off, cp) TWORD t; CONSZ off; char *cp; {
	/* is it legal to make an OREG or NAME entry which has an
	/* offset of off, (from a register of r), if the
	/* resulting thing had type t */

	return(0);  /* YES */
	}

# define max(x,y) ((x)<(y)?(y):(x))

sucomp( p ) register NODE *p; {

	/* set the su field in the node to the sethi-ullman
	   number, or local equivalent */

	register int o, ty, sul, sur, r;

	o = p->in.op;
	ty = optype( o );
	p->in.su = szty( p->in.type );   /* 2 for double, else 1 */;

	if( ty == LTYPE ){
		if( o == OREG ){
			r = p->tn.rval;
			/* oreg cost is (worst case) 1 + number of temp registers used */
			if( R2TEST(r) ){
				if( R2UPK1(r)!=100 && istreg(R2UPK1(r)) ) ++p->in.su;
				if( istreg(R2UPK2(r)) ) ++p->in.su;
				}
			else {
				if( istreg( r ) ) ++p->in.su;
				}
			}
		if( p->in.su == szty(p->in.type) &&
		   (p->in.op!=REG || !istreg(p->tn.rval)) &&
D 4
		   (p->in.type==INT || p->in.type==UNSIGNED || p->in.type==DOUBLE) )
E 4
I 4
		   (p->in.type==INT ||
		    p->in.type==UNSIGNED ||
		    p->in.type==FLOAT ||
		    p->in.type==DOUBLE ||
		    ISPTR(p->in.type) ||
D 5
		    ISARY(p->in.type) )
E 5
I 5
		    ISARY(p->in.type)) )
E 5
E 4
			p->in.su = 0;
		return;
		}

	else if( ty == UTYPE ){
		switch( o ) {
		case UNARY CALL:
		case UNARY STCALL:
			p->in.su = fregs;  /* all regs needed */
			return;

		default:
			p->in.su = p->in.left->in.su +
			(szty(p->in.type) >1 ? 2 : 0);
			return;
			}
		}


	/* If rhs needs n, lhs needs m, regular su computation */

	sul = p->in.left->in.su;
	sur = p->in.right->in.su;

	if( o == ASSIGN ){
		/* computed by doing right, then left (if not in mem), then doing it */
		p->in.su = max(sur,sul+1);
		return;
		}

	if( o == CALL || o == STCALL ){
		/* in effect, takes all free registers */
		p->in.su = fregs;
		return;
		}

	if( o == STASG ){
		/* right, then left */
		p->in.su = max( max( 1+sul, sur), fregs );
		return;
		}

	if( asgop(o) ){
		/* computed by doing right, doing left address, doing left, op, and store */
		if(optype(p->in.left->in.op) != LTYPE)
			sul++;
		/* ediv uses more regs */
		if(o==ASG DIV && p->in.left->in.type==UNSIGNED || o==ASG MOD){
D 6
			p->in.su = max(max(sur,sul+(sur!=0)),4+(sul!=0)+(sur!=0));
E 6
I 6
			p->in.su = max(max(sul,(sul!=0)+2),sur+1);
E 6
			return;
			}
		p->in.su = max(sur,sul+1);
		return;
		}

	switch( o ){
	case ANDAND:
	case OROR:
	case QUEST:
	case COLON:
	case COMOP:
		p->in.su = max( max(sul,sur), 1);
		return;

	case PLUS:
	case MUL:
	case OR:
	case ER:
		/* commutative ops; put harder on left */
		if( p->in.right->in.su > p->in.left->in.su && !istnode(p->in.left) ){
			register NODE *temp;
			temp = p->in.left;
			p->in.left = p->in.right;
			p->in.right = temp;
			}
		break;
	case DIV:
		/* ediv uses more regs */
		if(p->in.left->in.type!=UNSIGNED)
			break;
	case MOD:
D 6
		p->in.su = max(max(sul,sur+(sul!=0)),4+(sul!=0)+(sur!=0));
E 6
I 6
		p->in.su = max(max(sul,(sul!=0)+2),sur+1);
E 6
		return;
D 4
	case SCONV:
		p->in.su = max(sul,szty(p->in.right->in.type)+sur)+2;
		return;
E 4
		}
	/* binary op, computed by left, then right, then do op */
	p->in.su = max(sul,szty(p->in.right->in.type)+sur);

	}

int radebug = 0;

rallo( p, down ) NODE *p; {
	/* do register allocation */
	register int o, down1, down2, ty;

	if( radebug ) printf( "rallo( %o, %d )\n", p, down );

	down2 = NOPREF;
	p->in.rall = down;
	down1 = ( down &= ~MUSTDO );

	ty = optype( o = p->in.op );
	switch( o ) {
	case ASSIGN:	
		down1 = NOPREF;
		down2 = down;
		break;

	case CALL:
	case STASG:
	case EQ:
	case NE:
	case GT:
	case GE:
	case LT:
	case LE:
	case NOT:
	case ANDAND:
	case OROR:
		down1 = NOPREF;
		break;

	case FORCE:	
		down1 = R0|MUSTDO;
		break;

		}

	if( ty != LTYPE ) rallo( p->in.left, down1 );
	if( ty == BITYPE ) rallo( p->in.right, down2 );

	}

D 4
/* VARARGS1 */
E 4
offstar( p ) register NODE *p; {
	if( p->in.op == PLUS ) {
		if( p->in.left->in.su == fregs ) {
			order( p->in.left, INTAREG|INAREG );
			return;
		} else if( p->in.right->in.su == fregs ) {
			order( p->in.right, INTAREG|INAREG );
			return;
		}
		if( p->in.left->in.op==LS && 
D 4
		  (p->in.left->in.left->in.op!=REG || tlen(p->in.left->in.left)!=sizeof(int) ) ) {
E 4
I 4
		  (p->in.left->in.left->in.op!=REG || tlen(p->in.left->in.left)!=SZINT/SZCHAR ) ) {
E 4
			order( p->in.left->in.left, INTAREG|INAREG );
			return;
		}
		if( p->in.right->in.op==LS &&
D 4
		  (p->in.right->in.left->in.op!=REG || tlen(p->in.right->in.left)!=sizeof(int) ) ) {
E 4
I 4
		  (p->in.right->in.left->in.op!=REG || tlen(p->in.right->in.left)!=SZINT/SZCHAR ) ) {
E 4
			order( p->in.right->in.left, INTAREG|INAREG );
			return;
		}
		if( p->in.type == (PTR|CHAR) || p->in.type == (PTR|UCHAR) ) {
D 4
			if( p->in.left->in.op!=REG || tlen(p->in.left)!=sizeof(int) ) {
E 4
I 4
			if( p->in.left->in.op!=REG || tlen(p->in.left)!=SZINT/SZCHAR ) {
E 4
				order( p->in.left, INTAREG|INAREG );
				return;
			}
D 4
			else if( p->in.right->in.op!=REG || tlen(p->in.right)!=sizeof(int) ) {
E 4
I 4
			else if( p->in.right->in.op!=REG || tlen(p->in.right)!=SZINT/SZCHAR ) {
E 4
				order(p->in.right, INTAREG|INAREG);
				return;
			}
		}
	}
	if( p->in.op == PLUS || p->in.op == MINUS ){
		if( p->in.right->in.op == ICON ){
			p = p->in.left;
			order( p , INTAREG|INAREG);
			return;
			}
		}

	if( p->in.op == UNARY MUL && !canaddr(p) ) {
		offstar( p->in.left );
		return;
	}

	order( p, INTAREG|INAREG );
	}

D 4
/* VARARGS1 */
E 4
setincr( p ) register NODE *p; {
	p = p->in.left;
	if( p->in.op == UNARY MUL ){
D 4
		offstar( p );
E 4
I 4
		offstar( p->in.left );
E 4
		return( 1 );
		}
	return( 0 );
	}

D 4
/* VARARGS1 */
E 4
setbin( p ) register NODE *p; {
	register int ro, rt;

	rt = p->in.right->in.type;
	ro = p->in.right->in.op;

	if( canaddr( p->in.left ) && !canaddr( p->in.right ) ) { /* address rhs */
		if( ro == UNARY MUL ) {
			offstar( p->in.right->in.left );
			return(1);
		} else {
			order( p->in.right, INAREG|INTAREG|SOREG );
			return(1);
		}
	}
	if( !istnode( p->in.left) ) { /* try putting LHS into a reg */
		order( p->in.left, INAREG|INTAREG|INBREG|INTBREG|SOREG );
		return(1);
		}
	else if( ro == UNARY MUL && rt != CHAR && rt != UCHAR ){
		offstar( p->in.right->in.left );
		return(1);
		}
	else if( rt == CHAR || rt == UCHAR || rt == SHORT || rt == USHORT || (ro != REG &&
			ro != NAME && ro != OREG && ro != ICON ) ){
		order( p->in.right, INAREG|INBREG );
		return(1);
		}
	return(0);
	}

/* VARARGS1 */
setstr( p ) register NODE *p; { /* structure assignment */
	if( p->in.right->in.op != REG ){
		order( p->in.right, INTAREG );
		return(1);
		}
	p = p->in.left;
	if( p->in.op != NAME && p->in.op != OREG ){
		if( p->in.op != UNARY MUL ) cerror( "bad setstr" );
		order( p->in.left, INTAREG );
		return( 1 );
		}
	return( 0 );
	}

D 4
/* VARARGS1 */
E 4
setasg( p ) register NODE *p; {
	/* setup for assignment operator */

	if( !canaddr(p->in.right) ) {
		if( p->in.right->in.op == UNARY MUL )
			offstar(p->in.right->in.left);
		else
			order( p->in.right, INAREG|INBREG|SOREG );
		return(1);
		}
	if( p->in.left->in.op == UNARY MUL ) {
		offstar( p->in.left->in.left );
		return(1);
		}
	if( p->in.left->in.op == FLD && p->in.left->in.left->in.op == UNARY MUL ){
		offstar( p->in.left->in.left->in.left );
		return(1);
		}
/* FLD patch */
	if( p->in.left->in.op == FLD && !(p->in.right->in.type==INT || p->in.right->in.type==UNSIGNED)) {
		order( p->in.right, INAREG);
		return(1);
		}
/* end of FLD patch */
	return(0);
	}

D 4
/* VARARGS1 */
E 4
setasop( p ) register NODE *p; {
	/* setup for =ops */
	register int rt, ro;

	rt = p->in.right->in.type;
	ro = p->in.right->in.op;

	if( ro == UNARY MUL && rt != CHAR ){
		offstar( p->in.right->in.left );
		return(1);
		}
	if( ( rt == CHAR || rt == SHORT || rt == UCHAR || rt == USHORT ||
			( ro != REG && ro != ICON && ro != NAME && ro != OREG ) ) ){
		order( p->in.right, INAREG|INBREG );
		return(1);
		}


	p = p->in.left;
	if( p->in.op == FLD ) p = p->in.left;

	switch( p->in.op ){

	case REG:
	case ICON:
	case NAME:
	case OREG:
		return(0);

	case UNARY MUL:
		if( p->in.left->in.op==OREG )
			return(0);
		else
			offstar( p->in.left );
		return(1);

		}
	cerror( "illegal setasop" );
I 4
	/*NOTREACHED*/
E 4
	}

D 3
int crslab = 9999;  /* Honeywell */
E 3
I 3
int crslab = 99999;  /* Tahoe */
E 3

getlab(){
	return( crslab-- );
	}

I 3
D 7
#ifndef deflab
E 7
E 3
deflab( l ){
I 7
	if (nerrors) return;
E 7
	printf( "L%d:\n", l );
	}
I 3
D 7
#endif
E 7
E 3

genargs( p, ptemp ) register NODE *p, *ptemp; {
	register NODE *pasg;
	register int align;
	register int size;

	/* generate code for the arguments */

	/*  first, do the arguments on the right */
	while( p->in.op == CM ){
		genargs( p->in.right, ptemp );
		p->in.op = FREE;
		p = p->in.left;
		}

	if( p->in.op == STARG ){ /* structure valued argument */

		size = p->stn.stsize;
		align = p->stn.stalign;
		if( p->in.left->in.op == ICON ){
			p->in.op = FREE;
			p= p->in.left;
			}
		else {
			/* make it look beautiful... */
			p->in.op = UNARY MUL;
			canon( p );  /* turn it into an oreg */
			if( p->in.op != OREG ){
				offstar( p->in.left );
				canon( p );
				if( p->in.op != OREG ){
					offstar( p->in.left );
					canon( p );
					if( p->in.op != OREG ) cerror( "stuck starg" );
					}
				}
			}


 		ptemp->tn.lval = 0;	/* all moves to (sp) */

		pasg = talloc();
		pasg->in.op = STASG;
		pasg->stn.stsize = size;
		pasg->stn.stalign = align;
		pasg->in.right = p;
		pasg->in.left = tcopy( ptemp );

		/* the following line is done only with the knowledge
		that it will be undone by the STASG node, with the
		offset (lval) field retained */

		if( p->in.op == OREG ) p->in.op = REG;  /* only for temporaries */

 		order( pasg, FORARG );
		ptemp->tn.lval += size;
		return;
		}

	/* ordinary case */

	order( p, FORARG );
	}

argsize( p ) register NODE *p; {
	register int t;
	t = 0;
	if( p->in.op == CM ){
		t = argsize( p->in.left );
		p = p->in.right;
		}
	if( p->in.type == DOUBLE || p->in.type == FLOAT ){
		SETOFF( t, 4 );
		return( t+8 );
		}
	else if( p->in.op == STARG ){
 		SETOFF( t, 4 );  /* alignment */
 		return( t + ((p->stn.stsize+3)/4)*4 );  /* size */
		}
	else {
		SETOFF( t, 4 );
		return( t+4 );
		}
	}
E 1
