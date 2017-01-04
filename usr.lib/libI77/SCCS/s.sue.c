h39193
s 00007/00001/00079
d D 5.1 85/06/07 23:56:19 kre 5 4
c Add copyright
e
s 00004/00003/00076
d D 1.4 85/05/21 19:25:26 libs 4 3
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00009/00009/00070
d D 1.3 81/08/11 23:24:57 dlw 3 2
c added test for return val of now{r,w}. DLW
e
s 00004/00004/00075
d D 1.2 81/02/20 18:34:24 dlw 2 1
c changed to F_ER codes. DLW
e
s 00079/00000/00000
d D 1.1 81/02/18 18:02:00 dlw 1 0
c date and time created 81/02/18 18:02:00 by dlw
e
u
U
t
T
I 1
/*
D 5
char id_sue[] = "%W%";
E 5
I 5
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 5
 *
I 5
 *	%W%	%G%
 */

/*
E 5
 * sequential unformatted external read/write routines
 */

#include "fio.h"

extern int reclen;
D 4
long recloc;
D 3
char *rsue = "read sue";
char *sue = "sue";
E 3
I 3
char rsue[] = "read sue";
char wsue[] = "write sue";
E 4
I 4
LOCAL long recloc;
LOCAL char rsue[] = "read sue";
LOCAL char wsue[] = "write sue";
E 4
E 3

s_rsue(a) cilist *a;
{
	int n;
	reading = YES;
	if(n=c_sue(a,READ)) return(n);
D 3
	if(curunit->uwrt) nowreading(curunit);
E 3
I 3
	if(curunit->uwrt && ! nowreading(curunit)) err(errflag, errno, rsue)
E 3
	recpos = 0;
	if(fread(&reclen,sizeof(int),1,cf) == 1) return(OK);
	if(feof(cf))
	{	curunit->uend = YES;
		err(endflag, EOF, rsue)
	}
	clearerr(cf);
	err(errflag, errno, rsue)
}

s_wsue(a) cilist *a;
{
	int n;
	reading = NO;
	if(n=c_sue(a,WRITE)) return(n);
D 3
	if(!curunit->uwrt) nowwriting(curunit);
E 3
I 3
	if(!curunit->uwrt && ! nowwriting(curunit)) err(errflag, errno, wsue)
E 3
	reclen = 0;
	recloc=ftell(cf);
	fseek(cf,(long)sizeof(int),1);
	curunit->uend = NO;
	return(OK);
}

I 4
LOCAL
E 4
c_sue(a,flag) cilist *a;
{	int n;
	external = sequential = YES;
	formatted = NO;
	lfname = NULL;
	elist = NO;
	errflag = a->cierr;
	endflag = a->ciend;
	lunit = a->ciunit;
D 2
	if(not_legal(lunit)) err(errflag,101,sue)
E 2
I 2
D 3
	if(not_legal(lunit)) err(errflag,F_ERUNIT,sue)
E 3
I 3
	if(not_legal(lunit)) err(errflag,F_ERUNIT,rsue+5)
E 3
E 2
	curunit = &units[lunit];
	if(!curunit->ufd && (n=fk_open(flag,SEQ,UNF,(ftnint)lunit)))
D 3
		err(errflag,n,sue)
E 3
I 3
		err(errflag,n,rsue+5)
E 3
	cf = curunit->ufd;
	elist = YES;
	lfname = curunit->ufnm;
D 2
	if(curunit->ufmt) err(errflag,103,sue)
	if(curunit->url) err(errflag,105,sue)
	if(!curunit->useek) err(errflag,120,sue)
E 2
I 2
D 3
	if(curunit->ufmt) err(errflag,F_ERNOUIO,sue)
	if(curunit->url) err(errflag,F_ERNOSIO,sue)
	if(!curunit->useek) err(errflag,F_ERSEEK,sue)
E 3
I 3
	if(curunit->ufmt) err(errflag,F_ERNOUIO,rsue+5)
	if(curunit->url) err(errflag,F_ERNOSIO,rsue+5)
	if(!curunit->useek) err(errflag,F_ERSEEK,rsue+5)
E 3
E 2
	return(OK);
}

e_wsue()
{	long loc;
	fwrite(&reclen,sizeof(int),1,cf);
	loc=ftell(cf);
	fseek(cf,recloc,0);
	fwrite(&reclen,sizeof(int),1,cf);
	fseek(cf,loc,0);
	return(OK);
}

e_rsue()
{
	fseek(cf,(long)(reclen-recpos+sizeof(int)),1);
	return(OK);
}
E 1
