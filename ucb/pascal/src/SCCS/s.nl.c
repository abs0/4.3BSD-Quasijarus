h45068
s 00008/00003/00837
d D 5.1 85/06/05 14:33:39 dist 18 17
c Add copyright
e
s 00004/00008/00836
d D 2.2 84/04/02 12:53:03 peter 17 16
c fixing jennifer's changing (int *) to (struct nl *)
c by changing the way the pointers are used.
c how many more of these are lurking around?
c reported by chris aoki at sun.
e
s 00000/00000/00844
d D 2.1 84/02/08 20:50:19 aoki 16 15
c synchronize to version 2
e
s 00008/00002/00836
d D 1.15 84/02/08 00:51:36 mckusick 15 14
c merge in conformant array code by Carol Nishizak
e
s 00000/00000/00838
d D 1.14 83/09/19 06:59:09 thien 14 13
c Restoring to unlinted version
e
s 00049/00034/00789
d D 1.13 83/08/19 04:58:45 thien 13 12
c The changes were made to allow successful linting
e
s 00001/00002/00822
d D 1.12 83/05/31 19:54:16 peter 12 11
c fix of #ifdef PI placement for pxp, which doesn't know certain things.
e
s 00003/00000/00821
d D 1.11 83/05/31 14:44:25 peter 11 10
c restore conditional compilation so it can be common with pxp.
e
s 00001/00001/00820
d D 1.10 83/02/01 19:58:33 peter 10 9
c fix the range for T1INT.  how long has this been like this?
e
s 00030/00006/00791
d D 1.9 82/10/19 20:42:22 peter 9 8
c c style alignment of variants within records.
e
s 00002/00000/00795
d D 1.8 82/08/27 00:34:24 mckusick 8 7
c convert "assert" from being a reserved word to being a non-standard procedure
e
s 00001/00001/00794
d D 1.7 82/08/26 17:49:00 mckusick 7 6
c make dispose a standard procedure
e
s 00002/00000/00793
d D 1.6 82/03/29 12:25:54 peter 6 5
c genmx() shouldn't be reference unless we are the OBJ version.
e
s 00019/00000/00774
d D 1.5 81/06/01 15:36:44 peter 5 4
c add storage classes to namelist, and use them.
e
s 00002/00002/00772
d D 1.4 80/11/24 18:59:08 peter 4 3
c malloc returns 0 on out of memory, not -1 as in version 6.
e
s 00001/00001/00773
d D 1.3 80/11/17 23:24:24 peter 3 2
c mark the built-in procedure dispose as non-standard
e
s 00009/00005/00765
d D 1.2 80/10/03 01:08:14 peter 2 1
c Implement formal functions and procedures
e
s 00770/00000/00000
d D 1.1 80/08/27 19:55:25 peter 1 0
c date and time created 80/08/27 19:55:25 by peter
e
u
U
t
T
I 1
D 18
/* Copyright (c) 1979 Regents of the University of California */
E 18
I 18
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 18

I 13
#ifndef lint
E 13
D 18
static	char sccsid[] = "%Z%%M% %I% %G%";
I 13
#endif
E 18
I 18
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 18
E 13

#include "whoami.h"
#include "0.h"
I 12
#ifdef PI
E 12
#include "opcode.h"
#include "objfmt.h"
D 12

I 11
#ifdef PI
E 12

E 11
/*
 * NAMELIST SEGMENT DEFINITIONS
 */
struct nls {
	struct nl *nls_low;
	struct nl *nls_high;
} ntab[MAXNL], *nlact;

struct	nl nl[INL];
struct	nl *nlp = nl;
struct	nls *nlact = ntab;

    /*
     *	all these strings must be places where people can find them
     *	since lookup only looks at the string pointer, not the chars.
     *	see, for example, pTreeInit.
     */

    /*
     *	built in constants
     */
char	*in_consts[] = {
	    "true" ,
	    "false" ,
	    "TRUE",
	    "FALSE",
	    "minint" ,
	    "maxint" ,
	    "minchar" ,
	    "maxchar" ,
	    "bell" ,
	    "tab" ,
	    0
	};

    /*
     *	built in simple types
     */
