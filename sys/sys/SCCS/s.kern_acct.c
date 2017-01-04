h65393
s 00001/00001/00166
d D 7.2 86/11/25 13:58:30 karels 12 11
c race if unlinking acct file
e
s 00001/00001/00166
d D 7.1 86/06/05 00:01:20 mckusick 11 10
c 4.3BSD release version
e
s 00003/00003/00164
d D 6.9 86/02/20 15:58:16 karels 10 9
c cleanups from Sam: format, spl's, ptrace defs
e
s 00007/00001/00160
d D 6.8 85/06/08 14:34:31 mckusick 9 8
c Add copyright
e
s 00005/00000/00156
d D 6.7 85/05/21 15:25:35 mckusick 8 7
c must not enable accounting on read-only file systems
e
s 00002/00002/00154
d D 6.6 84/12/12 09:18:53 karels 7 6
c use AHZ instead of 1<<6.
e
s 00009/00009/00147
d D 6.5 84/08/29 20:18:44 bloom 6 5
c Change to includes.  no more ../h
e
s 00001/00001/00155
d D 6.4 84/07/15 11:53:56 karels 5 4
c typo in memory average calculation
e
s 00022/00010/00134
d D 6.3 84/07/14 14:45:35 sam 4 3
c correct accounting system: report times in 64ths of a second; 
c calculate average memory usage correctly (and returned in units of the 
c software page size so that sa can use getpagesize to figure out kilobytes)
e
s 00005/00002/00139
d D 6.2 84/07/08 16:18:07 mckusick 3 2
c rework `namei' interface to eliminate global variables
e
s 00000/00000/00141
d D 6.1 83/07/29 06:32:11 sam 2 1
c 4.2 distribution
e
s 00141/00000/00000
d D 4.1 83/05/27 14:02:40 sam 1 0
c date and time created 83/05/27 14:02:40 by sam
e
u
U
t
T
I 1
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 11
 * Copyright (c) 1982 Regents of the University of California.
E 11
I 11
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9

D 6
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/inode.h"
#include "../h/fs.h"
#include "../h/kernel.h"
#include "../h/acct.h"
D 3
#include "../h/nami.h"
E 3
#include "../h/uio.h"
E 6
I 6
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "inode.h"
#include "fs.h"
#include "kernel.h"
#include "acct.h"
#include "uio.h"
E 6

/*
 * SHOULD REPLACE THIS WITH A DRIVER THAT CAN BE READ TO SIMPLIFY.
 */
struct	inode *acctp;
struct	inode *savacctp;

/*
 * Perform process accounting functions.
 */
sysacct()
{
	register struct inode *ip;
	register struct a {
		char	*fname;
	} *uap = (struct a *)u.u_ap;
I 3
	register struct nameidata *ndp = &u.u_nd;
E 3

	if (suser()) {
		if (savacctp) {
			acctp = savacctp;
			savacctp = NULL;
		}
		if (uap->fname==NULL) {
			if (ip = acctp) {
D 12
				irele(ip);
E 12
				acctp = NULL;
I 12
				irele(ip);
E 12
			}
			return;
		}
D 3
		ip = namei(uchar, LOOKUP, 1);
E 3
I 3
		ndp->ni_nameiop = LOOKUP | FOLLOW;
		ndp->ni_segflg = UIO_USERSPACE;
		ndp->ni_dirp = uap->fname;
		ip = namei(ndp);
E 3
D 10
		if(ip == NULL)
E 10
I 10
		if (ip == NULL)
E 10
			return;
D 10
		if((ip->i_mode & IFMT) != IFREG) {
E 10
I 10
		if ((ip->i_mode&IFMT) != IFREG) {
E 10
			u.u_error = EACCES;
			iput(ip);
			return;
		}
I 8
		if (ip->i_fs->fs_ronly) {
			u.u_error = EROFS;
			iput(ip);
			return;
		}
E 8
		if (acctp && (acctp->i_number != ip->i_number ||
		    acctp->i_dev != ip->i_dev))
			irele(acctp);
		acctp = ip;
		iunlock(ip);
	}
}

int	acctsuspend = 2;	/* stop accounting when < 2% free space left */
int	acctresume = 4;		/* resume when free space risen to > 4% */

struct	acct acctbuf;
/*
 * On exit, write a record on the accounting file.
 */
acct()
{
	register int i;
	register struct inode *ip;
	register struct fs *fs;
I 4
	register struct rusage *ru;
E 4
	off_t siz;
I 4
	struct timeval t;
E 4
	register struct acct *ap = &acctbuf;

	if (savacctp) {
		fs = savacctp->i_fs;
		if (freespace(fs, fs->fs_minfree + acctresume) > 0) {
			acctp = savacctp;
			savacctp = NULL;
			printf("Accounting resumed\n");
		}
	}
	if ((ip = acctp) == NULL)
		return;
	fs = acctp->i_fs;
	if (freespace(fs, fs->fs_minfree + acctsuspend) <= 0) {
		savacctp = acctp;
		acctp = NULL;
		printf("Accounting suspended\n");
		return;
	}
	ilock(ip);
	for (i = 0; i < sizeof (ap->ac_comm); i++)
		ap->ac_comm[i] = u.u_comm[i];
D 4
	ap->ac_utime = compress((long)u.u_ru.ru_utime.tv_sec);
	ap->ac_stime = compress((long)u.u_ru.ru_stime.tv_sec);
	ap->ac_etime = compress((long)time.tv_sec - u.u_start);
	ap->ac_btime = u.u_start;
E 4
I 4
	ru = &u.u_ru;
	ap->ac_utime = compress(ru->ru_utime.tv_sec, ru->ru_utime.tv_usec);
	ap->ac_stime = compress(ru->ru_stime.tv_sec, ru->ru_stime.tv_usec);
	t = time;
	timevalsub(&t, &u.u_start);
	ap->ac_etime = compress(t.tv_sec, t.tv_usec);
	ap->ac_btime = u.u_start.tv_sec;
E 4
	ap->ac_uid = u.u_ruid;
	ap->ac_gid = u.u_rgid;
D 4
	ap->ac_mem = 0;
	if (i = u.u_ru.ru_utime.tv_sec + u.u_ru.ru_stime.tv_sec)
		ap->ac_mem =
		    (u.u_ru.ru_ixrss + u.u_ru.ru_idrss + u.u_ru.ru_isrss) / i;
	ap->ac_io = compress((long)(u.u_ru.ru_inblock + u.u_ru.ru_oublock));
E 4
I 4
	t = ru->ru_stime;
	timevaladd(&t, &ru->ru_utime);
D 5
	if (i = t.tv_sec / hz + t.tv_usec / tick)
E 5
I 5
	if (i = t.tv_sec * hz + t.tv_usec / tick)
E 5
		ap->ac_mem = (ru->ru_ixrss+ru->ru_idrss+ru->ru_isrss) / i;
	else
		ap->ac_mem = 0;
	ap->ac_mem >>= CLSIZELOG2;
D 10
	ap->ac_io = compress(ru->ru_inblock + ru->ru_oublock, 0);
E 10
I 10
	ap->ac_io = compress(ru->ru_inblock + ru->ru_oublock, (long)0);
E 10
E 4
	if (u.u_ttyp)
		ap->ac_tty = u.u_ttyd;
	else
		ap->ac_tty = NODEV;
	ap->ac_flag = u.u_acflag;
	siz = ip->i_size;
	u.u_error = 0;				/* XXX */
	u.u_error =
	    rdwri(UIO_WRITE, ip, (caddr_t)ap, sizeof (acctbuf), siz,
		1, (int *)0);
	if (u.u_error)
		itrunc(ip, (u_long)siz);
	iunlock(ip);
}

/*
 * Produce a pseudo-floating point representation
 * with 3 bits base-8 exponent, 13 bits fraction.
 */
D 4
compress(t)
E 4
I 4
compress(t, ut)
E 4
	register long t;
I 4
	long ut;
E 4
{
	register exp = 0, round = 0;

I 4
D 7
	t <<= 6;
E 7
I 7
	t = t * AHZ;  /* compiler will convert only this format to a shift */
E 7
	if (ut)
D 7
		t += ut / (1000000 / (1<<6));
E 7
I 7
		t += ut / (1000000 / AHZ);
E 7
E 4
	while (t >= 8192) {
		exp++;
		round = t&04;
		t >>= 3;
	}
	if (round) {
		t++;
		if (t >= 8192) {
			t >>= 3;
			exp++;
		}
	}
	return ((exp<<13) + t);
}
E 1
