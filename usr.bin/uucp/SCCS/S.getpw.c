h55095
s 00001/00001/00043
d D 5.2 83/07/02 18:25:10 sam 2 1
c include fixes
e
s 00044/00000/00000
d D 5.1 83/07/02 17:56:55 sam 1 0
c date and time created 83/07/02 17:56:55 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

D 2
#include "stdio.h"
E 2
I 2
#include <stdio.h>
E 2

getpw(uid, buf)
int uid;
char buf[];
{
	static FILE *pwf;
	register n, c;
	register char *bp;

	if(pwf == 0)
		pwf = fopen("/etc/passwd", "r");
	if(pwf == NULL)
		return(1);
	rewind(pwf);
	uid &= 0377;

	for (;;) {
		bp = buf;
		while((c=getc(pwf)) != '\n') {
			if(c <= 0)
				return(1);
			*bp++ = c;
		}
		*bp++ = '\0';
		bp = buf;
		n = 3;
		while(--n)
		while((c = *bp++) != ':')
			if(c == '\n')
				return(1);
		while((c = *bp++) != ':') {
			if(c<'0' || c>'9')
				continue;
			n = n*10+c-'0';
		}
		if(n == uid)
			return(0);
	}
}
E 1
