h35506
s 00000/00002/00261
d D 5.6 88/01/03 19:25:31 mckusick 10 9
c allow negative rotational delays (for torek)
e
s 00002/00002/00261
d D 5.5 87/10/22 10:51:09 bostic 9 8
c ANSI C; sprintf now returns an int.
e
s 00006/00004/00257
d D 5.4 87/02/23 17:40:09 mckusick 8 7
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00012/00000/00249
d D 5.3 85/09/11 23:34:13 mckusick 7 6
c add warnings relating to optimization
e
s 00029/00002/00220
d D 5.2 85/09/11 22:31:23 mckusick 6 5
c allow users to specify optimization preference
e
s 00014/00002/00208
d D 5.1 85/05/28 15:41:47 dist 5 4
c Add copyright
e
s 00001/00001/00209
d D 4.4 83/07/01 03:19:52 sam 4 3
c correct spelling 
e
s 00007/00001/00203
d D 4.3 83/06/14 22:19:06 sam 3 2
c take file system names as well
e
s 00001/00001/00203
d D 4.2 83/02/26 13:24:07 sam 2 1
c oversight
e
s 00204/00000/00000
d D 4.1 83/02/26 00:19:48 mckusick 1 0
c date and time created 83/02/26 00:19:48 by mckusick
e
u
U
t
T
I 5
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 5
I 1
#ifndef lint
D 5
static	char *sccsid = "%W% (Berkeley) %G%";
#endif lint
E 5
I 5
char copyright[] =
"%Z% Copyright (c) 1983 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
#endif not lint
E 5

/*
 * tunefs: change layout parameters to an existing file system.
 */

D 3
#include <stdio.h>
E 3
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/fs.h>
#include <sys/inode.h>

I 3
#include <stdio.h>
#include <fstab.h>

E 3
union {
	struct	fs sb;
	char pad[MAXBSIZE];
} sbun;
#define	sblock sbun.sb

int fi;
I 8
long dev_bsize = 1;
E 8

main(argc, argv)
	int argc;
	char *argv[];
{
	char *cp, *special, *name;
	struct stat st;
	int i;
	int Aflag = 0;
D 6
	char device[MAXPATHLEN];
	extern char *sprintf();
E 6
I 3
	struct fstab *fs;
I 6
	char *chg[2], device[MAXPATHLEN];
D 9
	extern char *sprintf();
E 9
E 6
E 3

	argc--, argv++; 
	if (argc < 2)
		goto usage;
	special = argv[argc - 1];
I 3
	fs = getfsfile(special);
	if (fs)
		special = fs->fs_spec;
E 3
again:
	if (stat(special, &st) < 0) {
		if (*special != '/') {
			if (*special == 'r')
				special++;
D 9
			special = sprintf(device, "/dev/%s", special);
E 9
I 9
			(void)sprintf(device, "/dev/%s", special);
			special = device;
E 9
			goto again;
		}
		fprintf(stderr, "tunefs: "); perror(special);
		exit(1);
	}
	if ((st.st_mode & S_IFMT) != S_IFBLK &&
	    (st.st_mode & S_IFMT) != S_IFCHR)
		fatal("%s: not a block or character device", special);
	getsb(&sblock, special);
	for (; argc > 0 && argv[0][0] == '-'; argc--, argv++) {
		for (cp = &argv[0][1]; *cp; cp++)
			switch (*cp) {

			case 'A':
				Aflag++;
				continue;

			case 'a':
				name = "maximum contiguous block count";
				if (argc < 1)
					fatal("-a: missing %s", name);
				argc--, argv++;
				i = atoi(*argv);
				if (i < 1)
					fatal("%s: %s must be >= 1",
						*argv, name);
				fprintf(stdout, "%s changes from %d to %d\n",
					name, sblock.fs_maxcontig, i);
				sblock.fs_maxcontig = i;
				continue;

			case 'd':
				name =
				   "rotational delay between contiguous blocks";
				if (argc < 1)
					fatal("-d: missing %s", name);
				argc--, argv++;
				i = atoi(*argv);
D 10
				if (i < 0)
					fatal("%s: bad %s", *argv, name);
E 10
				fprintf(stdout,
					"%s changes from %dms to %dms\n",
					name, sblock.fs_rotdelay, i);
				sblock.fs_rotdelay = i;
				continue;

			case 'e':
				name =
				  "maximum blocks per file in a cylinder group";
				if (argc < 1)
					fatal("-e: missing %s", name);
				argc--, argv++;
				i = atoi(*argv);
				if (i < 1)
					fatal("%s: %s must be >= 1",
						*argv, name);
				fprintf(stdout, "%s changes from %d to %d\n",
					name, sblock.fs_maxbpg, i);
				sblock.fs_maxbpg = i;
				continue;

			case 'm':
				name = "minimum percentage of free space";
				if (argc < 1)
					fatal("-m: missing %s", name);
				argc--, argv++;
				i = atoi(*argv);
				if (i < 0 || i > 99)
					fatal("%s: bad %s", *argv, name);
				fprintf(stdout,
					"%s changes from %d%% to %d%%\n",
					name, sblock.fs_minfree, i);
				sblock.fs_minfree = i;
I 7
				if (i >= 10 && sblock.fs_optim == FS_OPTSPACE)
					fprintf(stdout, "should optimize %s",
					    "for time with minfree >= 10%\n");
				if (i < 10 && sblock.fs_optim == FS_OPTTIME)
					fprintf(stdout, "should optimize %s",
					    "for space with minfree < 10%\n");
E 7
				continue;

I 6
			case 'o':
				name = "optimization preference";
				if (argc < 1)
					fatal("-o: missing %s", name);
				argc--, argv++;
				chg[FS_OPTSPACE] = "space";
				chg[FS_OPTTIME] = "time";
				if (strcmp(*argv, chg[FS_OPTSPACE]) == 0)
					i = FS_OPTSPACE;
				else if (strcmp(*argv, chg[FS_OPTTIME]) == 0)
					i = FS_OPTTIME;
				else
					fatal("%s: bad %s (options are `space' or `time')",
						*argv, name);
				if (sblock.fs_optim == i) {
					fprintf(stdout,
						"%s remains unchanged as %s\n",
						name, chg[i]);
					continue;
				}
				fprintf(stdout,
					"%s changes from %s to %s\n",
					name, chg[sblock.fs_optim], chg[i]);
				sblock.fs_optim = i;
I 7
				if (sblock.fs_minfree >= 10 && i == FS_OPTSPACE)
					fprintf(stdout, "should optimize %s",
					    "for time with minfree >= 10%\n");
				if (sblock.fs_minfree < 10 && i == FS_OPTTIME)
					fprintf(stdout, "should optimize %s",
					    "for space with minfree < 10%\n");
E 7
				continue;

E 6
			default:
				fatal("-%c: unknown flag", *cp);
			}
	}
	if (argc != 1)
		goto usage;
D 8
	bwrite(SBLOCK, (char *)&sblock, SBSIZE);
E 8
I 8
	bwrite(SBOFF / dev_bsize, (char *)&sblock, SBSIZE);
E 8
	if (Aflag)
		for (i = 0; i < sblock.fs_ncg; i++)
			bwrite(fsbtodb(&sblock, cgsblock(&sblock, i)),
			    (char *)&sblock, SBSIZE);
	close(fi);
	exit(0);
usage:
	fprintf(stderr, "Usage: tunefs tuneup-options special-device\n");
	fprintf(stderr, "where tuneup-options are:\n");
D 4
	fprintf(stderr, "\t-a maximum contigouous blocks\n");
E 4
I 4
	fprintf(stderr, "\t-a maximum contiguous blocks\n");
E 4
	fprintf(stderr, "\t-d rotational delay between contiguous blocks\n");
	fprintf(stderr, "\t-e maximum blocks per file in a cylinder group\n");
	fprintf(stderr, "\t-m minimum percentage of free space\n");
I 6
	fprintf(stderr, "\t-o optimization preference (`space' or `time')\n");
E 6
	exit(2);
}

