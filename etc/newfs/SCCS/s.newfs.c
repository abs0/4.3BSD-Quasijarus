h08202
s 00025/00002/00605
d D 6.16 88/05/01 23:23:48 mckusick 36 35
c add -n flag to allow specification of number of rotational positions;
c set the default to be the old NRPOS of 8
e
s 00001/00001/00606
d D 6.15 87/12/07 17:06:08 mckusick 35 34
c fix error message
e
s 00002/00002/00605
d D 6.14 87/10/22 11:12:52 bostic 34 33
c ANSI C; sprintf now returns an int.
e
s 00002/00002/00605
d D 6.13 87/10/01 22:45:13 mckusick 33 32
c cannot initialize maxbpg until bsize is set
e
s 00001/00001/00606
d D 6.12 87/10/01 19:25:14 bostic 32 31
c pointer typo
e
s 00055/00010/00552
d D 6.11 87/10/01 12:45:35 mckusick 31 30
c add remainder of tunable parameters (-a, -d, -e); 
c rename old -a to -x, old -d to -u so above can have same values as `tunefs'
e
s 00002/00000/00560
d D 6.10 87/09/10 00:37:27 mckusick 30 29
c need to know if cpg is specified
e
s 00045/00002/00515
d D 6.9 87/06/23 12:15:54 karels 29 28
c backward compat for unlabelled disks
e
s 00001/00000/00516
d D 6.8 87/05/08 10:59:43 sam 28 27
c missing definition for vax (from jim mckie)
e
s 00003/00003/00513
d D 6.7 87/04/07 20:15:01 karels 27 26
c use fsize, bsize from label if no args
e
s 00008/00008/00508
d D 6.6 87/04/02 11:42:13 karels 26 25
c print correct arg, more tolerant of omissions
e
s 00042/00073/00474
d D 6.5 87/03/29 15:58:13 karels 25 24
c update for new label ioctls, get bbsize/sbsize from label;
c tahoe hacks to use DEV_BSIZE
e
s 00016/00018/00531
d D 6.4 87/02/02 22:42:09 karels 24 23
c rm byte-swapping
e
s 00007/00007/00542
d D 6.3 87/01/15 21:23:11 mckusick 23 22
c reorder usage to correspond to manual page
e
s 00063/00006/00486
d D 6.2 87/01/13 19:33:22 mckusick 22 21
c add trackskew, interleave, npsect, headswitch, and trackseek
c use first three to more completely calculate rotational position
e
s 00307/00198/00186
d D 6.1 87/01/13 12:32:11 mckusick 21 20
c merge mkfs and newfs; add support for disk labels
e
s 00004/00000/00380
d D 5.3 86/10/13 15:06:15 sam 20 19
c make installboot conditional on BOOTDIR and that conditional on vax
e
s 00023/00000/00357
d D 5.2 85/09/11 23:20:46 mckusick 19 18
c allow specification of optimization preference
e
s 00014/00002/00343
d D 5.1 85/05/28 15:02:49 dist 18 17
c Add copyright
e
s 00011/00001/00334
d D 4.14 84/08/16 14:04:54 mckusick 17 15
c add -N flag to print out stats on file system without creating it
e
s 00011/00001/00334
d R 4.14 84/08/16 11:28:09 mckusick 16 15
c add -N flag to print out stats on file system without creating it
e
s 00001/00001/00334
d D 4.13 84/04/18 09:22:14 ralph 15 14
c pass the exit code from system() correctly.
e
s 00016/00000/00319
d D 4.12 83/08/28 15:56:28 mckusick 14 13
c add -i option to specify "number of bytes per inode"
e
s 00001/00001/00318
d D 4.11 83/08/01 12:25:05 sam 13 12
c what a hack, but it will suffice for now
e
s 00009/00010/00310
d D 4.10 83/07/22 15:03:55 mckusick 12 11
c strengthen up code for converting disk names to raw disk names
e
s 00002/00001/00318
d D 4.9 83/07/06 22:59:27 sam 11 10
c check for raw device name correctly according to kre
e
s 00001/00001/00318
d D 4.8 83/07/02 00:04:07 sam 10 9
c include fiox
e
s 00008/00003/00311
d D 4.7 83/05/08 21:18:13 helge 9 8
c new -n (noboot) flag, fix allowing zero reserved space
e
s 00004/00002/00310
d D 4.6 83/02/20 19:40:25 sam 8 7
c grab boot blocks out of /usr/mdec
e
s 00048/00012/00264
d D 4.5 83/02/15 16:07:16 sam 7 6
c add minfree and rps; change name to newfs
e
s 00004/00004/00272
d D 4.4 83/02/14 14:45:59 sam 6 5
c fix usage
e
s 00011/00007/00265
d D 4.3 83/02/10 18:59:31 sam 5 3
c use raw device
e
s 00007/00007/00265
d R 4.3 83/02/10 18:54:19 sam 4 3
c use raw device
e
s 00003/00007/00269
d D 4.2 83/02/08 14:57:49 sam 3 1
c enable dangerous code
e
s 00000/00004/00272
d R 4.2 83/02/08 14:54:01 sam 2 1
c enable dangerous code
e
s 00276/00000/00000
d D 4.1 83/02/08 14:50:22 sam 1 0
c date and time created 83/02/08 14:50:22 by sam
e
u
U
t
T
I 18
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 18
I 1
#ifndef lint
D 18
static char sccsid[] = "%W% %G%";
#endif
E 18
I 18
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 18

/*
D 7
 * makefs: friendly front end to mkfs
E 7
I 7
 * newfs: friendly front end to mkfs
E 7
 */
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/fs.h>
I 10
#include <sys/dir.h>
I 21
#include <sys/ioctl.h>
#include <sys/disklabel.h>
#include <sys/file.h>
E 21
E 10

#include <stdio.h>
D 10
#include <dir.h>
E 10
D 21
#include <disktab.h>
E 21
I 21
#include <ctype.h>
E 21

I 29
#define COMPAT			/* allow non-labeled disks */

E 29
I 20
D 21
#ifdef vax
E 20
I 8
#define	BOOTDIR	"/usr/mdec"	/* directory for boot blocks */
I 20
#endif
E 21
I 21
/*
 * The following two constants set the default block and fragment sizes.
 * Both constants must be a power of 2 and meet the following constraints:
 *	MINBSIZE <= DESBLKSIZE <= MAXBSIZE
 *	sectorsize <= DESFRAGSIZE <= DESBLKSIZE
 *	DESBLKSIZE / DESFRAGSIZE <= 8
 */
#define	DFL_FRAGSIZE	1024
#define	DFL_BLKSIZE	8192
E 21
E 20

I 17
D 21
int	Nflag;			/* run mkfs without writing file system */
E 17
E 8
int	verbose;		/* show mkfs line before exec */
I 9
int	noboot;			/* do not fill boot blocks */
E 21
I 21
/*
D 36
 * Cylinder groups may have up to MAXCPG cylinders. The actual
E 36
I 36
 * Cylinder groups may have up to many cylinders. The actual
E 36
 * number used depends upon how much information can be stored
D 36
 * on a single cylinder. The default is to used 16 cylinders
E 36
I 36
 * on a single cylinder. The default is to use 16 cylinders
E 36
 * per group.
 */
#define	DESCPG		16	/* desired fs_cpg */

/*
 * MINFREE gives the minimum acceptable percentage of file system
 * blocks which may be free. If the freelist drops below this level
 * only the superuser may continue to allocate blocks. This may
 * be set to 0 if no reserve of free blocks is deemed necessary,
 * however throughput drops by fifty percent if the file system
 * is run at between 90% and 100% full; thus the default value of
 * fs_minfree is 10%. With 10% free space, fragmentation is not a
 * problem, so we choose to optimize for time.
 */
#define MINFREE		10
#define DEFAULTOPT	FS_OPTTIME

/*
 * ROTDELAY gives the minimum number of milliseconds to initiate
 * another disk transfer on the same cylinder. It is used in
 * determining the rotationally optimal layout for disk blocks
 * within a file; the default of fs_rotdelay is 4ms.
 */
#define ROTDELAY	4

/*
 * MAXCONTIG sets the default for the maximum number of blocks
 * that may be allocated sequentially. Since UNIX drivers are
 * not capable of scheduling multi-block transfers, this defaults
 * to 1 (ie no contiguous blocks are allocated).
 */
#define MAXCONTIG	1

/*
I 31
 * MAXBLKPG determines the maximum number of data blocks which are
 * placed in a single cylinder group. The default is one indirect
 * block worth of data blocks.
 */
#define MAXBLKPG(bsize)	((bsize) / sizeof(daddr_t))

/*
E 31
 * Each file system has a number of inodes statically allocated.
 * We allocate one inode slot per NBPI bytes, expecting this
 * to be far more than we will ever need.
 */
#define	NBPI		2048

I 36
/*
 * For each cylinder we keep track of the availability of blocks at different
 * rotational positions, so that we can lay out the data to be picked
 * up with minimum rotational latency.  NRPOS is the default number of
 * rotational positions that we distinguish.  With NRPOS of 8 the resolution
 * of our summary information is 2ms for a typical 3600 rpm drive.
 */
#define	NRPOS		8	/* number distinct rotational positions */


E 36
int	Nflag;			/* run without writing file system */
E 21
E 9
int	fssize;			/* file system size */
D 21
int	fsize;			/* fragment size */
int	bsize;			/* block size */
E 21
int	ntracks;		/* # tracks/cylinder */
int	nsectors;		/* # sectors/track */
I 21
D 22
int	nspares = -1;		/* spare sectors per cylinder */
E 22
I 22
int	nphyssectors;		/* # sectors/track including spares */
E 22
int	secpercyl;		/* sectors per cylinder */
I 22
int	trackspares = -1;	/* spare sectors per track */
int	cylspares = -1;		/* spare sectors per cylinder */
E 22
E 21
int	sectorsize;		/* bytes/sector */
I 25
#ifdef tahoe
int	realsectorsize;		/* bytes/sector in hardware */
#endif
E 25
D 21
int	cpg;			/* cylinders/cylinder group */
I 7
D 9
int	minfree;		/* free space threshold */
E 9
I 9
int	minfree = -1;		/* free space threshold */
I 19
int	opt;			/* optimization preference (space or time) */
E 21
E 19
E 9
int	rpm;			/* revolutions/minute of drive */
I 22
int	interleave;		/* hardware sector interleave */
int	trackskew = -1;		/* sector 0 skew, per track */
int	headswitch;		/* head switch time, usec */
int	trackseek;		/* track-to-track seek, usec */
E 22
I 14
D 21
int	density;		/* number of bytes per inode */
E 21
I 21
D 27
int	fsize = DFL_FRAGSIZE;	/* fragment size */
int	bsize = DFL_BLKSIZE;	/* block size */
E 27
I 27
int	fsize = 0;		/* fragment size */
int	bsize = 0;		/* block size */
E 27
int	cpg = DESCPG;		/* cylinders/cylinder group */
I 30
int	cpgflg;			/* cylinders/cylinder group flag was given */
E 30
int	minfree = MINFREE;	/* free space threshold */
int	opt = DEFAULTOPT;	/* optimization preference (space or time) */
int	density = NBPI;		/* number of bytes per inode */
int	maxcontig = MAXCONTIG;	/* max contiguous blocks to allocate */
int	rotdelay = ROTDELAY;	/* rotational delay between blocks */
I 31
int	maxbpg;			/* maximum blocks per file in a cyl group */
I 36
int	nrpos = NRPOS;		/* # of distinguished rotational positions */
E 36
E 31
I 25
int	bbsize = BBSIZE;	/* boot block size */
int	sbsize = SBSIZE;	/* superblock size */
I 29
#ifdef COMPAT
int	unlabelled;
#endif
E 29
E 25
E 21
E 14
E 7

D 21
char	*av[20];		/* argv array and buffers for exec */
char	a2[20];
char	a3[20];
char	a4[20];
char	a5[20];
char	a6[20];
char	a7[20];
I 7
char	a8[20];
char	a9[20];
I 14
char	a10[20];
E 21
E 14
E 7
char	device[MAXPATHLEN];
D 21
char	cmd[BUFSIZ];
E 21

I 21
extern	int errno;
E 21
char	*index();
char	*rindex();
D 34
char	*sprintf();
E 34

main(argc, argv)
I 12
	int argc;
E 12
	char *argv[];
{
	char *cp, *special;
D 21
	register struct disktab *dp;
E 21
	register struct partition *pp;
I 21
	register struct disklabel *lp;
	struct disklabel *getdisklabel();
	struct partition oldpartition;
E 21
	struct stat st;
I 21
	int fsi, fso;
E 21
	register int i;
	int status;

	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		for (cp = &argv[0][1]; *cp; cp++)
			switch (*cp) {

D 21
			case 'v':
				verbose++;
				break;

E 21
I 17
			case 'N':
				Nflag++;
D 21
				/* fall through to */

E 17
I 9
			case 'n':
				noboot++;
E 21
				break;

E 9
D 21
			case 's':
E 21
I 21
			case 'S':
E 21
				if (argc < 1)
D 21
					fatal("-s: missing file system size");
E 21
I 21
					fatal("-S: missing sector size");
E 21
				argc--, argv++;
D 21
				fssize = atoi(*argv);
				if (fssize < 0)
					fatal("%s: bad file system size",
						*argv);
E 21
I 21
				sectorsize = atoi(*argv);
				if (sectorsize <= 0)
					fatal("%s: bad sector size", *argv);
E 21
				goto next;

D 21
			case 't':
E 21
I 21
			case 'a':
E 21
				if (argc < 1)
D 21
					fatal("-t: missing track total");
E 21
I 21
D 31
					fatal("-a: spare sectors per cylinder");
E 31
I 31
					fatal("-a: missing max contiguous blocks\n");
E 31
E 21
				argc--, argv++;
D 21
				ntracks = atoi(*argv);
				if (ntracks < 0)
					fatal("%s: bad total tracks", *argv);
E 21
I 21
D 22
				nspares = atoi(*argv);
				if (nspares < 0)
E 22
I 22
D 31
				cylspares = atoi(*argv);
				if (cylspares < 0)
E 22
					fatal("%s: bad spare sectors per cylinder", *argv);
E 31
I 31
				maxcontig = atoi(*argv);
				if (maxcontig <= 0)
					fatal("%s: bad max contiguous blocks\n",
						*argv);
E 31
E 21
				goto next;

I 19
D 21
			case 'o':
				if (argc < 1)
					fatal("-o: missing optimization preference");
				argc--, argv++;
				if (strcmp(*argv, "space") == 0)
					opt = FS_OPTSPACE;
				else if (strcmp(*argv, "time") == 0)
					opt = FS_OPTTIME;
				else
					fatal("%s: bad optimization preference %s",
					    *argv,
					    "(options are `space' or `time')");
				goto next;

