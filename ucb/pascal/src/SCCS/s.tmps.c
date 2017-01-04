h01865
s 00019/00006/00225
d D 5.2 86/11/12 10:17:50 mckusick 17 16
c add CCI (tahoe) support
e
s 00007/00003/00224
d D 5.1 85/06/05 15:01:39 dist 16 15
c Add copyright
e
s 00000/00000/00227
d D 2.1 84/02/08 20:47:59 aoki 15 14
c synchronize to version 2
e
s 00000/00001/00227
d D 1.13 84/02/04 20:10:37 mckusick 14 12
i 13
c merge lint by thien
e
s 00010/00006/00170
d D 1.9.1.1 84/02/04 20:08:21 mckusick 13 9
c lint (by thien)
e
s 00002/00000/00221
d D 1.12 83/09/09 13:16:35 peter 12 11
c if with pointer doesn't get allocated to register, 
c explicitly align it like a pointer, since align() can't handle nl+TPTR.
e
s 00001/00002/00220
d D 1.11 83/09/09 12:29:03 peter 11 10
c bug left from putting register variables in for the mc68000.
e
s 00057/00011/00165
d D 1.10 83/09/05 18:52:53 peter 10 9
c allocate temporaries to registers in the mc68000.
e
s 00008/00001/00168
d D 1.9 83/04/06 22:01:17 peter 9 8
c if no type is given, guess that the temporary has to be stack
c aligned (e.g. for formal procedure descriptor save areas!).
e
s 00098/00045/00071
d D 1.8 83/02/28 17:18:06 peter 8 7
c clean up temporary allocation, moving everything relevant to
c tmps.c and (new) tmps.h.  correctly emit LBRAC lines.  allocate registers
c from high to low.  put in data structures for multiple types of registers.
e
s 00009/00008/00107
d D 1.7 83/02/01 20:20:55 peter 7 6
c change the #ifdefs from names from whoami.h to pre-defines from /lib/cpp.
e
s 00002/00001/00113
d D 1.6 81/07/23 13:52:32 mckusic 6 5
c align temporaries
e
s 00016/00012/00098
d D 1.5 81/06/01 15:41:03 peter 5 4
c add storage classes to namelist, and use them.
e
s 00001/00001/00109
d D 1.4 81/04/21 15:02:02 peter 4 3
c fix register allocation, even stack allocations
e
s 00004/00000/00106
d D 1.3 81/03/16 22:59:27 mckusic 3 2
c ifdef out PC part
e
s 00075/00013/00031
d D 1.2 81/03/16 18:13:14 mckusic 2 1
c add temporary register allocation
e
s 00044/00000/00000
d D 1.1 81/03/11 23:30:58 mckusick 1 0
c date and time created 81/03/11 23:30:58 by mckusick
e
u
U
f b 
t
T
I 1
D 16
/* Copyright (c) 1979 Regents of the University of California */
E 16
I 16
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 16

I 13
#ifndef lint
E 13
D 16
static char sccsid[] = "%Z%%M% %I% %G%";
I 13
#endif
E 16
I 16
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 16
E 13

#include "whoami.h"
#include "0.h"
I 7
#include "objfmt.h"
E 7
I 2
#ifdef PC
#   include "pc.h"
#endif PC
I 9
#include "align.h"
E 9
I 8
#include "tmps.h"
E 8
E 2

/*
I 2
 * This routine defines the register allocation strategy
 * All temporaries are allocated here, and this routines decides
 * where they are to be put.
 */
I 3
#ifdef PC
I 8
    /*
D 10
     *	registers are allocated from highreg towards lowreg.
     *	registers are of size regsize.
     *	stack variables are allocated on a downward growing stack.
E 10
I 10
     *	register temporaries
     *	- are allocated from highreg towards lowreg.
     *	- are of size regsize.
     *	- register numbers from the various register types are mapped to 
     *	  integer register numbers using the offsets.  (cf. pcc/mac2defs)
     *
     *	stack temporaries
     *	- are allocated on a downward growing stack.
E 10
     */

