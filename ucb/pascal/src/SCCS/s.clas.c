h64766
s 00000/00007/00271
d D 5.2 85/06/05 13:58:20 dist 13 12
c Add copyright
e
s 00010/00000/00268
d D 5.1 85/06/05 11:56:48 dist 12 11
c Add copyright
e
s 00000/00000/00268
d D 2.1 84/02/08 20:52:08 aoki 11 10
c synchronize to version 2
e
s 00017/00002/00251
d D 1.8 84/02/08 00:52:12 mckusick 10 7
c merge in conformant array code by Carol Nishizak
e
s 00000/00000/00253
d R 1.9 83/10/13 12:32:33 thien 9 8
c 
e
s 00000/00000/00253
d R 1.8 83/09/19 06:57:46 thien 8 7
c Restoring to unlinted version
e
s 00028/00015/00225
d D 1.7 83/08/19 04:55:49 thien 7 6
c The changes were made to allow successful linting
e
s 00003/00001/00237
d D 1.6 82/11/11 19:40:11 mckusick 6 5
c optimize display save/restore and setjmp() to be done only when needed.
e
s 00003/00003/00235
d D 1.5 82/08/26 19:42:36 mckusick 5 4
c convert namelist structure to use unions
e
s 00021/00015/00217
d D 1.4 81/06/01 15:35:28 peter 4 3
c add storage classes to namelist, and use them.
e
s 00005/00001/00227
d D 1.3 81/03/16 23:05:51 mckusic 3 2
c ifdef out PC part of whereis
e
s 00020/00000/00208
d D 1.2 81/03/16 18:12:17 mckusic 2 1
c add temporary register allocation
e
s 00208/00000/00000
d D 1.1 80/08/27 19:54:44 peter 1 0
c date and time created 80/08/27 19:54:44 by peter
e
u
U
t
T
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
D 13

E 12
I 1
/* Copyright (c) 1979 Regents of the University of California */

I 7
#ifndef lint
E 7
static	char sccsid[] = "%Z%%M% %I% %G%";
I 7
#endif
E 7

E 13
#include "whoami.h"
#include "0.h"
#include "tree.h"
I 7
#include "tree_ty.h"
E 7

/*
 * This is the array of class
 * names for the classes returned
 * by classify.  The order of the 
 * classes is the same as the base
 * of the namelist, with special
 * negative index entries for structures,
 * scalars, pointers, sets and strings
 * to be collapsed into.
 */
char	*clnxxxx[] =
{
	"file",			/* -7	TFILE */
	"record",		/* -6	TREC */
	"array",		/* -5	TARY */
	"scalar",		/* -4	TSCAL */
	"pointer",		/* -3	TPTR */
	"set",			/* -2	TSET */
	"string",		/* -1	TSTR */
	"SNARK",		/*  0	NIL */
	"Boolean",		/*  1	TBOOL */
	"char",			/*  2	TCHAR */
	"integer",		/*  3	TINT */
	"real",			/*  4	TREAL */
	"\"nil\"",		/*  5	TNIL */
};

char **clnames	= &clnxxxx[-(TFIRST)];

/*
 * Classify takes a pointer
 * to a type and returns one
 * of several interesting group
 * classifications for easy use.
 */
classify(p1)
	struct nl *p1;
{
	register struct nl *p;

	p = p1;
swit:
D 7
	if (p == NIL) {
E 7
I 7
	if (p == NLNIL) {
E 7
		nocascade();
		return (NIL);
	}
	if (p == &nl[TSTR])
		return (TSTR);
	if ( p == &nl[ TSET ] ) {
	    return TSET;
	}
	switch (p->class) {
		case PTR:
			return (TPTR);
		case ARRAY:
			if (p->type == nl+T1CHAR)
				return (TSTR);
			return (TARY);
		case STR:
			return (TSTR);
		case SET:
			return (TSET);
I 10
		case CRANGE:
E 10
		case RANGE:
			p = p->type;
			goto swit;
		case TYPE:
			if (p <= nl+TLAST)
				return (p - nl);
			panic("clas2");
		case FILET:
			return (TFILE);
		case RECORD:
			return (TREC);
		case SCAL:
			return (TSCAL);
		default:
D 7
			panic("clas");
E 7
I 7
			{
			    panic("clas");
			    return(NIL);
			}
E 7
	}
}

#ifndef	PI0
/*
 * Is p a text file?
 */
text(p)
	struct nl *p;
{

	return (p != NIL && p->class == FILET && p->type == nl+T1CHAR);
}
#endif

/*
 * Scalar returns a pointer to
 * the the base scalar type of
 * its argument if its argument
 * is a SCALar else NIL.
 */
I 7
struct nl *
E 7
scalar(p1)
	struct nl *p1;
{
	register struct nl *p;

