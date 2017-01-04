h20316
s 00007/00001/00055
d D 5.1 85/06/07 23:54:48 kre 2 1
c Add copyright
e
s 00056/00000/00000
d D 1.1 85/05/21 20:09:04 libs 1 0
c date and time created 85/05/21 20:09:04 by libs
e
u
U
t
T
I 1
/*
D 2
char id_rfi[] = "%W%";
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
 * internal (character array) i/o: read formatted, sequential and direct
 */

#include "fio.h"

extern int rd_ed(),rd_ned();
extern int z_getc(),z_rnew(),z_tab();

LOCAL
c_rfi()
{
	reading = YES;
	doed=rd_ed;
	doned=rd_ned;
	getn=z_getc;
	doend = donewrec = z_rnew;
	dorevert = z_rnew;
	dotab = z_tab;
}

s_rsfi(a) icilist *a;
{
	int n;

	c_rfi();
	if( n = c_si(a) ) return (n);
	if(pars_f()) err(errflag,F_ERFMT,"rsfio")
	fmt_bg();
	return( OK );
}

s_rdfi(a) icilist *a;
{
	int n;

	c_rfi();
	if( n = c_di(a) ) return (n);
	if(pars_f()) err(errflag,F_ERFMT,"rdfio")
	fmt_bg();
	return( OK );
}

e_rsfi()
{	int n;
	n = en_fio();
	fmtbuf = NULL;
	return(n);
}

e_rdfi()
{
	return(e_rsfi());
}
E 1
