h39158
s 00034/00013/01729
d D 4.36 88/05/11 01:11:55 donn 36 35
c (1) Make the NOT operator work with floating constants.  (2) Fix shifts so
c that the type depends solely on the left operand, and so that the right
c operand has type INT.  (3) Eliminate warnings for pointer conversions to
c and from void *.
e
s 00002/00002/01740
d D 4.35 88/04/24 15:49:57 bostic 35 34
c fix for ANSI C  
e
s 00005/00001/01737
d D 4.34 87/12/10 00:53:00 donn 34 33
c utah rcsid 1.30 87/07/06 13:19:17: Preserve LONG and ULONG through constant
c expression folding.
e
s 00002/00002/01736
d D 4.33 87/12/10 00:52:49 donn 33 32
c utah rcsid 1.29 87/04/24 18:51:39: Changed tymatch() to force propagation
c of unsigned type from one operand to another in an expression where only
c one operand is unsigned.  This cuts down on the number of combinations of
c types which need to be handled in the code table in the second pass, at a
c cost of some flexibility.
e
s 00007/00009/01731
d D 4.32 87/12/10 00:52:38 donn 32 31
c utah rcsid 1.28 87/04/17 21:32:38: Simplify handling of integer promotions
c in conval().
e
s 00000/00002/01740
d D 4.31 87/12/10 00:52:26 donn 31 30
c utah rcsid 1.27 87/04/01 14:00:45: Remove TVOID case in moditype so that
c void functions can properly be converted to pointers to void functions when
c used as operands.
e
s 00000/00008/01742
d D 4.30 87/12/10 00:52:14 donn 30 29
c utah rcsid 1.26 87/03/24 01:47:26: Remove tahoe ifdefs; the code table
c handles this correctly now.
e
s 00002/00001/01748
d D 4.29 87/12/10 00:52:02 donn 29 28
c utah rcsid 1.25 87/03/18 00:09:50: From Sam Kendall (sam@think.com): don't
c let structs, unions, floats, doubles or voids be cast into pointers.
e
s 00003/00002/01746
d D 4.28 87/12/10 00:51:50 donn 28 27
c utah rcsid 1.24 87/01/15 05:29:21: Fix brace balancing in ifdefs so that
c ctags works.
e
s 00007/00004/01741
d D 4.27 87/12/10 00:51:38 donn 27 26
c utah rcsid 1.23 87/01/15 02:12:21: Some minor lint fixes.
e
s 00005/00002/01740
d D 4.26 87/12/10 00:51:25 donn 26 25
c utah rcsid 1.22 86/11/28 21:21:08: Fix test for type puns when comparing
c constant enum values.  Also moved counter declaration into an ifdef.  Lint
c IS worth something!
e
s 00010/00000/01732
d D 4.25 87/12/10 00:51:12 donn 25 24
c utah rcsid 1.21 86/11/27 19:34:28: upgrade to ucb sid 4.11 --  'take care
c with unsigned constant compression (for tahoe); put back PRTDCON
c redefinition; ifdef asgop optimizations (tahoe can't handle them in code
c generation)' (sam).
e
s 00001/00001/01731
d D 4.24 87/12/10 00:50:57 donn 24 23
c utah rcsid 1.20 86/11/21 22:22:26: Changed 'illegal lhs of assignment
c operator' to 'illegal lvalue operand...' because there are unary assignment
c operators like ++ and --.
e
s 00006/00006/01726
d D 4.23 87/12/10 00:50:42 donn 23 22
c utah rcsid 1.19 86/11/10 09:21:58: More of the same -- unsigned compares
c between constants weren't unsigned.
e
s 00002/00002/01730
d D 4.22 87/12/10 00:50:30 donn 22 21
c utah rcsid 1.18 86/11/08 20:51:18: Argh -- restore commented-out cast which
c bollixed unsigned -> double (and float) conversions for constants.
e
s 00002/00002/01730
d D 4.21 87/12/10 00:50:16 donn 21 20
c utah rcsid 1.17 86/08/11 09:27:37: Oops -- void type is now represented by
c MVOID, not 0, in opact()...
e
s 00003/00002/01729
d D 4.20 87/12/10 00:50:02 donn 20 19
c utah rcsid 1.16 86/08/05 19:59:17: Permit void expressions in the colon
c part of a question mark operator (only, of course, if both subexpressions
c are type void).
e
s 00015/00010/01716
d D 4.19 87/12/10 00:49:42 donn 19 18
c utah rcsid 1.15 86/07/11 13:19:14: More changes for enums.  Did some tuning
c in opact() to remove clutter and handle unary operators.
e
s 00017/00018/01709
d D 4.18 87/12/10 00:49:27 donn 18 17
c utah rcsid 1.14 86/07/09 19:15:24: Guy Harris's fix for making chkpun()
c distinguish char **cpp and char c2a[10][20].
e
s 00012/00000/01715
d D 4.17 87/12/10 00:49:12 donn 17 16
c utah rcsid 1.13 86/07/08 16:05:37: Get more determined about 'usual type
c conversions' in conval() -- if we don't have the usual simple case, do the
c same type guessing that we would perform for non-constants.
e
s 00009/00005/01706
d D 4.16 87/12/10 00:48:59 donn 16 15
c utah rcsid 1.12 86/07/03 13:46:59: More tuning of enums hack.  Remove
c warning about ordering in chkpun(), change enum types to int and fall
c through to general case.
e
s 00029/00055/01682
d D 4.15 87/12/10 00:48:41 donn 15 14
c utah rcsid 1.11 86/07/02 22:40:02: First attack on enum bugs.  Eliminates
c all errors due to enum type &'clashes' and drastically reduces warnings.
c Only enum vs. enum clashes and enum comparisons are deemed worth a warning
c now.
e
s 00024/00000/01713
d D 4.14 87/04/22 15:14:57 bostic 14 13
c bug report 4.3BSD/usr.bin/51
e
s 00006/00006/01707
d D 4.13 86/12/02 16:29:18 bostic 13 12
c bug report 4.3BSD/lib/21
e
s 00002/00002/01711
d D 4.12 86/12/02 12:26:08 bostic 12 11
c bug report 4.3BSD/lib/10
e
s 00012/00001/01701
d D 4.11 86/10/15 22:05:43 sam 11 10
c take care with unsigned constant compression (for tahoe); 
c put back PRTDCON redefinition; ifdef asgop optimizations (tahoe can't 
c handle them in code generation)
e
s 00008/00004/01694
d D 4.10 86/01/08 01:14:35 donn 10 9
c (1) Make 'integer *= float' work right -- pass such asgops on to the back
c end without attempting to balance their types.  (2) Allow econvert() to be
c defined as a macro.  Lint uses this to avoid converting enum types.
e
s 00064/00060/01634
d D 4.9 85/08/22 19:09:06 mckusick 9 8
c update from donn@utah-cs
e
s 00003/00001/01691
d D 4.8 85/03/19 19:55:30 mckusick 8 7
c removed spurious type mismatch errors in expressions involving pointers
c to void functions, e.g., void foo(){...} void (*f)() = foo; (from sun!aoki)
e
s 00001/00001/01691
d D 4.7 85/03/19 13:10:03 ralph 7 6
c use common header file for C, Fortran, Pascal.
e
s 00205/00047/01487
d D 4.6 85/01/18 16:15:55 ralph 6 5
c changes for single precision floats; lint cleanups
e
s 00001/00001/01533
d D 4.5 84/10/03 11:01:38 ralph 5 4
c undo clocal() for PCONV, breaks constant pointer arithmetic.
e
s 00001/00000/01533
d D 4.4 84/09/20 16:55:25 ralph 4 3
c allow assignments to type void (*)();
e
s 00002/00002/01531
d D 4.3 84/08/29 09:29:07 ralph 3 2
c call clocal after inserting SCONV's in makety.
e
s 00006/00000/01527
d D 4.2 84/03/14 15:34:25 ralph 2 1
c print error message for funny conditional expression types.
e
s 01527/00000/00000
d D 4.1 84/03/14 15:32:50 ralph 1 0
c date and time created 84/03/14 15:32:50 by ralph
e
u
U
t
T
I 6
#ifndef lint
E 6
I 1
static char *sccsid ="%W% (Berkeley) %G%";
I 6
#endif

E 6
D 7
# include "mfile1"
E 7
I 7
# include "pass1.h"
E 7

I 9
# include <setjmp.h>

E 9
I 6
int bdebug = 0;
int adebug = 0;
extern ddebug;
extern eprint();

E 6
	    /* corrections when in violation of lint */

/*	some special actions, used in finding the type of nodes */
# define NCVT 01
# define PUN 02
# define TYPL 04
# define TYPR 010
# define TYMATCH 040
# define LVAL 0100
# define CVTO 0200
# define CVTL 0400
# define CVTR 01000
# define PTMATCH 02000
# define OTHER 04000
# define NCVTR 010000

