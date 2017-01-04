h14931
s 00000/00020/00447
d D 1.10 87/12/10 20:44:01 donn 10 9
c utah rcsid 1.6 87/11/29 20:31:47: Remove isitfloat() -- this was broken,
c yylex() now handles this properly.  Also delete useless SPRECC ifdef.
e
s 00046/00077/00421
d D 1.9 87/12/10 20:43:53 donn 9 8
c utah rcsid 1.5 87/07/17 19:21:48: (1) Replaced SCONV code in clocal() with
c VAX version.  (2) Deleted the 'float percolation' code in clocal() -- it's
c simply wrong.  (3) Deleted the QUEST case in clocal() which hacks around
c the funny trees created by the deleted 'float percolation'.  (4) Added 'if
c (nerrors) return' to vfdzero().  (5) Changed %X to %lx in incode() and
c vfdzero().  (6) Cleaned up some comments, to make this code more easily
c diffable with the VAX version.
e
s 00006/00001/00492
d D 1.8 87/12/10 20:43:45 donn 8 7
c utah rcsid 1.4 87/05/02 14:58:59: Stop generating code after errors; add
c some lint tidbits.
e
s 00003/00001/00490
d D 1.7 87/12/10 20:43:38 donn 7 6
c utah rcsid 1.3 87/04/17 21:32:02: Oops -- we still want to clobber constant
c conversions...
e
s 00004/00003/00487
d D 1.6 87/12/10 20:43:31 donn 6 5
c utah rcsid 1.2 87/04/17 03:31:22: Let optim2() handle conversion
c optimizations for variables.
e
s 00006/00014/00484
d D 1.5 87/01/09 15:20:40 sam 5 4
c leave SCONV nodes in unless they don't change object's size
e
s 00002/00002/00496
d D 1.4 86/07/27 00:24:29 sam 4 3
c 1.21 release; allow register floats to get a register
e
s 00001/00002/00497
d D 1.3 86/02/12 20:44:23 sam 3 2
c purge as many printf calls as possible
e
s 00079/00060/00420
d D 1.2 86/02/04 22:22:41 sam 2 1
c new include files; don't print leading 0's to cut down on file i/o; 
c distinguish FCON/DCON; steal vax code massaging mixed type constant initializations
e
s 00480/00000/00000
d D 1.1 86/01/11 11:00:53 sam 1 0
c date and time created 86/01/11 11:00:53 by sam
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

/*	this file contains code which is dependent on the target machine */

