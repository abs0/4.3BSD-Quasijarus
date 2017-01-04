h46577
s 00006/00007/00034
d D 5.2 85/09/21 16:21:39 sam 2 1
c bring in most up to date code; removes hardcoded printer resolution; 
c adds 2 pixels to effective plotting resolution; parameterizes font and point size; 
c make linemod a hack to set font from plot file
e
s 00041/00000/00000
d D 5.1 85/09/21 15:05:53 sam 1 0
c date and time created 85/09/21 15:05:53 by sam
e
u
U
t
T
I 1
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

#include "imp.h"
#include "imPcodes.h"
D 2

E 2
float obotx = 0.;
float oboty = 0.;
D 2
float botx = 0.;
float boty = 0.;
E 2
I 2
float botx = 2.;
float boty = 2.;
E 2
float scalex = 1.;
float scaley = 1.;
line(x0,y0,x1,y1)
{
	putch(imP_CREATE_PATH);
	putwd(2);		/* two coordinates follow */
D 2
	putwd((int)((x0-obotx)*scalex+botx+1));	
	putwd((int)((y0-oboty)*scaley+boty+1));	
	putwd((int)((x1-obotx)*scalex+botx+1));	
	putwd((int)((y1-oboty)*scaley+boty+1));	
E 2
I 2
	putwd((int)((x0-obotx)*scalex+botx));	
	putwd((int)((y0-oboty)*scaley+boty));	
	putwd((int)((x1-obotx)*scalex+botx));	
	putwd((int)((y1-oboty)*scaley+boty));	
E 2
	putch(imP_DRAW_PATH);
	putch(15);		/* "black" lines */
	imPx = x1;
	imPy = y1;
}
putch(c)
{
	putc(c, stdout);
}
putwd(w)
{
	putch(w>>8);
	putch(w);
}
E 1
