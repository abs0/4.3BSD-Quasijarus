h23362
s 00007/00001/00069
d D 5.1 85/06/07 23:44:49 kre 5 4
c Add copyright
e
s 00003/00002/00067
d D 1.4 85/05/21 19:24:29 libs 4 3
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00010/00009/00059
d D 1.3 81/08/11 23:24:09 dlw 3 2
c added test for return val of now{w,r}. DLW
e
s 00003/00003/00065
d D 1.2 81/02/20 18:28:19 dlw 2 1
c changed to F_ER codes. DLW
e
s 00068/00000/00000
d D 1.1 81/02/18 18:01:09 dlw 1 0
c date and time created 81/02/18 18:01:09 by dlw
e
u
U
t
T
I 1
/*
D 5
char id_due[] = "%W%";
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
 * direct unformatted external i/o
 */

#include "fio.h"

D 3
char *due = "due";
E 3
I 3
D 4
char rdue[] = "read due";
char wdue[] = "write due";
E 4
I 4
LOCAL char rdue[] = "read due";
LOCAL char wdue[] = "write due";
E 4
E 3

s_rdue(a) cilist *a;
{
	int n;
	reading = YES;
	if(n=c_due(a,READ)) return(n);
D 3
	if(curunit->uwrt) nowreading(curunit);
E 3
I 3
	if(curunit->uwrt && ! nowreading(curunit)) err(errflag, errno, rdue);
E 3
	return(OK);
}

s_wdue(a) cilist *a;
{
	int n;
	reading = NO;
	if(n=c_due(a,WRITE)) return(n);
	curunit->uend = NO;
D 3
	if(!curunit->uwrt) nowwriting(curunit);
E 3
I 3
	if(!curunit->uwrt && ! nowwriting(curunit)) err(errflag, errno, wdue)
E 3
	return(OK);
}

I 4
LOCAL
E 4
c_due(a,flag) cilist *a;
{	int n;
	lfname = NULL;
	elist = NO;
	sequential=formatted=NO;
	recpos = reclen = 0;
	external = YES;
	errflag = a->cierr;
	endflag = a->ciend;
	lunit = a->ciunit;
D 2
	if(not_legal(lunit)) err(errflag,101,due);
E 2
I 2
D 3
	if(not_legal(lunit)) err(errflag,F_ERUNIT,due);
E 3
I 3
	if(not_legal(lunit)) err(errflag,F_ERUNIT,rdue+5);
E 3
E 2
	curunit = &units[lunit];
	if (!curunit->ufd && (n=fk_open(flag,DIR,UNF,(ftnint)lunit)) )
D 3
		err(errflag,n,due)
E 3
I 3
		err(errflag,n,rdue+5)
E 3
	cf = curunit->ufd;
	elist = YES;
	lfname = curunit->ufnm;
D 2
	if (curunit->ufmt) err(errflag,103,due)
	if (!curunit->useek || !curunit->url) err(errflag,104,due)
E 2
I 2
D 3
	if (curunit->ufmt) err(errflag,F_ERNOUIO,due)
	if (!curunit->useek || !curunit->url) err(errflag,F_ERNODIO,due)
E 3
I 3
	if (curunit->ufmt) err(errflag,F_ERNOUIO,rdue+5)
	if (!curunit->useek || !curunit->url) err(errflag,F_ERNODIO,rdue+5)
E 3
E 2
	if (fseek(cf, (long)((a->cirec-1)*curunit->url), 0) < 0)
D 3
		return(due_err(due));
E 3
I 3
		return(due_err(rdue+5));
E 3
	else
		return(OK);
}

e_rdue()
{
	return(OK);
}

e_wdue()
{/*	This is to ensure full records. It is really necessary. */
	int n = 0;
	if (curunit->url!=1 && recpos!=curunit->url &&
	    (fseek(cf, (long)(curunit->url-recpos-1), 1) < 0
		|| fwrite(&n, 1, 1, cf) != 1))
D 3
			return(due_err(due));
E 3
I 3
			return(due_err(rdue+5));
E 3
	return(OK);
}
E 1
