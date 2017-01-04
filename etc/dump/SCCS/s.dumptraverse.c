h60893
s 00017/00004/00345
d D 5.5 88/05/20 10:03:02 karels 25 23
c update 'bread error' message, attempt read a sector at a time after error,
c don't return old stuff in buffer after read failure
e
s 00001/00001/00348
d R 5.5 87/06/18 10:13:12 mckusick 24 23
c must dump last inode! bug report 4.3BSD/etc/69
e
s 00004/00004/00345
d D 5.4 87/02/23 18:06:26 mckusick 23 22
c convert SBLOCK to SBOFF; generalize dev_bsize
e
s 00013/00014/00336
d D 5.3 86/01/09 21:28:29 mckusick 22 21
c speedup and cleanup by Chris Torek
e
s 00005/00002/00345
d D 5.2 85/08/05 14:43:13 mckusick 21 20
c optimization (from speck@cit-vlsi)
e
s 00009/00001/00338
d D 5.1 85/06/05 08:47:37 dist 20 19
c Add copyright
e
s 00011/00000/00328
d D 1.17 84/10/05 15:56:11 mckusick 19 18
c maintain consistent dump tapes on active systems (decvax!watmath!srradia)
e
s 00002/00009/00326
d D 1.16 84/03/08 16:26:18 mckusick 18 17
c always dump entire map, not just the non-zero portion
e
s 00034/00024/00301
d D 1.15 83/09/25 16:46:13 mckusick 17 16
c kludge to handle case where we need to read the last fragment in a file system
e
s 00018/00010/00307
d D 1.14 83/09/08 11:09:57 mckusick 16 15
c do not depend on unused portions of directories being zero
e
s 00001/00008/00316
d D 1.13 83/02/11 12:58:45 sam 15 14
c merge from sun
e
s 00001/00001/00323
d D 1.12 82/12/02 17:52:24 mckusick 14 13
c fix to properly dump 4096/512 byte file systems
e
s 00002/00002/00322
d D 1.11 82/10/14 12:52:46 mckusick 13 12
c fix to properly dump file systems with 512 byte frags
e
s 00000/00001/00324
d D 1.10 82/10/07 19:28:16 mckusick 12 11
c move struct itime out of dumprestor.h into dump.h
e
s 00001/00001/00324
d D 1.9 82/10/07 18:22:06 mckusick 11 10
c update to new magic number
e
s 00001/00001/00324
d D 1.8 82/05/20 15:11:20 sam 10 9
c convert to calder
e
s 00002/00002/00323
d D 1.7 82/03/23 12:53:03 mckusick 9 8
c add symbolic links
e
s 00016/00014/00309
d D 1.6 82/02/23 12:59:25 mckusic 8 7
c convert to new directory format
e
s 00001/00001/00322
d D 1.5 82/01/12 22:33:02 mckusic 7 6
c change all macros taking "fs" to have it as their first argument
e
s 00084/00109/00239
d D 1.4 82/01/05 01:37:35 mckusic 6 5
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00096/00038/00252
d D 1.3 81/11/07 15:05:58 mckusic 5 2
c dump from "standard" (ie 1K file system) dump tapes
e
s 00090/00032/00258
d R 1.3 81/11/07 14:55:18 mckusic 4 2
c dump to "standard" (ie 1K file system) dump tapes
e
s 00095/00031/00259
d R 1.3 81/11/07 14:53:23 mckusic 3 2
c dump to "standard" (ie 1K file system) dump tapes
e
s 00051/00045/00239
d D 1.2 81/10/31 18:30:56 mckusic 2 1
c 8K only dump/restor
e
s 00284/00000/00000
d D 1.1 80/10/13 17:30:31 root 1 0
c date and time created 80/10/13 17:30:31 by root
e
u
U
t
T
I 1
D 20
static	char *sccsid = "%W% (Berkeley) %G%";
E 20
I 20
/*
D 25
 * Copyright (c) 1980 Regents of the University of California.
E 25
I 25
 * Copyright (c) 1980, 1988 Regents of the University of California.
E 25
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 20
I 6

E 6
#include "dump.h"
I 8
D 10
#include <ndir.h>
E 10
I 10
D 12
#include <dir.h>
E 12
E 10
E 8

D 2
struct	filsys	sblock;
struct	dinode	itab[INOPB * NI];
E 2
I 2
D 6
struct	fs	sblock;
E 2

E 6
pass(fn, map)
D 2
int (*fn)();
short *map;
E 2
I 2
D 22
	int (*fn)();
D 6
	short *map;
E 6
I 6
	char *map;
E 22
I 22
	register int (*fn)();
	register char *map;
E 22
E 6
E 2
{
D 2
	register i, j;
E 2
I 2
D 22
	struct dinode *dp;
E 2
	int bits;
E 22
I 22
	register int bits;
E 22
D 2
	ino_t mino;
	daddr_t d;
E 2
I 2
	ino_t maxino;
E 2

D 6
	sync();
D 2
	bread((daddr_t)1, (char *)&sblock, sizeof(sblock));
	mino = (sblock.s_isize-2) * INOPB;
	ino = 0;
	for(i=2;; i+=NI) {
		if(ino >= mino)
			break;
		d = (unsigned)i;
		for(j=0; j<INOPB*NI; j++) {
			if(ino >= mino)
				break;
			if((ino % MLEN) == 0) {
				bits = ~0;
				if(map != NULL)
					bits = *map++;
			}
			ino++;
			if(bits & 1) {
				if(d != 0) {
					bread(d, (char *)itab, sizeof(itab));
					d = 0;
				}
				(*fn)(&itab[j]);
			}
			bits >>= 1;
E 2
I 2
	bread(SBLOCK, &sblock, sizeof sblock);
	if (sblock.fs_magic != FS_MAGIC) {
		msg("bad sblock magic number\n");
		dumpabort();
	}
	maxino = sblock.fs_ipg * sblock.fs_ncg;
E 6
I 6
	maxino = sblock->fs_ipg * sblock->fs_ncg - 1;
E 6
	for (ino = 0; ino < maxino; ) {
D 6
		if((ino % MLEN) == 0) {
E 6
I 6
D 22
		if((ino % NBBY) == 0) {
E 22
I 22
		if ((ino % NBBY) == 0) {
E 22
E 6
			bits = ~0;
D 22
			if(map != NULL)
E 22
I 22
			if (map != NULL)
E 22
				bits = *map++;
E 2
		}
I 2
		ino++;
D 22
		if(bits & 1) {
			dp = getino(ino);
			(*fn)(dp);
		}
E 22
I 22
		if (bits & 1)
			(*fn)(getino(ino));
E 22
		bits >>= 1;
E 2
	}
}

D 2
icat(ip, fn1, fn2)
struct	dinode	*ip;
int (*fn1)(), (*fn2)();
E 2
I 2
D 5
icat(dp, fn1, fn2)
E 5
I 5
D 6
icat(dp, fn1)
E 5
	register struct	dinode	*dp;
D 5
	int (*fn1)(), (*fn2)();
E 5
I 5
	int (*fn1)();
E 5
E 2
{
D 2
	register i;
	daddr_t d[NADDR];
E 2
I 2
	register int i;
E 2

D 2
	l3tol(&d[0], &ip->di_addr[0], NADDR);
	(*fn2)(d, NADDR-3);
	for(i=0; i<NADDR; i++) {
		if(d[i] != 0) {
			if(i < NADDR-3)
				(*fn1)(d[i]); else
				indir(d[i], fn1, fn2, i-(NADDR-3));
		}
E 2
I 2
D 5
	(*fn2)(dp->di_db, NDADDR);
E 5
	for (i = 0; i < NDADDR; i++) {
		if (dp->di_db[i] != 0)
			(*fn1)(dp->di_db[i]);
E 2
	}
I 2
	for (i = 0; i < NIADDR; i++) {
		if (dp->di_ib[i] != 0)
D 5
			indir(dp->di_ib[i], fn1, fn2, i);
E 5
I 5
			indir(dp->di_ib[i], fn1, i);
E 5
	}
E 2
}

D 5
indir(d, fn1, fn2, n)
daddr_t d;
int (*fn1)(), (*fn2)();
E 5
I 5
indir(d, fn1, n)
	daddr_t d;
	int (*fn1)();
	int n;
E 5
{
	register i;
	daddr_t	idblk[NINDIR];

	bread(d, (char *)idblk, sizeof(idblk));
	if(n <= 0) {
D 5
		spcl.c_type = TS_ADDR;
		(*fn2)(idblk, NINDIR);
E 5
		for(i=0; i<NINDIR; i++) {
			d = idblk[i];
			if(d != 0)
				(*fn1)(d);
		}
	} else {
		n--;
		for(i=0; i<NINDIR; i++) {
			d = idblk[i];
			if(d != 0)
D 5
				indir(d, fn1, fn2, n);
E 5
I 5
				indir(d, fn1, n);
E 5
		}
	}
}

E 6
mark(ip)
D 5
struct dinode *ip;
E 5
I 5
	struct dinode *ip;
E 5
{
D 22
	register f;
E 22
I 22
	register int f;
	extern int anydskipped;
E 22

	f = ip->di_mode & IFMT;
D 22
	if(f == 0)
E 22
I 22
	if (f == 0)
E 22
		return;
	BIS(ino, clrmap);
D 22
	if(f == IFDIR)
E 22
I 22
	if (f == IFDIR)
E 22
		BIS(ino, dirmap);
D 6
	if(ip->di_mtime >= spcl.c_ddate ||
	   ip->di_ctime >= spcl.c_ddate) {
E 6
I 6
	if ((ip->di_mtime >= spcl.c_ddate || ip->di_ctime >= spcl.c_ddate) &&
	    !BIT(ino, nodmap)) {
E 6
		BIS(ino, nodmap);
D 6
		if (f != IFREG){
E 6
I 6
D 9
		if (f != IFREG && f != IFDIR) {
E 9
I 9
		if (f != IFREG && f != IFDIR && f != IFLNK) {
E 9
E 6
			esize += 1;
			return;
		}
		est(ip);
D 22
	}
E 22
I 22
	} else if (f == IFDIR)
		anydskipped = 1;
E 22
}

add(ip)
D 5
struct dinode *ip;
E 5
I 5
D 6
	struct dinode *ip;
E 6
I 6
	register struct	dinode	*ip;
E 6
E 5
{
I 6
	register int i;
I 16
	long filesize;
E 16
E 6

	if(BIT(ino, nodmap))
		return;
	nsubdir = 0;
	dadded = 0;
I 16
	filesize = ip->di_size;
E 16
D 5
	icat(ip, dsrch, nullf);
E 5
I 5
D 6
	icat(ip, dsrch);
E 6
I 6
	for (i = 0; i < NDADDR; i++) {
		if (ip->di_db[i] != 0)
D 16
			dsrch(ip->di_db[i], dblksize(sblock, ip, i));
E 16
I 16
			dsrch(ip->di_db[i], dblksize(sblock, ip, i), filesize);
		filesize -= sblock->fs_bsize;
E 16
	}
	for (i = 0; i < NIADDR; i++) {
		if (ip->di_ib[i] != 0)
D 16
			indir(ip->di_ib[i], i);
E 16
I 16
			indir(ip->di_ib[i], i, &filesize);
E 16
	}
E 6
E 5
	if(dadded) {
D 6
		BIS(ino, nodmap);
		est(ip);
E 6
		nadded++;
I 6
		if (!BIT(ino, nodmap)) {
			BIS(ino, nodmap);
			est(ip);
		}
E 6
	}
	if(nsubdir == 0)
		if(!BIT(ino, nodmap))
			BIC(ino, dirmap);
}

I 6
D 16
indir(d, n)
E 16
I 16
indir(d, n, filesize)
E 16
	daddr_t d;
D 16
	int n;
E 16
I 16
	int n, *filesize;
E 16
{
	register i;
	daddr_t	idblk[MAXNINDIR];

	bread(fsbtodb(sblock, d), (char *)idblk, sblock->fs_bsize);
	if(n <= 0) {
		for(i=0; i < NINDIR(sblock); i++) {
			d = idblk[i];
			if(d != 0)
D 16
				dsrch(d, sblock->fs_bsize);
E 16
I 16
				dsrch(d, sblock->fs_bsize, *filesize);
			*filesize -= sblock->fs_bsize;
E 16
		}
	} else {
		n--;
		for(i=0; i < NINDIR(sblock); i++) {
			d = idblk[i];
			if(d != 0)
D 16
				indir(d, n);
E 16
I 16
				indir(d, n, filesize);
E 16
		}
	}
}

I 19
dirdump(ip)
	struct dinode *ip;
{
	/* watchout for dir inodes deleted and maybe reallocated */
	if ((ip->di_mode & IFMT) != IFDIR)
		return;
	dump(ip);
}

