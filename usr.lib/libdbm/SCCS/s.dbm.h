h33569
s 00018/00023/00010
d D 5.1 86/03/27 15:21:51 bloom 2 1
c add copyright
c
c >> A lot more got done on this delta -- this is when the new stuff by
c >> Robert Elz that used ndbm got checked in.  Keith Bostic.
e
s 00033/00000/00000
d D 4.1 83/05/03 13:47:56 sam 1 0
c date and time created 83/05/03 13:47:56 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

D 2
#define	PBLKSIZ	1024
#define	DBLKSIZ	4096
#define	BYTESIZ	8
E 2
I 2
#ifndef NULL
/*
 * this is lunacy, we no longer use it (and never should have
 * unconditionally defined it), but, this whole file is for
 * backwards compatability - someone may rely on this.
 */
E 2
#define	NULL	((char *) 0)
I 2
#endif
E 2

D 2
long	bitno;
long	maxbno;
long	blkno;
long	hmask;
E 2
I 2
#include <ndbm.h>
E 2

D 2
char	pagbuf[PBLKSIZ];
char	dirbuf[DBLKSIZ];

int	dirf;
int	pagf;
int	dbrdonly;

typedef	struct
{
	char	*dptr;
	int	dsize;
} datum;

E 2
datum	fetch();
D 2
datum	makdatum();
E 2
datum	firstkey();
datum	nextkey();
I 2
#if 0
datum	makdatum();
E 2
datum	firsthash();
long	calchash();
long	hashinc();
D 2

E 2
I 2
#endif
E 2
E 1
