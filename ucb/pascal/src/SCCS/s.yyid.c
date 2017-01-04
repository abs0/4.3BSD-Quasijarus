h23398
s 00007/00003/00256
d D 5.1 85/06/05 15:08:10 dist 10 9
c Add copyright
e
s 00000/00000/00259
d D 2.1 84/02/08 20:44:18 aoki 9 8
c synchronize to version 2
e
s 00000/00000/00259
d D 1.6 83/09/19 07:01:59 thien 8 7
c Restoring to unlinted version
e
s 00013/00009/00246
d D 1.5 83/08/19 05:04:20 thien 7 5
c The changes were made to allow successful linting
e
s 00002/00000/00255
d R 1.5 83/02/05 16:52:01 mckusick 6 5
c merge in PXP
e
s 00004/00004/00251
d D 1.4 82/08/26 23:46:40 mckusick 5 3
c convert namelist structure to use unions
e
s 00001/00001/00254
d R 1.4 82/08/26 23:45:12 mckusick 4 3
c convert namelist structure to use unions
e
s 00002/00002/00253
d D 1.3 81/03/08 19:29:53 mckusic 3 2
c merge in onyx changes
e
s 00012/00004/00243
d D 1.2 80/10/03 01:09:55 peter 2 1
c Implement formal functions and procedures
e
s 00247/00000/00000
d D 1.1 80/08/27 19:57:08 peter 1 0
c date and time created 80/08/27 19:57:08 by peter
e
u
U
t
T
I 1
D 10
/* Copyright (c) 1979 Regents of the University of California */
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */
E 10

I 7
#ifndef lint
E 7
D 3
static	char sccsid[] = "%Z%%M% %I% %G%";
E 3
I 3
D 10
static char sccsid[] = "%Z%%M% %I% %G%";
I 7
#endif
E 10
I 10
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 10
E 7
E 3

#include "whoami.h"
#include "0.h"
I 7
#include "tree_ty.h"	/* must be included for yy.h */
E 7
#include "yy.h"

#ifdef PI
D 7
extern	int *yypv;
E 7
I 7
extern	union semstack *yypv;
E 7
/*
 * Determine whether the identifier whose name
 * is "cp" can possibly be a kind, which is a
 * namelist class.  We look through the symbol
 * table for the first instance of cp as a non-field,
 * and at all instances of cp as a field.
 * If any of these are ok, we return true, else false.
 * It would be much better to handle with's correctly,
 * even to just know whether we are in a with at all.
 *
 * Note that we don't disallow constants on the lhs of assignment.
 */
identis(cp, kind)
	register char *cp;
	int kind;
{
	register struct nl *p;
	int i;

	/*
	 * Cp is NIL when error recovery inserts it.
	 */
	if (cp == NIL)
		return (1);

	/*
	 * Record kind we want for possible later use by yyrecover
	 */
	yyidwant = kind;
	yyidhave = NIL;
	i = ( (int) cp ) & 077;
	for (p = disptab[i]; p != NIL; p = p->nl_next)
		if (p->symbol == cp) {
			if (yyidok(p, kind))
				goto gotit;
			if (p->class != FIELD && p->class != BADUSE)
				break;
		}
	if (p != NIL)
		for (p = p->nl_next; p != NIL; p = p->nl_next)
			if (p->symbol == cp && p->class == FIELD && yyidok(p, kind))
				goto gotit;
	return (0);
gotit:
	if (p->class == BADUSE && !Recovery) {
		yybadref(p, OY.Yyeline);
D 7
		yypv[0] = NIL;
E 7
I 7
		yypv[0].i_entry = NIL;
E 7
	}
	return (1);
}

/*
 * A bad reference to the identifier cp on line
 * line and use implying the addition of kindmask
 * to the mask of kind information.
 */
I 7
struct nl *
E 7
yybaduse(cp, line, kindmask)
	register char *cp;
	int line, kindmask;
{
	register struct nl *p, *oldp;
	int i;

	i = ( (int) cp ) & 077;
	for (p = disptab[i]; p != NIL; p = p->nl_next)
		if (p->symbol == cp)
			break;
	oldp = p;
	if (p == NIL || p->class != BADUSE)
D 7
		p = enter(defnl(cp, BADUSE, 0, 0));
E 7
I 7
		p = enter(defnl(cp, BADUSE, NLNIL, 0));
E 7
D 3
	p->value[NL_KINDS] =| kindmask;
E 3
I 3
	p->value[NL_KINDS] |= kindmask;
E 3
	yybadref(p, line);
	return (oldp);
}

    /*
     *	ud is initialized so that esavestr will allocate
     *	sizeof ( struct udinfo ) bytes for the 'real' struct udinfo
     */
D 7
struct	udinfo ud = { ~0 , ~0 , 0};
E 7
I 7
struct	udinfo ud = { ~0 , (struct udinfo *) ~0 , 0};
E 7
/*
 * Record a reference to an undefined identifier,
 * or one which is improperly used.
 */
