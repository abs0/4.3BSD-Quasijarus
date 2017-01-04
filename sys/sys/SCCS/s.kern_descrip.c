h45873
s 00001/00001/00412
d D 7.1 86/06/05 00:02:01 mckusick 40 39
c 4.3BSD release version
e
s 00001/00001/00412
d D 6.13 86/05/15 09:42:27 karels 39 38
c correct no-such-process error
e
s 00000/00007/00413
d D 6.12 85/12/19 14:42:50 karels 38 37
c move unp_gc call to unp_detach
e
s 00007/00001/00413
d D 6.11 85/06/08 14:35:17 mckusick 37 36
c Add copyright
e
s 00012/00006/00402
d D 6.10 85/05/27 19:53:45 karels 36 35
c implement high-water mark on file descriptors in use
e
s 00000/00001/00408
d D 6.9 85/03/19 20:47:56 mckusick 35 34
c eliminate extraneous include of conf.h
e
s 00004/00001/00405
d D 6.8 85/02/16 15:45:42 karels 34 33
c satisfy ino_lock's assumptions
e
s 00003/00003/00403
d D 6.7 84/11/27 17:06:09 karels 33 32
c no close-on-exec for new fd after dup/dup2/fcntl(DUPFD)
e
s 00004/00003/00402
d D 6.6 84/11/27 16:27:07 karels 32 31
c off-by-one in fcntl-DUPFD; avoid panic on flock(f,0) if holding shared
c lock; don't fail when changing lock types without blocking if we hold the only
c lock
e
s 00014/00014/00391
d D 6.5 84/08/29 20:19:04 bloom 31 30
c Change to includes.  no more ../h
e
s 00006/00018/00399
d D 6.4 84/08/22 16:56:47 mckusick 30 29
c use GETF macro where appropriate
e
s 00002/00002/00415
d D 6.3 83/11/18 10:04:30 karels 29 28
c Zero file f_count exactly once (in closef only);
c catch interrupted device close routines so ino_close always returns
c to closef
e
s 00009/00009/00408
d D 6.2 83/09/25 12:26:54 karels 28 27
c manifest constants '5' and '6' were backwards
e
s 00000/00000/00417
d D 6.1 83/07/29 06:32:36 sam 27 26
c 4.2 distribution
e
s 00014/00061/00403
d D 5.26 83/06/14 01:36:50 sam 26 25
c revamp locking to be done at the file table level
e
s 00108/00006/00356
d D 5.25 83/06/12 14:29:54 sam 25 24
c cleanup locking a bit; fix problem with close not unlocking
e
s 00147/00321/00215
d D 5.24 83/05/27 12:46:13 sam 24 23
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00000/00002/00536
d D 5.23 83/01/17 16:16:52 sam 23 22
c sun mods
e
s 00004/00007/00534
d D 5.22 83/01/12 15:38:52 sam 22 21
c race condition: pty input arrives at spl0 and results in 
c ttwakeup call -> selwakeup; if any thing else arrives as input, the 
c call to setrun can be interrupted by another setrun call and setrun will 
c then panic
e
s 00016/00018/00525
d D 5.21 82/12/28 23:45:58 sam 21 20
c copyin & copyout now return EFAULT and all callers uniformly 
c return (or ignore) this value
e
s 00000/00002/00543
d D 5.20 82/12/17 11:43:30 sam 20 19
c sun merge
e
s 00005/00005/00540
d D 5.19 82/12/09 19:01:20 sam 19 18
c u.u_pofile flags are now UF_*
e
s 00007/00007/00538
d D 5.18 82/11/13 22:49:39 sam 18 17
c merge of 4.1b and 4.1c
e
s 00008/00000/00537
d D 5.17 82/10/30 20:48:12 root 17 16
c first version with 68k stuff
e
s 00003/00005/00534
d D 5.16 82/10/23 16:39:10 root 16 15
c bug fixes and more forgiveness in select()
e
s 00008/00011/00531
d D 5.15 82/10/22 00:01:35 root 15 14
c fixes to select
e
s 00001/00002/00541
d D 5.14 82/10/20 01:09:42 root 14 13
c lint
e
s 00003/00003/00540
d D 5.13 82/10/17 21:48:34 root 13 12
c more lint
e
s 00001/00001/00542
d D 5.12 82/10/17 14:04:32 root 12 11
c fix lint
e
s 00000/00001/00543
d D 5.11 82/10/10 15:02:07 root 11 10
c split header files over to vax directories
e
s 00035/00010/00509
d D 5.10 82/09/11 13:12:25 root 10 9
c working select()
e
s 00007/00000/00512
d D 5.9 82/09/08 08:07:26 root 9 8
c opause not here
e
s 00104/00073/00408
d D 5.8 82/09/08 07:58:28 root 8 7
c first attempt at a new select
e
s 00036/00043/00445
d D 5.7 82/09/06 22:38:59 root 7 6
c more work on timer stuff
e
s 00044/00049/00444
d D 5.6 82/09/04 09:07:39 root 6 5
c new clock style; select not tested
e
s 00004/00000/00489
d D 5.5 82/08/22 20:30:37 root 5 4
c lint
e
s 00030/00087/00459
d D 5.4 82/08/10 17:41:14 sam 4 3
c file locking
e
s 00000/00012/00546
d D 5.3 82/08/03 14:03:59 sam 3 2
c purge EFS stuff
e
s 00370/00047/00188
d D 5.2 82/07/24 18:09:01 root 2 1
c merge with calder
e
s 00235/00000/00000
d D 5.1 82/07/15 20:13:31 root 1 0
c date and time created 82/07/15 20:13:31 by root
e
u
U
t
T
I 1
D 37
/*	%M%	%I%	%E%	*/
E 37
I 37
/*
D 40
 * Copyright (c) 1982 Regents of the University of California.
E 40
I 40
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 40
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 37

D 31
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
I 6
#include "../h/kernel.h"
E 6
D 2
#include "../h/reg.h"
E 2
#include "../h/inode.h"
#include "../h/proc.h"
D 2
#include "../h/clock.h"
#include "../h/mtpr.h"
#include "../h/timeb.h"
#include "../h/times.h"
#include "../h/reboot.h"
#include "../h/fs.h"
E 2
#include "../h/conf.h"
D 2
#include "../h/buf.h"
#include "../h/mount.h"
E 2
#include "../h/file.h"
D 11
#include "../h/inline.h"
E 11
#include "../h/socket.h"
#include "../h/socketvar.h"
I 2
#include "../h/mount.h"
I 25
#include "../h/stat.h"
E 31
I 31
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "kernel.h"
#include "inode.h"
#include "proc.h"
D 35
#include "conf.h"
E 35
#include "file.h"
#include "socket.h"
#include "socketvar.h"
#include "mount.h"
#include "stat.h"
E 31
E 25
E 2

I 2
D 24
#include "../h/descrip.h"
E 24
I 24
D 31
#include "../h/ioctl.h"
E 31
I 31
#include "ioctl.h"
E 31
E 24

E 2
/*
D 2
 * the dup system call.
E 2
I 2
 * Descriptor management.
E 2
 */
