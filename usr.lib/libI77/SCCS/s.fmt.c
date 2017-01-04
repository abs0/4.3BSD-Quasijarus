h45566
s 00004/00000/00377
d D 5.2 86/10/22 17:07:18 mckusick 12 11
c add tahoe
e
s 00007/00001/00370
d D 5.1 85/06/07 23:47:09 kre 11 10
c Add copyright
e
s 00011/00002/00360
d D 1.9 85/05/21 19:24:39 libs 10 9
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00016/00008/00346
d D 1.8 85/02/14 23:06:45 libs 9 7
c Substitute low_case[] for lcase() to speed up execution.
e
s 00015/00008/00346
d R 1.8 85/02/14 22:19:55 libs 8 7
c Speed up lcase by using low_case[]
e
s 00050/00027/00304
d D 1.7 85/02/14 21:28:48 libs 7 6
c Recognize compiled formats, change syl[] members to shorts and 
c don't generate STACK operators for rep. factors for editing 
c terms so compiled formats will be shorter & execute faster.
e
s 00007/00004/00324
d D 1.6 85/01/29 10:25:52 dlw 6 5
c changed 'B' to use control struct 'ublnk' at run time. DLW
e
s 00048/00019/00280
d D 1.5 84/06/21 10:29:51 ralph 5 4
c changes from dlw to fix I/O hanging on illegal fmt specs.
e
s 00003/00001/00296
d D 1.4 83/05/05 01:24:42 dlw 4 3
c allow '+' before nP,nR,nX,etc. DLW
e
s 00001/00000/00296
d D 1.3 83/04/30 12:54:43 dlw 3 2
c fixed 'B' to revert to cblank. DLW
e
s 00003/00003/00293
d D 1.2 81/02/20 18:29:34 dlw 2 1
c changed to F_ER codes. DLW
e
s 00296/00000/00000
d D 1.1 81/02/18 18:02:24 dlw 1 0
c date and time created 81/02/18 18:02:24 by dlw
e
u
U
t
T
I 1
/*
D 11
char id_fmt[] = "%W%";
E 11
I 11
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 11
 *
I 11
 *	%W%	%G%
 */

/*
E 11
 * fortran format parser
 */

#include "fio.h"
D 2
#include "fmt.h"
E 2
I 2
#include "format.h"
E 2

#define isdigit(x)	(x>='0' && x<='9')
#define isspace(s)	(s==' ')
#define skip(s)		while(isspace(*s)) s++

#ifdef interdata
#define SYLMX 300
#endif

#ifdef pdp11
#define SYLMX 300
#endif

#ifdef vax
#define SYLMX 300
#endif

I 12
#ifdef tahoe
#define SYLMX 300
#endif

E 12
D 7
struct syl syl[SYLMX];
int parenlvl,pc,revloc;
E 7
I 7
D 10
struct syl syl_vec[SYLMX];
E 10
I 10
LOCAL struct syl syl_vec[SYLMX];
E 10
struct syl *syl_ptr;
D 9
int parenlvl,revloc;
E 9
I 9
D 10
int parenlvl,revloc, low_case[256];
E 10
I 10
LOCAL int parenlvl,revloc;
int low_case[256];
E 10
E 9
short pc;
E 7
char *f_s(), *f_list(), *i_tem(), *gt_num(), *ap_end();
I 7
char *s_init;
E 7

D 7
pars_f(s) char *s;
E 7
I 7
pars_f()
E 7
{
I 7
	short *s_ptr;
	long  *l_ptr;
I 9
	int i;
E 9

I 9
	/* first time, initialize low_case[] */
	if( low_case[1] == 0 ) {
	    for(i = 0; i<256; i++) low_case[i]=i;
	    for(i = 'A'; i<='Z'; i++) low_case[i]=i-'A'+'a';
	}

E 9
E 7
	parenlvl=revloc=pc=0;
I 9

E 9
D 7
	return((f_s(s,0)==FMTERR)? ERROR : OK);
E 7
I 7
	s_ptr = (short *) fmtbuf;
	if( *s_ptr == FMT_COMP ) {
		/* already compiled - copy value of pc */
		pc = *(s_ptr+1);
		/* get address of the format */
		l_ptr = (long *) fmtbuf;
		fmtbuf = s_init = (char *) *(l_ptr+1);
		/* point syl_ptr to the compiled format */
		syl_ptr = (struct syl *) (l_ptr + 2);
		return(OK);
	} else {
		syl_ptr = syl_vec;
		s_init = fmtbuf;
		return((f_s(fmtbuf,0)==FMTERR)? ERROR : OK);
	}
E 7
}

