h01633
s 00010/00005/00321
d D 5.5 88/06/29 19:23:31 bostic 9 8
c install approved copyright notice
e
s 00009/00003/00317
d D 5.4 88/05/05 17:50:31 bostic 8 7
c add Berkeley specific header; written by K. McKusick and P. Kessler
e
s 00005/00005/00315
d D 5.3 86/01/07 00:05:01 sam 7 6
c everyone wants to rename calls to callf (or similar), make it just findcall
e
s 00005/00005/00315
d D 5.2 86/01/07 00:01:04 sam 6 5
c CALLSDEBUG -> CALLDEBUG
e
s 00007/00001/00313
d D 5.1 85/06/04 13:26:29 dist 5 4
c Add copyright
e
s 00001/00000/00313
d D 1.4 83/03/30 20:50:07 peter 4 3
c initialize the aligned entry point field of the ``indirect'' nl entry.
e
s 00003/00000/00310
d D 1.3 82/06/18 20:21:29 peter 3 2
c -e -E -f and -F flags, this time for sure.
e
s 00001/00000/00309
d D 1.2 82/06/14 18:08:19 peter 2 1
c -f and -e flags.
e
s 00309/00000/00000
d D 1.1 81/11/11 11:16:40 peter 1 0
c date and time created 81/11/11 11:16:40 by peter
e
u
U
t
T
I 5
/*
 * Copyright (c) 1983 Regents of the University of California.
D 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
I 8
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 9
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 9
I 9
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 9
E 8
 */

E 5
I 1
#ifndef lint
D 5
    static	char *sccsid = "%W% (Berkeley) %G%";
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
E 5
D 8
#endif not lint
E 8
I 8
#endif /* not lint */
E 8

#include	"gprof.h"

    /*
     *	a namelist entry to be the child of indirect calls
     */
nltype	indirectchild = {
	"(*)" ,				/* the name */
	(unsigned long) 0 ,		/* the pc entry point */
I 4
	(unsigned long) 0 ,		/* entry point aligned to histogram */
E 4
	(double) 0.0 ,			/* ticks in this routine */
	(double) 0.0 ,			/* cumulative ticks in children */
	(long) 0 ,			/* how many times called */
	(long) 0 ,			/* how many calls to self */
I 3
	(double) 1.0 ,			/* propagation fraction */
	(double) 0.0 ,			/* self propagation time */
	(double) 0.0 ,			/* child propagation time */
E 3
I 2
	(bool) 0 ,			/* print flag */
E 2
	(int) 0 ,			/* index in the graph list */
	(int) 0 , 			/* graph call chain top-sort order */
	(int) 0 ,			/* internal number of cycle on */
	(struct nl *) &indirectchild ,	/* pointer to head of cycle */
	(struct nl *) 0 ,		/* pointer to next member of cycle */
	(arctype *) 0 ,			/* list of caller arcs */
	(arctype *) 0 			/* list of callee arcs */
    };

operandenum
operandmode( modep )
    struct modebyte	*modep;
{
    long	usesreg = modep -> regfield;
    
    switch ( modep -> modefield ) {
	case 0:
	case 1:
	case 2:
	case 3:
	    return literal;
	case 4:
	    return indexed;
	case 5:
	    return reg;
	case 6:
	    return regdef;
	case 7:
	    return autodec;
	case 8:
	    return ( usesreg != PC ? autoinc : immediate );
	case 9:
	    return ( usesreg != PC ? autoincdef : absolute );
	case 10:
	    return ( usesreg != PC ? bytedisp : byterel );
	case 11:
	    return ( usesreg != PC ? bytedispdef : bytereldef );
	case 12:
	    return ( usesreg != PC ? worddisp : wordrel );
	case 13:
	    return ( usesreg != PC ? worddispdef : wordreldef );
	case 14:
	    return ( usesreg != PC ? longdisp : longrel );
	case 15:
	    return ( usesreg != PC ? longdispdef : longreldef );
    }
    /* NOTREACHED */
}

char *
operandname( mode )
    operandenum	mode;
{
    
    switch ( mode ) {
	case literal:
	    return "literal";
	case indexed:
	    return "indexed";
	case reg:
	    return "register";
	case regdef:
	    return "register deferred";
	case autodec:
	    return "autodecrement";
	case autoinc:
	    return "autoincrement";
	case autoincdef:
	    return "autoincrement deferred";
	case bytedisp:
	    return "byte displacement";
	case bytedispdef:
	    return "byte displacement deferred";
	case byterel:
	    return "byte relative";
	case bytereldef:
	    return "byte relative deferred";
	case worddisp:
	    return "word displacement";
	case worddispdef:
	    return "word displacement deferred";
	case wordrel:
	    return "word relative";
	case wordreldef:
	    return "word relative deferred";
	case immediate:
	    return "immediate";
	case absolute:
	    return "absolute";
	case longdisp:
	    return "long displacement";
	case longdispdef:
	    return "long displacement deferred";
	case longrel:
	    return "long relative";
	case longreldef:
	    return "long relative deferred";
    }
    /* NOTREACHED */
}

long
operandlength( modep )
    struct modebyte	*modep;
{
    
    switch ( operandmode( modep ) ) {
	case literal:
	case reg:
	case regdef:
	case autodec:
	case autoinc:
	case autoincdef:
	    return 1;
	case bytedisp:
	case bytedispdef:
	case byterel:
	case bytereldef:
	    return 2;
	case worddisp:
	case worddispdef:
	case wordrel:
	case wordreldef:
	    return 3;
	case immediate:
	case absolute:
	case longdisp:
	case longdispdef:
	case longrel:
	case longreldef:
	    return 5;
	case indexed:
	    return 1+operandlength( (struct modebyte *) ((char *) modep) + 1 );
    }
    /* NOTREACHED */
}

