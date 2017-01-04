h43567
s 00007/00002/00065
d D 5.3 87/01/28 15:11:38 mckusick 12 11
c backward compatibility
e
s 00028/00018/00039
d D 5.2 86/10/21 15:57:45 mckusick 11 10
c make space for more dump information in the new dump header
e
s 00007/00001/00050
d D 5.1 85/06/05 08:50:26 dist 10 9
c Add copyright
e
s 00004/00001/00047
d D 2.6 85/03/24 18:00:23 mckusick 9 8
c add HIGHDENSITYTREC to define block size on high density tapes
e
s 00001/00003/00047
d D 2.5 83/08/11 22:56:54 sam 8 7
c standardize sccs keyword lines
e
s 00000/00004/00050
d D 2.4 82/10/14 11:54:36 mckusick 7 6
c get rid of (incorrect for 512 byte frags) BLKING macro
e
s 00000/00006/00054
d D 2.3 82/10/07 18:53:55 mckusick 6 5
c move out idates which is dump specific
e
s 00002/00001/00058
d D 2.2 82/10/07 18:20:12 mckusick 5 4
c create new magic number
e
s 00000/00000/00059
d D 2.1 82/03/30 17:16:37 mckusick 4 3
c merge into the new kernel
e
s 00014/00003/00045
d D 1.3 82/01/05 01:23:00 mckusic 3 2
c parameterize BSIZE, FSIZE, and FRAG into fs_bsize, fs_fsize, and fs_frag
e
s 00021/00013/00027
d D 1.2 81/11/07 14:56:16 mckusic 2 1
c dump to "standard" (ie 1K file system) dump tapes
e
s 00040/00000/00000
d D 1.1 81/10/31 18:36:40 mckusick 1 0
c date and time created 81/10/31 18:36:40 by mckusick
e
u
U
t
T
I 1
D 8
/* Copyright (c) 1981 Regents of the University of California */

/* "%Z%%M% %I% %G%" */
E 8
I 8
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 10
E 8

I 3
/*
 * TP_BSIZE is the size of file blocks on the dump tapes.
 * Note that TP_BSIZE must be a multiple of DEV_BSIZE.
 *
 * NTREC is the number of TP_BSIZE blocks that are written
D 9
 * in each tape record.
E 9
I 9
 * in each tape record. HIGHDENSITYTREC is the number of
 * TP_BSIZE blocks that are written in each tape record on
 * 6250 BPI or higher density tapes.
E 9
 *
D 7
 * BLKING calculates the number of TP_BSIZE blocks in a file
 * system frag.
 *
E 7
 * TP_NINDIR is the number of indirect pointers in a TS_INODE
 * or TS_ADDR record. Note that it must be a power of two.
 */
E 3
I 2
#define TP_BSIZE	1024
E 2
#define NTREC   	10
I 9
#define HIGHDENSITYTREC	32
E 9
D 3
#define MLEN    	16
#define MSIZ    	4096
I 2
#define BLKING		(FSIZE/TP_BSIZE)
E 3
I 3
D 7
#define BLKING(fs)	((fs)->fs_fsize/TP_BSIZE)
E 7
E 3
#define TP_NINDIR	(TP_BSIZE/2)
I 11
#define LBLSIZE		16
#define NAMELEN		64
E 11
E 2

D 11
#define TS_TAPE 	1
#define TS_INODE	2
#define TS_BITS 	3
#define TS_ADDR 	4
#define TS_END  	5
#define TS_CLRI 	6
E 11
D 5
#define MAGIC   	(int)60011
E 5
I 5
#define OFS_MAGIC   	(int)60011
#define NFS_MAGIC   	(int)60012
E 5
#define CHECKSUM	(int)84446

D 2
struct	spcl {
	int	c_type;
	time_t	c_date;
	time_t	c_ddate;
	int	c_volume;
	daddr_t	c_tapea;
	ino_t	c_inumber;
	int	c_magic;
	int	c_checksum;
	struct	dinode	c_dinode;
	int	c_count;
	char	c_addr[BSIZE];
} spcl;
E 2
I 2
union u_spcl {
	char dummy[TP_BSIZE];
	struct	s_spcl {
D 11
		int	c_type;
		time_t	c_date;
		time_t	c_ddate;
		int	c_volume;
		daddr_t	c_tapea;
		ino_t	c_inumber;
		int	c_magic;
		int	c_checksum;
		struct	dinode	c_dinode;
		int	c_count;
		char	c_addr[TP_NINDIR];
E 11
I 11
		long	c_type;		    /* record type (see below) */
		time_t	c_date;		    /* date of previous dump */
		time_t	c_ddate;	    /* date of this dump */
		long	c_volume;	    /* dump volume number */
		daddr_t	c_tapea;	    /* logical block of this record */
		ino_t	c_inumber;	    /* number of inode */
		long	c_magic;	    /* magic number (see above) */
		long	c_checksum;	    /* record checksum */
		struct	dinode	c_dinode;   /* ownership and mode of inode */
		long	c_count;	    /* number of valid c_addr entries */
		char	c_addr[TP_NINDIR];  /* 1 => data; 0 => hole in inode */
		char	c_label[LBLSIZE];   /* dump label */
		long	c_level;	    /* level of this dump */
		char	c_filesys[NAMELEN]; /* name of dumpped file system */
		char	c_dev[NAMELEN];	    /* name of dumpped device */
		char	c_host[NAMELEN];    /* name of dumpped host */
I 12
		long	c_flags;	    /* additional information */
E 12
E 11
	} s_spcl;
} u_spcl;
D 11

E 11
#define spcl u_spcl.s_spcl
I 11
/*
 * special record types
 */
D 12
#define TS_OTAPE 	1	/* 4.3BSD and earlier type dump tape header */
#define TS_TAPE 	7	/* dump tape header */
E 12
I 12
#define TS_TAPE 	1	/* dump tape header */
E 12
#define TS_INODE	2	/* beginning of file record */
#define TS_ADDR 	4	/* continuation of file record */
#define TS_BITS 	3	/* map of inodes on tape */
#define TS_CLRI 	6	/* map of inodes deleted since last dump */
#define TS_END  	5	/* end of volume marker */
I 12

/*
 * flag values
 */
#define DR_NEWHEADER	1	/* new format tape header */
E 12
E 11
E 2

D 6
struct	idates {
	char	id_name[16];
	char	id_incno;
	time_t	id_ddate;
};

E 6
#define	DUMPOUTFMT	"%-16s %c %s"		/* for printf */
						/* name, incno, ctime(date) */
#define	DUMPINFMT	"%16s %c %[^\n]\n"	/* inverse for scanf */
E 1
