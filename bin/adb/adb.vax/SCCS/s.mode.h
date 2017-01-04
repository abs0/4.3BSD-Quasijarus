h10549
s 00001/00001/00054
d D 4.3 87/03/22 17:10:27 bostic 3 2
c LINSIZE jumped to 1024
e
s 00001/00000/00054
d D 4.2 81/05/14 20:09:06 root 2 1
c non-working version
e
s 00054/00000/00000
d D 4.1 81/05/14 15:23:11 root 1 0
c date and time created 81/05/14 15:23:11 by root
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
D 3
#define LINSIZ	512
E 3
I 3
#define LINSIZ	1024
E 3
TYPE	long	ADDR;
TYPE	short	INT;
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
I 2
	int	*rkern;
E 2
};
E 1
