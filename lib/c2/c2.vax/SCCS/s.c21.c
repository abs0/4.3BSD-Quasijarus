h02462
s 00002/00002/01586
d D 4.35 00/08/31 22:44:03 msokolov 36 35
c .globl is now called GLOBL, not EROU
e
s 00023/00040/01565
d D 4.34 00/08/29 22:18:47 msokolov 35 34
c (addsob): SOB, AOB, and ACB relaxation is here! Take advantage of it.
e
s 00134/00043/01471
d D 4.33 00/08/09 19:40:50 msokolov 34 33
c (addsob): Thorough cleanup. Reformat, fix minor bugs and deficiencies, get
c ready for the upcoming addition of SOB, AOB, and ACB relaxation to as.
e
s 00001/00001/01513
d D 4.32 00/08/09 19:26:46 msokolov 33 32
c Fix catastrophic breakage from my delta 4.28. Now this will teach me to test
c code at least minimally before checking it in... (red face)
e
s 00003/00001/01511
d D 4.31 00/08/08 20:51:55 msokolov 32 31
c (redunbr) doing a savereg() on RT2 is totally bogus
e
s 00000/00001/01512
d D 4.30 00/08/08 20:48:21 msokolov 31 30
c (rmove case CBR): don't clear ccloc
e
s 00005/00001/01508
d D 4.29 00/08/08 20:46:48 msokolov 30 29
c (rmove case TST): Don't do a bogus setcc() after throwing out a redundant TST
e
s 00002/00000/01507
d D 4.28 00/08/07 23:47:31 msokolov 29 28
c (bmove): clearuse() for CASE just like for JMP
e
s 00001/00001/01506
d D 4.27 00/08/07 23:45:50 msokolov 28 27
c (bmove small negative constant CMP optimisation): Make the handling of perm
c regs just copied from temp ones actually work.
e
s 00007/00003/01500
d D 4.26 00/08/07 22:40:17 msokolov 27 26
x 24
c donn, your fix (sid 4.23) is wrong. We must look at the instruction a second
c time to take note of the new source operand and the registers it may use,
c including deferred and indexed addressing modes. I'm reverting your incorrect
c fix and replacing it with the correct one, which is to explicitly disable the
c inappropriate dead store elimination.
e
s 00014/00015/01490
d D 4.25 00/08/07 22:28:50 msokolov 26 25
c (bflow): clean up the send directly to destination optimisation
e
s 00023/00003/01482
d D 4.24 88/05/11 01:40:35 donn 25 24
c Two fixes from Chris Torek -- get the type right after deleting a shift
c and upgrading an indexed address from byte to short or long offsets; don't
c lose a label number after deleting a test-and-branch.
e
s 00002/00001/01483
d D 4.23 88/01/15 19:48:13 donn 24 23
c A bflow() fix analogous to sid 1.6 in c2.tahoe/c21.c.
e
s 00001/00001/01483
d D 4.22 87/12/11 20:16:36 donn 23 22
c utah rcsid 1.8 87/09/10 12:54:29: The last fix was too liberal with the
c definition of 'redundant' -- it deleted the first instruction in pairs like
c 'cvtdl r0,r0; cvtlb r0,-1(fp)'.  We now only make the deletion if the
c source of the first instruction is as small as the source of the second
c instruction (we use equtype() instead of compat()).
e
s 00007/00001/01477
d D 4.21 87/12/11 20:16:23 donn 22 21
c utah rcsid 1.7 87/06/25 15:42:14: Spot sequences like 'cvtbl 4(ap),r0;
c movzbl r0,-4(fp)' in which the initial conversion is made redundant by a
c subsequent one.
e
s 00002/00000/01476
d D 4.20 87/12/11 20:16:12 donn 21 20
c utah rcsid 1.6 87/01/20 22:00:38: equop() used to lump all 'leftover'
c instructions together; now these instructions are specifically tested to
c ensure that they have the same name.
e
s 00005/00003/01471
d D 4.19 86/04/27 04:18:12 donn 20 19
c Fixed a bug that caused char *cp to be incremented by 4 in 'if (*cp++ & 01)'
c because of an oversight in jbc => jlbc optimization in bitopt().  Made long
c *lp, 'if (*lp++ & 01)', eligible instead; suggested by Chris Torek.
e
s 00002/00001/01472
d D 4.18 86/02/24 22:40:59 donn 19 18
c GFLOAT, HFLOAT and OCTA are not 32-bit types (from Jay Schuster,
c schuster@su-pescadero).
e
s 00001/00001/01472
d D 4.17 86/01/08 02:22:58 donn 18 17
c Catch more instances of 'ashl $1,A,A' => 'addl2 A,A'.
e
s 00004/00001/01469
d D 4.16 85/08/22 18:45:45 mckusick 17 16
c update from donn@utah-cs
e
s 00093/00067/01377
d D 4.15 85/03/19 10:54:28 ralph 16 15
c lint changes from donn@utah-cs.
e
s 00007/00001/01437
d D 4.14 85/01/16 11:42:26 ralph 15 14
c changes to merge f2 and c2. Added -f flag to act as f2.
e
s 00001/00001/01437
d D 4.13 84/10/07 10:02:00 sam 14 13
c from chris torek (chris@maryland)
e
s 00034/00016/01404
d D 4.12 84/09/24 11:36:30 ralph 13 12
c clobber conloc in dest() if loc is changed.
e
s 00003/00002/01417
d D 4.11 84/08/02 11:08:55 ralph 12 10
c don't convert ashl, bicl to extzv if `field' crosses longword boundary
e
s 00003/00002/01417
d R 4.11 84/07/23 15:56:45 ralph 11 10
c don't convert ashl, bicl to extzv if `field' crosses long boundary
e
s 00036/00006/01383
d D 4.10 84/03/08 15:23:52 ralph 10 9
c fix extv => movw offset problem, don't fold cvtfl, bicl => movz.
e
s 00014/00014/01375
d D 4.9 82/05/27 12:48:30 rrh 9 8
c Resort to the original type enumeration order, putting the three
c new data types at the end of the original ordering.  This makes c2 work again
c let's hear it for consistent use of magic numbers and clear coding style.
c 
e
s 00047/00006/01342
d D 4.8 82/02/14 16:01:37 root 8 7
c (by rrh) Added three extra data types: GFLOAT, HFLOAT and OCTA
c Allowed c2 to optimize instructions manipulating G and H format instructions
c just as it can now optimize F and D format instructions.
c c22.c now is mostly empty; data for c2 is now stored in as/instrs, to
c minimize the duplication that existed formerly.
c New data types have ordinal assignments after existing ones;
c because of the flakiness of c2, it is not clear what this may break.
e
s 00001/00001/01347
d D 4.7 81/07/08 20:56:39 bugs 7 6
c there aint no CMPV
e
s 00003/00002/01345
d D 4.6 81/07/08 20:36:04 bugs 6 5
c fix to movc3 operand botch per jfr
e
s 00005/00005/01342
d D 4.5 81/07/05 18:14:24 root 5 4
c fixes per kre
e
s 00001/00001/01346
d D 4.4 81/03/02 12:39:52 toy 4 3
c Changed constant 20 to C2_ASIZE (64)
e
s 00008/00008/01339
d D 4.3 80/10/18 01:06:47 bill 3 2
c take out spurious diffs cause by <blank><tab> instead of <tab>
e
s 00006/00003/01341
d D 4.2 80/10/17 02:00:03 bill 2 1
c Keep up with version 1.83 of jfr fixing dead reg/arg problem.
e
s 01344/00000/00000
d D 4.1 80/10/17 01:46:29 bill 1 0
c date and time created 80/10/17 01:46:29 by bill
e
u
U
t
T
I 16
#ifndef lint
E 16
I 1
static	char sccsid[] = "%Z%%M% %I% %G%";
I 16
#endif
E 16
D 2
/* char C21[] = {"@(#)c21.c 1.82 - 81 ??/??/?? ??:??:?? JFR"}; /* sccs ident */
E 2
I 2
/* char C21[] = {"@(#)c21.c 1.83 80/10/16 21:18:22 JFR"}; /* sccs ident */
E 2

/*
 * C object code improver-- second part
 */

#include "c2.h"
#include <stdio.h>
#include <ctype.h>

#define NUSE 6
int ioflag;
int biti[NUSE] = {1,2,4,8,16,32};
D 8
int bitsize[4] = {0,8,16,32}; /* index by type codes */
E 8
I 8
int bitsize[] = {	/* index by type codes */
D 9
	0,		/* not allocated */
	8,		/* BYTE */
	16,		/* WORD */
	32,		/* LONG */
	32,		/* FFLOAT /
	64,		/* DFLOAT */
	64,		/* GFLOAT */
	128,		/* HFLOAT */
	64,		/* QUAD */
	128,		/* OCTA */
	0,		/* OP2 */
	0,		/* OP3 */
	0,		/* OPB */
	0		/* OPX */
E 9
I 9
	0,		/* 0	not allocated */
	8,		/* 1	BYTE */
	16,		/* 2	WORD */
	32,		/* 3	LONG */
D 22
	32,		/* 4	FFLOAT /
E 22
I 22
	32,		/* 4	FFLOAT */
E 22
	64,		/* 5	DFLOAT */
	64,		/* 6	QUAD */
	0,		/* 7	OP2 */
	0,		/* 8	OP3 */
	0,		/* 9	OPB */
	0,		/* 10	OPX */
	64,		/* 11	GFLOAT */
	128,		/* 12	HFLOAT */
	128		/* 13	OCTA */
E 9
};
E 8
int pos,siz; long f; /* for bit field communication */
struct node *uses[NUSE]; /* for backwards flow analysis */
char *lastrand; /* last operand of instruction */
struct node *bflow();
struct node *bicopt();
char *findcon();
I 16
char *strcpy();
E 16

redun3(p,split) register struct node *p; int split; {
/* check for 3 addr instr which should be 2 addr */
	if (OP3==((p->subop>>4)&0xF)) {
		if (split) splitrand(p);
		if (equstr(regs[RT1],regs[RT3])
		  && (p->op==ADD || p->op==MUL || p->op==BIS || p->op==XOR)) {
			register char *t=regs[RT1]; regs[RT1]=regs[RT2]; regs[RT2]=t;
		}
		if (equstr(regs[RT2],regs[RT3])) {
			p->subop=(p->subop&0xF)|(OP2<<4); p->pop=0;
			lastrand=regs[RT2]; *regs[RT3]=0; return(1);
		}
	} return(0);
}

