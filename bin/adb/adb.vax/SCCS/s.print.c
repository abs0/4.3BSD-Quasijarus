h02523
s 00001/00001/00479
d D 4.11 85/05/02 15:39:35 mckusick 11 10
c change magic number when walking across sigtramp frame
e
s 00012/00006/00468
d D 4.10 85/05/02 00:05:29 sam 10 9
c show return pc symbolically (to be correct should actually figure 
c out the address of the call[sg], not just display the return pc, but that's 
c too much work for me)
e
s 00002/00002/00472
d D 4.9 85/04/26 17:15:26 mckusick 9 8
c use %x not %X
e
s 00076/00054/00398
d D 4.8 84/12/30 18:18:40 sam 8 7
c check kernel stack addresses properly; reformat a la Bourne for consistency
e
s 00001/00001/00451
d D 4.7 83/08/14 20:36:12 sam 7 6
c updated for revision to signals
e
s 00001/00001/00451
d D 4.6 83/07/04 17:12:33 sam 6 5
c fix frame offset for new signal code
e
s 00014/00010/00438
d D 4.5 82/07/23 16:45:42 kre 5 4
c print variables ($v) in hex; make $<- re-read current file
e
s 00017/00001/00431
d D 4.4 81/05/15 02:04:57 root 4 3
c works, still with prings
e
s 00004/00001/00428
d D 4.3 81/05/15 00:53:59 root 3 2
c new attempt
e
s 00028/00028/00401
d D 4.2 81/05/14 20:09:08 root 2 1
c non-working version
e
s 00429/00000/00000
d D 4.1 81/05/14 15:19:56 root 1 0
c date and time created 81/05/14 15:19:56 by root
e
u
U
t
T
I 1
static	char sccsid[] = "%Z%%M% %I% %G%";
/*
 *
 *	UNIX debugger
 *
 */
#include "defs.h"

MSG		LONGFIL;
MSG		NOTOPEN;
MSG		A68BAD;
MSG		A68LNK;
MSG		BADMOD;

MAP		txtmap;
MAP		datmap;

ADDR		lastframe;
ADDR		callpc;

INT		infile;
INT		outfile;
CHAR		*lp;
L_INT		maxoff;
L_INT		maxpos;
INT		radix;

/* symbol management */
L_INT		localval;

/* breakpoints */
BKPTR		bkpthead;

REGLIST reglist [] = {
D 2
		"p1lr", P1LR,
		"p1br",P1BR,
		"p0lr", P0LR,
		"p0br",P0BR,
		"ksp",KSP,
		"esp",ESP,
		"ssp",SSP,
		"psl", PSL,
		"pc", PC,
		"usp",USP,
		"fp", FP,
		"ap", AP,
		"r11", R11,
		"r10", R10,
		"r9", R9,
		"r8", R8,
		"r7", R7,
		"r6", R6,
		"r5", R5,
		"r4", R4,
		"r3", R3,
		"r2", R2,
		"r1", R1,
		"r0", R0,
E 2
I 2
	"p1lr",	P1LR,	&pcb.pcb_p1lr,
	"p1br",	P1BR,	&pcb.pcb_p1br,
	"p0lr",	P0LR,	&pcb.pcb_p0lr,
	"p0br",	P0BR,	&pcb.pcb_p0br,
	"ksp",	KSP,	&pcb.pcb_ksp,
	"esp",	ESP,	&pcb.pcb_esp,
	"ssp",	SSP,	&pcb.pcb_ssp,
	"psl",	PSL,	&pcb.pcb_psl,
	"pc",	PC,	&pcb.pcb_pc,
	"usp",	USP,	&pcb.pcb_usp,
	"fp",	FP,	&pcb.pcb_fp,
	"ap",	AP,	&pcb.pcb_ap,
	"r11",	R11,	&pcb.pcb_r11,
	"r10",	R10,	&pcb.pcb_r10,
	"r9",	R9,	&pcb.pcb_r9,
	"r8",	R8,	&pcb.pcb_r8,
	"r7",	R7,	&pcb.pcb_r7,
	"r6",	R6,	&pcb.pcb_r6,
	"r5",	R5,	&pcb.pcb_r5,
	"r4",	R4,	&pcb.pcb_r4,
	"r3",	R3,	&pcb.pcb_r3,
	"r2",	R2,	&pcb.pcb_r2,
	"r1",	R1,	&pcb.pcb_r1,
	"r0",	R0,	&pcb.pcb_r0,
E 2
};

