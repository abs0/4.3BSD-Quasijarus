h03735
s 00002/00002/00210
d D 5.3 88/01/10 15:37:03 bostic 21 20
c fix #endif lines for ANSI C
e
s 00009/00009/00203
d D 5.2 87/03/18 18:04:22 mckusick 20 19
c SBLOCK become SBOFF
e
s 00014/00002/00198
d D 5.1 85/04/30 14:55:36 dist 19 18
c Add copyright
e
s 00012/00004/00188
d D 4.18 84/02/02 11:19:32 ralph 18 17
c don't exit if df on a drive that is off-line.
e
s 00022/00024/00170
d D 4.17 83/06/19 18:09:05 sam 17 16
c new mtab
e
s 00002/00001/00192
d D 4.16 83/05/24 13:47:58 sam 16 15
c quotas
e
s 00002/00002/00191
d D 4.15 83/02/07 15:47:52 sam 15 14
c only show file systems of interest
e
s 00001/00001/00192
d D 4.14 83/01/02 14:13:19 sam 14 13
c from sun
e
s 00001/00000/00192
d D 4.13 82/06/15 12:40:11 mckusick 13 12
c sync() before printing so as to get up to date info
e
s 00039/00032/00153
d D 4.12 82/05/07 16:27:46 mckusick 12 11
c update to new fs
e
s 00003/00001/00182
d D 4.11 82/04/01 06:53:17 root 11 10
c fix sccsid
e
s 00002/00002/00181
d D 4.10 82/03/15 14:23:55 root 10 9
c bug in deciding which not to print
e
s 00001/00002/00182
d D 4.9 82/02/28 23:25:44 wnj 9 8
c remove traces of -l option
e
s 00078/00125/00106
d D 4.8 82/02/26 14:02:46 root 8 7
c new version cleaned up
e
s 00001/00001/00230
d D 4.7 81/07/10 15:19:58 bugs 7 6
c s/-il/-i -l/
e
s 00002/00001/00229
d D 4.6 81/07/08 16:11:51 wnj 6 5
c sync() less
e
s 00001/00001/00229
d D 4.5 81/03/22 21:11:14 wnj 5 4
c s/blocks/kbytes/
e
s 00004/00002/00226
d D 4.4 81/03/10 07:01:28 wnj 4 3
c miscellaneous minor fixups
e
s 00033/00014/00195
d D 4.3 80/10/15 23:35:38 bill 3 2
c put back in df dir
e
s 00002/00000/00207
d D 4.2 80/10/13 17:14:05 bill 2 1
c adding calls to fstab routines
e
s 00207/00000/00000
d D 4.1 80/10/01 17:26:18 bill 1 0
c date and time created 80/10/01 17:26:18 by bill
e
u
U
t
T
I 19
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 */

E 19
I 1
D 3
static char *sccsid = "%W% (Berkeley) %G%";
E 3
I 3
D 11
static	char *sccsid = "%W% (Berkeley) %G%";
E 11
I 11
#ifndef lint
D 19
static	char *sccsid = "%W% %G%";
#endif
E 19
I 19
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
D 21
#endif not lint
E 21
I 21
#endif /* not lint */
E 21

#ifndef lint
static char sccsid[] = "%W% (Berkeley) %G%";
D 21
#endif not lint
E 21
I 21
#endif /* not lint */
E 21
E 19
E 11
I 8

E 8
E 3
D 17
#include <stdio.h>
#include <fstab.h>
E 17
#include <sys/param.h>
D 12
#include <sys/filsys.h>
#include <sys/fblk.h>
E 12
I 12
#include <sys/fs.h>
E 12
I 3
#include <sys/stat.h>
I 18
#include <errno.h>
E 18
I 8

I 17
#include <stdio.h>
#include <fstab.h>
#include <mtab.h>

E 17
E 8
/*
 * df
 */
E 3
D 8

E 8
D 17
#define NFS	20	/* Max number of filesystems */

D 3

E 3
struct {
	char path[32];
	char spec[32];
} mtab[NFS];
E 17
I 17
struct	mtab mtab[NMOUNT];
E 17
D 8
char root[32];