bmove() {
	register struct node *p, *lastp; register char *cp1,*cp2; register int r;
	refcount();
	for (p=lastp= &first; 0!=(p=p->forw); lastp=p);
	clearreg(); clearuse();
	for (p=lastp; p!= &first; p=p->back) {
	if (debug) {
		printf("Uses:\n");
		for (r=NUSE;--r>=0;) if (uses[r])
			printf("%d: %s\n",r,uses[r]->code? uses[r]->code:"");
		printf("-\n");
	}
	r=(p->subop>>4)&0xF;
	if (OP2==r && (cp1=p->code, *cp1++)=='$' && *cp1++=='0' && *cp1++==',' &&
			!source(cp1)) {/* a no-op unless MUL or DIV */
		if (p->op==MUL) {p->op=MOV; p->subop&=0xF; p->pop=0;}
		else if (p->op==DIV) fprintf(stderr,"c2: zero divide\n");
		else {delnode(p); redunm++; continue;}
	}
	if (OP3==r && 0!=redun3(p,1)) {newcode(p); redunm++;}
	switch (p->op) {
	case LABEL: case DLABEL:
		for (r=NUSE; --r>=0;)
			if (uses[r]) p->ref=(struct node *) (((int)p->ref)|biti[r]);
		break;
	case CALLS:
		clearuse(); goto std;
	case 0:
D 15
		clearuse(); break;
E 15
I 15
		/*
		 * Be conservative -- if we don't know what it is, then we
		 *	assume that it can set anything.
		 */
		for ( r = 0; r < NUSE; ++r )
			uses[r] = p;
		break;
E 15
	case SUB:
		if ((p->subop&0xF)!=LONG) goto std; cp1=p->code;
		if (*cp1++!='$') goto std; splitrand(p);
		if (equstr(regs[RT2],"fp") && !indexa(regs[RT1])) {/* address comp. */
D 5
			char buf[50]; cp2=buf; *cp2++='-'; 
E 5
I 5
			char buf[C2_ASIZE]; cp2=buf; *cp2++='-'; 
E 5
			cp1=regs[RT1]+1; while (*cp2++= *cp1++); --cp2;
			cp1="(fp),"; while (*cp2++= *cp1++); --cp2;
			cp1=regs[RT3]; while (*cp2++= *cp1++);
			p->code=copy(buf); p->combop=T(MOVA,LONG); p->pop=0;
		} else if (*cp1++=='-' && 0<=(r=getnum(cp1))) {
			p->op=ADD; p->pop=0; *--cp1='$'; p->code=cp1;
		} goto std;
	case ADD:
		if ((p->subop&0xF)!=LONG) goto std; cp1=p->code;
		if (*cp1++!='$') goto std; splitrand(p);
		if (isstatic(cp1) && (r=isreg(regs[RT2]))>=0 && r<NUSE && uses[r]==p->forw)
		{
			/* address comp:
			**	addl2	$_foo,r0  \	movab	_foo[r0],bar
			**	movl	r0,bar	  /
			*/
			register struct	node	*pnext = p->forw;
D 5
			char	buf[50];
E 5
I 5
			char	buf[C2_ASIZE];
E 5

			if (pnext->op == MOV && pnext->subop == LONG)
			{
				cp1 = &regs[RT1][1]; cp2 = &buf[0];
				while (*cp2++ = *cp1++) ; cp2--;
				splitrand(pnext);
				if (r == isreg(regs[RT1]))
				{
					delnode(p); p = pnext;
					p->op = MOVA; p->subop = BYTE;
					p->pop = 0;
					cp1 = regs[RT1]; *cp2++ = '[';
					while (*cp2++ = *cp1++) ; cp2--;
					*cp2++ = ']'; *cp2++ = ',';
					cp1 = regs[RT2];
					while (*cp2++ = *cp1++) ;
					p->code = copy(buf);
				}
			}
		}
		else
		if (equstr(regs[RT2],"fp") && !indexa(regs[RT1])) {/* address comp. */
			cp2=cp1-1; cp1=regs[RT1]+1; while (*cp2++= *cp1++); --cp2;
			cp1="(fp)"; while (*cp2++= *cp1++); *--cp2=',';
			p->combop=T(MOVA,LONG); p->pop=0;
		} else if (*cp1++=='-' && 0<=(r=getnum(cp1))) {
			p->op=SUB; p->pop=0; *--cp1='$'; p->code=cp1;
		}
D 33
		/* fall thru ... */
E 33
I 33
		goto std;
E 33
	case CASE:
I 29
		clearuse();
		/* fall thru ... */
E 29
	default: std:
		p=bflow(p); break;
	case MUL:
	{
		/*
		** Change multiplication by constant powers of 2 to
		**	shifts.
		*/
		splitrand(p);
		if (regs[RT1][0] != '$' || regs[RT1][1] == '-') goto std;
		if ((r = ispow2(getnum(&regs[RT1][1]))) < 0) goto std;
		switch (r)
		{
		case 0:		/* mull3 $1,x,y */
			if (p->subop == U(LONG,OP3))
			{
				if (equstr(regs[RT2], regs[RT3]))
				{
					delnode(p); p = p->forw;
				}
				else
				{
					p->op = MOV; p->subop = LONG;
					p->pop = 0; newcode(p); nchange++;
				}
			}
			else
			if (p->subop == U(LONG,OP2))
			{
				delnode(p); p = p->forw;
			}
			goto std;

		case 1:		/* mull2 $2,x */
			if (p->subop == U(LONG, OP2) && !source(regs[RT2]))
			{
				strcpy(regs[RT1], regs[RT2]);
				p->op = ADD; p->pop = 0; newcode(p); nchange++;
			}
			goto std;
		}
		if(p->subop==U(LONG,OP3)||(p->subop==U(LONG,OP2)&&!source(regs[RT2])))
		{
			if (p->subop == U(LONG,OP2))
				strcpy(regs[RT3], regs[RT2]);
			sprintf(regs[RT1], "$%d", r);
			p->op = ASH; p->subop = LONG;
			p->pop = 0; newcode(p); nchange++;
		}
		goto std;
	}
	case ASH:
	{
		/* address comp:
		**	ashl	$1,bar,r0  \	movl	bar,r0
		**	movab	_foo[r0]   /	movaw	_foo[r0]
		**
		**	ashl	$2,r0,r0   \	moval	_foo[r0]
		**	movab	_foo[r0]   /
		*/
		register struct	node	*pf;
		register int	shfrom, shto;
		long	shcnt;
		char	*regfrom;

		splitrand(p);
		if (regs[RT1][0] != '$') goto std;
		if ((shcnt = getnum(&regs[RT1][1])) < 1 || shcnt > 3) goto std;
		if ((shfrom = isreg(regs[RT2])) >= 0)
D 16
			regfrom = copy(regs[RT2],"]");
E 16
I 16
			regfrom = copy(regs[RT2]);
E 16
		if ((shto = isreg(regs[RT3])) >= 0 && shto<NUSE)
		{
			int	regnum;

			if (uses[shto] != (pf = p->forw)) goto ashadd;
			if (pf->op != MOVA && pf->op != PUSHA) goto ashadd;
			if (pf->subop != BYTE) goto ashadd;
			splitrand(pf);
			if (!indexa(regs[RT1])) goto std;
			cp2 = regs[RT1];
			if(!isstatic(cp2)) goto std;
			while (*cp2++ != '[') ;
			if (*cp2++ != 'r' || !isdigit(*cp2)) goto std;
			regnum = *cp2++ - '0';
			if (isdigit(*cp2))
			{
				if (cp2[1] != ']') goto std;
				regnum *= 10; regnum += *cp2 - '0';
			}
			if (regnum != shto) goto std;
			if (shfrom >= 0)	/* ashl $N,r*,r0 */
			{
				delnode(p);
I 25
				p = pf;
E 25
				if (shfrom != shto)
				{
D 25
					uses[shto] = NULL; splitrand(pf);
E 25
I 25
					uses[shto] = NULL; splitrand(p);
E 25
					cp2=regs[RT1]; while (*cp2++!='[');
					cp1=regfrom; while (*cp2++= *cp1++);
I 16
					*--cp2 = ']';
					*++cp2 = '\0';
E 16
D 25
					newcode(pf);
E 25
I 25
					newcode(p);
E 25
				}
I 25
				if (p->op == MOVA)
				{
					int movato;

					splitrand(p);
					if ((movato = isreg(regs[RT2])) >= 0
					    && movato < NUSE)
						/*
						 * this register is dead;
						 * resurrect it temporarily
						 */
						uses[movato] = p;
				}
E 25
			}
			else
			{
				p->op = MOV; splitrand(p);
				strcpy(regs[RT1], regs[RT2]);
				strcpy(regs[RT2], regs[RT3]);
				regs[RT3][0] = '\0';
				p->pop = 0; newcode(p);
			}
			switch (shcnt)
			{
			case 1:	pf->subop = WORD; break;
			case 2:	pf->subop = LONG; break;
			case 3:	pf->subop = QUAD; break;
			}
I 25
			pf->pop = 0;
E 25
			redunm++; nsaddr++; nchange++;
I 18
			goto std;
E 18
		}
D 18
		goto std;
E 18
ashadd:
		/* at this point, RT2 and RT3 are guaranteed to be simple regs*/
		if (shcnt == 1 && equstr(regs[RT2], regs[RT3]))
		{
			/*
			** quickie:
			**	ashl	$1,A,A	>	addl2	A,A
			*/
			p->op = ADD; p->subop = U(LONG,OP2); p->pop = 0;
			strcpy(regs[RT1], regs[RT2]); regs[RT3][0] = '\0';
			newcode(p); nchange++;
		}
		goto std;
	}

	case EXTV:
	case EXTZV:
	{
		/* bit tests:
		**	extv	A,$1,B,rC  \
		**	tstl	rC	    >	jbc	A,B,D
		**	jeql	D	   /
		**
		** also byte- and word-size fields:
		**	extv	$n*8,$8,A,B	>	cvtbl	n+A,B
D 10
		**	extv	$n*16,$16,A,B	>	cvtwl	n+A,B
E 10
I 10
		**	extv	$n*16,$16,A,B	>	cvtwl	2n+A,B
E 10
		**	extzv	$n*8,$8,A,B	>	movzbl	n+A,B
D 10
		**	extzv	$n*16,$16,A,B	>	movzwl	n+A,B
E 10
I 10
		**	extzv	$n*16,$16,A,B	>	movzwl	2n+A,B
E 10
		*/
		register struct	node	*pf;	/* forward node */
		register struct	node	*pn;	/* next node (after pf) */
		int	flen;			/* field length */

		splitrand(p);
		if (regs[RT2][0] != '$') goto std;
		if ((flen = getnum(&regs[RT2][1])) < 0) goto std;
		if (flen == 1)
		{
			register int	extreg;		/* reg extracted to */

			extreg = isreg(regs[RT4]);
			if (extreg < 0 || extreg >= NUSE) goto std;
			if ((pf = p->forw)->op != TST) goto std;
			if (uses[extreg] && uses[extreg] != pf) goto std;
			splitrand(pf);
			if (extreg != isreg(regs[RT1])) goto std;
			if ((pn = pf->forw)->op != CBR) goto std;
			if (pn->subop != JEQ && pn->subop != JNE) goto std;
			delnode(p); delnode(pf);
			pn->subop = (pn->subop == JEQ) ? JBC : JBS;
			for(cp2=p->code; *cp2++!=',';);
			for(cp1=cp2;     *cp1++!=',';);
			while (*cp1!=',') *cp2++= *cp1++; *cp2='\0';
			pn->code = p->code; pn->pop = NULL;
			uses[extreg] = NULL;
I 25
			p = pn;
			break;
E 25
		}
		else
		if (flen == 8 || flen == 16)
		{
			register int	boff;	/* bit offset */
			register int	coff;	/* chunk (byte or word) offset*/

			if (regs[RT1][0] != '$') goto std;
			if ((boff = getnum(&regs[RT1][1])) < 0) goto std;
			coff = boff / flen;
			if (coff && (isreg(regs[RT3]) >= 0)) goto std;
			if (boff < 0 || (boff % flen) != 0) goto std;
			p->op = (p->op == EXTV) ? CVT : MOVZ;
			p->subop = U((flen == 8 ? BYTE : WORD), LONG);
			if (coff == 0)
				strcpy(regs[RT1], regs[RT3]);
			else
D 10
				sprintf(regs[RT1], "%d%s%s", coff, regs[RT3][0]=='(' ? "":"+",
E 10
I 10
				sprintf(regs[RT1], "%d%s%s",
					(flen == 8 ? coff : 2*coff),
					(regs[RT3][0] == '(' ? "" : "+"),
E 10
					regs[RT3]);
			strcpy(regs[RT2], regs[RT4]);
			regs[RT3][0] = '\0'; regs[RT4][0] = '\0';
			p->pop = 0; newcode(p);
		}
		nchange++;
		goto std;
	}

	case CMP:
	{
		/* comparison to -63 to -1:
		**	cmpl	r0,$-1	>	incl	r0
		**	jeql	...
		**
		**	cmpl	r0,$-63	>	addl2	$63,r0
		**	jeql	...
		*/
		register int	num;
		register int	reg;
		register struct	node	*regp = p->back;

		if (p->forw->op != CBR) goto std;
		if (p->forw->subop != JEQ && p->forw->subop != JNE) goto std;
		splitrand(p);
		if (strncmp(regs[RT2], "$-", 2) != 0) goto std;
		reg = r = isreg(regs[RT1]);
		if (r < 0) goto std;
		if (r < NUSE && uses[r] != 0) goto std;
		if (r >= NUSE && regp->op == MOV && p->subop == regp->subop)
		{
			if (*regp->code != 'r') goto std;
			reg = regp->code[1] - '0';
			if (isdigit(regp->code[2]) || reg >= NUSE || uses[reg])
				goto std;
		}
D 28
		if (r >= NUSE) goto std;
E 28
I 28
		else if (r >= NUSE) goto std;
E 28
		if (reg != r)
			sprintf(regs[RT1], "r%d", reg);
		if ((num = getnum(&regs[RT2][2])) <= 0 || num > 63) goto std;
		if (num == 1)
		{
			p->op = INC; regs[RT2][0] = '\0';
		}
		else
		{
			register char	*t;

			t=regs[RT1];regs[RT1]=regs[RT2];regs[RT2]=t;
			p->op = ADD; p->subop = U(p->subop, OP2);
			for (t = &regs[RT1][2]; t[-1] = *t; t++) ;
		}
		p->pop = 0; newcode(p);
		nchange++;
		goto std;
	}

	case JSB:
		if (equstr(p->code,"mcount")) {uses[0]=p; regs[0][0]= -1;}
		goto std;
	case JBR: case JMP:
		clearuse();
		if (p->subop==RET || p->subop==RSB) {uses[0]=p; regs[0][0]= -1; break;}
		if (p->ref==0) goto std;	/* jmp (r0) */
		/* fall through */
	case CBR:
		if (p->ref->ref!=0) for (r=NUSE;--r>=0;)
			if (biti[r] & (int)p->ref->ref) {uses[r]=p; regs[r][0]= -1;}
D 36
	case EROU: case JSW:
E 36
I 36
	case GLOBL: case JSW:
E 36
	case TEXT: case DATA: case BSS: case ALIGN: case WGEN: case END: ;
	}
	}
	for (p= &first; p!=0; p=p->forw)
		if (p->op==LABEL || p->op==DLABEL) p->ref=0;	/* erase our tracks */
}

rmove()
{
D 16
	register struct node *p, *lastp;
E 16
I 16
	register struct node *p;
E 16
	register int r;
	int r1;

	clearreg();
	for (p=first.forw; p!=0; p = p->forw) {
D 16
	lastp=p;
E 16
	if (debug) {
I 13
		if (*conloc) {
			r1=conval[0];
			printf("Con %s = %d%d %s\n", conloc, r1&0xF, r1>>4, conval+1);
		}
E 13
		printf("Regs:\n");
		for (r=0; r<NREG; r++)
			if (regs[r][0]) {
				r1=regs[r][0];
				printf("%d: %d%d %s\n", r, r1&0xF, r1>>4, regs[r]+1);
			}
		printf("-\n");
	}
	switch (p->op) {

	case CVT:
		splitrand(p); goto mov;

	case MOV:
		splitrand(p);
		if ((r = findrand(regs[RT1],p->subop)) >= 0) {
			if (r == isreg(regs[RT2]) && p->forw->op!=CBR) {
				delnode(p); redunm++; break;
			}
		}
mov:
		repladdr(p);
		r = isreg(regs[RT1]);
		r1 = isreg(regs[RT2]);
		dest(regs[RT2],p->subop);
D 3
 		if (r>=0) {
 			if (r1>=0) savereg(r1, regs[r]+1, p->subop);
 			else if (p->op!=CVT) savereg(r, regs[RT2], p->subop);
 		} else if (r1>=0) savereg(r1, regs[RT1], p->subop);
 		else if (p->op!=CVT) setcon(regs[RT1], regs[RT2], p->subop);
E 3
I 3
		if (r>=0) {
			if (r1>=0) savereg(r1, regs[r]+1, p->subop);
			else if (p->op!=CVT) savereg(r, regs[RT2], p->subop);
		} else if (r1>=0) savereg(r1, regs[RT1], p->subop);
		else if (p->op!=CVT) setcon(regs[RT1], regs[RT2], p->subop);
E 3
		break;

/* .rx,.wx */
	case MFPR:
	case COM:
	case NEG:
/* .rx,.wx or .rx,.rx,.wx */
	case ADD:
	case SUB:
	case BIC:
	case BIS:
	case XOR:
	case MUL:
	case DIV:
	case ASH:
	case MOVZ:
/* .rx,.rx,.rx,.wx */
	case EXTV:
	case EXTZV:
	case INSV:
		splitrand(p);
		repladdr(p);
		dest(lastrand,p->subop);
		if (p->op==INSV) ccloc[0]=0;
		break;

/* .mx or .wx */
	case CLR:
	case INC:
	case DEC:
		splitrand(p);
		dest(lastrand,p->subop);
		if (p->op==CLR)
			if ((r = isreg(regs[RT1])) >= 0)
				savereg(r, "$0", p->subop);
			else
				setcon("$0", regs[RT1], p->subop);
		break;

/* .rx */
	case TST:
	case PUSH:
		splitrand(p);
		lastrand=regs[RT1+1]; /* fool repladdr into doing 1 operand */
		repladdr(p);
		if (p->op==TST && equstr(lastrand=regs[RT1], ccloc+1)
		  && ((0xf&(ccloc[0]>>4))==p->subop || equtype(ccloc[0],p->subop))
		  &&!source(lastrand)) {
D 30
			delnode(p); p = p->back; nrtst++; nchange++;
E 30
I 30
			delnode(p);
			p = p->back;
			nrtst++;
			nchange++;
			break;
E 30
		}
		setcc(lastrand,p->subop);
		break;

/* .rx,.rx,.rx */
	case PROBER:
	case PROBEW:
	case CASE:
	case MOVC3:
/* .rx,.rx */
	case MTPR:
	case CALLS:
	case CMP:
	case BIT:
		splitrand(p);
		/* fool repladdr into doing right number of operands */
D 6
		if (p->op==CASE || p->op==MOVC3 || p->op==PROBER || p->op==PROBEW)
			lastrand=regs[RT4];
E 6
I 6
		if (p->op==CASE || p->op==PROBER || p->op==PROBEW) lastrand=regs[RT4];
D 7
		else if (p->op==CMPV || p->op==CMPZV) lastrand=regs[RT4+1];
E 7
I 7
/*		else if (p->op==CMPV || p->op==CMPZV) lastrand=regs[RT4+1]; */
E 7
		else if (p->op==MOVC3) lastrand=regs[RT1];
E 6
		else lastrand=regs[RT3];
		repladdr(p);
		if (p->op==CALLS || p->op==MOVC3) clearreg();
		if (p->op==BIT) bitopt(p);
		ccloc[0]=0; break;

	case CBR:
		if (p->subop>=JBC) {
			splitrand(p);
			if (p->subop<JBCC) lastrand=regs[RT3]; /* 2 operands can be optimized */
			else lastrand=regs[RT2]; /* .mb destinations lose */
			repladdr(p);
		}
D 31
		ccloc[0] = 0;
E 31
		break;

	case JBR:
		redunbr(p);

/* .wx,.bb */
	case SOB:

	default:
		clearreg();
	}
	}
}

char *
byondrd(p) register struct node *p; {
/* return pointer to register which is "beyond last read/modify operand" */
	if (OP2==(p->subop>>4)) return(regs[RT3]);
	switch (p->op) {
		case MFPR:
		case JSB:
		case PUSHA:
		case TST: case INC: case DEC: case PUSH:	return(regs[RT2]);
		case MTPR:
		case BIT: case CMP: case CALLS:				return(regs[RT3]);
		case PROBER: case PROBEW:
		case CASE: case MOVC3:						return(regs[RT4]);
	}
	return(lastrand);
}

struct node *
bflow(p)
register struct node *p;
{
	register char *cp1,*cp2,**preg; register int r;
	int flow= -1;
	struct node *olduse=0;
	splitrand(p);
	if (p->op!=PUSH && p->subop && 0<=(r=isreg(lastrand)) && r<NUSE && uses[r]==p->forw) {
I 22
	if ((p->op==CVT || p->op==MOVZ)
		&& (p->forw->op==CVT || p->forw->op==MOVZ)
		&& p->forw->subop&0xf
D 23
		&& compat(p->subop,p->forw->subop)
E 23
I 23
		&& equtype(p->subop,p->forw->subop)
E 23
		&& !source(cp1=regs[RT1])
		&& !indexa(cp1)) goto movit;
E 22
	if (equtype(p->subop,regs[r][0])
	|| ((p->op==CVT || p->op==MOVZ)
			 && 0xf&regs[r][0] && compat(0xf&(p->subop>>4),regs[r][0]))) {
		register int r2;
		if (regs[r][1]!=0) {/* send directly to destination */
			if (p->op==INC || p->op==DEC) {
				if (p->op==DEC) p->op=SUB; else p->op=ADD;
				p->subop=(OP2<<4)+(p->subop&0xF); /* use 2 now, convert to 3 later */
				p->pop=0;
				cp1=lastrand; cp2=regs[RT2]; while (*cp2++= *cp1++); /* copy reg */
				cp1=lastrand; *cp1++='$'; *cp1++='1'; *cp1=0;
			}
			cp1=regs[r]+1; cp2=lastrand;
			if (OP2==(p->subop>>4)) {/* use 3 operand form of instruction */
				p->pop=0;
				p->subop += (OP3-OP2)<<4; lastrand=cp2=regs[RT3];
			}
			while (*cp2++= *cp1++);
			if (p->op==MOVA && p->forw->op==PUSH) {
				p->op=PUSHA; *regs[RT2]=0; p->pop=0;
			} else if (p->op==MOV && p->forw->op==PUSH) {
				p->op=PUSH ; *regs[RT2]=0; p->pop=0;
			}
			delnode(p->forw);
D 26
			if (0<=(r2=isreg(lastrand)) && r2<NUSE) {
				uses[r2]=uses[r]; uses[r]=0;
			}
E 26
D 16
			redun3(p,0);
E 16
I 16
			(void) redun3(p,0);
E 16
D 26
			newcode(p); redunm++; flow=r;
E 26
I 26
			newcode(p); redunm++;
			uses[r]=0;
			regs[r][0]=regs[r][1]=0;
E 26
		} else if (p->op==MOV && p->forw->op!=EXTV && p->forw->op!=EXTZV) {
			/* superfluous fetch */
			int nmatch;
D 4
			char src[20];
E 4
I 4
			char src[C2_ASIZE];
E 4
	movit:
			cp2=src; cp1=regs[RT1]; while (*cp2++= *cp1++);
			splitrand(p->forw);
			if (p->forw->op != INC && p->forw->op != DEC)
				lastrand=byondrd(p->forw);
			nmatch=0;
			for (preg=regs+RT1;*preg!=lastrand;preg++)
				if (r==isreg(*preg)) {
				cp2= *preg; cp1=src; while (*cp2++= *cp1++); ++nmatch;
			}
			if (nmatch==1) {
				if (OP2==(p->forw->subop>>4) && equstr(src,regs[RT2])) {
					p->forw->pop=0;
					p->forw->subop += (OP3-OP2)<<4; cp1=regs[RT3];
					*cp1++='r'; *cp1++=r+'0'; *cp1=0;
				}
				delnode(p); p=p->forw;
D 27
				if (0<=(r2=isreg(src)) && r2<NUSE) {
					uses[r2]=uses[r]; uses[r]=0;
				}
E 27
D 16
				redun3(p,0);
E 16
I 16
				(void) redun3(p,0);
E 16
D 24
				newcode(p); redunm++; flow=r;
E 24
I 24
				newcode(p); redunm++;
				return(p);	/* avoid stale uses[] data */
E 24
			} else splitrand(p);
		}
	} else if (p->op==MOV && (p->forw->op==CVT || p->forw->op==MOVZ)
		&& p->forw->subop&0xf 	/* if base or index, then forget it */
		&& compat(p->subop,p->forw->subop) && !source(cp1=regs[RT1])
		&& !indexa(cp1)) goto movit;
	}
	/* adjust 'lastrand' past any 'read' or 'modify' operands. */
	lastrand=byondrd(p);
	/* a 'write' clobbers the register. */
	if (0<=(r=isreg(lastrand)) && r<NUSE
	|| OP2==(p->subop>>4) && 0<=(r=isreg(regs[RT2])) && r<NUSE && uses[r]==0) {
		/* writing a dead register is useless, but watch side effects */
		switch (p->op) {
I 2
		case ACB:
E 2
		case AOBLEQ: case AOBLSS: case SOBGTR: case SOBGEQ: break;
D 2
		default: if (p->op==ACB) break;
E 2
I 2
		default:
I 27
			/*
			 * If flow is already set, we are looking at this
			 * instruction a second time, so we can't do this
			 * seeming dead store elimination.
			 */
			if (flow >= 0)
				break;
E 27
E 2
			if (uses[r]==0) {/* no direct uses, check for use of condition codes */
				register struct node *q=p;
				while ((q=nonlab(q->forw))->combop==JBR) q=q->ref;	/* cc unused, unchanged */
				if (q->op!=CBR) {/* ... and destroyed */
					preg=regs+RT1;
					while (cp1= *preg++) {
						if (cp1==lastrand) {redunm++; delnode(p); return(p->forw);}
						if (source(cp1) || equstr(cp1,lastrand)) break;
					}
				}
			}
			flow=r;
		}
	}
D 16
	if (0<=(r=flow)) {olduse=uses[r]; uses[r]=0; *(short *)(regs[r])=0;}
E 16
I 16
	if (0<=(r=flow)) {
		olduse=uses[r];
		uses[r]=0;
		regs[r][0]=regs[r][1]=0;
	}
E 16
		/* these two are here, rather than in bmove(),
		/* because I decided that it was better to go for 3-address code
		/* (save time) rather than fancy jbxx (save 1 byte)
		/* on sequences like  bisl2 $64,r0; movl r0,foo
		*/
	if (p->op==BIC) {p=bicopt(p); splitrand(p); lastrand=byondrd(p);}
D 16
	if (p->op==BIS) {bixprep(p,JBSS);           lastrand=byondrd(p);}
E 16
I 16
	if (p->op==BIS) {(void) bixprep(p,JBSS);    lastrand=byondrd(p);}
E 16
	/* now look for 'read' or 'modify' (read & write) uses */
	preg=regs+RT1; 
	while (*(cp1= *preg++)) {
		/* check for  r  */
		if (lastrand!=cp1 && 0<=(r=isreg(cp1)) && r<NUSE && uses[r]==0) {
			uses[r]=p; cp2=regs[r]; *cp2++=p->subop;
I 2
D 3
 			if (p->op==ASH && preg==(regs+RT1+1)) cp2[-1]=BYTE; /* stupid DEC */
E 3
I 3
			if (p->op==ASH && preg==(regs+RT1+1)) cp2[-1]=BYTE; /* stupid DEC */
E 3
E 2
D 26
			if (p->op==MOV || p->op==PUSH || p->op==CVT || p->op==MOVZ || p->op==COM || p->op==NEG) {
				if (p->op==PUSH) cp1="-(sp)";
				else {
					cp1=regs[RT2];
					if (0<=(r=isreg(cp1)) && r<NUSE && uses[r]==0)
						uses[r]=olduse; /* reincarnation!! */
					/* as in  addl2 r0,r1;  movl r1,r0;  ret  */
					if (p->op!=MOV) cp1=0;
				}
				if (cp1) while (*cp2++= *cp1++);
D 2
			} else *cp2++=0;
E 2
I 2
D 3
 				else *cp2=0;
 			} else *cp2=0;
E 3
I 3
				else *cp2=0;
E 26
I 26
			if (p->op == MOV) {
				cp1 = regs[RT2];
				if (0<=(r=isreg(cp1)) && r<NUSE && uses[r]==0)
					uses[r]=olduse; /* reincarnation!! */
				while (*cp2++ = *cp1++)
					;
				/* as in  addl2 r0,r1;  movl r1,r0;  ret  */
			} else if (p->op == PUSH) {
				cp1 = "-(sp)";
				while (*cp2++ = *cp1++)
					;
E 26
			} else *cp2=0;
E 3
E 2
			continue;
		}
		/* check for (r),(r)+,-(r),[r] */
		do if (*cp1=='(' || *cp1=='[') {/* get register number */
			char t;
			cp2= ++cp1; while (*++cp1!=')' && *cp1!=']'); t= *cp1; *cp1=0;
			if (0<=(r=isreg(cp2)) && r<NUSE && (uses[r]==0 || uses[r]==p)) {
				uses[r]=p; regs[r][0]=(*--cp2=='[' ? OPX<<4 : OPB<<4);
			}
			*cp1=t;
		} while (*++cp1);
	}
	/* pushax or movax possibility? */
	cp1=regs[RT1];
	if (*cp1++=='$' && isstatic(cp1) && natural(regs[RT1])) {
		if (p->combop==T(MOV,LONG)) {
			if (regs[RT1][1]=='L' && 0!=(p->labno=getnum(regs[RT1]+2))) {
				cp1=p->code; while (*cp1++!=','); p->code= --cp1;
			}
			p->combop=T(MOVA,LONG); ++p->code; p->pop=0;
		} else if (p->combop==T(PUSH,LONG)) {
			p->combop=T(PUSHA,LONG); ++p->code; p->pop=0;
		} else if ((p->combop&0xFFFF)==T(ADD,U(LONG,OP3))
				 && 0<=(r=isreg(regs[RT2]))) {
			cp1=cp2=p->code; ++cp1;
			do *cp2++= *cp1; while (*cp1++!=','); cp2[-1]='[';
			do *cp2++= *cp1; while (*cp1++!=','); cp2[-1]=']';
			if (!equstr(regs[RT3],"-(sp)")) p->combop=T(MOVA,BYTE);
			else {p->combop=T(PUSHA,BYTE); *cp2=0;}
D 17
			if (uses[r]==0) {uses[r]=p; regs[r][0]=OPX<<4;}
E 17
I 17
			if (r < NUSE && uses[r] == 0) {
				uses[r]=p;
				regs[r][0]=OPX<<4;
			}
E 17
			p->pop=0;
		}
	}
	return(p);
}

