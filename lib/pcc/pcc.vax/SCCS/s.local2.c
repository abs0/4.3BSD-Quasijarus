h33154
s 00006/00019/01877
d D 1.39 88/05/11 00:40:35 donn 41 40
c Installed much simpler unsigned-to-floating conversion code suggested by
c Robert Firth and the tahoe compiler.
e
s 00033/00005/01863
d D 1.38 87/12/11 00:40:12 donn 40 39
c utah rcsid 1.33 87/11/28 02:59:18: Be cooperative with SCCON and SSCON by
c masking and sign-extending ASG OPSIMP constant operands.  Added a few
c comments in the tortuous AND code too.
e
s 00043/00015/01825
d D 1.37 87/12/11 00:39:53 donn 39 38
c utah rcsid 1.32 87/09/24 22:24:49: Missing case for FORARG in sconv() --
c floating to short integral conversions.
e
s 00005/00001/01835
d D 1.36 87/12/11 00:39:33 donn 38 37
c utah rcsid 1.31 87/09/08 19:12:14: Fix bug where stack push of 0.0 only
c pushes one word of zeroes...  Ack.
e
s 00002/00001/01834
d D 1.35 87/12/11 00:39:03 donn 37 36
c utah rcsid 1.30 87/09/07 20:41:00: Another minor battle in the struggle
c between makearg() and float arguments.  This time we kluge the issue and
c avoid szty() (which predicts that float values are only 4 bytes when SPRECC
c is used).
e
s 00091/00036/01744
d D 1.34 87/12/11 00:38:35 donn 36 35
c utah rcsid 1.29 87/08/25 00:05:43: Took care of some bugs in the extension
c of sconv() to handle FORARG evaluations.  Conversion of UCHAR/USHORT to
c floating is now handled in sconv() so that ZG can take advantage of it;
c this cures a bug with assignment ops with UCHAR/USHORT lhs and floating rhs
c which caused the lhs to be treated as signed.  Conversions to FLOAT are now
c handled in sconv() too.
e
s 00000/00000/01780
d D 1.33 87/12/11 00:38:14 donn 35 34
c conversions to insert an INT conversion and thus avoid the expensive and
c redundant UNSIGNED to FLOAT/DOUBLE overhead.  (7) Delete INT to UNSIGNED
c and reverse conversions on function calls.  (8) Delete FLOAT to DOUBLE
c conversions below logical operators.
e
s 00099/00012/01681
d D 1.32 87/12/11 00:38:02 donn 34 33
c utah rcsid 1.28 87/08/24 01:55:20: (1) Changed code for ZZ so that we can
c generate optimal AND tests against constants.  (2) Fixed botch in my
c makearg() routine.  (3) Generate 'pushl' instead of 'movl' when working on
c FORARG in sconv().  (4) Permitted NAME nodes as possible indexing bases,
c using pc relative deferred addressing.  (5) Produce positive bicl masks if
c possible, so we can use literals.  (6) Modify UCHAR/USHORT to FLOAT/DOUBLE
e
s 00004/00004/01689
d D 1.31 87/12/11 00:37:43 donn 33 32
c utah rcsid 1.27 87/07/17 17:09:50: Cosmetic change to tlen() -- use
c #define'd constants.  Also fix use of local machine 'sizeof (int)' in
c zzzcode to #define'd target machine constants.
e
s 00000/00000/01693
d D 1.30 87/12/11 00:37:25 donn 32 31
c shifts.  (6) Add ZV entry in zzzcode() to handle FORARG goals for
c conversions and leaf nodes.  (7) Fix minor bug with ZB entry and unsigned
c char/short.
e
s 00337/00381/01356
d D 1.29 87/12/11 00:37:08 donn 31 30
c utah rcsid 1.26 87/07/17 15:31:14: Some changes to reduce differences with
c the tahoe compiler.  (1) #include <ctype.h> not "ctype.h".  (2) Simplify
c eobl2(), hopcode() and hoptab[], flshape(), acon(), and cbgen() and
c ccbranches[].  (3) Farm out conversion and structure assignment code in
c zzzcode() to sconv() and stasg() functions.  (4) Delete lots of
c commented-out old code.  (5) Fix bug in optim2() code for degenerate left
e
s 00001/00001/01736
d D 1.28 87/12/11 00:36:44 donn 30 29
c utah rcsid 1.25 87/07/07 20:30:32: Permit the ZE code for INCR/DECR in
c zzzcode() to take a NAME as its second operand: this permits FLOAT and
c DOUBLE operands to be handled, since floating constants are represented by
c NAMEs.
e
s 00003/00003/01734
d D 1.27 87/12/11 00:36:19 donn 29 28
c utah rcsid 1.24 87/07/07 19:37:31: Prevent core dumps in shumul() when
c using -x debugging...
e
s 00029/00011/01708
d D 1.26 87/12/11 00:35:56 donn 28 27
c utah rcsid 1.23 87/05/31 20:46:39: More work on degenerate operations in
c optim2() and degenerate().
e
s 00218/00070/01501
d D 1.25 87/12/11 00:35:34 donn 27 26
c utah rcsid 1.22 87/05/15 17:03:03: First pass at handling degenerate
c operations in optim2().  The idea is mainly that we can avoid some table
c complications by assuming that no degenerate operations dribble down there.
c Since I did some degenerate operations, I decided to do a few others so
c that some operations aren't outstandingly slow.
e
s 00000/00000/01571
d D 1.24 87/12/11 00:35:10 donn 26 25
c on a certain amount of tree canonicalization there.
e
s 00087/00001/01484
d D 1.23 87/12/11 00:34:56 donn 25 24
c utah rcsid 1.21 87/04/24 19:05:37: Optimize comparisons with constants
c which are out of range of short integral types.  The purpose of this was
c mainly to handle a problem in the code table -- it's hard to generate the
c best code for short comparisons unless you know that the ridiculous cases
c have been taken care of.  The optimization could have gone in either
c clocal() or optim2(); the latter seemed more reasonable since I could count
e
s 00055/00002/01430
d D 1.22 87/12/11 00:34:32 donn 24 23
c utah rcsid 1.20 87/04/19 23:47:13: Add support for handling unsigned div
c and rem inline when the divisor is a constant: (1) ZJ template escape for
c stuff that's too complex for the table; (2) a real version of upput() which
c lets the table access both words of the 64-bit dividend operand of the ediv
c instruction; (3) a hack to hardops() to detect constant divisors -- it
c handles the easiest case and passes everything else to the table.
e
s 00000/00002/01432
d D 1.21 87/12/11 00:34:07 donn 23 22
c utah rcsid 1.19 87/03/18 00:02:55: The earlier rewrite of shtemp() left the
c code for STARNM forms commented out for some reason...
e
s 00024/00001/01410
d D 1.20 87/12/11 00:33:43 donn 22 21
c utah rcsid 1.18 87/02/08 22:50:12: Replaced shtemp() routine -- shtemp() is
c supposed to find leaf nodes which don't use any temporary registers, and
c the old version didn't do that well.
e
s 00001/00001/01410
d D 1.19 87/12/11 00:33:22 donn 21 20
c utah rcsid 1.17 87/01/16 02:45:01: Permit nonpositive offsets from the
c argument pointer for excessively clever program which want to recover funny
c stuff on the stack.
e
s 00016/00008/01395
d D 1.18 87/12/11 00:32:53 donn 20 19
c utah rcsid 1.16 87/01/15 01:36:58: Changed optim2()'s SCONV optimization
c code to avoid screwing up function types.  Also some minor lint fixes.
e
s 00003/00001/01400
d D 1.17 87/12/11 00:32:28 donn 19 18
c utah rcsid 1.15 86/11/27 20:26:18: update to ucb sid 1.15 -- upput calling
c sequence changes (sam).  Added a couple /*ARGSUSED*/ lint directives;
c probably a lost cause.
e
s 00002/00001/01399
d D 1.16 87/12/11 00:32:07 donn 18 17
c utah rcsid 1.14 86/06/18 14:35:25: The idea of converting ASSIGN+SCONV into
c ASSIGN with modified types was cute, but unfortunately certain varieties of
c ASSIGN are not supported -- in particular double => bit field.  We chicken
c out and leave bitfields alone.
e
s 00001/00001/01399
d D 1.15 86/10/15 22:02:08 sam 17 16
c upput calling sequence changes
e
s 00001/00001/01399
d D 1.14 86/04/23 13:56:22 donn 16 15
c In the code for unsigned => float conversions, turned bbsc into magic
c jbsc to avoid 'branch too far' messages from the assembler.
e
s 00072/00000/01328
d D 1.13 86/01/08 01:39:13 donn 15 14
c (1) Modified zzzcode() to pick up unsigned int => float/double conversions
c and produce correct code.  (2) Added 'G' entry under zzzcode() to handle
c assignment ops with unbalanced operand types (integer *= float).  (3) Don't
c fold scalar and pointer conversions -- there are actually two kinds of
c nodes whose semantics changes with type.
e
s 00124/00079/01204
d D 1.12 85/08/23 15:03:45 mckusick 14 12
c update from donn@utah-cs
e
s 00006/00002/01281
d R 1.12 85/07/27 10:44:13 mckusick 13 12
c double cast fix (from donn@utah-cs)
e
s 00069/00008/01214
d D 1.11 85/06/18 19:11:10 bloom 12 11
c fix pointer increment problems (from donn@utah-cs)
e
s 00011/00020/01211
d D 1.10 85/05/03 20:55:31 mckusick 11 9
c sign-extension corrections (from donn@utah-cs)
e
s 00032/00017/01214
d R 1.10 85/05/01 14:56:00 mckusick 10 9
c sign-extension corrections (from donn@utah-cs)
e
s 00001/00001/01230
d D 1.9 85/04/02 11:52:33 ralph 9 8
c use common header file for intermediate language defs.
e
s 00123/00016/01108
d D 1.8 85/01/18 16:11:38 ralph 8 7
c changes for single precision floats; lint cleanups
e
s 00029/00068/01095
d D 1.7 85/01/15 16:49:29 ralph 7 6
c added calls to audiv & aurem so side effects u[foo()] /= x done once.
e
s 00008/00008/01155
d D 1.6 85/01/07 16:37:14 ralph 6 5
c fix autoinc/autodec detection in shumul() (get size right).
e
s 00023/00033/01140
d D 1.5 84/09/21 14:39:06 ralph 5 4
c don't convert ICON to unsigned type if converting to float/double
e
s 00006/00000/01167
d D 1.4 84/06/06 15:30:45 ralph 4 3
c don't throw away float <-> double conversions for FORTRAN.
e
s 00009/00018/01158
d D 1.3 84/04/27 09:58:29 ralph 3 2
c fix structure arguments. don't map OREG to REG for STASG (match fails)
e
s 00075/00054/01101
d D 1.2 84/03/14 15:41:58 ralph 2 1
c merge f1 and c1; fix type casting conversion bugs.
e
s 01155/00000/00000
d D 1.1 82/12/15 13:23:55 linton 1 0
c date and time created 82/12/15 13:23:55 by linton
e
u
U
t
T
I 8
# ifndef lint
E 8
I 1
static char *sccsid ="%W% (Berkeley) %G%";
I 8
# endif

E 8
D 9
# include "mfile2"
E 9
I 9
# include "pass2.h"
E 9
D 31
# include "ctype.h"
E 31
I 31
# include <ctype.h>

# define putstr(s)	fputs((s), stdout)

E 31
# ifdef FORT
int ftlab1, ftlab2;
# endif
/* a lot of the machine dependent parts of the second pass */

I 14
D 31
# define putstr(s)	fputs((s), stdout)

E 31
E 14
# define BITMASK(n) ((1L<<n)-1)

I 20
/*ARGSUSED*/
E 20
where(c){
	fprintf( stderr, "%s, line %d: ", filename, lineno );
	}

lineid( l, fn ) char *fn; {
	/* identify line l and file fn */
	printf( "#	line %d, file %s\n", l, fn );
	}


