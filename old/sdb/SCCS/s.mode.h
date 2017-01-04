h43750
s 00000/00000/00080
d D 4.2 82/08/17 13:26:37 rrh 2 1
c Changed the data types for the sdb class characters to be unsigned
c characters; this fixed a bug that prevented the arguments to a function
c from being printed symbolically.  The fix was done globally; it is not
c known if the "fix" fixed other bugs
e
s 00080/00000/00000
d D 4.1 80/10/09 23:57:43 bill 1 0
c date and time created 80/10/09 23:57:43 by bill
e
u
U
t
T
I 1
/* "%Z%%M% %I% %G%" */
#include "machine.h"
/*
 *	UNIX debugger
 */

#define MAXCOM	64
#define MAXARG	32
#define LINSIZ	256
TYPE	long	ADDR;
#ifndef vax
TYPE	int		INT;
#else
TYPE	short	INT;
#endif
TYPE	int		VOID;
TYPE	long int	L_INT;
TYPE	float		REAL;
TYPE	double		L_REAL;
TYPE	unsigned	POS;
TYPE	char		BOOL;
TYPE	char		CHAR;
TYPE	char		*STRING;
TYPE	char		MSG[];
TYPE	struct map	MAP;
TYPE	MAP		*MAPPTR;
TYPE	struct symtab	SYMTAB;
TYPE	SYMTAB		*SYMPTR;
TYPE	struct symslave SYMSLAVE;
TYPE	struct bkpt	BKPT;
TYPE	BKPT		*BKPTR;


/* file address maps */
struct map {
	L_INT	b1;
	L_INT	e1;
	L_INT	f1;
	L_INT	b2;
	L_INT	e2;
	L_INT	f2;
	INT	ufd;
};


/* slave table for symbols */
struct symslave {
	SYMV	valslave;
	INT	typslave;
};

struct bkpt {
	ADDR	loc;
	ADDR	ins;
	INT	count;
	INT	initcnt;
	INT	flag;
	CHAR	comm[MAXCOM];
	BKPT	*nxtbkpt;
};

TYPE	struct reglist	REGLIST;
TYPE	REGLIST		*REGPTR;
struct reglist {
	STRING	rname;
	INT	roffs;
};

struct {
	INT	junk[2];
	INT	fpsr;
	REAL	Sfr[6];
};

struct {
	INT	junk[2];
	INT	fpsr;
	L_REAL	Lfr[6];
};

E 1
