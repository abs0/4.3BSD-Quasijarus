h33422
s 00001/00001/00347
d D 7.5 04/12/09 23:56:29 msokolov 14 13
c FNDELAY support
e
s 00001/00001/00347
d D 7.4 89/01/24 17:24:08 bostic 13 12
c typo in attach routines; bug report 4.3BSD-tahoe/sys/34
e
s 00177/00641/00171
d D 7.3 87/02/19 17:36:34 karels 12 11
c merge common code from dmf and dmz drivers
e
s 00024/00016/00788
d D 7.2 86/12/19 11:46:35 karels 11 10
c correct uba reallocation on reset
e
s 00001/00001/00803
d D 7.1 86/06/05 01:08:28 mckusick 10 9
c 4.3BSD release version
e
s 00001/00001/00803
d D 6.8 86/04/26 01:13:04 lepreau 9 8
c PASS8 affects only input, not output
e
s 00013/00004/00791
d D 6.7 86/04/12 14:11:00 karels 8 7
c revert to "sticky" baudrate except for portselector
e
s 00001/00001/00794
d D 6.6 86/03/13 11:24:51 karels 7 6
c more (obscure) lint
e
s 00009/00009/00786
d D 6.5 86/02/17 22:57:31 karels 6 5
c correct uba allocation after reset; do flags like dmf
e
s 00061/00083/00734
d D 6.4 85/12/19 17:49:09 karels 5 3
c try to make this sucker work!  futz modem control to not look like
c a DM-11 internally, careful about word-only registers; still modem control
c doesn't work right
e
s 00000/00001/00816
d R 6.4 85/11/09 11:57:44 karels 4 3
c only set WOPEN once, only if no carrier
e
s 00013/00014/00804
d D 6.3 85/11/08 19:09:53 karels 3 2
c share unibus resources between multiplexor types; change printf
c on silo overflow to syslog; don't set break on all modem control ioctls
e
s 00029/00031/00789
d D 6.2 85/11/04 18:20:04 karels 2 1
c move carrier change code to line disciplines; make PORTSELECTOR
c code and configuration consistent; change default speed to 9600
e
s 00820/00000/00000
d D 6.1 85/10/17 14:14:54 mckusick 1 0
c date and time created 85/10/17 14:14:54 by mckusick
e
u
U
t
T
I 1
/*
D 10
 * Copyright (c) 1985 Regents of the University of California.
E 10
I 10
 * Copyright (c) 1985, 1986 Regents of the University of California.
E 10
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	%W% (Berkeley) %G%
 */

/*
 * DMZ-32 driver
D 12
 * HISTORY
 * 23-Apr-85  Joe Camaratta (jcc) at Siemens RTL
 *	Driver for DEC's DMZ32 24-line asynchronous multiplexor.
 *	Based on Chris Maloney's driver for DEC's DMF32
D 6
 *	NOTE: The modem control routines have NOT been tested yet!!!
E 6
 *
 * 9-Aug-85	Mike Meyer (mwm) at ucb
 *	Mangled into shape for 4.3.
E 12
 */

#include "dmz.h"
#if NDMZ > 0

D 12

E 12
#include "../machine/pte.h"

D 12

E 12
#include "bk.h"
#include "uba.h"
#include "param.h"
#include "conf.h"
#include "dir.h"
#include "user.h"
I 7
#include "proc.h"
E 7
#include "ioctl.h"
#include "tty.h"
#include "map.h"
#include "buf.h"
#include "vm.h"
#include "bkmac.h"
#include "clist.h"
#include "file.h"
#include "uio.h"
#include "kernel.h"
I 3
#include "syslog.h"
E 3

I 12
#include "dmx.h"
E 12
#include "ubareg.h"
#include "ubavar.h"
I 12
#include "dmxreg.h"
E 12
#include "dmzreg.h"
I 5
#include "dmreg.h"
E 5

D 12
int dmzprobe(), dmzattach(), dmzrint(), dmzxint();
struct uba_device *dmzinfo[NDMZ];
u_short dmzstd[] = {0, 0};
struct uba_driver dmzdriver = {
	dmzprobe, 0, dmzattach, 0, dmzstd, "dmz", dmzinfo
};
E 12
I 12
extern	int dmx_timeout;		/* silo timeout, in ms */
extern	char dmx_speeds[];
int	dmzstart();
E 12

D 12
#define	NDMZLINES	(NDMZ*24)

int ttrstrt();
struct tty dmz_tty[NDMZLINES];

int dmzsoftCAR[NDMZ];

struct {
	char dmz_state;		/* dmz state */
	int dmz_count;		/* dmz dma count */
} dmz_softc[NDMZ*24];

#define	ST_TXOFF	(0x01)	/* transmission turned off (^S) */
#define	ST_DMA		(0x02)	/* dma inprogress */
#define	ST_INBUSY	(0x04)	/* stop transmission in busy */

char dmz_speeds[] = {
	0, 0, 1, 2, 3, 4, 0, 5, 6, 7, 010, 012, 014, 016, 017, 0 
};

I 2
#ifndef	PORTSELECTOR
#define	ISPEED	B9600
#define	IFLAGS	(EVENP|ODDP|ECHO)
#else
#define	ISPEED	B4800
#define	IFLAGS	(EVENP|ODDP)
#endif

E 2
#ifndef lint
int ndmz = NDMZLINES;		/* Used by pstat/iostat */
#endif

short dmzact[NDMZ];		/* Mask of active octets on the dmz */
int dmzstart();

E 12
/*
D 12
 * SILO_TIMEOUT represents the number of milliseconds characters can sit
 * in the input silo without causing an interrupt.  If data overruns or
 * slow XON/XOFF occur, set it lower but AT LEAST equal to 1.
 */
#define	SILO_TIMEOUT	(3)

/*
 * DO_DMA_COUNT represents the threshold of the number of output
 * characters beyond which the driver uses DMA mode.
 */
#define	DO_DMA_COUNT	(10)

#define	TRUE		(1)
#define	FALSE		(0)

