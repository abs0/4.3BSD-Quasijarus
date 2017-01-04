h13419
s 00045/00048/00328
d D 4.14 88/04/18 21:43:08 bostic 14 13
c put in getopt; fix usage of dev_bsize, it was dropping core; lots
c of minor lint fixes, minor bullet-proofing, rip out unused space
e
s 00001/00001/00375
d D 4.13 87/10/22 10:37:06 bostic 13 12
c ANSI C; sprintf now returns an int.
e
s 00004/00002/00372
d D 4.12 87/02/23 17:40:02 mckusick 12 11
c convert SBLOCK to SBOFF; generalize use of dev_bsize
e
s 00015/00005/00359
d D 4.11 85/09/09 21:52:53 serge 11 10
c print directory file system is mounted on; add missing return(0) to check()
e
s 00022/00043/00342
d D 4.10 85/05/27 17:20:31 mckusick 10 9
c modernize name lookup
e
s 00003/00004/00382
d D 4.9 83/09/22 22:17:40 sam 9 8
c out of range uid mapping bug
e
s 00002/00002/00384
d D 4.8 83/08/19 16:18:13 sam 8 7
c incorrect max login name size
e
s 00002/00002/00384
d D 4.7 83/08/16 23:42:07 mckusick 7 6
c off by one error, consternation rains
e
s 00229/00114/00157
d D 4.6 83/08/16 22:06:08 sam 6 5
c rewrite to handle large uids and to hash lookups
e
s 00008/00009/00263
d D 4.5 83/08/14 22:27:57 mckusick 5 4
c fix up to use block count in inode to compute sizes
e
s 00007/00003/00265
d D 4.4 83/07/01 03:19:20 sam 4 3
c from sun
e
s 00048/00026/00220
d D 4.3 82/10/24 23:19:08 mckusick 3 2
c update to new file system
e
s 00024/00014/00222
d D 4.2 82/03/29 20:14:57 wnj 2 1
c quot -v
e
s 00236/00000/00000
d D 4.1 80/10/01 17:28:01 bill 1 0
c date and time created 80/10/01 17:28:01 by bill
e
u
U
t
T
I 4
#ifndef lint
E 4
I 1
D 2
static char *sccsid = "%W% (Berkeley) %G%";
E 2
I 2
static char *sccsid = "%W% (Berkeley) %E%";
I 4
#endif
E 4

E 2
/*
D 2
 * Disk usage by user
E 2
I 2
 * quot
E 2
 */

D 2
char	*dargv[] = {
	"/dev/rrp3",
	0
};

E 2
#include <stdio.h>
#include <ctype.h>
D 6
#include <pwd.h>
E 6
#include <sys/param.h>
D 3
#include <sys/ino.h>
E 3
#include <sys/inode.h>
D 3
#include <sys/filsys.h>
E 3
I 3
#include <sys/fs.h>
I 6
#include <sys/file.h>
E 6
E 3

D 3
#define	ITABSZ	256
#define	ISIZ	(BSIZE/sizeof(struct dinode))
E 3
I 3
#define	ISIZ	(MAXBSIZE/sizeof(struct dinode))
E 3
D 6
#define	NUID	1000
E 6
D 3
struct	filsys	sblock;
struct	dinode	itab[ITABSZ];
E 3
I 3
union {
	struct fs u_sblock;
	char dummy[SBSIZE];
} sb_un;
#define sblock sb_un.u_sblock
struct dinode itab[MAXBSIZE/sizeof(struct dinode)];
E 3
D 6
struct du
{
E 6
I 6

struct du {
	struct	du *next;
E 6
	long	blocks;
I 2
D 6
	long	blocks30,blocks60,blocks90;
E 6
I 6
	long	blocks30;
	long	blocks60;
	long	blocks90;
E 6
E 2
	long	nfiles;
	int	uid;
D 6
	char	*name;
} du[NUID];
E 6
I 6
#define	NDU	2048
} du[NDU];
int	ndu;
#define	DUHASH	8209	/* smallest prime >= 4 * NDU */
#define	HASH(u)	((u) % DUHASH)
struct	du *duhash[DUHASH];

E 6
#define	TSIZE	500
int	sizes[TSIZE];
long	overflow;

int	nflg;
int	fflg;
int	cflg;
I 2
int	vflg;
I 3
int	hflg;
E 3
long	now;
I 12
D 14
long	dev_bsize = 1;
E 14
E 12
E 2

