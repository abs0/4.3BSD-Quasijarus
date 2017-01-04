h27019
s 00007/00001/00298
d D 5.1 85/06/07 23:58:18 kre 14 13
c Add copyright
e
s 00006/00000/00293
d D 1.11 85/05/21 19:25:37 libs 13 12
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00008/00004/00285
d D 1.10 85/05/07 20:52:56 libs 12 9
c Donn Seeley's patch to make logical*2 work.
e
s 00019/00001/00288
d R 1.10 85/02/14 22:33:01 libs 11 9
c Print reserved operand as '****' instead of getting an interrupt.
e
s 00019/00001/00288
d R 1.10 85/02/14 22:22:57 libs 10 9
c Print reserved operand as '****' instead of getting interrupt.
e
s 00010/00006/00279
d D 1.9 85/02/14 21:29:26 libs 9 8
c Recognize compiled formats, change syl[] members to shorts and 
c don't generate STACK operators for rep. factors for editing 
c terms so compiled formats will be shorter & execute faster.
e
s 00003/00000/00282
d D 1.8 84/10/03 17:14:43 dlw 8 7
c force '0' fill on E/D output of 0.  DLW
e
s 00001/00000/00281
d D 1.7 83/05/16 14:47:22 dlw 7 6
c fixed wr_mvcur to test for cursor > 0. DLW
e
s 00011/00004/00269
d D 1.6 83/05/11 11:55:13 dlw 6 5
c fixed TL; non-destructive X; +nPE output. DLW
e
s 00006/00005/00267
d D 1.5 83/04/25 17:25:24 dlw 5 4
c made exponent char conform to ANSI. DLW
e
s 00001/00001/00271
d D 1.4 82/07/17 00:51:17 dlw 4 3
c fixed uplim test in G conversion. DLW
e
s 00001/00001/00271
d D 1.3 81/04/19 20:04:33 dlw 3 2
c added zero fill on output with BZ. DLW
e
s 00003/00003/00269
d D 1.2 81/02/20 18:35:07 dlw 2 1
c changed to F_ER codes. DLW
e
s 00272/00000/00000
d D 1.1 81/02/18 18:02:07 dlw 1 0
c date and time created 81/02/18 18:02:07 by dlw
e
u
U
t
T
I 1
/*
D 14
char id_wrtfmt[] = "%W%";
E 14
I 14
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 14
 *
I 14
 *	%W%	%G%
 */

/*
E 14
 * formatted write routines
 */

#include "fio.h"
D 2
#include "fmt.h"
E 2
I 2
#include "format.h"
E 2

extern char *icvt();
I 9
extern char *s_init;
E 9

#define abs(x) (x<0?-x:x)

w_ed(p,ptr,len) char *ptr; struct syl *p; ftnlen len;
{	int n;
	if(cursor && (n=wr_mvcur())) return(n);
	switch(p->op)
	{
	case I:
	case IM:
		return(wrt_IM(ptr,p->p1,p->p2,len));
	case L:
D 12
		return(wrt_L(ptr,p->p1));
E 12
I 12
		return(wrt_L(ptr,p->p1,len));
E 12
	case A:
D 9
		p->p1 = len;	/* cheap trick */
E 9
I 9
		return(wrt_AW(ptr,len,len));
E 9
	case AW:
		return(wrt_AW(ptr,p->p1,len));
	case D:
I 9
		return(wrt_E(ptr,p->p1,p->p2,2,len,'d'));
E 9
	case DE:
I 5
D 9
		return(wrt_E(ptr,p->p1,p->p2,p->p3,len,'d'));
E 9
I 9
		return(wrt_E(ptr,p->p1,(p->p2)&0xff,((p->p2)>>8)&0xff,len,'d'));
E 9
E 5
	case E:
I 9
		return(wrt_E(ptr,p->p1,p->p2,2,len,'e'));
E 9
	case EE:
D 5
		return(wrt_E(ptr,p->p1,p->p2,p->p3,len));
E 5
I 5
D 9
		return(wrt_E(ptr,p->p1,p->p2,p->p3,len,'e'));
E 9
I 9
		return(wrt_E(ptr,p->p1,(p->p2)&0xff,((p->p2)>>8)&0xff,len,'e'));
E 9
E 5
	case G:
I 9
		return(wrt_G(ptr,p->p1,p->p2,2,len));
E 9
	case GE:
D 9
		return(wrt_G(ptr,p->p1,p->p2,p->p3,len));
E 9
I 9
		return(wrt_G(ptr,p->p1,(p->p2)&0xff,((p->p2)>>8)&0xff,len));
E 9
	case F:
		return(wrt_F(ptr,p->p1,p->p2,len));
	default:
D 2
		return(errno=100);
E 2
I 2
		return(errno=F_ERFMT);
E 2
	}
}