NODE *
clocal(p) register NODE *p; {

	/* this is called to do local transformations on
	   an expression tree preparitory to its being
	   written out in intermediate code.
	*/

	/* the major essential job is rewriting the
	   automatic variables and arguments in terms of
	   REG and OREG nodes */
	/* conversion ops which are not necessary are also clobbered here */
	/* in addition, any special features (such as rewriting
	   exclusive or) are easily handled here as well */

	register struct symtab *q;
	register NODE *r;
	register int o;
	register int m, ml;

	switch( o = p->in.op ){

	case NAME:
		if( p->tn.rval < 0 ) { /* already processed; ignore... */
			return(p);
			}
		q = &stab[p->tn.rval];
		switch( q->sclass ){

		case AUTO:
		case PARAM:
			/* fake up a structure reference */
			r = block( REG, NIL, NIL, PTR+STRTY, 0, 0 );
			r->tn.lval = 0;
			r->tn.rval = STKREG;
			p = stref( block( STREF, r, p, 0, 0, 0 ) );
			break;

		case ULABEL:
		case LABEL:
		case STATIC:
			if( q->slevel == 0 ) break;
			p->tn.lval = 0;
			p->tn.rval = -q->offset;
			break;

		case REGISTER:
			p->in.op = REG;
			p->tn.lval = 0;
			p->tn.rval = q->offset;
#ifdef REG_CHAR
			m = p->in.type;
			if( m==CHAR || m==SHORT )
				p->in.type = INT;
			else if( m==UCHAR || m==USHORT )
				p->in.type = UNSIGNED;
#endif
			break;

			}
		break;

	case LT:
	case LE:
	case GT:
	case GE:
		if( ISPTR( p->in.left->in.type ) || ISPTR( p->in.right->in.type ) ){
			p->in.op += (ULT-LT);
			}
		break;

	case PCONV:
		/* do pointer conversions for char and longs */
		ml = p->in.left->in.type;
		if( ( ml==CHAR || ml==UCHAR || ml==SHORT || ml==USHORT ) && p->in.left->in.op != ICON ) break;

		/* pointers all have the same representation; the type is inherited */

D 9
	inherit:
E 9
		p->in.left->in.type = p->in.type;
		p->in.left->fn.cdim = p->fn.cdim;
		p->in.left->fn.csiz = p->fn.csiz;
		p->in.op = FREE;
		return( p->in.left );

	case SCONV:
		m = p->in.type;
		ml = p->in.left->in.type;
I 9
		if(m == ml)
			goto clobber;
		o = p->in.left->in.op;
E 9
		if(m == FLOAT || m == DOUBLE) {
D 9
			if(p->in.left->in.op==SCONV &&
E 9
I 9
			if(o==SCONV &&
E 9
D 4
			 (ml == FLOAT || ml == DOUBLE) &&
E 4
I 4
			 ml == DOUBLE &&
E 4
			 p->in.left->in.left->in.type==m) {
				p->in.op = p->in.left->in.op = FREE;
				return(p->in.left->in.left);
D 9
			}
			if(p->in.left->in.op==FCON)
				goto inherit;
E 9
I 9
				}
D 10
#ifndef SPRECC
			if(m == DOUBLE && ml == FLOAT)
				goto clobber;
#endif
E 10
			/* see makety() for constant conversions */
E 9
			break;
D 9
		}
E 9
I 9
			}
E 9
		if(ml == FLOAT || ml == DOUBLE){
D 9
			if (p->in.left->in.op == FCON){
				p->in.left->in.op = FREE;
				p->in.op = ICON;
D 2
				p->tn.lval = p->in.left->fpn.dval;
E 2
I 2
				p->tn.lval = p->in.left->fpn.fval;
E 2
				p->tn.rval = NONAME;
				return(p);
E 9
I 9
			if(o != FCON && o != DCON)
				break;
			ml = ISUNSIGNED(m) ? UNSIGNED : INT; /* LONG? */
			r = block( ICON, (NODE *)NULL, (NODE *)NULL, ml, 0, 0 );
			if( o == FCON )
				r->tn.lval = ml == INT ?
					(int) p->in.left->fpn.fval :
					(unsigned) p->in.left->fpn.fval;
			else
				r->tn.lval = ml == INT ?
					(int) p->in.left->dpn.dval :
					(unsigned) p->in.left->dpn.dval;
			r->tn.rval = NONAME;
			p->in.left->in.op = FREE;
			p->in.left = r;
			o = ICON;
			if( m == ml )
				goto clobber;
E 9
			}
D 9
			break;
		}
E 9
		/* now, look for conversions downwards */

D 5
		if( p->in.left->in.op == ICON ){ /* simulate the conversion here */
E 5
I 5
D 9
		if( p->in.left->in.op == ICON ){	/* simulate the conversion here */
E 9
I 9
		if( o == ICON ){ /* simulate the conversion here */
E 9
E 5
			CONSZ val;
			val = p->in.left->tn.lval;
			switch( m ){
			case CHAR:
				p->in.left->tn.lval = (char) val;
				break;
			case UCHAR:
				p->in.left->tn.lval = val & 0XFF;
				break;
			case USHORT:
				p->in.left->tn.lval = val & 0XFFFFL;
				break;
			case SHORT:
				p->in.left->tn.lval = (short)val;
				break;
			case UNSIGNED:
				p->in.left->tn.lval = val & 0xFFFFFFFFL;
				break;
			case INT:
				p->in.left->tn.lval = (int)val;
				break;
				}
			p->in.left->in.type = m;
D 5
			}
		else {
			/* meaningful ones are conversion of int to char, int to short,
			   and short to char, and unsigned versions thereof */
			if( m==CHAR || m==UCHAR ){
				if( ml!=CHAR && ml!= UCHAR ) break;
				}
			else if( m==SHORT || m==USHORT ){
				if( ml!=CHAR && ml!=UCHAR && ml!=SHORT && ml!=USHORT ) break;
				}
			}

E 5
I 5
D 6
		} else if (tlen(p) == tlen(p->in.left))
E 6
I 6
D 9
		}
#ifdef notdef
		else if (tlen(p) == tlen(p->in.left))
E 6
			goto inherit;
I 7
#else
		else break;
#endif
E 7
D 6
		else
			break;
E 6
E 5
		/* clobber conversion */
E 9
I 9
			}
		else
			break;

	clobber:
E 9
D 5
		if( tlen(p) == tlen(p->in.left) ) goto inherit;
