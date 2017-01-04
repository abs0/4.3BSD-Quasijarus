h39282
s 00001/00000/00083
d D 7.3 88/05/14 11:25:47 karels 24 23
c raw read/write support from torek: add strategy to cdevsw, B_RAW flag
e
s 00001/00000/00082
d D 7.2 87/04/02 15:36:22 karels 23 21
c working again
e
s 00005/00000/00082
d D 7.1.1.1 87/04/02 15:17:34 karels 22 21
c ifdef for dev_bsize
e
s 00001/00001/00081
d D 7.1 86/06/04 23:20:49 mckusick 21 20
c 4.3BSD release version
e
s 00007/00001/00075
d D 6.2 85/06/08 14:55:24 mckusick 20 19
c Add copyright
e
s 00000/00000/00076
d D 6.1 83/07/29 06:11:56 sam 19 18
c 4.2 distribution
e
s 00002/00000/00074
d D 4.11 83/05/18 02:11:29 sam 18 17
c stuff for variable sized swap partitions (note addition to bdevsw)
e
s 00001/00000/00073
d D 4.10 82/10/31 15:53:00 root 17 16
c add d_mmap (from 68k)
e
s 00001/00001/00072
d D 4.9 82/10/17 12:03:51 root 16 15
c l_write routine returns error not a char *
e
s 00001/00000/00072
d D 4.8 81/10/17 16:14:03 wnj 15 14
c cleanup (mpx removal, old tty removal, beginnings of select)
e
s 00001/00001/00071
d D 4.7 81/04/03 14:52:30 root 14 13
c cosmetics for pstats sake
e
s 00018/00010/00054
d D 4.6 81/03/09 00:26:50 wnj 13 12
c lint
e
s 00001/00001/00063
d D 4.5 81/02/19 21:39:40 wnj 12 11
c %G%->%E%
e
s 00001/00001/00063
d D 4.4 81/02/15 12:15:13 kre 11 10
c d_tab ->d_flags
e
s 00001/00000/00063
d D 4.3 81/02/03 23:42:42 wnj 10 9
c added d_dump
e
s 00004/00000/00059
d D 4.2 81/01/26 20:42:24 wnj 9 8
c chaos
e
s 00000/00000/00059
d D 4.1 80/11/09 17:00:44 bill 8 7
c stamp for 4bsd
e
s 00009/00000/00050
d D 3.7 80/07/01 08:17:04 bill 7 6
c various minor fixups pre-split to dev dir
e
s 00001/00000/00049
d D 3.6 80/06/22 12:39:08 bill 6 5
c added d_reset
e
s 00001/00001/00048
d D 3.5 80/06/07 02:56:47 bill 5 4
c %H%->%G%
e
s 00000/00004/00049
d D 3.4 80/05/15 17:17:05 bill 4 3
c new tty discipline
e
s 00001/00001/00052
d D 3.3 80/05/08 10:41:34 bill 3 2
c BNELDIS=>NETLDISC
e
s 00004/00000/00049
d D 3.2 80/05/08 10:15:38 bill 2 1
c addition for netldis
e
s 00049/00000/00000
d D 3.1 80/04/09 16:23:35 bill 1 0
c date and time created 80/04/09 16:23:35 by bill
e
u
U
f b 
t
T
I 1
D 5
/*	%M%	%I%	%H%	*/
E 5
I 5
D 12
/*	%M%	%I%	%G%	*/
E 12
I 12
D 20
/*	%M%	%I%	%E%	*/
E 20
I 20
/*
D 21
 * Copyright (c) 1982 Regents of the University of California.
E 21
I 21
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 21
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 20
E 12
E 5

/*
 * Declaration of block device
 * switch. Each entry (row) is
 * the only link between the
 * main unix code and the driver.
 * The initialization of the
 * device switches is in the
 * file conf.c.
 */
D 13
extern struct bdevsw
E 13
I 13
struct bdevsw
E 13
{
	int	(*d_open)();
	int	(*d_close)();
	int	(*d_strategy)();
I 23
	int	(*d_ioctl)();
E 23
I 22
	int	(*d_ioctl)();
E 22
I 10
	int	(*d_dump)();
I 18
	int	(*d_psize)();
E 18
E 10
D 11
	struct buf *d_tab;
E 11
I 11
	int	d_flags;
E 11
D 13
} bdevsw[];
E 13
I 13
};
#ifdef KERNEL
struct	bdevsw bdevsw[];
#endif
E 13

/*
 * Character device switch.
 */
D 13
extern struct cdevsw
E 13
I 13
struct cdevsw
E 13
{
	int	(*d_open)();
	int	(*d_close)();
	int	(*d_read)();
	int	(*d_write)();
	int	(*d_ioctl)();
	int	(*d_stop)();
I 6
	int	(*d_reset)();
E 6
	struct tty *d_ttys;
I 15
	int	(*d_select)();
I 17
	int	(*d_mmap)();
I 24
	int	(*d_strategy)();
E 24
E 17
E 15
D 13
} cdevsw[];
E 13
I 13
};
#ifdef KERNEL
struct	cdevsw cdevsw[];
#endif
E 13

/*
 * tty line control switch.
 */
D 13
extern struct linesw
E 13
I 13
struct linesw
E 13
{
	int	(*l_open)();
	int	(*l_close)();
	int	(*l_read)();
D 16
	char	*(*l_write)();
E 16
I 16
	int	(*l_write)();
E 16
	int	(*l_ioctl)();
	int	(*l_rint)();
	int	(*l_rend)();
	int	(*l_meta)();
	int	(*l_start)();
	int	(*l_modem)();
D 13
} linesw[];
E 13
I 13
};
#ifdef KERNEL
struct	linesw linesw[];
#endif
E 13
I 7

/*
 * Swap device information
 */
D 13
extern struct swdevt
E 13
I 13
struct swdevt
E 13
{
	dev_t	sw_dev;
	int	sw_freed;
I 18
	int	sw_nblks;
I 22
#ifdef SECSIZE
	int	sw_blksize;
	int	sw_bshift;
#endif SECSIZE
E 22
E 18
D 14
} swdevt[];
E 14
I 14
};
E 14
I 9
D 13

#ifdef	CHAOS
extern int cdevpath;
E 13
I 13
#ifdef KERNEL
struct	swdevt swdevt[];
E 13
#endif
E 9
E 7
I 2
D 4

#ifdef BERKNET
D 3
#define	BNETLDIS	1		/* line discip for berk net */
E 3
I 3
#define	NETLDISC	1		/* line discip for berk net */
E 3
#endif
E 4
E 2
E 1
