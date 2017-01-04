h43062
s 00001/00001/00159
d D 5.2 87/12/21 12:46:47 bostic 12 11
c make ANSI C compatible
e
s 00007/00001/00153
d D 5.1 85/06/07 23:43:13 kre 11 10
c Add copyright
e
s 00005/00005/00149
d D 1.9 85/05/21 19:24:18 libs 10 9
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00016/00007/00138
d D 1.8 85/05/02 22:08:53 libs 9 8
c flush record on error if err= specified.
e
s 00005/00000/00140
d D 1.7 85/02/19 18:41:35 libs 8 7
c Catch infinite loops in formats.
e
s 00034/00047/00106
d D 1.6 85/02/14 22:56:09 libs 7 5
c Speed up dofio by replacing type_f() function call by array reference.
e
s 00036/00047/00106
d R 1.6 85/02/14 22:21:01 libs 6 5
c Speed up dofio by replacing type_f() function by array.
e
s 00017/00013/00136
d D 1.5 85/02/14 21:28:40 libs 5 4
c Recognize compiled formats, change syl[] members to shorts and 
c don't generate STACK operators for rep. factors for editing 
c terms so compiled formats will be shorter & execute faster.
e
s 00005/00002/00143
d D 1.4 85/01/29 10:26:33 dlw 4 3
c changed 'B' to use control struct 'ublnk' at runtime. DLW
e
s 00001/00001/00144
d D 1.3 81/08/07 18:44:32 dlw 3 2
c fixed 0l -> 0L. DLW
e
s 00004/00004/00141
d D 1.2 81/02/20 18:27:09 dlw 2 1
c changed to F_ER codes. DLW
e
s 00145/00000/00000
d D 1.1 81/02/18 18:00:56 dlw 1 0
c date and time created 81/02/18 18:00:56 by dlw
e
u
U
t
T
I 1
/*
D 11
char id_dofio[] = "%W%";
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
 * fortran format executer
 */

#include "fio.h"
D 2
#include "fmt.h"
E 2
I 2
#include "format.h"
E 2

#define DO(x)	if(n=x) err(n>0?errflag:endflag,n,dfio)
I 9
#define DO_F(x)	if(n=x) err_f(n>0?errflag:endflag,n,dfio)
#define err_f(f,n,s)	{if(f) return(dof_err(n)); else fatal(n,s);}
E 9
#define STKSZ 10
D 10
int cnt[STKSZ],ret[STKSZ],cp,rp;
char *dfio = "dofio";
E 10
I 10
LOCAL int cnt[STKSZ],ret[STKSZ],cp,rp;
LOCAL char *dfio = "dofio";
E 10
I 8
int used_data;
E 8

en_fio()
{	ftnint one=1;
D 3
	return(do_fio(&one,NULL,0l));
E 3
I 3
	return(do_fio(&one,NULL,0L));
E 3
}

I 7
/* OP_TYPE_TAB is defined in format.h,
		  it is NED for X,SLASH,APOS,H,TL,TR,T
		  ED  for I,IM,F,E,EE,D,DE,G,GE,L,A,AW
		  and returns op for other values 
 */
D 10
static int optypes[] = { OP_TYPE_TAB };
E 7
I 5
static int rep_count, in_mid;
E 10
I 10
D 12
LOCAL int optypes[] = { OP_TYPE_TAB };
E 12
I 12
LOCAL int optypes[] = OP_TYPE_TAB;
E 12
LOCAL int rep_count, in_mid;
E 10

