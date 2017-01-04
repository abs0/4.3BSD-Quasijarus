h18034
s 00002/00004/01987
d D 1.32 88/02/29 18:47:43 donn 34 33
c For some reason the cc tests in sconv() were inverted; I believe this was
c copied from the original code, but I should have checked this at the time...
e
s 00010/00003/01981
d D 1.31 88/01/29 12:04:40 donn 33 32
c ZU doesn't handle floating operands, hence ZD was broken.
e
s 00008/00001/01976
d D 1.30 88/01/19 18:48:01 donn 32 30
c Finish installing vax fix for float/double increments.
e
s 00005/00001/01976
d R 1.30 88/01/19 16:39:40 donn 31 30
c Finish installing vax fix for float/double increments.
e
s 00018/00004/01959
d D 1.29 88/01/14 00:30:31 donn 30 29
c Hack genconv() so that downward scalar conversions for conversion codes
c force a test to be emitted if the source is a register; more tahoe
c architecture grot...
e
s 00017/00006/01946
d D 1.28 87/12/10 22:57:50 donn 29 28
c utah rcsid 1.17 87/12/10 21:53:05: fix code for passing structures to
c subroutines (4.3BSD/lib/66) from mcvax!cwi.nl!root@seismo.css.gov (Ed
c Gronke)
e
s 00000/00000/01952
d D 1.27 87/12/10 22:57:30 donn 28 27
c double conversions below logical operators, leftovers from the first pass.
e
s 00000/00000/01952
d D 1.26 87/12/10 22:57:16 donn 27 26
c base() to permit indexed displacement deferred addressing.  (7) Put
c special() back -- SIREG is useful after all.  (8) Change optim2() to reduce
c the range of constant operands to +=, -=, *=, |=, &= and &, and so take
c advantage of byte and word arithmetic.  (9) Optimize ASG AND like unsigned
c AND since sign extension is not a problem for small lhs.  (10) Optimize
c int/unsigned SCONVs above function calls.  (11) Take care of float to
e
s 00078/00025/01874
d D 1.25 87/12/10 22:56:55 donn 26 25
c utah rcsid 1.16 87/11/29 20:59:25: (1) Don't put temporary registers into
c the entry mask in rname().  (2) Simplify ZM macro in zzzcode() for new ediv
c templates.  (3) Tahoe has byte and word operands, so MNEGx is only shorter
c for the 'literal' addressing mode, which is unsigned; sconv() changed
c appropriately.  (4) Print decimal rather than hex masks in sconv().  (5)
c Fix sconv() botch with rules for when to pun a source operand.  (6) Change
e
s 00442/00237/01457
d D 1.24 87/12/10 22:56:25 donn 25 24
c utah rcsid 1.15 87/07/19 22:46:18: First attack at integrating recent VAX
c fixes...  Too many to list at once.
e
s 00090/00000/01604
d D 1.23 87/12/10 22:56:06 donn 24 23
c utah rcsid 1.14 87/05/03 21:29:03: Add code from VAX compiler for detecting
c ridiculous comparisons between small variables and large constants.
e
s 00019/00000/01585
d D 1.22 87/12/10 22:55:45 donn 23 22
c utah rcsid 1.13 87/05/02 15:50:50: Add ZI feature -- generate result of
c bitfield assignment without using a shift.
e
s 00002/00000/01583
d D 1.21 87/12/10 22:55:25 donn 22 21
c utah rcsid 1.12 87/05/02 13:58:32: Don't delete double => int conversions
c on the rhs of assignments to bit fields; we don't want to write double =>
c bitfield templates...
e
s 00013/00012/01570
d D 1.20 87/12/10 22:55:02 donn 21 20
c utah rcsid 1.11 87/05/01 18:43:57: 'mnegl $1,r0' is one byte shorter than
c 'movl $-1,r0', so we make an effort to detect negative constant sources in
c sconv().  Note that MNEGx is no slower than MOVx in the general case where
c the source won't fit in a short literal operand.
e
s 00007/00001/01575
d D 1.19 87/12/10 22:54:40 donn 20 19
c utah rcsid 1.10 87/04/18 18:20:15: Another screwup -- must distinguish
c constant addresses from constant values in the conversion code.
e
s 00017/00013/01559
d D 1.18 87/12/10 22:54:20 donn 19 18
c utah rcsid 1.9 87/04/18 02:27:10: Fix a stupid mistake in the previous
c rev...
e
s 00089/00028/01483
d D 1.17 87/12/10 22:53:56 donn 18 17
c utah rcsid 1.8 87/04/18 01:42:25: Extensive hacking to weed out bugs in
c unsigned/float and float/unsigned conversions.
e
s 00001/00000/01510
d D 1.16 87/12/10 22:53:35 donn 17 16
c utah rcsid 1.7 87/04/17 03:32:04: Don't zap conversions of function calls
c -- the result of a call isn't quite the type it appears to be.
e
s 00088/00058/01422
d D 1.15 87/12/10 22:53:13 donn 16 15
c utah rcsid 1.6 87/04/16 23:32:35: Replaced hardops() with VAX PCC version
c -- fix bugs with computing unsigned remainder when divisor is > 2**31,
c multiple evaluation of lhs with asgops.
e
s 00130/00059/01350
d D 1.14 87/12/10 22:52:51 donn 15 14
c utah rcsid 1.5 87/03/23 04:40:10: Add 'G' zzzcode entry for int *= float
c operations.  Added 'W' and 'Y' entries and float_to_unsigned() and
c unsigned_to_float() functions to deal with these conversions.  Deleted the
c 'A' entry since its function is now handled by the 'U' entry.
e
s 00081/00020/01328
d D 1.13 87/12/10 22:52:30 donn 14 13
c utah rcsid 1.4 87/03/20 05:10:31: More work on sconv().  For sign extension
c in registers we use the stack code because shifts are too slow.  We are
c less stupid about constants.  We get register source operand lengths right.
c We distinguish between mova[bwl] in memory to register shrinking
c conversions so that side effects are handled correctly.
e
s 00009/00116/01339
d D 1.12 87/12/10 22:52:07 donn 13 12
c utah rcsid 1.3 87/03/18 02:20:29: Delete the old sconv() routine (ifdef'ed
c out in the previous rev); fix initial tabs (assume that the table provides
c them).
e
s 00133/00001/01322
d D 1.11 87/12/10 22:51:42 donn 12 10
c utah rcsid 1.2 87/03/16 20:03:49: First crack at fixing integer
c conversions.
e
s 00015/00004/01319
d R 1.11 87/06/04 10:25:38 mckusick 11 10
c fix code for passing structures to subroutines (4.3BSD/lib/66)
c from mcvax!cwi.nl!root@seismo.css.gov (Ed Gronke)
e
s 00001/00001/01322
d D 1.10 87/04/24 19:22:30 mckusick 10 9
c get the comparison in the correct order
e
s 00009/00019/01314
d D 1.9 87/02/11 18:24:55 mckusick 9 8
c must be more careful about signed and unsigned conversions
e
s 00229/00054/01104
d D 1.8 87/01/09 15:24:58 sam 8 7
c completely redo handling of SCONV nodes to cope with Tahoe's 
c incorrect handling of char's and short's in registers (e.g. cvtwl r0,r0 
c does a movl); also correct OPLOG handling for items shorter than 32-bits: 
c tst[wb] on registers don't work, but cmp[bw] $0,r? does; finally, handle 
c change to local.c which leaves in lots of new SCONV's (we optimize those 
c which are extraneous in code added mainly to optim2)
e
s 00027/00001/01131
d D 1.7 86/07/27 00:25:07 sam 7 6
c 1.21 release; handle unsigned arithmetic with char and short
e
s 00000/00001/01132
d D 1.6 86/02/12 20:45:24 sam 6 5
c get rid of warning, it seems like it works
e
s 00063/00066/01070
d D 1.5 86/02/12 20:44:25 sam 5 4
c purge as many printf calls as possible
e
s 00007/00002/01129
d D 1.4 86/02/04 22:19:34 sam 4 3
c new include files; szty and shltype are now macros; define nncon
e
s 00158/00069/00973
d D 1.3 86/01/25 23:55:34 sam 3 2
c optimize structure assignment based on size and alignment
e
s 00022/00034/01020
d D 1.2 86/01/23 00:35:41 sam 2 1
c restrict structure assignments to use movblk's; print address constants using ACONFMT
e
s 01054/00000/00000
d D 1.1 86/01/11 11:00:54 sam 1 0
c date and time created 86/01/11 11:00:54 by sam
e
u
U
t
T
I 1
D 25
#ifndef lint
E 25
I 25
D 29
# ifndef lint
E 29
I 29
#ifndef lint
E 29
E 25
static char sccsid[] = "%W% (Berkeley) %G%";
D 25
#endif
E 25
I 25
D 29
# endif
E 29
I 29
#endif
E 29
E 25

D 4
# include "mfile2"
# include "ctype.h"
E 4
I 4
# include "pass2.h"
# include <ctype.h>
I 5

# define putstr(s)	fputs((s), stdout)
I 7
# define ISCHAR(p)	(p->in.type == UCHAR || p->in.type == CHAR)
E 7

E 5
E 4
# ifdef FORT
int ftlab1, ftlab2;
# endif
/* a lot of the machine dependent parts of the second pass */

# define BITMASK(n) ((1L<<n)-1)

# ifndef ONEPASS
I 25
/*ARGSUSED*/
E 25
where(c){
	fprintf( stderr, "%s, line %d: ", filename, lineno );
	}
# endif

lineid( l, fn ) char *fn; {
	/* identify line l and file fn */
	printf( "#	line %d, file %s\n", l, fn );
	}

int ent_mask;

eobl2(){
	register OFFSZ spoff;	/* offset from stack pointer */
#ifndef FORT
	extern int ftlab1, ftlab2;
#endif

	spoff = maxoff;
	spoff /= SZCHAR;
	SETOFF(spoff,4);
#ifdef FORT
#ifndef FLEXNAMES
D 25
	printf( "	.set	.F%d,%d\n", ftnno, spoff );
E 25
I 25
	printf( "	.set	.F%d,%ld\n", ftnno, spoff );
E 25
#else
	/* SHOULD BE L%d ... ftnno but must change pc/f77 */
D 25
	printf( "	.set	LF%d,%d\n", ftnno, spoff );
E 25
I 25
	printf( "	.set	LF%d,%ld\n", ftnno, spoff );
E 25
#endif
	printf( "	.set	LWM%d,0x%x\n", ftnno, ent_mask&0x1ffc|0x1000);
#else
	printf( "	.set	L%d,0x%x\n", ftnno, ent_mask&0x1ffc);
	printf( "L%d:\n", ftlab1);
	if( maxoff > AUTOINIT )
D 25
		printf( "	subl3	$%d,fp,sp\n", spoff);
E 25
I 25
		printf( "	subl3	$%ld,fp,sp\n", spoff);
E 25
	printf( "	jbr 	L%d\n", ftlab2);
#endif
	ent_mask = 0;
	maxargs = -1;
	}

struct hoptab { int opmask; char * opstring; } ioptab[] = {

