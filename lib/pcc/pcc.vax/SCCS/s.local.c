h25131
s 00005/00005/00440
d D 1.17 88/05/11 00:38:19 donn 18 17
c (1) We must adjust inoff even if errors have occurred and we aren't
c generating code for initializations, since error reporting upstream
c depends on it.  (2) Use char size offsets for field references in
c indexed structs since we can't generate code for long indexed OREG
c field trees.  I think the Tahoe compiler did this in the early days.
e
s 00000/00016/00445
d D 1.16 87/12/11 00:25:38 donn 17 16
c utah rcsid 1.10 87/11/26 16:26:36: Delete isitfloat() -- make float
c constants predictable and ANSI compatible.
e
s 00000/00004/00461
d D 1.15 87/12/11 00:25:27 donn 16 15
c utah rcsid 1.9 87/08/24 01:48:41: Preserve FLOAT to DOUBLE conversions --
c on balance this seems to save some trouble down the line.
e
s 00003/00003/00462
d D 1.14 87/12/11 00:25:16 donn 15 14
c utah rcsid 1.8 87/07/17 17:09:10: Cosmetic change to tlen() -- use
c #define'd constants.
e
s 00004/00000/00461
d D 1.13 87/12/11 00:25:08 donn 14 13
c utah rcsid 1.7 87/07/14 20:27:12: A problem with the new clocal conversion
c code -- in double-only floating arithmetic, delete all float to double
c conversions (reclaim and the table will handle them).
e
s 00000/00000/00461
d D 1.12 87/12/11 00:24:58 donn 13 12
c (6) 'word' has type CONSZ; adjusted printf()s accordingly.  (7) Added
c private prtdcon() routine; just like standard one but substitutes INT 0 for
c floating so that the code table can use 'clrd'.
e
s 00080/00049/00381
d D 1.11 87/12/11 00:24:52 donn 12 11
c utah rcsid 1.6 87/07/11 21:50:58: Several fixes/enhancements from Sam
c Leffler's tahoe compiler.  (1) Delete redundant cast() and isitlong()
c functions.  (2) Make argument p to clocal() have class register (speed).
c (3) Use unsigned comparisons with pointers.  (4) Greatly clean up
c conversion code in clocal(); I made some changes of my own here.  (5)
c Pretend fields have INT or UNSIGNED type, not UCHAR or CHAR, in clocal().
e
s 00004/00001/00426
d D 1.10 87/12/11 00:24:42 donn 11 10
c utah rcsid 1.5 86/11/28 21:33:38: Added some ARGSUSED comments.  Perhaps
c isitlong() ought to have just one parameter anyway?  So it goes.
e
s 00004/00000/00423
d D 1.9 87/12/11 00:24:31 donn 10 9
c utah rcsid 1.4 86/08/03 01:00:36: Don't generate code after errors.
e
s 00002/00003/00421
d D 1.8 85/08/23 15:03:17 mckusick 9 8
c update from donn@utah-cs
e
s 00018/00006/00406
d D 1.7 85/04/02 11:50:51 ralph 8 7
c changes for pcc.h; fix isfloat to not get double -> float exceptions.
e
s 00023/00002/00389
d D 1.6 85/03/19 20:26:23 mckusick 7 5
c do coercions for expressions like int i = 9600/1234.5
e
s 00008/00002/00389
d R 1.6 85/02/07 14:22:27 ralph 6 5
c output float constants in hex, lose precision otherwise (from corbett).
e
s 00037/00006/00354
d D 1.5 85/01/18 15:23:28 ralph 5 4
c changes for single precision floats; lint cleanups
e
s 00001/00001/00359
d D 1.4 84/03/15 14:37:14 ralph 4 3
c throw away float <-> double SCONV's so static initializers work.
e
s 00002/00011/00358
d D 1.3 84/03/14 15:41:50 ralph 3 2
c merge f1 and c1; fix type casting conversion bugs.
e
s 00000/00220/00369
d D 1.2 82/12/18 11:36:00 linton 2 1
c added new symbol stuff for dbx, split symbol table dumping 
c off into separate file ("stab.c")
e
s 00589/00000/00000
d D 1.1 82/12/15 13:23:52 linton 1 0
c date and time created 82/12/15 13:23:52 by linton
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
D 8
# include "mfile1"
E 8
I 8
# include "pass1.h"
E 8

