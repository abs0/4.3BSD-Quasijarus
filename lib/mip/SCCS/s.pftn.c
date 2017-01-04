h59174
s 00012/00001/02007
d D 1.28 2011/10/19 05:44:52 msokolov 29 28
c long long support begins with syntax parsing
e
s 00007/00012/02001
d D 1.27 87/12/10 00:31:40 donn 28 27
c utah rcsid 1.20 87/09/21 02:23:15: Code for the relook()/schain hack from
c allegra!jpl which is quite a bit prettier than the old code and works the
c same.
e
s 00004/00000/02009
d D 1.26 87/12/10 00:31:20 donn 27 26
c utah rcsid 1.19 87/07/10 22:45:12: Arthur Olsen's hack to force lint to
c examine initializations.
e
s 00012/00009/01997
d D 1.25 87/12/10 00:31:05 donn 26 25
c utah rcsid 1.18 87/05/18 22:30:36: Fix goof in previous revision which
c screws up when a symbol returned by relook() is the first element in an
c schain.
e
s 00010/00000/01996
d D 1.24 87/12/10 00:30:49 donn 25 24
c utah rcsid 1.17 87/04/30 13:53:40: Prevent 'schain botch' -- if relook()
c succeeds, fix up schain so that it passes through the copy instead of the
c (mishashed) original.
e
s 00004/00000/01992
d D 1.23 87/12/10 00:30:33 donn 24 23
c utah rcsid 1.16 87/02/25 00:16:05: Prevent confusion when introducing a new
c definition of an identifier in an inner scope.  Previously an incomplete
c definition of an external array could get 'adjusted' by the definition of
c an auto array with the same name.
e
s 00002/00001/01990
d D 1.22 87/12/10 00:30:17 donn 23 22
c utah rcsid 1.15 87/02/08 20:23:37: Add typedefs to the set of storage
c classes which may have null storage.
e
s 00003/00001/01988
d D 1.21 87/12/10 00:29:59 donn 22 21
c utah rcsid 1.14 87/01/15 06:57:19: Changed the compiler error in tsize()
c into a normal user error -- you can get this by trying to dereference a
c function pointer in ordinary code.
e
s 00010/00000/01979
d D 1.20 87/12/10 00:29:42 donn 21 20
c utah rcsid 1.13 87/01/15 05:50:53: Added fixinit() routine for recovering
c the initial state after an error.
e
s 00027/00028/01952
d D 1.19 87/12/10 00:29:20 donn 20 19
c utah rcsid 1.12 87/01/15 02:00:24: Made test for missing declared arguments
c in defid() more stringent.  Made some minor lint fixes and touched up a
c couple of comments.
e
s 00014/00004/01966
d D 1.18 87/12/10 00:29:03 donn 19 18
c utah rcsid 1.11 86/11/12 23:17:23: A variation on a suggestion by Ray
c Butterworth -- when an array is not initialized and not external, its
c definition must allocate space.  I also cleaned up the corresponding 'null
c dimension' error for empty dimensions in places other than the last.
c Following Butterworth's suggestion, a lint error was added for an explicit
c dimension which is converted to a pointer in the normal formal argument
c conversion code (contingent on lint's -h flag).
e
s 00002/00001/01968
d D 1.17 87/12/10 00:28:45 donn 18 17
c utah rcsid 1.10 86/08/16 00:01:25: Don't allow addresses (or unloadable
c things) to be placed in bit fields.
e
s 00007/00030/01962
d D 1.16 87/12/10 00:28:18 donn 17 16
c utah rcsid 1.9 86/08/03 01:06:07: Don't generate code after errors.
e
s 00022/00000/01970
d D 1.15 87/05/01 08:53:16 bostic 16 15
c bug report 4.3BSD/lib/60
e
s 00003/00000/01967
d D 1.14 87/04/13 17:19:55 bostic 15 14
c bug report 4.3BSD/usr.bin/44
e
s 00001/00001/01966
d D 1.13 86/10/15 22:04:39 sam 14 13
c additional check for empty stack
e
s 00013/00003/01954
d D 1.12 86/04/21 23:00:22 donn 13 12
c (1) Prevent compiler errors for 'int i = { 1, 2 };' and similar disasters.
c (2) From Carl Sutton (sutton@tektronix) -- Save symbol table 'next' pointer
c in step 2 in clearst() in case relookup() causes 'r' to equal 'p' (resulting
c in '*p' getting clobbered).
e
s 00001/00001/01956
d D 1.11 86/03/12 01:47:14 donn 12 11
c Fix a bug that was confusing lint -- to free a symbol table element,
c set its type to TNULL, not NULL.
e
s 00010/00001/01947
d D 1.10 86/01/08 01:06:55 donn 11 10
c Better error reporting for undefined structures.  You used to get
c 'unknown size' for uninitialized undefined structures and a compiler
c error if you tried to initialize one...
e
s 00064/00064/01884
d D 1.9 85/08/22 19:05:10 mckusick 10 9
c update from donn@utah-cs
e
s 00001/00001/01947
d D 1.8 85/03/19 13:12:35 ralph 9 7
c use common header file for C, Fortran, Pascal.
e
s 00000/00000/01948
d R 1.8 85/03/19 13:09:18 ralph 8 7
c use common header file for C, Fortran, Pascal.
e
s 00002/00002/01946
d D 1.7 85/02/15 08:56:28 ralph 7 6
c don't core dump on "struct { a y; a z; };".
e
s 00013/00005/01935
d D 1.6 85/01/18 16:14:25 ralph 6 5
c changes for single precision floats; lint cleanups
e
s 00007/00003/01933
d D 1.5 84/09/04 12:24:06 ralph 5 4
c fix illegal storage class declarations for parameters.
e
s 00003/00001/01933
d D 1.4 84/03/14 15:30:04 ralph 4 3
c INIT of expression confuses sucomp(). Print uerror here.
e
s 00001/00000/01933
d D 1.3 83/07/15 16:35:17 linton 3 2
c added another FIXDEF for initialized arrays
e
s 00011/00002/01922
d D 1.2 83/07/15 16:10:43 linton 2 1
c added a "FIXDEF" to generate stab information for arrays 
c which were declared with a dimension of 0 the first time around.
e
s 01924/00000/00000
d D 1.1 83/07/15 15:12:37 linton 1 0
c date and time created 83/07/15 15:12:37 by linton
e
u
U
t
T
I 6
#ifndef lint
E 6
I 1
D 29
static char *sccsid ="%W% (Berkeley) %G%";
E 29
I 29
static char *sccsid ="%W% (Berkeley) %E%";
E 29
I 6
#endif lint

E 6
D 9
# include "mfile1"
E 9
I 9
# include "pass1.h"
E 9

unsigned int offsz;

I 10
struct symtab *schain[MAXSCOPES];	/* sym chains for clearst */
int chaintop;				/* highest active entry */

E 10
struct instk {
	int in_sz;   /* size of array element */
	int in_x;    /* current index for structure member in structure initializations */
	int in_n;    /* number of initializations seen */
	int in_s;    /* sizoff */
	int in_d;    /* dimoff */
	TWORD in_t;    /* type */
	int in_id;   /* stab index */
	int in_fl;   /* flag which says if this level is controlled by {} */
	OFFSZ in_off;  /* offset of the beginning of this level */
	}
instack[10],
*pstk;

	/* defines used for getting things off of the initialization stack */


struct symtab *relook();


int ddebug = 0;

struct symtab * mknonuniq();

