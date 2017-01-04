h10950
s 00011/00003/00196
d D 1.10 85/05/21 19:25:20 libs 10 9
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00002/00002/00197
d D 1.9 85/02/14 21:29:19 libs 9 8
c Recognize compiled formats, change syl[] members to shorts and 
c don't generate STACK operators for rep. factors for editing 
c terms so compiled formats will be shorter & execute faster.
e
s 00001/00001/00198
d D 1.8 83/10/30 20:15:23 dlw 8 7
c tolerate short records on non-seekable input. DLW
e
s 00001/00004/00198
d D 1.7 83/09/20 11:38:41 dlw 7 6
c removed extraneous (*ungetn)() from x_tab(). DLW
e
s 00001/00001/00201
d D 1.6 83/04/25 18:12:04 dlw 6 5
c TL beyond BOR becomes TO to BOR. DLW
e
s 00005/00004/00197
d D 1.5 82/04/30 13:48:25 dlw 5 4
c cleaned up EOF handling. DLW
e
s 00011/00008/00190
d D 1.4 81/08/11 23:24:37 dlw 4 3
c added test for return val of now{r,w}. DLW
e
s 00004/00000/00194
d D 1.3 81/08/07 18:56:50 dlw 3 2
c set EOF on null read at end of file. DLW
e
s 00008/00008/00186
d D 1.2 81/02/20 18:34:06 dlw 2 1
c changed to F_ER codes. DLW
e
s 00194/00000/00000
d D 1.1 81/02/18 18:01:56 dlw 1 0
c date and time created 81/02/18 18:01:56 by dlw
e
u
U
t
T
I 1
/*
char id_sfe[] = "%W%";
 *
 * sequential formatted external routines
 */

#include "fio.h"

/*
 * read sequential formatted external
 */

extern int rd_ed(),rd_ned();
int x_rnew(),x_getc(),x_tab();

I 4
D 10
char rsfe[] = "read sfe";
char wsfe[] = "write sfe";
E 10
I 10
LOCAL char rsfe[] = "read sfe";
LOCAL char wsfe[] = "write sfe";
E 10

E 4
s_rsfe(a) cilist *a; /* start */
{	int n;
	reading = YES;
	if(n=c_sfe(a,READ)) return(n);
D 4
	if(curunit->uwrt) nowreading(curunit);
E 4
I 4
	if(curunit->uwrt && ! nowreading(curunit)) err(errflag, errno, rsfe)
E 4
	getn= x_getc;
	doed= rd_ed;
	doned= rd_ned;
	donewrec = dorevert = doend = x_rnew;
	dotab = x_tab;
D 2
	if(pars_f(fmtbuf)) err(errflag,100,"read sfe")
E 2
I 2
D 4
	if(pars_f(fmtbuf)) err(errflag,F_ERFMT,"read sfe")
E 4
I 4
D 9
	if(pars_f(fmtbuf)) err(errflag,F_ERFMT,rsfe)
E 9
I 9
	if(pars_f()) err(errflag,F_ERFMT,rsfe)
E 9
E 4
E 2
	fmt_bg();
	return(OK);
}

