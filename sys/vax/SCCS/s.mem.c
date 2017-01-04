h05907
s 00001/00001/00144
d D 7.1 86/06/05 00:45:39 mckusick 22 21
c 4.3BSD release version
e
s 00003/00002/00142
d D 6.4 86/02/23 23:07:14 karels 21 20
c lint
e
s 00007/00001/00137
d D 6.3 85/06/08 13:43:36 mckusick 20 19
c Add copyright
e
s 00011/00011/00127
d D 6.2 84/08/28 18:10:29 bloom 19 18
c Change to includes.  No more ../h
e
s 00000/00000/00138
d D 6.1 83/07/29 07:20:35 sam 18 17
c 4.2 distribution
e
s 00002/00001/00136
d D 4.12 82/12/17 11:56:39 sam 17 16
c sun merge
e
s 00002/00001/00135
d D 4.11 82/12/05 22:15:14 sam 16 14
c page acess bits being set wrong
e
s 00002/00001/00135
d R 4.11 82/11/22 20:24:20 sam 15 14
c write on physical memory caused protection fault
e
s 00002/00000/00134
d D 4.10 82/10/31 15:27:24 root 14 13
c umbabeg and umbaend declared external
e
s 00002/00002/00132
d D 4.9 82/10/21 20:58:44 root 13 12
c lint
e
s 00004/00004/00130
d D 4.8 82/10/20 01:37:35 root 12 11
c lint
e
s 00002/00002/00132
d D 4.7 82/10/17 23:05:05 root 11 10
c lint
e
s 00004/00005/00130
d D 4.6 82/10/17 15:25:01 root 10 9
c fix lint
e
s 00014/00016/00121
d D 4.5 82/10/13 22:14:50 root 9 8
c rearrange header files
e
s 00083/00109/00054
d D 4.4 82/08/22 21:19:44 root 8 7
c fully uio()'d
e
s 00001/00001/00162
d D 4.3 81/03/09 01:53:34 wnj 7 6
c %G% -> %E%
e
s 00006/00008/00157
d D 4.2 81/02/27 17:49:38 wnj 6 5
c system sized at boot version
e
s 00000/00000/00165
d D 4.1 80/11/09 16:53:27 bill 5 4
c stamp for 4bsd
e
s 00001/00001/00164
d D 3.4 80/06/07 02:46:19 bill 4 3
c %H%->%G%
e
s 00002/00002/00163
d D 3.3 80/06/06 16:19:38 bill 3 2
c fix botch in previous delta
e
s 00002/00000/00163
d D 3.2 80/06/06 14:47:09 bill 2 1
c fix page faulting bugs
e
s 00163/00000/00000
d D 3.1 80/04/09 16:03:31 bill 1 0
c date and time created 80/04/09 16:03:31 by bill
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%H%	*/
E 4
I 4
D 7
/*	%M%	%I%	%G%	*/
E 7
I 7
D 20
/*	%M%	%I%	%E%	*/
E 20
I 20
/*
D 22
 * Copyright (c) 1982 Regents of the University of California.
E 22
I 22
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 22
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 20
E 7
E 4

/*
 * Memory special file
D 8
 *	minor device 0 is physical memory
 *	minor device 1 is kernel memory 
 *	minor device 2 is EOF/RATHOLE
 *	minor device 3 is unibus memory (addressed by shorts)
E 8
 */

I 17
D 19
#include "../machine/pte.h"
E 19
I 19
#include "pte.h"
E 19

E 17
D 19
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/conf.h"
#include "../h/buf.h"
#include "../h/systm.h"
D 17
#include "../h/pte.h"
E 17
D 9
#include "../h/mtpr.h"
E 9
#include "../h/vm.h"
#include "../h/cmap.h"
I 8
#include "../h/uio.h"
E 19
I 19
#include "param.h"
#include "dir.h"
#include "user.h"
#include "conf.h"
#include "buf.h"
#include "systm.h"
#include "vm.h"
#include "cmap.h"
#include "uio.h"
E 19
E 8

