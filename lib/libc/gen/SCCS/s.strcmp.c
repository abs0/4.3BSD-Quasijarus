h45705
s 00002/00002/00015
d D 5.2 86/03/09 19:57:36 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00013
d D 5.1 85/06/05 12:36:35 mckusick 2 1
c Add copyright
e
s 00014/00000/00000
d D 4.1 80/12/21 16:40:10 wnj 1 0
c date and time created 80/12/21 16:40:10 by wnj
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
 * Compare strings:  s1>s2: >0  s1==s2: 0  s1<s2: <0
 */

strcmp(s1, s2)
register char *s1, *s2;
{

	while (*s1 == *s2++)
		if (*s1++=='\0')
			return(0);
	return(*s1 - *--s2);
}
E 1
