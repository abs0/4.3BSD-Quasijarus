h43080
s 00006/00004/00422
d D 5.19 88/05/07 01:04:16 mckusick 25 24
c expand from three static buffer to a dynamic buffer pool;
c initial sizing of the buffer pool is 128K (For 8K fs == 16 buffers)
e
s 00029/00017/00397
d D 5.18 88/05/02 15:56:10 mckusick 24 23
c conversion (in either direction) is only done when requested with -c
e
s 00070/00020/00344
d D 5.17 88/05/01 23:40:39 mckusick 23 22
c conversion between static and dynamic cylinder group tables;
c force write of last alternate super block when adding new constants
c (to avoid comparison errors during normal super block checking)
e
s 00008/00003/00356
d D 5.16 88/04/06 18:52:11 mckusick 22 21
c recover from trashed summary information
e
s 00001/00000/00358
d D 5.15 87/12/21 12:43:38 bostic 21 20
c make ANSI C compatible
e
s 00028/00012/00330
d D 5.14 87/04/07 19:49:20 karels 20 19
c fix alternate superblock location again; don't offer to rewrite
c standard superblock if we haven't found a good one yet; standardize units
c for -b (sectors! as before); kernel may change fs_dbsize
e
s 00000/00008/00342
d D 5.13 87/03/11 20:10:23 karels 19 18
c huh? where did this come from?
e
s 00015/00005/00327
d D 5.12 87/03/11 20:06:26 karels 18 17
c use physical sector size for partial buffer reads;
c -n implies "yes" answer for "CONTINUE?"
e
s 00008/00003/00329
d D 5.11 87/03/09 14:49:59 mckusick 17 16
c make fixing interleave non-fatal
e
s 00004/00006/00328
d D 5.10 87/03/05 12:46:53 mckusick 16 15
c allow fsck to proceed even when not setting default psect and interleave
e
s 00012/00056/00322
d D 5.9 87/02/26 17:44:54 karels 15 14
c update disk labels to ioctl's; check the file the user specified!;
c don't try to check "." if a named file doesn't exist;
c don't check spare constants in superblock against alternate;
c make the "TRASHED VALUES" message understandable
e
s 00003/00003/00375
d D 5.8 87/02/23 14:42:19 mckusick 14 13
c use SBOFF instead of SBLOCK
e
s 00003/00000/00375
d D 5.7 87/02/18 18:14:43 mckusick 13 12
c intuit the appropriate DEV_BSIZE from fsbtodb macro
e
s 00002/00000/00373
d D 5.6 87/01/17 11:35:23 mckusick 12 11
c must copy fs_npsect and fs_interleave to cope for old file systems
e
s 00016/00000/00357
d D 5.5 87/01/15 21:29:06 mckusick 11 10
c add sanity checks for new values used in calculating rotational layout
e
s 00230/00064/00127
d D 5.4 87/01/15 21:28:08 mckusick 10 9
c reorganize to allow use of disk labels to search for alternate
c super-blocks when the standard super-block is unusable
e
s 00018/00000/00173
d D 5.3 86/05/15 13:40:24 mckusick 9 8
c add error messages for bad minfree and optimization values
e
s 00001/00000/00172
d D 5.2 85/09/11 21:22:38 mckusick 8 7
c must account for fs_optim field in check
e
s 00008/00002/00164
d D 5.1 85/06/05 08:58:18 dist 7 6
c Add copyright
e
s 00000/00001/00166
d D 3.6 85/06/02 16:47:16 mckusick 6 5
c dynamically allocate zero link count table
e
s 00000/00001/00167
d D 3.5 85/05/31 20:08:51 mckusick 5 4
c dynamically allocate the duplicate block table
e
s 00004/00004/00164
d D 3.4 85/05/31 00:19:38 mckusick 4 3
c check for improper directory offsets; recover gracefully from read errors
e
s 00000/00008/00168
d D 3.3 85/02/08 19:15:55 mckusick 3 2
c merge passes 5 and 6 into a single pass
e
s 00003/00014/00173
d D 3.2 85/02/07 17:52:21 mckusick 2 1
c code reorganization and cleanup
e
s 00187/00000/00000
d D 3.1 84/03/31 21:03:54 mckusick 1 0
c date and time created 84/03/31 21:03:54 by mckusick
e
u
U
t
T
I 7
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 7
I 1
#ifndef lint
D 7
static char version[] = "%W% (Berkeley) %G%";
#endif
E 7
I 7
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 7

