h19150
s 00007/00004/00023
d D 5.2 85/09/21 16:21:47 sam 2 1
c bring in most up to date code; removes hardcoded printer resolution; 
c adds 2 pixels to effective plotting resolution; parameterizes font and point size; 
c make linemod a hack to set font from plot file
e
s 00027/00000/00000
d D 5.1 85/09/21 15:05:58 sam 1 0
c date and time created 85/09/21 15:05:58 by sam
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

extern float botx;
extern float boty;
extern float obotx;
extern float oboty;
extern float scalex;
extern float scaley;
I 2

int PlotRes = DEFRES;

E 2
int scaleflag;
space(x0,y0,x1,y1){
D 2
	botx = 0.;
	boty = 0.;
E 2
I 2
	botx = 2.;
	boty = 2.;
E 2
	obotx = x0;
	oboty = y0;
	if(scaleflag)
		return;
D 2
	scalex = 2040./(x1-x0);
	scaley = 2040./(y1-y0);
E 2
I 2
	scalex = (8.0 * PlotRes)/(x1-x0);
	scaley = (8.0 * PlotRes)/(y1-y0);
E 2
}
E 1