/*	this file contains code which is dependent on the target machine */

NODE *
D 12
cast( p, t ) register NODE *p; TWORD t; {
	/* cast node p to type t */
E 12
I 12
clocal(p) register NODE *p; {
E 12

D 12
	p = buildtree( CAST, block( NAME, NIL, NIL, t, 0, (int)t ), p );
	p->in.left->in.op = FREE;
	p->in.op = FREE;
	return( p->in.right );
	}

NODE *
clocal(p) NODE *p; {

E 12
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
D 12
	register o;
	register m, ml;
E 12
I 12
	register int o;
	register int m, ml;
E 12

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
			r->tn.rval = (q->sclass==AUTO?STKREG:ARGREG);
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
			break;

			}
		break;

I 12
	case LT:
	case LE:
	case GT:
	case GE:
		if( ISPTR( p->in.left->in.type ) || ISPTR( p->in.right->in.type ) ){
			p->in.op += (ULT-LT);
			}
		break;

E 12
	case PCONV:
		/* do pointer conversions for char and longs */
		ml = p->in.left->in.type;
		if( ( ml==CHAR || ml==UCHAR || ml==SHORT || ml==USHORT ) && p->in.left->in.op != ICON ) break;

		/* pointers all have the same representation; the type is inherited */

D 5
	inherit:
E 5
		p->in.left->in.type = p->in.type;
		p->in.left->fn.cdim = p->fn.cdim;
		p->in.left->fn.csiz = p->fn.csiz;
		p->in.op = FREE;
		return( p->in.left );

	case SCONV:
D 12
		m = (p->in.type == FLOAT || p->in.type == DOUBLE );
		ml = (p->in.left->in.type == FLOAT || p->in.left->in.type == DOUBLE );
E 12
I 12
		m = p->in.type;
		ml = p->in.left->in.type;
		if(m == ml)
			goto clobber;
E 12
D 5
		if( m != ml ) break;
E 5
I 5
		o = p->in.left->in.op;
D 12
		if( (o == FCON || o == DCON) && ml && !m ) {
			/* float type to int type */
			r = block( ICON, (NODE *)NULL, (NODE *)NULL, INT, 0, 0 );
E 12
I 12
		if(m == FLOAT || m == DOUBLE) {
			if(o==SCONV &&
			 ml == DOUBLE &&
			 p->in.left->in.left->in.type==m) {
				p->in.op = p->in.left->in.op = FREE;
				return(p->in.left->in.left);
				}
I 14
D 16
#ifndef SPRECC
			if(m == DOUBLE && ml == FLOAT)
				goto clobber;
#endif
E 16
E 14
			/* see makety() for constant conversions */
			break;
			}
		if(ml == FLOAT || ml == DOUBLE){
			if(o != FCON && o != DCON)
				break;
			ml = ISUNSIGNED(m) ? UNSIGNED : INT; /* LONG? */
			r = block( ICON, (NODE *)NULL, (NODE *)NULL, ml, 0, 0 );
E 12
			if( o == FCON )
D 12
				r->tn.lval = (int) p->in.left->fpn.fval;
E 12
I 12
				r->tn.lval = ml == INT ?
					(int) p->in.left->fpn.fval :
					(unsigned) p->in.left->fpn.fval;
E 12
			else
D 12
				r->tn.lval = (int) p->in.left->dpn.dval;
E 12
I 12
				r->tn.lval = ml == INT ?
					(int) p->in.left->dpn.dval :
					(unsigned) p->in.left->dpn.dval;
E 12
			r->tn.rval = NONAME;
			p->in.left->in.op = FREE;
			p->in.left = r;
I 12
			o = ICON;
			if( m == ml )
				goto clobber;
E 12
			}
D 12
		else
#ifdef SPRECC
			if ( ml || m )
#else
			if ( ml != m )
#endif
				break;
E 5

E 12
		/* now, look for conversions downwards */

D 12
		m = p->in.type;
		ml = p->in.left->in.type;
		if( p->in.left->in.op == ICON ){ /* simulate the conversion here */
E 12
I 12
		if( o == ICON ){ /* simulate the conversion here */
E 12
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
			}
D 3
		else {
			/* meaningful ones are conversion of int to char, int to short,
			   and short to char, and unsigned version of them */
			if( m==CHAR || m==UCHAR ){
				if( ml!=CHAR && ml!= UCHAR ) break;
				}
			else if( m==SHORT || m==USHORT ){
				if( ml!=CHAR && ml!=UCHAR && ml!=SHORT && ml!=USHORT ) break;
				}
			}
E 3
I 3
D 4
		else
E 4
I 4
D 12
		else if( m != FLOAT && m != DOUBLE )
E 12
I 12
		else
E 12
E 4
			break;
E 3

D 12
		/* clobber conversion */
E 12
I 12
	clobber:
E 12
D 3
		if( tlen(p) == tlen(p->in.left) ) goto inherit;
E 3
		p->in.op = FREE;
		return( p->in.left );  /* conversion gets clobbered */

	case PVCONV:
	case PMCONV:
		if( p->in.right->in.op != ICON ) cerror( "bad conversion", 0);
		p->in.op = FREE;
		return( buildtree( o==PMCONV?MUL:DIV, p->in.left, p->in.right ) );

	case RS:
	case ASG RS:
		/* convert >> to << with negative shift count */
		/* only if type of left operand is not unsigned */

		if( ISUNSIGNED(p->in.left->in.type) ) break;
D 5
		p->in.right = buildtree( UNARY MINUS, p->in.right, NIL );
E 5
I 5
		if( p->in.right->in.op != UNARY MINUS )
			p->in.right = buildtree( UNARY MINUS, p->in.right, NIL );
		else {
			r = p->in.right;
			p->in.right = p->in.right->in.left;
			r->in.op = FREE;
		}
E 5
		if( p->in.op == RS ) p->in.op = LS;
		else p->in.op = ASG LS;
		break;

	case FLD:
		/* make sure that the second pass does not make the
		   descendant of a FLD operator into a doubly indexed OREG */

		if( p->in.left->in.op == UNARY MUL
				&& (r=p->in.left->in.left)->in.op == PCONV)
			if( r->in.left->in.op == PLUS || r->in.left->in.op == MINUS ) 
				if( ISPTR(r->in.type) ) {
					if( ISUNSIGNED(p->in.left->in.type) )
D 12
						p->in.left->in.type = UCHAR;
E 12
I 12
D 18
						p->in.left->in.type = UNSIGNED;
E 18
I 18
						p->in.left->in.type = UCHAR;
E 18
E 12
					else
D 12
						p->in.left->in.type = CHAR;
E 12
I 12
D 18
						p->in.left->in.type = INT;
E 18
I 18
						p->in.left->in.type = CHAR;
E 18
E 12
				}
		break;
		}

	return(p);
	}

I 11
/*ARGSUSED*/
E 11
andable( p ) NODE *p; {
	return(1);  /* all names can have & taken on them */
	}

cendarg(){ /* at the end of the arguments of a ftn, set the automatic offset */
	autooff = AUTOINIT;
	}

cisreg( t ) TWORD t; { /* is an automatic variable of type t OK for a register variable */

#ifdef TRUST_REG_CHAR_AND_REG_SHORT
	if( t==INT || t==UNSIGNED || t==LONG || t==ULONG	/* tbl */
		|| t==CHAR || t==UCHAR || t==SHORT 		/* tbl */
		|| t==USHORT || ISPTR(t)) return(1);		/* tbl */
#else
	if( t==INT || t==UNSIGNED || t==LONG || t==ULONG	/* wnj */
I 5
#ifdef SPRECC
		|| t==FLOAT
#endif
E 5
		|| ISPTR(t)) return (1);			/* wnj */
#endif
	return(0);
	}

I 11
/*ARGSUSED*/
E 11
NODE *
offcon( off, t, d, s ) OFFSZ off; TWORD t; {

	/* return a node, for structure references, which is suitable for
	   being added to a pointer of type t, in order to be off bits offset
	   into a structure */

	register NODE *p;

	/* t, d, and s are the type, dimension offset, and sizeoffset */
D 11
	/* in general they  are necessary for offcon, but not on H'well */
E 11
I 11
	/* in general they  are necessary for offcon, but not on VAX */
E 11

	p = bcon(0);
	p->tn.lval = off/SZCHAR;
	return(p);

	}


static inwd	/* current bit offsed in word */;
D 12
static word	/* word being built from fields */;
E 12
I 12
static CONSZ word	/* word being built from fields */;
E 12

incode( p, sz ) register NODE *p; {

	/* generate initialization code for assigning a constant c
		to a field of width sz */
	/* we assume that the proper alignment has been obtained */
	/* inoff is updated to have the proper final value */
	/* we also assume sz  < SZINT */

I 18
	inoff += sz;
E 18
I 10
D 12
	if (nerrors) return;
E 12
I 12
	if(nerrors) return;
E 12
E 10
	if((sz+inwd) > SZINT) cerror("incode: field > int");
	word |= ((unsigned)(p->tn.lval<<(32-sz))) >> (32-sz-inwd);
	inwd += sz;
D 18
	inoff += sz;
E 18
	if(inoff%SZINT == 0) {
D 12
		printf( "	.long	0x%x\n", word);
E 12
I 12
		printf( "	.long	0x%lx\n", word);
E 12
		word = inwd = 0;
		}
	}

fincode( d, sz ) double d; {
	/* output code to initialize space of size sz to the value d */
	/* the proper alignment has been obtained */
	/* inoff is updated to have the proper final value */
	/* on the target machine, write it out in octal! */


I 10
D 18
	if (nerrors) return;
E 18
I 18
	if(!nerrors)
E 18
E 10
	printf("	%s	0%c%.20e\n", sz == SZDOUBLE ? ".double" : ".float",
		sz == SZDOUBLE ? 'd' : 'f', d);
	inoff += sz;
	}

cinit( p, sz ) NODE *p; {
D 7
	/* arrange for the initialization of p into a space of
	size sz */
E 7
I 7
	NODE *l;

	/*
	 * as a favor (?) to people who want to write
	 *     int i = 9600/134.5;
	 * we will, under the proper circumstances, do
D 12
	 * a coersion here.
E 12
I 12
	 * a coercion here.
E 12
	 */
	switch (p->in.type) {
	case INT:
	case UNSIGNED:
		l = p->in.left;
D 8
		if (l->in.op != SCONV || l->in.left->tn.op != FCON) break;
E 8
I 8
		if (l->in.op != SCONV ||
		    (l->in.left->tn.op != DCON && l->in.left->tn.op != FCON))
			break;
E 8
		l->in.op = FREE;
		l = l->in.left;
D 8
		l->tn.lval = (long)(l->fpn.dval);
E 8
I 8
		l->tn.lval = l->tn.op == DCON ? (long)(l->dpn.dval) :
			(long)(l->fpn.fval);
E 8
		l->tn.rval = NONAME;
		l->tn.op = ICON;
		l->tn.type = INT;
		p->in.left = l;
		break;
	}
	/* arrange for the initialization of p into a space of size sz */
E 7
	/* the proper alignment has been opbtained */
	/* inoff is updated to have the proper final value */
	ecode( p );
	inoff += sz;
	}

vfdzero( n ){ /* define n bits of zeros in a vfd */

	if( n <= 0 ) return;

I 18
	inoff += n;
E 18
I 10
	if (nerrors) return;
E 10
	inwd += n;
D 18
	inoff += n;
E 18
	if( inoff%ALINT ==0 ) {
D 12
		printf( "	.long	0x%x\n", word );
E 12
I 12
		printf( "	.long	0x%lx\n", word );
E 12
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

D 12
	register i;
E 12
I 12
	register int i;
E 12

	text[0] = '_';
#ifndef FLEXNAMES
D 9
	for( i=1; *p&&i<NCHNAM; ++i ){
E 9
I 9
	for( i=1; *p&&i<NCHNAM; ++i )
E 9
#else
D 9
	for( i=1; *p; ++i ){
E 9
I 9
	for( i=1; *p; ++i )
E 9
#endif
		text[i] = *p++;
D 9
		}
E 9

	text[i] = '\0';
#ifndef FLEXNAMES
	text[NCHNAM] = '\0';  /* truncate */
#endif

	return( text );
	}

D 5
ctype( type ){ /* map types which are not defined on the local machine */
E 5
I 5
ctype( type ) TWORD type;
	{ /* map types which are not defined on the local machine */
E 5
	switch( BTYPE(type) ){

	case LONG:
		MODTYPE(type,INT);
		break;

	case ULONG:
		MODTYPE(type,UNSIGNED);
		}
	return( type );
	}

D 5
noinit( t ) { /* curid is a variable which is defined but
E 5
I 5
noinit() { /* curid is a variable which is defined but
E 5
	is not initialized (and not a function );
	This routine returns the stroage class for an uninitialized declaration */

	return(EXTERN);

	}

commdec( id ){ /* make a common declaration for id, if reasonable */
	register struct symtab *q;
	OFFSZ off, tsize();

I 10
	if (nerrors) return;
E 10
	q = &stab[id];
	printf( "	.comm	%s,", exname( q->sname ) );
	off = tsize( q->stype, q->dimoff, q->sizoff );
	printf( CONFMT, off/SZCHAR );
D 12
	printf( "\n" );
E 12
I 12
	putchar( '\n' );
E 12
	}

I 11
D 12
/*ARGSUSED*/
E 11
isitlong( cb, ce ){ /* is lastcon to be long or short */
	/* cb is the first character of the representation, ce the last */
E 12
I 12
prtdcon(p)
	register NODE *p;
{
	register int o = p->in.op;
	int i;
E 12

D 12
	if( ce == 'l' || ce == 'L' ||
		lastcon >= (1L << (SZINT-1) ) ) return (1);
	return(0);
E 12
I 12
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
E 12
	}
D 12

E 12
I 12
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
E 12

D 17
isitfloat( s ) char *s; {
I 8
	union cvt {
		double	d;
		int	n[2];
	} cvt;
E 8
	double atof();
D 8
	dcon = atof(s);
D 5
	return( FCON );
E 5
I 5
	fcon = dcon;
	return( fcon == dcon ? FCON : DCON );
E 8
I 8

	/* avoid floating point exception for double -> float conversions */
	dcon = cvt.d = atof(s);
	if( cvt.n[1] == 0 ){
		fcon = dcon;
		return( FCON );
		}
	return( DCON );
E 8
E 5
	}

E 17
ecode( p ) NODE *p; {

	/* walk the tree and write out the nodes.. */

	if( nerrors ) return;
	p2tree( p );
	p2compile( p );
	}
D 2
	
#include <sys/types.h>
#include <a.out.h>
#include <stab.h>
extern int ddebug;
extern int gdebug;

fixarg(p)
struct symtab *p; {
		pstab(p->sname, N_PSYM);
		if (gdebug) printf("0,%d,%d\n", p->stype, argoff/SZCHAR);
		poffs(p);
}
int	stabLCSYM;

outstab(p)
struct symtab *p; {
	register TWORD ptype;
	register char *pname;
	register char pclass;
	register int poffset;

	if (!gdebug) return;

	ptype = p->stype;
	pname = p->sname;
	pclass = p->sclass;
	poffset = p->offset;

	if (ISFTN(ptype)) {
		return;
	}
	
	switch (pclass) {
	
	case AUTO:
		pstab(pname, N_LSYM);
		printf("0,%d,%d\n", ptype, (-poffset)/SZCHAR);
		poffs(p);
		return;
	
	case EXTDEF:
	case EXTERN:
		pstab(pname, N_GSYM);
		printf("0,%d,0\n", ptype);
		poffs(p);
		return;
			
	case STATIC:
#ifdef LCOMM
		/* stabLCSYM is 1 during nidcl so we can get stab type right */
		pstab(pname, stabLCSYM ? N_LCSYM : N_STSYM);
#else
		pstab(pname, N_STSYM);
#endif
		if (p->slevel > 1) {
			printf("0,%d,L%d\n", ptype, poffset);
		} else {
			printf("0,%d,%s\n", ptype, exname(pname));
		}
		poffs(p);
		return;
	
	case REGISTER:
		pstab(pname, N_RSYM);
		printf("0,%d,%d\n", ptype, poffset);
		poffs(p);
		return;
	
	case MOS:
	case MOU:
		pstab(pname, N_SSYM);
		printf("0,%d,%d\n", ptype, poffset/SZCHAR);
		poffs(p);
		return;
	
	case PARAM:
		/* parameter stab entries are processed in dclargs() */
		return;
	
	default:
#ifndef FLEXNAMES
		if (ddebug) printf("	No .stab for %.8s\n", pname);
#else
		if (ddebug) printf("	No .stab for %s\n", pname);
#endif
		
	}
}

pstab(name, type)
char *name;
int type; {
	register int i;
	register char c;
	if (!gdebug) return;
	/* locctr(PROG);  /* .stabs must appear in .text for c2 */
#ifdef ASSTRINGS
	if ( name[0] == '\0')
		printf("\t.stabn\t");
	else
#ifndef FLEXNAMES
		printf("\t.stabs\t\"%.8s\", ", name);
#else
		printf("\t.stabs\t\"%s\", ", name);
#endif
#else
	printf("	.stab	");
	for(i=0; i<8; i++) 
		if (c = name[i]) printf("'%c,", c);
		else printf("0,");
#endif
	printf("0%o,", type);
}

#ifdef STABDOT
pstabdot(type, value)
	int	type;
	int	value;
{
	if ( ! gdebug) return;
	/* locctr(PROG);  /* .stabs must appear in .text for c2 */
	printf("\t.stabd\t");
	printf("0%o,0,0%o\n",type, value);
}
#endif

poffs(p)
register struct symtab *p; {
	int s;
	if (!gdebug) return;
	if ((s = dimtab[p->sizoff]/SZCHAR) > 1) {
		pstab(p->sname, N_LENG);
		printf("1,0,%d\n", s);
	}
}

extern char NULLNAME[8];
extern int  labelno;
extern int  fdefflag;

psline() {
	static int lastlineno;
	register char *cp, *cq;
	register int i;
	
	if (!gdebug) return;

	cq = ititle;
	cp = ftitle;

	while ( *cq ) if ( *cp++ != *cq++ ) goto neq;
	if ( *cp == '\0' ) goto eq;
	
neq:	for (i=0; i<100; i++)
		ititle[i] = '\0';
	cp = ftitle;
	cq = ititle;
	while ( *cp )  
		*cq++ = *cp++;
	*cq = '\0';
	*--cq = '\0';
#ifndef FLEXNAMES
	for ( cp = ititle+1; *(cp-1); cp += 8 ) {
		pstab(cp, N_SOL);
		if (gdebug) printf("0,0,LL%d\n", labelno);
		}
#else
	pstab(ititle+1, N_SOL);
	if (gdebug) printf("0,0,LL%d\n", labelno);
#endif
	*cq = '"';
	printf("LL%d:\n", labelno++);

eq:	if (lineno == lastlineno) return;
	lastlineno = lineno;

	if (fdefflag) {
#ifdef STABDOT
		pstabdot(N_SLINE, lineno);
#else
		pstab(NULLNAME, N_SLINE);
		printf("0,%d,LL%d\n", lineno, labelno);
		printf("LL%d:\n", labelno++);
#endif
		}
	}
	
plcstab(level) {
	if (!gdebug) return;
#ifdef STABDOT
	pstabdot(N_LBRAC, level);
#else
	pstab(NULLNAME, N_LBRAC);
	printf("0,%d,LL%d\n", level, labelno);
	printf("LL%d:\n", labelno++);
#endif
	}
	
prcstab(level) {
	if (!gdebug) return;
#ifdef STABDOT
	pstabdot(N_RBRAC, level);
#else
	pstab(NULLNAME, N_RBRAC);
	printf("0,%d,LL%d\n", level, labelno);
	printf("LL%d:\n", labelno++);
#endif
	}
	
pfstab(sname) 
char *sname; {
	if (!gdebug) return;
	pstab(sname, N_FUN);
#ifndef FLEXNAMES
	printf("0,%d,_%.7s\n", lineno, sname);
#else
	printf("0,%d,_%s\n", lineno, sname);
#endif
}
E 2

#ifndef ONEPASS
tlen(p) NODE *p; 
{
	switch(p->in.type) {
		case CHAR:
		case UCHAR:
			return(1);
			
		case SHORT:
		case USHORT:
D 15
			return(2);
E 15
I 15
			return(SZSHORT/SZCHAR);
E 15
			
		case DOUBLE:
D 15
			return(8);
E 15
I 15
			return(SZDOUBLE/SZCHAR);
E 15
			
		default:
D 15
			return(4);
E 15
I 15
			return(SZINT/SZCHAR);
E 15
		}
	}
#endif
E 1
