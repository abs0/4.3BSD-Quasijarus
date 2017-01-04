h15843
s 00046/00040/00279
d D 7.4 86/12/15 20:26:46 sam 4 3
c lint
e
s 00032/00023/00287
d D 7.3 86/11/23 13:36:00 sam 3 2
c move machine dependencies to ../machine/kdbparam.h
e
s 00001/00001/00309
d D 7.2 86/11/20 14:43:17 sam 2 1
c no more TRUE|FALSE
e
s 00310/00000/00000
d D 7.1 86/11/20 12:22:02 sam 1 0
c date and time created 86/11/20 12:22:02 by sam
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
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

#include "../kdb/defs.h"

char	*BADSYM;
char	*BADVAR;
char	*BADKET;
char	*BADSYN;
char	*NOCFN;
char	*NOADR;
char	*BADLOC;

ADDR	lastframe;
ADDR	savlastf;
ADDR	savframe;
ADDR	savpc;
ADDR	callpc;

char	*lp;
int	radix;
char	isymbol[1024];

char	lastc, peekc;

long	ditto;
long	expv;

I 4
static long
round(a,b)
	register long a, b;
{
	register long w;

	w = (a/b)*b;
	if (a!=w)
		w += b;
	return (w);
}

E 4
/* term | term dyadic expr |  */
expr(a)
{
	register rc;
	register long lhs;

D 4
	rdc(); lp--; rc=term(a);
E 4
I 4
	(void) rdc(); lp--; rc=term(a);
E 4

	while (rc) {
		lhs = expv;
		switch ((int)readchar()) {
		case '+':
D 4
			term(a|1); expv += lhs; break;
E 4
I 4
			(void) term(a|1); expv += lhs; break;
E 4
		case '-':
D 4
			term(a|1); expv = lhs - expv; break;
E 4
I 4
			(void) term(a|1); expv = lhs - expv; break;
E 4
		case '#':
D 4
			term(a|1); expv = round(lhs,expv); break;
E 4
I 4
			(void) term(a|1); expv = round(lhs,expv); break;
E 4
		case '*':
D 4
			term(a|1); expv *= lhs; break;
E 4
I 4
			(void) term(a|1); expv *= lhs; break;
E 4
		case '%':
D 4
			term(a|1); expv = lhs/expv; break;
E 4
I 4
			(void) term(a|1); expv = lhs/expv; break;
E 4
		case '&':
D 4
			term(a|1); expv &= lhs; break;
E 4
I 4
			(void) term(a|1); expv &= lhs; break;
E 4
		case '|':
D 4
			term(a|1); expv |= lhs; break;
E 4
I 4
			(void) term(a|1); expv |= lhs; break;
E 4
		case ')':
			if ((a&2)==0)
				error(BADKET);
		default:
			lp--;
			return (rc);
		}
	}
	return (rc);
}

/* item | monadic item | (expr) | */
static
term(a)
{

	switch ((int)readchar()) {
	case '*':
D 4
		term(a|1); expv=chkget(expv,DSP);
E 4
I 4
		(void) term(a|1); expv=chkget(expv,DSP);
E 4
		return(1);
	case '@':
D 4
		term(a|1); expv=chkget(expv,ISP);
E 4
I 4
		(void) term(a|1); expv=chkget(expv,ISP);
E 4
		return(1);
	case '-':
D 4
		term(a|1); expv = -expv;
E 4
I 4
		(void) term(a|1); expv = -expv;
E 4
		return(1);
	case '~':
D 4
		term(a|1); expv = ~expv;
E 4
I 4
		(void) term(a|1); expv = ~expv;
E 4
		return(1);
	case '#':
D 4
		term(a|1); expv = !expv;
E 4
I 4
		(void) term(a|1); expv = !expv;
E 4
		return(1);
	case '(':
D 4
		expr(2);
E 4
I 4
		(void) expr(2);
E 4
		if (*lp!=')')
			error(BADSYN);
		lp++;
		return(1);
	}
	lp--;
	return (item(a));
}