I 9
D 19
#include "../vax/mtpr.h"
E 19
I 19
#include "mtpr.h"
E 19

E 9
D 8
mmread(dev)
E 8
I 8
mmread(dev, uio)
	dev_t dev;
	struct uio *uio;
E 8
{
D 8
	register int o;
	register unsigned c, v;
E 8

D 8
	switch (minor(dev)) {
E 8
I 8
D 9
	mmrw(dev, uio, UIO_READ);
E 9
I 9
	return (mmrw(dev, uio, UIO_READ));
E 9
}
E 8

D 8
	case 0:
		while (u.u_count != 0 && u.u_error == 0) {
			if (fubyte(u.u_base) == -1)
				goto fault;
			v = btop(u.u_offset);
			if (v >= physmem)
				goto fault;
			*(int *)mmap = v | (PG_V | PG_KR);
			mtpr(TBIS, vmmap);
			o = (int)u.u_offset & PGOFSET;
			c = min((unsigned)(NBPG - o), u.u_count);
I 2
D 3
			c = min(c, (unsigned)((int)u.u_base & PGOFSET));
E 3
I 3
			c = min(c, (unsigned)(NBPG - ((int)u.u_base&PGOFSET)));
E 3
E 2
			if (copyout((caddr_t)&vmmap[o], u.u_base, c))
				goto fault;
			u.u_count -= c;
			u.u_base += c;
			u.u_offset += c;
		}
		return;
E 8
I 8
mmwrite(dev, uio)
	dev_t dev;
	struct uio *uio;
{
E 8

D 8
	case 1:
D 6
		if (u.u_uid != 0) {
			if ((caddr_t)u.u_offset < (caddr_t)&umbabeg &&
			    (caddr_t)u.u_offset + u.u_count >= (caddr_t)&umbabeg)
				goto fault;
			if ((caddr_t)u.u_offset >= (caddr_t)&umbabeg &&
			    (caddr_t)u.u_offset < (caddr_t)&umbaend)
				goto fault;
		}
E 6
I 6
		if ((caddr_t)u.u_offset < (caddr_t)&umbabeg &&
		    (caddr_t)u.u_offset + u.u_count >= (caddr_t)&umbabeg)
			goto fault;
		if ((caddr_t)u.u_offset >= (caddr_t)&umbabeg &&
		    (caddr_t)u.u_offset < (caddr_t)&umbaend)
			goto fault;
E 6
		if (!kernacc((caddr_t)u.u_offset, u.u_count, B_READ))
			goto fault;
		if (copyout((caddr_t)u.u_offset, u.u_base, u.u_count))
			goto fault;
		c = u.u_count;
		u.u_count = 0;
		u.u_base += c;
		u.u_offset += c;
		return;

	case 2:
		return;

	case 3:
		if (!kernacc((caddr_t)u.u_offset, u.u_count, B_READ))
			goto fault;
		if (!useracc(u.u_base, u.u_count, B_WRITE))
			goto fault;
		UNIcpy((caddr_t)u.u_offset, u.u_base, u.u_count, B_READ);
		c = u.u_count;
		u.u_count = 0;
		u.u_base += c;
		u.u_offset += c;
		return;
	}
fault:
	u.u_error = EFAULT;
	return;
E 8
I 8
D 9
	mmrw(dev, uio, UIO_WRITE);
E 9
I 9
	return (mmrw(dev, uio, UIO_WRITE));
E 9
E 8
}

D 8
mmwrite(dev)
E 8
I 8
mmrw(dev, uio, rw)
	dev_t dev;
	struct uio *uio;
	enum uio_rw rw;
