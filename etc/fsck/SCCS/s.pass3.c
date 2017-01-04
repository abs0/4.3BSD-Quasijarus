h38666
s 00001/00002/00055
d D 5.2 87/01/07 19:26:44 mckusick 6 5
c be more persistent in trying to read directories; 
c add FOUND return status for routines called from dirscan
e
s 00008/00002/00049
d D 5.1 85/06/05 08:57:29 dist 5 4
c Add copyright
e
s 00000/00001/00051
d D 3.4 85/02/15 12:07:07 mckusick 4 3
c filesize now set by ckinode(); pass1() uses id_entryno to calc block count
e
s 00002/00001/00050
d D 3.3 85/02/11 18:29:30 mckusick 3 2
c ginode() succeeds or exits
e
s 00001/00001/00050
d D 3.2 85/02/07 17:52:14 mckusick 2 1
c code reorganization and cleanup
e
s 00051/00000/00000
d D 3.1 84/03/31 21:03:49 mckusick 1 0
c date and time created 84/03/31 21:03:49 by mckusick
e
u
U
t
T
I 5
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
#ifndef lint
D 5
static char version[] = "%W% (Berkeley) %G%";
#endif
E 5
I 5
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5

#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include "fsck.h"

int	pass2check();

pass3()
{
	register DINODE *dp;
	struct inodesc idesc;
	ino_t inumber, orphan;
	int loopcnt;

	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = DATA;
	for (inumber = ROOTINO; inumber <= lastino; inumber++) {
		if (statemap[inumber] == DSTATE) {
			pathp = pathname;
			*pathp++ = '?';
			*pathp = '\0';
			idesc.id_func = findino;
D 2
			srchname = "..";
E 2
I 2
			idesc.id_name = "..";
E 2
			idesc.id_parent = inumber;
			loopcnt = 0;
			do {
				orphan = idesc.id_parent;
D 3
				if ((dp = ginode(orphan)) == NULL)
E 3
I 3
				if (orphan < ROOTINO || orphan > imax)
E 3
					break;
I 3
				dp = ginode(orphan);
E 3
				idesc.id_parent = 0;
D 4
				idesc.id_filesize = dp->di_size;
E 4
				idesc.id_number = orphan;
D 6
				(void)ckinode(dp, &idesc);
				if (idesc.id_parent == 0)
E 6
I 6
				if ((ckinode(dp, &idesc) & FOUND) == 0)
E 6
					break;
				if (loopcnt >= sblock.fs_cstotal.cs_ndir)
					break;
				loopcnt++;
			} while (statemap[idesc.id_parent] == DSTATE);
			if (linkup(orphan, idesc.id_parent) == 1) {
				idesc.id_func = pass2check;
				idesc.id_number = lfdir;
				descend(&idesc, orphan);
			}
		}
	}
}
E 1
