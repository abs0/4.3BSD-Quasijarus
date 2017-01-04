h48023
s 00001/00001/00036
d D 5.2 85/06/07 23:01:57 kre 5 4
c fix botch in previous delta
e
s 00005/00001/00032
d D 5.1 85/06/07 22:30:48 kre 4 3
c Add copyright
e
s 00013/00005/00020
d D 1.3 84/10/03 22:27:10 dlw 3 2
c made it work. DLW
e
s 00001/00001/00024
d D 1.2 81/03/02 10:07:28 dlw 2 1
c now uses s_cmp from libF77. DLW
e
s 00025/00000/00000
d D 1.1 81/02/19 21:58:58 dlw 1 0
c date and time created 81/02/19 21:58:58 by dlw
e
u
U
t
T
I 1
/*
D 4
char id_rindex[] = "%W%";
E 4
I 4
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 4
 *
I 4
 *	%W%	%G%
D 5
 */
E 5
I 5
 *
E 5
E 4
 * find last occurrence of substring in string
 *
 * calling sequence:
 *	character*(*) substr, string
 *	indx = rindex (string, substr)
 * where:
 *	indx will be the index of the first character of the last occurence
 *	of substr in string, or zero if not found.
 */

long rindex_(str, substr, slen, sublen)
char *str, *substr; long slen, sublen;
{
D 3
	register char *p = str + (slen - sublen);
E 3
I 3
	register char	*p = str + (slen - sublen);
	register char	*p1, *p2;
	register int	len;
E 3

D 3
	while (p >= str)
D 2
		if (strncmp(p, substr, (int)sublen) == 0)
E 2
I 2
		if (s_cmp(substr, p, sublen, slen) == 0)
E 3
I 3
	if (sublen == 0)
		return(0L);
	while (p >= str) {
		p1 = p;
		p2 = substr;
		len = sublen;
		while ( *p1++ == *p2++ && --len > 0) ;
		if ( len <= 0 )
E 3
E 2
			return((long)(++p - str));
D 3
		else
			p--;
E 3
I 3
		p--;
	}
E 3
	return(0L);
}
E 1