D 10
defid( q, class )  NODE *q; {
E 10
I 10
defid( q, class ) register NODE *q; register int class; {
E 10
	register struct symtab *p;
	int idp;
D 10
	TWORD type;
E 10
I 10
	register TWORD type;
E 10
	TWORD stp;
D 10
	int scl;
E 10
I 10
	register int scl;
E 10
	int dsym, ddef;
	int slev, temp;
I 2
	int changed;
E 2

	if( q == NIL ) return;  /* an error was detected */

	if( q < node || q >= &node[TREESZ] ) cerror( "defid call" );

	idp = q->tn.rval;

	if( idp < 0 ) cerror( "tyreduce" );
	p = &stab[idp];
I 16
D 17
#ifdef LINT
	if (pflag) {
		register int	i;
E 17

D 17
#ifndef FLEXNAMES
		for (i = 0; i < 8; ++i)
#else /* FLEXNAMES */
		for (i = 0; ; ++i)
#endif /* FLEXNAMES */
			if (p->sname[i] == '\0')
				break;
			else if (p->sname[i] == '$') {
#ifndef FLEXNAMES
				werror( "nonportable identifier (uses $): %.8s",
#else /* FLEXNAMES */
				werror( "nonportable identifier (uses $): %s",
#endif /* FLEXNAMES */
					p->sname);
				break;
			}
	}
#endif /* LINT */
E 16

E 17
# ifndef BUG1
	if( ddebug ){
#ifndef FLEXNAMES
		printf( "defid( %.8s (%d), ", p->sname, idp );
#else
		printf( "defid( %s (%d), ", p->sname, idp );
#endif
		tprint( q->in.type );
		printf( ", %s, (%d,%d) ), level %d\n", scnames(class), q->fn.cdim, q->fn.csiz, blevel );
		}
# endif

	fixtype( q, class );

	type = q->in.type;
	class = fixclass( class, type );

	stp = p->stype;
	slev = p->slevel;

# ifndef BUG1
	if( ddebug ){
		printf( "	modified to " );
		tprint( type );
		printf( ", %s\n", scnames(class) );
		printf( "	previous def'n: " );
		tprint( stp );
		printf( ", %s, (%d,%d) ), level %d\n", scnames(p->sclass), p->dimoff, p->sizoff, slev );
		}
# endif

	if( stp == FTN && p->sclass == SNULL )goto enter;
D 20
		/* name encountered as function, not yet defined */
	if( stp == UNDEF|| stp == FARG ){
		if( blevel==1 && stp!=FARG ) switch( class ){
E 20
I 20
	if( blevel==1 && stp!=FARG ) switch( class ){
E 20

		default:
#ifndef FLEXNAMES
			if(!(class&FIELD)) uerror( "declared argument %.8s is missing", p->sname );
#else
			if(!(class&FIELD)) uerror( "declared argument %s is missing", p->sname );
#endif
		case MOS:
		case STNAME:
		case MOU:
		case UNAME:
		case MOE:
		case ENAME:
		case TYPEDEF:
			;
			}
D 20
		goto enter;
		}
E 20
I 20
	if( stp == UNDEF|| stp == FARG ) goto enter;
E 20

	if( type != stp ) goto mismatch;
I 24
	if( blevel > slev && (class == AUTO || class == REGISTER) )
		/* new scope */
		goto mismatch;

E 24
	/* test (and possibly adjust) dimensions */
	dsym = p->dimoff;
	ddef = q->fn.cdim;
I 2
	changed = 0;
E 2
	for( temp=type; temp&TMASK; temp = DECREF(temp) ){
		if( ISARY(temp) ){
D 2
			if( dimtab[dsym] == 0 ) dimtab[dsym] = dimtab[ddef];
			else if( dimtab[ddef]!=0 && dimtab[dsym] != dimtab[ddef] ){
E 2
I 2
			if (dimtab[dsym] == 0) {
				dimtab[dsym] = dimtab[ddef];
				changed = 1;
				}
			else if (dimtab[ddef]!=0&&dimtab[dsym]!=dimtab[ddef]) {
E 2
				goto mismatch;
				}
			++dsym;
			++ddef;
			}
I 2
		}

	if (changed) {
		FIXDEF(p);
E 2
		}

	/* check that redeclarations are to the same structure */
	if( (temp==STRTY||temp==UNIONTY||temp==ENUMTY) && p->sizoff != q->fn.csiz
		 && class!=STNAME && class!=UNAME && class!=ENAME ){
		goto mismatch;
		}

	scl = ( p->sclass );

# ifndef BUG1
	if( ddebug ){
		printf( "	previous class: %s\n", scnames(scl) );
		}
# endif

	if( class&FIELD ){
		/* redefinition */
		if( !falloc( p, class&FLDSIZ, 1, NIL ) ) {
			/* successful allocation */
			psave( idp );
			return;
			}
		/* blew it: resume at end of switch... */
		}

	else switch( class ){

	case EXTERN:
		switch( scl ){
		case STATIC:
		case USTATIC:
			if( slev==0 ) return;
			break;
		case EXTDEF:
		case EXTERN:
		case FORTRAN:
		case UFORTRAN:
			return;
			}
		break;

	case STATIC:
		if( scl==USTATIC || (scl==EXTERN && blevel==0) ){
			p->sclass = STATIC;
			if( ISFTN(type) ) curftn = idp;
			return;
			}
		break;

	case USTATIC:
		if( scl==STATIC || scl==USTATIC ) return;
		break;

	case LABEL:
		if( scl == ULABEL ){
			p->sclass = LABEL;
			deflab( p->offset );
			return;
			}
		break;

	case TYPEDEF:
		if( scl == class ) return;
		break;

	case UFORTRAN:
		if( scl == UFORTRAN || scl == FORTRAN ) return;
		break;

	case FORTRAN:
		if( scl == UFORTRAN ){
			p->sclass = FORTRAN;
			if( ISFTN(type) ) curftn = idp;
			return;
			}
		break;

	case MOU:
	case MOS:
		if( scl == class ) {
			if( oalloc( p, &strucoff ) ) break;
			if( class == MOU ) strucoff = 0;
			psave( idp );
			return;
			}
		break;

	case MOE:
		if( scl == class ){
			if( p->offset!= strucoff++ ) break;
			psave( idp );
			}
		break;

	case EXTDEF:
		if( scl == EXTERN ) {
			p->sclass = EXTDEF;
			if( ISFTN(type) ) curftn = idp;
			return;
			}
		break;

	case STNAME:
	case UNAME:
	case ENAME:
		if( scl != class ) break;
		if( dimtab[p->sizoff] == 0 ) return;  /* previous entry just a mention */
		break;

	case ULABEL:
		if( scl == LABEL || scl == ULABEL ) return;
	case PARAM:
	case AUTO:
	case REGISTER:
		;  /* mismatch.. */

		}

	mismatch:
	/* allow nonunique structure/union member names */

	if( class==MOU || class==MOS || class & FIELD ){/* make a new entry */
D 10
		int * memp;
E 10
I 10
		register int *memp;
E 10
		p->sflags |= SNONUNIQ;  /* old entry is nonunique */
		/* determine if name has occurred in this structure/union */
D 7
		for( memp = &paramstk[paramno-1];
E 7
I 7
		if (paramno > 0) for( memp = &paramstk[paramno-1];
E 7
			/* while */ *memp>=0 && stab[*memp].sclass != STNAME
				&& stab[*memp].sclass != UNAME;
D 7
			/* iterate */ --memp){ char * cname, * oname;
E 7
I 7
			/* iterate */ --memp){ char *cname, *oname;
E 7
D 20
			if( stab[*memp].sflags & SNONUNIQ ){int k;
E 20
I 20
			if( stab[*memp].sflags & SNONUNIQ ){
E 20
				cname=p->sname;
				oname=stab[*memp].sname;
#ifndef FLEXNAMES
D 20
				for(k=1; k<=NCHNAM; ++k){
E 20
I 20
				for(temp=1; temp<=NCHNAM; ++temp){
E 20
					if(*cname++ != *oname)goto diff;
					if(!*oname++)break;
					}
#else
				if (cname != oname) goto diff;
#endif
				uerror("redeclaration of: %s",p->sname);
				break;
				diff: continue;
				}
			}
		p = mknonuniq( &idp ); /* update p and idp to new entry */
		goto enter;
		}
	if( blevel > slev && class != EXTERN && class != FORTRAN &&
		class != UFORTRAN && !( class == LABEL && slev >= 2 ) ){
		q->tn.rval = idp = hide( p );
		p = &stab[idp];
		goto enter;
		}
#ifndef FLEXNAMES
	uerror( "redeclaration of %.8s", p->sname );
#else
	uerror( "redeclaration of %s", p->sname );
#endif
	if( class==EXTDEF && ISFTN(type) ) curftn = idp;
	return;

	enter:  /* make a new entry */

# ifndef BUG1
	if( ddebug ) printf( "	new entry made\n" );
# endif
	if( type == UNDEF ) uerror("void type for %s",p->sname);
	p->stype = type;
	p->sclass = class;
	p->slevel = blevel;
	p->offset = NOOFFSET;
	p->suse = lineno;
	if( class == STNAME || class == UNAME || class == ENAME ) {
		p->sizoff = curdim;
		dstash( 0 );  /* size */
		dstash( -1 ); /* index to members of str or union */
		dstash( ALSTRUCT );  /* alignment */
		dstash( idp );
		}
	else {
		switch( BTYPE(type) ){
		case STRTY:
		case UNIONTY:
		case ENUMTY:
			p->sizoff = q->fn.csiz;
			break;
		default:
			p->sizoff = BTYPE(type);
			}
		}

	/* copy dimensions */

	p->dimoff = q->fn.cdim;

	/* allocate offsets */
	if( class&FIELD ){
D 20
		falloc( p, class&FLDSIZ, 0, NIL );  /* new entry */
E 20
I 20
		(void) falloc( p, class&FLDSIZ, 0, NIL );  /* new entry */
E 20
		psave( idp );
		}
	else switch( class ){

	case AUTO:
D 20
		oalloc( p, &autooff );
E 20
I 20
		(void) oalloc( p, &autooff );
E 20
		break;
	case STATIC:
	case EXTDEF:
		p->offset = getlab();
		if( ISFTN(type) ) curftn = idp;
		break;
	case ULABEL:
	case LABEL:
		p->offset = getlab();
		p->slevel = 2;
		if( class == LABEL ){
D 20
			locctr( PROG );
E 20
I 20
			(void) locctr( PROG );
E 20
			deflab( p->offset );
			}
		break;

	case EXTERN:
	case UFORTRAN:
	case FORTRAN:
		p->offset = getlab();
		p->slevel = 0;
		break;
	case MOU:
	case MOS:
D 20
		oalloc( p, &strucoff );
E 20
I 20
		(void) oalloc( p, &strucoff );
E 20
		if( class == MOU ) strucoff = 0;
		psave( idp );
		break;

	case MOE:
		p->offset = strucoff++;
		psave( idp );
		break;
	case REGISTER:
		p->offset = regvar--;
		if( blevel == 1 ) p->sflags |= SSET;
		if( regvar < minrvar ) minrvar = regvar;
		break;
		}

I 10
	{
		register int l = p->slevel;

		if( l >= MAXSCOPES )
			cerror( "scopes nested too deep" );

		p->snext = schain[l];
		schain[l] = p;
		if( l >= chaintop )
			chaintop = l + 1;
		}

E 10
	/* user-supplied routine to fix up new definitions */

	FIXDEF(p);

# ifndef BUG1
	if( ddebug ) printf( "	dimoff, sizoff, offset: %d, %d, %d\n", p->dimoff, p->sizoff, p->offset );
# endif

	}

psave( i ){
	if( paramno >= PARAMSZ ){
		cerror( "parameter stack overflow");
		}
	paramstk[ paramno++ ] = i;
	}

ftnend(){ /* end of function */
D 17
	if( retlab != NOLAB ){ /* inside a real function */
E 17
I 17
	if( retlab != NOLAB && nerrors == 0 ){ /* inside a real function */
E 17
		efcode();
		}
	checkst(0);
	retstat = 0;
	tcheck();
	curclass = SNULL;
	brklab = contlab = retlab = NOLAB;
	flostat = 0;
	if( nerrors == 0 ){
		if( psavbc != & asavbc[0] ) cerror("bcsave error");
		if( paramno != 0 ) cerror("parameter reset error");
		if( swx != 0 ) cerror( "switch error");
		}
	psavbc = &asavbc[0];
	paramno = 0;
	autooff = AUTOINIT;
	minrvar = regvar = MAXRVAR;
	reached = 1;
	swx = 0;
	swp = swtab;
D 20
	locctr(DATA);
E 20
I 20
	(void) locctr(DATA);
E 20
	}

dclargs(){
	register i, j;
	register struct symtab *p;
	register NODE *q;
	argoff = ARGINIT;
# ifndef BUG1
	if( ddebug > 2) printf("dclargs()\n");
# endif
	for( i=0; i<paramno; ++i ){
		if( (j = paramstk[i]) < 0 ) continue;
		p = &stab[j];
# ifndef BUG1
		if( ddebug > 2 ){
			printf("\t%s (%d) ",p->sname, j);
			tprint(p->stype);
			printf("\n");
			}
# endif
		if( p->stype == FARG ) {
			q = block(FREE,NIL,NIL,INT,0,INT);
			q->tn.rval = j;
			defid( q, PARAM );
			}
		FIXARG(p); /* local arg hook, eg. for sym. debugger */
		oalloc( p, &argoff );  /* always set aside space, even for register arguments */
		}
	cendarg();
D 20
	locctr(PROG);
E 20
I 20
	(void) locctr(PROG);
E 20
	defalign(ALINT);
	ftnno = getlab();
	bfcode( paramstk, paramno );
	paramno = 0;
	}

NODE *
rstruct( idn, soru ){ /* reference to a structure or union, with no definition */
	register struct symtab *p;
	register NODE *q;
	p = &stab[idn];
	switch( p->stype ){

	case UNDEF:
	def:
		q = block( FREE, NIL, NIL, 0, 0, 0 );
		q->tn.rval = idn;
		q->in.type = (soru&INSTRUCT) ? STRTY : ( (soru&INUNION) ? UNIONTY : ENUMTY );
		defid( q, (soru&INSTRUCT) ? STNAME : ( (soru&INUNION) ? UNAME : ENAME ) );
		break;

	case STRTY:
		if( soru & INSTRUCT ) break;
		goto def;

	case UNIONTY:
		if( soru & INUNION ) break;
		goto def;

	case ENUMTY:
		if( !(soru&(INUNION|INSTRUCT)) ) break;
		goto def;

		}
	stwart = instruct;
	return( mkty( p->stype, 0, p->sizoff ) );
	}

moedef( idn ){
	register NODE *q;

	q = block( FREE, NIL, NIL, MOETY, 0, 0 );
	q->tn.rval = idn;
	if( idn>=0 ) defid( q, MOE );
	}

bstruct( idn, soru ){ /* begining of structure or union declaration */
	register NODE *q;

	psave( instruct );
	psave( curclass );
	psave( strucoff );
	strucoff = 0;
	instruct = soru;
	q = block( FREE, NIL, NIL, 0, 0, 0 );
	q->tn.rval = idn;
	if( instruct==INSTRUCT ){
		curclass = MOS;
		q->in.type = STRTY;
		if( idn >= 0 ) defid( q, STNAME );
		}
	else if( instruct == INUNION ) {
		curclass = MOU;
		q->in.type = UNIONTY;
		if( idn >= 0 ) defid( q, UNAME );
		}
	else { /* enum */
		curclass = MOE;
		q->in.type = ENUMTY;
		if( idn >= 0 ) defid( q, ENAME );
		}
	psave( idn = q->tn.rval );
	/* the "real" definition is where the members are seen */
	if ( idn >= 0 ) stab[idn].suse = lineno;
	return( paramno-4 );
	}

NODE *
dclstruct( oparam ){
	register struct symtab *p;
	register i, al, sa, j, sz, szindex;
	register TWORD temp;
	register high, low;

D 20
	/* paramstack contains:
		paramstack[ oparam ] = previous instruct
		paramstack[ oparam+1 ] = previous class
E 20
I 20
	/* paramstk contains:
		paramstk[ oparam ] = previous instruct
		paramstk[ oparam+1 ] = previous class
E 20
		paramstk[ oparam+2 ] = previous strucoff
		paramstk[ oparam+3 ] = structure name

		paramstk[ oparam+4, ... ]  = member stab indices

		*/


	if( (i=paramstk[oparam+3]) < 0 ){
		szindex = curdim;
		dstash( 0 );  /* size */
		dstash( -1 );  /* index to member names */
		dstash( ALSTRUCT );  /* alignment */
		dstash( -lineno );	/* name of structure */
		}
	else {
		szindex = stab[i].sizoff;
		}

# ifndef BUG1
	if( ddebug ){
#ifndef FLEXNAMES
		printf( "dclstruct( %.8s ), szindex = %d\n", (i>=0)? stab[i].sname : "??", szindex );
#else
		printf( "dclstruct( %s ), szindex = %d\n", (i>=0)? stab[i].sname : "??", szindex );
#endif
		}
# endif
	temp = (instruct&INSTRUCT)?STRTY:((instruct&INUNION)?UNIONTY:ENUMTY);
	stwart = instruct = paramstk[ oparam ];
	curclass = paramstk[ oparam+1 ];
	dimtab[ szindex+1 ] = curdim;
	al = ALSTRUCT;

	high = low = 0;

	for( i = oparam+4;  i< paramno; ++i ){
		dstash( j=paramstk[i] );
		if( j<0 || j>= SYMTSZ ) cerror( "gummy structure member" );
		p = &stab[j];
		if( temp == ENUMTY ){
			if( p->offset < low ) low = p->offset;
			if( p->offset > high ) high = p->offset;
			p->sizoff = szindex;
			continue;
			}
		sa = talign( p->stype, p->sizoff );
		if( p->sclass & FIELD ){
			sz = p->sclass&FLDSIZ;
			}
		else {
			sz = tsize( p->stype, p->dimoff, p->sizoff );
			}
		if( sz == 0 ){
#ifndef FLEXNAMES
			werror( "illegal zero sized structure member: %.8s", p->sname );
#else
			werror( "illegal zero sized structure member: %s", p->sname );
#endif
			}
		if( sz > strucoff ) strucoff = sz;  /* for use with unions */
		SETOFF( al, sa );
		/* set al, the alignment, to the lcm of the alignments of the members */
		}
	dstash( -1 );  /* endmarker */
	SETOFF( strucoff, al );

	if( temp == ENUMTY ){
		register TWORD ty;

# ifdef ENUMSIZE
		ty = ENUMSIZE(high,low);
# else
		if( (char)high == high && (char)low == low ) ty = ctype( CHAR );
		else if( (short)high == high && (short)low == low ) ty = ctype( SHORT );
		else ty = ctype(INT);
#endif
		strucoff = tsize( ty, 0, (int)ty );
		dimtab[ szindex+2 ] = al = talign( ty, (int)ty );
		}

	if( strucoff == 0 ) uerror( "zero sized structure" );
	dimtab[ szindex ] = strucoff;
	dimtab[ szindex+2 ] = al;
	dimtab[ szindex+3 ] = paramstk[ oparam+3 ];  /* name index */

	FIXSTRUCT( szindex, oparam ); /* local hook, eg. for sym debugger */
# ifndef BUG1
	if( ddebug>1 ){
		printf( "\tdimtab[%d,%d,%d] = %d,%d,%d\n", szindex,szindex+1,szindex+2,
				dimtab[szindex],dimtab[szindex+1],dimtab[szindex+2] );
		for( i = dimtab[szindex+1]; dimtab[i] >= 0; ++i ){
#ifndef FLEXNAMES
			printf( "\tmember %.8s(%d)\n", stab[dimtab[i]].sname, dimtab[i] );
#else
			printf( "\tmember %s(%d)\n", stab[dimtab[i]].sname, dimtab[i] );
#endif
			}
		}
# endif

	strucoff = paramstk[ oparam+2 ];
	paramno = oparam;

	return( mkty( temp, 0, szindex ) );
	}

	/* VARARGS */
yyerror( s ) char *s; { /* error printing routine in parser */

	uerror( s );

	}

yyaccpt(){
	ftnend();
	}

ftnarg( idn ) {
	switch( stab[idn].stype ){

	case UNDEF:
		/* this parameter, entered at scan */
		break;
	case FARG:
#ifndef FLEXNAMES
		uerror("redeclaration of formal parameter, %.8s",
#else
		uerror("redeclaration of formal parameter, %s",
#endif
			stab[idn].sname);
		/* fall thru */
	case FTN:
		/* the name of this function matches parm */
		/* fall thru */
	default:
		idn = hide( &stab[idn]);
		break;
	case TNULL:
		/* unused entry, fill it */
		;
		}
	stab[idn].stype = FARG;
	stab[idn].sclass = PARAM;
	psave( idn );
	}

talign( ty, s) register unsigned ty; register s; {
	/* compute the alignment of an object with type ty, sizeoff index s */

	register i;
	if( s<0 && ty!=INT && ty!=CHAR && ty!=SHORT && ty!=UNSIGNED && ty!=UCHAR && ty!=USHORT 
#ifdef LONGFIELDS
		&& ty!=LONG && ty!=ULONG
#endif
					){
		return( fldal( ty ) );
		}

	for( i=0; i<=(SZINT-BTSHIFT-1); i+=TSHIFT ){
		switch( (ty>>i)&TMASK ){

		case FTN:
			cerror( "compiler takes alignment of function");
		case PTR:
			return( ALPOINT );
		case ARY:
			continue;
		case 0:
			break;
			}
		}

	switch( BTYPE(ty) ){

	case UNIONTY:
	case ENUMTY:
	case STRTY:
		return( (unsigned int) dimtab[ s+2 ] );
	case CHAR:
	case UCHAR:
		return( ALCHAR );
	case FLOAT:
		return( ALFLOAT );
	case DOUBLE:
		return( ALDOUBLE );
	case LONG:
	case ULONG:
		return( ALLONG );
	case SHORT:
	case USHORT:
		return( ALSHORT );
	default:
		return( ALINT );
		}
	}

OFFSZ
tsize( ty, d, s )  TWORD ty; {
	/* compute the size associated with type ty,
	    dimoff d, and sizoff s */
	/* BETTER NOT BE CALLED WHEN t, d, and s REFER TO A BIT FIELD... */

	int i;
	OFFSZ mult;

	mult = 1;

	for( i=0; i<=(SZINT-BTSHIFT-1); i+=TSHIFT ){
		switch( (ty>>i)&TMASK ){

		case FTN:
D 22
			cerror( "compiler takes size of function");
E 22
I 22
			/* cerror( "compiler takes size of function"); */
			uerror( "can't take size of function" );
			return( SZCHAR );
E 22
		case PTR:
			return( SZPOINT * mult );
		case ARY:
			mult *= (unsigned int) dimtab[ d++ ];
			continue;
		case 0:
			break;

			}
		}

	if( dimtab[s]==0 ) {
D 11
		uerror( "unknown size");
E 11
I 11
		if( ty == STRTY )
			uerror( "undefined structure" );
		else
			uerror( "unknown size");
E 11
		return( SZINT );
		}
	return( (unsigned int) dimtab[ s ] * mult );
	}

inforce( n ) OFFSZ n; {  /* force inoff to have the value n */
	/* inoff is updated to have the value n */
	OFFSZ wb;
	register rest;
	/* rest is used to do a lot of conversion to ints... */

	if( inoff == n ) return;
	if( inoff > n ) {
		cerror( "initialization alignment error");
		}

	wb = inoff;
	SETOFF( wb, SZINT );

	/* wb now has the next higher word boundary */

	if( wb >= n ){ /* in the same word */
		rest = n - inoff;
		vfdzero( rest );
		return;
		}

	/* otherwise, extend inoff to be word aligned */

	rest = wb - inoff;
	vfdzero( rest );

	/* now, skip full words until near to n */

	rest = (n-inoff)/SZINT;
	zecode( rest );

	/* now, the remainder of the last word */

	rest = n-inoff;
	vfdzero( rest );
	if( inoff != n ) cerror( "inoff error");

	}

vfdalign( n ){ /* make inoff have the offset the next alignment of n */
	OFFSZ m;

	m = inoff;
	SETOFF( m, n );
	inforce( m );
	}


int idebug = 0;

int ibseen = 0;  /* the number of } constructions which have been filled */

I 13
int ifull = 0; /* 1 if all initializers have been seen */

E 13
int iclass;  /* storage class of thing being initialized */

int ilocctr = 0;  /* location counter for current initialization */

beginit(curid){
	/* beginning of initilization; set location ctr and set type */
	register struct symtab *p;

# ifndef BUG1
	if( idebug >= 3 ) printf( "beginit(), curid = %d\n", curid );
# endif

	p = &stab[curid];

	iclass = p->sclass;
	if( curclass == EXTERN || curclass == FORTRAN ) iclass = EXTERN;
	switch( iclass ){

	case UNAME:
	case EXTERN:
		return;
	case AUTO:
	case REGISTER:
		break;
	case EXTDEF:
	case STATIC:
		ilocctr = ISARY(p->stype)?ADATA:DATA;
D 17
		locctr( ilocctr );
		defalign( talign( p->stype, p->sizoff ) );
		defnam( p );
E 17
I 17
		if( nerrors == 0 ){
D 20
			locctr( ilocctr );
E 20
I 20
			(void) locctr( ilocctr );
E 20
			defalign( talign( p->stype, p->sizoff ) );
			defnam( p );
			}
E 17

		}

	inoff = 0;
	ibseen = 0;
I 13
	ifull = 0;
E 13

	pstk = 0;

	instk( curid, p->stype, p->dimoff, p->sizoff, inoff );

	}

instk( id, t, d, s, off ) OFFSZ off; TWORD t; {
	/* make a new entry on the parameter stack to initialize id */

	register struct symtab *p;

	for(;;){
# ifndef BUG1
		if( idebug ) printf( "instk((%d, %o,%d,%d, %d)\n", id, t, d, s, off );
# endif

		/* save information on the stack */

		if( !pstk ) pstk = instack;
		else ++pstk;

		pstk->in_fl = 0;	/* { flag */
		pstk->in_id =  id ;
		pstk->in_t =  t ;
		pstk->in_d =  d ;
		pstk->in_s =  s ;
		pstk->in_n = 0;  /* number seen */
		pstk->in_x =  t==STRTY ?dimtab[s+1] : 0 ;
		pstk->in_off =  off;   /* offset at the beginning of this element */
		/* if t is an array, DECREF(t) can't be a field */
		/* INS_sz has size of array elements, and -size for fields */
		if( ISARY(t) ){
			pstk->in_sz = tsize( DECREF(t), d+1, s );
			}
		else if( stab[id].sclass & FIELD ){
			pstk->in_sz = - ( stab[id].sclass & FLDSIZ );
			}
		else {
			pstk->in_sz = 0;
			}

		if( (iclass==AUTO || iclass == REGISTER ) &&
			(ISARY(t) || t==STRTY) ) uerror( "no automatic aggregate initialization" );

		/* now, if this is not a scalar, put on another element */

		if( ISARY(t) ){
			t = DECREF(t);
			++d;
			continue;
			}
		else if( t == STRTY ){
I 11
			if( dimtab[pstk->in_s] == 0 ){
				uerror( "can't initialize undefined structure" );
				iclass = -1;
				return;
				}
E 11
			id = dimtab[pstk->in_x];
			p = &stab[id];
			if( p->sclass != MOS && !(p->sclass&FIELD) ) cerror( "insane structure member list" );
			t = p->stype;
			d = p->dimoff;
			s = p->sizoff;
			off += p->offset;
			continue;
			}
		else return;
		}
	}

NODE *
getstr(){ /* decide if the string is external or an initializer, and get the contents accordingly */

	register l, temp;
	register NODE *p;

	if( (iclass==EXTDEF||iclass==STATIC) && (pstk->in_t == CHAR || pstk->in_t == UCHAR) &&
			pstk!=instack && ISARY( pstk[-1].in_t ) ){
		/* treat "abc" as { 'a', 'b', 'c', 0 } */
		strflg = 1;
		ilbrace();  /* simulate { */
		inforce( pstk->in_off );
		/* if the array is inflexible (not top level), pass in the size and
			be prepared to throw away unwanted initializers */
		lxstr((pstk-1)!=instack?dimtab[(pstk-1)->in_d]:0);  /* get the contents */
		irbrace();  /* simulate } */
		return( NIL );
		}
	else { /* make a label, and get the contents and stash them away */
		if( iclass != SNULL ){ /* initializing */
			/* fill out previous word, to permit pointer */
			vfdalign( ALPOINT );
			}
		temp = locctr( blevel==0?ISTRNG:STRNG ); /* set up location counter */
		deflab( l = getlab() );
		strflg = 0;
		lxstr(0); /* get the contents */
D 20
		locctr( blevel==0?ilocctr:temp );
E 20
I 20
		(void) locctr( blevel==0?ilocctr:temp );
E 20
		p = buildtree( STRING, NIL, NIL );
		p->tn.rval = -l;
		return(p);
		}
	}

putbyte( v ){ /* simulate byte v appearing in a list of integer values */
	register NODE *p;
	p = bcon(v);
	incode( p, SZCHAR );
	tfree( p );
	gotscal();
	}

endinit(){
	register TWORD t;
	register d, s, n, d1;

# ifndef BUG1
	if( idebug ) printf( "endinit(), inoff = %d\n", inoff );
# endif

	switch( iclass ){

	case EXTERN:
	case AUTO:
	case REGISTER:
I 11
	case -1:
E 11
		return;
		}

	pstk = instack;

	t = pstk->in_t;
	d = pstk->in_d;
	s = pstk->in_s;
	n = pstk->in_n;

	if( ISARY(t) ){
		d1 = dimtab[d];

		vfdalign( pstk->in_sz );  /* fill out part of the last element, if needed */
		n = inoff/pstk->in_sz;  /* real number of initializers */
		if( d1 >= n ){
			/* once again, t is an array, so no fields */
			inforce( tsize( t, d, s ) );
			n = d1;
			}
		if( d1!=0 && d1!=n ) uerror( "too many initializers");
		if( n==0 ) werror( "empty array declaration");
		dimtab[d] = n;
I 3
		if( d1==0 ) FIXDEF(&stab[pstk->in_id]);
E 3
		}

	else if( t == STRTY || t == UNIONTY ){
		/* clearly not fields either */
		inforce( tsize( t, d, s ) );
		}
	else if( n > 1 ) uerror( "bad scalar initialization");
	/* this will never be called with a field element... */
	else inforce( tsize(t,d,s) );

	paramno = 0;
	vfdalign( AL_INIT );
	inoff = 0;
	iclass = SNULL;

	}

I 21
fixinit(){
	/* called from the grammar if we must punt during initialization */
	/* stolen from endinit() */
	pstk = instack;
	paramno = 0;
	vfdalign( AL_INIT );
	inoff = 0;
	iclass = SNULL;
	}

E 21
doinit( p ) register NODE *p; {

	/* take care of generating a value for the initializer p */
	/* inoff has the current offset (last bit written)
		in the current word being generated */

	register sz, d, s;
	register TWORD t;
I 6
	int o;
E 6

	/* note: size of an individual initializer is assumed to fit into an int */

D 14
	if( iclass < 0 ) goto leave;
E 14
I 14
D 17
	if( iclass < 0 || pstk == 0 ) goto leave;
E 17
I 17
	if( iclass < 0 ) goto leave;
E 17
E 14
	if( iclass == EXTERN || iclass == UNAME ){
		uerror( "cannot initialize extern or union" );
		iclass = -1;
		goto leave;
		}

	if( iclass == AUTO || iclass == REGISTER ){
		/* do the initialization and get out, without regard 
		    for filing out the variable with zeros, etc. */
		bccode();
		idname = pstk->in_id;
		p = buildtree( ASSIGN, buildtree( NAME, NIL, NIL ), p );
		ecomp(p);
		return;
		}

	if( p == NIL ) return;  /* for throwing away strings that have been turned into lists */

I 13
	if( ifull ){
		uerror( "too many initializers" );
		iclass = -1;
		goto leave;
		}
E 13
	if( ibseen ){
		uerror( "} expected");
		goto leave;
		}

# ifndef BUG1
	if( idebug > 1 ) printf( "doinit(%o)\n", p );
# endif

	t = pstk->in_t;  /* type required */
	d = pstk->in_d;
	s = pstk->in_s;
	if( pstk->in_sz < 0 ){  /* bit field */
		sz = -pstk->in_sz;
		}
	else {
		sz = tsize( t, d, s );
		}

	inforce( pstk->in_off );

	p = buildtree( ASSIGN, block( NAME, NIL,NIL, t, d, s ), p );
I 27
#ifdef LINT
	/* force lint to treat this like an assignment */
	ecode(p);
#endif
E 27
I 15
D 17
#ifdef LINT
	ecode(p);
#endif
E 17
E 15
	p->in.left->in.op = FREE;
	p->in.left = p->in.right;
	p->in.right = NIL;
	p->in.left = optim( p->in.left );
D 6
	if( p->in.left->in.op == UNARY AND ){
		p->in.left->in.op = FREE;
E 6
I 6
	o = p->in.left->in.op;
	if( o == UNARY AND ){
		o = p->in.left->in.op = FREE;
E 6
		p->in.left = p->in.left->in.left;
		}
	p->in.op = INIT;

	if( sz < SZINT ){ /* special case: bit fields, etc. */
D 6
		if( p->in.left->in.op != ICON ) uerror( "illegal initialization" );
E 6
I 6
D 18
		if( o != ICON ) uerror( "illegal initialization" );
E 18
I 18
		if( o != ICON || p->in.left->tn.rval != NONAME )
			uerror( "illegal initialization" );
E 18
E 6
		else incode( p->in.left, sz );
		}
D 6
	else if( p->in.left->in.op == FCON ){
		fincode( p->in.left->fpn.dval, sz );
E 6
I 6
	else if( o == FCON ){
		fincode( p->in.left->fpn.fval, sz );
		}
	else if( o == DCON ){
		fincode( p->in.left->dpn.dval, sz );
E 6
		}
	else {
D 4
		cinit( optim(p), sz );
E 4
I 4
		p = optim(p);
		if( p->in.left->in.op != ICON ) uerror( "illegal initialization" );
		else cinit( p, sz );
E 4
		}

	gotscal();

	leave:
	tfree(p);
	}

gotscal(){
	register t, ix;
	register n, id;
	struct symtab *p;
	OFFSZ temp;

	for( ; pstk > instack; ) {

		if( pstk->in_fl ) ++ibseen;

		--pstk;
		
		t = pstk->in_t;

		if( t == STRTY ){
			ix = ++pstk->in_x;
			if( (id=dimtab[ix]) < 0 ) continue;

			/* otherwise, put next element on the stack */

			p = &stab[id];
			instk( id, p->stype, p->dimoff, p->sizoff, p->offset+pstk->in_off );
			return;
			}
		else if( ISARY(t) ){
			n = ++pstk->in_n;
			if( n >= dimtab[pstk->in_d] && pstk > instack ) continue;

			/* put the new element onto the stack */

			temp = pstk->in_sz;
			instk( pstk->in_id, (TWORD)DECREF(pstk->in_t), pstk->in_d+1, pstk->in_s,
				pstk->in_off+n*temp );
			return;
			}

		}
D 13

E 13
I 13
	ifull = 1;
E 13
	}

ilbrace(){ /* process an initializer's left brace */
	register t;
	struct instk *temp;

	temp = pstk;

	for( ; pstk > instack; --pstk ){

		t = pstk->in_t;
		if( t != STRTY && !ISARY(t) ) continue; /* not an aggregate */
		if( pstk->in_fl ){ /* already associated with a { */
			if( pstk->in_n ) uerror( "illegal {");
			continue;
			}

		/* we have one ... */
		pstk->in_fl = 1;
		break;
		}

	/* cannot find one */
	/* ignore such right braces */

	pstk = temp;
	}

irbrace(){
	/* called when a '}' is seen */

# ifndef BUG1
	if( idebug ) printf( "irbrace(): paramno = %d on entry\n", paramno );
# endif

	if( ibseen ) {
		--ibseen;
		return;
		}

	for( ; pstk > instack; --pstk ){
		if( !pstk->in_fl ) continue;

		/* we have one now */

		pstk->in_fl = 0;  /* cancel { */
		gotscal();  /* take it away... */
		return;
		}

	/* these right braces match ignored left braces: throw out */
I 13
	ifull = 1;
E 13

	}

upoff( size, alignment, poff ) register alignment, *poff; {
	/* update the offset pointed to by poff; return the
	/* offset of a value of size `size', alignment `alignment',
	/* given that off is increasing */

	register off;

	off = *poff;
	SETOFF( off, alignment );
	if( (offsz-off) <  size ){
		if( instruct!=INSTRUCT )cerror("too many local variables");
		else cerror("Structure too large");
		}
	*poff = off+size;
	return( off );
	}

oalloc( p, poff ) register struct symtab *p; register *poff; {
	/* allocate p with offset *poff, and update *poff */
	register al, off, tsz;
	int noff;

	al = talign( p->stype, p->sizoff );
	noff = off = *poff;
	tsz = tsize( p->stype, p->dimoff, p->sizoff );
#ifdef BACKAUTO
	if( p->sclass == AUTO ){
		if( (offsz-off) < tsz ) cerror("too many local variables");
		noff = off + tsz;
		SETOFF( noff, al );
		off = -noff;
		}
	else
#endif
		if( p->sclass == PARAM && ( tsz < SZINT ) ){
			off = upoff( SZINT, ALINT, &noff );
# ifndef RTOLBYTES
			off = noff - tsz;
#endif
			}
		else
		{
		off = upoff( tsz, al, &noff );
		}

	if( p->sclass != REGISTER ){ /* in case we are allocating stack space for register arguments */
		if( p->offset == NOOFFSET ) p->offset = off;
		else if( off != p->offset ) return(1);
		}

	*poff = noff;
	return(0);
	}

falloc( p, w, new, pty )  register struct symtab *p; NODE *pty; {
	/* allocate a field of width w */
	/* new is 0 if new entry, 1 if redefinition, -1 if alignment */

	register al,sz,type;

	type = (new<0)? pty->in.type : p->stype;

	/* this must be fixed to use the current type in alignments */
	switch( new<0?pty->in.type:p->stype ){

	case ENUMTY:
		{
			int s;
			s = new<0 ? pty->fn.csiz : p->sizoff;
			al = dimtab[s+2];
			sz = dimtab[s];
			break;
			}

	case CHAR:
	case UCHAR:
		al = ALCHAR;
		sz = SZCHAR;
		break;

	case SHORT:
	case USHORT:
		al = ALSHORT;
		sz = SZSHORT;
		break;

	case INT:
	case UNSIGNED:
		al = ALINT;
		sz = SZINT;
		break;
#ifdef LONGFIELDS

	case LONG:
	case ULONG:
		al = ALLONG;
		sz = SZLONG;
		break;
#endif

	default:
		if( new < 0 ) {
			uerror( "illegal field type" );
			al = ALINT;
			}
		else {
			al = fldal( p->stype );
			sz =SZINT;
			}
		}

	if( w > sz ) {
		uerror( "field too big");
		w = sz;
		}

	if( w == 0 ){ /* align only */
		SETOFF( strucoff, al );
		if( new >= 0 ) uerror( "zero size field");
		return(0);
		}

	if( strucoff%al + w > sz ) SETOFF( strucoff, al );
	if( new < 0 ) {
		if( (offsz-strucoff) < w )
			cerror("structure too large");
		strucoff += w;  /* we know it will fit */
		return(0);
		}

	/* establish the field */

	if( new == 1 ) { /* previous definition */
		if( p->offset != strucoff || p->sclass != (FIELD|w) ) return(1);
		}
	p->offset = strucoff;
	if( (offsz-strucoff) < w ) cerror("structure too large");
	strucoff += w;
	p->stype = type;
	fldty( p );
	return(0);
	}

nidcl( p ) NODE *p; { /* handle unitialized declarations */
	/* assumed to be not functions */
	register class;
	register commflag;  /* flag for labelled common declarations */

	commflag = 0;

	/* compute class */
	if( (class=curclass) == SNULL ){
		if( blevel > 1 ) class = AUTO;
		else if( blevel != 0 || instruct ) cerror( "nidcl error" );
		else { /* blevel = 0 */
			class = noinit();
			if( class == EXTERN ) commflag = 1;
			}
		}
#ifdef LCOMM
D 20
	/* hack so stab will come at as LCSYM rather than STSYM */
E 20
I 20
	/* hack so stab will come out as LCSYM rather than STSYM */
E 20
	if (class == STATIC) {
		extern int stabLCSYM;
		stabLCSYM = 1;
	}
#endif

	defid( p, class );

I 19
	/* if an array is not initialized, no empty dimension */
D 23
	if( class!=EXTERN && ISARY(p->in.type) && dimtab[p->fn.cdim]==0 )
E 23
I 23
	if( class!=EXTERN && class!=TYPEDEF &&
	    ISARY(p->in.type) && dimtab[p->fn.cdim]==0 )
E 23
		uerror("null storage definition");

E 19
#ifndef LCOMM
D 10
	if( class==EXTDEF || class==STATIC ){
E 10
I 10
	if( class==EXTDEF || class==STATIC )
E 10
#else
	if (class==STATIC) {
		register struct symtab *s = &stab[p->tn.rval];
		extern int stabLCSYM;
		int sz = tsize(s->stype, s->dimoff, s->sizoff)/SZCHAR;
		
		stabLCSYM = 0;
		if (sz % sizeof (int))
			sz += sizeof (int) - (sz % sizeof (int));
		if (s->slevel > 1)
			printf("	.lcomm	L%d,%d\n", s->offset, sz);
		else
			printf("	.lcomm	%s,%d\n", exname(s->sname), sz);
D 10
	}else if (class == EXTDEF) {
E 10
I 10
	}else if (class == EXTDEF)
E 10
#endif
I 10
		{
E 10
		/* simulate initialization by 0 */
		beginit(p->tn.rval);
		endinit();
		}
	if( commflag ) commdec( p->tn.rval );
	}

TWORD
types( t1, t2, t3 ) TWORD t1, t2, t3; {
	/* return a basic type from basic types t1, t2, and t3 */

	TWORD t[3], noun, adj, unsg;
	register i;
I 29
	int longlong = 0;
E 29

	t[0] = t1;
	t[1] = t2;
	t[2] = t3;

	unsg = INT;  /* INT or UNSIGNED */
	noun = UNDEF;  /* INT, CHAR, or FLOAT */
	adj = INT;  /* INT, LONG, or SHORT */

	for( i=0; i<3; ++i ){
		switch( t[i] ){

		default:
		bad:
			uerror( "illegal type combination" );
			return( INT );

		case UNDEF:
			continue;

		case UNSIGNED:
			if( unsg != INT ) goto bad;
			unsg = UNSIGNED;
			continue;

		case LONG:
I 29
			if( adj == LONG ){
				longlong = 1;
				continue;
				}
			/* FALL THRU */
E 29
		case SHORT:
			if( adj != INT ) goto bad;
			adj = t[i];
			continue;

		case INT:
		case CHAR:
		case FLOAT:
			if( noun != UNDEF ) goto bad;
			noun = t[i];
			continue;
			}
		}

	/* now, construct final type */
	if( noun == UNDEF ) noun = INT;
	else if( noun == FLOAT ){
		if( unsg != INT || adj == SHORT ) goto bad;
		return( adj==LONG ? DOUBLE : FLOAT );
		}
	else if( noun == CHAR && adj != INT ) goto bad;

	/* now, noun is INT or CHAR */
	if( adj != INT ) noun = adj;
I 29
#ifdef LONGLONG
	if( noun == LONG && !longlong ) noun = INT;
#else
	if( longlong ) uerror( "this machine has no long long int support" );
#endif
E 29
	if( unsg == UNSIGNED ) return( noun + (UNSIGNED-INT) );
	else return( noun );
	}

NODE *
tymerge( typ, idp ) NODE *typ, *idp; {
	/* merge type typ with identifier idp  */

	register unsigned t;
	register i;
	extern int eprint();

	if( typ->in.op != TYPE ) cerror( "tymerge: arg 1" );
	if(idp == NIL ) return( NIL );

# ifndef BUG1
	if( ddebug > 2 ) fwalk( idp, eprint, 0 );
# endif

	idp->in.type = typ->in.type;
	idp->fn.cdim = curdim;
	tyreduce( idp );
	idp->fn.csiz = typ->fn.csiz;

	for( t=typ->in.type, i=typ->fn.cdim; t&TMASK; t = DECREF(t) ){
		if( ISARY(t) ) dstash( dimtab[i++] );
		}

	/* now idp is a single node: fix up type */

	idp->in.type = ctype( idp->in.type );

	if( (t = BTYPE(idp->in.type)) != STRTY && t != UNIONTY && t != ENUMTY ){
		idp->fn.csiz = t;  /* in case ctype has rewritten things */
		}

	return( idp );
	}

tyreduce( p ) register NODE *p; {

	/* build a type, and stash away dimensions, from a parse tree of the declaration */
	/* the type is build top down, the dimensions bottom up */
	register o, temp;
	register unsigned t;

	o = p->in.op;
	p->in.op = FREE;

	if( o == NAME ) return;

	t = INCREF( p->in.type );
	if( o == UNARY CALL ) t += (FTN-PTR);
	else if( o == LB ){
		t += (ARY-PTR);
		temp = p->in.right->tn.lval;
		p->in.right->in.op = FREE;
D 19
		if( ( temp == 0 ) & ( p->in.left->tn.op == LB ) )
			uerror( "Null dimension" );
E 19
I 19
		if( temp == 0 && p->in.left->tn.op == LB )
			uerror( "null dimension" );
E 19
		}

	p->in.left->in.type = t;
	tyreduce( p->in.left );

	if( o == LB ) dstash( temp );

	p->tn.rval = p->in.left->tn.rval;
	p->in.type = p->in.left->in.type;

	}

fixtype( p, class ) register NODE *p; {
	register unsigned t, type;
	register mod1, mod2;
	/* fix up the types, and check for legality */

	if( (type = p->in.type) == UNDEF ) return;
	if( mod2 = (type&TMASK) ){
		t = DECREF(type);
		while( mod1=mod2, mod2 = (t&TMASK) ){
			if( mod1 == ARY && mod2 == FTN ){
				uerror( "array of functions is illegal" );
				type = 0;
				}
			else if( mod1 == FTN && ( mod2 == ARY || mod2 == FTN ) ){
				uerror( "function returns illegal type" );
				type = 0;
				}
			t = DECREF(t);
			}
		}

	/* detect function arguments, watching out for structure declarations */
D 19
	/* for example, beware of f(x) struct [ int a[10]; } *x; { ... } */
E 19
I 19
	/* for example, beware of f(x) struct { int a[10]; } *x; { ... } */
E 19
	/* the danger is that "a" will be converted to a pointer */

D 19
	if( class==SNULL && blevel==1 && !(instruct&(INSTRUCT|INUNION)) ) class = PARAM;
E 19
I 19
	if( class==SNULL && blevel==1 && !(instruct&(INSTRUCT|INUNION)) )
		class = PARAM;
E 19
	if( class == PARAM || ( class==REGISTER && blevel==1 ) ){
		if( type == FLOAT ) type = DOUBLE;
		else if( ISARY(type) ){
I 19
#ifdef LINT
			if( hflag && dimtab[p->fn.cdim]!=0 )
				werror("array[%d] type changed to pointer",
					dimtab[p->fn.cdim]);
#endif
E 19
			++p->fn.cdim;
			type += (PTR-ARY);
			}
		else if( ISFTN(type) ){
			werror( "a function is declared as an argument" );
			type = INCREF(type);
			}

		}

	if( instruct && ISFTN(type) ){
		uerror( "function illegal in structure or union" );
		type = INCREF(type);
		}
	p->in.type = type;
	}

uclass( class ) register class; {
	/* give undefined version of class */
	if( class == SNULL ) return( EXTERN );
	else if( class == STATIC ) return( USTATIC );
	else if( class == FORTRAN ) return( UFORTRAN );
	else return( class );
	}

fixclass( class, type ) TWORD type; {

	/* first, fix null class */

	if( class == SNULL ){
		if( instruct&INSTRUCT ) class = MOS;
		else if( instruct&INUNION ) class = MOU;
		else if( blevel == 0 ) class = EXTDEF;
		else if( blevel == 1 ) class = PARAM;
		else class = AUTO;

		}

	/* now, do general checking */

	if( ISFTN( type ) ){
		switch( class ) {
		default:
			uerror( "function has illegal storage class" );
		case AUTO:
			class = EXTERN;
		case EXTERN:
		case EXTDEF:
		case FORTRAN:
		case TYPEDEF:
		case STATIC:
		case UFORTRAN:
		case USTATIC:
			;
			}
		}

	if( class&FIELD ){
		if( !(instruct&INSTRUCT) ) uerror( "illegal use of field" );
		return( class );
		}

	switch( class ){

	case MOU:
		if( !(instruct&INUNION) ) uerror( "illegal class" );
		return( class );

	case MOS:
		if( !(instruct&INSTRUCT) ) uerror( "illegal class" );
		return( class );

	case MOE:
		if( instruct & (INSTRUCT|INUNION) ) uerror( "illegal class" );
		return( class );

	case REGISTER:
		if( blevel == 0 ) uerror( "illegal register declaration" );
		else if( regvar >= MINRVAR && cisreg( type ) ) return( class );
		if( blevel == 1 ) return( PARAM );
		else return( AUTO );

	case AUTO:
	case LABEL:
	case ULABEL:
		if( blevel < 2 ) uerror( "illegal class" );
		return( class );

	case PARAM:
		if( blevel != 1 ) uerror( "illegal class" );
		return( class );

	case UFORTRAN:
	case FORTRAN:
# ifdef NOFORTRAN
			NOFORTRAN;    /* a condition which can regulate the FORTRAN usage */
# endif
		if( !ISFTN(type) ) uerror( "fortran declaration must apply to function" );
		else {
			type = DECREF(type);
			if( ISFTN(type) || ISARY(type) || ISPTR(type) ) {
				uerror( "fortran function has wrong type" );
				}
			}
D 5
	case STNAME:
	case UNAME:
	case ENAME:
E 5
	case EXTERN:
	case STATIC:
	case EXTDEF:
	case TYPEDEF:
	case USTATIC:
I 5
		if( blevel == 1 ){
			uerror( "illegal class" );
			return( PARAM );
			}
	case STNAME:
	case UNAME:
	case ENAME:
E 5
		return( class );

	default:
		cerror( "illegal class: %d", class );
		/* NOTREACHED */

		}
	}

struct symtab *
mknonuniq(idindex) int *idindex; {/* locate a symbol table entry for */
	/* an occurrence of a nonunique structure member name */
	/* or field */
	register i;
	register struct symtab * sp;
D 20
	char *p,*q;
E 20
I 20
	char *q;
E 20

	sp = & stab[ i= *idindex ]; /* position search at old entry */
	while( sp->stype != TNULL ){ /* locate unused entry */
		if( ++i >= SYMTSZ ){/* wrap around symbol table */
			i = 0;
			sp = stab;
			}
		else ++sp;
		if( i == *idindex ) cerror("Symbol table full");
		}
	sp->sflags = SNONUNIQ | SMOS;
D 20
	p = sp->sname;
E 20
	q = stab[*idindex].sname; /* old entry name */
#ifdef FLEXNAMES
	sp->sname = stab[*idindex].sname;
#endif
# ifndef BUG1
	if( ddebug ){
		printf("\tnonunique entry for %s from %d to %d\n",
			q, *idindex, i );
		}
# endif
	*idindex = i;
#ifndef FLEXNAMES
D 20
	for( i=1; i<=NCHNAM; ++i ){ /* copy name */
		if( *p++ = *q /* assign */ ) ++q;
E 20
I 20
	{
		char *p = sp->sname;
		for( i=1; i<=NCHNAM; ++i ) /* copy name */
			if( *p++ = *q /* assign */ ) ++q;
E 20
		}
#endif
	return ( sp );
	}

lookup( name, s) char *name; { 
	/* look up name: must agree with s w.r.t. STAG, SMOS and SHIDDEN */

	register char *p, *q;
D 20
	int i, j, ii;
E 20
I 20
	int i, ii;
#ifndef FLEXNAMES
	int j;
#endif
E 20
	register struct symtab *sp;

	/* compute initial hash index */
# ifndef BUG1
	if( ddebug > 2 ){
		printf( "lookup( %s, %d ), stwart=%d, instruct=%d\n", name, s, stwart, instruct );
		}
# endif

	i = 0;
#ifndef FLEXNAMES
	for( p=name, j=0; *p != '\0'; ++p ){
		i += *p;
		if( ++j >= NCHNAM ) break;
		}
#else
	i = (int)name;
#endif
	i = i%SYMTSZ;
	sp = &stab[ii=i];

	for(;;){ /* look for name */

		if( sp->stype == TNULL ){ /* empty slot */
			sp->sflags = s;  /* set STAG, SMOS if needed, turn off all others */
#ifndef FLEXNAMES
			p = sp->sname;
			for( j=0; j<NCHNAM; ++j ) if( *p++ = *name ) ++name;
#else
			sp->sname = name;
#endif
			sp->stype = UNDEF;
			sp->sclass = SNULL;
			return( i );
			}
		if( (sp->sflags & (STAG|SMOS|SHIDDEN)) != s ) goto next;
		p = sp->sname;
		q = name;
#ifndef FLEXNAMES
		for( j=0; j<NCHNAM;++j ){
			if( *p++ != *q ) goto next;
			if( !*q++ ) break;
			}
		return( i );
#else
		if (p == q)
			return ( i );
#endif
	next:
		if( ++i >= SYMTSZ ){
			i = 0;
			sp = stab;
			}
		else ++sp;
		if( i == ii ) cerror( "symbol table full" );
		}
	}

#ifndef checkst
/* if not debugging, make checkst a macro */
checkst(lev){
	register int s, i, j;
	register struct symtab *p, *q;

	for( i=0, p=stab; i<SYMTSZ; ++i, ++p ){
		if( p->stype == TNULL ) continue;
		j = lookup( p->sname, p->sflags&(SMOS|STAG) );
		if( j != i ){
			q = &stab[j];
			if( q->stype == UNDEF ||
			    q->slevel <= p->slevel ){
#ifndef FLEXNAMES
				cerror( "check error: %.8s", q->sname );
#else
				cerror( "check error: %s", q->sname );
#endif
				}
			}
#ifndef FLEXNAMES
		else if( p->slevel > lev ) cerror( "%.8s check at level %d", p->sname, lev );
#else
		else if( p->slevel > lev ) cerror( "%s check at level %d", p->sname, lev );
#endif
		}
	}
#endif

struct symtab *
relook(p) register struct symtab *p; {  /* look up p again, and see where it lies */

	register struct symtab *q;

	/* I'm not sure that this handles towers of several hidden definitions in all cases */
	q = &stab[lookup( p->sname, p->sflags&(STAG|SMOS|SHIDDEN) )];
	/* make relook always point to either p or an empty cell */
	if( q->stype == UNDEF ){
		q->stype = TNULL;
		return(q);
		}
	while( q != p ){
		if( q->stype == TNULL ) break;
		if( ++q >= &stab[SYMTSZ] ) q=stab;
		}
	return(q);
	}

D 10
clearst( lev ){ /* clear entries of internal scope  from the symbol table */
	register struct symtab *p, *q, *r;
	register int temp, rehash;
E 10
I 10
clearst( lev ) register int lev; {
	register struct symtab *p, *q;
	register int temp;
	struct symtab *clist = 0;
E 10

	temp = lineno;
	aobeg();

D 10
	/* first, find an empty slot to prevent newly hashed entries from
	   being slopped into... */
E 10
I 10
	/* step 1: remove entries */
	while( chaintop-1 > lev ){
D 20
		register int type;
E 10

E 20
D 10
	for( q=stab; q< &stab[SYMTSZ]; ++q ){
		if( q->stype == TNULL )goto search;
		}

	cerror( "symbol table full");

	search:
	p = q;

	for(;;){
		if( p->stype == TNULL ) {
			rehash = 0;
			goto next;
			}
		lineno = p->suse;
		if( lineno < 0 ) lineno = - lineno;
		if( p->slevel>lev ){ /* must clobber */
			if( p->stype == UNDEF || ( p->sclass == ULABEL && lev < 2 ) ){
E 10
I 10
		p = schain[--chaintop];
		schain[chaintop] = 0;
		for( ; p; p = q ){
			q = p->snext;
D 20
			type = p->stype;
E 20
			if( p->stype == TNULL || p->slevel <= lev )
				cerror( "schain botch" );
			lineno = p->suse < 0 ? -p->suse : p->suse;
			if( p->stype==UNDEF || ( p->sclass==ULABEL && lev<2 ) ){
E 10
				lineno = temp;
#ifndef FLEXNAMES
				uerror( "%.8s undefined", p->sname );
#else
				uerror( "%s undefined", p->sname );
#endif
				}
			else aocode(p);
# ifndef BUG1
I 10
			if( ddebug ){
E 10
#ifndef FLEXNAMES
D 10
			if (ddebug) printf("removing %8s from stab[ %d], flags %o level %d\n",
E 10
I 10
				printf( "removing %.8s", p->sname );
E 10
#else
D 10
			if (ddebug) printf("removing %s from stab[ %d], flags %o level %d\n",
E 10
I 10
				printf( "removing %s", p->sname );
E 10
#endif
D 10
				p->sname,p-stab,p->sflags,p->slevel);
E 10
I 10
				printf( " from stab[%d], flags %o level %d\n",
					p-stab, p->sflags, p->slevel);
				}
E 10
# endif
D 10
			if( p->sflags & SHIDES ) unhide(p);
E 10
I 10
			if( p->sflags & SHIDES )unhide( p );
E 10
			p->stype = TNULL;
D 10
			rehash = 1;
			goto next;
E 10
I 10
			p->snext = clist;
			clist = p;
E 10
			}
D 10
		if( rehash ){
			if( (r=relook(p)) != p ){
				movestab( r, p );
				p->stype = TNULL;
E 10
I 10
		}

	/* step 2: fix any mishashed entries */
	p = clist;
	while( p ){
D 13
		register struct symtab *r;
E 13
I 13
D 26
		register struct symtab *r, *next;
E 26
I 26
D 28
		register struct symtab *r, *next, *t;
E 28
I 28
		register struct symtab *next, **t, *r;
E 28
E 26
E 13

		q = p;
I 13
		next = p->snext;
E 13
		for(;;){
			if( ++q >= &stab[SYMTSZ] )q = stab;
			if( q == p || q->stype == TNULL )break;
			if( (r = relook(q)) != q ) {
I 25
				/* move q in schain list */
D 26
				register struct symtab *t = schain[q->slevel];
				if ( !t )
					cerror("schain botch during relook");
				while ( t->snext && t->snext != q )
					t = t->snext;
				if ( !t->snext )
					cerror("schain botch during relook");
				t->snext = r;
E 26
I 26
D 28
				if( !(t = schain[q->slevel]) )
E 28
I 28
				t = &schain[q->slevel];
				while( *t && *t != q )
					t = &(*t)->snext;
				if( *t )
					*t = r;
				else
E 28
					cerror("schain botch 2");
D 28
				if( t == q )
					schain[q->slevel] = r;
				else {
					while( t->snext && t->snext != q )
						t = t->snext;
					if( !t->snext )
						cerror("schain botch 3");
					t->snext = r;
					}
E 26
				/* are we guaranteed r isn't in clist too? */
E 28
E 25
				*r = *q;
D 12
				q->stype = NULL;
E 12
I 12
				q->stype = TNULL;
E 12
E 10
				}
			}
D 10
		next:
		if( ++p >= &stab[SYMTSZ] ) p = stab;
		if( p == q ) break;
E 10
I 10
D 13
		p = p->snext;
E 13
I 13
		p = next;
E 13
E 10
		}
I 10

E 10
	lineno = temp;
	aoend();
	}

D 10
movestab( p, q ) register struct symtab *p, *q; {
	int k;
	/* structure assignment: *p = *q; */
	p->stype = q->stype;
	p->sclass = q->sclass;
	p->slevel = q->slevel;
	p->offset = q->offset;
	p->sflags = q->sflags;
	p->dimoff = q->dimoff;
	p->sizoff = q->sizoff;
	p->suse = q->suse;
#ifndef FLEXNAMES
	for( k=0; k<NCHNAM; ++k ){
		p->sname[k] = q->sname[k];
		}
#else
	p->sname = q->sname;
#endif
	}


E 10
hide( p ) register struct symtab *p; {
	register struct symtab *q;
	for( q=p+1; ; ++q ){
		if( q >= &stab[SYMTSZ] ) q = stab;
		if( q == p ) cerror( "symbol table full" );
		if( q->stype == TNULL ) break;
		}
D 10
	movestab( q, p );
E 10
I 10
	*q = *p;
E 10
	p->sflags |= SHIDDEN;
	q->sflags = (p->sflags&(SMOS|STAG)) | SHIDES;
#ifndef FLEXNAMES
	if( hflag ) werror( "%.8s redefinition hides earlier one", p->sname );
#else
	if( hflag ) werror( "%s redefinition hides earlier one", p->sname );
#endif
# ifndef BUG1
	if( ddebug ) printf( "	%d hidden in %d\n", p-stab, q-stab );
# endif
	return( idname = q-stab );
	}

unhide( p ) register struct symtab *p; {
	register struct symtab *q;
D 20
	register s, j;
E 20
I 20
	register s;
E 20

	s = p->sflags & (SMOS|STAG);
	q = p;

	for(;;){

		if( q == stab ) q = &stab[SYMTSZ-1];
		else --q;

		if( q == p ) break;

		if( (q->sflags&(SMOS|STAG)) == s ){
#ifndef FLEXNAMES
I 20
			register j;
E 20
			for( j =0; j<NCHNAM; ++j ) if( p->sname[j] != q->sname[j] ) break;
			if( j == NCHNAM ){ /* found the name */
#else
			if (p->sname == q->sname) {
#endif
				q->sflags &= ~SHIDDEN;
# ifndef BUG1
				if( ddebug ) printf( "unhide uncovered %d from %d\n", q-stab,p-stab);
# endif
				return;
				}
			}

		}
	cerror( "unhide fails" );
	}
E 1
