h29837
s 00007/00001/00039
d D 5.1 85/06/07 23:36:18 kre 4 3
c Add copyright
e
s 00001/00001/00039
d D 1.3 85/05/21 19:25:52 libs 3 2
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00001/00000/00039
d D 1.2 83/04/25 01:29:50 dlw 2 1
c added ioiflg definition. DLW
e
s 00039/00000/00000
d D 1.1 81/02/18 18:02:17 dlw 1 0
c date and time created 81/02/18 18:02:17 by dlw
e
u
U
t
T
I 1
/*
D 4
char id_fio[] = "%W%";
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
 *
I 4
 *	%W% (Berkeley) %G%
 */

/*
E 4
 * f77 file i/o common definitions
 */

#include "fiodefs.h"

I 3
#define LOCAL		static
E 3
#define err(f,n,s)	{if(f) return(errno=n); else fatal(n,s);}
#define not_legal(u)	(u>=MXUNIT || u<0)
#define GET(x)		if((x=(*getn)())<0) return(x)
#define VAL(x)		(x!='\n'?x:' ')
#define PUT(x)		{if(n=(*putn)(x)) return(n);}
#define lcase(s)	((s >= 'A') && (s <= 'Z') ? s+('a'-'A') : s)

#define MAXINTLENGTH	32	/* to accomodate binary format */

long ftell();

extern int errno;
extern ioflag init;
D 3
extern icilist *svic;	/* active internal io list */
E 3
extern flag reading,external,sequential,formatted;
extern int (*getn)(),(*putn)(),(*ungetn)();	/*for formatted io*/
extern FILE *cf;	/*current file structure*/
extern unit *curunit;	/*current unit structure */
extern int lunit;	/*current logical unit*/
extern char *lfname;	/*current filename*/
extern unit units[];	/*logical units table*/
extern int recpos;		/*position in current record*/
extern ftnint recnum;		/*current record number*/
extern int reclen;		/* current record length */
extern int (*doed)(), (*doned)();
extern int (*dorevert)(), (*donewrec)(), (*doend)(), (*dotab)();
extern ioflag cblank, cplus, tab, elist, signit, errflag, endflag;
extern char *fmtbuf, *icptr, *icend, *fmtptr;
extern int scale;
extern int cursor;
extern int radix;
I 2
extern struct ioiflg	ioiflg_;
E 2
E 1
