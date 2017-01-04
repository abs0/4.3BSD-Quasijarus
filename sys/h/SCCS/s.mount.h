h54278
s 00001/00001/00022
d D 7.2 87/06/21 15:27:13 mckusick 10 9
c geteblk => malloc, so m_bufp => m_fs as it should be
e
s 00001/00001/00022
d D 7.1 86/06/04 23:25:10 mckusick 9 8
c 4.3BSD release version
e
s 00007/00001/00016
d D 6.2 85/06/08 15:01:46 mckusick 8 7
c Add copyright
e
s 00000/00000/00017
d D 6.1 83/07/29 06:13:10 sam 7 6
c 4.2 distribution
e
s 00001/00000/00016
d D 4.4 82/07/19 17:40:15 kre 6 5
c added inode pointer to quota file (for disc quotas)
e
s 00004/00001/00012
d D 4.3 81/02/26 23:17:17 wnj 5 4
c #ifdef KERNEL
e
s 00001/00001/00012
d D 4.2 81/02/19 21:41:19 wnj 4 3
c %G%->%E%
e
s 00000/00000/00013
d D 4.1 80/11/09 17:01:14 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00012
d D 3.2 80/06/07 02:58:44 bill 2 1
c %H%->%G%
e
s 00013/00000/00000
d D 3.1 80/04/09 16:24:20 bill 1 0
c date and time created 80/04/09 16:24:20 by bill
e
u
U
t
T
I 1
D 2
/*	%M%	%I%	%H%	*/
E 2
I 2
D 4
/*	%M%	%I%	%G%	*/
E 4
I 4
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
E 4
E 2

/*
 * Mount structure.
 * One allocated on every mount.
 * Used to find the super block.
 */
struct	mount
{
	dev_t	m_dev;		/* device mounted */
D 10
	struct	buf *m_bufp;	/* pointer to superblock */
E 10
I 10
	struct	fs *m_fs;	/* pointer to superblock */
E 10
	struct	inode *m_inodp;	/* pointer to mounted on inode */
I 6
	struct	inode *m_qinod;	/* QUOTA: pointer to quota file */
E 6
D 5
} mount[NMOUNT];
E 5
I 5
};
#ifdef KERNEL
struct	mount mount[NMOUNT];
#endif
E 5
E 1
