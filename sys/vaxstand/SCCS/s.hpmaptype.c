h34389
s 00006/00002/00203
d D 7.8 88/06/14 18:20:37 bostic 21 20
c The emulex sc7003 is the newer version of the older sc750/sc780 massbus
c disk controls that is fast enough to handle super eagles (the sc780
c cannot). The code in hp.c requires that emulex disk controls emulate
c RM02. The code assumes that super eagles have 64 sectors, however the
c ONLY emulation for super eagles on a sc7003 that is a RM02 uses 68 sectors.
c From: muller%sdcc7@sdcsvax.ucsd.edu (Keith Muller)
e
s 00004/00002/00201
d D 7.7 88/05/27 15:50:17 karels 20 19
c unbreak compat code, allow formatter to open unformatted disk
e
s 00000/00001/00203
d D 7.6 88/02/05 11:24:35 bostic 19 18
c doesn't need savax.h
e
s 00009/00011/00195
d D 7.5 88/01/28 20:53:00 karels 18 17
c uvax changes; fix devsw index in confxx; header updates
e
s 00000/00011/00206
d D 7.4 87/09/16 13:23:20 karels 17 16
c move struct st to saio (again, now compat)
e
s 00001/00001/00216
d D 7.3 87/02/21 11:44:23 karels 16 15
c restore keywords
e
s 00069/00029/00148
d D 7.2 87/02/21 11:41:36 karels 15 14
c pack labels; various cleanups: open returns failure instead of stopping
e
s 00001/00001/00176
d D 7.1 86/06/05 01:42:40 mckusick 14 13
c 4.3BSD release version
e
s 00004/00000/00173
d D 6.4 86/05/30 17:54:20 karels 13 12
c add double eagle
e
s 00047/00024/00126
d D 6.3 85/11/08 19:15:47 karels 12 11
c so much cleaning: make skip-sector work in formatter, clean up
c ioctls for formatting options, make boothp small enough to fit,
c configure 9766's properly (sorry, 9300's!), don't use _exit from libc
e
s 00007/00001/00143
d D 6.2 85/06/08 13:08:53 mckusick 11 10
c Add copyright
e
s 00000/00000/00144
d D 6.1 83/07/29 07:47:07 sam 10 9
c 4.2 distribution
e
s 00004/00000/00140
d D 4.8 83/06/17 22:26:19 helge 9 8
c added 9300's on Emulex controller
e
s 00001/00002/00139
d D 4.7 83/03/03 11:05:57 sam 8 7
c bozo typing
e
s 00027/00013/00114
d D 4.6 83/03/01 19:09:49 sam 7 6
c with symbolic names it might even work
e
s 00014/00005/00113
d D 4.5 83/02/27 18:36:50 sam 6 5
c don't forget to do drive clear afterwards
e
s 00003/00005/00115
d D 4.4 83/02/22 00:11:54 sam 5 4
c screwed up mapping
e
s 00019/00020/00101
d D 4.3 83/02/21 18:18:39 sam 4 2
c reflect standard disk partition table sizes
e
s 00019/00020/00101
d R 4.3 83/02/21 18:13:44 sam 3 2
c fix up offset arrays to reflect partition tables
e
s 00000/00002/00121
d D 4.2 83/02/18 05:24:02 sam 2 1
c pull out common type mapping code for hp's
e
s 00123/00000/00000
d D 4.1 83/02/18 00:50:10 sam 1 0
c date and time created 83/02/18 00:50:10 by sam
e
u
U
t
T
I 1
D 11
/*	%M%	%I%	%E%	*/
E 11
I 11
/*
D 14
 * Copyright (c) 1982 Regents of the University of California.
E 14
I 14
D 20
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 20
I 20
 * Copyright (c) 1982, 1986, 1988 Regents of the University of California.
E 20
E 14
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
D 15
 *	%W% (Berkeley) %G%
E 15
I 15
D 16
 *	@(#)hpmaptype.c	7.1 (Berkeley) 6/5/86
E 16
I 16
 *	%W% (Berkeley) %G%
E 16
E 15
 */
