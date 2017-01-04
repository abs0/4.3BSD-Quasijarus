h10613
s 00001/00001/00473
d D 7.1 86/06/05 01:23:40 mckusick 38 37
c 4.3BSD release version
e
s 00007/00001/00467
d D 6.3 85/06/08 14:30:27 mckusick 37 36
c Add copyright
e
s 00012/00012/00456
d D 6.2 84/08/29 20:12:14 bloom 36 35
c Change to includes.  No more ../h
e
s 00000/00000/00468
d D 6.1 83/07/29 07:30:57 sam 35 34
c 4.2 distribution
e
s 00000/00002/00468
d D 4.22 83/05/27 13:53:30 sam 34 33
c lint
e
s 00001/00000/00469
d D 4.21 83/03/10 17:16:17 sam 33 32
c must have ioctl.h before vcmd.h
e
s 00001/00000/00468
d D 4.20 83/02/10 20:15:30 sam 32 30
c hz now only in kernel.h
e
s 00002/00000/00468
d R 4.20 83/02/10 20:03:30 sam 31 30
c hz now only in kernel.h
e
s 00002/00001/00466
d D 4.19 82/12/17 12:05:56 sam 30 29
c sun merge
e
s 00009/00001/00458
d D 4.18 82/11/28 16:28:01 mckusick 29 27
c fix several botches in branch merge
e
s 00002/00001/00458
d R 4.18 82/11/27 13:48:17 mckusick 28 27
c merger cleanups
e
s 00002/00010/00457
d D 4.17 82/11/27 13:27:01 mckusick 27 23
i 26 25 24
c merge in 4.13.1.1, changes for 4.1->4.1c
e
s 00024/00025/00331
d D 4.13.1.3 82/11/27 13:13:12 mckusick 26 25
c (wnj) 82/10/17 ioctl/open return errors, not u.u_error; remove ubarelses 
c 	(it is now done in uba.c); add open routines to some disk drivers. 
c (wnj) 82/10/10 minor fixes relating to u.u_error handling. 
c (wnj) 82/10/10 header files for vax are in their place.
e
s 00020/00011/00336
d D 4.13.1.2 82/11/27 13:12:09 mckusick 25 24
c (wnj) 82/08/22 fully uio()'d. 
c (wnj) 82/08/13 changes for char dev uio'ing. 
c (sam) 82/08/01 new ioctl's. 
c (kre) 82/07/15 probe routines return size of unibus dev regs to reserve space. 
c (sam) 82/06/26 varian w/ GO bit (from lucas)
e
s 00000/00000/00347
d D 4.13.1.1 82/11/27 12:53:58 mckusick 24 20
c branch-place-holder
e
s 00036/00030/00425
d D 4.16 82/11/16 19:06:33 mckusick 23 22
c add extra (grotty) level of buffer headers; reset vatimo in vastart
e
s 00192/00121/00263
d D 4.15 82/11/16 14:21:03 mckusick 22 21
c sam's mods to use unibus manager
e
s 00048/00011/00336
d D 4.14 82/11/16 14:18:53 mckusick 21 20
c update to new varian hardware
e
s 00001/00001/00346
d D 4.13 82/05/19 15:31:42 root 20 19
c new delay (mosher)
e
s 00005/00000/00342
d D 4.12 82/04/01 18:34:54 sam 19 18
c missing select routines
e
s 00004/00000/00338
d D 4.11 81/11/18 15:52:07 wnj 18 17
c lint
e
s 00000/00002/00338
d D 4.10 81/07/08 20:31:24 root 17 16
c cosmetic change
e
s 00197/00147/00143
d D 4.9 81/03/10 16:56:55 wnj 16 15
c ht typos; mba maintain dk_busy for seeks; up minor fixes; va and vp new working versions
e
s 00001/00001/00289
d D 4.8 81/03/09 01:56:09 wnj 15 14
c %G% -> %E%
e
s 00000/00002/00290
d D 4.7 81/03/09 00:35:43 wnj 14 13
c lint
e
s 00001/00001/00291
d D 4.6 81/02/27 03:15:25 wnj 13 12
c s/HZ/hz/
e
s 00002/00002/00290
d D 4.5 80/12/30 18:51:33 wnj 12 11
c ubafree() becomes ubarelse() to fix race conditions
e
s 00002/00002/00290
d D 4.4 80/12/30 18:18:49 wnj 11 10
c fix ubafree(i), i = 0 to be UBAFREECLR(i) to avoid races
e
s 00001/00001/00291
d D 4.3 80/12/19 11:44:31 wnj 10 9
c s,../conf/,,
e
s 00001/00000/00291
d D 4.2 80/12/17 10:46:47 wnj 9 8
c set all address bits
e
s 00000/00000/00291
d D 4.1 80/11/09 16:53:12 bill 8 7
c stamp for 4bsd
e
s 00017/00016/00274
d D 3.7 80/10/19 22:16:23 bill 7 6
c ../conf/*.h
e
s 00120/00094/00170
d D 3.6 80/06/22 12:35:15 bill 6 5
c vareset
e
s 00001/00001/00263
d D 3.5 80/06/07 02:48:59 bill 5 4
c %H%->%G%
e
s 00001/00001/00263
d D 3.4 80/06/04 14:41:09 bill 4 3
c reformat
e
s 00001/00001/00263
d D 3.3 80/06/04 14:39:28 bill 3 2
c reformat
e
s 00008/00008/00256
d D 3.2 80/05/08 10:24:01 bill 2 1
c VOID=>void
e
s 00264/00000/00000
d D 3.1 80/04/09 16:04:50 bill 1 0
c date and time created 80/04/09 16:04:50 by bill
e
u
U
f b 
t
T
I 1
D 3
/*	%M%	%I%	%H%	*/
E 3
I 3
D 4
/*	va.c	3.2	5/8/80	*/
E 4
I 4
D 5
/*	%M%	%I%	%H%	*/
E 5
I 5
D 15
/*	%M%	%I%	%G%	*/
E 15
I 15
D 37
/*	%M%	%I%	%E%	*/
E 37
I 37
/*
D 38
 * Copyright (c) 1982 Regents of the University of California.
E 38
I 38
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 38
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 37
E 15
E 5
E 4
E 3

I 21
D 22
/*	va.c	4.10	81/07/08	*/

