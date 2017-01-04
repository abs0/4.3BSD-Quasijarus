h22378
s 00013/00000/00000
d D 4.1 83/06/27 14:43:18 sam 1 0
c date and time created 83/06/27 14:43:18 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>
label(s)
char *s;
{
	int i;
	putc('t',stdout);
	for(i=0;s[i];)putc(s[i++],stdout);
	putc('\n',stdout);
}
E 1
