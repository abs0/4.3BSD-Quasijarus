h16361
s 00007/00001/00050
d D 5.1 85/05/07 12:07:41 dist 2 1
c Add copyright notice
e
s 00051/00000/00000
d D 4.1 83/11/10 14:15:34 ralph 1 0
c date and time created 83/11/10 14:15:34 by ralph
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

#include <sgtty.h>
#include "hp2648.h"

handshake()
{
	int i;
	char ch;

	if( shakehands != TRUE )
		return;
	ch = ' ';
	putchar(ENQ);
	fflush(stdout);
	while(1){
		i = read(fildes, &ch, 1);
		if(i < 0)
			continue;
		if(ch == ACK)
			break;
		putchar('Z');
		fflush(stdout);
		stty(fildes, &sarg);
		exit(0);
	}
}

buffready(n)
int n;
{
	buffcount = buffcount + n;
	if(buffcount >= 80){
		handshake();
		putchar(ESC); 
		putchar(GRAPHIC);
		putchar(PLOT);
		putchar(BINARY);
		buffcount = n+4;
	}
}

itoa(num,byte1,byte2)
int num;
char *byte1,*byte2;
{
	*byte1 = (num & 037) | 040;
	*byte2 = ((num>>5) & 037) | 040;
}
E 1
