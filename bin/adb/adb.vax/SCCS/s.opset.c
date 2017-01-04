h37607
s 00006/00000/00574
d D 4.7 88/07/18 18:03:43 bostic 7 6
c Adb naively tries to print the reserved operand with %f and gets a
c fault; from Donn Seeley
e
s 00018/00018/00556
d D 4.6 88/01/10 15:40:33 bostic 6 5
c fix #endif's for ANSI C
e
s 00005/00002/00569
d D 4.5 85/05/27 18:08:54 edward 5 4
c don't use symbolic names in register offsets unless it's PC
e
s 00003/00003/00568
d D 4.4 83/05/12 08:52:07 rrh 4 3
c Fix bug with 0 based indexing into the operator table being 
c mistaken as non existant operator byte.
e
s 00001/00001/00570
d D 4.3 83/05/01 19:24:04 sam 3 2
c from rws@mit-xx
e
s 00506/00213/00065
d D 4.2 82/10/27 14:37:14 rrh 2 1
c Complete reworking of opset.c to make its operation understandable
c Allow 2 byte opcodes for extended VAX architecture (G and H numbers).
c Opset.c is shared between adb and sdb.  Use a common instruction data base
c with adb, sdb, as and c2
e
s 00278/00000/00000
d D 4.1 81/05/14 15:19:49 root 1 0
c date and time created 81/05/14 15:19:49 by root
e
u
U
t
T
I 1
D 2
#
E 2
I 2
#ifndef lint
static	char sccsid[] = "%Z%%M% %I% %G%";
D 6
#endif lint
E 6
I 6
#endif /* lint */
E 6
E 2
/*
D 2
 *
E 2
 *	UNIX debugger
D 2
 *
E 2
I 2
 *	Instruction printing routines.
 *	MACHINE DEPENDENT
E 2
 */

I 2
#ifdef ADB
E 2
#include "defs.h"
D 2
static	char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
D 6
#endif ADB
E 6
I 6
#endif /* ADB */
E 6
#ifdef SDB
#include "head.h"
D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6
E 2

D 2
STRING		errflg;
E 2
L_INT		dot;
INT		dotinc;
D 2
L_INT		var[];
E 2
I 2
L_INT		insoutvar[36];
#ifdef ADB
L_INT		var[36];
D 6
#endif ADB
E 6
I 6
#endif /* ADB */
E 6
E 2

I 2
#undef	INSTTAB
#include "instrs.h"
E 2

D 2
/* instruction printing */

E 2
I 2
STRING	regname[];
STRING	fltimm[];
POS	type, space, incp;
E 2
/*
D 2
 * Argument access types
E 2
I 2
 *	Definitions for registers and for operand classes
E 2
 */
D 2
#define ACCA	(8<<3)	/* address only */
#define ACCR	(1<<3)	/* read */
#define ACCW	(2<<3)	/* write */
#define ACCM	(3<<3)	/* modify */
#define ACCB	(4<<3)	/* branch displacement */
#define ACCI	(5<<3)	/* XFC code */
E 2
I 2
char	*insregname();	/* how to print a register */
E 2

I 2
#define	R_PC		0xF

#define	OC_IMM0		0x0
#define	OC_IMM1		0x1
#define	OC_IMM2		0x2
#define	OC_IMM3		0x3
#define	OC_INDEX	0x4
#define	OC_REG		0x5
#define	OC_DREG		0x6
#define	OC_ADREG	0x7
#define	OC_AIREG	0x8
#define	OC_DAIREG	0x9

#define	OC_BDISP	0xA
#define	OC_DBDISP	0xB
#define	OC_WDISP	0xC
#define	OC_DWDISP	0xD
#define	OC_LDISP	0xE
#define	OC_DLDISP	0xF

#define	OC_SHIFT	4
#define	OC_CONS(oc,reg)	(((oc & 0xF) << OC_SHIFT) | (reg & 0xF))
#define	OC_AMEXT(x)	(((x) >> OC_SHIFT) & 0xF)
#define	OC_REGEXT(x)	((x) & 0xF)

E 2
/*
D 2
 * Argument data types
E 2
I 2
 *	Definitions for large numbers
E 2
 */
