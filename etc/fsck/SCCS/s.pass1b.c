h50218
s 00001/00002/00070
d D 5.2 88/05/07 00:17:08 mckusick 5 4
c eliminate unnecessary flush
e
s 00008/00002/00064
d D 5.1 85/06/05 08:56:49 dist 4 3
c Add copyright
e
s 00013/00007/00053
d D 3.3 85/05/31 20:08:45 mckusick 3 2
c dynamically allocate the duplicate block table
e
s 00002/00000/00058
d D 3.2 85/05/16 17:26:42 mckusick 2 1
c must not do ginode() on numbers less than ROOTINO
e
s 00058/00000/00000
d D 3.1 84/03/31 21:03:47 mckusick 1 0
c date and time created 84/03/31 21:03:47 by mckusick
e
u
U
t
T
I 4
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 4
I 1
#ifndef lint
D 4
static char version[] = "%W% (Berkeley) %G%";
#endif
E 4
I 4
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include "fsck.h"

int	pass1bcheck();
I 3
static  struct dups *duphead;
E 3

pass1b()
{
	register int c, i;
	register DINODE *dp;
	struct inodesc idesc;
	ino_t inumber;

	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = ADDR;
	idesc.id_func = pass1bcheck;
I 3
	duphead = duplist;
E 3
	inumber = 0;
	for (c = 0; c < sblock.fs_ncg; c++) {
		for (i = 0; i < sblock.fs_ipg; i++, inumber++) {
I 2
			if (inumber < ROOTINO)
				continue;
E 2
			dp = ginode(inumber);
			if (dp == NULL)
				continue;
			idesc.id_number = inumber;
			if (statemap[inumber] != USTATE &&
			    (ckinode(dp, &idesc) & STOP))
				goto out1b;
		}
	}
D 5
out1b:
	flush(&dfile, &inoblk);
E 5
I 5
out1b:;
E 5
}

pass1bcheck(idesc)
	register struct inodesc *idesc;
{
D 3
	register daddr_t *dlp;
E 3
I 3
	register struct dups *dlp;
E 3
	int nfrags, res = KEEPON;
	daddr_t blkno = idesc->id_blkno;

	for (nfrags = idesc->id_numfrags; nfrags > 0; blkno++, nfrags--) {
		if (outrange(blkno, 1))
			res = SKIP;
D 3
		for (dlp = duplist; dlp < muldup; dlp++)
			if (*dlp == blkno) {
E 3
I 3
		for (dlp = duphead; dlp; dlp = dlp->next) {
			if (dlp->dup == blkno) {
E 3
				blkerr(idesc->id_number, "DUP", blkno);
D 3
				*dlp = *--muldup;
				*muldup = blkno;
				if (muldup == duplist)
					return (STOP);
E 3
I 3
				dlp->dup = duphead->dup;
				duphead->dup = blkno;
				duphead = duphead->next;
E 3
			}
I 3
			if (dlp == muldup)
				break;
		}
		if (muldup == 0 || duphead == muldup->next)
			return (STOP);
E 3
	}
	return (res);
}
E 1
