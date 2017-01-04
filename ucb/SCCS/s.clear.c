h45936
s 00016/00001/00042
d D 5.1 85/05/31 09:08:12 dist 3 2
c Add copyright
e
s 00001/00001/00042
d D 4.2 85/01/08 17:13:35 serge 2 1
c Exit status was inverted.
e
s 00043/00000/00000
d D 4.1 80/10/01 17:25:36 bill 1 0
c date and time created 80/10/01 17:25:36 by bill
e
u
U
t
T
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 3
/* load me with -ltermlib */
/* #include <retrofit.h> on version 6 */
/*
 * clear - clear the screen
 */

#include <stdio.h>
#include <sgtty.h>

char	*getenv();
char	*tgetstr();
char	PC;
short	ospeed;
#undef	putchar
int	putchar();

main()
{
	char *cp = getenv("TERM");
	char clbuf[20];
	char pcbuf[20];
	char *clbp = clbuf;
	char *pcbp = pcbuf;
	char *clear;
	char buf[1024];
	char *pc;
	struct sgttyb tty;

	gtty(1, &tty);
	ospeed = tty.sg_ospeed;
	if (cp == (char *) 0)
		exit(1);
	if (tgetent(buf, cp) != 1)
		exit(1);
	pc = tgetstr("pc", &pcbp);
	if (pc)
		PC = *pc;
	clear = tgetstr("cl", &clbp);
	if (clear)
		tputs(clear, tgetnum("li"), putchar);
D 2
	exit (clear != (char *) 0);
E 2
I 2
	exit (clear == (char *) 0);
E 2
}
E 1