w_ned(p,ptr) char *ptr; struct syl *p;
{
	switch(p->op)
	{
	case SLASH:
		return((*donewrec)());
	case T:
		if(p->p1) cursor = p->p1 - recpos - 1;
#ifndef KOSHER
		else cursor = 8*p->p2 - recpos%8;	/* NOT STANDARD FORT */
#endif
		tab = YES;
		return(OK);
	case TL:
		cursor -= p->p1;
I 6
		if ((recpos + cursor) < 0) cursor = -recpos;	/* ANSI req'd */
E 6
		tab = YES;
		return(OK);
	case TR:
	case X:
		cursor += p->p1;
D 6
		tab = (p->op == TR);
E 6
I 6
		/* tab = (p->op == TR); this would implement destructive X */
		tab = YES;
E 6
		return(OK);
	case APOS:
D 9
		return(wrt_AP(p->p1));
E 9
I 9
		return(wrt_AP(&s_init[p->p1]));
E 9
	case H:
D 9
		return(wrt_H(p->p1,p->p2));
E 9
I 9
		return(wrt_H(p->p1,&s_init[p->p2]));
E 9
	default:
D 2
		return(errno=100);
E 2
I 2
		return(errno=F_ERFMT);
E 2
	}
}

I 13
LOCAL
E 13
wr_mvcur()
{	int n;
	if(tab) return((*dotab)());
I 7
	if (cursor < 0) return(errno=F_ERSEEK);
E 7
	while(cursor--) PUT(' ')
	return(cursor=0);
}

I 13
LOCAL
E 13
wrt_IM(ui,w,m,len) uint *ui; ftnlen len;
{	int ndigit,sign,spare,i,xsign,n;
	long x;
	char *ans;
	if(sizeof(short)==len) x=ui->is;
/*	else if(len == sizeof(char)) x = ui->ic; */
	else x=ui->il;
	if(x==0 && m==0)
	{	for(i=0;i<w;i++) PUT(' ')
		return(OK);
	}
	ans=icvt(x,&ndigit,&sign);
	if(sign || cplus) xsign=1;
	else xsign=0;
	if(ndigit+xsign>w || m+xsign>w)
	{	for(i=0;i<w;i++) PUT('*')
		return(OK);
	}
	if(ndigit>=m)
		spare=w-ndigit-xsign;
	else
		spare=w-m-xsign;
	for(i=0;i<spare;i++) PUT(' ')
	if(sign) PUT('-')
	else if(cplus) PUT('+')
	for(i=0;i<m-ndigit;i++) PUT('0')
	for(i=0;i<ndigit;i++) PUT(*ans++)
	return(OK);
}

I 13
LOCAL
E 13
wrt_AP(p)
{	char *s,quote;
	int n;
	if(cursor && (n=wr_mvcur())) return(n);
	s=(char *)p;
	quote = *s++;
	for(; *s; s++)
	{	if(*s!=quote) PUT(*s)
		else if(*++s==quote) PUT(*s)
		else return(OK);
	}
	return(OK);
}

I 13
LOCAL
E 13
wrt_H(a,b)
{	char *s=(char *)b;
	int n;
	if(cursor && (n=wr_mvcur())) return(n);
	while(a--) PUT(*s++)
	return(OK);
}

D 12
wrt_L(l,len) ftnint *l;
E 12
I 12
wrt_L(l,width,len) uint *l; ftnlen len;
E 12
{	int i,n;
D 12
	for(i=0;i<len-1;i++) PUT(' ')
	if(*l) PUT('t')
E 12
I 12
	for(i=0;i<width-1;i++) PUT(' ')
	if(len == sizeof (short))
		i = l->is;
	else
		i = l->il;
	if(i) PUT('t')
E 12
	else PUT('f')
	return(OK);
}

I 13
LOCAL
E 13
wrt_AW(p,w,len) char * p; ftnlen len;
{	int n;
	while(w>len)
	{	w--;
		PUT(' ')
	}
	while(w-- > 0)
		PUT(*p++)
	return(OK);
}

