h44362
s 00001/00000/00022
d D 1.2 89/05/10 22:42:20 bostic 2 1
c add types.h for pwd.h
e
s 00022/00000/00000
d D 1.1 89/04/12 10:30:50 bostic 1 0
c date and time created 89/04/12 10:30:50 by bostic
e
u
U
t
T
I 2
#include <sys/types.h>
E 2
I 1
#include <pwd.h>
extern struct passwd *getpwuid();
extern char *getlogin();
extern char *getenv();

char *
logname()
{
	register struct passwd *pw;
	register char *cp;

	cp = getenv("USER");
	if (cp != 0 && *cp != '\0')
		return (cp);
	cp = getlogin();
	if (cp != 0 && *cp != '\0')
		return (cp);
	setpwent();
	pw=getpwuid(getuid());
	endpwent();
	return(pw->pw_name);
}
E 1
