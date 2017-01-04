h31488
s 00021/00000/00000
d D 1.1 87/09/26 19:04:17 bostic 1 0
c date and time created 87/09/26 19:04:17 by bostic
e
u
U
t
T
I 1
# include	<stdio.h>
# include	<ctype.h>

# define	reg	register

# define	makelower(c)	(isupper(c) ? tolower(c) : c)

/*
 * Compare strings:  s1>s2: >0  s1==s2: 0  s1<s2: <0
 */

strcmp(s1, s2)
reg char	*s1, *s2; {

	while (makelower(*s1) == makelower(*s2)) {
		if (*s1 == '\0')
			return 0;
		s1++, s2++;
	}
	return *s1 - *s2;
}
E 1
