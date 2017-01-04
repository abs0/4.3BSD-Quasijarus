h52248
s 00002/00002/00695
d D 7.7 88/07/01 09:05:59 bostic 26 25
c clever isdigit/isupper macros; from Chris
e
s 00112/00103/00585
d D 7.6 88/05/24 13:32:15 bostic 25 23
c many changes/cleanups; change to dev(a,b,c,d) format
e
s 00114/00103/00585
d R 7.6 88/03/03 14:58:31 bostic 24 23
c new version to handle (adapter, controller, drive, unit)
e
s 00020/00010/00668
d D 7.5 88/01/28 20:53:21 karels 23 22
c uvax changes; fix devsw index in confxx; header updates
e
s 00006/00000/00672
d D 7.4 87/04/17 15:59:15 karels 22 21
c squish
e
s 00016/00011/00656
d D 7.3 87/04/02 16:37:21 karels 21 20
c fix up more error messages
e
s 00092/00105/00575
d D 7.2 87/02/21 11:41:45 karels 20 19
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00679
d D 7.1 86/06/05 01:45:24 mckusick 19 18
c 4.3BSD release version
e
s 00010/00045/00670
d D 6.6 85/11/08 19:16:07 karels 18 17
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00111/00013/00604
d D 6.5 85/10/11 11:48:25 karels 17 16
c faster read; other stuff for later
e
s 00001/00001/00616
d D 6.4 85/10/04 00:12:51 bloom 16 15
c allow more units for second sbi (untested in rest of code)
e
s 00007/00001/00610
d D 6.3 85/06/08 13:12:24 mckusick 15 14
c Add copyright
e
s 00008/00000/00603
d D 6.2 83/09/23 10:07:35 karels 14 13
c ghg's severe burnin format
e
s 00000/00000/00603
d D 6.1 83/07/29 07:47:43 sam 13 12
c 4.2 distribution
e
s 00037/00012/00566
d D 4.10 83/02/16 21:50:44 sam 12 11
c use errno returns
e
s 00017/00000/00561
d D 4.9 83/01/16 14:39:56 helge 11 10
c added some more ioctl's
e
s 00126/00066/00435
d D 4.8 82/12/30 15:30:53 sam 10 9
c add ioctl's + errno; fix chk to work with new stuff
e
s 00000/00004/00501
d D 4.7 82/12/22 15:53:03 helge 9 8
c removed `count?' error message from read and write entries
e
s 00010/00004/00495
d D 4.6 82/07/15 21:32:06 root 8 7
c new boot scheme
e
s 00144/00129/00355
d D 4.5 82/03/07 19:11:58 mckusic 7 5
c convert to the new file system
e
s 00004/00005/00479
d R 4.5 82/02/28 16:58:18 mckusic 6 5
c put in new headers
e
s 00005/00004/00479
d D 4.4 81/03/22 20:52:15 wnj 5 4
c fixes
e
s 00003/00001/00480
d D 4.3 81/03/16 00:54:44 wnj 4 3
c fixes for generic functionality
e
s 00005/00000/00476
d D 4.2 81/02/09 03:26:15 toy 3 2
c Fixes to _stop for dual ported controllers.
e
s 00000/00000/00476
d D 4.1 80/11/09 16:29:41 bill 2 1
c stamp for 4bsd
e
s 00476/00000/00000
d D 1.1 80/06/28 10:43:12 bill 1 0
c date and time created 80/06/28 10:43:12 by bill
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%G%	*/
E 5
I 5
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
/*
D 19
 * Copyright (c) 1982 Regents of the University of California.
E 19
I 19
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 15
E 5

D 7
#include <sys/param.h>
#include <sys/ino.h>
#include <sys/inode.h>
#include <sys/filsys.h>
#include <sys/dir.h>
E 7
I 7
D 21
#include "../h/param.h"
#include "../h/inode.h"
#include "../h/fs.h"
D 8
#include "../h/ndir.h"
E 8
I 8
#include "../h/dir.h"
I 20
#include "../h/reboot.h"
E 21
I 21
#include "param.h"
#include "inode.h"
#include "fs.h"
#include "dir.h"
#include "reboot.h"
E 21
E 20
E 8
E 7
#include "saio.h"

I 25
D 26
#define	isdigit(c)	((c) >= '0' && (c) <= '9')
E 26
I 26
#define	isdigit(c)	((u_int)((c) - '0') <= 9)
E 26
#define	isspace(c)	((c) == ' ' || (c) == '\t')
D 26
#define	isupper(c)	((c) >= 'A' && (c) <= 'Z')
E 26
I 26
#define	isupper(c)	((u_int)((c) - 'A') <= 'Z' - 'A')
E 26
#define	tolower(c)	((c) - 'A' + 'a')

E 25
ino_t	dlook();

I 7
struct dirstuff {
	int loc;
	struct iob *io;
};

I 25
struct iob iob[NFILES];

E 25
E 7
static
D 10
openi(n,io)
E 10
I 10
openi(n, io)
E 10
D 7
register struct iob *io;
E 7
I 7
	register struct iob *io;
E 7
{
	register struct dinode *dp;
I 12
	int cc;
E 12

	io->i_offset = 0;
D 7
	io->i_bn = fsbtodb(itod(n)) + io->i_boff;
	io->i_cc = BSIZE;
E 7
I 7
	io->i_bn = fsbtodb(&io->i_fs, itod(&io->i_fs, n)) + io->i_boff;
	io->i_cc = io->i_fs.fs_bsize;
E 7
	io->i_ma = io->i_buf;
D 12
	devread(io);
E 12
I 12
	cc = devread(io);
E 12
D 7

E 7
	dp = (struct dinode *)io->i_buf;
D 7
	dp = &dp[itoo(n)];
	io->i_ino.i_number = n;
	io->i_ino.i_mode = dp->di_mode;
	io->i_ino.i_size = dp->di_size;
	l3tol((char *)io->i_ino.i_un.i_addr, (char *)dp->di_addr, NADDR);
E 7
I 7
	io->i_ino.i_ic = dp[itoo(&io->i_fs, n)].di_ic;
I 12
	return (cc);
E 12
E 7
}

static
find(path, file)
D 7
register char *path;
struct iob *file;
E 7
I 7
	register char *path;
	struct iob *file;
E 7
{
	register char *q;
I 21
D 25
	char *dir;
E 21
	char c;
E 25
I 25
	char *dir, c;
E 25
	int n;

D 25
	if (path==NULL || *path=='\0') {
E 25
I 25
	if (path == NULL || *path == '\0') {
E 25
		printf("null path\n");
D 10
		return(0);
E 10
I 10
		return (0);
E 10
	}

D 12
	openi((ino_t) ROOTINO, file);
E 12
I 12
	if (openi((ino_t) ROOTINO, file) < 0) {
		printf("can't read root inode\n");
		return (0);
	}
I 21
	dir = path;
E 21
E 12
	while (*path) {
		while (*path == '/')
			path++;
		q = path;
		while(*q != '/' && *q != '\0')
			q++;
		c = *q;
		*q = '\0';
I 17
		if (q == path) path = "." ;	/* "/" means "/." */
E 17

D 12
		if ((n=dlook(path, file))!=0) {
			if (c=='\0')
E 12
I 12
D 21
		if ((n = dlook(path, file)) != 0) {
E 21
I 21
		if ((n = dlook(path, file, dir)) != 0) {
E 21
			if (c == '\0')
E 12
				break;
D 12
			openi(n, file);
E 12
I 12
			if (openi(n, file) < 0)
				return (0);
E 12
			*q = c;
			path = q;
			continue;
		} else {
D 12
			printf("%s not found\n",path);
E 12
I 12
D 17
			printf("%s not found\n", path);
E 17
I 17
			printf("%s: not found\n", path);
E 17
E 12
D 10
			return(0);
E 10
I 10
			return (0);
E 10
		}
	}
D 10
	return(n);
E 10
I 10
	return (n);
E 10
}

I 25
#define	NBUFS	4
static char	b[NBUFS][MAXBSIZE];
static daddr_t	blknos[NBUFS];

E 25
static daddr_t
sbmap(io, bn)
D 7
register struct iob *io;
daddr_t bn;
E 7
I 7
	register struct iob *io;
	daddr_t bn;
E 7
{
D 7
	register i;
E 7
	register struct inode *ip;
D 7
	int j, sh;
E 7
I 7
	int i, j, sh;
E 7
	daddr_t nb, *bap;
D 7
	int ibn = bn;
E 7

	ip = &io->i_ino;
D 7
	if(bn < 0) {
E 7
I 7
	if (bn < 0) {
E 7
		printf("bn negative\n");
D 10
		return((daddr_t)0);
E 10
I 10
		return ((daddr_t)0);
E 10
	}

	/*
D 7
	 * blocks 0..NADDR-4 are direct blocks
E 7
I 7
	 * blocks 0..NDADDR are direct blocks
E 7
	 */
D 7
	if(bn < NADDR-3) {
		i = bn;
		nb = ip->i_un.i_addr[i];
E 7
I 7
	if(bn < NDADDR) {
		nb = ip->i_db[bn];
E 7
D 10
		return(nb);
E 10
I 10
		return (nb);
E 10
	}

	/*
D 7
	 * addresses NADDR-3, NADDR-2, and NADDR-1
	 * have single, double, triple indirect blocks.
	 * the first step is to determine
	 * how many levels of indirection.
E 7
I 7
	 * addresses NIADDR have single and double indirect blocks.
	 * the first step is to determine how many levels of indirection.
E 7
	 */
D 7
	sh = 0;
	nb = 1;
	bn -= NADDR-3;
	for(j=3; j>0; j--) {
		sh += NSHIFT;
		nb <<= NSHIFT;
		if(bn < nb)
E 7
I 7
	sh = 1;
	bn -= NDADDR;
	for (j = NIADDR; j > 0; j--) {
		sh *= NINDIR(&io->i_fs);
		if (bn < sh)
E 7
			break;
D 7
		bn -= nb;
E 7
I 7
		bn -= sh;
E 7
	}
D 7
	if(j == 0) {
		printf("bn ovf %D\n",bn);
		return((daddr_t)0);
E 7
I 7
	if (j == 0) {
		printf("bn ovf %D\n", bn);
		return ((daddr_t)0);
E 7
	}

	/*
D 7
	 * fetch the address from the inode
E 7
I 7
	 * fetch the first indirect block address from the inode
E 7
	 */
D 7
	nb = ip->i_un.i_addr[NADDR-j];
	if(nb == 0) {
E 7
I 7
	nb = ip->i_ib[NIADDR - j];
	if (nb == 0) {
E 7
		printf("bn void %D\n",bn);
D 10
		return((daddr_t)0);
E 10
I 10
		return ((daddr_t)0);
E 10
	}

	/*
	 * fetch through the indirect blocks
	 */
D 7
	for(; j<=3; j++) {
E 7
I 7
	for (; j <= NIADDR; j++) {
E 7
		if (blknos[j] != nb) {
D 7
			io->i_bn = fsbtodb(nb) + io->i_boff;
E 7
I 7
			io->i_bn = fsbtodb(&io->i_fs, nb) + io->i_boff;
E 7
			io->i_ma = b[j];
D 7
			io->i_cc = BSIZE;
E 7
I 7
			io->i_cc = io->i_fs.fs_bsize;
E 7
D 12
			devread(io);
E 12
I 12
			if (devread(io) != io->i_fs.fs_bsize) {
				if (io->i_error)
					errno = io->i_error;
				printf("bn %D: read error\n", io->i_bn);
				return ((daddr_t)0);
			}
E 12
D 7
			bap = (daddr_t *)b[j];
E 7
			blknos[j] = nb;
		}
		bap = (daddr_t *)b[j];
D 7
		sh -= NSHIFT;
		i = (bn>>sh) & NMASK;
E 7
I 7
		sh /= NINDIR(&io->i_fs);
		i = (bn / sh) % NINDIR(&io->i_fs);
E 7
		nb = bap[i];
		if(nb == 0) {
			printf("bn void %D\n",bn);
D 10
			return((daddr_t)0);
E 10
I 10
			return ((daddr_t)0);
E 10
		}
	}
D 10
	return(nb);
E 10
I 10
	return (nb);
E 10
}

static ino_t
D 21
dlook(s, io)
E 21
I 21
dlook(s, io, dir)
E 21
D 7
char *s;
register struct iob *io;
E 7
I 7
	char *s;
	register struct iob *io;
I 21
	char *dir;
E 21
E 7
{
	register struct direct *dp;
	register struct inode *ip;
D 7
	daddr_t bn;
	int n,dc;
E 7
I 7
	struct dirstuff dirp;
	int len;
E 7

D 7
	if (s==NULL || *s=='\0')
E 7
I 7
	if (s == NULL || *s == '\0')
E 7
D 10
		return(0);
E 10
I 10
		return (0);
E 10
	ip = &io->i_ino;
D 7
	if ((ip->i_mode&IFMT)!=IFDIR) {
E 7
I 7
	if ((ip->i_mode&IFMT) != IFDIR) {
E 7
D 23
		printf("not a directory\n");
E 23
I 17
D 21
		printf("%s: not a directory\n", s);
E 21
I 21
		printf("%s: not a directory\n", dir);
E 21
E 17
D 10
		return(0);
E 10
I 10
		return (0);
E 10
	}
D 7

	n = ip->i_size/sizeof(struct direct);

	if (n==0) {
E 7
I 7
	if (ip->i_size == 0) {
E 7
D 17
		printf("zero length directory\n");
E 17
I 17
D 21
		printf("%s: zero length directory\n", s);
E 21
I 21
		printf("%s: zero length directory\n", dir);
E 21
E 17
D 10
		return(0);
E 10
I 10
		return (0);
E 10
	}
D 7

	dc = BSIZE;
	bn = (daddr_t)0;
	while(n--) {
		if (++dc >= BSIZE/sizeof(struct direct)) {
			io->i_bn = fsbtodb(sbmap(io, bn++)) + io->i_boff;
			io->i_ma = io->i_buf;
			io->i_cc = BSIZE;
			devread(io);
			dp = (struct direct *)io->i_buf;
			dc = 0;
		}

		if (match(s, dp->d_name))
E 7
I 7
	len = strlen(s);
	dirp.loc = 0;
	dirp.io = io;
	for (dp = readdir(&dirp); dp != NULL; dp = readdir(&dirp)) {
		if(dp->d_ino == 0)
			continue;
		if (dp->d_namlen == len && !strcmp(s, dp->d_name))
E 7
D 10
			return(dp->d_ino);
E 10
I 10
			return (dp->d_ino);
E 10
D 7
		dp++;
E 7
	}
D 10
	return(0);
E 10
I 10
	return (0);
E 10
}

D 7
static
match(s1,s2)
register char *s1,*s2;
E 7
I 7
/*
 * get next entry in a directory.
 */
struct direct *
readdir(dirp)
	register struct dirstuff *dirp;
E 7
{
D 7
	register cc;
E 7
I 7
	register struct direct *dp;
	register struct iob *io;
	daddr_t lbn, d;
	int off;
E 7

D 7
	cc = DIRSIZ;
	while (cc--) {
		if (*s1 != *s2)
			return(0);
		if (*s1++ && *s2++)
			continue; else
			return(1);
E 7
I 7
	io = dirp->io;
	for(;;) {
		if (dirp->loc >= io->i_ino.i_size)
D 12
			return NULL;
E 12
I 12
			return (NULL);
E 12
		off = blkoff(&io->i_fs, dirp->loc);
		if (off == 0) {
			lbn = lblkno(&io->i_fs, dirp->loc);
			d = sbmap(io, lbn);
			if(d == 0)
D 25
				return NULL;
E 25
I 25
				return (NULL);
E 25
			io->i_bn = fsbtodb(&io->i_fs, d) + io->i_boff;
			io->i_ma = io->i_buf;
			io->i_cc = blksize(&io->i_fs, &io->i_ino, lbn);
D 12
			devread(io);
E 12
I 12
			if (devread(io) < 0) {
				errno = io->i_error;
D 17
				printf("bn %D: read error\n", io->i_bn);
E 17
I 17
				printf("bn %D: directory read error\n",
					io->i_bn);
E 17
				return (NULL);
			}
E 12
		}
		dp = (struct direct *)(io->i_buf + off);
		dirp->loc += dp->d_reclen;
		if (dp->d_ino == 0)
			continue;
		return (dp);
E 7
	}
D 7
	return(1);
E 7
}

lseek(fdesc, addr, ptr)
D 7
int	fdesc;
off_t	addr;
int	ptr;
E 7
I 7
D 10
	int	fdesc;
	off_t	addr;
	int	ptr;
E 10
I 10
	int fdesc, ptr;
	off_t addr;
E 10
E 7
{
	register struct iob *io;

I 18
D 25
#ifndef	SMALL
E 18
	if (ptr != 0) {
E 25
I 25
#ifndef SMALL
	if (ptr != L_SET) {
E 25
		printf("Seek not from beginning of file\n");
D 10
		return(-1);
E 10
I 10
		errno = EOFFSET;
		return (-1);
E 10
	}
I 18
D 25
#endif SMALL
E 25
I 25
#endif
E 25
E 18
	fdesc -= 3;
D 7
	if (fdesc < 0 || fdesc >= NFILES || ((io = &iob[fdesc])->i_flgs&F_ALLOC) == 0)
E 7
I 7
	if (fdesc < 0 || fdesc >= NFILES ||
D 10
	    ((io = &iob[fdesc])->i_flgs & F_ALLOC) == 0)
E 7
		return(-1);
E 10
I 10
	    ((io = &iob[fdesc])->i_flgs & F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
E 10
	io->i_offset = addr;
D 7
	io->i_bn = fsbtodb(addr/BSIZE) + io->i_boff;
E 7
I 7
	io->i_bn = addr / DEV_BSIZE;
E 7
	io->i_cc = 0;
D 10
	return(0);
E 10
I 10
	return (0);
E 10
}

getc(fdesc)
D 7
int	fdesc;
E 7
I 7
D 10
	int	fdesc;
E 10
I 10
	int fdesc;
E 10
E 7
{
	register struct iob *io;
I 7
	register struct fs *fs;
E 7
	register char *p;
D 7
	register  c;
	int off;
E 7
I 7
	int c, lbn, off, size, diff;
E 7


	if (fdesc >= 0 && fdesc <= 2)
D 10
		return(getchar());
E 10
I 10
		return (getchar());
E 10
	fdesc -= 3;
D 7
	if (fdesc < 0 || fdesc >= NFILES || ((io = &iob[fdesc])->i_flgs&F_ALLOC) == 0)
E 7
I 7
	if (fdesc < 0 || fdesc >= NFILES ||
D 10
	    ((io = &iob[fdesc])->i_flgs&F_ALLOC) == 0)
E 7
		return(-1);
E 10
I 10
	    ((io = &iob[fdesc])->i_flgs&F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
E 10
	p = io->i_ma;
	if (io->i_cc <= 0) {
D 7
		io->i_bn = fsbtodb(io->i_offset/(off_t)BSIZE);
		if (io->i_flgs&F_FILE)
			io->i_bn = fsbtodb(sbmap(io, dbtofsb(io->i_bn))) + io->i_boff;
E 7
I 7
		if ((io->i_flgs & F_FILE) != 0) {
			diff = io->i_ino.i_size - io->i_offset;
			if (diff <= 0)
				return (-1);
			fs = &io->i_fs;
			lbn = lblkno(fs, io->i_offset);
			io->i_bn = fsbtodb(fs, sbmap(io, lbn)) + io->i_boff;
			off = blkoff(fs, io->i_offset);
			size = blksize(fs, &io->i_ino, lbn);
		} else {
			io->i_bn = io->i_offset / DEV_BSIZE;
			off = 0;
			size = DEV_BSIZE;
		}
E 7
		io->i_ma = io->i_buf;
D 7
		io->i_cc = BSIZE;
E 7
I 7
		io->i_cc = size;
E 7
D 12
		devread(io);
E 12
I 12
		if (devread(io) < 0) {
			errno = io->i_error;
			return (-1);
		}
E 12
D 7
		if (io->i_flgs&F_FILE) {
			off = io->i_offset % (off_t)BSIZE;
			if (io->i_offset+(BSIZE-off) >= io->i_ino.i_size)
				io->i_cc = io->i_ino.i_size - io->i_offset + off;
E 7
I 7
		if ((io->i_flgs & F_FILE) != 0) {
			if (io->i_offset - off + size >= io->i_ino.i_size)
				io->i_cc = diff + off;
E 7
			io->i_cc -= off;
D 7
			if (io->i_cc <= 0)
				return(-1);
		} else
			off = 0;
E 7
I 7
		}
E 7
		p = &io->i_buf[off];
	}
	io->i_cc--;
	io->i_offset++;
	c = (unsigned)*p++;
	io->i_ma = p;
D 10
	return(c);
E 10
I 10
	return (c);
E 10
}
I 7

E 7
D 18
/* does this port?
getw(fdesc)
D 7
int	fdesc;
E 7
I 7
D 10
	int	fdesc;
E 10
I 10
	int fdesc;
E 10
E 7
{
	register w,i;
	register char *cp;
	int val;

	for (i = 0, val = 0, cp = &val; i < sizeof(val); i++) {
		w = getc(fdesc);
		if (w < 0) {
			if (i == 0)
D 10
				return(-1);
E 10
I 10
				return (-1);
E 10
			else
D 10
				return(val);
E 10
I 10
				return (val);
E 10
		}
		*cp++ = w;
	}
D 10
	return(val);
E 10
I 10
	return (val);
E 10
}
*/
E 18
I 10
int	errno;
E 10

read(fdesc, buf, count)
D 7
int	fdesc;
char	*buf;
int	count;
E 7
I 7
D 10
	int	fdesc;
	char	*buf;
	int	count;
E 10
I 10
	int fdesc, count;
	char *buf;
E 10
E 7
{
D 17
	register i;
E 17
I 17
	register i, size;
E 17
	register struct iob *file;
I 17
	register struct fs *fs;
	int lbn, off;
E 17

I 10
	errno = 0;
E 10
	if (fdesc >= 0 & fdesc <= 2) {
		i = count;
		do {
			*buf = getchar();
		} while (--i && *buf++ != '\n');
D 10
		return(count - i);
E 10
I 10
		return (count - i);
E 10
	}
	fdesc -= 3;
D 7
	if (fdesc < 0 || fdesc >= NFILES || ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0)
E 7
I 7
	if (fdesc < 0 || fdesc >= NFILES ||
D 10
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0)
E 7
		return(-1);
	if ((file->i_flgs&F_READ) == 0)
		return(-1);
E 10
I 10
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
	if ((file->i_flgs&F_READ) == 0) {
		errno = EBADF;
		return (-1);
	}
I 18
D 25
#ifndef	SMALL
E 25
I 25
#ifndef SMALL
E 25
E 18
E 10
D 7
	if ((file->i_flgs&F_FILE) == 0) {
E 7
I 7
	if ((file->i_flgs & F_FILE) == 0) {
I 8
D 9
		if (count % DEV_BSIZE)
			printf("count=%d?\n", count);
E 9
E 8
E 7
		file->i_cc = count;
		file->i_ma = buf;
I 8
		file->i_bn = file->i_boff + (file->i_offset / DEV_BSIZE);
E 8
		i = devread(file);
D 7
		file->i_bn += CLSIZE;
E 7
I 7
D 8
		file->i_bn += (count / DEV_BSIZE);
E 8
I 8
D 20
		file->i_offset += count;
E 20
E 8
E 7
D 10
		return(i);
E 10
I 10
		if (i < 0)
			errno = file->i_error;
I 20
		else
			file->i_offset += i;
E 20
		return (i);
E 10
D 7
	}
	else {
E 7
I 7
D 17
	} else {
E 7
		if (file->i_offset+count > file->i_ino.i_size)
			count = file->i_ino.i_size - file->i_offset;
		if ((i = count) <= 0)
D 10
			return(0);
E 10
I 10
			return (0);
E 10
		do {
			*buf++ = getc(fdesc+3);
		} while (--i);
D 10
		return(count);
E 10
I 10
		return (count);
E 17
E 10
	}
I 18
D 25
#endif SMALL
E 25
I 25
#endif
E 25
E 18
I 17
	if (file->i_offset+count > file->i_ino.i_size)
		count = file->i_ino.i_size - file->i_offset;
	if ((i = count) <= 0)
		return (0);
	/*
	 * While reading full blocks, do I/O into user buffer.
	 * Anything else uses getc().
	 */
	fs = &file->i_fs;
	while (i) {
		off = blkoff(fs, file->i_offset);
		lbn = lblkno(fs, file->i_offset);
		size = blksize(fs, &file->i_ino, lbn);
		if (off == 0 && size <= i) {
			file->i_bn = fsbtodb(fs, sbmap(file, lbn)) +
			    file->i_boff;
			file->i_cc = size;
			file->i_ma = buf;
			if (devread(file) < 0) {
				errno = file->i_error;
				return (-1);
			}
			file->i_offset += size;
			file->i_cc = 0;
			buf += size;
			i -= size;
		} else {
			size -= off;
			if (size > i)
				size = i;
			i -= size;
			do {
				*buf++ = getc(fdesc+3);
			} while (--size);
		}
	}
	return (count);
E 17
}

I 18
D 25
#ifndef	SMALL
E 25
I 25
#ifndef SMALL
E 25
E 18
write(fdesc, buf, count)
D 7
int	fdesc;
char	*buf;
int	count;
E 7
I 7
D 10
	int	fdesc;
	char	*buf;
	int	count;
E 10
I 10
	int fdesc, count;
	char *buf;
E 10
E 7
{
	register i;
	register struct iob *file;

I 10
	errno = 0;
E 10
	if (fdesc >= 0 && fdesc <= 2) {
		i = count;
		while (i--)
			putchar(*buf++);
D 10
		return(count);
E 10
I 10
		return (count);
E 10
	}
	fdesc -= 3;
D 7
	if (fdesc < 0 || fdesc >= NFILES || ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0)
E 7
I 7
	if (fdesc < 0 || fdesc >= NFILES ||
D 10
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0)
E 7
		return(-1);
	if ((file->i_flgs&F_WRITE) == 0)
		return(-1);
E 10
I 10
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
	if ((file->i_flgs&F_WRITE) == 0) {
		errno = EBADF;
		return (-1);
	}
E 10
I 8
D 9
	if (count % DEV_BSIZE)
		printf("count=%d?\n", count);
E 9
E 8
	file->i_cc = count;
	file->i_ma = buf;
I 8
	file->i_bn = file->i_boff + (file->i_offset / DEV_BSIZE);
E 8
	i = devwrite(file);
D 7
	file->i_bn += CLSIZE;
E 7
I 7
D 8
	file->i_bn += (count / DEV_BSIZE);
E 8
I 8
	file->i_offset += count;
E 8
E 7
D 10
	return(i);
E 10
I 10
	if (i < 0)
		errno = file->i_error;
	return (i);
E 10
}
I 18
D 25
#endif SMALL
E 25
I 25
#endif
E 25
E 18

I 5
int	openfirst = 1;
I 17
D 20
#ifdef notyet
int	opendev;	/* last device opened; for boot to set bootdev */
extern	int bootdev;
#endif notyet
E 20
I 20
D 25
unsigned opendev;		/* last device opened */
extern	unsigned bootdev;
E 25
I 25
u_int	opendev;		/* last device opened */
extern u_int bootdev;
E 25
E 20
E 17

E 5
open(str, how)
D 7
char *str;
int	how;
E 7
I 7
	char *str;
D 10
	int	how;
E 10
I 10
	int how;
E 10
E 7
{
D 25
	register char *cp;
D 20
	int i;
E 20
I 20
	register int i;
E 25
I 25
	register char *t;
	register int cnt;
E 25
E 20
	register struct iob *file;
D 20
	register struct devsw *dp;
E 20
D 10
	int	fdesc;
D 5
	static first = 1;
E 5
	long	atol();
E 10
I 10
D 25
	int fdesc;
	long atol();
E 25
I 25
	int fdesc, args[8], *argp;
E 25
E 10

D 5
	if (first) {
E 5
I 5
	if (openfirst) {
E 5
D 25
		for (i = 0; i < NFILES; i++)
			iob[i].i_flgs = 0;
E 25
I 25
		for (cnt = 0; cnt < NFILES; cnt++)
			iob[cnt].i_flgs = 0;
E 25
D 5
		first = 0;
E 5
I 5
		openfirst = 0;
E 5
	}

D 25
	for (fdesc = 0; fdesc < NFILES; fdesc++)
		if (iob[fdesc].i_flgs == 0)
			goto gotfile;
	_stop("No more file slots");
gotfile:
	(file = &iob[fdesc])->i_flgs |= F_ALLOC;
E 25
I 25
	for (fdesc = 0;; fdesc++) {
		if (fdesc == NFILES)
			_stop("No more file slots");
		if (iob[fdesc].i_flgs == 0) {
			file = &iob[fdesc];
			file->i_flgs |= F_ALLOC;
			file->i_adapt = file->i_ctlr = file->i_unit =
			    file->i_part = 0;
			break;
		}
	}
E 25

I 22
D 25
#ifndef	SMALL
E 22
I 17
D 20
#ifdef notyet
	for (cp = str; *cp && *cp != '/' && *cp != ':'; cp++)
			;
	if (*cp != ':') {
E 20
I 20
	for (cp = str; *cp && *cp != '/' && *cp != ':' && *cp != '('; cp++)
		;
	if (*cp == '(') {
		if ((file->i_ino.i_dev = getdev(str, cp - str)) == -1)
E 25
I 25
	for (cnt = 0; cnt < sizeof(args)/sizeof(args[0]); args[cnt++] = 0);
#ifndef SMALL
	for (t = str; *t && *t != '/' && *t != ':' && *t != '('; ++t)
		if (isupper(*t))
			*t = tolower(*t);
	switch(*t) {
	case '(':	/* type(adapt, ctlr, drive, partition)file */
		if ((file->i_ino.i_dev = getdev(str, t - str)) == -1)
E 25
			goto bad;
D 25
		cp++;
		if ((file->i_unit = getunit(cp)) == -1)
			goto bad;
		for (; *cp != ','; cp++)
D 23
			if (*cp == NULL) {
E 23
I 23
			if (*cp == 0) {
E 23
				errno = EOFFSET;
				goto badspec;
			}
D 21
		file->i_boff = atol(cp);
E 21
I 21
		file->i_boff = atol(++cp);
E 21
		for (;;) {
			if (*cp == ')')
E 25
I 25
		for (argp = args + 4, cnt = 0; *t != ')'; ++cnt) {
			for (++t; isspace(*t); ++t);
			if (*t == ')')
E 25
				break;
D 25
			if (*cp++)
				continue;
			goto badspec;
E 25
I 25
			if (!isdigit(*t))
				goto badspec;
			*argp++ = atoi(t);
			for (++t; isdigit(*t); ++t);
			if (*t != ',' && *t != ')' || cnt == 4)
				goto badspec;
E 25
		}
I 21
D 25
		cp++;
E 21
	} else if (*cp != ':') {
I 22
#endif
E 22
E 20
		/* default bootstrap unit and device */
D 20
		file->i_ino.i_dev = bootdev;
E 20
I 20
		file->i_ino.i_dev = (bootdev >> B_TYPESHIFT) & B_TYPEMASK;
		file->i_unit = ((bootdev >> B_UNITSHIFT) & B_UNITMASK) +
		     (8 * ((bootdev >> B_ADAPTORSHIFT) & B_ADAPTORMASK));
		file->i_boff = (bootdev >> B_PARTITIONSHIFT) & B_PARTITIONMASK;
E 20
		cp = str;
I 22
#ifndef	SMALL
E 22
	} else {
# define isdigit(n)	((n>='0') && (n<='9'))
I 20
		if (cp == str)
			goto badspec;
E 20
		/*
	 	 * syntax for possible device name:
	 	 *	<alpha-string><digit-string><letter>:
	 	 */
		for (cp = str; *cp != ':' && !isdigit(*cp); cp++)
			;
D 20
		for (dp = devsw; dp->dv_name; dp++) {
			if (!strncmp(str, dp->dv_name,cp-str))
				goto gotdev;
		}
		printf("unknown device\n");
		file->i_flgs = 0;
		errno = EDEV;
		return (-1);
	gotdev:
		i = 0;
		while (*cp >= '0' && *cp <= '9')
			i = i * 10 + *cp++ - '0';
		if (i < 0 || i > 255) {
			printf("minor device number out of range (0-255)\n");
			file->i_flgs = 0;
			errno = EUNIT;
			return (-1);
		}
		if (*cp >= 'a' && *cp <= 'h') {
			if (i > 31) {
				printf("unit number out of range (0-31)\n");
				file->i_flgs = 0;
				errno = EUNIT;
				return (-1);
			}
			i = make_minor(i, *cp++ - 'a');
		}

E 20
I 20
		if ((file->i_ino.i_dev = getdev(str, cp - str)) == -1)
E 25
I 25
		for (++t; isspace(*t); ++t);
		argp -= 4;
		file->i_adapt = *argp++;
		file->i_ctlr = *argp++;
		file->i_unit = *argp++;
		file->i_part = *argp;
		break;
	case ':':	/* [A-Za-z]*[0-9]*[A-Za-z]:file */
		for (t = str; *t != ':' && !isdigit(*t); ++t);
		if ((file->i_ino.i_dev = getdev(str, t - str)) == -1)
E 25
			goto bad;
D 25
		if ((file->i_unit = getunit(cp)) == -1)
E 25
I 25
		if ((file->i_unit = getunit(t)) == -1)
E 25
			goto bad;
D 25
		while (isdigit(*cp))
			cp++;
		file->i_boff = 0;
		if (*cp >= 'a' && *cp <= 'h')
			file->i_boff = *cp++ - 'a';
E 20
		if (*cp++ != ':') {
E 25
I 25
		for (; isdigit(*t); ++t);
		if (*t >= 'a' && *t <= 'h')
			file->i_part = *t++ - 'a';
		if (*t != ':') {
E 25
D 20
			printf("incorrect device specification\n");
			file->i_flgs = 0;
E 20
			errno = EOFFSET;
D 20
			return (-1);
E 20
I 20
			goto badspec;
E 20
		}
I 25
		for (++t; isspace(*t); ++t);
		break;
	case '/':
	default:		/* default bootstrap unit and device */
#else
	{
#endif /* SMALL */
		file->i_ino.i_dev = B_TYPE(bootdev);
		file->i_adapt = B_ADAPTOR(bootdev);
		file->i_ctlr = B_CONTROLLER(bootdev);
		file->i_unit = B_UNIT(bootdev);
		file->i_part = B_PARTITION(bootdev);
		t = str;
E 25
D 20
		opendev = file->i_ino.i_dev = makedev(dp-devsw, i);
E 20
	}
I 22
D 25
#endif
E 22
D 20
	file->i_boff = 0;
	devopen(file);
E 20
I 20
	opendev = file->i_ino.i_dev << B_TYPESHIFT;
D 23
	opendev |= ((file->i_unit % 8) << B_UNITSHIFT);
	opendev |= ((file->i_unit / 8) << B_ADAPTORSHIFT);
E 23
I 23
	opendev |= (file->i_unit % 8) << B_UNITSHIFT;
	opendev |= (file->i_unit / 8) << B_ADAPTORSHIFT;
E 23
	opendev |= file->i_boff << B_PARTITIONSHIFT;
I 21
	opendev |= B_DEVMAGIC;
E 25
I 25

	opendev = MAKEBOOTDEV(file->i_ino.i_dev, file->i_adapt, file->i_ctlr,
	    file->i_unit, file->i_part);

E 25
E 21
	if (errno = devopen(file))
		goto bad;
I 23
D 25
#ifndef SMALL
E 23
E 20
	if (cp != str && *cp == '\0') {
		file->i_flgs |= how+1;
E 25
I 25

	if (*t == '\0') {
		file->i_flgs |= how + 1;
E 25
		file->i_cc = 0;
		file->i_offset = 0;
		return (fdesc+3);
	}
I 25
#ifndef SMALL
	else if (how != 0) {
		printf("Can't write files yet.. Sorry\n");
		errno = EIO;
		goto bad;
	}
E 25
I 23
#endif
E 23
D 20
#else notyet
E 17
	for (cp = str; *cp && *cp != '('; cp++)
			;
	if (*cp != '(') {
		printf("Bad device\n");
		file->i_flgs = 0;
D 10
		return(-1);
E 10
I 10
		errno = EDEV;
		return (-1);
E 10
	}
	*cp++ = '\0';
	for (dp = devsw; dp->dv_name; dp++) {
D 7
		if (match(str, dp->dv_name))
E 7
I 7
		if (!strcmp(str, dp->dv_name))
E 7
			goto gotdev;
	}
	printf("Unknown device\n");
	file->i_flgs = 0;
D 10
	return(-1);
E 10
I 10
	errno = ENXIO;
	return (-1);
E 10
gotdev:
	*(cp-1) = '(';
	file->i_ino.i_dev = dp-devsw;
	file->i_unit = *cp++ - '0';
D 4
	if (file->i_unit < 0 || file->i_unit > 7) {
E 4
I 4
	if (*cp >= '0' && *cp <= '9')
		file->i_unit = file->i_unit * 10 + *cp++ - '0';
D 16
	if (file->i_unit < 0 || file->i_unit > 31) {
E 16
I 16
	if (file->i_unit < 0 || file->i_unit > 63) {
E 16
E 4
		printf("Bad unit specifier\n");
		file->i_flgs = 0;
D 10
		return(-1);
E 10
I 10
		errno = EUNIT;
		return (-1);
E 10
	}
	if (*cp++ != ',') {
badoff:
		printf("Missing offset specification\n");
		file->i_flgs = 0;
D 10
		return(-1);
E 10
I 10
		errno = EOFFSET;
		return (-1);
E 10
	}
	file->i_boff = atol(cp);
	for (;;) {
		if (*cp == ')')
			break;
		if (*cp++)
			continue;
		goto badoff;
	}
	devopen(file);
	if (*++cp == '\0') {
		file->i_flgs |= how+1;
		file->i_cc = 0;
		file->i_offset = 0;
D 10
		return(fdesc+3);
E 10
I 10
		return (fdesc+3);
E 10
	}
I 17
#endif notyet
E 20
E 17
I 7
	file->i_ma = (char *)(&file->i_fs);
	file->i_cc = SBSIZE;
D 8
	file->i_bn = SBLOCK;
E 8
I 8
D 21
	file->i_bn = SBLOCK + file->i_boff;
E 21
I 21
	file->i_bn = SBOFF / DEV_BSIZE + file->i_boff;
E 21
E 8
	file->i_offset = 0;
D 12
	devread(file);
E 12
I 12
	if (devread(file) < 0) {
		errno = file->i_error;
		printf("super block read error\n");
D 20
		return (-1);
E 20
I 20
		goto bad;
E 20
	}
E 12
E 7
D 25
	if ((i = find(cp, file)) == 0) {
E 25
I 25
	if ((cnt = find(t, file)) == 0) {
E 25
D 20
		file->i_flgs = 0;
E 20
D 10
		return(-1);
E 10
I 10
		errno = ESRCH;
D 20
		return (-1);
E 20
I 20
		goto bad;
E 20
E 10
	}
I 18
D 25
#ifndef	SMALL
E 18
	if (how != 0) {
		printf("Can't write files yet.. Sorry\n");
D 20
		file->i_flgs = 0;
E 20
D 10
		return(-1);
E 10
I 10
		errno = EIO;
D 20
		return (-1);
E 20
I 20
		goto bad;
E 20
E 10
	}
I 18
#endif SMALL
E 18
D 12
	openi(i, file);
E 12
I 12
	if (openi(i, file) < 0) {
E 25
I 25
	if (openi(cnt, file) < 0) {
E 25
		errno = file->i_error;
D 20
		return (-1);
E 20
I 20
		goto bad;
E 20
	}
E 12
	file->i_offset = 0;
	file->i_cc = 0;
	file->i_flgs |= F_FILE | (how+1);
D 10
	return(fdesc+3);
E 10
I 10
	return (fdesc+3);
I 20

I 23
#ifndef SMALL
E 23
badspec:
D 25
	printf("malformed device specification\n");
E 25
I 25
	printf("malformed device specification\nusage: device(adaptor, controller, drive, partition)file\n");
E 25
I 23
#endif
E 23
bad:
	file->i_flgs = 0;
	return (-1);
}

I 22
#ifndef SMALL
E 22
static
getdev(str, len)
D 23
	char *str;
E 23
I 23
	register char *str;
E 23
	int len;
{
	register struct devsw *dp;
I 23
	register int i;
D 25
	char c = str[len];
E 25
I 25
	char savedch = str[len];
E 25
E 23

D 23
	for (dp = devsw; dp->dv_name; dp++) {
		if (!strncmp(str, dp->dv_name, len))
			return (dp - devsw);
	}
	printf("Unknown device\n");
E 23
I 23
D 25
	str[len] = 0;
E 25
I 25
	str[len] = '\0';
E 25
	for (dp = devsw, i = 0; i < ndevs; dp++, i++)
		if (dp->dv_name && strcmp(str, dp->dv_name) == 0) {
D 25
			str[len] = c;
E 25
I 25
			str[len] = savedch;
E 25
			return (i);
		}
	printf("Unknown device\nKnown devices are:\n");
	for (dp = devsw, i = 0; i < ndevs; dp++, i++)
		if (dp->dv_name)
			printf(" %s", dp->dv_name);
I 25
	printf("\n");
E 25
E 23
	errno = ENXIO;
	return (-1);
}

static
getunit(cp)
	register char *cp;
{
D 25
	register int i = 0;
E 25
I 25
	int unit;
E 25

D 25
	while (*cp >= '0' && *cp <= '9')
		i = i * 10 + *cp++ - '0';
	if ((unsigned) i > 255) {
E 25
I 25
	unit = atoi(cp);
	if ((u_int)unit > 255) {
E 25
		printf("minor device number out of range (0-255)\n");
		errno = EUNIT;
D 25
		i = -1;
E 25
I 25
		return (-1);
E 25
	}
D 25
	return (i);
E 25
I 25
	return (unit);
E 25
E 20
E 10
}
I 22
D 25
#endif
E 25
I 25
#endif /* SMALL */
E 25
E 22

close(fdesc)
D 7
int	fdesc;
E 7
I 7
D 10
	int	fdesc;
E 10
I 10
	int fdesc;
E 10
E 7
{
	struct iob *file;

	fdesc -= 3;
D 7
	if (fdesc < 0 || fdesc >= NFILES || ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0)
E 7
I 7
	if (fdesc < 0 || fdesc >= NFILES ||
D 10
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0)
E 7
		return(-1);
E 10
I 10
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
E 10
	if ((file->i_flgs&F_FILE) == 0)
		devclose(file);
	file->i_flgs = 0;
D 10
	return(0);
E 10
I 10
	return (0);
E 10
}

I 18
D 25
#ifndef	SMALL
E 25
I 25
#ifndef SMALL
E 25
E 18
I 10
ioctl(fdesc, cmd, arg)
	int fdesc, cmd;
	char *arg;
{
	register struct iob *file;
	int error = 0;

I 11
	fdesc -= 3;
E 11
	if (fdesc < 0 || fdesc >= NFILES ||
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
	switch (cmd) {

	case SAIOHDR:
		file->i_flgs |= F_HDR;
		break;

	case SAIOCHECK:
		file->i_flgs |= F_CHECK;
		break;

	case SAIOHCHECK:
		file->i_flgs |= F_HCHECK;
I 11
		break;

	case SAIONOBAD:
		file->i_flgs |= F_NBSF;
		break;

	case SAIODOBAD:
		file->i_flgs &= ~F_NBSF;
		break;

D 18
	case SAIOECCLIM:
		file->i_flgs |= F_ECCLM;
		break;

	case SAIOECCUNL:
		file->i_flgs &= ~F_ECCLM;
E 11
		break;

I 14
	case SAIOSEVRE:
		file->i_flgs |= F_SEVRE;
		break;

	case SAIONSEVRE:
		file->i_flgs &= ~F_SEVRE;
		break;

E 18
E 14
	default:
		error = devioctl(file, cmd, arg);
		break;
	}
	if (error < 0)
		errno = file->i_error;
	return (error);
}
I 18
D 25
#endif SMALL
E 25
I 25
#endif /* SMALL */
E 25
E 18

E 10
exit()
{
	_stop("Exit called");
}

_stop(s)
D 7
char	*s;
E 7
I 7
D 10
	char	*s;
E 10
I 10
	char *s;
E 10
E 7
{
I 3
	int i;

	for (i = 0; i < NFILES; i++)
		if (iob[i].i_flgs != 0)
			close(i);
E 3
	printf("%s\n", s);
	_rtt();
D 18
}

trap(ps)
D 7
int ps;
E 7
I 7
	int ps;
E 7
{
	printf("Trap %o\n", ps);
	for (;;)
		;
E 18
}
E 1
