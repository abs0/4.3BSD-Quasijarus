h60735
s 00014/00003/00022
d D 5.3 88/06/18 15:12:22 bostic 9 8
c install approved copyright notice
e
s 00002/00002/00023
d D 5.2 86/03/09 19:44:53 donn 8 7
c added LIBC_SCCS condition for sccs ids
e
s 00007/00001/00018
d D 5.1 85/05/30 10:40:42 dist 7 6
c Add copyright
e
s 00004/00004/00015
d D 4.5 83/07/01 18:32:28 sam 6 5
c include fixes
e
s 00001/00001/00018
d D 4.4 82/05/07 20:26:28 mckusick 5 4
c update to new fs
e
s 00001/00001/00018
d D 4.3 82/03/30 13:15:21 mckusic 4 3
c convert to DEV_BSIZE size directory blocks
e
s 00003/00001/00016
d D 4.2 82/03/10 23:49:19 mckusic 3 2
c invalidate descriptor so that subsequent illegal uses can be detected
e
s 00000/00000/00017
d D 4.1 82/02/21 14:49:13 mckusic 2 1
c convert to version number 4.x
e
s 00017/00000/00000
d D 1.1 82/02/11 12:01:11 mckusick 1 0
c date and time created 82/02/11 12:01:11 by mckusick
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
D 4
#include <sys/types.h>
E 4
I 4
#include <sys/param.h>
E 4
D 5
#include <ndir.h>
E 5
I 5
D 6
#include <dir.h>
E 6
I 6
#include <sys/dir.h>
E 6
E 5

/*
 * close a directory.
 */
void
closedir(dirp)
D 3
	DIR *dirp;
E 3
I 3
	register DIR *dirp;
E 3
{
	close(dirp->dd_fd);
I 3
	dirp->dd_fd = -1;
	dirp->dd_loc = 0;
E 3
	free(dirp);
}
E 1
