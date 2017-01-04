h20762
s 00012/00000/00000
d D 4.1 83/06/27 14:43:19 sam 1 0
c date and time created 83/06/27 14:43:19 by sam
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
line(x0,y0,x1,y1){
	putc('l',stdout);
	putsi(x0);
	putsi(y0);
	putsi(x1);
	putsi(y1);
}
E 1
