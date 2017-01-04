h34578
s 00024/00000/00000
d D 5.1 85/06/23 15:41:11 bloom 1 0
c date and time created 85/06/23 15:41:11 by bloom
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

/*LINTLIBRARY*/

/*
 * this is like index, but takes a string as the second argument
 */
char *
strpbrk(str, chars)
register char *str, *chars;
{
	register char *cp;

	do {
		cp = chars - 1;
		while (*++cp) {
			if (*str == *cp)
				return str;
		}
	} while (*str++);
	return (char *)0;
}
E 1