D 2
#define TYPB	0	/* byte */
#define TYPW	1	/* word */
#define TYPL	2	/* long */
#define TYPQ	3	/* quad */
#define TYPF	4	/* floating */
#define TYPD	5	/* double floating */
E 2
I 2
#include "asnumber.h"
typedef	struct	as_number	*numberp;
numberp snarf();
numberp snarfreloc();
/*
 *	Definitions for special instructions
 */
#define	CASEB	0x8F
#define	CASEW	0xAF
#define	CASEL	0xCF
/*
 *	Definitions for converting TYP's into numbers, booleans, etc.
 *	These are shared with the assembler.
 */
extern	int	ty_NORELOC[];
extern	int	ty_float[];
extern	int	ty_nbyte[];
extern	int	ty_nlg[];
extern	char	*ty_string[];
E 2

I 2
D 4
short ioptab[3][256];	/* two level index by opcode into insttab */
E 4
I 4
short ioptab[3][256];	/* two level 1-based index by opcode into insttab */
E 4
E 2

D 2
TYPE	struct optab	*OPTAB;
struct optab {
	char *iname;
	char val;
	char nargs;
	char argtype[6];
} optab[];
#define SYSTAB struct systab
SYSTAB {
	int	argc;
	char	*sname;
} systab[];
STRING	regname[];
STRING	fltimm[];
POS	type, space, incp;
E 2
I 2
int mapescbyte(byte)
	u_char	byte;
{
	switch(byte){
	default:	return(0);
	case ESCD:	return(1);
	case ESCF:	return(2);
	}
}
E 2

