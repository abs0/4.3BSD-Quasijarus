h41271
s 00024/00006/00252
d D 4.7 86/01/08 00:36:03 donn 7 6
c (1) Deleted arguable 'i << 1' => 'i + i' optimization -- this enables
c 'register short *sp; register int i; sp[i]' to be done with a VAX indexing
c mode.  (2) Added an optimization that converts constant negative shifts of
c unsigned variables into positive shifts in the opposite direction.
e
s 00084/00031/00174
d D 4.6 85/08/22 19:04:49 mckusick 6 5
c update from donn@utah-cs
e
s 00001/00001/00204
d D 4.5 85/03/19 13:09:13 ralph 5 4
c use common header file for C, Fortran, Pascal.
e
s 00023/00001/00182
d D 4.4 85/02/20 09:33:30 ralph 4 3
c change unsigned %'s and /'s to &'s and >>'s.
e
s 00003/00000/00180
d D 4.3 85/01/18 16:14:20 ralph 3 2
c changes for single precision floats; lint cleanups
e
s 00001/00003/00179
d D 4.2 84/08/13 15:25:59 ralph 2 1
c don't give compiler error for & of register
e
s 00182/00000/00000
d D 4.1 84/08/13 15:24:59 ralph 1 0
c date and time created 84/08/13 15:24:59 by ralph
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
# include "mfile1"
E 5
I 5
# include "pass1.h"
E 5

# define SWAP(p,q) {sp=p; p=q; q=sp;}
# define RCON(p) (p->in.right->in.op==ICON)
# define RO(p) p->in.right->in.op
# define RV(p) p->in.right->tn.lval
# define LCON(p) (p->in.left->in.op==ICON)
# define LO(p) p->in.left->in.op
# define LV(p) p->in.left->tn.lval

I 6
	/* is p a constant without a name */
# define nncon(p)	((p)->in.op == ICON && (p)->tn.rval == NONAME)

E 6
int oflag = 0;

NODE *
fortarg( p ) NODE *p; {
	/* fortran function arguments */

	if( p->in.op == CM ){
		p->in.left = fortarg( p->in.left );
		p->in.right = fortarg( p->in.right );
		return(p);
		}

	while( ISPTR(p->in.type) ){
		p = buildtree( UNARY MUL, p, NIL );
		}
	return( optim(p) );
	}

	/* mapping relationals when the sides are reversed */