I 2

/*
 * TODO:
D 24
 *	getf should be renamed
 *	ufalloc side effects are gross
E 24
I 24
D 36
 *	increase NOFILE
E 36
 *	eliminate u.u_error side effects
E 24
 */

/*
 * System calls on descriptors.
 */
D 6
dstd()
E 6
I 6
getdtablesize()
E 6
{

	u.u_r.r_val1 = NOFILE;
}

I 7
D 24
getdprop()
{
	register struct a {
		int	d;
		struct	dtype *dtypeb;
	} *uap = (struct a *)u.u_ap;
	register struct file *fp;
	struct dtype adtype;

	fp = getf(uap->d);
	if (fp == 0)
		return;
	adtype.dt_type = 0;		/* XXX */
	adtype.dt_protocol = 0;		/* XXX */
D 21
	if (copyout((caddr_t)&adtype, (caddr_t)uap->dtypeb,
	    sizeof (struct dtype)) < 0) {
		u.u_error = EFAULT;
E 21
I 21
	u.u_error = copyout((caddr_t)&adtype, (caddr_t)uap->dtypeb,
	    sizeof (struct dtype)); 
	if (u.u_error)
E 21
		return;
D 21
	}
E 21
}

E 24
getdopt()
{

}

setdopt()
{

}

E 7
E 2
dup()
{
I 2
	register struct a {
		int	i;
	} *uap = (struct a *) u.u_ap;
E 2
D 4
	register struct file *fp;
I 2
	register int j;
E 4
I 4
	struct file *fp;
	int j;
E 4

	if (uap->i &~ 077) { uap->i &= 077; dup2(); return; }	/* XXX */

D 30
	fp = getf(uap->i);
	if (fp == 0)
		return;
E 30
I 30
	GETF(fp, uap->i);
E 30
D 24
	j = ufalloc();
E 24
I 24
	j = ufalloc(0);
E 24
	if (j < 0)
		return;
D 4
	u.u_ofile[j] = fp;
	fp->f_count++;
E 4
I 4
D 18
	dupit(j, fp, u.u_pofile[uap->i] & (RDLOCK|WRLOCK));
E 18
I 18
D 19
	dupit(j, fp, u.u_pofile[uap->i] & (SHLOCK|EXLOCK));
E 19
I 19
D 24
	dupit(j, fp, u.u_pofile[uap->i] & (UF_SHLOCK|UF_EXLOCK));
E 24
I 24
D 33
	dupit(j, fp, u.u_pofile[uap->i]);
E 33
I 33
	dupit(j, fp, u.u_pofile[uap->i] &~ UF_EXCLOSE);
E 33
E 24
E 19
E 18
E 4
}

dup2()
{
E 2
	register struct a {
D 2
		int	fdes;
		int	fdes2;
	} *uap;
	register i, m;
E 2
I 2
		int	i, j;
	} *uap = (struct a *) u.u_ap;
	register struct file *fp;
E 2

D 2
	uap = (struct a *)u.u_ap;
	m = uap->fdes & ~077;
	uap->fdes &= 077;
	fp = getf(uap->fdes);
	if (fp == NULL)
E 2
I 2
D 30
	fp = getf(uap->i);
	if (fp == 0)
E 2
		return;
E 30
I 30
	GETF(fp, uap->i);