char *in_types[] = 
    {
	"boolean",
	"char",
	"integer",
	"real",
	"_nil",		/* dummy name */
	0
    };

int in_rclasses[] =
    {
	TINT , 
	TINT ,
	TINT ,
	TCHAR ,
	TBOOL ,
	TDOUBLE ,
	0
    };

long in_ranges[] =
    {
D 10
	-128L	 , 128L ,
E 10
I 10
	-128L	 , 127L ,
E 10
	-32768L	 , 32767L ,
	-2147483648L , 2147483647L ,
	0L		 , 127L ,
	0L		 , 1L ,
	0L		 , 0L 		/* fake for reals */
    };

    /*
     *	built in constructed types
     */
char	*in_ctypes[] = {
	    "Boolean" ,
	    "intset" ,
	    "alfa" ,
	    "text" ,
	    0
	};

    /*
     *	built in variables
     */
char	*in_vars[] = {
	    "input" ,
	    "output" ,
	    0
	};

    /*
     *	built in functions 
     */
char *in_funcs[] =
    {
	"abs" ,
	"arctan" ,
	"card" ,
	"chr" ,
	"clock" ,
	"cos" ,
	"eof" ,
	"eoln" ,
	"eos" ,
	"exp" ,
	"expo" ,
	"ln" ,
	"odd" ,
	"ord" ,
	"pred" ,
	"round" ,
	"sin" ,
	"sqr" ,
	"sqrt" ,
	"succ" ,
	"trunc" ,
	"undefined" ,
	/*
	 * Extensions
	 */
	"argc" ,
	"random" ,
	"seed" ,
	"wallclock" ,
	"sysclock" ,
	0
    };

	/*
	 * Built-in procedures
	 */
char *in_procs[] =
    {
I 8
	"assert",
E 8
	"date" ,
	"dispose" ,
	"flush" ,
	"get" ,
	"getseg" ,
	"halt" ,
	"linelimit" ,
	"message" ,
	"new" ,
	"pack" ,
	"page" ,
	"put" ,
	"putseg" ,
	"read" ,
	"readln" ,
	"remove" ,
	"reset" ,
	"rewrite" ,
	"time" ,
	"unpack" ,
	"write" ,
	"writeln" ,
	/*
	 * Extensions
	 */
	"argv" ,
	"null" ,
	"stlimit" ,
	0
    };

#ifndef PI0
    /*
     *	and their opcodes
     */
int in_fops[] =
    {
	O_ABS2,
	O_ATAN,
	O_CARD|NSTAND,
	O_CHR2,
	O_CLCK|NSTAND,
	O_COS,
	O_EOF,
	O_EOLN,
	0,
	O_EXP,
	O_EXPO|NSTAND,
	O_LN,
	O_ODD2,
	O_ORD2,
	O_PRED2,
	O_ROUND,
	O_SIN,
	O_SQR2,
	O_SQRT,
	O_SUCC2,
	O_TRUNC,
	O_UNDEF|NSTAND,
	/*
	 * Extensions
	 */
	O_ARGC|NSTAND,
	O_RANDOM|NSTAND,
	O_SEED|NSTAND,
	O_WCLCK|NSTAND,
	O_SCLCK|NSTAND
    };

    /*
     * Built-in procedures
     */
int in_pops[] =
    {
I 8
	O_ASRT|NSTAND,
E 8
	O_DATE|NSTAND,
D 3
	O_DISPOSE,
E 3
I 3
D 7
	O_DISPOSE|NSTAND,
E 7
I 7
	O_DISPOSE,
E 7
E 3
	O_FLUSH|NSTAND,
	O_GET,
	0,
	O_HALT|NSTAND,
	O_LLIMIT|NSTAND,
	O_MESSAGE|NSTAND,
	O_NEW,
	O_PACK,
	O_PAGE,
	O_PUT,
	0,
	O_READ4,
	O_READLN,
	O_REMOVE|NSTAND,
	O_RESET,
	O_REWRITE,
	O_TIME|NSTAND,
	O_UNPACK,
	O_WRITEF,
	O_WRITLN,
	/*
	 * Extensions
	 */
	O_ARGV|NSTAND,
	O_ABORT|NSTAND,
	O_STLIM|NSTAND
    };