E 11

/*
 * RP??/RM?? drive type mapping routine.
I 15
 * Used for compatibility with unlabeled disks.
E 15
 */
I 15
#ifdef COMPAT_42
E 15
#include "../machine/pte.h"

D 18
#include "../h/param.h"
#include "../h/inode.h"
#include "../h/fs.h"
I 15
#include "../h/disklabel.h"
E 18
I 18
#include "param.h"
#include "inode.h"
#include "fs.h"
#include "disklabel.h"
E 18
E 15

#include "../vaxmba/hpreg.h"
#include "../vaxmba/mbareg.h"

#include "saio.h"
D 19
#include "savax.h"
E 19

D 15
/* THIS SHOULD BE READ IN OFF THE PACK, PER DRIVE */
E 15
I 15
D 17
/*
 * Drive description table.
 */
struct st {
	short	nsect;		/* # sectors/track */
	short	ntrak;		/* # tracks/surfaces/heads */
	short	nspc;		/* # sectors/cylinder */
	short	ncyl;		/* # cylinders */
	short	*off;		/* partition offset table (cylinders) */
};

E 17
E 15
D 4
short	hp6_off[8] =	{ 0, 38, 0, -1, -1, -1, 118, -1 };
short	rm3_off[8] =	{ 0, 100, 0, -1, -1, -1, 310, -1 };
short	rm5_off[8] =	{ 0, 27, 0, 562, 589, 681, 562, 82 };
short	rm80_off[8] =	{ 0, 37, 0, -1, -1, -1, 115, 305 };
short	hp7_off[8] = 	{ 0, 10, 0, 330, 340, 500, 330, 50 };
E 4
I 4
short	rp06_off[8] =	{ 0, 38, 0, -1, -1, -1, 118, -1 };
short	rm03_off[8] =	{ 0, 100, 0, -1, -1, -1, 309, -1 };
short	rm05_off[8] =	{ 0, 27, 0, 562, 589, 681, 562, 82 };
short	rm80_off[8] =	{ 0, 37, 0, -1, -1, -1, 115, -1 };
D 21
short	rp07_off[8] = 	{ 0, 10, 0, 235, 245, 437, 235, 52 };
E 21
I 21
short	rp07_off[8] =	{ 0, 10, 0, 235, 245, 437, 235, 52 };
E 21
E 4
short	ml_off[8] =	{ 0, -1, -1, -1, -1, -1, -1, -1 };
D 4
short	si9775_off[8] =	{ 0, 13, 0, -1, -1, -1, 40, 441 };
short	si9730_off[8] = { 0, 50, 0, -1, -1, -1, -1, 155 };
short	hpam_off[8] =	{ 0, 32, 0, 668, 723, 778, 668, 98 };
short	hpfj_off[8] =	{ 0, 19, 0, -1, -1, -1, 398, 59 };
E 4
I 4
D 15
short	cdc9775_off[8] = { 0, 13, 0, -1, -1, -1, 294, 66 };
E 15
I 15
/*short	cdc9775_off[8] = { 0, 13, 0, -1, -1, -1, 294, 66 };*/
E 15
short	cdc9730_off[8] = { 0, 50, 0, -1, -1, -1, 155, -1 };
short	capricorn_off[8] = { 0, 32, 0, 668, 723, 778, 668, 98 };
D 21
short	eagle_off[8] =	{ 0, 17, 0, 391, 408, 728, 391, 87 };
E 21
I 21
short	eagle_off[8] = { 0, 17, 0, 391, 408, 728, 391, 87 };
E 21
I 13
short	fj2361_off[8] = { 0, 13, 0, 294, 307, 547, 294, 66 };
I 21
short	fj2361a_off[8] = { 0, 12, 0, 277, 289, 515, 277, 62 };
E 21
E 13
E 4
D 15
/* END SHOULD BE READ IN */
E 15

I 12
/*
 * hptypes is used to translate Massbus drive type and other information
 * into an index in hpst.  The indices of hptypes and hpst must therefore agree.
 */
