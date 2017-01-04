h38223
s 00004/00001/00014
d D 5.1 85/06/05 12:24:32 mckusick 2 1
c Add copyright
e
s 00015/00000/00000
d D 4.1 80/12/21 16:50:39 wnj 1 0
c date and time created 80/12/21 16:50:39 by wnj
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
getpwnam(name)
char *name;
{
	register struct passwd *p;
	struct passwd *getpwent();

	setpwent();
	while( (p = getpwent()) && strcmp(name,p->pw_name) );
	endpwent();
	return(p);
}
E 1
