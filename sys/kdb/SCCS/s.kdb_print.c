h24756
s 00020/00013/00215
d D 7.5 86/12/15 20:26:51 sam 5 4
c lint
e
s 00029/00048/00199
d D 7.4 86/11/23 13:36:04 sam 4 3
c move machine dependencies to ../machine/kdbparam.h
e
s 00009/00005/00238
d D 7.3 86/11/20 15:48:58 sam 3 2
c keep trap info around as well as current proc; move printing 
c of this stuff into machine-dependent routine
e
s 00008/00010/00235
d D 7.2 86/11/20 14:44:40 sam 2 1
c put back old radix handling; print current values on $s and $w
e
s 00245/00000/00000
d D 7.1 86/11/20 12:22:06 sam 1 0
c date and time created 86/11/20 12:22:06 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

#include "../kdb/defs.h"

I 2
char	*BADRAD;

E 2
ADDR	lastframe;
ADDR	callpc;

char	*BADMOD;
char	*lp;
long	maxpos;
int	radix;
char	lastc;

/* breakpoints */
BKPTR	bkpthead;

D 4
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
E 4
I 4
extern	REGLIST reglist[];
E 4

/* general printing routines ($) */

printtrace(modif)
{
	register narg, i;
	register BKPTR bkptr;
	register ADDR word;
	register char *comptr;
	register ADDR argp, frame;
	register struct nlist *sp;
D 5
	int stack, ntramp;
E 5
I 5
	int ntramp;
E 5
I 3
	register struct  proc *p;
	extern struct proc *allproc;
E 3

	if (cntflg==0)
		cntval = -1;
	switch (modif) {

	case 'd':
		if (adrflg) {
D 2
			if (!(adrval>=2 &&
			      adrval<=16 || adrval<=-2 && adrval>=-16)) {
				printf("illegal radix %d base ten", radix);
				break;
			}
			radix=adrval;
E 2
I 2
			if (adrval < 2 || adrval > 16)
				error(BADRAD);
			radix = adrval;
E 2
		}
D 2
		printf("radix=%d base ten",radix);
E 2
I 2
		printf("radix=%d base ten", radix);
E 2
		break;

	case 'w': case 'W':
D 2
		maxpos=(adrflg?adrval:MAXPOS);
E 2
I 2
		printf("maxpos=%d", maxpos=(adrflg?adrval:MAXPOS));
E 2
		break;

	case 's': case 'S':
D 2
		maxoff=(adrflg?adrval:MAXOFF);
E 2
I 2
		printf("maxoff=%d", maxoff=(adrflg?adrval:MAXOFF));
E 2
		break;

	case 'v': case 'V':
		printf("variables\n");
		for (i=0;i<=35;i++)
			if (var[i]) {
				printc((i<=9 ? '0' : 'a'-10) + i);
				printf(" = %R\n",var[i]);
			}
		break;

	case 0: case '?':
I 3
		if (p = (struct proc *)var[varchk('p')])
			printf("pid = %d\n", p->p_pid);
		else
			printf("in idle loop\n");
		printtrap(var[varchk('t')], var[varchk('c')]);
		/* fall thru... */
E 3
D 2

E 2
	case 'r': case 'R':
		printregs(modif);
		return;

	case 'c': case 'C':
		if (adrflg) {
D 4
			frame=adrval;
			callpc=get(frame-8,DSP);
E 4
I 4
			frame = adrval;
			callpc = getprevpc(frame);
E 4
		} else {
			frame = pcb.pcb_fp;
			callpc = pcb.pcb_pc;
		}
D 4
		lastframe=0;
E 4
I 4
		lastframe = NOFRAME;
E 4
		ntramp = 0;
D 4
		while (cntval-- && frame!=0) {
E 4
I 4
		while (cntval-- && frame != NOFRAME) {
E 4
			char *name;

			chkerr();
			/* check for pc in pcb (signal trampoline code) */
D 4
			if (MAXSTOR < callpc &&
			   callpc < MAXSTOR+ctob(UPAGES)) {
E 4
I 4
			if (issignalpc(callpc)) {
E 4
				name = "sigtramp";
				ntramp++;
			} else {
				ntramp = 0;
D 4
				findsym(callpc,ISYM);
E 4
I 4
D 5
				findsym(callpc, ISYM);
E 5
I 5
				(void) findsym((long)callpc, ISYM);
E 5
E 4
				if (cursym)
					name = cursym->n_un.n_name;
				else
					name = "?";
			}
			printf("%s(", name);
D 4
			narg = ((get(frame-4, DSP)&0xffff)-4)/4;
E 4
I 4
			narg = getnargs(frame);
E 4
			argp = frame;
			if (ntramp != 1)
D 4
				for (;;) {
					if (narg==0)
						break;
					printf("%R", get(argp += 4, DSP));
					if (--narg!=0)
E 4
I 4
				while (narg) {
					printf("%R",
D 5
					    get(argp = nextarg(argp), DSP));
E 5
I 5
					    get((off_t)(argp = nextarg(argp)),
					        DSP));
E 5
					if (--narg != 0)
E 4
						printc(',');
				}
			printf(") at ");
D 5
			psymoff(callpc, ISYM, "\n");
E 5
I 5
			psymoff((long)callpc, ISYM, "\n");
E 5

			if (modif=='C') {
D 4
				while (localsym(frame,argp)) {
					word=get(localval,DSP);
E 4
I 4
D 5
				while (localsym(frame, argp)) {
					word = get(localval, DSP);
E 5
I 5
				while (localsym((long)frame)) {
					word = get((off_t)localval, DSP);
E 5
E 4
					printf("%8t%s:%10t",
					    cursym->n_un.n_name);
					if (errflg) {
						printf("?\n");
D 4
						errflg=0;
E 4
I 4
						errflg = 0;
E 4
					} else
D 4
						printf("%R\n",word);
E 4
I 4
						printf("%R\n", word);
E 4
				}
			}
			if (ntramp != 1) {
D 4
				callpc = get(frame-8, DSP);
E 4
I 4
				callpc = getprevpc(frame);
E 4
				lastframe = frame;
D 4
				frame = get(frame, DSP)&ALIGN;
E 4
I 4
				frame = getprevframe(frame);
E 4
			} else
D 4
				callpc = get(lastframe+44, DSP);
			if (frame == 0 || (!adrflg && !INSTACK(frame)))
E 4
I 4
				callpc = getsignalpc(lastframe);
			if (!adrflg && !INSTACK(frame))
E 4
				break;
		}
		break;

		/*print externals*/
	case 'e': case 'E':
		for (sp = symtab; sp < esymtab; sp++)
			if (sp->n_type==(N_DATA|N_EXT) ||
			    sp->n_type==(N_BSS|N_EXT))
				printf("%s:%12t%R\n", sp->n_un.n_name,
D 5
					get(sp->n_value,DSP));
E 5
I 5
					get((off_t)sp->n_value, DSP));
E 5
		break;

		/*print breakpoints*/
	case 'b': case 'B':
		printf("breakpoints\ncount%8tbkpt%24tcommand\n");
		for (bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt)
			if (bkptr->flag) {
		   		printf("%-8.8d",bkptr->count);
D 5
				psymoff(bkptr->loc,ISYM,"%24t");
E 5
I 5
				psymoff((long)bkptr->loc,ISYM,"%24t");
E 5
				comptr=bkptr->comm;
				while (*comptr)
					printc(*comptr++);
			}
		break;

D 3
	case 'l': {
		register struct  proc *p;
		extern struct proc *allproc;

E 3
I 3
	case 'l':
E 3
		for (p = allproc; p; p = p->p_nxt) {
			printf("%X pid %5d %c", p, p->p_pid,
				p->p_stat == SSLEEP ? 'S' :
				p->p_stat == SRUN ? 'R':
				p->p_stat == SIDL ? 'I':
				p->p_stat == SSTOP ? 'T' : '?');
			if (p->p_wchan) {
				printf(" wait ");
D 5
				psymoff(p->p_wchan, ISYM, "");
E 5
I 5
				psymoff((long)p->p_wchan, ISYM, "");
E 5
			}
			printc(EOR);
		}
		break;
D 3
	}
E 3

	default:
		error(BADMOD);
	}
}

static
printregs(c)
{
	register REGPTR	p;
	ADDR v;

D 4
	for (p=reglist; p->rname; p++) {
		if (c!='R' && p->rkern!=&pcb.pcb_psl)
E 4
I 4
	for (p = reglist; p->rname; p++) {
		if (c != 'R' && ishiddenreg(p))
E 4
			continue;
D 4
		c = 'R';
E 4
		v = *p->rkern;
		printf("%s%6t%R %16t", p->rname, v);
D 4
		valpr(v,(p->rkern==&pcb.pcb_pc?ISYM:DSYM));
E 4
I 4
D 5
		valpr(v, p->rkern == &pcb.pcb_pc ? ISYM : DSYM);
E 5
I 5
		valpr((long)v, p->rkern == &pcb.pcb_pc ? ISYM : DSYM);
E 5
E 4
		printc(EOR);
	}
	printpc();
}

getreg(regnam)
{
	register REGPTR	p;
	register char *regptr;
	char *olp;

D 4
	olp=lp;
	for (p=reglist; p->rname; p++) {
		regptr=p->rname;
E 4
I 4
	olp = lp;
	for (p = reglist; p->rname; p++) {
		regptr = p->rname;
E 4
		if (regnam == *regptr++) {
			while (*regptr)
				if (readchar() != *regptr++) {
					--regptr;
					break;
				}
			if (*regptr)
D 4
				lp=olp;
E 4
I 4
				lp = olp;
E 4
			else
D 4
				return((int)p->rkern);
E 4
I 4
				return ((int)p->rkern);
E 4
		}
	}
D 4
	lp=olp;
E 4
I 4
	lp = olp;
E 4
	return (-1);
}

printpc()
{

D 5
	psymoff(pcb.pcb_pc, ISYM, ":%16t");
	printins(ISP, chkget(pcb.pcb_pc, ISP));
E 5
I 5
	psymoff((long)pcb.pcb_pc, ISYM, ":%16t");
	printins(ISP, (long)chkget((off_t)pcb.pcb_pc, ISP));
E 5
	printc(EOR);
}
E 1