short	hptypes[] = {
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
	-1,		/* 9766 */
I 13
	-1,		/* 2361 */
I 21
	-1,		/* 2361A */
E 21
E 13
	0
};

E 12
struct st hpst[] = {
I 7
#define	HPDT_RM03	0
E 7
D 4
	32,	5,	32*5,	823,	rm3_off,	/* RM03 */
	32,	19,	32*19,	823,	rm5_off,	/* RM05 */
	22,	19,	22*19,	815,	hp6_off,	/* RP06 */
E 4
I 4
	32,	5,	32*5,	823,	rm03_off,	/* RM03 */
I 7
#define	HPDT_RM05	1
E 7
	32,	19,	32*19,	823,	rm05_off,	/* RM05 */
I 7
#define	HPDT_RP06	2
E 7
	22,	19,	22*19,	815,	rp06_off,	/* RP06 */
I 7
#define	HPDT_RM80	3
E 7
E 4
	31,	14, 	31*14,	559,	rm80_off,	/* RM80 */
D 4
	22,	19,	22*19,	411,	hp6_off,	/* RP06 */
	50,	32,	50*32,	630,	hp7_off,	/* RP07 */
E 4
I 4
D 7
	22,	19,	22*19,	411,	rp06_off,	/* RP06 */
E 7
I 7
#define	HPDT_RP05	4
	22,	19,	22*19,	411,	rp06_off,	/* RP05 */
#define	HPDT_RP07	5
E 7
	50,	32,	50*32,	630,	rp07_off,	/* RP07 */
I 7
#define	HPDT_ML11A	6
E 7
E 4
	1,	1,	1,	1,	ml_off,		/* ML11A */
I 7
#define	HPDT_ML11B	7
E 7
	1,	1,	1,	1,	ml_off,		/* ML11B */
I 7
#define	HPDT_9775	8
E 7
D 4
	32,	40,	32*40,	843,	si9775_off,	/* 9775 */
	32,	10,	32*10,	823,	si9730_off,	/* 9730 */
	32,	16,	32*16,	1024,	hpam_off,	/* Ampex capricorn */
	43,	20,	43*20,	842,	hpfj_off,	/* Fuji Eagle */
	48,	20,	48*20,	842,	hpfj_off,	/* 48 sector Eagle */
E 4
I 4
D 15
	32,	40,	32*40,	843,	cdc9775_off,	/* 9775 */
E 15
I 15
	32,	40,	32*40,	843,	fj2361_off,	/* 9775 */
E 15
I 7
#define	HPDT_9730	9
E 7
	32,	10,	32*10,	823,	cdc9730_off,	/* 9730 */
I 7
#define	HPDT_CAP	10
E 7
	32,	16,	32*16,	1024,	capricorn_off,	/* Ampex capricorn */
I 7
#define	HPDT_EAGLE	11
E 7
D 8
	48,	20,	43*20,	842,	eagle_off,	/* Fuji Eagle */
E 8
I 8
	48,	20,	48*20,	842,	eagle_off,	/* Fuji Eagle */
E 8
I 7
#define	HPDT_RM02	12
E 7
E 4
D 12
	1,	1,	1,	1,	0,		/* rm02 - not used */
E 12
I 12
	32,	5,	32*5,	823,	rm03_off,	/* rm02 - not used */
E 12
I 7
#define	HPDT_9300	13
E 7
D 4
	32,	19,	32*19,	815,	rm5_off,	/* Ampex 9300 */
E 4
I 4
	32,	19,	32*19,	815,	rm05_off,	/* Ampex 9300 */
I 12
#define	HPDT_9766	14
	32,	19,	32*19,	823,	rm05_off,	/* CDC 9766 */
I 13
#define HPDT_2361	15
	64,	20,	64*20,	842,	fj2361_off,	/* Fuji 2361 */
I 21
#define HPDT_2361A
	68,	20,	68*20,	842,	fj2361a_off,	/* Fuji 2361a */
E 21
E 13
E 12
E 4
D 8

E 8
};
I 12
#define	NTYPES	(sizeof(hpst) / sizeof(hpst[0]))
E 12