#endif

/*
 * Initnl initializes the first namelist segment and then
 * initializes the name list for block 0.
 */
initnl()
    {
	register char		**cp;
	register struct nl	*np;
	struct nl		*fp;
	int			*ip;
	long			*lp;

#ifdef	DEBUG
	if ( hp21mx )
	    {
		MININT = -32768.;
		MAXINT = 32767.;
#ifndef	PI0
I 6
#ifdef OBJ
E 6
		genmx();
I 6
#endif OBJ
E 6
#endif
	    }
#endif
	ntab[0].nls_low = nl;
	ntab[0].nls_high = &nl[INL];
D 13
	defnl ( 0 , 0 , 0 , 0 );
E 13
I 13
	(void) defnl ( (char *) 0 , 0 , NLNIL , 0 );
E 13

	/*
	 *	Types
	 */
	for ( cp = in_types ; *cp != 0 ; cp ++ )
D 13
	    hdefnl ( *cp , TYPE , nlp , 0 );
E 13
I 13
	    (void) hdefnl ( *cp , TYPE , nlp , 0 );
E 13

	/*
	 *	Ranges
	 */
	lp = in_ranges;
	for ( ip = in_rclasses ; *ip != 0 ; ip ++ )
	    {
D 13
		np = defnl ( 0 , RANGE , nl+(*ip) , 0 );
E 13
I 13
		np = defnl ( (char *) 0 , RANGE , nl+(*ip) , 0 );
E 13
		nl[*ip].type = np;
		np -> range[0] = *lp ++ ;
		np -> range[1] = *lp ++ ;
	
	    };

	/*
	 *	built in constructed types
	 */
	
	cp = in_ctypes;
	/*
	 *	Boolean = boolean;
	 */
D 13
	hdefnl ( *cp++ , TYPE , nl+T1BOOL , 0 );
E 13
I 13
	(void) hdefnl ( *cp++ , TYPE , (struct nl *) (nl+T1BOOL) , 0 );
E 13

	/*
	 *	intset = set of 0 .. 127;
	 */
D 13
	intset = *cp++;
	hdefnl( intset , TYPE , nlp+1 , 0 );
	defnl ( 0 , SET , nlp+1 , 0 );
	np = defnl ( 0 , RANGE , nl+TINT , 0 );
E 13
I 13
	intset = ((struct nl *) *cp++);
	(void) hdefnl( (char *) intset , TYPE , nlp+1 , 0 );
	(void) defnl ( (char *) 0 , SET , nlp+1 , 0 );
	np = defnl ( (char *) 0 , RANGE , nl+TINT , 0 );
E 13
	np -> range[0] = 0L;
	np -> range[1] = 127L;

	/*
	 *	alfa = array [ 1 .. 10 ] of char;
	 */
D 13
	np = defnl ( 0 , RANGE , nl+TINT , 0 );
E 13
I 13
	np = defnl ( (char *) 0 , RANGE , nl+TINT , 0 );
E 13
	np -> range[0] = 1L;
	np -> range[1] = 10L;
D 13
	defnl ( 0 , ARRAY , nl+T1CHAR , 1 ) -> chain = np;
	hdefnl ( *cp++ , TYPE , nlp-1 , 0 );
E 13
I 13
	defnl ( (char *) 0 , ARRAY , nl+T1CHAR , 1 ) -> chain = np;
	(void) hdefnl ( *cp++ , TYPE , nlp-1 , 0 );
E 13

	/*
	 *	text = file of char;
	 */
D 13
	hdefnl ( *cp++ , TYPE , nlp+1 , 0 );
	np = defnl ( 0 , FILET , nl+T1CHAR , 0 );
E 13
I 13
	(void) hdefnl ( *cp++ , TYPE , nlp+1 , 0 );
	np = defnl ( (char *) 0 , FILET , nl+T1CHAR , 0 );
E 13
	np -> nl_flags |= NFILES;

	/*
	 *	input,output : text;
	 */
	cp = in_vars;
#	ifndef	PI0
		input = hdefnl ( *cp++ , VAR , np , INPUT_OFF );
		output = hdefnl (  *cp++ , VAR , np , OUTPUT_OFF );
#	else
		input = hdefnl ( *cp++ , VAR , np , 0 );
		output = hdefnl ( *cp++ , VAR , np , 0 );
#	endif
I 5
#	ifdef PC
	    input -> extra_flags |= NGLOBAL;
	    output -> extra_flags |= NGLOBAL;
#	endif PC
E 5

	/*
	 *	built in constants
	 */
	cp = in_consts;
	np = hdefnl ( *cp++ , CONST , nl + TBOOL , 1 );
	fp = hdefnl ( *cp++ , CONST , nl + TBOOL , 0 );
	(nl + TBOOL)->chain = fp;
	fp->chain = np;
	np = hdefnl ( *cp++ , CONST , nl + TBOOL , 1 );
	fp = hdefnl ( *cp++ , CONST , nl + TBOOL , 0 );
	fp->chain = np;
	if (opt('s'))
		(nl + TBOOL)->chain = fp;
	hdefnl ( *cp++ , CONST , nl + T4INT , 0 ) -> range[0] = MININT;
	hdefnl ( *cp++ , CONST , nl + T4INT , 0 ) -> range[0] = MAXINT;
D 13
	hdefnl ( *cp++ , CONST , nl + T1CHAR , 0 );
	hdefnl ( *cp++ , CONST , nl + T1CHAR , 127 );
	hdefnl ( *cp++ , CONST , nl + T1CHAR , '\007' );
	hdefnl ( *cp++ , CONST , nl + T1CHAR , '\t' );
E 13
I 13
	(void) hdefnl ( *cp++ , CONST , nl + T1CHAR , 0 );
	(void) hdefnl ( *cp++ , CONST , nl + T1CHAR , 127 );
	(void) hdefnl ( *cp++ , CONST , nl + T1CHAR , '\007' );
	(void) hdefnl ( *cp++ , CONST , nl + T1CHAR , '\t' );
E 13

	/*
	 * Built-in functions and procedures
	 */
#ifndef PI0
	ip = in_fops;
	for ( cp = in_funcs ; *cp != 0 ; cp ++ )
D 13
	    hdefnl ( *cp , FUNC , 0 , * ip ++ );
E 13
I 13
	    (void) hdefnl ( *cp , FUNC , NLNIL , * ip ++ );
E 13
	ip = in_pops;
	for ( cp = in_procs ; *cp != 0 ; cp ++ )
D 13
	    hdefnl ( *cp , PROC , 0 , * ip ++ );
E 13
I 13
	    (void) hdefnl ( *cp , PROC , NLNIL , * ip ++ );
E 13
#else
	for ( cp = in_funcs ; *cp != 0 ; cp ++ )
D 13
	    hdefnl ( *cp , FUNC , 0 , 0 );
E 13
I 13
	    (void) hdefnl ( *cp , FUNC , NLNIL , 0 );
E 13
	for ( cp = in_procs ; *cp != 0 , cp ++ )
D 13
	    hdefnl ( *cp , PROC , 0 , 0 );
E 13
I 13
	    (void) hdefnl ( *cp , PROC , NLNIL , 0 );
E 13
#endif
#	ifdef PTREE
	    pTreeInit();
#	endif
    }

