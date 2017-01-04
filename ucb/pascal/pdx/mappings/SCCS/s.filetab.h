h58768
s 00007/00003/00013
d D 5.1 85/06/06 16:17:08 dist 3 2
c Add copyright
e
s 00001/00001/00015
d D 1.2 82/01/18 21:55:58 linton 2 1
c sccsid
e
s 00016/00000/00000
d D 1.1 82/01/18 19:20:30 linton 1 0
c date and time created 82/01/18 19:20:30 by linton
e
u
U
t
T
I 1
D 3
/* Copyright (c) 1982 Regents of the University of California */

D 2
static char sccsid[] = "%Z%%M% %I% %G%";
E 2
I 2
/* static char sccsid[] = "%Z%%M% %I% %G%"; */
E 3
I 3
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 3
E 2

/*
 * definition of file table
 */

typedef struct {
	LINENO line;
	ADDRESS addr;
	char *filename;
	LINENO lineindex;
} FILETAB;

FILETAB *filetab;
E 1
