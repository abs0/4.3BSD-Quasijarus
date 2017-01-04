h22180
s 00003/00002/00034
d D 5.2 85/07/30 16:23:50 jerry 10 9
c endfile unit not conn -> open and create file.
e
s 00007/00001/00029
d D 5.1 85/06/07 23:45:36 kre 9 8
c Add copyright
e
s 00000/00019/00030
d D 1.8 85/05/21 19:25:49 libs 8 7
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00006/00003/00043
d D 1.7 83/08/23 15:39:16 dlw 7 6
c t_runc now sets "reading". DLW
e
s 00025/00047/00021
d D 1.6 83/02/01 23:27:57 dlw 6 5
c converted to use truncate syscall. DLW
e
s 00001/00001/00067
d D 1.5 81/12/06 11:24:18 dlw 5 4
c fixed t_runc of /dev/null !  DLW
e
s 00001/00001/00067
d D 1.4 81/08/14 14:13:59 dlw 4 3
c moved 'nowreading' after the test to see if trunc should be done. DLW
e
s 00002/00002/00066
d D 1.3 81/08/11 23:26:43 dlw 3 2
c added test for return val of now{r,w}. DLW
e
s 00005/00005/00063
d D 1.2 81/02/20 18:28:50 dlw 2 1
c changed to F_ER codes. DLW
e
s 00068/00000/00000
d D 1.1 81/02/18 18:01:13 dlw 1 0
c date and time created 81/02/18 18:01:13 by dlw
e
u
U
t
T
I 1
/*
D 9
char id_endfile[] = "%W%";
E 9
I 9
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
 *
I 9
 *	%W%	%G%
 */

/*
E 9
 * endfile
 */

#include "fio.h"

D 3
char *endf = "endfile";
E 3
I 3
D 6
char endf[] = "endfile";
E 3
extern char *tmplate;
E 6
I 6
static char	endf[]	= "endfile";
E 6

D 6
f_end(a) alist *a;
E 6
I 6
f_end (a)
alist	*a;
E 6
{
D 6
	unit *b;
E 6
I 6
	unit	*b;
I 10
	int n;
E 10

E 6
	lfname = NULL;
	elist = NO;
	errflag = a->aerr;
	lunit = a->aunit;
D 2
	if (not_legal(lunit)) err(errflag,101,endf)
E 2
I 2
D 6
	if (not_legal(lunit)) err(errflag,F_ERUNIT,endf)
E 6
I 6
	if (not_legal(lunit))
		err (errflag, F_ERUNIT, endf)
E 6
E 2
	b = &units[lunit];
D 2
	if(!b->ufd) err(errflag,114,endf)
E 2
I 2
D 6
	if(!b->ufd) err(errflag,F_ERNOPEN,endf)
E 2
	if(b->uend) return(0);
E 6
I 6
D 10
	if (!b->ufd)
		err (errflag, F_ERNOPEN, endf)
E 10
I 10
	if(!b->ufd && (n = fk_open(READ, SEQ, FMT, (ftnint)lunit)) )
		err(errflag, n, endf);
E 10
	if (b->uend)
		return(0);
E 6
	lfname = b->ufnm;
	b->uend = YES;
D 6
	return(t_runc(b,errflag));
E 6
I 6
D 7
	return ( t_runc (b, errflag) );
E 7
I 7
	return ( t_runc (b, errflag, endf) );
E 7
E 6
}
D 8

D 6
t_runc(b,flag) unit *b; ioflag flag;
E 6
I 6
D 7
t_runc (b, flag)
E 7
I 7
t_runc (b, flag, str)
E 7
unit	*b;
ioflag	flag;
I 7
char	*str;
E 7
E 6
{
D 6
	char buf[128],nm[16];
	FILE *tmp;
	int n,m;
	long loc,len;
	fflush(b->ufd);
D 3
	if(b->uwrt) nowreading(b);
E 3
I 3
D 4
	if(b->uwrt && ! nowreading(b)) err(errflag, errno, endf);
E 4
E 3
	if(b->url || !b->useek || !b->ufnm) return(OK); /*don't trunc dir files*/
I 4
	if(b->uwrt && ! nowreading(b)) err(errflag, errno, endf);
E 4
	loc=ftell(b->ufd);
	fseek(b->ufd,0L,2);
	len=ftell(b->ufd);
D 5
	if (loc==len) return(OK);
E 5
I 5
	if (loc>=len) return(OK);
E 5
	strcpy(nm,tmplate);
	mktemp(nm);
	if(!(tmp=fopen(nm,"w"))) err(flag,errno,endf);
	fseek(b->ufd,0L,0);
	while (loc)
	{
		n=fread(buf,1,loc>sizeof(buf)?sizeof(buf):(int)loc,b->ufd);
		loc -= n;
		fwrite(buf,1,n,tmp);
	}
	fflush(tmp);
	for(n=0;n<10;n++)
	{
		if((m=fork())==-1) continue;
		else if(m==0)
		{
			execl("/bin/cp","cp",nm,b->ufnm,0);
			execl("/usr/bin/cp","cp",nm,b->ufnm,0);
D 2
			fatal(119,"no cp for trunc");
E 2
I 2
			fatal(F_ERSYS,"no cp for trunc");
E 2
		}
		wait(&m);
D 2
		if(m) err(flag,111,endf);
E 2
I 2
		if(m) err(flag,F_ERTRUNC,endf);
E 2
		fclose(tmp);
		unlink(nm);
		return(OK);
	}
D 2
	err(flag,111,endf);
E 2
I 2
	err(flag,F_ERTRUNC,endf);
E 6
I 6
	long	loc;

	if (b->uwrt)
		fflush (b->ufd);
	if (b->url || !b->useek || !b->ufnm)
		return (OK);	/* don't truncate direct access files, etc. */
	loc = ftell (b->ufd);
	if (truncate (b->ufnm, loc) != 0)
D 7
		err (flag, errno, endf)
E 7
I 7
		err (flag, errno, str)
	if (b->uwrt && ! nowreading(b))
		err (flag, errno, str)
E 7
	return (OK);
E 6
E 2
}
E 8
E 1