struct nl *
hdefnl(sym, cls, typ, val)
I 13
    char *sym;
    int  cls;
    struct nl *typ;
    int val;
E 13
{
	register struct nl *p;

#ifndef PI1
	if (sym)
D 13
		hash(sym, 0);
E 13
I 13
		(void) hash(sym, 0);
E 13
#endif
	p = defnl(sym, cls, typ, val);
	if (sym)
D 13
		enter(p);
E 13
I 13
		(void) enter(p);
E 13
	return (p);
}

/*
 * Free up the name list segments
 * at the end of a statement/proc/func
 * All segments are freed down to the one in which
 * p points.
 */
nlfree(p)
	struct nl *p;
{

	nlp = p;
	while (nlact->nls_low > nlp || nlact->nls_high < nlp) {
D 13
		free(nlact->nls_low);
E 13
I 13
		free((char *) nlact->nls_low);
E 13
		nlact->nls_low = NIL;
		nlact->nls_high = NIL;
		--nlact;
		if (nlact < &ntab[0])
			panic("nlfree");
	}
}
I 11
#endif PI
E 11


I 13
#ifndef PC
#ifndef OBJ
E 13
char	*VARIABLE	= "variable";
I 13
#endif PC
#endif OBJ
E 13

char	*classes[ ] = {
	"undefined",
	"constant",
	"type",
	"variable",	/*	VARIABLE	*/
	"array",
	"pointer or file",
	"record",
	"field",
	"procedure",
	"function",
	"variable",	/*	VARIABLE	*/
	"variable",	/*	VARIABLE	*/
	"pointer",
	"file",
	"set",
	"subrange",
	"label",
	"withptr",
	"scalar",
	"string",
	"program",
D 2
	"improper"
#ifdef DEBUG
	,"variant"
#endif
E 2
I 2
	"improper",
	"variant",
	"formal procedure",
	"formal function"
E 2
};

