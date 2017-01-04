h45468
s 00011/00015/00344
d D 4.22 82/10/17 11:52:22 root 29 28
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00009/00006/00350
d D 4.21 82/10/10 22:38:44 root 28 27
c minor fixes relating to u.u_error handling
e
s 00003/00002/00353
d D 4.20 82/10/10 17:30:37 root 27 26
c header files for vax are in their place
e
s 00003/00004/00352
d D 4.19 82/09/12 03:12:26 root 26 25
c 
e
s 00007/00002/00349
d D 4.18 82/08/22 21:22:49 root 25 24
c fully uio()'d
e
s 00002/00001/00349
d D 4.17 82/08/13 00:18:45 root 24 23
c changes for char dev uio'ing
e
s 00004/00009/00346
d D 4.16 82/08/01 19:26:59 sam 23 22
c new ioctl's
e
s 00001/00000/00354
d D 4.15 82/07/15 19:57:50 kre 22 21
c probe routines return size of unibus dev regs to reserve space
e
s 00007/00000/00347
d D 4.14 82/06/26 22:10:04 sam 21 20
c varian w/ GO bit (from lucas)
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
/*	%M%	%I%	%E%	*/
E 15
E 5
E 4
E 3

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
E 7
D 6
#ifdef ERNIE
E 6
#include "../h/param.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/buf.h"
#include "../h/systm.h"
#include "../h/map.h"
#include "../h/pte.h"
D 16
#include "../h/uba.h"
E 16
I 16
D 27
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 27
E 16
#include "../h/vcmd.h"
I 24
#include "../h/uio.h"
I 27

#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 27
E 24

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
I 21
#define	VA_DMAGO	0000010		/* DMA go bit */
E 21
#define	VA_SUPPLIESLOW	0000004
#define	VA_BOTOFFORM	0000002
#define	VA_BYTEREVERSE	0000001		/* reverse byte order in words */
E 16
E 7
E 6

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
	char	sc_openf;
	char	sc_busy;
	int	sc_state;
	int	sc_wc;
	struct	buf *sc_bp;
	int	sc_ubinfo;
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

struct	buf rvabuf[NVA];

int	vaprobe(), vaattach();
struct	uba_device *vadinfo[NVA];
u_short	vastd[] = { 0764000, 0 };
struct	uba_driver vadriver =
    { vaprobe, 0, vaattach, 0, vastd, "va", vadinfo };

vaprobe(reg)
	caddr_t reg;
E 16
{
I 16
	register int br, cvec;		/* value-result */
	register struct vadevice *vaaddr = (struct vadevice *)reg;
E 16

I 18
#ifdef lint
	br = 0; cvec = br; br = cvec;
	vaintr(0);
#endif
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
I 21
#ifndef VARIANGOBIT
E 21
	vaaddr->vacsl = 0;
I 21
#endif
E 21
	vaaddr->vawc = -1;
D 20
	DELAY(10000);
E 20
I 20
	DELAY(100000);
E 20
	vaaddr->vacsl = 0;
I 22
	return (sizeof (struct vadevice));
E 22
}

/*ARGSUSED*/
vaattach(ui)
	struct uba_device *ui;
{

}

vaopen(dev)
	dev_t dev;
{
	register struct va_softc *sc;
	register struct vadevice *vaaddr;
	register struct uba_device *ui;
I 29
	int error;
E 29

	if (VAUNIT(dev) >= NVA || (sc = &va_softc[minor(dev)])->sc_openf ||
D 29
	    (ui = vadinfo[VAUNIT(dev)]) == 0 || ui->ui_alive == 0) {
E 16
E 6
		u.u_error = ENXIO;
		return;
	}
E 29
I 29
	    (ui = vadinfo[VAUNIT(dev)]) == 0 || ui->ui_alive == 0)
		return (ENXIO);
E 29
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
	sc->sc_wc = 0;
	sc->sc_state = 0;
	vaaddr->vacsl = VA_IENABLE;
	vatimo(dev);
D 28
	vacmd(dev, VPRINT);
E 28
I 28
D 29
	u.u_error = vacmd(dev, VPRINT);
E 28
E 16
E 6
	if (u.u_error)
E 29
I 29
	error = vacmd(dev, VPRINT);
	if (error)
E 29
D 16
		vaclose();
E 16
I 16
		vaclose(dev);
I 29
	return (error);
E 29
E 16
}

vastrategy(bp)
	register struct buf *bp;
{
	register int e;
I 16
	register struct va_softc *sc = &va_softc[VAUNIT(bp->b_dev)];
	register struct uba_device *ui = vadinfo[VAUNIT(bp->b_dev)];
	register struct vadevice *vaaddr = (struct vadevice *)ui->ui_addr;
E 16

D 2
	VOID spl4();
E 2
I 2
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
E 16
	}
D 2
	VOID spl0();
E 2
I 2
	(void) spl0();
E 2
brkout:
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
D 28
	iodone(bp);
E 28
	if (e)
D 28
		u.u_error = EIO;
E 28
I 28
		bp->b_flags |= B_ERROR;
	iodone(bp);
E 28
D 6
	wakeup((caddr_t)&vainfo);
E 6
I 6
D 16
	wakeup((caddr_t)&va11);
E 16
I 16
	wakeup((caddr_t)sc);
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
D 16
	physio(vastrategy, &rvabuf, dev, B_WRITE, minvaph);
E 16
I 16

D 24
	physio(vastrategy, &rvabuf[VAUNIT(dev)], dev, B_WRITE, minvaph);
