h24053
s 00001/00001/00115
d D 7.12 89/05/23 17:15:42 bostic 34 33
c back to normal
c (may have been distributed as revision 7.7)
e
s 00001/00001/00115
d D 7.11 89/05/23 17:14:36 bostic 33 32
c hack to allow HCX-9 to autoboot
c (may have been distributed as revision 7.6)
e
s 00023/00014/00093
d D 7.10 88/09/29 16:54:23 bostic 32 31
c minor cleanup, Berkeley copyright notice
c (may have been distributed as revision 7.5)
e
s 00002/00001/00105
d D 7.9 88/09/12 12:46:55 bostic 31 30
c alias i_bus to i_adapt
c (may have been distributed as revision 7.4)
e
s 00005/00000/00101
d D 7.8 88/03/02 15:54:44 bostic 30 29
c add codes for sector header word 1
c (may have been distributed as revision 7.3)
e
s 00002/00000/00099
d D 7.7 88/03/02 15:53:00 bostic 29 28
c add F_'s from tahoestand
c (may have been distributed as revision 7.2)
e
s 00023/00046/00076
d D 7.6 88/03/02 11:59:56 bostic 28 27
c moved from vaxstand directory; split out disk ioctl's, cleanup
c (may have been distributed as revision 7.1)
e
s 00018/00022/00104
d D 7.5 88/03/02 11:57:47 bostic 27 26
c last version for the vaxstand directory
e
s 00014/00000/00112
d D 7.4 87/12/12 23:36:36 karels 26 25
c need struct st for a while yet
e
s 00001/00001/00111
d D 7.3 87/02/21 11:44:25 karels 25 24
c restore keywords
e
s 00004/00015/00108
d D 7.2 87/02/21 11:41:41 karels 24 23
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00122
d D 7.1 86/06/05 01:44:50 mckusick 23 22
c 4.3BSD release version
e
s 00003/00011/00120
d D 6.4 85/11/08 19:15:52 karels 22 21
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00007/00001/00124
d D 6.3 85/06/08 13:11:38 mckusick 21 20
c Add copyright
e
s 00003/00000/00122
d D 6.2 83/09/23 10:07:17 karels 20 19
c ghg's severe burnin format
e
s 00000/00000/00122
d D 6.1 83/07/29 07:47:36 sam 19 18
c 4.2 distribution
e
s 00033/00037/00089
d D 4.14 83/03/01 22:40:45 sam 18 17
c add debug ioctl; move vax stuff to savax.h; cleanup for grinding
e
s 00015/00013/00111
d D 4.13 83/02/18 03:15:20 sam 17 16
c cleanup
e
s 00001/00000/00123
d D 4.12 83/02/01 14:44:40 helge 16 15
c new ioctl command to find if a device has skip sector handling.
e
s 00000/00002/00123
d D 4.11 83/01/31 16:40:19 helge 15 13
c removed i_active: not used
e
s 00000/00001/00124
d R 4.11 83/01/29 14:50:09 helge 14 13
c removed i_active: not used
e
s 00006/00000/00119
d D 4.10 83/01/27 11:40:04 helge 13 12
c more new ioctl commands
e
s 00006/00010/00113
d D 4.9 83/01/17 10:38:16 helge 12 11
c moved def of st structure from drivers
e
s 00027/00001/00096
d D 4.8 83/01/16 14:43:44 helge 11 10
c new ioctl commands and other stuff
e
s 00038/00005/00059
d D 4.7 82/12/30 15:30:49 sam 10 9
c add ioctl's + errno; fix chk to work with new stuff
e
s 00005/00000/00059
d D 4.6 82/03/30 17:04:58 mckusic 9 8
c add PHYSXXXX defines
e
s 00007/00002/00052
d D 4.5 82/02/28 16:58:10 mckusic 8 7
c put in new headers
e
s 00000/00009/00054
d D 4.4 81/03/15 20:49:40 wnj 7 6
c 
e
s 00000/00008/00063
d D 4.3 80/12/26 12:28:40 wnj 6 5
c remove PHYSU* which is now in uba.h
e
s 00007/00000/00064
d D 4.2 80/12/17 12:28:46 wnj 5 4
c conditionals for 750/780
e
s 00000/00000/00064
d D 4.1 80/11/09 16:29:37 bill 4 3
c stamp for 4bsd
e
s 00000/00004/00064
d D 1.3 80/07/29 15:09:38 bill 3 2
c work w/o mba's
e
s 00009/00000/00059
d D 1.2 80/07/28 10:05:14 bill 2 1
c mbaact, etc
e
s 00059/00000/00000
d D 1.1 80/06/28 10:43:09 bill 1 0
c date and time created 80/06/28 10:43:09 by bill
e
u
U
t
T
I 1
D 21
/*	%M%	%I%	%G%	*/
E 21
I 21
/*
D 23
 * Copyright (c) 1982 Regents of the University of California.
E 23
I 23
D 24
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 24
I 24
D 28
 * Copyright (c) 1982 Regents of the University of California.
E 28
I 28
D 32
 * Copyright (c) 1982, 1988 Regents of the University of California.
E 28
E 24
E 23
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
E 32
I 32
 * Copyright (c) 1982, 1988 The Regents of the University of California.
 * All rights reserved.
E 32
 *
I 32
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
E 32
D 24
 *	%W% (Berkeley) %G%
E 24
I 24
D 25
 *	@(#)saio.h	6.4 (Berkeley) 11/8/85
E 25
I 25
 *	%W% (Berkeley) %G%
E 25
E 24
 */
