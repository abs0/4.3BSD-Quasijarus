h22249
s 00027/00069/00558
d D 7.6 88/05/06 17:21:45 bostic 57 56
c changes for raw{read,write} stuff
e
s 00004/00002/00623
d D 7.5 87/06/18 14:39:16 karels 56 54
c nonexistent slaves aren't really on formatter 0
e
s 00002/00002/00623
d R 7.5 87/06/18 14:09:26 karels 55 54
c all nonexistent slaves aren't on formatter 0!
e
s 00004/00004/00621
d D 7.4 87/05/12 11:37:02 karels 54 53
c add bits for tri-density tape
e
s 00001/00000/00624
d D 7.3 87/05/07 09:38:37 karels 53 52
c need syslog.h
e
s 00015/00003/00609
d D 7.2 87/04/17 14:10:21 karels 52 51
c fix race in open; log excessive soft errs
e
s 00001/00001/00611
d D 7.1 86/06/05 01:29:49 mckusick 51 50
c 4.3BSD release version
e
s 00001/00001/00611
d D 6.7 86/02/20 17:28:15 karels 50 48
c lint
e
s 00001/00001/00611
d R 6.7 86/02/20 17:24:40 karels 49 48
c cd ../vaxuba
e
s 00004/00002/00608
d D 6.6 85/10/01 09:41:17 karels 48 47
c no ENXIO if busy
e
s 00007/00001/00603
d D 6.5 85/06/08 14:06:33 mckusick 47 46
c Add copyright
e
s 00005/00002/00599
d D 6.4 85/03/13 09:50:20 ralph 46 45
c change printf error messages to tprintf's.
e
s 00015/00015/00586
d D 6.3 84/08/29 20:52:55 bloom 45 44
c change to includes.  no more ../h
e
s 00003/00000/00598
d D 6.2 83/09/26 22:05:08 karels 44 43
c sense command in htustart may hang controller if no slave (from dlw)
e
s 00000/00000/00598
d D 6.1 83/07/29 07:34:45 sam 43 42
c 4.2 distribution
e
s 00000/00001/00598
d D 4.36 83/05/27 13:54:47 sam 42 41
c leftovers
e
s 00002/00001/00597
d D 4.35 82/12/17 12:09:16 sam 41 40
c sun merge
e
s 00001/00002/00597
d D 4.34 82/10/20 02:23:46 root 40 39
c lint
e
s 00002/00001/00597
d D 4.33 82/10/20 01:07:16 root 39 38
c lint
e
s 00000/00000/00598
d D 4.32 82/10/17 23:07:29 root 38 37
c lint
e
s 00003/00001/00595
d D 4.31 82/10/17 15:31:45 root 37 36
c minor lint
e
s 00016/00024/00580
d D 4.30 82/10/17 11:54:43 root 36 35
c open/ioctl routine return errors; hpopen!!!
e
s 00004/00004/00600
d D 4.29 82/10/10 17:19:31 root 35 34
c vax header files in their place
e
s 00010/00008/00594
d D 4.28 82/09/12 03:04:45 root 34 33
c physio returns errors
e
s 00004/00009/00598
d D 4.27 82/08/22 21:17:16 root 33 32
c fully uio()'d
e
s 00015/00008/00592
d D 4.26 82/08/13 00:23:46 root 32 31
c hacks for chardev uio
e
s 00026/00022/00574
d D 4.25 82/08/01 19:28:36 sam 31 30
c new ioctl's
e
s 00004/00003/00592
d D 4.24 82/07/15 20:32:51 kre 30 29
c slave routines now have sn passwd as param rather than in struct
e
s 00014/00014/00581
d D 4.23 82/07/13 18:09:04 sam 29 28
c bdbtofsb maps block device blocks to DEV_BSIZE blocks
e
s 00001/00000/00594
d D 4.22 82/05/12 16:28:22 wnj 28 27
c fix per Jeffrey Jongeward
e
s 00006/00004/00588
d D 4.21 82/01/17 20:28:09 root 27 26
c remove spl0's from block tape routines
e
s 00009/00003/00583
d D 4.20 81/11/07 10:38:09 wnj 26 25
c fixes from shannon
e
s 00001/00001/00585
d D 4.19 81/08/31 03:14:09 root 25 24
c fix per shannon
e
s 00003/00003/00583
d D 4.18 81/05/10 01:25:05 root 24 23
c spelling errors
e
s 00013/00004/00573
d D 4.17 81/05/09 19:49:58 root 23 22
c better error messages
e
s 00001/00000/00576
d D 4.16 81/04/03 07:38:42 toy 22 21
c Added type to MTIOCGET ioctl.
e
s 00011/00007/00565
d D 4.15 81/03/11 18:38:28 wnj 21 20
c new version (from ernie)
e
s 00004/00004/00568
d D 4.14 81/03/11 18:36:36 wnj 20 19
c fix up density sensing
e
s 00003/00003/00569
d D 4.13 81/03/10 16:56:09 wnj 19 18
c ht typos; mba maintain dk_busy for seeks; up minor fixes; va and vp new working versions
e
s 00022/00014/00550
d D 4.12 81/03/09 19:45:26 wnj 18 17
c fixes from monday and also dont print console errors when only
c thing wrong is record length
e
s 00000/00000/00564
d D 4.11 81/03/09 01:53:17 wnj 17 16
c %G% -> %E%
e
s 00002/00001/00562
d D 4.10 81/03/09 00:34:00 wnj 16 15
c lint
e
s 00084/00090/00479
d D 4.9 81/03/08 20:12:32 wnj 15 14
c fixups just pre lint
e
s 00057/00030/00512
d D 4.8 81/03/07 14:27:53 wnj 14 13
c after attempt at ht driver at cc again; working with new 
c field names
e
s 00024/00022/00518
d D 4.7 81/03/07 00:40:42 wnj 13 12
c more fixups
e
s 00010/00028/00530
d D 4.6 81/03/06 18:23:34 wnj 12 11
c another non-working version
e
s 00423/00282/00135
d D 4.5 81/03/06 11:31:17 wnj 11 10
c first (non-working) version
e
s 00001/00001/00416
d D 4.4 80/12/19 11:43:55 wnj 10 9
c s,../conf/,,
e
s 00063/00000/00354
d D 4.3 80/12/17 18:34:55 wnj 9 8
c tdump in the driver
e
s 00000/00001/00354
d D 4.2 80/11/11 00:01:14 bill 8 7
c let ht.h define NHT
e
s 00000/00000/00355
d D 4.1 80/11/09 16:52:27 bill 7 6
c stamp for 4bsd
e
s 00010/00011/00345
d D 3.6 80/10/19 22:15:51 bill 6 5
c ../conf/*.h
e
s 00041/00035/00315
d D 3.5 80/07/29 09:15:01 bill 5 4
c new mba stuff
e
s 00001/00001/00349
d D 3.4 80/06/07 02:45:51 bill 4 3
c %H%->%G%
e
s 00005/00006/00345
d D 3.3 80/06/04 13:59:56 bill 3 2
c reformat
e
s 00009/00009/00342
d D 3.2 80/05/08 10:21:39 bill 2 1
c VOID=>void
e
s 00351/00000/00000
d D 3.1 80/04/09 16:03:18 bill 1 0
c date and time created 80/04/09 16:03:18 by bill
e
u
U
t
T
I 13
D 47
/*	%M%	%I%	%E%	*/
E 47
I 47
/*
D 51
 * Copyright (c) 1982 Regents of the University of California.
E 51
I 51
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 51
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 47

E 13
I 1
D 4
/*	%M%	%I%	%H%	*/
E 4
I 4
D 11
/*	%M%	%I%	%G%	*/
E 4

E 11
I 6
D 10
#include "../conf/ht.h"
E 10
I 10
D 14
#include "ht.h"
E 14
I 14
#include "tu.h"
E 14
E 10
#if NHT > 0
E 6
/*
D 11
 * TJU16 tape driver
E 11
I 11
 * TM03/TU?? tape driver
I 15
 *
 * TODO:
D 18
 *	test tape writing
E 18
D 21
 *	test error handling
E 21
I 21
 *	cleanup messages on errors
E 21
D 18
 *	test 2 tapes
E 18
D 20
 *	test tape with disk on same mba
E 20
D 18
 *	test dump code
 *	try a mounted filesys on tape to check positioning code
E 18
 *	test ioctl's
 *	see how many rewind interrups we get if we kick when not at BOT
I 18
D 20
 *	test writing on write prot tape and error thereby
E 20
D 21
 *	check rle error on block tape code
E 21
I 21
 *	fixup rle error on block tape code
E 21
E 18
E 15
E 11
 */
I 41
D 52
#include "../machine/pte.h"

E 52
E 41
D 11

