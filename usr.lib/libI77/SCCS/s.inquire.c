h31720
s 00038/00020/00089
d D 5.2 85/07/30 16:27:01 jerry 5 4
c units 0-MAXUNIT always exist, other set exist=false; 
c fill in all requested values all the time, etc.
e
s 00007/00001/00102
d D 5.1 85/06/07 23:48:18 kre 4 3
c Add copyright
e
s 00002/00002/00101
d D 1.3 83/05/09 11:49:47 dlw 3 2
c fixed BLANK= return; fixed NEXTREC return. DLW
e
s 00001/00001/00102
d D 1.2 81/02/20 18:31:55 dlw 2 1
c changed to F_ER codes. DLW
e
s 00103/00000/00000
d D 1.1 81/02/18 18:01:25 dlw 1 0
c date and time created 81/02/18 18:01:25 by dlw
e
u
U
t
T
I 1
/*
D 4
char id_inquire[] = "%W%";
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
 * inquire.c - f77 i/o inquire statement routine
 */

#include "fio.h"

f_inqu(a) inlist *a;
{	char *byfile;
	int i;
I 5
	int exist;
E 5
	unit *p;
	char buf[256], *s;
	long x_inode;

	elist = NO;
	lfname = a->infile;
	lunit = a->inunit;
	external = YES;
	p = NULL;
	if(byfile=a->infile)
	{
		g_char(a->infile,a->infilen,buf);
		if((x_inode=inode(buf))==-1)
D 5
		{	if(a->inex) *a->inex = NO;  /* doesn't exist */
			return(OK);
E 5
I 5
		{	exist = NO;  /* file doesn't exist */
E 5
		}
D 5
		for(i=0;i<MXUNIT;i++)
			if(units[i].ufd && (units[i].uinode==x_inode))
			{
				p = &units[i];
				break;
			}
E 5
I 5
		else
		{	exist = YES;  /* file does exist */
			for(i=0;i<MXUNIT;i++)
				if(units[i].ufd && (units[i].uinode==x_inode))
				{
					p = &units[i];
					break;
				}
		}
E 5
	}
	else
	{
D 2
		if (not_legal(lunit)) err(a->inerr,101,"inquire")
E 2
I 2
D 5
		if (not_legal(lunit)) err(a->inerr,F_ERUNIT,"inquire")
E 5
I 5
		if (not_legal(lunit))
		{	exist = NO;  /* unit doesn't exist */
		}
E 5
E 2
		else
I 5
		{	exist = YES;
E 5
			if (units[lunit].ufd)
			{	p= &units[lunit];
				lfname = p->ufnm;
			}
I 5
		}
E 5
	}
D 5
	if(a->inex) *a->inex= ((byfile && x_inode) || (!byfile && p));
E 5
I 5
	if(a->inex) *a->inex = exist;
E 5
	if(a->inopen) *a->inopen=(p!=NULL);
D 5
	if(a->innum) *a->innum= (p?(p-units):-1);
E 5
I 5
	if(a->innum) *a->innum = byfile?(p?(p-units):-1):lunit;
E 5
	if(a->innamed) *a->innamed= (byfile || (p && p->ufnm));
	if(a->inname)
	{
		if(byfile) s = buf;
		else if(p && p->ufnm) s = p->ufnm;
		else s="";
		b_char(s,a->inname,a->innamlen);
	}
D 5
	if(a->inacc && p)
E 5
I 5
	if(a->inacc)
E 5
	{
D 5
		if(p->url) s = "direct";
E 5
I 5
		if(!p) s = "unknown";
		else if(p->url) s = "direct";
E 5
		else	s = "sequential";
		b_char(s,a->inacc,a->inacclen);
	}
	if(a->inseq)
	{
D 5
		s= ((byfile && !p) || (p && !p->url))? "yes" : "no";
E 5
I 5
		if(!p) s = "unknown";
		else s = (p && !p->url)? "yes" : "no";
E 5
		b_char(s,a->inseq,a->inseqlen);
	}
	if(a->indir)
	{
D 5
		s= ((byfile && !p) || (p && p->useek && p->url))? "yes" : "no";
E 5
I 5
		if(!p) s = "unknown";
		else s = (p && p->useek && p->url)? "yes" : "no";
E 5
		b_char(s,a->indir,a->indirlen);
	}
	if(a->inform)
	{	if(p)
		{
#ifndef KOSHER
			if(p->uprnt) s = "print"; /*** NOT STANDARD FORTRAN ***/
			else
#endif
				s = p->ufmt?"formatted":"unformatted";
		}
		else s = "unknown";
		b_char(s,a->inform,a->informlen);
	}
	if(a->infmt)
	{
		if (p) s= p->ufmt? "yes" : "no";
		else s= "unknown";
		b_char(s,a->infmt,a->infmtlen);
	}
	if(a->inunf)
	{
		if (p) s= p->ufmt? "no" : "yes";
		else s= "unknown";
		b_char(s,a->inunf,a->inunflen);
	}
D 5
	if(a->inrecl && p) *a->inrecl=p->url;
	if(a->innrec && p && p->url)
D 3
		*a->innrec=(ftell(p->ufd)/p->url)+1;
E 3
I 3
		*a->innrec=((ftell(p->ufd) + p->url - 1)/p->url) + 1;
E 3
	if(a->inblank && p && p->ufmt)
E 5
I 5
	if(a->inrecl) *a->inrecl = p ? p->url : -1;
	if(a->innrec) {
		if(p && p->url)
			*a->innrec = ((ftell(p->ufd) + p->url - 1)/p->url) + 1;
		else
			*a->innrec = -1;
	}
	if(a->inblank)
E 5
	{
D 3
		b_char(p->ublnk? "zero" : "blank",a->inblank,a->inblanklen);
E 3
I 3
D 5
		b_char(p->ublnk? "zero" : "null",a->inblank,a->inblanklen);
E 5
I 5
		if( p && p->ufmt)
			s = p->ublnk ? "zero" : "null" ;
		else
			s = "unknown";
		b_char(s,a->inblank,a->inblanklen);
E 5
E 3
	}
	return(OK);
}
E 1
