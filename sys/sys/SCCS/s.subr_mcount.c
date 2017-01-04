h14563
s 00001/00001/00231
d D 7.5 88/01/19 15:04:42 mckusick 15 14
c must avoid asm label botch on vax too (from torek)
e
s 00003/00000/00229
d D 7.4 87/07/21 17:15:07 mckusick 14 13
c zero out malloc'ed memory before using it!
e
s 00007/00006/00222
d D 7.3 87/06/06 15:12:09 mckusick 13 12
c calloc => malloc
e
s 00080/00082/00148
d D 7.2 86/11/03 12:00:05 karels 12 11
c merge in tahoe support
e
s 00001/00001/00229
d D 7.1 86/06/05 00:06:40 mckusick 11 10
c 4.3BSD release version
e
s 00007/00001/00223
d D 6.5 85/06/08 14:41:16 mckusick 10 9
c Add copyright
e
s 00003/00003/00221
d D 6.4 84/08/29 20:21:26 bloom 9 8
c Change to includes.  no more ../h
e
s 00008/00003/00216
d D 6.3 84/08/12 12:27:57 mckusick 8 7
c use spl's rather than exclusion to single thread mcount() as this
c allows all interrupts to be accounted for.
e
s 00006/00006/00213
d D 6.2 84/07/28 12:05:44 mckusick 7 6
c allocate profiling buffers from special profiling map instead of Kernelmap
e
s 00000/00000/00219
d D 6.1 83/07/29 06:35:49 sam 6 5
c 4.2 distribution
e
s 00000/00003/00219
d D 4.5 83/07/01 02:18:59 sam 5 4
c purge #if sun's
e
s 00127/00069/00095
d D 4.4 83/01/15 16:52:22 mckusick 4 3
c new austere memory version; speed-ups for parametric calls
e
s 00007/00000/00157
d D 4.3 82/12/17 11:45:38 sam 3 2
c sun merge
e
s 00003/00003/00154
d D 4.2 82/11/13 22:51:04 sam 2 1
c merge of 4.1b and 4.1c
e
s 00157/00000/00000
d D 4.1 82/06/28 12:09:53 sam 1 0
c date and time created 82/06/28 12:09:53 by sam
e
u
U
t
T
I 1
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
/*
D 11
 * Copyright (c) 1982 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 10

I 4
D 12
/* last integrated from: gmon.c	4.10 (Berkeley) 1/14/83 */

E 12
E 4
#ifdef GPROF
D 4
#include "../h/crt0.h"
E 4
I 4
D 9
#include "../h/gprof.h"
E 4
#include "../h/param.h"
#include "../h/systm.h"
E 9
I 9
#include "gprof.h"
#include "param.h"
#include "systm.h"
I 13
#include "malloc.h"
E 13
E 9

/*
 * Froms is actually a bunch of unsigned shorts indexing tos
 */
D 4
int	profiling = 3;
u_short	*froms = 0;
struct	tostruct *tos = 0;
u_short	tolimit = 0;
E 4
I 4
D 12
int profiling = 3;
u_short *froms;
struct tostruct *tos = 0;
long tolimit = 0;
E 4
I 3
#ifdef vax
E 12
I 12
int	profiling = 3;
u_short	*froms;
struct	tostruct *tos = 0;
long	tolimit = 0;
#if defined(vax)
E 12
E 3
char	*s_lowpc = (char *)0x80000000;
I 3
#endif
D 5
#ifdef sun
char	*s_lowpc = (char *)0x4000;
#endif
E 5
E 3
D 4
extern	char etext;
char	*s_highpc = &etext;
E 4
I 4
D 12
extern char etext;
char *s_highpc = &etext;
E 12
I 12
#if defined(tahoe)
char	*s_lowpc = (char *)0xc0000000;
#endif
extern	char etext;
char	*s_highpc = &etext;
E 12
E 4
u_long	s_textsize = 0;
D 4
int	ssiz;
E 4
I 4
D 12
int ssiz;
E 12
I 12
int	ssiz;
E 12
E 4
u_short	*sbuf;
u_short	*kcount;

