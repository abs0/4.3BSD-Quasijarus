h54647
s 00001/00001/00020
d D 1.2 87/02/15 16:08:55 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00021/00000/00000
d D 1.1 87/02/15 16:03:38 lepreau 1 0
c date and time created 87/02/15 16:03:38 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)trnslat	2.2";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Copy `str' to `result' replacing any character found
	in both `str' and `old' with the corresponding character from `new'.
	Return `result'.
*/

char *trnslat(str,old,new,result)
register char *str;
char *old, *new, *result;
{
	register char *r, *o;

	for (r = result; *r = *str++; r++)
		for (o = old; *o; )
			if (*r == *o++) {
				*r = new[o - old -1];
				break;
			}
	return(result);
}
E 1
