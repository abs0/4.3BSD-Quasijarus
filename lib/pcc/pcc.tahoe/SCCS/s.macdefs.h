h15375
s 00000/00001/00083
d D 1.7 88/05/31 21:16:11 donn 8 6
c Bleah -- deflab() can't be a macro, too many things use the side
c effects from expressions passed as arguments.
e
s 00000/00002/00082
d R 1.7 88/05/31 21:05:37 donn 7 6
c Bleah -- deflab() can't be a macro, too many things use the side
c effects from expressions passed as arguments.
e
s 00001/00000/00083
d D 1.6 88/04/24 15:47:41 bostic 6 5
c fix for ANSI C  
e
s 00001/00000/00082
d D 1.5 87/12/10 23:05:16 donn 5 4
c utah rcsid 1.3 87/12/10 20:25:17: Move SPRECC from Makefile to macdefs.h;
c the tahoe pcc doesn't do the old-style double-only floating arithmetic.
e
s 00015/00003/00067
d D 1.4 87/12/10 23:05:08 donn 4 3
c utah rcsid 1.2 87/05/02 14:42:38: Turn some trivial functions into macros;
c move Makefile CONFIG flags in here; add a comment to ADDROREG.
e
s 00055/00070/00015
d D 1.3 86/02/04 22:17:35 sam 3 2
c redo for new mip
e
s 00001/00000/00084
d D 1.2 86/01/23 00:35:09 sam 2 1
c add ACONFMT for printing address constants in hex
e
s 00084/00000/00000
d D 1.1 86/01/11 11:00:58 sam 1 0
c date and time created 86/01/11 11:00:58 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

D 3
# define makecc(val,i)  lastcon = (lastcon<<8)|((val<<24)>>24);  
E 3
I 3
#ifndef _MACDEFS_
#define _MACDEFS_
E 3

D 3
# define  ARGINIT SZINT
# define  AUTOINIT (13*SZINT)
# define  SZCHAR 8
# define  SZINT 32
# define  SZFLOAT 32
# define  SZDOUBLE 64
# define  SZLONG 32
# define  SZSHORT 16
# define SZPOINT 32
# define ALCHAR 8
# define ALINT 32
# define ALFLOAT 32
# define ALDOUBLE 32
# define ALLONG 32
# define ALSHORT 16
# define ALPOINT 32
# define ALSTRUCT 8
# define  ALSTACK 32 
E 3
I 3
#define makecc(val,i)	lastcon = (lastcon<<8)|((val<<24)>>24);		
E 3

D 3
/*	size in which constants are converted */
/*	should be long if feasable */
E 3
I 3
#define ARGINIT		SZINT
#define AUTOINIT	(13*SZINT)
E 3

D 3
# define CONSZ long
I 2
# define ACONFMT "$0x%lx"
E 2
# define CONFMT "%ld"
E 3
I 3
/*
 * Storage space requirements.
 */
#define SZCHAR		8
#define SZINT		32
#define SZFLOAT		32
#define SZDOUBLE	64
#define SZLONG		32
#define SZSHORT		16
#define SZPOINT		32
E 3

D 3
/*	size in which offsets are kept
/*	should be large enough to cover address space in bits
*/
E 3
I 3
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
E 3

D 3
# define OFFSZ long
E 3
I 3
#define ACONFMT	"$0x%lx"	/* format for printing address constants */
#define CONFMT	"%ld"		/* format for printing constants */
#define LABFMT	"L%d"		/* format for printing labels */
E 3

D 3
/* 	character set macro */
E 3
I 3
typedef	long	CONSZ;		/* size in which constants are converted */
I 6
typedef	unsigned long	U_CONSZ;/* unsigned version of the above */
E 6
typedef	long	OFFSZ;		/* size in which offsets are kept */
E 3

D 3
# define  CCTRANS(x) x
E 3
I 3
#define CCTRANS(x) x		/* character set macro */
E 3

D 3
/* register cookie for stack pointer */
E 3
I 3
/*
 * Register cookie for stack pointer.
 */
#define STKREG	13		/* stack pointer */
E 3

D 3
# define  STKREG 13
E 3
I 3
/*
 * Maximum and minimum register variables
 */
#define MINRVAR	6		/* use R6 thru ... */
#define MAXRVAR	12		/* ... R12 */
E 3

D 3
/*	maximum and minimum register variables */
E 3
I 3
#define BACKAUTO		/* stack grows negatively for automatics */
#define BACKTEMP		/* stack grows negatively for temporaries */
/*#define FIELDOPS	/* no hardware field support */
/*#define RTOLBYTES	/* bytes are number from left to right */
I 4
#define ADDROREG		/* can unwind &o, where o is OREG */

#define ASSTRINGS		/* assembler handles string initializations */
#define STABDOT			/* assembler understands .stabd */
#define LCOMM			/* assembler supports .lcomm */
I 5
#define SPRECC			/* double only arithmetic not supported */
E 5

E 4
#define ENUMSIZE(high,low) INT	/* enums are always stored in full int */
E 3

D 3
# define MAXRVAR 12
# define MINRVAR 6

	/* various standard pieces of code are used */
# define STDPRTREE
# define LABFMT "L%d"

/* show stack grows negatively */
#define BACKAUTO
#define BACKTEMP

/* no field hardware support on Tahoe
#define FIELDOPS */

/* bytes are numbered from left to right
#define RTOLBYTES */

/* we want prtree included */
# define STDPRTREE
# ifndef FORT
# define ONEPASS
E 3
I 3
D 4
#define ADDROREG
#define FIXDEF(p)	outstab(p)
#define FIXARG(p)	fixarg(p)
E 4
I 4
#define FIXDEF(p)	if (!nerrors) outstab(p); else
#define FIXARG(p)	if (!nerrors) fixarg(p); else
#define FIXSTRUCT(p,q)	if (!nerrors) outstruct(p,q); else

E 4
#ifndef ncopy
#define	ncopy(q, p)	((q)->in = (p)->in)
E 3
#endif
I 4

#define aobeg()
#define aocode(p)
#define aoend()
D 8
#define deflab(m)	if (!nerrors) printf("L%d:\n", m); else
E 8
E 4

D 3
# define ENUMSIZE(high,low) INT


/* register char and short are not allowed
#define REG_CHAR */
/* addr of reg+offset is computed */
# define ADDROREG
# define FIXDEF(p) outstab(p)
# define FIXARG(p) fixarg(p)
# define FIXSTRUCT(a,b) outstruct(a,b)
# define PRTDCON	/* use local version of prtdcon */
# define ASSTRINGS	/* assembler recognizes strings */
# define STABDOT	/* output .stabdot entries */
# define LCOMM		/* .lcomm for non-global commons */
# define BUFSTDERR	/* buffer error messages */
# define FLEXNAMES	/* unlimited name length */
E 3
I 3
#define	PRTDCON			/* use machine-specific prtdcon routine */
extern	prtdcon();
#endif
E 3
E 1
