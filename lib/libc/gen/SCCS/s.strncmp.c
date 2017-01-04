h49791
s 00002/00002/00016
d D 5.2 86/03/09 19:58:35 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00014
d D 5.1 85/06/05 12:37:53 mckusick 2 1
c Add copyright
e
s 00015/00000/00000
d D 4.1 80/12/21 16:40:19 wnj 1 0
c date and time created 80/12/21 16:40:19 by wnj
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
 * Compare strings (at most n bytes):  s1>s2: >0  s1==s2: 0  s1<s2: <0
 */

strncmp(s1, s2, n)
register char *s1, *s2;
register n;
{

	while (--n >= 0 && *s1 == *s2++)
		if (*s1++ == '\0')
			return(0);
	return(n<0 ? 0 : *s1 - *--s2);
}
E 1
