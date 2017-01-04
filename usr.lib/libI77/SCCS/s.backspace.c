h21506
s 00001/00002/00063
d D 5.2 85/07/30 16:22:20 jerry 8 7
c rewind and backspace unconnected unit -> no-op.
e
s 00007/00001/00058
d D 5.1 85/06/07 23:40:02 kre 7 6
c Add copyright
e
s 00001/00003/00058
d D 1.6 83/08/23 15:38:42 dlw 6 5
c t_runc now sets "reading". DLW
e
s 00019/00011/00042
d D 1.5 83/02/01 23:34:04 dlw 5 4
c added nowreading since t_runc doesn't do it anymore. DLW
e
s 00001/00000/00052
d D 1.4 82/04/29 16:28:48 dlw 4 3
c clearerr() if b->uend set. DLW
e
s 00002/00001/00050
d D 1.3 81/11/03 17:05:03 dlw 3 2
c added test for successful truncation if (b->uwrt). DLW
e
s 00002/00002/00049
d D 1.2 81/02/20 18:25:32 dlw 2 1
c changed to F_ER codes. DLW
e
s 00051/00000/00000
d D 1.1 81/02/18 18:00:39 dlw 1 0
c date and time created 81/02/18 18:00:39 by dlw
e
u
U
t
T
I 1
/*
D 7
char id_backspace[] = "%W%";
E 7
I 7
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 7
 *
I 7
 *	%W%	%G%
 */

/*
E 7
 * Backspace records
 */

#include "fio.h"

D 5
char *bksp = "backspace";
char last_char();
E 5
I 5
static char	bksp[]	= "backspace";
char	last_char();
E 5

D 5
f_back(a) alist *a;
E 5
I 5
f_back(a)
alist	*a;
E 5
{	unit *b;
	int n,i;
	long x,y;
I 3

E 3
	lfname = NULL;
	elist = NO;
	external = YES;
	errflag = a->aerr;
	lunit = a->aunit;
D 2
	if (not_legal(lunit)) err(errflag,101,bksp)
E 2
I 2
D 5
	if (not_legal(lunit)) err(errflag,F_ERUNIT,bksp)
E 5
I 5
	if (not_legal(lunit))
		err(errflag, F_ERUNIT, bksp)
E 5
E 2
	b= &units[lunit];
D 5
	if(!b->ufd && (n=fk_open(READ,SEQ,FMT,(ftnint)lunit)) )
		err(errflag,n,bksp)
E 5
I 5
D 8
	if(!b->ufd && (n = fk_open(READ, SEQ, FMT, (ftnint)lunit)) )
		err(errflag, n, bksp)
E 8
I 8
	if(!b->ufd) return(OK);
E 8
E 5
	lfname = b->ufnm;
	if(b->uend)
	{	b->uend = NO;
I 4
		clearerr(b->ufd);
E 4
		return(OK);
	}
D 5
	if((x=ftell(b->ufd))==0) return(OK);
D 2
	if(!b->useek) err(errflag,106,bksp)
E 2
I 2
	if(!b->useek) err(errflag,F_ERNOBKSP,bksp)
E 2
D 3
	if(b->uwrt) t_runc(b,errflag);
E 3
I 3
	if(b->uwrt && (n=t_runc(b,errflag))) return(n);
E 5
I 5
	if((x = ftell(b->ufd)) == 0)
		return(OK);
	if(!b->useek)
		err(errflag, F_ERNOBKSP, bksp)
D 6
	if(b->uwrt && (n = t_runc(b, errflag)))
E 6
I 6
	if(b->uwrt && (n = t_runc(b, errflag, bksp)))	/* sets 'reading' */
E 6
		return(n);
E 5
E 3
	if(b->url)		/* direct access, purely academic */
	{	y = x%(long)b->url;
		x -= y?y:b->url;
		fseek(b->ufd,x,0);
		return(OK);
	}
	if(!b->ufmt)		/* unformatted sequential */
	{	fseek(b->ufd,-(long)sizeof(int),1);
		fread((char *)&n,sizeof(int),1,b->ufd);
		fseek(b->ufd,-(long)n-2*sizeof(int),1);
		return(OK);
	}
D 5
	if(x==1)			/* formatted sequential */
E 5
I 5
	if(x == 1)			/* formatted sequential */
E 5
	{	rewind(b->ufd);
		return(OK);
	}
D 5
	while(last_char(b->ufd)!='\n');	/* slow but simple */
E 5
I 5
D 6
	if (b->uwrt && ! nowreading(b))
		err(errflag, errno, bksp)
E 6
	while (last_char(b->ufd) != '\n')	/* slow but simple */
		;
E 5
	return(OK);
}
E 1
