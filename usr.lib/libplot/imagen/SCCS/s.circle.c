h33296
s 00013/00000/00000
d D 5.1 85/09/21 15:05:48 sam 1 0
c date and time created 85/09/21 15:05:48 by sam
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

circle(x,y,r){
	arc(x,y,x+r,y,x+r,y);
}
E 1
