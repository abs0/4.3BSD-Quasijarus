h46915
s 00007/00001/00015
d D 5.1 85/06/07 08:26:24 dist 2 1
c Add copyright
e
s 00016/00000/00000
d D 1.1 85/01/02 20:10:39 jak 1 0
c date and time created 85/01/02 20:10:39 by jak
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

extern int ohiy;
extern int ohix;
extern int oloy;
erase(){
	int i;
		putch(033);
		putch(014);
		ohiy= -1;
		ohix = -1;
		oloy = -1;
		return;
}
E 1