char		lastc;

INT		fcor;
STRING		errflg;
INT		signo;
INT		sigcode;


L_INT		dot;
L_INT		var[];
STRING		symfil;
STRING		corfil;
INT		pid;
L_INT		adrval;
INT		adrflg;
L_INT		cntval;
INT		cntflg;

STRING		signals[] = {
		"",
		"hangup",
		"interrupt",
		"quit",
		"illegal instruction",
		"trace/BPT",
		"IOT",
		"EMT",
		"floating exception",
		"killed",
		"bus error",
		"memory fault",
		"bad system call",
		"broken pipe",
		"alarm call",
		"terminated",
		"signal 16",
		"stop (signal)",
		"stop (tty)",
		"continue (signal)",
		"child termination",
		"stop (tty input)",
		"stop (tty output)",
		"input available (signal)",
		"cpu timelimit",
		"file sizelimit",
		"signal 26",
		"signal 27",
		"signal 28",
		"signal 29",
		"signal 30",
		"signal 31",
};

/* general printing routines ($) */

printtrace(modif)
{
	INT		narg, i, stat, name, limit;
	POS		dynam;
	REG BKPTR	bkptr;
	CHAR		hi, lo;
	ADDR		word;
	STRING		comptr;
	ADDR		argp, frame, link;
	register struct nlist *sp;
	INT		stack;
	INT		ntramp;

	IF cntflg==0 THEN cntval = -1; FI

	switch (modif) {

	    case '<':
		IF cntval == 0
		THEN	WHILE readchar() != EOR
			DO OD
			lp--;
			break;
		FI
		IF rdc() == '<'
		THEN	stack = 1;
		ELSE	stack = 0; lp--;
		FI
D 8
							/* fall through */
E 8
I 8
		/* fall thru... */

E 8
	    case '>':
		{CHAR		file[64];
		CHAR		Ifile[128];
		extern CHAR	*Ipath;
		INT		index;

		index=0;
D 5
		IF modif=='<'
		THEN	iclose(stack, 0);
		ELSE	oclose();
		FI
E 5
		IF rdc()!=EOR
		THEN	REP file[index++]=lastc;
			    IF index>=63 THEN error(LONGFIL); FI
			PER readchar()!=EOR DONE
			file[index]=0;
			IF modif=='<'
			THEN	IF Ipath THEN
					strcpy(Ifile, Ipath);
					strcat(Ifile, "/");
					strcat(Ifile, file);
				FI
D 5
				infile=open(file,0);
				IF infile<0 && (infile=open(Ifile,0))<0
E 5
I 5
				IF strcmp(file, "-")!=0
				THEN	iclose(stack, 0);
					infile=open(file,0);
					IF infile<0
					THEN	infile=open(Ifile,0);
					FI
				ELSE	lseek(infile, 0L, 0);
				FI
				IF infile<0
E 5
				THEN	infile=0; error(NOTOPEN);
				ELSE	IF cntflg
					THEN	var[9] = cntval;
					ELSE	var[9] = 1;
					FI
				FI
D 5
			ELSE	outfile=open(file,1);
E 5
I 5
			ELSE	oclose();
				outfile=open(file,1);
E 5
				IF outfile<0
				THEN	outfile=creat(file,0644);
#ifndef EDDT
				ELSE	lseek(outfile,0L,2);
#endif
				FI
			FI

		ELSE	IF modif == '<'
			THEN	iclose(-1, 0);
I 5
			ELSE	oclose();
E 5
			FI
		FI
		lp--;
		}
		break;

I 4
	    case 'p':
D 8
		IF kernel == 0 THEN
			printf("not debugging kernel\n");
		ELSE
			IF adrflg THEN
				int pte = access(RD, dot, DSP, 0);
E 8
I 8
		IF kernel == 0
		THEN	printf("not debugging kernel\n");
		ELSE	IF adrflg
			THEN	int pte = access(RD, dot, DSP, 0);
E 8
				masterpcbb = (pte&PG_PFNUM)*512;
			FI
			getpcb();
		FI
		break;

E 4
	    case 'd':
D 8
		if (adrflg) {
			if (adrval<2 || adrval>16) {printf("must have 2 <= radix <= 16"); break;}
E 8
I 8
		IF adrflg
		THEN	IF adrval < 2 ORF adrval > 16
			THEN	printf("must have 2 <= radix <= 16");
				break;
			FI
E 8
			printf("radix=%d base ten",radix=adrval);
D 8
		}
E 8
I 8
		FI
E 8
		break;

	    case 'q': case 'Q': case '%':
		done();

	    case 'w': case 'W':
		maxpos=(adrflg?adrval:MAXPOS);
		break;

	    case 's': case 'S':
		maxoff=(adrflg?adrval:MAXOFF);
		break;

	    case 'v': case 'V':
		prints("variables\n");
		FOR i=0;i<=35;i++
D 8
		DO IF var[i]
		   THEN printc((i<=9 ? '0' : 'a'-10) + i);
D 5
			printf(" = %Q\n",var[i]);
E 5
I 5
			printf(" = %X\n",var[i]);
E 5
		   FI
E 8
I 8
		DO	IF var[i]
			THEN printc((i<=9 ? '0' : 'a'-10) + i);
D 9
				printf(" = %X\n",var[i]);
E 9
I 9
				printf(" = %x\n",var[i]);
E 9
			FI
E 8
		OD
		break;

	    case 'm': case 'M':
		printmap("? map",&txtmap);
		printmap("/ map",&datmap);
		break;

	    case 0: case '?':
		IF pid
		THEN printf("pcs id = %d\n",pid);
		ELSE prints("no process\n");
		FI
		sigprint(); flushbuf();

	    case 'r': case 'R':
		printregs();
		return;

	    case 'c': case 'C':
		IF adrflg
D 8
		THEN frame=adrval;
E 8
I 8
		THEN	frame=adrval;
E 8
			word=get(adrval+6,DSP)&0xFFFF;
			IF word&0x2000
D 8
			THEN /* 'calls', can figure out argp */
E 8
I 8
			THEN	/* 'calls', can figure out argp */
E 8
				argp=adrval+20+((word>>14)&3); word &= 0xFFF;
D 8
				WHILE word DO IF word&1 THEN argp+=4; FI word>>=1; OD
			ELSE /* 'callg', can't tell where argp is */ argp=frame;
E 8
I 8
				WHILE word
				DO	IF word&1
					THEN	argp+=4;
					FI
					word>>=1;
				OD
			ELSE	/* 'callg', can't tell where argp is */
				argp=frame;
E 8
			FI
			callpc=get(frame+16,DSP);
D 4
		ELSE argp= *(ADDR *)(((ADDR)&u)+AP);
E 4
I 4
D 8
		ELIF kcore THEN
			argp = pcb.pcb_ap;
E 8
I 8
		ELIF kcore
		THEN	argp = pcb.pcb_ap;
E 8
			frame = pcb.pcb_fp;
			callpc = pcb.pcb_pc;
		ELSE	argp= *(ADDR *)(((ADDR)&u)+AP);
E 4
			frame= *(ADDR *)(((ADDR)&u)+FP);
			callpc= *(ADDR *)(((ADDR)&u)+PC);
		FI
		lastframe=0;
		ntramp = 0;
		WHILE cntval--
		DO	char *name;
			chkerr();
D 8
			if (callpc > 0x80000000 - 0x200 * UPAGES) {
				name = "sigtramp";
E 8
I 8
D 10
			IF callpc > 0x80000000 - 0x200 * UPAGES
E 10
I 10
			/* if in extended pcb must be signal trampoline code */
			IF KERNOFF - ctob(UPAGES) < callpc ANDF
			    (unsigned)callpc < KERNOFF
E 10
			THEN	name = "sigtramp";
E 8
				ntramp++;
D 8
			} else {
				ntramp = 0;
E 8
I 8
			ELSE	ntramp = 0;
E 8
				findsym(callpc,ISYM);
D 8
				if (cursym &&
D 5
				    !strcmp(cursym->n_un.n_name, "start"))
E 5
I 5
				    !strcmp(cursym->n_un.n_name, "start")) 
E 5
					break;
				if (cursym)
					name = cursym->n_un.n_name;
				else
					name = "?";
			}
E 8
I 8
				IF cursym ANDF
				    !strcmp(cursym->n_un.n_name, "start")
				THEN break;
				FI
				IF cursym
				THEN name = cursym->n_un.n_name;
				ELSE name = "?";
				FI
			FI
E 8
			printf("%s(", name);
			narg = get(argp,DSP); IF narg&~0xFF THEN narg=0; FI
D 8
			LOOP IF narg==0 THEN break; FI
E 8
I 8
			LOOP	IF narg==0 THEN break; FI
E 8
				printf("%R", get(argp += 4, DSP));
				IF --narg!=0 THEN printc(','); FI
			POOL
D 8
			printf(") from %X\n",callpc);  /* jkf mod */
E 8
I 8
D 9
			printf(") from %X\n",callpc);
E 9
I 9
D 10
			printf(") from %x\n",callpc);
E 10
I 10
			IF ntramp == 1
D 11
			THEN callpc=get(frame+84, DSP);
E 11
I 11
			THEN callpc=get(frame+92, DSP);
E 11
			ELSE callpc=get(frame+16, DSP);
			FI
			IF callpc != 0
			THEN	prints(") from ");
				psymoff(callpc, ISYM, "\n");
			ELSE	prints(")\n");
			FI
E 10
E 9
E 8

			IF modif=='C'
D 8
			THEN WHILE localsym(frame,argp)
			     DO word=get(localval,DSP);
				printf("%8t%s:%10t", cursym->n_un.n_name);
				IF errflg THEN prints("?\n"); errflg=0; ELSE printf("%R\n",word); FI
			     OD
E 8
I 8
			THEN	WHILE localsym(frame,argp)
				DO	word=get(localval,DSP);
					printf("%8t%s:%10t",
					    cursym->n_un.n_name);
					IF errflg
					THEN prints("?\n"); errflg=0;
					ELSE printf("%R\n",word);
					FI
				OD
E 8
			FI

D 8
			if (ntramp == 1)
D 6
				callpc=get(frame+64, DSP);
E 6
I 6
D 7
				callpc=get(frame+76, DSP);
E 7
I 7
				callpc=get(frame+84, DSP);
E 7
E 6
			else
				callpc=get(frame+16, DSP);
E 8
I 8
D 10
			IF ntramp == 1
			THEN callpc=get(frame+84, DSP);
			ELSE callpc=get(frame+16, DSP);
			FI
E 10
E 8
			argp=get(frame+8, DSP);
			lastframe=frame;
			frame=get(frame+12, DSP)&EVEN;
D 8
			IF frame==0 ORF (!adrflg ANDF !INSTACK(frame))
			THEN break;
E 8
I 8
			IF frame==0 THEN break; FI
			IF !adrflg ANDF !INSTACK(frame)
			THEN	IF !kcore ORF !kstackaddr(frame)
				THEN break;
				FI
E 8
			FI
		OD
		break;

	    /*print externals*/
	    case 'e': case 'E':
D 8
		for (sp = symtab; sp < esymtab; sp++) {
		   if (sp->n_type==(N_DATA|N_EXT) ORF sp->n_type==(N_BSS|N_EXT))
		   	printf("%s:%12t%R\n", sp->n_un.n_name, get(sp->n_value,DSP));
		}
E 8
I 8
		FOR sp = symtab; sp < esymtab; sp++
		DO	IF sp->n_type == (N_DATA|N_EXT) ORF
			   sp->n_type == (N_BSS|N_EXT)
			THEN printf("%s:%12t%R\n", sp->n_un.n_name,
				    get(sp->n_value,DSP));
			FI
		OD
E 8
		break;

	    case 'a': case 'A':
		error("No algol 68 on VAX");
		/*NOTREACHED*/

	    /*print breakpoints*/
	    case 'b': case 'B':
		printf("breakpoints\ncount%8tbkpt%24tcommand\n");
D 8
		for (bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt)
			if (bkptr->flag) {
		   		printf("%-8.8d",bkptr->count);
E 8
I 8
		FOR bkptr=bkpthead; bkptr; bkptr=bkptr->nxtbkpt
		DO	IF bkptr->flag
			THEN	printf("%-8.8d",bkptr->count);
E 8
				psymoff(leng(bkptr->loc),ISYM,"%24t");
				comptr=bkptr->comm;
				WHILE *comptr DO printc(*comptr++); OD
D 8
			}
E 8
I 8
			FI
		OD
E 8
		break;

D 8
	    default: error(BADMOD);
E 8
I 8
	    default:
		error(BADMOD);
E 8
	}

}

