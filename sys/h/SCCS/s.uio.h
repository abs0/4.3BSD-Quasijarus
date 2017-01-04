h33022
s 00001/00001/00032
d D 7.1 86/06/04 23:30:50 mckusick 6 5
c 4.3BSD release version
e
s 00001/00001/00032
d D 6.4 86/02/23 23:01:08 karels 5 4
c lint
e
s 00007/00001/00026
d D 6.3 85/06/08 15:11:30 mckusick 4 3
c Add copyright
e
s 00011/00000/00016
d D 6.2 84/07/08 15:47:42 mckusick 3 2
c rework `namei' interface to eliminate global variables
e
s 00000/00000/00016
d D 6.1 83/07/29 06:14:45 sam 2 1
c 4.2 distribution
e
s 00016/00000/00000
d D 4.1 82/09/04 09:27:46 root 1 0
c date and time created 82/09/04 09:27:46 by root
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%E%	*/
E 4
I 4
/*
D 6
 * Copyright (c) 1982 Regents of the University of California.
E 6
I 6
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 6
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 4

I 3
#ifndef _UIO_
#define	_UIO_

E 3
struct iovec {
	caddr_t	iov_base;
	int	iov_len;
};

struct uio {
	struct	iovec *uio_iov;
	int	uio_iovcnt;
D 5
	int	uio_offset;
E 5
I 5
	off_t	uio_offset;
E 5
	int	uio_segflg;
	int	uio_resid;
};

enum	uio_rw { UIO_READ, UIO_WRITE };
I 3

/*
 * Segment flag values (should be enum).
 */
#define UIO_USERSPACE	0		/* from user data space */
#define UIO_SYSSPACE	1		/* from system space */
#define UIO_USERISPACE	2		/* from user I space */
#endif
E 3
E 1