E 5
		p->in.op = FREE;
		return( p->in.left );  /* conversion gets clobbered */
I 6
D 7
#endif
E 7
E 6
I 5
D 9
		break;
E 9
E 5

D 9
	case QUEST:	/* the right side should be COLON */
		if((r = p->in.right)->in.op == SCONV) {
			p->in.right = r->in.left;
			p->in.type = r->in.left->in.type;
			r->in.left = p;
			return(r);
		}
		return(p);

E 9
	case PVCONV:
	case PMCONV:
		if( p->in.right->in.op != ICON ) cerror( "bad conversion", 0);
		p->in.op = FREE;
		return( buildtree( o==PMCONV?MUL:DIV, p->in.left, p->in.right ) );

	case FLD:
		/* make sure that the second pass does not make the
		   descendant of a FLD operator into a doubly indexed OREG */

		if( p->in.left->in.op == UNARY MUL
				&& (r=p->in.left->in.left)->in.op == PCONV)
			if( r->in.left->in.op == PLUS || r->in.left->in.op == MINUS ) 
				if( ISPTR(r->in.type) ) {
					if( ISUNSIGNED(p->in.left->in.type) )
						p->in.left->in.type = UNSIGNED;
					else
						p->in.left->in.type = INT;
				}
		break;
D 2
		case FORTCALL: /* arg must be FLOAT */
			if((r = p->in.right)->in.type != FLOAT)
				p->in.right = clocal(makety(r, FLOAT, 0, FLOAT));
			return(p);
		}
E 2
I 2
	case FORTCALL: /* arg must be FLOAT */
		if((r = p->in.right)->in.type != FLOAT)
			p->in.right = clocal(makety(r, FLOAT, 0, FLOAT));
		return(p);
	}
E 2

D 9
	/* if both sides are FLOAT, so is the op */
	if(optype(o)!=LTYPE && p->in.left->in.type==DOUBLE &&
	 (o==UNARY MINUS || optype(o)==BITYPE && p->in.right->in.type==DOUBLE)) {
		r = p->in.left;
		if(r->in.op==SCONV && r->in.left->in.type==FLOAT) {
			if(optype(o)==BITYPE) {
				r = p->in.right;
				if(r->in.op==SCONV && r->in.left->in.type==FLOAT) {
					r->in.op = FREE;
					p->in.right = r->in.left;
				} else if(r->in.op==FCON)
					r->in.type = FLOAT;
				else
					return(p);
			}
			r = p->in.left;
			p->in.left = r->in.left;
		} else if(optype(o)==BITYPE && r->in.op==FCON) {
			r = p->in.right;
			if(!(r->in.op==SCONV && r->in.left->in.type==FLOAT))
				return(p);
			p->in.right = r->in.left;
			p->in.left->in.type = FLOAT;
		} else
			return(p);
		if(p->in.type==DOUBLE) {
			p->in.type = FLOAT;
			r->in.left = p;
			return(r);
		} else {	/* usually logop */
			r->in.op = FREE;
			return(p);
		}
	}
E 9
	return(p);
D 9
}
E 9
I 9
	}
E 9

I 8
/*ARGSUSED*/
E 8
andable( p ) NODE *p; {
	return(1);  /* all names can have & taken on them */
	}

cendarg(){ /* at the end of the arguments of a ftn, set the automatic offset */
	autooff = AUTOINIT;
	}

cisreg( t ) TWORD t; { /* is an automatic variable of type t OK for a register variable */

	if( t==INT || t==UNSIGNED || t==LONG || t==ULONG	/* tbl */
#ifdef REG_CHAR
		|| t==CHAR || t==UCHAR || t==SHORT || t==USHORT		/* tbl */
#endif
D 4
		|| ISPTR(t)) return (1);			/* wnj */
E 4
I 4
		|| ISPTR(t) || t == FLOAT) return (1);		/* wnj */
E 4
	return(0);
	}

I 8
/*ARGSUSED*/
E 8
NODE *
offcon( off, t, d, s ) OFFSZ off; TWORD t; {

	/* return a node, for structure references, which is suitable for
	   being added to a pointer of type t, in order to be off bits offset
	   into a structure */

	register NODE *p;

	/* t, d, and s are the type, dimension offset, and sizeoffset */
D 8
	/* in general they  are necessary for offcon, but not on H'well */
E 8
I 8
	/* in general they  are necessary for offcon, but not on Tahoe */
E 8

	p = bcon(0);
	p->tn.lval = off/SZCHAR;
	return(p);

	}


