h00466
s 00002/00001/00452
d D 7.7 88/05/24 19:26:06 mckusick 66 65
c lint
e
s 00001/00001/00452
d D 7.6 88/03/10 18:28:56 karels 65 64
c clear SSEL when done selecting
e
s 00003/00003/00450
d D 7.5 88/02/08 21:40:19 karels 64 63
c lint
e
s 00010/00007/00443
d D 7.4 87/06/20 15:02:05 mckusick 63 62
c replace geteblk with malloc
e
s 00000/00002/00450
d D 7.3 87/03/17 18:02:23 mckusick 62 61
c must avoid race between use and updating of f_offset pointer
e
s 00031/00016/00421
d D 7.2 87/02/19 17:27:56 karels 61 60
c allow ioctl to handle larger buffers (for pack labels)
e
s 00001/00001/00436
d D 7.1 86/06/05 00:07:39 mckusick 60 59
c 4.3BSD release version
e
s 00007/00007/00430
d D 6.15 86/03/04 19:55:01 karels 59 57
c consistency
e
s 00437/00000/00000
d R 6.15 86/03/04 19:25:23 karels 58 57
c consistency
e
s 00004/00004/00433
d D 6.14 86/02/20 15:58:28 karels 57 56
c cleanups from Sam: format, spl's, ptrace defs
e
s 00001/00001/00436
d D 6.13 86/02/04 17:17:03 karels 56 55
c consistency in select: never modify masks on return with an error,
c always if no error ( return >= 0)
e
s 00013/00022/00424
d D 6.12 85/06/17 21:58:39 karels 55 54
c move select bitmask macros to types.h, rename and structurize
e
s 00007/00001/00439
d D 6.11 85/06/08 14:42:53 mckusick 54 53
c Add copyright
e
s 00005/00003/00435
d D 6.10 85/05/27 19:59:51 karels 53 52
c select now leaves masks unmodified if interrupted (always)
e
s 00001/00002/00437
d D 6.9 85/05/22 19:48:31 mckusick 52 51
c eliminate double meaning of SOUSIG
e
s 00008/00003/00431
d D 6.8 85/03/12 13:53:12 mckusick 51 50
c add another bit to sigvec() flags to disable system call restart
e
s 00004/00004/00430
d D 6.7 85/02/08 17:52:59 karels 50 49
c don't drop spl during selwakeup
e
s 00039/00028/00395
d D 6.6 84/12/27 16:43:10 karels 49 48
c select on >32 files
e
s 00006/00003/00417
d D 6.5 84/10/19 10:54:16 karels 48 47
c don't setrun stopped procs in selwakeup
e
s 00010/00010/00410
d D 6.4 84/08/29 20:21:54 bloom 47 46
c Change to includes.  no more ../h
e
s 00001/00002/00419
d D 6.3 84/08/22 16:56:59 mckusick 46 45
c use GETF macro where appropriate
e
s 00001/00001/00420
d D 6.2 84/07/08 22:20:23 mckusick 45 44
c use proper definition of UIO flags
e
s 00000/00000/00421
d D 6.1 83/07/29 06:36:48 sam 44 43
c 4.2 distribution
e
s 00001/00000/00420
d D 5.42 83/06/24 14:47:26 sam 43 42
c infinite loop
e
s 00001/00001/00419
d D 5.41 83/06/21 20:36:00 sam 42 41
c change NOCOMPAT to COMPAT and make it work
e
s 00000/00018/00420
d D 5.40 83/06/12 14:28:47 sam 41 40
c cleanup fstat
e
s 00003/00001/00435
d D 5.39 83/06/12 12:46:36 sam 40 38
c blew it last time
e
s 00003/00001/00435
d R 5.39 83/06/11 12:30:32 sam 39 38
c mask bits so ffs in selscan always returns properly bounded value
e
s 00003/00001/00433
d D 5.38 83/06/10 21:24:31 sam 38 37
c timercmp isn't all that it's cracked up to be
e
s 00001/00001/00433
d D 5.37 83/06/02 15:57:16 sam 37 36
c new signals
e
s 00204/00352/00230
d D 5.36 83/05/27 12:47:42 sam 36 35
c merge of bill's code plus lint (plus, of course, cleanup of bill's bugs)
e
s 00000/00010/00582
d D 5.35 83/05/21 15:36:16 sam 35 34
c purge mush
e
s 00002/00002/00590
d D 5.34 83/05/08 13:37:43 sam 34 33
c format
e
s 00002/00001/00590
d D 5.33 83/05/06 17:01:23 helge 33 32
c added f_flag to the call to the driver ioctl routine
e
s 00002/00000/00589
d D 5.32 83/02/25 05:30:19 sam 32 31
c from shannon
e
s 00002/00000/00587
d D 5.31 83/02/18 12:43:51 sam 31 30
c put back append mode?
e
s 00013/00011/00574
d D 5.30 83/01/23 00:01:49 sam 30 29
c don't zero buffer when doing in/out ioctl's
e
s 00011/00015/00574
d D 5.29 82/12/28 23:47:44 sam 29 28
c copyin & copyout now return EFAULT and all callers uniformly 
c return (or ignore) this value
e
s 00001/00001/00588
d D 5.28 82/12/28 22:30:48 sam 28 27
c using return val from copyin/copyout -- causes uiomove to 
c give errno of -1 instead of EFAULT!!!
e
s 00001/00002/00588
d D 5.27 82/12/21 14:59:09 sam 27 26
c error uninitialized in uiomove
e
s 00001/00000/00589
d D 5.26 82/12/21 14:39:08 sam 26 25
c make mkdir & rmdir work with rdwri (still kludged)
e
s 00002/00002/00587
d D 5.25 82/12/09 19:01:57 sam 25 24
c u.u_pofile flags are now UF_*
e
s 00001/00001/00588
d D 5.24 82/12/05 22:00:34 sam 24 23
c include ioctl.h separate from tty.h
e
s 00003/00001/00586
d D 5.23 82/11/17 00:07:34 sam 23 22
c no return value and add read(..., 0) early return
e
s 00005/00001/00582
d D 5.22 82/11/13 22:48:40 sam 22 21
c merge of 4.1b and 4.1c; and missing check for 0 length write
e
s 00001/00001/00582
d D 5.21 82/10/21 23:53:36 root 21 20
c lint
e
s 00003/00001/00580
d D 5.20 82/10/21 20:58:02 root 20 19
c lint
e
s 00002/00002/00579
d D 5.19 82/10/19 10:31:12 root 19 18
c more lint
e
s 00002/00001/00579
d D 5.18 82/10/17 21:49:48 root 18 17
c more lint
e
s 00003/00003/00577
d D 5.17 82/10/17 11:34:46 root 17 16
c ioctl lower levels return errno's
e
s 00002/00002/00578
d D 5.16 82/10/13 22:08:14 root 16 15
c return errors from ioctl routines and internal ldisc routines
e
s 00003/00004/00577
d D 5.15 82/10/10 15:55:50 root 15 14
c header files to vax directories
e
s 00002/00002/00579
d D 5.14 82/09/08 08:07:19 root 14 13
c label_t now structure
e
s 00010/00000/00571
d D 5.13 82/09/06 22:54:24 root 13 12
c  
e
s 00002/00002/00569
d D 5.12 82/09/04 09:17:31 root 12 11
c cosmetic for new style limits
e
s 00376/00370/00195
d D 5.11 82/08/22 20:38:31 root 11 10
c first completely uio'd version
e
s 00026/00105/00539
d D 5.10 82/08/14 18:54:28 root 10 9
c no more readi()
e
s 00072/00035/00572
d D 5.9 82/08/14 18:01:26 root 9 8
c read() now goes through readip()
e
s 00012/00002/00595
d D 5.8 82/08/13 00:04:22 wnj 8 7
c fixes to get uio'd readi for char devs
e
s 00106/00000/00491
d D 5.7 82/08/11 21:11:35 root 7 6
c first use of readip()
e
s 00006/00014/00485
d D 5.6 82/08/10 17:44:45 sam 6 5
c don't copy stuff out if an error in lower levels
e
s 00081/00030/00418
d D 5.5 82/08/01 19:21:04 sam 5 4
c new ioctl's
e
s 00007/00011/00441
d D 5.4 82/07/25 23:13:15 root 4 3
c add more error checking on result of bmap (chk u.u_error)
e
s 00016/00003/00436
d D 5.3 82/07/24 18:10:50 root 3 2
c merge with calder
e
s 00009/00000/00430
d D 5.2 82/07/22 13:20:08 kre 2 1
c mush
e
s 00430/00000/00000
d D 5.1 82/07/15 20:16:17 root 1 0
c date and time created 82/07/15 20:16:17 by root
e
u
U
f i 
t
T
I 1
D 54
/*	%M%	%I%	%E%	*/
E 54
I 54
/*
D 60
 * Copyright (c) 1982 Regents of the University of California.
E 60
I 60
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 60
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 54

D 47
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
I 24
#include "../h/ioctl.h"
E 24
D 36
#include "../h/tty.h"
E 36
I 3
D 6
#include "../h/fcntl.h"
E 6
E 3
#include "../h/file.h"
I 22
D 24
#define	IDEBUG
E 24
E 22
D 36
#include "../h/inode.h"
#include "../h/buf.h"
E 36
#include "../h/proc.h"
D 15
#include "../h/inline.h"
E 15
D 36
#include "../h/conf.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
D 11
#include "../h/cmap.h"
#include "../h/vlimit.h"
E 11
#include "../h/fs.h"
I 2
D 35
#ifdef MUSH
#include "../h/quota.h"
#include "../h/share.h"
#else
#define	CHARGE(nothing)
#endif
E 35
I 11
D 12
#include "../h/vlimit.h"
E 12
E 11
I 3
#include "../h/descrip.h"
E 36
I 7
#include "../h/uio.h"
I 19
D 36
#include "../h/cmap.h"
E 36
I 36
#include "../h/kernel.h"
#include "../h/stat.h"
E 47
I 47
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "ioctl.h"
#include "file.h"
#include "proc.h"
#include "uio.h"
#include "kernel.h"
#include "stat.h"
I 61
D 63
#include "buf.h"				/* XXX */
E 63
I 63
#include "malloc.h"
E 63
E 61
E 47
E 36
E 19
E 7
E 3
E 2

