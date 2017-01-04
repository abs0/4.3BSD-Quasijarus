h00968
s 00002/00000/00016
d D 5.2 85/09/21 16:21:37 sam 2 1
c bring in most up to date code; removes hardcoded printer resolution; 
c adds 2 pixels to effective plotting resolution; parameterizes font and point size; 
c make linemod a hack to set font from plot file
e
s 00016/00000/00000
d D 5.1 85/09/21 15:05:45 sam 1 0
c date and time created 85/09/21 15:05:45 by sam
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
 *
 *	%W% (Berkeley) %G%
 */

#include <stdio.h>
extern float obotx;
extern float boty;
extern float botx;
extern float oboty;
extern float scalex;
extern float scaley;
int imPx, imPy;
I 2
extern int imPcsize;
extern char *imP_charset;
E 2
E 1
