h32853
s 00001/00001/00788
d D 7.5 88/10/22 15:14:00 karels 72 71
c use ubaalloc macros; use qbgetpri for Q-bus device probe routines
e
s 00008/00004/00781
d D 7.4 88/05/27 16:10:29 karels 71 70
c new diskerr routine
e
s 00000/00024/00785
d D 7.3 88/05/06 17:17:00 bostic 70 69
c changes for raw{read,write} stuff
e
s 00001/00001/00808
d D 7.2 87/01/14 08:48:54 karels 69 68
c rename dk.h to dkstat.h
e
s 00001/00001/00808
d D 7.1 86/06/05 01:14:35 mckusick 68 67
c 4.3BSD release version
e
s 00004/00004/00805
d D 6.11 86/05/02 11:46:35 karels 67 66
c watch for partial sectors in ecc routine, correct ptob=>dbtob
e
s 00004/00004/00805
d D 6.10 85/10/28 17:34:08 mckusick 66 65
c add d & f partitions; g partition didn't change but noted as wrong
e
s 00001/00001/00808
d D 6.9 85/09/17 18:37:55 eric 65 64
c facilities in syslog
e
s 00008/00006/00801
d D 6.8 85/09/16 22:09:17 karels 64 63
c off by one, and need resid
e
s 00028/00020/00779
d D 6.7 85/09/14 17:19:36 bloom 63 62
c get rid of interleave code, add macro to get unit number, add error return
c codes to strategy, reading last block after end of partition returns size = 0
e
s 00003/00001/00796
d D 6.6 85/08/08 13:52:41 bloom 62 61
c support partial dumps for large memory
e
s 00007/00001/00790
d D 6.5 85/06/08 14:19:11 mckusick 61 60
c Add copyright
e
s 00002/00001/00789
d D 6.4 85/03/12 15:30:09 ralph 60 59
c change softecc printf's to log's.
e
s 00016/00016/00774
d D 6.3 84/08/29 20:09:11 bloom 59 58
c Change to includes.  No more ../h
e
s 00001/00003/00789
d D 6.2 83/10/11 11:03:36 karels 58 57
c still active if forwarded sector completed transfer (from decvax!rich)
e
s 00000/00000/00792
d D 6.1 83/07/29 07:28:24 sam 57 56
c 4.2 distribution
e
s 00013/00000/00779
d D 4.54 83/05/18 02:21:03 sam 56 55
c add entry point for swap partition sizing at boot time
e
s 00001/00000/00778
d D 4.53 83/02/10 18:44:00 sam 55 54
c hz not in systm.h anymore
e
s 00000/00014/00778
d D 4.52 83/02/10 16:53:39 sam 54 53
c everybody has bad sector code
e
s 00002/00001/00790
d D 4.51 82/12/17 12:03:07 sam 53 52
c sun merge
e
s 00001/00001/00790
d D 4.50 82/11/26 18:17:10 sam 52 51
c don't call ubadone at ubareset time
e
s 00001/00002/00790
d D 4.49 82/10/17 20:18:07 root 51 50
c lint
e
s 00011/00000/00781
d D 4.48 82/10/17 11:50:03 root 50 49
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00002/00003/00779
d D 4.47 82/10/10 22:38:20 root 49 48
c minor fixes relating to u.u_error handling
e
s 00004/00006/00778
d D 4.46 82/10/10 17:28:16 root 48 47
c header files for vax are in their place
e
s 00002/00003/00782
d D 4.45 82/09/12 03:08:39 root 47 46
c 
e
s 00003/00002/00782
d D 4.44 82/08/22 21:19:02 root 46 45
c fully uio()'d
e
s 00005/00003/00779
d D 4.43 82/08/13 00:16:23 root 45 44
c changes for char dev uio'ing
e
s 00001/00001/00781
d D 4.42 82/07/15 20:01:29 kre 44 43
c probe routines return size of unibus dev regs to reserve space
e
s 00015/00008/00767
d D 4.41 82/06/14 22:42:30 root 43 42
c fixes to ecc code
e
s 00004/00002/00771
d D 4.40 82/06/05 20:04:45 wnj 42 39
c fix handling of b_active
e
s 00001/00001/00775
d R 4.41 82/05/19 15:32:05 root 41 40
c typo in printf (mosher)
e
s 00003/00000/00773
d R 4.40 82/05/10 08:07:00 root 40 39
c added more information to print out on rk not ready
e
s 00014/00021/00759
d D 4.39 82/03/29 00:48:38 wnj 39 38
c fixes from lucasfilm
e
s 00003/00002/00777
d D 4.38 82/01/17 20:12:33 root 38 37
c make bio and disk drivers not do spl0 so can call from panic without trap 2's
e
s 00001/00000/00778
d D 4.37 81/11/18 15:49:53 wnj 37 36
c lint
e
s 00002/00002/00776
d D 4.36 81/07/25 21:49:35 wnj 36 35
c fixes a couple of bugs related to resetting of
e
s 00007/00007/00771
d D 4.35 81/05/10 20:05:08 root 35 34
c NOBADBLOCK->NOBADSECT
e
s 00174/00065/00604
d D 4.34 81/05/09 19:50:36 root 34 33
c support rk06 and handle bad blocks
e
s 00001/00001/00668
d D 4.33 81/04/02 15:15:05 root 33 32
c fixup ecc code to work
e
s 00001/00004/00668
d D 4.32 81/03/21 15:53:30 wnj 32 31
c simplify ubainit() code
e
s 00024/00015/00648
d D 4.31 81/03/17 19:26:23 wnj 31 30
c fixes to error handling and cosmetics
e
s 00001/00001/00662
d D 4.30 81/03/17 18:12:19 wnj 30 29
c fixes to skip offset position on WRITES, not READS!
e
s 00001/00003/00662
d D 4.29 81/03/11 18:41:33 wnj 29 28
c cleanup todo
e
s 00002/00003/00663
d D 4.28 81/03/09 20:02:17 wnj 28 27
c fixes to offset recovery code
e
s 00002/00001/00664
d D 4.27 81/03/09 13:20:56 wnj 27 26
c recal fixes; fix botch with SSE in hp.c
e
s 00001/00001/00664
d D 4.26 81/03/09 01:54:04 wnj 26 25
c %G% -> %E%
e
s 00003/00007/00662
d D 4.25 81/03/09 00:34:26 wnj 25 24
c lint
e
s 00035/00025/00634
d D 4.24 81/03/07 14:28:17 wnj 24 23
c after attempt at ht driver at cc again; working with new 
c field names
e
s 00040/00022/00619
d D 4.23 81/03/06 23:30:17 wnj 23 22
c this driver really works except for lost interrupts 
c when you spin a drive down when both drives are running you lose an intrupt
e
s 00001/00001/00640
d D 4.22 81/03/06 13:03:38 wnj 22 21
c cosmetic
e
s 00008/00014/00633
d D 4.21 81/03/06 11:31:39 wnj 21 20
c new format of error prints
e
s 00009/00008/00638
d D 4.20 81/03/05 01:35:24 wnj 20 19
c new version which doesn't get hung up
e
s 00048/00041/00598
d D 4.19 81/03/03 18:10:58 wnj 19 18
c it workie it workie
e
s 00016/00022/00623
d D 4.18 81/03/03 12:38:57 wnj 18 17
c further driver work... up now handles spin down; rest still dont
e
s 00002/00009/00643
d D 4.17 81/02/28 17:36:56 wnj 17 16
c rmalloc and related stuff
e
s 00003/00003/00649
d D 4.16 81/02/27 03:14:52 wnj 16 15
c s/HZ/hz/
e
s 00001/00001/00651
d D 4.15 81/02/26 21:58:13 wnj 15 14
c call ubapurge() which works on 750's
e
s 00000/00001/00652
d D 4.14 81/02/26 10:38:08 wnj 14 13
c delete printing of mask and pos
e
s 00001/00001/00652
d D 4.13 81/02/26 04:29:25 wnj 13 12
c cosmetic for new config and 750/780
e
s 00028/00011/00625
d D 4.12 81/02/25 23:27:08 wnj 12 11
c cant get spin down code to work
e
s 00006/00004/00630
d D 4.11 81/02/25 21:03:44 wnj 11 10
c almost working versions
e
s 00003/00002/00631
d D 4.10 81/02/25 15:17:24 wnj 10 9
c fix size table
e
s 00018/00022/00615
d D 4.9 81/02/23 23:45:34 wnj 9 8
c minor typos
e
s 00021/00022/00616
d D 4.8 81/02/23 19:59:42 wnj 8 7
c working version
e
s 00568/00226/00070
d D 4.7 81/02/22 21:47:01 wnj 7 6
c working interlocked system
e
s 00006/00000/00290
d D 4.6 81/02/08 01:13:56 wnj 6 5
c last pre-mba version
e
s 00007/00010/00283
d D 4.5 81/01/15 19:37:46 wnj 5 4
c cleaned up printfs on errors... (still scrawed, tho)
e
s 00002/00002/00291
d D 4.4 80/12/30 18:51:52 wnj 4 3
c ubafree() becomes ubarelse() to fix race conditions
e
s 00004/00004/00289
d D 4.3 80/12/19 15:21:53 wnj 3 2
c DK_N -> XXDK_N
e
s 00001/00001/00292
d D 4.2 80/12/19 11:46:12 wnj 2 1
c s,../conf/,,
e
s 00293/00000/00000
d D 4.1 80/12/17 10:41:30 wnj 1 0
c date and time created 80/12/17 10:41:30 by wnj
e
u
U
t
T
I 42
D 48
#define	RKDEBUG
I 43
#define RKBDEBUG
E 48
E 43
E 42
I 1
D 26
/*	%M%	%I%	%G%	*/
E 26
I 26
D 61
/*	%M%	%I%	%E%	*/
E 61
I 61
/*
D 68
 * Copyright (c) 1982 Regents of the University of California.
E 68
I 68
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 68
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 61
E 26

I 23
D 25
int	rkpip;
int	rknosval;
E 25
E 23
D 2
#include "../conf/rk.h"
E 2
I 2
#include "rk.h"
E 2
D 7
#if NRK > 0
E 7
I 7
D 9
#if NRK11 > 0
E 9
I 9
#if NHK > 0
I 25
int	rkpip;		/* DEBUG */
int	rknosval;	/* DEBUG */
I 34
#ifdef RKDEBUG
E 34
I 31
int	rkdebug;
I 34
#endif
#ifdef RKBDEBUG
int	rkbdebug;
#endif
E 34
E 31
E 25
I 19
D 23
int	rkwaitdry;
E 23
E 19
E 9
D 8

