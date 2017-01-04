h02294
s 00007/00000/00089
d D 5.3 86/03/05 17:14:40 mckusick 7 6
c add firewall check for bad entry in state map
e
s 00005/00001/00084
d D 5.2 86/03/05 17:12:35 mckusick 6 5
c free dup list and zero link count entries as they are used
c reinitialize dup list head and zero link count head to empty after each fs check
e
s 00008/00002/00077
d D 5.1 85/06/05 08:57:44 dist 5 4
c Add copyright
e
s 00006/00005/00073
d D 3.4 85/06/02 16:47:13 mckusick 4 3
c dynamically allocate zero link count table
e
s 00016/00010/00062
d D 3.3 85/05/31 20:08:48 mckusick 3 2
c dynamically allocate the duplicate block table
e
s 00003/00011/00069
d D 3.2 85/02/08 19:15:47 mckusick 2 1
c merge passes 5 and 6 into a single pass
e
s 00080/00000/00000
d D 3.1 84/03/31 21:03:50 mckusick 1 0
c date and time created 84/03/31 21:03:50 by mckusick
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

int	pass4check();

pass4()
{
D 4
	register ino_t inumber, *blp;
	int n;
E 4
I 4
	register ino_t inumber;
	register struct zlncnt *zlnp;
E 4
	struct inodesc idesc;
I 4
	int n;
E 4

	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = ADDR;
	idesc.id_func = pass4check;
	for (inumber = ROOTINO; inumber <= lastino; inumber++) {
		idesc.id_number = inumber;
		switch (statemap[inumber]) {

		case FSTATE:
I 2
		case DFOUND:
E 2
			n = lncntp[inumber];
			if (n)
				adjust(&idesc, (short)n);
			else {
D 4
				for (blp = badlncnt;blp < badlnp; blp++)
					if (*blp == inumber) {
E 4
I 4
				for (zlnp = zlnhead; zlnp; zlnp = zlnp->next)
					if (zlnp->zlncnt == inumber) {
I 6
						zlnp->zlncnt = zlnhead->zlncnt;
						zlnp = zlnhead;
						zlnhead = zlnhead->next;
						free(zlnp);
E 6
E 4
						clri(&idesc, "UNREF", 1);
						break;
					}
			}
			break;

		case DSTATE:
			clri(&idesc, "UNREF", 1);
			break;

D 2
		case CLEAR:
E 2
I 2
		case DCLEAR:
		case FCLEAR:
E 2
			clri(&idesc, "BAD/DUP", 1);
			break;
I 7

		case USTATE:
			break;

		default:
			errexit("BAD STATE %d FOR INODE I=%d",
			    statemap[inumber], inumber);
E 7
		}
	}
D 2
	if (imax - ROOTINO - n_files != sblock.fs_cstotal.cs_nifree) {
		pwarn("FREE INODE COUNT WRONG IN SUPERBLK");
		if (preen)
			printf(" (FIXED)\n");
		if (preen || reply("FIX") == 1) {
			sblock.fs_cstotal.cs_nifree = imax - ROOTINO - n_files;
			sbdirty();
		}
	}
	flush(&dfile, &fileblk);
E 2
}

pass4check(idesc)
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
D 3
		if (outrange(blkno, 1))
E 3
I 3
		if (outrange(blkno, 1)) {
E 3
			res = SKIP;
D 3
		else if (getbmap(blkno)) {
			for (dlp = duplist; dlp < enddup; dlp++)
				if (*dlp == blkno) {
					*dlp = *--enddup;
					return (KEEPON);
				}
			clrbmap(blkno);
			n_blks--;
E 3
I 3
		} else if (getbmap(blkno)) {
			for (dlp = duplist; dlp; dlp = dlp->next) {
				if (dlp->dup != blkno)
					continue;
				dlp->dup = duplist->dup;
				dlp = duplist;
				duplist = duplist->next;
D 4
				free(dlp);
E 4
I 4
D 6
				/* free(dlp); */
E 6
I 6
				free(dlp);
E 6
E 4
				break;
			}
			if (dlp == 0) {
				clrbmap(blkno);
				n_blks--;
			}
E 3
		}
	}
	return (res);
}
E 1
