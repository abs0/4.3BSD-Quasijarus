h26200
s 00015/00000/00000
d D 4.1 83/06/27 14:16:35 sam 1 0
c date and time created 83/06/27 14:16:35 by sam
e
u
U
t
T
I 1
#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif

# include "con.h"
float deltx = 4095.;
float delty = 4095.;
space(x0,y0,x1,y1){
	botx = -2047.;
	boty = -2047.;
	obotx = x0;
	oboty = y0;
	scalex = deltx/(x1-x0);
	scaley = delty/(y1-y0);
}
E 1