	PLUS,	"add",
	MINUS,	"sub",
	MUL,	"mul",
	DIV,	"div",
	MOD,	"div",
	OR,	"or",
	ER,	"xor",
	AND,	"and",
	-1,	""    };

hopcode( f, o ){
	/* output the appropriate string from the above table */

	register struct hoptab *q;

	if(asgop(o))
		o = NOASG o;
	for( q = ioptab;  q->opmask>=0; ++q ){
		if( q->opmask == o ){
			if(f == 'E')
				printf( "e%s", q->opstring);
			else
				printf( "%s%c", q->opstring, tolower(f));
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
	"r12", "fp", "sp", "pc",
	};

/* output register name and update entry mask */
char *
rname(r)
	register int r;
{

D 26
	ent_mask |= 1<<r;
E 26
I 26
	if (!istreg(r))
		ent_mask |= 1<<r;
E 26
	return(rnames[r]);
}

int rstatus[] = {
	SAREG|STAREG, SAREG|STAREG,
	SAREG|STAREG, SAREG|STAREG, SAREG|STAREG, SAREG|STAREG,
	SAREG, SAREG, SAREG, SAREG, SAREG, SAREG,
	SAREG, SAREG, SAREG, SAREG,
	};

tlen(p) NODE *p;
{
	switch(p->in.type) {
		case CHAR:
		case UCHAR:
			return(1);

		case SHORT:
		case USHORT:
D 25
			return(2);
E 25
I 25
			return(SZSHORT/SZCHAR);
E 25

		case DOUBLE:
D 25
			return(8);
E 25
I 25
			return(SZDOUBLE/SZCHAR);
E 25

		default:
D 25
			return(4);
E 25
I 25
			return(SZINT/SZCHAR);
E 25
		}
}

I 8
D 25
anyfloat(p, q)
	NODE *p, *q;
E 25
I 25
mixtypes(p, q) NODE *p, *q;
E 25
{
	register TWORD tp, tq;

	tp = p->in.type;
	tq = q->in.type;
D 25
	return (tp == FLOAT || tp == DOUBLE || tq == FLOAT || tq == DOUBLE);
E 25
I 25

	return( (tp==FLOAT || tp==DOUBLE) !=
		(tq==FLOAT || tq==DOUBLE) );
E 25
}

E 8
prtype(n) NODE *n;
{
	switch (n->in.type)
		{

		case DOUBLE:
D 5
			printf("d");
E 5
I 5
			putchar('d');
E 5
			return;

		case FLOAT:
D 5
			printf("f");
E 5
I 5
			putchar('f');
E 5
			return;

I 25
		case LONG:
		case ULONG:
E 25
		case INT:
		case UNSIGNED:
D 5
			printf("l");
E 5
I 5
			putchar('l');
E 5
			return;

		case SHORT:
		case USHORT:
D 5
			printf("w");
E 5
I 5
			putchar('w');
E 5
			return;

		case CHAR:
		case UCHAR:
D 5
			printf("b");
E 5
I 5
			putchar('b');
E 5
			return;

		default:
			if ( !ISPTR( n->in.type ) ) cerror("zzzcode- bad type");
			else {
D 5
				printf("l");
E 5
I 5
				putchar('l');
E 5
				return;
				}
		}
}

zzzcode( p, c ) register NODE *p; {
	register int m;
	int val;
	switch( c ){

	case 'N':  /* logical ops, turned into 0-1 */
		/* use register given by register 1 */
		cbgen( 0, m=getlab(), 'I' );
		deflab( p->bn.label );
		printf( "	clrl	%s\n", rname(getlr( p, '1' )->tn.rval) );
		deflab( m );
		return;

	case 'P':
		cbgen( p->in.op, p->bn.label, c );
		return;

D 15
	case 'A':	/* assignment and load (integer only) */
E 15
I 15
	case 'G':	/* i *= f; asgops with int lhs and float rhs */
E 15
		{
D 15
		register NODE *l, *r;
E 15
I 15
		register NODE *l, *r, *s;
		int lt, rt;
E 15

D 15
		if (xdebug) eprint(p, 0, &val, &val);
		r = getlr(p, 'R');
		if (optype(p->in.op) == LTYPE || p->in.op == UNARY MUL) {
			l = resc;
			l->in.type = INT;
		} else
			l = getlr(p, 'L');
		if(r->in.type==FLOAT || r->in.type==DOUBLE
		 || l->in.type==FLOAT || l->in.type==DOUBLE)
			cerror("float in ZA");
		if (r->in.op == ICON)
			if(r->in.name[0] == '\0') {
				if (r->tn.lval == 0) {
D 5
					printf("clr");
E 5
I 5
					putstr("clr");
E 5
					prtype(l);
D 5
					printf("	");
E 5
I 5
					putchar('\t');
E 5
					adrput(l);
					return;
				}
				if (r->tn.lval < 0 && r->tn.lval >= -63) {
D 5
					printf("mneg");
E 5
I 5
					putstr("mneg");
E 5
					prtype(l);
					r->tn.lval = -r->tn.lval;
					goto ops;
				}
#ifdef MOVAFASTER
			} else {
D 5
				printf("movab");
				printf("	");
E 5
I 5
				putstr("movab\t");
E 5
				acon(r);
D 5
				printf(",");
E 5
I 5
				putchar(',');
E 5
				adrput(l);
				return;
#endif MOVAFASTER
			}
E 15
I 15
		l = p->in.left;
		r = p->in.right;
		s = talloc();
		rt = r->in.type;
		lt = l->in.type;
E 15

D 15
		if (l->in.op == REG) {
			if( tlen(l) < tlen(r) ) {
D 5
				!ISUNSIGNED(l->in.type)?
					printf("cvt"):
					printf("movz");
E 5
I 5
				putstr(!ISUNSIGNED(l->in.type)?
					"cvt": "movz");
E 5
				prtype(l);
D 5
				printf("l");
E 5
I 5
				putchar('l');
E 5
				goto ops;
			} else
				l->in.type = INT;
E 15
I 15
		if (lt != INT && lt != UNSIGNED) {
			s->in.op = SCONV;
			s->in.left = l;
			s->in.type = ISUNSIGNED(lt) ? UNSIGNED : INT;
			zzzcode(s, 'U');
			putstr("\n\t");
E 15
		}
D 15
		if (tlen(l) == tlen(r)) {
D 5
			printf("mov");
E 5
I 5
			putstr("mov");
E 5
			prtype(l);
			goto ops;
		} else if (tlen(l) > tlen(r) && ISUNSIGNED(r->in.type))
D 5
			printf("movz");
E 5
I 5
			putstr("movz");
E 5
		else
D 5
			printf("cvt");
E 5
I 5
			putstr("cvt");
E 5
		prtype(r);
		prtype(l);
	ops:
E 15
I 15

		if (ISUNSIGNED(lt)) {
			s->in.op = SCONV;
			s->in.left = lt == UNSIGNED ? l : resc;
			s->in.type = rt;
			unsigned_to_float(s);
		} else {
			putstr("cvl");
			prtype(r);
			putchar('\t');
			adrput(lt == INT ? l : resc);
		}
		putstr("\n\t");

		hopcode(rt == FLOAT ? 'F' : 'D', p->in.op);
E 15
D 5
		printf("	");
E 5
I 5
		putchar('\t');
E 5
		adrput(r);
D 5
		printf(",");
E 5
I 5
D 15
		putchar(',');
E 5
		adrput(l);
E 15
I 15

		if (ISUNSIGNED(lt)) {
			putstr("\n\t");
			s->in.op = SCONV;
			s->in.left = r;		/* we need only the type */
			s->in.type = UNSIGNED;
			float_to_unsigned(s);
		} else {
			putstr("\n\tcv");
			prtype(r);
			putstr("l\t");
			if (lt == INT)
				adrput(l);
			else
				adrput(resc);
		}
		if (lt != INT) {
			putstr("\n\t");
			s->in.op = ASSIGN;
			s->in.left = l;
			s->in.right = resc;
			s->in.type = lt;
			zzzcode(s, 'U');
		}

		s->in.op = FREE;
E 15
		return;
		}

I 25
	case 'J':	/* unsigned DIV/MOD with constant divisors */
		{
		register int ck = INAREG;
		int label1, label2;

		/* case constant <= 1 is handled by optim() in pass 1 */
		/* case constant < 0x80000000 is handled in table */
		switch( p->in.op ) {
D 26
		/* case DIV: handled in hardops() */
E 26
I 26
		/* case DIV: handled in optim2() */
E 26
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

E 25
	case 'B':	/* get oreg value in temp register for shift */
		{
		register NODE *r;
		if (xdebug) eprint(p, 0, &val, &val);
		r = p->in.right;
D 25
		if( tlen(r) == sizeof(int) && r->in.type != FLOAT )
E 25
I 25
		if( tlen(r) == SZINT/SZCHAR && r->in.type != FLOAT )
E 25
D 5
			printf("movl");
E 5
I 5
			putstr("movl");
E 5
		else {
D 5
			printf(ISUNSIGNED(r->in.type) ? "movz" : "cvt");
E 5
I 5
			putstr(ISUNSIGNED(r->in.type) ? "movz" : "cvt");
E 5
			prtype(r);
D 5
			printf("l");
E 5
I 5
			putchar('l');
E 5
			}
		return;
		}

D 25
	case 'C':	/* num bytes pushed on arg stack */
E 25
I 25
	case 'C':	/* generate 'call[fs] $bytes' */
E 25
		{
		extern int gc_numbytes;
		extern int xdebug;

		if (xdebug) printf("->%d<-",gc_numbytes);

		printf("call%c	$%d",
		 (p->in.left->in.op==ICON && gc_numbytes<60)?'f':'s',
		 gc_numbytes+4);
D 25
		/* dont change to double (here's the only place to catch it) */
E 25
I 25
		/* don't change to double (here's the only place to catch it) */
E 25
		if(p->in.type == FLOAT)
			rtyflg = 1;
		return;
		}

	case 'D':	/* INCR and DECR */
D 15
		zzzcode(p->in.left, 'A');
E 15
I 15
D 33
		zzzcode(p->in.left, 'U');
E 33
I 33
		if (p->in.left->in.type == FLOAT)
			expand(p, INAREG, "movl\tAL,A1");
		else if (p->in.left->in.type == DOUBLE)
			expand(p, INAREG, "ldd\tAL\n\tstd\tA1");
		else
			zzzcode(p->in.left, 'U');
E 33
E 15
D 5
		printf("\n	");
E 5
I 5
		putstr("\n	");
E 5

	case 'E':	/* INCR and DECR, FOREFF */
D 32
 		if (p->in.right->tn.lval == 1)
E 32
I 32
 		if (p->in.right->in.op == ICON && p->in.right->tn.lval == 1)
E 32
			{
D 5
			printf("%s", (p->in.op == INCR ? "inc" : "dec") );
E 5
I 5
			putstr(p->in.op == INCR ? "inc" : "dec");
E 5
			prtype(p->in.left);
D 5
			printf("	");
E 5
I 5
			putchar('\t');
E 5
			adrput(p->in.left);
I 32
			return;
			}
		else if (p->in.left->in.type == FLOAT || p->in.left->in.type == DOUBLE) {
I 33
			if (c == 'E' || p->in.left->in.type == FLOAT)
				expand(p, INAREG, "ldZL\tAL\n\t");
E 33
			if (p->in.op == INCR)
D 33
				expand(p, INAREG, "ldZL\tAL\n\taddZL\tAR\n\tstZL\tAL");
E 33
I 33
				expand(p, INAREG, "addZL\tAR\n\tstZL\tAL");
E 33
			else /* DECR */
D 33
				expand(p, INAREG, "ldZL\tAL\n\tsubZL\tAR\n\tstZL\tAL");
E 33
I 33
				expand(p, INAREG, "subZL\tAR\n\tstZL\tAL");
E 33
E 32
			return;
			}
D 5
		printf("%s", (p->in.op == INCR ? "add" : "sub") );
E 5
I 5
		putstr(p->in.op == INCR ? "add" : "sub");
E 5
		prtype(p->in.left);
D 5
		printf("2	");
E 5
I 5
		putstr("2	");
E 5
		adrput(p->in.right);
D 5
		printf(",");
E 5
I 5
		putchar(',');
E 5
		adrput(p->in.left);
		return;

	case 'F':	/* masked constant for fields */
D 2
		printf("$%d", (p->in.right->tn.lval&((1<<fldsz)-1))<<fldshf);
E 2
I 2
		printf(ACONFMT, (p->in.right->tn.lval&((1<<fldsz)-1))<<fldshf);
E 2
		return;

I 23
	case 'I':	/* produce value of bitfield assignment */
			/* avoid shifts -- shifts are SLOW on this machine */
I 26
			/* XXX this wouldn't be necessary if we were smarter
			       and masked BEFORE shifting XXX */
E 26
		{
D 25
			register NODE *r = p->in.right;
			if(r->in.op == ICON && r->tn.name[0] == '\0') {
				putstr("movl\t");
				printf(ACONFMT, r->tn.lval & ((1<<fldsz)-1));
				}
			else {
				putstr("andl3\t");
				printf(ACONFMT, (1 << fldsz) - 1);
				putchar(',');
				adrput(r);
				}
E 25
I 25
		register NODE *r = p->in.right;
		if(r->in.op == ICON && r->tn.name[0] == '\0') {
			putstr("movl\t");
			printf(ACONFMT, r->tn.lval & ((1<<fldsz)-1));
			}
		else {
			putstr("andl3\t");
			printf(ACONFMT, (1 << fldsz) - 1);
E 25
			putchar(',');
D 25
			adrput(resc);
			break;
E 25
I 25
			adrput(r);
E 25
			}
I 25
		putchar(',');
		adrput(resc);
		break;
		}
E 25

E 23
	case 'H':	/* opcode for shift */
		if(p->in.op == LS || p->in.op == ASG LS)
D 5
			printf("shll");
E 5
I 5
			putstr("shll");
E 5
		else if(ISUNSIGNED(p->in.left->in.type))
D 5
			printf("shrl");
E 5
I 5
			putstr("shrl");
E 5
		else
D 5
			printf("shar");
E 5
I 5
			putstr("shar");
E 5
		return;

	case 'L':	/* type of left operand */
	case 'R':	/* type of right operand */
		{
		register NODE *n;
		extern int xdebug;

		n = getlr ( p, c);
		if (xdebug) printf("->%d<-", n->in.type);

		prtype(n);
		return;
		}

D 8
	case 'M':  /* initiate ediv for mod and unsigned div */
		{
E 8
I 8
	case 'M': {  /* initiate ediv for mod and unsigned div */
E 8
D 26
		register char *r;
		m = getlr(p, '1')->tn.rval;
		r = rname(m);
		printf("\tclrl\t%s\n\tmovl\t", r);
E 26
I 26
		putstr("clrl\t");
		adrput(resc);
		putstr("\n\tmovl\t");
E 26
		adrput(p->in.left);
D 26
		printf(",%s\n", rname(m+1));
		if(!ISUNSIGNED(p->in.type)) { 	/* should be MOD */
			m = getlab();
			printf("\tjgeq\tL%d\n\tmnegl\t$1,%s\n", m, r);
			deflab(m);
		}
E 26
I 26
		putchar(',');
		upput(resc, SZLONG);
		printf("\n\tjgeq\tL%d\n\tmnegl\t$1,", m = getlab());
		adrput(resc);
		putchar('\n');
		deflab(m);
E 26
D 8
		}
E 8
		return;
I 8
	}
E 8

D 8
	case 'U':
		/* Truncate int for type conversions:
		    LONG|ULONG -> CHAR|UCHAR|SHORT|USHORT
		    SHORT|USHORT -> CHAR|UCHAR
		   increment offset to correct byte */
		{
		register NODE *p1;
		int dif;

		p1 = p->in.left;
		switch( p1->in.op ){
		case NAME:
		case OREG:
			dif = tlen(p1)-tlen(p);
			p1->tn.lval += dif;
			adrput(p1);
			p1->tn.lval -= dif;
			return;
		default:
			cerror( "Illegal ZU type conversion" );
			return;
			}
		}

	case 'T':	/* rounded structure length for arguments */
		{
		int size;

		size = p->stn.stsize;
E 8
I 8
	case 'T': {	/* rounded structure length for arguments */
		int size = p->stn.stsize;
E 8
		SETOFF( size, 4);
		printf("movab	-%d(sp),sp", size);
		return;
D 8
		}
E 8
I 8
	}
E 8

	case 'S':  /* structure assignment */
D 3
		{
			register NODE *l, *r;
			register int size;
E 3
I 3
		stasg(p);
		break;
E 3

I 25
#ifdef I_don_t_understand_this
E 25
I 7
	case 'X':	/* multiplication for short and char */
		if (ISUNSIGNED(p->in.left->in.type)) 
			printf("\tmovz");
		else
			printf("\tcvt");
		zzzcode(p, 'L');
		printf("l\t");
		adrput(p->in.left);
		printf(",");
		adrput(&resc[0]);
		printf("\n");
		if (ISUNSIGNED(p->in.right->in.type)) 
			printf("\tmovz");
		else
			printf("\tcvt");
		zzzcode(p, 'R');
		printf("l\t");
		adrput(p->in.right);
		printf(",");
		adrput(&resc[1]);
		printf("\n");
		return;
I 25
#endif
E 25

I 8
	case 'U':		/* SCONV */
	case 'V':		/* SCONV with FORCC */
		sconv(p, c == 'V');
		break;

I 15
D 18
	case 'W':		/* SCONV float/double => unsigned */
E 18
I 18
	case 'W': {		/* SCONV or ASSIGN float/double => unsigned */
		NODE *src = p->in.op == SCONV ? p->in.left : p->in.right;

E 18
		putstr("ld");
D 18
		prtype(p->in.left);
E 18
I 18
		prtype(src);
E 18
		putchar('\t');
D 18
		adrput(p->in.left);
E 18
I 18
		adrput(src);
E 18
		putstr("\n\t");
		float_to_unsigned(p);
		break;
I 18
	}
E 18

D 18
	case 'Y':		/* SCONV unsigned => float/double */
E 18
I 18
	case 'Y':		/* SCONV or ASSIGN unsigned => float/double */
E 18
		unsigned_to_float(p);	/* stores into accumulator */
		putstr("\n\tst");
		prtype(p);
		putchar('\t');
D 18
		adrput(resc);
E 18
I 18
		if (p->in.op == SCONV)
			adrput(resc);
		else
			adrput(p->in.left);
		rtyflg = 1;
E 18
		break;

I 25
#ifdef I_don_t_understand_this
E 25
E 15
	case 'Z':
		p = p->in.right;
		switch (p->in.type) {
		case SHORT: {
			short w = p->tn.lval;
			p->tn.lval = w;
			break;
		}
		case CHAR: {
			char c = p->tn.lval;
			p->tn.lval = c;
			break;
		}
		}
		printf("$%d", p->tn.lval);
		break;
I 25
#endif
E 25

E 8
E 7
D 3
			if( p->in.op == STASG ){
				l = p->in.left;
				r = p->in.right;
E 3
I 3
	default:
		cerror( "illegal zzzcode" );
D 8
		}
E 8
	}
I 8
}
E 8
E 3

D 3
				}
			else if( p->in.op == STARG ){  /* store an arg into a temporary */
				l = getlr( p, '3' );
				r = p->in.left;
				}
			else cerror( "STASG bad" );
E 3
I 3
#define	MOVB(dst, src, off) { \
D 5
	printf("\tmovb\t"); upput(src, off); putchar(','); \
E 5
I 5
	putstr("\tmovb\t"); upput(src, off); putchar(','); \
E 5
	upput(dst, off); putchar('\n'); \
}
#define	MOVW(dst, src, off) { \
D 5
	printf("\tmovw\t"); upput(src, off); putchar(','); \
E 5
I 5
	putstr("\tmovw\t"); upput(src, off); putchar(','); \
E 5
	upput(dst, off); putchar('\n'); \
}
#define	MOVL(dst, src, off) { \
D 5
	printf("\tmovl\t"); upput(src, off); putchar(','); \
E 5
I 5
	putstr("\tmovl\t"); upput(src, off); putchar(','); \
E 5
	upput(dst, off); putchar('\n'); \
}
/*
 * Generate code for a structure assignment.
 */
stasg(p)
	register NODE *p;
{
	register NODE *l, *r;
	register int size;
E 3

D 3
			if( r->in.op == ICON ) r->in.op = NAME;
			else if( r->in.op == REG ) r->in.op = OREG;
			else if( r->in.op != OREG ) cerror( "STASG-r" );
E 3
I 3
	switch (p->in.op) {
	case STASG:			/* regular assignment */
		l = p->in.left;
		r = p->in.right;
		break;
	case STARG:			/* place arg on the stack */
		l = getlr(p, '3');
		r = p->in.left;
		break;
	default:
		cerror("STASG bad");
		/*NOTREACHED*/
	}
	/*
	 * Pun source for use in code generation.
	 */
	switch (r->in.op) {
	case ICON:
		r->in.op = NAME;
		break;
	case REG:
		r->in.op = OREG;
		break;
	default:
		cerror( "STASG-r" );
		/*NOTREACHED*/
	}
	size = p->stn.stsize;
	if (size <= 0 || size > 65535)
		cerror("structure size out of range");
	/*
	 * Generate optimized code based on structure size
	 * and alignment properties....
	 */
	switch (size) {

	case 1:
D 5
		printf("\tmovb\t");
E 5
I 5
		putstr("\tmovb\t");
E 5
	optimized:
		adrput(r);
D 5
		printf(",");
E 5
I 5
		putchar(',');
E 5
		adrput(l);
D 5
		printf("\n");
E 5
I 5
		putchar('\n');
E 5
D 6
werror("optimized structure assignment (size %d alignment %d)", size, p->stn.stalign);
E 6
		break;
E 3

D 3
			size = p->stn.stsize;
E 3
I 3
	case 2:
		if (p->stn.stalign != 2) {
			MOVB(l, r, SZCHAR);
D 5
			printf("\tmovb\t");
E 5
I 5
			putstr("\tmovb\t");
E 5
		} else
D 5
			printf("\tmovw\t");
E 5
I 5
			putstr("\tmovw\t");
E 5
		goto optimized;
E 3

D 3
			if( size <= 0 || size > 65535 )
				cerror("structure size <0=0 or >65535");
D 2

			switch(size) {
				case 1:
					printf("	movb	");
					break;
				case 2:
					printf("	movw	");
					break;
				case 4:
					printf("	movl	");
					break;
				case 8:
					printf("	movl	");
					upput(r);
					printf(",");
					upput(l);
					printf("\n	movl	");
					break;
				default:
					printf("	movab	");
					adrput(l);
					printf(",r1\n	movab	");
					adrput(r);
					printf(",r0\n	movl	$%d,r2\n	movblk\n", size);
					rname(2);
					goto endstasg;
E 2
I 2
			/*
			 * Can't optimize with movw's or movl's here as
			 * we don't know the alignment properties of
			 * either source or destination (governed, potentially
			 * by alignment of enclosing structure/union).
			 * (PERHAPS WE COULD SIMULATE dclstruct?)
			 */
			if (size != 1) {
				printf("\tmovab\t");
				adrput(l);
				printf(",r1\n\tmovab\t");
				adrput(r);
				printf(",r0\n\tmovl\t$%d,r2\n\tmovblk\n", size);
				rname(2);
			} else {
E 3
I 3
	case 4:
		if (p->stn.stalign != 4) {
			if (p->stn.stalign != 2) {
				MOVB(l, r, 3*SZCHAR);
				MOVB(l, r, 2*SZCHAR);
				MOVB(l, r, 1*SZCHAR);
E 3
D 5
				printf("\tmovb\t");
E 5
I 5
				putstr("\tmovb\t");
E 5
D 3
				adrput(r);
				printf(",");
				adrput(l);
				printf("\n");
E 3
I 3
			} else {
				MOVW(l, r, SZSHORT);
D 5
				printf("\tmovw\t");
E 5
I 5
				putstr("\tmovw\t");
E 5
E 3
E 2
			}
D 2
			adrput(r);
			printf(",");
			adrput(l);
			printf("\n");
		endstasg:
E 2
D 3
			if( r->in.op == NAME ) r->in.op = ICON;
			else if( r->in.op == OREG ) r->in.op = REG;
E 3
I 3
		} else
D 5
			printf("\tmovl\t");
E 5
I 5
			putstr("\tmovl\t");
E 5
		goto optimized;
E 3

D 3
			}
		break;
E 3
I 3
	case 6:
		if (p->stn.stalign != 2)
			goto movblk;
		MOVW(l, r, 2*SZSHORT);
		MOVW(l, r, 1*SZSHORT);
D 5
		printf("\tmovw\t");
E 5
I 5
		putstr("\tmovw\t");
E 5
		goto optimized;
E 3

I 3
	case 8:
		if (p->stn.stalign == 4) {
			MOVL(l, r, SZLONG);
D 5
			printf("\tmovl\t");
E 5
I 5
			putstr("\tmovl\t");
E 5
			goto optimized;
		}
		/* fall thru...*/

E 3
	default:
D 3
		cerror( "illegal zzzcode" );
E 3
I 3
	movblk:
		/*
		 * Can we ever get a register conflict with R1 here?
		 */
D 5
		printf("\tmovab\t");
E 5
I 5
		putstr("\tmovab\t");
E 5
D 29
		adrput(l);
D 5
		printf(",r1\n\tmovab\t");
E 5
I 5
		putstr(",r1\n\tmovab\t");
E 5
		adrput(r);
		printf(",r0\n\tmovl\t$%d,r2\n\tmovblk\n", size);
E 29
I 29
		if(r->in.op == OREG && r->tn.rval == R1)
		{
			adrput(r);
			printf(",r0\n\tmovab\t");
			adrput(l);
			putstr(",r1\n");
		}
		else
		{
			adrput(l);
			putstr(",r1\n\tmovab\t");
			adrput(r);
			printf(",r0\n");
		}
		printf("\tmovl\t$%d,r2\n\tmovblk\n", size);
E 29
		rname(R2);
		break;
	}
	/*
	 * Reverse above pun for reclaim.
	 */
	if (r->in.op == NAME)
		r->in.op = ICON;
	else if (r->in.op == OREG)
		r->in.op = REG;
}

/*
D 25
 * Output the address of the second item in the
 * pair pointed to by p.
 */
upput(p, size)
	register NODE *p;
{
	CONSZ save;

	if (p->in.op == FLD)
		p = p->in.left;
	switch (p->in.op) {

	case NAME:
	case OREG:
		save = p->tn.lval;
		p->tn.lval += size/SZCHAR;
		adrput(p);
		p->tn.lval = save;
		break;

	case REG:
		if (size == SZLONG) {
D 5
			printf("%s", rname(p->tn.rval+1));
E 5
I 5
			putstr(rname(p->tn.rval+1));
E 5
			break;
E 3
		}
I 3
		/* fall thru... */

	default:
		cerror("illegal upper address op %s size %d",
		    opst[p->tn.op], size);
		/*NOTREACHED*/
E 3
	}
I 15
}

/*
E 25
 * Convert a float or double in the accumulator into an unsigned int.
 * Unlike the vax, the tahoe stores 0 into the destination
 *	on a conversion of > 2 ** 31, so we compensate.
 */
float_to_unsigned(p)
	NODE *p;
{
	register NODE *l = p->in.left;
	int label1 = getlab();
	int label2 = getlab();
	int label3 = getlab();
I 18
	NODE *src, *dst;
E 18

I 18
	if (p->in.op == SCONV) {
		src = p->in.left;
		dst = resc;
	} else {
		src = p->in.right;
		dst = p->in.left;
	}

E 18
	printf(".data\n\t.align\t2\nL%d:\n\t.long\t0x50000000", label1);
D 18
	if (l->in.type == DOUBLE)
		putstr(", 0x00000000");
	putstr(" # .double 2147483648\n\t.text\n\tcmp");
	prtype(l);
E 18
I 18
	if (src->in.type == DOUBLE)
		putstr(", 0x00000000 # .double");
	else
		putstr(" # .float");
	putstr(" 2147483648\n\t.text\n\tcmp");
	prtype(src);
E 18
	printf("\tL%d\n\tjlss\tL%d\n\tsub", label1, label2);
D 18
	prtype(l);
E 18
I 18
	prtype(src);
E 18
	printf("\tL%d\n\tcv", label1);
D 18
	prtype(l);
E 18
I 18
	prtype(src);
E 18
	putstr("l\t");
D 18
	adrput(resc);
E 18
I 18
	adrput(dst);
E 18
	putstr("\n\taddl2\t$-2147483648,");
D 18
	adrput(resc);
E 18
I 18
	adrput(dst);
E 18
	printf("\n\tjbr\tL%d\nL%d:\n\tcv", label3, label2);
D 18
	prtype(l);
E 18
I 18
	prtype(src);
E 18
	putstr("l\t");
D 18
	adrput(resc);
E 18
I 18
	adrput(dst);
E 18
	printf("\nL%d:", label3);
}

/*
 * Convert an unsigned int into a float or double, leaving the result
 *	in the accumulator.
 */
unsigned_to_float(p)
	register NODE *p;
{
	int label1 = getlab();
	int label2 = getlab();
I 18
	NODE *src, *dst;
E 18

I 18
	if (p->in.op == SCONV) {
		src = p->in.left;
		dst = resc;
	} else {
		src = p->in.right;
		dst = p->in.left;
	}

E 18
	printf(".data\n\t.align\t2\nL%d:\n\t.long\t0x50800000", label2);
	if (p->in.type == DOUBLE)
D 18
		putstr(", 0x00000000");
	putstr(" # .double 4294967296\n\t.text\n\tmovl\t");
	adrput(p->in.left);
E 18
I 18
		putstr(", 0x00000000 # .double");
	else
		putstr(" # .float");
	putstr(" 4294967296\n\t.text\n\tmovl\t");
	adrput(src);
E 18
	putchar(',');
D 18
	adrput(resc);
E 18
I 18
	adrput(dst);
E 18
	putstr("\n\tcvl");
	prtype(p);
	putchar('\t');
D 18
	adrput(resc);
	printf("\n\tjgeq\tL%d\n\taddd\tL%d\nL%d:", label1, label2, label1);
E 18
I 18
	adrput(dst);
	printf("\n\tjgeq\tL%d\n\tadd", label1);
	prtype(p);
	printf("\tL%d\nL%d:", label2, label1);
E 18
E 15
I 3
}
E 3

I 12
D 13
#ifdef old
E 13
E 12
I 8
/*
I 14
 * Prlen() is a cheap prtype()...
 */
static char convtab[SZINT/SZCHAR + 1] = {
	'?', 'b', 'w', '?', 'l'
};
#define	prlen(len)	putchar(convtab[len])


/*
E 14
D 13
 * Generate code for storage conversions.
 */
sconv(p, forcc)
	NODE *p;
{
	register NODE *l, *r;
	register wfrom, wto;
	int oltype;

	l = getlr(p, '1');
	oltype = l->in.type, l->in.type = r->in.type;
	r = getlr(p, 'L');
	wfrom = tlen(r), wto = tlen(l);
	if (wfrom == wto)		/* e.g. int -> unsigned */
		goto done;
	/*
	 * Conversion in registers requires care
	 * as cvt and movz instruction don't work
	 * as expected (they end up as plain mov's).
	 */
	if (l->in.op == REG && r->in.op == REG) {
D 9
		if (ISUNSIGNED(r->in.type)) {		/* unsigned, mask */
			if (r->tn.lval != l->tn.lval) {
E 9
I 9
		if ((wfrom < wto && ISUNSIGNED(r->in.type)) ||
		    (wto < wfrom && ISUNSIGNED(l->in.type))) {
			/* unsigned, mask */
			if (r->tn.rval != l->tn.rval) {
E 9
				printf("\tandl3\t$%d,", (1<<(wto*SZCHAR))-1);
				adrput(r);
				putchar(',');
			} else
				printf("\tandl2\t$%d,", (1<<(wto*SZCHAR))-1);
			adrput(l);
		} else {				/* effect sign-extend */
D 9
			int shift = (sizeof (int)-wto)*SZCHAR;
			printf("\tshll\t$%d,", shift);
			adrput(r); putchar(','); adrput(l);
			printf("\n\tshar\t$%d,", shift);
			adrput(l); putchar(','); adrput(l);
			if (wfrom != sizeof (int)) {
				/*
				 * Must mask if result is shorter than
				 * the width of a register (to account
				 * for register treatment).
				 */
				printf("\n\tandl2\t$%d,",(1<<(wfrom*SZCHAR))-1);
				adrput(l);
			} else
				forcc = 0;
E 9
I 9
			printf("\tpushl\t"); adrput(r);
			printf("\n\tcvt"); prtype(l);
			printf("l\t%d(sp),", sizeof (int) - wto); adrput(l);
			printf("\n\tmovab\t4(sp),sp");
E 9
		}
		/*
D 9
		 * If condition codes are required and the last thing
		 * we did was mask the result, then we must generate a
E 9
I 9
		 * If condition codes are required then we must generate a
E 9
		 * test of the appropriate type.
		 */
		if (forcc) {
			printf("\n\tcmp");
			prtype(l);
			putchar('\t');
I 12
			printf("$0,");
E 12
D 10
			printf("$0,");
E 10
			adrput(l);
I 10
D 12
			printf(",$0");
E 12
E 10
		}
	} else {
		/*
		 * Conversion with at least one parameter in memory.
		 */
		if (wfrom < wto) {		/* expanding datum */
			if (ISUNSIGNED(r->in.type)) {
				printf("\tmovz");
				prtype(r);
				/*
				 * If target is a register, generate
				 * movz?l so optimizer can compress
				 * argument pushes.
				 */
				if (l->in.op == REG)
					putchar('l');
				else
					prtype(l);
			} else {
				printf("\tcvt");
				prtype(r), prtype(l);
			}
			putchar('\t');
			adrput(r);
		} else {			/* shrinking dataum */
			int off = wfrom - wto;
			if (l->in.op == REG) {
				printf("\tmovz");
				prtype(l);
				putchar('l');
			} else {
				printf("\tcvt");
				prtype(l), prtype(r);
			}
			putchar('\t');
			switch (r->in.op) {
			case NAME: case OREG:
				r->tn.lval += off;
				adrput(r);
				r->tn.lval -= off;
				break;
			case REG: case ICON: case UNARY MUL:
				adrput(r);
				break;
			default:
				cerror("sconv: bad shrink op");
				/*NOTREACHED*/
			}
		}
		putchar(',');
		adrput(l);
	}
	putchar('\n');
done:
	l->in.type = oltype;
}
I 12
#else /* new */
/*
E 13
 * Generate code for integral scalar conversions.
D 14
 * Many work-arounds for brain-damaged Tahoe register behavior.
E 14
I 14
 * Some of this code is designed to work around a tahoe misfeature
 *	that causes sign- and zero- extension to be defeated in
 *	certain circumstances.
 * Basically if the source operand of a CVT or MOVZ instruction is
 *	shorter than the destination, and the source is a register
 *	or an immediate constant, sign- and zero- extension are
 *	ignored and the high bits of the source are copied.  (Note
 *	that zero-extension is not a problem for immediate
 *	constants.)
I 30
 * Another problem -- condition codes for a conversion with a
 *	register source reflect the source rather than the destination.
E 30
E 14
 */
sconv(p, forcc)
	NODE *p;
	int forcc;
{
	register NODE *src, *dst;
	register NODE *tmp;
	register int srclen, dstlen;
	int srctype, dsttype;
	int val;
I 21
	int neg = 0;
E 21

	if (p->in.op == ASSIGN) {
D 18
		src = getlr(p, 'R');
		dst = getlr(p, 'L');
E 18
I 18
		src = p->in.right;
		dst = p->in.left;
E 18
		dstlen = tlen(dst);
		dsttype = dst->in.type;
D 18
	} else /* if (p->in.op == SCONV || optype(p->in.op) == LTYPE) */ {
		src = getlr(p, 'L');
		dst = getlr(p, '1');
E 18
I 18
	} else if (p->in.op == SCONV) {
		src = p->in.left;
		dst = resc;
E 18
		dstlen = tlen(p);
		dsttype = p->in.type;
I 18
	} else /* if (p->in.op == OPLEAF) */ {
		src = p;
		dst = resc;
		dstlen = SZINT/SZCHAR;
		dsttype = ISUNSIGNED(src->in.type) ? UNSIGNED : INT;
E 18
	}

D 14
	srclen = tlen(src);
	srctype = src->in.op == REG ?
		ISUNSIGNED(src->in.type) ? UNSIGNED : INT :
		src->in.type;
E 14
I 14
	if (src->in.op == REG) {
		srclen = SZINT/SZCHAR;
		srctype = ISUNSIGNED(src->in.type) ? UNSIGNED : INT;
	} else {
		srclen = tlen(src);
		srctype = src->in.type;
	}
E 14

I 14
D 20
	if (src->in.op == ICON) {
E 20
I 20
D 21
	if (src->in.op == ICON &&
#ifdef FLEXNAMES
	    (src->tn.name == NULL || *src->tn.name == '\0')
#else
	    src->tn.name[0] == '\0'
#endif
	) {
E 21
I 21
	if (src->in.op == ICON && src->tn.name[0] == '\0') {
E 21
E 20
		if (src->tn.lval == 0) {
			putstr("clr");
			prtype(dst);
			putchar('\t');
			adrput(dst);
			return;
		}
		if (dstlen < srclen) {
			switch (dsttype) {
			case CHAR:
				src->tn.lval = (char) src->tn.lval;
				break;
			case UCHAR:
				src->tn.lval = (unsigned char) src->tn.lval;
				break;
			case SHORT:
				src->tn.lval = (short) src->tn.lval;
				break;
			case USHORT:
				src->tn.lval = (unsigned short) src->tn.lval;
				break;
			}
		}
		if (dst->in.op == REG) {
			dsttype = INT;
			dstlen = SZINT/SZCHAR;
		}
		srctype = dsttype;
		srclen = dstlen;
I 21
D 26
		if ((val = src->tn.lval) & 1 << dstlen * SZCHAR - 1) {
			src->tn.lval = -(val | ~((1 << dstlen * SZCHAR) - 1));
E 26
I 26
		val = -src->tn.lval & ((1 << dstlen * SZCHAR) - 1);
		if ((unsigned) val < 64) {
			src->tn.lval = val;
E 26
			++neg;		/* MNEGx may be shorter */
		}
E 21
	}

E 14
	if (srclen < dstlen) {
		if (srctype == CHAR && dsttype == USHORT && dst->in.op == REG) {
			/* (unsigned short) c; => sign extend to 16 bits */
D 13
			putstr("\tcvtbl\t");
E 13
I 13
			putstr("cvtbl\t");
E 13
			adrput(src);
			putstr(",-(sp)\n\tmovzwl\t2(sp),");
			adrput(dst);
			putstr("\n\tmovab\t4(sp),sp");
			if (forcc) {
D 34
				/* inverted test */
				putstr("\n\tcmpl\t$0,");
E 34
I 34
				putstr("\n\ttstl\t");
E 34
				adrput(dst);
			}
			return;
		}
		genconv(ISUNSIGNED(srctype),
			srclen, dst->in.op == REG ? SZINT/SZCHAR : dstlen,
D 30
			src, dst);
E 30
I 30
			src, dst, forcc);
E 30
		return;
	}

	if (srclen > dstlen && dst->in.op == REG) {
I 14
		/* if dst is a register, the result must look like an int */
E 14
		if (src->in.op == REG) {
			if (ISUNSIGNED(dsttype)) {
				val = (1 << dstlen * SZCHAR) - 1;
				if (src->tn.rval == dst->tn.rval)
					/* conversion in place */
D 13
					printf("\tandl2\t$%#x,", val);
E 13
I 13
D 26
					printf("andl2\t$%#x,", val);
E 26
I 26
					printf("andl2\t$%ld,", val);
E 26
E 13
				else {
D 13
					printf("\tandl3\t$%#x,", val);
E 13
I 13
D 26
					printf("andl3\t$%#x,", val);
E 26
I 26
					printf("andl3\t$%ld,", val);
E 26
E 13
					adrput(src);
					putchar(',');
				}
				adrput(dst);
				return;
			}
D 14
			val = SZINT - srclen * SZCHAR;
D 13
			printf("\tshll\t$%d,", val);
E 13
I 13
			printf("shll\t$%d,", val);
E 14
I 14
			/*
			 * Sign extension in register can also be
			 * accomplished by shifts, but unfortunately
			 * shifts are extremely slow, due to the lack
			 * of a barrel shifter.
			 */
			putstr("pushl\t");
E 14
E 13
			adrput(src);
D 14
			putchar(',');
E 14
I 14
			putstr("\n\tcvt");
			prlen(dstlen);
			printf("l\t%d(sp),", SZINT/SZCHAR - dstlen);
E 14
			adrput(dst);
D 14
			printf("\n\tshar\t$%d,", val);
			adrput(dst);
			putchar(',');
			adrput(dst);
E 14
I 14
			putstr("\n\tmovab\t4(sp),sp");
			if (forcc) {
D 34
				/* inverted test */
				putstr("\n\tcmpl\t$0,");
E 34
I 34
				putstr("\n\ttstl\t");
E 34
				adrput(dst);
			}
E 14
			return;
		}
		tmp = talloc();
D 26
		if ((src->in.op == UNARY MUL &&
		    ((src->in.left->in.op == NAME ||
		     (src->in.left->in.op == ICON)))) ||
E 26
I 26
		if ((src->in.op == NAME) ||
		    (src->in.op == UNARY MUL && src->in.left->in.op == ICON) ||
E 26
		    (src->in.op == OREG && !R2TEST(src->tn.rval))) {
			/* we can increment src's address & pun it */
			*tmp = *src;
			tmp->tn.lval += srclen - dstlen;
		} else {
			/* we must store src's address */
			*tmp = *dst;
D 13
			putstr("\tmovab\t");
E 13
I 13
D 14
			putstr("movab\t");
E 14
I 14
			putstr("mova");
			prlen(srclen);
			putchar('\t');
E 14
E 13
			adrput(src);
			putchar(',');
			adrput(tmp);
D 13
			putchar('\n');
E 13
I 13
			putstr("\n\t");
E 13
			tmp->tn.op = OREG;
			tmp->tn.lval = srclen - dstlen;
		}
D 30
		genconv(ISUNSIGNED(dsttype), dstlen, SZINT/SZCHAR, tmp, dst);
E 30
I 30
		genconv(ISUNSIGNED(dsttype), dstlen, SZINT/SZCHAR, tmp, dst, forcc);
E 30
		tmp->in.op = FREE;
		return;
	}

D 21
	genconv(ISUNSIGNED(dsttype),
E 21
I 21
	genconv(neg ? -1 : ISUNSIGNED(dsttype),
E 21
		srclen, dst->in.op == REG ? SZINT/SZCHAR : dstlen,
D 30
		src, dst);
E 30
I 30
		src, dst, forcc);
E 30
}

D 21
genconv(usrc, srclen, dstlen, src, dst)
D 14
	int usrc, srclen, dstlen;
E 14
I 14
	int usrc;
E 21
I 21
D 30
genconv(srcflag, srclen, dstlen, src, dst)
E 30
I 30
genconv(srcflag, srclen, dstlen, src, dst, forcc)
E 30
	int srcflag;
E 21
	register int srclen, dstlen;
E 14
	NODE *src, *dst;
I 30
	int forcc;
E 30
{
D 14
	static char convtab[SZINT/SZCHAR + 1] = {
		'?', 'b', 'w', '?', 'l'
	};

E 14
	if (srclen != dstlen) {
D 21
		if (usrc && srclen < dstlen)
E 21
I 21
		if (srcflag > 0 && srclen < dstlen)
E 21
D 13
			putstr("\tmovz");
E 13
I 13
			putstr("movz");
E 13
		else
D 13
			putstr("\tcvt");
E 13
I 13
			putstr("cvt");
E 13
D 14
		putchar(convtab[srclen]);
E 14
I 14
		prlen(srclen);
E 14
D 21
	} else
E 21
I 21
	} else if (srcflag < 0)
		putstr("mneg");
	else
E 21
D 13
		putstr("\tmov");
E 13
I 13
		putstr("mov");
E 13
D 14
	putchar(convtab[dstlen]);
E 14
I 14
	prlen(dstlen);
E 14
	putchar('\t');
	adrput(src);
	putchar(',');
	adrput(dst);
I 30

	/*
	 * This hack is made necessary by architecture problems
	 *	described above
	 */
	if (forcc && src->in.op == REG && srclen > dstlen) {
		putstr("\n\ttst");
		prlen(dstlen);
		putchar('\t');
		adrput(dst);
	}
E 30
}
D 13
#endif /* new */
E 13
E 12

E 8
D 25
rmove( rt, rs, t ) TWORD t;{
E 25
I 25
rmove( rt, rs, t ) TWORD t; {
E 25
	printf( "	movl	%s,%s\n", rname(rs), rname(rt) );
	if(t==DOUBLE)
		printf( "	movl	%s,%s\n", rname(rs+1), rname(rt+1) );
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
	fregs = 6;	/* tbl- 6 free regs on Tahoe (0-5) */
	}

I 4
#ifndef szty
E 4
szty(t) TWORD t;{ /* size, in registers, needed to hold thing of type t */
	return(t==DOUBLE ? 2 : 1 );
	}
I 4
#endif
E 4

I 25
/*ARGSUSED*/
E 25
rewfld( p ) NODE *p; {
	return(1);
	}

I 25
/*ARGSUSED*/
E 25
callreg(p) NODE *p; {
	return( R0 );
	}

base( p ) register NODE *p; {
	register int o = p->in.op;

D 26
	if( (o==ICON && p->in.name[0] != '\0')) return( 100 ); /* ie no base reg */
E 26
I 26
	if( o==ICON && p->in.name[0] != '\0' ) return( 100 ); /* ie no base reg */
E 26
	if( o==REG ) return( p->tn.rval );
    if( (o==PLUS || o==MINUS) && p->in.left->in.op == REG && p->in.right->in.op==ICON)
		return( p->in.left->tn.rval );
    if( o==OREG && !R2TEST(p->tn.rval) && (p->in.type==INT || p->in.type==UNSIGNED || ISPTR(p->in.type)) )
		return( p->tn.rval + 0200*1 );
I 26
	if( o==NAME ) return( 100 + 0200*1 );
E 26
	return( -1 );
	}

offset( p, tyl ) register NODE *p; int tyl; {

D 25
	if(tyl > 8) return( -1 );
	if( tyl==1 && p->in.op==REG && (p->in.type==INT || p->in.type==UNSIGNED) ) return( p->tn.rval );
	if( (p->in.op==LS && p->in.left->in.op==REG && (p->in.left->in.type==INT || p->in.left->in.type==UNSIGNED) &&
	      (p->in.right->in.op==ICON && p->in.right->in.name[0]=='\0')
	      && (1<<p->in.right->tn.lval)==tyl))
E 25
I 25
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
E 25
		return( p->in.left->tn.rval );
I 25
	if( tyl==2 &&
	    p->in.op==PLUS &&
	    (p->in.left->in.type==INT || p->in.left->in.type==UNSIGNED) &&
	    p->in.left->in.op==REG &&
	    p->in.right->in.op==REG &&
	    p->in.left->tn.rval==p->in.right->tn.rval )
		return( p->in.left->tn.rval );
E 25
	return( -1 );
	}

makeor2( p, q, b, o) register NODE *p, *q; register int b, o; {
	register NODE *t;
D 25
	register int i;
E 25
	NODE *f;

	p->in.op = OREG;
	f = p->in.left; 	/* have to free this subtree later */

	/* init base */
	switch (q->in.op) {
		case ICON:
		case REG:
		case OREG:
I 26
		case NAME:
E 26
			t = q;
			break;

		case MINUS:
			q->in.right->tn.lval = -q->in.right->tn.lval;
		case PLUS:
			t = q->in.right;
			break;

		case UNARY MUL:
			t = q->in.left->in.left;
			break;

		default:
			cerror("illegal makeor2");
	}

	p->tn.lval = t->tn.lval;
#ifndef FLEXNAMES
D 25
	for(i=0; i<NCHNAM; ++i)
		p->in.name[i] = t->in.name[i];
E 25
I 25
	{
		register int i;
		for(i=0; i<NCHNAM; ++i)
			p->in.name[i] = t->in.name[i];
	}
E 25
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

I 4
#ifndef shltype
E 4
shltype( o, p ) register NODE *p; {
	return( o== REG || o == NAME || o == ICON || o == OREG || ( o==UNARY MUL && shumul(p->in.left)) );
	}
I 4
#endif
E 4

flshape( p ) NODE *p; {
	register int o = p->in.op;

	if( o==NAME || o==REG || o==ICON || o==OREG || (o==UNARY MUL && shumul(p->in.left)) ) return(1);
	return(0);
	}

I 25
/* INTEMP shapes must not contain any temporary registers */
E 25
shtemp( p ) register NODE *p; {
I 25
	int r;

E 25
	if( p->in.op == STARG ) p = p->in.left;
D 25
	return( p->in.op==NAME || p->in.op ==ICON || p->in.op == OREG || (p->in.op==UNARY MUL && shumul(p->in.left)) );
E 25
I 25

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
	case UNARY MUL:
		p = p->in.left;
		return( p->in.op != UNARY MUL && shtemp(p) );
		}

	if( optype( p->in.op ) != LTYPE ) return(0);
	return(1);
E 25
	}

shumul( p ) register NODE *p; {
	register int o;
	extern int xdebug;

	if (xdebug) {
		 printf("\nshumul:op=%d,lop=%d,rop=%d", p->in.op, p->in.left->in.op, p->in.right->in.op);
		printf(" prname=%s,plty=%d, prlval=%D\n", p->in.right->in.name, p->in.left->in.type, p->in.right->tn.lval);
		}

	o = p->in.op;
	if(( o == NAME || (o == OREG && !R2TEST(p->tn.rval)) || o == ICON )
	 && p->in.type != PTR+DOUBLE)
		return( STARNM );

	return( 0 );
	}

I 26
special( p, shape ) register NODE *p; {
	if( shape==SIREG && p->in.op == OREG && R2TEST(p->tn.rval) ) return(1);
	else return(0);
}

E 26
D 25
special( p, shape ) register NODE *p; {
	if( shape==SIREG && p->in.op == OREG && R2TEST(p->tn.rval) ) return(1);
	else return(0);
}

E 25
adrcon( val ) CONSZ val; {
D 2
	printf( "$" );
	printf( CONFMT, val );
E 2
I 2
	printf(ACONFMT, val);
E 2
	}

conput( p ) register NODE *p; {
	switch( p->in.op ){

	case ICON:
		acon( p );
		return;

	case REG:
D 5
		printf( "%s", rname(p->tn.rval) );
E 5
I 5
		putstr(rname(p->tn.rval));
E 5
		return;

	default:
		cerror( "illegal conput" );
		}
	}

I 25
/*ARGSUSED*/
E 25
insput( p ) NODE *p; {
	cerror( "insput" );
D 3
	}

upput( p ) register NODE *p; {
	/* output the address of the second long in the
	   pair pointed to by p (for DOUBLEs)*/
	CONSZ save;

	if( p->in.op == FLD ){
		p = p->in.left;
		}
	switch( p->in.op ){

	case NAME:
	case OREG:
		save = p->tn.lval;
		p->tn.lval += SZLONG/SZCHAR;
		adrput(p);
		p->tn.lval = save;
		return;

	case REG:
		printf( "%s", rname(p->tn.rval+1) );
		return;

	default:
		cerror( "illegal upper address" );
		}
E 3
	}

I 25
/*
 * Output the address of the second item in the
 * pair pointed to by p.
 */
upput(p, size)
	register NODE *p;
{
	CONSZ save;

	if (p->in.op == FLD)
		p = p->in.left;
	switch (p->in.op) {

	case NAME:
	case OREG:
		save = p->tn.lval;
		p->tn.lval += size/SZCHAR;
		adrput(p);
		p->tn.lval = save;
		break;

	case REG:
		if (size == SZLONG) {
			putstr(rname(p->tn.rval+1));
			break;
		}
		/* fall thru... */

	default:
		cerror("illegal upper address op %s size %d",
		    opst[p->tn.op], size);
		/*NOTREACHED*/
	}
}

E 25
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
D 5
		printf( "$" );
E 5
I 5
		putchar('$');
E 5
		acon( p );
		return;

	case REG:
D 5
		printf( "%s", rname(p->tn.rval) );
E 5
I 5
		putstr(rname(p->tn.rval));
E 5
		if(p->in.type == DOUBLE)	/* for entry mask */
			(void) rname(p->tn.rval+1);
		return;

	case OREG:
		r = p->tn.rval;
		if( R2TEST(r) ){ /* double indexing */
			register int flags;

			flags = R2UPK3(r);
D 5
			if( flags & 1 ) printf("*");
E 5
I 5
			if( flags & 1 ) putchar('*');
E 5
			if( p->tn.lval != 0 || p->in.name[0] != '\0' ) acon(p);
			if( R2UPK1(r) != 100) printf( "(%s)", rname(R2UPK1(r)) );
			printf( "[%s]", rname(R2UPK2(r)) );
			return;
			}
		if( r == FP && p->tn.lval > 0 ){  /* in the argument region */
			if( p->in.name[0] != '\0' ) werror( "bad arg temp" );
			printf( CONFMT, p->tn.lval );
D 5
			printf( "(fp)" );
E 5
I 5
			putstr( "(fp)" );
E 5
			return;
			}
		if( p->tn.lval != 0 || p->in.name[0] != '\0') acon( p );
		printf( "(%s)", rname(p->tn.rval) );
		return;

	case UNARY MUL:
		/* STARNM or STARREG found */
		if( tshape(p, STARNM) ) {
D 5
			printf( "*" );
E 5
I 5
			putchar( '*' );
E 5
			adrput( p->in.left);
			}
		return;

	default:
		cerror( "illegal address" );
		return;

		}

	}

acon( p ) register NODE *p; { /* print out a constant */

D 25
	if( p->in.name[0] == '\0' ){
E 25
I 25
	if( p->in.name[0] == '\0' )
E 25
		printf( CONFMT, p->tn.lval);
D 5
		}
	else if( p->tn.lval == 0 ) {
E 5
I 5
D 25
		return;
	} else {
E 25
I 25
	else {
E 25
E 5
#ifndef FLEXNAMES
		printf( "%.8s", p->in.name );
#else
D 5
		printf( "%s", p->in.name );
E 5
I 5
D 25
		putstr(p->in.name);
E 25
I 25
		putstr( p->in.name );
E 25
E 5
#endif
I 5
D 25
		if (p->tn.lval != 0) {
			putchar('+');
			printf(CONFMT, p->tn.lval);
E 25
I 25
		if( p->tn.lval != 0 ) {
			putchar( '+' );
			printf( CONFMT, p->tn.lval );
			}
E 25
E 5
		}
D 5
	else {
#ifndef FLEXNAMES
		printf( "%.8s+", p->in.name );
#else
		printf( "%s+", p->in.name );
#endif
		printf( CONFMT, p->tn.lval );
		}
E 5
I 5
	}
E 5
D 25
	}
E 25

genscall( p, cookie ) register NODE *p; {
	/* structure valued call */
	return( gencall( p, cookie ) );
	}

genfcall( p, cookie ) register NODE *p; {
	register NODE *p1;
	register int m;
	static char *funcops[6] = {
		"sin", "cos", "sqrt", "exp", "log", "atan"
	};

	/* generate function opcodes */
	if(p->in.op==UNARY FORTCALL && p->in.type==FLOAT &&
	 (p1 = p->in.left)->in.op==ICON &&
	 p1->tn.lval==0 && p1->in.type==INCREF(FTN|FLOAT)) {
#ifdef FLEXNAMES
		p1->in.name++;
#else
		strcpy(p1->in.name, p1->in.name[1]);
#endif
		for(m=0; m<6; m++)
			if(!strcmp(p1->in.name, funcops[m]))
				break;
		if(m >= 6)
			uerror("no opcode for fortarn function %s", p1->in.name);
	} else
		uerror("illegal type of fortarn function");
	p1 = p->in.right;
	p->in.op = FORTCALL;
	if(!canaddr(p1))
		order( p1, INAREG|INBREG|SOREG|STARREG|STARNM );
	m = match( p, INTAREG|INTBREG );
	return(m != MDONE);
}

/* tbl */
int gc_numbytes;
/* tbl */

I 25
/*ARGSUSED*/
E 25
gencall( p, cookie ) register NODE *p; {
	/* generate the call given by p */
	register NODE *p1, *ptemp;
	register int temp, temp1;
	register int m;

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

/* tbl
	setup gc_numbytes so reference to ZC works */

	gc_numbytes = temp&(0x3ff);

	p->in.op = UNARY CALL;
	m = match( p, INTAREG|INTBREG );

	return(m != MDONE);
	}

/* tbl */
char *
ccbranches[] = {
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
	};
/* tbl */

I 25
/*ARGSUSED*/
E 25
cbgen( o, lab, mode ) { /*   printf conditional and unconditional branches */

D 25
		if(o != 0 && (o < EQ || o > UGT ))
			cerror( "bad conditional branch: %s", opst[o] );
		printf( "	j%s	L%d\n",
		 o == 0 ? "br" : ccbranches[o-EQ], lab );
E 25
I 25
	if( o != 0 && ( o < EQ || o > UGT ) )
		cerror( "bad conditional branch: %s", opst[o] );
	printf( "	j%s	L%d\n", o == 0 ? "br" : ccbranches[o-EQ], lab );
E 25
	}

nextcook( p, cookie ) NODE *p; {
	/* we have failed to match p with cookie; try another */
	if( cookie == FORREW ) return( 0 );  /* hopeless! */
	if( !(cookie&(INTAREG|INTBREG)) ) return( INTAREG|INTBREG );
	if( !(cookie&INTEMP) && asgop(p->in.op) ) return( INTEMP|INAREG|INTAREG|INTBREG|INBREG );
	return( FORREW );
	}

I 25
/*ARGSUSED*/
E 25
lastchance( p, cook ) NODE *p; {
	/* forget it! */
	return(0);
	}

optim2( p ) register NODE *p; {
D 25
# ifdef ONEPASS
E 25
	/* do local tree transformations and optimizations */
D 25
# define RV(p) p->in.right->tn.lval
I 4
# define nncon(p)	((p)->in.op == ICON && (p)->in.name[0] == 0)
E 4
D 8
	register int o = p->in.op;
	register int i;
E 8
I 8
	register int o, i;
E 25
I 25

	int o;
	int i, mask;
E 25
	register NODE *l, *r;
I 24
D 25
	int lower, upper, result;
E 25
E 24
E 8

D 8
	/* change unsigned mods and divs to logicals (mul is done in mip & c2) */
	if(optype(o) == BITYPE && ISUNSIGNED(p->in.left->in.type)
	 && nncon(p->in.right) && (i=ispow2(RV(p)))>=0){
		switch(o) {
		case DIV:
		case ASG DIV:
			p->in.op = RS;
			RV(p) = i;
			break;
		case MOD:
		case ASG MOD:
			p->in.op = AND;
			RV(p)--;
			break;
		default:
			return;
E 8
I 8
D 25
	switch (o = p->in.op) {
E 25
I 25
	switch( o = p->in.op ) {
E 25

I 26
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

E 26
D 25
	case DIV: case ASG DIV:
	case MOD: case ASG MOD:
		/*
		 * Change unsigned mods and divs to
		 * logicals (mul is done in mip & c2)
		 */
		if (ISUNSIGNED(p->in.left->in.type) && nncon(p->in.right) &&
		    (i = ispow2(RV(p))) >= 0) {
			if (o == DIV || o == ASG DIV) {
				p->in.op = RS;
				RV(p) = i;
			} else {
				p->in.op = AND;
				RV(p)--;
E 25
I 25
	case AND:
	case ASG AND:
		r = p->in.right;
		if( r->in.op==ICON && r->in.name[0]==0 ) {
			/* check for degenerate operations */
			l = p->in.left;
			mask = (1 << tlen(l) * SZCHAR) - 1;
D 26
			if( ISUNSIGNED(r->in.type) ) {
				i = (r->tn.lval & mask);
E 26
I 26
			if( o == ASG AND || ISUNSIGNED(r->in.type) ) {
				i = r->tn.lval & mask;
E 26
				if( i == mask ) {
I 26
					/* redundant mask */
E 26
					r->in.op = FREE;
					ncopy(p, l);
					l->in.op = FREE;
					break;
					}
				else if( i == 0 )
I 26
					/* all bits masked off */
E 26
					goto zero;
D 26
				else
					r->tn.lval = i;
E 26
I 26
				r->tn.lval = i;
				if( tlen(l) < SZINT/SZCHAR ){
					/* sign extend */
					if( r->tn.lval & (mask & ~(mask >> 1)) )
						r->tn.lval |= ~mask;
					else
						r->tn.lval &= mask;
					}
E 26
				}
			else if( r->tn.lval == mask &&
				 tlen(l) < SZINT/SZCHAR ) {
I 26
				/* use movz instead of and */
E 26
				r->in.op = SCONV;
				r->in.left = l;
				r->in.right = 0;
				r->in.type = ENUNSIGN(l->in.type);
				r->in.su = l->in.su > 1 ? l->in.su : 1;
				ncopy(p, r);
				p->in.left = r;
				p->in.type = INT;
				}
E 25
			}
D 25
			if (asgop(o))
				p->in.op = ASG p->in.op;
E 8
		}
D 8
		if(asgop(o))
			p->in.op = ASG p->in.op;
E 8
I 8
		return;
E 25
I 25
		break;
E 25

	case SCONV:
		l = p->in.left;
D 18
		/* clobber conversions w/o side effects */
		if (!anyfloat(p, l) && l->in.op != PCONV &&
E 18
I 18
D 25
		if (anyfloat(p, l)) {
			/* save some labor later */
			NODE *t = talloc();
E 25
I 25
		if( p->in.type == FLOAT || p->in.type == DOUBLE ||
		    l->in.type == FLOAT || l->in.type == DOUBLE )
			return;
D 26
		if( l->in.op == PCONV || l->in.op == CALL || l->in.op == UNARY CALL )
E 26
I 26
		if( l->in.op == PCONV )
E 26
			return;
I 26
		if( (l->in.op == CALL || l->in.op == UNARY CALL) &&
		    l->in.type != INT && l->in.type != UNSIGNED )
			return;
E 26
E 25

D 25
			if (p->in.type == UCHAR || p->in.type == USHORT) {
				*t = *p;
				t->in.type = UNSIGNED;
				p->in.left = t;
			} else if (l->in.type == UCHAR || l->in.type == USHORT) {
				*t = *p;
				t->in.type = INT;
				p->in.left = t;
			}
		} else if (l->in.op != PCONV &&
E 18
I 17
		    l->in.op != CALL && l->in.op != UNARY CALL &&
E 17
		    tlen(p) == tlen(l)) {
I 18
			/* clobber conversions w/o side effects */
E 18
			if (l->in.op != FLD)
				l->in.type = p->in.type;
			ncopy(p, l);
			l->in.op = FREE;
		}
		return;
E 25
I 25
		/* Only trust it to get it right if the size is the same */
		if( tlen(p) != tlen(l) )
			return;
E 25

I 25
		/* clobber conversion */
		if( l->in.op != FLD )
			l->in.type = p->in.type;
		ncopy( p, l );
		l->in.op = FREE;

		break;

E 25
	case ASSIGN:
		/*
D 25
		 * Try to zap storage conversions of non-float items.
E 25
I 25
		 * Conversions are equivalent to assignments;
		 * when the two operations are combined,
		 * we can sometimes zap the conversion.
E 25
		 */
		r = p->in.right;
D 19
		if (r->in.op == SCONV && !anyfloat(r->in.left, r)) {
E 19
I 19
D 25
		if (r->in.op == SCONV) {
E 19
			int wdest, wconv, wsrc;
I 19

I 22
			if (p->in.left->in.op == FLD)
				return;
E 22
			if (anyfloat(r, r->in.left)) {
				/* let the code table handle two cases */
				if (p->in.left->in.type == UNSIGNED && 
					   r->in.type == UNSIGNED) {
					p->in.right = r->in.left;
					r->in.op = FREE;
				} else if ((p->in.left->in.type == FLOAT ||
					    p->in.left->in.type == DOUBLE) &&
					   p->in.left->in.type == r->in.type &&
					   r->in.left->in.type == UNSIGNED) {
					p->in.right = r->in.left;
					r->in.op = FREE;
				}
				return;
			}
E 19
			wdest = tlen(p->in.left);
			wconv = tlen(r);
			/*
			 * If size doesn't change across assignment or
			 * conversion expands src before shrinking again
			 * due to the assignment, delete conversion so
			 * code generator can create optimal code.
			 */
			if (wdest == wconv ||
			 (wdest == (wsrc = tlen(r->in.left)) && wconv > wsrc)) {
E 25
I 25
		l = p->in.left;
		if ( r->in.op == SCONV &&
		     !mixtypes(l, r) &&
		     l->in.op != FLD &&
		     tlen(l) == tlen(r) ) {
E 25
				p->in.right = r->in.left;
				r->in.op = FREE;
			}
I 24
D 25
		}
		return;
E 25
I 25
		break;
E 25

	case ULE:
	case ULT:
	case UGE:
	case UGT:
D 25
		o -= (UGE-GE);
E 25
I 25
		p->in.op -= (UGE-GE);
		if( degenerate(p) )
			break;
		p->in.op += (UGE-GE);
		break;

E 25
	case EQ:
	case NE:
	case LE:
	case LT:
	case GE:
	case GT:
I 26
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
E 26
I 25
		(void) degenerate(p);
		break;

	case DIV:
		if( p->in.right->in.op == ICON &&
		    p->in.right->tn.name[0] == '\0' &&
		    ISUNSIGNED(p->in.right->in.type) &&
		    (unsigned) p->in.right->tn.lval >= 0x80000000 ) {
			/* easy to do here, harder to do in zzzcode() */
			p->in.op = UGE;
			break;
			}
	case MOD:
	case ASG DIV:
	case ASG MOD:
E 25
		/*
D 25
		 * Optimize comparisons against constants which are
		 * out of the range of a variable's precision.
		 * This saves some labor out in the code table
		 * handling ridiculous comparisons...
E 25
I 25
		 * optimize DIV and MOD
		 *
		 * basically we spot UCHAR and USHORT and try to do them
		 * as signed ints...  this may need tuning for the tahoe.
E 25
		 */
I 25
		if( degenerate(p) )
			break;
		l = p->in.left;
E 25
		r = p->in.right;
I 25
		if( !ISUNSIGNED(r->in.type) ||
		    tlen(l) >= SZINT/SZCHAR ||
		    !(tlen(r) < SZINT/SZCHAR ||
		      (r->in.op == ICON && r->tn.name[0] == '\0')) )
			break;
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
			}
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
E 25
		l = p->in.left;
D 25
		if (r->in.op != ICON ||
		    r->tn.name[0] != '\0' ||
		    tlen(l) >= tlen(r))
			return;
		switch (l->in.type) {
		case CHAR:
			lower = -(1 << SZCHAR - 1);
			upper = (1 << SZCHAR - 1) - 1;
E 25
I 25
		r = p->in.right;
		if( !(r->in.op == ICON && r->tn.name[0] == '\0') )
E 25
			break;
D 25
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
			cerror("unsupported OPLOG in optim2");
		}
		result = -1;
E 25
		i = r->tn.lval;
D 25
		switch (o) {
		case EQ:
		case NE:
			if (lower == 0 && (unsigned) i > upper)
				result = o == NE;
			else if (i < lower || i > upper)
				result = o == NE;
E 25
I 25
		if( i < 0 )
			/* front end 'fixes' this? */
			if( o == LS || o == ASG LS )
				o += (RS-LS);
			else
				o += (LS-RS);
		if( (o == RS || o == ASG RS) &&
		    !ISUNSIGNED(l->in.type) )
			/* can't optimize signed right shifts */
E 25
			break;
D 25
		case LT:
		case GE:
			if (lower == 0 && (unsigned) i > upper)
				result = o == LT;
			else if (i <= lower)
				result = o != LT;
			else if (i > upper)
				result = o == LT;
			break;
		case LE:
		case GT:
			if (lower == 0 && (unsigned) i >= upper)
				result = o == LE;
			else if (i < lower)
				result = o != LE;
			else if (i >= upper)
				result = o == LE;
			break;
E 25
I 25
		if( o == LS ) {
			if( i < SZINT )
				break;
			}
		else {
			if( i < tlen(l) * SZCHAR )
				break;
			}
	zero:
		if( !asgop( o ) )
			if( tshape(l, SAREG|SNAME|SCON|SOREG|STARNM) ) {
				/* no side effects */
				tfree(l);
				ncopy(p, r);
				r->in.op = FREE;
				p->tn.lval = 0;
				}
			else {
				p->in.op = COMOP;
				r->tn.lval = 0;
				}
		else {
			p->in.op = ASSIGN;
			r->tn.lval = 0;
			}
		break;
E 25
		}
D 25
		if (result == -1)
			return;
E 25
I 25
	}
E 25

D 25
		if (tshape(l, SAREG|SNAME|SCON|SOREG|STARNM)) {
			l->in.op = FREE;
			ncopy(p, r);
			r->in.op = FREE;
			p->tn.type = INT;
			p->tn.lval = result;
		} else {
E 25
I 25
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
		cerror("unsupported type in degenerate()");
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
		tfree(l);
		ncopy(p, r);
		r->in.op = FREE;
		p->tn.lval = result;
		}
	else {
		if( o == ASG DIV )
			p->in.op = ASSIGN;
		else {
E 25
			p->in.op = COMOP;
D 25
			p->in.type = INT;
E 25
			r->tn.type = INT;
D 25
			r->tn.lval = result;
E 25
I 25
			}
		r->tn.lval = result;
E 25
E 24
I 18
D 19
		} else if (p->in.left->in.type == UNSIGNED && 
			   r->in.type == UNSIGNED) {
			/* let the code table handle it */
			p->in.right = r->in.left;
			r->in.op = FREE;
		} else if ((p->in.left->in.type == FLOAT ||
			    p->in.left->in.type == DOUBLE) &&
			   p->in.left->in.type == r->in.type &&
			   r->in.left->in.type == UNSIGNED) {
			/* let the code table handle it */
			p->in.right = r->in.left;
			r->in.op = FREE;
E 19
E 18
		}
D 25
		return;
E 25
I 25
	if( logop(o) )
		p->in.type = INT;

	return (1);
E 25
E 8
	}
D 25
# endif
}
E 25

struct functbl {
	int fop;
I 16
	TWORD ftype;
E 16
	char *func;
D 16
} opfunc[] = {
	DIV,		"udiv", 
	ASG DIV,	"udiv", 
	0
};
E 16
I 16
	} opfunc[] = {
	DIV,		TANY,	"udiv",
	MOD,		TANY,	"urem",
	ASG DIV,	TANY,	"audiv",
	ASG MOD,	TANY,	"aurem",
	0,	0,	0 };
E 16

hardops(p)  register NODE *p; {
	/* change hard to do operators into function calls.  */
	register NODE *q;
	register struct functbl *f;
D 16
	register int o;
	register TWORD t, t1, t2;
E 16
I 16
	register o;
	NODE *old,*temp;
E 16

	o = p->in.op;
I 16
	if( ! (optype(o)==BITYPE &&
	       (ISUNSIGNED(p->in.left->in.type) ||
		ISUNSIGNED(p->in.right->in.type))) )
		return;
E 16

	for( f=opfunc; f->fop; f++ ) {
		if( o==f->fop ) goto convert;
D 16
	}
E 16
I 16
		}
E 16
	return;

	convert:
I 25
	if( p->in.right->in.op == ICON && p->in.right->tn.name[0] == '\0' )
		/* 'J' in zzzcode() -- assumes DIV or MOD operations */
		/* save a subroutine call -- use at most 5 instructions */
		return;
	if( tlen(p->in.left) < SZINT/SZCHAR && tlen(p->in.right) < SZINT/SZCHAR )
		/* optim2() will modify the op into an ordinary int op */
		return;
E 25
D 16
	t = p->in.type;
	t1 = p->in.left->in.type;
	t2 = p->in.right->in.type;
D 7
	if ( t1 != UNSIGNED && (t2 != UNSIGNED)) return;
E 7
I 7

	if (!((ISUNSIGNED(t1) && !(ISUNSIGNED(t2))) || 
	     ( t2 == UNSIGNED))) return;
E 7

	/* need to rewrite tree for ASG OP */
	/* must change ASG OP to a simple OP */
E 16
	if( asgop( o ) ) {
D 16
		q = talloc();
		q->in.op = NOASG ( o );
		q->in.rall = NOPREF;
		q->in.type = p->in.type;
		q->in.left = tcopy(p->in.left);
		q->in.right = p->in.right;
		p->in.op = ASSIGN;
		p->in.right = q;
		zappost(q->in.left); /* remove post-INCR(DECR) from new node */
		fixpre(q->in.left);	/* change pre-INCR(DECR) to +/-	*/
		p = q;
E 16
I 16
		old = NIL;
		switch( p->in.left->in.op ){
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
E 16

D 16
	}
	/* turn logicals to compare 0 */
	else if( logop( o ) ) {
		ncopy(q = talloc(), p);
		p->in.left = q;
		p->in.right = q = talloc();
		q->in.op = ICON;
		q->in.type = INT;
#ifndef FLEXNAMES
		q->in.name[0] = '\0';
E 16
I 16
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
E 16
#else
D 16
		q->in.name = "";
E 16
I 16
				q->in.name[0] = '\0';
E 16
#endif
D 16
		q->tn.lval = 0;
		q->tn.rval = 0;
		p = p->in.left;
	}
E 16
I 16
				temp->in.left = q;
			}
			break;
E 16

D 16
	/* build comma op for args to function */
	t1 = p->in.left->in.type;
	t2 = 0;
	if ( optype(p->in.op) == BITYPE) {
		q = talloc();
		q->in.op = CM;
		q->in.rall = NOPREF;
		q->in.type = INT;
		q->in.left = p->in.left;
		q->in.right = p->in.right;
		t2 = p->in.right->in.type;
	} else
		q = p->in.left;
E 16
I 16
		case UNARY MUL:
			/* avoid doing side effects twice */
			q = p->in.left;
			p->in.left = q->in.left;
			q->in.op = FREE;
			break;
E 16

I 16
		default:
			cerror( "hardops: can't compute & LHS" );
			}
		}

	/* build comma op for args to function */
	q = talloc();
	q->in.op = CM;
	q->in.rall = NOPREF;
	q->in.type = INT;
	q->in.left = p->in.left;
	q->in.right = p->in.right;
E 16
	p->in.op = CALL;
	p->in.right = q;

	/* put function name in left node of call */
	p->in.left = q = talloc();
	q->in.op = ICON;
	q->in.rall = NOPREF;
	q->in.type = INCREF( FTN + p->in.type );
#ifndef FLEXNAMES
D 16
		strcpy( q->in.name, f->func );
E 16
I 16
	strcpy( q->in.name, f->func );
E 16
#else
D 16
		q->in.name = f->func;
E 16
I 16
	q->in.name = f->func;
E 16
#endif
	q->tn.lval = 0;
	q->tn.rval = 0;

	}

zappost(p) NODE *p; {
	/* look for ++ and -- operators and remove them */

	register int o, ty;
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

	register int o, ty;
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

I 25
/*ARGSUSED*/
E 25
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
I 25
	/*NOTREACHED*/
E 25
}

# ifndef ONEPASS
main( argc, argv ) char *argv[]; {
	return( mainp2( argc, argv ) );
	}
# endif

I 8
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

E 8
myreader(p) register NODE *p; {
I 8
	strip( p );		/* strip off operations with no side effects */
I 25
	canon( p );		/* expands r-vals for fields */
E 25
E 8
	walkf( p, hardops );	/* convert ops to function calls */
D 25
	canon( p );		/* expands r-vals for fileds */
E 25
	walkf( p, optim2 );
	}
E 1
