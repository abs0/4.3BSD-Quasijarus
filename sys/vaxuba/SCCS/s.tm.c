h15110
s 00036/00081/00957
d D 7.4 88/05/06 17:16:47 bostic 76 75
c changes for raw{read,write} stuff
e
s 00004/00002/01034
d D 7.3 88/02/08 20:37:45 karels 75 74
c make BGL code work (was looking at status for backspace)
e
s 00026/00005/01010
d D 7.2 87/04/17 14:09:47 karels 74 73
c fix race in open; log excessive soft errs
e
s 00001/00001/01014
d D 7.1 86/06/05 01:16:57 mckusick 73 72
c 4.3BSD release version
e
s 00001/00001/01014
d D 6.10 86/02/23 23:17:53 karels 72 71
c lint
e
s 00001/00001/01014
d D 6.9 86/02/20 19:53:10 karels 71 70
c lint
e
s 00003/00002/01012
d D 6.8 85/10/01 09:33:03 karels 70 69
c no ENXIO for drive in use
e
s 00031/00004/00983
d D 6.7 85/09/20 14:46:40 mckusick 69 68
c support for AVIV
e
s 00007/00001/00980
d D 6.6 85/06/08 14:22:45 mckusick 68 67
c Add copyright
e
s 00006/00002/00975
d D 6.5 85/03/13 09:44:31 ralph 67 66
c change error message printf's to tprintf's to the user.
e
s 00017/00017/00960
d D 6.4 84/08/29 20:10:07 bloom 66 65
c Change to includes.  No more ../h
e
s 00001/00004/00976
d D 6.3 83/09/25 12:50:38 karels 65 64
c simpler fix
e
s 00007/00001/00973
d D 6.2 83/09/08 15:07:22 karels 64 61
c get resid right even if >32767
e
s 00007/00001/00973
d R 6.2 83/09/08 12:10:24 karels 63 61
c correct resid even if >32767 (tmbc is not negative)
e
s 00004/00001/00973
d R 6.2 83/09/07 10:35:27 karels 62 61
c Fix anomalous resid if resid >32767 (tmbc isn't negative)
e
s 00000/00000/00974
d D 6.1 83/07/29 07:29:02 sam 61 60
c 4.2 distribution
e
s 00002/00001/00972
d D 4.60 82/12/17 12:03:29 sam 60 59
c sun merge
e
s 00001/00001/00972
d D 4.59 82/11/26 18:17:23 sam 59 58
c don't call ubadone at ubareset time
e
s 00001/00002/00972
d D 4.58 82/10/17 23:06:26 root 58 57
c lint
e
s 00001/00000/00973
d D 4.57 82/10/17 20:18:23 root 57 56
c lint
e
s 00017/00025/00956
d D 4.56 82/10/17 11:50:20 root 56 55
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00004/00004/00977
d D 4.55 82/10/10 17:28:35 root 55 54
c header files for vax are in their place
e
s 00010/00008/00971
d D 4.54 82/09/12 03:09:05 root 54 53
c 
e
s 00006/00010/00973
d D 4.53 82/08/22 21:19:34 root 53 52
c fully uio()'d
e
s 00015/00008/00968
d D 4.52 82/08/13 00:16:47 root 52 51
c changes for char dev uio'ing
e
s 00026/00022/00950
d D 4.51 82/08/01 19:25:55 sam 51 50
c new ioctl's
e
s 00001/00001/00971
d D 4.50 82/07/15 19:54:39 kre 50 49
c probe routines return size of unibus dev regs to reserve space
e
s 00013/00013/00959
d D 4.49 82/07/13 18:14:00 sam 49 48
c bdbtofsb maps block device blocks DEV_BSIZE units
e
s 00001/00001/00971
d D 4.48 82/05/27 08:55:35 wnj 48 47
c fix typo so can handle more than one transport
e
s 00001/00001/00971
d D 4.47 82/03/28 17:06:05 wnj 47 46
c fix per probert
e
s 00015/00028/00957
d D 4.46 82/02/03 19:34:49 root 46 45
c mods from shannon finally installed
e
s 00009/00006/00976
d D 4.45 82/01/17 20:28:31 root 45 44
c remove spl0's from block tape routines
e
s 00001/00000/00981
d D 4.44 81/11/18 15:50:10 wnj 44 43
c lint
e
s 00003/00002/00978
d D 4.43 81/11/10 12:39:36 root 43 42
c fix splx bug in timer routines
e
s 00001/00001/00979
d D 4.42 81/08/31 03:17:56 root 42 41
c fix per mosher
e
s 00002/00001/00978
d D 4.41 81/08/30 16:19:14 wnj 41 40
c fix per sam leffler
e
s 00001/00001/00978
d D 4.40 81/07/09 04:20:26 root 40 39
c lint
e
s 00001/00001/00978
d D 4.39 81/07/05 22:28:11 bugs 39 38
c fix per pur-ee!bruner
e
s 00013/00007/00966
d D 4.38 81/05/09 22:33:53 root 38 37
c better error messages
e
s 00005/00005/00968
d D 4.37 81/04/28 03:04:07 root 37 36
c lint
e
s 00004/00002/00969
d D 4.36 81/04/15 02:36:16 wnj 36 35
c after interrupt while tape rewinding set timeout to 5 minutes
e
s 00013/00000/00958
d D 4.35 81/04/14 14:19:51 root 35 34
c fix for generic interlocking tm and ts
e
s 00042/00003/00916
d D 4.34 81/04/09 15:11:11 root 34 33
c timer for lost interrupt added
e
s 00001/00001/00918
d D 4.33 81/04/08 19:04:32 root 33 32
c fix bug clobbering tape when reading multi-set tape
e
s 00001/00001/00918
d D 4.32 81/04/03 08:29:45 root 32 31
c speeling error
e
s 00001/00000/00918
d D 4.31 81/04/03 07:38:30 toy 31 30
c Added type to MTIOCGET ioctl.
e
s 00001/00004/00917
d D 4.30 81/03/21 15:54:52 wnj 30 29
c restore id keyw; simplify ubainit
e
s 00007/00005/00914
d D 4.29 81/03/11 18:45:13 wnj 29 28
c fix to sensing when multiple transports
e
s 00002/00003/00917
d D 4.28 81/03/10 06:51:11 wnj 28 27
c check FWRITE only, not only FWRITE for WRL
e
s 00008/00002/00912
d D 4.27 81/03/09 12:44:19 wnj 27 26
c hacked in printfs for testing
e
s 00001/00001/00913
d D 4.26 81/03/09 01:54:23 wnj 26 25
c %G% -> %E%
e
s 00007/00006/00907
d D 4.25 81/03/09 00:34:39 wnj 25 24
c lint
e
s 00212/00145/00701
d D 4.24 81/03/08 20:12:54 wnj 24 23
c fixups just pre lint
e
s 00029/00018/00817
d D 4.23 81/03/07 14:28:32 wnj 23 22
c after attempt at ht driver at cc again; working with new 
c field names
e
s 00015/00027/00820
d D 4.22 81/03/06 11:31:58 wnj 22 21
c new format of error prints; no more TM UBA late messages
e
s 00004/00004/00843
d D 4.21 81/03/03 12:39:14 wnj 21 20
c further driver work... up now handles spin down; rest still dont
e
s 00001/00001/00846
d D 4.20 81/02/28 13:41:16 wnj 20 19
c er=%b
e
s 00001/00001/00846
d D 4.19 81/02/26 04:29:10 wnj 19 18
c cosmetic for new config and 750/780
e
s 00003/00001/00844
d D 4.18 81/02/25 21:03:31 wnj 18 17
c almost working versions
e
s 00019/00006/00826
d D 4.17 81/02/25 17:16:58 wnj 17 16
c rearrange to do TM_SDWN if necessary
e
s 00020/00020/00812
d D 4.16 81/02/23 20:30:38 wnj 16 15
c name changes
e
s 00004/00004/00828
d D 4.15 81/02/22 21:46:49 wnj 15 14
c working interlocked system
e
s 00441/00219/00391
d D 4.14 81/02/21 21:21:25 wnj 14 13
c first working uba interlockable version
e
s 00027/00024/00583
d D 4.13 81/02/19 22:35:15 wnj 13 12
c non-werking but ubago version
e
s 00118/00109/00489
d D 4.12 81/02/17 17:34:22 wnj 12 11
c minor cleanups... for dh: DELAY(5)s
e
s 00044/00042/00554
d D 4.11 81/02/16 20:57:31 wnj 11 10
c new minfo strategy
e
s 00025/00028/00571
d D 4.10 81/02/15 12:10:09 kre 10 9
c bootable autoconf version
e
s 00139/00115/00460
d D 4.9 81/02/10 13:20:01 wnj 9 8
c compilable first uba autoconf version
e
s 00020/00008/00555
d D 4.8 81/02/07 15:49:31 wnj 8 7
c new dump code
e
s 00008/00006/00555
d D 4.7 81/01/31 23:30:39 kre 7 6
c add NOP as tape operation, fix dump to be 1600 bpi and add wait
e
s 00006/00003/00555
d D 4.6 81/01/28 11:43:04 wnj 6 5
c fixes to bpd purging to fool C compiler (to not use bb*)
e
s 00006/00012/00552
d D 4.5 80/12/30 18:51:44 wnj 5 4
c ubafree() becomes ubarelse() to fix race conditions
e
s 00006/00006/00558
d D 4.4 80/12/26 12:20:20 wnj 4 3
c change spelling
e
s 00001/00001/00563
d D 4.3 80/12/19 11:45:01 wnj 3 2
c s,../conf/,,
e
s 00010/00015/00554
d D 4.2 80/12/18 03:12:48 wnj 2 1
c fixed for 1 drive, and from working v on ingres (modulo error handling)
e
s 00569/00000/00000
d D 4.1 80/12/17 18:35:38 wnj 1 0
c date and time created 80/12/17 18:35:38 by wnj
e
u
U
t
T
I 1
D 26
/*	%M%	%I%	%G%	*/
E 26
I 26
D 68
/*	%M%	%I%	%E%	*/
E 68
I 68
/*
D 73
 * Copyright (c) 1982 Regents of the University of California.
E 73
I 73
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 73
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 68
E 26

D 3
#include "../conf/tm.h"
E 3
I 3
D 19
#include "tm.h"
E 19
I 19
#include "te.h"
I 35
#include "ts.h"
E 35
E 19
E 3
D 12
#if NTM > 0
E 12
I 12
D 16
#if NTM03 > 0
E 16
I 16
D 47
#if NTM > 0
E 47
I 47
#if NTE > 0
E 47
I 17
D 25
int	tmgapsdcnt;		/* DEBUG */
E 25
E 17
E 16
E 12
/*
D 16
 * TM tape driver
E 16
I 16
 * TM11/TE10 tape driver
E 16
I 12
 *
D 14
 * THIS HANDLES ONLY ONE DRIVE ON ONE CONTROLER, AS WE HAVE NO
 * WAY TO TEST MULTIPLE TRANSPORTS.
E 14
I 14
D 22
 * THIS DRIVER HAS NOT BEEN TESTED WITH MORE THAN ONE TRANSPORT.
E 22
I 22
D 24
 * Todo:
 *	Test driver with more than one slave
 *	Test reset code
 *	Do rewinds without hanging in driver
E 24
I 24
 * TODO:
D 75
 *	test driver with more than one slave
E 75
 *	test driver with more than one controller
 *	test reset code
D 29
 *	test rewinds without hanging in driver
E 29
 *	what happens if you offline tape during rewind?
 *	test using file system on tape
E 24
E 22
E 14
E 12
 */
I 60
D 74
#include "../machine/pte.h"

E 74
E 60
D 7

E 7
I 7
D 12
#define	DELAY(N)		{ register int d; d = N; while (--d > 0); }
E 12
I 12
D 24
#define	DELAY(N)		{ register int d = N; while (--d > 0); }
E 24
E 12
E 7
D 66
#include "../h/param.h"
I 27
#include "../h/systm.h"
E 27
#include "../h/buf.h"
#include "../h/dir.h"
#include "../h/conf.h"
#include "../h/user.h"
#include "../h/file.h"
#include "../h/map.h"
D 60
#include "../h/pte.h"
E 60
I 13
#include "../h/vm.h"
E 13
D 23
#include "../h/uba.h"
E 23
I 23
D 55
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 55
E 23
D 51
#include "../h/mtio.h"
E 51
#include "../h/ioctl.h"
I 51
#include "../h/mtio.h"
E 51
D 13
#include "../h/vm.h"
E 13
I 8
#include "../h/cmap.h"
I 9
D 55
#include "../h/cpu.h"
E 55
I 52
#include "../h/uio.h"
I 57
#include "../h/kernel.h"
E 66
I 66
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
#include "kernel.h"
I 67
#include "tty.h"
I 74
#include "syslog.h"
E 74
E 67
E 66
E 57
E 52
E 9
E 8

I 74
#include "../machine/pte.h"
E 74
D 9
struct device {
	u_short	tmer;
	u_short	tmcs;
	short	tmbc;
	u_short tmba;
	short	tmdb;
	short	tmrd;
};
E 9
I 9
D 55
#include "../h/tmreg.h"
E 55
I 55
#include "../vax/cpu.h"
D 66
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
#include "../vaxuba/tmreg.h"
E 66
I 66
#include "ubareg.h"
#include "ubavar.h"
#include "tmreg.h"
E 66
E 55
E 9

D 9
#define	b_repcnt  b_bcount
#define	b_command b_resid

E 9
D 11
struct	buf	tmtab;
E 11
D 14
struct	buf	ctmbuf;
struct	buf	rtmbuf;
E 14
I 14
D 16
struct	buf	ctmbuf[NTM11];
struct	buf	rtmbuf[NTM11];
E 16
I 16
D 24
struct	buf	ctmbuf[NTE];
struct	buf	rtmbuf[NTE];
E 24
I 24
/*
 * There is a ctmbuf per tape controller.
 * It is used as the token to pass to the internal routines
 * to execute tape ioctls, and also acts as a lock on the slaves
 * on the controller, since there is only one per controller.
 * In particular, when the tape is rewinding on close we release
 * the user process but any further attempts to use the tape drive
 * before the rewind completes will hang waiting for ctmbuf.
 */
struct	buf	ctmbuf[NTM];
E 24
E 16
E 14

I 24
/*
D 76
 * Raw tape operations use rtmbuf.  The driver
 * notices when rtmbuf is being used and allows the user
 * program to continue after errors and read records
 * not of the standard length (BSIZE).
 */
struct	buf	rtmbuf[NTM];

/*
E 76
 * Driver unibus interface routines and variables.
 */
E 24
I 9
D 14
int	tmcntrlr(), tmslave(), tmdgo(), tmintr();
E 14
I 14
int	tmprobe(), tmslave(), tmattach(), tmdgo(), tmintr();
E 14
D 11
struct	uba_dinfo *tminfo[NTM];
D 10
u_short	tmstd[] = { 0 };
int	(*tmivec[])() = { tmintr, 0 };
E 10
I 10
extern	u_short	tmstd[];
E 11
I 11
D 12
struct	uba_dinfo *tmdinfo[NTM];
struct	uba_minfo *tmminfo[NTM];
E 12
I 12
D 16
struct	uba_minfo *tmminfo[NTM03];
struct	uba_dinfo *tmdinfo[NTM11];
I 14
struct	buf tmutab[NTM11];
E 16
I 16
D 23
struct	uba_minfo *tmminfo[NTM];
struct	uba_dinfo *tmdinfo[NTE];
E 23
I 23
struct	uba_ctlr *tmminfo[NTM];
D 24
struct	uba_device *tmdinfo[NTE];
E 23
struct	buf tmutab[NTE];
E 16
#ifdef notyet
D 16
struct	uba_dinfo *tmip[NTM03][4];
E 16
I 16
D 23
struct	uba_dinfo *tmip[NTM][4];
E 23
I 23
struct	uba_device *tmip[NTM][4];
E 23
E 16
#endif
E 24
I 24
struct	uba_device *tedinfo[NTE];
struct	buf teutab[NTE];
short	tetotm[NTE];
E 24
E 14
E 12
u_short	tmstd[] = { 0772520, 0 };
E 11
E 10
struct	uba_driver tmdriver =
D 10
	{ tmcntrlr, tmslave, tmdgo, 0, 0, tmstd, tminfo, tmivec };
E 10
I 10
D 11
	{ tmcntrlr, tmslave, tmdgo, 4, 0, tmstd, "tm", tminfo };
E 11
I 11
D 13
	{ tmcntrlr, tmslave, tmdgo, 0, tmstd, "tm", tmdinfo, tmminfo };
E 13
I 13
D 14
	{ tmcntrlr, tmslave, tmdgo, 0, tmstd, "mt", tmdinfo, "tm", tmminfo };
E 14
I 14
D 16
  { tmprobe, tmslave, tmattach, tmdgo, tmstd, "mtm", tmdinfo, "tm", tmminfo };
E 16
I 16
D 24
 { tmprobe, tmslave, tmattach, tmdgo, tmstd, "te", tmdinfo, "tm", tmminfo, 0 };
E 24
I 24
 { tmprobe, tmslave, tmattach, tmdgo, tmstd, "te", tedinfo, "tm", tmminfo, 0 };
E 24
E 16
E 14
E 13
E 11
E 10
E 9
D 12
int	tm_ubinfo;
E 12

/* bits in minor device */
I 14
D 24
#define	TMUNIT(dev)	(minor(dev)&03)
E 24
I 24
#define	TEUNIT(dev)	(minor(dev)&03)
#define	TMUNIT(dev)	(tetotm[TEUNIT(dev)])
E 24
E 14
#define	T_NOREWIND	04
D 69
#define	T_1600BPI	08
E 69
I 69
#define	T_1600BPI	0x8
E 69

#define	INF	(daddr_t)1000000L

I 14
/*
 * Software state per tape transport.
I 24
 *
 * 1. A tape drive is a unique-open device; we refuse opens when it is already.
 * 2. We keep track of the current position on a block tape and seek
 *    before operations by forward/back spacing if necessary.
 * 3. We remember if the last operation was a write on a tape, so if a tape
 *    is open read write and the last thing done is a write we can
 *    write a standard end of tape mark (two eofs).
 * 4. We remember the status registers after the last command, using
 *    then internally and returning them to the SENSE ioctl.
 * 5. We remember the last density the tape was used at.  If it is
 *    not a BOT when we start using it and we are writing, we don't
 *    let the density be changed.
E 24
 */
E 14
D 12
/*
 * Really only handle one tape drive... if you have more than one,
D 9
 * you can make all these arrays and change the obvious things, but
E 9
I 9
 * you can put all these (and some of the above) in a structure,
 * change the obvious things, and make tmslave smarter, but
E 9
 * it is not clear what happens when some drives are transferring while
 * others rewind, so we don't pretend that this driver handles multiple
 * tape drives.
 */
char	t_openf;
daddr_t	t_blkno;
char	t_flags;
daddr_t	t_nxrec;
u_short	t_erreg;
u_short	t_dsreg;
short	t_resid;
E 12
I 12
D 24
struct	tm_softc {
E 24
I 24
struct	te_softc {
E 24
D 14
	char	sc_openf;
	char	sc_flags;
	daddr_t	sc_blkno;
	daddr_t	sc_nxrec;
	u_short	sc_erreg;
	u_short	sc_dsreg;
	short	sc_resid;
E 14
I 14
	char	sc_openf;	/* lock against multiple opens */
	char	sc_lastiow;	/* last op was a write */
	daddr_t	sc_blkno;	/* block number, for block device tape */
D 24
	daddr_t	sc_nxrec;	/* desired block position */
E 24
I 24
	daddr_t	sc_nxrec;	/* position of end of tape, if known */
E 24
	u_short	sc_erreg;	/* copy of last erreg */
I 75
	u_short	sc_ioerreg;	/* copy of last erreg for I/O command */
E 75
	u_short	sc_dsreg;	/* copy of last dsreg */
	short	sc_resid;	/* copy of last bc */
I 22
D 25
#ifdef notdef
E 25
I 25
#ifdef unneeded
E 25
E 22
I 17
	short	sc_lastcmd;	/* last command to handle direction changes */
I 22
#endif
E 22
E 17
E 14
D 13
	int	sc_ubinfo;
E 13
D 16
} tm_softc[NTM03];
E 16
I 16
D 24
} tm_softc[NTM];
E 24
I 24
	u_short	sc_dens;	/* prototype command with density info */
I 34
D 67
	daddr_t	sc_timo;	/* time until timeout expires */
E 67
	short	sc_tact;	/* timeout is active */
I 67
	daddr_t	sc_timo;	/* time until timeout expires */
I 74
	int	sc_blks;	/* number of I/O operations since open */
	int	sc_softerrs;	/* number of soft I/O errors since open */
E 74
	struct	tty *sc_ttyp;	/* record user's tty for errors */
E 67
E 34
D 48
} te_softc[NTM];
E 48
I 48
} te_softc[NTE];
E 48
I 25
#ifdef unneeded
int	tmgapsdcnt;		/* DEBUG */
#endif
E 25
E 24
E 16
E 12

