h20159
s 00002/00002/00085
d D 5.3 88/04/24 15:33:44 bostic 5 4
c fix for ANSI C
e
s 00002/00002/00085
d D 5.2 86/03/09 19:46:03 donn 4 3
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00083
d D 5.1 85/06/05 12:14:23 mckusick 3 2
c Add copyright
e
s 00001/00001/00083
d D 4.2 84/10/16 21:52:01 sam 2 1
c remove use of '-' as pathname delimiter
e
s 00084/00000/00000
d D 4.1 80/12/21 16:39:39 wnj 1 0
c date and time created 80/12/21 16:39:39 by wnj
e
u
U
t
T
I 1
D 3
/* %W% (Berkeley) %G% */
E 3
I 3
D 4
#ifndef lint
E 4
I 4
#if defined(LIBC_SCCS) && !defined(lint)
E 4
static char sccsid[] = "%W% (Berkeley) %G%";
D 4
#endif not lint
E 4
I 4
#endif LIBC_SCCS and not lint
E 4

E 3
/*
 *	execlp(name, arg,...,0)	(like execl, but does path search)
 *	execvp(name, argv)	(like execv, but does path search)
 */
#include <errno.h>
#define	NULL	0

static	char shell[] =	"/bin/sh";
D 5
char	*execat(), *getenv();
E 5
I 5
char	*getenv();
E 5
extern	errno;

execlp(name, argv)
char *name, *argv;
{
	return(execvp(name, &argv));
}

execvp(name, argv)
char *name, **argv;
{
	char *pathstr;
	register char *cp;
	char fname[128];
D 5
	char *newargs[256];
E 5
I 5
	char *newargs[256], *execat();
E 5
	int i;
	register unsigned etxtbsy = 1;
	register eacces = 0;

	if ((pathstr = getenv("PATH")) == NULL)
		pathstr = ":/bin:/usr/bin";
	cp = index(name, '/')? "": pathstr;

	do {
		cp = execat(cp, name, fname);
	retry:
		execv(fname, argv);
		switch(errno) {
		case ENOEXEC:
			newargs[0] = "sh";
			newargs[1] = fname;
			for (i=1; newargs[i+1]=argv[i]; i++) {
				if (i>=254) {
					errno = E2BIG;
					return(-1);
				}
			}
			execv(shell, newargs);
			return(-1);
		case ETXTBSY:
			if (++etxtbsy > 5)
				return(-1);
			sleep(etxtbsy);
			goto retry;
		case EACCES:
			eacces++;
			break;
		case ENOMEM:
		case E2BIG:
			return(-1);
		}
	} while (cp);
	if (eacces)
		errno = EACCES;
	return(-1);
}

static char *
execat(s1, s2, si)
register char *s1, *s2;
char *si;
{
	register char *s;

	s = si;
D 2
	while (*s1 && *s1 != ':' && *s1 != '-')
E 2
I 2
	while (*s1 && *s1 != ':')
E 2
		*s++ = *s1++;
	if (si != s)
		*s++ = '/';
	while (*s2)
		*s++ = *s2++;
	*s = '\0';
	return(*s1? ++s1: 0);
}
E 1
