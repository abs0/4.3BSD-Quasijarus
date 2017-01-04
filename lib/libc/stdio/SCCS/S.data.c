h33017
s 00010/00001/00012
d D 5.1 85/06/05 13:31:15 mckusick 5 4
c Add copyright
e
s 00000/00002/00013
d D 4.3 84/05/15 16:54:37 ralph 4 2
c use malloc instead of static 8K sibuf and sobuf.
e
s 00001/00001/00014
d R 4.3 83/06/30 15:18:38 sam 3 2
c stderr not buffered --- no comments from the peanut gallery
e
s 00006/00005/00009
d D 4.2 82/10/05 22:43:52 mckusick 2 1
c utilize st_blksize field to optimize size of reads and writes
e
s 00014/00000/00000
d D 4.1 80/12/21 16:50:00 wnj 1 0
c date and time created 80/12/21 16:50:00 by wnj
e
u
U
t
T
I 1
D 5
/* %W% (Berkeley) %G% */
E 5
I 5
/*
 * Copyright (c) 1985 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 5
#include <stdio.h>
D 2
char	_sibuf[BUFSIZ];
char	_sobuf[BUFSIZ];
E 2
I 2
#include <sys/param.h>
D 4
char	_sibuf[MAXBSIZE];
char	_sobuf[MAXBSIZE];
E 4
E 2

struct	_iobuf	_iob[_NFILE] ={
D 2
	{ 0, _sibuf, _sibuf, _IOREAD, 0},
	{ 0, NULL, NULL, _IOWRT, 1},
	{ 0, NULL, NULL, _IOWRT+_IONBF, 2},
E 2
I 2
	{ 0, NULL, NULL, NULL, _IOREAD, 0},
	{ 0, NULL, NULL, NULL, _IOWRT, 1},
	{ 0, NULL, NULL, NULL, _IOWRT+_IONBF, 2},
E 2
};
/*
 * Ptr to end of buffers
 */
struct	_iobuf	*_lastbuf ={ &_iob[_NFILE] };
E 1
