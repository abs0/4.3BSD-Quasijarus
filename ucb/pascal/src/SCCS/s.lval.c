h33139
s 00002/00000/00553
d D 5.2 85/07/26 16:14:34 mckusick 18 17
c null pointer checks (from ralph)
e
s 00007/00003/00546
d D 5.1 85/06/05 14:23:01 dist 17 16
c Add copyright
e
s 00011/00011/00538
d D 2.2 85/03/20 15:02:16 ralph 16 15
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00549
d D 2.1 84/02/08 20:46:47 aoki 15 14
c synchronize to version 2
e
s 00002/00001/00547
d D 1.13 84/02/08 20:09:55 aoki 14 13
c lint and suppression of spurious error messages after 
c incorrect number of array subscripts.
e
s 00119/00021/00429
d D 1.12 84/02/08 00:43:52 mckusick 13 12
c merge in conformant array code by Carol Nishizak
e
s 00000/00000/00450
d D 1.11 84/02/04 19:12:02 mckusick 12 10
i 11
c merge lint by thien
e
s 00114/00092/00336
d D 1.9.1.1 84/02/04 19:08:48 mckusick 11 9
c lint (by thien)
e
s 00001/00001/00427
d D 1.10 83/10/24 18:15:16 mckusick 10 9
c fix range error in calculating constant subscripts
e
s 00002/00001/00426
d D 1.9 83/01/17 13:56:52 mckusick 9 8
c put in explicit scalar converts (sconv's) to make less code-generator dependent.
e
s 00042/00009/00385
d D 1.8 81/06/15 19:59:50 mckusic 8 7
c perform constant subscript calculations at compile time
e
s 00001/00001/00393
d D 1.7 81/04/21 15:04:54 peter 7 6
c clean up for loop code
e
s 00001/00001/00393
d D 1.6 81/03/26 17:30:47 peter 6 5
c fix to match new for variable flags.
e
s 00013/00013/00381
d D 1.5 81/03/08 19:26:04 mckusic 5 4
c merge in onyx changes
e
s 00005/00000/00389
d D 1.4 81/01/13 12:27:45 mckusic 4 3
c ifdef OBJ body of lvalue
e
s 00003/00002/00386
d D 1.3 81/01/10 17:00:31 mckusic 3 2
c convert to "fp", "ap" type display; fix SUCC and PRED
e
s 00039/00003/00349
d D 1.2 81/01/06 17:15:59 mckusic 2 1
c modify to allow use of px written in `C' and the use of libpc
e
s 00352/00000/00000
d D 1.1 80/08/27 19:55:18 peter 1 0
c date and time created 80/08/27 19:55:18 by peter
e
u
U
f b 
t
T
I 1
D 17
/* Copyright (c) 1979 Regents of the University of California */
E 17
I 17
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 17

I 11
#ifndef lint
E 11
D 5
static	char sccsid[] = "%Z%%M% %I% %G%";
E 5
I 5
D 17
static char sccsid[] = "%Z%%M% %I% %G%";
I 11
#endif
E 17
I 17
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 17
E 11
E 5

#include "whoami.h"
#include "0.h"
#include "tree.h"
#include "opcode.h"
#include "objfmt.h"
I 11
#include "tree_ty.h"
E 11
#ifdef PC
#   include	"pc.h"
D 16
#   include	"pcops.h"
E 16
I 16
#   include	<pcc.h>
E 16
#endif PC

extern	int flagwas;
/*
 * Lvalue computes the address
 * of a qualified name and
 * leaves it on the stack.
 * for pc, it can be asked for either an lvalue or an rvalue.
 * the semantics are the same, only the code is different.
 */
I 11
/*ARGSUSED*/
E 11
struct nl *
D 11
lvalue(r, modflag , required )
	int *r, modflag;
E 11
I 11
lvalue(var, modflag , required )
	struct tnode *var; 
	int	modflag;
E 11
	int	required;
{
I 11
#ifdef OBJ
E 11
	register struct nl *p;
	struct nl *firstp, *lastp;
D 11
	register *c, *co;
E 11
I 11
	register struct tnode *c, *co;
E 11
D 13
	int f, o;
E 13
I 13
	int f, o, s;
E 13
	/*
	 * Note that the local optimizations
	 * done here for offsets would more
	 * appropriately be done in put.
	 */
D 11
	int tr[2], trp[3];
E 11
I 11
	struct tnode	tr;	/* T_FIELD */ 
	struct tnode	*tr_ptr;
	struct tnode	l_node;
#endif
E 11

D 11
	if (r == NIL) {
		return (NIL);
E 11
I 11
	if (var == TR_NIL) {
		return (NLNIL);
E 11
	}
D 11
	if (nowexp(r)) {
		return (NIL);
E 11
I 11
	if (nowexp(var)) {
		return (NLNIL);
E 11
	}
D 11
	if (r[0] != T_VAR) {
E 11
I 11
	if (var->tag != T_VAR) {
E 11
		error("Variable required");	/* Pass mesgs down from pt of call ? */
D 11
		return (NIL);
E 11
I 11
		return (NLNIL);
E 11
	}
#	ifdef PC
		/*
		 *	pc requires a whole different control flow
		 */
D 11
	    return pclvalue( r , modflag , required );
E 11
I 11
	    return pclvalue( var , modflag , required );
E 11
#	endif PC
I 4
#	ifdef OBJ
		/*
		 *	pi uses the rest of the function
		 */
E 4
D 11
	firstp = p = lookup(r[2]);
	if (p == NIL) {
		return (NIL);
E 11
I 11
	firstp = p = lookup(var->var_node.cptr);
	if (p == NLNIL) {
		return (NLNIL);
E 11
	}
D 11
	c = r[3];
E 11
I 11
	c = var->var_node.qual;
E 11
	if ((modflag & NOUSE) && !lptr(c)) {
		p->nl_flags = flagwas;
	}
	if (modflag & MOD) {
		p->nl_flags |= NMOD;
	}
	/*
	 * Only possibilities for p->class here
	 * are the named classes, i.e. CONST, TYPE
	 * VAR, PROC, FUNC, REF, or a WITHPTR.
	 */
I 11
	tr_ptr = &l_node;
E 11
	switch (p->class) {
		case WITHPTR:
			/*
			 * Construct the tree implied by
			 * the with statement
			 */
D 11
			trp[0] = T_LISTPP;
			trp[1] = tr;
			trp[2] = r[3];
			tr[0] = T_FIELD;
			tr[1] = r[2];
			c = trp;
E 11
I 11
			l_node.tag = T_LISTPP;

			/* the cast has got to go but until the node is figured
			   out it stays */

			tr_ptr->list_node.list = (&tr);
			tr_ptr->list_node.next = var->var_node.qual;
			tr.tag = T_FIELD;
			tr.field_node.id_ptr = var->var_node.cptr;
			c = tr_ptr; /* c is a ptr to a tnode */
E 11
#			ifdef PTREE
			    /*
D 11
			     * mung r[4] to say which field this T_VAR is
E 11
I 11
			     * mung var->fields to say which field this T_VAR is
E 11
			     * for VarCopy
			     */
D 11
			    r[4] = reclook( p -> type , r[2] );
E 11
I 11

			    /* problem! reclook returns struct nl* */

			    var->var_node.fields = reclook( p -> type , 
					    var->var_node.line_no );
E 11
#			endif
			/* and fall through */
		case REF:
			/*
			 * Obtain the indirect word
			 * of the WITHPTR or REF
			 * as the base of our lvalue
			 */
D 5
			put(2, PTR_RV | bn << 8+INDX , p->value[0] );
E 5
I 5
D 11
			put(2, PTR_RV | bn << 8+INDX , (int)p->value[0] );
E 11
I 11
			(void) put(2, PTR_RV | bn << 8+INDX , (int)p->value[0] );
E 11
E 5
			f = 0;		/* have an lv on stack */
			o = 0;
			break;
		case VAR:
D 13
			f = 1;		/* no lv on stack yet */
			o = p->value[0];
E 13
I 13
			if (p->type->class != CRANGE) {
			    f = 1;		/* no lv on stack yet */
			    o = p->value[0];
			} else {
			    error("Conformant array bound %s found where variable required", p->symbol);
			    return(NLNIL);
			}
E 13
			break;
		default:
			error("%s %s found where variable required", classes[p->class], p->symbol);
D 11
			return (NIL);
E 11
I 11
			return (NLNIL);
E 11
	}
	/*
	 * Loop and handle each
	 * qualification on the name
	 */
D 6
	if (c == NIL && (modflag&ASGN) && p->value[NL_FORV]) {
E 6
I 6
D 7
	if (c == NIL && (modflag&ASGN) && ( p->value[NL_FORV] & FORBOUND ) ) {
E 7
I 7
D 11
	if (c == NIL && (modflag&ASGN) && ( p->value[NL_FORV] & FORVAR ) ) {
E 11
I 11
	if (c == TR_NIL && (modflag&ASGN) && ( p->value[NL_FORV] & FORVAR ) ) {
E 11
E 7
E 6
		error("Can't modify the for variable %s in the range of the loop", p->symbol);
D 11
		return (NIL);
E 11
I 11
		return (NLNIL);
E 11
	}
I 13
	s = 0;		/* subscripts seen */
E 13
D 11
	for (; c != NIL; c = c[2]) {
		co = c[1];
		if (co == NIL) {
			return (NIL);
E 11
I 11
	for (; c != TR_NIL; c = c->list_node.next) {
		co = c->list_node.list; /* co is a ptr to a tnode */
		if (co == TR_NIL) {
			return (NLNIL);
E 11
		}
		lastp = p;
		p = p->type;
D 11
		if (p == NIL) {
			return (NIL);
E 11
I 11
		if (p == NLNIL) {
			return (NLNIL);
E 11
		}
I 13
		/*
		 * If we haven't seen enough subscripts, and the next
		 * qualification isn't array reference, then it's an error.
		 */
		if (s && co->tag != T_ARY) {
			error("Too few subscripts (%d given, %d required)",
				s, p->value[0]);
		}
E 13
D 11
		switch (co[0]) {
E 11
I 11
		switch (co->tag) {
E 11
			case T_PTR:
				/*
				 * Pointer qualification.
				 */
				lastp->nl_flags |= NUSED;
				if (p->class != PTR && p->class != FILET) {
					error("^ allowed only on files and pointers, not on %ss", nameof(p));
					goto bad;
				}
				if (f) {
D 2
				    put(2, PTR_RV | bn <<8+INDX , o );
E 2
I 2
				    if (p->class == FILET && bn != 0)
D 11
				        put(2, O_LV | bn <<8+INDX , o );
E 11
I 11
				        (void) put(2, O_LV | bn <<8+INDX , o );
E 11
				    else
					/*
					 * this is the indirection from
					 * the address of the pointer 
					 * to the pointer itself.
					 * kirk sez:
					 * fnil doesn't want this.
					 * and does it itself for files
					 * since only it knows where the
					 * actual window is.
					 * but i have to do this for
					 * regular pointers.
					 * This is further complicated by
					 * the fact that global variables
					 * are referenced through pointers
					 * on the stack. Thus an RV on a
					 * global variable is the same as
					 * an LV of a non-global one ?!?
					 */
D 11
				        put(2, PTR_RV | bn <<8+INDX , o );
E 11
I 11
				        (void) put(2, PTR_RV | bn <<8+INDX , o );
E 11
E 2
				} else {
					if (o) {
D 5
					    put2(O_OFF, o);
E 5
I 5
D 11
					    put(2, O_OFF, o);
E 11
I 11
					    (void) put(2, O_OFF, o);
E 11
E 5
					}
D 3
					put(1, PTR_IND);
E 3
I 3
				        if (p->class != FILET || bn == 0)
D 11
					    put(1, PTR_IND);
E 11
I 11
					    (void) put(1, PTR_IND);
E 11
E 3
				}
				/*
				 * Pointer cannot be
				 * nil and file cannot
				 * be at end-of-file.
				 */
D 5
				put1(p->class == FILET ? O_FNIL : O_NIL);
E 5
I 5
D 11
				put(1, p->class == FILET ? O_FNIL : O_NIL);
E 11
I 11
				(void) put(1, p->class == FILET ? O_FNIL : O_NIL);
E 11
E 5
				f = o = 0;
				continue;
			case T_ARGL:
				if (p->class != ARRAY) {
					if (lastp == firstp) {
D 11
						error("%s is a %s, not a function", r[2], classes[firstp->class]);
E 11
I 11
						error("%s is a %s, not a function", var->var_node.cptr, classes[firstp->class]);
E 11
					} else {
						error("Illegal function qualificiation");
					}
D 11
					return (NIL);
E 11
I 11
					return (NLNIL);
E 11
				}
				recovered();
				error("Pascal uses [] for subscripting, not ()");
			case T_ARY:
				if (p->class != ARRAY) {
					error("Subscripting allowed only on arrays, not on %ss", nameof(p));
					goto bad;
				}
				if (f) {
D 2
					put2(O_LV | bn<<8+INDX, o);
E 2
I 2
					if (bn == 0)
						/*
						 * global variables are
						 * referenced through pointers
						 * on the stack
						 */
D 5
						put2(PTR_RV | bn<<8+INDX, o);
E 5
I 5
D 11
						put(2, PTR_RV | bn<<8+INDX, o);
E 11
I 11
						(void) put(2, PTR_RV | bn<<8+INDX, o);
E 11
E 5
					else
D 5
						put2(O_LV | bn<<8+INDX, o);
E 5
I 5
D 11
						put(2, O_LV | bn<<8+INDX, o);
E 11
I 11
						(void) put(2, O_LV | bn<<8+INDX, o);
E 11
E 5
E 2
				} else {
					if (o) {
D 5
					    put2(O_OFF, o);
E 5
I 5
D 11
					    put(2, O_OFF, o);
E 11
I 11
					    (void) put(2, O_OFF, o);
E 11
E 5
					}
				}
D 11
				switch (arycod(p, co[1])) {
E 11
I 11
D 13
				switch (arycod(p, co->ary_node.expr_list)) {
E 13
I 13
				switch(s = arycod(p,co->ary_node.expr_list,s)) {
					/*
					 * This is the number of subscripts seen
					 */
E 13
E 11
					case 0:
D 11
						return (NIL);
E 11
I 11
						return (NLNIL);
E 11
					case -1:
						goto bad;
				}
I 13
				if (s == p->value[0]) {
					s = 0;
				} else {
					p = lastp;
				}
E 13
				f = o = 0;
				continue;
			case T_FIELD:
				/*
				 * Field names are just
				 * an offset with some 
				 * semantic checking.
				 */
				if (p->class != RECORD) {
					error(". allowed only on records, not on %ss", nameof(p));
					goto bad;
				}
D 11
				if (co[1] == NIL) {
					return (NIL);
E 11
I 11
				/* must define the field node!! */
				if (co->field_node.id_ptr == NIL) {
					return (NLNIL);
E 11
				}
D 11
				p = reclook(p, co[1]);
				if (p == NIL) {
					error("%s is not a field in this record", co[1]);
E 11
I 11
				p = reclook(p, co->field_node.id_ptr);
				if (p == NLNIL) {
					error("%s is not a field in this record", co->field_node.id_ptr);
E 11
					goto bad;
				}
#				ifdef PTREE
				    /*
				     * mung co[3] to indicate which field
				     * this is for SelCopy
				     */
D 11
				    co[3] = p;
E 11
I 11
				    co->field_node.nl_entry = p;
E 11
#				endif
				if (modflag & MOD) {
					p->nl_flags |= NMOD;
				}
D 11
				if ((modflag & NOUSE) == 0 || lptr(c[2])) {
E 11
I 11
				if ((modflag & NOUSE) == 0 ||
				    lptr(c->list_node.next)) {
				/* figure out what kind of node c is !! */
E 11
					p->nl_flags |= NUSED;
				}
				o += p->value[0];
				continue;
			default:
				panic("lval2");
		}
	}
I 13
	if (s) {
		error("Too few subscripts (%d given, %d required)",
			s, p->type->value[0]);
I 14
		return NLNIL;
E 14
	}
E 13
	if (f) {
D 2
		put2(O_LV | bn<<8+INDX, o);
E 2
I 2
		if (bn == 0)
			/*
			 * global variables are referenced through
			 * pointers on the stack
			 */
D 5
			put2(PTR_RV | bn<<8+INDX, o);
E 5
I 5
D 11
			put(2, PTR_RV | bn<<8+INDX, o);
E 11
I 11
			(void) put(2, PTR_RV | bn<<8+INDX, o);
E 11
E 5
		else
D 5
			put2(O_LV | bn<<8+INDX, o);
E 5
I 5
D 11
			put(2, O_LV | bn<<8+INDX, o);
E 11
I 11
			(void) put(2, O_LV | bn<<8+INDX, o);
E 11
E 5
E 2
	} else {
		if (o) {
D 5
		    put2(O_OFF, o);
E 5
I 5
D 11
		    put(2, O_OFF, o);
E 11
I 11
		    (void) put(2, O_OFF, o);
E 11
E 5
		}
	}
	return (p->type);
bad:
D 11
	cerror("Error occurred on qualification of %s", r[2]);
	return (NIL);
E 11
I 11
	cerror("Error occurred on qualification of %s", var->var_node.cptr);
	return (NLNIL);
E 11
I 4
#	endif OBJ
E 4
}

D 11
lptr(c)
	register int *c;
E 11
I 11
int lptr(c)
	register struct tnode *c;
E 11
{
D 11
	register int *co;
E 11
I 11
	register struct tnode *co;
E 11

D 11
	for (; c != NIL; c = c[2]) {
		co = c[1];
		if (co == NIL) {
E 11
I 11
	for (; c != TR_NIL; c = c->list_node.next) {
		co = c->list_node.list;
		if (co == TR_NIL) {
E 11
			return (NIL);
		}
D 11
		switch (co[0]) {
E 11
I 11
		switch (co->tag) {
E 11

		case T_PTR:
			return (1);
		case T_ARGL:
			return (0);
		case T_ARY:
		case T_FIELD:
			continue;
		default:
			panic("lptr");
		}
	}
	return (0);
}

/*
 * Arycod does the
 * code generation
 * for subscripting.
I 13
 * n is the number of
 * subscripts already seen
 * (CLN 09/13/83)
E 13
 */
D 11
arycod(np, el)
E 11
I 11
D 13
int arycod(np, el)
E 13
I 13
int arycod(np, el, n)
E 13
E 11
	struct nl *np;
D 11
	int *el;
E 11
I 11
	struct tnode *el;
I 13
	int n;
E 13
E 11
{
	register struct nl *p, *ap;
I 8
	long sub;
	bool constsub;
E 8
D 11
	int i, d, v, v1;
E 11
I 11
	extern bool constval();
	int i, d;  /* v, v1;  these aren't used */
E 11
	int w;

	p = np;
D 11
	if (el == NIL) {
E 11
I 11
	if (el == TR_NIL) {
E 11
		return (0);
	}
	d = p->value[0];
I 13
	for (i = 1; i <= n; i++) {
		p = p->chain;
	}
E 13
	/*
	 * Check each subscript
	 */
D 13
	for (i = 1; i <= d; i++) {
E 13
I 13
	for (i = n+1; i <= d; i++) {
E 13
D 11
		if (el == NIL) {
			error("Too few subscripts (%d given, %d required)", i-1, d);
E 11
I 11
		if (el == TR_NIL) {
D 13
			error("Too few subscripts (%d given, %d required)", (char *) i-1, (char *) d);
E 11
			return (-1);
E 13
I 13
			return (i-1);
E 13
		}
		p = p->chain;
I 18
		if (p == NLNIL)
			return (0);
E 18
D 8
#		ifdef PC
		    precheck( p , "_SUBSC" , "_SUBSCZ" );
#		endif PC
		ap = rvalue(el[1], NLNIL , RREQ );
		if (ap == NIL) {
			return (0);
E 8
I 8
D 11
		if (constsub = constval(el[1])) {
E 11
I 11
D 13
		if (constsub = constval(el->list_node.list)) {
E 13
I 13
		if ((p->class != CRANGE) &&
			(constsub = constval(el->list_node.list))) {
E 13
E 11
		    ap = con.ctype;
		    sub = con.crval;
		    if (sub < p->range[0] || sub > p->range[1]) {
D 11
			error("Subscript value of %D is out of range", sub);
E 11
I 11
			error("Subscript value of %D is out of range", (char *) sub);
E 11
			return (0);
		    }
		    sub -= p->range[0];
		} else {
#		    ifdef PC
			precheck( p , "_SUBSC" , "_SUBSCZ" );
#		    endif PC
D 11
		    ap = rvalue(el[1], NLNIL , RREQ );
E 11
I 11
		    ap = rvalue(el->list_node.list, NLNIL , RREQ );
E 11
		    if (ap == NIL) {
			    return (0);
		    }
#		    ifdef PC
D 9
			postcheck( p );
E 9
I 9
			postcheck(p, ap);
D 16
			sconv(p2type(ap),P2INT);
E 16
I 16
			sconv(p2type(ap),PCCT_INT);
E 16
E 9
#		    endif PC
E 8
		}
D 8
#		ifdef PC
		    postcheck( p );
#		endif PC
E 8
D 11
		if (incompat(ap, p->type, el[1])) {
E 11
I 11
		if (incompat(ap, p->type, el->list_node.list)) {
E 11
			cerror("Array index type incompatible with declared index type");
			if (d != 1) {
D 11
				cerror("Error occurred on index number %d", i);
E 11
I 11
				cerror("Error occurred on index number %d", (char *) i);
E 11
			}
			return (-1);
		}
D 13
		w = aryconst(np, i);
E 13
I 13
		if (p->class == CRANGE) {
D 14
			constsub = 0;
E 14
I 14
			constsub = FALSE;
E 14
		} else {
			w = aryconst(np, i);
		}
E 13
#		ifdef OBJ
I 8
		    if (constsub) {
			sub *= w;
			if (sub != 0) {
D 10
			    w = width(ap);
E 10
I 10
			    w = bytes(sub, sub);
E 10
D 11
			    put(2, w <= 2 ? O_CON2 : O_CON4, sub);
			    gen(NIL, T_ADD, sizeof(char *), w);
E 11
I 11
			    (void) put(2, w <= 2 ? O_CON2 : O_CON4, sub);
			    (void) gen(NIL, T_ADD, sizeof(char *), w);
E 11
			}
D 11
			el = el[2];
E 11
I 11
			el = el->list_node.next;
E 11
			continue;
		    }
E 8
D 13
		    if (opt('t') == 0) {
E 13
I 13
		    if (p->class == CRANGE) {
			putcbnds(p, 0);
			putcbnds(p, 1);
			putcbnds(p, 2);
		    } else if (opt('t') == 0) {
E 13
			    switch (w) {
			    case 8:
				    w = 6;
			    case 4:
			    case 2:
			    case 1:
D 5
				    put2((width(ap) != 4 ? O_INX2P2 : O_INX4P2) | (w & ~1) << 7, ( short ) p->range[0]);
E 5
I 5
D 11
				    put(2, (width(ap) != 4 ? O_INX2P2 : O_INX4P2) | (w & ~1) << 7, ( short ) p->range[0]);
E 5
				    el = el[2];
E 11
I 11
				    (void) put(2, (width(ap) != 4 ? O_INX2P2 : O_INX4P2) | (w & ~1) << 7, ( short ) p->range[0]);
				    el = el->list_node.next;
E 11
				    continue;
			    }
		    }
D 5
		    put(4, width(ap) != 4 ? O_INX2 : O_INX4,w,( short ) p->range[0],
D 3
			   ( short ) ( p->range[1] - p->range[0] ) );
E 3
I 3
			   ( short ) ( p->range[1] ) );
E 5
I 5
D 11
		    put(4, width(ap) != 4 ? O_INX2 : O_INX4, w,
E 11
I 11
D 13
		    (void) put(4, width(ap) != 4 ? O_INX2 : O_INX4, w,
E 11
			(short)p->range[0], (short)(p->range[1]));
E 13
I 13
		    if (p->class == CRANGE) {
			if (width(p) == 4) {
			    put(1, width(ap) != 4 ? O_VINX42 : O_VINX4);
			} else {
			    put(1, width(ap) != 4 ? O_VINX2 : O_VINX24);
			}
		    } else {
			put(4, width(ap) != 4 ? O_INX2 : O_INX4, w,
			    (short)p->range[0], (short)(p->range[1]));
		    }
E 13
I 8
D 11
		    el = el[2];
E 11
I 11
		    el = el->list_node.next;
E 11
		    continue;
E 8
E 5
E 3
#		endif OBJ
#		ifdef PC
			/*
			 *	subtract off the lower bound
			 */
I 8
		    if (constsub) {
			sub *= w;
			if (sub != 0) {
D 11
			    putleaf( P2ICON , sub , 0 , P2INT , 0 );
E 11
I 11
D 16
			    putleaf( P2ICON , (int) sub , 0 , P2INT , (char *) 0 );
E 11
			    putop(P2PLUS, ADDTYPE(p2type(np->type), P2PTR));
E 16
I 16
			    putleaf( PCC_ICON , (int) sub , 0 , PCCT_INT , (char *) 0 );
			    putop(PCC_PLUS, PCCM_ADDTYPE(p2type(np->type), PCCTM_PTR));
E 16
			}
D 11
			el = el[2];
E 11
I 11
			el = el->list_node.next;
E 11
			continue;
		    }
E 8
D 13
		    if ( p -> range[ 0 ] != 0 ) {
D 11
			putleaf( P2ICON , p -> range[0] , 0 , P2INT , 0 );
E 11
I 11
			putleaf( P2ICON , (int) p -> range[0] , 0 , P2INT , (char *) 0 );
E 11
			putop( P2MINUS , P2INT );
		    }
E 13
I 13
		    if (p->class == CRANGE) {
E 13
			/*
D 13
			 *	multiply by the width of the elements
E 13
I 13
			 *	if conformant array, subtract off lower bound
E 13
			 */
D 13
		    if ( w != 1 ) {
D 11
			putleaf( P2ICON , w , 0 , P2INT , 0 );
E 11
I 11
			putleaf( P2ICON , w , 0 , P2INT , (char *) 0 );
E 13
I 13
			ap = p->nptr[0];
			putRV(ap->symbol, (ap->nl_block & 037), ap->value[0], 
				ap->extra_flags, p2type( ap ) );
D 16
			putop( P2MINUS, P2INT );
E 16
I 16
			putop( PCC_MINUS, PCCT_INT );
E 16
			/*
			 *	and multiply by the width of the elements
			 */
			ap = p->nptr[2];
			putRV( 0 , (ap->nl_block & 037), ap->value[0], 
				ap->extra_flags, p2type( ap ) );
E 13
E 11
D 16
			putop( P2MUL , P2INT );
E 16
I 16
			putop( PCC_MUL , PCCT_INT );
E 16
I 13
		    } else {
			if ( p -> range[ 0 ] != 0 ) {
D 16
			    putleaf( P2ICON , (int) p -> range[0] , 0 , P2INT , (char *) 0 );
			    putop( P2MINUS , P2INT );
E 16
I 16
			    putleaf( PCC_ICON , (int) p -> range[0] , 0 , PCCT_INT , (char *) 0 );
			    putop( PCC_MINUS , PCCT_INT );
E 16
			}
			    /*
			     *	multiply by the width of the elements
			     */
			if ( w != 1 ) {
D 16
			    putleaf( P2ICON , w , 0 , P2INT , (char *) 0 );
			    putop( P2MUL , P2INT );
E 16
I 16
			    putleaf( PCC_ICON , w , 0 , PCCT_INT , (char *) 0 );
			    putop( PCC_MUL , PCCT_INT );
E 16
			}
E 13
		    }
			/*
			 *	and add it to the base address
			 */
D 16
		    putop( P2PLUS , ADDTYPE( p2type( np -> type ) , P2PTR ) );
E 16
I 16
		    putop( PCC_PLUS , PCCM_ADDTYPE( p2type( np -> type ) , PCCTM_PTR ) );
E 16
I 11
		el = el->list_node.next;
E 11
#		endif PC
D 11
		el = el[2];
E 11
	}
D 11
	if (el != NIL) {
E 11
I 11
	if (el != TR_NIL) {
I 13
	    if (np->type->class != ARRAY) {
E 13
E 11
		do {
D 11
			el = el[2];
E 11
I 11
			el = el->list_node.next;
E 11
			i++;
D 11
		} while (el != NIL);
		error("Too many subscripts (%d given, %d required)", i-1, d);
E 11
I 11
		} while (el != TR_NIL);
		error("Too many subscripts (%d given, %d required)", (char *) (i-1), (char *) d);
E 11
		return (-1);
I 13
	    } else {
		return(arycod(np->type, el, d));
	    }
E 13
	}
D 13
	return (1);
E 13
I 13
	return (d);
E 13
}
I 13

#ifdef OBJ
/*
 * Put out the conformant array bounds (lower bound, upper bound or width)
 * for conformant array type ctype.
 * The value of i determines which is being put
 * i = 0: lower bound, i=1: upper bound, i=2: width
 */
putcbnds(ctype, i)
struct nl *ctype;
int i;
{
	switch(width(ctype->type)) {
	    case 1:
		put(2, O_RV1 | (ctype->nl_block & 037) << 8+INDX,
			(int)ctype->nptr[i]->value[0]);
		break;
	    case 2:
		put(2, O_RV2 | (ctype->nl_block & 037) << 8+INDX,
			(int)ctype->nptr[i]->value[0]);
		break;
	    case 4:
	    default:
		put(2, O_RV4 | (ctype->nl_block & 037) << 8+INDX,
			(int)ctype->nptr[i]->value[0]);
	}
}
#endif OBJ
E 13
E 1