eobl2(){
D 31
	OFFSZ spoff;	/* offset from stack pointer */
#ifdef FORT
E 31
I 31
	register OFFSZ spoff;	/* offset from stack pointer */
#ifndef FORT
	extern int ftlab1, ftlab2;
#endif

E 31
	spoff = maxoff;
	if( spoff >= AUTOINIT ) spoff -= AUTOINIT;
	spoff /= SZCHAR;
	SETOFF(spoff,4);
I 31
#ifdef FORT
E 31
#ifndef FLEXNAMES
	printf( "	.set	.F%d,%ld\n", ftnno, spoff );
#else
	/* SHOULD BE L%d ... ftnno but must change pc/f77 */
	printf( "	.set	LF%d,%ld\n", ftnno, spoff );
#endif
#else
D 31
	extern int ftlab1, ftlab2;

	spoff = maxoff;
	if( spoff >= AUTOINIT ) spoff -= AUTOINIT;
	spoff /= SZCHAR;
	SETOFF(spoff,4);
E 31
	printf( "L%d:\n", ftlab1);
	if( spoff!=0 )
		if( spoff < 64 )
			printf( "	subl2	$%ld,sp\n", spoff);
		else
			printf( "	movab	-%ld(sp),sp\n", spoff);
	printf( "	jbr 	L%d\n", ftlab2);
#endif
	maxargs = -1;
	}

struct hoptab { int opmask; char * opstring; } ioptab[] = {

D 31
	ASG PLUS, "add",
	ASG MINUS, "sub",
	ASG MUL, "mul",
	ASG DIV, "div",
	ASG OR, "bis",
	ASG ER,	"xor",
	ASG AND, "bic",
E 31
	PLUS,	"add",
	MINUS,	"sub",
	MUL,	"mul",
	DIV,	"div",
	OR,	"bis",
	ER,	"xor",
	AND,	"bic",
	-1, ""    };

hopcode( f, o ){
	/* output the appropriate string from the above table */

	register struct hoptab *q;

I 31
	if(asgop(o))
		o = NOASG o;
E 31
	for( q = ioptab;  q->opmask>=0; ++q ){
		if( q->opmask == o ){
D 14
			printf( "%s", q->opstring );
E 14
I 14
D 31
			putstr( q->opstring );
E 14
/* tbl
D 14
			if( f == 'F' ) printf( "e" );
			else if( f == 'D' ) printf( "d" );
E 14
I 14
			if( f == 'F' ) putchar( 'e' );
			else if( f == 'D' ) putchar( 'd' );
E 14
   tbl */
/* tbl */
			switch( f ) {
				case 'L':
				case 'W':
				case 'B':
				case 'D':
				case 'F':
D 14
					printf("%c", tolower(f));
E 14
I 14
					putchar(tolower(f));
E 14
					break;

				}
/* tbl */
E 31
I 31
			printf( "%s%c", q->opstring, tolower(f));
E 31
			return;
			}
		}
	cerror( "no hoptab for %s", opst[o] );
	}

char *
rnames[] = {  /* keyed to register number tokens */

	"r0", "r1",
	"r2", "r3", "r4", "r5",
	"r6", "r7", "r8", "r9", "r10", "r11",
	"ap", "fp", "sp", "pc",
D 31

E 31
	};

int rstatus[] = {
	SAREG|STAREG, SAREG|STAREG,
	SAREG|STAREG, SAREG|STAREG, SAREG|STAREG, SAREG|STAREG,
	SAREG, SAREG, SAREG, SAREG, SAREG, SAREG,
	SAREG, SAREG, SAREG, SAREG,
D 31

E 31
	};

tlen(p) NODE *p;
{
	switch(p->in.type) {
		case CHAR:
		case UCHAR:
			return(1);

		case SHORT:
		case USHORT:
D 33
			return(2);
E 33
I 33
			return(SZSHORT/SZCHAR);
E 33

		case DOUBLE:
D 33
			return(8);
E 33
I 33
			return(SZDOUBLE/SZCHAR);
E 33

		default:
D 33
			return(4);
E 33
I 33
			return(SZINT/SZCHAR);
E 33
		}
}

mixtypes(p, q) NODE *p, *q;
{
D 2
	register tp, tq;
E 2
I 2
	register TWORD tp, tq;
E 2

	tp = p->in.type;
	tq = q->in.type;

	return( (tp==FLOAT || tp==DOUBLE) !=
		(tq==FLOAT || tq==DOUBLE) );
}

prtype(n) NODE *n;
{
	switch (n->in.type)
		{
I 31

E 31
		case DOUBLE:
D 14
			printf("d");
E 14
I 14
			putchar('d');
E 14
			return;

		case FLOAT:
D 14
			printf("f");
E 14
I 14
			putchar('f');
E 14
			return;

		case LONG:
		case ULONG:
		case INT:
		case UNSIGNED:
D 14
			printf("l");
E 14
I 14
			putchar('l');
E 14
			return;

		case SHORT:
		case USHORT:
D 14
			printf("w");
E 14
I 14
			putchar('w');
E 14
			return;

		case CHAR:
		case UCHAR:
D 14
			printf("b");
E 14
I 14
			putchar('b');
E 14
			return;

		default:
			if ( !ISPTR( n->in.type ) ) cerror("zzzcode- bad type");
			else {
D 14
				printf("l");
E 14
I 14
				putchar('l');
E 14
				return;
				}
		}
}

