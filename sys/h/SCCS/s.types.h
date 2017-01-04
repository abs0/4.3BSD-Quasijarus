h15736
s 00002/00002/00073
d D 7.4 2012/06/16 07:50:54 msokolov 23 22
c Y2038: time_t is now an unsigned long
e
s 00001/00000/00074
d D 7.3 87/06/20 14:24:16 mckusick 22 21
c add typedef for qaddr_t
e
s 00002/00002/00072
d D 7.2 86/10/13 23:02:05 karels 21 20
c merge in tahoe system
e
s 00001/00001/00073
d D 7.1 86/06/04 23:30:38 mckusick 20 19
c 4.3BSD release version
e
s 00001/00001/00073
d D 6.8 86/03/28 19:34:29 karels 19 18
c now need cast in FD_ZERO...
e
s 00003/00003/00071
d D 6.7 85/10/28 16:41:01 mckusick 18 17
c exterminate the ints
e
s 00007/00009/00067
d D 6.6 85/06/25 13:18:22 karels 17 16
c remove dependency of types.h on param.h; increase CBSIZE
e
s 00028/00001/00048
d D 6.5 85/06/17 21:56:44 karels 16 15
c add macros for select masks; mv param's include of types.h
c after defn. of howmany; allow larger hostnames (domains coming!)
e
s 00007/00001/00042
d D 6.4 85/06/08 15:11:18 mckusick 15 14
c Add copyright
e
s 00002/00000/00041
d D 6.3 85/03/07 19:10:51 karels 14 13
c add uid_t, gid_t
e
s 00003/00000/00038
d D 6.2 84/06/09 13:10:47 sam 13 12
c allow multiple includes
e
s 00000/00000/00038
d D 6.1 83/07/29 06:14:42 sam 12 11
c 4.2 distribution
e
s 00000/00006/00038
d D 4.11 83/07/01 02:25:08 root 11 10
c purge #if sun's
e
s 00001/00000/00043
d D 4.10 83/05/18 02:42:30 sam 10 9
c sun changes
e
s 00001/00001/00042
d D 4.9 82/11/13 23:08:50 sam 9 8
c merge 4.1b and 4.1c
e
s 00012/00005/00031
d D 4.8 82/10/31 16:38:34 root 8 7
c label_t and physadr dependent on vax/sun
e
s 00001/00002/00035
d D 4.7 82/10/20 01:16:33 root 7 6
c lint
e
s 00001/00001/00036
d D 4.6 82/10/17 20:51:38 root 6 5
c daddr_t is a long
e
s 00003/00003/00034
d D 4.5 82/09/08 08:12:01 root 5 4
c label_t now a structure; other misc changes
e
s 00003/00001/00034
d D 4.4 82/04/19 19:27:11 mckusic 4 3
c merge in the new file system
e
s 00002/00000/00033
d D 4.3 81/10/17 16:14:46 wnj 3 2
c cleanup (mpx removal, old tty removal, beginnings of select)
e
s 00001/00000/00032
d D 4.2 81/04/28 03:02:28 root 2 1
c typedef portid_t
e
s 00032/00000/00000
d D 4.1 81/03/21 16:09:48 wnj 1 0
c date and time created 81/03/21 16:09:48 by wnj
e
u
U
t
T
I 4
D 5
/*	types.h	2.1	3/25/82	*/

E 5
E 4
I 1
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
/*
D 20
 * Copyright (c) 1982 Regents of the University of California.
E 20
I 20
D 21
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 21
I 21
 * Copyright (c) 1982 Regents of the University of California.
E 21
E 20
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 23
 *	%W% (Berkeley) %G%
E 23
I 23
 *	%W% (Berkeley) %E%
E 23
 */
E 15

I 13
#ifndef _TYPES_
#define	_TYPES_
E 13
/*
 * Basic system types and major/minor device constructing/busting macros.
 */

/* major part of a device */
#define	major(x)	((int)(((unsigned)(x)>>8)&0377))

/* minor part of a device */
#define	minor(x)	((int)((x)&0377))

/* make a device number */
#define	makedev(x,y)	((dev_t)(((x)<<8) | (y)))