E 21
E 19
			case 'b':
				if (argc < 1)
					fatal("-b: missing block size");
				argc--, argv++;
				bsize = atoi(*argv);
D 21
				if (bsize < 0 || bsize < MINBSIZE)
E 21
I 21
				if (bsize < MINBSIZE)
E 21
					fatal("%s: bad block size", *argv);
				goto next;

D 21
			case 'f':
E 21
I 21
			case 'c':
E 21
				if (argc < 1)
D 21
					fatal("-f: missing frag size");
E 21
I 21
					fatal("-c: missing cylinders/group");
E 21
				argc--, argv++;
D 21
				fsize = atoi(*argv);
				if (fsize < 0)
					fatal("%s: bad frag size", *argv);
E 21
I 21
				cpg = atoi(*argv);
				if (cpg <= 0)
					fatal("%s: bad cylinders/group", *argv);
I 30
				cpgflg++;
E 30
E 21
				goto next;

D 21
			case 'S':
E 21
I 21
			case 'd':
E 21
				if (argc < 1)
D 21
					fatal("-S: missing sector size");
E 21
I 21
D 31
					fatal("-d: missing sectors/track");
E 31
I 31
					fatal("-d: missing rotational delay\n");
E 31
E 21
				argc--, argv++;
D 21
				sectorsize = atoi(*argv);
				if (sectorsize < 0)
					fatal("%s: bad sector size", *argv);
