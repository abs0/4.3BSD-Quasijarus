h11061
s 00002/00000/00039
d D 5.3 85/06/20 10:13:13 bloom 3 2
c lint fix from rick adams
e
s 00008/00010/00031
d D 5.2 85/01/22 14:10:46 ralph 2 1
c bug fixes and changes from Rick Adams
e
s 00041/00000/00000
d D 5.1 83/07/02 17:57:26 sam 1 0
c date and time created 83/07/02 17:57:26 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

I 3
/*LINTLIBRARY*/

E 3
D 2
/*******
 *	prefix(s1, s2)	check s2 for prefix s1
 *	char *s1, *s2;
E 2
I 2
/*
 *	check s2 for prefix s1
E 2
 *
 *	return 0 - !=
 *	return 1 - == 
 */

prefix(s1, s2)
register char *s1, *s2;
{
	register char c;

	while ((c = *s1++) == *s2++)
		if (c == '\0')
D 2
			return(1);
	return(c == '\0');
E 2
I 2
			return 1;
	return c == '\0';
E 2
}

D 2
/*******
 *	wprefix(s1, s2)	check s2 for prefix s1 with a wildcard character ?
 *	char *s1, *s2;
E 2
I 2
/*
 *	check s2 for prefix s1 with a wildcard character ?
E 2
 *
 *	return 0 - !=
 *	return 1 - == 
 */

wprefix(s1, s2)
register char *s1, *s2;
{
	register char c;

	while ((c = *s1++) != '\0')
		if (*s2 == '\0'  ||  (c != *s2++  &&  c != '?'))
D 2
			return(0);
	return(1);
E 2
I 2
			return 0;
	return 1;
E 2
}
E 1