typedef	unsigned char	u_char;
typedef	unsigned short	u_short;
typedef	unsigned int	u_int;
typedef	unsigned long	u_long;
I 10
typedef	unsigned short	ushort;		/* sys III compat */
E 10

D 8
/* SHOULD USE long RATHER THAN int HERE BUT IT WOULD GIVE LINT ON THE KERNEL */
/* GASTRIC DISTRESS AND DON'T HAVE TIME TO FIX THAT JUST NOW */
E 8
I 8
D 21
#ifdef vax
E 21
I 21
#if defined(vax) || defined(tahoe)
E 21
E 8
typedef	struct	_physadr { int r[1]; } *physadr;
I 8
typedef	struct	label_t	{
	int	val[14];
} label_t;
#endif
D 11
#ifdef sun
typedef	struct	_physadr { short r[1]; } *physadr;
typedef	struct	label_t	{
	int	val[13];
} label_t;
D 9
typedef	struct	quad { long val[2]; } quad;
E 9
#endif
E 11
I 9
typedef	struct	_quad { long val[2]; } quad;
E 9
E 8
D 6
typedef	int	daddr_t;
E 6
I 6
typedef	long	daddr_t;
E 6
typedef	char *	caddr_t;
I 22
typedef	long *	qaddr_t;	/* should be typedef quad * qaddr_t; */
E 22
D 4
typedef	u_short ino_t;
E 4
I 4
typedef	u_long	ino_t;
E 4
D 7
typedef	int	swblk_t;
E 7
I 7
typedef	long	swblk_t;
E 7
D 18
typedef	int	size_t;
typedef	int	time_t;
E 18
I 18
typedef	long	size_t;
D 23
typedef	long	time_t;
E 23
I 23
typedef	u_long	time_t;
E 23
E 18
D 5
typedef	int	label_t[14];
E 5
I 5
D 8
typedef	struct	label_t	{
	int	val[14];
} label_t;
E 8
E 5
typedef	short	dev_t;
D 18
typedef	int	off_t;
E 18
I 18
typedef	long	off_t;
E 18
I 14
typedef	u_short	uid_t;
typedef	u_short	gid_t;
E 14
I 2
D 7
typedef	long	portid_t;
E 7
I 3

I 17
#define	NBBY	8		/* number of bits in a byte */
E 17
D 16
typedef	struct	fd_set { int fds_bits[1]; } fd_set;
E 16
I 16
/*
 * Select uses bit masks of file descriptors in longs.
 * These macros manipulate such bit fields (the filesystem macros use chars).
I 17
 * FD_SETSIZE may be defined by the user, but the default here
 * should be >= NOFILE (param.h).
E 17
 */
D 17
#ifndef	NBBY
#ifdef KERNEL
#include "param.h"
#else	KERNEL
#include <sys/param.h>
#endif	KERNEL
#endif	NBBY

E 17
#ifndef	FD_SETSIZE
D 17
#define	FD_SETSIZE	NOFILE
E 17
I 17
#define	FD_SETSIZE	256
E 17
#endif

typedef long	fd_mask;
#define NFDBITS	(sizeof(fd_mask) * NBBY)	/* bits per mask */
I 17
#ifndef howmany
#define	howmany(x, y)	(((x)+((y)-1))/(y))
#endif
E 17

typedef	struct fd_set {
	fd_mask	fds_bits[howmany(FD_SETSIZE, NFDBITS)];
} fd_set;

#define	FD_SET(n, p)	((p)->fds_bits[(n)/NFDBITS] |= (1 << ((n) % NFDBITS)))
#define	FD_CLR(n, p)	((p)->fds_bits[(n)/NFDBITS] &= ~(1 << ((n) % NFDBITS)))
#define	FD_ISSET(n, p)	((p)->fds_bits[(n)/NFDBITS] & (1 << ((n) % NFDBITS)))
D 19
#define FD_ZERO(p)	bzero(p, sizeof(*(p)))
E 19
I 19
#define FD_ZERO(p)	bzero((char *)(p), sizeof(*(p)))
E 19

E 16
I 13
#endif
E 13
E 3
E 2
E 1
