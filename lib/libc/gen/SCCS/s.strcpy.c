h48210
s 00002/00002/00018
d D 5.2 86/03/09 19:57:52 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00016
d D 5.1 85/06/05 12:36:52 mckusick 2 1
c Add copyright
e
s 00017/00000/00000
d D 4.1 82/10/05 21:00:05 root 1 0
c date and time created 82/10/05 21:00:05 by root
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
D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3

E 2
/*
 * Copy string s2 to s1.  s1 must be large enough.
 * return s1
 */

char *
strcpy(s1, s2)
register char *s1, *s2;
{
	register char *os1;

	os1 = s1;
	while (*s1++ = *s2++)
		;
	return(os1);
}
E 1
