h08996
s 00002/00001/00165
d D 5.2 85/07/30 16:31:07 jerry 5 4
c sequential & external should always be set to YES or NO.
e
s 00007/00001/00159
d D 5.1 85/06/07 23:41:12 kre 4 3
c Add copyright
e
s 00000/00008/00160
d D 1.3 85/06/04 17:53:02 libs 3 2
c delete iiorec_, iiopos_
e
s 00024/00002/00144
d D 1.2 85/05/22 19:53:43 libs 2 1
c Make list directed work for multiple records.
e
s 00146/00000/00000
d D 1.1 85/05/21 20:09:14 libs 1 0
c date and time created 85/05/21 20:09:14 by libs
e
u
U
t
T
I 1
/*
D 4
char id_c_iio[] = "%W%";
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
 *
I 4
 *	%W%	%G%
 */

/*
E 4
 * internal (character array) i/o: common portions
 */

#include "fio.h"
#include "lio.h"

LOCAL icilist *svic;		/* active internal io list */
I 2
LOCAL lio_nl;
E 2

int z_wnew();

z_getc()
{
I 2
	if(formatted == LISTDIRECTED )
	{
		if( lio_nl == YES )
		{
			recnum++;
			recpos = 0;
		}
		else if (recpos == svic->icirlen)
		{
			lio_nl = YES;
			return('\n');
		}
		lio_nl = NO;
	}

E 2
	if(icptr >= icend && !recpos)	/* new rec beyond eof */
	{	leof = EOF;
		return(EOF);
	}
	if(recpos++ < svic->icirlen) return(*icptr++);
D 2
	if(formatted == LISTDIRECTED) return(EOF);
E 2
	return(' ');
}

z_putc(c) char c;
{
	if(icptr < icend)
	{	if(c=='\n') return(z_wnew());
		if(recpos++ < svic->icirlen)
		{	*icptr++ = c;
			return(OK);
		}
		else err(errflag,F_EREREC,"iio")
	}
	leof = EOF;
#ifndef KOSHER
	err(endflag,EOF,"iio")   /* NOT STANDARD, end-of-file on writes */
#endif
#ifdef KOSHER
	err(errflag,F_EREREC,"iio")
#endif
}

z_ungetc(ch,cf) char ch;
D 2
{	if(ch==EOF || --recpos >= svic->icirlen) return(OK);
E 2
I 2
{	
	if( lio_nl == YES )
	{
		lio_nl = NO;
		return(OK);
	}
	if(ch==EOF || --recpos >= svic->icirlen) return(OK);
E 2
	if(--icptr < svic->iciunit || recpos < 0) err(errflag,F_ERBREC,"ilio")
	*icptr = ch;
	return(OK);
}

LOCAL
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
	return(OK);
}

c_si(a) icilist *a;
{
	sequential = YES;
	recnum = 0;
	icptr = a->iciunit;
	return(c_fi(a));
}

c_di(a) icilist *a;
{
	sequential = NO;
	recnum = a->icirec - 1;
	icptr = a->iciunit + recnum*a->icirlen;
	return(c_fi(a));
}

z_rnew()
{
	icptr = svic->iciunit + (++recnum)*svic->icirlen;
	recpos = reclen = cursor = 0;
	return(OK);
}

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

z_tab()
{	int n;
	if(reclen < recpos) reclen = recpos;
	if((recpos + cursor) < 0) cursor = -recpos;	/* to BOR */
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

c_li(a) icilist *a;
{
	fmtbuf="int list io";
D 5
	sequential = formatted = LISTDIRECTED;
E 5
I 5
	sequential = YES;
	formatted = LISTDIRECTED;
E 5
	external = NO;
	elist = YES;
	svic = a;
	recnum = recpos = 0;
	cplus = cblank = NO;
I 2
	lio_nl = NO;
E 2
	icptr = a->iciunit;
	icend = icptr + a->icirlen * a->icirnum;
	errflag = a->icierr;
	endflag = a->iciend;
	leof = NO;
	return(OK);
}
D 3

ftnint
iiorec_()
{	return(recnum);	}

ftnint
iiopos_()
{	return(recpos);	}
E 3
E 1
