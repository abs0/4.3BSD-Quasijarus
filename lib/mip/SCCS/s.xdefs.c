h56053
s 00001/00001/00106
d D 4.3 85/03/19 13:10:26 ralph 3 2
c use common header file for C, Fortran, Pascal.
e
s 00004/00000/00103
d D 4.2 85/01/18 16:16:39 ralph 2 1
c changes for single precision floats; lint cleanups
e
s 00103/00000/00000
d D 4.1 85/01/16 16:57:10 ralph 1 0
c date and time created 85/01/16 16:57:10 by ralph
e
u
U
t
T
I 2
#ifndef lint
E 2
I 1
static char *sccsid ="%W% (Berkeley) %G%";
I 2
#endif lint

E 2
D 3
# include "mfile1"
E 3
I 3
# include "pass1.h"
E 3

/*	communication between lexical routines	*/

char	ftitle[100] = "";   	/* title of the file */
char	ititle[100] = "";   	/* title of initial file */
int	lineno;		/* line number of the input file */

CONSZ lastcon;  /* the last constant read by the lexical analyzer */
I 2
float fcon;   /* the last float read by the lexical analyzer */
E 2
double dcon;   /* the last double read by the lexical analyzer */


/*	symbol table maintainence */

struct symtab stab[SYMTSZ+1];  /* one extra slot for scratch */

int	curftn;  /* "current" function */
int	ftnno;  /* "current" function number */

int	curclass,	  /* current storage class */
	instruct,	/* "in structure" flag */
	stwart,		/* for accessing names which are structure members or names */
	blevel,		/* block level: 0 for extern, 1 for ftn args, >=2 inside function */
	curdim;		/* current offset into the dimension table */
	
int	dimtab[ DIMTABSZ ];

int	paramstk[ PARAMSZ ];  /* used in the definition of function parameters */
int	paramno;	  /* the number of parameters */
int	autooff,	/* the next unused automatic offset */
	argoff,	/* the next unused argument offset */
	strucoff;	/*  the next structure offset position */
int	regvar;		/* the next free register for register variables */
int	minrvar;	/* the smallest that regvar gets witing a function */
OFFSZ	inoff;		/* offset of external element being initialized */
int	brkflag = 0;	/* complain about break statements not reached */

struct sw swtab[SWITSZ];  /* table for cases within a switch */
struct sw *swp;  /* pointer to next free entry in swtab */
int swx;  /* index of beginning of cases for current switch */

/* debugging flag */
int xdebug = 0;

int strflg;  /* if on, strings are to be treated as lists */

int reached;	/* true if statement can be reached... */

int idname;	/* tunnel to buildtree for name id's */


NODE node[TREESZ];

int cflag = 0;  /* do we check for funny casts */
int hflag = 0;  /* do we check for various heuristics which may indicate errors */
int pflag = 0;  /* do we check for portable constructions */

int brklab;
int contlab;
int flostat;
int retlab = NOLAB;
int retstat;

/* save array for break, continue labels, and flostat */

int asavbc[BCSZ];
int *psavbc = asavbc ;

# ifndef BUG1
static char *
ccnames[] = { /* names of storage classes */
	"SNULL",
	"AUTO",
	"EXTERN",
	"STATIC",
	"REGISTER",
	"EXTDEF",
	"LABEL",
	"ULABEL",
	"MOS",
	"PARAM",
	"STNAME",
	"MOU",
	"UNAME",
	"TYPEDEF",
	"FORTRAN",
	"ENAME",
	"MOE",
	"UFORTRAN",
	"USTATIC",
	};

char * scnames( c ) register c; {
	/* return the name for storage class c */
	static char buf[12];
	if( c&FIELD ){
		sprintf( buf, "FIELD[%d]", c&FLDSIZ );
		return( buf );
		}
	return( ccnames[c] );
	}
# endif
E 1
