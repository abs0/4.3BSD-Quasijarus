h14869
s 00013/00001/00248
d D 1.7 85/05/21 19:24:47 libs 7 6
c make unneeded globals LOCAL (static); move several routines to .c
c in which they are called.
e
s 00001/00001/00248
d D 1.6 85/02/14 21:29:02 libs 6 5
c Recognize compiled formats, change syl[] members to shorts and 
c don't generate STACK operators for rep. factors for editing 
c terms so compiled formats will be shorter & execute faster.
e
s 00001/00004/00248
d D 1.5 85/01/31 19:56:18 dlw 5 4
c don't set 'leof' on internal list-directed read beyond EOR. DLW
e
s 00004/00000/00248
d D 1.4 85/01/09 17:29:57 dlw 4 3
c don't allow list read beyond EOR. DLW
e
s 00001/00001/00247
d D 1.3 83/04/25 18:44:18 dlw 3 2
c TL beyond BOR becomes TL to BOR. DLW
e
s 00005/00005/00243
d D 1.2 81/02/20 18:31:21 dlw 2 1
c changed to F_ER codes. DLW
e
s 00248/00000/00000
d D 1.1 81/02/18 18:01:21 dlw 1 0
c date and time created 81/02/18 18:01:21 by dlw
e
u
U
t
T
I 1
/*
char id_iio[] = "%W%";
 *
 * internal (character array) i/o
 */

#include "fio.h"
#include "lio.h"

I 7
LOCAL icilist *svic;		/* active internal io list */

E 7
extern int rd_ed(),rd_ned(),w_ed(),w_ned();
extern int l_read(),l_write();
int z_wnew(),z_rnew(),z_tab();

I 7
LOCAL
E 7
z_getc()
{
	if(icptr >= icend && !recpos)	/* new rec beyond eof */
	{	leof = EOF;
		return(EOF);
	}
D 7
	if(recpos++ < svic->icirlen) return(*icptr++);
E 7
I 4
D 5
	if(formatted == LISTDIRECTED)
	{	leof = EOF;
		return(EOF);
	}
E 5
I 5
	if(formatted == LISTDIRECTED) return(EOF);
I 7
	if(recpos++ < svic->icirlen) return(*icptr++);
E 7
E 5
E 4
	return(' ');
}

I 7
LOCAL
E 7
z_putc(c) char c;
{
	if(icptr < icend)
	{	if(c=='\n') return(z_wnew());
		if(recpos++ < svic->icirlen)
		{	*icptr++ = c;
			return(OK);
		}
D 2
		else err(errflag,110,"iio")
E 2
I 2
		else err(errflag,F_EREREC,"iio")
E 2
	}
	leof = EOF;
#ifndef KOSHER
	err(endflag,EOF,"iio")   /* NOT STANDARD, end-of-file on writes */
#endif
#ifdef KOSHER
D 2
	err(errflag,110,"iio")
E 2
I 2
	err(errflag,F_EREREC,"iio")
E 2
#endif
}

I 7
LOCAL
E 7
z_ungetc(ch,cf) char ch;
{	if(ch==EOF || --recpos >= svic->icirlen) return(OK);
D 2
	if(--icptr < svic->iciunit || recpos < 0) err(errflag,107,"ilio")
E 2
I 2
	if(--icptr < svic->iciunit || recpos < 0) err(errflag,F_ERBREC,"ilio")
E 2
	*icptr = ch;
	return(OK);
}

s_rsfi(a) icilist *a;
{
	reading = YES;
	doed=rd_ed;
	doned=rd_ned;
	getn=z_getc;
	doend = donewrec = z_rnew;
	dorevert = z_rnew;
	dotab = z_tab;
	return(c_si(a));
}

s_wsfi(a) icilist *a;
{
	reading = NO;
	doed=w_ed;
	doned=w_ned;
	putn=z_putc;
	doend = donewrec = z_wnew;
	dorevert = z_wnew;
	dotab = z_tab;
	return(c_si(a));
}

s_rdfi(a) icilist *a;
{
	reading = YES;
	doed = rd_ed;
	doned = rd_ned;
	getn = z_getc;
	donewrec = z_rnew;
	dorevert = doend = z_rnew;
	dotab = z_tab;
	return(c_di(a));
}

