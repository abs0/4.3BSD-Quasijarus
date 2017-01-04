h08415
s 00007/00001/00033
d D 5.1 85/05/07 11:50:55 dist 2 1
c Add copyright notice
e
s 00034/00000/00000
d D 4.1 83/11/10 16:05:44 ralph 1 0
c date and time created 83/11/10 16:05:44 by ralph
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

/*
 * Displays plot files on a gigi "graphics" terminal.
 */

#include <signal.h>
#include "gigi.h"

int currentx = 0;
int currenty = 0;
double lowx = 0.0;
double lowy = 0.0;
double scalex = 1.0;
double scaley = 1.0;

openpl()
{
	int closepl();

	/* catch interupts */
	signal(SIGINT, closepl);
	currentx = 0;
	currenty = 0;
	/* enter grapics mode */
	putchar(ESC); putchar('P'); putchar('p');

	/* set some parameters */
	printf("S(I0 T0 [0,0])");

	space(0, 0, XMAX, YMAX);
}
E 1