E 19
E 6
dump(ip)
D 5
struct dinode *ip;
E 5
I 5
	struct dinode *ip;
E 5
{
D 5
	register i;
E 5
I 5
	register int i;
	long size;
E 5

	if(newtape) {
		newtape = 0;
		bitmap(nodmap, TS_BITS);
	}
	BIC(ino, nodmap);
	spcl.c_dinode = *ip;
	spcl.c_type = TS_INODE;
	spcl.c_count = 0;
	i = ip->di_mode & IFMT;
I 19
	if (i == 0) /* free inode */
		return;
E 19
D 5
	if(i != IFDIR && i != IFREG) {
E 5
I 5
D 9
	if ((i != IFDIR && i != IFREG) || ip->di_size == 0) {
E 9
I 9
	if ((i != IFDIR && i != IFREG && i != IFLNK) || ip->di_size == 0) {
E 9
E 5
		spclrec();
		return;
	}
D 5
	icat(ip, tapsrec, dmpspc);
E 5
I 5
D 6
	if (ip->di_size > NDADDR * BSIZE)
		i = NDADDR * FRAG;
E 6
I 6
	if (ip->di_size > NDADDR * sblock->fs_bsize)
		i = NDADDR * sblock->fs_frag;
E 6
	else
D 6
		i = howmany(ip->di_size, FSIZE);
E 6
I 6
		i = howmany(ip->di_size, sblock->fs_fsize);
E 6
	blksout(&ip->di_db[0], i);
D 6
	size = ip->di_size - NDADDR * BSIZE;
E 6
I 6
	size = ip->di_size - NDADDR * sblock->fs_bsize;
E 6
	if (size <= 0)
		return;
	for (i = 0; i < NIADDR; i++) {
		dmpindir(ip->di_ib[i], i, &size);
		if (size <= 0)
			return;
	}
E 5
}

D 5
dmpspc(dp, n)
daddr_t *dp;
E 5
I 5
dmpindir(blk, lvl, size)
	daddr_t blk;
	int lvl;
	long *size;
E 5
{
D 5
	register i, t;
E 5
I 5
	int i, cnt;
D 6
	daddr_t idblk[NINDIR];
E 6
I 6
	daddr_t idblk[MAXNINDIR];
E 6
E 5

D 5
	spcl.c_count = n;
	for(i=0; i<n; i++) {
		t = 0;
		if(dp[i] != 0)
			t++;
		spcl.c_addr[i] = t;
E 5
I 5
	if (blk != 0)
D 6
		bread(blk, (char *)idblk, sizeof(idblk));
E 6
I 6
		bread(fsbtodb(sblock, blk), (char *)idblk, sblock->fs_bsize);
E 6
	else
D 6
		blkclr(idblk, sizeof(idblk));
E 6
I 6
D 15
		blkclr(idblk, sblock->fs_bsize);
E 15
I 15
		bzero(idblk, sblock->fs_bsize);
E 15
E 6
	if (lvl <= 0) {
D 6
		if (*size < NINDIR * BSIZE)
			cnt = howmany(*size, TP_BSIZE);
E 6
I 6
		if (*size < NINDIR(sblock) * sblock->fs_bsize)
			cnt = howmany(*size, sblock->fs_fsize);
E 6
		else
D 6
			cnt = NINDIR * BLKING * FRAG;
		*size -= NINDIR * BSIZE;
E 6
I 6
			cnt = NINDIR(sblock) * sblock->fs_frag;
		*size -= NINDIR(sblock) * sblock->fs_bsize;
E 6
		blksout(&idblk[0], cnt);
		return;
E 5
	}
D 5
	spclrec();
E 5
I 5
	lvl--;
D 6
	for (i = 0; i < NINDIR; i++) {
E 6
I 6
	for (i = 0; i < NINDIR(sblock); i++) {
E 6
		dmpindir(idblk[i], lvl, size);
		if (*size <= 0)
			return;
	}
E 5
}

I 5
blksout(blkp, frags)
	daddr_t *blkp;
	int frags;
{
D 6
	int i, j, count, blks;
E 6
I 6
	int i, j, count, blks, tbperdb;
E 6

D 6
	blks = frags * BLKING;
E 6
I 6
D 13
	blks = frags * BLKING(sblock);
	tbperdb = BLKING(sblock) * sblock->fs_frag;
E 13
I 13
D 14
	blks = frags * sblock->fs_fsize / TP_BSIZE;
E 14
I 14
	blks = howmany(frags * sblock->fs_fsize, TP_BSIZE);
E 14
	tbperdb = sblock->fs_bsize / TP_BSIZE;
E 13
E 6
	for (i = 0; i < blks; i += TP_NINDIR) {
		if (i + TP_NINDIR > blks)
			count = blks;
		else
			count = i + TP_NINDIR;
		for (j = i; j < count; j++)
D 6
			if (blkp[j / (BLKING * FRAG)] != 0)
E 6
I 6
			if (blkp[j / tbperdb] != 0)
E 6
				spcl.c_addr[j - i] = 1;
			else
				spcl.c_addr[j - i] = 0;
		spcl.c_count = count - i;
		spclrec();
D 6
		for (j = i; j < count; j += (BLKING * FRAG))
			if (blkp[j / (BLKING * FRAG)] != 0)
				if (j + (BLKING * FRAG) <= count)
					dmpblk(blkp[j / (BLKING * FRAG)],
					    BSIZE);
E 6
I 6
		for (j = i; j < count; j += tbperdb)
			if (blkp[j / tbperdb] != 0)
				if (j + tbperdb <= count)
					dmpblk(blkp[j / tbperdb],
					    sblock->fs_bsize);
E 6
				else
D 6
					dmpblk(blkp[j / (BLKING * FRAG)],
E 6
I 6
					dmpblk(blkp[j / tbperdb],
E 6
					    (count - j) * TP_BSIZE);
		spcl.c_type = TS_ADDR;
	}
}

E 5
bitmap(map, typ)
D 5
short *map;
E 5
I 5
D 6
	short *map;
E 6
I 6
	char *map;
E 6
E 5
{
D 18
	register i, n;
E 18
I 18
	register i;
E 18
	char *cp;

D 18
	n = -1;
D 6
	for(i=0; i<MSIZ; i++)
E 6
I 6
	for (i = 0; i < msiz; i++)
E 6
		if(map[i])
			n = i;
D 6
	if(n < 0)
E 6
I 6
	if (n < 0)
E 6
		return;
I 6
	n++;
E 18
E 6
	spcl.c_type = typ;
D 5
	spcl.c_count = (n*sizeof(map[0]) + BSIZE)/BSIZE;
E 5
I 5
D 6
	spcl.c_count = (n*sizeof(map[0]) + TP_BSIZE)/TP_BSIZE;
E 6
I 6
D 18
	spcl.c_count = howmany(n * sizeof(map[0]), TP_BSIZE);
E 18
I 18
	spcl.c_count = howmany(msiz * sizeof(map[0]), TP_BSIZE);
E 18
E 6
E 5
	spclrec();
D 6
	cp = (char *)map;
	for(i=0; i<spcl.c_count; i++) {
E 6
I 6
	for (i = 0, cp = map; i < spcl.c_count; i++, cp += TP_BSIZE)
E 6
		taprec(cp);
D 5
		cp += BSIZE;
E 5
I 5
D 6
		cp += TP_BSIZE;
E 5
	}
E 6
}

spclrec()
{
D 5
	register i, *ip, s;
E 5
I 5
	register int s, i, *ip;
E 5

	spcl.c_inumber = ino;
D 11
	spcl.c_magic = MAGIC;
E 11
I 11
	spcl.c_magic = NFS_MAGIC;
E 11
	spcl.c_checksum = 0;
	ip = (int *)&spcl;
	s = 0;
D 5
	for(i=0; i<BSIZE/sizeof(*ip); i++)
E 5
I 5
D 21
	for(i = 0; i < sizeof(union u_spcl)/sizeof(int); i++)
E 5
		s += *ip++;
E 21
I 21
	i = sizeof(union u_spcl) / (4*sizeof(int));
	while (--i >= 0) {
		s += *ip++; s += *ip++;
		s += *ip++; s += *ip++;
	}
E 21
	spcl.c_checksum = CHECKSUM - s;
	taprec((char *)&spcl);
}

D 6
dsrch(d)
E 6
I 6
D 16
dsrch(d, size)
E 16
I 16
dsrch(d, size, filesize)
E 16
E 6
D 5
daddr_t d;
E 5
I 5
	daddr_t d;
I 6
D 16
	int size;
E 16
I 16
	int size, filesize;
E 16
E 6
E 5
{
D 8
	register char *cp;
	register i;
	register ino_t in;
D 6
	struct direct dblk[DIRPB];
E 6
I 6
	struct direct dblk[MAXDIRPB];
E 8
I 8
	register struct direct *dp;
	long loc;
	char dblk[MAXBSIZE];
E 8
E 6

	if(dadded)
		return;
D 6
	bread(d, (char *)dblk, sizeof(dblk));
	for(i=0; i<DIRPB; i++) {
E 6
I 6
D 8
	bread(fsbtodb(sblock, d), (char *)dblk, size);
	for(i=0; i < DIRPB(sblock); i++) {
E 6
		in = dblk[i].d_ino;
		if(in == 0)
E 8
I 8
D 17
	bread(fsbtodb(sblock, d), dblk, size);
E 17
D 16
	for (loc = 0; loc < size; ) {
E 16
I 16
	if (filesize > size)
		filesize = size;
I 17
	bread(fsbtodb(sblock, d), dblk, filesize);
E 17
	for (loc = 0; loc < filesize; ) {
E 16
		dp = (struct direct *)(dblk + loc);
D 16
		if (dp->d_reclen == 0)
E 16
I 16
		if (dp->d_reclen == 0) {
			msg("corrupted directory, inumber %d\n", ino);
E 16
			break;
I 16
		}
E 16
		loc += dp->d_reclen;
		if(dp->d_ino == 0)
E 8
			continue;
D 8
		cp = dblk[i].d_name;
		if(cp[0] == '.') {
			if(cp[1] == '\0')
E 8
I 8
		if(dp->d_name[0] == '.') {
			if(dp->d_name[1] == '\0')
E 8
				continue;
D 8
			if(cp[1] == '.' && cp[2] == '\0')
E 8
I 8
			if(dp->d_name[1] == '.' && dp->d_name[2] == '\0')
E 8
				continue;
		}
D 8
		if(BIT(in, nodmap)) {
E 8
I 8
		if(BIT(dp->d_ino, nodmap)) {
E 8
			dadded++;
			return;
		}
D 8
		if(BIT(in, dirmap))
E 8
I 8
		if(BIT(dp->d_ino, dirmap))
E 8
			nsubdir++;
	}
}

D 5
nullf()
{
}

E 5
I 2
struct dinode *
getino(ino)
	daddr_t ino;
{
	static daddr_t minino, maxino;
D 6
	static struct dinode itab[INOPB];
E 6
I 6
	static struct dinode itab[MAXINOPB];
E 6

	if (ino >= minino && ino < maxino) {
		return (&itab[ino - minino]);
	}
D 6
	bread(itod(ino, &sblock), itab, BSIZE);
	minino = ino - (ino % INOPB);
	maxino = minino + INOPB;
E 6
I 6
D 7
	bread(fsbtodb(sblock, itod(ino, sblock)), itab, sblock->fs_bsize);
E 7
I 7
	bread(fsbtodb(sblock, itod(sblock, ino)), itab, sblock->fs_bsize);
E 7
	minino = ino - (ino % INOPB(sblock));
	maxino = minino + INOPB(sblock);
E 6
	return (&itab[ino - minino]);
}

E 2
int	breaderrors = 0;		
#define	BREADEMAX 32

D 17
bread(da, ba, c)
E 17
I 17
bread(da, ba, cnt)
E 17
	daddr_t da;
	char *ba;
D 17
	int	c;	
E 17
I 17
	int	cnt;	
E 17
{
D 17
	register n;
	register	regc;
E 17
I 17
D 25
	int n;
E 25
I 25
	int n, i;
	extern int errno;
E 25
E 17

I 17
loop:
E 17
D 2
	if (lseek(fi, (long)(da*BSIZE), 0) < 0){
E 2
I 2
D 6
	if (lseek(fi, (long)(da*FSIZE), 0) < 0){
E 6
I 6
D 23
	if (lseek(fi, (long)(da * DEV_BSIZE), 0) < 0){
E 23
I 23
	if (lseek(fi, (long)(da * dev_bsize), 0) < 0){
E 23
E 6
E 2
		msg("bread: lseek fails\n");
	}
D 17
	regc = c;	/* put c someplace safe; it gets clobbered */
	n = read(fi, ba, c);
D 6
	if(n != c || regc != c){
E 6
I 6
	if (n != c || regc != c) {
E 6
		msg("(This should not happen)bread from %s [block %d]: c=0x%x, regc=0x%x, &c=0x%x, n=0x%x\n",
			disk, da, c, regc, &c, n);
#ifdef ERNIE
		msg("Notify Robert Henry of this error.\n");
#endif
		if (++breaderrors > BREADEMAX){
			msg("More than %d block read errors from %d\n",
				BREADEMAX, disk);
			broadcast("DUMP IS AILING!\n");
			msg("This is an unrecoverable error.\n");
			if (!query("Do you want to attempt to continue?")){
				dumpabort();
				/*NOTREACHED*/
			} else
				breaderrors = 0;
		}
E 17
I 17
	n = read(fi, ba, cnt);
	if (n == cnt)
		return;
D 23
	if (da + (cnt / DEV_BSIZE) > fsbtodb(sblock, sblock->fs_size)) {
E 23
I 23
	if (da + (cnt / dev_bsize) > fsbtodb(sblock, sblock->fs_size)) {
E 23
		/*
		 * Trying to read the final fragment.
		 *
		 * NB - dump only works in TP_BSIZE blocks, hence
D 23
		 * rounds DEV_BSIZE fragments up to TP_BSIZE pieces.
E 23
I 23
		 * rounds `dev_bsize' fragments up to TP_BSIZE pieces.
E 23
		 * It should be smarter about not actually trying to
		 * read more than it can get, but for the time being
		 * we punt and scale back the read only when it gets
		 * us into trouble. (mkm 9/25/83)
		 */
D 23
		cnt -= DEV_BSIZE;
E 23
I 23
		cnt -= dev_bsize;
E 23
		goto loop;
	}
D 25
	msg("(This should not happen)bread from %s [block %d]: count=%d, got=%d\n",
		disk, da, cnt, n);
E 25
I 25
	msg("read error from %s [block %d]: count=%d, got=%d, errno=%d\n",
		disk, da, cnt, n, errno);
E 25
	if (++breaderrors > BREADEMAX){
		msg("More than %d block read errors from %d\n",
			BREADEMAX, disk);
		broadcast("DUMP IS AILING!\n");
		msg("This is an unrecoverable error.\n");
		if (!query("Do you want to attempt to continue?")){
			dumpabort();
			/*NOTREACHED*/
		} else
			breaderrors = 0;
I 25
	}
	/*
	 * Zero buffer, then try to read each sector of buffer separately.
	 */
	bzero(ba, cnt);
	for (i = 0; i < cnt; i += dev_bsize, ba += dev_bsize, da++) {
		if (lseek(fi, (long)(da * dev_bsize), 0) < 0)
			msg("bread: lseek2 fails!\n");
		n = read(fi, ba, dev_bsize);
		if (n != dev_bsize)
			msg("    read error from %s [sector %d, errno %d]\n",
			    disk, da, errno);
E 25
E 17
	}
D 6
}

CLR(map)
D 5
register short *map;
E 5
I 5
	register short *map;
E 5
{
	register n;

	n = MSIZ;
	do
		*map++ = 0;
	while(--n);
E 6
D 15
}

I 5
blkclr(cp, size)
	char *cp;
	long size;
{
	asm("movc5	$0,(r0),$0,8(ap),*4(ap)");
E 15
}
E 5
E 1
