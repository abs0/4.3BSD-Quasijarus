h51276
s 00008/00001/00016
d D 5.1 85/06/07 09:29:46 dist 2 1
c Add copyright
e
s 00017/00000/00000
d D 1.1 85/01/02 20:29:46 jak 1 0
c date and time created 85/01/02 20:29:46 by jak
e
u
U
t
T
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 2
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 2
#endif
E 2
I 2
#endif not lint

E 2
linemd_(s, len)
register char *s;
long len;
{
	char buf[256];
	register char *cp, *cend;

	cp = buf;
	cend = cp + (len < 255 ? len : 255 );
	while ( cp < cend  && *s != ' ') 
		*cp++ = *s++;
	*cp = 0;
	linemod( buf );
}
E 1
