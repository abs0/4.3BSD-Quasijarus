h46793
s 00000/00001/00082
d D 4.6 88/05/31 20:53:11 donn 6 5
c Bleah -- deflab() can't be a macro, too many things use the side
c effects from expressions passed as arguments.
e
s 00001/00000/00082
d D 4.5 88/04/24 15:49:11 bostic 5 4
c fix for ANSI C  
e
s 00003/00000/00079
d D 4.4 87/12/11 00:46:08 donn 4 3
c utah rcsid 1.5 87/07/11 21:48:46: A little tweak from Sam Leffler's tahoe
c compiler (produce 'clrd -8(fp)' not 'L17: .double 0d0e+00; .text; movd
c L17,-8(fp)').
e
s 00014/00003/00065
d D 4.3 87/12/11 00:46:01 donn 3 2
c utah rcsid 1.4 86/08/03 01:03:22: Add 'configuration' flags which are
c really 'assembler style' flags, clean up makefile.  Add macros to replace
c some trivial functions.  Change FIX macros to punt if errors have been
c seen.
e
s 00003/00000/00065
d D 4.2 85/08/23 15:10:26 mckusick 2 1
c update from donn@utah-cs
e
s 00065/00000/00000
d D 4.1 85/03/19 13:24:10 ralph 1 0
c date and time created 85/03/19 13:24:10 by ralph
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#ifndef _MACDEFS_
#define	_MACDEFS_

#define makecc(val,i)	lastcon = (lastcon<<8)|((val<<24)>>24);  

#define ARGINIT		32 
#define AUTOINIT	0 

/*
 * Storage space requirements
 */
#define SZCHAR		8
#define SZINT		32
#define SZFLOAT		32
#define SZDOUBLE	64
#define SZLONG		32
#define SZSHORT		16
#define SZPOINT		32

/*
 * Alignment constraints
 */
#define ALCHAR		8
#define ALINT		32
#define ALFLOAT		32
#define ALDOUBLE	32
#define ALLONG		32
#define ALSHORT		16
#define ALPOINT		32
#define ALSTRUCT	8
#define ALSTACK		32 

typedef	long	CONSZ;		/* size in which constants are converted */
I 5
typedef	unsigned long	U_CONSZ;/* unsigned version of the above */
E 5
typedef	long	OFFSZ;		/* size in which offsets are kept */

#define CONFMT	"%ld"		/* format for printing constants */
#define LABFMT	"L%d"		/* format for printing labels */

#define CCTRANS(x) x		/* character set macro */

/*
 * Register cookies for stack pointer and argument pointer
 */
#define STKREG	13		/* stack pointer */
#define ARGREG	12		/* off frame pointer */

/*
 * Maximum and minimum register variables
 */
#define MINRVAR	6		/* use R6 thru ... */
#define MAXRVAR	11		/* ... R11 */

#define BACKAUTO		/* stack grows negatively for automatics */
#define BACKTEMP		/* stack grows negatively for temporaries */
#define FIELDOPS		/* show field hardware support on VAX */
#define RTOLBYTES		/* bytes are numbered from right to left */
I 3
#define ADDROREG		/* can unwind &o, where o is OREG */
E 3

I 3
#define ASSTRINGS		/* assembler handles string initializations */
#define STABDOT			/* assembler understands .stabd */
#define LCOMM			/* assembler supports .lcomm */

E 3
#define ENUMSIZE(high,low) INT	/* enums are always stored in full int */

D 3
#define ADDROREG
#define FIXDEF(p) outstab(p)
#define FIXARG(p) fixarg(p)
E 3
I 3
#define FIXDEF(p) if (!nerrors) outstab(p); else
#define FIXARG(p) if (!nerrors) fixarg(p); else
#define FIXSTRUCT(p,q) if (!nerrors) outstruct(p,q); else

E 3
I 2
#ifndef ncopy
#define	ncopy(q, p)	((q)->in = (p)->in)
#endif
I 3

#define aobeg()
#define aocode(p)
#define aoend()
D 6
#define deflab(m)	if (!nerrors) printf("L%d:\n", m); else
E 6
I 4

#define	PRTDCON			/* use machine-specific prtdcon routine */
extern	prtdcon();
E 4
E 3
E 2
#endif
E 1
