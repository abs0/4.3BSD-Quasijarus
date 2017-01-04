h10484
s 00002/00003/00217
d D 5.3 87/07/27 17:11:16 bostic 9 8
c checked in for jerry
e
s 00034/00025/00186
d D 5.2 85/07/30 16:40:39 jerry 8 7
c implement namelist
e
s 00007/00001/00204
d D 5.1 85/06/07 23:50:54 kre 7 6
c Add copyright
e
s 00005/00001/00200
d D 1.6 85/06/07 00:29:34 jerry 6 5
c refix short integer logical writes.
e
s 00011/00001/00190
d D 1.5 85/05/21 19:25:02 libs 5 4
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00002/00002/00189
d D 1.4 83/04/25 17:28:00 dlw 4 3
c added expch arg to wrt_E call. DLW
e
s 00002/00001/00189
d D 1.3 81/08/11 23:25:36 dlw 3 2
c added test for return val of now{r,w}. DLW
e
s 00001/00001/00189
d D 1.2 81/02/20 18:32:55 dlw 2 1
c changed to F_ER codes. DLW
e
s 00190/00000/00000
d D 1.1 81/02/18 18:01:38 dlw 1 0
c date and time created 81/02/18 18:01:38 by dlw
e
u
U
t
T
I 1
/*
D 7
char id_lwrite[] = "%W%";
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
 * list directed write
 */

#include "fio.h"
#include "lio.h"

int l_write(), t_putc();
I 3
D 5
char lwrt[] = "list write";
E 5
I 5
LOCAL char lwrt[] = "list write";
E 5
E 3

s_wsle(a) cilist *a;
{
	int n;
	reading = NO;
I 8
	formatted = LISTDIRECTED;
	fmtbuf = "ext list io";
E 8
	if(n=c_le(a,WRITE)) return(n);
	putn = t_putc;
	lioproc = l_write;
	line_len = LINE;
	curunit->uend = NO;
	leof = NO;
D 3
	if(!curunit->uwrt) nowwriting(curunit);
E 3
I 3
	if(!curunit->uwrt && ! nowwriting(curunit)) err(errflag, errno, lwrt)
E 3
	return(OK);
}

I 5
LOCAL
E 5
t_putc(c) char c;
{
	if(c=='\n') recpos=0;
	else recpos++;
	putc(c,cf);
	return(OK);
}

e_wsle()
{	int n;
	PUT('\n')
	return(OK);
}

l_write(number,ptr,len,type) ftnint *number,type; flex *ptr; ftnlen len;
{
	int i,n;
	ftnint x;
	float y,z;
	double yd,zd;
	float *xx;
	double *yy;
	for(i=0;i< *number; i++)
	{
I 8
		if( formatted == NAMELIST && i != 0 ) PUT(',');
E 8
		switch((int)type)
		{
		case TYSHORT:
			x=ptr->flshort;
			goto xint;
		case TYLONG:
			x=ptr->flint;
D 8
	xint:		ERR(lwrt_I(x));
E 8
I 8
	xint:		ERRCHK(lwrt_I(x));
E 8
			break;
		case TYREAL:
D 8
			ERR(lwrt_F(ptr->flreal));
E 8
I 8
			ERRCHK(lwrt_F(ptr->flreal));
E 8
			break;
		case TYDREAL:
D 8
			ERR(lwrt_D(ptr->fldouble));
E 8
I 8
			ERRCHK(lwrt_D(ptr->fldouble));
E 8
			break;
		case TYCOMPLEX:
			xx= &(ptr->flreal);
			y = *xx++;
			z = *xx;
D 8
			ERR(lwrt_C(y,z));
E 8
I 8
			ERRCHK(lwrt_C(y,z));
E 8
			break;
		case TYDCOMPLEX:
			yy = &(ptr->fldouble);
			yd= *yy++;
			zd = *yy;
D 8
			ERR(lwrt_DC(yd,zd));
E 8
I 8
			ERRCHK(lwrt_DC(yd,zd));
E 8
			break;
		case TYLOGICAL:
D 6
			ERR(lwrt_L(ptr->flint));
E 6
I 6
			if(len == sizeof(short))
				x = ptr->flshort;
			else
				x = ptr->flint;
D 8
			ERR(lwrt_L(x));
E 8
I 8
			ERRCHK(lwrt_L(x));
E 8
E 6
			break;
		case TYCHAR:
D 8
			ERR(lwrt_A((char *)ptr,len));
E 8
I 8
			ERRCHK(lwrt_A((char *)ptr,len));
E 8
			break;
		default:
D 2
			fatal(119,"unknown type in lwrite");
E 2
I 2
			fatal(F_ERSYS,"unknown type in lwrite");
E 2
		}
		ptr = (flex *)((char *)ptr + len);
	}
	return(OK);
I 8

got_err:
	err( n>0?errflag:endflag,  n,
		formatted==LISTDIRECTED?"list io":"name list io");
E 8
}

