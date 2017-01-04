h01836
s 00025/00012/00326
d D 5.6 88/05/07 01:04:14 mckusick 17 16
c expand from three static buffer to a dynamic buffer pool;
c initial sizing of the buffer pool is 128K (For 8K fs == 16 buffers)
e
s 00001/00001/00337
d D 5.5 87/12/21 12:41:34 bostic 16 15
c make ANSI C compatible
e
s 00001/00001/00337
d D 5.4 87/10/22 10:52:20 bostic 15 14
c ANSI C; sprintf now returns an int.
e
s 00002/00004/00336
d D 5.3 87/01/07 19:26:42 mckusick 14 13
c be more persistent in trying to read directories; 
c add FOUND return status for routines called from dirscan
e
s 00004/00001/00336
d D 5.2 85/07/17 16:46:04 mckusick 13 12
c more descriptive error message
e
s 00008/00002/00329
d D 5.1 85/06/05 08:54:49 dist 12 11
c Add copyright
e
s 00003/00005/00328
d D 3.11 85/05/31 00:19:28 mckusick 11 10
c check for improper directory offsets; recover gracefully from read errors
e
s 00005/00008/00328
d D 3.10 85/02/22 15:07:09 mckusick 10 9
c replace getpw with getpwuid
e
s 00003/00003/00333
d D 3.9 85/02/18 15:33:02 mckusick 9 8
c initialization bug in ckinode()
e
s 00014/00003/00322
d D 3.8 85/02/15 12:09:12 mckusick 8 7
c calc and print out pathname of offending hard links to directories
e
s 00001/00000/00324
d D 3.7 85/02/15 12:06:56 mckusick 7 6
c filesize now set by ckinode(); pass1() uses id_entryno to calc block count
e
s 00069/00000/00255
d D 3.6 85/02/13 18:22:43 mckusick 6 5
c create lost+found directory if none already in existence
e
s 00013/00000/00242
d D 3.5 85/02/13 15:26:12 mckusick 5 4
c check for blocks allocated past end of file in indirect blocks
e
s 00005/00008/00237
d D 3.4 85/02/11 18:29:16 mckusick 4 3
c ginode() succeeds or exits
e
s 00018/00002/00227
d D 3.3 85/02/08 19:15:09 mckusick 3 2
c merge passes 5 and 6 into a single pass
e
s 00009/00012/00220
d D 3.2 85/02/07 17:51:37 mckusick 2 1
c code reorganization and cleanup
e
s 00232/00000/00000
d D 3.1 84/03/31 21:03:42 mckusick 1 0
c date and time created 84/03/31 21:03:42 by mckusick
e
u
U
t
T
I 12
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 12
I 1
#ifndef lint
D 12
static char version[] = "%W% (Berkeley) %G%";
#endif
E 12
I 12
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 12

I 10
#include <pwd.h>
E 10
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include <sys/dir.h>
#include "fsck.h"

I 17
BUFAREA *pbp = 0;