E 11
D 45
#include "../h/param.h"
#include "../h/systm.h"
#include "../h/buf.h"
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/file.h"
#include "../h/user.h"
#include "../h/map.h"
I 5
D 41
#include "../h/pte.h"
E 41
E 5
D 14
#include "../h/mba.h"
E 14
I 14
D 35
#include "../h/mbareg.h"
#include "../h/mbavar.h"
E 35
E 14
I 9
D 11
#include "../h/vm.h"
E 11
I 11
D 31
#include "../h/mtio.h"
E 31
#include "../h/ioctl.h"
I 31
#include "../h/mtio.h"
E 31
E 11
#include "../h/cmap.h"
I 13
D 35
#include "../h/cpu.h"
E 35
I 32
#include "../h/uio.h"
E 45
I 45
#include "param.h"
#include "systm.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "file.h"
#include "user.h"
#include "map.h"
#include "ioctl.h"
#include "mtio.h"
#include "cmap.h"
#include "uio.h"
I 46
#include "tty.h"
I 53
#include "syslog.h"
E 53
E 46
E 45
E 32
E 13
E 9

I 52
#include "../machine/pte.h"
E 52
D 11
struct	device
{
	int	htcs1;
	int	htds;
	int	hter;
	int	htmr;
	int	htas;
	int	htfc;
	int	htdt;
	int	htck;
	int	htsn;
	int	httc;
};
E 11
I 11
D 35
#include "../h/htreg.h"
E 35
I 35
#include "../vax/cpu.h"
D 45
#include "../vaxmba/mbareg.h"
#include "../vaxmba/mbavar.h"
#include "../vaxmba/htreg.h"
E 45
I 45
#include "mbareg.h"
#include "mbavar.h"
#include "htreg.h"
E 45
E 35
E 11

D 11
struct	buf	httab;
struct	buf	rhtbuf;
struct	buf	chtbuf;
E 11
I 11
D 57
struct	buf	rhtbuf[NHT];
E 57
struct	buf	chtbuf[NHT];
E 11

D 6
#define	NUNIT	1
#define	BUNIT	2
E 6
I 6
D 8
#define	NHT	1
E 8
E 6
D 11
#define	INF	1000000
E 11
I 11
short	httypes[] =
D 19
	{ MBDT_TE16, MBDT_TU45, MBDT_TU77, 0 };
E 19
I 19
	{ MBDT_TM03, MBDT_TE16, MBDT_TU45, MBDT_TU77, 0 };
E 19
D 14
struct	mba_info *htinfo[NHT];
int	htdkinit(), htustart(), htndtint(), htdtint();
E 14
I 14
struct	mba_device *htinfo[NHT];
I 56
struct	mba_slave *tuinfo[NTU];
E 56
D 16
int	htdkinit(), htattach(), htslave(), htustart(), htndtint(), htdtint();
E 16
I 16
int	htattach(), htslave(), htustart(), htndtint(), htdtint();
E 16
E 14
struct	mba_driver htdriver =
D 14
	{ htdkinit, htustart, 0, htdtint, htndtint, httypes, htinfo };
E 14
I 14
    { htattach, htslave, htustart, 0, htdtint, htndtint,
      httypes, "ht", "tu", htinfo };
E 14
E 11

D 6
char	h_openf[NUNIT];
daddr_t	h_blkno[NUNIT];
char	h_flags[NUNIT];
daddr_t	h_nxrec[NUNIT];
E 6
I 6
D 11
char	h_openf[NHT];
daddr_t	h_blkno[NHT];
char	h_flags[NHT];
daddr_t	h_nxrec[NHT];
E 11
I 11
#define MASKREG(r)	((r) & 0xffff)
E 11
E 6

D 5
#define	HTADDR	((struct device *)(MBA1 + MBA_ERB))
E 5
I 5
D 6
#define	HTMBA		MBA1
#define	HTMBANUM	1
E 5

E 6
D 11
#define	GO	01
#define	WCOM	060
#define	RCOM	070
#define	NOP	0
#define	WEOF	026
#define	SFORW	030
#define	SREV	032
#define	ERASE	024
#define	REW	06
#define	DCLR	010
#define	P800	01700		/* 800 + pdp11 mode */
#define	P1600	02300		/* 1600 + pdp11 mode */
#define	IENABLE	0100
#define	RDY	0200
#define	TM	04
#define	DRY	0200
#define	EOT	02000
#define	CS	02000
#define	COR	0100000
#define	PES	040
#define	WRL	04000
#define	MOL	010000
#define	ERR	040000
#define	FCE	01000
#define	TRE	040000
#define	HARD	064023	/* UNS|OPI|NEF|FMT|RMR|ILR|ILF */
E 11
I 11
/* bits in minor device */
D 14
#define HTUNIT(dev)	(minor(dev)&03)
E 14
I 14
#define	TUUNIT(dev)	(minor(dev)&03)
E 14
#define	H_NOREWIND	04
D 54
#define	H_1600BPI	08
E 54
I 54
#define	H_DENS(dev)	((minor(dev) >> 3) & 03)
E 54
E 11

I 14
D 15
#define HTUNIT(dev)	(htunit[TUUNIT(dev)])
E 15
I 15
D 57
#define HTUNIT(dev)	(tutoht[TUUNIT(dev)])
E 57
I 57
#define HTUNIT(dev)	(tuinfo[TUUNIT(dev)]->ms_ctlr)
E 57
E 15

E 14
I 11
#define	INF	(daddr_t)1000000L	/* a block number that wont exist */

D 15
struct	ht_softc {
E 15
I 15
struct	tu_softc {
E 15
	char	sc_openf;
	char	sc_flags;
	daddr_t	sc_blkno;
	daddr_t	sc_nxrec;
	u_short	sc_erreg;
	u_short	sc_dsreg;
	short	sc_resid;
	short	sc_dens;
D 14
} ht_softc[NHT];
E 14
I 14
D 57
	struct	mba_device *sc_mi;
	int	sc_slave;
E 57
I 46
	struct	tty *sc_ttyp;		/* record user's tty for errors */
I 52
	int	sc_blks;	/* number of I/O operations since open */
	int	sc_softerrs;	/* number of soft I/O errors since open */
E 52
E 46
D 15
} ht_softc[NTU];
short	htunit[NTU];
E 15
I 15
} tu_softc[NTU];
D 57
short	tutoht[NTU];
E 57
E 15
E 14

/*
D 12
 * States for b_active for device.
 */
E 11
#define	SIO	1
#define	SSFOR	2
#define	SSREV	3
#define	SRETRY	4
#define	SCOM	5
#define	SOK	6
I 11
#define	SEOF	7
E 11

D 11
#define	H_WRITTEN 1
E 11
I 11
/*
E 12
 * Bits for sc_flags.
 */
#define	H_WRITTEN 1	/* last operation was a write */
#define H_ERASED  2	/* last write retry was an erase gap */
#define H_REWIND  4	/* last unit start was a rewind */
E 11

I 21
char	hter_bits[] = HTER_BITS;
char	htds_bits[] = HTDS_BITS;

E 21
I 11
/*ARGSUSED*/
D 14
htdkinit(mi)
	struct mba_info *mi;
E 14
I 14
htattach(mi)
	struct mba_device *mi;
E 14
{

}

I 14
D 30
htslave(mi, ms)
E 30
I 30
htslave(mi, ms, sn)
E 30
	struct mba_device *mi;
	struct mba_slave *ms;
I 30
	int sn;
E 30
{
D 15
	register struct ht_softc *sc = &ht_softc[ms->ms_unit];
E 15
I 15
D 57
	register struct tu_softc *sc = &tu_softc[ms->ms_unit];
E 57
I 26
	register struct htdevice *htaddr = (struct htdevice *)mi->mi_drv;
E 26
E 15

D 26
	sc->sc_mi = mi;
	sc->sc_slave = ms->ms_slave;
D 15
	htunit[ms->ms_unit] = mi->mi_unit;
E 15
I 15
	tutoht[ms->ms_unit] = mi->mi_unit;
E 26
I 26
D 30
	htaddr->httc = ms->ms_slave;
E 30
I 30
	htaddr->httc = sn;
E 30
	if (htaddr->htdt & HTDT_SPR) {
D 57
		sc->sc_mi = mi;
D 30
		sc->sc_slave = ms->ms_slave;
E 30
I 30
		sc->sc_slave = sn;
E 57
I 56
		tuinfo[ms->ms_unit] = ms;
E 56
E 30
D 57
		tutoht[ms->ms_unit] = mi->mi_unit;
E 57
		return (1);
	} else
		return (0);
E 26
E 15
}

I 54
int	htdens[4] = { HTTC_800BPI, HTTC_1600BPI, HTTC_6250BPI, HTTC_800BPI };

E 54
E 14
E 11
htopen(dev, flag)
I 11
	dev_t dev;
	int flag;
