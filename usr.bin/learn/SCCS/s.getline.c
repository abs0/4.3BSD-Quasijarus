h29991
s 00020/00000/00000
d D 1.1 88/06/08 15:14:34 jak 1 0
c date and time created 88/06/08 15:14:34 by jak
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include <stdio.h>

getline(s, lim)	/* get line into s, return length */
char s[];
int lim;
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return(i);
}
E 1