I 10
LOCAL
E 10
char *f_s(s,curloc) char *s;
{
	skip(s);
	if(*s++!='(')
	{
		fmtptr = s;
		return(FMTERR);
	}
	if(parenlvl++ ==1) revloc=curloc;
	op_gen(RET,curloc,0,0,s);
	if((s=f_list(s))==FMTERR)
	{
		return(FMTERR);
	}
	skip(s);
	return(s);
}

I 10
LOCAL
E 10
char *f_list(s) char *s;
{
	while (*s)
	{	skip(s);
		if((s=i_tem(s))==FMTERR) return(FMTERR);
		skip(s);
		if(*s==',') s++;
		else if(*s==')')
		{	if(--parenlvl==0)
D 5
			{
E 5
				op_gen(REVERT,revloc,0,0,s);
D 5
			}
			else	op_gen(GOTO,0,0,0,s);
E 5
I 5
			else
				op_gen(GOTO,0,0,0,s);
E 5
			return(++s);
		}
	}
	fmtptr = s;
	return(FMTERR);
}

I 10
LOCAL
E 10
char *i_tem(s) char *s;
{	char *t;
	int n,curloc;
	if(*s==')') return(s);
D 5
	if(ne_d(s,&t)) return(t);
	if(e_d(s,&t)) return(t);
E 5
I 5
	if ((n=ne_d(s,&t))==FMTOK)
		return(t);
	else if (n==FMTERR)
		return(FMTERR);
	if ((n=e_d(s,&t))==FMTOK)
		return(t);
	else if (n==FMTERR)
		return(FMTERR);
E 5
	s=gt_num(s,&n);
I 5
	if (n == 0) { fmtptr = s; return(FMTERR); }
E 5
	curloc = op_gen(STACK,n,0,0,s);
	return(f_s(s,curloc));
}

I 10
LOCAL
E 10
ne_d(s,p) char *s,**p;
{	int n,x,sign=0,pp1,pp2;
D 9
	switch(lcase(*s))
E 9
I 9
	switch(low_case[*s])
E 9
	{
	case ':': op_gen(COLON,(int)('\n'),0,0,s); break;
#ifndef KOSHER
	case '$': op_gen(DOLAR,(int)('\0'),0,0,s); break;  /*** NOT STANDARD FORTRAN ***/
#endif
	case 'b':
D 9
		switch(lcase(*(s+1)))
E 9
I 9
		switch(low_case[*(s+1)])
E 9
		{
I 3
D 6
			case '\0': op_gen(BN,cblank,0,0,s); break;
E 3
			case 'z': s++; op_gen(BZ,1,0,0,s); break;
			case 'n': s++;
			default:  op_gen(BN,0,0,0,s); break;
E 6
I 6
			case 'n': s++; op_gen(BNZ,0,0,0,s); break;
			case 'z': s++; op_gen(BNZ,1,0,0,s); break;
#ifndef KOSHER
			default: op_gen(B,0,0,0,s); break;  /*** NOT STANDARD FORTRAN ***/
#else
			default: fmtptr = s; return(FMTUNKN);
#endif
E 6
		}
		break;
	case 's':
D 9
		switch(lcase(*(s+1)))
E 9
I 9
		switch(low_case[*(s+1)])
E 9
		{
			case 'p': s++; x=SP; pp1=1; pp2=1; break;
#ifndef KOSHER
			case 'u': s++; x=SU; pp1=0; pp2=0; break;  /*** NOT STANDARD FORTRAN ***/
#endif
			case 's': s++; x=SS; pp1=0; pp2=1; break;
			default:  x=S; pp1=0; pp2=1; break;
		}
		op_gen(x,pp1,pp2,0,s);
		break;
	case '/': op_gen(SLASH,0,0,0,s); break;
D 4
	case '-': sign=1; s++;	/*OUTRAGEOUS CODING TRICK*/
E 4
I 4

	case '-': sign=1;	/* OUTRAGEOUS CODING */
	case '+': s++;		/* OUTRAGEOUS CODING */
E 4
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		s=gt_num(s,&n);
D 9
		switch(lcase(*s))
E 9
I 9
		switch(low_case[*s])
E 9
		{
		case 'p': if(sign) n= -n; op_gen(P,n,0,0,s); break;
#ifndef KOSHER
		case 'r': if(n<=1)		/*** NOT STANDARD FORTRAN ***/
D 5
			{	fmtptr = s; return(FMTERR); }
E 5
I 5
			{	fmtptr = --s; return(FMTERR); }
E 5
			op_gen(R,n,0,0,s); break;
		case 't': op_gen(T,0,n,0,s); break;	/* NOT STANDARD FORT */
#endif
		case 'x': op_gen(X,n,0,0,s); break;
D 7
		case 'h': op_gen(H,n,(int)(s+1),0,s);
E 7
I 7
		case 'h': op_gen(H,n,(s+1)-s_init,0,s);
E 7
			s+=n;
			break;
D 5
		default: fmtptr = s; return(0);
E 5
I 5
		default: fmtptr = s; return(FMTUNKN);
E 5
		}
		break;
	case GLITCH:
	case '"':
D 7
	case '\'': op_gen(APOS,(int)s,0,0,s);
E 7
I 7
	case '\'': op_gen(APOS,s-s_init,0,0,s);
E 7
		*p = ap_end(s);
		return(FMTOK);
	case 't':
D 9
		switch(lcase(*(s+1)))
E 9
I 9
		switch(low_case[*(s+1)])
E 9
		{
			case 'l': s++; x=TL; break;
			case 'r': s++; x=TR; break;
			default:  x=T; break;
		}
		if(isdigit(*(s+1))) {s=gt_num(s+1,&n); s--;}
D 5
#ifndef KOSHER
E 5
I 5
#ifdef KOSHER
		else { fmtptr = s; return(FMTERR); }
#else
E 5
		else n = 0;	/* NOT STANDARD FORTRAN, should be error */
#endif
D 5
#ifdef KOSHER
		fmtptr = s; return(FMTERR);
#endif
E 5
		op_gen(x,n,1,0,s);
		break;
	case 'x': op_gen(X,1,0,0,s); break;
	case 'p': op_gen(P,0,0,0,s); break;
#ifndef KOSHER
	case 'r': op_gen(R,10,1,0,s); break;  /*** NOT STANDARD FORTRAN ***/
#endif

D 5
	default: fmtptr = s; return(0);
E 5
I 5
	default: fmtptr = s; return(FMTUNKN);
E 5
	}
	s++;
	*p=s;
	return(FMTOK);
}

