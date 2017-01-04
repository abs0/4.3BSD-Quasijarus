h54013
s 00007/00007/00564
d D 7.8 88/09/17 16:01:36 bostic 29 28
c ubastd -> upstd
e
s 00049/00037/00522
d D 7.7 88/07/09 14:38:49 karels 28 27
c squish for SMALL
e
s 00010/00013/00549
d D 7.6 88/05/27 15:52:47 karels 27 25
c unbreak compat code, allow formatter to open unformatted disk
e
s 00010/00013/00549
d R 7.6 88/05/27 15:50:14 karels 26 25
c unbreak compat code, allow formatter to open unformatted disk
e
s 00088/00078/00474
d D 7.5 88/03/04 14:11:48 bostic 25 24
c add disklabels
e
s 00051/00039/00501
d D 7.4 88/02/22 13:00:32 bostic 24 23
c change to dev(a,b,c,d) format
e
s 00014/00005/00526
d D 7.3 88/01/28 20:53:32 karels 23 22
c uvax changes; fix devsw index in confxx; header updates
e
s 00025/00009/00506
d D 7.2 87/09/16 13:05:32 karels 22 21
c SMALL ifdefs
e
s 00001/00001/00514
d D 7.1 86/06/05 01:47:02 mckusick 21 20
c 4.3BSD release version
e
s 00121/00099/00394
d D 6.5 85/11/08 19:16:23 karels 20 19
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00007/00001/00486
d D 6.4 85/06/08 13:13:38 mckusick 19 18
c Add copyright
e
s 00001/00000/00486
d D 6.3 84/02/06 13:00:36 karels 18 17
c allow second open of same device (initialize those variables!)
e
s 00046/00042/00440
d D 6.2 83/09/23 16:40:56 karels 17 16
c mods for ghg's burnin
e
s 00000/00000/00482
d D 6.1 83/07/29 07:47:59 sam 16 15
c 4.2 distribution
e
s 00025/00033/00457
d D 4.12 83/03/02 17:52:52 sam 15 14
c treat hard ECC errors as hard, no matter what; check recalculated 
c wc on restart of ECC correction at proper place
e
s 00001/00001/00489
d D 4.11 83/03/02 16:03:24 sam 14 13
c silence printf except on retries
e
s 00049/00042/00441
d D 4.10 83/03/01 23:26:55 sam 13 12
c add debugging flags so it'll always be there
e
s 00039/00020/00444
d D 4.9 83/02/27 18:37:27 sam 12 11
c fix ecc restart
e
s 00043/00071/00421
d D 4.8 83/02/18 05:25:38 sam 11 10
c pull out common type mapping code for up's
e
s 00036/00020/00456
d D 4.7 83/02/17 13:15:29 sam 10 8
c fix up 9300/9766 stuff
e
s 00034/00017/00459
d R 4.7 83/02/17 11:51:07 sam 9 8
c handle drive mapping chores
e
s 00069/00075/00407
d D 4.6 83/02/16 21:57:58 sam 8 7
c untangle some code
e
s 00021/00031/00461
d D 4.5 83/01/31 16:38:12 helge 7 5
c more changes re: hp.new.c
e
s 00024/00034/00458
d R 4.5 83/01/29 15:08:12 helge 6 5
c more changes re. hp.new.c
e
s 00006/00032/00486
d D 4.4 83/01/18 14:26:46 helge 5 4
c removed the local copy of isbad
e
s 00134/00098/00384
d D 4.3 83/01/17 10:47:56 helge 4 2
c more ioctl's and other changes, need testing!!!!
e
s 00135/00089/00393
d R 4.3 83/01/16 14:42:40 helge 3 2
c lots of changes, ioctls etc, need more testing
e
s 00120/00088/00362
d D 4.2 82/12/30 15:31:07 sam 2 1
c add ioctl's + errno; fix chk to work with new stuff
e
s 00450/00000/00000
d D 4.1 82/12/26 18:53:17 sam 1 0
c date and time created 82/12/26 18:53:17 by sam
e
u
U
t
T
I 1
D 19
/*	%M%	%I%	%E%	*/
E 19
I 19
/*
D 21
 * Copyright (c) 1982 Regents of the University of California.
E 21
I 21
D 22
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 22
I 22
D 28
 * Copyright (c) 1982 Regents of the University of California.
E 28
I 28
 * Copyright (c) 1982, 1988 Regents of the University of California.
E 28
E 22
E 21
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 19
I 12
D 13
#define	UPECCDEBUG
E 13
E 12

I 2
/*
D 25
 * UNIBUS peripheral standalone driver
 * with ECC correction and bad block forwarding.
 * Also supports header operation and write
 * check for data and/or header.
E 25
I 25
 * UNIBUS peripheral standalone driver with ECC correction and bad
 * block forwarding.  Also supports header operation and write check
 * for data and/or header.
E 25
 */
I 4
D 13

E 13
E 4
E 2
D 22
#include "../h/param.h" 
#include "../h/inode.h"
#include "../h/fs.h"
#include "../h/dkbad.h"
#include "../h/vmmac.h"
E 22
I 22
#include "param.h" 
#include "inode.h"
#include "fs.h"
#include "dkbad.h"
D 25
#include "vmmac.h"
E 25
I 25
#include "disklabel.h"
E 25
E 22

D 22
#include "../vax/pte.h"
#include "../vaxuba/upreg.h"
#include "../vaxuba/ubareg.h"
E 22
I 22
D 23
#include "vax/pte.h"
#include "vaxuba/upreg.h"
#include "vaxuba/ubareg.h"
E 23
I 23
#include "../vax/pte.h"
E 23
E 22

I 23
#include "../vaxuba/upreg.h"
#include "../vaxuba/ubareg.h"

E 23
D 2
#include "nsaio.h"
E 2
I 2
#include "saio.h"
E 2
#include "savax.h"

I 20
#define RETRIES		27

E 20
I 4
#define MAXBADDESC	126	/* max number of bad sectors recorded */
#define SECTSIZ		512	/* sector size in bytes */
#define HDRSIZ		4	/* number of bytes in sector header */
I 13

E 13
D 10
#define MAXECC		5	/* max number of bad bits accepted in
				 * a soft ecc error when F_ECCLM is set */
#define	NUPTYPES	3
E 10
I 10
D 20
#define MAXECC		5	/* max # bad bits allowed on ecc w/ F_ECCLM */
E 10

E 20
E 4
D 2
#define updevctl(io, func)  (up_ctl[io->i_unit] = func)

struct  dkbad upbad[MAXNUBA*8];		/* bad block pointers */
E 2
D 24
u_short	ubastd[] = { 0776700 };
E 24
I 24
D 25
#define	MAXPART		8
E 25
I 25
#define	MAXUNIT		8
E 25
#define	MAXCTLR		1	/* all addresses must be specified */
D 29
u_short	ubastd[MAXCTLR] = { 0776700 };
I 25
struct	disklabel uplabel[MAXNUBA][MAXCTLR][MAXUNIT];
char	lbuf[SECTSIZ];
E 29
I 29
static u_short	upstd[MAXCTLR] = { 0776700 };
static struct	disklabel uplabel[MAXNUBA][MAXCTLR][MAXUNIT];
static char	lbuf[SECTSIZ];
E 29
E 25
E 24
I 2

E 2
D 13
char	up_gottype[MAXNUBA*8] = { 0 };
char	up_type[MAXNUBA*8] = { 0 };
E 13
I 13
D 20
char	up_gottype[MAXNUBA*8];
char	up_type[MAXNUBA*8];
E 20
E 13
D 2
char	up_ctl[MAXNUBA*8]  = { 0 };
E 2
D 10
short	up_off[] = { 0, 27, 68, -1, -1, -1, -1, 82 };
E 10
I 10
D 11
short	up9300_off[] = { 0, 27, 68, -1, -1, -1, -1, 82 };
short	up9766_off[] = { 0, 27, 68, -1, -1, -1, -1, 82 };
E 10
short	fj_off[] = { 0, 50, 0, -1, -1, -1, -1, 155 };
/* this is called upam instead of am because hp.c has a similar array */
short	upam_off[] = { 0, 32, 0, 668, 723, 778, 668, 98 };
E 11
I 11
extern	struct st upst[];
E 11
I 2

I 22
#ifndef SMALL
E 22
I 13
D 24
struct  dkbad upbad[MAXNUBA*8];		/* bad sector table */
E 24
I 24
D 25
struct  dkbad upbad[MAXNUBA][MAXCTLR][8];	/* bad sector table */
E 25
I 25
struct  dkbad upbad[MAXNUBA][MAXCTLR][MAXUNIT];	/* bad sector table */
E 25
E 24
I 22
#endif
E 22
D 25
int 	sectsiz;			/* real sector size */
E 25
I 25
int 	sectsiz;				/* real sector size */
E 25
D 20
int	updebug[MAXNUBA*8];
#define	UPF_BSEDEBUG	01	/* debugging bad sector forwarding */
#define	UPF_ECCDEBUG	02	/* debugging ecc correction */
E 20