E 11
{
D 11
	register unit, ds;
E 11
I 11
D 15
	register int unit;
E 15
I 15
	register int tuunit;
E 15
D 14
	register struct mba_info *mi;
E 14
I 14
D 57
	register struct mba_device *mi;
E 57
E 14
D 15
	register struct ht_softc *sc;
E 15
I 15
	register struct tu_softc *sc;
I 57
	register struct mba_slave *ms;
E 57
D 20
	int dens;
E 20
I 20
	int olddens, dens;
E 20
E 15
E 11

I 5
D 11
	if ((mbaact&(1<<HTMBANUM)) == 0)
		mbainit(HTMBANUM);
E 5
	httab.b_flags |= B_TAPE;
	unit = minor(dev) & 03;
D 6
	if (unit >= NUNIT || h_openf[unit]) {
E 6
I 6
	if (unit >= NHT || h_openf[unit]) {
E 11
I 11
D 14
	unit = HTUNIT(dev);
	if (unit >= NHT || (sc = &ht_softc[unit])->sc_openf ||
	    (mi = htinfo[unit]) == 0 || mi->mi_alive == 0) {
E 14
I 14
D 15
	unit = TUUNIT(dev);
	if (unit >= NTU || (sc = &ht_softc[unit])->sc_openf ||
E 15
I 15
	tuunit = TUUNIT(dev);
D 48
	if (tuunit >= NTU || (sc = &tu_softc[tuunit])->sc_openf ||
E 15
D 36
	    (mi = htinfo[HTUNIT(dev)]) == 0 || mi->mi_alive == 0) {
E 14
E 11
E 6
		u.u_error = ENXIO;
		return;
	}
E 36
I 36
	    (mi = htinfo[HTUNIT(dev)]) == 0 || mi->mi_alive == 0)
E 48
I 48
D 56
	if (tuunit >= NTU || (mi = htinfo[HTUNIT(dev)]) == 0 ||
	    mi->mi_alive == 0)
E 56
I 56
D 57
	if (tuunit >= NTU || tuinfo[tuunit]->ms_alive == 0 || 
	    (mi = htinfo[HTUNIT(dev)]) == 0 || mi->mi_alive == 0)
E 57
I 57
	if (tuunit >= NTU || (ms = tuinfo[tuunit]) == NULL ||
	    ms->ms_alive == 0 || htinfo[ms->ms_ctlr]->mi_alive == 0)
E 57
E 56
E 48
		return (ENXIO);
I 48
	if ((sc = &tu_softc[tuunit])->sc_openf)
		return (EBUSY);
I 52
	sc->sc_openf = 1;
E 52
E 48
E 36
D 11
	h_blkno[unit] = 0;
	h_nxrec[unit] = INF;
	h_flags[unit] = 0;
	ds = hcommand(dev, NOP);
	if ((ds&MOL)==0 || (flag && (ds&WRL)))
		u.u_error = ENXIO;
	if (u.u_error==0)
		h_openf[unit]++;
E 11
I 11
D 15
	/*
	 * The NOP below serves two purposes:
	 * 1. To get a recent copy of the status registers.
	 * 2. To ensure that any outstanding rewinds are truly finished
D 12
	 *	so that the test for BOT is valid.
E 12
	 */
E 15
D 20
	htcommand(dev, HT_SENSE, 1);
E 20
I 20
	olddens = sc->sc_dens;
E 20
I 15
D 21
	dens =
E 21
I 21
D 54
	dens = sc->sc_dens =
E 21
	    ((minor(dev)&H_1600BPI)?HTTC_1600BPI:HTTC_800BPI)|
		HTTC_PDP11|sc->sc_slave;
E 54
I 54
D 57
	dens = sc->sc_dens = htdens[H_DENS(dev)] | HTTC_PDP11 | sc->sc_slave;
E 57
I 57
	dens = sc->sc_dens = htdens[H_DENS(dev)] | HTTC_PDP11 | ms->ms_slave;
E 57
E 54
I 20
	htcommand(dev, HT_SENSE, 1);
	sc->sc_dens = olddens;
E 20
E 15
D 23
	if ((sc->sc_dsreg & HTDS_MOL) == 0 || 
I 18
	   (flag&FWRITE) && (sc->sc_dsreg&HTDS_WRL) ||
E 18
I 15
	   (sc->sc_dsreg & HTDS_BOT) == 0 && (flag&FWRITE) &&
D 18
		dens != sc->sc_dens ||
E 15
	   (flag & (FREAD|FWRITE)) == FWRITE && sc->sc_dsreg&HTDS_WRL) {
E 18
I 18
		dens != sc->sc_dens) {
E 23
I 23
	if ((sc->sc_dsreg & HTDS_MOL) == 0) {
I 52
		sc->sc_openf = 0;
E 52
D 24
		uprintf("ht%d: not online\n", htunit);
E 24
I 24
		uprintf("tu%d: not online\n", tuunit);
E 24
D 36
		u.u_error = EIO;
		return;
E 36
I 36
		return (EIO);
E 36
	}
	if ((flag&FWRITE) && (sc->sc_dsreg&HTDS_WRL)) {
I 52
		sc->sc_openf = 0;
E 52
D 24
		uprintf("ht%d: no write ring\n", htunit);
E 24
I 24
		uprintf("tu%d: no write ring\n", tuunit);
E 24
D 36
		u.u_error = EIO;
		return;
E 36
I 36
		return (EIO);
E 36
	}
	if ((sc->sc_dsreg & HTDS_BOT) == 0 && (flag&FWRITE) &&
	    dens != sc->sc_dens) {
I 52
		sc->sc_openf = 0;
E 52
D 24
		uprintf("ht%d: can't change density in mid-tape\n", htunit);
E 24
I 24
		uprintf("tu%d: can't change density in mid-tape\n", tuunit);
E 24
E 23
E 18
D 36
		u.u_error = EIO;
		return;
E 36
I 36
		return (EIO);
E 36
	}
D 15
	sc->sc_dens =
D 12
	    ((minor(dev)&H_1600BPI)?HTTC_1600BPI:HTTC_800BPI)|HTTC_PDP11|unit;
E 12
I 12
D 13
	    ((minor(dev)&H_1600BPI)?HTTC_1600BPI:HTTC_800BPI)|HTTC_PDP11|mi->mi_slave;
	printf("dens %o\n", sc->sc_dens);
E 13
I 13
	    ((minor(dev)&H_1600BPI)?HTTC_1600BPI:HTTC_800BPI)|
D 14
		HTTC_PDP11|mi->mi_slave;
E 14
I 14
		HTTC_PDP11|sc->sc_slave;
E 15
E 14
E 13
E 12
D 52
	sc->sc_openf = 1;
E 52
	sc->sc_blkno = (daddr_t)0;
	sc->sc_nxrec = INF;
	sc->sc_flags = 0;
I 15
	sc->sc_dens = dens;
I 52
	sc->sc_blks = 0;
	sc->sc_softerrs = 0;
E 52
I 46
	sc->sc_ttyp = u.u_ttyp;
E 46
I 36
	return (0);
E 36
E 15
E 11
}

htclose(dev, flag)
I 11
	register dev_t dev;
	register flag;
E 11
{
D 11
	register int unit;
E 11
I 11
D 14
	register struct ht_softc *sc = &ht_softc[HTUNIT(dev)];
E 14
I 14
D 15
	register struct ht_softc *sc = &ht_softc[TUUNIT(dev)];
E 15
I 15
	register struct tu_softc *sc = &tu_softc[TUUNIT(dev)];
E 15
E 14
E 11

D 11
	unit = minor(dev) & 03;
	if (flag == FWRITE || ((flag&FWRITE) && (h_flags[unit]&H_WRITTEN))) {
D 2
		VOID hcommand(dev, WEOF);
		VOID hcommand(dev, WEOF);
		VOID hcommand(dev, SREV);
E 2
I 2
		(void) hcommand(dev, WEOF);
		(void) hcommand(dev, WEOF);
		(void) hcommand(dev, SREV);
E 11
I 11
	if (flag == FWRITE || ((flag&FWRITE) && (sc->sc_flags&H_WRITTEN))) {
		htcommand(dev, HT_WEOF, 1);
		htcommand(dev, HT_WEOF, 1);
		htcommand(dev, HT_SREV, 1);
E 11
E 2
	}
D 2
/*	VOID hcommand(dev, REW);	*/
E 2
I 2
D 3
/*	(void) hcommand(dev, REW);	*/
E 2
/* for 'mtm' file positioning */
E 3
D 11
	if((minor(dev)&4) == 0) /* no 4 -> rewind */
D 2
		VOID hcommand(dev, REW);
E 2
I 2
		(void) hcommand(dev, REW);
E 2
	h_openf[unit] = 0;
E 11
I 11
	if ((minor(dev)&H_NOREWIND) == 0)
D 15
		/* 0 as third arg means don't wait */
E 15
		htcommand(dev, HT_REW, 0);
I 52
	if (sc->sc_blks > 100 && sc->sc_softerrs > sc->sc_blks / 100)
		log(LOG_INFO, "tu%d: %d soft errors in %d blocks\n",
		    TUUNIT(dev), sc->sc_softerrs, sc->sc_blks);
E 52
	sc->sc_openf = 0;
E 11
}

D 11
hcommand(dev, com)
E 11
I 11
D 15
/*
 * Do a non-data-transfer command.
 *
 * N.B.: Count should be zero ONLY for rewind during close.
 */
E 15
htcommand(dev, com, count)
	dev_t dev;
	int com, count;
E 11
{
	register struct buf *bp;
I 27
	register int s;
E 27

D 11
	bp = &chtbuf;
E 11
I 11
	bp = &chtbuf[HTUNIT(dev)];
E 11
D 2
	VOID spl5();
E 2
I 2
D 27
	(void) spl5();
E 27
I 27
	s = spl5();
E 27
E 2
D 11
	while(bp->b_flags&B_BUSY) {
E 11
I 11
D 12
	/*
	 * The B_DONE test is to allow the rewind on close not to wait at
	 * all.  We just must make sure that it was an asynchronous rewind,
	 * otherwise if it isn't we might wake up before the process
	 * waiting for the command (we are waiting for the buffer here).
	 */
E 12
	while (bp->b_flags&B_BUSY) {
I 14
D 18
		if (bp->b_command == H_REWIND && bp->b_repcnt == 0 &&
		    (bp->b_flags&B_DONE))
E 18
I 18
		if(bp->b_repcnt == 0 && (bp->b_flags&B_DONE))
E 18
			break;
E 14
D 12
		if (bp->b_flags&B_DONE && bp->b_repcnt == 0)
			break;
E 12
E 11
		bp->b_flags |= B_WANTED;
		sleep((caddr_t)bp, PRIBIO);
	}
I 11
D 12
	bp->b_flags = B_BUSY;
E 12
I 12
	bp->b_flags = B_BUSY|B_READ;
E 12
E 11
D 2
	VOID spl0();
E 2
I 2
D 27
	(void) spl0();
E 27
I 27
	splx(s);
E 27
E 2
	bp->b_dev = dev;
D 11
	bp->b_resid = com;
E 11
I 11
	bp->b_command = com;
	bp->b_repcnt = count;
E 11
	bp->b_blkno = 0;
D 11
	bp->b_flags = B_BUSY|B_READ;
E 11
	htstrategy(bp);
I 11
	if (count == 0)
		return;
E 11
	iowait(bp);
D 11
	if(bp->b_flags&B_WANTED)
E 11
I 11
	if (bp->b_flags&B_WANTED)
E 11
		wakeup((caddr_t)bp);
D 11
	bp->b_flags = 0;
	return(bp->b_resid);
E 11
I 11
	bp->b_flags &= B_ERROR;
E 11
}

htstrategy(bp)
D 11
register struct buf *bp;
E 11
I 11
	register struct buf *bp;
E 11
{
D 11
	register daddr_t *p;
E 11
I 11
D 15
	register int unit = HTUNIT(bp->b_dev);
D 12
	register struct mba_info *mi;
E 12
I 12
D 14
	register struct mba_info *mi = htinfo[unit];
E 14
I 14
	register struct mba_device *mi = htinfo[unit];
E 15
I 15
	register struct mba_device *mi = htinfo[HTUNIT(bp->b_dev)];
E 15
E 14
E 12
	register struct buf *dp;
I 27
	register int s;
E 27
D 13
	register struct ht_softc *sc = &ht_softc[unit];
E 13
E 11

D 11
	if(bp != &chtbuf) {
		p = &h_nxrec[minor(bp->b_dev)&03];
		if(dbtofsb(bp->b_blkno) > *p) {
			bp->b_flags |= B_ERROR;
			bp->b_error = ENXIO;
			iodone(bp);
			return;
		}
		if(dbtofsb(bp->b_blkno) == *p && bp->b_flags&B_READ) {
			bp->b_resid = bp->b_bcount;
			clrbuf(bp);
			iodone(bp);
			return;
		}
		if ((bp->b_flags&B_READ)==0) {
			*p = dbtofsb(bp->b_blkno) + 1;
			h_flags[minor(bp->b_dev)&03] |=  H_WRITTEN;
		}
	}
E 11
	bp->av_forw = NULL;
I 11
	dp = &mi->mi_tab;
E 11
D 2
	VOID spl5();
E 2
I 2
D 27
	(void) spl5();
E 27
I 27
	s = spl5();
E 27
E 2
D 11
	if (httab.b_actf == NULL)
		httab.b_actf = bp;
E 11
I 11
	if (dp->b_actf == NULL)
		dp->b_actf = bp;
E 11
	else
D 11
		httab.b_actl->av_forw = bp;
	httab.b_actl = bp;
	if (httab.b_active==0)
		htstart();
E 11
I 11
		dp->b_actl->av_forw = bp;
	dp->b_actl = bp;
	if (dp->b_active == 0)
		mbustart(mi);
E 11
D 2
	VOID spl0();
E 2
I 2
D 27
	(void) spl0();
E 27
I 27
	splx(s);
E 27
E 2
}

D 11
htstart()
E 11
I 11
htustart(mi)
D 14
	register struct mba_info *mi;
E 14
I 14
	register struct mba_device *mi;
E 14
E 11
{
D 11
	register struct buf *bp;
	register unit, den;
E 11
I 11
	register struct htdevice *htaddr =
	    (struct htdevice *)mi->mi_drv;
	register struct buf *bp = mi->mi_tab.b_actf;
D 14
	int unit = HTUNIT(bp->b_dev);
E 14
I 14
D 15
	int unit = TUUNIT(bp->b_dev);
E 14
	register struct ht_softc *sc = &ht_softc[unit];
E 15
I 15
	register struct tu_softc *sc = &tu_softc[TUUNIT(bp->b_dev)];
E 15
E 11
	daddr_t blkno;
I 5
D 11
	register struct device *htp = mbadev(HTMBA,0);
E 11
E 5

D 11
    loop:
	if ((bp = httab.b_actf) == NULL)
		return;
	unit = minor(bp->b_dev);
	den = P800 | (unit&03);
	if(unit >= 8)
		den = P1600 | (unit&03);
D 5
	if((HTADDR->httc&03777) != den)
		HTADDR->httc = den;
E 5
I 5
	if((htp->httc&03777) != den)
		htp->httc = den;
E 5
	unit &= 03;
	blkno = h_blkno[unit];
	if (bp == &chtbuf) {
		if (bp->b_resid==NOP) {
D 5
			bp->b_resid = HTADDR->htds & 0xffff;
E 5
I 5
			bp->b_resid = htp->htds & 0xffff;
E 11
I 11
	htaddr->httc = sc->sc_dens;
I 44
#ifdef	notdef
	/* unneeded, may hang controller */
E 44
I 18
D 19
	if (bp == &chtbuf[HTUNIT(bp->b_dev)] && bp->b_command == H_SENSE) {
E 19
I 19
	if (bp == &chtbuf[HTUNIT(bp->b_dev)] && bp->b_command == HT_SENSE) {
E 19
		htaddr->htcs1 = HT_SENSE|HT_GO;
		mbclrattn(mi);
	}
I 44
#endif
E 44
E 18
	sc->sc_dsreg = htaddr->htds;
	sc->sc_erreg = htaddr->hter;
	sc->sc_resid = htaddr->htfc;
	sc->sc_flags &= ~(H_WRITTEN|H_REWIND);
	if ((htaddr->htdt & HTDT_SPR) == 0 || (htaddr->htds & HTDS_MOL) == 0)
		if (sc->sc_openf > 0)
			sc->sc_openf = -1;
	if (sc->sc_openf < 0) {
		bp->b_flags |= B_ERROR;
		return (MBU_NEXT);
	}
D 15
	if (bp != &chtbuf[unit]) {
E 15
I 15
	if (bp != &chtbuf[HTUNIT(bp->b_dev)]) {
E 15
D 29
		if (dbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 29
I 29
D 57
		if (bdbtofsb(bp->b_blkno) > sc->sc_nxrec) {
E 29
			bp->b_flags |= B_ERROR;
			bp->b_error = ENXIO;
E 11
E 5
D 13
			goto next;
E 13
I 13
			return (MBU_NEXT);
E 57
I 57
		/* transfer: check positioning */
		if (bp->b_flags & B_RAW) {
			/* raw transfer: record position for retry */
			if (mi->mi_tab.b_errcnt == 0) {
				sc->sc_blkno = bdbtofsb(bp->b_blkno);
				sc->sc_nxrec = sc->sc_blkno + 1;
			}
		} else {
			if (bdbtofsb(bp->b_blkno) > sc->sc_nxrec) {
				bp->b_flags |= B_ERROR;
				bp->b_error = ENXIO;
				return (MBU_NEXT);
			}
			if (bdbtofsb(bp->b_blkno) == sc->sc_nxrec &&
			    bp->b_flags&B_READ) {
				bp->b_resid = bp->b_bcount;
				clrbuf(bp);
				return (MBU_NEXT);
			}
			if ((bp->b_flags&B_READ)==0)
				sc->sc_nxrec = bdbtofsb(bp->b_blkno) + 1;
E 57
E 13
I 11
D 15
		} else if (dbtofsb(bp->b_blkno) == sc->sc_nxrec &&
E 15
I 15
		}
D 29
		if (dbtofsb(bp->b_blkno) == sc->sc_nxrec &&
E 29
I 29
D 57
		if (bdbtofsb(bp->b_blkno) == sc->sc_nxrec &&
E 29
E 15
		    bp->b_flags&B_READ) {
			bp->b_resid = bp->b_bcount;
			clrbuf(bp);
D 13
			goto next;
E 13
I 13
			return (MBU_NEXT);
E 13
D 15
		} else if ((bp->b_flags&B_READ)==0)
E 15
I 15
		}
		if ((bp->b_flags&B_READ)==0)
E 15
D 29
			sc->sc_nxrec = dbtofsb(bp->b_blkno) + 1;
E 29
I 29
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) + 1;
E 57
E 29
	} else {
D 12
		if (bp->b_command == HT_SENSE)
E 12
I 12
D 13
		if (bp->b_command == HT_SENSE) {
			T(10)("sense complete\n");
E 13
I 13
		if (bp->b_command == HT_SENSE)
E 13
E 12
			return (MBU_NEXT);
I 12
D 13
		}
E 13
E 12
		if (bp->b_command == HT_REW)
			sc->sc_flags |= H_REWIND;
		else
			htaddr->htfc = -bp->b_bcount;
		htaddr->htcs1 = bp->b_command|HT_GO;
I 12
D 13
		T(10)("started cmd %d\n", bp->b_command);
E 13
E 12
		return (MBU_STARTED);
	}
D 29
	if ((blkno = sc->sc_blkno) == dbtofsb(bp->b_blkno)) {
E 29
I 29
	if ((blkno = sc->sc_blkno) == bdbtofsb(bp->b_blkno)) {
E 29
		htaddr->htfc = -bp->b_bcount;
		if ((bp->b_flags&B_READ) == 0) {
D 15
			if (mi->mi_tab.b_errcnt)
				if (sc->sc_flags & H_ERASED)
					sc->sc_flags &= ~H_ERASED;
				else {
E 15
I 15
			if (mi->mi_tab.b_errcnt) {
				if ((sc->sc_flags & H_ERASED) == 0) {
E 15
					sc->sc_flags |= H_ERASED;
					htaddr->htcs1 = HT_ERASE | HT_GO;
					return (MBU_STARTED);
				}
I 15
				sc->sc_flags &= ~H_ERASED;
			}
E 15
			if (htaddr->htds & HTDS_EOT) {
				bp->b_resid = bp->b_bcount;
I 28
				bp->b_flags |= B_ERROR;
E 28
				return (MBU_NEXT);
			}
E 11
		}
D 11
		httab.b_active = SCOM;
D 5
		HTADDR->htfc = 0;
		HTADDR->htcs1 = bp->b_resid|GO;
E 5
I 5
		htp->htfc = 0;
		htp->htcs1 = bp->b_resid|GO;
E 5
		return;
E 11
I 11
		return (MBU_DODATA);
E 11
	}
D 11
	if (h_openf[unit] < 0 || dbtofsb(bp->b_blkno) > h_nxrec[unit])
		goto abort;
	if (blkno == dbtofsb(bp->b_blkno)) {
		httab.b_active = SIO;
D 5
		HTADDR->htfc = -bp->b_bcount;
		mbastart(bp, (int *)HTADDR);
E 5
I 5
		htp->htfc = -bp->b_bcount;
		mbastart(bp, (int *)htp);
E 11
I 11
D 29
	if (blkno < dbtofsb(bp->b_blkno)) {
		htaddr->htfc = blkno - dbtofsb(bp->b_blkno);
E 29
I 29
	if (blkno < bdbtofsb(bp->b_blkno)) {
		htaddr->htfc = blkno - bdbtofsb(bp->b_blkno);
E 29
I 12
D 13
		T(10)("spacing fwd %d\n", MASKREG(htaddr)->htfc);
E 13
E 12
		htaddr->htcs1 = HT_SFORW|HT_GO;
E 11
E 5
	} else {
D 11
		if (blkno < dbtofsb(bp->b_blkno)) {
			httab.b_active = SSFOR;
D 5
			HTADDR->htfc = blkno - dbtofsb(bp->b_blkno);
			HTADDR->htcs1 = SFORW|GO;
E 5
I 5
			htp->htfc = blkno - dbtofsb(bp->b_blkno);
			htp->htcs1 = SFORW|GO;
E 5
		} else {
			httab.b_active = SSREV;
D 5
			HTADDR->htfc = dbtofsb(bp->b_blkno) - blkno;
			HTADDR->htcs1 = SREV|GO;
E 5
I 5
			htp->htfc = dbtofsb(bp->b_blkno) - blkno;
			htp->htcs1 = SREV|GO;
E 5
		}
E 11
I 11
D 29
		htaddr->htfc = dbtofsb(bp->b_blkno) - blkno;
E 29
I 29
		htaddr->htfc = bdbtofsb(bp->b_blkno) - blkno;
E 29
I 12
D 13
		T(10)("spacing back %d\n", MASKREG(htaddr)->htfc);
E 13
E 12
		htaddr->htcs1 = HT_SREV|HT_GO;
E 11
	}
D 11
	return;

    abort:
	bp->b_flags |= B_ERROR;

    next:
	httab.b_actf = bp->av_forw;
E 11
I 11
	return (MBU_STARTED);
D 13
next:
E 11
	iodone(bp);
D 11
	goto loop;
E 11
I 11
	return (MBU_NEXT);
E 13
E 11
}

I 11
D 15
/*
 * data transfer interrupt - must be read or write
 */
E 11
/*ARGSUSED*/
D 11
htintr(mbastat, as)
E 11
I 11
htdtint(mi, mbasr)
E 15
I 15
htdtint(mi, mbsr)
E 15
D 14
	register struct mba_info *mi;
E 14
I 14
	register struct mba_device *mi;
E 14
D 15
	int mbasr;
E 15
I 15
	int mbsr;
E 15
E 11
{
D 11
	register struct buf *bp;
	register int unit, state;
	int err;
I 5
	register struct device *htp = mbadev(HTMBA,0);
E 11
I 11
	register struct htdevice *htaddr = (struct htdevice *)mi->mi_drv;
	register struct buf *bp = mi->mi_tab.b_actf;
D 15
	register struct ht_softc *sc;
E 15
I 15
	register struct tu_softc *sc;
E 15
D 13
	int ds, er;
E 13
I 13
	int ds, er, mbs;
E 13
E 11
E 5

D 11
	if ((bp = httab.b_actf)==NULL)
E 11
I 11
D 12
	if (bp == NULL)
E 11
		return;
E 12
D 11
	unit = minor(bp->b_dev) & 03;
	state = httab.b_active;
	httab.b_active = 0;
D 5
	if (HTADDR->htds&(ERR|EOT|TM) || mbastat & MBAEBITS) {
		err = HTADDR->hter & 0xffff;
E 5
I 5
	if (htp->htds&(ERR|EOT|TM) || mbastat & MBAEBITS) {
		err = htp->hter & 0xffff;
E 5
		if ((mbastat & MBAEBITS) || (err&HARD))
			state = 0;
		if (bp == &rhtbuf)
			err &= ~FCE;
D 5
		if ((bp->b_flags&B_READ) && (HTADDR->htds&PES))
E 5
I 5
		if ((bp->b_flags&B_READ) && (htp->htds&PES))
E 5
			err &= ~(CS|COR);
D 5
		if(HTADDR->htds&EOT || (HTADDR->htds&MOL)==0) {
E 5
I 5
		if(htp->htds&EOT || (htp->htds&MOL)==0) {
E 5
			if(h_openf[unit])
				h_openf[unit] = -1;
		}
D 5
		else if(HTADDR->htds&TM) {
			HTADDR->htfc = 0;
E 5
I 5
		else if(htp->htds&TM) {
			htp->htfc = 0;
E 5
			h_nxrec[unit] = dbtofsb(bp->b_blkno);
			state = SOK;
		}
		else if(state && err == 0)
			state = SOK;
		if(httab.b_errcnt > 4)
D 5
			deverror(bp, HTADDR->hter, mbastat);
		((struct mba_regs *)MBA1)->mba_cr &= ~MBAIE;
		HTADDR->htcs1 = DCLR|GO;
		((struct mba_regs *)MBA1)->mba_cr |= MBAIE;
E 5
I 5
			deverror(bp, htp->hter, mbastat);
		HTMBA->mba_cr &= ~MBAIE;
		htp->htcs1 = DCLR|GO;
		HTMBA->mba_cr |= MBAIE;
E 5
		if (state==SIO && ++httab.b_errcnt < 10) {
			httab.b_active = SRETRY;
			h_blkno[unit]++;
D 5
			HTADDR->htfc = -1;
			HTADDR->htcs1 = SREV|GO;
E 5
I 5
			htp->htfc = -1;
			htp->htcs1 = SREV|GO;
E 5
			return;
		}
		if (state!=SOK) {
E 11
I 11
D 14
	sc = &ht_softc[HTUNIT(bp->b_dev)];
E 14
I 14
D 15
	sc = &ht_softc[TUUNIT(bp->b_dev)];
E 15
I 15
	sc = &tu_softc[TUUNIT(bp->b_dev)];
E 15
E 14
	ds = sc->sc_dsreg = MASKREG(htaddr->htds);
	er = sc->sc_erreg = MASKREG(htaddr->hter);
	sc->sc_resid = MASKREG(htaddr->htfc);
I 13
D 15
	mbs = mbasr;
E 15
I 15
	mbs = mbsr;
E 15
E 13
	sc->sc_blkno++;
	if((bp->b_flags & B_READ) == 0)
		sc->sc_flags |= H_WRITTEN;
D 15
	if ((ds&(HTDS_ERR|HTDS_MOL)) != HTDS_MOL ||
D 13
	    mbasr & MBAEBITS) {
E 13
I 13
	    mbs & MBAEBITS) {
E 15
I 15
	if ((ds&(HTDS_ERR|HTDS_MOL)) != HTDS_MOL || mbs & MBSR_EBITS) {
E 15
E 13
		htaddr->htcs1 = HT_DCLR|HT_GO;
D 13
		if (bp == &rhtbuf[HTUNIT(bp->b_dev)])
E 13
I 13
		mbclrattn(mi);
D 57
		if (bp == &rhtbuf[HTUNIT(bp->b_dev)]) {
E 57
I 57
		if (bp->b_flags & B_RAW) {
E 57
E 13
			er &= ~HTER_FCE;
I 13
D 15
			mbs &= ~(MBS_DTABT|MBS_MBEXC);
E 15
I 15
			mbs &= ~(MBSR_DTABT|MBSR_MBEXC);
E 15
D 18
		}
E 18
I 18
D 25
		} else
E 25
I 25
		}
E 25
E 18
E 13
		if (bp->b_flags & B_READ && ds & HTDS_PES)
			er &= ~(HTER_CSITM|HTER_CORCRC);
D 15
		if (er&HTER_HARD ||
D 13
		    mbasr&MBAEBITS || (ds&HTDS_MOL) == 0 ||
		    sc->sc_erreg && ++mi->mi_tab.b_errcnt >= 7) {
E 13
I 13
		    mbs&MBAEBITS || (ds&HTDS_MOL) == 0 ||
E 15
I 15
		if (er&HTER_HARD || mbs&MBSR_EBITS || (ds&HTDS_MOL) == 0 ||
E 15
		    er && ++mi->mi_tab.b_errcnt >= 7) {
E 13
			if ((ds & HTDS_MOL) == 0 && sc->sc_openf > 0)
				sc->sc_openf = -1;
I 18
			if ((er&HTER_HARD) == HTER_FCE &&
			    (mbs&MBSR_EBITS) == (MBSR_DTABT|MBSR_MBEXC) &&
			    (ds&HTDS_MOL))
				goto noprint;
E 18
D 14
			printf("ht%d: hard error bn%d mbasr=%b er=%b\n",
			    HTUNIT(bp->b_dev), bp->b_blkno,
E 14
I 14
D 15
			printf("tu%d: hard error bn%d mbasr=%b er=%b\n",
E 15
I 15
D 21
			printf("tu%d: hard error bn%d mbsr=%b er=%b\n",
E 21
I 21
D 46
			printf("tu%d: hard error bn%d mbsr=%b er=%b ds=%b\n",
E 46
I 46
			tprintf(sc->sc_ttyp, "tu%d: hard error bn%d mbsr=%b er=%b ds=%b\n",
E 46
E 21
E 15
			    TUUNIT(bp->b_dev), bp->b_blkno,
E 14
D 15
			    mbasr, mbasr_bits,
E 15
I 15
			    mbsr, mbsr_bits,
E 15
D 21
			    MASKREG(htaddr->hter), HTER_BITS);
E 21
I 21
			    sc->sc_erreg, hter_bits,
			    sc->sc_dsreg, htds_bits);
E 21
I 18
noprint:
E 18
E 11
			bp->b_flags |= B_ERROR;
D 11
			state = SIO;
E 11
I 11
			return (MBD_DONE);
E 11
		}
D 5
	} else if (HTADDR->htcs1 < 0) {	/* SC */
		if(HTADDR->htds & ERR) {
			((struct mba_regs *)MBA1)->mba_cr &= ~MBAIE;
			HTADDR->htcs1 = DCLR|GO;
			((struct mba_regs *)MBA1)->mba_cr |= MBAIE;
E 5
I 5
D 11
	} else if (htp->htcs1 < 0) {	/* SC */
		if(htp->htds & ERR) {
			HTMBA->mba_cr &= ~MBAIE;
			htp->htcs1 = DCLR|GO;
			HTMBA->mba_cr |= MBAIE;
E 5
		}
E 11
I 11
		if (er)
			return (MBD_RETRY);
E 11
	}
D 11
	switch(state) {
	case SIO:
	case SOK:
		h_blkno[unit]++;
E 11
I 11
	bp->b_resid = 0;
I 52
	sc->sc_blks++;
	if (mi->mi_tab.b_errcnt)
		sc->sc_softerrs++;
E 52
	if (bp->b_flags & B_READ)
		if (ds&HTDS_TM) {		/* must be a read, right? */
			bp->b_resid = bp->b_bcount;
D 29
			sc->sc_nxrec = dbtofsb(bp->b_blkno);
E 29
I 29
			sc->sc_nxrec = bdbtofsb(bp->b_blkno);
E 29
		} else if(bp->b_bcount > MASKREG(htaddr->htfc))
			bp->b_resid = bp->b_bcount - MASKREG(htaddr->htfc);
	return (MBD_DONE);
}
E 11

D 11
	case SCOM:
		httab.b_errcnt = 0;
		httab.b_actf = bp->av_forw;
D 5
		bp->b_resid = - (HTADDR->htfc & 0xffff);
E 5
I 5
		bp->b_resid = - (htp->htfc & 0xffff);
E 5
		if (bp->b_flags & B_READ)
			bp->b_resid += bp->b_bcount;
		iodone(bp);
		break;
E 11
I 11
D 15
/*
 * non-data-transfer interrupt
 */
E 15
htndtint(mi)
D 14
	register struct mba_info *mi;
E 14
I 14
	register struct mba_device *mi;
E 14
{
	register struct htdevice *htaddr = (struct htdevice *)mi->mi_drv;
	register struct buf *bp = mi->mi_tab.b_actf;
D 15
	register struct ht_softc *sc;
E 15
I 15
	register struct tu_softc *sc;
E 15
	int er, ds, fc;
E 11

D 11
	case SRETRY:
		if((bp->b_flags&B_READ)==0) {
			httab.b_active = SSFOR;
D 5
			HTADDR->htcs1 = ERASE|GO;
E 5
I 5
			htp->htcs1 = ERASE|GO;
E 5
			return;
		}

	case SSFOR:
	case SSREV:
I 3
#define blk dbtofsb(bp->b_blkno)
E 3
D 5
		if(HTADDR->htds & TM) {
E 5
I 5
		if(htp->htds & TM) {
E 5
			if(state == SSREV) {
D 3
				h_nxrec[unit] = dbtofsb(bp->b_blkno) - (HTADDR->htfc&0xffff);
E 3
I 3
D 5
				h_nxrec[unit] = blk - (HTADDR->htfc&0xffff);
E 5
I 5
				h_nxrec[unit] = blk - (htp->htfc&0xffff);
E 5
E 3
				h_blkno[unit] = h_nxrec[unit];
			} else {
D 3
				h_nxrec[unit] = dbtofsb(bp->b_blkno) + (HTADDR->htfc & 0xffff) - 1;
				h_blkno[unit] = dbtofsb(bp->b_blkno) + (HTADDR->htfc & 0xffff);
E 3
I 3
D 5
				h_nxrec[unit] = blk + (HTADDR->htfc&0xffff) - 1;
				h_blkno[unit] = blk + (HTADDR->htfc & 0xffff);
E 5
I 5
				h_nxrec[unit] = blk + (htp->htfc&0xffff) - 1;
				h_blkno[unit] = blk + (htp->htfc & 0xffff);
E 5
E 3
			}
		} else
D 3
			h_blkno[unit] = dbtofsb(bp->b_blkno);
E 3
I 3
			h_blkno[unit] = blk;
E 3
		break;
I 9
#undef blk
E 9

	default:
E 11
I 11
D 12
	if (bp == NULL)
E 11
		return;
E 12
I 11
D 14
	sc = &ht_softc[HTUNIT(bp->b_dev)];
E 14
I 14
D 15
	if (bp == 0)
		return (MBN_SKIP);
	sc = &ht_softc[TUUNIT(bp->b_dev)];
E 14
	ds = sc->sc_dsreg = MASKREG(htaddr->htds);
	er = sc->sc_erreg = MASKREG(htaddr->hter);
D 13
	sc->sc_resid = MASKREG(htaddr->htfc);
	if (sc->sc_erreg)
E 13
I 13
	fc = sc->sc_resid = MASKREG(htaddr->htfc);
	if (sc->sc_erreg) {
E 15
I 15
	ds = MASKREG(htaddr->htds);
	er = MASKREG(htaddr->hter);
	fc = MASKREG(htaddr->htfc);
	if (er) {
E 15
E 13
		htaddr->htcs1 = HT_DCLR|HT_GO;
I 13
		mbclrattn(mi);
	}
E 13
D 14
	if (bp == &chtbuf[HTUNIT(bp->b_dev)]) {
E 14
I 14
D 15
	if (sc->sc_flags&H_REWIND) {
		sc->sc_flags &= ~H_REWIND;
		return (MBN_CONT);
	}
	if (bp == &chtbuf[TUUNIT(bp->b_dev)]) {
E 14
		if (bp->b_command == HT_REWOFFL)
E 15
I 15
	if (bp == 0)
		return (MBN_SKIP);
	sc = &tu_softc[TUUNIT(bp->b_dev)];
	sc->sc_dsreg = ds;
	sc->sc_erreg = er;
	sc->sc_resid = fc;
	if (bp == &chtbuf[HTUNIT(bp->b_dev)]) {
D 50
		switch (bp->b_command) {
E 50
I 50
		switch ((int)bp->b_command) {
E 50
		case HT_REWOFFL:
E 15
			/* offline is on purpose; don't do anything special */
			ds |= HTDS_MOL;	
D 15
		else if (bp->b_resid == HT_SREV &&
		    er == (HTER_NEF|HTER_FCE) &&
		    ds&HTDS_BOT && bp->b_bcount == INF)
			er &= ~HTER_NEF;
E 15
I 15
			break;
		case HT_SREV:
			/* if backspace file hit bot, its not an error */
		        if (er == (HTER_NEF|HTER_FCE) && ds&HTDS_BOT &&
			    bp->b_repcnt == INF)
				er &= ~HTER_NEF;
			break;
		}
E 15
		er &= ~HTER_FCE;
		if (er == 0)
			ds &= ~HTDS_ERR;
E 11
	}
D 11
	htstart();
E 11
I 11
	if ((ds & (HTDS_ERR|HTDS_MOL)) != HTDS_MOL) {
		if ((ds & HTDS_MOL) == 0 && sc->sc_openf > 0)
			sc->sc_openf = -1;
D 14
		printf("ht%d: hard error bn%d er=%b ds=%b\n",
		    HTUNIT(bp->b_dev), bp->b_blkno,
E 14
I 14
D 18
		printf("tu%d: hard error bn%d er=%b ds=%b\n",
E 18
I 18
D 21
		printf("tu%d: hard error bn%d er=%b\n",
E 21
I 21
D 46
		printf("tu%d: hard error bn%d er=%b ds=%b\n",
E 46
I 46
		tprintf(sc->sc_ttyp, "tu%d: hard error bn%d er=%b ds=%b\n",
E 46
E 21
E 18
		    TUUNIT(bp->b_dev), bp->b_blkno,
E 14
D 18
		    sc->sc_erreg, HTER_BITS, sc->sc_dsreg, HTDS_BITS);
E 18
I 18
D 21
		    sc->sc_erreg, HTER_BITS);
E 21
I 21
		    sc->sc_erreg, hter_bits, sc->sc_dsreg, htds_bits);
E 21
E 18
		bp->b_flags |= B_ERROR;
		return (MBN_DONE);
	}
D 14
	if (bp == &chtbuf[HTUNIT(bp->b_dev)]) {
E 14
I 14
D 15
	if (bp == &chtbuf[TUUNIT(bp->b_dev)]) {
E 15
I 15
	if (bp == &chtbuf[HTUNIT(bp->b_dev)]) {
E 15
E 14
		if (sc->sc_flags & H_REWIND)
			return (ds & HTDS_BOT ? MBN_DONE : MBN_RETRY);
		bp->b_resid = -sc->sc_resid;
		return (MBN_DONE);
	}
	if (ds & HTDS_TM)
D 15
		if (sc->sc_blkno > dbtofsb(bp->b_blkno)) {/* reversing */
E 15
I 15
D 29
		if (sc->sc_blkno > dbtofsb(bp->b_blkno)) {
E 15
			sc->sc_nxrec = dbtofsb(bp->b_blkno) - fc;
E 29
I 29
		if (sc->sc_blkno > bdbtofsb(bp->b_blkno)) {
			sc->sc_nxrec = bdbtofsb(bp->b_blkno) - fc;
E 29
			sc->sc_blkno = sc->sc_nxrec;
D 15
		} else {			/* spacing forward */
E 15
I 15
		} else {
E 15
D 29
			sc->sc_blkno = dbtofsb(bp->b_blkno) + fc;
E 29
I 29
			sc->sc_blkno = bdbtofsb(bp->b_blkno) + fc;
E 29
			sc->sc_nxrec = sc->sc_blkno - 1;
		}
	else
D 29
		sc->sc_blkno = dbtofsb(bp->b_blkno);
E 29
I 29
		sc->sc_blkno = bdbtofsb(bp->b_blkno);
E 29
	return (MBN_RETRY);
E 11
D 57
}

D 32
htread(dev)
E 32
I 32
htread(dev, uio)
E 32
I 11
	dev_t dev;
I 32
	struct uio *uio;
E 32
E 11
{
I 34
	int errno;
E 34
I 11

E 11
D 32
	htphys(dev);
E 32
I 32
D 34
	u.u_error = htphys(dev, uio);
E 32
D 11
	physio(htstrategy, &rhtbuf, dev, B_READ, minphys);
E 11
I 11
	if (u.u_error)
		return;
D 32
	physio(htstrategy, &rhtbuf[HTUNIT(dev)], dev, B_READ, minphys);
E 32
I 32
	physio(htstrategy, &rhtbuf[HTUNIT(dev)], dev, B_READ, minphys, uio);
E 34
I 34
	errno = htphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(htstrategy, &rhtbuf[HTUNIT(dev)], dev, B_READ, minphys, uio));
E 34
E 32
E 11
}

D 37
htwrite(dev)
E 37
I 37
htwrite(dev, uio)
	dev_t dev;
D 39
	struct uio uio;
E 39
I 39
	struct uio *uio;
E 39
E 37
{
I 34
	int errno;
E 34
I 11

E 11
D 32
	htphys(dev);
E 32
I 32
D 33
	htphys(dev, 0);
E 33
I 33
D 34
	u.u_error = htphys(dev, uio);
E 33
E 32
D 11
	physio(htstrategy, &rhtbuf, dev, B_WRITE, minphys);
E 11
I 11
	if (u.u_error)
		return;
D 32
	physio(htstrategy, &rhtbuf[HTUNIT(dev)], dev, B_WRITE, minphys);
E 32
I 32
D 33
	physio(htstrategy, &rhtbuf[HTUNIT(dev)], dev, B_WRITE, minphys, 0);
E 33
I 33
	physio(htstrategy, &rhtbuf[HTUNIT(dev)], dev, B_WRITE, minphys, uio);
E 34
I 34
	errno = htphys(dev, uio);
	if (errno)
		return (errno);
	return (physio(htstrategy, &rhtbuf[HTUNIT(dev)], dev, B_WRITE, minphys, uio));
E 34
E 33
E 32
E 11
}

D 32
htphys(dev)
E 32
I 32
htphys(dev, uio)
E 32
I 11
	dev_t dev;
I 32
	struct uio *uio;
E 32
E 11
{
D 11
	register unit;
E 11
I 11
D 15
	register int unit;
	register struct ht_softc *sc;
E 15
I 15
	register int htunit;
I 39
D 42
/*###439 [lint] htphys arg. 2 used inconsistently ht.c(439) :: ht.c(430)%%%*/
E 42
E 39
	register struct tu_softc *sc;
	register struct mba_device *mi;
E 15
E 11
	daddr_t a;

D 11
	unit = minor(dev) & 03;
D 6
	if(unit < NUNIT) {
E 6
I 6
	if(unit < NHT) {
E 6
		a = u.u_offset >> 9;
		h_blkno[unit] = dbtofsb(a);
		h_nxrec[unit] = dbtofsb(a)+1;
E 11
I 11
D 15
	unit = HTUNIT(dev);
	if (unit >= NHT) {
E 15
I 15
	htunit = HTUNIT(dev);
D 33
	if (htunit >= NHT || (mi = htinfo[htunit]) == 0 || mi->mi_alive == 0) {
E 15
		u.u_error = ENXIO;
E 33
I 33
	if (htunit >= NHT || (mi = htinfo[htunit]) == 0 || mi->mi_alive == 0)
E 33
D 32
		return;
E 32
I 32
		return (ENXIO);
E 32
E 11
D 33
	}
I 11
D 32
	a = u.u_offset >> 9;
E 32
I 32
	if (uio)
		a = uio->uio_offset >> 9;
	else
		a = u.u_offset >> 9;
E 33
I 33
	a = uio->uio_offset >> 9;
E 33
E 32
D 15
	sc = &ht_softc[unit];
E 15
I 15
	sc = &tu_softc[TUUNIT(dev)];
E 15
D 29
	sc->sc_blkno = dbtofsb(a);
	sc->sc_nxrec = dbtofsb(a)+1;
E 29
I 29
	sc->sc_blkno = bdbtofsb(a);
	sc->sc_nxrec = bdbtofsb(a)+1;
I 32
	return (0);
E 57
E 32
E 29
E 11
I 9
}

D 11
#define	HTADDR	((struct device *)(HTPHYSMBA + 0x400))
#define	HTMAP ((struct pte *) (HTPHYSMBA + 0x800))
E 11
I 11
/*ARGSUSED*/
D 31
htioctl(dev, cmd, addr, flag)
E 31
I 31
htioctl(dev, cmd, data, flag)
E 31
	dev_t dev;
	int cmd;
D 31
	caddr_t addr;
E 31
I 31
	caddr_t data;
E 31
	int flag;
{
D 15
	register unit = HTUNIT(dev);
	register struct ht_softc *sc = &ht_softc[unit];
	register struct buf *bp = &chtbuf[unit];
E 15
I 15
	register struct tu_softc *sc = &tu_softc[TUUNIT(dev)];
	register struct buf *bp = &chtbuf[HTUNIT(dev)];
E 15
	register callcount;
	int fcount;
D 31
	struct mtop mtop;
	struct mtget mtget;
E 31
I 31
	struct mtop *mtop;
	struct mtget *mtget;
E 31
	/* we depend of the values and order of the MT codes here */
	static htops[] =
   {HT_WEOF,HT_SFORW,HT_SREV,HT_SFORW,HT_SREV,HT_REW,HT_REWOFFL,HT_SENSE};
E 11

I 11
	switch (cmd) {
D 31
		case MTIOCTOP:	/* tape operation */
		if (copyin((caddr_t)addr, (caddr_t)&mtop, sizeof(mtop))) {
			u.u_error = EFAULT;
			return;
		}
		switch(mtop.mt_op) {
E 31
I 31

	case MTIOCTOP:	/* tape operation */
		mtop = (struct mtop *)data;
		switch (mtop->mt_op) {

E 31
		case MTWEOF:
D 31
			callcount = mtop.mt_count;
E 31
I 31
			callcount = mtop->mt_count;
E 31
			fcount = 1;
			break;
I 31

E 31
		case MTFSF: case MTBSF:
D 31
			callcount = mtop.mt_count;
E 31
I 31
			callcount = mtop->mt_count;
E 31
			fcount = INF;
			break;
I 31

E 31
		case MTFSR: case MTBSR:
			callcount = 1;
D 31
			fcount = mtop.mt_count;
E 31
I 31
			fcount = mtop->mt_count;
E 31
			break;
I 31

E 31
		case MTREW: case MTOFFL:
			callcount = 1;
			fcount = 1;
			break;
I 31

E 31
		default:
D 36
			u.u_error = ENXIO;
			return;
E 36
I 36
			return (ENXIO);
E 36
		}
D 36
		if (callcount <= 0 || fcount <= 0) {
			u.u_error = ENXIO;
			return;
		}
E 36
I 36
		if (callcount <= 0 || fcount <= 0)
			return (EINVAL);
E 36
		while (--callcount >= 0) {
D 31
			htcommand(dev, htops[mtop.mt_op], fcount);
			if ((mtop.mt_op == MTFSR || mtop.mt_op == MTBSR) &&
E 31
I 31
			htcommand(dev, htops[mtop->mt_op], fcount);
			if ((mtop->mt_op == MTFSR || mtop->mt_op == MTBSR) &&
E 31
D 36
			    bp->b_resid) {
				u.u_error = EIO;
				break;
			}
E 36
I 36
			    bp->b_resid)
				return (EIO);
E 36
D 15
			if ((chtbuf[HTUNIT(bp->b_dev)].b_flags&B_ERROR) ||
			    sc->sc_dsreg&HTDS_BOT)
E 15
I 15
			if ((bp->b_flags&B_ERROR) || sc->sc_dsreg&HTDS_BOT)
E 15
				break;
		}
D 36
		geterror(bp);
		return;
E 36
I 36
D 40
		geterror(bp);		/* XXX */
		return (u.u_error);	/* XXX */
E 40
I 40
		return (geterror(bp));	
E 40
E 36
I 31

E 31
	case MTIOCGET:
D 31
		mtget.mt_dsreg = sc->sc_dsreg;
		mtget.mt_erreg = sc->sc_erreg;
		mtget.mt_resid = sc->sc_resid;
I 22
		mtget.mt_type = MT_ISHT;
E 22
		if (copyout((caddr_t)&mtget, addr, sizeof(mtget)))
			u.u_error = EFAULT;
E 31
I 31
		mtget = (struct mtget *)data;
		mtget->mt_dsreg = sc->sc_dsreg;
		mtget->mt_erreg = sc->sc_erreg;
		mtget->mt_resid = sc->sc_resid;
		mtget->mt_type = MT_ISHT;
E 31
D 36
		return;
E 36
I 36
		break;
E 36
I 31

E 31
	default:
D 36
		u.u_error = ENXIO;
E 36
I 36
		return (ENXIO);
E 36
	}
I 36
	return (0);
E 36
}

E 11
#define	DBSIZE	20

D 11
twall(start, num)
	char *start;
	int num;
E 11
I 11
htdump()
E 11
{
D 11
	int blk;
E 11
I 11
D 14
	register struct mba_info *mi;
E 14
I 14
	register struct mba_device *mi;
E 14
	register struct mba_regs *mp;
	register struct htdevice *htaddr;
	int blk, num;
	int start;
E 11

D 11
	HTADDR->httc = P800;	/* set 800 bpi mode */
	HTADDR->htcs1 = DCLR | GO;
E 11
I 11
	start = 0;
	num = maxfree;
#define	phys(a,b)		((b)((int)(a)&0x7fffffff))
	if (htinfo[0] == 0)
		return (ENXIO);
D 14
	mi = phys(htinfo[0], struct mba_info *);
E 14
I 14
	mi = phys(htinfo[0], struct mba_device *);
E 14
	mp = phys(mi->mi_hd, struct mba_hd *)->mh_physmba;
D 15
#if VAX780
D 13
	mbainit(mp);
E 13
I 13
	if (cpu == VAX780)
		mbainit(mp);
#endif
E 15
I 15
D 18
	mbainit(mp);
E 18
I 18
	mp->mba_cr = MBCR_IE;
E 18
E 15
E 13
	htaddr = (struct htdevice *)&mp->mba_drv[mi->mi_drive];
	htaddr->httc = HTTC_PDP11|HTTC_1600BPI;
	htaddr->htcs1 = HT_DCLR|HT_GO;
E 11
	while (num > 0) {
		blk = num > DBSIZE ? DBSIZE : num;
D 11
		twrite(start, blk);
		start += blk*NBPG;
E 11
I 11
		htdwrite(start, blk, htaddr, mp);
		start += blk;
E 11
		num -= blk;
	}
I 11
D 18
	htwait(htaddr);
	htaddr->htcs1 = HT_REW|HT_GO;
E 18
	hteof(htaddr);
	hteof(htaddr);
I 18
	htwait(htaddr);
D 19
	if (htaddr->htcs&HTDS_ERR)
E 19
I 19
	if (htaddr->htds&HTDS_ERR)
E 19
		return (EIO);
	htaddr->htcs1 = HT_REW|HT_GO;
E 18
I 16
	return (0);
E 16
E 11
}

D 11
twrite(buf, num)
char *buf;
E 11
I 11
htdwrite(dbuf, num, htaddr, mp)
	register dbuf, num;
	register struct htdevice *htaddr;
	struct mba_regs *mp;
E 11
{
D 11
	register struct pte *hpte = HTMAP;
E 11
I 11
	register struct pte *io;
E 11
	register int i;

D 11
	twait();
	HTADDR->htfc = -(num*NBPG);
E 11
I 11
	htwait(htaddr);
	io = mp->mba_map;
E 11
	for (i = 0; i < num; i++)
D 11
		*(int *)hpte++ = (btop(buf)+i) | PG_V;
	((struct mba_regs *)PHYSMBA1)->mba_sr = -1;
	((struct mba_regs *)PHYSMBA1)->mba_bcr = -(num*NBPG);
	((struct mba_regs *)PHYSMBA1)->mba_var = 0;
	HTADDR->htcs1 = WCOM | GO;
E 11
I 11
		*(int *)io++ = dbuf++ | PG_V;
	htaddr->htfc = -(num*NBPG);
	mp->mba_sr = -1;
	mp->mba_bcr = -(num*NBPG);
	mp->mba_var = 0;
	htaddr->htcs1 = HT_WCOM|HT_GO;
E 11
}

D 11
twait()
E 11
I 11
htwait(htaddr)
	struct htdevice *htaddr;
E 11
{
	register s;

	do
D 11
		s = HTADDR->htds;
	while ((s & RDY) == 0);
E 11
I 11
		s = htaddr->htds;
	while ((s & HTDS_DRY) == 0);
E 11
}

D 11
rewind()
E 11
I 11
hteof(htaddr)
	struct htdevice *htaddr;
E 11
{

D 11
	twait();
	HTADDR->htcs1 = REW | GO;
}

teof()
{

	twait();
	HTADDR->htcs1 = WEOF | GO;
E 11
I 11
	htwait(htaddr);
	htaddr->htcs1 = HT_WEOF|HT_GO;
E 11
E 9
}
I 6
#endif
E 6
E 1