E 24
I 24
D 25
	physio(vastrategy, &rvabuf[VAUNIT(dev)], dev, B_WRITE, minvaph, 0);
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
E 24
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
vawait(dev)
	dev_t dev;
E 16
{
I 16
	register struct vadevice *vaaddr =
	    (struct vadevice *)vadinfo[VAUNIT(dev)]->ui_addr;
E 16
	register int e;

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
	while (((e = vaaddr->vacsw) & (VA_DONE|VA_ERROR)) == 0)
		sleep((caddr_t)&va_softc[VAUNIT(dev)], VAPRI);
	if (e & VA_NPRTIMO)
		printf("va%d: npr timeout\n", VAUNIT(dev));
	return (e & VA_ERROR);
E 16
}

D 6
/* vastart starts up the DMA by setting the buffer pointer and the word count. */
E 6
D 16
vastart()
E 16
I 16
vastart(dev)
	dev_t;
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
	register struct va_softc *sc = &va_softc[VAUNIT(dev)];
	register struct vadevice *vaaddr =
	    (struct vadevice *)vadinfo[VAUNIT(dev)]->ui_addr;

	if (sc->sc_wc == 0)
E 16
E 6
		return;
D 16
	}
E 16
I 16
	vaaddr->vaba = sc->sc_ubinfo;
I 21
#ifndef VARIANGOBIT
E 21
	vaaddr->vacsl = (sc->sc_ubinfo >> 12) & 0x30;
I 21
#else
	vaaddr->vacsl = (sc->sc_ubinfo >> 12) & 0x30 | VA_IENABLE | VA_DMAGO;
#endif
E 21
	vaaddr->vawc = sc->sc_wc;
E 16
}

/*ARGSUSED*/
D 23
vaioctl(dev, cmd, addr, flag)
	register caddr_t addr;
E 23
I 23
vaioctl(dev, cmd, data, flag)
	register caddr_t data;
E 23
{
	register int vcmd;
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
D 23
		(void) suword(addr, sc->sc_state);
E 23
I 23
		*(int *)data = sc->sc_state;
E 23
E 16
E 6
E 2
D 29
		return;
E 29
I 29
		break;
E 29

	case VSETSTATE:
D 23
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
E 23
I 23
D 28
		vacmd(dev, *(int *)data);
E 28
I 28
D 29
		u.u_error = vacmd(dev, *(int *)data);
E 28
E 23
E 16
		return;
E 29
I 29
		return (vacmd(dev, *(int *)data));
		break;
E 29

	default:
D 16
		u.u_error = ENOTTY;	/* Not a legal ioctl cmd. */
E 16
I 16
D 29
		u.u_error = ENOTTY;
E 16
		return;
E 29
I 29
		return (ENOTTY);
E 29
	}
I 29
	return (0);
E 29
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
	register struct vadevice *vaaddr =
	    (struct vadevice *)vadinfo[VAUNIT(dev)]->ui_addr;
I 28
	int error = 0;
E 28

E 16
D 2
	VOID spl4();
	VOID vaerror(DONE);	/* Wait for va to be ready. */
E 2
I 2
	(void) spl4();
D 6
	(void) vaerror(DONE);	/* Wait for va to be ready. */
E 6
I 6
D 16
	(void) vaerror(DONE);		/* Wait for va to be ready */
E 16
I 16
	(void) vawait(dev);
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
		vaaddr->vacsh = VAPLOT;
		if (vawait(dev))
E 16
D 28
			u.u_error = EIO;
E 28
I 28
			error = EIO;
E 28
D 6
		VAADDR->vacsrhi = VAAUTOSTEP;
E 6
I 6
D 16
		VAADDR->vacsh = VAAUTOSTEP;
E 16
I 16
		vaaddr->vacsh = VAAUTOSTEP;
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
		vaaddr->vacsh = VAPRINT;
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
		vaaddr->vacsh = VAPRINTPLOT;
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
	if (vawait(dev))
E 16
D 28
		u.u_error = EIO;
E 28
I 28
		error = EIO;
E 28
D 2
	VOID spl0();
E 2
I 2
	(void) spl0();
I 28
	return (error);
E 28
E 2
}

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
		timeout(vatimo, (caddr_t)dev, hz/10);
	vaintr(dev);
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
	register struct va_softc *sc = &va_softc[VAUNIT(dev)];

	wakeup((caddr_t)sc);
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
	sc->sc_busy = 0;
	sc->sc_state = 0;
	sc->sc_ubinfo = 0;
	vaaddr->vacsl = 0;
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
	register struct uba_device *ui;
	register struct va_softc *sc = va_softc;
	register struct vadevice *vaaddr;
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
		if ((ui = vadinfo[va11]) == 0 || ui->ui_alive == 0 ||
		    ui->ui_ubanum != uban || sc->sc_openf == 0)
			continue;
		printf(" va%d", va11);
		vaaddr = (struct vadevice *)ui->ui_addr;
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
		if (sc->sc_busy == 0)
			continue;
D 29
		if (sc->sc_ubinfo) {
			printf("<%d>", (sc->sc_ubinfo>>28)&0xf);
			ubarelse(ui->ui_ubanum, &sc->sc_ubinfo);
		}
E 29
		sc->sc_ubinfo = ubasetup(ui->ui_ubanum, sc->sc_bp, UBA_NEEDBDP);
		sc->sc_wc = -(sc->sc_bp->b_bcount/2);
		vastart(sc->sc_bp->b_dev);
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
I 28

E 28
	return (1);
}
E 19
I 7
#endif
E 7
E 6
E 1