I 6
#ifndef BUG1
printact(t, acts)
	NODE *t;
	int acts;
{
	static struct actions {
		int	a_bit;
		char	*a_name;
	} actions[] = {
		{ PUN,		"PUN" },
		{ CVTL,		"CVTL" },
		{ CVTR,		"CVTR" },
		{ TYPL,		"TYPL" },
		{ TYPR,		"TYPR" },
		{ TYMATCH,	"TYMATCH" },
		{ PTMATCH,	"PTMATCH" },
		{ LVAL,		"LVAL" },
		{ CVTO,		"CVTO" },
		{ NCVT,		"NCVT" },
		{ OTHER,	"OTHER" },
		{ NCVTR,	"NCVTR" },
		{ 0 }
	};
	register struct actions *p;
	char *sep = " ";

	printf("actions");
	for (p = actions; p->a_name; p++)
		if (p->a_bit & acts) {
			printf("%s%s", sep, p->a_name);
			sep = "|";
		}
	if (!bdebug) {
		printf(" for:\n");
		fwalk(t, eprint, 0);
	} else
		putchar('\n');
}
#endif

E 6
/* node conventions:

	NAME:	rval>0 is stab index for external
		rval<0 is -inlabel number
		lval is offset in bits
	ICON:	lval has the value
		rval has the STAB index, or - label number,
			if a name whose address is in the constant
		rval = NONAME means no name
	REG:	rval is reg. identification cookie

	*/

D 6
int bdebug = 0;
extern ddebug;