I 20
struct	up_softc {
	char	gottype;
	char	type;
	char	debug;
#	define	UPF_BSEDEBUG	01	/* debugging bad sector forwarding */
#	define	UPF_ECCDEBUG	02	/* debugging ecc correction */
	int	retries;
	int	ecclim;
D 24
} up_softc[MAXNUBA * 8];
E 24
I 24
D 25
} up_softc[MAXNUBA][MAXCTLR][8];
E 25
I 25
} up_softc[MAXNUBA][MAXCTLR][MAXUNIT];
E 25
E 24

E 20
E 13
I 10
D 11
#define	NUPTYPES	4
E 10
D 4
#define	NUPTYPES	3

E 2
struct upst {
	short nsect;
	short ntrak;
	short nspc;
	short ncyl;
	short *off;
D 2
} upst[] = {
/*  sectors,   surfaces,sect/cyl,cylind,		*/
	32,	19,	32*19,	823,	up_off,
	32,	10,	32*10,	823,	fj_off,
	32,	16,	32*16,	1024,	upam_off,
E 2
I 2
} upst[NUPTYPES] = {
E 4
I 4
struct st upst[NUPTYPES] = {
E 4
D 10
	32,	19,	32*19,	823,	up_off,		/* 9300/equiv */
E 10
I 10
	32,	19,	32*19,	815,	up9300_off,	/* 9300 */
	32,	19,	32*19,	823,	up9766_off,	/* 9766 */
E 10
	32,	10,	32*10,	823,	fj_off,		/* Fuji 160 */
	32,	16,	32*16,	1024,	upam_off,	/* Capricorn */
E 2
};
I 2

E 11
E 2
u_char	up_offset[16] = {
	UPOF_P400, UPOF_M400, UPOF_P400, UPOF_M400,
	UPOF_P800, UPOF_M800, UPOF_P800, UPOF_M800, 
	UPOF_P1200, UPOF_M1200, UPOF_P1200, UPOF_M1200,
	0, 0, 0, 0
};

I 2
D 13
struct  dkbad upbad[MAXNUBA*8];		/* bad sector table */
I 4
int 	sectsiz;			/* real sector size */
E 4

E 13
E 2
upopen(io)
	register struct iob *io;
{
I 4
D 25
	register unit = io->i_unit;
E 25
E 4
D 2
	register struct updevice *upaddr =
	    (struct updevice *)ubamem(io->i_unit, ubastd[0]);
E 2
I 2
	register struct updevice *upaddr;
I 20
D 24
	register struct up_softc *sc = &up_softc[unit];
E 24
I 24
	register struct up_softc *sc;
E 24
E 20
E 2
D 4
	register struct upst *st;
E 4
I 4
D 10
	register struct st *st = &upst[up_type[unit]];
E 10
I 10
	register struct st *st;
I 28
	register struct disklabel *lp;
	struct disklabel *dlp;
E 28
I 25
	register int unit;
D 28
	struct disklabel *dlp, *lp;
I 27
	int error = 0;
E 28
I 28
	int error = 0, uba, ctlr;
E 28
E 27
E 25
E 10
E 4
D 2
	struct iob tio;
	int i = 0;
E 2

I 2
D 11
	if (io->i_boff < 0 || io->i_boff > 7 || st->off[io->i_boff] == -1)
E 11
I 11
D 24
	if (io->i_boff < 0 || io->i_boff > 7)
E 11
		_stop("up bad unit");
D 4
	upaddr = (struct updevice *)ubamem(io->i_unit, ubastd[0]);
E 4
I 4
	upaddr = (struct updevice *)ubamem(unit, ubastd[0]);
E 24
I 24
D 28
	if ((u_int)io->i_ctlr >= MAXCTLR)
E 28
I 28
	if ((u_int)(uba = io->i_adapt) >= nuba)
		return (EADAPT);
	if ((u_int)(ctlr = io->i_ctlr) >= MAXCTLR)
E 28
		return (ECTLR);
D 25
	if ((u_int)io->i_part >= MAXPART)
E 25
I 25
D 28
	if ((u_int)io->i_part >= MAXUNIT)
E 25
		return (EPART);
	upaddr = (struct updevice *)ubamem(io->i_adapt, ubastd[io->i_ctlr]);
E 28
I 25
	unit = io->i_unit;
E 25
E 24
I 17
D 28
	upaddr->upcs2 = unit % 8;
E 28
I 28
	if ((u_int)unit >= MAXUNIT)
		return (EUNIT);
D 29
	upaddr = (struct updevice *)ubamem(uba, ubastd[ctlr]);
E 29
I 29
	upaddr = (struct updevice *)ubamem(uba, upstd[ctlr]);
E 29
	upaddr->upcs2 = unit;
E 28
E 17
E 4
E 2
D 8
	while ((upaddr->upcs1 & UP_DVA) == 0) /* infinite wait */
E 8
I 8
D 24
	while ((upaddr->upcs1 & UP_DVA) == 0)
E 8
		;
E 24
I 24
	while ((upaddr->upcs1 & UP_DVA) == 0);
D 28
	sc = &up_softc[io->i_adapt][io->i_ctlr][unit];
I 25
	lp = &uplabel[io->i_adapt][io->i_ctlr][unit];
E 28
I 28
	sc = &up_softc[uba][ctlr][unit];
	lp = &uplabel[uba][ctlr][unit];
E 28
E 25
E 24
D 4
	st = &upst[up_type[io->i_unit]];
	if (up_gottype[io->i_unit] == 0) {
E 4
I 4
D 20
	if (up_gottype[unit] == 0) {
E 20
I 20
	if (sc->gottype == 0) {
E 20
E 4
I 2
		register int i;
		struct iob tio;

I 25
#ifndef SMALL
E 25
E 2
D 10
		upaddr->uphr = UPHR_MAXTRAK;
D 2
		if (upaddr->uphr == 9)
			up_type[io->i_unit] = 1;	/* fuji kludge */
		else if (upaddr->uphr == 15)
			up_type[io->i_unit] = 2;	/* capricorn kludge */
E 2
I 2
		for (st = upst; st < &upst[NUPTYPES]; st++)
			if (upaddr->uphr == st->ntrak - 1) {
D 4
				up_type[io->i_unit] = st - upst;
E 4
I 4
				up_type[unit] = st - upst;
E 4
				break;
			}
		if (st == &upst[NUPTYPES]) {
D 4
			printf("up%d: uphr=%x\n", upaddr->uphr);
E 4
I 4
			printf("up%d: uphr=%x\n", unit, upaddr->uphr);
E 10
I 10
D 20
		up_type[unit] = upmaptype(unit, upaddr);
		if (up_type[unit] < 0)
E 20
I 20
		sc->retries = RETRIES;
		sc->ecclim = 11;
		sc->debug = 0;
D 25
		sc->type = upmaptype(unit, upaddr);
D 24
		if (sc->type < 0)
E 20
E 10
E 4
			_stop("unknown drive type");
E 24
I 24
		if (sc->type < 0) {
			printf("unknown drive type\n");
			return (ENXIO);
E 25
I 25
#endif
		/* Read in the pack label. */
		lp->d_nsectors = 32;
		lp->d_secpercyl = 19*32;
		tio = *io;
		tio.i_bn = LABELSECTOR;
		tio.i_ma = lbuf;
		tio.i_cc = SECTSIZ;
		tio.i_flgs |= F_RDDATA;
		if (upstrategy(&tio, READ) != SECTSIZ)
D 27
			return (ERDLAB);
E 27
I 27
			error = ERDLAB;
E 27
		dlp = (struct disklabel *)(lbuf + LABELOFFSET);
D 27
		if (dlp->d_magic != DISKMAGIC || dlp->d_magic2 != DISKMAGIC)
E 27
I 27
		if (error == 0 && (dlp->d_magic != DISKMAGIC ||
		    dlp->d_magic2 != DISKMAGIC))
			error = EUNLAB;
		if (error == 0)
			*lp = *dlp;
		else
E 27
#ifdef COMPAT_42
D 27
		{
			printf("up%d: unlabeled\n", unit);
			if (!upmaptype(unit, upaddr, dlp)) {
				printf("up: unknown drive type\n");
				return (ENXIO);
			}
E 25
		}
E 24
D 10
		}
E 2
		upaddr->upcs2 = UPCS2_CLR;
#ifdef DEBUG
D 4
		printf("Unittype=%d\n",up_type[io->i_unit]);
E 4
I 4
		printf("Unittype=%d\n",up_type[unit]);
E 4
#endif
D 2
		st = &upst[up_type[io->i_unit]];
E 2

E 10
I 10
D 20
		st = &upst[up_type[unit]];
E 20
I 20
D 25
		st = &upst[sc->type];
E 20
I 11
D 24
		if (st->off[io->i_boff] == -1)
			_stop("up bad unit");
E 24
I 24
		if (st->off[io->i_part] == -1)
			return (EPART);
E 25
I 25
#else
			return (EUNLAB);
E 27
I 27
		    if (upmaptype(unit, upaddr, lp) == 0)
E 27
#endif
D 27
		else
			*lp = *dlp;
E 27
I 27
			return (error);
E 27

E 25
E 24
I 22
#ifndef SMALL
E 22
E 11
E 10
D 2
	/* read in bad block ptrs */
		tio = *io;		/* copy the contents of the io structure
					 * to tio for use during the bb pointer
					 * read operation */
		tio.i_bn = (st->nspc * st->ncyl - st->nsect);
E 2
I 2
D 25
		/*
D 13
		 * Read in the bad sector table:
		 *	copy the contents of the io structure
		 *	to tio for use during the bb pointer
		 *	read operation.
E 13
I 13
		 * Read in the bad sector table.
E 13
		 */
		tio = *io;
		tio.i_bn = st->nspc * st->ncyl - st->nsect;
E 2
D 24
		tio.i_ma = (char *)&upbad[tio.i_unit];
E 24
I 24
		tio.i_ma = (char *)&upbad[tio.i_adapt][tio.i_ctlr][tio.i_unit];
E 24
D 2
		tio.i_cc = sizeof(upbad);
		for (i=0; i<5; i++) {
			if (upstrategy(&tio, READ) == sizeof(upbad)) break;
E 2
I 2
D 7
		tio.i_cc = sizeof (upbad);
E 7
I 7
		tio.i_cc = sizeof (struct dkbad);
E 25
I 25
		/* Read in the bad sector table. */
		tio.i_bn = lp->d_secpercyl * lp->d_ncylinders - lp->d_nsectors;
D 28
		tio.i_ma = (char *)&upbad[io->i_adapt][io->i_ctlr][io->i_unit];
E 28
I 28
		tio.i_ma = (char *)&upbad[uba][ctlr][unit];
E 28
		tio.i_cc = sizeof(struct dkbad);
E 25
E 7
		tio.i_flgs |= F_RDDATA;
		for (i = 0; i < 5; i++) {
D 7
			if (upstrategy(&tio, READ) == sizeof (upbad))
E 7
I 7
D 25
			if (upstrategy(&tio, READ) == sizeof (struct dkbad))
E 25
I 25
			if (upstrategy(&tio, READ) == sizeof(struct dkbad))
E 25
E 7
				break;
E 2
			tio.i_bn += 2;
		}
		if (i == 5) {
D 2
			printf("Unable to read bad block ptrs\n");
			for (i=0; i<126; i++) {
E 2
I 2
D 25
			printf("Unable to read bad sector table\n");
E 25
I 25
			printf("up: can't read bad sector table\n");
E 25
D 4
			for (i = 0; i < 126; i++) {
E 2
				upbad[io->i_unit].bt_bad[i].bt_cyl = -1;
				upbad[io->i_unit].bt_bad[i].bt_trksec = -1;
E 4
I 4
			for (i = 0; i < MAXBADDESC; i++) {
D 24
				upbad[unit].bt_bad[i].bt_cyl = -1;
				upbad[unit].bt_bad[i].bt_trksec = -1;
E 24
I 24
D 28
				upbad[tio.i_adapt][tio.i_ctlr][unit].bt_bad[i].bt_cyl = -1;
				upbad[tio.i_adapt][tio.i_ctlr][unit].bt_bad[i].bt_trksec = -1;
E 28
I 28
				upbad[uba][ctlr][unit].bt_bad[i].bt_cyl = -1;
				upbad[uba][ctlr][unit].bt_bad[i].bt_trksec = -1;
E 28
E 24
E 4
			}
D 25
		}	
E 25
I 25
		}
E 25
I 22
#endif
E 22
D 4
		up_gottype[io->i_unit] = 1;
E 4
I 4
D 20
		up_gottype[unit] = 1;
E 20
I 20
		sc->gottype = 1;
E 20
E 4
	}
I 18
D 20
	st = &upst[up_type[unit]];
E 20
I 20
D 25
	st = &upst[sc->type];
E 20
E 18
D 2
	if (io->i_boff < 0 || io->i_boff > 7 || st->off[io->i_boff] == -1)
		_stop("up bad unit");
E 2
D 24
	io->i_boff = st->off[io->i_boff] * st->nspc;
E 24
I 24
	io->i_boff = st->off[io->i_part] * st->nspc;
E 25
I 25
	if (io->i_part >= lp->d_npartitions ||
	    lp->d_partitions[io->i_part].p_size == 0)
D 28
			return (EPART);
E 28
I 28
		return (EPART);
E 28
	io->i_boff = lp->d_partitions[io->i_part].p_offset;
E 25
E 24
D 2
	updevctl(io, NORMAL);
E 2
I 2
	io->i_flgs &= ~F_TYPEMASK;
I 23
	return (0);
E 23
I 10
}

D 11
upmaptype(unit, upaddr)
	int unit;
	register struct updevice *upaddr;
{
	register struct st *st;
	int type = -1;

	upaddr->upcs1 = 0;
	upaddr->upcs2 = unit % 8;
	upaddr->uphr = UPHR_MAXTRAK;
	for (st = upst; st < &upst[NUPTYPES]; st++)
		if (upaddr->uphr == st->ntrak - 1) {
			type = st - upst;
			break;
		}
	if (type < 0)
		printf("up%d: uphr=%x\n", unit, upaddr->uphr);
	if (type == 0) {
		upaddr->uphr = UPHR_MAXCYL;
		if (upaddr->uphr == 822)	/* CDC 9766 */
			type++;
	}
	upaddr->upcs2 = UPCS2_CLR;
	return (type);
E 10
E 2
}

E 11
upstrategy(io, func)
	register struct iob *io;
I 25
	int func;
E 25
{
D 4
	int unit, cn, tn, sn;
E 4
I 4
D 12
	int cn, tn, sn;
E 12
I 12
	int cn, tn, sn, o;
E 12
	register unit = io->i_unit;
E 4
D 23
	daddr_t bn;
E 23
I 23
	register daddr_t bn;
E 23
	int recal, info, waitdry;
D 24
	register struct updevice *upaddr =
D 4
	    (struct updevice *)ubamem(io->i_unit, ubastd[0]);
	register struct upst *st = &upst[up_type[io->i_unit]];
E 4
I 4
	    (struct updevice *)ubamem(unit, ubastd[0]);
D 20
	register struct st *st = &upst[up_type[unit]];
I 12
	int doprintf = 0;
E 20
I 20
	struct up_softc *sc = &up_softc[unit];
	register struct st *st = &upst[sc->type];
E 24
I 24
	register struct updevice *upaddr;
I 25
	register struct disklabel *lp;
E 25
	struct up_softc *sc;
D 25
	register struct st *st;
E 25
E 24
D 23
	int doprintf = 0, error, rv = io->i_cc;
E 23
I 23
	int error, rv = io->i_cc;
#ifndef SMALL
	int doprintf = 0;
#endif
E 23
E 20
E 12
E 4

I 24
D 29
	upaddr = (struct updevice *)ubamem(io->i_adapt, ubastd[io->i_ctlr]);
E 29
I 29
	upaddr = (struct updevice *)ubamem(io->i_adapt, upstd[io->i_ctlr]);
E 29
	sc = &up_softc[io->i_adapt][io->i_ctlr][unit];
D 25
	st = &upst[sc->type];
E 25
I 25
	lp = &uplabel[io->i_adapt][io->i_ctlr][unit];
E 25
E 24
D 2
	if (func == READ) 
		io->i_flgs |= IO_READ;
	else
		io->i_flgs |= IO_WRITE;
E 2
I 2
D 4
	if (func != READ && func != WRITE) {
		io->i_error = ECMD;
		return (-1);
	}
E 2
	unit = io->i_unit;
E 4
I 4
	sectsiz = SECTSIZ;
I 28
#ifndef SMALL
E 28
D 8
	if ((io->i_flgs & (F_HDR|F_CHECK)) != 0)
E 8
I 8
	if (io->i_flgs & (F_HDR|F_HCHECK))
E 8
		sectsiz += HDRSIZ;
E 4
D 8
	io->i_errcnt = 0;
D 4
	recal = 3;
E 4
I 4
D 7
	recal = 1;
E 7
I 7
	recal = 0;
E 8
E 7
E 4
D 13
	upaddr->upcs2 = unit;
E 13
I 13
D 28
	upaddr->upcs2 = unit % 8;
E 28
I 28
#endif
	upaddr->upcs2 = unit;
E 28
E 13
	if ((upaddr->upds & UPDS_VV) == 0) {
		upaddr->upcs1 = UP_DCLR|UP_GO;
		upaddr->upcs1 = UP_PRESET|UP_GO;
		upaddr->upof = UPOF_FMT22;
	}
D 8
	if ((upaddr->upds & UPDS_DREADY) != UPDS_DREADY)
E 8
I 8
D 20
	if ((upaddr->upds & UPDS_DREADY) == 0)
E 8
		_stop("up not ready");
E 20
I 20
	if ((upaddr->upds & UPDS_DREADY) == 0) {
D 28
		printf("up%d not ready", unit);
E 28
I 28
		printf("up%d not ready\n", unit);
E 28
		return (-1);
	}
E 20
	info = ubasetup(io, 1);
	upaddr->upwc = -io->i_cc / sizeof (short);
D 12
	upaddr->upba = info;
E 12
I 8
	recal = 0;
	io->i_errcnt = 0;

E 8
D 7
readmore: 
E 7
I 7
restart: 
I 20
D 28
	error = 0;
E 28
E 20
E 7
D 4
	bn = io->i_bn + btop(io->i_cc + upaddr->upwc*sizeof(short));
E 4
I 4
D 8
	bn = io->i_bn + (io->i_cc + upaddr->upwc*sizeof(short))/sectsiz;
E 8
I 8
D 12
	bn = io->i_bn + (io->i_cc + upaddr->upwc * sizeof(short)) / sectsiz;
E 12
I 12
D 15
#define	rounddown(x, y)	(((x) / (y)) * (y))
	upaddr->upwc = rounddown(upaddr->upwc, sectsiz / sizeof (short));
E 15
	o = io->i_cc + (upaddr->upwc * sizeof (short));
	upaddr->upba = info + o;
	bn = io->i_bn + o / sectsiz;
I 23
#ifndef SMALL
I 28
	error = 0;
E 28
E 23
D 13
	if (doprintf)
		printf("upwc %d o %d i_bn %d bn %d\n", upaddr->upwc,
			o, io->i_bn, bn);
E 13
I 13
D 14
	if (updebug[unit] & (UPF_ECCDEBUG|UPF_BSEDEBUG))
E 14
I 14
D 20
	if (doprintf && updebug[unit] & (UPF_ECCDEBUG|UPF_BSEDEBUG))
E 20
I 20
	if (doprintf && sc->debug & (UPF_ECCDEBUG|UPF_BSEDEBUG))
E 20
E 14
D 15
		printf("upwc=%d o=%d i_bn=%d bn=%d\n",
E 15
I 15
		printf("wc=%d o=%d i_bn=%d bn=%d\n",
E 15
			upaddr->upwc, o, io->i_bn, bn);
I 23
#endif
E 23
E 13
E 12
E 8
E 4
D 2
	while((upaddr->upds & UPDS_DRY) == 0) ;
E 2
I 2
D 28
	while((upaddr->upds & UPDS_DRY) == 0)
		;
E 28
I 28
	upwaitdry(upaddr);
E 28
E 2
D 4
	if (upstart(io, bn) != 0) 
E 4
I 4
D 25
	if (upstart(io, bn) != 0) {
E 25
I 25
	if (upstart(io, bn, lp) != 0) {
E 25
D 20
		ubafree(io, info);
E 4
		return (-1);
E 20
I 20
		rv = -1;
		goto done;
E 20
I 4
	}
E 4
D 28
	do {
		DELAY(25);
	} while ((upaddr->upcs1 & UP_RDY) == 0);
E 28
I 28
	upwaitrdy(upaddr);
E 28
D 8

D 4
	if (((upaddr->upds&UPDS_ERR) | (upaddr->upcs1&UP_TRE)) == 0 )
E 4
I 4
	if (((upaddr->upds&UPDS_ERR) | (upaddr->upcs1&UP_TRE)) == 0 ) {
E 8
I 8
	/*
	 * If transfer has completed, free UNIBUS
	 * resources and return transfer size.
	 */
D 17
	if ((upaddr->upds&UPDS_ERR) == 0 && (upaddr->upcs1&UP_TRE) == 0) {
E 8
		ubafree(io, info);
E 4
D 8
		return(io->i_cc);
E 8
I 8
		return (io->i_cc);
E 8
I 4
	}
E 17
I 17
	if ((upaddr->upds&UPDS_ERR) == 0 && (upaddr->upcs1&UP_TRE) == 0)
		goto done;
E 17
E 4
D 8

E 8
D 13
#ifdef LOGALLERRS
	printf("uper: (c,t,s)=(%d,%d,%d) cs2=%b er1=%b er2=%b wc=%x\n",
D 8
			upaddr->updc, upaddr->upda>>8, (upaddr->upda&0x1f-1),
		    	upaddr->upcs2, UPCS2_BITS, upaddr->uper1, 
			UPER1_BITS, upaddr->uper2, UPER2_BITS,-upaddr->upwc);
E 8
I 8
		upaddr->updc, upaddr->upda>>8, (upaddr->upda&0x1f-1),
	    	upaddr->upcs2, UPCS2_BITS, upaddr->uper1, 
		UPER1_BITS, upaddr->uper2, UPER2_BITS,-upaddr->upwc);
E 8
#endif
E 13
I 13
D 20
	if (updebug[unit] & (UPF_ECCDEBUG|UPF_BSEDEBUG)) {
		printf("up error: (cyl,trk,sec)=(%d,%d,%d) ",
D 15
		  upaddr->updc, upaddr->upda>>8, (upaddr->upda&0x1f-1));
		printf("cs2=%b er1=%b er2=%b wc=%x\n",
E 15
I 15
D 17
		  upaddr->updc, upaddr->upda>>8, (upaddr->upda&0x1f)-1);
E 17
I 17
		  upaddr->updc, upaddr->upda>>8, upaddr->upda&0xff);
E 20
I 20
	bn = io->i_bn +
		(io->i_cc + upaddr->upwc * sizeof (short)) / sectsiz;
	if (upaddr->uper1 & (UPER1_DCK|UPER1_ECH))
		bn--;
D 25
	cn = bn/st->nspc;
	sn = bn%st->nspc;
	tn = sn/st->nsect;
	sn = sn%st->nsect;
E 25
I 25
	cn = bn / lp->d_secpercyl;
	sn = bn % lp->d_secpercyl;
	tn = sn / lp->d_nsectors;
	sn = sn % lp->d_nsectors;
E 25
I 22
#ifndef SMALL
E 22
	if (sc->debug & (UPF_ECCDEBUG|UPF_BSEDEBUG)) {
		printf("up error: sn%d (cyl,trk,sec)=(%d,%d,%d) ",
		   bn, cn, tn, sn);
E 20
E 17
		printf("cs2=%b er1=%b er2=%b wc=%d\n",
E 15
	    	  upaddr->upcs2, UPCS2_BITS, upaddr->uper1, 
D 15
		  UPER1_BITS, upaddr->uper2, UPER2_BITS,-upaddr->upwc);
E 15
I 15
		  UPER1_BITS, upaddr->uper2, UPER2_BITS, upaddr->upwc);
E 15
	}
I 22
#endif
E 22
E 13
	waitdry = 0;
D 2
	while ((upaddr->upds & UPDS_DRY) == 0) {
		if (++waitdry > 512)
			break;
	}
E 2
I 2
D 4
	while ((upaddr->upds & UPDS_DRY) == 0 && ++waitdry < 512)
E 4
I 4
D 15
	while ((upaddr->upds & UPDS_DRY) == 0 && ++waitdry < sectsiz)
E 15
I 15
	while ((upaddr->upds&UPDS_DRY) == 0 && ++waitdry < sectsiz)
E 15
E 4
		DELAY(5);
I 22
#ifndef SMALL
E 22
I 8
	if (upaddr->uper1&UPER1_WLE) {
		/*
		 * Give up on write locked devices immediately.
		 */
		printf("up%d: write locked\n", unit);
D 20
		return (-1);
E 20
I 20
		rv = -1;
		goto done;
E 20
	}
E 8
E 2
D 20
	if (++io->i_errcnt > 27) {
E 20
I 20
	if (upaddr->uper2 & UPER2_BSE) {
		if ((io->i_flgs&F_NBSF) == 0 && upecc(io, BSE) == 0)
			goto success;
		error = EBSE;
		goto hard;
	}
	/*
	 * ECC error. If a soft error, correct it;
	 * if correction is too large, no more retries.
	 */
	if ((upaddr->uper1 & (UPER1_DCK|UPER1_ECH|UPER1_HCRC)) == UPER1_DCK) {
		if (upecc(io, ECC) == 0)
			goto success;
		error = EECC;
		goto hard;
	} 
	/*
D 25
	 * If the error is a header CRC,
	 * check if a replacement sector exists in
	 * the bad sector table.
E 25
I 25
	 * If the error is a header CRC, check if a replacement sector
	 * exists in the bad sector table.
E 25
	 */
	if ((upaddr->uper1&UPER1_HCRC) && (io->i_flgs&F_NBSF) == 0 &&
	     upecc(io, BSE) == 0)
		goto success;
I 22
#endif
E 22
	if (++io->i_errcnt > sc->retries) {
E 20
		/*
		 * After 28 retries (16 without offset, and
		 * 12 with offset positioning) give up.
I 12
D 20
		 * But first, if the error is a header CRC,
		 * check if a replacement sector exists in
		 * the bad sector table.
E 20
E 12
		 */
I 12
D 20
		if ((upaddr->uper1&UPER1_HCRC) && (io->i_flgs&F_NBSF) == 0 &&
		     upecc(io, BSE) == 0)
			goto success;
E 12
D 2
		io->i_error = IOERR_HER;
E 2
I 2
		io->i_error = EHER;
E 2
D 4
hard:
E 4
D 2
		if (upaddr->upcs2 & UPCS2_WCE) io->i_error=IOERR_WCK;
E 2
I 2
		if (upaddr->upcs2 & UPCS2_WCE)
			io->i_error = EWCK;
E 20
E 2
D 4
		bn = io->i_bn + btop(io->i_cc + upaddr->upwc*sizeof(short));
E 4
I 4
hard:
I 28
#ifndef SMALL
E 28
D 8
		bn = io->i_bn + (io->i_cc + upaddr->upwc*sizeof(short))/sectsiz;
E 8
I 8
D 20
		bn = io->i_bn +
			(io->i_cc + upaddr->upwc * sizeof (short)) / sectsiz;
E 8
E 4
		cn = bn/st->nspc;
		sn = bn%st->nspc;
		tn = sn/st->nsect;
		sn = sn%st->nsect;
D 8
		printf("up error: (cyl,trk,sec)=(%d,%d,%d) cs2=%b er1=%b er2=%b\n",
		    	cn, tn, sn,
		    	upaddr->upcs2, UPCS2_BITS, upaddr->uper1, 
			UPER1_BITS, upaddr->uper2, UPER2_BITS);
E 8
I 8
		printf(
		  "up error: (cyl,trk,sec)=(%d,%d,%d) cs2=%b er1=%b er2=%b\n",
		   cn, tn, sn,
E 20
I 20
		if (error == 0) {
			error = EHER;
			if (upaddr->upcs2 & UPCS2_WCE)
				error = EWCK;
		}
I 28
		io->i_error = error;
#endif
E 28
		printf("up error: sn%d (cyl,trk,sec)=(%d,%d,%d) ",
		   bn, cn, tn, sn);
		printf("cs2=%b er1=%b er2=%b\n",
E 20
		   upaddr->upcs2, UPCS2_BITS, upaddr->uper1, 
		   UPER1_BITS, upaddr->uper2, UPER2_BITS);
E 8
		upaddr->upcs1 = UP_TRE|UP_DCLR|UP_GO;
I 4
		io->i_errblk = bn;
I 17
		if (io->i_errcnt >= 16) {
			upaddr->upof = UPOF_FMT22;
			upaddr->upcs1 = UP_RTC|UP_GO;
D 28
			while ((upaddr->upds&UPDS_DRY) == 0)
				DELAY(25);
E 28
I 28
			upwaitdry(upaddr);
E 28
		}
E 17
E 4
D 8
		return (io->i_cc + upaddr->upwc*sizeof(short));
	} else 
		if (upaddr->uper1&UPER1_WLE) {
D 2
		/*
		 * Give up on write locked devices
		 * immediately.
		 */
		printf("up%d: write locked\n", unit);
		return(-1);
E 2
I 2
			/*
			 * Give up on write locked devices
			 * immediately.
			 */
			printf("up%d: write locked\n", unit);
			return(-1);
E 2
		}
#ifndef NOBADSECT
	else if (upaddr->uper2 & UPER2_BSE) {
D 4
		if (upecc( io, BSE)) 
E 4
I 4
		if (io->i_flgs & F_NBSF) {
			io->i_error = EBSE;
			goto hard;
		}
		if (upecc( io, BSE) == 0) 
E 8
I 8
D 20
		return (io->i_cc + upaddr->upwc * sizeof(short));
E 20
I 20
		rv = -1;
		goto done;
E 20
	}
D 20
	if (upaddr->uper2 & UPER2_BSE) {
D 11
		short wc = upaddr->upwc;
		if ((io->i_flgs&F_NBSF) == 0 && upecc(io, BSE) == 0) {
			if (wc != upaddr->upwc)
				printf("wc %x upwc %x\n", wc, upaddr->upwc);
E 11
I 11
		if ((io->i_flgs&F_NBSF) == 0 && upecc(io, BSE) == 0)
E 11
E 8
E 4
			goto success;
D 8
		else {
D 2
			io->i_error = IOERR_BSE;
E 2
I 2
			io->i_error = EBSE;
E 2
			goto hard;
E 8
D 11
		}
E 11
I 8
		io->i_error = EBSE;
		goto hard;
E 8
	}
E 20
D 8
#endif
	else {
E 8
I 8
	/*
D 15
	 * Retriable error.
	 * If a soft ecc, correct it 
	 * Otherwise fall through and retry the transfer
E 15
I 15
D 20
	 * ECC error. If a soft error, correct it;
	 * otherwise fall through and retry the transfer.
E 15
	 */
D 15
	if (upaddr->uper1 & UPER1_DCK) {
E 8
		/*
D 8
		 * Retriable error.
		 * If a soft ecc, correct it 
		 * Otherwise fall through and retry the transfer
E 8
I 8
		 * If a write check command is active, all
		 * ecc errors give UPER1_ECH.
E 8
		 */
D 4
		if ((upaddr->uper1&(UPER1_DCK|UPER1_ECH))==UPER1_DCK) {
D 2
			upecc( io, ECC);
E 2
I 2
			upecc(io, ECC);
E 2
			goto success;
D 2
		} else {
E 2
I 2
		} else
E 2
			io->i_active = 0; /* force retry */
E 4
I 4
D 8
		if ((upaddr->uper1 & UPER1_DCK) != 0) {
			/*
			 * If a write check command is active, all
			 * ecc errors give UPER1_ECH.
			 */
			if (((upaddr->uper1 & UPER1_ECH) == 0 )|| 
			    ((upaddr->upcs2 & UPCS2_WCE) != 0 )) {
				if (upecc(io, ECC) == 0)
					goto success;
				else {
					io->i_error = EECC;
					goto hard;
				}
			}
		} 
D 7
		io->i_active = 0; /* else force retry */
E 7
E 4
D 2
		}
E 2
	}
E 8
I 8
		if ((upaddr->uper1 & UPER1_ECH) == 0 || 
		    (upaddr->upcs2 & UPCS2_WCE)) {
			if (upecc(io, ECC) == 0)
				goto success;
			io->i_error = EECC;
			goto hard;
		}
E 15
I 15
D 17
	if ((upaddr->uper1 & (UPER1_DCK|UPER1_ECH)) == UPER1_DCK) {
E 17
I 17
	if ((upaddr->uper1 & (UPER1_DCK|UPER1_ECH|UPER1_HCRC)) == UPER1_DCK) {
E 17
		if (upecc(io, ECC) == 0)
I 17
#ifdef F_SEVRE
		    if (io->i_flgs & F_SEVRE)
			return (-1);
		    else
#endif
E 17
			goto success;
		io->i_error = EECC;
		goto hard;
E 15
	} 
I 17
#ifdef F_SEVRE
	if (io->i_flgs & F_SEVRE)
		goto hard;
#endif
E 17
E 8
	/*
E 20
D 25
	 * Clear drive error and, every eight attempts,
	 * (starting with the fourth)
	 * recalibrate to clear the slate.
E 25
I 25
	 * Clear drive error and, every eight attempts, (starting with the
	 * fourth) recalibrate to clear the slate.
E 25
	 */
	upaddr->upcs1 = UP_TRE|UP_DCLR|UP_GO;
D 7
	if ((io->i_errcnt&07) == 4 && io->i_active == 0) {
E 7
I 7
	if ((io->i_errcnt&07) == 4 ) {
E 7
		upaddr->upcs1 = UP_RECAL|UP_GO;
D 7
		recal = 0;
		goto nextrecal;
E 7
I 7
D 17
		recal = 1;
		goto restart;
E 7
	}
	/*
	 * Advance recalibration finite state machine
	 * if recalibrate in progress, through
	 *	RECAL
	 *	SEEK
	 *	OFFSET (optional)
	 *	RETRY
	 */
	switch (recal) {

	case 1:
E 17
I 17
D 28
		while ((upaddr->upds&UPDS_DRY) == 0)
			DELAY(25);
E 28
I 28
		upwaitdry(upaddr);
E 28
E 17
		upaddr->updc = cn;
		upaddr->upcs1 = UP_SEEK|UP_GO;
D 7
		goto nextrecal;
E 7
I 7
D 8
		recal++;
E 8
I 8
D 17
		recal = 2;
E 8
		goto restart;
E 7
I 2

E 2
	case 2:
		if (io->i_errcnt < 16 || (func & READ) == 0)
			goto donerecal;
E 17
I 17
D 28
		while ((upaddr->upds&UPDS_DRY) == 0)
			DELAY(25);
E 28
I 28
		upwaitdry(upaddr);
E 28
	}
	if (io->i_errcnt >= 16 && (func & READ)) {
E 17
		upaddr->upof = up_offset[io->i_errcnt & 017] | UPOF_FMT22;
		upaddr->upcs1 = UP_OFFSET|UP_GO;
D 7
	nextrecal:
E 7
D 8
		recal++;
E 8
I 8
D 17
		recal = 3;
E 8
D 7
		io->i_active = 1;
		goto readmore;
E 7
I 7
		goto restart;
E 7
I 2

E 2
	donerecal:
	case 3:
		recal = 0;
D 7
		io->i_active = 0;
E 7
		break;
	}
	/*
D 7
	 * If still ``active'', then don't need any more retries.
E 7
I 7
	 * If we were offset positioning,
	 * return to centerline.
E 7
	 */
D 7
	if (io->i_active) {
		/*
		 * If we were offset positioning,
		 * return to centerline.
		 */
		if (io->i_errcnt >= 16) {
			upaddr->upof = UPOF_FMT22;
			upaddr->upcs1 = UP_RTC|UP_GO;
D 2
			while (!upaddr->upds & UPDS_DRY) /* removed PIP test*/
E 2
I 2
			while ((upaddr->upds&UPDS_DRY) == 0)
E 2
				DELAY(25);
		}
		goto readmore;
E 7
I 7
	if (io->i_errcnt >= 16) {
		upaddr->upof = UPOF_FMT22;
		upaddr->upcs1 = UP_RTC|UP_GO;
E 17
D 28
		while ((upaddr->upds&UPDS_DRY) == 0)
			DELAY(25);
E 28
I 28
		upwaitdry(upaddr);
E 28
E 7
	}
I 7
	goto restart;
I 8

E 8
E 7
success:
D 7
	io->i_active = 1;
E 7
D 2
	if (upaddr->upwc != 0) {
E 2
I 2
D 12
	if (upaddr->upwc != 0)
E 12
I 12
D 15
	if (upaddr->upwc != 0) {
E 15
I 15
#define	rounddown(x, y)	(((x) / (y)) * (y))
	upaddr->upwc = rounddown(upaddr->upwc, sectsiz / sizeof (short));
	if (upaddr->upwc) {
I 23
#ifndef SMALL
E 23
E 15
		doprintf++;
I 23
#endif
E 23
E 12
E 2
D 7
		goto readmore;
E 7
I 7
		goto restart;
I 12
	}
I 17
done:
E 17
E 12
E 7
D 2
	}
E 2
D 25
	/*
D 13
	 * Release unibus 
E 13
I 13
	 * Release UNIBUS 
E 13
	 */
E 25
	ubafree(io, info);
I 17
	/*
	 * If we were offset positioning,
	 * return to centerline.
	 */
	if (io->i_errcnt >= 16) {
		upaddr->upof = UPOF_FMT22;
		upaddr->upcs1 = UP_RTC|UP_GO;
D 28
		while ((upaddr->upds&UPDS_DRY) == 0)
			DELAY(25);
E 28
I 28
		upwaitdry(upaddr);
E 28
	}
E 17
D 20
	return (io->i_cc);
E 20
I 20
	return (rv);
E 20
}

I 28
upwaitrdy(upaddr)
	register struct updevice *upaddr;
{
	do {
		DELAY(25);
	} while ((upaddr->upcs1 & UP_RDY) == 0);
}

upwaitdry(upaddr)
	register struct updevice *upaddr;
{
	while ((upaddr->upds&UPDS_DRY) == 0)
		DELAY(25);
}

E 28
I 22
#ifndef SMALL
E 22
/*
D 11
 * Correct an ECC error, and restart the i/o to complete
 * the transfer if necessary.  This is quite complicated because
 * the transfer may be going to an odd memory address base and/or
E 11
I 11
D 25
 * Correct an ECC error, and restart the
 * i/o to complete the transfer (if necessary). 
 * This is quite complicated because the transfer
 * may be going to an odd memory address base and/or
E 11
 * across a page boundary.
E 25
I 25
 * Correct an ECC error, and restart the i/o to complete the transfer (if
 * necessary).  This is quite complicated because the transfer may be going
 * to an odd memory address base and/or across a page boundary.
E 25
 */
D 2
upecc( io, flag)
E 2
I 2
upecc(io, flag)
E 2
	register struct iob *io;
	int flag;
{
I 13
D 24
	register i, unit = io->i_unit;
I 20
	register struct up_softc *sc = &up_softc[unit];
E 20
E 13
	register struct updevice *up = 
D 13
		(struct updevice *)ubamem(io->i_unit, ubastd[0]);
E 13
I 13
		(struct updevice *)ubamem(unit, ubastd[0]);
E 24
I 24
	register i, unit;
	register struct up_softc *sc;
	register struct updevice *up;
E 24
E 13
D 4
	register struct upst *st;
E 4
I 4
D 25
	register struct st *st;
E 25
I 25
	register struct disklabel *lp;
E 25
E 4
D 13
	register int i;
E 13
	caddr_t addr;
D 4
	int bit, byte, npf, mask;
	int bn, twc, bbn;
E 4
I 4
D 5
	int bn, twc, npf, mask;
E 5
I 5
	int bn, twc, npf, mask, cn, tn, sn;
E 5
	daddr_t bbn;
E 4

	/*
D 11
	 * Npf is the number of sectors transferred before the sector
	 * containing the ECC error, bn is the current block number
E 11
I 11
	 * Npf is the number of sectors transferred
	 * before the sector containing the ECC error;
	 * bn is the current block number.
E 11
	 */
I 24
	unit = io->i_unit;
	sc = &up_softc[io->i_adapt][io->i_ctlr][unit];
I 25
	lp = &uplabel[io->i_adapt][io->i_ctlr][unit];
E 25
D 29
	up = (struct updevice *)ubamem(io->i_adapt, ubastd[io->i_ctlr]);
E 29
I 29
	up = (struct updevice *)ubamem(io->i_adapt, upstd[io->i_ctlr]);
E 29
E 24
D 4
	npf = btop((up->upwc * sizeof(short)) + io->i_cc);
	mask = up->upec2;
E 4
I 4
	twc = up->upwc;
D 11
	npf = ((twc * sizeof(short)) + io->i_cc)/sectsiz;
E 11
I 11
	npf = ((twc * sizeof(short)) + io->i_cc) / sectsiz;
I 17
	if (flag == ECC)
		npf--;
E 17
E 11
E 4
D 13
#ifdef UPECCDEBUG
D 11
	printf("npf %d mask 0x%x pos %d wc 0x%x\n",npf,mask,up->upec1,-up->upwc);
E 11
I 11
	printf("npf %d mask 0x%x pos %d wc 0x%x\n",
D 12
		npf, up->ec2, up->upec1, -twc);
E 12
I 12
		npf, up->upec2, up->upec1, -twc);
E 12
E 11
#endif
E 13
I 13
D 20
	if (updebug[unit] & UPF_ECCDEBUG)
E 20
I 20
	if (sc->debug & UPF_ECCDEBUG)
E 20
D 15
		printf("npf=%d mask=0x%x pos=%d wc=0x%x\n",
			npf, up->upec2, up->upec1, -twc);
E 15
I 15
		printf("npf=%d mask=0x%x ec1=%d wc=%d\n",
			npf, up->upec2, up->upec1, twc);
E 15
E 13
D 4
	bn = io->i_bn + npf + 1 ;
E 4
I 4
D 12
	bn = io->i_bn + npf ;
E 12
I 12
	bn = io->i_bn + npf;
E 12
E 4
D 13
	st = &upst[up_type[io->i_unit]];
E 13
I 13
D 20
	st = &upst[up_type[unit]];
E 20
I 20
D 25
	st = &upst[sc->type];
E 20
E 13
D 4
	twc = up->upwc;
E 4
D 7
	io->i_active = 2;
E 7
I 5
	cn = bn/st->nspc;
	sn = bn%st->nspc;
	tn = sn/st->nsect;
	sn = sn%st->nsect;
E 25
I 25
	cn = bn / lp->d_secpercyl;
	sn = bn % lp->d_secpercyl;
	tn = sn / lp->d_nsectors;
	sn = sn % lp->d_nsectors;
E 25
I 11

E 11
E 5
	/*
D 11
	 * action taken depends on the flag
E 11
I 11
	 * ECC correction.
E 11
	 */
	if (flag == ECC) {
I 4
D 12
		int bit, byte, ecccnt;
E 12
I 12
D 20
		int bit, o, ecccnt;
E 20
I 20
		int bit, o;
E 20
E 12
I 8

E 8
D 20
		ecccnt = 0;
E 20
E 4
		mask = up->upec2;
D 4
		printf("up%d: soft ecc sn%d\n", io->i_unit, io->i_bn + npf +1);
E 4
I 4
D 7
		printf("up%d: soft ecc sn%d\n", io->i_unit, io->i_bn + npf );
E 7
I 7
D 13
		printf("up%d: soft ecc sn%d\n", io->i_unit, bn);
E 13
I 13
		printf("up%d: soft ecc sn%d\n", unit, bn);
I 20
		for (i = mask, bit = 0; i; i >>= 1)
			if (i & 1)
				bit++;
		if (bit > sc->ecclim) {
			printf("%d-bit error\n", bit);
			return (1);
		}
E 20
E 13
E 7
E 4
		/*
D 11
		 * Compute the
		 * byte and bit position of the error.  The variable i
		 * is the byte offset in the transfer.
E 11
I 11
D 12
		 * Compute the byte and bit position
		 * of the error.  i is the byte offset
		 * in the transfer at which the correction
		 * is first applied.
E 12
I 12
		 * Compute the byte and bit position of
		 * the error.  o is the byte offset in
		 * the transfer at which the correction
		 * applied.
E 12
E 11
		 */
I 12
D 17
		npf--;
E 17
E 12
		i = up->upec1 - 1;		/* -1 makes 0 origin */
D 15
		bit = i&07;
D 12
		i = (i&~07)>>3;
		byte = i;
E 12
I 12
		o = (i&~07) >> 3;
E 15
I 15
		bit = i & 07;
		o = (i & ~07) >> 3;
E 15
E 12
		up->upcs1 = UP_TRE|UP_DCLR|UP_GO;
		/*
D 11
		 * Correct while possible bits remain of mask.  Since mask
		 * contains 11 bits, we continue while the bit offset is > -11.
		 * Also watch out for end of this block and the end of the whole
		 * transfer.
E 11
I 11
		 * Correct while possible bits remain of mask.
		 * Since mask contains 11 bits, we continue while
		 * the bit offset is > -11.  Also watch out for
		 * end of this block and the end of the transfer.
E 11
		 */
D 4
		while (i < 512 && (int)ptob(npf)+i < io->i_cc && bit > -11) {
E 4
I 4
D 12
		while (i < sectsiz && (npf*sectsiz)+i < io->i_cc && bit > -11) {
E 12
I 12
		while (o < sectsiz && (npf*sectsiz)+o < io->i_cc && bit > -11) {
E 12
E 4
			/*
D 2
			 * addr = vax base addr + ( number of sectors transferred
E 2
I 2
D 11
			 * addr = vax base addr + (number of sectors transferred
E 2
			 *	  before the error sector times the sector size)
			 *	  + byte number
E 11
I 11
			 * addr =
D 12
			 *  vax base addr +
E 12
I 12
			 *  (base address of transfer) +
E 12
			 *  (# sectors transferred before the error) *
			 *    (sector size) +
D 12
			 *  byte number
E 12
I 12
			 *  (byte offset to incorrect data)
E 12
E 11
			 */
D 4
			addr = io->i_ma + (npf*512) + byte;
E 4
I 4
D 8
			addr = io->i_ma + (npf*sectsiz) + byte;
E 8
I 8
D 12
			addr = io->i_ma + (npf * sectsiz) + byte;
E 12
I 12
			addr = io->i_ma + (npf * sectsiz) + o;
E 12
E 8
E 4
D 13
#ifdef UPECCDEBUG
D 4
			printf("addr %x old: %x ",addr, *addr);
E 4
I 4
D 12
			printf("addr %x old: %x ",addr, (*addr&0xff));
E 12
I 12
			printf("addr %x old: %x ", addr, (*addr&0xff));
E 12
E 4
#endif
E 13
I 12
			/*
			 * No data transfer occurs with a write check,
			 * so don't correct the resident copy of data.
			 */
E 12
D 4
			*addr ^= (mask << bit);
E 4
I 4
D 13
			if ((io->i_flgs & (F_CHECK|F_HCHECK)) == 0)
E 13
I 13
			if ((io->i_flgs & (F_CHECK|F_HCHECK)) == 0) {
D 20
				if (updebug[unit] & UPF_ECCDEBUG)
E 20
I 20
				if (sc->debug & UPF_ECCDEBUG)
E 20
					printf("addr=0x%x old=0x%x ", addr,
						(*addr&0xff));
E 13
				*addr ^= (mask << bit);
E 4
D 13
#ifdef UPECCDEBUG
D 4
			printf("new: %x\n", *addr);
E 4
I 4
			printf("new: %x\n", (*addr&0xff));
E 4
#endif
E 13
I 13
D 20
				if (updebug[unit] & UPF_ECCDEBUG)
E 20
I 20
				if (sc->debug & UPF_ECCDEBUG)
E 20
					printf("new=0x%x\n", (*addr&0xff));
			}
E 13
D 11
			byte++;
			i++;
E 11
I 11
D 12
			byte++, i++;
E 11
			bit -= 8;
E 12
I 12
			o++, bit -= 8;
E 12
I 4
D 8
			if ((ecccnt++ >= MAXECC) && ((io->i_flgs&F_ECCLM) != 0))
				return(1);
E 8
I 8
D 20
			if ((io->i_flgs&F_ECCLM) && ++ecccnt > MAXECC)
				return (1);
E 20
E 8
E 4
		}
I 17
D 20
#ifdef F_SEVRE
		if (io->i_flgs & F_SEVRE) {
			io->i_error = EECC;
			io->i_bn = bn;
			return(1);
		}
#endif
E 20
E 17
I 4
D 8
		return(0);
E 4
#ifndef NOBADSECT
	} else if (flag == BSE) {
E 8
I 8
		return (0);
	}
I 11

	/*
	 * Bad sector forwarding.
	 */
E 11
	if (flag == BSE) {
E 8
		/*
D 4
		 * if not in bad sector table, return 0
E 4
I 4
D 11
		 * if not in bad sector table, return 1 (= hard error)
E 11
I 11
		 * If not in bad sector table,
		 * indicate a hard error to caller.
E 11
E 4
		 */
D 4
		if ((bbn = isbad(&upbad[io->i_unit], st, bn)) < 0)
			return(0);
E 4
		up->upcs1 = UP_TRE|UP_DCLR|UP_GO;
I 4
D 5
		if ((bbn = isbad(&upbad[io->i_unit], st, bn)) < 0)
E 5
I 5
D 13
		if ((bbn = isbad(&upbad[io->i_unit], cn, tn, sn)) < 0)
E 13
I 13
D 24
		if ((bbn = isbad(&upbad[unit], cn, tn, sn)) < 0)
E 24
I 24
		if ((bbn = isbad(&upbad[io->i_adapt][io->i_ctlr][unit], cn, tn, sn)) < 0)
E 24
E 13
E 5
D 8
			return(1);
E 8
I 8
			return (1);
E 8
E 4
D 15
		bbn = st->ncyl * st->nspc -st->nsect - 1 - bbn;
E 15
I 15
D 25
		bbn = (st->ncyl * st->nspc) - st->nsect - 1 - bbn;
E 25
I 25
		bbn = (lp->d_ncylinders * lp->d_secpercyl) -
			lp->d_nsectors - 1 - bbn;
E 25
E 15
D 4
		twc = up->upwc + 512;
		up->upwc = -(512 / sizeof (short));
E 4
I 4
		twc = up->upwc + sectsiz;
D 8
		up->upwc = -(sectsiz / sizeof (short));
E 8
I 8
		up->upwc = - (sectsiz / sizeof (short));
E 8
E 4
D 13
#ifdef UPECCDEBUG
		printf("revector to block %d\n", bbn);
#endif
E 13
I 13
D 20
		if (updebug[unit] & UPF_BSEDEBUG)
E 20
I 20
		if (sc->debug & UPF_BSEDEBUG)
E 20
			printf("revector sn %d to %d\n", sn, bbn);
E 13
		/*
D 11
	 	* Clear the drive & read the replacement sector.
	 	* If this is in the middle of a transfer, then set up the
	 	* controller registers in a normal fashion. 
	 	* The ub-address need not be changed.
	 	*/
E 11
I 11
	 	 * Clear the drive & read the replacement
		 * sector.  If this is in the middle of a
		 * transfer, then set up the controller
		 * registers in a normal fashion. 
	 	 * The UNIBUS address need not be changed.
	 	 */
E 11
D 2
		while ( up->upcs1 & UP_RDY == 0) 
E 2
I 2
D 15
		while (up->upcs1 & UP_RDY == 0) 
E 15
I 15
D 28
		while ((up->upcs1 & UP_RDY) == 0) 
E 15
E 2
			;
E 28
I 28
		upwaitrdy(up);
E 28
D 4
		up->upcs1 = UP_TRE|UP_DCLR|UP_GO;
E 4
D 2
		if (upstart(io, bbn) != 0) return (0);
E 2
I 2
D 15
		if (upstart(io, bbn) != 0)
E 15
I 15
D 25
		if (upstart(io, bbn))
E 25
I 25
		if (upstart(io, bbn, lp))
E 25
E 15
D 4
			return (0);
E 2
		io->i_errcnt = 0;
E 4
I 4
			return (1);		/* error */
		io->i_errcnt = 0;		/* success */
E 4
D 28
		do {
			DELAY(25);
D 15
		} while ( up->upcs1 & UP_RDY == 0) ;
		if (up->upds & UPDS_ERR || up->upcs1 & UP_TRE) {
D 4
			up->upwc = twc -512;
			return (0);
E 4
I 4
			up->upwc = twc -sectsiz;
E 15
I 15
		} while ((up->upcs1 & UP_RDY) == 0) ;
E 28
I 28
		upwaitrdy(up);
E 28
		if ((up->upds & UPDS_ERR) || (up->upcs1 & UP_TRE)) {
			up->upwc = twc - sectsiz;
E 15
			return (1);
E 4
		}
	}
D 2
	if (twc != 0) {
E 2
I 2
D 7
	if (twc != 0)
E 7
I 7
	if (twc)
E 7
E 2
		up->upwc = twc;
D 2
	}
E 2
D 4
	return (1);
E 4
I 4
	return (0);
E 4
}
I 22
D 24
#endif
E 24
I 24
#endif /* !SMALL */
E 24
E 22

D 4
#ifndef NOBADSECT
D 2

E 2
/*
 * Search the bad sector table looking for
 * the specified sector.  Return index if found.
 * Return -1 if not found.
 */
D 2

E 2
isbad(bt, st, blno)
	register struct dkbad *bt;
	register struct upst *st;
{
	register int i;
	register long blk, bblk;
	int trk, sec;

	sec = blno % st->nspc;
	trk = sec / st->nsect;
	sec %= st->nsect;
	blk = ((long)(blno/st->nspc) << 16) + (trk << 8) + sec;
	for (i = 0; i < 126; i++) {
D 2
		bblk = ((long)bt->bt_bad[i].bt_cyl << 16) + bt->bt_bad[i].bt_trksec;
E 2
I 2
		bblk = ((long)bt->bt_bad[i].bt_cyl << 16) +
			bt->bt_bad[i].bt_trksec;
E 2
		if (blk == bblk)
			return (i);
		if (blk < bblk || bblk < 0)
			break;
	}
	return (-1);
}
#endif

E 4
D 25
upstart(io, bn)
E 25
I 25
upstart(io, bn, lp)
E 25
D 2
register struct iob *io;
daddr_t bn;
E 2
I 2
	register struct iob *io;
	daddr_t bn;
I 25
	register struct disklabel *lp;
E 25
E 2
{
D 24
	register struct updevice *upaddr = 
D 2
			(struct updevice *)ubamem(io->i_unit, ubastd[0]);
E 2
I 2
		(struct updevice *)ubamem(io->i_unit, ubastd[0]);
E 2
D 4
	register struct upst *st = &upst[up_type[io->i_unit]];
E 4
I 4
D 20
	register struct st *st = &upst[up_type[io->i_unit]];
E 20
I 20
	register struct up_softc *sc = &up_softc[io->i_unit];
	register struct st *st = &upst[sc->type];
E 24
I 24
	register struct updevice *upaddr;
	register struct up_softc *sc;
D 25
	register struct st *st;
E 25
E 24
E 20
E 4
	int sn, tn;

I 24
D 29
	upaddr = (struct updevice *)ubamem(io->i_adapt, ubastd[io->i_ctlr]);
E 29
I 29
	upaddr = (struct updevice *)ubamem(io->i_adapt, upstd[io->i_ctlr]);
E 29
	sc = &up_softc[io->i_adapt][io->i_ctlr][io->i_unit];
D 25
	st = &upst[sc->type];
E 24
	sn = bn%st->nspc;
	tn = sn/st->nsect;
	sn %= st->nsect;
	upaddr->updc = bn/st->nspc;
E 25
I 25
	sn = bn % lp->d_secpercyl;
	tn = sn / lp->d_nsectors;
	sn = sn % lp->d_nsectors;
	upaddr->updc = bn / lp->d_secpercyl;
E 25
	upaddr->upda = (tn << 8) + sn;
D 2
	switch (up_ctl[io->i_unit]) {
	case NORMAL:
		if (io->i_flgs & IO_READ)
			upaddr->upcs1 = UP_RCOM|UP_GO;
		else
			upaddr->upcs1 = UP_WCOM|UP_GO;
E 2
I 2
D 4
	switch (io->i_flgs&F_TYPEMASK) {
E 4
I 4
	switch (io->i_flgs & F_TYPEMASK) {
E 4

	case F_RDDATA:
		upaddr->upcs1 = UP_RCOM|UP_GO;
E 2
		break;
D 2
	case HDRIO:	
		if (io->i_flgs & IO_READ)	
			upaddr->upcs1 = UP_RHDR|UP_GO;
		else
			upaddr->upcs1 = UP_WHDR|UP_GO;
E 2
I 2

	case F_WRDATA:
		upaddr->upcs1 = UP_WCOM|UP_GO;
E 2
		break;
D 2
	case WCHECK:
		/* don't care if read or write, write check is writecheck
		 * anyhow  */
E 2
I 2

I 22
#ifndef SMALL
E 22
D 24
	case F_HDR|F_RDDATA:	
E 24
I 24
	case F_HDR|F_RDDATA:
E 24
		upaddr->upcs1 = UP_RHDR|UP_GO;
		break;

	case F_HDR|F_WRDATA:
		upaddr->upcs1 = UP_WHDR|UP_GO;
		break;

	case F_CHECK|F_WRDATA:
	case F_CHECK|F_RDDATA:
E 2
		upaddr->upcs1 = UP_WCDATA|UP_GO;
		break;
D 2
	case WHCHECK:
		/* don't care if read or write, write check is writecheck
		 * anyhow  */
E 2
I 2

	case F_HCHECK|F_WRDATA:
	case F_HCHECK|F_RDDATA:
E 2
		upaddr->upcs1 = UP_WCHDR|UP_GO;
		break;
I 22
#endif
E 22
I 2

E 2
	default:
D 2
		io->i_error = IOERR_CMD;
		return(1);
E 2
I 2
		io->i_error = ECMD;
		io->i_flgs &= ~F_TYPEMASK;
		return (1);
E 2
	}
D 2
	return(0) ;
E 2
I 2
	return (0);
E 2
}

I 24
#ifndef SMALL
E 24
I 2
/*ARGSUSED*/
upioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{
I 22
D 24
#ifndef SMALL
E 24
E 22
D 8

E 8
D 4
	return (ECMD);
E 4
I 4
D 13
	struct st *st = &upst[up_type[io->i_unit]], *tmp;
E 13
I 13
D 20
	int unit = io->i_unit, flag;
	struct st *st = &upst[up_type[unit]], *tmp;
E 20
I 20
D 25
	int unit = io->i_unit;
E 25
D 24
	register struct up_softc *sc = &up_softc[unit];
	struct st *st = &upst[sc->type];
E 24
I 24
	register struct up_softc *sc;
D 25
	struct st *st;
E 25
E 24
E 20
E 13

I 24
D 25
	sc = &up_softc[io->i_adapt][io->i_ctlr][unit];
	st = &upst[sc->type];
E 25
I 25
	sc = &up_softc[io->i_adapt][io->i_ctlr][io->i_unit];
E 25
E 24
	switch(cmd) {
I 13
D 25

E 25
	case SAIODEBUG:
D 20
		flag = (int)arg;
		if (flag > 0)
			updebug[unit] |= flag;
		else
			updebug[unit] &= ~flag;
		return (0);
E 20
I 20
		sc->debug = (int)arg;
		break;
E 20
E 13
D 25

E 25
	case SAIODEVDATA:
D 20
		tmp = (struct st *)arg;
		*tmp = *st;
D 8
		return(0);

	default:
		return (ECMD);
E 8
I 8
		return (0);
E 20
I 20
D 25
		*(struct st *)arg = *st;
E 25
I 25
		*(struct disklabel *)arg =
		    uplabel[io->i_adapt][io->i_ctlr][io->i_unit];
E 25
		break;
D 25

E 25
	case SAIOGBADINFO:
D 24
		*(struct dkbad *)arg = upbad[unit];
E 24
I 24
D 25
		*(struct dkbad *)arg = upbad[io->i_adapt][io->i_ctlr][unit];
E 25
I 25
		*(struct dkbad *)arg =
		    upbad[io->i_adapt][io->i_ctlr][io->i_unit];
E 25
E 24
		break;
D 25

E 25
	case SAIOECCLIM:
		sc->ecclim = (int)arg;
		break;
D 25

E 25
	case SAIORETRIES:
		sc->retries = (int)arg;
		break;
D 25

E 25
	default:
		return (ECMD);
E 20
E 8
	}
I 8
D 20
	return (ECMD);
E 20
I 20
	return (0);
I 22
D 24
#else SMALL
	return (ECMD);
#endif
E 24
E 22
E 20
E 8
}
I 24
#endif /* !SMALL */
E 24
D 8

E 8
D 5
/* this routine is common to up & hp, move to separate file */

/*
 * Search the bad sector table looking for
 * the specified sector.  Return index if found.
 * Return -1 if not found.
 */

isbad(bt, st, blno)
	register struct dkbad *bt;
	register struct st *st;
{
	register int i;
	register long blk, bblk;
	int trk, sec;

	sec = blno % st->nspc;
	trk = sec / st->nsect;
	sec %= st->nsect;
	blk = ((long)(blno/st->nspc) << 16) + (trk << 8) + sec;
	for (i = 0; i < MAXBADDESC; i++) {
		bblk = ((long)bt->bt_bad[i].bt_cyl << 16) +
			bt->bt_bad[i].bt_trksec;
		if (blk == bblk)
			return (i);
		if (blk < bblk || bblk < 0)
			break;
	}
	return (-1);
E 4
}
E 5
E 2
E 1
