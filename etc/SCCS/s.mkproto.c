h24541
s 00009/00008/00538
d D 5.4 88/05/31 17:54:04 mckusick 8 7
c convert to understand dynamic file systems
e
s 00016/00014/00530
d D 5.3 87/12/26 12:57:11 bostic 7 6
c fix declarations for ANSI C; minor lint cleanups
e
s 00006/00005/00538
d D 5.2 87/02/23 17:39:57 mckusick 6 5
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00013/00001/00530
d D 5.1 85/05/28 14:59:18 dist 5 4
c Add copyright
e
s 00003/00003/00528
d D 4.4 83/08/11 22:51:39 sam 4 3
c standardize sccs keyword lines
e
s 00004/00004/00527
d D 4.3 83/05/03 20:53:02 sam 3 2
c fix name conflict with kernel
e
s 00001/00001/00530
d D 4.2 82/10/13 17:29:44 mckusick 2 1
c fix creation of block and character devices
e
s 00531/00000/00000
d D 4.1 82/09/10 00:09:25 mckusick 1 0
c date and time created 82/09/10 00:09:25 by mckusick
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
D 4
/* Copyright (c) 1982 Regents of the University of California */

static char sccsid[] = "%W%	(Berkeley)	%G%";
E 4
I 4
#ifndef lint
I 5
char copyright[] =
"%Z% Copyright (c) 1980 Regents of the University of California.\n\
 All rights reserved.\n";
#endif not lint

#ifndef lint
E 5
static char sccsid[] = "%W% (Berkeley) %G%";
D 5
#endif
E 5
I 5
#endif not lint
E 5
E 4

/*
 * Make a file system prototype.
 * usage: mkproto filsys proto
 */
#include <stdio.h>
#include <sys/param.h>
#include <sys/inode.h>
#include <sys/fs.h>
#include <sys/dir.h>

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
struct	csum *fscs;
int	fso, fsi;
FILE	*proto;
char	token[BUFSIZ];
int	errs;
I 6
long	dev_bsize = 1;
E 6
int	ino = 10;
long	getnum();
char	*strcpy();

main(argc, argv)
	int argc;
	char *argv[];
{
	int i;
I 7
	char *calloc();
E 7

	if (argc != 3) {
		fprintf(stderr, "usage: mkproto filsys proto\n");
		exit(1);
	}
	fso = open(argv[1], 1);
	fsi = open(argv[1], 0);
	if (fso < 0 || fsi < 0) {
		perror(argv[1]);
		exit(1);
	}
	fs = &sblock;
D 6
	rdfs(SBLOCK, SBSIZE, (char *)fs);
E 6
I 6
	rdfs(SBOFF, SBSIZE, (char *)fs);
	dev_bsize = fs->fs_fsize / fsbtodb(fs, 1);
E 6
D 7
	fscs = (struct csum *)calloc(1, fs->fs_cssize);
E 7
I 7
	fscs = (struct csum *)calloc(1, (u_int)fs->fs_cssize);
E 7
	for (i = 0; i < fs->fs_cssize; i += fs->fs_bsize)
		rdfs(fsbtodb(fs, fs->fs_csaddr + numfrags(fs, i)),
			(int)(fs->fs_cssize - i < fs->fs_bsize ?
			    fs->fs_cssize - i : fs->fs_bsize),
			((char *)fscs) + i);
	proto = fopen(argv[2], "r");
	descend((struct inode *)0);
D 6
	wtfs(SBLOCK, SBSIZE, (char *)fs);
E 6
I 6
	wtfs(SBOFF / dev_bsize, SBSIZE, (char *)fs);
E 6
	for (i = 0; i < fs->fs_cssize; i += fs->fs_bsize)
		wtfs(fsbtodb(&sblock, fs->fs_csaddr + numfrags(&sblock, i)),
			(int)(fs->fs_cssize - i < fs->fs_bsize ?
			    fs->fs_cssize - i : fs->fs_bsize),
			((char *)fscs) + i);
	exit(errs);
}

descend(par)
	struct inode *par;
{
	struct inode in;
	int ibc = 0;
	int i, f, c;
	struct dinode *dip, inos[MAXBSIZE / sizeof (struct dinode)];
	daddr_t ib[MAXBSIZE / sizeof (daddr_t)];
	char buf[MAXBSIZE];