I 14
/*
D 24
 * States for um->um_tab.b_active, the
 * per controller state flag.
E 24
I 24
 * States for um->um_tab.b_active, the per controller state flag.
 * This is used to sequence control in the driver.
E 24
 */
E 14
D 9
/* bits in tmcs */
#define	GO	01
#define	OFFL	0
#define	RCOM	02
#define	WCOM	04
#define	WEOF	06
#define	SFORW	010
#define	SREV	012
#define	WIRG	014
#define	REW	016
#define	IENABLE	0100
#define	CUR	0200
#define	NOP	IENABLE
#define	DCLR	010000
#define	D800	060000
#define	ERROR	0100000

/* bits in tmer */
#define	TUR	1
#define	RWS	02
#define	WRL	04
#define	SDWN	010
#define	BOT	040
#define	SELR	0100
#define	NXM	0200
#define	TMBTE	0400
#define	RLE	01000
#define	EOT	02000
#define	BGL	04000
#define	PAE	010000
#define	CRE	020000
#define	EOF	040000
#define	ILC	0100000

#define	HARD    (ILC|EOT)
#define	SOFT	(CRE|PAE|BGL|RLE|TMBTE|NXM)

E 9
#define	SSEEK	1		/* seeking */
#define	SIO	2		/* doing seq i/o */
#define	SCOM	3		/* sending control command */
I 14
#define	SREW	4		/* sending a drive rewind */
E 14

I 35
D 46
#if NTS > 0
E 46
E 35
D 14
#define	LASTIOW 1		/* last op was a write */
#define	WAITREW	2		/* someone is waiting for a rewind */
E 14
I 14
D 24
/* WE CURRENTLY HANDLE REWINDS PRIMITIVELY, BUSYING OUT THE CONTROLLER */
/* DURING THE REWIND... IF WE EVER GET TWO TRANSPORTS, WE CAN DEBUG MORE */
/* SOPHISTICATED LOGIC... THIS SIMPLE CODE AT LEAST MAY WORK. */
E 14

E 24
I 10
/*
I 35
D 46
 * Kludge to get around fact that we don't really
 * check if a ts is there... if there are both tm's and ts's
 * declared in the system, then this driver sets havetm to 1
 * if it finds a tm, and ts just pretends there isn't a ts.
 */
int	havetm = 0;
#endif
/*
E 46
E 35
 * Determine if there is a controller for
 * a tm at address reg.  Our goal is to make the
 * device interrupt.
D 11
 * THE ARGUMENT UI IS OBSOLETE
E 11
 */
E 10
I 9
D 11
tmcntrlr(ui, reg)
	struct uba_dinfo *ui;
E 11
I 11
D 14
tmcntrlr(um, reg)
	struct uba_minfo *um;
E 14
I 14
tmprobe(reg)
E 14
E 11
	caddr_t reg;
{
I 11
D 24
	register int br, cvec;
E 24
I 24
	register int br, cvec;		/* must be r11,r10; value-result */
E 24
E 11
I 10

E 10
D 14
	((struct device *)reg)->tmcs = IENABLE;
E 14
I 14
#ifdef lint
D 25
	br = 0; br = cvec; cvec = br;
E 25
I 25
	br = 0; cvec = br; br = cvec;
I 44
	tmintr(0);
E 44
E 25
#endif
D 46
	((struct device *)reg)->tmcs = TM_IE;
E 46
I 46
	((struct tmdevice *)reg)->tmcs = TM_IE;
E 46
E 14
	/*
D 14
	 * If this is a tm03/tc11, it ought to have interrupted
E 14
I 14
D 16
	 * If this is a tm03, it ought to have interrupted
E 16
I 16
	 * If this is a tm11, it ought to have interrupted
E 16
E 14
	 * by now, if it isn't (ie: it is a ts04) then we just
D 11
	 * pray that it didn't interrupt, so autoconf will ignore it
	 * - just in case out prayers fail, we will reference one
E 11
I 11
	 * hope that it didn't interrupt, so autoconf will ignore it.
	 * Just in case, we will reference one
E 11
	 * of the more distant registers, and hope for a machine
D 11
	 * check, or similar disaster
E 11
I 11
	 * check, or similar disaster if this is a ts.
I 12
	 *
	 * Note: on an 11/780, badaddr will just generate
	 * a uba error for a ts; but our caller will notice that
	 * so we won't check for it.
E 12
E 11
	 */
D 25
	if (badaddr(&((struct device *)reg)->tmrd, 2))
E 25
I 25
D 46
	if (badaddr((caddr_t)&((struct device *)reg)->tmrd, 2))
E 46
I 46
	if (badaddr((caddr_t)&((struct tmdevice *)reg)->tmrd, 2))
E 46
E 25
D 11
		return(0);
	return(1);
E 11
I 11
		return (0);
D 50
	return (1);
E 50
I 50
	return (sizeof (struct tmdevice));
E 50
E 11
}

I 14
/*
 * Due to a design flaw, we cannot ascertain if the tape
 * exists or not unless it is on line - ie: unless a tape is
 * mounted. This is too servere a restriction to bear,
 * so all units are assumed to exist.
 */
/*ARGSUSED*/
E 14
D 13
tmslave(ui, reg, slaveno)
E 13
I 13
tmslave(ui, reg)
E 13
D 23
	struct uba_dinfo *ui;
E 23
I 23
	struct uba_device *ui;
E 23
	caddr_t reg;
{
I 11

E 11
D 14
	/*
	 * Due to a design flaw, we cannot ascertain if the tape
	 * exists or not unless it is on line - ie: unless a tape is
	 * mounted. This is too servere a restriction to bear.
	 * As we can only handle one tape, we might just as well insist
	 * that it be slave #0, and just assume that it exists.
	 * Something better will have to be done if you have two
	 * tapes on one controller, or two controllers
	 */
I 10
D 11
	printf("tm: sl %d - tmi %x\n", slaveno, tminfo[0]);
E 10
	if (slaveno != 0 || tminfo[0])
E 11
I 11
D 13
	if (slaveno != 0 || tmdinfo[0])
E 13
I 13
	if (ui->ui_slave != 0 || tmdinfo[0])
E 13
E 11
		return(0);
E 14
D 11
	return(1);
E 11
I 11
	return (1);
E 11
}

I 14
/*
D 24
 * Record attachment of the unit to the controller port.
E 24
I 24
 * Record attachment of the unit to the controller.
E 24
 */
/*ARGSUSED*/
tmattach(ui)
D 23
	struct uba_dinfo *ui;
