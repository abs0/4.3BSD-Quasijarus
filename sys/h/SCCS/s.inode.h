h33019
s 00003/00003/00195
d D 7.2 86/10/13 20:59:51 karels 43 42
c merge in tahoe system
e
s 00001/00001/00197
d D 7.1 86/06/04 23:23:42 mckusick 42 41
c 4.3BSD release version
e
s 00000/00001/00198
d D 6.11 85/11/26 12:37:52 karels 41 40
c now can use XTRC again instead of IXMOD
e
s 00001/00000/00198
d D 6.10 85/11/09 16:38:07 karels 40 39
c keep pointer to text in inode, avoiding linear search (later will be pointer
c to region(s) mapping the file)
e
s 00002/00002/00196
d D 6.9 85/10/28 15:04:03 karels 39 38
c use proper types for uids, gids
e
s 00007/00001/00191
d D 6.8 85/06/08 14:59:10 mckusick 38 37
c Add copyright
e
s 00001/00005/00191
d D 6.7 85/01/10 23:40:51 mckusick 37 36
c simplify (and fix) cacheinval macro
e
s 00001/00000/00195
d D 6.6 84/12/20 15:42:17 karels 36 35
c add IXMOD for now (for text modified with ptrace)
e
s 00001/00000/00194
d D 6.5 84/07/26 22:30:52 mckusick 35 34
c add IRENAME to prevent reentrant rename for same directory
e
s 00014/00000/00180
d D 6.4 84/07/20 01:11:25 mckusick 34 33
c add macro `cacheinval' to purge stale entries in the inode table
e
s 00002/00001/00178
d D 6.3 84/06/27 20:46:43 sam 33 32
c add unique id for namei cache -- allows . and .. to be held in cache
e
s 00016/00001/00163
d D 6.2 84/02/15 21:12:46 karels 32 31
c add IMOD flag, allowing update of times in in-core inode
c without immediate write to disk
e
s 00000/00000/00164
d D 6.1 83/07/29 06:12:39 sam 31 30
c 4.2 distribution
e
s 00000/00006/00164
d D 4.24 83/07/01 02:24:53 root 30 29
c purge #if sun's
e
s 00004/00001/00166
d D 4.23 83/05/21 15:59:50 sam 29 28
c i_blocks (from kre)
e
s 00001/00001/00166
d D 4.22 83/02/10 16:10:57 sam 28 27
c fix comment
e
s 00011/00000/00156
d D 4.21 82/12/17 12:10:58 sam 27 26
c sun merge
e
s 00025/00015/00131
d D 4.20 82/11/13 23:08:21 sam 26 25
c merge 4.1b and 4.1c
e
s 00001/00001/00145
d D 4.19 82/10/31 17:54:45 root 25 24
c i_socket is i_un.is_socket; i_un was missing
e
s 00002/00001/00144
d D 4.18 82/10/31 15:56:09 root 24 23
c s/PORTAL/SOCK/
e
s 00000/00001/00145
d D 4.17 82/10/20 02:10:06 root 23 22
c lint
e
s 00003/00003/00143
d D 4.16 82/10/20 01:16:06 root 22 21
c lint
e
s 00022/00001/00124
d D 4.15 82/10/10 17:12:31 root 21 20
c header file cleanup while moving vax files to their own directory
e
s 00013/00010/00112
d D 4.14 82/08/10 17:53:08 sam 20 19
c file locking and new open 
e
s 00002/00002/00120
d D 4.13 82/07/16 16:47:15 kre 19 18
c removed hlink (no longer used); added dquot (disc quota pointer);
c changed count from char to u_short (> 255 refs possible).
e
s 00009/00000/00113
d D 4.12 82/06/29 23:01:07 kre 18 17
c inode cache added (Chris Maltby, Sydney Uni originated this)
e
s 00074/00042/00039
d D 4.11 82/04/19 19:26:55 mckusic 17 16
c merge in the new file system
e
s 00001/00002/00080
d D 4.10 82/02/27 14:56:13 wnj 16 15
c symbolic links
e
s 00019/00012/00063
d D 4.9 81/11/14 16:50:58 wnj 15 14
c just before overlay of ip
e
s 00012/00023/00063
d D 4.8 81/11/08 16:44:25 wnj 14 13
c remove vfdcnt, IPIPE and IFPORT
e
s 00000/00017/00086
d D 4.7 81/10/17 16:14:12 wnj 13 12
c cleanup (mpx removal, old tty removal, beginnings of select)
e
s 00007/00000/00096
d D 4.6 81/06/15 18:07:34 root 12 11
c port id overlay
e
s 00002/00002/00094
d D 4.5 81/03/09 00:27:01 wnj 11 10
c lint
e
s 00002/00001/00094
d D 4.4 81/02/27 00:02:02 wnj 10 9
c move to pointer base to allow dyn allocation
e
s 00001/00001/00094
d D 4.3 81/02/19 21:40:47 wnj 9 8
c %G%->%E%
e
s 00001/00001/00094
d D 4.2 81/01/27 15:42:35 wnj 8 7
c reduce NINDEX to 6 to save a lot of space
e
s 00000/00000/00095
d D 4.1 80/11/09 17:01:05 bill 7 6
c stamp for 4bsd
e
s 00001/00001/00094
d D 3.6 80/06/07 02:58:01 bill 6 5
c %H%->%G%
e
s 00001/00001/00094
d D 3.5 80/06/04 14:59:28 bill 5 4
c repair from cosmetics
e
s 00001/00001/00094
d D 3.4 80/06/04 13:45:43 bill 4 3
c reformat
e
s 00010/00006/00085
d D 3.3 80/04/30 17:19:50 bill 3 2
c macros to get around new c compiler
e
s 00001/00000/00090
d D 3.2 80/04/11 10:17:46 bill 2 1
c add IPIPE bit for sake of writei
e
s 00090/00000/00000
d D 3.1 80/04/09 16:24:06 bill 1 0
c date and time created 80/04/09 16:24:06 by bill
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%H%	*/
E 6
I 6
D 9
/*	%M%	%I%	%G%	*/
E 9
I 9
D 38
/*	%M%	%I%	%E%	*/
E 38
I 38
/*
D 42
 * Copyright (c) 1982 Regents of the University of California.
E 42
I 42
D 43
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 43
I 43
 * Copyright (c) 1982 Regents of the University of California.
E 43
E 42
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 38
E 9
E 6

I 17
D 20
/*	inode.h	2.1	3/25/82	*/

E 20
E 17
/*
D 14
 * The I node is the focus of all
 * file activity in unix. There is a unique
 * inode allocated for each active file,
 * each current directory, each mounted-on
 * file, text file, and the root. An inode is 'named'
 * by its dev/inumber pair. (iget/iget.c)
 * Data, from mode on, is read in
 * from permanent inode on volume.
E 14
I 14
 * The I node is the focus of all file activity in UNIX.
 * There is a unique inode allocated for each active file,
 * each current directory, each mounted-on file, text file, and the root.
 * An inode is 'named' by its dev/inumber pair. (iget/iget.c)
D 17
 * Data, from mode on, is read in from permanent inode on volume.
E 17
I 17
 * Data in icommon is read in from permanent inode on volume.
E 17
E 14
 */
D 14

E 14
D 17
#define	NADDR	13
E 17

I 17
D 26
#define	NDADDR	8		/* direct addresses in inode */
#define	NIADDR	2		/* indirect addresses in inode */
E 26
I 26
#define	NDADDR	12		/* direct addresses in inode */
#define	NIADDR	3		/* indirect addresses in inode */
E 26

E 17
D 8
#define	NINDEX		15
E 8
I 8
D 13
#define	NINDEX		6
E 8
struct group
{
	short	g_state;
	char	g_index;
	char	g_rot;
	struct	group	*g_group;
	struct	inode	*g_inode;
	struct	file	*g_file;
	short	g_rotmask;
	short	g_datq;
	struct	chan *g_chans[NINDEX];
};
E 13
D 14
struct	inode
{
E 14
I 14
struct inode {
I 18
	struct	inode *i_chain[2];	/* must be first */
E 18
E 14
D 20
	char	i_flag;
E 20
I 20
	u_short	i_flag;
E 20
D 19
	char	i_count;	/* reference count */
E 19
I 19
	u_short	i_count;	/* reference count */
E 19
	dev_t	i_dev;		/* device where inode resides */
I 20
D 26
	u_short	i_rdlockc;	/* count of locked readers on inode */
	u_short	i_wrlockc;	/* count of locked writers on inode */
E 26
I 26
	u_short	i_shlockc;	/* count of shared locks on inode */
	u_short	i_exlockc;	/* count of exclusive locks on inode */
E 26
E 20
	ino_t	i_number;	/* i number, 1-to-1 with device address */
I 33
	long	i_id;		/* unique identifier */
E 33
D 14
	unsigned short i_mode;
E 14
I 14
D 17
/* begin read from disk */
	u_short	i_mode;
E 14
	short	i_nlink;	/* directory entries */
	short	i_uid;		/* owner */
	short	i_gid;		/* group of owner */
	off_t	i_size;		/* size of file */
E 17
I 17
D 19
	long	i_hlink;	/* link in hash chain (iget/iput/ifind) */
E 19
	struct	fs *i_fs;	/* file sys associated with this inode */
I 19
	struct	dquot *i_dquot;	/* quota structure controlling this file */
I 40
	struct	text *i_text;	/* text entry, if any (should be region) */
E 40
E 19
E 17
	union {
D 15
		struct {
D 3
			daddr_t	i_addr[NADDR];	/* if normal file/directory */
			daddr_t	i_lastr;	/* last logical block read (for read-ahead) */
		};
E 3
I 3
			daddr_t	I_addr[NADDR];	/* if normal file/directory */
D 4
			daddr_t	I_lastr;	/* last logical block read (for read-ahead) */
E 4
I 4
D 5
			daddr_t	I_last bnor;	/* last read (for read-ahead) */
E 5
I 5
D 14
			daddr_t	I_lastr;	/* last read (for read-ahead) */
E 14
I 14
			daddr_t	I_lastr;	/* last read (read-ahead) */
E 15
I 15
D 17
		struct i_f {
			daddr_t	if_addr[NADDR];	/* if normal file/directory */
			daddr_t	if_lastr;	/* last read (read-ahead) */
E 15
E 14
E 5
E 4
		} i_f;
D 15
#define	i_addr	i_f.I_addr
#define	i_lastr	i_f.I_lastr
E 3
		struct {
D 3
			daddr_t	i_rdev;		/* i_addr[0] */
			struct	group i_group;	/* multiplexor group file */
		};
E 3
I 3
			daddr_t	I_rdev;		/* i_addr[0] */
E 15
I 15
		struct i_d {
			daddr_t	id_rdev;	/* i_addr[0] */
E 15
D 13
			struct	group I_group;	/* multiplexor group file */
E 13
		} i_d;
D 15
#define	i_rdev	i_d.I_rdev
E 15
I 15
		struct i_s {
			struct	socket *is_socket;
		} i_s;
#define	i_addr		i_f.if_addr
#define	i_lastr		i_f.if_lastr
#define	i_rdev		i_d.id_rdev
#define	i_socket	i_s.is_socket
E 17
I 17
		daddr_t	if_lastr;	/* last read (read-ahead) */
		struct	socket *is_socket;
I 18
		struct	{
			struct inode  *if_freef;	/* free list forward */
			struct inode **if_freeb;	/* free list back */
		} i_fr;
E 18
E 17
E 15
D 13
#define	i_group	i_d.I_group
E 13
I 12
D 14
		struct {
			daddr_t	I_port0;	/* low 16 bits of portid */
			daddr_t	I_port1;	/* high 16 bits of portid */
		} i_p;
#define	i_port0	i_p.I_port0
#define	i_port1	i_p.I_port1
E 14
E 12
E 3
	} i_un;
D 14
	short	i_vfdcnt;	/* number of fd's vreading this inode */
E 14
I 14
D 17
/* end read from disk */
	short	i_XXXXXX;	/* ### */
/* SHOULD USE POINTERS, NOT INDICES, FOR HAS CHAIN */
E 14
	short	i_hlink;	/* link in hash chain (iget/iput/ifind) */
E 17
I 17
	struct 	icommon
	{
		u_short	ic_mode;	/*  0: mode and type of file */
		short	ic_nlink;	/*  2: number of links to file */
D 39
		short	ic_uid;		/*  4: owner's user id */
		short	ic_gid;		/*  6: owner's group id */
E 39
I 39
		uid_t	ic_uid;		/*  4: owner's user id */
		gid_t	ic_gid;		/*  6: owner's group id */
E 39
D 26
		off_t	ic_size;	/*  8: number of bytes in file */
		daddr_t	ic_db[NDADDR];	/* 12: disk block addresses */
		daddr_t	ic_ib[NIADDR];	/* 44: indirect blocks */
		time_t	ic_atime;	/* 52: time last accessed */
		time_t	ic_mtime;	/* 56: time last modified */
		time_t	ic_ctime;	/* 60: time created */
E 26
I 26
		quad	ic_size;	/*  8: number of bytes in file */
		time_t	ic_atime;	/* 16: time last accessed */
		long	ic_atspare;
		time_t	ic_mtime;	/* 24: time last modified */
		long	ic_mtspare;
D 28
		time_t	ic_ctime;	/* 32: time created */
E 28
I 28
		time_t	ic_ctime;	/* 32: last time inode changed */
E 28
		long	ic_ctspare;
		daddr_t	ic_db[NDADDR];	/* 40: disk block addresses */
		daddr_t	ic_ib[NIADDR];	/* 88: indirect blocks */
		long	ic_flags;	/* 100: status, currently unused */
D 29
		long	ic_spare[6];	/* 104: reserved, currently unused */
E 29
I 29
		long	ic_blocks;	/* 104: blocks actually held */
		long	ic_spare[5];	/* 108: reserved, currently unused */
E 29
E 26
	} i_ic;
E 17
};

I 17
struct dinode {
	union {
		struct	icommon di_icom;
D 26
		char	di_size[64];
E 26
I 26
		char	di_size[128];
E 26
	} di_un;
};

#define	i_mode		i_ic.ic_mode
#define	i_nlink		i_ic.ic_nlink
#define	i_uid		i_ic.ic_uid
#define	i_gid		i_ic.ic_gid
I 27
/* ugh! -- must be fixed */
D 43
#ifdef vax
E 43
I 43
#if defined(vax) || defined(tahoe)
E 43
E 27
D 26
#define	i_size		i_ic.ic_size
E 26
I 26
#define	i_size		i_ic.ic_size.val[0]
I 27
#endif
D 30
#ifdef sun
#define	i_size		i_ic.ic_size.val[1]
#endif
E 30
E 27
E 26
#define	i_db		i_ic.ic_db
#define	i_ib		i_ic.ic_ib
#define	i_atime		i_ic.ic_atime
#define	i_mtime		i_ic.ic_mtime
#define	i_ctime		i_ic.ic_ctime
I 29
#define i_blocks	i_ic.ic_blocks
E 29
#define	i_rdev		i_ic.ic_db[0]
#define	i_lastr		i_un.if_lastr
D 25
#define	i_socket	is_socket
E 25
I 25
#define	i_socket	i_un.is_socket
E 25
I 18
#define	i_forw		i_chain[0]
#define	i_back		i_chain[1]
#define	i_freef		i_un.i_fr.if_freef
#define	i_freeb		i_un.i_fr.if_freeb
E 18

#define di_ic		di_un.di_icom
#define	di_mode		di_ic.ic_mode
#define	di_nlink	di_ic.ic_nlink
#define	di_uid		di_ic.ic_uid
#define	di_gid		di_ic.ic_gid
I 27
D 43
#ifdef vax
E 43
I 43
#if defined(vax) || defined(tahoe)
E 43
E 27
D 26
#define	di_size		di_ic.ic_size
E 26
I 26
#define	di_size		di_ic.ic_size.val[0]
I 27
D 30
#endif
#ifdef sun
#define	di_size		di_ic.ic_size.val[1]
E 30
#endif
E 27
E 26
#define	di_db		di_ic.ic_db
#define	di_ib		di_ic.ic_ib
#define	di_atime	di_ic.ic_atime
#define	di_mtime	di_ic.ic_mtime
#define	di_ctime	di_ic.ic_ctime
#define	di_rdev		di_ic.ic_db[0]
I 29
#define	di_blocks	di_ic.ic_blocks
E 29

E 17
#ifdef KERNEL
I 34
/*
 * Invalidate an inode. Used by the namei cache to detect stale
 * information. At an absurd rate of 100 calls/second, the inode
 * table invalidation should only occur once every 16 months.
 */
#define cacheinval(ip)	\
D 37
{ \
	struct inode *xp; \
E 37
	(ip)->i_id = ++nextinodeid; \
	if (nextinodeid == 0) \
D 37
		for (nextinodeid = 0, xp = inode; xp < inodeNINODE; xp++) \
			xp->i_id = 0; \
}
E 37
I 37
		cacheinvalall();
E 37

E 34
D 10
extern	struct inode inode[];	/* The inode table itself */
E 10
I 10
D 11
extern	struct inode *inode, *inodeNINODE;/* The inode table itself */
extern	int ninode;
E 11
I 11
D 17
struct	inode *inode, *inodeNINODE;
int	ninode;
E 17
I 17
D 22
extern	struct inode *inode;		/* The inode table itself */
extern	struct inode *inodeNINODE;	/* The end of the inode table */
extern	int ninode;			/* number of slots in the table */
E 22
I 22
struct inode *inode;		/* the inode table itself */
struct inode *inodeNINODE;	/* the end of the inode table */
int	ninode;			/* number of slots in the table */
I 33
long	nextinodeid;		/* unique id generator */
E 33
E 22
E 17
E 11
E 10

D 17
struct	inode *rootdir;		/* pointer to inode of root directory */
E 17
I 17
struct	inode *rootdir;			/* pointer to inode of root directory */
E 17
D 14
struct	inode *mpxip;		/* mpx virtual inode */
E 14

struct	inode *ialloc();
D 23
struct	inode *ifind();
E 23
struct	inode *iget();
I 26
#ifdef notdef
struct	inode *ifind();
#endif
E 26
struct	inode *owner();
struct	inode *maknode();
struct	inode *namei();
I 26

ino_t	dirpref();
E 26
#endif

/* flags */
D 20
#define	ILOCK	01		/* inode is locked */
#define	IUPD	02		/* file has been modified */
#define	IACC	04		/* inode access time to be updated */
#define	IMOUNT	010		/* inode is mounted on */
#define	IWANT	020		/* some process waiting on lock */
#define	ITEXT	040		/* inode is pure text prototype */
#define	ICHG	0100		/* inode has been changed */
E 20
I 20
D 21
#define	ILOCK		0x1		/* inode is locked */
E 21
I 21
#define	ILOCKED		0x1		/* inode is locked */
E 21
#define	IUPD		0x2		/* file has been modified */
#define	IACC		0x4		/* inode access time to be updated */
#define	IMOUNT		0x8		/* inode is mounted on */
#define	IWANT		0x10		/* some process waiting on lock */
#define	ITEXT		0x20		/* inode is pure text prototype */
#define	ICHG		0x40		/* inode has been changed */
D 26
#define	IRDLOCK		0x80		/* file is read locked */
#define	IWRLOCK		0x100		/* file is write locked */
E 26
I 26
#define	ISHLOCK		0x80		/* file has shared lock */
#define	IEXLOCK		0x100		/* file has exclusive lock */
E 26
#define	ILWAIT		0x200		/* someone waiting on file lock */
I 32
#define	IMOD		0x400		/* inode has been modified */
I 35
#define	IRENAME		0x800		/* inode is being renamed */
I 36
D 41
#define	IXMOD		0x8000		/* inode is text, but impure (XXX) */
E 41
E 36
E 35
E 32
E 20
I 2
D 14
#define	IPIPE	0200		/* inode is a pipe */
E 14
E 2

/* modes */
D 17
#define	IFMT	0170000		/* type of file */
D 15
#define		IFDIR	0040000	/* directory */
#define		IFCHR	0020000	/* character special */
#define		IFBLK	0060000	/* block special */
#define		IFREG	0100000	/* regular */
E 15
I 15
#define		IFCHR		0020000		/* character special */
#define		IFDIR		0040000		/* directory */
#define		IFBLK		0060000		/* block special */
#define		IFREG		0100000		/* regular */
D 16
#define		IFSYMREG	0110000		/* regular symbolic link */
#define		IFSYMDIR	0130000		/* directory symbolic link */
E 16
I 16
#define		IFLNK		0120000		/* symbolic link */
E 16
#define		IFPORTAL	0140000		/* portal */
E 15
I 12
D 14
#define		IFPORT	0010000	/* named port */
E 14
E 12
D 13
#define		IFMPC	0030000	/* multiplexed char special */
#define		IFMPB	0070000	/* multiplexed block special */
E 13
#define	ISUID	04000		/* set user id on execution */
#define	ISGID	02000		/* set group id on execution */
#define	ISVTX	01000		/* save swapped text even after use */
#define	IREAD	0400		/* read, write, execute permissions */
#define	IWRITE	0200
#define	IEXEC	0100
E 17
I 17
#define	IFMT		0170000		/* type of file */
#define	IFCHR		0020000		/* character special */
#define	IFDIR		0040000		/* directory */
#define	IFBLK		0060000		/* block special */
#define	IFREG		0100000		/* regular */
#define	IFLNK		0120000		/* symbolic link */
D 24
#define	IFPORTAL	0140000		/* portal */
E 24
I 24
#define	IFSOCK		0140000		/* socket */

E 24
#define	ISUID		04000		/* set user id on execution */
#define	ISGID		02000		/* set group id on execution */
#define	ISVTX		01000		/* save swapped text even after use */
#define	IREAD		0400		/* read, write, execute permissions */
#define	IWRITE		0200
#define	IEXEC		0100
I 21

#define	ILOCK(ip) { \
	while ((ip)->i_flag & ILOCKED) { \
		(ip)->i_flag |= IWANT; \
		sleep((caddr_t)(ip), PINOD); \
	} \
	(ip)->i_flag |= ILOCKED; \
}

#define	IUNLOCK(ip) { \
	(ip)->i_flag &= ~ILOCKED; \
	if ((ip)->i_flag&IWANT) { \
		(ip)->i_flag &= ~IWANT; \
		wakeup((caddr_t)(ip)); \
	} \
}

#define	IUPDAT(ip, t1, t2, waitfor) { \
D 32
	if (ip->i_flag&(IUPD|IACC|ICHG)) \
E 32
I 32
	if (ip->i_flag&(IUPD|IACC|ICHG|IMOD)) \
E 32
		iupdat(ip, t1, t2, waitfor); \
}
I 32

#define	ITIMES(ip, t1, t2) { \
	if ((ip)->i_flag&(IUPD|IACC|ICHG)) { \
		(ip)->i_flag |= IMOD; \
		if ((ip)->i_flag&IACC) \
			(ip)->i_atime = (t1)->tv_sec; \
		if ((ip)->i_flag&IUPD) \
			(ip)->i_mtime = (t2)->tv_sec; \
		if ((ip)->i_flag&ICHG) \
			(ip)->i_ctime = time.tv_sec; \
		(ip)->i_flag &= ~(IACC|IUPD|ICHG); \
	} \
}
D 33

E 33
E 32
E 21
E 17
E 1
