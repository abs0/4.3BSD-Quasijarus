h15782
s 00002/00002/00086
d D 5.2 85/07/30 16:19:32 jerry 10 8
c Unit does not exist or not connected is no-op, not error.
e
s 00000/00000/00088
d R 5.2 85/07/30 16:17:26 jerry 9 8
c Unit does not exist or not connected s/b no-op.
e
s 00007/00001/00081
d D 5.1 85/06/07 23:42:32 kre 8 7
c Add copyright
e
s 00018/00011/00064
d D 1.7 85/05/21 19:24:08 libs 7 6
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00004/00003/00071
d D 1.6 83/08/23 15:38:59 dlw 6 5
c t_runc now sets "reading". DLW
e
s 00002/00002/00072
d D 1.5 83/04/29 11:26:45 dlw 5 4
c fixed close on normal exit to obey uscrtch. DLW
e
s 00005/00001/00069
d D 1.4 83/04/14 22:58:06 dlw 4 3
c check for legal unit on flush_(). DLW
e
s 00004/00002/00066
d D 1.3 81/09/14 20:49:52 dlw 3 2
c added error return for t_runc, and truncate of stderr on close. DLW
e
s 00004/00004/00064
d D 1.2 81/02/20 18:25:51 dlw 2 1
c changed to F_ER codes. DLW
e
s 00068/00000/00000
d D 1.1 81/02/18 18:00:42 dlw 1 0
c date and time created 81/02/18 18:00:42 by dlw
e
u
U
t
T
I 1
/*
D 8
char id_close[] = "%W%";
E 8
I 8
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 8
 *
I 8
 *	%W%	%G%
 */

/*
E 8
D 7
 * close.c  -  f77 file close, flush, exit routines
E 7
I 7
 * f_clos(): f77 file close
 * t_runc(): truncation
 * f_exit(): I/O library exit routines
E 7
 */

#include "fio.h"

D 5
#define FROM_OPEN	'\1'
E 5
I 5
static char FROM_OPEN[] =	"\2";
I 6
static char clse[]	=	"close";
E 6
E 5

f_clos(a) cllist *a;
{	unit *b;
I 3
	int n;

E 3
	lfname = NULL;
	elist = NO;
	external = YES;
	errflag = a->cerr;
	lunit = a->cunit;
D 2
	if(not_legal(lunit)) err(errflag,101,"close");
E 2
I 2
D 6
	if(not_legal(lunit)) err(errflag,F_ERUNIT,"close");
E 6
I 6
D 10
	if(not_legal(lunit)) err(errflag,F_ERUNIT,clse);
E 10
I 10
	if(not_legal(lunit)) return(OK);
E 10
E 6
E 2
D 5
	if(lunit==STDERR && (!a->csta || *a->csta != FROM_OPEN))
E 5
I 5
	if(lunit==STDERR && (!a->csta || *a->csta != FROM_OPEN[0]))
E 5
D 2
		err(errflag,101,"can't close stderr");
E 2
I 2
		err(errflag,F_ERUNIT,"can't close stderr");
E 2
	b= &units[lunit];
D 2
	if(!b->ufd) err(errflag,114,"close");
E 2
I 2
D 6
	if(!b->ufd) err(errflag,F_ERNOPEN,"close");
E 6
I 6
D 10
	if(!b->ufd) err(errflag,F_ERNOPEN,clse);
E 10
I 10
	if(!b->ufd) return(OK);
E 10
E 6
E 2
D 5
	if(a->csta)
E 5
I 5
	if(a->csta && *a->csta != FROM_OPEN[0])
E 5
		switch(lcase(*a->csta))
		{
	delete:
		case 'd':
			fclose(b->ufd);
			if(b->ufnm) unlink(b->ufnm); /*SYSDEP*/
			break;
		default:
	keep:
		case 'k':
D 3
			if(b->uwrt) t_runc(b,errflag);
E 3
I 3
D 6
			if(b->uwrt && (n=t_runc(b,errflag))) return(n);
E 6
I 6
			if(b->uwrt && (n=t_runc(b,errflag,clse))) return(n);
E 6
E 3
			fclose(b->ufd);
			break;
		}
	else if(b->uscrtch) goto delete;
	else goto keep;
	if(b->ufnm) free(b->ufnm);
	b->ufnm=NULL;
	b->ufd=NULL;
	return(OK);
}

f_exit()
{
	ftnint lu, dofirst = YES;
	cllist xx;
	xx.cerr=1;
D 3
	xx.csta=NULL;
E 3
I 3
D 5
	xx.csta="\1";
E 5
I 5
	xx.csta=FROM_OPEN;
E 5
E 3
	for(lu=STDOUT; (dofirst || lu!=STDOUT); lu = ++lu % MXUNIT)
	{
		xx.cunit=lu;
		f_clos(&xx);
		dofirst = NO;
	}
}

D 7
ftnint
flush_(u) ftnint *u;
E 7
I 7
t_runc (b, flag, str)
unit	*b;
ioflag	flag;
char	*str;
E 7
{
D 4
	FILE *F = units[*u].ufd;
E 4
I 4
D 7
	FILE *F;
E 7
I 7
	long	loc;
E 7

D 7
	if(not_legal(*u))
		return(F_ERUNIT);
	F = units[*u].ufd;
E 4
	if(F)
		return(fflush(F));
	else
D 2
		return(114);
E 2
I 2
		return(F_ERNOPEN);
E 7
I 7
	if (b->uwrt)
		fflush (b->ufd);
	if (b->url || !b->useek || !b->ufnm)
		return (OK);	/* don't truncate direct access files, etc. */
	loc = ftell (b->ufd);
	if (truncate (b->ufnm, loc) != 0)
		err (flag, errno, str)
	if (b->uwrt && ! nowreading(b))
		err (flag, errno, str)
	return (OK);
E 7
E 2
}
E 1