E 6
NODE *
buildtree( o, l, r ) register NODE *l, *r; {
	register NODE *p, *q;
	register actions;
	register opty;
	register struct symtab *sp;
	register NODE *lr, *ll;
I 6
	NODE *fixargs();
E 6
	int i;
D 6
	extern int eprint();
E 6

# ifndef BUG1
	if( bdebug ) printf( "buildtree( %s, %o, %o )\n", opst[o], l, r );
# endif
	opty = optype(o);

	/* check for constants */

	if( opty == UTYPE && l->in.op == ICON ){

		switch( o ){

		case NOT:
			if( hflag ) werror( "constant argument to NOT" );
		case UNARY MINUS:
		case COMPL:
			if( conval( l, o, l ) ) return(l);
			break;

			}
		}

D 36
	else if( o==UNARY MINUS && l->in.op==FCON ){
D 6
		l->fpn.dval = -l->fpn.dval;
E 6
I 6
		l->fpn.fval = -l->fpn.fval;
E 6
		return(l);
		}
E 36
I 36
	else if( opty == UTYPE && (l->in.op == FCON || l->in.op == DCON) ){
E 36

I 6
D 36
	else if( o==UNARY MINUS && l->in.op==DCON ){
		l->dpn.dval = -l->dpn.dval;
		return(l);
E 36
I 36
		switch( o ){

		case NOT:
			if( hflag ) werror( "constant argument to NOT" );
			if( l->in.op == FCON )
				l->tn.lval = l->fpn.fval == 0.0;
			else
				l->tn.lval = l->dpn.dval == 0.0;
			l->tn.rval = NONAME;
			l->in.op = ICON;
			l->fn.csiz = l->in.type = INT;
			l->fn.cdim = 0;
			return(l);
		case UNARY MINUS:
			if( l->in.op == FCON )
				l->fpn.fval = -l->fpn.fval;
			else
				l->dpn.dval = -l->dpn.dval;
			return(l);
			}
E 36
		}

E 6
	else if( o==QUEST && l->in.op==ICON ) {
		l->in.op = FREE;
		r->in.op = FREE;
		if( l->tn.lval ){
			tfree( r->in.right );
			return( r->in.left );
			}
		else {
			tfree( r->in.left );
			return( r->in.right );
			}
		}

	else if( (o==ANDAND || o==OROR) && (l->in.op==ICON||r->in.op==ICON) ) goto ccwarn;

	else if( opty == BITYPE && l->in.op == ICON && r->in.op == ICON ){

		switch( o ){

		case ULT:
		case UGT:
		case ULE:
		case UGE:
		case LT:
		case GT:
		case LE:
		case GE:
		case EQ:
		case NE:
I 15
D 26
			if( l->in.type == ENUMTY && r->in.type == ENUMTY )
E 26
I 26
			if( l->in.type == ENUMTY && r->in.type == ENUMTY ){
				p = block( o, l, r, INT, 0, INT );
E 26
				chkpun( p );
I 26
				p->in.op = FREE;
				}
E 26

E 15
		case ANDAND:
		case OROR:
		case CBRANCH:

		ccwarn:
			if( hflag ) werror( "constant in conditional context" );

		case PLUS:
		case MINUS:
		case MUL:
		case DIV:
		case MOD:
		case AND:
		case OR:
		case ER:
		case LS:
		case RS:
			if( conval( l, o, r ) ) {
				r->in.op = FREE;
				return(l);
				}
			break;
			}
		}
I 6
D 9
	else if (opty == BITYPE) {
		if ((l->in.op == FCON || l->in.op == ICON) &&
		    (r->in.op == FCON || r->in.op == ICON))
			switch (o) {
E 9
I 9
	else if (opty == BITYPE &&
		(l->in.op == FCON || l->in.op == DCON || l->in.op == ICON) &&
		(r->in.op == FCON || r->in.op == DCON || r->in.op == ICON)) {
			if (o == PLUS || o == MINUS || o == MUL || o == DIV) {
				extern int fpe_count;
				extern jmp_buf gotfpe;
E 9
E 6

D 6
	else if( opty == BITYPE && (l->in.op==FCON||l->in.op==ICON) &&
		(r->in.op==FCON||r->in.op==ICON) ){
		switch(o){
		case PLUS:
		case MINUS:
		case MUL:
		case DIV:
			if( l->in.op == ICON ){
				l->fpn.dval = l->tn.lval;
E 6
I 6
D 9
			case PLUS:
			case MINUS:
			case MUL:
			case DIV:
E 9
I 9
				fpe_count = 0;
				if (setjmp(gotfpe))
					goto treatfpe;
E 9
				if (l->in.op == ICON)
D 9
					l->fpn.fval = l->tn.lval;
				if (r->in.op == ICON)
					r->fpn.fval = r->tn.lval;
				l->in.op = FCON;
				l->in.type = l->fn.csiz = FLOAT;
				r->in.op = FREE;
				switch (o) {

				case PLUS:
					l->fpn.fval += r->fpn.fval;
					return (l);

				case MINUS:
					l->fpn.fval -= r->fpn.fval;
					return (l);

				case MUL:
					l->fpn.fval *= r->fpn.fval;
					return (l);

				case DIV:
					if (r->fpn.fval == 0)
						uerror("division by 0.");
					else
						l->fpn.fval /= r->fpn.fval;
					return (l);
E 6
				}
D 6
			if( r->in.op == ICON ){
				r->fpn.dval = r->tn.lval;
				}
			l->in.op = FCON;
			l->in.type = l->fn.csiz = DOUBLE;
			r->in.op = FREE;
			switch(o){
E 6
I 6
			}
		else if ((l->in.op == DCON || l->in.op == ICON) &&
		    (r->in.op == DCON || r->in.op == ICON))
			switch (o) {

E 6
			case PLUS:
D 6
				l->fpn.dval += r->fpn.dval;
				return(l);
E 6
			case MINUS:
D 6
				l->fpn.dval -= r->fpn.dval;
				return(l);
E 6
			case MUL:
D 6
				l->fpn.dval *= r->fpn.dval;
				return(l);
E 6
			case DIV:
D 6
				if( r->fpn.dval == 0 ) uerror( "division by 0." );
				else l->fpn.dval /= r->fpn.dval;
				return(l);
E 6
I 6
				if (l->in.op == ICON)
E 9
					l->dpn.dval = l->tn.lval;
I 9
				else if (l->in.op == FCON)
					l->dpn.dval = l->fpn.fval;
E 9
				if (r->in.op == ICON)
					r->dpn.dval = r->tn.lval;
D 9
				l->in.op = DCON;
				l->in.type = l->fn.csiz = DOUBLE;
				r->in.op = FREE;
E 9
I 9
				else if (r->in.op == FCON)
					r->dpn.dval = r->fpn.fval;
E 9
				switch (o) {

				case PLUS:
					l->dpn.dval += r->dpn.dval;
D 9
					return (l);
E 9
I 9
					break;
E 9

				case MINUS:
					l->dpn.dval -= r->dpn.dval;
D 9
					return (l);
E 9
I 9
					break;
E 9

				case MUL:
					l->dpn.dval *= r->dpn.dval;
D 9
					return (l);
E 9
I 9
					break;
E 9

				case DIV:
					if (r->dpn.dval == 0)
						uerror("division by 0.");
					else
						l->dpn.dval /= r->dpn.dval;
D 9
					return (l);
E 6
				}
E 9
I 9
					break;
					}
			treatfpe:
				if (fpe_count > 0) {
					uerror("floating point exception in constant expression");
					l->dpn.dval = 1.0; /* Fairly harmless */
					}
				fpe_count = -1;
				l->in.op = DCON;
				l->in.type = l->fn.csiz = DOUBLE;
				r->in.op = FREE;
				return (l);
E 9
			}
D 6
		}
E 6
I 6
D 9
	}
E 9
I 9
		}
E 9
E 6

D 9
	/* its real; we must make a new node */
E 9
I 9
	/* it's real; we must make a new node */
E 9

	p = block( o, l, r, INT, 0, INT );

	actions = opact(p);
I 6
#ifndef	BUG1
	if (adebug)
		printact(p, actions);
#endif
E 6

	if( actions&LVAL ){ /* check left descendent */
		if( notlval(p->in.left) ) {
D 24
			uerror( "illegal lhs of assignment operator" );
E 24
I 24
			uerror( "illegal lvalue operand of assignment operator" );
E 24
			}
		}

	if( actions & NCVTR ){
		p->in.left = pconvert( p->in.left );
		}
	else if( !(actions & NCVT ) ){
		switch( opty ){

		case BITYPE:
			p->in.right = pconvert( p->in.right );
		case UTYPE:
			p->in.left = pconvert( p->in.left );

			}
		}

	if( (actions&PUN) && (o!=CAST||cflag) ){
		chkpun(p);
		}

	if( actions & (TYPL|TYPR) ){

		q = (actions&TYPL) ? p->in.left : p->in.right;

		p->in.type = q->in.type;
		p->fn.cdim = q->fn.cdim;
		p->fn.csiz = q->fn.csiz;
		}

	if( actions & CVTL ) p = convert( p, CVTL );
	if( actions & CVTR ) p = convert( p, CVTR );
	if( actions & TYMATCH ) p = tymatch(p);
	if( actions & PTMATCH ) p = ptmatch(p);

	if( actions & OTHER ){
		l = p->in.left;
		r = p->in.right;

		switch(o){

		case NAME:
			sp = &stab[idname];
			if( sp->stype == UNDEF ){
#ifndef FLEXNAMES
				uerror( "%.8s undefined", sp->sname );
#else
				uerror( "%s undefined", sp->sname );
#endif
				/* make p look reasonable */
D 36
				p->in.type = p->fn.cdim = p->fn.csiz = INT;
E 36
I 36
				p->in.type = p->fn.csiz = INT;
				p->fn.cdim = 0;
E 36
				p->tn.rval = idname;
				p->tn.lval = 0;
				defid( p, SNULL );
				break;
				}
			p->in.type = sp->stype;
			p->fn.cdim = sp->dimoff;
			p->fn.csiz = sp->sizoff;
			p->tn.lval = 0;
			p->tn.rval = idname;
			/* special case: MOETY is really an ICON... */
			if( p->in.type == MOETY ){
				p->tn.rval = NONAME;
				p->tn.lval = sp->offset;
				p->fn.cdim = 0;
				p->in.type = ENUMTY;
				p->in.op = ICON;
				}
			break;

		case ICON:
			p->in.type = INT;
			p->fn.cdim = 0;
			p->fn.csiz = INT;
			break;

		case STRING:
			p->in.op = NAME;
			p->in.type = CHAR+ARY;
			p->tn.lval = 0;
			p->tn.rval = NOLAB;
			p->fn.cdim = curdim;
			p->fn.csiz = CHAR;
			break;

		case FCON:
			p->tn.lval = 0;
			p->tn.rval = 0;
I 6
			p->in.type = FLOAT;
			p->fn.cdim = 0;
			p->fn.csiz = FLOAT;
			break;

		case DCON:
			p->tn.lval = 0;
			p->tn.rval = 0;
E 6
			p->in.type = DOUBLE;
			p->fn.cdim = 0;
			p->fn.csiz = DOUBLE;
			break;

		case STREF:
			/* p->x turned into *(p+offset) */
			/* rhs must be a name; check correctness */

			i = r->tn.rval;
			if( i<0 || ((sp= &stab[i])->sclass != MOS && sp->sclass != MOU && !(sp->sclass&FIELD)) ){
				uerror( "member of structure or union required" );
				}else
			/* if this name is non-unique, find right one */
			if( stab[i].sflags & SNONUNIQ &&
				(l->in.type==PTR+STRTY || l->in.type == PTR+UNIONTY) &&
				(l->fn.csiz +1) >= 0 ){
				/* nonunique name && structure defined */
				char * memnam, * tabnam;
D 26
				register k;
E 26
				int j;
				int memi;
				j=dimtab[l->fn.csiz+1];
				for( ; (memi=dimtab[j]) >= 0; ++j ){
					tabnam = stab[memi].sname;
					memnam = stab[i].sname;
# ifndef BUG1
					if( ddebug>1 ){
#ifndef FLEXNAMES
						printf("member %.8s==%.8s?\n",
#else
						printf("member %s==%s?\n",
#endif
							memnam, tabnam);
						}
# endif
					if( stab[memi].sflags & SNONUNIQ ){
#ifndef FLEXNAMES
I 26
						register k;
E 26
						for( k=0; k<NCHNAM; ++k ){
							if(*memnam++!=*tabnam)
								goto next;
							if(!*tabnam++) break;
							}
#else
						if (memnam != tabnam)
							goto next;
#endif
						r->tn.rval = i = memi;
						break;
						}
					next: continue;
					}
				if( memi < 0 )
#ifndef FLEXNAMES
					uerror("illegal member use: %.8s",
#else
					uerror("illegal member use: %s",
#endif
						stab[i].sname);
				}
			else {
				register j;
				if( l->in.type != PTR+STRTY && l->in.type != PTR+UNIONTY ){
					if( stab[i].sflags & SNONUNIQ ){
						uerror( "nonunique name demands struct/union or struct/union pointer" );
						}
					else werror( "struct/union or struct/union pointer required" );
					}
				else if( (j=l->fn.csiz+1)<0 ) cerror( "undefined structure or union" );
				else if( !chkstr( i, dimtab[j], DECREF(l->in.type) ) ){
#ifndef FLEXNAMES
					werror( "illegal member use: %.8s", stab[i].sname );
#else
					werror( "illegal member use: %s", stab[i].sname );
#endif
					}
				}

			p = stref( p );
			break;

		case UNARY MUL:
			if( l->in.op == UNARY AND ){
				p->in.op = l->in.op = FREE;
				p = l->in.left;
				}
			if( !ISPTR(l->in.type))uerror("illegal indirection");
			p->in.type = DECREF(l->in.type);
			p->fn.cdim = l->fn.cdim;
			p->fn.csiz = l->fn.csiz;
			break;

		case UNARY AND:
			switch( l->in.op ){

			case UNARY MUL:
				p->in.op = l->in.op = FREE;
				p = l->in.left;
			case NAME:
				p->in.type = INCREF( l->in.type );
				p->fn.cdim = l->fn.cdim;
				p->fn.csiz = l->fn.csiz;
				break;

			case COMOP:
				lr = buildtree( UNARY AND, l->in.right, NIL );
				p->in.op = l->in.op = FREE;
				p = buildtree( COMOP, l->in.left, lr );
				break;

			case QUEST:
				lr = buildtree( UNARY AND, l->in.right->in.right, NIL );
				ll = buildtree( UNARY AND, l->in.right->in.left, NIL );
				p->in.op = l->in.op = l->in.right->in.op = FREE;
				p = buildtree( QUEST, l->in.left, buildtree( COLON, ll, lr ) );
				break;

# ifdef ADDROREG
			case OREG:
				/* OREG was built in clocal()
				 * for an auto or formal parameter
				 * now its address is being taken
				 * local code must unwind it
				 * back to PLUS/MINUS REG ICON
				 * according to local conventions
				 */
				{
				extern NODE * addroreg();
				p->in.op = FREE;
				p = addroreg( l );
				}
				break;

# endif
			default:
				uerror( "unacceptable operand of &" );
				break;
				}
			break;

		case LS:
		case RS:
I 36
			if( l->in.type == CHAR || l->in.type == SHORT )
				p->in.type = INT;
			else if( l->in.type == UCHAR || l->in.type == USHORT )
				p->in.type = UNSIGNED;
			else
				p->in.type = l->in.type;
E 36
		case ASG LS:
		case ASG RS:
D 36
			if(tsize(p->in.right->in.type, p->in.right->fn.cdim, p->in.right->fn.csiz) > SZINT)
				p->in.right = makety(p->in.right, INT, 0, INT );
E 36
I 36
			if( r->in.type != INT )
				p->in.right = r = makety(r, INT, 0, INT );
E 36
			break;

		case RETURN:
		case ASSIGN:
		case CAST:
			/* structure assignment */
			/* take the addresses of the two sides; then make an
			/* operator using STASG and
			/* the addresses of left and right */

			{
				register TWORD t;
				register d, s;

				if( l->fn.csiz != r->fn.csiz ) uerror( "assignment of different structures" );

				r = buildtree( UNARY AND, r, NIL );
				t = r->in.type;
				d = r->fn.cdim;
				s = r->fn.csiz;

				l = block( STASG, l, r, t, d, s );

				if( o == RETURN ){
					p->in.op = FREE;
					p = l;
					break;
					}

				p->in.op = UNARY MUL;
				p->in.left = l;
				p->in.right = NIL;
				break;
				}
		case COLON:
			/* structure colon */

			if( l->fn.csiz != r->fn.csiz ) uerror( "type clash in conditional" );
			break;

		case CALL:
D 6
			p->in.right = r = strargs( p->in.right );
E 6
I 6
			p->in.right = r = fixargs( p->in.right );
E 6
		case UNARY CALL:
			if( !ISPTR(l->in.type)) uerror("illegal function");
			p->in.type = DECREF(l->in.type);
			if( !ISFTN(p->in.type)) uerror("illegal function");
			p->in.type = DECREF( p->in.type );
			p->fn.cdim = l->fn.cdim;
			p->fn.csiz = l->fn.csiz;
			if( l->in.op == UNARY AND && l->in.left->in.op == NAME &&
				l->in.left->tn.rval >= 0 && l->in.left->tn.rval != NONAME &&
				( (i=stab[l->in.left->tn.rval].sclass) == FORTRAN || i==UFORTRAN ) ){
				p->in.op += (FORTCALL-CALL);
				}
			if( p->in.type == STRTY || p->in.type == UNIONTY ){
				/* function returning structure */
				/*  make function really return ptr to str., with * */

				p->in.op += STCALL-CALL;
				p->in.type = INCREF( p->in.type );
				p = buildtree( UNARY MUL, p, NIL );

				}
			break;

		default:
			cerror( "other code %d", o );
			}

		}

	if( actions & CVTO ) p = oconvert(p);
	p = clocal(p);

# ifndef BUG1
	if( bdebug ) fwalk( p, eprint, 0 );
# endif

	return(p);

	}

I 9
int fpe_count = -1;
jmp_buf gotfpe;

fpe() {
	if (fpe_count < 0)
		cerror("floating point exception");
	++fpe_count;
	longjmp(gotfpe, 1);
	}

E 9
I 6
/*
 * Rewrite arguments in a function call.
 * Structure arguments are massaged, single
 * precision floating point constants are
 * cast to double (to eliminate convert code).
 */
E 6
NODE *
D 6
strargs( p ) register NODE *p;  { /* rewrite structure flavored arguments */
E 6
I 6
fixargs( p ) register NODE *p;  {
	int o = p->in.op;
E 6

D 6
	if( p->in.op == CM ){
		p->in.left = strargs( p->in.left );
		p->in.right = strargs( p->in.right );
E 6
I 6
	if( o == CM ){
		p->in.left = fixargs( p->in.left );
		p->in.right = fixargs( p->in.right );
E 6
		return( p );
		}

	if( p->in.type == STRTY || p->in.type == UNIONTY ){
		p = block( STARG, p, NIL, p->in.type, p->fn.cdim, p->fn.csiz );
		p->in.left = buildtree( UNARY AND, p->in.left, NIL );
		p = clocal(p);
		}
I 6
	else if( o == FCON )
		p = makety(p, DOUBLE, 0, 0);
E 6
	return( p );
	}

chkstr( i, j, type ) TWORD type; {
	/* is the MOS or MOU at stab[i] OK for strict reference by a ptr */
	/* i has been checked to contain a MOS or MOU */
	/* j is the index in dimtab of the members... */
	int k, kk;

	extern int ddebug;

# ifndef BUG1
#ifndef FLEXNAMES
	if( ddebug > 1 ) printf( "chkstr( %.8s(%d), %d )\n", stab[i].sname, i, j );
#else
	if( ddebug > 1 ) printf( "chkstr( %s(%d), %d )\n", stab[i].sname, i, j );
#endif
# endif
	if( (k = j) < 0 ) uerror( "undefined structure or union" );
	else {
		for( ; (kk = dimtab[k] ) >= 0; ++k ){
			if( kk >= SYMTSZ ){
				cerror( "gummy structure" );
				return(1);
				}
			if( kk == i ) return( 1 );
			switch( stab[kk].stype ){

			case STRTY:
			case UNIONTY:
				if( type == STRTY ) continue;  /* no recursive looking for strs */
				if( hflag && chkstr( i, dimtab[stab[kk].sizoff+1], stab[kk].stype ) ){
					if( stab[kk].sname[0] == '$' ) return(0);  /* $FAKE */
					werror(
#ifndef FLEXNAMES
					"illegal member use: perhaps %.8s.%.8s?",
#else
					"illegal member use: perhaps %s.%s?",
#endif
					stab[kk].sname, stab[i].sname );
					return(1);
					}
				}
			}
		}
	return( 0 );
	}

conval( p, o, q ) register NODE *p, *q; {
	/* apply the op o to the lval part of p; if binary, rhs is val */
I 17
	/* works only on integer constants */
	NODE *r;
E 17
	int i, u;
	CONSZ val;
I 32
	TWORD utype;
E 32

	val = q->tn.lval;
	u = ISUNSIGNED(p->in.type) || ISUNSIGNED(q->in.type);
	if( u && (o==LE||o==LT||o==GE||o==GT)) o += (UGE-GE);

	if( p->tn.rval != NONAME && q->tn.rval != NONAME ) return(0);
	if( q->tn.rval != NONAME && o!=PLUS ) return(0);
	if( p->tn.rval != NONAME && o!=PLUS && o!=MINUS ) return(0);
I 17

D 32
	if( p->in.type != INT || q->in.type != INT ){
		/* will this always work if p == q and o is UTYPE? */
		r = block( o, p, q, INT, 0, INT );
		r = tymatch( r );
		p->in.type = r->in.type;
		p->fn.cdim = r->fn.cdim;
		p->fn.csiz = r->fn.csiz;
		r->in.op = FREE;
		}
E 32
I 32
	/* usual type conversions -- handle casts of constants */
D 34
	utype = u ? UNSIGNED : INT;
E 34
I 34
#define	ISLONG(t)	((t) == LONG || (t) == ULONG)
	if (ISLONG(p->in.type) || ISLONG(q->in.type))
		utype = u ? ULONG : LONG;
	else
		utype = u ? UNSIGNED : INT;
E 34
	if( !ISPTR(p->in.type) && p->in.type != utype )
		p = makety(p, utype, 0, (int)utype);
	if( q->in.type != utype )
		q = makety(q, utype, 0, (int)utype);
E 32
E 17

	switch( o ){

	case PLUS:
		p->tn.lval += val;
		if( p->tn.rval == NONAME ){
			p->tn.rval = q->tn.rval;
			p->in.type = q->in.type;
			}
		break;
	case MINUS:
		p->tn.lval -= val;
		break;
	case MUL:
D 11
		p->tn.lval *= val;
E 11
I 11
D 15
		if ( u ) p->tn.lval *= (unsigned) val;
		else p->tn.lval *= val;
E 15
I 15
		p->tn.lval *= val;
E 15
E 11
		break;
	case DIV:
		if( val == 0 ) uerror( "division by 0" );
I 6
		else if ( u ) p->tn.lval = (unsigned) p->tn.lval / val;
E 6
		else p->tn.lval /= val;
		break;
	case MOD:
		if( val == 0 ) uerror( "division by 0" );
I 6
		else if ( u ) p->tn.lval = (unsigned) p->tn.lval % val;
E 6
		else p->tn.lval %= val;
		break;
	case AND:
		p->tn.lval &= val;
		break;
	case OR:
		p->tn.lval |= val;
		break;
	case ER:
D 6
		p->tn.lval ^=  val;
E 6
I 6
		p->tn.lval ^= val;
E 6
		break;
	case LS:
		i = val;
		p->tn.lval = p->tn.lval << i;
		break;
	case RS:
		i = val;
D 6
		p->tn.lval = p->tn.lval >> i;
E 6
I 6
		if ( u ) p->tn.lval = (unsigned) p->tn.lval >> i;
		else p->tn.lval = p->tn.lval >> i;
E 6
		break;

	case UNARY MINUS:
		p->tn.lval = - p->tn.lval;
		break;
	case COMPL:
		p->tn.lval = ~p->tn.lval;
		break;
	case NOT:
		p->tn.lval = !p->tn.lval;
		break;
	case LT:
		p->tn.lval = p->tn.lval < val;
		break;
	case LE:
		p->tn.lval = p->tn.lval <= val;
		break;
	case GT:
		p->tn.lval = p->tn.lval > val;
		break;
	case GE:
		p->tn.lval = p->tn.lval >= val;
		break;
	case ULT:
D 13
		p->tn.lval = (p->tn.lval-val)<0;
E 13
I 13
D 15
		p->tn.lval = p->tn.lval < (unsigned) val;
E 15
I 15
D 23
		p->tn.lval = (p->tn.lval-val)<0;
E 23
I 23
		p->tn.lval = p->tn.lval < (unsigned) val;
E 23
E 15
E 13
		break;
	case ULE:
D 13
		p->tn.lval = (p->tn.lval-val)<=0;
E 13
I 13
D 15
		p->tn.lval = p->tn.lval <= (unsigned) val;
E 15
I 15
D 23
		p->tn.lval = (p->tn.lval-val)<=0;
E 23
I 23
		p->tn.lval = p->tn.lval <= (unsigned) val;
E 23
E 15
E 13
		break;
D 13
	case UGE:
		p->tn.lval = (p->tn.lval-val)>=0;
		break;
E 13
D 15
	case UGT:
D 13
		p->tn.lval = (p->tn.lval-val)>0;
E 13
I 13
		p->tn.lval = p->tn.lval > (unsigned) val;
		break;
E 15
D 23
	case UGE:
D 15
		p->tn.lval = p->tn.lval >= (unsigned) val;
E 15
I 15
		p->tn.lval = (p->tn.lval-val)>=0;
E 15
E 13
		break;
E 23
I 15
	case UGT:
D 23
		p->tn.lval = (p->tn.lval-val)>0;
E 23
I 23
		p->tn.lval = p->tn.lval > (unsigned) val;
		break;
	case UGE:
		p->tn.lval = p->tn.lval >= (unsigned) val;
E 23
		break;
E 15
	case EQ:
		p->tn.lval = p->tn.lval == val;
		break;
	case NE:
		p->tn.lval = p->tn.lval != val;
		break;
	default:
		return(0);
		}
	return(1);
	}

chkpun(p) register NODE *p; {

	/* checks p for the existance of a pun */

	/* this is called when the op of p is ASSIGN, RETURN, CAST, COLON, or relational */

	/* one case is when enumerations are used: this applies only to lint */
	/* in the other case, one operand is a pointer, the other integer type */
	/* we check that this integer is in fact a constant zero... */

	/* in the case of ASSIGN, any assignment of pointer to integer is illegal */
	/* this falls out, because the LHS is never 0 */

	register NODE *q;
	register t1, t2;
	register d1, d2;
I 19
	int ref1, ref2;
E 19

	t1 = p->in.left->in.type;
	t2 = p->in.right->in.type;

	if( t1==ENUMTY || t2==ENUMTY ) { /* check for enumerations */
I 16
		/* rob pike says this is obnoxious...
E 16
D 15
		if( logop( p->in.op ) && p->in.op != EQ && p->in.op != NE ) {
			uerror( "illegal comparison of enums" );
			return;
			}
		if( t1==ENUMTY && t2==ENUMTY && p->in.left->fn.csiz==p->in.right->fn.csiz ) return;
		werror( "enumeration type clash, operator %s", opst[p->in.op] );
E 15
I 15
		if( logop( p->in.op ) && p->in.op != EQ && p->in.op != NE )
D 16
			werror( "comparison of enums" );
		if( t1==ENUMTY && t2==ENUMTY &&
		    p->in.left->fn.csiz!=p->in.right->fn.csiz )
			werror( "enumeration type clash, operator %s", opst[p->in.op] );
E 15
		return;
E 16
I 16
			werror( "comparison of enums" ); */
		if( t1==ENUMTY && t2==ENUMTY ) {
			if ( p->in.left->fn.csiz!=p->in.right->fn.csiz )
				werror( "enumeration type clash, operator %s", opst[p->in.op] );
			return;
			}
		if ( t1 == ENUMTY ) t1 = INT;
		if ( t2 == ENUMTY ) t2 = INT;
E 16
		}

D 19
	if( ISPTR(t1) || ISARY(t1) ) q = p->in.right;
	else q = p->in.left;
E 19
I 19
	ref1 = ISPTR(t1) || ISARY(t1);
	ref2 = ISPTR(t2) || ISARY(t2);
E 19

D 19
	if( !ISPTR(q->in.type) && !ISARY(q->in.type) ){
E 19
I 19
	if( ref1 ^ ref2 ){
		if( ref1 ) q = p->in.right;
		else q = p->in.left;
E 19
		if( q->in.op != ICON || q->tn.lval != 0 ){
			werror( "illegal combination of pointer and integer, op %s",
				opst[p->in.op] );
			}
		}
D 19
	else {
E 19
I 19
	else if( ref1 ){
E 19
D 18
		d1 = p->in.left->fn.cdim;
		d2 = p->in.right->fn.cdim;
		for( ;; ){
			if( t1 == t2 ) {;
				if( p->in.left->fn.csiz != p->in.right->fn.csiz ) {
					werror( "illegal structure pointer combination" );
					}
E 18
I 18
		if( t1 == t2 ) {
			if( p->in.left->fn.csiz != p->in.right->fn.csiz ) {
				werror( "illegal structure pointer combination" );
E 18
				return;
				}
D 18
			if( ISARY(t1) || ISPTR(t1) ){
				if( !ISARY(t2) && !ISPTR(t2) ) break;
				if( ISARY(t1) && ISARY(t2) && dimtab[d1] != dimtab[d2] ){
					werror( "illegal array size combination" );
					return;
E 18
I 18
			d1 = p->in.left->fn.cdim;
			d2 = p->in.right->fn.cdim;
			for( ;; ){
				if( ISARY(t1) ){
					if( dimtab[d1] != dimtab[d2] ){
						werror( "illegal array size combination" );
						return;
						}
					++d1;
					++d2;
E 18
					}
D 18
				if( ISARY(t1) ) ++d1;
				if( ISARY(t2) ) ++d2;
E 18
I 18
				else if( !ISPTR(t1) ) break;
				t1 = DECREF(t1);
E 18
				}
D 18
			else break;
			t1 = DECREF(t1);
			t2 = DECREF(t2);
E 18
			}
D 18
		werror( "illegal pointer combination" );
E 18
I 18
D 36
		else
E 36
I 36
		else if( t1 != INCREF(UNDEF) && t2 != INCREF(UNDEF) )
E 36
			werror( "illegal pointer combination" );
E 18
		}

	}

NODE *
stref( p ) register NODE *p; {

	TWORD t;
	int d, s, dsc, align;
	OFFSZ off;
	register struct symtab *q;

	/* make p->x */
	/* this is also used to reference automatic variables */

	q = &stab[p->in.right->tn.rval];
	p->in.right->in.op = FREE;
	p->in.op = FREE;
	p = pconvert( p->in.left );

	/* make p look like ptr to x */

	if( !ISPTR(p->in.type)){
		p->in.type = PTR+UNIONTY;
		}

	t = INCREF( q->stype );
	d = q->dimoff;
	s = q->sizoff;

	p = makety( p, t, d, s );

	/* compute the offset to be added */

	off = q->offset;
	dsc = q->sclass;

	if( dsc & FIELD ) {  /* normalize offset */
		align = ALINT;
		s = INT;
		off = (off/align)*align;
		}
	if( off != 0 ) p = clocal( block( PLUS, p, offcon( off, t, d, s ), t, d, s ) );

	p = buildtree( UNARY MUL, p, NIL );

	/* if field, build field info */

	if( dsc & FIELD ){
		p = block( FLD, p, NIL, q->stype, 0, q->sizoff );
		p->tn.rval = PKFIELD( dsc&FLDSIZ, q->offset%align );
		}

	return( clocal(p) );
	}

notlval(p) register NODE *p; {

	/* return 0 if p an lvalue, 1 otherwise */

	again:

	switch( p->in.op ){

	case FLD:
		p = p->in.left;
		goto again;

	case UNARY MUL:
		/* fix the &(a=b) bug, given that a and b are structures */
		if( p->in.left->in.op == STASG ) return( 1 );
		/* and the f().a bug, given that f returns a structure */
		if( p->in.left->in.op == UNARY STCALL ||
		    p->in.left->in.op == STCALL ) return( 1 );
	case NAME:
	case OREG:
		if( ISARY(p->in.type) || ISFTN(p->in.type) ) return(1);
	case REG:
		return(0);

	default:
		return(1);

		}

	}

NODE *
bcon( i ){ /* make a constant node with value i */
	register NODE *p;

	p = block( ICON, NIL, NIL, INT, 0, INT );
	p->tn.lval = i;
	p->tn.rval = NONAME;
	return( clocal(p) );
	}

NODE *
bpsize(p) register NODE *p; {
	return( offcon( psize(p), p->in.type, p->fn.cdim, p->fn.csiz ) );
	}

OFFSZ
psize( p ) NODE *p; {
	/* p is a node of type pointer; psize returns the
	   size of the thing pointed to */

	if( !ISPTR(p->in.type) ){
		uerror( "pointer required");
		return( SZINT );
		}
	/* note: no pointers to fields */
	return( tsize( DECREF(p->in.type), p->fn.cdim, p->fn.csiz ) );
	}

NODE *
convert( p, f )  register NODE *p; {
	/*  convert an operand of p
	    f is either CVTL or CVTR
	    operand has type int, and is converted by the size of the other side
	    */

	register NODE *q, *r;

	q = (f==CVTL)?p->in.left:p->in.right;

	r = block( PMCONV,
		q, bpsize(f==CVTL?p->in.right:p->in.left), INT, 0, INT );
	r = clocal(r);
	if( f == CVTL )
		p->in.left = r;
	else
		p->in.right = r;
	return(p);

	}

I 10
#ifndef econvert
E 10
econvert( p ) register NODE *p; {

	/* change enums to ints, or appropriate types */

	register TWORD ty;

	if( (ty=BTYPE(p->in.type)) == ENUMTY || ty == MOETY ) {
		if( dimtab[ p->fn.csiz ] == SZCHAR ) ty = CHAR;
		else if( dimtab[ p->fn.csiz ] == SZINT ) ty = INT;
		else if( dimtab[ p->fn.csiz ] == SZSHORT ) ty = SHORT;
		else ty = LONG;
		ty = ctype( ty );
		p->fn.csiz = ty;
		MODTYPE(p->in.type,ty);
		if( p->in.op == ICON && ty != LONG ) p->in.type = p->fn.csiz = INT;
		}
	}
I 10
#endif
E 10

NODE *
pconvert( p ) register NODE *p; {

	/* if p should be changed into a pointer, do so */

	if( ISARY( p->in.type) ){
		p->in.type = DECREF( p->in.type );
		++p->fn.cdim;
		return( buildtree( UNARY AND, p, NIL ) );
		}
	if( ISFTN( p->in.type) )
		return( buildtree( UNARY AND, p, NIL ) );

	return( p );
	}

NODE *
oconvert(p) register NODE *p; {
	/* convert the result itself: used for pointer and unsigned */

	switch(p->in.op) {

	case LE:
	case LT:
	case GE:
	case GT:
		if( ISUNSIGNED(p->in.left->in.type) || ISUNSIGNED(p->in.right->in.type) )  p->in.op += (ULE-LE);
	case EQ:
	case NE:
		return( p );

	case MINUS:
		return(  clocal( block( PVCONV,
			p, bpsize(p->in.left), INT, 0, INT ) ) );
		}

	cerror( "illegal oconvert: %d", p->in.op );

	return(p);
	}

NODE *
ptmatch(p)  register NODE *p; {

	/* makes the operands of p agree; they are
	   either pointers or integers, by this time */
	/* with MINUS, the sizes must be the same */
	/* with COLON, the types must be the same */

	TWORD t1, t2, t;
	int o, d2, d, s2, s;

	o = p->in.op;
	t = t1 = p->in.left->in.type;
	t2 = p->in.right->in.type;
	d = p->in.left->fn.cdim;
	d2 = p->in.right->fn.cdim;
	s = p->in.left->fn.csiz;
	s2 = p->in.right->fn.csiz;

	switch( o ){

	case ASSIGN:
	case RETURN:
	case CAST:
		{  break; }

	case MINUS:
		{  if( psize(p->in.left) != psize(p->in.right) ){
			uerror( "illegal pointer subtraction");
			}
		   break;
		   }
	case COLON:
		{  if( t1 != t2 ) uerror( "illegal types in :");
		   break;
		   }
	default:  /* must work harder: relationals or comparisons */

		if( !ISPTR(t1) ){
			t = t2;
			d = d2;
			s = s2;
			break;
			}
		if( !ISPTR(t2) ){
			break;
			}

		/* both are pointers */
		if( talign(t2,s2) < talign(t,s) ){
			t = t2;
			s = s2;
			}
		break;
		}

	p->in.left = makety( p->in.left, t, d, s );
	p->in.right = makety( p->in.right, t, d, s );
	if( o!=MINUS && !logop(o) ){

		p->in.type = t;
		p->fn.cdim = d;
		p->fn.csiz = s;
		}

	return(clocal(p));
	}

int tdebug = 0;

NODE *
tymatch(p)  register NODE *p; {

	/* satisfy the types of various arithmetic binary ops */

	/* rules are:
D 10
		if assignment, op, type of LHS
E 10
I 10
		if assignment, type of LHS
E 10
		if any float or doubles, make double
		if any longs, make long
		otherwise, make int
		if either operand is unsigned, the result is...
	*/

	register TWORD t1, t2, t, tu;
	register o, u;

	o = p->in.op;

	t1 = p->in.left->in.type;
	t2 = p->in.right->in.type;
	if( (t1==UNDEF || t2==UNDEF) && o!=CAST )
		uerror("void type illegal in expression");

	u = 0;
	if( ISUNSIGNED(t1) ){
		u = 1;
		t1 = DEUNSIGN(t1);
		}
	if( ISUNSIGNED(t2) ){
		u = 1;
		t2 = DEUNSIGN(t2);
		}

	if( ( t1 == CHAR || t1 == SHORT ) && o!= RETURN ) t1 = INT;
	if( t2 == CHAR || t2 == SHORT ) t2 = INT;

D 6
	if( t1==DOUBLE || t1==FLOAT || t2==DOUBLE || t2==FLOAT ) t = DOUBLE;
E 6
I 6
#ifdef SPRECC
	if( t1 == DOUBLE || t2 == DOUBLE )
		t = DOUBLE;
	else if( t1 == FLOAT || t2 == FLOAT )
		t = FLOAT;
#else
	if (t1 == DOUBLE || t1 == FLOAT || t2 == DOUBLE || t2 == FLOAT)
		t = DOUBLE;
#endif
E 6
	else if( t1==LONG || t2==LONG ) t = LONG;
	else t = INT;

I 25
D 30
#ifdef tahoe
D 28
	if( asgop(o) ){
E 28
I 28
	if( asgop(o) )
E 28
#else
E 30
E 25
I 11
D 15
#ifdef tahoe
	if( asgop(o) ){
#else
E 15
E 11
D 10
	if( asgop(o) ){
E 10
I 10
D 28
	if( o == ASSIGN || o == CAST || o == RETURN ){
E 28
I 28
	if( o == ASSIGN || o == CAST || o == RETURN )
E 28
I 25
D 30
#endif
E 30
I 28
	{
E 28
E 25
I 11
D 15
#endif
E 15
E 11
E 10
		tu = p->in.left->in.type;
		t = t1;
		}
	else {
		tu = (u && UNSIGNABLE(t))?ENUNSIGN(t):t;
		}

	/* because expressions have values that are at least as wide
	   as INT or UNSIGNED, the only conversions needed
	   are those involving FLOAT/DOUBLE, and those
	   from LONG to INT and ULONG to UNSIGNED */

I 25
D 30
#ifdef tahoe
	if( t != t1 )
#else
E 30
E 25
I 11
D 15
#ifdef tahoe
	if( t != t1 )
#else
E 15
E 11
D 10
	if( t != t1 ) p->in.left = makety( p->in.left, tu, 0, (int)tu );
E 10
I 10
D 33
	if( t != t1 && ! asgop(o) )
E 33
I 33
	if( (t != t1 || (u && !ISUNSIGNED(p->in.left->in.type))) && ! asgop(o) )
E 33
I 25
D 30
#endif
E 30
E 25
I 11
D 15
#endif
E 15
E 11
		p->in.left = makety( p->in.left, tu, 0, (int)tu );
E 10

D 10
	if( t != t2 || o==CAST ) p->in.right = makety( p->in.right, tu, 0, (int)tu );
E 10
I 10
D 15
	if( t != t2 || o==CAST )
		p->in.right = makety( p->in.right, tu, 0, (int)tu );
E 15
I 15
D 33
	if( t != t2 || o==CAST)
E 33
I 33
	if( t != t2 || (u && !ISUNSIGNED(p->in.right->in.type)) || o==CAST)
E 33
		if ( tu == ENUMTY ) {/* always asgop */
			p->in.right = makety( p->in.right, INT, 0, INT );
			p->in.right->in.type = tu;
			p->in.right->fn.cdim = p->in.left->fn.cdim;
			p->in.right->fn.csiz = p->in.left->fn.csiz;
			}
		else
			p->in.right = makety( p->in.right, tu, 0, (int)tu );
E 15
E 10

	if( asgop(o) ){
		p->in.type = p->in.left->in.type;
		p->fn.cdim = p->in.left->fn.cdim;
		p->fn.csiz = p->in.left->fn.csiz;
		}
	else if( !logop(o) ){
		p->in.type = tu;
		p->fn.cdim = 0;
		p->fn.csiz = t;
		}

# ifndef BUG1
	if( tdebug ) printf( "tymatch(%o): %o %s %o => %o\n",p,t1,opst[o],t2,tu );
# endif

	return(p);
	}

NODE *
makety( p, t, d, s ) register NODE *p; TWORD t; {
	/* make p into type t by inserting a conversion */

	if( p->in.type == ENUMTY && p->in.op == ICON ) econvert(p);
	if( t == p->in.type ){
		p->fn.cdim = d;
		p->fn.csiz = s;
		return( p );
		}

	if( t & TMASK ){
		/* non-simple type */
D 3
		return( block( PCONV, p, NIL, t, d, s ) );
E 3
I 3
D 5
		return( clocal( block( PCONV, p, NIL, t, d, s ) ) );
E 5
I 5
		return( block( PCONV, p, NIL, t, d, s ) );
E 5
E 3
		}

	if( p->in.op == ICON ){
D 6
		if( t==DOUBLE||t==FLOAT ){
E 6
I 6
		if (t == DOUBLE) {
			p->in.op = DCON;
			if (ISUNSIGNED(p->in.type))
D 12
				p->dpn.dval = /* (unsigned CONSZ) */ p->tn.lval;
E 12
I 12
D 15
				p->dpn.dval = (unsigned CONSZ) p->tn.lval;
E 15
I 15
D 22
				p->dpn.dval = /* (unsigned CONSZ) */ p->tn.lval;
E 22
I 22
D 35
				p->dpn.dval = (unsigned CONSZ) p->tn.lval;
E 35
I 35
				p->dpn.dval = (U_CONSZ) p->tn.lval;
E 35
E 22
E 15
E 12
			else
				p->dpn.dval = p->tn.lval;
			p->in.type = p->fn.csiz = t;
			return (clocal(p));
		}
		if (t == FLOAT) {
E 6
			p->in.op = FCON;
			if( ISUNSIGNED(p->in.type) ){
D 6
				p->fpn.dval = /* (unsigned CONSZ) */ p->tn.lval;
E 6
I 6
D 12
				p->fpn.fval = /* (unsigned CONSZ) */ p->tn.lval;
E 12
I 12
D 15
				p->fpn.fval = (unsigned CONSZ) p->tn.lval;
E 15
I 15
D 22
				p->fpn.fval = /* (unsigned CONSZ) */ p->tn.lval;
E 22
I 22
D 35
				p->fpn.fval = (unsigned CONSZ) p->tn.lval;
E 35
I 35
				p->fpn.fval = (U_CONSZ) p->tn.lval;
E 35
E 22
E 15
E 12
E 6
				}
			else {
D 6
				p->fpn.dval = p->tn.lval;
E 6
I 6
				p->fpn.fval = p->tn.lval;
E 6
				}

			p->in.type = p->fn.csiz = t;
			return( clocal(p) );
			}
		}
I 6
	else if (p->in.op == FCON && t == DOUBLE) {
		double db;
E 6

I 6
		p->in.op = DCON;
		db = p->fpn.fval;
		p->dpn.dval = db;
		p->in.type = p->fn.csiz = t;
		return (clocal(p));
	} else if (p->in.op == DCON && t == FLOAT) {
		float fl;

		p->in.op = FCON;
		fl = p->dpn.dval;
#ifdef notdef
		if (fl != p->dpn.dval)
			werror("float conversion loses precision");
#endif
		p->fpn.fval = fl;
		p->in.type = p->fn.csiz = t;
		return (clocal(p));
	}

E 6
D 3
	return( block( SCONV, p, NIL, t, d, s ) );
E 3
I 3
	return( clocal( block( SCONV, p, NIL, t, d, s ) ) );
E 3

	}

NODE *
block( o, l, r, t, d, s ) register NODE *l, *r; TWORD t; {

	register NODE *p;

	p = talloc();
	p->in.op = o;
	p->in.left = l;
	p->in.right = r;
	p->in.type = t;
	p->fn.cdim = d;
	p->fn.csiz = s;
	return(p);
	}

icons(p) register NODE *p; {
	/* if p is an integer constant, return its value */
	int val;

	if( p->in.op != ICON ){
		uerror( "constant expected");
		val = 1;
		}
	else {
		val = p->tn.lval;
		if( val != p->tn.lval ) uerror( "constant too big for cross-compiler" );
		}
	tfree( p );
	return(val);
	}

/* 	the intent of this table is to examine the
	operators, and to check them for
	correctness.

	The table is searched for the op and the
	modified type (where this is one of the
	types INT (includes char and short), LONG,
	DOUBLE (includes FLOAT), and POINTER

	The default action is to make the node type integer

	The actions taken include:
		PUN	  check for puns
		CVTL	  convert the left operand
		CVTR	  convert the right operand
		TYPL	  the type is determined by the left operand
		TYPR	  the type is determined by the right operand
		TYMATCH	  force type of left and right to match, by inserting conversions
		PTMATCH	  like TYMATCH, but for pointers
		LVAL	  left operand must be lval
		CVTO	  convert the op
		NCVT	  do not convert the operands
		OTHER	  handled by code
		NCVTR	  convert the left operand, not the right...

	*/

# define MINT 01  /* integer */
# define MDBI 02   /* integer or double */
# define MSTR 04  /* structure */
# define MPTR 010  /* pointer */
# define MPTI 020  /* pointer or integer */
# define MENU 040 /* enumeration variable or member */
I 9
# define MVOID 0100000 /* void type */
E 9

opact( p )  NODE *p; {

	register mt12, mt1, mt2, o;

D 9
	mt12 = 0;
E 9
I 9
	mt1 = mt2 = mt12 = 0;
E 9

	switch( optype(o=p->in.op) ){

	case BITYPE:
D 9
		mt12=mt2 = moditype( p->in.right->in.type );
E 9
I 9
		mt2 = moditype( p->in.right->in.type );
E 9
	case UTYPE:
D 9
		mt12 &= (mt1 = moditype( p->in.left->in.type ));
E 9
I 9
		mt1 = moditype( p->in.left->in.type );
		break;
E 9

		}

I 9
	if( ((mt1 | mt2) & MVOID) &&
	    o != COMOP &&
I 20
	    o != COLON &&
	    !(o == QUEST && (mt1 & MVOID) == 0) &&
E 20
	    !(o == CAST && (mt1 & MVOID)) ){
		/* if lhs of RETURN is void, grammar will complain */
		if( o != RETURN )
			uerror( "value of void expression used" );
		return( NCVT );
		}
D 20
	mt1 &= ~MVOID;
	mt2 &= ~MVOID;
E 20
	mt12 = mt1 & mt2;

E 9
	switch( o ){

	case NAME :
	case STRING :
	case ICON :
	case FCON :
I 6
	case DCON :
E 6
	case CALL :
	case UNARY CALL:
	case UNARY MUL:
		{  return( OTHER ); }
	case UNARY MINUS:
I 19
		if( mt1 & MENU ) return( 0 );
E 19
		if( mt1 & MDBI ) return( TYPL );
		break;

	case COMPL:
I 19
		if( mt1 & MENU ) return( 0 );
E 19
		if( mt1 & MINT ) return( TYPL );
		break;

	case UNARY AND:
D 36
		{  return( NCVT+OTHER ); }
E 36
I 36
		return( NCVT+OTHER );
E 36
	case INIT:
	case CM:
I 2
		return( 0 );

E 2
	case NOT:
	case CBRANCH:
I 2
		if( mt1 & MSTR ) break;
		return( 0 );

E 2
	case ANDAND:
	case OROR:
I 2
		if( (mt1 & MSTR) || (mt2 & MSTR) ) break;
E 2
		return( 0 );

	case MUL:
	case DIV:
		if( mt12 & MDBI ) return( TYMATCH );
		break;

	case MOD:
	case AND:
	case OR:
	case ER:
		if( mt12 & MINT ) return( TYMATCH );
		break;

	case LS:
	case RS:
D 36
		if( mt12 & MINT ) return( TYMATCH+OTHER );
E 36
I 36
		if( mt12 & MINT ) return( OTHER );
E 36
		break;

	case EQ:
	case NE:
	case LT:
	case LE:
	case GT:
	case GE:
D 19
		if( (mt1&MENU)||(mt2&MENU) ) return( PTMATCH+PUN+NCVT );
		if( mt12 & MDBI ) return( TYMATCH+CVTO );
E 19
I 19
		if( mt12 & MENU ) return( TYMATCH+NCVT+PUN );
		if( mt12 & MDBI ) return( TYMATCH+NCVT+CVTO );
E 19
		else if( mt12 & MPTR ) return( PTMATCH+PUN );
		else if( mt12 & MPTI ) return( PTMATCH+PUN );
		else break;

	case QUEST:
	case COMOP:
		if( mt2&MENU ) return( TYPR+NCVTR );
		return( TYPR );

	case STREF:
		return( NCVTR+OTHER );

	case FORCE:
		return( TYPL );

	case COLON:
D 19
		if( mt12 & MENU ) return( NCVT+PUN+PTMATCH );
		else if( mt12 & MDBI ) return( TYMATCH );
E 19
I 19
		if( mt12 & MENU ) return( NCVT+PUN+TYMATCH );
		else if( mt12 & MDBI ) return( NCVT+TYMATCH );
E 19
		else if( mt12 & MPTR ) return( TYPL+PTMATCH+PUN );
		else if( (mt1&MINT) && (mt2&MPTR) ) return( TYPR+PUN );
		else if( (mt1&MPTR) && (mt2&MINT) ) return( TYPL+PUN );
		else if( mt12 & MSTR ) return( NCVT+TYPL+OTHER );
I 20
		else if( mt12 == MVOID ) return( NCVT+TYPL );
E 20
		break;

	case ASSIGN:
	case RETURN:
		if( mt12 & MSTR ) return( LVAL+NCVT+TYPL+OTHER );
I 15
D 19
		else if( (mt1&MENU)||(mt2&MENU) ) return( LVAL+NCVT+TYPL+PTMATCH+PUN );
E 19
I 19
		else if( mt12 & MENU ) return( LVAL+NCVT+TYPL+TYMATCH+PUN );
E 19
E 15
	case CAST:
D 21
		if(o==CAST && mt1==0)return(TYPL+TYMATCH);
E 21
I 21
		if(o==CAST && mt1==MVOID)return(TYPL+TYMATCH);
E 21
D 15
		if( mt12 & MDBI ) return( TYPL+LVAL+TYMATCH );
		else if( (mt1&MENU)||(mt2&MENU) ) return( LVAL+NCVT+TYPL+PTMATCH+PUN );
E 15
I 15
D 19
		else if( mt12 & MDBI ) return( TYPL+LVAL+TYMATCH );
E 19
I 19
		else if( mt12 & MDBI ) return( TYPL+LVAL+NCVT+TYMATCH );
E 19
E 15
D 8
		else if( mt12 == 0 ) break;
E 8
I 8
D 21
		else if( mt2 == 0 &&
E 21
I 21
		else if( mt2 == MVOID &&
E 21
		        ( p->in.right->in.op == CALL ||
			  p->in.right->in.op == UNARY CALL)) break;
E 8
D 29
		else if( mt1 & MPTR ) return( LVAL+PTMATCH+PUN );
E 29
I 29
		else if( (mt1 & MPTR) && (mt2 & MPTI) )
			return( LVAL+PTMATCH+PUN );
E 29
		else if( mt12 & MPTI ) return( TYPL+LVAL+TYMATCH+PUN );
		break;

	case ASG LS:
	case ASG RS:
		if( mt12 & MINT ) return( TYPL+LVAL+OTHER );
		break;

	case ASG MUL:
	case ASG DIV:
		if( mt12 & MDBI ) return( LVAL+TYMATCH );
		break;

	case ASG MOD:
	case ASG AND:
	case ASG OR:
	case ASG ER:
		if( mt12 & MINT ) return( LVAL+TYMATCH );
		break;

	case ASG PLUS:
	case ASG MINUS:
	case INCR:
	case DECR:
		if( mt12 & MDBI ) return( TYMATCH+LVAL );
		else if( (mt1&MPTR) && (mt2&MINT) ) return( TYPL+LVAL+CVTR );
		break;

	case MINUS:
		if( mt12 & MPTR ) return( CVTO+PTMATCH+PUN );
		if( mt2 & MPTR ) break;
	case PLUS:
		if( mt12 & MDBI ) return( TYMATCH );
		else if( (mt1&MPTR) && (mt2&MINT) ) return( TYPL+CVTR );
		else if( (mt1&MINT) && (mt2&MPTR) ) return( TYPR+CVTL );

		}
D 9
	uerror( "operands of %s have incompatible types", opst[o] );
E 9
I 9
	if( mt12 == MSTR )
		uerror( "%s is not a permitted struct/union operation", opst[o] );
	else
		uerror( "operands of %s have incompatible types", opst[o] );
E 9
	return( NCVT );
	}

moditype( ty ) TWORD ty; {

	switch( ty ){

D 31
	case TVOID:
I 4
		return( MPTR );
E 31
E 4
	case UNDEF:
D 9
		return(0); /* type is void */
E 9
I 9
		return( MVOID );
E 9
	case ENUMTY:
	case MOETY:
D 15
		return( MENU );
E 15
I 15
		return( MENU|MINT|MDBI|MPTI );  /* enums are ints */
E 15

	case STRTY:
	case UNIONTY:
		return( MSTR );

	case CHAR:
	case SHORT:
	case UCHAR:
	case USHORT:
		return( MINT|MPTI|MDBI );
	case UNSIGNED:
	case ULONG:
	case INT:
	case LONG:
		return( MINT|MDBI|MPTI );
	case FLOAT:
	case DOUBLE:
		return( MDBI );
	default:
		return( MPTR|MPTI );

		}
	}

I 14
D 15
int	nsizeof;

static
haseffects(p)
register NODE *	p;
{
	register	o, ty;

	o = p->in.op;
	ty = optype(o);
	if (ty == LTYPE)
		return 0;
	if (asgop(o) || callop(o))
		return 1;
	if (haseffects(p->in.left))
		return 1;
	if (ty == UTYPE)
		return 0;
	return haseffects(p->in.right);
}

E 15
E 14
NODE *
doszof( p )  register NODE *p; {
	/* do sizeof p */
	int i;

I 14
D 15
	--nsizeof;
	if (haseffects(p))
		werror( "operations in object of sizeof are skipped" );
E 15
E 14
	/* whatever is the meaning of this if it is a bitfield? */
	i = tsize( p->in.type, p->fn.cdim, p->fn.csiz )/SZCHAR;

	tfree(p);
	if( i <= 0 ) werror( "sizeof returns 0" );
	return( bcon( i ) );
	}

# ifndef BUG2
eprint( p, down, a, b ) register NODE *p; int *a, *b; {
	register ty;

	*a = *b = down+1;
	while( down > 1 ){
		printf( "\t" );
		down -= 2;
		}
	if( down ) printf( "    " );

	ty = optype( p->in.op );

	printf("%o) %s, ", p, opst[p->in.op] );
	if( ty == LTYPE ){
		printf( CONFMT, p->tn.lval );
		printf( ", %d, ", p->tn.rval );
		}
	tprint( p->in.type );
	printf( ", %d, %d\n", p->fn.cdim, p->fn.csiz );
	}
# endif

I 25
#ifndef PRTDCON
E 25
I 11
D 15
#ifndef PRTDCON
E 15
E 11
prtdcon( p ) register NODE *p; {
D 6
	int i;
E 6
I 6
	int o = p->in.op, i;
E 6

D 6
	if( p->in.op == FCON ){
E 6
I 6
	if( o == DCON || o == FCON ){
E 6
D 27
		locctr( DATA );
E 27
I 27
		(void) locctr( DATA );
E 27
D 6
		defalign( ALDOUBLE );
E 6
I 6
		defalign( o == DCON ? ALDOUBLE : ALFLOAT );
E 6
		deflab( i = getlab() );
D 6
		fincode( p->fpn.dval, SZDOUBLE );
E 6
I 6
		if( o == FCON )
			fincode( p->fpn.fval, SZFLOAT );
		else
			fincode( p->dpn.dval, SZDOUBLE );
E 6
		p->tn.lval = 0;
		p->tn.rval = -i;
D 6
		p->in.type = DOUBLE;
E 6
I 6
		p->in.type = (o == DCON ? DOUBLE : FLOAT);
E 6
		p->in.op = NAME;
		}
	}
I 25
#endif PRTDCON
E 25
I 11
D 15
#endif PRTDCON
E 15
E 11


int edebug = 0;
ecomp( p ) register NODE *p; {
# ifndef BUG2
	if( edebug ) fwalk( p, eprint, 0 );
# endif
	if( !reached ){
		werror( "statement not reached" );
		reached = 1;
		}
	p = optim(p);
	walkf( p, prtdcon );
D 27
	locctr( PROG );
E 27
I 27
	(void) locctr( PROG );
E 27
	ecode( p );
	tfree(p);
	}

# ifdef STDPRTREE
# ifndef ONEPASS

prtree(p) register NODE *p; {

	register struct symtab *q;
	register ty;

# ifdef MYPRTREE
	MYPRTREE(p);  /* local action can be taken here; then return... */
#endif

	ty = optype(p->in.op);

	printf( "%d\t", p->in.op );

	if( ty == LTYPE ) {
		printf( CONFMT, p->tn.lval );
		printf( "\t" );
		}
	if( ty != BITYPE ) {
		if( p->in.op == NAME || p->in.op == ICON ) printf( "0\t" );
		else printf( "%d\t", p->tn.rval );
		}

	printf( "%o\t", p->in.type );

	/* handle special cases */

	switch( p->in.op ){

	case NAME:
	case ICON:
		/* print external name */
		if( p->tn.rval == NONAME ) printf( "\n" );
		else if( p->tn.rval >= 0 ){
			q = &stab[p->tn.rval];
			printf(  "%s\n", exname(q->sname) );
			}
		else { /* label */
			printf( LABFMT, -p->tn.rval );
			}
		break;

	case STARG:
	case STASG:
	case STCALL:
	case UNARY STCALL:
		/* print out size */
		/* use lhs size, in order to avoid hassles with the structure `.' operator */

		/* note: p->in.left not a field... */
		printf( CONFMT, (CONSZ) tsize( STRTY, p->in.left->fn.cdim, p->in.left->fn.csiz ) );
		printf( "\t%d\t\n", talign( STRTY, p->in.left->fn.csiz ) );
		break;

	default:
		printf(  "\n" );
		}

	if( ty != LTYPE ) prtree( p->in.left );
	if( ty == BITYPE ) prtree( p->in.right );

	}

# else

p2tree(p) register NODE *p; {
	register ty;

# ifdef MYP2TREE
	MYP2TREE(p);  /* local action can be taken here; then return... */
# endif

	ty = optype(p->in.op);

	switch( p->in.op ){

	case NAME:
	case ICON:
#ifndef FLEXNAMES
		if( p->tn.rval == NONAME ) p->in.name[0] = '\0';
#else
		if( p->tn.rval == NONAME ) p->in.name = "";
#endif
		else if( p->tn.rval >= 0 ){ /* copy name from exname */
			register char *cp;
D 27
			register i;
E 27
			cp = exname( stab[p->tn.rval].sname );
#ifndef FLEXNAMES
D 27
			for( i=0; i<NCHNAM; ++i ) p->in.name[i] = *cp++;
E 27
I 27
			{
				register i;
				for( i=0; i<NCHNAM; ++i )
					p->in.name[i] = *cp++;
			}
E 27
#else
			p->in.name = tstr(cp);
#endif
			}
#ifndef FLEXNAMES
		else sprintf( p->in.name, LABFMT, -p->tn.rval );
#else
		else {
			char temp[32];
			sprintf( temp, LABFMT, -p->tn.rval );
			p->in.name = tstr(temp);
		}
#endif
		break;

	case STARG:
	case STASG:
	case STCALL:
	case UNARY STCALL:
		/* set up size parameters */
		p->stn.stsize = (tsize(STRTY,p->in.left->fn.cdim,p->in.left->fn.csiz)+SZCHAR-1)/SZCHAR;
		p->stn.stalign = talign(STRTY,p->in.left->fn.csiz)/SZCHAR;
		break;

	case REG:
		rbusy( p->tn.rval, p->in.type );
	default:
#ifndef FLEXNAMES
		p->in.name[0] = '\0';
#else
		p->in.name = "";
#endif
		}

	p->in.rall = NOPREF;

	if( ty != LTYPE ) p2tree( p->in.left );
	if( ty == BITYPE ) p2tree( p->in.right );
	}

# endif
# endif
E 1