E 21
I 21
D 31
				nsectors = atoi(*argv);
				if (nsectors <= 0)
					fatal("%s: bad sectors/track", *argv);
E 31
I 31
				rotdelay = atoi(*argv);
				if (rotdelay < 0)
					fatal("%s: bad rotational delay\n",
						*argv);
E 31
E 21
				goto next;

I 31
			case 'e':
				if (argc < 1)
					fatal("-e: missing blocks pre file in a cyl group\n");
				argc--, argv++;
				maxbpg = atoi(*argv);
				if (maxbpg <= 0)
					fatal("%s: bad blocks per file in a cyl group\n",
						*argv);
				goto next;

E 31
D 21
			case 'c':
E 21
I 21
			case 'f':
E 21
				if (argc < 1)
D 21
					fatal("-c: missing cylinders/group");
E 21
I 21
					fatal("-f: missing frag size");
E 21
				argc--, argv++;
D 21
				cpg = atoi(*argv);
				if (cpg < 0)
					fatal("%s: bad cylinders/group", *argv);
E 21
I 21
				fsize = atoi(*argv);
				if (fsize <= 0)
					fatal("%s: bad frag size", *argv);
E 21
				goto next;

I 21
			case 'i':
				if (argc < 1)
					fatal("-i: missing bytes per inode\n");
				argc--, argv++;
				density = atoi(*argv);
				if (density <= 0)
					fatal("%s: bad bytes per inode\n",
						*argv);
				goto next;