short revrel[] ={ EQ, NE, GE, GT, LE, LT, UGE, UGT, ULE, ULT };
NODE *
optim(p) register NODE *p; {
	/* local optimizations, most of which are probably machine independent */

	register o, ty;
	NODE *sp;
	int i;
	TWORD t;

	if( (t=BTYPE(p->in.type))==ENUMTY || t==MOETY ) econvert(p);
	if( oflag ) return(p);
	ty = optype( o=p->in.op);
	if( ty == LTYPE ) return(p);

	if( ty == BITYPE ) p->in.right = optim(p->in.right);
	p->in.left = optim(p->in.left);

	/* collect constants */

	switch(o){

	case SCONV:
	case PCONV:
		return( clocal(p) );

	case FORTCALL:
		p->in.right = fortarg( p->in.right );
		break;

	case UNARY AND:
D 2
		if( LO(p) != NAME ) cerror( "& error" );

		if( !andable(p->in.left) ) return(p);
E 2
I 2
		if( LO(p) != NAME || !andable(p->in.left) ) return(p);
E 2

		LO(p) = ICON;

		setuleft:
		/* paint over the type of the left hand side with the type of the top */
		p->in.left->in.type = p->in.type;
		p->in.left->fn.cdim = p->fn.cdim;
		p->in.left->fn.csiz = p->fn.csiz;
		p->in.op = FREE;
		return( p->in.left );

	case UNARY MUL:
		if( LO(p) != ICON ) break;
		LO(p) = NAME;
		goto setuleft;

	case MINUS:
		if( !nncon(p->in.right) ) break;
		RV(p) = -RV(p);
		o = p->in.op = PLUS;

	case MUL:
	case PLUS:
	case AND:
	case OR:
	case ER:
		/* commutative ops; for now, just collect constants */
		/* someday, do it right */
		if( nncon(p->in.left) || ( LCON(p) && !RCON(p) ) ) SWAP( p->in.left, p->in.right );
		/* make ops tower to the left, not the right */
		if( RO(p) == o ){
			NODE *t1, *t2, *t3;
			t1 = p->in.left;
			sp = p->in.right;
			t2 = sp->in.left;
			t3 = sp->in.right;
			/* now, put together again */
			p->in.left = sp;
			sp->in.left = t1;
			sp->in.right = t2;
			p->in.right = t3;
			}
		if(o == PLUS && LO(p) == MINUS && RCON(p) && RCON(p->in.left) &&
D 6
		  conval(p->in.right, MINUS, p->in.left->in.right)){
E 6
I 6
		   conval(p->in.right, MINUS, p->in.left->in.right)){
E 6
			zapleft:
			RO(p->in.left) = FREE;
			LO(p) = FREE;
			p->in.left = p->in.left->in.left;
		}
D 6
		if( RCON(p) && LO(p)==o && RCON(p->in.left) && conval( p->in.right, o, p->in.left->in.right ) ){
E 6
I 6
		if( RCON(p) && LO(p)==o && RCON(p->in.left) &&
		    conval( p->in.right, o, p->in.left->in.right ) ){
E 6
			goto zapleft;
			}
D 6
		else if( LCON(p) && RCON(p) && conval( p->in.left, o, p->in.right ) ){
E 6
I 6
		else if( LCON(p) && RCON(p) &&
			 conval( p->in.left, o, p->in.right ) ){
E 6
			zapright:
			RO(p) = FREE;
			p->in.left = makety( p->in.left, p->in.type, p->fn.cdim, p->fn.csiz );
			p->in.op = FREE;
			return( clocal( p->in.left ) );
			}
I 6
		/* FALL THROUGH */
E 6

D 6
		/* change muls to shifts */
E 6
I 6
	case ASG MUL:
		/* change muls to adds or shifts */
E 6

D 6
		if( o==MUL && nncon(p->in.right) && (i=ispow2(RV(p)))>=0){
			if( i == 0 ){ /* multiplication by 1 */
E 6
I 6
		if( (o == MUL || o == ASG MUL) &&
		    nncon(p->in.right) && (i=ispow2(RV(p)))>=0){
			if( i == 0 ) /* multiplication by 1 */
E 6
				goto zapright;
I 6
D 7
			if( i == 1 && optype(LO(p)) == LTYPE){
				/* multiplication by 2 */
				p->in.op = (asgop(o) ? ASG PLUS : PLUS);
				o = p->in.op;
				ncopy(p->in.right, p->in.left);
E 6
				}
E 7
I 7
			/* c2 will turn 'i << 1' into 'i + i' for us */
E 7
D 6
			o = p->in.op = LS;
			p->in.right->in.type = p->in.right->fn.csiz = INT;
			RV(p) = i;
E 6
I 6
			else {
				p->in.op = (asgop(o) ? ASG LS : LS);
				o = p->in.op;
				p->in.right->in.type = p->in.right->fn.csiz = INT;
				RV(p) = i;
				}
E 6
			}

		/* change +'s of negative consts back to - */
		if( o==PLUS && nncon(p->in.right) && RV(p)<0 ){
			RV(p) = -RV(p);
			o = p->in.op = MINUS;
			}
D 4
		break;
E 4
I 4
D 6
		/*FALLTHROUGH*/
E 6
I 6
		/* FALL THROUGH */
	case ASG AND:
	case ASG PLUS:
	case ASG MINUS:
E 6
	case RS:
	case LS:
D 6
		/* Operations with zero -- DAS 1/20/85 */
		if( (o==PLUS || o==MINUS || o==OR || o==ER || o==LS || o==RS)
		    && nncon(p->in.right) && RV(p)==0 ) goto zapright;
			break;
E 6
I 6
		/* Operations with zero */
		if( nncon(p->in.right) && RV(p) == 0 ) {
			if( o == MUL || o == ASG MUL ||
			    o == AND || o == ASG AND ) {
				if( asgop(o) )
					p->in.op = ASSIGN;
				else if( optype(LO(p)) == LTYPE ) {
					p->in.op = FREE;
					LO(p) = FREE;
					p = p->in.right;
					}
				else
					p->in.op = COMOP; /* side effects */
				}
			else if( o == PLUS || o == MINUS ||
				 o == ASG PLUS || o == ASG MINUS ||
				 o == OR || o == ER ||
				 o == LS || o == RS )
				goto zapright;
I 7
			}
		if( o != LS && o != RS )
			break;
		/* FALL THROUGH */

	case ASG RS:
	case ASG LS:
		if( !ISUNSIGNED(p->in.left->in.type) )
			break;
		if( p->in.right->in.op == ICON &&
		    p->in.right->tn.lval < 0 ) {
			/*
			 * Technically negative shifts are illegal
			 * but we can support them, at least with
			 * constants; you take potluck with variables.
			 */
			p->in.right->tn.lval = -p->in.right->tn.lval;
			switch( o ){
			case LS:	p->in.op = RS; break;
			case ASG LS:	p->in.op = ASG RS; break;
			case RS:	p->in.op = LS; break;
			case ASG RS:	p->in.op = ASG LS; break;
				}
E 7
			}
		break;
E 6
E 4

I 6
	case ASG DIV:
E 6
	case DIV:
D 6
		if( nncon( p->in.right ) && p->in.right->tn.lval == 1 ) goto zapright;
I 4
		/* Unsigned division by a power of two -- DAS 1/13/85 */
		if( nncon(p->in.right) && (i=ispow2(RV(p)))>=0 &&
		    ISUNSIGNED(p->in.type) ){
			o = p->in.op = RS;
			p->in.right->in.type = p->in.right->fn.csiz = INT;
			RV(p) = i;
E 6
I 6
		if( nncon( p->in.right ) ){
			if( RV(p) == 0 ) uerror("division by zero");
			else if( RV(p) == 1 ) goto zapright;
			/* Unsigned division by a power of two */
			else if( (i=ispow2(RV(p)))>=0 &&
				 (ISUNSIGNED(p->in.left->in.type) ||
				  ISUNSIGNED(p->in.right->in.type)) ){
				p->in.op = (asgop(o) ? ASG RS : RS);
				p->in.right->in.type = p->in.right->fn.csiz = INT;
				RV(p) = i;
				}
E 6
			}
		break;

I 6
	case ASG MOD:
E 6
	case MOD:
D 6
		/* Unsigned mod by a power of two -- DAS 1/13/85 */
		if( nncon(p->in.right) && (i=ispow2(RV(p)))>=0 &&
		    ISUNSIGNED(p->in.type) ){
			o = p->in.op = AND;
			RV(p)--;
E 6
I 6
		if( nncon(p->in.right) ){
			if( RV(p) == 0 ) uerror("modulus of zero");
			else if( RV(p) == 1 ){ /* mod by one gives zero */
				RV(p) = 0;
				if( asgop(o) )
					p->in.op = ASSIGN;
				else if( optype(LO(p)) == LTYPE ) {
					p->in.op = FREE;
					LO(p) = FREE;
					p = p->in.right;
					}
				else
					p->in.op = COMOP; /* side effects */
				}
			else if ((i=ispow2(RV(p)))>=0 &&
				 (ISUNSIGNED(p->in.left->in.type) ||
				  ISUNSIGNED(p->in.right->in.type)) ){
				/* Unsigned mod by a power of two */
				p->in.op = (asgop(o) ? ASG AND : AND);
				RV(p)--;
				}
E 6
			}
E 4
		break;

	case EQ:
	case NE:
	case LT:
	case LE:
	case GT:
	case GE:
	case ULT:
	case ULE:
	case UGT:
	case UGE:
		if( !LCON(p) ) break;

		/* exchange operands */

		sp = p->in.left;
		p->in.left = p->in.right;
		p->in.right = sp;
		p->in.op = revrel[p->in.op - EQ ];
		break;

		}

	return(p);
	}

ispow2( c ) CONSZ c; {
	register i;
	if( c <= 0 || (c&(c-1)) ) return(-1);
	for( i=0; c>1; ++i) c >>= 1;
	return(i);
D 6
	}

nncon( p ) NODE *p; {
	/* is p a constant without a name */
	return( p->in.op == ICON && p->tn.rval == NONAME );
E 6
	}
E 1