I 13
#ifndef PC
#ifndef OBJ
E 13
char	*snark	= "SNARK";
I 13
#endif
#endif
E 13

#ifdef PI
#ifdef DEBUG
char	*ctext[] =
{
	"BADUSE",
	"CONST",
	"TYPE",
	"VAR",
	"ARRAY",
	"PTRFILE",
	"RECORD",
	"FIELD",
	"PROC",
	"FUNC",
	"FVAR",
	"REF",
	"PTR",
	"FILET",
	"SET",
	"RANGE",
	"LABEL",
	"WITHPTR",
	"SCAL",
	"STR",
	"PROG",
	"IMPROPER",
D 2
	"VARNT"
E 2
I 2
	"VARNT",
	"FPROC",
D 15
	"FFUNC"
E 15
I 15
	"FFUNC",
	"CRANGE"
E 15
E 2
};

char	*stars	= "\t***";

/*
 * Dump the namelist from the
 * current nlp down to 'to'.
 * All the namelist is dumped if
 * to is NIL.
 */
I 13
/*VARARGS*/
E 13
dumpnl(to, rout)
	struct nl *to;
{
	register struct nl *p;
D 13
	register int j;
E 13
	struct nls *nlsp;
D 13
	int i, v, head;
E 13
I 13
	int v, head;
E 13

