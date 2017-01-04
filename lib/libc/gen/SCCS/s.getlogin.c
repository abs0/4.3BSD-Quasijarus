h08172
s 00002/00000/00031
d D 5.3 86/05/09 16:14:11 lepreau 8 6
c return 0 not null string when user has a ctty but no utmp entry
e
s 00002/00000/00031
d R 5.3 86/05/09 16:00:19 lepreau 7 6
c avoid return pointer to a null string; return 0 instead
e
s 00002/00002/00029
d D 5.2 86/03/09 19:47:51 donn 6 5
c added LIBC_SCCS condition for sccs ids
e
s 00003/00001/00028
d D 5.1 85/06/05 12:45:28 mckusick 5 2
c Add copyright
e
s 00009/00001/00028
d R 5.1 85/06/05 12:20:57 mckusick 4 2
c Add copyright
e
s 00029/00012/00017
d R 4.3 84/04/27 10:32:15 ralph 3 2
c new versions which use getttyent(3).
e
s 00015/00012/00014
d D 4.2 82/11/14 13:59:06 sam 2 1
c merge of 4.1b and 4.1c
e
s 00026/00000/00000
d D 4.1 82/11/07 19:06:08 sam 1 0
c date and time created 82/11/07 19:06:08 by sam
e
u
U
t
T
I 1
D 2
/*	%W% (Berkeley) %G%	*/
E 2
I 2
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
D 6
#ifndef lint
E 6
I 6
#if defined(LIBC_SCCS) && !defined(lint)
E 6
static char sccsid[] = "%W% (Berkeley) %G%";
D 6
#endif not lint
E 6
I 6
#endif LIBC_SCCS and not lint
E 6
E 5

E 2
#include <utmp.h>

D 2
static	char	UTMP[]	= "/etc/utmp";
static	struct	utmp ubuf;
E 2
I 2
static	char UTMP[]	= "/etc/utmp";
static	struct utmp ubuf;
E 2

char *
getlogin()
{
D 2
	register me, uf;
E 2
I 2
	register int me, uf;
E 2
	register char *cp;

D 2
	if( !(me = ttyslot()) )
E 2
I 2
	if (!(me = ttyslot()))
E 2
		return(0);
D 2
	if( (uf = open( UTMP, 0 )) < 0 )
		return(0);
	lseek( uf, (long)(me*sizeof(ubuf)), 0 );
	if (read(uf, (char *)&ubuf, sizeof(ubuf)) != sizeof(ubuf))
		return(0);
E 2
I 2
	if ((uf = open(UTMP, 0)) < 0)
		return (0);
	lseek (uf, (long)(me*sizeof(ubuf)), 0);
	if (read(uf, (char *)&ubuf, sizeof (ubuf)) != sizeof (ubuf)) {
		close(uf);
		return (0);
	}
E 2
	close(uf);
I 8
	if (ubuf.ut_name[0] == '\0')
		return (0);
E 8
	ubuf.ut_name[sizeof (ubuf.ut_name)] = ' ';
D 2
	for (cp=ubuf.ut_name; *cp++!=' ';)
E 2
I 2
	for (cp = ubuf.ut_name; *cp++ != ' '; )
E 2
		;
	*--cp = '\0';
D 2
	return( ubuf.ut_name );
E 2
I 2
	return (ubuf.ut_name);
E 2
}
E 1
