h24383
s 00002/00000/00040
d D 5.3 85/09/21 16:24:57 sam 3 2
c need imp.h to reference imPcsize
e
s 00026/00000/00014
d D 5.2 85/09/21 16:21:42 sam 2 1
c bring in most up to date code; removes hardcoded printer resolution; 
c adds 2 pixels to effective plotting resolution; parameterizes font and point size; 
c make linemod a hack to set font from plot file
e
s 00014/00000/00000
d D 5.1 85/09/21 15:05:54 sam 1 0
c date and time created 85/09/21 15:05:54 by sam
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

I 3
#include "imp.h"

E 3
I 2
/*
 * Hack to set font.
 */
E 2
linemod(s)
char *s;
{
I 2
	register char *tit;
	register char *nam;
	int siz = 0;
	nam = s;
	for(tit = "charset="; *tit; )
		if (*tit++ != *nam++)
			return;
	s = nam;
	while(*nam) 
		switch(*nam++) {
		case ',':
		case '\n':
			*--nam = 0;
		}
	siz = atoi(++nam);
	if (siz == 0) {
		while (*--nam >= '0' && *nam <= '9')
			;
		siz = (atoi(++nam)*4)/3;
	}
	if (siz == 0)
		siz = imPcsize;
	setfont(s, siz);
E 2
}
E 1
