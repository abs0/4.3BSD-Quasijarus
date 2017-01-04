h64168
s 00007/00001/00331
d D 5.1 85/06/07 23:53:50 kre 13 12
c Add copyright
e
s 00004/00001/00328
d D 1.12 85/06/04 22:31:11 libs 12 11
c have formatted logical read check for errors.
e
s 00007/00000/00322
d D 1.11 85/05/21 19:25:13 libs 11 10
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00004/00003/00318
d D 1.10 85/05/07 20:52:40 libs 10 9
c Donn Seeley's patch to make logical*2 work.
e
s 00097/00051/00224
d D 1.9 85/02/19 19:38:02 libs 9 8
c Correct rd_I rd_F
e
s 00005/00000/00270
d D 1.8 85/02/19 18:41:40 libs 8 7
c Catch infinite loops in formats.
e
s 00003/00003/00267
d D 1.7 85/02/14 22:23:44 libs 7 6
c Improve error messages.
e
s 00006/00003/00264
d D 1.6 85/02/14 21:29:09 libs 6 5
c Recognize compiled formats, change syl[] members to shorts and 
c don't generate STACK operators for rep. factors for editing 
c terms so compiled formats will be shorter & execute faster.
e
s 00003/00001/00264
d D 1.5 83/05/16 14:46:43 dlw 5 4
c fixed TL/TR/X to always use tab. DLW
e
s 00001/00000/00264
d D 1.4 83/05/11 11:36:35 dlw 4 3
c fixed TL to never be negative. DLW
e
s 00035/00024/00229
d D 1.3 81/04/28 13:53:23 dlw 3 2
c re-enabled 'read into hollerith field in format' feature. DLW
e
s 00007/00007/00246
d D 1.2 81/02/20 18:33:35 dlw 2 1
c changed to F_ER codes. DLW
e
s 00253/00000/00000
d D 1.1 81/02/18 18:01:49 dlw 1 0
c date and time created 81/02/18 18:01:49 by dlw
e
u
U
t
T
I 1
/*
D 13
char id_rdfmt[] = "%W%";
E 13
I 13
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 13
 *
I 13
 *	%W%	%G%
 */

/*
E 13
 * formatted read routines
 */

#include "fio.h"
D 2
#include "fmt.h"
E 2
I 2
#include "format.h"
E 2

D 9
#define isdigit(c)	(c>='0' && c<='9')
#define isalpha(c)	(c>='a' && c<='z')

E 9
I 6
extern char *s_init;
I 9
extern int low_case[256];
E 9
I 8
extern int used_data;
E 8

E 6
rd_ed(p,ptr,len) char *ptr; struct syl *p; ftnlen len;
{	int n;
	if(cursor && (n=rd_mvcur())) return(n);
	switch(p->op)
	{
	case I:
	case IM:
		n = (rd_I(ptr,p->p1,len));
		break;
	case L:
D 10
		n = (rd_L(ptr,p->p1));
E 10
I 10
		n = (rd_L(ptr,p->p1,len));
E 10
		break;
	case A:
D 6
		p->p1 = len;	/* cheap trick */
E 6
I 6
		n = (rd_AW(ptr,len,len));
		break;
E 6
	case AW:
		n = (rd_AW(ptr,p->p1,len));
		break;
	case E:
	case EE:
	case D:
	case DE:
	case G:
	case GE:
	case F:
		n = (rd_F(ptr,p->p1,p->p2,len));
		break;
	default:
D 2
		return(errno=100);
E 2
I 2
		return(errno=F_ERFMT);
E 2
	}
	if (n < 0)
	{
		if(feof(cf)) return(EOF);
		n = errno;
		clearerr(cf);
	}
	return(n);
}

