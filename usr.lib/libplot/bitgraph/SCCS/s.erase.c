h56336
s 00009/00002/00011
d D 5.2 85/04/30 16:15:10 dist 3 2
c add copyright
e
s 00001/00001/00012
d D 5.1 85/04/30 15:43:43 dist 2 1
c add copyright
e
s 00013/00000/00000
d D 4.1 83/11/10 11:01:33 ralph 1 0
c date and time created 83/11/10 11:01:33 by ralph
e
u
U
t
T
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 3
I 1
#ifndef lint
D 2
static char sccsid[] = "%W% (Berkeley) %G%";
E 2
I 2
D 3
static char sccsid[] = "@(#)erase.c	4.1 (Berkeley) 11/10/83";
E 2
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3

#include "bg.h"

erase()
{
	putchar( ESC );
	printf("[H");
	putchar( ESC );
	printf("[J");
}
E 1