I 10
LOCAL
E 10
x_rnew()			/* find next record */
{	int ch;
D 5
	if(!curunit->uend)
		while((ch=getc(cf))!='\n' && ch!=EOF);
I 3
	if(recpos==0 && feof(cf))
	{	curunit->uend = YES;
E 5
I 5
	if(curunit->uend)
E 5
		return(EOF);
I 5
	while((ch=getc(cf))!='\n' && ch!=EOF);
	if(feof(cf))
	{	curunit->uend = YES;
		if (recpos==0) return(EOF);
E 5
	}
E 3
	cursor=recpos=reclen=0;
	return(OK);
}

I 10
LOCAL
E 10
x_getc()
{	int ch;
	if(curunit->uend) return(EOF);
	if((ch=getc(cf))!=EOF && ch!='\n')
	{	recpos++;
		return(ch);
	}
	if(ch=='\n')
	{	ungetc(ch,cf);
		return(ch);
	}
	if(feof(cf)) curunit->uend = YES;
	return(EOF);
}

e_rsfe()
{	int n;
	n=en_fio();
	fmtbuf=NULL;
	return(n);
}

I 10
LOCAL
E 10
c_sfe(a,flag) cilist *a; /* check */
{	unit *p;
	int n;
	external=sequential=formatted=FORMATTED;
	fmtbuf=a->cifmt;
	lfname = NULL;
	elist = NO;
	errflag = a->cierr;
	endflag = a->ciend;
	lunit = a->ciunit;
D 2
	if(not_legal(lunit)) err(errflag,101,"sfe");
E 2
I 2
D 4
	if(not_legal(lunit)) err(errflag,F_ERUNIT,"sfe");
E 4
I 4
	if(not_legal(lunit)) err(errflag,F_ERUNIT,rsfe+5);
E 4
E 2
	curunit = p = &units[lunit];
	if(!p->ufd && (n=fk_open(flag,SEQ,FMT,(ftnint)lunit)) )
D 4
		err(errflag,n,"sfe")
E 4
I 4
		err(errflag,n,rsfe+5)
E 4
	cf = curunit->ufd;
	elist = YES;
	lfname = curunit->ufnm;
D 2
	if(!p->ufmt) err(errflag,102,"sfe")
	if(p->url) err(errflag,105,"sfe")
E 2
I 2
D 4
	if(!p->ufmt) err(errflag,F_ERNOFIO,"sfe")
	if(p->url) err(errflag,F_ERNOSIO,"sfe")
E 4
I 4
	if(!p->ufmt) err(errflag,F_ERNOFIO,rsfe+5)
	if(p->url) err(errflag,F_ERNOSIO,rsfe+5)
E 4
E 2
	cursor=recpos=scale=reclen=0;
	radix = 10;
	signit = YES;
	cblank = curunit->ublnk;
	cplus = NO;
	return(OK);
}

/*
 * write sequential formatted external
 */

extern int w_ed(),w_ned();
int x_putc(),pr_put(),x_wend(),x_wnew();
D 10
ioflag new;
E 10
I 10
LOCAL ioflag new;
E 10

s_wsfe(a) cilist *a;	/*start*/
{	int n;
	reading = NO;
	if(n=c_sfe(a,WRITE)) return(n);
D 4
	if(!curunit->uwrt) nowwriting(curunit);
E 4
I 4
	if(!curunit->uwrt && ! nowwriting(curunit)) err(errflag, errno, wsfe)
E 4
	curunit->uend = NO;
	if (curunit->uprnt) putn = pr_put;
	else putn = x_putc;
	new = YES;
	doed= w_ed;
	doned= w_ned;
	doend = x_wend;
	dorevert = donewrec = x_wnew;
	dotab = x_tab;
D 2
	if(pars_f(fmtbuf)) err(errflag,100,"write sfe")
E 2
I 2
D 4
	if(pars_f(fmtbuf)) err(errflag,F_ERFMT,"write sfe")
E 4
I 4
D 9
	if(pars_f(fmtbuf)) err(errflag,F_ERFMT,wsfe)
E 9
I 9
	if(pars_f()) err(errflag,F_ERFMT,wsfe)
E 9
E 4
E 2
	fmt_bg();
	return(OK);
}

I 10
LOCAL
E 10
x_putc(c)
{
	if(c=='\n') recpos = reclen = cursor = 0;
	else recpos++;
	if (c) putc(c,cf);
	return(OK);
}

I 10
LOCAL
E 10
pr_put(c)
{
	if(c=='\n')
	{	new = YES;
		recpos = reclen = cursor = 0;
	}
	else if(new)
	{	new = NO;
		if(c=='0') c = '\n';
		else if(c=='1') c = '\f';
		else return(OK);
	}
	else recpos++;
	if (c) putc(c,cf);
	return(OK);
}

I 10
LOCAL
E 10
x_tab()
{	int n;
	if(reclen < recpos) reclen = recpos;
	if(curunit->useek)
D 2
	{	if((recpos+cursor) < 0) return(107);
E 2
I 2
D 6
	{	if((recpos+cursor) < 0) return(F_ERBREC);
E 6
I 6
	{	if((recpos+cursor) < 0) cursor = -recpos;	/* to BOR */
E 6
E 2
		n = reclen - recpos;	/* distance to eor, n>=0 */
		if((cursor-n) > 0)
		{	fseek(cf,(long)n,1);  /* find current eor */
			recpos = reclen;
			cursor -= n;
		}
		else
		{	fseek(cf,(long)cursor,1);  /* do not pass go */
			recpos += cursor;
			return(cursor=0);
		}
	}
	else
D 2
		if(cursor < 0) return(120);	/* cant go back */
E 2
I 2
		if(cursor < 0) return(F_ERSEEK);   /* can't go back */
E 2
	while(cursor--)
	{	if(reading)
		{	n = (*getn)();
D 7
			if(n=='\n')
			{	(*ungetn)(n,cf);
D 2
				return(110);
E 2
I 2
				return(F_EREREC);
E 2
			}
E 7
I 7
D 8
			if(n=='\n') return(F_EREREC);
E 8
I 8
			if(n=='\n') return(cursor=0);	/* be tolerant */
E 8
E 7
			if(n==EOF) return(EOF);
		}
		else	(*putn)(' ');	/* fill in the empty record */
	}
	return(cursor=0);
}

I 10
LOCAL
E 10
x_wnew()
{
	if(reclen>recpos) fseek(cf,(long)(reclen-recpos),1);
	return((*putn)('\n'));
}

I 10
LOCAL
E 10
x_wend(last) char last;
{
	if(reclen>recpos) fseek(cf,(long)(reclen-recpos),1);
	return((*putn)(last));
}

/*
/*xw_rev()
/*{
/*	if(workdone) x_wSL();
/*	return(workdone=0);
/*}
/*
*/
e_wsfe()
{	return(e_rsfe()); }
E 1
