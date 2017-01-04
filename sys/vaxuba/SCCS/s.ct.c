h02813
s 00001/00001/00184
d D 7.1 86/06/05 01:05:26 mckusick 19 18
c 4.3BSD release version
e
s 00002/00002/00183
d D 6.6 86/06/02 14:47:20 karels 18 17
c lint
e
s 00001/00000/00184
d D 6.5 86/05/21 08:01:28 mckusick 17 16
c need definition of winsize structure
e
s 00075/00028/00109
d D 6.4 86/04/21 12:06:28 karels 16 15
c from computer center; changed #includes and EBUSY if open
e
s 00007/00001/00130
d D 6.3 85/06/08 14:13:29 mckusick 15 14
c Add copyright
e
s 00010/00010/00121
d D 6.2 84/08/29 20:08:03 bloom 14 13
c Change to includes.  No more ../h
e
s 00000/00000/00131
d D 6.1 83/07/29 07:26:57 sam 13 12
c 4.2 distribution
e
s 00001/00001/00130
d D 4.12 82/12/17 12:01:12 sam 12 11
c sun merge
e
s 00003/00004/00128
d D 4.11 82/10/17 11:48:02 root 11 10
c ioctl/open return errors, not u.u_error; remove ubarelses (it is
c now done in uba.c); add open routines to some disk drivers
e
s 00003/00002/00129
d D 4.10 82/10/10 17:26:13 root 10 9
c header files for vax are in their place
e
s 00003/00002/00128
d D 4.9 82/08/22 21:16:43 root 9 8
c fully uio()'d
e
s 00001/00000/00129
d D 4.8 82/07/15 19:58:41 kre 8 7
c probe routines return size of unibus dev regs to reserve space
e
s 00004/00003/00125
d D 4.7 81/11/18 15:48:52 wnj 7 6
c lint
e
s 00004/00000/00124
d D 4.6 81/07/05 21:59:59 bugs 6 5
c fix per ghg
e
s 00009/00000/00115
d D 4.5 81/03/11 21:34:12 wnj 5 4
c tyops
e
s 00061/00031/00054
d D 4.4 81/03/11 18:33:58 wnj 4 3
c converted for auto-configure
e
s 00000/00000/00085
d D 4.3 81/03/09 01:52:33 wnj 3 2
c %G% -> %E%
e
s 00002/00002/00083
d D 4.2 81/03/09 00:33:01 wnj 2 1
c lint
e
s 00085/00000/00000
d D 4.1 81/02/23 19:47:19 wnj 1 0
c date and time created 81/02/23 19:47:19 by wnj
e
u
U
t
T
I 1
D 15
/*	%M%	%I%	%E%	*/
E 15
I 15
/*
D 19
 * Copyright (c) 1982 Regents of the University of California.
E 19
I 19
 * Copyright (c) 1982, 1986 Regents of the University of California.
E 19
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */
E 15

D 4
#include "cat.h"
E 4
I 4
#include "ct.h"
E 4
#if NCT > 0
/*
D 16
 * GP DR11C driver used for C/A/T
I 6
 *
 * BUGS:
 *	This driver hasn't been tested in 4.1bsd
E 16
I 16
 * GP DR11C driver used for C/A/T or Autologic APS micro-5
E 16
E 6
 */
I 12
#include "../machine/pte.h"
E 12

D 14
#include "../h/param.h"
I 4
#include "../h/systm.h"
E 4
#include "../h/tty.h"
D 12
#include "../h/pte.h"
E 12
#include "../h/map.h"
D 4
#include "../h/uba.h"
E 4
#include "../h/buf.h"
I 4
D 10
#include "../h/ubareg.h"
#include "../h/ubavar.h"
E 10
E 4
#include "../h/conf.h"
#include "../h/dir.h"
#include "../h/user.h"
E 14
I 14
#include "param.h"
#include "systm.h"
I 17
#include "ioctl.h"
E 17
#include "tty.h"
#include "map.h"
#include "buf.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
I 16
#include "kernel.h"
E 16
E 14
I 10

D 14
#include "../vaxuba/ubareg.h"
#include "../vaxuba/ubavar.h"
E 14
I 14
#include "ubareg.h"
#include "ubavar.h"
E 14
E 10

#define	PCAT	(PZERO+9)
#define	CATHIWAT	100
#define	CATLOWAT	30

I 16
#define	REQUEST_B	0x8000
#define REQUEST_A	0x80
#define	INT_ENB_A	0x40
#define	INT_ENB_B	0x20
#define	CSR1		0x2
#define	CSR0		0x1

