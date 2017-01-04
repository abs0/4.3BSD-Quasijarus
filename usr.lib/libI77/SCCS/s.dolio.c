h61944
s 00002/00003/00040
d D 5.2 85/07/30 16:40:28 jerry 4 3
c implement namelist
e
s 00007/00001/00036
d D 5.1 85/06/07 23:43:46 kre 3 2
c Add copyright
e
s 00003/00003/00034
d D 1.2 81/02/20 18:27:36 dlw 2 1
c changed to F_ER codes. DLW
e
s 00037/00000/00000
d D 1.1 81/02/18 18:01:02 dlw 1 0
c date and time created 81/02/18 18:01:02 by dlw
e
u
U
t
T
I 1
/*
D 3
char id_dolio[] = "%W%";
E 3
I 3
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
 *
I 3
 *	%W%	%G%
 */

/*
E 3
D 4
 * list directed i/o common routines
E 4
I 4
 * list directed and namelist i/o common routines
E 4
 */

#include "fio.h"
#include "lio.h"


c_le(a,flag) cilist *a;
{	int n;
	lfname = NULL;
	elist = NO;
D 4
	sequential=external=formatted= LISTDIRECTED;
	fmtbuf = "ext list io";
E 4
I 4
	sequential=external=YES;
E 4
	errflag = a->cierr;
	endflag = a->ciend;
	lunit = a->ciunit;
D 2
	if(not_legal(lunit)) err(errflag,101,fmtbuf)
E 2
I 2
	if(not_legal(lunit)) err(errflag,F_ERUNIT,fmtbuf)
E 2
	curunit = &units[lunit];
	if(!curunit->ufd && (n=fk_open(flag,SEQ,FMT,(ftnint)lunit)))
		err(errflag,n,fmtbuf)
	cf = curunit->ufd;
	elist = YES;
	lfname = curunit->ufnm;
	scale=recpos=cursor=0;
	cplus=cblank=NO;
D 2
	if(!curunit->ufmt) err(errflag,102,fmtbuf)
	if(curunit->url) err(errflag,105,fmtbuf)
E 2
I 2
	if(!curunit->ufmt) err(errflag,F_ERNOFIO,fmtbuf)
	if(curunit->url) err(errflag,F_ERNOSIO,fmtbuf)
E 2
	return(OK);
}

do_lio(type,number,ptr,len) ftnint *number,*type; flex *ptr; ftnlen len;
{
	return((*lioproc)(number,ptr,len,*type));
}
E 1
