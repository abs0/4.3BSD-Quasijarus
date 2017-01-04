h06567
s 00005/00004/00520
d D 5.13 88/06/07 18:52:04 mckusick 21 19
c must be sure to always convert b_bno to disk block (db) units
e
s 00002/00001/00523
d R 5.13 88/06/07 15:45:16 mckusick 20 19
c missing fsbtodb!
e
s 00009/00003/00515
d D 5.12 88/05/25 17:21:12 mckusick 19 18
c add firewall to check for lost buffers; fine tune cache statistics
e
s 00078/00006/00440
d D 5.11 88/05/07 01:04:19 mckusick 18 17
c expand from three static buffer to a dynamic buffer pool;
c initial sizing of the buffer pool is 128K (For 8K fs == 16 buffers)
e
s 00002/00002/00444
d D 5.10 87/04/07 19:49:22 karels 17 16
c fix alternate superblock location again; don't offer to rewrite
c standard superblock if we haven't found a good one yet; standardize units
c for -b (sectors! as before); kernel may change fs_dbsize
e
s 00018/00010/00428
d D 5.9 87/03/11 20:06:28 karels 16 15
c use physical sector size for partial buffer reads;
c -n implies "yes" answer for "CONTINUE?"
e
s 00006/00006/00432
d D 5.8 87/02/23 15:54:08 mckusick 15 14
c eliminate dbtob macro (which uses DEV_BSIZE)
e
s 00002/00002/00436
d D 5.7 87/02/23 14:42:21 mckusick 14 13
c use SBOFF instead of SBLOCK
e
s 00011/00010/00427
d D 5.6 87/02/18 18:14:45 mckusick 13 12
c intuit the appropriate DEV_BSIZE from fsbtodb macro
e
s 00001/00001/00436
d D 5.5 87/02/11 16:38:19 mckusick 12 11
c must zero the buffer
e
s 00005/00002/00432
d D 5.4 87/01/15 11:09:38 mckusick 11 10
c must do lseek after read or write failure
e
s 00003/00003/00431
d D 5.3 87/01/07 19:26:45 mckusick 10 9
c be more persistent in trying to read directories; 
c add FOUND return status for routines called from dirscan
e
s 00026/00000/00408
d D 5.2 85/09/10 20:14:29 karels 9 8
c allow a single sigquit to force exit(2) after completing checks
c if preening
e
s 00008/00002/00400
d D 5.1 85/06/05 08:58:37 dist 8 7
c Add copyright
e
s 00017/00006/00385
d D 3.7 85/06/02 16:46:27 mckusick 7 6
c persist in writing back bad sectors; be more informative about the errors
e
s 00022/00009/00369
d D 3.6 85/05/31 00:19:43 mckusick 6 5
c check for improper directory offsets; recover gracefully from read errors
e
s 00001/00000/00377
d D 3.5 85/02/18 16:27:05 mckusick 5 4
c must remember to flush out cylinder group block when done
e
s 00053/00000/00324
d D 3.4 85/02/15 12:09:17 mckusick 4 3
c calc and print out pathname of offending hard links to directories
e
s 00044/00000/00280
d D 3.3 85/02/11 20:55:35 mckusick 3 2
c expand lost+found when running out of space
e
s 00029/00024/00251
d D 3.2 85/02/07 17:52:26 mckusick 2 1
c code reorganization and cleanup
e
s 00275/00000/00000
d D 3.1 84/03/31 21:03:55 mckusick 1 0
c date and time created 84/03/31 21:03:55 by mckusick
e
u
U
t
T
I 8
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 8
I 1
#ifndef lint
D 8
static char version[] = "%W% (Berkeley) %G%";
#endif
E 8
I 8
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 8

#include <stdio.h>
#include <ctype.h>
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
I 4
#include <sys/dir.h>
E 4
#include "fsck.h"

I 18
long	diskreads, totalreads;	/* Disk cache statistics */
E 18
long	lseek();

ftypeok(dp)
	DINODE *dp;
{
	switch (dp->di_mode & IFMT) {

	case IFDIR:
	case IFREG:
	case IFBLK:
	case IFCHR:
	case IFLNK:
	case IFSOCK:
		return (1);

	default:
		if (debug)
			printf("bad file type 0%o\n", dp->di_mode);
		return (0);
	}
}