E 30
D 2
	if ((m&0100) == 0) {
		if ((i = ufalloc()) < 0)
			return;
	} else {
		i = uap->fdes2;
		if (i<0 || i>=NOFILE) {
			u.u_error = EBADF;
			return;
		}
		u.u_r.r_val1 = i;
E 2
I 2
	if (uap->j < 0 || uap->j >= NOFILE) {
		u.u_error = EBADF;
		return;
E 2
	}
D 2
	if (i != uap->fdes) {
		if (u.u_ofile[i]!=NULL)
			closef(u.u_ofile[i], 0);
E 2
I 2
	u.u_r.r_val1 = uap->j;
	if (uap->i == uap->j)
		return;
	if (u.u_ofile[uap->j]) {
I 17
D 20
#ifdef SUNMMAP
E 20
		if (u.u_pofile[uap->j] & UF_MAPPED)
			munmapfd(uap->j);
D 20
#endif
E 20
E 17
D 4
		closef(u.u_ofile[uap->j], 0);
E 4
I 4
D 24
		closef(u.u_ofile[uap->j], 0, u.u_pofile[uap->j]);
E 24
I 24
D 26
		closef(u.u_ofile[uap->j], u.u_pofile[uap->j]);
E 26
I 26
		closef(u.u_ofile[uap->j]);
E 26
E 24
E 4
E 2
		if (u.u_error)
			return;
D 2
		u.u_ofile[i] = fp;
		fp->f_count++;
E 2
I 2
D 26
		/* u.u_ofile[uap->j] = 0; */
I 4
		/* u.u_pofile[uap->j] = 0; */
E 26
E 4
E 2
	}
I 2
D 4
	u.u_ofile[uap->j] = fp;
E 4
I 4
D 18
	dupit(uap->j, fp, u.u_pofile[uap->i] & (RDLOCK|WRLOCK));
E 18
I 18
D 19
	dupit(uap->j, fp, u.u_pofile[uap->i] & (SHLOCK|EXLOCK));
E 19
I 19
D 24
	dupit(uap->j, fp, u.u_pofile[uap->i] & (UF_SHLOCK|UF_EXLOCK));
E 24
I 24
D 33
	dupit(uap->j, fp, u.u_pofile[uap->i]);
E 33
I 33
	dupit(uap->j, fp, u.u_pofile[uap->i] &~ UF_EXCLOSE);
E 33
E 24
E 19
E 18
}

D 26
dupit(fd, fp, lockflags)
E 26
I 26
dupit(fd, fp, flags)
E 26
	int fd;
	register struct file *fp;
D 26
	register int lockflags;
E 26
I 26
	register int flags;
E 26
{

	u.u_ofile[fd] = fp;
D 26
	u.u_pofile[fd] = lockflags;
E 26
I 26
	u.u_pofile[fd] = flags;
E 26
E 4
	fp->f_count++;
I 36
	if (fd > u.u_lastfile)
		u.u_lastfile = fd;
E 36
I 24
D 26
/* THIS DOESN'T BELONG HERE */
E 24
I 4
D 18
	if (lockflags&RDLOCK)
		fp->f_inode->i_rdlockc++;
	if (lockflags&WRLOCK)
		fp->f_inode->i_wrlockc++;
E 18
I 18
D 19
	if (lockflags&SHLOCK)
E 19
I 19
	if (lockflags&UF_SHLOCK)
E 19
D 24
		fp->f_inode->i_shlockc++;
E 24
I 24
		((struct inode *)fp->f_data)->i_shlockc++;
E 24
D 19
	if (lockflags&EXLOCK)
E 19
I 19
	if (lockflags&UF_EXLOCK)
E 19
D 24
		fp->f_inode->i_exlockc++;
E 24
I 24
		((struct inode *)fp->f_data)->i_exlockc++;
/* END DOESN'T BELONG */
E 26
E 24
E 18
E 4
E 2
}

I 2
D 24
close()
E 24
I 24
/*
 * The file control system call.
 */
fcntl()
E 24
{
D 24
	register struct a {
		int	i;
	} *uap = (struct a *)u.u_ap;
E 24
	register struct file *fp;
D 24

	fp = getf(uap->i);
	if (fp == 0)
		return;
I 17
D 23
#ifdef SUNMMAP
E 23
	if (u.u_pofile[uap->i] & UF_MAPPED)
		munmapfd(uap->i);
D 23
#endif
E 23
E 17
D 4
	u.u_ofile[uap->i] = 0;
	closef(fp, 0);
E 4
I 4
	closef(fp, 0, u.u_pofile[uap->i]);
E 4
	/* WHAT IF u.u_error ? */
I 4
	u.u_ofile[uap->i] = NULL;
	u.u_pofile[uap->i] = 0;
E 4
}

D 6
dtype()
E 6
I 6
D 7
getdprop()
E 6
{
	register struct a {
		int	d;
		struct	dtype *dtypeb;
	} *uap = (struct a *)u.u_ap;
	register struct file *fp;
	struct dtype adtype;

	fp = getf(uap->d);
	if (fp == 0)
		return;
	adtype.dt_type = 0;		/* XXX */
	adtype.dt_protocol = 0;		/* XXX */
	if (copyout((caddr_t)&adtype, (caddr_t)uap->dtypeb,
	    sizeof (struct dtype)) < 0) {
		u.u_error = EFAULT;
		return;
	}
}

E 7
D 6
dwrap()
E 6
I 6
wrap()
E 6
{
E 24
	register struct a {
D 24
		int	d;
		struct	dtype *dtypeb;
	} *uap = (struct a *)u.u_ap;
	register struct file *fp;
	struct dtype adtype;
E 24
I 24
		int	fdes;
		int	cmd;
		int	arg;
	} *uap;
	register i;
	register char *pop;
E 24

D 24
	fp = getf(uap->d);
	if (fp == 0)
E 24
I 24
	uap = (struct a *)u.u_ap;
D 30
	fp = getf(uap->fdes);
	if (fp == NULL)
E 24
		return;
E 30
I 30
	GETF(fp, uap->fdes);
E 30
D 21
	if (copyin((caddr_t)uap->dtypeb, (caddr_t)&adtype,
	    sizeof (struct dtype)) < 0) {
		u.u_error = EFAULT;
E 21
I 21
D 24
	u.u_error = copyin((caddr_t)uap->dtypeb, (caddr_t)&adtype,
	    sizeof (struct dtype));
	if (u.u_error)
E 21
		return;
D 21
	}
E 21
	/* DO WRAP */
}
E 24
I 24
	pop = &u.u_pofile[uap->fdes];
	switch(uap->cmd) {
D 28
	case 0:
E 28
I 28
	case F_DUPFD:
E 28
		i = uap->arg;
D 32
		if (i < 0 || i > NOFILE) {
E 32
I 32
		if (i < 0 || i >= NOFILE) {
E 32
			u.u_error = EINVAL;
			return;
		}
		if ((i = ufalloc(i)) < 0)
			return;
D 33
		dupit(i, fp, *pop);
E 33
I 33
		dupit(i, fp, *pop &~ UF_EXCLOSE);
E 33
		break;
E 24

I 8
D 24
int	unselect();
E 8
D 6
dselect()
E 6
I 6
D 7
select()
E 6
{

}

E 7
D 6
dnblock()
{
I 5
#ifdef notdef
E 5
	register struct a {
		int	d;
		int	how;
	} *uap = (struct a *)u.u_ap;

	/* XXX */
I 5
#endif
E 5
}

dsignal()
{
I 5
#ifdef notdef
E 5
	register struct a {
		int	d;
		int	how;
	} *uap = (struct a *)u.u_ap;

	/* XXX */
I 5
#endif
E 5
}

E 6
E 2
int	nselcoll;
/*
 * Select system call.
 */
D 2
select()
E 2
I 2
D 7
oselect()
E 7
I 7
select()
E 7
E 2
{
	register struct uap  {
D 7
		int	nfd;
		fd_set	*rp, *wp;
E 7
I 7
D 8
		fd_set	*rp, *wp, *ep;
E 8
I 8
D 10
		long	*ibits;
		long	*obits;
E 10
I 10
		int	nd;
		long	*in;
		long	*ou;
		long	*ex;
E 10
E 8
E 7
D 6
		int	timo;
	} *ap = (struct uap *)u.u_ap;
E 6
I 6
		struct	timeval *tv;
	} *uap = (struct uap *)u.u_ap;
E 6
D 8
	fd_set rd, wr;
	int nfds = 0, readable = 0, writeable = 0;
D 6
	time_t t = time;
E 6
I 6
	struct timeval atv, origin, now;
E 8
I 8
	int ibits[3], obits[3];
	struct timeval atv;
E 8
E 6
D 12
	int s, tsel, ncoll, rem;
E 12
I 12
	int s, ncoll;
E 12
I 8
	label_t lqsave;
E 24
I 24
D 28
	case 1:
E 28
I 28
	case F_GETFD:
E 28
		u.u_r.r_val1 = *pop & 1;
		break;
E 24
E 8

I 15
D 24
	obits[0] = obits[1] = obits[2] = 0;
E 15
I 10
D 16
	if (uap->nd >= NOFILE) {
		u.u_error = EINVAL;
D 15
		return;
E 15
I 15
		goto done;
E 15
	}
E 16
I 16
	if (uap->nd > NOFILE)
		uap->nd = NOFILE;	/* forgiving, if slightly wrong */
E 24
I 24
D 28
	case 2:
E 28
I 28
	case F_SETFD:
E 28
		*pop = (*pop &~ 1) | (uap->arg & 1);
		break;
E 24
E 16

D 24
#define	getbits(name, x) \
	if (uap->name) { \
D 21
		if (copyin((caddr_t)uap->name, (caddr_t)&ibits[x], \
		    sizeof (ibits[x]))) { \
			u.u_error = EFAULT; \
E 21
I 21
		u.u_error = copyin((caddr_t)uap->name, (caddr_t)&ibits[x], \
		    sizeof (ibits[x])); \
		if (u.u_error) \
E 21
D 15
			return; \
E 15
I 15
			goto done; \
E 15
D 21
		} \
E 21
	} else \
		ibits[x] = 0;
	getbits(in, 0);
	getbits(ou, 1);
	getbits(ex, 2);
#undef	getbits
E 24
I 24
D 28
	case 3:
E 28
I 28
	case F_GETFL:
E 28
		u.u_r.r_val1 = fp->f_flag+FOPEN;
		break;
E 24

E 10
D 6
	if (ap->nfd > NOFILE)
		ap->nfd = NOFILE;
	if (ap->nfd < 0) {
E 6
I 6
D 7
	if (uap->nfd > NOFILE)
		uap->nfd = NOFILE;
	if (uap->nfd < 0) {
E 6
		u.u_error = EBADF;
		return;
	}
E 7
D 6
	if (ap->rp && copyin((caddr_t)ap->rp,(caddr_t)&rd,sizeof(fd_set)))
E 6
I 6
D 24
	if (uap->tv) {
D 21
		if (copyin((caddr_t)uap->tv, (caddr_t)&atv, sizeof (atv))) {
			u.u_error = EFAULT;
E 21
I 21
		u.u_error = copyin((caddr_t)uap->tv, (caddr_t)&atv,
			sizeof (atv));
E 24
I 24
D 28
	case 4:
E 28
I 28
	case F_SETFL:
E 28
		fp->f_flag &= FCNTLCANT;
		fp->f_flag |= (uap->arg-FOPEN) &~ FCNTLCANT;
		u.u_error = fset(fp, FNDELAY, fp->f_flag & FNDELAY);
E 24
		if (u.u_error)
E 21
D 15
			return;
E 15
I 15
D 24
			goto done;
E 15
D 21
		}
E 21
D 8
	} else
		timerclear(&atv);
	if (uap->rp && copyin((caddr_t)uap->rp,(caddr_t)&rd,sizeof(fd_set)))
E 8
I 8
		if (itimerfix(&atv)) {
			u.u_error = EINVAL;
D 15
			return;
E 15
I 15
			goto done;
E 15
		}
		s = spl7(); timevaladd(&atv, &time); splx(s);
	}
D 10
	if (copyin((caddr_t)uap->ibits, (caddr_t)ibits, sizeof (ibits))) {
		u.u_error = EFAULT;
E 8
E 6
		return;
D 6
	if (ap->wp && copyin((caddr_t)ap->wp,(caddr_t)&wr,sizeof(fd_set)))
E 6
I 6
D 8
	if (uap->wp && copyin((caddr_t)uap->wp,(caddr_t)&wr,sizeof(fd_set)))
E 6
		return;
E 8
I 8
	}
E 10
E 8
retry:
I 6
D 8
	s = spl7(); now = time; splx(s);
E 8
E 6
	ncoll = nselcoll;
	u.u_procp->p_flag |= SSEL;
D 6
	if (ap->rp)
		readable = selscan(ap->nfd, rd, &nfds, FREAD);
	if (ap->wp)
		writeable = selscan(ap->nfd, wr, &nfds, FWRITE);
E 6
I 6
D 8
	if (uap->rp)
D 7
		readable = selscan(uap->nfd, rd, &nfds, FREAD);
E 7
I 7
		readable = selscan(rd, &nfds, FREAD);
E 7
	if (uap->wp)
D 7
		writeable = selscan(uap->nfd, wr, &nfds, FWRITE);
E 7
I 7
		writeable = selscan(wr, &nfds, FWRITE);
E 8
I 8
	u.u_r.r_val1 = selscan(ibits, obits);
E 8
E 7
E 6
D 15
	if (u.u_error)
I 8
		return;
	if (u.u_r.r_val1)
E 15
I 15
	if (u.u_error || u.u_r.r_val1)
E 15
E 8
		goto done;
D 8
	if (readable || writeable)
		goto done;
D 6
	rem = (ap->timo+999)/1000 - (time - t);
	if (ap->timo == 0 || rem <= 0)
E 6
I 6
	if (!timerisset(&atv))
E 6
		goto done;
E 8
	s = spl6();
I 8
D 10
	if (uap->tv && timercmp(&atv, &time, >=)) {
E 10
I 10
	if (uap->tv && timercmp(&time, &atv, >=)) {
E 10
		splx(s);
		goto done;
	}
E 8
	if ((u.u_procp->p_flag & SSEL) == 0 || nselcoll != ncoll) {
		u.u_procp->p_flag &= ~SSEL;
		splx(s);
		goto retry;
	}
	u.u_procp->p_flag &= ~SSEL;
D 6
	tsel = tsleep((caddr_t)&selwait, PZERO+1, rem);
E 6
I 6
D 8
	tsel = tsleep((caddr_t)&selwait, PZERO+1, &atv);
E 8
I 8
	if (uap->tv) {
		lqsave = u.u_qsave;
		if (setjmp(&u.u_qsave)) {
D 13
			untimeout(unselect, u.u_procp);
E 13
I 13
			untimeout(unselect, (caddr_t)u.u_procp);
E 13
			u.u_error = EINTR;
			splx(s);
D 15
			return;
E 15
I 15
			goto done;
E 15
		}
D 13
		timeout(unselect, u.u_procp, hzto(&atv));
E 13
I 13
		timeout(unselect, (caddr_t)u.u_procp, hzto(&atv));
E 13
	}
	sleep((caddr_t)&selwait, PZERO+1);
	if (uap->tv) {
		u.u_qsave = lqsave;
D 13
		untimeout(unselect, u.u_procp);
E 13
I 13
		untimeout(unselect, (caddr_t)u.u_procp);
E 13
	}
E 8
E 6
	splx(s);
D 8
	switch (tsel) {
E 8
I 8
	goto retry;
done:
D 10
	if (copyout((caddr_t)obits, (caddr_t)uap->obits, sizeof (obits))) {
		u.u_error = EFAULT;
		return;
E 10
I 10
#define	putbits(name, x) \
	if (uap->name) { \
D 16
		if (copyout((caddr_t)obits[x], (caddr_t)uap->name, \
E 16
I 16
D 21
		if (copyout((caddr_t)&obits[x], (caddr_t)uap->name, \
E 16
D 15
		    sizeof (obits[x]))) { \
E 15
I 15
		    sizeof (obits[x]))) \
E 15
			u.u_error = EFAULT; \
E 21
I 21
		int error = copyout((caddr_t)&obits[x], (caddr_t)uap->name, \
		    sizeof (obits[x])); \
		if (error) \
			u.u_error = error; \
E 21
D 15
			return; \
		} \
E 15
E 10
	}
I 10
	putbits(in, 0);
	putbits(ou, 1);
	putbits(ex, 2);
#undef putbits
E 10
}
E 24
I 24
			break;
		u.u_error = fset(fp, FASYNC, fp->f_flag & FASYNC);
		if (u.u_error)
			(void) fset(fp, FNDELAY, 0);
		break;
E 24
E 8

D 8
	case TS_OK:
I 6
		now = time;
		timevalsub(&now, &origin);
		timevalsub(&atv, now);
		if (atv.tv_sec < 0 || atv.tv_usec < 0)
			timerclear(&atv);
E 6
		goto retry;
E 8
I 8
D 24
unselect(p)
	register struct proc *p;
{
	register int s = spl6();
E 8

D 8
	case TS_SIG:
		u.u_error = EINTR;
		return;
E 8
I 8
	switch (p->p_stat) {
E 8

D 8
	case TS_TIME:
E 8
I 8
	case SSLEEP:
		setrun(p);
E 24
I 24
D 28
	case 5:
		u.u_error = fsetown(fp, uap->arg);
E 28
I 28
	case F_GETOWN:
		u.u_error = fgetown(fp, &u.u_r.r_val1);
E 28
E 24
E 8
		break;
I 8

D 24
	case SSTOP:
		unsleep(p);
E 24
I 24
D 28
	case 6:
		u.u_error = fgetown(fp, &u.u_r.r_val1);
E 28
I 28
	case F_SETOWN:
		u.u_error = fsetown(fp, uap->arg);
E 28
E 24
		break;
I 24

	default:
		u.u_error = EINVAL;
E 24
E 8
	}
D 8
done:
	rd.fds_bits[0] = readable;
	wr.fds_bits[0] = writeable;
	s = sizeof (fd_set);
D 6
	if (s * NBBY > ap->nfd)
		s = (ap->nfd + NBBY - 1) / NBBY;
E 6
I 6
D 7
	if (s * NBBY > uap->nfd)
		s = (uap->nfd + NBBY - 1) / NBBY;
E 7
E 6
	u.u_r.r_val1 = nfds;
D 6
	if (ap->rp)
		(void) copyout((caddr_t)&rd, (caddr_t)ap->rp, sizeof(fd_set));
	if (ap->wp)
		(void) copyout((caddr_t)&wr, (caddr_t)ap->wp, sizeof(fd_set));
E 6
I 6
	if (uap->rp)
		(void) copyout((caddr_t)&rd, (caddr_t)uap->rp, sizeof(fd_set));
	if (uap->wp)
		(void) copyout((caddr_t)&wr, (caddr_t)uap->wp, sizeof(fd_set));
E 8
I 8
D 24
	splx(s);
E 24
E 8
E 6
}

D 7
selscan(nfd, fds, nfdp, flag)
	int nfd;
E 7
I 7
D 8
selscan(fds, nfdp, flag)
E 7
	fd_set fds;
	int *nfdp, flag;
E 8
I 8
D 24
selscan(ibits, obits)
	int *ibits, *obits;
E 8
{
I 8
	register int which, bits, i;
	int flag;
E 24
I 24
fset(fp, bit, value)
E 24
E 8
	struct file *fp;
I 8
D 24
	int able;
E 8
	struct inode *ip;
D 8
	register int bits;
	int i, able, res = 0;
		
	bits = fds.fds_bits[0];
	while (i = ffs(bits)) {
D 7
		if (i > nfd)
			break;
E 7
		bits &= ~(1<<(i-1));
		fp = u.u_ofile[i-1];
		if (fp == NULL) {
			u.u_error = EBADF;
			return (0);
		}
D 2
		if (fp->f_flag & FSOCKET)
E 2
I 2
		if (fp->f_type == DTYPE_SOCKET)
E 2
			able = soselect(fp->f_socket, flag);
		else {
			ip = fp->f_inode;
			switch (ip->i_mode & IFMT) {
E 8
I 8
	int n = 0;
E 24
I 24
	int bit, value;
{
E 24
E 8

D 8
			case IFCHR:
				able =
				    (*cdevsw[major(ip->i_rdev)].d_select)
					(ip->i_rdev, flag);
				break;
E 8
I 8
D 24
	for (which = 0; which < 3; which++) {
		bits = ibits[which];
		obits[which] = 0;
		switch (which) {
E 24
I 24
	if (value)
		fp->f_flag |= bit;
	else
		fp->f_flag &= ~bit;
	return (fioctl(fp, (int)(bit == FNDELAY ? FIONBIO : FIOASYNC),
	    (caddr_t)&value));
}
E 24
E 8

D 8
			case IFBLK:
			case IFREG:
			case IFDIR:
				able = 1;
E 8
I 8
D 24
		case 0:
			flag = FREAD; break;
E 24
I 24
fgetown(fp, valuep)
	struct file *fp;
	int *valuep;
{
	int error;
E 24

D 24
		case 1:
			flag = FWRITE; break;
E 24
I 24
	switch (fp->f_type) {
E 24

D 24
		case 2:
			flag = 0; break;
		}
		while (i = ffs(bits)) {
			bits &= ~(1<<(i-1));
			fp = u.u_ofile[i-1];
			if (fp == NULL) {
				u.u_error = EBADF;
E 8
				break;
			}
I 8
			if (fp->f_type == DTYPE_SOCKET)
				able = soselect(fp->f_socket, flag);
			else {
				ip = fp->f_inode;
				switch (ip->i_mode & IFMT) {
E 24
I 24
	case DTYPE_SOCKET:
		*valuep = ((struct socket *)fp->f_data)->so_pgrp;
		return (0);
E 24
E 8
I 2

I 8
D 24
				case IFCHR:
					able =
					    (*cdevsw[major(ip->i_rdev)].d_select)
						(ip->i_rdev, flag);
					break;

				case IFBLK:
				case IFREG:
				case IFDIR:
					able = 1;
					break;
				}

			}
			if (able) {
				obits[which] |= (1<<(i-1));
				n++;
			}
E 8
E 2
		}
E 24
I 24
	default:
		error = fioctl(fp, (int)TIOCGPGRP, (caddr_t)valuep);
		*valuep = -*valuep;
		return (error);
E 24
D 8
		if (able) {
			res |= (1<<(i-1));
			(*nfdp)++;
		}
E 8
	}
D 8
	return (res);
E 8
I 8
D 24
	return (n);
E 24
E 8
}

D 24
/*ARGSUSED*/
seltrue(dev, flag)
	dev_t dev;
	int flag;
E 24
I 24
fsetown(fp, value)
	struct file *fp;
	int value;
E 24
{

D 24
	return (1);
E 24
I 24
	if (fp->f_type == DTYPE_SOCKET) {
		((struct socket *)fp->f_data)->so_pgrp = value;
		return (0);
	}
	if (value > 0) {
		struct proc *p = pfind(value);
		if (p == 0)
D 39
			return (EINVAL);
E 39
I 39
			return (ESRCH);
E 39
		value = p->p_pgrp;
	} else
		value = -value;
	return (fioctl(fp, (int)TIOCSPGRP, (caddr_t)&value));
E 24
}

D 24
selwakeup(p, coll)
	register struct proc *p;
	int coll;
E 24
I 24
fioctl(fp, cmd, value)
	struct file *fp;
	int cmd;
	caddr_t value;
E 24
{
D 22
	int s;
E 22

D 24
	if (coll) {
		nselcoll++;
		wakeup((caddr_t)&selwait);
	}
	if (p) {
I 22
		int s = spl6();
E 22
		if (p->p_wchan == (caddr_t)&selwait)
			setrun(p);
D 22
		else {
			s = spl6();
			if (p->p_flag & SSEL)
				p->p_flag &= ~SSEL;
			splx(s);
		}
E 22
I 22
		else if (p->p_flag & SSEL)
			p->p_flag &= ~SSEL;
		splx(s);
E 22
	}
E 24
I 24
	return ((*fp->f_ops->fo_ioctl)(fp, cmd, value));
E 24
I 6
}

D 24
revoke()
E 24
I 24
close()
E 24
{
I 24
D 36
	register struct a {
E 36
I 36
	struct a {
E 36
		int	i;
	} *uap = (struct a *)u.u_ap;
I 36
	register int i = uap->i;
E 36
	register struct file *fp;
I 25
	register u_char *pf;
E 25
E 24

D 24
	/* XXX */
E 24
I 24
D 30
	fp = getf(uap->i);
	if (fp == 0)
		return;
E 30
I 30
D 36
	GETF(fp, uap->i);
E 30
D 25
	if (u.u_pofile[uap->i] & UF_MAPPED)
E 25
I 25
	pf = (u_char *)&u.u_pofile[uap->i];
E 36
I 36
	GETF(fp, i);
	pf = (u_char *)&u.u_pofile[i];
E 36
	if (*pf & UF_MAPPED)
E 25
D 36
		munmapfd(uap->i);
D 25
	closef(fp, u.u_pofile[uap->i]);
E 25
I 25
D 26
	if (*pf & (UF_SHLOCK|UF_EXLOCK))
		unlockf(fp, pf);
E 26
D 29
	closef(fp);
E 25
	/* WHAT IF u.u_error ? */
E 29
	u.u_ofile[uap->i] = NULL;
E 36
I 36
		munmapfd(i);
	u.u_ofile[i] = NULL;
	while (u.u_lastfile >= 0 && u.u_ofile[u.u_lastfile] == NULL)
		u.u_lastfile--;
E 36
D 25
	u.u_pofile[uap->i] = 0;
E 25
I 25
	*pf = 0;
I 29
	closef(fp);
	/* WHAT IF u.u_error ? */
E 29
E 25
E 24
E 6
}

I 25
fstat()
{
	register struct file *fp;
	register struct a {
		int	fdes;
		struct	stat *sb;
	} *uap;
	struct stat ub;

	uap = (struct a *)u.u_ap;
D 30
	fp = getf(uap->fdes);
	if (fp == 0)
		return;
E 30
I 30
	GETF(fp, uap->fdes);
E 30
	switch (fp->f_type) {

	case DTYPE_INODE:
		u.u_error = ino_stat((struct inode *)fp->f_data, &ub);
		break;

	case DTYPE_SOCKET:
		u.u_error = soo_stat((struct socket *)fp->f_data, &ub);
		break;

	default:
		panic("fstat");
		/*NOTREACHED*/
	}
	if (u.u_error == 0)
D 26
		u.u_error = copyout(&ub, uap->sb, sizeof (ub));
E 26
I 26
		u.u_error = copyout((caddr_t)&ub, (caddr_t)uap->sb,
		    sizeof (ub));
E 26
}

E 25
I 2
D 4

E 4
E 2
/*
D 2
 * Close system call
E 2
I 2
 * Allocate a user file descriptor.
E 2
 */
D 2
close()
E 2
I 2
D 24
ufalloc()
E 24
I 24
ufalloc(i)
	register int i;
E 24
E 2
{
I 2
D 24
	register i;
E 24

D 24
	for (i=0; i<NOFILE; i++)
E 24
I 24
	for (; i < NOFILE; i++)
E 24
		if (u.u_ofile[i] == NULL) {
			u.u_r.r_val1 = i;
			u.u_pofile[i] = 0;
I 36
			if (i > u.u_lastfile)
				u.u_lastfile = i;
E 36
			return (i);
		}
	u.u_error = EMFILE;
	return (-1);
}

I 24
ufavail()
{
	register int i, avail = 0;

	for (i = 0; i < NOFILE; i++)
		if (u.u_ofile[i] == NULL)
			avail++;
	return (avail);
}

E 24
struct	file *lastf;
/*
 * Allocate a user file descriptor
 * and a file structure.
 * Initialize the descriptor
 * to point at the file structure.
 */
struct file *
falloc()
{
E 2
	register struct file *fp;
D 2
	register struct a {
		int	fdes;
	} *uap;
E 2
I 2
	register i;
E 2

D 2
	uap = (struct a *)u.u_ap;
	fp = getf(uap->fdes);
E 2
I 2
D 24
	i = ufalloc();
E 24
I 24
	i = ufalloc(0);
E 24
	if (i < 0)
		return (NULL);
	if (lastf == 0)
		lastf = file;
	for (fp = lastf; fp < fileNFILE; fp++)
		if (fp->f_count == 0)
			goto slot;
	for (fp = file; fp < lastf; fp++)
		if (fp->f_count == 0)
			goto slot;
	tablefull("file");
	u.u_error = ENFILE;
	return (NULL);
slot:
	u.u_ofile[i] = fp;
D 24
	fp->f_count++;
E 24
I 24
	fp->f_count = 1;
	fp->f_data = 0;
E 24
	fp->f_offset = 0;
D 24
	fp->f_inode = 0;
E 24
	lastf = fp + 1;
	return (fp);
}
I 24

E 24
/*
 * Convert a user supplied file descriptor into a pointer
 * to a file structure.  Only task is to check range of the descriptor.
D 24
 * Critical paths should use the GETF macro, defined in inline.h.
E 24
I 24
 * Critical paths should use the GETF macro.
E 24
 */
struct file *
getf(f)
	register int f;
{
	register struct file *fp;

	if ((unsigned)f >= NOFILE || (fp = u.u_ofile[f]) == NULL) {
		u.u_error = EBADF;
		return (NULL);
	}
	return (fp);
}

/*
 * Internal form of close.
D 24
 * Decrement reference count on
 * file structure.
 * Also make sure the pipe protocol
 * does not constipate.
 *
 * Decrement reference count on the inode following
 * removal to the referencing file structure.
 * Call device handler on last close.
 * Nouser indicates that the user isn't available to present
 * errors to.
I 4
 *
 * Handling locking at this level is RIDICULOUS.
E 24
I 24
 * Decrement reference count on file structure.
D 38
 * If last reference not going away, but no more
 * references except in message queues, run a
 * garbage collect.  This would better be done by
 * forcing a gc() to happen sometime soon, rather
 * than running one each time.
E 38
E 24
E 4
 */
D 4
closef(fp, nouser)
E 4
I 4
D 24
closef(fp, nouser, flags)
E 24
I 24
D 25
closef(fp, flags)
E 25
I 25
closef(fp)
E 25
E 24
E 4
	register struct file *fp;
I 4
D 24
	int nouser, flags;
E 24
I 24
D 25
	int flags;					/* XXX */
E 25
E 24
E 4
{
D 24
	register struct inode *ip;
	register struct mount *mp;
	int flag, mode;
	dev_t dev;
	register int (*cfunc)();
E 24

E 2
	if (fp == NULL)
		return;
D 2
	if (u.u_vrpages[uap->fdes]) {
		u.u_error = ETXTBSY;
E 2
I 2
	if (fp->f_count > 1) {
		fp->f_count--;
I 24
D 38
		if (fp->f_count == fp->f_msgcount)
			unp_gc();
E 38
E 24
E 2
		return;
	}
D 2
	u.u_ofile[uap->fdes] = NULL;
	closef(fp, 0);
E 2
I 2
D 24
	if (fp->f_type == DTYPE_SOCKET) {
D 14
		u.u_error = 0;			/* XXX */
		soclose(fp->f_socket, nouser);
E 14
I 14
		u.u_error = soclose(fp->f_socket, nouser);
E 14
		if (nouser == 0 && u.u_error)
			return;
		fp->f_socket = 0;
		fp->f_count = 0;
		return;
	}
	flag = fp->f_flag;
	ip = fp->f_inode;
	dev = (dev_t)ip->i_rdev;
	mode = ip->i_mode & IFMT;
I 4
D 18
	flags &= RDLOCK|WRLOCK;			/* conservative */
E 18
I 18
D 19
	flags &= SHLOCK|EXLOCK;			/* conservative */
E 19
I 19
	flags &= UF_SHLOCK|UF_EXLOCK;			/* conservative */
E 19
E 18
	if (flags)
		funlocki(ip, flags);
E 4
	ilock(ip);
	iput(ip);
E 24
I 24
D 25
	(*fp->f_ops->fo_close)(fp, flags);
E 25
I 25
	(*fp->f_ops->fo_close)(fp);
E 25
E 24
	fp->f_count = 0;
I 25
}

/*
 * Apply an advisory lock on a file descriptor.
 */
flock()
{
	register struct a {
		int	fd;
		int	how;
	} *uap = (struct a *)u.u_ap;
	register struct file *fp;
D 26
	register u_char *pf;
	int cmd;
E 26

D 30
	fp = getf(uap->fd);
	if (fp == NULL)
		return;
E 30
I 30
	GETF(fp, uap->fd);
E 30
D 26
	cmd = uap->how;
	pf = (u_char *)&u.u_pofile[uap->fd];
	if (cmd & LOCK_UN) {
		unlockf(fp, pf);
E 26
I 26
	if (fp->f_type != DTYPE_INODE) {
		u.u_error = EOPNOTSUPP;
E 26
		return;
	}
D 26
	/*
	 * No reason to write lock a file we've already
	 * write locked, similarly with a read lock.
	 */
	if ((*pf & UF_EXLOCK) && (cmd & LOCK_EX) ||
	    (*pf & UF_SHLOCK) && (cmd & LOCK_SH))
E 26
I 26
	if (uap->how & LOCK_UN) {
		ino_unlock(fp, FSHLOCK|FEXLOCK);
E 26
		return;
D 26
	switch (fp->f_type) {

	case DTYPE_INODE:
		u.u_error = ino_lock((struct inode *)fp->f_data, pf, cmd);
		break;

	case DTYPE_SOCKET:
		u.u_error = soo_lock((struct socket *)fp->f_data, pf, cmd);
		break;

	default:
		panic("lockf");
E 26
	}
I 32
	if ((uap->how & (LOCK_SH | LOCK_EX)) == 0)
		return;					/* error? */
I 34
	if (uap->how & LOCK_EX)
		uap->how &= ~LOCK_SH;
E 34
E 32
D 26
}

unlockf(fp, pf)
	register struct file *fp;
	register u_char *pf;
{

	if ((*pf & (UF_SHLOCK|UF_EXLOCK)) == 0)
E 26
I 26
	/* avoid work... */
D 32
	if ((fp->f_flag & FEXLOCK) && (uap->how & LOCK_EX) ||
	    (fp->f_flag & FSHLOCK) && (uap->how & LOCK_SH))
E 32
I 32
D 34
	if ((fp->f_flag & FEXLOCK) && (uap->how & LOCK_EX))
E 34
I 34
	if ((fp->f_flag & FEXLOCK) && (uap->how & LOCK_EX) ||
	    (fp->f_flag & FSHLOCK) && (uap->how & LOCK_SH))
E 34
E 32
E 26
		return;
D 26
	switch (fp->f_type) {

	case DTYPE_INODE:
		ino_unlock((struct inode *)fp->f_data, *pf);
		break;

	case DTYPE_SOCKET:
		soo_unlock((struct socket *)fp->f_data, *pf);
		break;

	default:
		panic("unlockf");
	}
	*pf &= ~(UF_SHLOCK|UF_EXLOCK);
E 26
I 26
	u.u_error = ino_lock(fp, uap->how);
E 26
E 25
D 24

	switch (mode) {

	case IFCHR:
		cfunc = cdevsw[major(dev)].d_close;
D 3
#ifdef EFS
		/*
		 * Every close() must call the driver if the
		 * extended file system is being used -- not
		 * just the last close.  Pass along the file
		 * pointer for reference later.
		 */
		if (major(dev) == efs_major) {
			(*cfunc)(dev, flag, fp, nouser);
			return;
		}
#endif
E 3
		break;

	case IFBLK:
		/*
		 * We don't want to really close the device if it is mounted
		 */
		for (mp = mount; mp < &mount[NMOUNT]; mp++)
			if (mp->m_bufp != NULL && mp->m_dev == dev)
				return;
		cfunc = bdevsw[major(dev)].d_close;
		break;

	default:
		return;
	}
	for (fp = file; fp < fileNFILE; fp++) {
		if (fp->f_type == DTYPE_SOCKET)		/* XXX */
			continue;
		if (fp->f_count && (ip = fp->f_inode) &&
		    ip->i_rdev == dev && (ip->i_mode&IFMT) == mode)
			return;
	}
	if (mode == IFBLK) {
		/*
		 * On last close of a block device (that isn't mounted)
		 * we must invalidate any in core blocks
		 */
		bflush(dev);
		binval(dev);
	}
	(*cfunc)(dev, flag, fp);
E 2
}
I 9

opause()
{

	for (;;)
		sleep((caddr_t)&u, PSLEP);
E 24
}
E 9
I 2
D 4

#ifdef CAD
/*
 * chfile -- change all references to the inode named by
 *	     device/inum to the file referred to by fd.
 * Used by init to remove all references to the device.
 */
chfile()
{
	register struct file *fp;
	register struct inode *from;
	register struct inode *to;
	off_t offset;
	dev_t dev;
	int rw;
	struct a {
		int	device;		/* actually dev_t */
		int	inum;		/* actually ino_t */
		int	fd;
	} *uap;

	if (!suser()) {
		u.u_error = EPERM;
		return;
	}
	uap = (struct a *) u.u_ap;
	fp = getf(uap->fd);
	if (fp == NULL) {
		u.u_error = EBADF;
		return;
	}
	if (fp->f_type == DTYPE_SOCKET) {
		u.u_error = EINVAL;
		return;
	}
	for (from = &inode[0]; from < &inode[ninode]; from++)
		if (from->i_number == (ino_t)uap->inum
		   && from->i_dev == (dev_t)uap->device)
			break;
	if (from >= &inode[ninode]) {
		u.u_error = ENXIO;
		return;
	}
	offset = fp->f_offset;
	to = fp->f_inode;
	from->i_count++;
	for (fp = &file[0]; fp < &file[nfile]; fp++) {
		if (fp->f_count > 0 && fp->f_inode == from) {
			fp->f_inode = to;
			to->i_count++;
			fp->f_offset = offset;
			rw |= fp->f_flag & FWRITE;
			iput(from);
		}
	}
	/*
	 * This inode is no longer referenced.
	 * Switch out to the appropriate close
	 * routine, if required
	 */
	dev = (dev_t)from->i_un.i_rdev;
	switch(from->i_mode & IFMT) {

	case IFCHR:
		(*cdevsw[major(dev)].d_close)(dev, rw);
		break;
	
	case IFBLK:
		(*bdevsw[major(dev)].d_close)(dev, rw);
		break;

	default:
		break;
	}
	iput(from);
}
#endif
E 4
E 2
E 1
