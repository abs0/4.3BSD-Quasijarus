h38220
s 00001/00001/00018
d D 7.1 86/06/04 23:25:21 mckusick 9 8
c 4.3BSD release version
e
s 00007/00001/00012
d D 6.3 85/06/08 15:01:59 mckusick 8 7
c Add copyright
e
s 00003/00002/00010
d D 6.2 84/07/17 16:20:31 ralph 7 6
c changes for log device.
e
s 00000/00000/00012
d D 6.1 83/07/29 06:13:13 sam 6 3
c 4.2 distribution
e
s 00001/00001/00012
d R 4.5 81/08/31 02:29:10 root 5 4
c s/2/4/ (# longs in structure; 1 for slop!)
e
s 00003/00002/00010
d R 4.4 81/08/31 01:12:46 wnj 4 3
c new code for /dev/errlog
e
s 00001/00001/00011
d D 4.3 81/08/30 20:58:27 root 3 2
c make message buffer 4096 not 1024 bytes
e
s 00001/00001/00011
d D 4.2 81/02/19 21:41:22 wnj 2 1
c %G%->%E%
e
s 00012/00000/00000
d D 4.1 81/02/19 21:34:18 wnj 1 0
c date and time created 81/02/19 21:34:18 by wnj
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%G%	*/
E 2
I 2
D 8
/*	%M%	%I%	%E%	*/
E 8
I 8
/*
D 9
 * Copyright (c) 1982 Regents of the University of California.
E 9
I 9
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 9
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 8
E 2

D 7
#define	MSG_MAGIC	0x063060
D 3
#define	MSG_BSIZE	(NBPG*CLSIZE - 2 * sizeof (long))
E 3
I 3
#define	MSG_BSIZE	(4096 - 2 * sizeof (long))
E 7
I 7
#define	MSG_MAGIC	0x063061
#define	MSG_BSIZE	(4096 - 3 * sizeof (long))
E 7
E 3
struct	msgbuf {
	long	msg_magic;
	long	msg_bufx;
I 7
	long	msg_bufr;
E 7
	char	msg_bufc[MSG_BSIZE];
};
#ifdef KERNEL
struct	msgbuf msgbuf;
#endif
E 1
