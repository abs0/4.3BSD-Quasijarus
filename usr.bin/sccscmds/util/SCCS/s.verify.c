h49190
s 00001/00001/00017
d D 1.2 87/02/15 16:09:04 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00018/00000/00000
d D 1.1 87/02/15 16:03:42 lepreau 1 0
c date and time created 87/02/15 16:03:42 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)verify	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	If `astr1' contains any characters not in `str2' return the
	offset of the first such character found in `astr1',
	else return -1.
*/

verify(astr1,str2)
char *astr1;
register char *str2;
{
	register char *str1;

	for (str1=astr1; *str1; str1++)
		if (!any(*str1,str2))
			return(str1 - astr1 - 1);
	return(-1);
}
E 1
