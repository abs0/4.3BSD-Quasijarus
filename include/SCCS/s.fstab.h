h05277
s 00007/00001/00035
d D 5.1 85/05/30 09:36:18 dist 5 4
c Add copyright
e
s 00001/00001/00035
d D 4.4 83/05/24 13:46:46 sam 4 3
c typo....blast
e
s 00011/00008/00025
d D 4.3 83/05/24 10:39:55 sam 3 2
c quota file now fixed name, new type and function to search by type
e
s 00004/00009/00029
d D 4.2 83/05/19 17:41:42 sam 2 1
c byte the bullet and allow variable length names
e
s 00038/00000/00000
d D 4.1 83/05/03 13:47:58 sam 1 0
c date and time created 83/05/03 13:47:58 by sam
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
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 5

/*
 * File system table, see fstab (5)
 *
 * Used by dump, mount, umount, swapon, fsck, df, ...
 *
D 3
 * The fs_spec field is the block special name.
 * Programs that want to use the character special name must
 * create that name by prepending a 'r' after the right most slash.
E 3
I 3
 * The fs_spec field is the block special name.  Programs
 * that want to use the character special name must create
 * that name by prepending a 'r' after the right most slash.
 * Quota files are always named "quotas", so if type is "rq",
 * then use concatenation of fs_file and "quotas" to locate
 * quota file.
E 3
 */
D 3

E 3
#define	FSTAB		"/etc/fstab"
D 2
#define	FSNMLG		32
E 2

D 2
#define	FSTABFMT	"%32s:%32s:%2s:%d:%d\n"
#define	FSTABARG(p)	(p)->fs_spec, (p)->fs_file, \
			(p)->fs_type, &(p)->fs_freq, &(p)->fs_passno
#define FSTABNARGS	5

E 2
D 3
#define	FSTAB_RW	"rw"	/* read write device */
#define	FSTAB_RO	"ro"	/* read only device */
E 3
I 3
#define	FSTAB_RW	"rw"	/* read/write device */
D 4
#define	FSTAB_RQ	"rq",	/* read/write with quotas */
E 4
I 4
#define	FSTAB_RQ	"rq"	/* read/write with quotas */
E 4
#define	FSTAB_RO	"ro"	/* read-only device */
E 3
#define	FSTAB_SW	"sw"	/* swap device */
#define	FSTAB_XX	"xx"	/* ignore totally */

struct	fstab{
D 2
	char	fs_spec[FSNMLG];	/* block special device name */
	char	fs_file[FSNMLG];	/* file system path prefix */
	char	fs_type[3];		/* rw,ro,sw or xx */
E 2
I 2
	char	*fs_spec;		/* block special device name */
	char	*fs_file;		/* file system path prefix */
D 3
	char	*fs_type;		/* rw,ro,sw or xx */
	char	*fs_quotafile;		/* name of quota file if used */
E 3
I 3
	char	*fs_type;		/* FSTAB_* */
E 3
E 2
	int	fs_freq;		/* dump frequency, in days */
	int	fs_passno;		/* pass number on parallel dump */
};

struct	fstab *getfsent();
struct	fstab *getfsspec();
struct	fstab *getfsfile();
I 3
struct	fstab *getfstype();
E 3
int	setfsent();
int	endfsent();
E 1
