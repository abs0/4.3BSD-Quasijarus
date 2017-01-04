h06806
s 00007/00002/00146
d D 7.7 88/07/09 14:39:59 karels 19 18
c check adaptor numbers against actual number
e
s 00007/00008/00141
d D 7.6 88/03/03 14:32:16 bostic 18 16
c add ERDLAB, EUNLAB
e
s 00006/00007/00142
d R 7.6 88/02/25 13:16:07 bostic 17 16
c add ERDLAB, EUNLAB
e
s 00001/00003/00148
d D 7.5 88/02/24 11:00:22 bostic 16 15
c default to dev error, doesn't tell you anything new
e
s 00023/00033/00128
d D 7.4 88/02/23 15:53:00 bostic 15 13
c change to dev(a,b,c,d) format
e
s 00024/00032/00129
d R 7.4 88/02/22 12:58:49 bostic 14 13
c change to dev(a,b,c,d) format
e
s 00011/00012/00150
d D 7.3 88/01/28 20:53:14 karels 13 12
c uvax changes; fix devsw index in confxx; header updates
e
s 00059/00006/00103
d D 7.2 87/02/21 11:41:39 karels 12 11
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00108
d D 7.1 86/06/05 01:44:30 mckusick 11 10
c 4.3BSD release version
e
s 00007/00001/00102
d D 6.2 85/06/08 13:10:51 mckusick 10 9
c Add copyright
e
s 00000/00000/00103
d D 6.1 83/07/29 07:47:30 sam 9 8
c 4.2 distribution
e
s 00010/00000/00093
d D 4.8 82/12/30 15:32:42 sam 8 7
c add ioctl's and errno
e
s 00001/00001/00092
d D 4.7 82/12/17 17:01:12 sam 7 6
c pte.h is now in ../machine/
e
s 00004/00002/00089
d D 4.6 82/11/13 23:15:18 sam 6 5
c move includes for 4.1c directory layout
e
s 00001/00000/00090
d D 4.5 82/07/15 21:31:45 root 5 4
c new boot scheme
e
s 00001/00001/00089
d D 4.4 81/07/25 21:44:38 wnj 4 3
c make ea bit handling consistent with actual rk driver
e
s 00020/00006/00070
d D 4.3 81/03/22 20:52:10 wnj 3 2
c fixes
e
s 00045/00073/00031
d D 4.2 81/03/15 20:46:41 wnj 2 1
c 
e
s 00104/00000/00000
d D 4.1 80/12/17 12:21:16 wnj 1 0
c date and time created 80/12/17 12:21:16 by wnj
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
D 10
/*	%M%	%I%	%E%	*/
E 10
I 10
/*
D 11
 * Copyright (c) 1982 Regents of the University of California.
E 11
I 11
D 19
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 19
I 19
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 19
E 11
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 10
E 2

/*
D 2
 * RK disk driver, standalone version
E 2
I 2
 * RK611/RK07
E 2
 */
I 7
D 13
#include "../machine/pte.h"
E 13
I 13
#include "param.h"
#include "inode.h"
#include "fs.h"
#include "disklabel.h"
E 13
E 7

D 13
#include "../h/param.h"
I 2
D 6
#include "../h/rkreg.h"
E 6
E 2
#include "../h/inode.h"
D 7
#include "../h/pte.h"
E 7
D 2
#include "../h/uba.h"
E 2
I 2
D 6
#include "../h/ubareg.h"
E 6
I 5
#include "../h/fs.h"
I 12
#include "../h/disklabel.h"
E 13
I 13
#include "../vax/pte.h"
E 13
E 12
I 6

#include "../vaxuba/ubareg.h"
#include "../vaxuba/rkreg.h"

E 6
E 5
E 2
#include "saio.h"
I 2
#include "savax.h"
E 2

I 12
D 15
#define	SECTSIZ 	512	/* sector size in bytes */
E 15
I 15
#define	SECTSIZ		512		/* sector size in bytes */
E 15

