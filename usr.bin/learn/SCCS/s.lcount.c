h29318
s 00000/00000/00016
d D 4.2 83/04/25 23:58:48 mckusick 2 1
c 
e
s 00016/00000/00000
d D 4.1 83/02/24 12:55:45 mckusick 1 0
c date and time created 83/02/24 12:55:45 by mckusick
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W%	(Berkeley)	%G%";
#endif not lint

#include "stdio.h"

main()	/* count lines in something */
{
	register n, c;

	n = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			n++;
	printf("%d\n", n);
}
E 1
