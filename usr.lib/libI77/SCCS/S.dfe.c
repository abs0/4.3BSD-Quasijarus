h33353
s 00010/00002/00184
d D 1.6 85/05/21 19:24:12 libs 6 5
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00002/00002/00184
d D 1.5 85/02/14 21:28:31 libs 5 4
c Recognize compiled formats, change syl[] members to shorts and 
c don't generate STACK operators for rep. factors for editing 
c terms so compiled formats will be shorter & execute faster.
e
s 00004/00002/00182
d D 1.4 83/04/25 18:39:50 dlw 4 3
c TL beyond BOR becomes TL to BOR. DLW
e
s 00010/00011/00174
d D 1.3 81/08/11 23:23:41 dlw 3 2
c added test for return val of now{r,w}. DLW
e
s 00010/00010/00175
d D 1.2 81/02/20 18:26:44 dlw 2 1
c chaged to F_ER codes. DLW
e
s 00185/00000/00000
d D 1.1 81/02/18 18:00:51 dlw 1 0
c date and time created 81/02/18 18:00:51 by dlw
e
u
U
t
T
I 1
/*
char id_dfe[] = "%W%";
 *
 * direct formatted external i/o
 */

#include "fio.h"

extern int rd_ed(),rd_ned(),w_ed(),w_ned();
int y_getc(),y_putc(),y_rnew(),y_wnew(),y_tab();

D 3
char *dfe = "dfe";
char *rdfe = "read dfe";
char *wdfe = "write dfe";
E 3
I 3
D 6
char rdfe[] = "read dfe";
char wdfe[] = "write dfe";
E 6
I 6
LOCAL char rdfe[] = "read dfe";
LOCAL char wdfe[] = "write dfe";
E 6
E 3

s_rdfe(a) cilist *a;
{
	int n;
	reading = YES;
	if(n=c_dfe(a,READ)) return(n);
D 3
	if(curunit->uwrt) nowreading(curunit);
E 3
I 3
	if(curunit->uwrt && ! nowreading(curunit)) err(errflag, errno, rdfe)
E 3
	getn = y_getc;
	doed = rd_ed;
	doned = rd_ned;
	dotab = y_tab;
	dorevert = doend = donewrec = y_rnew;
D 2
	if(pars_f(fmtbuf)) err(errflag,100,rdfe)
E 2
I 2
D 5
	if(pars_f(fmtbuf)) err(errflag,F_ERFMT,rdfe)
E 5
I 5
	if(pars_f()) err(errflag,F_ERFMT,rdfe)
E 5
E 2
	fmt_bg();
	return(OK);
}

s_wdfe(a) cilist *a;
{
	int n;
	reading = NO;
	if(n=c_dfe(a,WRITE)) return(n);
	curunit->uend = NO;
D 3
	if(!curunit->uwrt) nowwriting(curunit);
E 3
I 3
	if(!curunit->uwrt && ! nowwriting(curunit)) err(errflag, errno, wdfe)
E 3
	putn = y_putc;
	doed = w_ed;
	doned = w_ned;
	dotab = y_tab;
	dorevert = doend = donewrec = y_wnew;
D 2
	if(pars_f(fmtbuf)) err(errflag,100,wdfe)
E 2
I 2
D 5
	if(pars_f(fmtbuf)) err(errflag,F_ERFMT,wdfe)
E 5
I 5
	if(pars_f()) err(errflag,F_ERFMT,wdfe)
E 5
E 2
	fmt_bg();
	return(OK);
}

e_rdfe()
{
	en_fio();
	return(OK);
}

e_wdfe()
{
	en_fio();
	return(OK);
}

I 6
LOCAL
E 6
c_dfe(a,flag) cilist *a;
{	int n;
	sequential = NO;
	external = formatted = FORMATTED;
	lfname = NULL;
	elist = NO;
	cursor=scale=recpos=reclen=0;
	radix = 10;
	signit = YES;
	fmtbuf = a->cifmt;
	errflag = a->cierr;
	endflag = a->ciend;
	lunit = a->ciunit;
D 2
	if(not_legal(lunit)) err(errflag,101,dfe);
E 2
I 2
D 3
	if(not_legal(lunit)) err(errflag,F_ERUNIT,dfe);
E 3
I 3
	if(not_legal(lunit)) err(errflag,F_ERUNIT,rdfe+5);
E 3
E 2
	curunit = &units[lunit];
	if(!curunit->ufd && (n=fk_open(flag,DIR,FMT,(ftnint)lunit)))
D 3
		err(errflag,n,dfe)
E 3
I 3
		err(errflag,n,rdfe+5)
E 3
	cf = curunit->ufd;
	elist = YES;
	lfname = curunit->ufnm;
D 2
	if(!curunit->ufmt) err(errflag,102,dfe)
	if(!curunit->useek || !curunit->url) err(errflag,104,dfe)
E 2
I 2
D 3
	if(!curunit->ufmt) err(errflag,F_ERNOFIO,dfe)
	if(!curunit->useek || !curunit->url) err(errflag,F_ERNODIO,dfe)
E 3
I 3
	if(!curunit->ufmt) err(errflag,F_ERNOFIO,rdfe+5)
	if(!curunit->useek || !curunit->url) err(errflag,F_ERNODIO,rdfe+5)
E 3
E 2
	recnum = a->cirec - 1;
	fseek(cf, (long)curunit->url * recnum, 0);
	cblank = curunit->ublnk;
	cplus = NO;
	return(OK);
}