int	rkflags;
int	rkerrs;
E 8
I 8
D 17
int	rkflags,rkerrs;		/* GROT */
E 17
E 8
E 7
/*
D 7
 * RK disk driver
E 7
I 7
D 31
 * RK11/RK07 disk driver
E 31
I 31
 * RK611/RK0[67] disk driver
E 31
I 8
 *
 * This driver mimics up.c; see it for an explanation of common code.
I 12
 *
D 18
 * THIS DRIVER DOESN'T DEAL WITH DRIVES SPINNING DOWN AND UP
E 18
I 18
 * TODO:
D 19
 *	Correct to handle spun-down drives
 *	Check write lock handling
E 19
D 29
 *	Add reading of bad sector information and disk layout from sector 1
 *	Add bad sector forwarding code
I 20
 *	Why do we lose an interrupt sometime when spinning drives down?
E 29
I 29
 *	Learn why we lose an interrupt sometime when spinning drives down
I 31
D 34
 *	Support rk06
E 34
E 31
E 29
E 20
D 19
 *	Fix drive recognition
E 19
E 18
E 12
E 8
E 7
 */
I 53
#include "../machine/pte.h"

E 53
D 7

E 7
I 7
D 25
#define	DELAY(i)		{ register int j; j = i; while (--j > 0); }
E 25
E 7
D 59
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
D 53
#include "../h/pte.h"
E 53
#include "../h/map.h"
I 7
#include "../h/vm.h"
E 7
D 24
#include "../h/uba.h"
E 24
I 24
D 48
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 48
E 24
#include "../h/dk.h"
I 7
D 48
#include "../h/cpu.h"
E 48
#include "../h/cmap.h"
I 34
#include "../h/dkbad.h"
I 45
#include "../h/uio.h"
I 55
#include "../h/kernel.h"
E 59
I 59
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
#include "map.h"
#include "vm.h"
D 69
#include "dk.h"
E 69
I 69
#include "dkstat.h"
E 69
#include "cmap.h"
#include "dkbad.h"
I 71
#include "ioctl.h"
#include "disklabel.h"
E 71
#include "uio.h"
#include "kernel.h"
I 60
#include "syslog.h"
E 60
E 59
E 55
E 45
E 34
E 7

D 7
#define NCYL 815
#define NSECT 22
#define NTRK 3
#define NBLK (NTRK*NSECT*NCYL)
E 7
I 7
D 48
#include "../h/rkreg.h"
E 48
I 48
#include "../vax/cpu.h"
D 59
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
#include "../vaxuba/rkreg.h"
E 59
I 59
#include "ubareg.h"
#include "ubavar.h"
#include "rkreg.h"
E 59
E 48
E 7

D 7
/* rkcs1 */
#define CCLR	0100000		/* controller clear */
#define	DI	040000		/* drive interrupt */
#define	CTO	04000		/* controller timeout */
#define	CDT	02000		/* drive type (rk07/rk06) */
#define	RDY	0200		/* controller ready */
#define	IEN	0100		/* interrupt enable */
E 7
I 7
struct	rk_softc {
	int	sc_softas;
	int	sc_ndrive;
	int	sc_wticks;
	int	sc_recal;
D 9
} rk_softc[NRK11];
E 9
I 9
} rk_softc[NHK];
E 9
E 7

I 63
#define rkunit(dev)	(minor(dev) >> 3)

E 63
I 7
/* THIS SHOULD BE READ OFF THE PACK, PER DRIVE */
D 17
struct	size
{
E 17
I 17
struct size {
E 17
	daddr_t	nblocks;
	int	cyloff;
D 34
} rk7_sizes[] ={
E 34
I 34
D 66
} rk7_sizes[8] ={
E 66
I 66
} rk7_sizes[8] = {
E 66
E 34
	15884,	0,		/* A=cyl 0 thru 240 */
D 10
	10032,	146,		/* B=cyl 241 thru 392 */
	53790,	246,		/* C=cyl 0 thru 814 */
E 10
I 10
	10032,	241,		/* B=cyl 241 thru 392 */
	53790,	0,		/* C=cyl 0 thru 814 */
I 66
	15884,	393,		/* D=cyl 393 thru 633 */
E 66
E 10
	0,	0,
D 66
	0,	0,
	0,	0,
	27786,	393,		/* G=cyl 393 thru 813 */
E 66
I 66
	11792,	634,		/* F=cyl 634 thru 814 */
	27786,	393,		/* G=cyl 393 thru 814, should be 27698 */
E 66
	0,	0,
I 34
}, rk6_sizes[8] ={
	15884,	0,		/* A=cyl 0 thru 240 */
	11154,	241,		/* B=cyl 241 thru 409 */
	27126,	0,		/* C=cyl 0 thru 410 */
	0,	0,
	0,	0,
	0,	0,
	0,	0,
	0,	0,
E 34
};
/* END OF STUFF WHICH SHOULD BE READ IN PER DISK */
E 7

I 34
short	rktypes[] = { RK_CDT, 0 };

E 34
D 7
/* rkcs2 */
#define	DLT	0100000		/* data late */
#define	WCE	040000		/* write check */
#define	UPE	020000		/* unibus parity */
#define	NED	010000		/* non-existant drive */
#define	NEM	04000		/* non-existant memory */
#define	PGE	02000		/* software error */
#define	MDS	01000		/* multiple drive select */
#define	UFE	0400		/* unit field error */
#define	SCLR	040		/* subsystem clear */
#define	cs2abort	(NED|NEM|PGE|UFE)
E 7
I 7
int	rkprobe(), rkslave(), rkattach(), rkdgo(), rkintr();
D 9
struct	uba_minfo *rkminfo[NRK11];
struct	uba_dinfo *rkdinfo[NRK07];
struct	uba_dinfo *rkip[NRK11][4];
E 9
I 9
D 24
struct	uba_minfo *rkminfo[NHK];
struct	uba_dinfo *rkdinfo[NRK];
struct	uba_dinfo *rkip[NHK][4];
E 24
I 24
struct	uba_ctlr *rkminfo[NHK];
struct	uba_device *rkdinfo[NRK];
struct	uba_device *rkip[NHK][4];
E 24
E 9
E 7

D 7
/* rkds */
#define	SVAL	0100000		/* status valid */
#define	CDA	040000		/* current drive attention */
#define	PIP	020000		/* positioning in progress */
#define	WRL	04000		/* write lock */
#define	DDT	0400		/* disk drive type */
#define	DRDY	0200		/* drive ready */
#define	VV	0100		/* volume valid */
#define	DROT	040		/* drive off track */
#define	SPLS	020		/* speed loss */
#define	ACLO	010		/* ac low */
#define	OFFSET	04		/* offset mode */
#define	DRA	01		/* drive available */
#define	dsabort		(ACLO|SPLS)
E 7
I 7
u_short	rkstd[] = { 0777440, 0 };
struct	uba_driver hkdriver =
D 8
  { rkprobe, rkslave, rkattach, rkdgo, rkstd, "rk", rkdinfo, "hk", rkminfo };
E 8
I 8
 { rkprobe, rkslave, rkattach, rkdgo, rkstd, "rk", rkdinfo, "hk", rkminfo, 1 };
E 8
D 9
struct	buf rkutab[NRK07];
short	rkcyl[NRK07];
E 9
I 9
struct	buf rkutab[NRK];
short	rkcyl[NRK];
I 34
D 35
#ifndef NOBADBLOCK
E 35
I 35
D 54
#ifndef NOBADSECT
E 54
E 35
struct	dkbad rkbad[NRK];
struct	buf brkbuf[NRK];
D 54
#endif
E 54
E 34
E 9
E 7

I 7
struct	rkst {
	short	nsect;
	short	ntrak;
	short	nspc;
	short	ncyl;
	struct	size *sizes;
} rkst[] = {
	NRKSECT, NRKTRK, NRKSECT*NRKTRK,	NRK7CYL,	rk7_sizes,
I 34
	NRKSECT, NRKTRK, NRKSECT*NRKTRK,	NRK6CYL,	rk6_sizes,
E 34
};
E 7

D 7
/* commands */
#define SELECT 0
#define PACK 2
#define DCLR 4
#define	RESET	012
#define	WCOM	022
#define	RCOM	020
#define	GO	01
#define	DRESET	012
E 7
I 7
u_char 	rk_offset[16] =
D 31
  { P400,M400,P400,M400,P800,M800,P800,M800,P1200,M1200,P1200,M1200,0,0,0,0 };
E 31
I 31
  { RKAS_P400,RKAS_M400,RKAS_P400,RKAS_M400,RKAS_P800,RKAS_M800,RKAS_P800,
    RKAS_M800,RKAS_P1200,RKAS_M1200,RKAS_P1200,RKAS_M1200,0,0,0,0
  };
E 31
E 7

D 7
struct	device
E 7
I 7
D 9
struct	buf rrkbuf[NRK07];
E 9
I 9
D 70
struct	buf rrkbuf[NRK];
E 9

E 70
#define	b_cylin	b_resid

D 63
#ifdef INTRLVE
daddr_t	dkblock();
#endif

E 63
int	rkwstart, rkwatch();

rkprobe(reg)
	caddr_t reg;
E 7
{
D 7
	short rkcs1;
	short rkwc;
	unsigned short rkba;
	short rkda;
	short rkcs2;
	short rkds;
	short rker;
	short rkatt;
	short rkcyl;
	short rkdb;
	short rkmr1;
	short rkecps;
	short rkecpt;
	short rkmr2;
	short rkmr3;
} ;
E 7
I 7
	register int br, cvec;
E 7

D 7
struct	buf	rktab;
struct	buf	rrkbuf;
E 7
I 7
#ifdef lint	
	br = 0; cvec = br; br = cvec;
I 37
	rkintr(0);
E 37
#endif
	((struct rkdevice *)reg)->rkcs1 = RK_CDT|RK_IE|RK_CRDY;
	DELAY(10);
	((struct rkdevice *)reg)->rkcs1 = RK_CDT;
D 44
	return (1);
E 44
I 44
	return (sizeof (struct rkdevice));
E 44
}
E 7

