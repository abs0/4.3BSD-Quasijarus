h56009
s 00002/00002/00023
d D 5.2 86/03/09 19:58:48 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00021
d D 5.1 85/06/05 12:38:10 mckusick 2 1
c Add copyright
e
s 00022/00000/00000
d D 4.1 80/12/21 16:40:20 wnj 1 0
c date and time created 80/12/21 16:40:20 by wnj
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
 * Copy s2 to s1, truncating or null-padding to always copy n bytes
 * return s1
 */

char *
strncpy(s1, s2, n)
register char *s1, *s2;
{
	register i;
	register char *os1;

	os1 = s1;
	for (i = 0; i < n; i++)
		if ((*s1++ = *s2++) == '\0') {
			while (++i < n)
				*s1++ = '\0';
			return(os1);
		}
	return(os1);
}
E 1