	getstr();
	in.i_mode = gmode(token[0], "-bcd", IFREG, IFBLK, IFCHR, IFDIR);
	in.i_mode |= gmode(token[1], "-u", 0, ISUID, 0, 0);
	in.i_mode |= gmode(token[2], "-g", 0, ISGID, 0, 0);
	for (i = 3; i < 6; i++) {
		c = token[i];
		if (c < '0' || c > '7') {
			printf("%c/%s: bad octal mode digit\n", c, token);
			errs++;
			c = 0;
		}
		in.i_mode |= (c-'0')<<(15-3*i);
	}
	in.i_uid = getnum(); in.i_gid = getnum();
	for (i = 0; i < fs->fs_bsize; i++)
		buf[i] = 0;
	for (i = 0; i < NINDIR(fs); i++)
		ib[i] = (daddr_t)0;
	in.i_nlink = 1;
	in.i_size = 0;
	for (i = 0; i < NDADDR; i++)
		in.i_db[i] = (daddr_t)0;
	for (i = 0; i < NIADDR; i++)
		in.i_ib[i] = (daddr_t)0;
	if (par != (struct inode *)0) {
		ialloc(&in);
	} else {
		par = &in;
		i = itod(fs, ROOTINO);
		rdfs(fsbtodb(fs, i), fs->fs_bsize, (char *)inos);
		dip = &inos[ROOTINO % INOPB(fs)];
		in.i_number = ROOTINO;
		in.i_nlink = dip->di_nlink;
		in.i_size = dip->di_size;
		in.i_db[0] = dip->di_db[0];
		rdfs(fsbtodb(fs, in.i_db[0]), fs->fs_bsize, buf);
	}