/* name [ . local ] | number | . | ^ | <var | <register | 'x | | */
static
item(a)
{
	register base, d, regptr;
	char savc;
	register long frame;
	register struct nlist *symp;

D 4
	readchar();
E 4
I 4
	(void) readchar();
E 4
	if (symchar(0)) {
		readsym();
		if (lastc=='.') {
			frame = pcb.pcb_fp; lastframe = 0;
D 3
			callpc= pcb.pcb_pc;
			while (errflg==0) {
			    savpc=callpc;
			    findsym(callpc,ISYM);
			    if (eqsym(cursym->n_un.n_name,isymbol,'~'))
				    break;
			    callpc=get(frame-8, DSP);
			    lastframe=frame;
			    frame=get(frame, DSP)&ALIGN;
			    if (frame==0)
				    error(NOCFN);
E 3
I 3
			callpc = pcb.pcb_pc;
			while (!errflg) {
				savpc = callpc;
D 4
				findsym(callpc,ISYM);
E 4
I 4
				(void) findsym((long)callpc,ISYM);
E 4
				if (eqsym(cursym->n_un.n_name,isymbol,'~'))
					break;
				callpc = getprevpc(frame);
				lastframe = frame;
				frame = getprevframe(frame);
				if (frame == NOFRAME)
					error(NOCFN);
E 3
			}
D 3
			savlastf=lastframe; savframe=frame;
E 3
I 3
			savlastf = lastframe; savframe = frame;
E 3
D 4
			readchar();
E 4
I 4
			(void) readchar();
E 4
			if (symchar(0))
				chkloc(expv=frame);
		} else if ((symp=lookup(isymbol))==0)
			error(BADSYM);
		else
			expv = symp->n_value;
		lp--;
D 3
	} else if (getnum())
		;
	else if (lastc=='.') {
E 3
I 3
		return (1);
	}
	if (getnum())
		return (1);
	switch (lastc) {
	case '.':
E 3
D 4
		readchar();
E 4
I 4
		(void) readchar();
E 4
		if (symchar(0)) {
			lastframe=savlastf; callpc=savpc;
D 4
			chkloc(savframe);
E 4
I 4
			chkloc((long)savframe);
E 4
		} else
			expv=dot;
		lp--;
D 3
	} else if (lastc=='"')
E 3
I 3
		break;
	case '"':
E 3
		expv=ditto;
D 3
	else if (lastc=='+')
E 3
I 3
		break;
	case '+':
E 3
		expv=inkdot(dotinc);
D 3
	else if (lastc=='^')
E 3
I 3
		break;
	case '^':
E 3
		expv=inkdot(-dotinc);
D 3
	else if (lastc=='<') {
E 3
I 3
		break;
	case '<':
E 3
		savc=rdc();
		if ((regptr=getreg(savc)) != -1)
			expv = *(int *)regptr;
		else if ((base=varchk(savc)) != -1)
			expv=var[base];
		else
			error(BADVAR);
D 3
	} else if (lastc=='\'') {
E 3
I 3
		break;
	case '\'':
E 3
		d=4; expv=0;
		while (quotchar()) {
		    if (d--) {
		         expv <<= 8;
			 expv |= lastc;
		    } else
			error(BADSYN);
		}
D 3
	} else if (a)
		error(NOADR);
	else {
E 3
I 3
		break;
	default:
		if (a)
			error(NOADR);
E 3
		lp--;
		return(0);
	}
	return (1);
}

/* service routines for expression reading */
static
getnum()
{
	register base,d,frpt;
	union { float r; long i;} real;

	if (!isdigit(lastc))
		return (0);
	if ((base = radix) < 0)
		base = -base;
	expv = 0;
	while (base>10 ? isxdigit(lastc) : isdigit(lastc)) {
		register m = MAXINT/base;

		if (expv>m)		/* avoid overflow */
			expv = (expv-m)*base+m*base;
		else
			expv *= base;
		if ((d=convdig(lastc))>=base || d<0)
			error(BADSYN);
D 4
		expv += d; readchar();
E 4
I 4
		expv += d; (void) readchar();
E 4
		if (expv==0) {
			if (lastc=='x' || lastc=='X') {
D 4
				 base=16; readchar();
E 4
I 4
				 base=16; (void) readchar();
E 4
			} else if (lastc=='t' || lastc=='T') {
D 4
				 base=10; readchar();
E 4
I 4
				 base=10; (void) readchar();
E 4
			} else if (lastc=='o' || lastc=='O') {
D 4
				 base=8; readchar();
E 4
I 4
				 base=8; (void) readchar();
E 4
			}
		}
	}
	if (lastc=='.' && (base==10 || expv==0)) {
		real.r=expv; frpt=0; base=10;
		while (isdigit(readchar())) {
			real.r *= base; frpt++;
			real.r += lastc-'0';
		}
		while (frpt--)
			real.r /= base;
		expv = real.i;
	}
	peekc=lastc;
	return (1);
}

static
readsym()
{
	register char *p;

	p = isymbol;
	do {
D 4
	    if (p < &isymbol[sizeof(isymbol)-1])
		    *p++ = lastc;
	    readchar();
E 4
I 4
		if (p < &isymbol[sizeof(isymbol)-1])
			*p++ = lastc;
		(void) readchar();
E 4
	} while (symchar(1));
	*p++ = 0;
}

static
convdig(c)
	char c;
{
	if (isdigit(c))
		return (c-'0');
	if (isxdigit(c))
		return (c-'a'+10);
	return (-1);
}

static
symchar(dig)
{

	if (lastc=='\\') {
D 4
		readchar();
E 4
I 4
		(void) readchar();
E 4
D 2
		return (TRUE);
E 2
I 2
		return (1);
E 2
	}
	return (isalpha(lastc) || lastc=='_' || dig && isdigit(lastc));
}

varchk(name)
	register name;
{
	if (isdigit(name))
		return (name-'0');
	if (isalpha(name))
		return ((name&037)-1+10);
	return (-1);
}

static
chkloc(frame)
	long frame;
{

	readsym();
	do {
		if (localsym(frame)==0)
			error(BADLOC);
		expv=localval;
	} while (!eqsym(cursym->n_un.n_name,isymbol,'~'));
}

eqsym(s1, s2, c)
	register char *s1, *s2;
{

	if (streq(s1,s2))
		return (1);
	if (*s1 == c && streq(s1+1, s2))
		return (1);
	return (0);
}

static
streq(s1, s2)
	char *s1, *s2;
{

	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return (1);
	return (0);
D 4
}

static
round(a,b)
	register long a, b;
{
	register long w;

	w = (a/b)*b;
	if (a!=w)
		w += b;
	return (w);
E 4
}
E 1
