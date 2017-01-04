h63100
s 00008/00010/00486
d D 5.2 87/04/07 15:56:37 mckusick 8 7
c port to tahoe by Nir peleg of CCI
e
s 00008/00002/00488
d D 5.1 85/06/06 11:57:59 dist 7 6
c Add copyright
e
s 00001/00001/00489
d D 1.6 83/02/15 15:33:24 linton 6 5
c fixed a bug in multi-subscript calculation
e
s 00040/00019/00450
d D 1.5 83/02/14 23:29:17 linton 5 4
c changed the way the INDEX operator is evaluated to better 
c handle multiple subscript arrays
e
s 00000/00001/00469
d D 1.4 83/02/08 17:59:08 linton 4 3
c 
e
s 00001/00000/00469
d D 1.3 82/03/08 23:45:11 linton 3 2
c fixed "a.b" so that type of "a" in generated addition is t_int
e
s 00289/00289/00180
d D 1.2 82/02/13 17:19:52 linton 2 1
c small elements are now stored in their exact size rather than 
c always as longs on the evaluation stack
e
s 00469/00000/00000
d D 1.1 82/01/18 19:21:22 linton 1 0
c date and time created 82/01/18 19:21:22 by linton
e
u
U
t
T
I 1
D 7
/* Copyright (c) 1982 Regents of the University of California */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 7

D 7
static char sccsid[] = "%Z%%M% %I% %G%";
E 7
I 7
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7

/*
 * This module contains the interface between the SYM routines and
 * the parse tree routines.  It would be nice if such a crude
 * interface were not necessary, but some parts of tree building are
 * language and hence SYM-representation dependent.  It's probably
 * better to have tree-representation dependent code here than vice versa.
 */

#include "defs.h"
#include "tree.h"
#include "sym.h"
#include "btypes.h"
#include "classes.h"
#include "sym.rep"
#include "tree/tree.rep"

typedef char *ARGLIST;

D 2
#define nextarg(arglist, type)	((type *) (arglist += sizeof(type)))[-1]
E 2
I 2
#define nextarg(arglist, type)  ((type *) (arglist += sizeof(type)))[-1]
E 2

LOCAL SYM *mkstring();
LOCAL SYM *namenode();

/*
 * Determine the type of a parse tree.  While we're at, check
 * the parse tree out.
 */