printmap(s,amap)
STRING	s; MAP *amap;
{
	int file;
	file=amap->ufd;
D 8
	printf("%s%12t`%s'\n",s,(file<0 ? "-" : (file==fcor ? corfil : symfil)));
E 8
I 8
	printf("%s%12t`%s'\n", s,
	    (file<0 ? "-" : (file==fcor ? corfil : symfil)));
E 8
	printf("b1 = %-16R",amap->b1);
	printf("e1 = %-16R",amap->e1);
	printf("f1 = %-16R",amap->f1);
	printf("\nb2 = %-16R",amap->b2);
	printf("e2 = %-16R",amap->e2);
	printf("f2 = %-16R",amap->f2);
	printc(EOR);
}

printregs()
{
	REG REGPTR	p;
	L_INT		v;

	FOR p=reglist; p < &reglist[24]; p++
D 2
	DO	printf("%s%6t%R %16t", p->rname, v= *(ADDR *)(((ADDR)&u)+p->roffs));
E 2
I 2
	DO	v = kcore ? *p->rkern : *(ADDR *)(((ADDR)&u)+p->roffs);
		printf("%s%6t%R %16t", p->rname, v);
E 2
		valpr(v,(p->roffs==PC?ISYM:DSYM));
		printc(EOR);
	OD
	printpc();
}

