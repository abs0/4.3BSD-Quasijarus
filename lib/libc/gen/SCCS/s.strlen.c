h45781
s 00002/00002/00017
d D 5.2 86/03/09 19:58:07 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00004/00001/00015
d D 5.1 85/06/05 12:37:13 mckusick 2 1
c Add copyright
e
s 00016/00000/00000
d D 4.1 80/12/21 16:40:16 wnj 1 0
c date and time created 80/12/21 16:40:16 by wnj
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
 * Returns the number of
 * non-NULL bytes in string argument.
 */

strlen(s)
register char *s;
{
	register n;

	n = 0;
	while (*s++)
		n++;
	return(n);
}
E 1
