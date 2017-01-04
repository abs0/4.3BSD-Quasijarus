h43397
s 00026/00365/00512
d D 5.4 88/05/02 16:35:10 mckusick 30 29
c convert to understand dynamic file systems;
c delete -s option (superceded by fsck at last)
e
s 00006/00006/00871
d D 5.3 87/10/22 10:35:02 bostic 29 28
c ANSI C; sprintf now returns an int.
e
s 00006/00004/00871
d D 5.2 87/02/23 17:39:52 mckusick 28 27
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00010/00001/00865
d D 5.1 85/05/28 14:23:29 dist 27 26
c add copyright
e
s 00035/00017/00831
d D 2.4 82/11/18 20:06:32 mckusick 26 25
c fixups to -b option
e
s 00051/00005/00797
d D 2.3 82/09/10 00:35:40 mckusick 25 23
c add ifdef's for STANDALONE; clear out unused bits in block map
e
s 00051/00005/00797
d R 2.3 82/09/10 00:28:19 mckusick 24 23
c ifdef's for STANDALONE; clear out unused bits in block maps
e
s 00040/00034/00762
d D 2.2 82/04/11 17:22:14 mckusick 23 22
c float the super block, reclaim redundant boot block space
e
s 00113/00000/00683
d D 2.1 82/04/08 14:45:05 mckusick 22 21
c merge into the new kernel
e
s 00001/00001/00682
d D 1.21 82/03/23 12:55:48 mckusick 21 20
c compress frag tables
e
s 00010/00007/00673
d D 1.20 82/03/23 01:03:39 mckusick 20 19
c add symbolic links
e
s 00003/00001/00677
d D 1.19 82/02/25 14:48:38 mckusic 19 18
c use speed-up macros in fs.h
e
s 00003/00004/00675
d D 1.18 82/02/23 19:04:34 mckusic 18 17
c always allocate inodes 0 and 1 when reconstructing cyl group 0
e
s 00004/00002/00675
d D 1.17 82/01/15 13:47:40 mckusic 17 16
c fix bug in initializing cg_free in makecg()
e
s 00003/00002/00674
d D 1.16 82/01/13 18:33:54 mckusic 16 15
c zero out cg_free for unused portion of last cylinder group
e
s 00013/00013/00663
d D 1.15 82/01/12 22:19:51 mckusic 15 14
c change all macros taking "fs" to have it as their first argument
e
s 00004/00001/00672
d D 1.14 82/01/12 19:34:47 mckusic 14 13
c add cg_ctot to summarize cg_b
e
s 00002/00003/00671
d D 1.13 82/01/10 18:25:00 mckusic 13 12
c fix rotational layout code to work with disks with nsect % bsize != 0
e
s 00003/00003/00671
d D 1.12 82/01/06 23:34:34 mckusic 12 11
c incorporate fs.h -r1.10, and param.h -r1.8 reorganization
e
s 00005/00000/00669
d D 1.11 82/01/06 21:12:32 mckusic 11 10
c skip over inode 1 when checking
e
s 00167/00092/00502
d D 1.10 82/01/05 01:33:39 mckusic 10 9
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00198/00008/00396
d D 1.9 81/11/27 16:39:26 mckusic 9 8
c put in makecg() from fsck to implement the -s flag (correctly)
e
s 00001/00008/00403
d D 1.8 81/11/07 19:59:52 mckusic 8 7
c edit to incorperate -r1.6 reorganization of fs.h
e
s 00006/00127/00405
d D 1.7 81/11/07 14:23:54 mckusic 7 6
c excise -s option which did not work
e
s 00010/00008/00522
d D 1.6 81/10/29 00:37:11 mckusic 6 5
c put in optimal rotational block allocation
e
s 00060/00040/00470
d D 1.5 81/09/22 17:46:51 mckusic 5 4
c allow files and directories to have FRAGS as their final block
e
s 00068/00086/00442
d D 1.4 81/09/19 16:25:55 mckusic 4 3
c initial BSIZE only file system
e
s 00000/00004/00528
d D 1.3 81/08/28 22:47:06 mckusic 3 2
c move bit op macros to param.h
e
s 00006/00009/00526
d D 1.2 81/08/28 21:22:27 mckusic 2 1
c put in new inode structure
e
s 00535/00000/00000
d D 1.1 81/08/26 23:47:50 mckusick 1 0
c date and time created 81/08/26 23:47:50 by mckusick
e
u
U
t
T
I 7
D 8
/*###1 [lint] static variable sccsid unused%%%*/
/*###1 [lint] sccsid defined( icheck.c(1) ), but never used%%%*/
E 8
E 7
I 1
D 27
static	char *sccsid = "%W% (Berkeley) %G%";
E 27
I 27
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint

E 27
I 4
D 30

E 30
E 4
/*
 * icheck
 */
#define	NB	500
D 9
#define	BITS	8
E 9
#define	MAXFN	500
I 10
D 12
#define MAXNINDIR (MAXBSIZE / sizeof (daddr_t))
E 12
I 12
#define	MAXNINDIR	(MAXBSIZE / sizeof (daddr_t))
E 12
E 10

#ifndef STANDALONE
#include <stdio.h>
#endif
I 22
D 30
#ifndef SIMFS
E 30
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
D 30
#else
E 22
#include "../h/param.h"
#include "../h/inode.h"
D 2
#include "../h/ino.h"
E 2
#include "../h/fs.h"
I 22
#endif
E 30
E 22

D 3
#define	setbit(a, i)	((a)[(i)/NBBY] |= 1<<((i)%NBBY))
#define	clrbit(a, i)	((a)[(i)/NBBY] &= ~(1<<((i)%NBBY)))
#define	isset(a,i)	((a)[(i)/NBBY] & (1<<((i)%NBBY)))

E 3
union {
	struct	fs sb;
D 10
	char pad[BSIZE];
E 10
I 10
D 30
	char pad[MAXBSIZE];
E 30
I 30
	char pad[SBSIZE];
E 30
E 10
} sbun;
#define	sblock sbun.sb

union {
	struct	cg cg;
D 10
	char pad[BSIZE];
E 10
I 10
	char pad[MAXBSIZE];
E 10
} cgun;
#define	cgrp cgun.cg

D 30
struct	dinode	itab[MAXIPG];
E 30
I 30
struct dinode itab[MAXBSIZE / sizeof(struct dinode)];

E 30
D 2
daddr_t	iaddr[NDADDR+NIADDR];
E 2
daddr_t	blist[NB];
I 26
daddr_t	fsblist[NB];
E 26
char	*bmap;

D 7
int	sflg;
E 7
int	mflg;
I 9
D 30
int	sflg;
E 30
E 9
int	dflg;
int	fi;
ino_t	ino;
int	cginit;

ino_t	nrfile;
ino_t	ndfile;
ino_t	nbfile;
ino_t	ncfile;
D 20
ino_t	nmcfile;
E 20
I 20
ino_t	nlfile;
I 30
ino_t	nsfile;
E 30
E 20

daddr_t	nblock;
daddr_t	nfrag;
D 5
long	szfrag;
E 5
daddr_t	nindir;
D 5
long	szindir;
E 5
daddr_t	niindir;

daddr_t	nffree;
D 5
long	szffree;
E 5
daddr_t	nbfree;

daddr_t	ndup;

int	nerror;
I 28
long	dev_bsize = 1;
E 28

I 9
D 30
extern int inside[], around[];
D 10
extern unsigned char fragtbl[];
E 10
I 10
extern unsigned char *fragtbl[];
E 10

E 30
E 9
long	atol();
D 9
daddr_t	alloc();
E 9
#ifndef STANDALONE
char	*malloc();
I 9
char	*calloc();
E 9
#endif

main(argc, argv)
D 9
char *argv[];
E 9
I 9
	int argc;
	char *argv[];
E 9
{
	register i;
	long n;

	blist[0] = -1;
#ifndef STANDALONE
	while (--argc) {
		argv++;
		if (**argv=='-')
		switch ((*argv)[1]) {
		case 'd':
			dflg++;
			continue;

		case 'm':
			mflg++;
			continue;

I 9
D 30
		case 's':
			sflg++;
			continue;

E 30
E 9
D 7
		case 's':
			sflg++;
			continue;

E 7
		case 'b':
			for(i=0; i<NB; i++) {
				n = atol(argv[1]);
				if(n == 0)
					break;
				blist[i] = n;
				argv++;
				argc--;
			}
			blist[i] = -1;
			continue;

		default:
			printf("Bad flag\n");
		}
		check(*argv);
	}
#else
	{
		static char fname[128];

		printf("File: ");
		gets(fname);
		check(fname);
	}
#endif
	return(nerror);
}

