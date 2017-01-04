h10471
s 00010/00005/00124
d D 5.3 88/06/18 15:08:34 bostic 4 3
c install approved copyright notice
e
s 00009/00003/00120
d D 5.2 88/05/05 18:35:00 bostic 3 2
c written by Eric Allman; add Berkeley header
e
s 00007/00001/00116
d D 5.1 85/05/30 09:05:43 dist 2 1
c Add copyright
e
s 00117/00000/00000
d D 4.1 83/03/23 15:01:59 mckusick 1 0
c date and time created 83/03/23 15:01:59 by mckusick
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
D 3
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 3
I 3
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
D 4
 * provided that this notice is preserved and that due credit is given
 * to the University of California at Berkeley. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
E 4
I 4
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 4
E 3
 */

E 2
I 1
#ifndef lint
D 2
static char sccsid[] = "%W%	(Berkeley)	%G%";
E 2
I 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
D 3
#endif not lint
E 3
I 3
#endif /* not lint */
E 3

/*
**  ASSORTED UTILITY ROUTINES
*/

/*
**  BLOCK MOVE
**
**	Moves a block of storage of length `l' bytes from the data
**	area pointed to by `a' to the area pointed to by `b'.
**	Returns the address of the byte following the `b' field.
**	Overflow of `b' is not tested.
*/

char *bmove(a, b, l)
char	*a, *b;
int	l;
{
	register int		n;
	register char		*p, *q;

	p = a;
	q = b;
	n = l;
	while (n--)
		*q++ = *p++;
	return (q);
}


/*
**  STRING EQUALITY TEST
**	null-terminated strings `a' and `b' are tested for
**	absolute equality.
**	returns one if equal, zero otherwise.
*/

sequal(a, b)
char	*a, *b;
{
	register char		*p, *q;

	p = a;
	q = b;
	while (*p || *q)
		if (*p++ != *q++)
			return(0);
	return(1);
}


/*
**  STRING CONCATENATE
**
**	The strings `s1' and `s2' are concatenated and stored into
**	`s3'.  It is ok for `s1' to equal `s3', but terrible things
**	will happen if `s2' equals `s3'.  The return value is is a
**	pointer to the end of `s3' field.
*/

char *concat(s1, s2, s3)
char	*s1, *s2, *s3;
{
	register char		*p;
	register char		*q;

	p = s3;
	q = s1;
	while (*q)
		*p++ = *q++;
	q = s2;
	while (*q)
		*p++ = *q++;
	*p = 0;
	return (p);
}


/*
**  FIND STRING LENGTH
**
**	The length of string `s' (excluding the null byte which
**		terminates the string) is returned.
*/

length(s)
char	*s;
{
	register int	l;
	register char	*p;

	l = 0;
	p = s;
	while (*p++)
		l++;
	return(l);
}


/*
**  SYSTEM ERROR
*/

syserr(p0, p1, p2, p3, p4, p5)
{
	extern int	errno;

	printf("\n\07TREK SYSERR: ");
	printf(p0, p1, p2, p3, p4, p5);
	printf("\n");
	if (errno)
		printf("\tsystem error %d\n", errno);
	exit(-1);
}
E 1