	switch (in.i_mode&IFMT) {

	case IFREG:
		getstr();
		f = open(token, 0);
		if (f < 0) {
			printf("%s: cannot open\n", token);
			errs++;
			break;
		}
		while ((i = read(f, buf, (int)fs->fs_bsize)) > 0) {
			in.i_size += i;
			newblk(buf, &ibc, ib, (int)blksize(fs, &in, ibc));
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
		in.i_dev = (i << 8) | f;
E 2
I 2
		in.i_rdev = (i << 8) | f;
E 2
		break;

	case IFDIR:
		/*
		 * directory
		 * put in extra links
		 * call recursively until
		 * name of "$" found
		 */

		if (in.i_number != ROOTINO) {
			par->i_nlink++;
			in.i_nlink++;
			entry(&in, in.i_number, ".", buf);
			entry(&in, par->i_number, "..", buf);
		}
		for (;;) {
			getstr();
			if (token[0]=='$' && token[1]=='\0')
				break;
			entry(&in, (ino_t)(ino+1), token, buf);
			descend(&in);
		}
		if (in.i_number != ROOTINO)
			newblk(buf, &ibc, ib, (int)blksize(fs, &in, 0));
		else
			wtfs(fsbtodb(fs, in.i_db[0]), (int)fs->fs_bsize, buf);
		break;
	}
	iput(&in, &ibc, ib);
}

/*ARGSUSED*/
gmode(c, s, m0, m1, m2, m3)
	char c, *s;
{
	int i;

	for (i = 0; s[i]; i++)
		if (c == s[i])
			return((&m0)[i]);
	printf("%c/%s: bad mode\n", c, token);
	errs++;
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
	for (i = 0; c=token[i]; i++) {
		if (c<'0' || c>'9') {
			printf("%s: bad number\n", token);
			errs++;
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
	switch (c = getc(proto)) {

	case ' ':
	case '\t':
	case '\n':
		goto loop;

	case EOF:
		printf("Unexpected EOF\n");
		exit(1);

	case ':':
		while (getc(proto) != '\n')
			;
		goto loop;

	}
	i = 0;
	do {
		token[i++] = c;
		c = getc(proto);
	} while (c != ' ' && c != '\t' && c != '\n' && c != '\0');
	token[i] = 0;
}

entry(ip, inum, str, buf)
	struct inode *ip;
	ino_t inum;
	char *str;
	char *buf;
{
	register struct direct *dp, *odp;
D 3
	int oldsize, newsize, freespace;
E 3
I 3
	int oldsize, newsize, spacefree;
E 3

	odp = dp = (struct direct *)buf;
	while ((int)dp - (int)buf < ip->i_size) {
		odp = dp;
		dp = (struct direct *)((int)dp + dp->d_reclen);
	}
	if (odp != dp)
		oldsize = DIRSIZ(odp);
	else
		oldsize = 0;
D 3
	freespace = odp->d_reclen - oldsize;
E 3
I 3
	spacefree = odp->d_reclen - oldsize;
E 3
	dp = (struct direct *)((int)odp + oldsize);
	dp->d_ino = inum;
	dp->d_namlen = strlen(str);
	newsize = DIRSIZ(dp);
D 3
	if (freespace >= newsize) {
E 3
I 3
	if (spacefree >= newsize) {
E 3
		odp->d_reclen = oldsize;
D 3
		dp->d_reclen = freespace;
E 3
I 3
		dp->d_reclen = spacefree;
E 3
	} else {
		dp = (struct direct *)((int)odp + odp->d_reclen);
		if ((int)dp - (int)buf >= fs->fs_bsize) {
			printf("directory too large\n");
			exit(1);
		}
		dp->d_ino = inum;
		dp->d_namlen = strlen(str);
		dp->d_reclen = DIRBLKSIZ;
	}
	strcpy(dp->d_name, str);
	ip->i_size = (int)dp - (int)buf + newsize;
}

newblk(buf, aibc, ib, size)
	int *aibc;
	char *buf;
	daddr_t *ib;
	int size;
{
	int i;
D 7
	daddr_t bno;
E 7
I 7
	daddr_t bno, alloc();
E 7

	bno = alloc(size);
	wtfs(fsbtodb(fs, bno), (int)fs->fs_bsize, buf);
	for (i = 0; i < fs->fs_bsize; i++)
		buf[i] = 0;
	ib[(*aibc)++] = bno;
	if (*aibc >= NINDIR(fs)) {
		printf("indirect block full\n");
		errs++;
		*aibc = 0;
	}
}

iput(ip, aibc, ib)
	struct inode *ip;
	int *aibc;
	daddr_t *ib;
{
D 7
	daddr_t d;
E 7
I 7
	daddr_t d, alloc();
E 7
	int i;
	struct dinode buf[MAXBSIZE / sizeof (struct dinode)];
I 7
	time_t time();
E 7

D 7
	ip->i_atime = ip->i_mtime = ip->i_ctime = time((long *)0);
E 7
I 7
	ip->i_atime = ip->i_mtime = ip->i_ctime = time((time_t *)NULL);
E 7
	switch (ip->i_mode&IFMT) {

	case IFDIR:
	case IFREG:
		for (i = 0; i < *aibc; i++) {
			if (i >= NDADDR)
				break;
			ip->i_db[i] = ib[i];
		}
		if (*aibc > NDADDR) {
			ip->i_ib[0] = alloc((int)fs->fs_bsize);
			for (i = 0; i < NINDIR(fs) - NDADDR; i++) {
				ib[i] = ib[i+NDADDR];
				ib[i+NDADDR] = (daddr_t)0;
			}
			wtfs(fsbtodb(fs, ip->i_ib[0]),
			    (int)fs->fs_bsize, (char *)ib);
		}
		break;

	case IFBLK:
	case IFCHR:
		break;

	default:
		printf("bad mode %o\n", ip->i_mode);
		exit(1);
	}
	d = fsbtodb(fs, itod(fs, ip->i_number));
	rdfs(d, (int)fs->fs_bsize, (char *)buf);
	buf[itoo(fs, ip->i_number)].di_ic = ip->i_ic;
	wtfs(d, (int)fs->fs_bsize, (char *)buf);
}

daddr_t
alloc(size)
	int size;
{
	int i, frag;
	daddr_t d;
	static int cg = 0;

again:
	rdfs(fsbtodb(&sblock, cgtod(&sblock, cg)), (int)sblock.fs_cgsize,
	    (char *)&acg);
D 8
	if (acg.cg_magic != CG_MAGIC) {
E 8
I 8
	if (!cg_chkmagic(&acg)) {
E 8
		printf("cg %d: bad magic number\n", cg);
		return (0);
	}
	if (acg.cg_cs.cs_nbfree == 0) {
		cg++;
		if (cg >= fs->fs_ncg) {
			printf("ran out of space\n");
			return (0);
		}
		goto again;
	}
	for (d = 0; d < acg.cg_ndblk; d += sblock.fs_frag)
D 8
		if (isblock(&sblock, (u_char *)acg.cg_free, d / sblock.fs_frag))
E 8
I 8
		if (isblock(&sblock, (u_char *)cg_blksfree(&acg),
		    d / sblock.fs_frag))
E 8
			goto goth;
	printf("internal error: can't find block in cyl %d\n", cg);
	return (0);
goth:
D 8
	clrblock(&sblock, (u_char *)acg.cg_free, d / sblock.fs_frag);
E 8
I 8
	clrblock(&sblock, (u_char *)cg_blksfree(&acg), d / sblock.fs_frag);
E 8
	acg.cg_cs.cs_nbfree--;
	sblock.fs_cstotal.cs_nbfree--;
	fscs[cg].cs_nbfree--;
D 8
	acg.cg_btot[cbtocylno(&sblock, d)]--;
	acg.cg_b[cbtocylno(&sblock, d)][cbtorpos(&sblock, d)]--;
E 8
I 8
	cg_blktot(&acg)[cbtocylno(&sblock, d)]--;
	cg_blks(&sblock, &acg, cbtocylno(&sblock, d))[cbtorpos(&sblock, d)]--;
E 8
	if (size != sblock.fs_bsize) {
		frag = howmany(size, sblock.fs_fsize);
		fscs[cg].cs_nffree += sblock.fs_frag - frag;
		sblock.fs_cstotal.cs_nffree += sblock.fs_frag - frag;
		acg.cg_cs.cs_nffree += sblock.fs_frag - frag;
		acg.cg_frsum[sblock.fs_frag - frag]++;
		for (i = frag; i < sblock.fs_frag; i++)
D 8
			setbit(acg.cg_free, d + i);
E 8
I 8
			setbit(cg_blksfree(&acg), d + i);
E 8
	}
	wtfs(fsbtodb(&sblock, cgtod(&sblock, cg)), (int)sblock.fs_cgsize,
	    (char *)&acg);
	return (acg.cg_cgx * fs->fs_fpg + d);
}

/*
 * Allocate an inode on the disk
 */
ialloc(ip)
	register struct inode *ip;
{
D 7
	struct dinode buf[MAXBSIZE / sizeof (struct dinode)];
	daddr_t d;
E 7
	int c;

	ip->i_number = ++ino;
	c = itog(&sblock, ip->i_number);
	rdfs(fsbtodb(&sblock, cgtod(&sblock, c)), (int)sblock.fs_cgsize,
	    (char *)&acg);
D 8
	if (acg.cg_magic != CG_MAGIC) {
E 8
I 8
	if (!cg_chkmagic(&acg)) {
E 8
		printf("cg %d: bad magic number\n", c);
		exit(1);
	}
	if (ip->i_mode & IFDIR) {
		acg.cg_cs.cs_ndir++;
		sblock.fs_cstotal.cs_ndir++;
		fscs[c].cs_ndir++;
	}
	acg.cg_cs.cs_nifree--;
D 8
	setbit(acg.cg_iused, ip->i_number);
E 8
I 8
	setbit(cg_inosused(&acg), ip->i_number);
E 8
	wtfs(fsbtodb(&sblock, cgtod(&sblock, c)), (int)sblock.fs_cgsize,
	    (char *)&acg);
	sblock.fs_cstotal.cs_nifree--;
	fscs[c].cs_nifree--;
	if(ip->i_number >= sblock.fs_ipg * sblock.fs_ncg) {
D 7
		printf("fsinit: inode value out of range (%d).\n",
E 7
I 7
		printf("fsinit: inode value out of range (%lu).\n",
E 7
		    ip->i_number);
		exit(1);
	}
D 7
	return (ip->i_number);
E 7
I 7
	/* return (ip->i_number); */
E 7
}

/*
 * read a block from the file system
 */
rdfs(bno, size, bf)
	int bno, size;
	char *bf;
{
	int n;
I 7
	off_t lseek();
E 7

D 6
	if (lseek(fsi, bno * DEV_BSIZE, 0) < 0) {
E 6
I 6
	if (lseek(fsi, bno * dev_bsize, 0) < 0) {
E 6
D 7
		printf("seek error: %ld\n", bno);
E 7
I 7
		printf("seek error: %d\n", bno);
E 7
		perror("rdfs");
		exit(1);
	}
	n = read(fsi, bf, size);
	if(n != size) {
D 7
		printf("read error: %ld\n", bno);
E 7
I 7
		printf("read error: %d\n", bno);
E 7
		perror("rdfs");
		exit(1);
	}
}

/*
 * write a block to the file system
 */
wtfs(bno, size, bf)
	int bno, size;
	char *bf;
{
	int n;
I 7
	off_t lseek();
E 7

D 6
	lseek(fso, bno * DEV_BSIZE, 0);
	if (lseek(fso, bno * DEV_BSIZE, 0) < 0) {
E 6
I 6
	if (lseek(fso, bno * dev_bsize, 0) < 0) {
E 6
D 7
		printf("seek error: %ld\n", bno);
E 7
I 7
		printf("seek error: %d\n", bno);
E 7
		perror("wtfs");
		exit(1);
	}
	n = write(fso, bf, size);
	if(n != size) {
D 7
		printf("write error: %D\n", bno);
E 7
I 7
		printf("write error: %d\n", bno);
E 7
		perror("wtfs");
		exit(1);
	}
}
/*
 * check if a block is available
 */
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
D 7
		fprintf(stderr, "isblock bad fs_frag %d\n", fs->fs_frag);
E 7
I 7
		fprintf(stderr, "isblock bad fs_frag %ld\n", fs->fs_frag);
E 7
		return (0);
	}
	/*NOTREACHED*/
}

/*
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
D 7
		fprintf(stderr, "clrblock bad fs_frag %d\n", fs->fs_frag);
E 7
I 7
		fprintf(stderr, "clrblock bad fs_frag %ld\n", fs->fs_frag);
E 7
		return;
	}
}

E 1