SYM *treetype(p, ap)
register NODE *p;
register ARGLIST ap;
{
D 2
	switch(p->op) {
		case O_NAME: {
			SYM *s;
E 2
I 2
    switch(p->op) {
	case O_NAME: {
	    SYM *s;
E 2

D 2
			s = nextarg(ap, SYM *);
			s = which(s);
			return namenode(p, s);
			/* NOTREACHED */
		}
E 2
I 2
	    s = nextarg(ap, SYM *);
	    s = which(s);
	    return namenode(p, s);
	    /* NOTREACHED */
	}
E 2

D 2
		case O_WHICH:
			p->nameval = nextarg(ap, SYM *);
			p->nameval = which(p->nameval);
			return NIL;
E 2
I 2
	case O_WHICH:
	    p->nameval = nextarg(ap, SYM *);
	    p->nameval = which(p->nameval);
	    return NIL;
E 2

D 2
		case O_LCON:
			return t_int;
E 2
I 2
	case O_LCON:
	    return t_int;
E 2

D 2
		case O_FCON:
			return t_real;
E 2
I 2
	case O_FCON:
	    return t_real;
E 2

D 2
		case O_SCON: {
			char *cpy;
			SYM *s;
E 2
I 2
	case O_SCON: {
	    char *cpy;
	    SYM *s;
E 2

D 2
			cpy = strdup(p->sconval);
			p->sconval = cpy;
			s = mkstring(p->sconval);
			if (s == t_char) {
				p->op = O_LCON;
				p->lconval = p->sconval[0];
			}
			return s;
		}
E 2
I 2
	    cpy = strdup(p->sconval);
	    p->sconval = cpy;
	    s = mkstring(p->sconval);
	    if (s == t_char) {
		p->op = O_LCON;
		p->lconval = p->sconval[0];
	    }
	    return s;
	}
E 2

D 2
		case O_INDIR:
			p->left = nextarg(ap, NODE *);
			chkclass(p->left, PTR);
			return rtype(p->left->nodetype)->type;
E 2
I 2
	case O_INDIR:
	    p->left = nextarg(ap, NODE *);
	    chkclass(p->left, PTR);
	    return rtype(p->left->nodetype)->type;
E 2

D 2
		case O_RVAL: {
			NODE *p1, *q;
E 2
I 2
	case O_RVAL: {
D 8
	    NODE *p1, *q;
E 8
I 8
	    NODE *p1;
E 8
E 2

D 2
			p1 = p->left;
			p->nodetype = p1->nodetype;
			if (p1->op == O_NAME) {
				if (p1->nodetype->class == FUNC) {
					p->op = O_CALL;
					p->right = NIL;
				} else if (p1->nameval->class == CONST) {
					if (p1->nameval->type == t_real->type) {
						p->op = O_FCON;
						p->fconval = p1->nameval->symvalue.fconval;
						p->nodetype = t_real;
						dispose(p1);
					} else {
						p->op = O_LCON;
						p->lconval = p1->nameval->symvalue.iconval;
						p->nodetype = p1->nameval->type;
						dispose(p1);
					}
				}
			}
			return p->nodetype;
			/* NOTREACHED */
E 2
I 2
	    p1 = p->left;
	    p->nodetype = p1->nodetype;
	    if (p1->op == O_NAME) {
		if (p1->nodetype->class == FUNC) {
		    p->op = O_CALL;
		    p->right = NIL;
		} else if (p1->nameval->class == CONST) {
		    if (p1->nameval->type == t_real->type) {
			p->op = O_FCON;
			p->fconval = p1->nameval->symvalue.fconval;
			p->nodetype = t_real;
			dispose(p1);
		    } else {
			p->op = O_LCON;
			p->lconval = p1->nameval->symvalue.iconval;
			p->nodetype = p1->nameval->type;
			dispose(p1);
		    }
E 2
		}
I 2
	    }
	    return p->nodetype;
	    /* NOTREACHED */
	}
E 2

D 2
		case O_CALL: {
			SYM *s;
E 2
I 2
	case O_CALL: {
	    SYM *s;
E 2

D 2
			p->left = nextarg(ap, NODE *);
			p->right = nextarg(ap, NODE *);
			s = p->left->nodetype;
			if (isblock(s) && isbuiltin(s)) {
				p->op = (OP) s->symvalue.token.tokval;
				tfree(p->left);
				p->left = p->right;
				p->right = NIL;
			}
			return s->type;
		}
E 2
I 2
	    p->left = nextarg(ap, NODE *);
	    p->right = nextarg(ap, NODE *);
	    s = p->left->nodetype;
	    if (isblock(s) && isbuiltin(s)) {
		p->op = (OP) s->symvalue.token.tokval;
		tfree(p->left);
		p->left = p->right;
		p->right = NIL;
	    }
	    return s->type;
	}
E 2

D 2
		case O_ITOF:
			return t_real;
E 2
I 2
	case O_ITOF:
	    return t_real;
E 2

D 2
		case O_NEG: {
			SYM *s;
E 2
I 2
	case O_NEG: {
	    SYM *s;
E 2

D 2
			p->left = nextarg(ap, NODE *);
			s = p->left->nodetype;
			if (!compatible(s, t_int)) {
				if (!compatible(s, t_real)) {
					trerror("%t is improper type", p->left);
				} else {
					p->op = O_NEGF;
				}
			}
			return s;
E 2
I 2
	    p->left = nextarg(ap, NODE *);
	    s = p->left->nodetype;
	    if (!compatible(s, t_int)) {
		if (!compatible(s, t_real)) {
		    trerror("%t is improper type", p->left);
		} else {
		    p->op = O_NEGF;
E 2
		}
I 2
	    }
	    return s;
	}
E 2

D 2
		case O_ADD:
		case O_SUB:
		case O_MUL:
		case O_LT:
		case O_LE:
		case O_GT:
		case O_GE:
		case O_EQ:
		case O_NE:
		{
			BOOLEAN t1real, t2real;
			SYM *t1, *t2;
E 2
I 2
	case O_ADD:
	case O_SUB:
	case O_MUL:
	case O_LT:
	case O_LE:
	case O_GT:
	case O_GE:
	case O_EQ:
	case O_NE:
	{
	    BOOLEAN t1real, t2real;
	    SYM *t1, *t2;
E 2

D 2
			p->left = nextarg(ap, NODE *);
			p->right = nextarg(ap, NODE *);
			t1 = rtype(p->left->nodetype);
			t2 = rtype(p->right->nodetype);
			t1real = (t1 == t_real);
			t2real = (t2 == t_real);
			if (t1real || t2real) {
				p->op++;
				if (!t1real) {
					p->left = build(O_ITOF, p->left);
				} else if (!t2real) {
					p->right = build(O_ITOF, p->right);
				}
			} else {
				if (t1real) {
					convert(&p->left, t_int, O_NOP);
				}
				if (t2real) {
					convert(&p->right, t_int, O_NOP);
				}
			}
			if (p->op >= O_LT) {
				return t_boolean;
			} else {
				if (t1real || t2real) {
					return t_real;
				} else {
					return t_int;
				}
			}
			/* NOTREACHED */
E 2
I 2
	    p->left = nextarg(ap, NODE *);
	    p->right = nextarg(ap, NODE *);
	    t1 = rtype(p->left->nodetype);
	    t2 = rtype(p->right->nodetype);
	    t1real = (t1 == t_real);
	    t2real = (t2 == t_real);
	    if (t1real || t2real) {
		p->op++;
		if (!t1real) {
		    p->left = build(O_ITOF, p->left);
		} else if (!t2real) {
		    p->right = build(O_ITOF, p->right);
E 2
		}
I 2
	    } else {
		if (t1real) {
		    convert(&p->left, t_int, O_NOP);
		}
		if (t2real) {
		    convert(&p->right, t_int, O_NOP);
		}
	    }
	    if (p->op >= O_LT) {
		return t_boolean;
	    } else {
		if (t1real || t2real) {
		    return t_real;
		} else {
		    return t_int;
		}
	    }
	    /* NOTREACHED */
	}
E 2

D 2
		case O_DIVF:
			p->left = nextarg(ap, NODE *);
			p->right = nextarg(ap, NODE *);
			convert(&p->left, t_real, O_ITOF);
			convert(&p->right, t_real, O_ITOF);
			return t_real;
E 2
I 2
	case O_DIVF:
	    p->left = nextarg(ap, NODE *);
	    p->right = nextarg(ap, NODE *);
	    convert(&p->left, t_real, O_ITOF);
	    convert(&p->right, t_real, O_ITOF);
	    return t_real;
E 2

D 2
		case O_DIV:
		case O_MOD:
			p->left = nextarg(ap, NODE *);
			p->right = nextarg(ap, NODE *);
			convert(&p->left, t_int, O_NOP);
			convert(&p->right, t_int, O_NOP);
			return t_int;
E 2
I 2
	case O_DIV:
	case O_MOD:
	    p->left = nextarg(ap, NODE *);
	    p->right = nextarg(ap, NODE *);
	    convert(&p->left, t_int, O_NOP);
	    convert(&p->right, t_int, O_NOP);
	    return t_int;
E 2

D 2
		case O_AND:
		case O_OR:
			p->left = nextarg(ap, NODE *);
			p->right = nextarg(ap, NODE *);
			chkboolean(p->left);
			chkboolean(p->right);
			return t_boolean;
E 2
I 2
	case O_AND:
	case O_OR:
	    p->left = nextarg(ap, NODE *);
	    p->right = nextarg(ap, NODE *);
	    chkboolean(p->left);
	    chkboolean(p->right);
	    return t_boolean;
E 2

D 2
		default:
			return NIL;
	}
E 2
I 2
	default:
	    return NIL;
    }
E 2
}

/*
 * Create a node for a name.  The symbol for the name has already
 * been chosen, either implicitly with "which" or explicitly from
 * the dot routine.
 */

LOCAL SYM *namenode(p, s)
NODE *p;
SYM *s;
{
D 2
	NODE *np;
E 2
I 2
    NODE *np;
E 2

D 2
	p->nameval = s;
	if (s->class == REF) {
		np = alloc(1, NODE);
		*np = *p;
		p->op = O_INDIR;
		p->left = np;
		np->nodetype = s;
	}
	if (s->class == CONST || s->class == VAR || s->class == FVAR) {
		return s->type;
	} else {
		return s;
	}
E 2
I 2
    p->nameval = s;
    if (s->class == REF) {
	np = alloc(1, NODE);
	*np = *p;
	p->op = O_INDIR;
	p->left = np;
	np->nodetype = s;
    }
    if (s->class == CONST || s->class == VAR || s->class == FVAR) {
	return s->type;
    } else {
	return s;
    }
E 2
}

/*
 * Convert a tree to a type via a conversion operator;
 * if this isn't possible generate an error.
 *
 * Note the tree is call by address, hence the #define below.
 */

LOCAL convert(tp, typeto, op)
NODE **tp;
SYM *typeto;
OP op;
{
D 2
#define tree	(*tp)
E 2
I 2
#define tree    (*tp)
E 2

D 2
	SYM *s;
E 2
I 2
    SYM *s;
E 2

D 2
	s = rtype(tree->nodetype);
	typeto = rtype(typeto);
	if (typeto == t_real && compatible(s, t_int)) {
		tree = build(op, tree);
	} else if (!compatible(s, typeto)) {
		trerror("%t is improper type");
	} else if (op != O_NOP && s != typeto) {
		tree = build(op, tree);
	}
E 2
I 2
    s = rtype(tree->nodetype);
    typeto = rtype(typeto);
    if (typeto == t_real && compatible(s, t_int)) {
	tree = build(op, tree);
    } else if (!compatible(s, typeto)) {
	trerror("%t is improper type");
    } else if (op != O_NOP && s != typeto) {
	tree = build(op, tree);
    }
E 2

#undef tree
}

/*
 * Construct a node for the Pascal dot operator.
 *
 * If the left operand is not a record, but rather a procedure
 * or function, then we interpret the "." as referencing an
 * "invisible" variable; i.e. a variable within a dynamically
 * active block but not within the static scope of the current procedure.
 */

NODE *dot(record, field)
NODE *record;
SYM *field;
{
D 2
	register NODE *p;
	register SYM *s;
E 2
I 2
    register NODE *p;
    register SYM *s;
E 2

D 2
	if (isblock(record->nodetype)) {
		s = findsym(field, record->nodetype);
		if (s == NIL) {
			error("\"%s\" is not defined in \"%s\"",
				field->symbol, record->nodetype->symbol);
		}
		p = alloc(1, NODE);
		p->op = O_NAME;
		p->nodetype = namenode(p, s);
	} else {
		s = findclass(field, FIELD);
		if (s == NIL) {
			error("\"%s\" is not a field", field->symbol);
		}
		field = s;
		chkfield(record, field);
		p = alloc(1, NODE);
		p->op = O_ADD;
		p->nodetype = field->type;
		p->left = record;
		p->right = build(O_LCON, (long) field->symvalue.offset);
E 2
I 2
    if (isblock(record->nodetype)) {
	s = findsym(field, record->nodetype);
	if (s == NIL) {
	    error("\"%s\" is not defined in \"%s\"",
		field->symbol, record->nodetype->symbol);
E 2
	}
D 2
	return p;
E 2
I 2
	p = alloc(1, NODE);
	p->op = O_NAME;
	p->nodetype = namenode(p, s);
    } else {
	s = findclass(field, FIELD);
	if (s == NIL) {
	    error("\"%s\" is not a field", field->symbol);
	}
	field = s;
	chkfield(record, field);
	p = alloc(1, NODE);
	p->op = O_ADD;
	p->nodetype = field->type;
	p->left = record;
I 3
D 4
	p->left->nodetype = t_int;
E 4
E 3
	p->right = build(O_LCON, (long) field->symvalue.offset);
    }
    return p;
E 2
}

/*
 * Return a tree corresponding to an array reference and do the
 * error checking.
 */

NODE *subscript(a, slist)
NODE *a, *slist;
{
D 2
	register SYM *t;
	register NODE *p;
	SYM *etype, *atype, *eltype;
	NODE *esub, *olda;
E 2
I 2
    register SYM *t;
    register NODE *p;
    SYM *etype, *atype, *eltype;
D 5
    NODE *esub, *olda;
E 5
I 5
    NODE *esub;
E 5
E 2

D 2
	olda = a;
	t = rtype(a->nodetype);
	if (t->class != ARRAY) {
		trerror("%t is not an array");
E 2
I 2
D 5
    olda = a;
E 5
    t = rtype(a->nodetype);
    if (t->class != ARRAY) {
D 5
	trerror("%t is not an array");
E 5
I 5
	trerror("%t is not an array", a);
E 5
    }
    eltype = t->type;
    p = slist;
    t = t->chain;
    for (; p != NIL && t != NIL; p = p->right, t = t->chain) {
	esub = p->left;
	etype = rtype(esub->nodetype);
	atype = rtype(t);
	if (!compatible(atype, etype)) {
	    trerror("subscript %t is the wrong type", esub);
E 2
	}
D 2
	eltype = t->type;
	p = slist;
	t = t->chain;
	for (; p != NIL && t != NIL; p = p->right, t = t->chain) {
		esub = p->left;
		etype = rtype(esub->nodetype);
		atype = rtype(t);
		if (!compatible(atype, etype)) {
			trerror("subscript %t is the wrong type", esub);
		}
		a = build(O_INDEX, a, esub);
		a->nodetype = eltype;
	}
	if (p != NIL) {
		trerror("too many subscripts for %t", olda);
	} else if (t != NIL) {
		trerror("not enough subscripts for %t", olda);
	}
	return(a);
E 2
I 2
D 5
	a = build(O_INDEX, a, esub);
	a->nodetype = eltype;
E 5
I 5
	esub->nodetype = atype;
E 5
    }
    if (p != NIL) {
D 5
	trerror("too many subscripts for %t", olda);
E 5
I 5
	trerror("too many subscripts for %t", a);
E 5
    } else if (t != NIL) {
D 5
	trerror("not enough subscripts for %t", olda);
E 5
I 5
	trerror("not enough subscripts for %t", a);
E 5
    }
D 5
    return(a);
E 5
I 5
    p = alloc(1, NODE);
    p->op = O_INDEX;
    p->left = a;
    p->right = slist;
    p->nodetype = eltype;
    return p;
E 5
E 2
}

/*
D 5
 * Evaluate a subscript index.
E 5
I 5
 * Evaluate a subscript (possibly more than one index).
E 5
 */

D 2
evalindex(s)
SYM *s;
E 2
I 2
D 5
evalindex(arraytype, index)
E 5
I 5
long evalindex(arraytype, subs)
E 5
SYM *arraytype;
D 5
long index;
E 5
I 5
NODE *subs;
E 5
E 2
{
D 2
	long i;
	long lb, ub;
E 2
I 2
D 5
    long lb, ub;
    SYM *indextype;
E 5
I 5
    long lb, ub, index, i;
    SYM *t, *indextype;
    NODE *p;
E 5
E 2

D 2
	s = rtype(s)->chain;
	i = pop(long);
	lb = s->symvalue.rangev.lower;
	ub = s->symvalue.rangev.upper;
	if (i < lb || i > ub) {
		error("subscript out of range");
	}
	return(i - lb);
E 2
I 2
D 5
    indextype = arraytype->chain;
    lb = indextype->symvalue.rangev.lower;
    ub = indextype->symvalue.rangev.upper;
    if (index < lb || index > ub) {
	error("subscript out of range");
E 5
I 5
    t = rtype(arraytype);
    if (t->class != ARRAY) {
	panic("unexpected class %d in evalindex", t->class);
E 5
    }
D 5
    return(index - lb);
E 5
I 5
    i = 0;
    t = t->chain;
    p = subs;
    while (t != NIL) {
	if (p == NIL) {
	    panic("unexpected end of subscript list in evalindex");
	}
	indextype = rtype(t);
	lb = indextype->symvalue.rangev.lower;
	ub = indextype->symvalue.rangev.upper;
	eval(p->left);
	index = popsmall(p->left->nodetype);
	if (index < lb || index > ub) {
	    error("subscript value %d out of range %d..%d", index, lb, ub);
	}
D 6
	i = i + (index - lb);
E 6
I 6
	i = (ub-lb+1)*i + (index-lb);
E 6
	t = t->chain;
	p = p->right;
    }
    return i;
E 5
E 2
}

/*
 * Check that a record.field usage is proper.
 */

LOCAL chkfield(r, f)
NODE *r;
SYM *f;
{
D 2
	register SYM *s;
E 2
I 2
    register SYM *s;
E 2

D 2
	chkclass(r, RECORD);
E 2
I 2
    chkclass(r, RECORD);
E 2

D 2
	/*
	 * Don't do this for compiled code.
	 */
#	if (!isvax)
		for (s = r->nodetype->chain; s != NIL; s = s->chain) {
			if (s == f) {
				break;
			}
		}
		if (s == NIL) {
			error("\"%s\" is not a field in specified record", f->symbol);
		}
#	endif
E 2
I 2
    /*
     * Don't do this for compiled code.
     */
D 8
#   if (!isvax)
	for (s = r->nodetype->chain; s != NIL; s = s->chain) {
	    if (s == f) {
		break;
	    }
E 8
I 8
    for (s = r->nodetype->chain; s != NIL; s = s->chain) {
	if (s == f) {
	    break;
E 8
	}
D 8
	if (s == NIL) {
	    error("\"%s\" is not a field in specified record", f->symbol);
	}
#   endif
E 8
I 8
    }
    if (s == NIL) {
	error("\"%s\" is not a field in specified record", f->symbol);
    }
E 8
E 2
}

/*
 * Check to see if a tree is boolean-valued, if not it's an error.
 */

chkboolean(p)
register NODE *p;
{
D 2
	if (p->nodetype != t_boolean) {
		trerror("found %t, expected boolean expression");
	}
E 2
I 2
    if (p->nodetype != t_boolean) {
	trerror("found %t, expected boolean expression");
    }
E 2
}

/*
 * Check to make sure the given tree has a type of the given class.
 */

LOCAL chkclass(p, class)
NODE *p;
int class;
{
D 2
	SYM tmpsym;
E 2
I 2
    SYM tmpsym;
E 2

D 2
	tmpsym.class = class;
	if (p->nodetype->class != class) {
		trerror("%t is not a %s", p, classname(&tmpsym));
	}
E 2
I 2
    tmpsym.class = class;
    if (p->nodetype->class != class) {
	trerror("%t is not a %s", p, classname(&tmpsym));
    }
E 2
}

/*
 * Construct a node for the type of a string.  While we're at it,
 * scan the string for '' that collapse to ', and chop off the ends.
 */

LOCAL SYM *mkstring(str)
char *str;
{
D 2
	register char *p, *q;
	SYM *s, *t;
	static SYM zerosym;
E 2
I 2
    register char *p, *q;
    SYM *s, *t;
    static SYM zerosym;
E 2

D 2
	p = str;
	q = str + 1;
	while (*q != '\0') {
		if (q[0] != '\'' || q[1] != '\'') {
			*p = *q;
			p++;
		}
		q++;
E 2
I 2
    p = str;
    q = str + 1;
    while (*q != '\0') {
	if (q[0] != '\'' || q[1] != '\'') {
	    *p = *q;
	    p++;
E 2
	}
D 2
	*--p = '\0';
	if (p == str + 1) {
		return t_char;
	}
	s = alloc(1, SYM);
	*s = zerosym;
	s->class = ARRAY;
	s->type = t_char;
	s->chain = alloc(1, SYM);
	t = s->chain;
	*t = zerosym;
	t->class = RANGE;
	t->type = t_int;
	t->symvalue.rangev.lower = 1;
	t->symvalue.rangev.upper = p - str + 1;
	return s;
E 2
I 2
	q++;
    }
    *--p = '\0';
    if (p == str + 1) {
	return t_char;
    }
    s = alloc(1, SYM);
    *s = zerosym;
    s->class = ARRAY;
    s->type = t_char;
    s->chain = alloc(1, SYM);
    t = s->chain;
    *t = zerosym;
    t->class = RANGE;
    t->type = t_int;
    t->symvalue.rangev.lower = 1;
    t->symvalue.rangev.upper = p - str + 1;
    return s;
E 2
}

/*
 * Free up the space allocated for a string type.
 */

unmkstring(s)
SYM *s;
{
D 2
	dispose(s->chain);
E 2
I 2
    dispose(s->chain);
E 2
}
E 1
