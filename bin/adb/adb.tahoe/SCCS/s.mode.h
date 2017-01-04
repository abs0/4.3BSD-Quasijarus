h04956
s 00001/00001/00055
d D 1.2 87/03/22 17:10:43 bostic 2 1
c LINSIZ jumped to 1024
e
s 00056/00000/00000
d D 1.1 86/02/25 16:04:41 sam 1 0
c date and time created 86/02/25 16:04:41 by sam
e
u
U
t
T
I 1
/*	%M%	%I%	%E%	*/

#include "machine.h"
/*
 * sdb/adb - common definitions for old srb style code
 */

#define MAXCOM	64
#define MAXARG	32
D 2
#define LINSIZ	256
E 2
I 2
#define LINSIZ	1024
E 2
TYPE	unsigned	ADDR;
TYPE	short	INT;
TYPE	int		VOID;
TYPE	int		L_INT;
TYPE	float		REAL;
TYPE	double		L_REAL;
TYPE	unsigned	POS;
TYPE	char		BOOL;
TYPE	char		CHAR;
TYPE	char		*STRING;
TYPE	char		MSG[];
TYPE	struct map	MAP;
TYPE	MAP		*MAPPTR;
TYPE	struct bkpt	BKPT;
TYPE	BKPT		*BKPTR;
TYPE	int		(*SIG)();


/* file address maps */
struct map {
	POS	b1;
	POS	e1;
	POS	f1;
	POS	b2;
	POS	e2;
	POS	f2;
	INT	ufd;
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
	int	*rkern;
};
E 1
