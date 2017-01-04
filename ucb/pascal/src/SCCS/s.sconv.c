h27571
s 00002/00002/00163
d D 5.2 86/11/12 10:20:09 mckusick 8 7
c add CCI (tahoe) support
e
s 00007/00003/00158
d D 5.1 85/06/05 14:52:47 dist 7 6
c Add copyright
e
s 00042/00042/00119
d D 2.2 85/03/20 15:06:33 ralph 6 5
c changes from donn@utah-cs for common header file for pcc
e
s 00000/00000/00161
d D 2.1 84/02/08 20:50:02 aoki 5 4
c synchronize to version 2
e
s 00000/00000/00161
d D 1.4 83/09/19 07:00:48 thien 4 3
c Restoring to unlinted version
e
s 00002/00000/00159
d D 1.3 83/08/19 05:02:20 thien 3 2
c The changes were made to allow successful linting
e
s 00001/00002/00158
d D 1.2 83/02/01 20:02:57 peter 2 1
c these should have tested against p2type from the beginning.  a botch.
e
s 00160/00000/00000
d D 1.1 83/01/17 13:49:04 mckusick 1 0
c date and time created 83/01/17 13:49:04 by mckusick
e
u
U
t
T
I 1
D 7
/* Copyright (c) 1983 Regents of the University of California */
E 7
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 7

I 3
#ifndef lint
E 3
D 7
static	char sccsid[] = "%Z%%M% %I% %G%";
I 3
#endif
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7
E 3

    /*
     *	functions to help pi put out
     *	polish postfix binary portable c compiler intermediate code
     *	thereby becoming the portable pascal compiler
     */

#include	"whoami.h"
#ifdef PC
#include	"0.h"
D 6
#include	"pcops.h"
E 6
I 6
#include	<pcc.h>
E 6
D 2
#include	"pc.h"
E 2

    /*
     *	this routine enforces ``the usual arithmetic conversions''
     *	all integral operands are converted to ints.
     *	if either operand is a double, both are made to be double.
     *	this routine takes struct nl *'s for the types,
     *	and returns both the struct nl * and the p2type for the result.
     */