E 16
D 4
struct {
	int	catlock;
	struct	clist	oq;
} cat;
E 4
I 4
struct ct_softc {
D 16
	int	sc_openf;
E 16
I 16
	int	sc_state;
E 16
	struct	clist sc_oq;
} ct_softc[NCT];
E 4

I 16
#define	CT_OPEN		0x1
#define	CT_RUNNING	0x2

E 16
D 4
struct device {
	short	catcsr;
	short	catbuf;
E 4
I 4
struct ctdevice {
D 16
	short	ctcsr;
	short	ctbuf;
E 16
I 16
	u_short	ctcsr;
	u_short	ctobuf;
	u_short ctibuf;
E 16
E 4
};

D 4
int ctintr();
E 4
I 4
int	ctprobe(), ctattach(), ctintr();
struct	uba_device *ctdinfo[NCT];
D 16
u_short	ctstd[] = { 0 };
E 16
I 16
u_short	ctstd[] = { 0167770, 0 };
E 16
struct	uba_driver ctdriver = 
    { ctprobe, 0, ctattach, 0, ctstd, "ct", ctdinfo };
E 4

I 5
#define	CTUNIT(dev)	(minor(dev))

I 16
int	ct_init	= 0;	/* set to CSR1 for testing loopback on controller */

E 16
E 5
I 4
ctprobe(reg)
	caddr_t reg;
{
I 6
	register int br, cvec;		/* value-result */
E 6
	register struct ctdevice *ctaddr = (struct ctdevice *)reg;

I 7
#ifdef lint
	br = 0; cvec = br; br = cvec;
	ctintr(0);
#endif
E 7
D 16
	ctaddr->ctcsr = IENABLE;
	DELAY(10000);
	ctaddr->ctcsr = 0;
E 16
I 16
	/*
	 * There is no way to make a DR11c interrupt without some
	 * external support. We can't always trust that the typesetter
	 * will be online and ready so we've made other provisions.
	 * This probe assumes setting the B Int Enb will generate
	 * an interrupt. To do this, we set CSR0 and loop this back
	 * to REQUEST_B in the second plug on the controller.
	 * Then, we reset the vector to be that for the "real" device.
	 */
	ctaddr->ctcsr = INT_ENB_B | CSR0; /* Assume hardware loopback! */
	DELAY(1000);
	ctaddr->ctcsr = ct_init; /* should be CSR1 for loopback testing */
	if (cvec & 04) {
		printf("ct: resetting vector %o to %o\n", cvec, cvec&0773);
		cvec &= 0773;
	}
E 16
I 8
	return (sizeof (struct ctdevice));
E 8
I 5
}

/*ARGSUSED*/
ctattach(ui)
D 18
	register struct uba_device *ui;
E 18
I 18
	struct uba_device *ui;
E 18
{
D 16

E 16
E 5
}

E 4
ctopen(dev)
I 4
	dev_t dev;
E 4
{
D 4
	if (cat.catlock==0) {
		cat.catlock++;
		CATADDR->catcsr |= IENABLE;
	} else
E 4
I 4
	register struct ct_softc *sc;
	register struct uba_device *ui;
	register struct ctdevice *ctaddr;

	if (CTUNIT(dev) >= NCT || (ui = ctdinfo[CTUNIT(dev)]) == 0 ||
D 11
	    ui->ui_alive == 0 || (sc = &ct_softc[CTUNIT(dev)])->sc_openf) {
E 4
		u.u_error = ENXIO;
I 4
		return;
	}
E 11
I 11
D 16
	    ui->ui_alive == 0 || (sc = &ct_softc[CTUNIT(dev)])->sc_openf)
		return (ENXIO);
E 11
	sc->sc_openf = 1;
	ctaddr->ctcsr |= IENABLE;
E 16
I 16
	    ui->ui_alive == 0)
		return (ENODEV);
	if ((sc = &ct_softc[CTUNIT(dev)])->sc_state&CT_OPEN)
		return (EBUSY);
	sc->sc_state = CT_OPEN;
	ctaddr = (struct ctdevice *)ui->ui_addr;
	ctaddr->ctcsr |= INT_ENB_A;
E 16
I 11
	return (0);
E 11
E 4
}

D 4
ctclose()
E 4
I 4
ctclose(dev)
	dev_t dev;
E 4
{
D 4
	cat.catlock = 0;
	ctintr();
E 4
I 4
D 16

	ct_softc[CTUNIT(dev)].sc_openf = 0;
E 16
I 16
	ct_softc[CTUNIT(dev)].sc_state = 0;
E 16
	ctintr(dev);
I 16
	return (0);
E 16
E 4
}

D 9
ctwrite(dev)
E 9
I 9
ctwrite(dev, uio)
E 9
I 4
	dev_t dev;
