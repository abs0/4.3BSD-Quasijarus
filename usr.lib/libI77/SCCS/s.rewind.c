h54416
s 00001/00002/00035
d D 5.2 85/07/30 16:22:16 jerry 5 4
c rewind and backspace unconnected unit -> no-op.
e
s 00007/00001/00030
d D 5.1 85/06/07 23:54:25 kre 4 3
c Add copyright
e
s 00006/00004/00025
d D 1.3 83/08/23 15:39:33 dlw 3 2
c t_runc now sets "reading". DLW
e
s 00002/00002/00027
d D 1.2 81/02/20 18:33:54 dlw 2 1
c changed to F_ER codes. DLW
e
s 00029/00000/00000
d D 1.1 81/02/18 18:01:53 dlw 1 0
c date and time created 81/02/18 18:01:53 by dlw
e
u
U
t
T
I 1
/*
D 4
char id_rewind[] = "%W%";
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
 *
I 4
 *	%W%	%G%
 */

/*
E 4
 * rewind.c  -  f77 file rewind
 */

#include "fio.h"

I 3
static char	rwnd[]	= "rewind";

E 3
f_rew(a) alist *a;
{	int n;
	unit *b;

	lfname = NULL;
	elist = NO;
	external = YES;			/* for err */
	lunit = a->aunit;
	errflag = a->aerr;
D 2
	if(not_legal(lunit)) err(errflag,101,"rewind")
E 2
I 2
D 3
	if(not_legal(lunit)) err(errflag,F_ERUNIT,"rewind")
E 3
I 3
	if(not_legal(lunit)) err(errflag,F_ERUNIT,rwnd)
E 3
E 2
	b = &units[lunit];
D 5
	if(!b->ufd && (n=fk_open(READ,SEQ,FMT,(ftnint)lunit)) )
D 3
		err(errflag,n,"rewind")
E 3
I 3
		err(errflag,n,rwnd)
E 5
I 5
	if(!b->ufd) return(OK);
E 5
E 3
	lfname = b->ufnm;
D 2
	if(!b->useek) err(errflag,106,"rewind")
E 2
I 2
D 3
	if(!b->useek) err(errflag,F_ERNOBKSP,"rewind")
E 3
I 3
	if(!b->useek) err(errflag,F_ERNOBKSP,rwnd)
E 3
E 2
	b->uend = NO;
	if(b->uwrt)
D 3
		if(n=t_runc(b,errflag)) return(n);
E 3
I 3
		if(n=t_runc(b,errflag,rwnd)) return(n);
E 3
	rewind(b->ufd);
	return(OK);
}
E 1