unsigned long
reladdr( modep )
    struct modebyte	*modep;
{
    operandenum	mode = operandmode( modep );
    char	*cp;
    short	*sp;
    long	*lp;

    cp = (char *) modep;
    cp += 1;			/* skip over the mode */
    switch ( mode ) {
	default:
	    fprintf( stderr , "[reladdr] not relative address\n" );
	    return (unsigned long) modep;
	case byterel:
	    return (unsigned long) ( cp + sizeof *cp + *cp );
	case wordrel:
	    sp = (short *) cp;
	    return (unsigned long) ( cp + sizeof *sp + *sp );
	case longrel:
	    lp = (long *) cp;
	    return (unsigned long) ( cp + sizeof *lp + *lp );
    }
}

D 7
findcalls( parentp , p_lowpc , p_highpc )
E 7
I 7
findcall( parentp , p_lowpc , p_highpc )
E 7
    nltype		*parentp;
    unsigned long	p_lowpc;
    unsigned long	p_highpc;
{
    unsigned char	*instructp;
    long		length;
    nltype		*childp;
    operandenum		mode;
    operandenum		firstmode;
    unsigned long	destpc;

    if ( textspace == 0 ) {
	return;
    }
    if ( p_lowpc < s_lowpc ) {
	p_lowpc = s_lowpc;
    }
    if ( p_highpc > s_highpc ) {
	p_highpc = s_highpc;
    }
#   ifdef DEBUG
D 6
	if ( debug & CALLSDEBUG ) {
E 6
I 6
	if ( debug & CALLDEBUG ) {
E 6
D 7
	    printf( "[findcalls] %s: 0x%x to 0x%x\n" ,
E 7
I 7
	    printf( "[findcall] %s: 0x%x to 0x%x\n" ,
E 7
		    parentp -> name , p_lowpc , p_highpc );
	}
#   endif DEBUG
    for (   instructp = textspace + p_lowpc ;
	    instructp < textspace + p_highpc ;
	    instructp += length ) {
	length = 1;
	if ( *instructp == CALLS ) {
		/*
		 *	maybe a calls, better check it out.
		 *	skip the count of the number of arguments.
		 */
#	    ifdef DEBUG
D 6
		if ( debug & CALLSDEBUG ) {
E 6
I 6
		if ( debug & CALLDEBUG ) {
E 6
D 7
		    printf( "[findcalls]\t0x%x:calls" , instructp - textspace );
E 7
I 7
		    printf( "[findcall]\t0x%x:calls" , instructp - textspace );
E 7
		}
#	    endif DEBUG
	    firstmode = operandmode( (struct modebyte *) (instructp+length) );
	    switch ( firstmode ) {
		case literal:
		case immediate:
		    break;
		default:
		    goto botched;
	    }
	    length += operandlength( (struct modebyte *) (instructp+length) );
	    mode = operandmode( (struct modebyte *) ( instructp + length ) );
#	    ifdef DEBUG
D 6
		if ( debug & CALLSDEBUG ) {
E 6
I 6
		if ( debug & CALLDEBUG ) {
E 6
		    printf( "\tfirst operand is %s", operandname( firstmode ) );
		    printf( "\tsecond operand is %s\n" , operandname( mode ) );
		}
#	    endif DEBUG
	    switch ( mode ) {
		case regdef:
		case bytedispdef:
		case worddispdef:
		case longdispdef:
		case bytereldef:
		case wordreldef:
		case longreldef:
			/*
			 *	indirect call: call through pointer
			 *	either	*d(r)	as a parameter or local
			 *		(r)	as a return value
			 *		*f	as a global pointer
			 *	[are there others that we miss?,
			 *	 e.g. arrays of pointers to functions???]
			 */
		    addarc( parentp , &indirectchild , (long) 0 );
		    length += operandlength(
				(struct modebyte *) ( instructp + length ) );
		    continue;
		case byterel:
		case wordrel:
		case longrel:
			/*
			 *	regular pc relative addressing
			 *	check that this is the address of 
			 *	a function.
			 */
		    destpc = reladdr( (struct modebyte *) (instructp+length) )
				- (unsigned long) textspace;
		    if ( destpc >= s_lowpc && destpc <= s_highpc ) {
			childp = nllookup( destpc );
#			ifdef DEBUG
D 6
			    if ( debug & CALLSDEBUG ) {
E 6
I 6
			    if ( debug & CALLDEBUG ) {
E 6
D 7
				printf( "[findcalls]\tdestpc 0x%x" , destpc );
E 7
I 7
				printf( "[findcall]\tdestpc 0x%x" , destpc );
E 7
				printf( " childp->name %s" , childp -> name );
				printf( " childp->value 0x%x\n" ,
					childp -> value );
			    }
#			endif DEBUG
			if ( childp -> value == destpc ) {
				/*
				 *	a hit
				 */
			    addarc( parentp , childp , (long) 0 );
			    length += operandlength( (struct modebyte *)
					    ( instructp + length ) );
			    continue;
			}
			goto botched;
		    }
			/*
			 *	else:
			 *	it looked like a calls,
			 *	but it wasn't to anywhere.
			 */
		    goto botched;
		default:
		botched:
			/*
			 *	something funny going on.
			 */
#		    ifdef DEBUG
D 6
			if ( debug & CALLSDEBUG ) {
E 6
I 6
			if ( debug & CALLDEBUG ) {
E 6
D 7
			    printf( "[findcalls]\tbut it's a botch\n" );
E 7
I 7
			    printf( "[findcall]\tbut it's a botch\n" );
E 7
			}
#		    endif DEBUG
		    length = 1;
		    continue;
	    }
	}
    }
}
E 1