I 22
			case 'k':
				if (argc < 1)
					fatal("-k: track skew");
				argc--, argv++;
				trackskew = atoi(*argv);
				if (trackskew < 0)
					fatal("%s: bad track skew", *argv);
				goto next;

			case 'l':
				if (argc < 1)
					fatal("-l: interleave");
				argc--, argv++;
				interleave = atoi(*argv);
				if (interleave <= 0)
					fatal("%s: bad interleave", *argv);
				goto next;

E 22
E 21
I 7
			case 'm':
				if (argc < 1)
					fatal("-m: missing free space %%\n");
				argc--, argv++;
				minfree = atoi(*argv);
				if (minfree < 0 || minfree > 99)
					fatal("%s: bad free space %%\n",
						*argv);
				goto next;

I 36
			case 'n':
				if (argc < 1)
					fatal("-n: missing rotational layout count\n");
				argc--, argv++;
				nrpos = atoi(*argv);
				if (nrpos <= 0)
					fatal("%s: bad rotational layout count\n",
						*argv);
				goto next;

E 36
I 21
			case 'o':
				if (argc < 1)
					fatal("-o: missing optimization preference");
				argc--, argv++;
				if (strcmp(*argv, "space") == 0)
					opt = FS_OPTSPACE;
				else if (strcmp(*argv, "time") == 0)
					opt = FS_OPTTIME;
				else
					fatal("%s: bad optimization preference %s",
					    *argv,
					    "(options are `space' or `time')");
				goto next;

I 22
			case 'p':
				if (argc < 1)
					fatal("-p: spare sectors per track");
				argc--, argv++;
				trackspares = atoi(*argv);
				if (trackspares < 0)
					fatal("%s: bad spare sectors per track", *argv);
				goto next;

E 22
E 21
			case 'r':
				if (argc < 1)
					fatal("-r: missing revs/minute\n");
				argc--, argv++;
				rpm = atoi(*argv);
D 21
				if (rpm < 0)
E 21
I 21
				if (rpm <= 0)
E 21
					fatal("%s: bad revs/minute\n", *argv);
				goto next;

I 14
D 21
			case 'i':
E 21
I 21
			case 's':
E 21
				if (argc < 1)
D 21
					fatal("-i: missing bytes per inode\n");
E 21
I 21
					fatal("-s: missing file system size");
E 21
				argc--, argv++;
D 21
				density = atoi(*argv);
				if (density < 0)
					fatal("%s: bad bytes per inode\n",
E 21
I 21
				fssize = atoi(*argv);
				if (fssize <= 0)
					fatal("%s: bad file system size",
E 21
						*argv);
				goto next;

I 21
			case 't':
				if (argc < 1)
					fatal("-t: missing track total");
				argc--, argv++;
				ntracks = atoi(*argv);
				if (ntracks <= 0)
					fatal("%s: bad total tracks", *argv);
				goto next;

I 31
			case 'u':
				if (argc < 1)
					fatal("-u: missing sectors/track");
				argc--, argv++;
				nsectors = atoi(*argv);
				if (nsectors <= 0)
					fatal("%s: bad sectors/track", *argv);
				goto next;

			case 'x':
				if (argc < 1)
					fatal("-x: spare sectors per cylinder");
				argc--, argv++;
				cylspares = atoi(*argv);
				if (cylspares < 0)
					fatal("%s: bad spare sectors per cylinder", *argv);
				goto next;

E 31
E 21
E 14
E 7
			default:
D 32
				fatal("-%c: unknown flag", cp);
E 32
I 32
				fatal("-%c: unknown flag", *cp);
E 32
			}
next:
		argc--, argv++;
	}