E 12
D 2
#define	RKADDR	((struct rk_regs *)(PHYSUMEM - 0160000 + 0177440))
#define FORMAT_22 0
#define	RESET	0102000
#define	WCOM	022
#define	RCOM	020
#define RK07	02000
#define	GO	01
#define RELEASE	010
#define	CTLRDY	0200
#define	PACKAK	000003	/* Pack Acknowledge */
E 2
I 2
D 15
u_short	rkstd[] = { 0777440 };
D 12
short	rk_off[] = { 0, 241, 0, -1, -1, -1, 393, -1 };
E 12
I 12
struct	disklabel rklabel[MAXNUBA*8];
E 15
I 15
#define	MAXCTLR		1		/* all addresses must be specified */
I 19
#define	MAXUNIT		8
E 19
u_short	rkstd[MAXCTLR] = { 0777440 };
D 19
struct	disklabel rklabel[MAXNUBA][MAXCTLR][8];
E 19
I 19
struct	disklabel rklabel[MAXNUBA][MAXCTLR][MAXUNIT];
E 19
E 15
char	lbuf[SECTSIZ];
E 12
E 2

D 2
struct	rk_regs
{
	short	rkcs1;
	short	rkwc;
	u_short	rkba;
	short	rkda;
	short	rkcs2;
	short	rkds;
	short	rker;
	short	rkasof;
	short	rkdc;
	short	rknull;
	short	rkdb;
	short	rkmr1;
	short	rkecps;
	short	rkecpt;
	short	rkmr2;
	short	rkmr3;
};

struct	devsize {
	daddr_t	cyloff;
} rk_sizes[] = {
	0, 146, 246, -1, -1, -1, -1, -1,
};

E 2
rkopen(io)
D 2
register struct iob *io;
E 2
I 2
	register struct iob *io;
E 2
{
I 3
D 15
	register struct rkdevice *rkaddr = (struct rkdevice *)ubamem(io->i_unit, rkstd[0]);
I 12
	register struct disklabel *lp = &rklabel[io->i_unit];
E 15
I 15
	register struct rkdevice *rkaddr;
	register struct disklabel *lp;
E 15
	struct iob tio;
E 12
E 3

I 19
	if ((u_int)io->i_adapt >= nuba)
		return (EADAPT);
E 19
I 15
	if ((u_int)io->i_ctlr >= MAXCTLR)
		return (ECTLR);
I 19
	if ((u_int)io->i_unit >= MAXUNIT)
		return (EUNIT);
E 19
	rkaddr = (struct rkdevice *)ubamem(io->i_adapt, rkstd[io->i_ctlr]);
E 15
D 2
	if (rk_sizes[io->i_boff].cyloff == -1 ||
E 2
I 2
D 12
	if (rk_off[io->i_boff] == -1 ||
E 2
	    io->i_boff < 0 || io->i_boff > 7)
		_stop("rk bad unit");
D 2
	io->i_boff = rk_sizes[io->i_boff].cyloff * 66;
E 2
I 2
	io->i_boff = rk_off[io->i_boff] * NRKSECT*NRKTRK;
E 12
I 12
D 16
	if (badaddr((char *)rkaddr, sizeof(short))) {
D 15
		printf("nonexistent device");
E 15
I 15
		printf("rk: nonexistent device\n");
E 16
I 16
	if (badaddr((char *)rkaddr, sizeof(short)))
E 16
E 15
		return (ENXIO);
D 16
	}
E 16
E 12
I 3
	rkaddr->rkcs2 = RKCS2_SCLR;
	rkwait(rkaddr);
I 12
	/*
	 * Read in the pack label.
	 */
I 15
	lp = &rklabel[io->i_adapt][io->i_ctlr][io->i_unit];
E 15
	lp->d_nsectors = NRKSECT;
	lp->d_secpercyl = NRKTRK*NRKSECT;
	tio = *io;
	tio.i_bn = LABELSECTOR;
	tio.i_ma = lbuf;
	tio.i_cc = SECTSIZ;
	tio.i_flgs |= F_RDDATA;
D 18
	if (rkstrategy(&tio, READ) != SECTSIZ) {
D 15
		printf("can't read disk label");
E 15
I 15
		printf("rk: can't read disk label\n");
E 15
		return (EIO);
	}
E 18
I 18
	if (rkstrategy(&tio, READ) != SECTSIZ)
		return (ERDLAB);
E 18
	*lp = *(struct disklabel *)(lbuf + LABELOFFSET);
D 18
	if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
D 15
		printf("hk%d: unlabeled\n", io->i_unit);
E 15
I 15
		printf("rk%d: unlabeled\n", io->i_unit);
E 18
I 18
	if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC)
E 18
E 15
#ifdef COMPAT_42
I 18
	{
		printf("rk%d: unlabeled\n", io->i_unit);
E 18
		rkmaptype(io, lp);
I 18
	}
E 18
#else
D 18
		return (ENXIO);
E 18
I 18
		return (EUNLAB);
E 18
#endif
D 18
	}
