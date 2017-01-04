h24546
s 00002/00000/00430
d D 5.2 85/07/30 16:40:31 jerry 14 13
c implement namelist
e
s 00007/00001/00423
d D 5.1 85/06/07 23:50:09 kre 13 12
c Add copyright
e
s 00033/00024/00391
d D 1.12 85/05/22 19:54:57 libs 12 11
c fix rep. factors with complex, fix R* followed by blank, 
c allow tab for blank.
e
s 00015/00005/00400
d D 1.11 85/05/21 19:24:53 libs 11 10
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00008/00000/00397
d D 1.10 85/05/07 20:54:07 libs 10 9
c Check for errors in input data.
e
s 00005/00000/00392
d D 1.9 85/03/28 10:33:29 ralph 9 8
c changes from donn@utah-cs.
e
s 00003/00003/00389
d D 1.8 85/01/09 10:50:54 dlw 8 7
c return EOF in e_rsle. DLW
e
s 00003/00003/00389
d D 1.7 83/05/11 10:50:08 dlw 7 6
c fixed e_rsle to look for \n; fixed l_L & l_CHAR to stop on /. DLW
e
s 00017/00001/00375
d D 1.6 83/05/06 10:42:08 dlw 6 5
c added check for null field following repeat count. DLW
e
s 00001/00000/00375
d D 1.5 83/04/25 18:01:35 dlw 5 4
c fixed record termination on l_L read. DLW
e
s 00001/00001/00374
d D 1.4 81/11/03 17:02:00 dlw 4 3
c fixed handling of multiple ,,, input. DLW
e
s 00002/00002/00373
d D 1.3 81/08/11 23:25:15 dlw 3 2
c added test for return val of now{r,w}. DLW
e
s 00007/00007/00368
d D 1.2 81/02/20 18:32:17 dlw 2 1
c changed to F_ER codes. DLW
e
s 00375/00000/00000
d D 1.1 81/02/18 18:01:28 dlw 1 0
c date and time created 81/02/18 18:01:28 by dlw
e
u
U
t
T
I 1
/*
D 13
char id_lread[] = "%W%";
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
 * list directed read
 */

#include "fio.h"
#include "lio.h"

#define SP 1
#define B  2
#define AP 4
#define EX 8
#define D 16
#define EIN 32
D 12
#define isblnk(x)	(ltab[x+1]&B)
#define issep(x)	(ltab[x+1]&SP)
#define isapos(x)	(ltab[x+1]&AP)
#define isexp(x)	(ltab[x+1]&EX)
E 12
I 12
#define isblnk(x)	(ltab[x+1]&B)	/* space, tab, newline */
#define issep(x)	(ltab[x+1]&SP)	/* space, tab, newline, comma */
#define isapos(x)	(ltab[x+1]&AP)	/* apost., quote mark, \02 */
#define isexp(x)	(ltab[x+1]&EX)	/* d, e, D, E */
E 12
#define isdigit(x)	(ltab[x+1]&D)
D 12
#define endlinp(x)	(ltab[x+1]&EIN)
E 12
I 12
#define endlinp(x)	(ltab[x+1]&EIN)	/* EOF, newline, / */
E 12

#define GETC(x) (x=(*getn)())

D 3
char *lrd = "list read";
E 3
I 3
D 11
char lrd[] = "list read";
E 3
char *lchar;
double lx,ly;
int ltype;
E 11
I 11
LOCAL char lrd[] = "list read";
LOCAL char *lchar;
LOCAL double lx,ly;
LOCAL int ltype;
E 11
int l_read(),t_getc(),ungetc();