D 3
static int cbase[NUBA];		/* base address in unibus map */
E 3
I 3
D 11
int cbase[NUBA];		/* base address in unibus map */
E 3
int dmz_ubinfo[NUBA];		/* info about allocated unibus map */

E 11
I 11
/*
E 12
 * The clist space is mapped by one terminal driver onto each UNIBUS.
 * The identity of the board which allocated resources is recorded,
 * so the process may be repeated after UNIBUS resets.
 * The UBACVT macro converts a clist space address for unibus uban
 * into an i/o space address for the DMA routine.
 */
int	dmz_uballoc[NUBA];	/* which dmz (if any) allocated unibus map */
int	cbase[NUBA];		/* base address of clists in unibus map */
E 11
D 12
#define	UBACVT(x, uban)	    (cbase[uban] + ((x) - (char *)cfree))
E 12

D 12
/* These flags are for debugging purposes only */
int dmz_dma_on = 1;
E 12
I 12
/*
 * Autoconfiguration and variables for DMZ32
 */
int dmzprobe(), dmzattach();
struct uba_device *dmzinfo[NDMZ];
u_short dmzstd[] = { 0 };
struct uba_driver dmzdriver = {
	dmzprobe, 0, dmzattach, 0, dmzstd, "dmz", dmzinfo
};
E 12
D 7
int dmz_debug_level;
E 7

I 12
struct	tty dmz_tty[NDMZ*24];
struct	dmx_softc dmz_softc[3 * NDMZ];
#ifndef lint
int	ndmz = NDMZ*24;			/* used by iostat */
#endif

E 12
dmzprobe(reg)
	caddr_t reg;
{
	register int br, cvec;
	register struct dmzdevice *dmz_addr;
	register unsigned int a;

	dmz_addr = (struct dmzdevice *)reg;

#ifdef lint
	br = 0; cvec = br; br = cvec; dmzxinta(0); dmzxintb(0); dmzxintc(0);
	dmzrinta(0); dmzrintb(0); dmzrintc(0);
#endif

	br = 0x15;

	a = dmz_addr->dmz_config;
	if (((a>>12) & ~DMZ_INTERFACE) != 0) {
		printf("	Unknown interface type\n");
		return (0);
	}
	if (((a>>8) & DMZ_NOC_MASK) != 3) {
		printf("	Not all octets are available\n");
		return (0);
	}

	cvec = (uba_hd[numuba].uh_lastiv -= 4 * 6);
	dmz_addr->dmz_config = cvec >> 2;

	return (sizeof(struct dmzdevice));
}

dmzattach(ui)
D 12
	struct uba_device *ui;
E 12
I 12
	register struct uba_device *ui;
E 12
{
D 12
	dmzsoftCAR[ui->ui_unit] = ui->ui_flags;
E 12
I 12
	register struct dmx_softc *sc;
	register int i;

	sc = &dmz_softc[3 * ui->ui_unit];
	for (i = 0; i < 3; i++, sc++) {
		sc->dmx_type = 'z';
		sc->dmx_unit = ui->ui_unit;
		sc->dmx_unit0 = 8 * i;
		sc->dmx_ubanum = ui->ui_ubanum;
		sc->dmx_softCAR = (ui->ui_flags >> (8 * i)) & 0xff;
		sc->dmx_tty = &dmz_tty[((ui->ui_unit * 3) + i) * 8];
		sc->dmx_octet = (struct dmx_octet *)
		    &((struct dmzdevice *)ui->ui_addr)->dmz_octet[i];
	}

E 12
D 6
	return;
E 6
I 6
	cbase[ui->ui_ubanum] = -1;
I 11
D 13
	dmz_uballoc[ui->ui_unit] = -1;
E 13
I 13
	dmz_uballoc[ui->ui_ubanum] = -1;
E 13
E 11
E 6
}

D 12
/* ARGSUSED */
dmzopen(device, flag)
	dev_t device;
	int flag;
E 12
I 12
/*
 * Open a DMF32 line, mapping the clist onto the uba if this
 * is the first dmf on this uba.  Turn on this dmf if this is
 * the first use of it.
 */
/*ARGSUSED*/
dmzopen(dev, flag)
	dev_t dev;
