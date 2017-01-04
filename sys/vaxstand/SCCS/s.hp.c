h23293
s 00010/00002/00570
d D 7.10 88/07/08 15:05:51 karels 41 40
c DWIM
e
s 00011/00010/00561
d D 7.9 88/05/27 15:50:11 karels 40 39
c unbreak compat code, allow formatter to open unformatted disk
e
s 00008/00008/00563
d D 7.8 88/03/03 14:30:14 bostic 39 37
c add ERDLAB, EUNLAB
e
s 00007/00007/00564
d R 7.8 88/02/25 13:16:27 bostic 38 37
c add ERDLAB, EUNLAB
e
s 00001/00003/00570
d D 7.7 88/02/24 10:59:59 bostic 37 36
c default to dev error, doesn't tell you anything new
e
s 00072/00064/00501
d D 7.6 88/02/23 16:09:40 bostic 36 35
c change to dev(a,b,c,d) format
e
s 00020/00019/00545
d D 7.5 88/01/28 20:54:32 karels 35 34
c uvax changes; fix devsw index in confxx; header updates
e
s 00008/00006/00556
d D 7.4 87/12/12 23:36:02 karels 34 33
c fixes
e
s 00001/00001/00561
d D 7.3 87/02/21 11:44:19 karels 33 32
c restore keywords
e
s 00117/00062/00445
d D 7.2 87/02/21 11:41:32 karels 32 31
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00506
d D 7.1 86/06/05 01:42:03 mckusick 31 30
c 4.3BSD release version
e
s 00132/00149/00375
d D 6.8 85/11/08 19:15:26 karels 30 29
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00007/00001/00517
d D 6.7 85/06/08 13:08:27 mckusick 29 28
c Add copyright
e
s 00003/00006/00515
d D 6.6 85/03/27 10:39:33 miriam 28 26
c fix ecc error recovery
e
s 00002/00008/00513
d R 6.6 84/08/09 09:09:14 ralph 27 26
c fix skip sector error handling for RM80
e
s 00001/00001/00520
d D 6.5 84/04/02 11:50:49 karels 26 25
c maptype wants drive number
e
s 00001/00000/00520
d D 6.4 84/02/06 13:00:20 karels 25 24
c allow second open of same device (initialize those variables!)
e
s 00005/00009/00515
d D 6.3 83/09/23 16:48:04 karels 24 23
c do RTC after retries fail
e
s 00051/00034/00473
d D 6.2 83/09/23 10:07:22 karels 23 22
c ghg's severe burnin format
e
s 00000/00000/00507
d D 6.1 83/07/29 07:46:54 sam 22 21
c 4.2 distribution
e
s 00098/00081/00409
d D 4.17 83/03/01 23:29:02 sam 21 20
c add debugging flags so the code'll always be there; fix bn 
c calculation bug (helge why don't you make all the drivers look the same?)
e
s 00017/00010/00473
d D 4.16 83/02/20 19:23:26 sam 20 19
c eliminate unneeded variable; slight cleanups
e
s 00059/00102/00424
d D 4.15 83/02/18 05:23:49 sam 19 18
c pull out common type mapping code for hp's
e
s 00007/00005/00519
d D 4.14 83/02/17 11:50:49 sam 18 17
c handle drive mapping chores
e
s 00001/00001/00523
d D 4.13 83/02/17 10:22:31 helge 17 16
c corrected the message printed by map-routine when RM02
e
s 00002/00001/00522
d D 4.12 83/02/17 09:56:26 helge 16 15
c added missing statement in map routine
e
s 00001/00001/00522
d D 4.11 83/02/16 23:21:00 sam 15 14
c typo
e
s 00130/00124/00393
d D 4.10 83/02/16 21:56:27 sam 14 13
c break out type mapping code; untangle some code
e
s 00024/00031/00493
d D 4.9 83/02/10 17:32:14 sam 13 12
c don't hang on hpds, it monopolizes SC750 and SC780's
e
s 00012/00004/00512
d D 4.8 83/02/02 16:18:56 helge 12 10
c added 48 sector eagle to device table
e
s 00014/00004/00512
d R 4.8 83/02/02 13:57:09 helge 11 10
c added 48 sect eagle to device table
e
s 00042/00023/00474
d D 4.7 83/02/01 17:25:14 helge 10 8
c fix in the skip sector handling
e
s 00006/00002/00495
d R 4.7 83/01/31 15:19:59 helge 9 8
c improved drive initialization, some cosmetic changes
e
s 00002/00002/00495
d D 4.6 83/01/29 14:34:16 helge 8 7
c fixed minor bug in hpopen
e
s 00082/00044/00415
d D 4.5 83/01/29 13:32:38 helge 7 5
c lots of fixes: hard error handling, bad sector forwarding, skip sector
c handling, new ioctl commands for `skip sector inhibit'
e
s 00075/00041/00418
d R 4.5 83/01/27 11:35:30 helge 6 5
c lots of fixes to the hard error handling; bad sector forw., skip sector
c handling and some new ioctl's
e
s 00021/00022/00438
d D 4.4 83/01/23 17:25:20 sam 5 4
c check in for Helge before cutting tape for Robert
e
s 00011/00042/00449
d D 4.3 83/01/18 16:10:41 helge 4 2
c removed local copy of isbad, fixed (?) skip sector handling, need more testing !!
e
s 00011/00042/00449
d R 4.3 83/01/18 15:07:43 helge 3 2
c removed the local copy of isbad, hard error handling need more testing!!
e
s 00008/00018/00483
d D 4.2 83/01/17 10:49:12 helge 2 1
c moved def of struct st to saio.h, deleted struct devdata
e
s 00501/00000/00000
d D 4.1 83/01/16 15:00:33 helge 1 0
c date and time created 83/01/16 15:00:33 by helge
e
u
U
t
T
I 1
D 29
/*	%M%	%I%	%E%	*/
E 29
I 29
/*
D 31
 * Copyright (c) 1982 Regents of the University of California.
E 31
I 31
D 32
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 32
I 32
D 35
 * Copyright (c) 1982 Regents of the University of California.
E 35
I 35
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 35
E 32
E 31
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 32
 *	%W% (Berkeley) %G%
E 32
I 32
D 33
 *	@(#)hp.c	6.8 (Berkeley) 11/8/85
E 33
I 33
 *	%W% (Berkeley) %G%
E 33
E 32
 */
E 29

/*
D 36
 * RP??/RM?? disk driver
 * with ECC handling and bad block forwarding.
 * Also supports header io operations and
 * commands to write check header and data.
E 36
I 36
 * RP??/RM?? disk driver with ECC handling and bad block forwarding.
 * Also supports header io operations and commands to write check
 * header and data.
E 36
 */
D 21

E 21
D 35
#include "../h/param.h"
#include "../h/inode.h"
#include "../h/fs.h"
#include "../h/dkbad.h"
I 32
#include "../h/disklabel.h"
E 35
I 35
#include "param.h"
#include "inode.h"
#include "fs.h"
#include "dkbad.h"
#include "disklabel.h"
E 35
E 32

#include "../vax/pte.h"
I 35

E 35
#include "../vaxmba/hpreg.h"
#include "../vaxmba/mbareg.h"

#include "saio.h"
#include "savax.h"

I 30
#define	RETRIES		27

E 30
#define	MASKREG(reg)	((reg)&0xffff)

D 21
#define MAXBADDESC	126
#define SECTSIZ 	512	/* sector size in bytes */
#define HDRSIZ		4	/* number of bytes in sector header */
D 19
#define MAXECC		5	/* the maximum number of bad bits accepted in
				 * an ecc error when F_ECCLM is set */
E 19
I 19
#define MAXECC		5	/* max # bits allow in ecc error w/ F_ECCLM */
E 21
I 21
#define	MAXBADDESC	126
#define	SECTSIZ 	512	/* sector size in bytes */
#define	HDRSIZ		4	/* number of bytes in sector header */
D 30
#define	MAXECC		5	/* max # bits allow in ecc error w/ F_ECCLM */
E 30
E 21
E 19

D 30
char	hp_type[MAXNMBA*8] = { 0 };
E 30
I 19
D 32
extern	struct st hpst[];
I 30
extern	short hptypes[];
E 32
I 32
char	lbuf[SECTSIZ];
E 32
E 30
E 19

D 19
/* THIS SHOULD BE READ IN OFF THE PACK, PER DRIVE */
short	hp6_off[8] =	{ 0, 38, 0, -1, -1, -1, 118, -1 };
short	rm3_off[8] =	{ 0, 100, 0, -1, -1, -1, 310, -1 };
short	rm5_off[8] =	{ 0, 27, 0, 562, 589, 681, 562, 82 };
short	rm80_off[8] =	{ 0, 37, 0, -1, -1, -1, 115, 305 };
short	hp7_off[8] = 	{ 0, 10, 0, 330, 340, 500, 330, 50 };
short	ml_off[8] =	{ 0, -1, -1, -1, -1, -1, -1, -1 };
short	si9775_off[8] =	{ 0, 13, 0, -1, -1, -1, 40, 441 };
short	si9730_off[8] = { 0, 50, 0, -1, -1, -1, -1, 155 };
short	hpam_off[8] =	{ 0, 32, 0, 668, 723, 778, 668, 98 };
I 7
short	hpfj_off[8] =	{ 0, 19, 0, -1, -1, -1, 398, 59 };
E 7
/* END SHOULD BE READ IN */

E 19
D 18
short	hptypes[] =
    { MBDT_RM03, MBDT_RM05, MBDT_RP06, MBDT_RM80, MBDT_RP05, MBDT_RP07,
D 7
      MBDT_ML11A, MBDT_ML11B, -1/*9755*/, -1/*9730*/, -1/*Capr*/, MBDT_RM02, 0};
E 7
I 7
      MBDT_ML11A, MBDT_ML11B, -1/*9755*/, -1/*9730*/, -1/*Capr*/,
D 12
      -1/* eagle */, MBDT_RM02, 0};
E 12
I 12
D 14
      -1/* eagle */, -1/* 48 sect eagle*/, MBDT_RM02, 0};
E 14
I 14
      -1/* eagle */, -1/* 48 sect eagle */, MBDT_RM02, 0};
E 18
I 18
D 30
short	hptypes[] = {
D 21
	MBDT_RM03,	MBDT_RM05,	MBDT_RP06,	MBDT_RM80,
	MBDT_RP05,	MBDT_RP07,	MBDT_ML11A,	MBDT_ML11B,
	-1 /*9755*/,	-1 /*9730*/,	-1 /*Cap*/,	-1 /* Eagle */,
	-1 /* Eagle */,	MBDT_RM02,	0
E 21
I 21
	MBDT_RM03,
	MBDT_RM05,
	MBDT_RP06,
	MBDT_RM80,
	MBDT_RP05,
	MBDT_RP07,
	MBDT_ML11A,
	MBDT_ML11B,
	-1,		/* 9755 */
	-1,		/* 9730 */
	-1,		/* Capricorn */
	-1,		/* Eagle */
	MBDT_RM02,	/* actually something else */
	-1,		/* 9300 */
	0
E 21
};
E 30
I 30
D 32
#define	RP06 (hptypes[sc->type] == MBDT_RP06 || hptypes[sc->type] == MBDT_RP05 \
	|| hptypes[sc->type] == MBDT_RP04)
#define	ML11 (hptypes[sc->type] == MBDT_ML11A)
#define	RM80 (hptypes[sc->type] == MBDT_RM80)
E 32
I 32
#define	RP06(type) ((type) == MBDT_RP06 || (type) == MBDT_RP05 \
	|| (type) == MBDT_RP04)
#define	ML11(type) ((type) == MBDT_ML11A)
#define	RM80(type) ((type) == MBDT_RM80)
E 32
E 30
E 18
E 14
E 12
E 7

D 7
#define RP06 (hptypes[UNITTODRIVE(unit)] <= MBDT_RP06)
#define ML11 (hptypes[UNITTODRIVE(unit)] <= MBDT_ML11A)
#define RM80 (hptypes[UNITTODRIVE(unit)] <= MBDT_RM80)
E 7
I 7
D 21
#define RP06 (hptypes[hp_type[unit]] <= MBDT_RP06)
#define ML11 (hptypes[hp_type[unit]] == MBDT_ML11A)
#define RM80 (hptypes[hp_type[unit]] == MBDT_RM80)
E 21
I 21
D 30
#define	RP06 (hptypes[hp_type[unit]] <= MBDT_RP06)
#define	ML11 (hptypes[hp_type[unit]] == MBDT_ML11A)
#define	RM80 (hptypes[hp_type[unit]] == MBDT_RM80)
E 21
D 10
#define EAGLE (hp_type[unit] == 11)
E 10
E 7

E 30
u_char	hp_offset[16] = {
D 36
    HPOF_P400, HPOF_M400, HPOF_P400, HPOF_M400,
    HPOF_P800, HPOF_M800, HPOF_P800, HPOF_M800,
    HPOF_P1200, HPOF_M1200, HPOF_P1200, HPOF_M1200,
    0, 0, 0, 0,
E 36
I 36
	HPOF_P400, HPOF_M400, HPOF_P400, HPOF_M400,
	HPOF_P800, HPOF_M800, HPOF_P800, HPOF_M800,
	HPOF_P1200, HPOF_M1200, HPOF_P1200, HPOF_M1200,
	0, 0, 0, 0,
E 36
};

I 32
D 36
struct	disklabel hplabel[MAXNMBA*8];
E 36
I 36
#define	MAXUNIT		8
struct	disklabel hplabel[MAXNMBA][MAXUNIT];
E 36
#ifndef SMALL
E 32
D 2
struct hpst {
	short	nsect;
	short	ntrak;
	short	nspc;
	short	ncyl;
	short	*off;
} hpst[] = {
E 2
I 2
D 19
struct st hpst[] = {
E 2
D 7
	32,	5,	32*5,	823,	rm3_off,	/* RM03 */
	32,	19,	32*19,	823,	rm5_off,	/* RM05 */
	22,	19,	22*19,	815,	hp6_off,	/* RP06 */
	31,	14, 	31*14,	559,	rm80_off,	/* RM80 */
	22,	19,	22*19,	411,	hp6_off,	/* RP06 */
	50,	32,	50*32,	630,	hp7_off,	/* RP07 */
	1,	1,	1,	1,	ml_off,		/* ML11A */
	1,	1,	1,	1,	ml_off,		/* ML11B */
	32,	40,	32*40,	843,	si9775_off,	/* 9775 */
	32,	10,	32*10,	823,	si9730_off,	/* 9730 */
	32,	16,	32*16,	1024,	hpam_off,	/* AMPEX capricorn */
	1,	1,	1,	1,	0,		/* rm02 - not used */
E 7
I 7
D 10
	32,	5,	32*5,	823,	rm3_off,	0,	/* RM03 */
	32,	19,	32*19,	823,	rm5_off,	0,	/* RM05 */
	22,	19,	22*19,	815,	hp6_off,	0,	/* RP06 */
	31,	14, 	31*14,	559,	rm80_off,	1,	/* RM80 */
	22,	19,	22*19,	411,	hp6_off,	0,	/* RP06 */
	50,	32,	50*32,	630,	hp7_off,	0,	/* RP07 */
	1,	1,	1,	1,	ml_off,		0,	/* ML11A */
	1,	1,	1,	1,	ml_off,		0,	/* ML11B */
	32,	40,	32*40,	843,	si9775_off,	0,	/* 9775 */
	32,	10,	32*10,	823,	si9730_off,	0,	/* 9730 */
	32,	16,	32*16,	1024,	hpam_off,	0,	/* capricorn */
	43,	20,	43*20,	842,	hpfj_off,	1,	/* Eagle */
	1,	1,	1,	1,	0,	0,	/* rm02 - not used */
E 10
I 10
	32,	5,	32*5,	823,	rm3_off,	/* RM03 */
	32,	19,	32*19,	823,	rm5_off,	/* RM05 */
	22,	19,	22*19,	815,	hp6_off,	/* RP06 */
	31,	14, 	31*14,	559,	rm80_off,	/* RM80 */
	22,	19,	22*19,	411,	hp6_off,	/* RP06 */
	50,	32,	50*32,	630,	hp7_off,	/* RP07 */
	1,	1,	1,	1,	ml_off,		/* ML11A */
	1,	1,	1,	1,	ml_off,		/* ML11B */
	32,	40,	32*40,	843,	si9775_off,	/* 9775 */
	32,	10,	32*10,	823,	si9730_off,	/* 9730 */
	32,	16,	32*16,	1024,	hpam_off,	/* capricorn */
	43,	20,	43*20,	842,	hpfj_off,	/* Eagle */
I 12
	48,	20,	48*20,	842,	hpfj_off,	/* modif. eagle */
E 12
D 18
	1,	1,	1,	1,	0,	/* rm02 - not used */
E 18
I 18
	1,	1,	1,	1,	0,		/* rm02 - not used */
E 18
E 10
E 7
};
I 14

E 19
E 14
D 21
struct dkbad hpbad[MAXNMBA*8];
int sectsiz;
E 21
I 21
D 36
struct	dkbad hpbad[MAXNMBA*8];
E 36
I 36
struct	dkbad hpbad[MAXNMBA][MAXUNIT];
E 36
I 32
int	sectsiz;
#endif
E 32
D 30
int	ssect[MAXNMBA*8];		/* 1 when on track w/skip sector */
E 30
E 21

I 21
D 30
int	hpdebug[MAXNMBA*8];
#define	HPF_BSEDEBUG	01	/* debugging bad sector forwarding */
#define	HPF_ECCDEBUG	02	/* debugging ecc correction */
E 30
I 30
struct	hp_softc {
	char	type;
	char	gottype;
D 36
	char	ssect;		/* 1 when on track w/skip sector */
E 36
I 36
	char	ssect;			/* 1 when on track w/skip sector */
E 36
	char	debug;
#	define	HPF_BSEDEBUG	01	/* debugging bad sector forwarding */
#	define	HPF_ECCDEBUG	02	/* debugging ecc correction */
	int	ecclim;
	int	retries;
D 36
} hp_softc[MAXNMBA * 8];
E 36
I 36
} hp_softc[MAXNMBA][MAXUNIT];
E 36
E 30

D 32
int	sectsiz;

E 32
E 21
I 13
/*
D 36
 * When awaiting command completion, don't
 * hang on to the status register since
D 21
 * this ties up the controller.
E 21
I 21
 * this ties up some controllers.
E 36
I 36
 * When awaiting command completion, don't hang on to the status register
 * since this ties up some controllers.
E 36
E 21
 */
D 21
#define	HPWAIT(addr)	while ((((addr)->hpds)&HPDS_DRY)==0) DELAY(500);
E 21
I 21
#define	HPWAIT(addr) \
D 36
	while ((((addr)->hpds)&HPDS_DRY)==0) DELAY(500);
E 36
I 36
	while ((((addr)->hpds)&HPDS_DRY) == 0) \
		DELAY(500);
E 36
E 21

E 13
hpopen(io)
	register struct iob *io;
{
	register unit = io->i_unit;
D 36
	struct hpdevice *hpaddr = (struct hpdevice *)mbadrv(unit);
D 2
	register struct hpst *st;
E 2
I 2
D 32
	register struct st *st;
E 32
I 30
	register struct hp_softc *sc = &hp_softc[unit];
I 32
	register struct disklabel *lp = &hplabel[unit];
E 36
I 36
	register struct hp_softc *sc;
	register struct disklabel *lp;
	struct hpdevice *hpaddr;
E 36
I 34
	struct disklabel *dlp;
I 40
	int error = 0;
E 40
E 34
E 32
E 30
E 2

I 41
	/*
	 * Accept adaptor number as either controller or adaptor,
	 * but not both.
	 */
	if (io->i_ctlr) {
		if (io->i_adapt == 0)
			io->i_adapt = io->i_ctlr;
		else
			return (ECTLR);
	}
E 41
D 32
	mbainit(UNITTOMBA(unit));
E 32
I 32
D 35
	if (mbainit(UNITTOMBA(unit)) == 0) {
		printf("nonexistent mba");
E 35
I 35
D 36
	if (mbainit(UNITTOMBA(unit)) == 0)
E 35
		return (ENXIO);
E 36
I 36
	if ((u_int)io->i_adapt >= MAXNMBA || !mbainit(io->i_adapt))
		return (EADAPT);
D 41
	if ((u_int)io->i_ctlr)
		return (ECTLR);
E 41
	if ((u_int)unit >= MAXUNIT)
		return (EUNIT);
	hpaddr = (struct hpdevice *)mbadrv(io->i_adapt, unit);
	sc = &hp_softc[io->i_adapt][unit];
	lp = &hplabel[io->i_adapt][unit];
E 36
D 35
	}
E 35
E 32
D 30
	if (hp_type[unit] == 0) {
E 30
I 30
	if (sc->gottype == 0) {
E 30
D 21
		register type = hpaddr->hpdt & MBDT_TYPE;
		register int i;
E 21
I 21
D 32
		register i, type = hpaddr->hpdt & MBDT_TYPE;
E 32
I 32
D 36
		register i;
E 36
I 36
		register int i;
E 36
E 32
E 21
		struct iob tio;

D 32
		for (i = 0; hptypes[i]; i++)
			if (hptypes[i] == type)
				goto found;
		_stop("unknown drive type");
found:
E 32
I 32
#ifndef SMALL
E 32
I 30
		sc->retries = RETRIES;
		sc->ecclim = 11;
		sc->debug = 0;
I 32
#endif
E 32
E 30
D 14
		switch (i) {
		case 0: case 1:	{	/* rm03 or rm05 */
			register hpsn = hpaddr->hpsn;

			if ((hpsn & SIMB_LU) != unit)
				break;
			switch ((hpsn & SIMB_MB) &~ (SIMB_S6|SIRM03|SIRM05)) {
			case SI9775D:
				i = 8;	/* si9775 */
				break;
			case SI9730D:
				i = 9;	/* si9730 */
				break;
			case SI9766:
				i = 1;	/* rm05 */
				hpaddr->hpcs1 = HP_RECAL|HP_GO;
				DELAY(100000);
				break;
			case SI9762:
				i = 0;	/* rm03 */
				break;
			}
			break;
		}

D 7
		case 11:		/* rm02 */
E 7
I 7
D 12
		case 12:		/* rm02 */
E 12
I 12
		case 13:		/* rm02 */

E 12
E 7
			hpaddr->hpcs1 = HP_NOP;
			hpaddr->hphr = HPHR_MAXTRAK;
I 12
			
E 12
			if (MASKREG(hpaddr->hphr) == 15)
				i = 10;		/* ampex capricorn */
D 12
			else
D 7
				i = 0;		/* rm03 */
E 7
I 7
				i = 11;		/* eagle */
E 12
I 12
			else {
				hpaddr->hphr = HPHR_MAXSECT;
				if (MASKREG(hpaddr->hphr) == 47)
					i = 12;		/* modified eagle */
				else	
					i = 11;		/* eagle */
			}
E 12
E 7
			break;
		
		case 6: case 7:		/* ml11a ml11b */
			i = 6;			/* ml11a */
			break;
		}
		hp_type[unit] = i;
E 14
I 14
D 16
		hp_type[unit] = hpmaptype(hpaddr, i, unit);
E 16
E 14
I 10
		hpaddr->hpcs1 = HP_DCLR|HP_GO;		/* init drive */
		hpaddr->hpcs1 = HP_PRESET|HP_GO;
D 32
		if (!ML11)
E 32
I 32
#ifndef SMALL
D 35
		if ((hpaddr->hpds & HPDS_DPR) == 0)
			_stop("drive nonexistent");
E 35
I 35
D 37
		if ((hpaddr->hpds & HPDS_DPR) == 0) {
D 36
			printf("drive nonexistent\n");
E 36
I 36
			printf("hp: drive nonexistent\n");
E 37
I 37
		if ((hpaddr->hpds & HPDS_DPR) == 0)
E 37
E 36
			return (ENXIO);
D 37
		}
E 37
E 35
		sc->type = hpaddr->hpdt & MBDT_TYPE;
		if (sc->type == MBDT_ML11B)
D 35
			sc->type == MBDT_ML11A;
E 35
I 35
			sc->type = MBDT_ML11A;
E 35
		if (!ML11(sc->type))
#endif
E 32
			hpaddr->hpof = HPOF_FMT22;
I 16
D 26
		hp_type[unit] = hpmaptype(hpaddr, i, unit);
E 26
I 26
D 30
		hp_type[unit] = hpmaptype(hpaddr, i, UNITTODRIVE(unit));
E 30
I 30
D 32
		sc->type = hpmaptype(hpaddr, i, UNITTODRIVE(unit));
E 32
E 30
E 26
E 16
E 10
		/*
D 21
		 * Read in the bad sector table:
		 *	copy the contents of the io structure
		 *	to tio for use during the bb pointer
		 *	read operation.
E 21
I 21
D 32
		 * Read in the bad sector table.
E 32
I 32
		 * Read in the pack label.
E 32
E 21
		 */
D 7
		st = &hpst[hp_type[unit]];
E 7
I 7
D 19
		st = &hpst[i];
E 19
I 19
D 30
		st = &hpst[hp_type[unit]];
E 30
I 30
D 32
		st = &hpst[sc->type];
E 32
I 32
		lp->d_nsectors = 32;
		lp->d_secpercyl = 20*32;
E 32
E 30
E 19
E 7
		tio = *io;
D 32
		tio.i_bn = st->nspc * st->ncyl - st->nsect;
E 32
I 32
		tio.i_bn = LABELSECTOR;
		tio.i_ma = lbuf;
		tio.i_cc = SECTSIZ;
		tio.i_flgs |= F_RDDATA;
D 39
		if (hpstrategy(&tio, READ) != SECTSIZ) {
D 35
			printf("can't read disk label");
E 35
I 35
D 36
			printf("can't read disk label\n");
E 36
I 36
			printf("hp: can't read disk label\n");
E 36
E 35
			return (EIO);
		}
E 39
I 39
		if (hpstrategy(&tio, READ) != SECTSIZ)
D 40
			return (ERDLAB);
E 40
I 40
			error = ERDLAB;
E 40
E 39
D 34
		*lp = *(struct disklabel *)(lbuf + LABELOFFSET);
#ifndef SMALL
		if (lp->d_magic != DISKMAGIC || lp->d_magic2 != DISKMAGIC) {
E 34
I 34
		dlp = (struct disklabel *)(lbuf + LABELOFFSET);
D 39
		if (dlp->d_magic != DISKMAGIC || dlp->d_magic2 != DISKMAGIC) {
E 39
I 39
D 40
		if (dlp->d_magic != DISKMAGIC || dlp->d_magic2 != DISKMAGIC)
E 40
I 40
		if (error == 0 && (dlp->d_magic != DISKMAGIC ||
		    dlp->d_magic2 != DISKMAGIC))
			error = EUNLAB;
		if (error == 0)
			*lp = *dlp;
		else
E 40
#ifdef COMPAT_42
D 40
		{
E 39
E 34
			printf("hp%d: unlabeled\n", unit);
D 34
#ifdef COMPAT_42
E 34
I 34
D 35
#if defined(COMPAT_42) && !defined(SMALL)
E 35
I 35
D 39
#if defined(COMPAT_42) /* && !defined(SMALL) */
E 39
E 35
E 34
D 36
			hpmaptype(hpaddr, hpaddr->hpdt & MBDT_TYPE,
			    UNITTODRIVE(unit), lp);
E 36
I 36
			hpmaptype(hpaddr, hpaddr->hpdt & MBDT_TYPE, unit, lp);
I 39
		}
E 39
E 36
#else
D 39
			return (ENXIO);
E 39
I 39
			return (EUNLAB);
E 40
I 40
		    if (hpmaptype(hpaddr, hpaddr->hpdt & MBDT_TYPE, unit, lp) == 0)
E 40
E 39
#endif
D 34
		}
E 34
I 34
D 39
		} else
E 39
I 39
D 40
		else
E 39
			*lp = *dlp;
E 40
I 40
			return (error);

E 40
#ifndef SMALL
E 34
		/*
		 * Read in the bad sector table.
		 */
		tio.i_bn = lp->d_secpercyl * lp->d_ncylinders - lp->d_nsectors;
E 32
D 7
		tio.i_ma = (char *)&hpbad[tio.i_unit];
E 7
I 7
D 36
		tio.i_ma = (char *)&hpbad[unit];
E 7
D 8
		tio.i_cc = sizeof (hpbad);
E 8
I 8
		tio.i_cc = sizeof (struct dkbad);
E 36
I 36
		tio.i_ma = (char *)&hpbad[io->i_adapt][unit];
		tio.i_cc = sizeof(struct dkbad);
E 36
E 8
D 32
		tio.i_flgs |= F_RDDATA;
E 32
		for (i = 0; i < 5; i++) {
D 8
			if (hpstrategy(&tio, READ) == sizeof (hpbad))
E 8
I 8
D 36
			if (hpstrategy(&tio, READ) == sizeof (struct dkbad))
E 36
I 36
			if (hpstrategy(&tio, READ) == sizeof(struct dkbad))
E 36
E 8
				break;
			tio.i_bn += 2;
		}
		if (i == 5) {
D 35
			printf("Unable to read bad sector table\n");
E 35
I 35
D 36
			printf("can't read bad sector table\n");
E 36
I 36
			printf("hp: can't read bad sector table\n");
E 36
E 35
			for (i = 0; i < MAXBADDESC; i++) {
D 36
				hpbad[unit].bt_bad[i].bt_cyl = -1;
				hpbad[unit].bt_bad[i].bt_trksec = -1;
E 36
I 36
				hpbad[io->i_adapt][unit].bt_bad[i].bt_cyl = -1;
				hpbad[io->i_adapt][unit].bt_bad[i].bt_trksec = -1;
E 36
			}
D 30
		}	
E 30
I 30
		}
D 34
		sc->gottype = 1;
E 34
I 32
#endif
I 34
		sc->gottype = 1;
E 34
E 32
E 30
	}
I 25
D 30
	st = &hpst[hp_type[unit]];
E 30
I 30
D 32
	st = &hpst[sc->type];
E 30
E 25
	if (io->i_boff < 0 || io->i_boff > 7 ||
	    st->off[io->i_boff]== -1)
		_stop("hp bad minor");
	io->i_boff = st->off[io->i_boff] * st->nspc;
E 32
I 32
D 35
	if (io->i_boff < 0 || io->i_boff >= lp->d_npartitions ||
E 35
I 35
D 36
	if ((unsigned)io->i_boff >= lp->d_npartitions ||
E 35
	    lp->d_partitions[io->i_boff].p_size == 0) {
D 35
		printf("hp bad minor");
E 35
I 35
		printf("hp bad minor\n");
E 35
		return (EUNIT);
	}
	io->i_boff = lp->d_partitions[io->i_boff].p_offset;
E 36
I 36
	if (io->i_part >= lp->d_npartitions ||
	    lp->d_partitions[io->i_part].p_size == 0)
		return (EPART);
	io->i_boff = lp->d_partitions[io->i_part].p_offset;
E 36
	return (0);
E 32
}

I 14
D 19
hpmaptype(hpaddr, type, unit)
	register struct hpdevice *hpaddr;
	unsigned type;
	int unit;
{
	int ntracks, hpsn;

	/*
	 * Handle SI model byte stuff when
	 * we think it's an RM03 or RM05.
	 */
	if (type == 0 || type == 1) {
		hpsn = hpaddr->hpsn;
		if ((hpsn & SIMB_LU) != unit)
			return (type);
		switch ((hpsn & SIMB_MB) &~ (SIMB_S6|SIRM03|SIRM05)) {
		case SI9775D:
			return (8);
		case SI9730D:
			return (9);
		case SI9766:
			hpaddr->hpcs1 = HP_RECAL|HP_GO;
			DELAY(100000);
			return (1);

		case SI9762:
			return (0);
		}
		return (type);
	}
	/*
	 * RM03: EMULEX controller.  Map to correct
	 * drive type by checking the holding
	 * register for the disk geometry.
	 */
	if (type == 13) {
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXTRAK;
		ntracks = MASKREG(hpaddr->hphr) + 1;
		if (ntracks == 16)
			return (10);	/* AMPEX capricorn */
		hpaddr->hphr = HPHR_MAXSECT;
I 16
		ntracks = MASKREG(hpaddr->hphr) + 1;
E 16
		if (ntracks == 48)
			return (12);	/* 48 sector Eagle */
		if (ntracks == 43)
			return (11);	/* 43 sector Eagle */
D 17
		printf("RM02 with %d tracks?\n", ntracks);
E 17
I 17
		printf("RM02 with %d sectors/track?\n", ntracks);
E 17
		return (type);
	}
	/*
	 * ML11's all map to the same type.
	 */
	if (type == 6 || type == 7)
		return (6);
	return (type);
}

E 19
E 14
I 10
D 21
int	ssect;		/* set to 1 if we are on a track with skip sectors */

E 21
E 10
hpstrategy(io, func)
	register struct iob *io;
{
D 36
	register unit = io->i_unit;
	struct mba_regs *mba = mbamba(unit);
E 36
I 36
	register int unit = io->i_unit;
	register struct hp_softc *sc;
	register struct disklabel *lp;
	struct mba_regs *mba;
	struct hpdevice *hpaddr;
E 36
D 21
	daddr_t bn;
E 21
I 21
	daddr_t bn, startblock;
E 21
D 36
	struct hpdevice *hpaddr = (struct hpdevice *)mbadrv(unit);
D 2
	struct hpst *st = &hpst[hp_type[unit]];
E 2
I 2
D 30
	struct st *st = &hpst[hp_type[unit]];
E 2
	int cn, tn, sn, bytecnt, bytesleft; 
E 30
I 30
	register struct hp_softc *sc = &hp_softc[unit];
D 32
	struct st *st = &hpst[sc->type];
E 32
I 32
	register struct disklabel *lp = &hplabel[unit];
E 36
E 32
D 35
	int cn, tn, sn, bytecnt, bytesleft, rv; 
E 35
I 35
	int cn, tn, sn, bytecnt, bytesleft, rv;
E 35
E 30
D 21
	daddr_t startblock;
E 21
D 36
	char *membase;
E 36
	int er1, er2, hprecal;
I 36
	char *membase;
E 36

I 36
	mba = mbamba(io->i_adapt);
	hpaddr = (struct hpdevice *)mbadrv(io->i_adapt, unit);
	sc = &hp_softc[io->i_adapt][unit];
	lp = &hplabel[io->i_adapt][unit];
E 36
I 32
#ifndef SMALL
E 32
	sectsiz = SECTSIZ;
	if ((io->i_flgs & (F_HDR|F_HCHECK)) != 0)
		sectsiz += HDRSIZ;
	if ((hpaddr->hpds & HPDS_VV) == 0) {
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
		hpaddr->hpcs1 = HP_PRESET|HP_GO;
D 10
		if (hp_type[unit] != 6)		/* any but ml11 */
E 10
I 10
D 14
		if (!ML11)			/* any but ml11 */
E 14
I 14
D 32
		if (!ML11)
E 32
I 32
		if (!ML11(sc->type))
E 32
E 14
E 10
			hpaddr->hpof = HPOF_FMT22;
	}
	io->i_errcnt = 0;
I 10
D 21
	ssect = 0;
E 21
I 21
D 30
	ssect[unit] = 0;
E 21
E 10
	bytecnt = io->i_cc;
E 30
I 30
	sc->ssect = 0;
	rv = bytecnt = io->i_cc;
E 30
	membase = io->i_ma;
	startblock = io->i_bn;
D 5
	hprecal = 1;
E 5
I 5
	hprecal = 0;
I 32
#endif
E 32
I 19

E 19
E 5
D 7
readmore:
E 7
I 7
restart:
E 7
	bn = io->i_bn;
D 32
	cn = bn/st->nspc;
	sn = bn%st->nspc;
	tn = sn/st->nsect;
D 10
	sn = sn%st->nsect;
E 10
I 10
D 21
	sn = sn%st->nsect + ssect;
E 21
I 21
D 30
	sn = sn%st->nsect + ssect[unit];
E 30
I 30
	sn = sn%st->nsect + sc->ssect;
E 32
I 32
	cn = bn / lp->d_secpercyl;
	sn = bn % lp->d_secpercyl;
	tn = sn / lp->d_nsectors;
	sn = sn % lp->d_nsectors + sc->ssect;
E 32
E 30
E 21
E 10

D 13
	while ((hpaddr->hpds & HPDS_DRY) == 0)
		;
E 13
I 13
	HPWAIT(hpaddr);
E 13
I 7
	mba->mba_sr = -1;
E 7
D 10
	if (hp_type[unit] == 6)		/* ml11 */
E 10
I 10
D 32
	if (ML11)
E 32
I 32
	if (ML11(sc->type))
E 32
E 10
		hpaddr->hpda = bn;
	else {
		hpaddr->hpdc = cn;
		hpaddr->hpda = (tn << 8) + sn;
	}
I 32
#ifdef SMALL
D 36
	mbastart(io, func);			/* start transfer */
E 36
I 36
	mbastart(io, io->i_unit, func);		/* start transfer */
E 36
	HPWAIT(hpaddr);
	if (hpaddr->hpds & HPDS_ERR) {
		printf("hp error: sn [%d-%d) ds=%b er1=%b\n",
		    bn, bn + io->i_cc/SECTSIZ, MASKREG(hpaddr->hpds), HPDS_BITS,
		    MASKREG(hpaddr->hper1), HPER1_BITS);
		return (-1);
	}
	return (io->i_cc);
#else
E 32
D 30
	if (mbastart(io, func) != 0)		/* start transfer */
		return (-1);
E 30
I 30
D 36
	if (mbastart(io, func) != 0) {		/* start transfer */
E 36
I 36
	if (mbastart(io, io->i_unit, func) != 0) {	/* start transfer */
E 36
		rv = -1;
		goto done;
	}
E 30
D 13

	while ((hpaddr->hpds & HPDS_DRY) == 0)
		;
E 13
I 13
	HPWAIT(hpaddr);
I 21
	/*
	 * Successful data transfer, return.
	 */
E 21
E 13
D 14
	if (((hpaddr->hpds&HPDS_ERR) | (mba->mba_sr&MBSR_EBITS)) == 0 )
		return(bytecnt);
E 14
I 14
D 23
	if ((hpaddr->hpds&HPDS_ERR) == 0 && (mba->mba_sr&MBSR_EBITS) == 0)
E 23
I 23
D 24
	if ((hpaddr->hpds&HPDS_ERR) == 0 && (mba->mba_sr&MBSR_EBITS) == 0) {
		if (io->i_errcnt >= 16) {
			hpaddr->hpcs1 = HP_RTC|HP_GO;
			while (hpaddr->hpds & HPDS_PIP)
				;
		}
E 23
		return (bytecnt);
I 23
	}
E 24
I 24
	if ((hpaddr->hpds&HPDS_ERR) == 0 && (mba->mba_sr&MBSR_EBITS) == 0)
		goto done;
E 24
E 23
E 14

D 21
	/* ------- error handling ------- */

	if (bytesleft = MASKREG(mba->mba_bcr>>16)) 
		bytesleft |= 0xffff0000;	/* sign ext */
	bn = io->i_bn + (io->i_cc + bytesleft)/sectsiz;
E 21
I 21
	/*
	 * Error handling.  Calculate location of error.
	 */
	bytesleft = MASKREG(mba->mba_bcr);
	if (bytesleft) 
		bytesleft |= 0xffff0000;	/* sxt */
	bn = io->i_bn + (io->i_cc + bytesleft) / sectsiz;
I 23
	er1 = MASKREG(hpaddr->hper1);
	er2 = MASKREG(hpaddr->hper2);
	if (er1 & (HPER1_DCK|HPER1_ECH))
		bn--;	/* Error is in Prev block */
E 23
E 21
D 32
	cn = bn/st->nspc;
	sn = bn%st->nspc;
	tn = sn/st->nsect;
	sn = sn%st->nsect;
E 32
I 32
	cn = bn/lp->d_secpercyl;
	sn = bn%lp->d_secpercyl;
	tn = sn/lp->d_nsectors;
	sn = sn%lp->d_nsectors;
E 32
D 23
	er1 = MASKREG(hpaddr->hper1);
	er2 = MASKREG(hpaddr->hper2);
E 23
D 21
#ifdef HPDEBUG
	printf("hp error: (cyl,trk,sec)=(%d,%d,%d) ds=%b \n",
		cn, tn, sn, MASKREG(hpaddr->hpds), HPDS_BITS);
D 7
	printf("er1=%b er2=%b",
		er1, HPER1_BITS,
		er2, HPER2_BITS);
E 7
I 7
	printf("er1=%b er2=%b", er1, HPER1_BITS, er2, HPER2_BITS);
	printf("\nbytes left: %d, of 0x%x, da 0x%x",-bytesleft,
	hpaddr->hpof, hpaddr->hpda);
E 7
	printf("\n");
#endif
E 21
I 21
D 30
	if (hpdebug[unit] & (HPF_ECCDEBUG|HPF_BSEDEBUG)) {
		printf("hp error: (cyl,trk,sec)=(%d,%d,%d) ds=%b\n",
			cn, tn, sn, MASKREG(hpaddr->hpds), HPDS_BITS);
E 30
I 30
	if (sc->debug & (HPF_ECCDEBUG|HPF_BSEDEBUG)) {
		printf("hp error: sn%d (cyl,trk,sec)=(%d,%d,%d) ds=%b\n",
			bn, cn, tn, sn, MASKREG(hpaddr->hpds), HPDS_BITS);
E 30
		printf("er1=%b er2=%b\n", er1, HPER1_BITS, er2, HPER2_BITS);
		printf("bytes left: %d, of 0x%x, da 0x%x\n",-bytesleft,
			hpaddr->hpof, hpaddr->hpda);
	}
E 21
	if (er1 & HPER1_HCRC) {
		er1 &= ~(HPER1_HCE|HPER1_FER);
		er2 &= ~HPER2_BSE;
I 30
		if ((io->i_flgs&F_NBSF) == 0 && hpecc(io, BSE) == 0)
			goto success;
E 30
	}
I 19
	/*
	 * Give up early if drive write locked.
	 */
E 19
	if (er1&HPER1_WLE) {
		printf("hp%d: write locked\n", unit);
D 14
		return(-1);
D 7
	} else if ((er1&0xffff) == HPER1_FER && RP06) {
E 7
I 7
	} else if (MASKREG(er1) == HPER1_FER && RP06) {
E 14
I 14
D 30
		return (-1);
E 30
I 30
		rv = -1;
		goto done;
E 30
	}
I 19
	/*
D 21
	 * No bad sector handling on RP06's yet.
E 21
I 21
D 30
	 * Interpret format error bit as a bad block on RP06's.
E 30
I 30
	 * Skip sector handling.
E 30
E 21
	 */
E 19
D 30
	if (MASKREG(er1) == HPER1_FER && RP06)
E 14
E 7
		goto badsect;
I 19

	/*
	 * If a hard error, or maximum retry count
	 * exceeded, clear controller state and
	 * pass back error to caller.
	 */
E 19
D 14

	} else if (++io->i_errcnt > 27 ||
		   er1 & HPER1_HARD ||
		   (!ML11 && (er2 & HPER2_HARD))) {
E 14
I 14
	if (++io->i_errcnt > 27 || (er1 & HPER1_HARD) ||
	    (!ML11 && (er2 & HPER2_HARD))) {
I 20
D 23
		if ((io->i_flgs&F_NBSF) == 0 && hpecc(io, BSE) == 0)
			goto success;
E 23
I 23
		/*
		 * The last ditch effort to bad sector forward
		 * below will probably fail since mba byte ctr
		 * (bcr) is different for BSE and ECC errors and
		 * the wrong block will be revectored to if one
		 * has 2 contiguous bad blocks and reads the second.
		 * For now, we can probably just let a header CRC
		 * error be handled like a BSE since no data will
		 * have been transferred and the bcr should the same
		 * as it would with a BSE error.
		 * --ghg.
		 */
		if (er1 & HPER1_HCRC) 
			if ((io->i_flgs&F_NBSF) == 0 && hpecc(io, BSE) == 0)
				goto success;
E 23
E 20
E 14
I 5
hard0:
E 5
		io->i_error = EHER;
D 14
		if ((mba->mba_sr & (MBSR_WCKUP | MBSR_WCKLWR)) != 0)
E 14
I 14
		if (mba->mba_sr & (MBSR_WCKUP|MBSR_WCKLWR))
E 14
			io->i_error = EWCK;
hard:
D 10
		io->i_errblk = bn;
E 10
I 10
D 21
		io->i_errblk = bn + ssect;
E 21
I 21
		io->i_errblk = bn + ssect[unit];
E 21
E 10
		printf("hp error: (cyl,trk,sec)=(%d,%d,%d) ds=%b \n",
			   cn, tn, sn, MASKREG(hpaddr->hpds), HPDS_BITS);
D 14
		printf("er1=%b er2=%b",
			   er1, HPER1_BITS,
			   er2, HPER2_BITS);
E 14
I 14
		printf("er1=%b er2=%b", er1, HPER1_BITS, er2, HPER2_BITS);
E 14
		if (hpaddr->hpmr)
D 7
			printf(" mr=%o", hpaddr->hpmr&0xffff);
E 7
I 7
			printf(" mr1=%o", MASKREG(hpaddr->hpmr));
E 7
		if (hpaddr->hpmr2)
D 7
			printf(" mr2=%o", hpaddr->hpmr2&0xffff);
E 7
I 7
			printf(" mr2=%o", MASKREG(hpaddr->hpmr2));
D 21
#ifdef HPDEBUG
		printf("dc: %d, da: 0x%x",MASKREG(hpaddr->hpdc),
D 14
					  MASKREG(hpaddr->hpda));
E 14
I 14
		  MASKREG(hpaddr->hpda));
E 14
#endif
E 21
I 21
		if (hpdebug[unit] & (HPF_BSEDEBUG|HPF_ECCDEBUG))
			printf(" dc=%d, da=0x%x",MASKREG(hpaddr->hpdc),
			  MASKREG(hpaddr->hpda));
E 21
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
E 7
		printf("\n");
D 14
		return(-1);
E 14
I 14
D 24
		return (-1);
E 24
I 24
		bytecnt = -1;
		goto done;
E 24
E 14

E 30
I 30
D 32
	if (RM80 && (er2 & HPER2_SSE)) {
E 32
I 32
	if (RM80(sc->type) && (er2 & HPER2_SSE)) {
E 32
		(void) hpecc(io, SSE);
		sc->ssect = 1;
		goto restart;
E 30
D 14
	} else if ((er2 & HPER2_BSE) && !ML11) {
E 14
I 14
	}
I 19
	/*
D 30
	 * Attempt to forward bad sectors on
D 28
	 * anything but an ML11.  If drive
	 * supports skip sector handling, try to
	 * use it first; otherwise try the
	 * bad sector table.
E 28
I 28
	 * anything but an ML11.
E 30
I 30
	 * Attempt to forward bad sectors on anything but an ML11.
	 * Interpret format error bit as a bad block on RP06's.
E 30
E 28
	 */
E 19
D 30
	if ((er2 & HPER2_BSE) && !ML11) {
E 14
badsect:
I 10
D 21
		if (!ssect && (er2&HPER2_SSE))
E 21
I 21
		if (!ssect[unit] && (er2&HPER2_SSE))
E 21
			goto skipsect;
E 30
I 30
D 32
	if (((er2 & HPER2_BSE) && !ML11) ||
	    (MASKREG(er1) == HPER1_FER && RP06)) {
E 32
I 32
	if (((er2 & HPER2_BSE) && !ML11(sc->type)) ||
	    (MASKREG(er1) == HPER1_FER && RP06(sc->type))) {
E 32
E 30
E 10
D 14
		if ((io->i_flgs & F_NBSF) != 0) {
E 14
I 14
		if (io->i_flgs & F_NBSF) {
E 14
D 36
			io->i_error = EBSE;	
E 36
I 36
			io->i_error = EBSE;
E 36
			goto hard;
		}
		if (hpecc(io, BSE) == 0)
			goto success;
D 14
		else {
			io->i_error = EBSE;
			goto hard;
		}
D 7
	} else if (RM80 && er2&HPER2_SSE) {
E 7
I 7
D 10
	} else if ((RM80||EAGLE) && er2&HPER2_SSE) {
E 10
I 10
	} else if (RM80 && er2&HPER2_SSE) {
E 14
I 14
		io->i_error = EBSE;
		goto hard;
	}
I 19
D 28

E 28
	/*
D 30
	 * Skip sector handling.
	 */
E 19
D 21
	if (RM80 && er2&HPER2_SSE) {
E 21
I 21
	if (RM80 && (er2 & HPER2_SSE)) {
E 21
E 14
skipsect:
E 10
E 7
D 14
	/* skip sector error */
E 14
		(void) hpecc(io, SSE);
I 4
D 10
		startblock++;		/* since one sector was skipped */
E 10
I 10
D 14
		ssect=1;
E 14
I 14
D 21
		ssect = 1;
E 21
I 21
		ssect[unit] = 1;
E 21
E 14
E 10
E 4
D 28
		goto success;
E 28
I 28
		goto restart;
E 28
D 14
	} else if ((er1&(HPER1_DCK|HPER1_ECH))==HPER1_DCK) {
E 14
I 14
	}
I 19
	/*
E 30
D 21
	 * ECC correction.
E 21
I 21
	 * ECC correction?
E 21
	 */
E 19
	if ((er1 & (HPER1_DCK|HPER1_ECH)) == HPER1_DCK) {
E 14
D 13
		if ( hpecc(io, ECC) == 0)
E 13
I 13
		if (hpecc(io, ECC) == 0)
E 13
			goto success;
D 14
		else {
			io->i_error = EECC;
			return(1);	
		}
E 14
I 14
		io->i_error = EECC;
I 23
D 30
		io->i_errblk = bn + ssect[unit];
E 23
		return (-1);	
E 14
D 5
	} else
		io->i_active = 0;		/* force retry */
E 5
I 5
	} 
I 23
#ifdef F_SEVRE
	if (io->i_flgs & F_SEVRE)
E 30
		goto hard;
D 30
#endif
E 23
E 5
D 14

E 14
I 5
	if (ML11 && (io->i_errcnt >= 16))
D 14
			goto hard0;

E 14
I 14
		goto hard0;
E 30
I 30
	} 

	/*
	 * If a hard error, or maximum retry count
	 * exceeded, clear controller state and
	 * pass back error to caller.
	 */
	if (++io->i_errcnt > sc->retries || (er1 & HPER1_HARD) ||
D 32
	    (!ML11 && (er2 & HPER2_HARD)) || (ML11 && (io->i_errcnt >= 16))) {
E 32
I 32
	    (!ML11(sc->type) && (er2 & HPER2_HARD)) ||
	    (ML11(sc->type) && (io->i_errcnt >= 16))) {
E 32
		io->i_error = EHER;
		if (mba->mba_sr & (MBSR_WCKUP|MBSR_WCKLWR))
			io->i_error = EWCK;
hard:
		io->i_errblk = bn + sc->ssect;
		if (sc->debug & (HPF_BSEDEBUG|HPF_ECCDEBUG))
		    printf(" dc=%d, da=0x%x",MASKREG(hpaddr->hpdc),
			  MASKREG(hpaddr->hpda));
		else {
		    printf("hp error: sn%d (cyl,trk,sec)=(%d,%d,%d) ds=%b \n",
			   bn, cn, tn, sn, MASKREG(hpaddr->hpds), HPDS_BITS);
		    printf("er1=%b er2=%b", er1, HPER1_BITS, er2, HPER2_BITS);
		}
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
		printf("\n");
		rv = -1;
		goto done;

	}
E 30
E 14
	/* fall thru to retry */
D 14

E 14
E 5
	hpaddr->hpcs1 = HP_DCLR|HP_GO;
D 13
	while ((hpaddr->hpds & HPDS_DRY) == 0)
		;
E 13
I 13
	HPWAIT(hpaddr);
I 19

	/* 
	 * Every fourth retry recalibrate.
	 */
E 19
E 13
D 5
	if (ML11) {
		if (io->i_errcnt >= 16)
			goto hard;
	} else if (((io->i_errcnt&07) == 4) && (io->i_active == 0)) {
E 5
I 5
D 21
	if (((io->i_errcnt&07) == 4) ) {
E 21
I 21
	if (((io->i_errcnt & 07) == 4) ) {
E 21
E 5
		hpaddr->hpcs1 = HP_RECAL|HP_GO;
D 5
		hprecal = 0;
		goto nextrecal;
E 5
I 5
D 23
		hprecal = 1;
D 14
		goto try_again;
E 14
I 14
		goto again;
E 14
E 5
	}
I 19

	/*
	 * Recalibration state machine.
	 */
E 19
	switch (hprecal) {

	case 1:
E 23
I 23
		HPWAIT(hpaddr);
E 23
		hpaddr->hpdc = cn;
		hpaddr->hpcs1 = HP_SEEK|HP_GO;
D 5
		goto nextrecal;
E 5
I 5
D 14
		hprecal++;
		goto try_again;
E 14
I 14
D 23
		hprecal = 2;
		goto again;
E 23
I 23
		HPWAIT(hpaddr);
	}
E 23
E 14
I 13

E 13
E 5
D 23
	case 2:
D 5
		if (io->i_errcnt < 16 || (func & READ) == 0)
E 5
I 5
		if (io->i_errcnt < 16 || (io->i_flgs & F_READ) == 0)
E 5
			goto donerecal;
E 23
I 23
	if (io->i_errcnt >= 16 && (io->i_flgs & F_READ)) {
E 23
		hpaddr->hpof = hp_offset[io->i_errcnt & 017]|HPOF_FMT22;
		hpaddr->hpcs1 = HP_OFFSET|HP_GO;
D 5
nextrecal:
E 5
D 14
		hprecal++;
D 5
		io->i_active = 1;
E 5
		goto try_again;
E 14
I 14
D 23
		hprecal = 3;
		goto again;
E 14
I 13

E 13
D 14
	donerecal:
E 14
	case 3:
I 14
	donerecal:
E 14
		hprecal = 0;
D 5
		io->i_active = 0;
E 5
D 14
		goto try_again;
E 14
I 14
		goto again;
E 23
I 23
		HPWAIT(hpaddr);
E 23
E 14
	}
D 5
	if (io->i_active) {
		if (io->i_errcnt >= 16) {
			hpaddr->hpcs1 = HP_RTC|HP_GO;
			while (hpaddr->hpds & HPDS_PIP)
				;
		}
E 5
I 5
D 23
	if (io->i_errcnt >= 16) {
		hpaddr->hpcs1 = HP_RTC|HP_GO;
		while (hpaddr->hpds & HPDS_PIP)
			;
E 5
	}
I 5
D 14
	goto try_again;
E 5
success:		 /* continue with the next block */
E 14
I 14
	goto again;
E 23
I 23
D 30
	if (hpdebug[unit] & (HPF_ECCDEBUG|HPF_BSEDEBUG))
E 30
I 30
	if (sc->debug & (HPF_ECCDEBUG|HPF_BSEDEBUG))
E 30
		printf("restart: bn=%d, cc=%d, ma=0x%x hprecal=%d\n",
		  io->i_bn, io->i_cc, io->i_ma, hprecal);
D 30
	goto restart;	/* retry whole transfer  --ghg */
E 30
I 30
	goto restart;
E 30
E 23

D 19
success:		 		/* continue with the next block */
E 19
I 19
success:
	/*
	 * On successful error recovery, bump
	 * block number to advance to next portion
	 * of i/o transfer.
	 */
E 19
E 14
	bn++;
	if ((bn-startblock) * sectsiz < bytecnt) {
D 14

try_again:		/* re-read same block */
E 14
I 14
D 19
again:					/* re-read same block */
E 19
I 19
D 23
again:
E 23
E 19
E 14
		io->i_bn = bn;
D 7
		mba->mba_sr = -1;
E 7
		io->i_ma = membase + (io->i_bn - startblock)*sectsiz;
		io->i_cc = bytecnt - (io->i_bn - startblock)*sectsiz;
D 21
#ifdef HPDEBUG
D 5
		printf("restart: bl %d, byte %d, mem 0x%x %d\n",
			io->i_bn, io->i_cc, io->i_ma, io->i_ma);
E 5
I 5
		printf("restart: bl %d, byte %d, mem 0x%x hprecal %d\n",
			io->i_bn, io->i_cc, io->i_ma, hprecal);
E 5
#endif
E 21
I 21
D 30
		if (hpdebug[unit] & (HPF_ECCDEBUG|HPF_BSEDEBUG))
E 30
I 30
		if (sc->debug & (HPF_ECCDEBUG|HPF_BSEDEBUG))
E 30
			printf("restart: bn=%d, cc=%d, ma=0x%x hprecal=%d\n",
			  io->i_bn, io->i_cc, io->i_ma, hprecal);
E 21
D 7
		goto readmore;
E 7
I 7
		goto restart;
E 7
	}
I 24
done:
E 24
I 23
	if (io->i_errcnt >= 16) {
		hpaddr->hpcs1 = HP_RTC|HP_GO;
		while (hpaddr->hpds & HPDS_PIP)
			;
	}
I 30
	io->i_bn = startblock;		/*reset i_bn to original */
E 30
I 28
	io->i_cc = bytecnt;		/*reset i_cc to total count xfered*/
E 28
E 23
D 30
	return (bytecnt);
E 30
I 30
	io->i_ma = membase;		/*reset i_ma to original */
	return (rv);
I 32
#endif
E 32
E 30
}
I 13

I 32
#ifndef SMALL
E 32
E 13
hpecc(io, flag)
	register struct iob *io;
	int flag;
{
D 36
	register unit = io->i_unit;
	register struct mba_regs *mbp = mbamba(unit);
	register struct hpdevice *rp = (struct hpdevice *)mbadrv(unit);
D 2
	register struct hpst *st = &hpst[hp_type[unit]];
E 2
I 2
D 30
	register struct st *st = &hpst[hp_type[unit]];
E 30
I 30
	register struct hp_softc *sc = &hp_softc[unit];
D 32
	register struct st *st = &hpst[sc->type];
E 32
I 32
	register struct disklabel *lp = &hplabel[unit];
E 36
I 36
	register int unit = io->i_unit;
	register struct mba_regs *mbp;
	register struct hpdevice *rp;
	register struct hp_softc *sc;
	register struct disklabel *lp;
E 36
E 32
E 30
E 2
D 14
	int npf;
	int bn, cn, tn, sn;
D 7
	int bcr, tad;
E 7
I 7
	int bcr;
E 14
I 14
	int npf, bn, cn, tn, sn, bcr;
E 14
E 7

I 36
	mbp = mbamba(io->i_adapt);
	rp = (struct hpdevice *)mbadrv(io->i_adapt, unit);
	sc = &hp_softc[io->i_adapt][unit];
	lp = &hplabel[io->i_adapt][unit];
E 36
D 21
	if (bcr = MASKREG(mbp->mba_bcr>>16))
D 20
		bcr |= 0xffff0000;		/* sxt */
E 20
I 20
		bcr |= 0xffff0000;		/* sign extend */
E 21
I 21
	bcr = MASKREG(mbp->mba_bcr);
	if (bcr)
		bcr |= 0xffff0000;		/* sxt */
E 21
E 20
D 14
	npf = (bcr + io->i_cc)/sectsiz;		/* number of sectors read */
I 4
D 10
	bn = io->i_bn + npf;
E 10
I 10
	bn = io->i_bn + npf + ssect;		/* bn is physical block number*/
E 14
I 14
	npf = (bcr + io->i_cc) / sectsiz;	/* # sectors read */
I 23
	if (flag == ECC)
		npf--;		/* Error is in prev block --ghg */
E 23
D 21
	bn = io->i_bn + npf + ssect;		/* physical block #*/
I 20
#ifdef HPECCDEBUG
	printf("bcr %d npf %d ssect %d sectsiz %d i_cc %d\n", bcr, npf,
		ssect, sectsiz, io->i_cc);
#endif
E 20
E 14
E 10
E 4
D 19
	switch (flag) {
E 19
I 14

E 21
I 21
D 30
	bn = io->i_bn + npf + ssect[unit];	/* physical block #*/
	if (hpdebug[unit]&HPF_ECCDEBUG)
E 30
I 30
	bn = io->i_bn + npf + sc->ssect;	/* physical block #*/
	if (sc->debug & HPF_ECCDEBUG)
E 30
		printf("bcr=%d npf=%d ssect=%d sectsiz=%d i_cc=%d\n",
D 30
			bcr, npf, ssect[unit], sectsiz, io->i_cc);
E 30
I 30
			bcr, npf, sc->ssect, sectsiz, io->i_cc);
E 30
E 21
E 14
D 13
	case ECC:
		{
E 13
I 13
D 19
	case ECC: {
E 19
I 19
	/*
	 * ECC correction logic.
	 */
	if (flag == ECC) {
E 19
E 13
		register int i;
		caddr_t addr;
D 20
		int bit, byte, mask, ecccnt = 0;
E 20
I 20
D 30
		int bit, o, mask, ecccnt = 0;
E 30
I 30
		int bit, o, mask;
E 30
E 20

D 4
		printf("hp%d: soft ecc sn%d\n", unit, io->i_bn + npf);
E 4
I 4
		printf("hp%d: soft ecc sn%d\n", unit, bn);
E 4
		mask = MASKREG(rp->hpec2);
I 30
		for (i = mask, bit = 0; i; i >>= 1)
			if (i & 1)
				bit++;
		if (bit > sc->ecclim) {
			printf("%d-bit error\n", bit);
			return (1);
		}
E 30
D 14
		i = MASKREG(rp->hpec1) - 1;		/* -1 makes 0 origin */
E 14
I 14
		i = MASKREG(rp->hpec1) - 1;	/* -1 makes 0 origin */
E 14
		bit = i&07;
D 20
		i = (i&~07)>>3;
		byte = i;
E 20
I 20
D 21
		o = (i&~07) >> 3;
E 21
I 21
		o = (i & ~07) >> 3;
E 21
E 20
		rp->hpcs1 = HP_DCLR | HP_GO;
D 20
		while (i <sectsiz && npf*sectsiz + i < io->i_cc && bit > -11) {
			addr = io->i_ma + (npf*sectsiz) + byte;
E 20
I 20
		while (o <sectsiz && npf*sectsiz + o < io->i_cc && bit > -11) {
			addr = io->i_ma + (npf*sectsiz) + o;
E 20
D 21
#ifdef HPECCDEBUG
			printf("addr %x old:%x ",addr, (*addr&0xff));
#endif
E 21
I 19
D 20
			/* don't correct in-core copy during wcheck */
E 20
I 20
			/*
			 * No data transfer occurs with a write check,
			 * so don't correct the resident copy of data.
			 */
E 20
E 19
D 21
			if ((io->i_flgs & (F_CHECK|F_HCHECK)) == 0)
E 21
I 21
			if ((io->i_flgs & (F_CHECK|F_HCHECK)) == 0) {
D 30
				if (hpdebug[unit] & HPF_ECCDEBUG)
E 30
I 30
				if (sc->debug & HPF_ECCDEBUG)
E 30
					printf("addr=%x old=%x ", addr,
						(*addr & 0xff));
E 21
D 19
				*addr ^= (mask << bit);	/* don't 'correct' mem-
							 * ory during Wcheck */
E 19
I 19
				*addr ^= (mask << bit);
E 19
D 21
#ifdef HPECCDEBUG
			printf("new:%x\n",(*addr&0xff));
#endif
E 21
I 21
D 30
				if (hpdebug[unit] & HPF_ECCDEBUG)
E 30
I 30
				if (sc->debug & HPF_ECCDEBUG)
E 30
					printf("new=%x\n",(*addr & 0xff));
			}
E 21
D 19
			byte++;
			i++;
E 19
I 19
D 20
			byte++, i++;
E 19
			bit -= 8;
E 20
I 20
			o++, bit -= 8;
E 20
D 14
			if ((ecccnt++>=MAXECC) && ((io->i_flgs&F_ECCLM) != 0))
				return(1);
E 14
I 14
D 15
			if ((io->i_flgs & F_ECCLIM) && ecccnt++ >= MAXECC)
E 15
I 15
D 30
			if ((io->i_flgs & F_ECCLM) && ecccnt++ >= MAXECC)
E 15
				return (1);
E 30
E 14
		}
I 23
D 30
#ifdef F_SEVRE
		if (io->i_flgs & F_SEVRE)
			return(1);
#endif
E 30
E 23
D 20
		return(0);
E 20
I 20
		return (0);
E 20
D 14
		}
E 14
I 14
	}
E 14

D 4
	case SSE:		/* skip sector error */
				/* -----this section must be fixed------*/
E 4
I 4
D 14
	case SSE:	/* skip sector error */
			/* set skip-sector-inhibit and read next sector */
E 14
I 14
	/*
	 * Skip sector error.
	 * Set skip-sector-inhibit and
	 * read next sector
	 */
D 19
	case SSE:
E 19
I 19
	if (flag == SSE) {
E 19
E 14
E 4
		rp->hpcs1 = HP_DCLR | HP_GO;
I 4
D 13
		while(rp->hpds & HPDS_DRY == 0)
			;			/* avoid RMR error */
E 13
I 13
		HPWAIT(rp);
E 13
E 4
		rp->hpof |= HPOF_SSEI;
D 4
		mbp->mba_bcr = -(io->i_cc - npf*sectsiz);
		/* presumably the disk address has already
		 * been incremented to point to the next sector	*/
E 4
D 14
		return(0);	
E 14
I 14
D 36
		return (0);	
E 36
I 36
		return (0);
E 36
I 19
	}
E 19
E 14

D 14
#ifndef NOBADSECT
E 14
D 13
	case BSE:
I 7
		{
E 13
I 13
D 19
	case BSE: {
E 19
I 19
	/*
	 * Bad block forwarding.
	 */
	 if (flag == BSE) {
E 19
E 13
		int bbn;
I 14

E 14
		rp->hpcs1 = HP_DCLR | HP_GO;
E 7
D 21
#ifdef HPDEBUG
		printf("hpecc: BSE @ bn %d\n", bn);
#endif
E 21
I 21
D 30
		if (hpdebug[unit] & HPF_BSEDEBUG)
E 30
I 30
		if (sc->debug & HPF_BSEDEBUG)
E 30
			printf("hpecc: BSE @ bn %d\n", bn);
E 21
D 7
		rp->hpcs1 = HP_DCLR | HP_GO;
D 4
		bcr += SECTSIZ;
E 4
I 4
		bcr += sectsiz;
E 4
		tad = rp->hpda;
D 4
		if ((bn = isbad(&hpbad[unit], bcr, tad>>8, tad&0x7f)) < 0)
E 4
I 4
		if ((bn = isbad(&hpbad[unit], bn/st->nspc,tad>>8,tad&0x7f)) < 0)
E 4
			return(1);
		bn = st->ncyl*st->nspc - st->nsect - 1 - bn;
E 7
D 32
		cn = bn/st->nspc;
		sn = bn%st->nspc;
		tn = sn/st->nsect;
D 7
		sn %= st->nsect;
D 4
		io->i_cc = -SECTSIZ;
		io->i_ma = (char *)((io->i_bn + npf -1)*SECTSIZ);
E 4
I 4
		io->i_cc = -sectsiz;
		io->i_ma += ((io->i_bn + npf -1)*sectsiz);
E 4
#ifdef HPDEBUG
		printf("revector to cn %d tn %d sn %d\n", cn, tn, sn);
#endif
E 7
I 7
		sn = sn%st->nsect;
E 32
I 32
		cn = bn / lp->d_secpercyl;
		sn = bn % lp->d_secpercyl;
		tn = sn / lp->d_nsectors;
		sn = sn % lp->d_nsectors;
E 32
		bcr += sectsiz;
D 36
		if ((bbn = isbad(&hpbad[unit], cn, tn, sn)) < 0)
E 36
I 36
		if ((bbn = isbad(&hpbad[io->i_adapt][unit], cn, tn, sn)) < 0)
E 36
D 14
			return(1);
E 14
I 14
			return (1);
E 14
D 32
		bbn = st->ncyl*st->nspc - st->nsect - 1 - bbn;
		cn = bbn/st->nspc;
		sn = bbn%st->nspc;
		tn = sn/st->nsect;
		sn = sn%st->nsect;
E 32
I 32
		bbn = lp->d_ncylinders * lp->d_secpercyl - lp->d_nsectors - 1
		    - bbn;
		cn = bbn / lp->d_secpercyl;
		sn = bbn % lp->d_secpercyl;
		tn = sn / lp->d_nsectors;
D 35
		sn = sn % lp ->d_nsectors;
E 35
I 35
		sn = sn % lp->d_nsectors;
E 35
E 32
		io->i_cc = sectsiz;
D 32
		io->i_ma += npf*sectsiz;
E 32
I 32
		io->i_ma += npf * sectsiz;
E 32
D 21
#ifdef HPDEBUG 
		printf("revector to cn %d tn %d sn %d mem: 0x%x\n", 
			cn, tn, sn, io->i_ma);
#endif 
I 10
		rp->hpof &= ~HPOF_SSEI;	/* clear skip sector inhibit if set */
E 21
I 21
D 30
		if (hpdebug[unit] & HPF_BSEDEBUG)
E 30
I 30
		if (sc->debug & HPF_BSEDEBUG)
E 30
			printf("revector to cn %d tn %d sn %d\n", cn, tn, sn);
		rp->hpof &= ~HPOF_SSEI;
E 21
E 10
		mbp->mba_sr = -1;
E 7
		rp->hpdc = cn;
		rp->hpda = (tn<<8) + sn;
D 7
		mbp->mba_sr = -1;
E 7
D 36
		mbastart(io,io->i_flgs);
E 36
I 36
		mbastart(io, io->i_unit, io->i_flgs);
E 36
D 21
		io->i_errcnt = 0;	/* error has been corrected */
E 21
I 21
		io->i_errcnt = 0;
E 21
I 7
D 13
		while(rp->hpds & HPDS_DRY == 0)
			;		/* wait for the read to complete */
E 7
D 4
		while(rp->hpds & HPDS_DRY == 0)
			;
E 4
		if (rp->hpds&HPDS_ERR)
			return(1);
		else
			return(0);
E 13
I 13
		HPWAIT(rp);
		return (rp->hpds&HPDS_ERR);
E 13
I 7
D 14
		}
E 14
E 7
	}
I 14
D 19
	}
E 19
	printf("hpecc: flag=%d\n", flag);
	return (1);
E 14
}
I 32
D 36
#endif
E 36
E 32
I 19

E 19
/*ARGSUSED*/
hpioctl(io, cmd, arg)
	struct iob *io;
	int cmd;
	caddr_t arg;
{
I 32
D 36
#ifdef SMALL
	return (ECMD);
#else
E 36
E 32
D 13

E 13
D 2
	struct hpst *st = &hpst[hp_type[io->i_unit]];
E 2
I 2
D 10
	struct st *st = &hpst[hp_type[io->i_unit]], *tmp;
E 2
	struct mba_drv *drv = mbadrv(io->i_unit);
E 10
I 10
	register unit = io->i_unit;
D 30
	struct st *st = &hpst[hp_type[unit]], *tmp;
E 30
I 30
D 36
	register struct hp_softc *sc = &hp_softc[unit];
D 32
	struct st *st = &hpst[sc->type];
E 32
I 32
	register struct disklabel *lp = &hplabel[unit];
E 32
E 30
	struct mba_drv *drv = mbadrv(unit);
E 36
I 36
	register struct hp_softc *sc = &hp_softc[io->i_adapt][unit];
	register struct disklabel *lp = &hplabel[io->i_adapt][unit];
	struct mba_drv *drv = mbadrv(io->i_adapt, unit);
E 36
I 21
D 30
	int flag;
E 30
E 21
E 10
D 2
	struct devdata *devd;
E 2

	switch(cmd) {
I 21

	case SAIODEBUG:
D 30
		flag = (int)arg;
		if (flag > 0)
			hpdebug[unit] |= flag;
		else
			hpdebug[unit] &= ~flag;
		return (0);
E 30
I 30
		sc->debug = (int)arg;
		break;
E 30
E 21

	case SAIODEVDATA:
D 30
		if ((drv->mbd_dt&MBDT_TAP) == 0) {
D 2
			devd = (struct devdata *)arg;
			devd->ncyl = st->ncyl;
			devd->ntrak = st->ntrak;
			devd->nspc = st->nspc;
			devd->nsect = st->nsect;
E 2
I 2
			tmp = (struct st *)arg;
			*tmp = *st;
E 2
D 14
			return(0);
E 14
I 14
			return (0);
E 14
		}
D 13
		else 
			return(ECMD);
E 13
I 13
D 14
		return(ECMD);
E 14
I 14
		return (ECMD);
E 30
I 30
		if (drv->mbd_dt&MBDT_TAP)
			return (ECMD);
D 32
		*(struct st *)arg = *st;
E 32
I 32
		*(struct disklabel *)arg = *lp;
E 32
		break;
E 30
E 14
E 13
I 7

I 30
	case SAIOGBADINFO:
		if (drv->mbd_dt&MBDT_TAP)
			return (ECMD);
D 36
		*(struct dkbad *)arg = hpbad[unit];
E 36
I 36
		*(struct dkbad *)arg = hpbad[io->i_adapt][unit];
E 36
		break;

	case SAIOECCLIM:
		sc->ecclim = (int)arg;
		break;

	case SAIORETRIES:
		sc->retries = (int)arg;
		break;

E 30
D 14
	case SAIOSSI:			/* set the skip-sector-inhibit flag */
		if ((drv->mbd_dt&MBDT_TAP) == 0) {
			if ((io->i_flgs&F_SSI)==0) { /* make sure this is */
				io->i_flgs |= F_SSI;  /* done only once    */
				st->nsect++;
				st->nspc += st->ntrak;
			}
			return(0);
E 14
I 14
	case SAIOSSI:			/* skip-sector-inhibit */
		if (drv->mbd_dt&MBDT_TAP)
			return (ECMD);
		if ((io->i_flgs&F_SSI) == 0) {
			/* make sure this is done once only */
			io->i_flgs |= F_SSI;
D 32
			st->nsect++;
			st->nspc += st->ntrak;
E 32
I 32
			lp->d_nsectors++;
			lp->d_secpercyl += lp->d_ntracks;
E 32
E 14
D 13
		} else
			return(ECMD);
E 13
I 13
		}
D 14
		return(ECMD);
E 14
I 14
D 30
		return (0);
E 30
I 30
		break;
E 30
E 14
E 13

D 14
	case SAIONOSSI:			/* remove the skip-sector-inh. flag */
E 14
I 14
	case SAIONOSSI:			/* remove skip-sector-inhibit */
E 14
		if (io->i_flgs & F_SSI) {
			io->i_flgs &= ~F_SSI;
			drv->mbd_of &= ~HPOF_SSEI;
D 32
			st->nsect--;
			st->nspc -= st->ntrak;
E 32
I 32
			lp->d_nsectors--;
			lp->d_secpercyl -= lp->d_ntracks;
E 32
		}
D 30
		return(0);
E 30
I 30
		break;
E 30
I 10

D 13
	case SAIOSSDEV:			/* return null if device has skip sector
					 * handling, otherwise return ECMD
					 */
E 13
I 13
	case SAIOSSDEV:			/* drive have skip sector? */
E 13
D 14
		if (RM80)
			return(0);
D 13
		else
			return(ECMD);
E 13
I 13
		return(ECMD);
E 13
E 10
E 7

	default:
		return (ECMD);
E 14
I 14
D 32
		return (RM80 ? 0 : ECMD);
E 32
I 32
		return (RM80(sc->type) ? 0 : ECMD);
E 32
I 30

	default:
		return (ECMD);
E 30
E 14
	}
I 14
D 30
	return (ECMD);
E 30
I 30
	return (0);
I 32
D 36
#endif
E 36
E 32
E 30
E 14
}
I 36
#endif /* !SMALL */
E 36
D 13

E 13
D 4
/* this routine is common to up & hp, move to a separate file */

/*
 * Search the bad sector table looking for
 * the specified sector.  Return index if found.
 * Return -1 if not found.
 */

isbad(bt, st, blno)
	register struct dkbad *bt;
D 2
	register struct devdata *st;	/* dirty, must be fixed */
E 2
I 2
	register struct st *st;
E 2
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
}
E 4
E 1
