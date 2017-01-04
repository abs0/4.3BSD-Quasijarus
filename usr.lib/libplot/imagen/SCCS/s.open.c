h31626
s 00003/00002/00038
d D 5.2 85/09/21 16:21:44 sam 2 1
c bring in most up to date code; removes hardcoded printer resolution; 
c adds 2 pixels to effective plotting resolution; parameterizes font and point size; 
c make linemod a hack to set font from plot file
e
s 00040/00000/00000
d D 5.1 85/09/21 15:05:55 sam 1 0
c date and time created 85/09/21 15:05:55 by sam
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

#include "imPcodes.h"
#include "imp.h"
D 2
int imPcsize = 12;
E 2
I 2

E 2
openpl(){
I 2

E 2
	putch(imP_SET_HV_SYSTEM);
	  putch((3<<3)|5);
	putch(imP_SET_FAMILY);
	  putch(2);
D 2
	setfont("cmasc7",imPcsize);
E 2
I 2
	setfont(imP_charset,imPcsize);
E 2
	putch(imP_SET_IL);
	  putwd(imPcsize+3);
	putch(imP_SET_SP);
	  putwd(imPcsize);
	putch(imP_SET_PEN);
	  putch(2);
	putch(imP_SET_ABS_H);
	  putwd(0);
	putch(imP_SET_ABS_V);
	  putwd(0);
}
setfont(c, sz) char *c; int sz;
{
	imPcsize = sz;
	putch(imP_CREATE_FAMILY_TABLE);
	  putch(2);
	  putch(1);
	  putch(0);
	  fprintf(stdout, c);
	  putch(0);
}
E 1
