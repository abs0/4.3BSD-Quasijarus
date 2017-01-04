h19199
s 00009/00000/00000
d D 4.1 83/06/27 14:43:24 sam 1 0
c date and time created 83/06/27 14:43:24 by sam
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
putsi(a){
	putc((char)a,stdout);
	putc((char)(a>>8),stdout);
}
E 1
