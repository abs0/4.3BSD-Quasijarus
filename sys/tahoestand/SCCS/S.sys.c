h46946
s 00000/00017/00674
d D 1.4 88/03/03 14:57:06 bostic 4 3
c remove trap and uncache to prf.c
e
s 00103/00114/00588
d D 1.3 87/04/02 16:01:31 karels 3 2
c notyet is here (new notation), also support old;
c fix up some more error msgs
e
s 00179/00041/00523
d D 1.2 86/12/18 23:52:23 karels 2 1
c updates
e
s 00564/00000/00000
d D 1.1 86/01/12 18:05:02 sam 1 0
c date and time created 86/01/12 18:05:02 by sam
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%E%	*/
/*	sys.c	6.2	83/09/23	*/
E 2
I 2
/*
 * Copyright (c) 1982, 1986 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%M%	%I%	%E%
 *
D 3
 * from	@(#)sys.c	7.1 (Berkeley) 6/5/86
E 3
I 3
 * from vax	@(#)sys.c	7.1 (Berkeley) 6/5/86
E 3
 */
E 2

D 3
#include "../machine/mtpr.h"

E 3
#include "param.h"
#include "inode.h"
#include "fs.h"
#include "dir.h"
I 3
#include "reboot.h"
E 3
D 2

E 2
#include "saio.h"
I 3
#include "../machine/mtpr.h"
E 3

ino_t	dlook();

struct dirstuff {
	int loc;
	struct iob *io;
};

static
openi(n, io)
	register struct iob *io;
{
	register struct dinode *dp;
	int cc;

	io->i_offset = 0;
	io->i_bn = fsbtodb(&io->i_fs, itod(&io->i_fs, n)) + io->i_boff;
	io->i_cc = io->i_fs.fs_bsize;
	io->i_ma = io->i_buf;
	cc = devread(io);
	dp = (struct dinode *)io->i_buf;
	io->i_ino.i_ic = dp[itoo(&io->i_fs, n)].di_ic;
	return (cc);
}

static
find(path, file)
	register char *path;
	struct iob *file;
{
	register char *q;
I 3
	char *dir;
E 3
	char c;
	int n;

	if (path==NULL || *path=='\0') {
		printf("null path\n");
		return (0);
	}

