h09542
s 00001/00000/00082
d D 1.6 88/05/22 13:02:54 bostic 6 5
c fix for ANSI C
e
s 00001/00000/00081
d D 1.5 86/01/08 02:35:08 donn 5 4
c Added econvert() to the list of faked PCC functions.  We want to see the
c real enum types downstream, not the 'equivalent' integer values.
e
s 00003/00000/00078
d D 1.4 85/08/28 14:22:01 mckusick 4 3
c update from donn@utah-cs
e
s 00001/00000/00077
d D 1.3 85/04/08 11:46:22 ralph 3 2
c changes due to pcc restructuring for common header files.
e
s 00007/00004/00070
d D 1.2 83/04/01 00:03:58 sam 2 1
c from sun
e
s 00074/00000/00000
d D 1.1 82/08/30 13:16:00 rrh 1 0
c date and time created 82/08/30 13:16:00 by rrh
e
u
U
t
T
I 1
D 2
/*
 *	%W%	(Berkeley)	%G%
 */
# define makecc(val,i)  lastcon |= val<<(8*i);  /* pdp-11 womp next char  */
E 2
I 2
/*	%W%	(Berkeley)	%G%	*/

#if defined(pdp11) || defined(vax)
#define makecc(val,i)  lastcon |= val<<(8*i);  /* pdp-11 womp next char  */
#else
#define makecc(val,i)	lastcon = i ? (val<<8)|lastcon : val
#endif
E 2

# define  ARGINIT 288 /* initial offset for arguments */
# define  AUTOINIT 0   /* initial automatic offset */
extern int  SZCHAR;
extern int  SZINT;
extern int  SZFLOAT;
extern int  SZDOUBLE;
extern int  SZLONG;
extern int  SZSHORT;
extern int SZPOINT;
extern int ALCHAR;
extern int ALINT;
extern int ALFLOAT;
extern int ALDOUBLE;
extern int ALLONG;
extern int ALSHORT;
extern int ALPOINT;
extern int ALSTRUCT;
# define SAVEADJUST 0 /* bits of adjustment required for stackframe */


/* type (INT OR LONG) big enough to hold pointers */


/*	size in which constants are converted */
/*	should be long if feasable */

# define CONSZ long
I 6
# define U_CONSZ unsigned long
E 6
# define CONFMT "%Ld"
# define CONOFMT "%Lo"
I 3
# define LABFMT	"L%d"
E 3

/*	size in which offsets are kept
/*	should be large enough to cover address space in bits
*/

# define OFFSZ long

/* 	character set macro */

# define  CCTRANS(x) x

/*	register cookie for stack pointer */

# define STKREG 9

/*	maximum and minimum register variable values */

# define MAXRVAR 1000
# define MINRVAR 1

I 4
/* macros carried over from the PCC */
# define ncopy(q, p)	((q)->in = (p)->in)

E 4
/* many macro definitions for functions irrelevant to lint */

# define locctr(n) 0
# define getlab() 10
# define genswitch( x,y)
# define bccode()
# define cendarg()
# define incode(a,s) (inoff += (s))
# define fincode(a,s) (inoff += (s) )
# define vfdzero(n) (inoff += (n))
# define aobeg()
# define aoend()
I 5
# define econvert(p)
E 5

# ifndef unix
# define NOFORTRAN  {extern int pflag; if(pflag) werror( "fortran keyword nonportable" );}
# else
# define NOFORTRAN { werror( "fortran keyword nonportable" ); }
# endif

# define LINT
E 1