rd_ned(p,ptr) char *ptr; struct syl *p;
{
	switch(p->op)
	{
D 3
/*	case APOS:
/*		return(rd_POS(p->p1));
/*	case H:
/*		return(rd_H(p->p1,p->p2));	*/
E 3
I 3
#ifndef	KOSHER
	case APOS:					/* NOT STANDARD F77 */
D 6
		return(rd_POS((char *)p->p1));
E 6
I 6
		return(rd_POS(&s_init[p->p1]));
E 6
	case H:						/* NOT STANDARD F77 */
D 6
		return(rd_H(p->p1,(char *)p->p2));
E 6
I 6
		return(rd_H(p->p1,&s_init[p->p2]));
E 6
#endif
E 3
	case SLASH:
		return((*donewrec)());
	case TR:
	case X:
		cursor += p->p1;
D 5
		tab = (p->op==TR);
E 5
I 5
		/* tab = (p->op==TR); This voids '..,tl6,1x,..' sequences */
		tab = YES;
E 5
		return(OK);
	case T:
		if(p->p1) cursor = p->p1 - recpos - 1;
#ifndef KOSHER
		else cursor = 8*p->p2 - recpos%8;	/* NOT STANDARD FORT */
#endif
		tab = YES;
		return(OK);
	case TL:
		cursor -= p->p1;
I 4
		if ((recpos + cursor) < 0) cursor = -recpos;	/* ANSI req'd */
E 4
		tab = YES;
		return(OK);
	default:
D 2
		return(errno=100);
E 2
I 2
		return(errno=F_ERFMT);
E 2
	}
}

I 11
LOCAL
E 11
rd_mvcur()
{	int n;
	if(tab) return((*dotab)());
I 5
	if (cursor < 0) return(errno=F_ERSEEK);
E 5
	while(cursor--) if((n=(*getn)()) < 0) return(n);
	return(cursor=0);
}