reply(s)
	char *s;
{
	char line[80];
I 16
	int cont = (strcmp(s, "CONTINUE") == 0);
E 16

	if (preen)
		pfatal("INTERNAL ERROR: GOT TO reply()");
D 2
	rplyflag = 1;
E 2
	printf("\n%s? ", s);
D 16
	if (nflag || dfile.wfdes < 0) {
E 16
I 16
	if (!cont && (nflag || dfile.wfdes < 0)) {
E 16
		printf(" no\n\n");
		return (0);
	}
D 16
	if (yflag) {
E 16
I 16
	if (yflag || (cont && nflag)) {
E 16
		printf(" yes\n\n");
		return (1);
	}
	if (getline(stdin, line, sizeof(line)) == EOF)
		errexit("\n");
	printf("\n");
	if (line[0] == 'y' || line[0] == 'Y')
		return (1);
	else
		return (0);
}

getline(fp, loc, maxlen)
	FILE *fp;
	char *loc;
{
	register n;
	register char *p, *lastloc;

	p = loc;
	lastloc = &p[maxlen-1];
	while ((n = getc(fp)) != '\n') {
		if (n == EOF)
			return (EOF);
		if (!isspace(n) && p < lastloc)
			*p++ = n;
	}
	*p = 0;
	return (p - loc);
}

I 18
/*
 * Malloc buffers and set up cache.
 */
bufinit()
{
	register BUFAREA *bp;
	long bufcnt, i;
	char *bufp;

	bufp = (char *)malloc(sblock.fs_bsize);
	if (bufp == 0)
		errexit("cannot allocate buffer pool\n");
	cgblk.b_un.b_buf = bufp;
	initbarea(&cgblk);
	bufhead.b_next = bufhead.b_prev = &bufhead;
	bufcnt = MAXBUFSPACE / sblock.fs_bsize;
	if (bufcnt < MINBUFS)
		bufcnt = MINBUFS;
	for (i = 0; i < bufcnt; i++) {
		bp = (BUFAREA *)malloc(sizeof(BUFAREA));
		bufp = (char *)malloc(sblock.fs_bsize);
		if (bp == 0 || bufp == 0) {
			if (i >= MINBUFS)
				break;
			errexit("cannot allocate buffer pool\n");
		}
		bp->b_un.b_buf = bufp;
		bp->b_prev = &bufhead;
		bp->b_next = bufhead.b_next;
		bufhead.b_next->b_prev = bp;
		bufhead.b_next = bp;
		initbarea(bp);
	}
I 19
	bufhead.b_size = i;	/* save number of buffers */
E 19
}

/*
 * Manage a cache of directory blocks.
 */
E 18
BUFAREA *
I 18
getdatablk(blkno, size)
	daddr_t blkno;
	long size;
{
	register BUFAREA *bp;

	for (bp = bufhead.b_next; bp != &bufhead; bp = bp->b_next)
D 21
		if (bp->b_bno == blkno)
E 21
I 21
		if (bp->b_bno == fsbtodb(&sblock, blkno))
E 21
			goto foundit;
	for (bp = bufhead.b_prev; bp != &bufhead; bp = bp->b_prev)
		if ((bp->b_flags & B_INUSE) == 0)
			break;
	if (bp == &bufhead)
		errexit("deadlocked buffer pool\n");
	getblk(bp, blkno, size);
	/* fall through */
foundit:
	totalreads++;
	bp->b_prev->b_next = bp->b_next;
	bp->b_next->b_prev = bp->b_prev;
	bp->b_prev = &bufhead;
	bp->b_next = bufhead.b_next;
	bufhead.b_next->b_prev = bp;
	bufhead.b_next = bp;
	bp->b_flags |= B_INUSE;
	return (bp);
}

BUFAREA *
E 18
getblk(bp, blk, size)
	register BUFAREA *bp;
	daddr_t blk;
	long size;
{
	register struct filecntl *fcp;
	daddr_t dblk;

	fcp = &dfile;
D 18
	dblk = fsbtodb(&sblock, blk);
	if (bp->b_bno == dblk)
E 18
I 18
D 21
	if (bp->b_bno == blk)
E 21
I 21
	dblk = fsbtodb(&sblock, blk);
	if (bp->b_bno == dblk)
E 21
E 18
		return (bp);
	flush(fcp, bp);
D 6
	if (bread(fcp, bp->b_un.b_buf, dblk, size) != 0) {
		bp->b_bno = dblk;
		bp->b_size = size;
		return (bp);
	}
	bp->b_bno = (daddr_t)-1;
	return (NULL);
E 6
I 6
D 18
	bp->b_errs = bread(fcp, bp->b_un.b_buf, dblk, size);
	bp->b_bno = dblk;
E 18
I 18
	diskreads++;
D 21
	bp->b_errs = bread(fcp, bp->b_un.b_buf, fsbtodb(&sblock, blk), size);
	bp->b_bno = blk;
E 21
I 21
	bp->b_errs = bread(fcp, bp->b_un.b_buf, dblk, size);
	bp->b_bno = dblk;
E 21
E 18
	bp->b_size = size;
	return (bp);
E 6
}

flush(fcp, bp)
	struct filecntl *fcp;
	register BUFAREA *bp;
{
I 2
	register int i, j;
E 2

D 2
	if (bp->b_dirty)
		(void)bwrite(fcp, bp->b_un.b_buf, bp->b_bno, (long)bp->b_size);
E 2
I 2
	if (!bp->b_dirty)
		return;
I 6
	if (bp->b_errs != 0)
D 16
		pfatal("WRITING ZERO'ED BLOCK %d TO DISK\n", bp->b_bno);
E 16
I 16
		pfatal("WRITING %sZERO'ED BLOCK %d TO DISK\n",
		    (bp->b_errs == bp->b_size / dev_bsize) ? "" : "PARTIALLY ",
		    bp->b_bno);
E 16
E 6
E 2
	bp->b_dirty = 0;
I 6
	bp->b_errs = 0;
E 6
I 2
D 7
	(void)bwrite(fcp, bp->b_un.b_buf, bp->b_bno, (long)bp->b_size);
E 7
I 7
	bwrite(fcp, bp->b_un.b_buf, bp->b_bno, (long)bp->b_size);
E 7
	if (bp != &sblk)
		return;
	for (i = 0, j = 0; i < sblock.fs_cssize; i += sblock.fs_bsize, j++) {
D 7
		(void)bwrite(&dfile, (char *)sblock.fs_csp[j],
E 7
I 7
		bwrite(&dfile, (char *)sblock.fs_csp[j],
E 7
		    fsbtodb(&sblock, sblock.fs_csaddr + j * sblock.fs_frag),
		    sblock.fs_cssize - i < sblock.fs_bsize ?
		    sblock.fs_cssize - i : sblock.fs_bsize);
	}
E 2
}

rwerr(s, blk)
	char *s;
	daddr_t blk;
{

	if (preen == 0)
		printf("\n");
	pfatal("CANNOT %s: BLK %ld", s, blk);
	if (reply("CONTINUE") == 0)
		errexit("Program terminated\n");
}

ckfini()
{
I 18
	register BUFAREA *bp;
I 19
	int cnt = 0;
E 19
E 18

D 18
	flush(&dfile, &fileblk);
E 18
	flush(&dfile, &sblk);
D 13
	if (sblk.b_bno != SBLOCK) {
		sblk.b_bno = SBLOCK;
E 13
I 13
D 14
	if (sblk.b_bno != SBLOCK * DEV_BSIZE / dev_bsize &&
E 14
I 14
D 16
	if (sblk.b_bno != SBOFF / dev_bsize &&
E 16
I 16
D 17
	if (dev_bsize && sblk.b_bno != SBOFF / dev_bsize &&
E 17
I 17
	if (havesb && sblk.b_bno != SBOFF / dev_bsize &&
E 17
E 16
E 14
	    !preen && reply("UPDATE STANDARD SUPERBLOCK")) {
D 14
		sblk.b_bno = SBLOCK * DEV_BSIZE / dev_bsize;
E 14
I 14
		sblk.b_bno = SBOFF / dev_bsize;
E 14
E 13
		sbdirty();
		flush(&dfile, &sblk);
	}
D 18
	flush(&dfile, &inoblk);
E 18
I 5
	flush(&dfile, &cgblk);
I 18
D 19
	for (bp = bufhead.b_prev; bp != &bufhead; bp = bp->b_prev)
E 19
I 19
	for (bp = bufhead.b_prev; bp != &bufhead; bp = bp->b_prev) {
		cnt++;
E 19
		flush(&dfile, bp);
I 19
	}
	if (bufhead.b_size != cnt)
		errexit("Panic: lost %d buffers\n", bufhead.b_size - cnt);
E 19
	if (debug)
D 19
		printf("cache hit %d of %d (%d%%)\n", totalreads - diskreads,
		    totalreads, (totalreads - diskreads) * 100 / totalreads);
E 19
I 19
		printf("cache missed %d of %d (%d%%)\n", diskreads,
		    totalreads, diskreads * 100 / totalreads);
E 19
E 18
E 5
	(void)close(dfile.rfdes);
	(void)close(dfile.wfdes);
}

bread(fcp, buf, blk, size)
	register struct filecntl *fcp;
	char *buf;
	daddr_t blk;
	long size;
{
I 6
	char *cp;
	int i, errs;

E 6
D 15
	if (lseek(fcp->rfdes, (long)dbtob(blk), 0) < 0)
E 15
I 15
	if (lseek(fcp->rfdes, blk * dev_bsize, 0) < 0)
E 15
		rwerr("SEEK", blk);
	else if (read(fcp->rfdes, buf, (int)size) == size)
D 6
		return (1);
E 6
I 6
		return (0);
E 6
	rwerr("READ", blk);
D 6
	return (0);
E 6
I 6
D 15
	if (lseek(fcp->rfdes, (long)dbtob(blk), 0) < 0)
E 15
I 15
	if (lseek(fcp->rfdes, blk * dev_bsize, 0) < 0)
E 15
		rwerr("SEEK", blk);
	errs = 0;
I 11
D 12
	bzero(cp, size);
E 12
I 12
	bzero(buf, size);
E 12
E 11
I 7
D 16
	pfatal("THE FOLLOWING SECTORS COULD NOT BE READ:");
E 7
D 13
	for (cp = buf, i = 0; i < size; i += DEV_BSIZE, cp += DEV_BSIZE) {
		if (read(fcp->rfdes, cp, DEV_BSIZE) < 0) {
I 11
			lseek(fcp->rfdes, (long)dbtob(blk) + i + DEV_BSIZE, 0);
E 11
I 7
			printf(" %d,", blk + i / DEV_BSIZE);
E 13
I 13
	for (cp = buf, i = 0; i < size; i += dev_bsize, cp += dev_bsize) {
		if (read(fcp->rfdes, cp, dev_bsize) < 0) {
D 15
			lseek(fcp->rfdes, (long)dbtob(blk) + i + dev_bsize, 0);
E 15
I 15
			lseek(fcp->rfdes, blk * dev_bsize + i + dev_bsize, 0);
E 15
			printf(" %d,", blk + i / dev_bsize);
E 16
I 16
	printf("THE FOLLOWING DISK SECTORS COULD NOT BE READ:");
	for (cp = buf, i = 0; i < size; i += secsize, cp += secsize) {
		if (read(fcp->rfdes, cp, secsize) < 0) {
			lseek(fcp->rfdes, blk * dev_bsize + i + secsize, 0);
D 17
			if (secsize != dev_bsize)
E 17
I 17
			if (secsize != dev_bsize && dev_bsize != 1)
E 17
				printf(" %d (%d),",
				    (blk * dev_bsize + i) / secsize,
				    blk + i / dev_bsize);
			else
				printf(" %d,", blk + i / dev_bsize);
E 16
E 13
E 7
D 11
			bzero(cp, DEV_BSIZE);
E 11
			errs++;
		}
	}
D 7
	pwarn("%d SECTORS REPLACED WITH ZERO'ED BLOCKS\n", errs);
E 7
I 7
	printf("\n");
E 7
	return (errs);
E 6
}

bwrite(fcp, buf, blk, size)
	register struct filecntl *fcp;
	char *buf;
	daddr_t blk;
	long size;
{
I 7
	int i;
	char *cp;
E 7

	if (fcp->wfdes < 0)
D 7
		return (0);
E 7
I 7
		return;
E 7
D 15
	if (lseek(fcp->wfdes, (long)dbtob(blk), 0) < 0)
E 15
I 15
	if (lseek(fcp->wfdes, blk * dev_bsize, 0) < 0)
E 15
		rwerr("SEEK", blk);
	else if (write(fcp->wfdes, buf, (int)size) == size) {
		fcp->mod = 1;
D 7
		return (1);
E 7
I 7
		return;
E 7
	}
	rwerr("WRITE", blk);
D 7
	return (0);
E 7
I 7
D 15
	if (lseek(fcp->wfdes, (long)dbtob(blk), 0) < 0)
E 15
I 15
	if (lseek(fcp->wfdes, blk * dev_bsize, 0) < 0)
E 15
		rwerr("SEEK", blk);
D 16
	pfatal("THE FOLLOWING SECTORS COULD NOT BE WRITTEN:");
E 16
I 16
	printf("THE FOLLOWING SECTORS COULD NOT BE WRITTEN:");
E 16
D 13
	for (cp = buf, i = 0; i < size; i += DEV_BSIZE, cp += DEV_BSIZE)
D 11
		if (write(fcp->wfdes, cp, DEV_BSIZE) < 0)
E 11
I 11
		if (write(fcp->wfdes, cp, DEV_BSIZE) < 0) {
			lseek(fcp->rfdes, (long)dbtob(blk) + i + DEV_BSIZE, 0);
E 11
			printf(" %d,", blk + i / DEV_BSIZE);
E 13
I 13
	for (cp = buf, i = 0; i < size; i += dev_bsize, cp += dev_bsize)
		if (write(fcp->wfdes, cp, dev_bsize) < 0) {
D 15
			lseek(fcp->rfdes, (long)dbtob(blk) + i + dev_bsize, 0);
E 15
I 15
			lseek(fcp->rfdes, blk * dev_bsize + i + dev_bsize, 0);
E 15
			printf(" %d,", blk + i / dev_bsize);
E 13
I 11
		}
E 11
	printf("\n");
	return;
E 7
}

I 3
/*
 * allocate a data block with the specified number of fragments
 */
allocblk(frags)
	int frags;
{
	register int i, j, k;

	if (frags <= 0 || frags > sblock.fs_frag)
		return (0);
	for (i = 0; i < fmax - sblock.fs_frag; i += sblock.fs_frag) {
		for (j = 0; j <= sblock.fs_frag - frags; j++) {
			if (getbmap(i + j))
				continue;
			for (k = 1; k < frags; k++)
				if (getbmap(i + j + k))
					break;
			if (k < frags) {
				j += k;
				continue;
			}
			for (k = 0; k < frags; k++)
				setbmap(i + j + k);
			n_blks += frags;
			return (i + j);
		}
	}
	return (0);
}

/*
 * Free a previously allocated block
 */
freeblk(blkno, frags)
	daddr_t blkno;
	int frags;
{
	struct inodesc idesc;

	idesc.id_blkno = blkno;
	idesc.id_numfrags = frags;
	pass4check(&idesc);
I 4
}

/*
 * Find a pathname
 */
getpathname(namebuf, curdir, ino)
	char *namebuf;
	ino_t curdir, ino;
{
	int len;
	register char *cp;
	struct inodesc idesc;
	extern int findname();

	if (statemap[ino] != DSTATE && statemap[ino] != DFOUND) {
		strcpy(namebuf, "?");
		return;
	}
	bzero(&idesc, sizeof(struct inodesc));
	idesc.id_type = DATA;
	cp = &namebuf[BUFSIZ - 1];
D 10
	*cp-- = '\0';
E 10
I 10
	*cp = '\0';
E 10
	if (curdir != ino) {
		idesc.id_parent = curdir;
		goto namelookup;
	}
	while (ino != ROOTINO) {
		idesc.id_number = ino;
		idesc.id_func = findino;
		idesc.id_name = "..";
D 10
		if ((ckinode(ginode(ino), &idesc) & STOP) == 0)
E 10
I 10
		if ((ckinode(ginode(ino), &idesc) & FOUND) == 0)
E 10
			break;
	namelookup:
		idesc.id_number = idesc.id_parent;
		idesc.id_parent = ino;
		idesc.id_func = findname;
		idesc.id_name = namebuf;
D 10
		if ((ckinode(ginode(idesc.id_number), &idesc) & STOP) == 0)
E 10
I 10
		if ((ckinode(ginode(idesc.id_number), &idesc) & FOUND) == 0)
E 10
			break;
		len = strlen(namebuf);
		cp -= len;
		if (cp < &namebuf[MAXNAMLEN])
			break;
		bcopy(namebuf, cp, len);
		*--cp = '/';
		ino = idesc.id_number;
	}
	if (ino != ROOTINO) {
		strcpy(namebuf, "?");
		return;
	}
	bcopy(cp, namebuf, &namebuf[BUFSIZ] - cp);
E 4
}

E 3
catch()
{

	ckfini();
	exit(12);
}

/*
I 9
 * When preening, allow a single quit to signal
 * a special exit after filesystem checks complete
 * so that reboot sequence may be interrupted.
 */
catchquit()
{
	extern returntosingle;

	printf("returning to single-user after filesystem check\n");
	returntosingle = 1;
	(void)signal(SIGQUIT, SIG_DFL);
}

/*
 * Ignore a single quit signal; wait and flush just in case.
 * Used by child processes in preen.
 */
voidquit()
{

	sleep(1);
	(void)signal(SIGQUIT, SIG_IGN);
	(void)signal(SIGQUIT, SIG_DFL);
}

/*
E 9
 * determine whether an inode should be fixed.
 */
D 2
dofix(idesc)
E 2
I 2
dofix(idesc, msg)
E 2
	register struct inodesc *idesc;
I 2
	char *msg;
E 2
{

	switch (idesc->id_fix) {

	case DONTKNOW:
D 2
		direrr(idesc->id_number, "DIRECTORY CORRUPTED");
E 2
I 2
		if (idesc->id_type == DATA)
			direrr(idesc->id_number, msg);
		else
			pwarn(msg);
		if (preen) {
			printf(" (SALVAGED)\n");
			idesc->id_fix = FIX;
			return (ALTERED);
		}
E 2
		if (reply("SALVAGE") == 0) {
			idesc->id_fix = NOFIX;
			return (0);
		}
		idesc->id_fix = FIX;
		return (ALTERED);

	case FIX:
		return (ALTERED);

	case NOFIX:
		return (0);

	default:
		errexit("UNKNOWN INODESC FIX MODE %d\n", idesc->id_fix);
	}
	/* NOTREACHED */
}

/* VARARGS1 */
D 2
error(s1, s2, s3, s4)
	char *s1;
{

	printf(s1, s2, s3, s4);
}

/* VARARGS1 */
E 2
errexit(s1, s2, s3, s4)
	char *s1;
{
D 2
	error(s1, s2, s3, s4);
E 2
I 2
	printf(s1, s2, s3, s4);
E 2
	exit(8);
}

/*
 * An inconsistency occured which shouldn't during normal operations.
 * Die if preening, otherwise just printf.
 */
/* VARARGS1 */
pfatal(s, a1, a2, a3)
	char *s;
{

	if (preen) {
		printf("%s: ", devname);
		printf(s, a1, a2, a3);
		printf("\n");
D 2
		preendie();
E 2
I 2
		printf("%s: UNEXPECTED INCONSISTENCY; RUN fsck MANUALLY.\n",
			devname);
		exit(8);
E 2
	}
	printf(s, a1, a2, a3);
}

D 2
preendie()
{

	printf("%s: UNEXPECTED INCONSISTENCY; RUN fsck MANUALLY.\n", devname);
	exit(8);
}

E 2
/*
 * Pwarn is like printf when not preening,
 * or a warning (preceded by filename) when preening.
 */
/* VARARGS1 */
pwarn(s, a1, a2, a3, a4, a5, a6)
	char *s;
{

	if (preen)
		printf("%s: ", devname);
	printf(s, a1, a2, a3, a4, a5, a6);
}

#ifndef lint
/*
 * Stub for routines from kernel.
 */
panic(s)
	char *s;
{

D 2
	pfatal("INTERNAL INCONSISTENCY: %s\n", s);
	exit(12);
E 2
I 2
	pfatal("INTERNAL INCONSISTENCY:");
	errexit(s);
E 2
}
#endif
E 1