getsb(fs, file)
	register struct fs *fs;
	char *file;
{

	fi = open(file, 2);
	if (fi < 0) {
		fprintf(stderr, "cannot open");
		perror(file);
		exit(3);
	}
D 8
	if (bread(SBLOCK, (char *)fs, SBSIZE)) {
E 8
I 8
	if (bread(SBOFF, (char *)fs, SBSIZE)) {
E 8
		fprintf(stderr, "bad super block");
		perror(file);
		exit(4);
	}
	if (fs->fs_magic != FS_MAGIC) {
		fprintf(stderr, "%s: bad magic number\n", file);
		exit(5);
	}
I 8
	dev_bsize = fs->fs_fsize / fsbtodb(fs, 1);
E 8
}

bwrite(blk, buf, size)
	char *buf;
	daddr_t blk;
	register size;
{
D 8
	if (lseek(fi, blk * DEV_BSIZE, 0) < 0) {
E 8
I 8
	if (lseek(fi, blk * dev_bsize, 0) < 0) {
E 8
		perror("FS SEEK");
		exit(6);
	}
	if (write(fi, buf, size) != size) {
		perror("FS WRITE");
		exit(7);
	}
}

bread(bno, buf, cnt)
	daddr_t bno;
	char *buf;
{
	register i;

D 8
	if (lseek(fi, bno * DEV_BSIZE, 0) < 0)
E 8
I 8
	if (lseek(fi, bno * dev_bsize, 0) < 0)
E 8
		return(1);
	if ((i = read(fi, buf, cnt)) != cnt) {
		for(i=0; i<sblock.fs_bsize; i++)
			buf[i] = 0;
		return (1);
	}
	return (0);
}

/* VARARGS1 */
fatal(fmt, arg1, arg2)
	char *fmt, *arg1, *arg2;
{

D 2
	fprintf(stderr, "newfs: ");
E 2
I 2
	fprintf(stderr, "tunefs: ");
E 2
	fprintf(stderr, fmt, arg1, arg2);
	putc('\n', stderr);
	exit(10);
}
E 1