yybadref(p, line)
	register struct nl *p;
	int line;
{
	register struct udinfo *udp;

D 7
	if (p->chain != NIL && p->chain->ud_line == line)
E 7
I 7
	if (p->chain != NIL && ((struct udinfo *) p->chain)->ud_line == line)
E 7
		return;
D 7
	udp = esavestr(&ud);
E 7
I 7
	udp = (struct udinfo *) esavestr((char *) &ud);
E 7
	udp->ud_line = line;
D 7
	udp->ud_next = p->chain;
	p->chain = udp;
E 7
I 7
	udp->ud_next = (struct udinfo *) p->chain;
	p->chain = (struct nl *) udp;
E 7
}

D 2
#define	varkinds	((1<<CONST)|(1<<VAR)|(1<<REF)|(1<<ARRAY)|(1<<PTR)|(1<<RECORD)|(1<<FIELD)|(1<<FUNC)|(1<<FVAR))
E 2
I 2
#define	varkinds	((1<<CONST)|(1<<VAR)|(1<<REF)|(1<<ARRAY)|(1<<PTR) \
			|(1<<RECORD)|(1<<FIELD)|(1<<FUNC)|(1<<FVAR) \
			|(1<<FFUNC)|(1<<PROC)|(1<<FPROC))
E 2
/*
 * Is the symbol in the p entry of the namelist
 * even possibly a kind kind?  If not, update
 * what we have based on this encounter.
 */
yyidok(p, kind)
	register struct nl *p;
	int kind;
{

	if (p->class == BADUSE) {
		if (kind == VAR)
			return (p->value[0] & varkinds);
		return (p->value[0] & (1 << kind));
	}
	if (yyidok1(p, kind))
		return (1);
	if (yyidhave != NIL)
		yyidhave = IMPROPER;
	else
		yyidhave = p->class;
	return (0);
}

yyidok1(p, kind)
	register struct nl *p;
	int kind;
{
D 7
	int i;
E 7

	switch (kind) {
I 7
		default:
E 7
		case FUNC:
D 2
			if (p->class == FVAR)
				return(1);
E 2
I 2
			return (   p -> class == FUNC
				|| p -> class == FVAR
				|| p -> class == FFUNC );
		case PROC:
			return ( p -> class == PROC || p -> class == FPROC );
E 2
		case CONST:
		case TYPE:
D 2
		case PROC:
E 2
		case FIELD:
			return (p->class == kind);
		case VAR:
			return (p->class == CONST || yyisvar(p, NIL));
		case ARRAY:
		case RECORD:
			return (yyisvar(p, kind));
		case PTRFILE:
			return (yyisvar(p, PTR) || yyisvar(p, FILET));
	}
}

D 5
yyisvar(p, class)
E 5
I 5
yyisvar(p, varclass)
E 5
	register struct nl *p;
D 5
	int class;
E 5
I 5
	int varclass;
E 5
{

	switch (p->class) {
		case FIELD:
		case VAR:
		case REF:
		case FVAR:
		/*
		 * We would prefer to return
		 * parameterless functions only.
		 */
		case FUNC:
I 2
		case FFUNC:
E 2
D 5
			return (class == NIL || (p->type != NIL && p->type->class == class));
E 5
I 5
			return (varclass == NIL || (p->type != NIL && p->type->class == varclass));
E 5
I 2
		case PROC:
		case FPROC:
D 5
			return ( class == NIL );
E 5
I 5
			return ( varclass == NIL );
E 5
E 2
	}
	return (0);
}
#endif
#ifdef PXP
#ifndef DEBUG
identis()
{

	return (1);
}
#endif
#ifdef DEBUG
extern	char *classes[];

char	kindchars[]	"UCTVAQRDPF";
/*
 * Fake routine "identis" for pxp when testing error recovery.
 * Looks at letters in variable names to answer questions
 * about attributes.  Mapping is
 *	C	const_id
 *	T	type_id
 *	V	var_id		also if any of AQRDF
 *	A	array_id
 *	Q	ptr_id
 *	R	record_id
 *	D	field_id	D for "dot"
 *	P	proc_id
 *	F	func_id
 */
identis(cp, kind)
	register char *cp;
	int kind;
{
	register char *dp;
	char kindch;

	/*
	 * Don't do anything unless -T
	 */
	if (!typetest)
		return (1);

	/*
	 * Inserted symbols are always correct
	 */
	if (cp == NIL)
		return (1);
	/*
	 * Set up the names for error messages
	 */
	yyidwant = classes[kind];
	for (dp = kindchars; *dp; dp++)
		if (any(cp, *dp)) {
			yyidhave = classes[dp - kindchars];
			break;
		}

	/*
	 * U in the name means undefined
	 */
	if (any(cp, 'U'))
		return (0);

	kindch = kindchars[kind];
	if (kindch == 'V')
		for (dp = "AQRDF"; *dp; dp++)
			if (any(cp, *dp))
				return (1);
	return (any(cp, kindch));
}
#endif
#endif
E 1