D 2
int ioptab[256]; /* index by opcode to optab */
E 2
I 2
mkioptab()
{
	REG	struct insttab *p;
		int	mapchar;
E 2

D 2
mkioptab() {/* set up ioptab */
	REG OPTAB p=optab;
	while (p->iname){
		ioptab[p->val&LOBYTE]=p-optab;
		p++;
E 2
I 2
	for(p = insttab; p->iname; p++){
		mapchar = mapescbyte(p->eopcode);
		if (ioptab[mapchar][p->popcode])
			continue;
D 4
		ioptab[mapchar][p->popcode] = p - insttab;
E 4
I 4
		ioptab[mapchar][p->popcode] = (p - insttab) + 1;
E 4
E 2
	}
}

D 2
extern char *fmtr;	/* not used */
extern char *fmtR;	/* not used */
E 2
I 2
u_char snarfuchar();
/*
 *	Global variables for communicating with the minions and printins
 */
static	int	idsp;
static	short	argno;		/* which argument one is working on */
static	char	insoutfmt[2];	/* how to format the relocated symbols */
#ifdef SDB
static	struct	proct	*procp;
D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6
E 2

D 2
printins(f,idsp,ins)
E 2
I 2
static savevar(val)
	long	val;
{
	var[argno] = val;
	insoutvar[argno] = val;
}

printins(fmt, Idsp, ins)
	char	fmt;
E 2
#ifndef vax
D 2
	REG INT		ins;
E 2
I 2
	u_char	ins;
E 2
#else
D 2
	REG L_INT	ins;
E 2
I 2
	u_char	ins;
E 2
#endif
I 2
	int	Idsp;
E 2
{
D 2
	short	argno;		/* argument index */
	short	mode;		/* mode */
	char	**r;		/* register name */
	long	d;		/* assembled byte, word, long or float */
	long	snarf();
	REG char *	ap;
	REG OPTAB	ip;
E 2
I 2
		u_char	mode;		/* mode */
		u_char	ins2;
		char	*indexreg;	/* print of which register indexes */
		char	*indexed;	/* we indexed */
		char	*operandout();
	REG	u_char 	*ap;
	REG	struct insttab *ip;
		u_char	optype;
		int	mapchar;
E 2

I 2
	idsp = Idsp;
E 2
	type = DSYM;
	space = idsp;
D 2
	ins &= LOBYTE;
	ip=optab+ioptab[ins];
	printf("%s%8t",ip->iname);
E 2
I 2
#ifdef SDB
	procp = adrtoprocp(dot);
	if (procp->paddr == dot){
		printf("0x%04.4x", ins);
		incp = 2;
		goto ret;
	}
D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6

#ifdef ADB
	insoutfmt[0] = 0;
D 6
#endif ADB
E 6
I 6
#endif /* ADB */
E 6
#ifdef SDB
	insoutfmt[0] = fmt;
D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6

E 2
	incp = 1;
D 2
	ap = ip->argtype;
	for (argno=0; argno<ip->nargs; argno++,ap++) {
		var[argno] = 0x80000000;
		if (argno!=0) printc(',');
	  top:
		if (*ap&ACCB)
			mode = 0xAF + ((*ap&7)<<5);  /* branch displacement */
		else{
			mode = bchkget(inkdot(incp),idsp); ++incp;
E 2
I 2
	if ((mapchar = mapescbyte(ins)) != 0){
		ins2 = snarfuchar();
		if (ioptab[mapchar][ins2] == 0){
			/*
			 *	Oops; not a defined instruction;
			 *	back over this escape byte.
			 */
			incp -= 1;
			mapchar = 0;
		} else {
			ins = ins2;
E 2
		}
D 2
		if (mode & 0300) {/* not short literal */
			r = &regname[mode&0xF];
			mode >>= 4;
			switch ((int)mode) {
				case 4: /* [r] */
					printf("[%s]",*r);
					goto top;
				case 5: /* r */
					printf("%s",*r);
E 2
I 2
	}
	if (ioptab[mapchar][ins] == 0){
		printf("<undefined operator byte>: %x", ins);
		goto ret;
	}
D 4
	ip = &insttab[ioptab[mapchar][ins]];
E 4
I 4
	ip = &insttab[ioptab[mapchar][ins] - 1];
E 4
	printf("%s\t", ip->iname);

	for (ap = ip->argtype, argno = 0; argno < ip->nargs; argno++, ap++) {
		savevar(0x80000000);	/* an illegal symbol */
		optype = *ap;
		if (argno != 0)
			printc(',');
		indexreg = 0;
		indexed = 0;
		do{
			if (A_ACCEXT(optype) & ACCB){
				switch(A_TYPEXT(optype)){
				case TYPB:
					mode = OC_CONS(OC_BDISP, R_PC);
E 2
					break;
D 2
				case 6: /* (r) */
					printf("(%s)",*r);
E 2
I 2
				case TYPW:
					mode = OC_CONS(OC_WDISP, R_PC);
E 2
					break;
D 2
				case 7: /* -(r) */
					printf("-(%s)",*r);
					break;
				case 9: /* *(r)+ */
					printc('*');
				case 8: /* (r)+ */
				  if (r==(regname+0xF)) {
					printc('$');
					if (mode==9){	/* PC absolute, always 4 bytes*/
						d = snarf(4, idsp);
						goto disp;
					}
					switch(*ap&7){
					 case TYPB:
						d = snarf(1, idsp);
						goto disp;
					 case TYPW:
						d = snarf(2, idsp);
						goto disp;
					 case TYPL:
						d = snarf(4, idsp);
						goto disp;
					 case TYPQ:
						d = snarf(4, idsp);
						printquad(d, snarf(4, idsp));
						break;
					 case TYPF:
						printfloating(TYPF, snarf(4, idsp), 0);
						break;
					 case TYPD:
						d = snarf(4, idsp);
						printfloating(TYPQ, d, snarf(4, idsp));
						break;
					} /*end of type switch */
					/*
					 *	here only for TYPQ, TYPf, TYPD
					 *	others went to disp
					 */
				  } else {	/*it's not PC immediate or abs*/
					  printf("(%s)+",*r);
				  }
				  break;
				case 0xB:	/* byte displacement defferred*/
					printc('*');
				case 0xA:	/* byte displacement */
					d = snarf(1, idsp);
					goto disp;
				case 0xD:	/* word displacement deferred */
					printc('*');
				case 0xC:	/* word displacement */
					d = snarf(2, idsp);
					goto disp;
				case 0xF:	/* long displacement deferred */
					printc('*');
				case 0xE:	/* long displacement */
					d = snarf(4, idsp);
					goto disp;
			disp:
					var[argno]=d;
					if (r==(regname+0xF) && mode>=0xA){
						/* PC offset addressing */
						var[argno] += dot+incp;
					}
					psymoff(var[argno],type,"");
					if (r != regname+0xF)
						printf("(%s)",*r);
					break;
			} /* end of the mode switch */
		} else {   /* short literal */
			var[argno]=mode;
			if(   (*ap&7)==TYPF
			   || (*ap&7)==TYPD)
				printf("$%s",fltimm[mode]);
			else
				printf("$%r",mode);
		}
E 2
I 2
				}
			} else {
				mode = snarfuchar();
			}
			indexreg = operandout(mode, optype);
			if (indexed)
				printf("[%s]", indexed);
			indexed = indexreg;
		} while(indexed);
E 2
	}
D 2
	if (ins==0xCF || ins==0xAF || ins==0x8F) {/* CASEx instr */
		for (argno=0; argno<=var[2]; ++argno) {
			printc(EOR);
			printf("    %R:  ",argno+var[1]);
			d=get(inkdot(incp+argno+argno),idsp)&0xFFFF;
			if (d&0x8000) d -= 0x10000;
			psymoff(inkdot(incp)+d,type,"");
E 2
I 2
	if (mapchar == 0){
		switch(ins){
		case CASEB:
		case CASEW:
		case CASEL:
			casebody(insoutvar[1], insoutvar[2]);
			break;
		default:
			break;
E 2
		}
D 2
		incp += var[2]+var[2]+2;
E 2
	}
D 2
	dotinc=incp;
E 2
I 2
   ret: ;

#ifdef SDB
	oincr = incp;
D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6
#ifdef ADB
	dotinc = incp;
D 6
#endif ADB
E 6
I 6
#endif /* ADB */
E 6
E 2
}

I 2
casebody(base, limit)
	long	base;
	long	limit;
{
	int	i;
	POS	baseincp;
	POS	advincp;
	struct	as_number	*valuep;
#define	OSIZE (sizeof(short))
	argno = 0;
	baseincp = incp;
	for (i = 0; i <= limit; i++) {
		printc(EOR);
#ifdef SDB
		printf("    %d:  ", i + base);
D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6
#ifdef ADB
		printf("    %R:  ", i + base);
D 6
#endif ADB
E 6
I 6
#endif /* ADB */
E 6
		valuep = snarfreloc(OSIZE, 0);
		advincp = incp;
		incp = baseincp;
		dispaddress(valuep, OC_CONS(OC_WDISP, R_PC));
		incp = advincp;
	}
}

E 2
/*
 *	magic values to mung an offset to a register into
 *	something that psymoff can understand.. all magic
 */
			      /* 0	1	2	3	4 */
static long magic_masks[5] =	{0,	0x80,	0x8000,	0,	0};	
static long magic_compl[5] =	{0,	0x100,	0x10000,0,	0};
I 2
/*
 *	Snarf up some bytes, and put in the magic relocation flags
 */
numberp snarfreloc(nbytes)
	int	nbytes;
{
	numberp	back;
	back = snarf(nbytes);
	if (back->num_ulong[0] & magic_masks[nbytes])
		back->num_ulong[0] -= magic_compl[nbytes];
	return(back);
}
/*
 *	The following code is NOT portable from the PDP 11 to the VAX
 *	because of the byte ordering problem.
 */
numberp snarf(nbytes)
	int	nbytes;
{
	REG	int	i;
E 2

I 2
	static	struct	as_number	backnumber;
	static	struct	as_number	znumber;	/* init'ed to 0 */

	backnumber = znumber;
	for (i = 0; i < nbytes; i++)
		backnumber.num_uchar[i] = snarfuchar();
	return(&backnumber);
}
E 2
/*
D 2
 *	The following code is NO LONGER portable from the PDP 11 to the VAX
E 2
I 2
 *	Read one single character, and advance the dot
E 2
 */
D 2
long snarf (nbytes, idsp)
			int	nbytes;
E 2
I 2
u_char snarfuchar()
E 2
{
D 2
	register	int	byteindex;
	union Long{
		char	long_bytes[4];
		long	long_value;
	} d;
E 2
I 2
	u_char	back;
	/*
	 *	assert: bchkget and inkdot don't have side effects
	 */
	back = (u_char)bchkget(inkdot(incp), idsp);
	incp += 1;
	return(back);
}
/*
 *	normal operand; return non zero pointer to register
 *	name if this is an index instruction.
 */
char *operandout(mode, optype)
	u_char	mode;
	u_char	optype;
{
	char	*r;
	int	regnumber;
	int	nbytes;
E 2

D 2
	d.long_value = 0;
	for (byteindex = 0; byteindex < nbytes; byteindex++){
		d.long_bytes[byteindex] = bchkget(inkdot(incp), idsp);
		++incp;
E 2
I 2
	regnumber = OC_REGEXT(mode);
	r = insregname(regnumber);
	switch (OC_AMEXT(mode)){
	case OC_IMM0:
	case OC_IMM1:
	case OC_IMM2:
	case OC_IMM3:
		shortliteral(mode, optype);
		return(0);
	case OC_INDEX:
		return(r);		/* will be printed later */
	case OC_REG:
		printf("%s", r);
		return(0);
	case OC_DREG:
		printf("(%s)", r);
		return(0);
	case OC_ADREG:
		printf("-(%s)", r);
		return(0);
	case OC_DAIREG:
		printc('*');
	case OC_AIREG:
		if (regnumber == R_PC){
			pcimmediate(mode, optype);
		} else {
			printf("(%s)+", r);
		}
		return(0);
	case OC_DBDISP:
		printc('*');
	case OC_BDISP:
		nbytes = 1;
		break;
	case OC_DWDISP:
		printc('*');
	case OC_WDISP:
		nbytes = 2;
		break;
	case OC_DLDISP:
		printc('*');
	case OC_LDISP:
		nbytes = 4;
		break;
E 2
	}
D 2
	if (d.long_value & magic_masks[nbytes])
		d.long_value -= magic_compl[nbytes];
	return(d.long_value);
E 2
I 2
	dispaddress(snarfreloc(nbytes), mode);
	return(0);
E 2
}

D 2
printfloating(type, word_first, word_last)
	int	type;
	long	word_first;
	long	word_last;
E 2
I 2
dispaddress(valuep, mode)
	numberp	valuep;
	u_char	mode;
E 2
{
D 2
	union	Double{
		struct {
			long	word_first;
			long	word_last;
		} composite;
		double	dvalue;
	} reconstructed;
E 2
I 2
	int	regnumber = OC_REGEXT(mode);
E 2

D 2
	reconstructed.composite.word_first = word_first;
	reconstructed.composite.word_last = word_last;
	printf( "%f", reconstructed.dvalue);
E 2
I 2
	switch(OC_AMEXT(mode)){
	case OC_BDISP:
	case OC_DBDISP:
	case OC_WDISP:
	case OC_DWDISP:
	case OC_LDISP:
	case OC_DLDISP:
		if (regnumber == R_PC){
			/* PC offset addressing */
			valuep->num_ulong[0] += inkdot(incp);
		}
	}
#ifdef ADB
D 5
	psymoff(valuep->num_ulong[0], type, &insoutfmt[0]);
	if (regnumber != R_PC){		/* } */
E 5
I 5
	if (regnumber == R_PC)
		psymoff(valuep->num_ulong[0], type, &insoutfmt[0]);
	else {				/* } */
		printf(LPRMODE, valuep->num_ulong[0]);
		printf(insoutfmt);
E 5
D 6
#endif ADB
E 6
I 6
#endif /* ADB */
E 6
#ifdef SDB
	if(psymoff(valuep->num_ulong[0], regnumber, &insoutfmt[0])
	   && (regnumber != R_PC)){
D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6
		printf("(%s)", insregname(regnumber));
	}
	savevar((long)valuep->num_ulong[0]);
E 2
}
I 2
/*
 *	get a register name
 */
char *insregname(regnumber)
	int	regnumber;
{
	char	*r;
	r = regname[regnumber];
#ifdef SDB
	if (   (insoutfmt[0] == 'i')
	    && (regnumber >= 6)
	    && (regnumber <= 11)
	    && (adrtoregvar(regnumber, procp) != -1)) {
		r = sl_name;
	}
D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6
	return(r);
}
/*
 *	print out a short literal
 */
shortliteral(mode, optype)
	u_char	mode;
	u_char	optype;
{
	savevar((long)mode);
	switch(A_TYPEXT(optype)){
	case TYPF:
	case TYPD:
	case TYPG:
	case TYPH:
		printf("$%s", fltimm[mode]);
		break;
	default:
#ifdef ADB
		printf("$%r", mode);
D 6
#endif ADB
E 6
I 6
#endif /* ADB */
E 6
#ifdef SDB
		printf("$%d", mode);
D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6
		break;
	}
}
E 2

D 2
printquad(word_first, word_last)
	long	word_first;
	long	word_last;
E 2
I 2
pcimmediate(mode, optype)
	u_char	mode;
	u_char	optype;
E 2
{
D 2
	union Quad {
		char	quad_bytes[8];
		long	quad_long[2];
	} reconstructed;
E 2
I 2
	int	nbytes;

	printc('$');
D 3
	if (mode == OC_DAIREG){	/* PC absolute, always 4 bytes*/
E 3
I 3
	if (mode == OC_CONS(OC_DAIREG, R_PC)){	/* PC absolute, always 4 bytes*/
E 3
		dispaddress(snarfreloc(4), mode);
		return;
	}
	nbytes = ty_nbyte[A_TYPEXT(optype)];
	if (! ty_NORELOC[A_TYPEXT(optype)]){
		dispaddress(snarfreloc(nbytes), mode);
		return;
	}
	bignumprint(nbytes, optype);
}

bignumprint(nbytes, optype)
	int	nbytes;
	u_char	optype;
{
	numberp	valuep;
E 2
	int	leading_zero = 1;
D 2
	int	byteindex;
	int	nibbleindex;
	register	int	ch;
E 2
I 2
	REG	int	bindex;
	REG	int	nindex;
	REG	int	ch;
E 2

D 2
	reconstructed.quad_long[0] = word_first;
	reconstructed.quad_long[1] = word_last;
	for (byteindex = 7; byteindex >= 0; --byteindex){
		for (nibbleindex = 4; nibbleindex >= 0; nibbleindex -= 4){
			ch = (reconstructed.quad_bytes[byteindex]
				>> nibbleindex) & 0x0F;
			if ( ! (leading_zero &= (ch == 0) ) ){
				if (ch <= 0x09)
					printc(ch + '0');
				else
					printc(ch - 0x0A + 'a');
E 2
I 2
	valuep = snarf(nbytes);
	switch(A_TYPEXT(optype)){
	case TYPF:	
I 7
		if ((valuep->num_num.numFf_float.Ff_ushort[0] & 0xff80) == 0x8000) {
			printf("0f::"); goto qprint;
		}
E 7
		printf("0f%f", valuep->num_num.numFf_float.Ff_value);
		break;
	case TYPD:
I 7
		if ((valuep->num_num.numFd_float.Fd_ushort[0] & 0xff80) == 0x8000) {
			printf("0d::"); goto qprint;
		}
E 7
		printf("0d%f", valuep->num_num.numFd_float.Fd_value);
		break;
	case TYPG:
		printf("0g::"); goto qprint;
	case TYPH:
		printf("0h::"); goto qprint;
	case TYPQ:
	case TYPO:
	qprint:
		for (bindex = nbytes - 1; bindex >= 0; --bindex){
			for (nindex = 4; nindex >= 0; nindex -= 4){
				ch = (valuep->num_uchar[bindex] >> nindex);
				ch &= 0x0F;
				if ( ! (leading_zero &= (ch == 0) ) ){
					if (ch <= 0x09)
						printc(ch + '0');
					else
						printc(ch - 0x0A + 'a');
				}
E 2
			}
		}
I 2
		break;
E 2
	}
}
I 2
#ifdef SDB

L_INT inkdot(incr)
	int	incr;
{
	L_INT		newdot;

	newdot = dot + incr;
	return(newdot);
}

printc(c)
	char c;
{
	printf("%c", c);
}

psymoff(v, regnumber, fmt)
	L_INT	v;
	char	*fmt;
{
	struct	proct	*procp;
	REG	int diff;
	if (fmt[0] == 'i') {
		switch(regnumber){
		case 12:	/* parameter */
			if ((diff = adrtoparam((ADDR) v, adrtoprocp(dot)))
					!= -1) {
				printf("%s", sl_name);
				prdiff(diff);
				return(0);
			}
			break;
		case 13:	/* local */
			if ((diff = adrtolocal((ADDR) -v, adrtoprocp(dot))
					) != -1) {
				printf("%s", sl_name);
				prdiff(diff);
				return(0);
			}
			break;
		default:
			break;
		}
		if (v < firstdata) {
			if ((procp = adrtoprocp((ADDR) v)) != badproc) {
				prlnoff(procp, v);
				return(0);
			}
		} else {
			if ((diff = adrtoext((ADDR) v)) != -1) {
				printf("%s", sl_name);
				prdiff(diff);
				return(0);
			}
		}
	}
	prhex(v);
	return(1);
}

prdiff(diff)
{
	if (diff) {
		printf("+");
		prhex(diff);
	}
}

D 6
#endif SDB
E 6
I 6
#endif /* SDB */
E 6
E 2
E 1
