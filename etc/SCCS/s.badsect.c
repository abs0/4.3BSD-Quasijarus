h34058
s 00002/00002/00169
d D 5.4 88/05/31 17:54:01 mckusick 7 6
c convert to understand dynamic file systems
e
s 00004/00002/00167
d D 5.3 87/02/23 17:39:44 mckusick 6 5
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00001/00001/00168
d D 5.2 85/06/24 09:37:04 bloom 5 4
c fix a return value
e
s 00015/00001/00154
d D 5.1 85/06/06 11:00:48 dist 4 3
c Add copyright
e
s 00134/00008/00021
d D 4.3 83/02/24 14:28:27 mckusick 3 2
c update for new file system
e
s 00000/00000/00029
d D 4.2 81/05/11 03:25:16 root 2 1
c new version
e
s 00029/00000/00000
d D 4.1 81/05/10 19:24:43 root 1 0
c date and time created 81/05/10 19:24:43 by root
e
u
U
t
T
I 1
D 4
static	char *sccsid = "%W% (Berkeley) %E%";
E 4
I 4
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

#ifndef lint
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 4

/*
 * badsect
 *
 * Badsect takes a list of file-system relative sector numbers
 * and makes files containing the blocks of which these sectors are a part.
 * It can be used to contain sectors which have problems if these sectors
 * are not part of the bad file for the pack (see bad144).  For instance,
 * this program can be used if the driver for the file system in question
 * does not support bad block forwarding.
 */
I 3
#include <stdio.h>
E 3
#include <sys/param.h>
I 3
#include <sys/fs.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <sys/inode.h>
E 3

I 3
union {
	struct	fs fs;
	char	fsx[SBSIZE];
} ufs;
#define sblock	ufs.fs
union {
	struct	cg cg;
	char	cgx[MAXBSIZE];
} ucg;
#define	acg	ucg.cg
struct	fs *fs;
int	fso, fsi;
int	errs;
I 6
long	dev_bsize = 1;
E 6

char buf[MAXBSIZE];


E 3
main(argc, argv)
	int argc;
D 3
	char **argv;
E 3
I 3
	char *argv[];
E 3
{
D 3
	char nambuf[32];
	int errs = 0;
E 3
I 3
	daddr_t number;
	struct stat stbuf, devstat;
	register struct direct *dp;
	DIR *dirp;
	int fd;
	char name[BUFSIZ];
E 3

D 3
	--argc, argv++;
	while (argc > 0) {
		if (mknod(*argv, 0, atoi(*argv) / CLSIZE))
			perror("mknod"), errs++;
		argc--, argv++;
E 3
I 3
	if (argc < 3) {
		fprintf(stderr, "usage: badsect bbdir blkno [ blkno ]\n");
		exit(1);
E 3
	}
I 3
	if (chdir(argv[1]) < 0 || stat(".", &stbuf) < 0) {
		perror(argv[1]);
		exit(2);
	}
	strcpy(name, "/dev/");
	if ((dirp = opendir(name)) == NULL) {
		perror(name);
		exit(3);
	}
	while ((dp = readdir(dirp)) != NULL) {
		strcpy(&name[5], dp->d_name);
		if (stat(name, &devstat) < 0) {
			perror(name);
			exit(4);
		}
		if (stbuf.st_dev == devstat.st_rdev &&
		    (devstat.st_mode & IFMT) == IFBLK)
			break;
	}
	closedir(dirp);
	if (dp == NULL) {
		printf("Cannot find dev 0%o corresponding to %s\n",
			stbuf.st_rdev, argv[1]);
		exit(5);
	}
	if ((fsi = open(name, 0)) < 0) {
		perror(name);
		exit(6);
	}
	fs = &sblock;
D 6
	rdfs(SBLOCK, SBSIZE, (char *)fs);
E 6
I 6
	rdfs(SBOFF, SBSIZE, (char *)fs);
	dev_bsize = fs->fs_fsize / fsbtodb(fs, 1);
E 6
	for (argc -= 2, argv += 2; argc > 0; argc--, argv++) {
		number = atoi(*argv);
		if (chkuse(number, 1))
			continue;
		if (mknod(*argv, IFMT|0600, dbtofsb(fs, number)) < 0) {
			perror(*argv);
			errs++;
		}
	}
	printf("Don't forget to run ``fsck %s''\n", name);
E 3
	exit(errs);
I 3
}

chkuse(blkno, cnt)
	daddr_t blkno;
	int cnt;
{
	int cg;
	daddr_t fsbn, bn;

	fsbn = dbtofsb(fs, blkno);
	if ((unsigned)(fsbn+cnt) > fs->fs_size) {
		printf("block %d out of range of file system\n", blkno);
		return (1);
	}
	cg = dtog(fs, fsbn);
	if (fsbn < cgdmin(fs, cg)) {
		if (cg == 0 || (fsbn+cnt) > cgsblock(fs, cg)) {
			printf("block %d in non-data area: cannot attach\n",
				blkno);
			return (1);
		}
	} else {
		if ((fsbn+cnt) > cgbase(fs, cg+1)) {
			printf("block %d in non-data area: cannot attach\n",
				blkno);
			return (1);
		}
	}
	rdfs(fsbtodb(fs, cgtod(fs, cg)), (int)sblock.fs_cgsize,
	    (char *)&acg);
D 7
	if (acg.cg_magic != CG_MAGIC) {
E 7
I 7
	if (!cg_chkmagic(&acg)) {
E 7
		fprintf(stderr, "cg %d: bad magic number\n", cg);
		errs++;
D 5
		return;
E 5
I 5
		return (1);
E 5
	}
	bn = dtogd(fs, fsbn);
D 7
	if (isclr(acg.cg_free, bn))
E 7
I 7
	if (isclr(cg_blksfree(&acg), bn))
E 7
		printf("Warning: sector %d is in use\n", blkno);
	return (0);
}

/*
 * read a block from the file system
 */
rdfs(bno, size, bf)
	int bno, size;
	char *bf;
{
	int n;

D 6
	if (lseek(fsi, bno * DEV_BSIZE, 0) < 0) {
E 6
I 6
	if (lseek(fsi, bno * dev_bsize, 0) < 0) {
E 6
		printf("seek error: %ld\n", bno);
		perror("rdfs");
		exit(1);
	}
	n = read(fsi, bf, size);
	if(n != size) {
		printf("read error: %ld\n", bno);
		perror("rdfs");
		exit(1);
	}
E 3
}
E 1
