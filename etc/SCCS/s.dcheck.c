h43836
s 00020/00012/00233
d D 5.3 88/05/02 16:56:38 mckusick 15 14
c convert to understand dynamic file systems
e
s 00004/00002/00241
d D 5.2 87/02/23 17:39:48 mckusick 14 13
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00015/00002/00228
d D 5.1 85/06/06 11:02:25 dist 13 12
c Add copyright
e
s 00003/00008/00227
d D 2.4 83/07/01 03:12:47 sam 12 11
c include fixes
e
s 00003/00007/00232
d D 2.3 82/05/10 00:39:48 mckusick 11 10
c get rid of 65K limit on number of inodes
e
s 00002/00002/00237
d D 2.2 82/05/10 00:21:54 mckusick 10 9
c update to new fs
e
s 00006/00000/00233
d D 2.1 82/04/08 15:33:17 mckusick 9 8
c merge into the new kernel
e
s 00002/00002/00231
d D 1.8 82/02/25 14:48:33 mckusic 8 7
c use speed-up macros in fs.h
e
s 00056/00039/00177
d D 1.7 82/02/23 22:47:53 mckusic 7 6
c convert to new directory format
e
s 00002/00002/00214
d D 1.6 82/01/12 22:17:51 mckusic 6 5
c change all macros taking "fs" to have it as their first argument
e
s 00002/00002/00214
d D 1.5 82/01/06 23:34:24 mckusic 5 4
c incorporate fs.h -r1.10, and param.h -r1.8 reorganization
e
s 00015/00013/00201
d D 1.4 82/01/05 01:33:31 mckusic 4 3
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00001/00001/00213
d D 1.3 81/09/22 21:55:40 mckusic 3 2
c allow files and directories to have FRAGS as their final block
e
s 00004/00005/00210
d D 1.2 81/08/28 21:22:22 mckusic 2 1
c put in new inode structure
e
s 00215/00000/00000
d D 1.1 81/08/26 23:47:46 mckusick 1 0
c date and time created 81/08/26 23:47:46 by mckusick
e
u
U
t
T
I 13
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 13
I 12
#ifndef lint
E 12
I 1
D 10
static	char *sccsid = "%W% (Berkeley) %G%";
E 10
I 10
D 11
static char sccsid[] = "%Z%%M% %I% %G%";
E 11
I 11
D 13
static	char *sccsid = "%W% (Berkeley) %G%";
I 12
#endif
E 13
I 13
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 13
E 12
E 11
E 10
/*
 * dcheck - check directory consistency
 */
#define	NB	10
D 4
#define	NDIR	(BSIZE/sizeof(struct direct))
E 4
I 4
D 7
#define	NDIR(fs)	((fs)->fs_bsize/sizeof(struct direct))
#define	MAXNDIR		(MAXBSIZE/sizeof(struct direct))
E 7
D 5
#define	MAXNINDIR	(MAXBSIZE/sizeof(daddr_t))
E 5
I 5
#define	MAXNINDIR	(MAXBSIZE / sizeof (daddr_t))
E 5
E 4

I 9
D 12
#ifndef SIMFS
E 12
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
I 11
D 12
#include <dir.h>
E 11
#else
E 9
D 7
#include <stdio.h>
E 7
#include "../h/param.h"
#include "../h/inode.h"
D 2
#include "../h/ino.h"
E 2
D 7
#include "../h/dir.h"
E 7
#include "../h/fs.h"
I 11
#include "../h/ndir.h"
E 11
I 9
#endif
E 12
I 12
#include <sys/dir.h>
E 12
E 9
I 7
D 10
#include <ndir.h>
E 10
I 10
D 11
#include <dir.h>
E 11
E 10
#include <stdio.h>
E 7

union {
	struct	fs fs;
D 4
	char pad[BSIZE];
E 4
I 4
D 15
	char pad[MAXBSIZE];
E 15
I 15
	char pad[SBSIZE];
E 15
E 4
} fsun;
#define	sblock	fsun.fs

I 7
struct dirstuff {
	int loc;
	struct dinode *ip;
	char dbuf[MAXBSIZE];
};

E 7
D 15
struct	dinode	itab[MAXIPG];
E 15
I 15
struct	dinode	itab[MAXBSIZE / sizeof(struct dinode)];
E 15
D 2
daddr_t	iaddr[NDADDR+NIADDR];
E 2
I 2
struct	dinode	*gip;
E 2
ino_t	ilist[NB];

int	fi;
ino_t	ino;
ino_t	*ecount;
int	headpr;
int	nfiles;
I 14
long	dev_bsize = 1;
E 14

int	nerror;
daddr_t	bmap();
long	atol();
char	*malloc();