kmstartup()
{
D 4
	u_long	limit;
E 4
I 4
D 12
	u_long	fromssize, tossize;
E 12
I 12
	u_long fromssize, tossize;
E 12
E 4

I 4
	/*
D 12
	 *	round lowpc and highpc to multiples of the density we're using
	 *	so the rest of the scaling (here and in gprof) stays in ints.
E 12
I 12
	 * Round lowpc and highpc to multiples of the density we're using
	 * so the rest of the scaling (here and in gprof) stays in ints.
E 12
	 */
	s_lowpc = (char *)
D 12
	    ROUNDDOWN((unsigned)s_lowpc, HISTFRACTION*sizeof(HISTCOUNTER));
E 12
I 12
	    ROUNDDOWN((unsigned)s_lowpc, HISTFRACTION*sizeof (HISTCOUNTER));
E 12
	s_highpc = (char *)
D 12
	    ROUNDUP((unsigned)s_highpc, HISTFRACTION*sizeof(HISTCOUNTER));
E 12
I 12
	    ROUNDUP((unsigned)s_highpc, HISTFRACTION*sizeof (HISTCOUNTER));
E 12
E 4
	s_textsize = s_highpc - s_lowpc;
D 4
	ssiz = s_textsize + sizeof(struct phdr);
E 4
	printf("Profiling kernel, s_textsize=%d [%x..%x]\n",
		s_textsize, s_lowpc, s_highpc);
I 4
D 12
	ssiz = (s_textsize / HISTFRACTION) + sizeof(struct phdr);
E 12
I 12
	ssiz = (s_textsize / HISTFRACTION) + sizeof (struct phdr);
E 12
E 4
D 2
	sbuf = (u_short *)wmemall(vmemall, ssiz);
E 2
I 2
D 7
	sbuf = (u_short *)wmemall(memall, ssiz);
E 7
I 7
D 13
	sbuf = (u_short *)calloc(ssiz);
E 13
I 13
	sbuf = (u_short *)malloc(ssiz, M_GPROF, M_WAITOK);
E 13
E 7
E 2
	if (sbuf == 0) {
		printf("No space for monitor buffer(s)\n");
		return;
	}
I 14
	bzero(sbuf, ssiz);
E 14
D 12
	blkclr((caddr_t)sbuf, ssiz);
E 12
D 2
	froms = (u_short *)wmemall(vmemall, s_textsize);
E 2
I 2
D 4
	froms = (u_short *)wmemall(memall, s_textsize);
E 4
I 4
	fromssize = s_textsize / HASHFRACTION;
D 7
	froms = (u_short *)wmemall(memall, fromssize);
E 7
I 7
D 13
	froms = (u_short *)calloc(fromssize);
E 13
I 13
	froms = (u_short *)malloc(fromssize, M_GPROF, M_WAITOK);
E 13
E 7
E 4
E 2
	if (froms == 0) {
		printf("No space for monitor buffer(s)\n");
D 7
		wmemfree(sbuf, ssiz);
E 7
I 7
D 13
		cfreemem(sbuf, ssiz);
E 13
I 13
		free(sbuf, M_GPROF);
E 13
E 7
		sbuf = 0;
		return;
	}
I 14
	bzero(froms, fromsize);
E 14
D 4
	blkclr((caddr_t)froms, s_textsize);
D 2
	tos = (struct tostruct *)wmemall(vmemall, s_textsize);
E 2
I 2
	tos = (struct tostruct *)wmemall(memall, s_textsize);
E 4
I 4
D 12
	blkclr((caddr_t)froms, fromssize);
E 12
	tolimit = s_textsize * ARCDENSITY / 100;
D 12
	if (tolimit < MINARCS) {
E 12
I 12
	if (tolimit < MINARCS)
E 12
		tolimit = MINARCS;
D 12
	} else if (tolimit > 65534) {
		tolimit = 65534;
	}
	tossize = tolimit * sizeof(struct tostruct);
E 12
I 12
	else if (tolimit > (0xffff - 1))
		tolimit = 0xffff - 1;
	tossize = tolimit * sizeof (struct tostruct);
E 12
D 7
	tos = (struct tostruct *)wmemall(memall, tossize);
E 7
I 7
D 13
	tos = (struct tostruct *)calloc(tossize);
E 13
I 13
	tos = (struct tostruct *)malloc(tossize, M_GPROF, M_WAITOK);
E 13
E 7
E 4
E 2
	if (tos == 0) {
		printf("No space for monitor buffer(s)\n");
D 7
		wmemfree(sbuf, ssiz);
E 7
I 7
D 12
		cfreemem(sbuf, ssiz);
E 7
		sbuf = 0;
D 4
		wmemfree(froms, s_textsize);
E 4
I 4
D 7
		wmemfree(froms, fromssize);
E 7
I 7
		cfreemem(froms, fromssize);
E 7
E 4
		froms = 0;
E 12
I 12
D 13
		cfreemem(sbuf, ssiz), sbuf = 0;
		cfreemem(froms, fromssize), froms = 0;
E 13
I 13
		free(sbuf, M_GPROF), sbuf = 0;
		free(froms, M_GPROF), froms = 0;
E 13
E 12
		return;
	}
I 14
	bzero(tos, tossize);
E 14
D 4
	blkclr((caddr_t)tos, s_textsize);
E 4
I 4
D 12
	blkclr((caddr_t)tos, tossize);
E 12
E 4
	tos[0].link = 0;
D 4
	limit = s_textsize / sizeof(struct tostruct);
	/*
	 * Tolimit is what mcount checks to see if
	 * all the data structures are ready!!!
	 * Make sure it won't overflow.
	 */
	tolimit = limit > 65534 ? 65534 : limit;
E 4
	((struct phdr *)sbuf)->lpc = s_lowpc;
	((struct phdr *)sbuf)->hpc = s_highpc;
	((struct phdr *)sbuf)->ncnt = ssiz;
D 12
	kcount = (u_short *)(((int)sbuf) + sizeof(struct phdr));
E 12
I 12
	kcount = (u_short *)(((int)sbuf) + sizeof (struct phdr));
E 12
#ifdef notdef
I 4
	/*
D 12
	 *	profiling is what mcount checks to see if
	 *	all the data structures are ready!!!
E 12
I 12
	 * Profiling is what mcount checks to see if
	 * all the data structures are ready!!!
E 12
	 */
E 4
	profiling = 0;		/* patch by hand when you're ready */
#endif
}