D 21
	if (argc < 2) {
D 7
		fprintf(stderr, "usage: makefs [ -v ] [ mkfs-options ] %s\n",
E 7
I 7
		fprintf(stderr, "usage: newfs [ -v ] [ mkfs-options ] %s\n",
E 7
			"special-device device-type");
		fprintf(stderr, "where mkfs-options are:\n");
E 21
I 21
	if (argc < 1) {
I 29
#ifdef COMPAT
		fprintf(stderr,
		"usage: newfs [ fsoptions ] special-device [device-type]\n");
#else
E 29
		fprintf(stderr, "usage: newfs [ fsoptions ] special-device\n");
I 29
#endif
E 29
		fprintf(stderr, "where fsoptions are:\n");
E 21
I 17
		fprintf(stderr, "\t-N do not create file system, %s\n",
			"just print out parameters");
E 17
D 5
		fprintf(stderr, "-s sectors/track\n");
		fprintf(stderr, "-b block-size\n");
		fprintf(stderr, "-f frag-size\n");
		fprintf(stderr, "-t tracks/cylinder\n");
		fprintf(stderr, "-c cylinders/group\n");
		fprintf(stderr, "-S sector-size\n");
E 5
I 5
D 6
		fprintf(stderr, "\t-s sectors/track\n");
		fprintf(stderr, "\t-b block-size\n");
		fprintf(stderr, "\t-f frag-size\n");
E 6
I 6
D 23
		fprintf(stderr, "\t-s file system size (sectors)\n");
E 23
		fprintf(stderr, "\t-b block size\n");
		fprintf(stderr, "\t-f frag size\n");
I 21
D 23
		fprintf(stderr, "\t-d sectors/track\n");
E 21
E 6
		fprintf(stderr, "\t-t tracks/cylinder\n");
		fprintf(stderr, "\t-c cylinders/group\n");
E 23
I 7
		fprintf(stderr, "\t-m minimum free space %%\n");
I 19
		fprintf(stderr, "\t-o optimization preference %s\n",
			"(`space' or `time')");
I 31
		fprintf(stderr, "\t-a maximum contiguous blocks\n");
		fprintf(stderr, "\t-d rotational delay between %s\n",
			"contiguous blocks");
		fprintf(stderr, "\t-e maximum blocks per file in a %s\n",
			"cylinder group");
E 31
E 19
D 23
		fprintf(stderr, "\t-r revolutions/minute\n");
E 23
E 7
D 6
		fprintf(stderr, "\t-S sector-size\n");
E 6
I 6
D 21
		fprintf(stderr, "\t-S sector size\n");
E 21
I 14
		fprintf(stderr, "\t-i number of bytes per inode\n");
I 23
		fprintf(stderr, "\t-c cylinders/group\n");
I 36
		fprintf(stderr, "\t-n number of distinguished %s\n",
			"rotational positions");
E 36
		fprintf(stderr, "\t-s file system size (sectors)\n");
		fprintf(stderr, "\t-r revolutions/minute\n");
E 23
I 21
		fprintf(stderr, "\t-S sector size\n");
I 22
D 23
		fprintf(stderr, "\t-l hardware sector interleave\n");
		fprintf(stderr, "\t-k sector 0 skew, per track\n");
E 23
I 23
D 31
		fprintf(stderr, "\t-d sectors/track\n");
E 31
I 31
		fprintf(stderr, "\t-u sectors/track\n");
E 31
		fprintf(stderr, "\t-t tracks/cylinder\n");
E 23
		fprintf(stderr, "\t-p spare sectors per track\n");
E 22
D 31
		fprintf(stderr, "\t-a spare sectors per cylinder\n");
E 31
I 31
		fprintf(stderr, "\t-x spare sectors per cylinder\n");
E 31
I 23
		fprintf(stderr, "\t-l hardware sector interleave\n");
		fprintf(stderr, "\t-k sector 0 skew, per track\n");
E 23
E 21
E 14
E 6
E 5
		exit(1);
	}
I 31
D 33
	if (maxbpg == 0)
		maxbpg = MAXBLKPG(bsize);
E 33
E 31
	special = argv[0];
D 12
again:
E 12
I 12
	cp = rindex(special, '/');
	if (cp != 0)
		special = cp + 1;
D 13
	if (*special == 'r')
E 13
I 13
	if (*special == 'r' && special[1] != 'a' && special[1] != 'b')
E 13
		special++;
D 34
	special = sprintf(device, "/dev/r%s", special);
E 34
I 34
	(void)sprintf(device, "/dev/r%s", special);
	special = device;
E 34
E 12
D 21
	if (stat(special, &st) < 0) {
E 21
I 21
	if (!Nflag) {
		fso = open(special, O_WRONLY);
		if (fso < 0) {
			perror(special);
			exit(1);
		}
	} else
		fso = -1;
	fsi = open(special, O_RDONLY);
	if (fsi < 0) {
		perror(special);
		exit(1);
	}
	if (fstat(fsi, &st) < 0) {
E 21
D 12
		if (*special != '/') {
D 5
			special = sprintf(device, "/dev/%s", argv[0]);
E 5
I 5
			if (*special == 'r')
				special++;
			special = sprintf(device, "/dev/r%s", special);
E 5
			goto again;
		}
E 12
D 7
		fprintf(stderr, "makefs: "); perror(special);
E 7
I 7
		fprintf(stderr, "newfs: "); perror(special);
E 7
		exit(2);
	}
D 12
	if ((st.st_mode & S_IFMT) != S_IFBLK &&
	    (st.st_mode & S_IFMT) != S_IFCHR)
		fatal("%s: not a block or character device", special);
E 12
I 12
	if ((st.st_mode & S_IFMT) != S_IFCHR)
		fatal("%s: not a character device", special);
E 12
D 21
	dp = getdiskbyname(argv[1]);
	if (dp == 0)
		fatal("%s: unknown disk type", argv[1]);
E 21
	cp = index(argv[0], '\0') - 1;
D 21
	if (cp == 0 || *cp < 'a' || *cp > 'h')
E 21
I 21
	if (cp == 0 || (*cp < 'a' || *cp > 'h') && !isdigit(*cp))
E 21
		fatal("%s: can't figure out file system partition", argv[0]);
I 29
#ifdef COMPAT
	lp = getdisklabel(special, fsi, argv[1]);
#else
E 29
D 21
	pp = &dp->d_partitions[*cp - 'a'];
	if (fssize == 0) {
E 21
I 21
	lp = getdisklabel(special, fsi);
I 29
#endif
E 29
	if (isdigit(*cp))
		pp = &lp->d_partitions[0];
	else
		pp = &lp->d_partitions[*cp - 'a'];
	if (pp->p_size == 0)
		fatal("%s: `%c' partition is unavailable", argv[0], *cp);
	if (fssize == 0)
E 21
		fssize = pp->p_size;
D 21
		if (fssize < 0)
			fatal("%s: no default size for `%c' partition",
				argv[1], *cp);
E 21
I 21
	if (fssize > pp->p_size)
	       fatal("%s: maximum file system size on the `%c' partition is %d",
			argv[0], *cp, pp->p_size);
	if (rpm == 0) {
		rpm = lp->d_rpm;
		if (rpm <= 0)
D 26
			fatal("%s: no default rpm", argv[1]);
E 26
I 26
			rpm = 3600;
E 26
E 21
	}
D 21
	if (nsectors == 0) {
		nsectors = dp->d_nsectors;
		if (nsectors < 0)
			fatal("%s: no default #sectors/track", argv[1]);
	}
E 21
	if (ntracks == 0) {
D 21
		ntracks = dp->d_ntracks;
		if (ntracks < 0)
E 21
I 21
		ntracks = lp->d_ntracks;
		if (ntracks <= 0)
E 21
D 26
			fatal("%s: no default #tracks", argv[1]);
E 26
I 26
			fatal("%s: no default #tracks", argv[0]);
E 26
	}
I 21
	if (nsectors == 0) {
		nsectors = lp->d_nsectors;
		if (nsectors <= 0)
D 26
			fatal("%s: no default #sectors/track", argv[1]);
E 26
I 26
			fatal("%s: no default #sectors/track", argv[0]);
E 26
	}
E 21
	if (sectorsize == 0) {
D 21
		sectorsize = dp->d_secsize;
		if (sectorsize < 0)
E 21
I 21
		sectorsize = lp->d_secsize;
		if (sectorsize <= 0)
E 21
D 26
			fatal("%s: no default sector size", argv[1]);
E 26
I 26
			fatal("%s: no default sector size", argv[0]);
E 26
	}
I 22
	if (trackskew == -1) {
		trackskew = lp->d_trackskew;
		if (trackskew < 0)
D 26
			fatal("%s: no default track skew", argv[1]);
E 26
I 26
			trackskew = 0;
E 26
	}
	if (interleave == 0) {
		interleave = lp->d_interleave;
		if (interleave <= 0)
D 26
			fatal("%s: no default interleave", argv[1]);
E 26
I 26
			interleave = 1;
E 26
	}
E 22
D 21
	if (bsize == 0) {
		bsize = pp->p_bsize;
		if (bsize < 0)
			fatal("%s: no default block size for `%c' partition",
				argv[1], *cp);
	}
E 21
	if (fsize == 0) {
		fsize = pp->p_fsize;
D 21
		if (fsize < 0)
			fatal("%s: no default frag size for `%c' partition",
				argv[1], *cp);
E 21
I 21
		if (fsize <= 0)
			fsize = MAX(DFL_FRAGSIZE, lp->d_secsize);
E 21
	}
I 7
D 21
	if (rpm == 0) {
		rpm = dp->d_rpm;
		if (rpm < 0)
			fatal("%s: no default revolutions/minute value",
				argv[1]);
E 21
I 21
	if (bsize == 0) {
		bsize = pp->p_frag * pp->p_fsize;
		if (bsize <= 0)
			bsize = MIN(DFL_BLKSIZE, 8 * fsize);
E 21
	}
I 14
D 21
	if (density <= 0)
		density = 2048;
E 14
D 9
	if (minfree == 0)
E 9
I 9
	if (minfree < 0)
E 9
		minfree = 10;
E 21
I 19
	if (minfree < 10 && opt != FS_OPTSPACE) {
D 21
		fprintf(stderr, "setting optimization for space ");
		fprintf(stderr, "with minfree less than 10%\n");
E 21
I 21
		fprintf(stderr, "Warning: changing optimization to space ");
		fprintf(stderr, "because minfree is less than 10%%\n");
E 21
		opt = FS_OPTSPACE;
	}
E 19
D 21
	if (cpg == 0)
		cpg = 16;
E 7
	i = 0;
I 17
	if (Nflag)
		av[i++] = "-N";
	av[i++] = special;
E 17
	av[i++] = sprintf(a2, "%d", fssize);
	av[i++] = sprintf(a3, "%d", nsectors);
	av[i++] = sprintf(a4, "%d", ntracks);
	av[i++] = sprintf(a5, "%d", bsize);
	av[i++] = sprintf(a6, "%d", fsize);
D 7
	if (cpg != 0)
		av[i++] = sprintf(a7, "%d", cpg);
E 7
I 7
	av[i++] = sprintf(a7, "%d", cpg);
	av[i++] = sprintf(a8, "%d", minfree);
	av[i++] = sprintf(a9, "%d", rpm / 60);
I 14
	av[i++] = sprintf(a10, "%d", density);
I 19
	av[i++] = opt == FS_OPTSPACE ? "s" : "t";
E 19
E 14
E 7
	av[i++] = 0;
D 17
	sprintf(cmd, "/etc/mkfs %s", special);
E 17
I 17
	strcpy(cmd, "/etc/mkfs");
E 17
	for (i = 0; av[i] != 0; i++) {
		strcat(cmd, " ");
		strcat(cmd, av[i]);
E 21
I 21
D 22
	if (nspares == -1)
		nspares = lp->d_sparespercyl;
	secpercyl = nsectors * ntracks - nspares;
E 22
I 22
	if (trackspares == -1) {
		trackspares = lp->d_sparespertrack;
		if (trackspares < 0)
D 26
			fatal("%s: no default spares/track", argv[1]);
E 26
I 26
			trackspares = 0;
E 26
	}
	nphyssectors = nsectors + trackspares;
	if (cylspares == -1) {
		cylspares = lp->d_sparespercyl;
		if (cylspares < 0)
D 26
			fatal("%s: no default spares/cylinder", argv[1]);
E 26
I 26
			cylspares = 0;
E 26
	}
	secpercyl = nsectors * ntracks - cylspares;
E 22
	if (secpercyl != lp->d_secpercyl)
		fprintf(stderr, "%s (%d) %s (%d)\n",
			"Warning: calculated sectors per cylinder", secpercyl,
			"disagrees with disk label", lp->d_secpercyl);
I 33
	if (maxbpg == 0)
		maxbpg = MAXBLKPG(bsize);
E 33
I 22
	headswitch = lp->d_headswitch;
	trackseek = lp->d_trkseek;
I 25
	bbsize = lp->d_bbsize;
	sbsize = lp->d_sbsize;
E 25
E 22
	oldpartition = *pp;
I 25
#ifdef tahoe
	realsectorsize = sectorsize;
D 27
	if (sectorsize != DEV_BSIZE) {
E 27
I 27
	if (sectorsize != DEV_BSIZE) {		/* XXX */
E 27
		int secperblk = DEV_BSIZE / sectorsize;

		sectorsize = DEV_BSIZE;
		nsectors /= secperblk;
		nphyssectors /= secperblk;
		secpercyl /= secperblk;
		fssize /= secperblk;
		pp->p_size /= secperblk;
	}
#endif
E 25
	mkfs(pp, special, fsi, fso);
I 25
#ifdef tahoe
	if (realsectorsize != DEV_BSIZE)
		pp->p_size *= DEV_BSIZE / realsectorsize;
#endif
E 25
	if (!Nflag && bcmp(pp, &oldpartition, sizeof(oldpartition)))
		rewritelabel(special, fso, lp);
	exit(0);
}

I 29
#ifdef COMPAT
E 29
D 25
#ifdef byioctl
E 25
struct disklabel *
I 29
getdisklabel(s, fd, type)
	char *s, *type;
	int fd;
{
	static struct disklabel lab;
	struct disklabel *getdiskbyname();

	if (ioctl(fd, DIOCGDINFO, (char *)&lab) < 0) {
		if (type == NULL) {
			perror("ioctl (GDINFO)");
			fatal(
		   "%s: can't read disk label; disk type must be specified", s);
		}
		unlabelled++;
		return (getdiskbyname(type));
	}
	return (&lab);
}
#else
struct disklabel *
E 29
getdisklabel(s, fd)
	char *s;
D 29
	int	fd;
E 29
I 29
	int fd;
E 29
{
	static struct disklabel lab;

	if (ioctl(fd, DIOCGDINFO, (char *)&lab) < 0) {
		perror("ioctl (GDINFO)");
		fatal("%s: can't read disk label", s);
E 21
	}
D 21
	if (verbose)
		printf("%s\n", cmd);
D 3
#ifdef notdef
E 3
	if (status = system(cmd))
D 15
		exit(status);
E 15
I 15
		exit(status >> 8);
E 15
D 3
#endif
E 3
D 9
	if (*cp == 'a') {
E 9
I 9
	if (*cp == 'a' && !noboot) {
E 9
		char type[3];
I 11
		struct stat sb;
E 21
I 21
	return (&lab);
}
I 29
#endif
E 29
E 21
E 11

D 21
		cp = rindex(special, '/');
		if (cp == NULL)
			fatal("%s: can't figure out disk type from name",
				special);
I 5
D 11
		if (cp[1] == 'r')
E 11
I 11
		if (stat(special, &sb) >= 0 && (sb.st_mode & S_IFMT) == S_IFCHR)
E 11
			cp++;
E 5
		type[0] = *++cp;
		type[1] = *++cp;
		type[2] = '\0';
		installboot(special, type);
E 21
I 21
rewritelabel(s, fd, lp)
	char *s;
	int fd;
	register struct disklabel *lp;
{

I 29
#ifdef COMPAT
	if (unlabelled)
		return;
#endif
E 29
	lp->d_checksum = 0;
	lp->d_checksum = dkcksum(lp);
	if (ioctl(fd, DIOCWDINFO, (char *)lp) < 0) {
D 35
		perror("ioctl (GWINFO)");
E 35
I 35
		perror("ioctl (WDINFO)");
E 35
		fatal("%s: can't rewrite disk label", s);
E 21
	}
D 21
	exit(0);
E 21
D 25
}
I 21
#else byioctl
char specname[64];
char boot[BBSIZE];
E 21

D 21
installboot(dev, type)
	char *dev, *type;
E 21
I 21
struct disklabel *
getdisklabel(s, fd)
	char *s;
	int	fd;
E 21
{
I 20
D 21
#ifdef BOOTDIR
E 20
	int fd;
	char bootblock[MAXPATHLEN], standalonecode[MAXPATHLEN];
	char bootimage[BBSIZE];
E 21
I 21
	char *cp;
	u_long magic = htonl(DISKMAGIC);
	register struct disklabel *lp;
	int cfd;
E 21

D 8
	sprintf(bootblock, "/sys/mdec/%sboot", type);
	sprintf(standalonecode, "/sys/stand/boot%s", type);
E 8
I 8
D 21
	sprintf(bootblock, "%s/%sboot", BOOTDIR, type);
	sprintf(standalonecode, "%s/boot%s", BOOTDIR, type);
E 8
	if (verbose) {
		printf("installing boot code\n");
		printf("sector 0 boot = %s\n", bootblock);
		printf("1st level boot = %s\n", standalonecode);
E 21
I 21
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
E 21
	}
D 21
	fd = open(bootblock, 0);
	if (fd < 0) {
D 7
		fprintf(stderr, "makefs: "); perror(bootblock);
E 7
I 7
		fprintf(stderr, "newfs: "); perror(bootblock);
E 7
		exit(1);
	}
	if (read(fd, bootimage, DEV_BSIZE) < 0) {
D 7
		fprintf(stderr, "makefs: "); perror(bootblock);
E 7
I 7
		fprintf(stderr, "newfs: "); perror(bootblock);
E 21
I 21

	if (read(cfd, boot, BBSIZE) < BBSIZE) {
		perror(specname);
E 21
E 7
		exit(2);
	}
D 21
	close(fd);
	fd = open(standalonecode, 0);
	if (fd < 0) {
D 7
		fprintf(stderr, "makefs: "); perror(standalonecode);
E 7
I 7
		fprintf(stderr, "newfs: "); perror(standalonecode);
E 21
I 21
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
		fprintf(stderr,
	"Bad pack magic number (label is damaged, or pack is unlabeled)\n");
E 21
E 7
		exit(1);
	}
D 21
	if (read(fd, &bootimage[DEV_BSIZE], BBSIZE - DEV_BSIZE) < 0) {
D 7
		fprintf(stderr, "makefs: "); perror(standalonecode);
E 7
I 7
		fprintf(stderr, "newfs: "); perror(standalonecode);
E 21
I 21
D 24
#if ENDIAN != BIG
	swablabel(lp);
#endif
E 24
	return (lp);
}

rewritelabel(s, fd, lp)
	char *s;
	int fd;
	register struct disklabel *lp;
{
D 24
	daddr_t alt;
	register i;
	int secsize, cfd;
E 24
I 24
	int cfd;
E 24

D 24
	secsize = lp->d_secsize;
	alt = lp->d_ncylinders * lp->d_secpercyl - lp->d_nsectors;
#if ENDIAN != BIG
	swablabel(lp);
#endif
E 24
	lp->d_checksum = 0;
	lp->d_checksum = dkcksum(lp);
	cfd = open(specname, O_WRONLY);
	if (cfd < 0) {
		perror(specname);
E 21
E 7
		exit(2);
	}
D 21
	close(fd);
D 3
#ifdef notdef
	fd = open(special, 1);
E 3
I 3
	fd = open(dev, 1);
E 3
	if (fd < 0) {
D 3
		fprintf(stderr, "makefs: "); perror(special);
E 3
I 3
D 7
		fprintf(stderr, "makefs: "); perror(dev);
E 7
I 7
		fprintf(stderr, "newfs: "); perror(dev);
E 7
E 3
		exit(1);
	}
	if (write(fd, bootimage, BBSIZE) != BBSIZE) {
D 3
		fprintf(stderr, "makefs: "); perror(special);
E 3
I 3
D 7
		fprintf(stderr, "makefs: "); perror(dev);
E 7
I 7
		fprintf(stderr, "newfs: "); perror(dev);
E 21
I 21
	lseek(cfd, (off_t)0, L_SET);
	if (write(cfd, boot, BBSIZE) < BBSIZE) {
		perror(specname);
E 21
E 7
E 3
		exit(2);
	}
E 25
D 21
	close(fd);
I 20
#endif
E 21
I 21
D 24
	for (i = 1; i < 11 && i < lp->d_nsectors; i += 2) {
		lseek(cfd, (off_t)(alt + i) * secsize, L_SET);
		if (write(cfd, boot, secsize) < secsize) {
			int oerrno = errno;
			fprintf(stderr, "alternate label %d ", i/2);
			errno = oerrno;
			perror("write");
E 24
I 24
#if vax
	if (lp->d_type == DTYPE_SMD && lp->d_flags & D_BADSECT) {
		register i;
I 25
		int cfd;
E 25
		daddr_t alt;
I 25
		char specname[64];
		char blk[1024];
I 28
		char *cp;
E 28
E 25

I 25
		/*
		 * Make name for 'c' partition.
		 */
		strcpy(specname, s);
		cp = specname + strlen(specname) - 1;
		if (!isdigit(*cp))
			*cp = 'c';
		cfd = open(specname, O_WRONLY);
		if (cfd < 0) {
			perror(specname);
			exit(2);
		}
		bzero(blk, sizeof(blk));
		*(struct disklabel *)(blk + LABELOFFSET) = *lp;
E 25
		alt = lp->d_ncylinders * lp->d_secpercyl - lp->d_nsectors;
		for (i = 1; i < 11 && i < lp->d_nsectors; i += 2) {
D 29
			lseek(cfd, (off_t)(alt + i) * lp->d_secsize, L_SET);
E 29
I 29
			if (lseek(cfd, (off_t)(alt + i) * lp->d_secsize, L_SET) == -1) {
				perror("lseek to badsector area");
				exit(30);
			}
E 29
D 25
			if (write(cfd, boot, lp->d_secsize) < lp->d_secsize) {
E 25
I 25
			if (write(cfd, blk, lp->d_secsize) < lp->d_secsize) {
E 25
				int oerrno = errno;
				fprintf(stderr, "alternate label %d ", i/2);
				errno = oerrno;
				perror("write");
			}
E 24
		}
	}
I 24
#endif
E 24
D 25
	close(cfd);
E 25
E 21
E 20
D 3
#endif
E 3
}
I 21
D 25
#endif byioctl
E 25
E 21

/*VARARGS*/
fatal(fmt, arg1, arg2)
	char *fmt;
{

D 7
	fprintf(stderr, "makefs: ");
E 7
I 7
	fprintf(stderr, "newfs: ");
E 7
	fprintf(stderr, fmt, arg1, arg2);
	putc('\n', stderr);
	exit(10);
}
E 1
