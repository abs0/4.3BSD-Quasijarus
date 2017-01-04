h19530
s 00011/00000/00000
d D 4.1 83/06/27 14:43:12 sam 1 0
c date and time created 83/06/27 14:43:12 by sam
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
circle(x,y,r){
	putc('c',stdout);
	putsi(x);
	putsi(y);
	putsi(r);
}
E 1
