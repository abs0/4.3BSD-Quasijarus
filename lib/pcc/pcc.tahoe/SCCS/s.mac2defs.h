h30425
s 00001/00001/00072
d D 1.4 88/01/19 13:14:07 donn 4 3
c Major goof -- make SIREG different from SMCON.
e
s 00000/00004/00073
d D 1.3 86/07/27 16:06:47 sam 3 2
c float's ALWAYS have size 1
e
s 00064/00040/00013
d D 1.2 86/02/04 22:17:36 sam 2 1
c redo for new mip
e
s 00053/00000/00000
d D 1.1 86/01/11 11:00:58 sam 1 0
c date and time created 86/01/11 11:00:58 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

D 2
/*	Tahoe Registers */
E 2
I 2
/*
 * Tahoe Registers
 */
E 2

D 2
	/* scratch registers */
# define R0 0
# define R1 1
# define R2 2
# define R3 3
# define R4 4
# define R5 5
E 2
I 2
/*
 * Scratch registers
 */
#define R0	0
#define R1	1
#define R2	2
#define R3	3
#define R4	4
#define R5	5
E 2

D 2
	/* register variables */
# define R6 6
# define R7 7
# define R8 8
# define R9 9
# define R10 10
# define R11 11
# define R12 12
E 2
I 2
/*
 * Register variables
 */
#define R6	6
#define R7	7
#define R8	8
#define R9	9
#define R10	10
#define R11	11
#define R12	12
E 2

D 2
	/* special purpose */
# define FP 13	/* frame pointer */
# define SP 14	/* stack pointer */
# define PC 15	/* program counter */
E 2
I 2
/*
 * Special purpose registers
 */
#define FP	13		/* frame pointer */
#define SP	14		/* stack pointer */
#define PC	15		/* program counter */
E 2

D 2
	/* floating registers */
# define ACC 16	/* accumulator */
E 2
I 2
/*
 * Floating registers
 */
#define	ACC	16		/* accumulator */
E 2

D 2
extern int fregs;
extern int maxargs;
E 2
I 2
#define	TMPREG	FP		/* reg off which temporaries are referenced */
#define	REGSZ	16		/* size of register set */
E 2

D 2
# define BYTEOFF(x) ((x)&03)
# define wdal(k) (BYTEOFF(k)==0)
# define BITOOR(x) ((x)>>3)  /* bit offset to oreg offset */
E 2
I 2
#define R2REGS	1		/* permit double indexing */
E 2

D 2
# define REGSZ 16
E 2
I 2
extern	int fregs;
extern	int maxargs;
E 2

D 2
# define TMPREG FP
E 2
I 2
#define BYTEOFF(x)	((x)&03)
#define wdal(k)		(BYTEOFF(k)==0)		/* word align */
#define BITOOR(x)	((x)>>3)		/* bit offset to oreg offset */
E 2

D 2
# define R2REGS   /* permit double indexing */
E 2
I 2
/*
 * Some macros used in store():
 *	just evaluate the arguments, and be done with it...
 */
#define STOARG(p)
#define STOFARG(p)
#define STOSTARG(p)
E 2

D 2
# define STOARG(p)     /* just evaluate the arguments, and be done with it... */
# define STOFARG(p)
# define STOSTARG(p)
E 2
I 2
/*
 * Some short routines that get called an awful lot are actually macros.
 */
D 3
#if defined(FORT) || defined(SPRECC)
E 3
#define	szty(t)	((t) == DOUBLE ? 2 : 1)
D 3
#else
#define	szty(t)	(((t) == DOUBLE || (t) == FLOAT) ? 2 : 1)
#endif
E 3
#define	shltype(o, p) \
	((o) == REG || (o) == NAME || (o) == ICON || \
	 (o) == OREG || ((o) == UNARY MUL && shumul((p)->in.left)))
#define	ncopy(q, p)	((q)->in = (p)->in)
E 2

D 2
# define NESTCALLS

# define MYREADER(p) myreader(p)
int optim2();
# define SIREG (SPECIAL|6)	/* indexed OREG */
int special();
#define callchk(p) if(p->in.op!=FORTCALL)allchk()
E 2
I 2
#define MYREADER(p)	myreader(p)
int	optim2();
D 4
#define	SIREG		(SPECIAL|6)	/* indexed OREG */
E 4
I 4
#define	SIREG		(SPECIAL|7)	/* indexed OREG */
E 4
int	special();			/* additional special shapes */
#define callchk(p)	if ((p)->in.op != FORTCALL) allchk()
E 2
E 1