ispow2(n) register long n; {/* -1 -> no; else -> log to base 2 */
	register int log;
	if (n==0 || n&(n-1)) return(-1); log=0;
	for (;;) {n >>= 1; if (n==0) return(log); ++log; if (n== -1) return(log);}
}

bitopt(p) register struct node *p; {
	/* change "bitx $<power_of_2>,a" followed by JEQ or JNE
	/* into JBC or JBS.  watch out for I/O registers. (?)
	/* assumes that 'splitrand' has already been called.
	*/
	register char *cp1,*cp2; int b;
	cp1=regs[RT1]; cp2=regs[RT2];
	if (*cp1++!='$' || !okio(cp2) || p->forw->op!=CBR || p->forw->subop&-2 ||
D 20
		0>(b=ispow2(getnum(cp1))) ||
		p->subop!=BYTE && (source(cp2) || indexa(cp2))) return;
E 20
I 20
		0>(b=ispow2(getnum(cp1)))) return;
	if (p->subop!=BYTE && !(b==0 && p->subop==LONG) &&
		(source(cp2) || indexa(cp2))) return;
E 20
	if (b>=bitsize[p->subop]) {/* you dummy! */
		if (source(cp2)) {/* side effect: auto increment or decrement */
			p->pop=0;
			p->op=TST; --cp1; while (*cp1++= *cp2++);
			regs[RT2][0]=0; newcode(p);
		} else delnode(p);
		p = p->forw;
		if (p->subop==JEQ) {p->combop=JBR; p->pop=0;}
		else delnode(p);
		nchange++; nbj++; return;
	}
	if (cp1=p->forw->code) {/* destination is not an internal label */
		cp2=regs[RT3]; while (*cp2++= *cp1++);
	}
