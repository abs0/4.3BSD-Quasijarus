h26877
s 00001/00001/00976
d D 7.6 88/08/27 07:20:53 tef 53 52
c Add support for microvax 3000.
e
s 00004/00028/00973
d D 7.5 88/05/06 17:16:38 bostic 52 51
c changes for raw{read,write} stuff
e
s 00003/00001/00998
d D 7.4 87/11/12 17:22:36 bostic 51 50
c hangs after hard I/O error in some cases; fix from Chris Torek
e
s 00308/00264/00691
d D 7.3 87/11/03 10:08:43 bostic 50 49
c new version from Chris Torek
e
s 00018/00004/00937
d D 7.2 87/04/17 14:10:00 karels 49 48
c fix race in open; log excessive soft errs
e
s 00001/00001/00940
d D 7.1 86/06/05 01:18:34 mckusick 48 47
c 4.3BSD release version
e
s 00003/00001/00938
d D 6.10 86/04/22 11:04:52 kridle 47 46
c MicroVAX II Integration (KA630)
e
s 00001/00001/00938
d D 6.9 86/02/20 19:54:09 karels 46 45
c lint
e
s 00006/00000/00933
d D 6.8 86/02/11 17:38:58 karels 45 44
c bug fix from Emulex: don't feed controller low bit if UBA
c is doing byte-offset mode (on BDP's only!)
e
s 00003/00002/00930
d D 6.7 85/10/01 09:42:24 karels 44 43
c no ENXIO if busy
e
s 00001/00001/00931
d D 6.6 85/08/12 18:56:40 bloom 43 42
c don't allow open O_RDWR if no write ring
e
s 00007/00001/00925
d D 6.5 85/06/08 14:24:16 mckusick 42 41
c Add copyright
e
s 00016/00008/00910
d D 6.4 85/03/13 09:44:59 ralph 41 40
c change error message printf's to tprintf's to the user.
e
s 00001/00000/00917
d D 6.3 84/11/27 15:34:59 karels 40 39
c force communications area to be remapped after uba reset (from Jim McKie)
e
s 00016/00016/00901
d D 6.2 84/08/29 20:10:32 bloom 39 38
c Change to includes.  No more ../h
e
s 00000/00000/00917
d D 6.1 83/07/29 07:29:20 sam 38 37
c 4.2 distribution
e
s 00002/00001/00915
d D 4.37 82/12/17 12:03:59 sam 37 36
c sun merge
e
s 00001/00001/00915
d D 4.36 82/11/26 18:17:41 sam 36 35
c don't call ubadone at ubareset time
e
s 00001/00001/00915
d D 4.35 82/10/20 01:42:50 root 35 34
c lint
e
s 00001/00002/00915
d D 4.34 82/10/17 23:06:44 root 34 33
c lint
e
s 00002/00002/00915
d D 4.33 82/10/17 22:04:44 root 33 32
c lint
e
s 00001/00001/00916
d D 4.32 82/10/17 20:18:48 root 32 31
c lint
e
s 00017/00026/00900
d D 4.31 82/10/17 11:51:02 root 31 30
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00004/00004/00922
d D 4.30 82/10/10 17:29:00 root 30 29
c header files for vax are in their place
e
s 00010/00008/00916
d D 4.29 82/09/12 03:09:39 root 29 28
c 
e
s 00006/00010/00918
d D 4.28 82/08/22 21:20:16 root 28 27
c fully uio()'d
e
s 00015/00008/00913
d D 4.27 82/08/13 00:17:13 root 27 26
c changes for char dev uio'ing
e
s 00023/00020/00898
d D 4.26 82/08/01 19:26:20 sam 26 25
c new ioctl's
e
s 00001/00001/00917
d D 4.25 82/07/15 19:56:21 kre 25 24
c probe routines return size of unibus dev regs to reserve space
e
s 00013/00013/00905
d D 4.24 82/07/13 18:14:40 sam 24 23
c bdbtofsb maps block device blocks DEV_BSIZE units
e
s 00001/00000/00917
d D 4.23 82/02/03 19:54:53 root 23 22
c deleted something in merging
e
s 00046/00093/00871
d D 4.22 82/02/03 19:35:15 root 22 21
c mods from shannon finally installed
e
s 00006/00004/00958
d D 4.21 82/01/17 20:28:52 root 21 20
c remove spl0's from block tape routines
e
s 00004/00007/00958
d D 4.20 81/11/18 15:50:34 wnj 20 19
c lint
e
s 00001/00001/00964
d D 4.19 81/07/09 04:28:03 root 19 18
c lint
e
s 00001/00001/00964
d D 4.18 81/07/09 04:14:10 root 18 17
c lint
e
s 00001/00000/00964
d D 4.17 81/07/09 04:04:55 root 17 16
c put in missing return(1) in tsprobe();
e
s 00001/00001/00963
d D 4.16 81/05/10 01:25:40 root 16 15
c () error
e
s 00007/00005/00957
d D 4.15 81/05/09 22:34:14 root 15 14
c better error messages; fix to lastiow=1 bug; init device after offline
e
s 00001/00001/00961
d D 4.14 81/05/08 21:53:04 wnj 14 13
c re-initialize tape drive after it was offline
e
s 00002/00005/00960
d D 4.13 81/05/05 21:53:04 wnj 13 12
c fix bugs in ts ioctl stuff
e
s 00035/00001/00930
d D 4.12 81/05/03 19:58:44 wnj 12 11
c fix up error prints and also bug in fsf/bsf ioctl
e
s 00001/00001/00930
d D 4.11 81/04/15 11:35:05 wnj 11 10
c typo
e
s 00009/00000/00922
d D 4.10 81/04/14 14:20:35 root 10 9
c fix for generic interlocking tm and ts
e
s 00001/00000/00921
d D 4.9 81/04/03 07:38:49 toy 9 8
c Added type to MTIOCGET ioctl.
e
s 00047/00019/00874
d D 4.8 81/03/21 15:51:30 wnj 8 7
c add ts
e
s 00752/00343/00141
d D 4.7 81/03/13 21:48:33 wnj 7 6
c shannons version
e
s 00001/00001/00483
d D 4.6 81/03/09 01:54:47 wnj 6 5
c %G% -> %E%
e
s 00005/00009/00479
d D 4.5 80/12/30 18:51:55 wnj 5 4
c ubafree() becomes ubarelse() to fix race conditions
e
s 00006/00002/00482
d D 4.4 80/12/20 01:01:16 wnj 4 3
c minor typos from merging with dump
e
s 00001/00001/00483
d D 4.3 80/12/19 11:46:00 wnj 3 2
c s,../conf/,,
e
s 00112/00025/00372
d D 4.2 80/12/17 18:35:16 wnj 2 1
c tdump in the driver
e
s 00397/00000/00000
d D 4.1 80/12/17 10:43:04 wnj 1 0
c date and time created 80/12/17 10:43:04 by wnj
e
u
U
t
T
I 1
D 6
/*	%M%	%I%	%G%	*/
E 6
I 6
D 42
/*	%M%	%I%	%E%	*/
E 42
I 42
/*
D 48
 * Copyright (c) 1982 Regents of the University of California.
E 48
I 48
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 48
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 42
E 6

D 3
#include "../conf/ts.h"
E 3
I 3
#include "ts.h"
I 10
D 11
#include "tm.h"
E 11
I 11
D 22
#include "te.h"
E 22
E 11
E 10
E 3
#if NTS > 0
I 12
D 22
#if TSDEBUG
E 12
I 8
#define printd if(tsdebug)printf
int tsdebug;
I 12
#endif
E 22
E 12
E 8
/*
 * TS11 tape driver
I 7
 *
I 50
 * NB: This driver takes advantage of the fact that there is only one
 *	drive per controller.
 *
E 50
 * TODO:
D 22
 *	test driver with more than one controller
 *	test reset code
 *	test dump code
 *	test rewinds without hanging in driver
 *	what happens if you offline tape during rewind?
 *	test using file system on tape
E 22
I 22
D 50
 *	write dump code
E 50
I 50
 *	test dump code
E 50
E 22
E 7
 */
I 37
D 49
#include "../machine/pte.h"

E 49
E 37
D 7

E 7
D 39
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
D 7
#include "../h/conf.h"
E 7
#include "../h/dir.h"
D 7
#include "../h/file.h"
E 7
I 7
#include "../h/conf.h"
E 7
#include "../h/user.h"
D 7
#include "../h/pte.h"
E 7
I 7
#include "../h/file.h"
E 7
#include "../h/map.h"
D 7
#include "../h/uba.h"
E 7
I 7
D 37
#include "../h/pte.h"
E 37
E 7
I 4
#include "../h/vm.h"
I 7
D 30
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 30
D 26
#include "../h/mtio.h"
E 26
#include "../h/ioctl.h"
I 26
#include "../h/mtio.h"
E 26
#include "../h/cmap.h"
D 30
#include "../h/cpu.h"
E 30
I 27
#include "../h/uio.h"
E 39
I 39
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "dir.h"
#include "conf.h"
#include "user.h"
#include "file.h"
#include "map.h"
#include "vm.h"
#include "ioctl.h"
#include "mtio.h"
#include "cmap.h"
#include "uio.h"
I 41
#include "tty.h"
I 49
#include "syslog.h"
E 49
E 41
E 39
E 27
E 7
E 4

I 49
#include "../machine/pte.h"
E 49
D 2
typedef	unsigned short ushort;

E 2
D 7
struct	device {
D 2
	ushort	tsdb;
	ushort	tssr;
E 2
I 2
	u_short	tsdb;
	u_short	tssr;
E 2
};
E 7
I 7
D 30
#include "../h/tsreg.h"
E 30
I 30
#include "../vax/cpu.h"
D 39
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
#include "../vaxuba/tsreg.h"
E 39
I 39
#include "ubareg.h"
#include "ubavar.h"
#include "tsreg.h"
E 39
E 30
E 7

D 7
struct	buf	tstab;
struct	buf	rtsbuf;
struct	buf	ctsbuf;
E 7
I 7
/*
 * There is a ctsbuf per tape controller.
 * It is used as the token to pass to the internal routines
 * to execute tape ioctls.
 * In particular, when the tape is rewinding on close we release
 * the user process but any further attempts to use the tape drive
 * before the rewind completes will hang waiting for ctsbuf.
 */
struct	buf	ctsbuf[NTS];
E 7

D 7
#define	INF	1000000000
E 7
I 7
/*
D 52
 * Raw tape operations use rtsbuf.  The driver
 * notices when rtsbuf is being used and allows the user
 * program to continue after errors and read records
 * not of the standard length (BSIZE).
 */
struct	buf	rtsbuf[NTS];
E 7

D 2
ushort	ts_uba;
E 2
I 2
D 7
u_short	ts_uba;
E 2
D 5
long	ts_iouba;
E 5
I 5
int	ts_ubinfo;
E 5
char	ts_flags;
char	ts_openf;
daddr_t	ts_blkno;
daddr_t	ts_nxrec;
E 7
I 7
/*
E 52
 * Driver unibus interface routines and variables.
 */
int	tsprobe(), tsslave(), tsattach(), tsdgo(), tsintr();
struct	uba_ctlr *tsminfo[NTS];
struct	uba_device *tsdinfo[NTS];
I 8
D 22
struct buf	tsbuf[NTS];
E 22
I 22
struct buf	tsutab[NTS];
E 22
E 8
u_short	tsstd[] = { 0772520, 0 };
D 50
/*** PROBABLY DON'T NEED ALL THESE SINCE CONTROLLER == DRIVE ***/
E 50
I 50
/* need all these even though controller == drive */
E 50
struct	uba_driver zsdriver =
D 8
 { tsprobe, tsslave, tsattach, tsdgo, tsstd, "ts", tsdinfo, "ts", tsminfo, 0 };
E 8
I 8
D 50
 { tsprobe, tsslave, tsattach, tsdgo, tsstd, "ts", tsdinfo, "zs", tsminfo, 0 };
E 50
I 50
 { tsprobe, tsslave, tsattach, tsdgo, tsstd, "ts", tsdinfo, "zs", tsminfo };
E 50
E 8
E 7

D 7
/* status message */
struct	sts {
D 2
	ushort	s_sts;
	ushort	len;
	ushort	rbpcr;
	ushort	xs0;
	ushort	xs1;
	ushort	xs2;
	ushort	xs3;
E 2
I 2
	u_short	s_sts;
I 4
	u_short	len;
	u_short rbpcr;
E 4
	u_short	xs0;
	u_short	xs1;
	u_short	xs2;
	u_short	xs3;
E 2
};
E 7
I 7
/* bits in minor device */
#define	TSUNIT(dev)	(minor(dev)&03)
#define	T_NOREWIND	04
I 50
#define	T_1600BPI	010
E 50
E 7

D 7
/* Error codes in stat 0 */
#define	TMK	0100000
#define	RLS	040000
#define	ONL	0100
#define	WLE	04000
E 7
I 7
#define	INF	(daddr_t)1000000L
E 7

D 7
/* command message */
struct cmd {
D 2
	ushort	c_cmd;
	ushort	c_loba;
	ushort	c_hiba;
	ushort	c_size;
E 2
I 2
	u_short	c_cmd;
	u_short	c_loba;
	u_short	c_hiba;
	u_short	c_size;
E 2
};
E 7
I 7
/*
 * Software state per tape transport.
 * Also contains hardware state in message packets.
 *
 * 1. A tape drive is a unique-open device; we refuse opens when it is already.
 * 2. We keep track of the current position on a block tape and seek
 *    before operations by forward/back spacing if necessary.
 * 3. We remember if the last operation was a write on a tape, so if a tape
 *    is open read write and the last thing done is a write we can
 *    write a standard end of tape mark (two eofs).
 * 4. We remember the status registers after the last command, using
 *    then internally and returning them to the SENSE ioctl.
 */
I 50
struct	ts_tsdata {		/* data shared with ts11 controller */
	struct	ts_cmd t_cmd;	/* the command packet (must be first) */
	struct	ts_sts t_sts;	/* status packet, for returned status */
	struct	ts_char t_char;	/* characteristics packet */
};
E 50
struct	ts_softc {
	char	sc_openf;	/* lock against multiple opens */
	char	sc_lastiow;	/* last op was a write */
I 8
	short	sc_resid;	/* copy of last bc */
E 8
	daddr_t	sc_blkno;	/* block number, for block device tape */
	daddr_t	sc_nxrec;	/* position of end of tape, if known */
D 8
	short	sc_resid;	/* copy of last bc */
E 8
D 22
	struct ts_cmd sc_cmd;	/* the command packet - ADDR MUST BE 0 MOD 4 */
	struct ts_sts sc_sts;	/* status packet, for returned status */
	struct ts_char sc_char;	/* characteristics packet */
	u_short	sc_uba;		/* Unibus addr of cmd pkt for tsdb */
E 22
I 22
D 50
	struct	ts_cmd sc_cmd;	/* the command packet */
	struct	ts_sts sc_sts;	/* status packet, for returned status */
	struct	ts_char sc_char; /* characteristics packet */
	struct	ts_softc *sc_ubaddr; /* Unibus address of ts_softc structure */
E 50
I 50
	struct	ts_tsdata sc_ts;/* command and status packets */
	struct	ts_tsdata *sc_ubaddr; /* Unibus address of tsdata structure */
E 50
I 23
	u_short	sc_uba;		/* Unibus addr of cmd pkt for tsdb */
E 23
D 50
	short	sc_mapped;	/* is ts_sfotc mapped in Unibus space? */
E 50
I 50
	short	sc_density;	/* value |'ed into char_mode for TC13 density */
E 50
I 41
	struct	tty *sc_ttyp;	/* record user's tty for errors */
I 49
	int	sc_blks;	/* number of I/O operations since open */
	int	sc_softerrs;	/* number of soft I/O errors since open */
E 49
E 41
E 22
} ts_softc[NTS];
E 7

D 7
#define	ACK	0100000
#define	CVC	040000
#define	IE	0200
#define	READ	01
#define	REREAD	01001
E 7
I 7
D 22
struct ts_softc *ts_ubaddr;	/* Unibus address of ts_softc */
E 7

E 22
D 7
#define	SETCHR	04
E 7
I 7
/*
 * States for um->um_tab.b_active, the per controller state flag.
 * This is used to sequence control in the driver.
 */
#define	SSEEK	1		/* seeking */
#define	SIO	2		/* doing seq i/o */
#define	SCOM	3		/* sending control command */
#define	SREW	4		/* sending a drive rewind */
E 7

I 10
D 22
#if NTM > 0
/* kludge... see tm.c */
extern	havetm;
#endif
E 22
E 10
D 7
#define	WRITE	05
#define	REWRITE	01005
E 7
I 7
/*
 * Determine if there is a controller for
 * a ts at address reg.  Our goal is to make the
 * device interrupt.
 */
I 18
/*ARGSUSED*/
E 18
D 50
tsprobe(reg)
E 50
I 50
tsprobe(reg, ctlr, um)
E 50
	caddr_t reg;
I 50
	int ctlr;
	struct uba_ctlr *um;
E 50
{
	register int br, cvec;		/* must be r11,r10; value-result */
I 50
	register struct tsdevice *addr = (struct tsdevice *)reg;
	register struct ts_softc *sc;
	register int i;
	int a;
E 50
E 7

D 7
#define	SFORW	010
#define	SREV	0410
#define	REW	02010
E 7
I 7
#ifdef lint
	br = 0; cvec = br; br = cvec;
I 20
	tsintr(0);
E 20
#endif
D 20
	/****************/
	/*		*/
	/*  K L U D G E */
	/*		*/
	/****************/
E 20
E 7
D 22

I 20
	/*
	 * Too hard to make it interrupt; don't try.
	 */
E 20
I 10
#if NTM > 0
	if (havetm)
		return (0);
#endif
E 10
D 7
#define	WTM	011
E 7
I 7
D 20
	/* IT'S TOO HARD TO MAKE THIS THING INTERRUPT
	   JUST TO FIND ITS VECTOR */
E 20
	cvec = 0224;
E 22
I 22
D 50
	((struct tsdevice *)reg)->tssr = 0;
E 50
I 50
	addr->tssr = 0;		/* initialize subsystem */
E 50
	DELAY(100);
D 50
	if ((((struct tsdevice *)reg)->tssr & TS_NBA) == 0)
		return(0);
	/* IT'S TOO HARD TO MAKE THIS THING INTERRUPT JUST TO FIND ITS VECTOR */
	cvec = ((unsigned)reg) & 07 ? 0260 : 0224;
E 22
	br = 0x15;
E 50
I 50
	if ((addr->tssr & TS_NBA) == 0)
		return (0);

	/*
	 * Make it interrupt.
	 * TS_SETCHR|TS_IE alone refuses to interrupt for me.
	 */
	sc = &ts_softc[ctlr];
	tsmap(sc, numuba, &a);
	i = (int)&sc->sc_ubaddr->t_char;
	sc->sc_ts.t_cmd.c_loba = i;
	sc->sc_ts.t_cmd.c_hiba = (i >> 16) & 3;
	sc->sc_ts.t_cmd.c_size = sizeof(struct ts_char);
	sc->sc_ts.t_cmd.c_cmd = TS_ACK | TS_SETCHR;
	sc->sc_ts.t_char.char_addr = (int)&sc->sc_ubaddr->t_sts;
	sc->sc_ts.t_char.char_size = sizeof(struct ts_sts);
	sc->sc_ts.t_char.char_mode = 0;	/* mode is unimportant */
	addr->tsdb = sc->sc_uba;
	DELAY(20000);
	sc->sc_ts.t_cmd.c_cmd = TS_ACK | TS_CVC | TS_IE | TS_SENSE;
	sc->sc_ts.t_cmd.c_repcnt = 1;
	addr->tsdb = sc->sc_uba;
	DELAY(20000);
	/* should have interrupted by now */

	if (cvec == 0 || cvec == 0x200)	/* no interrupt */
		ubarelse(numuba, &a);

E 50
I 17
D 25
	return (1);
E 25
I 25
	return (sizeof (struct tsdevice));
E 25
E 17
}
E 7

D 7
#define	GSTAT	017
E 7
I 7
/*
I 50
 * Map in the command, status, and characteristics packet.  We
 * make them contiguous to keep overhead down.  This also sets
 * sc_uba (which then never changes).
 */
tsmap(sc, uban, a)
	register struct ts_softc *sc;
	int uban, *a;
{
	register int i;

	i = uballoc(uban, (caddr_t)&sc->sc_ts, sizeof(sc->sc_ts), 0);
	if (a != NULL)
		*a = i;
	i = UBAI_ADDR(i);
	sc->sc_ubaddr = (struct ts_tsdata *)i;
	/*
	 * Note that i == the Unibus address of the command packet,
	 * and that it is a multiple of 4 (guaranteed by the compiler).
	 */
	sc->sc_uba = i + ((i >> 16) & 3);
}

/*
E 50
 * TS11 only supports one drive per controller;
 * check for ui_slave == 0.
D 50
 *
 * DO WE REALLY NEED THIS ROUTINE???
E 50
 */
/*ARGSUSED*/
tsslave(ui, reg)
	struct uba_device *ui;
	caddr_t reg;
{
E 7

D 7
/* characteristics data */
struct charac {
D 2
	ushort	char_loba;
	ushort	char_hiba;
	ushort	char_size;
	ushort	char_mode;
E 2
I 2
	u_short	char_loba;
	u_short	char_hiba;
	u_short	char_size;
	u_short	char_mode;
E 2
};
E 7
I 7
D 50
	if (ui->ui_slave)	/* non-zero slave not allowed */
		return(0);
	return (1);
E 50
I 50
	return (ui->ui_slave == 0);	/* non-zero slave not allowed */
E 50
}
E 7

D 7
/* All the packets, collected */
struct tsmesg {
	struct	cmd ts_cmd;
	struct	sts ts_sts;
	struct	charac ts_char;
	int	align;		/* Should force alignment */
} ts;
E 7
I 7
/*
 * Record attachment of the unit to the controller.
D 50
 *
 * SHOULD THIS ROUTINE DO ANYTHING???
E 50
 */
/*ARGSUSED*/
tsattach(ui)
	struct uba_device *ui;
{
E 7

I 50
	/* void */
E 50
D 7
/* Bits in (unibus) status register */
#define	SC	0100000
#define	SSR	0200
#define	OFL	0100
#define	NBA	02000
E 7
I 7
}
E 7

D 7
/* states */
#define	SIO	1
#define	SSFOR	2
#define	SSREV	3
#define SRETRY	4
#define SCOM	5
#define SOK	6

#define H_WRITTEN 1

E 7
I 7
/*
 * Open the device.  Tapes are unique open
 * devices, so we refuse if it is already open.
D 50
 * We also check that a tape is available, and
 * don't block waiting here; if you want to wait
 * for a tape you should timeout in user code.
E 50
 */
E 7
tsopen(dev, flag)
I 7
	dev_t dev;
	int flag;
E 7
{
D 7
	register struct device *tsaddr = TSADDR;
	static struct tsmesg *ubaddr;
E 7
I 7
D 50
	register int tsunit;
E 50
I 50
	register int tsunit = TSUNIT(dev);
E 50
	register struct uba_device *ui;
	register struct ts_softc *sc;
E 7

D 7
	tstab.b_flags |= B_TAPE;
	if (ts_openf) {
E 7
I 7
D 50
	tsunit = TSUNIT(dev);
D 44
	if (tsunit>=NTS || (sc = &ts_softc[tsunit])->sc_openf ||
D 31
	    (ui = tsdinfo[tsunit]) == 0 || ui->ui_alive == 0) {
E 7
		u.u_error = ENXIO;
		return;
	}
D 7
	if (ubaddr==0 || tsaddr->tssr&(OFL|NBA) || (tsaddr->tssr&SSR)==0) {
		long i = 0;
		tsaddr->tssr = 0;
		while ((tsaddr->tssr & SSR)==0) {
			if (++i > 1000000) {
				printf("Tape unready\n");
				u.u_error = ENXIO;
				return;
			}
		}
	}
	if (tsaddr->tssr&OFL) {
		printf("Tape offline\n");
E 7
I 7
	if (tsinit(tsunit)) {
E 7
		u.u_error = ENXIO;
I 12
D 22
#ifdef TSDEBUG
E 12
I 8
		printd("init failed\n");
I 12
#endif
E 22
E 12
E 8
		return;
	}
E 31
I 31
	    (ui = tsdinfo[tsunit]) == 0 || ui->ui_alive == 0)
E 44
I 44
	if (tsunit>=NTS || (ui = tsdinfo[tsunit]) == 0 || ui->ui_alive == 0)
E 50
I 50
	if (tsunit >= NTS || (ui = tsdinfo[tsunit]) == 0 || ui->ui_alive == 0)
E 50
E 44
		return (ENXIO);
I 44
D 50
	if ((sc = &ts_softc[tsunit])->sc_openf)
E 50
I 50
	if ((sc = &ts_softc[ui->ui_ctlr])->sc_openf)
E 50
		return (EBUSY);
E 44
D 49
	if (tsinit(tsunit))
E 49
I 49
	sc->sc_openf = 1;
D 50
	if (tsinit(tsunit)) {
E 50
I 50
	sc->sc_density = (minor(dev) & T_1600BPI) ? TS_NRZI : 0;
	tscommand(dev, TS_SENSE, 1);
	if (ctsbuf[tsunit].b_flags & B_ERROR)
		/*
		 * Try it again in case it went off-line
		 */
		tscommand(dev, TS_SENSE, 1);
	if (tsinit(ui->ui_ctlr)) {
E 50
		sc->sc_openf = 0;
E 49
		return (ENXIO);
I 49
	}
E 49
E 31
I 12
D 22
#ifdef TSDEBUG
E 12
I 8
	printd("init ok\n");
I 12
#endif
E 22
E 12
E 8
D 7
	if (tsaddr->tssr&NBA) {
		ctsbuf.b_un.b_addr = (caddr_t) &ts;
		ctsbuf.b_bcount = sizeof(ts);
		if (ubaddr == 0)
			ubaddr = (struct tsmesg *)ubasetup(&ctsbuf, 0);
D 2
		ts_uba = (ushort)((long)ubaddr + (((long)ubaddr >> 16) & 03));
E 2
I 2
		ts_uba = (u_short)((long)ubaddr + (((long)ubaddr >> 16) & 03));
E 2
		ts.ts_char.char_loba = (int)&ubaddr->ts_sts;
D 2
		ts.ts_char.char_hiba = (ushort)((long)&ubaddr->ts_sts >> 16) & 03;
E 2
I 2
		ts.ts_char.char_hiba = (u_short)((long)&ubaddr->ts_sts >> 16) & 03;
E 2
		ts.ts_char.char_size = sizeof(ts.ts_sts);
		ts.ts_char.char_mode = 0400;		/* Stop on 2 tape marks */
		ts.ts_cmd.c_cmd = ACK + 04;	/* write characteristics */
		ts.ts_cmd.c_loba = (int)&ubaddr->ts_char;
D 2
		ts.ts_cmd.c_hiba = (ushort)((long)&ubaddr->ts_sts >> 16) & 03;
E 2
I 2
		ts.ts_cmd.c_hiba = (u_short)((long)&ubaddr->ts_sts >> 16) & 03;
E 2
		ts.ts_cmd.c_size = sizeof(ts.ts_sts);
		tsaddr->tsdb = ts_uba;
E 7
I 7
D 50
	tscommand(dev, TS_SENSE, 1);
I 12
D 22
#ifdef TSDEBUG
E 12
I 8
	printd("sense xs0 %o\n", sc->sc_sts.s_xs0);
I 12
#endif
E 22
E 12
E 8
D 15
	if ((sc->sc_sts.s_xs0&TS_ONL) == 0 || ((flag&(FREAD|FWRITE)) ==
	    FWRITE && (sc->sc_sts.s_xs0&TS_WLK))) {
		/*
		 * Not online or write locked.
		 */
E 15
I 15
	if ((sc->sc_sts.s_xs0&TS_ONL) == 0) {
E 50
I 50
	if ((sc->sc_ts.t_sts.s_xs0&TS_ONL) == 0) {
E 50
I 49
		sc->sc_openf = 0;
E 49
		uprintf("ts%d: not online\n", tsunit);
D 31
		u.u_error = EIO;
		return;
E 31
I 31
		return (EIO);
E 31
	}
D 16
	if ((flag&(FREAD|FWRITE)) == FWRITE && (sc->sc_sts.s_xs0&TS_WLK))) {
E 16
I 16
D 43
	if ((flag&(FREAD|FWRITE)) == FWRITE && (sc->sc_sts.s_xs0&TS_WLK)) {
E 43
I 43
D 50
	if ((flag&FWRITE) && (sc->sc_sts.s_xs0&TS_WLK)) {
E 50
I 50
	if ((flag&FWRITE) && (sc->sc_ts.t_sts.s_xs0&TS_WLK)) {
E 50
I 49
		sc->sc_openf = 0;
E 49
E 43
E 16
		uprintf("ts%d: no write ring\n", tsunit);
E 15
D 31
		u.u_error = EIO;
		return;
E 31
I 31
		return (EIO);
E 31
E 7
	}
D 7
	ts_blkno = 0;
	ts_nxrec = INF;
	ts_flags = 0;
	if (u.u_error==0)
		ts_openf++;
E 7
I 7
D 49
	sc->sc_openf = 1;
E 49
	sc->sc_blkno = (daddr_t)0;
	sc->sc_nxrec = INF;
	sc->sc_lastiow = 0;
I 49
	sc->sc_blks = 0;
	sc->sc_softerrs = 0;
E 49
I 41
	sc->sc_ttyp = u.u_ttyp;
E 41
I 31
	return (0);
E 31
E 7
}

I 7
/*
 * Close tape device.
 *
 * If tape was open for writing or last operation was
 * a write, then write two EOF's and backspace over the last one.
 * Unless this is a non-rewinding special file, rewind the tape.
 * Make the tape available to others.
 */
E 7
tsclose(dev, flag)
I 7
	register dev_t dev;
D 50
	register flag;
E 50
I 50
	register int flag;
E 50
E 7
{
I 7
	register struct ts_softc *sc = &ts_softc[TSUNIT(dev)];
E 7

D 7
	if (flag == FWRITE || ((flag&FWRITE) && (ts_flags&H_WRITTEN))) {
		tscommand(WTM);
		tscommand(WTM);
		tscommand(SREV);
E 7
I 7
	if (flag == FWRITE || (flag&FWRITE) && sc->sc_lastiow) {
		tscommand(dev, TS_WEOF, 1);
		tscommand(dev, TS_WEOF, 1);
		tscommand(dev, TS_SREV, 1);
E 7
	}
D 7
	if ((minor(dev)&4) == 0)
		tscommand(REW);
	ts_openf = 0;
E 7
I 7
	if ((minor(dev)&T_NOREWIND) == 0)
		/*
		 * 0 count means don't hang waiting for rewind complete
		 * rather ctsbuf stays busy until the operation completes
		 * preventing further opens from completing by
		 * preventing a TS_SENSE from completing.
		 */
		tscommand(dev, TS_REW, 0);
I 49
	if (sc->sc_blks > 100 && sc->sc_softerrs > sc->sc_blks / 100)
		log(LOG_INFO, "ts%d: %d soft errors in %d blocks\n",
		    TSUNIT(dev), sc->sc_softerrs, sc->sc_blks);
E 49
	sc->sc_openf = 0;
E 7
}

D 7
tscommand(com)
E 7
I 7
/*
D 50
 * Initialize the TS11.  Set up Unibus mapping for command
 * packets and set device characteristics.
E 50
I 50
 * Initialize a TS11.  Set device characteristics.
E 50
 */
D 50
tsinit(unit)
	register int unit;
E 50
I 50
tsinit(ctlr)
	register int ctlr;
E 50
E 7
{
I 7
D 50
	register struct ts_softc *sc = &ts_softc[unit];
	register struct uba_ctlr *um = tsminfo[unit];
E 50
I 50
	register struct ts_softc *sc = &ts_softc[ctlr];
	register struct uba_ctlr *um = tsminfo[ctlr];
E 50
D 22
	register struct device *addr = (struct device *)um->um_addr;
E 22
I 22
	register struct tsdevice *addr = (struct tsdevice *)um->um_addr;
E 22
	register int i;

D 50
	/*
	 * Map the command and message packets into Unibus
	 * address space.  We do all the command and message
	 * packets at once to minimize the amount of Unibus
	 * mapping necessary.
	 */
D 22
	if (ts_ubaddr == 0) {
		ctsbuf[unit].b_un.b_addr = (caddr_t)ts_softc;
		ctsbuf[unit].b_bcount = sizeof(ts_softc);
E 22
I 22
	if (sc->sc_mapped == 0) {
		ctsbuf[unit].b_un.b_addr = (caddr_t)sc;
		ctsbuf[unit].b_bcount = sizeof(*sc);
E 22
		i = ubasetup(um->um_ubanum, &ctsbuf[unit], 0);
		i &= 0777777;
D 22
		ts_ubaddr = (struct ts_softc *)i;
		/* MAKE SURE WE DON'T GET UNIBUS ADDRESS ZERO */
		if (ts_ubaddr == 0)
			printf("ts%d: zero ubaddr\n", unit);
E 22
I 22
		sc->sc_ubaddr = (struct ts_softc *)i;
		sc->sc_mapped++;
E 22
	}
	/*
	 * Now initialize the TS11 controller.
	 * Set the characteristics.
	 */
D 14
	if (addr->tssr & TS_NBA) {
E 14
I 14
	if (addr->tssr & (TS_NBA|TS_OFL)) {
E 50
I 50
	if (addr->tssr & (TS_NBA|TS_OFL) || sc->sc_ts.t_sts.s_xs0 & TS_BOT) {
E 50
E 14
		addr->tssr = 0;		/* subsystem initialize */
		tswait(addr);
D 22
		i = (int)&ts_ubaddr[unit].sc_cmd;	/* Unibus addr of cmd */
I 8
		if (i&3) {
			printf("addr mod 4 != 0\n");
			return(1);
		}
E 22
I 22
D 50
		i = (int)&sc->sc_ubaddr->sc_cmd;	/* Unibus addr of cmd */
E 22
E 8
		sc->sc_uba = (u_short)(i + ((i>>16)&3));
D 22
		sc->sc_char.char_addr = (int)&ts_ubaddr[unit].sc_sts;
E 22
I 22
		sc->sc_char.char_addr = (int)&sc->sc_ubaddr->sc_sts;
E 22
		sc->sc_char.char_size = sizeof(struct ts_sts);
		sc->sc_char.char_mode = TS_ESS;
		sc->sc_cmd.c_cmd = TS_ACK | TS_SETCHR;
D 8
		sc->sc_cmd.c_addr = (int)&ts_ubaddr[unit].sc_char;
E 8
I 8
D 22
		i = (int)&ts_ubaddr[unit].sc_char;
E 22
I 22
		i = (int)&sc->sc_ubaddr->sc_char;
E 22
		sc->sc_cmd.c_loba = i;
		sc->sc_cmd.c_hiba = (i>>16)&3;
E 8
		sc->sc_cmd.c_size = sizeof(struct ts_char);
E 50
I 50
		i = (int)&sc->sc_ubaddr->t_char;
		sc->sc_ts.t_cmd.c_loba = i;
		sc->sc_ts.t_cmd.c_hiba = (i >> 16) & 3;
		sc->sc_ts.t_cmd.c_size = sizeof(struct ts_char);
		sc->sc_ts.t_cmd.c_cmd = TS_ACK | TS_CVC | TS_SETCHR;
		sc->sc_ts.t_char.char_addr = (int)&sc->sc_ubaddr->t_sts;
		sc->sc_ts.t_char.char_size = sizeof(struct ts_sts);
		sc->sc_ts.t_char.char_mode = TS_ESS | TS_EAI | TS_ERI |
			/* TS_ENB | */ sc->sc_density;
E 50
		addr->tsdb = sc->sc_uba;
		tswait(addr);
I 8
D 22
/*
		printd("%o %o %o %o %o %o %o %o\n", addr->tssr, sc->sc_sts.s_sts, sc->sc_sts.s_len, sc->sc_sts.s_rbpcr, sc->sc_sts.s_xs0, sc->sc_sts.s_xs1,sc->sc_sts.s_xs1,sc->sc_sts.s_xs2,sc->sc_sts.s_xs3);
*/
E 22
		if (addr->tssr & TS_NBA)
			return(1);
E 8
	}
	return(0);
}

/*
 * Execute a command on the tape drive
 * a specified number of times.
 */
tscommand(dev, com, count)
	dev_t dev;
	int com, count;
{
E 7
	register struct buf *bp;
I 21
	register int s;
I 50
	int didsleep = 0;
E 50
E 21

D 7
	bp = &ctsbuf;
	spl5();
	while(bp->b_flags&B_BUSY) {
E 7
I 7
	bp = &ctsbuf[TSUNIT(dev)];
D 21
	(void) spl5();
E 21
I 21
	s = spl5();
E 21
	while (bp->b_flags&B_BUSY) {
		/*
		 * This special check is because B_BUSY never
		 * gets cleared in the non-waiting rewind case.
		 */
		if (bp->b_repcnt == 0 && (bp->b_flags&B_DONE))
			break;
E 7
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO);
I 50
		didsleep = 1;
E 50
	}
D 7
	spl0();
	bp->b_resid = com;
	bp->b_blkno = 0;
E 7
	bp->b_flags = B_BUSY|B_READ;
I 7
D 21
	(void) spl0();
E 21
I 21
	splx(s);
I 50
	if (didsleep)
		(void) tsinit(tsdinfo[TSUNIT(dev)]->ui_ctlr);
E 50
E 21
I 12
D 22
#ifdef TSDEBUG
E 12
I 8
	printd("command %o dev %x count %d\n", com, dev, count);
I 12
#endif
E 22
E 12
E 8
	bp->b_dev = dev;
	bp->b_repcnt = count;
	bp->b_command = com;
	bp->b_blkno = 0;
E 7
	tsstrategy(bp);
I 7
	/*
	 * In case of rewind from close, don't wait.
	 * This is the only case where count can be 0.
	 */
	if (count == 0)
		return;
E 7
D 50
	iowait(bp);
E 50
I 50
	biowait(bp);
E 50
D 7
	if(bp->b_flags&B_WANTED)
E 7
I 7
	if (bp->b_flags&B_WANTED)
E 7
		wakeup((caddr_t)bp);
D 7
	bp->b_flags = 0;
	return(bp->b_resid);
E 7
I 7
	bp->b_flags &= B_ERROR;
E 7
}

I 7
/*
 * Queue a tape operation.
 */
E 7
tsstrategy(bp)
D 7
register struct buf *bp;
E 7
I 7
	register struct buf *bp;
E 7
{
D 7
	register daddr_t *p;
E 7
I 7
D 50
	int tsunit = TSUNIT(bp->b_dev);
E 50
I 50
	register int tsunit = TSUNIT(bp->b_dev);
E 50
	register struct uba_ctlr *um;
I 8
	register struct buf *dp;
I 21
D 50
	register int s;
E 50
I 50
	int s;
E 50
E 21
E 8
E 7

D 7
	if(bp != &ctsbuf) {
		p = &ts_nxrec;
		if(dbtofsb(bp->b_blkno) > *p) {
			bp->b_flags |= B_ERROR;
			bp->b_error = ENXIO;
			iodone(bp);
			return;
		}
		if(dbtofsb(bp->b_blkno) == *p && bp->b_flags&B_READ) {
			bp->b_resid = bp->b_bcount;
			iodone(bp);
			return;
		}
		if ((bp->b_flags&B_READ)==0) {
			*p = dbtofsb(bp->b_blkno) + 1;
			ts_flags |= H_WRITTEN;
		}
	}
E 7
I 7
	/*
	 * Put transfer at end of controller queue
	 */
E 7
	bp->av_forw = NULL;
D 7
	spl5();
	if (tstab.b_actf == NULL)
		tstab.b_actf = bp;
E 7
I 7
	um = tsdinfo[tsunit]->ui_mi;
I 8
D 22
	dp = &tsbuf[tsunit];
E 22
E 8
D 21
	(void) spl5();
E 21
I 21
D 50
	s = spl5();
E 50
I 22
	dp = &tsutab[tsunit];
I 50
	s = spl5();
E 50
E 22
E 21
D 8
	if (um->um_tab.b_actf == NULL)
		um->um_tab.b_actf = bp;
E 8
I 8
	if (dp->b_actf == NULL)
		dp->b_actf = bp;
E 8
E 7
	else
D 7
		tstab.b_actl->av_forw = bp;
	tstab.b_actl = bp;
	if (tstab.b_active==0)
		tsstart();
	spl0();
E 7
I 7
D 8
		um->um_tab.b_actl->av_forw = bp;
	um->um_tab.b_actl = bp;
E 8
I 8
		dp->b_actl->av_forw = bp;
	dp->b_actl = bp;
	um->um_tab.b_actf = um->um_tab.b_actl = dp;
E 8
	/*
	 * If the controller is not busy, get
	 * it going.
	 */
	if (um->um_tab.b_active == 0)
		tsstart(um);
D 21
	(void) spl0();
E 21
I 21
	splx(s);
E 21
E 7
}

D 7
tsstart()
E 7
I 7
/*
 * Start activity on a ts controller.
 */
tsstart(um)
	register struct uba_ctlr *um;
E 7
{
	register struct buf *bp;
D 7
	register struct device *tsaddr = TSADDR;
E 7
I 7
D 22
	register struct device *addr = (struct device *)um->um_addr;
E 22
I 22
	register struct tsdevice *addr = (struct tsdevice *)um->um_addr;
E 22
	register struct ts_softc *sc;
D 50
	register struct ts_cmd *tc;
E 50
	register struct uba_device *ui;
D 50
	int tsunit, cmd;
E 50
I 50
	register int tsunit;
	int cmd;
E 50
E 7
	daddr_t blkno;

D 7
    loop:
	if ((bp = tstab.b_actf) == NULL)
E 7
I 7
	/*
	 * Start the controller if there is something for it to do.
	 */
loop:
D 8
	if ((bp = um->um_tab.b_actf) == NULL)
E 8
I 8
D 51
	if ((bp = um->um_tab.b_actf->b_actf) == NULL)
E 51
I 51
	if ((bp = um->um_tab.b_actf->b_actf) == NULL) {
		um->um_tab.b_active = 0;
E 51
E 8
E 7
		return;
I 51
	}
E 51
D 7
	blkno = ts_blkno;
	if (ts_openf < 0 || dbtofsb(bp->b_blkno) > ts_nxrec)
		goto abort;
	if (bp == &ctsbuf) {
		tstab.b_active = SCOM;
		ts.ts_cmd.c_cmd = ACK+CVC+IE+bp->b_resid;
		ts.ts_cmd.c_loba = 1;		/* count always 1 */
	} else if (blkno == dbtofsb(bp->b_blkno)) {
		tstab.b_active = SIO;
D 5
		ts_iouba = ubasetup(bp, 1);
D 2
		ts.ts_cmd.c_loba = (ushort)ts_iouba;
		ts.ts_cmd.c_hiba = (ushort)(ts_iouba >> 16) & 03;
E 2
I 2
		ts.ts_cmd.c_loba = (u_short)ts_iouba;
		ts.ts_cmd.c_hiba = (u_short)(ts_iouba >> 16) & 03;
E 5
I 5
		ts_ubinfo = ubasetup(bp, 1);
		ts.ts_cmd.c_loba = (u_short)ts_ubinfo;
		ts.ts_cmd.c_hiba = (u_short)(ts_ubinfo >> 16) & 03;
E 5
E 2
		ts.ts_cmd.c_size = bp->b_bcount;
		if(bp->b_flags & B_READ)
			ts.ts_cmd.c_cmd = ACK+CVC+IE+READ;
E 7
I 7
	tsunit = TSUNIT(bp->b_dev);
	ui = tsdinfo[tsunit];
	sc = &ts_softc[tsunit];
D 50
	tc = &sc->sc_cmd;
E 50
	/*
	 * Default is that last command was NOT a write command;
D 50
	 * if we do a write command we will notice this in tsintr().
E 50
I 50
	 * if we finish a write command we will notice this in tsintr().
E 50
	 */
D 13
	sc->sc_lastiow = 1;
E 13
I 13
	sc->sc_lastiow = 0;
E 13
	if (sc->sc_openf < 0 || (addr->tssr&TS_OFL)) {
		/*
		 * Have had a hard error on a non-raw tape
		 * or the tape unit is now unavailable
		 * (e.g. taken off line).
		 */
		bp->b_flags |= B_ERROR;
		goto next;
	}
D 50
	if (bp == &ctsbuf[TSUNIT(bp->b_dev)]) {
E 50
I 50
	if (bp == &ctsbuf[tsunit]) {
E 50
		/*
		 * Execute control operation with the specified count.
		 */
		um->um_tab.b_active =
		    bp->b_command == TS_REW ? SREW : SCOM;
D 50
		tc->c_repcnt = bp->b_repcnt;
E 50
I 50
		sc->sc_ts.t_cmd.c_repcnt = bp->b_repcnt;
E 50
I 12
D 22
#ifdef TSDEBUG
E 12
I 8
		printd("strat: do cmd\n");
I 12
#endif
E 22
E 12
E 8
		goto dobpcmd;
	}
	/*
D 50
	 * The following checks handle boundary cases for operation
	 * on non-raw tapes.  On raw tapes the initialization of
	 * sc->sc_nxrec by tsphys causes them to be skipped normally
	 * (except in the case of retries).
E 50
I 50
	 * For raw I/O, save the current block
	 * number in case we have to retry.
E 50
	 */
D 24
	if (dbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 24
I 24
D 50
	if (bdbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 50
I 50
D 52
	if (bp == &rtsbuf[tsunit]) {
E 52
I 52
	if (bp->b_flags & B_RAW) {
E 52
		if (um->um_tab.b_errcnt == 0)
			sc->sc_blkno = bdbtofsb(bp->b_blkno);
	} else {
E 50
E 24
		/*
D 50
		 * Can't read past known end-of-file.
E 50
I 50
		 * Handle boundary cases for operation
		 * on non-raw tapes.
E 50
		 */
D 50
		bp->b_flags |= B_ERROR;
		bp->b_error = ENXIO;
		goto next;
E 50
I 50
		if (bdbtofsb(bp->b_blkno) > sc->sc_nxrec) {
			/*
			 * Can't read past known end-of-file.
			 */
			bp->b_flags |= B_ERROR;
			bp->b_error = ENXIO;
			goto next;
		}
		if (bdbtofsb(bp->b_blkno) == sc->sc_nxrec &&
		    bp->b_flags&B_READ) {
			/*
			 * Reading at end of file returns 0 bytes.
			 */
			bp->b_resid = bp->b_bcount;
			clrbuf(bp);
			goto next;
		}
		if ((bp->b_flags&B_READ) == 0)
			/*
			 * Writing sets EOF
			 */
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) + 1;
E 50
	}
D 24
	if (dbtofsb(bp->b_blkno) == sc->sc_nxrec &&
E 24
I 24
D 50
	if (bdbtofsb(bp->b_blkno) == sc->sc_nxrec &&
E 24
	    bp->b_flags&B_READ) {
		/*
		 * Reading at end of file returns 0 bytes.
		 */
		bp->b_resid = bp->b_bcount;
		clrbuf(bp);
		goto next;
	}
	if ((bp->b_flags&B_READ) == 0)
		/*
		 * Writing sets EOF
		 */
D 24
		sc->sc_nxrec = dbtofsb(bp->b_blkno) + 1;
E 24
I 24
		sc->sc_nxrec = bdbtofsb(bp->b_blkno) + 1;
E 50
I 50

E 50
E 24
	/*
	 * If the data transfer command is in the correct place,
	 * set up all the registers except the csr, and give
	 * control over to the UNIBUS adapter routines, to
	 * wait for resources to start the i/o.
	 */
D 24
	if ((blkno = sc->sc_blkno) == dbtofsb(bp->b_blkno)) {
E 24
I 24
	if ((blkno = sc->sc_blkno) == bdbtofsb(bp->b_blkno)) {
E 24
D 50
		tc->c_size = bp->b_bcount;
E 50
I 50
		sc->sc_ts.t_cmd.c_size = bp->b_bcount;
E 50
		if ((bp->b_flags&B_READ) == 0)
			cmd = TS_WCOM;
E 7
		else
D 7
			ts.ts_cmd.c_cmd = ACK+CVC+IE+WRITE;
E 7
I 7
			cmd = TS_RCOM;
		if (um->um_tab.b_errcnt)
			cmd |= TS_RETRY;
		um->um_tab.b_active = SIO;
D 8
		tc->c_cmd = TS_ACK | TS_CVC | cmd;
E 8
I 8
D 50
		tc->c_cmd = TS_ACK | TS_CVC | TS_IE | cmd;
E 50
I 50
		sc->sc_ts.t_cmd.c_cmd = TS_ACK | TS_CVC | TS_IE | cmd;
E 50
I 12
D 22
#ifdef TSDEBUG
E 12
		printd("r/w %o size %d\n", tc->c_cmd, tc->c_size);
I 12
#endif
E 22
E 12
E 8
		(void) ubago(ui);
		return;
	}
	/*
	 * Tape positioned incorrectly;
	 * set to seek forwards or backwards to the correct spot.
	 * This happens for raw tapes only on error retries.
	 */
	um->um_tab.b_active = SSEEK;
I 12
D 22
#ifdef TSDEBUG
E 12
I 8
	printd("seek blkno %d b_blkno %d\n", blkno, bp->b_blkno);
I 12
#endif
E 22
E 12
E 8
D 24
	if (blkno < dbtofsb(bp->b_blkno)) {
E 24
I 24
	if (blkno < bdbtofsb(bp->b_blkno)) {
E 24
		bp->b_command = TS_SFORW;
D 24
		tc->c_repcnt = dbtofsb(bp->b_blkno) - blkno;
E 24
I 24
D 50
		tc->c_repcnt = bdbtofsb(bp->b_blkno) - blkno;
E 50
I 50
		sc->sc_ts.t_cmd.c_repcnt = bdbtofsb(bp->b_blkno) - blkno;
E 50
E 24
E 7
	} else {
D 7
		if (blkno < dbtofsb(bp->b_blkno)) {
			tstab.b_active = SSFOR;
			ts.ts_cmd.c_cmd = ACK+CVC+IE+SFORW;
			ts.ts_cmd.c_loba = dbtofsb(bp->b_blkno) - blkno;
		} else {
			tstab.b_active = SSREV;
			ts.ts_cmd.c_cmd = ACK+CVC+IE+SREV;
			ts.ts_cmd.c_loba = blkno - dbtofsb(bp->b_blkno);
		}
E 7
I 7
		bp->b_command = TS_SREV;
D 24
		tc->c_repcnt = blkno - dbtofsb(bp->b_blkno);
E 24
I 24
D 50
		tc->c_repcnt = blkno - bdbtofsb(bp->b_blkno);
E 50
I 50
		sc->sc_ts.t_cmd.c_repcnt = blkno - bdbtofsb(bp->b_blkno);
E 50
E 24
E 7
	}
D 7
	tsaddr->tsdb = ts_uba;
E 7
I 7
dobpcmd:
	/*
	 * Do the command in bp.
	 */
D 8
	tc->c_cmd = TS_ACK | TS_CVC | bp->b_command;
E 8
I 8
D 50
	tc->c_cmd = TS_ACK | TS_CVC | TS_IE | bp->b_command;
E 50
I 50
	sc->sc_ts.t_cmd.c_cmd = TS_ACK | TS_CVC | TS_IE | bp->b_command;
E 50
E 8
	addr->tsdb = sc->sc_uba;
E 7
	return;

D 7
    abort:
	bp->b_flags |= B_ERROR;

    next:
	tstab.b_active = 0;
	tstab.b_actf = bp->av_forw;
E 7
I 7
next:
	/*
	 * Done with this operation due to error or
	 * the fact that it doesn't do anything.
	 * Release UBA resources (if any), dequeue
	 * the transfer and continue processing this slave.
	 */
	if (um->um_ubinfo)
		ubadone(um);
	um->um_tab.b_errcnt = 0;
D 8
	um->um_tab.b_actf = bp->av_forw;
E 8
I 8
	um->um_tab.b_actf->b_actf = bp->av_forw;
E 8
E 7
D 50
	iodone(bp);
E 50
I 50
	biodone(bp);
E 50
	goto loop;
}

D 7
tsintr()
E 7
I 7
/*
 * The UNIBUS resources we needed have been
 * allocated to us; start the device.
 */
tsdgo(um)
	register struct uba_ctlr *um;
E 7
{
I 7
D 22
	register struct device *addr = (struct device *)um->um_addr;
E 22
I 22
D 50
	register struct tsdevice *addr = (struct tsdevice *)um->um_addr;
E 50
E 22
	register struct ts_softc *sc = &ts_softc[um->um_ctlr];
I 8
	register int i;
E 8

I 45
	/*
	 * The uba code uses byte-offset mode if using bdp;
	 * mask off the low bit here.
	 */
E 45
D 8
	sc->sc_cmd.c_addr = um->um_ubinfo & 0777777;
E 8
I 8
D 50
	i = um->um_ubinfo & 0777777;
E 50
I 50
	i = UBAI_ADDR(um->um_ubinfo);
E 50
I 45
	if (UBAI_BDP(um->um_ubinfo))
		i &= ~1;
E 45
I 12
D 22
#ifdef TSDEBUG
E 12
	printd("dgo addr %o\n", i);
I 12
#endif
E 22
E 12
D 50
	sc->sc_cmd.c_loba = i;
	sc->sc_cmd.c_hiba = (i>>16)&3;
E 8
	addr->tsdb = sc->sc_uba;
E 50
I 50
	sc->sc_ts.t_cmd.c_loba = i;
	sc->sc_ts.t_cmd.c_hiba = (i >> 16) & 3;
	((struct tsdevice *)um->um_addr)->tsdb = sc->sc_uba;
E 50
}

/*
 * Ts interrupt routine.
 */
/*ARGSUSED*/
D 50
tsintr(ts11)
	int ts11;
E 50
I 50
tsintr(tsunit)
	register int tsunit;
E 50
{
E 7
	register struct buf *bp;
D 7
	register struct device *tsaddr = TSADDR;
	register err, errclass, state;
E 7
I 7
D 50
	register struct uba_ctlr *um = tsminfo[ts11];
E 50
I 50
	register struct uba_ctlr *um;
E 50
D 22
	register struct device *addr;
E 22
I 22
	register struct tsdevice *addr;
E 22
	register struct ts_softc *sc;
D 50
	int tsunit;
	register state;
E 50
I 50
	register int state;

E 50
E 7
D 47

E 47
I 47
D 53
#if VAX630
E 53
I 53
#ifdef QBA
E 53
D 50
	spl5();
E 50
I 50
	(void) spl5();
E 50
#endif
I 50
	um = tsdinfo[tsunit]->ui_mi;
E 50
E 47
I 12
D 22
#ifdef TSDEBUG
E 12
D 7
	if ((bp = tstab.b_actf)==NULL)
E 7
I 7
D 8
	if ((bp = um->um_tab.b_actf) == NULL)
E 8
I 8
	printd("intr\n");
I 12
#endif
E 22
E 12
	if ((bp = um->um_tab.b_actf->b_actf) == NULL)
E 8
E 7
		return;
D 7
	state = tstab.b_active;
	tstab.b_active = 0;
	err = tsaddr->tssr & 016;
	if ((tsaddr->tssr & SC) == 0)
		err = 0;
	errclass = 0;
	switch (err) {
	case 014:		/* unrecoverable */
	case 016:		/* fatal */
	case 002:		/* attention (shouldn't happen) */
	case 012:		/* "recoverable", but shouldn't happen */
		errclass = 2;
		break;
E 7
I 7
D 50
	tsunit = TSUNIT(bp->b_dev);
D 22
	addr = (struct device *)tsdinfo[tsunit]->ui_addr;
E 22
I 22
	addr = (struct tsdevice *)tsdinfo[tsunit]->ui_addr;
E 50
I 50
	addr = (struct tsdevice *)um->um_addr;
E 50
E 22
	/*
	 * If last command was a rewind, and tape is still
	 * rewinding, wait for the rewind complete interrupt.
	 *
	 * SHOULD NEVER GET AN INTERRUPT IN THIS STATE.
	 */
	if (um->um_tab.b_active == SREW) {
		um->um_tab.b_active = SCOM;
		if ((addr->tssr&TS_SSR) == 0)
			return;
	}
	/*
	 * An operation completed... record status
	 */
I 12
D 22
#ifdef TSDEBUG
E 12
I 8
	printd("  ok1\n");
I 12
#endif
E 22
E 12
E 8
D 50
	sc = &ts_softc[tsunit];
E 50
I 50
	sc = &ts_softc[um->um_ctlr];
E 50
	if ((bp->b_flags & B_READ) == 0)
		sc->sc_lastiow = 1;
	state = um->um_tab.b_active;
D 50
	um->um_tab.b_active = 0;
E 50
	/*
	 * Check for errors.
	 */
	if (addr->tssr&TS_SC) {
		switch (addr->tssr & TS_TC) {
		case TS_UNREC:		/* unrecoverable */
		case TS_FATAL:		/* fatal error */
D 50
		case TS_ATTN:		/* attention (shouldn't happen) */
E 50
		case TS_RECNM:		/* recoverable, no motion */
			break;
I 50
		case TS_ATTN:		/* attention */
			if (sc->sc_ts.t_sts.s_xs0 & TS_VCK) {
				/* volume check - may have changed tapes */
				bp->b_flags |= B_ERROR;
				goto ignoreerr;
			}
			break;
E 50
E 7

D 7
	case 0:			/* all OK */
		break;
E 7
I 7
		case TS_SUCC:		/* success termination */
D 50
			printf("ts%d: success\n", TSUNIT(minor(bp->b_dev)));
E 50
I 50
			printf("ts%d: success\n", tsunit);
E 50
			goto ignoreerr;
E 7

D 7
	case 004:		/* status alert */
		if (ts.ts_sts.xs0&RLS && bp==&rtsbuf)	/* short record */
E 7
I 7
		case TS_ALERT:		/* tape status alert */
			/*
			 * If we hit the end of the tape file,
			 * update our position.
			 */
D 50
			if (sc->sc_sts.s_xs0 & (TS_TMK|TS_EOT)) {
				tsseteof(bp);		/* set blkno and nxrec */
				state = SCOM;		/* force completion */
E 50
I 50
			if (sc->sc_ts.t_sts.s_xs0 & (TS_TMK|TS_EOT)) {
				tsseteof(bp);	/* set blkno and nxrec */
				state = SCOM;	/* force completion */
E 50
				/*
				 * Stuff bc so it will be unstuffed correctly
				 * later to get resid.
				 */
D 50
				sc->sc_sts.s_rbpcr = bp->b_bcount;
E 50
I 50
				sc->sc_ts.t_sts.s_rbpcr = bp->b_bcount;
E 50
				goto opdone;
			}
			/*
D 50
			 * If we were reading raw tape and the record was too long
			 * or too short, then we don't consider this an error.
E 50
I 50
			 * If we were reading raw tape and the record was too
			 * long or too short, we don't consider this an error.
E 50
			 */
D 50
			if (bp == &rtsbuf[TSUNIT(bp->b_dev)] && (bp->b_flags&B_READ) &&
			    sc->sc_sts.s_xs0&(TS_RLS|TS_RLL))
E 50
I 50
D 52
			if (bp == &rtsbuf[tsunit] && bp->b_flags&B_READ &&
E 52
I 52
			if ((bp->b_flags & (B_READ|B_RAW)) == (B_READ|B_RAW) &&
E 52
			    sc->sc_ts.t_sts.s_xs0&(TS_RLS|TS_RLL))
E 50
				goto ignoreerr;
I 50
			/* FALLTHROUGH */

E 50
		case TS_RECOV:		/* recoverable, tape moved */
			/*
			 * If this was an i/o operation retry up to 8 times.
			 */
D 50
			if (state==SIO) {
E 50
I 50
			if (state == SIO) {
E 50
				if (++um->um_tab.b_errcnt < 7) {
					ubadone(um);
					goto opcont;
				} else
					sc->sc_blkno++;
			} else {
				/*
				 * Non-i/o errors on non-raw tape
				 * cause it to close.
				 */
D 50
				if (sc->sc_openf>0 && bp != &rtsbuf[TSUNIT(bp->b_dev)])
E 50
I 50
D 52
				if (sc->sc_openf > 0 && bp != &rtsbuf[tsunit])
E 52
I 52
				if ((bp->b_flags&B_RAW) == 0 &&
				    sc->sc_openf > 0)
E 52
E 50
					sc->sc_openf = -1;
			}
E 7
			break;
D 7
		if (ts.ts_sts.xs0 & TMK) {		/* tape mark */
			ts.ts_sts.rbpcr = bp->b_bcount;
E 7
I 7

		case TS_REJECT:		/* function reject */
D 50
			if (state == SIO && sc->sc_sts.s_xs0 & TS_WLE)
E 50
I 50
			if (state == SIO && sc->sc_ts.t_sts.s_xs0 & TS_WLE)
E 50
D 41
				printf("ts%d: write locked\n", TSUNIT(bp->b_dev));
E 41
I 41
				tprintf(sc->sc_ttyp, "ts%d: write locked\n",
D 50
				    TSUNIT(bp->b_dev));
E 41
			if ((sc->sc_sts.s_xs0 & TS_ONL) == 0)
E 50
I 50
				    tsunit);
			if ((sc->sc_ts.t_sts.s_xs0 & TS_ONL) == 0)
E 50
D 41
				printf("ts%d: offline\n", TSUNIT(bp->b_dev));
E 41
I 41
				tprintf(sc->sc_ttyp, "ts%d: offline\n",
D 50
				    TSUNIT(bp->b_dev));
E 50
I 50
				    tsunit);
E 50
E 41
E 7
			break;
		}
D 7
		errclass = 1;
		break;

	case 010:		/* recoverable, tape moved */
		if (state==SIO && ++bp->b_errcnt < 10) {
			ts.ts_cmd.c_cmd |= 01000;	/* redo bit */
			tstab.b_active = SIO;
			tsaddr->tsdb = ts_uba;
			return;
		}
		errclass = 1;
		break;

	case 006:		/* Function reject */
		if (state==SIO && ts.ts_sts.xs0 & WLE)
			printf("Tape needs a ring\n");
		if ((ts.ts_sts.xs0&ONL) == 0)		/* tape offline */
			printf("Tape offline\n");
		errclass = 2;
E 7
I 7
		/*
		 * Couldn't recover error
		 */
D 12
		printf("ts%d: hard error bn%d xs0=%b\n", TSUNIT(bp->b_dev),
E 12
I 12
D 41
		printf("ts%d: hard error bn%d xs0=%b", TSUNIT(bp->b_dev),
E 12
		    bp->b_blkno, sc->sc_sts.s_xs0, TSXS0_BITS);
E 41
I 41
D 50
		tprintf(sc->sc_ttyp, "ts%d: hard error bn%d xs0=%b",
		    TSUNIT(bp->b_dev), bp->b_blkno, sc->sc_sts.s_xs0, TSXS0_BITS);
E 41
I 12
		if (sc->sc_sts.s_xs1)
D 41
			printf(" xs1=%b", sc->sc_sts.s_xs1, TSXS1_BITS);
E 41
I 41
			tprintf(sc->sc_ttyp, " xs1=%b", sc->sc_sts.s_xs1,
E 50
I 50
		tprintf(sc->sc_ttyp, "ts%d: hard error bn%d tssr=%b xs0=%b",
		    tsunit, bp->b_blkno, addr->tssr, TSSR_BITS,
		    sc->sc_ts.t_sts.s_xs0, TSXS0_BITS);
		if (sc->sc_ts.t_sts.s_xs1)
			tprintf(sc->sc_ttyp, " xs1=%b", sc->sc_ts.t_sts.s_xs1,
E 50
			    TSXS1_BITS);
E 41
D 50
		if (sc->sc_sts.s_xs2)
D 41
			printf(" xs2=%b", sc->sc_sts.s_xs2, TSXS2_BITS);
E 41
I 41
			tprintf(sc->sc_ttyp, " xs2=%b", sc->sc_sts.s_xs2,
E 50
I 50
		if (sc->sc_ts.t_sts.s_xs2)
			tprintf(sc->sc_ttyp, " xs2=%b", sc->sc_ts.t_sts.s_xs2,
E 50
			    TSXS2_BITS);
E 41
D 50
		if (sc->sc_sts.s_xs3)
D 41
			printf(" xs3=%b", sc->sc_sts.s_xs3, TSXS3_BITS);
		printf("\n");
E 41
I 41
			tprintf(sc->sc_ttyp, " xs3=%b", sc->sc_sts.s_xs3,
E 50
I 50
		if (sc->sc_ts.t_sts.s_xs3)
			tprintf(sc->sc_ttyp, " xs3=%b", sc->sc_ts.t_sts.s_xs3,
E 50
			    TSXS3_BITS);
		tprintf(sc->sc_ttyp, "\n");
E 41
E 12
		bp->b_flags |= B_ERROR;
		goto opdone;
E 7
	}
D 7
	if (errclass)
		printf("tp: %o %o %o %o %o %o %o %o\n", tsaddr->tssr,
		  ts.ts_sts.s_sts, ts.ts_sts.len, ts.ts_sts.rbpcr,
		  ts.ts_sts.xs0, ts.ts_sts.xs1, ts.ts_sts.xs2, ts.ts_sts.xs3);
	switch(state) {
E 7
I 7
	/*
	 * Advance tape control FSM.
	 */
ignoreerr:
	switch (state) {

E 7
	case SIO:
D 7
		ts_blkno++;
D 5
		if (ts_iouba)
			ubafree(ts_iouba);
		else
			printf("uba alloc botch\n");
		ts_iouba = 0;
E 5
I 5
		ubarelse(&ts_ubinfo);
E 7
I 7
		/*
		 * Read/write increments tape block number
		 */
		sc->sc_blkno++;
I 49
		sc->sc_blks++;
		if (um->um_tab.b_errcnt)
			sc->sc_softerrs++;
E 49
		goto opdone;

E 7
E 5
	case SCOM:
D 7
		tstab.b_errcnt = 0;
		tstab.b_actf = bp->av_forw;
		bp->b_resid = ts.ts_sts.rbpcr;
		iodone(bp);
		break;
E 7
I 7
		/*
		 * For forward/backward space record update current position.
		 */
D 50
		if (bp == &ctsbuf[TSUNIT(bp->b_dev)])
D 46
		switch (bp->b_command) {
E 46
I 46
		switch ((int)bp->b_command) {
E 50
I 50
		if (bp == &ctsbuf[tsunit])
			switch ((int)bp->b_command) {
E 50
E 46
E 7

D 7
	case SSFOR:
	case SSREV:
		ts_blkno = dbtofsb(bp->b_blkno);
		break;
E 7
I 7
D 50
		case TS_SFORW:
			sc->sc_blkno += bp->b_repcnt;
			break;
E 50
I 50
			case TS_SFORW:
				sc->sc_blkno += bp->b_repcnt;
				break;
E 50
E 7

I 7
D 50
		case TS_SREV:
			sc->sc_blkno -= bp->b_repcnt;
			break;
		}
E 50
I 50
			case TS_SREV:
				sc->sc_blkno -= bp->b_repcnt;
				break;
			}
E 50
		goto opdone;

	case SSEEK:
D 24
		sc->sc_blkno = dbtofsb(bp->b_blkno);
E 24
I 24
		sc->sc_blkno = bdbtofsb(bp->b_blkno);
E 24
		goto opcont;

E 7
	default:
D 7
		printf("Unknown tape interrupt\n");
		errclass = 2;
		break;
E 7
I 7
		panic("tsintr");
E 7
	}
D 7
	if (errclass > 1) {
		while (bp = tstab.b_actf) {
			bp->b_flags |= B_ERROR;
			iodone(bp);
			tstab.b_actf = bp->av_forw;
E 7
I 7
opdone:
	/*
	 * Reset error count and remove
	 * from device queue.
	 */
	um->um_tab.b_errcnt = 0;
D 8
	um->um_tab.b_actf = bp->av_forw;
E 8
I 8
	um->um_tab.b_actf->b_actf = bp->av_forw;
E 8
D 50
	bp->b_resid = sc->sc_sts.s_rbpcr;
E 50
I 50
	bp->b_resid = sc->sc_ts.t_sts.s_rbpcr;
E 50
	ubadone(um);
I 12
D 22
#ifdef TSDEBUG
E 12
I 8
	printd("  iodone\n");
I 12
#endif
E 22
E 12
E 8
D 50
	iodone(bp);
D 8
	if (um->um_tab.b_actf == 0)
E 8
I 8
	if (um->um_tab.b_actf->b_actf == 0)
E 50
I 50
	biodone(bp);
	if (um->um_tab.b_actf->b_actf == 0) {
		um->um_tab.b_active = 0;
E 50
E 8
		return;
I 50
	}
E 50
opcont:
	tsstart(um);
}

tsseteof(bp)
	register struct buf *bp;
{
	register int tsunit = TSUNIT(bp->b_dev);
D 50
	register struct ts_softc *sc = &ts_softc[tsunit];
E 50
I 50
	register struct ts_softc *sc = &ts_softc[tsdinfo[tsunit]->ui_ctlr];
E 50

D 50
	if (bp == &ctsbuf[TSUNIT(bp->b_dev)]) {
E 50
I 50
	if (bp == &ctsbuf[tsunit]) {
E 50
D 24
		if (sc->sc_blkno > dbtofsb(bp->b_blkno)) {
E 24
I 24
		if (sc->sc_blkno > bdbtofsb(bp->b_blkno)) {
E 24
			/* reversing */
D 24
			sc->sc_nxrec = dbtofsb(bp->b_blkno) - sc->sc_sts.s_rbpcr;
E 24
I 24
D 50
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) - sc->sc_sts.s_rbpcr;
E 50
I 50
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) -
				sc->sc_ts.t_sts.s_rbpcr;
E 50
E 24
			sc->sc_blkno = sc->sc_nxrec;
		} else {
			/* spacing forward */
D 24
			sc->sc_blkno = dbtofsb(bp->b_blkno) + sc->sc_sts.s_rbpcr;
E 24
I 24
D 50
			sc->sc_blkno = bdbtofsb(bp->b_blkno) + sc->sc_sts.s_rbpcr;
E 50
I 50
			sc->sc_blkno = bdbtofsb(bp->b_blkno) +
				sc->sc_ts.t_sts.s_rbpcr;
E 50
E 24
			sc->sc_nxrec = sc->sc_blkno - 1;
E 7
		}
D 7
	}
	tsstart();
E 7
I 7
		return;
	} 
	/* eof on read */
D 24
	sc->sc_nxrec = dbtofsb(bp->b_blkno);
E 24
I 24
	sc->sc_nxrec = bdbtofsb(bp->b_blkno);
E 24
E 7
}

D 27
tsread(dev)
E 27
I 27
D 52
tsread(dev, uio)
E 27
I 7
	dev_t dev;
I 27
	struct uio *uio;
E 27
E 7
{
I 29
D 50
	int errno;
E 50
E 29
I 7

E 7
D 27
	tsphys(dev);
E 27
I 27
D 29
	u.u_error = tsphys(dev, uio);
E 27
D 7
	physio(tsstrategy, &rtsbuf, dev, B_READ, minphys);
E 7
I 7
	if (u.u_error)
		return;
D 27
	physio(tsstrategy, &rtsbuf[TSUNIT(dev)], dev, B_READ, minphys);
E 27
I 27
	physio(tsstrategy, &rtsbuf[TSUNIT(dev)], dev, B_READ, minphys, uio);
E 29
I 29
D 50
	errno = tsphys(dev, uio);
	if (errno)
		return (errno);
E 50
	return (physio(tsstrategy, &rtsbuf[TSUNIT(dev)], dev, B_READ, minphys, uio));
E 29
E 27
E 7
}

D 28
tswrite(dev)
E 28
I 28
tswrite(dev, uio)
E 28
I 7
	dev_t dev;
I 28
	struct uio *uio;
E 28
E 7
{
I 29
D 50
	int errno;
E 50
E 29
I 7

E 7
D 27
	tsphys(dev);
E 27
I 27
D 28
	tsphys(dev, 0);
E 28
I 28
D 29
	u.u_error = tsphys(dev, uio);
E 28
E 27
D 7
	physio(tsstrategy, &rtsbuf, dev, B_WRITE, minphys);
E 7
I 7
	if (u.u_error)
		return;
D 27
	physio(tsstrategy, &rtsbuf[TSUNIT(dev)], dev, B_WRITE, minphys);
E 27
I 27
D 28
	physio(tsstrategy, &rtsbuf[TSUNIT(dev)], dev, B_WRITE, minphys, 0);
E 28
I 28
	physio(tsstrategy, &rtsbuf[TSUNIT(dev)], dev, B_WRITE, minphys, uio);
E 29
I 29
D 50
	errno = tsphys(dev, uio);
	if (errno)
		return (errno);
E 50
	return (physio(tsstrategy, &rtsbuf[TSUNIT(dev)], dev, B_WRITE, minphys, uio));
E 29
E 28
E 27
E 7
}

E 52
I 7
D 50
/*
 * Check that a raw device exists.
 * If it does, set up sc_blkno and sc_nxrec
 * so that the tape will appear positioned correctly.
 */
E 7
D 27
tsphys(dev)
E 27
I 27
tsphys(dev, uio)
E 27
I 7
	dev_t dev;
I 27
	struct uio *uio;
E 27
E 7
{
D 7
	register unit;
	daddr_t a;
E 7
I 7
	register int tsunit = TSUNIT(dev);
	register daddr_t a;
	register struct ts_softc *sc;
	register struct uba_device *ui;
E 7

D 7
	a = u.u_offset >> 9;
	ts_blkno = dbtofsb(a);
	ts_nxrec = dbtofsb(a)+1;
E 7
I 7
D 28
	if (tsunit >= NTS || (ui=tsdinfo[tsunit]) == 0 || ui->ui_alive == 0) {
		u.u_error = ENXIO;
E 28
I 28
	if (tsunit >= NTS || (ui=tsdinfo[tsunit]) == 0 || ui->ui_alive == 0)
E 28
D 27
		return;
E 27
I 27
		return (ENXIO);
E 27
D 28
	}
E 28
	sc = &ts_softc[tsunit];
D 24
	a = dbtofsb(u.u_offset >> 9);
E 24
I 24
D 27
	a = bdbtofsb(u.u_offset >> 9);
E 27
I 27
D 28
	if (uio)
		a = bdbtofsb(uio->uio_offset >> 9);
	else
		a = bdbtofsb(u.u_offset >> 9);
E 28
I 28
	a = bdbtofsb(uio->uio_offset >> 9);
E 28
E 27
E 24
	sc->sc_blkno = a;
	sc->sc_nxrec = a + 1;
I 27
	return (0);
E 27
E 7
I 2
}

E 50
D 7
#define	UBMAP	(int *)0xf30800

int dtsinfo;
I 4
struct tsmesg dts;
E 4

twall(start, num)
E 7
I 7
tsreset(uban)
	int uban;
E 7
{
D 7
	register struct device *tsaddr = TSPHYS;
	register int *ubap = UBMAP;
	register int p, i;
E 7
I 7
	register struct uba_ctlr *um;
I 22
	register struct uba_device *ui;
D 52
	register struct buf *dp;
E 52
E 22
D 50
	register ts11;
E 50
I 50
	register int ts11, i;
E 50
D 18
	register struct buf *dp;
E 18
E 7

D 7
	tsinit();
	/* dump mem */
	p = PG_V;
	i = 0;
	while (i<num) {
		*(ubap) = p|i++;
		*(ubap+1) = p|i;
		dts.ts_cmd.c_loba = 0;
		dts.ts_cmd.c_hiba = 0;
		dts.ts_cmd.c_size = NBPG;
		dts.ts_cmd.c_cmd = ACK+CVC+WRITE;
		tsaddr->tsdb = dtsinfo;
		twait();
E 7
I 7
	for (ts11 = 0; ts11 < NTS; ts11++) {
		if ((um = tsminfo[ts11]) == 0 || um->um_alive == 0 ||
D 50
		   um->um_ubanum != uban)
E 50
I 50
		    um->um_ubanum != uban)
E 50
			continue;
		printf(" ts%d", ts11);
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
D 22
		ts_softc[ts11].sc_openf = -1;
E 22
I 22
		if (ts_softc[ts11].sc_openf > 0)
			ts_softc[ts11].sc_openf = -1;
E 22
		if (um->um_ubinfo) {
D 50
			printf("<%d>", (um->um_ubinfo>>28)&0xf);
E 50
I 50
			printf("<%d>", UBAI_BDP(um->um_ubinfo));
E 50
D 36
			ubadone(um);
E 36
I 36
			um->um_ubinfo = 0;
E 36
		}
I 22
D 50
		if ((ui = tsdinfo[ts11]) && ui->ui_mi == um && ui->ui_alive) {
			dp = &tsutab[ts11];
			dp->b_active = 0;
			dp->b_forw = 0;
			if (um->um_tab.b_actf == NULL)
				um->um_tab.b_actf = dp;
			else
				um->um_tab.b_actl->b_forw = dp;
			um->um_tab.b_actl = dp;
E 50
I 50
		/*
		 * tsdinfo should be 1-to-1 with tsminfo, but someone
		 * might have screwed up the config file:
		 */
		for (i = 0; i < NTS; i++) {
			if ((ui = tsdinfo[i]) != NULL &&
			    ui->ui_alive && ui->ui_mi == um) {
				um->um_tab.b_actf = um->um_tab.b_actl =
				    &tsutab[i];
				break;
			}
E 50
		}
I 40
D 50
		ts_softc[ts11].sc_mapped = 0;
E 50
I 50
		tsmap(&ts_softc[ts11], uban, (int *)NULL);
E 50
E 40
E 22
D 19
		tsinit(ts11);
E 19
I 19
		(void) tsinit(ts11);
E 19
		tsstart(um);
E 7
	}
D 7
	printf("done\n");
E 7
}

D 7
tsinit()
E 7
I 7
/*ARGSUSED*/
D 26
tsioctl(dev, cmd, addr, flag)
	caddr_t addr;
E 26
I 26
tsioctl(dev, cmd, data, flag)
	caddr_t data;
E 26
	dev_t dev;
E 7
{
D 7
	register struct device *tsaddr = TSPHYS;
	register struct tsmesg *tsm;
	register int *ubap = UBMAP;
	register i;
E 7
I 7
	int tsunit = TSUNIT(dev);
D 50
	register struct ts_softc *sc = &ts_softc[tsunit];
E 50
I 50
	register struct ts_softc *sc = &ts_softc[tsdinfo[tsunit]->ui_ctlr];
E 50
	register struct buf *bp = &ctsbuf[TSUNIT(dev)];
D 50
	register callcount;
E 50
I 50
	register int callcount;
E 50
	int fcount;
D 26
	struct mtop mtop;
	struct mtget mtget;
E 26
I 26
	struct mtop *mtop;
	struct mtget *mtget;
E 26
	/* we depend of the values and order of the MT codes here */
D 50
	static tsops[] =
E 50
I 50
	static int tsops[] =
E 50
D 13
	 {TS_WEOF,TS_SFORW,TS_SREV,TS_SFORWF,TS_SREVF,TS_REW,TS_OFFL,TS_SENSE};
E 13
I 13
	 {TS_WEOF,TS_SFORWF,TS_SREVF,TS_SFORW,TS_SREV,TS_REW,TS_OFFL,TS_SENSE};
E 13
E 7

D 7
	tsaddr->tssr = 0;
	while ((tsaddr->tssr&SSR)==0)
		;
	i = (int)&dts;
	i &= 0xefffff;
	dtsinfo = ((i&0777)|02000);
	tsm = (struct tsmesg *)dtsinfo;
	i >>= 9;
	i |= PG_V;
	*(ubap+2) = i;
	*(ubap+3) = i+1;
	dts.ts_cmd.c_cmd = ACK + 04;
D 4
	dts.ts_cmd.c_loba = &tsm->ts_char;
E 4
I 4
	dts.ts_cmd.c_loba = (int)&tsm->ts_char;
E 4
	dts.ts_cmd.c_hiba = 0;
	dts.ts_cmd.c_size = sizeof(dts.ts_char);
D 4
	dts.ts_char.char_loba = &tsm->ts_sts;
E 4
I 4
	dts.ts_char.char_loba = (int)&tsm->ts_sts;
E 4
	dts.ts_char.char_hiba = 0;
	dts.ts_char.char_size = sizeof(dts.ts_sts);
	dts.ts_char.char_mode = 0400;
	tsaddr->tsdb = dtsinfo;
	twait();
E 7
I 7
	switch (cmd) {
I 26

E 26
	case MTIOCTOP:	/* tape operation */
D 26
		if (copyin((caddr_t)addr, (caddr_t)&mtop, sizeof(mtop))) {
			u.u_error = EFAULT;
			return;
		}
		switch(mtop.mt_op) {
E 26
I 26
		mtop = (struct mtop *)data;
D 31
		switch(mtop->mt_op) {
E 31
I 31
		switch (mtop->mt_op) {
E 31

E 26
		case MTWEOF:
D 26
			callcount = mtop.mt_count;
E 26
I 26
			callcount = mtop->mt_count;
E 26
			fcount = 1;
			break;
I 26

E 26
		case MTFSF: case MTBSF:
I 12
D 13
			callcount = mtop.mt_count;
			fcount = INF;
			break;
E 13
E 12
		case MTFSR: case MTBSR:
			callcount = 1;
D 26
			fcount = mtop.mt_count;
E 26
I 26
			fcount = mtop->mt_count;
E 26
			break;
I 26

E 26
		case MTREW: case MTOFFL: case MTNOP:
			callcount = 1;
			fcount = 1;
			break;
I 26

E 26
		default:
D 31
			u.u_error = ENXIO;
			return;
E 31
I 31
			return (ENXIO);
E 31
		}
D 31
		if (callcount <= 0 || fcount <= 0) {
			u.u_error = ENXIO;
			return;
		}
E 31
I 31
		if (callcount <= 0 || fcount <= 0)
			return (EINVAL);
E 31
		while (--callcount >= 0) {
D 26
			tscommand(dev, tsops[mtop.mt_op], fcount);
			if ((mtop.mt_op == MTFSR || mtop.mt_op == MTBSR) &&
E 26
I 26
			tscommand(dev, tsops[mtop->mt_op], fcount);
			if ((mtop->mt_op == MTFSR || mtop->mt_op == MTBSR) &&
E 26
D 32
			    bp->b_resid) {
E 32
I 32
			    bp->b_resid)
E 32
D 31
				u.u_error = EIO;
				break;
			}
E 31
I 31
				return (EIO);
E 31
D 50
			if ((bp->b_flags&B_ERROR) || sc->sc_sts.s_xs0&TS_BOT)
E 50
I 50
			if ((bp->b_flags&B_ERROR) ||
			    sc->sc_ts.t_sts.s_xs0&TS_BOT)
E 50
				break;
		}
D 31
		geterror(bp);
		return;
E 31
I 31
D 34
		geterror(bp);		/* XXX */
		return (u.u_error);	/* XXX */
E 34
I 34
		return (geterror(bp));
E 34
E 31
I 26

E 26
	case MTIOCGET:
D 26
		mtget.mt_dsreg = 0;
		mtget.mt_erreg = sc->sc_sts.s_xs0;
		mtget.mt_resid = sc->sc_resid;
I 9
		mtget.mt_type = MT_ISTS;
E 9
		if (copyout((caddr_t)&mtget, addr, sizeof(mtget)))
			u.u_error = EFAULT;
E 26
I 26
		mtget = (struct mtget *)data;
		mtget->mt_dsreg = 0;
D 50
		mtget->mt_erreg = sc->sc_sts.s_xs0;
E 50
I 50
		mtget->mt_erreg = sc->sc_ts.t_sts.s_xs0;
E 50
		mtget->mt_resid = sc->sc_resid;
		mtget->mt_type = MT_ISTS;
E 26
D 31
		return;
E 31
I 31
		break;
E 31
I 26

E 26
	default:
D 31
		u.u_error = ENXIO;
E 31
I 31
		return (ENXIO);
E 31
	}
I 31
	return (0);
E 31
E 7
}

D 7
teof()
E 7
I 7
#define	DBSIZE	20

D 50
tsdump()
E 50
I 50
tsdump(dev)
	dev_t dev;
E 50
E 7
{
I 7
	register struct uba_device *ui;
D 50
	register struct uba_regs *up;
E 50
I 50
	register struct uba_regs *uba;
E 50
D 22
	register struct device *addr;
E 22
I 22
	register struct tsdevice *addr;
E 22
D 50
	int blk, num;
	int start;
E 50
I 50
	register int i;
	register struct pte *io;
	int blk, num, unit, reg, start;
	u_short db;
	struct ts_tsdata *tc, *tc_ubaddr;
E 50
E 7

D 7
	dtscommand(WTM);
E 7
I 7
D 50
	start = 0;
	num = maxfree;
E 50
I 50
	unit = TSUNIT(dev);
	if (unit >= NTS)
		return (ENXIO);
E 50
#define	phys(a,b)	((b)((int)(a)&0x7fffffff))
D 50
	if (tsdinfo[0] == 0)
E 50
I 50
	ui = phys(tsdinfo[unit], struct uba_device *);
	if (ui->ui_alive == 0)
E 50
		return (ENXIO);
D 50
	ui = phys(tsdinfo[0], struct uba_device *);
	up = phys(ui->ui_hd, struct uba_hd *)->uh_physuba;
D 8
#if VAX780
	if (cpu == VAX_780)
		ubainit(up);
#endif
E 8
I 8
D 33
	ubainit(up);
E 33
I 33
D 35
	ubainit(ui->ui_hd);
E 35
I 35
	ubainit(up);
E 35
E 33
E 8
	DELAY(1000000);
E 50
I 50
	uba = phys(ui->ui_hd, struct uba_hd *)->uh_physuba;
	ubainit(uba);
E 50
D 22
	addr = (struct device *)ui->ui_physaddr;
E 22
I 22
	addr = (struct tsdevice *)ui->ui_physaddr;
I 50

	/* map a ts_tsdata structure */
	tc = phys(&ts_softc[0].sc_ts, struct ts_tsdata *);
	num = btoc(sizeof(struct ts_tsdata)) + 1;
	io = &uba->uba_map[reg = NUBMREG - num];
	for (i = 0; i < num; i++)
		*(int *)io++ = UBAMR_MRV | (btop(tc) + i);
	i = (((int)tc & PGOFSET) | (reg << 9));
	tc_ubaddr = (struct ts_tsdata *)i;
	db = i + ((i >> 16) & 3);

	/* init the drive */
E 50
E 22
	addr->tssr = 0;
	tswait(addr);
D 50
	while (num > 0) {
E 50
I 50
	if ((addr->tssr & (TS_NBA|TS_OFL)) != TS_NBA)
		return (EFAULT);

	/* set characteristics */
	i = (int)&tc_ubaddr->t_char;
	tc->t_cmd.c_loba = i;
	tc->t_cmd.c_hiba = (i >> 16) & 3;
	tc->t_cmd.c_size = sizeof(struct ts_char);
	tc->t_cmd.c_cmd = TS_ACK | TS_CVC | TS_SETCHR;
	tc->t_char.char_addr = (int)&tc_ubaddr->t_sts;
	tc->t_char.char_size = sizeof(struct ts_sts);
	tc->t_char.char_mode = TS_ESS;
	addr->tsdb = db;
	tswait(addr);
	if (addr->tssr & TS_NBA)
		return (ENXIO);

	/* dump */
	tc->t_cmd.c_cmd = TS_ACK | TS_WCOM;
	tc->t_cmd.c_repcnt = 1;
	num = maxfree;
	for (start = 0, num = maxfree; num > 0; start += blk, num -= blk) {
E 50
		blk = num > DBSIZE ? DBSIZE : num;
D 50
		tsdwrite(start, blk, addr, up);
		start += blk;
		num -= blk;
E 50
I 50
		io = uba->uba_map;
		for (i = 0; i < blk; i++)
			*(int *)io++ = UBAMR_MRV | (1 << UBAMR_DPSHIFT) |
				(start + i);
		*(int *)io = 0;
		addr->tsdb = db;
		tswait(addr);
E 50
	}
D 50
	tseof(addr);
	tseof(addr);
E 50
I 50

	/* eof */
	tc->t_cmd.c_cmd = TS_WEOF;
	addr->tsdb = db;
E 50
	tswait(addr);
I 50
	addr->tsdb = db;
	tswait(addr);

E 50
	if (addr->tssr&TS_SC)
		return (EIO);
	addr->tssr = 0;
	tswait(addr);
	return (0);
E 7
}

D 7
rewind()
E 7
I 7
D 50
tsdwrite(dbuf, num, addr, up)
D 33
	register dbuf, num;
E 33
I 33
	register int dbuf, num;
E 33
D 22
	register struct device *addr;
E 22
I 22
	register struct tsdevice *addr;
E 22
	struct uba_regs *up;
E 7
{
I 7
	register struct pte *io;
	register int npf;
E 7

D 7
	dtscommand(REW);
E 7
I 7
	tswait(addr);
	io = up->uba_map;
	npf = num+1;
	while (--npf != 0)
		 *(int *)io++ = (dbuf++ | (1<<UBAMR_DPSHIFT) | UBAMR_MRV);
	*(int *)io = 0;
#ifdef notyet
	addr->tsbc = -(num*NBPG);
	addr->tsba = 0;
	addr->tscs = TS_WCOM | TM_GO;
#endif
E 7
}

E 50
D 7
dtscommand(com)
E 7
I 7
tswait(addr)
D 22
	register struct device *addr;
E 22
I 22
	register struct tsdevice *addr;
E 22
E 7
{
D 7
	register struct device *tsaddr = TSPHYS;
E 7
I 7
D 50
	register s;
E 50
E 7

D 7
	dts.ts_cmd.c_cmd = ACK+CVC+com;
	dts.ts_cmd.c_loba = 1;
	tsaddr->tsdb = dtsinfo;
	twait();
E 7
I 7
D 50
	do
		s = addr->tssr;
	while ((s & TS_SSR) == 0);
E 50
I 50
	while ((addr->tssr & TS_SSR) == 0)
		/* void */;
E 50
E 7
}

D 7
twait()
E 7
I 7
D 50
tseof(addr)
D 22
	struct device *addr;
E 22
I 22
	struct tsdevice *addr;
E 22
E 7
{
D 7
	register struct device *tsaddr = TSPHYS;
	register i;
E 7

D 7
	while ((tsaddr->tssr&SSR)==0)
		;
	i = tsaddr->tssr;
	if (i&SC)
		printf("tssr %x ", i);
E 7
I 7
	tswait(addr);
#ifdef notyet
	addr->tscs = TS_WEOF | TM_GO;
#endif
E 7
E 2
}
#endif
E 50
I 50
#endif /* NTS > 0 */
E 50
E 1
