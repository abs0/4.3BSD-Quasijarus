h37616
s 00004/00001/00014
d D 5.1 85/06/05 12:25:06 mckusick 2 1
c Add copyright
e
s 00015/00000/00000
d D 4.1 80/12/21 16:50:40 wnj 1 0
c date and time created 80/12/21 16:50:40 by wnj
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 2
#include <pwd.h>

struct passwd *
getpwuid(uid)
register uid;
{
	register struct passwd *p;
	struct passwd *getpwent();

	setpwent();
	while( (p = getpwent()) && p->pw_uid != uid );
	endpwent();
	return(p);
}
E 1
