h41029
s 00001/00001/00014
d D 1.2 87/02/15 16:08:39 lepreau 2 1
c fix sccsid to use keywords and modern initialization syntax
e
s 00015/00000/00000
d D 1.1 87/02/15 16:03:30 lepreau 1 0
c date and time created 87/02/15 16:03:30 by lepreau
e
u
U
t
T
I 1
D 2
static char Sccsid[] "@(#)imatch	2.1";
E 2
I 2
static char Sccsid[] = "%W%	%G%";
E 2
/*
	initial match
	if `prefix' is a prefix of `string' return 1
	else return 0
*/

imatch(prefix,string)
register char *prefix, *string;
{
	while (*prefix++ == *string++)
		if (*prefix == 0)
			return(1);
	return(0);
}
E 1