E 8
{
	register int o;
D 11
	register unsigned c, v;
E 11
I 11
	register u_int c, v;
E 11
I 8
	register struct iovec *iov;
I 9
	int error = 0;
I 14
	extern int umbabeg, umbaend;

E 14
E 9
E 8

D 8
	switch (minor(dev)) {
E 8
I 8
D 9
	while (uio->uio_resid > 0 && u.u_error == 0) {
E 9
I 9
	while (uio->uio_resid > 0 && error == 0) {
E 9
		iov = uio->uio_iov;
		if (iov->iov_len == 0) {
			uio->uio_iov++;
			uio->uio_iovcnt--;
			if (uio->uio_iovcnt < 0)
				panic("mmrw");
			continue;
		}
		switch (minor(dev)) {
E 8

D 8
	case 0:
		while (u.u_count != 0 && u.u_error == 0) {
			if (fubyte(u.u_base) == -1)
				goto fault;
			v = btop(u.u_offset);
E 8
I 8
/* minor device 0 is physical memory */
		case 0:
			v = btop(uio->uio_offset);
E 8
			if (v >= physmem)
				goto fault;
D 8
			*(int *)mmap = v | (PG_V | PG_KW);
E 8
I 8
D 16
			*(int *)mmap = v | (PG_V | PG_KR);
E 16
I 16
			*(int *)mmap = v | PG_V |
				(rw == UIO_READ ? PG_KR : PG_KW);
E 16
E 8
			mtpr(TBIS, vmmap);
D 8
			o = (int)u.u_offset & PGOFSET;
			c = min((unsigned)(NBPG - o), u.u_count);
I 2
D 3
			c = min(c, (unsigned)((int)u.u_base & PGOFSET));
E 3
I 3
			c = min(c, (unsigned)(NBPG - ((int)u.u_base&PGOFSET)));
E 3
E 2
			if (copyin(u.u_base, (caddr_t)&vmmap[o], c))
E 8
I 8
			o = (int)uio->uio_offset & PGOFSET;
D 12
			c = min((unsigned)(NBPG - o), iov->iov_len);
			c = min(c, (unsigned)(NBPG - ((int)iov->iov_base&PGOFSET)));
E 12
I 12
D 21
			c = min((u_int)(NBPG - o), (u_int)iov->iov_len);
			c = min(c, (u_int)(NBPG - ((int)iov->iov_base&PGOFSET)));
E 21
I 21
			c = (u_int)(NBPG - ((int)iov->iov_base & PGOFSET));
			c = MIN(c, (u_int)(NBPG - o));
			c = MIN(c, (u_int)iov->iov_len);
E 21
E 12
D 9
			u.u_error = uiomove((caddr_t)&vmmap[o], c, rw, uio);
			if (u.u_error)
E 8
				goto fault;
E 9
I 9
D 13
			error = uiomove((caddr_t)&vmmap[o], c, rw, uio);
E 13
I 13
			error = uiomove((caddr_t)&vmmap[o], (int)c, rw, uio);
E 13
E 9
D 8
			u.u_count -= c;
			u.u_base += c;
			u.u_offset += c;
		}
		return;
E 8
I 8
			continue;
E 8

D 8
	case 1:
		if (!kernacc((caddr_t)u.u_offset, u.u_count, B_WRITE))
			goto fault;
		if (copyin(u.u_base, (caddr_t)u.u_offset, u.u_count))
			goto fault;
		u.u_base += u.u_count;
		u.u_offset += u.u_count;
		u.u_count = 0;
		return;
E 8
I 8
/* minor device 1 is kernel memory */
		case 1:
			if ((caddr_t)uio->uio_offset < (caddr_t)&umbabeg &&
			    (caddr_t)uio->uio_offset + uio->uio_resid >= (caddr_t)&umbabeg)
				goto fault;
			if ((caddr_t)uio->uio_offset >= (caddr_t)&umbabeg &&
			    (caddr_t)uio->uio_offset < (caddr_t)&umbaend)
				goto fault;
			c = iov->iov_len;
			if (!kernacc((caddr_t)uio->uio_offset, c, rw == UIO_READ ? B_READ : B_WRITE))
				goto fault;
D 9
			u.u_error = uiomove((caddr_t)uio->uio_offset, c, rw, uio);
			if (u.u_error)
				goto fault;
E 9
I 9
D 13
			error = uiomove((caddr_t)uio->uio_offset, c, rw, uio);
E 13
I 13
			error = uiomove((caddr_t)uio->uio_offset, (int)c, rw, uio);
E 13
E 9
			continue;
E 8

D 8
	case 2:
		u.u_offset += u.u_count;
		u.u_count = 0;
		return;
E 8
I 8
/* minor device 2 is EOF/RATHOLE */
		case 2:
			if (rw == UIO_READ)
D 10
				return;
E 10
I 10
				return (0);
E 10
			c = iov->iov_len;
			break;
E 8

D 8
	case 3:
		if (!kernacc((caddr_t)u.u_offset, u.u_count, B_WRITE))
E 8
I 8
/* minor device 3 is unibus memory (addressed by shorts) */
		case 3:
			c = iov->iov_len;
			if (!kernacc((caddr_t)uio->uio_offset, c, rw == UIO_READ ? B_READ : B_WRITE))
				goto fault;
			if (!useracc(iov->iov_base, c, rw == UIO_READ ? B_WRITE : B_READ))
				goto fault;
D 9
			UNIcpy((caddr_t)uio->uio_offset, iov->iov_base,
E 9
I 9
			error = UNIcpy((caddr_t)uio->uio_offset, iov->iov_base,
E 9
D 12
			    c, rw);
E 12
I 12
			    (int)c, rw);
E 12
			break;
		}
D 9
		if (u.u_error)
E 8
			goto fault;
E 9
I 9
		if (error)
			break;
E 9
D 8
		if (!useracc(u.u_base, u.u_count, B_READ))
			goto fault;
		UNIcpy((caddr_t)u.u_offset, u.u_base, u.u_count, B_WRITE);
		u.u_base += u.u_count;
		u.u_offset += u.u_count;
		u.u_count = 0;
		return;
E 8
I 8
		iov->iov_base += c;
		iov->iov_len -= c;
		uio->uio_offset += c;
		uio->uio_resid -= c;
E 8
	}
I 8
D 9
	return;
E 9
I 9
	return (error);
E 9
E 8
fault:
D 9
	u.u_error = EFAULT;
	return;
E 9
I 9
	return (EFAULT);
E 9
}

/*
 * UNIBUS Address Space <--> User Space transfer
 */
D 8
UNIcpy(uniadd, usradd, bknt, direct)
E 8
I 8
D 10
UNIcpy(uniadd, usradd, cnt, rw)
E 10
I 10
UNIcpy(uniadd, usradd, n, rw)
E 10
E 8
	caddr_t uniadd, usradd;
D 8
	unsigned bknt;
E 8
I 8
D 10
	int cnt;
E 10
I 10
D 11
	register int n;
E 11
I 11
D 12
	register u_int n;
E 12
I 12
	register int n;
E 12
E 11
E 10
	enum uio_rw rw;
E 8
{
	register short *from, *to;
D 10
	register int i;
E 10
 
D 8
	if (direct == B_READ) {
		from = (short *) uniadd;
		to = (short *) usradd;
E 8
I 8
	if (rw == UIO_READ) {
		from = (short *)uniadd;
		to = (short *)usradd;
E 8
	} else {
D 8
		from = (short *) usradd;
		to = (short *) uniadd;
E 8
I 8
		from = (short *)usradd;
		to = (short *)uniadd;
E 8
	}
D 8
	for (i = (bknt>>1); i > 0; i--)
E 8
I 8
D 10
	for (i = (cnt>>1); i > 0; i--)
E 10
I 10
	for (n >>= 1; n > 0; n--)
E 10
E 8
		*to++ = *from++;
I 9
	return (0);
E 9
}
E 1