I 11
LOCAL
E 11
rd_I(n,w,len) ftnlen len; uint *n;
{	long x=0;
D 9
	int i,sign=0,ch,c;
E 9
I 9
	int i,sign=0,ch,c,sign_ok=YES;
E 9
	for(i=0;i<w;i++)
	{
		if((ch=(*getn)())<0) return(ch);
D 9
		switch(ch=lcase(ch))
E 9
I 9
		switch(ch)
E 9
		{
		case ',': goto done;
D 9
		case '+': break;
		case '-':
			sign=1;
			break;
E 9
I 9
		case '-': sign=1;		/* and fall thru */
		case '+': if(sign_ok == NO) return(errno=F_ERRICHR);
			  sign_ok = NO;
			  break;
E 9
		case ' ':
			if(cblank) x *= radix;
			break;
D 9
		case '\n':  goto done;
E 9
I 9
		case '\n':  if(cblank) {
				x *= radix;
				break;
			    } else {
				goto done;
			    }
E 9
		default:
D 9
			if(isdigit(ch))
			{	if ((c=(ch-'0')) < radix)
				{	x = (x * radix) + c;
					break;
				}
E 9
I 9
			sign_ok = NO;
			if( (c = ch-'0')>=0 && c<radix )
			{	x = (x * radix) + c;
				break;
E 9
			}
D 9
			else if(isalpha(ch))
			{	if ((c=(ch-'a'+10)) < radix)
				{	x = (x * radix) + c;
					break;
				}
E 9
I 9
			else if( (c = low_case[ch]-'a'+10)>=0 && c<radix )
			{	x = (x * radix) + c;
				break;
E 9
			}
D 2
			return(errno=115);
E 2
I 2
D 7
			return(errno=F_ERRDCHR);
E 7
I 7
			return(errno=F_ERRICHR);
E 7
E 2
		}
	}
done:
	if(sign) x = -x;
	if(len==sizeof(short)) n->is=x;
	else n->il=x;
	return(OK);
}

I 11
LOCAL
E 11
D 10
rd_L(n,w) ftnint *n;
E 10
I 10
rd_L(n,w,len) uint *n; ftnlen len;
E 10
D 12
{	int ch,i,v = -1;
E 12
I 12
{	int ch,i,v = -1, period=0;
E 12
	for(i=0;i<w;i++)
	{	if((ch=(*getn)()) < 0) return(ch);
D 9
		if((ch=lcase(ch))=='t' && v==-1) v=1;
E 9
I 9
		if((ch=low_case[ch])=='t' && v==-1) v=1;
E 9
		else if(ch=='f' && v==-1) v=0;
I 12
		else if(ch=='.' && !period) period++;
		else if(ch==' ' || ch=='\t') ;
E 12
		else if(ch==',') break;
I 12
		else if(v==-1) return(errno=F_ERLOGIF);
E 12
	}
D 2
	if(v==-1) return(errno=116);
E 2
I 2
	if(v==-1) return(errno=F_ERLOGIF);
E 2
D 10
	*n=v;
E 10
I 10
	if(len==sizeof(short)) n->is=v;
	else n->il=v;
E 10
	return(OK);
}

I 11
LOCAL
E 11
rd_F(p,w,d,len) ftnlen len; ufloat *p;
{	double x,y;
D 9
	int i,sx,sz,ch,dot,ny,z,sawz;
E 9
I 9
	int i,sx,sz,ch,dot,ny,z,sawz,mode, sign_ok=YES;
E 9
	x=y=0;
	sawz=z=ny=dot=sx=sz=0;
I 9
	/* modes:	0 in initial blanks,
			2 blanks plus sign
			3 found a digit
	 */
	mode = 0;

E 9
	for(i=0;i<w;)
	{	i++;
		if((ch=(*getn)())<0) return(ch);
D 9
		ch=lcase(ch);
		if(ch==' ' && !cblank || ch=='+') continue;
		else if(ch=='-') sx=1;
		else if(ch<='9' && ch>='0')
E 9
I 9

		if(ch==' ') {	/* blank */
			if(cblank && (mode==2)) x *= 10;
		} else if(ch<='9' && ch>='0') { /* digit */
			mode = 2;
E 9
			x=10*x+ch-'0';
D 9
		else if(ch=='e' || ch=='d' || ch=='.')
E 9
I 9
		} else if(ch=='.') {
E 9
			break;
D 9
		else if(cblank && ch==' ') x*=10;
		else if(ch==',')
		{	i=w;
			break;
E 9
I 9
		} else if(ch=='e' || ch=='d' || ch=='E' || ch=='D') {
			goto exponent;
		} else if(ch=='+' || ch=='-') {
			if(mode==0) {  /* sign before digits */
				if(ch=='-') sx=1;
				mode = 1;
			} else if(mode==1) {  /* two signs before digits */
				return(errno=F_ERRFCHR);
			} else { /* sign after digits, weird but standard!
				    	means exponent without 'e' or 'd' */
				    goto exponent;
			}
		} else if(ch==',') {
			goto done;
		} else if(ch=='\n') {
			if(cblank && (mode==2)) x *= 10;
		} else {
			return(errno=F_ERRFCHR);
E 9
		}
D 2
		else if(ch!='\n') return(errno=115);
E 2
I 2
D 7
		else if(ch!='\n') return(errno=F_ERRDCHR);
E 7
I 7
D 9
		else if(ch!='\n') return(errno=F_ERRFCHR);
E 9
E 7
E 2
	}
I 9
	/* get here if out of characters to scan or found a period */
E 9
	if(ch=='.') dot=1;
D 9
	while(i<w && ch!='e' && ch!='d' && ch!='+' && ch!='-')
E 9
I 9
	while(i<w)
E 9
	{	i++;
		if((ch=(*getn)())<0) return(ch);
D 9
		ch = lcase(ch);
		if(ch<='9' && ch>='0')
E 9
I 9

		if(ch<='9' && ch>='0') {
E 9
			y=10*y+ch-'0';
D 9
		else if(cblank && ch==' ')
			y *= 10;
		else if(ch==',') {i=w; break;}
		else if(ch==' ') continue;
		else continue;
		ny++;
E 9
I 9
			ny++;
		} else if(ch==' ' || ch=='\n') {
			if(cblank) {
				y*= 10;
				ny++;
			}
		} else if(ch==',') {
			goto done;
		} else if(ch=='d' || ch=='e' || ch=='+' || ch=='-' || ch=='D' || ch=='E') {
			break;
		} else {
			return(errno=F_ERRFCHR);
		}
E 9
	}
D 9
	if(ch=='-') sz=1;
E 9
I 9
	/*	now for the exponent.
	 *	mode=3 means seen digit or sign of exponent.
	 *	either out of characters to scan or 
	 *		ch is '+', '-', 'd', or 'e'.
	 */
exponent:
	if(ch=='-' || ch=='+') {
		if(ch=='-') sz=1;
		mode = 3;
	} else {
		mode = 2;
	}

E 9
	while(i<w)
	{	i++;
		sawz=1;
		if((ch=(*getn)())<0) return(ch);
D 9
		ch = lcase(ch);
		if(ch=='-') sz=1;
		else if(ch<='9' && ch>='0')
E 9
I 9

		if(ch<='9' && ch>='0') {
			mode = 3;
E 9
			z=10*z+ch-'0';
D 9
		else if(cblank && ch==' ')
			z *= 10;
		else if(ch==',') break;
		else if(ch==' ') continue;
		else if(ch=='+') continue;
D 2
		else if(ch!='\n') return(errno=115);
E 2
I 2
D 7
		else if(ch!='\n') return(errno=F_ERRDCHR);
E 7
I 7
		else if(ch!='\n') return(errno=F_ERRFCHR);
E 9
I 9
		} else if(ch=='+' || ch=='-') {
			if(mode==3 ) return(errno=F_ERRFCHR);
			mode = 3;
			if(ch=='-') sz=1;
		} else if(ch == ' ' || ch=='\n') {
			if(cblank) z *=10;
		} else if(ch==',') {
			break;
		} else {
			return(errno=F_ERRFCHR);
		}
E 9
E 7
E 2
	}
I 9
done:
E 9
	if(!dot)
		for(i=0;i<d;i++) x /= 10;
	for(i=0;i<ny;i++) y /= 10;
	x=x+y;
	if(sz)
		for(i=0;i<z;i++) x /=10;
	else	for(i=0;i<z;i++) x *= 10;
	if(sx) x = -x;
	if(!sawz)
	{
		for(i=scale;i>0;i--) x /= 10;
		for(i=scale;i<0;i++) x *= 10;
	}
	if(len==sizeof(float)) p->pf=x;
	else p->pd=x;
	return(OK);
}

I 11
LOCAL
E 11
rd_AW(p,w,len) char *p; ftnlen len;
{	int i,ch;
	if(w >= len)
	{
		for(i=0;i<w-len;i++) GET(ch);
		for(i=0;i<len;i++)
		{	GET(ch);
			*p++=VAL(ch);
		}
	}
	else
	{
		for(i=0;i<w;i++)
		{	GET(ch);
			*p++=VAL(ch);
		}
		for(i=0;i<len-w;i++) *p++=' ';
	}
	return(OK);
}

/* THIS IS NOT ALLOWED IN THE NEW STANDARD 'CAUSE IT'S WEIRD */
I 11
LOCAL
E 11
D 3
/*rd_H(n,s) char *s;
/*{	int i,ch;
/*	for(i=0;i<n;i++)
/*		if((ch=(*getn)())<0) return(ch);
/*		else if(ch=='\n') for(;i<n;i++) *s++ = ' ';
/*		else *s++ = ch;
/*	return(OK);
/*}
*/
/*rd_POS(s) char *s;
/*{	char quote;
/*	int ch;
/*	quote= *s++;
/*	for(;*s;s++)
/*		if(*s==quote && *(s+1)!=quote) break;
/*		else if((ch=(*getn)())<0) return(ch);
/*		else *s = ch=='\n'?' ':ch;
/*	return(OK);
/*}
*/
E 3
I 3
rd_H(n,s) char *s;
{	int i,ch = 0;
I 8

	used_data = YES;
E 8
	for(i=0;i<n;i++)
	{	if (ch != '\n')
			GET(ch);
		if (ch == '\n')
			*s++ = ' ';
		else
			*s++ = ch;
	}
	return(OK);
}

I 11
LOCAL
E 11
rd_POS(s) char *s;
{	char quote;
	int ch = 0;
I 8

	used_data = YES;
E 8
	quote = *s++;
	while(*s)
	{	if(*s==quote && *(s+1)!=quote)
			break;
		if (ch != '\n')
			GET(ch);
		if (ch == '\n')
			*s++ = ' ';
		else
			*s++ = ch;
	}
	return(OK);
}
E 3
E 1
