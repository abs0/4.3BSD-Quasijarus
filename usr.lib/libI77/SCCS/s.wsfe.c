h28484
s 00006/00003/00085
d D 5.3 86/06/11 13:02:05 jerry 4 3
c allow nulls to be output in formatted writes
e
s 00001/00001/00087
d D 5.2 85/07/30 16:31:14 jerry 3 2
c sequential & external should always be set to YES or NO.
e
s 00007/00001/00081
d D 5.1 85/06/07 23:59:06 kre 2 1
c Add copyright
e
s 00082/00000/00000
d D 1.1 85/05/21 20:08:52 libs 1 0
c date and time created 85/05/21 20:08:52 by libs
e
u
U
t
T
I 1
/*
D 2
char id_wsfe[] = "%W%";
E 2
I 2
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 2
 *
I 2
 *	%W%	%G%
 */

/*
E 2
 * write sequential formatted external
 */

#include "fio.h"

LOCAL char wsfe[] = "write sfe";

extern int w_ed(),w_ned();
int x_putc(),pr_put(),x_wend(),x_wnew(),x_tab();
LOCAL ioflag new;

s_wsfe(a) cilist *a;	/*start*/
{	int n;
	reading = NO;
D 3
	sequential=FORMATTED;
E 3
I 3
	sequential = YES;
E 3
	if(n=c_sfe(a,WRITE,SEQ,wsfe)) return(n);
	if(curunit->url) err(errflag,F_ERNOSIO,wsfe)
	if(!curunit->uwrt && ! nowwriting(curunit)) err(errflag, errno, wsfe)
	curunit->uend = NO;
	if (curunit->uprnt) putn = pr_put;
	else putn = x_putc;
	new = YES;
	doed= w_ed;
	doned= w_ned;
	doend = x_wend;
	dorevert = donewrec = x_wnew;
	dotab = x_tab;
	if(pars_f()) err(errflag,F_ERFMT,wsfe)
	fmt_bg();
	return(OK);
}

LOCAL
x_putc(c)
{
	if(c=='\n') recpos = reclen = cursor = 0;
	else recpos++;
D 4
	if (c) putc(c,cf);
E 4
I 4
	putc(c,cf);
E 4
	return(OK);
}

LOCAL
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
D 4
	if (c) putc(c,cf);
E 4
I 4
	putc(c,cf);
E 4
	return(OK);
}

LOCAL
x_wnew()
{
	if(reclen>recpos) fseek(cf,(long)(reclen-recpos),1);
	return((*putn)('\n'));
}

LOCAL
x_wend(last) char last;
{
	if(reclen>recpos) fseek(cf,(long)(reclen-recpos),1);
D 4
	return((*putn)(last));
E 4
I 4
	if(last)
		return((*putn)(last));
	else
		return(OK);
E 4
}

e_wsfe()
{	int n;
	n=en_fio();
	fmtbuf=NULL;
	return(n);
}
E 1
