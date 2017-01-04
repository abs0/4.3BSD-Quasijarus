h34327
s 00001/00001/00013
d D 1.2 87/02/15 16:08:32 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00014/00000/00000
d D 1.1 87/02/15 16:03:27 lepreau 1 0
c date and time created 87/02/15 16:03:27 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)any	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	If any character of `s' is `c', return 1
	else return 0.
*/

any(c,s)
register char c, *s;
{
	while (*s)
		if (*s++ == c)
			return(1);
	return(0);
}
E 1
