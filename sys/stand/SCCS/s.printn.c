h55094
s 00032/00000/00000
d D 7.1 88/02/05 16:58:20 bostic 1 0
c date and time created 88/02/05 16:58:20 by bostic
e
u
U
t
T
I 1
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

#include "param.h"

/*
 * Printn prints a number n in base b.
 * We don't use recursion to avoid deep kernel stacks.
 */
printn(n, b)
	u_long n;
	int b;
{
	register char *cp;
	char prbuf[11];

	if (b == 10 && (int)n < 0) {
		putchar('-');
		n = (unsigned)(-(int)n);
	}
	cp = prbuf;
	do {
		*cp++ = "0123456789abcdef"[n%b];
		n /= b;
	} while (n);
	do
		putchar(*--cp);
	while (cp > prbuf);
}
E 1
