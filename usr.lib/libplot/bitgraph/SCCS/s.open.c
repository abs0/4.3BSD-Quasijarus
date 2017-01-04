h09339
s 00009/00002/00026
d D 5.2 85/04/30 16:15:31 dist 3 2
c add copyright
e
s 00001/00001/00027
d D 5.1 85/04/30 15:44:01 dist 2 1
c add copyright
e
s 00028/00000/00000
d D 4.1 83/11/10 11:02:44 ralph 1 0
c date and time created 83/11/10 11:02:44 by ralph
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
static char sccsid[] = "@(#)open.c	4.1 (Berkeley) 11/10/83";
E 2
#endif
E 3
I 3
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3

/*
 * Displays plot files on a BBN bitgraph terminal.
 */

#include <signal.h>
#include "bg.h"

int currentx = 0;
int currenty = 0;
double lowx = 0.0;
double lowy = 0.0;
double scale = 1.0;

openpl()
{
	int closepl();

	/* catch interupts */
	signal(SIGINT, closepl);
	currentx = 0;
	currenty = 0;

	space(0, 0, XMAX, YMAX);
}
E 1
