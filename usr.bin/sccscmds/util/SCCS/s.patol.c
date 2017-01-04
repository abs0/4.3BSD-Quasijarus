h44653
s 00001/00001/00020
d D 1.2 87/02/15 16:08:43 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00021/00000/00000
d D 1.1 87/02/15 16:03:33 lepreau 1 0
c date and time created 87/02/15 16:03:33 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)patol	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Function to convert ascii string to long.  Converts
	positive numbers only.  Returns -1 if non-numeric
	character encountered.
*/

long
patol(s)
register char *s;
{
	long i;

	i = 0;
	while (*s >= '0' && *s <= '9')
		i = 10*i + *s++ - '0';

	if (*s)
		return(-1);
	return(i);
}
E 1
