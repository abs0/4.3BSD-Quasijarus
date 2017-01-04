h19414
s 00012/00000/00000
d D 4.1 83/06/27 14:22:54 sam 1 0
c date and time created 83/06/27 14:22:54 by sam
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
	closepl();
}
closepl(){
	fflush(stdout);
	reset();
}
E 1
