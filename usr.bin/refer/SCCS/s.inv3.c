h27258
s 00024/00000/00000
d D 4.1 83/05/06 23:47:30 tut 1 0
c date and time created 83/05/06 23:47:30 by tut
e
u
U
t
T
I 1
#ifndef lint
static char *sccsid = "%W% (Berkeley) %G%";
#endif

getargs(s, arps)
char *s, *arps[];
{
	int i = 0;

	while (1)
	{
		arps[i++] = s;
		while (*s != 0 && *s!=' '&& *s != '\t')
			s++;
		if (*s == 0)
			break;
		*s++ = 0;
		while (*s==' ' || *s=='\t')
			s++;
		if (*s==0)
			break;
	}
	return(i);
}
E 1
