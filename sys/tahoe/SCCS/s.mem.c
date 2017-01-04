h40331
s 00018/00013/00128
d D 7.1 88/05/21 18:36:00 karels 5 4
c bring up to revision 7 for tahoe release
e
s 00001/00001/00140
d D 1.4 86/12/15 20:27:51 sam 4 3
c lint
e
s 00003/00002/00138
d D 1.3 86/07/16 08:27:37 sam 3 2
c purge min
e
s 00002/00002/00138
d D 1.2 86/01/05 18:42:36 sam 2 1
c 1st working version
e
s 00140/00000/00000
d D 1.1 85/07/21 20:20:52 sam 1 0
c date and time created 85/07/21 20:20:52 by sam
e
u
U
t
T
I 1
D 5
/*	%M%	%I%	%E%	*/
E 5
I 5
/*
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * Memory special file
 */

D 5
#include "../machine/pte.h"
E 5
I 5
#include "param.h"
#include "dir.h"
#include "user.h"
#include "conf.h"
#include "buf.h"
#include "systm.h"
#include "vm.h"
#include "cmap.h"
#include "uio.h"
E 5

D 5
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/conf.h"
#include "../h/buf.h"
#include "../h/systm.h"
#include "../h/vm.h"
#include "../h/cmap.h"
#include "../h/uio.h"

D 2
#include "../machine/mtpr.h"
E 2
I 2
#include "../tahoe/mtpr.h"
E 5
I 5
#include "pte.h"
#include "mtpr.h"
E 5
E 2

mmread(dev, uio)
	dev_t dev;
	struct uio *uio;
{

	return (mmrw(dev, uio, UIO_READ));
}

mmwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{

	return (mmrw(dev, uio, UIO_WRITE));
}

mmrw(dev, uio, rw)
	dev_t dev;
	struct uio *uio;
	enum uio_rw rw;
{
	register int o;
	register u_int c, v;
	register struct iovec *iov;
	int error = 0;
D 4
	extern int vmembeg, vmemend;
E 4
I 4
	extern caddr_t vmembeg, vmemend;
E 4


	while (uio->uio_resid > 0 && error == 0) {
		iov = uio->uio_iov;
		if (iov->iov_len == 0) {
			uio->uio_iov++;
			uio->uio_iovcnt--;
			if (uio->uio_iovcnt < 0)
				panic("mmrw");
			continue;
		}
		switch (minor(dev)) {

/* minor device 0 is physical memory */
		case 0:
			v = btop(uio->uio_offset);
			if (v >= physmem)
				goto fault;
			*(int *)mmap = v | PG_V |
				(rw == UIO_READ ? PG_KR : PG_KW);
D 2
			mtpr(vmmap, TBIS);
E 2
I 2
			mtpr(TBIS, vmmap);
E 2
			o = (int)uio->uio_offset & PGOFSET;
D 3
			c = min((u_int)(NBPG - o), (u_int)iov->iov_len);
			c = min(c, (u_int)(NBPG - ((int)iov->iov_base&PGOFSET)));
E 3
I 3
			c = (u_int)(NBPG - ((int)iov->iov_base & PGOFSET));
			c = MIN(c, (u_int)(NBPG - o));
			c = MIN(c, (u_int)iov->iov_len);
E 3
			error = uiomove((caddr_t)&vmmap[o], (int)c, rw, uio);
			continue;

/* minor device 1 is kernel memory */
		case 1:
			if ((caddr_t)uio->uio_offset < (caddr_t)&vmembeg &&
			    (caddr_t)uio->uio_offset + uio->uio_resid >= (caddr_t)&vmembeg)
				goto fault;
			if ((caddr_t)uio->uio_offset >= (caddr_t)&vmembeg &&
			    (caddr_t)uio->uio_offset < (caddr_t)&vmemend)
				goto fault;
			c = iov->iov_len;
			if (!kernacc((caddr_t)uio->uio_offset, c, rw == UIO_READ ? B_READ : B_WRITE))
				goto fault;
			error = uiomove((caddr_t)uio->uio_offset, (int)c, rw, uio);
			continue;

/* minor device 2 is EOF/RATHOLE */
		case 2:
			if (rw == UIO_READ)
				return (0);
			c = iov->iov_len;
			break;

/* minor device 3 is versabus memory (addressed by shorts) */
		case 3:
			c = iov->iov_len;
			if (!kernacc((caddr_t)uio->uio_offset, c, rw == UIO_READ ? B_READ : B_WRITE))
				goto fault;
			if (!useracc(iov->iov_base, c, rw == UIO_READ ? B_WRITE : B_READ))
				goto fault;
			error = VERSAcpy((caddr_t)uio->uio_offset, iov->iov_base,
			    (int)c, rw);
			break;
		}
		if (error)
			break;
		iov->iov_base += c;
		iov->iov_len -= c;
		uio->uio_offset += c;
		uio->uio_resid -= c;
	}
	return (error);
fault:
	return (EFAULT);
}

/*
 * VERSABUS Address Space <--> User Space transfer
 */
VERSAcpy(versaadd, usradd, n, rw)
	caddr_t versaadd, usradd;
	register int n;
	enum uio_rw rw;
{
	register short *from, *to;
 
	if(((int)versaadd&1) || ((int)usradd&1))
		return (EFAULT);
	if (rw == UIO_READ) {
		from = (short *)versaadd;
		to = (short *)usradd;
	} else {
		from = (short *)usradd;
		to = (short *)versaadd;
	}
	for (n >>= 1; n > 0; n--)
		*to++ = *from++;
	return (0);
}
E 1
