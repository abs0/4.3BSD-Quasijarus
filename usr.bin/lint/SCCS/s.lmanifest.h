h59796
s 00012/00007/00051
d D 1.2 83/03/29 11:54:11 edward 2 1
c Statics are now treated correctly.
c 	Structure type matching in second pass done by hashed name
c 	and size.
c 	-z flag added to ignore undeclared structure errors.
e
s 00058/00000/00000
d D 1.1 82/08/30 13:16:01 rrh 1 0
c date and time created 82/08/30 13:16:01 by rrh
e
u
U
t
T
I 1
/*
 *	%W%	(Berkeley)	%G%
 */
/*	the key:
	LDI	defined and initialized: storage set aside
	LIB	defined on a library
	LDC	defined as a common region on UNIX
	LDX	defined by an extern: if ! pflag, same as LDI
	LRV	function returns a value
	LUV	function used in a value context
	LUE	function used in effects context
	LUM	mentioned somewhere other than at the declaration
I 2
	LST	defined as a static
E 2
	*/
D 2
# define LDI 01
# define LIB 02
# define LDC 04
# define LDX 010
# define LRV 020
# define LUV 040
E 2
I 2
# define LDI 0001
# define LIB 0002
# define LDC 0004
# define LDX 0010
# define LRV 0020
# define LUV 0040
E 2
# define LUE 0100
# define LUM 0200
I 2
# define LST 0400
E 2

D 2
# define LFN 0400  /* filename record */
E 2
I 2
# define LFN 01000  /* filename record */
E 2

	/* number of chars in NAME, and filename */
#ifndef FLEXNAMES
# define LCHNM 8
# define LFNM 14
#endif

typedef struct ty {
	TWORD aty;
	short extra;
I 2
	short extra1;
E 2
	} ATYPE;
I 2

#define X_NONAME 0x8000		/* for extra1, if structure has no name */
E 2

typedef struct line {
	short decflag;
#ifndef FLEXNAMES
	char name[LCHNM];
#else
	char *name;
#endif
	short nargs;
	short fline;
	ATYPE type;
	} LINE;

union rec {
	struct line l;
	struct {
		short decflag;
#ifndef FLEXNAMES
		char fn[LFNM];
#else
		char *fn;
#endif
		} f;
	};
E 1