I 6
LOCAL
E 6
y_getc()
{
	int ch;
	if(curunit->uend) return(EOF);
	if(curunit->url==1 || recpos++ < curunit->url)
	{
		if((ch=getc(cf))!=EOF)
		{
				return(ch);
		}
		if(feof(cf))
		{
			curunit->uend = YES;
			return(EOF);
		}
		err(errflag,errno,rdfe);
	}
	else return(' ');
}

I 6
LOCAL
E 6
y_putc(c)
{
D 2
	if(curunit->url!=1 && recpos++ >= curunit->url) err(errflag,110,wdfe)
E 2
I 2
	if(curunit->url!=1 && recpos++ >= curunit->url) err(errflag,F_EREREC,wdfe)
E 2
	putc(c,cf);
	return(OK);
}

I 6
LOCAL
E 6
y_tab()
{	int n;
	if(curunit->url==1)
	{
D 2
		if(cursor < 0 && -cursor > ftell(cf)) return(107);
E 2
I 2
D 4
		if(cursor < 0 && -cursor > ftell(cf)) return(F_ERBREC);
E 4
I 4
		if(cursor < 0 && -cursor > ftell(cf)) rewind(cf);
		else	fseek(cf,(long)cursor,1);
		return(cursor=0);
E 4
E 2
	}
	else
	{	if(reclen < recpos) reclen = recpos;
D 2
		if((recpos + cursor) < 0) return(107);
E 2
I 2
D 4
		if((recpos + cursor) < 0) return(F_ERBREC);
E 4
I 4
		if((recpos + cursor) < 0) cursor = -recpos;	/* BOR */
E 4
E 2
		n = reclen - recpos;		/* n >= 0 */
		if(!reading && (cursor-n) > 0)
		{	recpos = reclen;
			cursor -= n;
			fseek(cf,(long)n,1);
			while(cursor--) if(n=(*putn)(' ')) return(n);
			return(cursor=0);
		}
		recpos += cursor;
D 2
		if(recpos >= curunit->url) err(errflag,110,dfe)
E 2
I 2
D 3
		if(recpos >= curunit->url) err(errflag,F_EREREC,dfe)
E 3
I 3
		if(recpos >= curunit->url) err(errflag,F_EREREC,rdfe+5)
E 3
E 2
	}
	fseek(cf,(long)cursor,1);
	return(cursor=0);
}

/*
/*y_rev()
/*{	/*what about work done?*/
/*	if(curunit->url==1) return(0);
/*	while(recpos<curunit->url) (*putn)(' ');
/*	recpos=0;
/*	return(0);
/*}
/*
/*y_err()
/*{
D 2
/*	err(errflag, 110, dfe);
E 2
I 2
D 3
/*	err(errflag, F_EREREC, dfe);
E 3
I 3
/*	err(errflag, F_EREREC, rdfe+5);
E 3
E 2
/*}
*/

I 6
LOCAL
E 6
y_rnew()
{	if(curunit->url != 1)
	{	fseek(cf,(long)curunit->url*(++recnum),0);
		recpos = reclen = cursor = 0;
	}
	return(OK);
}

I 6
LOCAL
E 6
y_wnew()
{	if(curunit->url != 1)
	{	if(reclen > recpos)
		{	fseek(cf,(long)(reclen-recpos),1);
			recpos = reclen;
		}
		while(recpos < curunit->url) (*putn)(' ');
		recnum++;
		recpos = reclen = cursor = 0;
	}
	return(OK);
}

I 6
LOCAL
E 6
y_rend()
{
	return(OK);
}

I 6
LOCAL
E 6
y_wend()
{
	return(y_wnew());
}
E 1