I 3
D 12
#ifdef vax
E 12
E 3
/*
D 12
 * This routine is massaged so that it may be jsb'ed to
E 12
I 12
 * This routine is massaged so that it may be jsb'ed to on vax.
E 12
 */
D 4
asm("#define _mcount mcount");
E 4
I 4
asm(".text");
asm("#the beginning of mcount()");
asm(".data");
E 4
mcount()
{
D 4
	register char *selfpc;		/* r11 */
	register u_short *frompcindex;	/* r10 */
	register struct tostruct *top;	/* r9 */
E 4
I 4
D 12
	register char			*selfpc;	/* r11 => r5 */
	register unsigned short		*frompcindex;	/* r10 => r4 */
	register struct tostruct	*top;		/* r9  => r3 */
	register struct tostruct	*prevtop;	/* r8  => r2 */
	register long			toindex;	/* r7  => r1 */
E 12
I 12
	register char *selfpc;			/* r11 => r5 */
	register u_short *frompcindex;		/* r10 => r4 */
	register struct tostruct *top;		/* r9  => r3 */
	register struct tostruct *prevtop;	/* r8  => r2 */
	register long toindex;			/* r7  => r1 */
E 12
I 8
	static int s;
E 8
E 4

I 12
	asm("	.text");		/* make sure we're in text space */
	/*
	 * Check that we are profiling.
	 */
	if (profiling)
		goto out;
	/*
	 * Find the return address for mcount,
	 * and the return address for mcount's caller.
	 */
E 12
D 4
	asm("	forgot to run ex script on gcrt0.s");
	asm("#define r11 r5");
	asm("#define r10 r4");
	asm("#define r9 r3");
E 4
#ifdef lint
D 4
	selfpc = (char *) 0;
E 4
I 4
	selfpc = (char *)0;
E 4
	frompcindex = 0;
D 12
#else not lint
	/*
D 4
	 * Find the return address for mcount,
	 * and the return address for mcount's caller.
E 4
I 4
	 *	find the return address for mcount,
	 *	and the return address for mcount's caller.
E 4
	 */
I 4
	asm("	.text");		/* make sure we're in text space */
E 12
I 12
#else
I 15
	;				/* avoid label botch */
E 15
#if defined(vax)
E 12
E 4
	asm("	movl (sp), r11");	/* selfpc = ... (jsb frame) */
	asm("	movl 16(fp), r10");	/* frompcindex =     (calls frame) */
D 12
#endif not lint
E 12
I 12
#endif
#if defined(tahoe)
D 15
	;				/* avoid label botch */
E 15
	asm("	movl -8(fp),r12");	/* selfpc = callf frame */
	asm("	movl (fp),r11");
	asm("	movl -8(r11),r11");	/* frompcindex = 1 callf frame back */
#endif
#endif
E 12
	/*
D 4
	 * Check that we are profiling
	 * and that we aren't recursively invoked.
E 4
I 4
D 12
	 *	check that we are profiling
E 12
I 12
	 * Insure that we cannot be recursively invoked.
	 * this requires that splhigh() and splx() below
	 * do NOT call mcount!
E 12
D 8
	 *	and that we aren't recursively invoked.
E 8
E 4
	 */
D 4
	if (tolimit == 0)
E 4
I 4
D 12
	if (profiling) {
E 4
		goto out;
D 4
	if (profiling)
		goto out;
E 4
I 4
	}
E 4
D 8
	profiling++;
E 8
	/*
I 8
	 *	insure that we cannot be recursively invoked.
	 *	this requires that splhigh() and splx() below
	 *	do NOT call mcount!
	 */
E 12
	s = splhigh();
	/*
E 8
D 4
	 * Check that frompcindex is a reasonable pc value.
	 * For example:	signal catchers get called from the stack,
	 * 		not from text space.  too bad.
E 4
I 4
D 12
	 *	check that frompcindex is a reasonable pc value.
	 *	for example:	signal catchers get called from the stack,
	 *			not from text space.  too bad.
E 12
I 12
	 * Check that frompcindex is a reasonable pc value.
	 * For example:	signal catchers get called from the stack,
	 *	not from text space.  too bad.
E 12
E 4
	 */
D 4
	frompcindex = (u_short *)((long)frompcindex - (long)s_lowpc);
	if ((u_long)frompcindex > s_textsize)
E 4
I 4
D 12
	frompcindex = (unsigned short *)((long)frompcindex - (long)s_lowpc);
	if ((unsigned long)frompcindex > s_textsize) {
E 12
I 12
	frompcindex = (u_short *)((long)frompcindex - (long)s_lowpc);
	if ((u_long)frompcindex > s_textsize)
E 12
E 4
		goto done;
D 4
	frompcindex = &froms[((long)frompcindex) >> 1];
	if (*frompcindex != 0)
		top = &tos[*frompcindex];
	else {
		*frompcindex = ++tos[0].link;
		if (*frompcindex >= tolimit)
E 4
I 4
D 12
	}
E 12
	frompcindex =
D 12
	    &froms[((long)frompcindex) / (HASHFRACTION * sizeof(*froms))];
E 12
I 12
	    &froms[((long)frompcindex) / (HASHFRACTION * sizeof (*froms))];
E 12
	toindex = *frompcindex;
	if (toindex == 0) {
		/*
D 12
		 *	first time traversing this arc
E 12
I 12
		 * First time traversing this arc
E 12
		 */
		toindex = ++tos[0].link;
D 12
		if (toindex >= tolimit) {
E 12
I 12
		if (toindex >= tolimit)
E 12
E 4
			goto overflow;
D 4
		top = &tos[*frompcindex];
E 4
I 4
D 12
		}
E 12
		*frompcindex = toindex;
		top = &tos[toindex];
E 4
		top->selfpc = selfpc;
D 4
		top->count = 0;
E 4
I 4
		top->count = 1;
E 4
		top->link = 0;
I 4
		goto done;
E 4
	}
D 4
	for (; /* break */; top = &tos[top->link]) {
E 4
I 4
	top = &tos[toindex];
	if (top->selfpc == selfpc) {
		/*
D 12
		 *	arc at front of chain; usual case.
E 12
I 12
		 * Arc at front of chain; usual case.
E 12
		 */
		top->count++;
		goto done;
	}
	/*
D 12
	 *	have to go looking down chain for it.
	 *	top points to what we are looking at,
	 *	prevtop points to previous top.
	 *	we know it is not at the head of the chain.
E 12
I 12
	 * Have to go looking down chain for it.
	 * Top points to what we are looking at,
	 * prevtop points to previous top.
	 * We know it is not at the head of the chain.
E 12
	 */
	for (; /* goto done */; ) {
		if (top->link == 0) {
			/*
D 12
			 *	top is end of the chain and none of the chain
			 *	had top->selfpc == selfpc.
			 *	so we allocate a new tostruct
			 *	and link it to the head of the chain.
E 12
I 12
			 * Top is end of the chain and none of the chain
			 * had top->selfpc == selfpc.
			 * So we allocate a new tostruct
			 * and link it to the head of the chain.
E 12
			 */
			toindex = ++tos[0].link;
D 12
			if (toindex >= tolimit) {
E 12
I 12
			if (toindex >= tolimit)
E 12
				goto overflow;
D 12
			}
E 12
			top = &tos[toindex];
			top->selfpc = selfpc;
			top->count = 1;
			top->link = *frompcindex;
			*frompcindex = toindex;
			goto done;
		}
		/*
D 12
		 *	otherwise, check the next arc on the chain.
E 12
I 12
		 * Otherwise, check the next arc on the chain.
E 12
		 */
		prevtop = top;
		top = &tos[top->link];
E 4
		if (top->selfpc == selfpc) {
I 4
			/*
D 12
			 *	there it is.
			 *	increment its count
			 *	move it to the head of the chain.
E 12
I 12
			 * There it is, increment its count and
			 * move it to the head of the chain.
E 12
			 */
E 4
			top->count++;
D 4
			break;
E 4
I 4
			toindex = prevtop->link;
			prevtop->link = top->link;
			top->link = *frompcindex;
			*frompcindex = toindex;
			goto done;
E 4
		}
D 4
		if (top->link != 0)
			continue;
		top->link = ++tos[0].link;
		if (top->link >= tolimit)
			goto overflow;
		top = &tos[top->link];
		top->selfpc = selfpc;
		top->count = 1;
		top->link = 0;
		break;
E 4
I 4

E 4
	}
done:
D 8
	profiling--;
E 8
I 8
	splx(s);
E 8
	/* and fall through */
out:
I 12
#if defined(vax)
E 12
	asm("	rsb");
D 4
	asm("#undef r11");
	asm("#undef r10");
	asm("#undef r9");
	asm("#undef _mcount");
E 4
D 12

E 12
I 12
#endif
	return;
E 12
overflow:
D 4
	tolimit = 0;
E 4
I 4
	profiling = 3;
E 4
	printf("mcount: tos overflow\n");
	goto out;
}
I 3
D 4
#endif
E 4
I 4
asm(".text");
asm("#the end of mcount()");
asm(".data");
D 12
#endif vax
E 4
E 3
#endif GPROF
E 12
I 12
#endif
E 12
E 1