I 5
LOCAL
E 5
lwrt_I(in) ftnint in;
{	int n;
	char buf[16],*p;
	sprintf(buf,"  %ld",(long)in);
D 8
	if(n=chk_len(LINTW)) return(n);
E 8
I 8
	chk_len(LINTW);
E 8
	for(p=buf;*p;) PUT(*p++)
	return(OK);
}

I 5
LOCAL
E 5
lwrt_L(ln) ftnint ln;
{	int n;
D 8
	if(n=chk_len(LLOGW)) return(n);
E 8
I 8
	chk_len(LLOGW);
E 8
	return(wrt_L(&ln,LLOGW));
}

I 5
LOCAL
E 5
lwrt_A(p,len) char *p; ftnlen len;
{	int i,n;
D 8
	if(n=chk_len(LSTRW)) return(n);
	PUT(' ')
	PUT(' ')
	for(i=0;i<len;i++) PUT(*p++)
E 8
I 8
D 9
	chk_len(LSTRW);
E 9
	if(formatted == LISTDIRECTED)
	{
D 9
		PUT(' ')
		PUT(' ')
E 9
I 9
		chk_len(len);
E 9
		for(i=0;i<len;i++) PUT(*p++)
	}
	else
	{
I 9
		chk_len(len+2);
E 9
		PUT('\'')
		for(i=0;i<len;i++) PUT(*p++)
		PUT('\'')
	}
E 8
	return(OK);
}

I 5
LOCAL
E 5
lwrt_F(fn) float fn;
{	int d,n; float x; ufloat f;
	if(fn==0.0) return(lwrt_0());
	f.pf = fn;
	d = width(fn);
D 8
	if(n=chk_len(d)) return(n);
E 8
I 8
	chk_len(d);
E 8
	if(d==LFW)
	{
		scale = 0;
		for(d=LFD,x=abs(fn);x>=1.0;x/=10.0,d--);
		return(wrt_F(&f,LFW,d,(ftnlen)sizeof(float)));
	}
	else
	{
		scale = 1;
D 4
		return(wrt_E(&f,LEW,LED-scale,LEE,(ftnlen)sizeof(float)));
E 4
I 4
		return(wrt_E(&f,LEW,LED-scale,LEE,(ftnlen)sizeof(float),'e'));
E 4
	}
}

I 5
LOCAL
E 5
lwrt_D(dn) double dn;
{	int d,n; double x; ufloat f;
	if(dn==0.0) return(lwrt_0());
	f.pd = dn;
	d = dwidth(dn);
D 8
	if(n=chk_len(d)) return(n);
E 8
I 8
	chk_len(d);
E 8
	if(d==LDFW)
	{
		scale = 0;
		for(d=LDFD,x=abs(dn);x>=1.0;x/=10.0,d--);
		return(wrt_F(&f,LDFW,d,(ftnlen)sizeof(double)));
	}
	else
	{
		scale = 1;
D 4
		return(wrt_E(&f,LDEW,LDED-scale,LDEE,(ftnlen)sizeof(double)));
E 4
I 4
		return(wrt_E(&f,LDEW,LDED-scale,LDEE,(ftnlen)sizeof(double),'d'));
E 4
	}
}

I 5
LOCAL
E 5
lwrt_C(a,b) float a,b;
{	int n;
D 8
	if(n=chk_len(LCW)) return(n);
E 8
I 8
	chk_len(LCW);
E 8
	PUT(' ')
	PUT(' ')
	PUT('(')
	if(n=lwrt_F(a)) return(n);
	PUT(',')
	if(n=lwrt_F(b)) return(n);
	PUT(')')
	return(OK);
}

I 5
LOCAL
E 5
lwrt_DC(a,b) double a,b;
{	int n;
D 8
	if(n=chk_len(LDCW)) return(n);
E 8
I 8
	chk_len(LDCW);
E 8
	PUT(' ')
	PUT(' ')
	PUT('(')
	if(n=lwrt_D(a)) return(n);
	PUT(',')
	if(n=lwrt_D(b)) return(n);
	PUT(')')
	return(OK);
}

I 5
LOCAL
E 5
lwrt_0()
{	int n; char *z = "  0.";
D 8
	if(n=chk_len(4)) return(n);
E 8
I 8
	chk_len(4);
E 8
	while(*z) PUT(*z++)
D 8
	return(OK);
}

I 5
LOCAL
E 5
chk_len(w)
{	int n;
	if(recpos+w > line_len) PUT('\n')
E 8
	return(OK);
}
E 1
