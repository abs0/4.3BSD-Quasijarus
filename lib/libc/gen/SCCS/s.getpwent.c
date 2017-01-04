h47929
s 00002/00002/00094
d D 5.2 86/03/09 19:48:16 donn 9 8
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00086
d D 5.1 85/06/05 12:22:49 mckusick 8 7
c Add copyright
e
s 00010/00006/00077
d D 4.6 85/01/21 20:12:14 serge 7 5
c made setpwfile work with getpwnam and getpwuid
e
s 00010/00006/00077
d R 4.6 85/01/16 15:12:39 serge 6 5
c made setpwfile work with getpwnam and getpwuid
e
s 00003/00003/00080
d D 4.5 84/08/28 14:57:39 ralph 5 4
c unify dbm names, break pwent <-> pwnamuid dependencies.
e
s 00002/00002/00081
d D 4.4 84/06/19 15:50:54 karels 4 3
c cure cancer
e
s 00007/00001/00076
d D 4.3 84/05/17 14:13:17 ralph 3 2
c added setpwfile() so routines can be used with alternate pw files.
e
s 00020/00010/00057
d D 4.2 84/04/26 10:32:46 ralph 2 1
c added stayopen flag for database, defaults to old code if no db.
e
s 00067/00000/00000
d D 4.1 80/12/21 16:50:37 wnj 1 0
c date and time created 80/12/21 16:50:37 by wnj
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
D 8
/* %W% (Berkeley) %E% */
E 8
I 8
/*
 * Copyright (c) 1984 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 9
#ifndef lint
E 9
I 9
#if defined(LIBC_SCCS) && !defined(lint)
E 9
static char sccsid[] = "%W% (Berkeley) %G%";
D 9
#endif not lint
E 9
I 9
#endif LIBC_SCCS and not lint
E 9

E 8
E 4
#include <stdio.h>
#include <pwd.h>
I 2
#include <ndbm.h>
E 2

D 3
static char PASSWD[]	= "/etc/passwd";
E 3
I 3
D 7
static char *PASSWD = "/etc/passwd";
E 7
E 3
static char EMPTY[] = "";
static FILE *pwf = NULL;
static char line[BUFSIZ+1];
static struct passwd passwd;
I 2
D 5
extern DBM *_pw_db;
extern int _pw_stayopen;
E 5
I 5
D 7
DBM *_pw_db;
int _pw_stayopen;
E 7
E 5
E 2

I 7
/*
 * The following are shared with getpwnamuid.c
 */
char	*_pw_file = "/etc/passwd";
DBM	*_pw_db;
int	_pw_stayopen;

E 7
setpwent()
{
D 2
	if( pwf == NULL )
		pwf = fopen( PASSWD, "r" );
E 2
I 2
	if (pwf == NULL)
D 7
		pwf = fopen(PASSWD, "r");
E 7
I 7
		pwf = fopen(_pw_file, "r");
E 7
E 2
	else
D 2
		rewind( pwf );
E 2
I 2
		rewind(pwf);
E 2
}

endpwent()
{
D 2
	if( pwf != NULL ){
		fclose( pwf );
E 2
I 2
	if (pwf != NULL) {
		fclose(pwf);
E 2
		pwf = NULL;
	}
I 2
	if (_pw_db != (DBM *)0) {
D 5
		ndbmclose(_pw_db);
E 5
I 5
		dbm_close(_pw_db);
E 5
		_pw_db = (DBM *)0;
		_pw_stayopen = 0;
	}
E 2
}

static char *
pwskip(p)
register char *p;
{
D 2
	while( *p && *p != ':' )
E 2
I 2
D 4
	while (*p && *p != ':')
E 4
I 4
	while (*p && *p != ':' && *p != '\n')
E 4
E 2
		++p;
D 2
	if( *p ) *p++ = 0;
E 2
I 2
	if (*p)
		*p++ = 0;
E 2
	return(p);
}

struct passwd *
getpwent()
{
	register char *p;

	if (pwf == NULL) {
D 2
		if( (pwf = fopen( PASSWD, "r" )) == NULL )
E 2
I 2
D 7
		if ((pwf = fopen( PASSWD, "r" )) == NULL)
E 7
I 7
		if ((pwf = fopen( _pw_file, "r" )) == NULL)
E 7
E 2
			return(0);
	}
	p = fgets(line, BUFSIZ, pwf);
D 2
	if (p==NULL)
E 2
I 2
	if (p == NULL)
E 2
		return(0);
	passwd.pw_name = p;
	p = pwskip(p);
	passwd.pw_passwd = p;
	p = pwskip(p);
	passwd.pw_uid = atoi(p);
	p = pwskip(p);
	passwd.pw_gid = atoi(p);
	passwd.pw_quota = 0;
	passwd.pw_comment = EMPTY;
	p = pwskip(p);
	passwd.pw_gecos = p;
	p = pwskip(p);
	passwd.pw_dir = p;
	p = pwskip(p);
	passwd.pw_shell = p;
D 2
	while(*p && *p != '\n') p++;
E 2
I 2
	while (*p && *p != '\n')
		p++;
E 2
	*p = '\0';
	return(&passwd);
I 3
}

setpwfile(file)
	char *file;
{
D 7
	PASSWD = file;
E 7
I 7
	_pw_file = file;
E 7
E 3
}
E 1
