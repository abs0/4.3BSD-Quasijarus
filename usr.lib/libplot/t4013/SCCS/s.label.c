h43415
s 00007/00001/00011
d D 5.1 85/06/07 08:26:37 dist 2 1
c Add copyright
e
s 00012/00000/00000
d D 1.1 85/01/02 20:10:40 jak 1 0
c date and time created 85/01/02 20:10:40 by jak
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

label(s)
char *s;
{
	register i,c;
	putch(037);	/* alpha mode */
	for(i=0; c=s[i]; i++)
		putch(c);
}
E 1
