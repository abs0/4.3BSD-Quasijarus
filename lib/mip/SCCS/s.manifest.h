h58383
s 00001/00001/00120
d D 4.2 87/12/09 23:57:02 donn 2 1
c utah rcsid 1.2 87/04/30 13:51:05: Use 'pointer to enum member' as the
c reserved 'impossible' type that distinguishes unused symbols; thus 'pointer
c to undef' becomes available to represent 'void *'.
e
s 00121/00000/00000
d D 4.1 85/03/19 13:05:07 ralph 1 0
c date and time created 85/03/19 13:05:07 by ralph
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#ifndef _MANIFEST_
#define	_MANIFEST_

#include <stdio.h>
#include "pcclocal.h"
#include "config.h"

#define DSIZE	(MAXOP+1)	/* DSIZE is the size of the dope array */

#define NOLAB	(-1)		/* no label with constant */

/*
 * Node types
 */
#define LTYPE	02		/* leaf */
#define UTYPE	04		/* unary */
#define BITYPE	010		/* binary */

/*
 * Bogus type values
 */
D 2
#define TNULL	PTR		/* pointer to UNDEF */
E 2
I 2
#define TNULL	INCREF(MOETY)	/* pointer to MOETY -- impossible type */
E 2
#define TVOID	FTN		/* function returning UNDEF (for void) */

/*
 * Type packing constants
 */
#define TMASK	060		/* mask for 1st component of compound type */
#define TMASK1	0300		/* mask for 2nd component of compound type */
#define TMASK2	0360		/* mask for 3rd component of compound type */
#define BTMASK	017		/* basic type mask */
#define BTSHIFT	4		/* basic type shift */
#define TSHIFT	2		/* shift count to get next type component */

/*
 * Type manipulation macros
 */
#define MODTYPE(x,y)	x = ((x)&(~BTMASK))|(y)	/* set basic type of x to y */
#define BTYPE(x)	((x)&BTMASK)		/* basic type of x */
#define ISUNSIGNED(x)	((x)<=ULONG&&(x)>=UCHAR)
#define UNSIGNABLE(x)	((x)<=LONG&&(x)>=CHAR)
#define ENUNSIGN(x)	((x)+(UNSIGNED-INT))
#define DEUNSIGN(x)	((x)+(INT-UNSIGNED))
#define ISPTR(x)	(((x)&TMASK)==PTR)
#define ISFTN(x)	(((x)&TMASK)==FTN)	/* is x a function type */
#define ISARY(x)	(((x)&TMASK)==ARY)	/* is x an array type */
#define INCREF(x)	((((x)&~BTMASK)<<TSHIFT)|PTR|((x)&BTMASK))
#define DECREF(x)	((((x)>>TSHIFT)&~BTMASK)|( (x)&BTMASK))
/* advance x to a multiple of y */
#define SETOFF(x,y)	if ((x)%(y) != 0) (x) = (((x)/(y) + 1) * (y))
/* can y bits be added to x without overflowing z */
#define NOFIT(x,y,z)	(((x)%(z) + (y)) > (z))

/*
 * Pack and unpack field descriptors (size and offset)
 */
#define PKFIELD(s,o)	(((o)<<6)| (s))
#define UPKFSZ(v)	((v) &077)
#define UPKFOFF(v)	((v)>>6)

/*
 * Operator information
 */
#define TYFLG	016
#define ASGFLG	01
#define LOGFLG	020

#define SIMPFLG	040
#define COMMFLG	0100
#define DIVFLG	0200
#define FLOFLG	0400
#define LTYFLG	01000
#define CALLFLG	02000
#define MULFLG	04000
#define SHFFLG	010000
#define ASGOPFLG 020000

#define SPFLG	040000

#define optype(o)	(dope[o]&TYFLG)
#define asgop(o)	(dope[o]&ASGFLG)
#define logop(o)	(dope[o]&LOGFLG)
#define callop(o)	(dope[o]&CALLFLG)

/*
 * External declarations, typedefs and the like
 */
#ifdef FLEXNAMES
char	*hash();
char	*savestr();
char	*tstr();
extern	int tstrused;
extern	char *tstrbuf[];
extern	char **curtstr;
#define	freetstr()	curtstr = tstrbuf, tstrused = 0
#endif

extern	int nerrors;		/* number of errors seen so far */
extern	int dope[];		/* a vector containing operator information */
extern	char *opst[];		/* a vector containing names for ops */

typedef	union ndu NODE;
typedef	unsigned int TWORD;
#define NIL	(NODE *)0

#ifndef ONEPASS
#ifndef EXPR
#define EXPR '.'
#endif
#ifndef BBEG
#define BBEG '['
#endif
#ifndef BEND
#define BEND ']'
#endif
#else
#include "onepass.h"
#endif
#endif
E 1
