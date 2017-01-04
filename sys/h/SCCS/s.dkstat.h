h53923
s 00001/00001/00032
d D 7.2 88/05/21 13:52:01 karels 9 8
c increase DK_NDRIVE to 8
e
s 00001/00001/00032
d D 7.1 86/06/04 23:21:23 mckusick 8 7
c 4.3BSD release version
e
s 00007/00001/00026
d D 6.3 85/06/08 14:55:50 mckusick 7 6
c Add copyright
e
s 00001/00000/00026
d D 6.2 83/10/08 14:09:37 sam 6 5
c add dk_ndrive so iostat/pstat/vmstat can be binary portable
e
s 00000/00000/00026
d D 6.1 83/07/29 06:12:03 sam 5 4
c 4.2 distribution
e
s 00001/00001/00025
d D 4.2 81/02/19 21:40:09 wnj 4 3
c %G%->%E%
e
s 00000/00000/00026
d D 4.1 80/11/09 17:02:14 bill 3 2
c stamp for 4bsd
e
s 00007/00003/00019
d D 3.2 80/10/13 09:59:47 bill 2 1
c simpler, cleaner iostat interface
e
s 00022/00000/00000
d D 3.1 80/07/01 08:20:52 bill 1 0
c date and time created 80/07/01 08:20:52 by bill
e
u
U
t
T
I 1
D 4
/*	%M%	%I%	%G%	*/
E 4
I 4
D 7
/*	%M%	%I%	%E%	*/
E 7
I 7
/*
D 8
 * Copyright (c) 1982 Regents of the University of California.
E 8
I 8
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 8
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 7
E 4

/*
 * Instrumentation
 */
#define	CPUSTATES	4

#define	CP_USER		0
#define	CP_NICE		1
#define	CP_SYS		2
#define	CP_IDLE		3

D 9
#define	DK_NDRIVE	4
E 9
I 9
#define	DK_NDRIVE	8
E 9
D 2
#define	DK_NSTATES	16		/* 2^DK_NDRIVE */
E 2

I 2
#ifdef KERNEL
long	cp_time[CPUSTATES];
I 6
int	dk_ndrive;
E 6
E 2
int	dk_busy;
D 2
long	dk_time[CPUSTATES][DK_NSTATES];
long	dk_numb[DK_NDRIVE];
E 2
I 2
long	dk_time[DK_NDRIVE];
long	dk_seek[DK_NDRIVE];
long	dk_xfer[DK_NDRIVE];
E 2
long	dk_wds[DK_NDRIVE];
I 2
float	dk_mspw[DK_NDRIVE];
E 2

long	tk_nin;
long	tk_nout;
I 2
#endif
E 2
E 1
