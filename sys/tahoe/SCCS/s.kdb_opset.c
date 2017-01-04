h35686
s 00007/00001/00189
d D 7.4 88/05/21 18:35:26 karels 4 3
c bring up to revision 7 for tahoe release
e
s 00004/00004/00186
d D 7.3 86/12/15 20:27:48 sam 3 2
c lint
e
s 00019/00001/00171
d D 7.2 86/11/23 13:36:54 sam 2 1
c move register list
e
s 00172/00000/00000
d D 7.1 86/11/20 15:50:33 sam 1 0
c date and time created 86/11/20 15:50:33 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

#include "../kdb/defs.h"

/*
D 2
 * Instruction printing
E 2
I 2
 * Instruction printing.
E 2
 */
I 2

REGLIST reglist[] = {
	"p2lr",	&pcb.pcb_p2lr,	"p2br",	(int *)&pcb.pcb_p2br,
	"p1lr",	&pcb.pcb_p1lr,	"p1br",	(int *)&pcb.pcb_p1br,
	"p0lr",	&pcb.pcb_p0lr,	"p0br",	(int *)&pcb.pcb_p0br,
	"ksp",	&pcb.pcb_ksp,	"hfs",	&pcb.pcb_hfs,
	"psl",	&pcb.pcb_psl,	"pc",	&pcb.pcb_pc,
	"ach",	&pcb.pcb_ach,	"acl",	&pcb.pcb_acl,
	"usp",	&pcb.pcb_usp,	"fp",	&pcb.pcb_fp,
	"r12",	&pcb.pcb_r12,	"r11",	&pcb.pcb_r11,
	"r10",	&pcb.pcb_r10,	"r9",	&pcb.pcb_r9,
	"r8",	&pcb.pcb_r8,	"r7",	&pcb.pcb_r7,
	"r6",	&pcb.pcb_r6,	"r5",	&pcb.pcb_r5,
	"r4",	&pcb.pcb_r4,	"r3",	&pcb.pcb_r3,
	"r2",	&pcb.pcb_r2,	"r1",	&pcb.pcb_r1,
	"r0",	&pcb.pcb_r0,
	0
};
E 2

/*
 * Argument access types
 */
#define ACCA	(8<<3)	/* address only */
#define ACCR	(1<<3)	/* read */
#define ACCW	(2<<3)	/* write */
#define ACCM	(3<<3)	/* modify */
#define ACCB	(4<<3)	/* branch displacement */
#define ACCI	(5<<3)	/* XFC code */

/*
 * Argument data types
 */
#define TYPB	0	/* byte */
#define TYPW	1	/* word */
#define TYPL	2	/* long */
#define TYPQ	3	/* quad */
#define TYPF	4	/* float */
#define TYPD	5	/* double */

struct optab {
	char *iname;
	char val;
	char nargs;
	char argtype[6];
};

static	struct optab *ioptab[256];	/* index by opcode to optab */
static	struct optab optab[] = {	/* opcode table */
#define OP(a,b,c,d,e,f,g,h,i) {a,b,c,d,e,f,g,h,i}
#include "../tahoe/kdb_instrs"
0};
static	char *regname[] = {
	"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
	"r8", "r9", "r10", "r11", "r12", "fp", "sp", "pc"
};
D 3
static	POS type, space, incp;
E 3
I 3
static	int type, space, incp;
E 3

/* set up ioptab */
kdbsetup()
{
	register struct optab *p;

	for (p = optab; p->iname; p++)
		ioptab[p->val&LOBYTE] = p;
}

static long
snarf(nbytes, idsp)
{
	register long value;

D 3
	value = chkget(inkdot(incp), idsp);
E 3
I 3
	value = (u_int)chkget((off_t)inkdot(incp), idsp);
E 3
	incp += nbytes;
	return(value>>(4-nbytes)*8);
}

D 3
printins(idsp,ins)
E 3
I 3
printins(idsp, ins)
E 3
	register long ins;
{
	short argno;		/* argument index */
	register mode;		/* mode */
	register r;		/* register name */
D 3
	register d;		/* assembled byte, word, long or float */
E 3
I 3
	register long d;	/* assembled byte, word, long or float */
E 3
	register char *ap;
	register struct optab *ip;

	type = DSYM;
	space = idsp;
	ins = byte(ins);
	if ((ip = ioptab[ins]) == (struct optab *)0) {
		printf("?%2x%8t", ins);
		dotinc = 1;
		return;
	}
	printf("%s%8t",ip->iname);
	incp = 1;
	ap = ip->argtype;
	for (argno = 0; argno < ip->nargs; argno++, ap++) {
		var[argno] = 0x80000000;
		if (argno!=0) printc(',');
	  top:
		if (*ap&ACCB)
			mode = 0xAF + ((*ap&7)<<5);  /* branch displacement */
		else {
			mode = bchkget(inkdot(incp),idsp); ++incp;
		}
		r = mode&0xF;
		mode >>= 4;
		switch ((int)mode) {
			case 0: case 1:
			case 2: case 3:	/* short literal */
				printc('$');
				d = mode<<4|r;
				goto immed;
			case 4: /* [r] */
				printf("[%s]", regname[r]);
				goto top;
			case 5: /* r */
				printf("%s", regname[r]);
				break;
			case 6: /* (r) */
				printf("(%s)", regname[r]);
				break;
			case 7: /* -(r) */
				printf("-(%s)", regname[r]);
				break;
			case 9: /* *(r)+ */
				printc('*');
			case 8: /* (r)+ */
				if (r == 0xF ||
				    mode == 8 && (r == 8 || r == 9)) {
					printc('$');
					d = snarf((r&03)+1, idsp);
				} else {	/*it's not PC immediate or abs*/
					printf("(%s)+", regname[r]);
					break;
				}
			immed:
				if (ins == KCALL && d >= 0 && d < 200) {
					printf("%R", d);
					break;
				}
				goto disp;
			case 0xB:	/* byte displacement deferred */
			case 0xD:	/* word displacement deferred */
			case 0xF:	/* long displacement deferred */
				printc('*');
			case 0xA:	/* byte displacement */
			case 0xC:	/* word displacement */
			case 0xE:	/* long displacement */
				d = snarf(1<<((mode>>1&03)-1), idsp);
				if (r==0xF) { /* PC offset addressing */
					d += dot+incp;
					psymoff(d,type,"");
					var[argno]=d;
					break;
				}
			disp:
				if (d >= 0 && d < maxoff)
					printf("%R", d);
				else
					psymoff(d,type,"");
				if (mode >= 0xA)
					printf("(%s)", regname[r]);
				var[argno] = d;
				break;
		}
	}
	if (ins == CASEL) {
		if (inkdot(incp)&01)	/* align */
			incp++;
		for (argno = 0; argno <= var[2]; ++argno) {
			printc(EOR);
			printf("    %R:  ", argno+var[1]);
			d = shorten(get(inkdot(incp+argno+argno), idsp));
			if (d&0x8000)
				d -= 0x10000;
			psymoff(inkdot(incp)+d, type, "");
		}
		incp += var[2]+var[2]+2;
	}
	dotinc = incp;
}
E 1