E 8
E 3
D 7
#ifdef VAX
E 7
I 7
#ifdef vax
E 7
D 8
#    define MAXREGS 6
D 5
#    define REGSIZ 4
E 5
I 5
#    define MINREGSIZE 4
#    define MAXREGSIZE 4
E 5
#    define FIRSTREG 6
E 8
I 8
    /*
     *	first pass register declaration constants
     */
D 10
#   define	LONGREGTYPE	0
E 10
struct	regtype {
    long	lowreg;
    long	highreg;
    long	regsize;
} regtypes[NUMREGTYPES] = {
D 10
	{ 6, 11, 4 },
E 10
I 10
	{ 6, 11, 4 },		/* r6..r11 */
E 10
};
E 8
D 7
#else
#ifdef PDP11
E 7
I 7
#endif vax
D 8
#ifdef pdp11
E 7
#    define MAXREGS 3
D 5
#    define REGSIZ 2
E 5
I 5
#    define MINREGSIZE 2
#    define MAXREGSIZE 2
E 5
#    define FIRSTREG 2
D 7
#else
E 7
I 7
#endif pdp11
#if (!(vax || pdp11))
E 7
#    define MAXREGS 0
D 5
#    define REGSIZ 0
E 5
I 5
#    define MINREGSIZE 0
#    define MAXREGSIZE 0
E 5
#    define FIRSTREG 0
D 7
#endif PDP11
#endif VAX
E 7
I 7
#endif
E 8
I 8

I 17
#ifdef tahoe
    /*
     *	first pass register declaration constants
     */
struct	regtype {
    long	lowreg;
    long	highreg;
    long	regsize;
} regtypes[NUMREGTYPES] = {
	{ 6, 12, 4 },		/* r6..r12 */
};
#endif tahoe

E 17
#ifdef mc68000
    /*
     *	first pass register declaration constants
     */
D 10
#   define	DATAREGTYPE	0
#   define	ADDRREGTYPE	1
E 10
struct	regtype {
    long	lowreg;
    long	highreg;
    long	regsize;
} regtypes[NUMREGTYPES] = {
D 10
	{ 2, 7, 0 },		/* off for now */
	{ 2, 5, 0 },		/* off for now */
E 10
I 10
	{ 2, 7, 4 },		/* d2..d7 */
	{ 2, 5, 4 },		/* a2..a5 */
E 10
};
#endif mc68000
E 8
E 7
I 3
#endif PC
E 3

I 8
tmpinit(cbn)
	int	cbn;
{
	struct om	*sizesp = &sizes[cbn];
I 13
#	ifdef PC
E 13
	int	i;
I 13
#	endif PC
E 13

	sizesp->om_max = -DPOFF1;
	sizesp->curtmps.om_off = -DPOFF1;
#	ifdef PC
		for (i = 0; i < NUMREGTYPES; i++) {
			sizesp->low_water[i] = regtypes[i].highreg + 1;
			sizesp->curtmps.next_avail[i] = regtypes[i].highreg;
		}
#	endif PC
}

E 8
/*
E 2
 * allocate runtime temporary variables
 */
I 13
/*ARGSUSED*/
E 13
D 5
long
E 5
I 5
struct nl *
E 5
D 2
tmpalloc(size, type, loc)
E 2
I 2
tmpalloc(size, type, mode)
E 2
	long size;
	struct nl *type;
D 2
	int loc;
E 2
I 2
	int mode;