/*
 * Read system call.
 */
read()
{
D 11
	register struct file *fp;
	register struct inode *ip;
E 11
	register struct a {
		int	fdes;
		char	*cbuf;
		unsigned count;
D 11
	} *uap;
E 11
I 11
	} *uap = (struct a *)u.u_ap;
E 11
I 9
	struct uio auio;
	struct iovec aiov;
E 9

D 11
	uap = (struct a *)u.u_ap;
	if ((int)uap->count < 0) {
		u.u_error = EINVAL;
		return;
	}
	GETF(fp, uap->fdes);
	if ((fp->f_flag&FREAD) == 0) {
		u.u_error = EBADF;
		return;
	}
E 11
D 9
	u.u_base = (caddr_t)uap->cbuf;
	u.u_count = uap->count;
	u.u_segflg = 0;
E 9
I 9
	aiov.iov_base = (caddr_t)uap->cbuf;
	aiov.iov_len = uap->count;
	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
D 11
	auio.uio_segflg = 0;
	auio.uio_resid = uap->count;
	u.u_base = (caddr_t)0xc0000000;
	u.u_count = 0x40000000;
E 9
	if ((u.u_procp->p_flag&SNUSIG) && setjmp(u.u_qsav)) {
D 9
		if (u.u_count == uap->count)
E 9
I 9
		if (auio.uio_resid == uap->count)
E 9
			u.u_eosys = RESTARTSYS;
D 3
	} else if (fp->f_flag & FSOCKET)
E 3
I 3
	} else if (fp->f_type == DTYPE_SOCKET)
E 3
D 9
		u.u_error = soreceive(fp->f_socket, (struct sockaddr *)0);
E 9
I 9
		u.u_error = soreceive(fp->f_socket, (struct sockaddr *)0, &auio);
E 9
	else {
		ip = fp->f_inode;
D 9
		u.u_offset = fp->f_offset;
E 9
I 9
		auio.uio_offset = fp->f_offset;
E 9
		if ((ip->i_mode&IFMT) == IFREG) {
			ilock(ip);
D 9
			readi(ip);
E 9
I 9
			u.u_error = readip(ip, &auio);
E 9
			iunlock(ip);
		} else
D 9
			readi(ip);
		fp->f_offset += uap->count - u.u_count;
E 9
I 9
			u.u_error = readip(ip, &auio);
		fp->f_offset += uap->count - auio.uio_resid;
E 11
I 11
	rwuio(&auio, UIO_READ);
}

readv()
{
	register struct a {
		int	fdes;
		struct	iovec *iovp;
D 59
		int	iovcnt;
E 59
I 59
		unsigned iovcnt;
E 59
	} *uap = (struct a *)u.u_ap;
	struct uio auio;
	struct iovec aiov[16];		/* XXX */

D 59
	if (uap->iovcnt <= 0 || uap->iovcnt > sizeof(aiov)/sizeof(aiov[0])) {
E 59
I 59
	if (uap->iovcnt > sizeof(aiov)/sizeof(aiov[0])) {
E 59
		u.u_error = EINVAL;
		return;
E 11
E 9
	}
D 9
	u.u_r.r_val1 = uap->count - u.u_count;
E 9
I 9
D 11
	u.u_r.r_val1 = uap->count - auio.uio_resid;
E 11
I 11
	auio.uio_iov = aiov;
	auio.uio_iovcnt = uap->iovcnt;
D 29
	if (copyin((caddr_t)uap->iovp, (caddr_t)aiov,
	    (unsigned)(uap->iovcnt * sizeof (struct iovec)))) {
		u.u_error = EFAULT;
E 29
I 29
	u.u_error = copyin((caddr_t)uap->iovp, (caddr_t)aiov,
D 59
	    (unsigned)(uap->iovcnt * sizeof (struct iovec)));
E 59
I 59
	    uap->iovcnt * sizeof (struct iovec));
E 59
	if (u.u_error)
E 29
		return;
D 29
	}
E 29
	rwuio(&auio, UIO_READ);
E 11
E 9
}

/*
 * Write system call
 */
write()
{
D 11
	register struct file *fp;
	register struct inode *ip;
E 11
	register struct a {
		int	fdes;
		char	*cbuf;
D 11
		unsigned count;
	} *uap;
E 11
I 11
D 59
		int	count;
E 59
I 59
		unsigned count;
E 59
	} *uap = (struct a *)u.u_ap;
	struct uio auio;
	struct iovec aiov;
E 11

D 11
	uap = (struct a *)u.u_ap;
	if ((int)uap->count < 0) {
E 11
I 11
	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
	aiov.iov_base = uap->cbuf;
	aiov.iov_len = uap->count;
	rwuio(&auio, UIO_WRITE);
}

