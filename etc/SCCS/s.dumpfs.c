h60166
s 00027/00014/00207
d D 5.6 88/05/01 23:44:49 mckusick 23 22
c conversion to interpret dynamic cylinder group tables
e
s 00006/00003/00215
d D 5.5 87/02/23 17:39:50 mckusick 22 21
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00020/00018/00198
d D 5.4 87/01/13 18:02:15 mckusick 21 20
c add trackskew, interleave, npsect, headswitch, and trackseek
c reorder superblock output to make more readable
e
s 00003/00002/00213
d D 5.3 85/09/11 22:32:35 mckusick 20 19
c print out optimization preference
e
s 00002/00002/00213
d D 5.2 85/06/06 11:06:00 dist 19 18
c Add copyright
e
s 00014/00002/00201
d D 5.1 85/06/06 11:03:54 dist 18 17
c Add copyright
e
s 00001/00001/00202
d D 2.6 83/09/25 15:28:48 mckusick 17 16
c arguments to seek are backwards
e
s 00042/00016/00161
d D 2.5 83/06/02 17:35:57 sam 16 15
c purge tell and support fs names
e
s 00012/00007/00165
d D 2.4 83/01/02 15:20:48 mckusick 15 14
c add new and useful constants
e
s 00004/00002/00168
d D 2.3 82/09/25 21:47:41 mckusick 14 13
c add maxbpg and maxcontig fields in super block
e
s 00011/00008/00159
d D 2.2 82/04/11 17:22:35 mckusick 13 12
c float the super block, reclaim redundant boot block space
e
s 00007/00001/00160
d D 2.1 82/04/08 15:46:07 mckusick 12 11
c merge into the new kernel
e
s 00028/00033/00133
d D 1.11 82/02/25 14:48:54 mckusic 11 10
c use speed-up macros in fs.h
e
s 00001/00001/00165
d D 1.10 82/01/12 22:18:05 mckusic 10 9
c change all macros taking "fs" to have it as their first argument
e
s 00001/00001/00165
d D 1.9 82/01/12 19:34:58 mckusic 9 8
c add cg_ctot to summarize cg_b
e
s 00024/00010/00142
d D 1.8 82/01/10 18:25:14 mckusic 8 7
c fix rotational layout code to work with disks with nsect % bsize != 0
e
s 00012/00007/00140
d D 1.7 82/01/06 23:35:00 mckusic 7 6
c incorporate fs.h -r1.10, and param.h -r1.8 reorganization
e
s 00020/00012/00127
d D 1.6 82/01/05 01:34:04 mckusic 6 5
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00010/00007/00129
d D 1.5 81/11/07 20:00:02 mckusic 5 4
c edit to incorperate -r1.6 reorganization of fs.h
e
s 00024/00010/00112
d D 1.4 81/10/29 00:37:22 mckusic 4 3
c put in optimal rotational block allocation
e
s 00006/00004/00116
d D 1.3 81/10/05 20:46:21 mckusic 3 2
c maintaining and using cg_frsum to do intelligent allocation of FRAGs
e
s 00001/00001/00119
d D 1.2 81/08/28 21:22:39 mckusic 2 1
c put in new inode structure
e
s 00120/00000/00000
d D 1.1 81/08/26 23:48:00 mckusick 1 0
c date and time created 81/08/26 23:48:00 by mckusick
e
u
U
t
T
I 18
/*
D 19
 * Copyright (c) 1980 Regents of the University of California.
E 19
I 19
 * Copyright (c) 1983 Regents of the University of California.
E 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 18
I 16
#ifndef lint
E 16
I 1
D 18
static	char *sccsid = "%W% (Berkeley) %G%";
I 16
#endif
E 18
I 18
char copyright[] =
D 19
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
E 19
I 19
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
E 19
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 18
E 16
I 6

I 12
D 16
#ifndef SIMFS
E 16
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
D 16
#else
E 12
E 6
#include "../h/param.h"
D 12
#include "../h/fs.h"
E 12
D 2
#include "../h/ino.h"
E 2
I 2
#include "../h/inode.h"
I 12
#include "../h/fs.h"
#endif
E 16
E 12
E 2

I 16
#include <stdio.h>
#include <fstab.h>

E 16
/*
 * dumpfs
 */

