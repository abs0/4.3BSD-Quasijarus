h21008
s 00013/00000/00000
d D 4.1 83/06/27 14:19:16 sam 1 0
c date and time created 83/06/27 14:19:16 by sam
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
closevt(){
	putch(037);
	fflush(stdout);
}
closepl(){
	putch(037);
	fflush(stdout);
}
E 1