writev()
{
	register struct a {
		int	fdes;
		struct	iovec *iovp;
D 59
		int	iovcnt;
E 59
I 59
		unsigned iovcnt;
E 59
	} *uap = (struct a *)u.u_ap;
	struct uio auio;
	struct iovec aiov[16];		/* XXX */

D 59
	if (uap->iovcnt <= 0 || uap->iovcnt > sizeof(aiov)/sizeof(aiov[0])) {
E 59
I 59
	if (uap->iovcnt > sizeof(aiov)/sizeof(aiov[0])) {
E 59
E 11
		u.u_error = EINVAL;
		return;
	}
D 11
	GETF(fp, uap->fdes);
	if ((fp->f_flag&FWRITE) == 0) {
E 11
I 11
	auio.uio_iov = aiov;
	auio.uio_iovcnt = uap->iovcnt;
D 29
	if (copyin((caddr_t)uap->iovp, (caddr_t)aiov,
	    (unsigned)(uap->iovcnt * sizeof (struct iovec)))) {
		u.u_error = EFAULT;
E 29
I 29
	u.u_error = copyin((caddr_t)uap->iovp, (caddr_t)aiov,
D 59
	    (unsigned)(uap->iovcnt * sizeof (struct iovec)));
E 59
I 59
	    uap->iovcnt * sizeof (struct iovec));
E 59
	if (u.u_error)
E 29
		return;
D 29
	}
E 29
	rwuio(&auio, UIO_WRITE);
}

rwuio(uio, rw)
	register struct uio *uio;
	enum uio_rw rw;
{
	struct a {
		int	fdes;
	};
	register struct file *fp;
	register struct iovec *iov;
D 36
	register struct inode *ip;
E 36
	int i, count;

	GETF(fp, ((struct a *)u.u_ap)->fdes);
	if ((fp->f_flag&(rw==UIO_READ ? FREAD : FWRITE)) == 0) {
E 11
		u.u_error = EBADF;
		return;
	}
D 11
	u.u_base = (caddr_t)uap->cbuf;
	u.u_count = uap->count;
	u.u_segflg = 0;
E 11
I 11
	uio->uio_resid = 0;
D 45
	uio->uio_segflg = 0;
E 45
I 45
	uio->uio_segflg = UIO_USERSPACE;
E 45
	iov = uio->uio_iov;
	for (i = 0; i < uio->uio_iovcnt; i++) {
		if (iov->iov_len < 0) {
			u.u_error = EINVAL;
			return;
		}
		uio->uio_resid += iov->iov_len;
		if (uio->uio_resid < 0) {
			u.u_error = EINVAL;
			return;
		}
I 43
		iov++;
E 43
	}
	count = uio->uio_resid;
I 36
D 62
	uio->uio_offset = fp->f_offset;
E 62
E 36
E 11
D 14
	if ((u.u_procp->p_flag&SNUSIG) && setjmp(u.u_qsav)) {
E 14
I 14
D 37
	if ((u.u_procp->p_flag&SNUSIG) && setjmp(&u.u_qsave)) {
E 37
I 37
D 51
	if ((u.u_procp->p_flag&SOUSIG) == 0 && setjmp(&u.u_qsave)) {
E 37
E 14
D 11
		if (u.u_count == uap->count)
E 11
I 11
		if (uio->uio_resid == count)
E 11
			u.u_eosys = RESTARTSYS;
E 51
I 51
	if (setjmp(&u.u_qsave)) {
		if (uio->uio_resid == count) {
D 52
			if ((u.u_sigintr & sigmask(u.u_procp->p_cursig)) != 0 ||
			    (u.u_procp->p_flag & SOUSIG) != 0)
E 52
I 52
			if ((u.u_sigintr & sigmask(u.u_procp->p_cursig)) != 0)
E 52
				u.u_error = EINTR;
			else
				u.u_eosys = RESTARTSYS;
		}
E 51
D 3
	} else if (fp->f_flag & FSOCKET)
E 3
I 3
D 11
	} else if (fp->f_type == DTYPE_SOCKET)
E 3
		u.u_error = sosend(fp->f_socket, (struct sockaddr *)0);
	else {
E 11
I 11
D 36
	} else if (fp->f_type == DTYPE_SOCKET) {
		int sosend(), soreceive();
		u.u_error = 
		    (*(rw==UIO_READ?soreceive:sosend))
D 15
		      (fp->f_socket, (struct sockaddr *)0, uio);
E 15
I 15
		      (fp->f_socket, (struct sockaddr *)0, uio, 0);
E 15
	} else {
E 11
		ip = fp->f_inode;
I 3
D 6
		if (fp->f_flag & O_APPEND)
E 6
I 6
D 11
		if (fp->f_flag&FAPPEND)
E 6
			fp->f_offset = ip->i_size;
E 3
		u.u_offset = fp->f_offset;
E 11
I 11
		uio->uio_offset = fp->f_offset;
E 11
		if ((ip->i_mode&IFMT) == IFREG) {
D 15
			ilock(ip);
E 15
I 15
			ILOCK(ip);
I 31
			if (fp->f_flag&FAPPEND && rw == UIO_WRITE)
				uio->uio_offset = fp->f_offset = ip->i_size;
E 31
E 15
D 11
			writei(ip);
E 11
I 11
			u.u_error = rwip(ip, uio, rw);
E 11
D 15
			iunlock(ip);
E 15
I 15
			IUNLOCK(ip);
E 15
		} else
D 11
			writei(ip);
		fp->f_offset += uap->count - u.u_count;
E 11
I 11
			u.u_error = rwip(ip, uio, rw);
		fp->f_offset += count - uio->uio_resid;
E 11
	}
E 36
I 36
	} else
		u.u_error = (*fp->f_ops->fo_rw)(fp, rw, uio);
E 36
D 11
	u.u_r.r_val1 = uap->count - u.u_count;
E 11
I 11
	u.u_r.r_val1 = count - uio->uio_resid;
I 36
D 62
	fp->f_offset += u.u_r.r_val1;
E 62
E 36
E 11
}

I 3
D 11
readv()
E 11
I 11
D 36
rdwri(rw, ip, base, len, offset, segflg, aresid)
	struct inode *ip;
	caddr_t base;
	int len, offset, segflg;
	int *aresid;
	enum uio_rw rw;
E 11
{
I 11
	struct uio auio;
	struct iovec aiov;
	int error;
E 11
E 3

I 11
	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
	aiov.iov_base = base;
	aiov.iov_len = len;
	auio.uio_resid = len;
	auio.uio_offset = offset;
	auio.uio_segflg = segflg;
	error = rwip(ip, &auio, rw);
	if (aresid)
		*aresid = auio.uio_resid;
	else
		if (auio.uio_resid)
			error = EIO;
	return (error);
E 11
I 3
}

D 11
writev()
E 11
I 11
rwip(ip, uio, rw)
	register struct inode *ip;
	register struct uio *uio;
	enum uio_rw rw;
E 11
{
I 11
	dev_t dev = (dev_t)ip->i_rdev;
	struct buf *bp;
	struct fs *fs;
	daddr_t lbn, bn;
D 19
	register int on, type;
	register unsigned n;
E 19
I 19
	register int n, on, type;
E 19
	int size;
	long bsize;
	extern int mem_no;
	int error = 0;
E 11

I 11
	if (rw != UIO_READ && rw != UIO_WRITE)
		panic("rwip");
I 23
	if (rw == UIO_READ && uio->uio_resid == 0)
		return (0);
E 23
	if (uio->uio_offset < 0 &&
	    ((ip->i_mode&IFMT) != IFCHR || mem_no != major(dev)))
D 22
		return (EINVAL); if (rw == UIO_READ)
E 22
I 22
		return (EINVAL);
	if (rw == UIO_READ)
E 22
		ip->i_flag |= IACC;
	type = ip->i_mode&IFMT;
	if (type == IFCHR) {
D 35
#ifdef QUOTA
		register c = uio->uio_resid;
#endif
E 35
		if (rw == UIO_READ)
D 16
			(*cdevsw[major(dev)].d_read)(dev, uio);
E 16
I 16
			u.u_error = (*cdevsw[major(dev)].d_read)(dev, uio);
E 16
		else {
			ip->i_flag |= IUPD|ICHG;
D 16
			(*cdevsw[major(dev)].d_write)(dev, uio);
E 16
I 16
			u.u_error = (*cdevsw[major(dev)].d_write)(dev, uio);
E 16
		}
D 35
		CHARGE(sc_tio * (c - uio->uio_resid));
E 35
		return (u.u_error);
	}
I 22
	if (uio->uio_resid == 0)
D 23
		return;
E 23
I 23
		return (0);
E 23
E 22
	if (rw == UIO_WRITE && type == IFREG &&
D 12
	    uio->uio_offset + uio->uio_resid > u.u_limit[LIM_FSIZE]) {
E 12
I 12
	    uio->uio_offset + uio->uio_resid >
	      u.u_rlimit[RLIMIT_FSIZE].rlim_cur) {
E 12
		psignal(u.u_procp, SIGXFSZ);
		return (EMFILE);
	}
	if (type != IFBLK) {
		dev = ip->i_dev;
		fs = ip->i_fs;
		bsize = fs->fs_bsize;
	} else
		bsize = BLKDEV_IOSIZE;
	do {
		lbn = uio->uio_offset / bsize;
		on = uio->uio_offset % bsize;
		n = MIN((unsigned)(bsize - on), uio->uio_resid);
		if (type != IFBLK) {
			if (rw == UIO_READ) {
				int diff = ip->i_size - uio->uio_offset;
				if (diff <= 0)
					return (0);
				if (diff < n)
					n = diff;
			}
I 26
D 27
			u.u_error = 0;		/* XXX */
E 27
E 26
			bn = fsbtodb(fs,
			    bmap(ip, lbn, rw == UIO_WRITE ? B_WRITE: B_READ, (int)(on+n)));
			if (u.u_error || rw == UIO_WRITE && (long)bn<0)
				return (u.u_error);
			if (rw == UIO_WRITE && uio->uio_offset + n > ip->i_size &&
			   (type == IFDIR || type == IFREG || type == IFLNK))
				ip->i_size = uio->uio_offset + n;
			size = blksize(fs, ip, lbn);
		} else {
			bn = lbn * (BLKDEV_IOSIZE/DEV_BSIZE);
			rablock = bn + (BLKDEV_IOSIZE/DEV_BSIZE);
			rasize = size = bsize;
		}
		if (rw == UIO_READ) {
			if ((long)bn<0) {
				bp = geteblk(size);
				clrbuf(bp);
			} else if (ip->i_lastr + 1 == lbn)
				bp = breada(dev, bn, size, rablock, rasize);
			else
				bp = bread(dev, bn, size);
			ip->i_lastr = lbn;
		} else {
			int i, count;
I 18
			extern struct cmap *mfind();
E 18

			count = howmany(size, DEV_BSIZE);
			for (i = 0; i < count; i += CLSIZE)
				if (mfind(dev, bn + i))
					munhash(dev, bn + i);
			if (n == bsize) 
				bp = getblk(dev, bn, size);
			else
				bp = bread(dev, bn, size);
		}
		n = MIN(n, size - bp->b_resid);
		if (bp->b_flags & B_ERROR) {
			error = EIO;
			brelse(bp);
			goto bad;
		}
		u.u_error =
D 18
		    uiomove(bp->b_un.b_addr+on, (u_int)n, rw, uio);
E 18
I 18
D 20
		    uiomove(bp->b_un.b_addr+on, n, rw, uio);
E 20
I 20
D 21
		    (void) uiomove(bp->b_un.b_addr+on, n, rw, uio);
E 21
I 21
		    uiomove(bp->b_un.b_addr+on, n, rw, uio);
E 21
E 20
E 18
		if (rw == UIO_READ) {
			if (n + on == bsize || uio->uio_offset == ip->i_size)
				bp->b_flags |= B_AGE;
			brelse(bp);
		} else {
			if ((ip->i_mode&IFMT) == IFDIR)
				bwrite(bp);
			else if (n + on == bsize) {
				bp->b_flags |= B_AGE;
				bawrite(bp);
			} else
				bdwrite(bp);
			ip->i_flag |= IUPD|ICHG;
			if (u.u_ruid != 0)
				ip->i_mode &= ~(ISUID|ISGID);
		}
	} while (u.u_error == 0 && uio->uio_resid > 0 && n != 0);
bad:
	return (error);
E 11
}

I 11
uiomove(cp, n, rw, uio)
	register caddr_t cp;
	register int n;
	enum uio_rw rw;
	register struct uio *uio;
{
	register struct iovec *iov;
D 27
	int error;
E 27
	u_int cnt;
I 27
	int error = 0;
E 27

	while (n > 0 && uio->uio_resid) {
		iov = uio->uio_iov;
		cnt = iov->iov_len;
		if (cnt == 0) {
			uio->uio_iov++;
			uio->uio_iovcnt--;
			continue;
		}
		if (cnt > n)
			cnt = n;
		switch (uio->uio_segflg) {

		case 0:
		case 2:
			if (rw == UIO_READ)
				error = copyout(cp, iov->iov_base, cnt);
			else
				error = copyin(iov->iov_base, cp, cnt);
			if (error)
D 28
				return (error);
E 28
I 28
D 29
				return (EFAULT);	/* XXX */
E 29
I 29
				return (error);
E 29
E 28
			break;

		case 1:
			if (rw == UIO_READ)
				bcopy((caddr_t)cp, iov->iov_base, cnt);
			else
				bcopy(iov->iov_base, (caddr_t)cp, cnt);
			break;
		}
		iov->iov_base += cnt;
		iov->iov_len -= cnt;
		uio->uio_resid -= cnt;
		uio->uio_offset += cnt;
		cp += cnt;
		n -= cnt;
	}
	return (error);
}

E 36
E 11
E 3
/*
I 11
D 36
 * Give next character to user as result of read.
 */
ureadc(c, uio)
	register int c;
	register struct uio *uio;
{
	register struct iovec *iov;

again:
	if (uio->uio_iovcnt == 0)
		panic("ureadc");
	iov = uio->uio_iov;
	if (iov->iov_len <= 0 || uio->uio_resid <= 0) {
		uio->uio_iovcnt--;
		uio->uio_iov++;
		goto again;
	}
	switch (uio->uio_segflg) {

	case 0:
		if (subyte(iov->iov_base, c) < 0)
			return (EFAULT);
		break;

	case 1:
		*iov->iov_base = c;
		break;

	case 2:
		if (suibyte(iov->iov_base, c) < 0)
			return (EFAULT);
		break;
	}
	iov->iov_base++;
	iov->iov_len--;
	uio->uio_resid--;
	uio->uio_offset++;
	return (0);
}

I 20
#ifdef notdef
E 20
/*
 * Get next character written in by user from uio.
 */
uwritec(uio)
	struct uio *uio;
{
	register struct iovec *iov;
	register int c;

again:
	if (uio->uio_iovcnt <= 0 || uio->uio_resid <= 0)
		panic("uwritec");
	iov = uio->uio_iov;
	if (iov->iov_len == 0) {
		uio->uio_iovcnt--;
		uio->uio_iov++;
		goto again;
	}
	switch (uio->uio_segflg) {

	case 0:
		c = fubyte(iov->iov_base);
		break;

	case 1:
		c = *iov->iov_base & 0377;
		break;

	case 2:
		c = fuibyte(iov->iov_base);
		break;
	}
	if (c < 0)
		return (-1);
	iov->iov_base++;
	iov->iov_len--;
	uio->uio_resid--;
	uio->uio_offset++;
	return (c & 0377);
}
I 20
#endif
E 20

/*
E 36
E 11
 * Ioctl system call
D 5
 * Check legality, execute common code, and switch out to individual
 * device routine.
E 5
I 5
D 36
 * Check legality, execute common code,
 * and switch out to individual device routine.
E 36
E 5
 */
ioctl()
{
	register struct file *fp;
D 5
	register struct inode *ip;
	register struct a {
E 5
I 5
	struct a {
E 5
		int	fdes;
		int	cmd;
		caddr_t	cmarg;
	} *uap;
D 5
	register dev_t dev;
	register fmt;
E 5
I 5
D 11
	register int com, size;
E 11
I 11
	register int com;
	register u_int size;
E 11
D 61
	char data[IOCPARM_MASK+1];
E 61
I 61
D 63
	struct buf *bp = 0;
E 63
I 63
	caddr_t memp = 0;
E 63
#define STK_PARAMS	128
D 64
	char buf[STK_PARAMS];
	caddr_t data = buf;
E 64
I 64
	char stkbuf[STK_PARAMS];
	caddr_t data = stkbuf;
E 64
E 61
E 5

	uap = (struct a *)u.u_ap;
D 46
	if ((fp = getf(uap->fdes)) == NULL)
		return;
E 46
I 46
	GETF(fp, uap->fdes);
E 46
	if ((fp->f_flag & (FREAD|FWRITE)) == 0) {
		u.u_error = EBADF;
		return;
	}
D 5
	if (uap->cmd==FIOCLEX) {
E 5
I 5
	com = uap->cmd;

D 6
#ifndef ONLYNEWIOCTLS
E 6
I 6
D 36
#ifndef NOCOMPAT
E 36
I 36
D 42
#if defined(vax) && !defined(NOCOMPAT)
E 42
I 42
#if defined(vax) && defined(COMPAT)
E 42
E 36
E 6
	/*
	 * Map old style ioctl's into new for the
	 * sake of backwards compatibility (sigh).
	 */
	if ((com&~0xffff) == 0) {
		com = mapioctl(com);
		if (com == 0) {
			u.u_error = EINVAL;
			return;
		}
	}
#endif
	if (com == FIOCLEX) {
E 5
D 25
		u.u_pofile[uap->fdes] |= EXCLOSE;
E 25
I 25
		u.u_pofile[uap->fdes] |= UF_EXCLOSE;
E 25
		return;
	}
D 5
	if (uap->cmd==FIONCLEX) {
E 5
I 5
	if (com == FIONCLEX) {
E 5
D 25
		u.u_pofile[uap->fdes] &= ~EXCLOSE;
E 25
I 25
		u.u_pofile[uap->fdes] &= ~UF_EXCLOSE;
E 25
		return;
	}
D 3
	if (fp->f_flag & FSOCKET) {
E 3
I 3
D 5
	if (fp->f_type == DTYPE_SOCKET) {
E 3
		soioctl(fp->f_socket, uap->cmd, uap->cmarg);
E 5
I 5

	/*
	 * Interpret high order word to find
	 * amount of data to be copied to/from the
	 * user's address space.
D 11
	 * (this'll have to change if we have in+out ioctls)
E 11
	 */
D 61
	size = (com &~ (IOC_INOUT|IOC_VOID)) >> 16;
	if (size > sizeof (data)) {
E 61
I 61
	size = IOCPARM_LEN(com);
	if (size > IOCPARM_MAX) {
E 61
		u.u_error = EFAULT;
E 5
		return;
	}
I 61
D 64
	if (size > sizeof (buf)) {
E 64
I 64
	if (size > sizeof (stkbuf)) {
E 64
D 63
		bp = geteblk(IOCPARM_MAX);		/* XXX */
		data = bp->b_un.b_addr;
E 63
I 63
D 66
		memp = (caddr_t)malloc(IOCPARM_MAX, M_IOCTLOPS, M_WAITOK);
E 66
I 66
		memp = (caddr_t)malloc((u_long)IOCPARM_MAX, M_IOCTLOPS,
		    M_WAITOK);
E 66
		data = memp;
E 63
	}
E 61
D 5
	ip = fp->f_inode;
	fmt = ip->i_mode & IFMT;
	if (fmt != IFCHR) {
		if (uap->cmd==FIONREAD && (fmt == IFREG || fmt == IFDIR)) {
			off_t nread = ip->i_size - fp->f_offset;
E 5
I 5
D 6
	if ((com&IOC_IN) && size) {
E 6
I 6
D 30
	if (com&IOC_IN && size) {
E 6
D 11
		if (copyin(uap->cmarg, (caddr_t)data, size)) {
E 11
I 11
D 29
		if (copyin(uap->cmarg, (caddr_t)data, (u_int)size)) {
E 11
			u.u_error = EFAULT;
E 29
I 29
		u.u_error = copyin(uap->cmarg, (caddr_t)data, (u_int)size);
		if (u.u_error)
E 29
			return;
D 29
		}
E 29
	} else
		*(caddr_t *)data = uap->cmarg;
	/*
	 * Zero the buffer on the stack so the user
	 * always gets back something deterministic.
	 */
	if ((com&IOC_OUT) && size)
E 30
I 30
	if (com&IOC_IN) {
		if (size) {
			u.u_error =
D 61
			    copyin(uap->cmarg, (caddr_t)data, (u_int)size);
E 61
I 61
			    copyin(uap->cmarg, data, (u_int)size);
E 61
D 63
			if (u.u_error)
E 63
I 63
			if (u.u_error) {
				if (memp)
					free(memp, M_IOCTLOPS);
E 63
				return;
I 63
			}
E 63
		} else
			*(caddr_t *)data = uap->cmarg;
	} else if ((com&IOC_OUT) && size)
		/*
		 * Zero the buffer on the stack so the user
		 * always gets back something deterministic.
		 */
E 30
D 61
		bzero((caddr_t)data, size);
E 61
I 61
		bzero(data, size);
E 61
I 32
	else if (com&IOC_VOID)
		*(caddr_t *)data = uap->cmarg;
E 32
E 5

D 5
			if (copyout((caddr_t)&nread, uap->cmarg, sizeof(off_t)))
				u.u_error = EFAULT;
		} else if (uap->cmd == FIONBIO || uap->cmd == FIOASYNC)
E 5
I 5
D 36
	if (fp->f_type == DTYPE_SOCKET)
D 17
		soioctl(fp->f_socket, com, data);
E 17
I 17
		u.u_error = soioctl(fp->f_socket, com, data);
E 17
	else {
		register struct inode *ip = fp->f_inode;
		int fmt = ip->i_mode & IFMT;
		dev_t dev;
E 36
I 36
	switch (com) {
E 36

D 36
		if (fmt != IFCHR) {
			if (com == FIONREAD && (fmt == IFREG || fmt == IFDIR)) {
				*(off_t *)data = ip->i_size - fp->f_offset;
				goto returndata;
			}
			if (com != FIONBIO && com != FIOASYNC)
				u.u_error = ENOTTY;
E 5
			return;
D 5
		else
			u.u_error = ENOTTY;
		return;
E 5
I 5
		}
		dev = ip->i_rdev;
		u.u_r.r_val1 = 0;
D 14
		if ((u.u_procp->p_flag&SNUSIG) && setjmp(u.u_qsav)) {
E 14
I 14
		if ((u.u_procp->p_flag&SNUSIG) && setjmp(&u.u_qsave)) {
E 14
			u.u_eosys = RESTARTSYS;
			return;
		}
D 17
		(*cdevsw[major(dev)].d_ioctl)(dev, com, data, 0);
E 17
I 17
D 33
		u.u_error = (*cdevsw[major(dev)].d_ioctl)(dev, com, data, 0);
E 33
I 33
D 34
		u.u_error = (*cdevsw[major(dev)].d_ioctl)(dev, com, data, 
								fp->f_flag);
E 34
I 34
		u.u_error =
		   (*cdevsw[major(dev)].d_ioctl)(dev, com, data, fp->f_flag);
E 34
E 33
E 17
E 5
	}
E 36
I 36
	case FIONBIO:
		u.u_error = fset(fp, FNDELAY, *(int *)data);
D 61
		return;
E 61
I 61
		break;
E 61
E 36
D 5
	dev = ip->i_rdev;
	u.u_r.r_val1 = 0;
	if ((u.u_procp->p_flag&SNUSIG) && setjmp(u.u_qsav)) {
		u.u_eosys = RESTARTSYS;
		return;
	}
	(*cdevsw[major(dev)].d_ioctl)(dev, uap->cmd, uap->cmarg, 0);
E 5
I 5

D 36
returndata:
E 36
I 36
	case FIOASYNC:
		u.u_error = fset(fp, FASYNC, *(int *)data);
D 61
		return;
E 61
I 61
		break;
E 61

	case FIOSETOWN:
		u.u_error = fsetown(fp, *(int *)data);
D 61
		return;
E 61
I 61
		break;
E 61

	case FIOGETOWN:
		u.u_error = fgetown(fp, (int *)data);
D 61
		return;
E 61
I 61
		break;
	default:
		if (setjmp(&u.u_qsave))
			u.u_error = EINTR;
		else
			u.u_error = (*fp->f_ops->fo_ioctl)(fp, com, data);
		/*
		 * Copy any data to user, size was
		 * already set and checked above.
		 */
		if (u.u_error == 0 && (com&IOC_OUT) && size)
			u.u_error = copyout(data, uap->cmarg, (u_int)size);
		break;
E 61
	}
D 61
	u.u_error = (*fp->f_ops->fo_ioctl)(fp, com, data);
E 36
	/*
	 * Copy any data to user, size was
	 * already set and checked above.
	 */
D 6
	if ((com&IOC_OUT) && size && copyout(data, uap->cmarg, size))
		u.u_error = EFAULT;
E 6
I 6
D 11
	if (u.u_error == 0 && com&IOC_OUT)
		if (size && copyout(data, uap->cmarg, size))
E 11
I 11
D 29
	if (u.u_error == 0 && (com&IOC_OUT))
		if (size && copyout(data, uap->cmarg, (u_int)size))
E 11
			u.u_error = EFAULT;
E 29
I 29
	if (u.u_error == 0 && (com&IOC_OUT) && size)
		u.u_error = copyout(data, uap->cmarg, (u_int)size);
E 61
I 61
D 63
	if (bp)
		brelse(bp);
E 63
I 63
	if (memp)
		free(memp, M_IOCTLOPS);
E 63
E 61
E 29
E 6
E 5
}

I 36
int	unselect();
int	nselcoll;
I 49

E 49
E 36
/*
I 49
D 55
 * Select uses bit masks of file descriptors in ints.
 * These macros manipulate such bit fields (the filesystem macros use chars).
 */
#define NBI		(sizeof(int) * NBBY)		/* bits per int */
#define	NI		howmany(NOFILE, NBI)
#define	tbit(p, n)	((p)[(n)/NBI] & (1 << ((n) % NBI)))
#define	sbit(p, n)	((p)[(n)/NBI] |= (1 << ((n) % NBI)))
#define	cbit(p, n)	((p)[(n)/NBI] &= ~(1 << ((n) % NBI)))

/*
E 55
E 49
D 36
 * Do nothing specific version of line
 * discipline specific ioctl command.
E 36
I 36
 * Select system call.
E 36
 */
I 36
select()
{
	register struct uap  {
		int	nd;
D 49
		long	*in, *ou, *ex;
E 49
I 49
D 55
		int	*in, *ou, *ex;
E 55
I 55
		fd_set	*in, *ou, *ex;
E 55
E 49
		struct	timeval *tv;
	} *uap = (struct uap *)u.u_ap;
D 49
	int ibits[3], obits[3];
E 49
I 49
D 55
	int ibits[3][NI], obits[3][NI];
E 55
I 55
	fd_set ibits[3], obits[3];
E 55
E 49
	struct timeval atv;
D 40
	int s, ncoll;
E 40
I 40
D 49
	int s, ncoll, mask;
E 49
I 49
	int s, ncoll, ni;
E 49
E 40
	label_t lqsave;

D 49
	obits[0] = obits[1] = obits[2] = 0;
E 49
I 49
D 57
	bzero(ibits, sizeof(ibits));
	bzero(obits, sizeof(obits));
E 57
I 57
	bzero((caddr_t)ibits, sizeof(ibits));
	bzero((caddr_t)obits, sizeof(obits));
E 57
E 49
	if (uap->nd > NOFILE)
		uap->nd = NOFILE;	/* forgiving, if slightly wrong */
I 40
D 49
	mask = (1 << uap->nd) - 1;
E 49
I 49
D 55
	ni = howmany(uap->nd, NBI);
E 55
I 55
	ni = howmany(uap->nd, NFDBITS);
E 55
E 49
E 40

#define	getbits(name, x) \
	if (uap->name) { \
D 49
		u.u_error = copyin((caddr_t)uap->name, (caddr_t)&ibits[x], \
		    sizeof (ibits[x])); \
E 49
I 49
D 55
		u.u_error = copyin((caddr_t)uap->name, (caddr_t)ibits[x], \
		    ni * sizeof(int)); \
E 55
I 55
		u.u_error = copyin((caddr_t)uap->name, (caddr_t)&ibits[x], \
D 57
		    ni * sizeof(fd_mask)); \
E 57
I 57
		    (unsigned)(ni * sizeof(fd_mask))); \
E 57
E 55
E 49
		if (u.u_error) \
			goto done; \
I 40
D 49
		ibits[x] &= mask; \
E 40
	} else \
		ibits[x] = 0;
E 49
I 49
	}
E 49
	getbits(in, 0);
	getbits(ou, 1);
	getbits(ex, 2);
#undef	getbits

	if (uap->tv) {
		u.u_error = copyin((caddr_t)uap->tv, (caddr_t)&atv,
			sizeof (atv));
		if (u.u_error)
			goto done;
		if (itimerfix(&atv)) {
			u.u_error = EINVAL;
			goto done;
		}
D 50
		s = spl7(); timevaladd(&atv, &time); splx(s);
E 50
I 50
		s = splhigh(); timevaladd(&atv, &time); splx(s);
E 50
	}
retry:
	ncoll = nselcoll;
	u.u_procp->p_flag |= SSEL;
D 49
	u.u_r.r_val1 = selscan(ibits, obits);
E 49
I 49
	u.u_r.r_val1 = selscan(ibits, obits, uap->nd);
E 49
	if (u.u_error || u.u_r.r_val1)
		goto done;
D 50
	s = spl6();
E 50
I 50
	s = splhigh();
E 50
D 38
	if (uap->tv && timercmp(&time, &atv, >=)) {
E 38
I 38
	/* this should be timercmp(&time, &atv, >=) */
	if (uap->tv && (time.tv_sec > atv.tv_sec ||
	    time.tv_sec == atv.tv_sec && time.tv_usec >= atv.tv_usec)) {
E 38
		splx(s);
		goto done;
	}
	if ((u.u_procp->p_flag & SSEL) == 0 || nselcoll != ncoll) {
D 65
		u.u_procp->p_flag &= ~SSEL;
E 65
		splx(s);
		goto retry;
	}
	u.u_procp->p_flag &= ~SSEL;
	if (uap->tv) {
		lqsave = u.u_qsave;
		if (setjmp(&u.u_qsave)) {
			untimeout(unselect, (caddr_t)u.u_procp);
			u.u_error = EINTR;
			splx(s);
			goto done;
		}
		timeout(unselect, (caddr_t)u.u_procp, hzto(&atv));
	}
	sleep((caddr_t)&selwait, PZERO+1);
	if (uap->tv) {
		u.u_qsave = lqsave;
		untimeout(unselect, (caddr_t)u.u_procp);
	}
	splx(s);
	goto retry;
done:
I 65
	u.u_procp->p_flag &= ~SSEL;
E 65
#define	putbits(name, x) \
	if (uap->name) { \
D 49
		int error = copyout((caddr_t)&obits[x], (caddr_t)uap->name, \
		    sizeof (obits[x])); \
E 49
I 49
D 55
		int error = copyout((caddr_t)obits[x], (caddr_t)uap->name, \
		    ni * sizeof(int)); \
E 55
I 55
		int error = copyout((caddr_t)&obits[x], (caddr_t)uap->name, \
D 57
		    ni * sizeof(fd_mask)); \
E 57
I 57
		    (unsigned)(ni * sizeof(fd_mask))); \
E 57
E 55
E 49
		if (error) \
			u.u_error = error; \
	}
D 53
	putbits(in, 0);
	putbits(ou, 1);
	putbits(ex, 2);
E 53
I 53
D 56
	if (u.u_error != EINTR) {
E 56
I 56
	if (u.u_error == 0) {
E 56
		putbits(in, 0);
		putbits(ou, 1);
		putbits(ex, 2);
E 53
#undef putbits
I 53
	}
E 53
}

unselect(p)
	register struct proc *p;
{
D 50
	register int s = spl6();
E 50
I 50
	register int s = splhigh();
E 50

	switch (p->p_stat) {

	case SSLEEP:
		setrun(p);
		break;

	case SSTOP:
		unsleep(p);
		break;
	}
	splx(s);
}

D 49
selscan(ibits, obits)
	int *ibits, *obits;
E 49
I 49
selscan(ibits, obits, nfd)
D 55
	int (*ibits)[NI], (*obits)[NI];
E 55
I 55
	fd_set *ibits, *obits;
E 55
E 49
{
D 49
	register int which, bits, i;
E 49
I 49
D 55
	register int which, bits, i, j;
E 55
I 55
	register int which, i, j;
	register fd_mask bits;
E 55
E 49
	int flag;
	struct file *fp;
	int n = 0;

	for (which = 0; which < 3; which++) {
D 49
		bits = ibits[which];
		obits[which] = 0;
E 49
		switch (which) {

		case 0:
			flag = FREAD; break;

		case 1:
			flag = FWRITE; break;

		case 2:
			flag = 0; break;
		}
D 49
		while (i = ffs(bits)) {
			bits &= ~(1<<(i-1));
			fp = u.u_ofile[i-1];
			if (fp == NULL) {
				u.u_error = EBADF;
				break;
			}
			if ((*fp->f_ops->fo_select)(fp, flag)) {
				obits[which] |= (1<<(i-1));
				n++;
E 49
I 49
D 55
		for (i = 0; i < nfd; i += NBI) {
			bits = ibits[which][i/NBI];
E 55
I 55
		for (i = 0; i < nfd; i += NFDBITS) {
			bits = ibits[which].fds_bits[i/NFDBITS];
E 55
			while ((j = ffs(bits)) && i + --j < nfd) {
				bits &= ~(1 << j);
				fp = u.u_ofile[i + j];
				if (fp == NULL) {
					u.u_error = EBADF;
					break;
				}
				if ((*fp->f_ops->fo_select)(fp, flag)) {
D 55
					sbit(obits[which], i + j);
E 55
I 55
					FD_SET(i + j, &obits[which]);
E 55
					n++;
				}
E 49
			}
		}
	}
	return (n);
}

E 36
/*ARGSUSED*/
D 5
nullioctl(tp, cmd, addr)
E 5
I 5
D 36
nullioctl(tp, cmd, data, flags)
E 5
	struct tty *tp;
D 5
	caddr_t addr;
E 5
I 5
	char *data;
	int flags;
E 36
I 36
seltrue(dev, flag)
	dev_t dev;
	int flag;
E 36
E 5
{

I 5
D 36
#ifdef lint
	tp = tp; data = data; flags = flags;
#endif
E 5
D 17
	return (cmd);
E 17
I 17
	return (-1);
E 36
I 36
	return (1);
E 36
E 17
D 11
}

/*
D 10
 * Read the file corresponding to
 * the inode pointed at by the argument.
 * The actual read arguments are found
 * in the variables:
 *	u_base		core address for destination
 *	u_offset	byte offset in file
 *	u_count		number of bytes to read
 *	u_segflg	read to kernel/user/user I
 */
readi(ip)
	register struct inode *ip;
{
	struct buf *bp;
	struct fs *fs;
	dev_t dev;
	daddr_t lbn, bn;
	off_t diff;
	register int on, type;
	register unsigned n;
	int size;
	long bsize;
	extern int mem_no;

	if (u.u_count == 0)
		return;
	dev = (dev_t)ip->i_rdev;
	if (u.u_offset < 0 && ((ip->i_mode&IFMT) != IFCHR ||
	    mem_no != major(dev))) {
		u.u_error = EINVAL;
		return;
	}
	ip->i_flag |= IACC;
	type = ip->i_mode&IFMT;
	if (type == IFCHR) {
I 2
		register c = u.u_count;
E 2
D 8
		(*cdevsw[major(dev)].d_read)(dev);
I 2
		CHARGE(sc_tio * (c - u.u_count));
E 8
I 8
		struct uio auio;
		struct iovec aiov;
		auio.uio_iov = &aiov;
		auio.uio_iovcnt = 1;
		aiov.iov_base = u.u_base;
		aiov.iov_len = u.u_count;
		auio.uio_offset = u.u_offset;
		auio.uio_segflg = u.u_segflg;
		auio.uio_resid = u.u_count;
		(*cdevsw[major(dev)].d_read)(dev, &auio);
		CHARGE(sc_tio * (c - auio.uio_resid));
		u.u_count = auio.uio_resid;
E 8
E 2
		return;
	}
	if (type != IFBLK) {
		dev = ip->i_dev;
		fs = ip->i_fs;
		bsize = fs->fs_bsize;
	} else
		bsize = BLKDEV_IOSIZE;
	do {
		lbn = u.u_offset / bsize;
		on = u.u_offset % bsize;
		n = MIN((unsigned)(bsize - on), u.u_count);
		if (type != IFBLK) {
			diff = ip->i_size - u.u_offset;
			if (diff <= 0)
				return;
			if (diff < n)
				n = diff;
			bn = fsbtodb(fs, bmap(ip, lbn, B_READ));
			if (u.u_error)
				return;
			size = blksize(fs, ip, lbn);
		} else {
			size = bsize;
			bn = lbn * (BLKDEV_IOSIZE/DEV_BSIZE);
			rablock = bn + (BLKDEV_IOSIZE/DEV_BSIZE);
			rasize = bsize;
		}
		if ((long)bn<0) {
			bp = geteblk(size);
			clrbuf(bp);
		} else if (ip->i_lastr + 1 == lbn)
			bp = breada(dev, bn, size, rablock, rasize);
		else
			bp = bread(dev, bn, size);
		ip->i_lastr = lbn;
		n = MIN(n, size - bp->b_resid);
		if (n != 0) {
D 6
#ifdef UNFAST
			iomove(bp->b_un.b_addr + on, n, B_READ);
#else
E 6
			if (u.u_segflg != 1) {
				if (copyout(bp->b_un.b_addr+on, u.u_base, n)) {
					u.u_error = EFAULT;
					goto bad;
				}
			} else
				bcopy(bp->b_un.b_addr + on, u.u_base, n);
			u.u_base += n;
			u.u_offset += n;
			u.u_count -= n;
bad:
			;
D 6
#endif
E 6
		}
		if (n + on == bsize || u.u_offset == ip->i_size)
			bp->b_flags |= B_AGE;
		brelse(bp);
	} while (u.u_error == 0 && u.u_count != 0 && n != 0);
}

/*
E 10
 * Write the file corresponding to
 * the inode pointed at by the argument.
 * The actual write arguments are found
 * in the variables:
 *	u_base		core address for source
 *	u_offset	byte offset in file
 *	u_count		number of bytes to write
 *	u_segflg	write to kernel/user/user I
 */
writei(ip)
	register struct inode *ip;
{
	struct buf *bp;
	register struct fs *fs;
	dev_t dev;
	daddr_t lbn, bn;
	register int on, type;
	register unsigned n;
	long bsize;
	int size, i, count;
	extern int mem_no;

	dev = (dev_t)ip->i_rdev;
	if (u.u_offset < 0 && ((ip->i_mode&IFMT) != IFCHR ||
	    mem_no != major(dev)) ) {
		u.u_error = EINVAL;
		return;
	}
	type = ip->i_mode & IFMT;
	if (type == IFCHR) {
		ip->i_flag |= IUPD|ICHG;
I 2
		CHARGE(sc_tio * u.u_count);
E 2
		(*cdevsw[major(dev)].d_write)(dev);
		return;
	}
	if (u.u_count == 0)
		return;
	if ((ip->i_mode & IFMT) == IFREG &&
	    u.u_offset + u.u_count > u.u_limit[LIM_FSIZE]) {
		psignal(u.u_procp, SIGXFSZ);
		u.u_error = EMFILE;
		return;
	}
	if (type!=IFBLK) {
		dev = ip->i_dev;
		fs = ip->i_fs;
		bsize = fs->fs_bsize;
D 4
	} else {
E 4
I 4
	} else
E 4
		bsize = BLKDEV_IOSIZE;
D 4
	}
E 4
	do {
		lbn = u.u_offset / bsize;
		on = u.u_offset % bsize;
		n = MIN((unsigned)(bsize - on), u.u_count);
		if (type != IFBLK) {
			bn = fsbtodb(fs, bmap(ip, lbn, B_WRITE, (int)(on + n)));
D 4
			if ((long)bn<0)
E 4
I 4
			if (u.u_error || (long)bn<0)
E 4
				return;
			if(u.u_offset + n > ip->i_size &&
			   (type == IFDIR || type == IFREG || type == IFLNK))
				ip->i_size = u.u_offset + n;
			size = blksize(fs, ip, lbn);
		} else {
			size = bsize;
			bn = lbn * (BLKDEV_IOSIZE/DEV_BSIZE);
		}
D 4
		if (bn) {
			count = howmany(size, DEV_BSIZE);
			for (i = 0; i < count; i += CLSIZE) {
				if (mfind(dev, bn + i))
					munhash(dev, bn + i);
			}
		}
		if(n == bsize) 
E 4
I 4
		count = howmany(size, DEV_BSIZE);
		for (i = 0; i < count; i += CLSIZE)
			if (mfind(dev, bn + i))
				munhash(dev, bn + i);
		if (n == bsize) 
E 4
			bp = getblk(dev, bn, size);
		else
			bp = bread(dev, bn, size);
D 6
#ifdef UNFAST
		iomove(bp->b_un.b_addr + on, n, B_WRITE);
#else
E 6
		if (u.u_segflg != 1) {
			if (copyin(u.u_base, bp->b_un.b_addr + on, n)) {
				u.u_error = EFAULT;
				goto bad;
			}
		} else
			bcopy(u.u_base, bp->b_un.b_addr + on, n);
		u.u_base += n;
		u.u_offset += n;
		u.u_count -= n;
bad:
		;
D 6
#endif
E 6
		if (u.u_error != 0)
			brelse(bp);
		else {
			if ((ip->i_mode&IFMT) == IFDIR)
				/*
				 * Writing to clear a directory entry.
				 * Must insure the write occurs before
				 * the inode is freed, or may end up
				 * pointing at a new (different) file
				 * if inode is quickly allocated again
				 * and system crashes.
				 */
				bwrite(bp);
			else if (n + on == bsize) {
				bp->b_flags |= B_AGE;
				bawrite(bp);
			} else
				bdwrite(bp);
		}
		ip->i_flag |= IUPD|ICHG;
		if (u.u_ruid != 0)
			ip->i_mode &= ~(ISUID|ISGID);
	} while (u.u_error == 0 && u.u_count != 0);
}

/*
 * Move n bytes at byte location
 * &bp->b_un.b_addr[o] to/from (flag) the
 * user/kernel (u.segflg) area starting at u.base.
 * Update all the arguments by the number
 * of bytes moved.
 */
iomove(cp, n, flag)
	register caddr_t cp;
	register unsigned n;
{
	register int t;

	if (n==0)
		return;
	if (u.u_segflg != 1) {
		if (flag==B_WRITE)
			t = copyin(u.u_base, (caddr_t)cp, n);
		else
			t = copyout((caddr_t)cp, u.u_base, n);
		if (t) {
			u.u_error = EFAULT;
			return;
		}
	} else
		if (flag == B_WRITE)
			bcopy(u.u_base, (caddr_t)cp, n);
		else
			bcopy((caddr_t)cp, u.u_base, n);
	u.u_base += n;
	u.u_offset += n;
	u.u_count -= n;
I 10
}

readip1(ip, base, len, offset, segflg, aresid)
	struct inode *ip;
	caddr_t base;
	int len, offset, segflg;
	int *aresid;
{
	struct uio auio;
	struct iovec aiov;
	int error;

	auio.uio_iov = &aiov;
	auio.uio_iovcnt = 1;
	aiov.iov_base = base;
	aiov.iov_len = len;
	auio.uio_resid = len;
	auio.uio_offset = offset;
	auio.uio_segflg = segflg;
	error = readip(ip, &auio);
	if (aresid)
		*aresid = auio.uio_resid;
	else
		if (auio.uio_resid)
			error = EIO;
	return (error);
E 10
I 7
}

readip(ip, uio)
	register struct inode *ip;
	register struct uio *uio;
{
D 9
	register struct iovec *iov = uio->uio_iov;
E 9
I 9
	register struct iovec *iov;
E 9
	struct buf *bp;
	struct fs *fs;
	dev_t dev;
	daddr_t lbn, bn;
	off_t diff;
	register int on, type;
	register unsigned n;
	int size;
	long bsize;
	extern int mem_no;
	int error = 0;

D 9
	uio->uio_resid = 0;
	if (uio->uio_iovcnt == 0)
		return (0);
E 9
	dev = (dev_t)ip->i_rdev;
	if (uio->uio_offset < 0 &&
D 9
	    ((ip->i_mode&IFMT) != IFCHR || mem_no != major(dev))) {
		error = EINVAL;
		goto bad;
	}
E 9
I 9
	    ((ip->i_mode&IFMT) != IFCHR || mem_no != major(dev)))
		return (EINVAL);
E 9
	ip->i_flag |= IACC;
	type = ip->i_mode&IFMT;
	if (type == IFCHR) {
		register c = u.u_count;
D 9
		error = (*cdevsw[major(dev)].d_read)(dev, uio);
		CHARGE(sc_tio * (c - u.u_count));
		return (error);
E 9
I 9
		(*cdevsw[major(dev)].d_read)(dev, uio);
		CHARGE(sc_tio * (c - uio->uio_resid));
		return (u.u_error);
E 9
	}
	if (type != IFBLK) {
		dev = ip->i_dev;
		fs = ip->i_fs;
		bsize = fs->fs_bsize;
	} else
		bsize = BLKDEV_IOSIZE;
nextiov:
	if (uio->uio_iovcnt == 0)
D 9
		goto getresid;
E 9
I 9
		return (0);
	iov = uio->uio_iov;
E 9
	if (iov->iov_len > 0)
	do {
		lbn = uio->uio_offset / bsize;
		on = uio->uio_offset % bsize;
		n = MIN((unsigned)(bsize - on), iov->iov_len);
		if (type != IFBLK) {
			diff = ip->i_size - uio->uio_offset;
			if (diff <= 0)
				return;
			if (diff < n)
				n = diff;
			bn = fsbtodb(fs, bmap(ip, lbn, B_READ));
			if (u.u_error)
D 9
				goto getresid;
E 9
I 9
				return (u.u_error);
E 9
			size = blksize(fs, ip, lbn);
		} else {
			size = bsize;
			bn = lbn * (BLKDEV_IOSIZE/DEV_BSIZE);
			rablock = bn + (BLKDEV_IOSIZE/DEV_BSIZE);
			rasize = bsize;
		}
		if ((long)bn<0) {
			bp = geteblk(size);
			clrbuf(bp);
		} else if (ip->i_lastr + 1 == lbn)
			bp = breada(dev, bn, size, rablock, rasize);
		else
			bp = bread(dev, bn, size);
		ip->i_lastr = lbn;
		n = MIN(n, size - bp->b_resid);
		if (n != 0) {
			if (uio->uio_segflg != 1) {
				if (copyout(bp->b_un.b_addr+on, iov->iov_base, n)) {
D 9
					error = EFAULT;
					goto getresid;
E 9
I 9
					brelse(bp);
					return (EFAULT);
E 9
				}
			} else
				bcopy(bp->b_un.b_addr + on, iov->iov_base, n);
			iov->iov_base += n;
			uio->uio_offset += n;
			iov->iov_len -= n;
D 9
bad:
			;
E 9
I 9
			uio->uio_resid -= n;
E 9
		}
		if (n + on == bsize || uio->uio_offset == ip->i_size)
			bp->b_flags |= B_AGE;
		brelse(bp);
	} while (u.u_error == 0 && iov->iov_len != 0 && n != 0);
D 9
	if (u.u_error == 0 && n > 0) {
		iov++;
E 9
I 9
	if (u.u_error == 0 && iov->iov_len == 0) {
		uio->uio_iov++;
E 9
		uio->uio_iovcnt--;
		goto nextiov;
	}
D 9
getresid:
	while (uio->uio_iovcnt > 0) {
		uio->uio_resid += iov->iov_len;
		iov++;
		uio->uio_iovcnt--;
	}
E 9
	return (error);
I 9
}

uiomove(cp, n, dir, uio)
	register caddr_t cp;
	register unsigned n;
	enum uio_direction dir;
	struct uio *uio;
{
	register struct iovec *iov;
	int bad, cnt;

	if (n == 0)
		return (0);
	if (uio->uio_segflg != 1) {
		if (dir == UIO_READFROM)
#ifdef notdef
			bad = copyuin(uio, (caddr_t)cp, n);
#else
			panic("uiomove");
#endif
		else
			bad = copyuout((caddr_t)cp, n, uio);
		if (bad)
			return (EFAULT);
	} else {
		while (n > 0 && uio->uio_iovcnt) {
			iov = uio->uio_iov;
			cnt = iov->iov_len;
			if (cnt > n)
				cnt = n;
			if (dir == UIO_READFROM)
				bcopy(iov->iov_base, (caddr_t)cp, cnt);
			else
				bcopy((caddr_t)cp, iov->iov_base, cnt);
			iov->iov_base += cnt;
			iov->iov_len -= cnt;
			uio->uio_resid -= cnt;
			n -= cnt;
		}
	}
	return (0);
E 11
E 9
E 7
}
I 13

D 36
ostty()
E 36
I 36
selwakeup(p, coll)
	register struct proc *p;
	int coll;
E 36
{

I 36
	if (coll) {
		nselcoll++;
		wakeup((caddr_t)&selwait);
	}
	if (p) {
D 50
		int s = spl6();
E 50
I 50
		int s = splhigh();
E 50
D 48
		if (p->p_wchan == (caddr_t)&selwait)
			setrun(p);
		else if (p->p_flag & SSEL)
E 48
I 48
		if (p->p_wchan == (caddr_t)&selwait) {
			if (p->p_stat == SSLEEP)
				setrun(p);
			else
				unsleep(p);
		} else if (p->p_flag & SSEL)
E 48
			p->p_flag &= ~SSEL;
		splx(s);
	}
E 36
}
D 41

D 36
ogtty()
E 36
I 36
fstat()
E 36
{
I 36
	register struct file *fp;
	register struct a {
		int	fdes;
		struct	stat *sb;
	} *uap;
	struct stat ub;
E 36

I 36
	uap = (struct a *)u.u_ap;
	fp = getf(uap->fdes);
	if (fp == 0)
		return;
	u.u_error = (*fp->f_ops->fo_stat)(fp, &ub);
	if (u.u_error == 0)
		u.u_error = copyout(&ub, uap->sb, sizeof (ub));
E 36
}
E 41
E 13
E 1
