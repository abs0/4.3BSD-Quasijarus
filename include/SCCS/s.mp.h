h16542
s 00007/00001/00034
d D 5.1 85/05/30 09:36:53 dist 3 2
c Add copyright
e
s 00001/00001/00034
d D 4.2 83/07/01 04:08:52 sam 2 1
c put stdio where it belongs
e
s 00035/00000/00000
d D 4.1 83/05/03 13:48:05 sam 1 0
c date and time created 83/05/03 13:48:05 by sam
e
u
U
t
T
I 1
D 3
/*	%M%	%I%	%E%	*/
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3

#define MINT struct mint
MINT
{	int len;
	short *val;
};
#define FREE(x) {if(x.len!=0) {free((char *)x.val); x.len=0;}}
#ifndef DBG
#define shfree(u) free((char *)u)
#else
D 2
#include "stdio.h"
E 2
I 2
#include <stdio.h>
E 2
#define shfree(u) { if(dbg) fprintf(stderr, "free %o\n", u); free((char *)u);}
extern int dbg;
#endif
#ifndef vax
struct half
{	short high;
	short low;
};
#else
struct half
{	short low;
	short high;
};
#endif
extern MINT *itom();
extern short *xalloc();

#ifdef lint
extern xv_oid;
#define VOID xv_oid =
#else
#define VOID
#endif
E 1
