h48345
s 00002/00001/00388
d D 4.3 88/04/24 15:17:20 bostic 4 3
c fix for ANSI C
e
s 00356/00468/00033
d D 4.2 84/05/05 21:50:42 mckusick 3 2
c fixes from Lou Salkind at NYU
e
s 00000/00000/00501
d D 4.1 82/05/12 11:13:48 rrh 2 1
c sync to release 4.1
e
s 00501/00000/00000
d D 1.1 82/05/12 11:03:16 rrh 1 0
c date and time created 82/05/12 11:03:16 by rrh
e
u
U
t
T
I 1
D 3
#
E 3
I 3
#ifndef	lint
E 3
static char sccsid[] = "	%M%	%I%	%E%	";
I 3
#endif

/* From Lou Salkind: compat/RCS/dofloat.c,v 1.2 84/01/31 13:33:53 */

E 3
/*
D 3
 *	Simulate pdp11 floating point for compatability mode programs.
 *	Quick and dirty with no big effort at speed since it takes so
 *	much overhead to get here in the first place.
 *	I make no claims on the completeness of this simulation.
 *	Art Wetzel 3/16/80
E 3
I 3
 * Partial PDP-11 floating-point simulator.  Always in double mode,
 * chop mode.  All arithmetic done in double-precision. Storing longs
 * into or taking longs from general registers doesn't work.
 * Overflow is never detected.
E 3
 */
D 3
#ifndef NOFPSIM
#ifdef DEBUG
E 3
I 3