char *mpath();

E 8
I 8
char	root[32];
char	*mpath();
E 8
D 12
daddr_t	blkno	= 1;
E 12

D 9
int	lflag;
E 9
int	iflag;

D 12
struct	filsys sblock;
E 12
I 12
union {
	struct fs iu_fs;
	char dummy[SBSIZE];
} sb;
#define sblock sb.iu_fs
E 12

int	fi;
daddr_t	alloc();
I 12
char	*strcpy();
E 12

main(argc, argv)
D 8
char **argv;
E 8
I 8
	int argc;
	char **argv;
E 8
{
	int i;
D 3
	FILE *f = fopen(FSTAB, "r");
E 3
D 8
	char buf[128];
E 8
D 3
	struct	fstab	fs;
E 3

D 14
	while (argc >= 1 && argv[1][0]=='-') {
E 14
I 14
	while (argc > 1 && argv[1][0]=='-') {
E 14
D 8
		switch(argv[1][1]) {
E 8
I 8
D 17
	switch (argv[1][1]) {
E 17
I 17
		switch (argv[1][1]) {
E 17
E 8

D 8
		case 'l':
			lflag++;
			break;
E 8
I 8
D 17
	case 'i':
		iflag++;
		break;
E 17
I 17
		case 'i':
			iflag++;
			break;
E 17
E 8

D 8
		case 'i':
			iflag++;
			break;

		default:
D 7
			fprintf(stderr, "usage: df [ -il ] [ filsys... ]\n");
E 7
I 7
			fprintf(stderr, "usage: df [ -i ] [ -l ] [ filsys... ]\n");
E 7
			exit(0);
		}
		argc--, argv++;
E 8
I 8
D 17
	default:
D 9
		fprintf(stderr, "usage: df [ -i ] [ -l ] [ filsys... ]\n");
E 9
I 9
		fprintf(stderr, "usage: df [ -i ] [ filsys... ]\n");
E 9
		exit(0);
E 17
I 17
		default:
			fprintf(stderr, "usage: df [ -i ] [ filsys... ]\n");
			exit(0);
		}
		argc--, argv++;
E 17
E 8
	}
D 8

	if ((i=open("/etc/mtab", 0)) >= 0) {
E 8
I 8
D 17
	argc--, argv++;
	}
E 17
	i = open("/etc/mtab", 0);
	if (i >= 0) {
E 8
D 12
		read(i, mtab, sizeof mtab);	/* Probably returns short */
		close(i);
E 12
I 12
D 17
		(void) read(i, (char *)mtab, sizeof mtab);
E 17
I 17
		(void) read(i, (char *)mtab, sizeof (mtab));
E 17
		(void) close(i);
E 12
	}
I 13
	sync();
E 13
D 5
	printf("Filesystem  Mounted on  blocks\t  used\t  free");
E 5
I 5
D 8
	printf("Filesystem  Mounted on  kbytes\t  used\t  free");
E 5
	if (lflag)
		printf("\thardway");
	printf("\t%% used");
E 8
I 8
D 12
	printf("Filesystem  Mounted on      kbytes    used    free");
	printf("   %% used");
E 12
I 12
	printf("Filesystem    kbytes    used   avail capacity");
E 12
E 8
	if (iflag)
D 8
		printf("\tiused\tifree\t%%iused");
E 8
I 8
D 12
		printf("   iused   ifree  %%iused");
E 8
	putchar('\n');
E 12
I 12
		printf(" iused   ifree  %%iused");
	printf("  Mounted on\n");
E 12
D 8
	if(argc <= 1) {
D 3
		if (f == NULL)
E 3
I 3
		struct	fstab	*fsp;
E 8
I 8
	if (argc <= 1) {
		struct fstab *fsp;

E 8
		if (setfsent() == 0)
E 3
			perror(FSTAB), exit(1);
D 3
		while (!feof(f)){
			fscanf(f, FSTABFMT, FSTABARG(&fs));
I 2
			if (strcmp(fs.fs_type, "rw") && strcmp(fs.fs_type, "ro"))
E 3
I 3
D 8
		while( (fsp = getfsent()) != 0){
			if (  (strcmp(fsp->fs_type, FSTAB_RW) != 0)
			    &&(strcmp(fsp->fs_type, FSTAB_RO) != 0) )
E 8
I 8
		while (fsp = getfsent()) {
D 10
			if (!strcmp(fsp->fs_type, FSTAB_RW) &&
			    !(strcmp(fsp->fs_type, FSTAB_RO)))
E 10
I 10
D 12
			if (strcmp(fsp->fs_type, FSTAB_RW) &&
			    strcmp(fsp->fs_type, FSTAB_RO))
E 12
I 12
D 15
			if (!strcmp(fsp->fs_type, FSTAB_RW) &&
			    !(strcmp(fsp->fs_type, FSTAB_RO)))
E 15
I 15
			if (strcmp(fsp->fs_type, FSTAB_RW) &&
D 16
			    strcmp(fsp->fs_type, FSTAB_RO))
E 16
I 16
			    strcmp(fsp->fs_type, FSTAB_RO) &&
			    strcmp(fsp->fs_type, FSTAB_RQ))
E 16
E 15
E 12
E 10
E 8
E 3
				continue;
E 2
			if (root[0] == 0)
D 3
				strcpy(root, fs.fs_spec);
			dfree(fs.fs_spec);
E 3
I 3
D 12
				strcpy(root, fsp->fs_spec);
E 12
I 12
				(void) strcpy(root, fsp->fs_spec);
E 12
D 8
			dfree(fsp->fs_spec);
E 8
I 8
			dfree(fsp->fs_spec, 1);
E 8
E 3
		}
I 3
D 20
		endfsent();
E 20
I 20
		(void)endfsent();
E 20
E 3
		exit(0);
	}
D 8

D 3
	if (f){
		fscanf(f, FSTABFMT, FSTABARG(&fs));
		strcpy(root, fs.fs_spec);
	}
E 3
	for(i=1; i<argc; i++) {
		dfree(argv[i]);
	}
E 8
I 8
	for (i=1; i<argc; i++)
		dfree(argv[i], 0);
E 8
}

D 8
dfree(file)
char *file;
E 8
I 8
dfree(file, infsent)
	char *file;
	int infsent;
E 8
{
D 12
	daddr_t i;
D 8
	long	blocks;
	long	free;
	long	used;
	long	hardway;
	char	*mp;
I 3
	struct	stat stbuf;
E 8
I 8
	long blocks, free, used, hardway;
	char *mp;
E 12
I 12
	long totalblks, availblks, avail, free, used;
E 12
	struct stat stbuf;
	struct fstab *fsp;
E 8
E 3

I 3
D 8
	if(stat(file, &stbuf) == 0 && (stbuf.st_mode&S_IFMT) != S_IFCHR
	  && (stbuf.st_mode&S_IFMT) != S_IFBLK) {
		int mt = open("/etc/mtab", 0), len;
		char *str = "/dev/xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
		char mtab[32];
		struct stat mstbuf;
		while((len = read(mt, mtab, 32)) == 32) {
			read(mt, &str[5], 32);
			if(stat(str, &mstbuf) == 0 && mstbuf.st_rdev == stbuf.st_dev) {
				file = str;
				break;
			}
		}
		close(mt);
		if(len == 0) {
			fprintf(stderr, "%s: mounted on unknown device\n", file);
E 8
I 8
	if (stat(file, &stbuf) == 0 &&
	    (stbuf.st_mode&S_IFMT) != S_IFCHR &&
	    (stbuf.st_mode&S_IFMT) != S_IFBLK) {
		if (infsent) {
			fprintf(stderr, "%s: screwy /etc/fstab entry\n", file);
E 8
			return;
		}
I 8
D 20
		setfsent();
E 20
I 20
		(void)setfsent();
E 20
		while (fsp = getfsent()) {
			struct stat stb;

			if (stat(fsp->fs_spec, &stb) == 0 &&
			    stb.st_rdev == stbuf.st_dev) {
				file = fsp->fs_spec;
D 20
				endfsent();
E 20
I 20
				(void)endfsent();
E 20
				goto found;
			}
		}
D 20
		endfsent();
E 20
I 20
		(void)endfsent();
E 20
		fprintf(stderr, "%s: mounted on unknown device\n", file);
		return;
E 8
	}
I 8
found:
E 8
E 3
	fi = open(file, 0);
D 8
	if(fi < 0) {
		fprintf(stderr,"cannot open %s\n", file);
E 8
I 8
	if (fi < 0) {
		perror(file);
E 8
		return;
	}
D 6
	sync();
E 6
I 6
D 8
	if (lflag)
		sync();
E 6
	bread(1L, (char *)&sblock, sizeof(sblock));
	printf("%-12.12s%s", file, mp = mpath(file));
	if (strlen(mp) < 4)
		putchar('\t');

E 8
I 8
D 12
	bread((long) 1, (char *)&sblock, sizeof (sblock));
	printf("%-12.12s%-14.14s", file, mp = mpath(file));
E 8
	blocks = (long) sblock.s_fsize - (long)sblock.s_isize;
	free = sblock.s_tfree;
	used = blocks - free;
D 8

	printf("\t%6ld", blocks);
	printf("\t%6ld", used);
	printf("\t%6ld", free);
	if (lflag) {
		hardway = 0;
		while(alloc())
			hardway++;
		printf("\t%6ld", free=hardway);
	}
D 4
	printf("\t%5.0f%%", (double) used / (double)blocks * 100.0);
E 4
I 4
	printf("\t%5.0f%%", 
E 8
I 8
	printf("%8d%8d%8d", blocks, used, free);
	printf("%8.0f%%", 
E 8
	    blocks == 0 ? 0.0 : (double) used / (double)blocks * 100.0);
E 12
I 12
D 18
	bread(SBLOCK, (char *)&sblock, SBSIZE);
E 18
I 18
D 20
	if (bread(SBLOCK, (char *)&sblock, SBSIZE) == 0) {
E 20
I 20
	if (bread((long)SBOFF, (char *)&sblock, SBSIZE) == 0) {
E 20
		(void) close(fi);
		return;
	}
E 18
	printf("%-12.12s", file);
	totalblks = sblock.fs_dsize;
	free = sblock.fs_cstotal.cs_nbfree * sblock.fs_frag +
	    sblock.fs_cstotal.cs_nffree;
	used = totalblks - free;
	availblks = totalblks * (100 - sblock.fs_minfree) / 100;
	avail = availblks > used ? availblks - used : 0;
	printf("%8d%8d%8d", totalblks * sblock.fs_fsize / 1024,
	    used * sblock.fs_fsize / 1024, avail * sblock.fs_fsize / 1024);
	printf("%6.0f%%",
	    availblks == 0 ? 0.0 : (double) used / (double) availblks * 100.0);
E 12
E 4
	if (iflag) {
D 12
		int inodes = (sblock.s_isize - 2) * INOPB;
		used = inodes - sblock.s_tinode;
D 4
		printf("\t%5ld\t%5ld\t%5.0f%%", used, sblock.s_tinode, (double)used/(double)inodes*100.0);
E 4
I 4
D 8
		printf("\t%5ld\t%5ld\t%5.0f%%", used, sblock.s_tinode, 
E 8
I 8
		printf("%8ld%8ld%8.0f%%", used, sblock.s_tinode, 
E 8
		    inodes == 0 ? 0.0 : (double)used/(double)inodes*100.0);
E 4
	}
	printf("\n");
	close(fi);
E 12
I 12
		int inodes = sblock.fs_ncg * sblock.fs_ipg;
		used = inodes - sblock.fs_cstotal.cs_nifree;
		printf("%8ld%8ld%6.0f%% ", used, sblock.fs_cstotal.cs_nifree,
		    inodes == 0 ? 0.0 : (double)used / (double)inodes * 100.0);
	} else 
		printf("  ");
	printf("  %s\n", mpath(file));
	(void) close(fi);
E 12
}

I 12
long lseek();

E 12
D 8
daddr_t
alloc()
{
	int i;
	daddr_t b;
	struct fblk buf;

	i = --sblock.s_nfree;
	if(i<0 || i>=NICFREE) {
		printf("bad free count, b=%D\n", blkno);
		return(0);
	}
	b = sblock.s_free[i];
	if(b == 0)
		return(0);
	if(b<sblock.s_isize || b>=sblock.s_fsize) {
		printf("bad free block (%D)\n", b);
		return(0);
	}
	if(sblock.s_nfree <= 0) {
		bread(b, (char *)&buf, sizeof(buf));
		blkno = b;
		sblock.s_nfree = buf.df_nfree;
		for(i=0; i<NICFREE; i++)
			sblock.s_free[i] = buf.df_free[i];
	}
	return(b);
}

E 8
D 20
bread(bno, buf, cnt)
D 8
daddr_t bno;
char *buf;
E 8
I 8
	daddr_t bno;
E 20
I 20
bread(off, buf, cnt)
	long off;
E 20
	char *buf;
E 8
{
	int n;
	extern errno;

D 12
	lseek(fi, bno<<BSHIFT, 0);
E 12
I 12
D 20
	(void) lseek(fi, (long)(bno * DEV_BSIZE), 0);
E 20
I 20
	(void) lseek(fi, off, 0);
E 20
E 12
D 8
	if((n=read(fi, buf, cnt)) != cnt) {
E 8
I 8
	if ((n=read(fi, buf, cnt)) != cnt) {
E 8
D 18
		printf("\nread error bno = %ld\n", bno);
		printf("count = %d; errno = %d\n", n, errno);
		exit(0);
E 18
I 18
		/* probably a dismounted disk if errno == EIO */
		if (errno != EIO) {
D 20
			printf("\nread error bno = %ld\n", bno);
E 20
I 20
			printf("\nread error off = %ld\n", off);
E 20
			printf("count = %d; errno = %d\n", n, errno);
		}
		return (0);
E 18
	}
I 18
	return (1);
E 18
}

/*
 * Given a name like /dev/rrp0h, returns the mounted path, like /usr.
 */
D 17
char *mpath(file)
E 17
I 17
char *
mpath(file)
E 17
D 8
char *file;
E 8
I 8
	char *file;
E 8
{
D 17
	register int i;
E 17
I 17
	register struct mtab *mp;
E 17

	if (eq(file, root))
D 17
		return "/";
	for (i=0; i<NFS; i++)
		if (eq(file, mtab[i].spec))
D 8
			return mtab[i].path;
E 8
I 8
			return (mtab[i].path);
E 17
I 17
		return ("/");
	for (mp = mtab; mp < mtab + NMOUNT; mp++)
		if (eq(file, mp->m_dname))
			return (mp->m_path);
E 17
E 8
	return "";
}

eq(f1, f2)
D 8
char *f1, *f2;
E 8
I 8
	char *f1, *f2;
E 8
{
I 8

E 8
	if (strncmp(f1, "/dev/", 5) == 0)
		f1 += 5;
	if (strncmp(f2, "/dev/", 5) == 0)
		f2 += 5;
D 8
	if (strcmp(f1, f2) == 0)
		return 1;
	if (*f1 == 'r' && strcmp(f1+1, f2) == 0)
		return 1;
	if (*f2 == 'r' && strcmp(f1, f2+1) == 0)
		return 1;
E 8
I 8
	if (!strcmp(f1, f2))
		return (1);
	if (*f1 == 'r' && !strcmp(f1+1, f2))
		return (1);
	if (*f2 == 'r' && !strcmp(f1, f2+1))
		return (1);
E 8
	if (*f1 == 'r' && *f2 == 'r' && strcmp(f1+1, f2+1) == 0)
D 8
		return 1;
	return 0;
E 8
I 8
		return (1);
	return (0);
E 8
}
E 1
