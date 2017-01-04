h17697
s 00014/00000/00000
d D 5.1 86/11/03 20:00:11 mckusick 1 0
c from CCI
e
u
U
t
T
I 1
/*
 *	%W% (Berkeley) %G%
 */

#include <stdio.h>

/* print a character string */
outstr_(s, n)
register char *s;
register long n;
{
while ( --n >= 0)
	putchar(*s++);
}
E 1