/*
 ****************************************************************
 * HISTORY:
 *	4 August 1981	Jeffrey Mogul @ Stanford
 *	- added DMAGO bit definition and use
 *	- clears word count register after failures and on close
 *	23 October 1981 Peter Eichenberger @ Stanford
 *	- added interrrupt
 ****************************************************************
 */
/*#define	DEBUG/**/
E 22
E 21
I 7
D 10
#include "../conf/va.h"
E 10
I 10
#include "va.h"
E 10
#if NVA > 0
/*
D 16
 * Benson-Varian matrix printer/plotter
 * dma interface driver
E 16
I 16
 * Varian printer plotter
E 16
 */
I 30
#include "../machine/pte.h"

E 30
E 7
D 6
#ifdef ERNIE
E 6
D 36
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/systm.h"
#include "../h/map.h"
I 33
#include "../h/ioctl.h"
E 33
D 30
#include "../h/pte.h"
E 30
D 16
#include "../h/uba.h"
E 16
I 16
D 26
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 26
E 16
#include "../h/vcmd.h"
I 25
#include "../h/uio.h"
I 32
#include "../h/kernel.h"
E 36
I 36
#include "param.h"
#include "dir.h"
#include "user.h"
#include "buf.h"
#include "systm.h"
#include "map.h"
#include "ioctl.h"
#include "vcmd.h"
#include "uio.h"
#include "kernel.h"
E 36
E 32
E 25

I 26
D 36
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 36
I 36
#include "ubareg.h"
#include "ubavar.h"
E 36

E 26
I 22
D 23
int	vadebug = 1;
E 23
I 23
int	vadebug = 0;
E 23
#define	dprintf	if(vadebug)printf

E 22
D 7
/*
D 6
 * Benson-Varian matrix printer/plotter.  Device "va", for "varian".
E 6
I 6
 * Benson-Varian matrix printer/plotter
E 6
 * dma interface driver
 */
E 7
D 6
int	vabdp = 1;	/* Used with ubasetup. */
E 6
I 6
D 16
int	vabdp = 1;
E 6

E 16
D 6
unsigned minvaph();	/* Maximum amount transferred by physio. */
E 6
I 6
unsigned minvaph();
E 6

#define	VAPRI	(PZERO-1)

D 6
struct	varegs {	/* Unibus registers provided by va. */
	unsigned short vabufaddr;	/* DMA buffer address. */
	short vawcount;			/* Negative of number of 16-bit
					   words to transfer by DMA. */
E 6
I 6
D 16
#define	ushort	unsigned short
struct	varegs {
	ushort	vaba;
	short	vawc;
E 16
I 16
struct	vadevice {
	u_short	vaba;			/* buffer address */
	short	vawc;			/* word count (2's complement) */
E 16
E 6
	union {
D 6
		short vacsrword;	/* csr addressed as a word (for R). */
E 6
I 6
D 16
		short	Vacsw;
E 6
		struct {
E 16
I 16
		short	Vacsw;		/* control status as word */
		struct {		/* control status as bytes */
E 16
D 6
			char Vacsrlo;
			char Vacsrhi;	/* High byte (command bytes go here). */
		} vacsrbytes;		/* csr addressed as bytes (for W). */
	} vacsr;			/* Control/Status Register (csr). */
E 6
I 6
			char Vacsl;
			char Vacsh;
		} vacsr;
	} vacs;
E 6
D 16
	short	vadata;
E 16
I 16
	short	vadata;			/* programmed i/o data buffer */
E 16
};

D 6
#define	vacsrhi	vacsr.vacsrbytes.Vacsrhi
#define	vacsrlo	vacsr.vacsrbytes.Vacsrlo
E 6
I 6
#define	vacsw	vacs.Vacsw
#define	vacsh	vacs.vacsr.Vacsh
#define	vacsl	vacs.vacsr.Vacsl

E 6
D 7
#define	VAADDR	((struct varegs *)(UBA0_DEV + 0164000))

E 7
D 6
/* vacsr.vacsrword bits: */
#define	ERROR		0100000		/* R	Some error has occurred */
#define NPRTIMO		01000		/* R    DMA timeout error */
#define NOTREADY	0400		/* R	Something besides NPRTIMO */
#define DONE		0200		/* R	*/
#define	IENABLE		0100		/* R/W	Interrupt enable */
#define	SUPPLIESLOW	04		/* R	*/
#define BOTOFFORM	02		/* R	*/
#define BYTEREVERSE	01		/* R/W	Reverse byte order in words */
E 6
I 6
/* vacsw bits */
D 16
#define	ERROR		0100000		/* Some error has occurred */
D 7
#define NPRTIMO		01000		/* DMA timeout error */
#define NOTREADY	0400		/* Something besides NPRTIMO */
#define DONE		0200
E 7
I 7
#define	NPRTIMO		01000		/* DMA timeout error */
#define	NOTREADY	0400		/* Something besides NPRTIMO */
#define	DONE		0200
E 7
#define	IENABLE		0100		/* Interrupt enable */
#define	SUPPLIESLOW	04
D 7
#define BOTOFFORM	02
#define BYTEREVERSE	01		/* Reverse byte order in words */
E 7
I 7
#define	BOTOFFORM	02
#define	BYTEREVERSE	01		/* Reverse byte order in words */
E 16
I 16
#define	VA_ERROR	0100000		/* some error has occurred */
#define	VA_NPRTIMO	0001000		/* DMA timeout error */
#define	VA_NOTREADY	0000400		/* something besides NPRTIMO */
#define	VA_DONE		0000200
#define	VA_IENABLE	0000100		/* interrupt enable */
I 25
#define	VA_DMAGO	0000010		/* DMA go bit */
E 25
I 21
D 22
#define	VA_DMAGO	0000010		/* DMA Go Bit */
E 22
I 22
#define	VA_DMAGO	0000010		/* DMA go bit */
E 22
E 21
#define	VA_SUPPLIESLOW	0000004
#define	VA_BOTOFFORM	0000002
#define	VA_BYTEREVERSE	0000001		/* reverse byte order in words */
E 16
E 7
E 6

I 21
D 22
char va_error[] =
  "\10\2BottomOfForm\3SuppliesLow\10Done\11NotReady\12NPRTimeout\20Error\n";

E 22
E 21
D 6
/* Command bytes sent to vacsrhi */
E 6
I 6
/* vacsh command bytes */
E 6
D 7
#define VAPLOT		0340
#define VAPRINT		0100
#define VAPRINTPLOT	0160
#define VAAUTOSTEP	0244
D 6
/* The following commands are not used in this driver: */
#define VANOAUTOSTEP	0045
#define	VAFORMFEED	0263
#define	VASLEW		0265
#define	VASTEP		0064
E 6
I 6
#define VANOAUTOSTEP	0045		/* unused */
E 7
I 7
D 16
#define	VAPLOT		0340
#define	VAPRINT		0100
#define	VAPRINTPLOT	0160
#define	VAAUTOSTEP	0244
#define	VANOAUTOSTEP	0045		/* unused */
E 7
#define	VAFORMFEED	0263		/* unused */
#define	VASLEW		0265		/* unused */
#define	VASTEP		0064		/* unused */
E 16
I 16
#define	VAPLOT		0000340
#define	VAPRINT		0000100
#define	VAPRINTPLOT	0000160
#define	VAAUTOSTEP	0000244
#define	VANOAUTOSTEP	0000045
#define	VAFORMFEED	0000263
#define	VASLEW		0000265
#define	VASTEP		0000064
E 16
E 6

D 16
struct {
D 6
	char	va_is_open;
E 6
I 6
	char	va_open;
E 6
	char	va_busy;
	int	va_state;	/* State: bits are commands in vcmd.h. */
D 6
	int	va_wcount;
E 6
I 6
	int	va_wc;
E 6
	int	va_bufp;
D 6
} vainfo;
E 6
I 6
	struct	buf *va_bp;
} va11;
E 6
int	va_ubinfo;
E 16
I 16
struct va_softc {
D 22
	char	sc_openf;
	char	sc_busy;
	int	sc_state;
	int	sc_wc;
	struct	buf *sc_bp;
	int	sc_ubinfo;
I 21
	short	sc_tocnt;
E 22
I 22
	u_char	sc_openf;		/* exclusive open flag */
	u_char	sc_iostate;		/* kind of I/O going on */
#define	VAS_IDLE	0	/* no I/O, free */
#define	VAS_PIO		1	/* programmed I/O */
#define	VAS_DMA		2	/* DMA, block pio */
#define	VAS_WANT	4	/* wakeup when iostate changes */
	short	sc_tocnt;		/* time out counter */
	short	sc_info;		/* csw passed from vaintr */
	int	sc_state;		/* print/plot state of device */
E 22
E 21
} va_softc[NVA];
E 16

