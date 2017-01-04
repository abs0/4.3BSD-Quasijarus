h57942
s 00007/00001/00020
d D 5.1 85/05/30 09:42:37 dist 2 1
c Add copyright
e
s 00021/00000/00000
d D 4.1 83/05/03 13:48:26 sam 1 0
c date and time created 83/05/03 13:48:26 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
E 2
I 2
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 2

/*
 * The structures header and dispatch define the format of a font file.
 *
 * See vfont(5) for more details.
 */
struct header {
	short magic;
	unsigned short size;
	short maxx;
	short maxy;
	short xtend;
}; 

struct dispatch {
	unsigned short addr;
	short nbytes;
	char up,down,left,right;
	short width;
};
E 1