D 2
getreg(regnam)
{
E 2
I 2
getreg(regnam) {
E 2
	REG REGPTR	p;
	REG STRING	regptr;
	CHAR	*olp;
	CHAR		regnxt;

	olp=lp;
	FOR p=reglist; p < &reglist[24]; p++
	DO	regptr=p->rname;
		IF (regnam == *regptr++)
		THEN
			WHILE *regptr
			DO IF (regnxt=readchar()) != *regptr++
				THEN --regptr; break;
				FI
			OD
			IF *regptr
			THEN lp=olp;
D 2
			ELSE return(p->roffs);
E 2
I 2
D 3
			ELSE return(kcore ? (int)p->rkern : p->roffs);
E 3
I 3
			ELSE
				int i = kcore ? (int)p->rkern : p->roffs;
D 5
				printf("returning %X\n", i);
E 5
				return (i);
E 3
E 2
			FI
		FI
	OD
	lp=olp;
	return(0);
}

printpc()
{
	dot= *(ADDR *)(((ADDR)&u)+PC);
	psymoff(dot,ISYM,":%16t"); printins(0,ISP,chkget(dot,ISP));
	printc(EOR);
}

char	*illinames[] = {
	"reserved addressing fault",
	"priviliged instruction fault",
	"reserved operand fault"
};
char	*fpenames[] = {
	0,
	"integer overflow trap",
	"integer divide by zero trap",
	"floating overflow trap",
	"floating/decimal divide by zero trap",
	"floating underflow trap",
	"decimal overflow trap",
	"subscript out of range trap",
	"floating overflow fault",
	"floating divide by zero fault",
	"floating undeflow fault"
};

sigprint()
{
	IF (signo>=0) ANDF (signo<sizeof signals/sizeof signals[0])
	THEN prints(signals[signo]); FI
	switch (signo) {

	case SIGFPE:
		IF (sigcode > 0 &&
		    sigcode < sizeof fpenames / sizeof fpenames[0]) THEN
			prints(" ("); prints(fpenames[sigcode]); prints(")");
		FI
		break;

	case SIGILL:
		IF (sigcode >= 0 &&
		    sigcode < sizeof illinames / sizeof illinames[0]) THEN
			prints(" ("); prints(illinames[sigcode]); prints(")");
		FI
		break;
	}
}
E 1
