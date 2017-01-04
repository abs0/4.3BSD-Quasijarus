h18776
s 00010/00000/00000
d D 4.1 83/06/27 14:43:21 sam 1 0
c date and time created 83/06/27 14:43:21 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

#include <stdio.h>
move(xi,yi){
	putc('m',stdout);
	putsi(xi);
	putsi(yi);
}
E 1
