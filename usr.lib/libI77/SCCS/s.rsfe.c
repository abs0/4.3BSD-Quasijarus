h61469
s 00001/00001/00071
d D 5.2 85/07/30 16:31:11 jerry 3 2
c sequential & external should always be set to YES or NO.
e
s 00007/00001/00065
d D 5.1 85/06/07 23:55:17 kre 2 1
c Add copyright
e
s 00066/00000/00000
d D 1.1 85/05/21 20:08:50 libs 1 0
c date and time created 85/05/21 20:08:50 by libs
e
u
U
t
T
I 1
/*
D 2
char id_rsfe[] = "%W%";
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
 * read sequential formatted external
 */

#include "fio.h"

extern int rd_ed(),rd_ned();
int x_rnew(),x_getc(),x_tab();

LOCAL char rsfe[] = "read sfe";

s_rsfe(a) cilist *a; /* start */
{	int n;
	reading = YES;
D 3
	sequential=FORMATTED;
E 3
I 3
	sequential = YES;
E 3
	if(n=c_sfe(a,READ,SEQ,rsfe)) return (n);
	if(curunit->url) err(errflag,F_ERNOSIO,rsfe)
	if(curunit->uwrt && ! nowreading(curunit)) err(errflag, errno, rsfe)
	getn= x_getc;
	doed= rd_ed;
	doned= rd_ned;
	donewrec = dorevert = doend = x_rnew;
	dotab = x_tab;
	if(pars_f()) err(errflag,F_ERFMT,rsfe)
	fmt_bg();
	return(OK);
}

LOCAL
x_rnew()			/* find next record */
{	int ch;
	if(curunit->uend)
		return(EOF);
	while((ch=getc(cf))!='\n' && ch!=EOF);
	if(feof(cf))
	{	curunit->uend = YES;
		if (recpos==0) return(EOF);
	}
	cursor=recpos=reclen=0;
	return(OK);
}

LOCAL
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
E 1