static inwd	/* current bit offsed in word */;
static CONSZ word	/* word being built from fields */;

incode( p, sz ) register NODE *p; {

	/* generate initialization code for assigning a constant c
		to a field of width sz */
	/* we assume that the proper alignment has been obtained */
	/* inoff is updated to have the proper final value */
	/* we also assume sz  < SZINT */

I 8
	if(nerrors) return;
E 8
	inwd += sz;
	if(inwd > SZINT) cerror("incode: field > int");
	word |= (p->tn.lval&((1L<<sz)-1)) << (SZINT-inwd);
	inoff += sz;
	if(inoff%SZINT == 0) {
D 2
		printf( "	.long	0x%08X\n", word);
E 2
I 2
D 9
		printf( "	.long	0x%X\n", word);
E 9
I 9
		printf( "	.long	0x%lx\n", word);
E 9
E 2
		word = inwd = 0;
		}
	}

D 2
# ifdef PRTDCON
prtdcon( p ) register NODE *p; {
	int i;

	if( p->in.op == FCON ){
		if(p->fpn.dval == 0) {
			p->in.op = ICON;
			p->tn.rval = NONAME;
			return;
		}
		locctr( DATA );
		defalign( ALDOUBLE );
		deflab( i = getlab() );
# ifndef SFCON
		fincode( p->fpn.dval, p->in.type==DOUBLE ? SZDOUBLE : SZFLOAT);
# else
		p->in.type = fincode( p->fpn.dval, 0 );
# endif
		p->tn.lval = 0;
		p->tn.rval = -i;
		p->in.op = NAME;
		}
	}
# endif

E 2
fincode( d, sz ) double d; register int sz; {
	/*
	 * output code to initialize space of size sz to the value d
	 * the proper alignment has been obtained
D 2
	 * inoff is updated to have the proper final value
	 * this code should be the same for PDP, VAX and Tahoe
	 * SFCON makes use of value to determine type - only where
	 * float<->double conversions are ignored.
E 2
I 2
	 * inoff is updated to have the proper final value.
E 2
	 */

	register struct sh4 {
		unsigned short sh[4];
	} *x;
D 2
# ifdef SFCON
	register int type;
# else
E 2
	float f;

I 8
	if (nerrors) return;
E 8
	if(sz == SZFLOAT) {	/* force rounding */
		f = d;
		d = f;
	}
D 2
# endif
E 2

	x = (struct sh4 *)&d;
	printf("	.long	0x%04x%04x", x->sh[0], x->sh[1]);
D 2
# ifdef SFCON
	if(sz==0)
		if(x->sh[2]==0 && x->sh[3]==0) {
			sz = SZFLOAT;
			type = FLOAT;
		} else {
			sz = SZDOUBLE;
			type = DOUBLE;
		}
# endif
E 2
	if(sz == SZDOUBLE) {
		printf(", 0x%04x%04x", x->sh[2], x->sh[3]);
		printf(" # .double %.17g\n", d);
	} else
		printf(" # .float %.8g\n", d);
	inoff += sz;
D 2
# ifdef SFCON
	return type;
# endif
E 2
	}

cinit( p, sz ) NODE *p; {
I 2
	NODE *l;

	/*
	 * as a favor (?) to people who want to write
	 *     int i = 9600/134.5;
	 * we will, under the proper circumstances, do
D 9
	 * a coersion here.
E 9
I 9
	 * a coercion here.
E 9
	 */
	switch (p->in.type) {
	case INT:
	case UNSIGNED:
		l = p->in.left;
		if (l->in.op != SCONV ||
		    (l->in.left->tn.op != DCON && l->in.left->tn.op != FCON))
			break;
		l->in.op = FREE;
		l = l->in.left;
		l->tn.lval = l->tn.op == DCON ? (long)(l->dpn.dval) :
			(long)(l->fpn.fval);
		l->tn.rval = NONAME;
		l->tn.op = ICON;
		l->tn.type = INT;
		p->in.left = l;
		break;
	}
E 2
D 9
	/* arrange for the initialization of p into a space of
	size sz */
E 9
I 9
	/* arrange for the initialization of p into a space of size sz */
E 9
	/* the proper alignment has been opbtained */
	/* inoff is updated to have the proper final value */
	ecode( p );
	inoff += sz;
	}

