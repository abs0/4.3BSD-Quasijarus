h48418
s 00003/00000/00095
d D 7.2 86/12/22 11:40:58 bostic 11 10
c bug report 4.1BSD/sys/31
e
s 00001/00001/00094
d D 7.1 86/06/04 23:21:09 mckusick 10 9
c 4.3BSD release version
e
s 00007/00001/00088
d D 6.2 85/06/08 14:55:38 mckusick 9 8
c Add copyright
e
s 00000/00000/00089
d D 6.1 83/07/29 06:11:59 sam 8 7
c 4.2 distribution
e
s 00026/00001/00063
d D 4.5 82/11/13 23:08:02 sam 7 6
c merge 4.1b and 4.1c
e
s 00049/00040/00015
d D 4.4 82/10/09 19:01:18 root 6 5
c better comments
e
s 00052/00007/00003
d D 4.3 82/04/19 19:26:48 mckusic 5 4
c merge in the new file system
e
s 00001/00001/00009
d D 4.2 81/02/19 21:39:59 wnj 4 3
c %G%->%E%
e
s 00000/00000/00010
d D 4.1 80/11/09 17:00:48 bill 3 2
c stamp for 4bsd
e
s 00001/00001/00009
d D 3.2 80/06/07 02:57:06 bill 2 1
c %H%->%G%
e
s 00010/00000/00000
d D 3.1 80/04/09 16:23:45 bill 1 0
c date and time created 80/04/09 16:23:45 by bill
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
D 9
/*	%M%	%I%	%E%	*/
E 9
I 9
/*
D 10
 * Copyright (c) 1982 Regents of the University of California.
E 10
I 10
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 9
E 4
E 2

D 5
#ifndef	DIRSIZ
#define	DIRSIZ	14
#endif
struct	direct
{
	ino_t	d_ino;
	char	d_name[DIRSIZ];
E 5
I 5
D 6
/* @(#)ndir.h 4.4 3/30/82 */

E 6
/*
D 6
 * This sets the "page size" for directories.
 * Requirements are DEV_BSIZE <= DIRBLKSIZ <= MINBSIZE with
 * DIRBLKSIZ a power of two.
 * Dennis Ritchie feels that directory pages should be atomic
 * operations to the disk, so we use DEV_BSIZE.
E 6
I 6
 * A directory consists of some number of blocks of DIRBLKSIZ
 * bytes, where DIRBLKSIZ is chosen such that it can be transferred
 * to disk in a single atomic operation (e.g. 512 bytes on most machines).
 *
 * Each DIRBLKSIZ byte block contains some number of directory entry
 * structures, which are of variable length.  Each directory entry has
 * a struct direct at the front of it, containing its inode number,
 * the length of the entry, and the length of the name contained in
 * the entry.  These are followed by the name padded to a 4 byte boundary
 * with null bytes.  All names are guaranteed null terminated.
 * The maximum length of a name in a directory is MAXNAMLEN.
 *
 * The macro DIRSIZ(dp) gives the amount of space required to represent
 * a directory entry.  Free space in a directory is represented by
 * entries which have dp->d_reclen > DIRSIZ(dp).  All DIRBLKSIZ bytes
 * in a directory block are claimed by the directory entries.  This
 * usually results in the last entry in a directory having a large
 * dp->d_reclen.  When entries are deleted from a directory, the
 * space is returned to the previous entry in the same directory
 * block by increasing its dp->d_reclen.  If the first entry of
 * a directory block is free, then its dp->d_ino is set to 0.
 * Entries other than the first in a directory do not normally have
 * dp->d_ino set to 0.
E 6
 */
I 7
/* so user programs can just include dir.h */
#if !defined(KERNEL) && !defined(DEV_BSIZE)
#define	DEV_BSIZE	512
#endif
E 7
D 6
#define DIRBLKSIZ DEV_BSIZE
E 6
I 6
#define DIRBLKSIZ	DEV_BSIZE
#define	MAXNAMLEN	255
E 6

D 6
/*
 * This limits the directory name length. Its main constraint
 * is that it appears twice in the user structure. (u. area)
 */
#define MAXNAMLEN 255

E 6
struct	direct {
D 6
	u_long	d_ino;
	short	d_reclen;
	short	d_namlen;
	char	d_name[MAXNAMLEN + 1];
	/* typically shorter */
E 6
I 6
	u_long	d_ino;			/* inode number of entry */
	u_short	d_reclen;		/* length of this record */
	u_short	d_namlen;		/* length of string in d_name */
	char	d_name[MAXNAMLEN + 1];	/* name must be no longer than this */
E 6
E 5
};
I 5

D 6
struct _dirdesc {
	int	dd_fd;
	long	dd_loc;
	long	dd_size;
	char	dd_buf[DIRBLKSIZ];
};

E 6
/*
D 6
 * useful macros.
E 6
I 6
 * The DIRSIZ macro gives the minimum record length which will hold
 * the directory entry.  This requires the amount of space in struct direct
 * without the d_name field, plus enough space for the name with a terminating
 * null byte (dp->d_namlen+1), rounded up to a 4 byte boundary.
E 6
 */
#undef DIRSIZ
#define DIRSIZ(dp) \
D 6
    ((sizeof(struct direct) - MAXNAMLEN + (dp)->d_namlen + sizeof(ino_t) - 1) &\
    ~(sizeof(ino_t) - 1))
typedef	struct _dirdesc DIR;
#ifndef	NULL
#define	NULL	0
#endif
E 6
I 6
    ((sizeof (struct direct) - (MAXNAMLEN+1)) + (((dp)->d_namlen+1 + 3) &~ 3))
E 6

I 6
#ifndef KERNEL
E 6
/*
D 6
 * functions defined on directories
E 6
I 6
 * Definitions for library routines operating on directories.
E 6
 */
D 6
extern DIR *opendir();
extern struct direct *readdir();
extern long telldir();
extern void seekdir();
#define rewinddir(dirp)	seekdir((dirp), 0)
extern void closedir();
E 6
I 6
typedef struct _dirdesc {
	int	dd_fd;
	long	dd_loc;
	long	dd_size;
	char	dd_buf[DIRBLKSIZ];
} DIR;
I 11

#define dirfd(dirp)	((dirp)->dd_fd)

E 11
I 7
#ifndef NULL
#define NULL 0
#endif
E 7
extern	DIR *opendir();
extern	struct direct *readdir();
extern	long telldir();
extern	void seekdir();
#define rewinddir(dirp)	seekdir((dirp), (long)0)
extern	void closedir();
D 7
#endif KERNEL
E 7
I 7
#endif

#ifdef KERNEL
/*
 * Template for manipulating directories.
 * Should use struct direct's, but the name field
 * is MAXNAMLEN - 1, and this just won't do.
 */
struct dirtemplate {
	u_long	dot_ino;
	short	dot_reclen;
	short	dot_namlen;
	char	dot_name[4];		/* must be multiple of 4 */
	u_long	dotdot_ino;
	short	dotdot_reclen;
	short	dotdot_namlen;
	char	dotdot_name[4];		/* ditto */
};
#endif
E 7
E 6
E 5
E 1