I 10
LOCAL
E 10
e_d(s,p) char *s,**p;
D 7
{	int n,w,d,e,x=0;
E 7
I 7
{	int n,w,d,e,x=0, rep_count;
E 7
	char *sv=s;
	char c;
D 7
	s=gt_num(s,&n);
I 5
	if (n == 0) goto ed_err;
E 5
	op_gen(STACK,n,0,0,s);
E 7
I 7
	s=gt_num(s,&rep_count);
	if (rep_count == 0) goto ed_err;
E 7
D 9
	c = lcase(*s); s++;
E 9
I 9
	c = low_case[*s]; s++;
E 9
	switch(c)
	{
	case 'd':
	case 'e':
	case 'g':
		s = gt_num(s, &w);
D 5
		if (w==0) break;
E 5
I 5
		if (w==0) goto ed_err;
E 5
		if(*s=='.')
		{	s++;
			s=gt_num(s,&d);
		}
		else d=0;
D 9
		if(lcase(*s) == 'e'
E 9
I 9
		if(low_case[*s] == 'e'
E 9
#ifndef KOSHER
		|| *s == '.'		 /*** '.' is NOT STANDARD FORTRAN ***/
#endif
		)
		{	s++;
			s=gt_num(s,&e);
I 7
			if (e==0 || e>127 || d>127 ) goto ed_err;
E 7
			if(c=='e') n=EE; else if(c=='d') n=DE; else n=GE;
I 7
			op_gen(n,w,d + (e<<8),rep_count,s);
E 7
		}
		else
D 7
		{	e=2;
E 7
I 7
		{
E 7
			if(c=='e') n=E; else if(c=='d') n=D; else n=G;
I 7
			op_gen(n,w,d,rep_count,s);
E 7
		}
I 5
D 7
		if (e==0) goto ed_err;
E 5
		op_gen(n,w,d,e,s);
E 7
		break;
	case 'l':
		s = gt_num(s, &w);
D 5
		if (w==0) break;
E 5
I 5
		if (w==0) goto ed_err;
E 5
D 7
		op_gen(L,w,0,0,s);
E 7
I 7
		op_gen(L,w,0,rep_count,s);
E 7
		break;
	case 'a':
		skip(s);
D 5
		if(*s>='0' && *s<='9')
E 5
I 5
		if(isdigit(*s))
E 5
		{	s=gt_num(s,&w);
D 5
			if(w==0) break;
E 5
I 5
#ifdef	KOSHER
			if (w==0) goto ed_err;
#else
D 7
			if (w==0) op_gen(A,0,0,0,s);
E 7
I 7
			if (w==0) op_gen(A,0,0,rep_count,s);
E 7
			else
#endif
E 5
D 7
			op_gen(AW,w,0,0,s);
E 7
I 7
			op_gen(AW,w,0,rep_count,s);
E 7
			break;
		}
D 7
		op_gen(A,0,0,0,s);
E 7
I 7
		op_gen(A,0,0,rep_count,s);
E 7
		break;
	case 'f':
		s = gt_num(s, &w);
D 5
		if (w==0) break;
E 5
I 5
		if (w==0) goto ed_err;
E 5
		if(*s=='.')
		{	s++;
			s=gt_num(s,&d);
		}
		else d=0;
D 7
		op_gen(F,w,d,0,s);
E 7
I 7
		op_gen(F,w,d,rep_count,s);
E 7
		break;
I 5
#ifndef	KOSHER
	case 'o':	/*** octal format - NOT STANDARD FORTRAN ***/
	case 'z':	/*** hex   format - NOT STANDARD FORTRAN ***/
#endif
E 5
	case 'i':
		s = gt_num(s, &w);
D 5
		if (w==0) break;
E 5
I 5
		if (w==0) goto ed_err;
E 5
		if(*s =='.')
		{
			s++;
			s=gt_num(s,&d);
			x = IM;
		}
		else
		{	d = 1;
			x = I;
		}
I 5
#ifndef KOSHER
		if (c == 'o')
D 7
			op_gen(R,8,1,0,s);
E 7
I 7
			op_gen(R,8,1,rep_count,s);
E 7
		else if (c == 'z')
D 7
			op_gen(R,16,1,0,s);
E 7
I 7
			op_gen(R,16,1,rep_count,s);
E 7
#endif
E 5
D 7
		op_gen(x,w,d,0,s);
E 7
I 7
		op_gen(x,w,d,rep_count,s);
E 7
I 5
#ifndef KOSHER
		if (c == 'o' || c == 'z')
D 7
			op_gen(R,10,1,0,s);
E 7
I 7
			op_gen(R,10,1,rep_count,s);
E 7
#endif
E 5
		break;
	default:
D 7
		pc--;	/* unSTACK */
E 7
		*p = sv;
		fmtptr = s;
D 5
		return(FMTERR);
E 5
I 5
		return(FMTUNKN);
E 5
	}
	*p = s;
	return(FMTOK);
I 5
ed_err:
	fmtptr = --s;
	return(FMTERR);
E 5
}

I 10
LOCAL
E 10
D 7
op_gen(a,b,c,d,s) char *s;
{	struct syl *p= &syl[pc];
E 7
I 7
op_gen(a,b,c,rep,s) char *s;
{	struct syl *p= &syl_ptr[pc];
E 7
	if(pc>=SYLMX)
	{	fmtptr = s;
D 2
		fatal(100,"format too complex");
E 2
I 2
		fatal(F_ERFMT,"format too complex");
E 2
	}
I 7
	if( b>32767 || c>32767 || rep>32767 )
	{	fmtptr = s;
		fatal("field width or repeat count too large");
	}
E 7
#ifdef DEBUG
	fprintf(stderr,"%3d opgen: %d %d %d %d %c\n",
D 7
		pc,a,b,c,d,*s==GLITCH?'"':*s); /* for debug */
E 7
I 7
		pc,a,b,c,rep,*s==GLITCH?'"':*s); /* for debug */
E 7
#endif
	p->op=a;
	p->p1=b;
	p->p2=c;
D 7
	p->p3=d;
E 7
I 7
	p->rpcnt=rep;
E 7
	return(pc++);
}

I 10
LOCAL
E 10
char *gt_num(s,n) char *s; int *n;
{	int m=0,a_digit=NO;
	skip(s);
	while(isdigit(*s) || isspace(*s))
	{
		if (isdigit(*s))
		{
			m = 10*m + (*s)-'0';
			a_digit = YES;
		}
		s++;
	}
	if(a_digit) *n=m;
	else *n=1;
	return(s);
}

I 10
LOCAL
E 10
char *ap_end(s) char *s;
{
	char quote;
	quote = *s++;
	for(;*s;s++)
	{
		if(*s==quote && *++s!=quote) return(s);
	}
	fmtptr = s;
D 2
	fatal(100,"bad string");
E 2
I 2
	fatal(F_ERFMT,"bad string");
E 2
}
E 1