zzzcode( p, c ) register NODE *p; {
D 31
	register m;
E 31
I 31
	register int m;
E 31
D 20
	CONSZ val;
E 20
I 20
	int val;
E 20
	switch( c ){

	case 'N':  /* logical ops, turned into 0-1 */
		/* use register given by register 1 */
		cbgen( 0, m=getlab(), 'I' );
		deflab( p->bn.label );
		printf( "	clrl	%s\n", rnames[getlr( p, '1' )->tn.rval] );
		deflab( m );
		return;

D 31
	case 'I':
E 31
	case 'P':
		cbgen( p->in.op, p->bn.label, c );
		return;

	case 'A':
D 31
		{
		register NODE *l, *r;

		if (xdebug) eprint(p, 0, &val, &val);
		r = getlr(p, 'R');
D 2
		if (optype(p->in.op) == LTYPE || p->in.op == UNARY MUL)
E 2
I 2
		if (p->in.op == ASSIGN)
			l = getlr(p, 'L');
D 5
		else if (p->in.op == SCONV)
E 2
			{
E 5
I 5
		else if (p->in.op == SCONV) {
E 5
			l = resc;
D 2
			l->in.type = (r->in.type==FLOAT || r->in.type==DOUBLE ? DOUBLE : INT);
E 2
I 2
D 8
#ifdef FORT
E 8
I 8
#if defined(FORT) || defined(SPRECC)
E 8
			l->in.type = r->in.type;
#else
			l->in.type = r->in.type==FLOAT ? DOUBLE : r->in.type;
#endif
			r = getlr(p, 'L');
E 2
			}
D 5
		else
D 2
			l = getlr(p, 'L');
E 2
I 2
			{		/* OPLTYPE */
E 5
I 5
		else {		/* OPLTYPE */
E 5
			l = resc;
D 8
#ifdef FORT
E 8
I 8
#if defined(FORT) || defined(SPRECC)
E 8
			l->in.type = (r->in.type==FLOAT || r->in.type==DOUBLE ? r->in.type : INT);
#else
			l->in.type = (r->in.type==FLOAT || r->in.type==DOUBLE ? DOUBLE : INT);
#endif
			}
E 2
		if (r->in.op == ICON)
D 2
			if(r->in.name[0] == '\0')
E 2
I 2
D 5
			if (r->in.name[0] == '\0')
E 2
				{
				if (r->tn.lval == 0)
					{
E 5
I 5
			if (r->in.name[0] == '\0') {
				if (r->tn.lval == 0) {
E 5
D 14
					printf("clr");
E 14
I 14
					putstr("clr");
E 14
					prtype(l);
D 14
					printf("	");
E 14
I 14
					putchar('\t');
E 14
					adrput(l);
					return;
					}
D 5
				if (r->tn.lval < 0 && r->tn.lval >= -63)
					{
E 5
I 5
				if (r->tn.lval < 0 && r->tn.lval >= -63) {
E 5
D 14
					printf("mneg");
E 14
I 14
					putstr("mneg");
E 14
					prtype(l);
					r->tn.lval = -r->tn.lval;
					goto ops;
					}
D 5
				r->in.type = (r->tn.lval < 0 ?
						(r->tn.lval >= -128 ? CHAR
E 5
I 5
				if (r->tn.lval < 0)
					r->in.type = r->tn.lval >= -128 ? CHAR
E 5
						: (r->tn.lval >= -32768 ? SHORT
D 5
						: INT )) : r->in.type);
				r->in.type = (r->tn.lval >= 0 ?
						(r->tn.lval <= 63 ? INT
						: ( r->tn.lval <= 127 ? CHAR
E 5
I 5
						: INT);
				else if (l->in.type == FLOAT ||
				    l->in.type == DOUBLE)
					r->in.type = r->tn.lval <= 63 ? INT
						: (r->tn.lval <= 127 ? CHAR
						: (r->tn.lval <= 32767 ? SHORT
						: INT));
				else
					r->in.type = r->tn.lval <= 63 ? INT
						: (r->tn.lval <= 127 ? CHAR
E 5
						: (r->tn.lval <= 255 ? UCHAR
						: (r->tn.lval <= 32767 ? SHORT
						: (r->tn.lval <= 65535 ? USHORT
D 5
						: INT ))))) : r->in.type );
E 5
I 5
						: INT))));
E 5
				}
D 2
				else
					{
					printf("moval");
					printf("	");
					acon(r);
					printf(",");
					adrput(l);
					return;
					}
E 2
I 2
D 5
			else
				{
E 5
I 5
			else {
E 5
D 14
				printf("moval");
				printf("	");
E 14
I 14
				putstr("moval");
				putchar('\t');
E 14
				acon(r);
D 14
				printf(",");
E 14
I 14
				putchar(',');
E 14
				adrput(l);
				return;
				}
E 2

D 5
		if (l->in.op == REG && l->in.type != FLOAT && l->in.type != DOUBLE)
			{
D 2
			if( tlen(l) < tlen(r) )
E 2
I 2
			if (tlen(l) < tlen(r) && !mixtypes(l,r))
E 2
				{
E 5
I 5
D 12
		if (l->in.op == REG && l->in.type != FLOAT && l->in.type != DOUBLE) {
			if (tlen(l) < tlen(r) && !mixtypes(l,r)) {
E 5
D 2
				if (!mixtypes(l,r))
					{
					!ISUNSIGNED(l->in.type)?
						printf("cvt"):
						printf("movz");
					prtype(l);
					printf("l");
					goto ops;
					}
E 2
I 2
				if (ISUNSIGNED(l->in.type))
E 12
I 12
		if (p->in.op == SCONV &&
		    !(l->in.type == FLOAT || l->in.type == DOUBLE) &&
		    !mixtypes(l, r)) {
			/*
			 * Because registers must always contain objects
			 * of the same width as INTs, we may have to
			 * perform two conversions to get an INT.  Can
			 * the conversions be collapsed into one?
			 */
			if (m = collapsible(l, r))
				r->in.type = m;
			else {
				/*
				 * Two steps are required.
				 */
				NODE *x = &resc[1];

				*x = *l;
				if (tlen(x) > tlen(r) && ISUNSIGNED(r->in.type))
E 12
D 14
					printf("movz");
E 14
I 14
					putstr("movz");
E 14
E 2
				else
D 2
					{
E 2
D 14
					printf("cvt");
E 14
I 14
					putstr("cvt");
E 14
D 2
					prtype(r);
					prtype(l);
					printf("	");
					adrput(r);
					printf(",");
					adrput(l);
					printf("cvt");
					prtype(l);
					printf("l");
					printf("	");
					adrput(l);
					printf(",");
					adrput(l);
					return;
					}
E 2
I 2
D 12
				prtype(l);
				printf("l");
				goto ops;
E 12
I 12
				prtype(r);
				prtype(x);
D 14
				printf("\t");
E 14
I 14
				putchar('\t');
E 14
				adrput(r);
D 14
				printf(",");
E 14
I 14
				putchar(',');
E 14
				adrput(x);
D 14
				printf("\n\t");
E 14
I 14
				putchar('\n');
				putchar('\t');
E 14
				r = x;
E 12
E 2
				}
D 12
			else
D 2
				{
			l->in.type = INT;
				}
E 2
I 2
				l->in.type = INT;
E 12
I 12
			l->in.type = (ISUNSIGNED(l->in.type) ? UNSIGNED : INT);
E 12
E 2
			}
I 12

I 15
		if ((r->in.type == UNSIGNED || r->in.type == ULONG) &&
		    mixtypes(l, r)) {
			int label1, label2;

			label1 = getlab();
			label2 = getlab();

			putstr("movl\t");
			adrput(r);
			putchar(',');
			adrput(l);
D 16
			putstr("\n\tbbsc\t$31,");
E 16
I 16
			putstr("\n\tjbsc\t$31,");
E 16
			adrput(l);
			printf(",L%d\n\tcvtl", label1);
			prtype(l);
			putchar('\t');
			adrput(l);
			putchar(',');
			adrput(l);
			printf("\n\tjbr\tL%d\nL%d:\n\tcvtl", label2, label1);
			prtype(l);
			putchar('\t');
			adrput(l);
			putchar(',');
			adrput(l);
			putstr("\n\tadd");
			prtype(l);
			putstr("2\t$0");
			prtype(l);
			putstr("2.147483648e9,");
			adrput(l);
			printf("\nL%d:", label2);

			return;
			}

E 15
E 12
D 5
		if (!mixtypes(l,r))
			{
			if (tlen(l) == tlen(r))
				{
E 5
I 5
		if (!mixtypes(l,r)) {
			if (tlen(l) == tlen(r)) {
E 5
D 14
				printf("mov");
E 14
I 14
				putstr("mov");
E 14
I 8
#ifdef FORT
				if (Oflag)
					prtype(l);
				else {
					if (l->in.type == DOUBLE)
D 14
						printf("q");
E 14
I 14
						putchar('q');
E 14
					else if(l->in.type == FLOAT)
D 14
						printf("l");
E 14
I 14
						putchar('l');
E 14
					else
						prtype(l);
					}
#else
E 8
				prtype(l);
I 8
#endif FORT
E 8
				goto ops;
				}
			else if (tlen(l) > tlen(r) && ISUNSIGNED(r->in.type))
D 5
				{
E 5
D 14
				printf("movz");
E 14
I 14
				putstr("movz");
E 14
D 5
				}
E 5
			else
D 5
				{
E 5
D 14
				printf("cvt");
E 14
I 14
				putstr("cvt");
E 14
D 5
				}
E 5
			}
		else
D 5
			{
E 5
D 14
			printf("cvt");
E 14
I 14
			putstr("cvt");
E 14
D 5
			}
E 5
		prtype(r);
		prtype(l);
	ops:
D 14
		printf("	");
E 14
I 14
		putchar('\t');
E 14
		adrput(r);
D 14
		printf(",");
E 14
I 14
		putchar(',');
E 14
		adrput(l);
E 31
I 31
	case 'V':
		sconv( p, c == 'V' );
E 31
		return;
D 31
		}
E 31

I 15
	case 'G':	/* i *= f; asgops with int lhs and float rhs */
		{
		register NODE *l, *r, *s;
		int rt;

		l = p->in.left;
		r = p->in.right;
		s = talloc();
		rt = r->in.type;

		s->in.op = SCONV;
		s->in.left = l;
		s->in.type = rt;
		zzzcode(s, 'A');
		putstr("\n\t");

		hopcode(rt == FLOAT ? 'F' : 'D', p->in.op);
		putstr("2\t");
		adrput(r);
		putchar(',');
		adrput(resc);
		putstr("\n\t");

		s->in.op = ASSIGN;
		s->in.left = l;
		s->in.right = resc;
		s->in.type = l->in.type;
		zzzcode(s, 'A');

		s->in.op = FREE;
		return;
		}

I 24
	case 'J':	/* unsigned DIV/MOD with constant divisors */
		{
		register int ck = INAREG;
		int label1, label2;

		/* case constant <= 1 is handled by optim() in pass 1 */
		/* case constant < 0x80000000 is handled in table */
		switch( p->in.op ) {
D 34
		/* case DIV: handled in hardops() */
E 34
I 34
		/* case DIV: handled in optim2() */
E 34
		case MOD:
			if( p->in.left->in.op == REG &&
			    p->in.left->tn.rval == resc->tn.rval )
				goto asgmod;
			label1 = getlab();
			expand(p, ck, "movl\tAL,A1\n\tcmpl\tA1,AR\n");
			printf("\tjlssu\tL%d\n", label1);
			expand(p, ck, "\tsubl2\tAR,A1\n");
			printf("L%d:", label1);
			break;
		case ASG DIV:
			label1 = getlab();
			label2 = getlab();
			expand(p, ck, "cmpl\tAL,AR\n");
			printf("\tjgequ\tL%d\n", label1);
			expand(p, ck, "\tmovl\t$1,AL\n");
			printf("\tjbr\tL%d\nL%d:\n", label2, label1);
			expand(p, ck, "\tclrl\tAL\n");
			printf("L%d:", label2);
			break;
		case ASG MOD:
		asgmod:
			label1 = getlab();
			expand(p, ck, "cmpl\tAL,AR\n");
			printf("\tjlssu\tL%d\n", label1);
			expand(p, ck, "\tsubl2\tAR,AL\n");
			printf("L%d:", label1);
			break;
			}
		return;
		}

E 24
E 15
	case 'B':	/* get oreg value in temp register for left shift */
		{
		register NODE *r;
		if (xdebug) eprint(p, 0, &val, &val);
		r = p->in.right;
D 33
		if( tlen(r) == sizeof(int) && r->in.type != FLOAT )
E 33
I 33
		if( tlen(r) == SZINT/SZCHAR && r->in.type != FLOAT )
E 33
D 14
			printf("movl");
E 14
I 14
			putstr("movl");
E 14
		else {
D 14
			printf("cvt");
E 14
I 14
D 31
			putstr("cvt");
E 31
I 31
			putstr(ISUNSIGNED(r->in.type) ? "movz" : "cvt");
E 31
E 14
			prtype(r);
D 14
			printf("l");
E 14
I 14
			putchar('l');
E 14
			}
		return;
		}

	case 'C':	/* num words pushed on arg stack */
		{
		extern int gc_numbytes;
		extern int xdebug;

		if (xdebug) printf("->%d<-",gc_numbytes);

		printf("$%d", gc_numbytes/(SZLONG/SZCHAR) );
		return;
		}

	case 'D':	/* INCR and DECR */
		zzzcode(p->in.left, 'A');
D 14
		printf("\n	");
E 14
I 14
		putchar('\n');
		putchar('\t');
E 14

	case 'E':	/* INCR and DECR, FOREFF */
D 30
		if (p->in.right->tn.lval == 1)
E 30
I 30
		if (p->in.right->in.op == ICON && p->in.right->tn.lval == 1)
E 30
			{
D 14
			printf("%s", (p->in.op == INCR ? "inc" : "dec") );
E 14
I 14
D 31
			putstr( p->in.op == INCR ? "inc" : "dec" );
E 31
I 31
			putstr(p->in.op == INCR ? "inc" : "dec");
E 31
E 14
			prtype(p->in.left);
D 14
			printf("	");
E 14
I 14
			putchar('\t');
E 14
			adrput(p->in.left);
			return;
			}
D 14
		printf("%s", (p->in.op == INCR ? "add" : "sub") );
E 14
I 14
D 31
		putstr( p->in.op == INCR ? "add" : "sub" );
E 31
I 31
		putstr(p->in.op == INCR ? "add" : "sub");
E 31
E 14
		prtype(p->in.left);
D 14
		printf("2	");
E 14
I 14
		putchar('2');
		putchar('\t');
E 14
		adrput(p->in.right);
D 14
		printf(",");
E 14
I 14
		putchar(',');
E 14
		adrput(p->in.left);
		return;

	case 'F':	/* register type of right operand */
		{
		register NODE *n;
		extern int xdebug;
		register int ty;

		n = getlr( p, 'R' );
		ty = n->in.type;

		if (xdebug) printf("->%d<-", ty);

D 14
		if ( ty==DOUBLE) printf("d");
		else if ( ty==FLOAT ) printf("f");
		else printf("l");
E 14
I 14
		if ( ty==DOUBLE) putchar('d');
		else if ( ty==FLOAT ) putchar('f');
		else putchar('l');
E 14
		return;
		}

	case 'L':	/* type of left operand */
	case 'R':	/* type of right operand */
		{
		register NODE *n;
		extern int xdebug;

D 2
		n = getlr ( p, c);
E 2
I 2
		n = getlr( p, c );
E 2
		if (xdebug) printf("->%d<-", n->in.type);

		prtype(n);
		return;
		}

D 34
	case 'Z':	/* complement mask for bit instr */
		printf("$%ld", ~p->in.right->tn.lval);
E 34
I 34
	case 'Z':	/* AND for CC with ICON -- lval is complemented */
		{
		register NODE *l, *r;

		l = getlr( p, 'L' );
		r = getlr( p, 'R' );
		m = (1 << tlen(l) * SZCHAR) - 1;
		r->tn.lval = ~r->tn.lval;
		if( (l->in.type == CHAR || l->in.type == SHORT) &&
		    (r->tn.lval & ~m) ) {
			putstr("cvt");
			prtype(l);
			putstr("l\t");
			adrput(l);
			putchar(',');
			adrput(resc);
			putstr("\n\t");
			resc->tn.type = INT;
			l = resc;
			}
		else if( l->in.type == UCHAR || l->in.type == USHORT )
			/* remove trash left over from complementing */
			r->tn.lval &= m;
		putstr("bit");
		prtype(l);
		printf("\t$%ld", r->tn.lval);
		putchar(',');
		adrput(l);
E 34
		return;
I 34
		}
E 34

	case 'U':	/* 32 - n, for unsigned right shifts */
		printf("$%d", 32 - p->in.right->tn.lval );
		return;

	case 'T':	/* rounded structure length for arguments */
		{
		int size;

		size = p->stn.stsize;
		SETOFF( size, 4);
		printf("$%d", size);
		return;
		}

	case 'S':  /* structure assignment */
D 31
		{
			register NODE *l, *r;
			register size;
E 31
I 31
		stasg(p);
		break;
E 31

D 31
			if( p->in.op == STASG ){
				l = p->in.left;
				r = p->in.right;
E 31
I 31
	default:
		cerror( "illegal zzzcode" );
		}
	}
E 31

D 31
				}
			else if( p->in.op == STARG ){  /* store an arg into a temporary */
D 3
				l = getlr( p, '3' );
E 3
				r = p->in.left;
				}
			else cerror( "STASG bad" );
E 31
I 31
stasg(p)
	register NODE *p;
{
	register NODE *l, *r;
	register size;
E 31

D 31
			if( r->in.op == ICON ) r->in.op = NAME;
			else if( r->in.op == REG ) r->in.op = OREG;
			else if( r->in.op != OREG ) cerror( "STASG-r" );
E 31
I 31
	if( p->in.op == STASG ){
		l = p->in.left;
		r = p->in.right;

		}
	else if( p->in.op == STARG ){  /* store an arg into a temporary */
		r = p->in.left;
		}
	else cerror( "STASG bad" );

	if( r->in.op == ICON ) r->in.op = NAME;
	else if( r->in.op == REG ) r->in.op = OREG;
	else if( r->in.op != OREG ) cerror( "STASG-r" );

	size = p->stn.stsize;

	if( size <= 0 || size > 65535 )
		cerror("structure size <0=0 or >65535");

	switch(size) {
		case 1:
			putstr("	movb	");
			break;
		case 2:
			putstr("	movw	");
			break;
		case 4:
			putstr("	movl	");
			break;
		case 8:
			putstr("	movq	");
			break;
		default:
			printf("	movc3	$%d,", size);
			break;
	}
	adrput(r);
	if( p->in.op == STASG ){
		putchar(',');
		adrput(l);
		putchar('\n');
		}
	else
		putstr(",(sp)\n");
E 31

D 31
			size = p->stn.stsize;
E 31
I 31
	if( r->in.op == NAME ) r->in.op = ICON;
	else if( r->in.op == OREG ) r->in.op = REG;
	}
E 31

D 31
			if( size <= 0 || size > 65535 )
				cerror("structure size <0=0 or >65535");
E 31
I 31
NODE *makearg( ty ) int ty; {
	register NODE *p, *q;
E 31

D 31
			switch(size) {
				case 1:
D 14
					printf("	movb	");
E 14
I 14
					putstr("	movb	");
E 14
					break;
				case 2:
D 14
					printf("	movw	");
E 14
I 14
					putstr("	movw	");
E 14
					break;
				case 4:
D 14
					printf("	movl	");
E 14
I 14
					putstr("	movl	");
E 14
					break;
				case 8:
D 14
					printf("	movq	");
E 14
I 14
					putstr("	movq	");
E 14
					break;
				default:
					printf("	movc3	$%d,", size);
					break;
			}
			adrput(r);
D 3
			printf(",");
			adrput(l);
			printf("\n");
E 3
I 3
			if( p->in.op == STASG ){
D 14
				printf(",");
E 14
I 14
				putchar(',');
E 31
I 31
	/* build a -(sp) operand */
	p = talloc();
	p->in.op = REG;
	/* the type needn't be right, just consistent */
	p->in.type = INCREF(ty);
	p->tn.rval = SP;
	p->tn.lval = 0;
	q = talloc();
	q->in.op = ASG MINUS;
	q->in.type = INCREF(ty);
	q->in.left = p;
	p = talloc();
	p->in.op = ICON;
	p->in.type = INT;
	p->tn.name = "";
D 34
	p->tn.lval = tlen(ty);
E 34
I 34
D 37
	p->tn.lval = szty(ty) * (SZINT/SZCHAR);
E 37
I 37
	/* size of floating argument is always 2 */
	p->tn.lval = (1 + (ty == FLOAT || ty == DOUBLE)) * (SZINT/SZCHAR);
E 37
E 34
	q->in.right = p;
	p = talloc();
	p->in.op = UNARY MUL;
	p->in.left = q;
	return( p );
	}

sconv( p, forarg ) register NODE *p; {
	register NODE *l, *r;
	int m, val;

	if (xdebug) eprint(p, 0, &val, &val);
	r = getlr(p, 'R');
	if (p->in.op == ASSIGN)
		l = getlr(p, 'L');
	else if (p->in.op == SCONV) {
D 36
#if defined(FORT) || defined(SPRECC)
E 36
		m = r->in.type;
D 36
#else
		m = r->in.type==FLOAT ? DOUBLE : r->in.type;
#endif
E 36
		if (forarg)
			l = makearg( m );
		else
			l = resc;
		l->in.type = m;
		r = getlr(p, 'L');
		}
	else {		/* OPLTYPE */
D 36
#if defined(FORT) || defined(SPRECC)
E 36
		m = (r->in.type==FLOAT || r->in.type==DOUBLE ? r->in.type : INT);
D 36
#else
		m = (r->in.type==FLOAT || r->in.type==DOUBLE ? DOUBLE : INT);
#endif
E 36
		if (forarg)
			l = makearg( m );
		else
			l = resc;
		l->in.type = m;
		}
	if (r->in.op == ICON)
		if (r->in.name[0] == '\0') {
D 34
			if (r->tn.lval == 0) {
E 34
I 34
D 38
			if (r->tn.lval == 0 && !forarg) {
E 38
I 38
			if (r->tn.lval == 0 &&
			    (r->in.type == DOUBLE || r->in.type == FLOAT ||
			    !forarg)) {
				if (r->in.type == FLOAT)
					r->in.type = DOUBLE;
E 38
E 34
				putstr("clr");
				prtype(l);
				putchar('\t');
E 31
E 14
				adrput(l);
D 14
				printf("\n");
E 14
I 14
D 31
				putchar('\n');
E 31
I 31
				goto cleanup;
E 31
E 14
				}
I 31
			if (r->tn.lval < 0 && r->tn.lval >= -63) {
				putstr("mneg");
				prtype(l);
				r->tn.lval = -r->tn.lval;
				goto ops;
				}
			if (r->tn.lval < 0)
				r->in.type = r->tn.lval >= -128 ? CHAR
					: (r->tn.lval >= -32768 ? SHORT
					: INT);
			else if (l->in.type == FLOAT ||
			    l->in.type == DOUBLE)
				r->in.type = r->tn.lval <= 63 ? INT
					: (r->tn.lval <= 127 ? CHAR
					: (r->tn.lval <= 32767 ? SHORT
					: INT));
E 31
			else
D 14
				printf(",(sp)\n");
E 14
I 14
D 31
				putstr(",(sp)\n");
E 31
I 31
				r->in.type = r->tn.lval <= 63 ? INT
					: (r->tn.lval <= 127 ? CHAR
					: (r->tn.lval <= 255 ? UCHAR
					: (r->tn.lval <= 32767 ? SHORT
					: (r->tn.lval <= 65535 ? USHORT
					: INT))));
I 34
			if (forarg && r->in.type == INT) {
				putstr("pushl\t");
				adrput(r);
				goto cleanup;
				}
E 34
			}
		else {
D 34
			putstr("moval");
			putchar('\t');
E 34
I 34
			if (forarg && tlen(r) == SZINT/SZCHAR) {
				putstr("pushl\t");
				adrput(r);
				goto cleanup;
				}
			putstr("moval\t");
E 34
			acon(r);
			putchar(',');
			adrput(l);
			goto cleanup;
			}
E 31
E 14
E 3

D 31
			if( r->in.op == NAME ) r->in.op = ICON;
			else if( r->in.op == OREG ) r->in.op = REG;
E 31
I 31
	if (p->in.op == SCONV &&
	    !(l->in.type == FLOAT || l->in.type == DOUBLE) &&
	    !mixtypes(l, r)) {
		/*
		 * Because registers must always contain objects
		 * of the same width as INTs, we may have to
		 * perform two conversions to get an INT.  Can
		 * the conversions be collapsed into one?
		 */
		if (m = collapsible(l, r))
			r->in.type = m;
		else {
D 39
			/*
			 * Two steps are required.
			 */
E 39
I 39
			/* two steps are required */
E 39
D 36
			NODE *x = &resc[1];
E 36
I 36
			NODE *x;
E 36
E 31

I 31
D 36
			*x = *l;
E 36
I 36
			if (forarg) {
				x = resc;
				x->in.type = l->in.type;
				}
			else {
				x = &resc[1];
				*x = *l;
				}

E 36
			if (tlen(x) > tlen(r) && ISUNSIGNED(r->in.type))
				putstr("movz");
			else
				putstr("cvt");
			prtype(r);
			prtype(x);
			putchar('\t');
			adrput(r);
			putchar(',');
			adrput(x);
			putchar('\n');
			putchar('\t');
			r = x;
E 31
			}
D 31
		break;
E 31
I 31
		l->in.type = (ISUNSIGNED(l->in.type) ? UNSIGNED : INT);
		}
E 31

D 31
	default:
		cerror( "illegal zzzcode" );
E 31
I 31
D 39
	if ((r->in.type == UNSIGNED || r->in.type == ULONG) &&
E 39
I 39
	else if ((forarg || l == resc) &&
		 tlen(l) < SZINT/SZCHAR &&
		 mixtypes(l, r)) {
		/* two steps needed here too */
		NODE *x;

		if (forarg) {
			x = resc;
			x->in.type = l->in.type;
			}
		else {
			x = &resc[1];
			*x = *l;
			}
		putstr("cvt");
		prtype(r);
		prtype(x);
		putchar('\t');
		adrput(r);
		putchar(',');
		adrput(x);
		putstr("\n\t");
		r = x;
		l->in.type = (ISUNSIGNED(l->in.type) ? UNSIGNED : INT);
		}

	else if ((r->in.type == UNSIGNED || r->in.type == ULONG) &&
E 39
	    mixtypes(l, r)) {
D 41
		int label1, label2;
E 41
I 41
		int label1;
E 41
I 36
		NODE *x = NULL;
E 36

I 36
#if defined(FORT) || defined(SPRECC)
		if (forarg)
#else
		if (forarg || l == resc)
#endif
			{
			/* compute in register, convert to double when done */
			x = l;
			l = resc;
			l->in.type = x->in.type;
			}

E 36
		label1 = getlab();
D 41
		label2 = getlab();
E 41

D 41
		putstr("movl\t");
		adrput(r);
		putchar(',');
		adrput(l);
		putstr("\n\tjbsc\t$31,");
		adrput(l);
		printf(",L%d\n\tcvtl", label1);
E 41
I 41
		putstr("cvtl");
E 41
		prtype(l);
		putchar('\t');
D 41
		adrput(l);
E 41
I 41
		adrput(r);
E 41
		putchar(',');
		adrput(l);
D 41
		printf("\n\tjbr\tL%d\nL%d:\n\tcvtl", label2, label1);
E 41
I 41
		printf("\n\tjgeq\tL%d\n\tadd", label1);
E 41
		prtype(l);
D 41
		putchar('\t');
		adrput(l);
		putchar(',');
		adrput(l);
		putstr("\n\tadd");
		prtype(l);
E 41
		putstr("2\t$0");
		prtype(l);
D 41
		putstr("2.147483648e9,");
E 41
I 41
		putstr("4.294967296e9,");
E 41
		adrput(l);
D 41
		printf("\nL%d:", label2);
E 41
I 41
		printf("\nL%d:", label1);
E 41

I 39
#if defined(FORT) || defined(SPRECC)
		if (!forarg)
#else
E 39
D 36
		goto cleanup;
E 36
I 36
		if (!forarg && (l->in.type == DOUBLE || l != resc))
I 39
#endif
E 39
			goto cleanup;
D 39
		if (x != NULL) {
			if (l == x) {
				r = &resc[1];
				*r = *l;
				}
			else {
				r = l;
				l = x;
				}
			l->in.type = DOUBLE;
E 39
I 39
		if (x == NULL)
			cerror("sconv botch");
		if (l == x) {
			r = &resc[1];
			*r = *l;
E 39
			}
I 39
		else {
			r = l;
			l = x;
			}
		l->in.type = DOUBLE;
E 39
		putstr("\n\t");
E 36
E 31
		}
I 31

I 36
D 39
	if( (l->in.type == FLOAT || l->in.type == DOUBLE) &&
E 39
I 39
	else if( (l->in.type == FLOAT || l->in.type == DOUBLE) &&
E 39
	    (r->in.type == UCHAR || r->in.type == USHORT) ) {
		/* skip unnecessary unsigned to floating conversion */
#if defined(FORT) || defined(SPRECC)
		if (forarg)
#else
		if (forarg || l == resc)
#endif
			l->in.type = DOUBLE;
		putstr("movz");
		prtype(r);
		putstr("l\t");
		adrput(r);
		putchar(',');
		adrput(resc);
		putstr("\n\t");
		if (l == resc) {
			r = &resc[1];
			*r = *l;
			}
		else
			r = resc;
		r->in.type = INT;
		}

#if defined(FORT) || defined(SPRECC)
	if (forarg && l->in.type == FLOAT)
#else
	if ((forarg || l == resc) && l->in.type == FLOAT)
#endif
		{
		/* perform an implicit conversion to double */
		l->in.type = DOUBLE;
		if (r->in.type != FLOAT &&
		    r->in.type != CHAR &&
		    r->in.type != SHORT) {
			/* trim bits from the mantissa */
			putstr("cvt");
			prtype(r);
			putstr("f\t");
			adrput(r);
			putchar(',');
			adrput(resc);
			putstr("\n\t");
			if (l == resc) {
				r = &resc[1];
				*r = *l;
				}
			else
				r = resc;
			r->in.type = FLOAT;
			}
		}

E 36
	if (!mixtypes(l,r)) {
		if (tlen(l) == tlen(r)) {
I 34
			if (forarg && tlen(l) == SZINT/SZCHAR) {
				putstr("pushl\t");
				adrput(r);
				goto cleanup;
				}
E 34
			putstr("mov");
#ifdef FORT
			if (Oflag)
				prtype(l);
			else {
				if (l->in.type == DOUBLE)
					putchar('q');
				else if(l->in.type == FLOAT)
					putchar('l');
				else
					prtype(l);
				}
#else
			prtype(l);
#endif FORT
			goto ops;
			}
		else if (tlen(l) > tlen(r) && ISUNSIGNED(r->in.type))
			putstr("movz");
		else
			putstr("cvt");
		}
	else
		putstr("cvt");
	prtype(r);
	prtype(l);
ops:
	putchar('\t');
	adrput(r);
	putchar(',');
	adrput(l);

cleanup:
	if (forarg)
		tfree(l);
E 31
I 12
	}

/*
 * collapsible(dest, src) -- if a conversion with a register destination
 *	can be accomplished in one instruction, return the type of src
 *	that will do the job correctly; otherwise return 0.  Note that
 *	a register must always end up having type INT or UNSIGNED.
 */
int
collapsible(dest, src)
NODE *dest, *src;
{
	int st = src->in.type;
	int dt = dest->in.type;
	int newt = 0;

	/*
	 * Are there side effects of evaluating src?
	 * If the derived type will not be the same size as src,
D 14
	 * we have to use two steps.
E 14
I 14
	 * we may have to use two steps.
E 14
	 */
D 14
	if (tlen(src) > tlen(dest) && tshape(src, STARREG))
		return (0);
E 14
I 14
	if (tlen(src) > tlen(dest)) {
		if (tshape(src, STARREG))
			return (0);
		if (src->in.op == OREG && R2TEST(src->tn.rval))
			return (0);
		}
E 14

	/*
	 * Can we get an object of dest's type by punning src?
	 * Praises be to great Cthulhu for little-endian machines...
	 */
	if (st == CHAR && dt == USHORT)
		/*
		 * Special case -- we must sign-extend to 16 bits.
		 */
		return (0);

	if (tlen(src) < tlen(dest))
		newt = st;
	else
		newt = dt;

	return (newt);
E 12
	}

D 8
rmove( rt, rs, t ){
E 8
I 8
rmove( rt, rs, t ) TWORD t; {
E 8
	printf( "	%s	%s,%s\n",
I 8
#ifdef FORT
		!Oflag ? (t==DOUBLE ? "movq" : "movl") :
#endif
E 8
		(t==FLOAT ? "movf" : (t==DOUBLE ? "movd" : "movl")),
		rnames[rs], rnames[rt] );
	}

struct respref
respref[] = {
	INTAREG|INTBREG,	INTAREG|INTBREG,
	INAREG|INBREG,	INAREG|INBREG|SOREG|STARREG|STARNM|SNAME|SCON,
	INTEMP,	INTEMP,
	FORARG,	FORARG,
	INTEMP,	INTAREG|INAREG|INTBREG|INBREG|SOREG|STARREG|STARNM,
	0,	0 };

setregs(){ /* set up temporary registers */
	fregs = 6;	/* tbl- 6 free regs on VAX (0-5) */
D 31
	;
E 31
	}

I 20
/*ARGSUSED*/
E 20
D 8
szty(t){ /* size, in registers, needed to hold thing of type t */
I 2
#ifdef FORT
E 8
I 8
D 14
szty(t) TWORD t; { /* size, in registers, needed to hold thing of type t */
#if defined(FORT) || defined(SPRECC)
E 8
	return( (t==DOUBLE) ? 2 : 1 );
#else
E 2
	return( (t==DOUBLE||t==FLOAT) ? 2 : 1 );
I 2
#endif
E 2
	}

E 14
rewfld( p ) NODE *p; {
	return(1);
	}

I 20
/*ARGSUSED*/
E 20
callreg(p) NODE *p; {
	return( R0 );
	}

base( p ) register NODE *p; {
	register int o = p->in.op;

D 34
	if( (o==ICON && p->in.name[0] != '\0')) return( 100 ); /* ie no base reg */
E 34
I 34
	if( o==ICON && p->tn.name[0] != '\0' ) return( 100 ); /* ie no base reg */
E 34
	if( o==REG ) return( p->tn.rval );
    if( (o==PLUS || o==MINUS) && p->in.left->in.op == REG && p->in.right->in.op==ICON)
		return( p->in.left->tn.rval );
    if( o==OREG && !R2TEST(p->tn.rval) && (p->in.type==INT || p->in.type==UNSIGNED || ISPTR(p->in.type)) )
		return( p->tn.rval + 0200*1 );
	if( o==INCR && p->in.left->in.op==REG ) return( p->in.left->tn.rval + 0200*2 );
	if( o==ASG MINUS && p->in.left->in.op==REG) return( p->in.left->tn.rval + 0200*4 );
	if( o==UNARY MUL && p->in.left->in.op==INCR && p->in.left->in.left->in.op==REG
	  && (p->in.type==INT || p->in.type==UNSIGNED || ISPTR(p->in.type)) )
		return( p->in.left->in.left->tn.rval + 0200*(1+2) );
I 34
	if( o==NAME ) return( 100 + 0200*1 );
E 34
	return( -1 );
	}

offset( p, tyl ) register NODE *p; int tyl; {

D 14
	if( tyl==1 && p->in.op==REG && (p->in.type==INT || p->in.type==UNSIGNED) ) return( p->tn.rval );
	if( (p->in.op==LS && p->in.left->in.op==REG && (p->in.left->in.type==INT || p->in.left->in.type==UNSIGNED) &&
	      (p->in.right->in.op==ICON && p->in.right->in.name[0]=='\0')
	      && (1<<p->in.right->tn.lval)==tyl))
E 14
I 14
	if( tyl==1 &&
	    p->in.op==REG &&
	    (p->in.type==INT || p->in.type==UNSIGNED) )
		return( p->tn.rval );
	if( p->in.op==LS &&
	    p->in.left->in.op==REG &&
	    (p->in.left->in.type==INT || p->in.left->in.type==UNSIGNED) &&
	    p->in.right->in.op==ICON &&
	    p->in.right->in.name[0]=='\0' &&
	    (1<<p->in.right->tn.lval)==tyl)
E 14
		return( p->in.left->tn.rval );
I 14
	if( tyl==2 &&
	    p->in.op==PLUS &&
	    (p->in.left->in.type==INT || p->in.left->in.type==UNSIGNED) &&
	    p->in.left->in.op==REG &&
	    p->in.right->in.op==REG &&
	    p->in.left->tn.rval==p->in.right->tn.rval )
		return( p->in.left->tn.rval );
E 14
	return( -1 );
	}

makeor2( p, q, b, o) register NODE *p, *q; register int b, o; {
	register NODE *t;
D 20
	register int i;
E 20
	NODE *f;

	p->in.op = OREG;
	f = p->in.left; 	/* have to free this subtree later */

	/* init base */
	switch (q->in.op) {
		case ICON:
		case REG:
		case OREG:
I 34
		case NAME:
E 34
			t = q;
			break;

		case MINUS:
			q->in.right->tn.lval = -q->in.right->tn.lval;
		case PLUS:
			t = q->in.right;
			break;

		case INCR:
		case ASG MINUS:
			t = q->in.left;
			break;

		case UNARY MUL:
			t = q->in.left->in.left;
			break;

		default:
			cerror("illegal makeor2");
	}

	p->tn.lval = t->tn.lval;
#ifndef FLEXNAMES
D 20
	for(i=0; i<NCHNAM; ++i)
		p->in.name[i] = t->in.name[i];
E 20
I 20
	{
		register int i;
		for(i=0; i<NCHNAM; ++i)
			p->in.name[i] = t->in.name[i];
	}
E 20
#else
	p->in.name = t->in.name;
#endif

	/* init offset */
	p->tn.rval = R2PACK( (b & 0177), o, (b>>7) );

	tfree(f);
	return;
	}

canaddr( p ) NODE *p; {
	register int o = p->in.op;

	if( o==NAME || o==REG || o==ICON || o==OREG || (o==UNARY MUL && shumul(p->in.left)) ) return(1);
	return(0);
	}

D 14
shltype( o, p ) register NODE *p; {
	return( o== REG || o == NAME || o == ICON || o == OREG || ( o==UNARY MUL && shumul(p->in.left)) );
	}

E 14
D 31
flshape( p ) register NODE *p; {
	return( p->in.op == REG || p->in.op == NAME || p->in.op == ICON ||
		(p->in.op == OREG && (!R2TEST(p->tn.rval) || tlen(p) == 1)) );
E 31
I 31
flshape( p ) NODE *p; {
	register int o = p->in.op;

	return( o == REG || o == NAME || o == ICON ||
		(o == OREG && (!R2TEST(p->tn.rval) || tlen(p) == 1)) );
E 31
	}

I 22
/* INTEMP shapes must not contain any temporary registers */
E 22
shtemp( p ) register NODE *p; {
I 22
	int r;

E 22
	if( p->in.op == STARG ) p = p->in.left;
D 22
	return( p->in.op==NAME || p->in.op ==ICON || p->in.op == OREG || (p->in.op==UNARY MUL && shumul(p->in.left)) );
E 22
I 22

	switch (p->in.op) {
	case REG:
		return( !istreg(p->tn.rval) );
	case OREG:
		r = p->tn.rval;
		if( R2TEST(r) ) {
			if( istreg(R2UPK1(r)) )
				return(0);
			r = R2UPK2(r);
			}
		return( !istreg(r) );
D 23
/*
E 23
	case UNARY MUL:
		p = p->in.left;
		return( p->in.op != UNARY MUL && shtemp(p) );
D 23
*/
E 23
		}

	if( optype( p->in.op ) != LTYPE ) return(0);
	return(1);
E 22
	}

shumul( p ) register NODE *p; {
D 31
	register o;
E 31
I 31
	register int o;
E 31
	extern int xdebug;

	if (xdebug) {
D 29
		 printf("\nshumul:op=%d,lop=%d,rop=%d", p->in.op, p->in.left->in.op, p->in.right->in.op);
		printf(" prname=%s,plty=%d, prlval=%D\n", p->in.right->in.name, p->in.left->in.type, p->in.right->tn.lval);
E 29
I 29
		int val;
		printf("shumul:\n");
		eprint(p, 0, &val, &val);
E 29
		}
D 29

E 29

	o = p->in.op;
	if( o == NAME || (o == OREG && !R2TEST(p->tn.rval)) || o == ICON ) return( STARNM );

	if( ( o == INCR || o == ASG MINUS ) &&
	    ( p->in.left->in.op == REG && p->in.right->in.op == ICON ) &&
	    p->in.right->in.name[0] == '\0' )
		{
D 6
		switch (p->in.left->in.type)
E 6
I 6
		switch (p->in.type)
E 6
			{
			case CHAR|PTR:
			case UCHAR|PTR:
				o = 1;
				break;

			case SHORT|PTR:
			case USHORT|PTR:
				o = 2;
				break;

			case INT|PTR:
			case UNSIGNED|PTR:
			case LONG|PTR:
			case ULONG|PTR:
			case FLOAT|PTR:
				o = 4;
				break;

			case DOUBLE|PTR:
				o = 8;
				break;

			default:
D 6
				if ( ISPTR(p->in.left->in.type) ) {
E 6
I 6
D 8
				if ( ISPTR(p->in.type) ) {
E 8
I 8
				if ( ISPTR(p->in.type) &&
				     ISPTR(DECREF(p->in.type)) ) {
E 8
E 6
					o = 4;
					break;
					}
				else return(0);
			}
		return( p->in.right->tn.lval == o ? STARREG : 0);
		}

	return( 0 );
	}

adrcon( val ) CONSZ val; {
D 14
	printf( "$" );
E 14
I 14
	putchar( '$' );
E 14
	printf( CONFMT, val );
	}

conput( p ) register NODE *p; {
	switch( p->in.op ){

	case ICON:
		acon( p );
		return;

	case REG:
D 14
		printf( "%s", rnames[p->tn.rval] );
E 14
I 14
		putstr( rnames[p->tn.rval] );
E 14
		return;

	default:
		cerror( "illegal conput" );
		}
	}

I 19
/*ARGSUSED*/
E 19
D 20
insput( p ) register NODE *p; {
E 20
I 20
insput( p ) NODE *p; {
E 20
	cerror( "insput" );
	}

D 17
upput( p ) register NODE *p; {
E 17
I 17
D 18
upput( p, off ) register NODE *p; int off; {
E 18
I 18
D 19
upput( p ) register NODE *p; {
E 19
I 19
D 24
/*ARGSUSED*/
D 20
upput( p, off ) register NODE *p; int off; {
E 20
I 20
upput( p, off ) NODE *p; int off; {
E 24
I 24
upput( p, size ) NODE *p; int size; {
	if( size == SZLONG && p->in.op == REG ) {
		putstr( rnames[p->tn.rval + 1] );
		return;
		}
E 24
E 20
E 19
E 18
E 17
	cerror( "upput" );
	}

adrput( p ) register NODE *p; {
	register int r;
	/* output an address, with offsets, from p */

	if( p->in.op == FLD ){
		p = p->in.left;
		}
	switch( p->in.op ){

	case NAME:
		acon( p );
		return;

	case ICON:
		/* addressable value of the constant */
D 14
		printf( "$" );
E 14
I 14
		putchar( '$' );
E 14
		acon( p );
		return;

	case REG:
D 14
		printf( "%s", rnames[p->tn.rval] );
E 14
I 14
		putstr( rnames[p->tn.rval] );
E 14
		return;

	case OREG:
		r = p->tn.rval;
		if( R2TEST(r) ){ /* double indexing */
			register int flags;

			flags = R2UPK3(r);
D 14
			if( flags & 1 ) printf("*");
			if( flags & 4 ) printf("-");
E 14
I 14
			if( flags & 1 ) putchar('*');
			if( flags & 4 ) putchar('-');
E 14
			if( p->tn.lval != 0 || p->in.name[0] != '\0' ) acon(p);
			if( R2UPK1(r) != 100) printf( "(%s)", rnames[R2UPK1(r)] );
D 14
			if( flags & 2 ) printf("+");
E 14
I 14
			if( flags & 2 ) putchar('+');
E 14
			printf( "[%s]", rnames[R2UPK2(r)] );
			return;
			}
		if( r == AP ){  /* in the argument region */
D 21
			if( p->tn.lval <= 0 || p->in.name[0] != '\0' ) werror( "bad arg temp" );
E 21
I 21
			if( p->in.name[0] != '\0' ) werror( "bad arg temp" );
E 21
			printf( CONFMT, p->tn.lval );
D 14
			printf( "(ap)" );
E 14
I 14
			putstr( "(ap)" );
E 14
			return;
			}
		if( p->tn.lval != 0 || p->in.name[0] != '\0') acon( p );
		printf( "(%s)", rnames[p->tn.rval] );
		return;

	case UNARY MUL:
		/* STARNM or STARREG found */
		if( tshape(p, STARNM) ) {
D 14
			printf( "*" );
E 14
I 14
			putchar( '*' );
E 14
			adrput( p->in.left);
			}
		else {	/* STARREG - really auto inc or dec */
			register NODE *q;

D 31
/* tbl
			p = p->in.left;
			p->in.left->in.op = OREG;
			if( p->in.op == INCR ) {
				adrput( p->in.left );
D 14
				printf( "+" );
E 14
I 14
				putchar( '+' );
E 14
				}
			else {
D 14
				printf( "-" );
E 14
I 14
				putchar( '-' );
E 14
				adrput( p->in.left );
				}
   tbl */
E 31
D 6
			printf("%s(%s)%s", (p->in.left->in.op==INCR ? "" : "-"),
				rnames[p->in.left->in.left->tn.rval], 
				(p->in.left->in.op==INCR ? "+" : "") );
			p->in.op = OREG;
			p->tn.rval = p->in.left->in.left->tn.rval;
E 6
			q = p->in.left;
I 8
			if( q->in.right->tn.lval != tlen(p) )
				cerror("adrput: bad auto-increment/decrement");
E 8
D 6
			p->tn.lval = (p->in.left->in.op == INCR ? -p->in.left->in.right->tn.lval : 0);
E 6
I 6
			printf("%s(%s)%s", (q->in.op==INCR ? "" : "-"),
				rnames[q->in.left->tn.rval], 
				(q->in.op==INCR ? "+" : "") );
			p->in.op = OREG;
			p->tn.rval = q->in.left->tn.rval;
			p->tn.lval = (q->in.op == INCR ? -q->in.right->tn.lval : 0);
E 6
#ifndef FLEXNAMES
			p->in.name[0] = '\0';
#else
			p->in.name = "";
#endif
			tfree(q);
		}
		return;

	default:
		cerror( "illegal address" );
		return;

		}

	}

acon( p ) register NODE *p; { /* print out a constant */

D 31
	if( p->in.name[0] == '\0' ){
E 31
I 31
	if( p->in.name[0] == '\0' )
E 31
		printf( CONFMT, p->tn.lval);
D 31
		}
	else if( p->tn.lval == 0 ) {
E 31
I 31
	else {
E 31
#ifndef FLEXNAMES
		printf( "%.8s", p->in.name );
#else
D 14
		printf( "%s", p->in.name );
E 14
I 14
		putstr( p->in.name );
E 14
#endif
I 31
		if( p->tn.lval != 0 ) {
			putchar( '+' );
			printf( CONFMT, p->tn.lval );
			}
E 31
		}
D 31
	else {
#ifndef FLEXNAMES
		printf( "%.8s+", p->in.name );
#else
		printf( "%s+", p->in.name );
#endif
		printf( CONFMT, p->tn.lval );
		}
E 31
	}

D 31
/*
aacon( p ) register NODE *p; { /* print out a constant */
/*

	if( p->in.name[0] == '\0' ){
		printf( CONFMT, p->tn.lval);
		return( 0 );
		}
	else if( p->tn.lval == 0 ) {
#ifndef FLEXNAMES
		printf( "$%.8s", p->in.name );
#else
		printf( "$%s", p->in.name );
#endif
		return( 1 );
		}
	else {
		printf( "$(" );
		printf( CONFMT, p->tn.lval );
		printf( "+" );
#ifndef FLEXNAMES
		printf( "%.8s)", p->in.name );
#else
		printf( "%s)", p->in.name );
#endif
		return(1);
		}
	}
 */

E 31
genscall( p, cookie ) register NODE *p; {
	/* structure valued call */
	return( gencall( p, cookie ) );
	}

/* tbl */
int gc_numbytes;
/* tbl */

I 20
/*ARGSUSED*/
E 20
gencall( p, cookie ) register NODE *p; {
	/* generate the call given by p */
D 3
	register NODE *p1, *ptemp;
E 3
I 3
	register NODE *p1;
E 3
D 31
	register temp, temp1;
	register m;
E 31
I 31
	register int temp, temp1;
	register int m;
E 31

	if( p->in.right ) temp = argsize( p->in.right );
	else temp = 0;

	if( p->in.op == STCALL || p->in.op == UNARY STCALL ){
		/* set aside room for structure return */

		if( p->stn.stsize > temp ) temp1 = p->stn.stsize;
		else temp1 = temp;
		}

	if( temp > maxargs ) maxargs = temp;
	SETOFF(temp1,4);

	if( p->in.right ){ /* make temp node, put offset in, and generate args */
D 3
		ptemp = talloc();
		ptemp->in.op = OREG;
		ptemp->tn.lval = -1;
		ptemp->tn.rval = SP;
#ifndef FLEXNAMES
		ptemp->in.name[0] = '\0';
#else
		ptemp->in.name = "";
#endif
		ptemp->in.rall = NOPREF;
		ptemp->in.su = 0;
		genargs( p->in.right, ptemp );
		ptemp->in.op = FREE;
E 3
I 3
		genargs( p->in.right );
E 3
		}

	p1 = p->in.left;
	if( p1->in.op != ICON ){
		if( p1->in.op != REG ){
			if( p1->in.op != OREG || R2TEST(p1->tn.rval) ){
				if( p1->in.op != NAME ){
					order( p1, INAREG );
					}
				}
			}
		}

D 31
/*
	if( p1->in.op == REG && p->tn.rval == R5 ){
		cerror( "call register overwrite" );
		}
 */
E 31
/* tbl
	setup gc_numbytes so reference to ZC works */

	gc_numbytes = temp&(0x3ff);
/* tbl */

	p->in.op = UNARY CALL;
	m = match( p, INTAREG|INTBREG );

	/* compensate for deficiency in 'ret' instruction ... wah,kre */
	/* (plus in assignment to gc_numbytes above, for neatness only) */
	if (temp >= 1024)
		printf("	addl2	$%d,sp\n", (temp&(~0x3ff)));

D 31
/* tbl
	switch( temp ) {
	case 0:
		break;
	case 2:
		printf( "	tst	(sp)+\n" );
		break;
	case 4:
		printf( "	cmp	(sp)+,(sp)+\n" );
		break;
	default:
		printf( "	add	$%d,sp\n", temp);
		}
   tbl */
E 31
	return(m != MDONE);
	}

/* tbl */
char *
ccbranches[] = {
D 31
	"	jeql	L%d\n",
	"	jneq	L%d\n",
	"	jleq	L%d\n",
	"	jlss	L%d\n",
	"	jgeq	L%d\n",
	"	jgtr	L%d\n",
	"	jlequ	L%d\n",
	"	jlssu	L%d\n",
	"	jgequ	L%d\n",
	"	jgtru	L%d\n",
E 31
I 31
	"eql",
	"neq",
	"leq",
	"lss",
	"geq",
	"gtr",
	"lequ",
	"lssu",
	"gequ",
	"gtru",
E 31
	};
/* tbl */

I 20
/*ARGSUSED*/
E 20
cbgen( o, lab, mode ) { /*   printf conditional and unconditional branches */

D 31
/* tbl */
	if( o == 0 ) printf( "	jbr	L%d\n", lab );
/* tbl */
	else {
		if( o > UGT ) cerror( "bad conditional branch: %s", opst[o] );
		printf( ccbranches[o-EQ], lab );
		}
E 31
I 31
	if( o != 0 && ( o < EQ || o > UGT ) )
		cerror( "bad conditional branch: %s", opst[o] );
	printf( "	j%s	L%d\n", o == 0 ? "br" : ccbranches[o-EQ], lab );
E 31
	}

nextcook( p, cookie ) NODE *p; {
	/* we have failed to match p with cookie; try another */
	if( cookie == FORREW ) return( 0 );  /* hopeless! */
	if( !(cookie&(INTAREG|INTBREG)) ) return( INTAREG|INTBREG );
	if( !(cookie&INTEMP) && asgop(p->in.op) ) return( INTEMP|INAREG|INTAREG|INTBREG|INBREG );
	return( FORREW );
	}

I 20
/*ARGSUSED*/
E 20
lastchance( p, cook ) NODE *p; {
	/* forget it! */
	return(0);
	}

optim2( p ) register NODE *p; {
	/* do local tree transformations and optimizations */

I 25
	int o;
D 27
	int result, i;
	int lower, upper;
E 27
I 27
D 28
	int i;
E 28
I 28
	int i, mask;
E 28
E 27
E 25
D 2
	register NODE *r;
E 2
I 2
	register NODE *l, *r;
D 20
	int m, ml;
E 20
E 2

D 25
	switch( p->in.op ) {
E 25
I 25
	switch( o = p->in.op ) {
E 25

I 40
	case ASG PLUS:
	case ASG MINUS:
	case ASG MUL:
	case ASG OR:
		/* simple ASG OPSIMP -- reduce range of constant rhs */
		l = p->in.left;
		r = p->in.right;
		if( tlen(l) < SZINT/SZCHAR &&
		    r->in.op==ICON && r->in.name[0]==0 ){
			mask = (1 << tlen(l) * SZCHAR) - 1;
			if( r->tn.lval & (mask & ~(mask >> 1)) )
				r->tn.lval |= ~mask;
			else
				r->tn.lval &= mask;
			}
		break;

E 40
	case AND:
D 11
		/* commute L and R to eliminate compliments and constants */
E 11
I 11
		/* commute L and R to eliminate complements and constants */
E 11
D 2
		if( (p->in.left->in.op==ICON&&p->in.left->in.name[0]==0) || p->in.left->in.op==COMPL ) {
			r = p->in.left;
E 2
I 2
		if( (l = p->in.left)->in.op == ICON && l->in.name[0] == 0 ||
		    l->in.op == COMPL ) {
E 2
			p->in.left = p->in.right;
D 2
			p->in.right = r;
E 2
I 2
			p->in.right = l;
E 2
			}
I 40
		/* fall through */

E 40
	case ASG AND:
D 40
		/* change meaning of AND to ~R&L - bic on pdp11 */
E 40
I 40
		/* change meaning of AND to ~R&L - bic on pdp11/vax */
E 40
		r = p->in.right;
D 11
		if( r->in.op==ICON && r->in.name[0]==0 ) { /* compliment constant */
E 11
I 11
D 27
		if( r->in.op==ICON && r->in.name[0]==0 ) { /* complement constant */
E 27
I 27
		if( r->in.op==ICON && r->in.name[0]==0 ) {
			/* check for degenerate operations */
			l = p->in.left;
D 28
			if( (i = (r->tn.lval & (1 << tlen(l) * SZCHAR) - 1)) == 0 )
				goto zero;
			else if( i == (1 << tlen(l) * SZCHAR) - 1 ) {
				r->in.op = FREE;
				ncopy(p, l);
				l->in.op = FREE;
E 28
I 28
			mask = (1 << tlen(l) * SZCHAR) - 1;
D 40
			if( ISUNSIGNED(r->in.type) ) {
D 34
				i = (r->tn.lval & mask);
				if( i == mask ) {
E 34
I 34
				i = (~r->tn.lval & mask);
E 40
I 40
			if( o == ASG AND || ISUNSIGNED(r->in.type) ) {
				i = ~r->tn.lval & mask;
E 40
				if( i == 0 ) {
I 40
					/* redundant mask */
E 40
E 34
					r->in.op = FREE;
					ncopy(p, l);
					l->in.op = FREE;
					break;
					}
D 34
				else if( i == 0 )
E 34
I 34
				else if( i == mask )
I 40
					/* all bits masked off */
E 40
E 34
					goto zero;
D 40
				else
					r->tn.lval = i;
E 40
I 40
				r->tn.lval = i;
				if( tlen(l) < SZINT/SZCHAR ){
					/* sign extend */
					if( r->tn.lval & (mask & ~(mask >> 1)) )
						r->tn.lval |= ~mask;
					else
						r->tn.lval &= mask;
					}
E 40
I 34
				break;
E 34
				}
			else if( r->tn.lval == mask &&
				 tlen(l) < SZINT/SZCHAR ) {
I 40
				/* use movz instead of bic */
E 40
				r->in.op = SCONV;
				r->in.left = l;
				r->in.right = 0;
				r->in.type = ENUNSIGN(l->in.type);
				r->in.su = l->in.su > 1 ? l->in.su : 1;
				ncopy(p, r);
				p->in.left = r;
				p->in.type = INT;
E 28
				break;
				}
			/* complement constant */
E 27
E 11
			r->tn.lval = ~r->tn.lval;
			}
		else if( r->in.op==COMPL ) { /* ~~A => A */
			r->in.op = FREE;
			p->in.right = r->in.left;
			}
		else { /* insert complement node */
D 2
			p->in.right = talloc();
			p->in.right->in.op = COMPL;
			p->in.right->in.rall = NOPREF;
			p->in.right->in.type = r->in.type;
			p->in.right->in.left = r;
			p->in.right->in.right = NULL;
E 2
I 2
			p->in.right = l = talloc();
			l->in.op = COMPL;
			l->in.rall = NOPREF;
			l->in.type = r->in.type;
			l->in.left = r;
			l->in.right = NULL;
E 2
			}
I 2
		break;

	case SCONV:
I 11
		l = p->in.left;
I 34
D 36
		if( (l->in.type == UCHAR || l->in.type == USHORT) &&
		    (p->in.type == DOUBLE || p->in.type == FLOAT) ) {
			/* we can convert to INT without loss of significance */
			r = talloc();
			*r = *p;
			r->in.type = INT;
			p->in.left = r;
#if !defined(FORT) && !defined(SPRECC)
			/* nothing to be 'gained' by a FLOAT conversion */
			p->in.type = DOUBLE;
#endif
			return;
			}
E 36
E 34
E 11
I 4
D 8
#ifdef FORT
E 8
I 8
#if defined(FORT) || defined(SPRECC)
E 8
		if( p->in.type == FLOAT || p->in.type == DOUBLE ||
D 11
		    (l = p->in.left)->in.type == FLOAT || l->in.type == DOUBLE )
			break;
E 11
I 11
		    l->in.type == FLOAT || l->in.type == DOUBLE )
			return;
E 11
#else
E 4
D 11
		m = (p->in.type == FLOAT || p->in.type == DOUBLE);
		ml = ((l = p->in.left)->in.type == FLOAT || l->in.type == DOUBLE);
		if( m != ml ) break;
E 11
I 11
		if( mixtypes(p, l) ) return;
E 11
I 4
#endif
I 15
D 20
		if( l->in.op == PCONV )
E 20
I 20
D 34
		if( l->in.op == PCONV || l->in.op == CALL || l->in.op == UNARY CALL )
E 34
I 34
		if( l->in.op == PCONV )
E 34
E 20
			return;
I 34
		if( (l->in.op == CALL || l->in.op == UNARY CALL) &&
		    l->in.type != INT && l->in.type != UNSIGNED )
			return;
E 34

E 15
E 4
D 11
		m = p->in.type;
		ml = l->in.type;
		/* meaningful ones are conversion of int to char, int to short,
		   and short to char, and unsigned version of them */
		if( m==CHAR || m==UCHAR ){
			if( ml!=CHAR && ml!= UCHAR )
				break;
			}
		else if( m==SHORT || m==USHORT ){
			if( ml!=CHAR && ml!=UCHAR && ml!=SHORT && ml!=USHORT )
				break;
			}
E 11
I 11
		/* Only trust it to get it right if the size is the same */
		if( tlen(p) != tlen(l) )
			return;
E 11

		/* clobber conversion */
D 11
		if( tlen( p ) == tlen( l ) && l->in.op != FLD )
E 11
I 11
		if( l->in.op != FLD )
E 11
			l->in.type = p->in.type;
		ncopy( p, l );
		l->in.op = FREE;
I 11

E 11
E 2
		break;

I 14
	case ASSIGN:
		/*
		 * Conversions are equivalent to assignments;
		 * when the two operations are combined,
		 * we can sometimes zap the conversion.
		 */
		r = p->in.right;
		l = p->in.left;
		if ( r->in.op == SCONV &&
		     !mixtypes(l, r) &&
I 18
		     l->in.op != FLD &&
E 18
		     tlen(l) == tlen(r) ) {
				p->in.right = r->in.left;
				r->in.op = FREE;
D 36
			}
I 34
		else if( (r->in.type == UCHAR || r->in.type == USHORT) &&
			 (p->in.type == DOUBLE || p->in.type == FLOAT) ) {
			/* we can convert to INT without loss of significance */
			l = talloc();
			l->in.op = SCONV;
			l->in.rall = NOPREF;
			l->in.left = r;
			l->in.right = NULL;
			l->in.type = INT;
			p->in.right = r;
			return;
E 36
			}
E 34
		break;

I 25
	case ULE:
	case ULT:
	case UGE:
	case UGT:
D 27
		o -= (UGE-GE);
E 27
I 27
		p->in.op -= (UGE-GE);
		if( degenerate(p) )
			break;
		p->in.op += (UGE-GE);
		break;

E 27
	case EQ:
	case NE:
	case LE:
	case LT:
	case GE:
	case GT:
I 34
		if( p->in.left->in.op == SCONV &&
		    p->in.right->in.op == SCONV ) {
			l = p->in.left;
			r = p->in.right;
			if( l->in.type == DOUBLE &&
			    l->in.left->in.type == FLOAT &&
			    r->in.left->in.type == FLOAT ) {
				/* nuke the conversions */
				p->in.left = l->in.left;
				p->in.right = r->in.left;
				l->in.op = FREE;
				r->in.op = FREE;
				}
			/* more? */
			}
E 34
D 27
		r = p->in.right;
		l = p->in.left;
		if( r->in.op != ICON ||
		    r->tn.name[0] != '\0' ||
		    tlen(l) >= tlen(r) )
E 27
I 27
		(void) degenerate(p);
		break;

	case DIV:
		if( p->in.right->in.op == ICON &&
		    p->in.right->tn.name[0] == '\0' &&
		    ISUNSIGNED(p->in.right->in.type) &&
		    (unsigned) p->in.right->tn.lval >= 0x80000000 ) {
			/* easy to do here, harder to do in zzzcode() */
			p->in.op = UGE;
E 27
			break;
D 27
		switch( l->in.type ) {
		case CHAR:
			lower = -(1 << SZCHAR - 1);
			upper = (1 << SZCHAR - 1) - 1;
E 27
I 27
			}
	case MOD:
	case ASG DIV:
	case ASG MOD:
		/*
		 * optimize DIV and MOD
		 *
		 * basically we spot UCHAR and USHORT and try to do them
		 * as signed ints...  apparently div+mul+sub is always
		 * faster than ediv for finding MOD on the VAX, when
		 * full unsigned MOD isn't needed.
		 *
		 * a curious fact: for MOD, cmp+sub and cmp+sub+cmp+sub
		 * are faster for unsigned dividend and a constant divisor
		 * in the right range (.5 to 1 of dividend's range for the
		 * first, .333+ to .5 for the second).  full unsigned is
		 * already done cmp+sub in the appropriate case; the
		 * other cases are less common and require more ambition.
		 */
		if( degenerate(p) )
E 27
			break;
D 27
		case UCHAR:
			lower = 0;
			upper = (1 << SZCHAR) - 1;
E 27
I 27
		l = p->in.left;
		r = p->in.right;
		if( !ISUNSIGNED(r->in.type) ||
		    tlen(l) >= SZINT/SZCHAR ||
		    !(tlen(r) < SZINT/SZCHAR ||
		      (r->in.op == ICON && r->tn.name[0] == '\0')) )
E 27
			break;
D 27
		case SHORT:
			lower = -(1 << SZSHORT - 1);
			upper = (1 << SZSHORT - 1) - 1;
			break;
		case USHORT:
			lower = 0;
			upper = (1 << SZSHORT) - 1;
			break;
		default:
			cerror("unsupported OPLOG in optim2");
E 27
I 27
		if( r->in.op == ICON )
			r->tn.type = INT;
		else {
			NODE *t = talloc();
			t->in.left = r;
			r = t;
			r->in.op = SCONV;
			r->in.type = INT;
			r->in.right = 0;
			p->in.right = r;
E 27
			}
D 27
		result = -1;
E 27
I 27
		if( o == DIV || o == MOD ) {
			NODE *t = talloc();
			t->in.left = l;
			l = t;
			l->in.op = SCONV;
			l->in.type = INT;
			l->in.right = 0;
			p->in.left = l;
			}
		/* handle asgops in table */
		break;

	case RS:
	case ASG RS:
	case LS:
	case ASG LS:
		/* pick up degenerate shifts */
		l = p->in.left;
		r = p->in.right;
		if( !(r->in.op == ICON && r->tn.name[0] == '\0') )
			break;
E 27
		i = r->tn.lval;
D 27
		switch( o ) {
		case EQ:
		case NE:
			if( lower == 0 && (unsigned) i > upper )
				result = o == NE;
			else if( i < lower || i > upper )
				result = o == NE;
E 27
I 27
		if( i < 0 )
			/* front end 'fixes' this? */
			if( o == LS || o == ASG LS )
				o += (RS-LS);
			else
				o += (LS-RS);
		if( (o == RS || o == ASG RS) &&
		    !ISUNSIGNED(l->in.type) )
			/* can't optimize signed right shifts */
E 27
			break;
D 27
		case LT:
		case GE:
			if( lower == 0 && (unsigned) i > upper )
				result = o == LT;
			else if( i <= lower )
				result = o != LT;
			else if( i > upper )
				result = o == LT;
E 27
I 27
D 31
		if( i < tlen(l) * SZCHAR )
E 27
			break;
E 31
I 31
		if( o == LS ) {
			if( i < SZINT )
				break;
			}
		else {
			if( i < tlen(l) * SZCHAR )
				break;
			}
E 31
D 27
		case LE:
		case GT:
			if( lower == 0 && (unsigned) i >= upper )
				result = o == LE;
			else if( i < lower )
				result = o != LE;
			else if( i >= upper )
				result = o == LE;
			break;
E 27
I 27
	zero:
		if( !asgop( o ) )
			if( tshape(l, SAREG|SNAME|SCON|SOREG|STARNM) ) {
				/* no side effects */
D 28
				l->in.op = FREE;
E 28
I 28
				tfree(l);
E 28
				ncopy(p, r);
				r->in.op = FREE;
				p->tn.lval = 0;
				}
			else {
				p->in.op = COMOP;
D 28
				r->in.lval = 0;
E 28
I 28
				r->tn.lval = 0;
E 28
				}
		else {
			p->in.op = ASSIGN;
			r->tn.lval = 0;
E 27
			}
D 27
		if( result == -1 )
			break;
			
		if( tshape(l, SAREG|SNAME|SCON|SOREG|STARNM) ) {
			l->in.op = FREE;
			ncopy(p, r);
			r->in.op = FREE;
			p->tn.type = INT;
			p->tn.lval = result;
			}
E 27
I 27
		break;
		}
	}

degenerate(p) register NODE *p; {
	int o;
	int result, i;
	int lower, upper;
	register NODE *l, *r;

	/*
	 * try to keep degenerate comparisons with constants
	 * out of the table.
	 */
	r = p->in.right;
	l = p->in.left;
	if( r->in.op != ICON ||
	    r->tn.name[0] != '\0' ||
	    tlen(l) >= tlen(r) )
		return (0);
	switch( l->in.type ) {
	case CHAR:
		lower = -(1 << SZCHAR - 1);
		upper = (1 << SZCHAR - 1) - 1;
		break;
	case UCHAR:
		lower = 0;
		upper = (1 << SZCHAR) - 1;
		break;
	case SHORT:
		lower = -(1 << SZSHORT - 1);
		upper = (1 << SZSHORT - 1) - 1;
		break;
	case USHORT:
		lower = 0;
		upper = (1 << SZSHORT) - 1;
		break;
	default:
D 28
		cerror("unsupported OPLOG in optim2");
E 28
I 28
		cerror("unsupported type in degenerate()");
E 28
		}
	i = r->tn.lval;
	switch( o = p->in.op ) {
	case DIV:
	case ASG DIV:
	case MOD:
	case ASG MOD:
		/* DIV and MOD work like EQ */
	case EQ:
	case NE:
		if( lower == 0 && (unsigned) i > upper )
			result = o == NE;
		else if( i < lower || i > upper )
			result = o == NE;
		else
			return (0);
		break;
	case LT:
	case GE:
		if( lower == 0 && (unsigned) i > upper )
			result = o == LT;
		else if( i <= lower )
			result = o != LT;
		else if( i > upper )
			result = o == LT;
		else
			return (0);
		break;
	case LE:
	case GT:
		if( lower == 0 && (unsigned) i >= upper )
			result = o == LE;
		else if( i < lower )
			result = o != LE;
		else if( i >= upper )
			result = o == LE;
		else
			return (0);
		break;
	default:
		cerror("unknown op in degenerate()");
		}
		
	if( o == MOD || o == ASG MOD ) {
		r->in.op = FREE;
		ncopy(p, l);
		l->in.op = FREE;
		}
	else if( o != ASG DIV && tshape(l, SAREG|SNAME|SCON|SOREG|STARNM) ) {
		/* no side effects */
D 28
		l->in.op = FREE;
E 28
I 28
		tfree(l);
E 28
		ncopy(p, r);
		r->in.op = FREE;
		p->tn.lval = result;
		}
	else {
		if( o == ASG DIV )
			p->in.op = ASSIGN;
E 27
		else {
			p->in.op = COMOP;
D 27
			p->in.type = INT;
E 27
			r->tn.type = INT;
D 27
			r->tn.lval = result;
E 27
			}
D 27
		break;
E 27
I 27
		r->tn.lval = result;
E 27
E 25
E 14
		}
I 27
	if( logop(o) )
		p->in.type = INT;

	return (1);
E 27
	}

I 20
D 31
/*ARGSUSED*/
E 20
D 8
NODE * addroreg(l)
E 8
I 8
NODE * addroreg(l) NODE *l;
E 8
				/* OREG was built in clocal()
				 * for an auto or formal parameter
				 * now its address is being taken
				 * local code must unwind it
				 * back to PLUS/MINUS REG ICON
				 * according to local conventions
				 */
{
	cerror("address of OREG taken");
I 8
	/*NOTREACHED*/
E 8
}



# ifndef ONEPASS
main( argc, argv ) char *argv[]; {
	return( mainp2( argc, argv ) );
	}
# endif


E 31
/* added by jwf */
struct functbl {
	int fop;
	TWORD ftype;
	char *func;
	} opfunc[] = {
	DIV,		TANY,	"udiv",
	MOD,		TANY,	"urem",
D 7
	ASG DIV,	TANY,	"udiv",
	ASG MOD,	TANY,	"urem",
E 7
I 7
	ASG DIV,	TANY,	"audiv",
	ASG MOD,	TANY,	"aurem",
E 7
	0,	0,	0 };

hardops(p)  register NODE *p; {
	/* change hard to do operators into function calls.  */
	register NODE *q;
	register struct functbl *f;
	register o;
D 8
	register TWORD t;
E 8
I 8
	NODE *old,*temp;
E 8

	o = p->in.op;
D 8
	t = p->in.type;
	if( t!=UNSIGNED && t!=ULONG ) return;
E 8
I 8
	if( ! (optype(o)==BITYPE &&
	       (ISUNSIGNED(p->in.left->in.type) ||
		ISUNSIGNED(p->in.right->in.type))) )
		return;
E 8

	for( f=opfunc; f->fop; f++ ) {
		if( o==f->fop ) goto convert;
		}
	return;

D 7
	/* need to rewrite tree for ASG OP */
	/* must change ASG OP to a simple OP */
E 7
	convert:
I 24
D 27
	if( p->in.right->in.op == ICON && p->in.right->tn.name[0] == '\0' ) {
E 27
I 27
	if( p->in.right->in.op == ICON && p->in.right->tn.name[0] == '\0' )
E 27
		/* 'J', 'K' in zzzcode() -- assumes DIV or MOD operations */
		/* save a subroutine call -- use at most 5 instructions */
D 27
		if( p->in.op == DIV &&
		     (unsigned) p->in.right->tn.lval >= 0x80000000 )
			/* easy to do here, harder to do in zzzcode() */
			p->in.op = UGE;
E 27
		return;
D 27
		}
E 27
I 27
	if( tlen(p->in.left) < SZINT/SZCHAR && tlen(p->in.right) < SZINT/SZCHAR )
		/* optim2() will modify the op into an ordinary int op */
		return;
E 27
E 24
	if( asgop( o ) ) {
I 8
		old = NIL;
E 8
D 7
		q = talloc();
		switch( p->in.op ) {
			case ASG DIV:
				q->in.op = DIV;
				break;
			case ASG MOD:
				q->in.op = MOD;
				break;
		}
		q->in.rall = NOPREF;
		q->in.type = p->in.type;
		q->in.left = tcopy(p->in.left);
		q->in.right = p->in.right;
		p->in.op = ASSIGN;
		p->in.right = q;
		zappost(q->in.left); /* remove post-INCR(DECR) from new node */
		fixpre(q->in.left);	/* change pre-INCR(DECR) to +/-	*/
		p = q;
E 7
I 7
		switch( p->in.left->in.op ){
I 8
		case FLD:
			q = p->in.left->in.left;
			/*
			 * rewrite (lval.fld /= rval); as
			 *  ((*temp).fld = udiv((*(temp = &lval)).fld,rval));
			 * else the compiler will evaluate lval twice.
			 */
			if( q->in.op == UNARY MUL ){
				/* first allocate a temp storage */
				temp = talloc();
				temp->in.op = OREG;
				temp->tn.rval = TMPREG;
				temp->tn.lval = BITOOR(freetemp(1));
				temp->in.type = INCREF(p->in.type);
#ifdef FLEXNAMES
				temp->in.name = "";
#else
				temp->in.name[0] = '\0';
#endif
				old = q->in.left;
				q->in.left = temp;
			}
			/* fall thru ... */

E 8
		case REG:
		case NAME:
		case OREG:
			/* change ASG OP to a simple OP */
			q = talloc();
			q->in.op = NOASG p->in.op;
			q->in.rall = NOPREF;
			q->in.type = p->in.type;
			q->in.left = tcopy(p->in.left);
			q->in.right = p->in.right;
			p->in.op = ASSIGN;
			p->in.right = q;
			p = q;
			f -= 2; /* Note: this depends on the table order */
I 8
			/* on the right side only - replace *temp with
			 *(temp = &lval), build the assignment node */
			if( old ){
				temp = q->in.left->in.left; /* the "*" node */
				q = talloc();
				q->in.op = ASSIGN;
				q->in.left = temp->in.left;
				q->in.right = old;
				q->in.type = old->in.type;
#ifdef FLEXNAMES
				q->in.name = "";
#else
				q->in.name[0] = '\0';
#endif
				temp->in.left = q;
			}
E 8
			break;
E 7

I 7
		case UNARY MUL:
			/* avoid doing side effects twice */
			q = p->in.left;
			p->in.left = q->in.left;
			q->in.op = FREE;
			break;

		default:
			cerror( "hardops: can't compute & LHS" );
			}
I 8
		}
E 8

E 7
D 8
	}

E 8
	/* build comma op for args to function */
	q = talloc();
	q->in.op = CM;
	q->in.rall = NOPREF;
	q->in.type = INT;
	q->in.left = p->in.left;
	q->in.right = p->in.right;
	p->in.op = CALL;
	p->in.right = q;

	/* put function name in left node of call */
	p->in.left = q = talloc();
	q->in.op = ICON;
	q->in.rall = NOPREF;
	q->in.type = INCREF( FTN + p->in.type );
#ifndef FLEXNAMES
	strcpy( q->in.name, f->func );
#else
	q->in.name = f->func;
#endif
	q->tn.lval = 0;
	q->tn.rval = 0;

D 7
	return;

E 7
	}
D 7

zappost(p) NODE *p; {
	/* look for ++ and -- operators and remove them */

	register o, ty;
	register NODE *q;
	o = p->in.op;
	ty = optype( o );

	switch( o ){

	case INCR:
	case DECR:
			q = p->in.left;
			p->in.right->in.op = FREE;  /* zap constant */
			ncopy( p, q );
			q->in.op = FREE;
			return;

		}

	if( ty == BITYPE ) zappost( p->in.right );
	if( ty != LTYPE ) zappost( p->in.left );
}

fixpre(p) NODE *p; {

	register o, ty;
	o = p->in.op;
	ty = optype( o );

	switch( o ){

	case ASG PLUS:
			p->in.op = PLUS;
			break;
	case ASG MINUS:
			p->in.op = MINUS;
			break;
		}

	if( ty == BITYPE ) fixpre( p->in.right );
	if( ty != LTYPE ) fixpre( p->in.left );
}
E 7

I 8
zappost(p) NODE *p; {
	/* look for ++ and -- operators and remove them */

D 31
	register o, ty;
E 31
I 31
	register int o, ty;
E 31
	register NODE *q;
	o = p->in.op;
	ty = optype( o );

	switch( o ){

	case INCR:
	case DECR:
			q = p->in.left;
			p->in.right->in.op = FREE;  /* zap constant */
			ncopy( p, q );
			q->in.op = FREE;
			return;

		}

	if( ty == BITYPE ) zappost( p->in.right );
	if( ty != LTYPE ) zappost( p->in.left );
}

fixpre(p) NODE *p; {

D 31
	register o, ty;
E 31
I 31
	register int o, ty;
E 31
	o = p->in.op;
	ty = optype( o );

	switch( o ){

	case ASG PLUS:
			p->in.op = PLUS;
			break;
	case ASG MINUS:
			p->in.op = MINUS;
			break;
		}

	if( ty == BITYPE ) fixpre( p->in.right );
	if( ty != LTYPE ) fixpre( p->in.left );
}

I 31
/*ARGSUSED*/
NODE * addroreg(l) NODE *l;
				/* OREG was built in clocal()
				 * for an auto or formal parameter
				 * now its address is being taken
				 * local code must unwind it
				 * back to PLUS/MINUS REG ICON
				 * according to local conventions
				 */
{
	cerror("address of OREG taken");
	/*NOTREACHED*/
}



# ifndef ONEPASS
main( argc, argv ) char *argv[]; {
	return( mainp2( argc, argv ) );
	}
# endif

E 31
I 14
strip(p) register NODE *p; {
	NODE *q;

	/* strip nodes off the top when no side effects occur */
	for( ; ; ) {
		switch( p->in.op ) {
		case SCONV:			/* remove lint tidbits */
			q = p->in.left;
			ncopy( p, q );
			q->in.op = FREE;
			break;
		/* could probably add a few more here */
		default:
			return;
			}
		}
	}

E 14
E 8
myreader(p) register NODE *p; {
I 14
	strip( p );		/* strip off operations with no side effects */
E 14
I 8
	canon( p );		/* expands r-vals for fields */
E 8
	walkf( p, hardops );	/* convert ops to function calls */
D 8
	canon( p );		/* expands r-vals for fileds */
E 8
	walkf( p, optim2 );
D 31
	/* jwf toff = 0;  /* stack offset swindle */
E 31
	}
D 8


E 8
E 1