E 23
I 23
	struct uba_device *ui;
E 23
{
D 46

I 35
#if NTS > 0
	havetm = 1;
#endif
E 46
E 35
D 24
#ifdef notyet
	tmip[ui->ui_ctlr][ui->ui_slave] = ui;
#endif
E 24
I 24
	/*
D 76
	 * Tetotm is used in TMUNIT to index the ctmbuf and rtmbuf
	 * arrays given a te unit number.
E 76
I 76
	 * Tetotm is used in TMUNIT to index the ctmbuf
	 * array given a te unit number.
E 76
	 */
	tetotm[ui->ui_unit] = ui->ui_mi->um_ctlr;
E 24
}

I 34
int	tmtimer();
E 34
/*
 * Open the device.  Tapes are unique open
 * devices, so we refuse if it is already open.
 * We also check that a tape is available, and
D 24
 * don't block waiting here.
E 24
I 24
 * don't block waiting here; if you want to wait
 * for a tape you should timeout in user code.
E 24
 */
I 69

#ifdef AVIV
int tmdens[4] = { 0x6000, 0x0000, 0x2000, 0 };
D 74
int tmdiag;
E 74
#endif AVIV
I 74
int tmdiag;
E 74

E 69
E 14
E 9
tmopen(dev, flag)
	dev_t dev;
	int flag;
{
D 14
	register ds, unit;
E 14
I 14
D 24
	register int unit;
E 24
I 24
	register int teunit;
E 24
E 14
I 9
D 23
	register struct uba_dinfo *ui;
E 23
I 23
	register struct uba_device *ui;
E 23
I 12
D 14
	register struct tm_softc *sc = &tm_softc[0];
E 14
I 14
D 24
	register struct tm_softc *sc;
E 24
I 24
	register struct te_softc *sc;
D 29
	int dens;
E 29
I 29
	int olddens, dens;
I 45
	int s;
E 45
E 29
E 24
E 14
E 12
E 9

D 11
	tmtab.b_flags |= B_TAPE;
E 11
I 11
D 14
	tmminfo[0]->um_tab.b_flags |= B_TAPE;
E 11
	unit = minor(dev)&03;
D 9
	if (unit >= NTM || t_openf) {
E 9
I 9
D 10
	if (unit>=NTM || t_openf || !(ui = tminfo[minor(dev)>>3])->ui_alive) {
E 10
I 10
D 11
	if (unit>=NTM || t_openf || !(ui = tminfo[minor(dev)&03])->ui_alive) {
E 11
I 11
D 12
	if (unit>=NTM || t_openf || !(ui = tmdinfo[minor(dev)&03])->ui_alive) {
E 12
I 12
	if (unit>=NTM11 || sc->sc_openf || (ui = tmdinfo[0]) == 0 || ui->ui_alive==0) {
E 12
E 11
E 10
E 9
		u.u_error = ENXIO;		/* out of range or open */
E 14
I 14
D 24
	unit = TMUNIT(dev);
D 16
	if (unit>=NTM11 || (sc = &tm_softc[unit])->sc_openf ||
E 16
I 16
	if (unit>=NTE || (sc = &tm_softc[unit])->sc_openf ||
E 16
	    (ui = tmdinfo[unit]) == 0 || ui->ui_alive == 0) {
E 24
I 24
	teunit = TEUNIT(dev);
D 70
	if (teunit>=NTE || (sc = &te_softc[teunit])->sc_openf ||
D 56
	    (ui = tedinfo[teunit]) == 0 || ui->ui_alive == 0) {
E 24
		u.u_error = ENXIO;
E 14
		return;
	}
E 56
I 56
	    (ui = tedinfo[teunit]) == 0 || ui->ui_alive == 0)
E 70
I 70
	if (teunit>=NTE || (ui = tedinfo[teunit]) == 0 || ui->ui_alive == 0)
E 70
		return (ENXIO);
I 70
	if ((sc = &te_softc[teunit])->sc_openf)
		return (EBUSY);
I 74
	sc->sc_openf = 1;
E 74
E 70
E 56
I 29
	olddens = sc->sc_dens;
	dens = TM_IE | TM_GO | (ui->ui_slave << 8);
I 69
#ifndef AVIV
E 69
	if ((minor(dev) & T_1600BPI) == 0)
		dens |= TM_D800;
I 69
#else AVIV
	dens |= tmdens[(minor(dev)>>3)&03];
#endif AVIV
E 69
	sc->sc_dens = dens;
E 29
I 27
get:
E 27
D 13
	tcommand(dev, NOP, 1);
E 13
I 13
D 14
	tmcommand(dev, NOP, 1);
E 13
D 12
	if ((t_erreg&SELR) == 0) {
		u.u_error = EIO;		/* offline */
		return;
E 12
I 12
	if ((sc->sc_erreg&SELR) == 0) {
E 14
I 14
	tmcommand(dev, TM_SENSE, 1);
I 27
	if (sc->sc_erreg&TMER_SDWN) {
		sleep((caddr_t)&lbolt, PZERO+1);
		goto get;
	}
E 27
D 22
	if ((sc->sc_erreg&(TM_SELR|TM_TUR)) != (TM_SELR|TM_TUR)) {
		uprintf("tape not online\n");
E 22
I 22
D 24
	if ((sc->sc_erreg&(TM_SELR|TM_TUR)) != (TM_SELR|TM_TUR) ||
	    (flag&(FREAD|FWRITE)) == FWRITE && sc->sc_erreg&TM_WRL) {
E 24
I 24
D 29
	dens = TM_IE | TM_GO | (ui->ui_slave << 8);
	if ((minor(dev) & T_1600BPI) == 0)
		dens |= TM_D800;
E 29
I 29
	sc->sc_dens = olddens;
E 29
D 38
	if ((sc->sc_erreg&(TMER_SELR|TMER_TUR)) != (TMER_SELR|TMER_TUR) ||
I 28
	    (flag&FWRITE) && (sc->sc_erreg&TMER_WRL) ||
E 28
	    (sc->sc_erreg&TMER_BOT) == 0 && (flag&FWRITE) &&
D 28
		dens != sc->sc_dens ||
	    (flag&(FREAD|FWRITE)) == FWRITE && sc->sc_erreg&TMER_WRL) {
I 27
		printf("er %o dens %o sc->sc_dens %o flag %o\n", sc->sc_erreg, dens, sc->sc_dens, flag);
E 28
I 28
		dens != sc->sc_dens) {
E 28
E 27
		/*
		 * Not online or density switch in mid-tape or write locked.
		 */
E 38
I 38
	if ((sc->sc_erreg&(TMER_SELR|TMER_TUR)) != (TMER_SELR|TMER_TUR)) {
		uprintf("te%d: not online\n", teunit);
I 74
		sc->sc_openf = 0;
E 74
D 56
		u.u_error = EIO;
		return;
E 56
I 56
		return (EIO);
E 56
	}
	if ((flag&FWRITE) && (sc->sc_erreg&TMER_WRL)) {
		uprintf("te%d: no write ring\n", teunit);
I 74
		sc->sc_openf = 0;
E 74
D 56
		u.u_error = EIO;
		return;
E 56
I 56
		return (EIO);
E 56
	}
	if ((sc->sc_erreg&TMER_BOT) == 0 && (flag&FWRITE) &&
	    dens != sc->sc_dens) {
		uprintf("te%d: can't change density in mid-tape\n", teunit);
I 74
		sc->sc_openf = 0;
E 74
E 38
E 24
E 22
E 14
D 56
		u.u_error = EIO;
D 14
		goto eio;
E 14
I 14
		return;
E 56
I 56
		return (EIO);
E 56
E 14
E 12
	}
D 12
	t_openf = 1;
	if (t_erreg&RWS)
E 12
I 12
D 14
	sc->sc_openf = 1;
	if (sc->sc_erreg&RWS)
E 12
		tmwaitrws(dev);			/* wait for rewind complete */
D 12
	while (t_erreg&SDWN)
E 12
I 12
	while (sc->sc_erreg&SDWN)
E 12
D 13
		tcommand(dev, NOP, 1);		/* await settle down */
E 13
I 13
		tmcommand(dev, NOP, 1);		/* await settle down */
E 13
D 12
	if ((t_erreg&TUR)==0 ||
	    ((flag&(FREAD|FWRITE)) == FWRITE && (t_erreg&WRL))) {
E 12
I 12
	if ((sc->sc_erreg&TUR)==0 ||
	    ((flag&(FREAD|FWRITE)) == FWRITE && (sc->sc_erreg&WRL))) {
E 12
D 9
		TMADDR->tmcs = DCLR|GO;
E 9
I 9
		((struct device *)ui->ui_addr)->tmcs = DCLR|GO;
E 9
		u.u_error = EIO;		/* offline or write protect */
	}
	if (u.u_error != 0) {
D 12
		t_openf = 0;
E 12
I 12
		sc->sc_openf = 0;
		if (u.u_error == EIO)
eio:
			uprintf("tape offline or protected\n");
E 14
I 14
D 22
	if ((flag&(FREAD|FWRITE)) == FWRITE && sc->sc_erreg&TM_WRL) {
		uprintf("tape write protected\n");
		u.u_error = EIO;
E 14
E 12
		return;
	}
E 22
I 14
D 74
	sc->sc_openf = 1;
E 74
E 14
D 12
	t_blkno = (daddr_t)0;
	t_nxrec = INF;
	t_flags = 0;
	t_openf = 1;
E 12
I 12
	sc->sc_blkno = (daddr_t)0;
	sc->sc_nxrec = INF;
D 14
	sc->sc_flags = 0;
E 14
I 14
	sc->sc_lastiow = 0;
I 24
	sc->sc_dens = dens;
I 74
	sc->sc_blks = 0;
	sc->sc_softerrs = 0;
E 74
I 67
	sc->sc_ttyp = u.u_ttyp;
E 67
I 34
D 45
	(void) spl6();
E 45
I 45
D 72
	s = spl6();
E 72
I 72
	s = splclock();
E 72
E 45
	if (sc->sc_tact == 0) {
		sc->sc_timo = INF;
		sc->sc_tact = 1;
D 37
		timeout(tmtimer, dev, 5*hz);
E 37
I 37
		timeout(tmtimer, (caddr_t)dev, 5*hz);
E 37
	}
D 45
	(void) spl0();
E 45
I 45
	splx(s);
I 56
	return (0);
E 56
E 45
E 34
E 24
E 14
D 22
	sc->sc_openf = 1;
I 14
	return;
E 22
E 14
E 12
}

D 14
tmwaitrws(dev)
	register dev;
{
I 9
	register struct device *addr =
D 10
	    (struct device *)tminfo[minor(dev)>>3]->ui_addr;
E 10
I 10
D 11
	    (struct device *)tminfo[minor(dev)&03]->ui_addr;
E 11
I 11
D 12
	    (struct device *)tmdinfo[minor(dev)&03]->ui_addr;
E 12
I 12
	    (struct device *)tmdinfo[0]->ui_addr;
	register struct tm_softc *sc = &tm_softc[0];
E 12
E 11
E 10
E 9

	spl5();
	for (;;) {
D 2
		tcommand(dev, NOP, 1);
		if ((t_erreg&RWS) == 0) {
E 2
I 2
D 9
		if ((TMADDR->tmer&RWS) == 0) {
E 9
I 9
		if ((addr->tmer&RWS) == 0) {
E 9
E 2
			spl0();		/* rewind complete */
			return;
		}
D 12
		t_flags |= WAITREW;
		sleep((caddr_t)&t_flags, PRIBIO);
E 12
I 12
		sc->sc_flags |= WAITREW;
		sleep((caddr_t)&sc->sc_flags, PRIBIO);
E 12
	}
}

E 14
I 14
/*
 * Close tape device.
 *
 * If tape was open for writing or last operation was
 * a write, then write two EOF's and backspace over the last one.
 * Unless this is a non-rewinding special file, rewind the tape.
 * Make the tape available to others.
 */
E 14
tmclose(dev, flag)
	register dev_t dev;
	register flag;
{
I 12
D 14
	register struct tm_softc *sc = &tm_softc[0];
E 14
I 14
D 24
	register struct tm_softc *sc = &tm_softc[TMUNIT(dev)];
E 24
I 24
	register struct te_softc *sc = &te_softc[TEUNIT(dev)];
E 24
E 14
E 12

D 12
	if (flag == FWRITE || ((flag&FWRITE) && (t_flags&LASTIOW))) {
E 12
I 12
D 14
	if (flag == FWRITE || ((flag&FWRITE) && (sc->sc_flags&LASTIOW))) {
E 12
D 13
		tcommand(dev, WEOF, 1);
		tcommand(dev, WEOF, 1);
		tcommand(dev, SREV, 1);
E 13
I 13
		tmcommand(dev, WEOF, 1);
		tmcommand(dev, WEOF, 1);
		tmcommand(dev, SREV, 1);
E 14
I 14
	if (flag == FWRITE || (flag&FWRITE) && sc->sc_lastiow) {
		tmcommand(dev, TM_WEOF, 1);
		tmcommand(dev, TM_WEOF, 1);
		tmcommand(dev, TM_SREV, 1);
E 14
E 13
	}
	if ((minor(dev)&T_NOREWIND) == 0)
D 13
		tcommand(dev, REW, 1);
E 13
I 13
D 14
		tmcommand(dev, REW, 1);
E 14
I 14
D 24
		tmcommand(dev, TM_REW, 1);
E 24
I 24
		/*
		 * 0 count means don't hang waiting for rewind complete
		 * rather ctmbuf stays busy until the operation completes
		 * preventing further opens from completing by
		 * preventing a TM_SENSE from completing.
		 */
		tmcommand(dev, TM_REW, 0);
I 74
	if (sc->sc_blks > 100 && sc->sc_softerrs > sc->sc_blks / 100)
		log(LOG_INFO, "te%d: %d soft errors in %d blocks\n",
		    TEUNIT(dev), sc->sc_softerrs, sc->sc_blks);
E 74
E 24
E 14
E 13
D 12
	t_openf = 0;
E 12
I 12
	sc->sc_openf = 0;
I 74
	return (0);
E 74
E 12
}

I 14
/*
 * Execute a command on the tape drive
 * a specified number of times.
 */
E 14
D 13
tcommand(dev, com, count)
E 13
I 13
tmcommand(dev, com, count)
E 13
	dev_t dev;
	int com, count;
{
	register struct buf *bp;
I 45
	register int s;
E 45

D 14
	bp = &ctmbuf;
E 14
I 14
	bp = &ctmbuf[TMUNIT(dev)];
E 14
D 45
	(void) spl5();
E 45
I 45
	s = spl5();
E 45
	while (bp->b_flags&B_BUSY) {
I 24
		/*
		 * This special check is because B_BUSY never
		 * gets cleared in the non-waiting rewind case.
		 */
D 27
		if (bp->b_command == TM_REW && bp->b_repcnt == 0 &&
		    (bp->b_flags&B_DONE))
E 27
I 27
		if (bp->b_repcnt == 0 && (bp->b_flags&B_DONE))
E 27
			break;
E 24
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO);
	}
	bp->b_flags = B_BUSY|B_READ;
D 45
	(void) spl0();
E 45
I 45
	splx(s);
E 45
	bp->b_dev = dev;
	bp->b_repcnt = -count;
	bp->b_command = com;
	bp->b_blkno = 0;
	tmstrategy(bp);
I 24
	/*
	 * In case of rewind from close, don't wait.
	 * This is the only case where count can be 0.
	 */
	if (count == 0)
		return;
E 24
	iowait(bp);
	if (bp->b_flags&B_WANTED)
		wakeup((caddr_t)bp);
	bp->b_flags &= B_ERROR;
}

I 14
/*
D 24
 * Decipher a tape operation and do what is needed
 * to see that it happens.
E 24
I 24
 * Queue a tape operation.
E 24
 */
E 14
tmstrategy(bp)
	register struct buf *bp;
{
D 14
	register daddr_t *p;
I 11
	register struct buf *tmi;
E 14
I 14
D 24
	int unit = TMUNIT(bp->b_dev);
E 24
I 24
	int teunit = TEUNIT(bp->b_dev);
E 24
D 23
	register struct uba_minfo *um;
E 23
I 23
	register struct uba_ctlr *um;
E 23
	register struct buf *dp;
I 45
	int s;
E 45
D 24
	register struct tm_softc *sc = &tm_softc[unit];
E 24
I 24
D 25
	register struct te_softc *sc = &te_softc[teunit];
E 25
E 24
E 14
E 11

D 2
	tcommand(bp->b_dev, NOP, 1);
	if (t_erreg&RWS)
		tmwaitrws(bp->b_dev);
E 2
I 2
D 14
	tmwaitrws(bp->b_dev);
E 2
	if (bp != &ctmbuf) {
D 12
		p = &t_nxrec;
E 12
I 12
		p = &tm_softc[0].sc_nxrec;
E 12
		if (dbtofsb(bp->b_blkno) > *p) {
			bp->b_flags |= B_ERROR;
			bp->b_error = ENXIO;		/* past EOF */
			iodone(bp);
			return;
		} else if (dbtofsb(bp->b_blkno) == *p && bp->b_flags&B_READ) {
			bp->b_resid = bp->b_bcount;
			clrbuf(bp);			/* at EOF */
			iodone(bp);
			return;
		} else if ((bp->b_flags&B_READ) == 0)
			*p = dbtofsb(bp->b_blkno) + 1;	/* write sets EOF */
	}
E 14
I 14
	/*
	 * Put transfer at end of unit queue
	 */
D 24
	dp = &tmutab[unit];
E 24
I 24
	dp = &teutab[teunit];
E 24
E 14
	bp->av_forw = NULL;
D 45
	(void) spl5();
E 45
I 45
	s = spl5();
E 45
I 39
	um = tedinfo[teunit]->ui_mi;
E 39
D 11
	if (tmtab.b_actf == NULL)
		tmtab.b_actf = bp;
E 11
I 11
D 14
	tmi = &tmminfo[0]->um_tab;
	if (tmi->b_actf == NULL)
		tmi->b_actf = bp;
E 11
	else
D 11
		tmtab.b_actl->av_forw = bp;
	tmtab.b_actl = bp;
	if (tmtab.b_active == 0)
E 11
I 11
		tmi->b_actl->av_forw = bp;
	tmi->b_actl = bp;
	if (tmi->b_active == 0)
E 11
		tmstart();
E 14
I 14
	if (dp->b_actf == NULL) {
		dp->b_actf = bp;
		/*
		 * Transport not already active...
		 * put at end of controller queue.
		 */
		dp->b_forw = NULL;
D 24
		um = tmdinfo[unit]->ui_mi;
E 24
I 24
D 39
		um = tedinfo[teunit]->ui_mi;
E 39
E 24
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
	} else
		dp->b_actl->av_forw = bp;
	dp->b_actl = bp;
	/*
	 * If the controller is not busy, get
	 * it going.
	 */
	if (um->um_tab.b_active == 0)
		tmstart(um);
E 14
D 45
	(void) spl0();
E 45
I 45
	splx(s);
E 45
}

D 14
tmstart()
E 14
I 14
/*
 * Start activity on a tm controller.
 */
tmstart(um)
D 23
	register struct uba_minfo *um;
E 23
I 23
	register struct uba_ctlr *um;
E 23
E 14
{
D 14
	register struct buf *bp;
I 12
	register struct uba_minfo *um = tmminfo[0];
E 14
I 14
	register struct buf *bp, *dp;
D 46
	register struct device *addr = (struct device *)um->um_addr;
E 46
I 46
	register struct tmdevice *addr = (struct tmdevice *)um->um_addr;
E 46
D 24
	register struct tm_softc *sc;
E 24
I 24
	register struct te_softc *sc;
E 24
E 14
E 12
I 9
D 23
	register struct uba_dinfo *ui;
E 23
I 23
	register struct uba_device *ui;
E 23
D 14
	register struct device *addr;
E 9
D 12
	register cmd;
	register daddr_t blkno;
I 5
	int s;
E 12
I 12
	register struct tm_softc *sc = &tm_softc[0];
	int cmd, s;
E 14
I 14
D 24
	int unit, cmd;
E 24
I 24
	int teunit, cmd;
E 24
E 14
	daddr_t blkno;
E 12
E 5

I 14
	/*
	 * Look for an idle transport on the controller.
	 */
E 14
loop:
D 11
	if ((bp = tmtab.b_actf) == 0)
E 11
I 11
D 12
	if ((bp = tmminfo[0]->um_tab.b_actf) == 0)
E 12
I 12
D 14
	if ((bp = um->um_tab.b_actf) == 0)
E 14
I 14
	if ((dp = um->um_tab.b_actf) == NULL)
E 14
E 12
E 11
		return;
D 9
	t_dsreg = TMADDR->tmcs;
	t_erreg = TMADDR->tmer;
	t_resid = TMADDR->tmbc;
E 9
I 9
D 10
	ui = tminfo[minor(bp->b_dev)>>3];
E 10
I 10
D 11
	ui = tminfo[minor(bp->b_dev)&03];
E 11
I 11
D 12
	ui = tmdinfo[minor(bp->b_dev)&03];
E 12
I 12
D 14
	ui = tmdinfo[0];
E 12
E 11
E 10
	addr = (struct device *)ui->ui_addr;
E 14
I 14
	if ((bp = dp->b_actf) == NULL) {
		um->um_tab.b_actf = dp->b_forw;
		goto loop;
	}
D 24
	unit = TMUNIT(bp->b_dev);
	ui = tmdinfo[unit];
E 24
I 24
	teunit = TEUNIT(bp->b_dev);
	ui = tedinfo[teunit];
E 24
	/*
	 * Record pre-transfer status (e.g. for TM_SENSE)
	 */
D 24
	sc = &tm_softc[unit];
E 24
I 24
	sc = &te_softc[teunit];
E 24
D 46
	addr = (struct device *)um->um_addr;
E 46
I 46
	addr = (struct tmdevice *)um->um_addr;
E 46
	addr->tmcs = (ui->ui_slave << 8);
E 14
D 12
	t_dsreg = addr->tmcs;
	t_erreg = addr->tmer;
	t_resid = addr->tmbc;
E 9
	t_flags &= ~LASTIOW;
D 9
	if (t_openf < 0 || (TMADDR->tmcs&CUR) == 0) {
E 9
I 9
	if (t_openf < 0 || (addr->tmcs&CUR) == 0) {
E 9
		/* t_openf = -1; ??? */
E 12
I 12
	sc->sc_dsreg = addr->tmcs;
	sc->sc_erreg = addr->tmer;
	sc->sc_resid = addr->tmbc;
D 14
	sc->sc_flags &= ~LASTIOW;
	if (sc->sc_openf < 0 || (addr->tmcs&CUR) == 0) {
		/* sc->sc_openf = -1; ??? */
E 12
		bp->b_flags |= B_ERROR;		/* hard error'ed or !SELR */
E 14
I 14
	/*
	 * Default is that last command was NOT a write command;
	 * if we do a write command we will notice this in tmintr().
	 */
D 33
	sc->sc_lastiow = 1;
E 33
I 33
	sc->sc_lastiow = 0;
E 33
	if (sc->sc_openf < 0 || (addr->tmcs&TM_CUR) == 0) {
		/*
D 24
		 * Have had a hard error on this (non-raw) tape,
		 * or the tape unit is now unavailable (e.g. taken off
		 * line).
E 24
I 24
		 * Have had a hard error on a non-raw tape
		 * or the tape unit is now unavailable
		 * (e.g. taken off line).
E 24
		 */
		bp->b_flags |= B_ERROR;
E 14
		goto next;
	}
D 14
	cmd = IENABLE | GO;
	if ((minor(bp->b_dev) & T_1600BPI) == 0)
		cmd |= D800;
	if (bp == &ctmbuf) {
		if (bp->b_command == NOP)
			goto next;		/* just get status */
		else {
			cmd |= bp->b_command;
D 11
			tmtab.b_active = SCOM;
E 11
I 11
D 12
			tmminfo[0]->um_tab.b_active = SCOM;
E 12
I 12
			um->um_tab.b_active = SCOM;
E 12
E 11
			if (bp->b_command == SFORW || bp->b_command == SREV)
D 9
				TMADDR->tmbc = bp->b_repcnt;
			TMADDR->tmcs = cmd;
E 9
I 9
				addr->tmbc = bp->b_repcnt;
			addr->tmcs = cmd;
E 9
			return;
E 14
I 14
D 24
	/*
	 * If operation is not a control operation,
	 * check for boundary conditions.
	 */
	if (bp != &ctmbuf[unit]) {
		if (dbtofsb(bp->b_blkno) > sc->sc_nxrec) {
			bp->b_flags |= B_ERROR;
			bp->b_error = ENXIO;		/* past EOF */
			goto next;
E 14
		}
I 14
		if (dbtofsb(bp->b_blkno) == sc->sc_nxrec &&
		    bp->b_flags&B_READ) {
			bp->b_resid = bp->b_bcount;
			clrbuf(bp);			/* at EOF */
			goto next;
		}
		if ((bp->b_flags&B_READ) == 0)
			/* write sets EOF */
			sc->sc_nxrec = dbtofsb(bp->b_blkno) + 1;
E 14
	}
I 14
	/*
	 * Set up the command, and then if this is a mt ioctl,
	 * do the operation using, for TM_SFORW and TM_SREV, the specified
	 * operation count.
	 */
	cmd = TM_IE | TM_GO | (ui->ui_slave << 8);
	if ((minor(bp->b_dev) & T_1600BPI) == 0)
		cmd |= TM_D800;
	if (bp == &ctmbuf[unit]) {
E 24
I 24
	if (bp == &ctmbuf[TMUNIT(bp->b_dev)]) {
		/*
		 * Execute control operation with the specified count.
		 */
E 24
		if (bp->b_command == TM_SENSE)
			goto next;
D 17
		cmd |= bp->b_command;
E 17
D 34
		um->um_tab.b_active =
		    bp->b_command == TM_REW ? SREW : SCOM;
E 34
I 34
		/*
		 * Set next state; give 5 minutes to complete
		 * rewind, or 10 seconds per iteration (minimum 60
D 37
		 * seconds and max 5 minute) to complete other ops.
E 37
I 37
		 * seconds and max 5 minutes) to complete other ops.
E 37
		 */
		if (bp->b_command == TM_REW) {
			um->um_tab.b_active = SREW;
			sc->sc_timo = 5 * 60;
		} else {
			um->um_tab.b_active = SCOM;
D 37
			sc->sc_timo = min(max(10 * bp->b_repcnt, 60), 5 * 60);
E 37
I 37
D 40
			sc->sc_timo = imin(imax(10 * bp->b_repcnt, 60), 5*60);
E 40
I 40
D 41
			sc->sc_timo = imin(imax(10*(int)bp->b_repcnt,60),5*60);
E 41
I 41
			sc->sc_timo =
			    imin(imax(10*(int)-bp->b_repcnt,60),5*60);
E 41
E 40
E 37
		}
E 34
		if (bp->b_command == TM_SFORW || bp->b_command == TM_SREV)
			addr->tmbc = bp->b_repcnt;
D 17
		addr->tmcs = cmd;
		return;
E 17
I 17
		goto dobpcmd;
E 17
	}
	/*
I 24
D 76
	 * The following checks handle boundary cases for operation
	 * on non-raw tapes.  On raw tapes the initialization of
	 * sc->sc_nxrec by tmphys causes them to be skipped normally
	 * (except in the case of retries).
E 76
I 76
	 * For raw I/O, save the current block
	 * number in case we have to retry.
E 76
	 */
D 49
	if (dbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 49
I 49
D 76
	if (bdbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 49
		/*
		 * Can't read past known end-of-file.
		 */
		bp->b_flags |= B_ERROR;
		bp->b_error = ENXIO;
		goto next;
E 76
I 76
	if (bp->b_flags & B_RAW) {
		if (um->um_tab.b_errcnt == 0) {
			sc->sc_blkno = bdbtofsb(bp->b_blkno);
			sc->sc_nxrec = sc->sc_blkno + 1;
		}
E 76
	}
D 49
	if (dbtofsb(bp->b_blkno) == sc->sc_nxrec &&
E 49
I 49
D 76
	if (bdbtofsb(bp->b_blkno) == sc->sc_nxrec &&
E 49
	    bp->b_flags&B_READ) {
E 76
I 76
	else {
E 76
		/*
D 76
		 * Reading at end of file returns 0 bytes.
E 76
I 76
		 * Handle boundary cases for operation
		 * on non-raw tapes.
E 76
		 */
D 76
		bp->b_resid = bp->b_bcount;
		clrbuf(bp);
		goto next;
E 76
I 76
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
E 76
	}
D 76
	if ((bp->b_flags&B_READ) == 0)
		/*
		 * Writing sets EOF
		 */
D 49
		sc->sc_nxrec = dbtofsb(bp->b_blkno) + 1;
E 49
I 49
		sc->sc_nxrec = bdbtofsb(bp->b_blkno) + 1;
E 76
E 49
	/*
E 24
	 * If the data transfer command is in the correct place,
	 * set up all the registers except the csr, and give
	 * control over to the UNIBUS adapter routines, to
	 * wait for resources to start the i/o.
	 */
E 14
D 12
	if ((blkno = t_blkno) == dbtofsb(bp->b_blkno)) {
E 12
I 12
D 49
	if ((blkno = sc->sc_blkno) == dbtofsb(bp->b_blkno)) {
E 49
I 49
	if ((blkno = sc->sc_blkno) == bdbtofsb(bp->b_blkno)) {
E 49
E 12
D 9
		TMADDR->tmbc = -bp->b_bcount;
E 9
I 9
		addr->tmbc = -bp->b_bcount;
E 9
I 5
D 13
		s = spl6();
E 5
D 12
		if (tm_ubinfo == 0)
D 9
			tm_ubinfo = ubasetup(bp,1);
E 9
I 9
			tm_ubinfo = ubasetup(ui->ui_ubanum, bp, 1);
E 12
I 12
		if (sc->sc_ubinfo == 0)
			sc->sc_ubinfo = ubasetup(ui->ui_ubanum, bp, 1);
E 12
E 9
I 5
		splx(s);
E 13
E 5
		if ((bp->b_flags&B_READ) == 0) {
D 11
			if (tmtab.b_errcnt)
E 11
I 11
D 12
			if (tmminfo[0]->um_tab.b_errcnt)
E 12
I 12
D 74
			if (um->um_tab.b_errcnt)
E 74
I 74
			if (um->um_tab.b_errcnt &&
D 75
			    (sc->sc_erreg & (TMER_HARD|TMER_SOFT)) != TMER_BGL)
E 75
I 75
			    (sc->sc_ioerreg&(TMER_HARD|TMER_SOFT)) != TMER_BGL)
E 75
E 74
E 12
E 11
D 14
				cmd |= WIRG;
E 14
I 14
D 24
				cmd |= TM_WIRG;
E 24
I 24
				cmd = TM_WIRG;
E 24
E 14
			else
D 14
				cmd |= WCOM;
E 14
I 14
D 24
				cmd |= TM_WCOM;
E 24
I 24
				cmd = TM_WCOM;
E 24
E 14
		} else
D 14
			cmd |= RCOM;
E 14
I 14
D 24
			cmd |= TM_RCOM;
E 24
I 24
			cmd = TM_RCOM;
E 24
E 14
D 12
		cmd |= (tm_ubinfo >> 12) & 0x30;
D 11
		tmtab.b_active = SIO;
E 11
I 11
		tmminfo[0]->um_tab.b_active = SIO;
E 11
D 9
		TMADDR->tmba = tm_ubinfo;
		TMADDR->tmcs = cmd; 
E 9
I 9
		addr->tmba = tm_ubinfo;
E 12
I 12
D 13
		cmd |= (sc->sc_ubinfo >> 12) & 0x30;
E 13
		um->um_tab.b_active = SIO;
D 13
		addr->tmba = sc->sc_ubinfo;
E 12
		addr->tmcs = cmd; 
E 13
I 13
D 14
		if (um->um_ubinfo)
			panic("tmstart");
E 14
D 24
		um->um_cmd = cmd;
E 24
I 24
		um->um_cmd = sc->sc_dens|cmd;
E 24
I 17
D 22
/*
E 22
I 22
#ifdef notdef
E 22
		if (tmreverseop(sc->sc_lastcmd))
D 24
			while (addr->tmer & TM_SDWN)
E 24
I 24
			while (addr->tmer & TMER_SDWN)
E 24
D 69
				tmgapsdcnt++;
E 69
I 69
				DELAY(10),tmgapsdcnt++;
E 69
D 22
*/
E 22
		sc->sc_lastcmd = TM_RCOM;		/* will serve */
I 22
#endif
I 34
		sc->sc_timo = 60;	/* premature, but should serve */
E 34
E 22
E 17
D 25
		ubago(ui);
E 25
I 25
		(void) ubago(ui);
E 25
D 14
		splx(s);
E 14
E 13
E 9
		return;
	}
I 14
	/*
D 24
	 * Block tape positioned incorrectly;
	 * seek forwards or backwards to the correct spot.
E 24
I 24
	 * Tape positioned incorrectly;
	 * set to seek forwards or backwards to the correct spot.
	 * This happens for raw tapes only on error retries.
E 24
	 */
E 14
D 11
	tmtab.b_active = SSEEK;
E 11
I 11
D 12
	tmminfo[0]->um_tab.b_active = SSEEK;
E 12
I 12
	um->um_tab.b_active = SSEEK;
E 12
E 11
D 49
	if (blkno < dbtofsb(bp->b_blkno)) {
E 49
I 49
	if (blkno < bdbtofsb(bp->b_blkno)) {
E 49
D 14
		cmd |= SFORW;
E 14
I 14
D 17
		cmd |= TM_SFORW;
E 17
I 17
		bp->b_command = TM_SFORW;
E 17
E 14
D 9
		TMADDR->tmbc = blkno - dbtofsb(bp->b_blkno);
E 9
I 9
D 49
		addr->tmbc = blkno - dbtofsb(bp->b_blkno);
E 49
I 49
		addr->tmbc = blkno - bdbtofsb(bp->b_blkno);
E 49
E 9
	} else {
D 14
		cmd |= SREV;
E 14
I 14
D 17
		cmd |= TM_SREV;
E 17
I 17
		bp->b_command = TM_SREV;
E 17
E 14
D 9
		TMADDR->tmbc = dbtofsb(bp->b_blkno) - blkno;
E 9
I 9
D 49
		addr->tmbc = dbtofsb(bp->b_blkno) - blkno;
E 49
I 49
		addr->tmbc = bdbtofsb(bp->b_blkno) - blkno;
E 49
E 9
	}
I 34
D 37
	sc->sc_timo = min(max(10 * -addr->tmbc, 60), 5 * 60);
E 37
I 37
	sc->sc_timo = imin(imax(10 * -addr->tmbc, 60), 5 * 60);
E 37
E 34
D 9
	TMADDR->tmcs = cmd;
E 9
I 9
D 17
	addr->tmcs = cmd;
E 17
I 17
dobpcmd:
D 22
/*
E 22
I 22
#ifdef notdef
I 24
	/*
	 * It is strictly necessary to wait for the tape
	 * to stop before changing directions, but the TC11
	 * handles this for us.
	 */
E 24
E 22
	if (tmreverseop(sc->sc_lastcmd) != tmreverseop(bp->b_command))
		while (addr->tmer & TM_SDWN)
D 69
			tmgapsdcnt++;
E 69
I 69
			DELAY(10),tmgapsdcnt++;
E 69
D 22
*/
E 22
	sc->sc_lastcmd = bp->b_command;
I 22
#endif
E 22
D 24
	addr->tmcs = (cmd | bp->b_command);
E 24
I 24
	/*
	 * Do the command in bp.
	 */
	addr->tmcs = (sc->sc_dens | bp->b_command);
E 24
E 17
E 9
	return;

next:
D 5
	if (tm_ubinfo != 0) {
		ubafree(tm_ubinfo);
		tm_ubinfo = 0;
	}
E 5
I 5
D 9
	ubarelse(&tm_ubinfo);
E 9
I 9
D 12
	ubarelse(ui->ui_ubanum, &tm_ubinfo);
E 9
E 5
D 11
	tmtab.b_actf = bp->av_forw;
E 11
I 11
	tmminfo[0]->um_tab.b_actf = bp->av_forw;
E 12
I 12
D 13
	ubarelse(ui->ui_ubanum, &sc->sc_ubinfo);
E 13
I 13
D 14
	ubarelse(um->um_ubanum, &um->um_ubinfo);
E 13
	um->um_tab.b_actf = bp->av_forw;
E 14
I 14
	/*
	 * Done with this operation due to error or
	 * the fact that it doesn't do anything.
	 * Release UBA resources (if any), dequeue
	 * the transfer and continue processing this slave.
	 */
	if (um->um_ubinfo)
D 15
		ubarelse(um->um_ubanum, &um->um_ubinfo);
E 15
I 15
		ubadone(um);
E 15
	um->um_tab.b_errcnt = 0;
	dp->b_actf = bp->av_forw;
E 14
E 12
E 11
	iodone(bp);
	goto loop;
}

I 14
/*
 * The UNIBUS resources we needed have been
 * allocated to us; start the device.
 */
E 14
D 9
tmintr()
E 9
I 9
D 13
tmdgo()
E 13
I 13
tmdgo(um)
D 23
	register struct uba_minfo *um;
E 23
I 23
	register struct uba_ctlr *um;
E 23
E 13
E 9
{
I 13
D 46
	register struct device *addr = (struct device *)um->um_addr;
E 46
I 46
	register struct tmdevice *addr = (struct tmdevice *)um->um_addr;
E 46
E 13
I 12

I 13
D 14
	printf("tmdgo %x %x\n", um->um_ubinfo, um->um_cmd);
E 14
	addr->tmba = um->um_ubinfo;
	addr->tmcs = um->um_cmd | ((um->um_ubinfo >> 12) & 0x30);
E 13
E 12
I 9
}

I 14
/*
 * Tm interrupt routine.
 */
E 14
I 12
/*ARGSUSED*/
E 12
D 14
tmintr(d)
I 12
	int d;
E 14
I 14
D 16
tmintr(tm03)
	int tm03;
E 16
I 16
tmintr(tm11)
	int tm11;
E 16
E 14
E 12
{
I 14
	struct buf *dp;
E 14
E 9
	register struct buf *bp;
I 9
D 11
	register struct device *addr = (struct device *)tminfo[d]->ui_addr;
E 11
I 11
D 12
	register struct device *addr = (struct device *)tmdinfo[d]->ui_addr;
E 12
I 12
D 14
	register struct uba_minfo *um = tmminfo[0];
	register struct device *addr = (struct device *)tmdinfo[0]->ui_addr;
	register struct tm_softc *sc = &tm_softc[0];
E 14
I 14
D 16
	register struct uba_minfo *um = tmminfo[tm03];
	register struct device *addr = (struct device *)tmdinfo[tm03]->ui_addr;
E 16
I 16
D 23
	register struct uba_minfo *um = tmminfo[tm11];
E 23
I 23
	register struct uba_ctlr *um = tmminfo[tm11];
E 23
D 24
	register struct device *addr = (struct device *)tmdinfo[tm11]->ui_addr;
E 16
	register struct tm_softc *sc;
	int unit;
E 24
I 24
D 46
	register struct device *addr;
E 46
I 46
	register struct tmdevice *addr;
E 46
	register struct te_softc *sc;
	int teunit;
E 24
E 14
E 12
E 11
E 9
	register state;

I 24
	if ((dp = um->um_tab.b_actf) == NULL)
		return;
	bp = dp->b_actf;
	teunit = TEUNIT(bp->b_dev);
D 46
	addr = (struct device *)tedinfo[teunit]->ui_addr;
E 46
I 46
	addr = (struct tmdevice *)tedinfo[teunit]->ui_addr;
E 46
I 36
	sc = &te_softc[teunit];
E 36
E 24
I 13
D 14
	printf("tmintr %x %x\n", um->um_tab.b_actf, um->um_tab.b_active);
E 13
D 9
	if (t_flags&WAITREW && (TMADDR->tmer&RWS) == 0) {
E 9
I 9
D 12
	if (t_flags&WAITREW && (addr->tmer&RWS) == 0) {
E 9
		t_flags &= ~WAITREW;
		wakeup((caddr_t)&t_flags);
E 12
I 12
	if (sc->sc_flags&WAITREW && (addr->tmer&RWS) == 0) {
		sc->sc_flags &= ~WAITREW;
		wakeup((caddr_t)&sc->sc_flags);
E 14
I 14
	/*
	 * If last command was a rewind, and tape is still
	 * rewinding, wait for the rewind complete interrupt.
	 */
	if (um->um_tab.b_active == SREW) {
		um->um_tab.b_active = SCOM;
D 24
		if (addr->tmer&TM_RWS)
E 24
I 24
D 36
		if (addr->tmer&TMER_RWS)
E 36
I 36
		if (addr->tmer&TMER_RWS) {
			sc->sc_timo = 5*60;		/* 5 minutes */
E 36
E 24
			return;
I 36
		}
E 36
E 14
E 12
	}
D 11
	if ((bp = tmtab.b_actf) == NULL)
E 11
I 11
D 12
	if ((bp = tmminfo[0]->um_tab.b_actf) == NULL)
E 12
I 12
D 14
	if ((bp = um->um_tab.b_actf) == NULL)
E 14
I 14
	/*
	 * An operation completed... record status
	 */
D 24
	if ((dp = um->um_tab.b_actf) == NULL)
E 14
E 12
E 11
		return;
I 14
	bp = dp->b_actf;
	unit = TMUNIT(bp->b_dev);
	sc = &tm_softc[unit];
E 24
I 24
D 36
	sc = &te_softc[teunit];
E 36
I 34
	sc->sc_timo = INF;
I 75
	if (um->um_tab.b_active = SIO)
		sc->sc_ioerreg = addr->tmer;
E 75
E 34
E 24
E 14
D 9
	t_dsreg = TMADDR->tmcs;
D 2
	TMADDR->tmcs = IENABLE;
E 2
	t_erreg = TMADDR->tmer;
	t_resid = TMADDR->tmbc;
E 9
I 9
D 12
	t_dsreg = addr->tmcs;
	t_erreg = addr->tmer;
	t_resid = addr->tmbc;
E 12
I 12
	sc->sc_dsreg = addr->tmcs;
	sc->sc_erreg = addr->tmer;
	sc->sc_resid = addr->tmbc;
E 12
E 9
	if ((bp->b_flags & B_READ) == 0)
D 12
		t_flags |= LASTIOW;
D 11
	state = tmtab.b_active;
	tmtab.b_active = 0;
E 11
I 11
	state = tmminfo[0]->um_tab.b_active;
	tmminfo[0]->um_tab.b_active = 0;
E 12
I 12
D 14
		sc->sc_flags |= LASTIOW;
E 14
I 14
		sc->sc_lastiow = 1;
E 14
	state = um->um_tab.b_active;
	um->um_tab.b_active = 0;
E 12
E 11
D 9
	if (TMADDR->tmcs&ERROR) {
		while(TMADDR->tmer & SDWN)
E 9
I 9
D 14
	if (addr->tmcs&ERROR) {
		while(addr->tmer & SDWN)
E 14
I 14
	/*
	 * Check for errors.
	 */
	if (addr->tmcs&TM_ERR) {
D 24
		while (addr->tmer & TM_SDWN)
E 24
I 24
		while (addr->tmer & TMER_SDWN)
E 24
E 14
E 9
D 69
			;			/* await settle down */
E 69
I 69
			DELAY(10);			/* await settle down */
E 69
D 9
		if (TMADDR->tmer&EOF) {
E 9
I 9
D 14
		if (addr->tmer&EOF) {
E 9
			tmseteof(bp);	/* set blkno and nxrec */
			state = SCOM;
E 14
I 14
		/*
D 24
		 * If we hit the end of the tape update our position.
E 24
I 24
		 * If we hit the end of the tape file, update our position.
E 24
		 */
D 24
		if (addr->tmer&TM_EOF) {
E 24
I 24
		if (addr->tmer&TMER_EOF) {
E 24
			tmseteof(bp);		/* set blkno and nxrec */
			state = SCOM;		/* force completion */
			/*
			 * Stuff bc so it will be unstuffed correctly
			 * later to get resid.
			 */
E 14
D 9
			TMADDR->tmbc = -bp->b_bcount;
E 9
I 9
			addr->tmbc = -bp->b_bcount;
E 9
D 14
			goto errout;
E 14
I 14
			goto opdone;
E 14
		}
D 9
		if ((bp->b_flags&B_READ) && (TMADDR->tmer&(HARD|SOFT)) == RLE)
E 9
I 9
D 14
		if ((bp->b_flags&B_READ) && (addr->tmer&(HARD|SOFT)) == RLE)
E 9
			goto out;
D 9
		if ((TMADDR->tmer&HARD)==0 && state==SIO) {
E 9
I 9
		if ((addr->tmer&HARD)==0 && state==SIO) {
E 14
I 14
		/*
D 24
		 * If we were reading and the only error was that the
		 * record was to long, then we don't consider this an error.
E 24
I 24
		 * If we were reading raw tape and the only error was that the
		 * record was too long, then we don't consider this an error.
E 24
		 */
D 24
		if ((bp->b_flags&B_READ) &&
		    (addr->tmer&(TM_HARD|TM_SOFT)) == TM_RLE)
E 24
I 24
D 76
		if (bp == &rtmbuf[TMUNIT(bp->b_dev)] && (bp->b_flags&B_READ) &&
E 76
I 76
		if ((bp->b_flags & (B_READ|B_RAW)) == (B_READ|B_RAW) &&
E 76
		    (addr->tmer&(TMER_HARD|TMER_SOFT)) == TMER_RLE)
E 24
			goto ignoreerr;
		/*
		 * If error is not hard, and this was an i/o operation
		 * retry up to 8 times.
		 */
D 24
		if ((addr->tmer&TM_HARD)==0 && state==SIO) {
E 24
I 24
		if ((addr->tmer&TMER_HARD)==0 && state==SIO) {
E 24
E 14
E 9
D 2
			if (++tmtab.b_errcnt < 3) {
E 2
I 2
D 11
			if (++tmtab.b_errcnt < 7) {
E 11
I 11
D 12
			if (++tmminfo[0]->um_tab.b_errcnt < 7) {
E 12
I 12
			if (++um->um_tab.b_errcnt < 7) {
I 74
				if (tmdiag)
					log(LOG_DEBUG,
					    "te%d: soft error bn%d er=%b\n",
					    minor(bp->b_dev)&03,
					    bp->b_blkno, sc->sc_erreg,
					    TMER_BITS);
E 74
E 12
E 11
E 2
D 9
				if((TMADDR->tmer&SOFT) == NXM)
E 9
I 9
D 14
				if((addr->tmer&SOFT) == NXM)
E 14
I 14
D 22
/* SHOULD CHECK THAT RECOVERY WORKS IN THIS CASE */
/* AND THEN ONLY PRINT IF errcnt==7 */
				if((addr->tmer&TM_SOFT) == TM_NXM)
E 14
E 9
					printf("TM UBA late error\n");
E 22
D 10
				else
D 2
					t_blkno++;
E 2
I 2
D 9
					t_blkno += 2;		/* ???????? */
E 2
D 5
				if (tm_ubinfo) {
					ubafree(tm_ubinfo);
					tm_ubinfo = 0;
				}
E 5
I 5
				ubarelse(&tm_ubinfo);
E 9
I 9
					t_blkno++;
E 10
I 10
D 12
				t_blkno++;
E 10
D 11
				ubarelse(tminfo[d]->ui_ubanum, &tm_ubinfo);
E 11
I 11
				ubarelse(tmdinfo[d]->ui_ubanum, &tm_ubinfo);
E 12
I 12
				sc->sc_blkno++;
D 13
				ubarelse(um->um_ubanum, &sc->sc_ubinfo);
E 13
I 13
D 15
				ubarelse(um->um_ubanum, &um->um_ubinfo);
E 15
I 15
				ubadone(um);
E 15
E 13
E 12
E 11
E 9
E 5
D 14
				tmstart();
				return;
E 14
I 14
				goto opcont;
E 14
			}
D 12
		} else if (t_openf>0 && bp != &rtmbuf)
			t_openf = -1;
D 2
		deverror(bp, t_erreg, 0);
E 2
I 2
		deverror(bp, t_erreg, t_dsreg);
E 12
I 12
D 14
		} else if (sc->sc_openf>0 && bp != &rtmbuf)
			sc->sc_openf = -1;
E 14
I 14
		} else
			/*
			 * Hard or non-i/o errors on non-raw tape
			 * cause it to close.
			 */
D 24
			if (sc->sc_openf>0 && bp != &rtmbuf[unit])
E 24
I 24
D 76
			if (sc->sc_openf>0 && bp != &rtmbuf[TMUNIT(bp->b_dev)])
E 76
I 76
			if ((bp->b_flags&B_RAW) == 0 && sc->sc_openf > 0)
E 76
E 24
				sc->sc_openf = -1;
		/*
		 * Couldn't recover error
		 */
E 14
D 18
		deverror(bp, sc->sc_erreg, sc->sc_dsreg);
E 18
I 18
D 22
		harderr(bp);
D 20
		printf("tm%d er %b\n", dkunit(bp),
E 20
I 20
		printf("tm%d er=%b\n", dkunit(bp),
E 20
		    sc->sc_erreg, TMEREG_BITS);
E 22
I 22
D 67
		printf("te%d: hard error bn%d er=%b\n", minor(bp->b_dev)&03,
E 67
I 67
		tprintf(sc->sc_ttyp,
		    "te%d: hard error bn%d er=%b\n", minor(bp->b_dev)&03,
E 67
D 24
		    bp->b_blkno, sc->sc_erreg, TMEREG_BITS);
E 24
I 24
		    bp->b_blkno, sc->sc_erreg, TMER_BITS);
I 69
#ifdef	AVIV
		if (tmdiag) {
			addr->tmmr = DAB;
			printf("reject code 0%o", addr->tmmr & DAB_MASK);
			addr->tmmr = DTS;
			if (addr->tmmr & DTS_MASK)
			    printf(", dead track 0%o", addr->tmmr & DTS_MASK);
			addr->tmmr = RWERR;
			printf(", read/write errors %b\n",
			    addr->tmmr & RWERR_MASK,
			    RWERR_BITS);
			addr->tmmr = DRSENSE;
			printf("drive sense %b, ", addr->tmmr & DRSENSE_MASK,
			    DRSENSE_BITS);
			printf("fsr %b\n", addr->tmfsr, FSR_BITS);
		}
#endif AVIV
E 69
E 24
E 22
E 18
E 12
E 2
		bp->b_flags |= B_ERROR;
D 14
		state = SIO;
E 14
I 14
		goto opdone;
E 14
	}
D 14
out:
E 14
I 14
	/*
	 * Advance tape control FSM.
	 */
ignoreerr:
E 14
	switch (state) {

	case SIO:
I 14
		/*
		 * Read/write increments tape block number
		 */
E 14
D 12
		t_blkno++;
E 12
I 12
		sc->sc_blkno++;
I 74
		sc->sc_blks++;
		if (um->um_tab.b_errcnt)
			sc->sc_softerrs++;
E 74
E 12
D 14
		/* fall into ... */
E 14
I 14
		goto opdone;
E 14

	case SCOM:
D 14
		if (bp == &ctmbuf) {
			switch (bp->b_command) {
			case SFORW:
D 12
				t_blkno -= bp->b_repcnt;
E 12
I 12
				sc->sc_blkno -= bp->b_repcnt;
E 12
				break;
E 14
I 14
		/*
D 24
		 * Unless special operation, op completed.
E 24
I 24
		 * For forward/backward space record update current position.
E 24
		 */
D 24
		if (bp != &ctmbuf[unit])
			goto opdone;
		/*
		 * Operation on block device...
		 * iterate operations which don't repeat
		 * for themselves in the hardware; for forward/
		 * backward space record update the current position.
		 */
E 24
I 24
		if (bp == &ctmbuf[TMUNIT(bp->b_dev)])
E 24
D 71
		switch (bp->b_command) {
E 71
I 71
		switch ((int)bp->b_command) {
E 71
E 14

D 14
			case SREV:
D 12
				t_blkno += bp->b_repcnt;
E 12
I 12
				sc->sc_blkno += bp->b_repcnt;
E 12
				break;
E 14
I 14
		case TM_SFORW:
			sc->sc_blkno -= bp->b_repcnt;
D 24
			goto opdone;
E 24
I 24
			break;
E 24
E 14

D 14
			default:
				if (++bp->b_repcnt < 0) {
					tmstart();	/* continue */
					return;
				}
			}
E 14
I 14
		case TM_SREV:
			sc->sc_blkno += bp->b_repcnt;
D 24
			goto opdone;

		default:
			if (++bp->b_repcnt < 0)
				goto opcont;
			goto opdone;
E 24
I 24
			break;
E 24
E 14
		}
I 24
		goto opdone;
E 24
D 14
errout:
D 11
		tmtab.b_errcnt = 0;
		tmtab.b_actf = bp->av_forw;
E 11
I 11
D 12
		tmminfo[0]->um_tab.b_errcnt = 0;
		tmminfo[0]->um_tab.b_actf = bp->av_forw;
E 12
I 12
		um->um_tab.b_errcnt = 0;
		um->um_tab.b_actf = bp->av_forw;
E 12
E 11
D 9
		bp->b_resid = -TMADDR->tmbc;
D 5
		if (tm_ubinfo != 0) {
			ubafree(tm_ubinfo);
			tm_ubinfo = 0;
		}
E 5
I 5
		ubarelse(&tm_ubinfo);
E 9
I 9
		bp->b_resid = -addr->tmbc;
D 11
		ubarelse(tminfo[d]->ui_ubanum, &tm_ubinfo);
E 11
I 11
D 12
		ubarelse(tmdinfo[d]->ui_ubanum, &tm_ubinfo);
E 12
I 12
D 13
		ubarelse(um->um_ubanum, &sc->sc_ubinfo);
E 13
I 13
		ubarelse(um->um_ubanum, &um->um_ubinfo);
E 13
E 12
E 11
E 9
E 5
		iodone(bp);
		break;
E 14

	case SSEEK:
D 12
		t_blkno = dbtofsb(bp->b_blkno);
E 12
I 12
D 49
		sc->sc_blkno = dbtofsb(bp->b_blkno);
E 49
I 49
		sc->sc_blkno = bdbtofsb(bp->b_blkno);
E 49
E 12
D 14
		break;
E 14
I 14
		goto opcont;
E 14

	default:
D 14
		return;
E 14
I 14
		panic("tmintr");
E 14
	}
D 14
	tmstart();
E 14
I 14
opdone:
	/*
	 * Reset error count and remove
	 * from device queue.
	 */
	um->um_tab.b_errcnt = 0;
	dp->b_actf = bp->av_forw;
D 64
	bp->b_resid = -addr->tmbc;
E 64
I 64
	/*
	 * Check resid; watch out for resid >32767 (tmbc not negative).
	 */
D 65
	if (addr->tmbc <= 0)
		bp->b_resid = -addr->tmbc;
	else
		bp->b_resid = 0x10000 - ((long)(u_short) addr->tmbc);
E 65
I 65
	bp->b_resid = ((int) -addr->tmbc) & 0xffff;
E 65
E 64
D 15
	ubarelse(um->um_ubanum, &um->um_ubinfo);
E 15
I 15
	ubadone(um);
E 15
	iodone(bp);
	/*
	 * Circulate slave to end of controller
	 * queue to give other slaves a chance.
	 */
	um->um_tab.b_actf = dp->b_forw;
	if (dp->b_actf) {
		dp->b_forw = NULL;
		if (um->um_tab.b_actf == NULL)
			um->um_tab.b_actf = dp;
		else
			um->um_tab.b_actl->b_forw = dp;
		um->um_tab.b_actl = dp;
	}
	if (um->um_tab.b_actf == 0)
		return;
opcont:
	tmstart(um);
E 14
}

I 34
tmtimer(dev)
	int dev;
{
	register struct te_softc *sc = &te_softc[TEUNIT(dev)];
I 43
	register short x;
E 43

	if (sc->sc_timo != INF && (sc->sc_timo -= 5) < 0) {
D 42
		printf("te%d: lost interrupt\n");
E 42
I 42
		printf("te%d: lost interrupt\n", TEUNIT(dev));
E 42
		sc->sc_timo = INF;
D 43
		(void) spl5();
E 43
I 43
		x = spl5();
E 43
		tmintr(TMUNIT(dev));
D 43
		(void) spl0();
E 43
I 43
		(void) splx(x);
E 43
	}
D 37
	timeout(tmtimer, dev, 5*hz);
E 37
I 37
	timeout(tmtimer, (caddr_t)dev, 5*hz);
E 37
}

E 34
tmseteof(bp)
	register struct buf *bp;
{
I 14
D 24
	register int unit = TMUNIT(bp->b_dev);
E 24
I 24
	register int teunit = TEUNIT(bp->b_dev);
E 24
E 14
I 9
D 46
	register struct device *addr = 
D 10
	    (struct device *)tminfo[minor(bp->b_dev)>>3]->ui_addr;
E 10
I 10
D 11
	    (struct device *)tminfo[minor(bp->b_dev)&03]->ui_addr;
E 11
I 11
D 12
	    (struct device *)tmdinfo[minor(bp->b_dev)&03]->ui_addr;
E 12
I 12
D 14
	    (struct device *)tmdinfo[0]->ui_addr;
	register struct tm_softc *sc = &tm_softc[0];
E 14
I 14
D 24
	    (struct device *)tmdinfo[unit]->ui_addr;
	register struct tm_softc *sc = &tm_softc[unit];
E 24
I 24
	    (struct device *)tedinfo[teunit]->ui_addr;
E 46
I 46
	register struct tmdevice *addr = 
	    (struct tmdevice *)tedinfo[teunit]->ui_addr;
E 46
	register struct te_softc *sc = &te_softc[teunit];
E 24
E 14
E 12
E 11
E 10
E 9

D 14
	if (bp == &ctmbuf) {
E 14
I 14
D 24
	if (bp == &ctmbuf[unit]) {
E 24
I 24
	if (bp == &ctmbuf[TMUNIT(bp->b_dev)]) {
E 24
E 14
D 12
		if (t_blkno > dbtofsb(bp->b_blkno)) {
E 12
I 12
D 49
		if (sc->sc_blkno > dbtofsb(bp->b_blkno)) {
E 49
I 49
		if (sc->sc_blkno > bdbtofsb(bp->b_blkno)) {
E 49
E 12
			/* reversing */
D 9
			t_nxrec = dbtofsb(bp->b_blkno) - TMADDR->tmbc;
E 9
I 9
D 12
			t_nxrec = dbtofsb(bp->b_blkno) - addr->tmbc;
E 9
			t_blkno = t_nxrec;
E 12
I 12
D 49
			sc->sc_nxrec = dbtofsb(bp->b_blkno) - addr->tmbc;
E 49
I 49
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) - addr->tmbc;
E 49
			sc->sc_blkno = sc->sc_nxrec;
E 12
		} else {
			/* spacing forward */
D 9
			t_blkno = dbtofsb(bp->b_blkno) + TMADDR->tmbc;
E 9
I 9
D 12
			t_blkno = dbtofsb(bp->b_blkno) + addr->tmbc;
E 9
			t_nxrec = t_blkno - 1;
E 12
I 12
D 49
			sc->sc_blkno = dbtofsb(bp->b_blkno) + addr->tmbc;
E 49
I 49
			sc->sc_blkno = bdbtofsb(bp->b_blkno) + addr->tmbc;
E 49
			sc->sc_nxrec = sc->sc_blkno - 1;
E 12
		}
		return;
	} 
	/* eof on read */
D 12
	t_nxrec = dbtofsb(bp->b_blkno);
E 12
I 12
D 49
	sc->sc_nxrec = dbtofsb(bp->b_blkno);
E 49
I 49
	sc->sc_nxrec = bdbtofsb(bp->b_blkno);
E 49
E 12
D 76
}

D 52
tmread(dev)
E 52
I 52
tmread(dev, uio)
E 52
I 14
	dev_t dev;
I 52
	struct uio *uio;
E 52
E 14
{
I 54
	int errno;
E 54

D 52
	tmphys(dev);
E 52
I 52
D 54
	u.u_error = tmphys(dev, uio);
E 52
I 23
	if (u.u_error)
		return;
E 23
D 14
	physio(tmstrategy, &rtmbuf, dev, B_READ, minphys);
E 14
I 14
D 52
	physio(tmstrategy, &rtmbuf[TMUNIT(dev)], dev, B_READ, minphys);
E 52
I 52
	physio(tmstrategy, &rtmbuf[TMUNIT(dev)], dev, B_READ, minphys, uio);
E 54
I 54
	errno = tmphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(tmstrategy, &rtmbuf[TMUNIT(dev)], dev, B_READ, minphys, uio));
E 54
E 52
E 14
}

D 53
tmwrite(dev)
E 53
I 53
tmwrite(dev, uio)
E 53
I 14
	dev_t dev;
I 53
	struct uio *uio;
E 53
E 14
{
I 54
	int errno;
E 54

D 52
	tmphys(dev);
E 52
I 52
D 53
	tmphys(dev, 0);
E 53
I 53
D 54
	u.u_error = tmphys(dev, uio);
E 53
E 52
I 23
	if (u.u_error)
		return;
E 23
D 14
	physio(tmstrategy, &rtmbuf, dev, B_WRITE, minphys);
E 14
I 14
D 52
	physio(tmstrategy, &rtmbuf[TMUNIT(dev)], dev, B_WRITE, minphys);
E 52
I 52
D 53
	physio(tmstrategy, &rtmbuf[TMUNIT(dev)], dev, B_WRITE, minphys, 0);
E 53
I 53
	physio(tmstrategy, &rtmbuf[TMUNIT(dev)], dev, B_WRITE, minphys, uio);
E 54
I 54
	errno = tmphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(tmstrategy, &rtmbuf[TMUNIT(dev)], dev, B_WRITE, minphys, uio));
E 54
E 53
E 52
E 14
}

I 24
/*
 * Check that a raw device exists.
 * If it does, set up sc_blkno and sc_nxrec
 * so that the tape will appear positioned correctly.
 */
E 24
D 52
tmphys(dev)
E 52
I 52
tmphys(dev, uio)
E 52
I 14
	dev_t dev;
I 52
	struct uio *uio;
E 52
E 14
{
I 23
D 24
	register int unit = TMUNIT(dev);
E 24
I 24
	register int teunit = TEUNIT(dev);
E 24
E 23
	register daddr_t a;
I 12
D 14
	register struct tm_softc *sc = &tm_softc[0];
E 14
I 14
D 23
	register struct tm_softc *sc = &tm_softc[TMUNIT(dev)];
E 23
I 23
D 24
	register struct tm_softc *sc;
E 24
I 24
	register struct te_softc *sc;
	register struct uba_device *ui;
E 24
E 23
E 14
E 12

I 23
D 24
	if (unit >= NTM) {
E 24
I 24
D 53
	if (teunit >= NTE || (ui=tedinfo[teunit]) == 0 || ui->ui_alive == 0) {
E 24
		u.u_error = ENXIO;
E 53
I 53
	if (teunit >= NTE || (ui=tedinfo[teunit]) == 0 || ui->ui_alive == 0)
E 53
D 52
		return;
E 52
I 52
		return (ENXIO);
E 52
D 53
	}
E 53
D 24
	sc = &tm_softc[TMUNIT(dev)];
E 24
I 24
	sc = &te_softc[teunit];
E 24
E 23
D 49
	a = dbtofsb(u.u_offset >> 9);
E 49
I 49
D 52
	a = bdbtofsb(u.u_offset >> 9);
E 52
I 52
D 53
	if (uio)
		a = bdbtofsb(uio->uio_offset >> 9);
	else
		a = bdbtofsb(u.u_offset >> 9);
E 53
I 53
	a = bdbtofsb(uio->uio_offset >> 9);
E 53
E 52
E 49
D 12
	t_blkno = a;
	t_nxrec = a + 1;
E 12
I 12
	sc->sc_blkno = a;
	sc->sc_nxrec = a + 1;
I 52
	return (0);
E 76
E 52
E 12
}

I 14
tmreset(uban)
	int uban;
{
D 22
	int printed = 0;
E 22
D 23
	register struct uba_minfo *um;
E 23
I 23
	register struct uba_ctlr *um;
E 23
D 16
	register tm03, unit;
E 16
I 16
D 24
	register tm11, unit;
E 24
I 24
	register tm11, teunit;
E 24
E 16
D 23
	register struct uba_dinfo *ui;
E 23
I 23
	register struct uba_device *ui;
E 23
	register struct buf *dp;

D 16
	for (tm03 = 0; tm03 < NTM03; tm03++) {
		if ((um = tmminfo[tm03]) == 0 || um->um_alive == 0 ||
E 16
I 16
	for (tm11 = 0; tm11 < NTM; tm11++) {
		if ((um = tmminfo[tm11]) == 0 || um->um_alive == 0 ||
E 16
		   um->um_ubanum != uban)
			continue;
D 22
		if (printed == 0) {
			printf(" tm");
			DELAY(2000000);		/* time to self test */
			printed = 1;
		}
E 22
I 22
		printf(" tm%d", tm11);
E 22
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
		if (um->um_ubinfo) {
			printf("<%d>", (um->um_ubinfo>>28)&0xf);
D 15
			ubarelse(um->um_ubanum, &um->um_ubinfo);
E 15
I 15
D 59
			ubadone(um);
E 59
I 59
			um->um_ubinfo = 0;
E 59
E 15
		}
D 46
		((struct device *)(um->um_addr))->tmcs = TM_DCLR;
E 46
I 46
		((struct tmdevice *)(um->um_addr))->tmcs = TM_DCLR;
E 46
D 16
		for (unit = 0; unit < NTM11; unit++) {
E 16
I 16
D 24
		for (unit = 0; unit < NTE; unit++) {
E 16
			if ((ui = tmdinfo[unit]) == 0)
E 24
I 24
		for (teunit = 0; teunit < NTE; teunit++) {
			if ((ui = tedinfo[teunit]) == 0 || ui->ui_mi != um ||
			    ui->ui_alive == 0)
E 24
				continue;
D 24
			if (ui->ui_alive == 0)
				continue;
			dp = &tmutab[unit];
E 24
I 24
			dp = &teutab[teunit];
E 24
			dp->b_active = 0;
			dp->b_forw = 0;
			if (um->um_tab.b_actf == NULL)
				um->um_tab.b_actf = dp;
			else
				um->um_tab.b_actl->b_forw = dp;
			um->um_tab.b_actl = dp;
D 24
			tm_softc[unit].sc_openf = -1;
E 24
I 24
D 34
			te_softc[teunit].sc_openf = -1;
E 34
I 34
			if (te_softc[teunit].sc_openf > 0)
				te_softc[teunit].sc_openf = -1;
E 34
E 24
		}
		tmstart(um);
	}
}

E 14
/*ARGSUSED*/
D 51
tmioctl(dev, cmd, addr, flag)
	caddr_t addr;
E 51
I 51
tmioctl(dev, cmd, data, flag)
	caddr_t data;
E 51
	dev_t dev;
{
I 14
D 24
	int unit = TMUNIT(dev);
	register struct tm_softc *sc = &tm_softc[unit];
	register struct buf *bp = &ctmbuf[unit];
E 24
I 24
	int teunit = TEUNIT(dev);
	register struct te_softc *sc = &te_softc[teunit];
	register struct buf *bp = &ctmbuf[TMUNIT(dev)];
E 24
E 14
	register callcount;
I 12
D 14
	register struct tm_softc *sc = &tm_softc[0];
E 14
E 12
	int fcount;
D 51
	struct mtop mtop;
	struct mtget mtget;
E 51
I 51
	struct mtop *mtop;
	struct mtget *mtget;
E 51
	/* we depend of the values and order of the MT codes here */
D 7
	static tmops[] = {WEOF, SFORW, SREV, SFORW, SREV, REW, OFFL};
E 7
I 7
D 14
	static tmops[] = {WEOF, SFORW, SREV, SFORW, SREV, REW, OFFL, NOP};
E 14
I 14
	static tmops[] =
	   {TM_WEOF,TM_SFORW,TM_SREV,TM_SFORW,TM_SREV,TM_REW,TM_OFFL,TM_SENSE};
E 14
E 7

D 14
	switch(cmd) {
E 14
I 14
	switch (cmd) {
E 14
D 51
		case MTIOCTOP:	/* tape operation */
		if (copyin((caddr_t)addr, (caddr_t)&mtop, sizeof(mtop))) {
			u.u_error = EFAULT;
			return;
		}
		switch(mtop.mt_op) {
E 51
I 51

	case MTIOCTOP:	/* tape operation */
		mtop = (struct mtop *)data;
D 56
		switch(mtop->mt_op) {
E 56
I 56
		switch (mtop->mt_op) {
E 56

E 51
D 14
		case MTWEOF: case MTFSF: case MTBSF:
E 14
I 14
		case MTWEOF:
E 14
D 51
			callcount = mtop.mt_count;
E 51
I 51
			callcount = mtop->mt_count;
E 51
I 14
			fcount = 1;
			break;
I 51

E 51
		case MTFSF: case MTBSF:
D 51
			callcount = mtop.mt_count;
E 51
I 51
			callcount = mtop->mt_count;
E 51
E 14
			fcount = INF;
			break;
I 51

E 51
		case MTFSR: case MTBSR:
			callcount = 1;
D 51
			fcount = mtop.mt_count;
E 51
I 51
			fcount = mtop->mt_count;
E 51
			break;
I 51

E 51
D 7
		case MTREW: case MTOFFL:
E 7
I 7
		case MTREW: case MTOFFL: case MTNOP:
E 7
			callcount = 1;
			fcount = 1;
			break;
I 51

E 51
		default:
D 56
			u.u_error = ENXIO;
			return;
E 56
I 56
			return (ENXIO);
E 56
		}
D 14
		if (callcount <= 0 || fcount <= 0)
E 14
I 14
D 56
		if (callcount <= 0 || fcount <= 0) {
E 14
			u.u_error = ENXIO;
D 14
		else while (--callcount >= 0) {
E 14
I 14
			return;
		}
E 56
I 56
		if (callcount <= 0 || fcount <= 0)
			return (EINVAL);
E 56
		while (--callcount >= 0) {
E 14
D 13
			tcommand(dev, tmops[mtop.mt_op], fcount);
E 13
I 13
D 51
			tmcommand(dev, tmops[mtop.mt_op], fcount);
E 13
			if ((mtop.mt_op == MTFSR || mtop.mt_op == MTBSR) &&
E 51
I 51
			tmcommand(dev, tmops[mtop->mt_op], fcount);
			if ((mtop->mt_op == MTFSR || mtop->mt_op == MTBSR) &&
E 51
D 14
			    ctmbuf.b_resid) {
E 14
I 14
D 56
			    bp->b_resid) {
E 14
				u.u_error = EIO;
				break;
			}
E 56
I 56
			    bp->b_resid)
				return (EIO);
E 56
D 12
			if ((ctmbuf.b_flags&B_ERROR) || t_erreg&BOT)
E 12
I 12
D 14
			if ((ctmbuf.b_flags&B_ERROR) ||
			    sc->sc_erreg&BOT)
E 14
I 14
D 24
			if ((bp->b_flags&B_ERROR) || sc->sc_erreg&TM_BOT)
E 24
I 24
			if ((bp->b_flags&B_ERROR) || sc->sc_erreg&TMER_BOT)
E 24
E 14
E 12
				break;
		}
D 14
		geterror(&ctmbuf);
E 14
I 14
D 56
		geterror(bp);
E 14
		return;
E 56
I 56
D 58
		geterror(bp);		/* XXX */
		return (u.u_error);	/* XXX */
E 58
I 58
		return (geterror(bp));
E 58
E 56
I 51

E 51
	case MTIOCGET:
D 12
		mtget.mt_dsreg = t_dsreg;
		mtget.mt_erreg = t_erreg;
		mtget.mt_resid = t_resid;
E 12
I 12
D 51
		mtget.mt_dsreg = sc->sc_dsreg;
		mtget.mt_erreg = sc->sc_erreg;
		mtget.mt_resid = sc->sc_resid;
I 31
D 32
		mtget.mt_type = MI_ISTM;
E 32
I 32
		mtget.mt_type = MT_ISTM;
E 32
E 31
E 12
		if (copyout((caddr_t)&mtget, addr, sizeof(mtget)))
			u.u_error = EFAULT;
E 51
I 51
		mtget = (struct mtget *)data;
		mtget->mt_dsreg = sc->sc_dsreg;
		mtget->mt_erreg = sc->sc_erreg;
		mtget->mt_resid = sc->sc_resid;
		mtget->mt_type = MT_ISTM;
E 51
D 56
		return;
E 56
I 56
		break;
E 56
I 51

E 51
	default:
D 56
		u.u_error = ENXIO;
E 56
I 56
		return (ENXIO);
E 56
	}
I 56
	return (0);
E 56
}

#define	DBSIZE	20

D 8
twall(start, num)
E 8
I 8
tmdump()
{
D 10

	tmwall((char *)0, maxfree);	/* write out memory */
	tmeof();
	tmeof();
	tmrewind();
	tmwait();
}

tmwall(start, num)
E 8
	int start, num;
{
E 10
D 9
#if VAX==780
	register struct uba_regs *up = (struct uba_regs *)PHYSUBA0;
#endif
E 9
I 9
D 23
	register struct uba_dinfo *ui;
E 23
I 23
	register struct uba_device *ui;
E 23
	register struct uba_regs *up;
D 46
	register struct device *addr;
E 46
I 46
	register struct tmdevice *addr;
E 46
E 9
D 6
	int blk;
E 6
I 6
D 10
	int blk, bdp;
E 10
I 10
	int blk, num;
	int start;
E 10
E 6

D 7
	TMPHYS->tmcs = DCLR | GO;
E 7
D 9
#if VAX==780
	up->uba_cr = ADINIT;
	up->uba_cr = IFS|BRIE|USEFIE|SUEFIE;
	while ((up->uba_cnfgr & UBIC) == 0)
		;
E 9
I 9
D 10
#define	phys1(a,b)	((b)((int)(a)&0x7fffffff))
#define	phys(a,b)	phys1(*phys1(&a, b*), b)
E 10
I 10
	start = 0;
	num = maxfree;
#define	phys(a,b)	((b)((int)(a)&0x7fffffff))
E 10
D 11
	if (tminfo[0] == 0) {
E 11
I 11
D 21
	if (tmdinfo[0] == 0) {
E 11
		printf("dna\n");
		return (-1);
	}
E 21
I 21
D 24
	if (tmdinfo[0] == 0)
E 24
I 24
	if (tedinfo[0] == 0)
E 24
		return (ENXIO);
E 21
D 11
	ui = phys(tminfo[0], struct uba_dinfo *);
E 11
I 11
D 23
	ui = phys(tmdinfo[0], struct uba_dinfo *);
E 23
I 23
D 24
	ui = phys(tmdinfo[0], struct uba_device *);
E 24
I 24
	ui = phys(tedinfo[0], struct uba_device *);
E 24
E 23
E 11
	up = phys(ui->ui_hd, struct uba_hd *)->uh_physuba;
D 30
#if VAX780
	if (cpu == VAX_780)
		ubainit(up);
E 9
#endif
E 30
I 30
	ubainit(up);
E 30
I 7
	DELAY(1000000);
D 8
	twait();
E 8
I 8
D 9
	tmwait();
E 8
	TMPHYS->tmcs = DCLR | GO;
E 9
I 9
D 46
	addr = (struct device *)ui->ui_physaddr;
E 46
I 46
	addr = (struct tmdevice *)ui->ui_physaddr;
E 46
	tmwait(addr);
D 14
	addr->tmcs = DCLR | GO;
E 14
I 14
	addr->tmcs = TM_DCLR | TM_GO;
E 14
E 9
E 7
	while (num > 0) {
		blk = num > DBSIZE ? DBSIZE : num;
D 9
		tmdwrite(start, blk);
E 9
I 9
		tmdwrite(start, blk, addr, up);
E 9
		start += blk;
		num -= blk;
	}
I 2
D 6
	((struct uba_regs *)PHYSUBA0)->uba_dpr[1] |= BNE;
E 6
I 6
D 10
	bdp = 1;		/* crud to fool c compiler */
D 9
	((struct uba_regs *)PHYSUBA0)->uba_dpr[bdp] |= BNE;
E 9
I 9
	up->uba_dpr[bdp] |= UBA_BNE;
E 10
I 10
D 12
	tmwait(addr);
E 12
	tmeof(addr);
	tmeof(addr);
D 12
	tmrewind(addr);
E 12
	tmwait(addr);
I 21
	if (addr->tmcs&TM_ERR)
		return (EIO);
E 21
I 12
D 14
	addr->tmcs = REW | GO;
E 14
I 14
	addr->tmcs = TM_REW | TM_GO;
E 14
	tmwait(addr);
E 12
E 10
E 9
I 8
	return (0);
E 8
E 6
E 2
}

D 9
tmdwrite(buf, num)
register buf, num;
E 9
I 9
D 14
tmdwrite(buf, num, addr, up)
	register buf, num;
E 14
I 14
tmdwrite(dbuf, num, addr, up)
	register dbuf, num;
E 14
D 46
	register struct device *addr;
E 46
I 46
	register struct tmdevice *addr;
E 46
	struct uba_regs *up;
E 9
{
D 9
	register int *io, npf;
E 9
I 9
	register struct pte *io;
	register int npf;
E 9
I 6
D 10
	int bdp;
E 10
E 6
I 2

E 2
D 4
	tmwait();
E 4
I 4
D 8
	twait();
E 8
I 8
D 9
	tmwait();
E 9
I 9
	tmwait(addr);
E 9
E 8
E 4
D 2
	/* Flush buffered data path 0 */
	((struct uba_regs *)PHYSUBA0)->uba_dpr[1] = 0;
	((struct uba_regs *)PHYSUBA0)->uba_dpr[1] = BNE;
	/* Map unibus address 0 to section of interest */
E 2
I 2
D 6
	((struct uba_regs *)PHYSUBA0)->uba_dpr[1] |= BNE;
E 6
I 6
D 10
	bdp = 1;		/* more dastardly tricks on pcc */
D 9
	((struct uba_regs *)PHYSUBA0)->uba_dpr[bdp] |= BNE;
E 6
E 2
	io = (int *)((struct uba_regs *)PHYSUBA0)->uba_map;
E 9
I 9
	up->uba_dpr[bdp] |= UBA_BNE;
E 10
	io = up->uba_map;
E 9
	npf = num+1;
D 2
	while(--npf != 0)
E 2
I 2
	while (--npf != 0)
E 2
D 9
		 *io++ = (int)(buf++ | (1<<21) | MRV);
	*io = 0;
	TMPHYS->tmbc = -(num*NBPG);
	TMPHYS->tmba = 0;
D 7
	TMPHYS->tmcs = WCOM | GO | D800;
E 7
I 7
	TMPHYS->tmcs = WCOM | GO;
E 9
I 9
D 14
		 *(int *)io++ = (buf++ | (1<<UBA_DPSHIFT) | UBA_MRV);
E 14
I 14
D 23
		 *(int *)io++ = (dbuf++ | (1<<UBA_DPSHIFT) | UBA_MRV);
E 23
I 23
		 *(int *)io++ = (dbuf++ | (1<<UBAMR_DPSHIFT) | UBAMR_MRV);
E 23
E 14
	*(int *)io = 0;
	addr->tmbc = -(num*NBPG);
	addr->tmba = 0;
D 14
	addr->tmcs = WCOM | GO;
E 14
I 14
	addr->tmcs = TM_WCOM | TM_GO;
E 14
E 9
E 7
}

D 4
tmwait()
E 4
I 4
D 8
twait()
E 8
I 8
D 9
tmwait()
E 9
I 9
tmwait(addr)
D 46
	register struct device *addr;
E 46
I 46
	register struct tmdevice *addr;
E 46
E 9
E 8
E 4
{
D 2
	register short s;
E 2
I 2
	register s;
E 2

	do
D 9
		s = TMPHYS->tmcs;
E 9
I 9
		s = addr->tmcs;
E 9
D 14
	while ((s & CUR) == 0);
E 14
I 14
	while ((s & TM_CUR) == 0);
E 14
D 12
}

D 4
tmrewind()
E 4
I 4
D 8
rewind()
E 8
I 8
D 9
tmrewind()
E 9
I 9
tmrewind(addr)
	struct device *addr;
E 9
E 8
E 4
{

D 4
	tmwait();
E 4
I 4
D 8
	twait();
E 8
I 8
D 9
	tmwait();
E 8
E 4
	TMPHYS->tmcs = REW | GO;
E 9
I 9
	tmwait(addr);
	addr->tmcs = REW | GO;
E 12
E 9
}

D 4
tmeof()
E 4
I 4
D 8
teof()
E 8
I 8
D 9
tmeof()
E 9
I 9
tmeof(addr)
D 46
	struct device *addr;
E 46
I 46
	struct tmdevice *addr;
E 46
E 9
E 8
E 4
{

D 4
	tmwait();
E 4
I 4
D 8
	twait();
E 8
I 8
D 9
	tmwait();
E 8
E 4
D 7
	TMPHYS->tmcs = WEOF | GO | D800;
E 7
I 7
	TMPHYS->tmcs = WEOF | GO;
E 9
I 9
	tmwait(addr);
D 14
	addr->tmcs = WEOF | GO;
E 14
I 14
	addr->tmcs = TM_WEOF | TM_GO;
E 14
E 9
E 7
}
#endif
E 1
