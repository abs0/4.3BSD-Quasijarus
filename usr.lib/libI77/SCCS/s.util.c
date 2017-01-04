h51688
s 00007/00001/00068
d D 5.1 85/06/07 23:56:55 kre 9 8
c Add copyright
e
s 00001/00036/00068
d D 1.8 85/05/21 19:25:31 libs 8 7
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00002/00002/00102
d D 1.7 83/04/25 01:34:24 dlw 7 6
c changed def of io flags. DLW
e
s 00004/00002/00100
d D 1.6 83/04/21 23:03:49 dlw 6 5
c changed i66 to separate flags for ccntrl & blzero. DLW
e
s 00026/00009/00076
d D 1.5 81/08/11 23:26:21 dlw 5 4
c return success/fail on nowreading/nowwriting(). DLW
e
s 00002/00002/00083
d D 1.4 81/04/29 09:46:22 dlw 4 3
c added 'blank=zero' to f66 init. DLW
e
s 00003/00002/00082
d D 1.3 81/04/28 19:20:51 dlw 3 2
c added ability to init lu6 with carriage control (init66_). DLW
e
s 00000/00000/00084
d D 1.2 81/02/20 18:34:43 dlw 2 1
c changed to F_ER codes. DLW
e
s 00084/00000/00000
d D 1.1 81/02/18 18:02:04 dlw 1 0
c date and time created 81/02/18 18:02:04 by dlw
e
u
U
t
T
I 1
/*
D 9
char id_util[] = "%W%";
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
 * utility routines
 */

D 8
#include <sys/types.h>
#include <sys/stat.h>
E 8
#include "fio.h"

I 6
extern short	ccntrl_, blzero_;
E 6

D 3
ini_std(u,F,w) FILE *F;
E 3
I 3
D 6
ini_std(u,F,w,i66) FILE *F;
E 6
I 6
D 8
ini_std(u,F,w) FILE *F;
E 6
E 3
{	unit *p;
	p = &units[u];
	p->ufd = F;
	p->ufnm = NULL;
	p->useek = canseek(F);
	p->ufmt = YES;
	p->uwrt = (w==WRITE)? YES : NO;
D 3
	p->ublnk = p->uscrtch = p->uprnt = p->uend = NO;
E 3
I 3
D 4
	p->ublnk = p->uscrtch = p->uend = NO;
	p->uprnt = (i66!=0)? YES : NO;
E 4
I 4
	p->uscrtch = p->uend = NO;
D 6
	p->ublnk = p->uprnt = (i66!=0)? YES : NO;
E 6
I 6
D 7
	p->ublnk = blzero_;
	p->uprnt = ccntrl_;
E 7
I 7
	p->ublnk = blzero;
	p->uprnt = ccntrl;
E 7
E 6
E 4
E 3
	p->url = 0;
	p->uinode = finode(F);
}

canseek(f) FILE *f; /*SYSDEP*/
{	struct stat x;
	return( (fstat(fileno(f),&x)==0) &&
	(x.st_nlink > 0 /*!pipe*/) && !isatty(fileno(f)) );
}

E 8
nowreading(x) unit *x;
{
D 5
	long loc;
	x->uwrt = NO;
	loc=ftell(x->ufd);
	freopen(x->ufnm,"r",x->ufd);
	fseek(x->ufd,loc,0);
E 5
I 5
	return(now_acc(x,"r"));
E 5
}

nowwriting(x) unit *x;
{
I 5
	return(now_acc(x,"a"));
}

D 8
now_acc(x,mode)
E 8
I 8
LOCAL now_acc(x,mode)
E 8
unit *x; char *mode;
{
E 5
	long loc;
D 5
	x->uwrt = YES;
	loc=ftell(x->ufd);
	freopen(x->ufnm,"a",x->ufd);
	fseek(x->ufd,loc,0);
E 5
I 5

	if (!x->ufnm)
	{
		errno = EBADF;
		return(NO);
	}
	if (x->useek)
		loc=ftell(x->ufd);
	if (freopen(x->ufnm,mode,x->ufd))
	{
		if (x->useek)
			fseek(x->ufd,loc,0);
		x->uwrt = (*mode=='a');
		return(YES);
	}
	if (x->ufd = fopen(x->ufnm, (*mode=='a')? "r":"a"))
		if (x->useek)
			fseek(x->ufd,loc,0);
	return(NO);
E 5
}

g_char(a,alen,b) char *a,*b; ftnlen alen;
{	char *x=a+alen-1, *y=b+alen-1;
	while (x >= a  &&  *x == ' ') {x--; y--;}
	*(y+1) = '\0';
	while (x >= a) *y-- = *x--;
}

b_char(from, to, tolen) char *from, *to; ftnlen tolen;
{	int i=0;
	while (*from && i < tolen) {
		*to++ = *from++;
		i++;
	}
	while (i++ < tolen)
		*to++ = ' ';
D 8
}

inode(a) char *a;
{	struct stat x;
	if(stat(a,&x)==0) return(x.st_ino);
	else return(-1);
}

finode(f) FILE *f;
{	struct stat x;
	if(fstat(fileno(f),&x)==0) return(x.st_ino);
	else return(-1);
E 8
}

char
last_char(f) FILE *f;
{
	fseek(f,-2L,1);
	if(ftell(f)) return(getc(f));
	else return('\n');
}
E 1
