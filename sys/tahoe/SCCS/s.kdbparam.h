h09171
s 00007/00001/00057
d D 7.7 88/05/21 18:35:30 karels 7 6
c bring up to revision 7 for tahoe release
e
s 00004/00004/00054
d D 7.6 87/03/13 10:53:03 karels 6 5
c move defn's to header, move KERNBASE to machparam;
c don't delay escapes if we don't plan to recognize them
e
s 00007/00007/00051
d D 7.5 86/12/15 20:27:49 sam 5 4
c lint
e
s 00001/00001/00057
d D 7.4 86/11/23 13:30:06 sam 4 3
c typo
e
s 00017/00001/00041
d D 7.3 86/11/23 13:15:59 sam 3 2
c create macros for walking stack frames, checking address wrap, 
c setting and clearing single step; and more
e
s 00001/00000/00041
d D 7.2 86/11/20 14:45:18 sam 2 1
c add byte->long conversion macro
e
s 00041/00000/00000
d D 7.1 86/11/20 12:22:48 sam 1 0
c date and time created 86/11/20 12:22:48 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7

D 6
#include <sys/vm.h>

E 6
#define DBNAME "kdb\n"
#define LPRMODE "%R"
#define OFFMODE "+%R"

#define	MAXINT	0x7fffffff
#define	MAXSTOR (KERNBASE - ctob(UPAGES))

I 3
#define	ENTRYMASK	1			/* check for entry masks */
D 4
#define	ishiddenreg(p)	((p) <= reglist[8])
E 4
I 4
#define	ishiddenreg(p)	((p) <= &reglist[8])
E 4

E 3
#define BPT	0x30
#define KCALL	0xcf
#define CASEL	0xfc
#define TBIT	0x10

I 6
#define	KDB_IPL		0xf	/* highest priority software interrupt */
#define	setsoftkdb()	mtpr(SIRR, KDB_IPL)

E 6
I 3
#define	clrsstep()	(pcb.pcb_psl &= ~TBIT)
#define	setsstep()	(pcb.pcb_psl |= TBIT)

E 3
#define	SETBP(ins)	((BPT<<24) | ((ins) & 0xffffff))

D 3
#define ALIGN	-4
E 3
I 3
D 5
#define	getprevpc(fp)	get((fp)-8, DSP)	/* pc of caller */
#define	getprevframe(fp) (get((fp), DSP)&~3)	/* fp of caller */
#define	getnargs(fp)	(((get((fp)-4, DSP)&0xffff)-4)/4)
E 5
I 5
#define	getprevpc(fp)	get((off_t)(fp)-8, DSP)	/* pc of caller */
#define	getprevframe(fp) (get((off_t)(fp), DSP)&~3)	/* fp of caller */
#define	getnargs(fp)	(((get((off_t)(fp)-4, DSP)&0xffff)-4)/4)
E 5
#define	nextarg(ap)	((ap) + 4)		/* next argument in list */
#define	NOFRAME		0			/* fp at top of call stack */
E 3

I 3
D 5
#define	issignalpc(pc)	(MAXSTOR < (pc) && (pc) < MAXSTOR+ctob(UPAGES))
#define	getsignalpc(fp)	get((fp)+44, DSP)	/* pc of caller before signal */
E 5
I 5
#define	issignalpc(pc)	((unsigned)MAXSTOR < (pc) && (pc) < (unsigned)KERNBASE)
#define	getsignalpc(fp)	get((off_t)(fp)+44, DSP)/* pc of caller before signal */
E 5

E 3
#define leng(a)		((long)((unsigned)(a)))
#define shorten(a)	(((a) >> 16) & 0xffff)
D 5
#define	itol(a,b)	(((a) << 16) | ((b) & 0xffff))
E 5
I 5
#define	itol(a,b)	((long)(((a) << 16) | ((b) & 0xffff)))
E 5
#define	byte(a)		(((a) >> 24) & 0xff)
I 2
D 5
#define	btol(a)		((a) << 24)
E 5
I 5
#define	btol(a)		((long)((a) << 24))
E 5
E 2

I 3
/* check for address wrap around */
#define	addrwrap(oaddr,newaddr) \
	(((oaddr)^(newaddr)) >> 24)
E 3
/*
 * INSTACK tells whether its argument is a stack address.
 * INUDOT tells whether its argument is in the (extended) u. area.
 * These are used for consistency checking and dont have to be exact.
 *
 * INKERNEL tells whether its argument is a kernel space address.
 * KVTOPH trims a kernel virtal address back to its offset
 * in the kernel address space.
 */
#define	INSTACK(x)	(((int)(x)&0xf0000000) == 0xb0000000)
#define	INUDOT(x)	(((int)(x)&0xf0000000) == 0xb0000000)
#define	INKERNEL(x)	(((int)(x)&0xf0000000) == 0xc0000000)

D 6
#define	KERNBASE	0xc0000000
E 6
#define	KERNOFF		(KERNBASE + 0x800)	/* start of kernel's text */
D 6
#define	KVTOPH(x)	((x)&~ 0xc0000000)
E 6
I 6
/* #define	KVTOPH(x)	((x)&~ 0xc0000000) sometimes */
E 6
E 1