E 5
do_fio(number,ptr,len) ftnint *number; ftnlen len; char *ptr;
{	struct syl *p;
D 7
	int n,i,more;
E 7
I 7
	int n,i,more,optype;
E 7
	more = *number;
D 7
	for(;;)
D 5
	switch(type_f((p= &syl[pc])->op))
E 5
I 5
	switch(type_f((p= &syl_ptr[pc])->op))
E 5
	{
	case NED:
E 7
I 7
	for(;;) {
	  if( (optype = ((p= &syl_ptr[pc])->op)) > LAST_TERM )
D 9
		err(errflag,F_ERFMT,"impossible code");
E 9
I 9
		err_f(errflag,F_ERFMT,"impossible code");
E 9
#ifdef DEBUG
	  fprintf(stderr," pc=%d, cnt[%d]=%d, ret[%d]=%d, op=%d\n",
		pc,cp,cnt[cp],rp,ret[rp],optype); /*for debug*/
#endif
	  switch(optypes[optype])
	  {
	  case NED:
E 7
D 9
		DO((*doned)(p,ptr))
E 9
I 9
		DO_F((*doned)(p,ptr))
E 9
		pc++;
		break;
D 7
	case ED:
E 7
I 7
	  case ED:
E 7
D 5
		if(ptr==NULL)
		{	DO((*doend)('\n'))
E 5
I 5
		if(in_mid == NO) rep_count = p->rpcnt;
		in_mid = YES;
		while (rep_count > 0 ) {
		    if(ptr==NULL)
		    {	DO((*doend)('\n'))
E 5
			return(OK);
I 5
		    }
		    if(!more) return(OK);
I 8
		    used_data = YES;
E 8
D 9
		    DO((*doed)(p,ptr,len))
E 9
I 9
		    DO_F((*doed)(p,ptr,len))
E 9
		    ptr += len;
		    more--;
		    rep_count--;
E 5
		}
D 5
		if(cnt[cp]<=0)
		{	cp--;
			pc++;
			break;
		}
		if(!more) return(OK);
		DO((*doed)(p,ptr,len))
		cnt[cp]--;
		ptr += len;
		more--;
E 5
I 5
		pc++;
		in_mid = NO;
E 5
		break;
D 7
	case STACK:		/* repeat count */
E 7
I 7
	  case STACK:		/* repeat count */
E 7
D 2
		if(++cp==STKSZ) err(errflag,100,"too many nested ()")
E 2
I 2
D 9
		if(++cp==STKSZ) err(errflag,F_ERFMT,"too many nested ()")
E 9
I 9
		if(++cp==STKSZ) err_f(errflag,F_ERFMT,"too many nested ()")
E 9
E 2
		cnt[cp]=p->p1;
		pc++;
		break;
D 7
	case RET:		/* open paren */
E 7
I 7
	  case RET:		/* open paren */
E 7
D 2
		if(++rp==STKSZ) err(errflag,100,"too many nested ()")
E 2
I 2
D 9
		if(++rp==STKSZ) err(errflag,F_ERFMT,"too many nested ()")
E 9
I 9
		if(++rp==STKSZ) err_f(errflag,F_ERFMT,"too many nested ()")
E 9
E 2
		ret[rp]=p->p1;
		pc++;
		break;
D 7
	case GOTO:		/* close paren */
E 7
I 7
	  case GOTO:		/* close paren */
E 7
		if(--cnt[cp]<=0)
		{	cp--;
			rp--;
			pc++;
		}
		else pc = ret[rp--] + 1;
		break;
D 7
	case REVERT:		/* end of format */
E 7
I 7
	  case REVERT:		/* end of format */
E 7
		if(ptr==NULL)
		{	DO((*doend)('\n'))
			return(OK);
		}
		if(!more) return(OK);
I 8
D 9
		if( used_data == NO ) err(errflag,F_ERFMT,"\nNo more editing terms in format");
E 9
I 9
		if( used_data == NO ) err_f(errflag,F_ERFMT,"\nNo more editing terms in format");
E 9
		used_data = NO;
E 8
		rp=cp=0;
		pc = p->p1;
		DO((*dorevert)())
		break;
D 7
	case COLON:
E 7
I 7
	  case COLON:
E 7
#ifndef KOSHER
D 7
	case DOLAR:				/*** NOT STANDARD FORTRAN ***/
E 7
I 7
	  case DOLAR:				/*** NOT STANDARD FORTRAN ***/
E 7
#endif
		if (ptr == NULL)
		{	DO((*doend)((char)p->p1))
			return(OK);
		}
		if (!more) return(OK);
		pc++;
		break;
#ifndef KOSHER
D 7
	case SU:				/*** NOT STANDARD FORTRAN ***/
E 7
I 7
	  case SU:				/*** NOT STANDARD FORTRAN ***/
E 7
#endif
D 7
	case SS:
	case SP:
	case S: cplus = p->p1;
E 7
I 7
	  case SS:
	  case SP:
	  case S: cplus = p->p1;
E 7
		signit = p->p2;
		pc++;
		break;
D 7
	case P:
E 7
I 7
	  case P:
E 7
		scale = p->p1;
		pc++;
		break;
#ifndef KOSHER
D 7
	case R:					/*** NOT STANDARD FORTRAN ***/
E 7
I 7
	  case R:					/*** NOT STANDARD FORTRAN ***/
E 7
		radix = p->p1;
		pc++;
		break;
I 4
D 7
	case B:					/*** NOT STANDARD FORTRAN ***/
E 7
I 7
	  case B:					/*** NOT STANDARD FORTRAN ***/
E 7
		if (external) cblank = curunit->ublnk;
		else cblank = 0;		/* blank = 'NULL' */
		pc++;
		break;
E 4
#endif
D 4
	case BN:
	case BZ:
E 4
I 4
D 7
	case BNZ:
E 7
I 7
	  case BNZ:
E 7
E 4
		cblank = p->p1;
		pc++;
		break;
D 7
	default:
E 7
I 7
	  default:
E 7
D 2
		err(errflag,100,"impossible code")
E 2
I 2
D 9
		err(errflag,F_ERFMT,"impossible code")
E 9
I 9
		err_f(errflag,F_ERFMT,"impossible code")
E 9
I 7
	  }
E 7
E 2
	}
}

fmt_bg()
{
I 5
	in_mid = NO;
E 5
	cp=rp=pc=cursor=0;
	cnt[0]=ret[0]=0;
I 8
	used_data = NO;
I 9
}

D 10
static
E 10
I 10
LOCAL
E 10
dof_err(n)
{
	if( reading==YES && external==YES && sequential==YES) donewrec();
	return(errno=n);
E 9
E 8
D 7
}

type_f(n)
{
#ifdef DEBUG
	fprintf(stderr," pc=%d, cnt[%d]=%d, ret[%d]=%d, op=%d\n",
		pc,cp,cnt[cp],rp,ret[rp],n); /*for debug*/
#endif
	switch(n)
	{
	case X:			/* non-editing specifications */
	case SLASH:
	case APOS: case H:
	case T: case TL: case TR:
				return(NED);

	case F:			/* editing conversions */
	case I: case IM:
	case A: case AW:
	case L:
	case E: case EE: case D: case DE:
	case G: case GE:
				return(ED);

	default: return(n);
	}
E 7
}
E 1
