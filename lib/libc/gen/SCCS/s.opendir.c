h35566
s 00014/00003/00030
d D 5.3 88/06/18 15:12:23 bostic 9 8
c install approved copyright notice
e
s 00002/00002/00031
d D 5.2 86/03/09 19:51:54 donn 8 7
c added LIBC_SCCS condition for sccs ids
e
s 00007/00001/00026
d D 5.1 85/05/30 10:47:02 dist 7 6
c Add copyright
e
s 00004/00004/00023
d D 4.5 83/07/01 18:32:40 sam 6 5
c include fixes
e
s 00003/00007/00024
d D 4.4 82/11/12 19:48:19 mckusick 5 4
c get rid of check for directory
e
s 00007/00008/00024
d D 4.3 82/08/04 22:39:18 mckusick 4 3
c open file before allocating buffer as per Ken Greer (hplabs!kg) suggestion
e
s 00008/00001/00024
d D 4.2 82/03/10 23:46:50 mckusic 3 2
c check that requested file is actually a directory
e
s 00000/00000/00025
d D 4.1 82/02/21 14:49:08 mckusic 2 1
c convert to version number 4.x
e
s 00025/00000/00000
d D 1.1 82/02/11 12:01:17 mckusick 1 0
c date and time created 82/02/11 12:01:17 by mckusick
e
u
U
t
T
I 7
/*
 * Copyright (c) 1983 Regents of the University of California.
D 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 9
I 9
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
E 9
 */

E 7
I 1
D 6
/* Copyright (c) 1982 Regents of the University of California */
E 6
I 6
D 8
#ifndef lint
E 8
I 8
#if defined(LIBC_SCCS) && !defined(lint)
E 8
static char sccsid[] = "%W% (Berkeley) %G%";
D 7
#endif
E 7
I 7
D 8
#endif not lint
E 8
I 8
D 9
#endif LIBC_SCCS and not lint
E 9
I 9
#endif /* LIBC_SCCS and not lint */
E 9
E 8
E 7
E 6

D 6
static char sccsid[] = "%Z%%M% %I% %G%";

E 6
D 5
#include <sys/types.h>
I 3
#include <sys/stat.h>
E 3
#include <ndir.h>
E 5
I 5
#include <sys/param.h>
D 6
#include <dir.h>
E 6
I 6
#include <sys/dir.h>
E 6
E 5

/*
 * open a directory.
 */
DIR *
opendir(name)
	char *name;
{
D 3
	DIR *dirp;
E 3
I 3
	register DIR *dirp;
I 4
	register int fd;
E 4
D 5
	struct stat sbuf;
E 5
E 3

D 4
	dirp = (DIR *)malloc(sizeof(DIR));
	dirp->dd_fd = open(name, 0);
	if (dirp->dd_fd == -1) {
I 3
		free(dirp);
E 4
I 4
	if ((fd = open(name, 0)) == -1)
E 4
		return NULL;
D 4
	}
	fstat(dirp->dd_fd, &sbuf);
	if ((sbuf.st_mode & S_IFDIR) == 0) {
E 3
		free(dirp);
E 4
I 4
D 5
	fstat(fd, &sbuf);
	if (((sbuf.st_mode & S_IFDIR) == 0) ||
	    ((dirp = (DIR *)malloc(sizeof(DIR))) == NULL)) {
E 5
I 5
	if ((dirp = (DIR *)malloc(sizeof(DIR))) == NULL) {
E 5
		close (fd);
E 4
		return NULL;
	}
I 4
	dirp->dd_fd = fd;
E 4
	dirp->dd_loc = 0;
	return dirp;
}
E 1