vfdzero( n ){ /* define n bits of zeros in a vfd */

	if( n <= 0 ) return;

I 9
	if (nerrors) return;
E 9
	inwd += n;
	inoff += n;
	if( inoff%ALINT ==0 ) {
D 2
		printf( "	.long	0x%08X\n", word );
E 2
I 2
D 9
		printf( "	.long	0x%X\n", word );
E 9
I 9
		printf( "	.long	0x%lx\n", word );
E 9
E 2
		word = inwd = 0;
		}
	}

char *
exname( p ) char *p; {
	/* make a name look like an external name in the local machine */

#ifndef FLEXNAMES
	static char text[NCHNAM+1];
#else
	static char text[BUFSIZ+1];
#endif

	register int i;

	text[0] = '_';
#ifndef FLEXNAMES
D 2
	for( i=1; *p&&i<NCHNAM; ++i ){
E 2
I 2
	for( i=1; *p&&i<NCHNAM; ++i )
E 2
#else
D 2
	for( i=1; *p; ++i ){
E 2
I 2
	for( i=1; *p; ++i )
E 2
#endif
		text[i] = *p++;
D 2
		}
E 2

	text[i] = '\0';
#ifndef FLEXNAMES
	text[NCHNAM] = '\0';  /* truncate */
#endif

	return( text );
	}

D 9
ctype( type )TWORD type;{ /* map types which are not defined on the local machine */
E 9
I 9
ctype( type ) TWORD type;
	{ /* map types which are not defined on the local machine */
E 9
	switch( BTYPE(type) ){

	case LONG:
		MODTYPE(type,INT);
		break;

	case ULONG:
		MODTYPE(type,UNSIGNED);
		}
	return( type );
	}

noinit() { /* curid is a variable which is defined but
	is not initialized (and not a function );
	This routine returns the stroage class for an uninitialized declaration */

	return(EXTERN);

	}

commdec( id ){ /* make a common declaration for id, if reasonable */
	register struct symtab *q;
	OFFSZ off, tsize();

I 8
	if (nerrors) return;
E 8
	q = &stab[id];
	printf( "	.comm	%s,", exname( q->sname ) );
	off = tsize( q->stype, q->dimoff, q->sizoff );
D 3
	printf( "%d" /*CONFMT*/, off/SZCHAR );
	printf( "\n" );
E 3
I 3
	printf( "%d\n" /*CONFMT*/, off/SZCHAR );
E 3
	}

I 2
prtdcon(p)
	register NODE *p;
{
	register int o = p->in.op;
	int i;
E 2

I 2
	if (o != DCON && o != FCON)
		return;
	/*
	 * Clobber constants of value zero so
	 * we can generate more efficient code.
	 */
	if ((o == DCON && p->dpn.dval == 0) ||
	    (o == FCON && p->fpn.fval == 0)) {
		p->in.op = ICON;
		p->tn.rval = NONAME;
		return;
	}
	locctr(DATA);
	defalign(o == DCON ? ALDOUBLE : ALFLOAT);
	deflab(i = getlab());
	if (o == FCON)
		fincode(p->fpn.fval, SZFLOAT);
	else
		fincode(p->dpn.dval, SZDOUBLE);
	p->tn.lval = 0;
	p->tn.rval = -i;
	p->in.type = (o == DCON ? DOUBLE : FLOAT);
	p->in.op = NAME;
}
D 10

E 2
isitfloat( s ) char *s; {
I 2
	union cvt {
		double	d;
		int	n[2];
	} cvt;
E 2
	double atof();
D 2
	dcon = atof(s);
	return( FCON );
E 2
I 2

	/* avoid floating point exception for double -> float conversions */
	dcon = cvt.d = atof(s);
	if( cvt.n[1] == 0 ){
		fcon = dcon;
		return( FCON );
		}
	return( DCON );
E 2
	}
E 10

ecode( p ) NODE *p; {

	/* walk the tree and write out the nodes.. */

	if( nerrors ) return;
	p2tree( p );
	p2compile( p );
	}

#ifndef ONEPASS
tlen(p) NODE *p; 
{
	switch(p->in.type) {
		case CHAR:
		case UCHAR:
			return(1);
			
		case SHORT:
		case USHORT:
D 9
			return(2);
E 9
I 9
			return(SZSHORT/SZCHAR);
E 9
			
		case DOUBLE:
D 9
			return(8);
E 9
I 9
			return(SZDOUBLE/SZCHAR);
E 9
			
		default:
D 9
			return(4);
E 9
I 9
			return(SZINT/SZCHAR);
E 9
		}
	}
#endif
E 1