I 9
	struct uio *uio;
E 9
E 4
{
D 4
	register c;
	extern lbolt;
E 4
I 4
	register struct ct_softc *sc = &ct_softc[CTUNIT(dev)];
	register int c;
I 16
	int s;
E 16
E 4

D 9
	while ((c=cpass()) >= 0) {
E 9
I 9
D 16
	while ((c=cupass(uio)) >= 0) {
E 9
D 2
		spl5();
E 2
I 2
		(void) spl5();
E 16
I 16
	while ((c = uwritec(uio)) >= 0) {
		s = spl5();
E 16
E 2
D 4
		while (cat.oq.c_cc > CATHIWAT)
			sleep((caddr_t)&cat.oq, PCAT);
		while (putc(c, &cat.oq) < 0)
E 4
I 4
		while (sc->sc_oq.c_cc > CATHIWAT)
			sleep((caddr_t)&sc->sc_oq, PCAT);
		while (putc(c, &sc->sc_oq) < 0)
E 4
			sleep((caddr_t)&lbolt, PCAT);
D 4
		ctintr();
E 4
I 4
D 16
		ctintr(dev);
E 4
D 2
		spl0();
E 2
I 2
		(void) spl0();
E 16
I 16
		if ( ! (sc->sc_state & CT_RUNNING) )
			ctintr(dev);
		splx(s);
E 16
E 2
	}
I 16
	return (0);
E 16
}

I 16
/*
 * The C/A/T is usually wired to accept data on the .5us DATA_AVAIL strobe.
 * If you use this with a C/A/T you can remove the lines with "APSu5" below.
 * This is way out of spec for the Autologic APS micro-5 which requires
 * at least a 40 microsec strobe. We therefore use CSR1 output as the
 * "strobe". It is set after data is loaded and reset only in the
 * interrupt routine. Therefore, the "strobe" is high for adequate time.
 * The constant "ctdelay" determines the "low" time for the strobe
 * and may have to be larger on a 780. "2" gives about 10us on a 750.
 */
int	ctdelay	= 2;	/* here so it's visible & changeable */

E 16
D 4
ctintr()
E 4
I 4
ctintr(dev)
	dev_t dev;
E 4
{
	register int c;
I 4
	register struct ct_softc *sc = &ct_softc[CTUNIT(dev)];
	register struct ctdevice *ctaddr =
	    (struct ctdevice *)ctdinfo[CTUNIT(dev)]->ui_addr;
E 4

D 4
	if (CATADDR->catcsr&DONE) {
		if ((c = getc(&cat.oq)) >= 0) {
E 4
I 4
D 16
	if (ctaddr->ctcsr&DONE) {
E 16
I 16
	if ((ctaddr->ctcsr&(INT_ENB_B|REQUEST_B)) == (INT_ENB_B|REQUEST_B)) {
		ctaddr->ctcsr &= ~(CSR0 | INT_ENB_B);	/* set in ctprobe */
	}
	if ((ctaddr->ctcsr&(INT_ENB_A|REQUEST_A)) == (INT_ENB_A|REQUEST_A)) {
E 16
		if ((c = getc(&sc->sc_oq)) >= 0) {
E 4
D 7
#if MH135A
			c |= (c & 01) << 8;	/* for dr11c bug */
#endif		
E 7
D 4
			CATADDR->catbuf = c;
			if (cat.oq.c_cc==0 || cat.oq.c_cc==CATLOWAT)
				wakeup(&cat.oq);
E 4
I 4
D 16
			ctaddr->ctbuf = c;
E 16
I 16
			ctaddr->ctcsr &= ~CSR1;	/* APSu5 - drop strobe */
			ctaddr->ctobuf = c;
			DELAY(ctdelay);		/* APSu5 - pause a bit */
			ctaddr->ctcsr |= CSR1;	/* APSu5 - raise strobe */
			sc->sc_state |= CT_RUNNING;
E 16
			if (sc->sc_oq.c_cc==0 || sc->sc_oq.c_cc==CATLOWAT)
D 18
				wakeup(&sc->sc_oq);
E 18
I 18
				wakeup((caddr_t)&sc->sc_oq);
E 18
E 4
D 16
		} else {
D 4
			if (cat.catlock==0)
				CATADDR->catcsr = 0;
E 4
I 4
			if (sc->sc_openf==0)
E 16
I 16
		} else if (sc->sc_state == 0) {
E 16
				ctaddr->ctcsr = 0;
E 4
D 16
		}
E 16
I 16
		} else
			sc->sc_state &= ~CT_RUNNING;
E 16
	}
D 16

E 16
}
#endif
E 1