	if (opt('y') == 0)
		return;
	if (to != NIL)
		printf("\n\"%s\" Block=%d\n", rout, cbn);
	nlsp = nlact;
	head = NIL;
	for (p = nlp; p != to;) {
		if (p == nlsp->nls_low) {
			if (nlsp == &ntab[0])
				break;
			nlsp--;
			p = nlsp->nls_high;
		}
		p--;
		if (head == NIL) {
			printf("\tName\tClass  Bn+Flags\tType\tVal\tChn\n");
			head++;
		}
		printf("%3d:", nloff(p));
		if (p->symbol)
			printf("\t%.7s", p->symbol);
		else
			printf(stars);
		if (p->class)
			printf("\t%s", ctext[p->class]);
		else
			printf(stars);
		if (p->nl_flags) {
			pchr('\t');
			if (p->nl_flags & 037)
				printf("%d ", p->nl_flags & 037);
#ifndef PI0
			if (p->nl_flags & NMOD)
				pchr('M');
			if (p->nl_flags & NUSED)
				pchr('U');
#endif
			if (p->nl_flags & NFILES)
				pchr('F');
		} else
			printf(stars);
		if (p->type)
			printf("\t[%d]", nloff(p->type));
		else
			printf(stars);
		v = p->value[0];
		switch (p->class) {
			case TYPE:
				break;
			case VARNT:
				goto con;
			case CONST:
				switch (nloff(p->type)) {
					default:
						printf("\t%d", v);
						break;
					case TDOUBLE:
						printf("\t%f", p->real);
						break;
					case TINT:
					case T4INT:
con:
						printf("\t%ld", p->range[0]);
						break;
					case TSTR:
						printf("\t'%s'", p->ptr[0]);
						break;
					}
				break;
			case VAR:
			case REF:
			case WITHPTR:
I 2
			case FFUNC:
			case FPROC:
E 2
				printf("\t%d,%d", cbn, v);
				break;
			case SCAL:
			case RANGE:
				printf("\t%ld..%ld", p->range[0], p->range[1]);
				break;
I 15
			case CRANGE:
				printf("\t%s..%s", p->nptr[0]->symbol,
					p->nptr[1]->symbol);
				break;
E 15
			case RECORD:
D 9
				printf("\t%d(%d)", v, p->value[NL_FLDSZ]);
E 9
I 9
				printf("\t%d", v);
E 9
				break;
			case FIELD:
				printf("\t%d", v);
				break;
			case STR:
				printf("\t|%d|", p->value[0]);
				break;
			case FVAR:
			case FUNC:
			case PROC:
			case PROG:
				if (cbn == 0) {
					printf("\t<%o>", p->value[0] & 0377);
#ifndef PI0
					if (p->value[0] & NSTAND)
						printf("\tNSTAND");
#endif
					break;
				}
				v = p->value[1];
			default:
D 13
casedef:
E 13
I 13

E 13
				if (v)
					printf("\t<%d>", v);
				else
					printf(stars);
		}
		if (p->chain)
			printf("\t[%d]", nloff(p->chain));
		switch (p->class) {
			case RECORD:
D 9
				if (p->ptr[NL_VARNT])
					printf("\tVARNT=[%d]", nloff(p->ptr[NL_VARNT]));
				if (p->ptr[NL_TAG])
					printf(" TAG=[%d]", nloff(p->ptr[NL_TAG]));
E 9
I 9
				printf("\tALIGN=%d", p->align_info);
				if (p->ptr[NL_FIELDLIST]) {
				    printf(" FLIST=[%d]",
					nloff(p->ptr[NL_FIELDLIST]));
				} else {
				    printf(" FLIST=[]");
				}
				if (p->ptr[NL_TAG]) {
				    printf(" TAG=[%d]",
					nloff(p->ptr[NL_TAG]));
				} else {
				    printf(" TAG=[]");
				}
				if (p->ptr[NL_VARNT]) {
				    printf(" VARNT=[%d]",
					nloff(p->ptr[NL_VARNT]));
				} else {
				    printf(" VARNT=[]");
				}
E 9
				break;
I 9
			case FIELD:
				if (p->ptr[NL_FIELDLIST]) {
				    printf("\tFLIST=[%d]",
					nloff(p->ptr[NL_FIELDLIST]));
				} else {
				    printf("\tFLIST=[]");
				}
				break;
E 9
			case VARNT:
D 9
				printf("\tVTOREC=[%d]", nloff(p->ptr[NL_VTOREC]));
E 9
I 9
				printf("\tVTOREC=[%d]",
				    nloff(p->ptr[NL_VTOREC]));
E 9
				break;
		}
I 5
#		ifdef PC
		    if ( p -> extra_flags != 0 ) {
			pchr( '\t' );
			if ( p -> extra_flags & NEXTERN )
			    printf( "NEXTERN " );
			if ( p -> extra_flags & NLOCAL )
			    printf( "NLOCAL " );
			if ( p -> extra_flags & NPARAM )
			    printf( "NPARAM " );
			if ( p -> extra_flags & NGLOBAL )
			    printf( "NGLOBAL " );
			if ( p -> extra_flags & NREGVAR )
			    printf( "NREGVAR " );
		    }
#		endif PC
E 5
#		ifdef PTREE
		    pchr( '\t' );
		    pPrintPointer( stdout , "%s" , p -> inTree );
#		endif
		pchr('\n');
	}
	if (head == 0)
		printf("\tNo entries\n");
}
#endif


/*
 * Define a new name list entry
 * with initial symbol, class, type
 * and value[0] as given.  A new name
 * list segment is allocated to hold
 * the next name list slot if necessary.
 */