	if (openi((ino_t) ROOTINO, file) < 0) {
		printf("can't read root inode\n");
		return (0);
	}
I 3
	dir = path;
E 3
	while (*path) {
		while (*path == '/')
			path++;
		q = path;
		while(*q != '/' && *q != '\0')
			q++;
		c = *q;
		*q = '\0';
I 2
		if (q == path) path = "." ;	/* "/" means "/." */
E 2

D 3
		if ((n = dlook(path, file)) != 0) {
E 3
I 3
		if ((n = dlook(path, file, dir)) != 0) {
E 3
			if (c == '\0')
				break;
			if (openi(n, file) < 0)
				return (0);
			*q = c;
			path = q;
			continue;
		} else {
D 2
			printf("%s not found\n", path);
E 2
I 2
			printf("%s: not found\n", path);
E 2
			return (0);
		}
	}
	return (n);
}

static daddr_t
sbmap(io, bn)
	register struct iob *io;
	daddr_t bn;
{
	register struct inode *ip;
	int i, j, sh;
	daddr_t nb, *bap;

	ip = &io->i_ino;
	if (bn < 0) {
		printf("bn negative\n");
		return ((daddr_t)0);
	}

	/*
	 * blocks 0..NDADDR are direct blocks
	 */
	if(bn < NDADDR) {
		nb = ip->i_db[bn];
		return (nb);
	}

	/*
	 * addresses NIADDR have single and double indirect blocks.
	 * the first step is to determine how many levels of indirection.
	 */
	sh = 1;
	bn -= NDADDR;
	for (j = NIADDR; j > 0; j--) {
		sh *= NINDIR(&io->i_fs);
		if (bn < sh)
			break;
		bn -= sh;
	}
	if (j == 0) {
		printf("bn ovf %D\n", bn);
		return ((daddr_t)0);
	}

	/*
	 * fetch the first indirect block address from the inode
	 */
	nb = ip->i_ib[NIADDR - j];
	if (nb == 0) {
		printf("bn void %D\n",bn);
		return ((daddr_t)0);
	}

	/*
	 * fetch through the indirect blocks
	 */
	for (; j <= NIADDR; j++) {
		if (blknos[j] != nb) {
			io->i_bn = fsbtodb(&io->i_fs, nb) + io->i_boff;
			io->i_ma = b[j];
			io->i_cc = io->i_fs.fs_bsize;
			if (devread(io) != io->i_fs.fs_bsize) {
				if (io->i_error)
					errno = io->i_error;
				printf("bn %D: read error\n", io->i_bn);
				return ((daddr_t)0);
			}
			blknos[j] = nb;
		}
		bap = (daddr_t *)b[j];
		sh /= NINDIR(&io->i_fs);
		i = (bn / sh) % NINDIR(&io->i_fs);
		nb = bap[i];
		if(nb == 0) {
			printf("bn void %D\n",bn);
			return ((daddr_t)0);
		}
	}
	return (nb);
}

static ino_t
D 3
dlook(s, io)
E 3
I 3
dlook(s, io, dir)
E 3
	char *s;
	register struct iob *io;
I 3
	char *dir;
E 3
{
	register struct direct *dp;
	register struct inode *ip;
	struct dirstuff dirp;
	int len;

	if (s == NULL || *s == '\0')
		return (0);
	ip = &io->i_ino;
	if ((ip->i_mode&IFMT) != IFDIR) {
D 3
		printf("not a directory\n");
I 2
		printf("%s: not a directory\n", s);
E 3
I 3
		printf("%s: not a directory\n", dir);
E 3
E 2
		return (0);
	}
	if (ip->i_size == 0) {
D 2
		printf("zero length directory\n");
E 2
I 2
D 3
		printf("%s: zero length directory\n", s);
E 3
I 3
		printf("%s: zero length directory\n", dir);
E 3
E 2
		return (0);
	}
	len = strlen(s);
	dirp.loc = 0;
	dirp.io = io;
	for (dp = readdir(&dirp); dp != NULL; dp = readdir(&dirp)) {
		if(dp->d_ino == 0)
			continue;
		if (dp->d_namlen == len && !strcmp(s, dp->d_name))
			return (dp->d_ino);
	}
	return (0);
}

/*
 * get next entry in a directory.
 */
struct direct *
readdir(dirp)
	register struct dirstuff *dirp;
{
	register struct direct *dp;
	register struct iob *io;
	daddr_t lbn, d;
	int off;

	io = dirp->io;
	for(;;) {
		if (dirp->loc >= io->i_ino.i_size)
			return (NULL);
		off = blkoff(&io->i_fs, dirp->loc);
		if (off == 0) {
			lbn = lblkno(&io->i_fs, dirp->loc);
			d = sbmap(io, lbn);
			if(d == 0)
				return NULL;
			io->i_bn = fsbtodb(&io->i_fs, d) + io->i_boff;
			io->i_ma = io->i_buf;
			io->i_cc = blksize(&io->i_fs, &io->i_ino, lbn);
			if (devread(io) < 0) {
				errno = io->i_error;
D 2
				printf("bn %D: read error\n", io->i_bn);
E 2
I 2
				printf("bn %D: directory read error\n",
					io->i_bn);
E 2
				return (NULL);
			}
		}
		dp = (struct direct *)(io->i_buf + off);
		dirp->loc += dp->d_reclen;
		if (dp->d_ino == 0)
			continue;
		return (dp);
	}
}

lseek(fdesc, addr, ptr)
	int fdesc, ptr;
	off_t addr;
{
	register struct iob *io;

I 2
#ifndef	SMALL
E 2
	if (ptr != 0) {
		printf("Seek not from beginning of file\n");
		errno = EOFFSET;
		return (-1);
	}
I 2
#endif SMALL
E 2
	fdesc -= 3;
	if (fdesc < 0 || fdesc >= NFILES ||
	    ((io = &iob[fdesc])->i_flgs & F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
	io->i_offset = addr;
	io->i_bn = addr / DEV_BSIZE;
	io->i_cc = 0;
	return (0);
}

getc(fdesc)
	int fdesc;
{
	register struct iob *io;
	register struct fs *fs;
	register char *p;
	int c, lbn, off, size, diff;


	if (fdesc >= 0 && fdesc <= 2)
		return (getchar());
	fdesc -= 3;
	if (fdesc < 0 || fdesc >= NFILES ||
	    ((io = &iob[fdesc])->i_flgs&F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
	p = io->i_ma;
	if (io->i_cc <= 0) {
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
		io->i_ma = io->i_buf;
		io->i_cc = size;
		if (devread(io) < 0) {
			errno = io->i_error;
			return (-1);
		}
		if ((io->i_flgs & F_FILE) != 0) {
			if (io->i_offset - off + size >= io->i_ino.i_size)
				io->i_cc = diff + off;
			io->i_cc -= off;
		}
		p = &io->i_buf[off];
	}
	io->i_cc--;
	io->i_offset++;
	c = (unsigned)*p++;
	io->i_ma = p;
	return (c);
}

D 2
/* does this port?
getw(fdesc)
	int fdesc;
{
	register w,i;
	int val;

	for (i = 0, val = 0; i < sizeof(val); i++) {
		w = getc(fdesc);
		if (w < 0) {
			if (i == 0)
				return (-1);
			else
				return (val);
		}
		val = (val << 8) | (w & 0xff);
	}
	return (val);
}
*/
E 2
int	errno;

read(fdesc, buf, count)
	int fdesc, count;
	char *buf;
{
D 2
	register i;
E 2
I 2
	register i, size;
E 2
	register struct iob *file;
I 2
	register struct fs *fs;
	int lbn, off;
E 2

	errno = 0;
D 2
	if (fdesc >= 0 && fdesc <= 2) {
E 2
I 2
	if (fdesc >= 0 & fdesc <= 2) {
E 2
		i = count;
		do {
			*buf = getchar();
		} while (--i && *buf++ != '\n');
		return (count - i);
	}
	fdesc -= 3;
	if (fdesc < 0 || fdesc >= NFILES ||
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
	if ((file->i_flgs&F_READ) == 0) {
		errno = EBADF;
		return (-1);
	}
I 2
#ifndef	SMALL
E 2
	if ((file->i_flgs & F_FILE) == 0) {
		file->i_cc = count;
		file->i_ma = buf;
		file->i_bn = file->i_boff + (file->i_offset / DEV_BSIZE);
		i = devread(file);
D 2
		file->i_offset += count;
E 2
		if (i < 0)
			errno = file->i_error;
I 2
		else
			file->i_offset += i;
E 2
		return (i);
D 2
	} else {
		if (file->i_offset+count > file->i_ino.i_size)
			count = file->i_ino.i_size - file->i_offset;
		if ((i = count) <= 0)
			return (0);
		do {
			*buf++ = getc(fdesc+3);
		} while (--i);
		return (count);
E 2
	}
I 2
#endif SMALL
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
E 2
}

I 2
#ifndef	SMALL
E 2
write(fdesc, buf, count)
	int fdesc, count;
	char *buf;
{
	register i;
	register struct iob *file;

	errno = 0;
	if (fdesc >= 0 && fdesc <= 2) {
		i = count;
		while (i--)
			putchar(*buf++);
		return (count);
	}
	fdesc -= 3;
	if (fdesc < 0 || fdesc >= NFILES ||
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
	if ((file->i_flgs&F_WRITE) == 0) {
		errno = EBADF;
		return (-1);
	}
	file->i_cc = count;
	file->i_ma = buf;
	file->i_bn = file->i_boff + (file->i_offset / DEV_BSIZE);
	i = devwrite(file);
	file->i_offset += count;
	if (i < 0)
		errno = file->i_error;
	return (i);
}
I 2
#endif SMALL
E 2

int	openfirst = 1;
I 2
D 3
#ifdef notyet
int	opendev;	/* last device opened; for boot to set bootdev */
extern	int bootdev;
#endif notyet
E 3
I 3
unsigned opendev;		/* last device opened */
extern	unsigned bootdev;
E 3
E 2

open(str, how)
	char *str;
	int how;
{
	register char *cp;
D 3
	int i;
E 3
I 3
	register int i;
E 3
	register struct iob *file;
D 3
	register struct devsw *dp;
E 3
	int fdesc;
	long atol();

	if (openfirst) {
		for (i = 0; i < NFILES; i++)
			iob[i].i_flgs = 0;
		openfirst = 0;
	}

	for (fdesc = 0; fdesc < NFILES; fdesc++)
		if (iob[fdesc].i_flgs == 0)
			goto gotfile;
	_stop("No more file slots");
gotfile:
	(file = &iob[fdesc])->i_flgs |= F_ALLOC;

I 2
D 3
#ifdef notyet
	for (cp = str; *cp && *cp != '/' && *cp != ':'; cp++)
			;
	if (*cp != ':') {
E 3
I 3
	for (cp = str; *cp && *cp != '/' && *cp != ':' && *cp != '('; cp++)
		;
	if (*cp == '(') {
		if ((file->i_ino.i_dev = getdev(str, cp - str)) == -1)
			goto bad;
		cp++;
		if ((file->i_unit = getunit(cp)) == -1)
			goto bad;
		for (; *cp != ','; cp++)
			if (*cp == NULL) {
				errno = EOFFSET;
				goto badspec;
			}
		file->i_boff = atol(++cp);
		for (;;) {
			if (*cp == ')')
				break;
			if (*cp++)
				continue;
			goto badspec;
		}
		cp++;
	} else if (*cp != ':') {
E 3
		/* default bootstrap unit and device */
D 3
		file->i_ino.i_dev = bootdev;
E 3
I 3
		file->i_ino.i_dev = (bootdev >> B_TYPESHIFT) & B_TYPEMASK;
		file->i_unit = ((bootdev >> B_UNITSHIFT) & B_UNITMASK) +
		     (8 * ((bootdev >> B_ADAPTORSHIFT) & B_ADAPTORMASK));
		file->i_boff = (bootdev >> B_PARTITIONSHIFT) & B_PARTITIONMASK;
E 3
		cp = str;
	} else {
# define isdigit(n)	((n>='0') && (n<='9'))
I 3
		if (cp == str)
			goto badspec;
E 3
		/*
	 	 * syntax for possible device name:
	 	 *	<alpha-string><digit-string><letter>:
	 	 */
		for (cp = str; *cp != ':' && !isdigit(*cp); cp++)
			;
D 3
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

E 3
I 3
		if ((file->i_ino.i_dev = getdev(str, cp - str)) == -1)
			goto bad;
		if ((file->i_unit = getunit(cp)) == -1)
			goto bad;
		while (isdigit(*cp))
			cp++;
		file->i_boff = 0;
		if (*cp >= 'a' && *cp <= 'h')
			file->i_boff = *cp++ - 'a';
E 3
		if (*cp++ != ':') {
D 3
			printf("incorrect device specification\n");
			file->i_flgs = 0;
E 3
			errno = EOFFSET;
D 3
			return (-1);
E 3
I 3
			goto badspec;
E 3
		}
D 3
		opendev = file->i_ino.i_dev = makedev(dp-devsw, i);
E 3
	}
D 3
	file->i_boff = 0;
	devopen(file);
E 3
I 3
	opendev = file->i_ino.i_dev << B_TYPESHIFT;
	opendev |= ((file->i_unit % 8) << B_UNITSHIFT);
	opendev |= ((file->i_unit / 8) << B_ADAPTORSHIFT);
	opendev |= file->i_boff << B_PARTITIONSHIFT;
	opendev |= B_DEVMAGIC;
	if (errno = devopen(file))
		goto bad;
E 3
	if (cp != str && *cp == '\0') {
		file->i_flgs |= how+1;
		file->i_cc = 0;
		file->i_offset = 0;
		return (fdesc+3);
	}
D 3
#else notyet
E 2
	for (cp = str; *cp && *cp != '('; cp++)
			;
	if (*cp != '(') {
		printf("Bad device\n");
		file->i_flgs = 0;
		errno = EDEV;
		return (-1);
	}
	*cp++ = '\0';
	for (dp = devsw; dp->dv_name; dp++) {
		if (!strcmp(str, dp->dv_name))
			goto gotdev;
	}
	printf("Unknown device\n");
	file->i_flgs = 0;
	errno = ENXIO;
	return (-1);
gotdev:
	*(cp-1) = '(';
	file->i_ino.i_dev = dp-devsw;
	file->i_unit = *cp++ - '0';
	if (*cp >= '0' && *cp <= '9')
		file->i_unit = file->i_unit * 10 + *cp++ - '0';
	if (file->i_unit < 0 || file->i_unit > 63) {
		printf("Bad unit specifier\n");
		file->i_flgs = 0;
		errno = EUNIT;
		return (-1);
	}
	if (*cp++ != ',') {
badoff:
		printf("Missing offset specification\n");
		file->i_flgs = 0;
		errno = EOFFSET;
		return (-1);
	}
	file->i_boff = atol(cp);
	for (;;) {
		if (*cp == ')')
			break;
		if (*cp++)
			continue;
		goto badoff;
	}
	file->i_flgs |= how+1;
	devopen(file);
	if (*++cp == '\0') {
		file->i_cc = 0;
		file->i_offset = 0;
		return (fdesc+3);
	}
I 2
#endif notyet
E 3
E 2
	file->i_ma = (char *)(&file->i_fs);
	file->i_cc = SBSIZE;
D 3
	file->i_bn = SBLOCK + file->i_boff;
E 3
I 3
	file->i_bn = SBOFF / DEV_BSIZE + file->i_boff;
E 3
	file->i_offset = 0;
	if (devread(file) < 0) {
		errno = file->i_error;
		printf("super block read error\n");
D 2
		file->i_flgs = 0;
E 2
D 3
		return (-1);
E 3
I 3
		goto bad;
E 3
	}
	if ((i = find(cp, file)) == 0) {
D 3
		file->i_flgs = 0;
E 3
		errno = ESRCH;
D 3
		return (-1);
E 3
I 3
		goto bad;
E 3
	}
I 2
#ifndef	SMALL
E 2
	if (how != 0) {
		printf("Can't write files yet.. Sorry\n");
D 3
		file->i_flgs = 0;
E 3
		errno = EIO;
D 3
		return (-1);
E 3
I 3
		goto bad;
E 3
	}
I 2
#endif SMALL
E 2
	if (openi(i, file) < 0) {
		errno = file->i_error;
D 2
		file->i_flgs = 0;
E 2
D 3
		return (-1);
E 3
I 3
		goto bad;
E 3
	}
	file->i_offset = 0;
	file->i_cc = 0;
D 2
	file->i_flgs |= F_FILE | (how+1);
E 2
I 2
D 3
	file->i_flgs |= F_FILE;
E 3
I 3
	file->i_flgs |= F_FILE | (how+1);
E 3
E 2
	return (fdesc+3);
I 3

badspec:
	printf("malformed device specification\n");
bad:
	file->i_flgs = 0;
	return (-1);
}

static
getdev(str, len)
	char *str;
	int len;
{
	register struct devsw *dp;

	for (dp = devsw; dp->dv_name; dp++) {
		if (!strncmp(str, dp->dv_name, len))
			return (dp - devsw);
	}
	printf("Unknown device\n");
	errno = ENXIO;
	return (-1);
}

static
getunit(cp)
	register char *cp;
{
	register int i = 0;

	while (*cp >= '0' && *cp <= '9')
		i = i * 10 + *cp++ - '0';
	if ((unsigned) i > 255) {
		printf("minor device number out of range (0-255)\n");
		errno = EUNIT;
		i = -1;
	}
	return (i);
E 3
}

close(fdesc)
	int fdesc;
{
	struct iob *file;

	fdesc -= 3;
	if (fdesc < 0 || fdesc >= NFILES ||
	    ((file = &iob[fdesc])->i_flgs&F_ALLOC) == 0) {
		errno = EBADF;
		return (-1);
	}
	if ((file->i_flgs&F_FILE) == 0)
		devclose(file);
	file->i_flgs = 0;
	return (0);
}

I 2
#ifndef	SMALL
ioctl(fdesc, cmd, arg)
	int fdesc, cmd;
	char *arg;
{
	register struct iob *file;
	int error = 0;
E 2

I 2
	fdesc -= 3;
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
		break;

	case SAIONOBAD:
		file->i_flgs |= F_NBSF;
		break;

	case SAIODOBAD:
		file->i_flgs &= ~F_NBSF;
		break;

	default:
		error = devioctl(file, cmd, arg);
		break;
	}
	if (error < 0)
		errno = file->i_error;
	return (error);
}
#endif SMALL

E 2
exit()
{
	_stop("Exit called");
}

_stop(s)
	char *s;
{
	int i;

	for (i = 0; i < NFILES; i++)
		if (iob[i].i_flgs != 0)
			close(i);
	printf("%s\n", s);
	_rtt();
}
D 4

I 2
#ifdef tahoe
E 2
trap(ps)
	int ps;
{
	printf("Trap %o\n", ps);
	for (;;)
		;
}

uncache (addr)
	char *addr;
{
	/* Return *(addr-0x4000); DIRTY assumes this address is valid */
	mtpr(PDCS, addr);
}
I 2
#endif
E 4
E 2
E 1