E 18
D 15
	if ((unsigned)io->i_boff >= lp->d_npartitions ||
	    (io->i_boff = lp->d_partitions[io->i_boff].p_offset) == -1) {
		printf("rk: bad partition");
		return (EUNIT);
	}
E 15
I 15
	if ((u_int)io->i_part >= lp->d_npartitions ||
	    (io->i_boff = lp->d_partitions[io->i_part].p_offset) == -1)
		return (EPART);
E 15
	return (0);
E 12
E 3
E 2
}

I 12
#ifdef COMPAT_42
u_long	rk_off[] = { 0, 241, 0, -1, -1, -1, 393, -1 };

rkmaptype(io, lp)
D 13
	register struct iob *io;
E 13
I 13
	struct iob *io;
E 13
	register struct disklabel *lp;
{
	register struct partition *pp;
D 15
	register i;
E 15
	register u_long *off = rk_off;
I 15
	register int i;
E 15

	lp->d_npartitions = 8;
	pp = lp->d_partitions;
	for (i = 0; i < 8; i++, pp++)
		pp->p_offset = *off++;
}
#endif

E 12
rkstrategy(io, func)
D 2
register struct iob *io;
E 2
I 2
	register struct iob *io;
E 2
{
D 2
	register short com;
E 2
I 2
D 15
	register struct rkdevice *rkaddr = (struct rkdevice *)ubamem(io->i_unit, rkstd[0]);
	int com;
E 15
I 15
	register struct rkdevice *rkaddr;
E 15
E 2
D 13
	daddr_t bn;
	short dn, cn, sn, tn;
E 13
I 13
	register daddr_t bn;
I 15
	int com, ubinfo, errcnt = 0;
E 15
	short cn, sn, tn;
E 13
D 3
	int ubinfo;
E 3
I 3
D 15
	int ubinfo, errcnt = 0;
E 15
E 3

I 15
	rkaddr = (struct rkdevice *)ubamem(io->i_adapt, rkstd[io->i_ctlr]);
E 15
I 3
retry:
E 3
	ubinfo = ubasetup(io, 1);
	bn = io->i_bn;
D 12
	dn = io->i_unit;
E 12
I 12
D 13
	dn = UNITTODRIVE(io->i_unit);
E 12
D 2
	cn = bn/66;
	sn = bn%22;
	tn = (bn / 22) % 3;

	RKADDR->rkcs2 = dn;
	RKADDR->rkcs1 = PACKAK | RK07;
	while ((com = RKADDR->rkcs1) & 01)
E 2
I 2
	cn = bn/(NRKSECT*NRKTRK);
	sn = bn%NRKSECT;
E 13
I 13
	cn = bn / (NRKSECT*NRKTRK);
	sn = bn % NRKSECT;
E 13
	tn = (bn / NRKSECT) % NRKTRK;
D 13
	rkaddr->rkcs2 = dn;
E 13
I 13
D 15
	rkaddr->rkcs2 = UNITTODRIVE(io->i_unit);
E 15
I 15
	rkaddr->rkcs2 = io->i_unit;
E 15
E 13
	rkaddr->rkcs1 = RK_CDT|RK_PACK|RK_GO;
	rkwait(rkaddr);
I 3
	rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
	rkwait(rkaddr);
E 3
	rkaddr->rkda = sn | (tn << 8);
	rkaddr->rkcyl = cn;
	rkaddr->rkba = ubinfo;
	rkaddr->rkwc = -(io->i_cc >> 1);
D 4
	com = RK_CDT|((ubinfo>>16)&0x30)|RK_GO;
E 4
I 4
	com = RK_CDT|((ubinfo>>8)&0x300)|RK_GO;
E 4
	if (func == READ)
		com |= RK_READ;
	else
		com |= RK_WRITE;
	rkaddr->rkcs1 = com;
	rkwait(rkaddr);
D 3
	while ((rkaddr->rkds & RK_SVAL) == 0)
E 3
I 3
	while ((rkaddr->rkds & RKDS_SVAL) == 0)
E 3
E 2
		;
D 2
	RKADDR->rkda = sn | (tn << 8);
	RKADDR->rkdc = cn;
	RKADDR->rkba = ubinfo;
	RKADDR->rkwc = -(io->i_cc >> 1);
	com = ((ubinfo & 0x30000) >> 8) | RK07 | GO | (FORMAT_22 << 12);
	if(func == READ)
		com |= RCOM; else
		com |= WCOM;
	RKADDR->rkcs1 = com;
	while (((com = RKADDR->rkcs1) & CTLRDY) == 0)
		;
	while(RKADDR->rkds >= 0)
		;
	ubafree(ubinfo);
	if (RKADDR->rkcs1 < 0) {		/* error bit */
		printf("RK07 error: unit %d, cyl %d, trk %d, sect %d, ",
			io->i_unit, cn, tn, sn);
		printf("cs1 %X, cs2 %X, err %X\n",
			RKADDR->rkcs1, RKADDR->rkcs2, RKADDR->rker);
		RKADDR->rkcs1 = RESET|GO;
		while(((com = RKADDR->rkcs1)&CTLRDY) == 0)
			;
E 2
I 2
	ubafree(io, ubinfo);
	if (rkaddr->rkcs1 & RK_CERR) {
D 3
		printf("rk error: cyl %d trk %d sec %d cs1 %o cs2 %o err %o\n",
		    cn, tn, sn, rkaddr->rkcs1, rkaddr->rkcs2, rkaddr->rker);
		rkaddr->rkcs1 = RK_DCLR|RK_GO;
E 3
I 3
		printf("rk error: (cyl,trk,sec)=(%d,%d,%d) cs2=%b er=%b\n",
		    cn, tn, sn, rkaddr->rkcs2, RKCS2_BITS,
		    rkaddr->rker, RKER_BITS);
		rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
E 3
		rkwait(rkaddr);
E 2
D 3
		return (-1);
E 3
I 3
D 15
		if (errcnt == 10) {
E 15
I 15
		if (errcnt++ == 10) {
E 15
			printf("rk: unrecovered error\n");
			return (-1);
		}
D 15
		errcnt++;
E 15
		goto retry;
E 3
	}
I 3
	if (errcnt)
		printf("rk: recovered by retry\n");
E 3
	return (io->i_cc);
I 2
}

rkwait(rkaddr)
	register struct rkdevice *rkaddr;
{
D 15

	while ((rkaddr->rkcs1 & RK_CRDY) == 0)
		;
E 2
}
I 8

/*ARGSUSED*/
rkioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{

	return (ECMD);
E 15
I 15
	while ((rkaddr->rkcs1 & RK_CRDY) == 0);
E 15
}
E 8
E 1