D 7
struct	devsize {
	unsigned int nblocks;
	int	cyloff;
} rk_sizes [] ={
	9614, 0,	/* 0 - 145 */
	6600, 146,	/* 146 - 245 */
	37554, 246,	/* 246 - 815 */
	0,	0,
	0,	0,
	0,	0,
	0,	0,
D 5
	0,	0,
E 5
I 5
	53790,	0,
E 5
};
E 7
I 7
rkslave(ui, reg)
D 24
	struct uba_dinfo *ui;
E 24
I 24
	struct uba_device *ui;
E 24
	caddr_t reg;
{
	register struct rkdevice *rkaddr = (struct rkdevice *)reg;
E 7

I 7
D 19
	rkaddr->rkcs1 = RK_CDT;
E 19
I 19
D 34
	rkaddr->rkcs1 = RK_CDT|RK_CCLR;
E 34
I 34
	ui->ui_type = 0;
	rkaddr->rkcs1 = RK_CCLR;
E 34
E 19
	rkaddr->rkcs2 = ui->ui_slave;
I 19
D 23
	rkaddr->rkcs1 = RK_CDT|RK_SELECT|RK_GO;
E 23
I 23
	rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
E 23
E 19
I 8
	rkwait(rkaddr);
D 19
/* SHOULD TRY THIS BY PULLING A PLUG */
/* A DELAY OR SOMETHING MAY BE NEEDED */
E 8
	if (rkaddr->rkcs2&RK_NED) {
E 19
I 19
	DELAY(50);
D 31
	if (rkaddr->rkcs2&RK_NED || (rkaddr->rkds&RK_SVAL) == 0) {
E 31
I 31
	if (rkaddr->rkcs2&RKCS2_NED || (rkaddr->rkds&RKDS_SVAL) == 0) {
E 31
E 19
D 34
		rkaddr->rkcs1 = RK_CDT|RK_CCLR;
E 34
I 34
		rkaddr->rkcs1 = RK_CCLR;
E 34
		return (0);
	}
I 34
	if (rkaddr->rkcs1&RK_CERR && rkaddr->rker&RKER_DTYE) {
		ui->ui_type = 1;
		rkaddr->rkcs1 = RK_CCLR;
	}
E 34
	return (1);
}

rkattach(ui)
D 24
	register struct uba_dinfo *ui;
E 24
I 24
	register struct uba_device *ui;
E 24
{

	if (rkwstart == 0) {
D 16
		timeout(rkwatch, (caddr_t)0, HZ);
E 16
I 16
		timeout(rkwatch, (caddr_t)0, hz);
E 16
		rkwstart++;
	}
	if (ui->ui_dk >= 0)
D 16
		dk_mspw[ui->ui_dk] = 1.0 / (HZ * NRKSECT * 256);
E 16
I 16
		dk_mspw[ui->ui_dk] = 1.0 / (60 * NRKSECT * 256);
E 16
	rkip[ui->ui_ctlr][ui->ui_slave] = ui;
	rk_softc[ui->ui_ctlr].sc_ndrive++;
	rkcyl[ui->ui_unit] = -1;
I 34
	ui->ui_flags = 0;
E 34
}
 
I 50
rkopen(dev)
	dev_t dev;
{
D 63
	register int unit = minor(dev) >> 3;
E 63
I 63
D 64
	register int unit = idcunit(dev);
E 64
I 64
	register int unit = rkunit(dev);
E 64
E 63
	register struct uba_device *ui;

	if (unit >= NRK || (ui = rkdinfo[unit]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
	return (0);
}

E 50
E 7
rkstrategy(bp)
D 7
register struct buf *bp;
E 7
I 7
	register struct buf *bp;
E 7
{
D 7
register dn, sz;
E 7
I 7
D 24
	register struct uba_dinfo *ui;
E 24
I 24
	register struct uba_device *ui;
E 24
	register struct rkst *st;
	register int unit;
	register struct buf *dp;
	int xunit = minor(bp->b_dev) & 07;
	long bn, sz;
I 38
	int s;
E 38
E 7

D 7
	dn = minor(bp->b_dev);
D 5
	sz = (bp->b_bcount>>9);
	if (dn > (NRK<<3) || sz+bp->b_blkno >= rk_sizes[dn&07].nblocks) {
E 5
I 5
	sz = ((bp->b_bcount+511)>>9);
	if (dn > (NRK<<3) || sz+bp->b_blkno > rk_sizes[dn&07].nblocks) {
E 5
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
E 7
I 7
	sz = (bp->b_bcount+511) >> 9;
D 63
	unit = dkunit(bp);
D 9
	if (unit >= NRK07)
E 9
I 9
	if (unit >= NRK)
E 63
I 63
	unit = rkunit(bp->b_dev);
	if (unit >= NRK) {
		bp->b_error = ENXIO;
E 63
E 9
		goto bad;
I 63
	}
E 63
	ui = rkdinfo[unit];
D 63
	if (ui == 0 || ui->ui_alive == 0)
E 63
I 63
	if (ui == 0 || ui->ui_alive == 0) {
		bp->b_error = ENXIO;
E 63
		goto bad;
I 63
	}
E 63
	st = &rkst[ui->ui_type];
	if (bp->b_blkno < 0 ||
D 63
	    (bn = dkblock(bp))+sz > st->sizes[xunit].nblocks)
E 63
I 63
	    (bn = bp->b_blkno)+sz > st->sizes[xunit].nblocks) {
D 64
		if (bp->b_blkno == st->sizes[xunit].nblocks +1)
E 64
I 64
		if (bp->b_blkno == st->sizes[xunit].nblocks) {
		    bp->b_resid = bp->b_bcount;
E 64
		    goto done;
I 64
		}
E 64
		bp->b_error = EINVAL;
E 63
		goto bad;
I 63
	}
E 63
	bp->b_cylin = bn/st->nspc + st->sizes[xunit].cyloff;
D 38
	(void) spl5();
E 38
I 38
	s = spl5();
E 38
	dp = &rkutab[ui->ui_unit];
	disksort(dp, bp);
	if (dp->b_active == 0) {
		(void) rkustart(ui);
		bp = &ui->ui_mi->um_tab;
		if (bp->b_actf && bp->b_active == 0)
			(void) rkstart(ui->ui_mi);
E 7
	}
D 7
	bp->av_forw = (struct buf *)NULL;
	spl5();
	if(rktab.b_actf == NULL)
		rktab.b_actf = bp;
	else
		rktab.b_actl->av_forw = bp;
	rktab.b_actl = bp;
	if(rktab.b_active == NULL)
		rkstart();
	spl0();
E 7
I 7
D 38
	(void) spl0();
E 38
I 38
	splx(s);
E 38
	return;

bad:
	bp->b_flags |= B_ERROR;
I 63
done:
E 63
	iodone(bp);
	return;
E 7
}

D 7
int rk_info;
int tcn, ttn, tsn;
E 7
I 7
rkustart(ui)
D 24
	register struct uba_dinfo *ui;
E 24
I 24
	register struct uba_device *ui;
E 24
{
	register struct buf *bp, *dp;
D 24
	register struct uba_minfo *um;
E 24
I 24
	register struct uba_ctlr *um;
E 24
	register struct rkdevice *rkaddr;
D 25
	register struct rkst *st;
	daddr_t bn;
	int sn, csn;
E 25
D 39
	int didie = 0;
E 39
E 7

D 7
rkstart()
E 7
I 7
	if (ui == 0)
D 39
		return (0);
E 39
I 39
		return;
E 39
	dk_busy &= ~(1<<ui->ui_dk);
	dp = &rkutab[ui->ui_unit];
D 19
	if ((bp = dp->b_actf) == NULL)
		goto out;
E 19
	um = ui->ui_mi;
I 19
	rkaddr = (struct rkdevice *)um->um_addr;
E 19
	if (um->um_tab.b_active) {
		rk_softc[um->um_ctlr].sc_softas |= 1<<ui->ui_slave;
D 39
		return (0);
E 39
I 39
		return;
E 39
	}
I 39
	if ((bp = dp->b_actf) == NULL)
		return;
E 39
D 19
	rkaddr = (struct rkdevice *)um->um_addr;
E 19
D 34
	rkaddr->rkcs1 = RK_CDT|RK_CERR;
E 34
I 34
	rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_CERR;
E 34
	rkaddr->rkcs2 = ui->ui_slave;
D 23
	rkaddr->rkcs1 = RK_CDT|RK_SELECT|RK_GO;
E 23
I 23
D 34
	rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
E 34
I 34
	rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_DCLR|RK_GO;
E 34
E 23
	rkwait(rkaddr);
D 19
	if (dp->b_active)
		goto done;
	dp->b_active = 1;
E 19
I 19
D 20
	rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
	rkwait(rkaddr);
	if ((bp = dp->b_actf) == NULL)
		goto out;
E 20
I 20
D 39
	if ((bp = dp->b_actf) == NULL) {
D 34
		rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
E 34
I 34
		rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_DCLR|RK_GO;
E 34
		rkwait(rkaddr);
		return (0);
	}
E 39
E 20
E 19
D 31
	if ((rkaddr->rkds & RK_VV) == 0) {
E 31
I 31
D 34
	if ((rkaddr->rkds & RKDS_VV) == 0) {
E 34
I 34
	if ((rkaddr->rkds & RKDS_VV) == 0 || ui->ui_flags == 0) {
E 34
E 31
		/* SHOULD WARN SYSTEM THAT THIS HAPPENED */
D 19
		rkaddr->rkcs1 = RK_CDT|RK_IE|RK_PACK|RK_GO;
E 19
I 19
D 34
		rkaddr->rkcs1 = RK_CDT|RK_PACK|RK_GO;
E 34
I 34
D 35
#ifndef NOBADBLOCK
E 35
I 35
D 54
#ifndef NOBADSECT
E 54
E 35
		struct rkst *st = &rkst[ui->ui_type];
		struct buf *bbp = &brkbuf[ui->ui_unit];
D 54
#endif
E 54

		rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_PACK|RK_GO;
		ui->ui_flags = 1;
D 35
#ifndef NOBADBLOCK
E 35
I 35
D 54
#ifndef NOBADSECT
E 54
E 35
		bbp->b_flags = B_READ|B_BUSY;
		bbp->b_dev = bp->b_dev;
		bbp->b_bcount = 512;
		bbp->b_un.b_addr = (caddr_t)&rkbad[ui->ui_unit];
		bbp->b_blkno = st->ncyl*st->nspc - st->nsect;
		bbp->b_cylin = st->ncyl - 1;
		dp->b_actf = bbp;
		bbp->av_forw = bp;
		bp = bbp;
D 54
#endif
E 54
E 34
E 19
		rkwait(rkaddr);
D 19
		didie = 1;
E 19
	}
I 20
	if (dp->b_active)
		goto done;
	dp->b_active = 1;
E 20
I 19
D 31
	if ((rkaddr->rkds & RK_DREADY) != RK_DREADY)
E 31
I 31
	if ((rkaddr->rkds & RKDS_DREADY) != RKDS_DREADY)
E 31
		goto done;
E 19
	if (rk_softc[um->um_ctlr].sc_ndrive == 1)
		goto done;
	if (bp->b_cylin == rkcyl[ui->ui_unit])
		goto done;
	rkaddr->rkcyl = bp->b_cylin;
	rkcyl[ui->ui_unit] = bp->b_cylin;
D 34
	rkaddr->rkcs1 = RK_CDT|RK_IE|RK_SEEK|RK_GO;
E 34
I 34
	rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_IE|RK_SEEK|RK_GO;
E 34
D 39
	didie = 1;
E 39
	if (ui->ui_dk >= 0) {
		dk_busy |= 1<<ui->ui_dk;
		dk_seek[ui->ui_dk]++;
	}
	goto out;
done:
	if (dp->b_active != 2) {
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
		dp->b_active = 2;
	}
out:
D 39
	return (didie);
E 39
I 39
	return;
E 39
}

rkstart(um)
D 24
	register struct uba_minfo *um;
E 24
I 24
	register struct uba_ctlr *um;
E 24
E 7
{
D 7
	register struct buf *bp;
	register com;
	register struct device *rkaddr = RKADDR;
E 7
I 7
	register struct buf *bp, *dp;
D 24
	register struct uba_dinfo *ui;
E 24
I 24
	register struct uba_device *ui;
E 24
	register struct rkdevice *rkaddr;
	struct rkst *st;
E 7
	daddr_t bn;
D 7
	int dn, cn, sn, tn;
E 7
I 7
	int sn, tn, cmd;
I 19
D 23
	int waitdry;
E 23
E 19
E 7

D 7
	if ((bp = rktab.b_actf) == NULL)
		return;
	rktab.b_active++;
	rk_info = ubasetup(bp, 1);
	bn = bp->b_blkno;
	dn = minor(bp->b_dev);
	cn = bn/(NTRK*NSECT);
	cn += rk_sizes[dn&07].cyloff;
	dn >>= 3;
	if (dn != (rkaddr->rkcs2&07)) {
		rkaddr->rkcs2 = dn;
		rkaddr->rkcs1 = CDT | GO;
		while ((rkaddr->rkcs1&RDY)==0)
			;
E 7
I 7
loop:
	if ((dp = um->um_tab.b_actf) == NULL)
D 39
		return (0);
E 39
I 39
		return;
E 39
	if ((bp = dp->b_actf) == NULL) {
		um->um_tab.b_actf = dp->b_forw;
		goto loop;
E 7
	}
D 7
	if ((rkaddr->rkds & VV) == 0) {
		rkaddr->rkcs1 = PACK | CDT | GO;
		while ((rkaddr->rkcs1&RDY)==0)
			;
E 7
I 7
	um->um_tab.b_active++;
D 63
	ui = rkdinfo[dkunit(bp)];
	bn = dkblock(bp);
E 63
I 63
	ui = rkdinfo[rkunit(bp->b_dev)];
	bn = bp->b_blkno;
E 63
	st = &rkst[ui->ui_type];
	sn = bn%st->nspc;
	tn = sn/st->nsect;
	sn %= st->nsect;
	rkaddr = (struct rkdevice *)ui->ui_addr;
I 23
retry:
E 23
D 34
	rkaddr->rkcs1 = RK_CDT|RK_CERR;
E 34
I 34
	rkaddr->rkcs1 = RK_CCLR;
E 34
	rkaddr->rkcs2 = ui->ui_slave;
D 23
	rkaddr->rkcs1 = RK_CDT|RK_SELECT|RK_GO;
E 23
I 23
D 34
	rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
E 34
I 34
	rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_DCLR|RK_GO;
E 34
E 23
	rkwait(rkaddr);
I 19
D 23
	waitdry = 0;
	while ((rkaddr->rkds&RK_SVAL) == 0) {
		if (++waitdry > 32)
			break;
		rkwaitdry++;
E 23
I 23
D 31
	if ((rkaddr->rkds&RK_SVAL) == 0) {
E 31
I 31
	if ((rkaddr->rkds&RKDS_SVAL) == 0) {
E 31
		rknosval++;
		goto nosval;
E 23
	}
I 23
D 31
	if (rkaddr->rkds&RK_PIP) {
E 31
I 31
	if (rkaddr->rkds&RKDS_PIP) {
E 31
		rkpip++;
		goto retry;
	}
E 23
D 31
	if ((rkaddr->rkds&RK_DREADY) != RK_DREADY) {
E 31
I 31
	if ((rkaddr->rkds&RKDS_DREADY) != RKDS_DREADY) {
E 31
D 21
		printf("rk%d not ready", dkunit(bp));
E 21
I 21
D 63
		printf("rk%d: not ready", dkunit(bp));
E 63
I 63
		printf("rk%d: not ready", rkunit(bp->b_dev));
E 63
E 21
D 31
		if ((rkaddr->rkds&RK_DREADY) != RK_DREADY) {
E 31
I 31
		if ((rkaddr->rkds&RKDS_DREADY) != RKDS_DREADY) {
E 31
			printf("\n");
D 34
			rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
E 34
I 34
			rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_DCLR|RK_GO;
E 34
			rkwait(rkaddr);
D 34
			rkaddr->rkcs1 = RK_CDT|RK_CERR;
E 34
I 34
			rkaddr->rkcs1 = RK_CCLR;
E 34
			rkwait(rkaddr);
			um->um_tab.b_active = 0;
			um->um_tab.b_errcnt = 0;
			dp->b_actf = bp->av_forw;
			dp->b_active = 0;
			bp->b_flags |= B_ERROR;
			iodone(bp);
			goto loop;
		}
		printf(" (came back!)\n");
	}
E 19
D 23
	if (um->um_tab.b_errcnt >= 16 && (bp->b_flags&B_READ) != 0) {
		rkaddr->rkatt = rk_offset[um->um_tab.b_errcnt & 017];
		rkaddr->rkcs1 = RK_CDT|RK_OFFSET|RK_GO;
		rkwait(rkaddr);
E 7
	}
E 23
I 23
nosval:
E 23
D 7
	tn = bn%(NTRK*NSECT);
	tn = tn/NSECT;
	sn = bn%NSECT;
	rkaddr->rkcs2 = dn;
	rkaddr->rkcyl = cn;
	rkaddr->rkda = (tn << 8) | sn;
	ttn = tn; tcn = cn; tsn = sn;
	rkaddr->rkba = rk_info;
	rkaddr->rkwc = -(bp->b_bcount>>1);
	com = ((rk_info &0x30000) >> 8) | CDT | IEN | GO;
	if(bp->b_flags & B_READ)
		com |= RCOM; else
		com |= WCOM;
	rkaddr->rkcs1 = com;
D 3
	dk_busy |= 1<<DK_N;
	dk_xfer[DK_N] += 1;
E 3
I 3
	dk_busy |= 1<<RKDK_N;
	dk_xfer[RKDK_N] += 1;
E 3
	com = bp->b_bcount>>6;
D 3
	dk_wds[DK_N] += com;
E 3
I 3
	dk_wds[RKDK_N] += com;
E 7
I 7
	rkaddr->rkcyl = bp->b_cylin;
	rkcyl[ui->ui_unit] = bp->b_cylin;
	rkaddr->rkda = (tn << 8) + sn;
	rkaddr->rkwc = -bp->b_bcount / sizeof (short);
	if (bp->b_flags & B_READ)
D 34
		cmd = RK_CDT|RK_IE|RK_READ|RK_GO;
E 34
I 34
		cmd = rktypes[ui->ui_type]|RK_IE|RK_READ|RK_GO;
E 34
	else
D 34
		cmd = RK_CDT|RK_IE|RK_WRITE|RK_GO;
E 34
I 34
		cmd = rktypes[ui->ui_type]|RK_IE|RK_WRITE|RK_GO;
E 34
	um->um_cmd = cmd;
D 25
	ubago(ui);
E 25
I 25
	(void) ubago(ui);
E 25
D 39
	return (1);
E 39
E 7
E 3
}

D 7
rkintr()
E 7
I 7
rkdgo(um)
D 24
	register struct uba_minfo *um;
E 24
I 24
	register struct uba_ctlr *um;
E 24
E 7
{
D 7
	register struct buf *bp;
	register d, x;
	register struct device *rkaddr = RKADDR;
	int ds, er;
E 7
I 7
	register struct rkdevice *rkaddr = (struct rkdevice *)um->um_addr;
E 7

I 39
D 42
	um->um_tab.b_active++;	/* should now be 2 */
E 42
I 42
	um->um_tab.b_active = 2;	/* should now be 2 */
E 42
E 39
D 7
	if (rktab.b_active == NULL)
		return;
D 3
	dk_busy &= ~(1<<DK_N);
E 3
I 3
	dk_busy &= ~(1<<RKDK_N);
E 3
	bp = rktab.b_actf;
	rktab.b_active = NULL;
	if (rkaddr->rkcs1 < 0) {		/* error bit */
		d = (minor(bp->b_dev)>>3);
		x = 1;
		if (rkaddr->rkcs1&DI) {
D 5
			printf("DI");
E 5
I 5
			printf("rkintr: DI\n");
E 5
		}
		if (rkaddr->rkds&CDA)
D 5
			printf("CDA ");
E 5
I 5
			printf("rkintr: CDA\n");
E 5
		if ((rkaddr->rkds&CDA) || (rkaddr->rkcs1&DI)) {
			er = (unsigned short)rkaddr->rker;
			ds = (unsigned short)rkaddr->rkds;
			rkaddr->rkcs1 = CDT | DCLR | GO;
D 5
			printf("DCLR");
E 5
		} else {
			if ((rkaddr->rkds&SVAL)==0) {
D 5
				printf("no SVAL\n");
				x = rkselect(rkaddr, d);
				printf("x = %d\n", x);
E 5
I 5
				x = 0x8000 - rkselect(rkaddr, d);
				printf("rkintr: no SVAL, delay %d\n", x);
E 7
I 7
	rkaddr->rkba = um->um_ubinfo;
	rkaddr->rkcs1 = um->um_cmd|((um->um_ubinfo>>8)&0x300);
}

D 13
hkintr(rk11)
E 13
I 13
rkintr(rk11)
E 13
	int rk11;
{
D 24
	register struct uba_minfo *um = rkminfo[rk11];
	register struct uba_dinfo *ui;
E 24
I 24
	register struct uba_ctlr *um = rkminfo[rk11];
	register struct uba_device *ui;
E 24
	register struct rkdevice *rkaddr = (struct rkdevice *)um->um_addr;
	register struct buf *bp, *dp;
	int unit;
	struct rk_softc *sc = &rk_softc[um->um_ctlr];
	int as = (rkaddr->rkatt >> 8) | sc->sc_softas;
D 51
	int needie = 1;
E 51

	sc->sc_wticks = 0;
	sc->sc_softas = 0;
D 39
	if (um->um_tab.b_active) {
E 39
I 39
	if (um->um_tab.b_active == 2 || sc->sc_recal) {
I 42
		um->um_tab.b_active = 1;
E 42
E 39
I 23
D 33
		ubadone(um);
E 33
E 23
		dp = um->um_tab.b_actf;
		bp = dp->b_actf;
D 63
		ui = rkdinfo[dkunit(bp)];
E 63
I 63
		ui = rkdinfo[rkunit(bp->b_dev)];
E 63
		dk_busy &= ~(1 << ui->ui_dk);
I 34
D 35
#ifndef NOBADBLOCK
E 35
I 35
D 54
#ifndef NOBADSECT
E 54
E 35
		if (bp->b_flags&B_BAD)
			if (rkecc(ui, CONT))
				return;
D 54
#endif
E 54
E 34
		if (rkaddr->rkcs1 & RK_CERR) {
			int recal;
I 12
D 19
#ifdef notdef
			int del = 0;
#endif
E 19
E 12
			u_short ds = rkaddr->rkds;
			u_short cs2 = rkaddr->rkcs2;
			u_short er = rkaddr->rker;
I 34
#ifdef RKDEBUG
E 34
D 21
			if (sc->sc_recal)
				printf("recal CERR\n");
E 21
D 8
			rkerrs++;
			if (rkflags&1)
			printf("%d ds %o cs2 %o er %o\n", um->um_tab.b_errcnt,
			    ds, cs2, er);
E 8
I 8
D 12
			rkerrs++;				/* GROT */
			if (rkflags&1)				/* GROT */
			printf("%d ds %o cs2 %o er %o\n",	/* GROT */
			    um->um_tab.b_errcnt, ds, cs2, er);	/* GROT */
E 8
			if (er & RK_WLE)	
				printf("rk%d is write locked\n", dkunit(bp));
I 8
/* THIS DOESN'T SEEM TO HAPPEN */
/* OR WAS SOMETHING BROKEN WHEN WE TRIED */
/* SPINNING A DRIVE DOWN ? */
E 8
			if (ds & RKDS_HARD)
E 12
I 12
D 17
			rkerrs++;
E 17
D 19
#ifdef notdef
/* THIS ATTEMPTED TO FIND OUT IF THE DRIVE IS SPUN */
/* DOWN BUT IT DOESN'T SEEM TO WORK... THE DRIVE SEEMS TO */
/* TELL PAINFULLY LITTLE WHEN IT IS SPUN DOWN (I.E. NOTHING CHANGES) */
/* THE DRIVE JUST KEEPS SAYING IT WANTS ATTENTION AND BLOWING ALL COMMANDS */
			if (ds & RK_CDA) {
				rkaddr->rkcs1 = RK_CDT|RK_CERR;
				rkaddr->rkcs2 = ui->ui_slave;
				rkaddr->rkcs1 = RK_CDT|RK_SELECT|RK_GO;
				rkwait(rkaddr);
				while ((rkaddr->rkds & RK_SVAL) == 0)
					if (++del > 512)
						break;
			}
			if (del > 512) {
E 12
				printf("rk%d is down\n", dkunit(bp));
D 12
			if (++um->um_tab.b_errcnt > 28 ||
E 12
I 12
				bp->b_flags |= B_ERROR;
			} else
#endif
E 19
D 31
			if (ds & RK_WLE) {
E 31
I 31
			if (rkdebug) {
				printf("cs2=%b ds=%b er=%b\n",
				    cs2, RKCS2_BITS, ds, 
				    RKDS_BITS, er, RKER_BITS);
			}
I 34
#endif
E 34
			if (er & RKER_WLE) {
E 31
D 21
				printf("rk%d is write locked\n", dkunit(bp));
E 21
I 21
D 63
				printf("rk%d: write locked\n", dkunit(bp));
E 63
I 63
				printf("rk%d: write locked\n",
					rkunit(bp->b_dev));
E 63
E 21
				bp->b_flags |= B_ERROR;
			} else if (++um->um_tab.b_errcnt > 28 ||
E 12
D 11
			    ds&RKDS_HARD || er&RKER_HARD || cs2&RKCS2_HARD)
E 11
I 11
			    ds&RKDS_HARD || er&RKER_HARD || cs2&RKCS2_HARD) {
I 34
hard:
E 34
E 11
D 27
				bp->b_flags |= B_ERROR;
E 27
D 11
			else
E 11
I 11
D 21
				harderr(bp);
D 17
				printf("rk%d cs2 %b ds %b er %b\n",
E 17
I 17
D 19
				printf("rk%d cs2=%b ds=%b er=%b\n",
E 17
				    dkunit(bp), cs2, RKCS2_BITS, ds, 
E 19
I 19
				printf("rk%d%c cs2=%b ds=%b er=%b\n",
				    dkunit(bp), 'a'+(minor(bp->b_dev)&07),
E 21
I 21
D 71
				harderr(bp, "rk");
				printf("cs2=%b ds=%b er=%b\n",
E 71
I 71
				diskerr(bp, "rk", "hard error", LOG_PRINTF, -1,
				    (struct disklabel *)0);
				printf(" cs2=%b ds=%b er=%b\n",
E 71
E 21
				    cs2, RKCS2_BITS, ds, 
E 19
				    RKDS_BITS, er, RKER_BITS);
I 27
				bp->b_flags |= B_ERROR;
				sc->sc_recal = 0;
I 34
			} else if (er & RKER_BSE) {
D 35
#ifndef NOBADBLOCK
E 35
I 35
D 54
#ifndef NOBADSECT
E 54
E 35
				if (rkecc(ui, BSE))
					return;
				else
D 54
#endif
E 54
					goto hard;
E 34
E 27
D 43
			} else
E 11
				um->um_tab.b_active = 0;
E 43
I 43
			} else {
				if ((er & (RKER_DCK|RKER_ECH)) == RKER_DCK) {
					if (rkecc(ui, ECC))
						return;
				} else
					um->um_tab.b_active = 0;
			}
E 43
D 11
			if (um->um_tab.b_errcnt > 27)
D 8
				deverror(bp, cs2, (ds<<8)|er);
E 8
I 8
				deverror(bp, cs2, (ds<<16)|er);
E 11
E 8
D 31
			if (cs2&RK_MDS) {
				rkaddr->rkcs2 = RK_SCLR;
E 31
I 31
			if (cs2&RKCS2_MDS) {
				rkaddr->rkcs2 = RKCS2_SCLR;
E 31
				goto retry;
E 7
E 5
			}
D 7
			er = (unsigned short)rkaddr->rker;
			ds = (unsigned short)rkaddr->rkds;
E 7
I 7
			recal = 0;
D 31
			if (ds&RK_DROT || er&(RK_OPI|RK_SKI|RK_UNS) ||
E 31
I 31
			if (ds&RKDS_DROT || er&(RKER_OPI|RKER_SKI|RKER_UNS) ||
E 31
			    (um->um_tab.b_errcnt&07) == 4)
				recal = 1;
D 31
			if ((er & (RK_DCK|RK_ECH)) == RK_DCK)
E 31
I 31
D 43
			if ((er & (RKER_DCK|RKER_ECH)) == RKER_DCK)
E 31
D 34
				if (rkecc(ui))
E 34
I 34
				if (rkecc(ui, ECC))
E 34
					return;
E 43
D 34
			rkaddr->rkcs1 = RK_CDT|RK_CCLR;
E 34
I 34
			rkaddr->rkcs1 = RK_CCLR;
E 34
			rkaddr->rkcs2 = ui->ui_slave;
D 34
			rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
E 34
I 34
			rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_DCLR|RK_GO;
E 34
			rkwait(rkaddr);
			if (recal && um->um_tab.b_active == 0) {
D 34
				rkaddr->rkcs1 = RK_CDT|RK_IE|RK_RECAL|RK_GO;
E 34
I 34
				rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_IE|RK_RECAL|RK_GO;
E 34
				rkcyl[ui->ui_unit] = -1;
D 23
				rkwait(rkaddr);
				um->um_tab.b_active = 1;
				sc->sc_recal = 1;
				return;
E 23
I 23
				sc->sc_recal = 0;
				goto nextrecal;
E 23
			}
E 7
		}
D 7
		if (rkaddr->rkds&dsabort) {
			printf("rk %d is down\n", d);
			rktab.b_errcnt = 10;
E 7
I 7
retry:
D 23
		if (sc->sc_recal) {
E 23
I 23
		switch (sc->sc_recal) {

		case 1:
			rkaddr->rkcyl = bp->b_cylin;
			rkcyl[ui->ui_unit] = bp->b_cylin;
D 34
			rkaddr->rkcs1 = RK_CDT|RK_IE|RK_SEEK|RK_GO;
E 34
I 34
			rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_IE|RK_SEEK|RK_GO;
E 34
			goto nextrecal;
D 28

E 28
		case 2:
			if (um->um_tab.b_errcnt < 16 ||
D 30
			    (bp->b_flags&B_READ) != 0)
E 30
I 30
			    (bp->b_flags&B_READ) == 0)
E 30
D 28
				break;
E 28
I 28
				goto donerecal;
E 28
			rkaddr->rkatt = rk_offset[um->um_tab.b_errcnt & 017];
D 34
			rkaddr->rkcs1 = RK_CDT|RK_IE|RK_OFFSET|RK_GO;
E 34
I 34
			rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_IE|RK_OFFSET|RK_GO;
E 34
			/* fall into ... */
		nextrecal:
			sc->sc_recal++;
			rkwait(rkaddr);
			um->um_tab.b_active = 1;
			return;
D 28

E 28
I 28
		donerecal:
E 28
		case 3:
E 23
			sc->sc_recal = 0;
			um->um_tab.b_active = 0;
I 23
			break;
E 23
E 7
		}
I 34
		ubadone(um);
E 34
D 7
		if (rkaddr->rkcs2&cs2abort) {
			printf("cs2 abort %o\n", rkaddr->rkcs2);
			rktab.b_errcnt = 10;
E 7
I 7
D 23
		ubadone(um);
E 23
		if (um->um_tab.b_active) {
			um->um_tab.b_active = 0;
			um->um_tab.b_errcnt = 0;
			um->um_tab.b_actf = dp->b_forw;
			dp->b_active = 0;
			dp->b_errcnt = 0;
			dp->b_actf = bp->av_forw;
			bp->b_resid = -rkaddr->rkwc * sizeof(short);
			iodone(bp);
			if (dp->b_actf)
D 39
				if (rkustart(ui))
					needie = 0;
E 39
I 39
				rkustart(ui);
E 39
E 7
		}
D 7
		if (rktab.b_errcnt >= 10) {
			deverror(bp, er, ds);
			printf("cn %d tn %d sn %d\n", tcn, ttn, tsn);
		}
		rkaddr->rkcs1 = CDT | DCLR | GO;
		while ((rkaddr->rkcs1&RDY)==0)
			;
		rkaddr->rkcs2 = SCLR;
		while ((rkaddr->rkcs1&RDY)==0)
			;
		if ((x=rkselect(rkaddr, d)) == 0) {
			printf("after clears\n");
			goto bad;
		}
D 5
		printf("reset\n");
E 5
		rkaddr->rkcs1 = CDT | RESET | GO;
		while (rkaddr->rkds & PIP)
			;
		if (++rktab.b_errcnt <= 10) {
D 4
			ubafree(rk_info);
E 4
I 4
			ubarelse(&rk_info);
E 4
			rkstart();
			return;
		}
bad:
		bp->b_flags |= B_ERROR;
E 7
I 7
		as &= ~(1<<ui->ui_slave);
I 33
D 34
		ubadone(um);
E 34
E 33
E 7
	}
I 19
D 23
att:
E 23
E 19
D 7
	rktab.b_errcnt = 0;
	rktab.b_actf = bp->av_forw;
	bp->b_resid = 0;
D 4
	ubafree(rk_info);
E 4
I 4
	ubarelse(&rk_info);
E 4
	iodone(bp);
	rkstart();
E 7
I 7
	for (unit = 0; as; as >>= 1, unit++)
D 24
		if (as & 1)
			if (rkustart(rkip[rk11][unit]))
				needie = 0;
E 24
I 24
		if (as & 1) {
			ui = rkip[rk11][unit];
			if (ui) {
D 39
				if (rkustart(rkip[rk11][unit]))
					needie = 0;
E 39
I 39
				rkustart(rkip[rk11][unit]);
E 39
			} else {
D 34
				rkaddr->rkcs1 = RK_CERR|RK_CDT;
E 34
I 34
				rkaddr->rkcs1 = RK_CCLR;
E 34
				rkaddr->rkcs2 = unit;
D 34
				rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
E 34
I 34
				rkaddr->rkcs1 = RK_DCLR|RK_GO;
E 34
				rkwait(rkaddr);
I 34
				rkaddr->rkcs1 = RK_CCLR;
E 34
			}
		}
E 24
	if (um->um_tab.b_actf && um->um_tab.b_active == 0)
D 39
		if (rkstart(um))
			needie = 0;
	if (needie)
E 39
I 39
		rkstart(um);
D 51
	if (((needie = rkaddr->rkcs1) & RK_IE) == 0)
E 51
I 51
	if (((rkaddr->rkcs1) & RK_IE) == 0)
E 51
E 39
D 34
		rkaddr->rkcs1 = RK_CDT|RK_IE;
E 34
I 34
		rkaddr->rkcs1 = RK_IE;
E 34
I 19
D 20
	if ((rkaddr->rkcs1 & RK_IE) == 0) {
		printf("cs1 %o not ie\n", rkaddr->rkcs1);
		rkaddr->rkcs1 |= RK_CDT|RK_IE;
	}
E 20
E 19
E 7
}

I 7
rkwait(addr)
	register struct rkdevice *addr;
{
E 7

D 7
rkselect(rkaddr, d)
register struct device *rkaddr;
E 7
I 7
	while ((addr->rkcs1 & RK_CRDY) == 0)
		;
D 70
}

D 45
rkread(dev)
E 45
I 45
rkread(dev, uio)
E 45
	dev_t dev;
I 45
	struct uio *uio;
E 45
E 7
{
D 7
	rkaddr->rkcs2 = d;
	rkaddr->rkcs1 = CDT|GO;
	return(rkwait(rkaddr));
E 7
I 7
D 63
	register int unit = minor(dev) >> 3;
E 63
I 63
D 64
	register int unit = idcunit(dev);
E 64
I 64
	register int unit = rkunit(dev);
E 64
E 63

D 9
	if (unit >= NRK07)
E 9
I 9
	if (unit >= NRK)
E 9
D 47
		u.u_error = ENXIO;
	else
D 45
		physio(rkstrategy, &rrkbuf[unit], dev, B_READ, minphys);
E 45
I 45
		physio(rkstrategy, &rrkbuf[unit], dev, B_READ, minphys, uio);
E 47
I 47
		return (ENXIO);
	return (physio(rkstrategy, &rrkbuf[unit], dev, B_READ, minphys, uio));
E 47
E 45
E 7
}

D 7
rkwait(rkaddr)
register struct device *rkaddr;
E 7
I 7
D 46
rkwrite(dev)
E 46
I 46
rkwrite(dev, uio)
E 46
	dev_t dev;
I 46
	struct uio *uio;
E 46
E 7
{
D 7
register t;
E 7
I 7
D 63
	register int unit = minor(dev) >> 3;
E 63
I 63
D 64
	register int unit = idcunit(dev);
E 64
I 64
	register int unit = rkunit(dev);
E 64
E 63
E 7

D 7
	for(t=0x8000; t && ((rkaddr->rkds&DRDY)==0); t--)
		;
	if (t==0)
		printf("rk not ready\n");
	return(t);
E 7
I 7
D 9
	if (unit >= NRK07)
E 9
I 9
	if (unit >= NRK)
E 9
D 49
		u.u_error = ENXIO;
	else
D 45
		physio(rkstrategy, &rrkbuf[unit], dev, B_WRITE, minphys);
E 45
I 45
D 46
		physio(rkstrategy, &rrkbuf[unit], dev, B_WRITE, minphys, 0);
E 46
I 46
		physio(rkstrategy, &rrkbuf[unit], dev, B_WRITE, minphys, uio);
E 49
I 49
		return (ENXIO);
	return (physio(rkstrategy, &rrkbuf[unit], dev, B_WRITE, minphys, uio));
E 70
E 49
E 46
E 45
E 7
}

D 7
rkread(dev)
dev_t dev;
E 7
I 7
D 34
rkecc(ui)
E 34
I 34
rkecc(ui, flag)
E 34
D 24
	register struct uba_dinfo *ui;
E 24
I 24
	register struct uba_device *ui;
E 24
E 7
{
I 7
	register struct rkdevice *rk = (struct rkdevice *)ui->ui_addr;
	register struct buf *bp = rkutab[ui->ui_unit].b_actf;
D 24
	register struct uba_minfo *um = ui->ui_mi;
E 24
I 24
	register struct uba_ctlr *um = ui->ui_mi;
E 24
	register struct rkst *st;
	struct uba_regs *ubp = ui->ui_hd->uh_uba;
D 34
	register int i;
E 34
	caddr_t addr;
D 34
	int reg, bit, byte, npf, mask, o, cmd, ubaddr;
E 34
I 34
	int reg, npf, o, cmd, ubaddr;
E 34
	int bn, cn, tn, sn;
E 7

D 7
	physio(rkstrategy, &rrkbuf, dev, B_READ, minphys);
E 7
I 7
D 34
	npf = btop((rk->rkwc * sizeof(short)) + bp->b_bcount) - 1;
E 34
I 34
D 35
#ifndef NOBADBLOCK
E 35
I 35
D 54
#ifndef NOBADSECT
E 54
E 35
	if (flag == CONT)
		npf = bp->b_error;
	else
D 54
#endif
E 54
D 67
		npf = btop((rk->rkwc * sizeof(short)) + bp->b_bcount);
E 67
I 67
		npf = btodb(bp->b_bcount + (rk->rkwc * sizeof(short)) + 511);
E 67
E 34
D 72
	reg = btop(um->um_ubinfo&0x3ffff) + npf;
E 72
I 72
	reg = btop(UBAI_ADDR(um->um_ubinfo)) + npf;
E 72
	o = (int)bp->b_un.b_addr & PGOFSET;
D 18
	printf("%D ", bp->b_blkno+npf);
	prdev("ECC", bp->b_dev);
E 18
I 18
D 19
	printf("SOFT ECC rk%d%c bn%d\n", dkunit(bp),
E 19
I 19
D 21
	printf("soft ecc rk%d%c bn%d\n", dkunit(bp),
E 21
I 21
D 22
	printf("rk%d%c: soft ecc bn%d\n", dkunit(bp),
E 22
I 22
D 34
	printf("rk%d%c: soft ecc sn%d\n", dkunit(bp),
E 22
E 21
E 19
	    'a'+(minor(bp->b_dev)&07), bp->b_blkno + npf);
E 18
	mask = rk->rkec2;
D 17
	if (mask == 0) {
		rk->rkatt = 0;
		return (0);
	}
E 17
D 15
	ubp->uba_dpr[(um->um_ubinfo>>28)&0x0f] |= UBA_BNE;
E 15
I 15
	ubapurge(um);
E 15
	i = rk->rkec1 - 1;		/* -1 makes 0 origin */
I 10
D 14
	printf("mask %x pos %x\n", mask, i+1);
E 14
E 10
	bit = i&07;
	i = (i&~07)>>3;
	byte = i + o;
	while (i < 512 && (int)ptob(npf)+i < bp->b_bcount && bit > -11) {
		addr = ptob(ubp->uba_map[reg+btop(byte)].pg_pfnum)+
		    (byte & PGOFSET);
		putmemc(addr, getmemc(addr)^(mask<<bit));
		byte++;
		i++;
		bit -= 8;
	}
	um->um_tab.b_active++;	/* Either complete or continuing... */
	if (rk->rkwc == 0)
		return (0);
I 8
#ifdef notdef
	rk->rkcs1 |= RK_GO;
#else
E 8
	rk->rkcs1 = RK_CDT|RK_CCLR;
	rk->rkcs2 = ui->ui_slave;
	rk->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
	rkwait(rk);
E 34
D 63
	bn = dkblock(bp);
E 63
I 63
	bn = bp->b_blkno;
E 63
	st = &rkst[ui->ui_type];
	cn = bp->b_cylin;
D 34
	sn = bn%st->nspc + npf + 1;
E 34
I 34
	sn = bn%st->nspc + npf;
E 34
	tn = sn/st->nsect;
	sn %= st->nsect;
	cn += tn/st->ntrak;
	tn %= st->ntrak;
I 34
	ubapurge(um);
D 39
	um->um_tab.b_active++;	/* Either complete or continuing... */
E 39
I 39
D 42
	um->um_tab.b_active = 2;	/* Either complete or continuing... */
E 42
E 39
	switch (flag) {
	case ECC:
		{
		register int i;
		int bit, byte, mask;

		npf--;
		reg--;
D 60
		printf("rk%d%c: soft ecc sn%d\n", dkunit(bp),
E 60
I 60
D 63
		log(KERN_RECOV, "rk%d%c: soft ecc sn%d\n", dkunit(bp),
E 63
I 63
D 65
		log(KERN_RECOV, "rk%d%c: soft ecc sn%d\n", rkunit(bp->b_dev),
E 65
I 65
D 71
		log(LOG_WARNING, "rk%d%c: soft ecc sn%d\n", rkunit(bp->b_dev),
E 65
E 63
E 60
		    'a'+(minor(bp->b_dev)&07), bp->b_blkno + npf);
E 71
I 71
		diskerr(bp, "rk", "soft ecc", LOG_WARNING, npf,
		    (struct disklabel *)0);
		addlog("\n");
E 71
		mask = rk->rkec2;
		i = rk->rkec1 - 1;		/* -1 makes 0 origin */
		bit = i&07;
		i = (i&~07)>>3;
		byte = i + o;
D 67
		while (i < 512 && (int)ptob(npf)+i < bp->b_bcount && bit > -11) {
E 67
I 67
		while (i < 512 && (int)dbtob(npf)+i < bp->b_bcount && bit > -11) {
E 67
			addr = ptob(ubp->uba_map[reg+btop(byte)].pg_pfnum)+
			    (byte & PGOFSET);
			putmemc(addr, getmemc(addr)^(mask<<bit));
			byte++;
			i++;
			bit -= 8;
		}
D 43
		if (rk->rkwc == 0)
E 43
I 43
		if (rk->rkwc == 0) {
			um->um_tab.b_active = 0;
E 43
			return (0);
I 43
		}
E 43
		npf++;
		reg++;
		break;
		}

D 35
#ifndef NOBADBLOCK
E 35
I 35
D 54
#ifndef NOBADSECT
E 54
E 35
	case BSE:
#ifdef RKBDEBUG
		if (rkbdebug)
	printf("rkecc, BSE: bn %d cn %d tn %d sn %d\n", bn, cn, tn, sn);
#endif
		if ((bn = isbad(&rkbad[ui->ui_unit], cn, tn, sn)) < 0)
			return(0);
		bp->b_flags |= B_BAD;
		bp->b_error = npf + 1;
		bn = st->ncyl*st->nspc - st->nsect - 1 - bn;
		cn = bn/st->nspc;
		sn = bn%st->nspc;
		tn = sn/st->nsect;
		sn %= st->nsect;
#ifdef RKBDEBUG
		if (rkbdebug)
	printf("revector to cn %d tn %d sn %d\n", cn, tn, sn);
#endif
		rk->rkwc = -(512 / sizeof (short));
		break;

	case CONT:
#ifdef RKBDEBUG
		if (rkbdebug)
	printf("rkecc, CONT: bn %d cn %d tn %d sn %d\n", bn,cn,tn,sn);
#endif
		bp->b_flags &= ~B_BAD;
D 67
		rk->rkwc = -((bp->b_bcount - (int)ptob(npf)) / sizeof (short));
D 43
		if (rk->rkwc == 0)
			return(0);
E 43
I 43
D 58
		if (rk->rkwc == 0) {
			um->um_tab.b_active = 0;
E 58
I 58
		if (rk->rkwc == 0)
E 67
I 67
		if ((int)dbtob(npf) >= bp->b_bcount)
E 67
E 58
			return (0);
I 67
		rk->rkwc = -((bp->b_bcount - (int)dbtob(npf)) / sizeof (short));
E 67
D 58
		}
E 58
E 43
		break;
D 54
#endif
E 54
	}
	rk->rkcs1 = RK_CCLR;
	rk->rkcs2 = ui->ui_slave;
	rk->rkcs1 = rktypes[ui->ui_type]|RK_DCLR|RK_GO;
	rkwait(rk);
E 34
	rk->rkcyl = cn;
	rk->rkda = (tn << 8) | sn;
D 34
	ubaddr = (int)ptob(reg+1) + o;
E 34
I 34
	ubaddr = (int)ptob(reg) + o;
E 34
	rk->rkba = ubaddr;
D 34
	cmd = (ubaddr >> 8) & 0x300;
	cmd |= RK_CDT|RK_IE|RK_GO|RK_READ;
E 34
I 34
	cmd = (bp->b_flags&B_READ ? RK_READ : RK_WRITE)|RK_IE|RK_GO;
	cmd |= (ubaddr >> 8) & 0x300;
	cmd |= rktypes[ui->ui_type];
E 34
	rk->rkcs1 = cmd;
I 42
	um->um_tab.b_active = 2;	/* continuing */
E 42
I 8
D 34
#endif
E 34
I 34
	um->um_tab.b_errcnt = 0;	/* error has been corrected */
E 34
E 8
	return (1);
E 7
}

D 7
rkwrite(dev)
dev_t dev;
E 7
I 7
D 8
/*
 * Reset driver after UBA init.
 * Cancel software state of all pending transfers
 * and restart all units and the controller.
 */
E 8
rkreset(uban)
I 21
	int uban;
E 21
E 7
{
I 7
D 24
	register struct uba_minfo *um;
	register struct uba_dinfo *ui;
E 24
I 24
	register struct uba_ctlr *um;
	register struct uba_device *ui;
E 24
	register rk11, unit;
D 21
	int any = 0;
E 21
E 7

D 7
	physio(rkstrategy, &rrkbuf, dev, B_WRITE, minphys);
E 7
I 7
D 9
	for (rk11 = 0; rk11 < NRK11; rk11++) {
E 9
I 9
	for (rk11 = 0; rk11 < NHK; rk11++) {
E 9
		if ((um = rkminfo[rk11]) == 0 || um->um_ubanum != uban ||
		    um->um_alive == 0)
			continue;
D 21
		if (any == 0) {
			printf(" rk");
			any++;
		}
E 21
I 21
		printf(" hk%d", rk11);
E 21
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
		rk_softc[um->um_ctlr].sc_recal = 0;
I 39
		rk_softc[um->um_ctlr].sc_wticks = 0;
E 39
		if (um->um_ubinfo) {
			printf("<%d>", (um->um_ubinfo>>28)&0xf);
D 52
			ubadone(um);
E 52
I 52
			um->um_ubinfo = 0;
E 52
		}
D 9
		((struct rkdevice *)(um->um_addr))->rkcs1 = RK_CDT|RK_CCLR;
		rkwait((struct rkdevice *)(um->um_addr));
		for (unit = 0; unit < NRK11; unit++) {
E 9
I 9
D 36
		for (unit = 0; unit < NHK; unit++) {
E 36
I 36
		for (unit = 0; unit < NRK; unit++) {
E 36
E 9
			if ((ui = rkdinfo[unit]) == 0)
				continue;
D 36
			if (ui->ui_alive == 0)
E 36
I 36
			if (ui->ui_alive == 0 || ui->ui_mi != um)
E 36
				continue;
			rkutab[unit].b_active = 0;
			(void) rkustart(ui);
		}
		(void) rkstart(um);
	}
E 7
}
I 6

D 7
rkdump()
E 7
I 7
D 8
/*
 * Wake up every second and if an interrupt is pending
 * but nothing has happened increment a counter.
 * If nothing happens for 20 seconds, reset the controller
 * and begin anew.
 */
E 8
rkwatch()
E 7
{
I 7
D 24
	register struct uba_minfo *um;
E 24
I 24
	register struct uba_ctlr *um;
E 24
	register rk11, unit;
	register struct rk_softc *sc;
E 7

D 7
	printf("don't know how to dump to rk (yet)\n");
E 7
I 7
D 16
	timeout(rkwatch, (caddr_t)0, HZ);
E 16
I 16
	timeout(rkwatch, (caddr_t)0, hz);
E 16
D 9
	for (rk11 = 0; rk11 < NRK11; rk11++) {
E 9
I 9
	for (rk11 = 0; rk11 < NHK; rk11++) {
E 9
		um = rkminfo[rk11];
		if (um == 0 || um->um_alive == 0)
			continue;
		sc = &rk_softc[rk11];
		if (um->um_tab.b_active == 0) {
D 9
			for (unit = 0; unit < NRK07; unit++)
E 9
I 9
			for (unit = 0; unit < NRK; unit++)
E 9
D 8
				if (rkdinfo[unit]->ui_mi == um &&
				    rkutab[unit].b_active)
E 8
I 8
				if (rkutab[unit].b_active &&
				    rkdinfo[unit]->ui_mi == um)
E 8
					goto active;
			sc->sc_wticks = 0;
			continue;
		}
active:
		sc->sc_wticks++;
		if (sc->sc_wticks >= 20) {
			sc->sc_wticks = 0;
D 9
			printf("LOST INTERRUPT RESET");
			/* SHOULD JUST RESET ONE CTLR, NOT ALL ON UBA */
			rkreset(um->um_ubanum);
			printf("\n");
E 9
I 9
D 19
			printf("LOST rkintr ");
E 19
I 19
D 21
			printf("lost rkintr ");
E 21
I 21
			printf("hk%d: lost interrupt\n", rk11);
E 21
E 19
			ubareset(um->um_ubanum);
E 9
		}
	}
}

#define	DBSIZE	20

rkdump(dev)
	dev_t dev;
{
	struct rkdevice *rkaddr;
	char *start;
	int num, blk, unit;
	struct size *sizes;
	register struct uba_regs *uba;
D 24
	register struct uba_dinfo *ui;
E 24
I 24
	register struct uba_device *ui;
E 24
	register short *rp;
	struct rkst *st;

D 63
	unit = minor(dev) >> 3;
E 63
I 63
D 64
	unit = idcunit(dev);
E 64
I 64
	unit = rkunit(dev);
E 64
E 63
D 9
	if (unit >= NRK07) {
E 9
I 9
D 18
	if (unit >= NRK) {
E 9
		printf("bad unit\n");
		return (-1);
	}
E 18
I 18
	if (unit >= NRK)
		return (ENXIO);
E 18
#define	phys(cast, addr) ((cast)((int)addr & 0x7fffffff))
D 24
	ui = phys(struct uba_dinfo *, rkdinfo[unit]);
E 24
I 24
	ui = phys(struct uba_device *, rkdinfo[unit]);
E 24
D 18
	if (ui->ui_alive == 0) {
		printf("dna\n");
		return(-1);
	}
E 18
I 18
	if (ui->ui_alive == 0)
		return (ENXIO);
E 18
	uba = phys(struct uba_hd *, ui->ui_hd)->uh_physuba;
D 32
#if VAX780
	if (cpu == VAX_780)
		ubainit(uba);
#endif
E 32
I 32
	ubainit(uba);
E 32
	rkaddr = (struct rkdevice *)ui->ui_physaddr;
	num = maxfree;
	start = 0;
D 34
	rkaddr->rkcs1 = RK_CDT|RK_CERR;
E 34
I 34
	rkaddr->rkcs1 = RK_CCLR;
E 34
	rkaddr->rkcs2 = unit;
D 34
	rkaddr->rkcs1 = RK_CDT|RK_DCLR|RK_GO;
E 34
I 34
	rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_DCLR|RK_GO;
E 34
	rkwait(rkaddr);
D 31
	if ((rkaddr->rkds & RK_VV) == 0) {
E 31
I 31
	if ((rkaddr->rkds & RKDS_VV) == 0) {
E 31
D 34
		rkaddr->rkcs1 = RK_CDT|RK_IE|RK_PACK|RK_GO;
E 34
I 34
		rkaddr->rkcs1 = rktypes[ui->ui_type]|RK_IE|RK_PACK|RK_GO;
E 34
		rkwait(rkaddr);
	}
	st = &rkst[ui->ui_type];
	sizes = phys(struct size *, st->sizes);
D 18
	if (dumplo < 0 || dumplo + num >= sizes[minor(dev)&07].nblocks) {
		printf("oor\n");
		return (-1);
	}
E 18
I 18
D 62
	if (dumplo < 0 || dumplo + num >= sizes[minor(dev)&07].nblocks)
E 62
I 62
	if (dumplo < 0)
E 62
		return (EINVAL);
I 62
	if (dumplo + num >= sizes[minor(dev)&07].nblocks)
		num = sizes[minor(dev)&07].nblocks - dumplo;
E 62
E 18
	while (num > 0) {
		register struct pte *io;
		register int i;
		int cn, sn, tn;
		daddr_t bn;

		blk = num > DBSIZE ? DBSIZE : num;
		io = uba->uba_map;
		for (i = 0; i < blk; i++)
D 24
			*(int *)io++ = (btop(start)+i) | (1<<21) | UBA_MRV;
E 24
I 24
			*(int *)io++ = (btop(start)+i) | (1<<21) | UBAMR_MRV;
E 24
		*(int *)io = 0;
		bn = dumplo + btop(start);
		cn = bn/st->nspc + sizes[minor(dev)&07].cyloff;
		sn = bn%st->nspc;
		tn = sn/st->nsect;
		sn = sn%st->nsect;
		rkaddr->rkcyl = cn;
		rp = (short *) &rkaddr->rkda;
		*rp = (tn << 8) + sn;
		*--rp = 0;
		*--rp = -blk*NBPG / sizeof (short);
D 34
		*--rp = RK_CDT|RK_GO|RK_WRITE;
E 34
I 34
		*--rp = rktypes[ui->ui_type]|RK_GO|RK_WRITE;
E 34
		rkwait(rkaddr);
D 18
		if (rkaddr->rkcs1 & RK_CERR) {
	printf("rk dump dsk err: (%d,%d,%d) cs1=%x, ds=%x, er1=%x\n",
			    cn, tn, sn,
			    rkaddr->rkcs1&0xffff, rkaddr->rkds&0xffff,
			    rkaddr->rker&0xffff);
			return (-1);
		}
E 18
I 18
		if (rkaddr->rkcs1 & RK_CERR)
			return (EIO);
E 18
		start += blk*NBPG;
		num -= blk;
	}
	return (0);
E 7
}
I 56
 
rksize(dev)
	dev_t dev;
{
D 63
	int unit = minor(dev) >> 3;
E 63
I 63
D 64
	int unit = idcunit(dev);
E 64
I 64
	int unit = rkunit(dev);
E 64
E 63
	struct uba_device *ui;
	struct rkst *st;

	if (unit >= NRK || (ui = rkdinfo[unit]) == 0 || ui->ui_alive == 0)
		return (-1);
	st = &rkst[ui->ui_type];
	return (st->sizes[minor(dev) & 07].nblocks);
}
E 56
E 6
#endif
E 1