E 2
{
D 2
	long offset;
E 2
I 2
D 8
	register struct om *op = &sizes[ cbn ];
	register int offset;
E 8
I 8
	register struct om	*op = &sizes[ cbn ];
	register int		offset;
E 8
I 5
	register struct nl	*nlp;
I 9
	long			alignment;
E 9
E 5
E 2

D 2
	offset = sizes[ cbn ].curtmps.om_off -= size;
	if ( offset < sizes[ cbn ].om_max ) {
	    sizes[ cbn ].om_max = offset;
E 2
I 2
#	ifdef PC
D 5
	    if (mode == REGOK && size <= REGSIZ &&
E 5
I 5
D 8
	    if (mode == REGOK && size >= MINREGSIZE && size <= MAXREGSIZE &&
E 5
		op->curtmps.reg_off < MAXREGS) {
		    offset = op->curtmps.reg_off++;
		    if ( offset > op->reg_max ) {
			    op->reg_max = offset;
		    }
D 5
		    /*
		     * the register number is encoded as an odd negative number
		     * which can never appear as an address.
		     */
		    return -(((offset + FIRSTREG) << 1) + 1);
E 5
I 5
		    nlp = defnl( 0 , VAR , type , offset + FIRSTREG );
		    nlp -> extra_flags = NLOCAL | NREGVAR;
		    return nlp;
E 5
	    }
E 8
I 8
D 17
#	    ifdef vax
E 17
I 17
#	    if defined(vax) || defined(tahoe)
E 17
		if (  mode == REGOK
		   && size == regtypes[REG_GENERAL].regsize
		   && op->curtmps.next_avail[REG_GENERAL]
			    >= regtypes[REG_GENERAL].lowreg) {
			offset = op->curtmps.next_avail[REG_GENERAL]--;
			if (offset < op->low_water[REG_GENERAL]) {
				op->low_water[REG_GENERAL] = offset;
			}
D 10
D 13
			nlp = defnl( 0 , VAR , type , offset );
E 13
I 13
			nlp = defnl( (char *) 0 , VAR , type , offset );
E 13
E 10
I 10
D 11
			nlp = defnl(0, VAR, type,
				offset + regtypes[REG_GENERAL].regno_offset );
E 11
I 11
D 14
			nlp = defnl(0, VAR, type, offset );
E 14
E 11
E 10
			nlp -> extra_flags = NLOCAL | NREGVAR;
			putlbracket(ftnno, op);
			return nlp;
		}
D 17
#	    endif vax
E 17
I 17
#	    endif vax || tahoe
E 17
I 10
#	    ifdef mc68000
		if (  mode == REGOK
		   && type != nl + TPTR
		   && size == regtypes[REG_DATA].regsize
		   && op->curtmps.next_avail[REG_DATA]
			    >= regtypes[REG_DATA].lowreg) {
			offset = op->curtmps.next_avail[REG_DATA]--;
			if (offset < op->low_water[REG_DATA]) {
				op->low_water[REG_DATA] = offset;
			}
			nlp = defnl(0, VAR, type, offset + DATA_REG_OFFSET );
			nlp -> extra_flags = NLOCAL | NREGVAR;
			putlbracket(ftnno, op);
			return nlp;
		}
		if (  mode == REGOK
		   && type == nl + TPTR
		   && size == regtypes[REG_ADDR].regsize
		   && op->curtmps.next_avail[REG_ADDR]
			    >= regtypes[REG_ADDR].lowreg) {
			offset = op->curtmps.next_avail[REG_ADDR]--;
			if (offset < op->low_water[REG_ADDR]) {
				op->low_water[REG_ADDR] = offset;
			}
			nlp = defnl(0, VAR, type, offset + ADDR_REG_OFFSET );
			nlp -> extra_flags = NLOCAL | NREGVAR;
			putlbracket(ftnno, op);
			return nlp;
		}
#	    endif mc68000
E 10
E 8
#	endif PC
I 9
	if (type == NIL) {
	    alignment = A_STACK;
I 12
	} else if (type == nl+TPTR) {
	    alignment = A_POINT;
E 12
	} else {
	    alignment = align(type);
	}
E 9
D 4
	offset = op->curtmps.om_off -= size;
E 4
I 4
D 6
	offset = op->curtmps.om_off -= leven( size );
E 6
I 6
D 8
        offset = op->curtmps.om_off =
E 8
I 8
        op->curtmps.om_off =
E 8
D 9
	    roundup((int)(op->curtmps.om_off - size), (long)align(type));
E 9
I 9
	    roundup((int)(op->curtmps.om_off - size), alignment);
E 9
I 8
	offset = op->curtmps.om_off;
E 8
E 6
E 4
	if ( offset < op->om_max ) {
	        op->om_max = offset;
E 2
	}
I 5
D 13
	nlp = defnl( 0 , VAR , type , offset );
E 13
I 13
	nlp = defnl( (char *) 0 , VAR , type , offset );
E 13
E 5
#	ifdef PC
I 5
	    nlp -> extra_flags = NLOCAL;
E 5
D 8
	    putlbracket( ftnno , -offset );
E 8
I 8
	    putlbracket(ftnno, op);
E 8
#	endif PC
D 5
	return offset;
E 5
I 5
	return nlp;
E 5
}
D 2

E 2
I 2
D 8

E 8
I 8

E 8
E 2
/*
 * deallocate runtime temporary variables
 */
I 13
/*ARGSUSED*/
E 13
tmpfree(restore)
D 2
	struct tmps *restore;
E 2
I 2
D 8
	register struct tmps *restore;
E 8
I 8
    register struct tmps	*restore;
E 8
E 2
{
I 13
#   ifdef PC
E 13
D 2
	long offset;
E 2
I 2
D 8
	register struct om *op = &sizes[ cbn ];
E 8
I 8
    register struct om		*op = &sizes[ cbn ];
    bool			change = FALSE;
E 8
E 2

D 2
	offset = restore->om_off;
	if (offset > sizes[cbn].curtmps.om_off) {
		sizes[cbn].curtmps.om_off = offset;
E 2
I 2
D 8
#	ifdef PC
	    if (restore->reg_off < op->curtmps.reg_off) {
		    op->curtmps.reg_off = restore->reg_off;
E 8
I 8
D 13
#   ifdef PC
E 13
D 10
	    /* i think this never gives back storage!	... peter */
E 10
D 17
#	ifdef vax
E 17
I 17
#	if defined(vax) || defined(tahoe)
E 17
	    if (restore->next_avail[REG_GENERAL]
		> op->curtmps.next_avail[REG_GENERAL]) {
		    op->curtmps.next_avail[REG_GENERAL]
			= restore->next_avail[REG_GENERAL];
		    change = TRUE;
E 8
	    }
D 8
#	endif PC
	if (restore->om_off > op->curtmps.om_off) {
		op->curtmps.om_off = restore->om_off;
E 2
#		ifdef PC
D 2
		    putlbracket( ftnno , -offset );
E 2
I 2
		    putlbracket( ftnno , -restore->om_off );
E 2
#		endif PC
E 8
I 8
D 17
#	endif vax
E 17
I 17
#	endif vax || tahoe
E 17
I 10
#	ifdef mc68000
	    if (restore->next_avail[REG_DATA]
		> op->curtmps.next_avail[REG_DATA]) {
		    op->curtmps.next_avail[REG_DATA]
			= restore->next_avail[REG_DATA];
		    change = TRUE;
	    }
	    if (restore->next_avail[REG_ADDR]
		> op->curtmps.next_avail[REG_ADDR]) {
		    op->curtmps.next_avail[REG_ADDR]
			= restore->next_avail[REG_ADDR];
		    change = TRUE;
	    }
#	endif mc68000
E 10
D 13
#   endif PC
E 13
    if (restore->om_off > op->curtmps.om_off) {
	    op->curtmps.om_off = restore->om_off;
	    change = TRUE;
    }
D 13
#   ifdef PC
E 13
	if (change) {
	    putlbracket(ftnno, op);
E 8
	}
I 8
D 13
#   endif PC
E 13
I 13
#endif PC
E 13
E 8
}
I 2
D 8

E 8
I 8

E 8
I 3
#ifdef PC
E 3
D 7
#ifdef VAX
E 7
I 7
D 17
#ifdef vax
E 17
I 17
#if defined(vax) || defined(tahoe)
E 17
E 7
/*
 * create a save mask for registers which have been used
 * in this level
 */
savmask()
{
D 5
	short mask;
E 5
I 5
	int mask;
E 5
	int i;

	mask = RSAVEMASK;
	if (opt('t'))
	        mask |= RUNCHECK;
D 8
	for (i = 0; i <= sizes[ cbn ].reg_max; i++)
		mask |= 1 << (FIRSTREG + i);
E 8
I 8
	for (i = 0; i <= regtypes[REG_GENERAL].highreg; i++) {
	    if (i >= sizes[cbn].low_water[REG_GENERAL]) {
		mask |= 1 << i;
	    }
	}
E 8
	return mask;
}
D 7
#endif VAX
E 7
I 7
D 17
#endif vax
E 17
I 17
#endif vax || tahoe
E 17
E 7
I 3
#endif PC
E 3
E 2
E 1