s_wdfi(a) icilist *a;
{
	reading = NO;
	doed = w_ed;
	doned = w_ned;
	putn = z_putc;
	donewrec = z_wnew;
	dorevert = doend = z_wnew;
	dotab = z_tab;
	return(c_di(a));
}

I 7
LOCAL
E 7
c_fi(a) icilist *a;
{
	fmtbuf=a->icifmt;
	formatted = FORMATTED;
	external = NO;
	cblank=cplus=NO;
	scale=cursor=0;
	radix = 10;
	signit = YES;
	elist = YES;
	svic = a;
	recpos=reclen=0;
	icend = a->iciunit + a->icirnum*a->icirlen;
	errflag = a->icierr;
	endflag = a->iciend;
D 2
	if(pars_f(fmtbuf)) err(errflag,100,"ifio")
E 2
I 2
D 6
	if(pars_f(fmtbuf)) err(errflag,F_ERFMT,"ifio")
E 6
I 6
	if(pars_f()) err(errflag,F_ERFMT,"ifio")
E 6
E 2
	fmt_bg();
	return(OK);
}

I 7
LOCAL
E 7
c_si(a) icilist *a;
{
	sequential = YES;
	recnum = 0;
	icptr = a->iciunit;
	return(c_fi(a));
}

I 7
LOCAL
E 7
c_di(a) icilist *a;
{
	sequential = NO;
	recnum = a->icirec - 1;
	icptr = a->iciunit + recnum*a->icirlen;
	return(c_fi(a));
}

I 7
LOCAL
E 7
z_rnew()
{
	icptr = svic->iciunit + (++recnum)*svic->icirlen;
	recpos = reclen = cursor = 0;
	return(OK);
}

I 7
LOCAL
E 7
z_wnew()
{
	if(reclen > recpos)
	{	icptr += (reclen - recpos);
		recpos = reclen;
	}
	while(recpos < svic->icirlen) (*putn)(' ');
	recpos = reclen = cursor = 0;
	recnum++;
	return(OK);
}

I 7
LOCAL
E 7
z_tab()
{	int n;
	if(reclen < recpos) reclen = recpos;
D 2
	if((recpos + cursor) < 0) return(107);
E 2
I 2
D 3
	if((recpos + cursor) < 0) return(F_ERBREC);
E 3
I 3
	if((recpos + cursor) < 0) cursor = -recpos;	/* to BOR */
E 3
E 2
	n = reclen - recpos;
	if(!reading && (cursor-n) > 0)
	{	icptr += n;
		recpos = reclen;
		cursor -= n;
		while(cursor--) if(n=(*putn)(' ')) return(n);
	}
	else
	{	icptr += cursor;
		recpos += cursor;
	}
	return(cursor=0);
}

e_rsfi()
{	int n;
	n = en_fio();
	fmtbuf = NULL;
	return(n);
}

e_wsfi()
{
	return(e_rsfi());
}

e_rdfi()
{
	return(e_rsfi());
}

e_wdfi()
{
	return(e_wsfi());
}

I 7
LOCAL
E 7
c_li(a) icilist *a;
{
	fmtbuf="int list io";
	sequential = formatted = LISTDIRECTED;
	external = NO;
	elist = YES;
	svic = a;
	recnum = recpos = 0;
	cplus = cblank = NO;
	icptr = a->iciunit;
	icend = icptr + a->icirlen * a->icirnum;
	errflag = a->icierr;
	endflag = a->iciend;
	leof = NO;
	return(OK);
}

s_rsli(a) icilist *a;
{
	reading = YES;
	lioproc = l_read;
	getn = z_getc;
	ungetn = z_ungetc;
	l_first = YES;
	lcount = 0;
	lquit = NO;
	return(c_li(a));
}

s_wsli(a) icilist *a;
{
	reading = NO;
	putn = z_putc;
	lioproc = l_write;
	line_len = a->icirlen;
	return(c_li(a));
}

e_rsli()
{	fmtbuf = NULL;
	return(OK);
}

e_wsli()
{	fmtbuf = NULL;
	reclen = recpos;
	return(z_wnew());
}

ftnint
iiorec_()
{	return(recnum);	}

ftnint
iiopos_()
{	return(recpos);	}
E 1