I 10
#define DKTYPENAMES
E 10
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include <sys/stat.h>
I 10
#include <sys/ioctl.h>
#include <sys/disklabel.h>
#include <sys/file.h>
I 23
#include <machine/endian.h>
E 23
#include <ctype.h>
E 10
#include "fsck.h"

I 23
BUFAREA asblk;
D 25
#define altsblock asblk.b_un.b_fs
E 25
I 25
#define altsblock (*asblk.b_un.b_fs)
E 25
E 23
I 10
#define POWEROF2(num)	(((num) & ((num) - 1)) == 0)

E 10
char	*calloc();
I 10
char	*index();
E 10

setup(dev)
	char *dev;
{
	dev_t rootdev;
I 10
D 22
	long cg, ncg, size, i, j;
E 22
I 22
	long cg, ncg, size, asked, i, j;
E 22
I 20
	struct disklabel *getdisklabel(), *lp;
E 20
E 10
	struct stat statb;
D 10
	daddr_t super = bflag ? bflag : SBLOCK;
D 2
	int i, j, c, d, cgd;
E 2
I 2
	int i, j;
E 2
	long size;
	BUFAREA asblk;
#	define altsblock asblk.b_un.b_fs
E 10
I 10
	struct fs proto;
E 10

I 20
	havesb = 0;
E 20
	if (stat("/", &statb) < 0)
		errexit("Can't stat root\n");
	rootdev = statb.st_dev;
	if (stat(dev, &statb) < 0) {
I 15
		perror(dev);
E 15
D 2
		error("Can't stat %s\n", dev);
E 2
I 2
		printf("Can't stat %s\n", dev);
E 2
		return (0);
	}
	rawflg = 0;
	if ((statb.st_mode & S_IFMT) == S_IFBLK)
		;
	else if ((statb.st_mode & S_IFMT) == S_IFCHR)
		rawflg++;
	else {
		if (reply("file is not a block or character device; OK") == 0)
			return (0);
	}
	if (rootdev == statb.st_rdev)
		hotroot++;
D 10
	if ((dfile.rfdes = open(dev, 0)) < 0) {
E 10
I 10
	if ((dfile.rfdes = open(dev, O_RDONLY)) < 0) {
I 15
		perror(dev);
E 15
E 10
D 2
		error("Can't open %s\n", dev);
E 2
I 2
		printf("Can't open %s\n", dev);
E 2
		return (0);
	}
	if (preen == 0)
		printf("** %s", dev);
D 10
	if (nflag || (dfile.wfdes = open(dev, 1)) < 0) {
E 10
I 10
	if (nflag || (dfile.wfdes = open(dev, O_WRONLY)) < 0) {
E 10
		dfile.wfdes = -1;
		if (preen)
			pfatal("NO WRITE ACCESS");
		printf(" (NO WRITE)");
	}
	if (preen == 0)
		printf("\n");
D 3
	fixcg = 0; inosumbad = 0; offsumbad = 0; frsumbad = 0; sbsumbad = 0;
E 3
	dfile.mod = 0;
D 3
	n_files = n_blks = n_ffree = n_bfree = 0;
E 3
D 5
	muldup = enddup = &duplist[0];
E 5
D 6
	badlnp = &badlncnt[0];
E 6
	lfdir = 0;
D 2
	rplyflag = 0;
E 2
	initbarea(&sblk);
D 25
	initbarea(&fileblk);
	initbarea(&inoblk);
	initbarea(&cgblk);
E 25
I 23
	initbarea(&asblk);
I 25
	sblk.b_un.b_buf = (char *)malloc(SBSIZE);
	asblk.b_un.b_buf = (char *)malloc(SBSIZE);
	if (sblk.b_un.b_buf == 0 || asblk.b_un.b_buf == 0)
		errexit("cannot allocate space for superblock\n");
E 25
E 23
I 20
	if (lp = getdisklabel((char *)NULL, dfile.rfdes))
		dev_bsize = secsize = lp->d_secsize;
D 23
	else {
		dev_bsize = DEV_BSIZE;
		secsize = 0;			/* guess later */
	}
E 23
I 23
	else
		dev_bsize = secsize = DEV_BSIZE;
E 23
E 20
D 10
	initbarea(&asblk);
E 10
	/*
D 10
	 * Read in the super block and its summary info.
E 10
I 10
	 * Read in the superblock, looking for alternates if necessary
E 10
	 */
D 4
	if (bread(&dfile, (char *)&sblock, super, (long)SBSIZE) == 0)
E 4
I 4
D 10
	if (bread(&dfile, (char *)&sblock, super, (long)SBSIZE) != 0)
E 4
		return (0);
	sblk.b_bno = super;
	sblk.b_size = SBSIZE;
E 10
I 10
	if (readsb(1) == 0) {
D 20
		if (bflag || calcsb(dev, dfile.rfdes, &proto) == 0 || preen)
E 20
I 20
		if (bflag || preen || calcsb(dev, dfile.rfdes, &proto) == 0)
E 20
			return(0);
		if (reply("LOOK FOR ALTERNATE SUPERBLOCKS") == 0)
			return (0);
		for (cg = 0; cg < proto.fs_ncg; cg++) {
			bflag = fsbtodb(&proto, cgsblock(&proto, cg));
			if (readsb(0) != 0)
				break;
		}
		if (cg >= proto.fs_ncg) {
			printf("%s %s\n%s %s\n%s %s\n",
				"SEARCH FOR ALTERNATE SUPER-BLOCK",
				"FAILED. YOU MUST USE THE",
				"-b OPTION TO FSCK TO SPECIFY THE",
				"LOCATION OF AN ALTERNATE",
				"SUPER-BLOCK TO SUPPLY NEEDED",
				"INFORMATION; SEE fsck(8).");
			return(0);
		}
		pwarn("USING ALTERNATE SUPERBLOCK AT %d\n", bflag);
	}
	fmax = sblock.fs_size;
	imax = sblock.fs_ncg * sblock.fs_ipg;
E 10
	/*
D 10
	 * run a few consistency checks of the super block
	 */
	if (sblock.fs_magic != FS_MAGIC)
		{ badsb("MAGIC NUMBER WRONG"); return (0); }
	if (sblock.fs_ncg < 1)
		{ badsb("NCG OUT OF RANGE"); return (0); }
	if (sblock.fs_cpg < 1 || sblock.fs_cpg > MAXCPG)
		{ badsb("CPG OUT OF RANGE"); return (0); }
	if (sblock.fs_ncg * sblock.fs_cpg < sblock.fs_ncyl ||
	    (sblock.fs_ncg - 1) * sblock.fs_cpg >= sblock.fs_ncyl)
		{ badsb("NCYL DOES NOT JIVE WITH NCG*CPG"); return (0); }
	if (sblock.fs_sbsize > SBSIZE)
		{ badsb("SIZE PREPOSTEROUSLY LARGE"); return (0); }
	/*
E 10
I 9
	 * Check and potentially fix certain fields in the super block.
	 */
	if (sblock.fs_optim != FS_OPTTIME && sblock.fs_optim != FS_OPTSPACE) {
		pfatal("UNDEFINED OPTIMIZATION IN SUPERBLOCK");
		if (reply("SET TO DEFAULT") == 1) {
			sblock.fs_optim = FS_OPTTIME;
			sbdirty();
		}
	}
	if ((sblock.fs_minfree < 0 || sblock.fs_minfree > 99)) {
		pfatal("IMPOSSIBLE MINFREE=%d IN SUPERBLOCK",
			sblock.fs_minfree);
		if (reply("SET TO DEFAULT") == 1) {
			sblock.fs_minfree = 10;
			sbdirty();
		}
	}
I 11
	if (sblock.fs_interleave < 1) {
D 17
D 18
		pfatal("IMPOSSIBLE INTERLEAVE=%d IN SUPERBLOCK",
E 18
I 18
		pwarn("IMPOSSIBLE INTERLEAVE=%d IN SUPERBLOCK",
E 18
E 17
I 17
D 19
		pwarn("IMPOSSIBLE INTERLEAVE=%d IN SUPERBLOCK",
E 19
E 17
			sblock.fs_interleave);
D 16
		if (reply("SET TO DEFAULT") == 1) {
			sblock.fs_interleave = 1;
E 16
I 16
		sblock.fs_interleave = 1;
D 17
D 18
		if (reply("SET TO DEFAULT") == 1)
E 18
I 18
		if (preen)
			printf(" (FIXED)\n");
D 23
		if (preen || reply("SET TO DEFAULT") == 1)
E 23
I 23
		if (preen || reply("SET TO DEFAULT") == 1) {
E 23
E 18
E 17
I 17
D 19
		if (preen)
			printf(" (FIXED)\n");
		if (preen || reply("SET TO DEFAULT") == 1)
E 19
E 17
E 16
			sbdirty();
I 23
			dirty(&asblk);
		}
E 23
D 16
		}
E 16
	}
	if (sblock.fs_npsect < sblock.fs_nsect) {
D 17
D 18
		pfatal("IMPOSSIBLE NPSECT=%d IN SUPERBLOCK",
E 18
I 18
		pwarn("IMPOSSIBLE NPSECT=%d IN SUPERBLOCK",
E 18
E 17
I 17
D 19
		pwarn("IMPOSSIBLE NPSECT=%d IN SUPERBLOCK",
E 19
E 17
			sblock.fs_npsect);
D 16
		if (reply("SET TO DEFAULT") == 1) {
			sblock.fs_npsect = sblock.fs_nsect;
E 16
I 16
		sblock.fs_npsect = sblock.fs_nsect;
I 17
D 19
		if (preen)
			printf(" (FIXED)\n");
		if (preen || reply("SET TO DEFAULT") == 1)
E 19
E 17
D 17
D 18
		if (reply("SET TO DEFAULT") == 1)
E 18
I 18
		if (preen)
			printf(" (FIXED)\n");
D 23
		if (preen || reply("SET TO DEFAULT") == 1)
E 23
I 23
		if (preen || reply("SET TO DEFAULT") == 1) {
E 23
E 18
E 17
E 16
			sbdirty();
I 23
			dirty(&asblk);
		}
E 23
D 16
		}
E 16
	}
I 23
D 24
	if (sblock.fs_postblformat == FS_42POSTBLFMT) {
		pwarn("OLD FILE SYSTEM FORMAT\n");
		if (!preen && reply("CONVERT TO NEW FILE SYSTEM FORMAT") == 1) {
			cvtflag++;
E 24
I 24
	if (cvtflag) {
		if (sblock.fs_postblformat == FS_42POSTBLFMT) {
			/*
			 * Requested to convert from old format to new format
			 */
			if (preen)
				pwarn("CONVERTING TO NEW FILE SYSTEM FORMAT\n");
			else if (!reply("CONVERT TO NEW FILE SYSTEM FORMAT"))
				return(0);
E 24
			sblock.fs_postblformat = FS_DYNAMICPOSTBLFMT;
			sblock.fs_nrpos = 8;
			sblock.fs_postbloff =
			    (char *)(&sblock.fs_opostbl[0][0]) -
			    (char *)(&sblock.fs_link);
			sblock.fs_rotbloff = &sblock.fs_space[0] -
			    (u_char *)(&sblock.fs_link);
			/*
			 * Planning now for future expansion.
			 */
#			if (BYTE_ORDER == BIG_ENDIAN)
				sblock.fs_qbmask.val[0] = 0;
				sblock.fs_qbmask.val[1] = ~sblock.fs_bmask;
				sblock.fs_qfmask.val[0] = 0;
				sblock.fs_qfmask.val[1] = ~sblock.fs_fmask;
#			endif /* BIG_ENDIAN */
#			if (BYTE_ORDER == LITTLE_ENDIAN)
				sblock.fs_qbmask.val[0] = ~sblock.fs_bmask;
				sblock.fs_qbmask.val[1] = 0;
				sblock.fs_qfmask.val[0] = ~sblock.fs_fmask;
				sblock.fs_qfmask.val[1] = 0;
#			endif /* LITTLE_ENDIAN */
			sbdirty();
			dirty(&asblk);
I 24
		} else if (sblock.fs_postblformat == FS_DYNAMICPOSTBLFMT) {
			/*
			 * Requested to convert from new format to old format
			 */
			if (sblock.fs_nrpos != 8 || sblock.fs_ipg > 2048 ||
			    sblock.fs_cpg > 32 || sblock.fs_cpc > 16) {
				printf(
				"PARAMETERS OF CURRENT FILE SYSTEM DO NOT\n\t");
				errexit(
				"ALLOW CONVERSION TO OLD FILE SYSTEM FORMAT\n");
			}
			if (preen)
				pwarn("CONVERTING TO OLD FILE SYSTEM FORMAT\n");
			else if (!reply("CONVERT TO OLD FILE SYSTEM FORMAT"))
				return(0);
			sblock.fs_postblformat = FS_42POSTBLFMT;
			sbdirty();
			dirty(&asblk);
		} else {
			errexit("UNKNOWN FILE SYSTEM FORMAT\n");
E 24
		}
D 24
	} else if (cvtflag) {
		/*
		 * Requested to convert from new format to old format
		 */
		if (sblock.fs_nrpos != 8 || sblock.fs_ipg > 2048 ||
		    sblock.fs_cpg > 32) {
			printf("PARAMETERS OF CURRENT FILE SYSTEM DO NOT\n\t");
			errexit("ALLOW CONVERSION TO OLD FILE SYSTEM FORMAT\n");
		}
		pwarn("CONVERTING TO OLD FILE SYSTEM FORMAT\n");
		sblock.fs_postblformat = FS_42POSTBLFMT;
		sbdirty();
		dirty(&asblk);
E 24
	}
	if (asblk.b_dirty) {
		bcopy((char *)&sblock, (char *)&altsblock, sblock.fs_sbsize);
		flush(&dfile, &asblk);
	}
E 23
E 11
	/*
E 9
D 10
	 * Set all possible fields that could differ, then do check
	 * of whole super block against an alternate super block.
	 * When an alternate super-block is specified this check is skipped.
	 */
	if (bflag)
		goto sbok;
D 4
	if (getblk(&asblk, cgsblock(&sblock, sblock.fs_ncg - 1),
	    sblock.fs_sbsize) == 0)
E 4
I 4
	getblk(&asblk, cgsblock(&sblock, sblock.fs_ncg - 1), sblock.fs_sbsize);
	if (asblk.b_errs != NULL)
E 4
		return (0);
	altsblock.fs_link = sblock.fs_link;
	altsblock.fs_rlink = sblock.fs_rlink;
	altsblock.fs_time = sblock.fs_time;
	altsblock.fs_cstotal = sblock.fs_cstotal;
	altsblock.fs_cgrotor = sblock.fs_cgrotor;
	altsblock.fs_fmod = sblock.fs_fmod;
	altsblock.fs_clean = sblock.fs_clean;
	altsblock.fs_ronly = sblock.fs_ronly;
	altsblock.fs_flags = sblock.fs_flags;
	altsblock.fs_maxcontig = sblock.fs_maxcontig;
	altsblock.fs_minfree = sblock.fs_minfree;
I 8
	altsblock.fs_optim = sblock.fs_optim;
E 8
	altsblock.fs_rotdelay = sblock.fs_rotdelay;
	altsblock.fs_maxbpg = sblock.fs_maxbpg;
	bcopy((char *)sblock.fs_csp, (char *)altsblock.fs_csp,
		sizeof sblock.fs_csp);
	bcopy((char *)sblock.fs_fsmnt, (char *)altsblock.fs_fsmnt,
		sizeof sblock.fs_fsmnt);
	if (bcmp((char *)&sblock, (char *)&altsblock, (int)sblock.fs_sbsize))
		{ badsb("TRASHED VALUES IN SUPER BLOCK"); return (0); }
sbok:
	fmax = sblock.fs_size;
	imax = sblock.fs_ncg * sblock.fs_ipg;
D 3
	n_bad = cgsblock(&sblock, 0); /* boot block plus dedicated sblock */
E 3
	/*
E 10
	 * read in the summary info.
	 */
I 22
	asked = 0;
E 22
	for (i = 0, j = 0; i < sblock.fs_cssize; i += sblock.fs_bsize, j++) {
		size = sblock.fs_cssize - i < sblock.fs_bsize ?
		    sblock.fs_cssize - i : sblock.fs_bsize;
		sblock.fs_csp[j] = (struct csum *)calloc(1, (unsigned)size);
		if (bread(&dfile, (char *)sblock.fs_csp[j],
		    fsbtodb(&sblock, sblock.fs_csaddr + j * sblock.fs_frag),
D 4
		    size) == 0)
E 4
I 4
D 22
		    size) != 0)
E 4
			return (0);
E 22
I 22
		    size) != 0 && !asked) {
			pfatal("BAD SUMMARY INFORMATION");
			if (reply("CONTINUE") == 0)
				errexit("");
			asked++;
		}
E 22
	}
	/*
	 * allocate and initialize the necessary maps
	 */
	bmapsz = roundup(howmany(fmax, NBBY), sizeof(short));
	blockmap = calloc((unsigned)bmapsz, sizeof (char));
	if (blockmap == NULL) {
		printf("cannot alloc %d bytes for blockmap\n", bmapsz);
D 3
		goto badsb;
	}
	freemap = calloc((unsigned)bmapsz, sizeof (char));
	if (freemap == NULL) {
		printf("cannot alloc %d bytes for freemap\n", bmapsz);
E 3
		goto badsb;
	}
	statemap = calloc((unsigned)(imax + 1), sizeof(char));
	if (statemap == NULL) {
		printf("cannot alloc %d bytes for statemap\n", imax + 1);
		goto badsb;
	}
	lncntp = (short *)calloc((unsigned)(imax + 1), sizeof(short));
	if (lncntp == NULL) {
		printf("cannot alloc %d bytes for lncntp\n", 
		    (imax + 1) * sizeof(short));
		goto badsb;
D 2
	}
	for (c = 0; c < sblock.fs_ncg; c++) {
		cgd = cgdmin(&sblock, c);
		if (c == 0) {
			d = cgbase(&sblock, c);
			cgd += howmany(sblock.fs_cssize, sblock.fs_fsize);
		} else
			d = cgsblock(&sblock, c);
		for (; d < cgd; d++)
			setbmap(d);
E 2
	}

I 25
	bufinit();
E 25
	return (1);

badsb:
	ckfini();
	return (0);
I 10
}

/*
 * Read in the super block and its summary info.
 */
readsb(listerr)
	int listerr;
{
D 23
	BUFAREA asblk;
I 18
D 20
	struct disklabel *getdisklabel(), *lp;
E 20
E 18
#	define altsblock asblk.b_un.b_fs
E 23
D 14
	daddr_t super = bflag ? bflag : SBLOCK;
E 14
I 14
D 20
	daddr_t super = bflag ? bflag * DEV_BSIZE : SBOFF;
E 20
I 20
	off_t sboff;
	daddr_t super = bflag ? bflag : SBOFF / dev_bsize;
E 20
E 14

D 23
	initbarea(&asblk);
E 23
I 13
D 14
	dev_bsize = DEV_BSIZE;
E 14
I 14
D 20
	dev_bsize = 1;
E 20
E 14
E 13
	if (bread(&dfile, (char *)&sblock, super, (long)SBSIZE) != 0)
		return (0);
	sblk.b_bno = super;
	sblk.b_size = SBSIZE;
	/*
	 * run a few consistency checks of the super block
	 */
	if (sblock.fs_magic != FS_MAGIC)
		{ badsb(listerr, "MAGIC NUMBER WRONG"); return (0); }
	if (sblock.fs_ncg < 1)
		{ badsb(listerr, "NCG OUT OF RANGE"); return (0); }
D 23
	if (sblock.fs_cpg < 1 || sblock.fs_cpg > MAXCPG)
E 23
I 23
	if (sblock.fs_cpg < 1)
E 23
		{ badsb(listerr, "CPG OUT OF RANGE"); return (0); }
	if (sblock.fs_ncg * sblock.fs_cpg < sblock.fs_ncyl ||
	    (sblock.fs_ncg - 1) * sblock.fs_cpg >= sblock.fs_ncyl)
		{ badsb(listerr, "NCYL LESS THAN NCG*CPG"); return (0); }
	if (sblock.fs_sbsize > SBSIZE)
		{ badsb(listerr, "SIZE PREPOSTEROUSLY LARGE"); return (0); }
	/*
I 20
	 * Compute block size that the filesystem is based on,
	 * according to fsbtodb, and adjust superblock block number
	 * so we can tell if this is an alternate later.
	 */
D 23
	if (sblock.fs_dbsize && secsize == 0)
		secsize = sblock.fs_dbsize;
E 23
	super *= dev_bsize;
	dev_bsize = sblock.fs_fsize / fsbtodb(&sblock, 1);
	sblk.b_bno = super / dev_bsize;
	/*
E 20
	 * Set all possible fields that could differ, then do check
	 * of whole super block against an alternate super block.
	 * When an alternate super-block is specified this check is skipped.
	 */
I 23
	getblk(&asblk, cgsblock(&sblock, sblock.fs_ncg - 1), sblock.fs_sbsize);
	if (asblk.b_errs != NULL)
		return (0);
E 23
I 13
D 20
	dev_bsize = sblock.fs_fsize / fsbtodb(&sblock, 1);
I 18
	if (lp = getdisklabel((char *)NULL, dfile.rfdes))
		secsize = lp->d_secsize;
	else
		secsize = dev_bsize;
E 18
D 14
	sblk.b_bno = sblk.b_bno * DEV_BSIZE / dev_bsize;
E 14
I 14
	sblk.b_bno = sblk.b_bno / dev_bsize;
E 14
E 13
	if (bflag)
E 20
I 20
	if (bflag) {
		havesb = 1;
E 20
		return (1);
I 20
	}
E 20
D 23
	getblk(&asblk, cgsblock(&sblock, sblock.fs_ncg - 1), sblock.fs_sbsize);
	if (asblk.b_errs != NULL)
		return (0);
I 15
	altsblock.fs_fsbtodb = sblock.fs_fsbtodb;
I 20
	altsblock.fs_dbsize = sblock.fs_dbsize;
E 23
E 20
E 15
	altsblock.fs_link = sblock.fs_link;
	altsblock.fs_rlink = sblock.fs_rlink;
	altsblock.fs_time = sblock.fs_time;
	altsblock.fs_cstotal = sblock.fs_cstotal;
	altsblock.fs_cgrotor = sblock.fs_cgrotor;
	altsblock.fs_fmod = sblock.fs_fmod;
	altsblock.fs_clean = sblock.fs_clean;
	altsblock.fs_ronly = sblock.fs_ronly;
	altsblock.fs_flags = sblock.fs_flags;
	altsblock.fs_maxcontig = sblock.fs_maxcontig;
	altsblock.fs_minfree = sblock.fs_minfree;
	altsblock.fs_optim = sblock.fs_optim;
	altsblock.fs_rotdelay = sblock.fs_rotdelay;
	altsblock.fs_maxbpg = sblock.fs_maxbpg;
I 12
D 23
	altsblock.fs_npsect = sblock.fs_npsect;
	altsblock.fs_interleave = sblock.fs_interleave;
E 23
E 12
	bcopy((char *)sblock.fs_csp, (char *)altsblock.fs_csp,
		sizeof sblock.fs_csp);
	bcopy((char *)sblock.fs_fsmnt, (char *)altsblock.fs_fsmnt,
		sizeof sblock.fs_fsmnt);
D 15
	if (bcmp((char *)&sblock, (char *)&altsblock, (int)sblock.fs_sbsize))
		{ badsb(listerr, "TRASHED VALUES IN SUPER BLOCK"); return (0); }
E 15
I 15
	bcopy((char *)sblock.fs_sparecon, (char *)altsblock.fs_sparecon,
		sizeof sblock.fs_sparecon);
I 23
	/*
	 * The following should not have to be copied.
	 */
	altsblock.fs_fsbtodb = sblock.fs_fsbtodb;
	altsblock.fs_interleave = sblock.fs_interleave;
	altsblock.fs_npsect = sblock.fs_npsect;
	altsblock.fs_nrpos = sblock.fs_nrpos;
E 23
	if (bcmp((char *)&sblock, (char *)&altsblock, (int)sblock.fs_sbsize)) {
		badsb(listerr,
		"VALUES IN SUPER BLOCK DISAGREE WITH THOSE IN FIRST ALTERNATE");
		return (0);
	}
I 20
	havesb = 1;
E 20
E 15
	return (1);
E 10
D 23
#	undef altsblock
E 23
}

D 10
badsb(s)
E 10
I 10
badsb(listerr, s)
	int listerr;
E 10
	char *s;
{

I 10
	if (!listerr)
		return;
E 10
	if (preen)
		printf("%s: ", devname);
D 10
	printf("BAD SUPER BLOCK: %s\n", s);
	pwarn("USE -b OPTION TO FSCK TO SPECIFY LOCATION OF AN ALTERNATE\n");
	pfatal("SUPER-BLOCK TO SUPPLY NEEDED INFORMATION; SEE fsck(8).\n");
E 10
I 10
	pfatal("BAD SUPER BLOCK: %s\n", s);
E 10
}
I 10

/*
 * Calculate a prototype superblock based on information in the disk label.
 * When done the cgsblock macro can be calculated and the fs_ncg field
 * can be used. Do NOT attempt to use other macros without verifying that
 * their needed information is available!
 */
calcsb(dev, devfd, fs)
	char *dev;
	int devfd;
	register struct fs *fs;
{
	register struct disklabel *lp;
	register struct partition *pp;
	register char *cp;
D 18
	struct disklabel *getdisklabel();
E 18
	int i;
I 21
	struct disklabel *getdisklabel();
E 21

	cp = index(dev, '\0') - 1;
	if (cp == (char *)-1 || (*cp < 'a' || *cp > 'h') && !isdigit(*cp)) {
		pfatal("%s: CANNOT FIGURE OUT FILE SYSTEM PARTITION\n", dev);
		return (0);
	}
	lp = getdisklabel(dev, devfd);
	if (isdigit(*cp))
		pp = &lp->d_partitions[0];
	else
		pp = &lp->d_partitions[*cp - 'a'];
	if (pp->p_fstype != FS_BSDFFS) {
D 20
		pfatal("%s: NOT FORMATTED AS A BSD FILE SYSTEM (%s)\n",
E 20
I 20
		pfatal("%s: NOT LABELED AS A BSD FILE SYSTEM (%s)\n",
E 20
			dev, pp->p_fstype < FSMAXTYPES ?
			fstypenames[pp->p_fstype] : "unknown");
		return (0);
	}
	bzero(fs, sizeof(struct fs));
	fs->fs_fsize = pp->p_fsize;
	fs->fs_frag = pp->p_frag;
	fs->fs_cpg = pp->p_cpg;
	fs->fs_size = pp->p_size;
	fs->fs_ntrak = lp->d_ntracks;
	fs->fs_nsect = lp->d_nsectors;
	fs->fs_spc = lp->d_secpercyl;
	fs->fs_nspf = fs->fs_fsize / lp->d_secsize;
	fs->fs_sblkno = roundup(
		howmany(lp->d_bbsize + lp->d_sbsize, fs->fs_fsize),
		fs->fs_frag);
	fs->fs_cgmask = 0xffffffff;
	for (i = fs->fs_ntrak; i > 1; i >>= 1)
		fs->fs_cgmask <<= 1;
	if (!POWEROF2(fs->fs_ntrak))
		fs->fs_cgmask <<= 1;
	fs->fs_cgoffset = roundup(
		howmany(fs->fs_nsect, NSPF(fs)), fs->fs_frag);
	fs->fs_fpg = (fs->fs_cpg * fs->fs_spc) / NSPF(fs);
	fs->fs_ncg = howmany(fs->fs_size / fs->fs_spc, fs->fs_cpg);
	for (fs->fs_fsbtodb = 0, i = NSPF(fs); i > 1; i >>= 1)
		fs->fs_fsbtodb++;
I 20
	dev_bsize = lp->d_secsize;
E 20
	return (1);
}

D 15
#ifdef byioctl
E 15
struct disklabel *
getdisklabel(s, fd)
	char *s;
	int	fd;
{
	static struct disklabel lab;

	if (ioctl(fd, DIOCGDINFO, (char *)&lab) < 0) {
I 18
		if (s == NULL)
			return ((struct disklabel *)NULL);
E 18
I 15
		pwarn("");
E 15
		perror("ioctl (GDINFO)");
D 15
		fatal("%s: can't read disk label", s);
E 15
I 15
		errexit("%s: can't read disk label", s);
E 15
	}
	return (&lab);
}
D 15
#else byioctl
char specname[64];
char boot[BBSIZE];

struct disklabel *
getdisklabel(s, fd)
	char *s;
	int	fd;
{
	char *cp;
	u_long magic = htonl(DISKMAGIC);
	register struct disklabel *lp;
	int cfd;

	/*
	 * Make name for 'c' partition.
	 */
	strcpy(specname, s);
	cp = specname + strlen(specname) - 1;
	if (!isdigit(*cp))
		*cp = 'c';
	cfd = open(specname, O_RDONLY);
	if (cfd < 0) {
		perror(specname);
		exit(2);
	}

	if (read(cfd, boot, BBSIZE) < BBSIZE) {
		perror(specname);
		exit(2);
	}
	close(cfd);
	for (lp = (struct disklabel *)(boot + LABELOFFSET);
	    lp <= (struct disklabel *)(boot + BBSIZE -
	    sizeof(struct disklabel));
	    lp = (struct disklabel *)((char *)lp + 128))
		if (lp->d_magic == magic && lp->d_magic2 == magic)
			break;
	if (lp > (struct disklabel *)(boot + BBSIZE -
	    sizeof(struct disklabel)) ||
	    lp->d_magic != magic || lp->d_magic2 != magic ||
	    dkcksum(lp) != 0) {
		printf("Bad pack magic number %s\n",
			"(label is damaged, or pack is unlabeled)");
		exit(1);
	}
#if ENDIAN != BIG
	swablabel(lp);
#endif
	return (lp);
}
#endif byioctl
E 15
E 10
E 1