D 20
	if (b==0 && (p->subop==LONG || !indexa(regs[RT2]))) {/* JLB optimization, ala BLISS */
E 20
I 20
	if (b==0 && (p->subop==LONG || !(source(regs[RT2]) || indexa(regs[RT2])))) {
		/* JLB optimization, ala BLISS */
E 20
		cp2=regs[RT1]; cp1=regs[RT2]; while (*cp2++= *cp1++);
		cp2=regs[RT2]; cp1=regs[RT3]; while (*cp2++= *cp1++);
		*(regs[RT3])=0; p->forw->subop += JLBC-JBC;
		p->forw->pop=0;
	} else {
		cp1=regs[RT1]+1;
		if (b>9) *cp1++= b/10 +'0'; *cp1++= b%10 +'0'; *cp1=0; /* $<bit_number> */
	}
	nbj++; newcode(p); p->combop = p->forw->combop+((JBC-JEQ)<<8);
	p->labno = p->forw->labno; delnode(p->forw);
	p->pop=0;
}

isfield(n) register long n; {/* -1 -> no; else -> position of low bit */
D 16
	register int pos; register long t;
E 16
I 16
	register int p; register long t;
E 16
	t= ((n-1)|n) +1;
D 12
	if (n!=0 && (0==t || 0==n || 0<=ispow2(t))) {
E 12
I 12
	if (n!=0 && (0==t || 0<=ispow2(t))) {
E 12
D 16
		pos=0; while(!(n&1)) {n >>= 1; ++pos;} return(pos);
E 16
I 16
		p=0; while(!(n&1)) {n >>= 1; ++p;} return(p);
E 16
	} else return(-1);
}

bixprep(p,bix) register struct node *p; {
/* initial setup, single-bit checking for bisopt, bicopt.
/* return: 0->don't bother any more; 1->worthwhile trying
*/
	register char *cp1,*cp2;
	splitrand(p); cp1=regs[RT1]; cp2=regs[RT2];
	if (*cp1++!='$' || 0>(pos=isfield(f=getnum(cp1)))
	  || !okio(cp2) || indexa(cp2) || source(cp2) || !okio(lastrand)) return(0);
	f |= f-1; if (++f==0) siz=32-pos; else siz=ispow2(f)-pos;
	if (siz==1 && pos>5 && (p->subop>>4)==OP2 && (p->subop&0xF)!=BYTE
	  && pos<bitsize[p->subop&0xF]) {
		p->ref = insertl(p->forw); p->combop = CBR | (bix<<8);
		p->pop=0;
		p->labno = p->ref->labno;
		if (pos>9) {*cp1++= pos/10 +'0'; pos %= 10;}
		*cp1++=pos+'0'; *cp1=0; newcode(p); nbj++; return(0);
	}
	return(1);
}


struct node *
bicopt(p) register struct node *p; {
/* use field operations or MOVZ if possible.  done as part of 'bflow'.
*/
	register char *cp1,*cp2; int r;
D 5
	char src[50];
E 5
I 5
	char src[C2_ASIZE];
I 10
D 16
	char lhssiz, subop;
E 16
I 16
	char lhssiz, sop;
E 16
E 10
E 5
	if (!bixprep(p,JBCC)) return(p);
	if (f==0) {/* the BIC isolates low order bits */
		siz=pos; pos=0;
		if ((p->subop&0xF)==LONG && *(regs[RT2])!='$') {/* result of EXTZV is long */
			/* save source of BICL in 'src' */
			cp1=regs[RT2]; cp2=src; while (*cp2++= *cp1++);
			if (p->back->op==ASH) {/* try for more */
				splitrand(p->back); cp1=regs[RT1]; cp2=regs[RT3];
				if (*cp1++=='$' && *(regs[RT2])!='$' && !indexa(regs[RT2])
				  && 0>(f=getnum(cp1)) && equstr(src,cp2)
D 12
				  && 0<=(r=isreg(cp2)) && r<NUSE) {/* a good ASH */
E 12
I 12
				  && 0<=(r=isreg(cp2)) && r<NUSE
				  && siz-f <= 32) {	/* a good ASH */
E 12
					pos -= f; cp1=regs[RT2]; cp2=src; while (*cp2++= *cp1++);
					delnode(p->back);
				}
			}
I 10
			/*
			 * 'pos', 'siz' known; find out the size of the
			 * left-hand operand of what the bicl will turn into.
			 */
			if (pos==0 && siz==16)
				lhssiz = WORD;	/* movzwl */
			else
				lhssiz = BYTE;	/* movzbl or extzvl */
E 10
			if (p->back->op==CVT || p->back->op==MOVZ) {/* greedy, aren't we? */
				splitrand(p->back); cp1=regs[RT1]; cp2=regs[RT2];
D 10
				if (equstr(src,cp2) && okio(cp1) && !indexa(cp1)
E 10
I 10
				/*
				 * If indexa(cp1) || autoid(cp1), the fold may
				 * still be OK if the CVT/MOVZ has the same
				 * size operand on its left size as what we
				 * will turn the bicl into.
				 * However, if the CVT is from a float or
				 * double, forget it!
				 */
D 16
				subop = p->back->subop&0xF;	/* type of LHS of CVT/MOVZ */
E 16
I 16
				sop = p->back->subop&0xF;	/* type of LHS of CVT/MOVZ */
E 16
				if (equstr(src,cp2) && okio(cp1)
D 16
				  && subop != FFLOAT && subop != DFLOAT
				  && subop != GFLOAT && subop != HFLOAT
				  && ((!indexa(cp1) && !autoid(cp1)) || lhssiz == subop)
E 16
I 16
				  && sop != FFLOAT && sop != DFLOAT
				  && sop != GFLOAT && sop != HFLOAT
				  && ((!indexa(cp1) && !autoid(cp1)) || lhssiz == sop)
E 16
E 10
				  && 0<=(r=isreg(cp2)) && r<NUSE
D 14
				  && bitsize[p->back->subop&0xF]>=(pos+siz)
E 14
I 14
D 16
				  && bitsize[subop]>=(pos+siz)
E 16
I 16
				  && bitsize[sop]>=(pos+siz)
E 16
E 14
				  && bitsize[p->back->subop>>4]>=(pos+siz)) {/* good CVT */
					cp1=regs[RT1]; cp2=src; while (*cp2++= *cp1++);
					delnode(p->back);
				}
			}
			/* 'pos', 'siz' known; source of field is in 'src' */
			splitrand(p); /* retrieve destination of BICL */
D 10
			if (siz==8 && pos==0) {
				p->combop = T(MOVZ,U(BYTE,LONG));
E 10
I 10
			if ((siz==8 || siz==16) && pos==0) {
				p->combop = T(MOVZ,U(lhssiz,LONG));
E 10
				sprintf(line,"%s,%s",src,lastrand);
			} else {
				p->combop = T(EXTZV,LONG);
				sprintf(line,"$%d,$%d,%s,%s",pos,siz,src,lastrand);
			}
			p->pop=0;
			p->code = copy(line); nfield++; return(p);
		}/* end EXTZV possibility */
	}/* end low order bits */
/* unfortunately, INSV clears the condition codes, thus cannot be used */
/*	else {/* see if BICL2 of positive field should be INSV $0 */
/*		if (p->subop==(LONG | (OP2<<4)) && 6<=(pos+siz)) {
/*			p->combop = INSV;
/*			sprintf(line,"$0,$%d,$%d,%s",pos,siz,lastrand);
/*			p->code = copy(line); nfield++; return(p);
/*		}
/*	}
*/
	return(p);
}

jumpsw()
{
	register struct node *p, *p1;
D 16
	register t;
E 16
I 16
	register struct node *tp;
	long tl;
	char *tcp;
	int ti;
E 16
	int nj;

D 16
	t = 0;
E 16
I 16
	ti = 0;
E 16
	nj = 0;
	for (p=first.forw; p!=0; p = p->forw)
D 16
		p->seq = ++t;
E 16
I 16
		p->seq = ++ti;
E 16
	for (p=first.forw; p!=0; p = p1) {
		p1 = p->forw;
		if (p->op == CBR && p1->op==JBR && p->ref && p1->ref
		 && abs(p->seq - p->ref->seq) > abs(p1->seq - p1->ref->seq)) {
			if (p->ref==p1->ref)
				continue;
			p->subop = revbr[p->subop];
			p->pop=0;
D 16
			t = p1->ref;
E 16
I 16
			tp = p1->ref;
E 16
			p1->ref = p->ref;
D 16
			p->ref = t;
			t = p1->labno;
E 16
I 16
			p->ref = tp;
			tl = p1->labno;
E 16
			p1->labno = p->labno;
D 16
			p->labno = t;
E 16
I 16
			p->labno = tl;
E 16
#ifdef COPYCODE
			if (p->labno == 0) {
D 16
				t = p1->code; p1->code = p->code; p->code = t;
E 16
I 16
				tcp = p1->code;
				p1->code = p->code;
				p->code = tcp;
E 16
			}
#endif
			nrevbr++;
			nj++;
		}
	}
	return(nj);
}

I 34
/*
 * The wonderful VAX architecture has nice loop instructions which neatly
 * replace some sequences that come out of typical for loops. A loop with a
 * counter ticking down to 0 will end with a DEC; JGE/JGT at this point, which
 * is neatly replaced with a SOB. A loop with a counter ticking up to some
 * limit will end with an INC; CMP; JLE/JLT at this point, which is neatly
 * replaced with an AOB or ACB (see below). We do these substitutions here.
 *
 * There are some gotchas, though. Just like ordinary branches, SOB and AOB
D 35
 * instructions are limited to byte displacements. The current UNIX as relaxes
E 35
I 35
 * instructions are limited to byte displacements. The original UNIX as relaxed
E 35
 * the former, but not the latter. One can add straightforward relaxing of SOBs
 * and AOBs to as (by putting roundabout branches after the SOB/AOB that can't
 * reach), which is what GNU as does. An AOB is always more efficient than INC;
 * CMP; JLE/JLT, even when relaxed. A SOB, however, is more efficient than DEC;
 * JGE/JGT only when it's simple. A relaxed DEC; JGE/JGT is more efficient than
 * a relaxed SOB. Also we can use an ACB instead of an AOB. With a +1 addend
 * it's almost as efficient as an AOB, but has a word displacement. (It's
 * wasteful with a -1 addend, though, worse than a relaxed SOB or a DEC;
 * JGE/JGT, so we don't use it there.) Also an ACB can only replace an AOBLEQ,
 * but not an AOBLSS.
 *
D 35
 * The current c2 practice, which is effectively for a non-relaxing assembler,
 * is to generate a SOB or AOB if the destination is within 8 instructions, or
 * if that doesn't cut it and we were trying to generate an AOBLEQ, generate an
 * ACB instead. Otherwise, miss the optimisation.
E 35
I 35
 * The original c2 solution, which was effectively for a non-relaxing
 * assembler, was to generate a SOB or AOB if the destination is within 8
 * instructions, or if that doesn't cut it and we were trying to generate an
 * AOBLEQ, generate an ACB instead. Otherwise, miss the optimisation.
E 35
 *
D 35
 * There is an overhaul coming soon for UNIX as, in which it will start
 * relaxing branches three-way without -J like GNU as does. At the same time it
 * will also start relaxing SOBs and AOBs like GNU as does. However, it will be
 * smarter than GNU as, and in light of the above considerations will relax
 * them a little differently. Straightforward relaxing will be done only for
 * AOBs, SOBs will revert to DEC; JGE/JGT as that's more efficient. Also when
 * an AOB is in the word relaxation state and it's an AOBLEQ, it will be
 * changed to an ACB, as that's more efficient than a relaxed AOB. When that is
 * done, c2 will be changed to always emit SOBs and AOBs for as to relax, as
 * its relaxing will always be at least as good as what c2 does now, often
 * better.
E 35
I 35
 * Fortunately, in 4.3BSD-Quasijarus UNIX as has been improved. It now relaxes
 * branches three-way without -J like GNU as does. It also relaxes SOBs, AOBs,
 * and ACBs now. However, it is smarter than GNU as, and in light of the above
 * considerations relaxes them a little differently. Straightforward relaxing
 * is done only for AOBs, SOBs revert to DEC; JGE/JGT as that's more efficient.
 * Also when an AOB is in the word relaxation state and it's an AOBLEQ, it is
 * changed to an ACB, as that's more efficient than a relaxed AOB. c2 now takes
 * advantage of this and always emits SOBs and AOBs for as to relax, as its
 * relaxing will always be at least as good as what c2 used to do in the past,
 * often better.
E 35
 */
E 34
addsob()
{
D 34
	register struct node *p, *p1, *p2, *p3;
E 34
I 34
	register struct node *p, *p1, *p2, *p3, *p4;
	register char *t;
E 34

D 34
	for (p = &first; (p1 = p->forw)!=0; p = p1) {
	if (p->combop==T(DEC,LONG) && p1->op==CBR) {
D 5
		if (abs(p->seq - p1->ref->seq) > 12) continue;
E 5
I 5
		if (abs(p->seq - p1->ref->seq) > 8) continue;
E 5
		if (p1->subop==JGE || p1->subop==JGT) {
			if (p1->subop==JGE) p->combop=SOBGEQ; else p->combop=SOBGTR;
			p->pop=0;
			p->labno = p1->labno; delnode(p1); nsob++;
		}
	} else if (p->combop==T(INC,LONG)) {
		if (p1->op==LABEL && p1->refc==1 && p1->forw->combop==T(CMP,LONG)
		  && (p2=p1->forw->forw)->combop==T(CBR,JLE)
		  && (p3=p2->ref->back)->combop==JBR && p3->ref==p1
		  && p3->forw->op==LABEL && p3->forw==p2->ref) {
			/* change	INC LAB: CMP	to	LAB: INC CMP */
			p->back->forw=p1; p1->back=p->back;
			p->forw=p1->forw; p1->forw->back=p;
			p->back=p1; p1->forw=p;
			p1=p->forw;
			/* adjust beginning value by 1 */
				p2=alloc(sizeof first); p2->combop=T(DEC,LONG);
				p2->pop=0;
				p2->forw=p3; p2->back=p3->back; p3->back->forw=p2;
				p3->back=p2; p2->code=p->code; p2->labno=0;
		}
		if (p1->combop==T(CMP,LONG) && (p2=p1->forw)->op==CBR) {
			register char *cp1,*cp2;
			splitrand(p1); if (!equstr(p->code,regs[RT1])) continue;
D 5
			if (abs(p->seq - p2->ref->seq)>12) {/* outside byte displ range */
E 5
I 5
			if (abs(p->seq - p2->ref->seq)>8) {/* outside byte displ range */
E 5
				if (p2->subop!=JLE) continue;
				p->combop=T(ACB,LONG);
				cp2=regs[RT1]; cp1=regs[RT2]; while (*cp2++= *cp1++); /* limit */
				cp2=regs[RT2]; cp1="$1"; while (*cp2++= *cp1++); /* increment */
				cp2=regs[RT3]; cp1=p->code; while (*cp2++= *cp1++); /* index */
				p->pop=0; newcode(p);
				p->labno = p2->labno; delnode(p2); delnode(p1); nsob++;
			} else if (p2->subop==JLE || p2->subop==JLT) {
				if (p2->subop==JLE) p->combop=AOBLEQ; else p->combop=AOBLSS;
				cp2=regs[RT1]; cp1=regs[RT2]; while (*cp2++= *cp1++); /* limit */
				cp2=regs[RT2]; cp1=p->code; while (*cp2++= *cp1++); /* index */
				p->pop=0; newcode(p);
				p->labno = p2->labno; delnode(p2); delnode(p1); nsob++;
E 34
I 34
	for (p = &first; (p1 = p->forw) != 0; p = p1) {
		if (p->combop == T(DEC,LONG)
		    && (p1->combop == T(CBR,JGE) || p1->combop == T(CBR,JGT))) {
			/* See if it's a SOB candidate. */
D 35
			if (abs(p->seq - p1->ref->seq) > 8)
				continue;	/* as can't relax this yet */
E 35
			if (p1->subop == JGE)
				p->combop = SOBGEQ;
			else
				p->combop = SOBGTR;
			p->pop = 0;
			p->labno = p1->labno;
			delnode(p1);
			nsob++;
		} else if (p->combop == T(CMP,LONG)
			   && (p1->combop == T(CBR,JLE)
			       || p1->combop == T(CBR,JLT))) {
			/*
			 * See if it's an AOB candidate. There must be an INC
			 * before the CMP and the two must have the same
			 * operand, which must have no side effects. There's
			 * one more gotcha here. Usually there will be a label
			 * between the INC and the CMP with a jump to it at the
			 * beginning of the loop. We solve this problem by
			 * adding a DEC before that jump and swapping the INC
			 * and the label. The inefficiency of the DEC -> jump
			 * -> INC path on loop entry is compensated for by the
			 * AOB optimisation, which affects every iteration. Of
			 * course, we do the DEC insertion and the label swap
			 * only when we really do the AOB optimisation. (But
			 * maybe I shouldn't say "of course", as the previous
			 * incarnation of this code blundered here. :-)
			 */
			splitrand(p);
			if (source(regs[RT1]))
				continue;
D 35
			if (abs(p->seq - p1->ref->seq) > 8 && p1->subop != JLE)
				continue;	/* only AOBLEQ can be ACB'ed */
E 35
			if ((p2 = p->back)->combop == T(INC,LONG)) {
				if (!equstr(p2->code, regs[RT1]))
					continue;
			} else if (p2->op == LABEL
				   && (p3 = p2->back)->combop == T(INC,LONG)) {
				if (!equstr(p3->code, regs[RT1]))
					continue;
				if (p2->refc != 1
				    || (p4 = p1->ref->back)->combop != JBR
				    || p4->ref != p2)
					continue;
				/* change INC LAB: CMP to LAB: INC CMP */
				p3->back->forw = p2;
				p2->back = p3->back;
				p3->forw = p2->forw;
				p2->forw->back = p3;
				p3->back = p2;
				p2->forw = p3;
				p2 = p3;
				/* adjust beginning value by 1 */
				p3 = alloc(sizeof first);
				p3->combop = T(DEC,LONG);
				p3->pop = 0;
				p3->forw = p4;
				p3->back = p4->back;
				p4->back->forw = p3;
				p4->back = p3;
				p3->code = p2->code;
				p3->labno = 0;
			} else
				continue;
			delnode(p2);
D 35
			if (abs(p->seq - p1->ref->seq) > 8) {
				/* Generate an ACB for an AOBLEQ. */
				p->combop = T(ACB,LONG);
				t = regs[RT3];
				regs[RT3] = regs[RT1];
				regs[RT1] = regs[RT2];
				regs[RT2] = t;
				t[0] = '$';
				t[1] = '1';
				t[2] = '\0';
			} else {
				/* Generate an AOBLEQ or AOBLSS. */
				if (p1->subop == JLE)
					p->combop = AOBLEQ;
				else
					p->combop = AOBLSS;
				t = regs[RT2];
				regs[RT2] = regs[RT1];
				regs[RT1] = t;
E 34
			}
E 35
I 35
			/* Generate an AOBLEQ or AOBLSS. */
			if (p1->subop == JLE)
				p->combop = AOBLEQ;
			else
				p->combop = AOBLSS;
			t = regs[RT2];
			regs[RT2] = regs[RT1];
			regs[RT1] = t;
E 35
I 34
			p->pop = 0;
			newcode(p);
			p->labno = p1->labno;
			delnode(p1);
			nsob++;
E 34
		}
D 34
	}
E 34
	}
}

D 16
abs(x)
{
	return(x<0? -x: x);
}

E 16
equop(p1, p2)
register struct node *p1;
struct node *p2;
{
	register char *cp1, *cp2;

	if (p1->combop != p2->combop)
		return(0);
I 21
	if (p1->combop == 0 && p1->pop != p2->pop)
		return(0);
E 21
	if (p1->op>0 && p1->op<MOV)
		return(0);
I 16
	switch (p1->combop) {
D 36
	case EROU:	case JSW:	case TEXT:	case DATA:
E 36
I 36
	case GLOBL:	case JSW:	case TEXT:	case DATA:
E 36
	case BSS:	case ALIGN:	case WGEN:	case END:
		/*
		 * Consider all pseudo-ops to be unique.
		 */
		return(0);
	}
E 16
	if (p1->op==MOVA && p1->labno!=p2->labno) return(0);
	cp1 = p1->code;
	cp2 = p2->code;
	if (cp1==0 && cp2==0)
		return(1);
	if (cp1==0 || cp2==0)
		return(0);
	while (*cp1 == *cp2++)
		if (*cp1++ == 0)
			return(1);
	return(0);
}

I 16
#ifndef delnode
E 16
delnode(p) register struct node *p; {
	p->back->forw = p->forw;
	p->forw->back = p->back;
}
I 16
#endif
E 16

I 16
#ifndef decref
E 16
decref(p)
register struct node *p;
{
	if (p && --p->refc <= 0) {
		nrlab++;
		delnode(p);
	}
}
I 16
#endif
E 16

struct node *
nonlab(ap)
struct node *ap;
{
	register struct node *p;

	p = ap;
	while (p && p->op==LABEL)
		p = p->forw;
	return(p);
}

clearuse() {
	register struct node **i;
	for (i=uses+NUSE; i>uses;) *--i=0;
}

clearreg() {
D 16
	register short **i;
	for (i=regs+NREG; i>regs;) **--i=0;
	conloc[0] = 0; ccloc[0] = 0;
E 16
I 16
	register char **i;
	for (i=regs; i<regs+NREG; ++i) {
		**i = 0;
		*(*i+1) = 0;
	}
	conloc[0] = 0;
	ccloc[0] = 0;
E 16
}

savereg(ai, s, type)
register char *s;
{
	register char *p, *sp;

	sp = p = regs[ai];
	if (source(s)) /* side effects in addressing */
		return;
	/* if any indexing, must be parameter or local */
	/* indirection (as in "*-4(fp)") is ok, however */
	*p++ = type;
	while (*p++ = *s)
		if (*s=='[' || *s++=='(' && *s!='a' && *s!='f') {*sp = 0; return;}
}

dest(s,type)
register char *s;
{
	register int i;

D 16
	source(s); /* handle addressing side effects */
E 16
I 16
	(void) source(s); /* handle addressing side effects */
E 16
I 13
	if (!natural(s)) {
		/* wild store, everything except constants vanishes */
		for (i=NREG; --i>=0;)
D 16
			if (regs[i][1] != '$') *(short *)(regs[i]) = 0;
E 16
I 16
			if (regs[i][1] != '$')
				regs[i][0] = regs[i][1] = 0;
E 16
		conloc[0] = 0; ccloc[0] = 0;
		return;
	}
E 13
	if ((i = isreg(s)) >= 0) {
D 16
		*(short *)(regs[i]) = 0; /* if register destination, that reg is a goner */
E 16
I 16
		/* if register destination, that reg is a goner */
		regs[i][0] = regs[i][1] = 0;
E 16
D 8
		if (DOUBLE==(type&0xF) || DOUBLE==((type>>4)&0xF))
			*(short *)(regs[i+1]) = 0; /* clobber two at once */
E 8
I 8
		switch(type & 0xF){
		case DFLOAT:	/* clobber two at once */
			/*FALLTHROUGH*/
		case GFLOAT:
D 16
			*(short *)(regs[i+1]) = 0;
E 16
I 16
			regs[i+1][0] = regs[i+1][1] = 0;
E 16
			break;
		case HFLOAT:	/* clobber four at once */
D 16
			*(short *)(regs[i+1]) = 0;
			*(short *)(regs[i+2]) = 0;
			*(short *)(regs[i+3]) = 0;
E 16
I 16
			regs[i+1][0] = regs[i+1][1] = 0;
			regs[i+2][0] = regs[i+2][1] = 0;
			regs[i+3][0] = regs[i+3][1] = 0;
E 16
			break;
		}
		switch((type>>4)&0xF){
		case DFLOAT:	/* clobber two at once */
			/*FALLTHROUGH*/
		case GFLOAT:
D 16
			*(short *)(regs[i+1]) = 0;
E 16
I 16
			regs[i+1][0] = regs[i+1][1] = 0;
E 16
			break;
		case HFLOAT:	/* clobber four at once */
D 16
			*(short *)(regs[i+1]) = 0;
			*(short *)(regs[i+2]) = 0;
			*(short *)(regs[i+3]) = 0;
E 16
I 16
			regs[i+1][0] = regs[i+1][1] = 0;
			regs[i+2][0] = regs[i+2][1] = 0;
			regs[i+3][0] = regs[i+3][1] = 0;
E 16
			break;
		}
D 16
		/*
		if (DFLOAT==(type&0xF) || DFLOAT==((type>>4)&0xF))
			*(short *)(regs[i+1]) = 0;
		*/
E 16
E 8
	}
	for (i=NREG; --i>=0;)
		if (regs[i][1]=='*' && equstr(s, regs[i]+2))
D 16
			*(short *)(regs[i]) = 0; /* previous indirection through destination is invalid */
E 16
I 16
			regs[i][0] = regs[i][1] = 0; /* previous indirection through destination is invalid */
E 16
	while ((i = findrand(s,0)) >= 0) /* previous values of destination are invalid */
D 16
		*(short *)(regs[i]) = 0;
E 16
I 16
		regs[i][0] = regs[i][1] = 0;
E 16
D 13
	if (!natural(s)) {/* wild store, everything except constants vanishes */
		for (i=NREG; --i>=0;) if (regs[i][1] != '$') *(short *)(regs[i]) = 0;
		conloc[0] = 0; ccloc[0] = 0;
	} else setcc(s,type); /* natural destinations set condition codes */
E 13
I 13
	if (*conloc && equstr(conloc, s))
		conloc[0] = 0;
	setcc(s, type); /* natural destinations set condition codes */
E 13
}

D 13
splitrand(p) struct node *p; {
E 13
/* separate operands at commas, set up 'regs' and 'lastrand' */
D 13
register char *p1, *p2; register char **preg;
preg=regs+RT1;
if (p1=p->code) while (*p1) {
	lastrand=p2= *preg++;
	while (*p1) if (','==(*p2++= *p1++)) {--p2; break;}
	*p2=0;
E 13
I 13
splitrand(p) struct node *p; {
	register char *p1, *p2;
	register char **preg;

	preg = regs+RT1;
	if (p1 = p->code)
		while (*p1) {
			lastrand = p2 = *preg++;
			while (*p1)
				if (',' == (*p2++ = *p1++)) {
					--p2;
					break;
				}
			*p2 = 0;
		}
	while (preg < (regs+RT1+5))
		*(*preg++) = 0;
E 13
}
D 13
while (preg<(regs+RT1+5)) *(*preg++)=0;
}
E 13

compat(have, want) {
register int hsrc, hdst;
if (0==(want &= 0xF)) return(1); /* anything satisfies a wildcard want */
D 19
hsrc=have&0xF; if (0==(hdst=((have>>4)&0xF)) || hdst>=OP2) hdst=hsrc;
E 19
I 19
hsrc=have&0xF;
if (0==(hdst=((have>>4)&0xF)) || (hdst>=OP2 && hdst<=OPX)) hdst=hsrc;
E 19
D 8
if (want>=FLOAT) return(hdst==want && hsrc==want);
	/* FLOAT, DOUBLE not compat: rounding */
return(hsrc>=want && hdst>=want && hdst<FLOAT);
E 8
I 8
if (want>=FFLOAT) return(hdst==want && hsrc==want);
	/* FLOAT, DFLOAT not compat: rounding */
return(hsrc>=want && hdst>=want && hdst<FFLOAT);
E 8
}

equtype(t1,t2) {return(compat(t1,t2) && compat(t2,t1));}

findrand(as, type)
char *as;
{
	register char **i;
	for (i = regs+NREG; --i>=regs;) {
		if (**i && equstr(*i+1, as) && compat(**i,type))
			return(i-regs);
	}
	return(-1);
}

isreg(s)
register char *s;
{
	if (*s++!='r' || !isdigit(*s++)) return(-1);
	if (*s==0) return(*--s-'0');
	if (*(s-1)=='1' && isdigit(*s++) && *s==0) return(10+*--s-'0');
	return(-1);
}

check()
{
	register struct node *p, *lp;

	lp = &first;
	for (p=first.forw; p!=0; p = p->forw) {
D 16
		if (p->back != lp)
			abort(-1);
E 16
I 16
		if (p->back != lp) {
			fprintf(stderr, "c2: failed internal consistency check -- help!\n");
			exit(-1);
		}
E 16
		lp = p;
	}
}

source(ap)
char *ap;
{
	register char *p1, *p2;

	p1 = ap;
	p2 = p1;
	if (*p1==0)
		return(0);
	while (*p2++ && *(p2-1)!='[');
	if (*p1=='-' && *(p1+1)=='('
	 || *p1=='*' && *(p1+1)=='-' && *(p1+2)=='('
	 || *(p2-2)=='+') {
		while (*p1 && *p1++!='r');
		if (isdigit(*p1++))
D 16
			if (isdigit(*p1)) *(short *)(regs[10+*p1-'0'])=0;
			else *(short *)(regs[*--p1-'0'])=0;
E 16
I 16
			if (isdigit(*p1))
				regs[10+*p1-'0'][0] = regs[10+*p1-'0'][1] = 0;
			else {
				--p1;
				regs[*p1-'0'][0] = regs[*p1-'0'][1] = 0;
			}
E 16
		return(1);
	}
	return(0);
}

newcode(p) struct node *p; {
	register char *p1,*p2,**preg;
	preg=regs+RT1; p2=line;
	while (*(p1= *preg++)) {while (*p2++= *p1++); *(p2-1)=',';}
	*--p2=0;
	p->code=copy(line);
}

repladdr(p)
struct node *p;
{
	register r;
D 16
	register char *p1, *p2;
E 16
I 16
	register char *p1;
E 16
	char **preg; int nrepl;

	preg=regs+RT1; nrepl=0;
	while (lastrand!=(p1= *preg++))
		if (!source(p1) && 0<=(r=findrand(p1,p->subop))) {
			*p1++='r'; if (r>9) {*p1++='1'; r -= 10;} *p1++=r+'0'; *p1=0;
			nrepl++; nsaddr++;
		}
	if (nrepl) newcode(p);
}

/* movedat()
/* {
/* 	register struct node *p1, *p2;
/* 	struct node *p3;
/* 	register seg;
/* 	struct node data;
/* 	struct node *datp;
/* 
/* 	if (first.forw == 0)
/* 		return;
/* 	datp = &data;
/* 	for (p1 = first.forw; p1!=0; p1 = p1->forw) {
/* 		if (p1->op == DATA) {
/* 			p2 = p1->forw;
/* 			while (p2 && p2->op!=TEXT)
/* 				p2 = p2->forw;
/* 			if (p2==0)
/* 				break;
/* 			p3 = p1->back;
/* 			p1->back->forw = p2->forw;
/* 			p2->forw->back = p3;
/* 			p2->forw = 0;
/* 			datp->forw = p1;
/* 			p1->back = datp;
/* 			p1 = p3;
/* 			datp = p2;
/* 		}
/* 	}
/* 	if (data.forw) {
/* 		datp->forw = first.forw;
/* 		first.forw->back = datp;
/* 		data.forw->back = &first;
/* 		first.forw = data.forw;
/* 	}
/* 	seg = -1;
/* 	for (p1 = first.forw; p1!=0; p1 = p1->forw) {
/* 		if (p1->op==TEXT||p1->op==DATA||p1->op==BSS) {
/* 			if (p1->op == seg || p1->forw&&p1->forw->op==seg) {
/* 				p1->back->forw = p1->forw;
/* 				p1->forw->back = p1->back;
/* 				p1 = p1->back;
/* 				continue;
/* 			}
/* 			seg = p1->op;
/* 		}
/* 	}
/* }
*/

redunbr(p)
register struct node *p;
{
	register struct node *p1;
	register char *ap1;
	char *ap2;

	if ((p1 = p->ref) == 0)
		return;
	p1 = nonlab(p1);
	if (p1->op==TST) {
		splitrand(p1);
D 32
		savereg(RT2, "$0", p1->subop);
E 32
I 32
		regs[RT2][0] = '$';
		regs[RT2][1] = '0';
		regs[RT2][2] = '\0';
E 32
	} else if (p1->op==CMP)
		splitrand(p1);
	else
		return;
	if (p1->forw->op==CBR) {
		ap1 = findcon(RT1, p1->subop);
		ap2 = findcon(RT2, p1->subop);
		p1 = p1->forw;
		if (compare(p1->subop, ap1, ap2)) {
			nredunj++;
			nchange++;
			decref(p->ref);
			p->ref = p1->ref;
			p->labno = p1->labno;
#ifdef COPYCODE
			if (p->labno == 0)
				p->code = p1->code;
D 13
			if (p->ref)
E 13
#endif
I 13
			if (p->ref)
E 13
				p->ref->refc++;
		}
	} else if (p1->op==TST && equstr(regs[RT1],ccloc+1) &&
			equtype(ccloc[0],p1->subop)) {
D 25
		p1=insertl(p1->forw); decref(p->ref); p->ref=p1; 
E 25
I 25
		p1=insertl(p1->forw);
		decref(p->ref);
		p->ref=p1; 
		p->labno=p1->labno;
E 25
		nrtst++; nchange++;
	}
}

char *
findcon(i, type)
{
	register char *p;
	register r;

	p = regs[i];
	if (*p=='$')
		return(p);
	if ((r = isreg(p)) >= 0 && compat(regs[r][0],type))
		return(regs[r]+1);
	if (equstr(p, conloc))
		return(conval+1);
	return(p);
}

D 16
compare(op, acp1, acp2)
E 16
I 16
compare(opc, acp1, acp2)
E 16
char *acp1, *acp2;
{
	register char *cp1, *cp2;
	register n1;
	int n2;	int sign;

	cp1 = acp1;
	cp2 = acp2;
	if (*cp1++ != '$' || *cp2++ != '$')
		return(0);
	n1 = 0; sign=1; if (*cp2=='-') {++cp2; sign= -1;}
	while (isdigit(*cp2)) {n1 *= 10; n1 += (*cp2++ - '0')*sign;}
	n2 = n1;
	n1 = 0; sign=1; if (*cp1=='-') {++cp1; sign= -1;}
	while (isdigit(*cp1)) {n1 *= 10; n1 += (*cp1++ - '0')*sign;}
	if (*cp1=='+')
		cp1++;
	if (*cp2=='+')
		cp2++;
	do {
		if (*cp1++ != *cp2)
			return(0);
	} while (*cp2++);
D 16
	cp1 = n1;
	cp2 = n2;
	switch(op) {
E 16
I 16
	switch(opc) {
E 16

	case JEQ:
D 16
		return(cp1 == cp2);
E 16
I 16
		return(n1 == n2);
E 16
	case JNE:
D 16
		return(cp1 != cp2);
E 16
I 16
		return(n1 != n2);
E 16
	case JLE:
D 16
		return(((int)cp1) <= ((int)cp2));
E 16
I 16
		return(n1 <= n2);
E 16
	case JGE:
D 16
		return(((int)cp1) >= ((int)cp2));
E 16
I 16
		return(n1 >= n2);
E 16
	case JLT:
D 16
		return(((int)cp1) < ((int)cp2));
E 16
I 16
		return(n1 < n2);
E 16
	case JGT:
D 16
		return(((int)cp1) > ((int)cp2));
E 16
I 16
		return(n1 > n2);
E 16
	case JLO:
D 16
		return(cp1 < cp2);
E 16
I 16
		return((unsigned) n1 < (unsigned) n2);
E 16
	case JHI:
D 16
		return(cp1 > cp2);
E 16
I 16
		return((unsigned) n1 > (unsigned) n2);
E 16
	case JLOS:
D 16
		return(cp1 <= cp2);
E 16
I 16
		return((unsigned) n1 <= (unsigned) n2);
E 16
	case JHIS:
D 16
		return(cp1 >= cp2);
E 16
I 16
		return((unsigned) n1 >= (unsigned) n2);
E 16
	}
	return(0);
}

setcon(cv, cl, type)
register char *cv, *cl;
{
	register char *p;

	if (*cv != '$')
		return;
	if (!natural(cl))
		return;
	p = conloc;
	while (*p++ = *cl++);
	p = conval;
	*p++ = type;
	while (*p++ = *cv++);
}

equstr(p1, p2)
register char *p1, *p2;
{
	do {
		if (*p1++ != *p2)
			return(0);
	} while (*p2++);
	return(1);
}

setcc(ap,type)
char *ap;
{
	register char *p, *p1;

	p = ap;
	if (!natural(p)) {
		ccloc[0] = 0;
		return;
	}
	p1 = ccloc;
	*p1++ = type;
	while (*p1++ = *p++);
}

okio(p) register char *p; {/* 0->probable I/O space address; 1->not */
	if (ioflag && (!natural(p) || 0>getnum(p))) return(0);
	return(1);
}

indexa(p) register char *p; {/* 1-> uses [r] addressing mode; 0->doesn't */
	while (*p) if (*p++=='[') return(1);
	return(0);
}

natural(p)
register char *p;
{/* 1->simple local, parameter, global, or register; 0->otherwise */
D 13
	if (*p=='*' || *p=='(' || *p=='-'&&*(p+1)=='(' || *p=='$'&&getnum(p+1))
E 13
I 13
	if (*p=='*' || *p=='(' || *p=='-'&&p[1]=='(' || *p=='$'&&getnum(p+1))
E 13
		return(0);
	while (*p++);
	p--;
D 13
	if (*--p=='+' || *p==']' || *p==')' && *(p-2)!='a' && *(p-2)!='f')
E 13
I 13
	if (*--p=='+' || *p==']' || *p==')' && p[-2]!='a' && p[-2]!='f')
E 13
		return(0);
	return(1);
}

/*
** Tell if an argument is most likely static.
*/

isstatic(cp)
register char	*cp;
{
	if (*cp == '_' || *cp == 'L' || (*cp++ == 'v' && *cp == '.'))
		return (1);
	return (0);
}
I 10

autoid(p) register char *p; {/* 1-> uses autoincrement/autodecrement; 0->doesn't */
	if (*p == '-' && *(p+1) == '(') return(1);
	while (*p) p++;
	if (*--p == '+' && *--p == ')') return(1);
	return(0);
  }
E 10
E 1