E 21

D 28
/*
D 18
 * header file for standalone package
E 18
I 18
 * Header file for standalone package
E 18
 */

E 28
I 28
#include "saioctl.h"
E 28
I 27
#include "saerrno.h"

D 33
#define	UNIX	"/vmunix"
E 33
I 33
D 34
#define	UNIX	"hd(6,0,0) /vmunix"
E 34
I 34
#define	UNIX	"/vmunix"
E 34
E 33
I 28
#define	NULL	0
E 28

E 27
/*
D 18
 * io block: includes an
E 18
I 18
D 27
 * Io block: includes an
E 18
 * inode, cells for the use of seek, etc,
E 27
I 27
 * Io block: includes an inode, cells for the use of seek, etc.,
E 27
 * and a buffer.
 */
D 28
struct	iob {
E 28
I 28
struct iob {
E 28
D 10
	char	i_flgs;
E 10
I 10
D 18
	int	i_flgs;
E 10
	struct	inode i_ino;
	int	i_unit;
	daddr_t	i_boff;
	daddr_t	i_cyloff;
	off_t	i_offset;
	daddr_t	i_bn;
	char	*i_ma;
	int	i_cc;
I 10
	int	i_error;
	int	i_errcnt;
I 11
	int	i_errblk;
E 11
D 15
	int	i_active;
E 15
E 10
D 8
	char	i_buf[BSIZE];
E 8
I 8
	char	i_buf[MAXBSIZE];
E 18
I 18
	int	i_flgs;		/* see F_ below */
D 27
	struct	inode i_ino;	/* inode, if file */
E 27
I 27
D 31
	int	i_adapt;	/* adapter */
E 31
I 31
	int	i_adapt;	/* adapter or bus */
E 31
	int	i_ctlr;		/* controller */
E 27
	int	i_unit;		/* pseudo device unit */
I 27
	int	i_part;		/* disk partition */
E 27
	daddr_t	i_boff;		/* block offset on device */
I 27
	struct	inode i_ino;	/* inode, if file */
E 27
	daddr_t	i_cyloff;	/* cylinder offset on device */
	off_t	i_offset;	/* seek offset in file */
	daddr_t	i_bn;		/* 1st block # of next read */
	char	*i_ma;		/* memory address of i/o buffer */
	int	i_cc;		/* character count of transfer */
	int	i_error;	/* error # return */
	int	i_errcnt;	/* error count for driver retries */
	int	i_errblk;	/* block # in error for error reporting */
	char	i_buf[MAXBSIZE];/* i/o buffer */
E 18
	union {
D 18
		struct fs ui_fs;
E 18
I 18
		struct fs ui_fs;	/* file system super block info */
E 18
		char dummy[SBSIZE];
	} i_un;
E 8
};
I 32

E 32
I 8
D 28
#define i_fs i_un.ui_fs
I 11
#define NULL 0
E 28
I 28
#define	i_fs	i_un.ui_fs
I 31
#define	i_bus	i_adapt
E 31
E 28
E 11
E 8

I 30
/* codes for sector header word 1 */
#define	HDR1_FMT22	0x1000	/* standard 16 bit format */
#define	HDR1_OKSCT	0xc000	/* sector ok */
#define	HDR1_SSF	0x2000	/* skip sector flag */

E 30
D 10
#define F_READ	01
#define F_WRITE	02
#define F_ALLOC	04
#define F_FILE	010
E 10
I 10
D 28
#define F_READ		0x1	/* file opened for reading */
#define F_WRITE		0x2	/* file opened for writing */
#define F_ALLOC		0x4	/* buffer allocated */
#define F_FILE		0x8	/* file instead of device */
I 11
#define F_NBSF		0x10	/* no bad sector forwarding */
D 17
#define F_ECCLM		0x20	/* limit the number of bad bits accepted in ecc's */
I 13
#define F_SSI		0x40	/* set skip sector inhibit,
				 * enable access to all sectors */
E 17
I 17
D 22
#define F_ECCLM		0x20	/* limit # of bits in ecc correction */
E 22
#define F_SSI		0x40	/* set skip sector inhibit */
E 28
I 28
D 32
#define	F_READ		0x1	/* file opened for reading */
#define	F_WRITE		0x2	/* file opened for writing */
#define	F_ALLOC		0x4	/* buffer allocated */
#define	F_FILE		0x8	/* file instead of device */
#define	F_NBSF		0x10	/* no bad sector forwarding */
I 29
#define	F_ECCLM		0x20	/* limit # of bits in ecc correction */
E 29
#define	F_SSI		0x40	/* set skip sector inhibit */
I 29
#define	F_SEVRE		0x80	/* Severe burnin (no retries, no ECC) */
E 32
I 32
#define	F_READ		0x0001	/* file opened for reading */
#define	F_WRITE		0x0002	/* file opened for writing */
#define	F_ALLOC		0x0004	/* buffer allocated */
#define	F_FILE		0x0008	/* file instead of device */
#define	F_NBSF		0x0010	/* no bad sector forwarding */
#define	F_ECCLM		0x0020	/* limit # of bits in ecc correction */
#define	F_SSI		0x0040	/* set skip sector inhibit */
#define	F_SEVRE		0x0080	/* Severe burnin (no retries, no ECC) */
E 32
E 29
E 28
I 27

E 27
I 20
D 22
#define F_SEVRE		0x80	/* Severe burnin (no retries, no ECC) */
E 22
E 20
E 17
E 13
E 11
/* io types */
#define	F_RDDATA	0x0100	/* read data */
#define	F_WRDATA	0x0200	/* write data */
D 28
#define F_HDR		0x0400	/* include header on next i/o */
#define F_CHECK		0x0800	/* perform check of data read/write */
#define F_HCHECK	0x1000	/* perform check of header and data */
E 28
I 28
#define	F_HDR		0x0400	/* include header on next i/o */
#define	F_CHECK		0x0800	/* perform check of data read/write */
#define	F_HCHECK	0x1000	/* perform check of header and data */
E 28
E 10

I 10
#define	F_TYPEMASK	0xff00

E 10
D 32
/*
I 28
 * Request codes. Must be the same as F_XXX above
 */
E 32
#define	READ	F_READ
#define	WRITE	F_WRITE

/*
E 28
I 27
 * Lseek call.
 */
#define	L_SET		0	/* absolute offset */

/*
E 27
D 18
 * dev switch
E 18
I 18
 * Device switch.
E 18
 */
struct devsw {
	char	*dv_name;
	int	(*dv_strategy)();
	int	(*dv_open)();
	int	(*dv_close)();
I 10
	int	(*dv_ioctl)();
E 10
};

D 28
struct devsw devsw[];
I 24
int ndevs;
E 28
I 28
extern struct devsw devsw[];	/* device array */
extern int ndevs;		/* number of elements in devsw[] */
E 28
E 24

I 26
#ifdef COMPAT_42
/*
 * Old drive description table.
 * still used by some drivers for now.
 */
struct st {
	short	nsect;		/* # sectors/track */
	short	ntrak;		/* # tracks/surfaces/heads */
	short	nspc;		/* # sectors/cylinder */
	short	ncyl;		/* # cylinders */
	short	*off;		/* partition offset table (cylinders) */
};
#endif

E 26
I 17
D 28
/*
D 24
 * Drive description table.
 * Returned from SAIODEVDATA call.
 */
E 17
I 11
D 12
/* 
 * device data structure,
 * used by the ioctl-command SAIODEVDATA ( for disks only)
 */

struct devdata {
	int	nsect;	/* number of sectors per track */
	int	ntrak;	/* number of tracks/surfaces/heads... */
	int	nspc;	/* number of sectors per cylinder */
	int	ncyl;	/* number of cylinders */
E 12
I 12
struct st {
D 17
	short	nsect;	/* number of sectors per track */
	short	ntrak;	/* number of tracks/surfaces/heads... */
	short	nspc;	/* number of sectors per cylinder */
	short	ncyl;	/* number of cylinders */
	short	*off;
E 17
I 17
	short	nsect;		/* # sectors/track */
D 18
	short	ntrak;		/* # tracks/surfaces/heads... */
E 18
I 18
	short	ntrak;		/* # tracks/surfaces/heads */
E 18
	short	nspc;		/* # sectors/cylinder */
	short	ncyl;		/* # cylinders */
	short	*off;		/* partition offset table (cylinders) */
E 17
I 13
D 15
	short	sflg;	/* skip sector flag */
E 15
E 13
E 12
};

E 11
/*
E 24
D 18
 * request codes. Must be the same a F_XXX above
E 18
I 18
D 27
 * Request codes. Must be the same a F_XXX above
E 27
I 27
 * Request codes. Must be the same as F_XXX above
E 27
E 18
 */
D 27
#define	READ	1
#define	WRITE	2
E 27
I 27
#define	READ	F_READ
#define	WRITE	F_WRITE
E 27

#define	NBUFS	4

D 8
char	b[NBUFS][BSIZE];
E 8
I 8
char	b[NBUFS][MAXBSIZE];
E 8
daddr_t	blknos[NBUFS];

E 28
D 18
#define NFILES	4
E 18
I 18
#define	NFILES	4
E 18
D 28
struct	iob iob[NFILES];
I 9
D 27

D 18
#define	PHYSUBA0	0x20006000
#define	PHYSMBA0	0x20010000
#define	PHYSMBA1	0x20012000
#define	PHYSUMEM	0x2013e000
I 10

E 18
extern	int errno;	/* just like unix */

/* error codes */
#define	EBADF	1	/* bad file descriptor */
#define	EOFFSET	2	/* relative seek not supported */
#define	EDEV	3	/* improper device specification on open */
#define	ENXIO	4	/* unknown device specified */
#define	EUNIT	5	/* improper unit specification */
#define	ESRCH	6	/* directory search for file failed */
#define	EIO	7	/* generic error */
D 18
#define ECMD	10	/* undefined driver command */
#define EBSE	11	/* bad sector error */
#define EWCK	12	/* write check error */
#define EHER	13	/* hard error */
D 17
#define EECC	14	/* severe ecc error, sector recorded as bad*/
E 17
I 17
#define EECC	14	/* uncorrectable ecc error */
E 18
I 18
#define	ECMD	10	/* undefined driver command */
#define	EBSE	11	/* bad sector error */
#define	EWCK	12	/* write check error */
#define	EECC	13	/* uncorrectable ecc error */
#define	EHER	14	/* hard error */
E 27
E 18
E 17

/* ioctl's -- for disks just now */
D 11
#define	SAIOHDR	(('d'<<8)|1)	/* next i/o includes header */
E 11
I 11
#define	SAIOHDR		(('d'<<8)|1)	/* next i/o includes header */
E 11
#define	SAIOCHECK	(('d'<<8)|2)	/* next i/o checks data */
#define	SAIOHCHECK	(('d'<<8)|3)	/* next i/o checks header & data */
I 11
#define	SAIONOBAD	(('d'<<8)|4)	/* inhibit bad sector forwarding */
D 17
#define	SAIODOBAD	(('d'<<8)|5)	/* do bad sector forwarding */
#define	SAIOECCLIM	(('d'<<8)|6)	/* report sectors as bad if more than
					 * 5 bits are bad in ecc */
E 17
I 17
#define	SAIODOBAD	(('d'<<8)|5)	/* enable bad sector forwarding */
D 22
#define	SAIOECCLIM	(('d'<<8)|6)	/* limit ecc correction to 5 bits */
E 17
#define	SAIOECCUNL	(('d'<<8)|7)	/* use standard ecc procedures */
E 22
I 22
#define	SAIOECCLIM	(('d'<<8)|6)	/* set limit to ecc correction, bits */
#define	SAIORETRIES	(('d'<<8)|7)	/* set retry count for unit */
E 22
D 18
#define SAIODEVDATA	(('d'<<8)|8)	/* get device data */
I 13
#define SAIOSSI		(('d'<<8)|9)	/* set skip sector inhibit */
D 17
#define SAIONOSSI	(('d'<<8)|10)	/* normal skip sector handling */
E 17
I 17
#define SAIONOSSI	(('d'<<8)|10)	/* inhibit skip sector handling */
E 17
I 16
#define SAIOSSDEV	(('d'<<8)|11)	/* is device skip sector type? */
E 18
I 18
D 24
#define	SAIODEVDATA	(('d'<<8)|8)	/* get device data */
E 24
I 24
#define	SAIODEVDATA	(('d'<<8)|8)	/* get pointer to pack label */
E 24
#define	SAIOSSI		(('d'<<8)|9)	/* set skip sector inhibit */
#define	SAIONOSSI	(('d'<<8)|10)	/* inhibit skip sector handling */
#define	SAIOSSDEV	(('d'<<8)|11)	/* is device skip sector type? */
#define	SAIODEBUG	(('d'<<8)|12)	/* enable/disable debugging */
I 20
D 22
#define	SAIOSEVRE	(('d'<<8)|13)	/* severe burnin, no ECC, no retries */
#define	SAIONSEVRE	(('d'<<8)|14)	/* clear severe burnin */
E 20
E 18
E 16
E 13

/* codes for sector header word 1 */
D 18
#define HDR1_FMT22	0x1000	/* standard 16 bit format */
#define HDR1_OKSCT	0xc000	/* sector ok */
I 13
#define HDR1_SSF	0x2000	/* skip sector flag */
E 18
I 18
#define	HDR1_FMT22	0x1000	/* standard 16 bit format */
#define	HDR1_OKSCT	0xc000	/* sector ok */
#define	HDR1_SSF	0x2000	/* skip sector flag */
E 22
I 22
#define	SAIOGBADINFO	(('d'<<8)|13)	/* get bad-sector table */
E 28
I 28
extern struct	iob iob[NFILES];
E 28
E 22
E 18
E 13
E 11
E 10
E 9
D 7

I 5
D 6
#if VAX==780
E 5
#define	PHYSUBA0	0x20006000
D 3
#define	PHYSMBA0	0x20010000
#define	PHYSMBA1	0x20012000
E 3
#define	PHYSUMEM	0x2013e000
I 5
#else
#define	PHYSUBA0	0xf30000
#define	PHYSUMEM	0xfc0000+0760000
#endif
E 5
I 2
D 3

#define	MBAINIT		0x1
E 3

E 6
int	mbaact;

I 5
#if VAX==780
E 5
struct mba_info
{
	struct	mba_regs *mi_phys;	/* physical address of mba */
};
I 5
#endif
E 7
E 5
E 2
E 1