D 5
wrt_E(p,w,d,e,len) ufloat *p; ftnlen len;
{	char *s,ex[4],expch;
E 5
I 5
wrt_E(p,w,d,e,len,expch) ufloat *p; ftnlen len; char expch;
{	char *s,ex[4];
E 5
	int dd,dp,sign,i,delta,pad,n;
	char *ecvt();
D 5
	expch=(len==sizeof(float)?'e':'d');
E 5
I 5

E 5
	if((len==sizeof(float)?p->pf:p->pd)==0.0)
	{
I 8
		n = cblank;
		cblank = 1;	/* force '0' fill */
E 8
		wrt_F(p,w-(e+2),d,len);
I 8
		cblank = n;
E 8
		PUT(expch)
		PUT('+')
/*		for(i=0;i<(e-1);i++)PUT(' ')
deleted		PUT('0')
 */
/* added */	for(i=0;i<e;i++) PUT('0')
		return(OK);
	}
D 6
	dd = d + scale;
E 6
I 6
	if (scale > 0) {	/* insane ANSI requirement */
		dd = d + 1;
		d = dd - scale;
	} else
		dd = d + scale;
	if (dd <= 0 || d < 0) goto E_badfield;
E 6
	s=ecvt( (len==sizeof(float)?(double)p->pf:p->pd) ,dd,&dp,&sign);
	delta = 3+e;
	if(sign||cplus) delta++;
	pad=w-(delta+d)-(scale>0? scale:0);
D 6
	if(pad<0)
	{	for(i=0;i<w;i++) PUT('*')
E 6
I 6
	if(pad<0) {
E_badfield:
		for(i=0;i<w;i++) PUT('*')
E 6
		return(OK);
	}
	for(i=0;i<(pad-(scale<=0?1:0));i++) PUT(' ')
	if(sign) PUT('-')
	else if(cplus) PUT('+')
	if(scale<=0 && pad) PUT('0')
	if(scale<0 && scale > -d)
	{
		PUT('.')
		for(i=0;i<-scale;i++)
			PUT('0')
		for(i=0;i<d+scale;i++)
			PUT(*s++)
	}
	else
	{
		if(scale>0)
			for(i=0;i<scale;i++)
				PUT(*s++)
		PUT('.')
		for(i=0;i<d;i++)
			PUT(*s++)
	}
	dp -= scale;
	sprintf(ex,"%d",abs(dp));
	if((pad=strlen(ex))>e)
	{	if(pad>(++e))
		{	PUT(expch)
			for(i=0;i<e;i++) PUT('*')
			return(OK);
		}
	}
	else PUT(expch)
	PUT(dp<0?'-':'+')
	for(i=0;i<(e-pad);i++) PUT('0')  /* was ' ' */
	s= &ex[0];
	while(*s) PUT(*s++)
	return(OK);
}

I 13
LOCAL
E 13
wrt_G(p,w,d,e,len) ufloat *p; ftnlen len;
{	double uplim = 1.0, x;
	int i,oldscale,n,j,ne;
	x=(len==sizeof(float)?(double)p->pf:p->pd);
	i=d;
	if(x==0.0) goto zero;
	x = abs(x);
	if(x>=0.1)
	{
		for(i=0; i<=d; i++, uplim*=10.0)
D 4
		{	if(x>uplim) continue;
E 4
I 4
		{	if(x>=uplim) continue;
E 4
zero:			oldscale=scale;
			scale=0;
			ne = e+2;
			if(n = wrt_F(p,w-ne,d-i,len)) return(n);
			for(j=0; j<ne; j++) PUT(' ')
			scale=oldscale;
			return(OK);
		}
		/* falling off the bottom implies E format */
	}
D 5
	return(wrt_E(p,w,d,e,len));
E 5
I 5
	return(wrt_E(p,w,d,e,len,'e'));
E 5
}

wrt_F(p,w,d,len) ufloat *p; ftnlen len;
{	int i,delta,dp,sign,n,nf;
	double x;
	char *s,*fcvt();
	x= (len==sizeof(float)?(double)p->pf:p->pd);
	if(scale && x!=0.0)
	{	if(scale>0)
			for(i=0;i<scale;i++) x*=10;
		else	for(i=0;i<-scale;i++) x/=10;
	}
	s=fcvt(x,d,&dp,&sign);
/*	if(-dp>=d) sign=0; ?? */
	delta=1;
	if(sign || cplus) delta++;
	nf = w - (d + delta + (dp>0?dp:0));
	if(nf<0)
	{
		for(i=0;i<w;i++) PUT('*')
		return(OK);
	}
	if(nf>0) for(i=0; i<(nf-(dp<=0?1:0)); i++) PUT(' ')
	if(sign) PUT('-')
	else if(cplus) PUT('+')
	if(dp>0) for(i=0;i<dp;i++) PUT(*s++)
	else if(nf>0) PUT('0')
	PUT('.')
	for(i=0; i< -dp && i<d; i++) PUT('0')
	for(;i<d;i++)
D 3
	{	if(x==0.0) PUT(' ')	/* exactly zero */
E 3
I 3
	{	if(x==0.0 && !cblank) PUT(' ')	/* exactly zero */
E 3
		else if(*s) PUT(*s++)
		else PUT('0')
	}
	return(OK);
}
E 1
