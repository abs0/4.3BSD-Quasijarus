h65489
s 00010/00005/00104
d D 7.4 86/12/15 20:26:43 sam 4 3
c lint
e
s 00001/00001/00108
d D 7.3 86/11/23 13:35:59 sam 3 2
c move machine dependencies to ../machine/kdbparam.h
e
s 00006/00004/00103
d D 7.2 86/11/20 14:42:10 sam 2 1
c miscellaneous cleanups
e
s 00107/00000/00000
d D 7.1 86/11/20 12:21:59 sam 1 0
c date and time created 86/11/20 12:21:59 by sam
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
 * Copyright (c) 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

/*
 * adb - string table version; common definitions
 */

#include "param.h"
#include "dir.h"
#include "../machine/psl.h"
#include "../machine/pte.h"
#include "user.h"
#include "proc.h"

#include <a.out.h>
#include <ctype.h>

struct	pcb kdbpcb;		/* must go before redef.h */

#include "redef.h"
D 3
#include "machine.h"
E 3
I 3
#include "../machine/kdbparam.h"
E 3

/* access modes */
#define RD	0
#define WT	1

#define NSP	0
#define	ISP	1
#define	DSP	2
#define STAR	4

/*
 * Symbol types, used internally in calls to findsym routine.
 * One the VAX this all degenerates since I & D symbols are indistinct.
 * Basically we get NSYM==0 for `=' command, ISYM==DSYM otherwise.
 */
#define NSYM	0
#define DSYM	1		/* Data space symbol */
#define ISYM	DSYM		/* Instruction space symbol == DSYM on VAX */

#define BKPTSET	1
#define BKPTEXEC 2

I 2
/*
 * setexit/reset tokens..
 */
#define	ERROR	1
#define	NEXT	6
E 2
#define	SINGLE	7
#define	CONTIN	8

D 2
#define MAXCOM	64
#define MAXARG	32
E 2
#define LINSIZ	256
#define MAXOFF	1024
#define MAXPOS	80
#define MAXLIN	256
#define QUOTE	0200

D 2
#define TRUE	 (-1)
#define FALSE	0
E 2
#define LOBYTE	0377
#define STRIP	0177

#define SP	' '
#define TB	'\t'
#define EOR	'\n'
#define	CTRL(c)	('c'&037)

#define	eqstr(a,b)	(strcmp(a,b)==0)

typedef	unsigned ADDR;
typedef	unsigned POS;

typedef	struct bkpt {
	ADDR	loc;
	ADDR	ins;
	short	count;
	short	initcnt;
	short	flag;
I 2
#define MAXCOM	64
E 2
	char	comm[MAXCOM];
	struct	bkpt *nxtbkpt;
} BKPT, *BKPTR;

typedef	struct {
	char	*rname;
	int	*rkern;
} REGLIST, *REGPTR;

ADDR	maxoff;
ADDR	localval;
int	mkfault;
long	var[36];
D 4
long	maxstor;
E 4
char	*errflg;
long	dot;
int	dotinc;
long	adrval;
int	adrflg;
long	cntval;
int	cntflg;

/* result type declarations */
long	inkdot();
D 4
POS	get();
POS	chkget();
E 4
I 4
u_int	get();
u_int	chkget();
u_int	bchkget();
E 4
char	*exform();
D 4
long	round();
E 4
BKPTR	scanbkpt();

struct	nlist *symtab, *esymtab;
struct	nlist *cursym;
struct	nlist *lookup();
E 1