main(argc, argv)
char *argv[];
{
	register i;
	long n;

	while (--argc) {
		argv++;
		if (**argv=='-')
		switch ((*argv)[1]) {

		case 'i':
			for(i=0; i<NB; i++) {
				n = atol(argv[1]);
				if(n == 0)
					break;
				ilist[i] = n;
				argv++;
				argc--;
			}
			ilist[i] = 0;
			continue;

		default:
			printf("Bad flag %c\n", (*argv)[1]);
			nerror++;
		}
		check(*argv);
	}
	return(nerror);
}

check(file)
char *file;
{
	register i, j, c;

	fi = open(file, 0);
	if(fi < 0) {
		printf("cannot open %s\n", file);
		nerror++;
		return;
	}
	headpr = 0;
	printf("%s:\n", file);
	sync();
D 4
	bread(SBLOCK, (char *)&sblock, BSIZE);
E 4
I 4
D 5
	bread(SBLOCK, (char *)&sblock, MAXBSIZE);
E 5
I 5
D 14
	bread(SBLOCK, (char *)&sblock, SBSIZE);
E 14
I 14
	bread(SBOFF, (char *)&sblock, SBSIZE);
E 14
E 5
E 4
	if (sblock.fs_magic != FS_MAGIC) {
		printf("%s: not a file system\n", file);
		nerror++;
		return;
	}
I 14
	dev_bsize = sblock.fs_fsize / fsbtodb(&sblock, 1);
E 14
	nfiles = sblock.fs_ipg * sblock.fs_ncg;
D 11
	if (nfiles > 65535) {
		printf("%s: preposterous number of files\n", file);
		nerror++;
		return;
	}
E 11
	ecount = (ino_t *)malloc((nfiles+1) * sizeof (*ecount));
	if (ecount == 0) {
		printf("%s: not enough core for %d files\n", file, nfiles);
		exit(04);
	}
	for (i = 0; i<=nfiles; i++)
		ecount[i] = 0;
	ino = 0;
	for (c = 0; c < sblock.fs_ncg; c++) {
D 4
		bread(cgimin(c, &sblock), (char *)itab,
E 4
I 4
D 6
		bread(fsbtodb(&sblock, cgimin(c, &sblock)), (char *)itab,
E 6
I 6
D 15
		bread(fsbtodb(&sblock, cgimin(&sblock, c)), (char *)itab,
E 6
E 4
		    sblock.fs_ipg * sizeof (struct dinode));
		for (j = 0; j < sblock.fs_ipg; j++) {
			pass1(&itab[j]);
			ino++;
E 15
I 15
		for (i = 0;
		     i < sblock.fs_ipg / INOPF(&sblock);
		     i += sblock.fs_frag) {
			bread(fsbtodb(&sblock, cgimin(&sblock, c) + i),
			    (char *)itab, sblock.fs_bsize);
			for (j = 0; j < INOPB(&sblock); j++) {
				pass1(&itab[j]);
				ino++;
			}
E 15
		}
	}
	ino = 0;
	for (c = 0; c < sblock.fs_ncg; c++) {
D 4
		bread(cgimin(c, &sblock), (char *)itab,
E 4
I 4
D 6
		bread(fsbtodb(&sblock, cgimin(c, &sblock)), (char *)itab,
E 6
I 6
D 15
		bread(fsbtodb(&sblock, cgimin(&sblock, c)), (char *)itab,
E 6
E 4
		    sblock.fs_ipg * sizeof (struct dinode));
		for (j = 0; j < sblock.fs_ipg; j++) {
			pass2(&itab[j]);
			ino++;
E 15
I 15
		for (i = 0;
		     i < sblock.fs_ipg / INOPF(&sblock);
		     i += sblock.fs_frag) {
			bread(fsbtodb(&sblock, cgimin(&sblock, c) + i),
			    (char *)itab, sblock.fs_bsize);
			for (j = 0; j < INOPB(&sblock); j++) {
				pass2(&itab[j]);
				ino++;
			}
E 15
		}
	}
	free(ecount);
}

pass1(ip)
D 7
register struct dinode *ip;
E 7
I 7
	register struct dinode *ip;
E 7
{
D 4
	struct direct dbuf[NDIR];
E 4
I 4
D 7
	struct direct dbuf[MAXNDIR];
E 4
	long doff;
	struct direct *dp;
	register i, j;
E 7
I 7
	register struct direct *dp;
	struct dirstuff dirp;
E 7
	int k;
D 7
	daddr_t d;
	ino_t kno;
E 7

	if((ip->di_mode&IFMT) != IFDIR)
		return;
I 7
	dirp.loc = 0;
	dirp.ip = ip;
E 7
D 2
	l3tol(iaddr, ip->di_addr, NDADDR+NIADDR);
E 2
I 2
	gip = ip;
E 2
D 7
	doff = 0;
	for(i=0;; i++) {
		if(doff >= ip->di_size)
			break;
		d = bmap(i);
		if(d == 0)
			break;
D 4
		bread(d, (char *)dbuf, BSIZE);
		for(j=0; j<NDIR; j++) {
E 4
I 4
		bread(fsbtodb(&sblock, d), (char *)dbuf, sblock.fs_bsize);
		for(j=0; j < NDIR(&sblock); j++) {
E 4
			if(doff >= ip->di_size)
				break;
			doff += sizeof(struct direct);
			dp = &dbuf[j];
			kno = dp->d_ino;
			if(kno == 0)
				continue;
			if(kno > nfiles || kno < ROOTINO) {
				printf("%d bad; %d/%.*s\n",
				    kno, ino, DIRSIZ, dp->d_name);
E 7
I 7
	for (dp = readdir(&dirp); dp != NULL; dp = readdir(&dirp)) {
		if(dp->d_ino == 0)
			continue;
		if(dp->d_ino > nfiles || dp->d_ino < ROOTINO) {
			printf("%d bad; %d/%s\n",
			    dp->d_ino, ino, dp->d_name);
			nerror++;
			continue;
		}
		for (k = 0; ilist[k] != 0; k++)
			if (ilist[k] == dp->d_ino) {
				printf("%d arg; %d/%s\n",
				     dp->d_ino, ino, dp->d_name);
E 7
				nerror++;
D 7
				continue;
E 7
			}
D 7
			for (k=0; ilist[k] != 0; k++)
				if (ilist[k]==kno) {
					printf("%d arg; %d/%.*s\n",
					    kno, ino, DIRSIZ, dp->d_name);
					nerror++;
				}
			ecount[kno]++;
		}
E 7
I 7
		ecount[dp->d_ino]++;
E 7
	}
}

pass2(ip)
register struct dinode *ip;
{
	register i;

	i = ino;
	if ((ip->di_mode&IFMT)==0 && ecount[i]==0)
		return;
	if (ip->di_nlink==ecount[i] && ip->di_nlink!=0)
		return;
	if (headpr==0) {
		printf("     entries  link cnt\n");
		headpr++;
	}
	printf("%u\t%d\t%d\n", ino,
	    ecount[i], ip->di_nlink);
I 7
}

/*
 * get next entry in a directory.
 */
struct direct *
readdir(dirp)
	register struct dirstuff *dirp;
{
	register struct direct *dp;
	daddr_t lbn, d;

	for(;;) {
		if (dirp->loc >= dirp->ip->di_size)
			return NULL;
D 8
		if ((lbn = dirp->loc / sblock.fs_bsize) == 0) {
E 8
I 8
		if ((lbn = lblkno(&sblock, dirp->loc)) == 0) {
E 8
			d = bmap(lbn);
			if(d == 0)
				return NULL;
			bread(fsbtodb(&sblock, d), dirp->dbuf,
			    dblksize(&sblock, dirp->ip, lbn));
		}
		dp = (struct direct *)
D 8
		    (dirp->dbuf + dirp->loc % sblock.fs_bsize);
E 8
I 8
		    (dirp->dbuf + blkoff(&sblock, dirp->loc));
E 8
		dirp->loc += dp->d_reclen;
		if (dp->d_ino == 0)
			continue;
		return (dp);
	}
E 7
}

bread(bno, buf, cnt)
daddr_t bno;
char *buf;
{
	register i;

D 4
	lseek(fi, bno*FSIZE, 0);
E 4
I 4
D 14
	lseek(fi, bno * DEV_BSIZE, 0);
E 14
I 14
	lseek(fi, bno * dev_bsize, 0);
E 14
E 4
	if (read(fi, buf, cnt) != cnt) {
		printf("read error %d\n", bno);
D 4
		for(i=0; i<BSIZE; i++)
E 4
I 4
		for(i=0; i < cnt; i++)
E 4
			buf[i] = 0;
	}
}

daddr_t
bmap(i)
{
D 4
	daddr_t ibuf[NINDIR];
E 4
I 4
	daddr_t ibuf[MAXNINDIR];
E 4

	if(i < NDADDR)
D 2
		return(iaddr[i]);
E 2
I 2
		return(gip->di_db[i]);
E 2
	i -= NDADDR;
D 4
	if(i > NINDIR) {
E 4
I 4
	if(i > NINDIR(&sblock)) {
E 4
		printf("%u - huge directory\n", ino);
		return((daddr_t)0);
	}
D 2
	bread(iaddr[NDADDR], (char *)ibuf, sizeof(ibuf));
E 2
I 2
D 3
	bread(gip->di_ib[i], (char *)ibuf, sizeof(ibuf));
E 3
I 3
D 4
	bread(gip->di_ib[0], (char *)ibuf, sizeof(ibuf));
E 4
I 4
	bread(fsbtodb(&sblock, gip->di_ib[0]), (char *)ibuf, sizeof(ibuf));
E 4
E 3
E 2
	return(ibuf[i]);
}
E 1