E 17
ckinode(dp, idesc)
	DINODE *dp;
	register struct inodesc *idesc;
{
	register daddr_t *ap;
	int ret, n, ndb, offset;
	DINODE dino;

D 2
	if (SPECIAL)
E 2
I 2
D 9
	if (SPECIAL(dp))
E 2
		return (KEEPON);
	dino = *dp;
E 9
	idesc->id_fix = DONTKNOW;
	idesc->id_entryno = 0;
I 7
	idesc->id_filesize = dp->di_size;
I 9
	if (SPECIAL(dp))
		return (KEEPON);
	dino = *dp;
E 9
E 7
	ndb = howmany(dino.di_size, sblock.fs_bsize);
	for (ap = &dino.di_db[0]; ap < &dino.di_db[NDADDR]; ap++) {
		if (--ndb == 0 && (offset = blkoff(&sblock, dino.di_size)) != 0)
			idesc->id_numfrags =
				numfrags(&sblock, fragroundup(&sblock, offset));
		else
			idesc->id_numfrags = sblock.fs_frag;
		if (*ap == 0)
			continue;
		idesc->id_blkno = *ap;
		if (idesc->id_type == ADDR)
			ret = (*idesc->id_func)(idesc);
		else
			ret = dirscan(idesc);
		if (ret & STOP)
			return (ret);
	}
	idesc->id_numfrags = sblock.fs_frag;
D 2
	for (ap = &dino.di_ib[0], n = 1; n <= 2; ap++, n++) {
E 2
I 2
	for (ap = &dino.di_ib[0], n = 1; n <= NIADDR; ap++, n++) {
E 2
		if (*ap) {
			idesc->id_blkno = *ap;
			ret = iblock(idesc, n,
				dino.di_size - sblock.fs_bsize * NDADDR);
			if (ret & STOP)
				return (ret);
		}
	}
	return (KEEPON);
}

iblock(idesc, ilevel, isize)
	struct inodesc *idesc;
	register ilevel;
	long isize;
{
	register daddr_t *ap;
	register daddr_t *aplim;
D 2
	int i, n, (*func)(), nif;
E 2
I 2
	int i, n, (*func)(), nif, sizepb;
E 2
D 17
	BUFAREA ib;
E 17
I 17
	register BUFAREA *bp;
E 17
I 13
	char buf[BUFSIZ];
E 13
I 5
D 16
	extern int pass1check();
E 16
I 16
	extern int dirscan(), pass1check();
E 16
E 5

	if (idesc->id_type == ADDR) {
		func = idesc->id_func;
		if (((n = (*func)(idesc)) & KEEPON) == 0)
			return (n);
	} else
		func = dirscan;
	if (outrange(idesc->id_blkno, idesc->id_numfrags)) /* protect thyself */
		return (SKIP);
D 17
	initbarea(&ib);
D 11
	if (getblk(&ib, idesc->id_blkno, sblock.fs_bsize) == NULL)
E 11
I 11
	getblk(&ib, idesc->id_blkno, sblock.fs_bsize);
E 17
I 17
	bp = getdatablk(idesc->id_blkno, sblock.fs_bsize);
E 17
D 14
	if (ib.b_errs != NULL)
E 11
		return (SKIP);
E 14
	ilevel--;
D 2
	if (ilevel == 0) {
		nif = lblkno(&sblock, isize) + 1;
	} else /* ilevel == 1 */ {
		nif = isize / (sblock.fs_bsize * NINDIR(&sblock)) + 1;
	}
E 2
I 2
	for (sizepb = sblock.fs_bsize, i = 0; i < ilevel; i++)
		sizepb *= NINDIR(&sblock);
	nif = isize / sizepb + 1;
E 2
	if (nif > NINDIR(&sblock))
		nif = NINDIR(&sblock);
I 5
	if (idesc->id_func == pass1check && nif < NINDIR(&sblock)) {
D 17
		aplim = &ib.b_un.b_indir[NINDIR(&sblock)];
		for (ap = &ib.b_un.b_indir[nif]; ap < aplim; ap++) {
E 17
I 17
		aplim = &bp->b_un.b_indir[NINDIR(&sblock)];
		for (ap = &bp->b_un.b_indir[nif]; ap < aplim; ap++) {
E 17
			if (*ap == 0)
				continue;
D 13
			if (dofix(idesc, "PARTIALLY TRUNCATED INODE")) {
E 13
I 13
D 15
			sprintf(buf, "PARTIALLY TRUNCATED INODE I=%d",
E 15
I 15
			(void)sprintf(buf, "PARTIALLY TRUNCATED INODE I=%d",
E 15
				idesc->id_number);
			if (dofix(idesc, buf)) {
E 13
				*ap = 0;
D 17
				dirty(&ib);
E 17
I 17
				dirty(bp);
E 17
			}
		}
D 17
		flush(&dfile, &ib);
E 17
I 17
		flush(&dfile, bp);
E 17
	}
E 5
D 17
	aplim = &ib.b_un.b_indir[nif];
	for (ap = ib.b_un.b_indir, i = 1; ap < aplim; ap++, i++)
E 17
I 17
	aplim = &bp->b_un.b_indir[nif];
	for (ap = bp->b_un.b_indir, i = 1; ap < aplim; ap++, i++) {
E 17
		if (*ap) {
			idesc->id_blkno = *ap;
			if (ilevel > 0)
D 2
				n = iblock(idesc, ilevel,
				    isize - i*NINDIR(&sblock)*sblock.fs_bsize);
E 2
I 2
				n = iblock(idesc, ilevel, isize - i * sizepb);
E 2
			else
				n = (*func)(idesc);
D 17
			if (n & STOP)
E 17
I 17
			if (n & STOP) {
				bp->b_flags &= ~B_INUSE;
E 17
				return (n);
I 17
			}
E 17
		}
I 17
	}
	bp->b_flags &= ~B_INUSE;
E 17
	return (KEEPON);
}

outrange(blk, cnt)
	daddr_t blk;
	int cnt;
{
	register int c;

	if ((unsigned)(blk+cnt) > fmax)
		return (1);
	c = dtog(&sblock, blk);
	if (blk < cgdmin(&sblock, c)) {
		if ((blk+cnt) > cgsblock(&sblock, c)) {
			if (debug) {
				printf("blk %d < cgdmin %d;",
				    blk, cgdmin(&sblock, c));
				printf(" blk+cnt %d > cgsbase %d\n",
				    blk+cnt, cgsblock(&sblock, c));
			}
			return (1);
		}
	} else {
		if ((blk+cnt) > cgbase(&sblock, c+1)) {
			if (debug)  {
				printf("blk %d >= cgdmin %d;",
				    blk, cgdmin(&sblock, c));
				printf(" blk+cnt %d > sblock.fs_fpg %d\n",
				    blk+cnt, sblock.fs_fpg);
			}
			return (1);
		}
	}
	return (0);
}

DINODE *
ginode(inumber)
	ino_t inumber;
{
	daddr_t iblk;
	static ino_t startinum = 0;	/* blk num of first in raw area */

D 11

E 11
D 4
	if (inumber < ROOTINO || inumber > imax) {
		if (debug && inumber > imax)
			printf("inumber out of range (%d)\n", inumber);
		return (NULL);
	}
E 4
I 4
	if (inumber < ROOTINO || inumber > imax)
		errexit("bad inode number %d to ginode\n", inumber);
E 4
	if (startinum == 0 ||
	    inumber < startinum || inumber >= startinum + INOPB(&sblock)) {
		iblk = itod(&sblock, inumber);
D 11
		if (getblk(&inoblk, iblk, sblock.fs_bsize) == NULL) {
			return (NULL);
		}
E 11
I 11
D 17
		getblk(&inoblk, iblk, sblock.fs_bsize);
E 17
I 17
		if (pbp != 0)
			pbp->b_flags &= ~B_INUSE;
		pbp = getdatablk(iblk, sblock.fs_bsize);
E 17
E 11
		startinum = (inumber / INOPB(&sblock)) * INOPB(&sblock);
	}
D 17
	return (&inoblk.b_un.b_dinode[inumber % INOPB(&sblock)]);
E 17
I 17
	return (&pbp->b_un.b_dinode[inumber % INOPB(&sblock)]);
}

inodirty()
{
	
	dirty(pbp);
E 17
}

clri(idesc, s, flg)
	register struct inodesc *idesc;
	char *s;
	int flg;
{
	register DINODE *dp;

D 4
	if ((dp = ginode(idesc->id_number)) == NULL)
		return;
E 4
I 4
	dp = ginode(idesc->id_number);
E 4
	if (flg == 1) {
D 2
		pwarn("%s %s", s, DIRCT?"DIR":"FILE");
E 2
I 2
		pwarn("%s %s", s, DIRCT(dp) ? "DIR" : "FILE");
E 2
		pinode(idesc->id_number);
	}
	if (preen || reply("CLEAR") == 1) {
		if (preen)
			printf(" (CLEARED)\n");
		n_files--;
		(void)ckinode(dp, idesc);
		zapino(dp);
		statemap[idesc->id_number] = USTATE;
		inodirty();
D 3
		inosumbad++;
E 3
	}
}

I 8
findname(idesc)
	struct inodesc *idesc;
{
	register DIRECT *dirp = idesc->id_dirp;

	if (dirp->d_ino != idesc->id_parent)
		return (KEEPON);
	bcopy(dirp->d_name, idesc->id_name, dirp->d_namlen + 1);
D 14
	return (STOP);
E 14
I 14
	return (STOP|FOUND);
E 14
}

E 8
findino(idesc)
	struct inodesc *idesc;
{
	register DIRECT *dirp = idesc->id_dirp;

	if (dirp->d_ino == 0)
		return (KEEPON);
D 2
	if (!strcmp(dirp->d_name, srchname)) {
E 2
I 2
D 8
	if (!strcmp(dirp->d_name, idesc->id_name)) {
E 2
		if (dirp->d_ino >= ROOTINO && dirp->d_ino <= imax)
			idesc->id_parent = dirp->d_ino;
E 8
I 8
	if (strcmp(dirp->d_name, idesc->id_name) == 0 &&
	    dirp->d_ino >= ROOTINO && dirp->d_ino <= imax) {
		idesc->id_parent = dirp->d_ino;
E 8
D 14
		return (STOP);
E 14
I 14
		return (STOP|FOUND);
E 14
	}
	return (KEEPON);
}

pinode(ino)
	ino_t ino;
{
	register DINODE *dp;
	register char *p;
D 10
	char uidbuf[BUFSIZ];
E 10
I 10
	struct passwd *pw;
E 10
	char *ctime();

	printf(" I=%u ", ino);
D 4
	if ((dp = ginode(ino)) == NULL)
E 4
I 4
	if (ino < ROOTINO || ino > imax)
E 4
		return;
I 4
	dp = ginode(ino);
E 4
	printf(" OWNER=");
D 10
	if (getpw((int)dp->di_uid, uidbuf) == 0) {
		for (p = uidbuf; *p != ':'; p++);
		*p = 0;
		printf("%s ", uidbuf);
	}
	else {
E 10
I 10
	if ((pw = getpwuid((int)dp->di_uid)) != 0)
		printf("%s ", pw->pw_name);
	else
E 10
		printf("%d ", dp->di_uid);
D 10
	}
E 10
	printf("MODE=%o\n", dp->di_mode);
	if (preen)
		printf("%s: ", devname);
	printf("SIZE=%ld ", dp->di_size);
	p = ctime(&dp->di_mtime);
	printf("MTIME=%12.12s %4.4s ", p+4, p+20);
}

blkerr(ino, s, blk)
	ino_t ino;
	char *s;
	daddr_t blk;
{

	pfatal("%ld %s I=%u", blk, s, ino);
	printf("\n");
D 3
	statemap[ino] = CLEAR;
E 3
I 3
	switch (statemap[ino]) {

	case FSTATE:
		statemap[ino] = FCLEAR;
		return;

	case DSTATE:
		statemap[ino] = DCLEAR;
		return;

	case FCLEAR:
	case DCLEAR:
		return;

	default:
		errexit("BAD STATE %d TO BLKERR", statemap[ino]);
		/* NOTREACHED */
	}
E 3
}
I 6

/*
 * allocate an unused inode
 */
ino_t
allocino(request, type)
	ino_t request;
	int type;
{
	register ino_t ino;
	register DINODE *dp;

	if (request == 0)
		request = ROOTINO;
	else if (statemap[request] != USTATE)
		return (0);
	for (ino = request; ino < imax; ino++)
		if (statemap[ino] == USTATE)
			break;
	if (ino == imax)
		return (0);
	switch (type & IFMT) {
	case IFDIR:
		statemap[ino] = DSTATE;
		break;
	case IFREG:
	case IFLNK:
		statemap[ino] = FSTATE;
		break;
	default:
		return (0);
	}
	dp = ginode(ino);
	dp->di_db[0] = allocblk(1);
	if (dp->di_db[0] == 0) {
		statemap[ino] = USTATE;
		return (0);
	}
	dp->di_mode = type;
	time(&dp->di_atime);
	dp->di_mtime = dp->di_ctime = dp->di_atime;
	dp->di_size = sblock.fs_fsize;
	dp->di_blocks = btodb(sblock.fs_fsize);
	n_files++;
	inodirty();
	return (ino);
}

/*
 * deallocate an inode
 */
freeino(ino)
	ino_t ino;
{
	struct inodesc idesc;
	extern int pass4check();
	DINODE *dp;

	bzero((char *)&idesc, sizeof(struct inodesc));
	idesc.id_type = ADDR;
	idesc.id_func = pass4check;
	idesc.id_number = ino;
	dp = ginode(ino);
	(void)ckinode(dp, &idesc);
	zapino(dp);
	inodirty();
	statemap[ino] = USTATE;
	n_files--;
}
E 6
E 1
