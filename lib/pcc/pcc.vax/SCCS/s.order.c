h10402
s 00001/00002/00530
d D 1.20 88/05/31 20:54:49 donn 20 19
c Bleah -- deflab() can't be a macro, too many things use the side
c effects from expressions passed as arguments.
e
s 00008/00002/00524
d D 1.19 88/05/20 01:09:44 donn 19 18
c Get more indexed addressing modes from char pointers.
e
s 00015/00009/00511
d D 1.18 88/05/11 00:42:56 donn 18 17
c Rearrange shift code in offstar() to produce more indexed operands.
e
s 00004/00004/00516
d D 1.17 87/12/11 00:49:15 donn 17 16
c utah rcsid 3.11 87/07/17 17:11:47: Change uses of 'sizeof (int)' to
c SZINT/SZCHAR to reflect target machine characteristics instead of local
c ones.
e
s 00014/00043/00506
d D 1.16 87/12/11 00:49:08 donn 16 15
c utah rcsid 3.10 87/07/12 18:33:19: Several minor changes from Sam Leffler's
c tahoe compiler.  (1) Deleted lots of old, commented-out code.  (2) Added
c missing 'int' types where (legally) omitted.  (3) Deleted special case for
c FLOAT and DOUBLE in rallo().  (4) Put '#ifndef SPRECC' around FLOAT test in
c setbin().
e
s 00000/00000/00549
d D 1.15 87/12/11 00:48:59 donn 15 14
c code for INCR from updating its lvalue operand...
e
s 00001/00001/00548
d D 1.14 87/12/11 00:48:52 donn 14 13
c utah rcsid 3.9 87/07/07 20:26:30: Fixed a goof in setincr().  If the
c operand of INCR is a UNARY MUL, the routine offstar() should be called to
c move the operand of UNARY MUL into a register, producing an OREG which
c might be matched by a template.  The old code called offstar() with the
c UNARY MUL as an argument rather than the UNARY MUL's operand, and that
c caused the operand of INCR to be put in a register, preventing the eventual
e
s 00015/00004/00534
d D 1.13 87/12/11 00:48:44 donn 13 12
c utah rcsid 3.8 87/04/24 18:53:26: Changed autoincr() -- due to changes
c upstream, an expression like 'register char *cp; unsigned char uc; uc =
c *cp++;' will result in a tree for '*cp++' which has unsigned char type but
c dereferences a char * pointer.  The test is now less stringent: the result
c of the dereference must match the base type of the pointer only in size,
c since only size is relevant to side effects like auto-increment.
e
s 00001/00002/00537
d D 1.12 87/12/11 00:48:34 donn 12 11
c utah rcsid 3.7 87/04/20 16:57:26: Simplify the su computation in the last
c rev -- constants use no registers.
e
s 00017/00012/00522
d D 1.11 87/12/11 00:48:21 donn 11 10
c utah rcsid 3.6 87/04/20 16:22:28: Moved test for unsigned DIV/MOD up higher
c in sucomp() to avoid asgop() test.
e
s 00012/00000/00522
d D 1.10 87/12/11 00:48:10 donn 10 9
c utah rcsid 3.5 87/04/19 23:39:34: Now that unsigned div/mod with constant
c divisors are done inline with the ediv instruction, we have to flag the
c register pair which ediv uses.
e
s 00003/00001/00519
d D 1.9 87/12/11 00:48:02 donn 9 8
c utah rcsid 3.4 87/01/15 01:34:22: Lint fixes.
e
s 00002/00000/00518
d D 1.8 87/12/11 00:47:53 donn 8 7
c utah rcsid 3.3 86/08/03 00:57:47: Permit deflab() to be a macro.
e
s 00003/00006/00515
d D 1.7 86/01/08 01:46:41 donn 7 6
c Make genargs more persistent when trying to convert structure arguments.
e
s 00001/00001/00520
d D 1.6 85/04/02 11:52:50 ralph 6 5
c use common header file for intermediate language defs.
e
s 00039/00035/00482
d D 1.5 85/01/18 15:23:39 ralph 5 4
c changes for single precision floats; lint cleanups
e
s 00004/00004/00513
d D 1.4 84/08/13 15:31:02 ralph 4 3
c convert float->double for float op float expressions not after op.
e
s 00005/00016/00512
d D 1.3 84/04/27 09:58:47 ralph 3 2
c fix structure arguments. don't map OREG to REG for STASG (match fails)
e
s 00001/00000/00527
d D 1.2 84/04/23 13:58:43 ralph 2 1
c initialize rall field for structures (don't core dump please)
e
s 00527/00000/00000
d D 1.1 82/12/15 13:24:01 linton 1 0
c date and time created 82/12/15 13:24:01 by linton
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
# include "mfile2"
E 6
I 6
# include "pass2.h"
E 6

int maxargs = { -1 };

D 9
stoasg( p, o ) register NODE *p; {
E 9
I 9
/*ARGSUSED*/
stoasg( p, o ) NODE *p; {
E 9
	/* should the assignment op p be stored,
	   given that it lies as the right operand of o
	   (or the left, if o==UNARY MUL) */
D 16
/*
	if( p->in.op == INCR || p->in.op == DECR ) return;
	if( o==UNARY MUL && p->in.left->in.op == REG && !isbreg(p->in.left->tn.rval) ) SETSTO(p,INAREG);
 */
E 16
	}

deltest( p ) register NODE *p; {
	/* should we delay the INCR or DECR operation p */
	p = p->in.left;
	return( p->in.op == REG || p->in.op == NAME || p->in.op == OREG );
	}

autoincr( p ) NODE *p; {
D 5
	register NODE *q = p->in.left, *r;
E 5
I 5
	register NODE *q = p->in.left;
I 13
	register TWORD t;
E 13
E 5

D 5
	if( q->in.op == INCR && (r=q->in.left)->in.op == REG &&
E 5
I 5
D 13
	if( q->in.op == INCR && q->in.left->in.op == REG &&
E 5
	    ISPTR(q->in.type) && p->in.type == DECREF(q->in.type) &&
	    tlen(p) == q->in.right->tn.lval ) return(1);
E 13
I 13
	if( q->in.op != INCR ||
	    q->in.left->in.op != REG ||
	    !ISPTR(q->in.type) )
		return(0);
	t = q->in.type;
	q->in.type = DECREF(t);
	if( tlen(p) != tlen(q) ) { /* side effects okay? */
		q->in.type = t;
		return(0);
		}
	q->in.type = t;
	if( tlen(p) != q->in.right->tn.lval )
		return(0);
E 13

D 13
	return(0);
E 13
I 13
	return(1);
E 13
	}

mkadrs(p) register NODE *p; {
D 16
	register o;
E 16
I 16
	register int o;
E 16

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

I 9
/*ARGSUSED*/
E 9
D 5
notoff( t, r, off, cp) CONSZ off; char *cp; {
E 5
I 5
notoff( t, r, off, cp) TWORD t; CONSZ off; char *cp; {
E 5
	/* is it legal to make an OREG or NAME entry which has an
	/* offset of off, (from a register of r), if the
	/* resulting thing had type t */

D 16
/*	if( r == R0 ) return( 1 );  /* NO */
E 16
	return(0);  /* YES */
	}

# define max(x,y) ((x)<(y)?(y):(x))

sucomp( p ) register NODE *p; {

	/* set the su field in the node to the sethi-ullman
	   number, or local equivalent */

D 5
	register o, ty, sul, sur, r;
E 5
I 5
	register int o, ty, sul, sur, r;
	int szr;
	NODE *temp;
E 5

	o = p->in.op;
	ty = optype( o );
D 16
	p->in.su = szty( p->in.type );   /* 2 for float or double, else 1 */;
E 16
I 16
	p->in.su = szty( p->in.type );   /* 2 for double, else 1 */;
E 16

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
D 5
		   (p->in.type==INT || p->in.type==UNSIGNED || p->in.type==DOUBLE) )
E 5
I 5
		   (p->in.type==INT ||
		    p->in.type==UNSIGNED ||
#if defined(FORT) || defined(SPRECC)
		    p->in.type==FLOAT ||
#endif
		    p->in.type==DOUBLE ||
		    ISPTR(p->in.type) ||
		    ISARY(p->in.type)) )
E 5
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
			p->in.su =  p->in.left->in.su + (szty( p->in.type ) > 1 ? 2 : 0) ;
			return;
			}
		}


	/* If rhs needs n, lhs needs m, regular su computation */

	sul = p->in.left->in.su;
	sur = p->in.right->in.su;
I 5
	szr = szty( p->in.right->in.type );
	if( szty( p->in.type ) > szr && szr >= 1 ) {
		/* implicit conversion in rhs */
		szr = szty( p->in.type );
		sur = max( szr, sur );
	}
E 5

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

I 11
	switch( o ){
		case DIV:
		case ASG DIV:
		case MOD:
		case ASG MOD:
			/* EDIV instructions require reg pairs */
			if( p->in.left->in.type == UNSIGNED &&
			    p->in.right->in.op == ICON &&
			    p->in.right->tn.name[0] == '\0' &&
			    (unsigned) p->in.right->tn.lval < 0x80000000 ) {
D 12
				sul += 2;
				p->in.su = max(sul, szr+sur);
E 12
I 12
				p->in.su = sul + 2;
E 12
				return;
				}
			break;
		}

E 11
	if( asgop(o) ){
		/* computed by doing right, doing left address, doing left, op, and store */
		p->in.su = max(sur,sul+2);
D 16
/*
		if( o==ASG MUL || o==ASG DIV || o==ASG MOD) p->in.su = max(p->in.su,fregs);
 */
E 16
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

I 5
D 16
	case MUL:
E 16
E 5
	case PLUS:
I 16
	case MUL:
E 16
	case OR:
	case ER:
		/* commutative ops; put harder on left */
		if( p->in.right->in.su > p->in.left->in.su && !istnode(p->in.left) ){
D 5
			register NODE *temp;
E 5
			temp = p->in.left;
			p->in.left = p->in.right;
			p->in.right = temp;
I 5
			sul = p->in.left->in.su;
			sur = p->in.right->in.su;
			szr = szty( p->in.right->in.type );
			if( szty( p->in.type ) > szr && szr >= 1 ) {
				/* implicit conversion in rhs */
				szr = szty( p->in.type );
				sur = max( szr, sur );
				}
E 5
			}
D 11
		break;
I 10

	case DIV:
	case ASG DIV:
	case MOD:
	case ASG MOD:
		/* EDIV instructions require reg pairs */
		if( p->in.left->in.type == UNSIGNED &&
		    p->in.right->in.op == ICON &&
		    p->in.right->tn.name[0] == '\0' &&
		    (unsigned) p->in.right->tn.lval < 0x80000000 )
			sul += 2;
E 11
		break;
E 10
		}
D 16

E 16
	/* binary op, computed by left, then right, then do op */
D 5
	p->in.su = max(sul,szty(p->in.right->in.type)+sur);
E 5
I 5
	p->in.su = max(sul,szr+sur);
E 5
D 16
/*
	if( o==MUL||o==DIV||o==MOD) p->in.su = max(p->in.su,fregs);
 */
E 16

	}

int radebug = 0;

rallo( p, down ) NODE *p; {
	/* do register allocation */
D 16
	register o, type, down1, down2, ty;
E 16
I 16
	register int o, down1, down2, ty;
E 16

	if( radebug ) printf( "rallo( %o, %d )\n", p, down );

	down2 = NOPREF;
	p->in.rall = down;
	down1 = ( down &= ~MUSTDO );

	ty = optype( o = p->in.op );
D 16
	type = p->in.type;


	if( type == DOUBLE || type == FLOAT ){
		if( o == FORCE ) down1 = R0|MUSTDO;
		}
	else switch( o ) {
E 16
I 16
	switch( o ) {
E 16
	case ASSIGN:	
		down1 = NOPREF;
		down2 = down;
		break;

D 5
/*
	case MUL:
	case DIV:
	case MOD:
		down1 = R3|MUSTDO;
		down2 = R5|MUSTDO;
		break;

	case ASG MUL:
	case ASG DIV:
	case ASG MOD:
		p->in.left->in.rall = down1 = R3|MUSTDO;
		if( p->in.left->in.op == UNARY MUL ){
			rallo( p->in.left->in.left, R4|MUSTDO );
			}
		else if( p->in.left->in.op == FLD  && p->in.left->in.left->in.op == UNARY MUL ){
			rallo( p->in.left->in.left->in.left, R4|MUSTDO );
			}
		else rallo( p->in.left, R3|MUSTDO );
		rallo( p->in.right, R5|MUSTDO );
		return;
 */

E 5
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

offstar( p ) register NODE *p; {
	if( p->in.op == PLUS ) {
I 18
		/* try to create index expressions */
		if( p->in.left->in.op==LS && 
		    p->in.left->in.left->in.op!=REG &&
		    p->in.left->in.right->in.op==ICON &&
		    p->in.left->in.right->tn.lval<=3 ){
			order( p->in.left->in.left, INTAREG|INAREG );
			return;
		}
E 18
		if( p->in.left->in.su == fregs ) {
			order( p->in.left, INTAREG|INAREG );
			return;
D 18
		} else if( p->in.right->in.su == fregs ) {
			order( p->in.right, INTAREG|INAREG );
			return;
E 18
		}
D 18
		if( p->in.left->in.op==LS && 
D 17
		  (p->in.left->in.left->in.op!=REG || tlen(p->in.left->in.left)!=sizeof(int) ) ) {
E 17
I 17
		  (p->in.left->in.left->in.op!=REG || tlen(p->in.left->in.left)!=SZINT/SZCHAR ) ) {
E 17
			order( p->in.left->in.left, INTAREG|INAREG );
E 18
I 18
		if( p->in.right->in.op==LS && 
		    p->in.right->in.left->in.op!=REG &&
		    p->in.right->in.right->in.op==ICON &&
		    p->in.right->in.right->tn.lval<=3 ){
			order( p->in.right->in.left, INTAREG|INAREG );
E 18
			return;
		}
D 18
		if( p->in.right->in.op==LS &&
D 17
		  (p->in.right->in.left->in.op!=REG || tlen(p->in.right->in.left)!=sizeof(int) ) ) {
E 17
I 17
		  (p->in.right->in.left->in.op!=REG || tlen(p->in.right->in.left)!=SZINT/SZCHAR ) ) {
E 17
			order( p->in.right->in.left, INTAREG|INAREG );
E 18
I 18
		if( p->in.right->in.su == fregs ) {
			order( p->in.right, INTAREG|INAREG );
E 18
			return;
		}
		if( p->in.type == (PTR|CHAR) || p->in.type == (PTR|UCHAR) ) {
D 17
			if( p->in.left->in.op!=REG || tlen(p->in.left)!=sizeof(int) ) {
E 17
I 17
D 19
			if( p->in.left->in.op!=REG || tlen(p->in.left)!=SZINT/SZCHAR ) {
E 19
I 19
			if( (p->in.left->in.op == ICON ||
			     p->in.left->in.op == NAME) &&
			    p->in.right->in.op != REG ) {
				order(p->in.right, INTAREG|INAREG);
				return;
			}
			if( p->in.left->in.op!=REG ) {
E 19
E 17
				order( p->in.left, INTAREG|INAREG );
				return;
			}
D 17
			else if( p->in.right->in.op!=REG || tlen(p->in.right)!=sizeof(int) ) {
E 17
I 17
D 19
			else if( p->in.right->in.op!=REG || tlen(p->in.right)!=SZINT/SZCHAR ) {
E 19
I 19
			if( p->in.right->in.op!=REG ) {
E 19
E 17
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

setincr( p ) register NODE *p; {
	p = p->in.left;
	if( p->in.op == UNARY MUL ){
D 14
		offstar( p );
E 14
I 14
		offstar( p->in.left );
E 14
		return( 1 );
		}
	return( 0 );
	}

setbin( p ) register NODE *p; {
D 16
	register ro, rt;
E 16
I 16
	register int ro, rt;
E 16

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
D 16
/*		order( p->in.left, logop(p->in.op)?(INAREG|INBREG|INTAREG|INTBREG|SOREG):(INTAREG|INTBREG|SOREG) );*/
E 16
		order( p->in.left, INAREG|INTAREG|INBREG|INTBREG|SOREG );
		return(1);
		}
	else if( ro == UNARY MUL && rt != CHAR && rt != UCHAR ){
		offstar( p->in.right->in.left );
		return(1);
		}
D 4
	else if( rt == CHAR || rt == UCHAR || rt == SHORT || rt == USHORT || (ro != REG &&
			ro != NAME && ro != OREG && ro != ICON ) ){
E 4
I 4
	else if( rt == CHAR || rt == UCHAR || rt == SHORT || rt == USHORT ||
D 16
	    rt == FLOAT || (ro != REG && ro != NAME && ro != OREG && ro != ICON ) ){
E 16
I 16
#ifndef SPRECC
	    rt == FLOAT ||
#endif
	    (ro != REG && ro != NAME && ro != OREG && ro != ICON ) ){
E 16
E 4
		order( p->in.right, INAREG|INBREG );
		return(1);
		}
D 16
/*
	else if( logop(p->in.op) && rt==USHORT ){  /* must get rhs into register */
/*
		order( p->in.right, INAREG );
		return( 1 );
		}
 */
E 16
	return(0);
	}

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

setasop( p ) register NODE *p; {
	/* setup for =ops */
D 16
	register rt, ro;
E 16
I 16
	register int rt, ro;
E 16

	rt = p->in.right->in.type;
	ro = p->in.right->in.op;

	if( ro == UNARY MUL && rt != CHAR ){
		offstar( p->in.right->in.left );
		return(1);
		}
D 4
	if( ( rt == CHAR || rt == SHORT || rt == UCHAR || rt == USHORT ||
			( ro != REG && ro != ICON && ro != NAME && ro != OREG ) ) ){
E 4
I 4
	if( rt == CHAR || rt == SHORT || rt == UCHAR || rt == USHORT ||
D 5
	    rt == FLOAT || ( ro != REG && ro != ICON && ro != NAME && ro != OREG ) ){
E 5
I 5
#ifndef SPRECC
	    rt == FLOAT ||
#endif
	    ( ro != REG && ro != ICON && ro != NAME && ro != OREG ) ){
E 5
E 4
		order( p->in.right, INAREG|INBREG );
		return(1);
		}
D 16
/*
	if( (p->in.op == ASG LS || p->in.op == ASG RS) && ro != ICON && ro != REG ){
		order( p->in.right, INAREG );
		return(1);
		}
 */
E 16


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
I 5
	/*NOTREACHED*/
E 5
	}

D 5
int crslab = 9999;  /* Honeywell */
E 5
I 5
int crslab = 99999;  /* VAX */
E 5

getlab(){
	return( crslab-- );
	}

I 8
D 20
#ifndef deflab
E 20
E 8
deflab( l ){
I 20
	if (nerrors) return;
E 20
	printf( "L%d:\n", l );
	}
I 8
D 20
#endif
E 20
E 8

D 3
genargs( p, ptemp ) register NODE *p, *ptemp; {
E 3
I 3
genargs( p ) register NODE *p; {
E 3
	register NODE *pasg;
D 16
	register align;
	register size;
E 16
I 16
	register int align;
	register int size;
E 16
I 7
	int count;
E 7
D 5
	register TWORD type;
E 5

	/* generate code for the arguments */

	/*  first, do the arguments on the right */
	while( p->in.op == CM ){
D 3
		genargs( p->in.right, ptemp );
E 3
I 3
		genargs( p->in.right );
E 3
		p->in.op = FREE;
		p = p->in.left;
		}

	if( p->in.op == STARG ){ /* structure valued argument */

		size = p->stn.stsize;
		align = p->stn.stalign;
		if( p->in.left->in.op == ICON ){
			p->in.op = FREE;
D 3
			p= p->in.left;
E 3
I 3
			p = p->in.left;
E 3
			}
		else {
			/* make it look beautiful... */
			p->in.op = UNARY MUL;
			canon( p );  /* turn it into an oreg */
D 7
			if( p->in.op != OREG ){
E 7
I 7
			for( count = 0; p->in.op != OREG && count < 10; ++count ){
E 7
				offstar( p->in.left );
				canon( p );
D 7
				if( p->in.op != OREG ){
					offstar( p->in.left );
					canon( p );
					if( p->in.op != OREG ) cerror( "stuck starg" );
					}
E 7
				}
I 7
			if( p->in.op != OREG ) cerror( "stuck starg" );
E 7
			}

D 3

 		ptemp->tn.lval = 0;	/* all moves to (sp) */

E 3
		pasg = talloc();
D 3
		pasg->in.op = STASG;
E 3
I 3
		pasg->in.op = STARG;
E 3
I 2
		pasg->in.rall = NOPREF;
E 2
		pasg->stn.stsize = size;
		pasg->stn.stalign = align;
D 3
		pasg->in.right = p;
		pasg->in.left = tcopy( ptemp );
E 3
I 3
		pasg->in.left = p;
E 3

D 3
		/* the following line is done only with the knowledge
		that it will be undone by the STASG node, with the
		offset (lval) field retained */

		if( p->in.op == OREG ) p->in.op = REG;  /* only for temporaries */

E 3
 		order( pasg, FORARG );
D 3
		ptemp->tn.lval += size;
E 3
		return;
		}

	/* ordinary case */

	order( p, FORARG );
	}

argsize( p ) register NODE *p; {
D 16
	register t;
E 16
I 16
	register int t;
E 16
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
D 5


E 5
E 1