D 11
char ltab[128+1] =
E 11
I 11
LOCAL char ltab[128+1] =
E 11
D 12
{		EIN, /* offset one for EOF */
/*   0- 15 */	0,0,AP,0,0,0,0,0,0,B,SP|B|EIN,0,0,0,0,0, /* ^B,TAB,NEWLINE */
E 12
I 12
{			EIN, 		/* offset one for EOF */
/*   0- 15 */	0,0,AP,0,0,0,0,0,0,SP|B,SP|B|EIN,0,0,0,0,0, /* ^B,TAB,NEWLINE */
E 12
/*  16- 31 */	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/*  32- 47 */	SP|B,0,AP,0,0,0,0,AP,0,0,0,0,SP,0,0,EIN, /* space,",',comma,/ */
/*  48- 63 */	D,D,D,D,D,D,D,D,D,D,0,0,0,0,0,0,	/* digits 0-9 */
/*  64- 79 */	0,0,0,0,EX,EX,0,0,0,0,0,0,0,0,0,0,	/* D,E */
/*  80- 95 */	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
/*  96-111 */	0,0,0,0,EX,EX,0,0,0,0,0,0,0,0,0,0,	/* d,e */
/* 112-127 */	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

s_rsle(a) cilist *a;	/* start read sequential list external */
{
	int n;
	reading = YES;
I 14
	formatted = LISTDIRECTED;
	fmtbuf = "ext list io";
E 14
	if(n=c_le(a,READ)) return(n);
	l_first = YES;
	lquit = NO;
	lioproc = l_read;
	getn = t_getc;
	ungetn = ungetc;
	leof = curunit->uend;
	lcount = 0;
I 6
	ltype = NULL;
E 6
D 3
	if(curunit->uwrt) nowreading(curunit);
E 3
I 3
	if(curunit->uwrt && ! nowreading(curunit)) err(errflag, errno, lrd)
E 3
	return(OK);
}

I 11
LOCAL
E 11
t_getc()
{	int ch;
	if(curunit->uend) return(EOF);
	if((ch=getc(cf))!=EOF) return(ch);
	if(feof(cf))
	{	curunit->uend = YES;
		leof = EOF;
	}
	else clearerr(cf);
	return(EOF);
}

e_rsle()
{
	int ch;
D 8
	if(curunit->uend) return(OK);
E 8
I 8
	if(curunit->uend) return(EOF);
E 8
D 7
	while(!endlinp(GETC(ch)));
E 7
I 7
	while(GETC(ch) != '\n' && ch != EOF);
E 7
D 8
	return(OK);
E 8
I 8
	return(ch==EOF?EOF:OK);
E 8
}

l_read(number,ptr,len,type) ftnint *number,type; flex *ptr; ftnlen len;
{	int i,n,ch;
	double *yy;
	float *xx;
	for(i=0;i<*number;i++)
	{
		if(leof) err(endflag, EOF, lrd)
		if(l_first)
		{	l_first = NO;
			while(isblnk(GETC(ch)));	/* skip blanks */
			(*ungetn)(ch,cf);
		}
		else if(lcount==0)		/* repeat count == 0 ? */
		{	ERR(t_sep());  /* look for non-blank, allow 1 comma */
			if(lquit) return(OK);	/* slash found */
		}
		switch((int)type)
		{
		case TYSHORT:
		case TYLONG:
		case TYREAL:
		case TYDREAL:
			ERR(l_R(1));
			break;
		case TYCOMPLEX:
		case TYDCOMPLEX:
			ERR(l_C());
			break;
		case TYLOGICAL:
			ERR(l_L());
			break;
		case TYCHAR:
			ERR(l_CHAR());
			break;
		}
I 10
		
 		/* peek at next character; it should be separator or new line */
 		GETC(ch); (*ungetn)(ch,cf);
 		if(!issep(ch) && !endlinp(ch)) {
 			while(GETC(ch)!= '\n' && ch != EOF);
 			err(errflag,F_ERLIO,lrd);
 		}
 
E 10
		if(lquit) return(OK);
		if(leof) err(endflag,EOF,lrd)
		else if(external && ferror(cf)) err(errflag,errno,lrd)
		if(ltype) switch((int)type)
		{
		case TYSHORT:
			ptr->flshort=lx;
			break;
		case TYLOGICAL:
I 9
			if(len == sizeof(short))
				ptr->flshort = lx;
			else
				ptr->flint = lx;
			break;
E 9
		case TYLONG:
			ptr->flint=lx;
			break;
		case TYREAL:
			ptr->flreal=lx;
			break;
		case TYDREAL:
			ptr->fldouble=lx;
			break;
		case TYCOMPLEX:
			xx=(float *)ptr;
			*xx++ = ly;
			*xx = lx;
			break;
		case TYDCOMPLEX:
			yy=(double *)ptr;
			*yy++ = ly;
			*yy = lx;
			break;
		case TYCHAR:
			b_char(lchar,(char *)ptr,len);
			break;
		}
		if(lcount>0) lcount--;
D 6
		ptr = (char *)ptr + len;
E 6
I 6
		ptr = (flex *)((char *)ptr + len);
E 6
	}
	return(OK);
}

I 11
LOCAL
E 11
lr_comm()
{	int ch;
	if(lcount) return(lcount);
	ltype=NULL;
	while(isblnk(GETC(ch)));
I 4
	(*ungetn)(ch,cf);
E 4
	if(ch==',')
	{	lcount=1;
		return(lcount);
	}
D 4
	(*ungetn)(ch,cf);
E 4
	if(ch=='/')
	{	lquit = YES;
		return(lquit);
	}
	else
		return(OK);
}

I 11
LOCAL
E 11
get_repet()
{	char ch;
	double lc;
	if(isdigit(GETC(ch)))
	{	(*ungetn)(ch,cf);
		rd_int(&lc);
		lcount = (int)lc;
		if(GETC(ch)!='*')
			if(leof) return(EOF);
D 2
			else return(109);
E 2
I 2
			else return(F_ERREPT);
E 2
	}
	else
	{	lcount = 1;
		(*ungetn)(ch,cf);
	}
	return(OK);
}

I 11
LOCAL
E 11
l_R(flg) int flg;
{	double a,b,c,d;
	int da,db,dc,dd;
	int i,ch,sign=0;
	a=b=c=d=0;
	da=db=dc=dd=0;
D 12
	if(flg && lr_comm()) return(OK);
	da=rd_int(&a);	/* repeat count ? */
	if(GETC(ch)=='*')
E 12
I 12

	if( flg )		/* real */
E 12
	{
D 2
		if (a <= 0.) return(122);
E 2
I 2
D 12
		if (a <= 0.) return(F_ERNREP);
E 2
		lcount=(int)a;
I 6
		if (nullfld()) return(OK);	/* could be R* */
E 6
		db=rd_int(&b);	/* whole part of number */
E 12
I 12
		if(lr_comm()) return(OK);
		da=rd_int(&a);	/* repeat count ? */
		if(GETC(ch)=='*')
		{
			if (a <= 0.) return(F_ERNREP);
			lcount=(int)a;
			if (nullfld()) return(OK);	/* could be R* */
			db=rd_int(&b);	/* whole part of number */
		}
		else
		{	(*ungetn)(ch,cf);
			db=da;
			b=a;
			lcount=1;
		}
E 12
	}
D 12
	else
	{	(*ungetn)(ch,cf);
		db=da;
		b=a;
		lcount=1;
E 12
I 12
	else		   /* complex */
	{
		db=rd_int(&b);
E 12
	}
I 12

E 12
	if(GETC(ch)=='.' && isdigit(GETC(ch)))
	{	(*ungetn)(ch,cf);
		dc=rd_int(&c);	/* fractional part of number */
	}
	else
	{	(*ungetn)(ch,cf);
		dc=0;
		c=0.;
	}
	if(isexp(GETC(ch)))
		dd=rd_int(&d);	/* exponent */
	else if (ch == '+' || ch == '-')
	{	(*ungetn)(ch,cf);
		dd=rd_int(&d);
	}
	else
	{	(*ungetn)(ch,cf);
		dd=0;
	}
	if(db<0 || b<0)
	{	sign=1;
		b = -b;
	}
	for(i=0;i<dc;i++) c/=10.;
	b=b+c;
	if (dd > 0)
	{	for(i=0;i<d;i++) b *= 10.;
		for(i=0;i< -d;i++) b /= 10.;
	}
	lx=sign?-b:b;
	ltype=TYLONG;
	return(OK);
}

I 11
LOCAL
E 11
rd_int(x) double *x;
{	int ch,sign=0,i=0;
	double y=0.0;
	if(GETC(ch)=='-') sign = -1;
	else if(ch=='+') sign=0;
	else (*ungetn)(ch,cf);
	while(isdigit(GETC(ch)))
	{	i++;
		y=10*y + ch-'0';
	}
	(*ungetn)(ch,cf);
	if(sign) y = -y;
	*x = y;
	return(y==0.0?sign:i); /* 0:[+]&&y==0, -1:-&&y==0, >0:#digits&&y!=0 */
}

I 11
LOCAL
E 11
l_C()
{	int ch,n;
	if(lr_comm()) return(OK);
	if(n=get_repet()) return(n);		/* get repeat count */
I 6
	if (nullfld()) return(OK);		/* could be R* */
E 6
D 2
	if(GETC(ch)!='(') err(errflag,112,"no (")
E 2
I 2
	if(GETC(ch)!='(') err(errflag,F_ERLIO,"no (")
E 2
	while(isblnk(GETC(ch)));
	(*ungetn)(ch,cf);
	l_R(0);		/* get real part */
	ly = lx;
	if(t_sep()) return(EOF);
	l_R(0);		/* get imag part */
	while(isblnk(GETC(ch)));
D 2
	if(ch!=')') err(errflag,112,"no )")
E 2
I 2
	if(ch!=')') err(errflag,F_ERLIO,"no )")
E 2
	ltype = TYCOMPLEX;
	return(OK);
}

I 11
LOCAL
E 11
l_L()
{
	int ch,n;
	if(lr_comm()) return(OK);
	if(n=get_repet()) return(n);		/* get repeat count */
I 6
	if (nullfld()) return(OK);		/* could be R* */
E 6
	if(GETC(ch)=='.') GETC(ch);
	switch(ch)
	{
	case 't':
	case 'T':
		lx=1;
		break;
	case 'f':
	case 'F':
		lx=0;
		break;
	default:
D 12
		if(isblnk(ch) || issep(ch))
E 12
I 12
		if(issep(ch))
E 12
		{	(*ungetn)(ch,cf);
			lx=0;
			return(OK);
		}
		else if(ch==EOF) return(EOF);
D 2
		else	err(errflag,112,"logical not T or F");
E 2
I 2
		else	err(errflag,F_ERLIO,"logical not T or F");
E 2
	}
	ltype=TYLOGICAL;
D 7
	while(!issep(GETC(ch)) && !isblnk(ch) && ch!='\n' && ch!=EOF);
E 7
I 7
D 12
	while(!issep(GETC(ch)) && !isblnk(ch) && !endlinp(ch));
E 12
I 12
	while(!issep(GETC(ch)) && !endlinp(ch));
E 12
E 7
I 5
	(*ungetn)(ch,cf);
E 5
	return(OK);
}

#define BUFSIZE	128
I 11
LOCAL
E 11
l_CHAR()
{	int ch,size,i,n;
	char quote,*p;
	if(lr_comm()) return(OK);
	if(n=get_repet()) return(n);		/* get repeat count */
I 6
	if (nullfld()) return(OK);		/* could be R* */
E 6
	if(isapos(GETC(ch))) quote=ch;
D 12
	else if(isblnk(ch) || issep(ch) || ch==EOF || ch=='\n')
E 12
I 12
	else if(issep(ch) || ch==EOF || ch=='\n')
E 12
	{	if(ch==EOF) return(EOF);
		(*ungetn)(ch,cf);
		return(OK);
	}
	else
	{	quote = '\0';	/* to allow single word non-quoted */
		(*ungetn)(ch,cf);
	}
	ltype=TYCHAR;
	if(lchar!=NULL) free(lchar);
	size=BUFSIZE-1;
	p=lchar=(char *)malloc(BUFSIZE);
D 2
	if(lchar==NULL) err(errflag,113,lrd)
E 2
I 2
	if(lchar==NULL) err(errflag,F_ERSPACE,lrd)
E 2
	for(i=0;;)
	{	while( ( (quote && GETC(ch)!=quote) ||
D 7
			(!quote && !issep(GETC(ch)) && !isblnk(ch) ) )
E 7
I 7
D 12
			(!quote && !issep(GETC(ch)) && !isblnk(ch) && !endlinp(ch)) )
E 12
I 12
			(!quote && !issep(GETC(ch)) && !endlinp(ch)) )
E 12
E 7
			&& ch!='\n' && ch!=EOF && ++i<size )
				*p++ = ch;
		if(i==size)
		{
		newone:
			size += BUFSIZE;
			lchar=(char *)realloc(lchar, size+1);
D 2
			if(lchar==NULL) err(errflag,113,lrd)
E 2
I 2
			if(lchar==NULL) err(errflag,F_ERSPACE,lrd)
E 2
			p=lchar+i-1;
			*p++ = ch;
		}
		else if(ch==EOF) return(EOF);
		else if(ch=='\n')
		{	if(*(p-1) == '\\') *(p-1) = ch;
			else if(!quote)
			{	*p = '\0';
				(*ungetn)(ch,cf);
				return(OK);
			}
		}
		else if(quote && GETC(ch)==quote)
		{	if(++i<size) *p++ = ch;
			else goto newone;
		}
		else
		{	(*ungetn)(ch,cf);
			*p = '\0';
			return(OK);
		}
	}
}

I 11
LOCAL
E 11
t_sep()
{
	int ch;
	while(isblnk(GETC(ch)));
	if(leof) return(EOF);
	if(ch=='/')
	{	lquit = YES;
		(*ungetn)(ch,cf);
		return(OK);
	}
	if(issep(ch)) while(isblnk(GETC(ch)));
	if(leof) return(EOF);
	(*ungetn)(ch,cf);
	return(OK);
I 6
}

I 11
LOCAL
E 11
nullfld()	/* look for null field following a repeat count */
{
	int	ch;

D 12
	while(isblnk(GETC(ch)));
E 12
I 12
	GETC(ch);
E 12
	(*ungetn)(ch,cf);
	if (issep(ch) || endlinp(ch))
		return(YES);
	return(NO);
E 6
}
E 1