union {
	struct fs fs;
D 6
	char pad[BSIZE];
E 6
I 6
	char pad[MAXBSIZE];
E 6
} fsun;
#define	afs	fsun.fs

D 4
struct	csum *fscs;

E 4
union {
	struct cg cg;
D 6
	char pad[BSIZE];
E 6
I 6
	char pad[MAXBSIZE];
E 6
} cgun;
#define	acg	cgun.cg

I 22
long	dev_bsize = 1;

E 22
main(argc, argv)
	char **argv;
{
I 16
	register struct fstab *fs;

	argc--, argv++;
	if (argc < 1) {
		fprintf(stderr, "usage: dumpfs fs ...\n");
		exit(1);
	}
	for (; argc > 0; argv++, argc--) {
		fs = getfsfile(*argv);
		if (fs == 0)
			dumpfs(*argv);
		else
			dumpfs(fs->fs_spec);
	}
}

dumpfs(name)
	char *name;
{
E 16
D 4
	int i;
E 4
I 4
D 8
	int i, j, k;
E 8
I 8
D 13
	int c, i, j, k;
E 13
I 13
	int c, i, j, k, size;
E 13
E 8
E 4

	close(0);
D 16
	if (open(argv[1], 0) != 0)
		perror(argv[1]), exit(1);
E 16
I 16
	if (open(name, 0) != 0) {
		perror(name);
		return;
	}
E 16
D 6
	lseek(0, SBLOCK*FSIZE, 0);
	if (read(0, &afs, BSIZE) != BSIZE)
E 6
I 6
D 22
	lseek(0, SBLOCK * DEV_BSIZE, 0);
E 22
I 22
	lseek(0, SBOFF, 0);
E 22
D 7
	if (read(0, &afs, MAXBSIZE) != MAXBSIZE)
E 7
I 7
D 16
	if (read(0, &afs, SBSIZE) != SBSIZE)
E 7
E 6
		perror(argv[1]), exit(1);
E 16
I 16
	if (read(0, &afs, SBSIZE) != SBSIZE) {
		perror(name);
		return;
	}
I 23
	if (afs.fs_postblformat == FS_42POSTBLFMT)
		afs.fs_nrpos = 8;
E 23
I 22
	dev_bsize = afs.fs_fsize / fsbtodb(&afs, 1);
E 22
E 16
D 11
	printf("magic\t%x\n", afs.fs_magic);
I 8
	printf("bblkno\t%d\n", afs.fs_bblkno);
E 8
	printf("sblkno\t%d\n", afs.fs_sblkno);
I 8
	printf("cblkno\t%d\n", afs.fs_cblkno);
	printf("iblkno\t%d\n", afs.fs_iblkno);
	printf("dblkno\t%d\n", afs.fs_dblkno);
E 8
	printf("time\t%s", ctime(&afs.fs_time));
	printf("size\t%d\n", afs.fs_size);
I 5
	printf("blocks\t%d\n", afs.fs_dsize);
E 5
	printf("ncg\t%d\n", afs.fs_ncg);
I 6
	printf("bsize\t%d\n", afs.fs_bsize);
	printf("fsize\t%d\n", afs.fs_fsize);
	printf("frag\t%d\n", afs.fs_frag);
	printf("minfree\t%d%%\n", afs.fs_minfree);
	printf("rotdelay %dms\n", afs.fs_rotdelay);
I 8
	printf("rps\t%d\n", afs.fs_rps);
E 8
	printf("csaddr\t%d\n", afs.fs_csaddr);
E 6
	printf("cssize\t%d\n", afs.fs_cssize);
	printf("cgsize\t%d\n", afs.fs_cgsize);
	printf("ntrak\t%d\nnsect\t%d\nspc\t%d\nncyl\t%d\n",
E 11
I 11
D 23
	printf("magic\t%x\ttime\t%s", afs.fs_magic, ctime(&afs.fs_time));
E 23
I 23
	printf("magic\t%x\tformat\t%s\ttime\t%s", afs.fs_magic,
	    afs.fs_postblformat == FS_42POSTBLFMT ? "static" : "dynamic",
	    ctime(&afs.fs_time));
E 23
D 13
	printf("bblkno\t%d\tsblkno\t%d\n", afs.fs_bblkno, afs.fs_sblkno);
	printf("cblkno\t%d\tiblkno\t%d\tdblkno\t%d\n",
	    afs.fs_cblkno, afs.fs_iblkno, afs.fs_dblkno);
E 13
I 13
D 21
	printf("sblkno\t%d\tcblkno\t%d\tiblkno\t%d\tdblkno\t%d\n",
	    afs.fs_sblkno, afs.fs_cblkno, afs.fs_iblkno, afs.fs_dblkno);
D 15
	printf("cgoffset\t%d\tcgmask\t0x%08x\n",
	    afs.fs_cgoffset, afs.fs_cgmask);
E 13
	printf("ncg\t%d\tsize\t%d\tblocks\t%d\tcgsize\t%d\n",
	    afs.fs_ncg, afs.fs_size, afs.fs_dsize, afs.fs_cgsize);
E 15
I 15
	printf("sbsize\t%d\tcgsize\t%d\tcgoffset %d\tcgmask\t0x%08x\n",
	    afs.fs_sbsize, afs.fs_cgsize, afs.fs_cgoffset, afs.fs_cgmask);
	printf("ncg\t%d\tsize\t%d\tblocks\t%d\n",
	    afs.fs_ncg, afs.fs_size, afs.fs_dsize);
E 21
I 21
	printf("nbfree\t%d\tndir\t%d\tnifree\t%d\tnffree\t%d\n",
	    afs.fs_cstotal.cs_nbfree, afs.fs_cstotal.cs_ndir,
	    afs.fs_cstotal.cs_nifree, afs.fs_cstotal.cs_nffree);
	printf("ncg\t%d\tncyl\t%d\tsize\t%d\tblocks\t%d\n",
	    afs.fs_ncg, afs.fs_ncyl, afs.fs_size, afs.fs_dsize);
E 21
E 15
	printf("bsize\t%d\tshift\t%d\tmask\t0x%08x\n",
	    afs.fs_bsize, afs.fs_bshift, afs.fs_bmask);
	printf("fsize\t%d\tshift\t%d\tmask\t0x%08x\n",
	    afs.fs_fsize, afs.fs_fshift, afs.fs_fmask);
D 14
	printf("frag\t%d\tminfree\t%d%%\n", afs.fs_frag, afs.fs_minfree);
	printf("rotdelay %dms\trps\t%d\n", afs.fs_rotdelay, afs.fs_rps);
E 14
I 14
D 15
	printf("frag\t%d\tminfree\t%d%%\tmaxbpg\t%d\n",
	    afs.fs_frag, afs.fs_minfree, afs.fs_maxbpg);
E 15
I 15
	printf("frag\t%d\tshift\t%d\tfsbtodb\t%d\n",
	    afs.fs_frag, afs.fs_fragshift, afs.fs_fsbtodb);
D 20
	printf("minfree\t%d%%\tmaxbpg\t%d\n",
	    afs.fs_minfree, afs.fs_maxbpg);
E 20
I 20
D 21
	printf("minfree\t%d%%\tmaxbpg\t%d\toptim\t%s\n",
	    afs.fs_minfree, afs.fs_maxbpg,
	    afs.fs_optim == FS_OPTSPACE ? "space" : "time");
E 20
E 15
	printf("maxcontig %d\trotdelay %dms\trps\t%d\n",
	    afs.fs_maxcontig, afs.fs_rotdelay, afs.fs_rps);
E 14
D 15
	printf("csaddr\t%d\tcssize\t%d\n", afs.fs_csaddr, afs.fs_cssize);
E 15
I 15
	printf("csaddr\t%d\tcssize\t%d\tshift\t%d\tmask\t0x%08x\n",
	    afs.fs_csaddr, afs.fs_cssize, afs.fs_csshift, afs.fs_csmask);
E 15
	printf("ntrak\t%d\tnsect\t%d\tspc\t%d\tncyl\t%d\n",
E 11
	    afs.fs_ntrak, afs.fs_nsect, afs.fs_spc, afs.fs_ncyl);
E 21
D 7
	printf("cpg\t%d\nfpg\t%d\nipg\t%d\n",
	    afs.fs_cpg, afs.fs_fpg, afs.fs_ipg);
E 7
I 7
D 11
	printf("cpg\t%d\nbpg\t%d\nfpg\t%d\nipg\t%d\n",
E 11
I 11
	printf("cpg\t%d\tbpg\t%d\tfpg\t%d\tipg\t%d\n",
E 11
	    afs.fs_cpg, afs.fs_fpg / afs.fs_frag, afs.fs_fpg, afs.fs_ipg);
I 21
	printf("minfree\t%d%%\toptim\t%s\tmaxcontig %d\tmaxbpg\t%d\n",
	    afs.fs_minfree, afs.fs_optim == FS_OPTSPACE ? "space" : "time",
	    afs.fs_maxcontig, afs.fs_maxbpg);
	printf("rotdelay %dms\theadswitch %dus\ttrackseek %dus\trps\t%d\n",
	    afs.fs_rotdelay, afs.fs_headswitch, afs.fs_trkseek, afs.fs_rps);
	printf("ntrak\t%d\tnsect\t%d\tnpsect\t%d\tspc\t%d\n",
	    afs.fs_ntrak, afs.fs_nsect, afs.fs_npsect, afs.fs_spc);
	printf("trackskew %d\tinterleave %d\n",
	    afs.fs_trackskew, afs.fs_interleave);
E 21
I 15
	printf("nindir\t%d\tinopb\t%d\tnspf\t%d\n",
	    afs.fs_nindir, afs.fs_inopb, afs.fs_nspf);
E 15
E 7
D 5
	printf("nffree\t%d\nnbfree\t%d\nnifree\t%d\n",
	    afs.fs_nffree, afs.fs_nbfree, afs.fs_nifree);
E 5
I 5
D 11
	printf("ndir\t%d\nnffree\t%d\nnbfree\t%d\nnifree\t%d\n",
	    afs.fs_cstotal.cs_ndir, afs.fs_cstotal.cs_nffree,
	    afs.fs_cstotal.cs_nbfree, afs.fs_cstotal.cs_nifree);
E 5
D 4
	printf("cs[].cs_(nbfree,ndir,nifree):\n\t");
	fscs = (struct csum *)calloc(afs.fs_ncg, sizeof (struct csum));
	lseek(0, csaddr(&afs)*FSIZE, 0);
	if (read(0, fscs, cssize(&afs)) != cssize(&afs))
		perror(argv[1]), exit(1);
E 4
I 4
D 7
	printf("cgrotor\t%d\nblocks available in each rotational position",
	    afs.fs_cgrotor);
E 7
I 7
	printf("cgrotor\t%d\nfmod\t%d\nronly\t%d\n",
E 11
I 11
D 21
	printf("nbfree\t%d\tndir\t%d\tnifree\t%d\tnffree\t%d\n",
	    afs.fs_cstotal.cs_nbfree, afs.fs_cstotal.cs_ndir,
	    afs.fs_cstotal.cs_nifree, afs.fs_cstotal.cs_nffree);
E 21
I 21
	printf("sblkno\t%d\tcblkno\t%d\tiblkno\t%d\tdblkno\t%d\n",
	    afs.fs_sblkno, afs.fs_cblkno, afs.fs_iblkno, afs.fs_dblkno);
	printf("sbsize\t%d\tcgsize\t%d\tcgoffset %d\tcgmask\t0x%08x\n",
	    afs.fs_sbsize, afs.fs_cgsize, afs.fs_cgoffset, afs.fs_cgmask);
	printf("csaddr\t%d\tcssize\t%d\tshift\t%d\tmask\t0x%08x\n",
	    afs.fs_csaddr, afs.fs_cssize, afs.fs_csshift, afs.fs_csmask);
E 21
	printf("cgrotor\t%d\tfmod\t%d\tronly\t%d\n",
E 11
	    afs.fs_cgrotor, afs.fs_fmod, afs.fs_ronly);
D 8
	printf("blocks available in each rotational position");
E 7
	for (i = 0; i < NRPOS; i++) {
		if (afs.fs_postbl[i] > -1)
			printf("\nposition %d:\t", i);
		for (j = afs.fs_postbl[i], k = 1; j > -1;
		     j = afs.fs_rotbl[j], k++) {
			if (k % 15 == 0)
				printf("\n\t\t");
			printf("%4d", j);
E 8
I 8
	if (afs.fs_cpc != 0)
D 23
		printf("blocks available in each rotational position");
E 23
I 23
		printf("blocks available in each of %d rotational positions",
		     afs.fs_nrpos);
E 23
	else
		printf("insufficient space to maintain rotational tables\n");
	for (c = 0; c < afs.fs_cpc; c++) {
		printf("\ncylinder number %d:", c);
D 23
		for (i = 0; i < NRPOS; i++) {
			if (afs.fs_postbl[c][i] == -1)
E 23
I 23
		for (i = 0; i < afs.fs_nrpos; i++) {
			if (fs_postbl(&afs, c)[i] == -1)
E 23
				continue;
			printf("\n   position %d:\t", i);
D 23
			for (j = afs.fs_postbl[c][i], k = 1; ;
			     j += afs.fs_rotbl[j], k++) {
E 23
I 23
			for (j = fs_postbl(&afs, c)[i], k = 1; ;
			     j += fs_rotbl(&afs)[j], k++) {
E 23
				printf("%5d", j);
				if (k % 12 == 0)
					printf("\n\t\t");
D 23
				if (afs.fs_rotbl[j] == 0)
E 23
I 23
				if (fs_rotbl(&afs)[j] == 0)
E 23
					break;
			}
E 8
		}
	}
D 5
	printf("\ncs[].cs_(nbfree,ndir,nifree):\n\t");
E 5
I 5
	printf("\ncs[].cs_(nbfree,ndir,nifree,nffree):\n\t");
E 5
D 6
	for (i = 0; i < howmany(cssize(&afs), BSIZE); i++) {
		afs.fs_csp[i] = (struct csum *)calloc(1, BSIZE);
		lseek(0, (csaddr(&afs) + (i * FRAG)) * FSIZE, 0);
		if (read(0, afs.fs_csp[i], BSIZE) != BSIZE)
E 6
I 6
D 13
	for (i = 0; i < howmany(afs.fs_cssize, afs.fs_bsize); i++) {
		afs.fs_csp[i] = (struct csum *)calloc(1, afs.fs_bsize);
		lseek(0, fsbtodb(&afs, (afs.fs_csaddr + (i * afs.fs_frag))) *
E 13
I 13
	for (i = 0, j = 0; i < afs.fs_cssize; i += afs.fs_bsize, j++) {
		size = afs.fs_cssize - i < afs.fs_bsize ?
		    afs.fs_cssize - i : afs.fs_bsize;
		afs.fs_csp[j] = (struct csum *)calloc(1, size);
		lseek(0, fsbtodb(&afs, (afs.fs_csaddr + j * afs.fs_frag)) *
E 13
D 22
		    DEV_BSIZE, 0);
E 22
I 22
		    dev_bsize, 0);
E 22
D 13
		if (read(0, afs.fs_csp[i], afs.fs_bsize) != afs.fs_bsize)
E 13
I 13
D 16
		if (read(0, afs.fs_csp[j], size) != size)
E 13
E 6
			perror(argv[1]), exit(1);
E 16
I 16
		if (read(0, afs.fs_csp[j], size) != size) {
			perror(name);
			return;
		}
E 16
	}
E 4
	for (i = 0; i < afs.fs_ncg; i++) {
D 4
		struct csum *cs = fscs+i;
E 4
I 4
D 6
		struct csum *cs = &afs.fs_cs(i);
E 6
I 6
		struct csum *cs = &afs.fs_cs(&afs, i);
E 6
E 4
D 5
		if (i && i % 5 == 0)
E 5
I 5
		if (i && i % 4 == 0)
E 5
			printf("\n\t");
D 5
		printf("(%d,%d,%d) ",
		    cs->cs_nbfree, cs->cs_ndir, cs->cs_nifree);
E 5
I 5
		printf("(%d,%d,%d,%d) ",
		    cs->cs_nbfree, cs->cs_ndir, cs->cs_nifree, cs->cs_nffree);
E 5
	}
	printf("\n");
D 7
	printf("fmod\t%d\n", afs.fs_fmod);
	printf("ronly\t%d\n", afs.fs_ronly);
E 7
I 7
	if (afs.fs_ncyl % afs.fs_cpg) {
		printf("cylinders in last group %d\n",
		    i = afs.fs_ncyl % afs.fs_cpg);
		printf("blocks in last group %d\n",
		    i * afs.fs_spc / NSPB(&afs));
	}
E 7
	printf("\n");
	for (i = 0; i < afs.fs_ncg; i++)
D 16
		dumpcg(i);
E 16
I 16
		dumpcg(name, i);
	close(0);
E 16
};

D 16
dumpcg(c)
E 16
I 16
dumpcg(name, c)
	char *name;
E 16
	int c;
{
	int i,j;

	printf("\ncg %d:\n", c);
D 6
	lseek(0, cgtod(c,&afs)*FSIZE, 0);
E 6
I 6
D 10
	lseek(0, fsbtodb(&afs, cgtod(c,&afs)) * DEV_BSIZE, 0);
E 10
I 10
D 22
	lseek(0, fsbtodb(&afs, cgtod(&afs, c)) * DEV_BSIZE, 0);
E 22
I 22
	lseek(0, fsbtodb(&afs, cgtod(&afs, c)) * dev_bsize, 0);
E 22
E 10
E 6
D 11
	printf("tell\t%x\n", tell(0));
E 11
I 11
D 16
	i = tell(0);
E 16
I 16
D 17
	i = lseek(0, 1, 0);
E 17
I 17
	i = lseek(0, 0, 1);
E 17
E 16
E 11
D 6
	if (read(0, (char *)&acg, afs.fs_cgsize) != afs.fs_cgsize) {
E 6
I 6
	if (read(0, (char *)&acg, afs.fs_bsize) != afs.fs_bsize) {
E 6
D 16
		printf("\terror reading cg\n");
E 16
I 16
		printf("dumpfs: %s: error reading cg\n", name);
E 16
		return;
	}
D 11
	printf("magic\t%x\ntime\t%s", acg.cg_magic, ctime(&acg.cg_time));
	printf("cgx\t%d\nncyl\t%d\nniblk\t%d\nndblk\t%d\n",
E 11
I 11
	printf("magic\t%x\ttell\t%x\ttime\t%s",
D 23
	    acg.cg_magic, i, ctime(&acg.cg_time));
E 23
I 23
	    afs.fs_postblformat == FS_42POSTBLFMT ?
	    ((struct ocg *)&acg)->cg_magic : acg.cg_magic,
	    i, ctime(&acg.cg_time));
E 23
	printf("cgx\t%d\tncyl\t%d\tniblk\t%d\tndblk\t%d\n",
E 11
	    acg.cg_cgx, acg.cg_ncyl, acg.cg_niblk, acg.cg_ndblk);
D 3
	printf("nifree\t%d\nndir\t%d\nnffree\t%d\nnbfree\t%d\n",
E 3
I 3
D 4
	printf("nifree\t%d\nndir\t%d\nnffree\t%d\nnbfree\t%d\nfrsum",
E 4
I 4
D 11
	printf("nifree\t%d\nndir\t%d\nnffree\t%d\nnbfree\t%d\n",
E 4
E 3
D 5
	    acg.cg_nifree, acg.cg_ndir, acg.cg_nffree, acg.cg_nbfree);
E 5
I 5
	    acg.cg_cs.cs_nifree, acg.cg_cs.cs_ndir,
	    acg.cg_cs.cs_nffree, acg.cg_cs.cs_nbfree);
E 5
I 4
	printf("rotor\t%d\nirotor\t%d\nfrotor\t%d\nfrsum",
E 11
I 11
	printf("nbfree\t%d\tndir\t%d\tnifree\t%d\tnffree\t%d\n",
	    acg.cg_cs.cs_nbfree, acg.cg_cs.cs_ndir,
	    acg.cg_cs.cs_nifree, acg.cg_cs.cs_nffree);
	printf("rotor\t%d\tirotor\t%d\tfrotor\t%d\nfrsum",
E 11
	    acg.cg_rotor, acg.cg_irotor, acg.cg_frotor);
E 4
D 3
	printf("iused:\t");
E 3
I 3
D 6
	for (i = 1, j = 0; i < FRAG; i++) {
E 6
I 6
	for (i = 1, j = 0; i < afs.fs_frag; i++) {
E 6
		printf("\t%d", acg.cg_frsum[i]);
		j += i * acg.cg_frsum[i];
	}
	printf("\nsum of frsum: %d\niused:\t", j);
E 3
D 23
	pbits(acg.cg_iused, afs.fs_ipg);
E 23
I 23
	pbits(cg_inosused(&acg), afs.fs_ipg);
E 23
	printf("free:\t");
D 23
	pbits(acg.cg_free, afs.fs_fpg);
E 23
I 23
	pbits(cg_blksfree(&acg), afs.fs_fpg);
E 23
	printf("b:\n");
	for (i = 0; i < afs.fs_cpg; i++) {
D 9
		printf("   c%d:\t", i);
E 9
I 9
D 23
		printf("   c%d:\t(%d)\t", i, acg.cg_btot[i]);
E 9
		for (j = 0; j < NRPOS; j++)
			printf(" %d", acg.cg_b[i][j]);
E 23
I 23
		if (cg_blktot(&acg)[i] == 0)
			continue;
		printf("   c%d:\t(%d)\t", i, cg_blktot(&acg)[i]);
		for (j = 0; j < afs.fs_nrpos; j++) {
			if (afs.fs_cpc > 0 &&
			    fs_postbl(&afs, i % afs.fs_cpc)[j] == -1)
				continue;
			printf(" %d", cg_blks(&afs, &acg, i)[j]);
		}
E 23
		printf("\n");
	}
};
D 3

#define	isset(cp,i)	(cp)[(i)/NBBY]&(1<<((i)%NBBY))
E 3

pbits(cp, max)
	register char *cp;
	int max;
{
	register int i;
	int count = 0, j;

	for (i = 0; i < max; i++)
		if (isset(cp, i)) {
			if (count)
D 11
				printf(",%s", count %10 == 9 ? "\n\t" : " ");
E 11
I 11
D 23
				printf(",%s", count %9 == 8 ? "\n\t" : " ");
E 23
I 23
				printf(",%s", count % 6 ? " " : "\n\t");
E 23
E 11
			count++;
			printf("%d", i);
			j = i;
			while ((i+1)<max && isset(cp, i+1))
				i++;
			if (i != j)
				printf("-%d", i);
		}
	printf("\n");
}
E 1
