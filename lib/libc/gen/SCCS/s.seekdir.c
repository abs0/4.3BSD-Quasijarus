h52502
s 00014/00003/00036
d D 5.3 88/06/18 15:12:28 bostic 15 14
c install approved copyright notice
e
s 00002/00002/00037
d D 5.2 86/03/09 19:54:54 donn 14 13
c added LIBC_SCCS condition for sccs ids
e
s 00007/00001/00032
d D 5.1 85/05/30 10:50:23 dist 13 12
c Add copyright
e
s 00004/00004/00029
d D 4.10 83/07/01 18:32:56 sam 12 11
c include fixes
e
s 00002/00001/00031
d D 4.9 83/03/25 09:44:30 mckusick 11 10
c lint
e
s 00001/00005/00031
d D 4.8 83/03/21 15:28:08 mckusick 10 9
c get rid of incorrect code reintroduced in 4.7
e
s 00004/00000/00032
d D 4.7 82/11/14 13:59:12 sam 9 8
c merge of 4.1b and 4.1c
e
s 00000/00004/00032
d D 4.6 82/09/12 18:33:19 mckusick 8 7
c remove unsafe optimization (might never read newe info)
e
s 00001/00001/00035
d D 4.5 82/05/07 20:37:10 mckusick 7 6
c update to new fs
e
s 00001/00001/00035
d D 4.4 82/03/30 13:15:31 mckusic 6 5
c convert to DEV_BSIZE size directory blocks
e
s 00001/00001/00035
d D 4.3 82/02/25 18:25:50 mckusic 5 4
c must force reading if file has been reopened
e
s 00019/00004/00017
d D 4.2 82/02/24 14:43:30 mckusic 4 3
c protect against seeks to directories that have been compacted in the interim
e
s 00000/00000/00021
d D 4.1 82/02/21 14:49:24 mckusic 3 2
c convert to version number 4.x
e
s 00009/00005/00012
d D 1.2 82/02/21 14:46:22 mckusic 2 1
c convert from resetdir to more general seekdir
e
s 00017/00000/00000
d D 1.1 82/02/11 12:01:42 mckusick 1 0
c date and time created 82/02/11 12:01:42 by mckusick
e
u
U
t
T
I 13
/*
 * Copyright (c) 1983 Regents of the University of California.
D 15
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 15
I 15
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
E 15
 */

E 13
I 1
D 12
/* Copyright (c) 1982 Regents of the University of California */
E 12
I 12
D 14
#ifndef lint
E 14
I 14
#if defined(LIBC_SCCS) && !defined(lint)
E 14
static char sccsid[] = "%W% (Berkeley) %G%";
D 13
#endif
E 13
I 13
D 14
#endif not lint
E 14
I 14
D 15
#endif LIBC_SCCS and not lint
E 15
I 15
#endif /* LIBC_SCCS and not lint */
E 15
E 14
E 13
E 12

D 12
static char sccsid[] = "%Z%%M% %I% %G%";

E 12
D 6
#include <sys/types.h>
E 6
I 6
#include <sys/param.h>
E 6
D 7
#include <ndir.h>
E 7
I 7
D 12
#include <dir.h>
E 12
I 12
#include <sys/dir.h>
E 12
E 7

/*
D 2
 * reset a directory.
E 2
I 2
 * seek to an entry in a directory.
D 10
 * Only values returned by ``telldir'' should be passed to seekdir.
E 10
I 10
 * Only values returned by "telldir" should be passed to seekdir.
E 10
E 2
 */
void
D 2
resetdir(dirp)
	DIR *dirp;
E 2
I 2
seekdir(dirp, loc)
	register DIR *dirp;
	long loc;
E 2
{
D 2
	lseek(dirp->dd_fd, (long)0, 0);
	dirp->dd_loc = 0;
E 2
I 2
D 4
	lseek(dirp->dd_fd, loc & ~(DIRBLKSIZ - 1), 0);
	dirp->dd_loc = loc % DIRBLKSIZ;
	if (dirp->dd_loc != 0)
		dirp->dd_size = read(dirp->dd_fd, dirp->dd_buf, DIRBLKSIZ);
E 4
I 4
	long curloc, base, offset;
	struct direct *dp;
I 11
	extern long lseek();
E 11

	curloc = telldir(dirp);
	if (loc == curloc)
		return;
	base = loc & ~(DIRBLKSIZ - 1);
	offset = loc & (DIRBLKSIZ - 1);
I 9
D 10
	if (dirp->dd_loc != 0 && (curloc & ~(DIRBLKSIZ - 1)) == base) {
		dirp->dd_loc = offset;
		return;
	}
E 10
E 9
D 5
	if ((curloc & ~(DIRBLKSIZ - 1)) == base) {
E 5
I 5
D 8
	if (dirp->dd_loc != 0 && (curloc & ~(DIRBLKSIZ - 1)) == base) {
E 5
		dirp->dd_loc = offset;
		return;
	}
E 8
D 11
	lseek(dirp->dd_fd, base, 0);
E 11
I 11
	(void) lseek(dirp->dd_fd, base, 0);
E 11
	dirp->dd_loc = 0;
	while (dirp->dd_loc < offset) {
		dp = readdir(dirp);
		if (dp == NULL)
			return;
	}
E 4
E 2
}
E 1
