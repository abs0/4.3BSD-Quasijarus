h43524
s 00007/00001/00011
d D 5.1 85/05/07 12:14:46 dist 2 1
c Add copyright notice
e
s 00012/00000/00000
d D 4.1 83/11/10 14:43:33 ralph 1 0
c date and time created 83/11/10 14:43:33 by ralph
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

#include "hp7221.h"

label(s)
char *s;
{
	printf("~'%s", s);
	putchar( ENDOFSTRING );
}
E 1