E 3
#include <stdio.h>
D 3
#endif
E 3
#include "defs.h"
D 3
/* output codes */
#define	NONE	0
#define	SHORT	01
#define	LONG	02
#define	FLOAT	04
#define	DOUBLE	010
#define	OUTPUT	020
/* parts of fps */
#define	FD	0200
#define	FL	0100
#define	FN	010
#define	FZ	04
#define	FV	02
#define	FC	01
/* fis instructions */
#define	FADD	075000
#define	FSUB	075010
#define	FMUL	075020
#define	FDIV	075030
/* fpu instructions */
#define	ABSD	0170600
#define	ABSF	0170600
#define	ADDD	0172000
#define	ADDF	0172000
#define	CFCC	0170000
#define	CLRD	0170400
#define	CLRF	0170400
#define	CMPD	0173400
#define	CMPF	0173400
#define	DIVD	0174400
#define	DIVF	0174400
#define	LDCFD	0177400
#define	LDCFF	0177400
#define	LDCLD	0177000
#define	LDCLF	0177000
#define	LDCIF	0177000
#define	LDCID	0177000
#define	LDEXP	0176400
#define	LDD	0172400
#define	LDF	0172400
#define	LDFPS	0170100
#define	MODD	0171400
#define	MODF	0171400
#define	MULD	0171000
#define	MULF	0171000
#define	NEGD	0170700
#define	NEGF	0170700
#define	SETF	0170001
#define	SETD	0170011
#define	SETI	0170002
#define	SETL	0170012
#define	STCDF	0176000
#define	STCFD	0176000
#define	STCDL	0175400
#define	STCDI	0175400
#define	STCFL	0175400
#define	STCFI	0175400
#define	STEXP	0175000
#define	STD	0174000
#define	STF	0174000
#define	STFPS	0170200
#define	STST	0170300
#define	SUBD	0173000
#define	SUBF	0173000
#define	TSTD	0170500
#define	TSTF	0170500
union	alltypes	{
	double	d;
	float	f;
	long	l;
	short	s;
	unsigned short p[4];
};
/* static storage for floating registers */
static union	alltypes	fregs[6];
static union	alltypes	srcdst;
int	fps = FD|FL;
int	dbl = 0;
int	lng = 0;
#endif
dofloat(instr) unsigned int instr; {
#ifdef NOFPSIM
	return(-1);
#else
	register unsigned short *wptr;
	register unsigned int opcode, ac, mode, fac, adjust, output, ccset;
	unsigned short *locate();
	/* indicate what condition codes will be changed by op - assume none */
	ccset = 0;
	/* type of memory output - assume none */
	output = NONE;
	/* default adjust to type */
	if(dbl)
		adjust = DOUBLE;
	else
		adjust = FLOAT;
	/* chop up instruction to get relevent parts */
	opcode = instr & 0177700;
	fac = (instr>>6) & 03;
	mode = (instr>>3) & 07;
	ac = instr & 07;
	/* if the instruction uses a src/dst construct ptr and fetch */
	switch(opcode) {
	case	FADD:
	case	CFCC:
E 3
I 3

#define TRUE 1
#define FALSE 0

#define ABSD	0170600
#define ADDD	0172000
#define CFCC	0170000
#define CLRD	0170400
#define CMPD	0173400
#define DIVD	0174400
#define LDCFD	0177400
#define LDCLD	0177000
#define LDD	0172400
#define LDEXP	0176400
#define MODD	0171400
#define MULD	0171000
#define NEGD	0170700
#define SETD	0170011
#define SETI	0170002
#define SETL	0170012
#define STCDL	0175400
#define STCDF	0176000
#define STD	0174000
#define STEXP	0175000
#define SUBD	0173000
#define TSTD	0170500

static struct {
	unsigned fc :1;
	unsigned fv :1;
	unsigned fz :1;
	unsigned fn :1;
	unsigned fmm :1;
	unsigned ft :1;
	unsigned fl :1;
	unsigned fd :1;
D 4
} fps = FALSE;
E 4
I 4
} fps;
E 4

#define FZ fps.fz
#define FN fps.fn
#define FL fps.fl
#define FD fps.fd

#define LMODE FL
#define IMODE (!LMODE)

static double fregs[6];

dofloat(instr)
unsigned int instr;
{
	int mode, reg, ac;
	unsigned short * x, * resolve();
I 4
	long fliplong();
E 4
#define DOUBLE (*((double *)x))
#define FLOAT (*(float *)x)
#define LONG (*(long *)x)
#define SHORT (*(short *)x)
#define GETDOUBLE (x = resolve(mode, reg, 8, TRUE))
#define GETFLOAT (x = resolve(mode, reg, 4, TRUE))
#define GETLONG (x = resolve(mode, reg, 4, FALSE))
#define GETSHORT (x = resolve(mode, reg, 2, FALSE))
#define FREG fregs[ac]
	double temp;
	union {
		double d;
		short s;
	} bits;

	switch (instr & 0170000) {
	case 0170000:
E 3
		break;
	default:
D 3
		wptr = locate(mode, ac);
		/* special case for mode 0 */
		if(mode == 0) switch(opcode & 0177400) {
		/* special instructions to use cpu regs */
		case	LDEXP:
		case	STEXP:
			wptr = &regs[ac];
			break;
		case	STCDL:
			wptr = &regs[ac];
E 3
I 3
		fprintf(stderr, "Unrecognized instr in dofloat %0o\n", instr);
		return (-1);
	}

	switch (instr & 07000) {
	case 0:
		switch (instr & 0700) {
		case 0:
			switch (instr) {
			case CFCC:
				psl &= ~017;
				if (FN) {
					psl |= 010;
				}
				if (FZ) {
					psl |= 04;
				}
				return (0);
			case SETD:
				FD = TRUE;
				return (0);
			case SETI:
				FL = FALSE;
				return (0);
			case SETL:
				FL = TRUE;
				return (0);
			default:
				fprintf(stderr, "Unrecognized instr in dofloat %0o\n", instr);
				return (-1);
			}
E 3
		default:
			break;
		}
D 3
		if(dbl)
			srcdst.d = *(double *)wptr;
		else
			srcdst.f = *(float *)wptr;
		/* immediate fetches are 16 bits */
		if(ac == 7 && (mode == 2)) {
			srcdst.p[1] = 0;
			srcdst.p[2] = 0;
			srcdst.p[3] = 0;
E 3
I 3

		mode = (instr & 070) >> 3;
		reg = instr & 07;

		switch (instr & 0177700) {
		case ABSD:
			GETDOUBLE;
			if (DOUBLE < 0.0) {
				DOUBLE = -DOUBLE;
			}
			FZ = (DOUBLE == 0.0);
			FN = (DOUBLE < 0.0);
			return (0);
		case CLRD:
			GETDOUBLE;
			DOUBLE = 0.0;
			FZ = TRUE;
			FN = FALSE;
			return (0);
		case NEGD:
			GETDOUBLE;
			DOUBLE = -DOUBLE;
			FZ = (DOUBLE == 0.0);
			FN = (DOUBLE < 0.0);
			return (0);
		case TSTD:
			GETDOUBLE;
			FZ = (DOUBLE == 0.0);
			FN = (DOUBLE < 0.0);
			return (0);
		default:
			fprintf(stderr, "Unrecognized instr in dofloat %0o\n", instr);
			return (-1);
E 3
		}
I 3
	default:
E 3
		break;
	}
D 3
#ifdef	DEBUG
fprintf(stderr,"pc %o sp %o instr %o srcdst %o mode %o reg %o fac %o\n", pc-1,regs[6],instr,srcdst.s,mode,ac,fac);
#endif
	switch(opcode) {
	case	FADD:
		/* catches all fis instructions */
		/* last 3 bits are stack pointer register */
		ac = instr & 07;
		/* get pointer to stack words */
		wptr = (unsigned short *)regs[ac];
		/* getch floating value from stack */
		srcdst.f = *(float *)wptr;
		/* shorten stack */
		wptr += 2;
		/* do appropriate operation */
		switch(instr & 0177770) {
		case	FADD:
			srcdst.f += *(float *)wptr;
			break;
		case	FSUB:
			srcdst.f = *(float *)wptr - srcdst.f;
			break;
		case	FMUL:
			srcdst.f *= *(float *)wptr;
			break;
		case	FDIV:
			srcdst.f = *(float *)wptr / srcdst.f;
			break;
		default:
			return(-1);
E 3
I 3

	ac = (instr & 0300) >> 6;
	mode = (instr & 070) >> 3;
	reg = instr & 07;

	switch (instr & 0177400) {
	case ADDD:
		GETDOUBLE;
		FREG += DOUBLE;
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
	case CMPD:
		GETDOUBLE;
		FZ = (DOUBLE == FREG);
		FN = (DOUBLE < FREG);
		return (0);
	case DIVD:
		GETDOUBLE;
		FREG /= DOUBLE;
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
	case LDCFD:
		GETFLOAT;
		FREG = FLOAT;
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
	case LDCLD:
		if (IMODE) {
			GETSHORT;
			FREG = SHORT;
		} else {
			GETLONG;
			FREG = fliplong(LONG);
E 3
		}
D 3
		/* copy out result */
		*(float *)wptr = srcdst.f;
		/* set up condition codes */
		psl &= ~017;
		if(srcdst.f == 0.) psl |= FZ;
		if(srcdst.f < 0.) psl |= FN;
		/* adjust register to reflect stack change */
		regs[ac] = (unsigned short)(int)wptr;
		return(0);
	case	CFCC:
		switch(instr) {
		case	SETF:
			dbl = 0;
			break;
		case	SETD:
			dbl = 1;
			break;
		case	SETI:
			lng = 0;
			break;
		case	SETL:
			lng = 1;
			break;
		case	CFCC:
E 3
I 3
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
	case LDD:
		GETDOUBLE;
		FREG = DOUBLE;
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
	case LDEXP:
		GETSHORT;
		bits.d = FREG;
		bits.s &= ~077600;
		bits.s |= (SHORT + 0200) << 7;
		FREG = bits.d;
		FZ = (SHORT == 0);
		FN = (FREG < 0.0);
		return (0);
	case MODD:
		GETDOUBLE;
		temp = FREG * DOUBLE;
		fregs[ac|1] = (long) temp;
		FREG = temp - (long) temp;
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
	case MULD:
		GETDOUBLE;
		FREG = FREG * DOUBLE;
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
	case STCDF:
		GETFLOAT;
		FLOAT = FREG;
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
	case STCDL:
		if (IMODE) {
			GETSHORT;
			SHORT = FREG;
E 3
			psl &= ~017;
D 3
			psl |= (fps & 017);
#ifdef DEBUG
fprintf(stderr,"CFCC %o\n",psl);
#endif
			break;
		default:
			return(-1);
		}
		return(0);
	case	ABSD:
		if(srcdst.d < 0.0 ) srcdst.d = -srcdst.d;
		ccset = FZ;
		if(dbl) 
			output = DOUBLE;
		else
			output = FLOAT;
		break;
	case	CLRD:
		srcdst.d =0.0;
		ccset = FZ;
		if(dbl)
			output = DOUBLE;
		else
			output = FLOAT;
		break;
	case	LDFPS:
		adjust = SHORT;
		fps = srcdst.s;
		if(fps & FD)
			dbl = 1;
		else
			dbl = 0;
		if(fps & FL )
			lng = 1;
		else
			lng = 0;
		break;
	case	NEGD:
		srcdst.d = -srcdst.d;
		ccset = FZ|FN;
		if(dbl)
			output = DOUBLE;
		else
			output = FLOAT;
		break;
	case	STFPS:
		srcdst.s = fps;
		adjust = output = SHORT;
		break;
	case	STST:
		return(0);
		break;
	case	TSTD:
		ccset = FZ|FN;
		break;
	default:
		opcode = instr & 0177400;
		switch(opcode) {
		case	STD:
			srcdst.d = fregs[fac].d;
#ifdef DEBUG
fprintf(stderr,"STD %o\n",srcdst.s);
#endif
			if(dbl)
				output = DOUBLE;
			else
				output = FLOAT;
			break;
		case	LDD:
#ifdef DEBUG
fprintf(stderr,"LDD %o\n",srcdst.s);
#endif
			fregs[fac].d = srcdst.d;
			ccset = FZ|FN;
			break;
		case	ADDD:
			fregs[fac].d += srcdst.d;
			ccset = FZ|FN;
			break;
		case	SUBD:
			fregs[fac].d -= srcdst.d;
			ccset = FZ|FN;
			break;
		case	MULD:
			fregs[fac].d *= srcdst.d;
			ccset = FZ|FN;
			break;
		case	DIVD:
#ifdef DEBUG
fprintf(stderr,"DIVD %f by %f gives ",fregs[fac].d,srcdst.d);
#endif
			fregs[fac].d /= srcdst.d;
#ifdef DEBUG
fprintf(stderr,"-> %f\n",fregs[fac].d);
#endif
			ccset = FZ|FN;
			break;
		case	STCDF:
			adjust = output = FLOAT;
			ccset = FZ|FN;
			break;
		case	LDCFD:
			adjust = FLOAT;
			ccset = FZ|FN;
			break;
		case	LDCLD:
			if(lng) {
				adjust = LONG;
				srcdst.d = srcdst.l;
			} else {
				adjust = SHORT;
				srcdst.d = srcdst.s;
E 3
I 3
			if (SHORT == 0) {
				psl |= 04;
E 3
			}
D 3
			ccset = FZ|FN;
			break;
		case	CMPD:
			srcdst.d -= fregs[fac].d;
			ccset = FZ|FN;
			break;
		case	LDEXP:
			srcdst.d = 0.0;
			srcdst.s = *wptr;
			srcdst.s <<= 7;
			srcdst.s += 0200;
			adjust = SHORT;
			ccset = FZ|FN;
#ifdef	DEBUG
fprintf(stderr,"LDEXP %o gives %o\n",*wptr,srcdst.s);
#endif
			break;
		case	MODD:
			srcdst.d *= fregs[fac].d;
			fregs[fac].d = (double)(long)srcdst.d;
			if(~fac & 1) fregs[fac + 1].d = fregs[fac].d;
			srcdst.d -= fregs[fac].d;
			ccset = FN|FZ;
			fregs[fac].d = srcdst.d;
#ifdef DEBUG
fprintf(stderr,"MODD %o %o\n",fregs[fac].s,fregs[fac+1].s);
#endif
			break;
		case	STCDL:
			if(lng)
				adjust = output = LONG;
			else
				adjust = output = SHORT;
			if(mode == 0) output = SHORT;
			srcdst.l = fregs[fac].d;
#ifdef DEBUG
fprintf(stderr,"STCDL %o\n",srcdst.l);
#endif
			ccset = FZ|FN;
			break;
		case	STEXP:
#ifdef DEBUG
fprintf(stderr,"STEXP of %o gives ",srcdst.s);
#endif
			srcdst.s &= 077600;
			srcdst.s >>= 7;
			srcdst.s -= 0200;
			adjust = output = SHORT;
			ccset = FZ|FN;
#ifdef DEBUG
fprintf(stderr,"%o\n",srcdst.s);
#endif
			break;
		default:
			return(-1);
E 3
I 3
			if (SHORT < 0) {
				psl |= 010;
			}
		} else {
			GETLONG;
			LONG = fliplong((long) FREG);
			psl &= ~017;
			if (fliplong(LONG) == 0) {
				psl |= 04;
			}
			if (fliplong(LONG) < 0) {
				psl |= 010;
			}
E 3
		}
D 3
	}
	if(ccset & FZ) {
		fps &= ~FZ;
		if(srcdst.d == 0.0) fps |= FZ;
		if(!dbl && srcdst.f == 0.0) fps |= FZ;
	}
	if(ccset & FN) {
		fps &= ~FN;
		if(srcdst.f < 0.0) fps |= FN;
	}
	switch(instr & 0177400) {
	case	STCDL:
	case	STEXP:
E 3
I 3
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
	case STD:
		GETDOUBLE;
		DOUBLE = FREG;
		return (0);
	case STEXP:
		GETSHORT;
		bits.d = FREG;
		SHORT = ((bits.s & 077600) >> 7) - 0200;
		FZ = (SHORT == 0);
		FN = (SHORT < 0);
E 3
		psl &= ~017;
D 3
		psl |= (fps & 017);
		break;
E 3
I 3
		if (FZ) {
			psl |= 04;
		}
		if (FN) {
			psl |= 010;
		}
		return (0);
	case SUBD:
		GETDOUBLE;
		FREG -= DOUBLE;
		FZ = (FREG == 0.0);
		FN = (FREG < 0.0);
		return (0);
E 3
	default:
D 3
		break;
E 3
I 3
		fprintf(stderr, "Unrecognized instr in dofloat %0o\n", instr);
		return (-1);
E 3
	}
D 3
	switch(output) {
	case	NONE:
E 3
I 3
}

unsigned short *
resolve(mode, reg, bytes, floating)
{
	static unsigned short *x;
	static union {
		double d;
		unsigned short s;
	} bits;

	switch (mode) {
	case 0:
		if (floating) {
			if (bytes != 8) {
				fprintf(stderr, "Bad length in dofloat\n");
				return ((unsigned short *) -1);
			}
			x = (unsigned short *) &fregs[reg];
		} else {
			if (bytes != 2) {
				fprintf(stderr, "Bad length in dofloat\n");
				return ((unsigned short *) -1);
			}
			x = (unsigned short *) &regs[reg];
		}
E 3
		break;
D 3
	case	SHORT:
		*((short *)wptr) = srcdst.s;
		srcdst.d = 0.0;
E 3
I 3
	case 1:
		x = (unsigned short *) regs[reg];
E 3
		break;
D 3
	case	LONG:
		if(mode == 4) wptr--;
		*((long *)wptr) = longrev(srcdst.l);
E 3
I 3
	case 2:
		if (reg == 7 && floating) {
			bits.d = 0.0;
			bits.s = *(unsigned short *) regs[7];
			x = (unsigned short *) &bits;
			regs[7] += 2;
			pc = (unsigned short *) regs[7];
		} else {
			x = (unsigned short *) regs[reg];
			regs[reg] += bytes;
			if (reg == 7) {
				if (bytes != 2) {
					return((unsigned short *) -1);
				}
				pc = (unsigned short *) regs[7];
			}
		}
E 3
		break;
D 3
	case	FLOAT:
		if(mode == 4) wptr--;
		*((float *)wptr) = srcdst.f;
E 3
I 3
	case 3:
		x = (unsigned short *) regs[reg];
		x = (unsigned short *) *x;
		regs[reg] += 2;
		if (reg == 7) {
			pc = (unsigned short *) regs[7];
		}
E 3
		break;
D 3
	case	DOUBLE:
		if(mode == 4) wptr -= 3;
		*((double *)wptr) = srcdst.d;
E 3
I 3
	case 4:
		regs[reg] -= bytes;
		if (reg == 7) {
			pc = (unsigned short *) regs[7];
		}
		x = (unsigned short *) regs[reg];
E 3
		break;
D 3
	}
	switch(mode) {
	case	0:
	case	1:
E 3
I 3
	case 5:
		regs[reg] -= 2;
		if (reg == 7) {
			pc = (unsigned short *) regs[7];
		}
		x = (unsigned short *) regs[reg];
		x = (unsigned short *) *x;
E 3
		break;
D 3
	case	2:
		switch(adjust) {
		case	SHORT:
			regs[ac] += 2;
			break;
		case	LONG:
		case	FLOAT:
			regs[ac] += 4;
			break;
		case	DOUBLE:
			regs[ac] += 8;
			break;
		case	NONE:
			break;
E 3
I 3
	case 6:
		x = (unsigned short *) (unsigned short) (regs[reg] + *(pc++));
		if (reg == 7) {
			++x;
E 3
		}
D 3
		if(ac == 7) pc++;
E 3
		break;
D 3
	case	3:
		regs[ac] += 2;
		if(ac == 7) pc++;
		break;
	case	4:
		switch(adjust) {
		case	SHORT:
			regs[ac] -= 2;
			break;
		case	LONG:
		case	FLOAT:
			regs[ac] -= 4;
			break;
		case	DOUBLE:
			regs[ac] -= 8;
			break;
		case	NONE:
			break;
E 3
I 3
	case 7:
		x = (unsigned short *) (unsigned short) (regs[reg] + *(pc++));
		if (reg == 7) {
			++x;
E 3
		}
I 3
		x = (unsigned short *) *x;
E 3
		break;
D 3
	case	5:
		regs[ac] -= 2;
		break;
	case	6:
	case	7:
		pc++;
		break;
E 3
	}
D 3
	return(0);
#endif
E 3
I 3

	return (x);
E 3
}
D 3
#ifndef NOFPSIM
unsigned short *locate(mode, ac) {
	register unsigned short *wptr;
	switch(mode) {
	case	0:
		/* mode 0 normally implies fregs */
		wptr = (unsigned short *)&fregs[ac];
		break;
	case	1:
		break;
	case	2:
		wptr = (unsigned short *)(int)regs[ac];
		break;
	case	3:
		wptr = (unsigned short *)regs[ac];
		wptr = (unsigned short *)*wptr;
		break;
	case	4:
		wptr = (unsigned short *)regs[ac];
		wptr--;
		break;
	case	5:
		wptr = (unsigned short *)regs[ac];
		wptr--;
		wptr = (unsigned short *)*wptr;
		break;
	case	6:
		wptr = (unsigned short *)((regs[ac] + *pc) & 0177776);
		if(ac == 7) wptr++;
		break;
	case	7:
		wptr = (unsigned short *)((regs[ac] + *pc) & 0177776);
		if(ac == 7) wptr++;
		wptr = (unsigned short *)*wptr;
		break;
	}
	return(wptr);
E 3
I 3

long
fliplong(l)
long l;
{
	union {
		long l;
		short s[2];
	} bits[2];

	bits[0].l = l;
	bits[1].s[1] = bits[0].s[0];
	bits[1].s[0] = bits[0].s[1];
	return (bits[1].l);
E 3
}
D 3
#endif
E 3
E 1