struct nl *
defnl(sym, cls, typ, val)
	char *sym;
	int cls;
	struct nl *typ;
	int val;
{
	register struct nl *p;
	register int *q, i;
	char *cp;

	p = nlp;

	/*
	 * Zero out this entry
	 */
D 13
	q = p;
E 13
I 13
	q = ((int *) p);
E 13
	i = (sizeof *p)/(sizeof (int));
	do
		*q++ = 0;
	while (--i);

	/*
	 * Insert the values
	 */
	p->symbol = sym;
	p->class = cls;
	p->type = typ;
	p->nl_block = cbn;
	p->value[0] = val;

	/*
	 * Insure that the next namelist
	 * entry actually exists. This is
	 * really not needed here, it would
	 * suffice to do it at entry if we
	 * need the slot.  It is done this
	 * way because, historically, nlp
	 * always pointed at the next namelist
	 * slot.
	 */
	nlp++;
	if (nlp >= nlact->nls_high) {
		i = NLINC;
D 13
		cp = malloc(NLINC * sizeof *nlp);
E 13
I 13
		cp = (char *) malloc(NLINC * sizeof *nlp);
E 13
D 4
		if (cp == -1) {
E 4
I 4
		if (cp == 0) {
E 4
			i = NLINC / 2;
D 13
			cp = malloc((NLINC / 2) * sizeof *nlp);
E 13
I 13
			cp = (char *) malloc((NLINC / 2) * sizeof *nlp);
E 13
		}
D 4
		if (cp == -1) {
E 4
I 4
		if (cp == 0) {
E 4
			error("Ran out of memory (defnl)");
			pexit(DIED);
		}
		nlact++;
		if (nlact >= &ntab[MAXNL]) {
			error("Ran out of name list tables");
			pexit(DIED);
		}
D 13
		nlp = cp;
E 13
I 13
		nlp = (struct nl *) cp;
E 13
		nlact->nls_low = nlp;
		nlact->nls_high = nlact->nls_low + i;
	}
	return (p);
}

/*
 * Make a duplicate of the argument
 * namelist entry for, e.g., type
 * declarations of the form 'type a = b'
 * and array indicies.
 */
struct nl *
nlcopy(p)
	struct nl *p;
{
D 13
	register int *p1, *p2, i;
E 13
I 13
	register struct nl *p1, *p2;
D 17
	register int i;
E 17
E 13

	p1 = p;
D 13
	p = p2 = defnl(0, 0, 0, 0);
E 13
I 13
D 17
	p = p2 = defnl((char *) 0, 0, NLNIL, 0);
E 13
	i = (sizeof *p)/(sizeof (int));
	do
		*p2++ = *p1++;
	while (--i);
	p->chain = NIL;
	return (p);
E 17
I 17
	p2 = defnl((char *) 0, 0, NLNIL, 0);
	*p2 = *p1;
	p2->chain = NLNIL;
	return (p2);
E 17
}

/*
 * Compute a namelist offset
 */
nloff(p)
	struct nl *p;
{

	return (p - nl);
}

/*
 * Enter a symbol into the block
 * symbol table.  Symbols are hashed
 * 64 ways based on low 6 bits of the
 * character pointer into the string
 * table.
 */
struct nl *
enter(np)
	struct nl *np;
{
	register struct nl *rp, *hp;
	register struct nl *p;
	int i;

	rp = np;
	if (rp == NIL)
		return (NIL);
#ifndef PI1
	if (cbn > 0)
		if (rp->symbol == input->symbol || rp->symbol == output->symbol)
			error("Pre-defined files input and output must not be redefined");
#endif
D 13
	i = rp->symbol;
E 13
I 13
	i = (int) rp->symbol;
E 13
	i &= 077;
	hp = disptab[i];
	if (rp->class != BADUSE && rp->class != FIELD)
	for (p = hp; p != NIL && (p->nl_block & 037) == cbn; p = p->nl_next)
D 15
		if (p->symbol == rp->symbol && p->class != BADUSE && p->class != FIELD) {
E 15
I 15
		if (p->symbol == rp->symbol && p->symbol != NIL &&
		    p->class != BADUSE && p->class != FIELD) {
E 15
#ifndef PI1
			error("%s is already defined in this block", rp->symbol);
#endif
			break;

		}
	rp->nl_next = hp;
	disptab[i] = rp;
	return (rp);
}
#endif
E 1
