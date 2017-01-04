h56745
s 00001/00001/00041
d D 7.1 86/06/04 23:28:23 mckusick 13 12
c 4.3BSD release version
e
s 00002/00002/00040
d D 6.3 85/10/28 15:04:34 karels 12 11
c use proper types for uids, gids
e
s 00007/00001/00035
d D 6.2 85/06/08 15:08:32 mckusick 11 10
c Add copyright
e
s 00000/00000/00036
d D 6.1 83/07/29 06:14:10 sam 10 9
c 4.2 distribution
e
s 00002/00001/00034
d D 4.7 83/05/21 16:02:03 sam 9 8
c i_blocks (from kre)
e
s 00004/00000/00031
d D 4.6 82/12/23 14:34:04 sam 8 7
c put some space in there for time changes and such
e
s 00001/00000/00030
d D 4.5 82/11/13 23:08:47 sam 7 6
c merge 4.1b and 4.1c
e
s 00001/00000/00029
d D 4.4 82/04/19 19:27:08 mckusic 6 5
c merge in the new file system
e
s 00001/00002/00028
d D 4.3 82/02/27 14:56:17 wnj 5 4
c symbolic links
e
s 00001/00001/00029
d D 4.2 81/02/19 21:42:14 wnj 4 3
c %G%->%E%
e
s 00000/00000/00030
d D 4.1 80/11/09 17:01:42 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00029
d D 3.2 80/06/07 03:00:46 bill 2 1
c %H%->%G%
e
s 00030/00000/00000
d D 3.1 80/04/09 16:25:22 bill 1 0
c date and time created 80/04/09 16:25:22 by bill
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
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 13
 * Copyright (c) 1982 Regents of the University of California.
E 13
I 13
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 13
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 11
E 4
E 2

struct	stat
{
	dev_t	st_dev;
	ino_t	st_ino;
	unsigned short st_mode;
	short	st_nlink;
D 12
	short	st_uid;
	short	st_gid;
E 12
I 12
	uid_t	st_uid;
	gid_t	st_gid;
E 12
	dev_t	st_rdev;
	off_t	st_size;
	time_t	st_atime;
I 8
	int	st_spare1;
E 8
	time_t	st_mtime;
I 8
	int	st_spare2;
E 8
	time_t	st_ctime;
I 8
	int	st_spare3;
E 8
I 6
	long	st_blksize;
I 8
D 9
	long	st_spare4[3];
E 9
I 9
	long	st_blocks;
	long	st_spare4[2];
E 9
E 8
E 6
};

#define	S_IFMT	0170000		/* type of file */
#define		S_IFDIR	0040000	/* directory */
#define		S_IFCHR	0020000	/* character special */
#define		S_IFBLK	0060000	/* block special */
#define		S_IFREG	0100000	/* regular */
D 5
#define		S_IFMPC	0030000	/* multiplexed char special */
#define		S_IFMPB	0070000	/* multiplexed block special */
E 5
I 5
#define		S_IFLNK	0120000	/* symbolic link */
I 7
#define		S_IFSOCK 0140000/* socket */
E 7
E 5
#define	S_ISUID	0004000		/* set user id on execution */
#define	S_ISGID	0002000		/* set group id on execution */
#define	S_ISVTX	0001000		/* save swapped text even after use */
#define	S_IREAD	0000400		/* read permission, owner */
#define	S_IWRITE 0000200	/* write permission, owner */
#define	S_IEXEC	0000100		/* execute/search permission, owner */
E 1
