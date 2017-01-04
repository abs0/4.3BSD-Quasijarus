h46704
s 00001/00001/00017
d D 1.2 87/02/15 16:08:46 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00018/00000/00000
d D 1.1 87/02/15 16:03:34 lepreau 1 0
c date and time created 87/02/15 16:03:34 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)repeat	2.2";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Set `result' equal to `str' repeated `repfac' times.
	Return `result'.
*/

char *repeat(result,str,repfac)
char *result, *str;
register unsigned repfac;
{
	register char *r, *s;

	r = result;
	for (++repfac; --repfac > 0; --r)
		for (s=str; *r++ = *s++; );
	*r = '\0';
	return(result);
}
E 1