#define	MASKREG(reg)	((reg)&0xffff)

D 15
hpmaptype(hpaddr, type, unit)
E 15
I 15
hpmaptype(hpaddr, type, unit, lp)
E 15
	register struct hpdevice *hpaddr;
D 15
	unsigned type;
E 15
I 15
	register unsigned type;
E 15
	int unit;
I 15
	register struct disklabel *lp;
E 15
{
I 15
	register i;
	register struct st *st;
E 15
D 12
	int ntracks, hpsn;
E 12
I 12
	int hpsn;
E 12

I 15
	for (i = 0; hptypes[i]; i++)
		if (hptypes[i] == type)
			goto found;
D 20
	_stop("unknown drive type");
E 20
I 20
	printf("unknown drive type\n");
	return (0);
E 20

found:
	type = i;
E 15
D 2
printf("hpmaptype: type=%d\n", type);
E 2
	/*
	 * Handle SI model byte stuff when
	 * we think it's an RM03 or RM05.
	 */
D 7
	if (type == 0 || type == 1) {
E 7
I 7
	if (type == HPDT_RM03 || type == HPDT_RM05) {
E 7
		hpsn = hpaddr->hpsn;
D 2
printf("hpsn=%x\n", hpsn&0xffff);
E 2
D 15
		if ((hpsn & SIMB_LU) != unit)
			return (type);
E 15
I 15
		if ((hpsn & SIMB_LU) == unit)
E 15
		switch ((hpsn & SIMB_MB) &~ (SIMB_S6|SIRM03|SIRM05)) {

		case SI9775D:
D 7
			return (8);
E 7
I 7
D 15
			return (HPDT_9775);
E 15
I 15
			type = HPDT_9775;
			break;
E 15
E 7

		case SI9730D:
D 7
			return (9);
E 7
I 7
D 15
			return (HPDT_9730);
E 15
I 15
			type = HPDT_9730;
			break;
E 15
E 7

D 12
		/*
		 * Beware, since the only have SI controller we
		 * have has a 9300 instead of a 9766, we map the
		 * drive type into the 9300.  This means that
		 * on a 9766 you lose the last 8 cylinders (argh).
		 */
E 12
		case SI9766:
D 5
			return (14);
E 5
I 5
D 7
			return (13);
E 7
I 7
D 12
			return (HPDT_9300);
E 12
I 12
D 15
			return (HPDT_9766);
E 15
I 15
			type = HPDT_9766;
			break;
E 15
E 12
E 7
E 5

		case SI9762:
D 7
			return (0);
E 7
I 7
D 15
			return (HPDT_RM03);
E 15
I 15
			type = HPDT_RM03;
			break;
E 15
E 7

		case SICAPD:
D 7
			return (10);
E 7
I 7
D 15
			return (HPDT_CAP);
E 15
I 15
			type = HPDT_CAP;
			break;
E 15
E 7

		case SI9751D:
D 5
			return (12);
E 5
I 5
D 7
			return (11);
E 7
I 7
D 15
			return (HPDT_EAGLE);
E 15
I 15
			type = HPDT_EAGLE;
			break;
E 15
E 7
E 5
		}
D 15
		return (type);
E 15
	}
	/*
D 12
	 * RM03: EMULEX controller.  Map to correct
E 12
I 12
	 * RM02: EMULEX controller.  Map to correct
E 12
	 * drive type by checking the holding
	 * register for the disk geometry.
	 */
D 7
	if (type == 13) {
E 7
I 7
	if (type == HPDT_RM02) {
E 7
I 6
D 12
		int newtype = type;
E 12
I 12
D 15
		int newtype, nsectors, ntracks, ncyl;
E 15
I 15
		int nsectors, ntracks, ncyl;
E 15
E 12

E 6
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXTRAK;
		ntracks = MASKREG(hpaddr->hphr) + 1;
D 6
		if (ntracks == 16)
			return (10);	/* AMPEX capricorn */
E 6
I 6
D 12
		if (ntracks == 16) {
D 7
			newtype = 10;	/* AMPEX capricorn */
E 7
I 7
			newtype = HPDT_CAP;	/* AMPEX capricorn */
E 7
			goto done;
		}
I 9
		if (ntracks == 19) {
			newtype = HPDT_9300;	/* AMPEX 9300 */
			goto done;
		}
E 12
I 12
		DELAY(100);
E 12
E 9
		hpaddr->hpcs1 = HP_NOP;
E 6
		hpaddr->hphr = HPHR_MAXSECT;
D 12
		ntracks = MASKREG(hpaddr->hphr) + 1;
D 6
		if (ntracks == 48)
D 5
			return (12);	/* 48 sector Eagle */
		if (ntracks == 43)
			return (11);	/* 43 sector Eagle */
E 5
I 5
			return (11);	/* 48 sector Eagle */
E 6
I 6
		if (ntracks == 48) {
D 7
			newtype = 11;	/* 48 sector Eagle */
E 7
I 7
			newtype = HPDT_EAGLE;	/* 48 sector Eagle */
E 7
			goto done;
E 12
I 12
		nsectors = MASKREG(hpaddr->hphr) + 1;
		DELAY(100);
		hpaddr->hpcs1 = HP_NOP;
		hpaddr->hphr = HPHR_MAXCYL;
		ncyl = MASKREG(hpaddr->hphr) + 1;
D 15
		for (newtype = 0; newtype < NTYPES; newtype++)
			if (hpst[newtype].nsect == nsectors &&
			    hpst[newtype].ntrak == ntracks &&
			    hpst[newtype].ncyl == ncyl)
E 15
I 15
		for (type = 0; type < NTYPES; type++)
			if (hpst[type].nsect == nsectors &&
			    hpst[type].ntrak == ntracks &&
			    hpst[type].ncyl == ncyl)
E 15
D 18
				break;
E 18
I 18
				goto done;
E 18

D 15
		if (newtype >= NTYPES) {
			printf("RM02 with %d sectors, %d tracks, %d cylinders?\n",
E 15
I 15
D 18
		if (type >= NTYPES) {
			printf("%d sectors, %d tracks, %d cyl?\n",
E 15
				nsectors, ntracks, ncyl);
D 15
			newtype = type;
E 15
I 15
			type = HPDT_RM02;
E 15
E 12
		}
E 18
I 18
		printf("%d sectors, %d tracks, %d cyl?\n",
			nsectors, ntracks, ncyl);
		type = HPDT_RM02;
E 18
E 6
E 5
D 12
		printf("RM02 with %d sectors/track?\n", ntracks);
E 12
D 6
		return (type);
E 6
I 6
	done:
		hpaddr->hpcs1 = HP_DCLR|HP_GO;
D 15
		return (newtype);
E 15
E 6
	}
I 15
D 18
	
E 18
I 18

E 18
E 15
	/*
D 15
	 * ML11's all map to the same type.
E 15
I 15
	 * set up minimal disk label.
E 15
	 */
D 7
	if (type == 6 || type == 7)
		return (6);
E 7
I 7
D 15
	if (type == HPDT_ML11A || type == HPDT_ML11B)
		return (HPDT_ML11A);
E 7
	return (type);
E 15
I 15
	st = &hpst[type];
	lp->d_nsectors = st->nsect;
	lp->d_ntracks = st->ntrak;
	lp->d_secpercyl = st->nspc;
	lp->d_ncylinders = st->ncyl;
	lp->d_secperunit = st->nspc * st->ncyl;
	lp->d_npartitions = 8;
	for (i = 0; i < 8; i++) {
		if (st->off[i] == -1)
			lp->d_partitions[i].p_size = 0;
		else {
			lp->d_partitions[i].p_offset = st->off[i] *
			    lp->d_secpercyl;
			lp->d_partitions[i].p_size = lp->d_secperunit;
		}
	}
I 20
	return (1);
E 20
E 15
}
I 15
#endif COMPAT_42
E 15
E 1