check(file)
D 9
char *file;
E 9
I 9
	char *file;
E 9
{
	register i, j, c;
	daddr_t d, cgd, cbase, b;
	long n;
I 26
	char buf[BUFSIZ];
E 26

D 7
	fi = open(file, sflg?2:0);
E 7
I 7
D 9
	fi = open(file, 0);
E 9
I 9
D 30
	fi = open(file, sflg ? 2 : 0);
E 30
I 30
	fi = open(file, 0);
E 30
E 9
E 7
	if (fi < 0) {
D 9
		printf("cannot open %s\n", file);
E 9
I 9
		perror(file);
E 9
		nerror |= 04;
		return;
	}
	printf("%s:\n", file);
	nrfile = 0;
	ndfile = 0;
	ncfile = 0;
	nbfile = 0;
D 20
	nmcfile = 0;
E 20
I 20
	nlfile = 0;
I 30
	nsfile = 0;
E 30
E 20

	nblock = 0;
	nfrag = 0;
D 5
	szfrag = 0;
E 5
	nindir = 0;
D 5
	szindir = 0;
E 5
	niindir = 0;

	ndup = 0;
#ifndef STANDALONE
	sync();
#endif
D 10
	bread(SBLOCK, (char *)&sblock, BSIZE);
	if (sblock.fs_magic != FS_MAGIC) {
		printf("%s: bad magic number\n", file);
		nerror |= 04;
E 10
I 10
	getsb(&sblock, file);
	if (nerror)
E 10
		return;
I 26
	for (n=0; blist[n] != -1; n++)
		fsblist[n] = dbtofsb(&sblock, blist[n]);
E 26
D 10
	}
D 6
	sblock.fs_cs =
	    (struct csum *)calloc(howmany(cssize(&sblock), BSIZE), BSIZE);
	lseek(fi, csaddr(&sblock)*FSIZE, 0);
	read(fi, (char *)sblock.fs_cs, cssize(&sblock));
E 6
I 6
	for (n = 0; n < howmany(cssize(&sblock), BSIZE); n++) {
I 7
D 8
/*###148 [lint] calloc value declared inconsistently llib-lc(58) :: icheck.c(148)%%%*/
/*###148 [lint] calloc value used inconsistently llib-lc(58) :: icheck.c(148)%%%*/
E 8
E 7
		sblock.fs_csp[n] = (struct csum *)calloc(1, BSIZE);
		bread(csaddr(&sblock) + (n * FRAG),
		      (char *)sblock.fs_csp[n], BSIZE);
	}
E 10
E 6
	ino = 0;
D 9
	n = (sblock.fs_size*FRAG + BITS-1) / BITS;
E 9
I 9
	n = roundup(howmany(sblock.fs_size, NBBY), sizeof(short));
E 9
#ifdef STANDALONE
	bmap = NULL;
#else
	bmap = malloc((unsigned)n);
#endif
	if (bmap==NULL) {
		printf("Not enough core; duplicates unchecked\n");
		dflg++;
I 9
D 30
		if (sflg) {
			printf("No Updates\n");
			sflg = 0;
		}
E 30
E 9
D 7
		sflg = 0;
E 7
	}
	ino = 0;
	cginit = 1;
D 23
	if(!dflg) {
		for (i=0; i<(unsigned)n; i++)
E 23
I 23
	if (!dflg) {
		for (i = 0; i < (unsigned)n; i++)
E 23
			bmap[i] = 0;
D 23
		for (c=0; c < sblock.fs_ncg; c++) {
E 23
I 23
		for (c = 0; c < sblock.fs_ncg; c++) {
E 23
D 15
			cgd = cgtod(c, &sblock);
D 4
			for (d = cgbase(c, &sblock); d < cgd; d++)
				chk(d, "badcg");
E 4
I 4
D 10
			for (d = cgbase(c, &sblock); d < cgd; d += FRAG)
D 5
				chk(d, "badcg", 0);
E 5
I 5
				chk(d, "badcg", BSIZE);
E 10
I 10
			for (d = cgbase(c, &sblock); d < cgd; d += sblock.fs_frag)
E 15
I 15
			cgd = cgtod(&sblock, c);
D 23
			for (d = cgbase(&sblock, c); d < cgd; d += sblock.fs_frag)
E 23
I 23
			if (c == 0)
				d = cgbase(&sblock, c);
			else
				d = cgsblock(&sblock, c);
I 26
D 29
			sprintf(buf, "spare super block %d", c);
E 29
I 29
			(void)sprintf(buf, "spare super block %d", c);
E 29
E 26
			for (; d < cgd; d += sblock.fs_frag)
E 23
E 15
D 26
				chk(d, "badcg", sblock.fs_bsize);
E 26
I 26
				chk(d, buf, sblock.fs_bsize);
E 26
E 10
E 5
E 4
D 15
			d = cgimin(c, &sblock);
E 15
I 15
			d = cgimin(&sblock, c);
I 26
D 29
			sprintf(buf, "cylinder group %d", c);
E 29
I 29
			(void)sprintf(buf, "cylinder group %d", c);
E 29
E 26
E 15
			while (cgd < d) {
D 4
				chk(cgd, "cg");
				cgd++;
E 4
I 4
D 5
				chk(cgd, "cg", 0);
E 5
I 5
D 10
				chk(cgd, "cg", BSIZE);
E 5
				cgd += FRAG;
E 10
I 10
D 26
				chk(cgd, "cg", sblock.fs_bsize);
E 26
I 26
				chk(cgd, buf, sblock.fs_bsize);
E 26
				cgd += sblock.fs_frag;
E 10
E 4
			}
D 15
			d = cgdmin(c, &sblock);
E 15
I 15
			d = cgdmin(&sblock, c);
E 15
D 4
			for (; cgd < d; cgd++)
				chk(cgd, "inode");
E 4
I 4
D 10
			for (; cgd < d; cgd += FRAG)
D 5
				chk(cgd, "inode", 0);
E 5
I 5
				chk(cgd, "inode", BSIZE);
E 10
I 10
D 26
			for (; cgd < d; cgd += sblock.fs_frag)
				chk(cgd, "inode", sblock.fs_bsize);
E 26
I 26
			i = INOPB(&sblock);
			for (; cgd < d; cgd += sblock.fs_frag) {
D 29
				sprintf(buf, "inodes %d-%d", ino, ino + i);
E 29
I 29
				(void)sprintf(buf, "inodes %d-%d", ino, ino + i);
E 29
				chk(cgd, buf, sblock.fs_bsize);
				ino += i;
			}
E 26
E 10
E 5
E 4
			if (c == 0) {
D 4
				d += howmany(cssize(&sblock), BSIZE) * FRAG;
				for (; cgd < d; cgd++)
					chk(cgd, "csum");
E 4
I 4
D 10
				d += howmany(cssize(&sblock), FSIZE);
				for (; cgd < d; cgd += FRAG)
D 5
					chk(cgd, "csum", 0);
E 5
I 5
					chk(cgd, "csum", BSIZE);
E 10
I 10
D 23
				d += howmany(sblock.fs_cssize, sblock.fs_bsize)
				    * sblock.fs_frag;
				for (; cgd < d; cgd += sblock.fs_frag)
					chk(cgd, "csum", sblock.fs_bsize);
E 23
I 23
				d += howmany(sblock.fs_cssize, sblock.fs_fsize);
				for (; cgd < d; cgd++)
					chk(cgd, "csum", sblock.fs_fsize);
E 23
E 10
E 5
E 4
			}
		}
	}
I 26
	ino = 0;
E 26
	cginit = 0;
	for (c = 0; c < sblock.fs_ncg; c++) {
D 10
		bread(cgimin(c,&sblock), (char *)itab,
E 10
I 10
D 15
		bread(fsbtodb(&sblock, cgimin(c,&sblock)), (char *)itab,
E 15
I 15
D 30
		bread(fsbtodb(&sblock, cgimin(&sblock, c)), (char *)itab,
E 15
E 10
		    sblock.fs_ipg * sizeof (struct dinode));
		for (j=0; j < sblock.fs_ipg; j++) {
			pass1(&itab[j]);
			ino++;
E 30
I 30
		for (i = 0;
		     i < sblock.fs_ipg / INOPF(&sblock);
		     i += sblock.fs_frag) {
			bread(fsbtodb(&sblock, cgimin(&sblock, c) + i),
			    (char *)itab, sblock.fs_bsize);
			for (j = 0; j < INOPB(&sblock); j++) {
				pass1(&itab[j]);
				ino++;
			}
E 30
		}
	}
	ino = 0;
#ifndef STANDALONE
	sync();
#endif
D 10
	bread(SBLOCK, (char *)&sblock, sizeof(sblock));
E 10
I 9
D 30
	if (sflg) {
		makecg();
		close(fi);
#ifndef STANDALONE
		if (bmap)
			free(bmap);
#endif
		return;
	}
E 30
E 9
D 7
	if (sflg) {
		makecg();
		close(fi);
#ifndef STANDALONE
		if (bmap)
			free(bmap);
#endif
		return;
	}
E 7
	nffree = 0;
D 5
	szffree = 0;
E 5
	nbfree = 0;
	for (c = 0; c < sblock.fs_ncg; c++) {
D 15
		cbase = cgbase(c,&sblock);
D 10
		bread(cgtod(c,&sblock), (char *)&cgrp, sblock.fs_cgsize);
		for (b = 0; b < sblock.fs_fpg; b += FRAG) {
			if (isblock(cgrp.cg_free, b / FRAG)) {
E 10
I 10
		bread(fsbtodb(&sblock, cgtod(c,&sblock)), (char *)&cgrp,
E 15
I 15
		cbase = cgbase(&sblock, c);
		bread(fsbtodb(&sblock, cgtod(&sblock, c)), (char *)&cgrp,
E 15
			sblock.fs_cgsize);
I 23
D 30
		if (cgrp.cg_magic != CG_MAGIC)
E 30
I 30
		if (!cg_chkmagic(&cgrp))
E 30
			printf("cg %d: bad magic number\n", c);
E 23
		for (b = 0; b < sblock.fs_fpg; b += sblock.fs_frag) {
D 30
			if (isblock(&sblock, cgrp.cg_free,
E 30
I 30
			if (isblock(&sblock, cg_blksfree(&cgrp),
E 30
			    b / sblock.fs_frag)) {
E 10
				nbfree++;
D 4
				for (d = 0; d < FRAG; d++)
					chk(cbase+b+d, "block");
E 4
I 4
D 5
				chk(cbase+b, "block", 0);
E 5
I 5
D 10
				chk(cbase+b, "block", BSIZE);
E 10
I 10
D 26
				chk(cbase+b, "block", sblock.fs_bsize);
E 26
I 26
				chk(cbase+b, "free block", sblock.fs_bsize);
E 26
E 10
E 5
E 4
			} else {
D 10
				for (d = 0; d < FRAG; d++)
E 10
I 10
				for (d = 0; d < sblock.fs_frag; d++)
E 10
D 30
					if (isset(cgrp.cg_free, b+d)) {
E 30
I 30
					if (isset(cg_blksfree(&cgrp), b+d)) {
E 30
D 4
						chk(cbase+b+d, "frag");
E 4
I 4
D 5
						chk(cbase+b+d, "frag", 1);
E 5
I 5
D 10
						chk(cbase+b+d, "frag", FSIZE);
E 10
I 10
D 26
						chk(cbase+b+d, "frag", sblock.fs_fsize);
E 26
I 26
						chk(cbase+b+d, "free frag", sblock.fs_fsize);
E 26
E 10
E 5
E 4
						nffree++;
D 5
						szffree++;
E 5
					}
			}
		}
	}
	close(fi);
#ifndef STANDALONE
	if (bmap)
		free(bmap);
#endif

D 20
	i = nrfile + ndfile + ncfile + nbfile + nmcfile;
E 20
I 20
D 30
	i = nrfile + ndfile + ncfile + nbfile + nlfile;
E 30
I 30
	i = nrfile + ndfile + ncfile + nbfile + nlfile + nsfile;
E 30
E 20
#ifndef STANDALONE
D 20
	printf("files %6u (r=%u,d=%u,b=%u,c=%u,mc=%u)\n",
		i, nrfile, ndfile, nbfile, ncfile, nmcfile);
E 20
I 20
D 30
	printf("files %6u (r=%u,d=%u,b=%u,c=%u,sl=%u)\n",
		i, nrfile, ndfile, nbfile, ncfile, nlfile);
E 30
I 30
	printf("files %6u (r=%u,d=%u,b=%u,c=%u,sl=%u,sock=%u)\n",
		i, nrfile, ndfile, nbfile, ncfile, nlfile, nsfile);
E 30
E 20
#else
D 20
	printf("files %u (r=%u,d=%u,b=%u,c=%u,mc=%u)\n",
		i, nrfile, ndfile, nbfile, ncfile, nmcfile);
E 20
I 20
D 30
	printf("files %u (r=%u,d=%u,b=%u,c=%u,sl=%u)\n",
		i, nrfile, ndfile, nbfile, ncfile, nlfile);
E 30
I 30
	printf("files %u (r=%u,d=%u,b=%u,c=%u,sl=%u,sock=%u)\n",
		i, nrfile, ndfile, nbfile, ncfile, nlfile, nsfile);
E 30
E 20
#endif
D 4
	n = (nblock + niindir) * FRAG + szfrag + szindir;
E 4
I 4
D 5
	n = (nblock + nindir + niindir) * FRAG + szfrag + szindir;
E 5
I 5
D 10
	n = (nblock + nindir + niindir) * FRAG + nfrag;
E 10
I 10
	n = (nblock + nindir + niindir) * sblock.fs_frag + nfrag;
E 10
E 5
E 4
#ifdef STANDALONE
	printf("used %ld (i=%ld,ii=%ld,b=%ld,f=%ld)\n",
		n, nindir, niindir, nblock, nfrag);
D 5
	printf("free %ld (b=%ld,f=%ld)\n", szffree + FRAG * nbfree,
E 5
I 5
D 10
	printf("free %ld (b=%ld,f=%ld)\n", nffree + FRAG * nbfree,
E 10
I 10
	printf("free %ld (b=%ld,f=%ld)\n", nffree + sblock.fs_frag * nbfree,
E 10
E 5
	    nbfree, nffree);
#else
	printf("used %7ld (i=%ld,ii=%ld,b=%ld,f=%ld)\n",
		n, nindir, niindir, nblock, nfrag);
D 5
	printf("free %7ld (b=%ld,f=%ld)\n", szffree + FRAG * nbfree,
E 5
I 5
D 10
	printf("free %7ld (b=%ld,f=%ld)\n", nffree + FRAG * nbfree,
E 10
I 10
	printf("free %7ld (b=%ld,f=%ld)\n", nffree + sblock.fs_frag * nbfree,
E 10
E 5
	    nbfree, nffree);
#endif
	if(!dflg) {
		n = 0;
D 4
		for(d=0; d<sblock.fs_size; d++)
			if(!duped(d)) {
E 4
I 4
		for (d = 0; d < sblock.fs_size; d++)
D 5
			if(!duped(d, 1)) {
E 5
I 5
D 10
			if(!duped(d, FSIZE)) {
E 10
I 10
			if(!duped(d, sblock.fs_fsize)) {
E 10
E 5
E 4
				if(mflg)
					printf("%ld missing\n", d);
				n++;
			}
		printf("missing%5ld\n", n);
	}
}

pass1(ip)
D 4
register struct dinode *ip;
E 4
I 4
	register struct dinode *ip;
E 4
{
D 4
	daddr_t ind1[NINDIR];
	daddr_t ind2[NINDIR];
	register i, j;
	int k, l, sz, ni, nib, ndb;
E 4
I 4
D 5
	fsbaddr_t ind1[NINDIR];
	fsbaddr_t ind2[NINDIR];
	fsbaddr_t db, ib;
	register i, j, k;
E 5
I 5
D 10
	daddr_t ind1[NINDIR];
	daddr_t ind2[NINDIR];
E 10
I 10
	daddr_t ind1[MAXNINDIR];
	daddr_t ind2[MAXNINDIR];
E 10
	daddr_t db, ib;
	register int i, j, k, siz;
I 26
	int lbn;
	char buf[BUFSIZ];
E 26
E 5
E 4

	i = ip->di_mode & IFMT;
D 8
	if(i == 0) {
		sblock.fs_nifree++;
E 8
I 8
	if(i == 0)
E 8
		return;
D 8
	}
E 8
	switch (i) {
	case IFCHR:
		ncfile++;
		return;
	case IFBLK:
		nbfile++;
		return;
	case IFDIR:
		ndfile++;
		break;
	case IFREG:
		nrfile++;
I 20
		break;
I 30
	case IFSOCK:
		nsfile++;
		break;
E 30
	case IFLNK:
		nlfile++;
E 20
		break;
	default:
		printf("bad mode %u\n", ino);
		return;
	}
D 2
	l3tol(iaddr, ip->di_addr, NDADDR+NIADDR);
E 2
D 4
	ndb = howmany(ip->di_size, BSIZE)-1;
	for(i=0; i<NDADDR; i++) {
D 2
		if(iaddr[i] == 0)
E 2
I 2
		if(ip->di_db[i] == 0)
E 4
I 4
	for (i = 0; i < NDADDR; i++) {
		db = ip->di_db[i];
		if (db == 0)
E 4
E 2
			continue;
D 4
		if (i==ndb && (ip->di_size&BMASK)) {
			sz = howmany(ip->di_size - i * BSIZE, FSIZE);
			for (l = 0; l < sz; l++)
D 2
				chk(iaddr[i]+l, "data (frag)");
E 2
I 2
				chk(ip->di_db[i]+l, "data (frag)");
E 2
			szfrag += sz;
			nfrag++;
		} else {
			for (l = 0; l < FRAG; l++)
D 2
				chk(iaddr[i]+l, "data (block)");
E 2
I 2
				chk(ip->di_db[i]+l, "data (block)");
E 2
			nblock++;
		}
E 4
I 4
D 5
		chk(fsbtodb(db), "data (block)", isfrag(db));
		nblock++;
E 5
I 5
D 10
		siz = dblksize(ip, i);
E 10
I 10
		siz = dblksize(&sblock, ip, i);
E 10
D 26
		chk(db, "data (block)", siz);
E 26
I 26
D 29
		sprintf(buf, "logical data block %d", i);
E 29
I 29
		(void)sprintf(buf, "logical data block %d", i);
E 29
		chk(db, buf, siz);
E 26
D 10
		if (siz == BSIZE)
E 10
I 10
		if (siz == sblock.fs_bsize)
E 10
			nblock++;
		else
D 10
			nfrag += howmany(siz, FSIZE);
E 10
I 10
			nfrag += howmany(siz, sblock.fs_fsize);
E 10
E 5
E 4
	}
D 4
	for(i=NDADDR; i<NDADDR+NIADDR;i++) {
D 2
		if(iaddr[i] == 0)
E 2
I 2
		if(ip->di_ib[i] == 0)
E 4
I 4
	for(i = 0; i < NIADDR; i++) {
		ib = ip->di_ib[i];
D 26
		if(ib == 0)
E 26
I 26
		if (ib == 0)
E 26
E 4
E 2
			continue;
I 4
D 5
		if (chk(fsbtodb(ib), "1st indirect", 0))
E 5
I 5
D 10
		if (chk(ib, "1st indirect", BSIZE))
E 10
I 10
		if (chk(ib, "1st indirect", sblock.fs_bsize))
E 10
E 5
			continue;
D 5
		bread(fsbtodb(ib), (char *)ind1, BSIZE);
E 5
I 5
D 10
		bread(ib, (char *)ind1, BSIZE);
E 10
I 10
		bread(fsbtodb(&sblock, ib), (char *)ind1, sblock.fs_bsize);
E 10
E 5
E 4
		nindir++;
D 4
		if (i==NDADDR) {
			sz = howmany((ip->di_size-NDADDR*BSIZE),
			    (NINDIR/FRAG) * BSIZE);
			if (sz > FRAG)
				sz = FRAG;
		} else
			sz = FRAG;
		for (j = 0; j < FRAG; j++)
D 2
			if (chk(iaddr[i]+j, "1st indirect"))
E 2
I 2
			if (chk(ip->di_ib[i]+j, "1st indirect"))
E 4
I 4
D 10
		for (j = 0; j < NINDIR; j++) {
E 10
I 10
		for (j = 0; j < NINDIR(&sblock); j++) {
E 10
			ib = ind1[j];
			if (ib == 0)
E 4
E 2
				continue;
D 2
		bread(iaddr[i], (char *)ind1, sz*FSIZE);
E 2
I 2
D 4
		bread(ip->di_ib[i], (char *)ind1, sz*FSIZE);
E 2
		nib = sz * (NINDIR/FRAG);
		for(j=0; j<nib; j++) {
			if(ind1[j] == 0)
				continue;
			if(i == NDADDR) {
				for (l = 0; l < FRAG; l++)
					chk(ind1[j]+l, "data (large)");
E 4
I 4
			if (i == 0) {
D 5
				chk(fsbtodb(ib), "data (large)", isfrag(ib));
E 4
				nblock++;
E 5
I 5
D 10
				siz = dblksize(ip, NDADDR + j);
E 10
I 10
D 26
				siz = dblksize(&sblock, ip, NDADDR + j);
E 10
				chk(ib, "data (large)", siz);
E 26
I 26
				lbn = NDADDR + j;
				siz = dblksize(&sblock, ip, lbn);
D 29
				sprintf(buf, "logical data block %d", lbn);
E 29
I 29
				(void)sprintf(buf, "logical data block %d", lbn);
E 29
				chk(ib, buf, siz);
E 26
D 10
				if (siz == BSIZE)
E 10
I 10
				if (siz == sblock.fs_bsize)
E 10
					nblock++;
				else
D 10
					nfrag += howmany(siz, FSIZE);
E 10
I 10
					nfrag += howmany(siz, sblock.fs_fsize);
E 10
E 5
				continue;
			}
I 4
D 5
			if (chk(fsbtodb(ib), "2nd indirect", 0))
E 5
I 5
D 10
			if (chk(ib, "2nd indirect", BSIZE))
E 10
I 10
			if (chk(ib, "2nd indirect", sblock.fs_bsize))
E 10
E 5
				continue;
D 5
			bread(fsbtodb(ib), (char *)ind2, BSIZE);
E 5
I 5
D 10
			bread(ib, (char *)ind2, BSIZE);
E 10
I 10
			bread(fsbtodb(&sblock, ib), (char *)ind2,
				sblock.fs_bsize);
E 10
E 5
E 4
			niindir++;
D 4
			for (l = 0; l < FRAG; l++)
				if(chk(ind1[j], "2nd indirect"))
					goto skip;
			bread(ind1[j], (char *)ind2, BSIZE);
			for(k=0; k<NINDIR; k++) {
				if(ind2[k] == 0)
E 4
I 4
D 10
			for (k = 0; k < NINDIR; k++) {
E 10
I 10
			for (k = 0; k < NINDIR(&sblock); k++) {
E 10
				ib = ind2[k];
				if (ib == 0)
E 4
					continue;
D 4
				for (l = 0; l < FRAG; l++)
					chk(ind1[j]+l, "data (huge)");
E 4
I 4
D 5
				chk(fsbtodb(ib), "data (huge)", isfrag(ib));
E 4
				nblock++;
E 5
I 5
D 10
				siz = dblksize(ip,
				    NDADDR + NINDIR * (i + j) + k);
E 10
I 10
D 26
				siz = dblksize(&sblock, ip,
				    NDADDR + NINDIR(&sblock) * (i + j) + k);
E 10
				chk(ib, "data (huge)", siz);
E 26
I 26
				lbn = NDADDR + NINDIR(&sblock) * (i + j) + k;
				siz = dblksize(&sblock, ip, lbn);
D 29
				sprintf(buf, "logical data block %d", lbn);
E 29
I 29
				(void)sprintf(buf, "logical data block %d", lbn);
E 29
				chk(ib, buf, siz);
E 26
D 10
				if (siz == BSIZE)
E 10
I 10
				if (siz == sblock.fs_bsize)
E 10
					nblock++;
				else
D 10
					nfrag += howmany(siz, FSIZE);
E 10
I 10
					nfrag += howmany(siz, sblock.fs_fsize);
E 10
E 5
D 4
				continue;
E 4
			}
D 4
skip:
			;
E 4
		}
	}
}

D 4
chk(bno, s)
daddr_t bno;
char *s;
E 4
I 4
D 5
chk(bno, s, fragflg)
E 5
I 5
chk(bno, s, size)
E 5
	daddr_t bno;
	char *s;
D 5
	int fragflg;
E 5
I 5
	int size;
E 5
E 4
{
	register n, cg;
I 19
	int frags;
E 19

D 15
	cg = dtog(bno, &sblock);
E 15
I 15
	cg = dtog(&sblock, bno);
E 15
D 5
	if (cginit==0 && bno<cgdmin(cg,&sblock) || bno>=FRAG*sblock.fs_size) {
E 5
I 5
D 23
	if (cginit==0 &&
D 10
	    bno<cgdmin(cg,&sblock) || bno >= FRAG * sblock.fs_size) {
E 10
I 10
D 15
	    bno<cgdmin(cg,&sblock) || bno >= sblock.fs_frag * sblock.fs_size) {
E 15
I 15
	    bno<cgdmin(&sblock, cg) || bno >= sblock.fs_frag * sblock.fs_size) {
E 23
I 23
	if (cginit == 0 && bno >= sblock.fs_frag * sblock.fs_size) {
E 23
E 15
E 10
E 5
		printf("%ld bad; inode=%u, class=%s\n", bno, ino, s);
		return(1);
	}
D 4
	if (duped(bno)) {
E 4
I 4
D 5
	if (duped(bno, fragflg)) {
E 4
		printf("%ld dup; inode=%u, class=%s\n", bno, ino, s);
		ndup++;
E 5
I 5
D 10
	if (size == BSIZE) {
E 10
I 10
D 26
	if (size == sblock.fs_bsize) {
E 26
I 26
	frags = numfrags(&sblock, size);
	if (frags == sblock.fs_frag) {
E 26
E 10
		if (duped(bno, size)) {
			printf("%ld dup block; inode=%u, class=%s\n",
			    bno, ino, s);
D 10
			ndup += FRAG;
E 10
I 10
			ndup += sblock.fs_frag;
E 10
		}
	} else {
D 10
		for (n = 0; n < size / FSIZE; n++) {
			if (duped(bno + n, FSIZE)) {
E 10
I 10
D 19
		for (n = 0; n < size / sblock.fs_fsize; n++) {
E 19
I 19
D 26
		frags = numfrags(&sblock, size);
E 26
		for (n = 0; n < frags; n++) {
E 19
			if (duped(bno + n, sblock.fs_fsize)) {
E 10
				printf("%ld dup frag; inode=%u, class=%s\n",
				    bno, ino, s);
				ndup++;
			}
		}
E 5
	}
	for (n=0; blist[n] != -1; n++)
D 26
		if (bno == blist[n])
			printf("%ld arg; inode=%u, class=%s\n", bno, ino, s);
E 26
I 26
		if (fsblist[n] >= bno && fsblist[n] < bno + frags)
			printf("%ld arg; frag %d of %d, inode=%u, class=%s\n",
				blist[n], fsblist[n] - bno, frags, ino, s);
E 26
	return(0);
}

D 4
duped(bno)
daddr_t bno;
E 4
I 4
D 5
duped(bno, fragflg)
E 5
I 5
duped(bno, size)
E 5
	daddr_t bno;
D 5
	int fragflg;
E 5
I 5
	int size;
E 5
E 4
{
D 4
	daddr_t d;
	register m, n;

E 4
	if(dflg)
		return(0);
D 4
	m = 1 << (bno%BITS);
	n = (bno/BITS);
	if(bmap[n] & m)
		return(1);
	bmap[n] |= m;
E 4
I 4
D 5
	if (fragflg) {
E 5
I 5
D 10
	if (size != FSIZE && size != BSIZE)
E 10
I 10
	if (size != sblock.fs_fsize && size != sblock.fs_bsize)
E 10
		printf("bad size %d to duped\n", size);
D 10
	if (size == FSIZE) {
E 10
I 10
	if (size == sblock.fs_fsize) {
E 10
E 5
		if (isset(bmap, bno))
			return(1);
		setbit(bmap, bno);
		return (0);
	}
D 10
	if (bno % FRAG != 0)
E 10
I 10
	if (bno % sblock.fs_frag != 0)
E 10
		printf("bad bno %d to duped\n", bno);
D 10
	if (isblock(bmap, bno/FRAG))
E 10
I 10
	if (isblock(&sblock, bmap, bno/sblock.fs_frag))
E 10
		return (1);
D 10
	setblock(bmap, bno/FRAG);
E 10
I 10
	setblock(&sblock, bmap, bno/sblock.fs_frag);
E 10
E 4
	return(0);
}

I 9
D 30
makecg()
{
	int c, blk;
D 23
	daddr_t dbase, d, dmin, dmax;
E 23
I 23
	daddr_t dbase, d, dlower, dupper, dmax;
E 23
	long i, j, s;
	register struct csum *cs;
	register struct dinode *dp;

	sblock.fs_cstotal.cs_nbfree = 0;
	sblock.fs_cstotal.cs_nffree = 0;
	sblock.fs_cstotal.cs_nifree = 0;
	sblock.fs_cstotal.cs_ndir = 0;
D 10
	for (i = 0; i < howmany(cssize(&sblock), BSIZE); i++) {
		sblock.fs_csp[i] = (struct csum *)calloc(1, BSIZE);
		bread(csaddr(&sblock) + (i * FRAG),
		      (char *)sblock.fs_csp[i], BSIZE);
	}
E 10
	for (c = 0; c < sblock.fs_ncg; c++) {
D 15
		dbase = cgbase(c, &sblock);
E 15
I 15
		dbase = cgbase(&sblock, c);
E 15
		dmax = dbase + sblock.fs_fpg;
D 17
		if (dmax > sblock.fs_size)
D 16
			dmax = sblock.fs_size;
D 15
		dmin = cgdmin(c, &sblock) - dbase;
E 15
I 15
		dmin = cgdmin(&sblock, c) - dbase;
E 16
I 16
			for ( ; dmax > sblock.fs_size; dmax--)
E 17
I 17
		if (dmax > sblock.fs_size) {
			for ( ; dmax >= sblock.fs_size; dmax--)
E 17
				clrbit(cgrp.cg_free, dmax - dbase);
I 17
			dmax++;
		}
E 17
D 23
		dmin = sblock.fs_dblkno;
E 23
I 23
		dlower = cgsblock(&sblock, c) - dbase;
		dupper = cgdmin(&sblock, c) - dbase;
E 23
E 16
E 15
D 10
		cs = &sblock.fs_cs(c);
E 10
I 10
		cs = &sblock.fs_cs(&sblock, c);
E 10
		cgrp.cg_time = time(0);
		cgrp.cg_magic = CG_MAGIC;
		cgrp.cg_cgx = c;
D 25
		cgrp.cg_ncyl = sblock.fs_cpg;
E 25
I 25
		if (c == sblock.fs_ncg - 1)
			cgrp.cg_ncyl = sblock.fs_ncyl % sblock.fs_cpg;
		else
			cgrp.cg_ncyl = sblock.fs_cpg;
E 25
		cgrp.cg_niblk = sblock.fs_ipg;
		cgrp.cg_ndblk = dmax - dbase;
		cgrp.cg_cs.cs_ndir = 0;
		cgrp.cg_cs.cs_nffree = 0;
		cgrp.cg_cs.cs_nbfree = 0;
		cgrp.cg_cs.cs_nifree = 0;
D 23
		cgrp.cg_rotor = dmin;
		cgrp.cg_frotor = dmin;
E 23
I 23
		cgrp.cg_rotor = 0;
		cgrp.cg_frotor = 0;
E 23
		cgrp.cg_irotor = 0;
D 10
		for (i = 0; i < FRAG; i++)
E 10
I 10
		for (i = 0; i < sblock.fs_frag; i++)
E 10
			cgrp.cg_frsum[i] = 0;
D 10
		bread(cgimin(c, &sblock), (char *)itab,
E 10
I 10
D 15
		bread(fsbtodb(&sblock, cgimin(c, &sblock)), (char *)itab,
E 15
I 15
		bread(fsbtodb(&sblock, cgimin(&sblock, c)), (char *)itab,
E 15
E 10
		      sblock.fs_ipg * sizeof(struct dinode));
		for (i = 0; i < sblock.fs_ipg; i++) {
I 18
			cgrp.cg_cs.cs_nifree++;
			clrbit(cgrp.cg_iused, i);
E 18
			dp = &itab[i];
D 18
			if (dp == NULL)
				continue;
E 18
			if ((dp->di_mode & IFMT) != 0) {
				if ((dp->di_mode & IFMT) == IFDIR)
					cgrp.cg_cs.cs_ndir++;
I 18
				cgrp.cg_cs.cs_nifree--;
E 18
				setbit(cgrp.cg_iused, i);
				continue;
			}
D 18
			cgrp.cg_cs.cs_nifree++;
			clrbit(cgrp.cg_iused, i);
E 18
		}
		while (i < MAXIPG) {
			clrbit(cgrp.cg_iused, i);
			i++;
		}
I 11
		if (c == 0)
			for (i = 0; i < ROOTINO; i++) {
				setbit(cgrp.cg_iused, i);
				cgrp.cg_cs.cs_nifree--;
			}
E 11
D 14
		for (s = 0; s < MAXCPG; s++)
E 14
I 14
		for (s = 0; s < MAXCPG; s++) {
			cgrp.cg_btot[s] = 0;
E 14
			for (i = 0; i < NRPOS; i++)
				cgrp.cg_b[s][i] = 0;
I 14
		}
E 14
		if (c == 0) {
D 10
			dmin += howmany(cssize(&sblock), BSIZE) * FRAG;
E 10
I 10
D 23
			dmin += howmany(sblock.fs_cssize, sblock.fs_bsize) *
			    sblock.fs_frag;
E 23
I 23
			dupper += howmany(sblock.fs_cssize, sblock.fs_fsize);
E 23
E 10
		}
D 23
		for (d = 0; d < dmin; d++)
E 23
I 23
		for (d = dlower; d < dupper; d++)
E 23
			clrbit(cgrp.cg_free, d);
D 10
		for (; (d + FRAG) <= dmax - dbase; d += FRAG) {
E 10
I 10
D 23
		for (; (d + sblock.fs_frag) <= dmax - dbase; d += sblock.fs_frag) {
E 23
I 23
		for (d = 0; (d + sblock.fs_frag) <= dmax - dbase;
		    d += sblock.fs_frag) {
E 23
E 10
			j = 0;
D 10
			for (i = 0; i < FRAG; i++) {
E 10
I 10
			for (i = 0; i < sblock.fs_frag; i++) {
E 10
D 23
				if (!isset(bmap, dbase+d+i)) {
					setbit(cgrp.cg_free, d+i);
E 23
I 23
				if (!isset(bmap, dbase + d + i)) {
					setbit(cgrp.cg_free, d + i);
E 23
					j++;
				} else
					clrbit(cgrp.cg_free, d+i);
			}
D 10
			if (j == FRAG) {
E 10
I 10
			if (j == sblock.fs_frag) {
E 10
				cgrp.cg_cs.cs_nbfree++;
I 14
				cgrp.cg_btot[cbtocylno(&sblock, d)]++;
E 14
D 10
				s = d * NSPF;
E 10
I 10
D 13
				s = d * NSPF(&sblock);
E 10
				cgrp.cg_b[s/sblock.fs_spc]
				  [s%sblock.fs_nsect*NRPOS/sblock.fs_nsect]++;
E 13
I 13
				cgrp.cg_b[cbtocylno(&sblock, d)]
				    [cbtorpos(&sblock, d)]++;
E 13
			} else if (j > 0) {
				cgrp.cg_cs.cs_nffree += j;
D 23
				blk = ((cgrp.cg_free[d / NBBY] >> (d % NBBY)) &
D 10
				       (0xff >> (NBBY - FRAG)));
				fragacct(blk, cgrp.cg_frsum, 1);
E 10
I 10
				       (0xff >> (NBBY - sblock.fs_frag)));
E 23
I 23
				blk = blkmap(&sblock, cgrp.cg_free, d);
E 23
				fragacct(&sblock, blk, cgrp.cg_frsum, 1);
E 10
			}
		}
		for (j = d; d < dmax - dbase; d++) {
D 23
			if (!isset(bmap, dbase+d)) {
E 23
I 23
			if (!isset(bmap, dbase + d)) {
E 23
				setbit(cgrp.cg_free, d);
				cgrp.cg_cs.cs_nffree++;
			} else
				clrbit(cgrp.cg_free, d);
		}
I 25
		for (; d % sblock.fs_frag != 0; d++)
			clrbit(cgrp.cg_free, d);
E 25
		if (j != d) {
D 23
			blk = ((cgrp.cg_free[j / NBBY] >> (j % NBBY)) &
D 10
			       (0xff >> (NBBY - FRAG)));
			fragacct(blk, cgrp.cg_frsum, 1);
E 10
I 10
			       (0xff >> (NBBY - sblock.fs_frag)));
E 23
I 23
			blk = blkmap(&sblock, cgrp.cg_free, j);
E 23
			fragacct(&sblock, blk, cgrp.cg_frsum, 1);
E 10
		}
D 10
		for (; d < MAXBPG; d++)
E 10
I 10
D 25
		for (; d < MAXBPG(&sblock); d++)
E 10
			clrbit(cgrp.cg_free, d);
E 25
I 25
		for (d /= sblock.fs_frag; d < MAXBPG(&sblock); d ++)
			clrblock(&sblock, cgrp.cg_free, d);
E 25
		sblock.fs_cstotal.cs_nffree += cgrp.cg_cs.cs_nffree;
		sblock.fs_cstotal.cs_nbfree += cgrp.cg_cs.cs_nbfree;
		sblock.fs_cstotal.cs_nifree += cgrp.cg_cs.cs_nifree;
		sblock.fs_cstotal.cs_ndir += cgrp.cg_cs.cs_ndir;
		*cs = cgrp.cg_cs;
D 10
		bwrite(cgtod(c, &sblock), &cgrp, sblock.fs_cgsize);
E 10
I 10
D 15
		bwrite(fsbtodb(&sblock, cgtod(c, &sblock)), &cgrp,
E 15
I 15
		bwrite(fsbtodb(&sblock, cgtod(&sblock, c)), &cgrp,
E 15
			sblock.fs_cgsize);
E 10
	}
D 10
	for (i = 0; i < howmany(cssize(&sblock), BSIZE); i++) {
		bwrite(csaddr(&sblock) + (i * FRAG),
		       (char *)sblock.fs_csp[i], BSIZE);
E 10
I 10
D 23
	for (i = 0; i < howmany(sblock.fs_cssize, sblock.fs_bsize); i++) {
		bwrite(fsbtodb(&sblock,
		    sblock.fs_csaddr + (i * sblock.fs_frag)),
		    (char *)sblock.fs_csp[i], sblock.fs_bsize);
E 23
I 23
	for (i = 0, j = 0; i < sblock.fs_cssize; i += sblock.fs_bsize, j++) {
		bwrite(fsbtodb(&sblock, sblock.fs_csaddr + j * sblock.fs_frag),
		    (char *)sblock.fs_csp[j],
		    sblock.fs_cssize - i < sblock.fs_bsize ?
		    sblock.fs_cssize - i : sblock.fs_bsize);
E 23
E 10
	}
	sblock.fs_ronly = 0;
	sblock.fs_fmod = 0;
D 10
	bwrite(SBLOCK, (char *)&sblock, sizeof(sblock));
E 10
I 10
D 12
	bwrite(SBLOCK, (char *)&sblock, MAXBSIZE);
E 12
I 12
D 28
	bwrite(SBLOCK, (char *)&sblock, SBSIZE);
E 28
I 28
	bwrite(SBOFF / dev_bsize, (char *)&sblock, SBSIZE);
E 28
E 12
E 10
}

/*
 * update the frsum fields to reflect addition or deletion 
 * of some frags
 */
D 10
fragacct(fragmap, fraglist, cnt)
E 10
I 10
fragacct(fs, fragmap, fraglist, cnt)
	struct fs *fs;
E 10
	int fragmap;
	long fraglist[];
	int cnt;
{
	int inblk;
	register int field, subfield;
	register int siz, pos;

D 10
	inblk = (int)(fragtbl[fragmap] << 1);
E 10
I 10
	inblk = (int)(fragtbl[fs->fs_frag][fragmap] << 1);
E 10
	fragmap <<= 1;
D 10
	for (siz = 1; siz < FRAG; siz++) {
E 10
I 10
	for (siz = 1; siz < fs->fs_frag; siz++) {
E 10
D 21
		if (((1 << siz) & inblk) == 0)
E 21
I 21
		if ((inblk & (1 << (siz + (fs->fs_frag % NBBY)))) == 0)
E 21
			continue;
		field = around[siz];
		subfield = inside[siz];
D 10
		for (pos = siz; pos <= FRAG; pos++) {
E 10
I 10
		for (pos = siz; pos <= fs->fs_frag; pos++) {
E 10
			if ((fragmap & field) == subfield) {
				fraglist[siz] += cnt;
				pos += siz;
				field <<= siz;
				subfield <<= siz;
			}
			field <<= 1;
			subfield <<= 1;
		}
	}
}

E 30
I 10
getsb(fs, file)
	register struct fs *fs;
	char *file;
{
D 23
	int i;
E 23
I 23
	int i, j, size;
E 23

D 12
	if (bread(SBLOCK, fs, MAXBSIZE)) {
E 12
I 12
D 28
	if (bread(SBLOCK, fs, SBSIZE)) {
E 28
I 28
	if (bread(SBOFF, fs, SBSIZE)) {
E 28
E 12
		printf("bad super block");
		perror(file);
		nerror |= 04;
		return;
	}
	if (fs->fs_magic != FS_MAGIC) {
		printf("%s: bad magic number\n", file);
		nerror |= 04;
		return;
	}
I 28
	dev_bsize = fs->fs_fsize / fsbtodb(fs, 1);
E 28
D 23
	for (i = 0; i < howmany(fs->fs_cssize, fs->fs_bsize); i++) {
		fs->fs_csp[i] = (struct csum *)calloc(1, fs->fs_bsize);
		bread(fsbtodb(fs, fs->fs_csaddr + (i * fs->fs_frag)),
		      (char *)fs->fs_csp[i], fs->fs_bsize);
E 23
I 23
	for (i = 0, j = 0; i < sblock.fs_cssize; i += sblock.fs_bsize, j++) {
		size = sblock.fs_cssize - i < sblock.fs_bsize ?
		    sblock.fs_cssize - i : sblock.fs_bsize;
		sblock.fs_csp[j] = (struct csum *)calloc(1, size);
		bread(fsbtodb(fs, fs->fs_csaddr + (j * fs->fs_frag)),
		      (char *)fs->fs_csp[j], size);
E 23
	}
}

E 10
D 30
bwrite(blk, buf, size)
	char *buf;
	daddr_t blk;
	register size;
{
D 10
	if (lseek(fi, blk * FSIZE, 0) < 0) {
E 10
I 10
D 28
	if (lseek(fi, blk * DEV_BSIZE, 0) < 0) {
E 28
I 28
	if (lseek(fi, blk * dev_bsize, 0) < 0) {
E 28
E 10
		perror("FS SEEK");
		return(1);
	}
	if (write(fi, buf, size) != size) {
		perror("FS WRITE");
		return(1);
	}
I 10
	return (0);
E 10
}

E 30
E 9
bread(bno, buf, cnt)
D 4
daddr_t bno;
char *buf;
E 4
I 4
	daddr_t bno;
	char *buf;
E 4
{
	register i;

D 9
	lseek(fi, bno*FSIZE, 0);
E 9
I 9
D 10
	lseek(fi, bno * FSIZE, 0);
E 10
I 10
D 28
	lseek(fi, bno * DEV_BSIZE, 0);
E 28
I 28
	lseek(fi, bno * dev_bsize, 0);
E 28
E 10
E 9
I 7
D 8
/*###402 [lint] lseek value declared inconsistently llib-lc(31) :: icheck.c(402)%%%*/
E 8
E 7
	if ((i = read(fi, buf, cnt)) != cnt) {
I 9
D 30
		if (sflg) {
			printf("No Update\n");
			sflg = 0;
		}
E 30
E 9
D 7
		if (sflg) {
			printf("No update\n");
			sflg = 0;
		}
E 7
D 10
		for(i=0; i<BSIZE; i++)
E 10
I 10
		for(i=0; i<sblock.fs_bsize; i++)
E 10
			buf[i] = 0;
I 10
		return (1);
	}
	return (0);
}

/*
D 25
 * block operations
E 25
I 25
 * check if a block is available
E 25
 */
D 25

E 25
isblock(fs, cp, h)
	struct fs *fs;
	unsigned char *cp;
	int h;
{
	unsigned char mask;

	switch (fs->fs_frag) {
	case 8:
		return (cp[h] == 0xff);
	case 4:
		mask = 0x0f << ((h & 0x1) << 2);
		return ((cp[h >> 1] & mask) == mask);
	case 2:
		mask = 0x03 << ((h & 0x3) << 1);
		return ((cp[h >> 2] & mask) == mask);
	case 1:
		mask = 0x01 << (h & 0x7);
		return ((cp[h >> 3] & mask) == mask);
	default:
I 25
#ifdef STANDALONE
		printf("isblock bad fs_frag %d\n", fs->fs_frag);
#else
E 25
		fprintf(stderr, "isblock bad fs_frag %d\n", fs->fs_frag);
I 25
#endif
E 25
		return;
	}
}

I 25
/*
D 30
 * take a block out of the map
 */
clrblock(fs, cp, h)
	struct fs *fs;
	unsigned char *cp;
	int h;
{
	switch ((fs)->fs_frag) {
	case 8:
		cp[h] = 0;
		return;
	case 4:
		cp[h >> 1] &= ~(0x0f << ((h & 0x1) << 2));
		return;
	case 2:
		cp[h >> 2] &= ~(0x03 << ((h & 0x3) << 1));
		return;
	case 1:
		cp[h >> 3] &= ~(0x01 << (h & 0x7));
		return;
	default:
#ifdef STANDALONE
		printf("clrblock bad fs_frag %d\n", fs->fs_frag);
#else
		fprintf(stderr, "clrblock bad fs_frag %d\n", fs->fs_frag);
#endif
		return;
	}
}

/*
E 30
 * put a block into the map
 */
E 25
setblock(fs, cp, h)
	struct fs *fs;
	unsigned char *cp;
	int h;
{
	switch (fs->fs_frag) {
	case 8:
		cp[h] = 0xff;
		return;
	case 4:
		cp[h >> 1] |= (0x0f << ((h & 0x1) << 2));
		return;
	case 2:
		cp[h >> 2] |= (0x03 << ((h & 0x3) << 1));
		return;
	case 1:
		cp[h >> 3] |= (0x01 << (h & 0x7));
		return;
	default:
I 25
#ifdef STANDALONE
		printf("setblock bad fs_frag %d\n", fs->fs_frag);
#else
E 25
		fprintf(stderr, "setblock bad fs_frag %d\n", fs->fs_frag);
I 25
#endif
E 25
		return;
E 10
D 7
	}
}

bwrite(bno, buf, cnt)
D 4
daddr_t bno;
char *buf;
E 4
I 4
	daddr_t bno;
	char *buf;
E 4
{
D 4
	register i;

E 4
	lseek(fi, bno*FSIZE, 0);
	if (write(fi, buf, cnt) != cnt)
		printf("write error %d\n", tell(fi)/BSIZE);
}

makecg()
{
	int c;
	daddr_t dbase, d, dmin, dmax;
	long i, j, s;
	register struct csum *cs;

	sblock.fs_nbfree = 0;
	sblock.fs_nffree = 0;
	for (c = 0; c < sblock.fs_ncg; c++) {
		bread(cgimin(c,&sblock), (char *)itab,
		    sblock.fs_ipg * sizeof (struct dinode));
		dbase = cgbase(c, &sblock);
		dmax = dbase + sblock.fs_fpg;
		if (dmax > sblock.fs_size)
			dmax = sblock.fs_size;
D 6
		cs = &sblock.fs_cs[c];
E 6
I 6
		cs = &sblock.fs_cs(c);
E 6
D 4
		cgrp.cg_time = time(0);
E 4
I 4
		cgrp.cg_time = time((long)0);
E 4
		cgrp.cg_magic = CG_MAGIC;
		cgrp.cg_cgx = c;
		cgrp.cg_ncyl = sblock.fs_cpg;
		cgrp.cg_niblk = sblock.fs_ipg;
		cgrp.cg_ndblk = dmax - dbase;
		cgrp.cg_ndir = 0;
		cgrp.cg_nffree = 0;
		cgrp.cg_nbfree = 0;
		cgrp.cg_nifree = 0;
		for (i = 0; i < sblock.fs_ipg; i++)
		switch (itab[i].di_mode&IFMT) {

		case 0:
			cgrp.cg_nifree++;
			clrbit(cgrp.cg_iused, i);
			continue;

		case IFDIR:
			cgrp.cg_ndir++;
			/* fall into ... */

		default:
			setbit(cgrp.cg_iused, i);
			continue;
		}
		while (i < MAXIPG) {
			clrbit(cgrp.cg_iused, i);
			i++;
		}
		for (s = 0; s < MAXCPG; s++)
			for (i = 0; i < NRPOS; i++)
				cgrp.cg_b[s][i] = 0;
		dmin = cgdmin(c, &sblock) - dbase;
		if (c == 0)
			dmin += howmany(cssize(&sblock), BSIZE) * FRAG;
		for (d = 0; d < dmin; d++)
			clrbit(cgrp.cg_free, d);
#define	getbmap(i) isset(bmap, i)
		for (; (d + FRAG) <= dmax - dbase; d += FRAG) {
			j = 0;
			for (i = 0; i < FRAG; i++) {
				if (!getbmap(dbase+d+i)) {
					setbit(cgrp.cg_free, d+i);
					j++;
				} else
					clrbit(cgrp.cg_free, d+i);
			}
			if (j == FRAG) {
				cgrp.cg_nbfree++;
				s = d * NSPF;
				cgrp.cg_b[s/sblock.fs_spc]
				  [s%sblock.fs_nsect*NRPOS/sblock.fs_nsect]++;
			} else
				cgrp.cg_nffree += j;
		}
		for (; d < dmax - dbase; d++) {
			if (!getbmap(dbase+d)) {
				setbit(cgrp.cg_free, d);
				cgrp.cg_nffree++;
			} else
				clrbit(cgrp.cg_free, d);
		}
		for (; d < MAXBPG; d++)
			clrbit(cgrp.cg_free, d);
		sblock.fs_nffree += cgrp.cg_nffree;
		sblock.fs_nbfree += cgrp.cg_nbfree;
		cs->cs_ndir = cgrp.cg_ndir;
		cs->cs_nifree = cgrp.cg_nifree;
		cs->cs_nbfree = cgrp.cg_nbfree;
		bwrite(cgtod(c, &sblock), (char *)&cgrp, sblock.fs_cgsize);
	}
	sblock.fs_ronly = 0;
	sblock.fs_fmod = 0;
	bwrite(SBLOCK, (char *)&sblock, sizeof (sblock));
D 4
	lseek(fi, csaddr(&sblock)*FSIZE, 0);
E 4
I 4
D 6
	lseek(fi, csaddr(&sblock) * FSIZE, 0);
E 4
	if (write(fi,(char *)sblock.fs_cs,cssize(&sblock)) != cssize(&sblock))
		printf("write error %d\n", tell(fi)/BSIZE);
E 6
I 6
	for (i = 0; i < howmany(cssize(&sblock), BSIZE); i++) {
		bwrite(csaddr(&sblock) + (i * FRAG),
		      (char *)sblock.fs_csp[i], BSIZE);
E 7
	}
E 6
}
I 22
D 30

/*	tables.c	4.1	82/03/25	*/

/* merged into kernel:	tables.c 2.1 3/25/82 */

/* last monet version:	partab.c	4.2	81/03/08	*/

/*
 * bit patterns for identifying fragments in the block map
 * used as ((map & around) == inside)
 */
int around[9] = {
	0x3, 0x7, 0xf, 0x1f, 0x3f, 0x7f, 0xff, 0x1ff, 0x3ff
};
int inside[9] = {
	0x0, 0x2, 0x6, 0xe, 0x1e, 0x3e, 0x7e, 0xfe, 0x1fe
};

/*
 * given a block map bit pattern, the frag tables tell whether a
 * particular size fragment is available. 
 *
 * used as:
 * if ((1 << (size - 1)) & fragtbl[fs->fs_frag][map] {
 *	at least one fragment of the indicated size is available
 * }
 *
 * These tables are used by the scanc instruction on the VAX to
 * quickly find an appropriate fragment.
 */

unsigned char fragtbl124[256] = {
	0x00, 0x16, 0x16, 0x2a, 0x16, 0x16, 0x26, 0x4e,
	0x16, 0x16, 0x16, 0x3e, 0x2a, 0x3e, 0x4e, 0x8a,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x2a, 0x3e, 0x3e, 0x2a, 0x3e, 0x3e, 0x2e, 0x6e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x2a, 0x3e, 0x6e, 0xaa,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x26, 0x36, 0x36, 0x2e, 0x36, 0x36, 0x26, 0x6e,
	0x36, 0x36, 0x36, 0x3e, 0x2e, 0x3e, 0x6e, 0xae,
	0x4e, 0x5e, 0x5e, 0x6e, 0x5e, 0x5e, 0x6e, 0x4e,
	0x5e, 0x5e, 0x5e, 0x7e, 0x6e, 0x7e, 0x4e, 0xce,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x16, 0x16, 0x16, 0x3e, 0x16, 0x16, 0x36, 0x5e,
	0x16, 0x16, 0x16, 0x3e, 0x3e, 0x3e, 0x5e, 0x9e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e, 0xbe,
	0x2a, 0x3e, 0x3e, 0x2a, 0x3e, 0x3e, 0x2e, 0x6e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x2a, 0x3e, 0x6e, 0xaa,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7e, 0xbe,
	0x4e, 0x5e, 0x5e, 0x6e, 0x5e, 0x5e, 0x6e, 0x4e,
	0x5e, 0x5e, 0x5e, 0x7e, 0x6e, 0x7e, 0x4e, 0xce,
	0x8a, 0x9e, 0x9e, 0xaa, 0x9e, 0x9e, 0xae, 0xce,
	0x9e, 0x9e, 0x9e, 0xbe, 0xaa, 0xbe, 0xce, 0x8a,
};

unsigned char fragtbl8[256] = {
	0x00, 0x01, 0x01, 0x02, 0x01, 0x01, 0x02, 0x04,
	0x01, 0x01, 0x01, 0x03, 0x02, 0x03, 0x04, 0x08,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x02, 0x03, 0x03, 0x02, 0x04, 0x05, 0x08, 0x10,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x05, 0x09,
	0x02, 0x03, 0x03, 0x02, 0x03, 0x03, 0x02, 0x06,
	0x04, 0x05, 0x05, 0x06, 0x08, 0x09, 0x10, 0x20,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x05, 0x09,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x03, 0x03, 0x03, 0x03, 0x05, 0x05, 0x09, 0x11,
	0x02, 0x03, 0x03, 0x02, 0x03, 0x03, 0x02, 0x06,
	0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x06, 0x0a,
	0x04, 0x05, 0x05, 0x06, 0x05, 0x05, 0x06, 0x04,
	0x08, 0x09, 0x09, 0x0a, 0x10, 0x11, 0x20, 0x40,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x05, 0x09,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x03, 0x03, 0x03, 0x03, 0x05, 0x05, 0x09, 0x11,
	0x01, 0x01, 0x01, 0x03, 0x01, 0x01, 0x03, 0x05,
	0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x05, 0x09,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07,
	0x05, 0x05, 0x05, 0x07, 0x09, 0x09, 0x11, 0x21,
	0x02, 0x03, 0x03, 0x02, 0x03, 0x03, 0x02, 0x06,
	0x03, 0x03, 0x03, 0x03, 0x02, 0x03, 0x06, 0x0a,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07,
	0x02, 0x03, 0x03, 0x02, 0x06, 0x07, 0x0a, 0x12,
	0x04, 0x05, 0x05, 0x06, 0x05, 0x05, 0x06, 0x04,
	0x05, 0x05, 0x05, 0x07, 0x06, 0x07, 0x04, 0x0c,
	0x08, 0x09, 0x09, 0x0a, 0x09, 0x09, 0x0a, 0x0c,
	0x10, 0x11, 0x11, 0x12, 0x20, 0x21, 0x40, 0x80,
};

/*
 * the actual fragtbl array
 */
unsigned char *fragtbl[MAXFRAG + 1] = {
	0, fragtbl124, fragtbl124, 0, fragtbl124, 0, 0, 0, fragtbl8,
};
E 30
E 22
E 1
