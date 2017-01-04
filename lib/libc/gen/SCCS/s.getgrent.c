h15661
s 00007/00001/00064
d D 5.3 87/11/05 14:35:17 bostic 6 5
c add setgrfile; bug report 4.3BSD/lib/96
e
s 00002/00002/00063
d D 5.2 86/03/09 19:47:14 donn 5 4
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00062
d D 5.1 85/06/05 12:19:19 mckusick 4 3
c Add copyright
e
s 00001/00001/00062
d D 4.3 83/08/18 14:56:20 sam 3 2
c upped limit to keep sites with many users happy
e
s 00008/00009/00055
d D 4.2 82/03/29 01:47:11 wnj 2 1
c bounds checking
e
s 00064/00000/00000
d D 4.1 80/12/21 16:50:31 wnj 1 0
c date and time created 80/12/21 16:50:31 by wnj
e
u
U
t
T
I 1
D 4
/* %W% (Berkeley) %G% */
E 4
I 4
D 5
#ifndef lint
E 5
I 5
#if defined(LIBC_SCCS) && !defined(lint)
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif not lint
E 5
I 5
#endif LIBC_SCCS and not lint
E 5
E 4
I 2

E 2
#include <stdio.h>
#include <grp.h>

D 2
#define	CL	':'
#define	CM	','
#define	NL	'\n'
E 2
D 3
#define	MAXGRP	100
E 3
I 3
#define	MAXGRP	200
E 3

D 6
static char GROUP[] = "/etc/group";
E 6
I 6
static char *GROUP = "/etc/group";
E 6
static FILE *grf = NULL;
static char line[BUFSIZ+1];
static struct group group;
static char *gr_mem[MAXGRP];

setgrent()
{
	if( !grf )
		grf = fopen( GROUP, "r" );
	else
		rewind( grf );
}

endgrent()
{
	if( grf ){
		fclose( grf );
		grf = NULL;
	}
}

static char *
grskip(p,c)
register char *p;
register c;
{
	while( *p && *p != c ) ++p;
	if( *p ) *p++ = 0;
	return( p );
}

struct group *
getgrent()
{
	register char *p, **q;

	if( !grf && !(grf = fopen( GROUP, "r" )) )
		return(NULL);
	if( !(p = fgets( line, BUFSIZ, grf )) )
		return(NULL);
	group.gr_name = p;
D 2
	group.gr_passwd = p = grskip(p,CL);
	group.gr_gid = atoi( p = grskip(p,CL) );
E 2
I 2
	group.gr_passwd = p = grskip(p,':');
	group.gr_gid = atoi( p = grskip(p,':') );
E 2
	group.gr_mem = gr_mem;
D 2
	p = grskip(p,CL);
	grskip(p,NL);
E 2
I 2
	p = grskip(p,':');
	grskip(p,'\n');
E 2
	q = gr_mem;
	while( *p ){
D 2
		*q++ = p;
		p = grskip(p,CM);
E 2
I 2
		if (q < &gr_mem[MAXGRP-1])
			*q++ = p;
		p = grskip(p,',');
E 2
	}
	*q = NULL;
	return( &group );
I 6
}

setgrfile(file)
	char *file;
{
	GROUP = file;
E 6
}
E 1
