h36781
s 00001/00001/00014
d D 1.2 87/02/15 16:09:08 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00015/00000/00000
d D 1.1 87/02/15 16:03:45 lepreau 1 0
c date and time created 87/02/15 16:03:45 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)zeropad	2.2";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	Replace initial blanks with '0's in `str'.
	Return `str'.
*/

char *zeropad(str)
char *str;
{
	register char *s;

	for (s=str; *s == ' '; s++)
		*s = '0';
	return(str);
}
E 1