D 6
int	fi;
E 6
unsigned	ino;
D 6
unsigned	nfiles;
E 6

D 6
struct	passwd	*getpwent();
E 6
char	*malloc();
D 6
char	*copy();
E 6
I 6
char	*getname();
E 6

main(argc, argv)
D 6
char **argv;
E 6
I 6
	int argc;
	char *argv[];
E 6
{
D 14
	register int n;
E 14
I 14
	extern char *optarg;
	extern int optind;
	int ch;
	time_t time();
E 14
D 6
	register struct passwd *lp;
	register char **p;
E 6

I 2
D 14
	now = time(0);
E 2
D 6
	for(n=0; n<NUID; n++)
		du[n].uid = n;
	while((lp=getpwent()) != 0) {
		n = lp->pw_uid;
		if (n>NUID)
			continue;
		if(du[n].name)
			continue;
		du[n].name = copy(lp->pw_name);
E 6
I 6
	argc--, argv++;
	while (argc > 0 && argv[0][0] == '-') {
		register char *cp;
E 14
I 14
	while ((ch = getopt(argc, argv, "cfhnv")) != EOF)
		switch((char)ch) {
		case 'c':
			cflg++; break;
		case 'f':
			fflg++; break;
		case 'h':		/* undocumented */
			hflg++; break;
		case 'n':
			nflg++; break;
		case 'v':		/* undocumented */
			vflg++; break;
		case '?':
		default:
			fputs("usage: quot [-cfn] [filesystem ...]\n", stderr);
			exit(1);
		}
	argc -= optind;
	argv += optind;
E 14

D 14
		for (cp = &argv[0][1]; *cp; cp++)
			switch (*cp) {
			case 'n':
				nflg++; break;
			case 'f':
				fflg++; break;
			case 'c':
				cflg++; break;
			case 'v':
				vflg++; break;
			case 'h':
				hflg++; break;
			default:
				fprintf(stderr,
				    "usage: quot [ -nfcvh ] [ device ... ]\n");
				exit(1);
			}
		argc--, argv++;
E 6
	}
D 6
	if (argc == 1) {
D 2
		for (p = dargv; *p;) {
			check(*p++);
			report();
		}
		return(0);
E 2
I 2
		fprintf(stderr, "usage: df device ...\n");
E 6
I 6
	if (argc == 0)
E 14
I 14
	(void)time(&now);
	if (argc)
		for (; *argv; ++argv) {
			if (check(*argv, (char *)NULL) == 0)
				report();
		}
	else
E 14
		quotall();
D 14
	while (argc-- > 0)
D 11
		if (check(*argv++) == 0)
E 11
I 11
		if (check(*argv++, (char *)NULL) == 0)
E 11
			report();
	exit (0);
E 14
I 14
	exit(0);
E 14
}

I 14
#include <sys/dir.h>
E 14
#include <fstab.h>

quotall()
{
	register struct fstab *fs;
	register char *cp;
D 14
	char dev[80], *rindex();
E 14
I 14
	char dev[MAXNAMLEN + 10], *rindex();
E 14

D 14
	if (setfsent() == 0) {
		fprintf(stderr, "quot: no %s file\n", FSTAB);
E 6
		exit(1);
E 2
	}
E 14
D 6
	while (--argc) {
		argv++;
		if (argv[0][0]=='-') {
			if (argv[0][1]=='n')
				nflg++;
			else if (argv[0][1]=='f')
				fflg++;
			else if (argv[0][1]=='c')
				cflg++;
I 2
			else if (argv[0][1]=='v')
				vflg++;
I 3
			else if (argv[0][1]=='h')
				hflg++;
E 3
E 2
		} else {
D 4
			check(*argv);
			report();
E 4
I 4
			if (check(*argv) == 0)
				report();
E 4
		}
E 6
I 6
	while (fs = getfsent()) {
		if (strcmp(fs->fs_type, FSTAB_RO) &&
		    strcmp(fs->fs_type, FSTAB_RW) &&
		    strcmp(fs->fs_type, FSTAB_RQ))
			continue;
		cp = rindex(fs->fs_spec, '/');
		if (cp == 0)
			continue;
D 13
		sprintf(dev, "/dev/r%s", cp + 1);
E 13
I 13
		(void)sprintf(dev, "/dev/r%s", cp + 1);
E 13
D 11
		if (check(dev) == 0)
E 11
I 11
		if (check(dev, fs->fs_file) == 0)
E 11
			report();
E 6
	}
D 6
	return(0);
E 6
I 6
D 14
	endfsent();
E 14
E 6
}

D 11
check(file)
E 11
I 11
check(file, fsdir)
E 11
D 6
char *file;
E 6
I 6
	char *file;
I 11
	char *fsdir;
E 11
E 6
{
D 6
	register unsigned i, j;
E 6
I 6
	register int i, j, nfiles;
	register struct du **dp;
E 6
D 3
	register c;
E 3
I 3
	daddr_t iblk;
I 14
	long dev_bsize;
E 14
D 6
	int c;
E 6
I 6
	int c, fd;
E 6
E 3

D 6
	fi = open(file, 0);
	if (fi < 0) {
		printf("cannot open %s\n", file);
E 6
I 6
	/*
	 * Initialize tables between checks;
	 * because of the qsort done in report()
	 * the hash tables must be rebuilt each time.
	 */
	for (i = 0; i < TSIZE; i++)
		sizes[i] = 0;
	overflow = 0;
	for (dp = duhash; dp < &duhash[DUHASH]; dp++)
		*dp = 0;
	ndu = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "quot: ");
		perror(file);
E 6
D 4
		return;
E 4
I 4
		return (-1);
E 4
	}
D 11
	printf("%s:\n", file);
E 11
I 11
	printf("%s", file);
	if (fsdir == NULL) {
		register struct fstab *fs = getfsspec(file);
		if (fs != NULL)
			fsdir = fs->fs_file;
	}
	if (fsdir != NULL && *fsdir != '\0')
		printf(" (%s)", fsdir);
	printf(":\n");
E 11
	sync();
D 3
	bread(1, (char *)&sblock, sizeof sblock);
	nfiles = (sblock.s_isize-2)*(BSIZE/sizeof(struct dinode));
	ino = 0;
E 3
I 3
D 6
	bread(SBLOCK, (char *)&sblock, SBSIZE);
E 6
I 6
D 12
	bread(fd, SBLOCK, (char *)&sblock, SBSIZE);
E 12
I 12
D 14
	bread(fd, SBOFF, (char *)&sblock, SBSIZE);
E 14
I 14
	bread(fd, (long)SBOFF, (char *)&sblock, SBSIZE);
E 14
	dev_bsize = sblock.fs_fsize / fsbtodb(&sblock, 1);
E 12
E 6
E 3
	if (nflg) {
		if (isdigit(c = getchar()))
D 14
			ungetc(c, stdin);
E 14
I 14
			(void)ungetc(c, stdin);
E 14
D 6
		else while (c!='\n' && c != EOF)
E 6
I 6
		else while (c != '\n' && c != EOF)
E 6
			c = getchar();
	}
D 3
	for(i=2; ino<nfiles; i += ITABSZ/ISIZ) {
		bread(i, (char *)itab, sizeof itab);
		for (j=0; j<ITABSZ && ino<nfiles; j++) {
			ino++;
E 3
I 3
	nfiles = sblock.fs_ipg * sblock.fs_ncg;
	for (ino = 0; ino < nfiles; ) {
		iblk = fsbtodb(&sblock, itod(&sblock, ino));
D 6
		bread(iblk, (char *)itab, sblock.fs_bsize);
E 6
I 6
D 14
		bread(fd, iblk, (char *)itab, sblock.fs_bsize);
E 14
I 14
		bread(fd, iblk * dev_bsize, (char *)itab, (int)sblock.fs_bsize);
E 14
E 6
D 7
		for (j = 0; j < INOPB(&sblock) && ino < nfiles; j++) {
			if (ino++ < ROOTINO)
E 7
I 7
		for (j = 0; j < INOPB(&sblock) && ino < nfiles; j++, ino++) {
			if (ino < ROOTINO)
E 7
				continue;
E 3
			acct(&itab[j]);
		}
	}
I 6
	close(fd);
I 11
	return (0);
E 11
E 6
}

acct(ip)
D 3
register struct dinode *ip;
E 3
I 3
	register struct dinode *ip;
E 3
{
D 3
	register n;
E 3
D 6
	register char *np;
E 6
I 6
	register struct du *dp;
	struct du **hp;
E 6
I 3
	long blks, frags, size;
D 11
	char n;
E 11
I 11
	int n;
E 11
E 3
	static fino;

D 6
	if ((ip->di_mode&IFMT) == 0)
E 6
I 6
	if ((ip->di_mode & IFMT) == 0)
E 6
		return;
I 3
D 5
	if (!hflg) {
E 5
I 5
D 6
	if (hflg) {
E 5
		/*
D 5
		 * Assume that there are no holes in files.
E 5
I 5
		 * Blocks based on number of 512 byte blocks claimed by inode.
E 5
		 */
E 6
I 6
	/*
	 * By default, take block count in inode.  Otherwise (-h),
	 * take the size field and estimate the blocks allocated.
	 * The latter does not account for holes in files.
	 */
	if (!hflg)
E 6
D 5
		blks = lblkno(&sblock, ip->di_size);
		frags = blks * sblock.fs_frag +
			numfrags(&sblock, dblksize(&sblock, ip, blks));
E 5
I 5
		size = ip->di_blocks / 2;
E 5
D 6
	} else {
		/*
D 5
		 * Actually go out and count the number of allocated blocks.
E 5
I 5
		 * Estimate based on size of file.
E 5
		 */
E 6
I 6
	else {
E 6
D 5
		printf("Sorry, hard way not implemented yet...\n");
		exit(1);
E 5
I 5
		blks = lblkno(&sblock, ip->di_size);
		frags = blks * sblock.fs_frag +
			numfrags(&sblock, dblksize(&sblock, ip, blks));
		size = frags * sblock.fs_fsize / 1024;
E 5
	}
D 5
	size = frags * sblock.fs_fsize / 1024;
E 5
E 3
	if (cflg) {
D 6
		if ((ip->di_mode&IFMT)!=IFDIR && (ip->di_mode&IFMT)!=IFREG)
E 6
I 6
		if ((ip->di_mode&IFMT) != IFDIR && (ip->di_mode&IFMT) != IFREG)
E 6
			return;
D 3
		n = (ip->di_size+BSIZE-1)/BSIZE;
		if (n >= TSIZE) {
			overflow += n;
			n = TSIZE-1;
E 3
I 3
		if (size >= TSIZE) {
			overflow += size;
			size = TSIZE-1;
E 3
		}
D 3
		sizes[n]++;
E 3
I 3
		sizes[size]++;
E 3
		return;
	}
D 6
	if (ip->di_uid >= NUID)
		return;
D 3
	du[ip->di_uid].blocks += (ip->di_size+BSIZE-1)/BSIZE;
E 3
I 3
	du[ip->di_uid].blocks += size;
E 6
I 6
	hp = &duhash[HASH(ip->di_uid)];
	for (dp = *hp; dp; dp = dp->next)
		if (dp->uid == ip->di_uid)
			break;
	if (dp == 0) {
		if (ndu >= NDU)
			return;
		dp = &du[ndu++];
		dp->next = *hp;
		*hp = dp;
		dp->uid = ip->di_uid;
		dp->nfiles = 0;
		dp->blocks = 0;
		dp->blocks30 = 0;
		dp->blocks60 = 0;
		dp->blocks90 = 0;
	}
	dp->blocks += size;
E 6
E 3
I 2
#define	DAY (60 * 60 * 24)	/* seconds per day */
	if (now - ip->di_atime > 30 * DAY)
D 3
		du[ip->di_uid].blocks30 += (ip->di_size+BSIZE-1)/BSIZE;
E 3
I 3
D 6
		du[ip->di_uid].blocks30 += size;
E 6
I 6
		dp->blocks30 += size;
E 6
E 3
	if (now - ip->di_atime > 60 * DAY)
D 3
		du[ip->di_uid].blocks60 += (ip->di_size+BSIZE-1)/BSIZE;
E 3
I 3
D 6
		du[ip->di_uid].blocks60 += size;
E 6
I 6
		dp->blocks60 += size;
E 6
E 3
	if (now - ip->di_atime > 90 * DAY)
D 3
		du[ip->di_uid].blocks90 += (ip->di_size+BSIZE-1)/BSIZE;
E 3
I 3
D 6
		du[ip->di_uid].blocks90 += size;
E 3
E 2
	du[ip->di_uid].nfiles++;
	if (nflg) {
	tryagain:
		if (fino==0)
			if (scanf("%d", &fino)<=0)
E 6
I 6
		dp->blocks90 += size;
	dp->nfiles++;
	while (nflg) {
		register char *np;

		if (fino == 0)
			if (scanf("%d", &fino) <= 0)
E 6
				return;
		if (fino > ino)
			return;
D 6
		if (fino<ino) {
			while ((n=getchar())!='\n' && n!=EOF)
E 6
I 6
		if (fino < ino) {
			while ((n = getchar()) != '\n' && n != EOF)
E 6
				;
			fino = 0;
D 6
			goto tryagain;
E 6
I 6
			continue;
E 6
		}
D 6
		if (np = du[ip->di_uid].name)
E 6
I 6
		if (np = getname(dp->uid))
E 6
D 14
			printf("%.7s	", np);
E 14
I 14
			printf("%.7s\t", np);
E 14
		else
D 14
			printf("%d	", ip->di_uid);
E 14
I 14
			printf("%u\t", ip->di_uid);
E 14
D 6
		while ((n = getchar())==' ' || n=='\t')
E 6
I 6
		while ((n = getchar()) == ' ' || n == '\t')
E 6
			;
		putchar(n);
D 6
		while (n!=EOF && n!='\n') {
E 6
I 6
		while (n != EOF && n != '\n') {
E 6
			n = getchar();
			putchar(n);
		}
		fino = 0;
I 6
		break;
E 6
	}
}

D 6
bread(bno, buf, cnt)
unsigned bno;
char *buf;
E 6
I 6
bread(fd, bno, buf, cnt)
D 14
	unsigned bno;
E 14
I 14
	long bno;
E 14
	char *buf;
E 6
{
I 14
	off_t lseek();
E 14

D 3
	lseek(fi, (long)bno*BSIZE, 0);
E 3
I 3
D 6
	lseek(fi, (long)bno*DEV_BSIZE, 0);
E 3
	if (read(fi, buf, cnt) != cnt) {
		printf("read error %u\n", bno);
E 6
I 6
D 12
	lseek(fd, (long)bno * DEV_BSIZE, L_SET);
E 12
I 12
D 14
	lseek(fd, (long)bno * dev_bsize, L_SET);
E 14
I 14
	(void)lseek(fd, bno, L_SET);
E 14
E 12
	if (read(fd, buf, cnt) != cnt) {
D 14
		fprintf(stderr, "quot: read error at block %u\n", bno);
E 14
I 14
		fprintf(stderr, "quot: read error at block %ld\n", bno);
E 14
E 6
		exit(1);
	}
}

qcmp(p1, p2)
D 6
register struct du *p1, *p2;
E 6
I 6
	register struct du *p1, *p2;
E 6
{
I 6
	char *s1, *s2;

E 6
	if (p1->blocks > p2->blocks)
D 6
		return(-1);
E 6
I 6
		return (-1);
E 6
	if (p1->blocks < p2->blocks)
D 6
		return(1);
I 4
	if (p1->name == 0 || p2->name == 0)
		return(0);	/* doesn't matter */
E 4
	return(strcmp(p1->name, p2->name));
E 6
I 6
		return (1);
	s1 = getname(p1->uid);
	if (s1 == 0)
		return (0);
	s2 = getname(p2->uid);
	if (s2 == 0)
		return (0);
	return (strcmp(s1, s2));
E 6
}

report()
{
	register i;
I 6
	register struct du *dp;
E 6

	if (nflg)
		return;
	if (cflg) {
D 6
		long t = 0;
		for (i=0; i<TSIZE-1; i++)
E 6
I 6
		register long t = 0;

		for (i = 0; i < TSIZE - 1; i++)
E 6
			if (sizes[i]) {
				t += i*sizes[i];
D 14
				printf("%d	%d	%D\n", i, sizes[i], t);
E 14
I 14
				printf("%d\t%d\t%ld\n", i, sizes[i], t);
E 14
			}
D 6
		printf("%d	%d	%D\n", TSIZE-1, sizes[TSIZE-1], overflow+t);
E 6
I 6
D 14
		printf("%d	%d	%D\n",
E 14
I 14
		printf("%d\t%d\t%ld\n",
E 14
		    TSIZE - 1, sizes[TSIZE - 1], overflow + t);
E 6
		return;
	}
D 6
	qsort(du, NUID, sizeof(du[0]), qcmp);
	for (i=0; i<NUID; i++) {
		if (du[i].blocks==0)
E 6
I 6
	qsort(du, ndu, sizeof (du[0]), qcmp);
	for (dp = du; dp < &du[ndu]; dp++) {
		register char *cp;

		if (dp->blocks == 0)
E 6
			return;
D 6
		printf("%5D\t", du[i].blocks);
E 6
I 6
		printf("%5D\t", dp->blocks);
E 6
		if (fflg)
D 6
			printf("%5D\t", du[i].nfiles);
		if (du[i].name)
D 2
			printf("%s\n", du[i].name);
E 2
I 2
			printf("%-8.8s", du[i].name);
E 6
I 6
			printf("%5D\t", dp->nfiles);
		if (cp = getname(dp->uid))
			printf("%-8.8s", cp);
E 6
E 2
		else
D 2
			printf("#%d\n", du[i].uid);
E 2
I 2
D 6
			printf("#%-8d", du[i].uid);
E 6
I 6
			printf("#%-8d", dp->uid);
E 6
		if (vflg)
			printf("\t%5D\t%5D\t%5D",
D 6
			    du[i].blocks30, du[i].blocks60, du[i].blocks90);
E 6
I 6
			    dp->blocks30, dp->blocks60, dp->blocks90);
E 6
		printf("\n");
E 2
	}
}

I 10
/* rest should be done with nameserver or database */

E 10
I 6
#include <pwd.h>
I 10
#include <grp.h>
E 10
#include <utmp.h>

struct	utmp utmp;
D 10

#define NUID	2048
E 10
#define	NMAX	(sizeof (utmp.ut_name))
I 10
#define SCPYN(a, b)	strncpy(a, b, NMAX)
E 10

D 10
char	names[NUID][NMAX+1];
E 10
I 10
#define NUID	64	/* power of 2 */
#define UIDMASK	0x3f

struct ncache {
	int	uid;
	char	name[NMAX+1];
} nc[NUID];
E 10
D 14
char	outrangename[NMAX+1];
int	outrangeuid = -1;
E 14

E 6
char *
D 6
copy(s)
char *s;
E 6
I 6
getname(uid)
D 10
	int uid;
E 10
E 6
{
D 6
	register char *p;
	register n;
E 6
I 6
	register struct passwd *pw;
D 10
	static init;
E 10
	struct passwd *getpwent();
I 10
	extern int _pw_stayopen;
	register int cp;
E 10
E 6

D 6
	for(n=0; s[n]; n++)
		;
	p = malloc((unsigned)n+1);
	for(n=0; p[n] = s[n]; n++)
		;
	return(p);
E 6
I 6
D 10
	if (uid >= 0 && uid < NUID && names[uid][0])
		return (&names[uid][0]);
	if (uid >= 0 && uid == outrangeuid)
		return (outrangename);
I 9
rescan:
E 9
	if (init == 2) {
		if (uid < NUID)
			return (0);
		setpwent();
		while (pw = getpwent()) {
			if (pw->pw_uid != uid)
				continue;
			outrangeuid = pw->pw_uid;
D 8
			strncpy(outrangename, pw->pw_name, NUID);
E 8
I 8
			strncpy(outrangename, pw->pw_name, NMAX);
E 8
			endpwent();
			return (outrangename);
		}
		endpwent();
E 10
I 10
	_pw_stayopen = 1;
	cp = uid & UIDMASK;
	if (uid >= 0 && nc[cp].uid == uid && nc[cp].name[0])
		return (nc[cp].name);
	pw = getpwuid(uid);
	if (!pw)
E 10
		return (0);
D 10
	}
	if (init == 0)
		setpwent(), init = 1;
	while (pw = getpwent()) {
		if (pw->pw_uid < 0 || pw->pw_uid >= NUID) {
			if (pw->pw_uid == uid) {
				outrangeuid = pw->pw_uid;
D 8
				strncpy(outrangename, pw->pw_name, NUID);
E 8
I 8
				strncpy(outrangename, pw->pw_name, NMAX);
E 8
				return (outrangename);
			}
			continue;
		}
		if (names[pw->pw_uid][0])
			continue;
		strncpy(names[pw->pw_uid], pw->pw_name, NMAX);
D 9
		if (pw->pw_uid == uid) {
E 9
I 9
		if (pw->pw_uid == uid)
E 9
			return (&names[uid][0]);
D 9
		}
E 9
	}
	init = 2;
D 9
	endpwent();
	return (0);
E 9
I 9
	goto rescan;
E 10
I 10
	nc[cp].uid = uid;
	SCPYN(nc[cp].name, pw->pw_name);
	return (nc[cp].name);
E 10
E 9
E 6
}
E 1