	p = p1;
D 7
	if (p == NIL)
		return (NIL);
E 7
I 7
	if (p == NLNIL)
		return (NLNIL);
E 7
D 10
	if (p->class == RANGE)
E 10
I 10
	if (p->class == RANGE || p->class == CRANGE)
E 10
		p = p->type;
D 7
	if (p == NIL)
		return (NIL);
	return (p->class == SCAL ? p : NIL);
E 7
I 7
	if (p == NLNIL)
		return (NLNIL);
	return (p->class == SCAL ? p : NLNIL);
E 7
}

/*
 * Isa tells whether p
 * is one of a group of
 * namelist classes.  The
 * classes wanted are specified
 * by the characters in s.
 * (Note that s would more efficiently,
 * if less clearly, be given by a mask.)
 */
isa(p, s)
	register struct nl *p;
	char *s;
{
	register i;
	register char *cp;

	if (p == NIL)
		return (NIL);
	/*
	 * map ranges down to
	 * the base type
	 */
D 10
	if (p->class == RANGE)
E 10
I 10
	if (p->class == RANGE) {
E 10
		p = p->type;
I 10
	}
E 10
	/*
	 * the following character/class
	 * associations are made:
	 *
	 *	s	scalar
	 *	b	Boolean
	 *	c	character
	 *	i	integer
	 *	d	double (real)
	 *	t	set
	 */
	switch (p->class) {
		case SET:
			i = TDOUBLE+1;
			break;
		case SCAL:
			i = 0;
I 10
			break;
		case CRANGE:
			/*
			 * find the base type of a conformant array range
			 */
			switch (classify(p->type)) {
				case TBOOL: i = 1; break;
				case TCHAR: i = 2; break;
				case TINT: i = 3; break;
				case TSCAL: i = 0; break;
				default:
					panic( "isa" );
			}
E 10
			break;
		default:
			i = p - nl;
	}
	if (i >= 0 && i <= TDOUBLE+1) {
		i = "sbcidt"[i];
		cp = s;
		while (*cp)
			if (*cp++ == i)
				return (1);
	}
	return (NIL);
}

/*
 * Isnta is !isa
 */
isnta(p, s)
I 7
    struct nl *p;
    char *s;
E 7
{

	return (!isa(p, s));
}

/*
 * "shorthand"
 */
I 7
char *
E 7
nameof(p)
I 7
struct nl *p;
E 7
{

	return (clnames[classify(p)]);
}

#ifndef PI0
D 7
nowexp(r)
	int *r;
E 7
I 7
/* find out for sure what kind of node this is being passed
   possibly several different kinds of node are passed to it */
int nowexp(r)
	struct tnode *r;
E 7
{
D 7
	if (r[0] == T_WEXP) {
		if (r[2] == NIL)
E 7
I 7
	if (r->tag == T_WEXP) {
		if (r->var_node.cptr == NIL)
E 7
			error("Oct/hex allowed only on writeln/write calls");
		else
			error("Width expressions allowed only in writeln/write calls");
		return (1);
	}
	return (NIL);
}
#endif
I 2

    /*
D 4
     *	is a variable a local, a formal parameter, or a register temporary?
E 4
I 4
     *	is a variable a local, a formal parameter, or a global?
E 4
     *	all this from just the offset:
I 4
     *	    globals are at levels 0 or 1
E 4
     *	    positives are parameters
     *	    negative evens are locals
D 4
     *	    negatives odds are encoded registers  ( see tmpalloc() ).
E 4
     */
D 4
whereis( offset )
    int	offset;
E 4
I 4
D 5
whereis( level , offset , extra_flags )
E 5
I 5
D 7
whereis( level , offset , other_flags )
E 5
    int		level;
E 7
I 7
/*ARGSUSED*/
whereis( offset , other_flags )
E 7
    int		offset;
D 5
    char	extra_flags;
E 5
I 5
    char	other_flags;
E 5
E 4
{
    
D 4
    if ( offset >= 0 ) {
	return PARAMVAR;
    }
    if ( offset & 1 ) {
D 3
	return REGVAR;
E 3
I 3
#	ifdef PC
	    return REGVAR;
#	else
	    panic("whereis");
#	endif PC
E 3
    }
    return LOCALVAR;
E 4
I 4
#   ifdef OBJ
	return ( offset >= 0 ? PARAMVAR : LOCALVAR );
#   endif OBJ
#   ifdef PC
D 5
	switch ( extra_flags & ( NGLOBAL | NPARAM | NLOCAL ) ) {
E 5
I 5
D 6
	switch ( other_flags & ( NGLOBAL | NPARAM | NLOCAL ) ) {
E 6
I 6
	switch ( other_flags & ( NGLOBAL | NPARAM | NLOCAL | NNLOCAL) ) {
I 7
	    default:
		panic( "whereis" );
E 7
E 6
E 5
	    case NGLOBAL:
		return GLOBALVAR;
	    case NPARAM:
		return PARAMVAR;
I 6
	    case NNLOCAL:
		return NAMEDLOCALVAR;
E 6
	    case NLOCAL:
		return LOCALVAR;
D 7
	    default:
		panic( "whereis" );
E 7
	}
#   endif PC
E 4
}
E 2
E 1