D 16
struct	buf rvabuf;		/* Used by physio for a buffer. */
E 16
I 16
D 17
struct	uba_device *vadinfo[NVA];
E 16

E 17
D 16
vaopen()
E 16
I 16
#define	VAUNIT(dev)	(minor(dev))

I 21
D 22
int va_intbit = VA_IENABLE;
E 22
E 21
struct	buf rvabuf[NVA];

D 22
int	vaprobe(), vaattach();
E 22
I 22
int	vaprobe(), vaslave(), vaattach(), vadgo();
E 22
struct	uba_device *vadinfo[NVA];
I 22
struct	uba_ctlr *vaminfo[NVA];
I 23
struct	buf vabhdr[NVA];
E 23
E 22
u_short	vastd[] = { 0764000, 0 };
struct	uba_driver vadriver =
D 22
    { vaprobe, 0, vaattach, 0, vastd, "va", vadinfo };
E 22
I 22
    { vaprobe, vaslave, vaattach, vadgo, vastd, "vz", vadinfo, "va", vaminfo };
E 22

vaprobe(reg)
	caddr_t reg;
E 16
{
I 16
	register int br, cvec;		/* value-result */
	register struct vadevice *vaaddr = (struct vadevice *)reg;
E 16

I 22
#ifdef lint
	br = 0; cvec = br; br = cvec;
	vaintr(0);
#endif
E 22
I 18
D 21
#ifdef lint
	br = 0; cvec = br; br = cvec;
	vaintr(0);
#endif
E 21
I 21
#ifndef UCBVAX
E 21
E 18
D 6
	if (vainfo.va_is_open) {	/* Can't open if it's already open. */
E 6
I 6
D 16
	if (va11.va_open) {
E 16
I 16
	vaaddr->vacsl = VA_IENABLE;
	vaaddr->vaba = 0;
	vaaddr->vacsh = VAPLOT;
I 25
D 27
#ifndef VARIANGOBIT
E 25
D 21
	vaaddr->vacsl = 0;
I 25
#endif
E 27
E 25
E 21
I 21
	vaaddr->vacsl = VA_IENABLE|VA_DMAGO;
E 21
	vaaddr->vawc = -1;
D 20
	DELAY(10000);
E 20
I 20
D 21
	DELAY(100000);
E 21
I 21
	DELAY(10000);
E 21
E 20
	vaaddr->vacsl = 0;
I 25
D 27
	return (sizeof (struct vadevice));
E 27
E 25
I 21
	vaaddr->vawc = 0;
#else
	br=0x14;
	cvec=0170;
#endif
I 27
	return (sizeof (struct vadevice));
E 27
E 21
}

/*ARGSUSED*/
I 22
vaslave(ui, reg)
	struct uba_device *ui;
	caddr_t reg;
{

	ui->ui_dk = 0;
	return (ui->ui_unit <= 0);
}

/*ARGSUSED*/
E 22
vaattach(ui)
	struct uba_device *ui;
{

I 23
	ui->ui_mi->um_tab.b_actf = &vabhdr[ui->ui_unit];
E 23
}

vaopen(dev)
	dev_t dev;
{
	register struct va_softc *sc;
	register struct vadevice *vaaddr;
	register struct uba_device *ui;
I 26
	int error;
E 26
I 22
	int unit = VAUNIT(dev);
E 22

D 22
	if (VAUNIT(dev) >= NVA || (sc = &va_softc[minor(dev)])->sc_openf ||
D 26
	    (ui = vadinfo[VAUNIT(dev)]) == 0 || ui->ui_alive == 0) {
E 22
I 22
	if (unit >= NVA || (sc = &va_softc[unit])->sc_openf ||
	    (ui = vadinfo[unit]) == 0 || ui->ui_alive == 0) {
E 22
E 16
E 6
		u.u_error = ENXIO;
		return;
	}
E 26
I 26
D 29
	    (ui = vadinfo[VAUNIT(dev)]) == 0 || ui->ui_alive == 0)
E 29
I 29
	if (unit >= NVA || (sc = &va_softc[unit])->sc_openf ||
	    (ui = vadinfo[unit]) == 0 || ui->ui_alive == 0)
E 29
		return (ENXIO);
E 26
D 6
	vainfo.va_is_open = 1;		/* NOW it's open! */
	VAADDR->vawcount = 0;		/* Clear residual errors */
	vainfo.va_wcount = 0;		/* No DMA to do now. */
	vainfo.va_state = 0;
	VAADDR->vacsrlo = IENABLE;
					/* Enable interrupts. */
E 6
I 6
D 16
	va11.va_open = 1;
	VAADDR->vawc = 0;
	va11.va_wc = 0;
	va11.va_state = 0;
	VAADDR->vacsl = IENABLE;
E 6
	vatimo();
D 6

	vacmd(VPRINT);			/* Start in print mode. */
E 6
I 6
	vacmd(VPRINT);
E 16
I 16
	vaaddr = (struct vadevice *)ui->ui_addr;
	sc->sc_openf = 1;
	vaaddr->vawc = 0;
D 22
	sc->sc_wc = 0;
E 22
	sc->sc_state = 0;
I 21
	sc->sc_tocnt = 0;
I 22
	sc->sc_iostate = VAS_IDLE;
E 22
E 21
	vaaddr->vacsl = VA_IENABLE;
	vatimo(dev);
D 26
	vacmd(dev, VPRINT);
E 16
E 6
	if (u.u_error)
E 26
I 26
	error = vacmd(dev, VPRINT);
	if (error)
E 26
D 16
		vaclose();
E 16
I 16
		vaclose(dev);
I 26
	return (error);
E 26
E 16
}

vastrategy(bp)
	register struct buf *bp;
{
D 22
	register int e;
I 16
	register struct va_softc *sc = &va_softc[VAUNIT(bp->b_dev)];
	register struct uba_device *ui = vadinfo[VAUNIT(bp->b_dev)];
	register struct vadevice *vaaddr = (struct vadevice *)ui->ui_addr;
E 22
I 22
	register struct uba_device *ui;
	register struct uba_ctlr *um;
	int s;
E 22
E 16

D 2
	VOID spl4();
E 2
I 2
D 22
	(void) spl4();
E 2
D 6
	while (vainfo.va_busy)		/* Wait till not busy. */
		sleep((caddr_t)&vainfo, VAPRI);
	vainfo.va_busy = 1;		/* Grab it. */
D 2
	VOID spl0();
E 2
I 2
	(void) spl0();
E 2

	va_ubinfo = ubasetup(bp, vabdp);	/* Set up uba mapper. */
	vainfo.va_bufp = va_ubinfo & 0x3ffff;

D 2
	VOID spl4();
E 2
I 2
	(void) spl4();
E 6
I 6
D 16
	while (va11.va_busy)
		sleep((caddr_t)&va11, VAPRI);
	va11.va_busy = 1;
	va11.va_bp = bp;
	va_ubinfo = ubasetup(bp, vabdp);
	va11.va_bufp = va_ubinfo & 0x3ffff;
E 6
E 2
	if (e = vaerror(DONE))
E 16
I 16
	while (sc->sc_busy)
		sleep((caddr_t)sc, VAPRI);
	sc->sc_busy = 1;
	sc->sc_bp = bp;
	sc->sc_ubinfo = ubasetup(ui->ui_ubanum, bp, UBA_NEEDBDP);
	if (e = vawait(bp->b_dev))
E 16
		goto brkout;
D 6
	vainfo.va_wcount = -(bp->b_bcount/2);
		/* va uses a word count, 
		   so user had better supply an even number of bytes. */
E 6
I 6
D 16
	va11.va_wc = -(bp->b_bcount/2);
E 6
	vastart();
D 6
	e = vaerror(DONE);	/* Wait for DMA to complete. */
	vainfo.va_wcount = 0;	/* Reset state info. */
	vainfo.va_bufp = 0;
E 6
I 6
	e = vaerror(DONE);	/* Wait for DMA to complete */
	va11.va_wc = 0;
	va11.va_bufp = 0;
E 6

D 6
	/* After printing a line of characters, VPRINTPLOT mode essentially
	   reverts to VPLOT mode, plotting things until a new mode is set.
	   This change is indicated by sending a VAAUTOSTEP command to
	   the va.  We also change va_state to reflect this effective
	   mode change.
E 6
I 6
	/*
	 * After printing a line of characters, VPRINTPLOT mode essentially
	 * reverts to VPLOT mode, plotting things until a new mode is set.
	 * This change is indicated by sending a VAAUTOSTEP command to
	 * the va.  We also change va_state to reflect this effective
	 * mode change.
E 6
	 */
D 6
	if (vainfo.va_state & VPRINTPLOT) {
		vainfo.va_state = (vainfo.va_state & ~VPRINTPLOT) | VPLOT;
		VAADDR->vacsrhi = VAAUTOSTEP;
E 6
I 6
	if (va11.va_state & VPRINTPLOT) {
		va11.va_state = (va11.va_state & ~VPRINTPLOT) | VPLOT;
		VAADDR->vacsh = VAAUTOSTEP;
E 6
		e |= vaerror(DONE);
E 16
I 16
	sc->sc_wc = -(bp->b_bcount/2);
	vastart(bp->b_dev);
	e = vawait(bp->b_dev);
	sc->sc_wc = 0;
	if (sc->sc_state & VPRINTPLOT) {
		sc->sc_state = (sc->sc_state & ~VPRINTPLOT) | VPLOT;
		vaaddr->vacsh = VAAUTOSTEP;
		e |= vawait(bp->b_dev);
E 22
I 22
D 23
dprintf("vastrategy(%x)\n", bp);
E 23
I 23
	dprintf("vastrategy(%x)\n", bp);
E 23
	ui = vadinfo[VAUNIT(bp->b_dev)];
	if (ui == 0 || ui->ui_alive == 0) {
		bp->b_flags |= B_ERROR;
		iodone(bp);
		return;
E 22
E 16
	}
D 2
	VOID spl0();
E 2
I 2
D 22
	(void) spl0();
E 2
brkout:
I 21
	vaaddr->vawc = 0;
E 21
D 11
	ubafree(va_ubinfo), va_ubinfo = 0;
E 11
I 11
D 12
	UBAFREECLR(va_ubinfo);
E 12
I 12
D 16
	ubarelse(&va_ubinfo);
E 12
E 11
D 6
	vainfo.va_busy = 0;
E 6
I 6
	va11.va_bp = 0;
	va11.va_busy = 0;
E 16
I 16
	ubarelse(ui->ui_ubanum, &sc->sc_ubinfo);
	sc->sc_bp = 0;
	sc->sc_busy = 0;
E 16
E 6
D 26
	iodone(bp);
E 26
	if (e)
D 26
		u.u_error = EIO;
E 26
I 26
D 27
		bp->b_flags |= B_ERROR;
	iodone(bp);
E 27
E 26
D 6
	wakeup((caddr_t)&vainfo);
E 6
I 6
D 16
	wakeup((caddr_t)&va11);
E 16
I 16
	wakeup((caddr_t)sc);
E 22
I 22
	s = spl4();
	um = ui->ui_mi;
D 23
	if (um->um_tab.b_actf == NULL)
		um->um_tab.b_actf = bp;
	else
		um->um_tab.b_actl->b_forw = bp;
	um->um_tab.b_actl = bp;
	bp = &um->um_tab;
dprintf("vastrategy: bp=%x actf=%x active=%x\n", bp, bp->b_actf, bp->b_active);
E 23
I 23
	bp->b_actf = NULL;
	if (um->um_tab.b_actf->b_actf == NULL)
		um->um_tab.b_actf->b_actf = bp;
	else {
		printf("bp = 0x%x, um->um_tab.b_actf->b_actf = 0x%x\n",
			bp, um->um_tab.b_actf->b_actf);
		panic("vastrategy");
		um->um_tab.b_actf->b_actl->b_forw = bp;
	}
	um->um_tab.b_actf->b_actl = bp;
	bp = um->um_tab.b_actf;
	dprintf("vastrategy: bp=%x actf=%x active=%d\n",
		bp, bp->b_actf, bp->b_active);
E 23
	if (bp->b_actf && bp->b_active == 0)
		(void) vastart(um);
	splx(s);
E 22
E 16
E 6
}

int	vablock = 16384;

unsigned
minvaph(bp)
D 16
struct buf *bp;
E 16
I 16
	struct buf *bp;
E 16
{
I 16

E 16
	if (bp->b_bcount > vablock)
		bp->b_bcount = vablock;
}

/*ARGSUSED*/
D 25
vawrite(dev)
E 25
I 25
vawrite(dev, uio)
E 25
I 16
	dev_t dev;
I 25
	struct uio *uio;
E 25
E 16
{
I 22

E 22
D 16
	physio(vastrategy, &rvabuf, dev, B_WRITE, minvaph);
E 16
I 16
D 21

E 21
D 25
	physio(vastrategy, &rvabuf[VAUNIT(dev)], dev, B_WRITE, minvaph);
E 25
I 25
	if (VAUNIT(dev) > NVA)
D 26
		u.u_error = ENXIO;
	else
		physio(vastrategy, &rvabuf[VAUNIT(dev)], dev, B_WRITE,
		    minvaph, uio);
E 26
I 26
		return (ENXIO);
	return (physio(vastrategy, &rvabuf[VAUNIT(dev)], dev, B_WRITE,
		    minvaph, uio));
E 26
E 25
E 16
}

D 16
/*
 * Vaerror waits until bit or ERROR gets set, then returns non-zero if
 * if it was ERROR that was set.
 */
vaerror(bit)
E 16
I 16
D 22
vawait(dev)
	dev_t dev;
E 22
I 22
vastart(um)
	register struct uba_ctlr *um;
E 22
E 16
{
I 16
D 22
	register struct vadevice *vaaddr =
	    (struct vadevice *)vadinfo[VAUNIT(dev)]->ui_addr;
E 16
	register int e;
E 22
I 22
	struct buf *bp;
	struct vadevice *vaaddr;
	register struct va_softc *sc;
	int unit;
E 22

D 6
	while ((e = VAADDR->vacsr.vacsrword & (bit|ERROR)) == 0)
		sleep((caddr_t)&vainfo, VAPRI);
E 6
I 6
D 16
	while ((e = VAADDR->vacsw & (bit|ERROR)) == 0)
		sleep((caddr_t)&va11, VAPRI);
E 6
	return (e & ERROR);
E 16
I 16
D 21
	while (((e = vaaddr->vacsw) & (VA_DONE|VA_ERROR)) == 0)
E 21
I 21
D 22
	while (((e = vaaddr->vacsw) & (VA_DONE|VA_ERROR)) == 0) {
E 21
		sleep((caddr_t)&va_softc[VAUNIT(dev)], VAPRI);
E 22
I 22
D 23
dprintf("vastart(%x), bp=%x\n", um, um->um_tab.b_actf);
	if ((bp = um->um_tab.b_actf) == NULL)
E 23
I 23
	dprintf("vastart(%x), bp=%x\n", um, um->um_tab.b_actf->b_actf);
	if ((bp = um->um_tab.b_actf->b_actf) == NULL)
E 23
		return;
D 23
	um->um_tab.b_active++;
E 23
	unit = VAUNIT(bp->b_dev);
	sc = &va_softc[unit];
I 23
	sc->sc_tocnt = 0;
E 23
	while (sc->sc_iostate&VAS_PIO) {
		sc->sc_iostate |= VAS_WANT;
		sleep((caddr_t)&sc->sc_iostate, VAPRI);
E 22
I 21
	}
D 22
	vaaddr->vacsl = 0;	/* clear interrupt enable */
#ifdef	DEBUG
	if (e & VA_ERROR)
	    printf("va%d: csw=%b wc=%o\n",VAUNIT(dev),(unsigned short)e,va_error, vaaddr->vawc);
#endif	DEBUG
E 21
	if (e & VA_NPRTIMO)
		printf("va%d: npr timeout\n", VAUNIT(dev));
	return (e & VA_ERROR);
E 22
I 22
	sc->sc_iostate |= VAS_DMA;
	vaaddr = (struct vadevice *)um->um_addr;
	vaaddr->vacsl = 0;
	vaaddr->vawc = -(bp->b_bcount / 2);
	um->um_cmd = VA_DMAGO | VA_IENABLE;
	(void) ubago(vadinfo[unit]);
E 22
E 16
}

D 6
/* vastart starts up the DMA by setting the buffer pointer and the word count. */
E 6
D 16
vastart()
E 16
I 16
D 22
vastart(dev)
	dev_t;
E 22
I 22
vadgo(um)
	register struct uba_ctlr *um;
E 22
E 16
{
D 6
	if (vainfo.va_wcount) {
		VAADDR->vabufaddr = vainfo.va_bufp;
		VAADDR->vawcount = vainfo.va_wcount;
E 6
I 6
D 16
	if (va11.va_wc) {
		VAADDR->vaba = va11.va_bufp;
I 9
		VAADDR->vacsl = (va11.va_bufp >> 12) & 0x30;
E 9
		VAADDR->vawc = va11.va_wc;
E 16
I 16
D 22
	register struct va_softc *sc = &va_softc[VAUNIT(dev)];
	register struct vadevice *vaaddr =
	    (struct vadevice *)vadinfo[VAUNIT(dev)]->ui_addr;
E 22
I 22
	register struct vadevice *vaaddr = (struct vadevice *)um->um_addr;
D 23
	u_short i;
	short j;
E 23
I 23
	register struct buf *bp;
E 23
E 22

D 22
	if (sc->sc_wc == 0)
E 16
E 6
		return;
I 21
	sc->sc_tocnt = 0;
	vaaddr->vacsl = 0;	/* clear GO bit before writing new wc */
E 21
D 16
	}
E 16
I 16
	vaaddr->vaba = sc->sc_ubinfo;
I 25
D 27
#ifndef VARIANGOBIT
E 25
D 21
	vaaddr->vacsl = (sc->sc_ubinfo >> 12) & 0x30;
I 25
#else
	vaaddr->vacsl = (sc->sc_ubinfo >> 12) & 0x30 | VA_IENABLE | VA_DMAGO;
#endif
E 27
E 25
E 21
	vaaddr->vawc = sc->sc_wc;
I 21
	vaaddr->vacsl = ((sc->sc_ubinfo >> 12) & 0x30)|VA_DMAGO|va_intbit;
E 22
I 22
D 23
	i = um->um_ubinfo;
	j = ((um->um_ubinfo >> 12) & 0x30) | um->um_cmd;
dprintf("vadgo: vaba 0x%x, vacsl 0%o, vawc 0x%x\n", i, j, vaaddr->vawc);
E 23
I 23
	bp = um->um_tab.b_actf;
	va_softc[VAUNIT(bp->b_actf->b_dev)].sc_tocnt = 0;
	bp->b_active++;
E 23
	vaaddr->vaba = um->um_ubinfo;
	vaaddr->vacsl = ((um->um_ubinfo >> 12) & 0x30) | um->um_cmd;
E 22
E 21
E 16
}

/*ARGSUSED*/
D 25
vaioctl(dev, cmd, addr, flag)
	register caddr_t addr;
E 25
I 25
vaioctl(dev, cmd, data, flag)
	register caddr_t data;
E 25
{
D 34
	register int vcmd;
E 34
I 16
	register struct va_softc *sc = &va_softc[VAUNIT(dev)];
E 16

	switch (cmd) {

	case VGETSTATE:
D 2
		VOID suword(addr, vainfo.va_state);
E 2
I 2
D 6
		(void) suword(addr, vainfo.va_state);
E 6
I 6
D 16
		(void) suword(addr, va11.va_state);
E 16
I 16
D 25
		(void) suword(addr, sc->sc_state);
E 25
I 25
		*(int *)data = sc->sc_state;
E 25
E 16
E 6
E 2
D 26
		return;
E 26
I 26
		break;
E 26

	case VSETSTATE:
D 25
		vcmd = fuword(addr);
		if (vcmd == -1) {	
			u.u_error = EFAULT;
			return;
		}
D 16
		vacmd(vcmd);
E 16
I 16
		vacmd(dev, vcmd);
E 25
I 25
D 26
		vacmd(dev, *(int *)data);
E 25
E 16
		return;
E 26
I 26
		return (vacmd(dev, *(int *)data));
D 34
		break;
E 34
E 26

	default:
D 16
		u.u_error = ENOTTY;	/* Not a legal ioctl cmd. */
E 16
I 16
D 26
		u.u_error = ENOTTY;
E 16
		return;
E 26
I 26
		return (ENOTTY);
E 26
	}
I 26
	return (0);
E 26
}

D 6
/* vacmd sends a command code to the va, and waits for it to complete.
   If an error occurs, u.u_error is set to EIO.
   vacmd also updates vainfo.va_state.
E 6
I 6
D 16
/*
 * Send a command code to the va, and wait for it to complete.
 * If an error occurs, u.u_error is set to EIO.
 * In any case, update va11.va_state.
E 6
 */
D 6

E 6
vacmd(vcmd)
E 16
I 16
vacmd(dev, vcmd)
	dev_t dev;
	int vcmd;
E 16
{
I 16
	register struct va_softc *sc = &va_softc[VAUNIT(dev)];
D 22
	register struct vadevice *vaaddr =
	    (struct vadevice *)vadinfo[VAUNIT(dev)]->ui_addr;
I 26
	int error = 0;
E 26
E 22
I 22
	int s, cmd;
E 22

E 16
D 2
	VOID spl4();
	VOID vaerror(DONE);	/* Wait for va to be ready. */
E 2
I 2
D 22
	(void) spl4();
E 22
I 22
	s = spl4();
	while (sc->sc_iostate&VAS_DMA) {
		sc->sc_iostate |= VAS_WANT;
		sleep((caddr_t)&sc->sc_iostate, VAPRI);
	}
	sc->sc_iostate |= VAS_PIO;
E 22
I 21
	sc->sc_tocnt = 0;
E 21
D 6
	(void) vaerror(DONE);	/* Wait for va to be ready. */
E 6
I 6
D 16
	(void) vaerror(DONE);		/* Wait for va to be ready */
E 16
I 16
D 22
	(void) vawait(dev);
E 22
I 22
	cmd = 0;
E 22
E 16
E 6
E 2
	switch (vcmd) {

	case VPLOT:
		/* Must turn on plot AND autostep modes. */
D 6
		VAADDR->vacsrhi = VAPLOT;
E 6
I 6
D 16
		VAADDR->vacsh = VAPLOT;
E 6
		if (vaerror(DONE))
E 16
I 16
D 22
		vaaddr->vacsh = VAPLOT;
		if (vawait(dev))
E 22
I 22
		if (vadopio(dev, VAPLOT))
E 22
E 16
D 26
			u.u_error = EIO;
E 26
I 26
			error = EIO;
E 26
D 6
		VAADDR->vacsrhi = VAAUTOSTEP;
E 6
I 6
D 16
		VAADDR->vacsh = VAAUTOSTEP;
E 16
I 16
D 22
		vaaddr->vacsh = VAAUTOSTEP;
E 22
I 22
		cmd = VAAUTOSTEP;
E 22
E 16
E 6
		break;

	case VPRINT:
D 6
		VAADDR->vacsrhi = VAPRINT;
E 6
I 6
D 16
		VAADDR->vacsh = VAPRINT;
E 16
I 16
D 22
		vaaddr->vacsh = VAPRINT;
E 22
I 22
		cmd = VAPRINT;
E 22
E 16
E 6
		break;

	case VPRINTPLOT:
D 6
		VAADDR->vacsrhi = VAPRINTPLOT;
E 6
I 6
D 16
		VAADDR->vacsh = VAPRINTPLOT;
E 16
I 16
D 22
		vaaddr->vacsh = VAPRINTPLOT;
E 22
I 22
		cmd = VAPRINTPLOT;
E 22
E 16
E 6
		break;
	}
D 6
	vainfo.va_state =
		(vainfo.va_state & ~(VPLOT | VPRINT | VPRINTPLOT)) | vcmd;
E 6
I 6
D 16
	va11.va_state =
		(va11.va_state & ~(VPLOT | VPRINT | VPRINTPLOT)) | vcmd;
E 6

	if (vaerror(DONE))	/* Wait for command to complete. */
E 16
I 16
	sc->sc_state = (sc->sc_state & ~(VPLOT|VPRINT|VPRINTPLOT)) | vcmd;
D 22
	if (vawait(dev))
E 22
I 22
	if (cmd && vadopio(dev, cmd))
E 22
E 16
D 26
		u.u_error = EIO;
E 26
I 26
		error = EIO;
E 26
D 2
	VOID spl0();
E 2
I 2
D 22
	(void) spl0();
I 26
D 27
	return (error);
E 27
E 26
E 22
I 22
	sc->sc_iostate &= ~VAS_PIO;
	if (sc->sc_iostate&VAS_WANT) {
		sc->sc_iostate &= ~VAS_WANT;
		wakeup((caddr_t)&sc->sc_iostate);
	}
	splx(s);
I 27
	return (error);
E 27
E 22
E 2
}

I 22
vadopio(dev, cmd)
	dev_t dev;
	int cmd;
{
	register struct vadevice *vaaddr =
	    (struct vadevice *)vaminfo[VAUNIT(dev)]->um_addr;
	register struct va_softc *sc = &va_softc[VAUNIT(dev)];

	sc->sc_info = 0;
	vaaddr->vacsh = cmd;
	while ((sc->sc_info&(VA_DONE|VA_ERROR)) == 0)
		sleep((caddr_t)&sc->sc_info, VAPRI);
	return (sc->sc_info&VA_ERROR);
}

E 22
D 16
vatimo()
E 16
I 16
vatimo(dev)
	dev_t dev;
E 16
{
D 6
	if (vainfo.va_is_open)
E 6
I 6
D 16
	if (va11.va_open)
E 6
D 13
		timeout(vatimo, (caddr_t)0, HZ/10);
E 13
I 13
		timeout(vatimo, (caddr_t)0, hz/10);
E 13
	vaintr(0);
E 16
I 16
	register struct va_softc *sc = &va_softc[VAUNIT(dev)];

	if (sc->sc_openf)
D 21
		timeout(vatimo, (caddr_t)dev, hz/10);
	vaintr(dev);
E 21
I 21
		timeout(vatimo, (caddr_t)dev, hz/2);
D 22
	if(!sc->sc_tocnt) {
		sc->sc_tocnt++;
	} else {
		sc->sc_tocnt = 0;
		vaintr(dev);
	}
E 22
I 22
	if (++sc->sc_tocnt < 2)
		return;
	sc->sc_tocnt = 0;
D 23
dprintf("vatimo: calling vaintr\n");
E 23
I 23
	dprintf("vatimo: calling vaintr\n");
E 23
	vaintr(dev);
E 22
E 21
E 16
}

/*ARGSUSED*/
vaintr(dev)
I 16
	dev_t dev;
E 16
{
D 6
	wakeup((caddr_t)&vainfo);
E 6
I 6
D 16
	wakeup((caddr_t)&va11);
E 16
I 16
D 22
	register struct va_softc *sc = &va_softc[VAUNIT(dev)];
E 22
I 22
	register struct uba_ctlr *um;
	struct vadevice *vaaddr;
	struct buf *bp;
	register int unit = VAUNIT(dev), e;
	register struct va_softc *sc = &va_softc[unit];
E 22

D 22
	wakeup((caddr_t)sc);
E 22
I 22
	um = vaminfo[unit];
	vaaddr = (struct vadevice *)um->um_addr;
	e = vaaddr->vacsw;
D 23
dprintf("vaintr: um=%x, e=%x\n", um, e);
E 23
I 23
	dprintf("vaintr: um=0x%x, e=0x%x, b_active %d\n",
		um, e, um->um_tab.b_actf->b_active);
E 23
	if ((e&(VA_DONE|VA_ERROR)) == 0)
		return;
	vaaddr->vacsl = 0;
	if ((e&VA_ERROR) && (e&VA_NPRTIMO))
		printf("va%d: npr timeout\n", unit);
	if (sc->sc_iostate&VAS_PIO) {
		sc->sc_info = e;
		wakeup((caddr_t)&sc->sc_info);
		return;
	}
D 23
	if (um->um_tab.b_active) {
		bp = um->um_tab.b_actf;
E 23
I 23
	if (um->um_tab.b_actf->b_active) {
		bp = um->um_tab.b_actf->b_actf;
E 23
		if (e&VA_ERROR)
			bp->b_flags |= B_ERROR;
		if (sc->sc_state&VPRINTPLOT) {
			sc->sc_state = (sc->sc_state & ~VPRINTPLOT) | VPLOT;
			vaaddr->vacsh = VAAUTOSTEP;
			return;
		}
D 23
	}
	ubadone(um);
	if (um->um_tab.b_active) {
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = bp->b_forw;
E 23
I 23
		ubadone(um);
		um->um_tab.b_actf->b_active = 0;
		um->um_tab.b_actf->b_actf = bp->b_forw;
E 23
		bp->b_active = 0;
		bp->b_errcnt = 0;
		bp->b_resid = 0;
		iodone(bp);
	}
D 23
	if (um->um_tab.b_actf == 0) {
E 23
I 23
	if (um->um_tab.b_actf->b_actf == 0) {
E 23
		sc->sc_iostate &= ~VAS_DMA;
		if (sc->sc_iostate&VAS_WANT) {
			sc->sc_iostate &= ~VAS_WANT;
			wakeup((caddr_t)&sc->sc_iostate);
		}
		return;
	}
D 23
	if (um->um_tab.b_active == 0)
E 23
I 23
	if (um->um_tab.b_actf->b_active == 0)
E 23
		vastart(um);
E 22
E 16
E 6
}

D 16
vaclose()
E 16
I 16
vaclose(dev)
	dev_t dev;
E 16
{
I 16
	register struct va_softc *sc = &va_softc[VAUNIT(dev)];
	register struct vadevice *vaaddr =
	    (struct vadevice *)vadinfo[VAUNIT(dev)]->ui_addr;
E 16

D 6
	vainfo.va_is_open = 0;
	vainfo.va_busy = 0;
	vainfo.va_state = 0;
	vainfo.va_wcount = 0;
	vainfo.va_bufp = 0;
	VAADDR->vacsrlo = 0;
E 6
I 6
D 16
	va11.va_open = 0;
	va11.va_busy = 0;
	va11.va_state = 0;
	va11.va_wc = 0;
	va11.va_bufp = 0;
	VAADDR->vacsl = 0;
E 16
I 16
	sc->sc_openf = 0;
D 22
	sc->sc_busy = 0;
E 22
	sc->sc_state = 0;
D 22
	sc->sc_ubinfo = 0;
E 22
I 22
	if (sc->sc_iostate != VAS_IDLE)
		wakeup((caddr_t)&sc->sc_iostate);
	sc->sc_iostate = VAS_IDLE;
E 22
	vaaddr->vacsl = 0;
I 21
	vaaddr->vawc = 0;
E 21
E 16
E 6
}
D 6
#endif
E 6
I 6

D 14
#define	DELAY(N)	{ register int d; d = N; while (--d > 0); }

E 14
D 16
vareset()
E 16
I 16
vareset(uban)
	int uban;
E 16
{
I 16
	register int va11;
D 22
	register struct uba_device *ui;
	register struct va_softc *sc = va_softc;
E 22
I 22
	register struct uba_ctlr *um;
E 22
	register struct vadevice *vaaddr;
I 22
	register struct va_softc *sc;
E 22
E 16

D 16
	if (va11.va_open == 0)
		return;
	printf(" va");
	VAADDR->vacsl = IENABLE;
	if (va11.va_state & VPLOT) {
		VAADDR->vacsh = VAPLOT;
E 16
I 16
	for (va11 = 0; va11 < NVA; va11++, sc++) {
D 22
		if ((ui = vadinfo[va11]) == 0 || ui->ui_alive == 0 ||
		    ui->ui_ubanum != uban || sc->sc_openf == 0)
E 22
I 22
		if ((um = vaminfo[va11]) == 0 || um->um_ubanum != uban ||
		    um->um_alive == 0)
E 22
			continue;
I 22
		sc = &va_softc[um->um_ctlr];
		if (sc->sc_openf == 0)
			continue;
E 22
		printf(" va%d", va11);
D 22
		vaaddr = (struct vadevice *)ui->ui_addr;
E 22
I 22
		vaaddr = (struct vadevice *)um->um_addr;
E 22
		vaaddr->vacsl = VA_IENABLE;
		if (sc->sc_state & VPLOT) {
			vaaddr->vacsh = VAPLOT;
			DELAY(10000);
			vaaddr->vacsh = VAAUTOSTEP;
		} else if (sc->sc_state & VPRINTPLOT)
			vaaddr->vacsh = VPRINTPLOT;
		else
			vaaddr->vacsh = VAPRINTPLOT;
E 16
		DELAY(10000);
I 29
		sc->sc_iostate = VAS_IDLE;
		um->um_tab.b_actf->b_active = 0;
		um->um_tab.b_actf->b_actf = um->um_tab.b_actf->b_actl = 0;
		if (um->um_ubinfo) {
			printf("<%d>", (um->um_ubinfo >> 28) & 0xf);
			um->um_ubinfo = 0;
		}
E 29
D 16
		VAADDR->vacsh = VAAUTOSTEP;
	} else if (va11.va_state & VPRINTPLOT)
		VAADDR->vacsh = VPRINTPLOT;
	else
		VAADDR->vacsh = VAPRINTPLOT;
	DELAY(10000);
	if (va11.va_busy == 0)
		return;
	if (va_ubinfo) {
		printf("<%d>", (va_ubinfo>>28)&0xf);
D 11
		ubafree(va_ubinfo), va_ubinfo = 0;
E 11
I 11
D 12
		UBAFREECLR(va_ubinfo);
E 12
I 12
		ubarelse(&va_ubinfo);
E 16
I 16
D 22
		if (sc->sc_busy == 0)
			continue;
D 26
		if (sc->sc_ubinfo) {
			printf("<%d>", (sc->sc_ubinfo>>28)&0xf);
			ubarelse(ui->ui_ubanum, &sc->sc_ubinfo);
E 22
I 22
		sc->sc_iostate = VAS_IDLE;
D 23
		um->um_tab.b_active = 0;
		um->um_tab.b_actf = um->um_tab.b_actl = 0;
E 23
I 23
		um->um_tab.b_actf->b_active = 0;
		um->um_tab.b_actf->b_actf = um->um_tab.b_actf->b_actl = 0;
E 23
		if (um->um_ubinfo) {
			printf("<%d>", (um->um_ubinfo >> 28) & 0xf);
			ubadone(um);
E 22
		}
E 26
D 22
		sc->sc_ubinfo = ubasetup(ui->ui_ubanum, sc->sc_bp, UBA_NEEDBDP);
		sc->sc_wc = -(sc->sc_bp->b_bcount/2);
		vastart(sc->sc_bp->b_dev);
E 22
I 22
		(void) vastart(um);
E 22
E 16
E 12
E 11
	}
D 16
	/* This code belongs in vastart() */
	va_ubinfo = ubasetup(va11.va_bp, vabdp);
	va11.va_bufp = va_ubinfo & 0x3ffff;
	va11.va_wc = (-va11.va_bp->b_bcount/2);
	/* End badly placed code */
	vastart();
E 16
}
I 19

vaselect()
{
I 26

E 26
	return (1);
}
E 19
I 7
#endif
E 7
E 6
E 1