E 12
{
	register struct tty *tp;
D 12
	register int unit, controller;
	register struct dmzdevice *dmz_addr;
	register struct uba_device *ui;
	int priority;
D 3
	int xstatus;
E 3
	int octet;
E 12
I 12
	struct dmx_softc *sc;
	int unit, dmz;
	struct uba_device *ui;
	int s;
E 12

D 12
	unit = minor(device);
	controller = DMZ(unit);
	octet = OCTET(unit);

	if (unit >= NDMZLINES ||
	    (ui = dmzinfo[controller]) == 0 ||
	    ui->ui_alive == 0)
E 12
I 12
	unit = minor(dev);
	dmz = DMZ(unit);
	if (unit >= NDMZ*24 || (ui = dmzinfo[dmz])== 0 || ui->ui_alive == 0)
E 12
		return (ENXIO);

	tp = &dmz_tty[unit];
D 12

	if ((tp->t_state & TS_XCLUDE) && u.u_uid != 0)
		return (EBUSY);

	dmz_addr = (struct dmzdevice *)ui->ui_addr;
	tp->t_addr = (caddr_t)dmz_addr;
E 12
I 12
	sc = &dmz_softc[unit / 8];
	tp->t_addr = (caddr_t)sc->dmx_octet;
E 12
	tp->t_oproc = dmzstart;
I 12
	tp->t_dev = dev;			/* needed before dmxopen */
E 12
D 5
	tp->t_state |= TS_WOPEN;
E 5

	/*
D 12
	 * Set up Unibus map registers.  Block uba resets, which can
	 * clear the state.
E 12
I 12
	 * While setting up state for this uba,
	 * block uba resets which can clear the state.
E 12
	 */
D 12
	priority = spl5();
E 12
I 12
	s = spl6();
E 12
D 3
	if (dmz_ubinfo[ui->ui_ubanum] == 0) {
E 3
I 3
D 6
	if (cbase[ui->ui_ubanum] == 0) {
E 6
I 6
	if (cbase[ui->ui_ubanum] == -1) {
E 6
E 3
D 11
		dmz_ubinfo[ui->ui_ubanum] = 
			uballoc(ui->ui_ubanum, (caddr_t)cfree,
				nclist * sizeof(struct cblock), 0);
		if (dmz_ubinfo[ui->ui_ubanum] == 0) {
			splx(priority);
			printf("dmz: insufficient unibus map regs\n");
D 3
			return (-1); /* Is this the right thing to return? */
E 3
I 3
			return (ENOMEM);
E 3
		}
D 6
		cbase[ui->ui_ubanum] = dmz_ubinfo[ui->ui_ubanum] & 0x3ffff;
E 6
I 6
		cbase[ui->ui_ubanum] = UBAI_ADDR(dmz_ubinfo[ui->ui_ubanum]);
E 11
I 11
D 12
		dmz_uballoc[ui->ui_ubanum] = controller;
E 12
I 12
		dmz_uballoc[ui->ui_ubanum] = dmz;
E 12
		cbase[ui->ui_ubanum] = UBAI_ADDR(uballoc(ui->ui_ubanum,
		    (caddr_t)cfree, nclist*sizeof(struct cblock), 0));
E 11
E 6
	}
I 12
	splx(s);
E 12

D 12
	if ((dmzact[controller] & (1 << octet)) == 0) {
		dmz_addr->octet[octet].octet_csr |= DMZ_IE;
		dmzact[controller] |= 1 << octet;
		dmz_addr->octet[octet].octet_receive.octet_sato = SILO_TIMEOUT;
	}

	splx(priority);

	if ((tp->t_state & TS_ISOPEN) == 0) {
		ttychars(tp);
D 2
		if (tp->t_ispeed == 0) {
			tp->t_ispeed = tp->t_ospeed = B300;
			tp->t_flags = ODDP | EVENP | ECHO;
		}
E 2
I 2
D 8
		tp->t_ispeed = tp->t_ospeed = ISPEED;
		tp->t_flags = IFLAGS;
E 8
I 8
#ifndef PORTSELECTOR
		if (tp->t_ispeed == 0) {
#else
			tp->t_state |= TS_HUPCLS;
#endif PORTSELECTOR
			tp->t_ispeed = ISPEED;
			tp->t_ospeed = ISPEED;
			tp->t_flags = IFLAGS;
#ifndef PORTSELECTOR
		}
#endif PORTSELECTOR
E 8
E 2
D 5
		dmzparam(unit);
E 5
		dmz_softc[unit].dmz_state = 0;
	}
I 5
	dmzparam(unit);
E 5

	/*
	 * Wait for carrier, then process line discipline specific open.
	 */
D 5
	if ((dmzmctl(device, DMZ_ON, DMSET) & (DMZ_CAR << 8)) ||
E 5
I 5
	if ((dmzmctl(unit, DMZ_ON, DMSET) & DMZ_CAR) ||
E 5
	    (dmzsoftCAR[controller] & (1 << (unit % 24))))
		tp->t_state |= TS_CARR_ON;
	priority = spl5();	
	while ((tp->t_state & TS_CARR_ON) == 0) {
		tp->t_state |= TS_WOPEN;
		sleep((caddr_t) &tp->t_rawq, TTIPRI);
	}
	splx(priority);

D 3
	xstatus = (*linesw[tp->t_line].l_open)(device, tp);
	return (xstatus);
E 3
I 3
	return ((*linesw[tp->t_line].l_open)(device, tp));
E 12
I 12
D 14
	return (dmxopen(tp, sc));
E 14
I 14
	return (dmxopen(tp, sc, flag));
E 14
E 12
E 3
}

D 12
dmzparam(unit)
	register int unit;
{
	register struct tty *tp;
	register struct dmzdevice *dmz_addr;
D 5
	register int line_parameters, line_control;
E 5
I 5
	register int line_parameters;
E 5
	register int octet;
	int priority;

	octet = OCTET(unit);

	tp = &dmz_tty[unit];
	dmz_addr = (struct dmzdevice *)tp->t_addr;

	priority = spl5();
	if ((tp->t_ispeed) == 0) {
		tp->t_state |= TS_HUPCLS;
		(void) dmzmctl(unit, DMZ_OFF, DMSET);
		splx(priority);
		return;
	}

	line_parameters = (dmz_speeds[tp->t_ospeed] << 12) | (dmz_speeds[tp->t_ispeed] << 8);
D 5
	line_control = DMZ_LCE;
E 5

	if ((tp->t_ispeed) == B134)
		line_parameters |= DMZ_6BT | DMZ_PEN;
D 5
	else if (tp->t_flags & (RAW | LITOUT))
E 5
I 5
	else if (tp->t_flags & (RAW | LITOUT | PASS8))
E 5
		line_parameters |= DMZ_8BT;
	else
		line_parameters |= DMZ_7BT | DMZ_PEN;

	if (tp->t_flags & EVENP)
		line_parameters |= DMZ_EPR;
	if ((tp->t_ospeed) == B110)
		line_parameters |= DMZ_SCD;

	line_parameters |= (unit & 07);

	dmz_addr->octet[octet].octet_lprm = line_parameters;
D 5
	dmz_addr->octet[octet].octet_csr = DMZ_IE | IR_LCTMR | (unit & 07);
	dmz_addr->octet[octet].octet_lctmr = 
	    (dmz_addr->octet[octet].octet_lctmr | (line_control & 0xff));

E 5
	splx(priority);
D 5
	return;
E 5
}

/* ARGSUSED */
dmzclose(device, flag)
	dev_t device;
E 12
I 12
/*
 * Close a DMZ32 line.
 */
/*ARGSUSED*/
dmzclose(dev, flag)
	dev_t dev;
E 12
	int flag;
{
D 12
	register struct  tty *tp;
	register int unit;
E 12

D 12
	unit = minor(device);
	tp = &dmz_tty[unit];
I 5
	(*linesw[tp->t_line].l_close)(tp);
E 5

	/*
D 5
	 * Break, hang-up and close the modem.
E 5
I 5
	 * Clear break, hang-up and close the modem.
E 5
	 */
	(void) dmzmctl(unit, DMZ_BRK, DMBIC);
	if (tp->t_state & TS_HUPCLS || (tp->t_state & TS_ISOPEN) == 0)
		(void) dmzmctl(unit, DMZ_OFF, DMSET);
	ttyclose(tp);
	return;
E 12
I 12
	dmxclose(&dmz_tty[minor(dev)]);
E 12
}

D 12
dmzreset(uban)
	int uban;
E 12
I 12
dmzread(dev, uio)
	dev_t dev;
	struct uio *uio;
E 12
{
D 12
	register int controller, unit;
E 12
	register struct tty *tp;
D 12
	register struct uba_device *ui;
	register struct dmzdevice *dmz_addr;
	int i;
	int octet;
E 12

D 3
	if (dmz_ubinfo[uban] == 0)
		return;

	dmz_ubinfo[uban] = uballoc(uban, (caddr_t) cfree, nclist * sizeof(struct cblock), 0);
	cbase[uban] = dmz_ubinfo[uban] & 0x3ffff;

E 3
D 12
	for (controller = 0; controller < NDMZ; controller++) {
		ui = dmzinfo[controller];
		if (ui == 0 || ui->ui_alive == 0 || ui->ui_ubanum != uban)
			continue;
		printf("dmz%d ", controller);
		dmz_addr = (struct dmzdevice *) ui->ui_addr;

I 3
D 6
		if (cbase[uban] == 0) {
E 6
I 6
D 11
		if (dmz_ubinfo[uban]) {
E 6
			dmz_ubinfo[uban] = uballoc(uban, (caddr_t)cfree,
				nclist * sizeof(struct cblock), 0);
D 6
			cbase[uban] = dmz_ubinfo[uban] & 0x3ffff;
E 6
I 6
			cbase[uban] = UBAI_ADDR(dmz_ubinfo[uban]);
E 11
I 11
		if (dmz_uballoc[uban] == controller) {
			int info;

			info = uballoc(uban, (caddr_t)cfree,
			    nclist * sizeof(struct cblock), UBA_CANTWAIT);
			if (info)
				cbase[uban] = UBAI_ADDR(info);
			else {
				printf(" [can't get uba map]");
				cbase[uban] = -1;
			}
E 11
E 6
		}

E 3
		for (octet = 0; octet < 3; octet++)
			if ((dmzact[controller] & (1 << octet)) != 0) {
				dmz_addr->octet[octet].octet_csr |= DMZ_IE;
				dmz_addr->octet[octet].octet_receive.octet_sato = SILO_TIMEOUT;
			}

		unit = controller * 24;

		/*
		 * If a unit is open or waiting for open to complete,
		 * reset it.
		 */
		for (i = 0; i < 24; i++) {
			dmz_softc[unit].dmz_state = 0;
			tp = &dmz_tty[unit];
			if (tp->t_state & (TS_ISOPEN | TS_WOPEN)) {
				dmzparam(unit);
				(void) dmzmctl(unit, DMZ_ON, DMSET);
				tp->t_state &= ~TS_BUSY;
				dmzstart(tp);
			}
			unit++;
		}
	}
	return;
E 12
I 12
	tp = &dmz_tty[minor(dev)];
	return ((*linesw[tp->t_line].l_read)(tp, uio));
E 12
}

D 12
dmzread(device, uio)
	dev_t device;
E 12
I 12
dmzwrite(dev, uio)
	dev_t dev;
E 12
	struct uio *uio;
{
	register struct tty *tp;
D 12
	int xstatus;
E 12

D 12
	tp = &dmz_tty[minor(device)];
	xstatus = (*linesw[tp->t_line].l_read)(tp, uio);
	return (xstatus);
E 12
I 12
	tp = &dmz_tty[minor(dev)];
	return ((*linesw[tp->t_line].l_write)(tp, uio));
E 12
}

D 12
dmzwrite(device, uio)
	dev_t device;
	struct uio *uio;
E 12
I 12
/*
 * DMZ32 receiver interrupts.
 */
dmzrinta(dmz)
	int dmz;
E 12
{
D 12
	register struct tty *tp;
	int xstatus;
E 12
I 12
	struct uba_device *ui;
E 12

D 12
	tp = &dmz_tty[minor(device)];
	xstatus = (*linesw[tp->t_line].l_write)(tp, uio);
	return (xstatus);
E 12
I 12
	ui = dmzinfo[dmz];
	if (ui == 0 || ui->ui_alive == 0)
		return;
	dmxrint(&dmz_softc[3 * dmz + 0]);
E 12
}

D 12
dmzrinta(controller)
	int controller;
E 12
I 12
dmzrintb(dmz)
	int dmz;
E 12
{
D 12
	dmzrint(controller, 0);
}
E 12
I 12
	struct uba_device *ui;
E 12

D 12
dmzrintb(controller)
	int controller;
{
	dmzrint(controller, 1);
E 12
I 12
	ui = dmzinfo[dmz];
	if (ui == 0 || ui->ui_alive == 0)
		return;
	dmxrint(&dmz_softc[3 * dmz + 1]);
E 12
}

D 12
dmzrintc(controller)
	int controller;
E 12
I 12
dmzrintc(dmz)
	int dmz;
E 12
{
D 12
	dmzrint(controller, 2);
}
E 12
I 12
	struct uba_device *ui;
E 12

D 12
dmzrint(controller, octet)
	int controller;
	register int octet;
{
	register struct tty *tp;
	register int character;
	register struct dmzdevice *dmz_addr;
	register struct tty *tp0;
	register int unit;
	register struct uba_device *ui;
D 2
	int overrun, priority;
E 2
I 2
	int overrun;
E 2

	overrun = 0;
	ui = dmzinfo[controller];
E 12
I 12
	ui = dmzinfo[dmz];
E 12
	if (ui == 0 || ui->ui_alive == 0)
		return;
D 12
	dmz_addr = (struct dmzdevice *) ui->ui_addr;
	tp0 = &dmz_tty[controller * 24];

	while ((character = dmz_addr->octet[octet].octet_receive.octet_rb) < 0) {
		unit = (character >> 8) & 07;	/* unit is bits 8-10 of rb */
		tp = tp0 + (octet * 8 + unit);

D 2
		if (character & DMZ_DSC) {
			if ((dmzsoftCAR[controller] & (1 << (octet * 8 + unit))) == 0) {
				priority = spl5();
				dmz_addr->octet[octet].octet_csr = DMZ_IE | IR_RMS | unit;
				if (dmz_addr->octet[octet].octet_rms & DMZ_CAR &&
				    (tp->t_state & TS_CARR_ON) == 0) {
					tp->t_state |= TS_CARR_ON;
					wakeup((caddr_t) &tp->t_rawq);
				} else {
					if (tp->t_state & TS_CARR_ON) {
						gsignal(tp->t_pgrp, SIGHUP);
						gsignal(tp->t_pgrp, SIGCONT);
						dmz_addr->octet[octet].octet_csr =
						   DMZ_IE | IR_LCTMR | unit;
						dmz_addr->octet[octet].octet_lctmr =
						   dmz_addr->octet[octet].octet_lctmr &
						   ((DMZ_OFF<<8) | 0xff);
						ttyflush(tp, FREAD|FWRITE);
					}
					tp->t_state &= ~TS_CARR_ON;
				}
				splx(priority);
E 2
I 2
D 6
		if (character & DMZ_DSC &&
		    (dmzsoftCAR[controller] & (1 << (octet * 8 + unit))) == 0) {
E 6
I 6
		if (character & DMZ_DSC) {
E 6
D 5
			dmz_addr->octet[octet].octet_csr = DMZ_IE | IR_RMS | unit;
			if (dmz_addr->octet[octet].octet_rms & DMZ_CAR)
E 5
I 5
			dmz_addr->octet[octet].octet_csr = DMZ_IE | IR_RMSTSC | unit;
			if (dmz_addr->octet[octet].octet_rmstsc & DMZ_CAR)
E 5
				(void)(*linesw[tp->t_line].l_modem)(tp, 1);
D 5
			else if ((*linesw[tp->t_line].l_modem)(tp, 0) == 0) {
				dmz_addr->octet[octet].octet_csr =
				   DMZ_IE | IR_LCTMR | unit;
				dmz_addr->octet[octet].octet_lctmr =
				   dmz_addr->octet[octet].octet_lctmr &
				   ((DMZ_OFF<<8) | 0xff);
E 2
			}
E 5
I 5
D 6
			else if ((*linesw[tp->t_line].l_modem)(tp, 0) == 0)
E 6
I 6
D 8
			else if (dmzsoftCAR[controller] &
			  (1 << (octet * 8 + unit)) == 0 &&
E 8
I 8
			else if ((dmzsoftCAR[controller] &
			    (1 << (octet * 8 + unit))) == 0 &&
E 8
			    (*linesw[tp->t_line].l_modem)(tp, 0) == 0)
E 6
				(void)dmzmctl(tp - dmz_tty, DMZ_OFF, DMSET);
E 5
			continue;
		}

D 2
		if ((tp->t_state & TS_ISOPEN) == 0) {
			wakeup((caddr_t) tp);
			continue;
E 2
I 2
		if ((tp->t_state&TS_ISOPEN)==0) {
			wakeup((caddr_t)&tp->t_rawq);
#ifdef PORTSELECTOR
			if ((tp->t_state&TS_WOPEN) == 0)
#endif
				continue;
E 2
		}

		if (character & DMZ_PE) {
			if ((tp->t_flags & (EVENP | ODDP)) == EVENP ||
			    (tp->t_flags & (EVENP | ODDP)) == ODDP)
				continue;
		}

		if ((character & DMZ_DO) && overrun == 0) {
D 3
			printf("dmz%d: silo overflow\n", controller);
E 3
I 3
			log(LOG_WARNING, "dmz%d: silo overflow\n", controller);
E 3
			overrun = 1;
		}

		if (character & DMZ_FE) {
			if (tp->t_flags & RAW)
				character = 0;
			else
				character = tp->t_intrc;
		}

		(*linesw[tp->t_line].l_rint)(character, tp);
	}

	return;
E 12
I 12
	dmxrint(&dmz_softc[3 * dmz + 2]);
E 12
}

D 12
dmzxinta(controller)
	int controller;
E 12
I 12
/*
 * Ioctl for DMZ32.
 */
dmzioctl(dev, cmd, data, flag)
	dev_t dev;
	caddr_t data;
E 12
{
D 12
	dmzxint(controller, 0);
E 12
I 12
	int unit = minor(dev);
 
	return (dmxioctl(&dmz_tty[unit], cmd, data, flag));
E 12
}

D 12
dmzxintb(controller)
	int controller;
E 12
I 12
/*
 * DMZ32 transmitter interrupts.
 */
dmzxinta(dmz)
	int dmz;
E 12
{
D 12
	dmzxint(controller, 1);
E 12
I 12

	dmxxint(&dmz_softc[3 * dmz + 0]);
E 12
}

D 12
dmzxintc(controller)
	int controller;
E 12
I 12
dmzxintb(dmz)
	int dmz;
E 12
{
D 12
	dmzxint(controller, 2);
E 12
I 12

	dmxxint(&dmz_softc[3 * dmz + 1]);
E 12
}

D 12
dmzxint(controller, octet)
	int controller;
	register int octet;
E 12
I 12
dmzxintc(dmz)
	int dmz;
E 12
{
D 12
	register struct tty *tp;
	register struct dmzdevice *dmz_addr;
	register struct uba_device *ui;
	register int unit, t;
	int priority;
E 12

D 12
	ui = dmzinfo[controller];
	dmz_addr = (struct dmzdevice *)ui->ui_addr;

	priority = spl5();

	while ((t = dmz_addr->octet[octet].octet_csr) & DMZ_TRDY) {
		unit = controller * 24 + (octet * 8 + ((t>>8) & 07));
		tp = &dmz_tty[unit];
		tp->t_state &= ~TS_BUSY;

		if (t & DMZ_NXM)
			printf("dmz%d: NXM line %d\n", controller, 
				octet * 8 + (unit & 07));

		if (tp->t_state & TS_FLUSH) {
			tp->t_state &= ~TS_FLUSH;
			dmz_addr->octet[octet].octet_csr = 
				DMZ_IE | IR_LCTMR | (unit & 07);
			dmz_addr->octet[octet].octet_lctmr = 
				(dmz_addr->octet[octet].octet_lctmr | DMZ_TE);
		} else
			if (dmz_softc[unit].dmz_state & ST_DMA)
				ndflush(&tp->t_outq, dmz_softc[unit].dmz_count);
		dmz_softc[unit].dmz_state = 0;

		if (tp->t_line)
			(*linesw[tp->t_line].l_start)(tp);
		else
			dmzstart(tp);
	}

	splx(priority);
	return;
E 12
I 12
	dmxxint(&dmz_softc[3 * dmz + 2]);
E 12
}

I 12
/*
 * Start (restart) transmission on the given line.
 */
E 12
dmzstart(tp)
D 12
	register struct tty *tp;
E 12
I 12
	struct tty *tp;
E 12
{
D 12
	register struct dmzdevice *dmz_addr;
	register int unit, nch, room;
	int controller, octet;
	int priority, car, use_dma;
	register int i;
	register char *cp;
E 12

D 12
	unit = minor(tp->t_dev);
	controller = DMZ(unit);
	octet = OCTET(unit);
	dmz_addr = (struct dmzdevice *)tp->t_addr;

	priority = spl5();

	if (tp->t_state & (TS_TIMEOUT | TS_BUSY | TS_TTSTOP))
		goto out;

	/*
	 * If the transmitter has been disabled, reenable it.
	 * If the transmitter was disabled before the xint (the
	 * ST_INBUSY was still on), then reset the BUSY state and
	 * we will wait for the interrupt.  If !TS_BUSY, we already
	 * saw the interrupt so we can start another transmission.
	 */
	if (dmz_softc[unit].dmz_state & ST_TXOFF) {
		dmz_addr->octet[octet].octet_csr = 
			DMZ_IE | IR_LCTMR | (unit & 07);
		dmz_addr->octet[octet].octet_lctmr = 
			(dmz_addr->octet[octet].octet_lctmr | DMZ_TE);
		dmz_softc[unit].dmz_state &= ~ST_TXOFF;
		if (dmz_softc[unit].dmz_state & ST_INBUSY) {
			dmz_softc[unit].dmz_state &= ~ST_INBUSY;
			tp->t_state |= TS_BUSY;
			goto out;
		}
	}

	if (tp->t_outq.c_cc <= TTLOWAT(tp)) {
		if (tp->t_state & TS_ASLEEP) {
			tp->t_state &= ~TS_ASLEEP;
			wakeup((caddr_t)&tp->t_outq);
		}
		if (tp->t_wsel) {
			selwakeup(tp->t_wsel, tp->t_state & TS_WCOLL);
			tp->t_wsel = 0;
			tp->t_state &= ~TS_WCOLL;
		}
	}

	if (tp->t_outq.c_cc == 0)
		goto out;
D 5
	if (tp->t_flags & (RAW | LITOUT))
E 5
I 5
D 9
	if (tp->t_flags & (RAW | LITOUT | PASS8))
E 9
I 9
	if (tp->t_flags & (RAW | LITOUT))
E 9
E 5
		nch = ndqb(&tp->t_outq, 0);
	else {
		nch = ndqb(&tp->t_outq, 0200);
		if (nch == 0) {
			nch = getc(&tp->t_outq);
			timeout(ttrstrt, (caddr_t)tp, (nch & 0x7f)+6);
			tp->t_state |= TS_TIMEOUT;
			goto out;
		}
	}

	/*
	 * Should we use DMA or SILO mode?
	 * If nch is greater than DO_DMA_COUNT then DMA.
	 */
	if (nch) {
		dmz_addr->octet[octet].octet_csr = 
			DMZ_IE | IR_LCTMR | (unit & 07);
		dmz_addr->octet[octet].octet_lctmr = 
			(dmz_addr->octet[octet].octet_lctmr | DMZ_TE);
		tp->t_state |= TS_BUSY;

		use_dma = FALSE;
		room = DMZ_SIZ;

		if (nch > DO_DMA_COUNT)
			use_dma = TRUE;
		
		if (use_dma && dmz_dma_on) {
			car = UBACVT(tp->t_outq.c_cf, 
				dmzinfo[controller]->ui_ubanum);
			dmz_softc[unit].dmz_count = nch;
			dmz_softc[unit].dmz_state |= ST_DMA;
			dmz_addr->octet[octet].octet_csr = 
				DMZ_IE | IR_TBA | (unit & 07);
			dmz_addr->octet[octet].octet_tba = car;
			dmz_addr->octet[octet].octet_tcc = 
				((car >> 2) & 0xc000) | nch;
		} else {
			dmz_softc[unit].dmz_state &= ~ST_DMA;
			cp = tp->t_outq.c_cf;
			nch = MIN(nch, room);
			dmz_addr->octet[octet].octet_csr = 
				DMZ_IE | IR_TBUF | (unit & 07);
			for (i = 0; i < nch; i++)
				dmz_addr->octet[octet].octet_tbf = *cp++ ;
			ndflush(&tp->t_outq, nch);
		}
	}

out:
	splx(priority);
	return;
E 12
I 12
	dmxstart(tp, &dmz_softc[minor(tp->t_dev) >> 3]);
E 12
}

D 12
/* ARGSUSED */
E 12
I 12
/*
 * Stop output on a line, e.g. for ^S/^Q or output flush.
 */
E 12
dmzstop(tp, flag)
D 12
	register struct tty *tp;
E 12
I 12
	struct tty *tp;
E 12
{
D 12
	register struct dmzdevice *dmz_addr;
	register int unit, priority, octet;
E 12

D 12
	priority = spl5();
	dmz_addr = (struct dmzdevice *) tp->t_addr;
	unit = minor(tp->t_dev);
	octet = OCTET(unit);

	dmz_addr->octet[octet].octet_csr = IR_LCTMR | (unit & 07) | DMZ_IE;
	dmz_addr->octet[octet].octet_lctmr = 
		(dmz_addr->octet[octet].octet_lctmr & ~DMZ_TE);
	dmz_softc[unit].dmz_state |= ST_TXOFF;
	if ((tp->t_state & TS_TTSTOP) == 0) {
		tp->t_state |= (TS_FLUSH | TS_BUSY);
		dmz_addr->octet[octet].octet_lctmr = 
			(dmz_addr->octet[octet].octet_lctmr | DMZ_FLS);
	} else if (tp->t_state & TS_BUSY) {
		dmz_softc[unit].dmz_state |= ST_INBUSY;
		tp->t_state &= ~TS_BUSY;
	}

	splx(priority);
	return;
E 12
I 12
	dmxstop(tp, &dmz_softc[minor(tp->t_dev) >> 3], flag);
E 12
}

D 12
/* ARGSUSED */
dmzioctl(device, command, data, flag)
	dev_t device;
	caddr_t data;
E 12
I 12
/*
 * Reset state of driver if UBA reset was necessary.
 * Reset the csr, lpr, and lcr registers on open lines, and
 * restart transmitters.
 */
dmzreset(uban)
	int uban;
E 12
{
I 12
	register int dmz;
E 12
	register struct tty *tp;
D 12
	register int unit;
	int error;
E 12
I 12
	register struct uba_device *ui;
	register struct dmzdevice *addr;
	int i;
E 12

D 12
	unit = minor(device);
	tp = &dmz_tty[unit];
E 12
I 12
	for (dmz = 0; dmz < NDMZ; dmz++) {
		ui = dmzinfo[dmz];
		if (ui == 0 || ui->ui_alive == 0 || ui->ui_ubanum != uban)
			continue;
		printf("dmz%d ", dmz);
		addr = (struct dmzdevice *)ui->ui_addr;
E 12

D 12
	error = (*linesw[tp->t_line].l_ioctl)(tp, command, data, flag);
	if (error >= 0)
		return (error);
	error = ttioctl(tp, command, data, flag);
	if (error >= 0) {
D 5
		if (command == TIOCSETP || command == TIOCSETN)
E 5
I 5
		if (command == TIOCSETP || command == TIOCSETN ||
		    command == TIOCLSET || command == TIOCLBIS ||
		    command == TIOCLBIC)
E 5
			dmzparam(unit);
		return (error);
	}
E 12
I 12
		if (dmz_uballoc[uban] == dmz) {
			int info;
E 12

D 12
	switch (command) {
		case TIOCSBRK:
D 5
			(void) dmzmctl(device, DMZ_BRK, DMBIS);
E 5
I 5
			(void) dmzmctl(unit, DMZ_BRK, DMBIS);
E 5
			break;
		case TIOCCBRK:
D 5
			(void) dmzmctl(device, DMZ_BRK, DMBIC);
E 5
I 5
			(void) dmzmctl(unit, DMZ_BRK, DMBIC);
E 5
			break;
		case TIOCSDTR:
D 5
			(void) dmzmctl(device, DMZ_DTR | DMZ_RTS, DMBIS);
E 5
I 5
			(void) dmzmctl(unit, DMZ_DTR | DMZ_RTS, DMBIS);
E 5
			break;
		case TIOCCDTR:
D 5
			(void) dmzmctl(device, DMZ_DTR | DMZ_RTS, DMBIC);
E 5
I 5
			(void) dmzmctl(unit, DMZ_DTR | DMZ_RTS, DMBIC);
E 5
			break;
		case TIOCMSET:
D 5
			(void) dmzmctl(device, dmtodmz(*(int *)data), DMSET);
E 5
I 5
			(void) dmzmctl(unit, dmtodmz(*(int *)data), DMSET);
E 5
			break;
		case TIOCMBIS:
D 5
			(void) dmzmctl(device, dmtodmz(*(int *)data), DMBIS);
E 5
I 5
			(void) dmzmctl(unit, dmtodmz(*(int *)data), DMBIS);
E 5
			break;
		case TIOCMBIC:
D 5
			(void) dmzmctl(device, dmtodmz(*(int *)data), DMBIC);
E 5
I 5
			(void) dmzmctl(unit, dmtodmz(*(int *)data), DMBIC);
E 5
			break;
		case TIOCMGET:
D 5
			*(int *)data = dmztodm(dmzmctl(device, 0, DMGET));
E 5
I 5
			*(int *)data = dmzmctl(unit, 0, DMGET);
E 5
			break;
		default:
			return (ENOTTY);
	}
	return (0);
}
E 12
I 12
			info = uballoc(uban, (caddr_t)cfree,
			    nclist * sizeof(struct cblock), UBA_CANTWAIT);
			if (info)
				cbase[uban] = UBAI_ADDR(info);
			else {
				printf(" [can't get uba map]");
				cbase[uban] = -1;
			}
		}
E 12

D 5
dmzmctl(device, bits, how)
	dev_t device;
E 5
I 5
D 12
dmzmctl(unit, bits, how)
	register int unit;
E 5
	int bits, how;
{
	register struct dmzdevice *dmz_addr;
D 5
	register int unit, modem_status, line_control;
	register int temp;
E 5
I 5
	register int modem_status, line_control;
E 5
	int priority;
	int octet;
E 12
I 12
		for (i = 0; i < 3; i++)
			if (dmz_softc[3 * dmz + i].dmx_flags & DMX_ACTIVE) {
				addr->dmz_octet[i].csr = DMF_IE;
				addr->dmz_octet[i].rsp = dmx_timeout;
			}
E 12

D 5
	unit = minor(device);
E 5
D 12
	octet = OCTET(unit);
D 5
	dmz_addr = (struct dmzdevice *) dmz_tty[unit].t_addr;
E 5
I 5
	dmz_addr = (struct dmzdevice *) dmzinfo[DMZ(unit)]->ui_addr;
E 5

	priority = spl5();
D 5
	dmz_addr->octet[octet].octet_csr = DMZ_IE | IR_RMS | (unit & 07);
	modem_status = dmz_addr->octet[octet].octet_rms << 8;
E 5
I 5
	dmz_addr->octet[octet].octet_csr = DMZ_IE | IR_RMSTSC | (unit & 07);
	modem_status = dmz_addr->octet[octet].octet_rmstsc & 0xff00;
E 5

	dmz_addr->octet[octet].octet_csr = DMZ_IE | IR_LCTMR | (unit & 07);
D 5
	temp = dmz_addr->octet[octet].octet_lctmr;
	modem_status |= ((temp>>8) & (0x1f));
D 2
	line_control = (temp & (0x1f));
E 2
I 2
	line_control = (temp & (0x3f));
E 5
I 5
	line_control = dmz_addr->octet[octet].octet_lctmr;
E 5
E 2

D 3
	if (line_control & DMZ_BRK)
E 3
I 3
D 5
	if (line_control & DMZ_RBK)
E 3
		modem_status |= DMZ_BRK;
E 5

	switch (how) {
		case DMSET:
D 5
			modem_status = (modem_status & 0xff00) | bits;
E 5
I 5
			line_control = bits;
E 5
			break;
		case DMBIS:
D 5
			modem_status |= bits;
E 5
I 5
			line_control |= bits;
E 5
			break;
		case DMBIC:
D 5
			modem_status &= ~bits;
E 5
I 5
			line_control &= ~bits;
E 5
			break;
		case DMGET:
			(void) splx(priority);
D 5
			return (modem_status);
E 5
I 5
			return (dmztodm(modem_status, line_control));
E 12
I 12
		/*
		 * If a unit is open or waiting for open to complete,
		 * reset it.
		 */
		tp = &dmz_tty[dmz * 24];
		for (i = 0; i < 24; i++, tp++) {
			if (tp->t_state & (TS_ISOPEN | TS_WOPEN)) {
				dmxparam(tp);
				(void) dmxmctl(tp, DMF_ON, DMSET);
				tp->t_state &= ~TS_BUSY;
				dmzstart(tp);
			}
		}
E 12
E 5
	}
D 12

D 5
	if (modem_status & DMZ_BRK)
		line_control |= DMZ_RBK;
	else
		line_control &= ~DMZ_RBK;
	modem_status &= ~DMZ_BRK;

E 5
	dmz_addr->octet[octet].octet_csr =
		DMZ_IE | IR_LCTMR | (unit & 07);
D 5
	dmz_addr->octet[octet].octet_lctmr =
		((modem_status & 0x1f) << 8) | (line_control & 0x3f);
E 5
I 5
	dmz_addr->octet[octet].octet_lctmr = line_control;
E 5

D 5
	(void) splx(priority);
E 5
I 5
	splx(priority);
E 5
	return (modem_status);
}

/*
D 5
 * Routine to convert modem status from dm to dmz format.
 * Pull bits 1 & 3 through unchanged. If dm secondary transmit bit is set,
 * and/or dm request to send bit is set, and/or dm user modem signal bit
 * is set, set the corresponding dmz bits.
E 5
I 5
 * Routine to convert modem status from dm to dmz lctmr format.
E 5
 */
dmtodmz(bits)
	register int bits;
{
D 5
	register int b;
E 5
I 5
	register int lcr = DMZ_LCE;
E 5

D 5
	b = bits & 012;
	if (bits & DM_ST)
		b |= DMZ_RAT;
	if (bits & DM_RTS)
		b |= DMZ_RTS;
	if (bits & DM_USR)
		b |= DMZ_USW;
	return (b);
E 5
I 5
	if (bits & DML_DTR)
		lcr |= DMZ_DTR;
	if (bits & DML_RTS)
		lcr |= DMZ_RTS;
	if (bits & DML_ST)
		lcr |= DMF_ST;
	if (bits & DML_USR)
		lcr |= DMZ_USRW;
	return (lcr);
E 5
}

/*
D 5
 * Routine to convert modem status from dmz to dm format.  Pull bits 1 & 3
 * through unchanged. Pull bits 11 - 15 through as bits 4 - 8 and set bit
 * 0 to dm line enable.  If dmz user modem signal bit set, and/or  dmz
 * request to send bit set, then set the corresponding dm bit also.
E 5
I 5
 * Routine to convert modem status from dmz receive modem status
 * and line control register to dm format.
 * If dmz user modem read bit set, set DML_USR.
E 5
 */
D 5
dmztodm(bits)
	register int bits;
E 5
I 5
dmztodm(rms, lcr)
	register int rms, lcr;
E 5
{
D 5
	register int b;
E 5

D 5
	b = (bits & 012) | ((bits >> 7) & 0760) | DM_LE;
	if (bits & DMZ_USR)
		b |= DM_USR;
	if (bits & DMZ_RTS)
		b |= DM_RTS;
	return (b);
E 5
I 5
	rms = ((rms & (DMZ_DSR|DMZ_RNG|DMZ_CAR|DMZ_CTS|DMF_SR)) >> 7) | 
		((rms & DMZ_USRR) >> 1) | DML_LE;
	if (lcr & DMZ_DTR)
		rms |= DML_DTR;
	if (lcr & DMF_ST)
		rms |= DML_ST;
	if (lcr & DMZ_RTS)
		rms |= DML_RTS;
	return (rms);
E 12
E 5
}
#endif
E 1