tuac(thistype, thattype, resulttypep, resultp2typep)
    struct nl	*thistype;
    struct nl	*thattype;
    struct nl	**resulttypep;
    int		*resultp2typep;
{
    int		thisp2type = p2type(thistype);
    int		thatp2type = p2type(thattype);

    *resulttypep = thistype;
    *resultp2typep = thisp2type;
	/*
	 *	should only be passed scalars
	 */
    if (isnta(thistype,"sbcid") || isnta(thattype,"sbcid")) {
	return;
    }
D 2
    if (thistype == P2CHAR || thistype == P2SHORT) {
E 2
I 2
D 6
    if (thisp2type == P2CHAR || thisp2type == P2SHORT) {
E 2
	*resultp2typep = P2INT;
E 6
I 6
    if (thisp2type == PCCT_CHAR || thisp2type == PCCT_SHORT) {
	*resultp2typep = PCCT_INT;
E 6
	*resulttypep = nl + T4INT;
    }
D 6
    if (*resultp2typep == P2INT && thatp2type == P2DOUBLE) {
	*resultp2typep = P2DOUBLE;
E 6
I 6
    if (*resultp2typep == PCCT_INT && thatp2type == PCCT_DOUBLE) {
	*resultp2typep = PCCT_DOUBLE;
E 6
	*resulttypep = nl + TDOUBLE;
    }
    sconv(thisp2type, *resultp2typep);
}
    
    /*
     *	this routine will emit sconv operators when it thinks they are needed.
     *	this is code generator specific, rather than machine-specific.
     *	this routine takes p2types for arguments, not struct nl *'s.
     */
D 8
#ifdef vax
E 8
I 8
#if defined(vax) || defined(tahoe)
E 8
    /*
     *	the vax code genrator is very good, this routine is extremely boring.
     */
sconv(fromp2type, top2type)
    int	fromp2type;
    int	top2type;
{

    switch (top2type) {
D 6
	case P2CHAR:
	case P2SHORT:
	case P2INT:
E 6
I 6
	case PCCT_CHAR:
	case PCCT_SHORT:
	case PCCT_INT:
E 6
	    switch (fromp2type) {
D 6
		case P2CHAR:
		case P2SHORT:
		case P2INT:
		case P2DOUBLE:
E 6
I 6
		case PCCT_CHAR:
		case PCCT_SHORT:
		case PCCT_INT:
		case PCCT_DOUBLE:
E 6
			return;	/* pass1 knows how to do these */
		default:
			return;
	    }
D 6
	case P2DOUBLE:
E 6
I 6
	case PCCT_DOUBLE:
E 6
	    switch (fromp2type) {
D 6
		case P2CHAR:
		case P2SHORT:
		case P2INT:
			putop(P2SCONV, P2DOUBLE);
E 6
I 6
		case PCCT_CHAR:
		case PCCT_SHORT:
		case PCCT_INT:
			putop(PCC_SCONV, PCCT_DOUBLE);
E 6
			return;
D 6
		case P2DOUBLE:
E 6
I 6
		case PCCT_DOUBLE:
E 6
			return;
		default:
			return;
	    }
	default:
		return;
    }
}
D 8
#endif vax
E 8
I 8
#endif vax || tahoe
E 8
#ifdef mc68000
    /*
     *	i don't know how much to trust the mc68000 compiler,
     *	so this routine is full.
     */
sconv(fromp2type, top2type)
    int	fromp2type;
    int	top2type;
{

    switch (top2type) {
D 6
	case P2CHAR:
E 6
I 6
	case PCCT_CHAR:
E 6
	    switch (fromp2type) {
D 6
		case P2CHAR:
E 6
I 6
		case PCCT_CHAR:
E 6
			return;
D 6
		case P2SHORT:
		case P2INT:
		case P2DOUBLE:
			putop(P2SCONV, P2CHAR);
E 6
I 6
		case PCCT_SHORT:
		case PCCT_INT:
		case PCCT_DOUBLE:
			putop(PCC_SCONV, PCCT_CHAR);
E 6
			return;
		default:
			return;
	    }
D 6
	case P2SHORT:
E 6
I 6
	case PCCT_SHORT:
E 6
	    switch (fromp2type) {
D 6
		case P2SHORT:
E 6
I 6
		case PCCT_SHORT:
E 6
			return;
D 6
		case P2CHAR:
		case P2INT:
		case P2DOUBLE:
			putop(P2SCONV, P2SHORT);
E 6
I 6
		case PCCT_CHAR:
		case PCCT_INT:
		case PCCT_DOUBLE:
			putop(PCC_SCONV, PCCT_SHORT);
E 6
			return;
		default:
			return;
	    }
D 6
	case P2INT:
E 6
I 6
	case PCCT_INT:
E 6
	    switch (fromp2type) {
D 6
		case P2INT:
E 6
I 6
		case PCCT_INT:
E 6
			return;
D 6
		case P2CHAR:
		case P2SHORT:
		case P2DOUBLE:
			putop(P2SCONV, P2INT);
E 6
I 6
		case PCCT_CHAR:
		case PCCT_SHORT:
		case PCCT_DOUBLE:
			putop(PCC_SCONV, PCCT_INT);
E 6
			return;
		default:
			return;
	    }
D 6
	case P2DOUBLE:
E 6
I 6
	case PCCT_DOUBLE:
E 6
	    switch (fromp2type) {
D 6
		case P2DOUBLE:
E 6
I 6
		case PCCT_DOUBLE:
E 6
			return;
D 6
		case P2CHAR:
		case P2SHORT:
		case P2INT:
			putop(P2SCONV, P2DOUBLE);
E 6
I 6
		case PCCT_CHAR:
		case PCCT_SHORT:
		case PCCT_INT:
			putop(PCC_SCONV, PCCT_DOUBLE);
E 6
			return;
		default:
			return;
	    }
	default:
		return;
    }
}
#endif mc68000
#endif PC
E 1
