h43933
s 00001/00001/00049
d D 5.3 86/04/27 01:41:04 donn 9 8
c Change error return to -1 to match manual page.  Shouldn't affect anything --
c no utility that I can find ever checks the return value!
e
s 00002/00002/00048
d D 5.2 86/03/09 19:49:52 donn 8 7
c added LIBC_SCCS condition for sccs ids
e
s 00009/00001/00041
d D 5.1 85/05/30 10:43:56 dist 7 6
c Add copyright
e
s 00001/00000/00041
d D 4.4 83/06/17 20:12:32 sam 6 5
c don't forget to close the file
e
s 00006/00003/00035
d D 4.3 83/05/01 19:04:12 sam 5 4
c avoid duplicate group id's; update diagnostics
e
s 00001/00001/00037
d D 4.2 83/02/15 21:59:43 mckusick 4 1
c complain about too many groups too early
e
s 00001/00001/00037
d R 4.2 83/02/15 21:57:23 mckusick 3 1
c complained too early about too many groups
e
s 00001/00001/00037
d R 4.2 83/02/10 16:55:39 sam 2 1
c group id's are short's, not int's
e
s 00038/00000/00000
d D 4.1 82/11/07 19:11:20 sam 1 0
c date and time created 82/11/07 19:11:20 by sam
e
u
U
t
T
I 1
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

D 8
#ifndef lint
E 8
I 8
#if defined(LIBC_SCCS) && !defined(lint)
E 8
static char sccsid[] = "%W% (Berkeley) %G%";
D 8
#endif not lint
E 8
I 8
#endif LIBC_SCCS and not lint
E 8
E 7

/*
 * initgroups
 */
#include <stdio.h>
#include <sys/param.h>
#include <grp.h>

struct group *getgrent();

initgroups(uname, agroup)
	char *uname;
	int agroup;
{
	int groups[NGROUPS], ngroups = 0;
	register struct group *grp;
	register int i;

	if (agroup >= 0)
		groups[ngroups++] = agroup;
	setgrent();
D 5
	while (grp = getgrent())
E 5
I 5
	while (grp = getgrent()) {
		if (grp->gr_gid == agroup)
			continue;
E 5
		for (i = 0; grp->gr_mem[i]; i++)
			if (!strcmp(grp->gr_mem[i], uname)) {
D 4
				groups[ngroups++] = grp->gr_gid;
E 4
				if (ngroups == NGROUPS) {
D 5
fprintf(stderr, "inigrp: %s is in too many groups\n", uname);
E 5
I 5
fprintf(stderr, "initgroups: %s is in too many groups\n", uname);
E 5
					goto toomany;
				}
I 4
				groups[ngroups++] = grp->gr_gid;
E 4
			}
I 5
	}
E 5
toomany:
I 6
	endgrent();
E 6
	if (setgroups(ngroups, groups) < 0) {
D 5
		perror("setgrp");
E 5
I 5
		perror("setgroups");
E 5
D 9
		return (1);
E 9
I 9
		return (-1);
E 9
	}
	return (0);
}
E 1
