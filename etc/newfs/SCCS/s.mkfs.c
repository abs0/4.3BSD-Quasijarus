h09748
s 00001/00001/00990
d D 6.9 88/07/08 16:28:54 mckusick 51 50
c 4.3BSD-tahoe/etc/6 (from Chris Torek <chris@gyre.umd.edu>)
e
s 00001/00001/00990
d D 6.8 88/06/01 18:27:50 bostic 50 49
c new _doprnt doesn't support %[A-Z]
e
s 00169/00118/00822
d D 6.7 88/05/01 23:34:19 mckusick 49 48
c change cylinder group format to contain dynamic arrays
e
s 00001/00001/00939
d D 6.6 88/04/24 15:11:20 bostic 48 47
c fix for ANSI C; isblock didn't always return a value
e
s 00002/00008/00938
d D 6.5 87/10/01 12:45:30 mckusick 47 46
c add remainder of tunable parameters (-a, -d, -e); 
c rename old -a to -x, old -d to -u so above can have same values as `tunefs'
e
s 00155/00067/00791
d D 6.4 87/09/10 00:39:44 mckusick 46 45
c reduce cpg to insure that requested bytes per inode are available
e
s 00006/00004/00852
d D 6.3 87/03/29 15:58:07 karels 45 44
c update for new label ioctls, get bbsize/sbsize from label;
c tahoe hacks to use DEV_BSIZE
e
s 00025/00015/00831
d D 6.2 87/01/13 19:33:27 mckusick 44 43
c add trackskew, interleave, npsect, headswitch, and trackseek
c use first three to more completely calculate rotational position
e
s 00092/00224/00754
d D 6.1 87/01/13 12:32:23 mckusick 43 42
c merge mkfs and newfs; add support for disk labels
e
s 00017/00002/00961
d D 5.3 85/09/11 23:21:00 mckusick 42 41
c allow specification of optimization preference
e
s 00001/00002/00962
d D 5.2 85/07/05 14:02:20 mckusick 41 40
c roundup directory sizes
e
s 00014/00002/00950
d D 5.1 85/05/28 14:32:11 dist 40 39
c Add copyright
e
s 00000/00000/00952
d D 2.19 85/04/02 08:50:19 bloom 39 38
x 38
c Some people should look in the dictionary
e
s 00001/00001/00951
d D 2.18 85/03/24 17:08:20 mckusick 38 37
c spelling error in error message
e
s 00001/00001/00951
d D 2.17 85/03/24 11:08:55 bloom 37 36
c fix spelling error
e
s 00027/00010/00925
d D 2.16 84/08/16 11:30:31 mckusick 36 35
c add -N flag to print out stats on file system without creating it
e
s 00002/00002/00933
d D 2.15 83/08/01 18:45:45 mckusick 35 34
c fix calculation of initial block counts
e
s 00002/00002/00933
d D 2.14 83/07/04 17:40:53 mckusick 34 33
c change default rotational delay to 4ms
e
s 00003/00007/00932
d D 2.13 83/07/02 00:04:17 sam 33 32
c include fiox
e
s 00002/00000/00937
d D 2.12 83/05/25 16:18:48 mckusick 32 31
c add calculation of i_blocks
e
s 00012/00004/00925
d D 2.11 83/05/13 18:56:15 mckusick 31 30
c add optional nbpi to specify "number of bytes per inode" 
e
s 00005/00001/00924
d D 2.10 83/05/06 19:21:33 mckusick 30 29
c make sure that the whole file system is writable!
e
s 00001/00003/00924
d D 2.9 83/03/10 18:52:54 sam 29 28
c with all apologies ....
e
s 00019/00003/00908
d D 2.8 83/02/15 15:55:58 sam 28 27
c add rps and minfree arguments
e
s 00014/00012/00897
d D 2.7 83/01/02 15:19:34 mckusick 27 26
c add new and useful constants
e
s 00001/00001/00908
d D 2.6 82/10/03 18:07:09 mckusick 26 25
c fix bug which failed to create first super block back-up
e
s 00070/00002/00839
d D 2.5 82/09/25 23:49:09 mckusick 25 24
c add initialization comments; init for maxcontig and maxbpg
e
s 00014/00000/00827
d D 2.4 82/09/10 00:08:10 mckusick 24 23
c add ifdef STANDALONE for printf and bcopy
e
s 00009/00004/00818
d D 2.3 82/09/10 00:04:45 mckusick 23 22
c force clearing of unused portions of block maps
e
s 00093/00034/00729
d D 2.2 82/04/11 17:21:15 mckusick 22 21
c float the super block, reclaim redundant boot block space
e
s 00006/00000/00757
d D 2.1 82/04/08 15:45:30 mckusick 21 20
c merge into the new kernel
e
s 00001/00001/00756
d D 1.20 82/03/25 02:30:38 mckusick 20 19
c update to the current system
e
s 00020/00014/00737
d D 1.19 82/02/25 14:47:42 mckusic 19 18
c use speed-up macros in fs.h
e
s 00052/00012/00699
d D 1.18 82/02/21 16:18:58 mckusic 18 17
c conversion to flexable length directory names
e
s 00009/00002/00702
d D 1.17 82/01/23 16:58:29 mckusic 17 16
c make default fail only based on bsize
e
s 00010/00005/00694
d D 1.16 82/01/13 18:32:38 mckusic 16 15
c force cylinder groups to have a multiple of bsize blocks
e
s 00016/00016/00683
d D 1.15 82/01/12 22:20:32 mckusic 15 14
c change all macros taking "fs" to have it as their first argument
e
s 00005/00001/00694
d D 1.14 82/01/12 19:34:02 mckusic 14 13
c add cg_ctot to summarize cg_b
e
s 00086/00059/00609
d D 1.13 82/01/10 18:23:59 mckusic 13 12
c fix rotational layout code to work with disks with nsect % bsize != 0
e
s 00016/00006/00652
d D 1.12 82/01/06 23:32:50 mckusic 12 11
c incorporate fs.h -r1.10, and param.h -r1.8 reorganization
e
s 00283/00513/00375
d D 1.11 82/01/06 21:11:06 mckusic 11 10
c get rid of proto, allocate lost+found, reserve inode 1
c incorperate fs.h -r1.10, and param.h -r1.8
e
s 00260/00132/00628
d D 1.10 82/01/05 01:32:12 mckusic 10 9
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00028/00023/00732
d D 1.9 81/11/07 19:59:20 mckusic 9 8
c edit to incorperate -r1.6 reorganization of fs.h
e
s 00010/00000/00745
d D 1.8 81/10/29 00:36:30 mckusic 8 7
c put in optimal rotational block allocation
e
s 00008/00006/00737
d D 1.7 81/10/05 20:45:46 mckusic 7 6
c maintaining and using cg_frsum to do intelligent allocation of FRAGs
e
s 00021/00016/00722
d D 1.6 81/09/22 17:45:55 mckusic 6 5
c allow files and directories to have FRAGS as their final block
e
s 00002/00002/00736
d D 1.5 81/09/19 16:25:47 mckusic 5 4
c initial BSIZE only file system
e
s 00001/00000/00737
d D 1.4 81/08/29 14:43:45 mckusic 4 3
c add cg_irotor initialization
e
s 00000/00004/00737
d D 1.3 81/08/28 22:46:45 mckusic 3 2
c move bit op macros to param.h
e
s 00027/00075/00714
d D 1.2 81/08/28 21:21:47 mckusic 2 1
c put in new inode structure
e
s 00789/00000/00000
d D 1.1 81/08/26 23:47:31 mckusick 1 0
c date and time created 81/08/26 23:47:31 by mckusick
e
u
U
t
T
I 40
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 40
I 33
#ifndef lint
E 33
I 1
D 40
static	char *sccsid = "%W% (Berkeley) %G%";
I 33
#endif
E 40
I 40
D 43
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 43
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 40
E 33

D 49
/*
 * make file system for cylinder-group style file systems
D 43
 *
D 11
 * usage: mkfs fs proto
D 10
 * or: mkfs size [ nsect ntrak cpg ]
E 10
I 10
 * or: mkfs size [ bsize frag nsect ntrak cpg ]
E 11
I 11
D 31
 * usage: mkfs special size [ nsect ntrak bsize fsize cpg ]
E 31
I 31
D 36
 * usage: mkfs special size [ nsect ntrak bsize fsize cpg minfree rps nbpi ]
E 36
I 36
D 42
 * usage: mkfs -N special size [ nsect ntrak bsize fsize cpg minfree rps nbpi ]
E 42
I 42
 * usage:
 *    mkfs -N special size [ nsect ntrak bsize fsize cpg minfree rps nbpi opt ]
E 43
E 42
E 36
E 31
E 11
E 10
 */

E 49
I 25
D 43
/*
 * The following constants set the defaults used for the number
 * of sectors (fs_nsect), and number of tracks (fs_ntrak).
 */
#define DFLNSECT	32
#define DFLNTRAK	16

/*
 * The following two constants set the default block and fragment sizes.
 * Both constants must be a power of 2 and meet the following constraints:
 *	MINBSIZE <= DESBLKSIZE <= MAXBSIZE
 *	DEV_BSIZE <= DESFRAGSIZE <= DESBLKSIZE
 *	DESBLKSIZE / DESFRAGSIZE <= 8
 */
#define DESBLKSIZE	8192
#define DESFRAGSIZE	1024

/*
 * Cylinder groups may have up to MAXCPG cylinders. The actual
 * number used depends upon how much information can be stored
 * on a single cylinder. The default is to used 16 cylinders
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
D 42
 * fs_minfree is 10%.
E 42
I 42
 * fs_minfree is 10%. With 10% free space, fragmentation is not a
 * problem, so we choose to optimize for time.
E 42
 */
#define MINFREE		10
I 42
#define DEFAULTOPT	FS_OPTTIME
E 42

/*
 * ROTDELAY gives the minimum number of milliseconds to initiate
 * another disk transfer on the same cylinder. It is used in
 * determining the rotationally optimal layout for disk blocks
D 34
 * within a file; the default of fs_rotdelay is 2ms.
E 34
I 34
 * within a file; the default of fs_rotdelay is 4ms.
E 34
 */
D 34
#define ROTDELAY	2
E 34
I 34
#define ROTDELAY	4
E 34

/*
 * MAXCONTIG sets the default for the maximum number of blocks
 * that may be allocated sequentially. Since UNIX drivers are
 * not capable of scheduling multi-block transfers, this defaults
 * to 1 (ie no contiguous blocks are allocated).
 */
#define MAXCONTIG	1

/*
 * MAXBLKPG determines the maximum number of data blocks which are
 * placed in a single cylinder group. This is currently a function
 * of the block and fragment size of the file system.
 */
#define MAXBLKPG(fs)	((fs)->fs_fsize / sizeof(daddr_t))

/*
 * Each file system has a number of inodes statically allocated.
 * We allocate one inode slot per NBPI bytes, expecting this
 * to be far more than we will ever need.
 */
#define	NBPI		2048

I 28
/*
 * Disks are assumed to rotate at 60HZ, unless otherwise specified.
 */
#define	DEFHZ		60

E 43
E 28
E 25
D 10
#define	NDIRECT	(BSIZE/sizeof(struct direct))
E 10
I 10
D 11
#define	NDIRECT(fs)	((fs)->fs_bsize/sizeof(struct direct))
E 10
#define	MAXFN	500

E 11
D 3
#define	setbit(a,i)	((a)[(i)/NBBY] |= 1<<((i)%NBBY))
#define	clrbit(a,i)	((a)[(i)/NBBY] &= ~(1<<((i)%NBBY)))
#define	isset(a,i)	((a)[(i)/NBBY] & (1<<((i)%NBBY)))

E 3
#ifndef STANDALONE
#include <stdio.h>
#include <a.out.h>
#endif

I 21
D 33
#ifndef SIMFS
E 33
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
D 33
#else
E 21
#include "../h/param.h"
D 2
#include "../h/ino.h"
E 2
#include "../h/inode.h"
#include "../h/fs.h"
I 21
#endif
E 21
D 18
#include "../h/dir.h"
E 18
I 18
D 23
#include <ndir.h>
E 23
I 23
#include <dir.h>
E 33
I 33
#include <sys/dir.h>
I 43
#include <sys/disklabel.h>
I 49
#include <machine/endian.h>
E 49
E 43
E 33
E 23
E 18

I 49
/*
 * make file system for cylinder-group style file systems
 */

/*
 * The size of a cylinder group is calculated by CGSIZE. The maximum size
 * is limited by the fact that cylinder groups are at most one block.
 * Its size is derived from the size of the maps maintained in the 
 * cylinder group and the (struct cg) size.
 */
#define CGSIZE(fs) \
    /* base cg */	(sizeof(struct cg) + \
    /* blktot size */	(fs)->fs_cpg * sizeof(long) + \
    /* blks size */	(fs)->fs_cpg * (fs)->fs_nrpos * sizeof(short) + \
    /* inode map */	howmany((fs)->fs_ipg, NBBY) + \
    /* block map */	howmany((fs)->fs_cpg * (fs)->fs_spc / NSPF(fs), NBBY))

/*
 * We limit the size of the inode map to be no more than a
 * third of the cylinder group space, since we must leave at
 * least an equal amount of space for the block map.
 *
 * N.B.: MAXIPG must be a multiple of INOPB(fs).
 */
#define MAXIPG(fs)	roundup((fs)->fs_bsize * NBBY / 3, INOPB(fs))

E 49
I 43
D 47
/*
 * MAXBLKPG determines the maximum number of data blocks which are
 * placed in a single cylinder group. This is currently a function
 * of the block and fragment size of the file system.
 */
#define MAXBLKPG(fs)	((fs)->fs_fsize / sizeof(daddr_t))

E 47
E 43
D 11
time_t	utime;
E 11
I 11
#define UMASK		0755
D 18
#define MAXNDIR		(MAXBSIZE / sizeof(struct direct))
E 18
I 12
#define MAXINOPB	(MAXBSIZE / sizeof(struct dinode))
E 12
#define POWEROF2(num)	(((num) & ((num) - 1)) == 0)
E 11

I 43
/*
 * variables set up by front end.
 */
D 44
int	Nflag;			/* run mkfs without writing file system */
int	fssize;			/* file system size */
int	ntracks;		/* # tracks/cylinder */
int	nsectors;		/* # sectors/track */
int     secpercyl;              /* sectors per cylinder */
int	sectorsize;		/* bytes/sector */
int	rpm;			/* revolutions/minute of drive */
int	fsize;			/* fragment size */
int	bsize;			/* block size */
int	cpg;			/* cylinders/cylinder group */
int	minfree;		/* free space threshold */
int	opt;			/* optimization preference (space or time) */
int	density;		/* number of bytes per inode */
int	maxcontig;		/* max contiguous blocks to allocate */
int	rotdelay;		/* rotational delay between blocks */
E 44
I 44
extern int	Nflag;		/* run mkfs without writing file system */
extern int	fssize;		/* file system size */
extern int	ntracks;	/* # tracks/cylinder */
extern int	nsectors;	/* # sectors/track */
extern int	nphyssectors;	/* # sectors/track including spares */
extern int	secpercyl;	/* sectors per cylinder */
extern int	sectorsize;	/* bytes/sector */
extern int	rpm;		/* revolutions/minute of drive */
extern int	interleave;	/* hardware sector interleave */
extern int	trackskew;	/* sector 0 skew, per track */
extern int	headswitch;	/* head switch time, usec */
extern int	trackseek;	/* track-to-track seek, usec */
extern int	fsize;		/* fragment size */
extern int	bsize;		/* block size */
extern int	cpg;		/* cylinders/cylinder group */
I 46
extern int	cpgflg;		/* cylinders/cylinder group flag was given */
E 46
extern int	minfree;	/* free space threshold */
extern int	opt;		/* optimization preference (space or time) */
extern int	density;	/* number of bytes per inode */
extern int	maxcontig;	/* max contiguous blocks to allocate */
extern int	rotdelay;	/* rotational delay between blocks */
I 47
extern int	maxbpg;		/* maximum blocks per file in a cyl group */
I 49
extern int	nrpos;		/* # of distinguished rotational positions */
E 49
E 47
I 45
extern int	bbsize;		/* boot block size */
extern int	sbsize;		/* superblock size */
E 45
E 44

E 43
D 11
#ifndef STANDALONE
FILE 	*fin;
#else
int	fin;
#endif

int	fsi;
int	fso;
char	*charp;
D 10
char	buf[BSIZE];
E 10
I 10
char	buf[MAXBSIZE];
E 10
#ifndef STANDALONE
struct exec head;
#endif
char	string[50];

E 11
union {
	struct fs fs;
D 10
	char pad[BSIZE];
E 10
I 10
D 49
	char pad[MAXBSIZE];
E 49
I 49
	char pad[SBSIZE];
E 49
E 10
} fsun;
#define	sblock	fsun.fs
struct	csum *fscs;

union {
	struct cg cg;
D 10
	char pad[BSIZE];
E 10
I 10
	char pad[MAXBSIZE];
E 10
} cgun;
#define	acg	cgun.cg

I 11
D 49
struct	dinode zino[MAXIPG];
E 49
I 49
struct dinode zino[MAXBSIZE / sizeof(struct dinode)];
E 49

E 11
D 10
#define	howmany(x, y)	(((x)+((y)-1))/(y))
#define	roundup(x, y)	((((x)+((y)-1))/(y))*(y))

E 10
D 43
char	*fsys;
E 43
I 43
int	fsi, fso;
E 43
D 11
char	*proto;
int	error;
ino_t	ino = ROOTINO - 1;
long	getnum();
E 11
I 11
time_t	utime;
D 43
int	fsi;
int	fso;
I 36
int	Nflag;
E 43
E 36
E 11
daddr_t	alloc();

D 11
struct	dinode zino[MAXIPG];

E 11
D 43
main(argc, argv)
D 10
char *argv[];
E 10
I 10
	int argc;
	char *argv[];
E 43
I 43
mkfs(pp, fsys, fi, fo)
	struct partition *pp;
	char *fsys;
	int fi, fo;
E 43
E 10
{
D 11
	int f, c;
	long i,n;
E 11
I 11
D 13
	long c, i, inos, fssize;
E 13
I 13
D 22
	long cylno, rpos, blk, i, inos, fssize;
E 22
I 22
D 43
	long cylno, rpos, blk, i, j, inos, fssize, warn = 0;
E 43
I 43
D 46
	long cylno, rpos, blk, i, j, warn = 0;
E 46
I 46
	register long i, mincpc, mincpg, inospercg;
	long cylno, rpos, blk, j, warn = 0;
	long used, mincpgcnt, bpcg;
	long mapcramped, inodecramped;
I 49
	long postblsize, rotblsize, totalsbsize;
E 49
E 46
E 43
E 22
E 13
E 11

D 11
	argc--, argv++;
E 11
#ifndef STANDALONE
I 11
D 43
	argc--, argv++;
I 36
	if (argv[0][0] == '-') {
		switch (argv[0][1]) {
		case 'N':
			Nflag++;
			break;
		default:
			printf("%s: unknown flag\n", &argv[0][1]);
			argc = 1;	/* force usage message */
			break;
		}
		argc--, argv++;
	}
E 43
E 36
E 11
	time(&utime);
D 11
	if(argc < 2) {
D 10
		printf("usage: mkfs sblock proto/size [ nsect ntrak cpg ]\n");
E 10
I 10
		printf("usage: mkfs sblock proto/size [ bsize frag nsect ntrak cpg ]\n");
E 11
I 11
D 43
	if (argc < 2) {
D 28
		printf("usage: mkfs special size [ nsect ntrak bsize fsize cpg ]\n");
E 28
I 28
D 31
		printf("usage: mkfs special size [ nsect ntrak bsize fsize cpg minfree rps ]\n");
E 31
I 31
D 36
		printf("usage: mkfs special size [ nsect ntrak bsize fsize cpg minfree rps nbpi ]\n");
E 36
I 36
		printf("usage: mkfs -N special size [ nsect ntrak bsize fsize cpg minfree rps nbpi ]\n");
E 36
E 31
E 28
E 11
E 10
		exit(1);
	}
	fsys = argv[0];
D 11
	proto = argv[1];
E 11
I 11
	fssize = atoi(argv[1]);
D 36
	fso = creat(fsys, 0666);
	if(fso < 0) {
		printf("%s: cannot create\n", fsys);
		exit(1);
E 36
I 36
	if (!Nflag) {
		fso = creat(fsys, 0666);
		if(fso < 0) {
			printf("%s: cannot create\n", fsys);
			exit(1);
		}
E 36
	}
	fsi = open(fsys, 0);
	if(fsi < 0) {
		printf("%s: cannot open\n", fsys);
		exit(1);
	}
E 11
#else
	{
		static char protos[60];
I 11
		char fsbuf[100];
E 11

		printf("file sys size: ");
		gets(protos);
D 11
		proto = protos;
	}
#endif
#ifdef STANDALONE
	{
		char fsbuf[100];

E 11
I 11
		fssize = atoi(protos);
E 11
		do {
			printf("file system: ");
			gets(fsbuf);
			fso = open(fsbuf, 1);
			fsi = open(fsbuf, 0);
		} while (fso < 0 || fsi < 0);
	}
D 11
	fin = NULL;
E 11
	argc = 0;
E 43
D 11
#else
	fso = creat(fsys, 0666);
	if(fso < 0) {
		printf("%s: cannot create\n", fsys);
E 11
I 11
#endif
I 43
	fsi = fi;
	fso = fo;
E 43
I 30
	/*
	 * Validate the given file system size.
	 * Verify that its last block can actually be accessed.
	 */
E 30
	if (fssize <= 0)
		printf("preposterous size %d\n", fssize), exit(1);
I 30
D 43
	wtfs(fssize - 1, DEV_BSIZE, (char *)&sblock);
E 43
I 43
	wtfs(fssize - 1, sectorsize, (char *)&sblock);
E 43
E 30
	/*
	 * collect and verify the sector and track info
	 */
D 43
	if (argc > 2)
		sblock.fs_nsect = atoi(argv[2]);
	else
		sblock.fs_nsect = DFLNSECT;
	if (argc > 3)
		sblock.fs_ntrak = atoi(argv[3]);
	else
		sblock.fs_ntrak = DFLNTRAK;
E 43
I 43
	sblock.fs_nsect = nsectors;
	sblock.fs_ntrak = ntracks;
E 43
	if (sblock.fs_ntrak <= 0)
		printf("preposterous ntrak %d\n", sblock.fs_ntrak), exit(1);
	if (sblock.fs_nsect <= 0)
		printf("preposterous nsect %d\n", sblock.fs_nsect), exit(1);
D 43
	sblock.fs_spc = sblock.fs_ntrak * sblock.fs_nsect;
E 43
I 43
D 46
	sblock.fs_spc = secpercyl;
E 46
E 43
	/*
	 * collect and verify the block and fragment sizes
	 */
D 43
	if (argc > 4)
		sblock.fs_bsize = atoi(argv[4]);
	else
D 25
		sblock.fs_bsize = MAXBSIZE;
E 25
I 25
		sblock.fs_bsize = DESBLKSIZE;
E 25
	if (argc > 5)
		sblock.fs_fsize = atoi(argv[5]);
	else
D 25
		sblock.fs_fsize = MAX(sblock.fs_bsize / DESFRAG, DEV_BSIZE);
E 25
I 25
		sblock.fs_fsize = DESFRAGSIZE;
E 43
I 43
	sblock.fs_bsize = bsize;
	sblock.fs_fsize = fsize;
E 43
E 25
	if (!POWEROF2(sblock.fs_bsize)) {
		printf("block size must be a power of 2, not %d\n",
		    sblock.fs_bsize);
E 11
		exit(1);
	}
D 11
	fsi = open(fsys, 0);
	if(fsi < 0) {
		printf("%s: cannot open\n", fsys);
E 11
I 11
	if (!POWEROF2(sblock.fs_fsize)) {
		printf("fragment size must be a power of 2, not %d\n",
		    sblock.fs_fsize);
E 11
		exit(1);
	}
D 11
	fin = fopen(proto, "r");
#endif
#ifndef STANDALONE
	if (fin != NULL) {
		getstr();
		f = open(string, 0);
		if (f < 0) {
			printf("%s: cannot open init\n", string);
			goto noinit;
		}
		read(f, (char *)&head, sizeof head);
		c = head.a_text + head.a_data;
D 10
		if (c > BSIZE)
E 10
I 10
		if (c > MAXBSIZE)
E 10
			printf("%s: too big\n", string);
		else {
			read(f, buf, c);
D 10
			wtfs(BBLOCK, BSIZE, buf);
E 10
I 10
			wtfs(BBLOCK, MAXBSIZE, buf);
E 10
		}
		close(f);
noinit:
D 10
		n = sblock.fs_size = getnum();
E 10
I 10
		n = getnum();
		sblock.fs_bsize = MAXBSIZE;
		sblock.fs_frag = MAXFRAG;
		sblock.fs_fsize = MAXBSIZE / MAXFRAG;
		sblock.fs_rotdelay = ROTDELAY;
		sblock.fs_minfree = MINFREE;
E 10
		sblock.fs_ntrak = getnum();
		sblock.fs_nsect = getnum();
		sblock.fs_cpg = getnum();
	} else
#endif
	{
		charp = "d--777 0 0 $ ";
		n = 0;
		for (f=0; c=proto[f]; f++) {
			if (c<'0' || c>'9') {
				printf("%s: cannot open\n", proto);
				exit(1);
			}
			n = n*10 + (c-'0');
		}
D 10
		sblock.fs_size = n;
E 10
		if (argc > 2)
D 10
			sblock.fs_nsect = atoi(argv[2]);
E 10
I 10
			sblock.fs_bsize = atoi(argv[2]);
E 10
		else
D 10
			sblock.fs_nsect = 32;
E 10
I 10
			sblock.fs_bsize = MAXBSIZE;
E 10
		if (argc > 3)
D 10
			sblock.fs_ntrak = atoi(argv[3]);
E 10
I 10
			sblock.fs_fsize = atoi(argv[3]);
E 10
		else
I 10
			sblock.fs_fsize = MAXBSIZE / MAXFRAG;
		if (argc > 4)
			sblock.fs_nsect = atoi(argv[4]);
		else
			sblock.fs_nsect = 32;
		if (argc > 5)
			sblock.fs_ntrak = atoi(argv[5]);
		else
E 10
			sblock.fs_ntrak = 19;
I 10
		sblock.fs_frag = sblock.fs_bsize / sblock.fs_fsize;
		sblock.fs_rotdelay = ROTDELAY;
		sblock.fs_minfree = MINFREE;
E 10
	}
	/*
	 * Now have size for file system and nsect and ntrak.
	 * (And, if coming from prototype, cpg).
	 * Determine number of cylinders occupied by file system.
	 */
E 11
I 10
D 43
	if (sblock.fs_fsize < DEV_BSIZE) {
E 43
I 43
	if (sblock.fs_fsize < sectorsize) {
E 43
		printf("fragment size %d is too small, minimum is %d\n",
D 43
		    sblock.fs_fsize, DEV_BSIZE);
E 43
I 43
		    sblock.fs_fsize, sectorsize);
E 43
		exit(1);
	}
	if (sblock.fs_bsize < MINBSIZE) {
		printf("block size %d is too small, minimum is %d\n",
		    sblock.fs_bsize, MINBSIZE);
		exit(1);
	}
D 11
	sblock.fs_size = n = dbtofsb(&sblock, n);
E 10
	if (sblock.fs_ntrak <= 0)
		printf("preposterous ntrak %d\n", sblock.fs_ntrak), exit(1);
	if (sblock.fs_nsect <= 0)
		printf("preposterous nsect %d\n", sblock.fs_nsect), exit(1);
	if (sblock.fs_size <= 0)
		printf("preposterous size %d\n", sblock.fs_size), exit(1);
D 10
	if (sblock.fs_ntrak * sblock.fs_nsect > MAXBPG * NSPB) {
E 10
I 10
	if (sblock.fs_ntrak * sblock.fs_nsect > MAXBPG(&sblock) * NSPB(&sblock)) {
E 10
		printf("cylinder too large (%d sectors)\n", 
		    sblock.fs_ntrak * sblock.fs_nsect);
		printf("maximum cylinder size: %d sectors\n",
D 10
		    MAXBPG * NSPB);
E 10
I 10
		    MAXBPG(&sblock) * NSPB(&sblock));
E 11
I 11
	if (sblock.fs_bsize < sblock.fs_fsize) {
		printf("block size (%d) cannot be smaller than fragment size (%d)\n",
		    sblock.fs_bsize, sblock.fs_fsize);
E 11
E 10
		exit(1);
	}
D 10
	sblock.fs_ncyl = n * NSPF / (sblock.fs_nsect * sblock.fs_ntrak);
	if (n * NSPF > sblock.fs_ncyl * sblock.fs_nsect * sblock.fs_ntrak) {
E 10
I 10
D 11
	sblock.fs_ncyl = n * NSPF(&sblock) / (sblock.fs_nsect * sblock.fs_ntrak);
	if (n * NSPF(&sblock) > sblock.fs_ncyl * sblock.fs_nsect * sblock.fs_ntrak) {
E 10
		printf("%d sector(s) in last cylinder unused\n",
D 10
		    n * NSPF - sblock.fs_ncyl * sblock.fs_nsect * sblock.fs_ntrak);
E 10
I 10
		    n * NSPF(&sblock) - sblock.fs_ncyl * sblock.fs_nsect * sblock.fs_ntrak);
E 10
		sblock.fs_ncyl++;
E 11
I 11
D 19
	sblock.fs_frag = sblock.fs_bsize / sblock.fs_fsize;
E 19
I 19
	sblock.fs_bmask = ~(sblock.fs_bsize - 1);
	sblock.fs_fmask = ~(sblock.fs_fsize - 1);
I 49
	/*
	 * Planning now for future expansion.
	 */
#	if (BYTE_ORDER == BIG_ENDIAN)
		sblock.fs_qbmask.val[0] = 0;
		sblock.fs_qbmask.val[1] = ~sblock.fs_bmask;
		sblock.fs_qfmask.val[0] = 0;
		sblock.fs_qfmask.val[1] = ~sblock.fs_fmask;
#	endif /* BIG_ENDIAN */
#	if (BYTE_ORDER == LITTLE_ENDIAN)
		sblock.fs_qbmask.val[0] = ~sblock.fs_bmask;
		sblock.fs_qbmask.val[1] = 0;
		sblock.fs_qfmask.val[0] = ~sblock.fs_fmask;
		sblock.fs_qfmask.val[1] = 0;
#	endif /* LITTLE_ENDIAN */
E 49
	for (sblock.fs_bshift = 0, i = sblock.fs_bsize; i > 1; i >>= 1)
		sblock.fs_bshift++;
	for (sblock.fs_fshift = 0, i = sblock.fs_fsize; i > 1; i >>= 1)
		sblock.fs_fshift++;
	sblock.fs_frag = numfrags(&sblock, sblock.fs_bsize);
I 27
	for (sblock.fs_fragshift = 0, i = sblock.fs_frag; i > 1; i >>= 1)
		sblock.fs_fragshift++;
E 27
E 19
	if (sblock.fs_frag > MAXFRAG) {
		printf("fragment size %d is too small, minimum with block size %d is %d\n",
		    sblock.fs_fsize, sblock.fs_bsize,
		    sblock.fs_bsize / MAXFRAG);
		exit(1);
E 11
	}
I 49
	sblock.fs_nrpos = nrpos;
E 49
I 27
	sblock.fs_nindir = sblock.fs_bsize / sizeof(daddr_t);
	sblock.fs_inopb = sblock.fs_bsize / sizeof(struct dinode);
D 43
	sblock.fs_nspf = sblock.fs_fsize / DEV_BSIZE;
	for (sblock.fs_fsbtodb = 0, i = sblock.fs_nspf; i > 1; i >>= 1)
E 43
I 43
	sblock.fs_nspf = sblock.fs_fsize / sectorsize;
	for (sblock.fs_fsbtodb = 0, i = NSPF(&sblock); i > 1; i >>= 1)
E 43
		sblock.fs_fsbtodb++;
E 27
I 13
D 22
	sblock.fs_bblkno = BBLOCK;
	sblock.fs_sblkno = SBLOCK;
	sblock.fs_cblkno = (daddr_t)
E 22
I 22
	sblock.fs_sblkno =
E 22
D 45
	    roundup(howmany(BBSIZE + SBSIZE, sblock.fs_fsize), sblock.fs_frag);
E 45
I 45
	    roundup(howmany(bbsize + sbsize, sblock.fs_fsize), sblock.fs_frag);
E 45
I 22
	sblock.fs_cblkno = (daddr_t)(sblock.fs_sblkno +
D 45
	    roundup(howmany(SBSIZE, sblock.fs_fsize), sblock.fs_frag));
E 45
I 45
	    roundup(howmany(sbsize, sblock.fs_fsize), sblock.fs_frag));
E 45
E 22
	sblock.fs_iblkno = sblock.fs_cblkno + sblock.fs_frag;
I 22
	sblock.fs_cgoffset = roundup(
D 43
	    howmany(sblock.fs_nsect, sblock.fs_fsize / DEV_BSIZE),
	    sblock.fs_frag);
E 43
I 43
	    howmany(sblock.fs_nsect, NSPF(&sblock)), sblock.fs_frag);
E 43
	for (sblock.fs_cgmask = 0xffffffff, i = sblock.fs_ntrak; i > 1; i >>= 1)
		sblock.fs_cgmask <<= 1;
	if (!POWEROF2(sblock.fs_ntrak))
		sblock.fs_cgmask <<= 1;
I 46
	/*
	 * Validate specified/determined secpercyl
	 * and calculate minimum cylinders per group.
	 */
	sblock.fs_spc = secpercyl;
E 46
E 22
I 16
	for (sblock.fs_cpc = NSPB(&sblock), i = sblock.fs_spc;
	     sblock.fs_cpc > 1 && (i & 1) == 0;
	     sblock.fs_cpc >>= 1, i >>= 1)
		/* void */;
I 17
D 46
	if (sblock.fs_cpc > MAXCPG) {
		printf("maximum block size with nsect %d and ntrak %d is %d\n",
		    sblock.fs_nsect, sblock.fs_ntrak,
		    sblock.fs_bsize / (sblock.fs_cpc / MAXCPG));
E 46
I 46
	mincpc = sblock.fs_cpc;
D 49
	if (mincpc > MAXCPG) {
		printf("Maximum frag size with %d sectors per cylinder is %d\n",
		    sblock.fs_spc, sblock.fs_fsize / (mincpc / MAXCPG));
E 46
		exit(1);
	}
E 49
I 46
	bpcg = sblock.fs_spc * sectorsize;
	inospercg = roundup(bpcg / sizeof(struct dinode), INOPB(&sblock));
D 49
	if (inospercg > MAXIPG)
		inospercg = MAXIPG;
E 49
I 49
	if (inospercg > MAXIPG(&sblock))
		inospercg = MAXIPG(&sblock);
E 49
	used = (sblock.fs_iblkno + inospercg / INOPF(&sblock)) * NSPF(&sblock);
	mincpgcnt = howmany(sblock.fs_cgoffset * (~sblock.fs_cgmask) + used,
	    sblock.fs_spc);
	mincpg = roundup(mincpgcnt, mincpc);
	/*
	 * Insure that cylinder group with mincpg has enough space
	 * for block maps
	 */
I 49
	sblock.fs_cpg = mincpg;
	sblock.fs_ipg = inospercg;
E 49
	mapcramped = 0;
D 49
	while (mincpg * sblock.fs_spc > MAXBPG(&sblock) * NSPB(&sblock)) {
E 49
I 49
	while (CGSIZE(&sblock) > sblock.fs_bsize) {
E 49
		mapcramped = 1;
		if (sblock.fs_bsize < MAXBSIZE) {
			sblock.fs_bsize <<= 1;
			if ((i & 1) == 0) {
				i >>= 1;
			} else {
				sblock.fs_cpc <<= 1;
				mincpc <<= 1;
				mincpg = roundup(mincpgcnt, mincpc);
I 49
				sblock.fs_cpg = mincpg;
E 49
			}
			sblock.fs_frag <<= 1;
			sblock.fs_fragshift += 1;
			if (sblock.fs_frag <= MAXFRAG)
				continue;
		}
		if (sblock.fs_fsize == sblock.fs_bsize) {
			printf("There is no block size that");
			printf(" can support this disk\n");
			exit(1);
		}
		sblock.fs_frag >>= 1;
		sblock.fs_fragshift -= 1;
		sblock.fs_fsize <<= 1;
		sblock.fs_nspf <<= 1;
	}
	/*
	 * Insure that cylinder group with mincpg has enough space for inodes
	 */
	inodecramped = 0;
	used *= sectorsize;
D 49
	inospercg = (mincpg * bpcg - used) / density;
	while (inospercg > MAXIPG) {
E 49
I 49
	inospercg = roundup((mincpg * bpcg - used) / density, INOPB(&sblock));
	sblock.fs_ipg = inospercg;
	while (inospercg > MAXIPG(&sblock)) {
E 49
		inodecramped = 1;
		if (mincpc == 1 || sblock.fs_frag == 1 ||
		    sblock.fs_bsize == MINBSIZE)
			break;
		printf("With a block size of %d %s %d\n", sblock.fs_bsize,
		    "minimum bytes per inode is",
D 49
		    (mincpg * bpcg - used) / MAXIPG + 1);
E 49
I 49
		    (mincpg * bpcg - used) / MAXIPG(&sblock) + 1);
E 49
		sblock.fs_bsize >>= 1;
		sblock.fs_frag >>= 1;
		sblock.fs_fragshift -= 1;
		mincpc >>= 1;
D 49
		i = roundup(mincpgcnt, mincpc);
		if (i * sblock.fs_spc > MAXBPG(&sblock) * NSPB(&sblock)) {
E 49
I 49
		sblock.fs_cpg = roundup(mincpgcnt, mincpc);
		if (CGSIZE(&sblock) > sblock.fs_bsize) {
E 49
			sblock.fs_bsize <<= 1;
			break;
		}
D 49
		mincpg = i;
		inospercg = (mincpg * bpcg - used) / density;
E 49
I 49
		mincpg = sblock.fs_cpg;
		inospercg =
		    roundup((mincpg * bpcg - used) / density, INOPB(&sblock));
		sblock.fs_ipg = inospercg;
E 49
	}
	if (inodecramped) {
D 49
		if (inospercg > MAXIPG) {
E 49
I 49
		if (inospercg > MAXIPG(&sblock)) {
E 49
			printf("Minimum bytes per inode is %d\n",
D 49
			    (mincpg * bpcg - used) / MAXIPG + 1);
E 49
I 49
			    (mincpg * bpcg - used) / MAXIPG(&sblock) + 1);
E 49
		} else if (!mapcramped) {
			printf("With %d bytes per inode, ", density);
			printf("minimum cylinders per group is %d\n", mincpg);
		}
	}
	if (mapcramped) {
		printf("With %d sectors per cylinder, ", sblock.fs_spc);
		printf("minimum cylinders per group is %d\n", mincpg);
	}
	if (inodecramped || mapcramped) {
		if (sblock.fs_bsize != bsize)
			printf("%s to be changed from %d to %d\n",
			    "This requires the block size",
			    bsize, sblock.fs_bsize);
		if (sblock.fs_fsize != fsize)
			printf("\t%s to be changed from %d to %d\n",
			    "and the fragment size",
D 49
			    bsize, sblock.fs_bsize);
E 49
I 49
			    fsize, sblock.fs_fsize);
E 49
		exit(1);
	}
E 46
E 17
E 16
E 13
D 11
	sblock.fs_magic = FS_MAGIC;
	/*
	 * Validate specified/determined cpg.
E 11
I 11
	/* 
D 46
	 * collect and verify the number of cylinders per group
E 46
I 46
	 * Calculate the number of cylinders per group
E 46
E 11
	 */
D 10
#define	CGTOOBIG(fs)	((fs).fs_nsect*(fs).fs_ntrak*(fs).fs_cpg/NSPB > MAXBPG)
	if (argc > 4 || fin) {
E 10
I 10
D 11
#define	CGTOOBIG(fs) \
   ((fs).fs_nsect * (fs).fs_ntrak * (fs).fs_cpg/NSPB(&sblock) > MAXBPG(&sblock))
	if (argc > 6 || fin) {
E 10
		if (fin == NULL)
D 10
			sblock.fs_cpg = atoi(argv[4]);
E 10
I 10
			sblock.fs_cpg = atoi(argv[6]);
E 10
		if (CGTOOBIG(sblock)) {
			printf("cylinder group too large (%d blocks); ",
D 10
			    sblock.fs_cpg * sblock.fs_nsect * sblock.fs_ntrak / NSPB);
			printf("max: %d blocks\n", MAXBPG);
E 10
I 10
			    sblock.fs_cpg * sblock.fs_nsect * sblock.fs_ntrak / NSPB(&sblock));
			printf("max: %d blocks\n", MAXBPG(&sblock));
E 10
			exit(1);
		}
		if (sblock.fs_cpg > MAXCPG) {
			printf("cylinder groups are limited to %d cylinders\n",
			    MAXCPG);
			exit(1);
		}
E 11
I 11
D 43
	if (argc > 6) {
		sblock.fs_cpg = atoi(argv[6]);
E 43
I 43
	sblock.fs_cpg = cpg;
D 46
	if (sblock.fs_cpg % sblock.fs_cpc != 0) {
		sblock.fs_cpg -= sblock.fs_cpg % sblock.fs_cpc;
E 46
I 46
	if (sblock.fs_cpg % mincpc != 0) {
E 46
		printf("%s groups must have a multiple of %d cylinders\n",
D 46
			"Warning: cylinder", sblock.fs_cpc);
E 46
I 46
			cpgflg ? "Cylinder" : "Warning: cylinder", mincpc);
		sblock.fs_cpg = roundup(sblock.fs_cpg, mincpc);
I 49
		if (!cpgflg)
			cpg = sblock.fs_cpg;
E 49
E 46
	}
I 46
	/*
D 49
	 * Must insure there is enough space to hold block map
E 49
I 49
	 * Must insure there is enough space for inodes
E 49
	 */
E 46
D 49
	sblock.fs_fpg = (sblock.fs_cpg * sblock.fs_spc) / NSPF(&sblock);
D 46
	while (sblock.fs_fpg / sblock.fs_frag > MAXBPG(&sblock) &&
	    sblock.fs_cpg > sblock.fs_cpc) {
		sblock.fs_cpg -= sblock.fs_cpc;
E 46
I 46
	while (sblock.fs_fpg > MAXBPG(&sblock) * sblock.fs_frag) {
		mapcramped = 1;
E 49
I 49
	sblock.fs_ipg = roundup((sblock.fs_cpg * bpcg - used) / density,
		INOPB(&sblock));
	while (sblock.fs_ipg > MAXIPG(&sblock)) {
		inodecramped = 1;
E 49
		sblock.fs_cpg -= mincpc;
E 46
E 43
D 49
		sblock.fs_fpg = (sblock.fs_cpg * sblock.fs_spc) / NSPF(&sblock);
E 49
I 49
		sblock.fs_ipg = roundup((sblock.fs_cpg * bpcg - used) / density,
			INOPB(&sblock));
E 49
E 11
D 43
	} else {
D 16
		sblock.fs_cpg = DESCPG;
E 16
I 16
		sblock.fs_cpg = MAX(sblock.fs_cpc, DESCPG);
E 16
D 11
		while (CGTOOBIG(sblock))
E 11
I 11
		sblock.fs_fpg = (sblock.fs_cpg * sblock.fs_spc) / NSPF(&sblock);
D 17
		while (sblock.fs_fpg / sblock.fs_frag > MAXBPG(&sblock)) {
E 11
			--sblock.fs_cpg;
E 17
I 17
		while (sblock.fs_fpg / sblock.fs_frag > MAXBPG(&sblock) &&
		    sblock.fs_cpg > sblock.fs_cpc) {
			sblock.fs_cpg -= sblock.fs_cpc;
E 17
I 11
			sblock.fs_fpg =
			    (sblock.fs_cpg * sblock.fs_spc) / NSPF(&sblock);
		}
E 43
E 11
	}
I 11
D 46
	if (sblock.fs_cpg < 1) {
		printf("cylinder groups must have at least 1 cylinder\n");
E 46
I 46
	/*
D 49
	 * Must insure there is enough space for inodes
E 49
I 49
	 * Must insure there is enough space to hold block map
E 49
	 */
D 49
	inospercg = (sblock.fs_cpg * bpcg - used) / density;
	while (inospercg > MAXIPG) {
		inodecramped = 1;
E 49
I 49
	while (CGSIZE(&sblock) > sblock.fs_bsize) {
		mapcramped = 1;
E 49
		sblock.fs_cpg -= mincpc;
D 49
		sblock.fs_fpg = (sblock.fs_cpg * sblock.fs_spc) / NSPF(&sblock);
		inospercg = (sblock.fs_cpg * bpcg - used) / density;
E 49
I 49
		sblock.fs_ipg = roundup((sblock.fs_cpg * bpcg - used) / density,
			INOPB(&sblock));
E 49
	}
I 49
	sblock.fs_fpg = (sblock.fs_cpg * sblock.fs_spc) / NSPF(&sblock);
E 49
	if ((sblock.fs_cpg * sblock.fs_spc) % NSPB(&sblock) != 0) {
		printf("newfs: panic (fs_cpg * fs_spc) % NSPF != 0");
		exit(2);
	}
	if (sblock.fs_cpg < mincpg) {
		printf("cylinder groups must have at least %d cylinders\n",
			mincpg);
E 46
		exit(1);
D 43
	}
	if (sblock.fs_cpg > MAXCPG) {
E 43
I 43
D 49
	} else if (sblock.fs_cpg > MAXCPG) {
E 43
		printf("cylinder groups are limited to %d cylinders\n", MAXCPG);
		exit(1);
E 49
I 43
D 46
	} else if (sblock.fs_cpg < cpg) {
		printf("%s: block size restricts cylinders per group to %d\n",
			"Warning", sblock.fs_cpg);
E 46
I 46
	} else if (sblock.fs_cpg != cpg) {
		if (!cpgflg)
			printf("Warning: ");
I 49
		else if (!mapcramped && !inodecramped)
			exit(1);
E 49
		if (mapcramped && inodecramped)
			printf("Block size and bytes per inode restrict");
		else if (mapcramped)
			printf("Block size restricts");
		else
			printf("Bytes per inode restrict");
		printf(" cylinders per group to %d.\n", sblock.fs_cpg);
		if (cpgflg)
			exit(1);
E 46
E 43
	}
I 46
D 49
	sblock.fs_cgsize = fragroundup(&sblock,
	    sizeof(struct cg) + howmany(sblock.fs_fpg, NBBY));
E 49
I 49
	sblock.fs_cgsize = fragroundup(&sblock, CGSIZE(&sblock));
E 49
E 46
I 16
D 43
	if (sblock.fs_cpg % sblock.fs_cpc != 0) {
		printf("cylinder groups must have a multiple of %d cylinders\n",
		    sblock.fs_cpc);
		exit(1);
	}
E 43
E 16
E 11
	/*
I 11
	 * Now have size for file system and nsect and ntrak.
	 * Determine number of cylinders and blocks in the file system.
	 */
	sblock.fs_size = fssize = dbtofsb(&sblock, fssize);
	sblock.fs_ncyl = fssize * NSPF(&sblock) / sblock.fs_spc;
D 13
	if (sblock.fs_spc > MAXBPC * NSPB(&sblock)) {
		printf("too many sectors per cylinder (%d sectors)\n",
		    sblock.fs_spc);
		while (sblock.fs_spc > MAXBPC * NSPB(&sblock))
			sblock.fs_bsize <<= 1;
		printf("nsect %d, and ntrak %d, requires block size of %d\n",
		    sblock.fs_nsect, sblock.fs_ntrak, sblock.fs_bsize);
E 13
I 13
	if (fssize * NSPF(&sblock) > sblock.fs_ncyl * sblock.fs_spc) {
D 22
		printf("Warning: %d sector(s) in last cylinder unallocated\n",
		    sblock.fs_spc -
		    (fssize * NSPF(&sblock) - sblock.fs_ncyl * sblock.fs_spc));
E 22
		sblock.fs_ncyl++;
I 22
		warn = 1;
E 22
	}
	if (sblock.fs_ncyl < 1) {
		printf("file systems must have at least one cylinder\n");
E 13
		exit(1);
	}
	/*
I 13
D 49
	 * determine feasability/values of rotational layout tables
E 49
I 49
	 * Determine feasability/values of rotational layout tables.
	 *
	 * The size of the rotational layout tables is limited by the
	 * size of the superblock, SBSIZE. The amount of space available
	 * for tables is calculated as (SBSIZE - sizeof (struct fs)).
	 * The size of these tables is inversely proportional to the block
	 * size of the file system. The size increases if sectors per track
	 * are not powers of two, because more cylinders must be described
	 * by the tables before the rotational pattern repeats (fs_cpc).
E 49
	 */
I 46
	sblock.fs_interleave = interleave;
	sblock.fs_trackskew = trackskew;
	sblock.fs_npsect = nphyssectors;
I 49
	sblock.fs_postblformat = FS_DYNAMICPOSTBLFMT;
	sblock.fs_sbsize = fragroundup(&sblock, sizeof(struct fs));
E 49
E 46
	if (sblock.fs_ntrak == 1) {
		sblock.fs_cpc = 0;
		goto next;
	}
D 16
	for (sblock.fs_cpc = NSPB(&sblock), i = sblock.fs_spc;
	     sblock.fs_cpc > 1 && (i & 1) == 0;
	     sblock.fs_cpc >>= 1, i >>= 1)
		/* void */;
E 16
D 49
	if (sblock.fs_spc * sblock.fs_cpc > MAXBPC * NSPB(&sblock) ||
E 49
I 49
	postblsize = sblock.fs_nrpos * sblock.fs_cpc * sizeof(short);
	rotblsize = sblock.fs_cpc * sblock.fs_spc / NSPB(&sblock);
	totalsbsize = sizeof(struct fs) + rotblsize;
	if (sblock.fs_nrpos == 8 && sblock.fs_cpc <= 16) {
		/* use old static table space */
		sblock.fs_postbloff = (char *)(&sblock.fs_opostbl[0][0]) -
		    (char *)(&sblock.fs_link);
		sblock.fs_rotbloff = &sblock.fs_space[0] -
		    (u_char *)(&sblock.fs_link);
	} else {
		/* use dynamic table space */
		sblock.fs_postbloff = &sblock.fs_space[0] -
		    (u_char *)(&sblock.fs_link);
		sblock.fs_rotbloff = sblock.fs_postbloff + postblsize;
		totalsbsize += postblsize;
	}
	if (totalsbsize > SBSIZE ||
E 49
	    sblock.fs_nsect > (1 << NBBY) * NSPB(&sblock)) {
		printf("%s %s %d %s %d.%s",
		    "Warning: insufficient space in super block for\n",
		    "rotational layout tables with nsect", sblock.fs_nsect,
		    "and ntrak", sblock.fs_ntrak,
D 37
		    "\nFile system performance may be impared.\n");
E 37
I 37
D 38
		    "\nFile system performance may be impaired.\n");
E 38
I 38
		    "\nFile system performance may be impared.\n");
E 38
E 37
		sblock.fs_cpc = 0;
		goto next;
	}
I 49
	sblock.fs_sbsize = fragroundup(&sblock, totalsbsize);
E 49
	/*
	 * calculate the available blocks for each rotational position
	 */
I 44
D 46
	sblock.fs_interleave = interleave;
	sblock.fs_trackskew = trackskew;
	sblock.fs_npsect = nphyssectors;
E 46
E 44
D 49
	for (cylno = 0; cylno < MAXCPG; cylno++)
		for (rpos = 0; rpos < NRPOS; rpos++)
			sblock.fs_postbl[cylno][rpos] = -1;
	blk = sblock.fs_spc * sblock.fs_cpc / NSPF(&sblock);
	for (i = 0; i < blk; i += sblock.fs_frag)
		/* void */;
	for (i -= sblock.fs_frag; i >= 0; i -= sblock.fs_frag) {
E 49
I 49
	for (cylno = 0; cylno < sblock.fs_cpc; cylno++)
		for (rpos = 0; rpos < sblock.fs_nrpos; rpos++)
			fs_postbl(&sblock, cylno)[rpos] = -1;
	for (i = (rotblsize - 1) * sblock.fs_frag;
	     i >= 0; i -= sblock.fs_frag) {
E 49
		cylno = cbtocylno(&sblock, i);
		rpos = cbtorpos(&sblock, i);
D 49
		blk = i / sblock.fs_frag;
		if (sblock.fs_postbl[cylno][rpos] == -1)
			sblock.fs_rotbl[blk] = 0;
E 49
I 49
		blk = fragstoblks(&sblock, i);
		if (fs_postbl(&sblock, cylno)[rpos] == -1)
			fs_rotbl(&sblock)[blk] = 0;
E 49
		else
D 49
			sblock.fs_rotbl[blk] =
			    sblock.fs_postbl[cylno][rpos] - blk;
		sblock.fs_postbl[cylno][rpos] = blk;
E 49
I 49
			fs_rotbl(&sblock)[blk] =
			    fs_postbl(&sblock, cylno)[rpos] - blk;
		fs_postbl(&sblock, cylno)[rpos] = blk;
E 49
	}
next:
	/*
E 13
D 46
	 * Validate specified/determined cpg.
	 */
	if (sblock.fs_spc > MAXBPG(&sblock) * NSPB(&sblock)) {
		printf("too many sectors per cylinder (%d sectors)\n",
		    sblock.fs_spc);
		while(sblock.fs_spc > MAXBPG(&sblock) * NSPB(&sblock)) {
			sblock.fs_bsize <<= 1;
			if (sblock.fs_frag < MAXFRAG)
				sblock.fs_frag <<= 1;
			else
				sblock.fs_fsize <<= 1;
		}
		printf("nsect %d, and ntrak %d, requires block size of %d,\n",
		    sblock.fs_nsect, sblock.fs_ntrak, sblock.fs_bsize);
		printf("\tand fragment size of %d\n", sblock.fs_fsize);
		exit(1);
	}
	if (sblock.fs_fpg > MAXBPG(&sblock) * sblock.fs_frag) {
		printf("cylinder group too large (%d cylinders); ",
		    sblock.fs_cpg);
D 13
		printf("max: %d cylinders\n",
E 13
I 13
		printf("max: %d cylinders per group\n",
E 13
		    MAXBPG(&sblock) * sblock.fs_frag /
		    (sblock.fs_fpg / sblock.fs_cpg));
		exit(1);
	}
D 19
	sblock.fs_cgsize = roundup(sizeof(struct cg) +
	    howmany(sblock.fs_fpg, NBBY), sblock.fs_fsize);
E 19
I 19
	sblock.fs_cgsize = fragroundup(&sblock,
	    sizeof(struct cg) + howmany(sblock.fs_fpg, NBBY));
E 19
	/*
E 46
E 11
	 * Compute/validate number of cylinder groups.
	 */
I 11
D 13
	if (fssize * NSPF(&sblock) > sblock.fs_ncyl * sblock.fs_spc) {
		printf("%d sector(s) in last cylinder unused\n",
		    fssize * NSPF(&sblock) - sblock.fs_ncyl * sblock.fs_spc);
	}
E 13
E 11
	sblock.fs_ncg = sblock.fs_ncyl / sblock.fs_cpg;
	if (sblock.fs_ncyl % sblock.fs_cpg)
		sblock.fs_ncg++;
D 10
	if ((sblock.fs_nsect*sblock.fs_ntrak*sblock.fs_cpg) % NSPF) {
E 10
I 10
D 11
	if ((sblock.fs_nsect*sblock.fs_ntrak*sblock.fs_cpg) % NSPF(&sblock)) {
E 11
I 11
D 46
	if ((sblock.fs_spc * sblock.fs_cpg) % NSPF(&sblock)) {
E 11
E 10
		printf("mkfs: nsect %d, ntrak %d, cpg %d is not tolerable\n",
		    sblock.fs_nsect, sblock.fs_ntrak, sblock.fs_cpg);
		printf("as this would would have cyl groups whose size\n");
D 10
		printf("is not a multiple of %d; choke!\n", FSIZE);
E 10
I 10
		printf("is not a multiple of %d; choke!\n", sblock.fs_fsize);
E 10
		exit(1);
	}
E 46
D 13
	fscs = (struct csum *)
D 10
	    calloc(1, roundup(sblock.fs_ncg * sizeof (struct csum), BSIZE));
E 10
I 10
	    calloc(1, roundup(sblock.fs_ncg * sizeof (struct csum),
		sblock.fs_bsize));
E 13
E 10
D 49
	/*
	 * Compute number of inode blocks per cylinder group.
D 43
	 * Start with one inode per NBPI bytes; adjust as necessary.
E 43
I 43
D 46
	 * Start with one inode per density bytes; adjust as necessary.
E 46
E 43
	 */
I 31
D 43
	inos = MAX(NBPI, sblock.fs_fsize);
	if (argc > 9) {
		i = atoi(argv[9]);
		if (i <= 0)
			printf("%s: bogus nbpi reset to %d\n", argv[9], inos);
		else
			inos = i;
	}
E 43
E 31
D 10
	n = ((n * BSIZE) / NBPI) / INOPB;
E 10
I 10
D 11
	n = ((n * sblock.fs_fsize) / NBPI) / INOPB(&sblock);
E 10
	if (n <= 0)
		n = 1;
D 10
	if (n > 65500/INOPB)
		n = 65500/INOPB;
	sblock.fs_ipg = ((n / sblock.fs_ncg) + 1) * INOPB;
	if (sblock.fs_ipg < INOPB)
		sblock.fs_ipg = INOPB;
E 10
I 10
	sblock.fs_ipg = ((n / sblock.fs_ncg) + 1) * INOPB(&sblock);
	if (sblock.fs_ipg < INOPB(&sblock))
		sblock.fs_ipg = INOPB(&sblock);
E 11
I 11
D 13
	inos = ((fssize * sblock.fs_fsize) / MAX(NBPI, sblock.fs_fsize)) /
	    INOPB(&sblock);
E 13
I 13
D 46
	i = sblock.fs_iblkno + MAXIPG / INOPF(&sblock);
D 31
	inos = (fssize - sblock.fs_ncg * i) * sblock.fs_fsize /
	    MAX(NBPI, sblock.fs_fsize) / INOPB(&sblock);
E 31
I 31
D 43
	inos = (fssize - sblock.fs_ncg * i) * sblock.fs_fsize / inos /
E 43
I 43
	density = (fssize - sblock.fs_ncg * i) * sblock.fs_fsize / density /
E 43
	    INOPB(&sblock);
E 31
E 13
D 43
	if (inos <= 0)
		inos = 1;
	sblock.fs_ipg = ((inos / sblock.fs_ncg) + 1) * INOPB(&sblock);
E 43
I 43
	if (density <= 0)
		density = 1;
	sblock.fs_ipg = ((density / sblock.fs_ncg) + 1) * INOPB(&sblock);
E 43
E 11
E 10
	if (sblock.fs_ipg > MAXIPG)
		sblock.fs_ipg = MAXIPG;
E 46
I 46
	sblock.fs_ipg = roundup(inospercg, INOPB(&sblock));
	if (sblock.fs_ipg > MAXIPG) {
		printf("newfs: panic fs_ipg > MAXIPG");
		exit(3);
	}
E 49
E 46
I 13
	sblock.fs_dblkno = sblock.fs_iblkno + sblock.fs_ipg / INOPF(&sblock);
E 13
D 10
	while (sblock.fs_ipg * sblock.fs_ncyl > 65500)
		sblock.fs_ipg -= INOPB;
E 10
D 11
	sblock.fs_spc = sblock.fs_ntrak * sblock.fs_nsect;
D 10
	sblock.fs_fpg = (sblock.fs_cpg * sblock.fs_spc) / (FSIZE / 512);
	if (cgdmin(0,&sblock) >= sblock.fs_fpg)
E 10
I 10
	sblock.fs_fpg = (sblock.fs_cpg * sblock.fs_spc) /
			(sblock.fs_fsize / SECTSIZE);
E 11
D 15
	if (cgdmin(0,&sblock) >= sblock.fs_fpg) {
E 15
I 15
D 22
	if (cgdmin(&sblock, 0) >= sblock.fs_fpg) {
E 22
I 22
	i = MIN(~sblock.fs_cgmask, sblock.fs_ncg - 1);
	if (cgdmin(&sblock, i) - cgbase(&sblock, i) >= sblock.fs_fpg) {
E 22
E 15
E 10
		printf("inode blocks/cyl group (%d) >= data blocks (%d)\n",
D 10
		    cgdmin(0,&sblock)/FRAG, sblock.fs_fpg/FRAG), exit(1);
E 10
I 10
D 15
		    cgdmin(0,&sblock) / sblock.fs_frag,
E 15
I 15
D 22
		    cgdmin(&sblock, 0) / sblock.fs_frag,
E 22
I 22
		    cgdmin(&sblock, i) - cgbase(&sblock, i) / sblock.fs_frag,
E 22
E 15
		    sblock.fs_fpg / sblock.fs_frag);
I 11
D 22
		printf("number of cylinder per cylinder group must be increased\n");
E 22
I 22
D 46
		printf("number of cylinders per cylinder group must be increased\n");
E 46
I 46
		printf("number of cylinders per cylinder group (%d) %s.\n",
D 49
		    sblock.fs_ncg, "must be increased");
E 49
I 49
		    sblock.fs_cpg, "must be increased");
E 49
E 46
E 22
E 11
		exit(1);
	}
I 22
	j = sblock.fs_ncg - 1;
	if ((i = fssize - j * sblock.fs_fpg) < sblock.fs_fpg &&
	    cgdmin(&sblock, j) - cgbase(&sblock, j) > i) {
		printf("Warning: inode blocks/cyl group (%d) >= data blocks (%d) in last\n",
		    (cgdmin(&sblock, j) - cgbase(&sblock, j)) / sblock.fs_frag,
		    i / sblock.fs_frag);
		printf("    cylinder group. This implies %d sector(s) cannot be allocated.\n",
		    i * NSPF(&sblock));
		sblock.fs_ncg--;
		sblock.fs_ncyl -= sblock.fs_ncyl % sblock.fs_cpg;
		sblock.fs_size = fssize = sblock.fs_ncyl * sblock.fs_spc /
		    NSPF(&sblock);
		warn = 0;
	}
	if (warn) {
		printf("Warning: %d sector(s) in last cylinder unallocated\n",
		    sblock.fs_spc -
		    (fssize * NSPF(&sblock) - (sblock.fs_ncyl - 1)
		    * sblock.fs_spc));
	}
E 22
E 10
D 9
	sblock.fs_nifree = sblock.fs_ipg * sblock.fs_ncg;
E 9
I 9
D 11
	sblock.fs_cstotal.cs_nifree = sblock.fs_ipg * sblock.fs_ncg;
E 9
	sblock.fs_cgsize = cgsize(&sblock);
E 11
I 11
	/*
D 13
	 * calculate the available blocks for each rotational position
	 */
	for (i = 0; i < NRPOS; i++)
		sblock.fs_postbl[i] = -1;
	for (i = 0; i < sblock.fs_spc; i += NSPB(&sblock))
		/* void */;
	for (i -= NSPB(&sblock); i >= 0; i -= NSPB(&sblock)) {
		c = i % sblock.fs_nsect * NRPOS / sblock.fs_nsect;
		sblock.fs_rotbl[i / NSPB(&sblock)] = sblock.fs_postbl[c];
		sblock.fs_postbl[c] = i / NSPB(&sblock);
	}
	/*
E 13
	 * fill in remaining fields of the super block
	 */
E 11
D 10
	sblock.fs_cssize = cssize(&sblock);
E 10
I 10
D 15
	sblock.fs_csaddr = cgdmin(0, &sblock);
E 15
I 15
	sblock.fs_csaddr = cgdmin(&sblock, 0);
E 15
D 22
	sblock.fs_cssize = sblock.fs_ncg * sizeof(struct csum);
I 13
	fscs = (struct csum *)
D 19
	    calloc(1, roundup(sblock.fs_cssize, sblock.fs_bsize));
E 19
I 19
	    calloc(1, blkroundup(&sblock, sblock.fs_cssize));
E 22
I 22
	sblock.fs_cssize =
	    fragroundup(&sblock, sblock.fs_ncg * sizeof(struct csum));
I 27
	i = sblock.fs_bsize / sizeof(struct csum);
	sblock.fs_csmask = ~(i - 1);
	for (sblock.fs_csshift = 0; i > 1; i >>= 1)
		sblock.fs_csshift++;
D 49
	i = sizeof(struct fs) +
		howmany(sblock.fs_spc * sblock.fs_cpc, NSPB(&sblock));
	sblock.fs_sbsize = fragroundup(&sblock, i);
E 49
E 27
	fscs = (struct csum *)calloc(1, sblock.fs_cssize);
E 22
E 19
	sblock.fs_magic = FS_MAGIC;
E 13
I 11
D 43
	sblock.fs_rotdelay = ROTDELAY;
D 28
	sblock.fs_minfree = MINFREE;
E 28
I 28
	if (argc > 7) {
		sblock.fs_minfree = atoi(argv[7]);
		if (sblock.fs_minfree < 0 || sblock.fs_minfree > 99) {
			printf("%s: bogus minfree reset to %d%%\n", argv[7],
				MINFREE);
			sblock.fs_minfree = MINFREE;
		}
	} else
		sblock.fs_minfree = MINFREE;
E 28
I 25
	sblock.fs_maxcontig = MAXCONTIG;
E 43
I 43
	sblock.fs_rotdelay = rotdelay;
	sblock.fs_minfree = minfree;
	sblock.fs_maxcontig = maxcontig;
I 44
	sblock.fs_headswitch = headswitch;
	sblock.fs_trkseek = trackseek;
E 44
E 43
D 47
	sblock.fs_maxbpg = MAXBLKPG(&sblock);
E 47
I 47
	sblock.fs_maxbpg = maxbpg;
E 47
E 25
D 13
	sblock.fs_magic = FS_MAGIC;
E 11
E 10
	sblock.fs_sblkno = SBLOCK;
E 13
I 13
D 20
	sblock.fs_rps = HZ;	/* assume disk speed == HZ */
E 20
I 20
D 28
	sblock.fs_rps = 60;	/* assume disk speed == 60 HZ */
E 28
I 28
D 43
	if (argc > 8)
		sblock.fs_rps = atoi(argv[8]);
	else
		sblock.fs_rps = DEFHZ;
I 42
	if (argc > 10)
		if (*argv[10] == 's')
			sblock.fs_optim = FS_OPTSPACE;
		else if (*argv[10] == 't')
			sblock.fs_optim = FS_OPTTIME;
		else {
			printf("%s: bogus optimization preference %s\n",
				argv[10], "reset to time");
			sblock.fs_optim = FS_OPTTIME;
		}
	else
		sblock.fs_optim = DEFAULTOPT;
E 43
I 43
	sblock.fs_rps = rpm / 60;
	sblock.fs_optim = opt;
E 43
E 42
E 28
E 20
E 13
I 11
	sblock.fs_cgrotor = 0;
	sblock.fs_cstotal.cs_ndir = 0;
	sblock.fs_cstotal.cs_nbfree = 0;
	sblock.fs_cstotal.cs_nifree = 0;
	sblock.fs_cstotal.cs_nffree = 0;
E 11
	sblock.fs_fmod = 0;
	sblock.fs_ronly = 0;
D 11

E 11
	/*
D 11
	 * Dump out information about file system.
E 11
I 11
	 * Dump out summary information about file system.
E 11
	 */
	printf("%s:\t%d sectors in %d cylinders of %d tracks, %d sectors\n",
D 10
	    fsys, sblock.fs_size*NSPF, sblock.fs_ncyl, sblock.fs_ntrak, sblock.fs_nsect);
E 10
I 10
D 11
	    fsys, sblock.fs_size*NSPF(&sblock), sblock.fs_ncyl,
E 11
I 11
	    fsys, sblock.fs_size * NSPF(&sblock), sblock.fs_ncyl,
E 11
	    sblock.fs_ntrak, sblock.fs_nsect);
E 10
D 51
	printf("\t%.1fMb in %d cyl groups (%d c/g, %.2fMb/g, %d i/g)\n",
E 51
I 51
	printf("\t%.1fMB in %d cyl groups (%d c/g, %.2fMB/g, %d i/g)\n",
E 51
D 10
	    (float)sblock.fs_size*FSIZE*1e-6, sblock.fs_ncg, sblock.fs_cpg,
	    (float)sblock.fs_fpg*FSIZE*1e-6, sblock.fs_ipg);
E 10
I 10
	    (float)sblock.fs_size * sblock.fs_fsize * 1e-6, sblock.fs_ncg,
	    sblock.fs_cpg, (float)sblock.fs_fpg * sblock.fs_fsize * 1e-6,
	    sblock.fs_ipg);
E 10
D 11
/*
D 10
	printf("%7d size (%d blocks)\n", sblock.fs_size, sblock.fs_size/FRAG);
E 10
I 10
	printf("%7d size (%d blocks)\n",
		sblock.fs_size, sblock.fs_size / sblock.fs_frag);
E 10
	printf("%7d cylinder groups\n", sblock.fs_ncg);
	printf("%7d cylinder group block size\n", sblock.fs_cgsize);
	printf("%7d tracks\n", sblock.fs_ntrak);
	printf("%7d sectors\n", sblock.fs_nsect);
	printf("%7d sectors per cylinder\n", sblock.fs_spc);
	printf("%7d cylinders\n", sblock.fs_ncyl);
	printf("%7d cylinders per group\n", sblock.fs_cpg);
D 10
	printf("%7d blocks per group\n", sblock.fs_fpg/FRAG);
E 10
I 10
	printf("%7d blocks per group\n", sblock.fs_fpg/sblock.fs_frag);
E 10
	printf("%7d inodes per group\n", sblock.fs_ipg);
	if (sblock.fs_ncyl % sblock.fs_cpg) {
		printf("%7d cylinders in last group\n",
		    i = sblock.fs_ncyl % sblock.fs_cpg);
		printf("%7d blocks in last group\n",
D 10
		    i * sblock.fs_spc / NSPB);
E 10
I 10
		    i * sblock.fs_spc / NSPB(&sblock));
E 10
	}
*/
E 11
	/*
	 * Now build the cylinders group blocks and
D 11
	 * then print out indices of cylinder groups forwarded
	 * past bad blocks or other obstructions.
E 11
I 11
	 * then print out indices of cylinder groups.
E 11
	 */
D 9
	sblock.fs_nffree = 0;
	sblock.fs_nbfree = 0;
E 9
I 9
D 11
	sblock.fs_cstotal.cs_ndir = 0;
	sblock.fs_cstotal.cs_nbfree = 0;
	sblock.fs_cstotal.cs_nifree = 0;
	sblock.fs_cstotal.cs_nffree = 0;
E 9
I 8
	sblock.fs_cgrotor = 0;
	for (i = 0; i < NRPOS; i++)
		sblock.fs_postbl[i] = -1;
D 10
	for (i = 0; i < sblock.fs_spc; i += (NSPF * FRAG))
E 10
I 10
	for (i = 0; i < sblock.fs_spc; i += (NSPF(&sblock) * sblock.fs_frag))
E 10
		/* void */;
D 10
	for (i -= (NSPF * FRAG); i >= 0; i -= (NSPF * FRAG)) {
E 10
I 10
	for (i -= (NSPF(&sblock) * sblock.fs_frag);
	     i >= 0;
	     i -= (NSPF(&sblock) * sblock.fs_frag)) {
E 10
		c = i % sblock.fs_nsect * NRPOS / sblock.fs_nsect;
D 10
		sblock.fs_rotbl[i / (NSPF * FRAG)] = sblock.fs_postbl[c];
		sblock.fs_postbl[c] = i / (NSPF * FRAG);
E 10
I 10
		sblock.fs_rotbl[i / (NSPF(&sblock) * sblock.fs_frag)] =
			sblock.fs_postbl[c];
		sblock.fs_postbl[c] = i / (NSPF(&sblock) * sblock.fs_frag);
E 10
	}
E 11
E 8
D 13
	for (c = 0; c < sblock.fs_ncg; c++)
		initcg(c);
E 13
I 13
D 22
	for (cylno = 0; cylno < sblock.fs_ncg; cylno++)
E 22
I 22
D 49
	printf("super-block backups (for fsck -b#) at:");
E 49
I 49
	printf("super-block backups (for fsck -b #) at:");
E 49
	for (cylno = 0; cylno < sblock.fs_ncg; cylno++) {
E 22
		initcg(cylno);
E 13
D 10
	printf("\tsuper-block backups (for fsck -b#) at %d+k*%d (%d .. %d)\n",
	    SBLOCK, sblock.fs_fpg, SBLOCK+sblock.fs_fpg,
	    SBLOCK+(sblock.fs_ncg-1)*sblock.fs_fpg);
E 10
I 10
D 22
	if (sblock.fs_ncg == 1)
D 13
		printf("Warning, no super-block backups with only one cylinder group\n");
E 13
I 13
		printf("Warning: no super-block backups with only one cylinder group\n");
E 13
	else
		printf("\tsuper-block backups (for fsck -b#) at %d+k*%d (%d .. %d)\n",
D 12
		    SBLOCK, fsbtodb(&sblock, sblock.fs_fpg),
		    SBLOCK + fsbtodb(&sblock, sblock.fs_fpg),
		    SBLOCK + fsbtodb(&sblock, (sblock.fs_ncg - 1) *
			sblock.fs_fpg));
E 12
I 12
D 13
		    SBLOCK, fsbtodb(&sblock, cgsblock(1, &sblock)) - SBLOCK,
		    fsbtodb(&sblock, cgsblock(1, &sblock)),
		    fsbtodb(&sblock, cgsblock(sblock.fs_ncg - 1, &sblock)));
E 13
I 13
D 15
		    SBLOCK, cgsblock(1, &sblock) - SBLOCK, cgsblock(1, &sblock),
		    cgsblock(sblock.fs_ncg - 1, &sblock));
E 15
I 15
		    SBLOCK, cgsblock(&sblock, 1) - SBLOCK, cgsblock(&sblock, 1),
		    cgsblock(&sblock, sblock.fs_ncg - 1));
E 22
I 22
D 46
		if (cylno % 10 == 0)
E 46
I 46
		if (cylno % 9 == 0)
E 46
			printf("\n");
		printf(" %d,", fsbtodb(&sblock, cgsblock(&sblock, cylno)));
	}
D 29
	printf("\n%s\n%s\n",
	    "WRITE THESE NUMBERS DOWN!!!",
	    "fsck depends on them to recover this file system.");
E 29
I 29
	printf("\n");
I 36
	if (Nflag)
		exit(0);
E 36
E 29
E 22
E 15
E 13
E 12
E 10
	/*
D 11
	 * Now construct the initial file system, and
E 11
I 11
	 * Now construct the initial file system,
E 11
	 * then write out the super-block.
	 */
D 11
	cfile((struct inode *)0);
E 11
I 11
	fsinit();
E 11
	sblock.fs_time = utime;
D 10
	wtfs(SBLOCK, BSIZE, (char *)&sblock);
	for (i = 0; i < cssize(&sblock); i += BSIZE)
		wtfs(csaddr(&sblock) + i/BSIZE, BSIZE, ((char *)fscs)+i);
E 10
I 10
D 11
	wtfs(SBLOCK, MAXBSIZE, (char *)&sblock);
E 11
I 11
D 45
	wtfs(SBLOCK, SBSIZE, (char *)&sblock);
E 45
I 45
	wtfs(SBOFF / sectorsize, sbsize, (char *)&sblock);
E 45
E 11
	for (i = 0; i < sblock.fs_cssize; i += sblock.fs_bsize)
D 19
		wtfs(fsbtodb(&sblock, sblock.fs_csaddr + i / sblock.fs_fsize),
E 19
I 19
		wtfs(fsbtodb(&sblock, sblock.fs_csaddr + numfrags(&sblock, i)),
E 19
D 22
			sblock.fs_bsize, ((char *)fscs) + i);
E 22
I 22
			sblock.fs_cssize - i < sblock.fs_bsize ?
			    sblock.fs_cssize - i : sblock.fs_bsize,
			((char *)fscs) + i);
E 22
E 10
D 11
	for (c = 0; c < sblock.fs_ncg; c++)
E 11
I 11
	/* 
	 * Write out the duplicate super blocks
	 */
D 13
	for (c = 1; c < sblock.fs_ncg; c++)
E 11
D 10
		wtfs(cgsblock(c, &sblock), BSIZE, (char *)&sblock);
E 10
I 10
		wtfs(fsbtodb(&sblock, cgsblock(c, &sblock)),
D 11
			MAXBSIZE, (char *)&sblock);
E 11
I 11
			SBSIZE, (char *)&sblock);
E 13
I 13
D 26
	for (cylno = 1; cylno < sblock.fs_ncg; cylno++)
E 26
I 26
	for (cylno = 0; cylno < sblock.fs_ncg; cylno++)
E 26
D 15
		wtfs(cgsblock(cylno, &sblock), SBSIZE, (char *)&sblock);
E 15
I 15
D 22
		wtfs(cgsblock(&sblock, cylno), SBSIZE, (char *)&sblock);
E 22
I 22
		wtfs(fsbtodb(&sblock, cgsblock(&sblock, cylno)),
D 45
		    SBSIZE, (char *)&sblock);
E 45
I 45
		    sbsize, (char *)&sblock);
E 45
E 22
E 15
E 13
E 11
E 10
D 43
#ifndef STANDALONE
D 11
	exit(error);
E 11
I 11
	exit(0);
E 11
#endif
E 43
I 43
	/*
	 * Update information about this partion in pack
	 * label, to that it may be updated on disk.
	 */
	pp->p_fstype = FS_BSDFFS;
	pp->p_fsize = sblock.fs_fsize;
	pp->p_frag = sblock.fs_frag;
	pp->p_cpg = sblock.fs_cpg;
E 43
}

/*
 * Initialize a cylinder group.
 */
D 13
initcg(c)
	int c;
E 13
I 13
initcg(cylno)
	int cylno;
E 13
{
D 22
	daddr_t cbase, d, dmin, dmax;
E 22
I 22
	daddr_t cbase, d, dlower, dupper, dmax;
E 22
	long i, j, s;
	register struct csum *cs;

	/*
	 * Determine block bounds for cylinder group.
	 * Allow space for super block summary information in first
	 * cylinder group.
	 */
D 13
	cbase = cgbase(c,&sblock);
E 13
I 13
D 15
	cbase = cgbase(cylno,&sblock);
E 15
I 15
	cbase = cgbase(&sblock, cylno);
E 15
E 13
	dmax = cbase + sblock.fs_fpg;
	if (dmax > sblock.fs_size)
		dmax = sblock.fs_size;
I 7
D 13
	dmin = cgdmin(c,&sblock) - cbase;
E 13
I 13
D 22
	dmin = sblock.fs_dblkno;
E 13
E 7
	d = cbase;
E 22
I 22
	dlower = cgsblock(&sblock, cylno) - cbase;
	dupper = cgdmin(&sblock, cylno) - cbase;
I 49
	if (cylno == 0)
		dupper += howmany(sblock.fs_cssize, sblock.fs_fsize);
E 49
E 22
D 13
	cs = fscs+c;
E 13
I 13
	cs = fscs + cylno;
E 13
D 2
tryagain:
	for (i = cgdmin(c,&sblock) - FRAG; i >= 0; i -= FRAG)
		if (badblk(d)) {
			d += i + FRAG;
			if (d + sblock.fs_ipg/INOPB >= dmax) {
				printf("bad blocks: cyl grp %d unusable\n", c);
				exit(1);
			}
			goto tryagain;
		}
E 2
D 9
	cs->cs_ndir = 0;
E 9
	acg.cg_time = utime;
	acg.cg_magic = CG_MAGIC;
D 13
	acg.cg_cgx = c;
E 13
I 13
	acg.cg_cgx = cylno;
E 13
D 23
	acg.cg_ncyl = sblock.fs_cpg;
E 23
I 23
	if (cylno == sblock.fs_ncg - 1)
		acg.cg_ncyl = sblock.fs_ncyl % sblock.fs_cpg;
	else
		acg.cg_ncyl = sblock.fs_cpg;
E 23
	acg.cg_niblk = sblock.fs_ipg;
	acg.cg_ndblk = dmax - cbase;
D 9
	acg.cg_ndir = 0;
	acg.cg_nffree = 0;
	acg.cg_nbfree = 0;
	acg.cg_nifree = 0;
E 9
I 9
	acg.cg_cs.cs_ndir = 0;
	acg.cg_cs.cs_nffree = 0;
	acg.cg_cs.cs_nbfree = 0;
	acg.cg_cs.cs_nifree = 0;
E 9
D 7
	acg.cg_rotor = 0;
E 7
I 7
D 22
	acg.cg_rotor = dmin;
	acg.cg_frotor = dmin;
E 22
I 22
	acg.cg_rotor = 0;
	acg.cg_frotor = 0;
E 22
E 7
I 4
	acg.cg_irotor = 0;
I 49
	acg.cg_btotoff = &acg.cg_space[0] - (u_char *)(&acg.cg_link);
	acg.cg_boff = acg.cg_btotoff + sblock.fs_cpg * sizeof(long);
	acg.cg_iusedoff = acg.cg_boff + 
		sblock.fs_cpg * sblock.fs_nrpos * sizeof(short);
	acg.cg_freeoff = acg.cg_iusedoff + howmany(sblock.fs_ipg, NBBY);
	acg.cg_nextfreeoff = acg.cg_freeoff +
		howmany(sblock.fs_cpg * sblock.fs_spc / NSPF(&sblock), NBBY);
E 49
E 4
D 7
	i = 0;
	d = cgimin(c,&sblock);
	while (i < sblock.fs_ipg) {
E 7
I 7
D 10
	for (i = 0; i < FRAG; i++) {
E 10
I 10
	for (i = 0; i < sblock.fs_frag; i++) {
E 10
		acg.cg_frsum[i] = 0;
	}
D 49
	for (i = 0; i < sblock.fs_ipg; ) {
E 7
D 10
		for (j = INOPB; j > 0; j--) {
E 10
I 10
		for (j = INOPB(&sblock); j > 0; j--) {
E 10
			clrbit(acg.cg_iused, i);
			i++;
		}
D 9
		acg.cg_nifree += INOPB;
E 9
I 9
D 10
		acg.cg_cs.cs_nifree += INOPB;
E 10
I 10
		acg.cg_cs.cs_nifree += INOPB(&sblock);
E 10
E 9
D 7
		d++;
E 7
	}
E 49
I 49
	bzero((caddr_t)cg_inosused(&acg), acg.cg_freeoff - acg.cg_iusedoff);
	acg.cg_cs.cs_nifree += sblock.fs_ipg;
E 49
I 11
D 13
	if (c == 0)
E 13
I 13
	if (cylno == 0)
E 13
		for (i = 0; i < ROOTINO; i++) {
D 49
			setbit(acg.cg_iused, i);
E 49
I 49
			setbit(cg_inosused(&acg), i);
E 49
			acg.cg_cs.cs_nifree--;
		}
E 11
D 49
	while (i < MAXIPG) {
		clrbit(acg.cg_iused, i);
		i++;
	}
D 10
	lseek(fso, cgimin(c,&sblock)*FSIZE, 0);
E 10
I 10
D 13
	lseek(fso, fsbtodb(&sblock, cgimin(c,&sblock)) * DEV_BSIZE, 0);
E 13
I 13
D 15
	lseek(fso, fsbtodb(&sblock, cgimin(cylno,&sblock)) * DEV_BSIZE, 0);
E 15
I 15
D 36
	lseek(fso, fsbtodb(&sblock, cgimin(&sblock, cylno)) * DEV_BSIZE, 0);
E 15
E 13
E 10
	if (write(fso, (char *)zino, sblock.fs_ipg * sizeof (struct dinode)) !=
	    sblock.fs_ipg * sizeof (struct dinode))
D 10
		printf("write error %D\n", tell(fso) / BSIZE);
E 10
I 10
D 19
		printf("write error %D\n", tell(fso) / sblock.fs_bsize);
E 19
I 19
		printf("write error %D\n", numfrags(&sblock, tell(fso)));
E 36
I 36
	wtfs(fsbtodb(&sblock, cgimin(&sblock, cylno)),
	    sblock.fs_ipg * sizeof (struct dinode), (char *)zino);
E 36
E 19
E 10
D 14
	for (i = 0; i < MAXCPG; i++)
E 14
I 14
	for (i = 0; i < MAXCPG; i++) {
		acg.cg_btot[i] = 0;
E 14
		for (j = 0; j < NRPOS; j++)
			acg.cg_b[i][j] = 0;
I 14
	}
E 14
D 7
	dmin = cgdmin(c,&sblock) - cbase;
E 7
D 13
	if (c == 0) {
E 13
I 13
	if (cylno == 0) {
E 49
I 49
	for (i = 0; i < sblock.fs_ipg / INOPF(&sblock); i += sblock.fs_frag)
		wtfs(fsbtodb(&sblock, cgimin(&sblock, cylno) + i),
		    sblock.fs_bsize, (char *)zino);
	bzero((caddr_t)cg_blktot(&acg), acg.cg_boff - acg.cg_btotoff);
	bzero((caddr_t)cg_blks(&sblock, &acg, 0),
	    acg.cg_iusedoff - acg.cg_boff);
	bzero((caddr_t)cg_blksfree(&acg), acg.cg_nextfreeoff - acg.cg_freeoff);
	if (cylno > 0) {
E 49
E 13
D 10
		dmin += howmany(cssize(&sblock), BSIZE) * FRAG;
E 10
I 10
D 22
		dmin += howmany(sblock.fs_cssize, sblock.fs_bsize) *
			sblock.fs_frag;
E 22
I 22
		/*
D 49
		 * reserve space for summary info and Boot block
E 49
I 49
		 * In cylno 0, beginning space is reserved
		 * for boot and super blocks.
E 49
		 */
D 49
		dupper += howmany(sblock.fs_cssize, sblock.fs_fsize);
		for (d = 0; d < dlower; d += sblock.fs_frag)
			clrblock(&sblock, acg.cg_free, d/sblock.fs_frag);
	} else {
E 49
		for (d = 0; d < dlower; d += sblock.fs_frag) {
D 49
			setblock(&sblock, acg.cg_free, d/sblock.fs_frag);
E 49
I 49
			setblock(&sblock, cg_blksfree(&acg), d/sblock.fs_frag);
E 49
			acg.cg_cs.cs_nbfree++;
D 49
			acg.cg_btot[cbtocylno(&sblock, d)]++;
			acg.cg_b[cbtocylno(&sblock, d)][cbtorpos(&sblock, d)]++;
E 49
I 49
			cg_blktot(&acg)[cbtocylno(&sblock, d)]++;
			cg_blks(&sblock, &acg, cbtocylno(&sblock, d))
			    [cbtorpos(&sblock, d)]++;
E 49
		}
		sblock.fs_dsize += dlower;
E 22
E 10
	}
D 10
	for (d = 0; d < dmin; d += FRAG)
		clrblock(acg.cg_free, d/FRAG);
	while ((d+FRAG) <= dmax - cbase) {
D 2
		if (badblk(cbase+d))
			clrblock(acg.cg_free, d/FRAG);
		else {
			setblock(acg.cg_free, d/FRAG);
			acg.cg_nbfree++;
			s = d * NSPF;
			acg.cg_b[s/sblock.fs_spc]
			    [s%sblock.fs_nsect*NRPOS/sblock.fs_nsect]++;
		}
E 2
I 2
		setblock(acg.cg_free, d/FRAG);
E 10
I 10
D 22
	for (d = 0; d < dmin; d += sblock.fs_frag)
E 22
I 22
	sblock.fs_dsize += acg.cg_ndblk - dupper;
D 49
	for (; d < dupper; d += sblock.fs_frag)
E 22
		clrblock(&sblock, acg.cg_free, d/sblock.fs_frag);
D 22
	while ((d+sblock.fs_frag) <= dmax - cbase) {
E 22
I 22
	if (d > dupper) {
		acg.cg_frsum[d - dupper]++;
		for (i = d - 1; i >= dupper; i--) {
			setbit(acg.cg_free, i);
E 49
I 49
	if (i = dupper % sblock.fs_frag) {
		acg.cg_frsum[sblock.fs_frag - i]++;
		for (d = dupper + sblock.fs_frag - i; dupper < d; dupper++) {
			setbit(cg_blksfree(&acg), dupper);
E 49
			acg.cg_cs.cs_nffree++;
		}
	}
D 49
	while ((d + sblock.fs_frag) <= dmax - cbase) {
E 22
		setblock(&sblock, acg.cg_free, d/sblock.fs_frag);
E 49
I 49
	for (d = dupper; d + sblock.fs_frag <= dmax - cbase; ) {
		setblock(&sblock, cg_blksfree(&acg), d / sblock.fs_frag);
E 49
E 10
D 9
		acg.cg_nbfree++;
E 9
I 9
		acg.cg_cs.cs_nbfree++;
I 14
D 49
		acg.cg_btot[cbtocylno(&sblock, d)]++;
E 14
E 9
D 10
		s = d * NSPF;
		acg.cg_b[s/sblock.fs_spc]
		    [s%sblock.fs_nsect*NRPOS/sblock.fs_nsect]++;
E 2
		d += FRAG;
E 10
I 10
D 13
		s = d * NSPF(&sblock);
		acg.cg_b[s / sblock.fs_spc]
		    [s % sblock.fs_nsect * NRPOS / sblock.fs_nsect]++;
E 13
I 13
		acg.cg_b[cbtocylno(&sblock, d)][cbtorpos(&sblock, d)]++;
E 49
I 49
		cg_blktot(&acg)[cbtocylno(&sblock, d)]++;
		cg_blks(&sblock, &acg, cbtocylno(&sblock, d))
		    [cbtorpos(&sblock, d)]++;
E 49
E 13
		d += sblock.fs_frag;
E 10
	}
D 22
	if (d < dmax - cbase)
E 22
I 22
	if (d < dmax - cbase) {
E 22
I 13
		acg.cg_frsum[dmax - cbase - d]++;
E 13
D 2
		if (badblk(d))
			for (; d < dmax - cbase; d++)
				clrbit(acg.cg_free, d);
		else
			for (; d < dmax - cbase; d++) {
				setbit(acg.cg_free, d);
				acg.cg_nffree++;
			}
E 2
I 2
		for (; d < dmax - cbase; d++) {
D 49
			setbit(acg.cg_free, d);
E 49
I 49
			setbit(cg_blksfree(&acg), d);
E 49
D 9
			acg.cg_nffree++;
E 9
I 9
			acg.cg_cs.cs_nffree++;
E 9
		}
I 23
D 49
		for (; d % sblock.fs_frag != 0; d++)
			clrbit(acg.cg_free, d);
E 49
E 23
I 22
	}
E 22
E 2
D 10
	for (; d < MAXBPG; d++)
E 10
I 10
D 23
	for (; d < MAXBPG(&sblock); d++)
E 10
		clrbit(acg.cg_free, d);
E 23
I 23
D 49
	for (d /= sblock.fs_frag; d < MAXBPG(&sblock); d ++)
		clrblock(&sblock, acg.cg_free, d);
E 49
E 23
D 9
	sblock.fs_nffree += acg.cg_nffree;
	sblock.fs_nbfree += acg.cg_nbfree;
	cs->cs_nifree = acg.cg_nifree;
	cs->cs_nbfree = acg.cg_nbfree;
E 9
I 9
D 22
	sblock.fs_dsize += acg.cg_ndblk - dmin;
E 22
	sblock.fs_cstotal.cs_ndir += acg.cg_cs.cs_ndir;
	sblock.fs_cstotal.cs_nffree += acg.cg_cs.cs_nffree;
	sblock.fs_cstotal.cs_nbfree += acg.cg_cs.cs_nbfree;
	sblock.fs_cstotal.cs_nifree += acg.cg_cs.cs_nifree;
	*cs = acg.cg_cs;
E 9
D 10
	wtfs(cgtod(c, &sblock), BSIZE, (char *)&acg);
E 10
I 10
D 13
	wtfs(fsbtodb(&sblock, cgtod(c, &sblock)),
E 13
I 13
D 15
	wtfs(fsbtodb(&sblock, cgtod(cylno, &sblock)),
E 15
I 15
	wtfs(fsbtodb(&sblock, cgtod(&sblock, cylno)),
E 15
E 13
		sblock.fs_bsize, (char *)&acg);
E 10
}

D 11
cfile(par)
D 10
struct inode *par;
E 10
I 10
	struct inode *par;
E 10
{
	struct inode in;
	int dbc, ibc;
D 10
	char db[BSIZE];
	daddr_t ib[NINDIR];
E 10
I 10
	char db[MAXBSIZE];
	daddr_t ib[MAXBSIZE / sizeof(daddr_t)];
E 10
	int i, f, c;
E 11
I 11
/*
 * initialize the file system
 */
struct inode node;
I 43

#ifdef LOSTDIR
E 43
#define PREDEFDIR 3
I 43
#else
#define PREDEFDIR 2
#endif

E 43
D 18
struct direct root_dir[MAXNDIR] = {
	{ ROOTINO, ".", 0, IFDIR },
	{ ROOTINO, "..", 0, IFDIR },
	{ LOSTFOUNDINO, "lost+found", 0, IFDIR },
E 18
I 18
struct direct root_dir[] = {
	{ ROOTINO, sizeof(struct direct), 1, "." },
	{ ROOTINO, sizeof(struct direct), 2, ".." },
I 43
#ifdef LOSTDIR
E 43
	{ LOSTFOUNDINO, sizeof(struct direct), 10, "lost+found" },
I 43
#endif
E 43
E 18
};
I 43
#ifdef LOSTDIR
E 43
D 18
struct direct lost_found_dir[MAXNDIR] = {
	{ LOSTFOUNDINO, ".", 0, IFDIR },
	{ ROOTINO, "..", 0, IFDIR },
E 18
I 18
struct direct lost_found_dir[] = {
	{ LOSTFOUNDINO, sizeof(struct direct), 1, "." },
	{ ROOTINO, sizeof(struct direct), 2, ".." },
	{ 0, DIRBLKSIZ, 0, 0 },
E 18
};
I 43
#endif
E 43
I 18
char buf[MAXBSIZE];
E 18
E 11

I 11
fsinit()
{
I 18
	int i;

E 18
E 11
	/*
D 11
	 * get mode, uid and gid
E 11
I 11
	 * initialize the node
E 11
	 */
D 11

	getstr();
	in.i_mode = gmode(string[0], "-bcd", IFREG, IFBLK, IFCHR, IFDIR);
	in.i_mode |= gmode(string[1], "-u", 0, ISUID, 0, 0);
	in.i_mode |= gmode(string[2], "-g", 0, ISGID, 0, 0);
	for(i=3; i<6; i++) {
		c = string[i];
		if(c<'0' || c>'7') {
			printf("%c/%s: bad octal mode digit\n", c, string);
			error = 1;
			c = 0;
		}
		in.i_mode |= (c-'0')<<(15-3*i);
	}
	in.i_uid = getnum();
	in.i_gid = getnum();
I 2
	in.i_atime = utime;
	in.i_mtime = utime;
	in.i_ctime = utime;
E 2

E 11
I 11
	node.i_atime = utime;
	node.i_mtime = utime;
	node.i_ctime = utime;
I 43
#ifdef LOSTDIR
E 43
E 11
	/*
D 11
	 * general initialization prior to
	 * switching on format
E 11
I 11
	 * create the lost+found directory
E 11
	 */
I 18
	(void)makedir(lost_found_dir, 2);
	for (i = DIRBLKSIZ; i < sblock.fs_bsize; i += DIRBLKSIZ)
		bcopy(&lost_found_dir[2], &buf[i], DIRSIZ(&lost_found_dir[2]));
E 18
D 11

	ino++;
	in.i_number = ino;
D 10
	for(i=0; i<BSIZE; i++)
E 10
I 10
	for(i=0; i<sblock.fs_bsize; i++)
E 10
		db[i] = 0;
D 10
	for(i=0; i<NINDIR; i++)
E 10
I 10
	for(i=0; i<NINDIR(&sblock); i++)
E 10
		ib[i] = (daddr_t)0;
	in.i_nlink = 1;
	in.i_size = 0;
	for(i=0; i<NDADDR; i++)
D 2
		in.i_un.i_f.i_db[i] = (daddr_t)0;
E 2
I 2
		in.i_db[i] = (daddr_t)0;
E 2
	for(i=0; i<NIADDR; i++)
D 2
		in.i_un.i_f.i_ib[i] = (daddr_t)0;
E 2
I 2
		in.i_ib[i] = (daddr_t)0;
E 2
	if(par == (struct inode *)0) {
		par = &in;
		in.i_nlink--;
	}
	dbc = 0;
	ibc = 0;
	switch(in.i_mode&IFMT) {

	case IFREG:
		/*
		 * regular file
		 * contents is a file name
		 */

		getstr();
		f = open(string, 0);
		if(f < 0) {
			printf("%s: cannot open\n", string);
			error = 1;
			break;
		}
D 10
		while((i=read(f, db, BSIZE)) > 0) {
E 10
I 10
		while((i = read(f, db, sblock.fs_bsize)) > 0) {
E 10
			in.i_size += i;
D 5
			newblk(&dbc, db, &ibc, ib, i);
E 5
I 5
D 6
			newblk(&dbc, db, &ibc, ib, BSIZE);
E 6
I 6
D 10
			newblk(&dbc, db, &ibc, ib, ibc < NDADDR ? i : BSIZE, 0);
E 10
I 10
			newblk(&dbc, db, &ibc, ib,
				ibc < NDADDR ? i : sblock.fs_bsize, 0);
E 10
E 6
E 5
		}
		close(f);
		break;

	case IFBLK:
	case IFCHR:
		/*
		 * special file
		 * content is maj/min types
		 */

		i = getnum() & 0377;
		f = getnum() & 0377;
D 2
		in.i_un.i_d.i_rdev = makedev(i, f);
E 2
I 2
		in.i_rdev = makedev(i, f);
E 2
		break;

	case IFDIR:
		/*
		 * directory
		 * put in extra links
		 * call recursively until
		 * name of "$" found
		 */

		par->i_nlink++;
		in.i_nlink++;
		entry(in.i_number, ".", &dbc, db, &ibc, ib);
		entry(par->i_number, "..", &dbc, db, &ibc, ib);
		in.i_size = 2*sizeof(struct direct);
		for(;;) {
			getstr();
			if(string[0]=='$' && string[1]=='\0')
				break;
D 6
			if (in.i_size >= FSIZE) {
E 6
I 6
D 10
			if (in.i_size >= BSIZE * NDADDR) {
E 10
I 10
			if (in.i_size >= sblock.fs_bsize * NDADDR) {
E 10
E 6
				printf("can't handle direct of > %d entries\n",
D 6
				    NDIRECT/FRAG);
E 6
I 6
D 10
				    NDIRECT * NDADDR);
E 10
I 10
				    NDIRECT(&sblock) * NDADDR);
E 10
E 6
				exit(1);
			}
			entry(ino+1, string, &dbc, db, &ibc, ib);
			in.i_size += sizeof(struct direct);
			cfile(&in);
		}
I 6
D 10
		newblk(&dbc, db, &ibc, ib, roundup(dbc, FSIZE), IFDIR);
E 10
I 10
		newblk(&dbc, db, &ibc, ib, roundup(dbc, sblock.fs_fsize),
			IFDIR);
E 10
E 6
		break;
	}
D 6
	if(dbc != 0)
D 5
		newblk(&dbc, db, &ibc, ib, roundup(dbc,FSIZE));
E 5
I 5
		newblk(&dbc, db, &ibc, ib, roundup(dbc,BSIZE));
E 6
E 5
	iput(&in, &ibc, ib);
E 11
I 11
	node.i_number = LOSTFOUNDINO;
	node.i_mode = IFDIR | UMASK;
	node.i_nlink = 2;
	node.i_size = sblock.fs_bsize;
	node.i_db[0] = alloc(node.i_size, node.i_mode);
I 32
D 35
	node.i_blocks = howmany(node.i_size, DEV_BSIZE);
E 35
I 35
	node.i_blocks = btodb(fragroundup(&sblock, node.i_size));
E 35
E 32
D 18
	wtfs(fsbtodb(&sblock, node.i_db[0]), node.i_size, lost_found_dir);
E 18
I 18
	wtfs(fsbtodb(&sblock, node.i_db[0]), node.i_size, buf);
E 18
	iput(&node);
I 43
#endif
E 43
	/*
	 * create the root directory
	 */
	node.i_number = ROOTINO;
	node.i_mode = IFDIR | UMASK;
	node.i_nlink = PREDEFDIR;
D 18
	node.i_size = PREDEFDIR * sizeof(struct direct);
E 18
I 18
	node.i_size = makedir(root_dir, PREDEFDIR);
E 18
	node.i_db[0] = alloc(sblock.fs_fsize, node.i_mode);
I 32
D 35
	node.i_blocks = howmany(node.i_size, DEV_BSIZE);
E 35
I 35
	node.i_blocks = btodb(fragroundup(&sblock, node.i_size));
E 35
E 32
D 18
	wtfs(fsbtodb(&sblock, node.i_db[0]), sblock.fs_fsize, root_dir);
E 18
I 18
	wtfs(fsbtodb(&sblock, node.i_db[0]), sblock.fs_fsize, buf);
E 18
	iput(&node);
E 11
}

D 11
gmode(c, s, m0, m1, m2, m3)
D 10
char c, *s;
E 10
I 10
	char c, *s;
	int m0, m1, m2, m3;
E 10
{
	int i;

	for(i=0; s[i]; i++)
		if(c == s[i])
			return((&m0)[i]);
	printf("%c/%s: bad mode\n", c, string);
	error = 1;
	return(0);
}

long
getnum()
{
	int i, c;
	long n;

	getstr();
	n = 0;
	i = 0;
	for(i=0; c=string[i]; i++) {
		if(c<'0' || c>'9') {
			printf("%s: bad number\n", string);
			error = 1;
			return((long)0);
		}
		n = n*10 + (c-'0');
	}
	return(n);
}

getstr()
{
	int i, c;

loop:
	switch(c=getch()) {

	case ' ':
	case '\t':
	case '\n':
		goto loop;

	case '\0':
		printf("EOF\n");
		exit(1);

	case ':':
		while(getch() != '\n');
		goto loop;

	}
	i = 0;

	do {
		string[i++] = c;
		c = getch();
	} while(c!=' '&&c!='\t'&&c!='\n'&&c!='\0');
	string[i] = '\0';
}

rdfs(bno, size, bf)
D 10
daddr_t bno;
int size;
char *bf;
E 10
I 10
	daddr_t bno;
	int size;
	char *bf;
E 10
{
	int n;

D 10
	lseek(fsi, bno*FSIZE, 0);
E 10
I 10
	lseek(fsi, bno * DEV_BSIZE, 0);
E 10
	n = read(fsi, bf, size);
	if(n != size) {
		printf("read error: %ld\n", bno);
		exit(1);
	}
}

wtfs(bno, size, bf)
D 10
daddr_t bno;
int size;
char *bf;
E 10
I 10
	daddr_t bno;
	int size;
	char *bf;
E 10
{
	int n;

D 10
	lseek(fso, bno*FSIZE, 0);
E 10
I 10
	lseek(fso, bno * DEV_BSIZE, 0);
E 10
	n = write(fso, bf, size);
	if(n != size) {
		printf("write error: %D\n", bno);
		exit(1);
	}
}

E 11
I 11
/*
I 18
 * construct a set of directory entries in "buf".
 * return size of directory.
 */
makedir(protodir, entries)
	register struct direct *protodir;
	int entries;
{
	char *cp;
	int i, spcleft;

	spcleft = DIRBLKSIZ;
	for (cp = buf, i = 0; i < entries - 1; i++) {
		protodir[i].d_reclen = DIRSIZ(&protodir[i]);
		bcopy(&protodir[i], cp, protodir[i].d_reclen);
		cp += protodir[i].d_reclen;
		spcleft -= protodir[i].d_reclen;
	}
	protodir[i].d_reclen = spcleft;
	bcopy(&protodir[i], cp, DIRSIZ(&protodir[i]));
D 41
	cp += DIRSIZ(&protodir[i]);
	return (cp - buf);
E 41
I 41
	return (DIRBLKSIZ);
E 41
}

/*
E 18
 * allocate a block or frag
 */
E 11
daddr_t
D 6
alloc(size)
int size;
E 6
I 6
alloc(size, mode)
	int size;
	int mode;
E 6
{
D 13
	int c, i, s, frag;
E 13
I 13
	int i, frag;
E 13
	daddr_t d;

D 13
	c = 0;
E 13
D 10
	rdfs(cgtod(0,&sblock), sblock.fs_cgsize, (char *)&acg);
E 10
I 10
D 15
	rdfs(fsbtodb(&sblock, cgtod(0,&sblock)),
E 15
I 15
D 19
	rdfs(fsbtodb(&sblock, cgtod(&sblock, 0)),
E 15
D 11
		sblock.fs_cgsize, (char *)&acg);
E 11
I 11
		roundup(sblock.fs_cgsize, DEV_BSIZE), (char *)&acg);
E 19
I 19
	rdfs(fsbtodb(&sblock, cgtod(&sblock, 0)), sblock.fs_cgsize,
	    (char *)&acg);
I 22
	if (acg.cg_magic != CG_MAGIC) {
		printf("cg 0: bad magic number\n");
		return (0);
	}
E 22
E 19
E 11
E 10
D 9
	if (acg.cg_nbfree == 0) {
E 9
I 9
	if (acg.cg_cs.cs_nbfree == 0) {
E 9
		printf("first cylinder group ran out of space\n");
		return (0);
	}
D 10
	for (d = 0; d < acg.cg_ndblk; d += FRAG)
		if (isblock(acg.cg_free, d/FRAG))
E 10
I 10
	for (d = 0; d < acg.cg_ndblk; d += sblock.fs_frag)
D 49
		if (isblock(&sblock, acg.cg_free, d / sblock.fs_frag))
E 49
I 49
		if (isblock(&sblock, cg_blksfree(&acg), d / sblock.fs_frag))
E 49
E 10
			goto goth;
	printf("internal error: can't find block in cyl 0\n");
	return (0);
goth:
D 10
	clrblock(acg.cg_free, d/FRAG);
E 10
I 10
D 49
	clrblock(&sblock, acg.cg_free, d / sblock.fs_frag);
E 49
I 49
	clrblock(&sblock, cg_blksfree(&acg), d / sblock.fs_frag);
E 49
E 10
D 9
	acg.cg_nbfree--;
	sblock.fs_nbfree--;
E 9
I 9
	acg.cg_cs.cs_nbfree--;
	sblock.fs_cstotal.cs_nbfree--;
E 9
	fscs[0].cs_nbfree--;
I 6
	if (mode & IFDIR) {
D 9
		acg.cg_ndir++;
E 9
I 9
		acg.cg_cs.cs_ndir++;
		sblock.fs_cstotal.cs_ndir++;
E 9
		fscs[0].cs_ndir++;
	}
I 14
D 49
	acg.cg_btot[cbtocylno(&sblock, d)]--;
E 14
E 6
D 10
	s = d * NSPF;
	acg.cg_b[s/sblock.fs_spc][s%sblock.fs_nsect*NRPOS/sblock.fs_nsect]--;
	if (size != BSIZE) {
		frag = howmany(size, FSIZE);
D 9
		acg.cg_nffree += FRAG - frag;
E 9
I 9
		fscs[0].cs_nffree += FRAG - frag;
		sblock.fs_cstotal.cs_nffree += FRAG - frag;
		acg.cg_cs.cs_nffree += FRAG - frag;
E 9
I 7
		acg.cg_frsum[FRAG - frag]++;
E 7
D 9
		sblock.fs_nffree += FRAG - frag;
E 9
		for (i = frag; i < FRAG; i++)
E 10
I 10
D 13
	s = d * NSPF(&sblock);
	acg.cg_b[s / sblock.fs_spc]
		[s % sblock.fs_nsect * NRPOS / sblock.fs_nsect]--;
E 13
I 13
	acg.cg_b[cbtocylno(&sblock, d)][cbtorpos(&sblock, d)]--;
E 49
I 49
	cg_blktot(&acg)[cbtocylno(&sblock, d)]--;
	cg_blks(&sblock, &acg, cbtocylno(&sblock, d))[cbtorpos(&sblock, d)]--;
E 49
E 13
	if (size != sblock.fs_bsize) {
		frag = howmany(size, sblock.fs_fsize);
		fscs[0].cs_nffree += sblock.fs_frag - frag;
		sblock.fs_cstotal.cs_nffree += sblock.fs_frag - frag;
		acg.cg_cs.cs_nffree += sblock.fs_frag - frag;
		acg.cg_frsum[sblock.fs_frag - frag]++;
		for (i = frag; i < sblock.fs_frag; i++)
E 10
D 22
			setbit(acg.cg_free, d+i);
E 22
I 22
D 49
			setbit(acg.cg_free, d + i);
E 49
I 49
			setbit(cg_blksfree(&acg), d + i);
E 49
E 22
	}
D 10
	wtfs(cgtod(0,&sblock), sblock.fs_cgsize, (char *)&acg);
E 10
I 10
D 15
	wtfs(fsbtodb(&sblock, cgtod(0,&sblock)),
E 15
I 15
D 19
	wtfs(fsbtodb(&sblock, cgtod(&sblock, 0)),
E 15
		roundup(sblock.fs_cgsize, DEV_BSIZE), (char *)&acg);
E 19
I 19
	wtfs(fsbtodb(&sblock, cgtod(&sblock, 0)), sblock.fs_cgsize,
	    (char *)&acg);
E 19
E 10
	return (d);
}

D 11
entry(inum, str, adbc, db, aibc, ib)
D 10
ino_t inum;
char *str;
int *adbc, *aibc;
char *db;
daddr_t *ib;
E 10
I 10
	ino_t inum;
	char *str;
	int *adbc, *aibc;
	char *db;
	daddr_t *ib;
E 11
I 11
/*
 * Allocate an inode on the disk
 */
iput(ip)
	register struct inode *ip;
E 11
E 10
{
D 11
	struct direct *dp;
	int i;

I 6
D 10
	if (*adbc == NDIRECT)
		newblk(adbc, db, aibc, ib, BSIZE, 0);
E 10
I 10
	if (*adbc == NDIRECT(&sblock))
		newblk(adbc, db, aibc, ib, sblock.fs_bsize, 0);
E 10
E 6
	dp = (struct direct *)db;
	dp += *adbc;
	(*adbc)++;
	dp->d_ino = inum;
D 10
	for(i=0; i<DIRSIZ; i++)
E 10
I 10
	for(i=0; i < DIRSIZ; i++)
E 10
		dp->d_name[i] = 0;
D 10
	for(i=0; i<DIRSIZ; i++)
E 10
I 10
	for(i=0; i < DIRSIZ; i++)
E 10
		if((dp->d_name[i] = str[i]) == 0)
			break;
D 6
	if(*adbc >= NDIRECT)
		newblk(adbc, db, aibc, ib, BSIZE);
E 6
}

D 6
newblk(adbc, db, aibc, ib, size)
int *adbc, *aibc;
char *db;
daddr_t *ib;
int size;
E 6
I 6
newblk(adbc, db, aibc, ib, size, mode)
	int *adbc, *aibc;
	char *db;
	daddr_t *ib;
	int size;
	int mode;
E 6
{
	int i;
	daddr_t bno;

D 6
	bno = alloc(size);
E 6
I 6
	bno = alloc(size, mode);
E 6
D 10
	wtfs(bno, size, db);
	for(i=0; i<size; i++)
E 10
I 10
	wtfs(fsbtodb(&sblock, bno), size, db);
	for(i = 0; i < size; i++)
E 10
		db[i] = 0;
	*adbc = 0;
	ib[*aibc] = bno;
	(*aibc)++;
D 10
	if(*aibc >= NINDIR) {
E 10
I 10
	if(*aibc >= NINDIR(&sblock)) {
E 10
		printf("indirect block full\n");
		error = 1;
		*aibc = 0;
	}
}

getch()
{

#ifndef STANDALONE
	if(charp)
#endif
		return(*charp++);
#ifndef STANDALONE
	return(getc(fin));
#endif
}

iput(ip, aibc, ib)
D 10
struct inode *ip;
int *aibc;
daddr_t *ib;
E 10
I 10
	struct inode *ip;
	int *aibc;
	daddr_t *ib;
E 10
{
	struct dinode *dp;
E 11
I 11
	struct dinode buf[MAXINOPB];
E 11
	daddr_t d;
D 11
	int i, c = ip->i_number / sblock.fs_ipg;
E 11
I 11
	int c;
E 11

I 11
D 15
	c = itog(ip->i_number, &sblock);
E 11
D 10
	rdfs(cgtod(c,&sblock), sblock.fs_cgsize, (char *)&acg);
E 10
I 10
	rdfs(fsbtodb(&sblock, cgtod(c,&sblock)),
E 15
I 15
	c = itog(&sblock, ip->i_number);
D 19
	rdfs(fsbtodb(&sblock, cgtod(&sblock, c)),
E 15
D 11
		sblock.fs_cgsize, (char *)&acg);
E 11
I 11
		roundup(sblock.fs_cgsize, DEV_BSIZE), (char *)&acg);
E 19
I 19
	rdfs(fsbtodb(&sblock, cgtod(&sblock, 0)), sblock.fs_cgsize,
	    (char *)&acg);
I 22
	if (acg.cg_magic != CG_MAGIC) {
		printf("cg 0: bad magic number\n");
		exit(1);
	}
E 22
E 19
E 11
E 10
D 9
	acg.cg_nifree--;
E 9
I 9
	acg.cg_cs.cs_nifree--;
E 9
D 49
	setbit(acg.cg_iused, ip->i_number);
E 49
I 49
	setbit(cg_inosused(&acg), ip->i_number);
E 49
D 10
	wtfs(cgtod(c,&sblock), sblock.fs_cgsize, (char *)&acg);
E 10
I 10
D 15
	wtfs(fsbtodb(&sblock, cgtod(c,&sblock)),
E 15
I 15
D 19
	wtfs(fsbtodb(&sblock, cgtod(&sblock, c)),
E 15
		roundup(sblock.fs_cgsize, DEV_BSIZE), (char *)&acg);
E 19
I 19
	wtfs(fsbtodb(&sblock, cgtod(&sblock, 0)), sblock.fs_cgsize,
	    (char *)&acg);
E 19
E 10
D 9
	sblock.fs_nifree--;
E 9
I 9
	sblock.fs_cstotal.cs_nifree--;
E 9
	fscs[0].cs_nifree--;
D 11
	if(ip->i_number >= sblock.fs_ipg) {
		printf("mkfs: cant handle more than one cg of inodes (yet)\n");
E 11
I 11
D 49
	if(ip->i_number >= sblock.fs_ipg * sblock.fs_ncg) {
E 49
I 49
	if (ip->i_number >= sblock.fs_ipg * sblock.fs_ncg) {
E 49
		printf("fsinit: inode value out of range (%d).\n",
		    ip->i_number);
E 11
		exit(1);
	}
D 11
	if(ip->i_number >= sblock.fs_ipg * sblock.fs_ncg) {
		if(error == 0)
			printf("ilist too small\n");
		error = 1;
		return;
E 11
I 11
D 15
	d = fsbtodb(&sblock, itod(ip->i_number, &sblock));
E 15
I 15
	d = fsbtodb(&sblock, itod(&sblock, ip->i_number));
E 15
	rdfs(d, sblock.fs_bsize, buf);
D 15
	buf[itoo(ip->i_number, &sblock)].di_ic = ip->i_ic;
E 15
I 15
	buf[itoo(&sblock, ip->i_number)].di_ic = ip->i_ic;
E 15
	wtfs(d, sblock.fs_bsize, buf);
}

/*
 * read a block from the file system
 */
rdfs(bno, size, bf)
	daddr_t bno;
	int size;
	char *bf;
{
	int n;

D 12
	lseek(fsi, bno * DEV_BSIZE, 0);
E 12
I 12
D 43
	if (lseek(fsi, bno * DEV_BSIZE, 0) < 0) {
E 43
I 43
	if (lseek(fsi, bno * sectorsize, 0) < 0) {
E 43
		printf("seek error: %ld\n", bno);
		perror("rdfs");
		exit(1);
	}
E 12
	n = read(fsi, bf, size);
	if(n != size) {
		printf("read error: %ld\n", bno);
I 12
		perror("rdfs");
E 12
		exit(1);
E 11
	}
D 11
	d = itod(ip->i_number,&sblock);
D 10
	rdfs(d, BSIZE, buf);
D 2
	dp = (struct dinode *)buf;
	dp += itoo(ip->i_number);

	dp->di_mode = ip->i_mode;
	dp->di_nlink = ip->i_nlink;
	dp->di_uid = ip->i_uid;
	dp->di_gid = ip->i_gid;
	dp->di_size = ip->i_size;
	dp->di_atime = utime;
	dp->di_mtime = utime;
	dp->di_ctime = utime;

	switch(ip->i_mode&IFMT) {

	case IFDIR:
	case IFREG:
		for(i=0; i<*aibc; i++) {
			if(i >= NDADDR)
				break;
			ip->i_un.i_f.i_db[i] = ib[i];
E 2
I 2
	for(i=0; i<*aibc; i++) {
E 10
I 10
	rdfs(fsbtodb(&sblock, d), sblock.fs_bsize, buf);
	for(i = 0; i < *aibc; i++) {
E 10
		if(i >= NDADDR)
			break;
		ip->i_db[i] = ib[i];
	}
	if(*aibc >= NDADDR) {
D 6
		ip->i_ib[0] = alloc(BSIZE);
E 6
I 6
D 10
		ip->i_ib[0] = alloc(BSIZE, 0);
E 6
		for(i=0; i<NINDIR-NDADDR; i++) {
E 10
I 10
		ip->i_ib[0] = alloc(sblock.fs_bsize, 0);
		for(i=0; i<NINDIR(&sblock)-NDADDR; i++) {
E 10
			ib[i] = ib[i+NDADDR];
			ib[i+NDADDR] = (daddr_t)0;
E 2
		}
D 2
		if(*aibc >= NDADDR) {
			ip->i_un.i_f.i_ib[0] = alloc(BSIZE);
			for(i=0; i<NINDIR-NDADDR; i++) {
				ib[i] = ib[i+NDADDR];
				ib[i+NDADDR] = (daddr_t)0;
			}
			wtfs(ip->i_un.i_f.i_ib[0], (char *)ib);
		}

	case IFBLK:
	case IFCHR:
		ltol3(dp->di_addr, ip->i_un.i_f.i_db, NDADDR+NIADDR);
		break;

	default:
		printf("bad mode %o\n", ip->i_mode);
		exit(1);
E 2
I 2
D 10
		wtfs(ip->i_ib[0], (char *)ib);
E 10
I 10
		wtfs(fsbtodb(&sblock, ip->i_ib[0]), sblock.fs_bsize,
			(char *)ib);
E 10
E 2
	}
I 2
D 10
	((struct dinode *)buf+itoo(ip->i_number))->di_ic = ip->i_ic;
E 2
	wtfs(d, BSIZE, buf);
E 10
I 10
	((struct dinode *)buf + itoo(ip->i_number, &sblock))->di_ic = ip->i_ic;
	wtfs(fsbtodb(&sblock, d), sblock.fs_bsize, buf);
E 11
}

/*
D 11
 * block operations
E 11
I 11
 * write a block to the file system
E 11
 */
I 11
wtfs(bno, size, bf)
	daddr_t bno;
	int size;
	char *bf;
{
	int n;
E 11

I 36
	if (Nflag)
		return;
E 36
I 11
D 12
	printf("wtfs: bno %d, size %d, buf %d\n", bno, size, bf);
E 12
D 30
	lseek(fso, bno * DEV_BSIZE, 0);
E 30
I 12
D 43
	if (lseek(fso, bno * DEV_BSIZE, 0) < 0) {
E 43
I 43
	if (lseek(fso, bno * sectorsize, 0) < 0) {
E 43
		printf("seek error: %ld\n", bno);
		perror("wtfs");
		exit(1);
	}
E 12
	n = write(fso, bf, size);
	if(n != size) {
D 50
		printf("write error: %D\n", bno);
E 50
I 50
		printf("write error: %ld\n", bno);
E 50
I 12
		perror("wtfs");
E 12
		exit(1);
	}
I 18
}
D 27

I 24
#ifndef STANDALONE
E 24
/*
 * copy a block
 */
bcopy(from, to, size)
	char *from, *to;
	int size;
{
	asm("	movc3	12(ap),*4(ap),*8(ap)");
E 18
}
I 24
#endif
E 27
E 24

/*
 * check if a block is available
 */
E 11
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
I 24
#ifdef STANDALONE
		printf("isblock bad fs_frag %d\n", fs->fs_frag);
#else
E 24
		fprintf(stderr, "isblock bad fs_frag %d\n", fs->fs_frag);
I 24
#endif
E 24
D 48
		return;
E 48
I 48
		return (0);
E 48
	}
}

I 11
/*
 * take a block out of the map
 */
E 11
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
I 24
#ifdef STANDALONE
		printf("clrblock bad fs_frag %d\n", fs->fs_frag);
#else
E 24
		fprintf(stderr, "clrblock bad fs_frag %d\n", fs->fs_frag);
I 24
#endif
E 24
		return;
	}
}

I 11
/*
 * put a block into the map
 */
E 11
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
I 24
#ifdef STANDALONE
		printf("setblock bad fs_frag %d\n", fs->fs_frag);
#else
E 24
		fprintf(stderr, "setblock bad fs_frag %d\n", fs->fs_frag);
I 24
#endif
E 24
		return;
	}
E 10
D 2
}

badblk(bno)
daddr_t bno;
{

	return(0);
E 2
}
E 1
