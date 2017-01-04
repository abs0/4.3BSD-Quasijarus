h20099
s 00002/00002/00047
d D 5.2 86/03/09 19:23:02 donn 3 2
c added LIBC_SCCS condition for sccs ids
e
s 00010/00001/00039
d D 5.1 85/05/30 10:27:22 dist 2 1
c Add copyright
e
s 00040/00000/00000
d D 4.1 80/12/21 16:50:36 wnj 1 0
c date and time created 80/12/21 16:50:36 by wnj
e
u
U
t
T
I 1
D 2
/* %W% (Berkeley) %G% */
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 3
#ifndef lint
E 3
I 3
#if defined(LIBC_SCCS) && !defined(lint)
E 3
static char sccsid[] = "%W% (Berkeley) %G%";
D 3
#endif not lint
E 3
I 3
#endif LIBC_SCCS and not lint
E 3

E 2
#include	<stdio.h>

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

	for (;;) {
		bp = buf;
		while((c=getc(pwf)) != '\n') {
			if(c == EOF)
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
