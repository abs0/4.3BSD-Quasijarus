h34053
s 00026/00000/00000
d D 4.1 82/03/01 01:06:15 wnj 1 0
c date and time created 82/03/01 01:06:15 by wnj
e
u
U
t
T
I 1
char	*sccsid = "%W% (Berkeley) %I%";

#include <stdio.h>

char linebuf[1024];
/*
 * rfc678
 */
main()
{
	register char *cp;
	int lineno = 0;

	while (gets(linebuf)) {
		for (cp = linebuf; *cp; cp++)
			if (*cp == 010) {
				strcpy(cp-1, cp+1);
				cp -= 2;
			}
		if (++lineno <= 59)
			printf("%s\n", linebuf);
		else if (lineno == 60)
			printf("%s\f\n", linebuf);
		lineno %= 66;
	}
}
E 1
