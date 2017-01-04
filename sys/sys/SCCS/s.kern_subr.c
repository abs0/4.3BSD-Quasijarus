h16409
s 00001/00001/00146
d D 7.1 86/06/05 00:04:38 mckusick 7 6
c 4.3BSD release version
e
s 00005/00004/00142
d D 6.5 86/04/21 12:13:35 karels 6 5
c fixes to uwritec from dlw; include it for ct driver
e
s 00007/00001/00139
d D 6.4 85/06/08 14:38:09 mckusick 5 4
c Add copyright
e
s 00005/00005/00135
d D 6.3 84/08/29 20:20:24 bloom 4 3
c Change to includes.  no more ../h
e
s 00009/00009/00131
d D 6.2 84/07/08 22:32:28 mckusick 3 2
c use proper definition of UIO flags
e
s 00000/00000/00140
d D 6.1 83/07/29 06:34:18 sam 2 1
c 4.2 distribution
e
s 00140/00000/00000
d D 4.1 83/05/27 14:02:47 sam 1 0
c date and time created 83/05/27 14:02:47 by sam
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
D 7
 * Copyright (c) 1982 Regents of the University of California.
E 7
I 7
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 7
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

D 4
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/uio.h"
E 4
I 4
#include "param.h"
#include "systm.h"
#include "dir.h"
#include "user.h"
#include "uio.h"
E 4

uiomove(cp, n, rw, uio)
	register caddr_t cp;
	register int n;
	enum uio_rw rw;
	register struct uio *uio;
{
	register struct iovec *iov;
	u_int cnt;
	int error = 0;

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

D 3
		case 0:
		case 2:
E 3
I 3
		case UIO_USERSPACE:
		case UIO_USERISPACE:
E 3
			if (rw == UIO_READ)
				error = copyout(cp, iov->iov_base, cnt);
			else
				error = copyin(iov->iov_base, cp, cnt);
			if (error)
				return (error);
			break;

D 3
		case 1:
E 3
I 3
		case UIO_SYSSPACE:
E 3
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

/*
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

D 3
	case 0:
E 3
I 3
	case UIO_USERSPACE:
E 3
		if (subyte(iov->iov_base, c) < 0)
			return (EFAULT);
		break;

D 3
	case 1:
E 3
I 3
	case UIO_SYSSPACE:
E 3
		*iov->iov_base = c;
		break;

D 3
	case 2:
E 3
I 3
	case UIO_USERISPACE:
E 3
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

D 6
#ifdef notdef
E 6
/*
 * Get next character written in by user from uio.
 */
uwritec(uio)
	struct uio *uio;
{
	register struct iovec *iov;
	register int c;

I 6
	if (uio->uio_resid <= 0)
		return (-1);
E 6
again:
D 6
	if (uio->uio_iovcnt <= 0 || uio->uio_resid <= 0)
E 6
I 6
	if (uio->uio_iovcnt <= 0)
E 6
		panic("uwritec");
	iov = uio->uio_iov;
	if (iov->iov_len == 0) {
D 6
		uio->uio_iovcnt--;
E 6
		uio->uio_iov++;
I 6
		if (--uio->uio_iovcnt == 0)
			return (-1);
E 6
		goto again;
	}
	switch (uio->uio_segflg) {

D 3
	case 0:
E 3
I 3
	case UIO_USERSPACE:
E 3
		c = fubyte(iov->iov_base);
		break;

D 3
	case 1:
E 3
I 3
	case UIO_SYSSPACE:
E 3
		c = *iov->iov_base & 0377;
		break;

D 3
	case 2:
E 3
I 3
	case UIO_USERISPACE:
E 3
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
D 6
#endif
E 6
E 1
